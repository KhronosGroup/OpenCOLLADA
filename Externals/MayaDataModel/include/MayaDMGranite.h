/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GRANITE_H__
#define __MayaDM_GRANITE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Granite : public Texture3d
{
public:
public:

	Granite():Texture3d(){}
	Granite(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture3d(file, name, parent, "granite", shared, create){}
	virtual ~Granite(){}

	void setColor1(const float3& c1)
	{
		if(c1 == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".c1\" -type \"float3\" ");
		c1.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor1R(float c1r)
	{
		if(c1r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1r\" %f;\n", c1r);
	}
	void setColor1G(float c1g)
	{
		if(c1g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1g\" %f;\n", c1g);
	}
	void setColor1B(float c1b)
	{
		if(c1b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c1.c1b\" %f;\n", c1b);
	}
	void setColor2(const float3& c2)
	{
		if(c2 == float3(0.549f,0.784f,0.392f)) return;
		fprintf(mFile,"\tsetAttr \".c2\" -type \"float3\" ");
		c2.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor2R(float c2r)
	{
		if(c2r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2r\" %f;\n", c2r);
	}
	void setColor2G(float c2g)
	{
		if(c2g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2g\" %f;\n", c2g);
	}
	void setColor2B(float c2b)
	{
		if(c2b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c2.c2b\" %f;\n", c2b);
	}
	void setColor3(const float3& c3)
	{
		if(c3 == float3(0.627f,0.824f,0.823f)) return;
		fprintf(mFile,"\tsetAttr \".c3\" -type \"float3\" ");
		c3.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor3R(float c3r)
	{
		if(c3r == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c3.c3r\" %f;\n", c3r);
	}
	void setColor3G(float c3g)
	{
		if(c3g == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c3.c3g\" %f;\n", c3g);
	}
	void setColor3B(float c3b)
	{
		if(c3b == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c3.c3b\" %f;\n", c3b);
	}
	void setFillerColor(const float3& fc)
	{
		if(fc == float3(0.588f,0.294f,0.196f)) return;
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
	void setCellSize(float cs)
	{
		if(cs == 0.15) return;
		fprintf(mFile,"\tsetAttr \".cs\" %f;\n", cs);
	}
	void setDensity(float dy)
	{
		if(dy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dy\" %f;\n", dy);
	}
	void setMixRatio(float mr)
	{
		if(mr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mr\" %f;\n", mr);
	}
	void setSpottyness(float s)
	{
		if(s == 0.3) return;
		fprintf(mFile,"\tsetAttr \".s\" %f;\n", s);
	}
	void setRandomness(float ra)
	{
		if(ra == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
	}
	void setThreshold(float th)
	{
		if(th == 0.5) return;
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
	void getColor1()const
	{
		fprintf(mFile,"\"%s.c1\"",mName.c_str());
	}
	void getColor1R()const
	{
		fprintf(mFile,"\"%s.c1.c1r\"",mName.c_str());
	}
	void getColor1G()const
	{
		fprintf(mFile,"\"%s.c1.c1g\"",mName.c_str());
	}
	void getColor1B()const
	{
		fprintf(mFile,"\"%s.c1.c1b\"",mName.c_str());
	}
	void getColor2()const
	{
		fprintf(mFile,"\"%s.c2\"",mName.c_str());
	}
	void getColor2R()const
	{
		fprintf(mFile,"\"%s.c2.c2r\"",mName.c_str());
	}
	void getColor2G()const
	{
		fprintf(mFile,"\"%s.c2.c2g\"",mName.c_str());
	}
	void getColor2B()const
	{
		fprintf(mFile,"\"%s.c2.c2b\"",mName.c_str());
	}
	void getColor3()const
	{
		fprintf(mFile,"\"%s.c3\"",mName.c_str());
	}
	void getColor3R()const
	{
		fprintf(mFile,"\"%s.c3.c3r\"",mName.c_str());
	}
	void getColor3G()const
	{
		fprintf(mFile,"\"%s.c3.c3g\"",mName.c_str());
	}
	void getColor3B()const
	{
		fprintf(mFile,"\"%s.c3.c3b\"",mName.c_str());
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
	void getCellSize()const
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getDensity()const
	{
		fprintf(mFile,"\"%s.dy\"",mName.c_str());
	}
	void getMixRatio()const
	{
		fprintf(mFile,"\"%s.mr\"",mName.c_str());
	}
	void getSpottyness()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getRandomness()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
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
	Granite(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture3d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GRANITE_H__
