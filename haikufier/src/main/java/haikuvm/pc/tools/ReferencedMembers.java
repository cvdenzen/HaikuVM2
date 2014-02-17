package haikuvm.pc.tools;

import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;
import java.util.logging.Logger;

public class ReferencedMembers<T> extends HashSet<T> {

	/**
	 * The set of methods and fields to be included
	 */
	/**
	 * Stupid (temporary) solution to lookup a Member by its owner,name,desc fields.
	 * This works in combination with the equals method of Member.
	 */
	HashMap<T,T> map=new HashMap<T,T>();
	public ReferencedMembers(ReferencedMembers<T> referencedMembers) {
		super();
		// TODO Auto-generated constructor stub
		for (T m:referencedMembers) {
			add(m);
		}
	}
	public ReferencedMembers() {
		// TODO Auto-generated constructor stub
		super();
	}
	/**
	 * Make the add method do some logging
	 */
	public boolean add(T member) {
		T returnValue=map.put(member,member);
		if (returnValue==null) {
			// This is a new member
			logger.fine("*** referencedMembers: add "+member);
		}
		return super.add(member);
	}
	/**
	 * Clear the Set and the Map
	 */
	@Override
	public void clear() {
		super.clear();
		map.clear();
	}
	@Override
	public boolean remove(Object o) {
		map.remove(o);
		return remove(o);
	}
	public Member get(String owner,String name, String desc) {
		Member m=new Member(owner,name,desc);
		// The equals method of Member will find the right Member and return this
		// in the remove method.
		m=(Member) map.get(m);
		return m;
	}
	public Member get(Member m) {
		return get(m.getOwner(),m.getName(),m.getDescriptor());
	}
	static private Logger logger=Logger.getLogger("haikuvm.pc.tools");
}
