/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDPLANARPROJ_H__
#define __MayaDM_SUBDPLANARPROJ_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifierWorld.h"
namespace MayaDM
{
/*
Projects a map onto an object, using an orthogonal projection.
 The piece of the map defined by the imageScale and imageCenter attributes
 is placed at projectionCenter on the object.<p/>
*/
class SubdPlanarProj : public SubdModifierWorld
{
public:
public:
	SubdPlanarProj(FILE* file,const std::string& name,const std::string& parent=""):SubdModifierWorld(file, name, parent, "subdPlanarProj"){}
	virtual ~SubdPlanarProj(){}
	/*The point on the object that will be the center of the projection.*/
	void setProjectionCenter(const double3& pc){if(pc == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".pc\" -type \"double3\" ");pc.write(mFile);fprintf_s(mFile,";\n");}
	/*The point on the object that will be the center of the projection.*/
	void setProjectionCenter(const Double3ID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*Projection center X coord.*/
	void setProjectionCenterX(double pcx){if(pcx == 0) return; fprintf_s(mFile, "setAttr \".pc.pcx\" %f;\n", pcx);}
	/*Projection center X coord.*/
	void setProjectionCenterX(const DoubleID& pcx){fprintf_s(mFile,"connectAttr \"");pcx.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcx\";\n",mName.c_str());}
	/*Projection center Y coord.*/
	void setProjectionCenterY(double pcy){if(pcy == 0) return; fprintf_s(mFile, "setAttr \".pc.pcy\" %f;\n", pcy);}
	/*Projection center Y coord.*/
	void setProjectionCenterY(const DoubleID& pcy){fprintf_s(mFile,"connectAttr \"");pcy.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcy\";\n",mName.c_str());}
	/*Projection center Z coord.*/
	void setProjectionCenterZ(double pcz){if(pcz == 0) return; fprintf_s(mFile, "setAttr \".pc.pcz\" %f;\n", pcz);}
	/*Projection center Z coord.*/
	void setProjectionCenterZ(const DoubleID& pcz){fprintf_s(mFile,"connectAttr \"");pcz.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcz\";\n",mName.c_str());}
	/*The center point of the 2D model layout.*/
	void setImageCenter(const double2& ic2){if(ic2 == double2(0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".ic2\" -type \"double2\" ");ic2.write(mFile);fprintf_s(mFile,";\n");}
	/*The center point of the 2D model layout.*/
	void setImageCenter(const Double2ID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.ic2\";\n",mName.c_str());}
	/*Image center X coord.*/
	void setImageCenterX(double icx){if(icx == 0.0) return; fprintf_s(mFile, "setAttr \".ic2.icx\" %f;\n", icx);}
	/*Image center X coord.*/
	void setImageCenterX(const DoubleID& icx){fprintf_s(mFile,"connectAttr \"");icx.write(mFile);fprintf_s(mFile,"\" \"%s.ic2.icx\";\n",mName.c_str());}
	/*Image center Y coord.*/
	void setImageCenterY(double icy){if(icy == 0.0) return; fprintf_s(mFile, "setAttr \".ic2.icy\" %f;\n", icy);}
	/*Image center Y coord.*/
	void setImageCenterY(const DoubleID& icy){fprintf_s(mFile,"connectAttr \"");icy.write(mFile);fprintf_s(mFile,"\" \"%s.ic2.icy\";\n",mName.c_str());}
	/*The mapping rotate angles.*/
	void setRotate(const double3& ro){if(ro == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ro\" -type \"double3\" ");ro.write(mFile);fprintf_s(mFile,";\n");}
	/*The mapping rotate angles.*/
	void setRotate(const Double3ID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*X mapping rotate angle.*/
	void setRotateX(double rx){if(rx == 0) return; fprintf_s(mFile, "setAttr \".ro.rx\" %f;\n", rx);}
	/*X mapping rotate angle.*/
	void setRotateX(const DoubleID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.ro.rx\";\n",mName.c_str());}
	/*Y mapping rotate angle.*/
	void setRotateY(double ry){if(ry == 0) return; fprintf_s(mFile, "setAttr \".ro.ry\" %f;\n", ry);}
	/*Y mapping rotate angle.*/
	void setRotateY(const DoubleID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.ro.ry\";\n",mName.c_str());}
	/*Z mapping rotate angle.*/
	void setRotateZ(double rz){if(rz == 0) return; fprintf_s(mFile, "setAttr \".ro.rz\" %f;\n", rz);}
	/*Z mapping rotate angle.*/
	void setRotateZ(const DoubleID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.ro.rz\";\n",mName.c_str());}
	/*The width and the height of the map relative to the 3D projection axis.*/
	void setProjectionScale(const double2& ps){if(ps == double2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".ps\" -type \"double2\" ");ps.write(mFile);fprintf_s(mFile,";\n");}
	/*The width and the height of the map relative to the 3D projection axis.*/
	void setProjectionScale(const Double2ID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*The width of the map relative to the 3D projection axis.*/
	void setProjectionWidth(double pw){if(pw == 0) return; fprintf_s(mFile, "setAttr \".ps.pw\" %f;\n", pw);}
	/*The width of the map relative to the 3D projection axis.*/
	void setProjectionWidth(const DoubleID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.ps.pw\";\n",mName.c_str());}
	/*The height of the map relative to the 3D projection axis.*/
	void setProjectionHeight(double ph){if(ph == 0) return; fprintf_s(mFile, "setAttr \".ps.ph\" %f;\n", ph);}
	/*The height of the map relative to the 3D projection axis.*/
	void setProjectionHeight(const DoubleID& ph){fprintf_s(mFile,"connectAttr \"");ph.write(mFile);fprintf_s(mFile,"\" \"%s.ps.ph\";\n",mName.c_str());}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	void setImageScale(const double2& is2){if(is2 == double2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".is2\" -type \"double2\" ");is2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	void setImageScale(const Double2ID& is2){fprintf_s(mFile,"connectAttr \"");is2.write(mFile);fprintf_s(mFile,"\" \"%s.is2\";\n",mName.c_str());}
	/*
	The the U scale : Enlarges or reduces the 2D version of the model
	in U space relative to the 2D centerpoint.
	*/
	void setImageScaleU(double isu){if(isu == 0.0) return; fprintf_s(mFile, "setAttr \".is2.isu\" %f;\n", isu);}
	/*
	The the U scale : Enlarges or reduces the 2D version of the model
	in U space relative to the 2D centerpoint.
	*/
	void setImageScaleU(const DoubleID& isu){fprintf_s(mFile,"connectAttr \"");isu.write(mFile);fprintf_s(mFile,"\" \"%s.is2.isu\";\n",mName.c_str());}
	/*
	The V scale : Enlarges or reduces the 2D version of the model
	in V space relative to the 2D centerpoint.
	*/
	void setImageScaleV(double isv){if(isv == 0.0) return; fprintf_s(mFile, "setAttr \".is2.isv\" %f;\n", isv);}
	/*
	The V scale : Enlarges or reduces the 2D version of the model
	in V space relative to the 2D centerpoint.
	*/
	void setImageScaleV(const DoubleID& isv){fprintf_s(mFile,"connectAttr \"");isv.write(mFile);fprintf_s(mFile,"\" \"%s.is2.isv\";\n",mName.c_str());}
	/*
	The angle for the rotation.
	When the angle is positive, then the map rotates counterclockwise on
	the mapped model; if negative, the map rotates clockwise.
	*/
	void setRotationAngle(double ra){if(ra == 0) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	The angle for the rotation.
	When the angle is positive, then the map rotates counterclockwise on
	the mapped model; if negative, the map rotates clockwise.
	*/
	void setRotationAngle(const DoubleID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*Used by the UI : Manipulator.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Used by the UI : Manipulator.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Which element to place the manip on (for interaction purposes only).*/
	void setCompId(const IntID& cid){fprintf_s(mFile,"connectAttr \"");cid.write(mFile);fprintf_s(mFile,"\" \"%s.cid\";\n",mName.c_str());}
	/*The point on the object that will be the center of the projection.*/
	Double3ID getProjectionCenter(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*Projection center X coord.*/
	DoubleID getProjectionCenterX(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcx",mName.c_str());return (const char*)buffer;}
	/*Projection center Y coord.*/
	DoubleID getProjectionCenterY(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcy",mName.c_str());return (const char*)buffer;}
	/*Projection center Z coord.*/
	DoubleID getProjectionCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcz",mName.c_str());return (const char*)buffer;}
	/*The center point of the 2D model layout.*/
	Double2ID getImageCenter(){char buffer[4096];sprintf_s (buffer, "%s.ic2",mName.c_str());return (const char*)buffer;}
	/*Image center X coord.*/
	DoubleID getImageCenterX(){char buffer[4096];sprintf_s (buffer, "%s.ic2.icx",mName.c_str());return (const char*)buffer;}
	/*Image center Y coord.*/
	DoubleID getImageCenterY(){char buffer[4096];sprintf_s (buffer, "%s.ic2.icy",mName.c_str());return (const char*)buffer;}
	/*The mapping rotate angles.*/
	Double3ID getRotate(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*X mapping rotate angle.*/
	DoubleID getRotateX(){char buffer[4096];sprintf_s (buffer, "%s.ro.rx",mName.c_str());return (const char*)buffer;}
	/*Y mapping rotate angle.*/
	DoubleID getRotateY(){char buffer[4096];sprintf_s (buffer, "%s.ro.ry",mName.c_str());return (const char*)buffer;}
	/*Z mapping rotate angle.*/
	DoubleID getRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.ro.rz",mName.c_str());return (const char*)buffer;}
	/*The width and the height of the map relative to the 3D projection axis.*/
	Double2ID getProjectionScale(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*The width of the map relative to the 3D projection axis.*/
	DoubleID getProjectionWidth(){char buffer[4096];sprintf_s (buffer, "%s.ps.pw",mName.c_str());return (const char*)buffer;}
	/*The height of the map relative to the 3D projection axis.*/
	DoubleID getProjectionHeight(){char buffer[4096];sprintf_s (buffer, "%s.ps.ph",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	Double2ID getImageScale(){char buffer[4096];sprintf_s (buffer, "%s.is2",mName.c_str());return (const char*)buffer;}
	/*
	The the U scale : Enlarges or reduces the 2D version of the model
	in U space relative to the 2D centerpoint.
	*/
	DoubleID getImageScaleU(){char buffer[4096];sprintf_s (buffer, "%s.is2.isu",mName.c_str());return (const char*)buffer;}
	/*
	The V scale : Enlarges or reduces the 2D version of the model
	in V space relative to the 2D centerpoint.
	*/
	DoubleID getImageScaleV(){char buffer[4096];sprintf_s (buffer, "%s.is2.isv",mName.c_str());return (const char*)buffer;}
	/*
	The angle for the rotation.
	When the angle is positive, then the map rotates counterclockwise on
	the mapped model; if negative, the map rotates clockwise.
	*/
	DoubleID getRotationAngle(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*Used by the UI : Manipulator.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Which element to place the manip on (for interaction purposes only).*/
	IntID getCompId(){char buffer[4096];sprintf_s (buffer, "%s.cid",mName.c_str());return (const char*)buffer;}
protected:
	SubdPlanarProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDPLANARPROJ_H__
