/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SOLIDFRACTAL_H__
#define __MayaDM_SOLIDFRACTAL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
class SolidFractal : public Texture3d
{
public:
public:

	SolidFractal():Texture3d(){}
	SolidFractal(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture3d(file, name, parent, "solidFractal", shared, create){}
	virtual ~SolidFractal(){}

	void setXPixelAngle(float xpa)
	{
		if(xpa == 0.002053) return;
		fprintf(mFile,"\tsetAttr \".xpa\" %f;\n", xpa);
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
	void setThreshold(float th)
	{
		if(th == 0.0) return;
		fprintf(mFile,"\tsetAttr \".th\" %f;\n", th);
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
	void setFrequencyRatio(float fr)
	{
		if(fr == 2.0) return;
		fprintf(mFile,"\tsetAttr \".fr\" %f;\n", fr);
	}
	void setBias(float bs)
	{
		if(bs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bs\" %f;\n", bs);
	}
	void setInflection(bool in)
	{
		if(in == false) return;
		fprintf(mFile,"\tsetAttr \".in\" %i;\n", in);
	}
	void setAnimated(bool an)
	{
		if(an == false) return;
		fprintf(mFile,"\tsetAttr \".an\" %i;\n", an);
	}
	void setTimeRatio(float tr)
	{
		if(tr == 2.0) return;
		fprintf(mFile,"\tsetAttr \".tr\" %f;\n", tr);
	}
	void setTime(float ti)
	{
		if(ti == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ti\" %f;\n", ti);
	}
	void getXPixelAngle()const
	{
		fprintf(mFile,"\"%s.xpa\"",mName.c_str());
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
	void getAmplitude()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getRatio()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());
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
	void getFrequencyRatio()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getBias()const
	{
		fprintf(mFile,"\"%s.bs\"",mName.c_str());
	}
	void getInflection()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getAnimated()const
	{
		fprintf(mFile,"\"%s.an\"",mName.c_str());
	}
	void getTimeRatio()const
	{
		fprintf(mFile,"\"%s.tr\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.ti\"",mName.c_str());
	}
protected:
	SolidFractal(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture3d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SOLIDFRACTAL_H__
