/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERLAYERMANAGER_H__
#define __MayaDM_RENDERLAYERMANAGER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RenderLayerManager : public DependNode
{
public:
public:
	RenderLayerManager():DependNode(){}
	RenderLayerManager(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderLayerManager"){}
	virtual ~RenderLayerManager(){}
	void setCurrentRenderLayer(short crl)
	{
		if(crl == 0) return;
		fprintf(mFile,"\tsetAttr \".crl\" %i;\n", crl);

	}
	void setRenderLayerId(size_t rlmi_i,short rlmi)
	{
		if(rlmi == 0) return;
		fprintf(mFile,"\tsetAttr \".rlmi[%i]\" %i;\n", rlmi_i,rlmi);

	}
	void setRenderLayerId(size_t rlmi_start,size_t rlmi_end,short* rlmi)
	{
		fprintf(mFile,"\tsetAttr \".rlmi[%i:%i]\" ", rlmi_start,rlmi_end);
		size_t size = (rlmi_end-rlmi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",rlmi[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startRenderLayerId(size_t rlmi_start,size_t rlmi_end)
	{
		fprintf(mFile,"\tsetAttr \".rlmi[%i:%i]\"",rlmi_start,rlmi_end);

	}
	void appendRenderLayerId(short rlmi)
	{
		fprintf(mFile," %i",rlmi);

	}
	void endRenderLayerId()
	{
		fprintf(mFile,";\n");

	}
	void getCurrentRenderLayer()
	{
		fprintf(mFile,"\"%s.crl\"",mName.c_str());

	}
	void getRenderLayerId(size_t rlmi_i)
	{
		fprintf(mFile,"\"%s.rlmi[%i]\"",mName.c_str(),rlmi_i);

	}
protected:
	RenderLayerManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERLAYERMANAGER_H__
