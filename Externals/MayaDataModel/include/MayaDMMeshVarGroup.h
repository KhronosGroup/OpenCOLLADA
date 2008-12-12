/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MESHVARGROUP_H__
#define __MayaDM_MESHVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseGeometryVarGroup.h"
namespace MayaDM
{
/*
This node will automatically create the transform/mesh pairs below
 it, depending on the number of meshes it can evaluate at its input.  If
 the number of meshes available at the input side increases, more
 transform/mesh pairs are created.  If the number decreases, the
 meshes are made empty, but not removed.
*/
class MeshVarGroup : public BaseGeometryVarGroup
{
public:
public:
	MeshVarGroup(FILE* file,const std::string& name,const std::string& parent=""):BaseGeometryVarGroup(file, name, parent, "meshVarGroup"){}
	virtual ~MeshVarGroup(){}
	/*The input meshes*/
	void setCreate(size_t cr_i,const MeshID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i]\";\n",mName.c_str(),cr_i);}
	/*The output meshes*/
	void setLocal(size_t l_i,const MeshID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l[%i]\";\n",mName.c_str(),l_i);}
	/*The input meshes*/
	const MeshID& getCreate(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i]",mName.c_str(),cr_i);return (const char*)buffer;}
	/*The output meshes*/
	const MeshID& getLocal(size_t l_i){char buffer[4096];sprintf_s (buffer, "%s.l[%i]",mName.c_str(),l_i);return (const char*)buffer;}
protected:
	MeshVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseGeometryVarGroup(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MESHVARGROUP_H__
