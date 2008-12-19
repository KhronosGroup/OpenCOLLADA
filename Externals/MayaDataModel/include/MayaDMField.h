/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
		void write(FILE* file) const
		{
			inputPositions.write(file);
			fprintf(file, " ");
			inputVelocities.write(file);
			fprintf(file, " ");
			inputMass.write(file);
			fprintf(file, " ");
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
	Field(FILE* file,const std::string& name,const std::string& parent=""):DynBase(file, name, parent, "field"){}
	virtual ~Field(){}
	void setMagnitude(double mag)
	{
		if(mag == 1.0) return;
		fprintf(mFile,"setAttr \".mag\" %f;\n", mag);

	}
	void setAttenuation(double att)
	{
		if(att == 0.0) return;
		fprintf(mFile,"setAttr \".att\" %f;\n", att);

	}
	void setMaxDistance(double max)
	{
		if(max == 1) return;
		fprintf(mFile,"setAttr \".max\" %f;\n", max);

	}
	void setApplyPerVertex(bool apv)
	{
		if(apv == false) return;
		fprintf(mFile,"setAttr \".apv\" %i;\n", apv);

	}
	void setUseMaxDistance(bool umd)
	{
		if(umd == false) return;
		fprintf(mFile,"setAttr \".umd\" %i;\n", umd);

	}
	void setInputData(size_t ind_i,const InputData& ind)
	{
		fprintf(mFile,"setAttr \".ind[%i]\" ",ind_i);
		ind.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputPositions(size_t ind_i,const vectorArray& inp)
	{
		if(inp.size == 0) return;
		fprintf(mFile,"setAttr \".ind[%i].inp\" -type \"vectorArray\" ",ind_i);
		inp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputVelocities(size_t ind_i,const vectorArray& inv)
	{
		if(inv.size == 0) return;
		fprintf(mFile,"setAttr \".ind[%i].inv\" -type \"vectorArray\" ",ind_i);
		inv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputMass(size_t ind_i,const doubleArray& inm)
	{
		if(inm.size == 0) return;
		fprintf(mFile,"setAttr \".ind[%i].inm\" -type \"doubleArray\" ",ind_i);
		inm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVolumeShape(unsigned int vol)
	{
		if(vol == 0) return;
		fprintf(mFile,"setAttr \".vol\" %i;\n", vol);

	}
	void setVolumeExclusion(bool vex)
	{
		if(vex == false) return;
		fprintf(mFile,"setAttr \".vex\" %i;\n", vex);

	}
	void setVolumeOffset(const double3& vfo)
	{
		fprintf(mFile,"setAttr \".vfo\" -type \"double3\" ");
		vfo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVolumeOffsetX(double vox)
	{
		if(vox == 0) return;
		fprintf(mFile,"setAttr \".vfo.vox\" %f;\n", vox);

	}
	void setVolumeOffsetY(double voy)
	{
		if(voy == 0) return;
		fprintf(mFile,"setAttr \".vfo.voy\" %f;\n", voy);

	}
	void setVolumeOffsetZ(double voz)
	{
		if(voz == 0) return;
		fprintf(mFile,"setAttr \".vfo.voz\" %f;\n", voz);

	}
	void setSectionRadius(double tsr)
	{
		if(tsr == 0) return;
		fprintf(mFile,"setAttr \".tsr\" %f;\n", tsr);

	}
	void setVolumeSweep(double vsw)
	{
		if(vsw == 3) return;
		fprintf(mFile,"setAttr \".vsw\" %f;\n", vsw);

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
	void getMagnitude()
	{
		fprintf(mFile,"\"%s.mag\"",mName.c_str());

	}
	void getAttenuation()
	{
		fprintf(mFile,"\"%s.att\"",mName.c_str());

	}
	void getMaxDistance()
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());

	}
	void getApplyPerVertex()
	{
		fprintf(mFile,"\"%s.apv\"",mName.c_str());

	}
	void getUseMaxDistance()
	{
		fprintf(mFile,"\"%s.umd\"",mName.c_str());

	}
	void getInputData(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i]\"",mName.c_str(),ind_i);

	}
	void getInputPositions(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i].inp\"",mName.c_str(),ind_i);

	}
	void getInputVelocities(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i].inv\"",mName.c_str(),ind_i);

	}
	void getInputMass(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i].inm\"",mName.c_str(),ind_i);

	}
	void getDeltaTime(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i].dt\"",mName.c_str(),ind_i);

	}
	void getInputForce(size_t inf_i)
	{
		fprintf(mFile,"\"%s.inf[%i]\"",mName.c_str(),inf_i);

	}
	void getOutputForce(size_t of_i)
	{
		fprintf(mFile,"\"%s.of[%i]\"",mName.c_str(),of_i);

	}
	void getVolumeShape()
	{
		fprintf(mFile,"\"%s.vol\"",mName.c_str());

	}
	void getVolumeExclusion()
	{
		fprintf(mFile,"\"%s.vex\"",mName.c_str());

	}
	void getVolumeOffset()
	{
		fprintf(mFile,"\"%s.vfo\"",mName.c_str());

	}
	void getVolumeOffsetX()
	{
		fprintf(mFile,"\"%s.vfo.vox\"",mName.c_str());

	}
	void getVolumeOffsetY()
	{
		fprintf(mFile,"\"%s.vfo.voy\"",mName.c_str());

	}
	void getVolumeOffsetZ()
	{
		fprintf(mFile,"\"%s.vfo.voz\"",mName.c_str());

	}
	void getSectionRadius()
	{
		fprintf(mFile,"\"%s.tsr\"",mName.c_str());

	}
	void getVolumeSweep()
	{
		fprintf(mFile,"\"%s.vsw\"",mName.c_str());

	}
	void getInputPPData(size_t ppda_i)
	{
		fprintf(mFile,"\"%s.ppda[%i]\"",mName.c_str(),ppda_i);

	}
	void getOwnerPPData()
	{
		fprintf(mFile,"\"%s.oppd\"",mName.c_str());

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
protected:
	Field(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DynBase(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FIELD_H__
