XXXXXAAAAAXXXXX
package de.netallied.xsd2cppsax;

import java.io.FileNotFoundException;
import java.io.IOException;

/**
 * Contains main method. Execution starts here.
 * 
 */
public class Main {

    /** Command with which this app is launched. */
    public final static String COMMAND_NAME = "xsd2cppsax";

    /**
     * Main method. Starts app.
     * 
     * @param args
     *            Commandline arguments.
     */
    public static void main(String[] args) {
        if (args.length == 0 || args.length % 2 != 0) {
            printUsage(args);
            System.exit(-1);
        }
        String configFileName = null;
        String inputXSD = null;
        String rootElement = null;

        for (int i = 0; i < args.length; i += 2) {
            if (args[i].equals("-c")) {
                configFileName = args[i + 1];
            } else if (args[i].equals("-i")) {
                inputXSD = args[i + 1];
            } else if (args[i].equals("-r")) {
                rootElement = args[i + 1];
            }
        }

        if (configFileName == null) {
            printUsage(args);
            System.exit(-1);
        }

        Config config = null;
        try {
            config = new Config(configFileName, inputXSD, rootElement);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(-1);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }
        Generator gener = new Generator(config);
        boolean success = gener.generate();

        // DEBUG
        // ElementUsageDumper dumper = new ElementUsageDumper();
        // try {
        // dumper.dumpTypeMapping(new Config());
        // } catch (FileNotFoundException e) {
        // e.printStackTrace();
        // }

        if (!success) {
            System.exit(-1);
        }
    }

    /**
     * Prints usage information to commandline.
     */
    private static void printUsage(String[] args) {
        System.out.println("usage: " + COMMAND_NAME + " -c <config file> [-i <input XSD> -r <root element name>]");
    }
}
