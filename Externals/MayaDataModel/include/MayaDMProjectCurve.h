/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PROJECTCURVE_H__
#define __MayaDM_PROJECTCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class ProjectCurve : public AbstractBaseCreate
{
public:
public:
	ProjectCurve():AbstractBaseCreate(){}
	ProjectCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "projectCurve"){}
	virtual ~ProjectCurve(){}
	void setDirection(const double3& d)
	{
		fprintf(mFile,"\tsetAttr \".d\" -type \"double3\" ");
		d.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDirectionX(double dx)
	{
		if(dx == 0) return;
		fprintf(mFile,"\tsetAttr \".d.dx\" %f;\n", dx);

	}
	void setDirectionY(double dy)
	{
		if(dy == 0) return;
		fprintf(mFile,"\tsetAttr \".d.dy\" %f;\n", dy);

	}
	void setDirectionZ(double dz)
	{
		if(dz == 1) return;
		fprintf(mFile,"\tsetAttr \".d.dz\" %f;\n", dz);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);

	}
	void setUseNormal(bool un)
	{
		if(un == false) return;
		fprintf(mFile,"\tsetAttr \".un\" %i;\n", un);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getOutputCurve(size_t oc_i)
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);

	}
	void getDirection()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getDirectionX()
	{
		fprintf(mFile,"\"%s.d.dx\"",mName.c_str());

	}
	void getDirectionY()
	{
		fprintf(mFile,"\"%s.d.dy\"",mName.c_str());

	}
	void getDirectionZ()
	{
		fprintf(mFile,"\"%s.d.dz\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getUseNormal()
	{
		fprintf(mFile,"\"%s.un\"",mName.c_str());

	}
protected:
	ProjectCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PROJECTCURVE_H__
