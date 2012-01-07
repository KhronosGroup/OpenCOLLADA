/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.util.Stack;

import org.apache.xerces.xs.XSElementDeclaration;

/**
 * Contains a stack which must be updated by subclasses. This class's main
 * purpose is to check the stack to escape endless recursion.
 * 
  */
public abstract class AbstractStackBasedTraverser extends AbstractXSTraverser {

    /** Contains all ancestors of current element. */
    private Stack<XSElementDeclaration> elementStack = new Stack<XSElementDeclaration>();

    /**
     * Constructor.
     */
    public AbstractStackBasedTraverser(Config config) {
        super(config);
    }

    /**
     * Checks if given element is already somewhere on stack.
     * 
     * @param element
     *            Element to check.
     * @return True if element is not on stack.
     */
    protected boolean checkStack(XSElementDeclaration element) {
        if (elementStack.isEmpty()) {
            return true;
        }
        int counter = 0;
        for (int i = elementStack.size() - 1; i >= 0; i--) {
            if (elementStack.get(i) == element) {
                counter++;
            }
        }
        if (counter == 0 || (counter == 1 && elementStack.peek() == element)) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * @return Element stack.
     */
    public Stack<XSElementDeclaration> getElementStack() {
        return elementStack;
    }

    /**
     * @return Parent element from stack, or <code>null</code>.
     */
    public XSElementDeclaration getParentElementFromStack() {
        if (elementStack.size() >= 2) {
            return elementStack.get(elementStack.size() - 2);
        }
        return null;
    }
}
