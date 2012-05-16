/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURGLOBALS_H__
#define __MayaDM_FURGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class FurGlobals : public DependNode
{
public:
public:

	FurGlobals():DependNode(){}
	FurGlobals(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "FurGlobals", shared, create){}
	virtual ~FurGlobals(){}

	void setRenderFur(bool rh)
	{
		if(rh == true) return;
		fprintf(mFile,"\tsetAttr \".rh\" %i;\n", rh);
	}
	void setAreaValue(unsigned int av)
	{
		if(av == 2) return;
		fprintf(mFile,"\tsetAttr \".av\" %i;\n", av);
	}
	void setEqualMap(short em)
	{
		if(em == 1) return;
		fprintf(mFile,"\tsetAttr \".em\" %i;\n", em);
	}
	void setShadowFur(bool sh)
	{
		if(sh == true) return;
		fprintf(mFile,"\tsetAttr \".sh\" %i;\n", sh);
	}
	void setCompFur(bool ch)
	{
		if(ch == true) return;
		fprintf(mFile,"\tsetAttr \".ch\" %i;\n", ch);
	}
	void setReadFurFiles(bool rff)
	{
		if(rff == false) return;
		fprintf(mFile,"\tsetAttr \".rff\" %i;\n", rff);
	}
	void setReadFurFilesPath(const string& rfp)
	{
		if(rfp == "n/a") return;
		fprintf(mFile,"\tsetAttr \".rfp\" -type \"string\" ");
		rfp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setReadEqualMapPath(const string& rep)
	{
		if(rep == "n/a") return;
		fprintf(mFile,"\tsetAttr \".rep\" -type \"string\" ");
		rep.write(mFile);
		fprintf(mFile,";\n");
	}
	void setReadShadowMap(bool rsm)
	{
		if(rsm == false) return;
		fprintf(mFile,"\tsetAttr \".rsm\" %i;\n", rsm);
	}
	void setReadShadowMapPath(const string& rsp)
	{
		if(rsp == "n/a") return;
		fprintf(mFile,"\tsetAttr \".rsp\" -type \"string\" ");
		rsp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setReadFurImage(bool rhi)
	{
		if(rhi == false) return;
		fprintf(mFile,"\tsetAttr \".rhi\" %i;\n", rhi);
	}
	void setReadFurImagePath(const string& rhp)
	{
		if(rhp == "n/a") return;
		fprintf(mFile,"\tsetAttr \".rhp\" -type \"string\" ");
		rhp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setProjectLocation(const string& pjl)
	{
		if(pjl == "n/a") return;
		fprintf(mFile,"\tsetAttr \".pjl\" -type \"string\" ");
		pjl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setKeepIntermediateFiles(bool kif)
	{
		if(kif == false) return;
		fprintf(mFile,"\tsetAttr \".kif\" %i;\n", kif);
	}
	void setKeepFurImages(bool kfi)
	{
		if(kfi == true) return;
		fprintf(mFile,"\tsetAttr \".kfi\" %i;\n", kfi);
	}
	void setCopyAttrMaps(short cam)
	{
		if(cam == 0) return;
		fprintf(mFile,"\tsetAttr \".cam\" %i;\n", cam);
	}
	void setFurPixelBufferSize(short fpsz)
	{
		if(fpsz == 5) return;
		fprintf(mFile,"\tsetAttr \".fpsz\" %i;\n", fpsz);
	}
	void setShadowPixelBufferSize(short shsz)
	{
		if(shsz == 5) return;
		fprintf(mFile,"\tsetAttr \".shsz\" %i;\n", shsz);
	}
	void setNurbsTesselation(short nts)
	{
		if(nts == 4) return;
		fprintf(mFile,"\tsetAttr \".nts\" %i;\n", nts);
	}
	void setIncludePidInFilesName(bool ipid)
	{
		if(ipid == false) return;
		fprintf(mFile,"\tsetAttr \".ipid\" %i;\n", ipid);
	}
	void setRenderFurImages(bool rfi)
	{
		if(rfi == true) return;
		fprintf(mFile,"\tsetAttr \".rfi\" %i;\n", rfi);
	}
	void setRenderShadowMaps(bool rnsm)
	{
		if(rnsm == true) return;
		fprintf(mFile,"\tsetAttr \".rnsm\" %i;\n", rnsm);
	}
	void setDisableGeometryRendering(bool dgr)
	{
		if(dgr == false) return;
		fprintf(mFile,"\tsetAttr \".dgr\" %i;\n", dgr);
	}
	void getRenderFur()const
	{
		fprintf(mFile,"\"%s.rh\"",mName.c_str());
	}
	void getAreaValue()const
	{
		fprintf(mFile,"\"%s.av\"",mName.c_str());
	}
	void getEqualMap()const
	{
		fprintf(mFile,"\"%s.em\"",mName.c_str());
	}
	void getShadowFur()const
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());
	}
	void getCompFur()const
	{
		fprintf(mFile,"\"%s.ch\"",mName.c_str());
	}
	void getReadFurFiles()const
	{
		fprintf(mFile,"\"%s.rff\"",mName.c_str());
	}
	void getReadFurFilesPath()const
	{
		fprintf(mFile,"\"%s.rfp\"",mName.c_str());
	}
	void getReadEqualMapPath()const
	{
		fprintf(mFile,"\"%s.rep\"",mName.c_str());
	}
	void getReadShadowMap()const
	{
		fprintf(mFile,"\"%s.rsm\"",mName.c_str());
	}
	void getReadShadowMapPath()const
	{
		fprintf(mFile,"\"%s.rsp\"",mName.c_str());
	}
	void getReadFurImage()const
	{
		fprintf(mFile,"\"%s.rhi\"",mName.c_str());
	}
	void getReadFurImagePath()const
	{
		fprintf(mFile,"\"%s.rhp\"",mName.c_str());
	}
	void getProjectLocation()const
	{
		fprintf(mFile,"\"%s.pjl\"",mName.c_str());
	}
	void getHairDescriptions()const
	{
		fprintf(mFile,"\"%s.hdc\"",mName.c_str());
	}
	void getAttractorSets()const
	{
		fprintf(mFile,"\"%s.asc\"",mName.c_str());
	}
	void getFurNodeList()const
	{
		fprintf(mFile,"\"%s.fnl\"",mName.c_str());
	}
	void getKeepIntermediateFiles()const
	{
		fprintf(mFile,"\"%s.kif\"",mName.c_str());
	}
	void getKeepFurImages()const
	{
		fprintf(mFile,"\"%s.kfi\"",mName.c_str());
	}
	void getCopyAttrMaps()const
	{
		fprintf(mFile,"\"%s.cam\"",mName.c_str());
	}
	void getFurPixelBufferSize()const
	{
		fprintf(mFile,"\"%s.fpsz\"",mName.c_str());
	}
	void getShadowPixelBufferSize()const
	{
		fprintf(mFile,"\"%s.shsz\"",mName.c_str());
	}
	void getNurbsTesselation()const
	{
		fprintf(mFile,"\"%s.nts\"",mName.c_str());
	}
	void getIncludePidInFilesName()const
	{
		fprintf(mFile,"\"%s.ipid\"",mName.c_str());
	}
	void getRenderFurImages()const
	{
		fprintf(mFile,"\"%s.rfi\"",mName.c_str());
	}
	void getRenderShadowMaps()const
	{
		fprintf(mFile,"\"%s.rnsm\"",mName.c_str());
	}
	void getDisableGeometryRendering()const
	{
		fprintf(mFile,"\"%s.dgr\"",mName.c_str());
	}
protected:
	FurGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURGLOBALS_H__
