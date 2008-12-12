/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_COPYCOLORSET_H__
#define __MayaDM_COPYCOLORSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> Node to copy individual color set.
</pre></p>
*/
class CopyColorSet : public DependNode
{
public:
public:
	CopyColorSet(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "copyColorSet"){}
	virtual ~CopyColorSet(){}
	/*The input geometry to be modified*/
	void setInputGeometry(const GeometryID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ig\";\n",mName.c_str());}
	/*The output modified geometry*/
	void setOutputGeometry(const GeometryID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*Name of the color set to copy from*/
	void setSrcColorSetName(const string& src){if(src == "NULL") return; fprintf_s(mFile, "setAttr \".src\" -type \"string\" ");src.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the color set to copy from*/
	void setSrcColorSetName(const StringID& src){fprintf_s(mFile,"connectAttr \"");src.write(mFile);fprintf_s(mFile,"\" \"%s.src\";\n",mName.c_str());}
	/*Name of the color set to copy to*/
	void setDstColorName(const string& dst){if(dst == "NULL") return; fprintf_s(mFile, "setAttr \".dst\" -type \"string\" ");dst.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the color set to copy to*/
	void setDstColorName(const StringID& dst){fprintf_s(mFile,"connectAttr \"");dst.write(mFile);fprintf_s(mFile,"\" \"%s.dst\";\n",mName.c_str());}
	/*The input geometry to be modified*/
	GeometryID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ig",mName.c_str());return (const char*)buffer;}
	/*The output modified geometry*/
	GeometryID getOutputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
	/*Name of the color set to copy from*/
	StringID getSrcColorSetName(){char buffer[4096];sprintf_s (buffer, "%s.src",mName.c_str());return (const char*)buffer;}
	/*Name of the color set to copy to*/
	StringID getDstColorName(){char buffer[4096];sprintf_s (buffer, "%s.dst",mName.c_str());return (const char*)buffer;}
protected:
	CopyColorSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_COPYCOLORSET_H__
