/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMABLESHAPE_H__
#define __MayaDM_DEFORMABLESHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
class DeformableShape : public GeometryShape
{
public:

	DeformableShape():GeometryShape(){}
	DeformableShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, "deformableShape", shared, create){}
	virtual ~DeformableShape(){}

protected:
	DeformableShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMABLESHAPE_H__
