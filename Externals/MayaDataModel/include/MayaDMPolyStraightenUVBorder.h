/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSTRAIGHTENUVBORDER_H__
#define __MayaDM_POLYSTRAIGHTENUVBORDER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
/*Maps UV selection border to a simpler curve.<p/>*/
class PolyStraightenUVBorder : public PolyModifierUV
{
public:
public:
	PolyStraightenUVBorder(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyStraightenUVBorder"){}
	virtual ~PolyStraightenUVBorder(){}
	/*
	How curved the UV curved will be. 0 is a straight line.
	When the values is 1, the mid point of the curve will be moved
	away from a straight line by 1/2 the length of the UV segment.
	*/
	void setCurvature(float c){if(c == 0.) return; fprintf_s(mFile, "setAttr \".c\" %f;\n", c);}
	/*
	How curved the UV curved will be. 0 is a straight line.
	When the values is 1, the mid point of the curve will be moved
	away from a straight line by 1/2 the length of the UV segment.
	*/
	void setCurvature(const FloatID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*
	How much we want to respect the UV edge ratios. When the value
	is 1, we build new UV position along the desired curve,
	respecting the previous UV spacings.
	When the value is 0, new UVs are equally spaced, no matter
	what their original positions were.
	*/
	void setPreserveLength(float pl){if(pl == 1.) return; fprintf_s(mFile, "setAttr \".pl\" %f;\n", pl);}
	/*
	How much we want to respect the UV edge ratios. When the value
	is 1, we build new UV position along the desired curve,
	respecting the previous UV spacings.
	When the value is 0, new UVs are equally spaced, no matter
	what their original positions were.
	*/
	void setPreserveLength(const FloatID& pl){fprintf_s(mFile,"connectAttr \"");pl.write(mFile);fprintf_s(mFile,"\" \"%s.pl\";\n",mName.c_str());}
	/*
	How much we want to move the UVs to their desired location. If
	the value is 1, nothing moves, 0 fully move UVs to the target curve.
	*/
	void setBlendOriginal(float bo){if(bo == 0.) return; fprintf_s(mFile, "setAttr \".bo\" %f;\n", bo);}
	/*
	How much we want to move the UVs to their desired location. If
	the value is 1, nothing moves, 0 fully move UVs to the target curve.
	*/
	void setBlendOriginal(const FloatID& bo){fprintf_s(mFile,"connectAttr \"");bo.write(mFile);fprintf_s(mFile,"\" \"%s.bo\";\n",mName.c_str());}
	/*Larger size of selection holes wich will be automatically filled*/
	void setGapTolerance(int gt){if(gt == 5) return; fprintf_s(mFile, "setAttr \".gt\" %i;\n", gt);}
	/*Larger size of selection holes wich will be automatically filled*/
	void setGapTolerance(const IntID& gt){fprintf_s(mFile,"connectAttr \"");gt.write(mFile);fprintf_s(mFile,"\" \"%s.gt\";\n",mName.c_str());}
	/*
	How curved the UV curved will be. 0 is a straight line.
	When the values is 1, the mid point of the curve will be moved
	away from a straight line by 1/2 the length of the UV segment.
	*/
	FloatID getCurvature(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*
	How much we want to respect the UV edge ratios. When the value
	is 1, we build new UV position along the desired curve,
	respecting the previous UV spacings.
	When the value is 0, new UVs are equally spaced, no matter
	what their original positions were.
	*/
	FloatID getPreserveLength(){char buffer[4096];sprintf_s (buffer, "%s.pl",mName.c_str());return (const char*)buffer;}
	/*
	How much we want to move the UVs to their desired location. If
	the value is 1, nothing moves, 0 fully move UVs to the target curve.
	*/
	FloatID getBlendOriginal(){char buffer[4096];sprintf_s (buffer, "%s.bo",mName.c_str());return (const char*)buffer;}
	/*Larger size of selection holes wich will be automatically filled*/
	IntID getGapTolerance(){char buffer[4096];sprintf_s (buffer, "%s.gt",mName.c_str());return (const char*)buffer;}
protected:
	PolyStraightenUVBorder(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSTRAIGHTENUVBORDER_H__
