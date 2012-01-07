/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.TypeMapping;

import java.util.HashMap;
import java.util.Map;

import de.netallied.xsd2cppsax.Config;

/**
 * Concrete Factory to be used by clients.
 * 
 */
public class TypeMapFactory extends TypeMapFactoryDate implements ITypeMapFactory {

    public Map<String, TypeMap> createDefaultTypeMap(Config config) {
        Map<String, TypeMap> map = new HashMap<String, TypeMap>();
        TypeMap typeMap = null;

        typeMap = createDefaultTypeMapAnyType();
        map.put(typeMap.getXsdType(), typeMap);

        typeMap = createDefaultTypeMapAnySimpleType();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapAnyAtomicType();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapString();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapQName();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapNOTATION();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapLanguage();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapNormalizedString();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapToken();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapNMTOKEN();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapNMTOKENS();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapName();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapNCName();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapID();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapIDREF();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapIDREFS();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapENTITY();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapENTITIES();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapAnyURI();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapLong();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapInt();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapShort();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapByte();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapUnsignedLong();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapUnsignedInt();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapUnsignedShort();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapUnsignedByte();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapInteger();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapPositiveInteger();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapNonNegativeInteger();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapNonPositiveInteger();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapNegativeInteger();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapBoolean();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapDecimal();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapPrecisionDecimal();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapFloat(config);
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapDouble(config);
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapHexBinary();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapBase64Binary();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapDuration();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapDateTime();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapTime();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapDate();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapGYearMonth();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapGYear();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapGMonthDay();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapGDay();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapGMonth();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapYearMonthDuration();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapDayTimeDuration();
        map.put(typeMap.getXsdType(), typeMap);
        typeMap = createDefaultTypeMapDateTimeStamp();
        map.put(typeMap.getXsdType(), typeMap);

        return map;
    }
}
