/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBCIRCLE_H__
#define __MayaDM_MAKENURBCIRCLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class MakeNurbCircle : public AbstractBaseCreate
{
public:
public:
	MakeNurbCircle(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "makeNurbCircle"){}
	virtual ~MakeNurbCircle(){}
	void setFirst(const double3& fp)
	{
		fprintf(mFile,"setAttr \".fp\" -type \"double3\" ");
		fp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFirstPointX(double fpx)
	{
		if(fpx == 1) return;
		fprintf(mFile,"setAttr \".fp.fpx\" %f;\n", fpx);

	}
	void setFirstPointY(double fpy)
	{
		if(fpy == 0) return;
		fprintf(mFile,"setAttr \".fp.fpy\" %f;\n", fpy);

	}
	void setFirstPointZ(double fpz)
	{
		if(fpz == 0) return;
		fprintf(mFile,"setAttr \".fp.fpz\" %f;\n", fpz);

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
		if(nry == 0) return;
		fprintf(mFile,"setAttr \".nr.nry\" %f;\n", nry);

	}
	void setNormalZ(double nrz)
	{
		if(nrz == 1) return;
		fprintf(mFile,"setAttr \".nr.nrz\" %f;\n", nrz);

	}
	void setCenter(const double3& c)
	{
		fprintf(mFile,"setAttr \".c\" -type \"double3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCenterX(double cx)
	{
		if(cx == 0) return;
		fprintf(mFile,"setAttr \".c.cx\" %f;\n", cx);

	}
	void setCenterY(double cy)
	{
		if(cy == 0) return;
		fprintf(mFile,"setAttr \".c.cy\" %f;\n", cy);

	}
	void setCenterZ(double cz)
	{
		if(cz == 0) return;
		fprintf(mFile,"setAttr \".c.cz\" %f;\n", cz);

	}
	void setRadius(double r)
	{
		if(r == 1) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setSweep(double sw)
	{
		if(sw == 6.2831853) return;
		fprintf(mFile,"setAttr \".sw\" %f;\n", sw);

	}
	void setUseTolerance(bool ut)
	{
		if(ut == false) return;
		fprintf(mFile,"setAttr \".ut\" %i;\n", ut);

	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setSections(int s)
	{
		if(s == 8) return;
		fprintf(mFile,"setAttr \".s\" %i;\n", s);

	}
	void setTolerance(double tol)
	{
		if(tol == 0) return;
		fprintf(mFile,"setAttr \".tol\" %f;\n", tol);

	}
	void setFixCenter(bool fc)
	{
		if(fc == true) return;
		fprintf(mFile,"setAttr \".fc\" %i;\n", fc);

	}
	void getFirst()
	{
		fprintf(mFile,"\"%s.fp\"",mName.c_str());

	}
	void getFirstPointX()
	{
		fprintf(mFile,"\"%s.fp.fpx\"",mName.c_str());

	}
	void getFirstPointY()
	{
		fprintf(mFile,"\"%s.fp.fpy\"",mName.c_str());

	}
	void getFirstPointZ()
	{
		fprintf(mFile,"\"%s.fp.fpz\"",mName.c_str());

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
	void getCenter()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getCenterX()
	{
		fprintf(mFile,"\"%s.c.cx\"",mName.c_str());

	}
	void getCenterY()
	{
		fprintf(mFile,"\"%s.c.cy\"",mName.c_str());

	}
	void getCenterZ()
	{
		fprintf(mFile,"\"%s.c.cz\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getSweep()
	{
		fprintf(mFile,"\"%s.sw\"",mName.c_str());

	}
	void getUseTolerance()
	{
		fprintf(mFile,"\"%s.ut\"",mName.c_str());

	}
	void getDegree()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSections()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getTolerance()
	{
		fprintf(mFile,"\"%s.tol\"",mName.c_str());

	}
	void getFixCenter()
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());

	}
	void getOutputCurve()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
protected:
	MakeNurbCircle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBCIRCLE_H__
