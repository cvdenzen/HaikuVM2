package haikuvm.pc.tools.asmvisitors;

import haikuvm.pc.tools.Member;

import java.util.HashSet;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.objectweb.asm.AnnotationVisitor;
import org.objectweb.asm.ClassVisitor;
import org.objectweb.asm.FieldVisitor;
import org.objectweb.asm.Handle;
import org.objectweb.asm.Label;
import org.objectweb.asm.MethodVisitor;
import org.objectweb.asm.Opcodes;


//
// Loop over all classes that are used
// and extract only the members (methods/fields)
// that are used. These members are in set Set referencedMembers.
//		
/**
 * Define a ClassVisitor that filters the members according to an input Collection
 * @author CDN
 *
 */
public class CreationClassVisitorAdapter extends ClassVisitor {

	String internalClassname;
	Set<Member> referencedMembers;
	/**
	 * This constructor is called with a classwriter or -visitor as argument.
	 * @param cv
	 */
	public CreationClassVisitorAdapter(ClassVisitor cv,Set<Member> referencedMembers) {

		super(Opcodes.ASM5,cv);
		this.referencedMembers=referencedMembers;
	}

	@Override
	public void visit(int version, int access, String name,
			String signature, String superName, String[] interfaces) {
		// forward call
		//cv.visit(version, access, name, signature, superName, interfaces);
		super.visit(version, access, name, signature, superName, interfaces);
		this.internalClassname=name;
	}
	@Override
	public AnnotationVisitor visitAnnotation(String desc,boolean visible) {
		logger.log(Level.FINE,"desc={0}, visble={1}",new Object[] {desc,visible});
		// forward call
		return super.visitAnnotation(desc, visible);
	}
	public FieldVisitor visitField(int access, String name, String desc,
			String signature, Object value) {
		// Fields only have to be included if they are referenced in called methods.
		Member newMember=new Member(internalClassname, name,desc);
		if (referencedMembers.contains(newMember)) {
			// This method should be included in the output
			logger.fine("Create field include ++++"+newMember);
			numberOfFields++;
			//textifier.visitField(access, name, desc,  signature, value);
			return super.visitField(access,name,desc,signature,value);
		} else {
			//logger.fine("Create field excludes ----"+newMember);
			return null; // do not include this method
		}
	}
	@Override
	public MethodVisitor visitMethod(final int access, String name,
			String desc, String signature, String[] exceptions) {
		final Member newMember=new Member(internalClassname,access,name,desc);
		if (referencedMembers.contains(newMember)) {
			// This method should be included in the output
			logger.fine("Create method include ++++"+newMember);
			// call the next visitor in the chain
			MethodVisitor mv=cv.visitMethod(access, internalClassname, desc, signature, exceptions);
			numberOfMethods++;
			//return cv.visitMethod(access,name,desc,signature,exceptions);
			// Collect all distinct byte codes in uniqueBCs.
			return new MethodVisitor(Opcodes.ASM5,mv) {
				@Override
				public void visitCode()
				{
					super.visitCode();
					// Insert some special instructions for synchronized methods
					if ((access & Opcodes.ACC_SYNCHRONIZED)!=0) {
						// Insert an extra instruction
						logger.fine("Call insert monitorenter for "+newMember);
						super.visitInsn(Opcodes.MONITORENTER);
					}
				};
				public void visitInsn(int opcode) {
					super.visitInsn(opcode);
					distinctBCs.add(opcode);
					// Write instruction to the textifier
					//textifier.visitInsn(opcode);
				};
				public void visitIntInsn(int opcode, int operand){
					super.visitIntInsn(opcode, operand);
					distinctBCs.add(opcode);
				};
				public void visitVarInsn(int opcode, int var){
					super.visitVarInsn(opcode,var);
					distinctBCs.add(opcode);
				};
				public void visitTypeInsn(int opcode, String desc){
					super.visitTypeInsn(opcode, desc);
					distinctBCs.add(opcode);

				};
				public void visitFieldInsn(int opc, String owner, String name, String desc){
					super.visitFieldInsn(opc, owner, name, desc);
					distinctBCs.add(opc);
				};
				public void visitMethodInsn(int opcode, String owner, String name, String desc) {
					super.visitMethodInsn(opcode, owner, name, desc);
					distinctBCs.add(opcode);
					//textifier.visitMethodInsn(opcode, owner, name, desc);

				};
				public void visitInvokeDynamicInsn(String name, String desc, Handle bsm,
						Object... bsmArgs) {
					super.visitInvokeDynamicInsn(name,desc,bsm,bsmArgs);
				};
				public void visitJumpInsn(int opcode, Label label){
					super.visitJumpInsn(opcode,label);
					distinctBCs.add(opcode);
					//textifier.visitJumpInsn(opcode, label);
				};
				/* (non-Javadoc)
				 * @see org.objectweb.asm.MethodVisitor#visitFrame(int, int, java.lang.Object[], int, java.lang.Object[])
				 */
				@Override
				public void visitFrame(int type, int nLocal,
						Object[] local, int nStack, Object[] stack) {
					try {
						super.visitFrame(type, nLocal, local, nStack, stack);
					}
					catch (Exception ex) {
						logger.log(Level.SEVERE,"Exception in visitFrame",ex);
					}
				}
				@Override
				public void visitEnd() {
					// Insert some special instructions for synchronized methods
					if ((access & Opcodes.ACC_SYNCHRONIZED)!=0) {
						logger.fine("Call insert monitorexit for "+newMember);
						mv.visitInsn(Opcodes.MONITOREXIT);
					}
					super.visitEnd();
				}
			};
		} else {
			logger.fine("Create method exclude ----"+newMember);
			return null; // do not include this method
		}
	} // visitmethod

	/**
	 * @return the distinctBCs
	 */
	public Set<Integer> getDistinctBCs() {
		return distinctBCs;
	}

	/**
	 * @return the numberOfFields
	 */
	public int getNumberOfFields() {
		return numberOfFields;
	}

	/**
	 * @return the numberOfMethods
	 */
	public int getNumberOfMethods() {
		return numberOfMethods;
	}

	/**
	 * This Set contains the used Bytecodes in the class that is visited.
	 */
	private Set<Integer> distinctBCs=new HashSet<Integer>();
	private int numberOfFields;
	private int numberOfMethods;

	private static Logger logger=Logger.getLogger("haikuvm.pc.tools.asmvisitors");
} // class