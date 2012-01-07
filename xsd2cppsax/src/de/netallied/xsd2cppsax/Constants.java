/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

/**
 * Contains constants.
 * 
 */
public class Constants {

    public static final String DEFAULT_CPP_TYPE = "const ParserChar*";

    public static final String DEFAULT_XSD_TYPE = "string";

    public static final String ENUM_CPP_BASE_TYPE_FOR_STRINGS = "StringHash";

    public static final String STATE_MACHINE_END_CPP_CONSTANT = "STATE_MACHINE_END";

    public static final String STATE_MACHINE_END_NODE_NAME = "STATE_MACHINE_END";

    public static final String STATE_MACHINE_ROOT_CPP_CONSTANT = "STATE_MACHINE_ROOT";

    public static final String STATE_MACHINE_ROOT_NODE_NAME = "STATE_MACHINE_ROOT";

    public static final String TEMPLATE_DELIMITER_COHERENCY_TEST = "#cht_";

    public static final String TEMPLATE_DELIMITER_COMPLEX_VALIDATION = "#ctv";

    public static final String TEMPLATE_DELIMITER_ENUM = "#enum";

    public static final String TEMPLATE_DELIMITER_TYPE_MAPPING = "#tm_";

    public static final String TEMPLATE_DELIMITER_UNION = "#union";

    public static final String TMPL_ATTR_ATOMIC_XSD_2_CPP = "#attr_atomic_xsd2cpp#";

    public static final String TMPL_ATTR_CHECK_REQUIRED_PRESENT = "#attr_check_required_present#";

    public static final String TMPL_ATTR_INIT_OBJECT = "#attr_init_object#";

    public static final String TMPL_ATTR_INIT_OBJECT_DEFAULT_VAL = "#attr_init_object_default_val#";

    public static final String TMPL_ATTR_INIT_OBJECT_DEFAULT_VAL_LENGTH = "#attr_init_object_default_val_length#";

    public static final String TMPL_ATTR_INIT_OBJECT_SET_PRESENT = "#attr_init_object_set_present#";

    public static final String TMPL_ATTR_INIT_OBJECTS = "#attr_init_objects#";

    public static final String TMPL_ATTR_LIST_XSD_2_CPP = "#attr_list_xsd2cpp#";

    public static final String TMPL_ATTR_LIST_XSD_2_CPP_ITEM_VALIDATION = "#attr_list_xsd2cpp_item_vali#";

    public static final String TMPL_ATTR_NOT_PRESENT_CHECK = "#attr_not_present_check#";

    public static final String TMPL_ATTR_PRESENT_CHECK = "#attr_present_check#";

    public static final String TMPL_ATTR_PRESENT_MASK = "#attr_present_mask#";

    public static final String TMPL_ATTR_PRESENT_MEMBER = "#attr_present_member#";

    public static final String TMPL_ATTR_PRESENT_SET = "#attr_present_set#";

    public static final String TMPL_ATTRIBUTE_NAME = "#attrName#";

    public static final String TMPL_ATTRIBUTE_NAME_HASH = "#attrNameHash#";

    public static final String TMPL_ATTRIBUTE_PARSING_SWITCH_DEFAULT = "#attr_parsing_switch_default#";

    public static final String TMPL_ATTRIBUTE_STRUCT_NAME = "#attr_struct_name#";

    public static final String TMPL_ATTRIBUTE_STRUCT_SUFFIX = "#attrStructSuffix#";

    public static final String TMPL_CLASS_NAME = "#className#";

    public static final String TMPL_COHERENCY_TEST_COUNT_ATTRIBUTE = "#cht_count_attr#";

    public static final String TMPL_COHERENCY_TEST_ERROR_HANDLER = "#cht_err_handler#";

    public static final String TMPL_COHERENCY_TEST_ID_COUNTER_MAP = "#cht_id_counter_map#";

    public static final String TMPL_COHERENCY_TEST_LIST_COUNT = "#cht_list_count#";

    public static final String TMPL_COMPLEX_VALI_CHECK_MAX_OCCURENCE = "#ctv_check_maxOccurence#";

    public static final String TMPL_COMPLEX_VALI_CHECK_MIN_OCCURENCE_OF_CHILDREN = "#ctv_check_minOccurence_of_children#";

    public static final String TMPL_COMPLEX_VALI_CHECK_SIBLINGS = "#ctv_check_siblings#";

    public static final String TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE = "#ctv_check_state_machine#";

    public static final String TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE_END = "#ctv_check_state_machine_end#";

    public static final String TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE_END_PER_STATE = "#ctv_check_state_machine_end_per_state#";

    public static final String TMPL_COMPLEX_VALI_CHOICE_ONE_CHILD_PER_CHILD = "#ctv_choice_one_child_per_child#";

    public static final String TMPL_COMPLEX_VALI_DELETE_VALIDATION_DATA = "#ctv_delete_vali_data#";

    public static final String TMPL_COMPLEX_VALI_GET_PARENT_VALIDATION_DATA = "#ctv_get_parent_vali_data#";

    public static final String TMPL_COMPLEX_VALI_GET_VALIDATION_DATA = "#ctv_get_vali_data#";

    public static final String TMPL_COMPLEX_VALI_INCREMENT_OCCURENCE = "#ctv_increment_occurence#";

    public static final String TMPL_COMPLEX_VALI_MAX_OCCURENCE = "#ctv_max_occurence#";

    public static final String TMPL_COMPLEX_VALI_MIN_OCCURENCE = "#ctv_min_occurence#";

    public static final String TMPL_COMPLEX_VALI_PARENT_STRUCT_NAME = "#ctv_parent_data_struct_name#";

    public static final String TMPL_COMPLEX_VALI_SET_STATE_MACHINE_STATE = "#ctv_set_state_machine_state#";

    public static final String TMPL_COMPLEX_VALI_SIBLING_NAME = "#ctv_sibling_name#";

    public static final String TMPL_COMPLEX_VALI_STATE_MACHINE_CHECK_PER_STATE = "#ctv_check_state_machine_per_state#";

    public static final String TMPL_COMPLEX_VALI_STATE_MACHINE_CURRENT_STATE = "#ctv_current_state#";

    public static final String TMPL_COMPLEX_VALI_STATE_MACHINE_END_STATE = "#ctv_end_state#";

    public static final String TMPL_COMPLEX_VALI_STATE_MACHINE_PREV_STATE = "#ctv_prev_state#";

    public static final String TMPL_COMPLEX_VALI_STATE_MACHINE_START_STATE = "#ctv_start_state#";

    public static final String TMPL_COMPLEX_VALI_STATE_MACHINE_STRUCT_MEMBER = "#ctv_struct_state_member#";

    public static final String TMPL_COMPLEX_VALI_STRUCT_MEMBER = "#ctv_data_member#";

    public static final String TMPL_COMPLEX_VALI_STRUCT_MEMBER_SIBLING_NAME = "#ctv_sibling_member#";

    public static final String TMPL_COMPLEX_VALI_STRUCT_NAME = "#ctv_data_struct_name#";

    public static final String TMPL_COMPLEX_VALI_STRUCT_TYPE = "#ctv_data_struct_type#";

    public static final String TMPL_CONTINUE_LOOP = "#CONTINUE_LOOP#";

    public static final String TMPL_CPP_ATOMIC_TYPE = "#cppAtomicType#";

    public static final String TMPL_DATA_ATOMIC_DATA_METHOD_IMPL = "#data_atomic_data_method_impl#";

    public static final String TMPL_DATA_ATOMIC_DATA_METHOD_IMPL_DEFAULT = "#ind#return true;";

    public static final String TMPL_DATA_ATOMIC_XSD_2_CPP = "#data_atomic_xsd2cpp#";

    public static final String TMPL_DATA_LIST_VALIDATE_END = "#data_list_validate_end#";

    public static final String TMPL_DATA_LIST_VALIDATE_END_VALIDATION = "#data_list_validate_end_vali#";

    public static final String TMPL_DATA_LIST_XSD_2_CPP = "#data_list_xsd2cpp#";

    public static final String TMPL_DATA_LIST_XSD_2_CPP_VALIDATION = "#data_list_xsd2cpp_vali#";

    public static final String TMPL_DATA_METHOD = "#dataMethod#";

    public static final String TMPL_ELEMENT_NAME = "#elementName#";

    public static final String TMPL_ELEMENT_NAME_HASH = "#elementNameHash#";

    public static final String TMPL_ENUM_BASE_TYPE_VALUE = "#enum_base_type_value#";

    public static final String TMPL_ENUM_COUNT = "#enum_count#";

    public static final String TMPL_ENUM_CPP_BASE_TYPE = "#enum_cpp_base_type#";

    public static final String TMPL_ENUM_CPP_TYPE_NAME = "#enum_cpp_type_name#";

    public static final String TMPL_ENUM_DATA_ATOMIC_XSD_2_CPP = "#enum_data_atomic_xsd2cpp#";

    public static final String TMPL_ENUM_FUNC_CHAR_DATA = "#enum_func_char_data#";

    public static final String TMPL_ENUM_FUNC_DATA_END = "#enum_func_data_end#";

    public static final String TMPL_ENUM_FUNC_DATA_PREFIX = "#enum_func_data_prefix#";

    public static final String TMPL_ENUM_FUNC_TO_ENUM = "#enum_func_to_enum#";

    public static final String TMPL_ENUM_MAP_ENTRY = "#enum_map_entry#";

    public static final String TMPL_ENUM_MAP_ENTRY_TYPE = "#enum_map_entry_type#";

    public static final String TMPL_ENUM_MAP_NAME = "#enum_map_name#";

    public static final String TMPL_ENUM_MAP_PAIR_TYPE = "#enum_map_pair_type#";

    public static final String TMPL_ENUM_VALUE = "#enum_value#";

    public static final String TMPL_ENUM_VALUE_NOT_PRESENT = "#enum_value_not_present#";

    public static final String TMPL_FINDHASH_GENERATED_HASH_VALUE = "#findhash_generated_hash_value#";

    public static final String TMPL_FINDHASH_TYPEID = "#findhash_typeid#";

    public static final String TMPL_FPRINTF_PARSER_CLASS_NAME = "#fPrintfParserClassName#";

    public static final String TMPL_FPRINTF_PARSER_FILE_MEMBER_NAME = "#fPrintfParserFileMemberName#";

    public static final String TMPL_FPRINTF_PARSER_PRINT_FLOAT_METHOD_PARAMETER_NAME = "#fprintfParserPrintFloatMethodParameterName#";

    public static final String TMPL_FPRINTF_PARSER_PRINT_FLOAT_TEMPLATE_METHOD_NAME = "#fprintfParserPrintFloatTemplateMethodName#";

    public static final String TMPL_INDENT = "#ind#";

    public static final String TMPL_INITAL_VALUE = "#init_value#";

    public static final String TMPL_MIMPL = "#mimpl#";

    public static final String TMPL_NEWLINE = "#nl#";

    public static final String TMPL_POST_ATTR_ATOMIC_XSD_2_CPP = "#post_attr_atomic_xsd2cpp#";

    public static final String TMPL_POST_ATTR_LIST_XSD_2_CPP = "#post_attr_list_xsd2cpp#";

    public static final String TMPL_POST_DATA_ATOMIC_XSD_2_CPP = "#post_data_atomic_xsd2cpp#";

    public static final String TMPL_PRE_ATTR_ATOMIC_XSD_2_CPP = "#pre_attr_atomic_xsd2cpp#";

    public static final String TMPL_PRE_ATTR_LIST_XSD_2_CPP = "#pre_attr_list_xsd2cpp#";

    public static final String TMPL_PRE_DATA_ATOMIC_XSD_2_CPP = "#pre_data_atomic_xsd2cpp#";

    public static final String TMPL_PRIVATE_CLASS_NAME = "#private_class_name#";

    public static final String TMPL_SIMPLE_VALI = "#simple_type_validation#";

    public static final String TMPL_SIMPLE_VALI_FUNCTION_NAME = "#stv_function_name#";

    public static final String TMPL_SIMPLE_VALI_FUNCTION_NAME_STREAM = "#stv_function_name_stream#";

    public static final String TMPL_SIMPLE_VALI_FUNCTION_NAME_STREAM_END = "#stv_function_name_stream_end#";

    public static final String TMPL_SIMPLE_VALI_GET_COUNT_STRUCT_MEMBER = "#stv_get_count_struct_member#";

    public static final String TMPL_SIMPLE_VALI_ITEM_TYPE_FUNCTION_NAME = "#stv_item_type_vali_func#";

    public static final String TMPL_SIMPLE_VALI_LENGTH = "#stv_length#";

    public static final String TMPL_SIMPLE_VALI_LENGTH_VALUE = "#stv_length_value#";

    public static final String TMPL_SIMPLE_VALI_MAX_EXCLUSIVE = "#stv_max_exclusive#";

    public static final String TMPL_SIMPLE_VALI_MAX_INCLUSIVE = "#stv_max_inclusive#";

    public static final String TMPL_SIMPLE_VALI_MAX_LENGTH = "#stv_max_length#";

    public static final String TMPL_SIMPLE_VALI_MIN_EXCLUSIVE = "#stv_min_exclusive#";

    public static final String TMPL_SIMPLE_VALI_MIN_INCLUSIVE = "#stv_min_inclusive#";

    public static final String TMPL_SIMPLE_VALI_MIN_LENGTH = "#stv_min_length#";

    public static final String TMPL_SIMPLE_VALI_PCRE_COMPILER_OUTPUT = "#stv_pcre_compiler_output#";

    public static final String TMPL_SIMPLE_VALI_SPECIAL_STREAM_END_VALI = "#stv_special_stream_end_vali#";

    public static final String TMPL_SIMPLE_VALI_SPECIAL_STREAM_END_VALI_HANDLE_ERROR = "#stv_special_stream_end_vali_handle_error#";

    public static final String TMPL_SIMPLE_VALI_STREAM_COUNT_STRUCT_MEMBER = "#stv_count_struct_member#";

    public static final String TMPL_SIMPLE_VALI_UPDATE_STREAM_COUNT = "#stv_update_stream_count#";

    public static final String TMPL_SIMPLE_VALI_VALUE = "#stv_value#";

    public static final String TMPL_TYPE_MAP_DEFAULT_ATTR_ATOMIC_XSD2CPP_RHS = "#tm_default_attr_atomic_xsd2cpp_rhs#";

    public static final String TMPL_TYPE_MAP_DEFAULT_ATTR_LIST_XSD2CPP_RHS = "#tm_default_attr_list_xsd2cpp_rhs#";

    public static final String TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_CONVERSION = "#tm_default_data_atomic_conversion#";

    public static final String TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_DATA_METHOD_IMPL = "#tm_default_data_atomic_data_method_impl#";

    public static final String TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_VALIDATE_END_FACET_PATTERN = "#tm_default_data_atomic_validate_end_facet_pattern#";

    public static final String TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_XSD2CPP_RHS = "#tm_default_data_atomic_xsd2cpp_rhs#";

    public static final String TMPL_TYPE_MAP_DEFAULT_DATA_LIST_XSD2CPP_LHS = "#tm_default_data_list_xsd2cpp_lhs#";

    public static final String TMPL_TYPE_MAP_DEFAULT_DATA_LIST_XSD2CPP_VALIDATION_LHS = "#tm_default_data_list_xsd2cpp_validation_lhs#";

    public static final String TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_ATTR_ATOMIC_XSD2CPP = "#tm_default_enum_string_attr_atomic_xsd2cpp#";

    public static final String TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_ATOMIC_XSD2CPP = "#tm_default_enum_string_data_atomic_xsd2cpp#";

    public static final String TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_LIST_DATAEND = "#tm_default_enum_string_data_list_dataend#";

    public static final String TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_LIST_XSD2CPP = "#tm_default_enum_string_data_list_xsd2cpp#";

    public static final String TMPL_TYPE_MAP_DEFAULT_POST_ATTR_ATOMIC_XSD2CPP = "#tm_default_post_attr_atomic_xsd2cpp#";

    public static final String TMPL_TYPE_MAP_DEFAULT_POST_DATA_ATOMIC_XSD2CPP = "#tm_default_post_data_atomic_xsd2cpp#";

    public static final String TMPL_TYPE_MAP_DEFAULT_PRE_ATTR_ATOMIC_XSD2CPP = "#tm_default_pre_attr_atomic_xsd2cpp#";

    public static final String TMPL_TYPE_MAP_DEFAULT_PRE_DATA_ATOMIC_XSD2CPP = "#tm_default_pre_data_atomic_xsd2cpp#";

    public static final String TMPL_TYPE_MAP_DEFAULT_STRING_DATA_XSD2CPP = "#tm_default_string_data_xsd2cpp#";

    public static final String TMPL_TYPE_MAP_DEFAULT_UNION_DATA_ATOMIC_XSD2CPP_RHS = "#tm_default_union_data_atomic_xsd2cpp_rhs#";

    public static final String TMPL_TYPED_ATTRIBUTE_STRUCT_VARIABLE_NAME = "#typed_attr_data_var_name#";

    public static final String TMPL_UNION_ATTR_ATOMIC_POST_XSD_2_CPP = "#union_attr_atomic_post_xsd2cpp#";

    public static final String TMPL_UNION_ATTR_ATOMIC_PRE_XSD_2_CPP = "#union_attr_atomic_pre_xsd2cpp#";

    public static final String TMPL_UNION_ATTR_ATOMIC_XSD_2_CPP = "#union_attr_atomic_xsd2cpp#";

    public static final String TMPL_UNION_CPP_TYPE_NAME = "#union_cpp_type_name#";

    public static final String TMPL_UNION_DATA_ATOMIC_DATA_METHOD_IMPL = "#union_data_atomic_data_method_impl#";

    public static final String TMPL_UNION_DATA_ATOMIC_POST_XSD2CPP = "#union_data_atomic_post_xsd2cpp#";

    public static final String TMPL_UNION_DATA_ATOMIC_PRE_XSD2CPP = "#union_data_atomic_pre_xsd2cpp#";

    public static final String TMPL_UNION_DATA_ATOMIC_XSD2CPP = "#union_data_atomic_xsd2cpp#";

    public static final String TMPL_UNION_DATA_MEMBER_NAME = "#union_data_member_name#";

    public static final String TMPL_UNION_ENUM_BASE_FUNC = "#union_enum_base_func#";

    public static final String TMPL_UNION_ENUM_BASE_TYPE = "#union_enum_base_type#";

    public static final String TMPL_UNION_FUNC_DATA_PREFIX = "#union_func_data_prefix#";

    public static final String TMPL_UNION_FUNC_TO_UNION = "#union_func_to_union#";

    public static final String TMPL_UNION_MEMBER_CONVERSION_FUNC_NAME = "#union_member_conversion_func_name#";

    public static final String TMPL_UNION_MEMBER_CONVERSION_FUNC_PARAS = "#union_member_conversion_func_paras#";

    public static final String TMPL_UNION_MEMBER_CPP_TYPE = "#union_member_cpp_type#";

    public static final String TMPL_UNION_MEMBER_TMP_VAR = "#union_member_tmp_var#";

    public static final String TMPL_UNION_MEMBER_TYPE_ENUM = "#union_member_type_enum#";

    public static final String TMPL_UNION_TO_UNION_PER_MEMBER = "#union_to_union_per_member#";

    public static final String TMPL_UNION_TYPE_MEMBER_NAME = "#union_type_member_name#";

    public static final String TMPL_UNKNOWN_ATTRIBUTE_TYPE = "#unknwonAttrType#";

    public static final String TMPL_UNKNOWN_ATTRIBUTES_MEMBER_NAME = "#unknwonAttrName#";

    public static final String TMPL_UNKNOWN_ATTRIBUTES_MEMBER_TYPE = "#unknwonAttrMemberType#";

    public static final String TMPL_VALI_BLOCK_CLOSE = "#validation_block_close#";

    public static final String TMPL_VALI_BLOCK_ELSE_COMPILE_TIME = "#validation_block_else_compiletime#";

    public static final String TMPL_VALI_BLOCK_ELSE_RUN_TIME = "#validation_block_else_runtime#";

    public static final String TMPL_VALI_BLOCK_OPEN = "#validation_block_open#";

    public static final String XML_BASE_NAMESPACE = "http://www.w3.org/XML/1998/namespace";

    public static final String XML_BASE_NAMESPACE_PREFIX = "xml";

    public static final String XSD_ANYTYPE_NAME = "anyType";
}
