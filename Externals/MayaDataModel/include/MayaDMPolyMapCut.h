/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMAPCUT_H__
#define __MayaDM_POLYMAPCUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Cut along edges of the texture mapping. The cut edges become
 texture borders.<p/>
*/
class PolyMapCut : public PolyModifier
{
public:
public:
	PolyMapCut(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyMapCut"){}
	virtual ~PolyMapCut(){}
	/*The name of the map set to work on*/
	void setUvSetName(const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs\" -type \"string\" ");uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the map set to work on*/
	void setUvSetName(const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*The name of the map set to work on*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
protected:
	PolyMapCut(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMAPCUT_H__
