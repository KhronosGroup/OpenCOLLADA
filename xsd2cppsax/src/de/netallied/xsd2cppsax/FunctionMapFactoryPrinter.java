package de.netallied.xsd2cppsax;

import java.io.PrintStream;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSTypeDefinition;

/**
 * Prints specialized function maps which allow parsing of child elements of
 * given element only. Used in OpenCOLLADA to create 'parser flags'.
 * 
 */
public class FunctionMapFactoryPrinter extends AbstractStackBasedTraverser {

    /** Collected element usage data. Key: XSD element name. */
    private Map<String, ElementUsage> completeElementUsage;

    /** Mapping of XSD element to C++ element name. */
    private Map<XSElementDeclaration, CppElementNameParentTypesPair> elementNameMapping;

    /** Handled ancestors. To avoid endless recursion. */
    private Set<XSElementDeclaration> handledAncestors = new HashSet<XSElementDeclaration>();

    /** Handled children. To avoid endless recursion. */
    private Set<XSElementDeclaration> handledChildren = new HashSet<XSElementDeclaration>();

    /** C++ Header file to print to. */
    private PrintStream headerFile;

    /** Max depth of children to be included in function map. */
    private int maxDepth;

    /** C++ Source file to print to. */
    private PrintStream sourceFile;

    /** C++ element name of element to start with. */
    private String startElementCppName;

    /** XSD substitution groups to collect correct children and ancestors. */
    private Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups;;

    /**
     * Constructor.
     */
    public FunctionMapFactoryPrinter(Config config,
            Map<XSElementDeclaration, CppElementNameParentTypesPair> elementNameMapping, PrintStream headerFile,
            PrintStream sourceFile, String startElementCppName,
            Map<XSElementDeclaration, List<XSElementDeclaration>> substitutionGroups,
            Map<String, ElementUsage> completeElementUsage, int maxDepth) {
        super(config);
        this.elementNameMapping = elementNameMapping;
        this.headerFile = headerFile;
        this.sourceFile = sourceFile;
        this.startElementCppName = startElementCppName;
        this.substitutionGroups = substitutionGroups;
        this.completeElementUsage = completeElementUsage;
        this.maxDepth = maxDepth;
    }

    /**
     * Collects ancestors of given elements and their ancestors as well.
     * 
     * @param element
     *            Element to start with.
     * @return Ancestors.
     */
    protected SortedSet<XSElementDeclaration> collectAncestorsOfAncestor(XSElementDeclaration element) {
        ElementUsage elementUsage = completeElementUsage.get(element.getName());
        List<List<XSElementDeclaration>> ancestors = elementUsage
                .collectAncestorsOfElement(element, substitutionGroups);
        SortedSet<XSElementDeclaration> sortedAncestors = new TreeSet<XSElementDeclaration>(new XSElementComparator());
        for (List<XSElementDeclaration> ancestorList : ancestors) {
            for (XSElementDeclaration ancestor : ancestorList) {
                sortedAncestors.add(ancestor);
                if (!handledAncestors.contains(ancestor)) {
                    handledAncestors.add(ancestor);
                    SortedSet<XSElementDeclaration> ancestorsOfAncestor = collectAncestorsOfAncestor(ancestor);
                    sortedAncestors.addAll(ancestorsOfAncestor);
                }
            }
        }
        return sortedAncestors;
    }

    /**
     * @return C++ function name.
     */
    protected String createFunctionName() {
        String functionName = "createFunctionMap__" + startElementCppName;
        if (maxDepth == -1) {
            functionName += "__allChildren";
        } else if (maxDepth == 1) {
            functionName += "__" + "1level";
        } else {
            functionName += "__" + maxDepth + "levels";
        }
        return functionName;
    }

    /**
     * @return Name of C++ type of function map.
     */
    protected String createMapType() {
        return config.getClassNamePrivate() + "::ElementFunctionMap";
    }

    /**
     * @return Name of C++ type of function map in method declaration.
     */
    protected String createMapTypeForMethodDecl() {
        return "const " + createMapType() + "&";
    }

    /**
     * @return C++ name of function map variable.
     */
    protected String createMapVariableName() {
        return "functionMap";
    }

    /**
     * {@inheritDoc}
     * 
     * @see de.netallied.xsd2cppsax.AbstractXSTraverser#handleElement(com.sun.org.apache.xerces.internal.xs.XSElementDeclaration)
     */
    @Override
    public boolean handleElement(XSElementDeclaration element) {
        if (!checkStack(element)) {
            return true;
        }

        String parentElementName = null;
        if (!getElementStack().isEmpty()) {
            parentElementName = getElementStack().peek().getName();
        }
        boolean ignoreElement = false;
        if (parentElementName == null) {
            if (!config.getRootElementName().equals(element.getName())) {
                ignoreElement = true;
            }
        }

        if (!ignoreElement) {
            String cppElementName = elementNameMapping.get(element).cppElementName;
            if (cppElementName.equals(startElementCppName)) {
                printFunction(element);
                return false;
            }
        }

        getElementStack().push(element);
        boolean retVal = super.handleElement(element);
        getElementStack().pop();
        return retVal;
    }

    /**
     * Prints factory function for given element.
     * 
     * @param element
     *            Element to print function for.
     */
    protected void printFunction(XSElementDeclaration element) {
        headerFile.print("static " + createMapTypeForMethodDecl() + " ");
        headerFile.println(createFunctionName() + "();");
        headerFile.println();

        sourceFile.println(config.getOutputSourceFileMethodDelimiter());
        sourceFile.print(createMapTypeForMethodDecl() + " ");
        sourceFile.print(config.getClassNameFunctionMapFactory() + "::");
        sourceFile.println(createFunctionName() + "() {");
        sourceFile.println("static " + createMapType() + " " + createMapVariableName() + ";");
        sourceFile.println("static bool mapFilled = false;");
        sourceFile.println("if ( !mapFilled )");
        sourceFile.println("{");

        printMapEntriesForAncestors(element);

        handledChildren.add(element);
        Util.printFunctionMapEntry(createMapVariableName(), Util.createElementNameHashIdentifier(startElementCppName),
                startElementCppName, sourceFile, config, true);

        printMapEntriesForChildren(element, 1);

        sourceFile.println("mapFilled = true;");
        sourceFile.println("}");
        sourceFile.println("return " + createMapVariableName() + ";");
        sourceFile.println("}");
        sourceFile.println();
    }

    /**
     * Prints map entries for ancestors of given element.
     * 
     * @param element
     *            Element to handle.
     */
    protected void printMapEntriesForAncestors(XSElementDeclaration element) {
        SortedSet<XSElementDeclaration> sortedAncestors = collectAncestorsOfAncestor(element);

        for (XSElementDeclaration ancestor : sortedAncestors) {
            handledChildren.add(ancestor);
            String cppName = elementNameMapping.get(ancestor).cppElementName;
            Util.printFunctionMapEntry(createMapVariableName(), Util.createElementNameHashIdentifier(cppName), cppName,
                    sourceFile, config, true);
        }
    }

    /**
     * Prints function map entries for child elements.
     * 
     * @param element
     *            Element to start with.
     * @param depth
     *            Depth of how many levels of children shall be handled. -1 for
     *            infinite.
     */
    protected void printMapEntriesForChildren(XSElementDeclaration element, int depth) {
        DirectChildrenCollector childrenCollector = new DirectChildrenCollector();
        SortedSet<XSElementDeclaration> children = childrenCollector.collect(element.getTypeDefinition(),
                substitutionGroups, new HashSet<XSTypeDefinition>());
        if (children != null) {
            for (XSElementDeclaration child : children) {
                if (!handledChildren.contains(child)) {
                    String cppName = elementNameMapping.get(child).cppElementName;
                    Util.printFunctionMapEntry(createMapVariableName(), Util.createElementNameHashIdentifier(cppName),
                            cppName, sourceFile, config, true);
                }
            }
            if (maxDepth == -1 || depth < maxDepth) {
                for (XSElementDeclaration child : children) {
                    if (!handledChildren.contains(child)) {
                        handledChildren.add(child);
                        printMapEntriesForChildren(child, depth++);
                    }
                }
            }
        }
    }
}
