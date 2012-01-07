package de.netallied.xsd2cppsax;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSTypeDefinition;

/**
 * Contains information about possible parents and types of an element name.
 * 
 */
public class ElementUsage {

    /**
     * Ancestors. First Element of each list is direct parent, following
     * elements in each list are ancestors of that parent.
     */
    private List<List<XSElementDeclaration>> ancestors = new ArrayList<List<XSElementDeclaration>>();

    /** Element name this object provides information for. */
    private String elementName;

    /** Different elements which have same name. */
    private List<XSElementDeclaration> elements = new ArrayList<XSElementDeclaration>();

    /** Map of parent name to element. */
    private Map<String, List<XSElementDeclaration>> elementsByParent = new HashMap<String, List<XSElementDeclaration>>();

    /** Different types of elements which have same name. */
    private SortedSet<XSTypeDefinition> types = new TreeSet<XSTypeDefinition>(new XSTypeComparator());

    /**
     * c-tor.
     * 
     * @param elementName
     *            Name of element this object provides information for.
     */
    public ElementUsage(String elementName) {
        this.elementName = elementName;
    }

    /**
     * Adds an element.
     * 
     * @param element
     *            Element to add.
     */
    public void addElement(XSElementDeclaration element) {
        if (!elements.contains(element)) {
            elements.add(element);
        }
        if (!getTypes().contains(element.getTypeDefinition())) {
            getTypes().add(element.getTypeDefinition());
        }
    }

    /**
     * Adds an element for a parent.
     * 
     * @param parentName
     *            Parent element name.
     * @param element
     *            Element.
     */
    public void addElementByParent(String parentName, XSElementDeclaration element) {
        List<XSElementDeclaration> elements = elementsByParent.get(parentName);
        if (elements == null) {
            elements = new ArrayList<XSElementDeclaration>();
            elementsByParent.put(parentName, elements);
        }
        elements.add(element);
        getTypes().add(element.getTypeDefinition());
    }

    /**
     * Get ancestors of given element.
     */
    public List<List<XSElementDeclaration>> collectAncestorsOfElement(XSElementDeclaration element,
            Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups) {
        List<List<XSElementDeclaration>> ancestorsOfElement = new ArrayList<List<XSElementDeclaration>>();
        for (List<XSElementDeclaration> possibleAncestors : ancestors) {
            if (possibleAncestors == null) {
                continue;
            }
            if (possibleAncestors.isEmpty()) {
                continue;
            }
            DirectChildrenCollector dcc = new DirectChildrenCollector();
            SortedSet<XSElementDeclaration> children = dcc.collect(possibleAncestors.get(0).getTypeDefinition(),
                    substitutionGroups, new HashSet<XSTypeDefinition>());
            if (children.contains(element)) {
                ancestorsOfElement.add(possibleAncestors);
            }
        }
        return ancestorsOfElement;
    }

    /**
     * @return List of possible parents for this element.
     */
    public List<XSElementDeclaration> collectParents() {
        List<XSElementDeclaration> parents = new ArrayList<XSElementDeclaration>();
        for (List<XSElementDeclaration> dads : ancestors) {
            if (dads != null && !dads.isEmpty()) {
                parents.add(dads.get(0));
            }
        }
        return parents;
    }

    /**
     * Returns all parents for given element.
     * 
     * @param child
     *            Child to find parents for.
     * @return Parents for given element.
     */
    public SortedSet<XSElementDeclaration> collectParents(XSElementDeclaration child) {
        SortedSet<XSElementDeclaration> possibleParents = collectPossibleParents();
        SortedSet<XSElementDeclaration> parents = new TreeSet<XSElementDeclaration>(new XSElementComparator());
        for (XSElementDeclaration parent : possibleParents) {
            List<XSElementDeclaration> elementsByParentName = getElementsByParent(parent.getName());
            if (elementsByParentName != null && elementsByParentName.contains(child)) {
                parents.add(parent);
            }
        }
        return parents;
    }

    /**
     * @return Direct parents for all elements with same name.
     */
    public SortedSet<XSElementDeclaration> collectPossibleParents() {
        SortedSet<XSElementDeclaration> parents = new TreeSet<XSElementDeclaration>(new XSElementComparator());
        for (List<XSElementDeclaration> tmp : ancestors) {
            if (tmp != null && !tmp.isEmpty()) {
                parents.add(tmp.get(0));
            }
        }
        return parents;
    }

    /**
     * Get possible ancestors of elements with name of this object.
     * 
     */
    public List<List<XSElementDeclaration>> getAncestors() {
        return ancestors;
    }

    /**
     * @return Name of element this object handles.
     */
    public String getElementName() {
        return elementName;
    }

    /**
     * @return All the elements with same name.
     */
    public List<XSElementDeclaration> getElements() {
        return elements;
    }

    /**
     * Get element by parent name.
     * 
     * @param parentName
     *            Name of parent element.
     * @return child of given parent.
     */
    public List<XSElementDeclaration> getElementsByParent(String parentName) {
        return elementsByParent.get(parentName);
    }

    /**
     * @return Types of elements which have given name.
     */
    public Set<XSTypeDefinition> getTypes() {
        return types;
    }
}
