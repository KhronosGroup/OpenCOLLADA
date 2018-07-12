/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_USEBACKGROUND_H__
#define __MayaDM_USEBACKGROUND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class UseBackground : public DependNode
{
public:
public:

	UseBackground():DependNode(){}
	UseBackground(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "useBackground", shared, create){}
	virtual ~UseBackground(){}

	void setShadowMask(float sm)
	{
		if(sm == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sm\" %f;\n", sm);
	}
	void setReflectionLimit(short fll)
	{
		if(fll == 2) return;
		fprintf(mFile,"\tsetAttr \".fll\" %i;\n", fll);
	}
	void setSpecularColor(const float3& sc)
	{
		fprintf(mFile,"\tsetAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularColorR(float sr)
	{
		if(sr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.sr\" %f;\n", sr);
	}
	void setSpecularColorG(float sg)
	{
		if(sg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.sg\" %f;\n", sg);
	}
	void setSpecularColorB(float sb)
	{
		if(sb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.sb\" %f;\n", sb);
	}
	void setReflectivity(float rfl)
	{
		if(rfl == 0.5) return;
		fprintf(mFile,"\tsetAttr \".rfl\" %f;\n", rfl);
	}
	void setMatteOpacityMode(unsigned int mom)
	{
		if(mom == 2) return;
		fprintf(mFile,"\tsetAttr \".mom\" %i;\n", mom);
	}
	void setMatteOpacity(float mog)
	{
		if(mog == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mog\" %f;\n", mog);
	}
	void setMiReflectionBlur(float mircb)
	{
		if(mircb == 0) return;
		fprintf(mFile,"\tsetAttr \".mircb\" %f;\n", mircb);
	}
	void setMiReflectionRays(short mircr)
	{
		if(mircr == 1) return;
		fprintf(mFile,"\tsetAttr \".mircr\" %i;\n", mircr);
	}
	void setMiDeriveFromMaya(bool mifm)
	{
		if(mifm == true) return;
		fprintf(mFile,"\tsetAttr \".mifm\" %i;\n", mifm);
	}
	void setMiShinyness(float mis)
	{
		if(mis == 10) return;
		fprintf(mFile,"\tsetAttr \".mis\" %f;\n", mis);
	}
	void setMiAngle(float mia)
	{
		if(mia == 0) return;
		fprintf(mFile,"\tsetAttr \".mia\" %f;\n", mia);
	}
	void setMiSpreadX(float misx)
	{
		if(misx == 10) return;
		fprintf(mFile,"\tsetAttr \".misx\" %f;\n", misx);
	}
	void setMiSpreadY(float misy)
	{
		if(misy == 5) return;
		fprintf(mFile,"\tsetAttr \".misy\" %f;\n", misy);
	}
	void setMiWhiteness(const float3& miwn)
	{
		fprintf(mFile,"\tsetAttr \".miwn\" -type \"float3\" ");
		miwn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiWhitenessR(float miwnr)
	{
		if(miwnr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwnr\" %f;\n", miwnr);
	}
	void setMiWhitenessG(float miwng)
	{
		if(miwng == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwng\" %f;\n", miwng);
	}
	void setMiWhitenessB(float miwnb)
	{
		if(miwnb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".miwn.miwnb\" %f;\n", miwnb);
	}
	void setMiSpecularColor(const float3& misc)
	{
		fprintf(mFile,"\tsetAttr \".misc\" -type \"float3\" ");
		misc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiSpecularColorR(float miscr)
	{
		if(miscr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscr\" %f;\n", miscr);
	}
	void setMiSpecularColorG(float miscg)
	{
		if(miscg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscg\" %f;\n", miscg);
	}
	void setMiSpecularColorB(float miscb)
	{
		if(miscb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".misc.miscb\" %f;\n", miscb);
	}
	void setMiReflectivity(float mirf)
	{
		if(mirf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mirf\" %f;\n", mirf);
	}
	void setMiRefractiveIndex(float miri)
	{
		if(miri == 1) return;
		fprintf(mFile,"\tsetAttr \".miri\" %f;\n", miri);
	}
	void setMiRefractions(bool mirc)
	{
		if(mirc == true) return;
		fprintf(mFile,"\tsetAttr \".mirc\" %i;\n", mirc);
	}
	void setMiAbsorbs(bool miab)
	{
		if(miab == true) return;
		fprintf(mFile,"\tsetAttr \".miab\" %i;\n", miab);
	}
	void setMiDiffuse(float midc)
	{
		if(midc == 0.8) return;
		fprintf(mFile,"\tsetAttr \".midc\" %f;\n", midc);
	}
	void setMiColor(const float3& mic)
	{
		fprintf(mFile,"\tsetAttr \".mic\" -type \"float3\" ");
		mic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiColorR(float micr)
	{
		if(micr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micr\" %f;\n", micr);
	}
	void setMiColorG(float micg)
	{
		if(micg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micg\" %f;\n", micg);
	}
	void setMiColorB(float micb)
	{
		if(micb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mic.micb\" %f;\n", micb);
	}
	void setMiTransparency(const float3& mit)
	{
		fprintf(mFile,"\tsetAttr \".mit\" -type \"float3\" ");
		mit.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiTransparencyR(float mitr)
	{
		if(mitr == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitr\" %f;\n", mitr);
	}
	void setMiTransparencyG(float mitg)
	{
		if(mitg == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitg\" %f;\n", mitg);
	}
	void setMiTransparencyB(float mitb)
	{
		if(mitb == 0) return;
		fprintf(mFile,"\tsetAttr \".mit.mitb\" %f;\n", mitb);
	}
	void setMiTranslucence(float mitc)
	{
		if(mitc == 0) return;
		fprintf(mFile,"\tsetAttr \".mitc\" %f;\n", mitc);
	}
	void setMiTranslucenceFocus(float mitf)
	{
		if(mitf == 0.5) return;
		fprintf(mFile,"\tsetAttr \".mitf\" %f;\n", mitf);
	}
	void setMiNormalCamera(const float3& minc)
	{
		fprintf(mFile,"\tsetAttr \".minc\" -type \"float3\" ");
		minc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiNormalCameraX(float mincx)
	{
		if(mincx == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincx\" %f;\n", mincx);
	}
	void setMiNormalCameraY(float mincy)
	{
		if(mincy == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincy\" %f;\n", mincy);
	}
	void setMiNormalCameraZ(float mincz)
	{
		if(mincz == 0) return;
		fprintf(mFile,"\tsetAttr \".minc.mincz\" %f;\n", mincz);
	}
	void setMiOcclusionMask(float mio)
	{
		if(mio == 1) return;
		fprintf(mFile,"\tsetAttr \".mio\" %f;\n", mio);
	}
	void getObjectId()const
	{
		fprintf(mFile,"\"%s.oi\"",mName.c_str());
	}
	void getPrimitiveId()const
	{
		fprintf(mFile,"\"%s.pi\"",mName.c_str());
	}
	void getRaySampler()const
	{
		fprintf(mFile,"\"%s.rtr\"",mName.c_str());
	}
	void getBackgroundSampler()const
	{
		fprintf(mFile,"\"%s.rtb\"",mName.c_str());
	}
	void getRayDepth()const
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());
	}
	void getRayInstance()const
	{
		fprintf(mFile,"\"%s.ryi\"",mName.c_str());
	}
	void getRayDirection()const
	{
		fprintf(mFile,"\"%s.rad\"",mName.c_str());
	}
	void getRayDirectionX()const
	{
		fprintf(mFile,"\"%s.rad.rdx\"",mName.c_str());
	}
	void getRayDirectionY()const
	{
		fprintf(mFile,"\"%s.rad.rdy\"",mName.c_str());
	}
	void getRayDirectionZ()const
	{
		fprintf(mFile,"\"%s.rad.rdz\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());
	}
	void getOutTransparency()const
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());
	}
	void getOutTransparencyR()const
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());
	}
	void getOutTransparencyG()const
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());
	}
	void getOutTransparencyB()const
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());
	}
	void getPointCamera()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getPointCameraX()const
	{
		fprintf(mFile,"\"%s.pc.px\"",mName.c_str());
	}
	void getPointCameraY()const
	{
		fprintf(mFile,"\"%s.pc.py\"",mName.c_str());
	}
	void getPointCameraZ()const
	{
		fprintf(mFile,"\"%s.pc.pz\"",mName.c_str());
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
	void getLightDataArray(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i]\"",mName.c_str(),ltd_i);
	}
	void getLightDataArray()const
	{

		fprintf(mFile,"\"%s.ltd\"",mName.c_str());
	}
	void getLightDirection(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld\"",mName.c_str(),ltd_i);
	}
	void getLightDirection()const
	{

		fprintf(mFile,"\"%s.ltd.ld\"",mName.c_str());
	}
	void getLightDirectionX(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldx\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionX()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldx\"",mName.c_str());
	}
	void getLightDirectionY(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldy\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionY()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldy\"",mName.c_str());
	}
	void getLightDirectionZ(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldz\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionZ()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldz\"",mName.c_str());
	}
	void getLightIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li\"",mName.c_str(),ltd_i);
	}
	void getLightIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.li\"",mName.c_str());
	}
	void getLightIntensityR(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lir\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityR()const
	{

		fprintf(mFile,"\"%s.ltd.li.lir\"",mName.c_str());
	}
	void getLightIntensityG(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lig\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityG()const
	{

		fprintf(mFile,"\"%s.ltd.li.lig\"",mName.c_str());
	}
	void getLightIntensityB(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lib\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityB()const
	{

		fprintf(mFile,"\"%s.ltd.li.lib\"",mName.c_str());
	}
	void getLightAmbient(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].la\"",mName.c_str(),ltd_i);
	}
	void getLightAmbient()const
	{

		fprintf(mFile,"\"%s.ltd.la\"",mName.c_str());
	}
	void getLightDiffuse(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ldf\"",mName.c_str(),ltd_i);
	}
	void getLightDiffuse()const
	{

		fprintf(mFile,"\"%s.ltd.ldf\"",mName.c_str());
	}
	void getLightSpecular(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ls\"",mName.c_str(),ltd_i);
	}
	void getLightSpecular()const
	{

		fprintf(mFile,"\"%s.ltd.ls\"",mName.c_str());
	}
	void getLightShadowFraction(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lsf\"",mName.c_str(),ltd_i);
	}
	void getLightShadowFraction()const
	{

		fprintf(mFile,"\"%s.ltd.lsf\"",mName.c_str());
	}
	void getPreShadowIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].psi\"",mName.c_str(),ltd_i);
	}
	void getPreShadowIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.psi\"",mName.c_str());
	}
	void getLightBlindData(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lbd\"",mName.c_str(),ltd_i);
	}
	void getLightBlindData()const
	{

		fprintf(mFile,"\"%s.ltd.lbd\"",mName.c_str());
	}
	void getShadowMask()const
	{
		fprintf(mFile,"\"%s.sm\"",mName.c_str());
	}
	void getReflectionLimit()const
	{
		fprintf(mFile,"\"%s.fll\"",mName.c_str());
	}
	void getSpecularColor()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getSpecularColorR()const
	{
		fprintf(mFile,"\"%s.sc.sr\"",mName.c_str());
	}
	void getSpecularColorG()const
	{
		fprintf(mFile,"\"%s.sc.sg\"",mName.c_str());
	}
	void getSpecularColorB()const
	{
		fprintf(mFile,"\"%s.sc.sb\"",mName.c_str());
	}
	void getReflectivity()const
	{
		fprintf(mFile,"\"%s.rfl\"",mName.c_str());
	}
	void getMatteOpacityMode()const
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());
	}
	void getMatteOpacity()const
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());
	}
	void getOutMatteOpacity()const
	{
		fprintf(mFile,"\"%s.omo\"",mName.c_str());
	}
	void getOutMatteOpacityR()const
	{
		fprintf(mFile,"\"%s.omo.omor\"",mName.c_str());
	}
	void getOutMatteOpacityG()const
	{
		fprintf(mFile,"\"%s.omo.omog\"",mName.c_str());
	}
	void getOutMatteOpacityB()const
	{
		fprintf(mFile,"\"%s.omo.omob\"",mName.c_str());
	}
	void getMiReflectionBlur()const
	{
		fprintf(mFile,"\"%s.mircb\"",mName.c_str());
	}
	void getMiReflectionRays()const
	{
		fprintf(mFile,"\"%s.mircr\"",mName.c_str());
	}
	void getMiDeriveFromMaya()const
	{
		fprintf(mFile,"\"%s.mifm\"",mName.c_str());
	}
	void getMiShinyness()const
	{
		fprintf(mFile,"\"%s.mis\"",mName.c_str());
	}
	void getMiAngle()const
	{
		fprintf(mFile,"\"%s.mia\"",mName.c_str());
	}
	void getMiSpreadX()const
	{
		fprintf(mFile,"\"%s.misx\"",mName.c_str());
	}
	void getMiSpreadY()const
	{
		fprintf(mFile,"\"%s.misy\"",mName.c_str());
	}
	void getMiWhiteness()const
	{
		fprintf(mFile,"\"%s.miwn\"",mName.c_str());
	}
	void getMiWhitenessR()const
	{
		fprintf(mFile,"\"%s.miwn.miwnr\"",mName.c_str());
	}
	void getMiWhitenessG()const
	{
		fprintf(mFile,"\"%s.miwn.miwng\"",mName.c_str());
	}
	void getMiWhitenessB()const
	{
		fprintf(mFile,"\"%s.miwn.miwnb\"",mName.c_str());
	}
	void getMiSpecularColor()const
	{
		fprintf(mFile,"\"%s.misc\"",mName.c_str());
	}
	void getMiSpecularColorR()const
	{
		fprintf(mFile,"\"%s.misc.miscr\"",mName.c_str());
	}
	void getMiSpecularColorG()const
	{
		fprintf(mFile,"\"%s.misc.miscg\"",mName.c_str());
	}
	void getMiSpecularColorB()const
	{
		fprintf(mFile,"\"%s.misc.miscb\"",mName.c_str());
	}
	void getMiReflectivity()const
	{
		fprintf(mFile,"\"%s.mirf\"",mName.c_str());
	}
	void getMiRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.miri\"",mName.c_str());
	}
	void getMiRefractions()const
	{
		fprintf(mFile,"\"%s.mirc\"",mName.c_str());
	}
	void getMiAbsorbs()const
	{
		fprintf(mFile,"\"%s.miab\"",mName.c_str());
	}
	void getMiDiffuse()const
	{
		fprintf(mFile,"\"%s.midc\"",mName.c_str());
	}
	void getMiColor()const
	{
		fprintf(mFile,"\"%s.mic\"",mName.c_str());
	}
	void getMiColorR()const
	{
		fprintf(mFile,"\"%s.mic.micr\"",mName.c_str());
	}
	void getMiColorG()const
	{
		fprintf(mFile,"\"%s.mic.micg\"",mName.c_str());
	}
	void getMiColorB()const
	{
		fprintf(mFile,"\"%s.mic.micb\"",mName.c_str());
	}
	void getMiTransparency()const
	{
		fprintf(mFile,"\"%s.mit\"",mName.c_str());
	}
	void getMiTransparencyR()const
	{
		fprintf(mFile,"\"%s.mit.mitr\"",mName.c_str());
	}
	void getMiTransparencyG()const
	{
		fprintf(mFile,"\"%s.mit.mitg\"",mName.c_str());
	}
	void getMiTransparencyB()const
	{
		fprintf(mFile,"\"%s.mit.mitb\"",mName.c_str());
	}
	void getMiTranslucence()const
	{
		fprintf(mFile,"\"%s.mitc\"",mName.c_str());
	}
	void getMiTranslucenceFocus()const
	{
		fprintf(mFile,"\"%s.mitf\"",mName.c_str());
	}
	void getMiNormalCamera()const
	{
		fprintf(mFile,"\"%s.minc\"",mName.c_str());
	}
	void getMiNormalCameraX()const
	{
		fprintf(mFile,"\"%s.minc.mincx\"",mName.c_str());
	}
	void getMiNormalCameraY()const
	{
		fprintf(mFile,"\"%s.minc.mincy\"",mName.c_str());
	}
	void getMiNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.minc.mincz\"",mName.c_str());
	}
	void getMiOcclusionMask()const
	{
		fprintf(mFile,"\"%s.mio\"",mName.c_str());
	}
protected:
	UseBackground(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_USEBACKGROUND_H__
