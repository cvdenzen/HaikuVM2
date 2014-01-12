#include "haikuConfig.h"

#include <float.h>



#if DEBUG_DISPATCHER
// bytecodes: 128

const BytecodeFoo bytecodeFoo[] PROGMEM = {
	OPF_INVOKESHORT,               //   0 processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV
	OPF_INVOKESHORT,               //   1 processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV
	OPF_INVOKESHORT,               //   2 arduino_libraries_liquidcrystal_LiquidCrystal_command_BV
	OPF_INVOKESHORT,               //   3 processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV
	OPF_INVOKESHORT,               //   4 java_lang_Object__init__V
	OPF_INVOKESHORT,               //   5 processing_hardware_arduino_cores_arduino_Print__init__V
	OPF_INVOKESHORT,               //   6 arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV
	OPF_INVOKESHORT,               //   7 arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V
	OPF_INVOKESHORT,               //   8 arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V
	OPF_INVOKESHORT,               //   9 haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V
	OPF_INVOKESHORT,               //  10 arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV
	OPF_INVOKESHORT,               //  11 java_lang_Throwable__init__Ljava_lang_String_V
	OPF_INVOKESHORT,               //  12 java_lang_Thread_setStateAndSwitch_II
	OPF_INVOKESHORT,               //  13 java_lang_OutOfMemoryError__init__Ljava_lang_String_V
	OPF_INVOKESHORT,               //  14 java_lang_Error__init__Ljava_lang_String_V
	OPF_INVOKESHORT,               //  15 java_lang_Thread_currentThread_Ljava_lang_Thread
	OPF_INVOKESHORT,               //  16 haiku_vm_MicroKernel_clinitHaikuMagic_V
	OPF_INVOKESHORT,               //  17 processing_hardware_arduino_cores_arduino_Stream__init__V
	OPF_INVOKESHORT,               //  18 arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV
	OPF_INVOKESHORT,               //  19 processing_hardware_arduino_cores_arduino_Arduino_millis_J
	OPF_INVOKESHORT,               //  20 processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J
	OPF_INVOKESHORT,               //  21 processing_hardware_arduino_cores_arduino_HardwareSerial__init__V
	OPF_INVOKESHORT,               //  22 processing_hardware_arduino_cores_arduino_Print_printNumber_JIV
	OPF_INVOKESHORT,               //  23 processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV
	OPF_INVOKESHORT,               //  24 processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV
	OPF_INVOKESHORT,               //  25 processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV
	OPF_INVOKESHORT,               //  26 processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB
	OPF_INVOKESHORT,               //  27 arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV
	OPF_INVOKESHORT,               //  28 arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV
	OPF_INVOKESHORT,               //  29 processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB
	OPF_INVOKESHORT,               //  30 arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV
	OPF_INVOKESHORT,               //  31 processing_hardware_arduino_cores_arduino_Print_print_CV
	OPF_INVOKESHORT,               //  32 processing_hardware_arduino_cores_arduino_Arduino__clinit__V
	OPF_INVOKESHORT,               //  33 arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV
	OPF_INVOKESHORT,               //  34 main_YLjava_lang_String
	OPF_INVOKESHORT,               //  35 arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV
	OPF_INVOKESHORT,               //  36 arduino_libraries_liquidcrystal_LiquidCrystal_clear_V
	OPF_INVOKESHORT,               //  37 java_lang_String_charAt_IC
	OPF_INVOKESHORT,               //  38 haiku_vm_MicroKernel__clinit__V
	OPF_INVOKESHORT,               //  39 processing_hardware_arduino_cores_arduino_Print__clinit__V
	OPF_INVOKESHORT,               //  40 java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable
	OPF_INVOKESHORT,               //  41 arduino_libraries_liquidcrystal_LiquidCrystal_write_BB
	OPF_INVOKESHORT,               //  42 arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V
	OPF_INVOKESHORT,               //  43 arduino_libraries_liquidcrystal_LiquidCrystal_display_V
	OPF_INVOKESHORT,               //  44 arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V
	OPF_INVOKESHORT,               //  45 java_lang_Thread_stop_V
	OPF_INVOKESHORT,               //  46 processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V
	OPF_INVOKESHORT,               //  47 java_lang_String_length_I
	OPF_INVOKESHORT,               //  48 processing_hardware_arduino_cores_arduino_Print_print_JV
	OPF_ALOAD_0,                   //  49 ALOAD_1
	OPF_IFEQ,                      //  50 IFEQ
	OPF_ALOAD_0,                   //  51 ALOAD_3
	OPF_IF_ICMPEQ,                 //  52 IF_ICMPLT
	OPF_IFEQ,                      //  53 IFNE
	OPF_IFEQ,                      //  54 IFLE
	OPF_LDC2_W_L,                  //  55 LDC2_W_L
	OPF_ALOAD_0,                   //  56 ALOAD_0
	OPF_ASTORE_0,                  //  57 ASTORE_1
	OPF_IF_ACMPEQ,                 //  58 IF_ACMPEQ
	OPF_ASTORE_0,                  //  59 ASTORE_3
	OPF_ALOAD,                     //  60 ALOAD
	OPF_IF_ICMPEQ,                 //  61 IF_ICMPNE
	OPF_IF_ICMPEQ,                 //  62 IF_ICMPLE
	OPF_ARETURN,                   //  63 ARETURN
	OPF_LCONST_0,                  //  64 LCONST_0
	OPF_LLOAD_0,                   //  65 LLOAD_1
	OPF_IF_ICMPEQ,                 //  66 IF_ICMPEQ
	OPF_IFEQ,                      //  67 IFGE
	OPF_ARRAYLENGTH,               //  68 ARRAYLENGTH
	OPF_LDC_S,                     //  69 LDC_S
	OPF_LDC_S,                     //  70 LDC_I
	OPF_ASTORE,                    //  71 ASTORE
	OPF_BALOAD,                    //  72 BALOAD
	OPF_LSTORE_0,                  //  73 LSTORE_1
	OPF_FSTORE_0,                  //  74 ISTORE_2
	OPF_IF_ICMPEQ,                 //  75 IF_ICMPGE
	OPF_BASTORE,                   //  76 BASTORE
	OPF_BIPUSH,                    //  77 BIPUSH
	OPF_CALOAD,                    //  78 CALOAD
	OPF_DUP,                       //  79 DUP
	OPF_GETFIELD_B,                //  80 GETFIELD_B
	OPF_GETFIELD_I,                //  81 GETFIELD_I
	OPF_GETFIELD_L,                //  82 GETFIELD_L
	OPF_GETSTATIC_L,               //  83 GETSTATIC_L
	OPF_GOTO,                      //  84 GOTO
	OPF_I2B,                       //  85 I2B
	OPF_I2C,                       //  86 I2C
	OPF_I2L,                       //  87 I2L
	OPF_IADD,                      //  88 IADD
	OPF_IAND,                      //  89 IAND
	OPF_ICONST_0,                  //  90 ICONST_0
	OPF_ICONST_1,                  //  91 ICONST_1
	OPF_ICONST_2,                  //  92 ICONST_2
	OPF_ICONST_3,                  //  93 ICONST_3
	OPF_ICONST_4,                  //  94 ICONST_4
	OPF_ICONST_5,                  //  95 ICONST_5
	OPF_ICONST_M1,                 //  96 ICONST_M1
	OPF_IINC,                      //  97 IINC
	OPF_IINC1,                     //  98 IINC1
	OPF_ILOAD,                     //  99 ILOAD
	OPF_ILOAD_0,                   // 100 ILOAD_0
	OPF_ILOAD_1,                   // 101 ILOAD_1
	OPF_ILOAD_2,                   // 102 ILOAD_2
	OPF_ILOAD_3,                   // 103 ILOAD_3
	OPF_INVOKESPECIAL,             // 104 INVOKESTATIC
	OPF_INVOKEVIRTUAL,             // 105 INVOKEVIRTUAL
	OPF_IOR,                       // 106 IOR
	OPF_ARETURN,                   // 107 IRETURN
	OPF_ISHR,                      // 108 ISHR
	OPF_FSTORE,                    // 109 ISTORE
	OPF_ISUB,                      // 110 ISUB
	OPF_L2I,                       // 111 L2I
	OPF_LCMP,                      // 112 LCMP
	OPF_LDIV,                      // 113 LDIV
	OPF_LNEG,                      // 114 LNEG
	OPF_LREM,                      // 115 LREM
	OPF_DRETURN,                   // 116 LRETURN
	OPF_NEW,                       // 117 NEW
	OPF_ANEWARRAY,                 // 118 NEWARRAY
	OPF_POP,                       // 119 POP
	OPF_PUTFIELD_B,                // 120 PUTFIELD_B
	OPF_PUTFIELD_C,                // 121 PUTFIELD_C
	OPF_PUTFIELD_I,                // 122 PUTFIELD_I
	OPF_PUTFIELD_L,                // 123 PUTFIELD_L
	OPF_PUTSTATIC_I,               // 124 PUTSTATIC_I
	OPF_PUTSTATIC_L,               // 125 PUTSTATIC_L
	OPF_RETURN,                    // 126 RETURN
	OPF_SIPUSH,                    // 127 SIPUSH
};
#endif

#if _DEBUG
char bytecodeDesc000[] PROGMEM ="processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV";
char bytecodeDesc001[] PROGMEM ="processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV";
char bytecodeDesc002[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_command_BV";
char bytecodeDesc003[] PROGMEM ="processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV";
char bytecodeDesc004[] PROGMEM ="java_lang_Object__init__V";
char bytecodeDesc005[] PROGMEM ="processing_hardware_arduino_cores_arduino_Print__init__V";
char bytecodeDesc006[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV";
char bytecodeDesc007[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V";
char bytecodeDesc008[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V";
char bytecodeDesc009[] PROGMEM ="haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V";
char bytecodeDesc010[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV";
char bytecodeDesc011[] PROGMEM ="java_lang_Throwable__init__Ljava_lang_String_V";
char bytecodeDesc012[] PROGMEM ="java_lang_Thread_setStateAndSwitch_II";
char bytecodeDesc013[] PROGMEM ="java_lang_OutOfMemoryError__init__Ljava_lang_String_V";
char bytecodeDesc014[] PROGMEM ="java_lang_Error__init__Ljava_lang_String_V";
char bytecodeDesc015[] PROGMEM ="java_lang_Thread_currentThread_Ljava_lang_Thread";
char bytecodeDesc016[] PROGMEM ="haiku_vm_MicroKernel_clinitHaikuMagic_V";
char bytecodeDesc017[] PROGMEM ="processing_hardware_arduino_cores_arduino_Stream__init__V";
char bytecodeDesc018[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV";
char bytecodeDesc019[] PROGMEM ="processing_hardware_arduino_cores_arduino_Arduino_millis_J";
char bytecodeDesc020[] PROGMEM ="processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J";
char bytecodeDesc021[] PROGMEM ="processing_hardware_arduino_cores_arduino_HardwareSerial__init__V";
char bytecodeDesc022[] PROGMEM ="processing_hardware_arduino_cores_arduino_Print_printNumber_JIV";
char bytecodeDesc023[] PROGMEM ="processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV";
char bytecodeDesc024[] PROGMEM ="processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV";
char bytecodeDesc025[] PROGMEM ="processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV";
char bytecodeDesc026[] PROGMEM ="processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB";
char bytecodeDesc027[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV";
char bytecodeDesc028[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV";
char bytecodeDesc029[] PROGMEM ="processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB";
char bytecodeDesc030[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV";
char bytecodeDesc031[] PROGMEM ="processing_hardware_arduino_cores_arduino_Print_print_CV";
char bytecodeDesc032[] PROGMEM ="processing_hardware_arduino_cores_arduino_Arduino__clinit__V";
char bytecodeDesc033[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV";
char bytecodeDesc034[] PROGMEM ="main_YLjava_lang_String";
char bytecodeDesc035[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV";
char bytecodeDesc036[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_clear_V";
char bytecodeDesc037[] PROGMEM ="java_lang_String_charAt_IC";
char bytecodeDesc038[] PROGMEM ="haiku_vm_MicroKernel__clinit__V";
char bytecodeDesc039[] PROGMEM ="processing_hardware_arduino_cores_arduino_Print__clinit__V";
char bytecodeDesc040[] PROGMEM ="java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable";
char bytecodeDesc041[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_write_BB";
char bytecodeDesc042[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V";
char bytecodeDesc043[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_display_V";
char bytecodeDesc044[] PROGMEM ="arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V";
char bytecodeDesc045[] PROGMEM ="java_lang_Thread_stop_V";
char bytecodeDesc046[] PROGMEM ="processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V";
char bytecodeDesc047[] PROGMEM ="java_lang_String_length_I";
char bytecodeDesc048[] PROGMEM ="processing_hardware_arduino_cores_arduino_Print_print_JV";
char bytecodeDesc049[] PROGMEM ="ALOAD_1";
char bytecodeDesc050[] PROGMEM ="IFEQ";
char bytecodeDesc051[] PROGMEM ="ALOAD_3";
char bytecodeDesc052[] PROGMEM ="IF_ICMPLT";
char bytecodeDesc053[] PROGMEM ="IFNE";
char bytecodeDesc054[] PROGMEM ="IFLE";
char bytecodeDesc055[] PROGMEM ="LDC2_W_L";
char bytecodeDesc056[] PROGMEM ="ALOAD_0";
char bytecodeDesc057[] PROGMEM ="ASTORE_1";
char bytecodeDesc058[] PROGMEM ="IF_ACMPEQ";
char bytecodeDesc059[] PROGMEM ="ASTORE_3";
char bytecodeDesc060[] PROGMEM ="ALOAD";
char bytecodeDesc061[] PROGMEM ="IF_ICMPNE";
char bytecodeDesc062[] PROGMEM ="IF_ICMPLE";
char bytecodeDesc063[] PROGMEM ="ARETURN";
char bytecodeDesc064[] PROGMEM ="LCONST_0";
char bytecodeDesc065[] PROGMEM ="LLOAD_1";
char bytecodeDesc066[] PROGMEM ="IF_ICMPEQ";
char bytecodeDesc067[] PROGMEM ="IFGE";
char bytecodeDesc068[] PROGMEM ="ARRAYLENGTH";
char bytecodeDesc069[] PROGMEM ="LDC_S";
char bytecodeDesc070[] PROGMEM ="LDC_I";
char bytecodeDesc071[] PROGMEM ="ASTORE";
char bytecodeDesc072[] PROGMEM ="BALOAD";
char bytecodeDesc073[] PROGMEM ="LSTORE_1";
char bytecodeDesc074[] PROGMEM ="ISTORE_2";
char bytecodeDesc075[] PROGMEM ="IF_ICMPGE";
char bytecodeDesc076[] PROGMEM ="BASTORE";
char bytecodeDesc077[] PROGMEM ="BIPUSH";
char bytecodeDesc078[] PROGMEM ="CALOAD";
char bytecodeDesc079[] PROGMEM ="DUP";
char bytecodeDesc080[] PROGMEM ="GETFIELD_B";
char bytecodeDesc081[] PROGMEM ="GETFIELD_I";
char bytecodeDesc082[] PROGMEM ="GETFIELD_L";
char bytecodeDesc083[] PROGMEM ="GETSTATIC_L";
char bytecodeDesc084[] PROGMEM ="GOTO";
char bytecodeDesc085[] PROGMEM ="I2B";
char bytecodeDesc086[] PROGMEM ="I2C";
char bytecodeDesc087[] PROGMEM ="I2L";
char bytecodeDesc088[] PROGMEM ="IADD";
char bytecodeDesc089[] PROGMEM ="IAND";
char bytecodeDesc090[] PROGMEM ="ICONST_0";
char bytecodeDesc091[] PROGMEM ="ICONST_1";
char bytecodeDesc092[] PROGMEM ="ICONST_2";
char bytecodeDesc093[] PROGMEM ="ICONST_3";
char bytecodeDesc094[] PROGMEM ="ICONST_4";
char bytecodeDesc095[] PROGMEM ="ICONST_5";
char bytecodeDesc096[] PROGMEM ="ICONST_M1";
char bytecodeDesc097[] PROGMEM ="IINC";
char bytecodeDesc098[] PROGMEM ="IINC1";
char bytecodeDesc099[] PROGMEM ="ILOAD";
char bytecodeDesc100[] PROGMEM ="ILOAD_0";
char bytecodeDesc101[] PROGMEM ="ILOAD_1";
char bytecodeDesc102[] PROGMEM ="ILOAD_2";
char bytecodeDesc103[] PROGMEM ="ILOAD_3";
char bytecodeDesc104[] PROGMEM ="INVOKESTATIC";
char bytecodeDesc105[] PROGMEM ="INVOKEVIRTUAL";
char bytecodeDesc106[] PROGMEM ="IOR";
char bytecodeDesc107[] PROGMEM ="IRETURN";
char bytecodeDesc108[] PROGMEM ="ISHR";
char bytecodeDesc109[] PROGMEM ="ISTORE";
char bytecodeDesc110[] PROGMEM ="ISUB";
char bytecodeDesc111[] PROGMEM ="L2I";
char bytecodeDesc112[] PROGMEM ="LCMP";
char bytecodeDesc113[] PROGMEM ="LDIV";
char bytecodeDesc114[] PROGMEM ="LNEG";
char bytecodeDesc115[] PROGMEM ="LREM";
char bytecodeDesc116[] PROGMEM ="LRETURN";
char bytecodeDesc117[] PROGMEM ="NEW";
char bytecodeDesc118[] PROGMEM ="NEWARRAY";
char bytecodeDesc119[] PROGMEM ="POP";
char bytecodeDesc120[] PROGMEM ="PUTFIELD_B";
char bytecodeDesc121[] PROGMEM ="PUTFIELD_C";
char bytecodeDesc122[] PROGMEM ="PUTFIELD_I";
char bytecodeDesc123[] PROGMEM ="PUTFIELD_L";
char bytecodeDesc124[] PROGMEM ="PUTSTATIC_I";
char bytecodeDesc125[] PROGMEM ="PUTSTATIC_L";
char bytecodeDesc126[] PROGMEM ="RETURN";
char bytecodeDesc127[] PROGMEM ="SIPUSH";
char bytecodeDesc999[] PROGMEM ="unused";

const char* bytecodeDesc[] PROGMEM = {
	bytecodeDesc000,
	bytecodeDesc001,
	bytecodeDesc002,
	bytecodeDesc003,
	bytecodeDesc004,
	bytecodeDesc005,
	bytecodeDesc006,
	bytecodeDesc007,
	bytecodeDesc008,
	bytecodeDesc009,
	bytecodeDesc010,
	bytecodeDesc011,
	bytecodeDesc012,
	bytecodeDesc013,
	bytecodeDesc014,
	bytecodeDesc015,
	bytecodeDesc016,
	bytecodeDesc017,
	bytecodeDesc018,
	bytecodeDesc019,
	bytecodeDesc020,
	bytecodeDesc021,
	bytecodeDesc022,
	bytecodeDesc023,
	bytecodeDesc024,
	bytecodeDesc025,
	bytecodeDesc026,
	bytecodeDesc027,
	bytecodeDesc028,
	bytecodeDesc029,
	bytecodeDesc030,
	bytecodeDesc031,
	bytecodeDesc032,
	bytecodeDesc033,
	bytecodeDesc034,
	bytecodeDesc035,
	bytecodeDesc036,
	bytecodeDesc037,
	bytecodeDesc038,
	bytecodeDesc039,
	bytecodeDesc040,
	bytecodeDesc041,
	bytecodeDesc042,
	bytecodeDesc043,
	bytecodeDesc044,
	bytecodeDesc045,
	bytecodeDesc046,
	bytecodeDesc047,
	bytecodeDesc048,
	bytecodeDesc049,
	bytecodeDesc050,
	bytecodeDesc051,
	bytecodeDesc052,
	bytecodeDesc053,
	bytecodeDesc054,
	bytecodeDesc055,
	bytecodeDesc056,
	bytecodeDesc057,
	bytecodeDesc058,
	bytecodeDesc059,
	bytecodeDesc060,
	bytecodeDesc061,
	bytecodeDesc062,
	bytecodeDesc063,
	bytecodeDesc064,
	bytecodeDesc065,
	bytecodeDesc066,
	bytecodeDesc067,
	bytecodeDesc068,
	bytecodeDesc069,
	bytecodeDesc070,
	bytecodeDesc071,
	bytecodeDesc072,
	bytecodeDesc073,
	bytecodeDesc074,
	bytecodeDesc075,
	bytecodeDesc076,
	bytecodeDesc077,
	bytecodeDesc078,
	bytecodeDesc079,
	bytecodeDesc080,
	bytecodeDesc081,
	bytecodeDesc082,
	bytecodeDesc083,
	bytecodeDesc084,
	bytecodeDesc085,
	bytecodeDesc086,
	bytecodeDesc087,
	bytecodeDesc088,
	bytecodeDesc089,
	bytecodeDesc090,
	bytecodeDesc091,
	bytecodeDesc092,
	bytecodeDesc093,
	bytecodeDesc094,
	bytecodeDesc095,
	bytecodeDesc096,
	bytecodeDesc097,
	bytecodeDesc098,
	bytecodeDesc099,
	bytecodeDesc100,
	bytecodeDesc101,
	bytecodeDesc102,
	bytecodeDesc103,
	bytecodeDesc104,
	bytecodeDesc105,
	bytecodeDesc106,
	bytecodeDesc107,
	bytecodeDesc108,
	bytecodeDesc109,
	bytecodeDesc110,
	bytecodeDesc111,
	bytecodeDesc112,
	bytecodeDesc113,
	bytecodeDesc114,
	bytecodeDesc115,
	bytecodeDesc116,
	bytecodeDesc117,
	bytecodeDesc118,
	bytecodeDesc119,
	bytecodeDesc120,
	bytecodeDesc121,
	bytecodeDesc122,
	bytecodeDesc123,
	bytecodeDesc124,
	bytecodeDesc125,
	bytecodeDesc126,
	bytecodeDesc127,
	bytecodeDesc999,//128
	bytecodeDesc999,//129
	bytecodeDesc999,//130
	bytecodeDesc999,//131
	bytecodeDesc999,//132
	bytecodeDesc999,//133
	bytecodeDesc999,//134
	bytecodeDesc999,//135
	bytecodeDesc999,//136
	bytecodeDesc999,//137
	bytecodeDesc999,//138
	bytecodeDesc999,//139
	bytecodeDesc999,//140
	bytecodeDesc999,//141
	bytecodeDesc999,//142
	bytecodeDesc999,//143
	bytecodeDesc999,//144
	bytecodeDesc999,//145
	bytecodeDesc999,//146
	bytecodeDesc999,//147
	bytecodeDesc999,//148
	bytecodeDesc999,//149
	bytecodeDesc999,//150
	bytecodeDesc999,//151
	bytecodeDesc999,//152
	bytecodeDesc999,//153
	bytecodeDesc999,//154
	bytecodeDesc999,//155
	bytecodeDesc999,//156
	bytecodeDesc999,//157
	bytecodeDesc999,//158
	bytecodeDesc999,//159
	bytecodeDesc999,//160
	bytecodeDesc999,//161
	bytecodeDesc999,//162
	bytecodeDesc999,//163
	bytecodeDesc999,//164
	bytecodeDesc999,//165
	bytecodeDesc999,//166
	bytecodeDesc999,//167
	bytecodeDesc999,//168
	bytecodeDesc999,//169
	bytecodeDesc999,//170
	bytecodeDesc999,//171
	bytecodeDesc999,//172
	bytecodeDesc999,//173
	bytecodeDesc999,//174
	bytecodeDesc999,//175
	bytecodeDesc999,//176
	bytecodeDesc999,//177
	bytecodeDesc999,//178
	bytecodeDesc999,//179
	bytecodeDesc999,//180
	bytecodeDesc999,//181
	bytecodeDesc999,//182
	bytecodeDesc999,//183
	bytecodeDesc999,//184
	bytecodeDesc999,//185
	bytecodeDesc999,//186
	bytecodeDesc999,//187
	bytecodeDesc999,//188
	bytecodeDesc999,//189
	bytecodeDesc999,//190
	bytecodeDesc999,//191
	bytecodeDesc999,//192
	bytecodeDesc999,//193
	bytecodeDesc999,//194
	bytecodeDesc999,//195
	bytecodeDesc999,//196
	bytecodeDesc999,//197
	bytecodeDesc999,//198
	bytecodeDesc999,//199
	bytecodeDesc999,//200
	bytecodeDesc999,//201
	bytecodeDesc999,//202
	bytecodeDesc999,//203
	bytecodeDesc999,//204
	bytecodeDesc999,//205
	bytecodeDesc999,//206
	bytecodeDesc999,//207
	bytecodeDesc999,//208
	bytecodeDesc999,//209
	bytecodeDesc999,//210
	bytecodeDesc999,//211
	bytecodeDesc999,//212
	bytecodeDesc999,//213
	bytecodeDesc999,//214
	bytecodeDesc999,//215
	bytecodeDesc999,//216
	bytecodeDesc999,//217
	bytecodeDesc999,//218
	bytecodeDesc999,//219
	bytecodeDesc999,//220
	bytecodeDesc999,//221
	bytecodeDesc999,//222
	bytecodeDesc999,//223
	bytecodeDesc999,//224
	bytecodeDesc999,//225
	bytecodeDesc999,//226
	bytecodeDesc999,//227
	bytecodeDesc999,//228
	bytecodeDesc999,//229
	bytecodeDesc999,//230
	bytecodeDesc999,//231
	bytecodeDesc999,//232
	bytecodeDesc999,//233
	bytecodeDesc999,//234
	bytecodeDesc999,//235
	bytecodeDesc999,//236
	bytecodeDesc999,//237
	bytecodeDesc999,//238
	bytecodeDesc999,//239
	bytecodeDesc999,//240
	bytecodeDesc999,//241
	bytecodeDesc999,//242
	bytecodeDesc999,//243
	bytecodeDesc999,//244
	bytecodeDesc999,//245
	bytecodeDesc999,//246
	bytecodeDesc999,//247
	bytecodeDesc999,//248
	bytecodeDesc999,//249
	bytecodeDesc999,//250
	bytecodeDesc999,//251
	bytecodeDesc999,//252
	bytecodeDesc999,//253
	bytecodeDesc999,//254
	bytecodeDesc999,//255
};
#endif


#include "haikuJava.h"


const ldc_jstring_t	Const0000 PROGMEM =  {16,	{'O','u','t','O','f','M','e','m','o','r','y','E','r','r','o','r'}};
const ldc_jstring_t	Const0001 PROGMEM =  {15,	{'h','e','l','l','o',',',' ','w','o','r','l','d',' ','A','!'}};
const ldc_jlong_t	Const0002 PROGMEM =  {LONG_CNSTR(500L)}; //0x00000000000001f4L
const ldc_jint_t	Const0003 PROGMEM =  {INT_CNSTR(50000)}; //0x0000c350


statics_t allStatics;
//jobject:
//	0	arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_lcd; gets=4 puts=1 native=0
//	1	haiku_vm_MicroKernel_outOfMemoryError; gets=0 puts=1 native=0
//	2	java_lang_Thread_currentThread; gets=2 puts=1 native=0
//	3	processing_hardware_arduino_cores_arduino_Arduino_Serial; gets=0 puts=1 native=0
//jbyte:
//jchar:
//jdouble:
//jfloat:
//jint:
//	0	arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_teller; gets=0 puts=1 native=0
//	1	processing_hardware_arduino_cores_arduino_Print_write_error; gets=0 puts=1 native=0
//jlong:
//jshort:
//jboolean:



const Exception_t	exceptionTable[] PROGMEM = {
	{&main_YLjava_lang_String.op0, &main_YLjava_lang_String.op18, &main_YLjava_lang_String.op18, &java_lang_Throwable__class},
	{NULL, NULL, NULL, NULL}
};

#if _DEBUG || NO_MICRO
const char *	functionDesc[] PROGMEM = {
	/*   0   48 */ "processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV",
	/*   1   48 */ "processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV",
	/*   2   41 */ "arduino_libraries_liquidcrystal_LiquidCrystal_command_BV",
	/*   3   26 */ "processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV",
	/*   4   12 */ "java_lang_Object__init__V",
	/*   5   11 */ "processing_hardware_arduino_cores_arduino_Print__init__V",
	/*   6    9 */ "arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV",
	/*   7    7 */ "arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V",
	/*   8    7 */ "arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V",
	/*   9    7 */ "haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V",
	/*  10    7 */ "arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV",
	/*  11    7 */ "java_lang_Throwable__init__Ljava_lang_String_V",
	/*  12    7 */ "java_lang_Thread_setStateAndSwitch_II",
	/*  13    7 */ "java_lang_OutOfMemoryError__init__Ljava_lang_String_V",
	/*  14    7 */ "java_lang_Error__init__Ljava_lang_String_V",
	/*  15    7 */ "java_lang_Thread_currentThread_Ljava_lang_Thread",
	/*  16    7 */ "haiku_vm_MicroKernel_clinitHaikuMagic_V",
	/*  17    6 */ "processing_hardware_arduino_cores_arduino_Stream__init__V",
	/*  18    6 */ "arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV",
	/*  19    6 */ "processing_hardware_arduino_cores_arduino_Arduino_millis_J",
	/*  20    6 */ "processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J",
	/*  21    6 */ "processing_hardware_arduino_cores_arduino_HardwareSerial__init__V",
	/*  22    6 */ "processing_hardware_arduino_cores_arduino_Print_printNumber_JIV",
	/*  23    5 */ "processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV",
	/*  24    5 */ "processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV",
	/*  25    5 */ "processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV",
	/*  26    5 */ "processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB",
	/*  27    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV",
	/*  28    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV",
	/*  29    1 */ "processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB",
	/*  30    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV",
	/*  31    1 */ "processing_hardware_arduino_cores_arduino_Print_print_CV",
	/*  32    1 */ "processing_hardware_arduino_cores_arduino_Arduino__clinit__V",
	/*  33    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV",
	/*  34    1 */ "main_YLjava_lang_String",
	/*  35    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV",
	/*  36    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_clear_V",
	/*  37    1 */ "java_lang_String_charAt_IC",
	/*  38    1 */ "haiku_vm_MicroKernel__clinit__V",
	/*  39    1 */ "processing_hardware_arduino_cores_arduino_Print__clinit__V",
	/*  40    1 */ "java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable",
	/*  41    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_write_BB",
	/*  42    1 */ "arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V",
	/*  43    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_display_V",
	/*  44    1 */ "arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V",
	/*  45    1 */ "java_lang_Thread_stop_V",
	/*  46    1 */ "processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V",
	/*  47    1 */ "java_lang_String_length_I",
	/*  48    1 */ "processing_hardware_arduino_cores_arduino_Print_print_JV",
};
#endif

//Needed for Exception unwinding
const ByteCode *	functionTable[] PROGMEM = {
	/*   0   48 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Arduino_delayMicroseconds_IV,
	/*   1   48 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Arduino_digitalWrite_IIV,
	/*   2   41 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_command_BV,
	/*   3   26 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Arduino_pinMode_IIV,
	/*   4   12 */ (ByteCode *)&java_lang_Object__init__V,
	/*   5   11 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Print__init__V,
	/*   6    9 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_send_BBV,
	/*   7    7 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_setup_V,
	/*   8    7 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld_loop_V,
	/*   9    7 */ (ByteCode *)&haiku_avr_lib_arduino_HaikuMicroKernelProcessing_init_V,
	/*  10    7 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal__init__BBBBBBV,
	/*  11    7 */ (ByteCode *)&java_lang_Throwable__init__Ljava_lang_String_V,
	/*  12    7 */ (ByteCode *)&java_lang_Thread_setStateAndSwitch_II,
	/*  13    7 */ (ByteCode *)&java_lang_OutOfMemoryError__init__Ljava_lang_String_V,
	/*  14    7 */ (ByteCode *)&java_lang_Error__init__Ljava_lang_String_V,
	/*  15    7 */ (ByteCode *)&java_lang_Thread_currentThread_Ljava_lang_Thread,
	/*  16    7 */ (ByteCode *)&haiku_vm_MicroKernel_clinitHaikuMagic_V,
	/*  17    6 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Stream__init__V,
	/*  18    6 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_init_BBBBBBBBBBBBV,
	/*  19    6 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Arduino_millis_J,
	/*  20    6 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J,
	/*  21    6 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_HardwareSerial__init__V,
	/*  22    6 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Print_printNumber_JIV,
	/*  23    5 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV,
	/*  24    5 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV,
	/*  25    5 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV,
	/*  26    5 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_HardwareSerialImpl_write_BB,
	/*  27    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_write8bits_BV,
	/*  28    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_write4bits_BV,
	/*  29    1 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_HardwareSerial_write_BB,
	/*  30    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_setCursor_BBV,
	/*  31    1 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Print_print_CV,
	/*  32    1 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Arduino__clinit__V,
	/*  33    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBBV,
	/*  34    1 */ (ByteCode *)&main_YLjava_lang_String,
	/*  35    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_begin_BBV,
	/*  36    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_clear_V,
	/*  37    1 */ (ByteCode *)&java_lang_String_charAt_IC,
	/*  38    1 */ (ByteCode *)&haiku_vm_MicroKernel__clinit__V,
	/*  39    1 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Print__clinit__V,
	/*  40    1 */ (ByteCode *)&java_lang_Throwable_fillInStackTrace_Ljava_lang_Throwable,
	/*  41    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_write_BB,
	/*  42    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__clinit__V,
	/*  43    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_display_V,
	/*  44    1 */ (ByteCode *)&arduino_libraries_liquidcrystal_LiquidCrystal_pulseEnable_V,
	/*  45    1 */ (ByteCode *)&java_lang_Thread_stop_V,
	/*  46    1 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Print_print_Ljava_lang_String_V,
	/*  47    1 */ (ByteCode *)&java_lang_String_length_I,
	/*  48    1 */ (ByteCode *)&processing_hardware_arduino_cores_arduino_Print_print_JV,
	NULL};

#if _DEBUG || NO_MICRO

char classDesc000[] PROGMEM ="free block";
char classDesc001[] PROGMEM ="arduino.libraries.liquidcrystal.LiquidCrystal";
char classDesc002[] PROGMEM ="arduino.libraries.liquidcrystal.LiquidCrystalHelloWorld";
char classDesc003[] PROGMEM ="haiku.avr.lib.arduino.HaikuMicroKernelProcessing";
char classDesc004[] PROGMEM ="haiku.vm.MicroKernel";
char classDesc005[] PROGMEM ="java.lang.Error";
char classDesc006[] PROGMEM ="java.lang.Object";
char classDesc007[] PROGMEM ="java.lang.OutOfMemoryError";
char classDesc008[] PROGMEM ="java.lang.String";
char classDesc009[] PROGMEM ="java.lang.Thread";
char classDesc010[] PROGMEM ="java.lang.Throwable";
char classDesc011[] PROGMEM ="processing.hardware.arduino.cores.arduino.Arduino";
char classDesc012[] PROGMEM ="processing.hardware.arduino.cores.arduino.ArduinoImpl";
char classDesc013[] PROGMEM ="processing.hardware.arduino.cores.arduino.HardwareSerial";
char classDesc014[] PROGMEM ="processing.hardware.arduino.cores.arduino.HardwareSerialImpl";
char classDesc015[] PROGMEM ="processing.hardware.arduino.cores.arduino.Print";
char classDesc016[] PROGMEM ="processing.hardware.arduino.cores.arduino.Stream";

const char *	classDesc[] PROGMEM = {
	classDesc001,
	classDesc002,
	classDesc003,
	classDesc004,
	classDesc005,
	classDesc006,
	classDesc007,
	classDesc008,
	classDesc009,
	classDesc010,
	classDesc011,
	classDesc012,
	classDesc013,
	classDesc014,
	classDesc015,
	classDesc016,
	classDesc000,
};

//Needed for Heap and Stack debugging
const jclass    classTable[] PROGMEM = {
	(jclass)&arduino_libraries_liquidcrystal_LiquidCrystal__class,
	(jclass)&arduino_libraries_liquidcrystal_LiquidCrystalHelloWorld__class,
	(jclass)&haiku_avr_lib_arduino_HaikuMicroKernelProcessing__class,
	(jclass)&haiku_vm_MicroKernel__class,
	(jclass)&java_lang_Error__class,
	(jclass)&java_lang_Object__class,
	(jclass)&java_lang_OutOfMemoryError__class,
	(jclass)&java_lang_String__class,
	(jclass)&java_lang_Thread__class,
	(jclass)&java_lang_Throwable__class,
	(jclass)&processing_hardware_arduino_cores_arduino_Arduino__class,
	(jclass)&processing_hardware_arduino_cores_arduino_ArduinoImpl__class,
	(jclass)&processing_hardware_arduino_cores_arduino_HardwareSerial__class,
	(jclass)&processing_hardware_arduino_cores_arduino_HardwareSerialImpl__class,
	(jclass)&processing_hardware_arduino_cores_arduino_Print__class,
	(jclass)&processing_hardware_arduino_cores_arduino_Stream__class,
	NULL
};
#endif
