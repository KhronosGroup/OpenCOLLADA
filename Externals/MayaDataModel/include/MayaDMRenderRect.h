/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERRECT_H__
#define __MayaDM_RENDERRECT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
/*
<p><pre>
        This class contains the "shape" information for renderRect.

</pre></p>
*/
class RenderRect : public GeometryShape
{
public:
public:
	RenderRect(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "renderRect"){}
	virtual ~RenderRect(){}
protected:
	RenderRect(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RENDERRECT_H__
