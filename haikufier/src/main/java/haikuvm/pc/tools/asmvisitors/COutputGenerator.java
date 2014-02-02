package haikuvm.pc.tools.asmvisitors;
import haikuvm.pc.tools.Member;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.Date;
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
	 */
	StringBuilder outhSb=new StringBuilder();
	/**
	 * The code in the haikuJava.c file
	 */
	StringBuilder outcSb=new StringBuilder();
	private String owner;

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
	public COutputGenerator(int api,ClassVisitor cv,Writer outc,Writer outh) {
		super(api,cv);
		this.outc=outc;
		this.outh=outh;

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
		try {
			outc.append("/*\nClass "+name+", extends "+superName+"\n*/\n");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
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
		try {
			outc.append(String.format("const %s_t %s {\n",
					new Object[] {member.getMangledName(),member.getMangledName()}));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		outcTextifier.visitMethod(access, name, desc, signature, exceptions);
		// Forward the call to the next ClassVisitor and store the MethodVisitor it returns(?)
		MethodVisitor mv=null;
		mv=super.visitMethod(access, name, desc, signature, exceptions);
		// if mv is null, nobody is interested in this method
		if (mv!=null) {
			// chain the MethodVisitors
			mv=new COutputMethodAdapter(api,mv,outc,outh);
		}
		return mv;
	}
	public void visitEnd() {
		super.visitEnd();
		// print the collected texts
		// print the comments EXPERIMENTAL
		StringBuilder sbh=new StringBuilder();
		sbh.append("outhTextifier text:\n");
		for (Object o:outhTextifier.text) {
			sbh.append(o.toString());
		}
		logger.finest(sbh.toString());

		StringBuilder sbc=new StringBuilder();
		sbc.append("outcTextifier text:\n");
		for (Object o:outcTextifier.text) {
			sbc.append(o.toString());
		}
		logger.finest(sbc.toString());
		// If there is an outc defined (parameter), write to it
		if (outc!=null) {
			try {
				outc.write(String.format("/*\nDate: %s\n",new Object[] {new Date().toString()}));
				outc.write(sbc.toString());
				outc.write("*/\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		// print the "�ode" as collected in this class
		outhSb.insert(0, "outhSb:\n");
		logger.finest(outhSb.toString());
		outcSb.insert(0, "outcSb:\n");
		logger.finest(outcSb.toString());
	}

	class COutputMethodAdapter extends MethodVisitor {
		private Writer outc;
		private Writer outh;
		public COutputMethodAdapter(int api,MethodVisitor mv,Writer outc,Writer outh) {
			super(api,mv);
			this.outc=outc;
			this.outh=outh;
		}
		@Override
		public void visitInsn(int opcode) {
			super.visitInsn(opcode); // calls mv.visitInsn if mv!=null
			outcTextifier.visitInsn(opcode);
		}
	}


	Logger logger=Logger.getLogger("haikuvm.tools.pc");
}
