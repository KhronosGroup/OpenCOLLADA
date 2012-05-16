/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSTESSELLATE_H__
#define __MayaDM_NURBSTESSELLATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMParentTessellate.h"
namespace MayaDM
{
class NurbsTessellate : public ParentTessellate
{
public:
public:

	NurbsTessellate():ParentTessellate(){}
	NurbsTessellate(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ParentTessellate(file, name, parent, "nurbsTessellate", shared, create){}
	virtual ~NurbsTessellate(){}

	void setSmoothEdge(bool ues)
	{
		if(ues == false) return;
		fprintf(mFile,"\tsetAttr \".ues\" %i;\n", ues);
	}
	void setSmoothEdgeRatio(double esr)
	{
		if(esr == 0.99) return;
		fprintf(mFile,"\tsetAttr \".esr\" %f;\n", esr);
	}
	void setExplicitTessellationAttributes(bool eta)
	{
		if(eta == true) return;
		fprintf(mFile,"\tsetAttr \".eta\" %i;\n", eta);
	}
	void setUDivisionsFactor(double nuf)
	{
		if(nuf == 1.5) return;
		fprintf(mFile,"\tsetAttr \".nuf\" %f;\n", nuf);
	}
	void setVDivisionsFactor(double nvf)
	{
		if(nvf == 1.5) return;
		fprintf(mFile,"\tsetAttr \".nvf\" %f;\n", nvf);
	}
	void setCurvatureTolerance(unsigned int cvt)
	{
		if(cvt == 2) return;
		fprintf(mFile,"\tsetAttr \".cvt\" %i;\n", cvt);
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getSmoothEdge()const
	{
		fprintf(mFile,"\"%s.ues\"",mName.c_str());
	}
	void getSmoothEdgeRatio()const
	{
		fprintf(mFile,"\"%s.esr\"",mName.c_str());
	}
	void getExplicitTessellationAttributes()const
	{
		fprintf(mFile,"\"%s.eta\"",mName.c_str());
	}
	void getUDivisionsFactor()const
	{
		fprintf(mFile,"\"%s.nuf\"",mName.c_str());
	}
	void getVDivisionsFactor()const
	{
		fprintf(mFile,"\"%s.nvf\"",mName.c_str());
	}
	void getCurvatureTolerance()const
	{
		fprintf(mFile,"\"%s.cvt\"",mName.c_str());
	}
protected:
	NurbsTessellate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ParentTessellate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSTESSELLATE_H__
