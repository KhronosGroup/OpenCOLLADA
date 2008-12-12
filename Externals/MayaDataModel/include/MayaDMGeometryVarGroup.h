/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOMETRYVARGROUP_H__
#define __MayaDM_GEOMETRYVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseGeometryVarGroup.h"
namespace MayaDM
{
/*
A node that can create a child shape of mesh/nurbs curve/nurbs surface
 type, depending on the type of the input it accepts.  You are supposed
 to use the other nodes derived from baseGeometryVarGroup if the types
 of all the inputs are the same.
*/
class GeometryVarGroup : public BaseGeometryVarGroup
{
public:
public:
	GeometryVarGroup(FILE* file,const std::string& name,const std::string& parent=""):BaseGeometryVarGroup(file, name, parent, "geometryVarGroup"){}
	virtual ~GeometryVarGroup(){}
	/*The input geometry*/
	void setCreate(size_t cr_i,const GeometryID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i]\";\n",mName.c_str(),cr_i);}
	/*The output Geometry*/
	void setLocal(size_t l_i,const GeometryID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l[%i]\";\n",mName.c_str(),l_i);}
	/*The input geometry*/
	const GeometryID& getCreate(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i]",mName.c_str(),cr_i);return (const char*)buffer;}
	/*The output Geometry*/
	const GeometryID& getLocal(size_t l_i){char buffer[4096];sprintf_s (buffer, "%s.l[%i]",mName.c_str(),l_i);return (const char*)buffer;}
protected:
	GeometryVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseGeometryVarGroup(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYVARGROUP_H__
