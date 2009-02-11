/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PAIRBLEND_H__
#define __MayaDM_PAIRBLEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class PairBlend : public DependNode
{
public:
public:
	PairBlend():DependNode(){}
	PairBlend(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "pairBlend"){}
	virtual ~PairBlend(){}
	void setCurrentDriver(unsigned int c)
	{
		if(c == 0) return;
		fprintf(mFile,"\tsetAttr \".c\" %i;\n", c);

	}
	void setInTranslate1(const double3& it1)
	{
		fprintf(mFile,"\tsetAttr \".it1\" -type \"double3\" ");
		it1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInTranslateX1(double itx1)
	{
		if(itx1 == 0) return;
		fprintf(mFile,"\tsetAttr \".it1.itx1\" %f;\n", itx1);

	}
	void setInTranslateY1(double ity1)
	{
		if(ity1 == 0) return;
		fprintf(mFile,"\tsetAttr \".it1.ity1\" %f;\n", ity1);

	}
	void setInTranslateZ1(double itz1)
	{
		if(itz1 == 0) return;
		fprintf(mFile,"\tsetAttr \".it1.itz1\" %f;\n", itz1);

	}
	void setInRotate1(const double3& ir1)
	{
		fprintf(mFile,"\tsetAttr \".ir1\" -type \"double3\" ");
		ir1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInRotateX1(double irx1)
	{
		if(irx1 == 0) return;
		fprintf(mFile,"\tsetAttr \".ir1.irx1\" %f;\n", irx1);

	}
	void setInRotateY1(double iry1)
	{
		if(iry1 == 0) return;
		fprintf(mFile,"\tsetAttr \".ir1.iry1\" %f;\n", iry1);

	}
	void setInRotateZ1(double irz1)
	{
		if(irz1 == 0) return;
		fprintf(mFile,"\tsetAttr \".ir1.irz1\" %f;\n", irz1);

	}
	void setInTranslate2(const double3& it2)
	{
		fprintf(mFile,"\tsetAttr \".it2\" -type \"double3\" ");
		it2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInTranslateX2(double itx2)
	{
		if(itx2 == 0) return;
		fprintf(mFile,"\tsetAttr \".it2.itx2\" %f;\n", itx2);

	}
	void setInTranslateY2(double ity2)
	{
		if(ity2 == 0) return;
		fprintf(mFile,"\tsetAttr \".it2.ity2\" %f;\n", ity2);

	}
	void setInTranslateZ2(double itz2)
	{
		if(itz2 == 0) return;
		fprintf(mFile,"\tsetAttr \".it2.itz2\" %f;\n", itz2);

	}
	void setInRotate2(const double3& ir2)
	{
		fprintf(mFile,"\tsetAttr \".ir2\" -type \"double3\" ");
		ir2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInRotateX2(double irx2)
	{
		if(irx2 == 0) return;
		fprintf(mFile,"\tsetAttr \".ir2.irx2\" %f;\n", irx2);

	}
	void setInRotateY2(double iry2)
	{
		if(iry2 == 0) return;
		fprintf(mFile,"\tsetAttr \".ir2.iry2\" %f;\n", iry2);

	}
	void setInRotateZ2(double irz2)
	{
		if(irz2 == 0) return;
		fprintf(mFile,"\tsetAttr \".ir2.irz2\" %f;\n", irz2);

	}
	void setWeight(double w)
	{
		if(w == 1.0) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);

	}
	void setRotateOrder(unsigned int ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"\tsetAttr \".ro\" %i;\n", ro);

	}
	void setTranslateXMode(unsigned int txm)
	{
		if(txm == 0) return;
		fprintf(mFile,"\tsetAttr \".txm\" %i;\n", txm);

	}
	void setTranslateYMode(unsigned int tym)
	{
		if(tym == 0) return;
		fprintf(mFile,"\tsetAttr \".tym\" %i;\n", tym);

	}
	void setTranslateZMode(unsigned int tzm)
	{
		if(tzm == 0) return;
		fprintf(mFile,"\tsetAttr \".tzm\" %i;\n", tzm);

	}
	void setRotateMode(unsigned int rm)
	{
		if(rm == 0) return;
		fprintf(mFile,"\tsetAttr \".rm\" %i;\n", rm);

	}
	void setRotInterpolation(unsigned int ri)
	{
		if(ri == 0) return;
		fprintf(mFile,"\tsetAttr \".ri\" %i;\n", ri);

	}
	void getInTranslate1()
	{
		fprintf(mFile,"\"%s.it1\"",mName.c_str());

	}
	void getInTranslateX1()
	{
		fprintf(mFile,"\"%s.it1.itx1\"",mName.c_str());

	}
	void getInTranslateY1()
	{
		fprintf(mFile,"\"%s.it1.ity1\"",mName.c_str());

	}
	void getInTranslateZ1()
	{
		fprintf(mFile,"\"%s.it1.itz1\"",mName.c_str());

	}
	void getInRotate1()
	{
		fprintf(mFile,"\"%s.ir1\"",mName.c_str());

	}
	void getInRotateX1()
	{
		fprintf(mFile,"\"%s.ir1.irx1\"",mName.c_str());

	}
	void getInRotateY1()
	{
		fprintf(mFile,"\"%s.ir1.iry1\"",mName.c_str());

	}
	void getInRotateZ1()
	{
		fprintf(mFile,"\"%s.ir1.irz1\"",mName.c_str());

	}
	void getInTranslate2()
	{
		fprintf(mFile,"\"%s.it2\"",mName.c_str());

	}
	void getInTranslateX2()
	{
		fprintf(mFile,"\"%s.it2.itx2\"",mName.c_str());

	}
	void getInTranslateY2()
	{
		fprintf(mFile,"\"%s.it2.ity2\"",mName.c_str());

	}
	void getInTranslateZ2()
	{
		fprintf(mFile,"\"%s.it2.itz2\"",mName.c_str());

	}
	void getInRotate2()
	{
		fprintf(mFile,"\"%s.ir2\"",mName.c_str());

	}
	void getInRotateX2()
	{
		fprintf(mFile,"\"%s.ir2.irx2\"",mName.c_str());

	}
	void getInRotateY2()
	{
		fprintf(mFile,"\"%s.ir2.iry2\"",mName.c_str());

	}
	void getInRotateZ2()
	{
		fprintf(mFile,"\"%s.ir2.irz2\"",mName.c_str());

	}
	void getWeight()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
	void getRotateOrder()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getOutTranslate()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutTranslateX()
	{
		fprintf(mFile,"\"%s.ot.otx\"",mName.c_str());

	}
	void getOutTranslateY()
	{
		fprintf(mFile,"\"%s.ot.oty\"",mName.c_str());

	}
	void getOutTranslateZ()
	{
		fprintf(mFile,"\"%s.ot.otz\"",mName.c_str());

	}
	void getOutRotate()
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());

	}
	void getOutRotateX()
	{
		fprintf(mFile,"\"%s.or.orx\"",mName.c_str());

	}
	void getOutRotateY()
	{
		fprintf(mFile,"\"%s.or.ory\"",mName.c_str());

	}
	void getOutRotateZ()
	{
		fprintf(mFile,"\"%s.or.orz\"",mName.c_str());

	}
protected:
	PairBlend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PAIRBLEND_H__
