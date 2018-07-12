/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOMETRYFILTER_H__
#define __MayaDM_GEOMETRYFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class GeometryFilter : public DependNode
{
public:
	struct Input{
		int groupId;
		void write(FILE* file) const
		{
			fprintf(file,"%i", groupId);
		}
	};
public:

	GeometryFilter():DependNode(){}
	GeometryFilter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "geometryFilter", shared, create){}
	virtual ~GeometryFilter(){}

	void setInput(size_t ip_i,const Input& ip)
	{
		fprintf(mFile,"\tsetAttr \".ip[%i]\" ",ip_i);
		ip.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInput(size_t ip_start,size_t ip_end,Input* ip)
	{
		fprintf(mFile,"\tsetAttr \".ip[%i:%i]\" ", ip_start,ip_end);
		size_t size = (ip_end-ip_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ip[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInput(size_t ip_start,size_t ip_end)const
	{
		fprintf(mFile,"\tsetAttr \".ip[%i:%i]\"",ip_start,ip_end);
		fprintf(mFile," -type \"Input\" ");
	}
	void appendInput(const Input& ip)const
	{
		fprintf(mFile," ");
		ip.write(mFile);
	}
	void endInput()const
	{
		fprintf(mFile,";\n");
	}
	void setGroupId(size_t ip_i,int gi)
	{
		if(gi == 0) return;
		fprintf(mFile,"\tsetAttr \".ip[%i].gi\" %i;\n", ip_i,gi);
	}
	void setEnvelope(float en)
	{
		if(en == 1) return;
		fprintf(mFile,"\tsetAttr \".en\" %f;\n", en);
	}
	void getInput(size_t ip_i)const
	{
		fprintf(mFile,"\"%s.ip[%i]\"",mName.c_str(),ip_i);
	}
	void getInput()const
	{

		fprintf(mFile,"\"%s.ip\"",mName.c_str());
	}
	void getInputGeometry(size_t ip_i)const
	{
		fprintf(mFile,"\"%s.ip[%i].ig\"",mName.c_str(),ip_i);
	}
	void getInputGeometry()const
	{

		fprintf(mFile,"\"%s.ip.ig\"",mName.c_str());
	}
	void getGroupId(size_t ip_i)const
	{
		fprintf(mFile,"\"%s.ip[%i].gi\"",mName.c_str(),ip_i);
	}
	void getGroupId()const
	{

		fprintf(mFile,"\"%s.ip.gi\"",mName.c_str());
	}
	void getOutputGeometry(size_t og_i)const
	{
		fprintf(mFile,"\"%s.og[%i]\"",mName.c_str(),og_i);
	}
	void getOutputGeometry()const
	{

		fprintf(mFile,"\"%s.og\"",mName.c_str());
	}
	void getEnvelope()const
	{
		fprintf(mFile,"\"%s.en\"",mName.c_str());
	}
	void getFunction()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getFchild1()const
	{
		fprintf(mFile,"\"%s.f.f1\"",mName.c_str());
	}
	void getFchild2()const
	{
		fprintf(mFile,"\"%s.f.f2\"",mName.c_str());
	}
	void getFchild3()const
	{
		fprintf(mFile,"\"%s.f.f3\"",mName.c_str());
	}
	void getMap64BitIndices()const
	{
		fprintf(mFile,"\"%s.map\"",mName.c_str());
	}
protected:
	GeometryFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYFILTER_H__
