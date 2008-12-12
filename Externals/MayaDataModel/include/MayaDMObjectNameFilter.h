/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTNAMEFILTER_H__
#define __MayaDM_OBJECTNAMEFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
/*Dependency node that filters selection lists by name.*/
class ObjectNameFilter : public ObjectFilter
{
public:
public:
	ObjectNameFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectNameFilter"){}
	virtual ~ObjectNameFilter(){}
	/*Regular expression for filtering*/
	void setRegExp(const string& rex){if(rex == "NULL") return; fprintf_s(mFile, "setAttr \".rex\" -type \"string\" ");rex.write(mFile);fprintf_s(mFile,";\n");}
	/*Regular expression for filtering*/
	void setRegExp(const StringID& rex){fprintf_s(mFile,"connectAttr \"");rex.write(mFile);fprintf_s(mFile,"\" \"%s.rex\";\n",mName.c_str());}
	/*Name string array for filtering*/
	void setNameStrings(const stringArray& nstr){if(nstr.size == 0) return; fprintf_s(mFile, "setAttr \".nstr\" -type \"stringArray\" ");nstr.write(mFile);fprintf_s(mFile,";\n");}
	/*Name string array for filtering*/
	void setNameStrings(const StringArrayID& nstr){fprintf_s(mFile,"connectAttr \"");nstr.write(mFile);fprintf_s(mFile,"\" \"%s.nstr\";\n",mName.c_str());}
	/*Filter on item name (false) or attribute name (true)*/
	void setAttrName(bool attr){if(attr == false) return; fprintf_s(mFile, "setAttr \".attr\" %i;\n", attr);}
	/*Filter on item name (false) or attribute name (true)*/
	void setAttrName(const BoolID& attr){fprintf_s(mFile,"connectAttr \"");attr.write(mFile);fprintf_s(mFile,"\" \"%s.attr\";\n",mName.c_str());}
	/*Regular expression for filtering*/
	StringID getRegExp(){char buffer[4096];sprintf_s (buffer, "%s.rex",mName.c_str());return (const char*)buffer;}
	/*Name string array for filtering*/
	StringArrayID getNameStrings(){char buffer[4096];sprintf_s (buffer, "%s.nstr",mName.c_str());return (const char*)buffer;}
	/*Filter on item name (false) or attribute name (true)*/
	BoolID getAttrName(){char buffer[4096];sprintf_s (buffer, "%s.attr",mName.c_str());return (const char*)buffer;}
protected:
	ObjectNameFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTNAMEFILTER_H__
