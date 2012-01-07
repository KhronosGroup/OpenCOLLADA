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
