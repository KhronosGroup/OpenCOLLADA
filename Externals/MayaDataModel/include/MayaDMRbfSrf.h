/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RBFSRF_H__
#define __MayaDM_RBFSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The 'rbfSrf' node computes the circular ( rolling ball ) fillet
 given two NURBS surface and radii of the fillet. It may also be
 used to compute the curve on surfaces on the two input surface using
 the output attributes 'trimCurveOnPrimary', 'trimCurveOnSecondary`. The
 curve on surfaces are intersection tracks between the computed fillet
 and the two input surfaces respectively.
 <p/>
 The surface fillet can be computed to user specified position and
 tangent tolerance using the attributes 'positionTolerance' and
 'tangentTolerance' respectively.
*/
class RbfSrf : public AbstractBaseCreate
{
public:
public:
	RbfSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "rbfSrf"){}
	virtual ~RbfSrf(){}
	/*The input primary surface*/
	void setPrimarySurface(const NurbsSurfaceID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*The input secondary surface*/
	void setSecondarySurface(const NurbsSurfaceID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*primary Radius*/
	void setPrimaryRadius(double pr){if(pr == 1) return; fprintf_s(mFile, "setAttr \".pr\" %f;\n", pr);}
	/*primary Radius*/
	void setPrimaryRadius(const DoubleID& pr){fprintf_s(mFile,"connectAttr \"");pr.write(mFile);fprintf_s(mFile,"\" \"%s.pr\";\n",mName.c_str());}
	/*secondary Radius*/
	void setSecondaryRadius(double sr){if(sr == 1) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*secondary Radius*/
	void setSecondaryRadius(const DoubleID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*C(0) Tolerance For Fillet Surface*/
	void setPositionTolerance(double pt){if(pt == 0.01) return; fprintf_s(mFile, "setAttr \".pt\" %f;\n", pt);}
	/*C(0) Tolerance For Fillet Surface*/
	void setPositionTolerance(const DoubleID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*G(1) Tolerance For Fillet Surface*/
	void setTangentTolerance(double tt){if(tt == 0.01) return; fprintf_s(mFile, "setAttr \".tt\" %f;\n", tt);}
	/*G(1) Tolerance For Fillet Surface*/
	void setTangentTolerance(const DoubleID& tt){fprintf_s(mFile,"connectAttr \"");tt.write(mFile);fprintf_s(mFile,"\" \"%s.tt\";\n",mName.c_str());}
	/*Output surface*/
	void setOutputSurface(size_t os_i,const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i]\";\n",mName.c_str(),os_i);}
	/*Output 2d Trim curve(s) on primary  surface*/
	void setTrimCurveOnPrimary(size_t tcp_i,const NurbsCurveID& tcp){fprintf_s(mFile,"connectAttr \"");tcp.write(mFile);fprintf_s(mFile,"\" \"%s.tcp[%i]\";\n",mName.c_str(),tcp_i);}
	/*Output 2d Trim curve(s) on seondary  surface*/
	void setTrimCurveOnSecondary(size_t tcs_i,const NurbsCurveID& tcs){fprintf_s(mFile,"connectAttr \"");tcs.write(mFile);fprintf_s(mFile,"\" \"%s.tcs[%i]\";\n",mName.c_str(),tcs_i);}
	/*The input primary surface*/
	NurbsSurfaceID getPrimarySurface(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*The input secondary surface*/
	NurbsSurfaceID getSecondarySurface(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*primary Radius*/
	DoubleID getPrimaryRadius(){char buffer[4096];sprintf_s (buffer, "%s.pr",mName.c_str());return (const char*)buffer;}
	/*secondary Radius*/
	DoubleID getSecondaryRadius(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*C(0) Tolerance For Fillet Surface*/
	DoubleID getPositionTolerance(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*G(1) Tolerance For Fillet Surface*/
	DoubleID getTangentTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tt",mName.c_str());return (const char*)buffer;}
	/*Output surface*/
	const NurbsSurfaceID& getOutputSurface(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i]",mName.c_str(),os_i);return (const char*)buffer;}
	/*Output 2d Trim curve(s) on primary  surface*/
	const NurbsCurveID& getTrimCurveOnPrimary(size_t tcp_i){char buffer[4096];sprintf_s (buffer, "%s.tcp[%i]",mName.c_str(),tcp_i);return (const char*)buffer;}
	/*Output 2d Trim curve(s) on seondary  surface*/
	const NurbsCurveID& getTrimCurveOnSecondary(size_t tcs_i){char buffer[4096];sprintf_s (buffer, "%s.tcs[%i]",mName.c_str(),tcs_i);return (const char*)buffer;}
protected:
	RbfSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RBFSRF_H__
