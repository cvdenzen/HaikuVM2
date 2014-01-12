#include <jni.h>
#include <math.h>
#include <string.h>

/////////////////////////////////////////////////


#ifndef pinMode
extern "C" void pinMode(char, char);
#endif

/*
 * Class:     processing.hardware.arduino.cores.arduino.ArduinoImpl
 * Method:    pinMode
 * Signature: (BB)V
 */
JNIEXPORT void Java_processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode
  (JNIEnv *env, jclass obj, jbyte arg1, jbyte arg2)
{
    pinMode(arg1, arg2);
}

/*
 * Proprietary HaikuVM stack to JNI interface function.
 * DO NOT EDIT THIS FUNCTION – it is machine generated.
 * 
 * Class:     processing.hardware.arduino.cores.arduino.ArduinoImpl
 * Method:    pinMode
 * Signature: (BB)V
 */
JNIEXPORT void native_processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode_BBV(void) {
    pushTop();    // Save variable top onto stack.
    {
        jbyte    arg2 = pop()->b;
        jbyte    arg1 = pop()->b;
        jclass     obj = NULL;
        JNIEnv     *env = NULL; // not used in HaikuVM
        Java_processing_hardware_arduino_cores_arduino_ArduinoImpl_pinMode(env, obj, arg1, arg2);
    }
    popTop();
}

/////////////////////////////////////////////////


#ifndef digitalWrite
extern "C" void digitalWrite(char, char);
#endif

/*
 * Class:     processing.hardware.arduino.cores.arduino.ArduinoImpl
 * Method:    digitalWrite
 * Signature: (BB)V
 */
JNIEXPORT void Java_processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite
  (JNIEnv *env, jclass obj, jbyte arg1, jbyte arg2)
{
    digitalWrite(arg1, arg2);
}

/*
 * Proprietary HaikuVM stack to JNI interface function.
 * DO NOT EDIT THIS FUNCTION – it is machine generated.
 * 
 * Class:     processing.hardware.arduino.cores.arduino.ArduinoImpl
 * Method:    digitalWrite
 * Signature: (BB)V
 */
JNIEXPORT void native_processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite_BBV(void) {
    pushTop();    // Save variable top onto stack.
    {
        jbyte    arg2 = pop()->b;
        jbyte    arg1 = pop()->b;
        jclass     obj = NULL;
        JNIEnv     *env = NULL; // not used in HaikuVM
        Java_processing_hardware_arduino_cores_arduino_ArduinoImpl_digitalWrite(env, obj, arg1, arg2);
    }
    popTop();
}

/////////////////////////////////////////////////


#ifndef millis
extern "C" long millis();
#endif

/*
 * Class:     processing.hardware.arduino.cores.arduino.ArduinoImpl
 * Method:    millis
 * Signature: ()J
 */
JNIEXPORT jlong Java_processing_hardware_arduino_cores_arduino_ArduinoImpl_millis
  (JNIEnv *env, jclass obj)
{
    return millis();
}

/*
 * Proprietary HaikuVM stack to JNI interface function.
 * DO NOT EDIT THIS FUNCTION – it is machine generated.
 * 
 * Class:     processing.hardware.arduino.cores.arduino.ArduinoImpl
 * Method:    millis
 * Signature: ()J
 */
JNIEXPORT void native_processing_hardware_arduino_cores_arduino_ArduinoImpl_millis_J(void) {
    pushTop();    // Save variable top onto stack.
    {
        jclass     obj = NULL;
        JNIEnv     *env = NULL; // not used in HaikuVM
        top.j = Java_processing_hardware_arduino_cores_arduino_ArduinoImpl_millis(env, obj);
    }
    // Variable top holds the return value. But we have to push the lower half.
    pushTop0();
}

/////////////////////////////////////////////////


#ifndef delayMicroseconds
extern "C" void delayMicroseconds(int);
#endif

/*
 * Class:     processing.hardware.arduino.cores.arduino.ArduinoImpl
 * Method:    delayMicroseconds
 * Signature: (I)V
 */
JNIEXPORT void Java_processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds
  (JNIEnv *env, jclass obj, jint arg1)
{
    delayMicroseconds(arg1);
}

/*
 * Proprietary HaikuVM stack to JNI interface function.
 * DO NOT EDIT THIS FUNCTION – it is machine generated.
 * 
 * Class:     processing.hardware.arduino.cores.arduino.ArduinoImpl
 * Method:    delayMicroseconds
 * Signature: (I)V
 */
JNIEXPORT void native_processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds_IV(void) {
    pushTop();    // Save variable top onto stack.
    {
        jint    arg1 = pop()->i;
        jclass     obj = NULL;
        JNIEnv     *env = NULL; // not used in HaikuVM
        Java_processing_hardware_arduino_cores_arduino_ArduinoImpl_delayMicroseconds(env, obj, arg1);
    }
    popTop();
}

/////////////////////////////////////////////////


