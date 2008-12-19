/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WEIGHTGEOMETRYFILTER_H__
#define __MayaDM_WEIGHTGEOMETRYFILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class WeightGeometryFilter : public GeometryFilter
{
public:
	struct WeightList{
		float* weights;
		void write(FILE* file) const
		{
			size_t size = sizeof(weights)/sizeof(float);
			for(size_t i=0; i<size; ++i)
			{
				fprintf(file,"%f", weights[i]);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:
	WeightGeometryFilter(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "weightGeometryFilter"){}
	virtual ~WeightGeometryFilter(){}
	void setWeightList(size_t wl_i,const WeightList& wl)
	{
		fprintf(mFile,"setAttr \".wl[%i]\" ",wl_i);
		wl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWeights(size_t wl_i,size_t w_i,float w)
	{
		if(w == 1.0) return;
		fprintf(mFile,"setAttr \".wl[%i].w[%i]\" %f;\n", wl_i,w_i,w);

	}
	void getWeightList(size_t wl_i)
	{
		fprintf(mFile,"\"%s.wl[%i]\"",mName.c_str(),wl_i);

	}
	void getWeights(size_t wl_i,size_t w_i)
	{
		fprintf(mFile,"\"%s.wl[%i].w[%i]\"",mName.c_str(),wl_i,w_i);

	}
protected:
	WeightGeometryFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_WEIGHTGEOMETRYFILTER_H__
