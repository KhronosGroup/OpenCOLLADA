/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOUD_H__
#define __MayaDM_CLOUD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class Cloud : public Texture3d
{
public:
public:

	Cloud():Texture3d(){}
	Cloud(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture3d(file, name, parent, "cloud", shared, create){}
	virtual ~Cloud(){}

	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);
	}
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
		if(c2 == float3(1.0f,1.0f,1.0f)) return;
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
	void setContrast(float c)
	{
		if(c == 0.5) return;
		fprintf(mFile,"\tsetAttr \".c\" %f;\n", c);
	}
	void setSoftEdges(bool se)
	{
		if(se == true) return;
		fprintf(mFile,"\tsetAttr \".se\" %i;\n", se);
	}
	void setTranspRange(float tr)
	{
		if(tr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".tr\" %f;\n", tr);
	}
	void setCenterThresh(float ct)
	{
		if(ct == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ct\" %f;\n", ct);
	}
	void setEdgeThresh(float et)
	{
		if(et == 1.0) return;
		fprintf(mFile,"\tsetAttr \".et\" %f;\n", et);
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
	void setAmplitude(float a)
	{
		if(a == 1.0) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void setRatio(float ra)
	{
		if(ra == 0.707) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
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
	void getXPixelAngle()const
	{
		fprintf(mFile,"\"%s.xpa\"",mName.c_str());
	}
	void getEyeToTextureMatrix()const
	{
		fprintf(mFile,"\"%s.e2t\"",mName.c_str());
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
	void getContrast()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getSoftEdges()const
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());
	}
	void getTranspRange()const
	{
		fprintf(mFile,"\"%s.tr\"",mName.c_str());
	}
	void getCenterThresh()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getEdgeThresh()const
	{
		fprintf(mFile,"\"%s.et\"",mName.c_str());
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
	void getAmplitude()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getRatio()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
protected:
	Cloud(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture3d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLOUD_H__
