/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMMESHCOM_H__
#define __MayaDM_CURVEFROMMESHCOM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromMesh.h"
namespace MayaDM
{
class CurveFromMeshCoM : public CurveFromMesh
{
public:
public:

	CurveFromMeshCoM():CurveFromMesh(){}
	CurveFromMeshCoM(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:CurveFromMesh(file, name, parent, "curveFromMeshCoM", shared, create){}
	virtual ~CurveFromMeshCoM(){}

	void getCurveOnMesh()const
	{
		fprintf(mFile,"\"%s.com\"",mName.c_str());
	}
protected:
	CurveFromMeshCoM(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:CurveFromMesh(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMMESHCOM_H__
