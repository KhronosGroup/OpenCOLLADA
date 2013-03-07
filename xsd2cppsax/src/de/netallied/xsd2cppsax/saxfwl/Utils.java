/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.saxfwl;

import java.util.ArrayList;
import java.util.List;

import de.netallied.xsd2Cppsax.saxfwl.ClassType;
import de.netallied.xsd2Cppsax.saxfwl.MethodType;
import de.netallied.xsd2Cppsax.saxfwl.SpecificType;
import de.netallied.xsd2Cppsax.saxfwl.VariableType;
import de.netallied.xsd2cppsax.saxfwl.model.Version;

/**
 * Utility methods for saxfwl generator.
 * 
 */
public class Utils {

    /**
     * Creates version specific class name.
     */
    public static String createClassName(String className, Version version) {
        return className + version.getVersion();
    }

    /**
     * Creates header file name (without path) of given class.
     */
    public static String createHeaderFileName(String namespace, String className) {
        return namespace + className + ".h";
    }

    /**
     * Finds correct base class.
     */
    public static String findCorrectBaseClass(Version version, ClassType classType) {
        String classTypeBaseClass = classType.getBaseClass();
        if (classTypeBaseClass != null && classTypeBaseClass.length() > 0) {
            return createClassName(classTypeBaseClass, version);
        }
        return version.getBaseClass();
    }

    /**
     * Finds correct parameter list. If specific has it's own, that one is used.
     * If specific don't has parameters the one of method is used.
     * 
     */
    public static List<VariableType> findCorrectParameterList(MethodType method, SpecificType specific) {
        if (!specific.getParameterList().isEmpty()) {
            return specific.getParameterList();
        } else if (!method.getParameterList().isEmpty()) {
            return method.getParameterList();
        }
        return new ArrayList<VariableType>();
    }

    /**
     * Finds out which file must be included for base class.
     */
    public static String findCorrectVersionInclude(Version version, ClassType classType) {
        String baseInclude = classType.getBaseInclude();
        if (baseInclude != null && baseInclude.length() > 0) {
            String baseFileName = baseInclude.substring(0, baseInclude.lastIndexOf(".h"));
            return baseFileName + version.getVersion() + ".h";
        }
        return version.getInclude();
    }
}
