/**
 *   Copyright &copy; 2008-2013 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

import org.apache.xerces.xs.StringList;
import org.apache.xerces.xs.XSAttributeUse;
import org.apache.xerces.xs.XSComplexTypeDefinition;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSImplementation;
import org.apache.xerces.xs.XSLoader;
import org.apache.xerces.xs.XSModel;
import org.apache.xerces.xs.XSModelGroup;
import org.apache.xerces.xs.XSNamespaceItemList;
import org.apache.xerces.xs.XSObjectList;
import org.apache.xerces.xs.XSParticle;
import org.apache.xerces.xs.XSSimpleTypeDefinition;
import org.apache.xerces.xs.XSTerm;
import org.apache.xerces.xs.XSTypeDefinition;
import org.apache.xerces.xs.XSWildcard;
import org.w3c.dom.DOMConfiguration;
import org.w3c.dom.DOMError;
import org.w3c.dom.DOMErrorHandler;
import org.w3c.dom.bootstrap.DOMImplementationRegistry;

import de.netallied.xsd2cppsax.printers.CodePrinterFactory;
import de.netallied.xsd2cppsax.printers.ICodePrinter;
import de.netallied.xsd2cppsax.printers.PrinterUtils;
import de.netallied.xsd2cppsax.statemachine.StateMachineBuilder;
import de.netallied.xsd2cppsax.statemachine.StateMachineRootNode;

/**
 * The code generator.
 * 
 */
public class Generator extends AbstractStackBasedTraverser implements DOMErrorHandler, IGenerationDataProvider {

    /** Generated C++ header file of attributes. */
    private PrintStream attrHeaderFile;

    /** Collected element usage data. Key: XSD element name. */
    private Map<String, ElementUsage> completeElementUsage;

    /** Used to create names for C++ enums. */
    private CppEnumNameCreator cppEnumOrUnionNameCreator;

    /** C++ element names. */
    private Map<XSElementDeclaration, CppElementNameParentTypesPair> elementNameMapping;

    /**
     * Contains generated C++ element names which have already been handled. To
     * prevent name clashes.
     */
    private Set<String> elementNamesAlreadyHandled = new HashSet<String>();

    /**
     * Elements at which generated code shall ignore xml namespace declarations.
     */
    private SortedSet<XSElementDeclaration> elementsToIgnoreNSDecls = new TreeSet<XSElementDeclaration>(
            new XSElementComparator());

    /**
     * Elements at which hand written code shall look for xml namespace
     * declarations.
     */
    private SortedSet<XSElementDeclaration> elementsToParseNSDecls = new TreeSet<XSElementDeclaration>(
            new XSElementComparator());

    /** Contains elements which may have any children. */
    private SortedSet<XSElementDeclaration> elementsWithXsAny = new TreeSet<XSElementDeclaration>(
            new XSElementComparator());

    /** Generated C++ header file containing enums. */
    private PrintStream enumHeaderFile;

    /** Generated C++ source file containing enums. */
    private PrintStream enumSourceFile;

    /**
     * When somewhere during generation a enum is found, it is added here to be
     * handled later.
     */
    private List<EnumNameTypePair> enumsToBeHandled = new ArrayList<EnumNameTypePair>();

    /** Generated file containing suggested better names for enums. */
    private PrintStream enumTypeMappingFile;

    /** Generated C++ source file containing findElementHash function. */
    private PrintStream findElementHashFile;

    /** Generated C++ source file containing function map. */
    private PrintStream functionMapFile;

    /** Generated C++ source file containing name map. */
    private PrintStream nameMapFile;

    /** Names of attribute structs which have already been printed. */
    private Set<String> printedAttributeStructs = new HashSet<String>();

    /** Stores C++ enum type names which have already been printed. */
    private Set<String> printedEnums = new HashSet<String>();

    /** Names of validation functions which have already been printed. */
    private Set<String> printedSimpleValidationFunctions = new HashSet<String>();

    /** Stores C++ union type names which have already been printed. */
    private Set<String> printedUnions = new HashSet<String>();

    /** Names of validation data structs which have already been printed. */
    private Set<String> printedValidationDataStructs = new HashSet<String>();

    /** Code printers to be used during generation. */
    private List<ICodePrinter> printers = new ArrayList<ICodePrinter>();

    /** Generated C++ header file of private implementation class. */
    private PrintStream privateImplHeaderFile;

    /** Generated C++ source file of private implementation class. */
    private PrintStream privateImplSourceFile;

    /** Generated C++ header file of public implementation class. */
    private PrintStream publicImplHeaderFile;

    /** Contains state machines per type. */
    private Map<XSTypeDefinition, StateMachineRootNode> stateMachineMap = new HashMap<XSTypeDefinition, StateMachineRootNode>();

    /**
     * Key is an element which may be substituted with elements from the value
     * list.
     */
    private Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups;

    /** Map of XSD types to an ID used in generated code. */
    private Map<XSTypeDefinition, String> typeIdMapping;

    /** Contains XSD type name (str1) and C++ type name (str2) of union members. */
    private Map<XSSimpleTypeDefinition, Map<XSSimpleTypeDefinition, StringPair>> unionMemberTypeMap = new HashMap<XSSimpleTypeDefinition, Map<XSSimpleTypeDefinition, StringPair>>();

    /**
     * When somewhere during generation a union is found, it is added here to be
     * handled later.
     */
    private List<EnumNameTypePair> unionsToBeHandled = new ArrayList<EnumNameTypePair>();

    /** Generated C++ header file of validation data structs. */
    private PrintStream valiHeaderFile;

    /** Generated C++ file containing validation functions and methods. */
    private PrintStream valiSourceFile;

    /** Stores C++ validation function names printed for xs simple types. */
    private Map<XSSimpleTypeDefinition, String> xsSimpleType2validationFunctionName;

    /** Stores C++ attribute struct names printed for xs types. */
    private Map<XSTypeDefinition, String> xsType2attributeStructName = new HashMap<XSTypeDefinition, String>();

    /** Stores C++ validation data struct names printed for xs types. */
    private Map<XSTypeDefinition, String> xsType2validationDataStructName = new HashMap<XSTypeDefinition, String>();

    /**
     * Constructor.
     */
    public Generator(Config config) {
        super(config);
    }

    /**
     * Creates parameter list of convenience begin method.
     * 
     * @param cppName
     *            C++ element name to create begin method for.
     * @param element
     *            XSD representation of element.
     * @param attributesRequired
     *            Indicates if attributes must be passed.
     * @return Parameter list.
     */
    protected String createBeginConvenienceMethodParameterList(String cppName, XSElementDeclaration element,
            boolean attributesRequired) {
        String paraList = new String("(");
        if (attributesRequired) {
            paraList += " const " + Util.createAttributeStructName(cppName, element, config, completeElementUsage)
                    + "& " + config.getAttributeDataParameterName() + " ";
        }
        paraList += ")";
        return paraList;
    }

    /**
     * Creates C++ Type of hashes.
     * 
     * @return Type.
     */
    protected String createCppHashType() {
        // currently without static
        // return "static const StringHash";
        return "const StringHash";
    }

    /**
     * Creates C++ Type of element name constants.
     * 
     * @return Type.
     */
    protected String createCppNameConstantType() {
        return "const char*";
    }

    /**
     * Creates name of C++ method to access character data.
     * 
     * @param cppElementName
     *            C++ element name.
     * @return Method name.
     */
    protected String createDataConvenienceMethodName(String cppElementName) {
        return "data__" + cppElementName;
    }

    /**
     * Creates parameter list of data convenience method.
     */
    protected String createDataConvenienceParameterList(XSTypeDefinition type) {
        XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(type);
        Variety variety = Util.findVariety(simpleType);
        if (variety == Variety.LIST) {
            simpleType = Util.findListItemType(simpleType);
        }
        String xsdType = Util.findXSDSimpleTypeString(simpleType, config);

        String cppType = null;
        switch (variety) {
        case LIST:
            if (Util.findVariety(simpleType) == Variety.UNION) {
                cppType = config.getTemplateUnionDataListType();
                cppType = TemplateEngine.fillInUnionTemplate(cppType, simpleType, this);
            } else if (Util.hasFacetEnum(simpleType)) {
                cppType = "const " + cppEnumOrUnionNameCreator.createEnumTypeName(simpleType, getElementStack()) + "*";
            } else {
                cppType = config.getTypeMapping().get(xsdType).getDataListType();
            }
            break;
        case ATOMIC:
            if (Util.hasFacetEnum(simpleType)) {
                cppType = "const " + cppEnumOrUnionNameCreator.createEnumTypeName(simpleType, getElementStack());
            } else {
                cppType = config.getTypeMapping().get(xsdType).getDataAtomicType();
            }
            break;
        case UNION:
            cppType = cppEnumOrUnionNameCreator.createUnionTypeName(simpleType, getElementStack());
            break;
        }

        cppType = TemplateEngine.fillInTypeMappingTemplate(cppType, cppType, null, this);

        String paraList = "( " + cppType + " " + config.getConvenienceDataMethodValueParameterName();

        // TODO better recognition if length is needed
        if (cppType.contains("*")) {
            paraList += ", size_t " + config.getConvenienceDataMethodLengthParameterName();
        }
        paraList += " )";
        return paraList;
    }

    /**
     * @return Name of C++ ElementToNamespace map member.
     */
    protected String createElementToNamespaceMapMembername() {
        return "mElementToNamespaceMap";
    }

    /**
     * Creates parameter list of convenience begin method.
     * 
     * @return Parameter list.
     */
    protected String createEndMethodParameterList() {
        return "()";
    }

    /**
     * @return Name of C++ function map member.
     */
    protected String createFunctionMapMembername() {
        return "mElementFunctionMap";
    }

    /**
     * @return Name of C++ name map member.
     */
    protected String createNameMapMembername() {
        return "mHashNameMap";
    }

    /**
     * Iterates over all types in XSD and gives each an ID.
     * 
     * @param elemUsage
     *            ElementUsage information to get all types.
     * @return Type ID mapping.
     */
    protected Map<XSTypeDefinition, String> createTypeIdMapping(Map<String, ElementUsage> elemUsage) {
        SortedMap<XSTypeDefinition, String> map = new TreeMap<XSTypeDefinition, String>(new XSTypeComparator());
        int i = 1; // important: do NOT start with 0
        for (String elemName : elemUsage.keySet()) {
            ElementUsage elementUsage = elemUsage.get(elemName);
            for (XSTypeDefinition type : elementUsage.getTypes()) {
                if (!map.containsKey(type)) {
                    map.put(type, String.valueOf(i++));
                    stateMachineMap.put(type, new StateMachineBuilder().build(type));
                }
            }
        }
        return map;
    }

    /**
     * Finds C++ type as string. Takes care of simple and complex type, base
     * types and variety.
     * 
     * @see #findCorrectCppTypeForAttribute(XSTypeDefinition)
     * 
     * @param memberType
     *            XSD type to find C++ type for.
     * @return C++ type.
     */
    protected String findCorrectCppTypeAsUnionMember(XSSimpleTypeDefinition unionType, XSSimpleTypeDefinition memberType) {
        Map<XSSimpleTypeDefinition, StringPair> map = unionMemberTypeMap.get(unionType);
        if (map == null) {
            map = new HashMap<XSSimpleTypeDefinition, StringPair>();
            unionMemberTypeMap.put(unionType, map);
        }
        StringPair stringPair = map.get(memberType);
        if (stringPair != null) {
            return stringPair.str2;
        }

        Variety variety = Util.findVariety(memberType);
        if (variety == Variety.LIST) {
            memberType = Util.findListItemType(memberType);
        }
        String xsdType = Util.findXSDSimpleTypeString(memberType, config);

        String cppType = null;
        switch (variety) {
        case LIST:
            cppType = config.getTypeMapping().get(xsdType).getAttrListType();

            // There cannot be a typedef for a template
            if (cppType.contains("<")) {
                cppType = config.getBaseClassNamespace() + "::" + cppType;
            }
            break;

        case ATOMIC:
            if (Util.hasFacetEnum(memberType)) {
                cppType = cppEnumOrUnionNameCreator.createEnumTypeName(memberType, getElementStack());
                enumsToBeHandled.add(new EnumNameTypePair(cppType, memberType));
            } else {
                cppType = config.getTypeMapping().get(xsdType).getUnionAtomicType();
            }
            break;

        case UNION:
            cppType = cppEnumOrUnionNameCreator.createUnionTypeName(memberType, getElementStack());
            unionsToBeHandled.add(new EnumNameTypePair(cppType, memberType));
            break;

        default:
            cppType = config.getTypeMapping().get(xsdType).getAttrAtomicType();
        }

        map.put(memberType, new StringPair(xsdType, cppType));

        return cppType;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.IGenerationDataProvider#findCorrectCppTypeForAttribute(com.sun.org.apache.xerces.internal.xs.XSTypeDefinition)
     */
    public String findCorrectCppTypeForAttribute(XSTypeDefinition type) {
        XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(type);
        Variety variety = Util.findVariety(simpleType);
        if (variety == Variety.LIST) {
            simpleType = Util.findListItemType(simpleType);
        }
        String xsdType = Util.findXSDSimpleTypeString(simpleType, config);

        String cppType = null;
        switch (variety) {
        case LIST:
            if (Util.findVariety(simpleType) == Variety.UNION) {
                cppType = config.getTemplateUnionAttributeListType();
                cppType = TemplateEngine.fillInUnionTemplate(cppType, simpleType, this);
            } else {
                cppType = config.getTypeMapping().get(xsdType).getAttrListType();
            }

            // There cannot be a typedef for a template
            if (cppType.contains("<")) {
                cppType = config.getBaseClassNamespace() + "::" + cppType;
            }
            break;

        case ATOMIC:
            if (Util.hasFacetEnum(simpleType)) {
                cppType = cppEnumOrUnionNameCreator.createEnumTypeName(simpleType, getElementStack());
                enumsToBeHandled.add(new EnumNameTypePair(cppType, simpleType));
            } else {
                cppType = config.getTypeMapping().get(xsdType).getAttrAtomicType();
            }
            break;

        case UNION:
            cppType = cppEnumOrUnionNameCreator.createUnionTypeName(simpleType, getElementStack());
            unionsToBeHandled.add(new EnumNameTypePair(cppType, simpleType));
            break;

        default:
            cppType = config.getTypeMapping().get(xsdType).getAttrAtomicType();
        }

        return cppType;
    }

    /**
     * Starts code generation.
     */
    public boolean generate() {
        boolean success = true;
        try {
            // setup lib
            // get DOM Implementation using DOM Registry
            System.setProperty(DOMImplementationRegistry.PROPERTY,
                    "org.apache.xerces.dom.DOMXSImplementationSourceImpl");
            DOMImplementationRegistry registry = DOMImplementationRegistry.newInstance();
            XSImplementation impl = (XSImplementation) registry.getDOMImplementation("XS-Loader");
            XSLoader schemaLoader = impl.createXSLoader(null);
            DOMConfiguration domConfig = schemaLoader.getConfig();

            // create Error Handler
            DOMErrorHandler errorHandler = new Generator(config);
            domConfig.setParameter("error-handler", errorHandler);
            domConfig.setParameter("validate", Boolean.TRUE);

            // parse document
            String input = config.getInputFile();
            if (input == null || input.length() == 0) {
                System.err.println("No input file!");
                return false;
            }
            System.out.println("Parsing " + input + "...");
            XSModel model = schemaLoader.loadURI(input);
            setModel(model);

            // check if root element exists
            XSElementDeclaration rootElement = findRootElement(model, config.getRootElementName());
            if (rootElement == null) {
                System.err.println("Root Element not found!");
                return false;
            }

            // collect element usage data
            System.out.println("Collecting element usage...");
            ElementUsageCollector euc = new ElementUsageCollector(config);
            // euc.startWithRootElement(model, config.getRootElementName());
            euc.start(model);
            completeElementUsage = euc.getCompleteElementUsage();

            // create type IDS
            System.out.println("Creating XSD type IDs...");
            typeIdMapping = createTypeIdMapping(completeElementUsage);

            // resolve substitution groups
            System.out.println("Resolving substitution groups...");
            SubstitutionGroupResolver subsGrpResolver = new SubstitutionGroupResolver(config);
            subsGrpResolver.startWithRootElement(model, config.getRootElementName());
            substitutionGroups = subsGrpResolver.getSubstitutionGroups();

            // create element names
            System.out.println("Creating C++ element names...");
            CppElementNameCreator nameCreator = new CppElementNameCreator(config, completeElementUsage,
                    substitutionGroups);
            nameCreator.startWithRootElement(model, config.getRootElementName());
            elementNameMapping = nameCreator.getElementNameMapping();

            // create validation names
            System.out.println("Creating C++ validation data struct and function names...");
            CppValidationDataStructNameCreator dataStructNameCreator = new CppValidationDataStructNameCreator(config,
                    elementNameMapping);
            dataStructNameCreator.startWithRootElement(model, config.getRootElementName());
            xsType2validationDataStructName = dataStructNameCreator.getXsType2validationDataStructName();
            xsSimpleType2validationFunctionName = dataStructNameCreator.getXsSimpleType2validationFunctionName();

            // create constant names
            System.out.println("Creating C++ element and attribute constants...");
            CppConstantsCreator constantsCreator = new CppConstantsCreator(config, this);
            constantsCreator.startWithRootElement(model, config.getRootElementName());

            // //////////////////////////////////////////////////////////////////
            // for debugging
            // //////////////////////////////////////////////////////////////////
            // ElementUsageDumper dumper = new ElementUsageDumper();
            // System.out.println("Dumping element usage...");
            // dumper.dumpElementUsage(completeElementUsage);
            // System.out.println("Dumping multiple elements per parent...");
            // dumper.dumpMultipleElementsPerParent(euc.
            // getMultipleElementsPerParent());
            //
            // NestedModelGroupChecker modelGroupChecker = new
            // NestedModelGroupChecker();
            // modelGroupChecker.start(model);
            // if (true) {
            // throw new
            // RuntimeException("Nested Model Group Checking completed");
            // }
            // //////////////////////////////////////////////////////////////////

            // create enum name creator
            if (config.isTypeNameMappingGenerationTurnedOn()) {
                enumTypeMappingFile = new PrintStream(config.getEnumTypeNameMappingFile());
            }
            cppEnumOrUnionNameCreator = new CppEnumNameCreator(config, enumTypeMappingFile, printedEnums, printedUnions);

            // create printers
            printers = CodePrinterFactory.createCodePrinters(this);

            // setup output files
            nameMapFile = new PrintStream(config.getOutputNameMapFileName());
            printNameMapFileBeginning();
            privateImplHeaderFile = new PrintStream(config.getOutputHeaderFileNamePrivate());
            printPrivateHeaderFileBeginning(); // nameMapFile must be setup here
            privateImplSourceFile = new PrintStream(config.getOutputSourceFileNamePrivate());
            printPrivateSourceFileBeginning(constantsCreator);
            publicImplHeaderFile = new PrintStream(config.getOutputHeaderFileNamePublic());
            printPublicHeaderFileBeginning();
            attrHeaderFile = new PrintStream(config.getOutputAttributesFileName());
            printAttributesHeaderFileBeginning(constantsCreator);
            functionMapFile = new PrintStream(config.getOutputFunctionMapFileName());
            printFunctionMapFileBeginning();
            enumHeaderFile = new PrintStream(config.getOutputEnumHeaderFileName());
            printEnumsHeaderFileBeginning();
            enumSourceFile = new PrintStream(config.getOutputEnumSourceFileName());
            printEnumsSourceFileBeginning();
            valiHeaderFile = new PrintStream(config.getOutputValidationDataHeaderFileName());
            printValidationDataHeaderFileBeginning();
            valiSourceFile = new PrintStream(config.getOutputValidationSourceFileName());
            printValidationSourceFileBeginning();
            findElementHashFile = new PrintStream(config.getOutputFindElementHashFileName());
            printFindElementHashFileBeginning();
            for (ICodePrinter printer : printers) {
                printer.setupOutputFiles();
            }

            // generate special function maps
            generateSpecialFunctionMaps(nameCreator);

            // start
            System.out.println("Starting code generation...");
            // start(model);
            // XSElementDeclaration rootElement = findRootElement(model, );
            // handleElement(rootElement);
            // start(model);
            startWithRootElement(model, config.getRootElementName());

        } catch (Throwable e) {
            System.err.println("EXCEPTION OCCURED, ABORTING !!!");
            e.printStackTrace();
            System.err.println();
            System.err.println("failed");
            success = false;
        } finally {
            if (privateImplHeaderFile != null) {
                printPrivateHeaderFileEnd();
                privateImplHeaderFile.close();
            }
            if (privateImplSourceFile != null) {
                printPrivateSourceFileEnd();
                privateImplSourceFile.close();
            }
            if (publicImplHeaderFile != null) {
                printPublicHeaderFileEnd();
                publicImplHeaderFile.close();
            }
            if (attrHeaderFile != null) {
                printAttributesHeaderFileEnd();
                attrHeaderFile.close();
            }
            if (functionMapFile != null) {
                printFunctionMapFileEnd();
                functionMapFile.close();
            }
            if (nameMapFile != null) {
                printNameMapFileEnd();
                nameMapFile.close();
            }
            if (enumHeaderFile != null) {
                printEnumsHeaderFileEnd();
                enumHeaderFile.close();
            }
            if (enumSourceFile != null) {
                printEnumsSourceFileEnd();
                enumSourceFile.close();
            }
            if (valiHeaderFile != null) {
                printValidationDataHeaderFileEnd();
                valiHeaderFile.close();
            }
            if (findElementHashFile != null) {
                printFindElementHashFileEnd();
                findElementHashFile.close();
            }
            if (valiSourceFile != null) {
                printValidationSourceFileEnd();
                valiSourceFile.close();
            }
            for (ICodePrinter printer : printers) {
                printer.cleanupOutputFiles();
            }
            if (enumTypeMappingFile != null) {
                enumTypeMappingFile.close();
            }
        }
        if (success) {
            System.out.println();
            System.out.println("finished");
        }
        return success;
    }

    /**
     * Generates source and header files with special function maps.
     * 
     * @throws FileNotFoundException
     */
    protected void generateSpecialFunctionMaps(CppElementNameCreator nameCreator) throws FileNotFoundException {
        String headerFilePath = config.getOutputFunctionMapFactoryHeaderFileName();
        PrintStream header = new PrintStream(headerFilePath);
        PrintStream source = new PrintStream(config.getOutputFunctionMapFactorySourceFileName());

        printBeginningOfFunctionMapFactoryFiles(header, source, headerFilePath);

        List<String> functionMapsStartElementNames = config.getSpecialFunctionMapsStartElementNamesOneLevel();
        for (String functionMapsStartElement : functionMapsStartElementNames) {
            System.out.println("generating special function map for " + functionMapsStartElement + " (one level) ...");
            FunctionMapFactoryPrinter printer = new FunctionMapFactoryPrinter(config, elementNameMapping, header,
                    source, functionMapsStartElement, substitutionGroups, completeElementUsage, 1);
            printer.startWithRootElement(getModel(), config.getRootElementName());
        }
        List<String> functionMapsStartElementNamesAllChildren = config
                .getSpecialFunctionMapsStartElementNamesAllLevels();
        for (String functionMapsStartElement : functionMapsStartElementNamesAllChildren) {
            System.out.println("generating special function map for " + functionMapsStartElement
                    + " (all children) ...");
            FunctionMapFactoryPrinter printer = new FunctionMapFactoryPrinter(config, elementNameMapping, header,
                    source, functionMapsStartElement, substitutionGroups, completeElementUsage, -1);
            printer.startWithRootElement(getModel(), config.getRootElementName());
        }

        header.println("private:");
        PrinterUtils.printDisableDefaultMethods(header, config.getClassNameFunctionMapFactory());
        header.println("};");
        PrinterUtils.printNamespaceClose(header, config);
        PrinterUtils.printNamespaceClose(source, config);
        header.println("#endif");
        header.close();
        source.close();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.IGenerationDataProvider#getCompleteElementUsage()
     */
    public Map<String, ElementUsage> getCompleteElementUsage() {
        return completeElementUsage;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.AbstractXSTraverser#getConfig()
     */
    @Override
    public Config getConfig() {
        return config;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.IGenerationDataProvider#getElementNameMapping()
     */
    public Map<XSElementDeclaration, CppElementNameParentTypesPair> getElementNameMapping() {
        return elementNameMapping;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.IGenerationDataProvider#getEnumOrUnionNameCreator()
     */
    public CppEnumNameCreator getEnumOrUnionNameCreator() {
        return cppEnumOrUnionNameCreator;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.IGenerationDataProvider#getUnionMemberTypeMap()
     */
    public Map<XSSimpleTypeDefinition, Map<XSSimpleTypeDefinition, StringPair>> getUnionMemberTypeMap() {
        return unionMemberTypeMap;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.IGenerationDataProvider#getXsSimpleType2validationFunctionName()
     */
    public Map<XSSimpleTypeDefinition, String> getXsSimpleType2validationFunctionName() {
        return xsSimpleType2validationFunctionName;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.IGenerationDataProvider#getXsType2validationDataStructName()
     */
    public Map<XSTypeDefinition, String> getXsType2validationDataStructName() {
        return xsType2validationDataStructName;
    }

    /**
     * Prints out attribute specific things if necessary.
     * 
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @param attributeUses
     *            Attribute uses of element.
     */
    protected void handleAttributes(String cppName, XSElementDeclaration element, List<XSAttributeUse> attributeUses) {
        String structName = Util.createAttributeStructName(cppName, element, config, completeElementUsage);
        if (!printedAttributeStructs.contains(structName)) {
            if (isAttributeStructTypedefRequired(cppName, element, structName)) {
                printAttributesStructTypedef(element, structName);
            } else {
                printAttributesStruct(cppName, element, attributeUses);
                printAttributesDefaultDefinition(cppName, element, attributeUses);
                xsType2attributeStructName.put(element.getTypeDefinition(), structName);
            }
            printedAttributeStructs.add(structName);
        }
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

        String parentElementName = null;
        if (!getElementStack().isEmpty()) {
            parentElementName = getElementStack().peek().getName();
        }
        boolean ignoreElement = false;
        if (parentElementName == null) {
            if (!config.getRootElementName().equals(element.getName())
                    && element.getSubstitutionGroupAffiliation() == null) {
                // parentElementName = findParentElementName(element.getName());
                ignoreElement = true;
            }
        }

        getElementStack().push(element);

        XSTypeDefinition typeDefinition = element.getTypeDefinition();
        XSComplexTypeDefinition complexTypeDefi = Util.getComplexType(typeDefinition);
        List<XSAttributeUse> attributeUses = null;
        boolean hasAttributes = false;
        boolean hasChardata = false;

        if (!ignoreElement) {
            // String cppName = createElementName(element);
            String cppName = elementNameMapping.get(element).cppElementName;
            if (!elementNamesAlreadyHandled.contains(cppName)) {
                System.out.println("handling element: " + cppName);

                // check for namespaces
                if (cppName.equals(config.getRootElementName())) {
                    elementsToIgnoreNSDecls.add(element);
                }
                XSElementDeclaration parentElement = getParentElementFromStack();
                if (parentElement != null) {
                    String parentNS = parentElement.getNamespace();
                    if (parentNS != null && !parentNS.equals(element.getNamespace())) {
                        elementsToParseNSDecls.add(parentElement);
                        elementsToIgnoreNSDecls.add(element);
                    } else if (parentNS == null && element.getNamespace() != null) {
                        elementsToParseNSDecls.add(parentElement);
                        elementsToIgnoreNSDecls.add(element);
                    }
                }

                // complex / simple type stuff
                if (complexTypeDefi != null) {
                    hasChardata = Util.mayHaveCharData(complexTypeDefi, config);
                    attributeUses = Util.collectAttributeUses(element);
                    if (!attributeUses.isEmpty() || Util.isUnknownAttributesMemberRequired(complexTypeDefi)) {
                        hasAttributes = true;
                    }
                    if (hasAttributes) {
                        handleAttributes(cppName, element, attributeUses);
                    }

                    if (Util.mayHaveChildElements(complexTypeDefi, config)) {
                        printComplexValidationDataStruct(cppName, element);
                    }

                } else {
                    // this else branch means we have a simple type.
                    hasChardata = true;
                }

                printBeginConvenienceMethod(cppName, element, hasAttributes);
                printEndConvenienceMethod(cppName, element);

                if (hasChardata) {
                    XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(typeDefinition);
                    if (Util.hasStreamingFacets(simpleType)) {
                        printComplexValidationDataStruct(cppName, element);
                    }
                    if (xsSimpleType2validationFunctionName.get(simpleType) != null) {
                        printSimpleValidationFunctions(simpleType);
                    }
                    if (Util.findVariety(simpleType) == Variety.LIST) {
                        printSimpleValidationFunctions(simpleType.getItemType());
                    }
                    printDataConvenienceMethod(cppName, element);
                }

                // printPrivate();
                printBeginInternalMethod(cppName, element, hasAttributes);
                printDataInternalHeaderDecl(cppName);
                printDataInternalImpl(cppName, element, hasChardata, element.getTypeDefinition());
                printEndInternalMethod(cppName);
                printPreBeginHeaderDecl(cppName);
                printPreBeginImpl(privateImplSourceFile, cppName, element, attributeUses, complexTypeDefi);
                printPreEndHeaderDecl(cppName);
                printPreEndImpl(privateImplSourceFile, cppName, element, hasChardata, element.getTypeDefinition());
                printComplexValidationBlockOpenCompileTimeOnly(privateImplHeaderFile);
                printValidateBeginHeaderDecl(cppName);
                printValidateBeginImpl(valiSourceFile, cppName, element, attributeUses, complexTypeDefi);
                printValidateEndHeaderDecl(cppName);
                printComplexValidationBlockCloseCompileTimeOnly(privateImplHeaderFile);
                printValidateEndImpl(valiSourceFile, cppName, element, hasChardata, element.getTypeDefinition());
                printFreeAttributesHeaderDecl(cppName);
                printFreeAttributesImpl(cppName, element, attributeUses);

                String elementHashID = Util.createElementNameHashIdentifier(cppName);
                Util.printFunctionMapEntry(createFunctionMapMembername(), elementHashID, cppName, functionMapFile,
                        config, false);
                Util.printElementToNamespaceMapEntry(createElementToNamespaceMapMembername(), elementHashID, element,
                        functionMapFile, config);

                handleEnumsAndUnions();

                printEmptyLine(privateImplHeaderFile);
                printEmptyLine(publicImplHeaderFile);
                for (ICodePrinter printer : printers) {
                    printer.printNewLine();
                }

                elementNamesAlreadyHandled.add(cppName);
            } else {
                // System.out.println("ignoring element: " + cppName);

                // quick hack to avoid endless recursion for mathml
                complexTypeDefi = null;
            }
        } else {
            // System.out.println("ignoring element: " + cppName);
        }

        if (complexTypeDefi != null) {
            // handleParticle(complexTypeDefi.getParticle());
            handleTypeDefinition(complexTypeDefi);
        } else if (typeDefinition.getTypeCategory() == XSTypeDefinition.SIMPLE_TYPE) {
        } else {
        }

        getElementStack().pop();
        return true;
    }

    /**
     * Prints enum specific things if necessary.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     * @param simpleType
     *            XSD type representing enum.
     */
    protected void handleEnum(String cppEnumTypeName, XSSimpleTypeDefinition simpleType) {
        if (!printedEnums.contains(cppEnumTypeName)) {
            printedEnums.add(cppEnumTypeName);

            printEnum(cppEnumTypeName, simpleType);
            printEnumMap(cppEnumTypeName, simpleType);
            printEnumFunctions(cppEnumTypeName, simpleType);

            for (ICodePrinter printer : printers) {
                printer.handleEnum(cppEnumTypeName, simpleType);
            }
        }
    }

    /**
     * Handle XSD enums and unions found during code generation. These are
     * special XSD types we have to generate own C++ types for. They have to be
     * handled independent of elements to avoid mixing up of generated methods.
     */
    protected void handleEnumsAndUnions() {
        for (EnumNameTypePair pair : unionsToBeHandled) {
            XSSimpleTypeDefinition unionType = pair.getXsdType();
            List<XSSimpleTypeDefinition> memberTypes = Util.objectListToList(unionType.getMemberTypes());
            for (XSSimpleTypeDefinition memberType : memberTypes) {
                if (Util.hasFacetEnum(memberType)) {
                    String cppType = cppEnumOrUnionNameCreator.createEnumTypeName(memberType, getElementStack());
                    enumsToBeHandled.add(new EnumNameTypePair(cppType, memberType));
                }
            }
        }
        for (EnumNameTypePair pair : enumsToBeHandled) {
            handleEnum(pair.getCppTypeName(), pair.getXsdType());
        }
        enumsToBeHandled.clear();

        for (EnumNameTypePair pair : unionsToBeHandled) {
            handleUnion(pair.getCppTypeName(), pair.getXsdType());
        }
        unionsToBeHandled.clear();
    }

    /**
     * {@inheritDoc}
     * 
     * @see org.w3c.dom.DOMErrorHandler#handleError(org.w3c.dom.DOMError)
     */
    public boolean handleError(DOMError error) {
        short severity = error.getSeverity();
        if (severity == DOMError.SEVERITY_FATAL_ERROR) {
            System.err.println("[xs-fatal-error]: " + error.getMessage());
            Object relatedException = error.getRelatedException();
            if (relatedException instanceof Throwable) {
                Throwable t = (Throwable) relatedException;
                t.printStackTrace();
            }
            return false;
        }

        if (severity == DOMError.SEVERITY_ERROR) {
            System.err.println("[xs-error]: " + error.getMessage());
        }

        if (severity == DOMError.SEVERITY_WARNING) {
            System.err.println("[xs-warning]: " + error.getMessage());
        }
        return true;

    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.AbstractXSTraverser#handleModelGroup(com.sun.org.apache.xerces.internal.xs.XSModelGroup)
     */
    @Override
    public boolean handleModelGroup(XSModelGroup modelGroup) {
        // switch (modelGroup.getCompositor()) {
        // case XSModelGroup.COMPOSITOR_SEQUENCE:
        // break;
        // case XSModelGroup.COMPOSITOR_CHOICE:
        // break;
        // default:
        // break;
        // }
        // XSObjectList particles = modelGroup.getParticles();
        // if (particles != null && particles.getLength() > 0) {
        // // ///////////////
        // // debugging
        // // ///////////////
        // // FileWriter tmpDebugFile;
        // // try {
        // // if (modelGroup.getName() != null) {
        // // tmpDebugFile = new FileWriter("groups.txt", true);
        // // // tmpDebugFile.append("### XSModelGroup with particles !!!"
        // // // + "\n");
        // // tmpDebugFile.append("### XSModelGroup name: " +
        // // modelGroup.getName() + "\n");
        // // // tmpDebugFile.append("### top element name: " +
        // // // getElementStack().peek().getName() + "\n");
        // // tmpDebugFile.append("\n");
        // // tmpDebugFile.close();
        // // }
        // // } catch (IOException e) {
        // // e.printStackTrace();
        // // }
        // }
        // return true;

        return super.handleModelGroup(modelGroup);
    }

    /**
     * Prints union specific things if necessary.
     * 
     * @param cppUnionTypeName
     *            Name of C++ union type.
     * @param simpleType
     *            XSD type representing enum.
     */
    protected void handleUnion(String cppUnionTypeName, XSSimpleTypeDefinition simpleType) {
        if (!printedUnions.contains(cppUnionTypeName)) {
            printedUnions.add(cppUnionTypeName);

            printUnion(cppUnionTypeName, simpleType, enumHeaderFile);
            printUnionFunctions(cppEnumOrUnionNameCreator, simpleType);

            for (ICodePrinter printer : printers) {
                printer.handleUnion(cppUnionTypeName, simpleType);
            }
        }
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.AbstractXSTraverser#handleWildcard(com.sun.org.apache.xerces.internal.xs.XSWildcard)
     */
    @Override
    public boolean handleWildcard(XSWildcard wildcard) {
        elementsWithXsAny.add(getElementStack().peek());
        return true;
    }

    /**
     * Finds out if a typedef should be printed instead of an attribute struct.
     * 
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @param structName
     *            Name of attribute struct to check.
     * @return True if typedef is required. False if struct is required.
     */
    protected boolean isAttributeStructTypedefRequired(String cppName, XSElementDeclaration element, String structName) {
        ElementUsage elementUsage = completeElementUsage.get(element.getName());
        int elementsWithSameType = Util.countElementsWithSameType(elementUsage, element);

        if (elementsWithSameType == 0) {
            return false;
        }
        if (elementsWithSameType == elementUsage.getElements().size()) {
            return false;
        }
        return xsType2attributeStructName.containsKey(element.getTypeDefinition());
    }

    /**
     * Prints implementation of attribute freeing.
     * 
     * @param elemName
     *            C++ element name.
     * @param element
     *            XSD representation of element.
     * @param attrs
     *            Attributes of element to parse.
     */
    protected void printAttributeFreeing(String cppName, XSElementDeclaration element, List<XSAttributeUse> attrs) {
        printAttributeFreeingDataStructCast(cppName, element);

        for (XSAttributeUse attr : attrs) {
            XSSimpleTypeDefinition type = Util.getType(attr);
            Variety variety = Util.findVariety(type);
            if (variety == Variety.LIST) {
                privateImplSourceFile.println(TemplateEngine.fillInTemplate(config.getTemplateFreeAttrList(), cppName,
                        element, attr, null, null, null, this));
            }
        }
        if (Util.isUnknownAttributesMemberRequired(element.getTypeDefinition())) {
            privateImplSourceFile.println(TemplateEngine.fillInTemplate(config.getTemplateFreeUnknownAttributes(),
                    cppName, element, null, null, null, null, this));
        }

        privateImplSourceFile.println(TemplateEngine.fillInTemplate(config.getTemplateFreeAttrStruct(), cppName,
                element, null, null, null, null, this));
    }

    /**
     * Prints casting of attribute struct for attribute freeing.
     * 
     * @param elemName
     *            C++ element name.
     * @param element
     *            XSD representation of element.
     */
    protected void printAttributeFreeingDataStructCast(String cppName, XSElementDeclaration element) {
        String attrStructName = Util.createAttributeStructName(cppName, element, config, completeElementUsage);
        privateImplSourceFile.print(config.getIndentation());
        privateImplSourceFile.print(attrStructName);
        privateImplSourceFile.print("* ");
        privateImplSourceFile.print(config.getTypedAttributeDataVariableName());
        privateImplSourceFile.print(" = static_cast<");
        privateImplSourceFile.print(attrStructName);
        privateImplSourceFile.print("*>(");
        privateImplSourceFile.print(config.getAttributeDataParameterName());
        privateImplSourceFile.println(");");
    }

    /**
     * Prints implementation of attribute parsing.
     * 
     * @param elemName
     *            C++ element name.
     * @param element
     *            XSD representation of element.
     * @param attrs
     *            Attributes of element to parse.
     */
    protected void printAttributeParsing(String elemName, XSElementDeclaration element, List<XSAttributeUse> attrs) {
        privateImplSourceFile.println(TemplateEngine.fillInTemplate(config.getTemplateValidateBeginPreSwitch(),
                elemName, element, null, null, null, null, this));
        privateImplSourceFile.println();

        if (!attrs.isEmpty()) {
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("switch ( hash )");
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("{");
        }

        for (XSAttributeUse attr : attrs) {
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("case "
                    + Util.createAttributeNameHashIdentifier(Util.getAttributeOriginalName(attr, config)) + ":");
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("{");

            XSSimpleTypeDefinition attrType = Util.getType(attr);
            String template = null;
            String simpleTypeValiTmpl = null;
            switch (Util.findVariety(attrType)) {
            case ATOMIC:
                template = config.getTemplateAttributeAtomicConversion();
                if (!Util.hasFacetEnum(attrType)) {
                    if (Util.isNumericType(attrType, config)) {
                        simpleTypeValiTmpl = config.getTemplateSimpleValidationNumericAtomicAttribute();
                    } else {
                        if (xsType2validationDataStructName.get(attrType) != null
                                || xsSimpleType2validationFunctionName.get(attrType) != null) {
                            simpleTypeValiTmpl = config.getTemplateSimpleValidationStringAtomicAttribute();
                        }
                    }
                }
                break;
            case LIST:
                template = config.getTemplateAttributeListConversion();
                XSSimpleTypeDefinition itemType = attrType.getItemType();
                if (Util.isNumericType(itemType, config) && !Util.hasFacetEnum(itemType)) {
                    simpleTypeValiTmpl = config.getTemplateSimpleValidationNumericListAttribute();
                } else {
                    simpleTypeValiTmpl = config.getTemplateSimpleValidationStringListAttribute();
                }
                break;
            case UNION:
                template = config.getTemplateUnionAttributeAtomicConversion();
                break;
            }
            privateImplSourceFile.println(TemplateEngine.fillInTemplate(template, elemName, element, attr, null,
                    attrType, simpleTypeValiTmpl, this));

            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("break;");
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("}");
        }

        if (!attrs.isEmpty()) {
            if (elementsToIgnoreNSDecls.contains(element)) {
                printParseAttrXMLNS(elemName, element);
            }

            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("default:");
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("{");
            String switchDefaultTmpl = null;
            if (elementsToIgnoreNSDecls.contains(element)) {
                switchDefaultTmpl = config.getTemplateParseAttrDefaultXMLNS();
            } else if (Util.isUnknownAttributesMemberRequired(element.getTypeDefinition())) {
                switchDefaultTmpl = config.getTemplateValidateBeginSwitchDefaultUnknownAttributes();
            } else {
                switchDefaultTmpl = config.getTemplateValidateBeginSwitchDefault();
            }

            privateImplSourceFile.println(TemplateEngine.fillInTemplate(switchDefaultTmpl, elemName, element, null,
                    null, null, null, this));
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("}");

            // close switch
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("}");
        } else {
            // unknown attribute handling for elements which have unknown
            // attributes only
            privateImplSourceFile.println(TemplateEngine.fillInTemplate(config
                    .getTemplateValidateBeginSwitchDefaultUnknownAttributes(), elemName, element, null, null, null,
                    null, this));
        }

        privateImplSourceFile.println(TemplateEngine.fillInTemplate(config.getTemplateValidateBeginPostSwitch(),
                elemName, element, null, null, null, null, this));
        privateImplSourceFile.println();

    }

    /**
     * Prints definition of attribute data static default member.
     * 
     * @param cppElementName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @param attributeUses
     *            Attributes to print default member for.
     */
    protected void printAttributesDefaultDefinition(String cppElementName, XSElementDeclaration element,
            List<XSAttributeUse> attributeUses) {
        privateImplSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        String attrStructName = Util.createAttributeStructName(cppElementName, element, config, completeElementUsage);
        privateImplSourceFile.print("const " + attrStructName + " " + attrStructName + "::"
                + config.getAttributeStructDefaultMemberName());

        privateImplSourceFile.print(" = {");

        // init attrs present member
        boolean attrsPresentMemberRequired = false;
        for (XSAttributeUse attrUse : attributeUses) {
            if (Util.presentMaskRequired(attrUse, getConfig())) {
                attrsPresentMemberRequired = true;
                break;
            }
        }
        if (attrsPresentMemberRequired) {
            privateImplSourceFile.print("0, ");
        }

        for (int i = 0; i < attributeUses.size(); i++) {
            XSAttributeUse attributeUse = attributeUses.get(i);
            XSSimpleTypeDefinition simpleTypeDefinition = Util.getType(attributeUse);
            Variety variety = Util.findVariety(simpleTypeDefinition);
            if (variety == Variety.ATOMIC) {
                if (Util.hasDefaultValue(attributeUse)) {
                    if (Util.hasFacetEnum(simpleTypeDefinition)) {
                        String constraintValueString = attributeUse.getConstraintValue();
                        List<String> enumValues = Util.stringListToList(simpleTypeDefinition.getLexicalEnumeration());
                        int j = 0;
                        while (j < enumValues.size()) {
                            if (enumValues.get(j).equals(constraintValueString)) {
                                break;
                            }
                            j++;
                        }
                        privateImplSourceFile.print(Util.createEnumValueName(cppEnumOrUnionNameCreator
                                .createEnumTypeName(simpleTypeDefinition, getElementStack()), enumValues, j,
                                simpleTypeDefinition, config));
                    } else {
                        String cppAtomicType = Util.findXSDSimpleTypeString(simpleTypeDefinition, getConfig());
                        String initialize = getConfig().getTypeMapping().get(cppAtomicType).getInitialize();
                        if (initialize != null) {
                            privateImplSourceFile.print(TemplateEngine.fillInInitializationTemplate(initialize,
                                    attributeUse.getConstraintValue()));
                        } else {
                            boolean cppTypeIsString = Util.isStringType(Util.getType(attributeUse), config);
                            if (cppTypeIsString) {
                                privateImplSourceFile.print("(");
                                privateImplSourceFile.print(getConfig().getTypeMapping().get("string")
                                        .getAttrAtomicType());
                                privateImplSourceFile.print(")\"");
                            }
                            privateImplSourceFile.print(attributeUse.getConstraintValue());
                            if (cppTypeIsString)
                                privateImplSourceFile.print("\"");
                        }
                    }

                } else {
                    if (!attributeUse.getRequired()) {
                        System.err.println("optional attribute without default value: " + cppElementName + ", "
                                + Util.getAttributeName(attributeUse, config));
                    }
                    if (Util.hasFacetEnum(simpleTypeDefinition)) {
                        privateImplSourceFile.print(Util.createEnumNotPresentName(cppEnumOrUnionNameCreator
                                .createEnumTypeName(simpleTypeDefinition, getElementStack()), config));
                    } else {
                        privateImplSourceFile.print("0");
                    }
                }
            } else {
                // @see TemplateEngine#attributesInitObjects()
                switch (variety) {
                case LIST:
                    privateImplSourceFile.print(findCorrectCppTypeForAttribute(simpleTypeDefinition) + "()");
                    break;

                case UNION:
                    String unionType = cppEnumOrUnionNameCreator.createUnionTypeName(simpleTypeDefinition,
                            getElementStack());
                    privateImplSourceFile.print(unionType + "()");
                    break;
                default:
                    privateImplSourceFile.print("0");
                    break;
                }
            }
            if (i != attributeUses.size() - 1) {
                privateImplSourceFile.print(", ");
            }
        }

        // unknown attributes
        if (Util.isUnknownAttributesMemberRequired(element.getTypeDefinition())) {
            if (!attributeUses.isEmpty()) {
                privateImplSourceFile.print(", ");
            }
            privateImplSourceFile.print(config.getUnknownAttributesMemberInit());
        }

        privateImplSourceFile.println("};");
        privateImplSourceFile.println();

    }

    /**
     * Prints first content of attributes header file:
     */
    protected void printAttributesHeaderFileBeginning(CppConstantsCreator constantsCreator) {
        attrHeaderFile.println(config.getOutFileHeader());
        attrHeaderFile.println();
        attrHeaderFile.println();
        PrinterUtils.printIncludeProtection(attrHeaderFile, PrinterUtils.createIncludeProtectionMacro(config
                .getNamespace(), config.getClassNamePublic() + config.getOutputAttributesFileSuffix()));
        attrHeaderFile.println();
        attrHeaderFile.println();

        List<String> includes = new ArrayList<String>();
        String enumHeaderPath = config.getOutputEnumHeaderFileName();
        includes.add(enumHeaderPath.substring(enumHeaderPath.lastIndexOf('/') + 1));
        PrinterUtils.printIncludes(attrHeaderFile, includes);
        attrHeaderFile.println();
        attrHeaderFile.println();

        PrinterUtils.printNamespaceOpen(attrHeaderFile, config.getNamespace());
        attrHeaderFile.println();
        attrHeaderFile.println();

        printNamespaceConstantDecls(attrHeaderFile);
        attrHeaderFile.println();
        attrHeaderFile.println();

        printStringConstantsDecls(attrHeaderFile, constantsCreator);
        attrHeaderFile.println();
        attrHeaderFile.println();
        printHashConstants(attrHeaderFile, constantsCreator);
        attrHeaderFile.println();
        attrHeaderFile.println();
    }

    /**
     * Prints ending of attributes C++ header file.
     */
    protected void printAttributesHeaderFileEnd() {
        attrHeaderFile.println();
        attrHeaderFile.println();
        PrinterUtils.printNamespaceClose(attrHeaderFile, config);

        attrHeaderFile.println("#endif");
    }

    /**
     * Prints Attribute data struct.
     * 
     * @param cppName
     *            C++ element name.
     * @param element
     *            XSD representation of element.
     * @param attributeUses
     *            Attribute uses of element's type.
     */
    protected void printAttributesStruct(String cppName, XSElementDeclaration element,
            List<XSAttributeUse> attributeUses) {
        String structName = Util.createAttributeStructName(cppName, element, config, completeElementUsage);

        // struct declaration
        attrHeaderFile.println("struct " + structName);
        attrHeaderFile.println("{");

        // static default member
        attrHeaderFile.print(config.getIndentation());
        attrHeaderFile.println("static const " + structName + " " + config.getAttributeStructDefaultMemberName() + ";");
        attrHeaderFile.println();

        // attribute present masks
        boolean attrsPresentMemberRequired = false;
        long maskValue = 1;
        for (XSAttributeUse attrUse : attributeUses) {
            if (Util.presentMaskRequired(attrUse, getConfig())) {
                attrsPresentMemberRequired = true;
                attrHeaderFile.print(config.getIndentation());
                attrHeaderFile.print(config.getAttributePresentMaskType() + " ");
                attrHeaderFile.print(Util.createAttributePresentMaskName(attrUse, getConfig()));
                attrHeaderFile.print(" = ");
                attrHeaderFile.print("0x" + Long.toHexString(maskValue));
                maskValue = maskValue << 1;
                attrHeaderFile.println(";");
            }
        }
        if (attrsPresentMemberRequired) {
            attrHeaderFile.println();
            attrHeaderFile.print(config.getIndentation());
            attrHeaderFile.print(config.getAttributesPresentMemberType() + " ");
            attrHeaderFile.println(config.getAttributesPresentMemberName() + ";");
            attrHeaderFile.println();
        }

        // attributes
        for (XSAttributeUse attrUse : attributeUses) {
            attrHeaderFile.print(config.getIndentation());
            XSSimpleTypeDefinition typeDefinition = Util.getType(attrUse);

            if (xsSimpleType2validationFunctionName.get(typeDefinition) != null) {
                printSimpleValidationFunctions(typeDefinition);
            }
            if (Util.findVariety(typeDefinition) == Variety.LIST) {
                printSimpleValidationFunctions(typeDefinition.getItemType());
            }

            String cppMemberTypeName = findCorrectCppTypeForAttribute(typeDefinition);
            attrHeaderFile.print(cppMemberTypeName);
            attrHeaderFile.print(" ");
            String attrName = Util.getAttributeName(attrUse, config);
            attrHeaderFile.print(attrName);
            attrHeaderFile.println(";");
        }

        // unknown attributes
        if (Util.isUnknownAttributesMemberRequired(element.getTypeDefinition())) {
            attrHeaderFile.println();
            attrHeaderFile.print(config.getIndentation());
            attrHeaderFile.print(config.getUnknownAttributesMemberType());
            attrHeaderFile.print(" ");
            attrHeaderFile.print(config.getUnknownAttributesMemberName());
            attrHeaderFile.println(";");
        }

        attrHeaderFile.println("};");
        printEmptyLine(attrHeaderFile);
    }

    /**
     * Prints a typedef for an attributes struct. Used for elements with same
     * name and different parents which have partly same types.
     * 
     * @param element
     *            XSD representation of element.
     * @param structName
     *            Name of typedef.
     */
    protected void printAttributesStructTypedef(XSElementDeclaration element, String structName) {
        attrHeaderFile.print("typedef ");

        attrHeaderFile.print(xsType2attributeStructName.get(element.getTypeDefinition()));

        attrHeaderFile.print(" " + structName);
        attrHeaderFile.println(";");
        printEmptyLine(attrHeaderFile);
    }

    /**
     * Prints convenience begin[element] method. It's parameter are a const
     * reference to attribute data if xsd type has attributes. If not generated
     * method does not have parameters.
     * 
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @param attributesRequired
     *            Indicates if attribute data parameter shall be generated.
     */
    protected void printBeginConvenienceMethod(String cppName, XSElementDeclaration element, boolean attributesRequired) {
        String methodName = Util.createBeginConvenienceMethodName(cppName, config);
        String paraList = createBeginConvenienceMethodParameterList(cppName, element, attributesRequired);
        printBeginConvenienceMethodToHeader(methodName, paraList);
        for (ICodePrinter printer : printers) {
            printer.printBeginMethodToHeader(methodName, paraList, cppName, element, attributesRequired);
            printer.printBeginMethodToSource(methodName, paraList, cppName, element, attributesRequired);
        }
    }

    /**
     * Prints convenience begin[element] method to header file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     */
    protected void printBeginConvenienceMethodToHeader(String methodName, String parameterList) {
        PrinterUtils.printBeginConvenienceMethodDeclTypeModifiers(publicImplHeaderFile);
        publicImplHeaderFile.print(" ");
        PrinterUtils.printBeginConvenienceMethodReturnType(publicImplHeaderFile);
        publicImplHeaderFile.print(" ");
        publicImplHeaderFile.print(methodName);
        publicImplHeaderFile.print(parameterList);
        PrinterUtils.printBeginConvenienceMethodDefaultImpl(publicImplHeaderFile, false, config);
        publicImplHeaderFile.println();
    }

    /**
     * Prints "normal" begin[element] method. A void* is passed and casted to
     * attribute data if xsd type may have attributes. Convenience method is
     * called in any case.
     * 
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @param cast
     *            Indicates if attribute data cast shall be generated.
     */
    protected void printBeginInternalMethod(String cppName, XSElementDeclaration element, boolean cast) {
        privateImplHeaderFile.print("bool ");
        String methodName = Util.createBeginConvenienceMethodName(cppName, config);
        privateImplHeaderFile.print(Util.createBeginInternalMethodName(cppName, config));
        privateImplHeaderFile.print("( void* ");
        privateImplHeaderFile.print(config.getAttributeDataParameterName());
        privateImplHeaderFile.print(" ){");
        privateImplHeaderFile.print("return " + config.getPublicImplMember() + "->");
        if (cast) {
            privateImplHeaderFile.print(methodName + "(*static_cast<"
                    + Util.createAttributeStructName(cppName, element, config, completeElementUsage) + "*>("
                    + config.getAttributeDataParameterName() + "));");
        } else {
            privateImplHeaderFile.print(methodName + "();");
        }
        privateImplHeaderFile.print("}");
        privateImplHeaderFile.println();
    }

    /**
     * Prints beginning of FunctionMapFactory header and source file.
     * 
     * @param header
     * @param source
     */
    protected void printBeginningOfFunctionMapFactoryFiles(PrintStream header, PrintStream source, String headerFilePath) {
        header.println(config.getOutFileHeader());
        header.println();
        String factoryClassName = config.getClassNameFunctionMapFactory();
        PrinterUtils.printIncludeProtection(header, PrinterUtils.createIncludeProtectionMacro(config.getNamespace(),
                factoryClassName));
        header.println();

        List<String> headerIncludes = new ArrayList<String>();
        String privateClassOutfileHeader = config.getOutputHeaderFileNamePrivate();
        headerIncludes.add(privateClassOutfileHeader.substring(privateClassOutfileHeader.lastIndexOf('/') + 1));
        PrinterUtils.printIncludes(header, headerIncludes);
        header.println();
        source.println(config.getOutFileHeader());
        source.println();

        String precompiledHeader = config.getIncludePrecompiledHeader();
        List<String> sourceIncludes = new ArrayList<String>();
        sourceIncludes.add(precompiledHeader);
        sourceIncludes.add(headerFilePath.substring(headerFilePath.lastIndexOf('/') + 1));
        PrinterUtils.printIncludes(source, sourceIncludes);
        source.println();

        PrinterUtils.printNamespaceOpen(header, config.getNamespace());
        header.println();
        PrinterUtils.printNamespaceOpen(source, config.getNamespace());
        source.println();

        header.println("class " + factoryClassName + " {");
        header.println("public:");
        header.println();
    }

    /**
     * Prints closing of validation block to given stream.
     * 
     * @param stream
     *            Stream to print closing of validation block to.
     */
    protected void printComplexValidationBlockClose(PrintStream stream) {
        stream.println(TemplateEngine.fillInTemplate(config.getTemplateComplexValidationBlockClose(), null, null, null,
                null, null, null, this));
    }

    /**
     * Prints closing of validation block at compile time onl to given stream.
     * 
     * @param stream
     *            Stream to print closing of validation block to.
     */
    protected void printComplexValidationBlockCloseCompileTimeOnly(PrintStream stream) {
        stream.println(TemplateEngine.fillInTemplate(config.getTemplateComplexValidationBlockCloseCompileTimeOnly(),
                null, null, null, null, null, null, this));
    }

    /**
     * Prints opening of validation block to given stream.
     * 
     * @param stream
     *            Stream to print opening of validation block to.
     */
    protected void printComplexValidationBlockOpen(PrintStream stream) {
        stream.println(TemplateEngine.fillInTemplate(config.getTemplateComplexValidationBlockOpen(), null, null, null,
                null, null, null, this));
    }

    /**
     * Prints opening of validation block at compile time only to given stream.
     * 
     * @param stream
     *            Stream to print opening of validation block to.
     */
    protected void printComplexValidationBlockOpenCompileTimeOnly(PrintStream stream) {
        stream.println(TemplateEngine.fillInTemplate(config.getTemplateComplexValidationBlockOpenCompileTimeOnly(),
                null, null, null, null, null, null, this));
    }

    /**
     * Prints validation data struct for complex type validation.
     * 
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD element using type.
     */
    protected void printComplexValidationDataStruct(String cppName, XSElementDeclaration element) {
        String structName = xsType2validationDataStructName.get(element.getTypeDefinition());
        if (structName == null) {
            return;
        }
        if (!printedValidationDataStructs.contains(structName)) {
            printedValidationDataStructs.add(structName);
            valiHeaderFile.print("struct ");
            valiHeaderFile.println(structName);
            valiHeaderFile.println("{");

            if (element.getTypeDefinition() instanceof XSComplexTypeDefinition) {
                XSComplexTypeDefinition complexType = (XSComplexTypeDefinition) element.getTypeDefinition();
                if (stateMachineMap.get(complexType) != null) {
                    printComplexValidationDataStructMember(valiHeaderFile, config
                            .getComplexValidationDataStateMachineStructMemberType(), config
                            .getComplexValidationStateMachineStructMember());
                }

                Set<String> printedMembers = new HashSet<String>();
                printComplexValidationDataStructMembers(valiHeaderFile, complexType, printedMembers);
            }
            if (Util.mayHaveCharData(element.getTypeDefinition(), config)) {
                printComplexValidationDataStructMember(valiHeaderFile, config
                        .getComplexValidationDataStateMachineStructMemberType(), config
                        .getSimpleValidationStreamCountStructMember());
            }

            valiHeaderFile.println("};");
            valiHeaderFile.println();
        }
    }

    /**
     * Prints creation of validation data struct.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppElementName
     *            C++ name of element.
     * @param cppValidationDataStructType
     *            C++ type name of validation data struct.
     * @param complexType
     *            XSD type.
     * @param element
     *            XSD element.
     */
    protected void printComplexValidationDataStructCreation(PrintStream stream, String cppElementName,
            String cppValidationDataStructType, XSComplexTypeDefinition complexType, XSElementDeclaration element) {
        stream.print(TemplateEngine.fillInTemplate(TemplateEngine.fillInComplexValidationTemplate(config
                .getTemplateComplexValidationCreateValidationData(), cppElementName, cppValidationDataStructType,
                complexType, element, null, this), null, null, null, null, null, null, this));
    }

    /**
     * Prints deletion of validation data struct.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppElementName
     *            C++ name of element.
     * @param cppValidationDataStructType
     *            C++ type name of validation data struct.
     * @param complexType
     *            XSD type.
     * @param element
     *            XSD element.
     */
    protected void printComplexValidationDataStructDeletion(PrintStream stream, String cppElementName,
            String cppValidationDataStructType, XSComplexTypeDefinition complexType, XSElementDeclaration element) {
        stream.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInComplexValidationTemplate(config
                .getTemplateComplexValidationDeleteValidationData(), cppElementName, cppValidationDataStructType,
                complexType, element, null, this), null, null, null, null, null, null, this));
    }

    /**
     * Prints a single member of validation data struct to given stream.
     * 
     * @param stream
     *            Stream to print to.
     * @param type
     *            Type of member.
     * @param name
     *            Name of member.
     */
    protected void printComplexValidationDataStructMember(PrintStream stream, String type, String name) {
        stream.print(config.getIndentation());
        stream.print(type);
        stream.print(" " + name);
        stream.print(";");
        stream.println();
    }

    /**
     * Prints members of C++ validation data structs for non-StateMachine
     * elements. Takes care of XSD base types.
     */
    protected void printComplexValidationDataStructMembers(PrintStream stream, XSComplexTypeDefinition complexType,
            Set<String> printedMembers) {
        if (complexType.getParticle() != null) {
            XSTerm term = complexType.getParticle().getTerm();
            if (term instanceof XSModelGroup) {
                XSModelGroup modelGroup = (XSModelGroup) term;
                printComplexValidationDataStructMembers(stream, modelGroup, printedMembers);
            }
        }
        if (complexType.getBaseType() instanceof XSComplexTypeDefinition) {
            XSComplexTypeDefinition baseType = (XSComplexTypeDefinition) complexType.getBaseType();
            if (!Constants.XSD_ANYTYPE_NAME.equals(baseType.getName())
                    && !config.getXSNamespace().equals(baseType.getNamespace())) {
                printComplexValidationDataStructMembers(stream, baseType, printedMembers);
            }
        }
    }

    /**
     * Prints members of given model group as validation data struct members.
     * 
     * @param stream
     *            Stream to print to.
     * @param modelGroup
     *            Model group to print.
     * @param printedMembers
     *            Struct members which have already been printed.
     */
    protected void printComplexValidationDataStructMembers(PrintStream stream, XSModelGroup modelGroup,
            Set<String> printedMembers) {
        XSObjectList particles = modelGroup.getParticles();
        for (int i = 0; i < particles.getLength(); i++) {
            XSTerm childTerm = ((XSParticle) (particles.item(i))).getTerm();
            if (childTerm instanceof XSElementDeclaration || childTerm instanceof XSWildcard) {
                String structMemberName = Util.createComplexValidationDataStructMemberName(childTerm, config);
                if (!printedMembers.contains(structMemberName)) {
                    printComplexValidationDataStructMember(valiHeaderFile, config.getValidationDataStructMemberType(),
                            structMemberName);
                    printedMembers.add(structMemberName);
                }
            } else if (childTerm instanceof XSModelGroup) {
                printComplexValidationDataStructMembers(stream, (XSModelGroup) childTerm, printedMembers);
            }
        }
    }

    /**
     * Prints specialized validation code for one single parent.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppName
     *            C++ element name of child.
     * @param element
     *            Child element.
     * @param parentType
     *            Parent type.
     */
    protected void printComplexValidationForSingleParent(PrintStream stream, String cppName,
            XSElementDeclaration element, XSComplexTypeDefinition parentType) {

        String tmpl = null;
        StateMachineRootNode sm = stateMachineMap.get(parentType);

        boolean isChildOfUnreferencedTopLevelElement = false;
        XSElementDeclaration parentElement = null;

        ElementUsage elementUsage = completeElementUsage.get(element.getName());
        List<XSElementDeclaration> parents = elementUsage.collectParents();
        for (XSElementDeclaration parent : parents) {
            if (parent.getTypeDefinition() == parentType) {
                parentElement = parent;
                break;
            }
        }

        if (parentElement != null && !parentElement.getName().equals(config.getRootElementName())) {
            if (parentElement.getSubstitutionGroupAffiliation() == null) {
                ElementUsage parentUsage = completeElementUsage.get(parentElement.getName());
                if (parentUsage.collectParents().isEmpty()) {
                    isChildOfUnreferencedTopLevelElement = true;
                }
            }
        }

        if (isChildOfUnreferencedTopLevelElement) {
            tmpl = "#ind##ind#// no validation because is child of unreferenced top level element#nl#";
            if (parentElement != null && parentElement.getName() != null) {
                tmpl += "#ind##ind#// parent element: " + parentElement.getName() + "#nl#";
            }
        } else {
            if (sm == null) {
                tmpl = config.getTemplateComplexValidationChildValidateBegin();
            } else {
                tmpl = config.getTemplateComplexValidationChildValidateBeginNestedModelGroup();
            }
        }

        stream.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInComplexValidationTemplate(tmpl, cppName,
                xsType2validationDataStructName.get(parentType), parentType, element, sm, this), cppName, element,
                null, null, null, null, this));
    }

    /**
     * Prints c-tor and d-tor for C++ source file.
     */
    protected void printCtorDtorImpl(PrintStream stream, String className, String baseClass, boolean initMaps,
            boolean errHandler) {
        // c-tor
        stream.println(config.getOutputSourceFileMethodDelimiter());
        stream.print(className + "::" + className + "(");
        if (errHandler) {
            stream.print(" " + config.getNamespace() + "::" + config.getClassNamePublic() + "* impl, "
                    + config.getBaseClassNamespace() + "::");
            stream.println("IErrorHandler* errorHandler ");
        }
        stream.print(")");
        if (errHandler) {
            stream.print(config.getIndentation());
            stream.println(": " + config.getBaseClassNamespace() + "::" + baseClass + "(impl, errorHandler)");
        } else {
            stream.println();
        }
        stream.println("{");

        if (initMaps) {
            stream.print(config.getIndentation());
            stream.println(PrinterUtils.createInitFunctionMapMethodName() + "();");
            stream.print(config.getIndentation());
            stream.println(PrinterUtils.createInitNameMapMethodName() + "();");
        }
        stream.println("}");
        stream.println();

        // d-tor
        stream.println(config.getOutputSourceFileMethodDelimiter());
        stream.println(className + "::~" + className + "()");
        stream.println("{");
        stream.println("}");
        stream.println();
    }

    /**
     * Prints convenience data method. It can be used by implementors to get
     * char data of element.
     * 
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD Element.
     */
    protected void printDataConvenienceMethod(String cppName, XSElementDeclaration element) {
        String methodName = createDataConvenienceMethodName(cppName);
        String paraList = createDataConvenienceParameterList(element.getTypeDefinition());
        printDataConvenienceMethodToHeader(methodName, paraList);
        for (ICodePrinter printer : printers) {
            printer.printDataMethodToHeader(methodName, paraList, cppName, element);
            printer.printDataMethodToSource(methodName, paraList, cppName, element);
        }
    }

    /**
     * Prints convenience data method to header file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     */
    protected void printDataConvenienceMethodToHeader(String methodName, String parameterList) {
        PrinterUtils.printDataConvenienceMethodDeclTypeModifiers(publicImplHeaderFile);
        publicImplHeaderFile.print(" ");
        PrinterUtils.printDataConvenienceMethodReturnType(publicImplHeaderFile);
        publicImplHeaderFile.print(" ");
        publicImplHeaderFile.print(methodName);
        publicImplHeaderFile.print(parameterList);
        PrinterUtils.printDataConvenienceMethodDefaultImpl(publicImplHeaderFile, false, config);
        publicImplHeaderFile.println();
    }

    /**
     * Prints declaration of internal data method to C++ header.
     * 
     * @param cppName
     *            C++ name of element to validate.
     */
    protected void printDataInternalHeaderDecl(String cppName) {
        printDataInternalReturnType(privateImplHeaderFile);
        privateImplHeaderFile.print(" ");
        privateImplHeaderFile.print(Util.createDataInternalMethodName(cppName));
        printDataInternalParameterList(privateImplHeaderFile);
        privateImplHeaderFile.println(";");
    }

    /**
     * Prints implementation of internal data method to C++ source file.
     * 
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @param hasChardata
     *            Indicates if element has char data.
     * @param typeDefinition
     *            Type of element.
     */
    protected void printDataInternalImpl(String cppName, XSElementDeclaration element, boolean hasChardata,
            XSTypeDefinition typeDefinition) {
        privateImplSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        printDataInternalReturnType(privateImplSourceFile);
        privateImplSourceFile.print(" ");
        privateImplSourceFile.print(config.getClassNamePrivate());
        privateImplSourceFile.print("::");
        privateImplSourceFile.print(Util.createDataInternalMethodName(cppName));
        printDataInternalParameterList(privateImplSourceFile);
        privateImplSourceFile.println();
        privateImplSourceFile.println("{");

        if (hasChardata) {
            XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(typeDefinition);
            String template = null;
            String simpleTypeValiTmpl = null;
            switch (Util.findVariety(simpleType)) {
            case ATOMIC:
                if (Util.hasFacetEnum(simpleType) && Util.isStringType(simpleType, config)) {
                    template = Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_DATA_METHOD_IMPL;
                    template = TemplateEngine.fillInTypeMappingTemplate(template, cppName, null, this);
                } else {
                    if (Util.isStringType(simpleType, config)
                            && (xsType2validationDataStructName.get(simpleType) != null)
                    /*
                     * || xsSimpleType2validationFunctionName.get(simpleType) !=
                     * null
                     */) {
                        simpleTypeValiTmpl = config.getTemplateSimpleValidationStringAtomicData();
                        simpleTypeValiTmpl = TemplateEngine.prepareSimpleTypeValidationTemplate(simpleTypeValiTmpl,
                                simpleType, cppName, element, this);
                    }
                    template = config.getTemplateDataAtomicDataMethod();
                }
                break;
            case LIST:
                if (Util.hasStreamingFacets(simpleType)) {
                    simpleTypeValiTmpl = config.getTemplateSimpleValidationNumericListData();
                    simpleTypeValiTmpl = TemplateEngine.prepareSimpleTypeValidationTemplate(simpleTypeValiTmpl,
                            simpleType, cppName, element, this);
                }
                template = config.getTemplateDataListConversion();
                template = TemplateEngine.prepareSimpleTypeValidationTemplate(template, simpleType, cppName, element,
                        this);
                break;
            case UNION:
                String cppType = cppEnumOrUnionNameCreator.createUnionTypeName(simpleType, getElementStack());
                unionsToBeHandled.add(new EnumNameTypePair(cppType, simpleType));
            default:
                template = config.getTemplateUnionDataAtomicDataMethod();
                break;
            }
            privateImplSourceFile.println(TemplateEngine.fillInTemplate(template, cppName, element, null,
                    createDataConvenienceMethodName(cppName), typeDefinition, simpleTypeValiTmpl, this));
        } else {
            privateImplSourceFile.print(config.getIndentation());
            privateImplSourceFile.println("return true;");
        }

        privateImplSourceFile.println("}");
        privateImplSourceFile.println();
    }

    /**
     * Prints parameter list of internal data method to given stream (including
     * parenthesis).
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printDataInternalParameterList(PrintStream stream) {
        stream.print("( const ParserChar* text, size_t textLength )");
    }

    /**
     * Prints return type of internal data method to given stream.
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printDataInternalReturnType(PrintStream stream) {
        stream.print("bool");
    }

    /**
     * Prints header declaration of isDifferentNamespaceAllowed method.
     */
    protected void printDifferentNamespaceAllowedHeaderDecl(PrintStream stream) {
        stream.println("virtual bool " + "isDifferentNamespaceAllowed" + "();");
    }

    /**
     * Prints begin of implementation of isDifferentNamespaceAllowed().
     */
    protected void printDifferentNamespaceAllowedImplStart(PrintStream stream) {
        stream.println(config.getOutputSourceFileMethodDelimiter());
        stream.println("bool " + config.getClassNamePrivate() + "::" + "isDifferentNamespaceAllowed" + "()");
        stream.println("{");

        stream.print(config.getIndentation());
        stream.println("if ( mElementDataStack.empty() )");
        stream.print(config.getIndentation());
        stream.print(config.getIndentation());
        stream.println("return true;");
        stream.println();
    }

    /**
     * Prints big switch in isDifferentNamespaceAllowed method (main part of
     * that method's impl). Prints closing bracket of that method as well.
     */
    protected void printDifferentNamespaceAllowedImplSwitch(PrintStream stream) {
        if (!elementsToParseNSDecls.isEmpty() || !elementsWithXsAny.isEmpty()) {
            stream.print(config.getIndentation());
            stream.println("switch ( mElementDataStack.back().typeID )");
            stream.print(config.getIndentation());
            stream.println("{");

            Set<String> handledIDs = new HashSet<String>();
            for (XSElementDeclaration element : elementsToParseNSDecls) {
                String typeID = typeIdMapping.get(element.getTypeDefinition());
                if (!handledIDs.contains(typeID)) {
                    stream.print(config.getIndentation());
                    stream.println("// " + elementNameMapping.get(element).cppElementName);
                    PrinterUtils.printTypeIDcaseReturnTrue(stream, typeID, config);
                    handledIDs.add(typeID);
                }
            }
            for (XSElementDeclaration element : elementsWithXsAny) {
                String typeID = typeIdMapping.get(element.getTypeDefinition());
                if (!handledIDs.contains(typeID)) {
                    stream.print(config.getIndentation());
                    stream.println("// " + elementNameMapping.get(element).cppElementName);
                    PrinterUtils.printTypeIDcaseReturnTrue(stream, typeID, config);
                    handledIDs.add(typeID);
                }
            }

            stream.print(config.getIndentation());
            stream.println("}"); // switch
        }
        stream.print(config.getIndentation());
        stream.println("return false;");

        stream.println("}"); // method
        stream.println();
    }

    /**
     * Prints a new line character.
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printEmptyLine(PrintStream stream) {
        stream.println();
    }

    /**
     * Prints end[element] method.
     * 
     * @param cppName
     *            C++ element name.
     * @param element
     *            XSD Element.
     */
    protected void printEndConvenienceMethod(String cppName, XSElementDeclaration element) {
        String methodName = Util.createEndConvenienceMethodName(cppName, config);
        String paraList = createEndMethodParameterList();
        printEndConvenienceMethodToHeader(methodName, paraList);
        for (ICodePrinter printer : printers) {
            printer.printEndMethodToHeader(methodName, paraList, cppName, element);
            printer.printEndMethodToSource(methodName, paraList, cppName, element);
        }
    }

    /**
     * Prints end[element] method to header file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     */
    protected void printEndConvenienceMethodToHeader(String methodName, String parameterList) {
        PrinterUtils.printEndMethodDeclTypeModifiers(publicImplHeaderFile);
        publicImplHeaderFile.print(" ");
        PrinterUtils.printEndMethodReturnType(publicImplHeaderFile);
        publicImplHeaderFile.print(" ");
        publicImplHeaderFile.print(methodName);
        publicImplHeaderFile.print(parameterList);
        PrinterUtils.printEndMethodDefaultImpl(publicImplHeaderFile, false, config);
        publicImplHeaderFile.println();
    }

    /**
     * Prints internal used end[element] method.
     * 
     * @param cppName
     *            C++ name of element.
     */
    protected void printEndInternalMethod(String cppName) {
        privateImplHeaderFile.print("bool ");
        String methodName = Util.createEndConvenienceMethodName(cppName, config);
        privateImplHeaderFile.print(Util.createEndInternalMethodName(cppName, config));
        String paraList = createEndMethodParameterList();
        privateImplHeaderFile.print(paraList);
        privateImplHeaderFile.print("{");
        privateImplHeaderFile.print("return " + config.getPublicImplMember() + "->" + methodName + paraList + ";");
        privateImplHeaderFile.print("}");
        privateImplHeaderFile.println();
    }

    /**
     * Prints enum itself to its header file.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     * @param simpleType
     *            XSD type representing enum.
     */
    protected void printEnum(String cppEnumTypeName, XSSimpleTypeDefinition simpleType) {
        enumHeaderFile.println("enum " + cppEnumTypeName);
        enumHeaderFile.println("{");

        StringList enumStringList = simpleType.getLexicalEnumeration();
        List<String> enumValues = Util.stringListToList(enumStringList);
        for (int i = 0; i < enumValues.size(); i++) {
            enumHeaderFile.print(config.getIndentation());
            enumHeaderFile.print(Util.createEnumValueName(cppEnumTypeName, enumValues, i, simpleType, config));
            enumHeaderFile.print(" = ");
            enumHeaderFile.print(i);
            enumHeaderFile.print(",");
            enumHeaderFile.println();
        }
        enumHeaderFile.print(config.getIndentation());
        enumHeaderFile.print(Util.createEnumCountName(cppEnumTypeName, config));
        enumHeaderFile.print(" = ");
        enumHeaderFile.println(enumValues.size() + ",");

        enumHeaderFile.print(config.getIndentation());
        enumHeaderFile.print(Util.createEnumNotPresentName(cppEnumTypeName, config));
        enumHeaderFile.print(" = ");
        enumHeaderFile.println(enumValues.size() + 1);

        enumHeaderFile.println("};");
        enumHeaderFile.println();
    }

    /**
     * Prints enum specific convenience functions.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     * @param simpleType
     *            XSD type representing enum.
     */
    protected void printEnumFunctions(String cppEnumTypeName, XSSimpleTypeDefinition simpleType) {
        // toEnum
        enumHeaderFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumFuncToEnumDecl(), cppEnumTypeName, simpleType, null, 0, this), null, null, null, null,
                null, null, this));
        enumHeaderFile.println();
        enumHeaderFile.println();

        enumSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        enumSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumFuncToEnumImpl(), cppEnumTypeName, simpleType, null, 0, this), null, null, null, null,
                null, null, this));
        enumSourceFile.println();

        // toEnumDataPrefix
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();
        privateImplHeaderFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumFuncDataPrefixDecl(), cppEnumTypeName, simpleType, null, 0, this), null, null, null,
                null, null, null, this));
        privateImplHeaderFile.println();

        privateImplSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        privateImplSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumFuncDataPrefixImpl(), cppEnumTypeName, simpleType, null, 0, this), null, null, null,
                null, null, null, this));
        privateImplSourceFile.println();

        // characterData2EnumData
        privateImplHeaderFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumFuncCharDataDecl(), cppEnumTypeName, simpleType, null, 0, this), null, null, null,
                null, null, null, this));
        privateImplHeaderFile.println();

        privateImplSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        privateImplSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumFuncCharDataImpl(), cppEnumTypeName, simpleType, null, 0, this), null, null, null,
                null, null, null, this));
        privateImplSourceFile.println();

        // dataEnumEnd
        privateImplHeaderFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumFuncDataEndDecl(), cppEnumTypeName, simpleType, null, 0, this), null, null, null, null,
                null, null, this));
        privateImplHeaderFile.println();

        privateImplSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        privateImplSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumFuncDataEndImpl(), cppEnumTypeName, simpleType, null, 0, this), null, null, null, null,
                null, null, this));
        privateImplSourceFile.println();
    }

    /**
     * Prints enum map.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     * @param simpleType
     *            XSD type representing enum.
     */
    protected void printEnumMap(String cppEnumTypeName, XSSimpleTypeDefinition simpleType) {
        enumHeaderFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumMapDeclaration(), cppEnumTypeName, simpleType, null, 0, this), null, null, null, null,
                null, null, this));
        enumHeaderFile.println();
        enumHeaderFile.println();

        enumSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        enumSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                .getTemplateEnumMapDefinitionStart(), cppEnumTypeName, simpleType, null, 0, this), null, null, null,
                null, null, null, this));
        enumSourceFile.println("{");

        StringList enumStringList = simpleType.getLexicalEnumeration();
        List<String> enumValues = Util.stringListToList(enumStringList);
        Collections.sort(enumValues);
        for (int i = 0; i < enumValues.size(); i++) {
            enumSourceFile.print(TemplateEngine.fillInTemplate(TemplateEngine.fillInEnumTemplate(config
                    .getTemplateEnumMapEntry(), cppEnumTypeName, simpleType, enumValues, i, this), null, null, null,
                    null, null, null, this));
            if (i != enumValues.size() - 1) {
                enumSourceFile.print(",");
            }
            enumSourceFile.println();
        }

        enumSourceFile.println("};");
        enumSourceFile.println();
    }

    /**
     * Prints beginning of output enum header file.
     */
    protected void printEnumsHeaderFileBeginning() {
        enumHeaderFile.println(config.getOutFileHeader());
        enumHeaderFile.println();
        enumHeaderFile.println();
        PrinterUtils.printIncludeProtection(enumHeaderFile, PrinterUtils.createIncludeProtectionMacro(config
                .getNamespace(), config.getClassNamePublic() + config.getOutputEnumsFileSuffix()));
        enumHeaderFile.println();
        enumHeaderFile.println();

        PrinterUtils.printIncludes(enumHeaderFile, config.getIncludeFilesForEnumsHeader());
        enumHeaderFile.println();
        enumHeaderFile.println();

        PrinterUtils.printNamespaceOpen(enumHeaderFile, config.getNamespace());
        enumHeaderFile.println();
        enumHeaderFile.println();

        PrinterUtils.printConvenienceTypedefs(enumHeaderFile, false, config);
        enumHeaderFile.println();
        enumHeaderFile.println();
    }

    /**
     * Prints end of generated enum header file.
     */
    protected void printEnumsHeaderFileEnd() {
        enumHeaderFile.println();
        enumHeaderFile.println();
        PrinterUtils.printNamespaceClose(enumHeaderFile, config);

        enumHeaderFile.println("#endif");
    }

    /**
     * Prints beginning of generated enum source file.
     */
    protected void printEnumsSourceFileBeginning() {
        enumSourceFile.println(config.getOutFileHeader());
        List<String> includes = new ArrayList<String>();
        includes.add(config.getIncludePrecompiledHeader());
        String enumHeaderPath = config.getOutputEnumHeaderFileName();
        includes.add(enumHeaderPath.substring(enumHeaderPath.lastIndexOf('/') + 1));
        includes.addAll(config.getIncludeFilesForEnumsSource());
        PrinterUtils.printIncludes(enumSourceFile, includes);
        enumSourceFile.println();
        enumSourceFile.println();
        PrinterUtils.printNamespaceOpen(enumSourceFile, config.getNamespace());
        enumSourceFile.println();
        enumSourceFile.println();
    }

    /**
     * Prints end of generated enum source file.
     */
    protected void printEnumsSourceFileEnd() {
        enumSourceFile.println();
        PrinterUtils.printNamespaceClose(enumSourceFile, config);
    }

    /**
     * Prints beginning of generated C++ findElementHash file.
     */
    protected void printFindElementHashFileBeginning() {
        findElementHashFile.println(config.getOutFileHeader());
        List<String> includes = new ArrayList<String>();
        includes.add(config.getIncludePrecompiledHeader());
        PrinterUtils.printIncludes(findElementHashFile, includes);
        PrinterUtils.printIncludeGeneratedHeader(findElementHashFile, config.getOutputHeaderFileNamePrivate());
        findElementHashFile.println();
        findElementHashFile.println();
        PrinterUtils.printNamespaceOpen(findElementHashFile, config.getNamespace());
        findElementHashFile.println();
        findElementHashFile.println();
        printFindElementHashImplStart();
        printFindElementHashImplSwitch();
    }

    /**
     * Prints end of generated C++ findElementHash file.
     */
    protected void printFindElementHashFileEnd() {
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("default:");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("return false;");

        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("}"); // close switch
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("}"); // close root if

        findElementHashFile.println();
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("return true;");
        findElementHashFile.println("}"); // close method
        findElementHashFile.println();

        // isXsAnyAllowed()
        printXsAnyAllowedImplStart();
        printXsAnyAllowedImplSwitch();

        // isDifferentNamespaceAllowed()
        printDifferentNamespaceAllowedImplStart(findElementHashFile);
        printDifferentNamespaceAllowedImplSwitch(findElementHashFile);

        PrinterUtils.printNamespaceClose(findElementHashFile, config);
    }

    /**
     * Prints header declaration of findElementHash method.
     */
    protected void printFindElementHashHeaderDecl() {
        privateImplHeaderFile.println("virtual bool " + "findElementHash" + "( ElementData& elementData );");
    }

    /**
     * Prints begin of implementation of findElementHash().
     */
    protected void printFindElementHashImplStart() {
        findElementHashFile.println(config.getOutputSourceFileMethodDelimiter());
        String elemDataVariableName = "elementData";
        findElementHashFile.println("bool " + config.getClassNamePrivate() + "::" + "findElementHash"
                + "( ElementData& " + elemDataVariableName + " )");
        findElementHashFile.println("{");

        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("if ( mElementDataStack.empty() )");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("{");

        String codeTemplate = config.getTemplateFindHashSetValues();
        XSElementDeclaration rootElement = findRootElement(getModel(), config.getRootElementName());

        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("if( elementData.elementHash == "
                + Util.createElementNameHashIdentifier(rootElement.getName()) + " )");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("{");

        findElementHashFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInFindHashTemplate(codeTemplate,
                this.elementNameMapping.get(rootElement).cppElementName, rootElement, config, typeIdMapping), null,
                null, null, null, null, null, this));

        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("}");

        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("else");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("{");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("return false;");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("}");

        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("}");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("else");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("{");

        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("switch ( " + "mElementDataStack.back().typeID" + " )");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("{");
    }

    /**
     * Prints big switch in findElementHash method (main part of that method's
     * impl).
     */
    protected void printFindElementHashImplSwitch() {
        String codeTemplate = config.getTemplateFindHashSetValues();

        for (XSTypeDefinition type : typeIdMapping.keySet()) {
            DirectChildrenCollector childrenCollector = new DirectChildrenCollector();
            SortedSet<XSElementDeclaration> children = childrenCollector.collect(type, substitutionGroups,
                    new HashSet<XSTypeDefinition>());
            if (children == null || children.isEmpty()) {
                continue;
            }

            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("case " + typeIdMapping.get(type) + ":");

            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("switch ( elementData.elementHash )");
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("{");

            Set<String> childrenElementNames = new HashSet<String>();
            for (XSElementDeclaration child : children) {
                if (childrenElementNames.contains(child.getName())) {
                    continue;
                }
                childrenElementNames.add(child.getName());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.println("case " + Util.createElementNameHashIdentifier(child.getName()) + ":");

                findElementHashFile.print(TemplateEngine.fillInTemplate(TemplateEngine.fillInFindHashTemplate(
                        codeTemplate, this.elementNameMapping.get(child).cppElementName, child, config, typeIdMapping),
                        null, null, null, null, null, null, this));

                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.println("break;");
            }

            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("default:");
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("return false;");

            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("}");

            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("break;");
        }
    }

    /**
     * Prints declaration of freeAttributes method to C++ header.
     * 
     * @param cppName
     *            C++ name of element to validate.
     */
    protected void printFreeAttributesHeaderDecl(String cppName) {
        printFreeAttributesReturnType(privateImplHeaderFile);
        privateImplHeaderFile.print(" ");
        privateImplHeaderFile.print(Util.createFreeAttributesMethodName(cppName));
        printFreeAttributesParameterList(privateImplHeaderFile);
        privateImplHeaderFile.println(";");
    }

    /**
     * Prints implementation of freeAttributes method to C++ source file.
     * 
     * @param cppName
     *            C++ name of element to validate.
     * @param element
     *            XSD representation of element.
     * @param attrs
     *            Attributes of element.
     */
    protected void printFreeAttributesImpl(String cppName, XSElementDeclaration element, List<XSAttributeUse> attrs) {
        privateImplSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        printFreeAttributesReturnType(privateImplSourceFile);
        privateImplSourceFile.print(" ");
        privateImplSourceFile.print(config.getClassNamePrivate());
        privateImplSourceFile.print("::");
        privateImplSourceFile.print(Util.createFreeAttributesMethodName(cppName));
        printFreeAttributesParameterList(privateImplSourceFile);
        privateImplSourceFile.println();
        privateImplSourceFile.println("{");

        if (attrs != null && !attrs.isEmpty() || Util.isUnknownAttributesMemberRequired(element.getTypeDefinition())) {
            printAttributeFreeing(cppName, element, attrs);
        }

        privateImplSourceFile.print(config.getIndentation());
        privateImplSourceFile.println("return true;");

        privateImplSourceFile.println("}");
        privateImplSourceFile.println();
    }

    /**
     * Prints parameter list of freeAttributes method to given stream (including
     * parenthesis).
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printFreeAttributesParameterList(PrintStream stream) {
        stream.print("( void* " + config.getAttributeDataParameterName() + " )");
    }

    /**
     * Prints return type of freeAttributes method to given stream.
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printFreeAttributesReturnType(PrintStream stream) {
        stream.print("bool");
    }

    /**
     * Prints a function declaration.
     * 
     * @param stream
     *            Stream to print to.
     * @param returnType
     *            Return type of the function.
     * @param functionName
     *            The function name.
     * @param parameters
     *            Function parameters (without parenthesis but with comma).
     */
    protected void printFunctionDeclaration(PrintStream stream, String returnType, String functionName,
            String parameters) {
        stream.println(returnType + " " + functionName + "( " + parameters + " );");
    }

    /**
     * Prints a function definition head (without curly braces).
     * 
     * @param stream
     *            Stream to print to.
     * @param returnType
     *            Return type of the function.
     * @param className
     *            Class name if a method is handled. <code>null</code>
     *            otherwise.
     * @param functionName
     *            The function name.
     * @param parameters
     *            Function parameters (without parenthesis but with comma).
     */
    protected void printFunctionDefinitionHead(PrintStream stream, String returnType, String className,
            String functionName, String parameters) {
        stream.println(config.getOutputSourceFileMethodDelimiter());
        stream.print(returnType + " ");
        if (className != null) {
            stream.print(className + "::");
        }
        stream.println(functionName + "( " + parameters + " )");
    }

    /**
     * Prints beginning of generated C++ function map file.
     */
    protected void printFunctionMapFileBeginning() {
        functionMapFile.println(config.getOutFileHeader());
        List<String> includes = new ArrayList<String>();
        includes.add(config.getIncludePrecompiledHeader());
        PrinterUtils.printIncludes(functionMapFile, includes);
        PrinterUtils.printIncludeGeneratedHeader(functionMapFile, config.getOutputHeaderFileNamePrivate());
        functionMapFile.println();
        functionMapFile.println();
        PrinterUtils.printNamespaceOpen(functionMapFile, config.getNamespace());
        functionMapFile.println();
        functionMapFile.println();
        printInitFunctionMapImplStart();
    }

    /**
     * Prints end of generated C++ function map file.
     */
    protected void printFunctionMapFileEnd() {
        printInitFunctionMapImplEnd();
        functionMapFile.println();
        PrinterUtils.printNamespaceClose(functionMapFile, config);
    }

    /**
     * Prints C++ hash constants.
     * 
     * @param stream
     *            Stream to print to.
     * @param constantsCreator
     *            Object to get constants from.
     */
    protected void printHashConstants(PrintStream stream, CppConstantsCreator constantsCreator) {
        SortedMap<String, String> stringConstants = constantsCreator.getHashNameValueMap();
        Map<String, String> hashNameToStringName = constantsCreator.getHashNameToStringName();
        for (Map.Entry<String, String> entry : stringConstants.entrySet()) {
            stream.println(createCppHashType() + " " + entry.getKey() + " = " + entry.getValue() + ";");
            printNameMapEntry(entry.getKey(), hashNameToStringName.get(entry.getKey()));
        }
        // print constants for state machine root and end
        stream.println(createCppHashType() + " " + Constants.STATE_MACHINE_ROOT_CPP_CONSTANT + " = "
                + Util.calculateHash(Constants.STATE_MACHINE_ROOT_NODE_NAME) + ";");
        stream.println(createCppHashType() + " " + Constants.STATE_MACHINE_END_CPP_CONSTANT + " = "
                + Util.calculateHash(Constants.STATE_MACHINE_END_NODE_NAME) + ";");
    }

    /**
     * Prints include files for generated header file.
     */
    protected void printHeaderIncludes() {
        PrinterUtils.printIncludes(privateImplHeaderFile, config.getIncludeFilesForPrivateHeader());
    }

    /**
     * Prints header declaration of initFunctionMap method.
     */
    protected void printInitFunctionMapHeaderDecl() {
        privateImplHeaderFile.println("void " + PrinterUtils.createInitFunctionMapMethodName() + "();");
    }

    /**
     * Prints end of implementation of initFunctionMap().
     */
    protected void printInitFunctionMapImplEnd() {
        functionMapFile.println("}");
        functionMapFile.println();
    }

    /**
     * Prints begin of implementation of initFunctionMap().
     */
    protected void printInitFunctionMapImplStart() {
        functionMapFile.println(config.getOutputSourceFileMethodDelimiter());
        functionMapFile.println("void " + config.getClassNamePrivate() + "::"
                + PrinterUtils.createInitFunctionMapMethodName() + "()");
        functionMapFile.println("{");
    }

    /**
     * Prints header declaration of initNameMap method.
     */
    protected void printInitNameMapHeaderDecl() {
        privateImplHeaderFile.println("void " + PrinterUtils.createInitNameMapMethodName() + "();");
    }

    /**
     * Prints end of implementation of initNameMap().
     */
    protected void printInitNameMapImplEnd() {
        nameMapFile.println("}");
        nameMapFile.println();
    }

    /**
     * Prints begin of implementation of initNameMap().
     */
    protected void printInitNameMapImplStart() {
        nameMapFile.println(config.getOutputSourceFileMethodDelimiter());
        nameMapFile.println("void " + config.getClassNamePrivate() + "::" + PrinterUtils.createInitNameMapMethodName()
                + "()");
        nameMapFile.println("{");
    }

    /**
     * Prints a name map entry.
     * 
     * @param hashID
     *            C++ constant for hash.
     * @param elemNameID
     *            C++ constant for element name.
     */
    protected void printNameMapEntry(String hashID, String elemNameID) {
        nameMapFile.println(createNameMapMembername() + "[" + hashID + "] = " + elemNameID + ";");
    }

    /**
     * Prints beginning of generated C++ name map file.
     */
    protected void printNameMapFileBeginning() {
        nameMapFile.println(config.getOutFileHeader());
        List<String> includes = new ArrayList<String>();
        includes.add(config.getIncludePrecompiledHeader());
        PrinterUtils.printIncludes(nameMapFile, includes);
        PrinterUtils.printIncludeGeneratedHeader(nameMapFile, config.getOutputHeaderFileNamePrivate());
        nameMapFile.println();
        nameMapFile.println();
        PrinterUtils.printNamespaceOpen(nameMapFile, config.getNamespace());
        nameMapFile.println();
        nameMapFile.println();
        printInitNameMapImplStart();
    }

    /**
     * Prints end of generated C++ name map file.
     */
    protected void printNameMapFileEnd() {
        printInitNameMapImplEnd();
        nameMapFile.println();
        PrinterUtils.printNamespaceClose(nameMapFile, config);
    }

    /**
     * Prints C++ constant declarations for xml namespaces.
     */
    protected void printNamespaceConstantDecls(PrintStream stream) {
        XSNamespaceItemList namespaceItems = getModel().getNamespaceItems();
        for (int i = 0; i < namespaceItems.getLength(); i++) {
            String namespace = namespaceItems.item(i).getSchemaNamespace();
            if (namespace != null) {
                String stringName = Util.createNamespaceStringConstantName(namespace, config);
                PrinterUtils.printCppStringConstantDecl(stream, stringName);
                String hashName = Util.createNamespaceHashConstantName(namespace, config);
                PrinterUtils.printCppHashConstant(stream, hashName, namespace);

                printNameMapEntry(hashName, stringName);
            }
        }
    }

    /**
     * Prints C++ constant definitions for xml namespaces.
     */
    protected void printNamespaceConstantDefs(PrintStream stream) {
        XSNamespaceItemList namespaceItems = getModel().getNamespaceItems();

        if (namespaceItems.getLength() > 0) {
            stream.println(config.getOutputSourceFileMethodDelimiter());
        }

        for (int i = 0; i < namespaceItems.getLength(); i++) {
            String namespace = namespaceItems.item(i).getSchemaNamespace();
            if (namespace != null) {
                String stringName = Util.createNamespaceStringConstantName(namespace, config);
                PrinterUtils.printCppStringConstantDef(stream, stringName, namespace);
            }
        }
    }

    /**
     * Prints parsing of attribute "xmlns".
     * 
     * @param elemName
     *            C++ Element name.
     * @param element
     *            XSD Element.
     */
    protected void printParseAttrXMLNS(String elemName, XSElementDeclaration element) {
        privateImplSourceFile.print(config.getIndentation());
        privateImplSourceFile.println("case "
                + Util.createAttributeNameHashIdentifier(Util.getAttributeOriginalName(
                        XSFactory.createAttributeXmlns(), config)) + ":");
        privateImplSourceFile.print(config.getIndentation());
        privateImplSourceFile.println("{");

        privateImplSourceFile.println(TemplateEngine.fillInTemplate(config.getTemplateParseAttrXMLNS(), elemName,
                element, null, null, null, null, this));

        privateImplSourceFile.print(config.getIndentation());
        privateImplSourceFile.println("break;");
        privateImplSourceFile.print(config.getIndentation());
        privateImplSourceFile.println("}");
    }

    /**
     * Prints definition of oveccount constant for pcre.
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printPcreOVECCOUNT(PrintStream stream) {
        stream.println(config.getOutputSourceFileMethodDelimiter());
        stream.println("const int PCRE_OVECCOUNT = 30;    /* should be a multiple of 3 */");
    }

    /**
     * Prints declaration of preBegin method to C++ header.
     * 
     * @param cppName
     *            C++ name of element to validate.
     */
    protected void printPreBeginHeaderDecl(String cppName) {
        printValidateBeginReturnType(privateImplHeaderFile);
        privateImplHeaderFile.print(" ");
        privateImplHeaderFile.print(Util.createPreBeginMethodName(cppName));
        printValidateBeginParameterList(privateImplHeaderFile);
        privateImplHeaderFile.println(";");
    }

    /**
     * Prints implementation of preBegin method to C++ source file.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppName
     *            C++ name of element to validate.
     * @param element
     *            XSD representation of element.
     * @param attrs
     *            Attributes of element.
     * @param complexType
     *            Complex XSD Type of this element or null.
     */
    protected void printPreBeginImpl(PrintStream stream, String cppName, XSElementDeclaration element,
            List<XSAttributeUse> attrs, XSComplexTypeDefinition complexType) {
        stream.println(config.getOutputSourceFileMethodDelimiter());
        printValidateBeginReturnType(stream);
        stream.print(" ");
        stream.print(config.getClassNamePrivate());
        stream.print("::");
        stream.print(Util.createPreBeginMethodName(cppName));
        printValidateBeginParameterList(stream);
        stream.println();
        stream.println("{");

        printComplexValidationBlockOpen(stream);
        stream.print(config.getIndentation());
        stream.print(config.getIndentation());
        stream.print("bool validationResult = " + Util.createValidateBeginMethodName(cppName));
        printValidateBeginParameterListForCall(stream);
        stream.println(";");
        stream.print(config.getIndentation());
        stream.print(config.getIndentation());
        stream.println("if ( !validationResult ) return false;");
        stream.println();
        printComplexValidationBlockClose(stream);

        if ((attrs != null && !attrs.isEmpty()) || Util.isUnknownAttributesMemberRequired(element.getTypeDefinition())) {
            printAttributeParsing(cppName, element, attrs);
        }

        stream.print(config.getIndentation());
        stream.println("return true;");

        stream.println("}");
        stream.println();
    }

    /**
     * Prints declaration of preEnd method to C++ header.
     * 
     * @param cppName
     *            C++ name of element to validate.
     */
    protected void printPreEndHeaderDecl(String cppName) {
        printValidateEndReturnType(privateImplHeaderFile);
        privateImplHeaderFile.print(" ");
        privateImplHeaderFile.print(Util.createPreEndMethodName(cppName));
        printValidateEndParameterList(privateImplHeaderFile);
        privateImplHeaderFile.println(";");
    }

    /**
     * Prints implementation of preEnd method to C++ source file.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppName
     *            C++ name of element to validate.
     * @param element
     *            XSD representation of element.
     * @param hasChardata
     *            Indicates if DataEnd() must be called.
     * @param typeDefinition
     *            Type of this element.
     */
    protected void printPreEndImpl(PrintStream stream, String cppName, XSElementDeclaration element,
            boolean hasChardata, XSTypeDefinition typeDefinition) {
        stream.println(config.getOutputSourceFileMethodDelimiter());
        printValidateEndReturnType(stream);
        stream.print(" ");
        stream.print(config.getClassNamePrivate());
        stream.print("::");
        stream.print(Util.createPreEndMethodName(cppName));
        printValidateEndParameterList(stream);
        stream.println();
        stream.println("{");

        printComplexValidationBlockOpen(stream);
        stream.print(config.getIndentation());
        stream.print(config.getIndentation());
        stream.print("bool validationResult = " + Util.createValidateEndMethodName(cppName));
        printValidateEndParameterList(stream);
        stream.println(";");
        stream.print(config.getIndentation());
        stream.print(config.getIndentation());
        stream.println("if ( !validationResult ) return false;");
        stream.println();
        printComplexValidationBlockClose(stream);

        XSSimpleTypeDefinition simpleType = null;
        if (typeDefinition instanceof XSSimpleTypeDefinition) {
            simpleType = (XSSimpleTypeDefinition) typeDefinition;
        }
        Variety variety = Util.findVariety(simpleType);

        boolean printDefaultImpl = true;
        if (hasChardata) {
            if (simpleType == null) {
                simpleType = Util.findSimpleTypeDefinition(typeDefinition);
                variety = Util.findVariety(simpleType);
            }
            XSSimpleTypeDefinition listType = null;
            if (variety == Variety.LIST) {
                listType = simpleType;
                simpleType = Util.findListItemType(simpleType);
            }
            String xsdType = Util.findXSDSimpleTypeString(simpleType, config);
            String cppValidateEnd = null;
            String simpleTypeValiTmpl = null;
            switch (variety) {
            case LIST:
                if (Util.hasFacetEnum(simpleType)) {
                    String cppEnumTypeName = cppEnumOrUnionNameCreator
                            .createEnumTypeName(simpleType, getElementStack());
                    enumsToBeHandled.add(new EnumNameTypePair(cppEnumTypeName, simpleType));
                    List<String> sortedEnumValues = Util.stringListToList(simpleType.getLexicalEnumeration());
                    cppValidateEnd = config.getTypeMapping().get(xsdType).getEnumDataListEnd();
                    cppValidateEnd = TemplateEngine.fillInTypeMappingTemplate(cppValidateEnd, null, null, this);
                    cppValidateEnd = TemplateEngine.fillInEnumTemplate(cppValidateEnd, cppEnumTypeName, simpleType,
                            sortedEnumValues, 0, this);
                } else {
                    cppValidateEnd = config.getTemplateDataListValidateEnd();
                    cppValidateEnd = TemplateEngine.prepareSimpleTypeValidationTemplate(cppValidateEnd, listType,
                            cppName, element, this);
                }
                break;
            case ATOMIC:
                if (Util.hasFacetEnum(simpleType)) {
                    String cppEnumTypeName = cppEnumOrUnionNameCreator
                            .createEnumTypeName(simpleType, getElementStack());
                    enumsToBeHandled.add(new EnumNameTypePair(cppEnumTypeName, simpleType));
                    List<String> sortedEnumValues = Util.stringListToList(simpleType.getLexicalEnumeration());
                    cppValidateEnd = TemplateEngine.fillInEnumTemplate(config.getTemplateEnumDataAtomicConversion(),
                            cppEnumTypeName, simpleType, sortedEnumValues, 0, this);
                } else {
                    cppValidateEnd = null;
                    if (Util.isFacetPatternSupported(simpleType, config)) {
                        cppValidateEnd = config.getTypeMapping().get(xsdType)
                                .getDataAtomicValidateEndImplFacetPattern();
                        cppValidateEnd = TemplateEngine.fillInTypeMappingTemplate(cppValidateEnd, null, null, this);
                        cppValidateEnd = TemplateEngine.fillInSimpleValidationTemplate(cppValidateEnd, simpleType,
                                config, xsSimpleType2validationFunctionName);
                    } else {
                        cppValidateEnd = config.getTypeMapping().get(xsdType).getDataAtomicValidateEndImpl();
                    }
                    if (cppValidateEnd != null) {
                        cppValidateEnd = TemplateEngine.fillInTypeMappingTemplate(cppValidateEnd, null, null, this);
                    }

                    if (Util.isNumericType(simpleType, config)) {
                        simpleTypeValiTmpl = config.getTemplateSimpleValidationNumericAtomicData();
                    } else {
                        simpleTypeValiTmpl = config.getTemplateSimpleValidationStringAtomicDataEnd();

                    }
                }
                break;
            case UNION:
                cppValidateEnd = config.getTemplateUnionDataAtomicConversion();
                cppValidateEnd = TemplateEngine.fillInTemplate(cppValidateEnd, cppName, element, null,
                        createDataConvenienceMethodName(cppName), typeDefinition, simpleTypeValiTmpl, this);
                cppValidateEnd = TemplateEngine.fillInUnionTemplate(cppValidateEnd, simpleType, this);
                break;
            }

            if (cppValidateEnd != null && cppValidateEnd.length() > 0) {
                printDefaultImpl = false;
                privateImplSourceFile.println(TemplateEngine.fillInTemplate(cppValidateEnd, cppName, element, null,
                        createDataConvenienceMethodName(cppName), typeDefinition, simpleTypeValiTmpl, this));
            }
        }

        if (printDefaultImpl) {
            privateImplSourceFile.println(TemplateEngine.fillInTemplate(
                    Constants.TMPL_DATA_ATOMIC_DATA_METHOD_IMPL_DEFAULT, cppName, element, null,
                    createDataConvenienceMethodName(cppName), typeDefinition, null, this));
        }

        privateImplSourceFile.println("}");
        privateImplSourceFile.println();
    }

    /**
     * Prints first content of private impl C++ header file. Including:
     * <ul>
     * <li>heading comment</li>
     * <li>include protection</li>
     * <li>include files</li>
     * <li>namespace</li>
     * <li>class declaration with base class</li>
     * <li>open curly bracket and public:</li>
     * </ul>
     */
    protected void printPrivateHeaderFileBeginning() {
        privateImplHeaderFile.println(config.getOutFileHeader());
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();
        PrinterUtils.printIncludeProtection(privateImplHeaderFile, PrinterUtils.createIncludeProtectionMacro(config
                .getNamespace(), config.getClassNamePrivate()));
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();
        printHeaderIncludes();
        PrinterUtils.printIncludeGeneratedHeader(privateImplHeaderFile, config.getOutputAttributesFileName());
        PrinterUtils.printIncludeGeneratedHeader(privateImplHeaderFile, config.getOutputHeaderFileNamePublic());
        PrinterUtils.printIncludeGeneratedHeader(privateImplHeaderFile, config.getOutputValidationDataHeaderFileName());
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();

        PrinterUtils.printNamespaceOpen(privateImplHeaderFile, config.getNamespace());
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();

        PrinterUtils.printConvenienceTypedefs(privateImplHeaderFile, true, config);
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();

        // print FunctionMapFactory forward decl
        privateImplHeaderFile.println("class " + config.getClassNameFunctionMapFactory() + ";");
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();

        privateImplHeaderFile.print("class " + config.getClassNamePrivate());
        String baseClass = config.getBaseClassName();
        if (baseClass != null && baseClass.length() > 0) {
            privateImplHeaderFile.print(" : public " + config.getBaseClassNamespace() + "::" + baseClass);
        }
        privateImplHeaderFile.println();
        privateImplHeaderFile.println("{");

        privateImplHeaderFile.println("public:");
        PrinterUtils.printCtorDtorHeaderDecl(privateImplHeaderFile, config.getClassNamePrivate(), true, false, null,
                config);
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();

        privateImplHeaderFile.println("private:");
        privateImplHeaderFile.println("friend class " + config.getClassNameFunctionMapFactory() + ";");
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();
    }

    /**
     * Prints ending of private impl C++ header file. Including:
     * <ul>
     * <li>closing curly bracket and ;</li>
     * <li>closing curly bracket of namespace</li>
     * <li>#endif of include protection</li>
     * </ul>
     */
    protected void printPrivateHeaderFileEnd() {
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();
        privateImplHeaderFile.println("private:");
        PrinterUtils.printDisableDefaultMethods(privateImplHeaderFile, config.getClassNamePrivate());
        privateImplHeaderFile.println();

        printInitFunctionMapHeaderDecl();
        printInitNameMapHeaderDecl();
        privateImplHeaderFile.println();

        privateImplHeaderFile.println("protected:");
        printFindElementHashHeaderDecl();
        printXsAnyAllowedHeaderDecl();
        printDifferentNamespaceAllowedHeaderDecl(privateImplHeaderFile);
        privateImplHeaderFile.println();

        privateImplHeaderFile.println("};");

        privateImplHeaderFile.println();
        PrinterUtils.printNamespaceClose(privateImplHeaderFile, config);

        privateImplHeaderFile.println("#endif");
    }

    /**
     * Prints beginning of generated C++ source file.
     */
    protected void printPrivateSourceFileBeginning(CppConstantsCreator constantsCreator) {
        privateImplSourceFile.println(config.getOutFileHeader());
        printSourceIncludes();
        privateImplSourceFile.println();
        PrinterUtils.printIncludeGeneratedHeader(privateImplSourceFile, config.getOutputHeaderFileNamePrivate());
        privateImplSourceFile.println();
        privateImplSourceFile.println();

        privateImplSourceFile.println(TemplateEngine.fillInTemplate(config.getTemplateDisableWarningUnused(), null,
                null, null, null, null, null, this));
        privateImplSourceFile.println();
        privateImplSourceFile.println();

        PrinterUtils.printNamespaceOpen(privateImplSourceFile, config.getNamespace());
        privateImplSourceFile.println();
        privateImplSourceFile.println();
        printCtorDtorImpl(privateImplSourceFile, config.getClassNamePrivate(), config.getBaseClassName(), true, true);
        privateImplSourceFile.println();

        printNamespaceConstantDefs(privateImplSourceFile);
        privateImplSourceFile.println();

        printStringConstantsDefis(privateImplSourceFile, constantsCreator);
        privateImplSourceFile.println();
        privateImplSourceFile.println();
        privateImplSourceFile.println();
    }

    /**
     * Prints ending of generated C++ source file.
     */
    protected void printPrivateSourceFileEnd() {
        privateImplSourceFile.println();
        privateImplSourceFile.println();
        privateImplSourceFile.println();
        PrinterUtils.printNamespaceClose(privateImplSourceFile, config);
    }

    /**
     * Prints first content of public impl C++ header file. Including:
     */
    protected void printPublicHeaderFileBeginning() {
        publicImplHeaderFile.println(config.getOutFileHeader());
        publicImplHeaderFile.println();
        publicImplHeaderFile.println();
        PrinterUtils.printIncludeProtection(publicImplHeaderFile, PrinterUtils.createIncludeProtectionMacro(config
                .getNamespace(), config.getClassNamePublic()));
        publicImplHeaderFile.println();
        publicImplHeaderFile.println();
        // printHeaderIncludes();
        PrinterUtils.printIncludeGeneratedHeader(publicImplHeaderFile, config.getOutputAttributesFileName());
        publicImplHeaderFile.println();
        publicImplHeaderFile.println();

        PrinterUtils.printNamespaceOpen(publicImplHeaderFile, config.getNamespace());
        publicImplHeaderFile.println();
        publicImplHeaderFile.println();

        // printConvenienceTypedefs(publicImplHeaderFile);
        // publicImplHeaderFile.println();
        // publicImplHeaderFile.println();

        publicImplHeaderFile.print("class " + config.getClassNamePublic());
        // String baseClass = config.getBaseClassName();
        // if (baseClass != null && baseClass.length() > 0) {
        // publicImplHeaderFile.print(" : public " +
        // config.getBaseClassNamespace() + "::" + baseClass);
        // }
        publicImplHeaderFile.println();
        publicImplHeaderFile.println("{");

        publicImplHeaderFile.println("public:");
        PrinterUtils.printCtorDtorHeaderDecl(publicImplHeaderFile, config.getClassNamePublic(), false, true, null,
                config);
        publicImplHeaderFile.println();
        publicImplHeaderFile.println();
    }

    /**
     * Prints ending of public impl C++ header file.
     */
    protected void printPublicHeaderFileEnd() {
        publicImplHeaderFile.println();
        publicImplHeaderFile.println();
        publicImplHeaderFile.println("private:");
        PrinterUtils.printDisableDefaultMethods(publicImplHeaderFile, config.getClassNamePublic());
        publicImplHeaderFile.println();

        publicImplHeaderFile.println("};");

        publicImplHeaderFile.println();
        PrinterUtils.printNamespaceClose(publicImplHeaderFile, config);

        publicImplHeaderFile.println("#endif");
    }

    /**
     * Prints implementation of a simple type validation function.
     * 
     * @param stream
     *            Stream to print to.
     * @param simpleType
     *            XSD type to validate.
     * @param handleStream
     *            Indicates if stream validation functions shall be printed.
     * @param handleStreamEnd
     *            Indicates if stream end validation functions shall be printed.
     */
    protected void printSimpleValidationFunctionImpl(PrintStream stream, XSSimpleTypeDefinition simpleType,
            boolean handleStream, boolean handleStreamEnd) {
        stream.println("{");

        short facets = simpleType.getDefinedFacets();
        // short facets = simpleType.getFixedFacets();

        if ((facets & XSSimpleTypeDefinition.FACET_MAXEXCLUSIVE) == XSSimpleTypeDefinition.FACET_MAXEXCLUSIVE) {
            stream.println(TemplateEngine.fillInTemplate(TemplateEngine
                    .fillInSimpleValidationTemplate(config.getTemplateSimpleValidationMaxExclusive(), simpleType,
                            config, xsSimpleType2validationFunctionName), null, null, null, null, null, null, this));
        }

        if ((facets & XSSimpleTypeDefinition.FACET_MAXINCLUSIVE) == XSSimpleTypeDefinition.FACET_MAXINCLUSIVE) {
            boolean print = true;
            String cppType = Util.findCorrectCppAtomicType(simpleType, config);

            String maxValue = config.getBuiltInTypeMaxValues().get(cppType);
            if (maxValue != null) {
                if (maxValue.equals(simpleType.getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MAXINCLUSIVE))) {
                    print = false;
                }
            }

            if (print) {
                stream.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInSimpleValidationTemplate(config
                        .getTemplateSimpleValidationMaxInclusive(), simpleType, config,
                        xsSimpleType2validationFunctionName), null, null, null, null, null, null, this));
            }
        }

        if ((facets & XSSimpleTypeDefinition.FACET_MINEXCLUSIVE) == XSSimpleTypeDefinition.FACET_MINEXCLUSIVE) {
            stream.println(TemplateEngine.fillInTemplate(TemplateEngine
                    .fillInSimpleValidationTemplate(config.getTemplateSimpleValidationMinExclusive(), simpleType,
                            config, xsSimpleType2validationFunctionName), null, null, null, null, null, null, this));
        }

        if ((facets & XSSimpleTypeDefinition.FACET_MININCLUSIVE) == XSSimpleTypeDefinition.FACET_MININCLUSIVE) {
            boolean print = true;
            String cppType = Util.findCorrectCppAtomicType(simpleType, config);

            String minValue = config.getBuiltInTypeMinValues().get(cppType);
            if (minValue != null) {
                if (minValue.equals(simpleType.getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MININCLUSIVE))) {
                    print = false;
                }
            }

            if (print) {
                stream.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInSimpleValidationTemplate(config
                        .getTemplateSimpleValidationMinInclusive(), simpleType, config,
                        xsSimpleType2validationFunctionName), null, null, null, null, null, null, this));
            }
        }

        if ((facets & XSSimpleTypeDefinition.FACET_LENGTH) == XSSimpleTypeDefinition.FACET_LENGTH) {
            String tmpl = null;
            if (handleStream)
                tmpl = config.getTemplateSimpleValidationLengthStream();
            else if (handleStreamEnd)
                tmpl = config.getTemplateSimpleValidationLengthStreamEnd();
            else
                tmpl = config.getTemplateSimpleValidationLength();
            stream
                    .println(TemplateEngine.fillInTemplate(TemplateEngine.fillInSimpleValidationTemplate(tmpl,
                            simpleType, config, xsSimpleType2validationFunctionName), null, null, null, null, null,
                            null, this));
        }

        if ((facets & XSSimpleTypeDefinition.FACET_MINLENGTH) == XSSimpleTypeDefinition.FACET_MINLENGTH) {
            String tmpl = null;
            if (handleStream)
                tmpl = config.getTemplateSimpleValidationMinLengthStream();
            else if (handleStreamEnd)
                tmpl = config.getTemplateSimpleValidationMinLengthStreamEnd();
            else
                tmpl = config.getTemplateSimpleValidationMinLength();
            stream
                    .println(TemplateEngine.fillInTemplate(TemplateEngine.fillInSimpleValidationTemplate(tmpl,
                            simpleType, config, xsSimpleType2validationFunctionName), null, null, null, null, null,
                            null, this));
        }

        if ((facets & XSSimpleTypeDefinition.FACET_MAXLENGTH) == XSSimpleTypeDefinition.FACET_MAXLENGTH) {
            String tmpl = null;
            if (handleStream)
                tmpl = config.getTemplateSimpleValidationMaxLengthStream();
            else if (handleStreamEnd)
                tmpl = config.getTemplateSimpleValidationMaxLengthStreamEnd();
            else
                tmpl = config.getTemplateSimpleValidationMaxLength();
            stream
                    .println(TemplateEngine.fillInTemplate(TemplateEngine.fillInSimpleValidationTemplate(tmpl,
                            simpleType, config, xsSimpleType2validationFunctionName), null, null, null, null, null,
                            null, this));
        }

        if ((facets & XSSimpleTypeDefinition.FACET_PATTERN) == XSSimpleTypeDefinition.FACET_PATTERN
                && Util.isFacetPatternSupported(simpleType, config)) {
            String tmpl = null;
            if (handleStream)
                tmpl = "";
            else if (handleStreamEnd)
                tmpl = "";
            else
                tmpl = config.getTemplateSimpleValidationPattern();
            stream
                    .println(TemplateEngine.fillInTemplate(TemplateEngine.fillInSimpleValidationTemplate(tmpl,
                            simpleType, config, xsSimpleType2validationFunctionName), null, null, null, null, null,
                            null, this));
        }

        stream.print(TemplateEngine.fillInTemplate(config.getTemplateSimpleValidationDefaultReturn(), null, null, null,
                null, null, null, this));
        stream.println("}");
        stream.println();
    }

    /**
     * Prints validation functions of a simple type.
     * 
     * @param simpleType
     *            Simple type to print validation function for.
     */
    protected void printSimpleValidationFunctions(XSSimpleTypeDefinition simpleType) {
        String functionName = xsSimpleType2validationFunctionName.get(simpleType);
        if (functionName == null) {
            // can this ever happen ???
            return;
        }
        if (!printedSimpleValidationFunctions.contains(functionName)) {
            printedSimpleValidationFunctions.add(functionName);

            String streamFunctionName = null;
            Variety variety = Util.findVariety(simpleType);
            boolean isStringType = false;
            String parameters = "";
            String valueParaName = config.getSimpleValidationFunctionValueParameterName();
            String lengthParaName = config.getSimpleValidationFunctionLengthParameterName();
            String lengthParaType = config.getSimpleValidationFunctionLengthParameterType();
            String simpleValiFuncReturnType = config.getSimpleValidationFunctionReturnType();
            if (variety == Variety.LIST) {
                if (Util.isStringType(simpleType.getItemType(), config)) {
                    parameters = config.getTypeMapping().get(Constants.DEFAULT_XSD_TYPE).getDataListType();
                } else {
                    parameters = Util.findCorrectCppAtomicType(simpleType, config) + "* ";
                }
                parameters += valueParaName;
                if (!parameters.startsWith("const")) {
                    parameters = "const " + parameters;
                }
                parameters += ", " + lengthParaType + " " + lengthParaName;
                streamFunctionName = Util.createSimpleValidationStreamFunctionName(functionName, config);

            } else if (variety == Variety.ATOMIC) {
                parameters = Util.findCorrectCppAtomicType(simpleType, config) + " " + valueParaName;
                if (!parameters.startsWith("const")) {
                    parameters = "const " + parameters;
                }
                isStringType = Util.isStringType(simpleType, config);
                if (isStringType) {
                    parameters += ", " + lengthParaType + " " + lengthParaName;
                    streamFunctionName = Util.createSimpleValidationStreamFunctionName(functionName, config);

                    String stringListItemParameter = config.getStringListItemValidationFunctionParameter() + " "
                            + valueParaName;
                    printFunctionDeclaration(valiHeaderFile, simpleValiFuncReturnType, functionName,
                            stringListItemParameter);
                    printFunctionDefinitionHead(valiSourceFile, simpleValiFuncReturnType, null, functionName,
                            stringListItemParameter);
                    valiSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInSimpleValidationTemplate(
                            config.getTemplateSimpleValidationStringListItemImpl(), simpleType, config,
                            xsSimpleType2validationFunctionName), null, null, null, null, null, null, this));
                }
            }

            parameters = TemplateEngine.fillInTypeMappingTemplate(parameters, null, null, this);

            printFunctionDeclaration(valiHeaderFile, simpleValiFuncReturnType, functionName, parameters);
            printFunctionDefinitionHead(valiSourceFile, simpleValiFuncReturnType, null, functionName, parameters);
            printSimpleValidationFunctionImpl(valiSourceFile, simpleType, false, false);
            if (streamFunctionName != null) {
                printFunctionDeclaration(valiHeaderFile, simpleValiFuncReturnType, streamFunctionName, parameters);
                printFunctionDefinitionHead(valiSourceFile, simpleValiFuncReturnType, null, streamFunctionName,
                        parameters);
                printSimpleValidationFunctionImpl(valiSourceFile, simpleType, true, false);

                String streamEndFunctionName = Util.createSimpleValidationStreamEndFunctionName(functionName, config);
                printFunctionDeclaration(valiHeaderFile, simpleValiFuncReturnType, streamEndFunctionName, parameters);
                printFunctionDefinitionHead(valiSourceFile, simpleValiFuncReturnType, null, streamEndFunctionName,
                        parameters);
                printSimpleValidationFunctionImpl(valiSourceFile, simpleType, false, true);
            }
            valiHeaderFile.println();
        }
    }

    /**
     * Prints include files for generated source file.
     */
    protected void printSourceIncludes() {
        PrinterUtils.printIncludes(privateImplSourceFile, config.getIncludeFilesForImpl());
    }

    /**
     * Prints declarations of C++ string constants.
     * 
     * @param stream
     *            Stream to print to.
     * @param constantsCreator
     *            Object to get constants from.
     */
    protected void printStringConstantsDecls(PrintStream stream, CppConstantsCreator constantsCreator) {
        SortedMap<String, String> stringConstants = constantsCreator.getStringNameValueMap();
        for (Map.Entry<String, String> entry : stringConstants.entrySet()) {
            stream.println("extern " + createCppNameConstantType() + " " + entry.getKey() + ";");
        }
    }

    /**
     * Prints definitions of C++ string constants.
     * 
     * @param stream
     *            Stream to print to.
     * @param constantsCreator
     *            Object to get constants from.
     */
    protected void printStringConstantsDefis(PrintStream stream, CppConstantsCreator constantsCreator) {
        SortedMap<String, String> stringConstants = constantsCreator.getStringNameValueMap();
        for (Map.Entry<String, String> entry : stringConstants.entrySet()) {
            stream.println(createCppNameConstantType() + " " + entry.getKey() + " = " + entry.getValue() + ";");
        }
    }

    /**
     * Prints C++ union struct to given stream.
     * 
     * @param cppUnionTypeName
     *            C++ union type name
     * @param simpleType
     *            XSD union type.
     * @param stream
     *            Stream to print struct to.
     */
    protected void printUnion(String cppUnionTypeName, XSSimpleTypeDefinition simpleType, PrintStream stream) {
        stream.println("struct " + cppUnionTypeName);
        stream.println("{");

        // print c-tors
        String ctorInitList = ":" + config.getUnionTypeMemberName() + "(" + config.getUnionInvalidTypeName() + ")";
        stream.print(config.getIndentation());
        stream.println(cppUnionTypeName + "()" + ctorInitList + "{}");
        stream.print(config.getIndentation());
        stream.println(cppUnionTypeName + "( int value )" + ctorInitList + "{}");
        stream.println();

        stream.print(config.getIndentation());
        stream.println("enum Types");
        stream.print(config.getIndentation());
        stream.println("{");

        XSObjectList objectList = simpleType.getMemberTypes();
        List<XSSimpleTypeDefinition> memberTypes = Util.objectListToList(objectList);
        List<String> memberNames = new ArrayList<String>();
        for (XSSimpleTypeDefinition memberType : memberTypes) {
            stream.print(config.getIndentation());
            stream.print(config.getIndentation());
            String memberName = cppEnumOrUnionNameCreator.createUnionMemberTypeName(memberType, simpleType);
            stream.print(memberName);
            memberNames.add(memberName);
            stream.println(",");
        }
        stream.print(config.getIndentation());
        stream.print(config.getIndentation());
        stream.println(config.getUnionInvalidTypeName());
        stream.print(config.getIndentation());
        stream.println("} " + config.getUnionTypeMemberName() + ";");
        stream.println();

        stream.print(config.getIndentation());
        stream.println("union Data");
        stream.print(config.getIndentation());
        stream.println("{");
        // for (XSSimpleTypeDefinition memberType : memberTypes) {
        for (int i = 0; i < memberTypes.size(); i++) {
            XSSimpleTypeDefinition memberType = memberTypes.get(i);
            stream.print(config.getIndentation());
            stream.print(config.getIndentation());
            stream.print(findCorrectCppTypeAsUnionMember(simpleType, memberType));
            stream.print(" " + memberNames.get(i));
            stream.println(";");
        }
        stream.print(config.getIndentation());
        stream.println("} " + config.getUnionDataMemberName() + ";");

        stream.println("};");
        stream.println();
    }

    /**
     * Prints union specific convenience functions.
     * 
     * @param unionNameCreator
     *            Object able to create C++ name of union.
     * @param simpleType
     *            XSD type representing union.
     */
    protected void printUnionFunctions(CppEnumNameCreator unionNameCreator, XSSimpleTypeDefinition unionType) {
        // toUnion( const ParserChar* buffer, size_t length, bool& failed )
        enumHeaderFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInUnionTemplate(config
                .getTemplateUnionFuncToUnionDecl(), unionType, this), null, null, null, null, null, null, this));
        enumHeaderFile.println();
        enumHeaderFile.println();

        enumSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        enumSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInUnionTemplate(config
                .getTemplateUnionFuncToUnionImpl(), unionType, this), null, null, null, null, null, null, this));
        enumSourceFile.println();

        // toUnion( const ParserChar** buffer, const ParserChar* bufferEnd,
        // bool& failed )
        enumHeaderFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInUnionTemplate(config
                .getTemplateUnionFuncToUnionBufferEndPtrDecl(), unionType, this), null, null, null, null, null, null,
                this));
        enumHeaderFile.println();
        enumHeaderFile.println();

        enumSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        enumSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInUnionTemplate(config
                .getTemplateUnionFuncToUnionBufferEndPtrImpl(), unionType, this), null, null, null, null, null, null,
                this));
        enumSourceFile.println();

        // toUnion( const ParserChar** buffer, bool& failed )
        enumHeaderFile.println(TemplateEngine
                .fillInTemplate(TemplateEngine.fillInUnionTemplate(config.getTemplateUnionFuncToUnionNullTermiDecl(),
                        unionType, this), null, null, null, null, null, null, this));
        enumHeaderFile.println();
        enumHeaderFile.println();

        enumSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        enumSourceFile.println(TemplateEngine
                .fillInTemplate(TemplateEngine.fillInUnionTemplate(config.getTemplateUnionFuncToUnionNullTermiImpl(),
                        unionType, this), null, null, null, null, null, null, this));
        enumSourceFile.println();

        // toEnumDataPrefix
        privateImplHeaderFile.println();
        privateImplHeaderFile.println();
        privateImplHeaderFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInUnionTemplate(config
                .getTemplateUnionFuncDataPrefixDecl(), unionType, this), null, null, null, null, null, null, this));
        privateImplHeaderFile.println();

        privateImplSourceFile.println(config.getOutputSourceFileMethodDelimiter());
        privateImplSourceFile.println(TemplateEngine.fillInTemplate(TemplateEngine.fillInUnionTemplate(config
                .getTemplateUnionFuncDataPrefixImpl(), unionType, this), null, null, null, null, null, null, this));
        privateImplSourceFile.println();
    }

    /**
     * Prints declaration of validateBegin method to C++ header.
     * 
     * @param cppName
     *            C++ name of element to validate.
     */
    protected void printValidateBeginHeaderDecl(String cppName) {
        printValidateBeginReturnType(privateImplHeaderFile);
        privateImplHeaderFile.print(" ");
        privateImplHeaderFile.print(Util.createValidateBeginMethodName(cppName));
        printValidateBeginParameterList(privateImplHeaderFile);
        privateImplHeaderFile.println(";");
    }

    /**
     * Prints implementation of validateBegin method to C++ source file.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppName
     *            C++ name of element to validate.
     * @param element
     *            XSD representation of element.
     * @param attrs
     *            Attributes of element.
     * @param complexType
     *            Complex XSD Type of this element or null.
     */
    protected void printValidateBeginImpl(PrintStream stream, String cppName, XSElementDeclaration element,
            List<XSAttributeUse> attrs, XSComplexTypeDefinition complexType) {
        stream.println(config.getOutputSourceFileMethodDelimiter());
        printValidateBeginReturnType(stream);
        stream.print(" ");
        stream.print(config.getClassNamePrivate());
        stream.print("::");
        stream.print(Util.createValidateBeginMethodName(cppName));
        printValidateBeginParameterList(stream);
        stream.println();
        stream.println("{");

        // TODO no validation block
        boolean validationBlockOpened = false;
        SortedSet<XSTypeDefinition> parentTypes = elementNameMapping.get(element).parentTypes;
        if (parentTypes != null && !parentTypes.isEmpty()) {
            SortedSet<XSComplexTypeDefinition> complexParentTypes = new TreeSet<XSComplexTypeDefinition>(
                    new XSTypeComparator());
            for (XSTypeDefinition parentType : parentTypes) {
                if (parentType instanceof XSComplexTypeDefinition) {
                    complexParentTypes.add((XSComplexTypeDefinition) parentType);
                }
            }
            if (complexParentTypes.size() == 1) {
                XSComplexTypeDefinition parentType = complexParentTypes.iterator().next();
                printComplexValidationBlockOpen(stream);
                validationBlockOpened = true;

                printComplexValidationForSingleParent(stream, cppName, element, parentType);
            } else if (!complexParentTypes.isEmpty()) {
                printComplexValidationBlockOpen(stream);
                validationBlockOpened = true;

                stream.print(config.getIndentation());
                stream.print(config.getIndentation());
                stream.println("switch ( mElementDataStack.back().typeID )");
                stream.print(config.getIndentation());
                stream.print(config.getIndentation());
                stream.println("{");
                String typeId = null;
                for (XSComplexTypeDefinition parentType : complexParentTypes) {
                    stream.print(config.getIndentation());
                    stream.print(config.getIndentation());
                    typeId = typeIdMapping.get(parentType);
                    stream.println("case " + typeId + ":");
                    stream.print(config.getIndentation());
                    stream.print(config.getIndentation());
                    stream.println("{");
                    printComplexValidationForSingleParent(stream, cppName, element, parentType);
                    stream.print(config.getIndentation());
                    stream.print(config.getIndentation());
                    stream.println("break;");
                    stream.print(config.getIndentation());
                    stream.print(config.getIndentation());
                    stream.println("}");
                    stream.println();
                }
                stream.print(config.getIndentation());
                stream.print(config.getIndentation());
                stream.println("default:");
                stream.print(config.getIndentation());
                stream.print(config.getIndentation());
                stream.print(config.getIndentation());
                // TODO validation per parent default branch.
                stream.println("// TODO we could throw some error here");
                stream.print(config.getIndentation());
                stream.print(config.getIndentation());
                stream.print(config.getIndentation());
                stream.println("break;");
                stream.print(config.getIndentation());
                stream.print(config.getIndentation());
                stream.println("}");
            }
        }

        boolean simpleTypeStreamValidationRequired = false;
        XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(element.getTypeDefinition());
        if (simpleType != null) {
            if (Util.hasStreamingFacets(simpleType)) {
                simpleTypeStreamValidationRequired = true;
            }
        }
        if (Util.mayHaveChildElements(complexType, config) || simpleTypeStreamValidationRequired) {
            if (!validationBlockOpened) {
                printComplexValidationBlockOpen(stream);
                validationBlockOpened = true;
            }
            String structName = xsType2validationDataStructName.get(element.getTypeDefinition());
            printComplexValidationDataStructCreation(stream, cppName, structName, complexType, element);

            StateMachineRootNode sm = stateMachineMap.get(complexType);
            if (sm != null) {
                stream.print(TemplateEngine.fillInTemplate(TemplateEngine.fillInComplexValidationTemplate(config
                        .getTemplateComplexValidationInitStateMachine(), cppName, structName, complexType, element, sm,
                        this), cppName, null, null, null, null, null, this));
            }

            stream.println();
            stream.println();
        }
        if (validationBlockOpened) {
            printComplexValidationBlockClose(stream);
        }

        stream.print(config.getIndentation());
        stream.println("return true;");

        stream.println("}");
        stream.println();
    }

    /**
     * Prints parameter list of validateBegin method to given stream (including
     * parenthesis).
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printValidateBeginParameterList(PrintStream stream) {
        stream.print("( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )");
    }

    /**
     * Prints parameter list of validateBegin method when called to given stream
     * (including parenthesis).
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printValidateBeginParameterListForCall(PrintStream stream) {
        stream.print("( attributes, attributeDataPtr, validationDataPtr )");
    }

    /**
     * Prints return type of validateBegin method to given stream.
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printValidateBeginReturnType(PrintStream stream) {
        stream.print("bool");
    }

    /**
     * Prints declaration of validateEnd method to C++ header.
     * 
     * @param cppName
     *            C++ name of element to validate.
     */
    protected void printValidateEndHeaderDecl(String cppName) {
        printValidateEndReturnType(privateImplHeaderFile);
        privateImplHeaderFile.print(" ");
        privateImplHeaderFile.print(Util.createValidateEndMethodName(cppName));
        printValidateEndParameterList(privateImplHeaderFile);
        privateImplHeaderFile.println(";");
    }

    /**
     * Prints implementation of validateEnd method to C++ source file.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppName
     *            C++ name of element to validate.
     * @param element
     *            XSD representation of element.
     * @param hasChardata
     *            Indicates if DataEnd() must be called.
     * @param typeDefinition
     *            Type of this element.
     */
    protected void printValidateEndImpl(PrintStream stream, String cppName, XSElementDeclaration element,
            boolean hasChardata, XSTypeDefinition typeDefinition) {
        stream.println(config.getOutputSourceFileMethodDelimiter());
        printValidateEndReturnType(stream);
        stream.print(" ");
        stream.print(config.getClassNamePrivate());
        stream.print("::");
        stream.print(Util.createValidateEndMethodName(cppName));
        printValidateEndParameterList(stream);
        stream.println();
        stream.println("{");

        // TODO no vali block

        XSComplexTypeDefinition complexType = null;
        XSSimpleTypeDefinition simpleType = null;
        if (typeDefinition instanceof XSComplexTypeDefinition) {
            complexType = (XSComplexTypeDefinition) typeDefinition;
        } else if (typeDefinition instanceof XSSimpleTypeDefinition) {
            simpleType = (XSSimpleTypeDefinition) typeDefinition;
        }
        Variety variety = Util.findVariety(simpleType);
        if (Util.mayHaveChildElements(complexType, config) || Util.hasStreamingFacets(simpleType)
                && variety == Variety.ATOMIC) {
            printComplexValidationBlockOpen(stream);

            String valiDataStrucName = xsType2validationDataStructName.get(typeDefinition);

            String tmpl = null;
            StateMachineRootNode sm = stateMachineMap.get(complexType);
            if (sm == null) {
                tmpl = config.getTemplateComplexValidationParentValidateEnd();
            } else {
                tmpl = config.getTemplateComplexValidationParentValidateEndNestedModelGroups();
            }
            stream
                    .println(TemplateEngine.fillInTemplate(TemplateEngine.fillInComplexValidationTemplate(tmpl,
                            cppName, valiDataStrucName, complexType, element, sm, this), cppName, element, null, null,
                            null, null, this));

            if (Util.hasStreamingFacets(simpleType) && variety == Variety.ATOMIC && !Util.hasFacetEnum(simpleType)) {
                simpleType = Util.findSimpleTypeDefinition(typeDefinition);
                String xsdType = Util.findXSDSimpleTypeString(simpleType, config);
                String cppValidateEnd = config.getTypeMapping().get(xsdType).getDataAtomicValidateEndImpl();
                String simpleTypeValiTmpl = null;
                if (Util.isNumericType(simpleType, config)) {
                    simpleTypeValiTmpl = config.getTemplateSimpleValidationNumericAtomicData();
                } else {
                    simpleTypeValiTmpl = config.getTemplateSimpleValidationStringAtomicDataEnd();
                }
                simpleTypeValiTmpl = TemplateEngine.prepareSimpleTypeValidationTemplate(simpleTypeValiTmpl, simpleType,
                        cppName, element, this);
                if (cppValidateEnd == null) {
                    cppValidateEnd = simpleTypeValiTmpl;
                }
                stream.println(TemplateEngine.fillInTemplate(cppValidateEnd, cppName, element, null,
                        createDataConvenienceMethodName(cppName), typeDefinition, simpleTypeValiTmpl, this));
            }

            printComplexValidationDataStructDeletion(stream, cppName, valiDataStrucName, complexType, element);
            stream.println();

            printComplexValidationBlockClose(stream);
        }

        stream.print(config.getIndentation());
        stream.println("return true;");

        stream.println("}");
        stream.println();
    }

    /**
     * Prints parameter list of validateEnd method to given stream (including
     * parenthesis).
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printValidateEndParameterList(PrintStream stream) {
        stream.print("()");
    }

    /**
     * Prints return type of validateEnd method to given stream.
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printValidateEndReturnType(PrintStream stream) {
        stream.print("bool");
    }

    /**
     * Prints first content of validation data structs header file:
     */
    protected void printValidationDataHeaderFileBeginning() {
        valiHeaderFile.println(config.getOutFileHeader());
        valiHeaderFile.println();
        valiHeaderFile.println();
        PrinterUtils.printIncludeProtection(valiHeaderFile, PrinterUtils.createIncludeProtectionMacro(config
                .getNamespace(), config.getClassNamePublic() + config.getOutputValidationDataFileSuffix()));
        valiHeaderFile.println();
        valiHeaderFile.println();

        PrinterUtils.printNamespaceOpen(valiHeaderFile, config.getNamespace());
        valiHeaderFile.println();
        valiHeaderFile.println();
    }

    /**
     * Prints ending of validation data structs C++ header file.
     */
    protected void printValidationDataHeaderFileEnd() {
        valiHeaderFile.println();
        valiHeaderFile.println();
        PrinterUtils.printNamespaceClose(valiHeaderFile, config);

        valiHeaderFile.println("#endif");
    }

    /**
     * Prints beginning of generated C++ validation source file.
     */
    protected void printValidationSourceFileBeginning() {
        valiSourceFile.println(config.getOutFileHeader());
        List<String> includes = new ArrayList<String>();
        includes.add(config.getIncludePrecompiledHeader());
        PrinterUtils.printIncludes(valiSourceFile, includes);
        PrinterUtils.printIncludeGeneratedHeader(valiSourceFile, config.getOutputHeaderFileNamePrivate());
        valiSourceFile.println();
        valiSourceFile.println();

        valiSourceFile.println(TemplateEngine.fillInTemplate(config.getTemplateDisableWarningUnused(), null, null,
                null, null, null, null, this));
        valiSourceFile.println();
        valiSourceFile.println();

        PrinterUtils.printNamespaceOpen(valiSourceFile, config.getNamespace());
        valiSourceFile.println();
        valiSourceFile.println();
        printComplexValidationBlockOpenCompileTimeOnly(valiSourceFile);
        valiSourceFile.println();
        valiSourceFile.println();
        printPcreOVECCOUNT(valiSourceFile);
        valiSourceFile.println();
    }

    /**
     * Prints end of generated C++ validation source file.
     */
    protected void printValidationSourceFileEnd() {
        printComplexValidationBlockCloseCompileTimeOnly(valiSourceFile);
        PrinterUtils.printNamespaceClose(valiSourceFile, config);
    }

    /**
     * Prints header declaration of isXsAnyAllowed method.
     */
    protected void printXsAnyAllowedHeaderDecl() {
        privateImplHeaderFile.println("virtual bool " + "isXsAnyAllowed" + "( const StringHash& elementHash );");
    }

    /**
     * Prints begin of implementation of isXsAnyAllowed().
     */
    protected void printXsAnyAllowedImplStart() {
        findElementHashFile.println(config.getOutputSourceFileMethodDelimiter());
        String elementHashVariableName = "elementHash";
        findElementHashFile.println("bool " + config.getClassNamePrivate() + "::" + "isXsAnyAllowed"
                + "( const StringHash& " + elementHashVariableName + " )");
        findElementHashFile.println("{");

        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("if ( mElementDataStack.empty() )");
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("return false;");
        findElementHashFile.println();
    }

    /**
     * Prints big switch in isXsAnyAllowed method (main part of that method's
     * impl). Prints closing bracket of that method as well.
     */
    protected void printXsAnyAllowedImplSwitch() {
        if (!elementsWithXsAny.isEmpty()) {
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("switch ( elementHash )");
            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("{");

            for (XSElementDeclaration element : elementsWithXsAny) {
                ElementUsage elementUsage = completeElementUsage.get(element.getName());
                SortedSet<XSElementDeclaration> parents = elementUsage.collectParents(element);
                if (parents == null || parents.isEmpty()) {
                    continue;
                }

                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                String cppElementName = elementNameMapping.get(element).cppElementName;
                findElementHashFile.println("case " + Util.createElementNameHashIdentifier(cppElementName) + ":");

                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.println("switch ( mElementDataStack.back().typeID )");
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.println("{");

                Set<String> printedTypes = new HashSet<String>();
                for (XSElementDeclaration parent : parents) {
                    String parentTypeID = typeIdMapping.get(parent.getTypeDefinition());
                    if (!printedTypes.contains(parentTypeID)) {
                        findElementHashFile.print(config.getIndentation());
                        findElementHashFile.print(config.getIndentation());
                        findElementHashFile.print(config.getIndentation());
                        findElementHashFile.println("case " + parentTypeID + ":");
                        printedTypes.add(parentTypeID);

                        findElementHashFile.print(config.getIndentation());
                        findElementHashFile.print(config.getIndentation());
                        findElementHashFile.print(config.getIndentation());
                        findElementHashFile.print(config.getIndentation());
                        findElementHashFile.println("return true;");
                    }
                }
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.println("default:");
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.println("return false;");

                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.print(config.getIndentation());
                findElementHashFile.println("}"); // inner switch
            }

            findElementHashFile.print(config.getIndentation());
            findElementHashFile.println("}"); // switch
        }
        findElementHashFile.print(config.getIndentation());
        findElementHashFile.println("return false;");

        findElementHashFile.println("}"); // method
        findElementHashFile.println();
    }

}
