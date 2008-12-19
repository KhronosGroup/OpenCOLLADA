/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYBEVEL_H__
#define __MayaDM_POLYBEVEL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyBevel : public PolyModifierWorld
{
public:
public:
	PolyBevel(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyBevel"){}
	virtual ~PolyBevel(){}
	void setOffsetAsFraction(bool oaf)
	{
		if(oaf == false) return;
		fprintf(mFile,"setAttr \".oaf\" %i;\n", oaf);

	}
	void setOffset(double o)
	{
		if(o == 0) return;
		fprintf(mFile,"setAttr \".o\" %f;\n", o);

	}
	void setRoundness(double r)
	{
		if(r == 0.5) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setSegments(int sg)
	{
		if(sg == 1) return;
		fprintf(mFile,"setAttr \".sg\" %i;\n", sg);

	}
	void setAutoFit(bool af)
	{
		if(af == true) return;
		fprintf(mFile,"setAttr \".af\" %i;\n", af);

	}
	void setAngleTolerance(double at)
	{
		if(at == 20.0) return;
		fprintf(mFile,"setAttr \".at\" %f;\n", at);

	}
	void setFillNgons(bool fn)
	{
		if(fn == false) return;
		fprintf(mFile,"setAttr \".fn\" %i;\n", fn);

	}
	void setUvAssignment(unsigned int ua)
	{
		if(ua == 0) return;
		fprintf(mFile,"setAttr \".ua\" %i;\n", ua);

	}
	void setMergeVertices(bool mv)
	{
		if(mv == false) return;
		fprintf(mFile,"setAttr \".mv\" %i;\n", mv);

	}
	void setMergeVertexTolerance(double mvt)
	{
		if(mvt == 0) return;
		fprintf(mFile,"setAttr \".mvt\" %f;\n", mvt);

	}
	void setSmoothingAngle(double sa)
	{
		if(sa == 0.0) return;
		fprintf(mFile,"setAttr \".sa\" %f;\n", sa);

	}
	void setMiteringAngle(double ma)
	{
		if(ma == 0.0) return;
		fprintf(mFile,"setAttr \".ma\" %f;\n", ma);

	}
	void getOffsetAsFraction()
	{
		fprintf(mFile,"\"%s.oaf\"",mName.c_str());

	}
	void getOffset()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getRoundness()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getSegments()
	{
		fprintf(mFile,"\"%s.sg\"",mName.c_str());

	}
	void getAutoFit()
	{
		fprintf(mFile,"\"%s.af\"",mName.c_str());

	}
	void getAngleTolerance()
	{
		fprintf(mFile,"\"%s.at\"",mName.c_str());

	}
	void getFillNgons()
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());

	}
	void getUvAssignment()
	{
		fprintf(mFile,"\"%s.ua\"",mName.c_str());

	}
	void getMergeVertices()
	{
		fprintf(mFile,"\"%s.mv\"",mName.c_str());

	}
	void getMergeVertexTolerance()
	{
		fprintf(mFile,"\"%s.mvt\"",mName.c_str());

	}
	void getSmoothingAngle()
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());

	}
	void getMiteringAngle()
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());

	}
protected:
	PolyBevel(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYBEVEL_H__
