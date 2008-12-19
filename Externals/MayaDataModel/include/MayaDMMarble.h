/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MARBLE_H__
#define __MayaDM_MARBLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Marble : public Texture3d
{
public:
public:
	Marble(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "marble"){}
	virtual ~Marble(){}
	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"setAttr \".xpa\" %f;\n", xpa);

	}
	void setFillerColor(const float3& fc)
	{
		if(fc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".fc\" -type \"float3\" ");
		fc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFillerColorR(float fcr)
	{
		if(fcr == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fcr\" %f;\n", fcr);

	}
	void setFillerColorG(float fcg)
	{
		if(fcg == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fcg\" %f;\n", fcg);

	}
	void setFillerColorB(float fcb)
	{
		if(fcb == 0.0) return;
		fprintf(mFile,"setAttr \".fc.fcb\" %f;\n", fcb);

	}
	void setVeinColor(const float3& vc)
	{
		if(vc == float3(0.298f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".vc\" -type \"float3\" ");
		vc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVeinColorR(float vcr)
	{
		if(vcr == 0.0) return;
		fprintf(mFile,"setAttr \".vc.vcr\" %f;\n", vcr);

	}
	void setVeinColorG(float vcg)
	{
		if(vcg == 0.0) return;
		fprintf(mFile,"setAttr \".vc.vcg\" %f;\n", vcg);

	}
	void setVeinColorB(float vcb)
	{
		if(vcb == 0.0) return;
		fprintf(mFile,"setAttr \".vc.vcb\" %f;\n", vcb);

	}
	void setVeinWidth(float vw)
	{
		if(vw == 0.1) return;
		fprintf(mFile,"setAttr \".vw\" %f;\n", vw);

	}
	void setDiffusion(float di)
	{
		if(di == 0.5) return;
		fprintf(mFile,"setAttr \".di\" %f;\n", di);

	}
	void setContrast(float c)
	{
		if(c == 0.5) return;
		fprintf(mFile,"setAttr \".c\" %f;\n", c);

	}
	void setRipples(const float3& r)
	{
		if(r == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".r\" -type \"float3\" ");
		r.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRipplesX(float rx)
	{
		if(rx == 0.0) return;
		fprintf(mFile,"setAttr \".r.rx\" %f;\n", rx);

	}
	void setRipplesY(float ry)
	{
		if(ry == 0.0) return;
		fprintf(mFile,"setAttr \".r.ry\" %f;\n", ry);

	}
	void setRipplesZ(float rz)
	{
		if(rz == 0.0) return;
		fprintf(mFile,"setAttr \".r.rz\" %f;\n", rz);

	}
	void setDepth(const float2& d)
	{
		if(d == float2(0.0f,20.0f)) return;
		fprintf(mFile,"setAttr \".d\" -type \"float2\" ");
		d.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDepthMin(float dmn)
	{
		if(dmn == 0.0) return;
		fprintf(mFile,"setAttr \".d.dmn\" %f;\n", dmn);

	}
	void setDepthMax(float dmx)
	{
		if(dmx == 0.0) return;
		fprintf(mFile,"setAttr \".d.dmx\" %f;\n", dmx);

	}
	void setAmplitude(float a)
	{
		if(a == 1.5) return;
		fprintf(mFile,"setAttr \".a\" %f;\n", a);

	}
	void setRatio(float ra)
	{
		if(ra == 0.707) return;
		fprintf(mFile,"setAttr \".ra\" %f;\n", ra);

	}
	void getNormalCamera()
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());

	}
	void getNormalCameraX()
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());

	}
	void getNormalCameraY()
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());

	}
	void getNormalCameraZ()
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());

	}
	void getRefPointObj()
	{
		fprintf(mFile,"\"%s.rpo\"",mName.c_str());

	}
	void getRefPointObjX()
	{
		fprintf(mFile,"\"%s.rpo.rox\"",mName.c_str());

	}
	void getRefPointObjY()
	{
		fprintf(mFile,"\"%s.rpo.roy\"",mName.c_str());

	}
	void getRefPointObjZ()
	{
		fprintf(mFile,"\"%s.rpo.roz\"",mName.c_str());

	}
	void getRefPointCamera()
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());

	}
	void getRefPointCameraX()
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());

	}
	void getRefPointCameraY()
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());

	}
	void getRefPointCameraZ()
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());

	}
	void getFillerColor()
	{
		fprintf(mFile,"\"%s.fc\"",mName.c_str());

	}
	void getFillerColorR()
	{
		fprintf(mFile,"\"%s.fc.fcr\"",mName.c_str());

	}
	void getFillerColorG()
	{
		fprintf(mFile,"\"%s.fc.fcg\"",mName.c_str());

	}
	void getFillerColorB()
	{
		fprintf(mFile,"\"%s.fc.fcb\"",mName.c_str());

	}
	void getVeinColor()
	{
		fprintf(mFile,"\"%s.vc\"",mName.c_str());

	}
	void getVeinColorR()
	{
		fprintf(mFile,"\"%s.vc.vcr\"",mName.c_str());

	}
	void getVeinColorG()
	{
		fprintf(mFile,"\"%s.vc.vcg\"",mName.c_str());

	}
	void getVeinColorB()
	{
		fprintf(mFile,"\"%s.vc.vcb\"",mName.c_str());

	}
	void getVeinWidth()
	{
		fprintf(mFile,"\"%s.vw\"",mName.c_str());

	}
	void getDiffusion()
	{
		fprintf(mFile,"\"%s.di\"",mName.c_str());

	}
	void getContrast()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getRipples()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getRipplesX()
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());

	}
	void getRipplesY()
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());

	}
	void getRipplesZ()
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());

	}
	void getDepth()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getDepthMin()
	{
		fprintf(mFile,"\"%s.d.dmn\"",mName.c_str());

	}
	void getDepthMax()
	{
		fprintf(mFile,"\"%s.d.dmx\"",mName.c_str());

	}
	void getAmplitude()
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());

	}
	void getRatio()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
protected:
	Marble(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MARBLE_H__
