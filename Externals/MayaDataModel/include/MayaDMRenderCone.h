/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class RenderCone : public ImplicitCone
{
public:

	RenderCone():ImplicitCone(){}
	RenderCone(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ImplicitCone(file, name, parent, "renderCone", shared, create){}
	virtual ~RenderCone(){}

protected:
	RenderCone(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ImplicitCone(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERCONE_H__
