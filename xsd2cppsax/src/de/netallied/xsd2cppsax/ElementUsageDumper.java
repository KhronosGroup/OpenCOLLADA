XXXXXAAAAAXXXXX
package de.netallied.xsd2cppsax;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import org.apache.xerces.xs.XSElementDeclaration;

/**
 * Dumps out different data for debugging purposes, e.g. element usage data.
 * 
 */
public class ElementUsageDumper {

    /**
     * Dumps out element usage data.
     */
    public void dumpElementUsage(Map<String, ElementUsage> elementUsage) throws FileNotFoundException {
        PrintStream stream = new PrintStream("element_usage.txt");

        for (Entry<String, ElementUsage> usage : elementUsage.entrySet()) {
            stream.println(usage.getKey());

            for (List<XSElementDeclaration> ancestors : usage.getValue().getAncestors()) {
                stream.print("    ");

                for (XSElementDeclaration ancestor : ancestors) {
                    stream.print(ancestor.getName() + ", ");
                }

                stream.println();
            }

            stream.println();
        }

        stream.close();
    }

    /**
     * Dumps out a map.
     */
    private void dumpMap(PrintStream stream, Map<String, String> map) {
        for (String key : map.keySet()) {
            stream.println("    " + key + " -> " + map.get(key));
        }
    }

    /**
     * Dumps out a parent name and it's child elements.
     */
    public void dumpMultipleElementsPerParent(Map<String, List<XSElementDeclaration>> elementsPerParent)
            throws FileNotFoundException {
        PrintStream stream = new PrintStream("multiple_elements_per_parent.txt");

        for (String parentName : elementsPerParent.keySet()) {
            stream.println(parentName);

            for (XSElementDeclaration element : elementsPerParent.get(parentName)) {
                stream.print("    ");
                stream.println(element.getName());
            }
        }
    }

    /**
     * Dumps out type mapping.
     */
    public void dumpTypeMapping(Config config) throws FileNotFoundException {
        PrintStream stream = new PrintStream("type_mapping.txt");

        // avoid "unused" warning
        dumpMap(stream, new HashMap<String, String>());
        //
        // Map<String, String> simpleAttrAtomicTypeMapping =
        // config.getSimpleAttrAtomicTypeMapping();
        // stream.println("AttrAtomicTypeMapping");
        // dumpMap(stream, simpleAttrAtomicTypeMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleAttrAtomicTypePreConversionMapping = config
        // .getSimpleAttrAtomicTypePreConversionMapping();
        // stream.println("AttrAtomicTypePreConversionMapping");
        // dumpMap(stream, simpleAttrAtomicTypePreConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleAttrAtomicTypeConversionMapping =
        // config.getSimpleAttrAtomicTypeConversionMapping();
        // stream.println("AttrAtomicTypeConversionMapping");
        // dumpMap(stream, simpleAttrAtomicTypeConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleAttrAtomicTypePostConversionMapping =
        // config
        // .getSimpleAttrAtomicTypePostConversionMapping();
        // stream.println("AttrAtomicTypePostConversionMapping");
        // dumpMap(stream, simpleAttrAtomicTypePostConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleAttrListTypeMapping =
        // config.getSimpleAttrListTypeMapping();
        // stream.println("AttrListTypeMapping");
        // dumpMap(stream, simpleAttrListTypeMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleAttrListTypePreConversionMapping =
        // config.getSimpleAttrListTypePreConversionMapping();
        // stream.println("AttrListTypePreConversionMapping");
        // dumpMap(stream, simpleAttrListTypePreConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleAttrListTypeConversionMapping =
        // config.getSimpleAttrListTypeConversionMappingNoItemValidation();
        // stream.println("AttrListTypeConversionMapping");
        // dumpMap(stream, simpleAttrListTypeConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleAttrListTypePostConversionMapping = config
        // .getSimpleAttrListTypePostConversionMapping();
        // stream.println("AttrListTypePostConversionMapping");
        // dumpMap(stream, simpleAttrListTypePostConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleDataAtomicTypeMapping =
        // config.getSimpleDataAtomicTypeMapping();
        // stream.println("DataAtomicTypeMapping");
        // dumpMap(stream, simpleDataAtomicTypeMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleDataAtomicTypePreConversionMapping = config
        // .getSimpleDataAtomicTypePreConversionMapping();
        // stream.println("DataAtomicTypePreConversionMapping");
        // dumpMap(stream, simpleDataAtomicTypePreConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleDataAtomicTypeConversionMapping =
        // config.getSimpleDataAtomicTypeConversionMapping();
        // stream.println("DataAtomicTypeConversionMapping");
        // dumpMap(stream, simpleDataAtomicTypeConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleDataAtomicTypePostConversionMapping =
        // config
        // .getSimpleDataAtomicTypePostConversionMapping();
        // stream.println("DataAtomicTypePostConversionMapping");
        // dumpMap(stream, simpleDataAtomicTypePostConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleDataListTypeMapping =
        // config.getSimpleDataListTypeMapping();
        // stream.println("DataListTypeMapping");
        // dumpMap(stream, simpleDataListTypeMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        // Map<String, String> simpleDataListTypeConversionMapping =
        // config.getSimpleDataListTypeConversionMapping();
        // stream.println("DataListTypeConversionMapping");
        // dumpMap(stream, simpleDataListTypeConversionMapping);
        // stream.println(
        // "***********************************************************");
        // stream.println();
        // stream.println();
        //
        stream.close();
    }
}
