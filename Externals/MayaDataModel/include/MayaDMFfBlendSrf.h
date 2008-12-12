/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FFBLENDSRF_H__
#define __MayaDM_FFBLENDSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute a freeform surface that blends between two surface rails.
 Each rail may
 consist of one or more surface curves on one or more surfaces.
 The tangent direction the blended surface leaves each rail is determined by
 flipLeft and flipRight.
 <p/>
*/
class FfBlendSrf : public AbstractBaseCreate
{
public:
public:
	FfBlendSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "ffBlendSrf"){}
	virtual ~FfBlendSrf(){}
	/*The surface curves comprising the left boundary.*/
	void setLeftCurve(size_t lc_i,const NurbsCurveID& lc){fprintf_s(mFile,"connectAttr \"");lc.write(mFile);fprintf_s(mFile,"\" \"%s.lc[%i]\";\n",mName.c_str(),lc_i);}
	/*The surface curves comprising the right boundary.*/
	void setRightCurve(size_t rc_i,const NurbsCurveID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc[%i]\";\n",mName.c_str(),rc_i);}
	/*The left rail boundary.*/
	void setLeftRail(const NurbsCurveID& lr){fprintf_s(mFile,"connectAttr \"");lr.write(mFile);fprintf_s(mFile,"\" \"%s.lr\";\n",mName.c_str());}
	/*The right rail boundary.*/
	void setRightRail(const NurbsCurveID& rr){fprintf_s(mFile,"connectAttr \"");rr.write(mFile);fprintf_s(mFile,"\" \"%s.rr\";\n",mName.c_str());}
	/*If true, use the new blend which produces fully multiple interior knots*/
	void setMultipleKnots(bool mk){if(mk == true) return; fprintf_s(mFile, "setAttr \".mk\" %i;\n", mk);}
	/*If true, use the new blend which produces fully multiple interior knots*/
	void setMultipleKnots(const BoolID& mk){fprintf_s(mFile,"connectAttr \"");mk.write(mFile);fprintf_s(mFile,"\" \"%s.mk\";\n",mName.c_str());}
	/*The positional C(0) tolerance of the blend surface to the adjacent surfaces.*/
	void setPositionTolerance(double pt){if(pt == 0.1) return; fprintf_s(mFile, "setAttr \".pt\" %f;\n", pt);}
	/*The positional C(0) tolerance of the blend surface to the adjacent surfaces.*/
	void setPositionTolerance(const DoubleID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*The tangent G(1) continuity tolerance of the blend surface to the adjacent surfaces.*/
	void setTangentTolerance(double tt){if(tt == 0.1) return; fprintf_s(mFile, "setAttr \".tt\" %f;\n", tt);}
	/*The tangent G(1) continuity tolerance of the blend surface to the adjacent surfaces.*/
	void setTangentTolerance(const DoubleID& tt){fprintf_s(mFile,"connectAttr \"");tt.write(mFile);fprintf_s(mFile,"\" \"%s.tt\";\n",mName.c_str());}
	/*If true, the direction of each starting tangent is computed based on given geometry.*/
	void setAutoNormal(bool an){if(an == true) return; fprintf_s(mFile, "setAttr \".an\" %i;\n", an);}
	/*If true, the direction of each starting tangent is computed based on given geometry.*/
	void setAutoNormal(const BoolID& an){fprintf_s(mFile,"connectAttr \"");an.write(mFile);fprintf_s(mFile,"\" \"%s.an\";\n",mName.c_str());}
	/*If true, flip the starting tangent off the left boundary.*/
	void setFlipLeftNormal(bool fln){if(fln == false) return; fprintf_s(mFile, "setAttr \".fln\" %i;\n", fln);}
	/*If true, flip the starting tangent off the left boundary.*/
	void setFlipLeftNormal(const BoolID& fln){fprintf_s(mFile,"connectAttr \"");fln.write(mFile);fprintf_s(mFile,"\" \"%s.fln\";\n",mName.c_str());}
	/*If true, flip the starting tangent off the right boundary.*/
	void setFlipRightNormal(bool frn){if(frn == false) return; fprintf_s(mFile, "setAttr \".frn\" %i;\n", frn);}
	/*If true, flip the starting tangent off the right boundary.*/
	void setFlipRightNormal(const BoolID& frn){fprintf_s(mFile,"connectAttr \"");frn.write(mFile);fprintf_s(mFile,"\" \"%s.frn\";\n",mName.c_str());}
	/*If true and both paths are closed, automatically determine the value on the right rail so that they match*/
	void setAutoAnchor(bool aa){if(aa == true) return; fprintf_s(mFile, "setAttr \".aa\" %i;\n", aa);}
	/*If true and both paths are closed, automatically determine the value on the right rail so that they match*/
	void setAutoAnchor(const BoolID& aa){fprintf_s(mFile,"connectAttr \"");aa.write(mFile);fprintf_s(mFile,"\" \"%s.aa\";\n",mName.c_str());}
	/*The reference parameter on the left boundary where the blend surface starts in the case of the closed rail.*/
	void setLeftAnchor(double la){if(la == 0.0) return; fprintf_s(mFile, "setAttr \".la\" %f;\n", la);}
	/*The reference parameter on the left boundary where the blend surface starts in the case of the closed rail.*/
	void setLeftAnchor(const DoubleID& la){fprintf_s(mFile,"connectAttr \"");la.write(mFile);fprintf_s(mFile,"\" \"%s.la\";\n",mName.c_str());}
	/*The reference parameter on the left boundary where the blend surface starts.*/
	void setLeftStart(double ls){if(ls == 0.0) return; fprintf_s(mFile, "setAttr \".ls\" %f;\n", ls);}
	/*The reference parameter on the left boundary where the blend surface starts.*/
	void setLeftStart(const DoubleID& ls){fprintf_s(mFile,"connectAttr \"");ls.write(mFile);fprintf_s(mFile,"\" \"%s.ls\";\n",mName.c_str());}
	/*The reference parameter on the left boundary where the blend surface ends.*/
	void setLeftEnd(double le){if(le == 1.0) return; fprintf_s(mFile, "setAttr \".le\" %f;\n", le);}
	/*The reference parameter on the left boundary where the blend surface ends.*/
	void setLeftEnd(const DoubleID& le){fprintf_s(mFile,"connectAttr \"");le.write(mFile);fprintf_s(mFile,"\" \"%s.le\";\n",mName.c_str());}
	/*If true, reverse the direction off the left boundary.  autoDirection must be false for this value to be considered.*/
	void setReverseLeft(bool rvl){if(rvl == false) return; fprintf_s(mFile, "setAttr \".rvl\" %i;\n", rvl);}
	/*If true, reverse the direction off the left boundary.  autoDirection must be false for this value to be considered.*/
	void setReverseLeft(const BoolID& rvl){fprintf_s(mFile,"connectAttr \"");rvl.write(mFile);fprintf_s(mFile,"\" \"%s.rvl\";\n",mName.c_str());}
	/*The reference parameter on the right boundary where the blend surface starts in the case of the closed rail.*/
	void setRightAnchor(double ra){if(ra == 0.0) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*The reference parameter on the right boundary where the blend surface starts in the case of the closed rail.*/
	void setRightAnchor(const DoubleID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*The reference parameter on the right boundary where the blend surface starts.*/
	void setRightStart(double rs){if(rs == 0.0) return; fprintf_s(mFile, "setAttr \".rs\" %f;\n", rs);}
	/*The reference parameter on the right boundary where the blend surface starts.*/
	void setRightStart(const DoubleID& rs){fprintf_s(mFile,"connectAttr \"");rs.write(mFile);fprintf_s(mFile,"\" \"%s.rs\";\n",mName.c_str());}
	/*The reference parameter on the right boundary where the blend surface ends.*/
	void setRightEnd(double re){if(re == 1.0) return; fprintf_s(mFile, "setAttr \".re\" %f;\n", re);}
	/*The reference parameter on the right boundary where the blend surface ends.*/
	void setRightEnd(const DoubleID& re){fprintf_s(mFile,"connectAttr \"");re.write(mFile);fprintf_s(mFile,"\" \"%s.re\";\n",mName.c_str());}
	/*If true, reverse the direction of the right boundary.  autoDirection must be false for this value to be considered.*/
	void setReverseRight(bool rvr){if(rvr == false) return; fprintf_s(mFile, "setAttr \".rvr\" %i;\n", rvr);}
	/*If true, reverse the direction of the right boundary.  autoDirection must be false for this value to be considered.*/
	void setReverseRight(const BoolID& rvr){fprintf_s(mFile,"connectAttr \"");rvr.write(mFile);fprintf_s(mFile,"\" \"%s.rvr\";\n",mName.c_str());}
	/*The computed blend surface.*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The surface curves comprising the left boundary.*/
	const NurbsCurveID& getLeftCurve(size_t lc_i){char buffer[4096];sprintf_s (buffer, "%s.lc[%i]",mName.c_str(),lc_i);return (const char*)buffer;}
	/*The surface curves comprising the right boundary.*/
	const NurbsCurveID& getRightCurve(size_t rc_i){char buffer[4096];sprintf_s (buffer, "%s.rc[%i]",mName.c_str(),rc_i);return (const char*)buffer;}
	/*The left rail boundary.*/
	NurbsCurveID getLeftRail(){char buffer[4096];sprintf_s (buffer, "%s.lr",mName.c_str());return (const char*)buffer;}
	/*The right rail boundary.*/
	NurbsCurveID getRightRail(){char buffer[4096];sprintf_s (buffer, "%s.rr",mName.c_str());return (const char*)buffer;}
	/*If true, use the new blend which produces fully multiple interior knots*/
	BoolID getMultipleKnots(){char buffer[4096];sprintf_s (buffer, "%s.mk",mName.c_str());return (const char*)buffer;}
	/*The positional C(0) tolerance of the blend surface to the adjacent surfaces.*/
	DoubleID getPositionTolerance(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*The tangent G(1) continuity tolerance of the blend surface to the adjacent surfaces.*/
	DoubleID getTangentTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tt",mName.c_str());return (const char*)buffer;}
	/*If true, the direction of each starting tangent is computed based on given geometry.*/
	BoolID getAutoNormal(){char buffer[4096];sprintf_s (buffer, "%s.an",mName.c_str());return (const char*)buffer;}
	/*If true, flip the starting tangent off the left boundary.*/
	BoolID getFlipLeftNormal(){char buffer[4096];sprintf_s (buffer, "%s.fln",mName.c_str());return (const char*)buffer;}
	/*If true, flip the starting tangent off the right boundary.*/
	BoolID getFlipRightNormal(){char buffer[4096];sprintf_s (buffer, "%s.frn",mName.c_str());return (const char*)buffer;}
	/*If true and both paths are closed, automatically determine the value on the right rail so that they match*/
	BoolID getAutoAnchor(){char buffer[4096];sprintf_s (buffer, "%s.aa",mName.c_str());return (const char*)buffer;}
	/*The reference parameter on the left boundary where the blend surface starts in the case of the closed rail.*/
	DoubleID getLeftAnchor(){char buffer[4096];sprintf_s (buffer, "%s.la",mName.c_str());return (const char*)buffer;}
	/*The reference parameter on the left boundary where the blend surface starts.*/
	DoubleID getLeftStart(){char buffer[4096];sprintf_s (buffer, "%s.ls",mName.c_str());return (const char*)buffer;}
	/*The reference parameter on the left boundary where the blend surface ends.*/
	DoubleID getLeftEnd(){char buffer[4096];sprintf_s (buffer, "%s.le",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the direction off the left boundary.  autoDirection must be false for this value to be considered.*/
	BoolID getReverseLeft(){char buffer[4096];sprintf_s (buffer, "%s.rvl",mName.c_str());return (const char*)buffer;}
	/*The reference parameter on the right boundary where the blend surface starts in the case of the closed rail.*/
	DoubleID getRightAnchor(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*The reference parameter on the right boundary where the blend surface starts.*/
	DoubleID getRightStart(){char buffer[4096];sprintf_s (buffer, "%s.rs",mName.c_str());return (const char*)buffer;}
	/*The reference parameter on the right boundary where the blend surface ends.*/
	DoubleID getRightEnd(){char buffer[4096];sprintf_s (buffer, "%s.re",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the direction of the right boundary.  autoDirection must be false for this value to be considered.*/
	BoolID getReverseRight(){char buffer[4096];sprintf_s (buffer, "%s.rvr",mName.c_str());return (const char*)buffer;}
	/*The computed blend surface.*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	FfBlendSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FFBLENDSRF_H__
