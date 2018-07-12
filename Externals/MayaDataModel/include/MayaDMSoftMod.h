/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SOFTMOD_H__
#define __MayaDM_SOFTMOD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
class SoftMod : public WeightGeometryFilter
{
public:
	struct SoftModXforms{
		void write(FILE* file) const
		{
		}
	};
	struct FalloffCurve{
		float falloffCurve_Position;
		float falloffCurve_FloatValue;
		unsigned int falloffCurve_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", falloffCurve_Position);
			fprintf(file,"%f ", falloffCurve_FloatValue);
			fprintf(file,"%i", falloffCurve_Interp);
		}
	};
public:

	SoftMod():WeightGeometryFilter(){}
	SoftMod(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:WeightGeometryFilter(file, name, parent, "softMod", shared, create){}
	virtual ~SoftMod(){}

	void setPercentResolution(float ptr)
	{
		if(ptr == 5) return;
		fprintf(mFile,"\tsetAttr \".ptr\" %f;\n", ptr);
	}
	void setUsePartialResolution(unsigned int upr)
	{
		if(upr == 0) return;
		fprintf(mFile,"\tsetAttr \".upr\" %i;\n", upr);
	}
	void setRelative(bool rel)
	{
		if(rel == false) return;
		fprintf(mFile,"\tsetAttr \".rel\" %i;\n", rel);
	}
	void setWeightedCompensationMatrix(const matrix& wcm)
	{
		if(wcm == identity) return;
		fprintf(mFile,"\tsetAttr \".wcm\" -type \"matrix\" ");
		wcm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGeomMatrix(size_t gm_i,const matrix& gm)
	{
		if(gm == identity) return;
		fprintf(mFile,"\tsetAttr \".gm[%i]\" -type \"matrix\" ",gm_i);
		gm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGeomMatrix(size_t gm_start,size_t gm_end,matrix* gm)
	{
		fprintf(mFile,"\tsetAttr \".gm[%i:%i]\" ", gm_start,gm_end);
		size_t size = (gm_end-gm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			gm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startGeomMatrix(size_t gm_start,size_t gm_end)const
	{
		fprintf(mFile,"\tsetAttr \".gm[%i:%i]\"",gm_start,gm_end);
		fprintf(mFile," -type \"matrix\" ");
	}
	void appendGeomMatrix(const matrix& gm)const
	{
		fprintf(mFile," ");
		gm.write(mFile);
	}
	void endGeomMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setMatrix(const matrix& ma)
	{
		if(ma == identity) return;
		fprintf(mFile,"\tsetAttr \".ma\" -type \"matrix\" ");
		ma.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBindPreMatrix(const matrix& pm)
	{
		if(pm == identity) return;
		fprintf(mFile,"\tsetAttr \".pm\" -type \"matrix\" ");
		pm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFalloffCurve(size_t fc_i,const FalloffCurve& fc)
	{
		fprintf(mFile,"\tsetAttr \".fc[%i]\" ",fc_i);
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFalloffCurve(size_t fc_start,size_t fc_end,FalloffCurve* fc)
	{
		fprintf(mFile,"\tsetAttr \".fc[%i:%i]\" ", fc_start,fc_end);
		size_t size = (fc_end-fc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fc[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startFalloffCurve(size_t fc_start,size_t fc_end)const
	{
		fprintf(mFile,"\tsetAttr \".fc[%i:%i]\"",fc_start,fc_end);
		fprintf(mFile," -type \"FalloffCurve\" ");
	}
	void appendFalloffCurve(const FalloffCurve& fc)const
	{
		fprintf(mFile," ");
		fc.write(mFile);
	}
	void endFalloffCurve()const
	{
		fprintf(mFile,";\n");
	}
	void setFalloffCurve_Position(size_t fc_i,float fcp)
	{
		if(fcp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc[%i].fcp\" %f;\n", fc_i,fcp);
	}
	void setFalloffCurve_FloatValue(size_t fc_i,float fcfv)
	{
		if(fcfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fc[%i].fcfv\" %f;\n", fc_i,fcfv);
	}
	void setFalloffCurve_Interp(size_t fc_i,unsigned int fci)
	{
		if(fci == 0) return;
		fprintf(mFile,"\tsetAttr \".fc[%i].fci\" %i;\n", fc_i,fci);
	}
	void setFalloffRadius(double fr)
	{
		if(fr == 5) return;
		fprintf(mFile,"\tsetAttr \".fr\" %f;\n", fr);
	}
	void setFalloffCenter(const double3& fcr)
	{
		fprintf(mFile,"\tsetAttr \".fcr\" -type \"double3\" ");
		fcr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFalloffCenterX(double fcx)
	{
		if(fcx == 0) return;
		fprintf(mFile,"\tsetAttr \".fcr.fcx\" %f;\n", fcx);
	}
	void setFalloffCenterY(double fcy)
	{
		if(fcy == 0) return;
		fprintf(mFile,"\tsetAttr \".fcr.fcy\" %f;\n", fcy);
	}
	void setFalloffCenterZ(double fcz)
	{
		if(fcz == 0) return;
		fprintf(mFile,"\tsetAttr \".fcr.fcz\" %f;\n", fcz);
	}
	void setFalloffInX(bool fix)
	{
		if(fix == true) return;
		fprintf(mFile,"\tsetAttr \".fix\" %i;\n", fix);
	}
	void setFalloffInY(bool fiy)
	{
		if(fiy == true) return;
		fprintf(mFile,"\tsetAttr \".fiy\" %i;\n", fiy);
	}
	void setFalloffInZ(bool fiz)
	{
		if(fiz == true) return;
		fprintf(mFile,"\tsetAttr \".fiz\" %i;\n", fiz);
	}
	void setFalloffAroundSelection(bool fas)
	{
		if(fas == true) return;
		fprintf(mFile,"\tsetAttr \".fas\" %i;\n", fas);
	}
	void setFalloffMasking(bool fm)
	{
		if(fm == true) return;
		fprintf(mFile,"\tsetAttr \".fm\" %i;\n", fm);
	}
	void setInfluenceMatrix(const matrix& im)
	{
		if(im == identity) return;
		fprintf(mFile,"\tsetAttr \".im\" -type \"matrix\" ");
		im.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAngleInterpolation(unsigned int ait)
	{
		if(ait == 0) return;
		fprintf(mFile,"\tsetAttr \".ait\" %i;\n", ait);
	}
	void setUseDistanceCache(bool udc)
	{
		if(udc == true) return;
		fprintf(mFile,"\tsetAttr \".udc\" %i;\n", udc);
	}
	void setFalloffMode(unsigned int fom)
	{
		if(fom == 0) return;
		fprintf(mFile,"\tsetAttr \".fom\" %i;\n", fom);
	}
	void getUsePartialResolution()const
	{
		fprintf(mFile,"\"%s.upr\"",mName.c_str());
	}
	void getRelative()const
	{
		fprintf(mFile,"\"%s.rel\"",mName.c_str());
	}
	void getSoftModXforms()const
	{
		fprintf(mFile,"\"%s.x\"",mName.c_str());
	}
	void getPreMatrix()const
	{
		fprintf(mFile,"\"%s.x.pre\"",mName.c_str());
	}
	void getWeightedMatrix()const
	{
		fprintf(mFile,"\"%s.x.wt\"",mName.c_str());
	}
	void getPostMatrix()const
	{
		fprintf(mFile,"\"%s.x.post\"",mName.c_str());
	}
	void getWeightedCompensationMatrix()const
	{
		fprintf(mFile,"\"%s.wcm\"",mName.c_str());
	}
	void getGeomMatrix(size_t gm_i)const
	{
		fprintf(mFile,"\"%s.gm[%i]\"",mName.c_str(),gm_i);
	}
	void getGeomMatrix()const
	{

		fprintf(mFile,"\"%s.gm\"",mName.c_str());
	}
	void getMatrix()const
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());
	}
	void getBindPreMatrix()const
	{
		fprintf(mFile,"\"%s.pm\"",mName.c_str());
	}
	void getFalloffCurve(size_t fc_i)const
	{
		fprintf(mFile,"\"%s.fc[%i]\"",mName.c_str(),fc_i);
	}
	void getFalloffCurve()const
	{

		fprintf(mFile,"\"%s.fc\"",mName.c_str());
	}
	void getFalloffCurve_Position(size_t fc_i)const
	{
		fprintf(mFile,"\"%s.fc[%i].fcp\"",mName.c_str(),fc_i);
	}
	void getFalloffCurve_Position()const
	{

		fprintf(mFile,"\"%s.fc.fcp\"",mName.c_str());
	}
	void getFalloffCurve_FloatValue(size_t fc_i)const
	{
		fprintf(mFile,"\"%s.fc[%i].fcfv\"",mName.c_str(),fc_i);
	}
	void getFalloffCurve_FloatValue()const
	{

		fprintf(mFile,"\"%s.fc.fcfv\"",mName.c_str());
	}
	void getFalloffCurve_Interp(size_t fc_i)const
	{
		fprintf(mFile,"\"%s.fc[%i].fci\"",mName.c_str(),fc_i);
	}
	void getFalloffCurve_Interp()const
	{

		fprintf(mFile,"\"%s.fc.fci\"",mName.c_str());
	}
	void getFalloffRadius()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getFalloffCenter()const
	{
		fprintf(mFile,"\"%s.fcr\"",mName.c_str());
	}
	void getFalloffCenterX()const
	{
		fprintf(mFile,"\"%s.fcr.fcx\"",mName.c_str());
	}
	void getFalloffCenterY()const
	{
		fprintf(mFile,"\"%s.fcr.fcy\"",mName.c_str());
	}
	void getFalloffCenterZ()const
	{
		fprintf(mFile,"\"%s.fcr.fcz\"",mName.c_str());
	}
	void getFalloffInX()const
	{
		fprintf(mFile,"\"%s.fix\"",mName.c_str());
	}
	void getFalloffInY()const
	{
		fprintf(mFile,"\"%s.fiy\"",mName.c_str());
	}
	void getFalloffInZ()const
	{
		fprintf(mFile,"\"%s.fiz\"",mName.c_str());
	}
	void getFalloffAroundSelection()const
	{
		fprintf(mFile,"\"%s.fas\"",mName.c_str());
	}
	void getFalloffMasking()const
	{
		fprintf(mFile,"\"%s.fm\"",mName.c_str());
	}
	void getInfluenceMatrix()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getAngleInterpolation()const
	{
		fprintf(mFile,"\"%s.ait\"",mName.c_str());
	}
	void getUseDistanceCache()const
	{
		fprintf(mFile,"\"%s.udc\"",mName.c_str());
	}
	void getDistanceCacheDirty()const
	{
		fprintf(mFile,"\"%s.dcd\"",mName.c_str());
	}
	void getFalloffMode()const
	{
		fprintf(mFile,"\"%s.fom\"",mName.c_str());
	}
protected:
	SoftMod(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:WeightGeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SOFTMOD_H__
