/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	OffsetCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "offsetCurve"){}
	virtual ~OffsetCurve(){}
	void setConnectBreaks(unsigned int cb)
	{
		if(cb == 2) return;
		fprintf(mFile,"setAttr \".cb\" %i;\n", cb);

	}
	void setReparameterize(bool rp)
	{
		if(rp == false) return;
		fprintf(mFile,"setAttr \".rp\" %i;\n", rp);

	}
	void setStitch(bool st)
	{
		if(st == true) return;
		fprintf(mFile,"setAttr \".st\" %i;\n", st);

	}
	void setCutLoop(bool cl)
	{
		if(cl == false) return;
		fprintf(mFile,"setAttr \".cl\" %i;\n", cl);

	}
	void setCutRadius(double cr)
	{
		if(cr == 0) return;
		fprintf(mFile,"setAttr \".cr\" %f;\n", cr);

	}
	void setDistance(double d)
	{
		if(d == 1) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setSubdivisionDensity(int sd)
	{
		if(sd == 5) return;
		fprintf(mFile,"setAttr \".sd\" %i;\n", sd);

	}
	void setUseGivenNormal(bool ugn)
	{
		if(ugn == 1) return;
		fprintf(mFile,"setAttr \".ugn\" %i;\n", ugn);

	}
	void setNormal(const double3& nr)
	{
		fprintf(mFile,"setAttr \".nr\" -type \"double3\" ");
		nr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setNormalX(double nrx)
	{
		if(nrx == 0) return;
		fprintf(mFile,"setAttr \".nr.nrx\" %f;\n", nrx);

	}
	void setNormalY(double nry)
	{
		if(nry == 1) return;
		fprintf(mFile,"setAttr \".nr.nry\" %f;\n", nry);

	}
	void setNormalZ(double nrz)
	{
		if(nrz == 0) return;
		fprintf(mFile,"setAttr \".nr.nrz\" %f;\n", nrz);

	}
	void setParameter(double p)
	{
		if(p == 0.0) return;
		fprintf(mFile,"setAttr \".p\" %f;\n", p);

	}
	void setUseParameter(bool up)
	{
		if(up == false) return;
		fprintf(mFile,"setAttr \".up\" %i;\n", up);

	}
	void getInputCurve()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getConnectBreaks()
	{
		fprintf(mFile,"\"%s.cb\"",mName.c_str());

	}
	void getReparameterize()
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());

	}
	void getStitch()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getCutLoop()
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());

	}
	void getCutRadius()
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());

	}
	void getDistance()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getSubdivisionDensity()
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());

	}
	void getUseGivenNormal()
	{
		fprintf(mFile,"\"%s.ugn\"",mName.c_str());

	}
	void getNormal()
	{
		fprintf(mFile,"\"%s.nr\"",mName.c_str());

	}
	void getNormalX()
	{
		fprintf(mFile,"\"%s.nr.nrx\"",mName.c_str());

	}
	void getNormalY()
	{
		fprintf(mFile,"\"%s.nr.nry\"",mName.c_str());

	}
	void getNormalZ()
	{
		fprintf(mFile,"\"%s.nr.nrz\"",mName.c_str());

	}
	void getParameter()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getUseParameter()
	{
		fprintf(mFile,"\"%s.up\"",mName.c_str());

	}
	void getOutputCurve(size_t oc_i)
	{
		fprintf(mFile,"\"%s.oc[%i]\"",mName.c_str(),oc_i);

	}
protected:
	OffsetCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_OFFSETCURVE_H__
