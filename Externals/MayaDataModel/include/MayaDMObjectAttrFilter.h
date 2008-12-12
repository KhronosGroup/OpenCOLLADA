/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTATTRFILTER_H__
#define __MayaDM_OBJECTATTRFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
/*Dependency node that filters selection lists by attribute characteristics*/
class ObjectAttrFilter : public ObjectFilter
{
public:
public:
	ObjectAttrFilter(FILE* file,const std::string& name,const std::string& parent=""):ObjectFilter(file, name, parent, "objectAttrFilter"){}
	virtual ~ObjectAttrFilter(){}
	/*
	Type of attribute to pass. The following are legal values:
	0 = All, 1 = Writable, 2 = Readable, 3 = Keyable,
	4 = Scale/Rotate/Translate, 5 = Has Expression, 6 = Has Curve,
	7 = Dynamic, 8 = Hidden.
	*/
	void setAttrType(unsigned int atyp){if(atyp == 1) return; fprintf_s(mFile, "setAttr \".atyp\" %i;\n", atyp);}
	/*
	Type of attribute to pass. The following are legal values:
	0 = All, 1 = Writable, 2 = Readable, 3 = Keyable,
	4 = Scale/Rotate/Translate, 5 = Has Expression, 6 = Has Curve,
	7 = Dynamic, 8 = Hidden.
	*/
	void setAttrType(const UnsignedintID& atyp){fprintf_s(mFile,"connectAttr \"");atyp.write(mFile);fprintf_s(mFile,"\" \"%s.atyp\";\n",mName.c_str());}
	/*
	Type of attribute to pass. The following are legal values:
	0 = All, 1 = Writable, 2 = Readable, 3 = Keyable,
	4 = Scale/Rotate/Translate, 5 = Has Expression, 6 = Has Curve,
	7 = Dynamic, 8 = Hidden.
	*/
	UnsignedintID getAttrType(){char buffer[4096];sprintf_s (buffer, "%s.atyp",mName.c_str());return (const char*)buffer;}
protected:
	ObjectAttrFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ObjectFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTATTRFILTER_H__
