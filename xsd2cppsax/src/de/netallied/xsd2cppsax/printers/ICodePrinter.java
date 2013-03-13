/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.printers;

import java.io.FileNotFoundException;

import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSSimpleTypeDefinition;

import de.netallied.xsd2cppsax.IGenerationDataProvider;

/**
 * Interface of printers which print a specialized version of generated public
 * parser.
 * 
 */
public interface ICodePrinter {

    /**
     * Cleans up output files
     */
    public abstract void cleanupOutputFiles();

    /**
     * @return {@link IGenerationDataProvider}.
     */
    public abstract IGenerationDataProvider getGenerationDataProvider();

    /**
     * Gives printer the possibility to generate enum specific code, e.g.
     * functions to convert enums to strings.
     * 
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     * @param simpleType
     *            XSD enum type.
     */
    public abstract void handleEnum(String cppEnumTypeName, XSSimpleTypeDefinition simpleType);

    /**
     * Gives printer the possibility to generate union specific code, e.g.
     * functions to convert unions to strings.
     * 
     * @param cppUnionTypeName
     *            Name of C++ union type.
     * @param simpleType
     *            XSD union type.
     */
    public abstract void handleUnion(String cppUnionTypeName, XSSimpleTypeDefinition simpleType);

    /**
     * Prints convenience begin[element] method to header file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @param attributesRequired
     *            Indicates if attribute data parameter is present.
     */
    public abstract void printBeginMethodToHeader(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element, boolean attributesRequired);

    /**
     * Prints convenience begin[element] method to source file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     * @param attributesRequired
     *            Indicates if attribute data parameter is present.
     */
    public abstract void printBeginMethodToSource(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element, boolean attributesRequired);

    /**
     * Prints convenience data method to header file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     */
    public abstract void printDataMethodToHeader(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element);

    /**
     * Prints convenience data method to source file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     */
    public abstract void printDataMethodToSource(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element);

    /**
     * Prints end[element] method to header file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     */
    public abstract void printEndMethodToHeader(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element);

    /**
     * Prints end[element] method to source file.
     * 
     * @param methodName
     *            Method name.
     * @param parameterList
     *            Parameter list.
     * @param cppName
     *            C++ name of element.
     * @param element
     *            XSD representation of element.
     */
    public abstract void printEndMethodToSource(String methodName, String parameterList, String cppElementName,
            XSElementDeclaration element);

    /**
     * Prints beginning of header file.
     */
    public abstract void printHeaderFileBeginning();

    /**
     * Prints end of header file.
     */
    public abstract void printHeaderFileEnd();

    /**
     * Prints new line to header.
     */
    public abstract void printNewLine();

    /**
     * Prints beginning of source file.
     */
    public abstract void printSourceFileBeginning();

    /**
     * Prints ending of source file.
     */
    public abstract void printSourceFileEnd();

    /**
     * Sets up output files.
     * 
     * @throws FileNotFoundException
     */
    public abstract void setupOutputFiles() throws FileNotFoundException;
}
