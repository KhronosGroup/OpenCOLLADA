/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.TypeMapping;

import de.netallied.xsd2cppsax.Config;

/**
 * Factory which creates type mappings for XSD numeric types. Defines type
 * mappings for C++ types (protected methods with 'Abstract' in their name) and
 * uses those for several XSD types.
 * 
 * TODO move type specific code templates in one (or multiple) config file(s).
 * 
 */
public abstract class TypeMapFactoryNumeric implements ITypeMapFactory {

    protected TypeMap createAbstractBool() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toBool(attributeValue, failed);");
        typeMap.setAttrAtomicType("bool");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");

        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2BoolList(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2BoolList(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<bool>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());

        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toBool((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");

        typeMap.setDataListEnd("return boolDataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = boolDataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2BoolData" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2BoolData"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const bool*");

        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, bool, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toBool);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, bool, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toBool);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toBool, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toBool);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toBool");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractDouble() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toDouble(attributeValue, failed);");
        typeMap.setAttrAtomicType("double");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2DoubleList(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2DoubleList(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<double>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toDouble((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return doubleDataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = doubleDataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2DoubleData" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2DoubleData"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const double*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, double, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toDouble);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, double, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toDouble);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toDouble, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toDouble);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toDouble");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractFloat() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toFloat(attributeValue, failed);");
        typeMap.setAttrAtomicType("float");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2FloatList(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2FloatList(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<float>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toFloat((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return floatDataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = floatDataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2FloatData" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2FloatData"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const float*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, float, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toFloat);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, float, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toFloat);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toFloat, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toFloat);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toFloat");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractSINT16() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toSint16(attributeValue, failed);");
        typeMap.setAttrAtomicType("sint16");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2Sint16List(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2Sint16List(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<sint16>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toSint16((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return sint16DataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = sint16DataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2Sint16Data" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2Sint16Data"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const sint16*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, sint16, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toSint16);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, sint16, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toSint16);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toSint16, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toSint16);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toSint16");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractSINT32() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toSint32(attributeValue, failed);");
        typeMap.setAttrAtomicType("sint32");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2Sint32List(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2Sint32List(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<sint32>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toSint32((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return sint32DataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = sint32DataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2Sint32Data" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2Sint32Data"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const sint32*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, sint32, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toSint32);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, sint32, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toSint32);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toSint32, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toSint32);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toSint32");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractSINT64() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toSint64(attributeValue, failed);");
        typeMap.setAttrAtomicType("sint64");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2Sint64List(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2Sint64List(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<sint64>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toSint64((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return sint64DataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = sint64DataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2Sint64Data" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2Sint64Data"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const sint64*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, sint64, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toSint64);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, sint64, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toSint64);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toSint64, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toSint64);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toSint64");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractSINT8() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toSint8(attributeValue, failed);");
        typeMap.setAttrAtomicType("sint8");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2Sint8List(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2Sint8List(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<sint8>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toSint8((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return sint8DataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = sint8DataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2Sint8Data" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2Sint8Data"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const sint8*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, sint8, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toSint8);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, sint8, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toSint8);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toSint8, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toSint8);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toSint8");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractUINT16() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toUint16(attributeValue, failed);");
        typeMap.setAttrAtomicType("uint16");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2Uint16List(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2Uint16List(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<uint16>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toUint16((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return uint16DataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = uint16DataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2Uint16Data" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2Uint16Data"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const uint16*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, uint16, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toUint16);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, uint16, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toUint16);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toUint16, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toUint16);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toUint16");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractUINT32() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toUint32(attributeValue, failed);");
        typeMap.setAttrAtomicType("uint32");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2Uint32List(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2Uint32List(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<uint32>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toUint32((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return uint32DataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = uint32DataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2Uint32Data" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2Uint32Data"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const uint32*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, uint32, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toUint32);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, uint32, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toUint32);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toUint32, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toUint32);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toUint32");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractUINT64() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toUint64(attributeValue, failed);");
        typeMap.setAttrAtomicType("uint64");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2Uint64List(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2Uint64List(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<uint64>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toUint64((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return uint64DataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = uint64DataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2Uint64Data" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2Uint64Data"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const uint64*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, uint64, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toUint64);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, uint64, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toUint64);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toUint64, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toUint64);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toUint64");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    protected TypeMap createAbstractUINT8() {
        TypeMap typeMap = new TypeMap();
        typeMap.setXsdType(null);

        typeMap.setAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                + "GeneratedSaxParser::Utils::toUint8(attributeValue, failed);");
        typeMap.setAttrAtomicType("uint8");
        typeMap.setAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setAttrListTypeConversionItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                        + "characterData2Uint8List(attributeValue, attributeData->#attrName#, #stv_item_type_vali_func#, #elementNameHash#, #attrNameHash#);");
        typeMap.setAttrListTypeConversionNoItemValidation("#tm_default_attr_list_xsd2cpp_rhs#"
                + "characterData2Uint8List(attributeValue, attributeData->#attrName#);");
        typeMap.setAttrListType("XSList<uint8>");
        typeMap.setAttrListTypePostConversion(typeMap.getAttrAtomicTypePostConversion());
        typeMap.setAttrListTypePreConversion(typeMap.getAttrAtomicTypePreConversion());
        typeMap.setDataAtomicDataMethodImpl("#tm_default_data_atomic_data_method_impl#");
        typeMap
                .setDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "GeneratedSaxParser::Utils::toUint8((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed);");
        typeMap.setDataAtomicType(typeMap.getAttrAtomicType());
        typeMap.setDataAtomicTypePostConversion("#tm_default_post_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicTypePreConversion("#tm_default_pre_data_atomic_xsd2cpp#");
        typeMap.setDataAtomicValidateEndImpl("#tm_default_data_atomic_conversion#");
        typeMap.setDataListEnd("return uint8DataEnd( &#className#::#dataMethod# );");
        typeMap
                .setDataListEndValidation("bool returnValue = uint8DataEnd( &#className#::#dataMethod#, #stv_function_name_stream_end#, #stv_get_count_struct_member#, #stv_item_type_vali_func# );");
        typeMap.setDataListTypeConversion("return characterData2Uint8Data" + "#tm_default_data_list_xsd2cpp_lhs#");
        typeMap.setDataListTypeConversionValidation("return characterData2Uint8Data"
                + "#tm_default_data_list_xsd2cpp_validation_lhs#");
        typeMap.setDataListType("const uint8*");
        typeMap
                .setEnumAttrAtomicTypeConversion("#tm_default_attr_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, uint8, #enum_count#>(attributeValue, failed, #enum_map_name#, Utils::toUint8);");
        typeMap.setEnumAttrAtomicTypePostConversion("#tm_default_post_attr_atomic_xsd2cpp#");
        typeMap.setEnumAttrAtomicTypePreConversion("#tm_default_pre_attr_atomic_xsd2cpp#");
        typeMap
                .setEnumDataAtomicTypeConversion("#tm_default_data_atomic_xsd2cpp_rhs#"
                        + "Utils::toEnum<#enum_cpp_type_name#, uint8, #enum_count#>((const ParserChar**)&mLastIncompleteFragmentInCharacterData, mEndOfDataInCurrentObjectOnStack, failed, #enum_map_name#, Utils::toUint8);");
        typeMap
                .setEnumDataListEnd("return #enum_func_data_end#(&#className#::#dataMethod#, #enum_map_name#, &Utils::toUint8, #enum_func_to_enum#);");
        typeMap
                .setEnumDataListTypeConversion("return #enum_func_char_data#(text, textLength, &#className#::#dataMethod#, &Utils::toUint8);");

        typeMap.setUnionAtomicType(typeMap.getAttrAtomicType());
        typeMap.setUnionAtomicTypeConversion("Utils::toUint8");
        typeMap.setUnionEnumBaseType(typeMap.getAttrAtomicType());
        typeMap.setUnionEnumBaseTypeConversion(typeMap.getUnionAtomicTypeConversion());

        typeMap.setInitializePreList("bool failed;#nl##ind#");

        return typeMap;
    }

    public TypeMap createDefaultTypeMapBase64Binary() {
        TypeMap typeMap = createAbstractUINT64();
        typeMap.setXsdType("base64Binary");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapBoolean() {
        TypeMap typeMap = createAbstractBool();
        typeMap.setXsdType("boolean");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapByte() {
        TypeMap typeMap = createAbstractSINT8();
        typeMap.setXsdType("byte");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapDecimal() {
        TypeMap typeMap = createAbstractDouble();
        typeMap.setXsdType("decimal");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapDouble(Config config) {
        TypeMap typeMap;
        if (config.isTreatXsDoubleAsCppDouble()) {
            typeMap = createAbstractDouble();
        } else {
            typeMap = createAbstractFloat();
        }
        typeMap.setXsdType("double");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapFloat(Config config) {
        TypeMap typeMap;
        if (config.isTreatXsFloatAsCppFloat()) {
            typeMap = createAbstractFloat();
        } else {
            typeMap = createAbstractDouble();
        }
        typeMap.setXsdType("float");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapHexBinary() {
        TypeMap typeMap = createAbstractUINT8();
        typeMap.setXsdType("hexBinary");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapInt() {
        TypeMap typeMap = createAbstractSINT32();
        typeMap.setXsdType("int");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapInteger() {
        TypeMap typeMap = createAbstractSINT64();
        typeMap.setXsdType("integer");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapLong() {
        TypeMap typeMap = createAbstractSINT64();
        typeMap.setXsdType("long");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapNegativeInteger() {
        TypeMap typeMap = createAbstractSINT64();
        typeMap.setXsdType("negativeInteger");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapNonNegativeInteger() {
        TypeMap typeMap = createAbstractUINT64();
        typeMap.setXsdType("nonNegativeInteger");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapNonPositiveInteger() {
        TypeMap typeMap = createAbstractSINT64();
        typeMap.setXsdType("nonPositiveInteger");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapPositiveInteger() {
        TypeMap typeMap = createAbstractUINT64();
        typeMap.setXsdType("positiveInteger");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapPrecisionDecimal() {
        TypeMap typeMap = createAbstractDouble();
        typeMap.setXsdType("precisionDecimal");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapShort() {
        TypeMap typeMap = createAbstractSINT16();
        typeMap.setXsdType("short");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapUnsignedByte() {
        TypeMap typeMap = createAbstractUINT8();
        typeMap.setXsdType("unsignedByte");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapUnsignedInt() {
        TypeMap typeMap = createAbstractUINT32();
        typeMap.setXsdType("unsignedInt");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapUnsignedLong() {
        TypeMap typeMap = createAbstractUINT64();
        typeMap.setXsdType("unsignedLong");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapUnsignedShort() {
        TypeMap typeMap = createAbstractUINT16();
        typeMap.setXsdType("unsignedShort");
        return typeMap;
    }
}
