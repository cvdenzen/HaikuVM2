package nl.vandenzen.arduino.lcdtest1;

//import javax.bluetooth.BluetoothStateException;

import javax.bluetooth.BluetoothStateException;

//import lejos.addon.keyboard.KeyEvent;
//import lejos.addon.keyboard.KeyListener;
//import lejos.addon.keyboard.Keyboard;
import arduino.libraries.dfr0009.Keypad;
import arduino.libraries.dfr0009.KeyEvent;
import arduino.libraries.dfr0009.KeyListener;
import arduino.libraries.liquidcrystal.LiquidCrystal;
import static processing.hardware.arduino.cores.arduino.Arduino.*;

public class LcdTest {

	//package arduino.libraries.liquidcrystal;

	/*
	      LiquidCrystal Library - Hello World

	     Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
	     library works with all LCD displays that are compatible with the 
	     Hitachi HD44780 driver. There are many of them out there, and you
	     can usually tell them by the 16-pin interface.

	     This sketch prints "Hello World!" to the LCD
	     and shows the time.

	      The circuit:
	 * LCD RS pin to digital pin 12
	 * LCD Enable pin to digital pin 11
	 * LCD D4 pin to digital pin 5
	 * LCD D5 pin to digital pin 4
	 * LCD D6 pin to digital pin 3
	 * LCD D7 pin to digital pin 2
	 * LCD R/W pin to ground
	 * 10K resistor:
	 * ends to +5V and ground
	 * wiper to LCD VO pin (pin 3)

	     Library originally added 18 Apr 2008
	     by David A. Mellis
	     library modified 5 Jul 2009
	     by Limor Fried (http://www.ladyada.net)
	     example added 9 Jul 2009
	     by Tom Igoe
	     modified 22 Nov 2010
	     by Tom Igoe

	     This example code is in the public domain.

	     http://www.arduino.cc/en/Tutorial/LiquidCrystal
	 */


	// initialize the library with the numbers of the interface pins
	//LiquidCrystal lcd=new LiquidCrystal((byte)12, (byte)11, (byte)5, (byte)4, (byte)3, (byte)2);
	// DFRobot shield
	static LiquidCrystal lcd=new LiquidCrystal((byte)8,(byte)9,(byte)4,(byte)5,(byte)6,(byte)7);


	public static void setup() {
		// set up the LCD's number of columns and rows: 
		
		lcd.begin((byte)16, (byte)2);
		// Print a message to the LCD.
		lcd.print("hello, world KL!");

		keypad=new Keypad(1);
		keypad.addKeyEventListener(new KeyListener() {

			@Override
			public void keyTyped(KeyEvent arg0) {
				// TODO Auto-generated method stub

			}

			@Override
			public void keyReleased(KeyEvent evt) {
				// TODO Auto-generated method stub

				byte col,row;
				col=0;row=1;
				lcd.print("    ");
			}

			@Override
			public void keyPressed(KeyEvent evt) {
				// TODO Auto-generated method stub

				byte col,row;
				col=0;row=1;
				lcd.print("    ");
				lcd.print(evt.getKeyCode());

			}
		});
	}

	public static void loop() {
		// set the cursor to column 0, line 1
		// (note: line 1 is the second row, since counting begins with 0):
		lcd.setCursor((byte)0, (byte)1);
		// print the number of seconds since reset:
		//lcd.print(millis()/1000);

		// testje:
		debugValue=analogRead(A0);
		lcd.print(debugValue++);
	}
	private static Keypad keypad;
	private static int debugValue=0; // is displayed at line 2 of the lcd display
	public static void main(String[] args) {

	}
}
