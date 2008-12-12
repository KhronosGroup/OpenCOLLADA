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
/*This node defines a NURBS curve that is compute from a subd face.*/
class CurveFromSubdivFace : public CurveFromSubdiv
{
public:
public:
	CurveFromSubdivFace(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSubdiv(file, name, parent, "curveFromSubdivFace"){}
	virtual ~CurveFromSubdivFace(){}
	/*Left index for the face*/
	void setFaceIndexL(size_t fil_i,int fil){if(fil == 0) return; fprintf_s(mFile, "setAttr \".fil[%i]\" %i;\n", fil_i,fil);}
	/*Left index for the face*/
	void setFaceIndexL(size_t fil_i,const IntID& fil){fprintf_s(mFile,"connectAttr \"");fil.write(mFile);fprintf_s(mFile,"\" \"%s.fil[%i]\";\n",mName.c_str(),fil_i);}
	/*Right index for the face*/
	void setFaceIndexR(size_t fir_i,int fir){if(fir == 0) return; fprintf_s(mFile, "setAttr \".fir[%i]\" %i;\n", fir_i,fir);}
	/*Right index for the face*/
	void setFaceIndexR(size_t fir_i,const IntID& fir){fprintf_s(mFile,"connectAttr \"");fir.write(mFile);fprintf_s(mFile,"\" \"%s.fir[%i]\";\n",mName.c_str(),fir_i);}
	/*Left index for the face*/
	const IntID& getFaceIndexL(size_t fil_i){char buffer[4096];sprintf_s (buffer, "%s.fil[%i]",mName.c_str(),fil_i);return (const char*)buffer;}
	/*Right index for the face*/
	const IntID& getFaceIndexR(size_t fir_i){char buffer[4096];sprintf_s (buffer, "%s.fir[%i]",mName.c_str(),fir_i);return (const char*)buffer;}
protected:
	CurveFromSubdivFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromSubdiv(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSUBDIVFACE_H__
