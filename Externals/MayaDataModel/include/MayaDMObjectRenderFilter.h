/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTRENDERFILTER_H__
#define __MayaDM_OBJECTRENDERFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMObjectFilter.h"
namespace MayaDM
{
class ObjectRenderFilter : public ObjectFilter
{
public:
public:

	ObjectRenderFilter():ObjectFilter(){}
	ObjectRenderFilter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ObjectFilter(file, name, parent, "objectRenderFilter", shared, create){}
	virtual ~ObjectRenderFilter(){}

	void setShaders(bool shad)
	{
		if(shad == 0) return;
		fprintf(mFile,"\tsetAttr \".shad\" %i;\n", shad);
	}
	void setTextures(bool txtr)
	{
		if(txtr == 0) return;
		fprintf(mFile,"\tsetAttr \".txtr\" %i;\n", txtr);
	}
	void setTextures2D(bool tx2d)
	{
		if(tx2d == 0) return;
		fprintf(mFile,"\tsetAttr \".tx2d\" %i;\n", tx2d);
	}
	void setTextures3D(bool tx3d)
	{
		if(tx3d == 0) return;
		fprintf(mFile,"\tsetAttr \".tx3d\" %i;\n", tx3d);
	}
	void setLights(bool lght)
	{
		if(lght == 0) return;
		fprintf(mFile,"\tsetAttr \".lght\" %i;\n", lght);
	}
	void setExclusiveLights(bool exlt)
	{
		if(exlt == 0) return;
		fprintf(mFile,"\tsetAttr \".exlt\" %i;\n", exlt);
	}
	void setNonExclusiveLights(bool nxlt)
	{
		if(nxlt == 0) return;
		fprintf(mFile,"\tsetAttr \".nxlt\" %i;\n", nxlt);
	}
	void setPostProcess(bool post)
	{
		if(post == 0) return;
		fprintf(mFile,"\tsetAttr \".post\" %i;\n", post);
	}
	void setUtility(bool util)
	{
		if(util == 0) return;
		fprintf(mFile,"\tsetAttr \".util\" %i;\n", util);
	}
	void setRenderableObjectSets(bool ros)
	{
		if(ros == 0) return;
		fprintf(mFile,"\tsetAttr \".ros\" %i;\n", ros);
	}
	void setLightSets(bool ls)
	{
		if(ls == 0) return;
		fprintf(mFile,"\tsetAttr \".ls\" %i;\n", ls);
	}
	void getShaders()const
	{
		fprintf(mFile,"\"%s.shad\"",mName.c_str());
	}
	void getTextures()const
	{
		fprintf(mFile,"\"%s.txtr\"",mName.c_str());
	}
	void getTextures2D()const
	{
		fprintf(mFile,"\"%s.tx2d\"",mName.c_str());
	}
	void getTextures3D()const
	{
		fprintf(mFile,"\"%s.tx3d\"",mName.c_str());
	}
	void getLights()const
	{
		fprintf(mFile,"\"%s.lght\"",mName.c_str());
	}
	void getExclusiveLights()const
	{
		fprintf(mFile,"\"%s.exlt\"",mName.c_str());
	}
	void getNonExclusiveLights()const
	{
		fprintf(mFile,"\"%s.nxlt\"",mName.c_str());
	}
	void getPostProcess()const
	{
		fprintf(mFile,"\"%s.post\"",mName.c_str());
	}
	void getUtility()const
	{
		fprintf(mFile,"\"%s.util\"",mName.c_str());
	}
	void getRenderableObjectSets()const
	{
		fprintf(mFile,"\"%s.ros\"",mName.c_str());
	}
	void getLightSets()const
	{
		fprintf(mFile,"\"%s.ls\"",mName.c_str());
	}
protected:
	ObjectRenderFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ObjectFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTRENDERFILTER_H__
