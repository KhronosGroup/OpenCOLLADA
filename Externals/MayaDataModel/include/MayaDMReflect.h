/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Reflect():Lambert(){}
	Reflect(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Lambert(file, name, parent, "reflect", shared, create){}
	virtual ~Reflect(){}

	void setReflectionLimit(short fll)
	{
		if(fll == 1) return;
		fprintf(mFile,"\tsetAttr \".fll\" %i;\n", fll);
	}
	void setSpecularColor(const float3& sc)
	{
		fprintf(mFile,"\tsetAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularColorR(float sr)
	{
		if(sr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.sr\" %f;\n", sr);
	}
	void setSpecularColorG(float sg)
	{
		if(sg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.sg\" %f;\n", sg);
	}
	void setSpecularColorB(float sb)
	{
		if(sb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.sb\" %f;\n", sb);
	}
	void setReflectivity(float rfl)
	{
		if(rfl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".rfl\" %f;\n", rfl);
	}
	void setReflectedColor(const float3& rc)
	{
		fprintf(mFile,"\tsetAttr \".rc\" -type \"float3\" ");
		rc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setReflectedColorR(float rr)
	{
		if(rr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rr\" %f;\n", rr);
	}
	void setReflectedColorG(float rg)
	{
		if(rg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rg\" %f;\n", rg);
	}
	void setReflectedColorB(float rb)
	{
		if(rb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rc.rb\" %f;\n", rb);
	}
	void setReflectionSpecularity(float rsp)
	{
		if(rsp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rsp\" %f;\n", rsp);
	}
	void getReflectionLimit()const
	{
		fprintf(mFile,"\"%s.fll\"",mName.c_str());
	}
	void getSpecularColor()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getSpecularColorR()const
	{
		fprintf(mFile,"\"%s.sc.sr\"",mName.c_str());
	}
	void getSpecularColorG()const
	{
		fprintf(mFile,"\"%s.sc.sg\"",mName.c_str());
	}
	void getSpecularColorB()const
	{
		fprintf(mFile,"\"%s.sc.sb\"",mName.c_str());
	}
	void getReflectivity()const
	{
		fprintf(mFile,"\"%s.rfl\"",mName.c_str());
	}
	void getReflectedColor()const
	{
		fprintf(mFile,"\"%s.rc\"",mName.c_str());
	}
	void getReflectedColorR()const
	{
		fprintf(mFile,"\"%s.rc.rr\"",mName.c_str());
	}
	void getReflectedColorG()const
	{
		fprintf(mFile,"\"%s.rc.rg\"",mName.c_str());
	}
	void getReflectedColorB()const
	{
		fprintf(mFile,"\"%s.rc.rb\"",mName.c_str());
	}
	void getTriangleNormalCamera()const
	{
		fprintf(mFile,"\"%s.tnc\"",mName.c_str());
	}
	void getTriangleNormalCameraX()const
	{
		fprintf(mFile,"\"%s.tnc.tnx\"",mName.c_str());
	}
	void getTriangleNormalCameraY()const
	{
		fprintf(mFile,"\"%s.tnc.tny\"",mName.c_str());
	}
	void getTriangleNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.tnc.tnz\"",mName.c_str());
	}
	void getReflectionSpecularity()const
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());
	}
protected:
	Reflect(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Lambert(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_REFLECT_H__
