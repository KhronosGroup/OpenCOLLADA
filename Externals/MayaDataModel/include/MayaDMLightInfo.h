/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHTINFO_H__
#define __MayaDM_LIGHTINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class LightInfo : public DependNode
{
public:
public:

	LightInfo():DependNode(){}
	LightInfo(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "lightInfo", shared, create){}
	virtual ~LightInfo(){}

	void setLightDirectionOnly(bool ldo)
	{
		if(ldo == false) return;
		fprintf(mFile,"\tsetAttr \".ldo\" %i;\n", ldo);
	}
	void getMatrixEyeToWorld()const
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());
	}
	void getLightDirectionOnly()const
	{
		fprintf(mFile,"\"%s.ldo\"",mName.c_str());
	}
	void getWorldMatrix()const
	{
		fprintf(mFile,"\"%s.wm\"",mName.c_str());
	}
	void getPointCamera()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPointCameraX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPointCameraY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPointCameraZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getLightPosition()const
	{
		fprintf(mFile,"\"%s.lp\"",mName.c_str());
	}
	void getLightPositionX()const
	{
		fprintf(mFile,"\"%s.lp.lpx\"",mName.c_str());
	}
	void getLightPositionY()const
	{
		fprintf(mFile,"\"%s.lp.lpy\"",mName.c_str());
	}
	void getLightPositionZ()const
	{
		fprintf(mFile,"\"%s.lp.lpz\"",mName.c_str());
	}
	void getLightDirection()const
	{
		fprintf(mFile,"\"%s.ld\"",mName.c_str());
	}
	void getLightDirectionX()const
	{
		fprintf(mFile,"\"%s.ld.ldx\"",mName.c_str());
	}
	void getLightDirectionY()const
	{
		fprintf(mFile,"\"%s.ld.ldy\"",mName.c_str());
	}
	void getLightDirectionZ()const
	{
		fprintf(mFile,"\"%s.ld.ldz\"",mName.c_str());
	}
	void getSampleDistance()const
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());
	}
protected:
	LightInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LIGHTINFO_H__
