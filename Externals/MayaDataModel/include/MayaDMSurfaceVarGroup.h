/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACEVARGROUP_H__
#define __MayaDM_SURFACEVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseGeometryVarGroup.h"
namespace MayaDM
{
/*
This node will automatically create the transform/nurbsSurface pairs below
 it, depending on the number of surfaces it can evaluate at its input.  If
 the number of surfaces available at the input side increases, more
 transform/nurbsSurface pairs are created.  If the number decreases, the
 surfaces are made empty, but not removed.  Each of the newly created
 surfaces will be added to the default rendering shader group, rather
 than to the one that is current for the surface created prior and
 reassigned.
*/
class SurfaceVarGroup : public BaseGeometryVarGroup
{
public:
public:
	SurfaceVarGroup(FILE* file,const std::string& name,const std::string& parent=""):BaseGeometryVarGroup(file, name, parent, "surfaceVarGroup"){}
	virtual ~SurfaceVarGroup(){}
	/*The input surfaces*/
	void setCreate(size_t cr_i,const NurbsSurfaceID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i]\";\n",mName.c_str(),cr_i);}
	/*The output surfaces*/
	void setLocal(size_t l_i,const NurbsSurfaceID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l[%i]\";\n",mName.c_str(),l_i);}
	/*The input surfaces*/
	const NurbsSurfaceID& getCreate(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i]",mName.c_str(),cr_i);return (const char*)buffer;}
	/*The output surfaces*/
	const NurbsSurfaceID& getLocal(size_t l_i){char buffer[4096];sprintf_s (buffer, "%s.l[%i]",mName.c_str(),l_i);return (const char*)buffer;}
protected:
	SurfaceVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseGeometryVarGroup(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SURFACEVARGROUP_H__
