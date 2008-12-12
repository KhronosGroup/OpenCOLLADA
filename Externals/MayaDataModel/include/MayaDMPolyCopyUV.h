/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOPYUV_H__
#define __MayaDM_POLYCOPYUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
/*
<p><pre> Copy UV information from a map set to another.
</pre></p>
*/
class PolyCopyUV : public PolyModifierUV
{
public:
public:
	PolyCopyUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyCopyUV"){}
	virtual ~PolyCopyUV(){}
	/*The name of the map set to read from*/
	void setUvSetNameInput(const string& uvi){if(uvi == "NULL") return; fprintf_s(mFile, "setAttr \".uvi\" -type \"string\" ");uvi.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the map set to read from*/
	void setUvSetNameInput(const StringID& uvi){fprintf_s(mFile,"connectAttr \"");uvi.write(mFile);fprintf_s(mFile,"\" \"%s.uvi\";\n",mName.c_str());}
	/*The name of the map set to read from*/
	StringID getUvSetNameInput(){char buffer[4096];sprintf_s (buffer, "%s.uvi",mName.c_str());return (const char*)buffer;}
protected:
	PolyCopyUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOPYUV_H__
