/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOLLAPSEF_H__
#define __MayaDM_POLYCOLLAPSEF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
<p><pre> Turns each selected facet into a point.
</pre></p>
*/
class PolyCollapseF : public PolyModifier
{
public:
public:
	PolyCollapseF(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyCollapseF"){}
	virtual ~PolyCollapseF(){}
	/*
	If true only collapse faces with area less than the area threshold,
	otherwise collapse all faces regardless of area
	*/
	void setUseAreaThreshold(bool uat){if(uat == false) return; fprintf_s(mFile, "setAttr \".uat\" %i;\n", uat);}
	/*
	If true only collapse faces with area less than the area threshold,
	otherwise collapse all faces regardless of area
	*/
	void setUseAreaThreshold(const BoolID& uat){fprintf_s(mFile,"connectAttr \"");uat.write(mFile);fprintf_s(mFile,"\" \"%s.uat\";\n",mName.c_str());}
	/*
	Area threshold to determine whether faces should
	be collapsed. Attribute is ignored unless useAreaThreshold is
	set to true.
	*/
	void setAreaThreshold(double at){if(at == 0.1) return; fprintf_s(mFile, "setAttr \".at\" %f;\n", at);}
	/*
	Area threshold to determine whether faces should
	be collapsed. Attribute is ignored unless useAreaThreshold is
	set to true.
	*/
	void setAreaThreshold(const DoubleID& at){fprintf_s(mFile,"connectAttr \"");at.write(mFile);fprintf_s(mFile,"\" \"%s.at\";\n",mName.c_str());}
	/*
	If true only collapse faces with area less than the area threshold,
	otherwise collapse all faces regardless of area
	*/
	BoolID getUseAreaThreshold(){char buffer[4096];sprintf_s (buffer, "%s.uat",mName.c_str());return (const char*)buffer;}
	/*
	Area threshold to determine whether faces should
	be collapsed. Attribute is ignored unless useAreaThreshold is
	set to true.
	*/
	DoubleID getAreaThreshold(){char buffer[4096];sprintf_s (buffer, "%s.at",mName.c_str());return (const char*)buffer;}
protected:
	PolyCollapseF(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOLLAPSEF_H__
