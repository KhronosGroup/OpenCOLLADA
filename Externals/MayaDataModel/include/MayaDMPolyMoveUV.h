/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class PolyMoveUV : public PolyModifier
{
public:
public:
	PolyMoveUV():PolyModifier(){}
	PolyMoveUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyMoveUV"){}
	virtual ~PolyMoveUV(){}
	void setTranslate(const double2& t)
	{
		if(t == double2(0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".t\" -type \"double2\" ");
		t.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTranslateU(double tu)
	{
		if(tu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".t.tu\" %f;\n", tu);

	}
	void setTranslateV(double tv)
	{
		if(tv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".t.tv\" %f;\n", tv);

	}
	void setRotationAngle(double ra)
	{
		if(ra == 0) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);

	}
	void setPivot(const double2& pvt)
	{
		if(pvt == double2(0.5, 0.5)) return;
		fprintf(mFile,"\tsetAttr \".pvt\" -type \"double2\" ");
		pvt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPivotU(double pvu)
	{
		if(pvu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pvt.pvu\" %f;\n", pvu);

	}
	void setPivotV(double pvv)
	{
		if(pvv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pvt.pvv\" %f;\n", pvv);

	}
	void setScale(const double2& s)
	{
		if(s == double2(1.0, 1.0)) return;
		fprintf(mFile,"\tsetAttr \".s\" -type \"double2\" ");
		s.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScaleU(double su)
	{
		if(su == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s.su\" %f;\n", su);

	}
	void setScaleV(double sv)
	{
		if(sv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s.sv\" %f;\n", sv);

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
	void setAxisLen(const double2& l)
	{
		if(l == double2(1.0, 1.0)) return;
		fprintf(mFile,"\tsetAttr \".l\" -type \"double2\" ");
		l.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAxisLenX(double lx)
	{
		if(lx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".l.lx\" %f;\n", lx);

	}
	void setAxisLenY(double ly)
	{
		if(ly == 0.0) return;
		fprintf(mFile,"\tsetAttr \".l.ly\" %f;\n", ly);

	}
	void setUvSetName(const string& uvs)
	{
		if(uvs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".uvs\" -type \"string\" ");
		uvs.write(mFile);
		fprintf(mFile,";\n");

	}
	void getTranslate()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getTranslateU()
	{
		fprintf(mFile,"\"%s.t.tu\"",mName.c_str());

	}
	void getTranslateV()
	{
		fprintf(mFile,"\"%s.t.tv\"",mName.c_str());

	}
	void getRotationAngle()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
	void getPivot()
	{
		fprintf(mFile,"\"%s.pvt\"",mName.c_str());

	}
	void getPivotU()
	{
		fprintf(mFile,"\"%s.pvt.pvu\"",mName.c_str());

	}
	void getPivotV()
	{
		fprintf(mFile,"\"%s.pvt.pvv\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getScaleU()
	{
		fprintf(mFile,"\"%s.s.su\"",mName.c_str());

	}
	void getScaleV()
	{
		fprintf(mFile,"\"%s.s.sv\"",mName.c_str());

	}
	void getRandom()
	{
		fprintf(mFile,"\"%s.ran\"",mName.c_str());

	}
	void getRandomSeed()
	{
		fprintf(mFile,"\"%s.rs\"",mName.c_str());

	}
	void getAxisLen()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getAxisLenX()
	{
		fprintf(mFile,"\"%s.l.lx\"",mName.c_str());

	}
	void getAxisLenY()
	{
		fprintf(mFile,"\"%s.l.ly\"",mName.c_str());

	}
	void getCompId()
	{
		fprintf(mFile,"\"%s.cid\"",mName.c_str());

	}
	void getUvSetName()
	{
		fprintf(mFile,"\"%s.uvs\"",mName.c_str());

	}
protected:
	PolyMoveUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEUV_H__
