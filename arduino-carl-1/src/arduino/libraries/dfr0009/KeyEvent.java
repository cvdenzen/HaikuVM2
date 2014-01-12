package arduino.libraries.dfr0009;

//import lejos.addon.keyboard.KeyEvent;
/**
 * A very simple implementation of java.awt.KeyEvent, just enough for the drf0009 keypad with 5 buttons.
 * 
 * @author Carl van Denzen
 *
 */
public class KeyEvent {
	/**
	 * 
	 * @param source The Keypad that originated the event
	 * @param id An integer indicating the type of event.
	 *   KEY_PRESSED
	 *   KEY_TYPED (is only generated if a valid Unicode character could be generated. That will never happen in dfr0009!)
	 *   KEY_RELEASED
	 * @param when A long integer that specifies the time the event occurred. Passing negative or zero value is not recommended
	 * @param keyCode The integer code for an actual key, or VK_UNDEFINED (for a key-typed event). See VK_xxxx in this class.
	 */
	public KeyEvent(Keypad source,int id,long when,int keyCode) {

	}

	/**
	 * @return the source
	 */
	public Keypad getSource() {
		return source;
	}
	/**
	 * @param source the source to set
	 */
	public void setSource(Keypad source) {
		this.source = source;
	}
	/**
	 * @return the keyCode
	 */
	public int getKeyCode() {
		return keyCode;
	}
	/**
	 * @param keyCode the keyCode to set
	 */
	public void setKeyCode(int keyCode) {
		this.keyCode = keyCode;
	}
	/**
	 * @return the id
	 */
	public int getID() {
		return id;
	}
	/**
	 * @return the when
	 */
	public long getWhen() {
		return when;
	}

	private Keypad source;
	private int id;
	private long when;
	private int keyCode;
	public static final int KEY_PRESSED=401;
	public static final int KEY_RELEASED=402;
	public static final int KEY_TYPED=400; // never used

	public static final int VK_LEFT=37;
	public static final int VK_RIGHT=39;
	public static final int VK_UP=38;
	public static final int VK_DOWN=40;
	public static final int VK_ENTER=10;
	public static final int VK_UNDEFINED=0;


}
