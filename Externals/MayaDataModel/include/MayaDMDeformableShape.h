/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
<p><pre>
 This contains the functions required to support shape deformations. Any shape
 that intends to work with deformers should derive from this class. Functions
 included here were previously defined in TcontrolPointShape. With the addition
 of particles to the list of deformable shapes, these functions needed to be in
 their own class. They could not be placed in TgeometryShape because a lot
 of nodes/classes derive from TgeometryShape that are not deformable.

</pre></p>
*/
class DeformableShape : public GeometryShape
{
public:
public:
	DeformableShape(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "deformableShape"){}
	virtual ~DeformableShape(){}
protected:
	DeformableShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMABLESHAPE_H__
