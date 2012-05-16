/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBSSQUARE_H__
#define __MayaDM_MAKENURBSSQUARE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class MakeNurbsSquare : public AbstractBaseCreate
{
public:
public:

	MakeNurbsSquare():AbstractBaseCreate(){}
	MakeNurbsSquare(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "makeNurbsSquare", shared, create){}
	virtual ~MakeNurbsSquare(){}

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
		if(nry == 0) return;
		fprintf(mFile,"\tsetAttr \".nr.nry\" %f;\n", nry);
	}
	void setNormalZ(double nrz)
	{
		if(nrz == 1) return;
		fprintf(mFile,"\tsetAttr \".nr.nrz\" %f;\n", nrz);
	}
	void setCenter(const double3& c)
	{
		fprintf(mFile,"\tsetAttr \".c\" -type \"double3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCenterX(double cx)
	{
		if(cx == 0) return;
		fprintf(mFile,"\tsetAttr \".c.cx\" %f;\n", cx);
	}
	void setCenterY(double cy)
	{
		if(cy == 0) return;
		fprintf(mFile,"\tsetAttr \".c.cy\" %f;\n", cy);
	}
	void setCenterZ(double cz)
	{
		if(cz == 0) return;
		fprintf(mFile,"\tsetAttr \".c.cz\" %f;\n", cz);
	}
	void setSideLength1(double sl1)
	{
		if(sl1 == 1) return;
		fprintf(mFile,"\tsetAttr \".sl1\" %f;\n", sl1);
	}
	void setSideLength2(double sl2)
	{
		if(sl2 == 1) return;
		fprintf(mFile,"\tsetAttr \".sl2\" %f;\n", sl2);
	}
	void setDegree(unsigned int d)
	{
		if(d == 3) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setSpansPerSide(int sps)
	{
		if(sps == 1) return;
		fprintf(mFile,"\tsetAttr \".sps\" %i;\n", sps);
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
	void getCenter()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getCenterX()const
	{
		fprintf(mFile,"\"%s.c.cx\"",mName.c_str());
	}
	void getCenterY()const
	{
		fprintf(mFile,"\"%s.c.cy\"",mName.c_str());
	}
	void getCenterZ()const
	{
		fprintf(mFile,"\"%s.c.cz\"",mName.c_str());
	}
	void getSideLength1()const
	{
		fprintf(mFile,"\"%s.sl1\"",mName.c_str());
	}
	void getSideLength2()const
	{
		fprintf(mFile,"\"%s.sl2\"",mName.c_str());
	}
	void getDegree()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSpansPerSide()const
	{
		fprintf(mFile,"\"%s.sps\"",mName.c_str());
	}
	void getOutputCurve1()const
	{
		fprintf(mFile,"\"%s.oc1\"",mName.c_str());
	}
	void getOutputCurve2()const
	{
		fprintf(mFile,"\"%s.oc2\"",mName.c_str());
	}
	void getOutputCurve3()const
	{
		fprintf(mFile,"\"%s.oc3\"",mName.c_str());
	}
	void getOutputCurve4()const
	{
		fprintf(mFile,"\"%s.oc4\"",mName.c_str());
	}
protected:
	MakeNurbsSquare(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBSSQUARE_H__
