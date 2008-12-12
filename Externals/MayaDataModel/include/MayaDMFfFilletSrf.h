/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FFFILLETSRF_H__
#define __MayaDM_FFFILLETSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The ffFilletSrf node computes a surface fillet given two NURBS surface
 curves. The input surface curves may be isoparams or trimmed edges. Using the
 attributes 'positionTolerance' and 'tangentTolerance', the filleted surface can be
 built to user specified positional or tangent tolerances respectively. The shape of
 surface fillet may be modified using the blend controls bias and depth. Using the
 attribute `depth', the magnitudes of the tangents on the surface fillet at either
 end of the surface curves may be scaled. The attribute 'bias' controls the deviation
 of the surface fillet from the tangent planes across the two surfaces curves.
 <p/>
 Could be used to fill the gap in between two NURBS surfaces.
*/
class FfFilletSrf : public AbstractBaseCreate
{
public:
public:
	FfFilletSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "ffFilletSrf"){}
	virtual ~FfFilletSrf(){}
	/*Surface curve on the left.*/
	void setLeftCurve(const NurbsCurveID& lc){fprintf_s(mFile,"connectAttr \"");lc.write(mFile);fprintf_s(mFile,"\" \"%s.lc\";\n",mName.c_str());}
	/*Surface curve on the right.*/
	void setRightCurve(const NurbsCurveID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc\";\n",mName.c_str());}
	/*C(0) Tolerance For Filleted Surface creation*/
	void setPositionTolerance(double pt){if(pt == 0.1) return; fprintf_s(mFile, "setAttr \".pt\" %f;\n", pt);}
	/*C(0) Tolerance For Filleted Surface creation*/
	void setPositionTolerance(const DoubleID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*G(1) continuity Tolerance For Filleted Surface creation*/
	void setTangentTolerance(double tt){if(tt == 0.1) return; fprintf_s(mFile, "setAttr \".tt\" %f;\n", tt);}
	/*G(1) continuity Tolerance For Filleted Surface creation*/
	void setTangentTolerance(const DoubleID& tt){fprintf_s(mFile,"connectAttr \"");tt.write(mFile);fprintf_s(mFile,"\" \"%s.tt\";\n",mName.c_str());}
	/*Depth value for fillet*/
	void setDepth(double d){if(d == 0.5) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*Depth value for fillet*/
	void setDepth(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Bias value for fillet*/
	void setBias(double b){if(b == 0.5) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*Bias value for fillet*/
	void setBias(const DoubleID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*Output Fillet Surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*Surface curve on the left.*/
	NurbsCurveID getLeftCurve(){char buffer[4096];sprintf_s (buffer, "%s.lc",mName.c_str());return (const char*)buffer;}
	/*Surface curve on the right.*/
	NurbsCurveID getRightCurve(){char buffer[4096];sprintf_s (buffer, "%s.rc",mName.c_str());return (const char*)buffer;}
	/*C(0) Tolerance For Filleted Surface creation*/
	DoubleID getPositionTolerance(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*G(1) continuity Tolerance For Filleted Surface creation*/
	DoubleID getTangentTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tt",mName.c_str());return (const char*)buffer;}
	/*Depth value for fillet*/
	DoubleID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Bias value for fillet*/
	DoubleID getBias(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*Output Fillet Surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	FfFilletSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FFFILLETSRF_H__
