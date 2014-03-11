package haikuvm.pc.tools.asmvisitors;
import haikuvm.pc.tools.Member;
import haikuvm.pc.tools.ReferencedMembers;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.Date;
import java.util.HashSet;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.objectweb.asm.AnnotationVisitor;
import org.objectweb.asm.Attribute;
import org.objectweb.asm.ClassVisitor;
import org.objectweb.asm.FieldVisitor;
import org.objectweb.asm.MethodVisitor;
import org.objectweb.asm.Opcodes;
import org.objectweb.asm.TypePath;
import org.objectweb.asm.util.Textifier;
import static org.objectweb.asm.util.Printer.OPCODES;

/**
 * This class will fill the haikuJava.h and haikuJava.c (into outc and outh)
 * @author CDN
 *
 */
public class COutputGenerator extends org.objectweb.asm.ClassVisitor {

	protected Writer outh;
	protected Writer outc;
	/**
	 * For comment in the output file, not for the real code.
	 */
	Textifier outcTextifier=new Textifier();
	/**
	 * For comment in the output file, not for the real code.
	 */
	Textifier outhTextifier=new Textifier();
	/**
	 * The code in the haikuJava.h file
	 * Use a StringBuilder as intermediate storage, to avoid
	 * catching Exceptions that the Writer (outc or outh) might throw.
	 */
	private StringBuilder outhSb=new StringBuilder();
	/**
	 * The code in the haikuJava.c file
	 * Use a StringBuilder as intermediate storage, to avoid
	 * catching Exceptions that the Writer (outc or outh) might throw.
	 */
	private StringBuilder outcSb=new StringBuilder();
	private String owner;
	private ReferencedMembers<Member> referencedMembers;

	class NullWriter extends Writer {
		@Override
		public void close() throws IOException {
			// TODO Auto-generated method stub
		}
		@Override
		public void flush() throws IOException {
			// TODO Auto-generated method stub
		}
		@Override
		public void write(char[] cbuf, int off, int len)
				throws IOException {
			// TODO Auto-generated method stub
		}
	};
	/**
	 * Constructor
	 * @param api Opcodes.ASM5
	 * @param cv The classVisitor to which to forward calls
	 * @param outc The writer to write the C code to
	 * @param outh The writer to write the header file (.h file) code to
	 */
	public COutputGenerator(int api,ClassVisitor cv,Writer outc,Writer outh,ReferencedMembers<Member> referencedMembers) {
		super(api,cv);
		this.outc=outc;
		this.outh=outh;
		this.referencedMembers=referencedMembers;

		// Assure valid values for outc and outh
		if (outc==null) {
			outc=new NullWriter();
		}
		if (outh==null) {
			outh=new NullWriter();
		}
	}

	//	protected COutputGenerator(int api,ClassVisitor cv) {
	//		super(api,cv);
	//	}


	@Override
	public void visit(int version, int access, String name, String signature,
			String superName, String[] interfaces) {
		super.visit(version, access, name, signature, superName, interfaces);
		// Print some comment in the output
		outcSb.append(String.format("/*\nDate: %s\n",new Object[] {new Date().toString()}));
		outcSb.append("/*\nClass "+name+", extends "+superName+"\n*/\n");
		this.owner=name;
		outcTextifier.visit(version, access, name, signature, superName, interfaces);
	}

	public void visitSource(String source, String debug) {
		super.visitSource(source, debug);
		outcTextifier.visitSource(source, debug);
	}
	public void visitOuterClass(String owner, String name, String desc) {
		super.visitOuterClass(owner, name, desc);
		outcTextifier.visitOuterClass(owner, name, desc);
	}
	public AnnotationVisitor visitAnnotation(String desc, boolean visible) {
		outcTextifier.visitAnnotation(desc, visible);
		return super.visitAnnotation(desc, visible);
	}
	public AnnotationVisitor visitTypeAnnotation(int typeRef,
			TypePath typePath, String desc, boolean visible) {
		if (api < Opcodes.ASM5) {
			throw new RuntimeException();
		}
		outcTextifier.visitTypeAnnotation(typeRef, typePath, desc, visible);
		return super.visitTypeAnnotation(typeRef, typePath, desc, visible);
	}
	public void visitAttribute(Attribute attr) {
		outcTextifier.visitAttribute(attr);
		super.visitAttribute(attr);
	}
	public void visitInnerClass(String name, String outerName,
			String innerName, int access) {
		outcTextifier.visitInnerClass(name, outerName, innerName, access);
		super.visitInnerClass(name, outerName, innerName, access);
	}
	public FieldVisitor visitField(int access, String name, String desc,
			String signature, Object value) {
		outcTextifier.visitField(access, name, desc, signature, value);
		return super.visitField(access, name, desc, signature, value);
	}
	public MethodVisitor visitMethod(int access, String name, String desc,
			String signature, String[] exceptions) {
		// Create a Member of this method
		Member member=new Member(access,owner,name,desc,signature,exceptions);
		outcTextifier.visitMethod(access, name, desc, signature, exceptions);
		// Forward the call to the next ClassVisitor and store the MethodVisitor it returns(?)
		MethodVisitor mv=null;
		mv=super.visitMethod(access, name, desc, signature, exceptions);
		// if mv is null, nobody is interested in this method
		if (mv!=null) {
			// Should this method be included?
			Member mr=referencedMembers.get(owner,name,desc);
			// if this member was selected to be called via invokeshort:
			if (mr==null) {
				logger.finest("This method is not included, do not process it: "+member);
			} else {
				// chain the MethodVisitors
				mv=new COutputMethodAdapter(api,mv,outcSb,outhSb,member);
			}
		}
		return mv;
	}
	/*
	 * (non-Javadoc)
	 * This is the end of the class visit
	 * @see org.objectweb.asm.ClassVisitor#visitEnd()
	 */
	public void visitEnd() {
		super.visitEnd();
		// print the collected texts
		// print the comments EXPERIMENTAL

		StringBuilder sbc=new StringBuilder();
		// Start a comment
		sbc.append("/*\noutcTextifier text:\n");
		for (Object o:outcTextifier.text) {
			sbc.append(o.toString());
		}
		// End the comment tag
		sbc.append("\n*/\n");
		// Prepend this Textifier output to the regular output
		outcSb.insert(0, sbc);

		// Print the .h comments
		StringBuilder sbh=new StringBuilder();
		sbh.append("/*\nouthTextifier text:\n");
		for (Object o:outhTextifier.text) {
			sbh.append(o.toString());
		}
		// End comment tag
		sbh.append("\n*/\n");
		// Prepend this Textifier output to the regular output
		outhSb.insert(0, sbh);

		// Write the content, as collected in the StringBuilders outcSb and outhSb
		// to the output writers
		try {
			outc.append(outcSb.toString());
			outh.append(outhSb.toString());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	class COutputMethodAdapter extends MethodVisitor {
		private StringBuilder outcSb;
		private StringBuilder outhSb;
		private Member member;
		private int opcodeCounter=0; // to create unique identifiers for opcodes
		/**
		// Because the method stack frame must be computed, and the counts must be
		// output first (before the code), we keep track of the position where to
		 * insert these counts (maxStack, maxLocals, paramsize)
		 */
		private int insertionPointForMaxs=0;

		public COutputMethodAdapter(int api,MethodVisitor mv,StringBuilder outcSb,StringBuilder outhSb,Member member) {
			super(api,mv);
			this.outcSb=outcSb;
			this.outhSb=outhSb;
			this.member=member;
		}
		/**
		 * This does not work for api version <ASM5 (java 8?)
		 */
		@Override
		public void visitParameter(String name, int access) {
			super.visitParameter(name, access);
		}
		@Override
		public void visitCode() {
			super.visitCode();
			logger.finest("code for "+member);
			outcSb.append(String.format("const %s_t\n  %s PROGMEM = {\n",
					new Object[] {member.getMangledName(),member.getMangledName()}));
			// Later on, the maxStack etc. must be inserted at this position, so remember it
			insertionPointForMaxs=outcSb.length();
			outhSb.append("typedef struct {\n"
					+"uint8_t max_stack; int8_t purLocals; uint8_t purParams;\n");
		}
		@Override
		public void visitInsn(int opcode) {
			super.visitInsn(opcode); // calls mv.visitInsn if mv!=null
			outcTextifier.visitInsn(opcode);
			// Print the name of the opcode
			outcSb.append(org.objectweb.asm.util.Printer.OPCODES[opcode]);
			outhSb.append(String.format("OP_bc op%d;",opcodeCounter++));
		}

		@Override
		public void visitIntInsn(int opcode, int operand) {
			super.visitIntInsn(opcode, operand);
			// Print the name of the opcode
			outcSb.append(org.objectweb.asm.util.Printer.OPCODES[opcode]).append(",");
			outhSb.append(String.format("OP_bc op%d,",opcodeCounter++)).append(",");
			switch(opcode) {
			case Opcodes.BIPUSH:
				// byte
				outcSb.append("B(").append(operand).append("),\n");
				outhSb.append(String.format("OP_bc op%d,\n",opcodeCounter++));
				break;
			case Opcodes.SIPUSH:
				// short
				outcSb.append("INT16(").append(operand).append("),\n");
				outhSb.append(String.format("OP_bc op%d,\n",opcodeCounter++));
				break;
			default:
				outcSb.append("%d,\n");
				outhSb.append(String.format("int operand%d\n",opcodeCounter++));
				break;
			}
		}
		@Override
		public void visitMethodInsn(int opcode,String owner,String name,String desc) {
			// invoke a method
			super.visitMethodInsn(opcode,owner,name,desc);
			// Go find the Member in referencedMembers
			Member m=new Member(owner,name,desc);
			Member mr=referencedMembers.get(owner,name,desc);
			// if this member was selected to be called via invokeshort:
			if (mr==null) {
				logger.severe("member not found, very strange: "+m);
				System.exit(11);
			}
			if (mr.getInvokeShortIndex()>=0) {
				outcSb.append(mr.getInvokeShortIndex());
				outhSb.append(String.format("OP_bc invokeshort%d, // invokeshort %s\n", opcodeCounter++,mr.getMangledName()));
			} else {
				outcSb.append(String.format("%s, ADR(%s), // invoke \n",OPCODES[opcode], mr.getMangledName()));
				outhSb.append(String.format("OP_bc op%d, int operand%d",opcodeCounter++,opcodeCounter++));
			}
		}
		@Override
		public void visitVarInsn(int opcode, int var) {
			super.visitVarInsn(opcode, var);
			// Print the name of the opcode
			outcSb.append(org.objectweb.asm.util.Printer.OPCODES[opcode]).append(",");
			outcSb.append("B(").append(var).append(")\n");
		}
		@Override
		public void visitTypeInsn(int opcode, String type) {
			super.visitTypeInsn(opcode, type);
			// Print the name of the opcode
			outcSb.append(org.objectweb.asm.util.Printer.OPCODES[opcode]).append(",");
			switch(opcode) {
			case Opcodes.NEW:
				outcSb.append("B(").append(type).append("),\n");
				break;
			case Opcodes.ANEWARRAY:
				outcSb.append("ADR(").append(type).append("),\n");
				break;
			}
		}
		@Override
		public void visitMaxs(int maxStack, int maxLocals) {
			int argumentsSize=0; // The size of the parameters ???
			// Calculate paramSize
			argumentsSize=member.getArgumentsSize();
			super.visitMaxs(maxStack, maxLocals);
			// Print out the values
			outcSb.insert(insertionPointForMaxs,
					String.format("%d,%d,%d // max_stack, maxLocals, argumentsSize\n",
							new Object[]{maxStack,maxLocals,argumentsSize}));
		}
		@Override
		public void visitEnd() {
			super.visitEnd();
			outcSb.append("\n}\n");

			// Append the name of the struct definition to the .h file
			outhSb.append(String.format("\n} %s",member.getMangledName()));
		}
	}


	Logger logger=Logger.getLogger("haikuvm.tools.pc");
}
