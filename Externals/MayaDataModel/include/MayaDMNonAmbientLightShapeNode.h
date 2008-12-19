/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	NonAmbientLightShapeNode(FILE* file,const std::string& name,const std::string& parent=""):RenderLight(file, name, parent, "nonAmbientLightShapeNode"){}
	virtual ~NonAmbientLightShapeNode(){}
	void setDecayRate(unsigned int de)
	{
		if(de == 0) return;
		fprintf(mFile,"setAttr \".de\" %i;\n", de);

	}
	void setEmitDiffuse(bool edi)
	{
		if(edi == true) return;
		fprintf(mFile,"setAttr \".edi\" %i;\n", edi);

	}
	void setEmitSpecular(bool esp)
	{
		if(esp == true) return;
		fprintf(mFile,"setAttr \".esp\" %i;\n", esp);

	}
	void getEmitDiffuse()
	{
		fprintf(mFile,"\"%s.edi\"",mName.c_str());

	}
	void getEmitSpecular()
	{
		fprintf(mFile,"\"%s.esp\"",mName.c_str());

	}
protected:
	NonAmbientLightShapeNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):RenderLight(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_NONAMBIENTLIGHTSHAPENODE_H__
