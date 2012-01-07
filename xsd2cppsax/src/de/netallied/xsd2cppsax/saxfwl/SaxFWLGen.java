package de.netallied.xsd2cppsax.saxfwl;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

import de.netallied.xsd2Cppsax.saxfwl.ClassType;
import de.netallied.xsd2Cppsax.saxfwl.ConfigType;
import de.netallied.xsd2Cppsax.saxfwl.CtorType;
import de.netallied.xsd2Cppsax.saxfwl.InitlistType;
import de.netallied.xsd2Cppsax.saxfwl.MethodType;
import de.netallied.xsd2Cppsax.saxfwl.RootType;
import de.netallied.xsd2Cppsax.saxfwl.SaxfwlDocument;
import de.netallied.xsd2Cppsax.saxfwl.SpecificType;
import de.netallied.xsd2Cppsax.saxfwl.VariableType;
import de.netallied.xsd2Cppsax.saxfwl.VersionType;
import de.netallied.xsd2cppsax.Util;
import de.netallied.xsd2cppsax.printers.PrinterUtils;
import de.netallied.xsd2cppsax.saxfwl.model.GlobalConfig;
import de.netallied.xsd2cppsax.saxfwl.model.Version;

/**
 * <p>
 * Code generator for COLLADASaxFrameworkLoader. Generates classes which map
 * methods of different COLLADA versions.
 * </p>
 * <p>
 * Generate XSD parsing code with:
 * 
 * <pre>
 * scomp -out saxfwlxsd.jar -javasource 1.5 -compiler %JAVA_HOME%\bin\javac -src src_dir saxfwl.xsd
 * </pre>
 * 
 * </p>
 * 
 */
public class SaxFWLGen {

    /** Return type of generated methods. */
    public static final String RETURN_TYPE = "bool";

    /** Configuration of this code generator. */
    private GlobalConfig config;

    /**
     * Finds out if given class contains at least one method which is specific
     * for given version.
     */
    protected boolean classContainsSpecificForVersion(ClassType classType, Version version) {
        for (MethodType method : classType.getMethodList()) {
            for (SpecificType specific : method.getSpecificList()) {
                if (specific.getVersion() == Integer.parseInt(version.getVersion())) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Retrieves config info from config file.
     * 
     * @param configType
     *            Config xml element.
     */
    protected GlobalConfig parseConfig(ConfigType configType) {
        List<Version> versionList = new ArrayList<Version>();
        for (VersionType verType : configType.getVersionList()) {
            versionList.add(new Version(verType.getBaseClass(), verType.getInclude(), verType.getStringValue()));
        }
        String header = configType.getHeader();
        String namespace = configType.getNamespace();
        String outpathBaseInc = Util.replaceEnvVar(configType.getOutpathBaseInc());
        String outpathBaseSrc = Util.replaceEnvVar(configType.getOutpathBaseSrc());
        List<String> includeHeaderList = new ArrayList<String>();
        for (String include : configType.getIncludeHeaderList()) {
            includeHeaderList.add(include);
        }
        List<String> includeImplList = new ArrayList<String>();
        for (String include : configType.getIncludeImplList()) {
            includeImplList.add(include);
        }
        List<String> forwardDeclList = new ArrayList<String>();
        for (String forwardDecl : configType.getForwardDeclList()) {
            forwardDeclList.add(forwardDecl);
        }

        return new GlobalConfig(outpathBaseInc, outpathBaseSrc, forwardDeclList, header, includeHeaderList,
                includeImplList, namespace, versionList);
    }

    /**
     * Prints beginning of a header file.
     * 
     * @param stream
     *            Stream to print to.
     * @param className
     *            Class to print header file of.
     */
    protected void printHeaderFileBeginning(PrintStream stream, String className, ClassType classType, Version version) {
        stream.println(config.getHeader());
        stream.println();
        stream.println();

        String includeProtectionMacro = PrinterUtils.createIncludeProtectionMacro(config.getNamespace(), className);
        PrinterUtils.printIncludeProtection(stream, includeProtectionMacro);
        stream.println();
        stream.println();

        PrinterUtils.printIncludes(stream, config.getIncludesHeader());
        List<String> incs = new ArrayList<String>();
        incs.add(classType.getInclude());
        incs.add(Utils.findCorrectVersionInclude(version, classType));
        PrinterUtils.printIncludes(stream, incs);
        stream.println();
        stream.println();

        PrinterUtils.printNamespaceOpen(stream, config.getNamespace());
        stream.println();
        stream.println();

        for (String forwardDecl : config.getForwardDecls()) {
            stream.println("class " + forwardDecl + ";");
        }
        stream.println();
        stream.println();

        String baseClass = Utils.findCorrectBaseClass(version, classType);
        stream.println("class " + className + " : public " + baseClass);
        stream.println("{");
        stream.println("private:");
        VariableType member = classType.getMember();
        stream.println(member.getType() + " " + member.getName() + ";");
        stream.println();
        stream.println("public:");
        CtorType ctor = classType.getCtor();
        VariableType ctorParameter = ctor.getParameter();
        stream.println(className + "(" + ctorParameter.getType() + " " + ctorParameter.getName() + ")");
        List<InitlistType> initList = ctor.getInitlistList();
        printInitializationList(stream, initList, classType, version);
        stream.println("{}");
        stream.println();
        stream.println();
    }

    /**
     * Prints ending of header file.
     */
    protected void printHeaderFileEnd(PrintStream stream, String className) {
        stream.println();
        stream.println("private:");
        stream.println("/** Disable default copy ctor. */");
        stream.println(className + "(const " + className + "&);");
        stream.println("/** Disable default assignment operator. */");
        stream.println("const " + className + "& operator=" + "(const " + className + "&);");
        stream.println("};");
        stream.println("}");
        stream.println("#endif // " + PrinterUtils.createIncludeProtectionMacro(config.getNamespace(), className));
    }

    /**
     * Prints beginning of impl file.
     */
    protected void printImplFileBeginning(PrintStream stream, String className) {
        stream.println(config.getHeader());
        stream.println();
        stream.println();

        PrinterUtils.printIncludes(stream, config.getIncludesImpl());
        List<String> incs = new ArrayList<String>();
        incs.add(Utils.createHeaderFileName(config.getNamespace(), className));
        PrinterUtils.printIncludes(stream, incs);
        stream.println();
        stream.println();

        PrinterUtils.printNamespaceOpen(stream, config.getNamespace());
        stream.println();
        stream.println();
    }

    /**
     * Prints ending of impl file.
     */
    protected void printImplFileEnd(PrintStream stream) {
        stream.println();
        stream.println("}");
    }

    /**
     * Prints Initialization List.
     */
    protected void printInitializationList(PrintStream stream, List<InitlistType> initList, ClassType classType,
            Version version) {
        for (int i = 0; i < initList.size(); i++) {
            if (i == 0) {
                stream.print(" : ");
            } else {
                stream.print(" , ");
            }
            String name = initList.get(i).getName();
            if (classType.getBaseClass() != null && classType.getBaseClass().equals(name)) {
                name = name + version.getVersion();
            }
            stream.println(name + "(" + initList.get(i).getValue() + ")");
        }
    }

    /**
     * Prints method parameter list.
     */
    protected void printMethodParameterList(PrintStream stream, MethodType method, SpecificType specific) {
        List<VariableType> parameterList = Utils.findCorrectParameterList(method, specific);
        for (int i = 0; i < parameterList.size(); i++) {
            VariableType para = parameterList.get(i);
            if (i == 0) {
                stream.print(" ");
            } else {
                stream.print(", ");
            }
            stream.print(para.getType() + " " + para.getName());
            if (i == parameterList.size() - 1) {
                stream.print(" ");
            }
        }
    }

    /**
     * Prints a method to header file.
     */
    protected void printMethodToHeader(PrintStream stream, ClassType classType, MethodType method, SpecificType specific) {
        stream.print("virtual " + RETURN_TYPE + " " + specific.getName() + "(");

        printMethodParameterList(stream, method, specific);

        stream.println(");");
        stream.println();
    }

    /**
     * Prints a method to impl file.
     */
    protected void printMethodToImpl(PrintStream stream, String className, ClassType classType, MethodType method,
            SpecificType specific, Version version) {
        stream.print(RETURN_TYPE + " " + className + "::" + specific.getName() + "(");
        printMethodParameterList(stream, method, specific);
        stream.println(")");
        stream.println("{");

        printSaxVirtualFunctionTest(stream, version, method, specific);
        for (String codeLine : specific.getCodeLineList()) {
            stream.println(codeLine);
        }
        stream.print("return " + classType.getMember().getName() + "->" + method.getName() + "(");
        List<VariableType> paraList = method.getParameterList();
        for (int i = 0; i < paraList.size(); i++) {
            VariableType para = paraList.get(i);
            printParaPassing(stream, i, para);
        }
        stream.println(");");

        stream.println("}");
        stream.println();
        stream.println();
    }

    /**
     * Prints passing of parameters to a method.
     * 
     */
    protected void printParaPassing(PrintStream stream, int i, VariableType para) {
        if (i != 0) {
            stream.print(", ");
        }
        stream.print(para.getName());
    }

    /**
     * Prints SaxVirtualFunctionTest.
     * 
     */
    protected void printSaxVirtualFunctionTest(PrintStream stream, Version version, MethodType method,
            SpecificType specific) {
        stream.print("SaxVirtualFunctionTest" + version.getVersion() + "(" + specific.getName() + "(");
        List<VariableType> paraList = Utils.findCorrectParameterList(method, specific);
        for (int i = 0; i < paraList.size(); i++) {
            VariableType para = paraList.get(i);
            printParaPassing(stream, i, para);
        }
        stream.println("));");
    }

    /**
     * Starts code generation
     * 
     * @param pathToXml
     *            Path to xml config.
     */
    public void start(String pathToXml) {
        try {
            SaxfwlDocument saxfwlDoc = SaxfwlDocument.Factory.parse(new File(pathToXml));
            RootType saxfwl = saxfwlDoc.getSaxfwl();
            config = parseConfig(saxfwl.getConfig());

            for (ClassType classType : saxfwl.getClass1List()) {
                for (Version version : config.getVersions()) {

                    if (classContainsSpecificForVersion(classType, version)) {
                        String className = Utils.createClassName(classType.getName(), version);

                        System.out.println("generating code for class: " + className);

                        String headerFileName = config.getOutpathBaseInc() + version.getVersion() + "/"
                                + Utils.createHeaderFileName(config.getNamespace(), className);
                        String implFileName = config.getOutpathBaseSrc() + version.getVersion() + "/"
                                + config.getNamespace() + className + ".cpp";

                        PrintStream headerFile = null;
                        PrintStream implFile = null;
                        try {
                            headerFile = new PrintStream(headerFileName);
                            implFile = new PrintStream(implFileName);

                            printHeaderFileBeginning(headerFile, className, classType, version);
                            printImplFileBeginning(implFile, className);

                            for (MethodType method : classType.getMethodList()) {
                                for (SpecificType specific : method.getSpecificList()) {
                                    if (specific.getVersion() == Integer.parseInt(version.getVersion())) {
                                        printMethodToHeader(headerFile, classType, method, specific);
                                        printMethodToImpl(implFile, className, classType, method, specific, version);
                                    }
                                }
                            }

                            printHeaderFileEnd(headerFile, className);
                            printImplFileEnd(implFile);
                            headerFile.close();
                            implFile.close();

                        } catch (Exception e) {
                            e.printStackTrace();
                            if (headerFile != null) {
                                headerFile.close();
                            }
                            if (implFile != null) {
                                implFile.close();
                            }
                        }
                    }
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
