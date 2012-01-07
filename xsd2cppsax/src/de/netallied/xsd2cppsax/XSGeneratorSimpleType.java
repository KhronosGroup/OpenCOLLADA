package de.netallied.xsd2cppsax;

import org.apache.xerces.impl.dv.xs.XSSimpleTypeDecl;

/**
 * Allows creation of additional XSD types.
 * 
 * @see XSFactory.
 * 
 */
public class XSGeneratorSimpleType extends XSSimpleTypeDecl {

    public XSGeneratorSimpleType(String name) {
        super(null, name, /* DV_STRING */PRIMITIVE_STRING, ORDERED_FALSE, false, false, false, false, PRIMITIVE_STRING);
    }
}
