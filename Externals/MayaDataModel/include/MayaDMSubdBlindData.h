/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
Special case of a poly blind data node type.  This one will hold
 the subdivision surface hierarchical edits; if a subdivision
 surface is created from a polygon with such blind data, the hierarchical
 edits will get transfered to the resulting subdivision surface.
*/
class SubdBlindData : public PolyBlindData
{
public:
public:
	SubdBlindData(FILE* file,const std::string& name,const std::string& parent=""):PolyBlindData(file, name, parent, "subdBlindData"){}
	virtual ~SubdBlindData(){}
protected:
	SubdBlindData(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyBlindData(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDBLINDDATA_H__
