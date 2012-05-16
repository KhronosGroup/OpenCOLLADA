/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDBLINDDATA_H__
#define __MayaDM_SUBDBLINDDATA_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyBlindData.h"
namespace MayaDM
{
class SubdBlindData : public PolyBlindData
{
public:

	SubdBlindData():PolyBlindData(){}
	SubdBlindData(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyBlindData(file, name, parent, "subdBlindData", shared, create){}
	virtual ~SubdBlindData(){}

protected:
	SubdBlindData(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyBlindData(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDBLINDDATA_H__
