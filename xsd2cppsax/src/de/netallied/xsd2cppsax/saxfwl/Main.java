/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.saxfwl;

/**
 * Entry point for saxfwl generator.
 * 
 */
public class Main {

    /**
     * main.
     * 
     * @param args
     *            Commandline args
     */
    public static void main(String[] args) {
        String xmlFile = null;
        if (args.length != 1) {
            printUsage();
            return;
        } else {
            xmlFile = args[0];
        }

        SaxFWLGen genner = new SaxFWLGen();
        genner.start(xmlFile);
    }

    /**
     * Prints usage to command line.
     */
    public static void printUsage() {
        System.out.println("saxfwlgen <xml config>");
    }

}
