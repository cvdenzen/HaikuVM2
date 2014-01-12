//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\haiku\avr\lib\arduino\HaikuMicroKernelProcessing.c
//
/*
public class haiku.avr.lib.arduino.HaikuMicroKernelProcessing extends haiku.vm.MicroKernel
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/haiku/avr/lib/arduino/HaikuMicroKernelProcessing.class
compiled from		HaikuMicroKernelProcessing.java
compiler version	51.0
access flags		33
constant pool		45 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(HaikuMicroKernelProcessing.java)

3 methods:
	public void <init>()
	private static native void init()
	public static void main(String[] arg0)

*/


#include "haikuConfig.h"
#include "haikuJava.h"



/**
private static native void init()
*/
#ifndef native_haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V
const NativCode haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V PROGMEM ={0xff, &native_haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V};
#endif

/**
public static void main(String[] arg0)
Code(max_stack = 1, max_locals = 2, code_length = 26)
*/
#undef  JMETHOD
#define JMETHOD main_YLjava_lang_String
const           main_YLjava_lang_String_t JMETHOD PROGMEM ={
1+2 +2,    1,    1,    // max_stack, purLocals, purParams

OP_INVOKESHORT_haiku_vm_MicroKernel_clinitHaikuMagic_V,                // 0:    invokestatic	haiku.avr.lib.arduino.HaikuMicroKernelProcessing.clinitHaikuMagic ()V (2)
OP_INVOKESHORT_haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V, 
                                                                       // 6:    invokestatic	haiku.avr.lib.arduino.HaikuMicroKernelProcessing.init ()V (4)
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V, 
                                                                       // 9:    invokestatic	haiku.vm.HaikuMagic.setup ()V (5)
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V, 
                                                                       // 12:   invokestatic	haiku.vm.HaikuMagic.loop ()V (6)
OP_GOTO,             TARGET(12),                                       // 15:   goto		#12
OP_ASTORE_1,                                                           // 18:   astore_1
OP_INVOKESHORT_java_lang_Thread_currentThread_Ljava_lang_Thread,       // 19:   invokestatic	java.lang.Thread.currentThread ()Ljava/lang/Thread; (8)
OP_INVOKEVIRTUAL,    B(0), LB(MSG_stop___V),                           // 22:   invokevirtual	java.lang.Thread.stop ()V (9)
OP_RETURN,                                                             // 25:   return
};

const class_t haiku_avr_lib_arduino_HaikuMicroKernelProcessing__class PROGMEM = {
	& haiku_vm_MicroKernel__class,
	SIZEOF_haiku_avr_lib_arduino_HaikuMicroKernelProcessing,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\Throwable.c
//
/*
public class java.lang.Throwable extends java.lang.Object
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/java/lang/Throwable.class
compiled from		Throwable.java
compiler version	51.0
access flags		33
constant pool		53 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(Throwable.java)

3 fields:
	private int[] _stackTrace
	private String _message
	Throwable _cause

10 methods:
	public void <init>()
	public void <init>(String arg1)
	public void <init>(String arg1, Throwable arg2)
	public void <init>(Throwable arg1)
	public Throwable initCause(Throwable arg1)
	public Throwable getCause()
	public String getLocalizedMessage()
	public String getMessage()
	public String toString()
	public Throwable fillInStackTrace()

*/



/**
public void <init>(String arg1)
Code(max_stack = 2, max_locals = 2, code_length = 15)
*/
#undef  JMETHOD
#define JMETHOD java_lang_Throwable__init__Ljava_lang_String_V
const           java_lang_Throwable__init__Ljava_lang_String_V_t JMETHOD PROGMEM ={
2+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_INVOKESHORT_java_lang_Object__init__V,                              // 1:    invokespecial	java.lang.Object.<init> ()V (1)
OP_ALOAD_0,                                                            // 4:    aload_0
OP_INVOKEVIRTUAL,    B(0), LB(MSG_fillInStackTrace___Ljava_lang_Throwable), 
                                                                       // 5:    invokevirtual	java.lang.Throwable.fillInStackTrace ()Ljava/lang/Throwable; (2)
OP_POP,                                                                // 8:    pop
OP_ALOAD_0,                                                            // 9:    aload_0
OP_ALOAD_1,                                                            // 10:   aload_1
OP_PUTFIELD_L,       FIDX(java_lang_Throwable, _message),              // 11:   putfield		java.lang.Throwable._message Ljava/lang/String; (3)
OP_RETURN,                                                             // 14:   return
};

/**
public Throwable fillInStackTrace()
Code(max_stack = 1, max_locals = 1, code_length = 2)
*/
#undef  JMETHOD
#define JMETHOD java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable
const           java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable_t JMETHOD PROGMEM ={
1+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ARETURN,                                                            // 1:    areturn
};

const class_t java_lang_Throwable__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_java_lang_Throwable,
	1,
    {
		{MSG_fillInStackTrace___Ljava_lang_Throwable, (ByteCode *)(&java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable)},
	}
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\Object.c
//
/*
public class java.lang.Object extends java.lang.Object
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/java/lang/Object.class
compiled from		Object.java
compiler version	51.0
access flags		33
constant pool		78 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(Object.java)

12 methods:
	public void <init>()
	public String toString()
	public boolean equals(Object arg1)
	public final void wait(long arg1)
		throws java.lang.InterruptedException
	public final void wait(long arg1, int arg3)
		throws java.lang.InterruptedException
	public final void wait()
		throws java.lang.InterruptedException
	protected native Object clone()
		throws java.lang.CloneNotSupportedException
	protected void finalize()
	public int hashCode()
	public Class getClass() [Signature(()Ljava/lang/Class<*>;)]
	public void notifyAll()
	public void notify()

*/



/**
public void <init>()
Code(max_stack = 0, max_locals = 1, code_length = 1)
*/
#undef  JMETHOD
#define JMETHOD java_lang_Object__init__V
const           java_lang_Object__init__V_t JMETHOD PROGMEM ={
0+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_RETURN,                                                             // 0:    return
};

const class_t java_lang_Object__class PROGMEM = {
	NULL,
	SIZEOF_java_lang_Object,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\Thread.c
//
/*
public class java.lang.Thread extends java.lang.Object
implements		java.lang.Runnable
filename		Thread.java
compiled from		Thread.java
compiler version	51.0
access flags		33
constant pool		135 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(Thread.java)

19 fields:
	private static final int IDLE = 0
	private static final int YIELD = 2
	private static final int WAITING = 6
	private static final int STOPPED = 8
	public static final int MAX_PRIORITY = 0
	public static final int NORM_PRIORITY = 0
	public static final int MIN_PRIORITY = 0
	private static volatile Thread currentThread
	private volatile Runnable target
	private volatile Thread next
	private volatile int state
	private volatile Object programcounter
	private volatile Object stackpointer
	private volatile Object stackframe
	private volatile Object stack
	private volatile long waitUntil
	private volatile Object locks
	private volatile boolean interrupt
	private volatile Object waitingOn

30 methods:
	public static void foolingProGuard()
	public void <init>()
	public void <init>(Runnable arg1)
	public static void sleep(long arg0)
		throws java.lang.InterruptedException
	public static void nap(long arg0)
	public void start()
	private native int fork()
	public void run()
	public void run$()
	public final void stop()
	public static Thread currentThread()
	public static void yield()
	private native int setStateAndSwitch(int arg1)
	public void setDaemon(boolean arg1)
	public void setPriority(int arg1)
	public void <init>(String arg1)
	public void <init>(Runnable arg1, String arg2)
	public final int getPriority()
	public String getName()
	public void setName(String arg1)
	public void interrupt()
	public static boolean interrupted()
	public final boolean isInterrupted()
	public final boolean isDaemon()
	public final void join()
		throws java.lang.InterruptedException
	public final void join(long arg1)
		throws java.lang.InterruptedException
	static void notifyAll(Object arg0)
	static void notify(Object arg0)
	private static native void haikuReleaseLock(Object arg0)
	static void haikuWait(Object arg0, long arg1)
		throws java.lang.InterruptedException

*/



/**
public final void stop()
Code(max_stack = 2, max_locals = 2, code_length = 46)
*/
#undef  JMETHOD
#define JMETHOD java_lang_Thread_stop_V
const           java_lang_Thread_stop_V_t JMETHOD PROGMEM ={
2+2 +2,    1,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_GETFIELD_I,       FIDX(java_lang_Thread, state),                    // 1:    getfield		java.lang.Thread.state I (19)
OP_BIPUSH,           B(8),                                             // 4:    bipush		8
OP_IF_ICMPEQ,        TARGET(45),                                       // 6:    if_icmpeq		#45
OP_ALOAD_0,                                                            // 9:    aload_0
OP_ASTORE_1,                                                           // 10:   astore_1
OP_ALOAD_1,                                                            // 11:   aload_1
OP_GETFIELD_L,       FIDX(java_lang_Thread, next),                     // 12:   getfield		java.lang.Thread.next Ljava/lang/Thread; (12)
OP_ALOAD_0,                                                            // 15:   aload_0
OP_IF_ACMPEQ,        TARGET(27),                                       // 16:   if_acmpeq		#27
OP_ALOAD_1,                                                            // 19:   aload_1
OP_GETFIELD_L,       FIDX(java_lang_Thread, next),                     // 20:   getfield		java.lang.Thread.next Ljava/lang/Thread; (12)
OP_ASTORE_1,                                                           // 23:   astore_1
OP_GOTO,             TARGET(11),                                       // 24:   goto		#11
OP_ALOAD_1,                                                            // 27:   aload_1
OP_ALOAD_1,                                                            // 28:   aload_1
OP_GETFIELD_L,       FIDX(java_lang_Thread, next),                     // 29:   getfield		java.lang.Thread.next Ljava/lang/Thread; (12)
OP_GETFIELD_L,       FIDX(java_lang_Thread, next),                     // 32:   getfield		java.lang.Thread.next Ljava/lang/Thread; (12)
OP_PUTFIELD_L,       FIDX(java_lang_Thread, next),                     // 35:   putfield		java.lang.Thread.next Ljava/lang/Thread; (12)
OP_ALOAD_0,                                                            // 38:   aload_0
OP_BIPUSH,           B(8),                                             // 39:   bipush		8
OP_INVOKESHORT_java_lang_Thread_setStateAndSwitch_II,                  // 41:   invokespecial	java.lang.Thread.setStateAndSwitch (I)I (8)
OP_POP,                                                                // 44:   pop
OP_RETURN,                                                             // 45:   return
};

/**
public static Thread currentThread()
Code(max_stack = 1, max_locals = 0, code_length = 4)
*/
#undef  JMETHOD
#define JMETHOD java_lang_Thread_currentThread_Ljava_lang_Thread
const           java_lang_Thread_currentThread_Ljava_lang_Thread_t JMETHOD PROGMEM ={
1+0 +2,    0,    0,    // max_stack, purLocals, purParams

OP_GETSTATIC_L,      SADR(java_lang_Thread_currentThread),             // 0:    getstatic		java.lang.Thread.currentThread Ljava/lang/Thread; (3)
OP_ARETURN,                                                            // 3:    areturn
};

/**
private native int setStateAndSwitch(int arg1)
*/
#ifndef native_java_lang_Thread_setStateAndSwitch_II
const NativCode java_lang_Thread_setStateAndSwitch_II PROGMEM ={0xff, &native_java_lang_Thread_setStateAndSwitch_II};
#endif

const class_t java_lang_Thread__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_java_lang_Thread,
	1,
    {
		{MSG_stop___V, (ByteCode *)(&java_lang_Thread_stop_V)},
	}
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\Yarrays\YC.c
//

const class_t YC__class PROGMEM = {
    & java_lang_Object__class,
    0,
    0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\String.c
//
/*
public class java.lang.String extends java.lang.Object
implements		java.lang.CharSequence, java.lang.Comparable
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/java/lang/String.class
compiled from		String.java
compiler version	51.0
access flags		33
constant pool		138 entries
ACC_SUPER flag		true

Attribute(s):
	Signature(Ljava/lang/Object;Ljava/lang/CharSequence;Ljava/lang/Comparable<Ljava/lang/String;>;)
	SourceFile(String.java)

1 fields:
	final char[] characters

31 methods:
	public void <init>()
	private void <init>(int arg1)
	public void <init>(char[] arg1)
	public void <init>(char arg1)
	public void <init>(String arg1)
	public void <init>(char[] arg1, int arg2, int arg3)
	public int length()
	public char charAt(int arg1)
	public static String valueOf(Object arg0)
	public static String valueOf(boolean arg0)
	public static String valueOf(char arg0)
	public static String valueOf(float arg0)
	public static String valueOf(double arg0)
	public String toString()
	public static String valueOf(long arg0)
	public static String valueOf(int arg0)
	static String valueOf(int arg0, int arg1)
	public boolean equals(Object arg1)
	public int hashCode()
	public int indexOf(int arg1)
	public int indexOf(int arg1, int arg2)
	public int indexOf(String arg1)
	public int indexOf(String arg1, int arg2)
	public String substring(int arg1, int arg2)
	public String substring(int arg1)
	static int lastIndexOf(char[] arg0, int arg1, int arg2, char[] arg3, int arg4, int arg5, int arg6)
	static int indexOf(char[] arg0, int arg1, int arg2, char[] arg3, int arg4, int arg5, int arg6)
	public CharSequence subSequence(int arg1, int arg2)
	public int compareTo(String arg1)
	public String trim()
	public volatile synthetic int compareTo(Object arg1)

*/



/**
public int length()
Code(max_stack = 1, max_locals = 1, code_length = 6)
*/
#undef  JMETHOD
#define JMETHOD java_lang_String_length_I
const           java_lang_String_length_I_t JMETHOD PROGMEM ={
1+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_GETFIELD_L,       FIDX(java_lang_String, characters),               // 1:    getfield		java.lang.String.characters [C (2)
OP_ARRAYLENGTH,                                                        // 4:    arraylength
OP_IRETURN,                                                            // 5:    ireturn
};

/**
public char charAt(int arg1)
Code(max_stack = 2, max_locals = 2, code_length = 7)
*/
#undef  JMETHOD
#define JMETHOD java_lang_String_charAt_IC
const           java_lang_String_charAt_IC_t JMETHOD PROGMEM ={
2+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_GETFIELD_L,       FIDX(java_lang_String, characters),               // 1:    getfield		java.lang.String.characters [C (2)
OP_ILOAD_1,                                                            // 4:    iload_1
OP_CALOAD,                                                             // 5:    caload
OP_IRETURN,                                                            // 6:    ireturn
};

const class_t java_lang_String__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_java_lang_String,
	2,
    {
		{MSG_charAt__I_C, (ByteCode *)(&java_lang_String_charAt_IC)},
		{MSG_length___I, (ByteCode *)(&java_lang_String_length_I)},
	}
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\haiku\vm\MicroKernel.c
//
/*
public class haiku.vm.MicroKernel extends java.lang.Object
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/haiku/vm/MicroKernel.class
compiled from		MicroKernel.java
compiler version	51.0
access flags		33
constant pool		115 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(MicroKernel.java)

1 fields:
	private static Throwable outOfMemoryError

4 methods:
	public void <init>()
	public static native void clinitHaikuMagic()
	public static void throwException()
		throws java.lang.Throwable
	static void <clinit>()

*/



/**
public static native void clinitHaikuMagic()
*/

// clinit           processing/hardware/arduino/cores/arduino/Print
// clinit           haiku/vm/MicroKernel
// clinit           arduino/libraries/liquidcrystal/LiquidCrystalHelloWorld
// clinit           processing/hardware/arduino/cores/arduino/Arduino
const           haiku_vm_MicroKernel_clinitHaikuMagic_V_t haiku_vm_MicroKernel_clinitHaikuMagic_V PROGMEM ={
2, 0, 0,    // max_stack, purLocals, purParams

OP_INVOKESTATIC,     ADR(processing_hardware_arduino_cores_arduino_Print__clinit__V),   // processing.hardware.arduino.cores.arduino.Print.<clinit>
OP_INVOKESTATIC,     ADR(haiku_vm_MicroKernel__clinit__V),   // haiku.vm.MicroKernel.<clinit>
OP_INVOKESTATIC,     ADR(arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V),   // arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.<clinit>
OP_INVOKESTATIC,     ADR(processing_hardware_arduino_cores_arduino_Arduino__clinit__V),   // processing.hardware.arduino.cores.arduino.Arduino.<clinit>
OP_RETURN,                                                             //       return
};

/**
static void <clinit>()
Code(max_stack = 3, max_locals = 0, code_length = 13)
*/
#undef  JMETHOD
#define JMETHOD haiku_vm_MicroKernel__clinit__V
const           haiku_vm_MicroKernel__clinit__V_t JMETHOD PROGMEM ={
3+0 +2,    0,    0,    // max_stack, purLocals, purParams

OP_NEW,              ADR(java_lang_OutOfMemoryError__class),           // 0:    new		<java.lang.OutOfMemoryError> (42)
OP_DUP,                                                                // 3:    dup
OP_LDC_S,            CADR(Const0000),                                  // 4:    ldc		"OutOfMemoryError" (43)
OP_INVOKESHORT_java_lang_OutOfMemoryError__init__Ljava_lang_String_V,  // 6:    invokespecial	java.lang.OutOfMemoryError.<init> (Ljava/lang/String;)V (44)
OP_PUTSTATIC_L,      SADR(haiku_vm_MicroKernel_outOfMemoryError),      // 9:    putstatic		haiku.vm.MicroKernel.outOfMemoryError Ljava/lang/Throwable; (26)
OP_RETURN,                                                             // 12:   return
};

const class_t haiku_vm_MicroKernel__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_haiku_vm_MicroKernel,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\OutOfMemoryError.c
//
/*
public class java.lang.OutOfMemoryError extends java.lang.Error
filename		java/lang/OutOfMemoryError.class
compiled from		OutOfMemoryError.java
compiler version	49.0
access flags		33
constant pool		21 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(OutOfMemoryError.java)

2 methods:
	public void <init>()
	public void <init>(String message)

*/



/**
public void <init>(String message)
Code(max_stack = 2, max_locals = 2, code_length = 6)
*/
#undef  JMETHOD
#define JMETHOD java_lang_OutOfMemoryError__init__Ljava_lang_String_V
const           java_lang_OutOfMemoryError__init__Ljava_lang_String_V_t JMETHOD PROGMEM ={
2+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ALOAD_1,                                                            // 1:    aload_1
OP_INVOKESHORT_java_lang_Error__init__Ljava_lang_String_V,             // 2:    invokespecial	java.lang.Error.<init> (Ljava/lang/String;)V (2)
OP_RETURN,                                                             // 5:    return
};

const class_t java_lang_OutOfMemoryError__class PROGMEM = {
	& java_lang_Error__class,
	SIZEOF_java_lang_OutOfMemoryError,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\Error.c
//
/*
public class java.lang.Error extends java.lang.Throwable
filename		java/lang/Error.class
compiled from		Error.java
compiler version	49.0
access flags		33
constant pool		21 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(Error.java)

2 methods:
	public void <init>()
	public void <init>(String message)

*/



/**
public void <init>(String message)
Code(max_stack = 2, max_locals = 2, code_length = 6)
*/
#undef  JMETHOD
#define JMETHOD java_lang_Error__init__Ljava_lang_String_V
const           java_lang_Error__init__Ljava_lang_String_V_t JMETHOD PROGMEM ={
2+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ALOAD_1,                                                            // 1:    aload_1
OP_INVOKESHORT_java_lang_Throwable__init__Ljava_lang_String_V,         // 2:    invokespecial	java.lang.Throwable.<init> (Ljava/lang/String;)V (2)
OP_RETURN,                                                             // 5:    return
};

const class_t java_lang_Error__class PROGMEM = {
	& java_lang_Throwable__class,
	SIZEOF_java_lang_Error,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\arduino\libraries\liquidcrystal\LiquidCrystalHelloWorld.c
//
/*
public class arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld extends java.lang.Object
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/arduino/libraries/liquidcrystal/LiquidCrystalHelloWorld.class
compiled from		LiquidCrystalHelloWorld.java
compiler version	51.0
access flags		33
constant pool		55 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(LiquidCrystalHelloWorld.java)

2 fields:
	private static arduino.libraries.liquidcrystal.LiquidCrystal lcd
	static int teller

5 methods:
	public void <init>()
	public static void setup()
	public static void loop()
	public static void main(String[] arg0)
	static void <clinit>()

*/



/**
public static void setup()
Code(max_stack = 3, max_locals = 0, code_length = 18)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V
const           arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V_t JMETHOD PROGMEM ={
3+0 +2,    0,    0,    // max_stack, purLocals, purParams

OP_GETSTATIC_L,      SADR(arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_lcd), 
                                                                       // 0:    getstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
OP_BIPUSH,           B(16),                                            // 3:    bipush		16
OP_ICONST_2,                                                           // 5:    iconst_2
OP_INVOKEVIRTUAL,    B(2), LB(MSG_begin__BB_V),                        // 6:    invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.begin (BB)V (3)
OP_GETSTATIC_L,      SADR(arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_lcd), 
                                                                       // 9:    getstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
OP_LDC_S,            CADR(Const0001),                                  // 12:   ldc		"hello, world A!" (4)
OP_INVOKEVIRTUAL,    B(1), LB(MSG_print__Ljava_lang_String__V),        // 14:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.print (Ljava/lang/String;)V (5)
OP_RETURN,                                                             // 17:   return
};

/**
public static void loop()
Code(max_stack = 5, max_locals = 0, code_length = 22)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V
const           arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V_t JMETHOD PROGMEM ={
5+0 +2,    0,    0,    // max_stack, purLocals, purParams

OP_GETSTATIC_L,      SADR(arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_lcd), 
                                                                       // 0:    getstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
OP_ICONST_0,                                                           // 3:    iconst_0
OP_ICONST_1,                                                           // 4:    iconst_1
OP_INVOKEVIRTUAL,    B(2), LB(MSG_setCursor__BB_V),                    // 5:    invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.setCursor (BB)V (6)
OP_GETSTATIC_L,      SADR(arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_lcd), 
                                                                       // 8:    getstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_millis_J, 
                                                                       // 11:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.millis ()J (7)
OP_LDC2_W_L,         CADR(Const0002),                                  // 14:   ldc2_w		500 (8)
OP_LDIV,                                                               // 17:   ldiv
OP_INVOKEVIRTUAL,    B(2), LB(MSG_print__J_V),                         // 18:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.print (J)V (10)
OP_RETURN,                                                             // 21:   return
};

/**
static void <clinit>()
Code(max_stack = 8, max_locals = 0, code_length = 25)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V
const           arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V_t JMETHOD PROGMEM ={
8+0 +2,    0,    0,    // max_stack, purLocals, purParams

OP_NEW,              ADR(arduino_libraries_liquidcrystal_LiquidCrystal__class), 
                                                                       // 0:    new		<arduino.libraries.liquidcrystal.LiquidCrystal> (11)
OP_DUP,                                                                // 3:    dup
OP_BIPUSH,           B(8),                                             // 4:    bipush		8
OP_BIPUSH,           B(9),                                             // 6:    bipush		9
OP_ICONST_4,                                                           // 8:    iconst_4
OP_ICONST_5,                                                           // 9:    iconst_5
OP_BIPUSH,           B(6),                                             // 10:   bipush		6
OP_BIPUSH,           B(7),                                             // 12:   bipush		7
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV, 
                                                                       // 14:   invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.<init> (BBBBBB)V (12)
OP_PUTSTATIC_L,      SADR(arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_lcd), 
                                                                       // 17:   putstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
OP_ICONST_0,                                                           // 20:   iconst_0
OP_PUTSTATIC_I,      SADR(arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_teller), 
                                                                       // 21:   putstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.teller I (13)
OP_RETURN,                                                             // 24:   return
};

const class_t arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\Yarrays\YB.c
//

const class_t YB__class PROGMEM = {
    & java_lang_Object__class,
    0,
    0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\arduino\libraries\liquidcrystal\LiquidCrystal.c
//
/*
public class arduino.libraries.liquidcrystal.LiquidCrystal extends processing.hardware.arduino.cores.arduino.Print
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/arduino/libraries/liquidcrystal/LiquidCrystal.class
compiled from		LiquidCrystal.java
compiler version	51.0
access flags		33
constant pool		152 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(LiquidCrystal.java)

39 fields:
	private static final byte LCD_CLEARDISPLAY = 1
	private static final byte LCD_RETURNHOME = 2
	private static final byte LCD_ENTRYMODESET = 4
	private static final byte LCD_DISPLAYCONTROL = 8
	private static final byte LCD_CURSORSHIFT = 16
	private static final byte LCD_FUNCTIONSET = 32
	private static final byte LCD_SETCGRAMADDR = 64
	private static final byte LCD_SETDDRAMADDR = -128
	private static final byte LCD_ENTRYRIGHT = 0
	private static final byte LCD_ENTRYLEFT = 2
	private static final byte LCD_ENTRYSHIFTINCREMENT = 1
	private static final byte LCD_ENTRYSHIFTDECREMENT = 0
	private static final byte LCD_DISPLAYON = 4
	private static final byte LCD_DISPLAYOFF = 0
	private static final byte LCD_CURSORON = 2
	private static final byte LCD_CURSOROFF = 0
	private static final byte LCD_BLINKON = 1
	private static final byte LCD_BLINKOFF = 0
	private static final byte LCD_DISPLAYMOVE = 8
	private static final byte LCD_CURSORMOVE = 0
	private static final byte LCD_MOVERIGHT = 4
	private static final byte LCD_MOVELEFT = 0
	private static final byte LCD_8BITMODE = 16
	private static final byte LCD_4BITMODE = 0
	private static final byte LCD_2LINE = 8
	private static final byte LCD_1LINE = 0
	private static final byte LCD_5x10DOTS = 4
	private static final byte LCD_5x8DOTS = 0
	private byte _rs_pin
	private byte _rw_pin
	private byte _enable_pin
	private byte[] _data_pins
	private byte _displayfunction
	private byte _displaycontrol
	private byte _displaymode
	private byte _initialized
	private byte _numlines
	private byte _currline
	private static final byte OUTPUT = 1

29 methods:
	public void <init>(byte arg1, byte arg2, byte arg3, byte arg4, byte arg5, byte arg6, byte arg7, byte arg8, byte arg9, byte arg10, byte arg11)
	public void <init>(byte arg1, byte arg2, byte arg3, byte arg4, byte arg5, byte arg6, byte arg7, byte arg8, byte arg9, byte arg10)
	public void <init>(byte arg1, byte arg2, byte arg3, byte arg4, byte arg5, byte arg6, byte arg7)
	public void <init>(byte arg1, byte arg2, byte arg3, byte arg4, byte arg5, byte arg6)
	private void init(byte arg1, byte arg2, byte arg3, byte arg4, byte arg5, byte arg6, byte arg7, byte arg8, byte arg9, byte arg10, byte arg11, byte arg12)
	public void begin(byte arg1, byte arg2, byte arg3)
	public void begin(byte arg1, byte arg2)
	public void clear()
	public void home()
	public void setCursor(byte arg1, byte arg2)
	public void noDisplay()
	public void display()
	public void noCursor()
	public void cursor()
	public void noBlink()
	public void blink()
	public void scrollDisplayLeft()
	public void scrollDisplayRight()
	public void leftToRight()
	public void rightToLeft()
	public void autoscroll()
	public void noAutoscroll()
	public void createChar(byte arg1, byte[] arg2)
	private void command(byte arg1)
	public byte write(byte arg1)
	private void send(byte arg1, byte arg2)
	public void pulseEnable()
	public void write4bits(byte arg1)
	public void write8bits(byte arg1)

*/



/**
public void <init>(byte arg1, byte arg2, byte arg3, byte arg4, byte arg5, byte arg6)
Code(max_stack = 13, max_locals = 7, code_length = 32)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV
const           arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV_t JMETHOD PROGMEM ={
13+7 +2,    0,    7,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Print__init__V, 
                                                                       // 1:    invokespecial	processing.hardware.arduino.cores.arduino.Print.<init> ()V (1)
OP_ALOAD_0,                                                            // 4:    aload_0
OP_BIPUSH,           B(8),                                             // 5:    bipush		8
OP_NEWARRAY,         B(1),                                             // 7:    newarray		<byte>
OP_PUTFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 9:    putfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ALOAD_0,                                                            // 12:   aload_0
OP_ICONST_1,                                                           // 13:   iconst_1
OP_ILOAD_1,                                                            // 14:   iload_1
OP_ICONST_M1,                                                          // 15:   iconst_m1
OP_ILOAD_2,                                                            // 16:   iload_2
OP_ILOAD_3,                                                            // 17:   iload_3
OP_ILOAD,            B(4),                                             // 18:   iload		%4
OP_ILOAD,            B(5),                                             // 20:   iload		%5
OP_ILOAD,            B(6),                                             // 22:   iload		%6
OP_ICONST_0,                                                           // 24:   iconst_0
OP_ICONST_0,                                                           // 25:   iconst_0
OP_ICONST_0,                                                           // 26:   iconst_0
OP_ICONST_0,                                                           // 27:   iconst_0
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV, 
                                                                       // 28:   invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.init (BBBBBBBBBBBB)V (3)
OP_RETURN,                                                             // 31:   return
};

/**
private void init(byte arg1, byte arg2, byte arg3, byte arg4, byte arg5, byte arg6, byte arg7, byte arg8, byte arg9, byte arg10, byte arg11, byte arg12)
Code(max_stack = 4, max_locals = 13, code_length = 141)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV
const           arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV_t JMETHOD PROGMEM ={
4+13 +2,    0,   13,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ILOAD_2,                                                            // 1:    iload_2
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rs_pin), 
                                                                       // 2:    putfield		arduino.libraries.liquidcrystal.LiquidCrystal._rs_pin B (4)
OP_ALOAD_0,                                                            // 5:    aload_0
OP_ILOAD_3,                                                            // 6:    iload_3
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rw_pin), 
                                                                       // 7:    putfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
OP_ALOAD_0,                                                            // 10:   aload_0
OP_ILOAD,            B(4),                                             // 11:   iload		%4
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _enable_pin), 
                                                                       // 13:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
OP_ALOAD_0,                                                            // 16:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 17:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ICONST_0,                                                           // 20:   iconst_0
OP_ILOAD,            B(5),                                             // 21:   iload		%5
OP_BASTORE,                                                            // 23:   bastore
OP_ALOAD_0,                                                            // 24:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 25:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ICONST_1,                                                           // 28:   iconst_1
OP_ILOAD,            B(6),                                             // 29:   iload		%6
OP_BASTORE,                                                            // 31:   bastore
OP_ALOAD_0,                                                            // 32:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 33:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ICONST_2,                                                           // 36:   iconst_2
OP_ILOAD,            B(7),                                             // 37:   iload		%7
OP_BASTORE,                                                            // 39:   bastore
OP_ALOAD_0,                                                            // 40:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 41:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ICONST_3,                                                           // 44:   iconst_3
OP_ILOAD,            B(8),                                             // 45:   iload		%8
OP_BASTORE,                                                            // 47:   bastore
OP_ALOAD_0,                                                            // 48:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 49:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ICONST_4,                                                           // 52:   iconst_4
OP_ILOAD,            B(9),                                             // 53:   iload		%9
OP_BASTORE,                                                            // 55:   bastore
OP_ALOAD_0,                                                            // 56:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 57:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ICONST_5,                                                           // 60:   iconst_5
OP_ILOAD,            B(10),                                            // 61:   iload		%10
OP_BASTORE,                                                            // 63:   bastore
OP_ALOAD_0,                                                            // 64:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 65:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_BIPUSH,           B(6),                                             // 68:   bipush		6
OP_ILOAD,            B(11),                                            // 70:   iload		%11
OP_BASTORE,                                                            // 72:   bastore
OP_ALOAD_0,                                                            // 73:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 74:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_BIPUSH,           B(7),                                             // 77:   bipush		7
OP_ILOAD,            B(12),                                            // 79:   iload		%12
OP_BASTORE,                                                            // 81:   bastore
OP_ALOAD_0,                                                            // 82:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rs_pin), 
                                                                       // 83:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rs_pin B (4)
OP_ICONST_1,                                                           // 86:   iconst_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV, 
                                                                       // 87:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
OP_ALOAD_0,                                                            // 90:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rw_pin), 
                                                                       // 91:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
OP_ICONST_M1,                                                          // 94:   iconst_m1
OP_IF_ICMPEQ,        TARGET(106),                                      // 95:   if_icmpeq		#106
OP_ALOAD_0,                                                            // 98:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rw_pin), 
                                                                       // 99:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
OP_ICONST_1,                                                           // 102:  iconst_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV, 
                                                                       // 103:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
OP_ALOAD_0,                                                            // 106:  aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _enable_pin), 
                                                                       // 107:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
OP_ICONST_1,                                                           // 110:  iconst_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV, 
                                                                       // 111:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
OP_ILOAD_1,                                                            // 114:  iload_1
OP_IFEQ,             TARGET(126),                                      // 115:  ifeq		#126
OP_ALOAD_0,                                                            // 118:  aload_0
OP_ICONST_0,                                                           // 119:  iconst_0
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 120:  putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_GOTO,             TARGET(132),                                      // 123:  goto		#132
OP_ALOAD_0,                                                            // 126:  aload_0
OP_BIPUSH,           B(16),                                            // 127:  bipush		16
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 129:  putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_ALOAD_0,                                                            // 132:  aload_0
OP_BIPUSH,           B(16),                                            // 133:  bipush		16
OP_ICONST_1,                                                           // 135:  iconst_1
OP_ICONST_0,                                                           // 136:  iconst_0
OP_INVOKEVIRTUAL,    B(3), LB(MSG_begin__BBB_V),                       // 137:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.begin (BBB)V (9)
OP_RETURN,                                                             // 140:  return
};

/**
public void begin(byte arg1, byte arg2, byte arg3)
Code(max_stack = 3, max_locals = 4, code_length = 225)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV
const           arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV_t JMETHOD PROGMEM ={
3+4 +2,    0,    4,    // max_stack, purLocals, purParams

OP_ILOAD_2,                                                            // 0:    iload_2
OP_ICONST_1,                                                           // 1:    iconst_1
OP_IF_ICMPLE,        TARGET(17),                                       // 2:    if_icmple		#17
OP_ALOAD_0,                                                            // 5:    aload_0
OP_DUP,                                                                // 6:    dup
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 7:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_BIPUSH,           B(8),                                             // 10:   bipush		8
OP_IOR,                                                                // 12:   ior
OP_I2B,                                                                // 13:   i2b
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 14:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_ALOAD_0,                                                            // 17:   aload_0
OP_ILOAD_2,                                                            // 18:   iload_2
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _numlines), 
                                                                       // 19:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._numlines B (10)
OP_ALOAD_0,                                                            // 22:   aload_0
OP_ICONST_0,                                                           // 23:   iconst_0
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _currline), 
                                                                       // 24:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._currline B (11)
OP_ILOAD_3,                                                            // 27:   iload_3
OP_IFEQ,             TARGET(47),                                       // 28:   ifeq		#47
OP_ILOAD_2,                                                            // 31:   iload_2
OP_ICONST_1,                                                           // 32:   iconst_1
OP_IF_ICMPNE,        TARGET(47),                                       // 33:   if_icmpne		#47
OP_ALOAD_0,                                                            // 36:   aload_0
OP_DUP,                                                                // 37:   dup
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 38:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_ICONST_4,                                                           // 41:   iconst_4
OP_IOR,                                                                // 42:   ior
OP_I2B,                                                                // 43:   i2b
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 44:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_LDC_I,            CADR(Const0003),                                  // 47:   ldc		50000 (12)
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 49:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_ALOAD_0,                                                            // 52:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rs_pin), 
                                                                       // 53:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rs_pin B (4)
OP_ICONST_0,                                                           // 56:   iconst_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 57:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_ALOAD_0,                                                            // 60:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _enable_pin), 
                                                                       // 61:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
OP_ICONST_0,                                                           // 64:   iconst_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 65:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_ALOAD_0,                                                            // 68:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rw_pin), 
                                                                       // 69:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
OP_ICONST_M1,                                                          // 72:   iconst_m1
OP_IF_ICMPEQ,        TARGET(84),                                       // 73:   if_icmpeq		#84
OP_ALOAD_0,                                                            // 76:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rw_pin), 
                                                                       // 77:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
OP_ICONST_0,                                                           // 80:   iconst_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 81:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_ALOAD_0,                                                            // 84:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 85:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_BIPUSH,           B(16),                                            // 88:   bipush		16
OP_IAND,                                                               // 90:   iand
OP_IFNE,             TARGET(135),                                      // 91:   ifne		#135
OP_ALOAD_0,                                                            // 94:   aload_0
OP_ICONST_3,                                                           // 95:   iconst_3
OP_INVOKEVIRTUAL,    B(1), LB(MSG_write4bits__B_V),                    // 96:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
OP_SIPUSH,           INT16(4500),                                      // 99:   sipush		4500
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 102:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_ALOAD_0,                                                            // 105:  aload_0
OP_ICONST_3,                                                           // 106:  iconst_3
OP_INVOKEVIRTUAL,    B(1), LB(MSG_write4bits__B_V),                    // 107:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
OP_SIPUSH,           INT16(4500),                                      // 110:  sipush		4500
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 113:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_ALOAD_0,                                                            // 116:  aload_0
OP_ICONST_3,                                                           // 117:  iconst_3
OP_INVOKEVIRTUAL,    B(1), LB(MSG_write4bits__B_V),                    // 118:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
OP_SIPUSH,           INT16(150),                                       // 121:  sipush		150
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 124:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_ALOAD_0,                                                            // 127:  aload_0
OP_ICONST_2,                                                           // 128:  iconst_2
OP_INVOKEVIRTUAL,    B(1), LB(MSG_write4bits__B_V),                    // 129:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
OP_GOTO,             TARGET(183),                                      // 132:  goto		#183
OP_ALOAD_0,                                                            // 135:  aload_0
OP_BIPUSH,           B(32),                                            // 136:  bipush		32
OP_ALOAD_0,                                                            // 138:  aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 139:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_IOR,                                                                // 142:  ior
OP_I2B,                                                                // 143:  i2b
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_command_BV, 
                                                                       // 144:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
OP_SIPUSH,           INT16(4500),                                      // 147:  sipush		4500
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 150:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_ALOAD_0,                                                            // 153:  aload_0
OP_BIPUSH,           B(32),                                            // 154:  bipush		32
OP_ALOAD_0,                                                            // 156:  aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 157:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_IOR,                                                                // 160:  ior
OP_I2B,                                                                // 161:  i2b
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_command_BV, 
                                                                       // 162:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
OP_SIPUSH,           INT16(150),                                       // 165:  sipush		150
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 168:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_ALOAD_0,                                                            // 171:  aload_0
OP_BIPUSH,           B(32),                                            // 172:  bipush		32
OP_ALOAD_0,                                                            // 174:  aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 175:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_IOR,                                                                // 178:  ior
OP_I2B,                                                                // 179:  i2b
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_command_BV, 
                                                                       // 180:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
OP_ALOAD_0,                                                            // 183:  aload_0
OP_BIPUSH,           B(32),                                            // 184:  bipush		32
OP_ALOAD_0,                                                            // 186:  aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 187:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_IOR,                                                                // 190:  ior
OP_I2B,                                                                // 191:  i2b
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_command_BV, 
                                                                       // 192:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
OP_ALOAD_0,                                                            // 195:  aload_0
OP_ICONST_4,                                                           // 196:  iconst_4
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displaycontrol), 
                                                                       // 197:  putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaycontrol B (17)
OP_ALOAD_0,                                                            // 200:  aload_0
OP_INVOKEVIRTUAL,    B(0), LB(MSG_display___V),                        // 201:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.display ()V (18)
OP_ALOAD_0,                                                            // 204:  aload_0
OP_INVOKEVIRTUAL,    B(0), LB(MSG_clear___V),                          // 205:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.clear ()V (19)
OP_ALOAD_0,                                                            // 208:  aload_0
OP_ICONST_2,                                                           // 209:  iconst_2
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displaymode), 
                                                                       // 210:  putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaymode B (20)
OP_ALOAD_0,                                                            // 213:  aload_0
OP_ICONST_4,                                                           // 214:  iconst_4
OP_ALOAD_0,                                                            // 215:  aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displaymode), 
                                                                       // 216:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaymode B (20)
OP_IOR,                                                                // 219:  ior
OP_I2B,                                                                // 220:  i2b
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_command_BV, 
                                                                       // 221:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
OP_RETURN,                                                             // 224:  return
};

/**
public void begin(byte arg1, byte arg2)
Code(max_stack = 4, max_locals = 3, code_length = 8)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV
const           arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV_t JMETHOD PROGMEM ={
4+3 +2,    0,    3,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ILOAD_1,                                                            // 1:    iload_1
OP_ILOAD_2,                                                            // 2:    iload_2
OP_ICONST_0,                                                           // 3:    iconst_0
OP_INVOKEVIRTUAL,    B(3), LB(MSG_begin__BBB_V),                       // 4:    invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.begin (BBB)V (9)
OP_RETURN,                                                             // 7:    return
};

/**
public void clear()
Code(max_stack = 2, max_locals = 1, code_length = 12)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_clear_V
const           arduino_libraries_liquidcrystal_LiquidCrystal_clear_V_t JMETHOD PROGMEM ={
2+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ICONST_1,                                                           // 1:    iconst_1
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_command_BV, 
                                                                       // 2:    invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
OP_SIPUSH,           INT16(2000),                                      // 5:    sipush		2000
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 8:    invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_RETURN,                                                             // 11:   return
};

/**
public void setCursor(byte arg1, byte arg2)
Code(max_stack = 5, max_locals = 4, code_length = 53)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV
const           arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV_t JMETHOD PROGMEM ={
5+4 +2,    1,    3,    // max_stack, purLocals, purParams

OP_ICONST_4,                                                           // 0:    iconst_4
OP_NEWARRAY,         B(1),                                             // 1:    newarray		<byte>
OP_DUP,                                                                // 3:    dup
OP_ICONST_0,                                                           // 4:    iconst_0
OP_ICONST_0,                                                           // 5:    iconst_0
OP_BASTORE,                                                            // 6:    bastore
OP_DUP,                                                                // 7:    dup
OP_ICONST_1,                                                           // 8:    iconst_1
OP_BIPUSH,           B(64),                                            // 9:    bipush		64
OP_BASTORE,                                                            // 11:   bastore
OP_DUP,                                                                // 12:   dup
OP_ICONST_2,                                                           // 13:   iconst_2
OP_BIPUSH,           B(20),                                            // 14:   bipush		20
OP_BASTORE,                                                            // 16:   bastore
OP_DUP,                                                                // 17:   dup
OP_ICONST_3,                                                           // 18:   iconst_3
OP_BIPUSH,           B(84),                                            // 19:   bipush		84
OP_BASTORE,                                                            // 21:   bastore
OP_ASTORE_3,                                                           // 22:   astore_3
OP_ILOAD_2,                                                            // 23:   iload_2
OP_ALOAD_0,                                                            // 24:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _numlines), 
                                                                       // 25:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._numlines B (10)
OP_IF_ICMPLT,        TARGET(39),                                       // 28:   if_icmplt		#39
OP_ALOAD_0,                                                            // 31:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _numlines), 
                                                                       // 32:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._numlines B (10)
OP_ICONST_1,                                                           // 35:   iconst_1
OP_ISUB,                                                               // 36:   isub
OP_I2B,                                                                // 37:   i2b
OP_ISTORE_2,                                                           // 38:   istore_2
OP_ALOAD_0,                                                            // 39:   aload_0
OP_BIPUSH,           B(-128),                                          // 40:   bipush		-128
OP_ILOAD_1,                                                            // 42:   iload_1
OP_ALOAD_3,                                                            // 43:   aload_3
OP_ILOAD_2,                                                            // 44:   iload_2
OP_BALOAD,                                                             // 45:   baload
OP_IADD,                                                               // 46:   iadd
OP_IOR,                                                                // 47:   ior
OP_I2B,                                                                // 48:   i2b
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_command_BV, 
                                                                       // 49:   invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
OP_RETURN,                                                             // 52:   return
};

/**
public void display()
Code(max_stack = 3, max_locals = 1, code_length = 24)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_display_V
const           arduino_libraries_liquidcrystal_LiquidCrystal_display_V_t JMETHOD PROGMEM ={
3+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_DUP,                                                                // 1:    dup
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displaycontrol), 
                                                                       // 2:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaycontrol B (17)
OP_ICONST_4,                                                           // 5:    iconst_4
OP_IOR,                                                                // 6:    ior
OP_I2B,                                                                // 7:    i2b
OP_PUTFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displaycontrol), 
                                                                       // 8:    putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaycontrol B (17)
OP_ALOAD_0,                                                            // 11:   aload_0
OP_BIPUSH,           B(8),                                             // 12:   bipush		8
OP_ALOAD_0,                                                            // 14:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displaycontrol), 
                                                                       // 15:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaycontrol B (17)
OP_IOR,                                                                // 18:   ior
OP_I2B,                                                                // 19:   i2b
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_command_BV, 
                                                                       // 20:   invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
OP_RETURN,                                                             // 23:   return
};

/**
private void command(byte arg1)
Code(max_stack = 3, max_locals = 2, code_length = 7)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_command_BV
const           arduino_libraries_liquidcrystal_LiquidCrystal_command_BV_t JMETHOD PROGMEM ={
3+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ILOAD_1,                                                            // 1:    iload_1
OP_ICONST_0,                                                           // 2:    iconst_0
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV, 
                                                                       // 3:    invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.send (BB)V (22)
OP_RETURN,                                                             // 6:    return
};

/**
public byte write(byte arg1)
Code(max_stack = 3, max_locals = 2, code_length = 8)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_write_BB
const           arduino_libraries_liquidcrystal_LiquidCrystal_write_BB_t JMETHOD PROGMEM ={
3+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ILOAD_1,                                                            // 1:    iload_1
OP_ICONST_1,                                                           // 2:    iconst_1
OP_INVOKESHORT_arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV, 
                                                                       // 3:    invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.send (BB)V (22)
OP_ICONST_1,                                                           // 6:    iconst_1
OP_IRETURN,                                                            // 7:    ireturn
};

/**
private void send(byte arg1, byte arg2)
Code(max_stack = 3, max_locals = 3, code_length = 56)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV
const           arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV_t JMETHOD PROGMEM ={
3+3 +2,    0,    3,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rs_pin), 
                                                                       // 1:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rs_pin B (4)
OP_ILOAD_2,                                                            // 4:    iload_2
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 5:    invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_ALOAD_0,                                                            // 8:    aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rw_pin), 
                                                                       // 9:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
OP_ICONST_M1,                                                          // 12:   iconst_m1
OP_IF_ICMPEQ,        TARGET(24),                                       // 13:   if_icmpeq		#24
OP_ALOAD_0,                                                            // 16:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _rw_pin), 
                                                                       // 17:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
OP_ICONST_0,                                                           // 20:   iconst_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 21:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_ALOAD_0,                                                            // 24:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _displayfunction), 
                                                                       // 25:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
OP_BIPUSH,           B(16),                                            // 28:   bipush		16
OP_IAND,                                                               // 30:   iand
OP_IFEQ,             TARGET(42),                                       // 31:   ifeq		#42
OP_ALOAD_0,                                                            // 34:   aload_0
OP_ILOAD_1,                                                            // 35:   iload_1
OP_INVOKEVIRTUAL,    B(1), LB(MSG_write8bits__B_V),                    // 36:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write8bits (B)V (23)
OP_GOTO,             TARGET(55),                                       // 39:   goto		#55
OP_ALOAD_0,                                                            // 42:   aload_0
OP_ILOAD_1,                                                            // 43:   iload_1
OP_ICONST_4,                                                           // 44:   iconst_4
OP_ISHR,                                                               // 45:   ishr
OP_I2B,                                                                // 46:   i2b
OP_INVOKEVIRTUAL,    B(1), LB(MSG_write4bits__B_V),                    // 47:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
OP_ALOAD_0,                                                            // 50:   aload_0
OP_ILOAD_1,                                                            // 51:   iload_1
OP_INVOKEVIRTUAL,    B(1), LB(MSG_write4bits__B_V),                    // 52:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
OP_RETURN,                                                             // 55:   return
};

/**
public void pulseEnable()
Code(max_stack = 2, max_locals = 1, code_length = 38)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V
const           arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V_t JMETHOD PROGMEM ={
2+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _enable_pin), 
                                                                       // 1:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
OP_ICONST_0,                                                           // 4:    iconst_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 5:    invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_ICONST_1,                                                           // 8:    iconst_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 9:    invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_ALOAD_0,                                                            // 12:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _enable_pin), 
                                                                       // 13:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
OP_ICONST_1,                                                           // 16:   iconst_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 17:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_ICONST_1,                                                           // 20:   iconst_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 21:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_ALOAD_0,                                                            // 24:   aload_0
OP_GETFIELD_B,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _enable_pin), 
                                                                       // 25:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
OP_ICONST_0,                                                           // 28:   iconst_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 29:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_BIPUSH,           B(100),                                           // 32:   bipush		100
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV, 
                                                                       // 34:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
OP_RETURN,                                                             // 37:   return
};

/**
public void write4bits(byte arg1)
Code(max_stack = 3, max_locals = 3, code_length = 43)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV
const           arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV_t JMETHOD PROGMEM ={
3+3 +2,    1,    2,    // max_stack, purLocals, purParams

OP_ICONST_0,                                                           // 0:    iconst_0
OP_ISTORE_2,                                                           // 1:    istore_2
OP_ILOAD_2,                                                            // 2:    iload_2
OP_ICONST_4,                                                           // 3:    iconst_4
OP_IF_ICMPGE,        TARGET(38),                                       // 4:    if_icmpge		#38
OP_ALOAD_0,                                                            // 7:    aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 8:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ILOAD_2,                                                            // 11:   iload_2
OP_BALOAD,                                                             // 12:   baload
OP_ICONST_1,                                                           // 13:   iconst_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV, 
                                                                       // 14:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
OP_ALOAD_0,                                                            // 17:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 18:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ILOAD_2,                                                            // 21:   iload_2
OP_BALOAD,                                                             // 22:   baload
OP_ILOAD_1,                                                            // 23:   iload_1
OP_ILOAD_2,                                                            // 24:   iload_2
OP_ISHR,                                                               // 25:   ishr
OP_ICONST_1,                                                           // 26:   iconst_1
OP_IAND,                                                               // 27:   iand
OP_I2B,                                                                // 28:   i2b
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 29:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_IINC1, B(2),                                                        // 32:   iinc		%2	1
OP_GOTO,             TARGET(2),                                        // 35:   goto		#2
OP_ALOAD_0,                                                            // 38:   aload_0
OP_INVOKEVIRTUAL,    B(0), LB(MSG_pulseEnable___V),                    // 39:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.pulseEnable ()V (24)
OP_RETURN,                                                             // 42:   return
};

/**
public void write8bits(byte arg1)
Code(max_stack = 3, max_locals = 3, code_length = 44)
*/
#undef  JMETHOD
#define JMETHOD arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV
const           arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV_t JMETHOD PROGMEM ={
3+3 +2,    1,    2,    // max_stack, purLocals, purParams

OP_ICONST_0,                                                           // 0:    iconst_0
OP_ISTORE_2,                                                           // 1:    istore_2
OP_ILOAD_2,                                                            // 2:    iload_2
OP_BIPUSH,           B(8),                                             // 3:    bipush		8
OP_IF_ICMPGE,        TARGET(39),                                       // 5:    if_icmpge		#39
OP_ALOAD_0,                                                            // 8:    aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 9:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ILOAD_2,                                                            // 12:   iload_2
OP_BALOAD,                                                             // 13:   baload
OP_ICONST_1,                                                           // 14:   iconst_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV, 
                                                                       // 15:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
OP_ALOAD_0,                                                            // 18:   aload_0
OP_GETFIELD_L,       FIDX(arduino_libraries_liquidcrystal_LiquidCrystal, _data_pins), 
                                                                       // 19:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
OP_ILOAD_2,                                                            // 22:   iload_2
OP_BALOAD,                                                             // 23:   baload
OP_ILOAD_1,                                                            // 24:   iload_1
OP_ILOAD_2,                                                            // 25:   iload_2
OP_ISHR,                                                               // 26:   ishr
OP_ICONST_1,                                                           // 27:   iconst_1
OP_IAND,                                                               // 28:   iand
OP_I2B,                                                                // 29:   i2b
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV, 
                                                                       // 30:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
OP_IINC1, B(2),                                                        // 33:   iinc		%2	1
OP_GOTO,             TARGET(2),                                        // 36:   goto		#2
OP_ALOAD_0,                                                            // 39:   aload_0
OP_INVOKEVIRTUAL,    B(0), LB(MSG_pulseEnable___V),                    // 40:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.pulseEnable ()V (24)
OP_RETURN,                                                             // 43:   return
};

const class_t arduino_libraries_liquidcrystal_LiquidCrystal__class PROGMEM = {
	& processing_hardware_arduino_cores_arduino_Print__class,
	SIZEOF_arduino_libraries_liquidcrystal_LiquidCrystal,
	9,
    {
		{MSG_begin__BBB_V, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV)},
		{MSG_begin__BB_V, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV)},
		{MSG_clear___V, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_clear_V)},
		{MSG_display___V, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_display_V)},
		{MSG_pulseEnable___V, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V)},
		{MSG_setCursor__BB_V, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV)},
		{MSG_write4bits__B_V, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV)},
		{MSG_write8bits__B_V, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV)},
		{MSG_write__B_B, (ByteCode *)(&arduino_libraries_liquidcrystal_LiquidCrystal_write_BB)},
	}
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\Print.c
//
/*
public abstract class processing.hardware.arduino.cores.arduino.Print extends java.lang.Object
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/processing/hardware/arduino/cores/arduino/Print.class
compiled from		Print.java
compiler version	51.0
access flags		1057
constant pool		79 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(Print.java)

2 fields:
	public static final int BYTE = 0
	private static int write_error

22 methods:
	public void <init>()
	protected void setWriteError(int arg1)
	protected void setWriteError()
	public int getWriteError()
	public void clearWriteError()
	public void print(char arg1)
	public abstract byte write(byte arg1)
	public void println(String arg1)
	public void print(String arg1)
	public void print(int arg1)
	public void print(long arg1)
	public void print(long arg1, int arg3)
	public void print(double arg1)
	public void println()
	public void println(char arg1)
	public void println(int arg1)
	public void println(long arg1)
	public void println(long arg1, int arg3)
	public void println(double arg1)
	private void printNumber(long arg1, int arg3)
	public void printFloat(double arg1, int arg3)
	static void <clinit>()

*/



/**
public void <init>()
Code(max_stack = 1, max_locals = 1, code_length = 5)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Print__init__V
const           processing_hardware_arduino_cores_arduino_Print__init__V_t JMETHOD PROGMEM ={
1+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_INVOKESHORT_java_lang_Object__init__V,                              // 1:    invokespecial	java.lang.Object.<init> ()V (1)
OP_RETURN,                                                             // 4:    return
};

/**
public void print(char arg1)
Code(max_stack = 2, max_locals = 2, code_length = 8)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Print_print_CV
const           processing_hardware_arduino_cores_arduino_Print_print_CV_t JMETHOD PROGMEM ={
2+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_ILOAD_1,                                                            // 1:    iload_1
OP_I2B,                                                                // 2:    i2b
OP_INVOKEVIRTUAL,    B(1), LB(MSG_write__B_B),                         // 3:    invokevirtual	processing.hardware.arduino.cores.arduino.Print.write (B)B (4)
OP_POP,                                                                // 6:    pop
OP_RETURN,                                                             // 7:    return
};

/**
public void print(String arg1)
Code(max_stack = 3, max_locals = 3, code_length = 26)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V
const           processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V_t JMETHOD PROGMEM ={
3+3 +2,    1,    2,    // max_stack, purLocals, purParams

OP_ICONST_0,                                                           // 0:    iconst_0
OP_ISTORE_2,                                                           // 1:    istore_2
OP_ILOAD_2,                                                            // 2:    iload_2
OP_ALOAD_1,                                                            // 3:    aload_1
OP_INVOKEVIRTUAL,    B(0), LB(MSG_length___I),                         // 4:    invokevirtual	java.lang.String.length ()I (7)
OP_IF_ICMPGE,        TARGET(25),                                       // 7:    if_icmpge		#25
OP_ALOAD_0,                                                            // 10:   aload_0
OP_ALOAD_1,                                                            // 11:   aload_1
OP_ILOAD_2,                                                            // 12:   iload_2
OP_INVOKEVIRTUAL,    B(1), LB(MSG_charAt__I_C),                        // 13:   invokevirtual	java.lang.String.charAt (I)C (8)
OP_INVOKEVIRTUAL,    B(1), LB(MSG_print__C_V),                         // 16:   invokevirtual	processing.hardware.arduino.cores.arduino.Print.print (C)V (9)
OP_IINC1, B(2),                                                        // 19:   iinc		%2	1
OP_GOTO,             TARGET(2),                                        // 22:   goto		#2
OP_RETURN,                                                             // 25:   return
};

/**
public void print(long arg1)
Code(max_stack = 4, max_locals = 3, code_length = 23)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Print_print_JV
const           processing_hardware_arduino_cores_arduino_Print_print_JV_t JMETHOD PROGMEM ={
4+3 +2,    0,    3,    // max_stack, purLocals, purParams

OP_LLOAD_1,                                                            // 0:    lload_1
OP_LCONST_0,                                                           // 1:    lconst_0
OP_LCMP,                                                               // 2:    lcmp
OP_IFGE,             TARGET(15),                                       // 3:    ifge		#15
OP_ALOAD_0,                                                            // 6:    aload_0
OP_BIPUSH,           B(45),                                            // 7:    bipush		45
OP_INVOKEVIRTUAL,    B(1), LB(MSG_print__C_V),                         // 9:    invokevirtual	processing.hardware.arduino.cores.arduino.Print.print (C)V (9)
OP_LLOAD_1,                                                            // 12:   lload_1
OP_LNEG,                                                               // 13:   lneg
OP_LSTORE_1,                                                           // 14:   lstore_1
OP_ALOAD_0,                                                            // 15:   aload_0
OP_LLOAD_1,                                                            // 16:   lload_1
OP_BIPUSH,           B(10),                                            // 17:   bipush		10
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Print_printNumber_JIV, 
                                                                       // 19:   invokespecial	processing.hardware.arduino.cores.arduino.Print.printNumber (JI)V (11)
OP_RETURN,                                                             // 22:   return
};

/**
private void printNumber(long arg1, int arg3)
Code(max_stack = 6, max_locals = 6, code_length = 105)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Print_printNumber_JIV
const           processing_hardware_arduino_cores_arduino_Print_printNumber_JIV_t JMETHOD PROGMEM ={
6+6 +2,    2,    4,    // max_stack, purLocals, purParams

OP_BIPUSH,           B(32),                                            // 0:    bipush		32
OP_NEWARRAY,         B(1),                                             // 2:    newarray		<byte>
OP_ASTORE,           B(4),                                             // 4:    astore		%4
OP_ICONST_0,                                                           // 6:    iconst_0
OP_ISTORE,           B(5),                                             // 7:    istore		%5
OP_LLOAD_1,                                                            // 9:    lload_1
OP_LCONST_0,                                                           // 10:   lconst_0
OP_LCMP,                                                               // 11:   lcmp
OP_IFNE,             TARGET(22),                                       // 12:   ifne		#22
OP_ALOAD_0,                                                            // 15:   aload_0
OP_BIPUSH,           B(48),                                            // 16:   bipush		48
OP_INVOKEVIRTUAL,    B(1), LB(MSG_print__C_V),                         // 18:   invokevirtual	processing.hardware.arduino.cores.arduino.Print.print (C)V (9)
OP_RETURN,                                                             // 21:   return
OP_LLOAD_1,                                                            // 22:   lload_1
OP_LCONST_0,                                                           // 23:   lconst_0
OP_LCMP,                                                               // 24:   lcmp
OP_IFLE,             TARGET(50),                                       // 25:   ifle		#50
OP_ALOAD,            B(4),                                             // 28:   aload		%4
OP_ILOAD,            B(5),                                             // 30:   iload		%5
OP_IINC1, B(5),                                                        // 32:   iinc		%5	1
OP_LLOAD_1,                                                            // 35:   lload_1
OP_ILOAD_3,                                                            // 36:   iload_3
OP_I2L,                                                                // 37:   i2l
OP_LREM,                                                               // 38:   lrem
OP_L2I,                                                                // 39:   l2i
OP_I2B,                                                                // 40:   i2b
OP_BASTORE,                                                            // 41:   bastore
OP_LLOAD_1,                                                            // 42:   lload_1
OP_ILOAD_3,                                                            // 43:   iload_3
OP_I2L,                                                                // 44:   i2l
OP_LDIV,                                                               // 45:   ldiv
OP_LSTORE_1,                                                           // 46:   lstore_1
OP_GOTO,             TARGET(22),                                       // 47:   goto		#22
OP_ILOAD,            B(5),                                             // 50:   iload		%5
OP_IFLE,             TARGET(104),                                      // 52:   ifle		#104
OP_ALOAD_0,                                                            // 55:   aload_0
OP_ALOAD,            B(4),                                             // 56:   aload		%4
OP_ILOAD,            B(5),                                             // 58:   iload		%5
OP_ICONST_1,                                                           // 60:   iconst_1
OP_ISUB,                                                               // 61:   isub
OP_BALOAD,                                                             // 62:   baload
OP_BIPUSH,           B(10),                                            // 63:   bipush		10
OP_IF_ICMPGE,        TARGET(81),                                       // 65:   if_icmpge		#81
OP_BIPUSH,           B(48),                                            // 68:   bipush		48
OP_ALOAD,            B(4),                                             // 70:   aload		%4
OP_ILOAD,            B(5),                                             // 72:   iload		%5
OP_ICONST_1,                                                           // 74:   iconst_1
OP_ISUB,                                                               // 75:   isub
OP_BALOAD,                                                             // 76:   baload
OP_IADD,                                                               // 77:   iadd
OP_GOTO,             TARGET(94),                                       // 78:   goto		#94
OP_BIPUSH,           B(65),                                            // 81:   bipush		65
OP_ALOAD,            B(4),                                             // 83:   aload		%4
OP_ILOAD,            B(5),                                             // 85:   iload		%5
OP_ICONST_1,                                                           // 87:   iconst_1
OP_ISUB,                                                               // 88:   isub
OP_BALOAD,                                                             // 89:   baload
OP_IADD,                                                               // 90:   iadd
OP_BIPUSH,           B(10),                                            // 91:   bipush		10
OP_ISUB,                                                               // 93:   isub
OP_I2C,                                                                // 94:   i2c
OP_INVOKEVIRTUAL,    B(1), LB(MSG_print__C_V),                         // 95:   invokevirtual	processing.hardware.arduino.cores.arduino.Print.print (C)V (9)
OP_IINC,             B(5), B(255),                                     // 98:   iinc		%5	-1
OP_GOTO,             TARGET(50),                                       // 101:  goto		#50
OP_RETURN,                                                             // 104:  return
};

/**
static void <clinit>()
Code(max_stack = 1, max_locals = 0, code_length = 5)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Print__clinit__V
const           processing_hardware_arduino_cores_arduino_Print__clinit__V_t JMETHOD PROGMEM ={
1+0 +2,    0,    0,    // max_stack, purLocals, purParams

OP_ICONST_0,                                                           // 0:    iconst_0
OP_PUTSTATIC_I,      SADR(processing_hardware_arduino_cores_arduino_Print_write_error), 
                                                                       // 1:    putstatic		processing.hardware.arduino.cores.arduino.Print.write_error I (2)
OP_RETURN,                                                             // 4:    return
};

const class_t processing_hardware_arduino_cores_arduino_Print__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_processing_hardware_arduino_cores_arduino_Print,
	3,
    {
		{MSG_print__C_V, (ByteCode *)(&processing_hardware_arduino_cores_arduino_Print_print_CV)},
		{MSG_print__J_V, (ByteCode *)(&processing_hardware_arduino_cores_arduino_Print_print_JV)},
		{MSG_print__Ljava_lang_String__V, (ByteCode *)(&processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V)},
	}
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\Arduino.c
//
/*
public class processing.hardware.arduino.cores.arduino.Arduino extends java.lang.Object
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/processing/hardware/arduino/cores/arduino/Arduino.class
compiled from		Arduino.java
compiler version	51.0
access flags		33
constant pool		252 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(Arduino.java)

64 fields:
	public static final int HIGH = 1
	public static final int LOW = 0
	public static final int INPUT = 0
	public static final int OUTPUT = 1
	public static final int INPUT_PLLUP = 2
	public static final double PI = 3.141592653589793
	public static final double HALF_PI = 1.5707963267948966
	public static final double TWO_PI = 6.283185307179586
	public static final double DEG_TO_RAD = 0.017453292519943295
	public static final double RAD_TO_DEG = 57.29577951308232
	public static final int SERIAL = 0
	public static final int DISPLAY = 1
	public static final int LSBFIRST = 0
	public static final int MSBFIRST = 1
	public static final int CHANGE = 1
	public static final int FALLING = 2
	public static final int RISING = 3
	public static final int DEFALT = 0
	public static final int EXTERNAL = 1
	public static final int INTERNAL = 2
	public static final int INTERNAL1V1 = 2
	public static final int INTERNAL2V56 = 3
	public static final int DEC = 10
	public static final int HEX = 16
	public static final int OCT = 8
	public static final int BIN = 2
	public static processing.hardware.arduino.cores.arduino.HardwareSerial Serial
	public static final int NOT_A_PIN = 0
	public static final int NOT_A_PORT = 0
	public static final int A0 = 0
	public static final int A1 = 1
	public static final int A2 = 2
	public static final int A3 = 3
	public static final int A4 = 4
	public static final int A5 = 5
	public static final int PA = 1
	public static final int PB = 2
	public static final int PC = 3
	public static final int PD = 4
	public static final int PE = 5
	public static final int PF = 6
	public static final int PG = 7
	public static final int PH = 8
	public static final int PJ = 10
	public static final int PK = 11
	public static final int PL = 12
	public static final int NOT_ON_TIMER = 0
	public static final int TIMER0A = 1
	public static final int TIMER0B = 2
	public static final int TIMER1A = 3
	public static final int TIMER1B = 4
	public static final int TIMER2 = 5
	public static final int TIMER2A = 6
	public static final int TIMER2B = 7
	public static final int TIMER3A = 8
	public static final int TIMER3B = 9
	public static final int TIMER3C = 10
	public static final int TIMER4A = 11
	public static final int TIMER4B = 12
	public static final int TIMER4C = 13
	public static final int TIMER4D = 14
	public static final int TIMER5A = 15
	public static final int TIMER5B = 16
	public static final int TIMER5C = 17

59 methods:
	public void <init>()
	public static int min(int arg0, int arg1)
	public static int max(int arg0, int arg1)
	public static int abs(int arg0)
	public static int constrain(int arg0, int arg1, int arg2)
	public static double min(double arg0, double arg2)
	public static double max(double arg0, double arg2)
	public static double abs(double arg0)
	public static double constrain(double arg0, double arg2, double arg4)
	public static long round(double arg0)
	public static double radians(double arg0)
	public static double degrees(double arg0)
	public static int sq(int arg0)
	public static long sq(long arg0)
	public static double sq(double arg0)
	public static void interrupts()
	public static void noInterrupts()
	public static int clockCyclesPerMicrosecond()
	public static long clockCyclesToMicroseconds(int arg0)
	public static long microsecondsToClockCycles(int arg0)
	public static int lowByte(int arg0)
	public static int highByte(int arg0)
	public static int bitRead(int arg0, int arg1)
	public static int bitSet(int arg0, int arg1)
	public static int bitClear(int arg0, int arg1)
	public static int bitWrite(int arg0, int arg1, int arg2)
	public static int bit(int arg0)
	public static long bitRead(long arg0, int arg2)
	public static long bitSet(long arg0, int arg2)
	public static long bitClear(long arg0, int arg2)
	public static long bitWrite(long arg0, int arg2, int arg3)
	public static long bit(long arg0)
	public static void init()
	public static void pinMode(int arg0, int arg1)
	public static void digitalWrite(int arg0, int arg1)
	public static int digitalRead(int arg0)
	public static int analogRead(int arg0)
	public static void analogReference(int arg0)
	public static void analogWrite(int arg0, int arg1)
	public static long millis()
	public static long micros()
	public static void delay(long arg0)
	public static void delayMicroseconds(int arg0)
	public static long pulseIn(byte arg0, byte arg1, long arg2)
	public static void shiftOut(byte arg0, byte arg1, byte arg2, byte arg3)
	public static byte shiftIn(byte arg0, byte arg1, byte arg2)
	public static void detachInterrupt(byte arg0)
	public static int analogInPinToBit(int arg0)
	public static int makeWord(int arg0)
	public static int makeWord(byte arg0, byte arg1)
	public static long pulseIn(byte arg0, byte arg1)
	public static void tone(int arg0, int arg1)
	public static void tone(int arg0, int arg1, long arg2)
	public static void noTone(int arg0)
	public static long random(long arg0)
	public static long random(long arg0, long arg2)
	public static void randomSeed(int arg0)
	public static long map(long arg0, long arg2, long arg4, long arg6, long arg8)
	static void <clinit>()

*/



/**
public static void pinMode(int arg0, int arg1)
Code(max_stack = 2, max_locals = 2, code_length = 8)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV
const           processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV_t JMETHOD PROGMEM ={
2+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ILOAD_0,                                                            // 0:    iload_0
OP_I2B,                                                                // 1:    i2b
OP_ILOAD_1,                                                            // 2:    iload_1
OP_I2B,                                                                // 3:    i2b
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV, 
                                                                       // 4:    invokestatic	processing.hardware.arduino.cores.arduino.ArduinoImpl.pinMode (BB)V (16)
OP_RETURN,                                                             // 7:    return
};

/**
public static void digitalWrite(int arg0, int arg1)
Code(max_stack = 2, max_locals = 2, code_length = 8)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV
const           processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV_t JMETHOD PROGMEM ={
2+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ILOAD_0,                                                            // 0:    iload_0
OP_I2B,                                                                // 1:    i2b
OP_ILOAD_1,                                                            // 2:    iload_1
OP_I2B,                                                                // 3:    i2b
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV, 
                                                                       // 4:    invokestatic	processing.hardware.arduino.cores.arduino.ArduinoImpl.digitalWrite (BB)V (17)
OP_RETURN,                                                             // 7:    return
};

/**
public static long millis()
Code(max_stack = 2, max_locals = 0, code_length = 4)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Arduino_millis_J
const           processing_hardware_arduino_cores_arduino_Arduino_millis_J_t JMETHOD PROGMEM ={
2+0 +2,    0,    0,    // max_stack, purLocals, purParams

OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J, 
                                                                       // 0:    invokestatic	processing.hardware.arduino.cores.arduino.ArduinoImpl.millis ()J (22)
OP_LRETURN,                                                            // 3:    lreturn
};

/**
public static void delayMicroseconds(int arg0)
Code(max_stack = 1, max_locals = 1, code_length = 5)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV
const           processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV_t JMETHOD PROGMEM ={
1+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ILOAD_0,                                                            // 0:    iload_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV, 
                                                                       // 1:    invokestatic	processing.hardware.arduino.cores.arduino.ArduinoImpl.delayMicroseconds (I)V (25)
OP_RETURN,                                                             // 4:    return
};

/**
static void <clinit>()
Code(max_stack = 2, max_locals = 0, code_length = 11)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Arduino__clinit__V
const           processing_hardware_arduino_cores_arduino_Arduino__clinit__V_t JMETHOD PROGMEM ={
2+0 +2,    0,    0,    // max_stack, purLocals, purParams

OP_NEW,              ADR(processing_hardware_arduino_cores_arduino_HardwareSerial__class), 
                                                                       // 0:    new		<processing.hardware.arduino.cores.arduino.HardwareSerial> (41)
OP_DUP,                                                                // 3:    dup
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_HardwareSerial__init__V, 
                                                                       // 4:    invokespecial	processing.hardware.arduino.cores.arduino.HardwareSerial.<init> ()V (42)
OP_PUTSTATIC_L,      SADR(processing_hardware_arduino_cores_arduino_Arduino_Serial), 
                                                                       // 7:    putstatic		processing.hardware.arduino.cores.arduino.Arduino.Serial Lprocessing/hardware/arduino/cores/arduino/HardwareSerial; (43)
OP_RETURN,                                                             // 10:   return
};

const class_t processing_hardware_arduino_cores_arduino_Arduino__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_processing_hardware_arduino_cores_arduino_Arduino,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\HardwareSerial.c
//
/*
public class processing.hardware.arduino.cores.arduino.HardwareSerial extends processing.hardware.arduino.cores.arduino.Stream
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/processing/hardware/arduino/cores/arduino/HardwareSerial.class
compiled from		HardwareSerial.java
compiler version	51.0
access flags		33
constant pool		41 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(HardwareSerial.java)

1 fields:
	private int lastChar

8 methods:
	public void <init>()
	public void begin(long arg1)
	public int available()
	public int read()
	public byte write(byte arg1)
	public boolean isOpen()
	public void flush()
	public int peek()

*/



/**
public void <init>()
Code(max_stack = 2, max_locals = 1, code_length = 10)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_HardwareSerial__init__V
const           processing_hardware_arduino_cores_arduino_HardwareSerial__init__V_t JMETHOD PROGMEM ={
2+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Stream__init__V, 
                                                                       // 1:    invokespecial	processing.hardware.arduino.cores.arduino.Stream.<init> ()V (1)
OP_ALOAD_0,                                                            // 4:    aload_0
OP_ICONST_M1,                                                          // 5:    iconst_m1
OP_PUTFIELD_I,       FIDX(processing_hardware_arduino_cores_arduino_HardwareSerial, lastChar), 
                                                                       // 6:    putfield		processing.hardware.arduino.cores.arduino.HardwareSerial.lastChar I (2)
OP_RETURN,                                                             // 9:    return
};

/**
public byte write(byte arg1)
Code(max_stack = 1, max_locals = 2, code_length = 5)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB
const           processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB_t JMETHOD PROGMEM ={
1+2 +2,    0,    2,    // max_stack, purLocals, purParams

OP_ILOAD_1,                                                            // 0:    iload_1
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB, 
                                                                       // 1:    invokestatic	processing.hardware.arduino.cores.arduino.HardwareSerialImpl.write (B)B (6)
OP_IRETURN,                                                            // 4:    ireturn
};

const class_t processing_hardware_arduino_cores_arduino_HardwareSerial__class PROGMEM = {
	& processing_hardware_arduino_cores_arduino_Stream__class,
	SIZEOF_processing_hardware_arduino_cores_arduino_HardwareSerial,
	1,
    {
		{MSG_write__B_B, (ByteCode *)(&processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB)},
	}
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\Stream.c
//
/*
public abstract class processing.hardware.arduino.cores.arduino.Stream extends processing.hardware.arduino.cores.arduino.Print
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/processing/hardware/arduino/cores/arduino/Stream.class
compiled from		Stream.java
compiler version	51.0
access flags		1057
constant pool		64 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(Stream.java)

4 fields:
	private long _timeout
	private long _startMillis
	private final int PARSE_TIMEOUT = 1000
	private final char NO_SKIP_CHAR = 1

11 methods:
	public void <init>()
	public abstract byte write(byte arg1)
	public abstract int read()
	public abstract int available()
	public abstract int peek()
	public abstract void flush()
	private int timedRead()
	private int timedPeek()
	public long parseInt()
	public long parseInt(char arg1)
	private int peekNextDigit()

*/



/**
public void <init>()
Code(max_stack = 2, max_locals = 1, code_length = 17)
*/
#undef  JMETHOD
#define JMETHOD processing_hardware_arduino_cores_arduino_Stream__init__V
const           processing_hardware_arduino_cores_arduino_Stream__init__V_t JMETHOD PROGMEM ={
2+1 +2,    0,    1,    // max_stack, purLocals, purParams

OP_ALOAD_0,                                                            // 0:    aload_0
OP_INVOKESHORT_processing_hardware_arduino_cores_arduino_Print__init__V, 
                                                                       // 1:    invokespecial	processing.hardware.arduino.cores.arduino.Print.<init> ()V (1)
OP_ALOAD_0,                                                            // 4:    aload_0
OP_SIPUSH,           INT16(1000),                                      // 5:    sipush		1000
OP_PUTFIELD_I,       FIDX(processing_hardware_arduino_cores_arduino_Stream, PARSE_TIMEOUT_jfPARSE_TIMEOUT), 
                                                                       // 8:    putfield		processing.hardware.arduino.cores.arduino.Stream.PARSE_TIMEOUT I (2)
OP_ALOAD_0,                                                            // 11:   aload_0
OP_ICONST_1,                                                           // 12:   iconst_1
OP_PUTFIELD_C,       FIDX(processing_hardware_arduino_cores_arduino_Stream, NO_SKIP_CHAR_jfNO_SKIP_CHAR), 
                                                                       // 13:   putfield		processing.hardware.arduino.cores.arduino.Stream.NO_SKIP_CHAR C (3)
OP_RETURN,                                                             // 16:   return
};

const class_t processing_hardware_arduino_cores_arduino_Stream__class PROGMEM = {
	& processing_hardware_arduino_cores_arduino_Print__class,
	SIZEOF_processing_hardware_arduino_cores_arduino_Stream,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\HardwareSerialImpl.c
//
/*
public class processing.hardware.arduino.cores.arduino.HardwareSerialImpl extends java.lang.Object
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/processing/hardware/arduino/cores/arduino/HardwareSerialImpl.class
compiled from		HardwareSerialImpl.java
compiler version	51.0
access flags		33
constant pool		22 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(HardwareSerialImpl.java)

6 methods:
	public void <init>()
	public static native void begin(long arg0)
	public static native int available()
	public static native int read()
	public static native byte write(byte arg0)
	public static native boolean isOpen()

*/



/**
public static native byte write(byte arg0)
*/
#ifndef native_processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB
const NativCode processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB PROGMEM ={0xff, &native_processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB};
#endif

const class_t processing_hardware_arduino_cores_arduino_HardwareSerialImpl__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_processing_hardware_arduino_cores_arduino_HardwareSerialImpl,
	0,
    // {{}} VC 5
};


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\ArduinoImpl.c
//
/*
public class processing.hardware.arduino.cores.arduino.ArduinoImpl extends java.lang.Object
filename		C:\Users\cdn\AppData\Local\Temp\haikuvm/processing/hardware/arduino/cores/arduino/ArduinoImpl.class
compiled from		ArduinoImpl.java
compiler version	51.0
access flags		33
constant pool		65 entries
ACC_SUPER flag		true

Attribute(s):
	SourceFile(ArduinoImpl.java)

1 fields:
	public static final long F_CPU = 16000000

26 methods:
	public void <init>()
	public static native void init() [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void pinMode(byte arg0, byte arg1) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void digitalWrite(byte arg0, byte arg1) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native int digitalRead(byte arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native int analogRead(byte arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void analogReference(byte arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void analogWrite(byte arg0, int arg1) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native long millis() [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native long micros() [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static void delay(long arg0)
	public static native void delayMicroseconds(int arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native long pulseIn(byte arg0, byte arg1, long arg2) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void shiftOut(byte arg0, byte arg1, byte arg2, byte arg3) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native byte shiftIn(byte arg0, byte arg1, byte arg2) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void detachInterrupt(byte arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void setup() [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void loop() [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native int makeWord(int arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native int makeWord(byte arg0, byte arg1) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
	public static native void tone(byte arg0, int arg1, long arg2) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 30 00 00)]
	public static native void noTone(byte arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 30 00 00)]
	public static native long random(long arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 30 00 00)]
	public static native long random(long arg0, long arg2) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 30 00 00)]
	public static native void randomSeed(int arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 30 00 00)]
	public static native long map(long arg0, long arg2, long arg4, long arg6, long arg8) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 30 00 00)]

*/



/**
public static native void pinMode(byte arg0, byte arg1) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
*/
#ifndef native_processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV
const NativCode processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV PROGMEM ={0xff, &native_processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV};
#endif

/**
public static native void digitalWrite(byte arg0, byte arg1) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
*/
#ifndef native_processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV
const NativCode processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV PROGMEM ={0xff, &native_processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV};
#endif

/**
public static native long millis() [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
*/
#ifndef native_processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J
const NativCode processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J PROGMEM ={0xff, &native_processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J};
#endif

/**
public static native void delayMicroseconds(int arg0) [(Unknown attribute RuntimeVisibleAnnotations: 00 01 00 10 00 00)]
*/
#ifndef native_processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV
const NativCode processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV PROGMEM ={0xff, &native_processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV};
#endif

const class_t processing_hardware_arduino_cores_arduino_ArduinoImpl__class PROGMEM = {
	& java_lang_Object__class,
	SIZEOF_processing_hardware_arduino_cores_arduino_ArduinoImpl,
	0,
    // {{}} VC 5
};


