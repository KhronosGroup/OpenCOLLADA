/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTBINFILTER_H__
#define __MayaDM_OBJECTBINFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
/*
<p><pre>
 Dependency node that filters selection lists by bin.

</pre></p>
*/
class ObjectBinFilter : public ObjectFilter
{
public:
public:
	ObjectBinFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectBinFilter"){}
	virtual ~ObjectBinFilter(){}
	/*Name of bin to be filtered*/
	void setBinName(const string& bnam){if(bnam == "NULL") return; fprintf_s(mFile, "setAttr \".bnam\" -type \"string\" ");bnam.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of bin to be filtered*/
	void setBinName(const StringID& bnam){fprintf_s(mFile,"connectAttr \"");bnam.write(mFile);fprintf_s(mFile,"\" \"%s.bnam\";\n",mName.c_str());}
	/*Name of bin to be filtered*/
	StringID getBinName(){char buffer[4096];sprintf_s (buffer, "%s.bnam",mName.c_str());return (const char*)buffer;}
protected:
	ObjectBinFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTBINFILTER_H__
