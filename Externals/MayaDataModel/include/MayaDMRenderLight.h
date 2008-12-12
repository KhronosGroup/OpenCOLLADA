/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERLIGHT_H__
#define __MayaDM_RENDERLIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLight.h"
namespace MayaDM
{
/*
<p><pre>
 This class contains the rendering information for all lights.

</pre></p>
*/
class RenderLight : public Light
{
public:
public:
	RenderLight(FILE* file,const std::string& name,const std::string& parent=""):Light(file, name, parent, "renderLight"){}
	virtual ~RenderLight(){}
protected:
	RenderLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Light(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RENDERLIGHT_H__
