/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_COPYUVSET_H__
#define __MayaDM_COPYUVSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> Node to copy individual sets of maps (uvs).
</pre></p>
*/
class CopyUVSet : public DependNode
{
public:
public:
	CopyUVSet(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "copyUVSet"){}
	virtual ~CopyUVSet(){}
	/*The input geometry to be modified*/
	void setInputGeometry(const GeometryID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ig\";\n",mName.c_str());}
	/*The output modified geometry*/
	void setOutputGeometry(const GeometryID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*Name of the uv set to copy from*/
	void setUvSetName(const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs\" -type \"string\" ");uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the uv set to copy from*/
	void setUvSetName(const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*Name of the uv set to copy to*/
	void setUvSetName2(const string& uv2){if(uv2 == "NULL") return; fprintf_s(mFile, "setAttr \".uv2\" -type \"string\" ");uv2.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the uv set to copy to*/
	void setUvSetName2(const StringID& uv2){fprintf_s(mFile,"connectAttr \"");uv2.write(mFile);fprintf_s(mFile,"\" \"%s.uv2\";\n",mName.c_str());}
	/*The input geometry to be modified*/
	GeometryID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ig",mName.c_str());return (const char*)buffer;}
	/*The output modified geometry*/
	GeometryID getOutputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
	/*Name of the uv set to copy from*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
	/*Name of the uv set to copy to*/
	StringID getUvSetName2(){char buffer[4096];sprintf_s (buffer, "%s.uv2",mName.c_str());return (const char*)buffer;}
protected:
	CopyUVSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_COPYUVSET_H__
