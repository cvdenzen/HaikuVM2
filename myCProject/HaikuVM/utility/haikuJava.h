//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\haiku\avr\lib\arduino\HaikuMicroKernelProcessing.h
//
#ifndef native_haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V
extern const NativCode haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V;
extern void            native_haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V(void);
#endif

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    invokestatic	haiku.avr.lib.arduino.HaikuMicroKernelProcessing.clinitHaikuMagic ()V (2)
	OP_bc op6;                                                             // 6:    invokestatic	haiku.avr.lib.arduino.HaikuMicroKernelProcessing.init ()V (4)
	OP_bc op9;                                                             // 9:    invokestatic	haiku.vm.HaikuMagic.setup ()V (5)
	OP_bc op12;                                                            // 12:   invokestatic	haiku.vm.HaikuMagic.loop ()V (6)
	OP_bc op15; OPtrg a15;                                                 // 15:   goto		#12
	OP_bc op18;                                                            // 18:   astore_1
	OP_bc op19;                                                            // 19:   invokestatic	java.lang.Thread.currentThread ()Ljava/lang/Thread; (8)
	OP_bc op22; OP__8 a22; OP__8 b22;                                      // 22:   invokevirtual	java.lang.Thread.stop ()V (9)
	OP_bc op25;                                                            // 25:   return
}            main_YLjava_lang_String_t;
extern const main_YLjava_lang_String_t main_YLjava_lang_String;



#ifndef haiku_avr_lib_arduino_HaikuMicroKernelProcessing

#define SIZEOF_haiku_avr_lib_arduino_HaikuMicroKernelProcessing 0


#endif
extern const class_t haiku_avr_lib_arduino_HaikuMicroKernelProcessing__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\Throwable.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    invokespecial	java.lang.Object.<init> ()V (1)
	OP_bc op4;                                                             // 4:    aload_0
	OP_bc op5; OP__8 a5; OP__8 b5;                                         // 5:    invokevirtual	java.lang.Throwable.fillInStackTrace ()Ljava/lang/Throwable; (2)
	OP_bc op8;                                                             // 8:    pop
	OP_bc op9;                                                             // 9:    aload_0
	OP_bc op10;                                                            // 10:   aload_1
	OP_bc op11; OP_16 a11;                                                 // 11:   putfield		java.lang.Throwable._message Ljava/lang/String; (3)
	OP_bc op14;                                                            // 14:   return
}            java_lang_Throwable__init__Ljava_lang_String_V_t;
extern const java_lang_Throwable__init__Ljava_lang_String_V_t java_lang_Throwable__init__Ljava_lang_String_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    areturn
}            java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable_t;
extern const java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable_t java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable;



#ifndef java_lang_Throwable

typedef struct java_lang_Throwable {
  jintArray _stackTrace;	//[I
  jstring _message;	//Ljava/lang/String;
  jobject _cause;	//Ljava/lang/Throwable;
} java_lang_Throwable;
#define SIZEOF_java_lang_Throwable sizeof(java_lang_Throwable)


#endif
extern const class_t java_lang_Throwable__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\Object.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    return
}            java_lang_Object__init__V_t;
extern const java_lang_Object__init__V_t java_lang_Object__init__V;



#ifndef java_lang_Object

#define SIZEOF_java_lang_Object 0


#endif
extern const class_t java_lang_Object__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\Thread.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1; OP_16 a1;                                                   // 1:    getfield		java.lang.Thread.state I (19)
	OP_bc op4; OP__8 b4;                                                   // 4:    bipush		8
	OP_bc op6; OPtrg a6;                                                   // 6:    if_icmpeq		#45
	OP_bc op9;                                                             // 9:    aload_0
	OP_bc op10;                                                            // 10:   astore_1
	OP_bc op11;                                                            // 11:   aload_1
	OP_bc op12; OP_16 a12;                                                 // 12:   getfield		java.lang.Thread.next Ljava/lang/Thread; (12)
	OP_bc op15;                                                            // 15:   aload_0
	OP_bc op16; OPtrg a16;                                                 // 16:   if_acmpeq		#27
	OP_bc op19;                                                            // 19:   aload_1
	OP_bc op20; OP_16 a20;                                                 // 20:   getfield		java.lang.Thread.next Ljava/lang/Thread; (12)
	OP_bc op23;                                                            // 23:   astore_1
	OP_bc op24; OPtrg a24;                                                 // 24:   goto		#11
	OP_bc op27;                                                            // 27:   aload_1
	OP_bc op28;                                                            // 28:   aload_1
	OP_bc op29; OP_16 a29;                                                 // 29:   getfield		java.lang.Thread.next Ljava/lang/Thread; (12)
	OP_bc op32; OP_16 a32;                                                 // 32:   getfield		java.lang.Thread.next Ljava/lang/Thread; (12)
	OP_bc op35; OP_16 a35;                                                 // 35:   putfield		java.lang.Thread.next Ljava/lang/Thread; (12)
	OP_bc op38;                                                            // 38:   aload_0
	OP_bc op39; OP__8 b39;                                                 // 39:   bipush		8
	OP_bc op41;                                                            // 41:   invokespecial	java.lang.Thread.setStateAndSwitch (I)I (8)
	OP_bc op44;                                                            // 44:   pop
	OP_bc op45;                                                            // 45:   return
}            java_lang_Thread_stop_V_t;
extern const java_lang_Thread_stop_V_t java_lang_Thread_stop_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0; OPadr a0;                                                   // 0:    getstatic		java.lang.Thread.currentThread Ljava/lang/Thread; (3)
	OP_bc op3;                                                             // 3:    areturn
}            java_lang_Thread_currentThread_Ljava_lang_Thread_t;
extern const java_lang_Thread_currentThread_Ljava_lang_Thread_t java_lang_Thread_currentThread_Ljava_lang_Thread;

#ifndef native_java_lang_Thread_setStateAndSwitch_II
extern const NativCode java_lang_Thread_setStateAndSwitch_II;
extern void            native_java_lang_Thread_setStateAndSwitch_II(void);
#endif



#ifndef java_lang_Thread

typedef struct java_lang_Thread {
  jobject target;	//Ljava/lang/Runnable;
  jobject next;	//Ljava/lang/Thread;
  jint state;	//I
  jobject programcounter;	//Ljava/lang/Object;
  jobject stackpointer;	//Ljava/lang/Object;
  jobject stackframe;	//Ljava/lang/Object;
  jobject stack;	//Ljava/lang/Object;
  jlong waitUntil;	//J
  jobject locks;	//Ljava/lang/Object;
  jboolean interrupt;	//Z
  jobject waitingOn;	//Ljava/lang/Object;
} java_lang_Thread;
#define SIZEOF_java_lang_Thread sizeof(java_lang_Thread)


#endif
extern const class_t java_lang_Thread__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\Yarrays\YC.h
//
extern const class_t YC__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\String.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1; OP_16 a1;                                                   // 1:    getfield		java.lang.String.characters [C (2)
	OP_bc op4;                                                             // 4:    arraylength
	OP_bc op5;                                                             // 5:    ireturn
}            java_lang_String_length_I_t;
extern const java_lang_String_length_I_t java_lang_String_length_I;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1; OP_16 a1;                                                   // 1:    getfield		java.lang.String.characters [C (2)
	OP_bc op4;                                                             // 4:    iload_1
	OP_bc op5;                                                             // 5:    caload
	OP_bc op6;                                                             // 6:    ireturn
}            java_lang_String_charAt_IC_t;
extern const java_lang_String_charAt_IC_t java_lang_String_charAt_IC;



#ifndef java_lang_String

typedef struct java_lang_String {
  jchar8or16Array characters;	//[C
} java_lang_String;
#define SIZEOF_java_lang_String sizeof(java_lang_String)


#endif
extern const class_t java_lang_String__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\haiku\vm\MicroKernel.h
//
typedef struct {
    uint8_t max_stack; int8_t purLocals; uint8_t purParams;
	OP_bc oph149; OPadr fh149;  // <clinit>
	OP_bc oph152; OPadr fh152;  // <clinit>
	OP_bc oph155; OPadr fh155;  // <clinit>
	OP_bc oph158; OPadr fh158;  // <clinit>
    OP_bc op0;                                                             //       return
}            haiku_vm_MicroKernel_clinitHaikuMagic_V_t;
extern const haiku_vm_MicroKernel_clinitHaikuMagic_V_t haiku_vm_MicroKernel_clinitHaikuMagic_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0; OPadr f0;                                                   // 0:    new		<java.lang.OutOfMemoryError> (42)
	OP_bc op3;                                                             // 3:    dup
	OP_bc op4; OPcon c4;                                                   // 4:    ldc		"OutOfMemoryError" (43)
	OP_bc op6;                                                             // 6:    invokespecial	java.lang.OutOfMemoryError.<init> (Ljava/lang/String;)V (44)
	OP_bc op9; OPadr a9;                                                   // 9:    putstatic		haiku.vm.MicroKernel.outOfMemoryError Ljava/lang/Throwable; (26)
	OP_bc op12;                                                            // 12:   return
}            haiku_vm_MicroKernel__clinit__V_t;
extern const haiku_vm_MicroKernel__clinit__V_t haiku_vm_MicroKernel__clinit__V;



#ifndef haiku_vm_MicroKernel

#define SIZEOF_haiku_vm_MicroKernel 0


#endif
extern const class_t haiku_vm_MicroKernel__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\OutOfMemoryError.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    aload_1
	OP_bc op2;                                                             // 2:    invokespecial	java.lang.Error.<init> (Ljava/lang/String;)V (2)
	OP_bc op5;                                                             // 5:    return
}            java_lang_OutOfMemoryError__init__Ljava_lang_String_V_t;
extern const java_lang_OutOfMemoryError__init__Ljava_lang_String_V_t java_lang_OutOfMemoryError__init__Ljava_lang_String_V;



#ifndef java_lang_OutOfMemoryError

typedef struct java_lang_OutOfMemoryError {
  jintArray _stackTrace;	//[I
  jstring _message;	//Ljava/lang/String;
  jobject _cause;	//Ljava/lang/Throwable;
} java_lang_OutOfMemoryError;
#define SIZEOF_java_lang_OutOfMemoryError sizeof(java_lang_OutOfMemoryError)


#endif
extern const class_t java_lang_OutOfMemoryError__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\java\lang\Error.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    aload_1
	OP_bc op2;                                                             // 2:    invokespecial	java.lang.Throwable.<init> (Ljava/lang/String;)V (2)
	OP_bc op5;                                                             // 5:    return
}            java_lang_Error__init__Ljava_lang_String_V_t;
extern const java_lang_Error__init__Ljava_lang_String_V_t java_lang_Error__init__Ljava_lang_String_V;



#ifndef java_lang_Error

typedef struct java_lang_Error {
  jintArray _stackTrace;	//[I
  jstring _message;	//Ljava/lang/String;
  jobject _cause;	//Ljava/lang/Throwable;
} java_lang_Error;
#define SIZEOF_java_lang_Error sizeof(java_lang_Error)


#endif
extern const class_t java_lang_Error__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\arduino\libraries\liquidcrystal\LiquidCrystalHelloWorld.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0; OPadr a0;                                                   // 0:    getstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
	OP_bc op3; OP__8 b3;                                                   // 3:    bipush		16
	OP_bc op5;                                                             // 5:    iconst_2
	OP_bc op6; OP__8 a6; OP__8 b6;                                         // 6:    invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.begin (BB)V (3)
	OP_bc op9; OPadr a9;                                                   // 9:    getstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
	OP_bc op12; OPcon c12;                                                 // 12:   ldc		"hello, world A!" (4)
	OP_bc op14; OP__8 a14; OP__8 b14;                                      // 14:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.print (Ljava/lang/String;)V (5)
	OP_bc op17;                                                            // 17:   return
}            arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V_t arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0; OPadr a0;                                                   // 0:    getstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
	OP_bc op3;                                                             // 3:    iconst_0
	OP_bc op4;                                                             // 4:    iconst_1
	OP_bc op5; OP__8 a5; OP__8 b5;                                         // 5:    invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.setCursor (BB)V (6)
	OP_bc op8; OPadr a8;                                                   // 8:    getstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
	OP_bc op11;                                                            // 11:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.millis ()J (7)
	OP_bc op14; OPcon c14;                                                 // 14:   ldc2_w		500 (8)
	OP_bc op17;                                                            // 17:   ldiv
	OP_bc op18; OP__8 a18; OP__8 b18;                                      // 18:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.print (J)V (10)
	OP_bc op21;                                                            // 21:   return
}            arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V_t arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0; OPadr f0;                                                   // 0:    new		<arduino.libraries.liquidcrystal.LiquidCrystal> (11)
	OP_bc op3;                                                             // 3:    dup
	OP_bc op4; OP__8 b4;                                                   // 4:    bipush		8
	OP_bc op6; OP__8 b6;                                                   // 6:    bipush		9
	OP_bc op8;                                                             // 8:    iconst_4
	OP_bc op9;                                                             // 9:    iconst_5
	OP_bc op10; OP__8 b10;                                                 // 10:   bipush		6
	OP_bc op12; OP__8 b12;                                                 // 12:   bipush		7
	OP_bc op14;                                                            // 14:   invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.<init> (BBBBBB)V (12)
	OP_bc op17; OPadr a17;                                                 // 17:   putstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.lcd Larduino/libraries/liquidcrystal/LiquidCrystal; (2)
	OP_bc op20;                                                            // 20:   iconst_0
	OP_bc op21; OPadr a21;                                                 // 21:   putstatic		arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld.teller I (13)
	OP_bc op24;                                                            // 24:   return
}            arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V_t arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V;



#ifndef arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld

#define SIZEOF_arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld 0


#endif
extern const class_t arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\Yarrays\YB.h
//
extern const class_t YB__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\arduino\libraries\liquidcrystal\LiquidCrystal.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    invokespecial	processing.hardware.arduino.cores.arduino.Print.<init> ()V (1)
	OP_bc op4;                                                             // 4:    aload_0
	OP_bc op5; OP__8 b5;                                                   // 5:    bipush		8
	OP_bc op7; OP__8 b7;                                                   // 7:    newarray		<byte>
	OP_bc op9; OP_16 a9;                                                   // 9:    putfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op12;                                                            // 12:   aload_0
	OP_bc op13;                                                            // 13:   iconst_1
	OP_bc op14;                                                            // 14:   iload_1
	OP_bc op15;                                                            // 15:   iconst_m1
	OP_bc op16;                                                            // 16:   iload_2
	OP_bc op17;                                                            // 17:   iload_3
	OP_bc op18; OP__8 b18;                                                 // 18:   iload		%4
	OP_bc op20; OP__8 b20;                                                 // 20:   iload		%5
	OP_bc op22; OP__8 b22;                                                 // 22:   iload		%6
	OP_bc op24;                                                            // 24:   iconst_0
	OP_bc op25;                                                            // 25:   iconst_0
	OP_bc op26;                                                            // 26:   iconst_0
	OP_bc op27;                                                            // 27:   iconst_0
	OP_bc op28;                                                            // 28:   invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.init (BBBBBBBBBBBB)V (3)
	OP_bc op31;                                                            // 31:   return
}            arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV_t arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    iload_2
	OP_bc op2; OP_16 a2;                                                   // 2:    putfield		arduino.libraries.liquidcrystal.LiquidCrystal._rs_pin B (4)
	OP_bc op5;                                                             // 5:    aload_0
	OP_bc op6;                                                             // 6:    iload_3
	OP_bc op7; OP_16 a7;                                                   // 7:    putfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
	OP_bc op10;                                                            // 10:   aload_0
	OP_bc op11; OP__8 b11;                                                 // 11:   iload		%4
	OP_bc op13; OP_16 a13;                                                 // 13:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
	OP_bc op16;                                                            // 16:   aload_0
	OP_bc op17; OP_16 a17;                                                 // 17:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op20;                                                            // 20:   iconst_0
	OP_bc op21; OP__8 b21;                                                 // 21:   iload		%5
	OP_bc op23;                                                            // 23:   bastore
	OP_bc op24;                                                            // 24:   aload_0
	OP_bc op25; OP_16 a25;                                                 // 25:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op28;                                                            // 28:   iconst_1
	OP_bc op29; OP__8 b29;                                                 // 29:   iload		%6
	OP_bc op31;                                                            // 31:   bastore
	OP_bc op32;                                                            // 32:   aload_0
	OP_bc op33; OP_16 a33;                                                 // 33:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op36;                                                            // 36:   iconst_2
	OP_bc op37; OP__8 b37;                                                 // 37:   iload		%7
	OP_bc op39;                                                            // 39:   bastore
	OP_bc op40;                                                            // 40:   aload_0
	OP_bc op41; OP_16 a41;                                                 // 41:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op44;                                                            // 44:   iconst_3
	OP_bc op45; OP__8 b45;                                                 // 45:   iload		%8
	OP_bc op47;                                                            // 47:   bastore
	OP_bc op48;                                                            // 48:   aload_0
	OP_bc op49; OP_16 a49;                                                 // 49:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op52;                                                            // 52:   iconst_4
	OP_bc op53; OP__8 b53;                                                 // 53:   iload		%9
	OP_bc op55;                                                            // 55:   bastore
	OP_bc op56;                                                            // 56:   aload_0
	OP_bc op57; OP_16 a57;                                                 // 57:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op60;                                                            // 60:   iconst_5
	OP_bc op61; OP__8 b61;                                                 // 61:   iload		%10
	OP_bc op63;                                                            // 63:   bastore
	OP_bc op64;                                                            // 64:   aload_0
	OP_bc op65; OP_16 a65;                                                 // 65:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op68; OP__8 b68;                                                 // 68:   bipush		6
	OP_bc op70; OP__8 b70;                                                 // 70:   iload		%11
	OP_bc op72;                                                            // 72:   bastore
	OP_bc op73;                                                            // 73:   aload_0
	OP_bc op74; OP_16 a74;                                                 // 74:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op77; OP__8 b77;                                                 // 77:   bipush		7
	OP_bc op79; OP__8 b79;                                                 // 79:   iload		%12
	OP_bc op81;                                                            // 81:   bastore
	OP_bc op82;                                                            // 82:   aload_0
	OP_bc op83; OP_16 a83;                                                 // 83:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rs_pin B (4)
	OP_bc op86;                                                            // 86:   iconst_1
	OP_bc op87;                                                            // 87:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
	OP_bc op90;                                                            // 90:   aload_0
	OP_bc op91; OP_16 a91;                                                 // 91:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
	OP_bc op94;                                                            // 94:   iconst_m1
	OP_bc op95; OPtrg a95;                                                 // 95:   if_icmpeq		#106
	OP_bc op98;                                                            // 98:   aload_0
	OP_bc op99; OP_16 a99;                                                 // 99:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
	OP_bc op102;                                                           // 102:  iconst_1
	OP_bc op103;                                                           // 103:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
	OP_bc op106;                                                           // 106:  aload_0
	OP_bc op107; OP_16 a107;                                               // 107:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
	OP_bc op110;                                                           // 110:  iconst_1
	OP_bc op111;                                                           // 111:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
	OP_bc op114;                                                           // 114:  iload_1
	OP_bc op115; OPtrg a115;                                               // 115:  ifeq		#126
	OP_bc op118;                                                           // 118:  aload_0
	OP_bc op119;                                                           // 119:  iconst_0
	OP_bc op120; OP_16 a120;                                               // 120:  putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op123; OPtrg a123;                                               // 123:  goto		#132
	OP_bc op126;                                                           // 126:  aload_0
	OP_bc op127; OP__8 b127;                                               // 127:  bipush		16
	OP_bc op129; OP_16 a129;                                               // 129:  putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op132;                                                           // 132:  aload_0
	OP_bc op133; OP__8 b133;                                               // 133:  bipush		16
	OP_bc op135;                                                           // 135:  iconst_1
	OP_bc op136;                                                           // 136:  iconst_0
	OP_bc op137; OP__8 a137; OP__8 b137;                                   // 137:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.begin (BBB)V (9)
	OP_bc op140;                                                           // 140:  return
}            arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV_t arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iload_2
	OP_bc op1;                                                             // 1:    iconst_1
	OP_bc op2; OPtrg a2;                                                   // 2:    if_icmple		#17
	OP_bc op5;                                                             // 5:    aload_0
	OP_bc op6;                                                             // 6:    dup
	OP_bc op7; OP_16 a7;                                                   // 7:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op10; OP__8 b10;                                                 // 10:   bipush		8
	OP_bc op12;                                                            // 12:   ior
	OP_bc op13;                                                            // 13:   i2b
	OP_bc op14; OP_16 a14;                                                 // 14:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op17;                                                            // 17:   aload_0
	OP_bc op18;                                                            // 18:   iload_2
	OP_bc op19; OP_16 a19;                                                 // 19:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._numlines B (10)
	OP_bc op22;                                                            // 22:   aload_0
	OP_bc op23;                                                            // 23:   iconst_0
	OP_bc op24; OP_16 a24;                                                 // 24:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._currline B (11)
	OP_bc op27;                                                            // 27:   iload_3
	OP_bc op28; OPtrg a28;                                                 // 28:   ifeq		#47
	OP_bc op31;                                                            // 31:   iload_2
	OP_bc op32;                                                            // 32:   iconst_1
	OP_bc op33; OPtrg a33;                                                 // 33:   if_icmpne		#47
	OP_bc op36;                                                            // 36:   aload_0
	OP_bc op37;                                                            // 37:   dup
	OP_bc op38; OP_16 a38;                                                 // 38:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op41;                                                            // 41:   iconst_4
	OP_bc op42;                                                            // 42:   ior
	OP_bc op43;                                                            // 43:   i2b
	OP_bc op44; OP_16 a44;                                                 // 44:   putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op47; OPcon c47;                                                 // 47:   ldc		50000 (12)
	OP_bc op49;                                                            // 49:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op52;                                                            // 52:   aload_0
	OP_bc op53; OP_16 a53;                                                 // 53:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rs_pin B (4)
	OP_bc op56;                                                            // 56:   iconst_0
	OP_bc op57;                                                            // 57:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op60;                                                            // 60:   aload_0
	OP_bc op61; OP_16 a61;                                                 // 61:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
	OP_bc op64;                                                            // 64:   iconst_0
	OP_bc op65;                                                            // 65:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op68;                                                            // 68:   aload_0
	OP_bc op69; OP_16 a69;                                                 // 69:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
	OP_bc op72;                                                            // 72:   iconst_m1
	OP_bc op73; OPtrg a73;                                                 // 73:   if_icmpeq		#84
	OP_bc op76;                                                            // 76:   aload_0
	OP_bc op77; OP_16 a77;                                                 // 77:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
	OP_bc op80;                                                            // 80:   iconst_0
	OP_bc op81;                                                            // 81:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op84;                                                            // 84:   aload_0
	OP_bc op85; OP_16 a85;                                                 // 85:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op88; OP__8 b88;                                                 // 88:   bipush		16
	OP_bc op90;                                                            // 90:   iand
	OP_bc op91; OPtrg a91;                                                 // 91:   ifne		#135
	OP_bc op94;                                                            // 94:   aload_0
	OP_bc op95;                                                            // 95:   iconst_3
	OP_bc op96; OP__8 a96; OP__8 b96;                                      // 96:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
	OP_bc op99; OP_16 a99;                                                 // 99:   sipush		4500
	OP_bc op102;                                                           // 102:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op105;                                                           // 105:  aload_0
	OP_bc op106;                                                           // 106:  iconst_3
	OP_bc op107; OP__8 a107; OP__8 b107;                                   // 107:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
	OP_bc op110; OP_16 a110;                                               // 110:  sipush		4500
	OP_bc op113;                                                           // 113:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op116;                                                           // 116:  aload_0
	OP_bc op117;                                                           // 117:  iconst_3
	OP_bc op118; OP__8 a118; OP__8 b118;                                   // 118:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
	OP_bc op121; OP_16 a121;                                               // 121:  sipush		150
	OP_bc op124;                                                           // 124:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op127;                                                           // 127:  aload_0
	OP_bc op128;                                                           // 128:  iconst_2
	OP_bc op129; OP__8 a129; OP__8 b129;                                   // 129:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
	OP_bc op132; OPtrg a132;                                               // 132:  goto		#183
	OP_bc op135;                                                           // 135:  aload_0
	OP_bc op136; OP__8 b136;                                               // 136:  bipush		32
	OP_bc op138;                                                           // 138:  aload_0
	OP_bc op139; OP_16 a139;                                               // 139:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op142;                                                           // 142:  ior
	OP_bc op143;                                                           // 143:  i2b
	OP_bc op144;                                                           // 144:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
	OP_bc op147; OP_16 a147;                                               // 147:  sipush		4500
	OP_bc op150;                                                           // 150:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op153;                                                           // 153:  aload_0
	OP_bc op154; OP__8 b154;                                               // 154:  bipush		32
	OP_bc op156;                                                           // 156:  aload_0
	OP_bc op157; OP_16 a157;                                               // 157:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op160;                                                           // 160:  ior
	OP_bc op161;                                                           // 161:  i2b
	OP_bc op162;                                                           // 162:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
	OP_bc op165; OP_16 a165;                                               // 165:  sipush		150
	OP_bc op168;                                                           // 168:  invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op171;                                                           // 171:  aload_0
	OP_bc op172; OP__8 b172;                                               // 172:  bipush		32
	OP_bc op174;                                                           // 174:  aload_0
	OP_bc op175; OP_16 a175;                                               // 175:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op178;                                                           // 178:  ior
	OP_bc op179;                                                           // 179:  i2b
	OP_bc op180;                                                           // 180:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
	OP_bc op183;                                                           // 183:  aload_0
	OP_bc op184; OP__8 b184;                                               // 184:  bipush		32
	OP_bc op186;                                                           // 186:  aload_0
	OP_bc op187; OP_16 a187;                                               // 187:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op190;                                                           // 190:  ior
	OP_bc op191;                                                           // 191:  i2b
	OP_bc op192;                                                           // 192:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
	OP_bc op195;                                                           // 195:  aload_0
	OP_bc op196;                                                           // 196:  iconst_4
	OP_bc op197; OP_16 a197;                                               // 197:  putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaycontrol B (17)
	OP_bc op200;                                                           // 200:  aload_0
	OP_bc op201; OP__8 a201; OP__8 b201;                                   // 201:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.display ()V (18)
	OP_bc op204;                                                           // 204:  aload_0
	OP_bc op205; OP__8 a205; OP__8 b205;                                   // 205:  invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.clear ()V (19)
	OP_bc op208;                                                           // 208:  aload_0
	OP_bc op209;                                                           // 209:  iconst_2
	OP_bc op210; OP_16 a210;                                               // 210:  putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaymode B (20)
	OP_bc op213;                                                           // 213:  aload_0
	OP_bc op214;                                                           // 214:  iconst_4
	OP_bc op215;                                                           // 215:  aload_0
	OP_bc op216; OP_16 a216;                                               // 216:  getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaymode B (20)
	OP_bc op219;                                                           // 219:  ior
	OP_bc op220;                                                           // 220:  i2b
	OP_bc op221;                                                           // 221:  invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
	OP_bc op224;                                                           // 224:  return
}            arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV_t arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    iload_1
	OP_bc op2;                                                             // 2:    iload_2
	OP_bc op3;                                                             // 3:    iconst_0
	OP_bc op4; OP__8 a4; OP__8 b4;                                         // 4:    invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.begin (BBB)V (9)
	OP_bc op7;                                                             // 7:    return
}            arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV_t arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    iconst_1
	OP_bc op2;                                                             // 2:    invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
	OP_bc op5; OP_16 a5;                                                   // 5:    sipush		2000
	OP_bc op8;                                                             // 8:    invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op11;                                                            // 11:   return
}            arduino_libraries_liquidcrystal_LiquidCrystal_clear_V_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_clear_V_t arduino_libraries_liquidcrystal_LiquidCrystal_clear_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iconst_4
	OP_bc op1; OP__8 b1;                                                   // 1:    newarray		<byte>
	OP_bc op3;                                                             // 3:    dup
	OP_bc op4;                                                             // 4:    iconst_0
	OP_bc op5;                                                             // 5:    iconst_0
	OP_bc op6;                                                             // 6:    bastore
	OP_bc op7;                                                             // 7:    dup
	OP_bc op8;                                                             // 8:    iconst_1
	OP_bc op9; OP__8 b9;                                                   // 9:    bipush		64
	OP_bc op11;                                                            // 11:   bastore
	OP_bc op12;                                                            // 12:   dup
	OP_bc op13;                                                            // 13:   iconst_2
	OP_bc op14; OP__8 b14;                                                 // 14:   bipush		20
	OP_bc op16;                                                            // 16:   bastore
	OP_bc op17;                                                            // 17:   dup
	OP_bc op18;                                                            // 18:   iconst_3
	OP_bc op19; OP__8 b19;                                                 // 19:   bipush		84
	OP_bc op21;                                                            // 21:   bastore
	OP_bc op22;                                                            // 22:   astore_3
	OP_bc op23;                                                            // 23:   iload_2
	OP_bc op24;                                                            // 24:   aload_0
	OP_bc op25; OP_16 a25;                                                 // 25:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._numlines B (10)
	OP_bc op28; OPtrg a28;                                                 // 28:   if_icmplt		#39
	OP_bc op31;                                                            // 31:   aload_0
	OP_bc op32; OP_16 a32;                                                 // 32:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._numlines B (10)
	OP_bc op35;                                                            // 35:   iconst_1
	OP_bc op36;                                                            // 36:   isub
	OP_bc op37;                                                            // 37:   i2b
	OP_bc op38;                                                            // 38:   istore_2
	OP_bc op39;                                                            // 39:   aload_0
	OP_bc op40; OP__8 b40;                                                 // 40:   bipush		-128
	OP_bc op42;                                                            // 42:   iload_1
	OP_bc op43;                                                            // 43:   aload_3
	OP_bc op44;                                                            // 44:   iload_2
	OP_bc op45;                                                            // 45:   baload
	OP_bc op46;                                                            // 46:   iadd
	OP_bc op47;                                                            // 47:   ior
	OP_bc op48;                                                            // 48:   i2b
	OP_bc op49;                                                            // 49:   invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
	OP_bc op52;                                                            // 52:   return
}            arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV_t arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    dup
	OP_bc op2; OP_16 a2;                                                   // 2:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaycontrol B (17)
	OP_bc op5;                                                             // 5:    iconst_4
	OP_bc op6;                                                             // 6:    ior
	OP_bc op7;                                                             // 7:    i2b
	OP_bc op8; OP_16 a8;                                                   // 8:    putfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaycontrol B (17)
	OP_bc op11;                                                            // 11:   aload_0
	OP_bc op12; OP__8 b12;                                                 // 12:   bipush		8
	OP_bc op14;                                                            // 14:   aload_0
	OP_bc op15; OP_16 a15;                                                 // 15:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displaycontrol B (17)
	OP_bc op18;                                                            // 18:   ior
	OP_bc op19;                                                            // 19:   i2b
	OP_bc op20;                                                            // 20:   invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.command (B)V (16)
	OP_bc op23;                                                            // 23:   return
}            arduino_libraries_liquidcrystal_LiquidCrystal_display_V_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_display_V_t arduino_libraries_liquidcrystal_LiquidCrystal_display_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    iload_1
	OP_bc op2;                                                             // 2:    iconst_0
	OP_bc op3;                                                             // 3:    invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.send (BB)V (22)
	OP_bc op6;                                                             // 6:    return
}            arduino_libraries_liquidcrystal_LiquidCrystal_command_BV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_command_BV_t arduino_libraries_liquidcrystal_LiquidCrystal_command_BV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    iload_1
	OP_bc op2;                                                             // 2:    iconst_1
	OP_bc op3;                                                             // 3:    invokespecial	arduino.libraries.liquidcrystal.LiquidCrystal.send (BB)V (22)
	OP_bc op6;                                                             // 6:    iconst_1
	OP_bc op7;                                                             // 7:    ireturn
}            arduino_libraries_liquidcrystal_LiquidCrystal_write_BB_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_write_BB_t arduino_libraries_liquidcrystal_LiquidCrystal_write_BB;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1; OP_16 a1;                                                   // 1:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rs_pin B (4)
	OP_bc op4;                                                             // 4:    iload_2
	OP_bc op5;                                                             // 5:    invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op8;                                                             // 8:    aload_0
	OP_bc op9; OP_16 a9;                                                   // 9:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
	OP_bc op12;                                                            // 12:   iconst_m1
	OP_bc op13; OPtrg a13;                                                 // 13:   if_icmpeq		#24
	OP_bc op16;                                                            // 16:   aload_0
	OP_bc op17; OP_16 a17;                                                 // 17:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._rw_pin B (5)
	OP_bc op20;                                                            // 20:   iconst_0
	OP_bc op21;                                                            // 21:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op24;                                                            // 24:   aload_0
	OP_bc op25; OP_16 a25;                                                 // 25:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._displayfunction B (8)
	OP_bc op28; OP__8 b28;                                                 // 28:   bipush		16
	OP_bc op30;                                                            // 30:   iand
	OP_bc op31; OPtrg a31;                                                 // 31:   ifeq		#42
	OP_bc op34;                                                            // 34:   aload_0
	OP_bc op35;                                                            // 35:   iload_1
	OP_bc op36; OP__8 a36; OP__8 b36;                                      // 36:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write8bits (B)V (23)
	OP_bc op39; OPtrg a39;                                                 // 39:   goto		#55
	OP_bc op42;                                                            // 42:   aload_0
	OP_bc op43;                                                            // 43:   iload_1
	OP_bc op44;                                                            // 44:   iconst_4
	OP_bc op45;                                                            // 45:   ishr
	OP_bc op46;                                                            // 46:   i2b
	OP_bc op47; OP__8 a47; OP__8 b47;                                      // 47:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
	OP_bc op50;                                                            // 50:   aload_0
	OP_bc op51;                                                            // 51:   iload_1
	OP_bc op52; OP__8 a52; OP__8 b52;                                      // 52:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.write4bits (B)V (15)
	OP_bc op55;                                                            // 55:   return
}            arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV_t arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1; OP_16 a1;                                                   // 1:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
	OP_bc op4;                                                             // 4:    iconst_0
	OP_bc op5;                                                             // 5:    invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op8;                                                             // 8:    iconst_1
	OP_bc op9;                                                             // 9:    invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op12;                                                            // 12:   aload_0
	OP_bc op13; OP_16 a13;                                                 // 13:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
	OP_bc op16;                                                            // 16:   iconst_1
	OP_bc op17;                                                            // 17:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op20;                                                            // 20:   iconst_1
	OP_bc op21;                                                            // 21:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op24;                                                            // 24:   aload_0
	OP_bc op25; OP_16 a25;                                                 // 25:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._enable_pin B (6)
	OP_bc op28;                                                            // 28:   iconst_0
	OP_bc op29;                                                            // 29:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op32; OP__8 b32;                                                 // 32:   bipush		100
	OP_bc op34;                                                            // 34:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.delayMicroseconds (I)V (13)
	OP_bc op37;                                                            // 37:   return
}            arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V_t arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iconst_0
	OP_bc op1;                                                             // 1:    istore_2
	OP_bc op2;                                                             // 2:    iload_2
	OP_bc op3;                                                             // 3:    iconst_4
	OP_bc op4; OPtrg a4;                                                   // 4:    if_icmpge		#38
	OP_bc op7;                                                             // 7:    aload_0
	OP_bc op8; OP_16 a8;                                                   // 8:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op11;                                                            // 11:   iload_2
	OP_bc op12;                                                            // 12:   baload
	OP_bc op13;                                                            // 13:   iconst_1
	OP_bc op14;                                                            // 14:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
	OP_bc op17;                                                            // 17:   aload_0
	OP_bc op18; OP_16 a18;                                                 // 18:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op21;                                                            // 21:   iload_2
	OP_bc op22;                                                            // 22:   baload
	OP_bc op23;                                                            // 23:   iload_1
	OP_bc op24;                                                            // 24:   iload_2
	OP_bc op25;                                                            // 25:   ishr
	OP_bc op26;                                                            // 26:   iconst_1
	OP_bc op27;                                                            // 27:   iand
	OP_bc op28;                                                            // 28:   i2b
	OP_bc op29;                                                            // 29:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op32; OP__8 a32;                                                 // 32:   iinc		%2	1
	OP_bc op35; OPtrg a35;                                                 // 35:   goto		#2
	OP_bc op38;                                                            // 38:   aload_0
	OP_bc op39; OP__8 a39; OP__8 b39;                                      // 39:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.pulseEnable ()V (24)
	OP_bc op42;                                                            // 42:   return
}            arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV_t arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iconst_0
	OP_bc op1;                                                             // 1:    istore_2
	OP_bc op2;                                                             // 2:    iload_2
	OP_bc op3; OP__8 b3;                                                   // 3:    bipush		8
	OP_bc op5; OPtrg a5;                                                   // 5:    if_icmpge		#39
	OP_bc op8;                                                             // 8:    aload_0
	OP_bc op9; OP_16 a9;                                                   // 9:    getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op12;                                                            // 12:   iload_2
	OP_bc op13;                                                            // 13:   baload
	OP_bc op14;                                                            // 14:   iconst_1
	OP_bc op15;                                                            // 15:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.pinMode (II)V (7)
	OP_bc op18;                                                            // 18:   aload_0
	OP_bc op19; OP_16 a19;                                                 // 19:   getfield		arduino.libraries.liquidcrystal.LiquidCrystal._data_pins [B (2)
	OP_bc op22;                                                            // 22:   iload_2
	OP_bc op23;                                                            // 23:   baload
	OP_bc op24;                                                            // 24:   iload_1
	OP_bc op25;                                                            // 25:   iload_2
	OP_bc op26;                                                            // 26:   ishr
	OP_bc op27;                                                            // 27:   iconst_1
	OP_bc op28;                                                            // 28:   iand
	OP_bc op29;                                                            // 29:   i2b
	OP_bc op30;                                                            // 30:   invokestatic	processing.hardware.arduino.cores.arduino.Arduino.digitalWrite (II)V (14)
	OP_bc op33; OP__8 a33;                                                 // 33:   iinc		%2	1
	OP_bc op36; OPtrg a36;                                                 // 36:   goto		#2
	OP_bc op39;                                                            // 39:   aload_0
	OP_bc op40; OP__8 a40; OP__8 b40;                                      // 40:   invokevirtual	arduino.libraries.liquidcrystal.LiquidCrystal.pulseEnable ()V (24)
	OP_bc op43;                                                            // 43:   return
}            arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV_t;
extern const arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV_t arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV;



#ifndef arduino_libraries_liquidcrystal_LiquidCrystal

typedef struct arduino_libraries_liquidcrystal_LiquidCrystal {
  jbyte _rs_pin;	//B
  jbyte _rw_pin;	//B
  jbyte _enable_pin;	//B
  jbyteArray _data_pins;	//[B
  jbyte _displayfunction;	//B
  jbyte _displaycontrol;	//B
  jbyte _displaymode;	//B
  jbyte _initialized;	//B
  jbyte _numlines;	//B
  jbyte _currline;	//B
} arduino_libraries_liquidcrystal_LiquidCrystal;
#define SIZEOF_arduino_libraries_liquidcrystal_LiquidCrystal sizeof(arduino_libraries_liquidcrystal_LiquidCrystal)


#endif
extern const class_t arduino_libraries_liquidcrystal_LiquidCrystal__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\Print.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    invokespecial	java.lang.Object.<init> ()V (1)
	OP_bc op4;                                                             // 4:    return
}            processing_hardware_arduino_cores_arduino_Print__init__V_t;
extern const processing_hardware_arduino_cores_arduino_Print__init__V_t processing_hardware_arduino_cores_arduino_Print__init__V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    iload_1
	OP_bc op2;                                                             // 2:    i2b
	OP_bc op3; OP__8 a3; OP__8 b3;                                         // 3:    invokevirtual	processing.hardware.arduino.cores.arduino.Print.write (B)B (4)
	OP_bc op6;                                                             // 6:    pop
	OP_bc op7;                                                             // 7:    return
}            processing_hardware_arduino_cores_arduino_Print_print_CV_t;
extern const processing_hardware_arduino_cores_arduino_Print_print_CV_t processing_hardware_arduino_cores_arduino_Print_print_CV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iconst_0
	OP_bc op1;                                                             // 1:    istore_2
	OP_bc op2;                                                             // 2:    iload_2
	OP_bc op3;                                                             // 3:    aload_1
	OP_bc op4; OP__8 a4; OP__8 b4;                                         // 4:    invokevirtual	java.lang.String.length ()I (7)
	OP_bc op7; OPtrg a7;                                                   // 7:    if_icmpge		#25
	OP_bc op10;                                                            // 10:   aload_0
	OP_bc op11;                                                            // 11:   aload_1
	OP_bc op12;                                                            // 12:   iload_2
	OP_bc op13; OP__8 a13; OP__8 b13;                                      // 13:   invokevirtual	java.lang.String.charAt (I)C (8)
	OP_bc op16; OP__8 a16; OP__8 b16;                                      // 16:   invokevirtual	processing.hardware.arduino.cores.arduino.Print.print (C)V (9)
	OP_bc op19; OP__8 a19;                                                 // 19:   iinc		%2	1
	OP_bc op22; OPtrg a22;                                                 // 22:   goto		#2
	OP_bc op25;                                                            // 25:   return
}            processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V_t;
extern const processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V_t processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    lload_1
	OP_bc op1;                                                             // 1:    lconst_0
	OP_bc op2;                                                             // 2:    lcmp
	OP_bc op3; OPtrg a3;                                                   // 3:    ifge		#15
	OP_bc op6;                                                             // 6:    aload_0
	OP_bc op7; OP__8 b7;                                                   // 7:    bipush		45
	OP_bc op9; OP__8 a9; OP__8 b9;                                         // 9:    invokevirtual	processing.hardware.arduino.cores.arduino.Print.print (C)V (9)
	OP_bc op12;                                                            // 12:   lload_1
	OP_bc op13;                                                            // 13:   lneg
	OP_bc op14;                                                            // 14:   lstore_1
	OP_bc op15;                                                            // 15:   aload_0
	OP_bc op16;                                                            // 16:   lload_1
	OP_bc op17; OP__8 b17;                                                 // 17:   bipush		10
	OP_bc op19;                                                            // 19:   invokespecial	processing.hardware.arduino.cores.arduino.Print.printNumber (JI)V (11)
	OP_bc op22;                                                            // 22:   return
}            processing_hardware_arduino_cores_arduino_Print_print_JV_t;
extern const processing_hardware_arduino_cores_arduino_Print_print_JV_t processing_hardware_arduino_cores_arduino_Print_print_JV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0; OP__8 b0;                                                   // 0:    bipush		32
	OP_bc op2; OP__8 b2;                                                   // 2:    newarray		<byte>
	OP_bc op4; OP__8 b4;                                                   // 4:    astore		%4
	OP_bc op6;                                                             // 6:    iconst_0
	OP_bc op7; OP__8 b7;                                                   // 7:    istore		%5
	OP_bc op9;                                                             // 9:    lload_1
	OP_bc op10;                                                            // 10:   lconst_0
	OP_bc op11;                                                            // 11:   lcmp
	OP_bc op12; OPtrg a12;                                                 // 12:   ifne		#22
	OP_bc op15;                                                            // 15:   aload_0
	OP_bc op16; OP__8 b16;                                                 // 16:   bipush		48
	OP_bc op18; OP__8 a18; OP__8 b18;                                      // 18:   invokevirtual	processing.hardware.arduino.cores.arduino.Print.print (C)V (9)
	OP_bc op21;                                                            // 21:   return
	OP_bc op22;                                                            // 22:   lload_1
	OP_bc op23;                                                            // 23:   lconst_0
	OP_bc op24;                                                            // 24:   lcmp
	OP_bc op25; OPtrg a25;                                                 // 25:   ifle		#50
	OP_bc op28; OP__8 b28;                                                 // 28:   aload		%4
	OP_bc op30; OP__8 b30;                                                 // 30:   iload		%5
	OP_bc op32; OP__8 a32;                                                 // 32:   iinc		%5	1
	OP_bc op35;                                                            // 35:   lload_1
	OP_bc op36;                                                            // 36:   iload_3
	OP_bc op37;                                                            // 37:   i2l
	OP_bc op38;                                                            // 38:   lrem
	OP_bc op39;                                                            // 39:   l2i
	OP_bc op40;                                                            // 40:   i2b
	OP_bc op41;                                                            // 41:   bastore
	OP_bc op42;                                                            // 42:   lload_1
	OP_bc op43;                                                            // 43:   iload_3
	OP_bc op44;                                                            // 44:   i2l
	OP_bc op45;                                                            // 45:   ldiv
	OP_bc op46;                                                            // 46:   lstore_1
	OP_bc op47; OPtrg a47;                                                 // 47:   goto		#22
	OP_bc op50; OP__8 b50;                                                 // 50:   iload		%5
	OP_bc op52; OPtrg a52;                                                 // 52:   ifle		#104
	OP_bc op55;                                                            // 55:   aload_0
	OP_bc op56; OP__8 b56;                                                 // 56:   aload		%4
	OP_bc op58; OP__8 b58;                                                 // 58:   iload		%5
	OP_bc op60;                                                            // 60:   iconst_1
	OP_bc op61;                                                            // 61:   isub
	OP_bc op62;                                                            // 62:   baload
	OP_bc op63; OP__8 b63;                                                 // 63:   bipush		10
	OP_bc op65; OPtrg a65;                                                 // 65:   if_icmpge		#81
	OP_bc op68; OP__8 b68;                                                 // 68:   bipush		48
	OP_bc op70; OP__8 b70;                                                 // 70:   aload		%4
	OP_bc op72; OP__8 b72;                                                 // 72:   iload		%5
	OP_bc op74;                                                            // 74:   iconst_1
	OP_bc op75;                                                            // 75:   isub
	OP_bc op76;                                                            // 76:   baload
	OP_bc op77;                                                            // 77:   iadd
	OP_bc op78; OPtrg a78;                                                 // 78:   goto		#94
	OP_bc op81; OP__8 b81;                                                 // 81:   bipush		65
	OP_bc op83; OP__8 b83;                                                 // 83:   aload		%4
	OP_bc op85; OP__8 b85;                                                 // 85:   iload		%5
	OP_bc op87;                                                            // 87:   iconst_1
	OP_bc op88;                                                            // 88:   isub
	OP_bc op89;                                                            // 89:   baload
	OP_bc op90;                                                            // 90:   iadd
	OP_bc op91; OP__8 b91;                                                 // 91:   bipush		10
	OP_bc op93;                                                            // 93:   isub
	OP_bc op94;                                                            // 94:   i2c
	OP_bc op95; OP__8 a95; OP__8 b95;                                      // 95:   invokevirtual	processing.hardware.arduino.cores.arduino.Print.print (C)V (9)
	OP_bc op98; OP__8 a98; OP__8 b98;                                      // 98:   iinc		%5	-1
	OP_bc op101; OPtrg a101;                                               // 101:  goto		#50
	OP_bc op104;                                                           // 104:  return
}            processing_hardware_arduino_cores_arduino_Print_printNumber_JIV_t;
extern const processing_hardware_arduino_cores_arduino_Print_printNumber_JIV_t processing_hardware_arduino_cores_arduino_Print_printNumber_JIV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iconst_0
	OP_bc op1; OPadr a1;                                                   // 1:    putstatic		processing.hardware.arduino.cores.arduino.Print.write_error I (2)
	OP_bc op4;                                                             // 4:    return
}            processing_hardware_arduino_cores_arduino_Print__clinit__V_t;
extern const processing_hardware_arduino_cores_arduino_Print__clinit__V_t processing_hardware_arduino_cores_arduino_Print__clinit__V;



#ifndef processing_hardware_arduino_cores_arduino_Print

#define SIZEOF_processing_hardware_arduino_cores_arduino_Print 0


#endif
extern const class_t processing_hardware_arduino_cores_arduino_Print__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\Arduino.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iload_0
	OP_bc op1;                                                             // 1:    i2b
	OP_bc op2;                                                             // 2:    iload_1
	OP_bc op3;                                                             // 3:    i2b
	OP_bc op4;                                                             // 4:    invokestatic	processing.hardware.arduino.cores.arduino.ArduinoImpl.pinMode (BB)V (16)
	OP_bc op7;                                                             // 7:    return
}            processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV_t;
extern const processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV_t processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iload_0
	OP_bc op1;                                                             // 1:    i2b
	OP_bc op2;                                                             // 2:    iload_1
	OP_bc op3;                                                             // 3:    i2b
	OP_bc op4;                                                             // 4:    invokestatic	processing.hardware.arduino.cores.arduino.ArduinoImpl.digitalWrite (BB)V (17)
	OP_bc op7;                                                             // 7:    return
}            processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV_t;
extern const processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV_t processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    invokestatic	processing.hardware.arduino.cores.arduino.ArduinoImpl.millis ()J (22)
	OP_bc op3;                                                             // 3:    lreturn
}            processing_hardware_arduino_cores_arduino_Arduino_millis_J_t;
extern const processing_hardware_arduino_cores_arduino_Arduino_millis_J_t processing_hardware_arduino_cores_arduino_Arduino_millis_J;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iload_0
	OP_bc op1;                                                             // 1:    invokestatic	processing.hardware.arduino.cores.arduino.ArduinoImpl.delayMicroseconds (I)V (25)
	OP_bc op4;                                                             // 4:    return
}            processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV_t;
extern const processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV_t processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0; OPadr f0;                                                   // 0:    new		<processing.hardware.arduino.cores.arduino.HardwareSerial> (41)
	OP_bc op3;                                                             // 3:    dup
	OP_bc op4;                                                             // 4:    invokespecial	processing.hardware.arduino.cores.arduino.HardwareSerial.<init> ()V (42)
	OP_bc op7; OPadr a7;                                                   // 7:    putstatic		processing.hardware.arduino.cores.arduino.Arduino.Serial Lprocessing/hardware/arduino/cores/arduino/HardwareSerial; (43)
	OP_bc op10;                                                            // 10:   return
}            processing_hardware_arduino_cores_arduino_Arduino__clinit__V_t;
extern const processing_hardware_arduino_cores_arduino_Arduino__clinit__V_t processing_hardware_arduino_cores_arduino_Arduino__clinit__V;



#ifndef processing_hardware_arduino_cores_arduino_Arduino

#define SIZEOF_processing_hardware_arduino_cores_arduino_Arduino 0


#endif
extern const class_t processing_hardware_arduino_cores_arduino_Arduino__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\HardwareSerial.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    invokespecial	processing.hardware.arduino.cores.arduino.Stream.<init> ()V (1)
	OP_bc op4;                                                             // 4:    aload_0
	OP_bc op5;                                                             // 5:    iconst_m1
	OP_bc op6; OP_16 a6;                                                   // 6:    putfield		processing.hardware.arduino.cores.arduino.HardwareSerial.lastChar I (2)
	OP_bc op9;                                                             // 9:    return
}            processing_hardware_arduino_cores_arduino_HardwareSerial__init__V_t;
extern const processing_hardware_arduino_cores_arduino_HardwareSerial__init__V_t processing_hardware_arduino_cores_arduino_HardwareSerial__init__V;

typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    iload_1
	OP_bc op1;                                                             // 1:    invokestatic	processing.hardware.arduino.cores.arduino.HardwareSerialImpl.write (B)B (6)
	OP_bc op4;                                                             // 4:    ireturn
}            processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB_t;
extern const processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB_t processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB;



#ifndef processing_hardware_arduino_cores_arduino_HardwareSerial

typedef struct processing_hardware_arduino_cores_arduino_HardwareSerial {
  jlong _timeout;	//J
  jlong _startMillis;	//J
  jint PARSE_TIMEOUT_jfPARSE_TIMEOUT;	//I
  jchar NO_SKIP_CHAR_jfNO_SKIP_CHAR;	//C
  jint lastChar;	//I
} processing_hardware_arduino_cores_arduino_HardwareSerial;
#define SIZEOF_processing_hardware_arduino_cores_arduino_HardwareSerial sizeof(processing_hardware_arduino_cores_arduino_HardwareSerial)


#endif
extern const class_t processing_hardware_arduino_cores_arduino_HardwareSerial__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\Stream.h
//
typedef struct {
	uint8_t max_stack; int8_t purLocals; uint8_t purParams;

	OP_bc op0;                                                             // 0:    aload_0
	OP_bc op1;                                                             // 1:    invokespecial	processing.hardware.arduino.cores.arduino.Print.<init> ()V (1)
	OP_bc op4;                                                             // 4:    aload_0
	OP_bc op5; OP_16 a5;                                                   // 5:    sipush		1000
	OP_bc op8; OP_16 a8;                                                   // 8:    putfield		processing.hardware.arduino.cores.arduino.Stream.PARSE_TIMEOUT I (2)
	OP_bc op11;                                                            // 11:   aload_0
	OP_bc op12;                                                            // 12:   iconst_1
	OP_bc op13; OP_16 a13;                                                 // 13:   putfield		processing.hardware.arduino.cores.arduino.Stream.NO_SKIP_CHAR C (3)
	OP_bc op16;                                                            // 16:   return
}            processing_hardware_arduino_cores_arduino_Stream__init__V_t;
extern const processing_hardware_arduino_cores_arduino_Stream__init__V_t processing_hardware_arduino_cores_arduino_Stream__init__V;



#ifndef processing_hardware_arduino_cores_arduino_Stream

typedef struct processing_hardware_arduino_cores_arduino_Stream {
  jlong _timeout;	//J
  jlong _startMillis;	//J
  jint PARSE_TIMEOUT_jfPARSE_TIMEOUT;	//I
  jchar NO_SKIP_CHAR_jfNO_SKIP_CHAR;	//C
} processing_hardware_arduino_cores_arduino_Stream;
#define SIZEOF_processing_hardware_arduino_cores_arduino_Stream sizeof(processing_hardware_arduino_cores_arduino_Stream)


#endif
extern const class_t processing_hardware_arduino_cores_arduino_Stream__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\HardwareSerialImpl.h
//
#ifndef native_processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB
extern const NativCode processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB;
extern void            native_processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB(void);
#endif



#ifndef processing_hardware_arduino_cores_arduino_HardwareSerialImpl

#define SIZEOF_processing_hardware_arduino_cores_arduino_HardwareSerialImpl 0


#endif
extern const class_t processing_hardware_arduino_cores_arduino_HardwareSerialImpl__class;


//////////////////////////////////////////////////
// D:\Users\cdn\workspace\myCProject\.\HaikuVM\utility\processing\hardware\arduino\cores\arduino\ArduinoImpl.h
//
#ifndef native_processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV
extern const NativCode processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV;
extern void            native_processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV(void);
#endif

#ifndef native_processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV
extern const NativCode processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV;
extern void            native_processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV(void);
#endif

#ifndef native_processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J
extern const NativCode processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J;
extern void            native_processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J(void);
#endif

#ifndef native_processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV
extern const NativCode processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV;
extern void            native_processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV(void);
#endif



#ifndef processing_hardware_arduino_cores_arduino_ArduinoImpl

#define SIZEOF_processing_hardware_arduino_cores_arduino_ArduinoImpl 0


#endif
extern const class_t processing_hardware_arduino_cores_arduino_ArduinoImpl__class;


