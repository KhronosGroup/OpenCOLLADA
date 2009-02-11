/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMEFOG_H__
#define __MayaDM_VOLUMEFOG_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class VolumeFog : public DependNode
{
public:
	struct ColorRamp{
		float colorRamp_Position;
		float3 colorRamp_Color;
		unsigned int colorRamp_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", colorRamp_Position);
			colorRamp_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", colorRamp_Interp);
		}
	};
public:
	VolumeFog():DependNode(){}
	VolumeFog(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "volumeFog"){}
	virtual ~VolumeFog(){}
	void setColor(const float3& cl)
	{
		fprintf(mFile,"\tsetAttr \".cl\" -type \"float3\" ");
		cl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(float cr)
	{
		if(cr == 0.9) return;
		fprintf(mFile,"\tsetAttr \".cl.cr\" %f;\n", cr);

	}
	void setColorG(float cg)
	{
		if(cg == 0.9) return;
		fprintf(mFile,"\tsetAttr \".cl.cg\" %f;\n", cg);

	}
	void setColorB(float cb)
	{
		if(cb == 0.9) return;
		fprintf(mFile,"\tsetAttr \".cl.cb\" %f;\n", cb);

	}
	void setColorRampInput(unsigned int cri)
	{
		if(cri == 0) return;
		fprintf(mFile,"\tsetAttr \".cri\" %i;\n", cri);

	}
	void setColorRamp(size_t crm_i,const ColorRamp& crm)
	{
		fprintf(mFile,"\tsetAttr \".crm[%i]\" ",crm_i);
		crm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorRamp_Position(size_t crm_i,float crmp)
	{
		if(crmp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crm[%i].crmp\" %f;\n", crm_i,crmp);

	}
	void setColorRamp_Color(size_t crm_i,const float3& crmc)
	{
		fprintf(mFile,"\tsetAttr \".crm[%i].crmc\" -type \"float3\" ",crm_i);
		crmc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorRamp_ColorR(size_t crm_i,float crmcr)
	{
		if(crmcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crm[%i].crmc.crmcr\" %f;\n", crm_i,crmcr);

	}
	void setColorRamp_ColorG(size_t crm_i,float crmcg)
	{
		if(crmcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crm[%i].crmc.crmcg\" %f;\n", crm_i,crmcg);

	}
	void setColorRamp_ColorB(size_t crm_i,float crmcb)
	{
		if(crmcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".crm[%i].crmc.crmcb\" %f;\n", crm_i,crmcb);

	}
	void setColorRamp_Interp(size_t crm_i,unsigned int crmi)
	{
		if(crmi == 0) return;
		fprintf(mFile,"\tsetAttr \".crm[%i].crmi\" %i;\n", crm_i,crmi);

	}
	void setTransparency(const float3& t)
	{
		fprintf(mFile,"\tsetAttr \".t\" -type \"float3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparencyR(float tr)
	{
		if(tr == 0.5) return;
		fprintf(mFile,"\tsetAttr \".t.tr\" %f;\n", tr);

	}
	void setTransparencyG(float tg)
	{
		if(tg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".t.tg\" %f;\n", tg);

	}
	void setTransparencyB(float tb)
	{
		if(tb == 0.5) return;
		fprintf(mFile,"\tsetAttr \".t.tb\" %f;\n", tb);

	}
	void setIncandescence(const float3& ic)
	{
		fprintf(mFile,"\tsetAttr \".ic\" -type \"float3\" ");
		ic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescenceR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ir\" %f;\n", ir);

	}
	void setIncandescenceG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ig\" %f;\n", ig);

	}
	void setIncandescenceB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ic.ib\" %f;\n", ib);

	}
	void setGlowIntensity(float gi)
	{
		if(gi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gi\" %f;\n", gi);

	}
	void setDensity(float dns)
	{
		if(dns == 1) return;
		fprintf(mFile,"\tsetAttr \".dns\" %f;\n", dns);

	}
	void setDensityMode(unsigned int dmd)
	{
		if(dmd == 1) return;
		fprintf(mFile,"\tsetAttr \".dmd\" %i;\n", dmd);

	}
	void setDropoffShape(unsigned int dos)
	{
		if(dos == 0) return;
		fprintf(mFile,"\tsetAttr \".dos\" %i;\n", dos);

	}
	void setEdgeDropoff(float edr)
	{
		if(edr == .5) return;
		fprintf(mFile,"\tsetAttr \".edr\" %f;\n", edr);

	}
	void setAxialDropoff(float axd)
	{
		if(axd == 0.3) return;
		fprintf(mFile,"\tsetAttr \".axd\" %f;\n", axd);

	}
	void setDropoffMethod(unsigned int drm)
	{
		if(drm == 0) return;
		fprintf(mFile,"\tsetAttr \".drm\" %i;\n", drm);

	}
	void setDropoffSubtract(float drs)
	{
		if(drs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".drs\" %f;\n", drs);

	}
	void setIlluminated(bool il)
	{
		if(il == false) return;
		fprintf(mFile,"\tsetAttr \".il\" %i;\n", il);

	}
	void setLightScatter(float lsc)
	{
		if(lsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lsc\" %f;\n", lsc);

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
	void getRayDirection()
	{
		fprintf(mFile,"\"%s.rad\"",mName.c_str());

	}
	void getRayDirectionX()
	{
		fprintf(mFile,"\"%s.rad.rdx\"",mName.c_str());

	}
	void getRayDirectionY()
	{
		fprintf(mFile,"\"%s.rad.rdy\"",mName.c_str());

	}
	void getRayDirectionZ()
	{
		fprintf(mFile,"\"%s.rad.rdz\"",mName.c_str());

	}
	void getPointWorld()
	{
		fprintf(mFile,"\"%s.pw\"",mName.c_str());

	}
	void getPointWorldX()
	{
		fprintf(mFile,"\"%s.pw.pwx\"",mName.c_str());

	}
	void getPointWorldY()
	{
		fprintf(mFile,"\"%s.pw.pwy\"",mName.c_str());

	}
	void getPointWorldZ()
	{
		fprintf(mFile,"\"%s.pw.pwz\"",mName.c_str());

	}
	void getFarPointWorld()
	{
		fprintf(mFile,"\"%s.fw\"",mName.c_str());

	}
	void getFarPointWorldX()
	{
		fprintf(mFile,"\"%s.fw.fwx\"",mName.c_str());

	}
	void getFarPointWorldY()
	{
		fprintf(mFile,"\"%s.fw.fwy\"",mName.c_str());

	}
	void getFarPointWorldZ()
	{
		fprintf(mFile,"\"%s.fw.fwz\"",mName.c_str());

	}
	void getPointObj()
	{
		fprintf(mFile,"\"%s.po\"",mName.c_str());

	}
	void getPointObjX()
	{
		fprintf(mFile,"\"%s.po.pox\"",mName.c_str());

	}
	void getPointObjY()
	{
		fprintf(mFile,"\"%s.po.poy\"",mName.c_str());

	}
	void getPointObjZ()
	{
		fprintf(mFile,"\"%s.po.poz\"",mName.c_str());

	}
	void getFarPointObj()
	{
		fprintf(mFile,"\"%s.fo\"",mName.c_str());

	}
	void getFarPointObjectX()
	{
		fprintf(mFile,"\"%s.fo.fox\"",mName.c_str());

	}
	void getFarPointObjectY()
	{
		fprintf(mFile,"\"%s.fo.foy\"",mName.c_str());

	}
	void getFarPointObjectZ()
	{
		fprintf(mFile,"\"%s.fo.foz\"",mName.c_str());

	}
	void getMatrixWorldToEye()
	{
		fprintf(mFile,"\"%s.wte\"",mName.c_str());

	}
	void getLightDataArray(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i]\"",mName.c_str(),ltd_i);

	}
	void getLightDirection(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionX(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldx\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionY(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldy\"",mName.c_str(),ltd_i);

	}
	void getLightDirectionZ(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldz\"",mName.c_str(),ltd_i);

	}
	void getLightIntensity(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityR(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lir\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityG(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lig\"",mName.c_str(),ltd_i);

	}
	void getLightIntensityB(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lib\"",mName.c_str(),ltd_i);

	}
	void getLightAmbient(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].la\"",mName.c_str(),ltd_i);

	}
	void getLightDiffuse(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ldf\"",mName.c_str(),ltd_i);

	}
	void getLightSpecular(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].ls\"",mName.c_str(),ltd_i);

	}
	void getLightShadowFraction(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].lsf\"",mName.c_str(),ltd_i);

	}
	void getPreShadowIntensity(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].psi\"",mName.c_str(),ltd_i);

	}
	void getLightBlindData(size_t ltd_i)
	{
		fprintf(mFile,"\"%s.ltd[%i].lbd\"",mName.c_str(),ltd_i);

	}
	void getColor()
	{
		fprintf(mFile,"\"%s.cl\"",mName.c_str());

	}
	void getColorR()
	{
		fprintf(mFile,"\"%s.cl.cr\"",mName.c_str());

	}
	void getColorG()
	{
		fprintf(mFile,"\"%s.cl.cg\"",mName.c_str());

	}
	void getColorB()
	{
		fprintf(mFile,"\"%s.cl.cb\"",mName.c_str());

	}
	void getColorRampInput()
	{
		fprintf(mFile,"\"%s.cri\"",mName.c_str());

	}
	void getColorRamp(size_t crm_i)
	{
		fprintf(mFile,"\"%s.crm[%i]\"",mName.c_str(),crm_i);

	}
	void getColorRamp_Position(size_t crm_i)
	{
		fprintf(mFile,"\"%s.crm[%i].crmp\"",mName.c_str(),crm_i);

	}
	void getColorRamp_Color(size_t crm_i)
	{
		fprintf(mFile,"\"%s.crm[%i].crmc\"",mName.c_str(),crm_i);

	}
	void getColorRamp_ColorR(size_t crm_i)
	{
		fprintf(mFile,"\"%s.crm[%i].crmc.crmcr\"",mName.c_str(),crm_i);

	}
	void getColorRamp_ColorG(size_t crm_i)
	{
		fprintf(mFile,"\"%s.crm[%i].crmc.crmcg\"",mName.c_str(),crm_i);

	}
	void getColorRamp_ColorB(size_t crm_i)
	{
		fprintf(mFile,"\"%s.crm[%i].crmc.crmcb\"",mName.c_str(),crm_i);

	}
	void getColorRamp_Interp(size_t crm_i)
	{
		fprintf(mFile,"\"%s.crm[%i].crmi\"",mName.c_str(),crm_i);

	}
	void getTransparency()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getTransparencyR()
	{
		fprintf(mFile,"\"%s.t.tr\"",mName.c_str());

	}
	void getTransparencyG()
	{
		fprintf(mFile,"\"%s.t.tg\"",mName.c_str());

	}
	void getTransparencyB()
	{
		fprintf(mFile,"\"%s.t.tb\"",mName.c_str());

	}
	void getIncandescence()
	{
		fprintf(mFile,"\"%s.ic\"",mName.c_str());

	}
	void getIncandescenceR()
	{
		fprintf(mFile,"\"%s.ic.ir\"",mName.c_str());

	}
	void getIncandescenceG()
	{
		fprintf(mFile,"\"%s.ic.ig\"",mName.c_str());

	}
	void getIncandescenceB()
	{
		fprintf(mFile,"\"%s.ic.ib\"",mName.c_str());

	}
	void getGlowIntensity()
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());

	}
	void getOutGlowColor()
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());

	}
	void getOutGlowColorR()
	{
		fprintf(mFile,"\"%s.ogc.ogr\"",mName.c_str());

	}
	void getOutGlowColorG()
	{
		fprintf(mFile,"\"%s.ogc.ogg\"",mName.c_str());

	}
	void getOutGlowColorB()
	{
		fprintf(mFile,"\"%s.ogc.ogb\"",mName.c_str());

	}
	void getDensity()
	{
		fprintf(mFile,"\"%s.dns\"",mName.c_str());

	}
	void getDensityMode()
	{
		fprintf(mFile,"\"%s.dmd\"",mName.c_str());

	}
	void getDropoffShape()
	{
		fprintf(mFile,"\"%s.dos\"",mName.c_str());

	}
	void getEdgeDropoff()
	{
		fprintf(mFile,"\"%s.edr\"",mName.c_str());

	}
	void getAxialDropoff()
	{
		fprintf(mFile,"\"%s.axd\"",mName.c_str());

	}
	void getDropoffMethod()
	{
		fprintf(mFile,"\"%s.drm\"",mName.c_str());

	}
	void getDropoffSubtract()
	{
		fprintf(mFile,"\"%s.drs\"",mName.c_str());

	}
	void getIlluminated()
	{
		fprintf(mFile,"\"%s.il\"",mName.c_str());

	}
	void getLightScatter()
	{
		fprintf(mFile,"\"%s.lsc\"",mName.c_str());

	}
	void getMatteOpacityMode()
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());

	}
	void getMatteOpacity()
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());

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
protected:
	VolumeFog(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMEFOG_H__
