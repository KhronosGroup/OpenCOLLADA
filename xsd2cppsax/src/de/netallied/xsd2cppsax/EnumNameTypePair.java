/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import org.apache.xerces.xs.XSSimpleTypeDefinition;

/**
 * A simple class storing a C++ enum or union type name and it's corresponding
 * XSD simple type.
 * 
 */
public class EnumNameTypePair {

    private String cppTypeName;

    private XSSimpleTypeDefinition xsdType;

    /**
     * Constructor.
     */
    public EnumNameTypePair(String cppTypeName, XSSimpleTypeDefinition xsdType) {
        super();
        this.cppTypeName = cppTypeName;
        this.xsdType = xsdType;
    }

    /**
     * @return C++ type name of enum or union.
     */
    public String getCppTypeName() {
        return cppTypeName;
    }

    /**
     * @return XSD enum or union type.
     */
    public XSSimpleTypeDefinition getXsdType() {
        return xsdType;
    }
}
