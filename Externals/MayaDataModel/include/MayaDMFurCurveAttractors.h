/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	FurCurveAttractors():DependNode(){}
	FurCurveAttractors(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "FurCurveAttractors", shared, create){}
	virtual ~FurCurveAttractors(){}

	void setCurveAttractorModel(unsigned int camd)
	{
		if(camd == 0) return;
		fprintf(mFile,"\tsetAttr \".camd\" %i;\n", camd);
	}
	void setCurveAttractorsPerHair(int caph)
	{
		if(caph == 1) return;
		fprintf(mFile,"\tsetAttr \".caph\" %i;\n", caph);
	}
	void setCurveGlobalScale(float cgs)
	{
		if(cgs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cgs\" %f;\n", cgs);
	}
	void setCurveRadius(double dcr)
	{
		if(dcr == 1) return;
		fprintf(mFile,"\tsetAttr \".dcr\" %f;\n", dcr);
	}
	void setCurveRadiusMapOffset(double crmo)
	{
		if(crmo == 0) return;
		fprintf(mFile,"\tsetAttr \".crmo\" %f;\n", crmo);
	}
	void setCurveRadiusMapMult(double crmm)
	{
		if(crmm == 1) return;
		fprintf(mFile,"\tsetAttr \".crmm\" %f;\n", crmm);
	}
	void setCurveRadiusNoise(double crn)
	{
		if(crn == 0) return;
		fprintf(mFile,"\tsetAttr \".crn\" %f;\n", crn);
	}
	void setCurveRadiusNoiseFreq(float crnf)
	{
		if(crnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".crnf\" %f;\n", crnf);
	}
	void setCurvePower(float dcp)
	{
		if(dcp == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dcp\" %f;\n", dcp);
	}
	void setCurvePowerMapOffset(float cpmo)
	{
		if(cpmo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cpmo\" %f;\n", cpmo);
	}
	void setCurvePowerMapMult(float cpmm)
	{
		if(cpmm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cpmm\" %f;\n", cpmm);
	}
	void setCurvePowerNoise(float cpn)
	{
		if(cpn == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cpn\" %f;\n", cpn);
	}
	void setCurvePowerNoiseFreq(float cpnf)
	{
		if(cpnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".cpnf\" %f;\n", cpnf);
	}
	void setCurveInfluence(float dci)
	{
		if(dci == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dci\" %f;\n", dci);
	}
	void setCurveInfluenceMapOffset(float cimo)
	{
		if(cimo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cimo\" %f;\n", cimo);
	}
	void setCurveInfluenceMapMult(float cimm)
	{
		if(cimm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cimm\" %f;\n", cimm);
	}
	void setCurveInfluenceNoise(float cin)
	{
		if(cin == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cin\" %f;\n", cin);
	}
	void setCurveInfluenceNoiseFreq(float cinf)
	{
		if(cinf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".cinf\" %f;\n", cinf);
	}
	void setCurveStartLength(float dcsl)
	{
		if(dcsl == 0.0) return;
		fprintf(mFile,"\tsetAttr \".dcsl\" %f;\n", dcsl);
	}
	void setCurveStartLengthMapOffset(double cslmo)
	{
		if(cslmo == 0) return;
		fprintf(mFile,"\tsetAttr \".cslmo\" %f;\n", cslmo);
	}
	void setCurveStartLengthMapMult(double cslmm)
	{
		if(cslmm == 1) return;
		fprintf(mFile,"\tsetAttr \".cslmm\" %f;\n", cslmm);
	}
	void setCurveStartLengthNoise(double csln)
	{
		if(csln == 0) return;
		fprintf(mFile,"\tsetAttr \".csln\" %f;\n", csln);
	}
	void setCurveStartLengthNoiseFreq(float cslnf)
	{
		if(cslnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".cslnf\" %f;\n", cslnf);
	}
	void setCurveEndLength(float dcel)
	{
		if(dcel == 5.0) return;
		fprintf(mFile,"\tsetAttr \".dcel\" %f;\n", dcel);
	}
	void setCurveEndLengthMapOffset(double celmo)
	{
		if(celmo == 0) return;
		fprintf(mFile,"\tsetAttr \".celmo\" %f;\n", celmo);
	}
	void setCurveEndLengthMapMult(double celmm)
	{
		if(celmm == 1) return;
		fprintf(mFile,"\tsetAttr \".celmm\" %f;\n", celmm);
	}
	void setCurveEndLengthNoise(double celn)
	{
		if(celn == 0) return;
		fprintf(mFile,"\tsetAttr \".celn\" %f;\n", celn);
	}
	void setCurveEndLengthNoiseFreq(float celnf)
	{
		if(celnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".celnf\" %f;\n", celnf);
	}
	void setCurveThresholdLength(float dctl)
	{
		if(dctl == 0.33) return;
		fprintf(mFile,"\tsetAttr \".dctl\" %f;\n", dctl);
	}
	void setCurveThresholdLengthMapOffset(double ctlmo)
	{
		if(ctlmo == 0) return;
		fprintf(mFile,"\tsetAttr \".ctlmo\" %f;\n", ctlmo);
	}
	void setCurveThresholdLengthMapMult(double ctlmm)
	{
		if(ctlmm == 1) return;
		fprintf(mFile,"\tsetAttr \".ctlmm\" %f;\n", ctlmm);
	}
	void setCurveThresholdLengthNoise(double ctln)
	{
		if(ctln == 0) return;
		fprintf(mFile,"\tsetAttr \".ctln\" %f;\n", ctln);
	}
	void setCurveThresholdLengthNoiseFreq(float ctlnf)
	{
		if(ctlnf == 10.0) return;
		fprintf(mFile,"\tsetAttr \".ctlnf\" %f;\n", ctlnf);
	}
	void getCurveAttractorModel()const
	{
		fprintf(mFile,"\"%s.camd\"",mName.c_str());
	}
	void getDagSetMembers()const
	{
		fprintf(mFile,"\"%s.dsm\"",mName.c_str());
	}
	void getCurveAttractors()const
	{
		fprintf(mFile,"\"%s.catt\"",mName.c_str());
	}
	void getFurGlobals()const
	{
		fprintf(mFile,"\"%s.fgc\"",mName.c_str());
	}
	void getCurveRadius()const
	{
		fprintf(mFile,"\"%s.dcr\"",mName.c_str());
	}
	void getCurveRadiusMap()const
	{
		fprintf(mFile,"\"%s.crm\"",mName.c_str());
	}
	void getCurveRadiusMapUSamples()const
	{
		fprintf(mFile,"\"%s.crmus\"",mName.c_str());
	}
	void getCurveRadiusMapVSamples()const
	{
		fprintf(mFile,"\"%s.crmvs\"",mName.c_str());
	}
	void getCurveRadiusMapOffset()const
	{
		fprintf(mFile,"\"%s.crmo\"",mName.c_str());
	}
	void getCurveRadiusMapMult()const
	{
		fprintf(mFile,"\"%s.crmm\"",mName.c_str());
	}
	void getCurveRadiusNoise()const
	{
		fprintf(mFile,"\"%s.crn\"",mName.c_str());
	}
	void getCurvePower()const
	{
		fprintf(mFile,"\"%s.dcp\"",mName.c_str());
	}
	void getCurvePowerMap()const
	{
		fprintf(mFile,"\"%s.cpm\"",mName.c_str());
	}
	void getCurvePowerMapUSamples()const
	{
		fprintf(mFile,"\"%s.cpmus\"",mName.c_str());
	}
	void getCurvePowerMapVSamples()const
	{
		fprintf(mFile,"\"%s.cpmvs\"",mName.c_str());
	}
	void getCurvePowerMapOffset()const
	{
		fprintf(mFile,"\"%s.cpmo\"",mName.c_str());
	}
	void getCurvePowerMapMult()const
	{
		fprintf(mFile,"\"%s.cpmm\"",mName.c_str());
	}
	void getCurvePowerNoise()const
	{
		fprintf(mFile,"\"%s.cpn\"",mName.c_str());
	}
	void getCurveInfluence()const
	{
		fprintf(mFile,"\"%s.dci\"",mName.c_str());
	}
	void getCurveInfluenceMap()const
	{
		fprintf(mFile,"\"%s.cim\"",mName.c_str());
	}
	void getCurveInfluenceMapUSamples()const
	{
		fprintf(mFile,"\"%s.cimus\"",mName.c_str());
	}
	void getCurveInfluenceMapVSamples()const
	{
		fprintf(mFile,"\"%s.cimvs\"",mName.c_str());
	}
	void getCurveInfluenceMapOffset()const
	{
		fprintf(mFile,"\"%s.cimo\"",mName.c_str());
	}
	void getCurveInfluenceMapMult()const
	{
		fprintf(mFile,"\"%s.cimm\"",mName.c_str());
	}
	void getCurveInfluenceNoise()const
	{
		fprintf(mFile,"\"%s.cin\"",mName.c_str());
	}
	void getCurveStartLength()const
	{
		fprintf(mFile,"\"%s.dcsl\"",mName.c_str());
	}
	void getCurveStartLengthMap()const
	{
		fprintf(mFile,"\"%s.cslm\"",mName.c_str());
	}
	void getCurveStartLengthMapUSamples()const
	{
		fprintf(mFile,"\"%s.cslmus\"",mName.c_str());
	}
	void getCurveStartLengthMapVSamples()const
	{
		fprintf(mFile,"\"%s.cslmvs\"",mName.c_str());
	}
	void getCurveStartLengthMapOffset()const
	{
		fprintf(mFile,"\"%s.cslmo\"",mName.c_str());
	}
	void getCurveStartLengthMapMult()const
	{
		fprintf(mFile,"\"%s.cslmm\"",mName.c_str());
	}
	void getCurveStartLengthNoise()const
	{
		fprintf(mFile,"\"%s.csln\"",mName.c_str());
	}
	void getCurveEndLength()const
	{
		fprintf(mFile,"\"%s.dcel\"",mName.c_str());
	}
	void getCurveEndLengthMap()const
	{
		fprintf(mFile,"\"%s.celm\"",mName.c_str());
	}
	void getCurveEndLengthMapUSamples()const
	{
		fprintf(mFile,"\"%s.celmus\"",mName.c_str());
	}
	void getCurveEndLengthMapVSamples()const
	{
		fprintf(mFile,"\"%s.celmvs\"",mName.c_str());
	}
	void getCurveEndLengthMapOffset()const
	{
		fprintf(mFile,"\"%s.celmo\"",mName.c_str());
	}
	void getCurveEndLengthMapMult()const
	{
		fprintf(mFile,"\"%s.celmm\"",mName.c_str());
	}
	void getCurveEndLengthNoise()const
	{
		fprintf(mFile,"\"%s.celn\"",mName.c_str());
	}
	void getCurveThresholdLength()const
	{
		fprintf(mFile,"\"%s.dctl\"",mName.c_str());
	}
	void getCurveThresholdLengthMap()const
	{
		fprintf(mFile,"\"%s.ctlm\"",mName.c_str());
	}
	void getCurveThresholdLengthMapUSamples()const
	{
		fprintf(mFile,"\"%s.ctlmus\"",mName.c_str());
	}
	void getCurveThresholdLengthMapVSamples()const
	{
		fprintf(mFile,"\"%s.ctlmvs\"",mName.c_str());
	}
	void getCurveThresholdLengthMapOffset()const
	{
		fprintf(mFile,"\"%s.ctlmo\"",mName.c_str());
	}
	void getCurveThresholdLengthMapMult()const
	{
		fprintf(mFile,"\"%s.ctlmm\"",mName.c_str());
	}
	void getCurveThresholdLengthNoise()const
	{
		fprintf(mFile,"\"%s.ctln\"",mName.c_str());
	}
protected:
	FurCurveAttractors(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FURCURVEATTRACTORS_H__
