/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEINTERSECT_H__
#define __MayaDM_CURVEINTERSECT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
This dependency node finds the intersections between two curves.
                If the "useDirection" attribute is on, then the two input
                curves are projected in the specified direction before being
                intersected.  For example, if two curves "appear" to intersect
                in an orthographic view, this dependency node can be used to
                find those intersections.<br/>

                This node outputs the parameter values on each curve where it is
                intersected.  When the number of intersections increases, the
                number of output parameters (attributes "parameter1" and "parameter2")
                increases.  When the number of intersections decreases, the
                number of output parameters REMAINS THE SAME.  For example,
                if a pair of curves intersect twice, the output attribute "parameter1"
                will have two values.  If one of the curves is moved such that there is
                now only one intersection, the output attribute will still have two
                values.  The second value will have the default parameter value,
                123456.0.  Thus, if these parameter values were connected to other
                objects, the connections will remain intact.

 <p/>
*/
class CurveIntersect : public AbstractBaseCreate
{
public:
public:
	CurveIntersect(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "curveIntersect"){}
	virtual ~CurveIntersect(){}
	/*The first input curve.*/
	void setInputCurve1(const NurbsCurveID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.ic1\";\n",mName.c_str());}
	/*The second input curve.*/
	void setInputCurve2(const NurbsCurveID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.ic2\";\n",mName.c_str());}
	/*Tolerance within which the curves must be to intersect.*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*Tolerance within which the curves must be to intersect.*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*If true, use direction attribute.  Curves are first projected in a specified direction, and then intersected.  If false, only find true 3D intersections.*/
	void setUseDirection(bool ud){if(ud == false) return; fprintf_s(mFile, "setAttr \".ud\" %i;\n", ud);}
	/*If true, use direction attribute.  Curves are first projected in a specified direction, and then intersected.  If false, only find true 3D intersections.*/
	void setUseDirection(const BoolID& ud){fprintf_s(mFile,"connectAttr \"");ud.write(mFile);fprintf_s(mFile,"\" \"%s.ud\";\n",mName.c_str());}
	/*Direction in which to project and find intersection.  This is only used when the useDirection attribute is true.  This direction vector must be of non-zero length.*/
	void setDirection(const double3& d){fprintf_s(mFile, "setAttr \".d\" -type \"double3\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*Direction in which to project and find intersection.  This is only used when the useDirection attribute is true.  This direction vector must be of non-zero length.*/
	void setDirection(const Double3ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*X direction of projection.*/
	void setDirectionX(double dx){if(dx == 0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*X direction of projection.*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*Y direction of projection.*/
	void setDirectionY(double dy){if(dy == 1) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*Y direction of projection.*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*Z direction of projection.*/
	void setDirectionZ(double dz){if(dz == 0) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*Z direction of projection.*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*Parameters on 1st curve where 1st curve is intersected by the 2nd curve*/
	void setParameter1(size_t p1_i,const DoubleID& p1){fprintf_s(mFile,"connectAttr \"");p1.write(mFile);fprintf_s(mFile,"\" \"%s.p1[%i]\";\n",mName.c_str(),p1_i);}
	/*Parameters on 2nd curve where 2nd curve is intersected by the 1st curve*/
	void setParameter2(size_t p2_i,const DoubleID& p2){fprintf_s(mFile,"connectAttr \"");p2.write(mFile);fprintf_s(mFile,"\" \"%s.p2[%i]\";\n",mName.c_str(),p2_i);}
	/*The first input curve.*/
	NurbsCurveID getInputCurve1(){char buffer[4096];sprintf_s (buffer, "%s.ic1",mName.c_str());return (const char*)buffer;}
	/*The second input curve.*/
	NurbsCurveID getInputCurve2(){char buffer[4096];sprintf_s (buffer, "%s.ic2",mName.c_str());return (const char*)buffer;}
	/*Tolerance within which the curves must be to intersect.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*If true, use direction attribute.  Curves are first projected in a specified direction, and then intersected.  If false, only find true 3D intersections.*/
	BoolID getUseDirection(){char buffer[4096];sprintf_s (buffer, "%s.ud",mName.c_str());return (const char*)buffer;}
	/*Direction in which to project and find intersection.  This is only used when the useDirection attribute is true.  This direction vector must be of non-zero length.*/
	Double3ID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*X direction of projection.*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*Y direction of projection.*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*Z direction of projection.*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
	/*Parameters on 1st curve where 1st curve is intersected by the 2nd curve*/
	const DoubleID& getParameter1(size_t p1_i){char buffer[4096];sprintf_s (buffer, "%s.p1[%i]",mName.c_str(),p1_i);return (const char*)buffer;}
	/*Parameters on 2nd curve where 2nd curve is intersected by the 1st curve*/
	const DoubleID& getParameter2(size_t p2_i){char buffer[4096];sprintf_s (buffer, "%s.p2[%i]",mName.c_str(),p2_i);return (const char*)buffer;}
protected:
	CurveIntersect(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEINTERSECT_H__
