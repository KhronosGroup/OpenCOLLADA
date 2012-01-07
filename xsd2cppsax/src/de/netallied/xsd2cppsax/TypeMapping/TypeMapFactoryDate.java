package de.netallied.xsd2cppsax.TypeMapping;

/**
 * Factory to create type mappings for XSD date/time types. Uses Type mapping of
 * string.
 * 
 * TODO move type specific code templates in one (or multiple) config file(s).
 * 
 */
public class TypeMapFactoryDate extends TypeMapFactoryString implements ITypeMapFactory {

    public TypeMap createDefaultTypeMapDate() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("date");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapDateTime() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("dateTime");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapDateTimeStamp() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("dateTimeStamp");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapDayTimeDuration() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("dayTimeDuration");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapDuration() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("duration");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapGDay() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("gDay");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapGMonth() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("gMonth");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapGMonthDay() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("gMonthDay");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapGYear() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("gYear");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapGYearMonth() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("gYearMonth");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapTime() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("time");
        return typeMap;
    }

    public TypeMap createDefaultTypeMapYearMonthDuration() {
        TypeMap typeMap = createDefaultTypeMapString();
        typeMap.setXsdType("yearMonthDuration");
        return typeMap;
    }

}
