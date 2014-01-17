package haikuvm.pc.tools;
import haikuvm.pc.tools.haikuc.HaikuDefs;

import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import java.util.Vector;

import org.apache.bcel.Constants;
import org.apache.bcel.classfile.ClassParser;
import org.apache.bcel.classfile.Code;
import org.apache.bcel.classfile.CodeException;
import org.apache.bcel.classfile.Constant;
import org.apache.bcel.classfile.ConstantClass;
import org.apache.bcel.classfile.ConstantPool;
import org.apache.bcel.classfile.JavaClass;
import org.apache.bcel.classfile.Method;


public class ClosureGenom2 {

	private String classname;
    private static Set<String> distinctBCs = new HashSet<String>();
	private static boolean rescan;
	static Set<String> mark=new HashSet<String>();
	static Set<String> virtual=new HashSet<String>();
	static Vector<String> closure=new Vector<String>(); // all referenced classes of the source


	public static int getDistinctBCs() {
	    return distinctBCs.size();
	}

	public ClosureGenom2(String classname) {
		this.classname=classname;
		if (!closure.contains(classname)) closure.add(classname);
	}

	public static Vector<String> root(String classname) throws IOException {
		
		rescan = true;
		new ClosureGenom2(classname).collectClass("");
		
		// Don't forget this class because is needed in function ldc()
		new ClosureGenom2("java.lang.String").collectClass("");
		
		while (rescan) {
			Verbose.println("#### rescan because new virtuals where found");
			rescan = false;
			
			Vector<String> closure0=(Vector<String>)(closure.clone());
			for (String cn : closure0) {
				//Haikout.println(cn);
				new ClosureGenom2(cn).collectClass("  ");
			}
		}
		Verbose.println("#################### closure complete!");
		Verbose.println();
		Verbose.println();

		return closure;
	}

	private void collectClass(String level) throws IOException {
		collectFoos(level);
	}

	private void collectFoos(String level) throws IOException {
		if (classname.startsWith("[")) return;
		
		JavaClass jc = HaikuVM.getClassFile(classname);

		Method[] methods=jc.getMethods();
		for (int i = 0; i < methods.length; i++) {
			Method method=methods[i];
			MethInfo mi=new MethInfo(jc.getClassName()+"."+method.getName(), method.getSignature());
            if (method.isAbstract()) continue;

			if (mark.contains(mi.getInclude()) || method.getName().equals("<clinit>") || virtual.contains(method.getName()+method.getSignature())) {
				if (mark.add(mi.getInclude())) {
					Verbose.println("included# "+level+mi.getInclude());
					String methodName= HaikuVM.getMethodSignature("1 bc "+mi.getInclude());
					HaikuVM.functionTable.callOf(methodName);
				}
//				if (method.getName().equals("<clinit>")) {
//					new Clinit(classname, level.length());
//				}
	            if (method.isNative() ) {
	                continue;
	            }
				Code code= method.getCode();
				String str =code.toString(true);
				String[] list=str.split("\n");
				for (int k = 0; k < list.length; k++) {
					String jcode=list[k];
					String[] token= jcode.split("[ \t,]+", 9);
					if (token[0].endsWith(":")) { //[39:, iconst_0]
					    distinctBCs .add(token[1]);
					}
					if (token.length>=5 && token[1].startsWith("invoke")) {
						mi=new MethInfo(token[2], token[3]);

						if (token[1].equals("invokestatic") || token[1].equals("invokespecial")) {
							String classnameSaved = mi.getClassname();
							if (token[1].equals("invokestatic")) mi=MethInfo.findRealMethod(token[2], token[3]);
							
                            if (token[2].equals("java.lang.Thread.fork") || token[2].equals("java.lang.Thread.haikuReleaseLock")) {
                                HaikuDefs.setProperty("Threads", "1");
                            }
                            
							if (!(HaikuVM.supressExceptionSupport(token[2]))) {
								HaikuVM.functionTable.callOf(mi.getLongName());
							}
							if (!HaikuVM.supressExceptionSupport(token[2]) && mark.add(mi.getInclude())) {
								Verbose.println("included: "+level+mi.getInclude());
								HaikuVM.functionTable.callOf(mi.getLongName());
								rescan=true;
							}
							if (!closure.contains(classnameSaved)) {
								rescan=true;
								new ClosureGenom2(classnameSaved).collectClass(level+"  ");
							}
							if (!closure.contains(mi.getClassname())) {
								rescan=true;
								new ClosureGenom2(mi.getClassname()).collectClass(level+"  ");
							}
						} else if (token[1].equals("invokevirtual") || token[1].equals("invokeinterface")) {
							if (virtual.add(mi.getShortName())) {
								Verbose.println("virtual : "+level+mi.getShortName());
								rescan=true;
							}
							if (!closure.contains(mi.getClassname())) {
								rescan=true;
								new ClosureGenom2(mi.getClassname()).collectClass(level+"  ");
							}
						}
					} else if (token.length>=5 && (token[1].equals("getstatic") || token[1].equals("setstatic"))) {
					    // value
					    // haiku.avr.AVRConstants.TCCR0A -> haiku.avr.AVRConstants
					    String classname = token[2].substring(0, token[2].lastIndexOf('.'));
                        if (!closure.contains(classname)) {
                            rescan=true;
                            new ClosureGenom2(classname).collectClass(level+"  ");
                        }
                        // type
                        // Lhaiku/avr/AVRConstants; -> haiku.avr.AVRConstants
                        if (token[3].startsWith("L")) {
                            String type = token[3].substring(1, token[3].lastIndexOf(';')).replace('/', '.');
                            if (!closure.contains(type)) {
                                rescan=true;
                                new ClosureGenom2(type).collectClass(level+"  ");
                            }
                        }
                    } else if (token.length>=4 && (token[1].equals("checkcast") || token[1].equals("instanceof"))) {
                        // <haikuvm.bench.from.darjeeling.testvm.classes.B> -> haikuvm.bench.from.darjeeling.testvm.classes.B
                        String classname = token[2].substring(1, token[2].length()-1);
                        if (!closure.contains(classname)) {
                            rescan=true;
                            new ClosureGenom2(classname).collectClass(level+"  ");
                        }
					}
				}

				collectExceptions(jc, code, level);
			} else	if (level.length()==0 && (method.getName()+method.getSignature()).equals("main([Ljava/lang/String;)V")) {
				if (mark.add(mi.getInclude())) {
					String methodName= HaikuVM.getMethodSignature("1 bc "+mi.getInclude());
					HaikuVM.functionTable.callOf(methodName);
					Verbose.println("included; "+mi.getInclude());
					new ClosureGenom2(jc.getClassName()).collectClass(level+"  ");
					return;
				}
			}
		}
		try {
			if (jc.getSuperClass()!=null) {
				String superclass=jc.getSuperClass().getClassName();
				if (!closure.contains(superclass)) {
					new ClosureGenom2(superclass).collectClass(level+"  ");
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void collectExceptions(JavaClass jc, Code code, String level) {
		CodeException[] et = code.getExceptionTable();
		ConstantPool cp=jc.getConstantPool();

		for (int i = 0; i < et.length; i++) {
			int ct=et[i].getCatchType();
			if (ct==0) {
			} else {
				String ex=cp.constantToString(ct, Constants.CONSTANT_Class);
				if (!closure.contains(ex))
					try {
						new ClosureGenom2(ex).collectClass(level+"  ");
					} catch (IOException e) {
						e.printStackTrace();
					}
			}
		}
	}

	/**
	 * 
	 * @param key
	 * @return true if key is found<br>
	 * key in method name eg. 
	 * <li>
	 * java.lang.StringBuilder.&lt;init&gt;(Ljava/lang/String;)V
	 * java.lang.System.identityHashCode(Ljava/lang/Object;)I
	 * </li> 
	 */
	public static boolean isMarked(String key) {
		return mark.contains(key);
	}

}
