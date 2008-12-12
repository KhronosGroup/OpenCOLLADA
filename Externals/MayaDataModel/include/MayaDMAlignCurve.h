/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ALIGNCURVE_H__
#define __MayaDM_ALIGNCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute the aligned curve(s) given two input curves. One input curve can
 be aligned to another input curve or both curves can be aligned to each
 other. If aligning one curve to another then the parameter value
 (joinParameter) is used to define the position on the other curve where
 to align to. If aligning both curves together then an end point on each
 curve is used.
 <br/>
 Alignment with positional (positionalContinuity) is always true. The types
 of positional continuity (positionalContinuityType) are: move
 first/second/both or modify first/second/both. For "move" the entire curve
 is moved so its end point coincides with the parameter value on the other
 curve. For "modify" only an end point is moved to the parameter value.
 <br/>
 The tangent and curvature information at the parameter value
 is used for aligning if the tangent (tangentContinuity) or curvature
 (curvatureContinuity) option is true. Curvature continuity true implies
 tangent continuity true as well. If tangent continuity is true, then the
 tangent scale values (tangentScale1 and tangentScale2) are applied to
 the appropriate curve based on the tangent type (tangentContinuityType).
 If one curve is to be modified for tangent continuity then the
 tangent at its end point is modified to match the tangent at the
 parameter value of the other curve. If curvature continuity is true, then
 the curvature scale values (aCurvatureScale1 and aCurvatureScale2) are
 applied to the appropriate curve as well.
 <p/>
*/
class AlignCurve : public AbstractBaseCreate
{
public:
public:
	AlignCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "alignCurve"){}
	virtual ~AlignCurve(){}
	/*The first input curve.*/
	void setInputCurve1(const NurbsCurveID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.ic1\";\n",mName.c_str());}
	/*The second input curve.*/
	void setInputCurve2(const NurbsCurveID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.ic2\";\n",mName.c_str());}
	/*Output aligned curve one (refers to first input curve). If attach option is true the attached result is in this output.*/
	void setOutputCurve1(const NurbsCurveID& oc1){fprintf_s(mFile,"connectAttr \"");oc1.write(mFile);fprintf_s(mFile,"\" \"%s.oc1\";\n",mName.c_str());}
	/*Output aligned curve two (refers to second input curve). If attach option is true this output is not available.*/
	void setOutputCurve2(const NurbsCurveID& oc2){fprintf_s(mFile,"connectAttr \"");oc2.write(mFile);fprintf_s(mFile,"\" \"%s.oc2\";\n",mName.c_str());}
	/*Tangent scale applied to tangent of first curve for tangent continuity.*/
	void setTangentScale1(double ts1){if(ts1 == 1.0) return; fprintf_s(mFile, "setAttr \".ts1\" %f;\n", ts1);}
	/*Tangent scale applied to tangent of first curve for tangent continuity.*/
	void setTangentScale1(const DoubleID& ts1){fprintf_s(mFile,"connectAttr \"");ts1.write(mFile);fprintf_s(mFile,"\" \"%s.ts1\";\n",mName.c_str());}
	/*Tangent scale applied to tangent of second curve for tangent continuity.*/
	void setTangentScale2(double ts2){if(ts2 == 1.0) return; fprintf_s(mFile, "setAttr \".ts2\" %f;\n", ts2);}
	/*Tangent scale applied to tangent of second curve for tangent continuity.*/
	void setTangentScale2(const DoubleID& ts2){fprintf_s(mFile,"connectAttr \"");ts2.write(mFile);fprintf_s(mFile,"\" \"%s.ts2\";\n",mName.c_str());}
	/*Curvature scale applied to curvature of first curve for curvature continuity.*/
	void setCurvatureScale1(double cs1){if(cs1 == 0.0) return; fprintf_s(mFile, "setAttr \".cs1\" %f;\n", cs1);}
	/*Curvature scale applied to curvature of first curve for curvature continuity.*/
	void setCurvatureScale1(const DoubleID& cs1){fprintf_s(mFile,"connectAttr \"");cs1.write(mFile);fprintf_s(mFile,"\" \"%s.cs1\";\n",mName.c_str());}
	/*Curvature scale applied to curvature of second curve for curvature continuity.*/
	void setCurvatureScale2(double cs2){if(cs2 == 0.0) return; fprintf_s(mFile, "setAttr \".cs2\" %f;\n", cs2);}
	/*Curvature scale applied to curvature of second curve for curvature continuity.*/
	void setCurvatureScale2(const DoubleID& cs2){fprintf_s(mFile,"connectAttr \"");cs2.write(mFile);fprintf_s(mFile,"\" \"%s.cs2\";\n",mName.c_str());}
	/*
	Positional continuity type legal values:
	1 - move first curve,
	2 - move second curve,
	3 - move both curves,
	4 - modify first curve,
	5 - modify second curve,
	6 - modify both curves
	*/
	void setPositionalContinuityType(unsigned int pct){if(pct == 1) return; fprintf_s(mFile, "setAttr \".pct\" %i;\n", pct);}
	/*
	Positional continuity type legal values:
	1 - move first curve,
	2 - move second curve,
	3 - move both curves,
	4 - modify first curve,
	5 - modify second curve,
	6 - modify both curves
	*/
	void setPositionalContinuityType(const UnsignedintID& pct){fprintf_s(mFile,"connectAttr \"");pct.write(mFile);fprintf_s(mFile,"\" \"%s.pct\";\n",mName.c_str());}
	/*
	Tangent continuity type legal values:
	1 - do tangent continuity on first curve,
	2 - do tangent continuity on second curve
	*/
	void setTangentContinuityType(unsigned int tct){if(tct == 1) return; fprintf_s(mFile, "setAttr \".tct\" %i;\n", tct);}
	/*
	Tangent continuity type legal values:
	1 - do tangent continuity on first curve,
	2 - do tangent continuity on second curve
	*/
	void setTangentContinuityType(const UnsignedintID& tct){fprintf_s(mFile,"connectAttr \"");tct.write(mFile);fprintf_s(mFile,"\" \"%s.tct\";\n",mName.c_str());}
	/*Parameter on reference curve where modified curve is to be aligned to.*/
	void setJoinParameter(float jnp){if(jnp == 123456.0) return; fprintf_s(mFile, "setAttr \".jnp\" %f;\n", jnp);}
	/*Parameter on reference curve where modified curve is to be aligned to.*/
	void setJoinParameter(const FloatID& jnp){fprintf_s(mFile,"connectAttr \"");jnp.write(mFile);fprintf_s(mFile,"\" \"%s.jnp\";\n",mName.c_str());}
	/*If true, reverse the first input curve before doing align. Otherwise, do nothing to the first input curve before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse1(bool rv1){if(rv1 == false) return; fprintf_s(mFile, "setAttr \".rv1\" %i;\n", rv1);}
	/*If true, reverse the first input curve before doing align. Otherwise, do nothing to the first input curve before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse1(const BoolID& rv1){fprintf_s(mFile,"connectAttr \"");rv1.write(mFile);fprintf_s(mFile,"\" \"%s.rv1\";\n",mName.c_str());}
	/*If true, reverse the second input curve before doing align. Otherwise, do nothing to the second input curve before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse2(bool rv2){if(rv2 == false) return; fprintf_s(mFile, "setAttr \".rv2\" %i;\n", rv2);}
	/*If true, reverse the second input curve before doing align. Otherwise, do nothing to the second input curve before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse2(const BoolID& rv2){fprintf_s(mFile,"connectAttr \"");rv2.write(mFile);fprintf_s(mFile,"\" \"%s.rv2\";\n",mName.c_str());}
	/*If true, join the aligned curves together. Otherwise, two curve results are output from the node. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setAttach(bool at){if(at == false) return; fprintf_s(mFile, "setAttr \".at\" %i;\n", at);}
	/*If true, join the aligned curves together. Otherwise, two curve results are output from the node. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setAttach(const BoolID& at){fprintf_s(mFile,"connectAttr \"");at.write(mFile);fprintf_s(mFile,"\" \"%s.at\";\n",mName.c_str());}
	/*If false, remove the multiple knots from the attached curve. Otherwise, the multiple knots are kept. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setKeepMultipleKnots(bool kmk){if(kmk == true) return; fprintf_s(mFile, "setAttr \".kmk\" %i;\n", kmk);}
	/*If false, remove the multiple knots from the attached curve. Otherwise, the multiple knots are kept. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setKeepMultipleKnots(const BoolID& kmk){fprintf_s(mFile,"connectAttr \"");kmk.write(mFile);fprintf_s(mFile,"\" \"%s.kmk\";\n",mName.c_str());}
	/*Positional continuity is on if true and off otherwise.*/
	void setPositionalContinuity(bool pc){if(pc == true) return; fprintf_s(mFile, "setAttr \".pc\" %i;\n", pc);}
	/*Positional continuity is on if true and off otherwise.*/
	void setPositionalContinuity(const BoolID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*Tangent continuity is on if true and off otherwise.*/
	void setTangentContinuity(bool tc){if(tc == true) return; fprintf_s(mFile, "setAttr \".tc\" %i;\n", tc);}
	/*Tangent continuity is on if true and off otherwise.*/
	void setTangentContinuity(const BoolID& tc){fprintf_s(mFile,"connectAttr \"");tc.write(mFile);fprintf_s(mFile,"\" \"%s.tc\";\n",mName.c_str());}
	/*Curvature continuity is on if true and off otherwise.*/
	void setCurvatureContinuity(bool cc){if(cc == false) return; fprintf_s(mFile, "setAttr \".cc\" %i;\n", cc);}
	/*Curvature continuity is on if true and off otherwise.*/
	void setCurvatureContinuity(const BoolID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc\";\n",mName.c_str());}
	/*The first input curve.*/
	NurbsCurveID getInputCurve1(){char buffer[4096];sprintf_s (buffer, "%s.ic1",mName.c_str());return (const char*)buffer;}
	/*The second input curve.*/
	NurbsCurveID getInputCurve2(){char buffer[4096];sprintf_s (buffer, "%s.ic2",mName.c_str());return (const char*)buffer;}
	/*Output aligned curve one (refers to first input curve). If attach option is true the attached result is in this output.*/
	NurbsCurveID getOutputCurve1(){char buffer[4096];sprintf_s (buffer, "%s.oc1",mName.c_str());return (const char*)buffer;}
	/*Output aligned curve two (refers to second input curve). If attach option is true this output is not available.*/
	NurbsCurveID getOutputCurve2(){char buffer[4096];sprintf_s (buffer, "%s.oc2",mName.c_str());return (const char*)buffer;}
	/*Tangent scale applied to tangent of first curve for tangent continuity.*/
	DoubleID getTangentScale1(){char buffer[4096];sprintf_s (buffer, "%s.ts1",mName.c_str());return (const char*)buffer;}
	/*Tangent scale applied to tangent of second curve for tangent continuity.*/
	DoubleID getTangentScale2(){char buffer[4096];sprintf_s (buffer, "%s.ts2",mName.c_str());return (const char*)buffer;}
	/*Curvature scale applied to curvature of first curve for curvature continuity.*/
	DoubleID getCurvatureScale1(){char buffer[4096];sprintf_s (buffer, "%s.cs1",mName.c_str());return (const char*)buffer;}
	/*Curvature scale applied to curvature of second curve for curvature continuity.*/
	DoubleID getCurvatureScale2(){char buffer[4096];sprintf_s (buffer, "%s.cs2",mName.c_str());return (const char*)buffer;}
	/*
	Positional continuity type legal values:
	1 - move first curve,
	2 - move second curve,
	3 - move both curves,
	4 - modify first curve,
	5 - modify second curve,
	6 - modify both curves
	*/
	UnsignedintID getPositionalContinuityType(){char buffer[4096];sprintf_s (buffer, "%s.pct",mName.c_str());return (const char*)buffer;}
	/*
	Tangent continuity type legal values:
	1 - do tangent continuity on first curve,
	2 - do tangent continuity on second curve
	*/
	UnsignedintID getTangentContinuityType(){char buffer[4096];sprintf_s (buffer, "%s.tct",mName.c_str());return (const char*)buffer;}
	/*Parameter on reference curve where modified curve is to be aligned to.*/
	FloatID getJoinParameter(){char buffer[4096];sprintf_s (buffer, "%s.jnp",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the first input curve before doing align. Otherwise, do nothing to the first input curve before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getReverse1(){char buffer[4096];sprintf_s (buffer, "%s.rv1",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the second input curve before doing align. Otherwise, do nothing to the second input curve before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getReverse2(){char buffer[4096];sprintf_s (buffer, "%s.rv2",mName.c_str());return (const char*)buffer;}
	/*If true, join the aligned curves together. Otherwise, two curve results are output from the node. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getAttach(){char buffer[4096];sprintf_s (buffer, "%s.at",mName.c_str());return (const char*)buffer;}
	/*If false, remove the multiple knots from the attached curve. Otherwise, the multiple knots are kept. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getKeepMultipleKnots(){char buffer[4096];sprintf_s (buffer, "%s.kmk",mName.c_str());return (const char*)buffer;}
	/*Positional continuity is on if true and off otherwise.*/
	BoolID getPositionalContinuity(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*Tangent continuity is on if true and off otherwise.*/
	BoolID getTangentContinuity(){char buffer[4096];sprintf_s (buffer, "%s.tc",mName.c_str());return (const char*)buffer;}
	/*Curvature continuity is on if true and off otherwise.*/
	BoolID getCurvatureContinuity(){char buffer[4096];sprintf_s (buffer, "%s.cc",mName.c_str());return (const char*)buffer;}
protected:
	AlignCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ALIGNCURVE_H__
