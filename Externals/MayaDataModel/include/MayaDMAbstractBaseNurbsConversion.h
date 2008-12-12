/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ABSTRACTBASENURBSCONVERSION_H__
#define __MayaDM_ABSTRACTBASENURBSCONVERSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*A base conversion node nurbs surfaces.*/
class AbstractBaseNurbsConversion : public AbstractBaseCreate
{
public:
public:
	AbstractBaseNurbsConversion(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "abstractBaseNurbsConversion"){}
	virtual ~AbstractBaseNurbsConversion(){}
protected:
	AbstractBaseNurbsConversion(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ABSTRACTBASENURBSCONVERSION_H__
