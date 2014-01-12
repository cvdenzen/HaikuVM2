package haiku.vm;

public class MicroKernel {
    private static Throwable outOfMemoryError = new OutOfMemoryError("OutOfMemoryError");

    /**
     * Bytecode placeholder for all static initializers.
     * 
     * Will be filled by haikufier with the (ordered) list of
     * all static initializers from your JAVA program.
     */
    public static native void clinitHaikuMagic();
    
    /**
     * @throws Throwable
     */
    public static void throwException() throws Throwable {
        int ex=haiku.vm.HaikuMagic.exceptionCode;
        haiku.vm.HaikuMagic.exceptionCode=0; // consume. Which allows C-Code to reenter.
        switch (ex) {
        case   0:   return; // only for initialization
        case   2:   throw new NullPointerException("NullPointerException"); 
        case   4:   throw new ArrayStoreException(); 
        case   8:   throw new IndexOutOfBoundsException("IndexOutOfBoundsException"); 
        case  16:   throw new NoSuchMethodError("NoSuchMethodError: msgCode="+haiku.vm.HaikuMagic.exceptionArg); 
        case  32:   throw new StackOverflowError("Stack"+(haiku.vm.HaikuMagic.exceptionArg<0?"Und":"Ov")+"erflow: " + haiku.vm.HaikuMagic.exceptionArg); 
//      case  64:   throw new OutOfMemoryError("Heap overflow: size needed="+haiku.vm.HaikuMagic.exceptionArg); 
        case  64:   throw outOfMemoryError; 
        case 128:   throw new ClassCastException("ClassCastException classCode="+haiku.vm.HaikuMagic.exceptionArg); 
        case 256:   throw new ArrayIndexOutOfBoundsException(haiku.vm.HaikuMagic.exceptionArg);
        case 512:   throw new VirtualMachineError("VirtualMachineError OP code is "+(haiku.vm.HaikuMagic.exceptionArg==0?"unimplemented":"unused")); 
        case 1024:  throw new ArithmeticException("ArithmeticException: Code="+haiku.vm.HaikuMagic.exceptionArg); 
        }
        throw new VirtualMachineError("Unregistered Haiku Exception: exceptionCode="+ex+" arg="+haiku.vm.HaikuMagic.exceptionArg); 
    }
}
