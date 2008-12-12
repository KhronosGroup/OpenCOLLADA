/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSPHPROJ_H__
#define __MayaDM_POLYSPHPROJ_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*Projects a spherical map onto an object.<p/>*/
class PolySphProj : public PolyModifierWorld
{
public:
public:
	PolySphProj(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySphProj"){}
	virtual ~PolySphProj(){}
	/*Specifies the origin point from which the map is projected.*/
	void setProjectionCenter(const double3& pc){if(pc == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".pc\" -type \"double3\" ");pc.write(mFile);fprintf_s(mFile,";\n");}
	/*Specifies the origin point from which the map is projected.*/
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
	void setImageCenter(const double2& ic){if(ic == double2(0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".ic\" -type \"double2\" ");ic.write(mFile);fprintf_s(mFile,";\n");}
	/*The center point of the 2D model layout.*/
	void setImageCenter(const Double2ID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Image center X coord.*/
	void setImageCenterX(double icx){if(icx == 0.0) return; fprintf_s(mFile, "setAttr \".ic.icx\" %f;\n", icx);}
	/*Image center X coord.*/
	void setImageCenterX(const DoubleID& icx){fprintf_s(mFile,"connectAttr \"");icx.write(mFile);fprintf_s(mFile,"\" \"%s.ic.icx\";\n",mName.c_str());}
	/*Image center Y coord.*/
	void setImageCenterY(double icy){if(icy == 0.0) return; fprintf_s(mFile, "setAttr \".ic.icy\" %f;\n", icy);}
	/*Image center Y coord.*/
	void setImageCenterY(const DoubleID& icy){fprintf_s(mFile,"connectAttr \"");icy.write(mFile);fprintf_s(mFile,"\" \"%s.ic.icy\";\n",mName.c_str());}
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
	void setProjectionScale(const double2& ps){if(ps == double2(180.0, 90.0)) return; fprintf_s(mFile, "setAttr \".ps\" -type \"double2\" ");ps.write(mFile);fprintf_s(mFile,";\n");}
	/*The width and the height of the map relative to the 3D projection axis.*/
	void setProjectionScale(const Double2ID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*
	The angle swept horizontally by the projection.
	The range is [0, 360].
	*/
	void setProjectionHorizontalSweep(double phs){if(phs == 0) return; fprintf_s(mFile, "setAttr \".ps.phs\" %f;\n", phs);}
	/*
	The angle swept horizontally by the projection.
	The range is [0, 360].
	*/
	void setProjectionHorizontalSweep(const DoubleID& phs){fprintf_s(mFile,"connectAttr \"");phs.write(mFile);fprintf_s(mFile,"\" \"%s.ps.phs\";\n",mName.c_str());}
	/*
	The angle swept vertically by the projection.
	The range is [0, 180].
	*/
	void setProjectionVerticalSweep(double pvs){if(pvs == 0) return; fprintf_s(mFile, "setAttr \".ps.pvs\" %f;\n", pvs);}
	/*
	The angle swept vertically by the projection.
	The range is [0, 180].
	*/
	void setProjectionVerticalSweep(const DoubleID& pvs){fprintf_s(mFile,"connectAttr \"");pvs.write(mFile);fprintf_s(mFile,"\" \"%s.ps.pvs\";\n",mName.c_str());}
	/*The name of the map set to work on*/
	void setUvSetName(const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs\" -type \"string\" ");uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the map set to work on*/
	void setUvSetName(const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*
	The UV scale : enlarges or reduces the 2D version of the model in U
	or V space relative to the 2D centerpoint.
	*/
	void setImageScale(const double2& is){if(is == double2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".is\" -type \"double2\" ");is.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The UV scale : enlarges or reduces the 2D version of the model in U
	or V space relative to the 2D centerpoint.
	*/
	void setImageScale(const Double2ID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*
	The U scale : enlarges or reduces the 2D version of the model in
	U space relative to the 2D centerpoint.
	*/
	void setImageScaleU(double isu){if(isu == 0.0) return; fprintf_s(mFile, "setAttr \".is.isu\" %f;\n", isu);}
	/*
	The U scale : enlarges or reduces the 2D version of the model in
	U space relative to the 2D centerpoint.
	*/
	void setImageScaleU(const DoubleID& isu){fprintf_s(mFile,"connectAttr \"");isu.write(mFile);fprintf_s(mFile,"\" \"%s.is.isu\";\n",mName.c_str());}
	/*
	The U scale : enlarges or reduces the 2D version of the model in
	V space relative to the 2D centerpoint.
	*/
	void setImageScaleV(double isv){if(isv == 0.0) return; fprintf_s(mFile, "setAttr \".is.isv\" %f;\n", isv);}
	/*
	The U scale : enlarges or reduces the 2D version of the model in
	V space relative to the 2D centerpoint.
	*/
	void setImageScaleV(const DoubleID& isv){fprintf_s(mFile,"connectAttr \"");isv.write(mFile);fprintf_s(mFile,"\" \"%s.is.isv\";\n",mName.c_str());}
	/*Used by the UI : Manipulator.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Used by the UI : Manipulator.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*
	The angle for the rotation.
	When the angle is positive, then the map rotates counterclockwise
	on the mapped model, whereas when it is negative then the map
	rotates lockwise on the mapped model.
	*/
	void setRotationAngle(double ra){if(ra == 0) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	The angle for the rotation.
	When the angle is positive, then the map rotates counterclockwise
	on the mapped model, whereas when it is negative then the map
	rotates lockwise on the mapped model.
	*/
	void setRotationAngle(const DoubleID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*Used to indicate fixing UV seams.*/
	void setSeamCorrect(bool sc){if(sc == false) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*Used to indicate fixing UV seams.*/
	void setSeamCorrect(const BoolID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*Which element to place the manip on (for UI purposes only).*/
	void setCompId(const IntID& cid){fprintf_s(mFile,"connectAttr \"");cid.write(mFile);fprintf_s(mFile,"\" \"%s.cid\";\n",mName.c_str());}
	/*
	Attribute to specify if the old poly projection needs to be used
	for the evaluation of this node. SHOULD NOT BE SET OR MODIFIED
	BY THE USER!!
	*/
	void setUseOldPolyProjection(bool uopp){if(uopp == false) return; fprintf_s(mFile, "setAttr \".uopp\" %i;\n", uopp);}
	/*Specifies the origin point from which the map is projected.*/
	Double3ID getProjectionCenter(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*Projection center X coord.*/
	DoubleID getProjectionCenterX(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcx",mName.c_str());return (const char*)buffer;}
	/*Projection center Y coord.*/
	DoubleID getProjectionCenterY(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcy",mName.c_str());return (const char*)buffer;}
	/*Projection center Z coord.*/
	DoubleID getProjectionCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcz",mName.c_str());return (const char*)buffer;}
	/*The center point of the 2D model layout.*/
	Double2ID getImageCenter(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*Image center X coord.*/
	DoubleID getImageCenterX(){char buffer[4096];sprintf_s (buffer, "%s.ic.icx",mName.c_str());return (const char*)buffer;}
	/*Image center Y coord.*/
	DoubleID getImageCenterY(){char buffer[4096];sprintf_s (buffer, "%s.ic.icy",mName.c_str());return (const char*)buffer;}
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
	/*
	The angle swept horizontally by the projection.
	The range is [0, 360].
	*/
	DoubleID getProjectionHorizontalSweep(){char buffer[4096];sprintf_s (buffer, "%s.ps.phs",mName.c_str());return (const char*)buffer;}
	/*
	The angle swept vertically by the projection.
	The range is [0, 180].
	*/
	DoubleID getProjectionVerticalSweep(){char buffer[4096];sprintf_s (buffer, "%s.ps.pvs",mName.c_str());return (const char*)buffer;}
	/*The name of the map set to work on*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
	/*
	The UV scale : enlarges or reduces the 2D version of the model in U
	or V space relative to the 2D centerpoint.
	*/
	Double2ID getImageScale(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*
	The U scale : enlarges or reduces the 2D version of the model in
	U space relative to the 2D centerpoint.
	*/
	DoubleID getImageScaleU(){char buffer[4096];sprintf_s (buffer, "%s.is.isu",mName.c_str());return (const char*)buffer;}
	/*
	The U scale : enlarges or reduces the 2D version of the model in
	V space relative to the 2D centerpoint.
	*/
	DoubleID getImageScaleV(){char buffer[4096];sprintf_s (buffer, "%s.is.isv",mName.c_str());return (const char*)buffer;}
	/*Used by the UI : Manipulator.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*
	The angle for the rotation.
	When the angle is positive, then the map rotates counterclockwise
	on the mapped model, whereas when it is negative then the map
	rotates lockwise on the mapped model.
	*/
	DoubleID getRotationAngle(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*Used to indicate fixing UV seams.*/
	BoolID getSeamCorrect(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*Which element to place the manip on (for UI purposes only).*/
	IntID getCompId(){char buffer[4096];sprintf_s (buffer, "%s.cid",mName.c_str());return (const char*)buffer;}
protected:
	PolySphProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSPHPROJ_H__
