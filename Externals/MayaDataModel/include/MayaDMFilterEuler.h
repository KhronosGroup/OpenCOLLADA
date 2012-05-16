/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTEREULER_H__
#define __MayaDM_FILTEREULER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFilter.h"
namespace MayaDM
{
class FilterEuler : public Filter
{
public:
public:

	FilterEuler():Filter(){}
	FilterEuler(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Filter(file, name, parent, "filterEuler", shared, create){}
	virtual ~FilterEuler(){}

	void setSmooth(unsigned int s)
	{
		if(s == 3) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void setNearestTo(unsigned int nt)
	{
		if(nt == 2) return;
		fprintf(mFile,"\tsetAttr \".nt\" %i;\n", nt);
	}
	void setWeight(const double3& w)
	{
		if(w == double3(1.0, 1.0, 1.0)) return;
		fprintf(mFile,"\tsetAttr \".w\" -type \"double3\" ");
		w.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWeightX(double wx)
	{
		if(wx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".w.wx\" %f;\n", wx);
	}
	void setWeightY(double wy)
	{
		if(wy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".w.wy\" %f;\n", wy);
	}
	void setWeightZ(double wz)
	{
		if(wz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".w.wz\" %f;\n", wz);
	}
	void setEnableInitialRotation(bool eir)
	{
		if(eir == false) return;
		fprintf(mFile,"\tsetAttr \".eir\" %i;\n", eir);
	}
	void setInitialRotation(const double3& ir)
	{
		if(ir == double3(0., 0., 0.)) return;
		fprintf(mFile,"\tsetAttr \".ir\" -type \"double3\" ");
		ir.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInitialRotationX(double irx)
	{
		if(irx == 0) return;
		fprintf(mFile,"\tsetAttr \".ir.irx\" %f;\n", irx);
	}
	void setInitialRotationY(double iry)
	{
		if(iry == 0) return;
		fprintf(mFile,"\tsetAttr \".ir.iry\" %f;\n", iry);
	}
	void setInitialRotationZ(double irz)
	{
		if(irz == 0) return;
		fprintf(mFile,"\tsetAttr \".ir.irz\" %f;\n", irz);
	}
	void setOutputUsageOpt(unsigned int use)
	{
		if(use == 0) return;
		fprintf(mFile,"\tsetAttr \".use\" %i;\n", use);
	}
	void getSmooth()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getNearestTo()const
	{
		fprintf(mFile,"\"%s.nt\"",mName.c_str());
	}
	void getWeight()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getWeightX()const
	{
		fprintf(mFile,"\"%s.w.wx\"",mName.c_str());
	}
	void getWeightY()const
	{
		fprintf(mFile,"\"%s.w.wy\"",mName.c_str());
	}
	void getWeightZ()const
	{
		fprintf(mFile,"\"%s.w.wz\"",mName.c_str());
	}
	void getEnableInitialRotation()const
	{
		fprintf(mFile,"\"%s.eir\"",mName.c_str());
	}
	void getInitialRotation()const
	{
		fprintf(mFile,"\"%s.ir\"",mName.c_str());
	}
	void getInitialRotationX()const
	{
		fprintf(mFile,"\"%s.ir.irx\"",mName.c_str());
	}
	void getInitialRotationY()const
	{
		fprintf(mFile,"\"%s.ir.iry\"",mName.c_str());
	}
	void getInitialRotationZ()const
	{
		fprintf(mFile,"\"%s.ir.irz\"",mName.c_str());
	}
	void getOutputUsageOpt()const
	{
		fprintf(mFile,"\"%s.use\"",mName.c_str());
	}
protected:
	FilterEuler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Filter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FILTEREULER_H__
