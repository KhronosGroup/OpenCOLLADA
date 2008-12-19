/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	VertexBakeSet(FILE* file,const std::string& name,const std::string& parent=""):BakeSet(file, name, parent, "vertexBakeSet"){}
	virtual ~VertexBakeSet(){}
	void setBakeColor(bool color)
	{
		if(color == 1) return;
		fprintf(mFile,"setAttr \".color\" %i;\n", color);

	}
	void setColorBlending(unsigned int cblend)
	{
		if(cblend == 0) return;
		fprintf(mFile,"setAttr \".cblend\" %i;\n", cblend);

	}
	void setAlphaBlending(unsigned int ablend)
	{
		if(ablend == 0) return;
		fprintf(mFile,"setAttr \".ablend\" %i;\n", ablend);

	}
	void setScaleRgba(float scale)
	{
		if(scale == 1.0) return;
		fprintf(mFile,"setAttr \".scale\" %f;\n", scale);

	}
	void setClampMin(bool min)
	{
		if(min == 0) return;
		fprintf(mFile,"setAttr \".min\" %i;\n", min);

	}
	void setMinColor(const float3& lc)
	{
		fprintf(mFile,"setAttr \".lc\" -type \"float3\" ");
		lc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinColorR(float lr)
	{
		if(lr == 0.0) return;
		fprintf(mFile,"setAttr \".lc.lr\" %f;\n", lr);

	}
	void setMinColorG(float lg)
	{
		if(lg == 0.0) return;
		fprintf(mFile,"setAttr \".lc.lg\" %f;\n", lg);

	}
	void setMinColorB(float lb)
	{
		if(lb == 0.0) return;
		fprintf(mFile,"setAttr \".lc.lb\" %f;\n", lb);

	}
	void setMinAlpha(float mina)
	{
		if(mina == 0) return;
		fprintf(mFile,"setAttr \".mina\" %f;\n", mina);

	}
	void setClampMax(bool max)
	{
		if(max == 0) return;
		fprintf(mFile,"setAttr \".max\" %i;\n", max);

	}
	void setMaxColor(const float3& hc)
	{
		fprintf(mFile,"setAttr \".hc\" -type \"float3\" ");
		hc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxColorR(float hr)
	{
		if(hr == 0.0) return;
		fprintf(mFile,"setAttr \".hc.hr\" %f;\n", hr);

	}
	void setMaxColorG(float hg)
	{
		if(hg == 0.0) return;
		fprintf(mFile,"setAttr \".hc.hg\" %f;\n", hg);

	}
	void setMaxColorB(float hb)
	{
		if(hb == 0.0) return;
		fprintf(mFile,"setAttr \".hc.hb\" %f;\n", hb);

	}
	void setMaxAlpha(float maxa)
	{
		if(maxa == 1) return;
		fprintf(mFile,"setAttr \".maxa\" %f;\n", maxa);

	}
	void setUseFaceNormals(bool ufn)
	{
		if(ufn == 0) return;
		fprintf(mFile,"setAttr \".ufn\" %i;\n", ufn);

	}
	void setColorSetName(const string& csn)
	{
		if(csn == "NULL") return;
		fprintf(mFile,"setAttr \".csn\" -type \"string\" ");
		csn.write(mFile);
		fprintf(mFile,";\n");

	}
	void getSharedVertices()
	{
		fprintf(mFile,"\"%s.shared\"",mName.c_str());

	}
	void getBakeColor()
	{
		fprintf(mFile,"\"%s.color\"",mName.c_str());

	}
	void getColorBlending()
	{
		fprintf(mFile,"\"%s.cblend\"",mName.c_str());

	}
	void getAlphaBlending()
	{
		fprintf(mFile,"\"%s.ablend\"",mName.c_str());

	}
	void getScaleRgba()
	{
		fprintf(mFile,"\"%s.scale\"",mName.c_str());

	}
	void getClampMin()
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());

	}
	void getMinColorR()
	{
		fprintf(mFile,"\"%s.lc.lr\"",mName.c_str());

	}
	void getMinColorG()
	{
		fprintf(mFile,"\"%s.lc.lg\"",mName.c_str());

	}
	void getMinColorB()
	{
		fprintf(mFile,"\"%s.lc.lb\"",mName.c_str());

	}
	void getMinAlpha()
	{
		fprintf(mFile,"\"%s.mina\"",mName.c_str());

	}
	void getClampMax()
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());

	}
	void getMaxColorR()
	{
		fprintf(mFile,"\"%s.hc.hr\"",mName.c_str());

	}
	void getMaxColorG()
	{
		fprintf(mFile,"\"%s.hc.hg\"",mName.c_str());

	}
	void getMaxColorB()
	{
		fprintf(mFile,"\"%s.hc.hb\"",mName.c_str());

	}
	void getMaxAlpha()
	{
		fprintf(mFile,"\"%s.maxa\"",mName.c_str());

	}
	void getUseFaceNormals()
	{
		fprintf(mFile,"\"%s.ufn\"",mName.c_str());

	}
	void getColorSetName()
	{
		fprintf(mFile,"\"%s.csn\"",mName.c_str());

	}
protected:
	VertexBakeSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BakeSet(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_VERTEXBAKESET_H__
