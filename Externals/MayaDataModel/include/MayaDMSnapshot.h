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
	Snapshot(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "snapshot"){}
	virtual ~Snapshot(){}
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
	void getStartTime()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getEndTime()
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());

	}
	void getIncrement()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getInputGeom()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getOutputGeom(size_t out_i)
	{
		fprintf(mFile,"\"%s.out[%i]\"",mName.c_str(),out_i);

	}
	void getInputMatrix()
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());

	}
	void getLocalPosition()
	{
		fprintf(mFile,"\"%s.lp\"",mName.c_str());

	}
	void getLocalPositionX()
	{
		fprintf(mFile,"\"%s.lp.lpx\"",mName.c_str());

	}
	void getLocalPositionY()
	{
		fprintf(mFile,"\"%s.lp.lpy\"",mName.c_str());

	}
	void getLocalPositionZ()
	{
		fprintf(mFile,"\"%s.lp.lpz\"",mName.c_str());

	}
	void getPoints()
	{
		fprintf(mFile,"\"%s.pts\"",mName.c_str());

	}
	void getFrames()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getAnimCurveChanged()
	{
		fprintf(mFile,"\"%s.acc\"",mName.c_str());

	}
	void getUpdate()
	{
		fprintf(mFile,"\"%s.up\"",mName.c_str());

	}
protected:
	Snapshot(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SNAPSHOT_H__
