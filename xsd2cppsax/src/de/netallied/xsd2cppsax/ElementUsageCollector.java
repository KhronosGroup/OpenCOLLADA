/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.xerces.xs.XSElementDeclaration;

/**
 * Traverses XSD Tree and finds out which element is used under which parent
 * elements.
 * 
 */
public class ElementUsageCollector extends AbstractStackBasedTraverser {

    /** Collected element usage data. Key: XSD element name. */
    private Map<String, ElementUsage> completeElementUsage = new HashMap<String, ElementUsage>();

    /**
     * Constructor.
     */
    public ElementUsageCollector(Config config) {
        super(config);
    }

    /**
     * @note: this consumes too much memory for COLLADA 1.5 -> only parent is
     *        returned.
     * @return List containing current stack elements in reverse order.
     */
    protected List<XSElementDeclaration> buildCurrentAncestorList() {
        List<XSElementDeclaration> list = new ArrayList<XSElementDeclaration>();

        // this consumes too much memory for COLLADA 1.5
        for (int i = getElementStack().size() - 1; i >= 0; i--) {
            XSElementDeclaration elemDecl = getElementStack().get(i);
            list.add(elemDecl);
        }

        // if (getElementStack().size() >= 1)
        // list.add(getElementStack().get(getElementStack().size() - 1));

        return list;
    }

    /**
     * @return Collected element usage data.
     */
    public Map<String, ElementUsage> getCompleteElementUsage() {
        return completeElementUsage;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.AbstractXSTraverser#handleElement(com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    @Override
    public boolean handleElement(XSElementDeclaration element) {
        if (!checkStack(element)) {
            return true;
        }

        String elemName = element.getName();
        if (!completeElementUsage.containsKey(elemName)) {
            ElementUsage usage = new ElementUsage(elemName);
            completeElementUsage.put(elemName, usage);
        }
        ElementUsage usage = completeElementUsage.get(elemName);

        if (!getElementStack().isEmpty()) {
            String parentName = getElementStack().peek().getName();
            usage.addElementByParent(parentName, element);
        }
        usage.addElement(element);

        List<List<XSElementDeclaration>> ancestors = usage.getAncestors();
        ancestors.add(buildCurrentAncestorList());

        getElementStack().push(element);
        super.handleElement(element);
        getElementStack().pop();
        return true;
    }
}
