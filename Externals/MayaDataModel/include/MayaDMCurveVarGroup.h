/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEVARGROUP_H__
#define __MayaDM_CURVEVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseGeometryVarGroup.h"
namespace MayaDM
{
/*
This node will automatically create the transform/nurbsCurve pairs below
 it, depending on the number of curves it can evaluate at its input.  If
 the number of curves available at the input side increases, more
 transform/nurbsCurve pairs are created.  If the number decreases, the
 curves are made empty, but not removed.
*/
class CurveVarGroup : public BaseGeometryVarGroup
{
public:
public:
	CurveVarGroup(FILE* file,const std::string& name,const std::string& parent=""):BaseGeometryVarGroup(file, name, parent, "curveVarGroup"){}
	virtual ~CurveVarGroup(){}
	/*The input curves*/
	void setCreate(size_t cr_i,const NurbsCurveID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i]\";\n",mName.c_str(),cr_i);}
	/*The output curves*/
	void setLocal(size_t l_i,const NurbsCurveID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l[%i]\";\n",mName.c_str(),l_i);}
	/*Display smoothness of the resulting curves*/
	void setDisplaySmoothness(int ds){if(ds == -1) return; fprintf_s(mFile, "setAttr \".ds\" %i;\n", ds);}
	/*Display smoothness of the resulting curves*/
	void setDisplaySmoothness(const IntID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*The input curves*/
	const NurbsCurveID& getCreate(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i]",mName.c_str(),cr_i);return (const char*)buffer;}
	/*The output curves*/
	const NurbsCurveID& getLocal(size_t l_i){char buffer[4096];sprintf_s (buffer, "%s.l[%i]",mName.c_str(),l_i);return (const char*)buffer;}
	/*Display smoothness of the resulting curves*/
	IntID getDisplaySmoothness(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
protected:
	CurveVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseGeometryVarGroup(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEVARGROUP_H__
