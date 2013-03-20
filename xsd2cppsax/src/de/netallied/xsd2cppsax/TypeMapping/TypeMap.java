/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.TypeMapping;

import de.netallied.xsd2cppsax.Variety;
import de.netallied.xsd2cppsax.printers.FPrintfParserPrinter;

/**
 * Contains C++ types/conversions for a XSD type. XSD types may be used as
 * attribute or as char data and they may have different varieties (
 * {@link Variety}). Furthermore they may have simple type validation facet
 * 'enumeration' in which case we generate an additional C++ type. All these
 * different cases require different C++ code to be generated. This leads to a
 * lot of code templates for each XSD type.
 * 
 */
public class TypeMap {

    /**
     * C++ type when XSD type is used as attribute with variety atomic.
     */
    private String attrAtomicType;

    /**
     * C++ code to convert XSD type to C++ type when used as attribute with
     * variety atomic.
     */
    private String attrAtomicTypeConversion;

    /**
     * C++ code required after conversion when type is used as attribute with
     * variety atomic.
     */
    private String attrAtomicTypePostConversion;

    /**
     * C++ code required before conversion when type is used as attribute with
     * variety atomic.
     */
    private String attrAtomicTypePreConversion;

    /**
     * C++ type when XSD type is used as attribute with variety list.
     */
    private String attrListType;

    /**
     * C++ code to convert XSD type to C++ type when used as attribute with
     * variety list and list items shall be validated.
     */
    private String attrListTypeConversionItemValidation;

    /**
     * C++ code to convert XSD type to C++ type when used as attribute with
     * variety list and list items shall not be validated.
     */
    private String attrListTypeConversionNoItemValidation;

    /**
     * C++ code required after conversion when type is used as attribute with
     * variety list.
     */
    private String attrListTypePostConversion;

    /**
     * C++ code required before conversion when type is used as attribute with
     * variety list.
     */
    private String attrListTypePreConversion;

    /**
     * C++ implementation of data-method when XSD type is used as char data with
     * variety atomic.
     */
    private String dataAtomicDataMethodImpl;

    /**
     * C++ implementation of data-method when XSD type is used as char data with
     * variety atomic and has simple type validation facet pattern.
     */
    private String dataAtomicDataMethodImplFacetPattern;

    /**
     * C++ type when XSD type is used as char data with variety atomic.
     */
    private String dataAtomicType;

    /**
     * C++ code to convert XSD type to C++ type when used as char data with
     * variety atomic.
     */
    private String dataAtomicTypeConversion;

    /**
     * C++ code required after conversion when type is used as char data with
     * variety atomic.
     */
    private String dataAtomicTypePostConversion;

    /**
     * C++ code required before conversion when type is used as char data with
     * variety atomic.
     */
    private String dataAtomicTypePreConversion;

    /**
     * C++ implementation of generated validateEnd method when type is used as
     * char data with variety atomic.
     */
    private String dataAtomicValidateEndImpl;

    /**
     * C++ implementation of generated validateEnd method when type is used as
     * char data with variety atomic and has simple type validation facet
     * pattern.
     */
    private String dataAtomicValidateEndImplFacetPattern;

    /**
     * C++ implementation of generated validateEnd method when type is used as
     * char data with variety list and simple type validation shall not be used.
     */
    private String dataListEnd;

    /**
     * C++ implementation of generated validateEnd method when type is used as
     * char data with variety list and simple type validation shall be used.
     */
    private String dataListEndValidation;

    /**
     * C++ type when XSD type is used as char data with variety list.
     */
    private String dataListType;

    /**
     * C++ code to convert XSD type to C++ type when used as char data with
     * variety list and simple type validation shall not be used.
     */
    private String dataListTypeConversion;

    /**
     * C++ code to convert XSD type to C++ type when used as char data with
     * variety list and simple type validation shall be used.
     */
    private String dataListTypeConversionValidation;

    /**
     * C++ code to convert XSD type to C++ type when used as attribute with
     * variety atomic and XSD type has simple type validation facet enumeration.
     */
    private String enumAttrAtomicTypeConversion;

    /**
     * C++ code required after conversion when type is used as attribute with
     * variety atomic and XSD type has simple type validation facet enumeration.
     */
    private String enumAttrAtomicTypePostConversion;

    /**
     * C++ code required before conversion when type is used as attribute with
     * variety atomic and XSD type has simple type validation facet enumeration.
     */
    private String enumAttrAtomicTypePreConversion;

    /**
     * C++ code to convert XSD type to C++ type when used as char data with
     * variety atomic and XSD type has simple type validation facet enumeration.
     */
    private String enumDataAtomicTypeConversion;

    /**
     * C++ implementation of generated validateEnd method when type is used as
     * char data with variety list and XSD type has simple type validation facet
     * enumeration.
     */
    private String enumDataListEnd;

    /**
     * C++ code to convert XSD type to C++ type when used as char data with
     * variety list and XSD type has simple type validation facet enumeration.
     */
    private String enumDataListTypeConversion;

    /**
     * C++ code to initialize C++ type. Required when C++ classes are used.
     */
    private String initialize;

    /**
     * C++ code required before initialization of C++ type when XSD type is used
     * with variety atomic. Required when C++ classes are used.
     */
    private String initializePreAtomic;

    /**
     * C++ code required before initialization of C++ type when XSD type is used
     * with variety list. Required when C++ classes are used.
     */
    private String initializePreList;

    /**
     * C++ code to convert C++ type to a C++ string. Used by
     * {@link FPrintfParserPrinter}. Required when C++ classes are used.
     */
    private String toString;

    /**
     * C++ type when XSD type is used as member of a XSD type with variety
     * union.
     */
    private String unionAtomicType;

    /**
     * C++ code to convert XSD union member type.
     */
    private String unionAtomicTypeConversion;

    /**
     * <p>
     * C++ Type a XSD enum is based on.
     * </p>
     * <p>
     * E.g. string:
     * </p>
     * 
     * <pre>
     *     &lt;simpleType name=&quot;stringEnumType&quot;&gt;
     *         &lt;restriction base=&quot;string&quot;&gt;
     *             &lt;enumeration value=&quot;bli&quot; /&gt;
     *             &lt;enumeration value=&quot;bla&quot; /&gt;
     *             &lt;enumeration value=&quot;blub&quot; /&gt;
     *         &lt;/restriction&gt;
     *     &lt;/simpleType&gt;
     * </pre>
     * 
     * or float:
     * 
     * <pre>
     *     &lt;simpleType name=&quot;floatEnumType&quot;&gt;
     *         &lt;restriction base=&quot;float&quot;&gt;
     *             &lt;enumeration value=&quot;1.1&quot; /&gt;
     *             &lt;enumeration value=&quot;2.2&quot; /&gt;
     *             &lt;enumeration value=&quot;3.3&quot; /&gt;
     *         &lt;/restriction&gt;
     *     &lt;/simpleType&gt;
     * </pre>
     */
    private String unionEnumBaseType;

    /**
     * C++ code to convert XSD enum base type.
     * 
     * @see #unionEnumBaseType
     */
    private String unionEnumBaseTypeConversion;

    /**
     * Name of XSD type this object represents.
     */
    private String xsdType;

    /**
     * Constructor.
     */
    public TypeMap() {

    }

    /**
     * @see #attrAtomicType
     */
    public String getAttrAtomicType() {
        return attrAtomicType;
    }

    /**
     * @see #attrAtomicTypeConversion
     */
    public String getAttrAtomicTypeConversion() {
        return attrAtomicTypeConversion;
    }

    /**
     * @see #attrAtomicTypePostConversion
     */
    public String getAttrAtomicTypePostConversion() {
        return attrAtomicTypePostConversion;
    }

    /**
     * @see #attrAtomicTypePreConversion
     */
    public String getAttrAtomicTypePreConversion() {
        return attrAtomicTypePreConversion;
    }

    /**
     * @see #attrListType
     */
    public String getAttrListType() {
        return attrListType;
    }

    /**
     * @see #attrListTypeConversionItemValidation
     */
    public String getAttrListTypeConversionItemValidation() {
        return attrListTypeConversionItemValidation;
    }

    /**
     * @see #attrListTypeConversionNoItemValidation
     */
    public String getAttrListTypeConversionNoItemValidation() {
        return attrListTypeConversionNoItemValidation;
    }

    /**
     * @see #attrListTypePostConversion
     */
    public String getAttrListTypePostConversion() {
        return attrListTypePostConversion;
    }

    /**
     * @see #attrListTypePreConversion
     */
    public String getAttrListTypePreConversion() {
        return attrListTypePreConversion;
    }

    /**
     * @see #dataAtomicDataMethodImpl
     */
    public String getDataAtomicDataMethodImpl() {
        return dataAtomicDataMethodImpl;
    }

    /**
     * @see #dataAtomicDataMethodImplFacetPattern
     */
    public String getDataAtomicDataMethodImplFacetPattern() {
        return dataAtomicDataMethodImplFacetPattern;
    }

    /**
     * @see #dataAtomicType
     */
    public String getDataAtomicType() {
        return dataAtomicType;
    }

    /**
     * @see #dataAtomicTypeConversion
     */
    public String getDataAtomicTypeConversion() {
        return dataAtomicTypeConversion;
    }

    /**
     * @see #dataAtomicTypePostConversion
     */
    public String getDataAtomicTypePostConversion() {
        return dataAtomicTypePostConversion;
    }

    /**
     * @see #dataAtomicTypePreConversion
     */
    public String getDataAtomicTypePreConversion() {
        return dataAtomicTypePreConversion;
    }

    /**
     * @see #dataAtomicValidateEndImpl
     */
    public String getDataAtomicValidateEndImpl() {
        return dataAtomicValidateEndImpl;
    }

    /**
     * @see #dataAtomicValidateEndImplFacetPattern
     */
    public String getDataAtomicValidateEndImplFacetPattern() {
        return dataAtomicValidateEndImplFacetPattern;
    }

    /**
     * @see #dataListEnd
     */
    public String getDataListEnd() {
        return dataListEnd;
    }

    /**
     * @see #dataListEndValidation
     */
    public String getDataListEndValidation() {
        return dataListEndValidation;
    }

    /**
     * @see #dataListType
     */
    public String getDataListType() {
        return dataListType;
    }

    /**
     * @see #dataListTypeConversion
     */
    public String getDataListTypeConversion() {
        return dataListTypeConversion;
    }

    /**
     * @see #dataListTypeConversionValidation
     */
    public String getDataListTypeConversionValidation() {
        return dataListTypeConversionValidation;
    }

    /**
     * @see #enumAttrAtomicTypeConversion
     */
    public String getEnumAttrAtomicTypeConversion() {
        return enumAttrAtomicTypeConversion;
    }

    /**
     * @see #enumAttrAtomicTypePostConversion
     */
    public String getEnumAttrAtomicTypePostConversion() {
        return enumAttrAtomicTypePostConversion;
    }

    /**
     * @see #enumAttrAtomicTypePreConversion
     */
    public String getEnumAttrAtomicTypePreConversion() {
        return enumAttrAtomicTypePreConversion;
    }

    /**
     * @see #enumDataAtomicTypeConversion
     */
    public String getEnumDataAtomicTypeConversion() {
        return enumDataAtomicTypeConversion;
    }

    /**
     * @see #enumDataListEnd
     */
    public String getEnumDataListEnd() {
        return enumDataListEnd;
    }

    /**
     * @see #enumDataListTypeConversion
     */
    public String getEnumDataListTypeConversion() {
        return enumDataListTypeConversion;
    }

    /**
     * @see #initialize
     */
    public String getInitialize() {
        return initialize;
    }

    /**
     * @see #initializePreAtomic
     */
    public String getInitializePreAtomic() {
        return initializePreAtomic;
    }

    /**
     * @see #initializePreList
     */
    public String getInitializePreList() {
        return initializePreList;
    }

    /**
     * @see #toString
     */
    public String getToString() {
        return toString;
    }

    /**
     * @see #unionAtomicType
     */
    public String getUnionAtomicType() {
        return unionAtomicType;
    }

    /**
     * @see #unionAtomicTypeConversion
     */
    public String getUnionAtomicTypeConversion() {
        return unionAtomicTypeConversion;
    }

    /**
     * @see #unionEnumBaseType
     */
    public String getUnionEnumBaseType() {
        return unionEnumBaseType;
    }

    /**
     * @see #unionEnumBaseTypeConversion
     */
    public String getUnionEnumBaseTypeConversion() {
        return unionEnumBaseTypeConversion;
    }

    /**
     * @see #xsdType
     */
    public String getXsdType() {
        return xsdType;
    }

    /**
     * @see #attrAtomicType
     */
    public void setAttrAtomicType(String attrAtomicType) {
        this.attrAtomicType = attrAtomicType;
    }

    /**
     * @see #attrAtomicTypeConversion
     */
    public void setAttrAtomicTypeConversion(String attrAtomicTypeConversion) {
        this.attrAtomicTypeConversion = attrAtomicTypeConversion;
    }

    /**
     * @see #attrAtomicTypePostConversion
     */
    public void setAttrAtomicTypePostConversion(String attrAtomicTypePostConversion) {
        this.attrAtomicTypePostConversion = attrAtomicTypePostConversion;
    }

    /**
     * @see #attrAtomicTypePreConversion
     */
    public void setAttrAtomicTypePreConversion(String attrAtomicTypePreConversion) {
        this.attrAtomicTypePreConversion = attrAtomicTypePreConversion;
    }

    /**
     * @see #attrListType
     */
    public void setAttrListType(String attrListType) {
        this.attrListType = attrListType;
    }

    /**
     * @see #attrListTypeConversionItemValidation
     */
    public void setAttrListTypeConversionItemValidation(String attrListTypeConversionItemValidation) {
        this.attrListTypeConversionItemValidation = attrListTypeConversionItemValidation;
    }

    /**
     * @see #attrListTypeConversionNoItemValidation
     */
    public void setAttrListTypeConversionNoItemValidation(String attrListTypeConversionNoItemValidation) {
        this.attrListTypeConversionNoItemValidation = attrListTypeConversionNoItemValidation;
    }

    /**
     * @see #attrListTypePostConversion
     */
    public void setAttrListTypePostConversion(String attrListTypePostConversion) {
        this.attrListTypePostConversion = attrListTypePostConversion;
    }

    /**
     * @see #attrListTypePreConversion
     */
    public void setAttrListTypePreConversion(String attrListTypePreConversion) {
        this.attrListTypePreConversion = attrListTypePreConversion;
    }

    /**
     * @see #dataAtomicDataMethodImpl
     */
    public void setDataAtomicDataMethodImpl(String dataAtomicDataMethodImpl) {
        this.dataAtomicDataMethodImpl = dataAtomicDataMethodImpl;
    }

    /**
     * @see #dataAtomicDataMethodImplFacetPattern
     */
    public void setDataAtomicDataMethodImplFacetPattern(String dataAtomicDataMethodImplFacetPattern) {
        this.dataAtomicDataMethodImplFacetPattern = dataAtomicDataMethodImplFacetPattern;
    }

    /**
     * @see #dataAtomicType
     */
    public void setDataAtomicType(String dataAtomicType) {
        this.dataAtomicType = dataAtomicType;
    }

    /**
     * @see #dataAtomicTypeConversion
     */
    public void setDataAtomicTypeConversion(String dataAtomicTypeConversion) {
        this.dataAtomicTypeConversion = dataAtomicTypeConversion;
    }

    /**
     * @see #dataAtomicTypePostConversion
     */
    public void setDataAtomicTypePostConversion(String dataAtomicTypePostConversion) {
        this.dataAtomicTypePostConversion = dataAtomicTypePostConversion;
    }

    /**
     * @see #dataAtomicTypePreConversion
     */
    public void setDataAtomicTypePreConversion(String dataAtomicTypePreConversion) {
        this.dataAtomicTypePreConversion = dataAtomicTypePreConversion;
    }

    /**
     * @see #dataAtomicValidateEndImpl
     */
    public void setDataAtomicValidateEndImpl(String dataAtomicValidateEndImpl) {
        this.dataAtomicValidateEndImpl = dataAtomicValidateEndImpl;
    }

    /**
     * @see #dataAtomicValidateEndImplFacetPattern
     */
    public void setDataAtomicValidateEndImplFacetPattern(String dataAtomicValidateEndImplFacetPattern) {
        this.dataAtomicValidateEndImplFacetPattern = dataAtomicValidateEndImplFacetPattern;
    }

    /**
     * @see #dataListEnd
     */
    public void setDataListEnd(String dataListEnd) {
        this.dataListEnd = dataListEnd;
    }

    /**
     * @see #dataListEndValidation
     */
    public void setDataListEndValidation(String dataListEndValidation) {
        this.dataListEndValidation = dataListEndValidation;
    }

    /**
     * @see #dataListType
     */
    public void setDataListType(String dataListType) {
        this.dataListType = dataListType;
    }

    /**
     * @see #dataListTypeConversion
     */
    public void setDataListTypeConversion(String dataListTypeConversion) {
        this.dataListTypeConversion = dataListTypeConversion;
    }

    /**
     * @see #dataListTypeConversionValidation
     */
    public void setDataListTypeConversionValidation(String dataListTypeConversionValidation) {
        this.dataListTypeConversionValidation = dataListTypeConversionValidation;
    }

    /**
     * @see #enumAttrAtomicTypeConversion
     */
    public void setEnumAttrAtomicTypeConversion(String enumAttrAtomicTypeConversion) {
        this.enumAttrAtomicTypeConversion = enumAttrAtomicTypeConversion;
    }

    /**
     * @see #enumAttrAtomicTypePostConversion
     */
    public void setEnumAttrAtomicTypePostConversion(String enumAttrAtomicTypePostConversion) {
        this.enumAttrAtomicTypePostConversion = enumAttrAtomicTypePostConversion;
    }

    /**
     * @see #enumAttrAtomicTypePreConversion
     */
    public void setEnumAttrAtomicTypePreConversion(String enumAttrAtomicTypePreConversion) {
        this.enumAttrAtomicTypePreConversion = enumAttrAtomicTypePreConversion;
    }

    /**
     * @see #enumDataAtomicTypeConversion
     */
    public void setEnumDataAtomicTypeConversion(String enumDataAtomicTypeConversion) {
        this.enumDataAtomicTypeConversion = enumDataAtomicTypeConversion;
    }

    /**
     * @see #enumDataListEnd
     */
    public void setEnumDataListEnd(String enumDataListEnd) {
        this.enumDataListEnd = enumDataListEnd;
    }

    /**
     * @see #enumDataListTypeConversion
     */
    public void setEnumDataListTypeConversion(String enumDataListTypeConversion) {
        this.enumDataListTypeConversion = enumDataListTypeConversion;
    }

    /**
     * @see #initialize
     */
    public void setInitialize(String initialize) {
        this.initialize = initialize;
    }

    /**
     * @see #initializePreAtomic
     */
    public void setInitializePreAtomic(String initializePreAtomic) {
        this.initializePreAtomic = initializePreAtomic;
    }

    /**
     * @see #initializePreList
     */
    public void setInitializePreList(String initializePreList) {
        this.initializePreList = initializePreList;
    }

    /**
     * @see #toString
     */
    public void setToString(String toString) {
        this.toString = toString;
    }

    /**
     * @see #unionAtomicType
     */
    public void setUnionAtomicType(String unionAtomicType) {
        this.unionAtomicType = unionAtomicType;
    }

    /**
     * @see #unionAtomicTypeConversion
     */
    public void setUnionAtomicTypeConversion(String unionAtomicTypeConversion) {
        this.unionAtomicTypeConversion = unionAtomicTypeConversion;
    }

    /**
     * @see #unionEnumBaseType
     */
    public void setUnionEnumBaseType(String unionEnumBaseType) {
        this.unionEnumBaseType = unionEnumBaseType;
    }

    /**
     * @see #unionEnumBaseTypeConversion
     */
    public void setUnionEnumBaseTypeConversion(String unionEnumBaseTypeConversion) {
        this.unionEnumBaseTypeConversion = unionEnumBaseTypeConversion;
    }

    /**
     * @see #xsdType
     */
    public void setXsdType(String xsdType) {
        this.xsdType = xsdType;
    }
}
