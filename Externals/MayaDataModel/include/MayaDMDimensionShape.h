/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DIMENSIONSHAPE_H__
#define __MayaDM_DIMENSIONSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class DimensionShape : public Shape
{
public:
	DimensionShape(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "dimensionShape"){}
	virtual ~DimensionShape(){}
protected:
	DimensionShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DIMENSIONSHAPE_H__
