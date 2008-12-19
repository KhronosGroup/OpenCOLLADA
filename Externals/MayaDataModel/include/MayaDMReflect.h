/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REFLECT_H__
#define __MayaDM_REFLECT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLambert.h"
namespace MayaDM
{
class Reflect : public Lambert
{
public:
public:
	Reflect(FILE* file,const std::string& name,const std::string& parent=""):Lambert(file, name, parent, "reflect"){}
	virtual ~Reflect(){}
	void setReflectionLimit(short fll)
	{
		if(fll == 1) return;
		fprintf(mFile,"setAttr \".fll\" %i;\n", fll);

	}
	void setSpecularColor(const float3& sc)
	{
		fprintf(mFile,"setAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularColorR(float sr)
	{
		if(sr == 0.5) return;
		fprintf(mFile,"setAttr \".sc.sr\" %f;\n", sr);

	}
	void setSpecularColorG(float sg)
	{
		if(sg == 0.5) return;
		fprintf(mFile,"setAttr \".sc.sg\" %f;\n", sg);

	}
	void setSpecularColorB(float sb)
	{
		if(sb == 0.5) return;
		fprintf(mFile,"setAttr \".sc.sb\" %f;\n", sb);

	}
	void setReflectivity(float rfl)
	{
		if(rfl == 0.5) return;
		fprintf(mFile,"setAttr \".rfl\" %f;\n", rfl);

	}
	void setReflectedColor(const float3& rc)
	{
		fprintf(mFile,"setAttr \".rc\" -type \"float3\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setReflectedColorR(float rr)
	{
		if(rr == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rr\" %f;\n", rr);

	}
	void setReflectedColorG(float rg)
	{
		if(rg == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rg\" %f;\n", rg);

	}
	void setReflectedColorB(float rb)
	{
		if(rb == 0.0) return;
		fprintf(mFile,"setAttr \".rc.rb\" %f;\n", rb);

	}
	void setReflectionSpecularity(float rsp)
	{
		if(rsp == 1.0) return;
		fprintf(mFile,"setAttr \".rsp\" %f;\n", rsp);

	}
	void getReflectionLimit()
	{
		fprintf(mFile,"\"%s.fll\"",mName.c_str());

	}
	void getSpecularColor()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getSpecularColorR()
	{
		fprintf(mFile,"\"%s.sc.sr\"",mName.c_str());

	}
	void getSpecularColorG()
	{
		fprintf(mFile,"\"%s.sc.sg\"",mName.c_str());

	}
	void getSpecularColorB()
	{
		fprintf(mFile,"\"%s.sc.sb\"",mName.c_str());

	}
	void getReflectivity()
	{
		fprintf(mFile,"\"%s.rfl\"",mName.c_str());

	}
	void getReflectedColor()
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());

	}
	void getReflectedColorR()
	{
		fprintf(mFile,"\"%s.rc.rr\"",mName.c_str());

	}
	void getReflectedColorG()
	{
		fprintf(mFile,"\"%s.rc.rg\"",mName.c_str());

	}
	void getReflectedColorB()
	{
		fprintf(mFile,"\"%s.rc.rb\"",mName.c_str());

	}
	void getTriangleNormalCamera()
	{
		fprintf(mFile,"\"%s.tnc\"",mName.c_str());

	}
	void getTriangleNormalCameraX()
	{
		fprintf(mFile,"\"%s.tnc.tnx\"",mName.c_str());

	}
	void getTriangleNormalCameraY()
	{
		fprintf(mFile,"\"%s.tnc.tny\"",mName.c_str());

	}
	void getTriangleNormalCameraZ()
	{
		fprintf(mFile,"\"%s.tnc.tnz\"",mName.c_str());

	}
	void getReflectionSpecularity()
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());

	}
protected:
	Reflect(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Lambert(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_REFLECT_H__
