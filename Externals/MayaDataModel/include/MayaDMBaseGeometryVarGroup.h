/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BASEGEOMETRYVARGROUP_H__
#define __MayaDM_BASEGEOMETRYVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
Derived from a transform, this is a base class for the nodes that
 automatically create the children below them, depending on the number of
 inputs available on their input attribute (see derived classes.)
 <p/>
 After the connections have been made, it is necessary to trigger the initial
 creation by evaluating an output attribute of the var-group.  See the derived
 classes for the actual names of the attributes, but doing something like:
 getAttr varGroup1.local should do the trick.  Once there is at least one
 object created, changing the number of inputs to the var-group will
 cause the creation of the extra objects below it.
*/
class BaseGeometryVarGroup : public Transform
{
public:
public:
	BaseGeometryVarGroup(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "baseGeometryVarGroup"){}
	virtual ~BaseGeometryVarGroup(){}
	/*Maximal number of objects created so far*/
	void setMaxCreated(int mc){if(mc == -1) return; fprintf_s(mFile, "setAttr \".mc\" %i;\n", mc);}
	/*Maximal number of objects created so far*/
	void setMaxCreated(const IntID& mc){fprintf_s(mFile,"connectAttr \"");mc.write(mFile);fprintf_s(mFile,"\" \"%s.mc\";\n",mName.c_str());}
	/*Maximal number of objects created so far*/
	IntID getMaxCreated(){char buffer[4096];sprintf_s (buffer, "%s.mc",mName.c_str());return (const char*)buffer;}
protected:
	BaseGeometryVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BASEGEOMETRYVARGROUP_H__
