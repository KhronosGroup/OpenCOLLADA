/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SCULPT_H__
#define __MayaDM_SCULPT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
<p><pre>This node takes geometry as input and deforms it by pushing a sculpting
tool (at present, a sphere) into it.
</pre></p>
*/
class Sculpt : public GeometryFilter
{
public:
public:
	Sculpt(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "sculpt"){}
	virtual ~Sculpt(){}
	/*World space matrix above the sculpt sphere*/
	void setSculptObjectMatrix(const matrix& sm){if(sm == identity) return; fprintf_s(mFile, "setAttr \".sm\" -type \"matrix\" ");sm.write(mFile);fprintf_s(mFile,";\n");}
	/*World space matrix above the sculpt sphere*/
	void setSculptObjectMatrix(const MatrixID& sm){fprintf_s(mFile,"connectAttr \"");sm.write(mFile);fprintf_s(mFile,"\" \"%s.sm\";\n",mName.c_str());}
	/*
	Geometry being used as the sculpt sphere.
	At present, this must be connected to an implicitSphere node.
	*/
	void setSculptObjectGeometry(const GeometryID& sg){fprintf_s(mFile,"connectAttr \"");sg.write(mFile);fprintf_s(mFile,"\" \"%s.sg\";\n",mName.c_str());}
	/*
	Which deformation algorithm to use to displace points.
	Valid values are: 0 = "flip", 1 = "project", 2 = "stretch".
	*/
	void setMode(unsigned int mo){if(mo == 2) return; fprintf_s(mFile, "setAttr \".mo\" %i;\n", mo);}
	/*
	Which deformation algorithm to use to displace points.
	Valid values are: 0 = "flip", 1 = "project", 2 = "stretch".
	*/
	void setMode(const UnsignedintID& mo){fprintf_s(mFile,"connectAttr \"");mo.write(mFile);fprintf_s(mFile,"\" \"%s.mo\";\n",mName.c_str());}
	/*
	Which algorithm to use to handle points inside the sculpt sphere
	Valid values are: 0 = "ring", 1 = "even".
	*/
	void setInsideMode(unsigned int im){if(im == 1) return; fprintf_s(mFile, "setAttr \".im\" %i;\n", im);}
	/*
	Which algorithm to use to handle points inside the sculpt sphere
	Valid values are: 0 = "ring", 1 = "even".
	*/
	void setInsideMode(const UnsignedintID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*
	Maximum amount a point may be displaced from the surface of
	the sculpt sphere.
	*/
	void setMaximumDisplacement(double md){if(md == 1) return; fprintf_s(mFile, "setAttr \".md\" %f;\n", md);}
	/*
	Maximum amount a point may be displaced from the surface of
	the sculpt sphere.
	*/
	void setMaximumDisplacement(const DoubleID& md){fprintf_s(mFile,"connectAttr \"");md.write(mFile);fprintf_s(mFile,"\" \"%s.md\";\n",mName.c_str());}
	/*
	Distance from the surface of the sculpt sphere at which
	the deformation effect becomes zero.
	*/
	void setDropoffDistance(double dd){if(dd == 1) return; fprintf_s(mFile, "setAttr \".dd\" %f;\n", dd);}
	/*
	Distance from the surface of the sculpt sphere at which
	the deformation effect becomes zero.
	*/
	void setDropoffDistance(const DoubleID& dd){fprintf_s(mFile,"connectAttr \"");dd.write(mFile);fprintf_s(mFile,"\" \"%s.dd\";\n",mName.c_str());}
	/*
	How the deformation effect drops to zero.
	Valid values are: 0 = "none", 1 = "linear".
	*/
	void setDropoffType(unsigned int dt){if(dt == 1) return; fprintf_s(mFile, "setAttr \".dt\" %i;\n", dt);}
	/*
	How the deformation effect drops to zero.
	Valid values are: 0 = "none", 1 = "linear".
	*/
	void setDropoffType(const UnsignedintID& dt){fprintf_s(mFile,"connectAttr \"");dt.write(mFile);fprintf_s(mFile,"\" \"%s.dt\";\n",mName.c_str());}
	/*
	Used by stretch mode as the initial position for the sculpt sphere.
	For both stretch and flip mode, when inside mode is even it is also
	used in conjuction with the current sculpt sphere position to provide
	a hint as to which direction to displace points that are
	inside the sculpt sphere.
	*/
	void setStartPosition(const float3& sp){fprintf_s(mFile, "setAttr \".sp\" -type \"float3\" ");sp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Used by stretch mode as the initial position for the sculpt sphere.
	For both stretch and flip mode, when inside mode is even it is also
	used in conjuction with the current sculpt sphere position to provide
	a hint as to which direction to displace points that are
	inside the sculpt sphere.
	*/
	void setStartPosition(const Float3ID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*Starting position X value.*/
	void setStartPosX(float sx){if(sx == 0) return; fprintf_s(mFile, "setAttr \".sp.sx\" %f;\n", sx);}
	/*Starting position X value.*/
	void setStartPosX(const FloatID& sx){fprintf_s(mFile,"connectAttr \"");sx.write(mFile);fprintf_s(mFile,"\" \"%s.sp.sx\";\n",mName.c_str());}
	/*Starting position Y value.*/
	void setStartPosY(float sy){if(sy == 0) return; fprintf_s(mFile, "setAttr \".sp.sy\" %f;\n", sy);}
	/*Starting position Y value.*/
	void setStartPosY(const FloatID& sy){fprintf_s(mFile,"connectAttr \"");sy.write(mFile);fprintf_s(mFile,"\" \"%s.sp.sy\";\n",mName.c_str());}
	/*Starting position Z value.*/
	void setStartPosZ(float sz){if(sz == 0) return; fprintf_s(mFile, "setAttr \".sp.sz\" %f;\n", sz);}
	/*Starting position Z value.*/
	void setStartPosZ(const FloatID& sz){fprintf_s(mFile,"connectAttr \"");sz.write(mFile);fprintf_s(mFile,"\" \"%s.sp.sz\";\n",mName.c_str());}
	/*
	When set to true, it prevents discontinuity in the deformation
	as the sculpt sphere crosses over the sculpt origin.
	*/
	void setExtendedEnd(bool exd){if(exd == false) return; fprintf_s(mFile, "setAttr \".exd\" %i;\n", exd);}
	/*
	When set to true, it prevents discontinuity in the deformation
	as the sculpt sphere crosses over the sculpt origin.
	*/
	void setExtendedEnd(const BoolID& exd){fprintf_s(mFile,"connectAttr \"");exd.write(mFile);fprintf_s(mFile,"\" \"%s.exd\";\n",mName.c_str());}
	/*World space matrix above the sculpt sphere*/
	MatrixID getSculptObjectMatrix(){char buffer[4096];sprintf_s (buffer, "%s.sm",mName.c_str());return (const char*)buffer;}
	/*
	Geometry being used as the sculpt sphere.
	At present, this must be connected to an implicitSphere node.
	*/
	GeometryID getSculptObjectGeometry(){char buffer[4096];sprintf_s (buffer, "%s.sg",mName.c_str());return (const char*)buffer;}
	/*
	Which deformation algorithm to use to displace points.
	Valid values are: 0 = "flip", 1 = "project", 2 = "stretch".
	*/
	UnsignedintID getMode(){char buffer[4096];sprintf_s (buffer, "%s.mo",mName.c_str());return (const char*)buffer;}
	/*
	Which algorithm to use to handle points inside the sculpt sphere
	Valid values are: 0 = "ring", 1 = "even".
	*/
	UnsignedintID getInsideMode(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*
	Maximum amount a point may be displaced from the surface of
	the sculpt sphere.
	*/
	DoubleID getMaximumDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.md",mName.c_str());return (const char*)buffer;}
	/*
	Distance from the surface of the sculpt sphere at which
	the deformation effect becomes zero.
	*/
	DoubleID getDropoffDistance(){char buffer[4096];sprintf_s (buffer, "%s.dd",mName.c_str());return (const char*)buffer;}
	/*
	How the deformation effect drops to zero.
	Valid values are: 0 = "none", 1 = "linear".
	*/
	UnsignedintID getDropoffType(){char buffer[4096];sprintf_s (buffer, "%s.dt",mName.c_str());return (const char*)buffer;}
	/*
	Used by stretch mode as the initial position for the sculpt sphere.
	For both stretch and flip mode, when inside mode is even it is also
	used in conjuction with the current sculpt sphere position to provide
	a hint as to which direction to displace points that are
	inside the sculpt sphere.
	*/
	Float3ID getStartPosition(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*Starting position X value.*/
	FloatID getStartPosX(){char buffer[4096];sprintf_s (buffer, "%s.sp.sx",mName.c_str());return (const char*)buffer;}
	/*Starting position Y value.*/
	FloatID getStartPosY(){char buffer[4096];sprintf_s (buffer, "%s.sp.sy",mName.c_str());return (const char*)buffer;}
	/*Starting position Z value.*/
	FloatID getStartPosZ(){char buffer[4096];sprintf_s (buffer, "%s.sp.sz",mName.c_str());return (const char*)buffer;}
	/*
	When set to true, it prevents discontinuity in the deformation
	as the sculpt sphere crosses over the sculpt origin.
	*/
	BoolID getExtendedEnd(){char buffer[4096];sprintf_s (buffer, "%s.exd",mName.c_str());return (const char*)buffer;}
protected:
	Sculpt(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SCULPT_H__
