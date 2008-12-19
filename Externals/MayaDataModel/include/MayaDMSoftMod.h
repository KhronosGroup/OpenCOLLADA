/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	SoftMod(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "softMod"){}
	virtual ~SoftMod(){}
	void setPercentResolution(float ptr)
	{
		if(ptr == 5) return;
		fprintf(mFile,"setAttr \".ptr\" %f;\n", ptr);

	}
	void setUsePartialResolution(unsigned int upr)
	{
		if(upr == 0) return;
		fprintf(mFile,"setAttr \".upr\" %i;\n", upr);

	}
	void setRelative(bool rel)
	{
		if(rel == false) return;
		fprintf(mFile,"setAttr \".rel\" %i;\n", rel);

	}
	void setWeightedCompensationMatrix(const matrix& wcm)
	{
		if(wcm == identity) return;
		fprintf(mFile,"setAttr \".wcm\" -type \"matrix\" ");
		wcm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGeomMatrix(size_t gm_i,const matrix& gm)
	{
		if(gm == identity) return;
		fprintf(mFile,"setAttr \".gm[%i]\" -type \"matrix\" ",gm_i);
		gm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMatrix(const matrix& ma)
	{
		if(ma == identity) return;
		fprintf(mFile,"setAttr \".ma\" -type \"matrix\" ");
		ma.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBindPreMatrix(const matrix& pm)
	{
		if(pm == identity) return;
		fprintf(mFile,"setAttr \".pm\" -type \"matrix\" ");
		pm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFalloffCurve(size_t fc_i,const FalloffCurve& fc)
	{
		fprintf(mFile,"setAttr \".fc[%i]\" ",fc_i);
		fc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFalloffCurve_Position(size_t fc_i,float fcp)
	{
		if(fcp == 0.0) return;
		fprintf(mFile,"setAttr \".fc[%i].fcp\" %f;\n", fc_i,fcp);

	}
	void setFalloffCurve_FloatValue(size_t fc_i,float fcfv)
	{
		if(fcfv == 0.0) return;
		fprintf(mFile,"setAttr \".fc[%i].fcfv\" %f;\n", fc_i,fcfv);

	}
	void setFalloffCurve_Interp(size_t fc_i,unsigned int fci)
	{
		if(fci == 0) return;
		fprintf(mFile,"setAttr \".fc[%i].fci\" %i;\n", fc_i,fci);

	}
	void setFalloffRadius(double fr)
	{
		if(fr == 5) return;
		fprintf(mFile,"setAttr \".fr\" %f;\n", fr);

	}
	void setFalloffCenter(const double3& fcr)
	{
		fprintf(mFile,"setAttr \".fcr\" -type \"double3\" ");
		fcr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFalloffCenterX(double fcx)
	{
		if(fcx == 0) return;
		fprintf(mFile,"setAttr \".fcr.fcx\" %f;\n", fcx);

	}
	void setFalloffCenterY(double fcy)
	{
		if(fcy == 0) return;
		fprintf(mFile,"setAttr \".fcr.fcy\" %f;\n", fcy);

	}
	void setFalloffCenterZ(double fcz)
	{
		if(fcz == 0) return;
		fprintf(mFile,"setAttr \".fcr.fcz\" %f;\n", fcz);

	}
	void setFalloffInX(bool fix)
	{
		if(fix == true) return;
		fprintf(mFile,"setAttr \".fix\" %i;\n", fix);

	}
	void setFalloffInY(bool fiy)
	{
		if(fiy == true) return;
		fprintf(mFile,"setAttr \".fiy\" %i;\n", fiy);

	}
	void setFalloffInZ(bool fiz)
	{
		if(fiz == true) return;
		fprintf(mFile,"setAttr \".fiz\" %i;\n", fiz);

	}
	void setFalloffAroundSelection(bool fas)
	{
		if(fas == true) return;
		fprintf(mFile,"setAttr \".fas\" %i;\n", fas);

	}
	void setFalloffMasking(bool fm)
	{
		if(fm == true) return;
		fprintf(mFile,"setAttr \".fm\" %i;\n", fm);

	}
	void setInfluenceMatrix(const matrix& im)
	{
		if(im == identity) return;
		fprintf(mFile,"setAttr \".im\" -type \"matrix\" ");
		im.write(mFile);
		fprintf(mFile,";\n");

	}
	void setAngleInterpolation(unsigned int ait)
	{
		if(ait == 0) return;
		fprintf(mFile,"setAttr \".ait\" %i;\n", ait);

	}
	void setUseDistanceCache(bool udc)
	{
		if(udc == true) return;
		fprintf(mFile,"setAttr \".udc\" %i;\n", udc);

	}
	void setFalloffMode(unsigned int fom)
	{
		if(fom == 0) return;
		fprintf(mFile,"setAttr \".fom\" %i;\n", fom);

	}
	void getUsePartialResolution()
	{
		fprintf(mFile,"\"%s.upr\"",mName.c_str());

	}
	void getRelative()
	{
		fprintf(mFile,"\"%s.rel\"",mName.c_str());

	}
	void getSoftModXforms()
	{
		fprintf(mFile,"\"%s.x\"",mName.c_str());

	}
	void getPreMatrix()
	{
		fprintf(mFile,"\"%s.x.pre\"",mName.c_str());

	}
	void getWeightedMatrix()
	{
		fprintf(mFile,"\"%s.x.wt\"",mName.c_str());

	}
	void getPostMatrix()
	{
		fprintf(mFile,"\"%s.x.post\"",mName.c_str());

	}
	void getWeightedCompensationMatrix()
	{
		fprintf(mFile,"\"%s.wcm\"",mName.c_str());

	}
	void getGeomMatrix(size_t gm_i)
	{
		fprintf(mFile,"\"%s.gm[%i]\"",mName.c_str(),gm_i);

	}
	void getMatrix()
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());

	}
	void getBindPreMatrix()
	{
		fprintf(mFile,"\"%s.pm\"",mName.c_str());

	}
	void getFalloffCurve(size_t fc_i)
	{
		fprintf(mFile,"\"%s.fc[%i]\"",mName.c_str(),fc_i);

	}
	void getFalloffCurve_Position(size_t fc_i)
	{
		fprintf(mFile,"\"%s.fc[%i].fcp\"",mName.c_str(),fc_i);

	}
	void getFalloffCurve_FloatValue(size_t fc_i)
	{
		fprintf(mFile,"\"%s.fc[%i].fcfv\"",mName.c_str(),fc_i);

	}
	void getFalloffCurve_Interp(size_t fc_i)
	{
		fprintf(mFile,"\"%s.fc[%i].fci\"",mName.c_str(),fc_i);

	}
	void getFalloffRadius()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getFalloffCenter()
	{
		fprintf(mFile,"\"%s.fcr\"",mName.c_str());

	}
	void getFalloffCenterX()
	{
		fprintf(mFile,"\"%s.fcr.fcx\"",mName.c_str());

	}
	void getFalloffCenterY()
	{
		fprintf(mFile,"\"%s.fcr.fcy\"",mName.c_str());

	}
	void getFalloffCenterZ()
	{
		fprintf(mFile,"\"%s.fcr.fcz\"",mName.c_str());

	}
	void getFalloffInX()
	{
		fprintf(mFile,"\"%s.fix\"",mName.c_str());

	}
	void getFalloffInY()
	{
		fprintf(mFile,"\"%s.fiy\"",mName.c_str());

	}
	void getFalloffInZ()
	{
		fprintf(mFile,"\"%s.fiz\"",mName.c_str());

	}
	void getFalloffAroundSelection()
	{
		fprintf(mFile,"\"%s.fas\"",mName.c_str());

	}
	void getFalloffMasking()
	{
		fprintf(mFile,"\"%s.fm\"",mName.c_str());

	}
	void getInfluenceMatrix()
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());

	}
	void getAngleInterpolation()
	{
		fprintf(mFile,"\"%s.ait\"",mName.c_str());

	}
	void getUseDistanceCache()
	{
		fprintf(mFile,"\"%s.udc\"",mName.c_str());

	}
	void getDistanceCacheDirty()
	{
		fprintf(mFile,"\"%s.dcd\"",mName.c_str());

	}
	void getFalloffMode()
	{
		fprintf(mFile,"\"%s.fom\"",mName.c_str());

	}
protected:
	SoftMod(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):WeightGeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SOFTMOD_H__
