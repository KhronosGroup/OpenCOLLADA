/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IMAGEPLANE_H__
#define __MayaDM_IMAGEPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ImagePlane : public DependNode
{
public:
public:

	ImagePlane():DependNode(){}
	ImagePlane(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "imagePlane", shared, create){}
	virtual ~ImagePlane(){}

	void setType(unsigned int t)
	{
		if(t == 0) return;
		fprintf(mFile,"\tsetAttr \".t\" %i;\n", t);
	}
	void setImageName(const string& imn)
	{
		if(imn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".imn\" -type \"string\" ");
		imn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUseFrameExtension(bool ufe)
	{
		if(ufe == false) return;
		fprintf(mFile,"\tsetAttr \".ufe\" %i;\n", ufe);
	}
	void setFrameExtension(int fe)
	{
		if(fe == 1) return;
		fprintf(mFile,"\tsetAttr \".fe\" %i;\n", fe);
	}
	void setFrameOffset(int fo)
	{
		if(fo == 0) return;
		fprintf(mFile,"\tsetAttr \".fo\" %i;\n", fo);
	}
	void setCoverage(const short2& cov)
	{
		if(cov == short2(1, 1)) return;
		fprintf(mFile,"\tsetAttr \".cov\" -type \"short2\" ");
		cov.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCoverageX(short cvx)
	{
		if(cvx == 0) return;
		fprintf(mFile,"\tsetAttr \".cov.cvx\" %i;\n", cvx);
	}
	void setCoverageY(short cvy)
	{
		if(cvy == 0) return;
		fprintf(mFile,"\tsetAttr \".cov.cvy\" %i;\n", cvy);
	}
	void setCoverageOrigin(const short2& co)
	{
		if(co == short2(0, 0)) return;
		fprintf(mFile,"\tsetAttr \".co\" -type \"short2\" ");
		co.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCoverageOriginX(short cox)
	{
		if(cox == 0) return;
		fprintf(mFile,"\tsetAttr \".co.cox\" %i;\n", cox);
	}
	void setCoverageOriginY(short coy)
	{
		if(coy == 0) return;
		fprintf(mFile,"\tsetAttr \".co.coy\" %i;\n", coy);
	}
	void setFit(unsigned int f)
	{
		if(f == 1) return;
		fprintf(mFile,"\tsetAttr \".f\" %i;\n", f);
	}
	void setDisplayMode(unsigned int dm)
	{
		if(dm == 3) return;
		fprintf(mFile,"\tsetAttr \".dm\" %i;\n", dm);
	}
	void setDisplayOnlyIfCurrent(bool dic)
	{
		if(dic == false) return;
		fprintf(mFile,"\tsetAttr \".dic\" %i;\n", dic);
	}
	void setColorGain(const float3& cg)
	{
		if(cg == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".cg\" -type \"float3\" ");
		cg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorGainR(float cgr)
	{
		if(cgr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cg.cgr\" %f;\n", cgr);
	}
	void setColorGainG(float cgg)
	{
		if(cgg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cg.cgg\" %f;\n", cgg);
	}
	void setColorGainB(float cgb)
	{
		if(cgb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cg.cgb\" %f;\n", cgb);
	}
	void setColorOffset(const float3& cof)
	{
		if(cof == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".cof\" -type \"float3\" ");
		cof.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorOffsetR(float cor)
	{
		if(cor == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cof.cor\" %f;\n", cor);
	}
	void setColorOffsetG(float cog)
	{
		if(cog == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cof.cog\" %f;\n", cog);
	}
	void setColorOffsetB(float cob)
	{
		if(cob == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cof.cob\" %f;\n", cob);
	}
	void setAlphaGain(double ag)
	{
		if(ag == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ag\" %f;\n", ag);
	}
	void setShadingSamplesOverride(bool sso)
	{
		if(sso == true) return;
		fprintf(mFile,"\tsetAttr \".sso\" %i;\n", sso);
	}
	void setShadingSamples(int ssa)
	{
		if(ssa == 1) return;
		fprintf(mFile,"\tsetAttr \".ssa\" %i;\n", ssa);
	}
	void setMaxShadingSamples(int msa)
	{
		if(msa == 1) return;
		fprintf(mFile,"\tsetAttr \".msa\" %i;\n", msa);
	}
	void setLockedToCamera(bool dlc)
	{
		if(dlc == true) return;
		fprintf(mFile,"\tsetAttr \".dlc\" %i;\n", dlc);
	}
	void setDepth(double d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void setSqueezeCorrection(double sqc)
	{
		if(sqc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sqc\" %f;\n", sqc);
	}
	void setSize(const double2& s)
	{
		if(s == double2(3.6, 2.4)) return;
		fprintf(mFile,"\tsetAttr \".s\" -type \"double2\" ");
		s.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSizeX(double sx)
	{
		if(sx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s.sx\" %f;\n", sx);
	}
	void setSizeY(double sy)
	{
		if(sy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".s.sy\" %f;\n", sy);
	}
	void setOffset(const double2& o)
	{
		if(o == double2(0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".o\" -type \"double2\" ");
		o.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOffsetX(double ox)
	{
		if(ox == 0.0) return;
		fprintf(mFile,"\tsetAttr \".o.ox\" %f;\n", ox);
	}
	void setOffsetY(double oy)
	{
		if(oy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".o.oy\" %f;\n", oy);
	}
	void setCenter(const double3& c)
	{
		if(c == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".c\" -type \"double3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCenterX(double cx)
	{
		if(cx == 0) return;
		fprintf(mFile,"\tsetAttr \".c.cx\" %f;\n", cx);
	}
	void setCenterY(double cy)
	{
		if(cy == 0) return;
		fprintf(mFile,"\tsetAttr \".c.cy\" %f;\n", cy);
	}
	void setCenterZ(double cz)
	{
		if(cz == 0) return;
		fprintf(mFile,"\tsetAttr \".c.cz\" %f;\n", cz);
	}
	void setWidth(double w)
	{
		if(w == 0) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void setHeight(double h)
	{
		if(h == 0) return;
		fprintf(mFile,"\tsetAttr \".h\" %f;\n", h);
	}
	void setVisibleInReflections(bool vir)
	{
		if(vir == false) return;
		fprintf(mFile,"\tsetAttr \".vir\" %i;\n", vir);
	}
	void setVisibleInRefractions(bool vif)
	{
		if(vif == false) return;
		fprintf(mFile,"\tsetAttr \".vif\" %i;\n", vif);
	}
	void setRotate(double r)
	{
		if(r == 0) return;
		fprintf(mFile,"\tsetAttr \".r\" %f;\n", r);
	}
	void setUseDepthMap(bool udm)
	{
		if(udm == false) return;
		fprintf(mFile,"\tsetAttr \".udm\" %i;\n", udm);
	}
	void setCompositeDepth(bool cmp)
	{
		if(cmp == true) return;
		fprintf(mFile,"\tsetAttr \".cmp\" %i;\n", cmp);
	}
	void setAlreadyPremult(bool pre)
	{
		if(pre == false) return;
		fprintf(mFile,"\tsetAttr \".pre\" %i;\n", pre);
	}
	void setDepthOversample(bool osp)
	{
		if(osp == false) return;
		fprintf(mFile,"\tsetAttr \".osp\" %i;\n", osp);
	}
	void setSeparateDepth(bool sd)
	{
		if(sd == false) return;
		fprintf(mFile,"\tsetAttr \".sd\" %i;\n", sd);
	}
	void setDepthFile(const string& df)
	{
		if(df == "false") return;
		fprintf(mFile,"\tsetAttr \".df\" -type \"string\" ");
		df.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDepthBias(double dg)
	{
		if(dg == 0) return;
		fprintf(mFile,"\tsetAttr \".dg\" %f;\n", dg);
	}
	void setDepthScale(double ds)
	{
		if(ds == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ds\" %f;\n", ds);
	}
	void getType()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getImageName()const
	{
		fprintf(mFile,"\"%s.imn\"",mName.c_str());
	}
	void getUseFrameExtension()const
	{
		fprintf(mFile,"\"%s.ufe\"",mName.c_str());
	}
	void getFrameExtension()const
	{
		fprintf(mFile,"\"%s.fe\"",mName.c_str());
	}
	void getFrameOffset()const
	{
		fprintf(mFile,"\"%s.fo\"",mName.c_str());
	}
	void getCoverage()const
	{
		fprintf(mFile,"\"%s.cov\"",mName.c_str());
	}
	void getCoverageX()const
	{
		fprintf(mFile,"\"%s.cov.cvx\"",mName.c_str());
	}
	void getCoverageY()const
	{
		fprintf(mFile,"\"%s.cov.cvy\"",mName.c_str());
	}
	void getCoverageOrigin()const
	{
		fprintf(mFile,"\"%s.co\"",mName.c_str());
	}
	void getCoverageOriginX()const
	{
		fprintf(mFile,"\"%s.co.cox\"",mName.c_str());
	}
	void getCoverageOriginY()const
	{
		fprintf(mFile,"\"%s.co.coy\"",mName.c_str());
	}
	void getSourceTexture()const
	{
		fprintf(mFile,"\"%s.stx\"",mName.c_str());
	}
	void getFit()const
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());
	}
	void getDisplayMode()const
	{
		fprintf(mFile,"\"%s.dm\"",mName.c_str());
	}
	void getDisplayOnlyIfCurrent()const
	{
		fprintf(mFile,"\"%s.dic\"",mName.c_str());
	}
	void getAlphaGain()const
	{
		fprintf(mFile,"\"%s.ag\"",mName.c_str());
	}
	void getShadingSamplesOverride()const
	{
		fprintf(mFile,"\"%s.sso\"",mName.c_str());
	}
	void getShadingSamples()const
	{
		fprintf(mFile,"\"%s.ssa\"",mName.c_str());
	}
	void getMaxShadingSamples()const
	{
		fprintf(mFile,"\"%s.msa\"",mName.c_str());
	}
	void getLockedToCamera()const
	{
		fprintf(mFile,"\"%s.dlc\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getSqueezeCorrection()const
	{
		fprintf(mFile,"\"%s.sqc\"",mName.c_str());
	}
	void getSize()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getSizeX()const
	{
		fprintf(mFile,"\"%s.s.sx\"",mName.c_str());
	}
	void getSizeY()const
	{
		fprintf(mFile,"\"%s.s.sy\"",mName.c_str());
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getOffsetX()const
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());
	}
	void getOffsetY()const
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());
	}
	void getCenter()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getCenterX()const
	{
		fprintf(mFile,"\"%s.c.cx\"",mName.c_str());
	}
	void getCenterY()const
	{
		fprintf(mFile,"\"%s.c.cy\"",mName.c_str());
	}
	void getCenterZ()const
	{
		fprintf(mFile,"\"%s.c.cz\"",mName.c_str());
	}
	void getWidth()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getHeight()const
	{
		fprintf(mFile,"\"%s.h\"",mName.c_str());
	}
	void getVisibleInReflections()const
	{
		fprintf(mFile,"\"%s.vir\"",mName.c_str());
	}
	void getVisibleInRefractions()const
	{
		fprintf(mFile,"\"%s.vif\"",mName.c_str());
	}
	void getRotate()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getUseDepthMap()const
	{
		fprintf(mFile,"\"%s.udm\"",mName.c_str());
	}
	void getCompositeDepth()const
	{
		fprintf(mFile,"\"%s.cmp\"",mName.c_str());
	}
	void getAlreadyPremult()const
	{
		fprintf(mFile,"\"%s.pre\"",mName.c_str());
	}
	void getDepthOversample()const
	{
		fprintf(mFile,"\"%s.osp\"",mName.c_str());
	}
	void getSeparateDepth()const
	{
		fprintf(mFile,"\"%s.sd\"",mName.c_str());
	}
	void getDepthFile()const
	{
		fprintf(mFile,"\"%s.df\"",mName.c_str());
	}
	void getDepthBias()const
	{
		fprintf(mFile,"\"%s.dg\"",mName.c_str());
	}
	void getDepthScale()const
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());
	}
protected:
	ImagePlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IMAGEPLANE_H__
