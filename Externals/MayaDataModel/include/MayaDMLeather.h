/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LEATHER_H__
#define __MayaDM_LEATHER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Leather : public Texture3d
{
public:
public:
	Leather(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "leather"){}
	virtual ~Leather(){}
	void setCellColor(const float3& ce)
	{
		if(ce == float3(0.373f,0.157f,0.059f)) return;
		fprintf(mFile,"setAttr \".ce\" -type \"float3\" ");
		ce.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCellColorR(float cer)
	{
		if(cer == 0.0) return;
		fprintf(mFile,"setAttr \".ce.cer\" %f;\n", cer);

	}
	void setCellColorG(float ceg)
	{
		if(ceg == 0.0) return;
		fprintf(mFile,"setAttr \".ce.ceg\" %f;\n", ceg);

	}
	void setCellColorB(float ceb)
	{
		if(ceb == 0.0) return;
		fprintf(mFile,"setAttr \".ce.ceb\" %f;\n", ceb);

	}
	void setCreaseColor(const float3& cr)
	{
		if(cr == float3(0.235f,0.118f,0.0f)) return;
		fprintf(mFile,"setAttr \".cr\" -type \"float3\" ");
		cr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCreaseColorR(float crr)
	{
		if(crr == 0.0) return;
		fprintf(mFile,"setAttr \".cr.crr\" %f;\n", crr);

	}
	void setCreaseColorG(float crg)
	{
		if(crg == 0.0) return;
		fprintf(mFile,"setAttr \".cr.crg\" %f;\n", crg);

	}
	void setCreaseColorB(float crb)
	{
		if(crb == 0.0) return;
		fprintf(mFile,"setAttr \".cr.crb\" %f;\n", crb);

	}
	void setCellSize(float cs)
	{
		if(cs == 0.5) return;
		fprintf(mFile,"setAttr \".cs\" %f;\n", cs);

	}
	void setDensity(float d)
	{
		if(d == 1.0) return;
		fprintf(mFile,"setAttr \".d\" %f;\n", d);

	}
	void setSpottyness(float s)
	{
		if(s == 0.1) return;
		fprintf(mFile,"setAttr \".s\" %f;\n", s);

	}
	void setRandomness(float r)
	{
		if(r == 0.5) return;
		fprintf(mFile,"setAttr \".r\" %f;\n", r);

	}
	void setThreshold(float th)
	{
		if(th == 0.83) return;
		fprintf(mFile,"setAttr \".th\" %f;\n", th);

	}
	void setCreases(bool c)
	{
		if(c == true) return;
		fprintf(mFile,"setAttr \".c\" %i;\n", c);

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
	void getCellColor()
	{
		fprintf(mFile,"\"%s.ce\"",mName.c_str());

	}
	void getCellColorR()
	{
		fprintf(mFile,"\"%s.ce.cer\"",mName.c_str());

	}
	void getCellColorG()
	{
		fprintf(mFile,"\"%s.ce.ceg\"",mName.c_str());

	}
	void getCellColorB()
	{
		fprintf(mFile,"\"%s.ce.ceb\"",mName.c_str());

	}
	void getCreaseColor()
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());

	}
	void getCreaseColorR()
	{
		fprintf(mFile,"\"%s.cr.crr\"",mName.c_str());

	}
	void getCreaseColorG()
	{
		fprintf(mFile,"\"%s.cr.crg\"",mName.c_str());

	}
	void getCreaseColorB()
	{
		fprintf(mFile,"\"%s.cr.crb\"",mName.c_str());

	}
	void getCellSize()
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());

	}
	void getDensity()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSpottyness()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getRandomness()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getThreshold()
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());

	}
	void getCreases()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
protected:
	Leather(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LEATHER_H__
