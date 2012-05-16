/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STENCIL_H__
#define __MayaDM_STENCIL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
class Stencil : public Texture2d
{
public:
public:

	Stencil():Texture2d(){}
	Stencil(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Texture2d(file, name, parent, "stencil", shared, create){}
	virtual ~Stencil(){}

	void setImage(const float3& im)
	{
		if(im == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".im\" -type \"float3\" ");
		im.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImageR(float imr)
	{
		if(imr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".im.imr\" %f;\n", imr);
	}
	void setImageG(float img)
	{
		if(img == 0.0) return;
		fprintf(mFile,"\tsetAttr \".im.img\" %f;\n", img);
	}
	void setImageB(float imb)
	{
		if(imb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".im.imb\" %f;\n", imb);
	}
	void setMask(float m)
	{
		if(m == 0.0) return;
		fprintf(mFile,"\tsetAttr \".m\" %f;\n", m);
	}
	void setEdgeBlend(float eb)
	{
		if(eb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".eb\" %f;\n", eb);
	}
	void setKeyMasking(bool km)
	{
		if(km == false) return;
		fprintf(mFile,"\tsetAttr \".km\" %i;\n", km);
	}
	void setPositiveKey(bool pk)
	{
		if(pk == false) return;
		fprintf(mFile,"\tsetAttr \".pk\" %i;\n", pk);
	}
	void setColorKey(const float3& ck)
	{
		if(ck == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".ck\" -type \"float3\" ");
		ck.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorKeyR(float ckr)
	{
		if(ckr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ck.ckr\" %f;\n", ckr);
	}
	void setColorKeyG(float ckg)
	{
		if(ckg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ck.ckg\" %f;\n", ckg);
	}
	void setColorKeyB(float ckb)
	{
		if(ckb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ck.ckb\" %f;\n", ckb);
	}
	void setHueRange(float hr)
	{
		if(hr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".hr\" %f;\n", hr);
	}
	void setSaturationRange(float sr)
	{
		if(sr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);
	}
	void setValueRange(float vr)
	{
		if(vr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".vr\" %f;\n", vr);
	}
	void setThreshold(float th)
	{
		if(th == 0.5) return;
		fprintf(mFile,"\tsetAttr \".th\" %f;\n", th);
	}
	void getImage()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getImageR()const
	{
		fprintf(mFile,"\"%s.im.imr\"",mName.c_str());
	}
	void getImageG()const
	{
		fprintf(mFile,"\"%s.im.img\"",mName.c_str());
	}
	void getImageB()const
	{
		fprintf(mFile,"\"%s.im.imb\"",mName.c_str());
	}
	void getMask()const
	{
		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getEdgeBlend()const
	{
		fprintf(mFile,"\"%s.eb\"",mName.c_str());
	}
	void getKeyMasking()const
	{
		fprintf(mFile,"\"%s.km\"",mName.c_str());
	}
	void getPositiveKey()const
	{
		fprintf(mFile,"\"%s.pk\"",mName.c_str());
	}
	void getColorKey()const
	{
		fprintf(mFile,"\"%s.ck\"",mName.c_str());
	}
	void getColorKeyR()const
	{
		fprintf(mFile,"\"%s.ck.ckr\"",mName.c_str());
	}
	void getColorKeyG()const
	{
		fprintf(mFile,"\"%s.ck.ckg\"",mName.c_str());
	}
	void getColorKeyB()const
	{
		fprintf(mFile,"\"%s.ck.ckb\"",mName.c_str());
	}
	void getHueRange()const
	{
		fprintf(mFile,"\"%s.hr\"",mName.c_str());
	}
	void getSaturationRange()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getValueRange()const
	{
		fprintf(mFile,"\"%s.vr\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());
	}
protected:
	Stencil(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Texture2d(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_STENCIL_H__
