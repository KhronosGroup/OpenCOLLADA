/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SPBIRAILSRF_H__
#define __MayaDM_SPBIRAILSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBirailSrf.h"
namespace MayaDM
{
class SpBirailSrf : public BirailSrf
{
public:
public:
	SpBirailSrf():BirailSrf(){}
	SpBirailSrf(FILE* file,const std::string& name,const std::string& parent=""):BirailSrf(file, name, parent, "spBirailSrf"){}
	virtual ~SpBirailSrf(){}
	void setTangentContinuityProfile1(bool tp1)
	{
		if(tp1 == false) return;
		fprintf(mFile,"\tsetAttr \".tp1\" %i;\n", tp1);

	}
	void getInputProfile()
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());

	}
	void getTangentContinuityProfile1()
	{
		fprintf(mFile,"\"%s.tp1\"",mName.c_str());

	}
protected:
	SpBirailSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:BirailSrf(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SPBIRAILSRF_H__
