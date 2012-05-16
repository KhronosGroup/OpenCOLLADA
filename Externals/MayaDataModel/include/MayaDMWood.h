/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WOOD_H__
#define __MayaDM_WOOD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Wood : public Texture3d
{
public:
public:

	Wood():Texture3d(){}
	Wood(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture3d(file, name, parent, "wood", shared, create){}
	virtual ~Wood(){}

	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);
	}
	void setFillerColor(const float3& fc)
	{
		if(fc == float3(0.824f,0.627f,0.471f)) return;
		fprintf(mFile,"\tsetAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFillerColorR(float fcr)
	{
		if(fcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcr\" %f;\n", fcr);
	}
	void setFillerColorG(float fcg)
	{
		if(fcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcg\" %f;\n", fcg);
	}
	void setFillerColorB(float fcb)
	{
		if(fcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc.fcb\" %f;\n", fcb);
	}
	void setVeinColor(const float3& vc)
	{
		if(vc == float3(0.157f,0.078f,0.039f)) return;
		fprintf(mFile,"\tsetAttr \".vc\" -type \"float3\" ");
		vc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVeinColorR(float vcr)
	{
		if(vcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc.vcr\" %f;\n", vcr);
	}
	void setVeinColorG(float vcg)
	{
		if(vcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc.vcg\" %f;\n", vcg);
	}
	void setVeinColorB(float vcb)
	{
		if(vcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vc.vcb\" %f;\n", vcb);
	}
	void setVeinSpread(float v)
	{
		if(v == 0.25) return;
		fprintf(mFile,"\tsetAttr \".v\" %f;\n", v);
	}
	void setLayerSize(float ls)
	{
		if(ls == 0.05) return;
		fprintf(mFile,"\tsetAttr \".ls\" %f;\n", ls);
	}
	void setRandomness(float rd)
	{
		if(rd == 0.5) return;
		fprintf(mFile,"\tsetAttr \".rd\" %f;\n", rd);
	}
	void setAge(float a)
	{
		if(a == 20.0) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void setGrainColor(const float3& gc)
	{
		if(gc == float3(0.118f,0.039f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".gc\" -type \"float3\" ");
		gc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGrainColorR(float gcr)
	{
		if(gcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcr\" %f;\n", gcr);
	}
	void setGrainColorG(float gcg)
	{
		if(gcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcg\" %f;\n", gcg);
	}
	void setGrainColorB(float gcb)
	{
		if(gcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gc.gcb\" %f;\n", gcb);
	}
	void setGrainContrast(float gx)
	{
		if(gx == 0.5) return;
		fprintf(mFile,"\tsetAttr \".gx\" %f;\n", gx);
	}
	void setGrainSpacing(float gs)
	{
		if(gs == 0.01) return;
		fprintf(mFile,"\tsetAttr \".gs\" %f;\n", gs);
	}
	void setCenter(const float2& c)
	{
		if(c == float2(0.5f,-0.5f)) return;
		fprintf(mFile,"\tsetAttr \".c\" -type \"float2\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCenterU(float cu)
	{
		if(cu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cu\" %f;\n", cu);
	}
	void setCenterV(float cv)
	{
		if(cv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cv\" %f;\n", cv);
	}
	void setAmplitudeX(float ax)
	{
		if(ax == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ax\" %f;\n", ax);
	}
	void setAmplitudeY(float ay)
	{
		if(ay == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ay\" %f;\n", ay);
	}
	void setRatio(float ra)
	{
		if(ra == 0.35) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
	}
	void setRipples(const float3& r)
	{
		if(r == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".r\" -type \"float3\" ");
		r.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRipplesX(float rx)
	{
		if(rx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.rx\" %f;\n", rx);
	}
	void setRipplesY(float ry)
	{
		if(ry == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.ry\" %f;\n", ry);
	}
	void setRipplesZ(float rz)
	{
		if(rz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.rz\" %f;\n", rz);
	}
	void setDepth(const float2& d)
	{
		if(d == float2(0.0f,8.0f)) return;
		fprintf(mFile,"\tsetAttr \".d\" -type \"float2\" ");
		d.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDepthMin(float dmn)
	{
		if(dmn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dmn\" %f;\n", dmn);
	}
	void setDepthMax(float dmx)
	{
		if(dmx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".d.dmx\" %f;\n", dmx);
	}
	void getXPixelAngle()const
	{
		fprintf(mFile,"\"%s.xpa\"",mName.c_str());
	}
	void getNormalCamera()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalCameraX()const
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getNormalCameraY()const
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
	}
	void getRefPointObj()const
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());
	}
	void getRefPointObjX()const
	{
		fprintf(mFile,"\"%s.rpo.rox\"",mName.c_str());
	}
	void getRefPointObjY()const
	{
		fprintf(mFile,"\"%s.rpo.roy\"",mName.c_str());
	}
	void getRefPointObjZ()const
	{
		fprintf(mFile,"\"%s.rpo.roz\"",mName.c_str());
	}
	void getRefPointCamera()const
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());
	}
	void getRefPointCameraX()const
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());
	}
	void getRefPointCameraY()const
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());
	}
	void getRefPointCameraZ()const
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());
	}
	void getFillerColor()const
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getFillerColorR()const
	{
		fprintf(mFile,"\"%s.fc.fcr\"",mName.c_str());
	}
	void getFillerColorG()const
	{
		fprintf(mFile,"\"%s.fc.fcg\"",mName.c_str());
	}
	void getFillerColorB()const
	{
		fprintf(mFile,"\"%s.fc.fcb\"",mName.c_str());
	}
	void getVeinColor()const
	{
		fprintf(mFile,"\"%s.vc\"",mName.c_str());
	}
	void getVeinColorR()const
	{
		fprintf(mFile,"\"%s.vc.vcr\"",mName.c_str());
	}
	void getVeinColorG()const
	{
		fprintf(mFile,"\"%s.vc.vcg\"",mName.c_str());
	}
	void getVeinColorB()const
	{
		fprintf(mFile,"\"%s.vc.vcb\"",mName.c_str());
	}
	void getVeinSpread()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getLayerSize()const
	{
		fprintf(mFile,"\"%s.ls\"",mName.c_str());
	}
	void getRandomness()const
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());
	}
	void getAge()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getGrainColor()const
	{
		fprintf(mFile,"\"%s.gc\"",mName.c_str());
	}
	void getGrainColorR()const
	{
		fprintf(mFile,"\"%s.gc.gcr\"",mName.c_str());
	}
	void getGrainColorG()const
	{
		fprintf(mFile,"\"%s.gc.gcg\"",mName.c_str());
	}
	void getGrainColorB()const
	{
		fprintf(mFile,"\"%s.gc.gcb\"",mName.c_str());
	}
	void getGrainContrast()const
	{
		fprintf(mFile,"\"%s.gx\"",mName.c_str());
	}
	void getGrainSpacing()const
	{
		fprintf(mFile,"\"%s.gs\"",mName.c_str());
	}
	void getCenter()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getCenterU()const
	{
		fprintf(mFile,"\"%s.c.cu\"",mName.c_str());
	}
	void getCenterV()const
	{
		fprintf(mFile,"\"%s.c.cv\"",mName.c_str());
	}
	void getAmplitudeX()const
	{
		fprintf(mFile,"\"%s.ax\"",mName.c_str());
	}
	void getAmplitudeY()const
	{
		fprintf(mFile,"\"%s.ay\"",mName.c_str());
	}
	void getRatio()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getRipples()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getRipplesX()const
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());
	}
	void getRipplesY()const
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());
	}
	void getRipplesZ()const
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getDepthMin()const
	{
		fprintf(mFile,"\"%s.d.dmn\"",mName.c_str());
	}
	void getDepthMax()const
	{
		fprintf(mFile,"\"%s.d.dmx\"",mName.c_str());
	}
protected:
	Wood(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture3d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_WOOD_H__
