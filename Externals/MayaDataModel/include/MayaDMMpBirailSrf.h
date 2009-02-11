/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MPBIRAILSRF_H__
#define __MayaDM_MPBIRAILSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBirailSrf.h"
namespace MayaDM
{
class MpBirailSrf : public BirailSrf
{
public:
public:
	MpBirailSrf():BirailSrf(){}
	MpBirailSrf(FILE* file,const std::string& name,const std::string& parent=""):BirailSrf(file, name, parent, "mpBirailSrf"){}
	virtual ~MpBirailSrf(){}
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
	void getInputProfile(size_t ip_i)
	{
		fprintf(mFile,"\"%s.ip[%i]\"",mName.c_str(),ip_i);

	}
	void getTangentContinuityProfile1()
	{
		fprintf(mFile,"\"%s.tp1\"",mName.c_str());

	}
	void getTangentContinuityProfile2()
	{
		fprintf(mFile,"\"%s.tp2\"",mName.c_str());

	}
protected:
	MpBirailSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:BirailSrf(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MPBIRAILSRF_H__
