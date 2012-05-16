/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDMODIFIERUV_H__
#define __MayaDM_SUBDMODIFIERUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifierWorld.h"
namespace MayaDM
{
class SubdModifierUV : public SubdModifierWorld
{
public:

	SubdModifierUV():SubdModifierWorld(){}
	SubdModifierUV(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SubdModifierWorld(file, name, parent, "subdModifierUV", shared, create){}
	virtual ~SubdModifierUV(){}

protected:
	SubdModifierUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SubdModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDMODIFIERUV_H__
