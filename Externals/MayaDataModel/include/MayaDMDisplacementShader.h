/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DISPLACEMENTSHADER_H__
#define __MayaDM_DISPLACEMENTSHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DisplacementShader : public DependNode
{
public:
public:
	DisplacementShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "displacementShader"){}
	virtual ~DisplacementShader(){}
	void setDisplacement(float d)
	{
		if(d == 0.0) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void getDisplacement()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
protected:
	DisplacementShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISPLACEMENTSHADER_H__
