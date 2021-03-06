package haikuvm.pc.tools;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.Reader;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.text.Format;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.Enumeration;
import java.util.Formatter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeSet;
import java.util.Vector;

/*
import org.apache.bcel.Constants;
import org.apache.bcel.classfile.Code;
import org.apache.bcel.classfile.CodeException;
import org.apache.bcel.classfile.ConstantPool;
import org.apache.bcel.classfile.JavaClass;
import org.apache.bcel.classfile.Method;
 */

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.ReentrantLock;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.event.TreeModelEvent;
import javax.swing.event.TreeModelListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreeNode;

import org.junit.experimental.categories.Categories.IncludeCategory;

import haikuvm.pc.tools.asmvisitors.*;

import org.objectweb.asm.*;
import org.objectweb.asm.commons.Method;
//import org.objectweb.asm.tree.ClassNode;
import org.objectweb.asm.util.Textifier;

import static org.objectweb.asm.Opcodes.*;
import static org.objectweb.asm.util.Printer.*;
/**
 * December 2013. Try asm instead of bcel.
 * 
 * This class should have a name like "TargetApplicationJavaClasses".
 * It used to be named "Closure".
 * 
 * This class will gather all referenced fields and methods (recursively) (the scan method)
 * and create (the build method) new classes (only the ones used in the given method at scan()) and these classes
 * will only contain the used fields and methods.
 * 
 * In the scan phase, a tree will be built with the referenced fields and methods.
 * This tree is not necessarily complete:
 * it will contain all fields and methods, but not in every branch of the tree. To improve performance,
 * duplicate entries might have been deleted. January 2014.
 * 
 * The UserObject in the tree can either be a Member (method or field) or a TreeNode. In
 * the latter case, it references a formerly created node. The userObject of the node
 * is the original node with the Member that would be in the location where the node userObject is.
 *
 * There is a method listClinitsInOrder that produces an ordered list of <clinit> methods.
 * 
 * Advantages asm over bcel:
 * it is actively maintained (januari 2014)
 * it uses the Visitor pattern
 * Disadvantages asm:
 * it it programmed to be fast, not to be stable or to be maintainable(?)
 * 
 * asm reference at http://download.forge.objectweb.org/asm/-guide.pdf
 * 
 * @author Carl van Denzen
 *
 */
public class TargetApplicationJavaClasses {

	/**
	 * Create an instance that will lookup the referenced members in classes that can
	 * be loaded with the specified classloader
	 * @param classLoader The ClassLoader to use for finding referenced classes.
	 */
	public TargetApplicationJavaClasses(ClassLoader classLoader) {
		this.classLoader=classLoader;
		// Create the root of the tree
		MemberTreeNode treeNode=new MemberTreeNode();
		tree=new DefaultTreeModel(treeNode);
		// Add a listener to keep the list with referencedMembers up-to-date
		// NOT USED (yet)
		tree.addTreeModelListener(new TreeModelListener() {


			@Override
			public void treeStructureChanged(TreeModelEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void treeNodesRemoved(TreeModelEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void treeNodesInserted(TreeModelEvent e) {
				// Check all inserted nodes
				for (Object nodeObject:e.getChildren()) {
					// If this Tree has (already) a userObject of type Member,
					// add this member
					// Assume we only insert MemberTreeNode
					MemberTreeNode node=(MemberTreeNode) nodeObject;
					if (node.getUserObject() instanceof Member) {
						referencedMembers.add((Member) node.getUserObject());
					}
					node.addPropertyChangeListener("userObject", new PropertyChangeListener() {

						@Override
						public void propertyChange(PropertyChangeEvent evt) {
							// userObject changed.
							if (evt.getNewValue() instanceof Member) {
								referencedMembers.add((Member) evt.getNewValue());
							}

						}
					});
				}


			}

			@Override
			public void treeNodesChanged(TreeModelEvent e) {
				// TODO Auto-generated method stub
				// not interesting

			}

			/**
			 * Insert the members that are userObjects of the nodes
			 * @param nodes The TreeNodes that are affected/changed
			 */
			private void insertNodes(Object[] nodes) {

			}
		});
	}
	/**
	 * A convenience constructor.
	 * Create an instance that will lookup the referenced members in classes that can
	 * be found in the classpath.
	 * @param classpaths
	 */
	public TargetApplicationJavaClasses(String[] classpaths) {
		// Our classloader needs URLs as the classpath.
		// Any URL ending in / is supposed to be a directory,
		// Any URL not ending in / is supposed to be a jar file
		URL[] urls=new URL[classpaths.length];
		// Make the file names into urls by prefixing them with file://
		for (int i=0;i<classpaths.length;i++) {
			try {
				urls[i]=new URL("file://"+classpaths[i]);
			} catch (MalformedURLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		// Use a specialized classloader that first searches the given urls and then the parent loader
		// does not fit my needs 20140101Carl classLoader=new ParentLastURLClassLoader(urls,null);
		//ClassLoader parent=classLoader.getParent();
		// Use a normal URLClassLoader and do a trick with getResourceAsStream to
		// give the new ClassLoader higher priority (to load e.g. Object.class from nxt
		// and not from rt.jar (the jre jar).
		classLoader=new URLClassLoader(urls);
	}
	/**
	 * A convenience constructor.
	 * Create an instance that will lookup the referenced members in classes that can
	 * be found in the classpath.
	 * @param classpath
	 */
	public TargetApplicationJavaClasses(String classpath) {
		// Split the classpath string into its components
		this(classpath.split(System.getProperty("path.separator",";")));
	}
	/**
	 * a graphical representation...??
	 */
	private TreeModel tree;
	//private TreeNode currentNode;
	/**
	 * Start parsing this method/field
	 * If the methodName is empty or null, all methods are assumed to be included in the output.
	 * @param member The class/field or method name etc.
	 * @throws ClassNotFoundException 
	 */
	public void scan(Member rootMember) throws ClassNotFoundException {
		logger.fine("** Scan ** "+rootMember);
		// Start this scan with the root node
		scan(rootMember,(MemberTreeNode) tree.getRoot());

		// Print the members, ordered by name
		SortedSet<Member> sortedSet=new TreeSet<Member>(referencedMembers);
		StringBuilder sb=new StringBuilder(1000);
		sb.append("End of scan "+rootMember+ ", included members are:");
		for (Member member:sortedSet) {
			sb.append("\n ++ ").append(member.toString());
		}
		sb.append("End of scan, end of included members");
		logger.fine(sb.toString());
		//System.out.println("} /* "+new Date().toString()+" */");
		//		MemberTreeNode tn;
		//		TreeModelListener tml;
		//		tn.
	}
	/**
	 * Start scanning this member
	 * @param classname
	 * @param member The to be scanned
	 * @param parentTreeNode The position of this element in the tree of included members (for presentational purposes only)
	 * @throws ClassNotFoundException 
	 */
	private void scan(final Member member,final MemberTreeNode parentTreeNode) throws ClassNotFoundException {
		logger.fine("** Scan "+member+", parentTreeNode="+parentTreeNode);


		// Skip array types
		if (member.getOwner().startsWith("[")) {
			logger.fine("Skip arraytype="+member);
			return;
		}
		ClassReader cr = null;
		URL selectedURL = null;
		try {
			InputStream classInputStream;
			// Class loading in Java is difficult, parent loader always has priority.
			// This is problematic for e.g. java.lang.Object and java.lang.String that we
			// want to redefine in HaikuVM
			// Solution used here: find all URLs for the searched resource and pick the last one found
			// (that will be the one in the last added classloader).
			// test
			ArrayList<URL> urls=new ArrayList<URL>();
			Enumeration<URL> e=null;
			try {
				e = classLoader.getResources(member.getOwner()+".class");
				while (e.hasMoreElements()) {
					urls.add(e.nextElement());
				};
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}

			selectedURL=null;
			// Select the last URL in the list, that is the one this member was found
			if (urls.size()>0) {
				selectedURL=urls.get(urls.size()-1);
			} else {
				logger.severe(e.toString());
				throw new ClassNotFoundException("Resource not found: "+member);
			}
			//member.setUrl(selectedURL);
			classInputStream=selectedURL.openStream();
			cr = new ClassReader(classInputStream);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			logger.severe(member+": "+e.getMessage());
			e.printStackTrace();
		}
		HaikuClassNode classNode;
		classNode=classNodes.get(member.getOwner());
		if (classNode==null) {
			// If this class has not yet been transformed into a tree (ClassNode object), do it now
			//ClassNode classNode=null;
			classNode=new HaikuClassNode();
			cr.accept(classNode, 0);
			classNode.setUrl(selectedURL);
			classNodes.put(member.getOwner(),classNode);
		};
		member.setClassNode(classNode);
		// Create a ClassVisitor (class that collects used methods and fields)
		ClassScanner classScanner = new ClassScanner(member);
		// start parsing, this will call the ASM Visitor
		cr.accept(classScanner, 0);
		/*
		 * Handling of super/subclasses (including interfaces):
		 * Referencing a member can be through INVOKEVIRTUAL, INVOKEINTERFACE?
		 * For every referenced member, this member is also set as "used" in all
		 * of its subclasses (or implementing classes, or sub-interfaces).
		 * When a new class is encountered, all of its superclass methods are set as "used".
		 */
		// Find the current class

		String currentClass=member.getOwner();
		// Read the members to be included
		ReferencedMembers<Member> referencedMembersTemp=classScanner.getReferencedMembers();
		// collect all interface members (can come from more than one interface)
		Set<Member> tempInterfaceMembers=new HashSet<Member>();
		// Scan all members that must be included, to find wildcard
		// (interface) members.
		for (Iterator<Member> iter=referencedMembersTemp.iterator();iter.hasNext();) {
			Member m=iter.next();
			// It can be an interface member, specifying that all methods with the
			// same name in the member object should be included
			// An interface member can be recognized because it has an owner but no name.
			if (m.getName()==null || m.getName().isEmpty()) {
				// This is an interface specification.
				// Find the interface methods in this class
				// Use a new TargetApplicationJavaClasses
				logger.finer("Scan for interface members, member="+m);
				TargetApplicationJavaClasses tajc=new TargetApplicationJavaClasses(classLoader);
				tajc.scan(m);
				tempInterfaceMembers.addAll(tajc.getReferencedMembers());
				// Remove this fake entry from the set
				iter.remove();
			}
		}

		// Include the implementation of the interface methods in the class we are visiting.
		// Collect the new members in a separate Set to avoid concurrent updates
		for (Member m1:tempInterfaceMembers) {
			// Create a clone, to 
			// include the interface member to avoid repetitive
			// visits to the interface members
			referencedMembersTemp.add(m1);
			// Set owner to the owner of the class, not of the interface.
			// Do this in a copy of the member, otherwise it would be the same object.
			Member m2=new Member(m1);
			m2.setOwner(member.getOwner());
			referencedMembersTemp.add(m2);
		}
		// Check whether the Member we were looking for is found.
		if (member.getName()!=null && !member.getName().isEmpty()&&!classScanner.isMemberFound()) {
			// Member was not found, so it could be in a superclass or an interface
			logger.finest("Member not found, try superclass or interface, member="+member);
			Set<Member> foundMembers=new HashSet<Member>();
			// Clone the original member, do not destroy the original
			Member m3=new Member(member);
			if (!classScanner.getSuperName().isEmpty()) {
				m3.setOwner(classScanner.getSuperName());
				TargetApplicationJavaClasses tajc=new TargetApplicationJavaClasses(classLoader);
				tajc.scan(m3,parentTreeNode);
				foundMembers=tajc.getReferencedMembers();
			}
			referencedMembersTemp.addAll(foundMembers);
			if (foundMembers.isEmpty()) {
				// Try if this Member is in an interface
				for (String interf:classScanner.getInterfaces()) {
					m3.setOwner(interf);
					TargetApplicationJavaClasses tajc=new TargetApplicationJavaClasses(classLoader);
					tajc.scan(m3,parentTreeNode);
					foundMembers=tajc.getReferencedMembers();
					if (!foundMembers.isEmpty()) {
						// We found this member in this interface, don't look further
						break;
					}
				}
			}
			referencedMembersTemp.addAll(foundMembers);
			// scan the referenced methods
			for (Member m:referencedMembersTemp) {
				scan(m,parentTreeNode);
			}
			// Add the foundMembers to the referencedMembers
			referencedMembers.addAll(referencedMembersTemp);
		}
		// Add the interface members to the Set that contains all members for the application
		referencedMembersTemp.addAll(tempInterfaceMembers);
		// Check all new members
		for (Member m1:referencedMembersTemp) {
			// Create a new tree node with the member m1 as the userObject
			MemberTreeNode n=new MemberTreeNode(m1);
			// If this member is not yet put into the referencedMembers set, it must be
			// scanned for new references. Otherwise it has already been seen and scanned.
			if (referencedMembers.add(m1)) {
				// Add to parent after checking whether this member is already known to avoid finding itself in the tree
				parentTreeNode.add(n);
				scan(m1, n);
			} else {
				// Member was already known, no need to rescan, but create a stub node
				// This member was seen earlier
				// Make a new node in the tree and add it to its parent
				// To indicate that this is a kind of "symbolic link" to an earlier found
				// Member, set the userObject to the original Node.
				@SuppressWarnings("unchecked")
				Enumeration<MemberTreeNode> enumeration=parentTreeNode.preorderEnumeration();//.depthFirstEnumeration();
				while (enumeration.hasMoreElements()) {
					MemberTreeNode existingNode;
					existingNode=enumeration.nextElement();
					// member can be null for root node
					Object existingMember=existingNode.getUserObject();
					if (existingMember!=null) {
						if (existingMember.equals(m1)) {
							// This is the original Node, set as "symbolic link"
							logger.fine("Going to set UserObject for member "+m1+" to existing node "+existingNode);
							n.setUserObject(existingNode);
							break; // no need to search further
						}
					}
				}
				parentTreeNode.add(n);
			}
		}

		//
		// Insert class init method
		//
		// For every class, the clinit method must be included explicitly,
		// because it is never called.
		// Not every class has a <clinit> method
		Member clinitMember=new Member(member.getOwner(), "<clinit>", "()V");
		//
		// Not every class has a <clinit> method. To avoid unnecessary searches for
		// <clinit> methods, set it as found. (unnecessary is an understatement: it
		// is an endless loop we are getting in).
		if (referencedMembers.add(clinitMember)) {
			try {
				logger.fine("<clinit> artificially added for "+clinitMember);
				scan(clinitMember,parentTreeNode);
			} catch (ClassNotFoundException e) {
				logger.severe(e.toString());
				throw new IllegalArgumentException(e);
			}
		}
	}
	/**
	 * Get the subclasses of the given class
	 * @param currentClass in internal format (with slashes)
	 * @return a Set of Strings with superclass names (in internal format)
	 */
	private HashSet<String> getSubClasses(String currentClass) {
		throw new Error("Method not implemented");
	}
	/**
	 * This method is not used.
	 * @param classname
	 * @return
	 * @throws ClassNotFoundException
	 */
	@Deprecated
	private Collection<Member> getMembers(String classname) throws ClassNotFoundException {
		HashSet<Member> members=new HashSet<>();
		// Create a ClassVisitor (class that collects used methods and fields)
		ClassReader cr = null;
		URL url=null; // the url where this class was loaded from
		try {
			InputStream classInputStream;
			// Class loading in Java is difficult, parent loader always has priority.
			// This is problematic for e.g. java.lang.Object and java.lang.String that we
			// want to redefine in HaikuVM
			// Solution used here: find all URLs for the searched resource and pick the last one found
			// (that will be the one in the last added classloader).
			// test
			ArrayList<URL> urls=new ArrayList<URL>();
			Enumeration<URL> e=null;
			try {
				e = classLoader.getResources(classname+".class");
				while (e.hasMoreElements()) {
					urls.add(e.nextElement());
				};
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			// Select the last URL in the list, that is the one this member was found
			if (urls.size()>0) {
				url=urls.get(urls.size()-1);
			} else {
				logger.severe(e.toString());
				throw new ClassNotFoundException("Resource not found: "+classname);
			}
			classInputStream=url.openStream();
			cr = new ClassReader(classInputStream);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			logger.severe(classname+": "+e.getMessage());
			e.printStackTrace();
		}
		ClassScanner classScanner = new ClassScanner(url);
		// start parsing, this will call the ASM Visitor
		cr.accept(classScanner, 0);

		return members;
	}
	/**
	 * 
	 * @return A set of Strings containing the internal class names (with / and not with .)
	 */
	public Set<String> getToBeIncludedClasses() {
		// TODO Auto-generated method stub
		Set<String> classes=new HashSet<String>();
		for (Member m:referencedMembers) {
			classes.add(m.getOwner());
		}
		return classes;
	}
	// scan()
	private ClassLoader classLoader;


	/**
	 * @return the referencedMembers
	 */
	public ReferencedMembers<Member> getReferencedMembers() {
		return referencedMembers;
	}
	/**
	 * Experimental: print the tree.
	 * @return
	 */
	private void printTree(TreeModel tree) {
		MemberTreeNode node=(MemberTreeNode) tree.getRoot();
		StringBuilder sb=new StringBuilder(1000);
		Enumeration<MemberTreeNode> enumeration=node.preorderEnumeration();//.depthFirstEnumeration();
		while (enumeration.hasMoreElements()) {
			MemberTreeNode n;
			n=enumeration.nextElement();
			int level=n.getLevel();
			// Print spaces to indent deeper levels. Print the empty string over n.getLevel positions
			// If level==0, then format throws exception
			if (level>0) {
				sb.append(String.format("%"+level+"s",""));
			}
			// member can be null for root node
			Object userObject=n.getUserObject();
			if (userObject!=null) {
				// Might be a "symbolic link" to another original
				logger.finest("Print tree: "+userObject.toString());
				if (userObject instanceof Member) {
					sb.append(userObject.toString()).append("\n");
				} else if (userObject instanceof TreeNode) {
					// treeNode's userObject is the treeNode with the original Member
					Object member=((MemberTreeNode)userObject).getUserObject();
					sb.append("*").append(member).append("\n"); //indicate with the * that this not the original
				} else {
					sb.append("Unknown userObject:"+userObject).append("\n");
				}
			}
		}
		logger.fine("Tree:\n"+sb.toString());
	}
	/**
	 * Remove all entries from referencedMembers that are not used,
	 * i.e. empty Class definitions
	 */
	private void cleanUpReferencedMembers() {
		logger.info("Start cleanUpreferencedMembers()");
		for (Iterator<Member> ite=referencedMembers.iterator();ite.hasNext();) {
			// find all empty members, i.e. no field/method present
			Member m=ite.next();
			if (m.getName()==null || m.getName().isEmpty()) {
				// empty, must be removed
				logger.fine("Removing "+m);
				ite.remove();
			}
		}
	}

	private void removeDirectoryTree(File directory) {
		//
		// Remove all files from the outputdirectory. Stupid that it has
		// to be so difficult in java
		//
		File[] currList;
		Stack<File> stack = new Stack<File>();
		stack.push(directory);
		while (! stack.isEmpty()) {
			if (stack.lastElement().isDirectory()) {
				logger.fine("Remove old files, list "+stack.lastElement().toString());
				currList = stack.lastElement().listFiles();
				if ((currList!=null) && currList.length > 0) {
					for (File curr: currList) {
						logger.fine("Remove old files, push (a):"+curr);
						stack.push(curr);
					}
				} else {
					logger.fine("Remove old files, del (a):"+stack.peek().toString());
					boolean result=false;
					File f=stack.peek();
					result=stack.pop().delete();
					if (!result) {
						logger.severe("Remove old files, delete of "+f+" failed");
						System.exit(5); // prevent unexplainable output
					}
				}
			} else {
				logger.fine("Remove old files, del (b):"+stack.peek().toString());
				boolean result=false;
				File f=stack.peek();
				result=stack.pop().delete();
				if (!result) {
					logger.severe("Remove old files, delete of "+f+" failed");
					System.exit(6); // prevent unexplainable output
				}
			}
		}

	}
	//
	// outh and outc
	//
	/**
	 * File haikuJava.h
	 */
	private BufferedWriter outh = null;
	/**
	 * File haikuJava.c
	 */
	private BufferedWriter outc = null;
	/**
	 * File haikuJ2C.h
	 */
	private BufferedWriter outj2ch = null;
	/**
	 * File haikuJ2C.c
	 */
	private BufferedWriter outj2cc = null;

	/**
	 * Create the stripped java target class files in the outputdirectory
	 * @param outputdirectory The directory into which te Java class files are to be written
	 */
	public void createClassFiles(final File outputdirectory) {
		//
		// Remove old class files in outputdirectory
		//
		removeDirectoryTree(outputdirectory);
		//
		// Clean up the Set with the members (not needed)
		//
		cleanUpReferencedMembers();
		//
		// Show the classes
		//
		TreeSet<String> owners=getOwners();
		StringBuilder sb=new StringBuilder(100*owners.size());
		for (String s:owners) {
			sb.append(s).append("\n");
		}
		logger.fine("Classes used:\n"+sb.toString());
		//
		// Temporary!!!!! outh and outc !!!
		//
		try {
			outputdirectory.mkdirs();
			File file=new File(outputdirectory,"haikuJava.h");
			file.createNewFile();
			FileWriter fileWriter=new FileWriter(file);
			outh=new BufferedWriter(fileWriter);

			file=new File(outputdirectory,"haikuJava.c");
			file.createNewFile();
			fileWriter=new FileWriter(file);
			outc=new BufferedWriter(fileWriter);

			outputdirectory.mkdirs();
			file=new File(outputdirectory,"haikuJ2C.h");
			file.createNewFile();
			fileWriter=new FileWriter(file);
			outj2ch=new BufferedWriter(fileWriter);

			file=new File(outputdirectory,"haikuJ2C.c");
			file.createNewFile();
			fileWriter=new FileWriter(file);
			outj2cc=new BufferedWriter(fileWriter);
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		//
		// Write comment into the file
		//
		String cmg="resources/CommentMachineGenerated.txt";
		ClassLoader classLoader = Thread.currentThread().getContextClassLoader();
		InputStream machGeneratedCommentStream=classLoader.getResourceAsStream(cmg);
		if (machGeneratedCommentStream==null) {
			logger.severe("Cannot find resource "+cmg);
			System.exit(11);
		}
		Reader reader=new InputStreamReader(machGeneratedCommentStream); // use default charset
		// Read the resource and write into outputstreams outh and outc
		// (this is the warning that the outh and outc are machine generated and not to be
		// edited by hand).
		char[] b=new char[2000];
		int len=0;
		try {
			while ((len=reader.read(b))>0) {
				outh.append(new String(b,0,len));
				outc.append(new String(b,0,len));
			}
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		//
		// Write declarations into .c file
		try {
			outc.write("\n#include \"haikuConfig.h\"\n");
			outc.write("#include \"haikuJava.h\"\n\n");

			outj2cc.write("\n#include <stdlib.h>\n#include <stdio.h>\n#include <stdarg.h>\n");
			outj2cc.write("#include <string.h>\n\n#include \"haikuJ2C.h\"\n");
			outj2cc.write("#include \"utility/haikuConfig.h\"#include \"simpleOS.h\"\n\n");
			outj2cc.write("\n\n#if TRACEING\nint indent=0;\n#endif\n\n");
			outj2cc.write("#define Debug(x)\n\njstack dataSp;\njstack lsp;\nunsigned char * pc;");
			outj2cc.write("stackFrame4Debug_t* stack;\n\ntop_t top;");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//
		// Loop over all classes to generate the (stripped) class files
		//
		for (String c:owners) {
			createClassFile(c,outputdirectory);
		}
		try {
			outh.close();
			outc.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//
		// Select the invokemethod calls to be compiled as invokeshort
		//
		selectInvokeShortMethodCalls();
		//
		// Create some statistics
		//
		numberOfClasses=owners.size();

		logger.info("Number of classes    :"+numberOfClasses);
		logger.info("Number of fields     :"+numberOfFields);
		logger.info("Number of methods    :"+numberOfMethods);
		logger.info("Number of bytecodes  :"+distinctBCs.size());

		printTree(tree);
	}
	/**
	 * Select the methods that are to be compiled as invokeshort byte code
	 */
	private void selectInvokeShortMethodCalls() {
		int numberOfSpares=250-distinctBCs.size(); // the available space
		// Select the methods with most of invocation
		// Select only methods (not fields). For performance reasons, do it in a Set
		ArrayList<Member> referencedMethods=new ArrayList<>();
		for (Member m:referencedMembers) {
			if (m.isMethod()) {
				referencedMethods.add(m);
			}
		}
		// Sort by max. use count
		Collections.sort(referencedMethods,new Comparator<Member>() {
			public int compare(Member m1,Member m2) {
				if (m1.getUseCount()>m2.getUseCount()) {
					return -1;
				} else if (m1.getUseCount()<m2.getUseCount()) {
					return 1;
				} else {
					return 0; // equal
				}
			}
		});
		for (int i=0;i<numberOfSpares;i++) {
			Member m=referencedMethods.get(i);
			// Indicate that this member is available for invokeshort calls
			m.setInvokeShortIndex(i);
		}

	}
	private int numberOfClasses;
	private int numberOfFields;
	private int numberOfMethods;
	private Set<Integer> distinctBCs=new HashSet<Integer>(); // track unique BC

	public Set<Integer> getDistinctBCs() {
		return distinctBCs;
	}
	/**
	 * Create the stripped class file.
	 * Writing the class file is not necessary. TODO
	 */
	public void createClassFile(final String internalClassname,File outputdirectory) {
		outputdirectory.mkdirs();
		if (!outputdirectory.isDirectory()) {
			String message="parameter outputdirectory is not a directory (";
			try {
				message=message+outputdirectory.getCanonicalPath()+")";
			} catch (IOException e) {
				message=message+"<file name unknown, exception occurred>)";
				// TODO Auto-generated catch block
			}
			finally {
				logger.severe(message);
				throw new IllegalArgumentException(message);
			}
		}
		if (!outputdirectory.canWrite()) {
			String message="outputdirectory is not writable (";
			try {
				message=message+outputdirectory.getCanonicalPath()+")";
			} catch (IOException e) {
				message=message+"<file name unknown, exception occurred>)";
				// TODO Auto-generated catch block
			}
			finally {
				logger.severe(message);
				throw new IllegalArgumentException(message);
			}
		}
		/**
		 * The class that makes code into readable text. ?? It doesn't do what we want
		 */
		@Deprecated
		final Textifier textifier=new Textifier();
		//
		// Loop over all classes that are used
		// and extract only the members (methods/fields)
		// that are used.
		//

		// Do the plumbing
		ClassReader cr = null;
		// Open the input class file
		try {
			InputStream classInputStream;
			// replace the dots in the classname into slashed to convert to internal classname format
			classInputStream=classLoader.getResourceAsStream(internalClassname + ".class");
			cr = new ClassReader(classInputStream);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		// start parsing
		ClassWriter cw = new ClassWriter(cr,0 /*org.objectweb.asm.ClassWriter.COMPUTE_FRAMES*/);
		// Create a ClassVisitor that forwards calls to the visitor named as its parameter,
		// see http://download.forge.objectweb.org/asm/asm4-guide.pdf
		J2COutputGenerator j2cog=new J2COutputGenerator(Opcodes.ASM5, cw, outc, outh);
		COutputGenerator og=new COutputGenerator(Opcodes.ASM5, j2cog,outc, outh,referencedMembers);
		// This is the first visitor, that delegates calls to og
		CreationClassVisitorAdapter ca = new CreationClassVisitorAdapter(og, referencedMembers);
		cr.accept(ca, 0);
		// Update some statistics that were created during the asm pass
		

		distinctBCs.addAll(ca.getDistinctBCs());
		numberOfFields+=ca.getNumberOfFields();
		numberOfMethods+=ca.getNumberOfMethods();
		
		// Create an outputfile in the outputdirectory in a subdirectory for the given package/class
		// This is not used, but nice for a test
		File classFile=new File(outputdirectory,internalClassname+".class");
		classFile.delete(); // delete old file (a bit of overkill, it was already removed)
		try {
			classFile.getParentFile().mkdirs(); // create directory to output file
			classFile.createNewFile();
			FileOutputStream fos=new FileOutputStream(classFile);
			fos.write(cw.toByteArray());
			fos.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	} // method createclassfile

	/**
	 * No clue as what this method should do
	 * (Closure.isMarked(jc.getClassName()+"."+method.getName()+method.getSignature())
	 * Cannot be implemented, is static method !!!
	 * 
	 * nl.vandenzen.hallo(IIIJ)Z
	 */
	@Deprecated
	public static boolean isMarked(String memberAsString) {
		// Maybe this is meant? Is it included in this set
		// Difficult parse
		// Class is everything before the last dot.
		// Method/field name is the part between the class and the signature
		// Everything after the opening ( is signature
		Pattern pattern=Pattern.compile("(.*)\\.(.*)(\\(.*\\))");
		Matcher matcher=pattern.matcher(memberAsString);
		String className = null;
		String methodName = null; // or field?
		String signature = null;

		if (matcher.matches()) {
			// OK, the string matches, find the three parts of it
			className=matcher.group(1);
			methodName=matcher.group(2);
			signature=matcher.group(3);
		}
		Member member=new Member(className, methodName, signature);
		// Cannot be implemented, I give up, return true
		return true;
	}
	/**
	 * No clue as what this method should do
	 * (Closure.isMarked(jc.getClassName()+"."+method.getName()+method.getSignature())
	 */
	public boolean isMarked(Member member) {
		return referencedMembers.contains(member);
	}
	/*
	 * This section handles clinit (class init, static init).
	 * It needs some fields, maybe it should go into a
	 * separate (sub)class.
	 */
	// Collect all <clinit> Members with their level
	private Map<Member,Integer> clinits;
	private Set<MemberTreeNode> clinitsSeenNodes=new HashSet<>();
	/**
	 * List all <clinit> methods in the order that they should be executed.
	 * TODO: is this ordering the right one????
	 * @return An ArrayList with Members that are <clinit> "methods". The ordering
	 * is the order in which the <clinit> methods should be called for initialisation.
	 */
	public ArrayList<Member> listClinitsInOrder() {
		// Collect all <clinit> Members with their level
		clinits=new HashMap<Member,Integer>() {
			/**
			 * 
			 */
			private static final long serialVersionUID = -2481500828723287858L;

			@Override
			public Integer put(Member m, Integer level) {
				logger.info("clinits.put level="+level+", member="+m);
				return super.put(m,level);
			}
		};

		logger.fine("Enter");
		// Enumerate all nodes

		MemberTreeNode node=(MemberTreeNode) tree.getRoot();
		// The first is at level 0, so levelAdjust is 0.
		listClinitsInOrder(node,0);
		logger.fine("1");
		// Find available levels and sort them (automatically by TreeSet)
		TreeSet<Integer> levels=new TreeSet<Integer>();
		levels.addAll(clinits.values());

		ArrayList<Member> returnValue=new ArrayList<Member>();
		// Fill the ArrayList. Start with lower levels
		for (int l:levels) {
			// todo make more efficient
			for (Map.Entry<Member,Integer> e:clinits.entrySet()) {
				if (e.getValue().equals(l)) {
					returnValue.add(e.getKey());
					break;
				}
			}
		}
		logger.fine("hallo1");
		StringBuilder sb=new StringBuilder();
		sb.append("<clinit>s:\n");
		for (int i=0;i<returnValue.size();i++) {
			sb.append("<clinit> ").append(returnValue.get(i)).append("\n");
		}
		sb.append("<clinit>s end of list");
		logger.fine(sb.toString());
		return returnValue;

	}
	/**
	 * Collect all <clinit> methods in the order that they should be executed.
	 * Start at node, levelAdjust gives the level of this node.
	 * @param node
	 * @param levelAdjust
	 */
	private void listClinitsInOrder(MemberTreeNode node,int levelAdjust) {
		// Walk the tree. The lower levels are the methods that should be
		// executed first.
		// The implementation of the tree is not straight-forward. It can contain
		// "symbolic links". These links could lead to lower-leveled calls to the method:
		// Consider a <clinit> that is for the first time seen in the tree at level 10.
		// If later-on (in the scan phase), the same <clinit> is called, but at level 2,
		// this level 2 node will contain a link to the original <clinit> method at level 10.
		// But in fact, its effective lowest level is 2, not 10.
		// This could also happen in a more hidden way: a call to a method that eventually
		// calls the <clinit> method.

		// Check whether this is an already known node
		if (clinitsSeenNodes.contains(node)) {
			return;
		}
		clinitsSeenNodes.add(node);
		// Enumerate all nodes

		//MemberTreeNode node=(MemberTreeNode) tree.getRoot();
		StringBuilder sb=new StringBuilder(1000);
		// Enumerate lowest levels first, but that is not necessary, implementation is not straight-forward
		Enumeration<MemberTreeNode> enumeration=node.breadthFirstEnumeration();// .preorderEnumeration();//.depthFirstEnumeration();
		while (enumeration.hasMoreElements()) {
			MemberTreeNode n;
			n=enumeration.nextElement();
			int level=n.getLevel();
			Object userObject=n.getUserObject();
			if (userObject!=null) {
				if (userObject instanceof Member) {
					// Is it a clinit?
					Member member=(Member) userObject;
					logger.finer("<clinits> member="+member);
					if ("<clinit>".equals(member.getName())) {
						// Lookup this member in our map
						Integer recordedLevel=clinits.get(member);
						if (recordedLevel==null) {
							// This is the first time we see this <clinit>
							clinits.put(member, level+levelAdjust);
						} else {
							// There is already mapping
							if (recordedLevel>level+levelAdjust) {
								clinits.put(member, level+levelAdjust);
							}
						}
					}
				} else if (userObject instanceof MemberTreeNode) {
					// This is a "symbolic link" to another tree. Follow it.
					MemberTreeNode newNode=(MemberTreeNode) userObject;
					logger.finer("<clinits> node="+newNode);
					listClinitsInOrder(newNode, levelAdjust);
				} else {
					String message="userObject is invalid:"+userObject;
					logger.severe(message);
					throw new IllegalArgumentException(message);
				}
			}
		}
	}

	/**
	 * Collect all used class names, replace separator with _ and return
	 * the ordered collection (automatically ordered by use of TreeSet).
	 * @return
	 */
	public TreeSet<String> getMangledClassNames() {
		TreeSet<String> classNames=new TreeSet<>();
		// Loop over all referencedMembers and select the owner (=classname with / separator)
		for (Member m:referencedMembers) {
			classNames.add(m.getMangledClassName());
		}
		return classNames;
	}

	/**
	 * Collect all used class names, replace separator with . and return
	 * the ordered collection (automatically ordered by use of TreeSet).
	 * @return
	 */
	public TreeSet<String> getClassNames() {
		TreeSet<String> classNames=new TreeSet<>();
		// Loop over all referencedMembers and select the owner (=classname with / separator)
		for (Member m:referencedMembers) {
			classNames.add(m.getClassName());
		}
		return classNames;
	}

	/**
	 * Collect all used class names (internal format, with / as separator) and return
	 * the ordered collection (automatically ordered by use of TreeSet).
	 * @return
	 */
	public TreeSet<String> getOwners() {
		TreeSet<String> ownerNames=new TreeSet<>();
		// Loop over all referencedMembers and select the owner (=classname with / separator)
		for (Member m:referencedMembers) {
			ownerNames.add(m.getOwner());
		}
		return ownerNames;
	}
	/**
	 * Original version by genom2 in ClassTable.java, toString().
	 * Output goes into haikuConfig.c
	 * 
	 * 

#if _DEBUG || NO_MICRO

char classDesc000[] PROGMEM ="free block";
char classDesc001[] PROGMEM ="arduino.libraries.dfr0009.Keypad";
char classDesc002[] PROGMEM ="arduino.libraries.dfr0009.Keypad$1";
char classDesc003[] PROGMEM ="arduino.libraries.liquidcrystal.LiquidCrystal";
char classDesc004[] PROGMEM ="haiku.avr.lib.arduino.HaikuMicroKernel4ArduinoIDE";
char classDesc005[] PROGMEM ="haiku.vm.MicroKernel";
char classDesc006[] PROGMEM ="java.io.IOException";
char classDesc007[] PROGMEM ="java.io.InputStream";
..

char classDesc137[] PROGMEM ="processing.hardware.arduino.cores.arduino.HardwareSerial";
char classDesc138[] PROGMEM ="processing.hardware.arduino.cores.arduino.HardwareSerialImpl";
char classDesc139[] PROGMEM ="processing.hardware.arduino.cores.arduino.Print";
char classDesc140[] PROGMEM ="processing.hardware.arduino.cores.arduino.Stream";

const char *	classDesc[] PROGMEM = {
	classDesc001,
	classDesc002,
	classDesc003,
	classDesc004,
	classDesc005,
	classDesc006,
	classDesc007,
..

	classDesc140,
	classDesc000,
};

//Needed for Heap and Stack debugging
const jclass    classTable[] PROGMEM = {
	(jclass)&arduino_libraries_dfr0009_Keypad__class,
	(jclass)&arduino_libraries_dfr0009_Keypad_1__class,
	(jclass)&arduino_libraries_liquidcrystal_LiquidCrystal__class,
	(jclass)&haiku_avr_lib_arduino_HaikuMicroKernel4ArduinoIDE__class,
	(jclass)&haiku_vm_MicroKernel__class,
	(jclass)&java_io_IOException__class,
	(jclass)&java_io_InputStream__class,
..

	(jclass)&processing_hardware_arduino_cores_arduino_HardwareSerialImpl__class,
	(jclass)&processing_hardware_arduino_cores_arduino_Print__class,
	(jclass)&processing_hardware_arduino_cores_arduino_Stream__class,
	NULL
};
#endif


	 * todo: make it write directly into an outputStream (should be a parameter). This
	 * would make it more efficient (String is unnecessary).
	 * @return
	 */
	public String getCDeclarationForClassString() {
		StringBuilder sb=new StringBuilder();
		// ??? prepareClasses();

		sb.append("\n");
		sb.append("\n");
		sb.append( "#if _DEBUG || NO_MICRO\n");
		sb.append("\n");
		int i=0;
		sb.append(new Formatter().format("char classDesc%03d[] PROGMEM =\"%s\";\n", i++, "free block"));
		for (String name:getMangledClassNames()) {
			sb.append(new Formatter().format("char classDesc%03d[] PROGMEM =\"%s\";\n", i++, name));
		}

		sb.append("\n");
		sb.append("const char *	classDesc[] PROGMEM = {\n");
		for (int j=0;j<i;j++) {
			sb.append(new Formatter().format("\tclassDesc%03d,\n", j));
		}
		sb.append(new Formatter().format("\tclassDesc%03d,\n", 0));
		sb.append("};\n");
		sb.append("\n");
		sb.append("//Needed for Heap and Stack debugging\n");
		sb.append("const jclass    classTable[] PROGMEM = {\n");
		//TreeSet<String> classNames=getMangledClassNames();
		for (String name:getMangledClassNames()) {
			sb.append(new Formatter().format("\t(jclass)&%s__class,\n", name));
		}
		return sb.toString();
	}
	private JFrame frame=new JFrame("TargetApplication methods and fields");

	public void showTreeInNewFrame() {

		// Create a lock to wait for window close
		final Semaphore sema=new Semaphore(0);
		//Schedule a job for the event-dispatching thread:
		//creating and showing this application's GUI.
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				JTree jTree=new JTree(tree);
				JScrollPane treeView = new JScrollPane(jTree);
				int width=8000; // max width
				int height=2000; // max height
				Dimension maxDimension=new Dimension(width, height);
				//jTree.setMaximumSize(maxDimension);
				//treeView.setMaximumSize(maxDimension); //doesn't help
				//frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				Container newContentPane = frame.getContentPane();// treeView;
				//newContentPane.setMaximumSize(maxDimension); // doesn't help
				newContentPane.add(treeView,BorderLayout.CENTER);
				//newContentPane.setPreferredSize(maxDimension);
				//newContentPane.setOpaque(true); //content panes must be opaque
				//frame.setContentPane(newContentPane);
				frame.pack();
				frame.setVisible(true);
				//createAndShowGUI(); 
			}
		});
		frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosed(WindowEvent e) {
				logger.fine("Window closed");
				sema.release();		}
			@Override
			public void windowClosing(WindowEvent e) {
				logger.fine("Window closing");
				sema.release();
			}
		});
		logger.fine("Display frame");
		try {
			sema.acquire();
		} catch (InterruptedException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		logger.fine("Display frame end");
	}
	private ReferencedMembers<Member> referencedMembers=new ReferencedMembers<>();

	private Map<String,HaikuClassNode> classNodes=new HashMap<String,HaikuClassNode>();

	final static private Logger logger=Logger.getLogger("haikuvm.pc.tools");
	// Not used, but could be useful:
	// http://stackoverflow.com/questions/5445511/how-do-i-create-a-parent-last-child-first-classloader-in-java-or-how-to-overr

}
