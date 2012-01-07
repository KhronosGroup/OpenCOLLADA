package de.netallied.xsd2cppsax.testsuite;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Date;
import java.util.List;

import de.netallied.xsd2Cppsax.testsuite.DocumentType;
import de.netallied.xsd2Cppsax.testsuite.TestSuiteDocument;
import de.netallied.xsd2Cppsax.testsuite.TestSuiteType;
import de.netallied.xsd2Cppsax.testsuite.TestType;

/**
 * <p>
 * Reads a test suite description from a XML file and runs tests.
 * </p>
 * <p>
 * You may use following command to generated java code for test_suite.xsd with
 * apache xml beans:
 * 
 * <pre>
 * scomp -out testsuitexsd.jar -javasource 1.5 -compiler %JAVA_HOME%\bin\javac -src src_dir &lt;path to xsd&gt;
 * </pre>
 * 
 * </p>
 * 
 */
public class TestSuite {

    /** Main class of xsd2cppsax. Required for launching it. */
    public static String CODE_GEN_MAIN_CLASS = "de.netallied.xsd2cppsax.Main";

    /** String to print at begin of log entries. */
    public static String LOG_ENTRY_START = "[TestSuite] ";

    /** File name of the log file. */
    public static String LOG_FILE_NAME = "testsuite.log";

    /** What to return on success. */
    public static int RETURN_VALUE_SUCCESS = 0;

    /** File name of the summary file. */
    public static String SUMMARY_FILE_NAME = "testsuite_summary.txt";

    /**
     * Launches test suite.
     * 
     * @param args
     *            commandline args.
     */
    public static void main(String[] args) {
        String xmlFile = null;
        if (args.length != 1) {
            printUsage();
            return;
        } else {
            xmlFile = args[0];
        }

        TestSuite testSuite = new TestSuite();
        testSuite.run(xmlFile);
    }

    /**
     * Prints usage information to command line.
     */
    public static void printUsage() {
        System.out.println("TestSuite <xml test suite description>");
    }

    /** Log file. */
    private PrintStream logFile;

    /** Output dir name. */
    private String outDir;

    /** Summary file. */
    private PrintStream summaryFile;

    /**
     * Constructor.
     */
    public TestSuite() {
    }

    /**
     * Builds fresh generated native code.
     */
    public boolean buildNativeCode() {
        String pathToSLN = "..\\saxLoader\\fprintfParserMain\\fprintfParser.sln";
        String msvcLog = outDir + System.getProperty("file.separator") + "msvc.log";
        String msvcOut = outDir + System.getProperty("file.separator") + "msvc.out";
        File msvcLogFile = new File(msvcLog);
        msvcLogFile.delete();
        File msvcOutFile = new File(msvcOut);
        msvcOutFile.delete();
        String commandline = "devenv " + pathToSLN + " /Log " + msvcLog + " /Out " + msvcOut
                + " /build \"Release LibXML\"";
        String msg = "Building native code";
        logToSummary(msg);
        logToLog(msg);
        if (runProcess(commandline, false, null) == RETURN_VALUE_SUCCESS) {
            return true;
        }
        return false;
    }

    /**
     * Deletes all files in output directory. Sub directories are not deleted.
     * 
     * @param outDirFile
     *            The output dir.
     */
    protected void clearOutputDir(File outDirFile) {
        for (File file : outDirFile.listFiles()) {
            file.delete();
        }
    }

    /**
     * Prints message to detailed log file.
     * 
     * @param msg
     *            Message to log.
     */
    protected void logToLog(String msg) {
        logFile.println();
        logFile.println(LOG_ENTRY_START + " " + msg);
    }

    /**
     * Prints message to summary file.
     * 
     * @param msg
     *            Message to log.
     */
    protected void logToSummary(String msg) {
        summaryFile.println(new Date(System.currentTimeMillis()).toString() + " " + msg);
        if (msg.equals("FAILED")) {
            System.err.println(msg);
        } else {
            System.out.println(msg);
        }
    }

    /**
     * Let fresh compiled native code parse a document.
     * 
     * @param inputDoc
     *            Input document to parse.
     * @param outputDoc
     *            Output document.
     * @param expectedErrors
     *            List of expected errors.
     */
    public boolean parseDocument(String inputDoc, String outputDoc, List<String> expectedErrors) {
        String pathToFprintfParser = "..\\saxLoader\\NullTests\\bin\\fprintfParser_libxml";
        String commandline = pathToFprintfParser + " -i " + inputDoc + " -o " + outputDoc;
        String msg = "Parsing document: " + commandline;
        logToSummary(msg);
        logToLog(msg);
        if (runProcess(commandline, true, expectedErrors) == RETURN_VALUE_SUCCESS) {
            return true;
        }
        return false;
    }

    /**
     * Starts test suite.
     * 
     * @param xmlFile
     *            Path to input file.
     */
    public void run(String xmlFile) {
        try {
            TestSuiteDocument testSuiteDoc = TestSuiteDocument.Factory.parse(new File(xmlFile));
            TestSuiteType testSuite = testSuiteDoc.getTestSuite();
            outDir = testSuite.getOutDir();
            if (outDir == null || outDir.length() == 0) {
                System.err.println("invalid output dir!");
                return;
            }

            // setup output dir and files.
            File outDirFile = new File(outDir);
            outDirFile.mkdirs();
            clearOutputDir(outDirFile);
            logFile = new PrintStream(outDir + "/" + LOG_FILE_NAME);
            summaryFile = new PrintStream(outDir + "/" + SUMMARY_FILE_NAME);

            // run tests
            for (TestType test : testSuite.getTestList()) {
                summaryFile.println();
                System.out.println();

                String config = test.getConfig();
                String input = test.getInput();
                String rootElement = test.getRootElement();

                logToSummary(LOG_ENTRY_START + "processing: " + input);
                boolean success = runCodeGenerator(config, input, rootElement);
                if (!success) {
                    logToSummary("FAILED");
                    continue;
                }

                success = buildNativeCode();
                if (!success) {
                    logToSummary("FAILED");
                    continue;
                }

                for (DocumentType doc : test.getDocumentList()) {
                    String inputDoc = doc.getInput();
                    String outputDoc = doc.getOutput();
                    outputDoc = outDir + System.getProperties().get("file.separator") + outputDoc;
                    List<String> expectedErrors = doc.getExpectedErrorList();

                    success = parseDocument(inputDoc, outputDoc, expectedErrors);
                    if (!success) {
                        logToSummary("FAILED");
                    }

                    // TODO xml compare
                }

                if (success) {
                    logToSummary("SUCCESS");
                }
            }

        } catch (Throwable e) {
            e.printStackTrace();
            if (logFile != null) {
                e.printStackTrace(logFile);
            }
        } finally {
            if (logFile != null) {
                logFile.close();
            }
            if (summaryFile != null) {
                summaryFile.close();
            }
        }
    }

    /**
     * Runs SAX parser code generator.
     * 
     * @param config
     *            Path to code generator config file.
     * @param input
     *            Path to input XSD for code generator.
     * @param rootElement
     *            Root Element of input XSD.
     */
    public boolean runCodeGenerator(String config, String input, String rootElement) {
        String classPath = System.getProperty("java.class.path");
        String commandline = "java -cp " + classPath + " " + CODE_GEN_MAIN_CLASS + " -c " + config + " -i " + input
                + " -r " + rootElement;
        String msg = "launching code gen: " + commandline;
        logToSummary(msg);
        logToLog(msg);
        if (runProcess(commandline, false, null) == RETURN_VALUE_SUCCESS) {
            return true;
        }
        return false;
    }

    /**
     * Runs given commandline as external process.
     * 
     * @param commandline
     *            Commandline to execute.
     * @param checkOutput
     *            If true, output will be checked for expectedErrors.
     * @param expectedErrors
     *            Expected errors to check output for.
     * @return Exit value of process.
     */
    protected int runProcess(String commandline, boolean checkOutput, List<String> expectedErrors) {
        int returnValue = 0;
        boolean outputCheckFailed = false;
        try {
            // Process proc = Runtime.getRuntime().exec(commandline);
            String[] split = commandline.split(" ");
            ProcessBuilder procBuilder = new ProcessBuilder(split);
            // procBuilder.environment(null);
            procBuilder.directory(null);
            procBuilder.redirectErrorStream(true);
            Process proc = procBuilder.start();

            InputStream inputStream = proc.getInputStream();
            InputStreamReader inStreamReader = new InputStreamReader(inputStream);
            BufferedReader bufferdReader = new BufferedReader(inStreamReader);
            String line = null;
            int errorIter = 0;
            while ((line = bufferdReader.readLine()) != null) {
                logFile.println(line);
                if (checkOutput) {
                    String lowerLine = line.toLowerCase();
                    if (lowerLine.contains("error")) {
                        if (errorIter < expectedErrors.size()) {
                            String expected = expectedErrors.get(errorIter++).toLowerCase();
                            if (!lowerLine.startsWith(expected)) {
                                outputCheckFailed = true;
                                logToLog("expected: " + expectedErrors.get(errorIter - 1));
                            }
                        } else {
                            outputCheckFailed = true;
                            logToLog("did NOT expect: " + line);
                        }
                    }
                }
            }
            if (checkOutput) {
                if (errorIter < expectedErrors.size()) {
                    outputCheckFailed = true;
                    logToLog("expected errors missing");
                }
            }
            returnValue = proc.waitFor();

        } catch (InterruptedException e) {
            returnValue = -1;
            e.printStackTrace(logFile);
        } catch (IOException e) {
            returnValue = -1;
            e.printStackTrace(logFile);
        }
        if (outputCheckFailed) {
            returnValue = -1;
        }

        return returnValue;
    }
}
