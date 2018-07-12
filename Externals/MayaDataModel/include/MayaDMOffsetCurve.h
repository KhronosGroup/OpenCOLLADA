/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OFFSETCURVE_H__
#define __MayaDM_OFFSETCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class OffsetCurve : public AbstractBaseCreate
{
public:
public:

	OffsetCurve():AbstractBaseCreate(){}
	OffsetCurve(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "offsetCurve", shared, create){}
	virtual ~OffsetCurve(){}

	void setConnectBreaks(unsigned int cb)
	{
		if(cb == 2) return;
		fprintf(mFile,"\tsetAttr \".cb\" %i;\n", cb);
	}
	void setReparameterize(bool rp)
	{
		if(rp == false) return;
		fprintf(mFile,"\tsetAttr \".rp\" %i;\n", rp);
	}
	void setStitch(bool st)
	{
		if(st == true) return;
		fprintf(mFile,"\tsetAttr \".st\" %i;\n", st);
	}
	void setCutLoop(bool cl)
	{
		if(cl == false) return;
		fprintf(mFile,"\tsetAttr \".cl\" %i;\n", cl);
	}
	void setCutRadius(double cr)
	{
		if(cr == 0) return;
		fprintf(mFile,"\tsetAttr \".cr\" %f;\n", cr);
	}
	void setDistance(double d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
	void setSubdivisionDensity(int sd)
	{
		if(sd == 5) return;
		fprintf(mFile,"\tsetAttr \".sd\" %i;\n", sd);
	}
	void setUseGivenNormal(bool ugn)
	{
		if(ugn == 1) return;
		fprintf(mFile,"\tsetAttr \".ugn\" %i;\n", ugn);
	}
	void setNormal(const double3& nr)
	{
		fprintf(mFile,"\tsetAttr \".nr\" -type \"double3\" ");
		nr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNormalX(double nrx)
	{
		if(nrx == 0) return;
		fprintf(mFile,"\tsetAttr \".nr.nrx\" %f;\n", nrx);
	}
	void setNormalY(double nry)
	{
		if(nry == 1) return;
		fprintf(mFile,"\tsetAttr \".nr.nry\" %f;\n", nry);
	}
	void setNormalZ(double nrz)
	{
		if(nrz == 0) return;
		fprintf(mFile,"\tsetAttr \".nr.nrz\" %f;\n", nrz);
	}
	void setParameter(double p)
	{
		if(p == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p\" %f;\n", p);
	}
	void setUseParameter(bool up)
	{
		if(up == false) return;
		fprintf(mFile,"\tsetAttr \".up\" %i;\n", up);
	}
	void getInputCurve()const
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());
	}
	void getConnectBreaks()const
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());
	}
	void getReparameterize()const
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());
	}
	void getStitch()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getCutLoop()const
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getCutRadius()const
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getTolerance()const
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());
	}
	void getSubdivisionDensity()const
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());
	}
	void getUseGivenNormal()const
	{
		fprintf(mFile,"\"%s.ugn\"",mName.c_str());
	}
	void getNormal()const
	{
		fprintf(mFile,"\"%s.nr\"",mName.c_str());
	}
	void getNormalX()const
	{
		fprintf(mFile,"\"%s.nr.nrx\"",mName.c_str());
	}
	void getNormalY()const
	{
		fprintf(mFile,"\"%s.nr.nry\"",mName.c_str());
	}
	void getNormalZ()const
	{
		fprintf(mFile,"\"%s.nr.nrz\"",mName.c_str());
	}
	void getParameter()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getUseParameter()const
	{
		fprintf(mFile,"\"%s.up\"",mName.c_str());
	}
	void getOutputCurve(size_t oc_i)const
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);
	}
	void getOutputCurve()const
	{

		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
protected:
	OffsetCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OFFSETCURVE_H__
