package de.netallied.xsd2cppsax.TypeMapping;

import de.netallied.xsd2cppsax.Config;

/**
 * Creates XSD to C++ type/conversion mappings.
 * 
 * <p>
 * XSD types:
 * <ul>
 * <li>anyType</li>
 * <li>anySimpleType</li>
 * <li>anyAtomicType</li>
 * 
 * <li>string</li>
 * 
 * <li>QName</li>
 * <li>NOTATION</li>
 * 
 * <li>language</li>
 * <li>normalizedString</li>
 * 
 * <li>Token</li>
 * <li>NMTOKEN</li>
 * <li>NMTOKENS</li>
 * <li>Name</li>
 * <li>NCName</li>
 * <li>ID</li>
 * <li>IDREF</li>
 * <li>IDREFS</li>
 * <li>ENTITY</li>
 * <li>ENTITIES</li>
 * 
 * <li>anyURI</li>
 * 
 * <li>long</li>
 * <li>int</li>
 * <li>short</li>
 * <li>byte</li>
 * 
 * <li>unsignedLong</li>
 * <li>unsignedInt</li>
 * <li>unsignedShort</li>
 * <li>unsignedByte</li>
 * 
 * <li>integer</li>
 * 
 * <li>positiveInteger</li>
 * <li>nonNegativeInteger</li>
 * <li>nonPositiveInteger</li>
 * <li>negativeInteger</li>
 * 
 * <li>boolean</li>
 * <li>decimal</li>
 * <li>precisionDecimal</li>
 * <li>float</li>
 * <li>double</li>
 * 
 * <li>hexBinary</li>
 * <li>base64Binary</li>
 * 
 * <li>duration</li>
 * <li>dateTime</li>
 * <li>time</li>
 * <li>date</li>
 * <li>gYearMonth</li>
 * <li>gYear</li>
 * <li>gMonthDay</li>
 * <li>gDay</li>
 * <li>gMonth</li>
 * <li>yearMonthDuration</li>
 * <li>dayTimeDuration</li>
 * <li>dateTimeStamp</li>
 * <ul>
 * </p>
 * 
 */
public interface ITypeMapFactory {

    public abstract TypeMap createDefaultTypeMapAnyAtomicType();

    public abstract TypeMap createDefaultTypeMapAnySimpleType();

    public abstract TypeMap createDefaultTypeMapAnyType();

    public abstract TypeMap createDefaultTypeMapAnyURI();

    public abstract TypeMap createDefaultTypeMapBase64Binary();

    public abstract TypeMap createDefaultTypeMapBoolean();

    public abstract TypeMap createDefaultTypeMapByte();

    public abstract TypeMap createDefaultTypeMapDate();

    public abstract TypeMap createDefaultTypeMapDateTime();

    public abstract TypeMap createDefaultTypeMapDateTimeStamp();

    public abstract TypeMap createDefaultTypeMapDayTimeDuration();

    public abstract TypeMap createDefaultTypeMapDecimal();

    public abstract TypeMap createDefaultTypeMapDouble(Config config);

    public abstract TypeMap createDefaultTypeMapDuration();

    public abstract TypeMap createDefaultTypeMapENTITIES();

    public abstract TypeMap createDefaultTypeMapENTITY();

    public abstract TypeMap createDefaultTypeMapFloat(Config config);

    public abstract TypeMap createDefaultTypeMapGDay();

    public abstract TypeMap createDefaultTypeMapGMonth();

    public abstract TypeMap createDefaultTypeMapGMonthDay();

    public abstract TypeMap createDefaultTypeMapGYear();

    public abstract TypeMap createDefaultTypeMapGYearMonth();

    public abstract TypeMap createDefaultTypeMapHexBinary();

    public abstract TypeMap createDefaultTypeMapID();

    public abstract TypeMap createDefaultTypeMapIDREF();

    public abstract TypeMap createDefaultTypeMapIDREFS();

    public abstract TypeMap createDefaultTypeMapInt();

    public abstract TypeMap createDefaultTypeMapInteger();

    public abstract TypeMap createDefaultTypeMapLanguage();

    public abstract TypeMap createDefaultTypeMapLong();

    public abstract TypeMap createDefaultTypeMapName();

    public abstract TypeMap createDefaultTypeMapNCName();

    public abstract TypeMap createDefaultTypeMapNegativeInteger();

    public abstract TypeMap createDefaultTypeMapNMTOKEN();

    public abstract TypeMap createDefaultTypeMapNMTOKENS();

    public abstract TypeMap createDefaultTypeMapNonNegativeInteger();

    public abstract TypeMap createDefaultTypeMapNonPositiveInteger();

    public abstract TypeMap createDefaultTypeMapNormalizedString();

    public abstract TypeMap createDefaultTypeMapNOTATION();

    public abstract TypeMap createDefaultTypeMapPositiveInteger();

    public abstract TypeMap createDefaultTypeMapPrecisionDecimal();

    public abstract TypeMap createDefaultTypeMapQName();

    public abstract TypeMap createDefaultTypeMapShort();

    public abstract TypeMap createDefaultTypeMapString();

    public abstract TypeMap createDefaultTypeMapTime();

    public abstract TypeMap createDefaultTypeMapToken();

    public abstract TypeMap createDefaultTypeMapUnsignedByte();

    public abstract TypeMap createDefaultTypeMapUnsignedInt();

    public abstract TypeMap createDefaultTypeMapUnsignedLong();

    public abstract TypeMap createDefaultTypeMapUnsignedShort();

    public abstract TypeMap createDefaultTypeMapYearMonthDuration();

}