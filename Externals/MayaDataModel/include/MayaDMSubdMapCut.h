/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDMAPCUT_H__
#define __MayaDM_SUBDMAPCUT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifier.h"
namespace MayaDM
{
/*
Cut along edges of the texture mapping. The cut edges become
 texture borders.<p/>
*/
class SubdMapCut : public SubdModifier
{
public:
public:
	SubdMapCut(FILE* file,const std::string& name,const std::string& parent=""):SubdModifier(file, name, parent, "subdMapCut"){}
	virtual ~SubdMapCut(){}
protected:
	SubdMapCut(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDMAPCUT_H__
