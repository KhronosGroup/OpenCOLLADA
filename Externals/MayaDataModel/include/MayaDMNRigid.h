/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NRIGID_H__
#define __MayaDM_NRIGID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNParticle.h"
namespace MayaDM
{
class NRigid : public NParticle
{
public:
public:

	NRigid():NParticle(){}
	NRigid(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:NParticle(file, name, parent, "nRigid", shared, create){}
	virtual ~NRigid(){}

	void setSolverDisplay(unsigned int svds)
	{
		if(svds == 0) return;
		fprintf(mFile,"\tsetAttr \".svds\" %i;\n", svds);
	}
	void getSolverDisplay()const
	{
		fprintf(mFile,"\"%s.svds\"",mName.c_str());
	}
protected:
	NRigid(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:NParticle(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NRIGID_H__
