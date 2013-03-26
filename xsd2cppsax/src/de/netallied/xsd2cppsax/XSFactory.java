/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax;

import org.apache.xerces.impl.dv.xs.XSSimpleTypeDecl;
import org.apache.xerces.impl.xs.XSAttributeDecl;
import org.apache.xerces.impl.xs.XSAttributeUseImpl;
import org.apache.xerces.xs.XSAttributeUse;
import org.apache.xerces.xs.XSSimpleTypeDefinition;

/**
 * Creates additional XSD objects.
 * 
 */
public class XSFactory {

    /** Name of attribute 'xmlns'. */
    public static final String ATTR_NAME_XMLNS = "xmlns";

    /**
     * Creates a {@link XSAttributeUse} object representing "xmlns" which is
     * defined in the w3c xml info set spec.
     * 
     * @see http://www.w3.org/TR/xml-infoset/#infoitem.element
     * 
     */
    public static XSAttributeUse createAttributeXmlns() {
        XSSimpleTypeDecl simpleType = new XSGeneratorSimpleType("string");
        XSAttributeDecl attr = new XSAttributeDecl();
        attr.setValues(ATTR_NAME_XMLNS, null, simpleType, (short) 0, (short) 0, null, null, null);
        XSAttributeUseImpl attrUse = new XSAttributeUseImpl();
        attrUse.fAttrDecl = attr;
        return attrUse;
    }

    /**
     * Creates a {@link XSSimpleTypeDefinition} object representing xs:anyType.
     * Required for elements with mixed content.
     * 
     */
    public static XSSimpleTypeDefinition createXSAnyType() {
        XSGeneratorSimpleType anyType = new XSGeneratorSimpleType(Constants.XSD_ANYTYPE_NAME);
        return anyType;
    }
}
