/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	DisplacementShader():DependNode(){}
	DisplacementShader(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "displacementShader", shared, create){}
	virtual ~DisplacementShader(){}

	void setDisplacement(float d)
	{
		if(d == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void getDisplacement()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
protected:
	DisplacementShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DISPLACEMENTSHADER_H__
