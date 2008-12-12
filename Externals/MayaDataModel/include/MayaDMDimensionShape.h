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
/*
<p><pre>
    This is the base class for all dimension dagObjects that are created
    either interactively using the dimension creation tools or by using
    any of the dimension creation commands.

    Dimensions are objects that are used to either measure specific
    characteretics of the scene or of curves and surfaces in the scene. As
    they have to be displayed visually, and as they have to be selected and
    modified using the standard transformation tools, these objects are
    created as dagObjects.

</pre></p>
*/
class DimensionShape : public Shape
{
public:
public:
	DimensionShape(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "dimensionShape"){}
	virtual ~DimensionShape(){}
protected:
	DimensionShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DIMENSIONSHAPE_H__
