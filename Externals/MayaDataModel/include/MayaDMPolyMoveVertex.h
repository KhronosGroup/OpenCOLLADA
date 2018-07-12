/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class PolyMoveVertex : public PolyModifierWorld
{
public:
public:

	PolyMoveVertex():PolyModifierWorld(){}
	PolyMoveVertex(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyMoveVertex", shared, create){}
	virtual ~PolyMoveVertex(){}

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
	void setRandom(float ran)
	{
		if(ran == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ran\" %f;\n", ran);
	}
	void setRandomSeed(int rs)
	{
		if(rs == 0) return;
		fprintf(mFile,"\tsetAttr \".rs\" %i;\n", rs);
	}
	void setLocalTranslate(const double3& lt)
	{
		if(lt == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".lt\" -type \"double3\" ");
		lt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocalTranslateX(double ltx)
	{
		if(ltx == 0) return;
		fprintf(mFile,"\tsetAttr \".lt.ltx\" %f;\n", ltx);
	}
	void setLocalTranslateY(double lty)
	{
		if(lty == 0) return;
		fprintf(mFile,"\tsetAttr \".lt.lty\" %f;\n", lty);
	}
	void setLocalTranslateZ(double ltz)
	{
		if(ltz == 0) return;
		fprintf(mFile,"\tsetAttr \".lt.ltz\" %f;\n", ltz);
	}
	void setLocalDirection(const double3& ld)
	{
		if(ld == double3(1.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".ld\" -type \"double3\" ");
		ld.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocalDirectionX(double ldx)
	{
		if(ldx == 0) return;
		fprintf(mFile,"\tsetAttr \".ld.ldx\" %f;\n", ldx);
	}
	void setLocalDirectionY(double ldy)
	{
		if(ldy == 0) return;
		fprintf(mFile,"\tsetAttr \".ld.ldy\" %f;\n", ldy);
	}
	void setLocalDirectionZ(double ldz)
	{
		if(ldz == 0) return;
		fprintf(mFile,"\tsetAttr \".ld.ldz\" %f;\n", ldz);
	}
	void setGain(size_t ga_i,float ga)
	{
		if(ga == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ga[%i]\" %f;\n", ga_i,ga);
	}
	void setGain(size_t ga_start,size_t ga_end,float* ga)
	{
		fprintf(mFile,"\tsetAttr \".ga[%i:%i]\" ", ga_start,ga_end);
		size_t size = (ga_end-ga_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",ga[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startGain(size_t ga_start,size_t ga_end)const
	{
		fprintf(mFile,"\tsetAttr \".ga[%i:%i]\"",ga_start,ga_end);
	}
	void appendGain(float ga)const
	{
		fprintf(mFile," %f",ga);
	}
	void endGain()const
	{
		fprintf(mFile,";\n");
	}
	void getTranslate()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getTranslateX()const
	{
		fprintf(mFile,"\"%s.t.tx\"",mName.c_str());
	}
	void getTranslateY()const
	{
		fprintf(mFile,"\"%s.t.ty\"",mName.c_str());
	}
	void getTranslateZ()const
	{
		fprintf(mFile,"\"%s.t.tz\"",mName.c_str());
	}
	void getRotate()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());
	}
	void getRotateX()const
	{
		fprintf(mFile,"\"%s.ro.rx\"",mName.c_str());
	}
	void getRotateY()const
	{
		fprintf(mFile,"\"%s.ro.ry\"",mName.c_str());
	}
	void getRotateZ()const
	{
		fprintf(mFile,"\"%s.ro.rz\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getScaleX()const
	{
		fprintf(mFile,"\"%s.s.sx\"",mName.c_str());
	}
	void getScaleY()const
	{
		fprintf(mFile,"\"%s.s.sy\"",mName.c_str());
	}
	void getScaleZ()const
	{
		fprintf(mFile,"\"%s.s.sz\"",mName.c_str());
	}
	void getPivot()const
	{
		fprintf(mFile,"\"%s.pvt\"",mName.c_str());
	}
	void getPivotX()const
	{
		fprintf(mFile,"\"%s.pvt.pvx\"",mName.c_str());
	}
	void getPivotY()const
	{
		fprintf(mFile,"\"%s.pvt.pvy\"",mName.c_str());
	}
	void getPivotZ()const
	{
		fprintf(mFile,"\"%s.pvt.pvz\"",mName.c_str());
	}
	void getRandom()const
	{
		fprintf(mFile,"\"%s.ran\"",mName.c_str());
	}
	void getRandomSeed()const
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());
	}
	void getLocalTranslate()const
	{
		fprintf(mFile,"\"%s.lt\"",mName.c_str());
	}
	void getLocalTranslateX()const
	{
		fprintf(mFile,"\"%s.lt.ltx\"",mName.c_str());
	}
	void getLocalTranslateY()const
	{
		fprintf(mFile,"\"%s.lt.lty\"",mName.c_str());
	}
	void getLocalTranslateZ()const
	{
		fprintf(mFile,"\"%s.lt.ltz\"",mName.c_str());
	}
	void getLocalDirection()const
	{
		fprintf(mFile,"\"%s.ld\"",mName.c_str());
	}
	void getLocalDirectionX()const
	{
		fprintf(mFile,"\"%s.ld.ldx\"",mName.c_str());
	}
	void getLocalDirectionY()const
	{
		fprintf(mFile,"\"%s.ld.ldy\"",mName.c_str());
	}
	void getLocalDirectionZ()const
	{
		fprintf(mFile,"\"%s.ld.ldz\"",mName.c_str());
	}
	void getMatrix()const
	{
		fprintf(mFile,"\"%s.cma\"",mName.c_str());
	}
	void getCompId()const
	{
		fprintf(mFile,"\"%s.cid\"",mName.c_str());
	}
	void getGain(size_t ga_i)const
	{
		fprintf(mFile,"\"%s.ga[%i]\"",mName.c_str(),ga_i);
	}
	void getGain()const
	{

		fprintf(mFile,"\"%s.ga\"",mName.c_str());
	}
protected:
	PolyMoveVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEVERTEX_H__
