package arduino.libraries.dfr0009;

import haiku.vm.NativeCFunction;

import java.util.ArrayList;
import static arduino.libraries.dfr0009.KeyEvent.*;

import static processing.hardware.arduino.cores.arduino.Arduino.*;
/**
 * This class offers support for the 5 button keypad of a DFRobots KeyPad Shield
 * (SKU: DFR0009). It will generate KeyEvent:
 * VK_ENTER for select
 * VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN for cursor keys
 * VK_UNDEFINED for none or undefined key
 * 
 * @see http://www.dfrobot.com/wiki/index.php?title=Arduino_LCD_KeyPad_Shield_(SKU:_DFR0009)#Example_use_of_LiquidCrystal_library
 * @author Carl van Denzen
 * 
 */
public class Keypad {

    
	public Keypad(int analogPin) {
		// Initialize values for buttons
		/*
		analogToButtonMap.put(0,VK_RIGHT);
		analogToButtonMap.put(144,VK_UP);
		analogToButtonMap.put(329,VK_DOWN);
		analogToButtonMap.put(504,VK_LEFT);
		analogToButtonMap.put(741,VK_ENTER);
		*/
		
		analogToButtonMap.clear();
		analogToButtonMap.add(0); // VK_RIGHT
		analogToButtonMap.add(144); // ,VK_UP);
		analogToButtonMap.add(329); //,VK_DOWN);
		analogToButtonMap.add(504); //,VK_LEFT);
		analogToButtonMap.add(741); //,VK_ENTER);

		
		this.analogPin=analogPin;
		// Start the polling thread that reads the analog value periodically

	}
	/**
	 * This thread polls the analog input that is connected to the buttons
	 */
	Thread pollAnalogButtons=new Thread() {
		public void run() {
			int previousKey=VK_UNDEFINED; // remember previous value
			for (;;) {
				// do forever
				int pressedKey=readKeyPadButtons();

				// fire key pressed / released event if necessary

				if (pressedKey!=previousKey) {
					//KeyEvent(Keyboard source, int id, long when, int modifiers, int keyCode, char keyChar, int location)
					if (previousKey!=VK_UNDEFINED) {
						// key was released
						KeyEvent event=new KeyEvent(Keypad.this, KEY_RELEASED, 1L /*WHEN*/, previousKey);
						for (KeyListener l:eventListenersList) {
							l.keyReleased(event);
						}
					}
					if (pressedKey!=VK_UNDEFINED) {
						KeyEvent event=new KeyEvent(Keypad.this, KEY_PRESSED, 1L /*WHEN*/,pressedKey);
						for (KeyListener l:eventListenersList) {
							l.keyPressed(event);
						}
					}
				}
				try {
					Thread.sleep(10); // sleep 10 ms
				}
				catch (InterruptedException ex) {
					// do nothing
				}
			}
		}
		
		private int readKeyPadButtons() {

			int adcKeyIn = analogRead(analogPin);      // read the value from the sensor 
			// my buttons when read are centered at these values: 0, 144, 329, 504, 741
			// we add approx 50 to those values and check to see if we are close
			final int threshold=50;

			if (adcKeyIn>analogToButtonMap.get(4)+threshold) {
				return VK_UNDEFINED;
			}
			for (int i=0;i<Math.min(analogToButtonMap.size(), buttonArray.length);i++) {
				if (adcKeyIn<analogToButtonMap.get(i)+threshold) {
					return buttonArray[i];
				}
			}
			// Nothing found, return the last choice
			return buttonArray[buttonArray.length-1];
			/*
			if (adcKeyIn > 1000) return VK_UNDEFINED; // We make this the 1st option for speed reasons since it will be the most likely result
			// For V1.1 us this threshold
			if (adcKeyIn < 50)   return VK_RIGHT;  
			if (adcKeyIn < 250)  return VK_UP; 
			if (adcKeyIn < 450)  return VK_DOWN; 
			if (adcKeyIn < 650)  return VK_LEFT; 
			if (adcKeyIn < 850)  return VK_ENTER;
			 */
		}
	};

	public void addKeyEventListener(KeyListener l) {
		eventListenersList.add(l);
	}
	public void removeKeyEventListener(KeyListener l) {
		eventListenersList.remove(l);
	}

	public static void main() {
		// for compilation in Eclipse
	}
	final private ArrayList<KeyListener> eventListenersList=new ArrayList<KeyListener>();
	//final private java.util.Hashtable<Integer,Integer> analogToButtonMap=new java.util.Hashtable<Integer,Integer>();
	final private java.util.ArrayList<Integer> analogToButtonMap=new java.util.ArrayList<Integer>();
	//final private java.util.ArrayList<Integer> buttonArray=new ArrayList<Integer>();
	final private static int[] buttonArray={VK_RIGHT,VK_UP,VK_DOWN,VK_LEFT,VK_ENTER};

	private int analogPin;
}