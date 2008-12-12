/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HARDENPOINT_H__
#define __MayaDM_HARDENPOINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Given an input curve (inputCurve) and an index of a control vertex (index),
 attempt to produce an output curve (outputCurve) that interpolates the
 position of that control point,
 without changing the parameter domain or the total number of
 control points in the curve.  This will be accomplished (if possible)
 by reparameterizing the curve to introduce a multiple knot of a specified
 multiplicity.  A multiplicity of -1 will produce a full multiplicity knot
 (equal to the degree of the curve.)
*/
class HardenPoint : public AbstractBaseCreate
{
public:
public:
	HardenPoint(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "hardenPoint"){}
	virtual ~HardenPoint(){}
	/*Input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*index of the control vertex*/
	void setIndex(size_t i_i,int i){if(i == 0) return; fprintf_s(mFile, "setAttr \".i[%i]\" %i;\n", i_i,i);}
	/*index of the control vertex*/
	void setIndex(size_t i_i,const IntID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*the required multiplicity of the curve knot*/
	void setMultiplicity(int m){if(m == -1) return; fprintf_s(mFile, "setAttr \".m\" %i;\n", m);}
	/*the required multiplicity of the curve knot*/
	void setMultiplicity(const IntID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*Output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*index of the control vertex*/
	const IntID& getIndex(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*the required multiplicity of the curve knot*/
	IntID getMultiplicity(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*Output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	HardenPoint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HARDENPOINT_H__
