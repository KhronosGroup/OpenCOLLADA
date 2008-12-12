/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMOVEVERTEX_H__
#define __MayaDM_POLYMOVEVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
Translate, rotate or scale vertices of a polygonal object.<p/>

 This node also acts as a base for poly modifier nodes that
 perform geometrical transformations (polyMoveEdge, polyMoveFace,
 polyChipOff, polyExtrudeFace).<p/>
*/
class PolyMoveVertex : public PolyModifierWorld
{
public:
public:
	PolyMoveVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyMoveVertex"){}
	virtual ~PolyMoveVertex(){}
	/*Translation vector.*/
	void setTranslate(const double3& t){if(t == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".t\" -type \"double3\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*Translation vector.*/
	void setTranslate(const Double3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*Translation X coord.*/
	void setTranslateX(double tx){if(tx == 0) return; fprintf_s(mFile, "setAttr \".t.tx\" %f;\n", tx);}
	/*Translation X coord.*/
	void setTranslateX(const DoubleID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.t.tx\";\n",mName.c_str());}
	/*Translation Y coord.*/
	void setTranslateY(double ty){if(ty == 0) return; fprintf_s(mFile, "setAttr \".t.ty\" %f;\n", ty);}
	/*Translation Y coord.*/
	void setTranslateY(const DoubleID& ty){fprintf_s(mFile,"connectAttr \"");ty.write(mFile);fprintf_s(mFile,"\" \"%s.t.ty\";\n",mName.c_str());}
	/*Translation Z coord.*/
	void setTranslateZ(double tz){if(tz == 0) return; fprintf_s(mFile, "setAttr \".t.tz\" %f;\n", tz);}
	/*Translation Z coord.*/
	void setTranslateZ(const DoubleID& tz){fprintf_s(mFile,"connectAttr \"");tz.write(mFile);fprintf_s(mFile,"\" \"%s.t.tz\";\n",mName.c_str());}
	/*Rotation angles around X, Y, Z.*/
	void setRotate(const double3& ro){if(ro == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ro\" -type \"double3\" ");ro.write(mFile);fprintf_s(mFile,";\n");}
	/*Rotation angles around X, Y, Z.*/
	void setRotate(const Double3ID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*Rotation angle around X.*/
	void setRotateX(double rx){if(rx == 0) return; fprintf_s(mFile, "setAttr \".ro.rx\" %f;\n", rx);}
	/*Rotation angle around X.*/
	void setRotateX(const DoubleID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.ro.rx\";\n",mName.c_str());}
	/*Rotation angle around Y.*/
	void setRotateY(double ry){if(ry == 0) return; fprintf_s(mFile, "setAttr \".ro.ry\" %f;\n", ry);}
	/*Rotation angle around Y.*/
	void setRotateY(const DoubleID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.ro.ry\";\n",mName.c_str());}
	/*Rotation angle around Z.*/
	void setRotateZ(double rz){if(rz == 0) return; fprintf_s(mFile, "setAttr \".ro.rz\" %f;\n", rz);}
	/*Rotation angle around Z.*/
	void setRotateZ(const DoubleID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.ro.rz\";\n",mName.c_str());}
	/*Scaling vector.*/
	void setScale(const double3& s){if(s == double3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".s\" -type \"double3\" ");s.write(mFile);fprintf_s(mFile,";\n");}
	/*Scaling vector.*/
	void setScale(const Double3ID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Scale X coord.*/
	void setScaleX(double sx){if(sx == 0.0) return; fprintf_s(mFile, "setAttr \".s.sx\" %f;\n", sx);}
	/*Scale X coord.*/
	void setScaleX(const DoubleID& sx){fprintf_s(mFile,"connectAttr \"");sx.write(mFile);fprintf_s(mFile,"\" \"%s.s.sx\";\n",mName.c_str());}
	/*Scale Y coord.*/
	void setScaleY(double sy){if(sy == 0.0) return; fprintf_s(mFile, "setAttr \".s.sy\" %f;\n", sy);}
	/*Scale Y coord.*/
	void setScaleY(const DoubleID& sy){fprintf_s(mFile,"connectAttr \"");sy.write(mFile);fprintf_s(mFile,"\" \"%s.s.sy\";\n",mName.c_str());}
	/*Scale Z coord.*/
	void setScaleZ(double sz){if(sz == 0.0) return; fprintf_s(mFile, "setAttr \".s.sz\" %f;\n", sz);}
	/*Scale Z coord.*/
	void setScaleZ(const DoubleID& sz){fprintf_s(mFile,"connectAttr \"");sz.write(mFile);fprintf_s(mFile,"\" \"%s.s.sz\";\n",mName.c_str());}
	/*The pivot for scaling and rotation.*/
	void setPivot(const float3& pvt){if(pvt == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".pvt\" -type \"float3\" ");pvt.write(mFile);fprintf_s(mFile,";\n");}
	/*The pivot for scaling and rotation.*/
	void setPivot(const Float3ID& pvt){fprintf_s(mFile,"connectAttr \"");pvt.write(mFile);fprintf_s(mFile,"\" \"%s.pvt\";\n",mName.c_str());}
	/*Pivot X coord.*/
	void setPivotX(float pvx){if(pvx == 0) return; fprintf_s(mFile, "setAttr \".pvt.pvx\" %f;\n", pvx);}
	/*Pivot X coord.*/
	void setPivotX(const FloatID& pvx){fprintf_s(mFile,"connectAttr \"");pvx.write(mFile);fprintf_s(mFile,"\" \"%s.pvt.pvx\";\n",mName.c_str());}
	/*Pivot Y coord.*/
	void setPivotY(float pvy){if(pvy == 0) return; fprintf_s(mFile, "setAttr \".pvt.pvy\" %f;\n", pvy);}
	/*Pivot Y coord.*/
	void setPivotY(const FloatID& pvy){fprintf_s(mFile,"connectAttr \"");pvy.write(mFile);fprintf_s(mFile,"\" \"%s.pvt.pvy\";\n",mName.c_str());}
	/*Pivot Z coord.*/
	void setPivotZ(float pvz){if(pvz == 0) return; fprintf_s(mFile, "setAttr \".pvt.pvz\" %f;\n", pvz);}
	/*Pivot Z coord.*/
	void setPivotZ(const FloatID& pvz){fprintf_s(mFile,"connectAttr \"");pvz.write(mFile);fprintf_s(mFile,"\" \"%s.pvt.pvz\";\n",mName.c_str());}
	/*Random value for all parameters.*/
	void setRandom(float ran){if(ran == 0.0) return; fprintf_s(mFile, "setAttr \".ran\" %f;\n", ran);}
	/*Random value for all parameters.*/
	void setRandom(const FloatID& ran){fprintf_s(mFile,"connectAttr \"");ran.write(mFile);fprintf_s(mFile,"\" \"%s.ran\";\n",mName.c_str());}
	/*Random seed for this node. Computed automatically.*/
	void setRandomSeed(int rs){if(rs == 0) return; fprintf_s(mFile, "setAttr \".rs\" %i;\n", rs);}
	/*Random seed for this node. Computed automatically.*/
	void setRandomSeed(const IntID& rs){fprintf_s(mFile,"connectAttr \"");rs.write(mFile);fprintf_s(mFile,"\" \"%s.rs\";\n",mName.c_str());}
	/*Local translate.*/
	void setLocalTranslate(const double3& lt){if(lt == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".lt\" -type \"double3\" ");lt.write(mFile);fprintf_s(mFile,";\n");}
	/*Local translate.*/
	void setLocalTranslate(const Double3ID& lt){fprintf_s(mFile,"connectAttr \"");lt.write(mFile);fprintf_s(mFile,"\" \"%s.lt\";\n",mName.c_str());}
	/*Local translation X coord.*/
	void setLocalTranslateX(double ltx){if(ltx == 0) return; fprintf_s(mFile, "setAttr \".lt.ltx\" %f;\n", ltx);}
	/*Local translation X coord.*/
	void setLocalTranslateX(const DoubleID& ltx){fprintf_s(mFile,"connectAttr \"");ltx.write(mFile);fprintf_s(mFile,"\" \"%s.lt.ltx\";\n",mName.c_str());}
	/*Local translation Y coord.*/
	void setLocalTranslateY(double lty){if(lty == 0) return; fprintf_s(mFile, "setAttr \".lt.lty\" %f;\n", lty);}
	/*Local translation Y coord.*/
	void setLocalTranslateY(const DoubleID& lty){fprintf_s(mFile,"connectAttr \"");lty.write(mFile);fprintf_s(mFile,"\" \"%s.lt.lty\";\n",mName.c_str());}
	/*Local translation Z coord : Move along the normal.*/
	void setLocalTranslateZ(double ltz){if(ltz == 0) return; fprintf_s(mFile, "setAttr \".lt.ltz\" %f;\n", ltz);}
	/*Local translation Z coord : Move along the normal.*/
	void setLocalTranslateZ(const DoubleID& ltz){fprintf_s(mFile,"connectAttr \"");ltz.write(mFile);fprintf_s(mFile,"\" \"%s.lt.ltz\";\n",mName.c_str());}
	/*Direction to determine X axis for local space.*/
	void setLocalDirection(const double3& ld){if(ld == double3(1.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ld\" -type \"double3\" ");ld.write(mFile);fprintf_s(mFile,";\n");}
	/*Direction to determine X axis for local space.*/
	void setLocalDirection(const Double3ID& ld){fprintf_s(mFile,"connectAttr \"");ld.write(mFile);fprintf_s(mFile,"\" \"%s.ld\";\n",mName.c_str());}
	/*X coord of the X axis.*/
	void setLocalDirectionX(double ldx){if(ldx == 0) return; fprintf_s(mFile, "setAttr \".ld.ldx\" %f;\n", ldx);}
	/*X coord of the X axis.*/
	void setLocalDirectionX(const DoubleID& ldx){fprintf_s(mFile,"connectAttr \"");ldx.write(mFile);fprintf_s(mFile,"\" \"%s.ld.ldx\";\n",mName.c_str());}
	/*Y coord of the X axis.*/
	void setLocalDirectionY(double ldy){if(ldy == 0) return; fprintf_s(mFile, "setAttr \".ld.ldy\" %f;\n", ldy);}
	/*Y coord of the X axis.*/
	void setLocalDirectionY(const DoubleID& ldy){fprintf_s(mFile,"connectAttr \"");ldy.write(mFile);fprintf_s(mFile,"\" \"%s.ld.ldy\";\n",mName.c_str());}
	/*Z coord of the X axis.*/
	void setLocalDirectionZ(double ldz){if(ldz == 0) return; fprintf_s(mFile, "setAttr \".ld.ldz\" %f;\n", ldz);}
	/*Z coord of the X axis.*/
	void setLocalDirectionZ(const DoubleID& ldz){fprintf_s(mFile,"connectAttr \"");ldz.write(mFile);fprintf_s(mFile,"\" \"%s.ld.ldz\";\n",mName.c_str());}
	/*Object to component matrix (for interaction purposes only).*/
	void setMatrix(const MatrixID& cma){fprintf_s(mFile,"connectAttr \"");cma.write(mFile);fprintf_s(mFile,"\" \"%s.cma\";\n",mName.c_str());}
	/*Identifies which component to place the manip on (for interaction purposes only).*/
	void setCompId(const IntID& cid){fprintf_s(mFile,"connectAttr \"");cid.write(mFile);fprintf_s(mFile,"\" \"%s.cid\";\n",mName.c_str());}
	/*Gain factor per component. Can be painted using Artisan.*/
	void setGain(size_t ga_i,float ga){if(ga == 1.0) return; fprintf_s(mFile, "setAttr \".ga[%i]\" %f;\n", ga_i,ga);}
	/*Gain factor per component. Can be painted using Artisan.*/
	void setGain(size_t ga_i,const FloatID& ga){fprintf_s(mFile,"connectAttr \"");ga.write(mFile);fprintf_s(mFile,"\" \"%s.ga[%i]\";\n",mName.c_str(),ga_i);}
	/*Translation vector.*/
	Double3ID getTranslate(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*Translation X coord.*/
	DoubleID getTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.t.tx",mName.c_str());return (const char*)buffer;}
	/*Translation Y coord.*/
	DoubleID getTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.t.ty",mName.c_str());return (const char*)buffer;}
	/*Translation Z coord.*/
	DoubleID getTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.t.tz",mName.c_str());return (const char*)buffer;}
	/*Rotation angles around X, Y, Z.*/
	Double3ID getRotate(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*Rotation angle around X.*/
	DoubleID getRotateX(){char buffer[4096];sprintf_s (buffer, "%s.ro.rx",mName.c_str());return (const char*)buffer;}
	/*Rotation angle around Y.*/
	DoubleID getRotateY(){char buffer[4096];sprintf_s (buffer, "%s.ro.ry",mName.c_str());return (const char*)buffer;}
	/*Rotation angle around Z.*/
	DoubleID getRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.ro.rz",mName.c_str());return (const char*)buffer;}
	/*Scaling vector.*/
	Double3ID getScale(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Scale X coord.*/
	DoubleID getScaleX(){char buffer[4096];sprintf_s (buffer, "%s.s.sx",mName.c_str());return (const char*)buffer;}
	/*Scale Y coord.*/
	DoubleID getScaleY(){char buffer[4096];sprintf_s (buffer, "%s.s.sy",mName.c_str());return (const char*)buffer;}
	/*Scale Z coord.*/
	DoubleID getScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.s.sz",mName.c_str());return (const char*)buffer;}
	/*The pivot for scaling and rotation.*/
	Float3ID getPivot(){char buffer[4096];sprintf_s (buffer, "%s.pvt",mName.c_str());return (const char*)buffer;}
	/*Pivot X coord.*/
	FloatID getPivotX(){char buffer[4096];sprintf_s (buffer, "%s.pvt.pvx",mName.c_str());return (const char*)buffer;}
	/*Pivot Y coord.*/
	FloatID getPivotY(){char buffer[4096];sprintf_s (buffer, "%s.pvt.pvy",mName.c_str());return (const char*)buffer;}
	/*Pivot Z coord.*/
	FloatID getPivotZ(){char buffer[4096];sprintf_s (buffer, "%s.pvt.pvz",mName.c_str());return (const char*)buffer;}
	/*Random value for all parameters.*/
	FloatID getRandom(){char buffer[4096];sprintf_s (buffer, "%s.ran",mName.c_str());return (const char*)buffer;}
	/*Random seed for this node. Computed automatically.*/
	IntID getRandomSeed(){char buffer[4096];sprintf_s (buffer, "%s.rs",mName.c_str());return (const char*)buffer;}
	/*Local translate.*/
	Double3ID getLocalTranslate(){char buffer[4096];sprintf_s (buffer, "%s.lt",mName.c_str());return (const char*)buffer;}
	/*Local translation X coord.*/
	DoubleID getLocalTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.lt.ltx",mName.c_str());return (const char*)buffer;}
	/*Local translation Y coord.*/
	DoubleID getLocalTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.lt.lty",mName.c_str());return (const char*)buffer;}
	/*Local translation Z coord : Move along the normal.*/
	DoubleID getLocalTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.lt.ltz",mName.c_str());return (const char*)buffer;}
	/*Direction to determine X axis for local space.*/
	Double3ID getLocalDirection(){char buffer[4096];sprintf_s (buffer, "%s.ld",mName.c_str());return (const char*)buffer;}
	/*X coord of the X axis.*/
	DoubleID getLocalDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.ld.ldx",mName.c_str());return (const char*)buffer;}
	/*Y coord of the X axis.*/
	DoubleID getLocalDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.ld.ldy",mName.c_str());return (const char*)buffer;}
	/*Z coord of the X axis.*/
	DoubleID getLocalDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.ld.ldz",mName.c_str());return (const char*)buffer;}
	/*Object to component matrix (for interaction purposes only).*/
	MatrixID getMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cma",mName.c_str());return (const char*)buffer;}
	/*Identifies which component to place the manip on (for interaction purposes only).*/
	IntID getCompId(){char buffer[4096];sprintf_s (buffer, "%s.cid",mName.c_str());return (const char*)buffer;}
	/*Gain factor per component. Can be painted using Artisan.*/
	const FloatID& getGain(size_t ga_i){char buffer[4096];sprintf_s (buffer, "%s.ga[%i]",mName.c_str(),ga_i);return (const char*)buffer;}
protected:
	PolyMoveVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEVERTEX_H__
