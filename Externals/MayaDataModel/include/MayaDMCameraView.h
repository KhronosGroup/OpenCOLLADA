/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CAMERAVIEW_H__
#define __MayaDM_CAMERAVIEW_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
 Dependency node to represent a camera's view.

</pre></p>
*/
class CameraView : public DependNode
{
public:
public:
	CameraView(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "cameraView"){}
	virtual ~CameraView(){}
	/*Eye point in world space*/
	void setEye(const double3& e){if(e == double3(60.0, 45.0, 60.0)) return; fprintf_s(mFile, "setAttr \".e\" -type \"double3\" ");e.write(mFile);fprintf_s(mFile,";\n");}
	/*Eye point in world space*/
	void setEye(const Double3ID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*Eye X in world space*/
	void setEyeX(double ex){if(ex == 0) return; fprintf_s(mFile, "setAttr \".e.ex\" %f;\n", ex);}
	/*Eye X in world space*/
	void setEyeX(const DoubleID& ex){fprintf_s(mFile,"connectAttr \"");ex.write(mFile);fprintf_s(mFile,"\" \"%s.e.ex\";\n",mName.c_str());}
	/*Eye Y in world space*/
	void setEyeY(double ey){if(ey == 0) return; fprintf_s(mFile, "setAttr \".e.ey\" %f;\n", ey);}
	/*Eye Y in world space*/
	void setEyeY(const DoubleID& ey){fprintf_s(mFile,"connectAttr \"");ey.write(mFile);fprintf_s(mFile,"\" \"%s.e.ey\";\n",mName.c_str());}
	/*Eye Z in world space*/
	void setEyeZ(double ez){if(ez == 0) return; fprintf_s(mFile, "setAttr \".e.ez\" %f;\n", ez);}
	/*Eye Z in world space*/
	void setEyeZ(const DoubleID& ez){fprintf_s(mFile,"connectAttr \"");ez.write(mFile);fprintf_s(mFile,"\" \"%s.e.ez\";\n",mName.c_str());}
	/*Center of interest point in world space*/
	void setCenterOfInterest(const double3& coi){if(coi == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".coi\" -type \"double3\" ");coi.write(mFile);fprintf_s(mFile,";\n");}
	/*Center of interest point in world space*/
	void setCenterOfInterest(const Double3ID& coi){fprintf_s(mFile,"connectAttr \"");coi.write(mFile);fprintf_s(mFile,"\" \"%s.coi\";\n",mName.c_str());}
	/*Center of interest X in world space*/
	void setCenterOfInterestX(double cx){if(cx == 0) return; fprintf_s(mFile, "setAttr \".coi.cx\" %f;\n", cx);}
	/*Center of interest X in world space*/
	void setCenterOfInterestX(const DoubleID& cx){fprintf_s(mFile,"connectAttr \"");cx.write(mFile);fprintf_s(mFile,"\" \"%s.coi.cx\";\n",mName.c_str());}
	/*Center of interest Y in world space*/
	void setCenterOfInterestY(double cy){if(cy == 0) return; fprintf_s(mFile, "setAttr \".coi.cy\" %f;\n", cy);}
	/*Center of interest Y in world space*/
	void setCenterOfInterestY(const DoubleID& cy){fprintf_s(mFile,"connectAttr \"");cy.write(mFile);fprintf_s(mFile,"\" \"%s.coi.cy\";\n",mName.c_str());}
	/*Center of interest Z in world space*/
	void setCenterOfInterestZ(double cz){if(cz == 0) return; fprintf_s(mFile, "setAttr \".coi.cz\" %f;\n", cz);}
	/*Center of interest Z in world space*/
	void setCenterOfInterestZ(const DoubleID& cz){fprintf_s(mFile,"connectAttr \"");cz.write(mFile);fprintf_s(mFile,"\" \"%s.coi.cz\";\n",mName.c_str());}
	/*Up vector in world space*/
	void setUp(const double3& u){if(u == double3(0.0, 1.0, 0.0)) return; fprintf_s(mFile, "setAttr \".u\" -type \"double3\" ");u.write(mFile);fprintf_s(mFile,";\n");}
	/*Up vector in world space*/
	void setUp(const Double3ID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*Up X in world space*/
	void setUpX(double ux){if(ux == 0) return; fprintf_s(mFile, "setAttr \".u.ux\" %f;\n", ux);}
	/*Up X in world space*/
	void setUpX(const DoubleID& ux){fprintf_s(mFile,"connectAttr \"");ux.write(mFile);fprintf_s(mFile,"\" \"%s.u.ux\";\n",mName.c_str());}
	/*Up Y in world space*/
	void setUpY(double uy){if(uy == 0) return; fprintf_s(mFile, "setAttr \".u.uy\" %f;\n", uy);}
	/*Up Y in world space*/
	void setUpY(const DoubleID& uy){fprintf_s(mFile,"connectAttr \"");uy.write(mFile);fprintf_s(mFile,"\" \"%s.u.uy\";\n",mName.c_str());}
	/*Up Z in world space*/
	void setUpZ(double uz){if(uz == 0) return; fprintf_s(mFile, "setAttr \".u.uz\" %f;\n", uz);}
	/*Up Z in world space*/
	void setUpZ(const DoubleID& uz){fprintf_s(mFile,"connectAttr \"");uz.write(mFile);fprintf_s(mFile,"\" \"%s.u.uz\";\n",mName.c_str());}
	/*Tumble pivot point in world space*/
	void setTumblePivot(const double3& tp){if(tp == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tp\" -type \"double3\" ");tp.write(mFile);fprintf_s(mFile,";\n");}
	/*Tumble pivot point in world space*/
	void setTumblePivot(const Double3ID& tp){fprintf_s(mFile,"connectAttr \"");tp.write(mFile);fprintf_s(mFile,"\" \"%s.tp\";\n",mName.c_str());}
	/*Tumble pivot X in world space*/
	void setTumblePivotX(double tpx){if(tpx == 0) return; fprintf_s(mFile, "setAttr \".tp.tpx\" %f;\n", tpx);}
	/*Tumble pivot X in world space*/
	void setTumblePivotX(const DoubleID& tpx){fprintf_s(mFile,"connectAttr \"");tpx.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpx\";\n",mName.c_str());}
	/*Tumble pivot Y in world space*/
	void setTumblePivotY(double tpy){if(tpy == 0) return; fprintf_s(mFile, "setAttr \".tp.tpy\" %f;\n", tpy);}
	/*Tumble pivot Y in world space*/
	void setTumblePivotY(const DoubleID& tpy){fprintf_s(mFile,"connectAttr \"");tpy.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpy\";\n",mName.c_str());}
	/*Tumble pivot Z in world space*/
	void setTumblePivotZ(double tpz){if(tpz == 0) return; fprintf_s(mFile, "setAttr \".tp.tpz\" %f;\n", tpz);}
	/*Tumble pivot Z in world space*/
	void setTumblePivotZ(const DoubleID& tpz){fprintf_s(mFile,"connectAttr \"");tpz.write(mFile);fprintf_s(mFile,"\" \"%s.tp.tpz\";\n",mName.c_str());}
	/*horizontal aperture in inches*/
	void setHorizontalAperture(double ha){if(ha == 3) return; fprintf_s(mFile, "setAttr \".ha\" %f;\n", ha);}
	/*horizontal aperture in inches*/
	void setHorizontalAperture(const DoubleID& ha){fprintf_s(mFile,"connectAttr \"");ha.write(mFile);fprintf_s(mFile,"\" \"%s.ha\";\n",mName.c_str());}
	/*Vertical aperture in inches*/
	void setVerticalAperture(double va){if(va == 2) return; fprintf_s(mFile, "setAttr \".va\" %f;\n", va);}
	/*Vertical aperture in inches*/
	void setVerticalAperture(const DoubleID& va){fprintf_s(mFile,"connectAttr \"");va.write(mFile);fprintf_s(mFile,"\" \"%s.va\";\n",mName.c_str());}
	/*Focal length in millimeters*/
	void setFocalLength(double fl){if(fl == 35.0) return; fprintf_s(mFile, "setAttr \".fl\" %f;\n", fl);}
	/*Focal length in millimeters*/
	void setFocalLength(const DoubleID& fl){fprintf_s(mFile,"connectAttr \"");fl.write(mFile);fprintf_s(mFile,"\" \"%s.fl\";\n",mName.c_str());}
	/*Orthographic width in world space*/
	void setOrthographicWidth(double ow){if(ow == 1) return; fprintf_s(mFile, "setAttr \".ow\" %f;\n", ow);}
	/*Orthographic width in world space*/
	void setOrthographicWidth(const DoubleID& ow){fprintf_s(mFile,"connectAttr \"");ow.write(mFile);fprintf_s(mFile,"\" \"%s.ow\";\n",mName.c_str());}
	/*Orthographic state*/
	void setOrthographic(bool o){if(o == false) return; fprintf_s(mFile, "setAttr \".o\" %i;\n", o);}
	/*Orthographic state*/
	void setOrthographic(const BoolID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Description of the camera view*/
	void setDescription(const string& d){if(d == "NULL") return; fprintf_s(mFile, "setAttr \".d\" -type \"string\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*Description of the camera view*/
	void setDescription(const StringID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Eye point in world space*/
	Double3ID getEye(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
	/*Eye X in world space*/
	DoubleID getEyeX(){char buffer[4096];sprintf_s (buffer, "%s.e.ex",mName.c_str());return (const char*)buffer;}
	/*Eye Y in world space*/
	DoubleID getEyeY(){char buffer[4096];sprintf_s (buffer, "%s.e.ey",mName.c_str());return (const char*)buffer;}
	/*Eye Z in world space*/
	DoubleID getEyeZ(){char buffer[4096];sprintf_s (buffer, "%s.e.ez",mName.c_str());return (const char*)buffer;}
	/*Center of interest point in world space*/
	Double3ID getCenterOfInterest(){char buffer[4096];sprintf_s (buffer, "%s.coi",mName.c_str());return (const char*)buffer;}
	/*Center of interest X in world space*/
	DoubleID getCenterOfInterestX(){char buffer[4096];sprintf_s (buffer, "%s.coi.cx",mName.c_str());return (const char*)buffer;}
	/*Center of interest Y in world space*/
	DoubleID getCenterOfInterestY(){char buffer[4096];sprintf_s (buffer, "%s.coi.cy",mName.c_str());return (const char*)buffer;}
	/*Center of interest Z in world space*/
	DoubleID getCenterOfInterestZ(){char buffer[4096];sprintf_s (buffer, "%s.coi.cz",mName.c_str());return (const char*)buffer;}
	/*Up vector in world space*/
	Double3ID getUp(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*Up X in world space*/
	DoubleID getUpX(){char buffer[4096];sprintf_s (buffer, "%s.u.ux",mName.c_str());return (const char*)buffer;}
	/*Up Y in world space*/
	DoubleID getUpY(){char buffer[4096];sprintf_s (buffer, "%s.u.uy",mName.c_str());return (const char*)buffer;}
	/*Up Z in world space*/
	DoubleID getUpZ(){char buffer[4096];sprintf_s (buffer, "%s.u.uz",mName.c_str());return (const char*)buffer;}
	/*Tumble pivot point in world space*/
	Double3ID getTumblePivot(){char buffer[4096];sprintf_s (buffer, "%s.tp",mName.c_str());return (const char*)buffer;}
	/*Tumble pivot X in world space*/
	DoubleID getTumblePivotX(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpx",mName.c_str());return (const char*)buffer;}
	/*Tumble pivot Y in world space*/
	DoubleID getTumblePivotY(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpy",mName.c_str());return (const char*)buffer;}
	/*Tumble pivot Z in world space*/
	DoubleID getTumblePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.tp.tpz",mName.c_str());return (const char*)buffer;}
	/*horizontal aperture in inches*/
	DoubleID getHorizontalAperture(){char buffer[4096];sprintf_s (buffer, "%s.ha",mName.c_str());return (const char*)buffer;}
	/*Vertical aperture in inches*/
	DoubleID getVerticalAperture(){char buffer[4096];sprintf_s (buffer, "%s.va",mName.c_str());return (const char*)buffer;}
	/*Focal length in millimeters*/
	DoubleID getFocalLength(){char buffer[4096];sprintf_s (buffer, "%s.fl",mName.c_str());return (const char*)buffer;}
	/*Orthographic width in world space*/
	DoubleID getOrthographicWidth(){char buffer[4096];sprintf_s (buffer, "%s.ow",mName.c_str());return (const char*)buffer;}
	/*Orthographic state*/
	BoolID getOrthographic(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*Description of the camera view*/
	StringID getDescription(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
protected:
	CameraView(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CAMERAVIEW_H__
