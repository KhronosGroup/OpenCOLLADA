/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACESHADER_H__
#define __MayaDM_SURFACESHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class SurfaceShader : public DependNode
{
public:
public:
	SurfaceShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "surfaceShader"){}
	virtual ~SurfaceShader(){}
	void setOutColor(const float3& oc)
	{
		if(oc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".oc\" -type \"float3\" ");
		oc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutColorR(float ocr)
	{
		if(ocr == 0.0) return;
		fprintf(mFile,"setAttr \".oc.ocr\" %f;\n", ocr);

	}
	void setOutColorG(float ocg)
	{
		if(ocg == 0.0) return;
		fprintf(mFile,"setAttr \".oc.ocg\" %f;\n", ocg);

	}
	void setOutColorB(float ocb)
	{
		if(ocb == 0.0) return;
		fprintf(mFile,"setAttr \".oc.ocb\" %f;\n", ocb);

	}
	void setOutTransparency(const float3& ot)
	{
		if(ot == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".ot\" -type \"float3\" ");
		ot.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutTransparencyR(float otr)
	{
		if(otr == 0.0) return;
		fprintf(mFile,"setAttr \".ot.otr\" %f;\n", otr);

	}
	void setOutTransparencyG(float otg)
	{
		if(otg == 0.0) return;
		fprintf(mFile,"setAttr \".ot.otg\" %f;\n", otg);

	}
	void setOutTransparencyB(float otb)
	{
		if(otb == 0.0) return;
		fprintf(mFile,"setAttr \".ot.otb\" %f;\n", otb);

	}
	void setOutMatteOpacity(const float3& omo)
	{
		if(omo == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".omo\" -type \"float3\" ");
		omo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutMatteOpacityR(float omor)
	{
		if(omor == 0.0) return;
		fprintf(mFile,"setAttr \".omo.omor\" %f;\n", omor);

	}
	void setOutMatteOpacityG(float omog)
	{
		if(omog == 0.0) return;
		fprintf(mFile,"setAttr \".omo.omog\" %f;\n", omog);

	}
	void setOutMatteOpacityB(float omob)
	{
		if(omob == 0.0) return;
		fprintf(mFile,"setAttr \".omo.omob\" %f;\n", omob);

	}
	void setOutGlowColor(const float3& og)
	{
		if(og == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".og\" -type \"float3\" ");
		og.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOutGlowColorR(float ogr)
	{
		if(ogr == 0.0) return;
		fprintf(mFile,"setAttr \".og.ogr\" %f;\n", ogr);

	}
	void setOutGlowColorG(float ogg)
	{
		if(ogg == 0.0) return;
		fprintf(mFile,"setAttr \".og.ogg\" %f;\n", ogg);

	}
	void setOutGlowColorB(float ogb)
	{
		if(ogb == 0.0) return;
		fprintf(mFile,"setAttr \".og.ogb\" %f;\n", ogb);

	}
	void setMiDeriveFromMaya(bool mifm)
	{
		if(mifm == true) return;
		fprintf(mFile,"setAttr \".mifm\" %i;\n", mifm);

	}
	void setMiShinyness(float mis)
	{
		if(mis == 10) return;
		fprintf(mFile,"setAttr \".mis\" %f;\n", mis);

	}
	void setMiAngle(float mia)
	{
		if(mia == 0) return;
		fprintf(mFile,"setAttr \".mia\" %f;\n", mia);

	}
	void setMiSpreadX(float misx)
	{
		if(misx == 10) return;
		fprintf(mFile,"setAttr \".misx\" %f;\n", misx);

	}
	void setMiSpreadY(float misy)
	{
		if(misy == 5) return;
		fprintf(mFile,"setAttr \".misy\" %f;\n", misy);

	}
	void setMiWhiteness(const float3& miwn)
	{
		fprintf(mFile,"setAttr \".miwn\" -type \"float3\" ");
		miwn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiWhitenessR(float miwnr)
	{
		if(miwnr == 0.5) return;
		fprintf(mFile,"setAttr \".miwn.miwnr\" %f;\n", miwnr);

	}
	void setMiWhitenessG(float miwng)
	{
		if(miwng == 0.5) return;
		fprintf(mFile,"setAttr \".miwn.miwng\" %f;\n", miwng);

	}
	void setMiWhitenessB(float miwnb)
	{
		if(miwnb == 0.5) return;
		fprintf(mFile,"setAttr \".miwn.miwnb\" %f;\n", miwnb);

	}
	void setMiSpecularColor(const float3& misc)
	{
		fprintf(mFile,"setAttr \".misc\" -type \"float3\" ");
		misc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiSpecularColorR(float miscr)
	{
		if(miscr == 0.5) return;
		fprintf(mFile,"setAttr \".misc.miscr\" %f;\n", miscr);

	}
	void setMiSpecularColorG(float miscg)
	{
		if(miscg == 0.5) return;
		fprintf(mFile,"setAttr \".misc.miscg\" %f;\n", miscg);

	}
	void setMiSpecularColorB(float miscb)
	{
		if(miscb == 0.5) return;
		fprintf(mFile,"setAttr \".misc.miscb\" %f;\n", miscb);

	}
	void setMiReflectivity(float mirf)
	{
		if(mirf == 0.5) return;
		fprintf(mFile,"setAttr \".mirf\" %f;\n", mirf);

	}
	void setMiRefractiveIndex(float miri)
	{
		if(miri == 1) return;
		fprintf(mFile,"setAttr \".miri\" %f;\n", miri);

	}
	void setMiRefractions(bool mirc)
	{
		if(mirc == true) return;
		fprintf(mFile,"setAttr \".mirc\" %i;\n", mirc);

	}
	void setMiAbsorbs(bool miab)
	{
		if(miab == true) return;
		fprintf(mFile,"setAttr \".miab\" %i;\n", miab);

	}
	void setMiDiffuse(float midc)
	{
		if(midc == 0.8) return;
		fprintf(mFile,"setAttr \".midc\" %f;\n", midc);

	}
	void setMiColor(const float3& mic)
	{
		fprintf(mFile,"setAttr \".mic\" -type \"float3\" ");
		mic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiColorR(float micr)
	{
		if(micr == 0.5) return;
		fprintf(mFile,"setAttr \".mic.micr\" %f;\n", micr);

	}
	void setMiColorG(float micg)
	{
		if(micg == 0.5) return;
		fprintf(mFile,"setAttr \".mic.micg\" %f;\n", micg);

	}
	void setMiColorB(float micb)
	{
		if(micb == 0.5) return;
		fprintf(mFile,"setAttr \".mic.micb\" %f;\n", micb);

	}
	void setMiTransparency(const float3& mit)
	{
		fprintf(mFile,"setAttr \".mit\" -type \"float3\" ");
		mit.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiTransparencyR(float mitr)
	{
		if(mitr == 0) return;
		fprintf(mFile,"setAttr \".mit.mitr\" %f;\n", mitr);

	}
	void setMiTransparencyG(float mitg)
	{
		if(mitg == 0) return;
		fprintf(mFile,"setAttr \".mit.mitg\" %f;\n", mitg);

	}
	void setMiTransparencyB(float mitb)
	{
		if(mitb == 0) return;
		fprintf(mFile,"setAttr \".mit.mitb\" %f;\n", mitb);

	}
	void setMiTranslucence(float mitc)
	{
		if(mitc == 0) return;
		fprintf(mFile,"setAttr \".mitc\" %f;\n", mitc);

	}
	void setMiTranslucenceFocus(float mitf)
	{
		if(mitf == 0.5) return;
		fprintf(mFile,"setAttr \".mitf\" %f;\n", mitf);

	}
	void setMiNormalCamera(const float3& minc)
	{
		fprintf(mFile,"setAttr \".minc\" -type \"float3\" ");
		minc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiNormalCameraX(float mincx)
	{
		if(mincx == 0) return;
		fprintf(mFile,"setAttr \".minc.mincx\" %f;\n", mincx);

	}
	void setMiNormalCameraY(float mincy)
	{
		if(mincy == 0) return;
		fprintf(mFile,"setAttr \".minc.mincy\" %f;\n", mincy);

	}
	void setMiNormalCameraZ(float mincz)
	{
		if(mincz == 0) return;
		fprintf(mFile,"setAttr \".minc.mincz\" %f;\n", mincz);

	}
	void setMaterialAlphaGain(float maga)
	{
		if(maga == 1.0) return;
		fprintf(mFile,"setAttr \".maga\" %f;\n", maga);

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
	void getOutTransparency()
	{
		fprintf(mFile,"\"%s.ot\"",mName.c_str());

	}
	void getOutTransparencyR()
	{
		fprintf(mFile,"\"%s.ot.otr\"",mName.c_str());

	}
	void getOutTransparencyG()
	{
		fprintf(mFile,"\"%s.ot.otg\"",mName.c_str());

	}
	void getOutTransparencyB()
	{
		fprintf(mFile,"\"%s.ot.otb\"",mName.c_str());

	}
	void getOutMatteOpacity()
	{
		fprintf(mFile,"\"%s.omo\"",mName.c_str());

	}
	void getOutMatteOpacityR()
	{
		fprintf(mFile,"\"%s.omo.omor\"",mName.c_str());

	}
	void getOutMatteOpacityG()
	{
		fprintf(mFile,"\"%s.omo.omog\"",mName.c_str());

	}
	void getOutMatteOpacityB()
	{
		fprintf(mFile,"\"%s.omo.omob\"",mName.c_str());

	}
	void getOutGlowColor()
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());

	}
	void getOutGlowColorR()
	{
		fprintf(mFile,"\"%s.og.ogr\"",mName.c_str());

	}
	void getOutGlowColorG()
	{
		fprintf(mFile,"\"%s.og.ogg\"",mName.c_str());

	}
	void getOutGlowColorB()
	{
		fprintf(mFile,"\"%s.og.ogb\"",mName.c_str());

	}
	void getMiDeriveFromMaya()
	{
		fprintf(mFile,"\"%s.mifm\"",mName.c_str());

	}
	void getMiShinyness()
	{
		fprintf(mFile,"\"%s.mis\"",mName.c_str());

	}
	void getMiAngle()
	{
		fprintf(mFile,"\"%s.mia\"",mName.c_str());

	}
	void getMiSpreadX()
	{
		fprintf(mFile,"\"%s.misx\"",mName.c_str());

	}
	void getMiSpreadY()
	{
		fprintf(mFile,"\"%s.misy\"",mName.c_str());

	}
	void getMiWhiteness()
	{
		fprintf(mFile,"\"%s.miwn\"",mName.c_str());

	}
	void getMiWhitenessR()
	{
		fprintf(mFile,"\"%s.miwn.miwnr\"",mName.c_str());

	}
	void getMiWhitenessG()
	{
		fprintf(mFile,"\"%s.miwn.miwng\"",mName.c_str());

	}
	void getMiWhitenessB()
	{
		fprintf(mFile,"\"%s.miwn.miwnb\"",mName.c_str());

	}
	void getMiSpecularColor()
	{
		fprintf(mFile,"\"%s.misc\"",mName.c_str());

	}
	void getMiSpecularColorR()
	{
		fprintf(mFile,"\"%s.misc.miscr\"",mName.c_str());

	}
	void getMiSpecularColorG()
	{
		fprintf(mFile,"\"%s.misc.miscg\"",mName.c_str());

	}
	void getMiSpecularColorB()
	{
		fprintf(mFile,"\"%s.misc.miscb\"",mName.c_str());

	}
	void getMiReflectivity()
	{
		fprintf(mFile,"\"%s.mirf\"",mName.c_str());

	}
	void getMiRefractiveIndex()
	{
		fprintf(mFile,"\"%s.miri\"",mName.c_str());

	}
	void getMiRefractions()
	{
		fprintf(mFile,"\"%s.mirc\"",mName.c_str());

	}
	void getMiAbsorbs()
	{
		fprintf(mFile,"\"%s.miab\"",mName.c_str());

	}
	void getMiDiffuse()
	{
		fprintf(mFile,"\"%s.midc\"",mName.c_str());

	}
	void getMiColor()
	{
		fprintf(mFile,"\"%s.mic\"",mName.c_str());

	}
	void getMiColorR()
	{
		fprintf(mFile,"\"%s.mic.micr\"",mName.c_str());

	}
	void getMiColorG()
	{
		fprintf(mFile,"\"%s.mic.micg\"",mName.c_str());

	}
	void getMiColorB()
	{
		fprintf(mFile,"\"%s.mic.micb\"",mName.c_str());

	}
	void getMiTransparency()
	{
		fprintf(mFile,"\"%s.mit\"",mName.c_str());

	}
	void getMiTransparencyR()
	{
		fprintf(mFile,"\"%s.mit.mitr\"",mName.c_str());

	}
	void getMiTransparencyG()
	{
		fprintf(mFile,"\"%s.mit.mitg\"",mName.c_str());

	}
	void getMiTransparencyB()
	{
		fprintf(mFile,"\"%s.mit.mitb\"",mName.c_str());

	}
	void getMiTranslucence()
	{
		fprintf(mFile,"\"%s.mitc\"",mName.c_str());

	}
	void getMiTranslucenceFocus()
	{
		fprintf(mFile,"\"%s.mitf\"",mName.c_str());

	}
	void getMiNormalCamera()
	{
		fprintf(mFile,"\"%s.minc\"",mName.c_str());

	}
	void getMiNormalCameraX()
	{
		fprintf(mFile,"\"%s.minc.mincx\"",mName.c_str());

	}
	void getMiNormalCameraY()
	{
		fprintf(mFile,"\"%s.minc.mincy\"",mName.c_str());

	}
	void getMiNormalCameraZ()
	{
		fprintf(mFile,"\"%s.minc.mincz\"",mName.c_str());

	}
	void getMaterialAlphaGain()
	{
		fprintf(mFile,"\"%s.maga\"",mName.c_str());

	}
protected:
	SurfaceShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SURFACESHADER_H__
