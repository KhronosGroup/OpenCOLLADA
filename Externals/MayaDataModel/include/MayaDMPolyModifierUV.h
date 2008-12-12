/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMODIFIERUV_H__
#define __MayaDM_POLYMODIFIERUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
Base class for all nodes which creat new UV sets, or modify
 existing ones.<br/>
 Warning: The aUVSetName attribute is meant to be set at creation
 time using a command deriving from TpolyModifierUVCmd. Unpredictable
 results may occur if this attribute value is changed after the node
 creation.<p/>
*/
class PolyModifierUV : public PolyModifierWorld
{
public:
public:
	PolyModifierUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyModifierUV"){}
	virtual ~PolyModifierUV(){}
	/*The name of the map set to work on*/
	void setUvSetName(const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs\" -type \"string\" ");uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the map set to work on*/
	void setUvSetName(const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*The name of the map set to work on*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
protected:
	PolyModifierUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMODIFIERUV_H__
