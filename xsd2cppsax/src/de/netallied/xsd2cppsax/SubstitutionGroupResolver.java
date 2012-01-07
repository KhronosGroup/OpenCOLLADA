XXXXXAAAAAXXXXX
package de.netallied.xsd2cppsax;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.xerces.xs.XSElementDeclaration;

/**
 * Traverses XSD in search for substitution groups. Stores elements which may
 * substitute another one.
 * 
 */
public class SubstitutionGroupResolver extends AbstractStackBasedTraverser {

    /** Stores found substitution groups. */
    private Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups = new HashMap<XSElementDeclaration, List<XSElementDeclaration>>();

    /**
     * Constructor.
     */
    public SubstitutionGroupResolver(Config config) {
        super(config);
    }

    /**
     * @return Resolved substitution groups.
     */
    public Map<XSElementDeclaration, List<XSElementDeclaration>> getSubstitutionGroups() {
        return substitutionGroups;
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

        storeSubstitutesRecursive(element, element.getSubstitutionGroupAffiliation());

        getElementStack().push(element);
        super.handleElement(element);
        getElementStack().pop();
        return true;
    }

    /**
     * Stores substitute in list corresponding to affiliation.
     * 
     * @param substitute
     *            Element which may substitute affiliation.
     * @param affiliation
     *            Element which may be substituted. May be null.
     */
    protected void storeSubstitutesRecursive(XSElementDeclaration substitute, XSElementDeclaration affiliation) {
        if (affiliation != null) {
            if (!substitutionGroups.containsKey(affiliation)) {
                substitutionGroups.put(affiliation, new ArrayList<XSElementDeclaration>());
            }
            List<XSElementDeclaration> substitutes = substitutionGroups.get(affiliation);
            substitutes.add(substitute);

            if (affiliation.getSubstitutionGroupAffiliation() != null) {
                storeSubstitutesRecursive(substitute, affiliation.getSubstitutionGroupAffiliation());
            }
        }
    }
}
