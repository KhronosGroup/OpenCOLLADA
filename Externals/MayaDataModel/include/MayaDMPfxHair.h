/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PFXHAIR_H__
#define __MayaDM_PFXHAIR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPfxGeometry.h"
namespace MayaDM
{
class PfxHair : public PfxGeometry
{
public:
public:
	PfxHair(FILE* file,const std::string& name,const std::string& parent=""):PfxGeometry(file, name, parent, "pfxHair"){}
	virtual ~PfxHair(){}
	void getRenderHairs()
	{
		fprintf(mFile,"\"%s.rhs\"",mName.c_str());

	}
protected:
	PfxHair(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PfxGeometry(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_PFXHAIR_H__
