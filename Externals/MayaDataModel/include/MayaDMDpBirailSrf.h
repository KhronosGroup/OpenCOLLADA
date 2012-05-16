/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DPBIRAILSRF_H__
#define __MayaDM_DPBIRAILSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBirailSrf.h"
namespace MayaDM
{
class DpBirailSrf : public BirailSrf
{
public:
public:

	DpBirailSrf():BirailSrf(){}
	DpBirailSrf(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:BirailSrf(file, name, parent, "dpBirailSrf", shared, create){}
	virtual ~DpBirailSrf(){}

	void setBlendFactor(double bl)
	{
		if(bl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".bl\" %f;\n", bl);
	}
	void setTangentContinuityProfile1(bool tp1)
	{
		if(tp1 == false) return;
		fprintf(mFile,"\tsetAttr \".tp1\" %i;\n", tp1);
	}
	void setTangentContinuityProfile2(bool tp2)
	{
		if(tp2 == false) return;
		fprintf(mFile,"\tsetAttr \".tp2\" %i;\n", tp2);
	}
	void getInputProfile1()const
	{
		fprintf(mFile,"\"%s.ip1\"",mName.c_str());
	}
	void getInputProfile2()const
	{
		fprintf(mFile,"\"%s.ip2\"",mName.c_str());
	}
	void getBlendFactor()const
	{
		fprintf(mFile,"\"%s.bl\"",mName.c_str());
	}
	void getTangentContinuityProfile1()const
	{
		fprintf(mFile,"\"%s.tp1\"",mName.c_str());
	}
	void getTangentContinuityProfile2()const
	{
		fprintf(mFile,"\"%s.tp2\"",mName.c_str());
	}
protected:
	DpBirailSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:BirailSrf(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DPBIRAILSRF_H__
