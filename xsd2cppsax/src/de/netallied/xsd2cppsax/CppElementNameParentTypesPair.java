/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import java.util.SortedSet;

import org.apache.xerces.xs.XSTypeDefinition;

/**
 * Contains a C++ element name and it's possible parent types.
 * 
 */
public class CppElementNameParentTypesPair {

    public String cppElementName;

    public SortedSet<XSTypeDefinition> parentTypes;
}
