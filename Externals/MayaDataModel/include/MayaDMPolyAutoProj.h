/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class PolyAutoProj : public PolyModifierUV
{
public:
public:
	PolyAutoProj():PolyModifierUV(){}
	PolyAutoProj(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyAutoProj"){}
	virtual ~PolyAutoProj(){}
	void setTranslate(const double3& t)
	{
		if(t == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".t\" -type \"double3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTranslateX(double tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"\tsetAttr \".t.tx\" %f;\n", tx);

	}
	void setTranslateY(double ty)
	{
		if(ty == 0) return;
		fprintf(mFile,"\tsetAttr \".t.ty\" %f;\n", ty);

	}
	void setTranslateZ(double tz)
	{
		if(tz == 0) return;
		fprintf(mFile,"\tsetAttr \".t.tz\" %f;\n", tz);

	}
	void setRotate(const double3& ro)
	{
		if(ro == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".ro\" -type \"double3\" ");
		ro.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRotateX(double rx)
	{
		if(rx == 0) return;
		fprintf(mFile,"\tsetAttr \".ro.rx\" %f;\n", rx);

	}
	void setRotateY(double ry)
	{
		if(ry == 0) return;
		fprintf(mFile,"\tsetAttr \".ro.ry\" %f;\n", ry);

	}
	void setRotateZ(double rz)
	{
		if(rz == 0) return;
		fprintf(mFile,"\tsetAttr \".ro.rz\" %f;\n", rz);

	}
	void setScale(const double3& s)
	{
		if(s == double3(1.0, 1.0, 1.0)) return;
		fprintf(mFile,"\tsetAttr \".s\" -type \"double3\" ");
		s.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScaleX(double sx)
	{
		if(sx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s.sx\" %f;\n", sx);

	}
	void setScaleY(double sy)
	{
		if(sy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s.sy\" %f;\n", sy);

	}
	void setScaleZ(double sz)
	{
		if(sz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s.sz\" %f;\n", sz);

	}
	void setPivot(const float3& pvt)
	{
		if(pvt == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".pvt\" -type \"float3\" ");
		pvt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPivotX(float pvx)
	{
		if(pvx == 0) return;
		fprintf(mFile,"\tsetAttr \".pvt.pvx\" %f;\n", pvx);

	}
	void setPivotY(float pvy)
	{
		if(pvy == 0) return;
		fprintf(mFile,"\tsetAttr \".pvt.pvy\" %f;\n", pvy);

	}
	void setPivotZ(float pvz)
	{
		if(pvz == 0) return;
		fprintf(mFile,"\tsetAttr \".pvt.pvz\" %f;\n", pvz);

	}
	void setPlanes(int p)
	{
		if(p == 6) return;
		fprintf(mFile,"\tsetAttr \".p\" %i;\n", p);

	}
	void setOptimize(unsigned int o)
	{
		if(o == 1) return;
		fprintf(mFile,"\tsetAttr \".o\" %i;\n", o);

	}
	void setLayoutMethod(unsigned int lm)
	{
		if(lm == 0) return;
		fprintf(mFile,"\tsetAttr \".lm\" %i;\n", lm);

	}
	void setSkipIntersect(bool si)
	{
		if(si == false) return;
		fprintf(mFile,"\tsetAttr \".si\" %i;\n", si);

	}
	void setLayout(unsigned int l)
	{
		if(l == 2) return;
		fprintf(mFile,"\tsetAttr \".l\" %i;\n", l);

	}
	void setPercentageSpace(float ps)
	{
		if(ps == 0) return;
		fprintf(mFile,"\tsetAttr \".ps\" %f;\n", ps);

	}
	void setScaleMode(unsigned int sc)
	{
		if(sc == 1) return;
		fprintf(mFile,"\tsetAttr \".sc\" %i;\n", sc);

	}
	void setDenseLayout(bool dl)
	{
		if(dl == false) return;
		fprintf(mFile,"\tsetAttr \".dl\" %i;\n", dl);

	}
	void setProjectBothDirections(bool pb)
	{
		if(pb == false) return;
		fprintf(mFile,"\tsetAttr \".pb\" %i;\n", pb);

	}
	void getTranslate()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getTranslateX()
	{
		fprintf(mFile,"\"%s.t.tx\"",mName.c_str());

	}
	void getTranslateY()
	{
		fprintf(mFile,"\"%s.t.ty\"",mName.c_str());

	}
	void getTranslateZ()
	{
		fprintf(mFile,"\"%s.t.tz\"",mName.c_str());

	}
	void getRotate()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getRotateX()
	{
		fprintf(mFile,"\"%s.ro.rx\"",mName.c_str());

	}
	void getRotateY()
	{
		fprintf(mFile,"\"%s.ro.ry\"",mName.c_str());

	}
	void getRotateZ()
	{
		fprintf(mFile,"\"%s.ro.rz\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getScaleX()
	{
		fprintf(mFile,"\"%s.s.sx\"",mName.c_str());

	}
	void getScaleY()
	{
		fprintf(mFile,"\"%s.s.sy\"",mName.c_str());

	}
	void getScaleZ()
	{
		fprintf(mFile,"\"%s.s.sz\"",mName.c_str());

	}
	void getPivot()
	{
		fprintf(mFile,"\"%s.pvt\"",mName.c_str());

	}
	void getPivotX()
	{
		fprintf(mFile,"\"%s.pvt.pvx\"",mName.c_str());

	}
	void getPivotY()
	{
		fprintf(mFile,"\"%s.pvt.pvy\"",mName.c_str());

	}
	void getPivotZ()
	{
		fprintf(mFile,"\"%s.pvt.pvz\"",mName.c_str());

	}
	void getPlanes()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getOptimize()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getLayoutMethod()
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());

	}
	void getSkipIntersect()
	{
		fprintf(mFile,"\"%s.si\"",mName.c_str());

	}
	void getLayout()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getPercentageSpace()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
	void getScaleMode()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getDenseLayout()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
	void getProjectBothDirections()
	{
		fprintf(mFile,"\"%s.pb\"",mName.c_str());

	}
	void getPolyGeomObject()
	{
		fprintf(mFile,"\"%s.pg\"",mName.c_str());

	}
protected:
	PolyAutoProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:PolyModifierUV(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYAUTOPROJ_H__
