/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	FurGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "FurGlobals"){}
	virtual ~FurGlobals(){}
	void setRenderFur(bool rh)
	{
		if(rh == true) return;
		fprintf(mFile,"setAttr \".rh\" %i;\n", rh);

	}
	void setAreaValue(unsigned int av)
	{
		if(av == 2) return;
		fprintf(mFile,"setAttr \".av\" %i;\n", av);

	}
	void setEqualMap(short em)
	{
		if(em == 1) return;
		fprintf(mFile,"setAttr \".em\" %i;\n", em);

	}
	void setShadowFur(bool sh)
	{
		if(sh == true) return;
		fprintf(mFile,"setAttr \".sh\" %i;\n", sh);

	}
	void setCompFur(bool ch)
	{
		if(ch == true) return;
		fprintf(mFile,"setAttr \".ch\" %i;\n", ch);

	}
	void setReadFurFiles(bool rff)
	{
		if(rff == false) return;
		fprintf(mFile,"setAttr \".rff\" %i;\n", rff);

	}
	void setReadFurFilesPath(const string& rfp)
	{
		if(rfp == "n/a") return;
		fprintf(mFile,"setAttr \".rfp\" -type \"string\" ");
		rfp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setReadEqualMapPath(const string& rep)
	{
		if(rep == "n/a") return;
		fprintf(mFile,"setAttr \".rep\" -type \"string\" ");
		rep.write(mFile);
		fprintf(mFile,";\n");

	}
	void setReadShadowMap(bool rsm)
	{
		if(rsm == false) return;
		fprintf(mFile,"setAttr \".rsm\" %i;\n", rsm);

	}
	void setReadShadowMapPath(const string& rsp)
	{
		if(rsp == "n/a") return;
		fprintf(mFile,"setAttr \".rsp\" -type \"string\" ");
		rsp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setReadFurImage(bool rhi)
	{
		if(rhi == false) return;
		fprintf(mFile,"setAttr \".rhi\" %i;\n", rhi);

	}
	void setReadFurImagePath(const string& rhp)
	{
		if(rhp == "n/a") return;
		fprintf(mFile,"setAttr \".rhp\" -type \"string\" ");
		rhp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setProjectLocation(const string& pjl)
	{
		if(pjl == "n/a") return;
		fprintf(mFile,"setAttr \".pjl\" -type \"string\" ");
		pjl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setKeepIntermediateFiles(bool kif)
	{
		if(kif == false) return;
		fprintf(mFile,"setAttr \".kif\" %i;\n", kif);

	}
	void setKeepFurImages(bool kfi)
	{
		if(kfi == true) return;
		fprintf(mFile,"setAttr \".kfi\" %i;\n", kfi);

	}
	void setCopyAttrMaps(short cam)
	{
		if(cam == 0) return;
		fprintf(mFile,"setAttr \".cam\" %i;\n", cam);

	}
	void setFurPixelBufferSize(short fpsz)
	{
		if(fpsz == 5) return;
		fprintf(mFile,"setAttr \".fpsz\" %i;\n", fpsz);

	}
	void setShadowPixelBufferSize(short shsz)
	{
		if(shsz == 5) return;
		fprintf(mFile,"setAttr \".shsz\" %i;\n", shsz);

	}
	void setNurbsTesselation(short nts)
	{
		if(nts == 4) return;
		fprintf(mFile,"setAttr \".nts\" %i;\n", nts);

	}
	void setIncludePidInFilesName(bool ipid)
	{
		if(ipid == false) return;
		fprintf(mFile,"setAttr \".ipid\" %i;\n", ipid);

	}
	void setRenderFurImages(bool rfi)
	{
		if(rfi == true) return;
		fprintf(mFile,"setAttr \".rfi\" %i;\n", rfi);

	}
	void setRenderShadowMaps(bool rnsm)
	{
		if(rnsm == true) return;
		fprintf(mFile,"setAttr \".rnsm\" %i;\n", rnsm);

	}
	void setDisableGeometryRendering(bool dgr)
	{
		if(dgr == false) return;
		fprintf(mFile,"setAttr \".dgr\" %i;\n", dgr);

	}
	void getRenderFur()
	{
		fprintf(mFile,"\"%s.rh\"",mName.c_str());

	}
	void getAreaValue()
	{
		fprintf(mFile,"\"%s.av\"",mName.c_str());

	}
	void getEqualMap()
	{
		fprintf(mFile,"\"%s.em\"",mName.c_str());

	}
	void getShadowFur()
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());

	}
	void getCompFur()
	{
		fprintf(mFile,"\"%s.ch\"",mName.c_str());

	}
	void getReadFurFiles()
	{
		fprintf(mFile,"\"%s.rff\"",mName.c_str());

	}
	void getReadShadowMap()
	{
		fprintf(mFile,"\"%s.rsm\"",mName.c_str());

	}
	void getReadFurImage()
	{
		fprintf(mFile,"\"%s.rhi\"",mName.c_str());

	}
	void getProjectLocation()
	{
		fprintf(mFile,"\"%s.pjl\"",mName.c_str());

	}
	void getKeepIntermediateFiles()
	{
		fprintf(mFile,"\"%s.kif\"",mName.c_str());

	}
	void getKeepFurImages()
	{
		fprintf(mFile,"\"%s.kfi\"",mName.c_str());

	}
	void getCopyAttrMaps()
	{
		fprintf(mFile,"\"%s.cam\"",mName.c_str());

	}
	void getFurPixelBufferSize()
	{
		fprintf(mFile,"\"%s.fpsz\"",mName.c_str());

	}
	void getShadowPixelBufferSize()
	{
		fprintf(mFile,"\"%s.shsz\"",mName.c_str());

	}
	void getNurbsTesselation()
	{
		fprintf(mFile,"\"%s.nts\"",mName.c_str());

	}
	void getIncludePidInFilesName()
	{
		fprintf(mFile,"\"%s.ipid\"",mName.c_str());

	}
	void getRenderFurImages()
	{
		fprintf(mFile,"\"%s.rfi\"",mName.c_str());

	}
	void getRenderShadowMaps()
	{
		fprintf(mFile,"\"%s.rnsm\"",mName.c_str());

	}
	void getDisableGeometryRendering()
	{
		fprintf(mFile,"\"%s.dgr\"",mName.c_str());

	}
protected:
	FurGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURGLOBALS_H__
