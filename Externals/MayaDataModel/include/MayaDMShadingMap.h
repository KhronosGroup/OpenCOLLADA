/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHADINGMAP_H__
#define __MayaDM_SHADINGMAP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ShadingMap : public DependNode
{
public:
public:

	ShadingMap():DependNode(){}
	ShadingMap(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "shadingMap", shared, create){}
	virtual ~ShadingMap(){}

	void setMapFunctionU(unsigned int mfu)
	{
		if(mfu == 0) return;
		fprintf(mFile,"\tsetAttr \".mfu\" %i;\n", mfu);
	}
	void setMapFunctionV(unsigned int mfv)
	{
		if(mfv == 2) return;
		fprintf(mFile,"\tsetAttr \".mfv\" %i;\n", mfv);
	}
	void setColor(const float3& c)
	{
		fprintf(mFile,"\tsetAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorR(float cr)
	{
		if(cr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".c.cr\" %f;\n", cr);
	}
	void setColorG(float cg)
	{
		if(cg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".c.cg\" %f;\n", cg);
	}
	void setColorB(float cb)
	{
		if(cb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".c.cb\" %f;\n", cb);
	}
	void setShadingMapColor(const float3& sc)
	{
		fprintf(mFile,"\tsetAttr \".sc\" -type \"float3\" ");
		sc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setShadingMapColorR(float scr)
	{
		if(scr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.scr\" %f;\n", scr);
	}
	void setShadingMapColorG(float scg)
	{
		if(scg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.scg\" %f;\n", scg);
	}
	void setShadingMapColorB(float scb)
	{
		if(scb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sc.scb\" %f;\n", scb);
	}
	void setGlowColor(const float3& g)
	{
		fprintf(mFile,"\tsetAttr \".g\" -type \"float3\" ");
		g.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGlowColorR(float gr)
	{
		if(gr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g.gr\" %f;\n", gr);
	}
	void setGlowColorG(float gg)
	{
		if(gg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g.gg\" %f;\n", gg);
	}
	void setGlowColorB(float gb)
	{
		if(gb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g.gb\" %f;\n", gb);
	}
	void setTransparency(const float3& it)
	{
		fprintf(mFile,"\tsetAttr \".it\" -type \"float3\" ");
		it.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparencyR(float itr)
	{
		if(itr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itr\" %f;\n", itr);
	}
	void setTransparencyG(float itg)
	{
		if(itg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itg\" %f;\n", itg);
	}
	void setTransparencyB(float itb)
	{
		if(itb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".it.itb\" %f;\n", itb);
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
	void getUvCoord()const
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());
	}
	void getUCoord()const
	{
		fprintf(mFile,"\"%s.uv.uu\"",mName.c_str());
	}
	void getVCoord()const
	{
		fprintf(mFile,"\"%s.uv.vv\"",mName.c_str());
	}
	void getMapFunctionU()const
	{
		fprintf(mFile,"\"%s.mfu\"",mName.c_str());
	}
	void getMapFunctionV()const
	{
		fprintf(mFile,"\"%s.mfv\"",mName.c_str());
	}
	void getColor()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getColorR()const
	{
		fprintf(mFile,"\"%s.c.cr\"",mName.c_str());
	}
	void getColorG()const
	{
		fprintf(mFile,"\"%s.c.cg\"",mName.c_str());
	}
	void getColorB()const
	{
		fprintf(mFile,"\"%s.c.cb\"",mName.c_str());
	}
	void getShadingMapColor()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
	void getShadingMapColorR()const
	{
		fprintf(mFile,"\"%s.sc.scr\"",mName.c_str());
	}
	void getShadingMapColorG()const
	{
		fprintf(mFile,"\"%s.sc.scg\"",mName.c_str());
	}
	void getShadingMapColorB()const
	{
		fprintf(mFile,"\"%s.sc.scb\"",mName.c_str());
	}
	void getGlowColor()const
	{
		fprintf(mFile,"\"%s.g\"",mName.c_str());
	}
	void getGlowColorR()const
	{
		fprintf(mFile,"\"%s.g.gr\"",mName.c_str());
	}
	void getGlowColorG()const
	{
		fprintf(mFile,"\"%s.g.gg\"",mName.c_str());
	}
	void getGlowColorB()const
	{
		fprintf(mFile,"\"%s.g.gb\"",mName.c_str());
	}
	void getTransparency()const
	{
		fprintf(mFile,"\"%s.it\"",mName.c_str());
	}
	void getTransparencyR()const
	{
		fprintf(mFile,"\"%s.it.itr\"",mName.c_str());
	}
	void getTransparencyG()const
	{
		fprintf(mFile,"\"%s.it.itg\"",mName.c_str());
	}
	void getTransparencyB()const
	{
		fprintf(mFile,"\"%s.it.itb\"",mName.c_str());
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
	void getOutGlowColor()const
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());
	}
	void getOutGlowColorR()const
	{
		fprintf(mFile,"\"%s.ogc.ogr\"",mName.c_str());
	}
	void getOutGlowColorG()const
	{
		fprintf(mFile,"\"%s.ogc.ogg\"",mName.c_str());
	}
	void getOutGlowColorB()const
	{
		fprintf(mFile,"\"%s.ogc.ogb\"",mName.c_str());
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
protected:
	ShadingMap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SHADINGMAP_H__
