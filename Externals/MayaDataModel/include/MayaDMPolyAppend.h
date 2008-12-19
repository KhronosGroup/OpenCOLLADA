/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYAPPEND_H__
#define __MayaDM_POLYAPPEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyAppend : public PolyModifier
{
public:
public:
	PolyAppend(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyAppend"){}
	virtual ~PolyAppend(){}
	void setVertices(size_t v_i,const float3& v)
	{
		fprintf(mFile,"setAttr \".v[%i]\" -type \"float3\" ",v_i);
		v.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertices(size_t v_start,size_t v_end,float* v)
	{
		fprintf(mFile,"setAttr \".v[%i:%i]\" ", v_start,v_end);
		size_t size = (v_end-v_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",v[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void setVtxx(size_t v_i,float vx)
	{
		if(vx == 0) return;
		fprintf(mFile,"setAttr \".v[%i].vx\" %f;\n", v_i,vx);

	}
	void setVtxy(size_t v_i,float vy)
	{
		if(vy == 0) return;
		fprintf(mFile,"setAttr \".v[%i].vy\" %f;\n", v_i,vy);

	}
	void setVtxz(size_t v_i,float vz)
	{
		if(vz == 0) return;
		fprintf(mFile,"setAttr \".v[%i].vz\" %f;\n", v_i,vz);

	}
	void setDesc(size_t d_i,int d)
	{
		if(d == 0) return;
		fprintf(mFile,"setAttr \".d[%i]\" %i;\n", d_i,d);

	}
	void setSubdivision(int s)
	{
		if(s == 1) return;
		fprintf(mFile,"setAttr \".s\" %i;\n", s);

	}
	void setTexture(unsigned int tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"setAttr \".tx\" %i;\n", tx);

	}
	void setTest2EdgeLoops(bool tel)
	{
		if(tel == true) return;
		fprintf(mFile,"setAttr \".tel\" %i;\n", tel);

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
	void getDesc(size_t d_i)
	{
		fprintf(mFile,"\"%s.d[%i]\"",mName.c_str(),d_i);

	}
	void getSubdivision()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getTexture()
	{
		fprintf(mFile,"\"%s.tx\"",mName.c_str());

	}
protected:
	PolyAppend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYAPPEND_H__
