/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSUBDIVEDGE_H__
#define __MayaDM_CURVEFROMSUBDIVEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSubdiv.h"
namespace MayaDM
{
/*This node defines a NURBS curve that is compute from a subd edge.*/
class CurveFromSubdivEdge : public CurveFromSubdiv
{
public:
public:
	CurveFromSubdivEdge(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSubdiv(file, name, parent, "curveFromSubdivEdge"){}
	virtual ~CurveFromSubdivEdge(){}
	/*Left index for the edge*/
	void setEdgeIndexL(size_t eil_i,int eil){if(eil == 0) return; fprintf_s(mFile, "setAttr \".eil[%i]\" %i;\n", eil_i,eil);}
	/*Left index for the edge*/
	void setEdgeIndexL(size_t eil_i,const IntID& eil){fprintf_s(mFile,"connectAttr \"");eil.write(mFile);fprintf_s(mFile,"\" \"%s.eil[%i]\";\n",mName.c_str(),eil_i);}
	/*Right index for the edge*/
	void setEdgeIndexR(size_t eir_i,int eir){if(eir == 0) return; fprintf_s(mFile, "setAttr \".eir[%i]\" %i;\n", eir_i,eir);}
	/*Right index for the edge*/
	void setEdgeIndexR(size_t eir_i,const IntID& eir){fprintf_s(mFile,"connectAttr \"");eir.write(mFile);fprintf_s(mFile,"\" \"%s.eir[%i]\";\n",mName.c_str(),eir_i);}
	/*Left index for the edge*/
	const IntID& getEdgeIndexL(size_t eil_i){char buffer[4096];sprintf_s (buffer, "%s.eil[%i]",mName.c_str(),eil_i);return (const char*)buffer;}
	/*Right index for the edge*/
	const IntID& getEdgeIndexR(size_t eir_i){char buffer[4096];sprintf_s (buffer, "%s.eir[%i]",mName.c_str(),eir_i);return (const char*)buffer;}
protected:
	CurveFromSubdivEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromSubdiv(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSUBDIVEDGE_H__
