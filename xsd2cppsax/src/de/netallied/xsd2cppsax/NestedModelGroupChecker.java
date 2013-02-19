/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Set;

import org.apache.xerces.xs.XSComplexTypeDefinition;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSModelGroup;
import org.apache.xerces.xs.XSObject;
import org.apache.xerces.xs.XSObjectList;
import org.apache.xerces.xs.XSParticle;

/**
 * Checks XSD for nested model groups. For debugging purposes.
 * 
 */
public class NestedModelGroupChecker extends AbstractStackBasedTraverser {

    /** Model groups which have already been checked. */
    private Set<XSModelGroup> checkedGroups = new HashSet<XSModelGroup>();

    /** Output file. */
    private PrintStream outFile;

    /**
     * Constructor.
     */
    public NestedModelGroupChecker(Config config) {
        super(config);
        try {
            outFile = new PrintStream("nested_model_groups.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    /**
     * Checks model group for nested model groups.
     */
    protected void checkModelGroup(XSModelGroup modelGroup, int nestedHierarchy) {
        if (!checkedGroups.contains(modelGroup)) {
            checkedGroups.add(modelGroup);
            XSObjectList particles = modelGroup.getParticles();
            for (int i = 0; i < particles.getLength(); i++) {
                XSObject item = particles.item(i);
                if (item instanceof XSParticle) {
                    XSParticle particle = (XSParticle) item;
                    if (particle.getTerm() instanceof XSModelGroup) {
                        XSModelGroup nestedModelGroup = (XSModelGroup) particle.getTerm();
                        String indent = "  ";
                        if (nestedHierarchy != 0) {
                            for (int j = 0; j < nestedHierarchy; j++) {
                                indent += indent;
                            }
                        }
                        if (nestedHierarchy == 0)
                            outFile.println("nested model group: ");
                        else {
                            outFile.println(indent + "nested nested model group: ");
                        }
                        outFile.println(indent + "element: " + getElementStack().peek().getName());
                        outFile.println(indent + "outer compositor: " + getCompositorString(modelGroup));
                        outFile.println(indent + "inner compositor: " + getCompositorString(nestedModelGroup));
                        outFile.println(indent + "inner min/max Occ: " + particle.getMinOccurs() + ", "
                                + particle.getMaxOccurs());
                        if (nestedModelGroup.getParticles() != null) {
                            for (int j = 0; j < nestedModelGroup.getParticles().getLength(); j++) {
                                XSParticle nestedChildParticle = (XSParticle) nestedModelGroup.getParticles().item(j);
                                if (nestedChildParticle.getMinOccurs() != 1 && nestedChildParticle.getMaxOccurs() != 1)
                                    outFile.println(indent + "inner child " + j + " min/max Occ: "
                                            + nestedChildParticle.getMinOccurs() + ", "
                                            + nestedChildParticle.getMaxOccurs());
                            }
                        }

                        checkModelGroup(nestedModelGroup, ++nestedHierarchy);
                    }
                }
            }
        }
    }

    /**
     * @param modelGroup
     *            Model group to get a compositor string for.
     * @return String for given model groups compositor.
     */
    protected String getCompositorString(XSModelGroup modelGroup) {
        switch (modelGroup.getCompositor()) {
        case XSModelGroup.COMPOSITOR_ALL:
            return "ALL";
        case XSModelGroup.COMPOSITOR_CHOICE:
            return "CHOICE";
        case XSModelGroup.COMPOSITOR_SEQUENCE:
            return "SEQUENCE";
        }
        return "UNKNOWN";
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
        getElementStack().push(element);

        if (element.getTypeDefinition() instanceof XSComplexTypeDefinition) {
            XSComplexTypeDefinition complexType = (XSComplexTypeDefinition) element.getTypeDefinition();
            if (complexType.getParticle() != null) {
                if (complexType.getParticle().getTerm() instanceof XSModelGroup) {
                    XSModelGroup modelGroup = (XSModelGroup) complexType.getParticle().getTerm();
                    checkModelGroup(modelGroup, 0);
                }
            }
        }

        super.handleElement(element);
        getElementStack().pop();
        return true;
    }
}
