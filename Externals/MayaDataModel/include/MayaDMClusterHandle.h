/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLUSTERHANDLE_H__
#define __MayaDM_CLUSTERHANDLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class ClusterHandle : public Shape
{
public:
	struct ClusterTransforms{
		void write(FILE* file) const
		{
		}
	};
public:

	ClusterHandle():Shape(){}
	ClusterHandle(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "clusterHandle", shared, create){}
	virtual ~ClusterHandle(){}

	void setOrigin(const double3& _or)
	{
		fprintf(mFile,"\tsetAttr \".or\" -type \"double3\" ");
		_or.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOriginX(double ox)
	{
		if(ox == 0) return;
		fprintf(mFile,"\tsetAttr \".or.ox\" %f;\n", ox);
	}
	void setOriginY(double oy)
	{
		if(oy == 0) return;
		fprintf(mFile,"\tsetAttr \".or.oy\" %f;\n", oy);
	}
	void setOriginZ(double oz)
	{
		if(oz == 0) return;
		fprintf(mFile,"\tsetAttr \".or.oz\" %f;\n", oz);
	}
	void getClusterTransforms(size_t x_i)const
	{
		fprintf(mFile,"\"%s.x[%i]\"",mName.c_str(),x_i);
	}
	void getClusterTransforms()const
	{

		fprintf(mFile,"\"%s.x\"",mName.c_str());
	}
	void getPreWeightedMatrixTransform(size_t x_i)const
	{
		fprintf(mFile,"\"%s.x[%i].pre\"",mName.c_str(),x_i);
	}
	void getPreWeightedMatrixTransform()const
	{

		fprintf(mFile,"\"%s.x.pre\"",mName.c_str());
	}
	void getWeightedMatrixTransform(size_t x_i)const
	{
		fprintf(mFile,"\"%s.x[%i].wt\"",mName.c_str(),x_i);
	}
	void getWeightedMatrixTransform()const
	{

		fprintf(mFile,"\"%s.x.wt\"",mName.c_str());
	}
	void getPostWeightedMatrixTransform(size_t x_i)const
	{
		fprintf(mFile,"\"%s.x[%i].post\"",mName.c_str(),x_i);
	}
	void getPostWeightedMatrixTransform()const
	{

		fprintf(mFile,"\"%s.x.post\"",mName.c_str());
	}
	void getOrigin()const
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());
	}
	void getOriginX()const
	{
		fprintf(mFile,"\"%s.or.ox\"",mName.c_str());
	}
	void getOriginY()const
	{
		fprintf(mFile,"\"%s.or.oy\"",mName.c_str());
	}
	void getOriginZ()const
	{
		fprintf(mFile,"\"%s.or.oz\"",mName.c_str());
	}
	void getWeightedNode()const
	{
		fprintf(mFile,"\"%s.wn\"",mName.c_str());
	}
protected:
	ClusterHandle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLUSTERHANDLE_H__
