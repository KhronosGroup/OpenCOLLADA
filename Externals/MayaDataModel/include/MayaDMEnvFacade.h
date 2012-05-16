/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVFACADE_H__
#define __MayaDM_ENVFACADE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFacade.h"
namespace MayaDM
{
class EnvFacade : public Facade
{
public:

	EnvFacade():Facade(){}
	EnvFacade(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Facade(file, name, parent, "envFacade", shared, create){}
	virtual ~EnvFacade(){}

protected:
	EnvFacade(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Facade(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVFACADE_H__
