/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXTRUDE_H__
#define __MayaDM_EXTRUDE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Create a surface by extruding a profile curve. There are three ways
 to perform the extrusion (extrueType):
 <br/>
 <br/>
 distance - The profile is extruded along a vector (direction) by a
 given distance (length).
 <br/>
 <br/>
 flat - The profile is extruded along a path curve. The relationship
 between the profile and path remains the same as the profile travels
 along the path.
 <br/>
 <br/>
 tube - The profile is extruded along a path curve. The profile is rotated
 as it travels along a path.
 <br/>
 <br/>
 The location of the resulting surface can be controlled by fixedPath.
 The shape of the resulting surface can be controlled by useProfileNormal,
 useComponentPivot and the placement of each object's pivot point.
 <br/>
 The resulting surface can be scaled and rotated (for each extrude type)
 to produce spirals and twists in the surface. The pivot point is only
 used for flat and distance extrude type if there is a rotation/scale.
 <p/>
*/
class Extrude : public AbstractBaseCreate
{
public:
public:
	Extrude(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "extrude"){}
	virtual ~Extrude(){}
	/*The curve to extrude (profile).*/
	void setProfile(const NurbsCurveID& pr){fprintf_s(mFile,"connectAttr \"");pr.write(mFile);fprintf_s(mFile,"\" \"%s.pr\";\n",mName.c_str());}
	/*
	The path curve.
	Used only if extrudeType is flat or tube
	*/
	void setPath(const NurbsCurveID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*The extrude type (distance-0, flat-1, or tube-2)*/
	void setExtrudeType(unsigned int et){if(et == 2) return; fprintf_s(mFile, "setAttr \".et\" %i;\n", et);}
	/*The extrude type (distance-0, flat-1, or tube-2)*/
	void setExtrudeType(const UnsignedintID& et){fprintf_s(mFile,"connectAttr \"");et.write(mFile);fprintf_s(mFile,"\" \"%s.et\";\n",mName.c_str());}
	/*
	If true, the resulting surface will be placed at the path curve.
	Otherwise, the resulting surface will be placed at the profile curve.
	*/
	void setFixedPath(bool fpt){if(fpt == false) return; fprintf_s(mFile, "setAttr \".fpt\" %i;\n", fpt);}
	/*
	If true, the resulting surface will be placed at the path curve.
	Otherwise, the resulting surface will be placed at the profile curve.
	*/
	void setFixedPath(const BoolID& fpt){fprintf_s(mFile,"connectAttr \"");fpt.write(mFile);fprintf_s(mFile,"\" \"%s.fpt\";\n",mName.c_str());}
	/*Use closest endpoint of the path - 0, component pivot - 1 or the center of the bounding box of the profile - 2*/
	void setUseComponentPivot(unsigned int ucp){if(ucp == 0) return; fprintf_s(mFile, "setAttr \".ucp\" %i;\n", ucp);}
	/*Use closest endpoint of the path - 0, component pivot - 1 or the center of the bounding box of the profile - 2*/
	void setUseComponentPivot(const UnsignedintID& ucp){fprintf_s(mFile,"connectAttr \"");ucp.write(mFile);fprintf_s(mFile,"\" \"%s.ucp\";\n",mName.c_str());}
	/*
	If true, use the profile curve normal for the direction in which to extrude.
	Use only for distance or tube extrudeType.
	*/
	void setUseProfileNormal(bool upn){if(upn == false) return; fprintf_s(mFile, "setAttr \".upn\" %i;\n", upn);}
	/*
	If true, use the profile curve normal for the direction in which to extrude.
	Use only for distance or tube extrudeType.
	*/
	void setUseProfileNormal(const BoolID& upn){fprintf_s(mFile,"connectAttr \"");upn.write(mFile);fprintf_s(mFile,"\" \"%s.upn\";\n",mName.c_str());}
	/*
	The direction in which to extrude.
	Use only for distance extrudeType and useProfileNormal off
	*/
	void setDirection(const double3& d){fprintf_s(mFile, "setAttr \".d\" -type \"double3\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The direction in which to extrude.
	Use only for distance extrudeType and useProfileNormal off
	*/
	void setDirection(const Double3ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*X of the direction*/
	void setDirectionX(double dx){if(dx == 0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*X of the direction*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*Y of the direction*/
	void setDirectionY(double dy){if(dy == 1) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*Y of the direction*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*Z of the direction*/
	void setDirectionZ(double dz){if(dz == 0) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*Z of the direction*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*
	The distance to extrude.
	Use only for distance extrudeType
	*/
	void setLength(double l){if(l == 1) return; fprintf_s(mFile, "setAttr \".l\" %f;\n", l);}
	/*
	The distance to extrude.
	Use only for distance extrudeType
	*/
	void setLength(const DoubleID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*The pivot point used for tube extrudeType*/
	void setPivot(const double3& p){fprintf_s(mFile, "setAttr \".p\" -type \"double3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*The pivot point used for tube extrudeType*/
	void setPivot(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*X of the pivot*/
	void setPivotX(double px){if(px == 0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*X of the pivot*/
	void setPivotX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*Y of the pivot*/
	void setPivotY(double py){if(py == 0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*Y of the pivot*/
	void setPivotY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*Z of the pivot*/
	void setPivotZ(double pz){if(pz == 0) return; fprintf_s(mFile, "setAttr \".p.pz\" %f;\n", pz);}
	/*Z of the pivot*/
	void setPivotZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*Amount to rotate the profile curve as it sweeps along the path curve.*/
	void setRotation(double ro){if(ro == 0) return; fprintf_s(mFile, "setAttr \".ro\" %f;\n", ro);}
	/*Amount to rotate the profile curve as it sweeps along the path curve.*/
	void setRotation(const DoubleID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*Amount to scale the profile curve as it sweeps along the path curve.*/
	void setScale(double sc){if(sc == 1.0) return; fprintf_s(mFile, "setAttr \".sc\" %f;\n", sc);}
	/*Amount to scale the profile curve as it sweeps along the path curve.*/
	void setScale(const DoubleID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*If true, extrude type is tube (2) and path has been internally reversed then computed surface is reversed in the direction corresponding to the path.*/
	void setReverseSurfaceIfPathReversed(bool rsp){if(rsp == false) return; fprintf_s(mFile, "setAttr \".rsp\" %i;\n", rsp);}
	/*If true, extrude type is tube (2) and path has been internally reversed then computed surface is reversed in the direction corresponding to the path.*/
	void setReverseSurfaceIfPathReversed(const BoolID& rsp){fprintf_s(mFile,"connectAttr \"");rsp.write(mFile);fprintf_s(mFile,"\" \"%s.rsp\";\n",mName.c_str());}
	/*Surface degree along the distance when a distance extrude is performed*/
	void setDegreeAlongLength(short dl){if(dl == 1) return; fprintf_s(mFile, "setAttr \".dl\" %i;\n", dl);}
	/*Surface degree along the distance when a distance extrude is performed*/
	void setDegreeAlongLength(const ShortID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*If true, curve range on the path will get applied to the resulting surface instead of cut before the extrude.*/
	void setSubCurveSubSurface(bool scs){if(scs == false) return; fprintf_s(mFile, "setAttr \".scs\" %i;\n", scs);}
	/*If true, curve range on the path will get applied to the resulting surface instead of cut before the extrude.*/
	void setSubCurveSubSurface(const BoolID& scs){fprintf_s(mFile,"connectAttr \"");scs.write(mFile);fprintf_s(mFile,"\" \"%s.scs\";\n",mName.c_str());}
	/*The extruded surface.*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The curve to extrude (profile).*/
	NurbsCurveID getProfile(){char buffer[4096];sprintf_s (buffer, "%s.pr",mName.c_str());return (const char*)buffer;}
	/*
	The path curve.
	Used only if extrudeType is flat or tube
	*/
	NurbsCurveID getPath(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*The extrude type (distance-0, flat-1, or tube-2)*/
	UnsignedintID getExtrudeType(){char buffer[4096];sprintf_s (buffer, "%s.et",mName.c_str());return (const char*)buffer;}
	/*
	If true, the resulting surface will be placed at the path curve.
	Otherwise, the resulting surface will be placed at the profile curve.
	*/
	BoolID getFixedPath(){char buffer[4096];sprintf_s (buffer, "%s.fpt",mName.c_str());return (const char*)buffer;}
	/*Use closest endpoint of the path - 0, component pivot - 1 or the center of the bounding box of the profile - 2*/
	UnsignedintID getUseComponentPivot(){char buffer[4096];sprintf_s (buffer, "%s.ucp",mName.c_str());return (const char*)buffer;}
	/*
	If true, use the profile curve normal for the direction in which to extrude.
	Use only for distance or tube extrudeType.
	*/
	BoolID getUseProfileNormal(){char buffer[4096];sprintf_s (buffer, "%s.upn",mName.c_str());return (const char*)buffer;}
	/*
	The direction in which to extrude.
	Use only for distance extrudeType and useProfileNormal off
	*/
	Double3ID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*X of the direction*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*Y of the direction*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*Z of the direction*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
	/*
	The distance to extrude.
	Use only for distance extrudeType
	*/
	DoubleID getLength(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*The pivot point used for tube extrudeType*/
	Double3ID getPivot(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*X of the pivot*/
	DoubleID getPivotX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*Y of the pivot*/
	DoubleID getPivotY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*Z of the pivot*/
	DoubleID getPivotZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*Amount to rotate the profile curve as it sweeps along the path curve.*/
	DoubleID getRotation(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*Amount to scale the profile curve as it sweeps along the path curve.*/
	DoubleID getScale(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*If true, extrude type is tube (2) and path has been internally reversed then computed surface is reversed in the direction corresponding to the path.*/
	BoolID getReverseSurfaceIfPathReversed(){char buffer[4096];sprintf_s (buffer, "%s.rsp",mName.c_str());return (const char*)buffer;}
	/*Surface degree along the distance when a distance extrude is performed*/
	ShortID getDegreeAlongLength(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*If true, curve range on the path will get applied to the resulting surface instead of cut before the extrude.*/
	BoolID getSubCurveSubSurface(){char buffer[4096];sprintf_s (buffer, "%s.scs",mName.c_str());return (const char*)buffer;}
	/*The extruded surface.*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	Extrude(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_EXTRUDE_H__
