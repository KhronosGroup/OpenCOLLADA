/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.TypeMapping;

/**
 * Factory which creates type mappings for XSD string types. Basically defines
 * one mapping for C++ strings and uses that for other XSD types. Just anyURI
 * has it's own mapping for variety atomic.
 * 
 * TODO move type specific code templates in one (or multiple) config file(s).
 * 
 */
public abstract class TypeMapFactoryString extends TypeMapFactoryNumeric implements ITypeMapFactory {

    public TypeMap createDefaultTypeMapAnyAtomicType() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("anyAtomicType");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapAnySimpleType() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("anySimpleType");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapAnyType() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("anyType");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapAnyURI() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("anyURI");
        typeMap.setToString(".getURIString().c_str()");
        typeMap.setInitialize("COLLADABU::URI(\"#init_value#\")");
        typeMap.setInitializePreAtomic("bool failed = false;#nl##ind#");

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toURI(&attributeValue, failed);");
        typeMap.setAttrAtomicType("COLLADABU::URI");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");

        // use list handling of xs:string
        // because of deep copy problem in characterData2Data and
        // characterData2List
        // it is the line:
        // typedBuffer[dataBufferIndex] = dataValue

        // typeMap
        // .setAttrListTypeConversionItemValidation(TypeMapConstants.
        // getDEFAULT_ATTR_LIST_XSD_2_CPP_rhs()
        // +
        // "characterData2URIList(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);"
        // );
        // typeMap.setAttrListTypeConversionNoItemValidation(TypeMapConstants.
        // getDEFAULT_ATTR_LIST_XSD_2_CPP_rhs()
        // +
        // "characterData2URIList(attributeValue, attributeData->#attrName#);");
        // typeMap.setAttrListType("XSList<COLLADABU::URI>");
        // typeMap.setAttrListTypePostConversion(typeMap.
        // getAttrAtomicTypePostConversion());
        // typeMap.setAttrListTypePreConversion(typeMap.
        // getAttrAtomicTypePreConversion());

        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toURI((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");

        // use list handling of xs:string
        // typeMap.setDataListEnd(
        // "return uriDataEnd( &#className#::#dataMethod# );");
        // typeMap
        // .setDataListEndValidation(
        // "bool returnValue = uriDataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );"
        // );
        // typeMap.setDataListTypeConversion("return characterData2URIData"
        // + "#tm_default_data_list_xsd2cpp_lhs#");
        // typeMap.setDataListTypeConversionValidation(
        // "return characterData2URIData"
        // + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        // typeMap.setDataListType("const COLLADABU::URI*");

        // reuse enum conversion from xs:string

        return typeMap;
    }

    public TypeMap createDefaultTypeMapENTITIES() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("ENTITIES");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapENTITY() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("ENTITY");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapID() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("ID");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapIDREF() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("IDREF");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapIDREFS() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("IDREFS");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapLanguage() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("language");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapName() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("Name");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapNCName() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("NCName");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapNMTOKEN() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("NMTOKEN");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapNMTOKENS() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("NMTOKENS");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapNormalizedString() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("normalizedString");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapNOTATION() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("NOTATION");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapQName() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("QName");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapString() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType("string");

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#" + "attributeValue;");
        typeMap.setAttrAtomicType("const ParserChar*");
        typeMap.setAttrAtomicTypePostConversion("#simple_type_validation#");
        typeMap.setAttrAtomicTypePreConversion("");

        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2StringList(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2StringList(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<ParserString>");
        typeMap.setAttrListTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrListTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");

        typeMap.setDataAtomicDataMethodImpl("#tm_default_string_data_xsd2cpp#");
        typeMap.setDataAtomicTypeConversion("#tm_default_string_data_xsd2cpp#");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("");
        typeMap.setDataAtomicTypePreConversion("");
        typeMap.setDataAtomicValidateEndImpl(null);
        typeMap.setDataAtomicDataMethodImplFacetPattern("#tm_default_data_atomic_data_method_impl#");
        typeMap.setDataAtomicValidateEndImplFacetPattern("#tm_default_data_atomic_validate_end_facet_pattern#");

        typeMap.setDataListEnd("return stringListDataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = stringListDataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2StringData" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2StringData"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const ParserString*");

        typeMap.setEnumAttrAtomicTypeConversion("#tm_default_enum_string_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap.setEnumDataAtomicTypeConversion("#tm_default_enum_string_data_atomic_xsd2cpp#");
        typeMap.setEnumDataListEnd("#tm_default_enum_string_data_list_dataend#");
        typeMap.setEnumDataListTypeConversion("#tm_default_enum_string_data_list_xsd2cpp#");

        typeMap.setUnionAtomicType("UnionString");
        typeMap.setUnionAtomicTypeConversion("Utils::toStringListItem");
        typeMap.setUnionEnumBaseType("StringHash");
        typeMap.setUnionEnumBaseTypeConversion("Utils::calculateStringHash");

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    public TypeMap createDefaultTypeMapToken() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("token");
        return typeMap;
    }

}
