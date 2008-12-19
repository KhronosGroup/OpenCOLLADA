/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REMAPVALUE_H__
#define __MayaDM_REMAPVALUE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RemapValue : public DependNode
{
public:
	struct Value{
		float value_Position;
		float value_FloatValue;
		unsigned int value_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", value_Position);
			fprintf(file,"%f ", value_FloatValue);
			fprintf(file,"%i", value_Interp);
		}
	};
	struct Color{
		float color_Position;
		float3 color_Color;
		unsigned int color_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", color_Position);
			color_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", color_Interp);
		}
	};
public:
	RemapValue(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "remapValue"){}
	virtual ~RemapValue(){}
	void setInputValue(float i)
	{
		if(i == 0.0) return;
		fprintf(mFile,"setAttr \".i\" %f;\n", i);

	}
	void setInputMin(float imn)
	{
		if(imn == 0) return;
		fprintf(mFile,"setAttr \".imn\" %f;\n", imn);

	}
	void setInputMax(float imx)
	{
		if(imx == 1) return;
		fprintf(mFile,"setAttr \".imx\" %f;\n", imx);

	}
	void setOutputMin(float omn)
	{
		if(omn == 0) return;
		fprintf(mFile,"setAttr \".omn\" %f;\n", omn);

	}
	void setOutputMax(float omx)
	{
		if(omx == 1) return;
		fprintf(mFile,"setAttr \".omx\" %f;\n", omx);

	}
	void setValue(size_t vl_i,const Value& vl)
	{
		fprintf(mFile,"setAttr \".vl[%i]\" ",vl_i);
		vl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setValue_Position(size_t vl_i,float vlp)
	{
		if(vlp == 0.0) return;
		fprintf(mFile,"setAttr \".vl[%i].vlp\" %f;\n", vl_i,vlp);

	}
	void setValue_FloatValue(size_t vl_i,float vlfv)
	{
		if(vlfv == 0.0) return;
		fprintf(mFile,"setAttr \".vl[%i].vlfv\" %f;\n", vl_i,vlfv);

	}
	void setValue_Interp(size_t vl_i,unsigned int vli)
	{
		if(vli == 0) return;
		fprintf(mFile,"setAttr \".vl[%i].vli\" %i;\n", vl_i,vli);

	}
	void setColor(size_t cl_i,const Color& cl)
	{
		fprintf(mFile,"setAttr \".cl[%i]\" ",cl_i);
		cl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor_Position(size_t cl_i,float clp)
	{
		if(clp == 0.0) return;
		fprintf(mFile,"setAttr \".cl[%i].clp\" %f;\n", cl_i,clp);

	}
	void setColor_Color(size_t cl_i,const float3& clc)
	{
		fprintf(mFile,"setAttr \".cl[%i].clc\" -type \"float3\" ",cl_i);
		clc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor_ColorR(size_t cl_i,float clcr)
	{
		if(clcr == 0.0) return;
		fprintf(mFile,"setAttr \".cl[%i].clc.clcr\" %f;\n", cl_i,clcr);

	}
	void setColor_ColorG(size_t cl_i,float clcg)
	{
		if(clcg == 0.0) return;
		fprintf(mFile,"setAttr \".cl[%i].clc.clcg\" %f;\n", cl_i,clcg);

	}
	void setColor_ColorB(size_t cl_i,float clcb)
	{
		if(clcb == 0.0) return;
		fprintf(mFile,"setAttr \".cl[%i].clc.clcb\" %f;\n", cl_i,clcb);

	}
	void setColor_Interp(size_t cl_i,unsigned int cli)
	{
		if(cli == 0) return;
		fprintf(mFile,"setAttr \".cl[%i].cli\" %i;\n", cl_i,cli);

	}
	void getInputValue()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getInputMin()
	{
		fprintf(mFile,"\"%s.imn\"",mName.c_str());

	}
	void getInputMax()
	{
		fprintf(mFile,"\"%s.imx\"",mName.c_str());

	}
	void getOutputMin()
	{
		fprintf(mFile,"\"%s.omn\"",mName.c_str());

	}
	void getOutputMax()
	{
		fprintf(mFile,"\"%s.omx\"",mName.c_str());

	}
	void getValue(size_t vl_i)
	{
		fprintf(mFile,"\"%s.vl[%i]\"",mName.c_str(),vl_i);

	}
	void getValue_Position(size_t vl_i)
	{
		fprintf(mFile,"\"%s.vl[%i].vlp\"",mName.c_str(),vl_i);

	}
	void getValue_FloatValue(size_t vl_i)
	{
		fprintf(mFile,"\"%s.vl[%i].vlfv\"",mName.c_str(),vl_i);

	}
	void getValue_Interp(size_t vl_i)
	{
		fprintf(mFile,"\"%s.vl[%i].vli\"",mName.c_str(),vl_i);

	}
	void getColor(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i]\"",mName.c_str(),cl_i);

	}
	void getColor_Position(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clp\"",mName.c_str(),cl_i);

	}
	void getColor_Color(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clc\"",mName.c_str(),cl_i);

	}
	void getColor_ColorR(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcr\"",mName.c_str(),cl_i);

	}
	void getColor_ColorG(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcg\"",mName.c_str(),cl_i);

	}
	void getColor_ColorB(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcb\"",mName.c_str(),cl_i);

	}
	void getColor_Interp(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].cli\"",mName.c_str(),cl_i);

	}
	void getOutValue()
	{
		fprintf(mFile,"\"%s.ov\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
protected:
	RemapValue(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_REMAPVALUE_H__
