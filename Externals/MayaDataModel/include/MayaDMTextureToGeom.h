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
	TextureToGeom(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "textureToGeom", shared, create){}
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
	void startSegGroupIds(size_t sgi_start,size_t sgi_end)const
	{
		fprintf(mFile,"\tsetAttr \".sgi[%i:%i]\"",sgi_start,sgi_end);
	}
	void appendSegGroupIds(int sgi)const
	{
		fprintf(mFile," %i",sgi);
	}
	void endSegGroupIds()const
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
	void getSegmentCount()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
	void getOutColorData(size_t ocd_i)const
	{
		fprintf(mFile,"\"%s.ocd[%i]\"",mName.c_str(),ocd_i);
	}
	void getOutColorData()const
	{

		fprintf(mFile,"\"%s.ocd\"",mName.c_str());
	}
	void getOutColor(size_t ocd_i)const
	{
		fprintf(mFile,"\"%s.ocd[%i].oc\"",mName.c_str(),ocd_i);
	}
	void getOutColor()const
	{

		fprintf(mFile,"\"%s.ocd.oc\"",mName.c_str());
	}
	void getOutColorR(size_t ocd_i)const
	{
		fprintf(mFile,"\"%s.ocd[%i].oc.ocr\"",mName.c_str(),ocd_i);
	}
	void getOutColorR()const
	{

		fprintf(mFile,"\"%s.ocd.oc.ocr\"",mName.c_str());
	}
	void getOutColorG(size_t ocd_i)const
	{
		fprintf(mFile,"\"%s.ocd[%i].oc.ocg\"",mName.c_str(),ocd_i);
	}
	void getOutColorG()const
	{

		fprintf(mFile,"\"%s.ocd.oc.ocg\"",mName.c_str());
	}
	void getOutColorB(size_t ocd_i)const
	{
		fprintf(mFile,"\"%s.ocd[%i].oc.ocb\"",mName.c_str(),ocd_i);
	}
	void getOutColorB()const
	{

		fprintf(mFile,"\"%s.ocd.oc.ocb\"",mName.c_str());
	}
	void getOutAlpha(size_t ocd_i)const
	{
		fprintf(mFile,"\"%s.ocd[%i].oa\"",mName.c_str(),ocd_i);
	}
	void getOutAlpha()const
	{

		fprintf(mFile,"\"%s.ocd.oa\"",mName.c_str());
	}
	void getOutSegFace(size_t ofm_i)const
	{
		fprintf(mFile,"\"%s.ofm[%i]\"",mName.c_str(),ofm_i);
	}
	void getOutSegFace()const
	{

		fprintf(mFile,"\"%s.ofm\"",mName.c_str());
	}
	void getSegGroupIds(size_t sgi_i)const
	{
		fprintf(mFile,"\"%s.sgi[%i]\"",mName.c_str(),sgi_i);
	}
	void getSegGroupIds()const
	{

		fprintf(mFile,"\"%s.sgi\"",mName.c_str());
	}
	void getInputMesh()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getInputMeshUVSet()const
	{
		fprintf(mFile,"\"%s.iuv\"",mName.c_str());
	}
	void getQuantize()const
	{
		fprintf(mFile,"\"%s.qut\"",mName.c_str());
	}
	void getQuantizeLevels()const
	{
		fprintf(mFile,"\"%s.qutl\"",mName.c_str());
	}
	void getMaxColorDiff()const
	{
		fprintf(mFile,"\"%s.mcd\"",mName.c_str());
	}
	void getMinSegmentSize()const
	{
		fprintf(mFile,"\"%s.msz\"",mName.c_str());
	}
	void getSpatialRadius()const
	{
		fprintf(mFile,"\"%s.spr\"",mName.c_str());
	}
	void getColorRange()const
	{
		fprintf(mFile,"\"%s.crng\"",mName.c_str());
	}
	void getImageFile()const
	{
		fprintf(mFile,"\"%s.if\"",mName.c_str());
	}
	void getMeshQuality()const
	{
		fprintf(mFile,"\"%s.mq\"",mName.c_str());
	}
	void getSurfaceOffset()const
	{
		fprintf(mFile,"\"%s.so\"",mName.c_str());
	}
	void getSmoothBoundary()const
	{
		fprintf(mFile,"\"%s.smbd\"",mName.c_str());
	}
	void getSmoothFactor()const
	{
		fprintf(mFile,"\"%s.smf\"",mName.c_str());
	}
	void getFitTolerance()const
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());
	}
	void getHardCornerDetect()const
	{
		fprintf(mFile,"\"%s.hcd\"",mName.c_str());
	}
	void getHardCornerMaxLength()const
	{
		fprintf(mFile,"\"%s.hcml\"",mName.c_str());
	}
	void getSimplifyBoundary()const
	{
		fprintf(mFile,"\"%s.smpl\"",mName.c_str());
	}
	void getSimplifyThreshold()const
	{
		fprintf(mFile,"\"%s.smpt\"",mName.c_str());
	}
	void getPointsOnBoundary()const
	{
		fprintf(mFile,"\"%s.pob\"",mName.c_str());
	}
	void getMaxPointsAdded()const
	{
		fprintf(mFile,"\"%s.mpa\"",mName.c_str());
	}
	void getShaderScript()const
	{
		fprintf(mFile,"\"%s.shs\"",mName.c_str());
	}
protected:
	TextureToGeom(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_TEXTURETOGEOM_H__
