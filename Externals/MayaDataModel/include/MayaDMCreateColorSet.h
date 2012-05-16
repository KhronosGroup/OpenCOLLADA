/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CREATECOLORSET_H__
#define __MayaDM_CREATECOLORSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class CreateColorSet : public DependNode
{
public:
public:

	CreateColorSet():DependNode(){}
	CreateColorSet(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "createColorSet", shared, create){}
	virtual ~CreateColorSet(){}

	void setColorSetName(const string& colos)
	{
		if(colos == "NULL") return;
		fprintf(mFile,"\tsetAttr \".colos\" -type \"string\" ");
		colos.write(mFile);
		fprintf(mFile,";\n");
	}
	void setClamped(bool clam)
	{
		if(clam == true) return;
		fprintf(mFile,"\tsetAttr \".clam\" %i;\n", clam);
	}
	void setRepresentation(unsigned int rprt)
	{
		if(rprt == 3) return;
		fprintf(mFile,"\tsetAttr \".rprt\" %i;\n", rprt);
	}
	void getInputGeometry()const
	{
		fprintf(mFile,"\"%s.ig\"",mName.c_str());
	}
	void getOutputGeometry()const
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());
	}
	void getColorSetName()const
	{
		fprintf(mFile,"\"%s.colos\"",mName.c_str());
	}
	void getClamped()const
	{
		fprintf(mFile,"\"%s.clam\"",mName.c_str());
	}
	void getRepresentation()const
	{
		fprintf(mFile,"\"%s.rprt\"",mName.c_str());
	}
protected:
	CreateColorSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CREATECOLORSET_H__
