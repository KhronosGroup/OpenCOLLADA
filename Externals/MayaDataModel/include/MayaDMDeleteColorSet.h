/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DELETECOLORSET_H__
#define __MayaDM_DELETECOLORSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> Node to delete individual sets of color (cpv layers).
</pre></p>
*/
class DeleteColorSet : public DependNode
{
public:
public:
	DeleteColorSet(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "deleteColorSet"){}
	virtual ~DeleteColorSet(){}
	/*The input geometry to be modified*/
	void setInputGeometry(const GeometryID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ig\";\n",mName.c_str());}
	/*The output modified geometry*/
	void setOutputGeometry(const GeometryID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*Name of the uv set the node is operating on.*/
	void setColorSetName(const string& cols){if(cols == "NULL") return; fprintf_s(mFile, "setAttr \".cols\" -type \"string\" ");cols.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the uv set the node is operating on.*/
	void setColorSetName(const StringID& cols){fprintf_s(mFile,"connectAttr \"");cols.write(mFile);fprintf_s(mFile,"\" \"%s.cols\";\n",mName.c_str());}
	/*The input geometry to be modified*/
	GeometryID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ig",mName.c_str());return (const char*)buffer;}
	/*The output modified geometry*/
	GeometryID getOutputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
	/*Name of the uv set the node is operating on.*/
	StringID getColorSetName(){char buffer[4096];sprintf_s (buffer, "%s.cols",mName.c_str());return (const char*)buffer;}
protected:
	DeleteColorSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DELETECOLORSET_H__
