/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ATTACHSURFACE_H__
#define __MayaDM_ATTACHSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class AttachSurface : public AbstractBaseCreate
{
public:
public:
	AttachSurface():AbstractBaseCreate(){}
	AttachSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "attachSurface"){}
	virtual ~AttachSurface(){}
	void setMethod(unsigned int m)
	{
		if(m == 0) return;
		fprintf(mFile,"\tsetAttr \".m\" %i;\n", m);

	}
	void setDirectionU(bool du)
	{
		if(du == true) return;
		fprintf(mFile,"\tsetAttr \".du\" %i;\n", du);

	}
	void setReverse1(bool rv1)
	{
		if(rv1 == false) return;
		fprintf(mFile,"\tsetAttr \".rv1\" %i;\n", rv1);

	}
	void setReverse2(bool rv2)
	{
		if(rv2 == false) return;
		fprintf(mFile,"\tsetAttr \".rv2\" %i;\n", rv2);

	}
	void setSwap1(bool sw1)
	{
		if(sw1 == false) return;
		fprintf(mFile,"\tsetAttr \".sw1\" %i;\n", sw1);

	}
	void setSwap2(bool sw2)
	{
		if(sw2 == false) return;
		fprintf(mFile,"\tsetAttr \".sw2\" %i;\n", sw2);

	}
	void setTwist(bool tw)
	{
		if(tw == false) return;
		fprintf(mFile,"\tsetAttr \".tw\" %i;\n", tw);

	}
	void setBlendBias(double bb)
	{
		if(bb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".bb\" %f;\n", bb);

	}
	void setBlendKnotInsertion(bool bki)
	{
		if(bki == false) return;
		fprintf(mFile,"\tsetAttr \".bki\" %i;\n", bki);

	}
	void setParameter(double p)
	{
		if(p == 0.1) return;
		fprintf(mFile,"\tsetAttr \".p\" %f;\n", p);

	}
	void setKeepMultipleKnots(bool kmk)
	{
		if(kmk == true) return;
		fprintf(mFile,"\tsetAttr \".kmk\" %i;\n", kmk);

	}
	void getInputSurface1()
	{
		fprintf(mFile,"\"%s.is1\"",mName.c_str());

	}
	void getInputSurface2()
	{
		fprintf(mFile,"\"%s.is2\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getMethod()
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());

	}
	void getDirectionU()
	{
		fprintf(mFile,"\"%s.du\"",mName.c_str());

	}
	void getReverse1()
	{
		fprintf(mFile,"\"%s.rv1\"",mName.c_str());

	}
	void getReverse2()
	{
		fprintf(mFile,"\"%s.rv2\"",mName.c_str());

	}
	void getSwap1()
	{
		fprintf(mFile,"\"%s.sw1\"",mName.c_str());

	}
	void getSwap2()
	{
		fprintf(mFile,"\"%s.sw2\"",mName.c_str());

	}
	void getTwist()
	{
		fprintf(mFile,"\"%s.tw\"",mName.c_str());

	}
	void getBlendBias()
	{
		fprintf(mFile,"\"%s.bb\"",mName.c_str());

	}
	void getBlendKnotInsertion()
	{
		fprintf(mFile,"\"%s.bki\"",mName.c_str());

	}
	void getParameter()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getKeepMultipleKnots()
	{
		fprintf(mFile,"\"%s.kmk\"",mName.c_str());

	}
protected:
	AttachSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ATTACHSURFACE_H__
