/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	RenderLayerManager(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "renderLayerManager"){}
	virtual ~RenderLayerManager(){}
	void setCurrentRenderLayer(short crl)
	{
		if(crl == 0) return;
		fprintf(mFile,"setAttr \".crl\" %i;\n", crl);

	}
	void setRenderLayerId(size_t rlmi_i,short rlmi)
	{
		if(rlmi == 0) return;
		fprintf(mFile,"setAttr \".rlmi[%i]\" %i;\n", rlmi_i,rlmi);

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
	RenderLayerManager(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERLAYERMANAGER_H__
