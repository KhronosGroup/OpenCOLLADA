XXXXXAAAAAXXXXX
package de.netallied.xsd2cppsax.printers;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.SortedMap;
import java.util.TreeMap;

import org.apache.xerces.xs.StringList;
import org.apache.xerces.xs.XSAttributeUse;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSObjectList;
import org.apache.xerces.xs.XSSimpleTypeDefinition;

import de.netallied.xsd2cppsax.CppEnumNameCreator;
import de.netallied.xsd2cppsax.IGenerationDataProvider;
import de.netallied.xsd2cppsax.TemplateEngine;
import de.netallied.xsd2cppsax.Util;
import de.netallied.xsd2cppsax.Variety;
import de.netallied.xsd2cppsax.TypeMapping.TypeMap;

/**
 * Prints a parser implementation which prints out parsed file to a file.
 * 
 */
public class FPrintfParserPrinter extends AbstractParserImplementationPrinter {

    /** Used to create names for C++ enums. */
    private CppEnumNameCreator cppEnumOrUnionNameCreator;

    /** Name of C++ FILE* member. */
    private String fileMemberName;

    /** Generated example C++ header file. */
    private PrintStream fprintfHeaderFile;

    /** Generated example C++ source file. */
    private PrintStream fprintfSourceFile;

    /**
     * C-tor.
     * 
     * @param config
     *            Configuration. Needed for output file names, classname and
     *            namespace.
     */
    public FPrintfParserPrinter(IGenerationDataProvider dataProvider) {
        super(dataProvider);
        fileMemberName = dataProvider.getConfig().getFprintfParserFileMemberName();
        this.cppEnumOrUnionNameCreator = dataProvider.getEnumOrUnionNameCreator();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#cleanupOutputFiles()
     */
    public void cleanupOutputFiles() {
        if (fprintfHeaderFile != null) {
            printHeaderFileEnd();
            fprintfHeaderFile.close();
        }
        if (fprintfSourceFile != null) {
            printSourceFileEnd();
            fprintfSourceFile.close();
        }
    }

    /**
     * Creates C++ code which converts a bool value into a string.
     */
    protected String createBoolToString() {
        return " ? \"true\" : \"false\" ";
    }

    /**
     * Creates C++ name for enumToString methods.
     */
    protected String createEnumToStringMethodName(String cppEnumTypeName, XSSimpleTypeDefinition simpleType) {
        return "toString__" + cppEnumTypeName;
    }

    /**
     * Creates C++ return type of printFloat methods.
     */
    protected String createPrintFloatReturnType() {
        return "void";
    }

    /**
     * Creates C++ return type of printFloat methods.
     */
    protected String createPrintFloatTypeParameter() {
        return "T";
    }

    /**
     * Creates C++ name for printUnion methods.
     */
    protected String createPrintUnionMethodName(String cppUnionTypeName, XSSimpleTypeDefinition simpleType) {
        return "printUnion__" + cppUnionTypeName;
    }

    /**
     * Finds fprintf format specifier for given XSD type.
     */
    protected String findFormatSpecifier(XSSimpleTypeDefinition simpleType) {
        String formatSpecifier;
        if (Util.hasFacetEnum(simpleType)) {
            formatSpecifier = "%s";
        } else if (Util.isStringType(simpleType, getConfig())) {
            formatSpecifier = "%s";
        } else if (Util.isBoolType(simpleType, getConfig())) {
            formatSpecifier = "%s";
        } else if (Util.isNumericType(simpleType, getConfig())) {
            if (Util.isFloatType(simpleType, getConfig())) {
                formatSpecifier = "%g";
            } else if (simpleType != null && simpleType.getNamespace() != null
                    && simpleType.getNamespace().equals(getConfig().getXSNamespace())
                    && simpleType.getName().equals("hexBinary")) {
                formatSpecifier = "%x";
            } else {
                formatSpecifier = "%i";
            }
        } else {
            formatSpecifier = "%s";
        }
        return formatSpecifier;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getAdditionalBaseClasses()
     */
    @Override
    protected List<String> getAdditionalBaseClasses() {
        List<String> baseClasses = new ArrayList<String>();
        baseClasses.add("public GeneratedSaxParser::IUnknownElementHandler");
        return baseClasses;
    }

    /**
     * Returns fprintf format specifier for C++ type char.
     */
    protected String getCharFormatSpecifier() {
        return "%c";
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ExampleParserPrinter#getClassName()
     */
    @Override
    protected String getClassName() {
        return getConfig().getFPrintfParserClassName();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getCtorParas()
     */
    @Override
    protected String getCtorParas() {
        return getConfig().getFprintfCtorParas();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getCtorTmpl()
     */
    @Override
    protected String getCtorTmpl() {
        return getConfig().getTemplateFprintfOpenFile();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getDtorTmpl()
     */
    @Override
    protected String getDtorTmpl() {
        return getConfig().getTemplateFprintfCloseFile();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ExampleParserPrinter#getHeaderFile()
     */
    @Override
    protected PrintStream getHeaderFile() {
        return fprintfHeaderFile;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ExampleParserPrinter#getHeaderFileName()
     */
    @Override
    protected String getHeaderFileName() {
        return getConfig().getOutputFPrintfHeaderFileName();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#getIncludeFiles()
     */
    @Override
    protected List<String> getIncludeFiles() {
        List<String> incs = new ArrayList<String>();
        incs.add("GeneratedSaxParserIUnknownElementHandler.h");
        incs.add("cstdio");
        return incs;
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
        SortedMap<String, String> members = new TreeMap<String, String>();
        members.put(fileMemberName, "FILE*");
        return members;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ExampleParserPrinter#getNamespace()
     */
    @Override
    protected String getNamespace() {
        return getConfig().getFPrintfParserNamespace();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ExampleParserPrinter#getSourceFile()
     */
    @Override
    protected PrintStream getSourceFile() {
        return fprintfSourceFile;
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#handleEnum(java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSSimpleTypeDefinition)
     */
    public void handleEnum(String cppEnumTypeName, XSSimpleTypeDefinition simpleType) {
        fprintfHeaderFile.println();
        printEnumToStringDecl(cppEnumTypeName, simpleType, fprintfHeaderFile, false);
        fprintfHeaderFile.println(";");

        fprintfSourceFile.println(getConfig().getOutputSourceFileMethodDelimiter());
        printEnumToStringDecl(cppEnumTypeName, simpleType, fprintfSourceFile, true);
        fprintfSourceFile.println();
        fprintfSourceFile.println("{");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("switch ( value ) {");
        StringList enumStringList = simpleType.getLexicalEnumeration();
        List<String> enumValues = Util.stringListToList(enumStringList);
        for (int i = 0; i < enumValues.size(); i++) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("case ");
            fprintfSourceFile.print(Util.createEnumValueName(cppEnumTypeName, enumValues, i, simpleType, getConfig()));
            fprintfSourceFile.println(":");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("return \"" + enumValues.get(i) + "\";");
        }

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("case ");
        fprintfSourceFile.print(Util.createEnumCountName(cppEnumTypeName, getConfig()));
        fprintfSourceFile.println(":");
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("return \"" + "ERROR" + "\";");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("case ");
        fprintfSourceFile.print(Util.createEnumNotPresentName(cppEnumTypeName, getConfig()));
        fprintfSourceFile.println(":");
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("return \"" + "NOT PRESENT" + "\";");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("}");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("return 0;");

        fprintfSourceFile.println("}");
        fprintfSourceFile.println();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#handleUnion(java.lang.String,
     *      com.sun.org.apache.xerces.internal.xs.XSSimpleTypeDefinition)
     */
    public void handleUnion(String cppUnionTypeName, XSSimpleTypeDefinition simpleType) {
        fprintfHeaderFile.println();
        printPrintUnionDecl(cppUnionTypeName, simpleType, fprintfHeaderFile, false);
        fprintfHeaderFile.println(";");

        fprintfSourceFile.println(getConfig().getOutputSourceFileMethodDelimiter());
        printPrintUnionDecl(cppUnionTypeName, simpleType, fprintfSourceFile, true);
        fprintfSourceFile.println();
        fprintfSourceFile.println("{");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("switch ( value." + getConfig().getUnionTypeMemberName() + " ) {");
        XSObjectList memberTypesObjectList = simpleType.getMemberTypes();
        List<XSSimpleTypeDefinition> memberTypes = Util.objectListToList(memberTypesObjectList);
        for (int i = 0; i < memberTypes.size(); i++) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("case ");
            fprintfSourceFile.print(getConfig().getNamespace() + "::");
            fprintfSourceFile.print(cppUnionTypeName + "::");
            String memberName = cppEnumOrUnionNameCreator.createUnionMemberTypeName(memberTypes.get(i), simpleType);
            fprintfSourceFile.print(memberName);
            fprintfSourceFile.println(":");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());

            if (!Util.isStringType(memberTypes.get(i), getConfig()) || Util.hasFacetEnum(memberTypes.get(i))) {
                fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
                String formatSpecifier = findFormatSpecifier(memberTypes.get(i));
                fprintfSourceFile.print(formatSpecifier);
                fprintfSourceFile.print("\", ");
            }
            String value = "value." + getConfig().getUnionDataMemberName() + "." + memberName;
            if (Util.hasFacetEnum(memberTypes.get(i))) {
                String cppEnumTypeName = cppEnumOrUnionNameCreator.createEnumTypeName(memberTypes.get(i), null);
                fprintfSourceFile.print(createEnumToStringMethodName(cppEnumTypeName, memberTypes.get(i)) + "(" + value
                        + ")");
            } else if (Util.isBoolType(memberTypes.get(i), getConfig())) {
                fprintfSourceFile.print(value + createBoolToString());
            } else if (Util.isStringType(memberTypes.get(i), getConfig())) {
                fprintfSourceFile.println("for (size_t i=0; i<" + value + ".length; ++i)");
                fprintfSourceFile.print(getConfig().getIndentation());
                fprintfSourceFile.print(getConfig().getIndentation());
                fprintfSourceFile.print(getConfig().getIndentation());
                fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
                fprintfSourceFile.print(getCharFormatSpecifier());
                fprintfSourceFile.print("\", " + value + ".str[i]");
                fprintfSourceFile.println(");");

            } else {
                fprintfSourceFile.print(value);
                String xsdTypeString = Util.findXSDSimpleTypeString(memberTypes.get(i), getConfig());
                TypeMap typeMap = getConfig().getTypeMapping().get(xsdTypeString);
                if (typeMap != null) {
                    if (typeMap.getToString() != null) {
                        fprintfSourceFile.print(typeMap.getToString());
                    }
                }
            }
            if (!Util.isStringType(memberTypes.get(i), getConfig()) || Util.hasFacetEnum(memberTypes.get(i))) {
                fprintfSourceFile.println(");");
            }

            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("break;");
        }

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("case ");
        fprintfSourceFile.print(getConfig().getNamespace() + "::" + cppUnionTypeName + "::");
        fprintfSourceFile.print(getConfig().getUnionInvalidTypeName());
        fprintfSourceFile.println(":");
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        fprintfSourceFile.println(getConfig().getUnionInvalidTypeName() + "\");");
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("break;");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("}");

        fprintfSourceFile.println("}");
        fprintfSourceFile.println();
    }

    /**
     * Prints code which prints an attribute with variety atomic.
     */
    protected void printAttributeAtomic(XSAttributeUse attrUse, XSSimpleTypeDefinition attrType, String attrName,
            String value, String cppElementName, XSElementDeclaration element) {
        String cppEnumTypeName = null;
        if (Util.hasFacetEnum(attrType)) {
            cppEnumTypeName = cppEnumOrUnionNameCreator.createEnumTypeName(attrType, null);
            fprintfSourceFile.print(getConfig().getIndentation());
            printEnumPresentCheck(value, cppEnumTypeName, fprintfSourceFile);
            fprintfSourceFile.print(getConfig().getIndentation());
        } else if (Util.isStringType(attrType, getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("if ( " + value + " )");
            fprintfSourceFile.print(getConfig().getIndentation());
        } else if (Util.presentMaskRequired(attrUse, getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            printAttributePresentCheck(attrUse, value, fprintfSourceFile, cppElementName, element);
            fprintfSourceFile.print(getConfig().getIndentation());
        }

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        String formatSpecifier = findFormatSpecifier(attrType);
        fprintfSourceFile.print(" " + attrName + "=\\\"" + formatSpecifier + "\\\"");
        fprintfSourceFile.print("\", ");
        if (Util.hasFacetEnum(attrType)) {
            fprintfSourceFile.print(createEnumToStringMethodName(cppEnumTypeName, attrType) + "(" + value + ")");
        } else if (Util.isBoolType(attrType, getConfig())) {
            fprintfSourceFile.print(value + createBoolToString());
        } else {
            fprintfSourceFile.print(value);
            String xsdTypeString = Util.findXSDSimpleTypeString(attrType, getConfig());
            TypeMap typeMap = getConfig().getTypeMapping().get(xsdTypeString);
            if (typeMap != null) {
                if (typeMap.getToString() != null) {
                    fprintfSourceFile.print(typeMap.getToString());
                }
            }
        }
        fprintfSourceFile.println(");");
    }

    /**
     * Prints code which prints a float/double attribute.
     */
    protected void printAttributeFloat(XSAttributeUse attrUse, XSSimpleTypeDefinition attrType, String attrName,
            String value, String cppElementName, XSElementDeclaration element) {
        int indentationLevel = 1;
        if (Util.presentMaskRequired(attrUse, getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            printAttributePresentCheck(attrUse, value, fprintfSourceFile, cppElementName, element);
            fprintfSourceFile.println(getConfig().getIndentation() + "{");
            indentationLevel++;
        }
        for (int i = 0; i < indentationLevel; i++) {
            fprintfSourceFile.print(getConfig().getIndentation());
        }
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        fprintfSourceFile.println(" " + attrName + "=\\\"\");");
        for (int i = 0; i < indentationLevel; i++) {
            fprintfSourceFile.print(getConfig().getIndentation());
        }
        if (Util.isFloat(attrType, getConfig())) {
            fprintfSourceFile.print(getConfig().getFprintfParserPrintFloatMethodName());
        } else if (Util.isDouble(attrType, getConfig())) {
            fprintfSourceFile.print(getConfig().getFprintfParserPrintDoubleMethodName());
        }
        fprintfSourceFile.println("(" + value + ");");
        for (int i = 0; i < indentationLevel; i++) {
            fprintfSourceFile.print(getConfig().getIndentation());
        }
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        fprintfSourceFile.println("\\\"\");");

        if (indentationLevel > 1) {
            fprintfSourceFile.println(getConfig().getIndentation() + "}");
        }
    }

    /**
     * Prints code which prints an attribute list.
     */
    protected void printAttributeList(XSAttributeUse attrUse, XSSimpleTypeDefinition attrType, String attrName,
            String value) {
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("if ( " + value + ".size > 0 ) {");
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        fprintfSourceFile.println(" " + attrName + "=\\\"\");");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("for (size_t i=0; i<" + value + ".size; ++i) {");

        XSSimpleTypeDefinition itemType = attrType.getItemType();
        if (Util.findVariety(itemType) == Variety.UNION) {
            printAttributeListItemUnion(itemType, value);
        } else if (Util.isFloatType(itemType, getConfig())) {
            printAttributeListItemFloat(itemType, value);
        } else if (Util.isNumericType(itemType, getConfig()) || Util.isBoolType(itemType, getConfig())) {
            printAttributeListItemNumeric(itemType, value);
        } else {
            printAttributeListItemString(itemType, value);
        }

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("}");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("fprintf(" + fileMemberName + ", \"\\\"\");");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("}");
    }

    /**
     * Prints code which prints a float/double list item of an attribute.
     */
    protected void printAttributeListItemFloat(XSSimpleTypeDefinition itemType, String value) {
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        if (Util.isFloat(itemType, getConfig())) {
            fprintfSourceFile.print(getConfig().getFprintfParserPrintFloatMethodName());
        } else if (Util.isDouble(itemType, getConfig())) {
            fprintfSourceFile.print(getConfig().getFprintfParserPrintDoubleMethodName());
        }
        fprintfSourceFile.println("(" + value + ".data[i]);");

        printAttributeListItemSeparator(value);
    }

    /**
     * Prints code which prints a numeric list item of an attribute.
     */
    protected void printAttributeListItemNumeric(XSSimpleTypeDefinition itemType, String value) {
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        fprintfSourceFile.print(findFormatSpecifier(itemType));
        fprintfSourceFile.print("\", ");
        fprintfSourceFile.print(value + ".data[i]");
        if (Util.isBoolType(itemType, getConfig())) {
            fprintfSourceFile.print(createBoolToString());
        }
        fprintfSourceFile.println(");");

        printAttributeListItemSeparator(value);
    }

    /**
     * Prints code which prints a separator between items of an attribute list.
     */
    protected void printAttributeListItemSeparator(String value) {
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("if ( i != " + value + ".size - 1 )");
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("fprintf(" + fileMemberName + ", \" \");");
    }

    /**
     * Prints code which prints a string list item of an attribute.
     */
    protected void printAttributeListItemString(XSSimpleTypeDefinition itemType, String value) {
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("for (size_t j=0; j<" + value + ".data[i].length; ++j)");
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        // fprintfSourceFile.print(findFormatSpecifier(itemType));
        fprintfSourceFile.print(getCharFormatSpecifier());
        fprintfSourceFile.print("\", ");
        fprintfSourceFile.print(value + ".data[i].str[j]");
        fprintfSourceFile.println(");");

        printAttributeListItemSeparator(value);
    }

    /**
     * Prints code which prints a union list item of an attribute.
     */
    protected void printAttributeListItemUnion(XSSimpleTypeDefinition itemType, String value) {
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        String cppUnionTypeName = cppEnumOrUnionNameCreator.createUnionTypeName(itemType, null);
        fprintfSourceFile.println(createPrintUnionMethodName(cppUnionTypeName, itemType) + "(" + value + ".data[i]);");

        printAttributeListItemSeparator(value);
    }

    /**
     * Prints code which checks if an attribute is present.
     */
    protected void printAttributePresentCheck(XSAttributeUse attrUse, String value, PrintStream stream,
            String cppElementName, XSElementDeclaration element) {
        String checkAttrPresent = getConfig().getTemplateAttributePresentCheck();
        checkAttrPresent = TemplateEngine.fillInTemplate(checkAttrPresent, cppElementName, element, attrUse, null,
                null, null, getGenerationDataProvider());
        stream.println("if ( " + checkAttrPresent + " )");
    }

    /**
     * Prints code which prints an union attribute.
     */
    protected void printAttributeUnion(XSAttributeUse attrUse, XSSimpleTypeDefinition attrType, String attrName,
            String value, String cppElementName, XSElementDeclaration element) {

        int indentationLevel = 1;
        if (Util.presentMaskRequired(attrUse, getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            printAttributePresentCheck(attrUse, value, fprintfSourceFile, cppElementName, element);
            fprintfSourceFile.println(getConfig().getIndentation() + "{");
            indentationLevel++;
        }
        for (int i = 0; i < indentationLevel; i++) {
            fprintfSourceFile.print(getConfig().getIndentation());
        }
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        fprintfSourceFile.println(" " + attrName + "=\\\"\");");
        String cppUnionTypeName = cppEnumOrUnionNameCreator.createUnionTypeName(attrType, null);
        for (int i = 0; i < indentationLevel; i++) {
            fprintfSourceFile.print(getConfig().getIndentation());
        }
        fprintfSourceFile.println(createPrintUnionMethodName(cppUnionTypeName, attrType) + "(" + value + ");");
        for (int i = 0; i < indentationLevel; i++) {
            fprintfSourceFile.print(getConfig().getIndentation());
        }
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        fprintfSourceFile.println("\\\"\");");

        if (indentationLevel > 1) {
            fprintfSourceFile.println(getConfig().getIndentation() + "}");
        }
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
        fprintfSourceFile.println("{");

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", ");
        fprintfSourceFile.println("\"<" + element.getName() + "\");");

        boolean unknwonAttributesHandlingRequired = Util.isUnknownAttributesMemberRequired(element.getTypeDefinition());

        // xmlns attribute
        if (cppElementName.equals(getConfig().getRootElementName())) {
            if (element.getNamespace() != null) {
                if (!unknwonAttributesHandlingRequired) {
                    fprintfSourceFile.print(getConfig().getIndentation());
                    fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
                    fprintfSourceFile.println(" " + "xmlns" + "=\\\"" + element.getNamespace() + "\\\"\");");
                }
            }
        }

        // handle attributes
        if (attributesRequired) {
            String attrDataParaName = getConfig().getAttributeDataParameterName();
            List<XSAttributeUse> attributeUses = Util.collectAttributeUses(element);
            for (XSAttributeUse attrUse : attributeUses) {
                XSSimpleTypeDefinition attrType = Util.getType(attrUse);
                String attrName = Util.getAttributeOriginalName(attrUse, getConfig());
                attrName = Util.updateAttributeNameWithNamespace(element.getNamespace(), attrUse, attrName);
                String value = attrDataParaName + "."
                        + Util.replaceCharactersForbiddenInCppIdentifiers(Util.getAttributeName(attrUse, getConfig()));
                switch (Util.findVariety(attrType)) {
                case ATOMIC:
                    if (Util.isFloatType(attrType, getConfig()) && !Util.hasFacetEnum(attrType)) {
                        printAttributeFloat(attrUse, attrType, attrName, value, cppElementName, element);
                    } else {
                        printAttributeAtomic(attrUse, attrType, attrName, value, cppElementName, element);
                    }
                    break;

                case LIST:
                    printAttributeList(attrUse, attrType, attrName, value);
                    break;

                case UNION:
                    printAttributeUnion(attrUse, attrType, attrName, value, cppElementName, element);
                    break;
                default:
                    break;
                }
            }
        }

        // unknown attributes
        if (unknwonAttributesHandlingRequired) {
            fprintfSourceFile.println(TemplateEngine.fillInTemplate(getConfig().getTemplateFprintfUnknownAttributes(),
                    cppElementName, element, null, null, null, null, getGenerationDataProvider()));
        }

        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
        if (Util.mayHaveCharData(element.getTypeDefinition(), getConfig())
                || Util.mayHaveChildElements(element.getTypeDefinition(), getConfig())) {
            fprintfSourceFile.print(">");
        } else {
            fprintfSourceFile.print(" />");
        }
        // print char data in same line ...
        // fprintfSourceFile.print("\\n");
        // if (Util.mayHaveCharData(element.getTypeDefinition())) {
        // fprintfSourceFile.print(getConfig().getIndentation());
        // }
        // ... but print new elements in new line
        if (!Util.mayHaveCharData(element.getTypeDefinition(), getConfig())) {
            fprintfSourceFile.print("\\n");
        }
        fprintfSourceFile.println("\");");

        printDefaultMethodEnd();
    }

    /**
     * Prints code which prints data with variety atomic.
     */
    protected void printDataAtomic(XSSimpleTypeDefinition simpleType, String value, String length) {
        if (Util.hasFacetEnum(simpleType)) {
            String cppEnumTypeName = cppEnumOrUnionNameCreator.createEnumTypeName(simpleType, null);
            fprintfSourceFile.print(getConfig().getIndentation());
            printEnumPresentCheck(value, cppEnumTypeName, fprintfSourceFile);
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
            String formatSpecifier = findFormatSpecifier(simpleType);
            fprintfSourceFile.print(formatSpecifier);
            fprintfSourceFile.print("\", ");
            fprintfSourceFile.print(createEnumToStringMethodName(cppEnumTypeName, simpleType) + "(" + value + ")");
            fprintfSourceFile.println(");");

        } else if (Util.isStringType(simpleType, getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("for (size_t i=0; i<" + length + "; ++i)");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
            fprintfSourceFile.print(getCharFormatSpecifier());
            fprintfSourceFile.print("\", " + value + "[i]");
            fprintfSourceFile.println(");");

        } else if (Util.isNumericType(simpleType, getConfig()) || Util.isBoolType(simpleType, getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
            String formatSpecifier = findFormatSpecifier(simpleType);
            fprintfSourceFile.print(formatSpecifier);
            fprintfSourceFile.print("\", " + value);
            if (Util.isBoolType(simpleType, getConfig())) {
                fprintfSourceFile.print(createBoolToString());
            }
            fprintfSourceFile.println(");");

        } else {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
            String formatSpecifier = findFormatSpecifier(simpleType);
            fprintfSourceFile.print(formatSpecifier);
            fprintfSourceFile.print("\", " + value);
            String xsdTypeString = Util.findXSDSimpleTypeString(simpleType, getConfig());
            TypeMap typeMap = getConfig().getTypeMapping().get(xsdTypeString);
            if (typeMap != null) {
                if (typeMap.getToString() != null) {
                    fprintfSourceFile.print(typeMap.getToString());
                }
            }
            fprintfSourceFile.println(");");
        }
    }

    /**
     * Prints code which prints float/double data.
     */
    protected void printDataFloat(XSSimpleTypeDefinition simpleType, String value, String length) {
        fprintfSourceFile.print(getConfig().getIndentation());
        if (Util.isFloat(simpleType, getConfig())) {
            fprintfSourceFile.print(getConfig().getFprintfParserPrintFloatMethodName());
        } else if (Util.isDouble(simpleType, getConfig())) {
            fprintfSourceFile.print(getConfig().getFprintfParserPrintDoubleMethodName());
        }
        fprintfSourceFile.println("(" + value + ");");

    }

    /**
     * Prints code which prints data with variety list.
     */
    protected void printDataList(XSSimpleTypeDefinition simpleType, String value, String length) {
        XSSimpleTypeDefinition itemType = simpleType.getItemType();
        if (Util.findVariety(itemType) == Variety.UNION) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("for (size_t i=0; i<" + length + "; ++i) {");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            String cppUnionTypeName = cppEnumOrUnionNameCreator.createUnionTypeName(itemType, null);
            fprintfSourceFile.println(createPrintUnionMethodName(cppUnionTypeName, itemType) + "(" + value + "[i]);");
            printDataListItemSeparator();

        } else if (Util.hasFacetEnum(itemType)) {
            String cppEnumTypeName = cppEnumOrUnionNameCreator.createEnumTypeName(itemType, null);
            value += "[i]";
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("for (size_t i=0; i<" + length + "; ++i) {");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            printEnumPresentCheck(value, cppEnumTypeName, fprintfSourceFile);
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("{");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
            String formatSpecifier = findFormatSpecifier(itemType);
            fprintfSourceFile.print(formatSpecifier);
            fprintfSourceFile.print("\", ");
            fprintfSourceFile.print(createEnumToStringMethodName(cppEnumTypeName, itemType) + "( " + value + " )");
            fprintfSourceFile.println(");");

            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("fprintf(" + fileMemberName + ", \" \");");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("}");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("}");

        } else if (Util.isFloatType(itemType, getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("for (size_t i=0; i<" + length + "; ++i) {");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            if (Util.isFloat(itemType, getConfig())) {
                fprintfSourceFile.print(getConfig().getFprintfParserPrintFloatMethodName());
            } else if (Util.isDouble(itemType, getConfig())) {
                fprintfSourceFile.print(getConfig().getFprintfParserPrintDoubleMethodName());
            }
            fprintfSourceFile.println("(" + value + "[i]);");
            printDataListItemSeparator();

        } else if (Util.isNumericType(itemType, getConfig()) || Util.isBoolType(itemType, getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("for (size_t i=0; i<" + length + "; ++i) {");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
            String formatSpecifier = findFormatSpecifier(itemType);
            fprintfSourceFile.print(formatSpecifier);
            fprintfSourceFile.print("\", " + value + "[i]");
            if (Util.isBoolType(itemType, getConfig())) {
                fprintfSourceFile.print(createBoolToString());
            }
            fprintfSourceFile.println(");");
            printDataListItemSeparator();

        } else {
            // String as default
            // if (Util.isStringType(itemType, getConfig()))
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("for (size_t i=0; i<" + length + "; ++i) {");
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.println("for (size_t j=0; j<" + value + "[i].length; ++j)");

            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("fprintf(" + fileMemberName + ", \"");
            fprintfSourceFile.print(getCharFormatSpecifier());
            fprintfSourceFile.print("\", " + value + "[i].str[j]");
            fprintfSourceFile.println(");");
            printDataListItemSeparator();

        }
    }

    /**
     * Prints code which prints a separator between items of a data list.
     */
    protected void printDataListItemSeparator() {
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("fprintf(" + fileMemberName + ", \" \");");
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("}");
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
        fprintfSourceFile.println("{");

        XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(element.getTypeDefinition());
        if (simpleType != null) {
            String value = getConfig().getConvenienceDataMethodValueParameterName();
            String length = getConfig().getConvenienceDataMethodLengthParameterName();
            switch (Util.findVariety(simpleType)) {
            case ATOMIC:
                if (Util.isFloatType(simpleType, getConfig()) && !Util.hasFacetEnum(simpleType)) {
                    printDataFloat(simpleType, value, length);
                } else {
                    printDataAtomic(simpleType, value, length);
                }
                break;
            case LIST:
                printDataList(simpleType, value, length);
                break;
            case UNION:
                printDataUnion(simpleType, value, length);
                break;
            default:
                break;
            }
        }

        printDefaultMethodEnd();
    }

    /**
     * Prints code which prints data with variety union.
     */
    protected void printDataUnion(XSSimpleTypeDefinition simpleType, String value, String length) {
        String cppUnionTypeName = cppEnumOrUnionNameCreator.createUnionTypeName(simpleType, null);
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println(createPrintUnionMethodName(cppUnionTypeName, simpleType) + "(" + value + ");");

    }

    /**
     * Prints the default end of a method.
     */
    protected void printDefaultMethodEnd() {
        fprintfSourceFile.println();
        fprintfSourceFile.print(getConfig().getIndentation());
        fprintfSourceFile.println("return true;");
        fprintfSourceFile.println("}");
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
        fprintfSourceFile.println("{");

        if (Util.mayHaveCharData(element.getTypeDefinition(), getConfig())
                || Util.mayHaveChildElements(element.getTypeDefinition(), getConfig())) {
            fprintfSourceFile.print(getConfig().getIndentation());
            fprintfSourceFile.print("fprintf(");
            fprintfSourceFile.print(fileMemberName + ", \"");
            // don't print closing tag in new line
            // if (Util.mayHaveCharData(element.getTypeDefinition())) {
            // fprintfSourceFile.print("\\n");
            // }
            fprintfSourceFile.print("</" + element.getName() + ">\\n\");");
            fprintfSourceFile.println();
        }

        printDefaultMethodEnd();
    }

    /**
     * Prints code which checks if an enum is present.
     */
    protected void printEnumPresentCheck(String value, String cppEnumTypeName, PrintStream stream) {
        stream.println("if ( " + value + " != " + Util.createEnumNotPresentName(cppEnumTypeName, getConfig()) + " )");
    }

    /**
     * Prints declaration of enumToString functions.
     */
    protected void printEnumToStringDecl(String cppEnumTypeName, XSSimpleTypeDefinition simpleType, PrintStream stream,
            boolean printClassName) {
        stream.print("const char* ");
        if (printClassName) {
            stream.print(getClassName() + "::");
        }
        stream.print(createEnumToStringMethodName(cppEnumTypeName, simpleType));
        stream.print("( " + cppEnumTypeName + " value )");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#printHeaderFileBeginning()
     */
    @Override
    public void printHeaderFileBeginning() {
        super.printHeaderFileBeginning();

        getHeaderFile().println();
        getHeaderFile()
                .println(
                        "virtual bool elementBegin( const ParserChar* elementName, const GeneratedSaxParser::xmlChar** attributes);");
        getHeaderFile().println("virtual bool elementEnd(const ParserChar* elementName);");
        getHeaderFile().println("virtual bool textData(const ParserChar* text, size_t textLength);");
        getHeaderFile().println();

        printPrintFloatMethodDeclarations(getHeaderFile());

        getHeaderFile().println();
        getHeaderFile().println();
        getHeaderFile().println();

    }

    /**
     * Prints declarations of printFloat methods.
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printPrintFloatMethodDeclarations(PrintStream stream) {
        String typePara = createPrintFloatTypeParameter();
        String returnType = createPrintFloatReturnType();

        stream.println("template<typename " + typePara + ">");
        stream.print(returnType + " " + getConfig().getFprintfParserPrintFloatTemplateMethodName());
        stream.println("( " + typePara + " " + getConfig().getFprintfParserPrintFloatMethodParameterName() + " );");

        stream.print(returnType + " " + getConfig().getFprintfParserPrintFloatMethodName());
        stream.println("( " + "float" + " " + getConfig().getFprintfParserPrintFloatMethodParameterName() + " );");

        stream.print(returnType + " " + getConfig().getFprintfParserPrintDoubleMethodName());
        stream.println("( " + "double" + " " + getConfig().getFprintfParserPrintFloatMethodParameterName() + " );");
    }

    /**
     * Prints implementation of printFloat methods.
     * 
     * @param stream
     *            Stream to print to.
     */
    protected void printPrintFloatMethodImpls(PrintStream stream) {
        String typePara = createPrintFloatTypeParameter();
        String returnType = createPrintFloatReturnType();

        stream.println(getConfig().getOutputSourceFileMethodDelimiter());
        stream.println("template<typename " + typePara + ">");
        stream.print(returnType + " " + getClassName() + "::"
                + getConfig().getFprintfParserPrintFloatTemplateMethodName());
        stream.println("( " + typePara + " " + getConfig().getFprintfParserPrintFloatMethodParameterName() + " )");
        stream.println("{");
        stream.print(TemplateEngine.fillInTemplate(getConfig().getTemplateFprintfPrintFloatTemplate(), null, null,
                null, null, null, null, getGenerationDataProvider()));
        stream.println("}");
        stream.println();

        stream.println(getConfig().getOutputSourceFileMethodDelimiter());
        stream.print(returnType + " " + getClassName() + "::" + getConfig().getFprintfParserPrintFloatMethodName());
        stream.println("( " + "float" + " " + getConfig().getFprintfParserPrintFloatMethodParameterName() + " )");
        stream.println("{");
        stream.print(TemplateEngine.fillInTemplate(getConfig().getTemplateFprintfPrintFloat(), null, null, null, null,
                null, null, getGenerationDataProvider()));
        stream.println("}");
        stream.println();

        stream.println(getConfig().getOutputSourceFileMethodDelimiter());
        stream.print(returnType + " " + getClassName() + "::" + getConfig().getFprintfParserPrintDoubleMethodName());
        stream.println("( " + "double" + " " + getConfig().getFprintfParserPrintFloatMethodParameterName() + " )");
        stream.println("{");
        stream.print(TemplateEngine.fillInTemplate(getConfig().getTemplateFprintfPrintDouble(), null, null, null, null,
                null, null, getGenerationDataProvider()));
        stream.println("}");
        stream.println();
    }

    /**
     * Prints declaration of printUnion method.
     */
    protected void printPrintUnionDecl(String cppUnionTypeName, XSSimpleTypeDefinition simpleType, PrintStream stream,
            boolean printClassName) {
        stream.print("void ");
        if (printClassName) {
            stream.print(getClassName() + "::");
        }
        stream.print(createPrintUnionMethodName(cppUnionTypeName, simpleType));
        stream.print("( const " + cppUnionTypeName + "& value )");
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.AbstractParserImplementationPrinter#printSourceFileBeginning()
     */
    @Override
    public void printSourceFileBeginning() {
        super.printSourceFileBeginning();
        getSourceFile().println();
        getSourceFile().println();

        getSourceFile().println(getConfig().getOutputSourceFileMethodDelimiter());
        getSourceFile().println(
                TemplateEngine.fillInTemplate(getConfig().getTemplateFprintfUnknownElementBegin(), null, null, null,
                        null, null, null, getGenerationDataProvider()));
        getSourceFile().println();

        getSourceFile().println(getConfig().getOutputSourceFileMethodDelimiter());
        getSourceFile().println(
                TemplateEngine.fillInTemplate(getConfig().getTemplateFprintfUnknownElementEnd(), null, null, null,
                        null, null, null, getGenerationDataProvider()));
        getSourceFile().println();

        getSourceFile().println(getConfig().getOutputSourceFileMethodDelimiter());
        getSourceFile().println(
                TemplateEngine.fillInTemplate(getConfig().getTemplateFprintfUnknownElementData(), null, null, null,
                        null, null, null, getGenerationDataProvider()));
        getSourceFile().println();

        getSourceFile().println();
        getSourceFile().println();

        printPrintFloatMethodImpls(getSourceFile());

        getSourceFile().println();
        getSourceFile().println();
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.printers.ICodePrinter#setupOutputFiles()
     */
    public void setupOutputFiles() throws FileNotFoundException {
        fprintfHeaderFile = new PrintStream(getConfig().getOutputFPrintfHeaderFileName());
        printHeaderFileBeginning();
        fprintfSourceFile = new PrintStream(getConfig().getOutputFPrintfSourceFileName());
        printSourceFileBeginning();
    }
}
