/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import org.apache.xerces.xs.XSConstants;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSNamedMap;
import org.apache.xerces.xs.XSObject;
import org.apache.xerces.xs.XSTypeDefinition;

/**
 * Creates C++ names for XML elements. As element names in XSD are not unique
 * there are several cases how the C++ name will be created see
 * {@link #createElementName(XSElementDeclaration)}.
 * 
 */
public class CppElementNameCreator extends AbstractStackBasedTraverser {

    /** Collected element usage data. */
    private Map<String, ElementUsage> completeElementUsage;

    /** Element to c++ element name mapping. */
    private Map<XSElementDeclaration, CppElementNameParentTypesPair> element2ElementName = new HashMap<XSElementDeclaration, CppElementNameParentTypesPair>();

    /** @see Generator#substitutionGroups */
    private Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups;

    /**
     * c-tor.
     * 
     * @param config
     *            Configuration.
     * @param completeElementUsage
     *            Element usage data.
     */
    public CppElementNameCreator(Config config, Map<String, ElementUsage> completeElementUsage,
            Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups) {
        super(config);
        this.completeElementUsage = completeElementUsage;
        this.substitutionGroups = substitutionGroups;
    }

    /**
     * Collects XSD types which have given element as child.
     * 
     * @param element
     *            Element to collect parents for.
     * @param elementUsage
     *            Element usage data.
     * @return Collected parent types.
     */
    protected SortedSet<XSTypeDefinition> collectParentTypes(XSElementDeclaration element, ElementUsage elementUsage) {
        SortedSet<XSTypeDefinition> parentTypes = new TreeSet<XSTypeDefinition>(new XSTypeComparator());
        for (XSElementDeclaration parent : elementUsage.collectParents()) {
            DirectChildrenCollector childrenCollector = new DirectChildrenCollector();
            Set<XSElementDeclaration> siblings = childrenCollector.collect(parent.getTypeDefinition(),
                    substitutionGroups, new HashSet<XSTypeDefinition>());
            for (XSElementDeclaration sibling : siblings) {
                if (sibling.getName().equals(element.getName())
                        && sibling.getTypeDefinition() == element.getTypeDefinition()) {
                    parentTypes.add(parent.getTypeDefinition());
                }
            }
        }
        return parentTypes;
    }

    /**
     * Counts how many XSD types exist with given name. If out commented code is
     * used, only those types are counted which have a child element with given
     * child name.
     * 
     * @param parentName
     *            Element name to cout types for.
     * 
     * @param childName
     *            Name of child element to reduce number of types.
     * @return Number of types.
     */
    protected int countParentsWithDifferentTypesAndSameNamesWhichHaveGivenChild(String parentName, String childName) {
        List<XSElementDeclaration> elements = completeElementUsage.get(parentName).getElements();
        Set<XSTypeDefinition> types = new HashSet<XSTypeDefinition>();
        for (XSElementDeclaration elem : elements) {
            types.add(elem.getTypeDefinition());
        }
        // Set<XSTypeDefinition> toRemove = new HashSet<XSTypeDefinition>();
        // for (XSTypeDefinition type : types) {
        // DirectChildrenCollector collector = new DirectChildrenCollector();
        // Set<String> children = collector.collect(type);
        // if (children == null || !children.contains(childName)) {
        // toRemove.add(type);
        // }
        // }
        // types.removeAll(toRemove);
        return types.size();
    }

    /**
     * Creates C++ Name to be used in generated code. Must take care of name
     * clashes.
     * 
     * @param element
     *            Element to create name for.
     * @return C++ Name.
     */
    protected CppElementNameParentTypesPair createElementName(XSElementDeclaration element) {
        String name = "";

        ElementUsage elementUsage = completeElementUsage.get(element.getName());
        List<XSElementDeclaration> elements = elementUsage.getElements();
        SortedSet<XSTypeDefinition> types = new TreeSet<XSTypeDefinition>(new XSTypeComparator());
        for (XSElementDeclaration elem : elements) {
            types.add(elem.getTypeDefinition());
        }

        // case 1: element-name has only one type
        if (types.size() == 1) {
            CppElementNameParentTypesPair returnVal = new CppElementNameParentTypesPair();
            returnVal.cppElementName = Util.replaceCharactersForbiddenInCppIdentifiers(element.getName());
            returnVal.parentTypes = new TreeSet<XSTypeDefinition>(new XSTypeComparator());
            for (XSElementDeclaration parent : elementUsage.collectParents()) {
                returnVal.parentTypes.add(parent.getTypeDefinition());
            }
            return returnVal;
        }

        // case 2: type has a name
        String delmi = config.getElementNameDelimiter();
        if (element.getTypeDefinition().getName() != null) {
            String uniqueTypeName = makeXstypeNamespaceUnique(element);
            CppElementNameParentTypesPair returnVal = new CppElementNameParentTypesPair();
            returnVal.cppElementName = Util.replaceCharactersForbiddenInCppIdentifiers(element.getName() + delmi
                    + delmi + uniqueTypeName);
            returnVal.parentTypes = collectParentTypes(element, elementUsage);
            return returnVal;
        }

        // case 3: anonymous type inside a type with a name
        SortedSet<XSTypeDefinition> parentTypes = collectParentTypes(element, elementUsage);
        // XSTypeDefinition exactParentType = findExactParentType(element,
        // parentTypes);
        XSElementDeclaration parentElement = getParentElementFromStack();
        XSTypeDefinition exactParentType = parentElement.getTypeDefinition();
        if (exactParentType != null && exactParentType.getName() != null) {
            String uniqueParentName = makeXstypeNamespaceUnique(parentElement);
            name = uniqueParentName + delmi + delmi + element.getName();
            CppElementNameParentTypesPair returnVal = new CppElementNameParentTypesPair();
            returnVal.cppElementName = Util.replaceCharactersForbiddenInCppIdentifiers(name);
            returnVal.parentTypes = parentTypes;
            return returnVal;
        }

        // case 4: anonymous type inside an element which has been declared as
        // top level element
        // TODO make this element naming case namespace unique
        XSNamedMap elementMap = getModel().getComponents(XSConstants.ELEMENT_DECLARATION);
        for (int i = 0; i < elementMap.getLength(); i++) {
            XSObject item = elementMap.item(i);
            if (item.getType() == XSConstants.ELEMENT_DECLARATION) {
                if (item == element) {
                    name = element.getName();
                    CppElementNameParentTypesPair returnVal = new CppElementNameParentTypesPair();
                    returnVal.cppElementName = Util.replaceCharactersForbiddenInCppIdentifiers(name);
                    returnVal.parentTypes = parentTypes;
                    return returnVal;
                }
            }
        }

        // case 5: anonymous type inside an element which has an not unique name
        // TODO make this element naming case namespace unique
        List<List<XSElementDeclaration>> possibilities = elementUsage.getAncestors();

        name += element.getName();

        if (possibilities.size() > 1 && getElementStack().size() > 1) {
            int i = getElementStack().size() - 2;
            String parentName = getElementStack().get(i).getName();
            String childName = getElementStack().get(i + 1).getName();
            name = parentName + delmi + name;
            while (countParentsWithDifferentTypesAndSameNamesWhichHaveGivenChild(parentName, childName) > 1 && i > 0) {
                i--;
                childName = parentName;
                parentName = getElementStack().get(i).getName();
                name = parentName + delmi + name;
            }
        }
        CppElementNameParentTypesPair returnVal = new CppElementNameParentTypesPair();
        returnVal.cppElementName = Util.replaceCharactersForbiddenInCppIdentifiers(name);
        returnVal.parentTypes = parentTypes;
        return returnVal;
    }

    /**
     * @return created element names.
     */
    public Map<XSElementDeclaration, CppElementNameParentTypesPair> getElementNameMapping() {
        return element2ElementName;
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

        if (!element2ElementName.containsKey(element)) {
            CppElementNameParentTypesPair cppNameAndParentsPair = createElementName(element);
            CppElementNameParentTypesPair oldValue = element2ElementName.put(element, cppNameAndParentsPair);
            if (oldValue != null) {
                System.err.println("*** old cpp name: " + oldValue.cppElementName + ", new one: "
                        + cppNameAndParentsPair.cppElementName);
            }
            Map<String, String> elementNameMapping = getConfig().getElementNameMapping();
            if (elementNameMapping.containsKey(cppNameAndParentsPair.cppElementName)) {
                cppNameAndParentsPair.cppElementName = elementNameMapping.get(cppNameAndParentsPair.cppElementName);
            }
        }

        super.handleElement(element);

        getElementStack().pop();
        return true;
    }

    /**
     * Checks if there are other xml namespaces containing a type with same name
     * as given element's type. If this is the case a namespace identifier is
     * added to the type name.
     * 
     * @param element
     *            Element of which type shall be made unique in all known
     *            namespaces.
     * @return unique type name.
     */
    protected String makeXstypeNamespaceUnique(XSElementDeclaration element) {
        ElementUsage elementUsage = completeElementUsage.get(element.getName());
        Set<XSTypeDefinition> types = elementUsage.getTypes();
        Set<XSTypeDefinition> typesWithSameName = new HashSet<XSTypeDefinition>();
        String givenElementTypeName = Util.replaceCharactersForbiddenInCppIdentifiers(element.getTypeDefinition()
                .getName());
        for (XSTypeDefinition type : types) {
            if (type == element.getTypeDefinition() || type.getName() == null) {
                continue;
            }
            String otherTypeName = Util.replaceCharactersForbiddenInCppIdentifiers(type.getName());
            if (type.getName() != null && givenElementTypeName.equals(otherTypeName)) {
                typesWithSameName.add(type);
            }
        }
        String uniqueTypeName = element.getTypeDefinition().getName();
        if (!typesWithSameName.isEmpty()) {
            String targetNamespace = Util.findTargetNamespace(getModel());
            String typeNamespace = element.getTypeDefinition().getNamespace();
            if (!typeNamespace.equals(targetNamespace)) {
                String delmi = config.getElementNameDelimiter();
                Map<String, String> xsNamespaceMapping = config.getXsNamespaceMapping();
                if (xsNamespaceMapping.containsKey(typeNamespace)) {
                    typeNamespace = xsNamespaceMapping.get(typeNamespace);
                }
                uniqueTypeName += delmi + delmi + typeNamespace;
            }
        }
        return uniqueTypeName;
    }

}
