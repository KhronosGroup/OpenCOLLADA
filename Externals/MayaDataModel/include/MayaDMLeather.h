/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Leather():Texture3d(){}
	Leather(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture3d(file, name, parent, "leather", shared, create){}
	virtual ~Leather(){}

	void setCellColor(const float3& ce)
	{
		if(ce == float3(0.373f,0.157f,0.059f)) return;
		fprintf(mFile,"\tsetAttr \".ce\" -type \"float3\" ");
		ce.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCellColorR(float cer)
	{
		if(cer == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ce.cer\" %f;\n", cer);
	}
	void setCellColorG(float ceg)
	{
		if(ceg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ce.ceg\" %f;\n", ceg);
	}
	void setCellColorB(float ceb)
	{
		if(ceb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ce.ceb\" %f;\n", ceb);
	}
	void setCreaseColor(const float3& cr)
	{
		if(cr == float3(0.235f,0.118f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".cr\" -type \"float3\" ");
		cr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCreaseColorR(float crr)
	{
		if(crr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cr.crr\" %f;\n", crr);
	}
	void setCreaseColorG(float crg)
	{
		if(crg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cr.crg\" %f;\n", crg);
	}
	void setCreaseColorB(float crb)
	{
		if(crb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cr.crb\" %f;\n", crb);
	}
	void setCellSize(float cs)
	{
		if(cs == 0.5) return;
		fprintf(mFile,"\tsetAttr \".cs\" %f;\n", cs);
	}
	void setDensity(float d)
	{
		if(d == 1.0) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setSpottyness(float s)
	{
		if(s == 0.1) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void setRandomness(float r)
	{
		if(r == 0.5) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setThreshold(float th)
	{
		if(th == 0.83) return;
		fprintf(mFile,"\tsetAttr \".th\" %f;\n", th);
	}
	void setCreases(bool c)
	{
		if(c == true) return;
		fprintf(mFile,"\tsetAttr \".c\" %i;\n", c);
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
	void getCellColor()const
	{
		fprintf(mFile,"\"%s.ce\"",mName.c_str());
	}
	void getCellColorR()const
	{
		fprintf(mFile,"\"%s.ce.cer\"",mName.c_str());
	}
	void getCellColorG()const
	{
		fprintf(mFile,"\"%s.ce.ceg\"",mName.c_str());
	}
	void getCellColorB()const
	{
		fprintf(mFile,"\"%s.ce.ceb\"",mName.c_str());
	}
	void getCreaseColor()const
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getCreaseColorR()const
	{
		fprintf(mFile,"\"%s.cr.crr\"",mName.c_str());
	}
	void getCreaseColorG()const
	{
		fprintf(mFile,"\"%s.cr.crg\"",mName.c_str());
	}
	void getCreaseColorB()const
	{
		fprintf(mFile,"\"%s.cr.crb\"",mName.c_str());
	}
	void getCellSize()const
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getDensity()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSpottyness()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getRandomness()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());
	}
	void getCreases()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
protected:
	Leather(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture3d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LEATHER_H__
