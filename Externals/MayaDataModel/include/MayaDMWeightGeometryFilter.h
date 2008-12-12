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
/*
Base class for deformations that use weights that correspond to components.
For example, clusters use the weights to store their percentages: one
"weightList" per geometry, and each geometry's percentages are stored
in "weights".
<p/>
 Within the weights attribute, the weights are stored in the index that
 corresponds to the related point's 1-dimensional cvIndex. For curves and
 polys, the cvIndex corresponds to the actual cvIndex. For nurbs surfaces,
 the cvIndex = (totalV * uIndex + vIndex). For lattices, the
 cvIndex = (totalS * (totalT * u + t) + s).
*/
class WeightGeometryFilter : public GeometryFilter
{
public:
	/*Bundle of weights for each geometry*/
	struct WeightList{
		float* weights;
		void write(FILE* file) const
		{
			size_t size = sizeof(weights)/sizeof(float);
			for(size_t i=0; i<size; ++i)
			{
				fprintf_s(file,"%f", weights[i]);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	WeightGeometryFilter(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "weightGeometryFilter"){}
	virtual ~WeightGeometryFilter(){}
	/*Bundle of weights for each geometry*/
	void setWeightList(size_t wl_i,const WeightList& wl){fprintf_s(mFile, "setAttr \".wl[%i]\" ",wl_i);wl.write(mFile);fprintf_s(mFile,";\n");}
	/*Bundle of weights for each geometry*/
	void setWeightList(size_t wl_i,const WeightListID& wl){fprintf_s(mFile,"connectAttr \"");wl.write(mFile);fprintf_s(mFile,"\" \"%s.wl[%i]\";\n",mName.c_str(),wl_i);}
	/*
	The weights themselves, in the same order as the components deformed
	by the deformation.
	*/
	void setWeights(size_t wl_i,size_t w_i,float w){if(w == 1.0) return; fprintf_s(mFile, "setAttr \".wl[%i].w[%i]\" %f;\n", wl_i,w_i,w);}
	/*
	The weights themselves, in the same order as the components deformed
	by the deformation.
	*/
	void setWeights(size_t wl_i,size_t w_i,const FloatID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.wl[%i].w[%i]\";\n",mName.c_str(),wl_i,w_i);}
	/*Bundle of weights for each geometry*/
	const WeightListID& getWeightList(size_t wl_i){char buffer[4096];sprintf_s (buffer, "%s.wl[%i]",mName.c_str(),wl_i);return (const char*)buffer;}
	/*
	The weights themselves, in the same order as the components deformed
	by the deformation.
	*/
	const FloatID& getWeights(size_t wl_i,size_t w_i){char buffer[4096];sprintf_s (buffer, "%s.wl[%i].w[%i]",mName.c_str(),wl_i,w_i);return (const char*)buffer;}
protected:
	WeightGeometryFilter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_WEIGHTGEOMETRYFILTER_H__
