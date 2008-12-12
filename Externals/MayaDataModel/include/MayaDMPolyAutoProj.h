/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYAUTOPROJ_H__
#define __MayaDM_POLYAUTOPROJ_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
/*
<p><pre> Projects a map onto an object, using several orthogonal projections simultaneously.
</pre></p>
*/
class PolyAutoProj : public PolyModifierUV
{
public:
public:
	PolyAutoProj(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyAutoProj"){}
	virtual ~PolyAutoProj(){}
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
	/*How many projections. Valid values are 3, 4, 5, 6, 8, 12. This value is only used if no polygonal object is connected to the polyGeomObject attribute.*/
	void setPlanes(int p){if(p == 6) return; fprintf_s(mFile, "setAttr \".p\" %i;\n", p);}
	/*How many projections. Valid values are 3, 4, 5, 6, 8, 12. This value is only used if no polygonal object is connected to the polyGeomObject attribute.*/
	void setPlanes(const IntID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*Either fewer pieces, or more equaly distributed*/
	void setOptimize(unsigned int o){if(o == 1) return; fprintf_s(mFile, "setAttr \".o\" %i;\n", o);}
	/*Either fewer pieces, or more equaly distributed*/
	void setOptimize(const UnsignedintID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*How to rotate the pieces, before move.*/
	void setLayoutMethod(unsigned int lm){if(lm == 0) return; fprintf_s(mFile, "setAttr \".lm\" %i;\n", lm);}
	/*How to rotate the pieces, before move.*/
	void setLayoutMethod(const UnsignedintID& lm){fprintf_s(mFile,"connectAttr \"");lm.write(mFile);fprintf_s(mFile,"\" \"%s.lm\";\n",mName.c_str());}
	/*Do not check for auto intersections.*/
	void setSkipIntersect(bool si){if(si == false) return; fprintf_s(mFile, "setAttr \".si\" %i;\n", si);}
	/*Do not check for auto intersections.*/
	void setSkipIntersect(const BoolID& si){fprintf_s(mFile,"connectAttr \"");si.write(mFile);fprintf_s(mFile,"\" \"%s.si\";\n",mName.c_str());}
	/*How to move the pieces.*/
	void setLayout(unsigned int l){if(l == 2) return; fprintf_s(mFile, "setAttr \".l\" %i;\n", l);}
	/*How to move the pieces.*/
	void setLayout(const UnsignedintID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	Extra space between UV pieces. Only used when moving
	pieces to a square. This is a percentage of the texture space.
	*/
	void setPercentageSpace(float ps){if(ps == 0) return; fprintf_s(mFile, "setAttr \".ps\" %f;\n", ps);}
	/*
	Extra space between UV pieces. Only used when moving
	pieces to a square. This is a percentage of the texture space.
	*/
	void setPercentageSpace(const FloatID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*Scaling mode after UVs have been moved*/
	void setScaleMode(unsigned int sc){if(sc == 1) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*Scaling mode after UVs have been moved*/
	void setScaleMode(const UnsignedintID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*
	Optimize packing to reduce unused texture area. Hiden
	attribute for pre 3.0.1 file format compatibility
	*/
	void setDenseLayout(bool dl){if(dl == false) return; fprintf_s(mFile, "setAttr \".dl\" %i;\n", dl);}
	/*
	Optimize packing to reduce unused texture area. Hiden
	attribute for pre 3.0.1 file format compatibility
	*/
	void setDenseLayout(const BoolID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*Only used when a used defined projection object is set, using the polyGeomObject attribute. When turned on, each projection direction will project faces facing both towards the projection direction and opposite to it.*/
	void setProjectBothDirections(bool pb){if(pb == false) return; fprintf_s(mFile, "setAttr \".pb\" %i;\n", pb);}
	/*Only used when a used defined projection object is set, using the polyGeomObject attribute. When turned on, each projection direction will project faces facing both towards the projection direction and opposite to it.*/
	void setProjectBothDirections(const BoolID& pb){fprintf_s(mFile,"connectAttr \"");pb.write(mFile);fprintf_s(mFile,"\" \"%s.pb\";\n",mName.c_str());}
	/*Arbitrary polyGeom Geometry to use for projections. Only up to 30 planes can be used. Each face of the object defines a projection along its normal. The positionning in texture space is defined usig the UV coordinates of the input object.*/
	void setPolyGeomObject(const GeometryID& pg){fprintf_s(mFile,"connectAttr \"");pg.write(mFile);fprintf_s(mFile,"\" \"%s.pg\";\n",mName.c_str());}
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
	/*How many projections. Valid values are 3, 4, 5, 6, 8, 12. This value is only used if no polygonal object is connected to the polyGeomObject attribute.*/
	IntID getPlanes(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*Either fewer pieces, or more equaly distributed*/
	UnsignedintID getOptimize(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*How to rotate the pieces, before move.*/
	UnsignedintID getLayoutMethod(){char buffer[4096];sprintf_s (buffer, "%s.lm",mName.c_str());return (const char*)buffer;}
	/*Do not check for auto intersections.*/
	BoolID getSkipIntersect(){char buffer[4096];sprintf_s (buffer, "%s.si",mName.c_str());return (const char*)buffer;}
	/*How to move the pieces.*/
	UnsignedintID getLayout(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	Extra space between UV pieces. Only used when moving
	pieces to a square. This is a percentage of the texture space.
	*/
	FloatID getPercentageSpace(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*Scaling mode after UVs have been moved*/
	UnsignedintID getScaleMode(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	Optimize packing to reduce unused texture area. Hiden
	attribute for pre 3.0.1 file format compatibility
	*/
	BoolID getDenseLayout(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*Only used when a used defined projection object is set, using the polyGeomObject attribute. When turned on, each projection direction will project faces facing both towards the projection direction and opposite to it.*/
	BoolID getProjectBothDirections(){char buffer[4096];sprintf_s (buffer, "%s.pb",mName.c_str());return (const char*)buffer;}
	/*Arbitrary polyGeom Geometry to use for projections. Only up to 30 planes can be used. Each face of the object defines a projection along its normal. The positionning in texture space is defined usig the UV coordinates of the input object.*/
	GeometryID getPolyGeomObject(){char buffer[4096];sprintf_s (buffer, "%s.pg",mName.c_str());return (const char*)buffer;}
protected:
	PolyAutoProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYAUTOPROJ_H__
