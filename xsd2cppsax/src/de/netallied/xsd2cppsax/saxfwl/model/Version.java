/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.saxfwl.model;

/**
 * Holds infos about a COLLADA version.
 * 
 */
public class Version {

    private String baseClass;

    private String include;

    private String version;

    public Version() {

    }

    public Version(String baseClass, String include, String version) {
        super();
        this.baseClass = baseClass;
        this.include = include;
        this.version = version;
    }

    public String getBaseClass() {
        return baseClass;
    }

    public String getInclude() {
        return include;
    }

    public String getVersion() {
        return version;
    }

    public void setBaseClass(String baseClass) {
        this.baseClass = baseClass;
    }

    public void setInclude(String include) {
        this.include = include;
    }

    public void setVersion(String version) {
        this.version = version;
    }
}
