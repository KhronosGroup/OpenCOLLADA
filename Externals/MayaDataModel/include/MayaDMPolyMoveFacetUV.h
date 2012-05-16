/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMOVEFACETUV_H__
#define __MayaDM_POLYMOVEFACETUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveUV.h"
namespace MayaDM
{
class PolyMoveFacetUV : public PolyMoveUV
{
public:

	PolyMoveFacetUV():PolyMoveUV(){}
	PolyMoveFacetUV(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyMoveUV(file, name, parent, "polyMoveFacetUV", shared, create){}
	virtual ~PolyMoveFacetUV(){}

protected:
	PolyMoveFacetUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyMoveUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEFACETUV_H__
