/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FIELD_H__
#define __MayaDM_FIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDynBase.h"
namespace MayaDM
{
class Field : public DynBase
{
public:
	struct InputData{
		vectorArray inputPositions;
		vectorArray inputVelocities;
		doubleArray inputMass;
		double deltaTime;
		void write(FILE* file) const
		{
			inputPositions.write(file);
			fprintf(file, " ");
			inputVelocities.write(file);
			fprintf(file, " ");
			inputMass.write(file);
			fprintf(file, " ");
			fprintf(file,"%f", deltaTime);
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

	Field():DynBase(){}
	Field(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DynBase(file, name, parent, "field", shared, create){}
	virtual ~Field(){}

	void setMagnitude(double mag)
	{
		if(mag == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mag\" %f;\n", mag);
	}
	void setAttenuation(double att)
	{
		if(att == 0.0) return;
		fprintf(mFile,"\tsetAttr \".att\" %f;\n", att);
	}
	void setMaxDistance(double max)
	{
		if(max == 1) return;
		fprintf(mFile,"\tsetAttr \".max\" %f;\n", max);
	}
	void setApplyPerVertex(bool apv)
	{
		if(apv == false) return;
		fprintf(mFile,"\tsetAttr \".apv\" %i;\n", apv);
	}
	void setUseMaxDistance(bool umd)
	{
		if(umd == false) return;
		fprintf(mFile,"\tsetAttr \".umd\" %i;\n", umd);
	}
	void setInputData(size_t ind_i,const InputData& ind)
	{
		fprintf(mFile,"\tsetAttr \".ind[%i]\" ",ind_i);
		ind.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputData(size_t ind_start,size_t ind_end,InputData* ind)
	{
		fprintf(mFile,"\tsetAttr \".ind[%i:%i]\" ", ind_start,ind_end);
		size_t size = (ind_end-ind_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ind[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputData(size_t ind_start,size_t ind_end)const
	{
		fprintf(mFile,"\tsetAttr \".ind[%i:%i]\"",ind_start,ind_end);
		fprintf(mFile," -type \"InputData\" ");
	}
	void appendInputData(const InputData& ind)const
	{
		fprintf(mFile," ");
		ind.write(mFile);
	}
	void endInputData()const
	{
		fprintf(mFile,";\n");
	}
	void setInputPositions(size_t ind_i,const vectorArray& inp)
	{
		if(inp.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ind[%i].inp\" -type \"vectorArray\" ",ind_i);
		inp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputVelocities(size_t ind_i,const vectorArray& inv)
	{
		if(inv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ind[%i].inv\" -type \"vectorArray\" ",ind_i);
		inv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputMass(size_t ind_i,const doubleArray& inm)
	{
		if(inm.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ind[%i].inm\" -type \"doubleArray\" ",ind_i);
		inm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDeltaTime(size_t ind_i,double dt)
	{
		if(dt == 0) return;
		fprintf(mFile,"\tsetAttr \".ind[%i].dt\" %f;\n", ind_i,dt);
	}
	void setVolumeShape(unsigned int vol)
	{
		if(vol == 0) return;
		fprintf(mFile,"\tsetAttr \".vol\" %i;\n", vol);
	}
	void setVolumeExclusion(bool vex)
	{
		if(vex == false) return;
		fprintf(mFile,"\tsetAttr \".vex\" %i;\n", vex);
	}
	void setVolumeOffset(const double3& vfo)
	{
		fprintf(mFile,"\tsetAttr \".vfo\" -type \"double3\" ");
		vfo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVolumeOffsetX(double vox)
	{
		if(vox == 0) return;
		fprintf(mFile,"\tsetAttr \".vfo.vox\" %f;\n", vox);
	}
	void setVolumeOffsetY(double voy)
	{
		if(voy == 0) return;
		fprintf(mFile,"\tsetAttr \".vfo.voy\" %f;\n", voy);
	}
	void setVolumeOffsetZ(double voz)
	{
		if(voz == 0) return;
		fprintf(mFile,"\tsetAttr \".vfo.voz\" %f;\n", voz);
	}
	void setSectionRadius(double tsr)
	{
		if(tsr == 0) return;
		fprintf(mFile,"\tsetAttr \".tsr\" %f;\n", tsr);
	}
	void setVolumeSweep(double vsw)
	{
		if(vsw == 3) return;
		fprintf(mFile,"\tsetAttr \".vsw\" %f;\n", vsw);
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
	void getMagnitude()const
	{
		fprintf(mFile,"\"%s.mag\"",mName.c_str());
	}
	void getAttenuation()const
	{
		fprintf(mFile,"\"%s.att\"",mName.c_str());
	}
	void getMaxDistance()const
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());
	}
	void getApplyPerVertex()const
	{
		fprintf(mFile,"\"%s.apv\"",mName.c_str());
	}
	void getUseMaxDistance()const
	{
		fprintf(mFile,"\"%s.umd\"",mName.c_str());
	}
	void getInputData(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i]\"",mName.c_str(),ind_i);
	}
	void getInputData()const
	{

		fprintf(mFile,"\"%s.ind\"",mName.c_str());
	}
	void getInputPositions(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i].inp\"",mName.c_str(),ind_i);
	}
	void getInputPositions()const
	{

		fprintf(mFile,"\"%s.ind.inp\"",mName.c_str());
	}
	void getInputVelocities(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i].inv\"",mName.c_str(),ind_i);
	}
	void getInputVelocities()const
	{

		fprintf(mFile,"\"%s.ind.inv\"",mName.c_str());
	}
	void getInputMass(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i].inm\"",mName.c_str(),ind_i);
	}
	void getInputMass()const
	{

		fprintf(mFile,"\"%s.ind.inm\"",mName.c_str());
	}
	void getDeltaTime(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i].dt\"",mName.c_str(),ind_i);
	}
	void getDeltaTime()const
	{

		fprintf(mFile,"\"%s.ind.dt\"",mName.c_str());
	}
	void getInputForce(size_t inf_i)const
	{
		fprintf(mFile,"\"%s.inf[%i]\"",mName.c_str(),inf_i);
	}
	void getInputForce()const
	{

		fprintf(mFile,"\"%s.inf\"",mName.c_str());
	}
	void getOutputForce(size_t of_i)const
	{
		fprintf(mFile,"\"%s.of[%i]\"",mName.c_str(),of_i);
	}
	void getOutputForce()const
	{

		fprintf(mFile,"\"%s.of\"",mName.c_str());
	}
	void getVolumeShape()const
	{
		fprintf(mFile,"\"%s.vol\"",mName.c_str());
	}
	void getVolumeExclusion()const
	{
		fprintf(mFile,"\"%s.vex\"",mName.c_str());
	}
	void getVolumeOffset()const
	{
		fprintf(mFile,"\"%s.vfo\"",mName.c_str());
	}
	void getVolumeOffsetX()const
	{
		fprintf(mFile,"\"%s.vfo.vox\"",mName.c_str());
	}
	void getVolumeOffsetY()const
	{
		fprintf(mFile,"\"%s.vfo.voy\"",mName.c_str());
	}
	void getVolumeOffsetZ()const
	{
		fprintf(mFile,"\"%s.vfo.voz\"",mName.c_str());
	}
	void getSectionRadius()const
	{
		fprintf(mFile,"\"%s.tsr\"",mName.c_str());
	}
	void getVolumeSweep()const
	{
		fprintf(mFile,"\"%s.vsw\"",mName.c_str());
	}
	void getInputPPData(size_t ppda_i)const
	{
		fprintf(mFile,"\"%s.ppda[%i]\"",mName.c_str(),ppda_i);
	}
	void getInputPPData()const
	{

		fprintf(mFile,"\"%s.ppda\"",mName.c_str());
	}
	void getOwnerPPData()const
	{
		fprintf(mFile,"\"%s.oppd\"",mName.c_str());
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
protected:
	Field(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DynBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FIELD_H__
