/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RENDERQUALITY_H__
#define __MayaDM_RENDERQUALITY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RenderQuality : public DependNode
{
public:
public:

	RenderQuality():DependNode(){}
	RenderQuality(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "renderQuality", shared, create){}
	virtual ~RenderQuality(){}

	void setReflections(int rfl)
	{
		if(rfl == 1) return;
		fprintf(mFile,"\tsetAttr \".rfl\" %i;\n", rfl);
	}
	void setRefractions(int rfr)
	{
		if(rfr == 6) return;
		fprintf(mFile,"\tsetAttr \".rfr\" %i;\n", rfr);
	}
	void setShadows(int sl)
	{
		if(sl == 2) return;
		fprintf(mFile,"\tsetAttr \".sl\" %i;\n", sl);
	}
	void setRayTraceBias(float rtb)
	{
		if(rtb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rtb\" %f;\n", rtb);
	}
	void setEdgeAntiAliasing(unsigned int eaa)
	{
		if(eaa == 3) return;
		fprintf(mFile,"\tsetAttr \".eaa\" %i;\n", eaa);
	}
	void setRenderSample(bool rsdn)
	{
		if(rsdn == false) return;
		fprintf(mFile,"\tsetAttr \".rsdn\" %i;\n", rsdn);
	}
	void setUseMultiPixelFilter(bool ufil)
	{
		if(ufil == false) return;
		fprintf(mFile,"\tsetAttr \".ufil\" %i;\n", ufil);
	}
	void setPixelFilterType(unsigned int pft)
	{
		if(pft == 1) return;
		fprintf(mFile,"\tsetAttr \".pft\" %i;\n", pft);
	}
	void setPixelFilterWidthX(float pfwx)
	{
		if(pfwx == 2.2) return;
		fprintf(mFile,"\tsetAttr \".pfwx\" %f;\n", pfwx);
	}
	void setPixelFilterWidthY(float pfwy)
	{
		if(pfwy == 2.2) return;
		fprintf(mFile,"\tsetAttr \".pfwy\" %f;\n", pfwy);
	}
	void setPlugInFilterWeight(float pifw)
	{
		if(pifw == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pifw\" %f;\n", pifw);
	}
	void setShadingSamples(int ss)
	{
		if(ss == 1) return;
		fprintf(mFile,"\tsetAttr \".ss\" %i;\n", ss);
	}
	void setMaxShadingSamples(int mss)
	{
		if(mss == 8) return;
		fprintf(mFile,"\tsetAttr \".mss\" %i;\n", mss);
	}
	void setVisibilitySamples(int mvs)
	{
		if(mvs == 1) return;
		fprintf(mFile,"\tsetAttr \".mvs\" %i;\n", mvs);
	}
	void setMaxVisibilitySamples(int mvm)
	{
		if(mvm == 4) return;
		fprintf(mFile,"\tsetAttr \".mvm\" %i;\n", mvm);
	}
	void setVolumeSamples(int vs)
	{
		if(vs == 1) return;
		fprintf(mFile,"\tsetAttr \".vs\" %i;\n", vs);
	}
	void setParticleSamples(int pss)
	{
		if(pss == 1) return;
		fprintf(mFile,"\tsetAttr \".pss\" %i;\n", pss);
	}
	void setEnableRaytracing(bool ert)
	{
		if(ert == false) return;
		fprintf(mFile,"\tsetAttr \".ert\" %i;\n", ert);
	}
	void setRedThreshold(float rct)
	{
		if(rct == 0.4) return;
		fprintf(mFile,"\tsetAttr \".rct\" %f;\n", rct);
	}
	void setGreenThreshold(float gct)
	{
		if(gct == 0.3) return;
		fprintf(mFile,"\tsetAttr \".gct\" %f;\n", gct);
	}
	void setBlueThreshold(float bct)
	{
		if(bct == 0.6) return;
		fprintf(mFile,"\tsetAttr \".bct\" %f;\n", bct);
	}
	void setCoverageThreshold(float cct)
	{
		if(cct == 0.125) return;
		fprintf(mFile,"\tsetAttr \".cct\" %f;\n", cct);
	}
	void getReflections()const
	{
		fprintf(mFile,"\"%s.rfl\"",mName.c_str());
	}
	void getRefractions()const
	{
		fprintf(mFile,"\"%s.rfr\"",mName.c_str());
	}
	void getShadows()const
	{
		fprintf(mFile,"\"%s.sl\"",mName.c_str());
	}
	void getRayTraceBias()const
	{
		fprintf(mFile,"\"%s.rtb\"",mName.c_str());
	}
	void getEdgeAntiAliasing()const
	{
		fprintf(mFile,"\"%s.eaa\"",mName.c_str());
	}
	void getRenderSample()const
	{
		fprintf(mFile,"\"%s.rsdn\"",mName.c_str());
	}
	void getUseMultiPixelFilter()const
	{
		fprintf(mFile,"\"%s.ufil\"",mName.c_str());
	}
	void getPixelFilterType()const
	{
		fprintf(mFile,"\"%s.pft\"",mName.c_str());
	}
	void getPixelFilterWidthX()const
	{
		fprintf(mFile,"\"%s.pfwx\"",mName.c_str());
	}
	void getPixelFilterWidthY()const
	{
		fprintf(mFile,"\"%s.pfwy\"",mName.c_str());
	}
	void getPlugInFilterWeight()const
	{
		fprintf(mFile,"\"%s.pifw\"",mName.c_str());
	}
	void getShadingSamples()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getMaxShadingSamples()const
	{
		fprintf(mFile,"\"%s.mss\"",mName.c_str());
	}
	void getVisibilitySamples()const
	{
		fprintf(mFile,"\"%s.mvs\"",mName.c_str());
	}
	void getMaxVisibilitySamples()const
	{
		fprintf(mFile,"\"%s.mvm\"",mName.c_str());
	}
	void getVolumeSamples()const
	{
		fprintf(mFile,"\"%s.vs\"",mName.c_str());
	}
	void getParticleSamples()const
	{
		fprintf(mFile,"\"%s.pss\"",mName.c_str());
	}
	void getEnableRaytracing()const
	{
		fprintf(mFile,"\"%s.ert\"",mName.c_str());
	}
	void getRedThreshold()const
	{
		fprintf(mFile,"\"%s.rct\"",mName.c_str());
	}
	void getGreenThreshold()const
	{
		fprintf(mFile,"\"%s.gct\"",mName.c_str());
	}
	void getBlueThreshold()const
	{
		fprintf(mFile,"\"%s.bct\"",mName.c_str());
	}
	void getCoverageThreshold()const
	{
		fprintf(mFile,"\"%s.cct\"",mName.c_str());
	}
protected:
	RenderQuality(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_RENDERQUALITY_H__
