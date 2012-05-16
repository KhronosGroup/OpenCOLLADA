/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HEIGHTFIELD_H__
#define __MayaDM_HEIGHTFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSurfaceShape.h"
namespace MayaDM
{
class HeightField : public SurfaceShape
{
public:
public:

	HeightField():SurfaceShape(){}
	HeightField(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SurfaceShape(file, name, parent, "heightField", shared, create){}
	virtual ~HeightField(){}

	void setResolution(int res)
	{
		if(res == 10) return;
		fprintf(mFile,"\tsetAttr \".res\" %i;\n", res);
	}
	void setColor(const float3& cl)
	{
		fprintf(mFile,"\tsetAttr \".cl\" -type \"float3\" ");
		cl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float cr)
	{
		if(cr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".cl.cr\" %f;\n", cr);
	}
	void setColorG(float cg)
	{
		if(cg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".cl.cg\" %f;\n", cg);
	}
	void setColorB(float cb)
	{
		if(cb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".cl.cb\" %f;\n", cb);
	}
	void setDisplacement(float dis)
	{
		if(dis == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dis\" %f;\n", dis);
	}
	void setHeightScale(float hc)
	{
		if(hc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hc\" %f;\n", hc);
	}
	void getResolution()const
	{
		fprintf(mFile,"\"%s.res\"",mName.c_str());
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getColorR()const
	{
		fprintf(mFile,"\"%s.cl.cr\"",mName.c_str());
	}
	void getColorG()const
	{
		fprintf(mFile,"\"%s.cl.cg\"",mName.c_str());
	}
	void getColorB()const
	{
		fprintf(mFile,"\"%s.cl.cb\"",mName.c_str());
	}
	void getDisplacement()const
	{
		fprintf(mFile,"\"%s.dis\"",mName.c_str());
	}
	void getHeightScale()const
	{
		fprintf(mFile,"\"%s.hc\"",mName.c_str());
	}
	void getCacheNeedsRebuilding()const
	{
		fprintf(mFile,"\"%s.cnr\"",mName.c_str());
	}
protected:
	HeightField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SurfaceShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HEIGHTFIELD_H__
