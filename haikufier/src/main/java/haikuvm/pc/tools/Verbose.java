package haikuvm.pc.tools;

import haikuvm.pc.tools.haikuc.HaikuDefs;

import java.util.Formatter;
import java.util.Vector;
@Deprecated
public class Verbose {
    private static Vector<String> warnings = new Vector<String>();
    private static Vector<String> errors = new Vector<String>();

	public static void printf(String format, Object ... args) {
		if (HaikuDefs.getProperty("Opt-v")!=null) {
			System.out.printf(format, args);	
		}
	}

	public static void println(String line) {
		printf("%s\n", line);	
	}

	public static void println() {
		printf("\n");	
	}

    public static void warning(String format, Object...args) {
        String msg=new Formatter().format(format, args).toString();
        if (!warnings.contains(msg)) {
            warnings.add(msg);
            System.err.println(msg);
        }
    }
    
    public static Error error(String format, Object...args) {
        String msg=new Formatter().format(format, args).toString();
        System.err.println(msg);
        if (!errors.contains(msg)) {
            errors.add(msg);
        }
        return new Error(msg);
    }
    
    public static void summary() {
        if (warnings.size()>0) {
            System.err.println("Warnings:");
            for (String msg : warnings) {
                System.err.println(msg);
            }
        }
        if (errors.size()>0) {
            System.err.println("Errors:");
            for (String msg : errors) {
                System.err.println(msg);
            }
        }
    }

    public static void swarning(String format, Object...args) {
        String msg=new Formatter().format(format, args).toString();
        if (!warnings.contains(msg)) {
            warnings.add(msg);
        }
    }
    
    public static boolean isError() {
        return errors.size()>0;
    }
}
