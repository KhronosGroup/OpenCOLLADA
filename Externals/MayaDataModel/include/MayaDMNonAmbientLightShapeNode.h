/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NONAMBIENTLIGHTSHAPENODE_H__
#define __MayaDM_NONAMBIENTLIGHTSHAPENODE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRenderLight.h"
namespace MayaDM
{
class NonAmbientLightShapeNode : public RenderLight
{
public:
public:

	NonAmbientLightShapeNode():RenderLight(){}
	NonAmbientLightShapeNode(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:RenderLight(file, name, parent, "nonAmbientLightShapeNode", shared, create){}
	virtual ~NonAmbientLightShapeNode(){}

	void setDecayRate(unsigned int de)
	{
		if(de == 0) return;
		fprintf(mFile,"\tsetAttr \".de\" %i;\n", de);
	}
	void setEmitDiffuse(bool edi)
	{
		if(edi == true) return;
		fprintf(mFile,"\tsetAttr \".edi\" %i;\n", edi);
	}
	void setEmitSpecular(bool esp)
	{
		if(esp == true) return;
		fprintf(mFile,"\tsetAttr \".esp\" %i;\n", esp);
	}
	void getDecayRate()const
	{
		fprintf(mFile,"\"%s.de\"",mName.c_str());
	}
	void getEmitDiffuse()const
	{
		fprintf(mFile,"\"%s.edi\"",mName.c_str());
	}
	void getEmitSpecular()const
	{
		fprintf(mFile,"\"%s.esp\"",mName.c_str());
	}
protected:
	NonAmbientLightShapeNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:RenderLight(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NONAMBIENTLIGHTSHAPENODE_H__
