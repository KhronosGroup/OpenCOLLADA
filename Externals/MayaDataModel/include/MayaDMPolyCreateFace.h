/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCREATEFACE_H__
#define __MayaDM_POLYCREATEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyCreator.h"
namespace MayaDM
{
class PolyCreateFace : public PolyCreator
{
public:
public:

	PolyCreateFace():PolyCreator(){}
	PolyCreateFace(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyCreator(file, name, parent, "polyCreateFace", shared, create){}
	virtual ~PolyCreateFace(){}

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
	void setLoop(size_t l_i,int l)
	{
		if(l == 0) return;
		fprintf(mFile,"\tsetAttr \".l[%i]\" %i;\n", l_i,l);
	}
	void setLoop(size_t l_start,size_t l_end,int* l)
	{
		fprintf(mFile,"\tsetAttr \".l[%i:%i]\" ", l_start,l_end);
		size_t size = (l_end-l_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",l[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startLoop(size_t l_start,size_t l_end)const
	{
		fprintf(mFile,"\tsetAttr \".l[%i:%i]\"",l_start,l_end);
	}
	void appendLoop(int l)const
	{
		fprintf(mFile," %i",l);
	}
	void endLoop()const
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
	void setUvSetName(const string& uvs)
	{
		if(uvs == "NULL") return;
		fprintf(mFile,"\tsetAttr \".uvs\" -type \"string\" ");
		uvs.write(mFile);
		fprintf(mFile,";\n");
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
	void getLoop(size_t l_i)const
	{
		fprintf(mFile,"\"%s.l[%i]\"",mName.c_str(),l_i);
	}
	void getLoop()const
	{

		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getSubdivision()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getTexture()const
	{
		fprintf(mFile,"\"%s.tx\"",mName.c_str());
	}
	void getUvSetName()const
	{
		fprintf(mFile,"\"%s.uvs\"",mName.c_str());
	}
protected:
	PolyCreateFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyCreator(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCREATEFACE_H__
