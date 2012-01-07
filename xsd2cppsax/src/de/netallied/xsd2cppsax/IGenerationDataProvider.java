package de.netallied.xsd2cppsax;

import java.util.Map;
import java.util.Stack;

import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSSimpleTypeDefinition;
import org.apache.xerces.xs.XSTypeDefinition;

/**
 * Provides data required for code generation.
 * 
 */
public interface IGenerationDataProvider {

    /**
     * Finds C++ type as string. Takes care of simple and complex type, base
     * types and variety.
     * 
     * @note {@link Generator#fillInTemplate(String, String, String, String, XSTypeDefinition)}
     *       has a copy of this code, as it requires temporary variables.
     * @note {@link Generator#createDataConvenienceParameterList(XSTypeDefinition)}
     *       does something similar, too.
     * @param type
     *            XSD type to find C++ type for.
     * @return C++ type.
     */
    String findCorrectCppTypeForAttribute(XSTypeDefinition type);

    /**
     * @return Existing elements and their ancestors.
     */
    Map<String, ElementUsage> getCompleteElementUsage();

    /**
     * @return Configuration.
     */
    Config getConfig();

    /**
     * @return Map of xsd elements to C++ names.
     */
    Map<XSElementDeclaration, CppElementNameParentTypesPair> getElementNameMapping();

    /**
     * @return Current element stack.
     */
    Stack<XSElementDeclaration> getElementStack();

    /**
     * @return Object able to create C++ names for enums and unions.
     */
    CppEnumNameCreator getEnumOrUnionNameCreator();

    /**
     * @return Map of xsd union type to map of C++ member types.
     */
    Map<XSSimpleTypeDefinition, Map<XSSimpleTypeDefinition, StringPair>> getUnionMemberTypeMap();

    /**
     * @return Map of xsd simple types to their C++ validation function name.
     */
    Map<XSSimpleTypeDefinition, String> getXsSimpleType2validationFunctionName();

    /**
     * @return Map of xsd type to C++ validation data struct name.
     */
    Map<XSTypeDefinition, String> getXsType2validationDataStructName();
}
