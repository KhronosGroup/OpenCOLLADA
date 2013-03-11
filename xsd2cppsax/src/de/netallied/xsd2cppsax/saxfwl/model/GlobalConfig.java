/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.saxfwl.model;

import java.util.List;

/**
 * Holds global options.
 * 
 */
public class GlobalConfig {

    private List<String> forwardDecls;

    private String header;

    private List<String> includesHeader;

    private List<String> includesImpl;

    private String namespace;

    private String outpathBaseInc;

    private String outpathBaseSrc;

    private List<Version> versions;

    public GlobalConfig() {

    }

    public GlobalConfig(String outpathBaseInc, String outpathBaseSrc, List<String> forwardDecls, String header,
            List<String> includesHeader, List<String> includesImpl, String namespace, List<Version> versions) {
        super();
        this.outpathBaseInc = outpathBaseInc;
        this.outpathBaseSrc = outpathBaseSrc;
        this.forwardDecls = forwardDecls;
        this.header = header;
        this.includesHeader = includesHeader;
        this.includesImpl = includesImpl;
        this.namespace = namespace;
        this.versions = versions;
    }

    public List<String> getForwardDecls() {
        return forwardDecls;
    }

    public String getHeader() {
        return header;
    }

    public List<String> getIncludesHeader() {
        return includesHeader;
    }

    public List<String> getIncludesImpl() {
        return includesImpl;
    }

    public String getNamespace() {
        return namespace;
    }

    public String getOutpathBaseInc() {
        return outpathBaseInc;
    }

    public String getOutpathBaseSrc() {
        return outpathBaseSrc;
    }

    public List<Version> getVersions() {
        return versions;
    }

    public void setForwardDecls(List<String> forwardDecls) {
        this.forwardDecls = forwardDecls;
    }

    public void setHeader(String header) {
        this.header = header;
    }

    public void setIncludesHeader(List<String> includesHeader) {
        this.includesHeader = includesHeader;
    }

    public void setIncludesImpl(List<String> includesImpl) {
        this.includesImpl = includesImpl;
    }

    public void setNamespace(String namespace) {
        this.namespace = namespace;
    }

    public void setOutpathBaseInc(String outpathBaseInc) {
        this.outpathBaseInc = outpathBaseInc;
    }

    public void setOutpathBaseSrc(String outpathBaseSrc) {
        this.outpathBaseSrc = outpathBaseSrc;
    }

    public void setVersions(List<Version> versions) {
        this.versions = versions;
    }
}
