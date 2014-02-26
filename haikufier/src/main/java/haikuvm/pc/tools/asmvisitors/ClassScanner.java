package haikuvm.pc.tools.asmvisitors;

import static org.objectweb.asm.util.Printer.OPCODES;
import haikuvm.pc.tools.Member;
import haikuvm.pc.tools.MemberTreeNode;
import haikuvm.pc.tools.ReferencedMembers;
import haikuvm.pc.tools.TargetApplicationJavaClasses;

import java.net.URL;
import java.util.Enumeration;
import java.util.HashSet;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.objectweb.asm.AnnotationVisitor;
import org.objectweb.asm.Attribute;
import org.objectweb.asm.ClassVisitor;
import org.objectweb.asm.FieldVisitor;
import org.objectweb.asm.Handle;
import org.objectweb.asm.Label;
import org.objectweb.asm.MethodVisitor;
import org.objectweb.asm.Opcodes;

/**
 * The class that scans the input for used methods and fields.
 * @author CDN
 *
 */
public class ClassScanner extends ClassVisitor {
	private String owner;
	/**
	 * The name of the superclass of this class. It is not very interesting, all
	 * references in Java byte code seem to be fully qualified.
	 */
	private String superName;
	/**
	 * Collection of Members that are to be included in the target application.
	 * This Collection is filled with the Fields and Methods that are referenced (called)
	 * in the Method that is scanned by this class.
	 */
	private ReferencedMembers<Member> referencedMembers=new ReferencedMembers<Member>();
	private ReferencedMembers<Member> fields=new ReferencedMembers<>();
	private ReferencedMembers<Member> methods=new ReferencedMembers<>();
	private Member member;
	private String[] interfaces;
	private int access;
	private boolean memberFound=false;
	private URL url;
	/**
	 * The constructor for the class scanner. The scanner is used to collect
	 * the methods and fields that are to be included in the executable for the target
	 * machine.
	 * It scans the given method and returns a Set of Members that are called by the given method ????
	 * @param member The method to scan for references to other methods and fields
	 */
	public ClassScanner(Member member) {
		super(Opcodes.ASM5);
		this.member=member;
	}
	/**
	 * Create a ClassScanner that only  reports the members in the class and that does not scan
	 * any method in the class
	 */
	public ClassScanner(URL url) {
		this((Member)null);
		this.url=url;
	}
	public void visit(int version, int access, String name,
			String signature, String superName, String[] interfaces) {
		logger.log(Level.INFO,"Start visit() version={0}, access={1},name={2},signature={3},superName={4}",
				new Object[]{version,access,name,signature,superName});
		//System.out.println(name + " extends " + superName + " { /* treeNode="+treeNode+" */");
		// name is the internal class name (e.g. lejos/addon/keyboard/KeyEvent)
		this.access=access;
		this.owner=name;
		this.superName=superName;
		this.interfaces=interfaces;
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
		fields.add(new Member(access,owner,name,desc,signature,(String[])null,url));
		return null;
	}
	@Override
	public MethodVisitor visitMethod(int access, final String name,
			String desc, String signature, String[] exceptions) {
		// test MethodVisitor mv1=super.visitMethod(access, name, desc, signature, exceptions);
		logger.fine("visitMethod access="+access+", desc=" + desc + ", signature="+signature+", owner="+owner+", name=" + name);
		Member newMember=new Member(owner,access,name,desc);
		//
		// Is this a method that should be scanned?
		//
		if ("<clinit>".equals(newMember.getName())) { // just for debugging purpose
			logger.fine("<clinit> found for member "+newMember);
		}
		if (
				true
				// if methodName empty, then include all (for interfaces)
				&& (member.getName()!=null && !member.getName().isEmpty())
				&& !"<clinit>".equals(newMember.getName()) // class init must be included
				// Default constructor is not needed to be always included: it will be
				// called explicitly in the Java class code
				// && !("<init>".equals(name) && "()V".equals(desc))
				&& !newMember.getName().equals(member.getName())
				) {
			// Should not be included
			logger.fine(" -- exclude "+newMember+", search member was "+member);
			return null;
		}
		// Yes, this is a method that must be scanned
		// And, for interfaces and the root class, include them. todo: tree must be adjusted?
		// But the tree is maintained in another class
		if (member.getName()==null || member.getName().isEmpty()) {
			referencedMembers.add(newMember);
			logger.fine("Setting newMember to be included, because of wildcard in scan member argument "+member+", newMember="+newMember);
			// An interface method should not be scanned (because it is empty)
			return null; // do not parse this right now, let caller call
		}
		memberFound=true;
		// Parse the bytecode, to look for methods and fields that must be included
		return new MethodVisitor(Opcodes.ASM5) {
			public void visitCode() {
				System.out.println("visitCode()");
				logger.finer("visitCode "+owner+" "+name);
			}
			public void visitFrame(int type, int nLocal, Object[] local, int nStack,
					Object[] stack) {
				logger.finer("visitFrame");
			};
			public void visitInsn(int opcode) {
				logger.finer("visitInsn("+opcode+" "+OPCODES[opcode]+")");
			};
			public void visitIntInsn(int opcode, int operand){
				logger.finer("visitInsn("+opcode+" "+OPCODES[opcode]+","+operand+")");
			};
			public void visitVarInsn(int opcode, int var){
				logger.finer("visitVarInsn("+opcode+" "+OPCODES[opcode]+","+var+")");
			};
			public void visitTypeInsn(int opcode, String desc){
				logger.finer("visitTypeInsn("+opcode+" "+OPCODES[opcode]+","+desc+")");

			};
			public void visitFieldInsn(int opc, String owner, String name, String desc){
				logger.finer("visitFieldInsn("+opc+" "+OPCODES[opc]+","+owner+","+name+","+desc+")");
				// This field must be included in the result, the URL is the same as the caller?
				Member newFieldMember=new Member(owner,name,desc);
				Member existingFieldMember=referencedMembers.get(newFieldMember);
				if (existingFieldMember!=null) {
					// This field has already been seen, increment its use count
					existingFieldMember.incrementUseCount();
				} else {
					// This is the first occurrence of this field
					referencedMembers.add(newFieldMember);
				}
			};
			public void visitMethodInsn(int opc, String owner, String name, String desc) {
				logger.finer("visitMethodInsn("+opc+" "+OPCODES[opc]+","+owner+","+name+", desc="+desc);
				// This field must be included in the result, the URL is the same as the caller?
				Member newMethodMember=new Member(owner,name,desc);
				Member existingMethodMember=referencedMembers.get(newMethodMember);
				if (existingMethodMember!=null) {
					// This method has already been seen, increment its use count
					existingMethodMember.incrementUseCount();
				} else {
					// This is the first occurrence of this method
					referencedMembers.add(newMethodMember);
				}
			};
			public void visitInvokeDynamicInsn(String name, String desc, Handle bsm,
					Object... bsmArgs) {
				logger.finer("visitInvokeDynamicInsn name="+name+", desc="+desc+", bsm="+bsm.toString());
			};

			@Override
			public void visitJumpInsn(int opcode, Label label){};
			@Override
			public void visitLabel(Label label){};
			@Override
			public void visitLdcInsn(Object cst){};
			@Override
			public void visitIincInsn(int var, int increment){};
			@Override
			public void visitTableSwitchInsn(int min, int max, Label dflt, Label... labels){};
			@Override
			public void visitLookupSwitchInsn(Label dflt, int[] keys, Label[] labels){};
			@Override
			public void visitMultiANewArrayInsn(String desc, int dims){};
			@Override
			public void visitTryCatchBlock(Label start, Label end, Label handler,
					String type){
			};
			@Override
			public void visitLocalVariable(String name, String desc, String signature,
					Label start, Label end, int index){
				logger.finer("visitLocalVariable name="+name+", desc="+desc+", signa="+signature
						+", startlabel="+start+", endlabel="+end+", index="+index);
			};
			@Override
			public void visitLineNumber(int line, Label start){};
			@Override
			public void visitMaxs(int maxStack, int maxLocals){};
			@Override
			public void visitEnd(){
				System.out.println("visitEnd()");
			};
		};
	};

	/**
	 * @return the toBeIncludedMembers
	 */
	public ReferencedMembers<Member> getReferencedMembers() {
		return new ReferencedMembers<Member>(referencedMembers);
	}

	/**
	 * @return the access
	 */
	public int getAccess() {
		return access;
	}
	/**
	 * @return the owner, never null. If empty, then the empty String
	 */
	public String getOwner() {
		if (owner==null) return "";
		return owner;
	}
	/**
	 * @return the superName, never null. If empty, then the empty String
	 */
	public String getSuperName() {
		if (superName==null) return "";
		return superName;
	}

	/**
	 * @return the memberFound
	 */
	public boolean isMemberFound() {
		return memberFound;
	}
	/**
	 * @return the interfaces
	 */
	public String[] getInterfaces() {
		return interfaces;
	}

	private static Logger logger=Logger.getLogger("haikuvm.pc.tools");
}
