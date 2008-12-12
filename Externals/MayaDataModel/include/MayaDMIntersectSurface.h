/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_INTERSECTSURFACE_H__
#define __MayaDM_INTERSECTSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute the intersection curve(s) given two surfaces. 2D results are output
 in curveOnSurface1 (for curves on first surface) and curveOnSurface2 (for
 curves on second surface if needed). 3D results are output in output3dCurve
 (if needed). Both 2D and 3D results are not available, only one type
 depending on how the node was connected.
 <p/>
*/
class IntersectSurface : public AbstractBaseCreate
{
public:
public:
	IntersectSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "intersectSurface"){}
	virtual ~IntersectSurface(){}
	/*The first input surface.*/
	void setInputSurface1(const NurbsSurfaceID& is1){fprintf_s(mFile,"connectAttr \"");is1.write(mFile);fprintf_s(mFile,"\" \"%s.is1\";\n",mName.c_str());}
	/*The second input surface.*/
	void setInputSurface2(const NurbsSurfaceID& is2){fprintf_s(mFile,"connectAttr \"");is2.write(mFile);fprintf_s(mFile,"\" \"%s.is2\";\n",mName.c_str());}
	/*Output curve(s) on surface on first surface.*/
	void setCurveOnSurface1(size_t cs1_i,const NurbsCurveID& cs1){fprintf_s(mFile,"connectAttr \"");cs1.write(mFile);fprintf_s(mFile,"\" \"%s.cs1[%i]\";\n",mName.c_str(),cs1_i);}
	/*Output curve(s) on surface on second surface.*/
	void setCurveOnSurface2(size_t cs2_i,const NurbsCurveID& cs2){fprintf_s(mFile,"connectAttr \"");cs2.write(mFile);fprintf_s(mFile,"\" \"%s.cs2[%i]\";\n",mName.c_str(),cs2_i);}
	/*Output 3D curve(s).*/
	void setOutput3dCurve(size_t oc_i,const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc[%i]\";\n",mName.c_str(),oc_i);}
	/*Tolerance to fit to.*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*Tolerance to fit to.*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*The first input surface.*/
	NurbsSurfaceID getInputSurface1(){char buffer[4096];sprintf_s (buffer, "%s.is1",mName.c_str());return (const char*)buffer;}
	/*The second input surface.*/
	NurbsSurfaceID getInputSurface2(){char buffer[4096];sprintf_s (buffer, "%s.is2",mName.c_str());return (const char*)buffer;}
	/*Output curve(s) on surface on first surface.*/
	const NurbsCurveID& getCurveOnSurface1(size_t cs1_i){char buffer[4096];sprintf_s (buffer, "%s.cs1[%i]",mName.c_str(),cs1_i);return (const char*)buffer;}
	/*Output curve(s) on surface on second surface.*/
	const NurbsCurveID& getCurveOnSurface2(size_t cs2_i){char buffer[4096];sprintf_s (buffer, "%s.cs2[%i]",mName.c_str(),cs2_i);return (const char*)buffer;}
	/*Output 3D curve(s).*/
	const NurbsCurveID& getOutput3dCurve(size_t oc_i){char buffer[4096];sprintf_s (buffer, "%s.oc[%i]",mName.c_str(),oc_i);return (const char*)buffer;}
	/*Tolerance to fit to.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
protected:
	IntersectSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_INTERSECTSURFACE_H__
