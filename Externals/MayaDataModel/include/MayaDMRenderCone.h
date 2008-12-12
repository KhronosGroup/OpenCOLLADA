/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERCONE_H__
#define __MayaDM_RENDERCONE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMImplicitCone.h"
namespace MayaDM
{
/*
<p><pre>
 This contains the shape for the spot light's fog volume.

</pre></p>
*/
class RenderCone : public ImplicitCone
{
public:
public:
	RenderCone(FILE* file,const std::string& name,const std::string& parent=""):ImplicitCone(file, name, parent, "renderCone"){}
	virtual ~RenderCone(){}
protected:
	RenderCone(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ImplicitCone(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RENDERCONE_H__
