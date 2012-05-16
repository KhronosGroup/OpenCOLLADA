/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class SubdMapCut : public SubdModifier
{
public:

	SubdMapCut():SubdModifier(){}
	SubdMapCut(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SubdModifier(file, name, parent, "subdMapCut", shared, create){}
	virtual ~SubdMapCut(){}

protected:
	SubdMapCut(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SubdModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDMAPCUT_H__
