/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.printers;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.SortedMap;
import java.util.TreeMap;

import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSSimpleTypeDefinition;

import de.netallied.xsd2cppsax.IGenerationDataProvider;

/**
 * Prints an empty example implementation of the generated parser.
 * 
 */
public class ExampleParserPrinter extends AbstractParserImplementationPrinter {

    /** Generated example C++ header file. */
    private PrintStream exampleHeaderFile;

    /** Generated example C++ source file. */
    private PrintStream exampleSourceFile;

    /**
     * C-tor.
     * 
     */
    public ExampleParserPrinter(IGenerationDataProvider dataProvider) {
        super(dataProvider);
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#cleanupOutputFiles()
     */
    public void cleanupOutputFiles() {
        if (exampleHeaderFile != null) {
            printHeaderFileEnd();
            exampleHeaderFile.close();
        }
        if (exampleSourceFile != null) {
            printSourceFileEnd();
            exampleSourceFile.close();
        }
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getAdditionalBaseClasses()
     */
    @Override
    protected List<String> getAdditionalBaseClasses() {
        return null;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getClassName()
     */
    @Override
    protected String getClassName() {
        return getConfig().getExampleClassName();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getCtorParas()
     */
    @Override
    protected String getCtorParas() {
        return null;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getCtorTmpl()
     */
    @Override
    protected String getCtorTmpl() {
        return null;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getDtorTmpl()
     */
    @Override
    protected String getDtorTmpl() {
        return null;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getHeaderFile()
     */
    @Override
    protected PrintStream getHeaderFile() {
        return exampleHeaderFile;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getHeaderFileName()
     */
    @Override
    protected String getHeaderFileName() {
        return getConfig().getOutputExampleHeaderFileName();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getIncludeFiles()
     */
    @Override
    protected List<String> getIncludeFiles() {
        return new ArrayList<String>();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getInitializationList()
     */
    @Override
    protected List<String> getInitializationList() {
        return new ArrayList<String>();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getMembers()
     */
    @Override
    protected SortedMap<String, String> getMembers() {
        return new TreeMap<String, String>();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getNamespace()
     */
    @Override
    protected String getNamespace() {
        return getConfig().getExampleNamespace();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getSourceFile()
     */
    @Override
    protected PrintStream getSourceFile() {
        return exampleSourceFile;
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
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#printBeginMethodImpl(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    @Override
    protected void printBeginMethodImpl(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element, boolean attributesRequired) {
        PrinterUtils.printBeginConvenienceMethodDefaultImpl(getSourceFile(), true, getConfig());
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
        PrinterUtils.printDataConvenienceMethodDefaultImpl(getSourceFile(), true, getConfig());
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
        PrinterUtils.printEndMethodDefaultImpl(getSourceFile(), true, getConfig());
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#setupOutputFiles()
     */
    public void setupOutputFiles() throws FileNotFoundException {
        exampleHeaderFile = new PrintStream(getConfig().getOutputExampleHeaderFileName());
        printHeaderFileBeginning();
        exampleSourceFile = new PrintStream(getConfig().getOutputExampleSourceFileName());
        printSourceFileBeginning();
    }
}
