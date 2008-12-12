/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POSTPROCESSLIST_H__
#define __MayaDM_POSTPROCESSLIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
        This node is for post-processing the list of shader and light glows.

</pre></p>
*/
class PostProcessList : public DependNode
{
public:
public:
	PostProcessList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "postProcessList"){}
	virtual ~PostProcessList(){}
protected:
	PostProcessList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POSTPROCESSLIST_H__
