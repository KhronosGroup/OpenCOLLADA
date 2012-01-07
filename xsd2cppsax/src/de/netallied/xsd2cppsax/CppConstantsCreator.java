XXXXXAAAAAXXXXX
package de.netallied.xsd2cppsax;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;

import org.apache.xerces.xs.XSAttributeUse;
import org.apache.xerces.xs.XSElementDeclaration;

/**
 * Creates C++ string and hash constants for XML elements and attributes.
 * 
 */
public class CppConstantsCreator extends AbstractStackBasedTraverser {

    /** Generation data provider. */
    private IGenerationDataProvider dataProvider;

    /** Map of C++ Hash constant name to C++ String constant name. */
    private Map<String, String> hashNameToStringName = new HashMap<String, String>();

    /** Mapping of a hash constant name to it's value. */
    private SortedMap<String, String> hashNameValueMap = new TreeMap<String, String>();

    /** Mapping of a hash constant value to it's C++ constant name. */
    private Map<String, String> hashValueNameMap = new HashMap<String, String>();

    /** Mapping of a string constant name to it's value. */
    private SortedMap<String, String> stringNameValueMap = new TreeMap<String, String>();

    /** Mapping of a string constant value to it's C++ constant name. */
    private Map<String, String> stringValueNameMap = new HashMap<String, String>();

    /**
     * Constructor.
     */
    public CppConstantsCreator(Config config, IGenerationDataProvider dataProvider) {
        super(config);
        this.dataProvider = dataProvider;

        List<XSAttributeUse> list = new ArrayList<XSAttributeUse>();
        list.add(XSFactory.createAttributeXmlns());
        createAttributesConstants(list, null);
    }

    /**
     * Adds a hash constant to internal maps.
     * 
     * @param name
     *            Constant name.
     * @param value
     *            Constant value.
     */
    protected void addHashConstant(String name, String value) {
        if (hashValueNameMap.containsKey(value)) {
            String otherName = hashValueNameMap.get(value);
            if (otherName.compareTo(name) > 0) {
                hashNameValueMap.put(name, value);
                hashValueNameMap.put(value, name);
                hashNameValueMap.put(otherName, name);
            } else {
                hashNameValueMap.put(name, otherName);
            }
        } else {
            hashNameValueMap.put(name, value);
            hashValueNameMap.put(value, name);
        }
    }

    /**
     * Adds a string constant to internal maps.
     * 
     * @param name
     *            Constant name.
     * @param value
     *            Constant value.
     */
    protected void addStringConstant(String name, String value) {
        if (stringValueNameMap.containsKey(value)) {
            stringNameValueMap.put(name, stringValueNameMap.get(value));
        } else {
            stringNameValueMap.put(name, "\"" + value + "\"");
            stringValueNameMap.put(value, name);
        }
    }

    /**
     * Creates C++ identifier (-> constant name) of attribute name.
     * 
     * @param attrName
     *            Attribute name to get identifier for.
     * @return Identifier.
     * @see Util#createAttributeNameHashIdentifier(String)
     */
    protected String createAttributeNameIdentifier(String attrName) {
        // don't use uppercase for constant names because of a name clash in plm
        // xml
        // element: Locator
        // attrs: subtype and subType
        return "NAME_ATTRIBUTE_" + attrName/* .toUpperCase() */;
    }

    /**
     * Creates hash and name constants for attributes.
     * 
     * @param attrs
     *            Attributes to print constants for.
     * @param element
     *            Element attributes belong to.
     */
    protected void createAttributesConstants(List<XSAttributeUse> attrs, XSElementDeclaration element) {
        String elementNamespace = null;
        if (element != null) {
            elementNamespace = element.getNamespace();
        }

        for (XSAttributeUse attr : attrs) {
            String attrName = Util.getAttributeOriginalName(attr, config);
            String attrStringValue = Util.updateAttributeNameWithNamespace(elementNamespace, attr, attrName);
            String cppHashConstantName = Util.createAttributeNameHashIdentifier(attrName);
            if (!hashNameValueMap.containsKey(cppHashConstantName)) {
                String hash = Util.calculateHash(attrStringValue);
                addHashConstant(cppHashConstantName, hash);
            }

            String cppNameConstantName = createAttributeNameIdentifier(attrName);
            if (!stringNameValueMap.containsKey(cppNameConstantName)) {
                String value = attrStringValue;
                addStringConstant(cppNameConstantName, value);
            }
            hashNameToStringName.put(cppHashConstantName, cppNameConstantName);
        }
    }

    /**
     * Creates hash and name constants for element.
     * 
     * @param xsdElementName
     *            Element name as in XSD.
     * @param cppName
     *            C++ name of element.
     */
    protected void createElementConstants(String xsdElementName, String cppName) {
        String cppHashConstantName = Util.createElementNameHashIdentifier(cppName);
        if (!hashNameValueMap.containsKey(cppHashConstantName)) {
            String hash = Util.calculateHash(cppName);
            addHashConstant(cppHashConstantName, hash);
        }

        String cppHashConstantNameElementOnly = Util.createElementNameHashIdentifier(Util
                .replaceCharactersForbiddenInCppIdentifiers(xsdElementName));
        if (!hashNameValueMap.containsKey(cppHashConstantNameElementOnly)) {
            String hash = Util.calculateHash(xsdElementName);
            addHashConstant(cppHashConstantNameElementOnly, hash);
        }

        String cppNameConstantName = createElementNameIdentifier(cppName);
        if (!stringNameValueMap.containsKey(cppNameConstantName)) {
            String value = cppName;
            addStringConstant(cppNameConstantName, value);
        }

        String cppNameConstantNameElementOnly = createElementNameIdentifier(Util
                .replaceCharactersForbiddenInCppIdentifiers(xsdElementName));
        if (!stringNameValueMap.containsKey(cppNameConstantNameElementOnly)) {
            String value = xsdElementName;
            addStringConstant(cppNameConstantNameElementOnly, value);
        }
        hashNameToStringName.put(cppHashConstantName, cppNameConstantName);
        hashNameToStringName.put(cppHashConstantNameElementOnly, cppNameConstantNameElementOnly);
    }

    /**
     * Creates C++ identifier (-> constant name) of element name.
     * 
     * @param elemName
     *            Element name (as in XSD or C++) to get identifier for.
     * @return Identifier.
     */
    protected String createElementNameIdentifier(String elemName) {
        return "NAME_ELEMENT_" + Util.replaceCharactersForbiddenInCppIdentifiers(elemName).toUpperCase();
    }

    public Map<String, String> getHashNameToStringName() {
        return hashNameToStringName;
    }

    public SortedMap<String, String> getHashNameValueMap() {
        return hashNameValueMap;
    }

    public SortedMap<String, String> getStringNameValueMap() {
        return stringNameValueMap;
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

        String cppName = dataProvider.getElementNameMapping().get(element).cppElementName;
        createElementConstants(element.getName(), cppName);
        List<XSAttributeUse> attrs = Util.collectAttributeUses(element);
        createAttributesConstants(attrs, element);

        super.handleElement(element);

        getElementStack().pop();
        return true;
    }
}
