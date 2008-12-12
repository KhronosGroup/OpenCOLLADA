/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FFBLENDSRFOBSOLETE_H__
#define __MayaDM_FFBLENDSRFOBSOLETE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
OBSOLETE: See ffBlendSrf node.
 Compute a freeform surface that blends between two surface rails.
 Each rail may
 consist of one or more surface curves on one or more surfaces.
 The tangent direction the blended surface leaves each rail is determined by
 flipLeft and flipRight. The blended surface can be twisted by using
 leftParameter and rightParameter.
 <p/>
*/
class FfBlendSrfObsolete : public AbstractBaseCreate
{
public:
public:
	FfBlendSrfObsolete(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "ffBlendSrfObsolete"){}
	virtual ~FfBlendSrfObsolete(){}
	/*The surface curves comprising the left boundary.*/
	void setLeftCurve(size_t lc_i,const NurbsCurveID& lc){fprintf_s(mFile,"connectAttr \"");lc.write(mFile);fprintf_s(mFile,"\" \"%s.lc[%i]\";\n",mName.c_str(),lc_i);}
	/*The surface curves comprising the right boundary.*/
	void setRightCurve(size_t rc_i,const NurbsCurveID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc[%i]\";\n",mName.c_str(),rc_i);}
	/*The positional C(0) tolerance of the blend surface to the adjacent surfaces.*/
	void setPositionTolerance(double pt){if(pt == 0.1) return; fprintf_s(mFile, "setAttr \".pt\" %f;\n", pt);}
	/*The positional C(0) tolerance of the blend surface to the adjacent surfaces.*/
	void setPositionTolerance(const DoubleID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*The tangent G(1) continuity tolerance of the blend surface to the adjacent surfaces.*/
	void setTangentTolerance(double tt){if(tt == 0.1) return; fprintf_s(mFile, "setAttr \".tt\" %f;\n", tt);}
	/*The tangent G(1) continuity tolerance of the blend surface to the adjacent surfaces.*/
	void setTangentTolerance(const DoubleID& tt){fprintf_s(mFile,"connectAttr \"");tt.write(mFile);fprintf_s(mFile,"\" \"%s.tt\";\n",mName.c_str());}
	/*If true, flip the starting tangent off the left boundary.*/
	void setFlipLeft(bool fl){if(fl == false) return; fprintf_s(mFile, "setAttr \".fl\" %i;\n", fl);}
	/*If true, flip the starting tangent off the left boundary.*/
	void setFlipLeft(const BoolID& fl){fprintf_s(mFile,"connectAttr \"");fl.write(mFile);fprintf_s(mFile,"\" \"%s.fl\";\n",mName.c_str());}
	/*If true, flip the starting tangent off the right boundary.*/
	void setFlipRight(bool fr){if(fr == false) return; fprintf_s(mFile, "setAttr \".fr\" %i;\n", fr);}
	/*If true, flip the starting tangent off the right boundary.*/
	void setFlipRight(const BoolID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*If true, the direction of each starting tangent is computed based on given geometry.*/
	void setAutoDirection(bool ad){if(ad == true) return; fprintf_s(mFile, "setAttr \".ad\" %i;\n", ad);}
	/*If true, the direction of each starting tangent is computed based on given geometry.*/
	void setAutoDirection(const BoolID& ad){fprintf_s(mFile,"connectAttr \"");ad.write(mFile);fprintf_s(mFile,"\" \"%s.ad\";\n",mName.c_str());}
	/*The left rail boundary.*/
	void setLeftRail(const NurbsCurveID& lr){fprintf_s(mFile,"connectAttr \"");lr.write(mFile);fprintf_s(mFile,"\" \"%s.lr\";\n",mName.c_str());}
	/*The right rail boundary.*/
	void setRightRail(const NurbsCurveID& rr){fprintf_s(mFile,"connectAttr \"");rr.write(mFile);fprintf_s(mFile,"\" \"%s.rr\";\n",mName.c_str());}
	/*The reference parameter on the left boundary where the blend surface begins.*/
	void setLeftParameter(double lp){if(lp == 123456.0) return; fprintf_s(mFile, "setAttr \".lp\" %f;\n", lp);}
	/*The reference parameter on the left boundary where the blend surface begins.*/
	void setLeftParameter(const DoubleID& lp){fprintf_s(mFile,"connectAttr \"");lp.write(mFile);fprintf_s(mFile,"\" \"%s.lp\";\n",mName.c_str());}
	/*The reference parameter on the right boundary where the blend surface begins.*/
	void setRightParameter(double rp){if(rp == 123456.0) return; fprintf_s(mFile, "setAttr \".rp\" %f;\n", rp);}
	/*The reference parameter on the right boundary where the blend surface begins.*/
	void setRightParameter(const DoubleID& rp){fprintf_s(mFile,"connectAttr \"");rp.write(mFile);fprintf_s(mFile,"\" \"%s.rp\";\n",mName.c_str());}
	/*The created blend surface.*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*If true, use the new blend which produces fully multiple interior knots*/
	void setMultipleKnots(bool mk){if(mk == true) return; fprintf_s(mFile, "setAttr \".mk\" %i;\n", mk);}
	/*If true, use the new blend which produces fully multiple interior knots*/
	void setMultipleKnots(const BoolID& mk){fprintf_s(mFile,"connectAttr \"");mk.write(mFile);fprintf_s(mFile,"\" \"%s.mk\";\n",mName.c_str());}
	/*The surface curves comprising the left boundary.*/
	const NurbsCurveID& getLeftCurve(size_t lc_i){char buffer[4096];sprintf_s (buffer, "%s.lc[%i]",mName.c_str(),lc_i);return (const char*)buffer;}
	/*The surface curves comprising the right boundary.*/
	const NurbsCurveID& getRightCurve(size_t rc_i){char buffer[4096];sprintf_s (buffer, "%s.rc[%i]",mName.c_str(),rc_i);return (const char*)buffer;}
	/*The positional C(0) tolerance of the blend surface to the adjacent surfaces.*/
	DoubleID getPositionTolerance(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*The tangent G(1) continuity tolerance of the blend surface to the adjacent surfaces.*/
	DoubleID getTangentTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tt",mName.c_str());return (const char*)buffer;}
	/*If true, flip the starting tangent off the left boundary.*/
	BoolID getFlipLeft(){char buffer[4096];sprintf_s (buffer, "%s.fl",mName.c_str());return (const char*)buffer;}
	/*If true, flip the starting tangent off the right boundary.*/
	BoolID getFlipRight(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*If true, the direction of each starting tangent is computed based on given geometry.*/
	BoolID getAutoDirection(){char buffer[4096];sprintf_s (buffer, "%s.ad",mName.c_str());return (const char*)buffer;}
	/*The left rail boundary.*/
	NurbsCurveID getLeftRail(){char buffer[4096];sprintf_s (buffer, "%s.lr",mName.c_str());return (const char*)buffer;}
	/*The right rail boundary.*/
	NurbsCurveID getRightRail(){char buffer[4096];sprintf_s (buffer, "%s.rr",mName.c_str());return (const char*)buffer;}
	/*The reference parameter on the left boundary where the blend surface begins.*/
	DoubleID getLeftParameter(){char buffer[4096];sprintf_s (buffer, "%s.lp",mName.c_str());return (const char*)buffer;}
	/*The reference parameter on the right boundary where the blend surface begins.*/
	DoubleID getRightParameter(){char buffer[4096];sprintf_s (buffer, "%s.rp",mName.c_str());return (const char*)buffer;}
	/*The created blend surface.*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*If true, use the new blend which produces fully multiple interior knots*/
	BoolID getMultipleKnots(){char buffer[4096];sprintf_s (buffer, "%s.mk",mName.c_str());return (const char*)buffer;}
protected:
	FfBlendSrfObsolete(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FFBLENDSRFOBSOLETE_H__
