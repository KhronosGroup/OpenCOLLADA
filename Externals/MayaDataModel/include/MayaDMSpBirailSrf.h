/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SPBIRAILSRF_H__
#define __MayaDM_SPBIRAILSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBirailSrf.h"
namespace MayaDM
{
/*
The 'spBirailSrf' node computes a NURBS surface by sweeping
 a NURBS profile curve along two NURBS rail curves. The profile
 curve should intersect the two rails. The profile, rail curves
 can also be surface curves i.e. isoparams, curve on surfaces.
 <p/>
 By setting the attribute 'tangentContinuityProfile1' to true,
 the computed surface can be made tangent continuous w.r.t.
 the underlying surface of the profile curve. It must be noted
 that continuity is possible provided the profile is a surface
 curve.
 <p/>
 Using the attribute 'transformMode' the profiles can be scaled
 either proportionately or non proportionately. The scaling is
 done in x,y,z using an internal local coordinate frame. The
 following are legal values : 0 - Non proportional , 1 - proportional.
*/
class SpBirailSrf : public BirailSrf
{
public:
public:
	SpBirailSrf(FILE* file,const std::string& name,const std::string& parent=""):BirailSrf(file, name, parent, "spBirailSrf"){}
	virtual ~SpBirailSrf(){}
	/*profile curve*/
	void setInputProfile(const NurbsCurveID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip\";\n",mName.c_str());}
	/*Need to be tangent continuous across the profile. The profile must be a surface curve.*/
	void setTangentContinuityProfile1(bool tp1){if(tp1 == false) return; fprintf_s(mFile, "setAttr \".tp1\" %i;\n", tp1);}
	/*Need to be tangent continuous across the profile. The profile must be a surface curve.*/
	void setTangentContinuityProfile1(const BoolID& tp1){fprintf_s(mFile,"connectAttr \"");tp1.write(mFile);fprintf_s(mFile,"\" \"%s.tp1\";\n",mName.c_str());}
	/*profile curve*/
	NurbsCurveID getInputProfile(){char buffer[4096];sprintf_s (buffer, "%s.ip",mName.c_str());return (const char*)buffer;}
	/*Need to be tangent continuous across the profile. The profile must be a surface curve.*/
	BoolID getTangentContinuityProfile1(){char buffer[4096];sprintf_s (buffer, "%s.tp1",mName.c_str());return (const char*)buffer;}
protected:
	SpBirailSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BirailSrf(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SPBIRAILSRF_H__
