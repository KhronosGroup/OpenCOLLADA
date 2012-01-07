XXXXXAAAAAXXXXX
package de.netallied.xsd2cppsax.printers;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;

import org.apache.xerces.xs.XSElementDeclaration;

import de.netallied.xsd2cppsax.Config;
import de.netallied.xsd2cppsax.IGenerationDataProvider;

/**
 * Abstract base class which prints an implementation of the generated parser.
 * 
 */
public abstract class AbstractParserImplementationPrinter implements ICodePrinter {

    /** {@link IGenerationDataProvider} */
    private IGenerationDataProvider dataProvider;

    /**
     * C-tor.
     * 
     */
    public AbstractParserImplementationPrinter(IGenerationDataProvider dataProvider) {
        this.dataProvider = dataProvider;
    }

    /**
     * @return List of additional base classes of printed parser.
     */
    protected abstract List<String> getAdditionalBaseClasses();

    /**
     * @return Class name of printed parser.
     */
    protected abstract String getClassName();

    /**
     * @return Configuration.
     */
    public Config getConfig() {
        return dataProvider.getConfig();
    }

    /**
     * @return Parameters for constructor.
     */
    abstract protected String getCtorParas();

    /**
     * @return Code template for C++ constructor.
     */
    abstract protected String getCtorTmpl();

    /**
     * @return Code template for C++ destructor.
     */
    abstract protected String getDtorTmpl();

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#getGenerationDataProvider()
     */
    public IGenerationDataProvider getGenerationDataProvider() {
        return dataProvider;
    }

    /**
     * @return C++ header file to print to.
     */
    protected abstract PrintStream getHeaderFile();

    /**
     * @return C++ header file name. For include in cpp file.
     */
    protected abstract String getHeaderFileName();

    /**
     * @return List of include files printed parser requires.
     */
    protected abstract List<String> getIncludeFiles();

    /**
     * @return C++ c-tor initialization list.
     */
    abstract protected List<String> getInitializationList();

    /**
     * @return A map of class member. Key is member name, value is member type.
     */
    abstract protected SortedMap<String, String> getMembers();

    /**
     * @return C++ namespace of printed parser.
     */
    protected abstract String getNamespace();

    /**
     * @return C++ source file to print to.
     */
    protected abstract PrintStream getSourceFile();

    /**
     * Prints implementation of SAX begin element method. Method head is printed
     * before.
     * 
     * @param methodName
     *            C++ method name.
     * @param parameterList
     *            C++ method parameters.
     * @param cppElementName
     *            C++ name of element.
     * @param element
     *            XSD element.
     * @param attributesRequired
     *            Indicates if element has attributes.
     */
    protected abstract void printBeginMethodImpl(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element, boolean attributesRequired);

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printBeginMethodToHeader(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration, boolean)
     */
    public void printBeginMethodToHeader(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element, boolean attributesRequired) {
        PrinterUtils.printBeginConvenienceMethodDeclTypeModifiers(getHeaderFile());
        getHeaderFile().print(" ");
        PrinterUtils.printBeginConvenienceMethodReturnType(getHeaderFile());
        getHeaderFile().print(" ");
        getHeaderFile().print(methodName);
        getHeaderFile().print(parameterList);
        getHeaderFile().println(";");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printBeginMethodToSource(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration, boolean)
     */
    public void printBeginMethodToSource(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element, boolean attributesRequired) {
        getSourceFile().println(getConfig().getOutputSourceFileMethodDelimiter());
        PrinterUtils.printBeginConvenienceMethodReturnType(getSourceFile());
        getSourceFile().print(" ");
        getSourceFile().print(getClassName() + "::");
        getSourceFile().print(methodName);
        getSourceFile().println(parameterList);

        printBeginMethodImpl(methodName, parameterList, cppElementName, element, attributesRequired);

        getSourceFile().println();
        getSourceFile().println();
    }

    /**
     * Prints implementation of SAX data method. Method head is printed before.
     * 
     * @param methodName
     *            C++ method name.
     * @param parameterList
     *            C++ method parameters.
     * @param cppElementName
     *            C++ name of element.
     * @param element
     *            XSD element.
     */
    protected abstract void printDataMethodImpl(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element);

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printDataMethodToHeader(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    public void printDataMethodToHeader(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element) {
        PrinterUtils.printDataConvenienceMethodDeclTypeModifiers(getHeaderFile());
        getHeaderFile().print(" ");
        PrinterUtils.printDataConvenienceMethodReturnType(getHeaderFile());
        getHeaderFile().print(" ");
        getHeaderFile().print(methodName);
        getHeaderFile().print(parameterList);
        getHeaderFile().println(";");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printDataMethodToSource(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    public void printDataMethodToSource(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element) {
        getSourceFile().println(getConfig().getOutputSourceFileMethodDelimiter());
        PrinterUtils.printDataConvenienceMethodReturnType(getSourceFile());
        getSourceFile().print(" ");
        getSourceFile().print(getClassName() + "::");
        getSourceFile().print(methodName);
        getSourceFile().println(parameterList);

        printDataMethodImpl(methodName, parameterList, cppElementName, element);

        getSourceFile().println();
        getSourceFile().println();
    }

    /**
     * Prints implementation of SAX end element method. Method head is printed
     * before.
     * 
     * @param methodName
     *            C++ method name.
     * @param parameterList
     *            C++ method parameters.
     * @param cppElementName
     *            C++ name of element.
     * @param element
     *            XSD element.
     */
    protected abstract void printEndMethodImpl(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element);

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printEndMethodToHeader(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    public void printEndMethodToHeader(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element) {
        PrinterUtils.printEndMethodDeclTypeModifiers(getHeaderFile());
        getHeaderFile().print(" ");
        PrinterUtils.printEndMethodReturnType(getHeaderFile());
        getHeaderFile().print(" ");
        getHeaderFile().print(methodName);
        getHeaderFile().print(parameterList);
        getHeaderFile().println(";");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printEndMethodToSource(java.lang.String,
     *      java.lang.String, java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    public void printEndMethodToSource(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element) {
        getSourceFile().println(getConfig().getOutputSourceFileMethodDelimiter());
        PrinterUtils.printEndMethodReturnType(getSourceFile());
        getSourceFile().print(" ");
        getSourceFile().print(getClassName() + "::");
        getSourceFile().print(methodName);
        getSourceFile().println(parameterList);

        printEndMethodImpl(methodName, parameterList, cppElementName, element);

        getSourceFile().println();
        getSourceFile().println();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printHeaderFileBeginning()
     */
    public void printHeaderFileBeginning() {
        getHeaderFile().println(getConfig().getOutFileHeader());
        getHeaderFile().println();
        getHeaderFile().println();
        String namespace = getNamespace();
        String className = getClassName();
        PrinterUtils.printIncludeProtection(getHeaderFile(), PrinterUtils.createIncludeProtectionMacro(namespace,
                className));
        getHeaderFile().println();
        getHeaderFile().println();
        PrinterUtils.printIncludeGeneratedHeader(getHeaderFile(), getConfig().getOutputAttributesFileName());
        PrinterUtils.printIncludeGeneratedHeader(getHeaderFile(), getConfig().getOutputHeaderFileNamePublic());
        PrinterUtils.printIncludes(getHeaderFile(), getIncludeFiles());
        getHeaderFile().println();
        getHeaderFile().println();

        getHeaderFile().println("using namespace " + getConfig().getNamespace() + ";");
        getHeaderFile().println();
        getHeaderFile().println();

        PrinterUtils.printNamespaceOpen(getHeaderFile(), namespace);
        getHeaderFile().println();

        PrinterUtils.printConvenienceTypedefs(getHeaderFile(), false, getConfig());
        getHeaderFile().println();
        getHeaderFile().println();

        getHeaderFile().print("class " + className);
        getHeaderFile().print(" : public " + getConfig().getNamespace() + "::" + getConfig().getClassNamePublic());
        List<String> baseClasses = getAdditionalBaseClasses();
        if (baseClasses != null) {
            for (String baseClass : baseClasses) {
                getHeaderFile().print(", " + baseClass);
            }
        }
        getHeaderFile().println();
        getHeaderFile().println("{");

        getHeaderFile().println("public:");
        PrinterUtils.printCtorDtorHeaderDecl(getHeaderFile(), className, false, false, getCtorParas(), getConfig());
        getHeaderFile().println();
        getHeaderFile().println();

    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printHeaderFileEnd()
     */
    public void printHeaderFileEnd() {
        getHeaderFile().println();
        getHeaderFile().println();
        getHeaderFile().println("private:");
        PrinterUtils.printDisableDefaultMethods(getHeaderFile(), getClassName());
        getHeaderFile().println();

        SortedMap<String, String> members = getMembers();
        for (Map.Entry<String, String> entry : members.entrySet()) {
            getHeaderFile().print(entry.getValue() + " ");
            getHeaderFile().println(entry.getKey() + ";");
        }
        getHeaderFile().println();

        getHeaderFile().println("};");

        getHeaderFile().println();
        PrinterUtils.printNamespaceClose(getHeaderFile(), getConfig());

        getHeaderFile().println("#endif");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printNewLine()
     */
    public void printNewLine() {
        getHeaderFile().println();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printSourceFileBeginning()
     *      )
     */
    public void printSourceFileBeginning() {
        getSourceFile().println(getConfig().getOutFileHeader());
        List<String> exampleSourceIncludeList = new ArrayList<String>();
        exampleSourceIncludeList.add(getConfig().getIncludePrecompiledHeader());
        String header = getHeaderFileName();
        exampleSourceIncludeList.add(header.substring(header.lastIndexOf('/') + 1));
        PrinterUtils.printIncludes(getSourceFile(), exampleSourceIncludeList);
        getSourceFile().println();
        getSourceFile().println();
        PrinterUtils.printNamespaceOpen(getSourceFile(), getNamespace());
        getSourceFile().println();
        getSourceFile().println();
        IGenerationDataProvider dataProvoider = getGenerationDataProvider();
        PrinterUtils.printCtorDtorImpl(getSourceFile(), getClassName(), getConfig().getNamespace() + "::"
                + getConfig().getClassNamePrivate(), false, false, dataProvoider, getCtorParas(),
                getInitializationList(), getCtorTmpl(), getDtorTmpl());
        getSourceFile().println();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#printSourceFileEnd()
     */
    public void printSourceFileEnd() {
        getSourceFile().println();
        getSourceFile().println();
        getSourceFile().println();
        PrinterUtils.printNamespaceClose(getSourceFile(), getConfig());
    }
}
