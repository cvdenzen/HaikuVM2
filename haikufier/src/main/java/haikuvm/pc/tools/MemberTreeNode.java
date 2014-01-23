package haikuvm.pc.tools;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;

import javax.swing.tree.DefaultMutableTreeNode;

/**
 * A TreeNode that has a Member or anothter MemberTreeNode as userObject.
 * It also informs about changes in userObject (making it a Property).
 * @author CDN
 *
 */
public class MemberTreeNode extends DefaultMutableTreeNode {

	private PropertyChangeSupport propertyChangeSupport=new PropertyChangeSupport(this);
	public MemberTreeNode(Member newFieldMember) {
		super(newFieldMember);
	}

	public MemberTreeNode() {
		super();
	}

	@Override
	public String toString() {
		if (getUserObject() instanceof MemberTreeNode) {
			// Indicate that this is something like a symbolic link
			// to another node
			return "*"+super.toString();
		} else {
			return super.toString();
		}
	}

	
	/**
	 * @param listener
	 * @see java.beans.PropertyChangeSupport#addPropertyChangeListener(java.beans.PropertyChangeListener)
	 */
	public void addPropertyChangeListener(PropertyChangeListener listener) {
		propertyChangeSupport.addPropertyChangeListener(listener);
	}

	/**
	 * @param propertyName
	 * @param listener
	 * @see java.beans.PropertyChangeSupport#addPropertyChangeListener(java.lang.String, java.beans.PropertyChangeListener)
	 */
	public void addPropertyChangeListener(String propertyName,
			PropertyChangeListener listener) {
		propertyChangeSupport.addPropertyChangeListener(propertyName, listener);
	}

	/**
	 * @return
	 * @see java.beans.PropertyChangeSupport#getPropertyChangeListeners()
	 */
	public PropertyChangeListener[] getPropertyChangeListeners() {
		return propertyChangeSupport.getPropertyChangeListeners();
	}

	/**
	 * @param propertyName
	 * @return
	 * @see java.beans.PropertyChangeSupport#getPropertyChangeListeners(java.lang.String)
	 */
	public PropertyChangeListener[] getPropertyChangeListeners(
			String propertyName) {
		return propertyChangeSupport.getPropertyChangeListeners(propertyName);
	}

	/**
	 * @param listener
	 * @see java.beans.PropertyChangeSupport#removePropertyChangeListener(java.beans.PropertyChangeListener)
	 */
	public void removePropertyChangeListener(PropertyChangeListener listener) {
		propertyChangeSupport.removePropertyChangeListener(listener);
	}

	/**
	 * @param propertyName
	 * @param listener
	 * @see java.beans.PropertyChangeSupport#removePropertyChangeListener(java.lang.String, java.beans.PropertyChangeListener)
	 */
	public void removePropertyChangeListener(String propertyName,
			PropertyChangeListener listener) {
		propertyChangeSupport.removePropertyChangeListener(propertyName,
				listener);
	}

	/**
	 * @param propertyName
	 * @return
	 * @see java.beans.PropertyChangeSupport#hasListeners(java.lang.String)
	 */
	public boolean hasListeners(String propertyName) {
		return propertyChangeSupport.hasListeners(propertyName);
	}

	/**
	 * Make userObject a bound property.
	 * In Eclipse I had write this manually! Netbeans would have generated this itself.
	 */
	public void setUserObject(Object newValue) {
		Object oldValue=userObject;
		super.setUserObject(newValue);
		propertyChangeSupport.firePropertyChange("userObject", oldValue, newValue);
	}
}
