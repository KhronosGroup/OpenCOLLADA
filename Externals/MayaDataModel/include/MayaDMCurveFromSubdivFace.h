/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSUBDIVFACE_H__
#define __MayaDM_CURVEFROMSUBDIVFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSubdiv.h"
namespace MayaDM
{
class CurveFromSubdivFace : public CurveFromSubdiv
{
public:
public:
	CurveFromSubdivFace(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSubdiv(file, name, parent, "curveFromSubdivFace"){}
	virtual ~CurveFromSubdivFace(){}
	void setFaceIndexL(size_t fil_i,int fil)
	{
		if(fil == 0) return;
		fprintf(mFile,"setAttr \".fil[%i]\" %i;\n", fil_i,fil);

	}
	void setFaceIndexR(size_t fir_i,int fir)
	{
		if(fir == 0) return;
		fprintf(mFile,"setAttr \".fir[%i]\" %i;\n", fir_i,fir);

	}
	void getFaceIndexL(size_t fil_i)
	{
		fprintf(mFile,"\"%s.fil[%i]\"",mName.c_str(),fil_i);

	}
	void getFaceIndexR(size_t fir_i)
	{
		fprintf(mFile,"\"%s.fir[%i]\"",mName.c_str(),fir_i);

	}
protected:
	CurveFromSubdivFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromSubdiv(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSUBDIVFACE_H__
