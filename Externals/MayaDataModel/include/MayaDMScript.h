/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SCRIPT_H__
#define __MayaDM_SCRIPT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Script nodes hold MEL code as part of a scene file. They are also set
        up to (possibly) execute after loading from a file, just before closing
        a file, or just before the node is deleted.<p/>

        The before scripts are executed when a file is loaded. If a file is
        closed or the node is deleted, the after script is executed. If a scene
        contains several script nodes, there is no guaranteed order of execution
        and the scripts should not depend on a specific execution sequence.<p/>

        The scriptType attribute accepts three different enumerated values that
        are used to determine if and when a script is executed. The after script
        will execute when the node is deleted regardless of the
        scriptType value.<p/>

        <center>
        <table border="1" width="80%">
                <tr><td><b>Enum</b></td>
                <td><b>Type</b></td>
                <td><b>Description</b></td></tr>
                <tr><td>0</td>
                        <td>Demand</td>
                        <td>The scripts are only executed if explicitly requested with
                                the scriptNode command. The after script will execute
                                if the node is deleted.</td>
                </tr>
                <tr><td>1</td>
                        <td>Open/Close</td>
                        <td>The before script will execute when the file is read. The
                                after script will execute when the file is closed. The file
                                is closed immediately after a file new is issued, but while
                                the file is still in memory; before a file open of a
                                different file; or if the file is de-referenced. The after
                                script will execute when the node is deleted.</td>
                </tr>
                <tr><td>2</td>
                        <td>GUI Open/Close</td>
                        <td>The script will only execute during file open and close
                                when Maya is in full GUI mode, not in batch mode. The after
                                script will execute when the node is deleted.</td>
                </tr>
                <tr><td>3</td>
                        <td>UI Configuration (Internal)</td>
                        <td>An internally used enum which indicates the script is used
                                to store the UI configuration for a scene. Any script node
                                with this enum may be deleted or changed without notice.</td>
                </tr>
                <tr><td>4</td>
                        <td>Software Render</td>
                        <td>The before script will execute immediately before a software
                                render starts. The after script executes when the software
                                render is finished.</td>
                </tr>
                <tr><td>5</td>
                        <td>Software Frame Render</td>
                        <td>The before script executes before a frame is software
                                rendered. The after script is executed after the frame
                                is rendered.</td>
                </tr>
                <tr><td>6</td>
                        <td>Scene Configuration (Internal)</td>
                        <td>An internally used enum which indicates the script is used
                                to store the configuration information for a scene. Any script
                                node with this enum may be deleted or changed without
                                notice.</td>
                </tr>
                <tr><td>7</td>
                        <td>Time Changed (Internal)</td>
                        <td>The script executes if the time is changed.</td>
                </tr>
        </table>
        </center>
*/
class Script : public DependNode
{
public:
public:
	Script(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "script"){}
	virtual ~Script(){}
	/*The script to execute when the file is opened.*/
	void setBefore(const string& b){if(b == "NULL") return; fprintf_s(mFile, "setAttr \".b\" -type \"string\" ");b.write(mFile);fprintf_s(mFile,";\n");}
	/*The script to execute when the file is opened.*/
	void setBefore(const StringID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*The script to execute when the file is closed or the node is deleted.*/
	void setAfter(const string& a){if(a == "NULL") return; fprintf_s(mFile, "setAttr \".a\" -type \"string\" ");a.write(mFile);fprintf_s(mFile,";\n");}
	/*The script to execute when the file is closed or the node is deleted.*/
	void setAfter(const StringID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*
	Sets the conditions for executing the scripts. The following are
	legal values: 0 = Demand, 1 = Open/Close, 2 = GUI Open/Close,
	3 = UI Configuration (Internal), 4 = Software Render,
	5 = Software Frame Render, 6 = Scene Configuration (Internal)
	7 = Time Changed
	*/
	void setScriptType(unsigned int st){if(st == 0) return; fprintf_s(mFile, "setAttr \".st\" %i;\n", st);}
	/*
	Sets the conditions for executing the scripts. The following are
	legal values: 0 = Demand, 1 = Open/Close, 2 = GUI Open/Close,
	3 = UI Configuration (Internal), 4 = Software Render,
	5 = Software Frame Render, 6 = Scene Configuration (Internal)
	7 = Time Changed
	*/
	void setScriptType(const UnsignedintID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*The script to execute when the file is opened.*/
	StringID getBefore(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*The script to execute when the file is closed or the node is deleted.*/
	StringID getAfter(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*
	Sets the conditions for executing the scripts. The following are
	legal values: 0 = Demand, 1 = Open/Close, 2 = GUI Open/Close,
	3 = UI Configuration (Internal), 4 = Software Render,
	5 = Software Frame Render, 6 = Scene Configuration (Internal)
	7 = Time Changed
	*/
	UnsignedintID getScriptType(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
protected:
	Script(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SCRIPT_H__
