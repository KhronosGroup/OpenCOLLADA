/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BOUNDARYBASE_H__
#define __MayaDM_BOUNDARYBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Creates a surface from three or four input curves. This is used by boundary
 and square.
 <p/>
 If only three curves are used as inputs, then the first curve
 can be roughly thought of as a "profile" curve that runs along the other
 two curves, which act as "rails".
 <p/>
 If four curves are used as inputs, then the first and third curves
 can be roughly thought of as a "profile" curves that runs along the other
 two curves, which act as "rails".
*/
class BoundaryBase : public AbstractBaseCreate
{
public:
public:
	BoundaryBase(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "boundaryBase"){}
	virtual ~BoundaryBase(){}
	/*The first input curve*/
	void setInputCurve1(const NurbsCurveID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.ic1\";\n",mName.c_str());}
	/*The second input curve*/
	void setInputCurve2(const NurbsCurveID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.ic2\";\n",mName.c_str());}
	/*The third input curve*/
	void setInputCurve3(const NurbsCurveID& ic3){fprintf_s(mFile,"connectAttr \"");ic3.write(mFile);fprintf_s(mFile,"\" \"%s.ic3\";\n",mName.c_str());}
	/*The fourth input curve (optional)*/
	void setInputCurve4(const NurbsCurveID& ic4){fprintf_s(mFile,"connectAttr \"");ic4.write(mFile);fprintf_s(mFile,"\" \"%s.ic4\";\n",mName.c_str());}
	/*Tolerance for end points, only used if endPoint attribute is true.*/
	void setEndPointTolerance(double ept){if(ept == 0) return; fprintf_s(mFile, "setAttr \".ept\" %f;\n", ept);}
	/*Tolerance for end points, only used if endPoint attribute is true.*/
	void setEndPointTolerance(const DoubleID& ept){fprintf_s(mFile,"connectAttr \"");ept.write(mFile);fprintf_s(mFile,"\" \"%s.ept\";\n",mName.c_str());}
	/*Output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The first input curve*/
	NurbsCurveID getInputCurve1(){char buffer[4096];sprintf_s (buffer, "%s.ic1",mName.c_str());return (const char*)buffer;}
	/*The second input curve*/
	NurbsCurveID getInputCurve2(){char buffer[4096];sprintf_s (buffer, "%s.ic2",mName.c_str());return (const char*)buffer;}
	/*The third input curve*/
	NurbsCurveID getInputCurve3(){char buffer[4096];sprintf_s (buffer, "%s.ic3",mName.c_str());return (const char*)buffer;}
	/*The fourth input curve (optional)*/
	NurbsCurveID getInputCurve4(){char buffer[4096];sprintf_s (buffer, "%s.ic4",mName.c_str());return (const char*)buffer;}
	/*Tolerance for end points, only used if endPoint attribute is true.*/
	DoubleID getEndPointTolerance(){char buffer[4096];sprintf_s (buffer, "%s.ept",mName.c_str());return (const char*)buffer;}
	/*Output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	BoundaryBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BOUNDARYBASE_H__
