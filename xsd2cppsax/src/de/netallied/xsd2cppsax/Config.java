/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Properties;

import de.netallied.xsd2cppsax.TypeMapping.TypeMap;
import de.netallied.xsd2cppsax.TypeMapping.TypeMapFactory;

/**
 * Configures code generation.
 */
public class Config {

    /**
     * Utility function to get a filepath without file extension.
     * 
     * @param fileName
     *            Path of a file.
     * @return Filepath without extension.
     */
    public static String getBaseFileName(String fileName) {
        return fileName.substring(0, fileName.lastIndexOf('.'));
    }

    private Map<String, String> builtInTypeMaxValues;

    private Map<String, String> builtInTypeMinValues;

    /** Code templates loaded from own properties file. */
    private Properties codeTemplates;

    private List<String> coherencyTestInitializationList;

    private Map<String, String> cppStructMemberNameMapping;

    private Map<String, String> elementNameMapping;

    private boolean generateCoherencyTestParser;

    private boolean generateExampleParser;

    private boolean generateFprintfParser;

    private boolean generateTypeNameMapping;

    private List<String> includeFilesForEnumsHeader;

    private List<String> includeFilesForEnumsSource;

    private List<String> includeFilesForImpl;

    private List<String> includeFilesForPrivateHeader;

    private int maxTemplateResolvingIterations;

    /** Options loaded from a properties file. */
    private Properties props;

    private List<String> specialFunctionMapsStartElementNamesAllLevels;

    private List<String> specialFunctionMapsStartElementNamesOneLevel;

    private boolean treatXsDoubleAsCppDouble;

    private boolean treatXsFloatAsCppFloat;

    private Map<String, TypeMap> typeMapping;

    private Map<String, String> userTypeNameMapping;

    private Map<String, String> xsNamespaceMapping;

    public Config(String configFileName, String inputXSD, String rootElement) throws FileNotFoundException, IOException {
        props = new Properties();
        FileInputStream propInputFile = new FileInputStream(configFileName);
        props.load(propInputFile);

        // options overwritten at commandline
        if (inputXSD != null) {
            props.setProperty("inputFile", inputXSD);
        }
        if (rootElement != null) {
            props.setProperty("rootElementName", rootElement);
        }

        // map options
        builtInTypeMaxValues = parseMapOption(props.getProperty("builtInTypeMaxValues"));
        builtInTypeMinValues = parseMapOption(props.getProperty("builtInTypeMinValues"));
        elementNameMapping = parseMapOption(props.getProperty("elementNameMapping"));
        cppStructMemberNameMapping = parseMapOption(props.getProperty("cppStructMemberNameMapping"));
        userTypeNameMapping = parseMapOption(props.getProperty("userTypeNameMapping"));
        xsNamespaceMapping = parseMapOption(props.getProperty("xsNamespaceMapping"));

        // list options
        includeFilesForEnumsHeader = parseListOption(props.getProperty("includeFilesForEnumsHeader"));
        includeFilesForEnumsSource = parseListOption(props.getProperty("includeFilesForEnumsSource"));
        includeFilesForPrivateHeader = parseListOption(props.getProperty("includeFilesForPrivateHeader"));
        includeFilesForImpl = new ArrayList<String>();
        includeFilesForImpl.add(getIncludePrecompiledHeader());
        includeFilesForImpl.addAll(parseListOption(props.getProperty("includeFilesForImpl")));
        coherencyTestInitializationList = parseListOption(props.getProperty("coherencyTestInitializationList"));

        specialFunctionMapsStartElementNamesAllLevels = parseListOption(props
                .getProperty("specialFunctionMapsStartElementNamesAllLevels"));
        specialFunctionMapsStartElementNamesOneLevel = parseListOption(props
                .getProperty("specialFunctionMapsStartElementNamesOneLevel"));

        // bool/numeric options
        maxTemplateResolvingIterations = Integer.parseInt(checkOption(props
                .getProperty("maxTemplateResolvingIterations")));
        generateTypeNameMapping = Boolean.parseBoolean(checkOption(props.getProperty("generateTypeNameMapping")));
        treatXsDoubleAsCppDouble = Boolean.parseBoolean(checkOption(props.getProperty("treatXsDoubleAsCppDouble")));
        treatXsFloatAsCppFloat = Boolean.parseBoolean(checkOption(props.getProperty("treatXsFloatAsCppFloat")));
        generateExampleParser = Boolean.parseBoolean(checkOption(props.getProperty("generateExampleParser")));
        generateFprintfParser = Boolean.parseBoolean(checkOption(props.getProperty("generateFprintfParser")));
        generateCoherencyTestParser = Boolean
                .parseBoolean(checkOption(props.getProperty("generateCoherencyTestParser")));

        // code templates
        codeTemplates = new Properties();
        String codeTemplatesFileName = props.getProperty("codeTemplates");
        if (codeTemplatesFileName != null && codeTemplatesFileName.length() > 0) {
            File configFile = new File(configFileName);
            String configDir = configFile.getParent();
            String codeTemplatesPath;
            if (configDir != null) {
                codeTemplatesPath = configDir + System.getProperty("file.separator") + codeTemplatesFileName;
            } else {
                codeTemplatesPath = codeTemplatesFileName;
            }
            FileInputStream codeTemplatesInputStream = new FileInputStream(codeTemplatesPath);
            codeTemplates.load(codeTemplatesInputStream);
        }

        // type mapping
        typeMapping = new TypeMapFactory().createDefaultTypeMap(this);
    }

    /**
     * Checks if option is null and returns empty string if the case.
     */
    protected String checkOption(String option) {
        return option == null ? "" : option;
    }

    public String getAnonymousEnumPrefix() {
        return checkOption(props.getProperty("anonymousEnumPrefix"));
    }

    public String getAnonymousUnionMemberPrefix() {
        return checkOption(props.getProperty("anonymousUnionMemberPrefix"));
    }

    public String getAnonymousUnionPrefix() {
        return checkOption(props.getProperty("anonymousUnionPrefix"));
    }

    public String getAttributeDataParameterName() {
        return checkOption(props.getProperty("attributeDataParameterName"));
    }

    public String getAttributePresentMaskType() {
        return checkOption(props.getProperty("attributePresentMaskType"));
    }

    public String getAttributesPresentMemberName() {
        return checkOption(props.getProperty("attributesPresentMemberName"));
    }

    public String getAttributesPresentMemberType() {
        return checkOption(props.getProperty("attributesPresentMemberType"));
    }

    public String getAttributeStructDefaultMemberName() {
        return checkOption(props.getProperty("attributeStructDefaultMemberName"));
    }

    public String getAttributeStructSuffix() {
        return checkOption(props.getProperty("attributeStructSuffix"));
    }

    public String getBaseClassName() {
        return getBaseClassTemplateName() + "<" + getClassNamePrivate() + ", " + getClassNamePublic() + ">";
    }

    public String getBaseClassNamespace() {
        return checkOption(props.getProperty("baseClassNamespace"));
    }

    public String getBaseClassTemplateName() {
        return checkOption(props.getProperty("baseClassTemplateName"));
    }

    public String getBeginMethodPrefix() {
        return checkOption(props.getProperty("beginMethodPrefix"));
    }

    /**
     * @return Mapping of C++ type names to max values from XSD built in types.
     */
    public Map<String, String> getBuiltInTypeMaxValues() {
        return builtInTypeMaxValues;
    }

    /**
     * @return Mapping of C++ type names to min values from XSD built in types.
     */
    public Map<String, String> getBuiltInTypeMinValues() {
        return builtInTypeMinValues;
    }

    public String getClassNameFunctionMapFactory() {
        return checkOption(props.getProperty("classNameFunctionMapFactory"));
    }

    public String getClassNamePrivate() {
        return checkOption(props.getProperty("classNamePrivate"));
    }

    public String getClassNamePublic() {
        return checkOption(props.getProperty("classNamePublic"));
    }

    public String getCoherencyTestCountAttributeMemberName() {
        return checkOption(props.getProperty("coherencyTestCountAttributeMemberName"));
    }

    public String getCoherencyTestCtorParas() {
        return checkOption(props.getProperty("coherencyTestCtorParas"));
    }

    public String getCoherencyTestErrorHandlerName() {
        return checkOption(props.getProperty("coherencyTestErrorHandlerName"));
    }

    public String getCoherencyTestIdCounterMapName() {
        return checkOption(props.getProperty("coherencyTestIdCounterMapName"));
    }

    public List<String> getCoherencyTestInitializationList() {
        return coherencyTestInitializationList;
    }

    public String getCoherencyTestListCountMemberName() {
        return checkOption(props.getProperty("coherencyTestListCountMemberName"));
    }

    public String getCoherencyTestParserClassName() {
        return checkOption(props.getProperty("coherencyTestParserClassName"));
    }

    public String getCoherencyTestParserNamespace() {
        return checkOption(props.getProperty("coherencyTestParserNamespace"));
    }

    public String getComplexValidationDataParentStructVariableName() {
        return checkOption(props.getProperty("complexValidationDataParentStructVariableName"));
    }

    public String getComplexValidationDataStateMachineStructMemberType() {
        return checkOption(props.getProperty("complexValidationDataStateMachineStructMemberType"));
    }

    public String getComplexValidationDataStructVariableName() {
        return checkOption(props.getProperty("complexValidationDataStructVariableName"));
    }

    public String getComplexValidationStateMachineStructMember() {
        return checkOption(props.getProperty("complexValidationStateMachineStructMember"));
    }

    public String getConvenienceDataMethodLengthParameterName() {
        return checkOption(props.getProperty("convenienceDataMethodLengthParameterName"));
    }

    public String getConvenienceDataMethodValueParameterName() {
        return checkOption(props.getProperty("convenienceDataMethodValueParameterName"));
    }

    public String getCppEnumTypePrefix() {
        return checkOption(props.getProperty("cppEnumTypePrefix"));
    }

    public Map<String, String> getCppStructMemberNameMapping() {
        return cppStructMemberNameMapping;
    }

    public String getCppUnionTypePrefix() {
        return checkOption(props.getProperty("cppUnionTypePrefix"));
    }

    public boolean getDebug() {
        // return true;
        return false;
    }

    /**
     * Returns configured delimiter for concatenated element names.
     * 
     * @note Must be changed in C++, too!
     * 
     * @return Delimiter.
     */
    public String getElementNameDelimiter() {
        return checkOption(props.getProperty("elementNameDelimiter"));
    }

    public Map<String, String> getElementNameMapping() {
        return elementNameMapping;
    }

    public String getEndMethodPrefix() {
        return checkOption(props.getProperty("endMethodPrefix"));
    }

    public String getEnumCountName() {
        return checkOption(props.getProperty("enumCountName"));
    }

    public String getEnumFuncPrefixCharData() {
        return checkOption(props.getProperty("enumFuncPrefixCharData"));
    }

    public String getEnumFuncPrefixDataEnd() {
        return checkOption(props.getProperty("enumFuncPrefixDataEnd"));
    }

    public String getEnumFuncPrefixDataPrefix() {
        return checkOption(props.getProperty("enumFuncPrefixDataPrefix"));
    }

    public String getEnumFuncPrefixToEnum() {
        return checkOption(props.getProperty("enumFuncPrefixToEnum"));
    }

    public String getEnumMapNameSuffix() {
        return checkOption(props.getProperty("enumMapNameSuffix"));
    }

    public String getEnumMapPairType() {
        return checkOption(props.getProperty("enumMapPairType"));
    }

    public String getEnumNotPresentName() {
        return checkOption(props.getProperty("enumNotPresentName"));
    }

    public String getEnumTypeNameMappingFile() {
        return checkOption(props.getProperty("enumTypeNameMappingFile"));
    }

    public String getExampleClassName() {
        return checkOption(props.getProperty("exampleClassName"));
    }

    public String getExampleNamespace() {
        return checkOption(props.getProperty("exampleNamespace"));
    }

    public String getFprintfCtorParas() {
        return checkOption(props.getProperty("fprintfCtorParas"));
    }

    public String getFPrintfParserClassName() {
        return checkOption(props.getProperty("fPrintfParserClassName"));
    }

    public String getFprintfParserFileMemberName() {
        return checkOption(props.getProperty("fprintfParserFileMemberName"));
    }

    public String getFPrintfParserNamespace() {
        return checkOption(props.getProperty("fPrintfParserNamespace"));
    }

    public String getFprintfParserPrintDoubleMethodName() {
        return checkOption(props.getProperty("fprintfParserPrintDoubleMethodName"));
    }

    public String getFprintfParserPrintFloatMethodName() {
        return checkOption(props.getProperty("fprintfParserPrintFloatMethodName"));
    }

    public String getFprintfParserPrintFloatMethodParameterName() {
        return checkOption(props.getProperty("fprintfParserPrintFloatMethodParameterName"));
    }

    public String getFprintfParserPrintFloatTemplateMethodName() {
        return checkOption(props.getProperty("fprintfParserPrintFloatMethodName"));
    }

    public boolean getGenerateCoherencyTestParser() {
        return generateCoherencyTestParser;
    }

    public boolean getGenerateExampleParser() {
        return generateExampleParser;
    }

    public boolean getGenerateFprintfParser() {
        return generateFprintfParser;
    }

    public List<String> getIncludeFilesForEnumsHeader() {
        return includeFilesForEnumsHeader;
    }

    public List<String> getIncludeFilesForEnumsSource() {
        return includeFilesForEnumsSource;
    }

    public List<String> getIncludeFilesForImpl() {
        return includeFilesForImpl;
    }

    public List<String> getIncludeFilesForPrivateHeader() {
        return includeFilesForPrivateHeader;
    }

    public String getIncludePrecompiledHeader() {
        return checkOption(props.getProperty("includePrecompiledHeader"));
    }

    public String getIndentation() {
        return checkOption(props.getProperty("indentation"));
    }

    public String getInputFile() {
        return checkOption(props.getProperty("inputFile"));
    }

    public int getMaxTemplateResolvingIterations() {
        return maxTemplateResolvingIterations;
    }

    public String getNamespace() {
        return checkOption(props.getProperty("namespace"));
    }

    public String getOutFileHeader() {
        return checkOption(props.getProperty("outFileHeader"));
    }

    public String getOutputAttributesFileName() {
        String baseName = getBaseFileName(getOutputHeaderFileNamePublic());
        return baseName + getOutputAttributesFileSuffix() + ".h";
    }

    public String getOutputAttributesFileSuffix() {
        return checkOption(props.getProperty("outputAttributesFileSuffix"));
    }

    public String getOutputCoherencyTestHeaderFileName() {
        return checkOption(props.getProperty("outputCoherencyTestHeaderFileName"));
    }

    public String getOutputCoherencyTestSourceFileName() {
        return checkOption(props.getProperty("outputCoherencyTestSourceFileName"));
    }

    public String getOutputEnumHeaderFileName() {
        String baseName = getBaseFileName(getOutputHeaderFileNamePublic());
        return baseName + getOutputEnumsFileSuffix() + ".h";
    }

    public String getOutputEnumsFileSuffix() {
        return checkOption(props.getProperty("outputEnumsFileSuffix"));
    }

    public String getOutputEnumSourceFileName() {
        String sourceOutFileBase = getOutputSourceFileNameBase();
        return sourceOutFileBase + getOutputEnumsFileSuffix() + ".cpp";
    }

    public String getOutputExampleHeaderFileName() {
        return checkOption(props.getProperty("outputExampleHeaderFileName"));
    }

    public String getOutputExampleSourceFileName() {
        return checkOption(props.getProperty("outputExampleSourceFileName"));
    }

    public String getOutputFindElementHashFileName() {
        String sourceOutFileBase = getOutputSourceFileNameBase();
        return sourceOutFileBase + getOutputFindElementHashFileSuffix() + ".cpp";
    }

    public String getOutputFindElementHashFileSuffix() {
        return checkOption(props.getProperty("outputFindElementHashFileSuffix"));
    }

    public String getOutputFPrintfHeaderFileName() {
        return checkOption(props.getProperty("outputFPrintfHeaderFileName"));
    }

    public String getOutputFPrintfSourceFileName() {
        return checkOption(props.getProperty("outputFPrintfSourceFileName"));
    }

    public String getOutputFunctionMapFactoryFileSuffix() {
        return checkOption(props.getProperty("outputFunctionMapFactoryFileSuffix"));
    }

    public String getOutputFunctionMapFactoryHeaderFileName() {
        String baseName = getBaseFileName(getOutputHeaderFileNamePublic());
        return baseName + getOutputFunctionMapFactoryFileSuffix() + ".h";
    }

    public String getOutputFunctionMapFactorySourceFileName() {
        String sourceOutFileBase = getOutputSourceFileNameBase();
        return sourceOutFileBase + getOutputFunctionMapFactoryFileSuffix() + ".cpp";
    }

    public String getOutputFunctionMapFileName() {
        String sourceOutFileBase = getOutputSourceFileNameBase();
        return sourceOutFileBase + getOutputFunctionMapFileSuffix() + ".cpp";
    }

    public String getOutputFunctionMapFileSuffix() {
        return checkOption(props.getProperty("outputFunctionMapFileSuffix"));
    }

    public String getOutputHeaderFileNamePrivate() {
        return checkOption(props.getProperty("outputHeaderFileNamePrivate"));
    }

    public String getOutputHeaderFileNamePublic() {
        return checkOption(props.getProperty("outputHeaderFileNamePublic"));
    }

    public String getOutputNameMapFileName() {
        String sourceOutFileBase = getOutputSourceFileNameBase();
        return sourceOutFileBase + getOutputNameMapFileSuffix() + ".cpp";
    }

    public String getOutputNameMapFileSuffix() {
        return checkOption(props.getProperty("outputNameMapFileSuffix"));
    }

    public String getOutputSourceFileMethodDelimiter() {
        return checkOption(props.getProperty("outputSourceFileMethodDelimiter"));
    }

    public String getOutputSourceFileNameBase() {
        return getBaseFileName(getOutputSourceFileNamePrivate());
    }

    public String getOutputSourceFileNamePrivate() {
        return checkOption(props.getProperty("outputSourceFileNamePrivate"));
    }

    public String getOutputValidationDataFileSuffix() {
        return checkOption(props.getProperty("outputValidationDataFileSuffix"));
    }

    public String getOutputValidationDataHeaderFileName() {
        String baseName = getBaseFileName(getOutputHeaderFileNamePublic());
        return baseName + getOutputValidationDataFileSuffix() + ".h";
    }

    public String getOutputValidationFileSuffix() {
        return checkOption(props.getProperty("outputValidationFileSuffix"));
    }

    public String getOutputValidationSourceFileName() {
        String sourceOutFileBase = getOutputSourceFileNameBase();
        return sourceOutFileBase + getOutputValidationFileSuffix() + ".cpp";
    }

    public String getPcreInitialNameCharacters() {
        return checkOption(props.getProperty("pcreInitialNameCharacters"));
    }

    public String getPcreInitialNameCharactersWithoutColon() {
        return checkOption(props.getProperty("pcreInitialNameCharactersWithoutColon"));
    }

    public String getPcreInitialNameCharactersWithoutColonAndDot() {
        return checkOption(props.getProperty("pcreInitialNameCharactersWithoutColonAndDot"));
    }

    public String getPcreNameCharacters() {
        return checkOption(props.getProperty("pcreNameCharacters"));
    }

    public String getPcreNameCharactersWithoutColon() {
        return checkOption(props.getProperty("pcreNameCharactersWithoutColon"));
    }

    public String getPublicImplMember() {
        return checkOption(props.getProperty("publicImplMember"));
    }

    public String getRootElementName() {
        return checkOption(props.getProperty("rootElementName"));
    }

    public String getSimpleTypeDefaultCpp() {
        return checkOption(props.getProperty("simpleTypeDefaultCpp"));
    }

    public String getSimpleValidationFunctionLengthParameterName() {
        return checkOption(props.getProperty("simpleValidationFunctionLengthParameterName"));
    }

    public String getSimpleValidationFunctionLengthParameterType() {
        return checkOption(props.getProperty("simpleValidationFunctionLengthParameterType"));
    }

    public String getSimpleValidationFunctionPrefix() {
        return checkOption(props.getProperty("simpleValidationFunctionPrefix"));
    }

    public String getSimpleValidationFunctionReturnType() {
        return checkOption(props.getProperty("simpleValidationFunctionReturnType"));
    }

    public String getSimpleValidationFunctionStreamEndSuffix() {
        return checkOption(props.getProperty("simpleValidationFunctionStreamEndSuffix"));
    }

    public String getSimpleValidationFunctionStreamSuffix() {
        return checkOption(props.getProperty("simpleValidationFunctionStreamSuffix"));
    }

    public String getSimpleValidationFunctionValueParameterName() {
        return checkOption(props.getProperty("simpleValidationFunctionValueParameterName"));
    }

    public String getSimpleValidationStreamCountStructMember() {
        return checkOption(props.getProperty("simpleValidationStreamCountStructMember"));
    }

    public List<String> getSpecialFunctionMapsStartElementNamesAllLevels() {
        return specialFunctionMapsStartElementNamesAllLevels;
    }

    public List<String> getSpecialFunctionMapsStartElementNamesOneLevel() {
        return specialFunctionMapsStartElementNamesOneLevel;
    }

    public String getStringListItemValidationFunctionParameter() {
        return checkOption(props.getProperty("stringListItemValidationFunctionParameter"));
    }

    public String getTemplateAttributeAtomicConversion() {
        return checkOption(codeTemplates.getProperty("AttributeAtomicConversion"));
    }

    public String getTemplateAttributeCheckRequiredPresent() {
        return checkOption(codeTemplates.getProperty("AttributeCheckRequiredPresent"));
    }

    public String getTemplateAttributeInitObject() {
        return checkOption(codeTemplates.getProperty("AttributeInitObject"));
    }

    public String getTemplateAttributeInitObjectNoDefaultLHS() {
        return checkOption(codeTemplates.getProperty("AttributeInitObjectNoDefaultLHS"));
    }

    public String getTemplateAttributeInitObjectUnionDefault() {
        return checkOption(codeTemplates.getProperty("AttributeInitObjectUnionDefault"));
    }

    public String getTemplateAttributeInitObjectUnionPreDefault() {
        return checkOption(codeTemplates.getProperty("AttributeInitObjectUnionPreDefault"));
    }

    public String getTemplateAttributeListConversion() {
        return checkOption(codeTemplates.getProperty("AttributeListConversion"));
    }

    public String getTemplateAttributeNotPresentCheck() {
        return checkOption(codeTemplates.getProperty("AttributeNotPresentCheck"));
    }

    public String getTemplateAttributePresentCheck() {
        return checkOption(codeTemplates.getProperty("AttributePresentCheck"));
    }

    public String getTemplateAttributePresentCheckEnumAtomic() {
        return checkOption(codeTemplates.getProperty("AttributePresentCheckEnumAtomic"));
    }

    public String getTemplateAttributePresentCheckStringAtomic() {
        return checkOption(codeTemplates.getProperty("AttributePresentCheckStringAtomic"));
    }

    public String getTemplateAttributePresentSet() {
        return checkOption(codeTemplates.getProperty("AttributePresentSet"));
    }

    public String getTemplateCoherencyTestCheckIdUnique() {
        return checkOption(codeTemplates.getProperty("CoherencyTestCheckIdUnique"));
    }

    public String getTemplateCoherencyTestSimpleCountCheckBegin() {
        return checkOption(codeTemplates.getProperty("CoherencyTestSimpleCountCheckBegin"));
    }

    public String getTemplateCoherencyTestSimpleCountCheckData() {
        return checkOption(codeTemplates.getProperty("CoherencyTestSimpleCountCheckData"));
    }

    public String getTemplateCoherencyTestSimpleCountCheckEnd() {
        return checkOption(codeTemplates.getProperty("CoherencyTestSimpleCountCheckEnd"));
    }

    public String getTemplateComplexValidationBlockClose() {
        return checkOption(codeTemplates.getProperty("ComplexValidationBlockClose"));
    }

    public String getTemplateComplexValidationBlockCloseCompileTimeOnly() {
        return checkOption(codeTemplates.getProperty("ComplexValidationBlockCloseCompileTimeOnly"));
    }

    public String getTemplateComplexValidationBlockElseCompileTime() {
        return checkOption(codeTemplates.getProperty("ComplexValidationBlockElseCompileTime"));
    }

    public String getTemplateComplexValidationBlockElseRunTime() {
        return checkOption(codeTemplates.getProperty("ComplexValidationBlockElseRunTime"));
    }

    public String getTemplateComplexValidationBlockOpen() {
        return checkOption(codeTemplates.getProperty("ComplexValidationBlockOpen"));
    }

    public String getTemplateComplexValidationBlockOpenCompileTimeOnly() {
        return checkOption(codeTemplates.getProperty("ComplexValidationBlockOpenCompileTimeOnly"));
    }

    public String getTemplateComplexValidationCheckMaxOccurence() {
        return checkOption(codeTemplates.getProperty("ComplexValidationCheckMaxOccurence"));
    }

    public String getTemplateComplexValidationCheckMinOccurencOfChildren() {
        return checkOption(codeTemplates.getProperty("ComplexValidationCheckMinOccurencOfChildren"));
    }

    public String getTemplateComplexValidationCheckStateMachine() {
        return checkOption(codeTemplates.getProperty("ComplexValidationCheckStateMachine"));
    }

    public String getTemplateComplexValidationCheckStateMachineEnd() {
        return checkOption(codeTemplates.getProperty("ComplexValidationCheckStateMachineEnd"));
    }

    public String getTemplateComplexValidationCheckStateMachineEndPerState() {
        return checkOption(codeTemplates.getProperty("ComplexValidationCheckStateMachineEndPerState"));
    }

    public String getTemplateComplexValidationCheckStateMachinePerState() {
        return checkOption(codeTemplates.getProperty("ComplexValidationCheckStateMachinePerState"));
    }

    public String getTemplateComplexValidationChildValidateBegin() {
        return checkOption(codeTemplates.getProperty("ComplexValidationChildValidateBegin"));
    }

    public String getTemplateComplexValidationChildValidateBeginNestedModelGroup() {
        return checkOption(codeTemplates.getProperty("ComplexValidationChildValidateBeginNestedModelGroup"));
    }

    public String getTemplateComplexValidationChoiceCheckMinOccurencOfChildren() {
        return checkOption(codeTemplates.getProperty("ComplexValidationChoiceCheckMinOccurencOfChildren"));
    }

    public String getTemplateComplexValidationChoiceCheckOneChildPresent() {
        return checkOption(codeTemplates.getProperty("ComplexValidationChoiceCheckOneChildPresent"));
    }

    public String getTemplateComplexValidationChoiceCheckOneChildPresentPerChild() {
        return checkOption(codeTemplates.getProperty("ComplexValidationChoiceCheckOneChildPresentPerChild"));
    }

    public String getTemplateComplexValidationChoiceCheckSiblilngs() {
        return checkOption(codeTemplates.getProperty("ComplexValidationChoiceCheckSiblilngs"));
    }

    public String getTemplateComplexValidationCreateValidationData() {
        return checkOption(codeTemplates.getProperty("ComplexValidationCreateValidationData"));
    }

    public String getTemplateComplexValidationDeleteValidationData() {
        return checkOption(codeTemplates.getProperty("ComplexValidationDeleteValidationData"));
    }

    public String getTemplateComplexValidationGetTopParentValidationData() {
        return checkOption(codeTemplates.getProperty("ComplexValidationGetTopParentValidationData"));
    }

    public String getTemplateComplexValidationGetTopValidationData() {
        return checkOption(codeTemplates.getProperty("ComplexValidationGetTopValidationData"));
    }

    public String getTemplateComplexValidationIncrementOccurence() {
        return checkOption(codeTemplates.getProperty("ComplexValidationIncrementOccurence"));
    }

    public String getTemplateComplexValidationInitStateMachine() {
        return checkOption(codeTemplates.getProperty("ComplexValidationInitStateMachine"));
    }

    public String getTemplateComplexValidationParentValidateEnd() {
        return checkOption(codeTemplates.getProperty("ComplexValidationParentValidateEnd"));
    }

    public String getTemplateComplexValidationParentValidateEndNestedModelGroups() {
        return checkOption(codeTemplates.getProperty("ComplexValidationParentValidateEndNestedModelGroups"));
    }

    public String getTemplateComplexValidationSequCheckNext() {
        return checkOption(codeTemplates.getProperty("ComplexValidationSequCheckNext"));
    }

    public String getTemplateComplexValidationSequCheckPrev() {
        return checkOption(codeTemplates.getProperty("ComplexValidationSequCheckPrev"));
    }

    public String getTemplateComplexValidationSetStateMachineState() {
        return checkOption(codeTemplates.getProperty("ComplexValidationSetStateMachineState"));
    }

    public String getTemplateDataAtomicConversion() {
        return checkOption(codeTemplates.getProperty("DataAtomicConversion"));
    }

    public String getTemplateDataAtomicDataMethod() {
        return checkOption(codeTemplates.getProperty("DataAtomicDataMethod"));
    }

    public String getTemplateDataListConversion() {
        return checkOption(codeTemplates.getProperty("DataListConversion"));
    }

    public String getTemplateDataListValidateEnd() {
        return checkOption(codeTemplates.getProperty("DataListValidateEnd"));
    }

    public String getTemplateDisableWarningUnused() {
        return checkOption(codeTemplates.getProperty("DisableWarningUnused"));
    }

    public String getTemplateEnumDataAtomicConversion() {
        return checkOption(codeTemplates.getProperty("EnumDataAtomicConversion"));
    }

    /**
     * <pre>
     * bool characterData2EnumData_stringEnumType(const ParserChar* text, 
     *                                            size_t textLength, 
     *                                            bool ( ColladaParserAutoGen::*dataFunction ) (const stringEnumType* data, size_t dataLength )
     *                                            );
     * 
     * </pre>
     */
    public String getTemplateEnumFuncCharDataDecl() {
        return checkOption(codeTemplates.getProperty("EnumFuncCharDataDecl"));
    }

    /**
     * <pre>
     * return characterData2EnumData&lt;stringEnumType, StringHash, stringEnumType__COUNT&gt;(text, textLength, dataFunction, stringEnumTypeMap, &amp;Utils::calculateStringHash, &amp;toEnum_stringEnumType, &amp;ColladaParserAutoGenPrivate::toEnumDataPrefix_stringEnumType);
     * </pre>
     */
    public String getTemplateEnumFuncCharDataImpl() {
        return checkOption(codeTemplates.getProperty("EnumFuncCharDataImpl"));
    }

    /**
     * <pre>
     * bool dataEnumEnd_stringEnumType(bool ( ColladaParserAutoGen::*dataFunction ) (const stringEnumType* data, size_t dataLength ),
     *                                 const std::pair&lt;StringHash, stringEnumType&gt;* enumMap,
     *                                 StringHash (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool&amp; failed),
     *                                 stringEnumType (*toEnum)( const ParserChar** buffer, 
     *                                     const ParserChar* bufferEnd,
     *                                     bool&amp; failed, 
     *                                     const std::pair&lt;StringHash, stringEnumType&gt;* enumMap,
     *                                     StringHash (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool&amp; failed)
     *                                 ));
     * 
     * </pre>
     */
    public String getTemplateEnumFuncDataEndDecl() {
        return checkOption(codeTemplates.getProperty("EnumFuncDataEndDecl"));
    }

    /**
     * <pre>
     * return dataEnumEnd&lt;stringEnumType, StringHash, stringEnumType__COUNT&gt;(dataFunction, enumMap, baseConversionFunctionPtr, toEnum);
     * </pre>
     */
    public String getTemplateEnumFuncDataEndImpl() {
        return checkOption(codeTemplates.getProperty("EnumFuncDataEndImpl"));
    }

    /**
     * <pre>
     * stringEnumType toEnumDataPrefix_stringEnumType(const ParserChar* prefixedBuffer,
     *                                                const ParserChar* prefixedBufferEnd,
     *                                                const ParserChar** buffer,
     *                                                const ParserChar* bufferEnd, 
     *                                                bool&amp; failed,
     *                                                const std::pair&lt;StringHash, stringEnumType&gt;* enumMap,
     *                                                StringHash (*baseConversionFunctionPtr)(const ParserChar** buffer, const ParserChar* bufferEnd, bool&amp; failed)
     *                                                );
     * 
     * </pre>
     */
    public String getTemplateEnumFuncDataPrefixDecl() {
        return checkOption(codeTemplates.getProperty("EnumFuncDataPrefixDecl"));
    }

    /**
     * <pre>
     * return toEnumDataPrefix&lt;stringEnumType, StringHash, stringEnumType__COUNT, &amp;toEnum_stringEnumType&gt;(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed, stringEnumTypeMap, Utils::calculateStringHash);
     * </pre>
     */
    public String getTemplateEnumFuncDataPrefixImpl() {
        return checkOption(codeTemplates.getProperty("EnumFuncDataPrefixImpl"));
    }

    /**
     * <pre>
     * stringEnumType toEnum_stringEnumType(const ParserChar** buffer,
     *                                      const ParserChar* bufferEnd,
     *                                      bool&amp; failed,
     *                                      const std::pair&lt;StringHash, stringEnumType&gt;* stringEnumTypeMap,
     *                                      StringHash (*calculateStringHash)( const ParserChar**, const ParserChar*, bool&amp; )
     *                                      );
     * </pre>
     */
    public String getTemplateEnumFuncToEnumDecl() {
        return checkOption(codeTemplates.getProperty("EnumFuncToEnumDecl"));
    }

    /**
     * 
     * <pre>
     * return Utils::toEnum&lt;stringEnumType, StringHash, stringEnumType__COUNT&gt;(buffer, bufferEnd, failed, stringEnumTypeMap, calculateStringHash);
     * </pre>
     */
    public String getTemplateEnumFuncToEnumImpl() {
        return checkOption(codeTemplates.getProperty("EnumFuncToEnumImpl"));
    }

    public String getTemplateEnumMapDeclaration() {
        return checkOption(codeTemplates.getProperty("EnumMapDeclaration"));
    }

    public String getTemplateEnumMapDefinitionStart() {
        return checkOption(codeTemplates.getProperty("EnumMapDefinitionStart"));
    }

    public String getTemplateEnumMapEntry() {
        return checkOption(codeTemplates.getProperty("EnumMapEntry"));
    }

    public String getTemplateEnumMapEntryType() {
        return checkOption(codeTemplates.getProperty("EnumMapEntryType"));
    }

    public String getTemplateFindHashSetValues() {
        return checkOption(codeTemplates.getProperty("FindHashSetValues"));
    }

    public String getTemplateFprintfCloseFile() {
        return checkOption(codeTemplates.getProperty("FprintfCloseFile"));
    }

    public String getTemplateFprintfOpenFile() {
        return checkOption(codeTemplates.getProperty("FprintfOpenFile"));
    }

    public String getTemplateFprintfPrintDouble() {
        return checkOption(codeTemplates.getProperty("FprintfPrintDouble"));
    }

    public String getTemplateFprintfPrintFloat() {
        return checkOption(codeTemplates.getProperty("FprintfPrintFloat"));
    }

    public String getTemplateFprintfPrintFloatTemplate() {
        return checkOption(codeTemplates.getProperty("FprintfPrintFloatTemplate"));
    }

    public String getTemplateFprintfUnknownAttributes() {
        return checkOption(codeTemplates.getProperty("FprintfUnknownAttributes"));
    }

    public String getTemplateFprintfUnknownElementBegin() {
        return checkOption(codeTemplates.getProperty("FprintfUnknownElementBegin"));
    }

    public String getTemplateFprintfUnknownElementData() {
        return checkOption(codeTemplates.getProperty("FprintfUnknownElementData"));
    }

    public String getTemplateFprintfUnknownElementEnd() {
        return checkOption(codeTemplates.getProperty("FprintfUnknownElementEnd"));
    }

    public String getTemplateFreeAttrList() {
        return checkOption(codeTemplates.getProperty("FreeAttrList"));
    }

    public String getTemplateFreeAttrStruct() {
        return checkOption(codeTemplates.getProperty("FreeAttrStruct"));
    }

    public String getTemplateFreeUnknownAttributes() {
        return checkOption(codeTemplates.getProperty("FreeUnknownAttributes"));
    }

    public String getTemplateParseAttrDefaultXMLNS() {
        return checkOption(codeTemplates.getProperty("ParseAttrDefaultXMLNS"));
    }

    public String getTemplateParseAttrXMLNS() {
        return checkOption(codeTemplates.getProperty("ParseAttrXMLNS"));
    }

    public String getTemplateSimpleValidationDefaultReturn() {
        return checkOption(codeTemplates.getProperty("SimpleValidationDefaultReturn"));
    }

    public String getTemplateSimpleValidationDeleteValidationDataNoValidation() {
        return checkOption(codeTemplates.getProperty("SimpleValidationDeleteValidationDataNoValidation"));
    }

    public String getTemplateSimpleValidationGetCountStructMemberNoValidation() {
        return checkOption(codeTemplates.getProperty("SimpleValidationGetCountStructMemberNoValidation"));
    }

    public String getTemplateSimpleValidationGetCountStructMemberValidation() {
        return checkOption(codeTemplates.getProperty("SimpleValidationGetCountStructMemberValidation"));
    }

    public String getTemplateSimpleValidationGetValidationDataNoValidation() {
        return checkOption(codeTemplates.getProperty("SimpleValidationGetValidationDataNoValidation"));
    }

    public String getTemplateSimpleValidationLength() {
        return checkOption(codeTemplates.getProperty("SimpleValidationLength"));
    }

    public String getTemplateSimpleValidationLengthStream() {
        return checkOption(codeTemplates.getProperty("SimpleValidationLengthStream"));
    }

    public String getTemplateSimpleValidationLengthStreamEnd() {
        return checkOption(codeTemplates.getProperty("SimpleValidationLengthStreamEnd"));
    }

    public String getTemplateSimpleValidationMaxExclusive() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMaxExclusive"));
    }

    public String getTemplateSimpleValidationMaxInclusive() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMaxInclusive"));
    }

    public String getTemplateSimpleValidationMaxLength() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMaxLength"));
    }

    public String getTemplateSimpleValidationMaxLengthStream() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMaxLengthStream"));
    }

    public String getTemplateSimpleValidationMaxLengthStreamEnd() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMaxLengthStreamEnd"));
    }

    public String getTemplateSimpleValidationMinExclusive() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMinExclusive"));
    }

    public String getTemplateSimpleValidationMinInclusive() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMinInclusive"));
    }

    public String getTemplateSimpleValidationMinLength() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMinLength"));
    }

    public String getTemplateSimpleValidationMinLengthStream() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMinLengthStream"));
    }

    public String getTemplateSimpleValidationMinLengthStreamEnd() {
        return checkOption(codeTemplates.getProperty("SimpleValidationMinLengthStreamEnd"));
    }

    public String getTemplateSimpleValidationNumericAtomicAttribute() {
        return checkOption(codeTemplates.getProperty("SimpleValidationNumericAtomicAttribute"));
    }

    public String getTemplateSimpleValidationNumericAtomicData() {
        return checkOption(codeTemplates.getProperty("SimpleValidationNumericAtomicData"));
    }

    public String getTemplateSimpleValidationNumericListAttribute() {
        return checkOption(codeTemplates.getProperty("SimpleValidationNumericListAttribute"));
    }

    public String getTemplateSimpleValidationNumericListData() {
        return checkOption(codeTemplates.getProperty("SimpleValidationNumericListData"));
    }

    public String getTemplateSimpleValidationNumericListDataEnd() {
        return checkOption(codeTemplates.getProperty("SimpleValidationNumericListDataEnd"));
    }

    public String getTemplateSimpleValidationPattern() {
        return checkOption(codeTemplates.getProperty("SimpleValidationPattern"));
    }

    public String getTemplateSimpleValidationSpecialStreamEndVali() {
        return checkOption(codeTemplates.getProperty("SimpleValidationSpecialStreamEndVali"));
    }

    public String getTemplateSimpleValidationSpecialStreamEndValiHandleError() {
        return checkOption(codeTemplates.getProperty("SimpleValidationSpecialStreamEndValiHandleError"));
    }

    public String getTemplateSimpleValidationStringAtomicAttribute() {
        return checkOption(codeTemplates.getProperty("SimpleValidationStringAtomicAttribute"));
    }

    public String getTemplateSimpleValidationStringAtomicData() {
        return checkOption(codeTemplates.getProperty("SimpleValidationStringAtomicData"));
    }

    public String getTemplateSimpleValidationStringAtomicDataEnd() {
        return checkOption(codeTemplates.getProperty("SimpleValidationStringAtomicDataEnd"));
    }

    public String getTemplateSimpleValidationStringListAttribute() {
        return checkOption(codeTemplates.getProperty("SimpleValidationStringListAttribute"));
    }

    public String getTemplateSimpleValidationStringListItemImpl() {
        return checkOption(codeTemplates.getProperty("SimpleValidationStringListItemImpl"));
    }

    public String getTemplateSimpleValidationUpdateStreamCount() {
        return checkOption(codeTemplates.getProperty("SimpleValidationUpdateStreamCount"));
    }

    public String getTemplateTypeMappingDefaultAttrAtomicXsd2cppRhs() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultAttrAtomicXsd2cppRhs"));
    }

    public String getTemplateTypeMappingDefaultAttrListXsd2cppRhs() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultAttrListXsd2cppRhs"));
    }

    public String getTemplateTypeMappingDefaultDataAtomicConversion() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultDataAtomicConversion"));
    }

    public String getTemplateTypeMappingDefaultDataAtomicDataMethodImpl() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultDataAtomicDataMethodImpl"));
    }

    public String getTemplateTypeMappingDefaultDataAtomicValidateEndFacetPattern() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultDataAtomicValidateEndFacetPattern"));
    }

    public String getTemplateTypeMappingDefaultDataAtomicXsd2cppRhs() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultDataAtomicXsd2cppRhs"));
    }

    public String getTemplateTypeMappingDefaultDataListXsd2cppLhs() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultDataListXsd2cppLhs"));
    }

    public String getTemplateTypeMappingDefaultDataListXsd2cppValidationLhs() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultDataListXsd2cppValidationLhs"));
    }

    public String getTemplateTypeMappingDefaultEnumSringAttrAtomicXsd2cpp() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultEnumSringAttrAtomicXsd2cpp"));
    }

    public String getTemplateTypeMappingDefaultEnumSringDataAtomicXsd2cpp() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultEnumSringDataAtomicXsd2cpp"));
    }

    public String getTemplateTypeMappingDefaultEnumSringDataListDataend() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultEnumSringDataListDataend"));
    }

    public String getTemplateTypeMappingDefaultEnumSringDataListXsd2cpp() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultEnumSringDataListXsd2cpp"));
    }

    public String getTemplateTypeMappingDefaultPostAttrAtomicXsd2cpp() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultPostAttrAtomicXsd2cpp"));
    }

    public String getTemplateTypeMappingDefaultPostDataAtomicXsd2cpp() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultPostDataAtomicXsd2cpp"));
    }

    public String getTemplateTypeMappingDefaultPreAttrAtomicXsd2cpp() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultPreAttrAtomicXsd2cpp"));
    }

    public String getTemplateTypeMappingDefaultPreDataAtomicXsd2cpp() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultPreDataAtomicXsd2cpp"));
    }

    public String getTemplateTypeMappingDefaultSringDataXsd2cpp() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultSringDataXsd2cpp"));
    }

    public String getTemplateTypeMappingDefaultUnionDataAtomicXsd2cppRhs() {
        return checkOption(codeTemplates.getProperty("TypeMappingDefaultUnionDataAtomicXsd2cppRhs"));
    }

    public String getTemplateUnionAttributeAtomicConversion() {
        return checkOption(codeTemplates.getProperty("UnionAttributeAtomicConversion"));
    }

    public String getTemplateUnionAttributeAtomicPostXsd2Cpp() {
        return checkOption(codeTemplates.getProperty("UnionAttributeAtomicPostXsd2Cpp"));
    }

    public String getTemplateUnionAttributeAtomicPreXsd2Cpp() {
        return checkOption(codeTemplates.getProperty("UnionAttributeAtomicPreXsd2Cpp"));
    }

    public String getTemplateUnionAttributeAtomicXsd2Cpp() {
        return checkOption(codeTemplates.getProperty("UnionAttributeAtomicXsd2Cpp"));
    }

    public String getTemplateUnionAttributeListType() {
        return checkOption(codeTemplates.getProperty("UnionAttributeListType"));
    }

    public String getTemplateUnionAttributeListTypeConversionItemValidation() {
        return checkOption(codeTemplates.getProperty("UnionAttributeListTypeConversionItemValidation"));
    }

    public String getTemplateUnionAttributeListTypeConversionNoItemValidation() {
        return checkOption(codeTemplates.getProperty("UnionAttributeListTypeConversionNoItemValidation"));
    }

    public String getTemplateUnionDataAtomicConversion() {
        return checkOption(codeTemplates.getProperty("UnionDataAtomicConversion"));
    }

    public String getTemplateUnionDataAtomicDataMethod() {
        return checkOption(codeTemplates.getProperty("UnionDataAtomicDataMethod"));
    }

    public String getTemplateUnionDataAtomicDataMethodImpl() {
        return checkOption(codeTemplates.getProperty("UnionDataAtomicDataMethodImpl"));
    }

    public String getTemplateUnionDataAtomicPostXsd2Cpp() {
        return checkOption(codeTemplates.getProperty("UnionDataAtomicPostXsd2Cpp"));
    }

    public String getTemplateUnionDataAtomicPreXsd2Cpp() {
        return checkOption(codeTemplates.getProperty("UnionDataAtomicPreXsd2Cpp"));
    }

    public String getTemplateUnionDataAtomicXsd2Cpp() {
        return checkOption(codeTemplates.getProperty("UnionDataAtomicXsd2Cpp"));
    }

    public String getTemplateUnionDataListEnd() {
        return checkOption(codeTemplates.getProperty("UnionDataListEnd"));
    }

    public String getTemplateUnionDataListEndValidation() {
        return checkOption(codeTemplates.getProperty("UnionDataListEndValidation"));
    }

    public String getTemplateUnionDataListType() {
        return checkOption(codeTemplates.getProperty("UnionDataListType"));
    }

    public String getTemplateUnionDataListTypeConversion() {
        return checkOption(codeTemplates.getProperty("UnionDataListTypeConversion"));
    }

    public String getTemplateUnionDataListTypeConversionValidation() {
        return checkOption(codeTemplates.getProperty("UnionDataListTypeConversionValidation"));
    }

    public String getTemplateUnionEnumMemberConversion() {
        return checkOption(codeTemplates.getProperty("UnionEnumMemberConversion"));
    }

    public String getTemplateUnionFuncDataPrefixDecl() {
        return checkOption(codeTemplates.getProperty("UnionFuncDataPrefixDecl"));
    }

    public String getTemplateUnionFuncDataPrefixImpl() {
        return checkOption(codeTemplates.getProperty("UnionFuncDataPrefixImpl"));
    }

    public String getTemplateUnionFuncToUnionBufferEndPtrDecl() {
        return checkOption(codeTemplates.getProperty("UnionFuncToUnionBufferEndPtrDecl"));
    }

    public String getTemplateUnionFuncToUnionBufferEndPtrImpl() {
        return checkOption(codeTemplates.getProperty("UnionFuncToUnionBufferEndPtrImpl"));
    }

    public String getTemplateUnionFuncToUnionDecl() {
        return checkOption(codeTemplates.getProperty("UnionFuncToUnionDecl"));
    }

    public String getTemplateUnionFuncToUnionImpl() {
        return checkOption(codeTemplates.getProperty("UnionFuncToUnionImpl"));
    }

    public String getTemplateUnionFuncToUnionNullTermiDecl() {
        return checkOption(codeTemplates.getProperty("UnionFuncToUnionNullTermiDecl"));
    }

    public String getTemplateUnionFuncToUnionNullTermiImpl() {
        return checkOption(codeTemplates.getProperty("UnionFuncToUnionNullTermiImpl"));
    }

    public String getTemplateUnionFuncToUnionPerMember() {
        return checkOption(codeTemplates.getProperty("UnionFuncToUnionPerMember"));
    }

    public String getTemplateUnionMemberTypeConversionFunctionParametersEnumAddon() {
        return checkOption(codeTemplates.getProperty("UnionMemberTypeConversionFunctionParametersEnumAddon"));
    }

    public String getTemplateValidateBeginPostSwitch() {
        return checkOption(codeTemplates.getProperty("ValidateBeginPostSwitch"));
    }

    public String getTemplateValidateBeginPreSwitch() {
        return checkOption(codeTemplates.getProperty("ValidateBeginPreSwitch"));
    }

    public String getTemplateValidateBeginSwitchDefault() {
        return checkOption(codeTemplates.getProperty("ValidateBeginSwitchDefault"));
    }

    public String getTemplateValidateBeginSwitchDefaultUnknownAttributes() {
        return checkOption(codeTemplates.getProperty("ValidateBeginSwitchDefaultUnknownAttributes"));
    }

    public String getTypedAttributeDataVariableName() {
        return checkOption(props.getProperty("typedAttributeDataVariableName"));
    }

    public Map<String, TypeMap> getTypeMapping() {
        return typeMapping;
    }

    public String getTypeNameMappingSeparator() {
        return checkOption(props.getProperty("typeNameMappingSeparator"));
    }

    public String getUnionDataMemberName() {
        return checkOption(props.getProperty("unionDataMemberName"));
    }

    public String getUnionFuncPrefixToUnion() {
        return checkOption(props.getProperty("unionFuncPrefixToUnion"));
    }

    public String getUnionFuncPrefixToUnionPrefix() {
        return checkOption(props.getProperty("unionFuncPrefixToUnionPrefix"));
    }

    public String getUnionInvalidTypeName() {
        return checkOption(props.getProperty("unionInvalidTypeName"));
    }

    public String getUnionMemberTypeConversionFunctionParameters() {
        return checkOption(props.getProperty("unionMemberTypeConversionFunctionParameters"));
    }

    public String getUnionTypeMemberName() {
        return checkOption(props.getProperty("unionTypeMemberName"));
    }

    public String getUnknownAttributesMemberInit() {
        return checkOption(props.getProperty("unknownAttributesMemberInit"));
    }

    public String getUnknownAttributesMemberName() {
        return checkOption(props.getProperty("unknownAttributesMemberName"));
    }

    public String getUnknownAttributesMemberType() {
        return checkOption(props.getProperty("unknownAttributesMemberType"));
    }

    public String getUnknownAttributeType() {
        return checkOption(props.getProperty("unknownAttributeType"));
    }

    public Map<String, String> getUserTypeNameMapping() {
        return userTypeNameMapping;
    }

    public String getValidationDataStructMemberType() {
        return checkOption(props.getProperty("validationDataStructMemberType"));
    }

    public String getValidationDataStructSuffix() {
        return checkOption(props.getProperty("validationDataStructSuffix"));
    }

    public String getWildcardValidationDataStructName() {
        return checkOption(props.getProperty("wildcardValidationDataStructName"));
    }

    public String getXSNamespace() {
        return checkOption(props.getProperty("xsNamespace"));
    }

    public Map<String, String> getXsNamespaceMapping() {
        return xsNamespaceMapping;
    }

    public boolean isTreatXsDoubleAsCppDouble() {
        return treatXsDoubleAsCppDouble;
    }

    public boolean isTreatXsFloatAsCppFloat() {
        return treatXsFloatAsCppFloat;
    }

    public boolean isTypeNameMappingGenerationTurnedOn() {
        return generateTypeNameMapping;
    }

    protected List<String> parseListOption(String value) {
        List<String> list = new ArrayList<String>();
        if (value == null) {
            return list;
        }
        String[] split = value.split(" ");
        for (String tmp : split) {
            list.add(tmp.trim());
        }
        return list;
    }

    protected Map<String, String> parseMapOption(String value) {
        Map<String, String> map = new HashMap<String, String>();
        if (value == null) {
            return map;
        }
        String[] split = value.split(";");
        if (split.length == 1 && split[0].length() == 0) {
            return map;
        }
        for (String tmp : split) {
            String[] split2 = tmp.split("=");
            if (split2.length != 2) {
                System.err.println("illegal map entry: " + tmp);
            } else {
                String parsedKey = split2[0].trim();
                String parsedValue = split2[1].trim();
                map.put(parsedKey, parsedValue);
            }
        }
        return map;
    }
}
