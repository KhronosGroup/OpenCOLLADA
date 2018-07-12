/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACESHAPE_H__
#define __MayaDM_SURFACESHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMControlPoint.h"
namespace MayaDM
{
class SurfaceShape : public ControlPoint
{
public:
	struct CollisionOffsetVelocityIncrement{
		float collisionOffsetVelocityIncrement_Position;
		float collisionOffsetVelocityIncrement_FloatValue;
		unsigned int collisionOffsetVelocityIncrement_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", collisionOffsetVelocityIncrement_Position);
			fprintf(file,"%f ", collisionOffsetVelocityIncrement_FloatValue);
			fprintf(file,"%i", collisionOffsetVelocityIncrement_Interp);
		}
	};
	struct CollisionDepthVelocityIncrement{
		float collisionDepthVelocityIncrement_Position;
		float collisionDepthVelocityIncrement_FloatValue;
		unsigned int collisionDepthVelocityIncrement_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", collisionDepthVelocityIncrement_Position);
			fprintf(file,"%f ", collisionDepthVelocityIncrement_FloatValue);
			fprintf(file,"%i", collisionDepthVelocityIncrement_Interp);
		}
	};
	struct CollisionOffsetVelocityMultiplier{
		float collisionOffsetVelocityMultiplier_Position;
		float collisionOffsetVelocityMultiplier_FloatValue;
		unsigned int collisionOffsetVelocityMultiplier_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", collisionOffsetVelocityMultiplier_Position);
			fprintf(file,"%f ", collisionOffsetVelocityMultiplier_FloatValue);
			fprintf(file,"%i", collisionOffsetVelocityMultiplier_Interp);
		}
	};
	struct CollisionDepthVelocityMultiplier{
		float collisionDepthVelocityMultiplier_Position;
		float collisionDepthVelocityMultiplier_FloatValue;
		unsigned int collisionDepthVelocityMultiplier_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", collisionDepthVelocityMultiplier_Position);
			fprintf(file,"%f ", collisionDepthVelocityMultiplier_FloatValue);
			fprintf(file,"%i", collisionDepthVelocityMultiplier_Interp);
		}
	};
public:

	SurfaceShape():ControlPoint(){}
	SurfaceShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ControlPoint(file, name, parent, "surfaceShape", shared, create){}
	virtual ~SurfaceShape(){}

	void setIgnoreHwShader(bool ih)
	{
		if(ih == false) return;
		fprintf(mFile,"\tsetAttr \".ih\" %i;\n", ih);
	}
	void setDoubleSided(bool ds)
	{
		if(ds == true) return;
		fprintf(mFile,"\tsetAttr \".ds\" %i;\n", ds);
	}
	void setOpposite(bool op)
	{
		if(op == false) return;
		fprintf(mFile,"\tsetAttr \".op\" %i;\n", op);
	}
	void setSmoothShading(bool smo)
	{
		if(smo == true) return;
		fprintf(mFile,"\tsetAttr \".smo\" %i;\n", smo);
	}
	void setBoundingBoxScale(const float3& bbs)
	{
		fprintf(mFile,"\tsetAttr \".bbs\" -type \"float3\" ");
		bbs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBoundingBoxScaleX(float bscx)
	{
		if(bscx == 1.5) return;
		fprintf(mFile,"\tsetAttr \".bbs.bscx\" %f;\n", bscx);
	}
	void setBoundingBoxScaleY(float bscy)
	{
		if(bscy == 1.5) return;
		fprintf(mFile,"\tsetAttr \".bbs.bscy\" %f;\n", bscy);
	}
	void setBoundingBoxScaleZ(float bscz)
	{
		if(bscz == 1.5) return;
		fprintf(mFile,"\tsetAttr \".bbs.bscz\" %f;\n", bscz);
	}
	void setFeatureDisplacement(bool fbda)
	{
		if(fbda == true) return;
		fprintf(mFile,"\tsetAttr \".fbda\" %i;\n", fbda);
	}
	void setInitialSampleRate(int dsr)
	{
		if(dsr == 6) return;
		fprintf(mFile,"\tsetAttr \".dsr\" %i;\n", dsr);
	}
	void setExtraSampleRate(int xsr)
	{
		if(xsr == 5) return;
		fprintf(mFile,"\tsetAttr \".xsr\" %i;\n", xsr);
	}
	void setTextureThreshold(int fth)
	{
		if(fth == 0) return;
		fprintf(mFile,"\tsetAttr \".fth\" %i;\n", fth);
	}
	void setNormalThreshold(float nat)
	{
		if(nat == 30) return;
		fprintf(mFile,"\tsetAttr \".nat\" %f;\n", nat);
	}
	void setDisplayHWEnvironment(bool dhe)
	{
		if(dhe == false) return;
		fprintf(mFile,"\tsetAttr \".dhe\" %i;\n", dhe);
	}
	void setCollisionOffsetVelocityIncrement(size_t covi_i,const CollisionOffsetVelocityIncrement& covi)
	{
		fprintf(mFile,"\tsetAttr \".covi[%i]\" ",covi_i);
		covi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCollisionOffsetVelocityIncrement(size_t covi_start,size_t covi_end,CollisionOffsetVelocityIncrement* covi)
	{
		fprintf(mFile,"\tsetAttr \".covi[%i:%i]\" ", covi_start,covi_end);
		size_t size = (covi_end-covi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			covi[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCollisionOffsetVelocityIncrement(size_t covi_start,size_t covi_end)const
	{
		fprintf(mFile,"\tsetAttr \".covi[%i:%i]\"",covi_start,covi_end);
		fprintf(mFile," -type \"CollisionOffsetVelocityIncrement\" ");
	}
	void appendCollisionOffsetVelocityIncrement(const CollisionOffsetVelocityIncrement& covi)const
	{
		fprintf(mFile," ");
		covi.write(mFile);
	}
	void endCollisionOffsetVelocityIncrement()const
	{
		fprintf(mFile,";\n");
	}
	void setCollisionOffsetVelocityIncrement_Position(size_t covi_i,float covip)
	{
		if(covip == 0.0) return;
		fprintf(mFile,"\tsetAttr \".covi[%i].covip\" %f;\n", covi_i,covip);
	}
	void setCollisionOffsetVelocityIncrement_FloatValue(size_t covi_i,float covifv)
	{
		if(covifv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".covi[%i].covifv\" %f;\n", covi_i,covifv);
	}
	void setCollisionOffsetVelocityIncrement_Interp(size_t covi_i,unsigned int covii)
	{
		if(covii == 0) return;
		fprintf(mFile,"\tsetAttr \".covi[%i].covii\" %i;\n", covi_i,covii);
	}
	void setCollisionDepthVelocityIncrement(size_t cdvi_i,const CollisionDepthVelocityIncrement& cdvi)
	{
		fprintf(mFile,"\tsetAttr \".cdvi[%i]\" ",cdvi_i);
		cdvi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCollisionDepthVelocityIncrement(size_t cdvi_start,size_t cdvi_end,CollisionDepthVelocityIncrement* cdvi)
	{
		fprintf(mFile,"\tsetAttr \".cdvi[%i:%i]\" ", cdvi_start,cdvi_end);
		size_t size = (cdvi_end-cdvi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cdvi[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCollisionDepthVelocityIncrement(size_t cdvi_start,size_t cdvi_end)const
	{
		fprintf(mFile,"\tsetAttr \".cdvi[%i:%i]\"",cdvi_start,cdvi_end);
		fprintf(mFile," -type \"CollisionDepthVelocityIncrement\" ");
	}
	void appendCollisionDepthVelocityIncrement(const CollisionDepthVelocityIncrement& cdvi)const
	{
		fprintf(mFile," ");
		cdvi.write(mFile);
	}
	void endCollisionDepthVelocityIncrement()const
	{
		fprintf(mFile,";\n");
	}
	void setCollisionDepthVelocityIncrement_Position(size_t cdvi_i,float cdvip)
	{
		if(cdvip == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cdvi[%i].cdvip\" %f;\n", cdvi_i,cdvip);
	}
	void setCollisionDepthVelocityIncrement_FloatValue(size_t cdvi_i,float cdvifv)
	{
		if(cdvifv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cdvi[%i].cdvifv\" %f;\n", cdvi_i,cdvifv);
	}
	void setCollisionDepthVelocityIncrement_Interp(size_t cdvi_i,unsigned int cdvii)
	{
		if(cdvii == 0) return;
		fprintf(mFile,"\tsetAttr \".cdvi[%i].cdvii\" %i;\n", cdvi_i,cdvii);
	}
	void setCollisionOffsetVelocityMultiplier(size_t covm_i,const CollisionOffsetVelocityMultiplier& covm)
	{
		fprintf(mFile,"\tsetAttr \".covm[%i]\" ",covm_i);
		covm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCollisionOffsetVelocityMultiplier(size_t covm_start,size_t covm_end,CollisionOffsetVelocityMultiplier* covm)
	{
		fprintf(mFile,"\tsetAttr \".covm[%i:%i]\" ", covm_start,covm_end);
		size_t size = (covm_end-covm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			covm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCollisionOffsetVelocityMultiplier(size_t covm_start,size_t covm_end)const
	{
		fprintf(mFile,"\tsetAttr \".covm[%i:%i]\"",covm_start,covm_end);
		fprintf(mFile," -type \"CollisionOffsetVelocityMultiplier\" ");
	}
	void appendCollisionOffsetVelocityMultiplier(const CollisionOffsetVelocityMultiplier& covm)const
	{
		fprintf(mFile," ");
		covm.write(mFile);
	}
	void endCollisionOffsetVelocityMultiplier()const
	{
		fprintf(mFile,";\n");
	}
	void setCollisionOffsetVelocityMultiplier_Position(size_t covm_i,float covmp)
	{
		if(covmp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".covm[%i].covmp\" %f;\n", covm_i,covmp);
	}
	void setCollisionOffsetVelocityMultiplier_FloatValue(size_t covm_i,float covmfv)
	{
		if(covmfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".covm[%i].covmfv\" %f;\n", covm_i,covmfv);
	}
	void setCollisionOffsetVelocityMultiplier_Interp(size_t covm_i,unsigned int covmi)
	{
		if(covmi == 0) return;
		fprintf(mFile,"\tsetAttr \".covm[%i].covmi\" %i;\n", covm_i,covmi);
	}
	void setCollisionDepthVelocityMultiplier(size_t cdvm_i,const CollisionDepthVelocityMultiplier& cdvm)
	{
		fprintf(mFile,"\tsetAttr \".cdvm[%i]\" ",cdvm_i);
		cdvm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCollisionDepthVelocityMultiplier(size_t cdvm_start,size_t cdvm_end,CollisionDepthVelocityMultiplier* cdvm)
	{
		fprintf(mFile,"\tsetAttr \".cdvm[%i:%i]\" ", cdvm_start,cdvm_end);
		size_t size = (cdvm_end-cdvm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cdvm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCollisionDepthVelocityMultiplier(size_t cdvm_start,size_t cdvm_end)const
	{
		fprintf(mFile,"\tsetAttr \".cdvm[%i:%i]\"",cdvm_start,cdvm_end);
		fprintf(mFile," -type \"CollisionDepthVelocityMultiplier\" ");
	}
	void appendCollisionDepthVelocityMultiplier(const CollisionDepthVelocityMultiplier& cdvm)const
	{
		fprintf(mFile," ");
		cdvm.write(mFile);
	}
	void endCollisionDepthVelocityMultiplier()const
	{
		fprintf(mFile,";\n");
	}
	void setCollisionDepthVelocityMultiplier_Position(size_t cdvm_i,float cdvmp)
	{
		if(cdvmp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cdvm[%i].cdvmp\" %f;\n", cdvm_i,cdvmp);
	}
	void setCollisionDepthVelocityMultiplier_FloatValue(size_t cdvm_i,float cdvmfv)
	{
		if(cdvmfv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cdvm[%i].cdvmfv\" %f;\n", cdvm_i,cdvmfv);
	}
	void setCollisionDepthVelocityMultiplier_Interp(size_t cdvm_i,unsigned int cdvmi)
	{
		if(cdvmi == 0) return;
		fprintf(mFile,"\tsetAttr \".cdvm[%i].cdvmi\" %i;\n", cdvm_i,cdvmi);
	}
	void getIgnoreHwShader()const
	{
		fprintf(mFile,"\"%s.ih\"",mName.c_str());
	}
	void getDoubleSided()const
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());
	}
	void getOpposite()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getSmoothShading()const
	{
		fprintf(mFile,"\"%s.smo\"",mName.c_str());
	}
	void getBoundingBoxScale()const
	{
		fprintf(mFile,"\"%s.bbs\"",mName.c_str());
	}
	void getBoundingBoxScaleX()const
	{
		fprintf(mFile,"\"%s.bbs.bscx\"",mName.c_str());
	}
	void getBoundingBoxScaleY()const
	{
		fprintf(mFile,"\"%s.bbs.bscy\"",mName.c_str());
	}
	void getBoundingBoxScaleZ()const
	{
		fprintf(mFile,"\"%s.bbs.bscz\"",mName.c_str());
	}
	void getFeatureDisplacement()const
	{
		fprintf(mFile,"\"%s.fbda\"",mName.c_str());
	}
	void getInitialSampleRate()const
	{
		fprintf(mFile,"\"%s.dsr\"",mName.c_str());
	}
	void getExtraSampleRate()const
	{
		fprintf(mFile,"\"%s.xsr\"",mName.c_str());
	}
	void getTextureThreshold()const
	{
		fprintf(mFile,"\"%s.fth\"",mName.c_str());
	}
	void getNormalThreshold()const
	{
		fprintf(mFile,"\"%s.nat\"",mName.c_str());
	}
	void getDisplayHWEnvironment()const
	{
		fprintf(mFile,"\"%s.dhe\"",mName.c_str());
	}
	void getCollisionOffsetVelocityIncrement(size_t covi_i)const
	{
		fprintf(mFile,"\"%s.covi[%i]\"",mName.c_str(),covi_i);
	}
	void getCollisionOffsetVelocityIncrement()const
	{

		fprintf(mFile,"\"%s.covi\"",mName.c_str());
	}
	void getCollisionOffsetVelocityIncrement_Position(size_t covi_i)const
	{
		fprintf(mFile,"\"%s.covi[%i].covip\"",mName.c_str(),covi_i);
	}
	void getCollisionOffsetVelocityIncrement_Position()const
	{

		fprintf(mFile,"\"%s.covi.covip\"",mName.c_str());
	}
	void getCollisionOffsetVelocityIncrement_FloatValue(size_t covi_i)const
	{
		fprintf(mFile,"\"%s.covi[%i].covifv\"",mName.c_str(),covi_i);
	}
	void getCollisionOffsetVelocityIncrement_FloatValue()const
	{

		fprintf(mFile,"\"%s.covi.covifv\"",mName.c_str());
	}
	void getCollisionOffsetVelocityIncrement_Interp(size_t covi_i)const
	{
		fprintf(mFile,"\"%s.covi[%i].covii\"",mName.c_str(),covi_i);
	}
	void getCollisionOffsetVelocityIncrement_Interp()const
	{

		fprintf(mFile,"\"%s.covi.covii\"",mName.c_str());
	}
	void getCollisionDepthVelocityIncrement(size_t cdvi_i)const
	{
		fprintf(mFile,"\"%s.cdvi[%i]\"",mName.c_str(),cdvi_i);
	}
	void getCollisionDepthVelocityIncrement()const
	{

		fprintf(mFile,"\"%s.cdvi\"",mName.c_str());
	}
	void getCollisionDepthVelocityIncrement_Position(size_t cdvi_i)const
	{
		fprintf(mFile,"\"%s.cdvi[%i].cdvip\"",mName.c_str(),cdvi_i);
	}
	void getCollisionDepthVelocityIncrement_Position()const
	{

		fprintf(mFile,"\"%s.cdvi.cdvip\"",mName.c_str());
	}
	void getCollisionDepthVelocityIncrement_FloatValue(size_t cdvi_i)const
	{
		fprintf(mFile,"\"%s.cdvi[%i].cdvifv\"",mName.c_str(),cdvi_i);
	}
	void getCollisionDepthVelocityIncrement_FloatValue()const
	{

		fprintf(mFile,"\"%s.cdvi.cdvifv\"",mName.c_str());
	}
	void getCollisionDepthVelocityIncrement_Interp(size_t cdvi_i)const
	{
		fprintf(mFile,"\"%s.cdvi[%i].cdvii\"",mName.c_str(),cdvi_i);
	}
	void getCollisionDepthVelocityIncrement_Interp()const
	{

		fprintf(mFile,"\"%s.cdvi.cdvii\"",mName.c_str());
	}
	void getCollisionOffsetVelocityMultiplier(size_t covm_i)const
	{
		fprintf(mFile,"\"%s.covm[%i]\"",mName.c_str(),covm_i);
	}
	void getCollisionOffsetVelocityMultiplier()const
	{

		fprintf(mFile,"\"%s.covm\"",mName.c_str());
	}
	void getCollisionOffsetVelocityMultiplier_Position(size_t covm_i)const
	{
		fprintf(mFile,"\"%s.covm[%i].covmp\"",mName.c_str(),covm_i);
	}
	void getCollisionOffsetVelocityMultiplier_Position()const
	{

		fprintf(mFile,"\"%s.covm.covmp\"",mName.c_str());
	}
	void getCollisionOffsetVelocityMultiplier_FloatValue(size_t covm_i)const
	{
		fprintf(mFile,"\"%s.covm[%i].covmfv\"",mName.c_str(),covm_i);
	}
	void getCollisionOffsetVelocityMultiplier_FloatValue()const
	{

		fprintf(mFile,"\"%s.covm.covmfv\"",mName.c_str());
	}
	void getCollisionOffsetVelocityMultiplier_Interp(size_t covm_i)const
	{
		fprintf(mFile,"\"%s.covm[%i].covmi\"",mName.c_str(),covm_i);
	}
	void getCollisionOffsetVelocityMultiplier_Interp()const
	{

		fprintf(mFile,"\"%s.covm.covmi\"",mName.c_str());
	}
	void getCollisionDepthVelocityMultiplier(size_t cdvm_i)const
	{
		fprintf(mFile,"\"%s.cdvm[%i]\"",mName.c_str(),cdvm_i);
	}
	void getCollisionDepthVelocityMultiplier()const
	{

		fprintf(mFile,"\"%s.cdvm\"",mName.c_str());
	}
	void getCollisionDepthVelocityMultiplier_Position(size_t cdvm_i)const
	{
		fprintf(mFile,"\"%s.cdvm[%i].cdvmp\"",mName.c_str(),cdvm_i);
	}
	void getCollisionDepthVelocityMultiplier_Position()const
	{

		fprintf(mFile,"\"%s.cdvm.cdvmp\"",mName.c_str());
	}
	void getCollisionDepthVelocityMultiplier_FloatValue(size_t cdvm_i)const
	{
		fprintf(mFile,"\"%s.cdvm[%i].cdvmfv\"",mName.c_str(),cdvm_i);
	}
	void getCollisionDepthVelocityMultiplier_FloatValue()const
	{

		fprintf(mFile,"\"%s.cdvm.cdvmfv\"",mName.c_str());
	}
	void getCollisionDepthVelocityMultiplier_Interp(size_t cdvm_i)const
	{
		fprintf(mFile,"\"%s.cdvm[%i].cdvmi\"",mName.c_str(),cdvm_i);
	}
	void getCollisionDepthVelocityMultiplier_Interp()const
	{

		fprintf(mFile,"\"%s.cdvm.cdvmi\"",mName.c_str());
	}
protected:
	SurfaceShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ControlPoint(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SURFACESHAPE_H__
