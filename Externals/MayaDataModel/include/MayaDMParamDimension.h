/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARAMDIMENSION_H__
#define __MayaDM_PARAMDIMENSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNurbsDimShape.h"
namespace MayaDM
{
class ParamDimension : public NurbsDimShape
{
public:

	ParamDimension():NurbsDimShape(){}
	ParamDimension(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:NurbsDimShape(file, name, parent, "paramDimension", shared, create){}
	virtual ~ParamDimension(){}

protected:
	ParamDimension(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:NurbsDimShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_PARAMDIMENSION_H__
