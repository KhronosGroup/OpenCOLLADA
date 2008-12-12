/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMOVEUV_H__
#define __MayaDM_POLYMOVEUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Moves the input UV coordinates in texture space.
 The mapping is manipulated without affecting the 3D
 geometry of the object.<p/>
*/
class PolyMoveUV : public PolyModifier
{
public:
public:
	PolyMoveUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyMoveUV"){}
	virtual ~PolyMoveUV(){}
	/*Translation vector.*/
	void setTranslate(const double2& t){if(t == double2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".t\" -type \"double2\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*Translation vector.*/
	void setTranslate(const Double2ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*Translation U coord.*/
	void setTranslateU(double tu){if(tu == 0.0) return; fprintf_s(mFile, "setAttr \".t.tu\" %f;\n", tu);}
	/*Translation U coord.*/
	void setTranslateU(const DoubleID& tu){fprintf_s(mFile,"connectAttr \"");tu.write(mFile);fprintf_s(mFile,"\" \"%s.t.tu\";\n",mName.c_str());}
	/*Translation V coord.*/
	void setTranslateV(double tv){if(tv == 0.0) return; fprintf_s(mFile, "setAttr \".t.tv\" %f;\n", tv);}
	/*Translation V coord.*/
	void setTranslateV(const DoubleID& tv){fprintf_s(mFile,"connectAttr \"");tv.write(mFile);fprintf_s(mFile,"\" \"%s.t.tv\";\n",mName.c_str());}
	/*Angle of rotation.*/
	void setRotationAngle(double ra){if(ra == 0) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*Angle of rotation.*/
	void setRotationAngle(const DoubleID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*The pivot for scaling and rotation.*/
	void setPivot(const double2& pvt){if(pvt == double2(0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".pvt\" -type \"double2\" ");pvt.write(mFile);fprintf_s(mFile,";\n");}
	/*The pivot for scaling and rotation.*/
	void setPivot(const Double2ID& pvt){fprintf_s(mFile,"connectAttr \"");pvt.write(mFile);fprintf_s(mFile,"\" \"%s.pvt\";\n",mName.c_str());}
	/*Pivot U coord.*/
	void setPivotU(double pvu){if(pvu == 0.0) return; fprintf_s(mFile, "setAttr \".pvt.pvu\" %f;\n", pvu);}
	/*Pivot U coord.*/
	void setPivotU(const DoubleID& pvu){fprintf_s(mFile,"connectAttr \"");pvu.write(mFile);fprintf_s(mFile,"\" \"%s.pvt.pvu\";\n",mName.c_str());}
	/*Pivot V coord.*/
	void setPivotV(double pvv){if(pvv == 0.0) return; fprintf_s(mFile, "setAttr \".pvt.pvv\" %f;\n", pvv);}
	/*Pivot V coord.*/
	void setPivotV(const DoubleID& pvv){fprintf_s(mFile,"connectAttr \"");pvv.write(mFile);fprintf_s(mFile,"\" \"%s.pvt.pvv\";\n",mName.c_str());}
	/*Scaling vector.*/
	void setScale(const double2& s){if(s == double2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".s\" -type \"double2\" ");s.write(mFile);fprintf_s(mFile,";\n");}
	/*Scaling vector.*/
	void setScale(const Double2ID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Scaling U coord.*/
	void setScaleU(double su){if(su == 0.0) return; fprintf_s(mFile, "setAttr \".s.su\" %f;\n", su);}
	/*Scaling U coord.*/
	void setScaleU(const DoubleID& su){fprintf_s(mFile,"connectAttr \"");su.write(mFile);fprintf_s(mFile,"\" \"%s.s.su\";\n",mName.c_str());}
	/*Scaling V coord.*/
	void setScaleV(double sv){if(sv == 0.0) return; fprintf_s(mFile, "setAttr \".s.sv\" %f;\n", sv);}
	/*Scaling V coord.*/
	void setScaleV(const DoubleID& sv){fprintf_s(mFile,"connectAttr \"");sv.write(mFile);fprintf_s(mFile,"\" \"%s.s.sv\";\n",mName.c_str());}
	/*Random value, added to all parameters.*/
	void setRandom(float ran){if(ran == 0.0) return; fprintf_s(mFile, "setAttr \".ran\" %f;\n", ran);}
	/*Random value, added to all parameters.*/
	void setRandom(const FloatID& ran){fprintf_s(mFile,"connectAttr \"");ran.write(mFile);fprintf_s(mFile,"\" \"%s.ran\";\n",mName.c_str());}
	/*Random seed for this node. Computed automatically.*/
	void setRandomSeed(int rs){if(rs == 0) return; fprintf_s(mFile, "setAttr \".rs\" %i;\n", rs);}
	/*Random seed for this node. Computed automatically.*/
	void setRandomSeed(const IntID& rs){fprintf_s(mFile,"connectAttr \"");rs.write(mFile);fprintf_s(mFile,"\" \"%s.rs\";\n",mName.c_str());}
	/*AxisLen vector, used to draw the manip handles.*/
	void setAxisLen(const double2& l){if(l == double2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".l\" -type \"double2\" ");l.write(mFile);fprintf_s(mFile,";\n");}
	/*AxisLen vector, used to draw the manip handles.*/
	void setAxisLen(const Double2ID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*AxisLen X coord.*/
	void setAxisLenX(double lx){if(lx == 0.0) return; fprintf_s(mFile, "setAttr \".l.lx\" %f;\n", lx);}
	/*AxisLen X coord.*/
	void setAxisLenX(const DoubleID& lx){fprintf_s(mFile,"connectAttr \"");lx.write(mFile);fprintf_s(mFile,"\" \"%s.l.lx\";\n",mName.c_str());}
	/*AxisLen Y coord.*/
	void setAxisLenY(double ly){if(ly == 0.0) return; fprintf_s(mFile, "setAttr \".l.ly\" %f;\n", ly);}
	/*AxisLen Y coord.*/
	void setAxisLenY(const DoubleID& ly){fprintf_s(mFile,"connectAttr \"");ly.write(mFile);fprintf_s(mFile,"\" \"%s.l.ly\";\n",mName.c_str());}
	/*Which component to place the manip on (for interaction purposes only).*/
	void setCompId(const IntID& cid){fprintf_s(mFile,"connectAttr \"");cid.write(mFile);fprintf_s(mFile,"\" \"%s.cid\";\n",mName.c_str());}
	/*The name of the uv set to work on*/
	void setUvSetName(const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs\" -type \"string\" ");uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the uv set to work on*/
	void setUvSetName(const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*Translation vector.*/
	Double2ID getTranslate(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*Translation U coord.*/
	DoubleID getTranslateU(){char buffer[4096];sprintf_s (buffer, "%s.t.tu",mName.c_str());return (const char*)buffer;}
	/*Translation V coord.*/
	DoubleID getTranslateV(){char buffer[4096];sprintf_s (buffer, "%s.t.tv",mName.c_str());return (const char*)buffer;}
	/*Angle of rotation.*/
	DoubleID getRotationAngle(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*The pivot for scaling and rotation.*/
	Double2ID getPivot(){char buffer[4096];sprintf_s (buffer, "%s.pvt",mName.c_str());return (const char*)buffer;}
	/*Pivot U coord.*/
	DoubleID getPivotU(){char buffer[4096];sprintf_s (buffer, "%s.pvt.pvu",mName.c_str());return (const char*)buffer;}
	/*Pivot V coord.*/
	DoubleID getPivotV(){char buffer[4096];sprintf_s (buffer, "%s.pvt.pvv",mName.c_str());return (const char*)buffer;}
	/*Scaling vector.*/
	Double2ID getScale(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Scaling U coord.*/
	DoubleID getScaleU(){char buffer[4096];sprintf_s (buffer, "%s.s.su",mName.c_str());return (const char*)buffer;}
	/*Scaling V coord.*/
	DoubleID getScaleV(){char buffer[4096];sprintf_s (buffer, "%s.s.sv",mName.c_str());return (const char*)buffer;}
	/*Random value, added to all parameters.*/
	FloatID getRandom(){char buffer[4096];sprintf_s (buffer, "%s.ran",mName.c_str());return (const char*)buffer;}
	/*Random seed for this node. Computed automatically.*/
	IntID getRandomSeed(){char buffer[4096];sprintf_s (buffer, "%s.rs",mName.c_str());return (const char*)buffer;}
	/*AxisLen vector, used to draw the manip handles.*/
	Double2ID getAxisLen(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*AxisLen X coord.*/
	DoubleID getAxisLenX(){char buffer[4096];sprintf_s (buffer, "%s.l.lx",mName.c_str());return (const char*)buffer;}
	/*AxisLen Y coord.*/
	DoubleID getAxisLenY(){char buffer[4096];sprintf_s (buffer, "%s.l.ly",mName.c_str());return (const char*)buffer;}
	/*Which component to place the manip on (for interaction purposes only).*/
	IntID getCompId(){char buffer[4096];sprintf_s (buffer, "%s.cid",mName.c_str());return (const char*)buffer;}
	/*The name of the uv set to work on*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
protected:
	PolyMoveUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEUV_H__
