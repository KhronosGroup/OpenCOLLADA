/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TEXTURETOGEOM_H__
#define __MayaDM_TEXTURETOGEOM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class TextureToGeom : public DependNode
{
public:
	struct OutColorData{
		void write(FILE* file) const
		{
		}
	};
public:
	TextureToGeom():DependNode(){}
	TextureToGeom(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "textureToGeom"){}
	virtual ~TextureToGeom(){}
	void setSegGroupIds(size_t sgi_i,int sgi)
	{
		if(sgi == -1) return;
		fprintf(mFile,"\tsetAttr \".sgi[%i]\" %i;\n", sgi_i,sgi);

	}
	void setSegGroupIds(size_t sgi_start,size_t sgi_end,int* sgi)
	{
		fprintf(mFile,"\tsetAttr \".sgi[%i:%i]\" ", sgi_start,sgi_end);
		size_t size = (sgi_end-sgi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",sgi[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startSegGroupIds(size_t sgi_start,size_t sgi_end)
	{
		fprintf(mFile,"\tsetAttr \".sgi[%i:%i]\"",sgi_start,sgi_end);

	}
	void appendSegGroupIds(int sgi)
	{
		fprintf(mFile," %i",sgi);

	}
	void endSegGroupIds()
	{
		fprintf(mFile,";\n");

	}
	void setInputMesh(const mesh& im)
	{
		fprintf(mFile,"\tsetAttr \".im\" -type \"mesh\" ");
		im.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputMeshUVSet(const string& iuv)
	{
		if(iuv == "NULL") return;
		fprintf(mFile,"\tsetAttr \".iuv\" -type \"string\" ");
		iuv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setQuantize(bool qut)
	{
		if(qut == 0) return;
		fprintf(mFile,"\tsetAttr \".qut\" %i;\n", qut);

	}
	void setQuantizeLevels(unsigned char qutl)
	{
		if(qutl == 10) return;
		fprintf(mFile,"\tsetAttr \".qutl\" %i;\n", qutl);

	}
	void setMaxColorDiff(float mcd)
	{
		if(mcd == 0.125) return;
		fprintf(mFile,"\tsetAttr \".mcd\" %f;\n", mcd);

	}
	void setMinSegmentSize(float msz)
	{
		if(msz == 0.005) return;
		fprintf(mFile,"\tsetAttr \".msz\" %f;\n", msz);

	}
	void setSpatialRadius(int spr)
	{
		if(spr == 7) return;
		fprintf(mFile,"\tsetAttr \".spr\" %i;\n", spr);

	}
	void setColorRange(float crng)
	{
		if(crng == 4.5) return;
		fprintf(mFile,"\tsetAttr \".crng\" %f;\n", crng);

	}
	void setImageFile(const string& if_)
	{
		if(if_ == "NULL") return;
		fprintf(mFile,"\tsetAttr \".if\" -type \"string\" ");
		if_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMeshQuality(double mq)
	{
		if(mq == 0.1) return;
		fprintf(mFile,"\tsetAttr \".mq\" %f;\n", mq);

	}
	void setSurfaceOffset(float so)
	{
		if(so == 0.01) return;
		fprintf(mFile,"\tsetAttr \".so\" %f;\n", so);

	}
	void setSmoothBoundary(bool smbd)
	{
		if(smbd == 1) return;
		fprintf(mFile,"\tsetAttr \".smbd\" %i;\n", smbd);

	}
	void setSmoothFactor(float smf)
	{
		if(smf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".smf\" %f;\n", smf);

	}
	void setFitTolerance(float ft)
	{
		if(ft == 0.007) return;
		fprintf(mFile,"\tsetAttr \".ft\" %f;\n", ft);

	}
	void setHardCornerDetect(bool hcd)
	{
		if(hcd == 1) return;
		fprintf(mFile,"\tsetAttr \".hcd\" %i;\n", hcd);

	}
	void setHardCornerMaxLength(float hcml)
	{
		if(hcml == 10.0) return;
		fprintf(mFile,"\tsetAttr \".hcml\" %f;\n", hcml);

	}
	void setSimplifyBoundary(bool smpl)
	{
		if(smpl == 1) return;
		fprintf(mFile,"\tsetAttr \".smpl\" %i;\n", smpl);

	}
	void setSimplifyThreshold(double smpt)
	{
		if(smpt == 0) return;
		fprintf(mFile,"\tsetAttr \".smpt\" %f;\n", smpt);

	}
	void setPointsOnBoundary(bool pob)
	{
		if(pob == 0) return;
		fprintf(mFile,"\tsetAttr \".pob\" %i;\n", pob);

	}
	void setMaxPointsAdded(int mpa)
	{
		if(mpa == 0) return;
		fprintf(mFile,"\tsetAttr \".mpa\" %i;\n", mpa);

	}
	void setShaderScript(const string& shs)
	{
		if(shs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".shs\" -type \"string\" ");
		shs.write(mFile);
		fprintf(mFile,";\n");

	}
	void getSegmentCount()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());

	}
	void getOutColorData(size_t ocd_i)
	{
		fprintf(mFile,"\"%s.ocd[%i]\"",mName.c_str(),ocd_i);

	}
	void getOutColor(size_t ocd_i)
	{
		fprintf(mFile,"\"%s.ocd[%i].oc\"",mName.c_str(),ocd_i);

	}
	void getOutColorR(size_t ocd_i)
	{
		fprintf(mFile,"\"%s.ocd[%i].oc.ocr\"",mName.c_str(),ocd_i);

	}
	void getOutColorG(size_t ocd_i)
	{
		fprintf(mFile,"\"%s.ocd[%i].oc.ocg\"",mName.c_str(),ocd_i);

	}
	void getOutColorB(size_t ocd_i)
	{
		fprintf(mFile,"\"%s.ocd[%i].oc.ocb\"",mName.c_str(),ocd_i);

	}
	void getOutAlpha(size_t ocd_i)
	{
		fprintf(mFile,"\"%s.ocd[%i].oa\"",mName.c_str(),ocd_i);

	}
	void getOutSegFace(size_t ofm_i)
	{
		fprintf(mFile,"\"%s.ofm[%i]\"",mName.c_str(),ofm_i);

	}
	void getSegGroupIds(size_t sgi_i)
	{
		fprintf(mFile,"\"%s.sgi[%i]\"",mName.c_str(),sgi_i);

	}
	void getInputMesh()
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());

	}
	void getInputMeshUVSet()
	{
		fprintf(mFile,"\"%s.iuv\"",mName.c_str());

	}
	void getQuantize()
	{
		fprintf(mFile,"\"%s.qut\"",mName.c_str());

	}
	void getQuantizeLevels()
	{
		fprintf(mFile,"\"%s.qutl\"",mName.c_str());

	}
	void getMaxColorDiff()
	{
		fprintf(mFile,"\"%s.mcd\"",mName.c_str());

	}
	void getMinSegmentSize()
	{
		fprintf(mFile,"\"%s.msz\"",mName.c_str());

	}
	void getSpatialRadius()
	{
		fprintf(mFile,"\"%s.spr\"",mName.c_str());

	}
	void getColorRange()
	{
		fprintf(mFile,"\"%s.crng\"",mName.c_str());

	}
	void getImageFile()
	{
		fprintf(mFile,"\"%s.if\"",mName.c_str());

	}
	void getMeshQuality()
	{
		fprintf(mFile,"\"%s.mq\"",mName.c_str());

	}
	void getSurfaceOffset()
	{
		fprintf(mFile,"\"%s.so\"",mName.c_str());

	}
	void getSmoothBoundary()
	{
		fprintf(mFile,"\"%s.smbd\"",mName.c_str());

	}
	void getSmoothFactor()
	{
		fprintf(mFile,"\"%s.smf\"",mName.c_str());

	}
	void getFitTolerance()
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());

	}
	void getHardCornerDetect()
	{
		fprintf(mFile,"\"%s.hcd\"",mName.c_str());

	}
	void getHardCornerMaxLength()
	{
		fprintf(mFile,"\"%s.hcml\"",mName.c_str());

	}
	void getSimplifyBoundary()
	{
		fprintf(mFile,"\"%s.smpl\"",mName.c_str());

	}
	void getSimplifyThreshold()
	{
		fprintf(mFile,"\"%s.smpt\"",mName.c_str());

	}
	void getPointsOnBoundary()
	{
		fprintf(mFile,"\"%s.pob\"",mName.c_str());

	}
	void getMaxPointsAdded()
	{
		fprintf(mFile,"\"%s.mpa\"",mName.c_str());

	}
	void getShaderScript()
	{
		fprintf(mFile,"\"%s.shs\"",mName.c_str());

	}
protected:
	TextureToGeom(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TEXTURETOGEOM_H__
