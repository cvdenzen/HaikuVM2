package haiku.avr.lib.asuro.lib2_8_0_rc1;

import haiku.vm.HaikuMagic;

import java.lang.String;
import java.lang.Thread;
import java.lang.Throwable;


/**
 * Skeleton for Haiku VM organizing the start of the target program.
 * 
 * @author genom2
 *
 */
public class HaikuMicroKernel extends haiku.vm.MicroKernel {
	
	public static void main(String[] args) {
		try {
		    clinitHaikuMagic();		
			
			/**
			 * The following call of throwException()
			 * and therefor the method body throwException() 
			 * will be extingted from code if property Target.InternalExceptionThrow is set to 0
			 * .. --Config:InternalExceptionThrow=0 ..
			 */
			throwException();
			
			HaikuMagic.main(args); // Will call your main method (by some HaikuVM magic)
			
		} catch (Throwable e) {
			// All Exceptions will end up at least here
		}
		Thread.currentThread().stop();
	}
}
