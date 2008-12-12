/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DPBIRAILSRF_H__
#define __MayaDM_DPBIRAILSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBirailSrf.h"
namespace MayaDM
{
/*
The 'dpBirailSrf' node computes a NURBS surface by sweeping a
 NURBS profile towards a second NURBS profile along two given
 NURBS rail curves. The profile curves should intersect the rail
 curves. The profiles and rails may be surface curves i.e. isoparams,
 curve on surfaces or trimmed edges.
 <p/>
 The input attributes 'tangentContinuityProfile1', 'tangentContinuityProfile2'
 can be used to build the surface to be tangent continuous with the
 underlying surfaces on the profiles.
 <p/>
 During the sweep, the input profile at 'inputProfile1' is also blended
 w.r.t. the second profile at 'inputProfile2'. The fraction of blend is
 determined by the attribute 'blendFactor'. A blend factor of 1.0 implies
 the  profile at 'inputProfile1' has a greater influence in the surface
 computation.
 <p/>
 Using the attribute 'transformMode',the profiles can be scaled
 proportionately or non proportionately. The scaling is done in x,y,z
 coordinates using an internal local coordinate frame. The legal values
 are : 0 - Non proportional , 1 - proportional.
*/
class DpBirailSrf : public BirailSrf
{
public:
public:
	DpBirailSrf(FILE* file,const std::string& name,const std::string& parent=""):BirailSrf(file, name, parent, "dpBirailSrf"){}
	virtual ~DpBirailSrf(){}
	/*input profile curve1*/
	void setInputProfile1(const NurbsCurveID& ip1){fprintf_s(mFile,"connectAttr \"");ip1.write(mFile);fprintf_s(mFile,"\" \"%s.ip1\";\n",mName.c_str());}
	/*input profile curve2*/
	void setInputProfile2(const NurbsCurveID& ip2){fprintf_s(mFile,"connectAttr \"");ip2.write(mFile);fprintf_s(mFile,"\" \"%s.ip2\";\n",mName.c_str());}
	/*
	A blend factor applied in between the two profiles.
	The amount of influence 'inputProfile1' has in the surface creation.
	*/
	void setBlendFactor(double bl){if(bl == 0.5) return; fprintf_s(mFile, "setAttr \".bl\" %f;\n", bl);}
	/*
	A blend factor applied in between the two profiles.
	The amount of influence 'inputProfile1' has in the surface creation.
	*/
	void setBlendFactor(const DoubleID& bl){fprintf_s(mFile,"connectAttr \"");bl.write(mFile);fprintf_s(mFile,"\" \"%s.bl\";\n",mName.c_str());}
	/*Need tangent continuity across the input profile at inputProfile1.*/
	void setTangentContinuityProfile1(bool tp1){if(tp1 == false) return; fprintf_s(mFile, "setAttr \".tp1\" %i;\n", tp1);}
	/*Need tangent continuity across the input profile at inputProfile1.*/
	void setTangentContinuityProfile1(const BoolID& tp1){fprintf_s(mFile,"connectAttr \"");tp1.write(mFile);fprintf_s(mFile,"\" \"%s.tp1\";\n",mName.c_str());}
	/*Need tangent continuity across the input curve at inputProfile2.*/
	void setTangentContinuityProfile2(bool tp2){if(tp2 == false) return; fprintf_s(mFile, "setAttr \".tp2\" %i;\n", tp2);}
	/*Need tangent continuity across the input curve at inputProfile2.*/
	void setTangentContinuityProfile2(const BoolID& tp2){fprintf_s(mFile,"connectAttr \"");tp2.write(mFile);fprintf_s(mFile,"\" \"%s.tp2\";\n",mName.c_str());}
	/*input profile curve1*/
	NurbsCurveID getInputProfile1(){char buffer[4096];sprintf_s (buffer, "%s.ip1",mName.c_str());return (const char*)buffer;}
	/*input profile curve2*/
	NurbsCurveID getInputProfile2(){char buffer[4096];sprintf_s (buffer, "%s.ip2",mName.c_str());return (const char*)buffer;}
	/*
	A blend factor applied in between the two profiles.
	The amount of influence 'inputProfile1' has in the surface creation.
	*/
	DoubleID getBlendFactor(){char buffer[4096];sprintf_s (buffer, "%s.bl",mName.c_str());return (const char*)buffer;}
	/*Need tangent continuity across the input profile at inputProfile1.*/
	BoolID getTangentContinuityProfile1(){char buffer[4096];sprintf_s (buffer, "%s.tp1",mName.c_str());return (const char*)buffer;}
	/*Need tangent continuity across the input curve at inputProfile2.*/
	BoolID getTangentContinuityProfile2(){char buffer[4096];sprintf_s (buffer, "%s.tp2",mName.c_str());return (const char*)buffer;}
protected:
	DpBirailSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BirailSrf(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DPBIRAILSRF_H__
