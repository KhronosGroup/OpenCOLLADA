/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AREALIGHT_H__
#define __MayaDM_AREALIGHT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNonExtendedLightShapeNode.h"
namespace MayaDM
{
class AreaLight : public NonExtendedLightShapeNode
{
public:
	struct MentalRayControls{
		bool miExportMrLight;
		bool emitPhotons;
		float3 energy;
		float photonIntensity;
		float exponent;
		int causticPhotons;
		int causticPhotonsEmit;
		int globIllPhotons;
		int globIllPhotonsEmit;
		bool shadowMap;
		int smapResolution;
		short smapSamples;
		float smapSoftness;
		float smapBias;
		string smapFilename;
		bool smapLightName;
		bool smapSceneName;
		bool smapFrameExt;
		bool smapDetail;
		short smapDetailSamples;
		float smapDetailAccuracy;
		bool smapDetailAlpha;
		struct SmapWindow{
			short smapWindowXMin;
			short smapWindowYMin;
			short smapWindowXMax;
			short smapWindowYMax;
			void write(FILE* file) const
			{
				fprintf(file,"%i ", smapWindowXMin);
				fprintf(file,"%i ", smapWindowYMin);
				fprintf(file,"%i ", smapWindowXMax);
				fprintf(file,"%i", smapWindowYMax);
			}
		} smapWindow;
		bool smapMerge;
		bool smapTrace;
		bool areaLight;
		unsigned int areaType;
		float areaShapeIntensity;
		short areaHiSamples;
		short areaHiSampleLimit;
		short areaLoSamples;
		bool areaVisible;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", miExportMrLight);
			fprintf(file,"%i ", emitPhotons);
			energy.write(file);
			fprintf(file, " ");
			fprintf(file,"%f ", photonIntensity);
			fprintf(file,"%f ", exponent);
			fprintf(file,"%i ", causticPhotons);
			fprintf(file,"%i ", causticPhotonsEmit);
			fprintf(file,"%i ", globIllPhotons);
			fprintf(file,"%i ", globIllPhotonsEmit);
			fprintf(file,"%i ", shadowMap);
			fprintf(file,"%i ", smapResolution);
			fprintf(file,"%i ", smapSamples);
			fprintf(file,"%f ", smapSoftness);
			fprintf(file,"%f ", smapBias);
			smapFilename.write(file);
			fprintf(file, " ");
			fprintf(file,"%i ", smapLightName);
			fprintf(file,"%i ", smapSceneName);
			fprintf(file,"%i ", smapFrameExt);
			fprintf(file,"%i ", smapDetail);
			fprintf(file,"%i ", smapDetailSamples);
			fprintf(file,"%f ", smapDetailAccuracy);
			fprintf(file,"%i ", smapDetailAlpha);
			smapWindow.write(file);
			fprintf(file, " ");
			fprintf(file,"%i ", smapMerge);
			fprintf(file,"%i ", smapTrace);
			fprintf(file,"%i ", areaLight);
			fprintf(file,"%i ", areaType);
			fprintf(file,"%f ", areaShapeIntensity);
			fprintf(file,"%i ", areaHiSamples);
			fprintf(file,"%i ", areaHiSampleLimit);
			fprintf(file,"%i ", areaLoSamples);
			fprintf(file,"%i ", areaVisible);
		}
	};
public:

	AreaLight():NonExtendedLightShapeNode(){}
	AreaLight(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:NonExtendedLightShapeNode(file, name, parent, "areaLight", shared, create){}
	virtual ~AreaLight(){}

	void setPointWorld(const float3& pw)
	{
		if(pw == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".pw\" -type \"float3\" ");
		pw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointWorldX(float tx)
	{
		if(tx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pw.tx\" %f;\n", tx);
	}
	void setPointWorldY(float ty)
	{
		if(ty == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pw.ty\" %f;\n", ty);
	}
	void setPointWorldZ(float tz)
	{
		if(tz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pw.tz\" %f;\n", tz);
	}
	void setObjectType(char ot)
	{
		if(ot == 1) return;
		fprintf(mFile,"\tsetAttr \".ot\" %;\n", ot);
	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"\tsetAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiExportMrLight(bool milt)
	{
		if(milt == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.milt\" %i;\n", milt);
	}
	void setEmitPhotons(bool phot)
	{
		if(phot == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.phot\" %i;\n", phot);
	}
	void setEnergy(const float3& eng)
	{
		fprintf(mFile,"\tsetAttr \".mrc.eng\" -type \"float3\" ");
		eng.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEnergyR(float engr)
	{
		if(engr == 8000) return;
		fprintf(mFile,"\tsetAttr \".mrc.eng.engr\" %f;\n", engr);
	}
	void setEnergyG(float engg)
	{
		if(engg == 8000) return;
		fprintf(mFile,"\tsetAttr \".mrc.eng.engg\" %f;\n", engg);
	}
	void setEnergyB(float engb)
	{
		if(engb == 8000) return;
		fprintf(mFile,"\tsetAttr \".mrc.eng.engb\" %f;\n", engb);
	}
	void setPhotonIntensity(float phi)
	{
		if(phi == 1) return;
		fprintf(mFile,"\tsetAttr \".mrc.phi\" %f;\n", phi);
	}
	void setExponent(float exp)
	{
		if(exp == 2) return;
		fprintf(mFile,"\tsetAttr \".mrc.exp\" %f;\n", exp);
	}
	void setCausticPhotons(int cph)
	{
		if(cph == 10000) return;
		fprintf(mFile,"\tsetAttr \".mrc.cph\" %i;\n", cph);
	}
	void setCausticPhotonsEmit(int cphe)
	{
		if(cphe == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.cphe\" %i;\n", cphe);
	}
	void setGlobIllPhotons(int gph)
	{
		if(gph == 10000) return;
		fprintf(mFile,"\tsetAttr \".mrc.gph\" %i;\n", gph);
	}
	void setGlobIllPhotonsEmit(int gphe)
	{
		if(gphe == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.gphe\" %i;\n", gphe);
	}
	void setShadowMap(bool usm)
	{
		if(usm == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.usm\" %i;\n", usm);
	}
	void setSmapResolution(int smr)
	{
		if(smr == 256) return;
		fprintf(mFile,"\tsetAttr \".mrc.smr\" %i;\n", smr);
	}
	void setSmapSamples(short smsa)
	{
		if(smsa == 1) return;
		fprintf(mFile,"\tsetAttr \".mrc.smsa\" %i;\n", smsa);
	}
	void setSmapSoftness(float smso)
	{
		if(smso == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smso\" %f;\n", smso);
	}
	void setSmapBias(float smb)
	{
		if(smb == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smb\" %f;\n", smb);
	}
	void setSmapFilename(const string& smf)
	{
		if(smf == "NULL") return;
		fprintf(mFile,"\tsetAttr \".mrc.smf\" -type \"string\" ");
		smf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSmapLightName(bool smln)
	{
		if(smln == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smln\" %i;\n", smln);
	}
	void setSmapSceneName(bool smsn)
	{
		if(smsn == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smsn\" %i;\n", smsn);
	}
	void setSmapFrameExt(bool smfe)
	{
		if(smfe == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smfe\" %i;\n", smfe);
	}
	void setSmapDetail(bool smd)
	{
		if(smd == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smd\" %i;\n", smd);
	}
	void setSmapDetailSamples(short sds)
	{
		if(sds == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.sds\" %i;\n", sds);
	}
	void setSmapDetailAccuracy(float sdac)
	{
		if(sdac == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.sdac\" %f;\n", sdac);
	}
	void setSmapDetailAlpha(bool sdal)
	{
		if(sdal == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.sdal\" %i;\n", sdal);
	}
	void setSmapWindow(const MentalRayControls::SmapWindow& smw)
	{
		fprintf(mFile,"\tsetAttr \".mrc.smw\" ");
		smw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSmapWindowXMin(short smxl)
	{
		if(smxl == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smw.smxl\" %i;\n", smxl);
	}
	void setSmapWindowYMin(short smyl)
	{
		if(smyl == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smw.smyl\" %i;\n", smyl);
	}
	void setSmapWindowXMax(short smxh)
	{
		if(smxh == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smw.smxh\" %i;\n", smxh);
	}
	void setSmapWindowYMax(short smyh)
	{
		if(smyh == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smw.smyh\" %i;\n", smyh);
	}
	void setSmapMerge(bool smm)
	{
		if(smm == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smm\" %i;\n", smm);
	}
	void setSmapTrace(bool smt)
	{
		if(smt == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.smt\" %i;\n", smt);
	}
	void setAreaLight(bool algt)
	{
		if(algt == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.algt\" %i;\n", algt);
	}
	void setAreaType(unsigned int atyp)
	{
		if(atyp == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.atyp\" %i;\n", atyp);
	}
	void setAreaShapeIntensity(float alsi)
	{
		if(alsi == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mrc.alsi\" %f;\n", alsi);
	}
	void setAreaHiSamples(short ahs)
	{
		if(ahs == 8) return;
		fprintf(mFile,"\tsetAttr \".mrc.ahs\" %i;\n", ahs);
	}
	void setAreaHiSampleLimit(short alev)
	{
		if(alev == 1) return;
		fprintf(mFile,"\tsetAttr \".mrc.alev\" %i;\n", alev);
	}
	void setAreaLoSamples(short als)
	{
		if(als == 1) return;
		fprintf(mFile,"\tsetAttr \".mrc.als\" %i;\n", als);
	}
	void setAreaVisible(bool avis)
	{
		if(avis == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.avis\" %i;\n", avis);
	}
	void getLightGlow()const
	{
		fprintf(mFile,"\"%s.lg\"",mName.c_str());
	}
	void getPointWorld()const
	{
		fprintf(mFile,"\"%s.pw\"",mName.c_str());
	}
	void getPointWorldX()const
	{
		fprintf(mFile,"\"%s.pw.tx\"",mName.c_str());
	}
	void getPointWorldY()const
	{
		fprintf(mFile,"\"%s.pw.ty\"",mName.c_str());
	}
	void getPointWorldZ()const
	{
		fprintf(mFile,"\"%s.pw.tz\"",mName.c_str());
	}
	void getNormalCamera()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalCameraX()const
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getNormalCameraY()const
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
	}
	void getObjectType()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getMentalRayControls()const
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());
	}
	void getMiExportMrLight()const
	{
		fprintf(mFile,"\"%s.mrc.milt\"",mName.c_str());
	}
	void getMiLightShader()const
	{
		fprintf(mFile,"\"%s.mrc.mils\"",mName.c_str());
	}
	void getMiPhotonEmitter()const
	{
		fprintf(mFile,"\"%s.mrc.mipe\"",mName.c_str());
	}
	void getEmitPhotons()const
	{
		fprintf(mFile,"\"%s.mrc.phot\"",mName.c_str());
	}
	void getEnergy()const
	{
		fprintf(mFile,"\"%s.mrc.eng\"",mName.c_str());
	}
	void getEnergyR()const
	{
		fprintf(mFile,"\"%s.mrc.eng.engr\"",mName.c_str());
	}
	void getEnergyG()const
	{
		fprintf(mFile,"\"%s.mrc.eng.engg\"",mName.c_str());
	}
	void getEnergyB()const
	{
		fprintf(mFile,"\"%s.mrc.eng.engb\"",mName.c_str());
	}
	void getPhotonIntensity()const
	{
		fprintf(mFile,"\"%s.mrc.phi\"",mName.c_str());
	}
	void getExponent()const
	{
		fprintf(mFile,"\"%s.mrc.exp\"",mName.c_str());
	}
	void getCausticPhotons()const
	{
		fprintf(mFile,"\"%s.mrc.cph\"",mName.c_str());
	}
	void getCausticPhotonsEmit()const
	{
		fprintf(mFile,"\"%s.mrc.cphe\"",mName.c_str());
	}
	void getGlobIllPhotons()const
	{
		fprintf(mFile,"\"%s.mrc.gph\"",mName.c_str());
	}
	void getGlobIllPhotonsEmit()const
	{
		fprintf(mFile,"\"%s.mrc.gphe\"",mName.c_str());
	}
	void getShadowMap()const
	{
		fprintf(mFile,"\"%s.mrc.usm\"",mName.c_str());
	}
	void getSmapResolution()const
	{
		fprintf(mFile,"\"%s.mrc.smr\"",mName.c_str());
	}
	void getSmapSamples()const
	{
		fprintf(mFile,"\"%s.mrc.smsa\"",mName.c_str());
	}
	void getSmapSoftness()const
	{
		fprintf(mFile,"\"%s.mrc.smso\"",mName.c_str());
	}
	void getSmapBias()const
	{
		fprintf(mFile,"\"%s.mrc.smb\"",mName.c_str());
	}
	void getSmapCamera()const
	{
		fprintf(mFile,"\"%s.mrc.smc\"",mName.c_str());
	}
	void getSmapFilename()const
	{
		fprintf(mFile,"\"%s.mrc.smf\"",mName.c_str());
	}
	void getSmapLightName()const
	{
		fprintf(mFile,"\"%s.mrc.smln\"",mName.c_str());
	}
	void getSmapSceneName()const
	{
		fprintf(mFile,"\"%s.mrc.smsn\"",mName.c_str());
	}
	void getSmapFrameExt()const
	{
		fprintf(mFile,"\"%s.mrc.smfe\"",mName.c_str());
	}
	void getSmapDetail()const
	{
		fprintf(mFile,"\"%s.mrc.smd\"",mName.c_str());
	}
	void getSmapDetailSamples()const
	{
		fprintf(mFile,"\"%s.mrc.sds\"",mName.c_str());
	}
	void getSmapDetailAccuracy()const
	{
		fprintf(mFile,"\"%s.mrc.sdac\"",mName.c_str());
	}
	void getSmapDetailAlpha()const
	{
		fprintf(mFile,"\"%s.mrc.sdal\"",mName.c_str());
	}
	void getSmapWindow()const
	{
		fprintf(mFile,"\"%s.mrc.smw\"",mName.c_str());
	}
	void getSmapWindowXMin()const
	{
		fprintf(mFile,"\"%s.mrc.smw.smxl\"",mName.c_str());
	}
	void getSmapWindowYMin()const
	{
		fprintf(mFile,"\"%s.mrc.smw.smyl\"",mName.c_str());
	}
	void getSmapWindowXMax()const
	{
		fprintf(mFile,"\"%s.mrc.smw.smxh\"",mName.c_str());
	}
	void getSmapWindowYMax()const
	{
		fprintf(mFile,"\"%s.mrc.smw.smyh\"",mName.c_str());
	}
	void getSmapMerge()const
	{
		fprintf(mFile,"\"%s.mrc.smm\"",mName.c_str());
	}
	void getSmapTrace()const
	{
		fprintf(mFile,"\"%s.mrc.smt\"",mName.c_str());
	}
	void getAreaLight()const
	{
		fprintf(mFile,"\"%s.mrc.algt\"",mName.c_str());
	}
	void getAreaType()const
	{
		fprintf(mFile,"\"%s.mrc.atyp\"",mName.c_str());
	}
	void getAreaShapeIntensity()const
	{
		fprintf(mFile,"\"%s.mrc.alsi\"",mName.c_str());
	}
	void getAreaHiSamples()const
	{
		fprintf(mFile,"\"%s.mrc.ahs\"",mName.c_str());
	}
	void getAreaHiSampleLimit()const
	{
		fprintf(mFile,"\"%s.mrc.alev\"",mName.c_str());
	}
	void getAreaLoSamples()const
	{
		fprintf(mFile,"\"%s.mrc.als\"",mName.c_str());
	}
	void getAreaVisible()const
	{
		fprintf(mFile,"\"%s.mrc.avis\"",mName.c_str());
	}
	void getAreaObject()const
	{
		fprintf(mFile,"\"%s.mrc.aobj\"",mName.c_str());
	}
protected:
	AreaLight(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:NonExtendedLightShapeNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_AREALIGHT_H__
