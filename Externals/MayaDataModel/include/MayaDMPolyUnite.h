/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYUNITE_H__
#define __MayaDM_POLYUNITE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyCreator.h"
namespace MayaDM
{
/*
This node creates a new poly object
 as a union of multiple polys.<p/>
*/
class PolyUnite : public PolyCreator
{
public:
public:
	PolyUnite(FILE* file,const std::string& name,const std::string& parent=""):PolyCreator(file, name, parent, "polyUnite"){}
	virtual ~PolyUnite(){}
	/*
	Attribute to specify if the old poly architecture needs to be used
	for the evaluation of this node. SHOULD NOT BE SET OR MODIFIED
	BY THE USER!!
	*/
	void setUseOldPolyArchitecture(bool uopa){if(uopa == false) return; fprintf_s(mFile, "setAttr \".uopa\" %i;\n", uopa);}
	/*
	The input polygonal objects, which are data meshes.
	You can connect mesh nodes to this attribute, or you can use
	MFnMeshData through the API.
	inputPoly is a multi-attribute.
	*/
	void setInputPoly(size_t ip_i,const MeshID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip[%i]\";\n",mName.c_str(),ip_i);}
	/*
	Input world transformation matrix. Also a multi-attribute. Each
	input poly object must have a corresponding inputMat.
	*/
	void setInputMat(size_t im_i,const MatrixID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im[%i]\";\n",mName.c_str(),im_i);}
	/*
	The input polygonal objects, which are data meshes.
	You can connect mesh nodes to this attribute, or you can use
	MFnMeshData through the API.
	inputPoly is a multi-attribute.
	*/
	const MeshID& getInputPoly(size_t ip_i){char buffer[4096];sprintf_s (buffer, "%s.ip[%i]",mName.c_str(),ip_i);return (const char*)buffer;}
	/*
	Input world transformation matrix. Also a multi-attribute. Each
	input poly object must have a corresponding inputMat.
	*/
	const MatrixID& getInputMat(size_t im_i){char buffer[4096];sprintf_s (buffer, "%s.im[%i]",mName.c_str(),im_i);return (const char*)buffer;}
protected:
	PolyUnite(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyCreator(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYUNITE_H__
