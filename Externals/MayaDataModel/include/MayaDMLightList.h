/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHTLIST_H__
#define __MayaDM_LIGHTLIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
        This node is for light-classification.

</pre></p>
*/
class LightList : public DependNode
{
public:
public:
	LightList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "lightList"){}
	virtual ~LightList(){}
protected:
	LightList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LIGHTLIST_H__
