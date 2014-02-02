package haikuvm.pc.tools;
import haikuvm.pc.tools.haikuc.HaikuDefs;

import java.net.URL;
import java.util.Formatter;
import java.util.logging.Logger;

/**
 * A Member identifies a method, field uniquely
 * @author CDN
 *
 */
public class Member implements Comparable {
	private String owner;
	private String name;
	private String descriptor;
	private URL url;
	private int access=-1;
	private String signature;
	private String[] exceptions;
	/**
	 * @param owner The internal class name of the class in which this member is declared.
	 * Internal class name is the class name with dots replaced by slashes.
	 * @param access The access flags (native, public, etc.). See Opcodes.ACC_xxxxx.
	 * @param descriptor
	 * The descriptor for this member (its parameters and/or (return) type)
	 * For fields e.g.:
	 * I (for integer type)
	 * C (for character type)
	 * For methods e.g.:
	 * (Llejos/addon/keyboard/Keyboard;IJIICI)V
	 * @param name The name of the member
	 * @param url The URL from which this member has been loaded
	 */
	public Member(int access, String owner, String name, String descriptor,
			String signature, String[] exceptions,URL url) {
		// TODO Auto-generated constructor stub
		super();
		this.access=access;
		this.owner=owner;
		this.name=name;
		this.descriptor = descriptor;
		this.signature=signature;
		this.exceptions=exceptions;
		this.url=url;
		if (owner.contains(".")) {
			String message="owner class name should not contain . character:"+this;
			logger.severe(message);
			throw new IllegalArgumentException(message);
		}
	}
	public Member(String owner, int access, String name, String descriptor, URL url) {
		this(access,owner,name,descriptor,null,null,url);
	}
	public Member(int access,String owner,String name,String desc,String signature,String[] exceptions) {
		this(access,owner,name,desc,signature,exceptions,null);
	}
	/**
	 * @param owner The internal class name of the class in which this member is declared.
	 * Internal class name is the class name with dots replaced by slashes.
	 * @param name The name of the member
	 * @param descriptor
	 * The descriptor for this member (its parameters and/or (return) type)
	 * For fields e.g.:
	 * I (for integer type)
	 * C (for character type)
	 * For methods e.g.:
	 * (Llejos/addon/keyboard/Keyboard;IJIICI)V
	 * @param url The URL from which this member has been loaded
	 */
	public Member(String owner, String name, String descriptor, URL url) {
		this(owner,-1,name,descriptor,url);
	}

	/**
	 * Create a new member with a null url
	 * @param owner
	 * @param descriptor
	 * @param name
	 */
	public Member(String owner, String name, String descriptor) {
		this(owner, name, descriptor, null);
	}
	/**
	 * Create a new member with a null url
	 * @param owner
	 * @param descriptor
	 * @param name
	 */
	public Member(String internalClassname, int access, String name,
			String desc) {
		this(internalClassname,access,name,desc,null);
	}
	/**
	 * Create a Member for a Class (no method or field name defined)
	 * @param name The name of the class in internal class format.
	 */
	public Member(String name) {
		this(name,"","");
	}
	public int getAccess() {
		return access;
	}
	public String getDescriptor() {
		return descriptor;
	}

	public void setDescriptor(String descriptor) {
		this.descriptor = descriptor;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getOwner() {
		return owner;
	}

	public void setOwner(String owner) {
		this.owner = owner;
	}
	/**
	 * @return true if the member is a field (and not a method)
	 */
	public boolean isField() {
		return !descriptor.startsWith("(");
	}

	/**
	 * @return the url
	 */
	public URL getUrl() {
		return url;
	}

	/**
	 * @param url the url to set
	 */
	public void setUrl(URL url) {
		this.url = url;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result
				+ ((descriptor == null) ? 0 : descriptor.hashCode());
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		result = prime * result + ((owner == null) ? 0 : owner.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof Member))
			return false;
		Member other = (Member) obj;
		if (descriptor == null) {
			if (other.descriptor != null)
				return false;
		} else if (!descriptor.equals(other.descriptor))
			return false;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		if (owner == null) {
			if (other.owner != null)
				return false;
		} else if (!owner.equals(other.owner))
			return false;
		return true;
	}

	public String toString() {
		StringBuilder sb=new StringBuilder();
		sb.append("[Member owner=").append(owner)
		.append(",name=").append(name)
		.append(",descriptor=").append(descriptor);
		// Print the url, but not including the fully qualified class name, because we already
		// have that (owner).
		if (url!=null) {
			sb.append(",url=").append(url.getPath().replaceAll(owner+"$",""));
		}
		sb.append("]");
		return sb.toString();
	}

	@Override
	public int compareTo(Object other) {
		Member otherMember;
		if (other instanceof Member) {
			otherMember=(Member) other;
		} else {
			return 1; // other was other type, other is smaller....
		}
		if ((owner!=null) && (owner.compareTo(otherMember.owner)==0)) {
			// same class
			if ((descriptor!=null) && (descriptor.compareTo(otherMember.descriptor)==0)) {
				return name==null?0:name.compareTo(otherMember.name);
			} else {
				// descriptors are different.
				// fields are smaller then methods in sorting them
				return isField()?
						(otherMember.isField()?0:-1)
						:name.compareTo(otherMember.name);
			}
		} else {
			// other class, order by name of class
			return owner.compareTo(otherMember.owner);
		}
	}
	/**
	 * Give a C name for the class name of this member:
	 * nl.vandenzen.dfr9000.Keypad -> nl_vandenzen_dfr9000_Keypad__class
	 * @return
	 */
	public String getMangledClassName() {
		return owner.replace('/', '_')+"__class";
	}
	/**
	 * Give a C name for the name of this member:
	 * nl.vandenzen.dfr9000.Keypad.read() -> nl_vandenzen_dfr9000_Keypad__class_jread__V
	 * If it is the name of the starting class (the microkernel) main method, return a special value.
	 * For haiku VM Magic it also does something special.
	 * It adds a lowercase letter j before the member name to avoid clashes with C declarations (?)
	 * @return
	 */
	public String getMangledName() {
		return getMangledClassName()+("_j"+name+descriptor).replaceAll("[)(.$<>;]","_");
	}

	private static Logger logger=Logger.getLogger("haikuvm.pc.tools");
	/**
	 * Convert the internal class name into an external class name:
	 * nl/vandenzen/arduino/lcdtest1/LcdTest -> nl.vandenzen.arduino.lcdtest1.LcdTest
	 * @return
	 */
	public String getClassName() {
		return owner.replace('/','.');
	}
} // end of Member inner class
