/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DELETECOMPONENT_H__
#define __MayaDM_DELETECOMPONENT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    This node handles deletion of components (parts) from geometry.
    The node deletes the specified components from the input geometry and
    sends the modified geometry out as output.

    This node is created when components (typically, CVs, Faces and Vertices)
    are selected and deleted using the "delete" command.
</pre></p>
*/
class DeleteComponent : public DependNode
{
public:
public:
	DeleteComponent(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "deleteComponent"){}
	virtual ~DeleteComponent(){}
	/*The input geometry to be modified*/
	void setInputGeometry(const GenericID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ig\";\n",mName.c_str());}
	/*Components to be deleted from the geometry data flowing through the node*/
	void setDeleteComponents(const componentList& dc){fprintf_s(mFile, "setAttr \".dc\" -type \"componentList\" ");dc.write(mFile);fprintf_s(mFile,";\n");}
	/*Components to be deleted from the geometry data flowing through the node*/
	void setDeleteComponents(const ComponentListID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*The output modified geometry*/
	void setOutputGeometry(const GenericID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*
	Attribute to specify if the old poly architecture needs to be used
	for the evaluation of this node. This attribute only makes sense
	when this node is deleting polygonal components. THIS ATTRIBUTE
	SHOULD NOT BE SET OR MODIFIED BY THE USER!!
	*/
	void setUseOldPolyArchitecture(bool uopa){if(uopa == false) return; fprintf_s(mFile, "setAttr \".uopa\" %i;\n", uopa);}
	/*The input geometry to be modified*/
	GenericID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ig",mName.c_str());return (const char*)buffer;}
	/*Components to be deleted from the geometry data flowing through the node*/
	ComponentListID getDeleteComponents(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*The output modified geometry*/
	GenericID getOutputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
protected:
	DeleteComponent(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DELETECOMPONENT_H__
