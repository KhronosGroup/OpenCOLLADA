/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VERTEXBAKESET_H__
#define __MayaDM_VERTEXBAKESET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBakeSet.h"
namespace MayaDM
{
class VertexBakeSet : public BakeSet
{
public:
public:

	VertexBakeSet():BakeSet(){}
	VertexBakeSet(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:BakeSet(file, name, parent, "vertexBakeSet", shared, create){}
	virtual ~VertexBakeSet(){}

	void setBakeColor(bool color)
	{
		if(color == 1) return;
		fprintf(mFile,"\tsetAttr \".color\" %i;\n", color);
	}
	void setColorBlending(unsigned int cblend)
	{
		if(cblend == 0) return;
		fprintf(mFile,"\tsetAttr \".cblend\" %i;\n", cblend);
	}
	void setAlphaBlending(unsigned int ablend)
	{
		if(ablend == 0) return;
		fprintf(mFile,"\tsetAttr \".ablend\" %i;\n", ablend);
	}
	void setScaleRgba(float scale)
	{
		if(scale == 1.0) return;
		fprintf(mFile,"\tsetAttr \".scale\" %f;\n", scale);
	}
	void setClampMin(bool min)
	{
		if(min == 0) return;
		fprintf(mFile,"\tsetAttr \".min\" %i;\n", min);
	}
	void setMinColor(const float3& lc)
	{
		fprintf(mFile,"\tsetAttr \".lc\" -type \"float3\" ");
		lc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinColorR(float lr)
	{
		if(lr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lr\" %f;\n", lr);
	}
	void setMinColorG(float lg)
	{
		if(lg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lg\" %f;\n", lg);
	}
	void setMinColorB(float lb)
	{
		if(lb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lc.lb\" %f;\n", lb);
	}
	void setMinAlpha(float mina)
	{
		if(mina == 0) return;
		fprintf(mFile,"\tsetAttr \".mina\" %f;\n", mina);
	}
	void setClampMax(bool max)
	{
		if(max == 0) return;
		fprintf(mFile,"\tsetAttr \".max\" %i;\n", max);
	}
	void setMaxColor(const float3& hc)
	{
		fprintf(mFile,"\tsetAttr \".hc\" -type \"float3\" ");
		hc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxColorR(float hr)
	{
		if(hr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hr\" %f;\n", hr);
	}
	void setMaxColorG(float hg)
	{
		if(hg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hg\" %f;\n", hg);
	}
	void setMaxColorB(float hb)
	{
		if(hb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hc.hb\" %f;\n", hb);
	}
	void setMaxAlpha(float maxa)
	{
		if(maxa == 1) return;
		fprintf(mFile,"\tsetAttr \".maxa\" %f;\n", maxa);
	}
	void setUseFaceNormals(bool ufn)
	{
		if(ufn == 0) return;
		fprintf(mFile,"\tsetAttr \".ufn\" %i;\n", ufn);
	}
	void setColorSetName(const string& csn)
	{
		if(csn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".csn\" -type \"string\" ");
		csn.write(mFile);
		fprintf(mFile,";\n");
	}
	void getSharedVertices()const
	{
		fprintf(mFile,"\"%s.shared\"",mName.c_str());
	}
	void getBakeColor()const
	{
		fprintf(mFile,"\"%s.color\"",mName.c_str());
	}
	void getColorBlending()const
	{
		fprintf(mFile,"\"%s.cblend\"",mName.c_str());
	}
	void getAlphaBlending()const
	{
		fprintf(mFile,"\"%s.ablend\"",mName.c_str());
	}
	void getScaleRgba()const
	{
		fprintf(mFile,"\"%s.scale\"",mName.c_str());
	}
	void getClampMin()const
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());
	}
	void getMinColorR()const
	{
		fprintf(mFile,"\"%s.lc.lr\"",mName.c_str());
	}
	void getMinColorG()const
	{
		fprintf(mFile,"\"%s.lc.lg\"",mName.c_str());
	}
	void getMinColorB()const
	{
		fprintf(mFile,"\"%s.lc.lb\"",mName.c_str());
	}
	void getMinAlpha()const
	{
		fprintf(mFile,"\"%s.mina\"",mName.c_str());
	}
	void getClampMax()const
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());
	}
	void getMaxColorR()const
	{
		fprintf(mFile,"\"%s.hc.hr\"",mName.c_str());
	}
	void getMaxColorG()const
	{
		fprintf(mFile,"\"%s.hc.hg\"",mName.c_str());
	}
	void getMaxColorB()const
	{
		fprintf(mFile,"\"%s.hc.hb\"",mName.c_str());
	}
	void getMaxAlpha()const
	{
		fprintf(mFile,"\"%s.maxa\"",mName.c_str());
	}
	void getUseFaceNormals()const
	{
		fprintf(mFile,"\"%s.ufn\"",mName.c_str());
	}
	void getColorSetName()const
	{
		fprintf(mFile,"\"%s.csn\"",mName.c_str());
	}
protected:
	VertexBakeSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:BakeSet(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_VERTEXBAKESET_H__
