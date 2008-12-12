/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOLORDEL_H__
#define __MayaDM_POLYCOLORDEL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*Deletes texture coordinates from input faces.<p/>*/
class PolyColorDel : public PolyModifier
{
public:
public:
	PolyColorDel(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyColorDel"){}
	virtual ~PolyColorDel(){}
	/*The name of the color set to work on*/
	void setColorSetName(const string& cls){if(cls == "NULL") return; fprintf_s(mFile, "setAttr \".cls\" -type \"string\" ");cls.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the color set to work on*/
	void setColorSetName(const StringID& cls){fprintf_s(mFile,"connectAttr \"");cls.write(mFile);fprintf_s(mFile,"\" \"%s.cls\";\n",mName.c_str());}
	/*The name of the color set to work on*/
	StringID getColorSetName(){char buffer[4096];sprintf_s (buffer, "%s.cls",mName.c_str());return (const char*)buffer;}
protected:
	PolyColorDel(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOLORDEL_H__
