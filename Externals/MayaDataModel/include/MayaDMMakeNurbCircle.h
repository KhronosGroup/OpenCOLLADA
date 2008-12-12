/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBCIRCLE_H__
#define __MayaDM_MAKENURBCIRCLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute a circle given the center, radius, and normal. A partial
 circle or arc can be computed if the sweep angle (sweep) is specified.
 <br/>
 <br/>
 The location and orientation of the circle can be controlled by using
 the center, fixCenter, and first attributes. If fixCenter is false then
 the circle will start at first point. This may pull the circle off of
 the specified center. Otherwise if fixCenter is true, the circle will
 use the specified center and its start point will be determined by the
 the direction vector created between the center and the first point.
 <br/>
 <br/>
 The resolution of the circle can be controlled by specifying the
 useTolerance (useTolerance) attribute and the tolerance (tolerance).
 Otherwise the number of sections (sections) will control the circle's
 resolution.
 <br/>
 <br/>
 The resulting circle can have a degree of linear or cubic.
 <p/>
*/
class MakeNurbCircle : public AbstractBaseCreate
{
public:
public:
	MakeNurbCircle(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "makeNurbCircle"){}
	virtual ~MakeNurbCircle(){}
	/*
	The start point of the circle if fixCenter is false.
	Determines the orientation of the circle if fixCenter is true.
	*/
	void setFirst(const double3& fp){fprintf_s(mFile, "setAttr \".fp\" -type \"double3\" ");fp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The start point of the circle if fixCenter is false.
	Determines the orientation of the circle if fixCenter is true.
	*/
	void setFirst(const Double3ID& fp){fprintf_s(mFile,"connectAttr \"");fp.write(mFile);fprintf_s(mFile,"\" \"%s.fp\";\n",mName.c_str());}
	/*X of the first point.*/
	void setFirstPointX(double fpx){if(fpx == 1) return; fprintf_s(mFile, "setAttr \".fp.fpx\" %f;\n", fpx);}
	/*X of the first point.*/
	void setFirstPointX(const DoubleID& fpx){fprintf_s(mFile,"connectAttr \"");fpx.write(mFile);fprintf_s(mFile,"\" \"%s.fp.fpx\";\n",mName.c_str());}
	/*Y of the first point.*/
	void setFirstPointY(double fpy){if(fpy == 0) return; fprintf_s(mFile, "setAttr \".fp.fpy\" %f;\n", fpy);}
	/*Y of the first point.*/
	void setFirstPointY(const DoubleID& fpy){fprintf_s(mFile,"connectAttr \"");fpy.write(mFile);fprintf_s(mFile,"\" \"%s.fp.fpy\";\n",mName.c_str());}
	/*Z of the first point.*/
	void setFirstPointZ(double fpz){if(fpz == 0) return; fprintf_s(mFile, "setAttr \".fp.fpz\" %f;\n", fpz);}
	/*Z of the first point.*/
	void setFirstPointZ(const DoubleID& fpz){fprintf_s(mFile,"connectAttr \"");fpz.write(mFile);fprintf_s(mFile,"\" \"%s.fp.fpz\";\n",mName.c_str());}
	/*The normal of the plane in which the circle will lie.*/
	void setNormal(const double3& nr){fprintf_s(mFile, "setAttr \".nr\" -type \"double3\" ");nr.write(mFile);fprintf_s(mFile,";\n");}
	/*The normal of the plane in which the circle will lie.*/
	void setNormal(const Double3ID& nr){fprintf_s(mFile,"connectAttr \"");nr.write(mFile);fprintf_s(mFile,"\" \"%s.nr\";\n",mName.c_str());}
	/*X of the normal direction.*/
	void setNormalX(double nrx){if(nrx == 0) return; fprintf_s(mFile, "setAttr \".nr.nrx\" %f;\n", nrx);}
	/*X of the normal direction.*/
	void setNormalX(const DoubleID& nrx){fprintf_s(mFile,"connectAttr \"");nrx.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nrx\";\n",mName.c_str());}
	/*Y of the normal direction.*/
	void setNormalY(double nry){if(nry == 0) return; fprintf_s(mFile, "setAttr \".nr.nry\" %f;\n", nry);}
	/*Y of the normal direction.*/
	void setNormalY(const DoubleID& nry){fprintf_s(mFile,"connectAttr \"");nry.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nry\";\n",mName.c_str());}
	/*Z of the normal direction.*/
	void setNormalZ(double nrz){if(nrz == 1) return; fprintf_s(mFile, "setAttr \".nr.nrz\" %f;\n", nrz);}
	/*Z of the normal direction.*/
	void setNormalZ(const DoubleID& nrz){fprintf_s(mFile,"connectAttr \"");nrz.write(mFile);fprintf_s(mFile,"\" \"%s.nr.nrz\";\n",mName.c_str());}
	/*The center point of the circle.*/
	void setCenter(const double3& c){fprintf_s(mFile, "setAttr \".c\" -type \"double3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*The center point of the circle.*/
	void setCenter(const Double3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*X of the center point.*/
	void setCenterX(double cx){if(cx == 0) return; fprintf_s(mFile, "setAttr \".c.cx\" %f;\n", cx);}
	/*X of the center point.*/
	void setCenterX(const DoubleID& cx){fprintf_s(mFile,"connectAttr \"");cx.write(mFile);fprintf_s(mFile,"\" \"%s.c.cx\";\n",mName.c_str());}
	/*Y of the center point.*/
	void setCenterY(double cy){if(cy == 0) return; fprintf_s(mFile, "setAttr \".c.cy\" %f;\n", cy);}
	/*Y of the center point.*/
	void setCenterY(const DoubleID& cy){fprintf_s(mFile,"connectAttr \"");cy.write(mFile);fprintf_s(mFile,"\" \"%s.c.cy\";\n",mName.c_str());}
	/*Z of the center point.*/
	void setCenterZ(double cz){if(cz == 0) return; fprintf_s(mFile, "setAttr \".c.cz\" %f;\n", cz);}
	/*Z of the center point.*/
	void setCenterZ(const DoubleID& cz){fprintf_s(mFile,"connectAttr \"");cz.write(mFile);fprintf_s(mFile,"\" \"%s.c.cz\";\n",mName.c_str());}
	/*The radius of the circle.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*The radius of the circle.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*
	The sweep angle determines the completeness of the circle.
	A full circle is 2Pi radians, or 360 degrees.
	*/
	void setSweep(double sw){if(sw == 6.2831853) return; fprintf_s(mFile, "setAttr \".sw\" %f;\n", sw);}
	/*
	The sweep angle determines the completeness of the circle.
	A full circle is 2Pi radians, or 360 degrees.
	*/
	void setSweep(const DoubleID& sw){fprintf_s(mFile,"connectAttr \"");sw.write(mFile);fprintf_s(mFile,"\" \"%s.sw\";\n",mName.c_str());}
	/*
	Use the specified tolerance to determine resolution.
	Otherwise number of sections will be used.
	*/
	void setUseTolerance(bool ut){if(ut == false) return; fprintf_s(mFile, "setAttr \".ut\" %i;\n", ut);}
	/*
	Use the specified tolerance to determine resolution.
	Otherwise number of sections will be used.
	*/
	void setUseTolerance(const BoolID& ut){fprintf_s(mFile,"connectAttr \"");ut.write(mFile);fprintf_s(mFile,"\" \"%s.ut\";\n",mName.c_str());}
	/*
	The degree of the resulting circle:
	1 - linear,
	3 - cubic
	*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The degree of the resulting circle:
	1 - linear,
	3 - cubic
	*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	The number of sections determines the resolution of the circle.
	Used only if useTolerance is false.
	*/
	void setSections(int s){if(s == 8) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*
	The number of sections determines the resolution of the circle.
	Used only if useTolerance is false.
	*/
	void setSections(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	The tolerance with which to build a circle.
	Used only if useTolerance is true
	*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*
	The tolerance with which to build a circle.
	Used only if useTolerance is true
	*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*
	Fix the center of the circle to the specified center point.
	Otherwise the circle will start at the specified first point.
	*/
	void setFixCenter(bool fc){if(fc == true) return; fprintf_s(mFile, "setAttr \".fc\" %i;\n", fc);}
	/*
	Fix the center of the circle to the specified center point.
	Otherwise the circle will start at the specified first point.
	*/
	void setFixCenter(const BoolID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc\";\n",mName.c_str());}
	/*The created circle.*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*
	The start point of the circle if fixCenter is false.
	Determines the orientation of the circle if fixCenter is true.
	*/
	Double3ID getFirst(){char buffer[4096];sprintf_s (buffer, "%s.fp",mName.c_str());return (const char*)buffer;}
	/*X of the first point.*/
	DoubleID getFirstPointX(){char buffer[4096];sprintf_s (buffer, "%s.fp.fpx",mName.c_str());return (const char*)buffer;}
	/*Y of the first point.*/
	DoubleID getFirstPointY(){char buffer[4096];sprintf_s (buffer, "%s.fp.fpy",mName.c_str());return (const char*)buffer;}
	/*Z of the first point.*/
	DoubleID getFirstPointZ(){char buffer[4096];sprintf_s (buffer, "%s.fp.fpz",mName.c_str());return (const char*)buffer;}
	/*The normal of the plane in which the circle will lie.*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.nr",mName.c_str());return (const char*)buffer;}
	/*X of the normal direction.*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.nr.nrx",mName.c_str());return (const char*)buffer;}
	/*Y of the normal direction.*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.nr.nry",mName.c_str());return (const char*)buffer;}
	/*Z of the normal direction.*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.nr.nrz",mName.c_str());return (const char*)buffer;}
	/*The center point of the circle.*/
	Double3ID getCenter(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*X of the center point.*/
	DoubleID getCenterX(){char buffer[4096];sprintf_s (buffer, "%s.c.cx",mName.c_str());return (const char*)buffer;}
	/*Y of the center point.*/
	DoubleID getCenterY(){char buffer[4096];sprintf_s (buffer, "%s.c.cy",mName.c_str());return (const char*)buffer;}
	/*Z of the center point.*/
	DoubleID getCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.c.cz",mName.c_str());return (const char*)buffer;}
	/*The radius of the circle.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*
	The sweep angle determines the completeness of the circle.
	A full circle is 2Pi radians, or 360 degrees.
	*/
	DoubleID getSweep(){char buffer[4096];sprintf_s (buffer, "%s.sw",mName.c_str());return (const char*)buffer;}
	/*
	Use the specified tolerance to determine resolution.
	Otherwise number of sections will be used.
	*/
	BoolID getUseTolerance(){char buffer[4096];sprintf_s (buffer, "%s.ut",mName.c_str());return (const char*)buffer;}
	/*
	The degree of the resulting circle:
	1 - linear,
	3 - cubic
	*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	The number of sections determines the resolution of the circle.
	Used only if useTolerance is false.
	*/
	IntID getSections(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	The tolerance with which to build a circle.
	Used only if useTolerance is true
	*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*
	Fix the center of the circle to the specified center point.
	Otherwise the circle will start at the specified first point.
	*/
	BoolID getFixCenter(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*The created circle.*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	MakeNurbCircle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBCIRCLE_H__
