/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ATTACHCURVE_H__
#define __MayaDM_ATTACHCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute the attached curve given two input curves. The end point of the
 first curve is attached to the start point of the second curve. After the
 attach is done, multiple knots exist at the point where the curves were
 joined. The multiple knots can be kept (keepMultipleKnots set to true) or
 they can be removed. If removed, the shape of the attach result may change.
 <p/>
 In the blend case, the multiple knot at the connection will not exist,
 so the "keepMultipleKnots" option is ignored.
 The blend value will skew the resulting curve toward one or the other
 input curve - the value of 0.5 gives them equal influence.
 The parameter value is used only when blendKnotInsertion is set to true.
*/
class AttachCurve : public AbstractBaseCreate
{
public:
public:
	AttachCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "attachCurve"){}
	virtual ~AttachCurve(){}
	/*The first input curve if there are two input curves in total.*/
	void setInputCurve1(const NurbsCurveID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.ic1\";\n",mName.c_str());}
	/*The second input curve if there are two input curves in total.*/
	void setInputCurve2(const NurbsCurveID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.ic2\";\n",mName.c_str());}
	/*All input curves if there are more than two input curves in total.*/
	void setInputCurves(size_t ics_i,const NurbsCurveID& ics){fprintf_s(mFile,"connectAttr \"");ics.write(mFile);fprintf_s(mFile,"\" \"%s.ics[%i]\";\n",mName.c_str(),ics_i);}
	/*Output attached curve.*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*
	If true, reverse the first input curve before doing attach.
	Otherwise, do nothing to the first input curve before attaching.
	NOTE: setting this attribute to random values will cause
	unpredictable results and is not supported.
	*/
	void setReverse1(bool rv1){if(rv1 == false) return; fprintf_s(mFile, "setAttr \".rv1\" %i;\n", rv1);}
	/*
	If true, reverse the first input curve before doing attach.
	Otherwise, do nothing to the first input curve before attaching.
	NOTE: setting this attribute to random values will cause
	unpredictable results and is not supported.
	*/
	void setReverse1(const BoolID& rv1){fprintf_s(mFile,"connectAttr \"");rv1.write(mFile);fprintf_s(mFile,"\" \"%s.rv1\";\n",mName.c_str());}
	/*
	If true, reverse the second input curve before doing attach.
	Otherwise, do nothing to the second input curve before
	attaching. NOTE: setting this attribute to random values will
	cause unpredictable results and is not supported.
	*/
	void setReverse2(bool rv2){if(rv2 == false) return; fprintf_s(mFile, "setAttr \".rv2\" %i;\n", rv2);}
	/*
	If true, reverse the second input curve before doing attach.
	Otherwise, do nothing to the second input curve before
	attaching. NOTE: setting this attribute to random values will
	cause unpredictable results and is not supported.
	*/
	void setReverse2(const BoolID& rv2){fprintf_s(mFile,"connectAttr \"");rv2.write(mFile);fprintf_s(mFile,"\" \"%s.rv2\";\n",mName.c_str());}
	/*Attach method (connect-0, blend-1)*/
	void setMethod(unsigned int m){if(m == 0) return; fprintf_s(mFile, "setAttr \".m\" %i;\n", m);}
	/*Attach method (connect-0, blend-1)*/
	void setMethod(const UnsignedintID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*
	If true, keep multiple knots at the join parameter.
	Otherwise remove them.
	*/
	void setKeepMultipleKnots(bool kmk){if(kmk == true) return; fprintf_s(mFile, "setAttr \".kmk\" %i;\n", kmk);}
	/*
	If true, keep multiple knots at the join parameter.
	Otherwise remove them.
	*/
	void setKeepMultipleKnots(const BoolID& kmk){fprintf_s(mFile,"connectAttr \"");kmk.write(mFile);fprintf_s(mFile,"\" \"%s.kmk\";\n",mName.c_str());}
	/*
	Skew the result toward the first or the second curve depending
	on the blend factory being smaller or larger than 0.5.
	*/
	void setBlendBias(double bb){if(bb == 0.5) return; fprintf_s(mFile, "setAttr \".bb\" %f;\n", bb);}
	/*
	Skew the result toward the first or the second curve depending
	on the blend factory being smaller or larger than 0.5.
	*/
	void setBlendBias(const DoubleID& bb){fprintf_s(mFile,"connectAttr \"");bb.write(mFile);fprintf_s(mFile,"\" \"%s.bb\";\n",mName.c_str());}
	/*
	If set to true, insert a knot in one of the original curves
	(relative position given by the parameter attribute below)
	in order to produce a slightly different effect.
	*/
	void setBlendKnotInsertion(bool bki){if(bki == false) return; fprintf_s(mFile, "setAttr \".bki\" %i;\n", bki);}
	/*
	If set to true, insert a knot in one of the original curves
	(relative position given by the parameter attribute below)
	in order to produce a slightly different effect.
	*/
	void setBlendKnotInsertion(const BoolID& bki){fprintf_s(mFile,"connectAttr \"");bki.write(mFile);fprintf_s(mFile,"\" \"%s.bki\";\n",mName.c_str());}
	/*The parameter value for the positioning of the newly inserted knot.*/
	void setParameter(double p){if(p == 0.1) return; fprintf_s(mFile, "setAttr \".p\" %f;\n", p);}
	/*The parameter value for the positioning of the newly inserted knot.*/
	void setParameter(const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The first input curve if there are two input curves in total.*/
	NurbsCurveID getInputCurve1(){char buffer[4096];sprintf_s (buffer, "%s.ic1",mName.c_str());return (const char*)buffer;}
	/*The second input curve if there are two input curves in total.*/
	NurbsCurveID getInputCurve2(){char buffer[4096];sprintf_s (buffer, "%s.ic2",mName.c_str());return (const char*)buffer;}
	/*All input curves if there are more than two input curves in total.*/
	const NurbsCurveID& getInputCurves(size_t ics_i){char buffer[4096];sprintf_s (buffer, "%s.ics[%i]",mName.c_str(),ics_i);return (const char*)buffer;}
	/*Output attached curve.*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*
	If true, reverse the first input curve before doing attach.
	Otherwise, do nothing to the first input curve before attaching.
	NOTE: setting this attribute to random values will cause
	unpredictable results and is not supported.
	*/
	BoolID getReverse1(){char buffer[4096];sprintf_s (buffer, "%s.rv1",mName.c_str());return (const char*)buffer;}
	/*
	If true, reverse the second input curve before doing attach.
	Otherwise, do nothing to the second input curve before
	attaching. NOTE: setting this attribute to random values will
	cause unpredictable results and is not supported.
	*/
	BoolID getReverse2(){char buffer[4096];sprintf_s (buffer, "%s.rv2",mName.c_str());return (const char*)buffer;}
	/*Attach method (connect-0, blend-1)*/
	UnsignedintID getMethod(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*
	If true, keep multiple knots at the join parameter.
	Otherwise remove them.
	*/
	BoolID getKeepMultipleKnots(){char buffer[4096];sprintf_s (buffer, "%s.kmk",mName.c_str());return (const char*)buffer;}
	/*
	Skew the result toward the first or the second curve depending
	on the blend factory being smaller or larger than 0.5.
	*/
	DoubleID getBlendBias(){char buffer[4096];sprintf_s (buffer, "%s.bb",mName.c_str());return (const char*)buffer;}
	/*
	If set to true, insert a knot in one of the original curves
	(relative position given by the parameter attribute below)
	in order to produce a slightly different effect.
	*/
	BoolID getBlendKnotInsertion(){char buffer[4096];sprintf_s (buffer, "%s.bki",mName.c_str());return (const char*)buffer;}
	/*The parameter value for the positioning of the newly inserted knot.*/
	DoubleID getParameter(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
protected:
	AttachCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ATTACHCURVE_H__
