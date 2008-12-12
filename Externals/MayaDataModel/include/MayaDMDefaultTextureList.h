/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFAULTTEXTURELIST_H__
#define __MayaDM_DEFAULTTEXTURELIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
  This node is the list of textures known to the system.
  Any node connected to this one will be typed as a texture.
  It will filter as a texture, show up in the UI as a texture, etc.
  Connecting something to this node will *NOT* stop it from being
  anything else - it just means that when someone looks for that
  object on maya's list of textures, the connected node will be there.

</pre></p>
*/
class DefaultTextureList : public DependNode
{
public:
public:
	DefaultTextureList(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "defaultTextureList"){}
	virtual ~DefaultTextureList(){}
protected:
	DefaultTextureList(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFAULTTEXTURELIST_H__
