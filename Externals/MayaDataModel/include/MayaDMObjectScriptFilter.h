/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTSCRIPTFILTER_H__
#define __MayaDM_OBJECTSCRIPTFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
/*Dependency node that filters selection lists using a user defined script.*/
class ObjectScriptFilter : public ObjectFilter
{
public:
public:
	ObjectScriptFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectScriptFilter"){}
	virtual ~ObjectScriptFilter(){}
	/*Use a single argument proc or a stringArray argument proc*/
	void setArrayArg(bool aarg){if(aarg == 1) return; fprintf_s(mFile, "setAttr \".aarg\" %i;\n", aarg);}
	/*Use a single argument proc or a stringArray argument proc*/
	void setArrayArg(const BoolID& aarg){fprintf_s(mFile,"connectAttr \"");aarg.write(mFile);fprintf_s(mFile,"\" \"%s.aarg\";\n",mName.c_str());}
	/*The name of the filter proc to be used.*/
	void setProcName(const string& pnam){if(pnam == "NULL") return; fprintf_s(mFile, "setAttr \".pnam\" -type \"string\" ");pnam.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the filter proc to be used.*/
	void setProcName(const StringID& pnam){fprintf_s(mFile,"connectAttr \"");pnam.write(mFile);fprintf_s(mFile,"\" \"%s.pnam\";\n",mName.c_str());}
	/*Filter on item name (false) or attribute name (true)*/
	void setAttrName(bool attr){if(attr == false) return; fprintf_s(mFile, "setAttr \".attr\" %i;\n", attr);}
	/*Filter on item name (false) or attribute name (true)*/
	void setAttrName(const BoolID& attr){fprintf_s(mFile,"connectAttr \"");attr.write(mFile);fprintf_s(mFile,"\" \"%s.attr\";\n",mName.c_str());}
	/*Return unique path names*/
	void setUniqueNodeNames(bool unn){if(unn == 0) return; fprintf_s(mFile, "setAttr \".unn\" %i;\n", unn);}
	/*Return unique path names*/
	void setUniqueNodeNames(const BoolID& unn){fprintf_s(mFile,"connectAttr \"");unn.write(mFile);fprintf_s(mFile,"\" \"%s.unn\";\n",mName.c_str());}
	/*Use a single argument proc or a stringArray argument proc*/
	BoolID getArrayArg(){char buffer[4096];sprintf_s (buffer, "%s.aarg",mName.c_str());return (const char*)buffer;}
	/*The name of the filter proc to be used.*/
	StringID getProcName(){char buffer[4096];sprintf_s (buffer, "%s.pnam",mName.c_str());return (const char*)buffer;}
	/*Filter on item name (false) or attribute name (true)*/
	BoolID getAttrName(){char buffer[4096];sprintf_s (buffer, "%s.attr",mName.c_str());return (const char*)buffer;}
	/*Return unique path names*/
	BoolID getUniqueNodeNames(){char buffer[4096];sprintf_s (buffer, "%s.unn",mName.c_str());return (const char*)buffer;}
protected:
	ObjectScriptFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTSCRIPTFILTER_H__
