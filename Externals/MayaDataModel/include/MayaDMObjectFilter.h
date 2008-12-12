/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTFILTER_H__
#define __MayaDM_OBJECTFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Base class dependency node that filters selection lists.  This base
 class node will just pass through all items, or no items if inverted.
*/
class ObjectFilter : public DependNode
{
public:
public:
	ObjectFilter(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "objectFilter"){}
	virtual ~ObjectFilter(){}
	/*Indicates this filter is part of a network.*/
	void setChild(bool ch){if(ch == 0) return; fprintf_s(mFile, "setAttr \".ch\" %i;\n", ch);}
	/*Indicates this filter is part of a network.*/
	void setChild(const BoolID& ch){fprintf_s(mFile,"connectAttr \"");ch.write(mFile);fprintf_s(mFile,"\" \"%s.ch\";\n",mName.c_str());}
	/*Boolean for inverting the filter*/
	void setInvert(bool inv){if(inv == 0) return; fprintf_s(mFile, "setAttr \".inv\" %i;\n", inv);}
	/*Boolean for inverting the filter*/
	void setInvert(const BoolID& inv){fprintf_s(mFile,"connectAttr \"");inv.write(mFile);fprintf_s(mFile,"\" \"%s.inv\";\n",mName.c_str());}
	/*List of items to be filtered*/
	void setInputList(const SelectionListID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*List of filtered items*/
	void setOutputList(const SelectionListID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*String for user annotation*/
	void setAnnotation(const string& an){if(an == "NULL") return; fprintf_s(mFile, "setAttr \".an\" -type \"string\" ");an.write(mFile);fprintf_s(mFile,";\n");}
	/*String for user annotation*/
	void setAnnotation(const StringID& an){fprintf_s(mFile,"connectAttr \"");an.write(mFile);fprintf_s(mFile,"\" \"%s.an\";\n",mName.c_str());}
	/*Strings for categorizing filter.*/
	void setCategory(const stringArray& cat){fprintf_s(mFile, "setAttr \".cat\" -type \"stringArray\" ");cat.write(mFile);fprintf_s(mFile,";\n");}
	/*Strings for categorizing filter.*/
	void setCategory(const StringArrayID& cat){fprintf_s(mFile,"connectAttr \"");cat.write(mFile);fprintf_s(mFile,"\" \"%s.cat\";\n",mName.c_str());}
	/*Boolean for turning off filtering*/
	void setDisable(bool dis){if(dis == 0) return; fprintf_s(mFile, "setAttr \".dis\" %i;\n", dis);}
	/*Boolean for turning off filtering*/
	void setDisable(const BoolID& dis){fprintf_s(mFile,"connectAttr \"");dis.write(mFile);fprintf_s(mFile,"\" \"%s.dis\";\n",mName.c_str());}
	/*Need to distinguish between builtin, user and other filters.*/
	void setFilterClass(unsigned int fcls){if(fcls == 0) return; fprintf_s(mFile, "setAttr \".fcls\" %i;\n", fcls);}
	/*Need to distinguish between builtin, user and other filters.*/
	void setFilterClass(const UnsignedintID& fcls){fprintf_s(mFile,"connectAttr \"");fcls.write(mFile);fprintf_s(mFile,"\" \"%s.fcls\";\n",mName.c_str());}
	/*Indicates this filter is part of a network.*/
	BoolID getChild(){char buffer[4096];sprintf_s (buffer, "%s.ch",mName.c_str());return (const char*)buffer;}
	/*Boolean for inverting the filter*/
	BoolID getInvert(){char buffer[4096];sprintf_s (buffer, "%s.inv",mName.c_str());return (const char*)buffer;}
	/*List of items to be filtered*/
	SelectionListID getInputList(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*List of filtered items*/
	SelectionListID getOutputList(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
	/*String for user annotation*/
	StringID getAnnotation(){char buffer[4096];sprintf_s (buffer, "%s.an",mName.c_str());return (const char*)buffer;}
	/*Strings for categorizing filter.*/
	StringArrayID getCategory(){char buffer[4096];sprintf_s (buffer, "%s.cat",mName.c_str());return (const char*)buffer;}
	/*Boolean for turning off filtering*/
	BoolID getDisable(){char buffer[4096];sprintf_s (buffer, "%s.dis",mName.c_str());return (const char*)buffer;}
	/*Need to distinguish between builtin, user and other filters.*/
	UnsignedintID getFilterClass(){char buffer[4096];sprintf_s (buffer, "%s.fcls",mName.c_str());return (const char*)buffer;}
protected:
	ObjectFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTFILTER_H__
