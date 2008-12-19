/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHT_H__
#define __MayaDM_LIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class Light : public Shape
{
public:
public:
	Light(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "light"){}
	virtual ~Light(){}
	void setColor(const float3& cl)
	{
		if(cl == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".cl\" -type \"float3\" ");
		cl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"setAttr \".cl.cr\" %f;\n", cr);

	}
	void setColorG(float cg)
	{
		if(cg == 0.0) return;
		fprintf(mFile,"setAttr \".cl.cg\" %f;\n", cg);

	}
	void setColorB(float cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"setAttr \".cl.cb\" %f;\n", cb);

	}
	void setIntensity(float in)
	{
		if(in == 1.0) return;
		fprintf(mFile,"setAttr \".in\" %f;\n", in);

	}
	void setUseRayTraceShadows(bool urs)
	{
		if(urs == false) return;
		fprintf(mFile,"setAttr \".urs\" %i;\n", urs);

	}
	void setShadowColor(const float3& sc)
	{
		if(sc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShadColorR(float scr)
	{
		if(scr == 0.0) return;
		fprintf(mFile,"setAttr \".sc.scr\" %f;\n", scr);

	}
	void setShadColorG(float scg)
	{
		if(scg == 0.0) return;
		fprintf(mFile,"setAttr \".sc.scg\" %f;\n", scg);

	}
	void setShadColorB(float scb)
	{
		if(scb == 0.0) return;
		fprintf(mFile,"setAttr \".sc.scb\" %f;\n", scb);

	}
	void setShadowRays(short shr)
	{
		if(shr == 1) return;
		fprintf(mFile,"setAttr \".shr\" %i;\n", shr);

	}
	void setRayDepthLimit(short rdl)
	{
		if(rdl == 1) return;
		fprintf(mFile,"setAttr \".rdl\" %i;\n", rdl);

	}
	void setCenterOfIllumination(double col)
	{
		if(col == 5.0) return;
		fprintf(mFile,"setAttr \".col\" %f;\n", col);

	}
	void setPointCamera(const float3& p)
	{
		if(p == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".p\" -type \"float3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPointCameraX(float px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"setAttr \".p.px\" %f;\n", px);

	}
	void setPointCameraY(float py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"setAttr \".p.py\" %f;\n", py);

	}
	void setPointCameraZ(float pz)
	{
		if(pz == 0.0) return;
		fprintf(mFile,"setAttr \".p.pz\" %f;\n", pz);

	}
	void setRenderState(int rdst)
	{
		if(rdst == 0) return;
		fprintf(mFile,"setAttr \".rdst\" %i;\n", rdst);

	}
	void setLocatorScale(double lls)
	{
		if(lls == 1.0) return;
		fprintf(mFile,"setAttr \".lls\" %f;\n", lls);

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());

	}
	void getColorR()
	{
		fprintf(mFile,"\"%s.cl.cr\"",mName.c_str());

	}
	void getColorG()
	{
		fprintf(mFile,"\"%s.cl.cg\"",mName.c_str());

	}
	void getColorB()
	{
		fprintf(mFile,"\"%s.cl.cb\"",mName.c_str());

	}
	void getIntensity()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getUseRayTraceShadows()
	{
		fprintf(mFile,"\"%s.urs\"",mName.c_str());

	}
	void getShadowColor()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getShadColorR()
	{
		fprintf(mFile,"\"%s.sc.scr\"",mName.c_str());

	}
	void getShadColorG()
	{
		fprintf(mFile,"\"%s.sc.scg\"",mName.c_str());

	}
	void getShadColorB()
	{
		fprintf(mFile,"\"%s.sc.scb\"",mName.c_str());

	}
	void getShadowRays()
	{
		fprintf(mFile,"\"%s.shr\"",mName.c_str());

	}
	void getRayDepthLimit()
	{
		fprintf(mFile,"\"%s.rdl\"",mName.c_str());

	}
	void getCenterOfIllumination()
	{
		fprintf(mFile,"\"%s.col\"",mName.c_str());

	}
	void getLocatorScale()
	{
		fprintf(mFile,"\"%s.lls\"",mName.c_str());

	}
	void getUvCoord()
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());

	}
	void getUCoord()
	{
		fprintf(mFile,"\"%s.uv.uu\"",mName.c_str());

	}
	void getVCoord()
	{
		fprintf(mFile,"\"%s.uv.vv\"",mName.c_str());

	}
	void getUvFilterSize()
	{
		fprintf(mFile,"\"%s.fq\"",mName.c_str());

	}
	void getUvFilterSizeX()
	{
		fprintf(mFile,"\"%s.fq.fsx\"",mName.c_str());

	}
	void getUvFilterSizeY()
	{
		fprintf(mFile,"\"%s.fq.fsy\"",mName.c_str());

	}
	void getInfoBits()
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());

	}
	void getLightData()
	{
		fprintf(mFile,"\"%s.ltd\"",mName.c_str());

	}
	void getLightDirection()
	{
		fprintf(mFile,"\"%s.ltd.ld\"",mName.c_str());

	}
	void getLightDirectionX()
	{
		fprintf(mFile,"\"%s.ltd.ld.ldx\"",mName.c_str());

	}
	void getLightDirectionY()
	{
		fprintf(mFile,"\"%s.ltd.ld.ldy\"",mName.c_str());

	}
	void getLightDirectionZ()
	{
		fprintf(mFile,"\"%s.ltd.ld.ldz\"",mName.c_str());

	}
	void getLightIntensity()
	{
		fprintf(mFile,"\"%s.ltd.li\"",mName.c_str());

	}
	void getLightIntensityR()
	{
		fprintf(mFile,"\"%s.ltd.li.lir\"",mName.c_str());

	}
	void getLightIntensityG()
	{
		fprintf(mFile,"\"%s.ltd.li.lig\"",mName.c_str());

	}
	void getLightIntensityB()
	{
		fprintf(mFile,"\"%s.ltd.li.lib\"",mName.c_str());

	}
	void getLightAmbient()
	{
		fprintf(mFile,"\"%s.ltd.la\"",mName.c_str());

	}
	void getLightDiffuse()
	{
		fprintf(mFile,"\"%s.ltd.ldf\"",mName.c_str());

	}
	void getLightSpecular()
	{
		fprintf(mFile,"\"%s.ltd.ls\"",mName.c_str());

	}
	void getLightShadowFraction()
	{
		fprintf(mFile,"\"%s.ltd.lsf\"",mName.c_str());

	}
	void getPreShadowIntensity()
	{
		fprintf(mFile,"\"%s.ltd.psi\"",mName.c_str());

	}
	void getLightBlindData()
	{
		fprintf(mFile,"\"%s.ltd.lbl\"",mName.c_str());

	}
	void getOpticalFXvisibility()
	{
		fprintf(mFile,"\"%s.ov\"",mName.c_str());

	}
	void getOpticalFXvisibilityR()
	{
		fprintf(mFile,"\"%s.ov.ovr\"",mName.c_str());

	}
	void getOpticalFXvisibilityG()
	{
		fprintf(mFile,"\"%s.ov.ovg\"",mName.c_str());

	}
	void getOpticalFXvisibilityB()
	{
		fprintf(mFile,"\"%s.ov.ovb\"",mName.c_str());

	}
protected:
	Light(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LIGHT_H__
