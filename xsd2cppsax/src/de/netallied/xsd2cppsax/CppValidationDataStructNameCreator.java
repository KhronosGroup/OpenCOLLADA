XXXXXAAAAAXXXXX
package de.netallied.xsd2cppsax;

import java.util.HashMap;
import java.util.Map;

import org.apache.xerces.xs.XSAttributeUse;
import org.apache.xerces.xs.XSComplexTypeDefinition;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSObject;
import org.apache.xerces.xs.XSObjectList;
import org.apache.xerces.xs.XSSimpleTypeDefinition;
import org.apache.xerces.xs.XSTypeDefinition;

/**
 * Creates names for C++ validation data structs and functions.
 * 
 */
public class CppValidationDataStructNameCreator extends AbstractStackBasedTraverser {

    /** Element to c++ element name mapping. */
    private Map<XSElementDeclaration, CppElementNameParentTypesPair> element2ElementName;

    /** Stores C++ validation function names printed for xs simple types. */
    private Map<XSSimpleTypeDefinition, String> xsSimpleType2validationFunctionName = new HashMap<XSSimpleTypeDefinition, String>();

    /** Stores C++ validation data struct names printed for xs complex types. */
    private Map<XSTypeDefinition, String> xsType2validationDataStructName = new HashMap<XSTypeDefinition, String>();

    /**
     * c-tor.
     * 
     * @param config
     *            Configuration.
     * @param completeElementUsage
     *            Element usage data.
     */
    public CppValidationDataStructNameCreator(Config config,
            Map<XSElementDeclaration, CppElementNameParentTypesPair> element2ElementName) {
        super(config);
        this.element2ElementName = element2ElementName;
    }

    /**
     * Creates name of C++ struct for complex type validation.
     * 
     * @param cppName
     *            C++ element name.
     * @param element
     *            XSD element using type.
     * @param type
     *            Type to validate.
     * @return C++ struct name.
     */
    protected String createComplexValidationDataStructName(String cppName, XSElementDeclaration element,
            XSTypeDefinition type) {
        if (!xsType2validationDataStructName.containsKey(type)) {
            String name = null;
            if (cppName != null) {
                name = cppName + config.getValidationDataStructSuffix();
            } else if (element != null) {
                name = element.getName() + config.getValidationDataStructSuffix();
            } else {
                name = "UNKNOWN_PARENT" + config.getValidationDataStructSuffix();
            }
            xsType2validationDataStructName.put(type, Util.replaceCharactersForbiddenInCppIdentifiers(name));
        }
        return xsType2validationDataStructName.get(type);
    }

    /**
     * Creates name for validation function of a simple type.
     * 
     * @param cppName
     *            C++ element name where type occurs.
     * @param element
     *            XSD element where type occurs.
     * @param type
     *            Type to create function name for.
     * @return Function name.
     */
    protected String createSimpleValidationFunctionName(String cppName, XSElementDeclaration element,
            XSSimpleTypeDefinition type) {
        if (!xsSimpleType2validationFunctionName.containsKey(type)) {
            String name = null;
            if (Util.hasSupportedFacets(type, config)) {
                if (type.getName() != null) {
                    name = config.getSimpleValidationFunctionPrefix()
                            + Util.replaceCharactersForbiddenInCppIdentifiers(type.getName());
                } else if (cppName != null) {
                    name = config.getSimpleValidationFunctionPrefix() + cppName;
                } else {
                    name = config.getSimpleValidationFunctionPrefix()
                            + Util.replaceCharactersForbiddenInCppIdentifiers(element.getName());
                }
            }
            xsSimpleType2validationFunctionName.put(type, name);

            XSSimpleTypeDefinition itemType = type.getItemType();
            if (itemType != null) {
                // TODO check if it is save to pass unchanged cppName here.
                createSimpleValidationFunctionName(cppName, element, itemType);
            }
        }
        return xsSimpleType2validationFunctionName.get(type);
    }

    /**
     * @return Generated simple type validation function names.
     */
    public Map<XSSimpleTypeDefinition, String> getXsSimpleType2validationFunctionName() {
        return xsSimpleType2validationFunctionName;
    }

    /**
     * @return Generated complex type validation data struct names.
     */
    public Map<XSTypeDefinition, String> getXsType2validationDataStructName() {
        return xsType2validationDataStructName;
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
            createComplexValidationDataStructName(element2ElementName.get(element).cppElementName, element, complexType);
            XSObjectList attributeUses = complexType.getAttributeUses();

            for (int i = 0; i < attributeUses.getLength(); i++) {
                XSObject item = attributeUses.item(i);
                if (item instanceof XSAttributeUse) {
                    XSAttributeUse attrUse = (XSAttributeUse) item;
                    XSSimpleTypeDefinition simpleType = Util.getType(attrUse);
                    createSimpleValidationFunctionName(element2ElementName.get(element).cppElementName, element,
                            simpleType);
                }
            }
        }
        XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(element.getTypeDefinition());
        if (simpleType != null) {
            if (Util.hasStreamingFacets(simpleType)) {
                createComplexValidationDataStructName(element2ElementName.get(element).cppElementName, element,
                        simpleType);
            }
            createSimpleValidationFunctionName(element2ElementName.get(element).cppElementName, element, simpleType);
        }

        super.handleElement(element);

        getElementStack().pop();
        return true;
    }
}
