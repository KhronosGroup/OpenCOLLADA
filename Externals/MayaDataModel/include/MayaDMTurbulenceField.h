/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TURBULENCEFIELD_H__
#define __MayaDM_TURBULENCEFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
class TurbulenceField : public Field
{
public:
public:

	TurbulenceField():Field(){}
	TurbulenceField(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Field(file, name, parent, "turbulenceField", shared, create){}
	virtual ~TurbulenceField(){}

	void setFrequency(double frq)
	{
		if(frq == 1.0) return;
		fprintf(mFile,"\tsetAttr \".frq\" %f;\n", frq);
	}
	void setPhaseX(double phx)
	{
		if(phx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".phx\" %f;\n", phx);
	}
	void setPhaseY(double phy)
	{
		if(phy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".phy\" %f;\n", phy);
	}
	void setPhaseZ(double phz)
	{
		if(phz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".phz\" %f;\n", phz);
	}
	void setNoiseLevel(int nslv)
	{
		if(nslv == 0) return;
		fprintf(mFile,"\tsetAttr \".nslv\" %i;\n", nslv);
	}
	void setNoiseRatio(double nsrt)
	{
		if(nsrt == 0.707) return;
		fprintf(mFile,"\tsetAttr \".nsrt\" %f;\n", nsrt);
	}
	void setInterpolationType(unsigned int intr)
	{
		if(intr == 0) return;
		fprintf(mFile,"\tsetAttr \".intr\" %i;\n", intr);
	}
	void getFrequency()const
	{
		fprintf(mFile,"\"%s.frq\"",mName.c_str());
	}
	void getPhaseX()const
	{
		fprintf(mFile,"\"%s.phx\"",mName.c_str());
	}
	void getPhaseY()const
	{
		fprintf(mFile,"\"%s.phy\"",mName.c_str());
	}
	void getPhaseZ()const
	{
		fprintf(mFile,"\"%s.phz\"",mName.c_str());
	}
	void getNoiseLevel()const
	{
		fprintf(mFile,"\"%s.nslv\"",mName.c_str());
	}
	void getNoiseRatio()const
	{
		fprintf(mFile,"\"%s.nsrt\"",mName.c_str());
	}
	void getInterpolationType()const
	{
		fprintf(mFile,"\"%s.intr\"",mName.c_str());
	}
protected:
	TurbulenceField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Field(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_TURBULENCEFIELD_H__
