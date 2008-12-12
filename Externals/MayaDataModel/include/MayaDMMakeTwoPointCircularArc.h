/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKETWOPOINTCIRCULARARC_H__
#define __MayaDM_MAKETWOPOINTCIRCULARARC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMMakeCircularArc.h"
namespace MayaDM
{
/*
Compute a non rational circular arc (bspline form) passing
  through two given points.
 <br/>
  The degree of the created arc can be linear or cubic and is controlled
  using the attribute "degree". The number of spans of the curve can be
        controlled using the attribute "sections".
 <br/>
        The radius of the arc can be specified using the attribute "radius".
        The radius must be atleast half the distance between the two points.
 <br/>
  The created arc available at "outputCurve" is non-rational.
 <p/>
*/
class MakeTwoPointCircularArc : public MakeCircularArc
{
public:
public:
	MakeTwoPointCircularArc(FILE* file,const std::string& name,const std::string& parent=""):MakeCircularArc(file, name, parent, "makeTwoPointCircularArc"){}
	virtual ~MakeTwoPointCircularArc(){}
	/*The point1 through which the circular arc must pass.*/
	void setPoint1(const double3& pt1){fprintf_s(mFile, "setAttr \".pt1\" -type \"double3\" ");pt1.write(mFile);fprintf_s(mFile,";\n");}
	/*The point1 through which the circular arc must pass.*/
	void setPoint1(const Double3ID& pt1){fprintf_s(mFile,"connectAttr \"");pt1.write(mFile);fprintf_s(mFile,"\" \"%s.pt1\";\n",mName.c_str());}
	/*X of the point1.*/
	void setPoint1X(double p1x){if(p1x == 1) return; fprintf_s(mFile, "setAttr \".pt1.p1x\" %f;\n", p1x);}
	/*X of the point1.*/
	void setPoint1X(const DoubleID& p1x){fprintf_s(mFile,"connectAttr \"");p1x.write(mFile);fprintf_s(mFile,"\" \"%s.pt1.p1x\";\n",mName.c_str());}
	/*Y of the point1.*/
	void setPoint1Y(double p1y){if(p1y == 0) return; fprintf_s(mFile, "setAttr \".pt1.p1y\" %f;\n", p1y);}
	/*Y of the point1.*/
	void setPoint1Y(const DoubleID& p1y){fprintf_s(mFile,"connectAttr \"");p1y.write(mFile);fprintf_s(mFile,"\" \"%s.pt1.p1y\";\n",mName.c_str());}
	/*Z of the point1.*/
	void setPoint1Z(double p1z){if(p1z == 0) return; fprintf_s(mFile, "setAttr \".pt1.p1z\" %f;\n", p1z);}
	/*Z of the point1.*/
	void setPoint1Z(const DoubleID& p1z){fprintf_s(mFile,"connectAttr \"");p1z.write(mFile);fprintf_s(mFile,"\" \"%s.pt1.p1z\";\n",mName.c_str());}
	/*The point2 through which the circular arc must pass.*/
	void setPoint2(const double3& pt2){fprintf_s(mFile, "setAttr \".pt2\" -type \"double3\" ");pt2.write(mFile);fprintf_s(mFile,";\n");}
	/*The point2 through which the circular arc must pass.*/
	void setPoint2(const Double3ID& pt2){fprintf_s(mFile,"connectAttr \"");pt2.write(mFile);fprintf_s(mFile,"\" \"%s.pt2\";\n",mName.c_str());}
	/*X of the point2.*/
	void setPoint2X(double p2x){if(p2x == 1) return; fprintf_s(mFile, "setAttr \".pt2.p2x\" %f;\n", p2x);}
	/*X of the point2.*/
	void setPoint2X(const DoubleID& p2x){fprintf_s(mFile,"connectAttr \"");p2x.write(mFile);fprintf_s(mFile,"\" \"%s.pt2.p2x\";\n",mName.c_str());}
	/*Y of the point2.*/
	void setPoint2Y(double p2y){if(p2y == 0) return; fprintf_s(mFile, "setAttr \".pt2.p2y\" %f;\n", p2y);}
	/*Y of the point2.*/
	void setPoint2Y(const DoubleID& p2y){fprintf_s(mFile,"connectAttr \"");p2y.write(mFile);fprintf_s(mFile,"\" \"%s.pt2.p2y\";\n",mName.c_str());}
	/*Z of the point2.*/
	void setPoint2Z(double p2z){if(p2z == 0) return; fprintf_s(mFile, "setAttr \".pt2.p2z\" %f;\n", p2z);}
	/*Z of the point2.*/
	void setPoint2Z(const DoubleID& p2z){fprintf_s(mFile,"connectAttr \"");p2z.write(mFile);fprintf_s(mFile,"\" \"%s.pt2.p2z\";\n",mName.c_str());}
	/*A direction vector not parallel to line segment joining the two given P1, P2*/
	void setDirectionVector(const double3& dv){fprintf_s(mFile, "setAttr \".dv\" -type \"double3\" ");dv.write(mFile);fprintf_s(mFile,";\n");}
	/*A direction vector not parallel to line segment joining the two given P1, P2*/
	void setDirectionVector(const Double3ID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*X component of the direction vector.*/
	void setDirectionVectorX(double dvx){if(dvx == 0) return; fprintf_s(mFile, "setAttr \".dv.dvx\" %f;\n", dvx);}
	/*X component of the direction vector.*/
	void setDirectionVectorX(const DoubleID& dvx){fprintf_s(mFile,"connectAttr \"");dvx.write(mFile);fprintf_s(mFile,"\" \"%s.dv.dvx\";\n",mName.c_str());}
	/*Y component of the direction vector.*/
	void setDirectionVectorY(double dvy){if(dvy == 0) return; fprintf_s(mFile, "setAttr \".dv.dvy\" %f;\n", dvy);}
	/*Y component of the direction vector.*/
	void setDirectionVectorY(const DoubleID& dvy){fprintf_s(mFile,"connectAttr \"");dvy.write(mFile);fprintf_s(mFile,"\" \"%s.dv.dvy\";\n",mName.c_str());}
	/*Z component of the direction vector*/
	void setDirectionVectorZ(double dvz){if(dvz == 1) return; fprintf_s(mFile, "setAttr \".dv.dvz\" %f;\n", dvz);}
	/*Z component of the direction vector*/
	void setDirectionVectorZ(const DoubleID& dvz){fprintf_s(mFile,"connectAttr \"");dvz.write(mFile);fprintf_s(mFile,"\" \"%s.dv.dvz\";\n",mName.c_str());}
	/*The required radius for the generated circular arc*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*The required radius for the generated circular arc*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*major or minor arc. Enables one to choose one of the two arcs possible.*/
	void setToggleArc(bool tac){if(tac == false) return; fprintf_s(mFile, "setAttr \".tac\" %i;\n", tac);}
	/*major or minor arc. Enables one to choose one of the two arcs possible.*/
	void setToggleArc(const BoolID& tac){fprintf_s(mFile,"connectAttr \"");tac.write(mFile);fprintf_s(mFile,"\" \"%s.tac\";\n",mName.c_str());}
	/*The point1 through which the circular arc must pass.*/
	Double3ID getPoint1(){char buffer[4096];sprintf_s (buffer, "%s.pt1",mName.c_str());return (const char*)buffer;}
	/*X of the point1.*/
	DoubleID getPoint1X(){char buffer[4096];sprintf_s (buffer, "%s.pt1.p1x",mName.c_str());return (const char*)buffer;}
	/*Y of the point1.*/
	DoubleID getPoint1Y(){char buffer[4096];sprintf_s (buffer, "%s.pt1.p1y",mName.c_str());return (const char*)buffer;}
	/*Z of the point1.*/
	DoubleID getPoint1Z(){char buffer[4096];sprintf_s (buffer, "%s.pt1.p1z",mName.c_str());return (const char*)buffer;}
	/*The point2 through which the circular arc must pass.*/
	Double3ID getPoint2(){char buffer[4096];sprintf_s (buffer, "%s.pt2",mName.c_str());return (const char*)buffer;}
	/*X of the point2.*/
	DoubleID getPoint2X(){char buffer[4096];sprintf_s (buffer, "%s.pt2.p2x",mName.c_str());return (const char*)buffer;}
	/*Y of the point2.*/
	DoubleID getPoint2Y(){char buffer[4096];sprintf_s (buffer, "%s.pt2.p2y",mName.c_str());return (const char*)buffer;}
	/*Z of the point2.*/
	DoubleID getPoint2Z(){char buffer[4096];sprintf_s (buffer, "%s.pt2.p2z",mName.c_str());return (const char*)buffer;}
	/*A direction vector not parallel to line segment joining the two given P1, P2*/
	Double3ID getDirectionVector(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*X component of the direction vector.*/
	DoubleID getDirectionVectorX(){char buffer[4096];sprintf_s (buffer, "%s.dv.dvx",mName.c_str());return (const char*)buffer;}
	/*Y component of the direction vector.*/
	DoubleID getDirectionVectorY(){char buffer[4096];sprintf_s (buffer, "%s.dv.dvy",mName.c_str());return (const char*)buffer;}
	/*Z component of the direction vector*/
	DoubleID getDirectionVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.dv.dvz",mName.c_str());return (const char*)buffer;}
	/*The required radius for the generated circular arc*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*major or minor arc. Enables one to choose one of the two arcs possible.*/
	BoolID getToggleArc(){char buffer[4096];sprintf_s (buffer, "%s.tac",mName.c_str());return (const char*)buffer;}
protected:
	MakeTwoPointCircularArc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):MakeCircularArc(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKETWOPOINTCIRCULARARC_H__
