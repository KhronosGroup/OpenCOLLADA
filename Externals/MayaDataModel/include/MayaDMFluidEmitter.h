/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLUIDEMITTER_H__
#define __MayaDM_FLUIDEMITTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPointEmitter.h"
namespace MayaDM
{
class FluidEmitter : public PointEmitter
{
public:
public:

	FluidEmitter():PointEmitter(){}
	FluidEmitter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PointEmitter(file, name, parent, "fluidEmitter", shared, create){}
	virtual ~FluidEmitter(){}

	void setFluidDropoff(double fdo)
	{
		if(fdo == 2) return;
		fprintf(mFile,"\tsetAttr \".fdo\" %f;\n", fdo);
	}
	void setTurbulenceType(unsigned int trt)
	{
		if(trt == 0) return;
		fprintf(mFile,"\tsetAttr \".trt\" %i;\n", trt);
	}
	void setFluidJitter(bool fjt)
	{
		if(fjt == true) return;
		fprintf(mFile,"\tsetAttr \".fjt\" %i;\n", fjt);
	}
	void setTurbulence(double trb)
	{
		if(trb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".trb\" %f;\n", trb);
	}
	void setTurbulenceSpeed(double trs)
	{
		if(trs == 0.2) return;
		fprintf(mFile,"\tsetAttr \".trs\" %f;\n", trs);
	}
	void setTurbulenceFrequency(const double3& tf)
	{
		fprintf(mFile,"\tsetAttr \".tf\" -type \"double3\" ");
		tf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTurbulenceFrequencyX(double tfx)
	{
		if(tfx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tf.tfx\" %f;\n", tfx);
	}
	void setTurbulenceFrequencyY(double tfy)
	{
		if(tfy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tf.tfy\" %f;\n", tfy);
	}
	void setTurbulenceFrequencyZ(double tfz)
	{
		if(tfz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tf.tfz\" %f;\n", tfz);
	}
	void setTurbulenceOffset(const double3& to)
	{
		fprintf(mFile,"\tsetAttr \".to\" -type \"double3\" ");
		to.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTurbulenceOffsetX(double tox)
	{
		if(tox == 0.0) return;
		fprintf(mFile,"\tsetAttr \".to.tox\" %f;\n", tox);
	}
	void setTurbulenceOffsetY(double toy)
	{
		if(toy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".to.toy\" %f;\n", toy);
	}
	void setTurbulenceOffsetZ(double toz)
	{
		if(toz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".to.toz\" %f;\n", toz);
	}
	void setDetailTurbulence(double dtr)
	{
		if(dtr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dtr\" %f;\n", dtr);
	}
	void setFluidDensityEmission(double fde)
	{
		if(fde == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fde\" %f;\n", fde);
	}
	void setFluidHeatEmission(double fhe)
	{
		if(fhe == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fhe\" %f;\n", fhe);
	}
	void setFluidFuelEmission(double ffe)
	{
		if(ffe == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ffe\" %f;\n", ffe);
	}
	void setEmitFluidColor(bool efc)
	{
		if(efc == false) return;
		fprintf(mFile,"\tsetAttr \".efc\" %i;\n", efc);
	}
	void getFluidDropoff()const
	{
		fprintf(mFile,"\"%s.fdo\"",mName.c_str());
	}
	void getTurbulenceType()const
	{
		fprintf(mFile,"\"%s.trt\"",mName.c_str());
	}
	void getFluidJitter()const
	{
		fprintf(mFile,"\"%s.fjt\"",mName.c_str());
	}
	void getTurbulence()const
	{
		fprintf(mFile,"\"%s.trb\"",mName.c_str());
	}
	void getTurbulenceSpeed()const
	{
		fprintf(mFile,"\"%s.trs\"",mName.c_str());
	}
	void getTurbulenceFrequency()const
	{
		fprintf(mFile,"\"%s.tf\"",mName.c_str());
	}
	void getTurbulenceFrequencyX()const
	{
		fprintf(mFile,"\"%s.tf.tfx\"",mName.c_str());
	}
	void getTurbulenceFrequencyY()const
	{
		fprintf(mFile,"\"%s.tf.tfy\"",mName.c_str());
	}
	void getTurbulenceFrequencyZ()const
	{
		fprintf(mFile,"\"%s.tf.tfz\"",mName.c_str());
	}
	void getTurbulenceOffset()const
	{
		fprintf(mFile,"\"%s.to\"",mName.c_str());
	}
	void getTurbulenceOffsetX()const
	{
		fprintf(mFile,"\"%s.to.tox\"",mName.c_str());
	}
	void getTurbulenceOffsetY()const
	{
		fprintf(mFile,"\"%s.to.toy\"",mName.c_str());
	}
	void getTurbulenceOffsetZ()const
	{
		fprintf(mFile,"\"%s.to.toz\"",mName.c_str());
	}
	void getDetailTurbulence()const
	{
		fprintf(mFile,"\"%s.dtr\"",mName.c_str());
	}
	void getFluidDensityEmission()const
	{
		fprintf(mFile,"\"%s.fde\"",mName.c_str());
	}
	void getFluidHeatEmission()const
	{
		fprintf(mFile,"\"%s.fhe\"",mName.c_str());
	}
	void getFluidFuelEmission()const
	{
		fprintf(mFile,"\"%s.ffe\"",mName.c_str());
	}
	void getEmitFluidColor()const
	{
		fprintf(mFile,"\"%s.efc\"",mName.c_str());
	}
	void getEmissionFunction()const
	{
		fprintf(mFile,"\"%s.ef\"",mName.c_str());
	}
protected:
	FluidEmitter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PointEmitter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FLUIDEMITTER_H__
