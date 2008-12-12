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
/*
<b>envFacade</b> is a node to which dynamic attributes
        can be added to define the parameters of an environment.
*/
class EnvFacade : public Facade
{
public:
public:
	EnvFacade(FILE* file,const std::string& name,const std::string& parent=""):Facade(file, name, parent, "envFacade"){}
	virtual ~EnvFacade(){}
protected:
	EnvFacade(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Facade(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ENVFACADE_H__
