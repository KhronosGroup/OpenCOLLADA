/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVTONURBS_H__
#define __MayaDM_SUBDIVTONURBS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
*/
class SubdivToNurbs : public AbstractBaseCreate
{
public:
public:
	SubdivToNurbs(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "subdivToNurbs"){}
	virtual ~SubdivToNurbs(){}
	/*The resulting nurbs surfaces*/
	void setOutputSurfaces(size_t os_i,const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i]\";\n",mName.c_str(),os_i);}
	/*
	Output surface type.
	0 - NURBS
	1 - Beziers
	Output surfaces are degree 3. The NURBS option tries to generate
	the minimal number of NURBS surfaces. The Bezier option converts
	each face on the subdiv into a separate Bezier surface.
	*/
	void setOutputType(unsigned int ot){if(ot == 0) return; fprintf_s(mFile, "setAttr \".ot\" %i;\n", ot);}
	/*
	Output surface type.
	0 - NURBS
	1 - Beziers
	Output surfaces are degree 3. The NURBS option tries to generate
	the minimal number of NURBS surfaces. The Bezier option converts
	each face on the subdiv into a separate Bezier surface.
	*/
	void setOutputType(const UnsignedintID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*
	If true, the matrix on the input geometry is applied to the object
	and the resulting geometry will have identity matrix on it.  If false
	the conversion is done on the local space object and the resulting
	geometry has the matrix of the input object on it.
	*/
	void setApplyMatrixToResult(bool amr){if(amr == true) return; fprintf_s(mFile, "setAttr \".amr\" %i;\n", amr);}
	/*
	If true, the matrix on the input geometry is applied to the object
	and the resulting geometry will have identity matrix on it.  If false
	the conversion is done on the local space object and the resulting
	geometry has the matrix of the input object on it.
	*/
	void setApplyMatrixToResult(const BoolID& amr){fprintf_s(mFile,"connectAttr \"");amr.write(mFile);fprintf_s(mFile,"\" \"%s.amr\";\n",mName.c_str());}
	/*The resulting nurbs surfaces*/
	const NurbsSurfaceID& getOutputSurfaces(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i]",mName.c_str(),os_i);return (const char*)buffer;}
	/*
	Output surface type.
	0 - NURBS
	1 - Beziers
	Output surfaces are degree 3. The NURBS option tries to generate
	the minimal number of NURBS surfaces. The Bezier option converts
	each face on the subdiv into a separate Bezier surface.
	*/
	UnsignedintID getOutputType(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*
	If true, the matrix on the input geometry is applied to the object
	and the resulting geometry will have identity matrix on it.  If false
	the conversion is done on the local space object and the resulting
	geometry has the matrix of the input object on it.
	*/
	BoolID getApplyMatrixToResult(){char buffer[4096];sprintf_s (buffer, "%s.amr",mName.c_str());return (const char*)buffer;}
protected:
	SubdivToNurbs(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVTONURBS_H__
