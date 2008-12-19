/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	TurbulenceField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "turbulenceField"){}
	virtual ~TurbulenceField(){}
	void setFrequency(double frq)
	{
		if(frq == 1.0) return;
		fprintf(mFile,"setAttr \".frq\" %f;\n", frq);

	}
	void setPhaseX(double phx)
	{
		if(phx == 0.0) return;
		fprintf(mFile,"setAttr \".phx\" %f;\n", phx);

	}
	void setPhaseY(double phy)
	{
		if(phy == 0.0) return;
		fprintf(mFile,"setAttr \".phy\" %f;\n", phy);

	}
	void setPhaseZ(double phz)
	{
		if(phz == 0.0) return;
		fprintf(mFile,"setAttr \".phz\" %f;\n", phz);

	}
	void setNoiseLevel(int nslv)
	{
		if(nslv == 0) return;
		fprintf(mFile,"setAttr \".nslv\" %i;\n", nslv);

	}
	void setNoiseRatio(double nsrt)
	{
		if(nsrt == 0.707) return;
		fprintf(mFile,"setAttr \".nsrt\" %f;\n", nsrt);

	}
	void setInterpolationType(unsigned int intr)
	{
		if(intr == 0) return;
		fprintf(mFile,"setAttr \".intr\" %i;\n", intr);

	}
	void getFrequency()
	{
		fprintf(mFile,"\"%s.frq\"",mName.c_str());

	}
	void getPhaseX()
	{
		fprintf(mFile,"\"%s.phx\"",mName.c_str());

	}
	void getPhaseY()
	{
		fprintf(mFile,"\"%s.phy\"",mName.c_str());

	}
	void getPhaseZ()
	{
		fprintf(mFile,"\"%s.phz\"",mName.c_str());

	}
	void getNoiseLevel()
	{
		fprintf(mFile,"\"%s.nslv\"",mName.c_str());

	}
	void getNoiseRatio()
	{
		fprintf(mFile,"\"%s.nsrt\"",mName.c_str());

	}
	void getInterpolationType()
	{
		fprintf(mFile,"\"%s.intr\"",mName.c_str());

	}
protected:
	TurbulenceField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TURBULENCEFIELD_H__
