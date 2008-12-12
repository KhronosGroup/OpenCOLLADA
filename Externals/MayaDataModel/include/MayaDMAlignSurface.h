/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ALIGNSURFACE_H__
#define __MayaDM_ALIGNSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute the aligned surface(s) given two input surfaces. One input surface
 can be aligned to another input surface or both surfaces can be aligned to
 each other. If aligning one surface to another then the parameter value
 (joinParameter) and direction (directionU) are used to define the isoparm
 on the other surface where to align to. If aligning both surfaces together
 then an end boundary on each surface is used in the specified direction.
 <br/>
 Alignment with positional (positionalContinuity) is always true. The types
 of positional continuity (positionalContinuityType) are: move
 first/second/both or modify first/second/both. For "move" the entire surface
 is moved so its end boundary coincides with the isoparm in the specified
 direction and at the parameter value on the other surface. For "modify"
 only an end boundary is moved to the isoparm at the parameter value.
 <br/>
 The tangent and curvature information at the parameter value
 is used for aligning if the tangent (tangentContinuity) or curvature
 (curvatureContinuity) option is true. Curvature continuity true implies
 tangent continuity true as well. If tangent continuity is true, then the
 tangent scale values (tangentScale1 and tangentScale2) are applied to
 the appropriate surface based on the tangent type (tangentContinuityType).
 If one surface is to be modified for tangent continuity then the
 tangents at its end boundary are modified to match the tangents of the
 isoparm in the specified direction and at the parameter value of the other
 surface. If curvature continuity is true, then the curvature scale values
 (aCurvatureScale1 and aCurvatureScale2) are applied to the appropriate
 surface as well.
 <p/>
*/
class AlignSurface : public AbstractBaseCreate
{
public:
public:
	AlignSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "alignSurface"){}
	virtual ~AlignSurface(){}
	/*The first input surface.*/
	void setInputSurface1(const NurbsSurfaceID& is1){fprintf_s(mFile,"connectAttr \"");is1.write(mFile);fprintf_s(mFile,"\" \"%s.is1\";\n",mName.c_str());}
	/*The second input surface.*/
	void setInputSurface2(const NurbsSurfaceID& is2){fprintf_s(mFile,"connectAttr \"");is2.write(mFile);fprintf_s(mFile,"\" \"%s.is2\";\n",mName.c_str());}
	/*Output aligned surface one (refers to first input surface). If attach option is true the attached result is in this output.*/
	void setOutputSurface1(const NurbsSurfaceID& os1){fprintf_s(mFile,"connectAttr \"");os1.write(mFile);fprintf_s(mFile,"\" \"%s.os1\";\n",mName.c_str());}
	/*Output aligned surface two (refers to second input surface). If attach option is true this output is not available.*/
	void setOutputSurface2(const NurbsSurfaceID& os2){fprintf_s(mFile,"connectAttr \"");os2.write(mFile);fprintf_s(mFile,"\" \"%s.os2\";\n",mName.c_str());}
	/*Tangent scale applied to tangent of first surface for tangent continuity.*/
	void setTangentScale1(double ts1){if(ts1 == 1.0) return; fprintf_s(mFile, "setAttr \".ts1\" %f;\n", ts1);}
	/*Tangent scale applied to tangent of first surface for tangent continuity.*/
	void setTangentScale1(const DoubleID& ts1){fprintf_s(mFile,"connectAttr \"");ts1.write(mFile);fprintf_s(mFile,"\" \"%s.ts1\";\n",mName.c_str());}
	/*Tangent scale applied to tangent of second surface for tangent continuity.*/
	void setTangentScale2(double ts2){if(ts2 == 1.0) return; fprintf_s(mFile, "setAttr \".ts2\" %f;\n", ts2);}
	/*Tangent scale applied to tangent of second surface for tangent continuity.*/
	void setTangentScale2(const DoubleID& ts2){fprintf_s(mFile,"connectAttr \"");ts2.write(mFile);fprintf_s(mFile,"\" \"%s.ts2\";\n",mName.c_str());}
	/*Curvature scale applied to curvature of first surface for curvature continuity.*/
	void setCurvatureScale1(double cs1){if(cs1 == 0.0) return; fprintf_s(mFile, "setAttr \".cs1\" %f;\n", cs1);}
	/*Curvature scale applied to curvature of first surface for curvature continuity.*/
	void setCurvatureScale1(const DoubleID& cs1){fprintf_s(mFile,"connectAttr \"");cs1.write(mFile);fprintf_s(mFile,"\" \"%s.cs1\";\n",mName.c_str());}
	/*Curvature scale applied to curvature of second surface for curvature continuity.*/
	void setCurvatureScale2(double cs2){if(cs2 == 0.0) return; fprintf_s(mFile, "setAttr \".cs2\" %f;\n", cs2);}
	/*Curvature scale applied to curvature of second surface for curvature continuity.*/
	void setCurvatureScale2(const DoubleID& cs2){fprintf_s(mFile,"connectAttr \"");cs2.write(mFile);fprintf_s(mFile,"\" \"%s.cs2\";\n",mName.c_str());}
	/*
	Positional continuity type legal values:
	1 - move first surface,
	2 - move second surface,
	3 - move both surfaces,
	4 - modify first surface,
	5 - modify second surface,
	6 - modify both surfaces
	*/
	void setPositionalContinuityType(unsigned int pct){if(pct == 1) return; fprintf_s(mFile, "setAttr \".pct\" %i;\n", pct);}
	/*
	Positional continuity type legal values:
	1 - move first surface,
	2 - move second surface,
	3 - move both surfaces,
	4 - modify first surface,
	5 - modify second surface,
	6 - modify both surfaces
	*/
	void setPositionalContinuityType(const UnsignedintID& pct){fprintf_s(mFile,"connectAttr \"");pct.write(mFile);fprintf_s(mFile,"\" \"%s.pct\";\n",mName.c_str());}
	/*
	Tangent continuity type legal values:
	1 - do tangent continuity on first surface,
	2 - do tangent continuity on second surface
	*/
	void setTangentContinuityType(unsigned int tct){if(tct == 1) return; fprintf_s(mFile, "setAttr \".tct\" %i;\n", tct);}
	/*
	Tangent continuity type legal values:
	1 - do tangent continuity on first surface,
	2 - do tangent continuity on second surface
	*/
	void setTangentContinuityType(const UnsignedintID& tct){fprintf_s(mFile,"connectAttr \"");tct.write(mFile);fprintf_s(mFile,"\" \"%s.tct\";\n",mName.c_str());}
	/*Parameter on reference surface where modified surface is to be aligned to.*/
	void setJoinParameter(float jnp){if(jnp == 123456.0) return; fprintf_s(mFile, "setAttr \".jnp\" %f;\n", jnp);}
	/*Parameter on reference surface where modified surface is to be aligned to.*/
	void setJoinParameter(const FloatID& jnp){fprintf_s(mFile,"connectAttr \"");jnp.write(mFile);fprintf_s(mFile,"\" \"%s.jnp\";\n",mName.c_str());}
	/*If true, reverse the second surface in the opposite direction (specified by directionU) before doing align. This will avoid twists in the aligned surfaces. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setTwist(bool tw){if(tw == false) return; fprintf_s(mFile, "setAttr \".tw\" %i;\n", tw);}
	/*If true, reverse the second surface in the opposite direction (specified by directionU) before doing align. This will avoid twists in the aligned surfaces. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setTwist(const BoolID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tw\";\n",mName.c_str());}
	/*If true, reverse the direction (specified by directionU) of the first input surface before doing align. Otherwise, do nothing to the first input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse1(bool rv1){if(rv1 == false) return; fprintf_s(mFile, "setAttr \".rv1\" %i;\n", rv1);}
	/*If true, reverse the direction (specified by directionU) of the first input surface before doing align. Otherwise, do nothing to the first input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse1(const BoolID& rv1){fprintf_s(mFile,"connectAttr \"");rv1.write(mFile);fprintf_s(mFile,"\" \"%s.rv1\";\n",mName.c_str());}
	/*If true, reverse the direction (specified by directionU) of the second input surface before doing align. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse2(bool rv2){if(rv2 == false) return; fprintf_s(mFile, "setAttr \".rv2\" %i;\n", rv2);}
	/*If true, reverse the direction (specified by directionU) of the second input surface before doing align. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse2(const BoolID& rv2){fprintf_s(mFile,"connectAttr \"");rv2.write(mFile);fprintf_s(mFile,"\" \"%s.rv2\";\n",mName.c_str());}
	/*If true, swap the UV directions of the first input surface before doing align. Otherwise, do nothing to the first input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setSwap1(bool sw1){if(sw1 == false) return; fprintf_s(mFile, "setAttr \".sw1\" %i;\n", sw1);}
	/*If true, swap the UV directions of the first input surface before doing align. Otherwise, do nothing to the first input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setSwap1(const BoolID& sw1){fprintf_s(mFile,"connectAttr \"");sw1.write(mFile);fprintf_s(mFile,"\" \"%s.sw1\";\n",mName.c_str());}
	/*If true, swap the UV directions of the second input surface before doing align. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setSwap2(bool sw2){if(sw2 == false) return; fprintf_s(mFile, "setAttr \".sw2\" %i;\n", sw2);}
	/*If true, swap the UV directions of the second input surface before doing align. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setSwap2(const BoolID& sw2){fprintf_s(mFile,"connectAttr \"");sw2.write(mFile);fprintf_s(mFile,"\" \"%s.sw2\";\n",mName.c_str());}
	/*If true, join the aligned surfaces together. Otherwise, two surface results are output from the node. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setAttach(bool at){if(at == false) return; fprintf_s(mFile, "setAttr \".at\" %i;\n", at);}
	/*If true, join the aligned surfaces together. Otherwise, two surface results are output from the node. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setAttach(const BoolID& at){fprintf_s(mFile,"connectAttr \"");at.write(mFile);fprintf_s(mFile,"\" \"%s.at\";\n",mName.c_str());}
	/*If false, remove the multiple knots from the attached surface. Otherwise, the multiple knots are kept. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setKeepMultipleKnots(bool kmk){if(kmk == true) return; fprintf_s(mFile, "setAttr \".kmk\" %i;\n", kmk);}
	/*If false, remove the multiple knots from the attached surface. Otherwise, the multiple knots are kept. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
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
	/*If true use U direction of surface and V direction otherwise.*/
	void setDirectionU(bool du){if(du == true) return; fprintf_s(mFile, "setAttr \".du\" %i;\n", du);}
	/*If true use U direction of surface and V direction otherwise.*/
	void setDirectionU(const BoolID& du){fprintf_s(mFile,"connectAttr \"");du.write(mFile);fprintf_s(mFile,"\" \"%s.du\";\n",mName.c_str());}
	/*The first input surface.*/
	NurbsSurfaceID getInputSurface1(){char buffer[4096];sprintf_s (buffer, "%s.is1",mName.c_str());return (const char*)buffer;}
	/*The second input surface.*/
	NurbsSurfaceID getInputSurface2(){char buffer[4096];sprintf_s (buffer, "%s.is2",mName.c_str());return (const char*)buffer;}
	/*Output aligned surface one (refers to first input surface). If attach option is true the attached result is in this output.*/
	NurbsSurfaceID getOutputSurface1(){char buffer[4096];sprintf_s (buffer, "%s.os1",mName.c_str());return (const char*)buffer;}
	/*Output aligned surface two (refers to second input surface). If attach option is true this output is not available.*/
	NurbsSurfaceID getOutputSurface2(){char buffer[4096];sprintf_s (buffer, "%s.os2",mName.c_str());return (const char*)buffer;}
	/*Tangent scale applied to tangent of first surface for tangent continuity.*/
	DoubleID getTangentScale1(){char buffer[4096];sprintf_s (buffer, "%s.ts1",mName.c_str());return (const char*)buffer;}
	/*Tangent scale applied to tangent of second surface for tangent continuity.*/
	DoubleID getTangentScale2(){char buffer[4096];sprintf_s (buffer, "%s.ts2",mName.c_str());return (const char*)buffer;}
	/*Curvature scale applied to curvature of first surface for curvature continuity.*/
	DoubleID getCurvatureScale1(){char buffer[4096];sprintf_s (buffer, "%s.cs1",mName.c_str());return (const char*)buffer;}
	/*Curvature scale applied to curvature of second surface for curvature continuity.*/
	DoubleID getCurvatureScale2(){char buffer[4096];sprintf_s (buffer, "%s.cs2",mName.c_str());return (const char*)buffer;}
	/*
	Positional continuity type legal values:
	1 - move first surface,
	2 - move second surface,
	3 - move both surfaces,
	4 - modify first surface,
	5 - modify second surface,
	6 - modify both surfaces
	*/
	UnsignedintID getPositionalContinuityType(){char buffer[4096];sprintf_s (buffer, "%s.pct",mName.c_str());return (const char*)buffer;}
	/*
	Tangent continuity type legal values:
	1 - do tangent continuity on first surface,
	2 - do tangent continuity on second surface
	*/
	UnsignedintID getTangentContinuityType(){char buffer[4096];sprintf_s (buffer, "%s.tct",mName.c_str());return (const char*)buffer;}
	/*Parameter on reference surface where modified surface is to be aligned to.*/
	FloatID getJoinParameter(){char buffer[4096];sprintf_s (buffer, "%s.jnp",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the second surface in the opposite direction (specified by directionU) before doing align. This will avoid twists in the aligned surfaces. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getTwist(){char buffer[4096];sprintf_s (buffer, "%s.tw",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the direction (specified by directionU) of the first input surface before doing align. Otherwise, do nothing to the first input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getReverse1(){char buffer[4096];sprintf_s (buffer, "%s.rv1",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the direction (specified by directionU) of the second input surface before doing align. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getReverse2(){char buffer[4096];sprintf_s (buffer, "%s.rv2",mName.c_str());return (const char*)buffer;}
	/*If true, swap the UV directions of the first input surface before doing align. Otherwise, do nothing to the first input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getSwap1(){char buffer[4096];sprintf_s (buffer, "%s.sw1",mName.c_str());return (const char*)buffer;}
	/*If true, swap the UV directions of the second input surface before doing align. Otherwise, do nothing to the second input surface before aligning. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getSwap2(){char buffer[4096];sprintf_s (buffer, "%s.sw2",mName.c_str());return (const char*)buffer;}
	/*If true, join the aligned surfaces together. Otherwise, two surface results are output from the node. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getAttach(){char buffer[4096];sprintf_s (buffer, "%s.at",mName.c_str());return (const char*)buffer;}
	/*If false, remove the multiple knots from the attached surface. Otherwise, the multiple knots are kept. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getKeepMultipleKnots(){char buffer[4096];sprintf_s (buffer, "%s.kmk",mName.c_str());return (const char*)buffer;}
	/*Positional continuity is on if true and off otherwise.*/
	BoolID getPositionalContinuity(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*Tangent continuity is on if true and off otherwise.*/
	BoolID getTangentContinuity(){char buffer[4096];sprintf_s (buffer, "%s.tc",mName.c_str());return (const char*)buffer;}
	/*Curvature continuity is on if true and off otherwise.*/
	BoolID getCurvatureContinuity(){char buffer[4096];sprintf_s (buffer, "%s.cc",mName.c_str());return (const char*)buffer;}
	/*If true use U direction of surface and V direction otherwise.*/
	BoolID getDirectionU(){char buffer[4096];sprintf_s (buffer, "%s.du",mName.c_str());return (const char*)buffer;}
protected:
	AlignSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ALIGNSURFACE_H__
