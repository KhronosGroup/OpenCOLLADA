/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AVGCURVES_H__
#define __MayaDM_AVGCURVES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The avgCurves node computes as output the weighted average of two input
 NURBS curves. The computed curve is also rebuilt to match the knot sequence
 of the input curve which has a fewer number of knots or lesser degree.
 <p/>
 The user may choose to normalize the weights by setting the attribute 'nw' to true.
 Weights may be automatically assigned to the input curves by setting the attribute
 'aw' to true. If 'aw' is true, then the value set at the attribute 'nw' is ignored.
 <p/>
 Can be used to do add or subtract two NURBS curves.
*/
class AvgCurves : public AbstractBaseCreate
{
public:
public:
	AvgCurves(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "avgCurves"){}
	virtual ~AvgCurves(){}
	/*The input curve One*/
	void setInputCurve1(const NurbsCurveID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.ic1\";\n",mName.c_str());}
	/*The input curve Two*/
	void setInputCurve2(const NurbsCurveID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.ic2\";\n",mName.c_str());}
	/*weight for Curve 1. The position and normal on inputCurve1 are weighted by 'w1'.*/
	void setWeight1(double w1){if(w1 == 0.5) return; fprintf_s(mFile, "setAttr \".w1\" %f;\n", w1);}
	/*weight for Curve 1. The position and normal on inputCurve1 are weighted by 'w1'.*/
	void setWeight1(const DoubleID& w1){fprintf_s(mFile,"connectAttr \"");w1.write(mFile);fprintf_s(mFile,"\" \"%s.w1\";\n",mName.c_str());}
	/*weight for Curve 2. The position and normal on inputCurve2 are weighted by 'w2'.*/
	void setWeight2(double w2){if(w2 == 0.5) return; fprintf_s(mFile, "setAttr \".w2\" %f;\n", w2);}
	/*weight for Curve 2. The position and normal on inputCurve2 are weighted by 'w2'.*/
	void setWeight2(const DoubleID& w2){fprintf_s(mFile,"connectAttr \"");w2.write(mFile);fprintf_s(mFile,"\" \"%s.w2\";\n",mName.c_str());}
	/*automate weight assigment based on the input curves span, degree, knots.*/
	void setAutomaticWeight(bool aw){if(aw == true) return; fprintf_s(mFile, "setAttr \".aw\" %i;\n", aw);}
	/*automate weight assigment based on the input curves span, degree, knots.*/
	void setAutomaticWeight(const BoolID& aw){fprintf_s(mFile,"connectAttr \"");aw.write(mFile);fprintf_s(mFile,"\" \"%s.aw\";\n",mName.c_str());}
	/*normalize the two weights. Has no Affect if aInAutomateWt is set to true.*/
	void setNormalizeWeights(bool nw){if(nw == true) return; fprintf_s(mFile, "setAttr \".nw\" %i;\n", nw);}
	/*normalize the two weights. Has no Affect if aInAutomateWt is set to true.*/
	void setNormalizeWeights(const BoolID& nw){fprintf_s(mFile,"connectAttr \"");nw.write(mFile);fprintf_s(mFile,"\" \"%s.nw\";\n",mName.c_str());}
	/*Output averaged or weighted curve of the two input curves.*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The input curve One*/
	NurbsCurveID getInputCurve1(){char buffer[4096];sprintf_s (buffer, "%s.ic1",mName.c_str());return (const char*)buffer;}
	/*The input curve Two*/
	NurbsCurveID getInputCurve2(){char buffer[4096];sprintf_s (buffer, "%s.ic2",mName.c_str());return (const char*)buffer;}
	/*weight for Curve 1. The position and normal on inputCurve1 are weighted by 'w1'.*/
	DoubleID getWeight1(){char buffer[4096];sprintf_s (buffer, "%s.w1",mName.c_str());return (const char*)buffer;}
	/*weight for Curve 2. The position and normal on inputCurve2 are weighted by 'w2'.*/
	DoubleID getWeight2(){char buffer[4096];sprintf_s (buffer, "%s.w2",mName.c_str());return (const char*)buffer;}
	/*automate weight assigment based on the input curves span, degree, knots.*/
	BoolID getAutomaticWeight(){char buffer[4096];sprintf_s (buffer, "%s.aw",mName.c_str());return (const char*)buffer;}
	/*normalize the two weights. Has no Affect if aInAutomateWt is set to true.*/
	BoolID getNormalizeWeights(){char buffer[4096];sprintf_s (buffer, "%s.nw",mName.c_str());return (const char*)buffer;}
	/*Output averaged or weighted curve of the two input curves.*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	AvgCurves(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_AVGCURVES_H__
