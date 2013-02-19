/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.apache.xerces.xs.StringList;
import org.apache.xerces.xs.XSAttributeUse;
import org.apache.xerces.xs.XSComplexTypeDefinition;
import org.apache.xerces.xs.XSConstants;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSModel;
import org.apache.xerces.xs.XSModelGroup;
import org.apache.xerces.xs.XSNamespaceItemList;
import org.apache.xerces.xs.XSObject;
import org.apache.xerces.xs.XSObjectList;
import org.apache.xerces.xs.XSParticle;
import org.apache.xerces.xs.XSSimpleTypeDefinition;
import org.apache.xerces.xs.XSTerm;
import org.apache.xerces.xs.XSTypeDefinition;
import org.apache.xerces.xs.XSWildcard;

import de.netallied.xsd2cppsax.TypeMapping.TypeMap;

/**
 * Contains static utility methods.
 * 
 */
public class Util {

    /**
     * Calculates Hash.
     * 
     * @param str
     *            String to hash.
     * @return hash.
     */
    static public String calculateHash(String str) {
        long h = 0;
        long g;
        int pos = 0;

        while (pos < str.length()) {
            h = (h << 4) + str.charAt(pos++);
            if ((g = (h & 0xf0000000)) != 0)
                h ^= g >> 24;
            h &= ~g;
        }
        return String.valueOf(h);
    }

    /**
     * Collects attribute uses of given element.
     * 
     * @param element
     *            Element to collect attributes for.
     */
    public static List<XSAttributeUse> collectAttributeUses(XSElementDeclaration element) {
        XSTypeDefinition type = element.getTypeDefinition();
        if (type instanceof XSComplexTypeDefinition) {
            XSComplexTypeDefinition complexType = (XSComplexTypeDefinition) type;
            List<XSAttributeUse> attrList = objectListToList(complexType.getAttributeUses());
            return attrList;
        }
        return new ArrayList<XSAttributeUse>();
    }

    /**
     * Obtains pattern facet of simple type.
     */
    public static String collectPatternFacet(XSSimpleTypeDefinition simpleType) {
        String pattern = new String();
        StringList lexicalPatterns = simpleType.getLexicalPattern();

        // TODO check how to use multiple pattern values
        // http://www.w3.org/TR/xmlschema11-2/#rf-pattern
        // 4.3.4.2 XML Representation of pattern Schema Components

        // for (int i = 0; i < lexicalPatterns.getLength(); i++) {
        // pattern += lexicalPatterns.item(i);
        // }

        // for (int i = 0; i < lexicalPatterns.getLength(); i++) {
        // if (i != 0) {
        // // pattern = "|" + pattern;
        // pattern = "&(" + pattern + ")";
        // }
        // pattern += lexicalPatterns.item(i);
        // }

        // if (lexicalPatterns.getLength() > 0) {
        // pattern = lexicalPatterns.item(0);
        // }

        if (lexicalPatterns.getLength() > 0) {
            pattern = lexicalPatterns.item(lexicalPatterns.getLength() - 1);
        }

        return pattern;
    }

    /**
     * Counts how many elements with same name have same type, too.
     * 
     * @param elementUsage
     *            Element usage data of element to check.
     * @param element
     *            Element to check.
     * @return count.
     */
    public static int countElementsWithSameType(ElementUsage elementUsage, XSElementDeclaration element) {
        int elementsWithSameType = 0;
        for (XSElementDeclaration siblingElement : elementUsage.getElements()) {
            if (siblingElement.getTypeDefinition() == element.getTypeDefinition()) {
                elementsWithSameType++;
            }
        }
        return elementsWithSameType;
    }

    /**
     * Creates C++ identifier (-> constant name) of attribute name hash.
     * 
     * @param attrName
     *            Attribute Name to get identifier for.
     * @return Identifier.
     * @see CppConstantsCreator#createAttributeNameIdentifier(String)
     */
    public static String createAttributeNameHashIdentifier(String attrName) {
        // don't use uppercase for constant names because of a name clash in plm
        // xml
        // element: Locator
        // attrs: subtype and subType
        return "HASH_ATTRIBUTE_" + attrName/* .toUpperCase() */;
    }

    /**
     * Creates C++ name of constant to check if an attribute is present.
     * 
     * @param attrUse
     *            Attribute to create C++ present constant name for.
     */
    public static String createAttributePresentMaskName(XSAttributeUse attrUse, Config config) {
        return "ATTRIBUTE_" + getAttributeName(attrUse, config).toUpperCase() + "_PRESENT";
    }

    /**
     * Creates name of C++ attributes struct.
     * 
     * @param cppElementName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @return struct name.
     */
    public static String createAttributeStructName(String cppElementName, XSElementDeclaration element, Config config,
            Map<String, ElementUsage> completeElementUsage) {
        ElementUsage elementUsage = completeElementUsage.get(element.getName());
        int elementsWithSameType = countElementsWithSameType(elementUsage, element);
        if (elementsWithSameType == elementUsage.getElements().size())
            return Util.replaceCharactersForbiddenInCppIdentifiers(element.getName())
                    + config.getAttributeStructSuffix();
        return Util.replaceCharactersForbiddenInCppIdentifiers(cppElementName) + config.getAttributeStructSuffix();
    }

    /**
     * Creates name of begin element method
     * 
     * @param cppName
     *            C++ element name.
     * @return Method name.
     */
    public static String createBeginConvenienceMethodName(String cppName, Config config) {
        return config.getBeginMethodPrefix() + cppName;
    }

    /**
     * Creates name of internal used begin element method
     * 
     * @param cppName
     *            C++ element name.
     * @return Method name.
     */
    public static String createBeginInternalMethodName(String cppName, Config config) {
        return "_" + createBeginConvenienceMethodName(cppName, config);
    }

    /**
     * Creates name of a validation data struct member. Member is a child
     * element, validation data struct is for a parent element.
     * 
     * @param term
     *            XS Term to create member name for.
     * @return C++ struct member name.
     */
    public static String createComplexValidationDataStructMemberName(XSTerm term, Config config) {
        String returnValue = null;
        String nameFromConfig = config.getCppStructMemberNameMapping().get(term.getName());
        if (nameFromConfig != null) {
            returnValue = nameFromConfig;
        } else if (term instanceof XSWildcard) {
            returnValue = config.getWildcardValidationDataStructName();
        } else {
            returnValue = term.getName();
        }
        return replaceCharactersForbiddenInCppIdentifiers(returnValue);

    }

    /**
     * Creates method name of internal data method.
     * 
     * @param cppName
     *            C++ name of element.
     * @return Method name.
     */
    public static String createDataInternalMethodName(String cppName) {
        return "_data__" + cppName;
    }

    /**
     * Creates C++ identifier (-> constant name) of element name hash.
     * 
     * @param elemName
     *            Element name (XSD or C++) to get identifier for.
     * @return Identifier.
     */
    static public String createElementNameHashIdentifier(String elemName) {
        return "HASH_ELEMENT_" + replaceCharactersForbiddenInCppIdentifiers(elemName).toUpperCase();
    }

    /**
     * Creates method name of C++ end element method.
     * 
     * @param cppName
     *            C++ element name.
     * @return Method name.
     */
    public static String createEndConvenienceMethodName(String cppName, Config config) {
        return config.getEndMethodPrefix() + cppName;
    }

    /**
     * Creates name of internal used end element method
     * 
     * @param cppName
     *            C++ element name.
     * @return Method name.
     */
    public static String createEndInternalMethodName(String cppName, Config config) {
        return "_" + createEndConvenienceMethodName(cppName, config);
    }

    /**
     * Creates name of enum count value.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     */
    public static String createEnumCountName(String cppEnumTypeName, Config config) {
        return cppEnumTypeName + config.getElementNameDelimiter() + config.getEnumCountName();
    }

    /**
     * Creates name of enum convenience function characterData2EnumData.
     * 
     * @param cppEnumTypeName
     *            C++ type name of enum.
     * @return C++ function name.
     */
    public static String createEnumFuncNameCharData(String cppEnumTypeName, Config config) {
        return config.getEnumFuncPrefixCharData() + cppEnumTypeName;
    }

    /**
     * Creates name of enum convenience function dataEnumEnd.
     * 
     * @param cppEnumTypeName
     *            C++ type name of enum.
     * @return C++ function name.
     */
    public static String createEnumFuncNameDataEnd(String cppEnumTypeName, Config config) {
        return config.getEnumFuncPrefixDataEnd() + cppEnumTypeName;
    }

    /**
     * Creates name of enum convenience function toEnumDataPrefix.
     * 
     * @param cppEnumTypeName
     *            C++ type name of enum.
     * @return C++ function name.
     */
    public static String createEnumFuncNameDataPrefix(String cppEnumTypeName, Config config) {
        return config.getEnumFuncPrefixDataPrefix() + cppEnumTypeName;
    }

    /**
     * Creates name of enum convenience function toEnum.
     * 
     * @param cppEnumTypeName
     *            C++ type name of enum.
     * @return C++ function name.
     */
    public static String createEnumFuncNameToEnum(String cppEnumTypeName, Config config) {
        return config.getEnumFuncPrefixToEnum() + cppEnumTypeName;
    }

    /**
     * Creates name of enum map.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     */
    public static String createEnumMapName(String cppEnumTypeName, Config config) {
        return cppEnumTypeName + config.getEnumMapNameSuffix();
    }

    /**
     * Creates name of enum NOT_PRESENT value.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     */
    public static String createEnumNotPresentName(String cppEnumTypeName, Config config) {
        return cppEnumTypeName + config.getElementNameDelimiter() + config.getEnumNotPresentName();
    }

    /**
     * Creates C++ name of one enum value.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     * @param enumValues
     *            Enum values to process.
     * @param enumValue
     *            Enum value to create name for.
     * @param type
     *            XSD type of enum.
     */
    public static String createEnumValueName(String cppEnumTypeName, List<String> enumValues, int enumValue,
            XSSimpleTypeDefinition type, Config config) {
        String enumValueString = null;
        if (isFloatType(type, config)) {
            double tmp = Double.parseDouble(enumValues.get(enumValue));
            enumValueString = String.valueOf(tmp);
        } else {
            enumValueString = enumValues.get(enumValue);
        }
        return cppEnumTypeName + config.getElementNameDelimiter()
                + Util.replaceCharactersForbiddenInCppIdentifiers(enumValueString);
    }

    /**
     * Creates method name of freeAttributes method.
     * 
     * @param cppName
     *            C++ name of element.
     * @return Method name.
     */
    public static String createFreeAttributesMethodName(String cppName) {
        return "_freeAttributes__" + cppName;
    }

    /**
     * Creates C++ Constant name for a xml namespace.
     * 
     * @param namespace
     *            Namespace to create constant for.
     * @param baseName
     *            Part of name depending on constant's type.
     * @param config
     *            Config.
     * @return C++ name.
     */
    protected static String createNamespaceConstantName(String namespace, String baseName, Config config) {
        String nsPrefix = config.getXsNamespaceMapping().get(namespace);
        if (nsPrefix != null) {
            baseName += nsPrefix;
        } else {
            baseName += namespace;
        }
        return replaceCharactersForbiddenInCppIdentifiers(baseName);

    }

    /**
     * Creates C++ hash constant name for a xml namespace.
     * 
     * @param namespace
     *            Namespace to create constant for.
     * @param config
     *            Config.
     * @return C++ name.
     */
    public static String createNamespaceHashConstantName(String namespace, Config config) {
        String name = "HASH_NAMESPACE_";
        return createNamespaceConstantName(namespace, name, config);
    }

    /**
     * Creates C++ string constant name for a xml namespace.
     * 
     * @param namespace
     *            Namespace to create constant for.
     * @param config
     *            Config.
     * @return C++ name.
     */
    public static String createNamespaceStringConstantName(String namespace, Config config) {
        String name = "NAME_NAMESPACE_";
        return createNamespaceConstantName(namespace, name, config);
    }

    /**
     * Creates method name of preBegin method.
     * 
     * @param cppName
     *            C++ name of element.
     * @return Method name.
     */
    public static String createPreBeginMethodName(String cppName) {
        return "_preBegin__" + cppName;
    }

    /**
     * Creates method name of preEnd method.
     * 
     * @param cppName
     *            C++ name of element.
     * @return Method name.
     */
    public static String createPreEndMethodName(String cppName) {
        return "_preEnd__" + cppName;
    }

    /**
     * Creates C++ function name for validation function which validates data at
     * end of stream.
     * 
     * @param functionName
     *            Base validation function name of simple type.
     * @return Function name.
     */
    public static String createSimpleValidationStreamEndFunctionName(String functionName, Config config) {
        return functionName + config.getSimpleValidationFunctionStreamEndSuffix();
    }

    /**
     * Creates C++ function name for validation function which validates data in
     * stream.
     * 
     * @param functionName
     *            Base validation function name of simple type.
     * @return Function name.
     */
    public static String createSimpleValidationStreamFunctionName(String functionName, Config config) {
        return functionName + config.getSimpleValidationFunctionStreamSuffix();
    }

    /**
     * Creates name of union convenience function toUnion.
     * 
     * @param cppUnionTypeName
     *            C++ type name of union.
     * @return C++ function name.
     */
    public static String createUnionFuncNameToUnion(String cppUnionTypeName, Config config) {
        return config.getUnionFuncPrefixToUnion() + cppUnionTypeName;
    }

    /**
     * Creates name of union convenience function toUnionPrefix.
     * 
     * @param cppUnionTypeName
     *            C++ type name of union.
     * @return C++ function name.
     */
    public static String createUnionFuncNameToUnionPrefix(String cppUnionTypeName, Config config) {
        return config.getUnionFuncPrefixToUnionPrefix() + cppUnionTypeName;
    }

    /**
     * Creates method name of validateBegin method.
     * 
     * @param cppName
     *            C++ name of element.
     * @return Method name.
     */
    public static String createValidateBeginMethodName(String cppName) {
        return "_validateBegin__" + cppName;
    }

    /**
     * Creates method name of validateEnd method.
     * 
     * @param cppName
     *            C++ name of element.
     * @return Method name.
     */
    public static String createValidateEndMethodName(String cppName) {
        return "_validateEnd__" + cppName;
    }

    /**
     * Finds build in type given type is derived from.
     * 
     * @param type
     *            Type to find base type for.
     * @return Base Type.
     */
    static public XSSimpleTypeDefinition findBuildinBaseType(XSSimpleTypeDefinition type, Config config) {
        if (type == null) {
            return null;
        }
        Map<String, TypeMap> typeMapping = config.getTypeMapping();
        String namespace = type.getNamespace();
        String xsNamespace = config.getXSNamespace();
        if (typeMapping.containsKey(type.getName()) && namespace.equals(xsNamespace)) {
            return type;
        } else {
            XSTypeDefinition baseType = type.getBaseType();
            XSSimpleTypeDefinition simpleBaseType = findSimpleTypeDefinition(baseType);
            if (simpleBaseType != null) {
                return findBuildinBaseType(simpleBaseType, config);
            } else {
                return null;
            }
        }
    }

    /**
     * Finds C++ type as string. Takes care of simple and complex type, base
     * types and variety. When variety is list, the item type is returned.
     * 
     * @note {@link TemplateEngine#fillInTemplate(String, String, String, String, XSTypeDefinition)}
     *       has a copy of this code, as it requires temporary variables.
     * @note {@link Generator#createDataConvenienceParameterList(XSTypeDefinition)}
     *       does something similar, too.
     * @param type
     *            XSD type to find C++ type for.
     * @return C++ type.
     */
    static public String findCorrectCppAtomicType(XSTypeDefinition type, Config config) {
        XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(type);
        Variety variety = Util.findVariety(simpleType);
        if (variety == Variety.LIST) {
            simpleType = Util.findListItemType(simpleType);
        }
        String xsdType = Util.findXSDSimpleTypeString(simpleType, config);

        return config.getTypeMapping().get(xsdType).getAttrAtomicType();
    }

    /**
     * @param type
     *            List type to find item type for.
     * @return Item type of given list type.
     */
    static public XSSimpleTypeDefinition findListItemType(XSSimpleTypeDefinition type) {
        return type != null ? type.getItemType() : null;
    }

    /**
     * Finds simple type. If given type is simple, it is returned. If given type
     * is complex it's content type is returned.
     * 
     * @param typeDefi
     *            Type to find simple type for.
     * @return Simple type or null.
     */
    static public XSSimpleTypeDefinition findSimpleTypeDefinition(XSTypeDefinition typeDefi) {
        if (typeDefi instanceof XSSimpleTypeDefinition) {
            return (XSSimpleTypeDefinition) typeDefi;
        } else if (typeDefi instanceof XSComplexTypeDefinition) {
            XSComplexTypeDefinition complexType = (XSComplexTypeDefinition) typeDefi;
            if (complexType.getSimpleType() == null
                    && complexType.getContentType() == XSComplexTypeDefinition.CONTENTTYPE_MIXED) {
                return XSFactory.createXSAnyType();
            }
            if (complexType.getSimpleType() != null) {
                return complexType.getSimpleType();
            } else {
                return findSimpleTypeDefinition(complexType.getBaseType());
            }
        }
        return null;
    }

    /**
     * Finds target namespace of given model.
     * 
     * @param model
     *            Model to find target namespace for.
     * @return target namespace.
     */
    public static String findTargetNamespace(XSModel model) {
        XSNamespaceItemList namespaceItems = model.getNamespaceItems();
        if (namespaceItems.getLength() > 0)
            return namespaceItems.item(0).getSchemaNamespace();
        return null;
    }

    /**
     * Finds out variety of given type.
     * 
     * @param type
     *            Type to find variety for.
     * @return Variety.
     */
    static public Variety findVariety(XSSimpleTypeDefinition type) {
        if (type == null) {
            return Variety.ATOMIC;
        }
        switch (type.getVariety()) {
        case XSSimpleTypeDefinition.VARIETY_LIST:
            return Variety.LIST;
        case XSSimpleTypeDefinition.VARIETY_UNION:
            return Variety.UNION;
        case XSSimpleTypeDefinition.VARIETY_ATOMIC:
        default:
            return Variety.ATOMIC;
        }
    }

    /**
     * Finds string representing xsd type. Takes care of base types. Result can
     * be used to get C++ types or type conversions from config.
     * 
     * @param typeDefi
     *            Type to find string for.
     * @return String representing type.
     */
    static public String findXSDSimpleTypeString(XSSimpleTypeDefinition simpleType, Config config) {
        if (simpleType == null) {
            // TODO check what happens here
            // System.err.println("*** Try to find type for null");
            return Constants.DEFAULT_XSD_TYPE;
        }
        XSSimpleTypeDefinition baseType = findBuildinBaseType(simpleType, config);
        if (baseType != null) {
            return baseType.getName();
        } else {
            // TODO check what happens here
            // System.err.println("*** Could not find base type for: " +
            // simpleType.getName());
            return Constants.DEFAULT_XSD_TYPE;
        }
    }

    /**
     * Finds attribute name of a attribute use. Takes care of C++ keywords.
     */
    public static String getAttributeName(XSAttributeUse attrUse, Config config) {
        String tmpName = attrUse.getAttrDeclaration().getName();
        if (config != null) {
            Map<String, String> attributeNameMapping = config.getCppStructMemberNameMapping();
            if (attributeNameMapping.containsKey(tmpName)) {
                tmpName = attributeNameMapping.get(tmpName);
            }
        }
        return replaceCharactersForbiddenInCppIdentifiers(tmpName);
    }

    /**
     * Returns attribute name as in XSD (may clash with a C++ keyword).
     */
    public static String getAttributeOriginalName(XSAttributeUse attrUse, Config config) {
        return attrUse.getAttrDeclaration().getName();
    }

    /**
     * If given type is a complex type it is returned as such. If not
     * <code>null</code> is returned.
     * 
     * @param type
     *            Type to check.
     * @return Complex type or null.
     */
    public static XSComplexTypeDefinition getComplexType(XSTypeDefinition type) {

        // ////////////////////////////////////////////////////////////////////
        // old version of this method:
        // public XSComplexTypeDefinition getComplexType(XSTypeDefinition type)
        // throws ClassCastException {
        // return (XSComplexTypeDefinition) type;
        // }
        // That was used in early versions of max/maya plugins
        // but it caused generation to abort too early.
        // ////////////////////////////////////////////////////////////////////

        if (type instanceof XSComplexTypeDefinition)
            return (XSComplexTypeDefinition) type;
        return null;
    }

    /**
     * Find XSD type of given attribute.
     * 
     * @param attrUse
     *            Attribute to find type for.
     * @return Type of attribute.
     */
    public static XSSimpleTypeDefinition getType(XSAttributeUse attrUse) {
        return attrUse.getAttrDeclaration().getTypeDefinition();
    }

    /**
     * Finds out if given attribute has a default value.
     */
    public static boolean hasDefaultValue(XSAttributeUse attrUse) {
        short constraintType = attrUse.getConstraintType();
        if (constraintType == XSConstants.VC_DEFAULT || constraintType == XSConstants.VC_FIXED) {
            return true;
        }
        return false;
    }

    /**
     * Finds out if given type is an enum.
     * 
     * @param simpleType
     *            Type to check.
     * @return True if type is enum.
     */
    public static boolean hasFacetEnum(XSSimpleTypeDefinition simpleType) {
        return simpleType == null ? false
                : (simpleType.getDefinedFacets() & XSSimpleTypeDefinition.FACET_ENUMERATION) == XSSimpleTypeDefinition.FACET_ENUMERATION;
    }

    /**
     * Checks if given type has facets which need accumulation of character data
     * length.
     * 
     * @param simpleType
     *            Type to check.
     * @return True if type has facets which need to be checked in stream.
     */
    static public boolean hasStreamingFacets(XSSimpleTypeDefinition simpleType) {
        if (simpleType == null) {
            return false;
        }
        short facets = simpleType.getDefinedFacets();
        if ((facets & XSSimpleTypeDefinition.FACET_LENGTH) == XSSimpleTypeDefinition.FACET_LENGTH) {
            return true;
        }
        if ((facets & XSSimpleTypeDefinition.FACET_MINLENGTH) == XSSimpleTypeDefinition.FACET_MINLENGTH) {
            return true;
        }
        if ((facets & XSSimpleTypeDefinition.FACET_MAXLENGTH) == XSSimpleTypeDefinition.FACET_MAXLENGTH) {
            return true;
        }

        return false;
    }

    /**
     * Finds out if given type has facets which are supported.
     * 
     * @return True if type can be validated.
     */
    static public boolean hasSupportedFacets(XSSimpleTypeDefinition simpleType, Config config) {
        short facets = simpleType.getDefinedFacets();
        if ((facets & XSSimpleTypeDefinition.FACET_WHITESPACE) == XSSimpleTypeDefinition.FACET_WHITESPACE) {
            facets -= XSSimpleTypeDefinition.FACET_WHITESPACE;
        }
        if ((facets & XSSimpleTypeDefinition.FACET_TOTALDIGITS) == XSSimpleTypeDefinition.FACET_TOTALDIGITS) {
            facets -= XSSimpleTypeDefinition.FACET_TOTALDIGITS;
        }
        if ((facets & XSSimpleTypeDefinition.FACET_FRACTIONDIGITS) == XSSimpleTypeDefinition.FACET_FRACTIONDIGITS) {
            facets -= XSSimpleTypeDefinition.FACET_FRACTIONDIGITS;
        }

        if ((facets & XSSimpleTypeDefinition.FACET_MAXINCLUSIVE) == XSSimpleTypeDefinition.FACET_MAXINCLUSIVE) {
            String cppType = Util.findCorrectCppAtomicType(simpleType, config);
            String maxValue = config.getBuiltInTypeMaxValues().get(cppType);
            if (maxValue != null) {
                if (maxValue.equals(simpleType.getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MAXINCLUSIVE))) {
                    facets -= XSSimpleTypeDefinition.FACET_MAXINCLUSIVE;
                }
            }
        }
        if ((facets & XSSimpleTypeDefinition.FACET_MININCLUSIVE) == XSSimpleTypeDefinition.FACET_MININCLUSIVE) {
            String cppType = Util.findCorrectCppAtomicType(simpleType, config);
            String minValue = config.getBuiltInTypeMinValues().get(cppType);
            if (minValue != null) {
                if (minValue.equals(simpleType.getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MININCLUSIVE))) {
                    facets -= XSSimpleTypeDefinition.FACET_MININCLUSIVE;
                }
            }
        }

        if (!isFacetPatternSupported(simpleType, config)) {
            if ((facets & XSSimpleTypeDefinition.FACET_PATTERN) == XSSimpleTypeDefinition.FACET_PATTERN) {
                facets -= XSSimpleTypeDefinition.FACET_PATTERN;
            }
        }

        return facets != XSSimpleTypeDefinition.FACET_NONE;
    }

    /**
     * Finds out whether an attribute must be initialized after the memcpy call.
     * 
     * @param attrUse
     *            Attribute to check.
     * @param config
     *            Config.
     * @return True if initialization is required, false otherwise.
     */
    public static boolean isAttributeInitializationRequired(XSAttributeUse attrUse, Config config) {
        XSSimpleTypeDefinition type = getType(attrUse);
        Variety variety = findVariety(type);
        if (variety == Variety.LIST || variety == Variety.UNION) {
            return true;
        } else {
            if (hasFacetEnum(type) || isStringType(type, config) || isNumericType(type, config)
                    || isBoolType(type, config)) {
                return false;
            } else {
                // e.g. URI
                return true;
            }
        }
    }

    /**
     * Finds out if given type maps to C++ bool.
     * 
     * @param type
     *            Type to check.
     * @param config
     *            Configuration.
     * @return True if type maps to C++ bool.
     */
    public static boolean isBoolType(XSSimpleTypeDefinition type, Config config) {
        String cppType = Util.findCorrectCppAtomicType(type, config);
        return cppType.equals("bool");
    }

    /**
     * Finds out if given XSD type maps to C++ double.
     * 
     * @see #isFloatType(XSSimpleTypeDefinition, Config)
     */
    public static boolean isDouble(XSSimpleTypeDefinition type, Config config) {
        String cppType = Util.findCorrectCppAtomicType(type, config);
        return cppType.equals("double");
    }

    /**
     * Finds out if facet pattern is supported for given type.
     */
    public static boolean isFacetPatternSupported(XSSimpleTypeDefinition simpleType, Config config) {
        Variety variety = findVariety(simpleType);
        if (variety != Variety.ATOMIC) {
            return false;
        }
        short facets = simpleType.getDefinedFacets();
        if ((facets & XSSimpleTypeDefinition.FACET_PATTERN) != XSSimpleTypeDefinition.FACET_PATTERN) {
            return false;
        }
        if (hasFacetEnum(simpleType)) {
            return false;
        }
        if (!isStringType(simpleType, config)) {
            return false;
        } else {
            String pattern = collectPatternFacet(simpleType);
            if (pattern.length() == 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * Finds out if given XSD type maps to C++ float.
     * 
     * @see #isFloatType(XSSimpleTypeDefinition, Config)
     */
    public static boolean isFloat(XSSimpleTypeDefinition type, Config config) {
        String cppType = Util.findCorrectCppAtomicType(type, config);
        return cppType.equals("float");
    }

    /**
     * Finds out if given type is of float kind (C++ float or double). If given
     * type uses variety list, it's itemtype is used.
     * 
     * @param type
     *            Type to check
     * @return True if type is of float kind.
     */
    public static boolean isFloatType(XSSimpleTypeDefinition type, Config config) {
        String cppType = Util.findCorrectCppAtomicType(type, config);
        return cppType.equals("float") || cppType.equals("double");

    }

    /**
     * Finds out if given type is numeric. Works only for variety atomic.
     */
    static public boolean isNumericType(XSSimpleTypeDefinition type, Config config) {
        if (type != null && type.getNamespace() != null) {
            if (type.getNamespace().equals(config.getXSNamespace()) && type.getName().equals("hexBinary")) {
                return true;
            }
        }
        return type == null ? false : type.getNumeric();
    }

    /**
     * Special stream end validation is required for list types with facets
     * length or minLength.
     */
    public static boolean isSpecialStreamEndValidationRequired(XSSimpleTypeDefinition simpleType) {
        Variety variety = Util.findVariety(simpleType);
        if (variety == Variety.LIST) {
            short facets = simpleType.getDefinedFacets();
            if ((facets & XSSimpleTypeDefinition.FACET_LENGTH) == XSSimpleTypeDefinition.FACET_LENGTH) {
                return true;
            }
            if ((facets & XSSimpleTypeDefinition.FACET_MINLENGTH) == XSSimpleTypeDefinition.FACET_MINLENGTH) {
                return true;
            }
        }
        return false;
    }

    /**
     * Finds out if given type is of string kind. If given type uses variety
     * list, it's itemtype is used.
     * 
     * @param type
     *            Type to check
     * @return True if type is of string kind.
     */
    public static boolean isStringType(XSSimpleTypeDefinition type, Config config) {
        String cppType = Util.findCorrectCppAtomicType(type, config);
        return cppType.equals(Constants.DEFAULT_CPP_TYPE);
    }

    /**
     * Finds out if a member for unknown attributes in C++ AttributeData struct
     * is required for given type.
     * 
     * @param type
     *            XSD type to check.
     * @return True if unknown attributes member is required.
     */
    public static boolean isUnknownAttributesMemberRequired(XSTypeDefinition type) {
        if (type instanceof XSComplexTypeDefinition) {
            return ((XSComplexTypeDefinition) type).getAttributeWildcard() != null;
        }
        return false;
    }

    /**
     * Finds out if given type may have char data.
     */
    public static boolean mayHaveCharData(XSComplexTypeDefinition type, Config config) {
        short contentType = type.getContentType();
        if (contentType == XSComplexTypeDefinition.CONTENTTYPE_SIMPLE
                || contentType == XSComplexTypeDefinition.CONTENTTYPE_MIXED) {
            return true;
        }
        if (type.getBaseType() != null) {
            if (Constants.XSD_ANYTYPE_NAME.equals(type.getBaseType().getName())
                    && config.getXSNamespace().equals(type.getBaseType().getNamespace())) {
                return false;
            }
            return mayHaveCharData(type.getBaseType(), config);
        }
        return false;
    }

    /**
     * Finds out if given type may have char data.
     */
    public static boolean mayHaveCharData(XSTypeDefinition type, Config config) {
        if (type instanceof XSComplexTypeDefinition) {
            return mayHaveCharData((XSComplexTypeDefinition) type, config);
        } else if (type instanceof XSSimpleTypeDefinition) {
            return true;
        }
        return false;
    }

    /**
     * Finds out if given type may have child elements.
     */
    public static boolean mayHaveChildElements(XSComplexTypeDefinition type, Config config) {
        if (type == null) {
            return false;
        }
        short contentType = type.getContentType();
        if (contentType == XSComplexTypeDefinition.CONTENTTYPE_ELEMENT
                || contentType == XSComplexTypeDefinition.CONTENTTYPE_MIXED) {
            return true;
        }
        if (type.getBaseType() != null) {
            if (Constants.XSD_ANYTYPE_NAME.equals(type.getBaseType().getName())
                    && config.getXSNamespace().equals(type.getBaseType().getNamespace())) {
                return false;
            }
            return mayHaveChildElements(type.getBaseType(), config);
        }
        return false;
    }

    /**
     * Finds out if given type may have child elements.
     */
    public static boolean mayHaveChildElements(XSTypeDefinition type, Config config) {
        if (type instanceof XSComplexTypeDefinition) {
            return mayHaveChildElements((XSComplexTypeDefinition) type, config);
        } else {
            return false;
        }
    }

    /**
     * Converts general {@link XSObjectList} to a {@link List}.
     * 
     * @param objList
     *            List to covert
     * @return Converted list.
     */
    @SuppressWarnings("unchecked")
    public static <T extends XSObject> List<T> objectListToList(XSObjectList objList) {
        List<T> list = new ArrayList<T>();
        for (int i = 0; i < objList.getLength(); i++) {
            list.add((T) objList.item(i));
        }
        return list;
    }

    /**
     * Finds out if it is necessary to crate a C++ present mask for given
     * attribute.
     */
    public static boolean presentMaskRequired(XSAttributeUse attrUse, Config config) {
        XSSimpleTypeDefinition type = getType(attrUse);
        Variety variety = findVariety(type);
        if (variety == Variety.LIST || variety == Variety.UNION) {
            return true;
        } else {
            if (hasFacetEnum(type)) {
                return false;
            } else if (isNumericType(type, config) || isBoolType(type, config)) {
                if (hasDefaultValue(attrUse)) {
                    return false;
                } else {
                    return true;
                }
            } else if (isStringType(type, config)) {
                return false;
            } else {
                return true;
            }
        }
    }

    /**
     * Prints an entry of map containing element hash to namespace hash.
     * 
     * @param mapVariableName
     *            Name of C++ map.
     * @param elementHash
     *            Hash constant or hash itself of element.
     * @param element
     *            Element, needed to find out namespace.
     * @param stream
     *            Stream to print map entry to.
     * @param config
     *            Config.
     */
    public static void printElementToNamespaceMapEntry(String mapVariableName, String elementHash,
            XSElementDeclaration element, PrintStream stream, Config config) {
        stream.print(mapVariableName + "[" + elementHash + "] = ");
        String namespace = element.getNamespace();
        String namespaceHash = null;
        if (namespace != null) {
            namespaceHash = createNamespaceHashConstantName(namespace, config);
        } else {
            namespaceHash = "0";
        }

        stream.println(namespaceHash + ";");
    }

    /**
     * Prints entry in function map for element.
     * 
     * @param hashID
     *            C++ constant for hash.
     * @param cppElementName
     *            C++ element name.
     */
    public static void printFunctionMapEntry(String mapVariableName, String hashID, String cppElementName,
            PrintStream stream, Config config, boolean printFunctionStructNamespace) {
        stream.print(mapVariableName + "[" + hashID + "] = ");
        if (printFunctionStructNamespace) {
            stream.print(config.getClassNamePrivate() + "::");
        }
        stream.print("FunctionStruct" + "(");

        printFunctionMapEntryAddressStart(stream, config);
        stream.print(createBeginInternalMethodName(cppElementName, config) + ", ");
        printFunctionMapEntryAddressStart(stream, config);
        stream.print(createDataInternalMethodName(cppElementName) + ", ");
        printFunctionMapEntryAddressStart(stream, config);
        stream.print(createEndInternalMethodName(cppElementName, config) + ", ");
        printFunctionMapEntryAddressStart(stream, config);
        stream.print(createPreBeginMethodName(cppElementName) + ", ");
        printFunctionMapEntryAddressStart(stream, config);
        stream.print(createPreEndMethodName(cppElementName) + ", ");
        printFunctionMapEntryAddressStart(stream, config);
        stream.print(createFreeAttributesMethodName(cppElementName));

        stream.println(");");
    }

    /**
     * Prints beginning of address assignment of function map entry.
     */
    protected static void printFunctionMapEntryAddressStart(PrintStream stream, Config config) {
        stream.print("&" + config.getClassNamePrivate() + "::");
    }

    /**
     * Replaces characters in identifiers which are not allowed in C++.
     * 
     * @param identifier
     *            XSD identifier to check.
     * @return Identifier valid in C++.
     */
    static public String replaceCharactersForbiddenInCppIdentifiers(String identifier) {
        if (identifier.contains(".")) {
            identifier = identifier.replace(".", "_");
        }
        if (identifier.contains(":")) {
            identifier = identifier.replace(":", "_");
        }
        if (identifier.contains("-")) {
            identifier = identifier.replace("-", "_M_");
        }
        if (identifier.contains("+")) {
            identifier = identifier.replace("+", "_P_");
        }
        if (identifier.contains("*")) {
            identifier = identifier.replace("*", "_");
        }
        if (identifier.contains("/")) {
            identifier = identifier.replace("/", "_");
        }
        if (identifier.contains(",")) {
            identifier = identifier.replace(",", "_");
        }
        if (identifier.contains(" ")) {
            identifier = identifier.replace(" ", "_");
        }
        return identifier;
    }

    /**
     * Checks if given string contains one environment variable in the form
     * ${variable_name} and replaces it.
     * 
     * @param str
     *            String to check.
     * @return String with replaced environment variable.
     */
    public static String replaceEnvVar(String str) {
        if (str.contains("${")) {
            int envVarStartIndex = str.indexOf("${");
            int envVarEndIndex = str.indexOf('}', envVarStartIndex);
            String envVarName = str.substring(envVarStartIndex + 2, envVarEndIndex);
            String envVarValue = System.getenv().get(envVarName);
            if (envVarValue != null) {
                str = str.replace("${" + envVarName + "}", envVarValue);
            }
        }
        return str;
    }

    /**
     * Splits particles of a model group with compositor choice.
     * 
     * @param modelGroup
     *            Model group to split.
     * @param particle
     *            Current particle.
     * @return List of siblings.
     */
    public static List<XSParticle> splitParticlesForChoice(XSModelGroup modelGroup, XSParticle particle) {
        List<XSParticle> siblings = new ArrayList<XSParticle>();
        for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
            XSObject item = modelGroup.getParticles().item(i);
            if (item instanceof XSParticle) {
                XSParticle currentParticle = (XSParticle) item;
                if (currentParticle != particle) {
                    siblings.add(currentParticle);
                }
            }
        }
        return siblings;
    }

    /**
     * Splits particles of a model group with compositor sequence.
     * 
     * @param modelGroup
     *            Model group to split.
     * @param particle
     *            Current particle.
     * @param previousSiblings
     *            Output parameter.
     * @param followingSiblings
     *            Output parameter.
     */
    public static void splitParticlesForSequence(XSModelGroup modelGroup, XSParticle particle,
            List<XSParticle> previousSiblings, List<XSParticle> followingSiblings) {
        boolean foundSelf = false;
        for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
            XSObject item = modelGroup.getParticles().item(i);
            if (item instanceof XSParticle) {
                XSParticle currentParticle = (XSParticle) item;
                if (!foundSelf) {
                    if (currentParticle == particle) {
                        foundSelf = true;
                    } else {
                        previousSiblings.add(currentParticle);
                    }
                } else {
                    followingSiblings.add(currentParticle);
                }
            }
        }
    }

    /**
     * Converts StringList to List<String>.
     */
    public static List<String> stringListToList(StringList stringList) {
        List<String> list = new ArrayList<String>();
        for (int i = 0; i < stringList.getLength(); i++) {
            list.add(stringList.item(i));
        }
        return list;
    }

    /**
     * Checks if attribute is a XML special case and adds a namespace prefix if
     * necessary.
     * 
     * @param elementNamespace
     *            Namespace of element attribute is used in.
     * @param attr
     *            Attribute.
     * @param attrName
     *            Attribute name to use. May contain characters illegal in C++.
     */
    static public String updateAttributeNameWithNamespace(String elementNamespace, XSAttributeUse attr, String attrName) {
        String attrStringValue = attrName;
        String attrNamespace = attr.getAttrDeclaration().getNamespace();
        if (Constants.XML_BASE_NAMESPACE.equals(attrNamespace)) {
            if (!attrNamespace.equals(elementNamespace)) {
                attrStringValue = Constants.XML_BASE_NAMESPACE_PREFIX + ":" + attrName;
            }
        }
        return attrStringValue;
    }
}
