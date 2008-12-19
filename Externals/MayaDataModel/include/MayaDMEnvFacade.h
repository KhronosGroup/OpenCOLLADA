/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	EnvFacade(FILE* file,const std::string& name,const std::string& parent=""):Facade(file, name, parent, "envFacade"){}
	virtual ~EnvFacade(){}
protected:
	EnvFacade(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Facade(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVFACADE_H__
