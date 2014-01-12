package haikuvm.pc.tools;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.text.Format;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Date;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.HashSet;
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

import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreeNode;

import org.junit.experimental.categories.Categories.IncludeCategory;
import org.objectweb.asm.*;

import static org.objectweb.asm.Opcodes.*;
import static org.objectweb.asm.util.Printer.*;
/**
 * December 2013. Try asm instead of bcel.
 * 
 * This class will gather all referenced fields and methods (recursively) (the scan method)
 * and create (the build method) new classes (only the ones used in the given method at scan()) and these classes
 * will only contain the used fields and methods.
 *
 * Advantages asm over bcel:
 * it is maintained
 * it uses the Visitor pattern
 * Disadvantages asm:
 * it it programmed to be fast, not to be stable or to be maintainable
 * 
 * asm reference at http://download.forge.objectweb.org/asm/asm4-guide.pdf
 * 
 * @author Carl van Denzen
 *
 */
public class ClosureCarl {

	/**
	 * Create an instance that will lookup the referenced members in classes that can
	 * be loaded with the specified classloader
	 * @param classLoader The ClassLoader to use for finding referenced classes.
	 */
	public ClosureCarl(ClassLoader classLoader) {
		this.classLoader=classLoader;
		// Create an ASM ClassReader
	}
	/**
	 * A convenience constructor.
	 * Create an instance that will lookup the referenced members in classes that can
	 * be found in the classpath.
	 * @param classpaths
	 */
	public ClosureCarl(String[] classpaths) {
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
	public ClosureCarl(String classpath) {
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
		DefaultMutableTreeNode treeNode=new DefaultMutableTreeNode(rootMember);
		tree=new DefaultTreeModel(treeNode);
		scan(rootMember,treeNode);

		SortedSet<Member> sortedSet=new TreeSet<Member>(toBeIncludedMembers);
		StringBuilder sb=new StringBuilder(1000);
		sb.append("End of scan "+rootMember+ ", included members are:");
		for (Member member:sortedSet) {
			sb.append("\n ++ ").append(member.toString());
		}
		sb.append("End of scan, end of included members");
		logger.fine(sb.toString());
		//System.out.println("} /* "+new Date().toString()+" */");
	}
	/**
	 * Start parsing this method
	 * @param classname
	 * @param member The method or field to be scanned
	 * @param parentTreeNode The position of this element in the tree of included members (for presentational purposes only)
	 * @throws ClassNotFoundException 
	 */
	private void scan(final Member member,final DefaultMutableTreeNode parentTreeNode) throws ClassNotFoundException {
		logger.fine("** Scan "+member+", parentTreeNode="+parentTreeNode);

		/**
		 * The class that scans the input for used methods and fields
		 * @author CDN
		 *
		 */
		class ClassScanner extends ClassVisitor {
			private String owner;
			/**
			 * The name of the superclass of this class. It is not very interesting, all
			 * references in Java byte code seem to be fully qualified.
			 */
			private String superName;
			/**
			 * The members that are part of interfaces this class implements.
			 * The owner of the members is set to the implementing class,
			 * that is the class that is being parsed.
			 */
			private Set<Member> interfaceMembers=new HashSet<Member>();
			/**
			 * If member is not found in this class, it must be looked up in the super class
			 */
			private boolean memberFound;
			//private DefaultMutableTreeNode treeNode;

			public ClassScanner(DefaultMutableTreeNode treeNode) {
				super(Opcodes.ASM5);
				//this.treeNode=treeNode;
			}
			public void visit(int version, int access, String name,
					String signature, String superName, String[] interfaces) {
				logger.log(Level.INFO,"Start visit() version={0}, access={1},name={2},signature={3},superName={4}",
						new Object[]{version,access,name,signature,superName});
				//System.out.println(name + " extends " + superName + " { /* treeNode="+treeNode+" */");
				// name is the internal class name (e.g. lejos/addon/keyboard/KeyEvent)
				this.owner=name;
				this.superName=name;
				memberFound=false;
				// All implemented interfaces must be included, and all their methods.
				StringBuilder sb=new StringBuilder(1000);
				sb.append("Interfaces (ClosureCarl.this="+ClosureCarl.this+")");
				// For all implemented interfaces
				for (String interfacename:interfaces) {
					sb.append("\n").append(interfacename);
					// Set name parameter to empty, then all methods will be included.
					// This is overhead: there is no need to include these interfaces.
					// We will remove them after we have added the real implementations
					// of the class??
					Set<Member> tempInterfaceMembers=new HashSet<>();
					try {
						ClosureCarl interfaceClosure=new ClosureCarl(classLoader);
						Member interfaceMember=new Member(interfacename,"","");
						interfaceClosure.scan(interfaceMember);
						tempInterfaceMembers.addAll(interfaceClosure.toBeIncludedMembers);
					} catch (ClassNotFoundException e) {
						// TODO Auto-generated catch block
						logger.severe(e.toString());
						throw new IllegalArgumentException(e);
					}
					// Include the implementation of the methods in the class we are visiting.
					// Collect the new members in a separate Set to avoid concurrent updates
					for (Member member:tempInterfaceMembers) {
						Member m=new Member(owner,member.getName(),member.getDescriptor());
						this.interfaceMembers.add(m);
						sb.append("\n").append("  i+ "+m);
					}
				}
				logger.fine(sb.toString());
				logger.info("End visit(), owner(=class being parsed)="+owner);
			}
			public void visitSource(String source, String debug) {
			}
			public void visitOuterClass(String owner, String name, String desc) {
				System.out.println("visitOuterClass owner,name,desc="+owner+", "+name+", "+desc);
			}
			public AnnotationVisitor visitAnnotation(String desc,
					boolean visible) {
				return null;
			}
			public void visitAttribute(Attribute attr) {
			}
			public void visitInnerClass(String name, String outerName,
					String innerName, int access) {
				System.out.println("visitInnerClass name,outername,innername,access="+name+", "+outerName+", "
						+innerName+", "+access);
			}
			public FieldVisitor visitField(int access, String name, String desc,
					String signature, Object value) {
				System.out.println("visitField desc=" + desc + ", signature="+signature+" name=" + name);
				// Fields only have to be included if they are referenced in called methods.

				return null;
			}
			@Override
			public MethodVisitor visitMethod(int access, final String name,
					String desc, String signature, String[] exceptions) {
				System.out.println("visitMethod desc=" + desc + ", signature="+signature+", owner="+owner+", name=" + name);
				Member newMember=new Member(owner,name,desc,member.getUrl());
				// Check whether already included
				if (toBeIncludedMembers.contains(newMember)) {
					// Was already inserted, do not parse any further
					logger.fine("visitMethod: "+newMember+" already inserted, return null for MethodVisitor");
					memberFound=true;
					return null;
				};
				//
				// Is this a method that should be included?
				//
				if ((member.getName()!=null && !member.getName().isEmpty()) // if methodName empty, then include all
						&& !"<clinit>".equals(name) // class init must be included
						// && !("<init>".equals(name) && "()V".equals(desc)) // default constructor must be included
						&& !newMember.getName().equals(name)
						&& !interfaceMembers.contains(newMember) // all interfacemembers must be included
						) {
					// Should not be included
					return null;
				}
				// Yes, this method must be included
				toBeIncludedMembers.add(newMember);
				logger.fine("memberFound to true");
				memberFound=true;
				// Make a new node in the tree and add it to its parent
				final DefaultMutableTreeNode treeNode=new DefaultMutableTreeNode(newMember);
				parentTreeNode.add(treeNode);
				// Eclipse would not debug parentTreeNode (cannot resolve to variable)
				logger.finest("parentTreeNode:"+parentTreeNode.toString());
				@SuppressWarnings("unchecked")
				Enumeration<DefaultMutableTreeNode> en=parentTreeNode.children();
				while (en.hasMoreElements()) {
					logger.finest("child="+en.nextElement());
				};
				// Parse the bytecode, to look for other methods that must be included
				return new MethodVisitor(Opcodes.ASM4) {
					public void visitCode() {
						System.out.println("visitCode "+owner+" "+name);
					}
					public void visitFrame(int type, int nLocal, Object[] local, int nStack,
							Object[] stack) {
						System.out.println("visitFrame");
					};
					public void visitInsn(int opcode) {
						System.out.println("visitInsn("+opcode+" "+OPCODES[opcode]+")");
					};
					public void visitIntInsn(int opcode, int operand){
						System.out.println("visitInsn("+opcode+" "+OPCODES[opcode]+","+operand+")");
					};
					public void visitVarInsn(int opcode, int var){
						System.out.println("visitVarInsn("+opcode+" "+OPCODES[opcode]+","+var+")");
					};
					public void visitTypeInsn(int opcode, String desc){
						System.out.println("visitTypeInsn("+opcode+" "+OPCODES[opcode]+","+desc+")");

					};
					public void visitFieldInsn(int opc, String owner, String name, String desc){
						System.out.println("visitFieldInsn("+opc+" "+OPCODES[opc]+","+owner+","+name+","+desc+")");
						// This field must be included in the result, the URL is the same as the caller?
						Member newFieldMember=new Member(owner,name,desc,member.getUrl());
						// Create a new node for this member
						DefaultMutableTreeNode node=new DefaultMutableTreeNode(newFieldMember);
						// This is a child of the method
						node.setParent(treeNode);
					};
					public void visitMethodInsn(int opc, String owner, String name, String desc) {
						System.out.println("visitMethodInsn("+opc+" "+OPCODES[opc]+","+owner+","+name+", desc="+desc);
						// Include this method in the result and check this method for references (recursively)
						// This field must be included in the result, the URL is the same as the caller?
						Member newMethodMember=new Member(owner,name,desc,member.getUrl());
						// Create a new node for this member NO the scan method will do this
						//DefaultMutableTreeNode node=new DefaultMutableTreeNode(newMethodMember);
						// This is a child of the method
						//node.setParent(treeNode);
						try {
							scan(newMethodMember,treeNode);
						} catch (ClassNotFoundException e) {
							logger.severe(e.toString());
							throw new IllegalArgumentException(e);
						}
						//System.out.println("Already included: "+newMember);
					};
					public void visitInvokeDynamicInsn(String name, String desc, Handle bsm,
							Object... bsmArgs) {
						System.out.println("visitInvokeDynamicInsn name="+name+", desc="+desc+", bsm="+bsm.toString());
					};
					public void visitJumpInsn(int opcode, Label label){};
					public void visitLabel(Label label){};
					public void visitLdcInsn(Object cst){};
					public void visitIincInsn(int var, int increment){};
					public void visitTableSwitchInsn(int min, int max, Label dflt, Label[] labels){};
					public void visitLookupSwitchInsn(Label dflt, int[] keys, Label[] labels){};
					public void visitMultiANewArrayInsn(String desc, int dims){};
					public void visitTryCatchBlock(Label start, Label end, Label handler,
							String type){
					};
					public void visitLocalVariable(String name, String desc, String signature,
							Label start, Label end, int index){
						System.out.println("visitLocalVariable name="+name+", desc="+desc+", signa="+signature
								+", startlabel="+start+", endlabel="+end+", index="+index);
					};
					public void visitLineNumber(int line, Label start){};
					public void visitMaxs(int maxStack, int maxLocals){};
					public void visitEnd(){
						System.out.println("visitEnd()");
						if (!memberFound) {
							logger.fine("Trying superclass "+superName);
							// look for it in the super class
							if (superName!=null && !superName.isEmpty()) {
								try {
									scan(new Member(superName,member.getName(),member.getDescriptor()),parentTreeNode);
								} catch (ClassNotFoundException e) {
									// TODO Auto-generated catch block
									String message=e.toString();
									logger.severe(message);
									e.printStackTrace();
									System.exit(7);
								}
							}
						}
					};
				};
			};
		}

		// Skip array types
		if (member.getOwner().startsWith("[")) {
			logger.fine("Skip arraytype="+member);
			return;
		}
		// Create a ClassVisitor (subclass that collects used methods and fields)
		ClassScanner classScanner = new ClassScanner(parentTreeNode);
		ClassReader cr = null;
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

			URL selectedURL=null;
			//classInputStream=classLoader.getResourceAsStream( internalClassname+ ".class");
			if (urls.size()>0) {
				selectedURL=urls.get(urls.size()-1);
			} else {
				logger.severe(e.toString());
				throw new ClassNotFoundException("Resource not found: "+member);
			}
			member.setUrl(selectedURL);
			classInputStream=selectedURL.openStream();
			cr = new ClassReader(classInputStream);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			logger.severe(member+": "+e.getMessage());
			e.printStackTrace();
		}
		// start parsing, this will call the 
		cr.accept(classScanner, 0);
	} // scan()
	private ClassLoader classLoader;


	/**
	 * Experimental: print the tree
	 * @return
	 */
	private void printTree(TreeModel tree) {
		DefaultMutableTreeNode node=(DefaultMutableTreeNode) tree.getRoot();
		StringBuilder sb=new StringBuilder(1000);
		Enumeration<DefaultMutableTreeNode> enumeration=node.preorderEnumeration();//.depthFirstEnumeration();
		while (enumeration.hasMoreElements()) {
			DefaultMutableTreeNode n;
			n=enumeration.nextElement();
			Object member=n.getUserObject();
			int level=n.getLevel();
			// Print spaces to indent deeper levels. Print the empty string over n.getLevel positions
			// If level==0, then format throws exception
			if (level>0) {
				sb.append(String.format("%"+level+"s",""));
			}
			sb.append(member.toString()).append("\n");
		}
		logger.fine("Tree:\n"+sb.toString());
	}
	/**
	 * Remove all entries from toBeIncludedMembers that are not used,
	 * i.e. empty Class definitions
	 */
	private void cleanUpToBeIncludedMembers() {
		logger.info("Start cleanUpToBeIncludedMembers()");
		for (Iterator<Member> ite=toBeIncludedMembers.iterator();ite.hasNext();) {
			// find all empty members, i.e. no field/method present
			Member m=ite.next();
			if (m.getName()==null || m.getName().isEmpty()) {
				// empty, must be removed
				logger.fine("Removing "+m);
				ite.remove();
			}
		}
	}

	/**
	 * The set of methods and fields to be included
	 */
	final private Set<Member> toBeIncludedMembers=new HashSet<Member>() {
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;

		/**
		 * Make the add method do some logging
		 */
		public boolean add(Member member) {
			boolean returnValue=super.add(member);
			if (returnValue) {
				logger.fine("*** toBeIncludedMembers: add "+member);
			}
			return returnValue;
		}
	};
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
	public void createClassFiles(final File outputdirectory) {
		//
		// Remove old class files in outputdirectory
		//
		removeDirectoryTree(outputdirectory);
		//
		// Clean up the Set with the members
		//
		cleanUpToBeIncludedMembers();
		//
		// Sort out the used classes from the toBeIncludedMembers
		//
		SortedSet<String> classes=new TreeSet<String>();
		for (Member member:toBeIncludedMembers) {
			Class<?> cl;
			String internalClassname;
			internalClassname=member.getOwner();
			classes.add(internalClassname);
		}
		//
		// Show the classes
		//
		StringBuilder sb=new StringBuilder(100*classes.size());
		for (String s:classes) {
			sb.append(s).append("\n");
		}
		logger.fine("Classes used:\n"+sb.toString());

		//
		// Create some statistics
		//
		numberOfClasses=classes.size();
		//
		// Loop over all classes to generate the (stripped) class files
		//
		for (String c:classes) {
			createClassFile(c,outputdirectory);
		}
		logger.info("Number of classes    :"+numberOfClasses);
		logger.info("Number of fields     :"+numberOfFields);
		logger.info("Number of methods    :"+numberOfMethods);
		logger.info("Number of bytecodes  :"+distinctBCs.size());

		printTree(tree);
	}
	private int numberOfClasses;
	private int numberOfFields;
	private int numberOfMethods;
	private Set<Integer> distinctBCs=new HashSet<Integer>(); // track unique BC
	
	public Set<Integer> getDistinctBCs() {
		return distinctBCs;
	}
	/**
	 * Create the stripped class file
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
		//
		// Loop over all classes that are used
		// and extract only the members (methods/fields)
		// that are used.
		//
		/**
		 * Define a ClassVisitor that filters the members according to an input Collection
		 * @author CDN
		 *
		 */
		class CreationClassVisitorAdapter extends ClassVisitor {


			private String name;
			private String descriptor;
			public CreationClassVisitorAdapter(ClassVisitor cv) {
				super(Opcodes.ASM4,cv);
			}
			public FieldVisitor visitField(int access, String name, String desc,
					String signature, Object value) {
				// Fields only have to be included if they are referenced in called methods.
				Member newMember=new Member(internalClassname, name,desc);
				if (toBeIncludedMembers.contains(newMember)) {
					// This method should be included in the output
					logger.fine("Create field include ++++"+newMember);
					numberOfFields++;
					return cv.visitField(access,name,desc,signature,value);
				} else {
					//logger.fine("Create field excludes ----"+newMember);
					return null; // do not include this method
				}
			}
			public MethodVisitor visitMethod(int access, String name,
					String desc, String signature, String[] exceptions) {
				Member newMember=new Member(internalClassname,name,desc);
				if (toBeIncludedMembers.contains(newMember)) {
					// This method should be included in the output
					logger.fine("Create method include ++++"+newMember);
					numberOfMethods++;
					//return cv.visitMethod(access,name,desc,signature,exceptions);
					// Collect all distinct byte codes in uniqueBCs.
					return new MethodVisitor(Opcodes.ASM4) {
						public void visitInsn(int opcode) {
							distinctBCs.add(opcode);
						};
						public void visitIntInsn(int opcode, int operand){
							distinctBCs.add(opcode);
						};
						public void visitVarInsn(int opcode, int var){
							distinctBCs.add(opcode);
						};
						public void visitTypeInsn(int opcode, String desc){
							distinctBCs.add(opcode);

						};
						public void visitFieldInsn(int opc, String owner, String name, String desc){
							distinctBCs.add(opc);
						};
						public void visitMethodInsn(int opc, String owner, String name, String desc) {
							distinctBCs.add(opc);

						};
						public void visitInvokeDynamicInsn(String name, String desc, Handle bsm,
								Object... bsmArgs) {
						};
						public void visitJumpInsn(int opcode, Label label){
							distinctBCs.add(opcode);
						};
					};
				} else {
					logger.fine("Create method excludes ----"+newMember);
					return null; // do not include this method
				}
			}
		}
		// Do the plumbing
		ClassReader cr = null;
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
		ClassWriter cw = new ClassWriter(cr, 0);
		CreationClassVisitorAdapter ca = new CreationClassVisitorAdapter(cw);
		cr.accept(cw, 0);
		// Create an outputfile in the outputdirectory in a subdirectory for the given package/class
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
		// class CreationClassVisitorAdapter
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
	static private Logger logger=Logger.getLogger("haikuvm.pc.tools");
	// Not used, but could be useful:
	// http://stackoverflow.com/questions/5445511/how-do-i-create-a-parent-last-child-first-classloader-in-java-or-how-to-overr

}
