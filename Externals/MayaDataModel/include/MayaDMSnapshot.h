/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SNAPSHOT_H__
#define __MayaDM_SNAPSHOT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Snapshot : public DependNode
{
public:
public:

	Snapshot():DependNode(){}
	Snapshot(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "snapshot", shared, create){}
	virtual ~Snapshot(){}

	void setStartTime(double s)
	{
		if(s == 0) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void setEndTime(double e)
	{
		if(e == 0) return;
		fprintf(mFile,"\tsetAttr \".e\" %f;\n", e);
	}
	void setIncrement(double b)
	{
		if(b == 1) return;
		fprintf(mFile,"\tsetAttr \".b\" %f;\n", b);
	}
	void setInputMatrix(const matrix& im)
	{
		if(im == identity) return;
		fprintf(mFile,"\tsetAttr \".im\" -type \"matrix\" ");
		im.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocalPosition(const double3& lp)
	{
		if(lp == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".lp\" -type \"double3\" ");
		lp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocalPositionX(double lpx)
	{
		if(lpx == 0) return;
		fprintf(mFile,"\tsetAttr \".lp.lpx\" %f;\n", lpx);
	}
	void setLocalPositionY(double lpy)
	{
		if(lpy == 0) return;
		fprintf(mFile,"\tsetAttr \".lp.lpy\" %f;\n", lpy);
	}
	void setLocalPositionZ(double lpz)
	{
		if(lpz == 0) return;
		fprintf(mFile,"\tsetAttr \".lp.lpz\" %f;\n", lpz);
	}
	void setUpdate(unsigned int up)
	{
		if(up == 1) return;
		fprintf(mFile,"\tsetAttr \".up\" %i;\n", up);
	}
	void getStartTime()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getEndTime()const
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());
	}
	void getIncrement()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getInputGeom()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getOutputGeom(size_t out_i)const
	{
		fprintf(mFile,"\"%s.out[%i]\"",mName.c_str(),out_i);
	}
	void getOutputGeom()const
	{

		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
	void getInputMatrix()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getLocalPosition()const
	{
		fprintf(mFile,"\"%s.lp\"",mName.c_str());
	}
	void getLocalPositionX()const
	{
		fprintf(mFile,"\"%s.lp.lpx\"",mName.c_str());
	}
	void getLocalPositionY()const
	{
		fprintf(mFile,"\"%s.lp.lpy\"",mName.c_str());
	}
	void getLocalPositionZ()const
	{
		fprintf(mFile,"\"%s.lp.lpz\"",mName.c_str());
	}
	void getPoints()const
	{
		fprintf(mFile,"\"%s.pts\"",mName.c_str());
	}
	void getFrames()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getAnimCurveChanged()const
	{
		fprintf(mFile,"\"%s.acc\"",mName.c_str());
	}
	void getUpdate()const
	{
		fprintf(mFile,"\"%s.up\"",mName.c_str());
	}
protected:
	Snapshot(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SNAPSHOT_H__
