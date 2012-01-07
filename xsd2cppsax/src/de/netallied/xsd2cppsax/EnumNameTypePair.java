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
