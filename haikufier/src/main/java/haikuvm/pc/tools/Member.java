package haikuvm.pc.tools;
import haikuvm.pc.tools.haikuc.HaikuDefs;

import java.net.URL;
import java.util.Formatter;
import java.util.logging.Logger;

import org.objectweb.asm.Type;

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
<<<<<<< HEAD
	private int useCount=0; // the number of times this member is used in the target code
	private int invokeShortIndex=-1; // positive value means this member (method) has been chosen for shortInvoke
=======
>>>>>>> e4ab4eaaf49ec68b28bc26d2f3ce3900f11cf47f
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
	public Member(Member m) {
		this(m.access,m.owner,m.name,m.descriptor,m.signature,m.exceptions,m.url);
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

	/**
	 * This customEquals method is a more relaxed version of a standard equals method.
	 * Strings that are null are considedered the same as empty Strings.
	 * I did not put this code in the default equals(Object) method, because that one is
	 * very likely to be overwritten by any enthousiastic IDE (NetBeans, Eclipse, ...)
	 * @param obj
	 * @return
	 */
	private boolean customEquals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof Member))
			return false;
		Member other = (Member) obj;

		String thisDescriptor=descriptor;
		if (thisDescriptor==null) thisDescriptor="";
		String thisName=name;
		if (thisName==null) thisName="";
		String thisOwner=owner;
		if (thisOwner==null) thisOwner="";
		
		String otherDescriptor=other.descriptor;
		if (otherDescriptor==null) otherDescriptor="";
		String otherName=other.name;
		if (otherName==null) otherName="";
		String otherOwner=other.owner;
		if (otherOwner==null) otherOwner="";
		
		if (!thisDescriptor.equals(otherDescriptor)) return false;
		if (!thisName.equals(otherName)) return false;
		if (!thisOwner.equals(otherOwner)) return false;
		
		org.objectweb.asm.commons.Method m;
		return true;
		/*
		 * Original code:
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
		*/
	}
	@Override
	public boolean equals(Object obj) {
		return customEquals(obj);
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
	/**
	 * Return the sizes of the returnvalue and params in units of 4 bytes (so a long will count as 2)
	 * Argument size is returnvalue>>2, return size is returnvalue&3.
	 * @return
	 */
	public int getArgumentsAndReturnSizes() {
		int s=0;
		// Use asm Type object to calculate the ParamSize
		Type t=Type.getMethodType(descriptor);
		s=t.getArgumentsAndReturnSizes();
		return s;
	}
	/**
	 * Return the size of the returnvalue in units of 4 bytes (so a long will count as 2)
	 * @return
	 */
	public int getReturnSize() {
		int s=0;
		// Use asm Type object to calculate the size
		Type t=Type.getReturnType(descriptor);
		s=t.getSize();
		return s;
	}
	/**
	 * Return the size of the returnvalue in units of 4 bytes (so a long will count as 2)
	 * @return
	 */
	public int getArgumentsSize() {
		// Use asm Type object to calculate the size
		return getArgumentsAndReturnSizes()>>2;
	}
	/**
	 * Increment the number of times this member is used in the target code
	 */
	public void incrementUseCount() {
		useCount++;
	}
	
	/**
	 * @return the useCount
	 */
	public int getUseCount() {
		return useCount;
	}
	/**
	 * @return the invokeShortIndex
	 */
	public int getInvokeShortIndex() {
		return invokeShortIndex;
	}
	/**
	 * @param invokeShortIndex the invokeShortIndex to set
	 */
	public void setInvokeShortIndex(int invokeShortIndex) {
		this.invokeShortIndex = invokeShortIndex;
	}
	
} // end of Member inner class
