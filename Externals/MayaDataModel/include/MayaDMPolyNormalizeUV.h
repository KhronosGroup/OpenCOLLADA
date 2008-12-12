/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYNORMALIZEUV_H__
#define __MayaDM_POLYNORMALIZEUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
/*
<p><pre> Normalizes the UVs of the selected faces.
</pre></p>
*/
class PolyNormalizeUV : public PolyModifierUV
{
public:
public:
	PolyNormalizeUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyNormalizeUV"){}
	virtual ~PolyNormalizeUV(){}
	/*Options for normalize*/
	void setNormalizeType(unsigned int nt){if(nt == 1) return; fprintf_s(mFile, "setAttr \".nt\" %i;\n", nt);}
	/*Options for normalize*/
	void setNormalizeType(const UnsignedintID& nt){fprintf_s(mFile,"connectAttr \"");nt.write(mFile);fprintf_s(mFile,"\" \"%s.nt\";\n",mName.c_str());}
	/*Scale uniform along U and V.*/
	void setPreserveAspectRatio(bool pa){if(pa == true) return; fprintf_s(mFile, "setAttr \".pa\" %i;\n", pa);}
	/*Scale uniform along U and V.*/
	void setPreserveAspectRatio(const BoolID& pa){fprintf_s(mFile,"connectAttr \"");pa.write(mFile);fprintf_s(mFile,"\" \"%s.pa\";\n",mName.c_str());}
	/*Options for normalize*/
	UnsignedintID getNormalizeType(){char buffer[4096];sprintf_s (buffer, "%s.nt",mName.c_str());return (const char*)buffer;}
	/*Scale uniform along U and V.*/
	BoolID getPreserveAspectRatio(){char buffer[4096];sprintf_s (buffer, "%s.pa",mName.c_str());return (const char*)buffer;}
protected:
	PolyNormalizeUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYNORMALIZEUV_H__
