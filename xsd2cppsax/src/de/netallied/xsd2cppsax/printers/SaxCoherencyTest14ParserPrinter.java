XXXXXAAAAAXXXXX
package de.netallied.xsd2cppsax.printers;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.SortedMap;
import java.util.TreeMap;

import org.apache.xerces.xs.XSAttributeUse;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSSimpleTypeDefinition;

import de.netallied.xsd2cppsax.IGenerationDataProvider;
import de.netallied.xsd2cppsax.TemplateEngine;
import de.netallied.xsd2cppsax.Util;
import de.netallied.xsd2cppsax.Variety;

/**
 * Prints a specialized Parser for coherence testing of COLLADA 1.4 documents.
 * 
 */
public class SaxCoherencyTest14ParserPrinter extends AbstractParserImplementationPrinter {

    /** Name of C++ count attribute member. */
    private String countAttributeName;

    /** Name of C++ error handler. */
    private String errorHandlerName;

    /** Generated example C++ header file. */
    private PrintStream headerFile;

    /** Name of C++ ID counter map. */
    private String idCounterMapName;

    /** Name of C++ list count member. */
    private String listCountName;

    /** Generated example C++ source file. */
    private PrintStream sourceFile;

    /**
     * C-tor.
     * 
     * @param dataProvider
     *            {@link IGenerationDataProvider} to be used.
     */
    public SaxCoherencyTest14ParserPrinter(IGenerationDataProvider dataProvider) {
        super(dataProvider);
        errorHandlerName = getConfig().getCoherencyTestErrorHandlerName();
        idCounterMapName = getConfig().getCoherencyTestIdCounterMapName();
        countAttributeName = getConfig().getCoherencyTestCountAttributeMemberName();
        listCountName = getConfig().getCoherencyTestListCountMemberName();
    }

    /**
     * Prints begin-method test which compares count attribute and list length.
     * 
     */
    protected void checkCountSimpleBegin(String cppElementName, XSElementDeclaration element) {
        List<XSAttributeUse> attributeUses = Util.collectAttributeUses(element);
        for (XSAttributeUse attrUse : attributeUses) {
            String attributeName = Util.getAttributeName(attrUse, getConfig());
            if (attributeName.equals("count")) {
                String cppCode = getConfig().getTemplateCoherencyTestSimpleCountCheckBegin();
                cppCode = TemplateEngine.fillInCoherencyTestTemplate(cppCode, getGenerationDataProvider());
                cppCode = TemplateEngine.fillInTemplate(cppCode, cppElementName, element, attrUse, null, null, null,
                        getGenerationDataProvider());
                sourceFile.println(cppCode);
                break;
            }
        }
    }

    /**
     * Prints data-method test which compares count attribute and list length.
     * 
     */
    protected void checkCountSimpleData(String cppElementName, XSElementDeclaration element) {
        List<XSAttributeUse> attributeUses = Util.collectAttributeUses(element);
        for (XSAttributeUse attrUse : attributeUses) {
            String attributeName = Util.getAttributeName(attrUse, getConfig());
            if (attributeName.equals("count")) {
                String cppCode = getConfig().getTemplateCoherencyTestSimpleCountCheckData();
                cppCode = TemplateEngine.fillInCoherencyTestTemplate(cppCode, getGenerationDataProvider());
                cppCode = TemplateEngine.fillInTemplate(cppCode, cppElementName, element, attrUse, null, null, null,
                        getGenerationDataProvider());
                sourceFile.println(cppCode);
                break;
            }
        }
    }

    /**
     * Prints end-method test which compares count attribute and list length.
     * 
     */
    protected void checkCountSimpleEnd(String cppElementName, XSElementDeclaration element) {
        List<XSAttributeUse> attributeUses = Util.collectAttributeUses(element);
        for (XSAttributeUse attrUse : attributeUses) {
            String attributeName = Util.getAttributeName(attrUse, getConfig());
            if (attributeName.equals("count")) {
                String cppCode = getConfig().getTemplateCoherencyTestSimpleCountCheckEnd();
                cppCode = TemplateEngine.fillInCoherencyTestTemplate(cppCode, getGenerationDataProvider());
                cppCode = TemplateEngine.fillInTemplate(cppCode, cppElementName, element, attrUse, null, null, null,
                        getGenerationDataProvider());
                sourceFile.println(cppCode);
                break;
            }
        }
    }

    /**
     * Prints test which checks for unique IDs.
     * 
     */
    protected void checkIdUnique(String cppElementName, XSElementDeclaration element) {
        List<XSAttributeUse> attributeUses = Util.collectAttributeUses(element);
        for (XSAttributeUse attrUse : attributeUses) {
            String attributeName = Util.getAttributeName(attrUse, getConfig());
            if (attributeName.toLowerCase().equals("id")) {
                String cppCode = getConfig().getTemplateCoherencyTestCheckIdUnique();
                cppCode = TemplateEngine.fillInCoherencyTestTemplate(cppCode, getGenerationDataProvider());
                cppCode = TemplateEngine.fillInTemplate(cppCode, cppElementName, element, attrUse, null, null, null,
                        getGenerationDataProvider());
                sourceFile.println(cppCode);
                break;
            }
        }
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#cleanupOutputFiles()
     */
    public void cleanupOutputFiles() {
        if (headerFile != null) {
            printHeaderFileEnd();
            headerFile.close();
        }
        if (sourceFile != null) {
            printSourceFileEnd();
            sourceFile.close();
        }
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getAdditionalBaseClasses()
     */
    @Override
    protected List<String> getAdditionalBaseClasses() {
        return new ArrayList<String>();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getClassName()
     */
    @Override
    protected String getClassName() {
        return getConfig().getCoherencyTestParserClassName();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getCtorParas()
     */
    @Override
    protected String getCtorParas() {
        return getConfig().getCoherencyTestCtorParas();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getCtorTmpl()
     */
    @Override
    protected String getCtorTmpl() {
        return new String();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getDtorTmpl()
     */
    @Override
    protected String getDtorTmpl() {
        return new String();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getHeaderFile()
     */
    @Override
    protected PrintStream getHeaderFile() {
        return headerFile;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getHeaderFileName()
     */
    @Override
    protected String getHeaderFileName() {
        return getConfig().getOutputCoherencyTestHeaderFileName();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getIncludeFiles()
     */
    @Override
    protected List<String> getIncludeFiles() {
        List<String> incs = new ArrayList<String>();
        incs.add("CoherencyTestErrorHandler.h");
        incs.add("map");
        return incs;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getInitializationList()
     */
    @Override
    protected List<String> getInitializationList() {
        return getConfig().getCoherencyTestInitializationList();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getMembers()
     */
    @Override
    protected SortedMap<String, String> getMembers() {
        SortedMap<String, String> members = new TreeMap<String, String>();
        members.put(errorHandlerName, "CoherencyTestErrorHandler*");
        members.put(idCounterMapName, "IDCounterMap");
        members.put(countAttributeName, "uint64");
        members.put(listCountName, "uint64");
        return members;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getNamespace()
     */
    @Override
    protected String getNamespace() {
        return getConfig().getCoherencyTestParserNamespace();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getSourceFile()
     */
    @Override
    protected PrintStream getSourceFile() {
        return sourceFile;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#handleEnum(java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSSimpleTypeDefinition)
     */
    public void handleEnum(String cppEnumTypeName, XSSimpleTypeDefinition simpleType) {
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#handleUnion(java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSSimpleTypeDefinition)
     */
    public void handleUnion(String cppUnionTypeName, XSSimpleTypeDefinition simpleType) {
    }

    /**
     * Indicates if it is necessary to print simple count check of given
     * element. That check tests if count attribute and list length are the
     * same.
     */
    protected boolean isSimpleCountCheckRequired(XSElementDeclaration element) {
        List<XSAttributeUse> attributeUses = Util.collectAttributeUses(element);
        boolean countAttrPresent = false;
        for (XSAttributeUse attrUse : attributeUses) {
            String attributeName = Util.getAttributeName(attrUse, getConfig());
            if (attributeName.equals("count")) {
                countAttrPresent = true;
                break;
            }
        }
        if (countAttrPresent) {
            XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(element.getTypeDefinition());
            if (simpleType != null) {
                Variety variety = Util.findVariety(simpleType);
                if (variety == Variety.LIST) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#printBeginMethodImpl(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration, boolean)
     */
    @Override
    protected void printBeginMethodImpl(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element, boolean attributesRequired) {

        sourceFile.println("{");

        if (attributesRequired) {
            checkIdUnique(cppElementName, element);
            if (isSimpleCountCheckRequired(element)) {
                checkCountSimpleBegin(cppElementName, element);
            }
        }

        sourceFile.print(getConfig().getIndentation());
        sourceFile.println("return true;");
        sourceFile.print("}");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#printDataMethodImpl(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    @Override
    protected void printDataMethodImpl(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element) {

        sourceFile.println("{");

        if (isSimpleCountCheckRequired(element)) {
            checkCountSimpleData(cppElementName, element);
        }

        sourceFile.print(getConfig().getIndentation());
        sourceFile.println("return true;");
        sourceFile.print("}");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#printEndMethodImpl(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    @Override
    protected void printEndMethodImpl(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element) {

        sourceFile.println("{");

        if (isSimpleCountCheckRequired(element)) {
            checkCountSimpleEnd(cppElementName, element);
        }

        sourceFile.print(getConfig().getIndentation());
        sourceFile.println("return true;");
        sourceFile.print("}");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#printHeaderFileBeginning()
     */
    @Override
    public void printHeaderFileBeginning() {
        super.printHeaderFileBeginning();

        getHeaderFile().println("typedef std::map<String, size_t> IDCounterMap;");
        getHeaderFile().println();
        getHeaderFile().println();
        getHeaderFile().println();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#setupOutputFiles()
     */
    public void setupOutputFiles() throws FileNotFoundException {
        headerFile = new PrintStream(getConfig().getOutputCoherencyTestHeaderFileName());
        printHeaderFileBeginning();
        sourceFile = new PrintStream(getConfig().getOutputCoherencyTestSourceFileName());
        printSourceFileBeginning();
    }

}
