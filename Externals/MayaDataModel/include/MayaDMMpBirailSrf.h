/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MPBIRAILSRF_H__
#define __MayaDM_MPBIRAILSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBirailSrf.h"
namespace MayaDM
{
/*
The 'mpBirailSrf' node computes a NURBS surface by sweeping
 a NURBS profile towards each of the other profiles along two
 given NURBS rail curves. The profiles should intersect the
 rail curves. The profiles, rails can also be surface curves
 i.e. isoparms, curve on surface, trimmed edges.
 <p/>
 The attributes 'tangentContinuityProfile1' and 'tangentContinuityProfile2'
 can be set to true if the surface is to be tangent continuous with
 the first and last profile curve respectively.
*/
class MpBirailSrf : public BirailSrf
{
public:
public:
	MpBirailSrf(FILE* file,const std::string& name,const std::string& parent=""):BirailSrf(file, name, parent, "mpBirailSrf"){}
	virtual ~MpBirailSrf(){}
	/*one or more profile curves*/
	void setInputProfile(size_t ip_i,const NurbsCurveID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip[%i]\";\n",mName.c_str(),ip_i);}
	/*Tangent continuous across the first profile. The profile must be a surface curve.*/
	void setTangentContinuityProfile1(bool tp1){if(tp1 == false) return; fprintf_s(mFile, "setAttr \".tp1\" %i;\n", tp1);}
	/*Tangent continuous across the first profile. The profile must be a surface curve.*/
	void setTangentContinuityProfile1(const BoolID& tp1){fprintf_s(mFile,"connectAttr \"");tp1.write(mFile);fprintf_s(mFile,"\" \"%s.tp1\";\n",mName.c_str());}
	/*Tangent continuous across the last profile. The profile must be a surface curve.*/
	void setTangentContinuityProfile2(bool tp2){if(tp2 == false) return; fprintf_s(mFile, "setAttr \".tp2\" %i;\n", tp2);}
	/*Tangent continuous across the last profile. The profile must be a surface curve.*/
	void setTangentContinuityProfile2(const BoolID& tp2){fprintf_s(mFile,"connectAttr \"");tp2.write(mFile);fprintf_s(mFile,"\" \"%s.tp2\";\n",mName.c_str());}
	/*one or more profile curves*/
	const NurbsCurveID& getInputProfile(size_t ip_i){char buffer[4096];sprintf_s (buffer, "%s.ip[%i]",mName.c_str(),ip_i);return (const char*)buffer;}
	/*Tangent continuous across the first profile. The profile must be a surface curve.*/
	BoolID getTangentContinuityProfile1(){char buffer[4096];sprintf_s (buffer, "%s.tp1",mName.c_str());return (const char*)buffer;}
	/*Tangent continuous across the last profile. The profile must be a surface curve.*/
	BoolID getTangentContinuityProfile2(){char buffer[4096];sprintf_s (buffer, "%s.tp2",mName.c_str());return (const char*)buffer;}
protected:
	MpBirailSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BirailSrf(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MPBIRAILSRF_H__
