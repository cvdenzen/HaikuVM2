package arduino.libraries.dfr0009;
/**
 * A very simple Listener, specific for dfr0009 keypad (only 5 keys...)
 * The listener interface for receiving keyboard events (keystrokes).
 * The class that is interested in processing a keyboard event implements this interface
 *  (and all the methods it contains).
 * The listener object created from that class is then registered with a component using
 * the component's addKeyListener method.
 * A keyboard event is generated when a key is pressed or released.
 * The relevant method in the listener object is then invoked, and the KeyEvent is passed to it.
 * @author CDN
 *
 */
interface KeyListener {
	void keyTyped(KeyEvent e);
	void keyPressed(KeyEvent e);
	void keyReleased(KeyEvent e);
}
