/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PLANE_H__
#define __MayaDM_PLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
/*
<p><pre> This node is the basis for other plane-like objects, such as the
 sketch plane node.
</pre></p>
*/
class Plane : public GeometryShape
{
public:
public:
	Plane(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "plane"){}
	virtual ~Plane(){}
protected:
	Plane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PLANE_H__
