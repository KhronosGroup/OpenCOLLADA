/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURATTRACTORS_H__
#define __MayaDM_FURATTRACTORS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class FurAttractors : public DependNode
{
public:
	struct RadiusMap{
	};
	struct RadiusMapUSamples{
	};
	struct RadiusMapVSamples{
	};
	struct PowerMap{
	};
	struct PowerMapUSamples{
	};
	struct PowerMapVSamples{
	};
	struct InfluenceMap{
	};
	struct InfluenceMapUSamples{
	};
	struct InfluenceMapVSamples{
	};
	struct StartLengthMap{
	};
	struct StartLengthMapUSamples{
	};
	struct StartLengthMapVSamples{
	};
	struct EndLengthMap{
	};
	struct EndLengthMapUSamples{
	};
	struct EndLengthMapVSamples{
	};
	struct ThresholdLengthMap{
	};
	struct ThresholdLengthMapUSamples{
	};
	struct ThresholdLengthMapVSamples{
	};
public:

	FurAttractors():DependNode(){}
	FurAttractors(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "FurAttractors", shared, create){}
	virtual ~FurAttractors(){}

	void setAttractorModel(unsigned int amd)
	{
		if(amd == 0) return;
		fprintf(mFile,"\tsetAttr \".amd\" %i;\n", amd);
	}
	void setAttractorsPerHair(int aph)
	{
		if(aph == 1) return;
		fprintf(mFile,"\tsetAttr \".aph\" %i;\n", aph);
	}
	void setGlobalScale(float gs)
	{
		if(gs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".gs\" %f;\n", gs);
	}
	void setRadius(double rd)
	{
		if(rd == 1) return;
		fprintf(mFile,"\tsetAttr \".rd\" %f;\n", rd);
	}
	void setRadiusMapOffset(double rmo)
	{
		if(rmo == 0) return;
		fprintf(mFile,"\tsetAttr \".rmo\" %f;\n", rmo);
	}
	void setRadiusMapMult(double rmm)
	{
		if(rmm == 1) return;
		fprintf(mFile,"\tsetAttr \".rmm\" %f;\n", rmm);
	}
	void setRadiusNoise(double rn)
	{
		if(rn == 0) return;
		fprintf(mFile,"\tsetAttr \".rn\" %f;\n", rn);
	}
	void setRadiusNoiseFreq(float rnf)
	{
		if(rnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".rnf\" %f;\n", rnf);
	}
	void setPower(float dp)
	{
		if(dp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dp\" %f;\n", dp);
	}
	void setPowerMapOffset(float pmo)
	{
		if(pmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pmo\" %f;\n", pmo);
	}
	void setPowerMapMult(float pmm)
	{
		if(pmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".pmm\" %f;\n", pmm);
	}
	void setPowerNoise(float pn)
	{
		if(pn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pn\" %f;\n", pn);
	}
	void setPowerNoiseFreq(float pnf)
	{
		if(pnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".pnf\" %f;\n", pnf);
	}
	void setInfluence(float di)
	{
		if(di == 1.0) return;
		fprintf(mFile,"\tsetAttr \".di\" %f;\n", di);
	}
	void setInfluenceMapOffset(float imo)
	{
		if(imo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imo\" %f;\n", imo);
	}
	void setInfluenceMapMult(float imm)
	{
		if(imm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".imm\" %f;\n", imm);
	}
	void setInfluenceNoise(float in)
	{
		if(in == 0.0) return;
		fprintf(mFile,"\tsetAttr \".in\" %f;\n", in);
	}
	void setInfluenceNoiseFreq(float inf)
	{
		if(inf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".inf\" %f;\n", inf);
	}
	void setStartLength(float dsl)
	{
		if(dsl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dsl\" %f;\n", dsl);
	}
	void setStartLengthMapOffset(double slmo)
	{
		if(slmo == 0) return;
		fprintf(mFile,"\tsetAttr \".slmo\" %f;\n", slmo);
	}
	void setStartLengthMapMult(double slmm)
	{
		if(slmm == 1) return;
		fprintf(mFile,"\tsetAttr \".slmm\" %f;\n", slmm);
	}
	void setStartLengthNoise(double sln)
	{
		if(sln == 0) return;
		fprintf(mFile,"\tsetAttr \".sln\" %f;\n", sln);
	}
	void setStartLengthNoiseFreq(float slnf)
	{
		if(slnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".slnf\" %f;\n", slnf);
	}
	void setEndLength(float del)
	{
		if(del == 5.0) return;
		fprintf(mFile,"\tsetAttr \".del\" %f;\n", del);
	}
	void setEndLengthMapOffset(double elmo)
	{
		if(elmo == 0) return;
		fprintf(mFile,"\tsetAttr \".elmo\" %f;\n", elmo);
	}
	void setEndLengthMapMult(double elmm)
	{
		if(elmm == 1) return;
		fprintf(mFile,"\tsetAttr \".elmm\" %f;\n", elmm);
	}
	void setEndLengthNoise(double eln)
	{
		if(eln == 0) return;
		fprintf(mFile,"\tsetAttr \".eln\" %f;\n", eln);
	}
	void setEndLengthNoiseFreq(float elnf)
	{
		if(elnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".elnf\" %f;\n", elnf);
	}
	void setThresholdLength(float dtl)
	{
		if(dtl == 0.33) return;
		fprintf(mFile,"\tsetAttr \".dtl\" %f;\n", dtl);
	}
	void setThresholdLengthMapOffset(double tlmo)
	{
		if(tlmo == 0) return;
		fprintf(mFile,"\tsetAttr \".tlmo\" %f;\n", tlmo);
	}
	void setThresholdLengthMapMult(double tlmm)
	{
		if(tlmm == 1) return;
		fprintf(mFile,"\tsetAttr \".tlmm\" %f;\n", tlmm);
	}
	void setThresholdLengthNoise(double tln)
	{
		if(tln == 0) return;
		fprintf(mFile,"\tsetAttr \".tln\" %f;\n", tln);
	}
	void setThresholdLengthNoiseFreq(float tlnf)
	{
		if(tlnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".tlnf\" %f;\n", tlnf);
	}
	void getAttractorModel()const
	{
		fprintf(mFile,"\"%s.amd\"",mName.c_str());
	}
	void getDagSetMembers()const
	{
		fprintf(mFile,"\"%s.dsm\"",mName.c_str());
	}
	void getAttractors()const
	{
		fprintf(mFile,"\"%s.att\"",mName.c_str());
	}
	void getFurGlobals()const
	{
		fprintf(mFile,"\"%s.fgc\"",mName.c_str());
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());
	}
	void getRadiusMap()const
	{
		fprintf(mFile,"\"%s.rm\"",mName.c_str());
	}
	void getRadiusMapUSamples()const
	{
		fprintf(mFile,"\"%s.rmus\"",mName.c_str());
	}
	void getRadiusMapVSamples()const
	{
		fprintf(mFile,"\"%s.rmvs\"",mName.c_str());
	}
	void getRadiusMapOffset()const
	{
		fprintf(mFile,"\"%s.rmo\"",mName.c_str());
	}
	void getRadiusMapMult()const
	{
		fprintf(mFile,"\"%s.rmm\"",mName.c_str());
	}
	void getRadiusNoise()const
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());
	}
	void getPower()const
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());
	}
	void getPowerMap()const
	{
		fprintf(mFile,"\"%s.pm\"",mName.c_str());
	}
	void getPowerMapUSamples()const
	{
		fprintf(mFile,"\"%s.pmus\"",mName.c_str());
	}
	void getPowerMapVSamples()const
	{
		fprintf(mFile,"\"%s.pmvs\"",mName.c_str());
	}
	void getPowerMapOffset()const
	{
		fprintf(mFile,"\"%s.pmo\"",mName.c_str());
	}
	void getPowerMapMult()const
	{
		fprintf(mFile,"\"%s.pmm\"",mName.c_str());
	}
	void getPowerNoise()const
	{
		fprintf(mFile,"\"%s.pn\"",mName.c_str());
	}
	void getInfluence()const
	{
		fprintf(mFile,"\"%s.di\"",mName.c_str());
	}
	void getInfluenceMap()const
	{
		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
	void getInfluenceMapUSamples()const
	{
		fprintf(mFile,"\"%s.imus\"",mName.c_str());
	}
	void getInfluenceMapVSamples()const
	{
		fprintf(mFile,"\"%s.imvs\"",mName.c_str());
	}
	void getInfluenceMapOffset()const
	{
		fprintf(mFile,"\"%s.imo\"",mName.c_str());
	}
	void getInfluenceMapMult()const
	{
		fprintf(mFile,"\"%s.imm\"",mName.c_str());
	}
	void getInfluenceNoise()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getStartLength()const
	{
		fprintf(mFile,"\"%s.dsl\"",mName.c_str());
	}
	void getStartLengthMap()const
	{
		fprintf(mFile,"\"%s.slm\"",mName.c_str());
	}
	void getStartLengthMapUSamples()const
	{
		fprintf(mFile,"\"%s.slmus\"",mName.c_str());
	}
	void getStartLengthMapVSamples()const
	{
		fprintf(mFile,"\"%s.slmvs\"",mName.c_str());
	}
	void getStartLengthMapOffset()const
	{
		fprintf(mFile,"\"%s.slmo\"",mName.c_str());
	}
	void getStartLengthMapMult()const
	{
		fprintf(mFile,"\"%s.slmm\"",mName.c_str());
	}
	void getStartLengthNoise()const
	{
		fprintf(mFile,"\"%s.sln\"",mName.c_str());
	}
	void getEndLength()const
	{
		fprintf(mFile,"\"%s.del\"",mName.c_str());
	}
	void getEndLengthMap()const
	{
		fprintf(mFile,"\"%s.elm\"",mName.c_str());
	}
	void getEndLengthMapUSamples()const
	{
		fprintf(mFile,"\"%s.elmus\"",mName.c_str());
	}
	void getEndLengthMapVSamples()const
	{
		fprintf(mFile,"\"%s.elmvs\"",mName.c_str());
	}
	void getEndLengthMapOffset()const
	{
		fprintf(mFile,"\"%s.elmo\"",mName.c_str());
	}
	void getEndLengthMapMult()const
	{
		fprintf(mFile,"\"%s.elmm\"",mName.c_str());
	}
	void getEndLengthNoise()const
	{
		fprintf(mFile,"\"%s.eln\"",mName.c_str());
	}
	void getThresholdLength()const
	{
		fprintf(mFile,"\"%s.dtl\"",mName.c_str());
	}
	void getThresholdLengthMap()const
	{
		fprintf(mFile,"\"%s.tlm\"",mName.c_str());
	}
	void getThresholdLengthMapUSamples()const
	{
		fprintf(mFile,"\"%s.tlmus\"",mName.c_str());
	}
	void getThresholdLengthMapVSamples()const
	{
		fprintf(mFile,"\"%s.tlmvs\"",mName.c_str());
	}
	void getThresholdLengthMapOffset()const
	{
		fprintf(mFile,"\"%s.tlmo\"",mName.c_str());
	}
	void getThresholdLengthMapMult()const
	{
		fprintf(mFile,"\"%s.tlmm\"",mName.c_str());
	}
	void getThresholdLengthNoise()const
	{
		fprintf(mFile,"\"%s.tln\"",mName.c_str());
	}
protected:
	FurAttractors(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURATTRACTORS_H__
