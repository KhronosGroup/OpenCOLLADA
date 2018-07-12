/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LOCATOR_H__
#define __MayaDM_LOCATOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
class Locator : public GeometryShape
{
public:
public:

	Locator():GeometryShape(){}
	Locator(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, "locator", shared, create){}
	virtual ~Locator(){}

	void setUnderWorldObject(bool uwo)
	{
		if(uwo == false) return;
		fprintf(mFile,"\tsetAttr \".uwo\" %i;\n", uwo);
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
	void setLocalScale(const double3& los)
	{
		if(los == double3(1.0, 1.0, 1.0)) return;
		fprintf(mFile,"\tsetAttr \".los\" -type \"double3\" ");
		los.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocalScaleX(double lsx)
	{
		if(lsx == 1) return;
		fprintf(mFile,"\tsetAttr \".los.lsx\" %f;\n", lsx);
	}
	void setLocalScaleY(double lsy)
	{
		if(lsy == 1) return;
		fprintf(mFile,"\tsetAttr \".los.lsy\" %f;\n", lsy);
	}
	void setLocalScaleZ(double lsz)
	{
		if(lsz == 1) return;
		fprintf(mFile,"\tsetAttr \".los.lsz\" %f;\n", lsz);
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
	void getWorldPosition(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i]\"",mName.c_str(),wp_i);
	}
	void getWorldPosition()const
	{

		fprintf(mFile,"\"%s.wp\"",mName.c_str());
	}
	void getWorldPositionX(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpx\"",mName.c_str(),wp_i);
	}
	void getWorldPositionX()const
	{

		fprintf(mFile,"\"%s.wp.wpx\"",mName.c_str());
	}
	void getWorldPositionY(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpy\"",mName.c_str(),wp_i);
	}
	void getWorldPositionY()const
	{

		fprintf(mFile,"\"%s.wp.wpy\"",mName.c_str());
	}
	void getWorldPositionZ(size_t wp_i)const
	{
		fprintf(mFile,"\"%s.wp[%i].wpz\"",mName.c_str(),wp_i);
	}
	void getWorldPositionZ()const
	{

		fprintf(mFile,"\"%s.wp.wpz\"",mName.c_str());
	}
	void getLocalScale()const
	{
		fprintf(mFile,"\"%s.los\"",mName.c_str());
	}
	void getLocalScaleX()const
	{
		fprintf(mFile,"\"%s.los.lsx\"",mName.c_str());
	}
	void getLocalScaleY()const
	{
		fprintf(mFile,"\"%s.los.lsy\"",mName.c_str());
	}
	void getLocalScaleZ()const
	{
		fprintf(mFile,"\"%s.los.lsz\"",mName.c_str());
	}
protected:
	Locator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LOCATOR_H__
