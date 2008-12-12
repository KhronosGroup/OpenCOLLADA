/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LOCATOR_H__
#define __MayaDM_LOCATOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
/*
A locator marks a position in world space or underworld space.
 A locator appears as a small gnomon, with lines extending in
 each major direction (along the X, Y and Z axis).
 You can also use point snapping to snap to a locator position.
*/
class Locator : public GeometryShape
{
public:
public:
	Locator(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "locator"){}
	virtual ~Locator(){}
	/*
	Specifies if the locator is defined in world space or in
	underworld space.  True means the locator is defined
	in underworld space.
	*/
	void setUnderWorldObject(bool uwo){if(uwo == false) return; fprintf_s(mFile, "setAttr \".uwo\" %i;\n", uwo);}
	/*Locator's position in local space coordinates.*/
	void setLocalPosition(const double3& lp){if(lp == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".lp\" -type \"double3\" ");lp.write(mFile);fprintf_s(mFile,";\n");}
	/*Locator's position in local space coordinates.*/
	void setLocalPosition(const Double3ID& lp){fprintf_s(mFile,"connectAttr \"");lp.write(mFile);fprintf_s(mFile,"\" \"%s.lp\";\n",mName.c_str());}
	/*Local location in X.*/
	void setLocalPositionX(double lpx){if(lpx == 0) return; fprintf_s(mFile, "setAttr \".lp.lpx\" %f;\n", lpx);}
	/*Local location in X.*/
	void setLocalPositionX(const DoubleID& lpx){fprintf_s(mFile,"connectAttr \"");lpx.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpx\";\n",mName.c_str());}
	/*Local location in Y.*/
	void setLocalPositionY(double lpy){if(lpy == 0) return; fprintf_s(mFile, "setAttr \".lp.lpy\" %f;\n", lpy);}
	/*Local location in Y.*/
	void setLocalPositionY(const DoubleID& lpy){fprintf_s(mFile,"connectAttr \"");lpy.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpy\";\n",mName.c_str());}
	/*Local location in Z.*/
	void setLocalPositionZ(double lpz){if(lpz == 0) return; fprintf_s(mFile, "setAttr \".lp.lpz\" %f;\n", lpz);}
	/*Local location in Z.*/
	void setLocalPositionZ(const DoubleID& lpz){fprintf_s(mFile,"connectAttr \"");lpz.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpz\";\n",mName.c_str());}
	/*
	Locator's position in world space coordinates.  This position
	includes all transformations above the locator.
	*/
	void setWorldPosition(size_t wp_i,const Double3ID& wp){fprintf_s(mFile,"connectAttr \"");wp.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i]\";\n",mName.c_str(),wp_i);}
	/*World space location in X.*/
	void setWorldPositionX(size_t wp_i,const DoubleID& wpx){fprintf_s(mFile,"connectAttr \"");wpx.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpx\";\n",mName.c_str(),wp_i);}
	/*World space location in Y.*/
	void setWorldPositionY(size_t wp_i,const DoubleID& wpy){fprintf_s(mFile,"connectAttr \"");wpy.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpy\";\n",mName.c_str(),wp_i);}
	/*World space location in Z.*/
	void setWorldPositionZ(size_t wp_i,const DoubleID& wpz){fprintf_s(mFile,"connectAttr \"");wpz.write(mFile);fprintf_s(mFile,"\" \"%s.wp[%i].wpz\";\n",mName.c_str(),wp_i);}
	/*Locator's local scale*/
	void setLocalScale(const double3& los){if(los == double3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".los\" -type \"double3\" ");los.write(mFile);fprintf_s(mFile,";\n");}
	/*Locator's local scale*/
	void setLocalScale(const Double3ID& los){fprintf_s(mFile,"connectAttr \"");los.write(mFile);fprintf_s(mFile,"\" \"%s.los\";\n",mName.c_str());}
	/*Local scale in X.*/
	void setLocalScaleX(double lsx){if(lsx == 1) return; fprintf_s(mFile, "setAttr \".los.lsx\" %f;\n", lsx);}
	/*Local scale in X.*/
	void setLocalScaleX(const DoubleID& lsx){fprintf_s(mFile,"connectAttr \"");lsx.write(mFile);fprintf_s(mFile,"\" \"%s.los.lsx\";\n",mName.c_str());}
	/*Local scale in Y.*/
	void setLocalScaleY(double lsy){if(lsy == 1) return; fprintf_s(mFile, "setAttr \".los.lsy\" %f;\n", lsy);}
	/*Local scale in Y.*/
	void setLocalScaleY(const DoubleID& lsy){fprintf_s(mFile,"connectAttr \"");lsy.write(mFile);fprintf_s(mFile,"\" \"%s.los.lsy\";\n",mName.c_str());}
	/*Local scale in Z.*/
	void setLocalScaleZ(double lsz){if(lsz == 1) return; fprintf_s(mFile, "setAttr \".los.lsz\" %f;\n", lsz);}
	/*Local scale in Z.*/
	void setLocalScaleZ(const DoubleID& lsz){fprintf_s(mFile,"connectAttr \"");lsz.write(mFile);fprintf_s(mFile,"\" \"%s.los.lsz\";\n",mName.c_str());}
	/*Locator's position in local space coordinates.*/
	Double3ID getLocalPosition(){char buffer[4096];sprintf_s (buffer, "%s.lp",mName.c_str());return (const char*)buffer;}
	/*Local location in X.*/
	DoubleID getLocalPositionX(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpx",mName.c_str());return (const char*)buffer;}
	/*Local location in Y.*/
	DoubleID getLocalPositionY(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpy",mName.c_str());return (const char*)buffer;}
	/*Local location in Z.*/
	DoubleID getLocalPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpz",mName.c_str());return (const char*)buffer;}
	/*
	Locator's position in world space coordinates.  This position
	includes all transformations above the locator.
	*/
	const Double3ID& getWorldPosition(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i]",mName.c_str(),wp_i);return (const char*)buffer;}
	/*World space location in X.*/
	const DoubleID& getWorldPositionX(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpx",mName.c_str(),wp_i);return (const char*)buffer;}
	/*World space location in Y.*/
	const DoubleID& getWorldPositionY(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpy",mName.c_str(),wp_i);return (const char*)buffer;}
	/*World space location in Z.*/
	const DoubleID& getWorldPositionZ(size_t wp_i){char buffer[4096];sprintf_s (buffer, "%s.wp[%i].wpz",mName.c_str(),wp_i);return (const char*)buffer;}
	/*Locator's local scale*/
	Double3ID getLocalScale(){char buffer[4096];sprintf_s (buffer, "%s.los",mName.c_str());return (const char*)buffer;}
	/*Local scale in X.*/
	DoubleID getLocalScaleX(){char buffer[4096];sprintf_s (buffer, "%s.los.lsx",mName.c_str());return (const char*)buffer;}
	/*Local scale in Y.*/
	DoubleID getLocalScaleY(){char buffer[4096];sprintf_s (buffer, "%s.los.lsy",mName.c_str());return (const char*)buffer;}
	/*Local scale in Z.*/
	DoubleID getLocalScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.los.lsz",mName.c_str());return (const char*)buffer;}
protected:
	Locator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LOCATOR_H__
