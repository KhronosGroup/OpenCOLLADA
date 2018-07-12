/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	PolyAppend():PolyModifier(){}
	PolyAppend(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyAppend", shared, create){}
	virtual ~PolyAppend(){}

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
	void startVertices(size_t v_start,size_t v_end)const
	{
		fprintf(mFile,"\tsetAttr \".v[%i:%i]\"",v_start,v_end);
	}
	void appendVertices(float v)const
	{
		fprintf(mFile," %f",v);
	}
	void endVertices()const
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
	void startDesc(size_t d_start,size_t d_end)const
	{
		fprintf(mFile,"\tsetAttr \".d[%i:%i]\"",d_start,d_end);
	}
	void appendDesc(int d)const
	{
		fprintf(mFile," %i",d);
	}
	void endDesc()const
	{
		fprintf(mFile,";\n");
	}
	void setSubdivision(int s)
	{
		if(s == 1) return;
		fprintf(mFile,"\tsetAttr \".s\" %i;\n", s);
	}
	void setTexture(unsigned int tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"\tsetAttr \".tx\" %i;\n", tx);
	}
	void setTest2EdgeLoops(bool tel)
	{
		if(tel == true) return;
		fprintf(mFile,"\tsetAttr \".tel\" %i;\n", tel);
	}
	void getVertices(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i]\"",mName.c_str(),v_i);
	}
	void getVertices()const
	{

		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getVtxx(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i].vx\"",mName.c_str(),v_i);
	}
	void getVtxx()const
	{

		fprintf(mFile,"\"%s.v.vx\"",mName.c_str());
	}
	void getVtxy(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i].vy\"",mName.c_str(),v_i);
	}
	void getVtxy()const
	{

		fprintf(mFile,"\"%s.v.vy\"",mName.c_str());
	}
	void getVtxz(size_t v_i)const
	{
		fprintf(mFile,"\"%s.v[%i].vz\"",mName.c_str(),v_i);
	}
	void getVtxz()const
	{

		fprintf(mFile,"\"%s.v.vz\"",mName.c_str());
	}
	void getDesc(size_t d_i)const
	{
		fprintf(mFile,"\"%s.d[%i]\"",mName.c_str(),d_i);
	}
	void getDesc()const
	{

		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSubdivision()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getTexture()const
	{
		fprintf(mFile,"\"%s.tx\"",mName.c_str());
	}
protected:
	PolyAppend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYAPPEND_H__
