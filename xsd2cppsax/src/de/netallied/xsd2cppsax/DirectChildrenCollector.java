package de.netallied.xsd2cppsax;

import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import org.apache.xerces.xs.XSComplexTypeDefinition;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSModelGroup;
import org.apache.xerces.xs.XSParticle;
import org.apache.xerces.xs.XSTypeDefinition;

/**
 * Collects direct children of a XSD type. Grand-Children are ignored. Takes
 * care of XSD substitution groups.
 * 
 */
public class DirectChildrenCollector {

    /** Collected children. */
    private SortedSet<XSElementDeclaration> children = new TreeSet<XSElementDeclaration>(new XSElementComparator());

    /** Given substitution groups which are used to find correct children. */
    private Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups;

    /**
     * Starts collecting of children.
     * 
     * @param type
     *            XSD type to collect children for.
     * @param substitutionGroups
     *            Substitution groups to be used during collection.
     * @param handledTypes
     *            Used to avoid endless recursion. Should be empty at the
     *            beginning.
     * @return collected children or null if type is a simple type.
     */
    public SortedSet<XSElementDeclaration> collect(XSTypeDefinition type,
            Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups, Set<XSTypeDefinition> handledTypes) {
        this.substitutionGroups = substitutionGroups;

        handledTypes.add(type);

        if (type instanceof XSComplexTypeDefinition) {
            XSComplexTypeDefinition complexType = (XSComplexTypeDefinition) type;
            handleParticle(complexType.getParticle());

            XSTypeDefinition baseType = complexType.getBaseType();
            SortedSet<XSElementDeclaration> baseTypeChildren = null;
            if (!handledTypes.contains(baseType)) {
                DirectChildrenCollector baseTypeChildrenCollector = new DirectChildrenCollector();
                baseTypeChildren = baseTypeChildrenCollector.collect(baseType, substitutionGroups, handledTypes);
            }
            SortedSet<XSElementDeclaration> children = new TreeSet<XSElementDeclaration>(new XSElementComparator());
            children.addAll(getChildren());
            if (baseTypeChildren != null) {
                children.addAll(baseTypeChildren);
            }

            return children;
        }
        return null;
    }

    /**
     * @return Collected children.
     */
    public SortedSet<XSElementDeclaration> getChildren() {
        return children;
    }

    /**
     * Handles element for children collection.
     */
    protected void handleElement(XSElementDeclaration element) {
        if (substitutionGroups.containsKey(element)) {
            children.addAll(substitutionGroups.get(element));
            if (!element.getAbstract()) {
                children.add(element);
            }
        } else {
            children.add(element);
        }
    }

    /**
     * Handles model group for children collection.
     */
    protected void handleModelGroup(XSModelGroup modelGroup) {
        for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
            XSParticle particle = (XSParticle) modelGroup.getParticles().item(i);
            handleParticle(particle);
        }
    }

    /**
     * Handles particle for children collection.
     */
    protected void handleParticle(XSParticle particle) {
        if (particle == null) {
            return;
        }
        if (particle.getTerm() instanceof XSElementDeclaration) {
            handleElement((XSElementDeclaration) particle.getTerm());
        } else if (particle.getTerm() instanceof XSModelGroup) {
            handleModelGroup((XSModelGroup) particle.getTerm());
        }
    }
}
