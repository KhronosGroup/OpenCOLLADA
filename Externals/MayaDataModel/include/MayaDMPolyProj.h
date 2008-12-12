/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPROJ_H__
#define __MayaDM_POLYPROJ_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
<p><pre> This node is grouping all the polygonal projection nodes in a single one.
 It is used only for UI interaction, by the projection manipulator, that
 connects to this node for all the projection types (instead of connecting
 to different nodes for the differnt projections).
</pre></p>
*/
class PolyProj : public PolyModifierWorld
{
public:
public:
	PolyProj(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyProj"){}
	virtual ~PolyProj(){}
	/*
	The switch to select the projection type (geometry).
	1=planar, 2=spherical, 3=cylindrical.
	*/
	void setProjType(short t){if(t == 1) return; fprintf_s(mFile, "setAttr \".t\" %i;\n", t);}
	/*
	The switch to select the projection type (geometry).
	1=planar, 2=spherical, 3=cylindrical.
	*/
	void setProjType(const ShortID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*The inverse world matrix, to transform from world to the given DAG object space.*/
	void setWorldInverseMatrix(const matrix& wim){if(wim == identity) return; fprintf_s(mFile, "setAttr \".wim\" -type \"matrix\" ");wim.write(mFile);fprintf_s(mFile,";\n");}
	/*The inverse world matrix, to transform from world to the given DAG object space.*/
	void setWorldInverseMatrix(const MatrixID& wim){fprintf_s(mFile,"connectAttr \"");wim.write(mFile);fprintf_s(mFile,"\" \"%s.wim\";\n",mName.c_str());}
	/*The origin point from which the map is projected.*/
	void setProjectionCenter(const double3& pc){if(pc == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".pc\" -type \"double3\" ");pc.write(mFile);fprintf_s(mFile,";\n");}
	/*The origin point from which the map is projected.*/
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
	void setImageCenterX(double icx){if(icx == 0) return; fprintf_s(mFile, "setAttr \".ic.icx\" %f;\n", icx);}
	/*Image center X coord.*/
	void setImageCenterX(const DoubleID& icx){fprintf_s(mFile,"connectAttr \"");icx.write(mFile);fprintf_s(mFile,"\" \"%s.ic.icx\";\n",mName.c_str());}
	/*Image center Y coord.*/
	void setImageCenterY(double icy){if(icy == 0) return; fprintf_s(mFile, "setAttr \".ic.icy\" %f;\n", icy);}
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
	void setProjectionScale(const double2& ps){if(ps == double2(180.0, 1.0)) return; fprintf_s(mFile, "setAttr \".ps\" -type \"double2\" ");ps.write(mFile);fprintf_s(mFile,";\n");}
	/*The width and the height of the map relative to the 3D projection axis.*/
	void setProjectionScale(const Double2ID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*The width of the map relative to the 3D projection axis.*/
	void setProjectionScaleU(double psu){if(psu == 0) return; fprintf_s(mFile, "setAttr \".ps.psu\" %f;\n", psu);}
	/*The width of the map relative to the 3D projection axis.*/
	void setProjectionScaleU(const DoubleID& psu){fprintf_s(mFile,"connectAttr \"");psu.write(mFile);fprintf_s(mFile,"\" \"%s.ps.psu\";\n",mName.c_str());}
	/*The height of the map relative to the 3D projection axis.*/
	void setProjectionScaleV(double psv){if(psv == 0) return; fprintf_s(mFile, "setAttr \".ps.psv\" %f;\n", psv);}
	/*The height of the map relative to the 3D projection axis.*/
	void setProjectionScaleV(const DoubleID& psv){fprintf_s(mFile,"connectAttr \"");psv.write(mFile);fprintf_s(mFile,"\" \"%s.ps.psv\";\n",mName.c_str());}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	void setImageScale(const double2& is){if(is == double2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".is\" -type \"double2\" ");is.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	void setImageScale(const Double2ID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	void setImageScaleU(double isu){if(isu == 0) return; fprintf_s(mFile, "setAttr \".is.isu\" %f;\n", isu);}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	void setImageScaleU(const DoubleID& isu){fprintf_s(mFile,"connectAttr \"");isu.write(mFile);fprintf_s(mFile,"\" \"%s.is.isu\";\n",mName.c_str());}
	/*
	The V scale : Enlarges or reduces the 2D version of the model
	in V space relative to the 2D centerpoint.
	*/
	void setImageScaleV(double isv){if(isv == 0) return; fprintf_s(mFile, "setAttr \".is.isv\" %f;\n", isv);}
	/*
	The V scale : Enlarges or reduces the 2D version of the model
	in V space relative to the 2D centerpoint.
	*/
	void setImageScaleV(const DoubleID& isv){fprintf_s(mFile,"connectAttr \"");isv.write(mFile);fprintf_s(mFile,"\" \"%s.is.isv\";\n",mName.c_str());}
	/*Used by the UI : Manipulator.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Used by the UI : Manipulator.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*
	The for the rotation.
	When the angle is positive, then the map rotates counterclockwise on
	the mapped model, whereas when it is negative then the map rotates
	lockwise on the mapped model.
	*/
	void setRotationAngle(double ra){if(ra == 0) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	The for the rotation.
	When the angle is positive, then the map rotates counterclockwise on
	the mapped model, whereas when it is negative then the map rotates
	lockwise on the mapped model.
	*/
	void setRotationAngle(const DoubleID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*
	The switch to select the projection type (geometry).
	1=planar, 2=spherical, 3=cylindrical.
	*/
	ShortID getProjType(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*The inverse world matrix, to transform from world to the given DAG object space.*/
	MatrixID getWorldInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.wim",mName.c_str());return (const char*)buffer;}
	/*The origin point from which the map is projected.*/
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
	/*The width of the map relative to the 3D projection axis.*/
	DoubleID getProjectionScaleU(){char buffer[4096];sprintf_s (buffer, "%s.ps.psu",mName.c_str());return (const char*)buffer;}
	/*The height of the map relative to the 3D projection axis.*/
	DoubleID getProjectionScaleV(){char buffer[4096];sprintf_s (buffer, "%s.ps.psv",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	Double2ID getImageScale(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the UV scale : Enlarges or reduces the 2D version of the
	model in U or V space relative to the 2D centerpoint.
	*/
	DoubleID getImageScaleU(){char buffer[4096];sprintf_s (buffer, "%s.is.isu",mName.c_str());return (const char*)buffer;}
	/*
	The V scale : Enlarges or reduces the 2D version of the model
	in V space relative to the 2D centerpoint.
	*/
	DoubleID getImageScaleV(){char buffer[4096];sprintf_s (buffer, "%s.is.isv",mName.c_str());return (const char*)buffer;}
	/*Used by the UI : Manipulator.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*
	The for the rotation.
	When the angle is positive, then the map rotates counterclockwise on
	the mapped model, whereas when it is negative then the map rotates
	lockwise on the mapped model.
	*/
	DoubleID getRotationAngle(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
protected:
	PolyProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYPROJ_H__
