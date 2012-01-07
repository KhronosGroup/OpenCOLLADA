package de.netallied.xsd2cppsax;

import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSSimpleTypeDefinition;

/**
 * Creates type names for C++ enums and union structs.
 * 
 */
public class CppEnumNameCreator {

    /** Counts enums without name. Used to generate C++ names for those enums. */
    private int anonymousEnumCounter = 0;

    /** Contains names for anonymous enums which have already been created. */
    private Map<XSSimpleTypeDefinition, String> anonymousEnumMap = new HashMap<XSSimpleTypeDefinition, String>();

    /** Counts unions without name. Used to generate C++ names for those unions. */
    private int anonymousUnionCounter = 0;

    /** Contains names for anonymous unions which have already been created. */
    private Map<XSSimpleTypeDefinition, String> anonymousUnionMap = new HashMap<XSSimpleTypeDefinition, String>();

    /**
     * Counts union members without name. Used to generate C++ names for those
     * union members.
     */
    private int anonymousUnionMemberCounter = 0;

    /**
     * Contains names for anonymous union members which have already been
     * created.
     */
    private Map<XSSimpleTypeDefinition, Map<XSSimpleTypeDefinition, String>> anonymousUnionMemberMap = new HashMap<XSSimpleTypeDefinition, Map<XSSimpleTypeDefinition, String>>();

    /** Configuration. */
    private Config config;

    /** Generated file containing suggested better names for enums. */
    private PrintStream enumTypeMappingFile;

    /**
     * Contains C++ names of enums which have already been printed. Used to
     * generate name proposals for anonymous enums.
     */
    private Set<String> printedEnums;

    /**
     * Contains C++ names of unions which have already been printed. Not used
     * because generation of name proposals for anonymous unions is not
     * implemented.
     */
    private Set<String> printedUnions;

    /**
     * Constructor.
     */
    public CppEnumNameCreator(Config config, PrintStream enumTypeMappingFile, Set<String> printedEnums,
            Set<String> printedUnions) {
        this.config = config;
        this.enumTypeMappingFile = enumTypeMappingFile;
        this.printedEnums = printedEnums;
        this.printedUnions = printedUnions;
    }

    /**
     * Creates name for a C++ enum type.
     * 
     * @param simpleType
     *            XSD type to create C++ type name for.
     * @return C++ type name.
     */
    public String createEnumTypeName(XSSimpleTypeDefinition simpleType, Stack<XSElementDeclaration> elementStack) {
        String cppEnumTypeName = null;
        String xsdTypeName = simpleType.getName();
        String enumTypePrefix = config.getCppEnumTypePrefix();
        if (xsdTypeName != null) {
            if (config.isTypeNameMappingGenerationTurnedOn() && !printedEnums.contains(xsdTypeName)) {
                enumTypeMappingFile.println(enumTypePrefix + xsdTypeName + config.getTypeNameMappingSeparator()
                        + xsdTypeName);
            }

            cppEnumTypeName = enumTypePrefix + Util.replaceCharactersForbiddenInCppIdentifiers(xsdTypeName);
        } else {

            if (!anonymousEnumMap.containsKey(simpleType)) {
                anonymousEnumMap.put(simpleType, enumTypePrefix + config.getAnonymousEnumPrefix()
                        + anonymousEnumCounter++);

                if (config.isTypeNameMappingGenerationTurnedOn()) {
                    String delimiter = config.getElementNameDelimiter();
                    Stack<XSElementDeclaration> stack = elementStack;
                    String suggestedName = new String();
                    for (int i = stack.size() - 1; i >= 0; i--) {
                        suggestedName += stack.get(i).getName();
                        if (i != 0) {
                            suggestedName += delimiter;
                        }
                    }

                    enumTypeMappingFile.println(anonymousEnumMap.get(simpleType) + config.getTypeNameMappingSeparator()
                            + enumTypePrefix + suggestedName);
                }
            }
            cppEnumTypeName = anonymousEnumMap.get(simpleType);
        }
        Map<String, String> userTypeNameMapping = config.getUserTypeNameMapping();
        if (userTypeNameMapping.containsKey(cppEnumTypeName)) {
            return userTypeNameMapping.get(cppEnumTypeName);
        }
        return cppEnumTypeName;
    }

    /**
     * Creates name for a C++ union member type (inside type enum of union
     * struct).
     * 
     * @param memberType
     *            Union member type to create name for.
     * @param unionType
     *            Parent union.
     * @return C++ type name.
     */
    public String createUnionMemberTypeName(XSSimpleTypeDefinition memberType, XSSimpleTypeDefinition unionType) {
        String cppName = memberType.getName();
        if (cppName == null) {
            Map<XSSimpleTypeDefinition, String> map = anonymousUnionMemberMap.get(unionType);
            if (map == null) {
                map = new HashMap<XSSimpleTypeDefinition, String>();
                anonymousUnionMemberMap.put(unionType, map);
            }
            if (map.containsKey(memberType)) {
                cppName = map.get(memberType);
            } else {
                cppName = config.getAnonymousUnionMemberPrefix() + anonymousUnionMemberCounter++;
                map.put(memberType, cppName);
            }
        }
        return Util.replaceCharactersForbiddenInCppIdentifiers(cppName.toUpperCase());
    }

    /**
     * Creates name for a C++ union type.
     * 
     * @param simpleType
     *            XSD type to create C++ type name for.
     * @return C++ type name.
     */
    public String createUnionTypeName(XSSimpleTypeDefinition simpleType, Stack<XSElementDeclaration> elementStack) {
        String cppUnionTypeName = null;
        String xsdTypeName = simpleType.getName();
        String unionTypePrefix = config.getCppUnionTypePrefix();
        if (xsdTypeName != null) {
            cppUnionTypeName = unionTypePrefix + Util.replaceCharactersForbiddenInCppIdentifiers(xsdTypeName);
        } else {
            if (!anonymousUnionMap.containsKey(simpleType)) {
                anonymousUnionMap.put(simpleType, unionTypePrefix + config.getAnonymousUnionPrefix()
                        + anonymousUnionCounter++);
            }
            cppUnionTypeName = anonymousUnionMap.get(simpleType);

        }
        Map<String, String> userTypeNameMapping = config.getUserTypeNameMapping();
        if (userTypeNameMapping.containsKey(cppUnionTypeName)) {
            return userTypeNameMapping.get(cppUnionTypeName);
        }
        return cppUnionTypeName;
    }

}
