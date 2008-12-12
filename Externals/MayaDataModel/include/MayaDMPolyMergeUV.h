/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMERGEUV_H__
#define __MayaDM_POLYMERGEUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
/*
Merge UVs within a given threshold.
 Only UVs correspinding to the same vertex can be merged.<p/>
*/
class PolyMergeUV : public PolyModifierUV
{
public:
public:
	PolyMergeUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyMergeUV"){}
	virtual ~PolyMergeUV(){}
	/*
	Tolerance to determine whether UVs should
	be merged. Default value of 0.0 specifies only coincident
	UVs are merged.
	*/
	void setDistance(float d){if(d == 10000) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	Tolerance to determine whether UVs should
	be merged. Default value of 0.0 specifies only coincident
	UVs are merged.
	*/
	void setDistance(const FloatID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	Tolerance to determine whether UVs should
	be merged. Default value of 0.0 specifies only coincident
	UVs are merged.
	*/
	FloatID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
protected:
	PolyMergeUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMERGEUV_H__
