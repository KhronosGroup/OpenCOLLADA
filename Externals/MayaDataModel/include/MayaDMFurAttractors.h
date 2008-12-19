/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	FurAttractors(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "FurAttractors"){}
	virtual ~FurAttractors(){}
	void setAttractorModel(unsigned int amd)
	{
		if(amd == 0) return;
		fprintf(mFile,"setAttr \".amd\" %i;\n", amd);

	}
	void setAttractorsPerHair(int aph)
	{
		if(aph == 1) return;
		fprintf(mFile,"setAttr \".aph\" %i;\n", aph);

	}
	void setGlobalScale(float gs)
	{
		if(gs == 1.0) return;
		fprintf(mFile,"setAttr \".gs\" %f;\n", gs);

	}
	void setRadius(double rd)
	{
		if(rd == 1) return;
		fprintf(mFile,"setAttr \".rd\" %f;\n", rd);

	}
	void setRadiusMapOffset(double rmo)
	{
		if(rmo == 0) return;
		fprintf(mFile,"setAttr \".rmo\" %f;\n", rmo);

	}
	void setRadiusMapMult(double rmm)
	{
		if(rmm == 1) return;
		fprintf(mFile,"setAttr \".rmm\" %f;\n", rmm);

	}
	void setRadiusNoise(double rn)
	{
		if(rn == 0) return;
		fprintf(mFile,"setAttr \".rn\" %f;\n", rn);

	}
	void setRadiusNoiseFreq(float rnf)
	{
		if(rnf == 10.0) return;
		fprintf(mFile,"setAttr \".rnf\" %f;\n", rnf);

	}
	void setPower(float dp)
	{
		if(dp == 1.0) return;
		fprintf(mFile,"setAttr \".dp\" %f;\n", dp);

	}
	void setPowerMapOffset(float pmo)
	{
		if(pmo == 0.0) return;
		fprintf(mFile,"setAttr \".pmo\" %f;\n", pmo);

	}
	void setPowerMapMult(float pmm)
	{
		if(pmm == 1.0) return;
		fprintf(mFile,"setAttr \".pmm\" %f;\n", pmm);

	}
	void setPowerNoise(float pn)
	{
		if(pn == 0.0) return;
		fprintf(mFile,"setAttr \".pn\" %f;\n", pn);

	}
	void setPowerNoiseFreq(float pnf)
	{
		if(pnf == 10.0) return;
		fprintf(mFile,"setAttr \".pnf\" %f;\n", pnf);

	}
	void setInfluence(float di)
	{
		if(di == 1.0) return;
		fprintf(mFile,"setAttr \".di\" %f;\n", di);

	}
	void setInfluenceMapOffset(float imo)
	{
		if(imo == 0.0) return;
		fprintf(mFile,"setAttr \".imo\" %f;\n", imo);

	}
	void setInfluenceMapMult(float imm)
	{
		if(imm == 1.0) return;
		fprintf(mFile,"setAttr \".imm\" %f;\n", imm);

	}
	void setInfluenceNoise(float in)
	{
		if(in == 0.0) return;
		fprintf(mFile,"setAttr \".in\" %f;\n", in);

	}
	void setInfluenceNoiseFreq(float inf)
	{
		if(inf == 10.0) return;
		fprintf(mFile,"setAttr \".inf\" %f;\n", inf);

	}
	void setStartLength(float dsl)
	{
		if(dsl == 0.0) return;
		fprintf(mFile,"setAttr \".dsl\" %f;\n", dsl);

	}
	void setStartLengthMapOffset(double slmo)
	{
		if(slmo == 0) return;
		fprintf(mFile,"setAttr \".slmo\" %f;\n", slmo);

	}
	void setStartLengthMapMult(double slmm)
	{
		if(slmm == 1) return;
		fprintf(mFile,"setAttr \".slmm\" %f;\n", slmm);

	}
	void setStartLengthNoise(double sln)
	{
		if(sln == 0) return;
		fprintf(mFile,"setAttr \".sln\" %f;\n", sln);

	}
	void setStartLengthNoiseFreq(float slnf)
	{
		if(slnf == 10.0) return;
		fprintf(mFile,"setAttr \".slnf\" %f;\n", slnf);

	}
	void setEndLength(float del)
	{
		if(del == 5.0) return;
		fprintf(mFile,"setAttr \".del\" %f;\n", del);

	}
	void setEndLengthMapOffset(double elmo)
	{
		if(elmo == 0) return;
		fprintf(mFile,"setAttr \".elmo\" %f;\n", elmo);

	}
	void setEndLengthMapMult(double elmm)
	{
		if(elmm == 1) return;
		fprintf(mFile,"setAttr \".elmm\" %f;\n", elmm);

	}
	void setEndLengthNoise(double eln)
	{
		if(eln == 0) return;
		fprintf(mFile,"setAttr \".eln\" %f;\n", eln);

	}
	void setEndLengthNoiseFreq(float elnf)
	{
		if(elnf == 10.0) return;
		fprintf(mFile,"setAttr \".elnf\" %f;\n", elnf);

	}
	void setThresholdLength(float dtl)
	{
		if(dtl == 0.33) return;
		fprintf(mFile,"setAttr \".dtl\" %f;\n", dtl);

	}
	void setThresholdLengthMapOffset(double tlmo)
	{
		if(tlmo == 0) return;
		fprintf(mFile,"setAttr \".tlmo\" %f;\n", tlmo);

	}
	void setThresholdLengthMapMult(double tlmm)
	{
		if(tlmm == 1) return;
		fprintf(mFile,"setAttr \".tlmm\" %f;\n", tlmm);

	}
	void setThresholdLengthNoise(double tln)
	{
		if(tln == 0) return;
		fprintf(mFile,"setAttr \".tln\" %f;\n", tln);

	}
	void setThresholdLengthNoiseFreq(float tlnf)
	{
		if(tlnf == 10.0) return;
		fprintf(mFile,"setAttr \".tlnf\" %f;\n", tlnf);

	}
	void getAttractorModel()
	{
		fprintf(mFile,"\"%s.amd\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());

	}
	void getRadiusMapUSamples()
	{
		fprintf(mFile,"\"%s.rmus\"",mName.c_str());

	}
	void getRadiusMapVSamples()
	{
		fprintf(mFile,"\"%s.rmvs\"",mName.c_str());

	}
	void getRadiusMapOffset()
	{
		fprintf(mFile,"\"%s.rmo\"",mName.c_str());

	}
	void getRadiusMapMult()
	{
		fprintf(mFile,"\"%s.rmm\"",mName.c_str());

	}
	void getRadiusNoise()
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());

	}
	void getPower()
	{
		fprintf(mFile,"\"%s.dp\"",mName.c_str());

	}
	void getPowerMapUSamples()
	{
		fprintf(mFile,"\"%s.pmus\"",mName.c_str());

	}
	void getPowerMapVSamples()
	{
		fprintf(mFile,"\"%s.pmvs\"",mName.c_str());

	}
	void getPowerMapOffset()
	{
		fprintf(mFile,"\"%s.pmo\"",mName.c_str());

	}
	void getPowerMapMult()
	{
		fprintf(mFile,"\"%s.pmm\"",mName.c_str());

	}
	void getPowerNoise()
	{
		fprintf(mFile,"\"%s.pn\"",mName.c_str());

	}
	void getInfluence()
	{
		fprintf(mFile,"\"%s.di\"",mName.c_str());

	}
	void getInfluenceMapUSamples()
	{
		fprintf(mFile,"\"%s.imus\"",mName.c_str());

	}
	void getInfluenceMapVSamples()
	{
		fprintf(mFile,"\"%s.imvs\"",mName.c_str());

	}
	void getInfluenceMapOffset()
	{
		fprintf(mFile,"\"%s.imo\"",mName.c_str());

	}
	void getInfluenceMapMult()
	{
		fprintf(mFile,"\"%s.imm\"",mName.c_str());

	}
	void getInfluenceNoise()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getStartLength()
	{
		fprintf(mFile,"\"%s.dsl\"",mName.c_str());

	}
	void getStartLengthMapUSamples()
	{
		fprintf(mFile,"\"%s.slmus\"",mName.c_str());

	}
	void getStartLengthMapVSamples()
	{
		fprintf(mFile,"\"%s.slmvs\"",mName.c_str());

	}
	void getStartLengthMapOffset()
	{
		fprintf(mFile,"\"%s.slmo\"",mName.c_str());

	}
	void getStartLengthMapMult()
	{
		fprintf(mFile,"\"%s.slmm\"",mName.c_str());

	}
	void getStartLengthNoise()
	{
		fprintf(mFile,"\"%s.sln\"",mName.c_str());

	}
	void getEndLength()
	{
		fprintf(mFile,"\"%s.del\"",mName.c_str());

	}
	void getEndLengthMapUSamples()
	{
		fprintf(mFile,"\"%s.elmus\"",mName.c_str());

	}
	void getEndLengthMapVSamples()
	{
		fprintf(mFile,"\"%s.elmvs\"",mName.c_str());

	}
	void getEndLengthMapOffset()
	{
		fprintf(mFile,"\"%s.elmo\"",mName.c_str());

	}
	void getEndLengthMapMult()
	{
		fprintf(mFile,"\"%s.elmm\"",mName.c_str());

	}
	void getEndLengthNoise()
	{
		fprintf(mFile,"\"%s.eln\"",mName.c_str());

	}
	void getThresholdLength()
	{
		fprintf(mFile,"\"%s.dtl\"",mName.c_str());

	}
	void getThresholdLengthMapUSamples()
	{
		fprintf(mFile,"\"%s.tlmus\"",mName.c_str());

	}
	void getThresholdLengthMapVSamples()
	{
		fprintf(mFile,"\"%s.tlmvs\"",mName.c_str());

	}
	void getThresholdLengthMapOffset()
	{
		fprintf(mFile,"\"%s.tlmo\"",mName.c_str());

	}
	void getThresholdLengthMapMult()
	{
		fprintf(mFile,"\"%s.tlmm\"",mName.c_str());

	}
	void getThresholdLengthNoise()
	{
		fprintf(mFile,"\"%s.tln\"",mName.c_str());

	}
protected:
	FurAttractors(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURATTRACTORS_H__
