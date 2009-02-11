/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
	Light():Shape(){}
	Light(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "light"){}
	virtual ~Light(){}
	void setColor(const float3& cl)
	{
		if(cl == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".cl\" -type \"float3\" ");
		cl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float cr)
	{
		if(cr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl.cr\" %f;\n", cr);

	}
	void setColorG(float cg)
	{
		if(cg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl.cg\" %f;\n", cg);

	}
	void setColorB(float cb)
	{
		if(cb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl.cb\" %f;\n", cb);

	}
	void setIntensity(float in)
	{
		if(in == 1.0) return;
		fprintf(mFile,"\tsetAttr \".in\" %f;\n", in);

	}
	void setUseRayTraceShadows(bool urs)
	{
		if(urs == false) return;
		fprintf(mFile,"\tsetAttr \".urs\" %i;\n", urs);

	}
	void setShadowColor(const float3& sc)
	{
		if(sc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShadColorR(float scr)
	{
		if(scr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.scr\" %f;\n", scr);

	}
	void setShadColorG(float scg)
	{
		if(scg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.scg\" %f;\n", scg);

	}
	void setShadColorB(float scb)
	{
		if(scb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sc.scb\" %f;\n", scb);

	}
	void setShadowRays(short shr)
	{
		if(shr == 1) return;
		fprintf(mFile,"\tsetAttr \".shr\" %i;\n", shr);

	}
	void setRayDepthLimit(short rdl)
	{
		if(rdl == 1) return;
		fprintf(mFile,"\tsetAttr \".rdl\" %i;\n", rdl);

	}
	void setCenterOfIllumination(double col)
	{
		if(col == 5.0) return;
		fprintf(mFile,"\tsetAttr \".col\" %f;\n", col);

	}
	void setPointCamera(const float3& p)
	{
		if(p == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".p\" -type \"float3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPointCameraX(float px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.px\" %f;\n", px);

	}
	void setPointCameraY(float py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.py\" %f;\n", py);

	}
	void setPointCameraZ(float pz)
	{
		if(pz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.pz\" %f;\n", pz);

	}
	void setRenderState(int rdst)
	{
		if(rdst == 0) return;
		fprintf(mFile,"\tsetAttr \".rdst\" %i;\n", rdst);

	}
	void setLocatorScale(double lls)
	{
		if(lls == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lls\" %f;\n", lls);

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
	void getPointCamera()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPointCameraX()
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());

	}
	void getPointCameraY()
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());

	}
	void getPointCameraZ()
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());

	}
	void getMatrixWorldToEye()
	{
		fprintf(mFile,"\"%s.wte\"",mName.c_str());

	}
	void getMatrixEyeToWorld()
	{
		fprintf(mFile,"\"%s.etw\"",mName.c_str());

	}
	void getObjectId()
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());

	}
	void getPrimitiveId()
	{
		fprintf(mFile,"\"%s.pi\"",mName.c_str());

	}
	void getRaySampler()
	{
		fprintf(mFile,"\"%s.rts\"",mName.c_str());

	}
	void getRayDepth()
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());

	}
	void getRenderState()
	{
		fprintf(mFile,"\"%s.rdst\"",mName.c_str());

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
	Light(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Shape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LIGHT_H__
