/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.util.HashSet;
import java.util.Set;

import org.apache.xerces.xs.XSComplexTypeDefinition;
import org.apache.xerces.xs.XSConstants;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSModel;
import org.apache.xerces.xs.XSModelGroup;
import org.apache.xerces.xs.XSNamedMap;
import org.apache.xerces.xs.XSObject;
import org.apache.xerces.xs.XSObjectList;
import org.apache.xerces.xs.XSParticle;
import org.apache.xerces.xs.XSTerm;
import org.apache.xerces.xs.XSTypeDefinition;
import org.apache.xerces.xs.XSWildcard;

/**
 * Traverses Xerces XS data structure.
 * 
 */
public abstract class AbstractXSTraverser {

    /** Code generator configuration. */
    protected Config config;

    /**
     * To avoid traversing of sub-trees multiple times when <xs:element ref="">
     * is used excessively
     */
    private Set<XSElementDeclaration> handledElements = new HashSet<XSElementDeclaration>();

    /** Model being traversed. */
    private XSModel model;

    /**
     * Constructor.
     */
    public AbstractXSTraverser(Config config) {
        this.config = config;
    }

    /**
     * Searches given model for a top level element with given name.
     * 
     * @param model
     *            Model to search.
     * @param rootElementName
     *            Root element name.
     * @return Root element.
     */
    public XSElementDeclaration findRootElement(XSModel model, String rootElementName) {
        XSNamedMap elementMap = model.getComponents(XSConstants.ELEMENT_DECLARATION);
        for (int i = 0; i < elementMap.getLength(); i++) {
            XSObject item = elementMap.item(i);
            if (item.getType() == XSConstants.ELEMENT_DECLARATION) {
                if (item.getName().equals(rootElementName)) {
                    return (XSElementDeclaration) item;
                }
            }
        }
        return null;
    }

    /**
     * @return Code generator configuration.
     */
    protected Config getConfig() {
        return config;
    }

    /**
     * @return Model being traversed.
     */
    public XSModel getModel() {
        return model;
    }

    /**
     * Handles an element,
     * 
     * @param element
     *            Element to handle.
     * @return True if traversing shall continue, false for abort.
     */
    public boolean handleElement(XSElementDeclaration element) {
        if (!handledElements.contains(element)) {
            handledElements.add(element);

            XSTypeDefinition typeDefinition = element.getTypeDefinition();
            return handleTypeDefinition(typeDefinition);
        }
        return true;
    }

    /**
     * Handles a model group.
     * 
     * @param modelGroup
     *            Model group to handle.
     * @return True if traversing shall continue, false for abort.
     */
    public boolean handleModelGroup(XSModelGroup modelGroup) {
        XSObjectList particles = modelGroup.getParticles();
        for (int i = 0; i < particles.getLength(); i++) {
            XSParticle particle = (XSParticle) particles.item(i);
            boolean success = handleParticle(particle);
            if (!success) {
                return false;
            }
        }
        return true;
    }

    /**
     * Handles a particle.
     * 
     * @param particle
     *            Particle to handle.
     * @return True if traversing shall continue, false for abort.
     */
    public boolean handleParticle(XSParticle particle) {
        if (particle == null) {
            return true;
        }

        XSTerm term = particle.getTerm();
        if (term instanceof XSModelGroup) {
            XSModelGroup modelGroup = (XSModelGroup) term;

            if (!handleModelGroup(modelGroup)) {
                return false;
            }

            XSObjectList particles = modelGroup.getParticles();
            for (int i = 0; i < particles.getLength(); i++) {
                if (particles.item(i) instanceof XSParticle) {
                    if (!handleParticle((XSParticle) particles.item(i))) {
                        return false;
                    }
                }
            }
        } else if (term instanceof XSElementDeclaration) {
            return handleElement((XSElementDeclaration) term);

        } else if (term instanceof XSWildcard) {
            return handleWildcard((XSWildcard) term);
        }
        return true;
    }

    /**
     * Handles a XSD type
     * 
     * @param typeDefinition
     *            Type to handle.
     * @return True if traversing shall continue, false for abort.
     */
    protected boolean handleTypeDefinition(XSTypeDefinition typeDefinition) {
        if (isTypeComplex(typeDefinition)) {
            XSComplexTypeDefinition complexTypeDefi = (XSComplexTypeDefinition) typeDefinition;
            boolean success = handleParticle(complexTypeDefi.getParticle());
            if (!success) {
                return false;
            }
        }
        XSTypeDefinition baseType = typeDefinition.getBaseType();
        if (baseType != null) {
            if (!Constants.XSD_ANYTYPE_NAME.equals(baseType.getName())
                    && !getConfig().getXSNamespace().equals(baseType.getNamespace())) {
                return handleTypeDefinition(baseType);
            }
        }
        return true;
    }

    /**
     * Handles a wildcard.
     * 
     * @param wildcard
     *            Wildcard to handle.
     * @return True if traversing shall continue, false for abort.
     */
    public boolean handleWildcard(XSWildcard wildcard) {
        return true;
    }

    public boolean isTypeComplex(XSTypeDefinition type) {
        return type.getTypeCategory() == XSTypeDefinition.COMPLEX_TYPE;
    }

    /**
     * @param model
     *            Model being traversed.
     */
    protected void setModel(XSModel model) {
        this.model = model;
    }

    /**
     * Starts traversing.
     * 
     * @param model
     *            Model to traverse.
     */
    public void start(XSModel model) {
        this.model = model;
        XSNamedMap elementMap = model.getComponents(XSConstants.ELEMENT_DECLARATION);
        for (int i = 0; i < elementMap.getLength(); i++) {
            XSObject item = elementMap.item(i);
            if (item.getType() == XSConstants.ELEMENT_DECLARATION) {
                handleElement((XSElementDeclaration) item);
            }
        }
    }

    /**
     * Starts traversing with given root element.
     * 
     * @param model
     *            Model to traverse.
     * @param rootElementName
     *            Name of element to start with.
     */
    public void startWithRootElement(XSModel model, String rootElementName) {
        this.model = model;
        XSElementDeclaration rootElement = findRootElement(model, rootElementName);
        if (handleElement(rootElement)) {
            start(model);
        }
    }
}
