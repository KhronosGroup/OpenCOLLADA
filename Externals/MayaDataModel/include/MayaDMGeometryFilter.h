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
	GeometryFilter(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "geometryFilter"){}
	virtual ~GeometryFilter(){}
	void setInput(size_t ip_i,const Input& ip)
	{
		fprintf(mFile,"\tsetAttr \".ip[%i]\" ",ip_i);
		ip.write(mFile);
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
	void getInput(size_t ip_i)
	{
		fprintf(mFile,"\"%s.ip[%i]\"",mName.c_str(),ip_i);

	}
	void getInputGeometry(size_t ip_i)
	{
		fprintf(mFile,"\"%s.ip[%i].ig\"",mName.c_str(),ip_i);

	}
	void getGroupId(size_t ip_i)
	{
		fprintf(mFile,"\"%s.ip[%i].gi\"",mName.c_str(),ip_i);

	}
	void getOutputGeometry(size_t og_i)
	{
		fprintf(mFile,"\"%s.og[%i]\"",mName.c_str(),og_i);

	}
	void getEnvelope()
	{
		fprintf(mFile,"\"%s.en\"",mName.c_str());

	}
	void getFunction()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getFchild1()
	{
		fprintf(mFile,"\"%s.f.f1\"",mName.c_str());

	}
	void getFchild2()
	{
		fprintf(mFile,"\"%s.f.f2\"",mName.c_str());

	}
	void getFchild3()
	{
		fprintf(mFile,"\"%s.f.f3\"",mName.c_str());

	}
	void getMap64BitIndices()
	{
		fprintf(mFile,"\"%s.map\"",mName.c_str());

	}
protected:
	GeometryFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYFILTER_H__
