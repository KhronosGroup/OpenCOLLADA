/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HWRENDERGLOBALS_H__
#define __MayaDM_HWRENDERGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class HwRenderGlobals : public DependNode
{
public:
public:

	HwRenderGlobals():DependNode(){}
	HwRenderGlobals(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "hwRenderGlobals", shared, create){}
	virtual ~HwRenderGlobals(){}

	void setRenderPasses(unsigned int rp)
	{
		if(rp == 0) return;
		fprintf(mFile,"\tsetAttr \".rp\" %i;\n", rp);
	}
	void setCameraIcons(bool cai)
	{
		if(cai == false) return;
		fprintf(mFile,"\tsetAttr \".cai\" %i;\n", cai);
	}
	void setCollisionIcons(bool coi)
	{
		if(coi == false) return;
		fprintf(mFile,"\tsetAttr \".coi\" %i;\n", coi);
	}
	void setBackgroundColor(const float3& bc)
	{
		if(bc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".bc\" -type \"float3\" ");
		bc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBackgroundColorR(float bcr)
	{
		if(bcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bc.bcr\" %f;\n", bcr);
	}
	void setBackgroundColorG(float bcg)
	{
		if(bcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bc.bcg\" %f;\n", bcg);
	}
	void setBackgroundColorB(float bcb)
	{
		if(bcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bc.bcb\" %f;\n", bcb);
	}
	void setEmitterIcons(bool ei)
	{
		if(ei == false) return;
		fprintf(mFile,"\tsetAttr \".ei\" %i;\n", ei);
	}
	void setExtension(unsigned int ex)
	{
		if(ex == 3) return;
		fprintf(mFile,"\tsetAttr \".ex\" %i;\n", ex);
	}
	void setEdgeSmoothing(float es)
	{
		if(es == 1.0) return;
		fprintf(mFile,"\tsetAttr \".es\" %f;\n", es);
	}
	void setEndFrame(int ef)
	{
		if(ef == 10) return;
		fprintf(mFile,"\tsetAttr \".ef\" %i;\n", ef);
	}
	void setByFrame(int bf)
	{
		if(bf == 1) return;
		fprintf(mFile,"\tsetAttr \".bf\" %i;\n", bf);
	}
	void setFieldIcons(bool fii)
	{
		if(fii == false) return;
		fprintf(mFile,"\tsetAttr \".fii\" %i;\n", fii);
	}
	void setStartFrame(int sf)
	{
		if(sf == 1) return;
		fprintf(mFile,"\tsetAttr \".sf\" %i;\n", sf);
	}
	void setGrid(bool gr)
	{
		if(gr == false) return;
		fprintf(mFile,"\tsetAttr \".gr\" %i;\n", gr);
	}
	void setLightIcons(bool li)
	{
		if(li == false) return;
		fprintf(mFile,"\tsetAttr \".li\" %i;\n", li);
	}
	void setLineSmoothing(bool ls)
	{
		if(ls == false) return;
		fprintf(mFile,"\tsetAttr \".ls\" %i;\n", ls);
	}
	void setMotionBlur(float mb)
	{
		if(mb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mb\" %f;\n", mb);
	}
	void setTransformIcons(bool ti)
	{
		if(ti == false) return;
		fprintf(mFile,"\tsetAttr \".ti\" %i;\n", ti);
	}
	void setTexturing(bool txt)
	{
		if(txt == true) return;
		fprintf(mFile,"\tsetAttr \".txt\" %i;\n", txt);
	}
	void setMultiPassRendering(bool mpr)
	{
		if(mpr == false) return;
		fprintf(mFile,"\tsetAttr \".mpr\" %i;\n", mpr);
	}
	void setWriteZDepth(bool wzd)
	{
		if(wzd == false) return;
		fprintf(mFile,"\tsetAttr \".wzd\" %i;\n", wzd);
	}
	void setFilename(const string& fn)
	{
		if(fn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".fn\" -type \"string\" ");
		fn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImageFormat(unsigned int if_)
	{
		if(if_ == 0) return;
		fprintf(mFile,"\tsetAttr \".if\" %i;\n", if_);
	}
	void setResolution(const string& res)
	{
		if(res == "NULL") return;
		fprintf(mFile,"\tsetAttr \".res\" -type \"string\" ");
		res.write(mFile);
		fprintf(mFile,";\n");
	}
	void setAlphaSource(unsigned int as)
	{
		if(as == 0) return;
		fprintf(mFile,"\tsetAttr \".as\" %i;\n", as);
	}
	void setDrawStyle(unsigned int ds)
	{
		if(ds == 3) return;
		fprintf(mFile,"\tsetAttr \".ds\" %i;\n", ds);
	}
	void setLightingMode(unsigned int lm)
	{
		if(lm == 0) return;
		fprintf(mFile,"\tsetAttr \".lm\" %i;\n", lm);
	}
	void setFullImageResolution(bool fir)
	{
		if(fir == false) return;
		fprintf(mFile,"\tsetAttr \".fir\" %i;\n", fir);
	}
	void setAntiAliasPolygons(bool aap)
	{
		if(aap == false) return;
		fprintf(mFile,"\tsetAttr \".aap\" %i;\n", aap);
	}
	void setGeometryMask(bool gh)
	{
		if(gh == false) return;
		fprintf(mFile,"\tsetAttr \".gh\" %i;\n", gh);
	}
	void setDisplayShadows(bool sd)
	{
		if(sd == false) return;
		fprintf(mFile,"\tsetAttr \".sd\" %i;\n", sd);
	}
	void getRenderPasses()const
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());
	}
	void getCameraIcons()const
	{
		fprintf(mFile,"\"%s.cai\"",mName.c_str());
	}
	void getCollisionIcons()const
	{
		fprintf(mFile,"\"%s.coi\"",mName.c_str());
	}
	void getBackgroundColor()const
	{
		fprintf(mFile,"\"%s.bc\"",mName.c_str());
	}
	void getBackgroundColorR()const
	{
		fprintf(mFile,"\"%s.bc.bcr\"",mName.c_str());
	}
	void getBackgroundColorG()const
	{
		fprintf(mFile,"\"%s.bc.bcg\"",mName.c_str());
	}
	void getBackgroundColorB()const
	{
		fprintf(mFile,"\"%s.bc.bcb\"",mName.c_str());
	}
	void getEmitterIcons()const
	{
		fprintf(mFile,"\"%s.ei\"",mName.c_str());
	}
	void getExtension()const
	{
		fprintf(mFile,"\"%s.ex\"",mName.c_str());
	}
	void getEdgeSmoothing()const
	{
		fprintf(mFile,"\"%s.es\"",mName.c_str());
	}
	void getEndFrame()const
	{
		fprintf(mFile,"\"%s.ef\"",mName.c_str());
	}
	void getByFrame()const
	{
		fprintf(mFile,"\"%s.bf\"",mName.c_str());
	}
	void getFieldIcons()const
	{
		fprintf(mFile,"\"%s.fii\"",mName.c_str());
	}
	void getStartFrame()const
	{
		fprintf(mFile,"\"%s.sf\"",mName.c_str());
	}
	void getGrid()const
	{
		fprintf(mFile,"\"%s.gr\"",mName.c_str());
	}
	void getLightIcons()const
	{
		fprintf(mFile,"\"%s.li\"",mName.c_str());
	}
	void getLineSmoothing()const
	{
		fprintf(mFile,"\"%s.ls\"",mName.c_str());
	}
	void getMotionBlur()const
	{
		fprintf(mFile,"\"%s.mb\"",mName.c_str());
	}
	void getTransformIcons()const
	{
		fprintf(mFile,"\"%s.ti\"",mName.c_str());
	}
	void getTexturing()const
	{
		fprintf(mFile,"\"%s.txt\"",mName.c_str());
	}
	void getMultiPassRendering()const
	{
		fprintf(mFile,"\"%s.mpr\"",mName.c_str());
	}
	void getWriteZDepth()const
	{
		fprintf(mFile,"\"%s.wzd\"",mName.c_str());
	}
	void getFilename()const
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());
	}
	void getImageFormat()const
	{
		fprintf(mFile,"\"%s.if\"",mName.c_str());
	}
	void getResolution()const
	{
		fprintf(mFile,"\"%s.res\"",mName.c_str());
	}
	void getAlphaSource()const
	{
		fprintf(mFile,"\"%s.as\"",mName.c_str());
	}
	void getDrawStyle()const
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());
	}
	void getLightingMode()const
	{
		fprintf(mFile,"\"%s.lm\"",mName.c_str());
	}
	void getFullImageResolution()const
	{
		fprintf(mFile,"\"%s.fir\"",mName.c_str());
	}
	void getAntiAliasPolygons()const
	{
		fprintf(mFile,"\"%s.aap\"",mName.c_str());
	}
	void getGeometryMask()const
	{
		fprintf(mFile,"\"%s.gh\"",mName.c_str());
	}
	void getDisplayShadows()const
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());
	}
protected:
	HwRenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HWRENDERGLOBALS_H__
