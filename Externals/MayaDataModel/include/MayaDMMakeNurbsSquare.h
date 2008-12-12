/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBSSQUARE_H__
#define __MayaDM_MAKENURBSSQUARE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute a NURBS square given the length of two adjacent sides, number of spans,
 degree, center and normal of the plane. The square is created about the specified
 center to lie on the plane.
 <br/>
 <br/>
 The length of two adjacent sides on the square can be controlled using the
 attributes "sideLength1" and "sideLength2". The square could be created on the
 desired plane using the attributes "normal" and "center".
 <br/>
 By default, a unit square of degree 3 is created around the origin on the XY
 plane i.e. Z = 0.
 <br/>
 <br/>
 The resolution of the square can be controlled by specifying the
 number of "spansPerSide" on the square. The degree of the NURBS
 curves describing the square can be controlled using the attribute
 "degree".
 <br/>
 The four output NURBS curves corresponding to the edges of the square can be
 obtained at the output attributes "aOutCurve1", "aOutCurve2", "aOutCurve3"
 and "aOutCurve4" respectively.

 <br/>
 <br/>
 The degree of the square can be 1, 2, 3, 5 or 7.
 <p/>
*/
class MakeNurbsSquare : public AbstractBaseCreate
{
public:
public:
	MakeNurbsSquare(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "makeNurbsSquare"){}
	virtual ~MakeNurbsSquare(){}
	/*The normal of the plane in which the square will lie.*/
	void setNormal(const double3& nr){fprintf_s(mFile, "setAttr \".nr\" -type \"double3\" ");nr.write(mFile);fprintf_s(mFile,";\n");}
	/*The normal of the plane in which the square will lie.*/
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
	/*The center point of the square.*/
	void setCenter(const double3& c){fprintf_s(mFile, "setAttr \".c\" -type \"double3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*The center point of the square.*/
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
	/*The length of a side on the square.*/
	void setSideLength1(double sl1){if(sl1 == 1) return; fprintf_s(mFile, "setAttr \".sl1\" %f;\n", sl1);}
	/*The length of a side on the square.*/
	void setSideLength1(const DoubleID& sl1){fprintf_s(mFile,"connectAttr \"");sl1.write(mFile);fprintf_s(mFile,"\" \"%s.sl1\";\n",mName.c_str());}
	/*The length of an adjacent side on the square.*/
	void setSideLength2(double sl2){if(sl2 == 1) return; fprintf_s(mFile, "setAttr \".sl2\" %f;\n", sl2);}
	/*The length of an adjacent side on the square.*/
	void setSideLength2(const DoubleID& sl2){fprintf_s(mFile,"connectAttr \"");sl2.write(mFile);fprintf_s(mFile,"\" \"%s.sl2\";\n",mName.c_str());}
	/*
	The degree of the resulting circle:
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The degree of the resulting circle:
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The number of spans per side determines the resolution of the square.*/
	void setSpansPerSide(int sps){if(sps == 1) return; fprintf_s(mFile, "setAttr \".sps\" %i;\n", sps);}
	/*The number of spans per side determines the resolution of the square.*/
	void setSpansPerSide(const IntID& sps){fprintf_s(mFile,"connectAttr \"");sps.write(mFile);fprintf_s(mFile,"\" \"%s.sps\";\n",mName.c_str());}
	/*Output Curve 1 - left square segment.*/
	void setOutputCurve1(const NurbsCurveID& oc1){fprintf_s(mFile,"connectAttr \"");oc1.write(mFile);fprintf_s(mFile,"\" \"%s.oc1\";\n",mName.c_str());}
	/*Output Curve 2 - top square segment.*/
	void setOutputCurve2(const NurbsCurveID& oc2){fprintf_s(mFile,"connectAttr \"");oc2.write(mFile);fprintf_s(mFile,"\" \"%s.oc2\";\n",mName.c_str());}
	/*Output Curve 3 - right square segment.*/
	void setOutputCurve3(const NurbsCurveID& oc3){fprintf_s(mFile,"connectAttr \"");oc3.write(mFile);fprintf_s(mFile,"\" \"%s.oc3\";\n",mName.c_str());}
	/*Output Curve 4 - bottom square segment.*/
	void setOutputCurve4(const NurbsCurveID& oc4){fprintf_s(mFile,"connectAttr \"");oc4.write(mFile);fprintf_s(mFile,"\" \"%s.oc4\";\n",mName.c_str());}
	/*The normal of the plane in which the square will lie.*/
	Double3ID getNormal(){char buffer[4096];sprintf_s (buffer, "%s.nr",mName.c_str());return (const char*)buffer;}
	/*X of the normal direction.*/
	DoubleID getNormalX(){char buffer[4096];sprintf_s (buffer, "%s.nr.nrx",mName.c_str());return (const char*)buffer;}
	/*Y of the normal direction.*/
	DoubleID getNormalY(){char buffer[4096];sprintf_s (buffer, "%s.nr.nry",mName.c_str());return (const char*)buffer;}
	/*Z of the normal direction.*/
	DoubleID getNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.nr.nrz",mName.c_str());return (const char*)buffer;}
	/*The center point of the square.*/
	Double3ID getCenter(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*X of the center point.*/
	DoubleID getCenterX(){char buffer[4096];sprintf_s (buffer, "%s.c.cx",mName.c_str());return (const char*)buffer;}
	/*Y of the center point.*/
	DoubleID getCenterY(){char buffer[4096];sprintf_s (buffer, "%s.c.cy",mName.c_str());return (const char*)buffer;}
	/*Z of the center point.*/
	DoubleID getCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.c.cz",mName.c_str());return (const char*)buffer;}
	/*The length of a side on the square.*/
	DoubleID getSideLength1(){char buffer[4096];sprintf_s (buffer, "%s.sl1",mName.c_str());return (const char*)buffer;}
	/*The length of an adjacent side on the square.*/
	DoubleID getSideLength2(){char buffer[4096];sprintf_s (buffer, "%s.sl2",mName.c_str());return (const char*)buffer;}
	/*
	The degree of the resulting circle:
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The number of spans per side determines the resolution of the square.*/
	IntID getSpansPerSide(){char buffer[4096];sprintf_s (buffer, "%s.sps",mName.c_str());return (const char*)buffer;}
	/*Output Curve 1 - left square segment.*/
	NurbsCurveID getOutputCurve1(){char buffer[4096];sprintf_s (buffer, "%s.oc1",mName.c_str());return (const char*)buffer;}
	/*Output Curve 2 - top square segment.*/
	NurbsCurveID getOutputCurve2(){char buffer[4096];sprintf_s (buffer, "%s.oc2",mName.c_str());return (const char*)buffer;}
	/*Output Curve 3 - right square segment.*/
	NurbsCurveID getOutputCurve3(){char buffer[4096];sprintf_s (buffer, "%s.oc3",mName.c_str());return (const char*)buffer;}
	/*Output Curve 4 - bottom square segment.*/
	NurbsCurveID getOutputCurve4(){char buffer[4096];sprintf_s (buffer, "%s.oc4",mName.c_str());return (const char*)buffer;}
protected:
	MakeNurbsSquare(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBSSQUARE_H__
