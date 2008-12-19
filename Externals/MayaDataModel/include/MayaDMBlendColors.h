/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDCOLORS_H__
#define __MayaDM_BLENDCOLORS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class BlendColors : public DependNode
{
public:
public:
	BlendColors(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "blendColors"){}
	virtual ~BlendColors(){}
	void setBlender(float b)
	{
		if(b == 0.5) return;
		fprintf(mFile,"setAttr \".b\" %f;\n", b);

	}
	void setColor1(const float3& c1)
	{
		if(c1 == float3(1.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".c1\" -type \"float3\" ");
		c1.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor1R(float c1r)
	{
		if(c1r == 0.0) return;
		fprintf(mFile,"setAttr \".c1.c1r\" %f;\n", c1r);

	}
	void setColor1G(float c1g)
	{
		if(c1g == 0.0) return;
		fprintf(mFile,"setAttr \".c1.c1g\" %f;\n", c1g);

	}
	void setColor1B(float c1b)
	{
		if(c1b == 0.0) return;
		fprintf(mFile,"setAttr \".c1.c1b\" %f;\n", c1b);

	}
	void setColor2(const float3& c2)
	{
		if(c2 == float3(0.0f,0.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".c2\" -type \"float3\" ");
		c2.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor2R(float c2r)
	{
		if(c2r == 0.0) return;
		fprintf(mFile,"setAttr \".c2.c2r\" %f;\n", c2r);

	}
	void setColor2G(float c2g)
	{
		if(c2g == 0.0) return;
		fprintf(mFile,"setAttr \".c2.c2g\" %f;\n", c2g);

	}
	void setColor2B(float c2b)
	{
		if(c2b == 0.0) return;
		fprintf(mFile,"setAttr \".c2.c2b\" %f;\n", c2b);

	}
	void getBlender()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getColor1()
	{
		fprintf(mFile,"\"%s.c1\"",mName.c_str());

	}
	void getColor1R()
	{
		fprintf(mFile,"\"%s.c1.c1r\"",mName.c_str());

	}
	void getColor1G()
	{
		fprintf(mFile,"\"%s.c1.c1g\"",mName.c_str());

	}
	void getColor1B()
	{
		fprintf(mFile,"\"%s.c1.c1b\"",mName.c_str());

	}
	void getColor2()
	{
		fprintf(mFile,"\"%s.c2\"",mName.c_str());

	}
	void getColor2R()
	{
		fprintf(mFile,"\"%s.c2.c2r\"",mName.c_str());

	}
	void getColor2G()
	{
		fprintf(mFile,"\"%s.c2.c2g\"",mName.c_str());

	}
	void getColor2B()
	{
		fprintf(mFile,"\"%s.c2.c2b\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
	void getOutputR()
	{
		fprintf(mFile,"\"%s.op.opr\"",mName.c_str());

	}
	void getOutputG()
	{
		fprintf(mFile,"\"%s.op.opg\"",mName.c_str());

	}
	void getOutputB()
	{
		fprintf(mFile,"\"%s.op.opb\"",mName.c_str());

	}
protected:
	BlendColors(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BLENDCOLORS_H__
