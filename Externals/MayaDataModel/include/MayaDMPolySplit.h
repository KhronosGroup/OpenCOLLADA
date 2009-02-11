/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSPLIT_H__
#define __MayaDM_POLYSPLIT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolySplit : public PolyModifier
{
public:
public:
	PolySplit():PolyModifier(){}
	PolySplit(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polySplit"){}
	virtual ~PolySplit(){}
	void setVertices(size_t v_i,const float3& v)
	{
		fprintf(mFile,"\tsetAttr \".v[%i]\" -type \"float3\" ",v_i);
		v.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertices(size_t v_start,size_t v_end,float* v)
	{
		fprintf(mFile,"\tsetAttr \".v[%i:%i]\" ", v_start,v_end);
		size_t size = (v_end-v_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",v[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startVertices(size_t v_start,size_t v_end)
	{
		fprintf(mFile,"\tsetAttr \".v[%i:%i]\"",v_start,v_end);

	}
	void appendVertices(float v)
	{
		fprintf(mFile," %f",v);

	}
	void endVertices()
	{
		fprintf(mFile,";\n");

	}
	void setVtxx(size_t v_i,float vx)
	{
		if(vx == 0) return;
		fprintf(mFile,"\tsetAttr \".v[%i].vx\" %f;\n", v_i,vx);

	}
	void setVtxy(size_t v_i,float vy)
	{
		if(vy == 0) return;
		fprintf(mFile,"\tsetAttr \".v[%i].vy\" %f;\n", v_i,vy);

	}
	void setVtxz(size_t v_i,float vz)
	{
		if(vz == 0) return;
		fprintf(mFile,"\tsetAttr \".v[%i].vz\" %f;\n", v_i,vz);

	}
	void setEdge(size_t e_i,float e)
	{
		if(e == 0.0) return;
		fprintf(mFile,"\tsetAttr \".e[%i]\" %f;\n", e_i,e);

	}
	void setEdge(size_t e_start,size_t e_end,float* e)
	{
		fprintf(mFile,"\tsetAttr \".e[%i:%i]\" ", e_start,e_end);
		size_t size = (e_end-e_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",e[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEdge(size_t e_start,size_t e_end)
	{
		fprintf(mFile,"\tsetAttr \".e[%i:%i]\"",e_start,e_end);

	}
	void appendEdge(float e)
	{
		fprintf(mFile," %f",e);

	}
	void endEdge()
	{
		fprintf(mFile,";\n");

	}
	void setDesc(size_t d_i,int d)
	{
		if(d == 0) return;
		fprintf(mFile,"\tsetAttr \".d[%i]\" %i;\n", d_i,d);

	}
	void setDesc(size_t d_start,size_t d_end,int* d)
	{
		fprintf(mFile,"\tsetAttr \".d[%i:%i]\" ", d_start,d_end);
		size_t size = (d_end-d_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",d[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startDesc(size_t d_start,size_t d_end)
	{
		fprintf(mFile,"\tsetAttr \".d[%i:%i]\"",d_start,d_end);

	}
	void appendDesc(int d)
	{
		fprintf(mFile," %i",d);

	}
	void endDesc()
	{
		fprintf(mFile,";\n");

	}
	void setSubdivision(int s)
	{
		if(s == 1) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);

	}
	void setSmoothingAngle(double sma)
	{
		if(sma == 0) return;
		fprintf(mFile,"\tsetAttr \".sma\" %f;\n", sma);

	}
	void setMaya70(bool m70)
	{
		if(m70 == true) return;
		fprintf(mFile,"\tsetAttr \".m70\" %i;\n", m70);

	}
	void getVertices(size_t v_i)
	{
		fprintf(mFile,"\"%s.v[%i]\"",mName.c_str(),v_i);

	}
	void getVtxx(size_t v_i)
	{
		fprintf(mFile,"\"%s.v[%i].vx\"",mName.c_str(),v_i);

	}
	void getVtxy(size_t v_i)
	{
		fprintf(mFile,"\"%s.v[%i].vy\"",mName.c_str(),v_i);

	}
	void getVtxz(size_t v_i)
	{
		fprintf(mFile,"\"%s.v[%i].vz\"",mName.c_str(),v_i);

	}
	void getEdge(size_t e_i)
	{
		fprintf(mFile,"\"%s.e[%i]\"",mName.c_str(),e_i);

	}
	void getDesc(size_t d_i)
	{
		fprintf(mFile,"\"%s.d[%i]\"",mName.c_str(),d_i);

	}
	void getSubdivision()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getSmoothingAngle()
	{
		fprintf(mFile,"\"%s.sma\"",mName.c_str());

	}
protected:
	PolySplit(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSPLIT_H__
