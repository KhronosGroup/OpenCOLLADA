/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTTYPEFILTER_H__
#define __MayaDM_OBJECTTYPEFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
/*Dependency node that filters selection lists by type.*/
class ObjectTypeFilter : public ObjectFilter
{
public:
public:
	ObjectTypeFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectTypeFilter"){}
	virtual ~ObjectTypeFilter(){}
	/*Name of object type to be filtered*/
	void setTypeName(const string& tnam){if(tnam == "NULL") return; fprintf_s(mFile, "setAttr \".tnam\" -type \"string\" ");tnam.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of object type to be filtered*/
	void setTypeName(const StringID& tnam){fprintf_s(mFile,"connectAttr \"");tnam.write(mFile);fprintf_s(mFile,"\" \"%s.tnam\";\n",mName.c_str());}
	/*Type Id of object type to be filtered*/
	void setType(const StringID& typ){fprintf_s(mFile,"connectAttr \"");typ.write(mFile);fprintf_s(mFile,"\" \"%s.typ\";\n",mName.c_str());}
	/*Name of object type to be filtered*/
	StringID getTypeName(){char buffer[4096];sprintf_s (buffer, "%s.tnam",mName.c_str());return (const char*)buffer;}
	/*Type Id of object type to be filtered*/
	StringID getType(){char buffer[4096];sprintf_s (buffer, "%s.typ",mName.c_str());return (const char*)buffer;}
protected:
	ObjectTypeFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTTYPEFILTER_H__
