/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYFLIPUV_H__
#define __MayaDM_POLYFLIPUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
/*
Flips the UVs of the selected faces.
 Options are horizontal/vertical, local/global
 <p/>
*/
class PolyFlipUV : public PolyModifierUV
{
public:
public:
	PolyFlipUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyFlipUV"){}
	virtual ~PolyFlipUV(){}
	/*Flip along U or V direction*/
	void setFlipType(unsigned int ft){if(ft == 0) return; fprintf_s(mFile, "setAttr \".ft\" %i;\n", ft);}
	/*Flip along U or V direction*/
	void setFlipType(const UnsignedintID& ft){fprintf_s(mFile,"connectAttr \"");ft.write(mFile);fprintf_s(mFile,"\" \"%s.ft\";\n",mName.c_str());}
	/*Flips in the local space of the input faces*/
	void setLocal(bool l){if(l == true) return; fprintf_s(mFile, "setAttr \".l\" %i;\n", l);}
	/*Flips in the local space of the input faces*/
	void setLocal(const BoolID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*Flip along U or V direction*/
	UnsignedintID getFlipType(){char buffer[4096];sprintf_s (buffer, "%s.ft",mName.c_str());return (const char*)buffer;}
	/*Flips in the local space of the input faces*/
	BoolID getLocal(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
protected:
	PolyFlipUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYFLIPUV_H__
