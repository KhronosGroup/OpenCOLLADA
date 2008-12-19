/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURCURVEATTRACTORS_H__
#define __MayaDM_FURCURVEATTRACTORS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class FurCurveAttractors : public DependNode
{
public:
	struct CurveRadiusMap{
	};
	struct CurveRadiusMapUSamples{
	};
	struct CurveRadiusMapVSamples{
	};
	struct CurvePowerMap{
	};
	struct CurvePowerMapUSamples{
	};
	struct CurvePowerMapVSamples{
	};
	struct CurveInfluenceMap{
	};
	struct CurveInfluenceMapUSamples{
	};
	struct CurveInfluenceMapVSamples{
	};
	struct CurveStartLengthMap{
	};
	struct CurveStartLengthMapUSamples{
	};
	struct CurveStartLengthMapVSamples{
	};
	struct CurveEndLengthMap{
	};
	struct CurveEndLengthMapUSamples{
	};
	struct CurveEndLengthMapVSamples{
	};
	struct CurveThresholdLengthMap{
	};
	struct CurveThresholdLengthMapUSamples{
	};
	struct CurveThresholdLengthMapVSamples{
	};
public:
	FurCurveAttractors(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "FurCurveAttractors"){}
	virtual ~FurCurveAttractors(){}
	void setCurveAttractorModel(unsigned int camd)
	{
		if(camd == 0) return;
		fprintf(mFile,"setAttr \".camd\" %i;\n", camd);

	}
	void setCurveAttractorsPerHair(int caph)
	{
		if(caph == 1) return;
		fprintf(mFile,"setAttr \".caph\" %i;\n", caph);

	}
	void setCurveGlobalScale(float cgs)
	{
		if(cgs == 1.0) return;
		fprintf(mFile,"setAttr \".cgs\" %f;\n", cgs);

	}
	void setCurveRadius(double dcr)
	{
		if(dcr == 1) return;
		fprintf(mFile,"setAttr \".dcr\" %f;\n", dcr);

	}
	void setCurveRadiusMapOffset(double crmo)
	{
		if(crmo == 0) return;
		fprintf(mFile,"setAttr \".crmo\" %f;\n", crmo);

	}
	void setCurveRadiusMapMult(double crmm)
	{
		if(crmm == 1) return;
		fprintf(mFile,"setAttr \".crmm\" %f;\n", crmm);

	}
	void setCurveRadiusNoise(double crn)
	{
		if(crn == 0) return;
		fprintf(mFile,"setAttr \".crn\" %f;\n", crn);

	}
	void setCurveRadiusNoiseFreq(float crnf)
	{
		if(crnf == 10.0) return;
		fprintf(mFile,"setAttr \".crnf\" %f;\n", crnf);

	}
	void setCurvePower(float dcp)
	{
		if(dcp == 1.0) return;
		fprintf(mFile,"setAttr \".dcp\" %f;\n", dcp);

	}
	void setCurvePowerMapOffset(float cpmo)
	{
		if(cpmo == 0.0) return;
		fprintf(mFile,"setAttr \".cpmo\" %f;\n", cpmo);

	}
	void setCurvePowerMapMult(float cpmm)
	{
		if(cpmm == 1.0) return;
		fprintf(mFile,"setAttr \".cpmm\" %f;\n", cpmm);

	}
	void setCurvePowerNoise(float cpn)
	{
		if(cpn == 0.0) return;
		fprintf(mFile,"setAttr \".cpn\" %f;\n", cpn);

	}
	void setCurvePowerNoiseFreq(float cpnf)
	{
		if(cpnf == 10.0) return;
		fprintf(mFile,"setAttr \".cpnf\" %f;\n", cpnf);

	}
	void setCurveInfluence(float dci)
	{
		if(dci == 1.0) return;
		fprintf(mFile,"setAttr \".dci\" %f;\n", dci);

	}
	void setCurveInfluenceMapOffset(float cimo)
	{
		if(cimo == 0.0) return;
		fprintf(mFile,"setAttr \".cimo\" %f;\n", cimo);

	}
	void setCurveInfluenceMapMult(float cimm)
	{
		if(cimm == 1.0) return;
		fprintf(mFile,"setAttr \".cimm\" %f;\n", cimm);

	}
	void setCurveInfluenceNoise(float cin)
	{
		if(cin == 0.0) return;
		fprintf(mFile,"setAttr \".cin\" %f;\n", cin);

	}
	void setCurveInfluenceNoiseFreq(float cinf)
	{
		if(cinf == 10.0) return;
		fprintf(mFile,"setAttr \".cinf\" %f;\n", cinf);

	}
	void setCurveStartLength(float dcsl)
	{
		if(dcsl == 0.0) return;
		fprintf(mFile,"setAttr \".dcsl\" %f;\n", dcsl);

	}
	void setCurveStartLengthMapOffset(double cslmo)
	{
		if(cslmo == 0) return;
		fprintf(mFile,"setAttr \".cslmo\" %f;\n", cslmo);

	}
	void setCurveStartLengthMapMult(double cslmm)
	{
		if(cslmm == 1) return;
		fprintf(mFile,"setAttr \".cslmm\" %f;\n", cslmm);

	}
	void setCurveStartLengthNoise(double csln)
	{
		if(csln == 0) return;
		fprintf(mFile,"setAttr \".csln\" %f;\n", csln);

	}
	void setCurveStartLengthNoiseFreq(float cslnf)
	{
		if(cslnf == 10.0) return;
		fprintf(mFile,"setAttr \".cslnf\" %f;\n", cslnf);

	}
	void setCurveEndLength(float dcel)
	{
		if(dcel == 5.0) return;
		fprintf(mFile,"setAttr \".dcel\" %f;\n", dcel);

	}
	void setCurveEndLengthMapOffset(double celmo)
	{
		if(celmo == 0) return;
		fprintf(mFile,"setAttr \".celmo\" %f;\n", celmo);

	}
	void setCurveEndLengthMapMult(double celmm)
	{
		if(celmm == 1) return;
		fprintf(mFile,"setAttr \".celmm\" %f;\n", celmm);

	}
	void setCurveEndLengthNoise(double celn)
	{
		if(celn == 0) return;
		fprintf(mFile,"setAttr \".celn\" %f;\n", celn);

	}
	void setCurveEndLengthNoiseFreq(float celnf)
	{
		if(celnf == 10.0) return;
		fprintf(mFile,"setAttr \".celnf\" %f;\n", celnf);

	}
	void setCurveThresholdLength(float dctl)
	{
		if(dctl == 0.33) return;
		fprintf(mFile,"setAttr \".dctl\" %f;\n", dctl);

	}
	void setCurveThresholdLengthMapOffset(double ctlmo)
	{
		if(ctlmo == 0) return;
		fprintf(mFile,"setAttr \".ctlmo\" %f;\n", ctlmo);

	}
	void setCurveThresholdLengthMapMult(double ctlmm)
	{
		if(ctlmm == 1) return;
		fprintf(mFile,"setAttr \".ctlmm\" %f;\n", ctlmm);

	}
	void setCurveThresholdLengthNoise(double ctln)
	{
		if(ctln == 0) return;
		fprintf(mFile,"setAttr \".ctln\" %f;\n", ctln);

	}
	void setCurveThresholdLengthNoiseFreq(float ctlnf)
	{
		if(ctlnf == 10.0) return;
		fprintf(mFile,"setAttr \".ctlnf\" %f;\n", ctlnf);

	}
	void getCurveAttractorModel()
	{
		fprintf(mFile,"\"%s.camd\"",mName.c_str());

	}
	void getCurveRadius()
	{
		fprintf(mFile,"\"%s.dcr\"",mName.c_str());

	}
	void getCurveRadiusMapUSamples()
	{
		fprintf(mFile,"\"%s.crmus\"",mName.c_str());

	}
	void getCurveRadiusMapVSamples()
	{
		fprintf(mFile,"\"%s.crmvs\"",mName.c_str());

	}
	void getCurveRadiusMapOffset()
	{
		fprintf(mFile,"\"%s.crmo\"",mName.c_str());

	}
	void getCurveRadiusMapMult()
	{
		fprintf(mFile,"\"%s.crmm\"",mName.c_str());

	}
	void getCurveRadiusNoise()
	{
		fprintf(mFile,"\"%s.crn\"",mName.c_str());

	}
	void getCurvePower()
	{
		fprintf(mFile,"\"%s.dcp\"",mName.c_str());

	}
	void getCurvePowerMapUSamples()
	{
		fprintf(mFile,"\"%s.cpmus\"",mName.c_str());

	}
	void getCurvePowerMapVSamples()
	{
		fprintf(mFile,"\"%s.cpmvs\"",mName.c_str());

	}
	void getCurvePowerMapOffset()
	{
		fprintf(mFile,"\"%s.cpmo\"",mName.c_str());

	}
	void getCurvePowerMapMult()
	{
		fprintf(mFile,"\"%s.cpmm\"",mName.c_str());

	}
	void getCurvePowerNoise()
	{
		fprintf(mFile,"\"%s.cpn\"",mName.c_str());

	}
	void getCurveInfluence()
	{
		fprintf(mFile,"\"%s.dci\"",mName.c_str());

	}
	void getCurveInfluenceMapUSamples()
	{
		fprintf(mFile,"\"%s.cimus\"",mName.c_str());

	}
	void getCurveInfluenceMapVSamples()
	{
		fprintf(mFile,"\"%s.cimvs\"",mName.c_str());

	}
	void getCurveInfluenceMapOffset()
	{
		fprintf(mFile,"\"%s.cimo\"",mName.c_str());

	}
	void getCurveInfluenceMapMult()
	{
		fprintf(mFile,"\"%s.cimm\"",mName.c_str());

	}
	void getCurveInfluenceNoise()
	{
		fprintf(mFile,"\"%s.cin\"",mName.c_str());

	}
	void getCurveStartLength()
	{
		fprintf(mFile,"\"%s.dcsl\"",mName.c_str());

	}
	void getCurveStartLengthMapUSamples()
	{
		fprintf(mFile,"\"%s.cslmus\"",mName.c_str());

	}
	void getCurveStartLengthMapVSamples()
	{
		fprintf(mFile,"\"%s.cslmvs\"",mName.c_str());

	}
	void getCurveStartLengthMapOffset()
	{
		fprintf(mFile,"\"%s.cslmo\"",mName.c_str());

	}
	void getCurveStartLengthMapMult()
	{
		fprintf(mFile,"\"%s.cslmm\"",mName.c_str());

	}
	void getCurveStartLengthNoise()
	{
		fprintf(mFile,"\"%s.csln\"",mName.c_str());

	}
	void getCurveEndLength()
	{
		fprintf(mFile,"\"%s.dcel\"",mName.c_str());

	}
	void getCurveEndLengthMapUSamples()
	{
		fprintf(mFile,"\"%s.celmus\"",mName.c_str());

	}
	void getCurveEndLengthMapVSamples()
	{
		fprintf(mFile,"\"%s.celmvs\"",mName.c_str());

	}
	void getCurveEndLengthMapOffset()
	{
		fprintf(mFile,"\"%s.celmo\"",mName.c_str());

	}
	void getCurveEndLengthMapMult()
	{
		fprintf(mFile,"\"%s.celmm\"",mName.c_str());

	}
	void getCurveEndLengthNoise()
	{
		fprintf(mFile,"\"%s.celn\"",mName.c_str());

	}
	void getCurveThresholdLength()
	{
		fprintf(mFile,"\"%s.dctl\"",mName.c_str());

	}
	void getCurveThresholdLengthMapUSamples()
	{
		fprintf(mFile,"\"%s.ctlmus\"",mName.c_str());

	}
	void getCurveThresholdLengthMapVSamples()
	{
		fprintf(mFile,"\"%s.ctlmvs\"",mName.c_str());

	}
	void getCurveThresholdLengthMapOffset()
	{
		fprintf(mFile,"\"%s.ctlmo\"",mName.c_str());

	}
	void getCurveThresholdLengthMapMult()
	{
		fprintf(mFile,"\"%s.ctlmm\"",mName.c_str());

	}
	void getCurveThresholdLengthNoise()
	{
		fprintf(mFile,"\"%s.ctln\"",mName.c_str());

	}
protected:
	FurCurveAttractors(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURCURVEATTRACTORS_H__
