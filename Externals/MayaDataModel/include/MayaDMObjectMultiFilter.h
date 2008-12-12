/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTMULTIFILTER_H__
#define __MayaDM_OBJECTMULTIFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
/*
Dependency node that attempts to act like a super node.  It has
                a sub-graph of filters, the final result of which gets placed
                in the multi-filter's result list attribute.  Sub filters take their
                input from the multi-filter input.  Thus a user can
                set a multi-filter's input and read its output, without knowing
                that it is a multi-filter.
*/
class ObjectMultiFilter : public ObjectFilter
{
public:
public:
	ObjectMultiFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectMultiFilter"){}
	virtual ~ObjectMultiFilter(){}
	/*Result from the filter sub-graph.*/
	void setResultList(const SelectionListID& res){fprintf_s(mFile,"connectAttr \"");res.write(mFile);fprintf_s(mFile,"\" \"%s.res\";\n",mName.c_str());}
	/*
	Need to distinguish between item and attribute filters. The following
	are legal values: 0 = Item, 1 = Attribute.
	*/
	void setFilterType(unsigned int ftyp){if(ftyp == 0) return; fprintf_s(mFile, "setAttr \".ftyp\" %i;\n", ftyp);}
	/*
	Need to distinguish between item and attribute filters. The following
	are legal values: 0 = Item, 1 = Attribute.
	*/
	void setFilterType(const UnsignedintID& ftyp){fprintf_s(mFile,"connectAttr \"");ftyp.write(mFile);fprintf_s(mFile,"\" \"%s.ftyp\";\n",mName.c_str());}
	/*Result from the filter sub-graph.*/
	SelectionListID getResultList(){char buffer[4096];sprintf_s (buffer, "%s.res",mName.c_str());return (const char*)buffer;}
	/*
	Need to distinguish between item and attribute filters. The following
	are legal values: 0 = Item, 1 = Attribute.
	*/
	UnsignedintID getFilterType(){char buffer[4096];sprintf_s (buffer, "%s.ftyp",mName.c_str());return (const char*)buffer;}
protected:
	ObjectMultiFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTMULTIFILTER_H__
