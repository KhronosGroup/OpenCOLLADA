/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.printers;

import java.io.PrintStream;
import java.util.List;

import de.netallied.xsd2cppsax.Config;
import de.netallied.xsd2cppsax.IGenerationDataProvider;
import de.netallied.xsd2cppsax.TemplateEngine;
import de.netallied.xsd2cppsax.Util;

/**
 * Contains utility methods for source printers.
 * 
 */
public class PrinterUtils {

    /**
     * Creates include protection macro.
     * 
     * @param namespace
     *            Namespace of file to protect.
     * @param className
     *            Class of file to protect.
     * @return Include protection.
     */
    public static String createIncludeProtectionMacro(String namespace, String className) {
        if (namespace == null)
            namespace = "";
        if (className == null)
            className = "";
        return "__" + namespace.toUpperCase() + "_" + className.toUpperCase() + "_H__";
    }

    /**
     * Creates method name of initFunctionMap method.
     * 
     * @return Method name.
     */
    public static String createInitFunctionMapMethodName() {
        return "initFunctionMap";
    }

    /**
     * Creates method name of initNameMap method.
     * 
     * @return Method name.
     */
    public static String createInitNameMapMethodName() {
        return "initNameMap";
    }

    /**
     * Prints begin convenience method decl type modifiers.
     * 
     * @param stream
     *            Stream to print to.
     */
    public static void printBeginConvenienceMethodDeclTypeModifiers(PrintStream stream) {
        stream.print("virtual");
    }

    /**
     * Prints default implementation of convenience begin method.
     * 
     * @param stream
     *            Stream to print to.
     * @param whiteSpaces
     *            Indicates if whitespaces shall be printed.
     */
    public static void printBeginConvenienceMethodDefaultImpl(PrintStream stream, boolean whiteSpaces, Config config) {
        stream.print("{");
        if (whiteSpaces) {
            stream.println();
            stream.print(config.getIndentation());
        }
        stream.print("return true;");
        if (whiteSpaces) {
            stream.println();
        }
        stream.print("}");
    }

    /**
     * Prints begin convenience method return type.
     * 
     * @param stream
     *            Stream to print to.
     */
    public static void printBeginConvenienceMethodReturnType(PrintStream stream) {
        stream.print("bool");
    }

    /**
     * Prints typedefs to use types from base class namespace without writing
     * namespace all the time.
     */
    public static void printConvenienceTypedefs(PrintStream stream, boolean errType, Config config) {
        stream.println("typedef " + config.getBaseClassNamespace() + "::sint8 sint8;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::sint16 sint16;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::sint32 sint32;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::sint64 sint64;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::uint8 uint8;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::uint16 uint16;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::uint32 uint32;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::uint64 uint64;");
        stream.println();
        stream.println("typedef " + config.getBaseClassNamespace() + "::StringHash StringHash;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::ParserChar ParserChar;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::ParserString ParserString;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::ParserAttributes ParserAttributes;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::Utils Utils;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::ParserError ParserError;");
        stream.println("typedef " + config.getBaseClassNamespace() + "::StringHashPair StringHashPair;");
        if (errType) {
            stream.println("typedef " + config.getBaseClassNamespace() + "::ParserError ParserError;");
        }
    }

    /**
     * Prints a C++ hash constant.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppIdentifier
     *            Constant name.
     * @param value
     *            Value of the constant. Hash will be calculated.
     */
    public static void printCppHashConstant(PrintStream stream, String cppIdentifier, String value) {
        stream.println("const StringHash " + cppIdentifier + " = " + Util.calculateHash(value) + ";");
    }

    /**
     * Prints declaration of a C++ string constant.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppIdentifier
     *            Constant name.
     */
    public static void printCppStringConstantDecl(PrintStream stream, String cppIdentifier) {
        stream.println("extern const char* " + cppIdentifier + ";");
    }

    /**
     * Prints definition of a C++ string constant.
     * 
     * @param stream
     *            Stream to print to.
     * @param cppIdentifier
     *            Constant name.
     * @param value
     *            Value of the constant.
     */
    public static void printCppStringConstantDef(PrintStream stream, String cppIdentifier, String value) {
        stream.println("const char* " + cppIdentifier + " = \"" + value + "\";");
    }

    /**
     * Prints c-tor and d-tor declaration for C++ header file.
     */
    public static void printCtorDtorHeaderDecl(PrintStream stream, String className, boolean errHandler,
            boolean emptyImpl, String ctorParas, Config config) {
        stream.print(className + "(");
        if (ctorParas != null) {
            stream.print(" " + ctorParas);
            if (errHandler) {
                stream.print(",");
            } else {
                stream.print(" ");
            }
        }
        if (errHandler) {
            stream.print(" " + config.getNamespace() + "::" + config.getClassNamePublic() + "* impl, "
                    + config.getBaseClassNamespace() + "::");
            stream.print("IErrorHandler* errorHandler = 0 ");
        }
        stream.print(")");
        if (emptyImpl) {
            stream.println("{}");
        } else {
            stream.println(";");
        }
        stream.print("virtual ~" + className + "()");
        if (emptyImpl) {
            stream.println("{}");
        } else {
            stream.println(";");
        }
    }

    /**
     * Prints c-tor and d-tor for C++ source file.
     */
    public static void printCtorDtorImpl(PrintStream stream, String className, String baseClass, boolean initMaps,
            boolean errHandler, IGenerationDataProvider dataProvoider, String ctorParas,
            List<String> initializationList, String ctorTmpl, String dtorTmpl) {

        Config config = dataProvoider.getConfig();

        // c-tor
        stream.println(config.getOutputSourceFileMethodDelimiter());
        stream.print(className + "::" + className + "(");
        if (ctorParas != null) {
            stream.print(" " + ctorParas);
            if (errHandler) {
                stream.print(",");
            } else {
                stream.print(" ");
            }
        }
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

        if (initializationList != null && !initializationList.isEmpty()) {
            stream.print(config.getIndentation());
            if (!errHandler) {
                stream.print(": ");
            } else {
                stream.print(", ");
            }
            stream.println(initializationList.get(0));
            for (int i = 1; i < initializationList.size(); i++) {
                stream.print(config.getIndentation());
                stream.print(", ");
                stream.println(initializationList.get(i));
            }
        }

        stream.println("{");

        if (initMaps) {
            stream.print(config.getIndentation());
            stream.println(createInitFunctionMapMethodName() + "();");
            stream.print(config.getIndentation());
            stream.println(createInitNameMapMethodName() + "();");
        }
        if (ctorTmpl != null) {
            stream.println(TemplateEngine.fillInTemplate(ctorTmpl, null, null, null, null, null, null, dataProvoider));
        }
        stream.println("}");
        stream.println();

        // d-tor
        stream.println(config.getOutputSourceFileMethodDelimiter());
        stream.println(className + "::~" + className + "()");
        stream.println("{");
        if (dtorTmpl != null) {
            stream.println(TemplateEngine.fillInTemplate(dtorTmpl, null, null, null, null, null, null, dataProvoider));
        }
        stream.println("}");
        stream.println();
    }

    /**
     * Prints data convenience method decl type modifiers.
     * 
     * @param stream
     *            Stream to print to.
     */
    public static void printDataConvenienceMethodDeclTypeModifiers(PrintStream stream) {
        stream.print("virtual");
    }

    /**
     * Prints default implementation of convenience data method.
     * 
     * @param stream
     *            Stream to print to.
     * @param whiteSpaces
     *            Indicates if whitespaces shall be printed.
     */
    public static void printDataConvenienceMethodDefaultImpl(PrintStream stream, boolean whiteSpaces, Config config) {
        PrinterUtils.printBeginConvenienceMethodDefaultImpl(stream, whiteSpaces, config);
    }

    /**
     * Prints return type of convenience data method to given stream.
     * 
     * @param stream
     *            Stream to print to.
     */
    public static void printDataConvenienceMethodReturnType(PrintStream stream) {
        stream.print("bool");
    }

    /**
     * Prints declaration of c-ctor and assignment op with comment.
     */
    public static void printDisableDefaultMethods(PrintStream stream, String className) {
        stream.println("/** Disable default copy ctor. */");
        stream.println(className + "( const " + className + "& pre );");

        stream.println("/** Disable default assignment operator. */");
        stream.println("const " + className + "& operator= ( const " + className + "& pre );");
    }

    /**
     * Prints end method decl type modifiers.
     * 
     * @param stream
     *            Stream to print to.
     */
    public static void printEndMethodDeclTypeModifiers(PrintStream stream) {
        stream.print("virtual");
    }

    /**
     * Prints default implementation of end method.
     * 
     * @param stream
     *            Stream to print to.
     * @param whiteSpaces
     *            Indicates if whitespaces shall be printed.
     */
    public static void printEndMethodDefaultImpl(PrintStream stream, boolean whiteSpaces, Config config) {
        printBeginConvenienceMethodDefaultImpl(stream, whiteSpaces, config);
    }

    /**
     * Prints end method return type.
     * 
     * @param stream
     *            Stream to print to.
     */
    public static void printEndMethodReturnType(PrintStream stream) {
        stream.print("bool");
    }

    /**
     * Prints inclusion statement for generated header file.
     * 
     * @param stream
     *            Stream to print to.
     * @param path
     *            Path to header file. Only file name will be printed
     */
    public static void printIncludeGeneratedHeader(PrintStream stream, String path) {
        if (path.contains("/")) {
            path = path.substring(path.lastIndexOf('/') + 1);
        }
        stream.println("#include \"" + path + "\"");
    }

    /**
     * Prints include protection.
     * 
     * @param stream
     *            Stream to print to.
     * @param includeProtectionMacro
     *            Unique constant for this file.
     */
    public static void printIncludeProtection(PrintStream stream, String includeProtectionMacro) {
        stream.println("#ifndef " + includeProtectionMacro);
        stream.println("#define " + includeProtectionMacro);
    }

    /**
     * Prints given includes to given stream.
     * 
     * @param stream
     *            String to print to.
     * @param includes
     *            List of header files.
     */
    public static void printIncludes(PrintStream stream, List<String> includes) {
        for (String include : includes) {
            stream.println("#include \"" + include + "\"");
        }
    }

    /**
     * Prints C++ code to close namespace from config.
     */
    public static void printNamespaceClose(PrintStream stream, Config config) {
        String namespace = config.getNamespace();
        if (namespace != null && namespace.length() > 0) {
            stream.println("} // namespace");
        }
    }

    /**
     * Prints C++ code to open namespace from config.
     * 
     * @param stream
     *            Stream to print to.
     * @param namespace
     *            Namespace to open
     */
    public static void printNamespaceOpen(PrintStream stream, String namespace) {
        if (namespace != null && namespace.length() > 0) {
            stream.println("namespace " + namespace);
            stream.println("{");
        }
    }

    /**
     * Prints a case inside a switch where given typeID is checked and true
     * returned.
     * 
     * @param stream
     *            Stream to print to.
     * @param typeID
     *            Type ID to check.
     * @param config
     *            Config.
     */
    public static void printTypeIDcaseReturnTrue(PrintStream stream, String typeID, Config config) {
        stream.print(config.getIndentation());
        stream.println("case " + typeID + ":");
        stream.print(config.getIndentation());
        stream.print(config.getIndentation());
        stream.println("return true;");
    }

}
