/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRANSFORM_H__
#define __MayaDM_TRANSFORM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDagNode.h"
namespace MayaDM
{
class Transform : public DagNode
{
public:
	struct MinTransLimitEnable{
		bool minTransXLimitEnable;
		bool minTransYLimitEnable;
		bool minTransZLimitEnable;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", minTransXLimitEnable);
			fprintf(file,"%i ", minTransYLimitEnable);
			fprintf(file,"%i", minTransZLimitEnable);
		}
	};
	struct MaxTransLimitEnable{
		bool maxTransXLimitEnable;
		bool maxTransYLimitEnable;
		bool maxTransZLimitEnable;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", maxTransXLimitEnable);
			fprintf(file,"%i ", maxTransYLimitEnable);
			fprintf(file,"%i", maxTransZLimitEnable);
		}
	};
	struct MinRotLimitEnable{
		bool minRotXLimitEnable;
		bool minRotYLimitEnable;
		bool minRotZLimitEnable;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", minRotXLimitEnable);
			fprintf(file,"%i ", minRotYLimitEnable);
			fprintf(file,"%i", minRotZLimitEnable);
		}
	};
	struct MaxRotLimitEnable{
		bool maxRotXLimitEnable;
		bool maxRotYLimitEnable;
		bool maxRotZLimitEnable;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", maxRotXLimitEnable);
			fprintf(file,"%i ", maxRotYLimitEnable);
			fprintf(file,"%i", maxRotZLimitEnable);
		}
	};
	struct MinScaleLimitEnable{
		bool minScaleXLimitEnable;
		bool minScaleYLimitEnable;
		bool minScaleZLimitEnable;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", minScaleXLimitEnable);
			fprintf(file,"%i ", minScaleYLimitEnable);
			fprintf(file,"%i", minScaleZLimitEnable);
		}
	};
	struct MaxScaleLimitEnable{
		bool maxScaleXLimitEnable;
		bool maxScaleYLimitEnable;
		bool maxScaleZLimitEnable;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", maxScaleXLimitEnable);
			fprintf(file,"%i ", maxScaleYLimitEnable);
			fprintf(file,"%i", maxScaleZLimitEnable);
		}
	};
	struct MentalRayControls{
		bool miDeriveFromMaya;
		bool miHide;
		unsigned int miVisible;
		unsigned int miTrace;
		unsigned int miShadow;
		unsigned int miCaustic;
		unsigned int miGlobillum;
		bool miExportGeoShader;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", miDeriveFromMaya);
			fprintf(file,"%i ", miHide);
			fprintf(file,"%i ", miVisible);
			fprintf(file,"%i ", miTrace);
			fprintf(file,"%i ", miShadow);
			fprintf(file,"%i ", miCaustic);
			fprintf(file,"%i ", miGlobillum);
			fprintf(file,"%i ", miExportGeoShader);
		}
	};
public:

	Transform():DagNode(){}
	Transform(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DagNode(file, name, parent, "transform", shared, create){}
	virtual ~Transform(){}

	void setTranslate(const double3& t)
	{
		fprintf(mFile,"\tsetAttr \".t\" -type \"double3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTranslateX(double tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"\tsetAttr \".t.tx\" %f;\n", tx);
	}
	void setTranslateY(double ty)
	{
		if(ty == 0) return;
		fprintf(mFile,"\tsetAttr \".t.ty\" %f;\n", ty);
	}
	void setTranslateZ(double tz)
	{
		if(tz == 0) return;
		fprintf(mFile,"\tsetAttr \".t.tz\" %f;\n", tz);
	}
	void setRotate(const double3& r)
	{
		fprintf(mFile,"\tsetAttr \".r\" -type \"double3\" ");
		r.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRotateX(double rx)
	{
		if(rx == 0) return;
		fprintf(mFile,"\tsetAttr \".r.rx\" %f;\n", rx);
	}
	void setRotateY(double ry)
	{
		if(ry == 0) return;
		fprintf(mFile,"\tsetAttr \".r.ry\" %f;\n", ry);
	}
	void setRotateZ(double rz)
	{
		if(rz == 0) return;
		fprintf(mFile,"\tsetAttr \".r.rz\" %f;\n", rz);
	}
	void setRotateOrder(unsigned int ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"\tsetAttr \".ro\" %i;\n", ro);
	}
	void setScale(const double3& s)
	{
		fprintf(mFile,"\tsetAttr \".s\" -type \"double3\" ");
		s.write(mFile);
		fprintf(mFile,";\n");
	}
	void setScaleX(double sx)
	{
		if(sx == 1.0) return;
		fprintf(mFile,"\tsetAttr \".s.sx\" %f;\n", sx);
	}
	void setScaleY(double sy)
	{
		if(sy == 1.0) return;
		fprintf(mFile,"\tsetAttr \".s.sy\" %f;\n", sy);
	}
	void setScaleZ(double sz)
	{
		if(sz == 1.0) return;
		fprintf(mFile,"\tsetAttr \".s.sz\" %f;\n", sz);
	}
	void setShear(const double3& sh)
	{
		fprintf(mFile,"\tsetAttr \".sh\" -type \"double3\" ");
		sh.write(mFile);
		fprintf(mFile,";\n");
	}
	void setShearXY(double shxy)
	{
		if(shxy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sh.shxy\" %f;\n", shxy);
	}
	void setShearXZ(double shxz)
	{
		if(shxz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sh.shxz\" %f;\n", shxz);
	}
	void setShearYZ(double shyz)
	{
		if(shyz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sh.shyz\" %f;\n", shyz);
	}
	void setRotatePivot(const double3& rp)
	{
		fprintf(mFile,"\tsetAttr \".rp\" -type \"double3\" ");
		rp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRotatePivotX(double rpx)
	{
		if(rpx == 0) return;
		fprintf(mFile,"\tsetAttr \".rp.rpx\" %f;\n", rpx);
	}
	void setRotatePivotY(double rpy)
	{
		if(rpy == 0) return;
		fprintf(mFile,"\tsetAttr \".rp.rpy\" %f;\n", rpy);
	}
	void setRotatePivotZ(double rpz)
	{
		if(rpz == 0) return;
		fprintf(mFile,"\tsetAttr \".rp.rpz\" %f;\n", rpz);
	}
	void setRotatePivotTranslate(const double3& rpt)
	{
		fprintf(mFile,"\tsetAttr \".rpt\" -type \"double3\" ");
		rpt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRotatePivotTranslateX(double rptx)
	{
		if(rptx == 0) return;
		fprintf(mFile,"\tsetAttr \".rpt.rptx\" %f;\n", rptx);
	}
	void setRotatePivotTranslateY(double rpty)
	{
		if(rpty == 0) return;
		fprintf(mFile,"\tsetAttr \".rpt.rpty\" %f;\n", rpty);
	}
	void setRotatePivotTranslateZ(double rptz)
	{
		if(rptz == 0) return;
		fprintf(mFile,"\tsetAttr \".rpt.rptz\" %f;\n", rptz);
	}
	void setScalePivot(const double3& sp)
	{
		fprintf(mFile,"\tsetAttr \".sp\" -type \"double3\" ");
		sp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setScalePivotX(double spx)
	{
		if(spx == 0) return;
		fprintf(mFile,"\tsetAttr \".sp.spx\" %f;\n", spx);
	}
	void setScalePivotY(double spy)
	{
		if(spy == 0) return;
		fprintf(mFile,"\tsetAttr \".sp.spy\" %f;\n", spy);
	}
	void setScalePivotZ(double spz)
	{
		if(spz == 0) return;
		fprintf(mFile,"\tsetAttr \".sp.spz\" %f;\n", spz);
	}
	void setScalePivotTranslate(const double3& spt)
	{
		fprintf(mFile,"\tsetAttr \".spt\" -type \"double3\" ");
		spt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setScalePivotTranslateX(double sptx)
	{
		if(sptx == 0) return;
		fprintf(mFile,"\tsetAttr \".spt.sptx\" %f;\n", sptx);
	}
	void setScalePivotTranslateY(double spty)
	{
		if(spty == 0) return;
		fprintf(mFile,"\tsetAttr \".spt.spty\" %f;\n", spty);
	}
	void setScalePivotTranslateZ(double sptz)
	{
		if(sptz == 0) return;
		fprintf(mFile,"\tsetAttr \".spt.sptz\" %f;\n", sptz);
	}
	void setRotateAxis(const double3& ra)
	{
		fprintf(mFile,"\tsetAttr \".ra\" -type \"double3\" ");
		ra.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRotateAxisX(double rax)
	{
		if(rax == 0) return;
		fprintf(mFile,"\tsetAttr \".ra.rax\" %f;\n", rax);
	}
	void setRotateAxisY(double ray)
	{
		if(ray == 0) return;
		fprintf(mFile,"\tsetAttr \".ra.ray\" %f;\n", ray);
	}
	void setRotateAxisZ(double raz)
	{
		if(raz == 0) return;
		fprintf(mFile,"\tsetAttr \".ra.raz\" %f;\n", raz);
	}
	void setMinTransLimit(const double3& mntl)
	{
		fprintf(mFile,"\tsetAttr \".mntl\" -type \"double3\" ");
		mntl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinTransXLimit(double mtxl)
	{
		if(mtxl == 1) return;
		fprintf(mFile,"\tsetAttr \".mntl.mtxl\" %f;\n", mtxl);
	}
	void setMinTransYLimit(double mtyl)
	{
		if(mtyl == 1) return;
		fprintf(mFile,"\tsetAttr \".mntl.mtyl\" %f;\n", mtyl);
	}
	void setMinTransZLimit(double mtzl)
	{
		if(mtzl == 1) return;
		fprintf(mFile,"\tsetAttr \".mntl.mtzl\" %f;\n", mtzl);
	}
	void setMaxTransLimit(const double3& mxtl)
	{
		fprintf(mFile,"\tsetAttr \".mxtl\" -type \"double3\" ");
		mxtl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxTransXLimit(double xtxl)
	{
		if(xtxl == 1) return;
		fprintf(mFile,"\tsetAttr \".mxtl.xtxl\" %f;\n", xtxl);
	}
	void setMaxTransYLimit(double xtyl)
	{
		if(xtyl == 1) return;
		fprintf(mFile,"\tsetAttr \".mxtl.xtyl\" %f;\n", xtyl);
	}
	void setMaxTransZLimit(double xtzl)
	{
		if(xtzl == 1) return;
		fprintf(mFile,"\tsetAttr \".mxtl.xtzl\" %f;\n", xtzl);
	}
	void setMinTransLimitEnable(const MinTransLimitEnable& mtle)
	{
		fprintf(mFile,"\tsetAttr \".mtle\" ");
		mtle.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinTransXLimitEnable(bool mtxe)
	{
		if(mtxe == false) return;
		fprintf(mFile,"\tsetAttr \".mtle.mtxe\" %i;\n", mtxe);
	}
	void setMinTransYLimitEnable(bool mtye)
	{
		if(mtye == false) return;
		fprintf(mFile,"\tsetAttr \".mtle.mtye\" %i;\n", mtye);
	}
	void setMinTransZLimitEnable(bool mtze)
	{
		if(mtze == false) return;
		fprintf(mFile,"\tsetAttr \".mtle.mtze\" %i;\n", mtze);
	}
	void setMaxTransLimitEnable(const MaxTransLimitEnable& xtle)
	{
		fprintf(mFile,"\tsetAttr \".xtle\" ");
		xtle.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxTransXLimitEnable(bool xtxe)
	{
		if(xtxe == false) return;
		fprintf(mFile,"\tsetAttr \".xtle.xtxe\" %i;\n", xtxe);
	}
	void setMaxTransYLimitEnable(bool xtye)
	{
		if(xtye == false) return;
		fprintf(mFile,"\tsetAttr \".xtle.xtye\" %i;\n", xtye);
	}
	void setMaxTransZLimitEnable(bool xtze)
	{
		if(xtze == false) return;
		fprintf(mFile,"\tsetAttr \".xtle.xtze\" %i;\n", xtze);
	}
	void setMinRotLimit(const double3& mnrl)
	{
		fprintf(mFile,"\tsetAttr \".mnrl\" -type \"double3\" ");
		mnrl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinRotXLimit(double mrxl)
	{
		if(mrxl == 4) return;
		fprintf(mFile,"\tsetAttr \".mnrl.mrxl\" %f;\n", mrxl);
	}
	void setMinRotYLimit(double mryl)
	{
		if(mryl == 4) return;
		fprintf(mFile,"\tsetAttr \".mnrl.mryl\" %f;\n", mryl);
	}
	void setMinRotZLimit(double mrzl)
	{
		if(mrzl == 4) return;
		fprintf(mFile,"\tsetAttr \".mnrl.mrzl\" %f;\n", mrzl);
	}
	void setMaxRotLimit(const double3& mxrl)
	{
		fprintf(mFile,"\tsetAttr \".mxrl\" -type \"double3\" ");
		mxrl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxRotXLimit(double xrxl)
	{
		if(xrxl == 4) return;
		fprintf(mFile,"\tsetAttr \".mxrl.xrxl\" %f;\n", xrxl);
	}
	void setMaxRotYLimit(double xryl)
	{
		if(xryl == 4) return;
		fprintf(mFile,"\tsetAttr \".mxrl.xryl\" %f;\n", xryl);
	}
	void setMaxRotZLimit(double xrzl)
	{
		if(xrzl == 4) return;
		fprintf(mFile,"\tsetAttr \".mxrl.xrzl\" %f;\n", xrzl);
	}
	void setMinRotLimitEnable(const MinRotLimitEnable& mrle)
	{
		fprintf(mFile,"\tsetAttr \".mrle\" ");
		mrle.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinRotXLimitEnable(bool mrxe)
	{
		if(mrxe == false) return;
		fprintf(mFile,"\tsetAttr \".mrle.mrxe\" %i;\n", mrxe);
	}
	void setMinRotYLimitEnable(bool mrye)
	{
		if(mrye == false) return;
		fprintf(mFile,"\tsetAttr \".mrle.mrye\" %i;\n", mrye);
	}
	void setMinRotZLimitEnable(bool mrze)
	{
		if(mrze == false) return;
		fprintf(mFile,"\tsetAttr \".mrle.mrze\" %i;\n", mrze);
	}
	void setMaxRotLimitEnable(const MaxRotLimitEnable& xrle)
	{
		fprintf(mFile,"\tsetAttr \".xrle\" ");
		xrle.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxRotXLimitEnable(bool xrxe)
	{
		if(xrxe == false) return;
		fprintf(mFile,"\tsetAttr \".xrle.xrxe\" %i;\n", xrxe);
	}
	void setMaxRotYLimitEnable(bool xrye)
	{
		if(xrye == false) return;
		fprintf(mFile,"\tsetAttr \".xrle.xrye\" %i;\n", xrye);
	}
	void setMaxRotZLimitEnable(bool xrze)
	{
		if(xrze == false) return;
		fprintf(mFile,"\tsetAttr \".xrle.xrze\" %i;\n", xrze);
	}
	void setMinScaleLimit(const double3& mnsl)
	{
		fprintf(mFile,"\tsetAttr \".mnsl\" -type \"double3\" ");
		mnsl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinScaleXLimit(double msxl)
	{
		if(msxl == -1) return;
		fprintf(mFile,"\tsetAttr \".mnsl.msxl\" %f;\n", msxl);
	}
	void setMinScaleYLimit(double msyl)
	{
		if(msyl == -1) return;
		fprintf(mFile,"\tsetAttr \".mnsl.msyl\" %f;\n", msyl);
	}
	void setMinScaleZLimit(double mszl)
	{
		if(mszl == -1) return;
		fprintf(mFile,"\tsetAttr \".mnsl.mszl\" %f;\n", mszl);
	}
	void setMaxScaleLimit(const double3& mxsl)
	{
		fprintf(mFile,"\tsetAttr \".mxsl\" -type \"double3\" ");
		mxsl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxScaleXLimit(double xsxl)
	{
		if(xsxl == 1) return;
		fprintf(mFile,"\tsetAttr \".mxsl.xsxl\" %f;\n", xsxl);
	}
	void setMaxScaleYLimit(double xsyl)
	{
		if(xsyl == 1) return;
		fprintf(mFile,"\tsetAttr \".mxsl.xsyl\" %f;\n", xsyl);
	}
	void setMaxScaleZLimit(double xszl)
	{
		if(xszl == 1) return;
		fprintf(mFile,"\tsetAttr \".mxsl.xszl\" %f;\n", xszl);
	}
	void setMinScaleLimitEnable(const MinScaleLimitEnable& msle)
	{
		fprintf(mFile,"\tsetAttr \".msle\" ");
		msle.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinScaleXLimitEnable(bool msxe)
	{
		if(msxe == false) return;
		fprintf(mFile,"\tsetAttr \".msle.msxe\" %i;\n", msxe);
	}
	void setMinScaleYLimitEnable(bool msye)
	{
		if(msye == false) return;
		fprintf(mFile,"\tsetAttr \".msle.msye\" %i;\n", msye);
	}
	void setMinScaleZLimitEnable(bool msze)
	{
		if(msze == false) return;
		fprintf(mFile,"\tsetAttr \".msle.msze\" %i;\n", msze);
	}
	void setMaxScaleLimitEnable(const MaxScaleLimitEnable& xsle)
	{
		fprintf(mFile,"\tsetAttr \".xsle\" ");
		xsle.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxScaleXLimitEnable(bool xsxe)
	{
		if(xsxe == false) return;
		fprintf(mFile,"\tsetAttr \".xsle.xsxe\" %i;\n", xsxe);
	}
	void setMaxScaleYLimitEnable(bool xsye)
	{
		if(xsye == false) return;
		fprintf(mFile,"\tsetAttr \".xsle.xsye\" %i;\n", xsye);
	}
	void setMaxScaleZLimitEnable(bool xsze)
	{
		if(xsze == false) return;
		fprintf(mFile,"\tsetAttr \".xsle.xsze\" %i;\n", xsze);
	}
	void setSelectHandle(const double3& hdl)
	{
		fprintf(mFile,"\tsetAttr \".hdl\" -type \"double3\" ");
		hdl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSelectHandleX(double hdlx)
	{
		if(hdlx == 0) return;
		fprintf(mFile,"\tsetAttr \".hdl.hdlx\" %f;\n", hdlx);
	}
	void setSelectHandleY(double hdly)
	{
		if(hdly == 0) return;
		fprintf(mFile,"\tsetAttr \".hdl.hdly\" %f;\n", hdly);
	}
	void setSelectHandleZ(double hdlz)
	{
		if(hdlz == 0) return;
		fprintf(mFile,"\tsetAttr \".hdl.hdlz\" %f;\n", hdlz);
	}
	void setInheritsTransform(bool it)
	{
		if(it == true) return;
		fprintf(mFile,"\tsetAttr \".it\" %i;\n", it);
	}
	void setDisplayHandle(bool dh)
	{
		if(dh == false) return;
		fprintf(mFile,"\tsetAttr \".dh\" %i;\n", dh);
	}
	void setDisplayScalePivot(bool dsp)
	{
		if(dsp == false) return;
		fprintf(mFile,"\tsetAttr \".dsp\" %i;\n", dsp);
	}
	void setDisplayRotatePivot(bool drp)
	{
		if(drp == false) return;
		fprintf(mFile,"\tsetAttr \".drp\" %i;\n", drp);
	}
	void setDisplayLocalAxis(bool dla)
	{
		if(dla == false) return;
		fprintf(mFile,"\tsetAttr \".dla\" %i;\n", dla);
	}
	void setShowManipDefault(unsigned int smd)
	{
		if(smd == 0) return;
		fprintf(mFile,"\tsetAttr \".smd\" %i;\n", smd);
	}
	void setRotateQuaternion(const double4& rq)
	{
		fprintf(mFile,"\tsetAttr \".rq\" -type \"double4\" ");
		rq.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRotateQuaternionX(double rqx)
	{
		if(rqx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rq.rqx\" %f;\n", rqx);
	}
	void setRotateQuaternionY(double rqy)
	{
		if(rqy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rq.rqy\" %f;\n", rqy);
	}
	void setRotateQuaternionZ(double rqz)
	{
		if(rqz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rq.rqz\" %f;\n", rqz);
	}
	void setRotateQuaternionW(double rqw)
	{
		if(rqw == 0.0) return;
		fprintf(mFile,"\tsetAttr \".rq.rqw\" %f;\n", rqw);
	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"\tsetAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiDeriveFromMaya(bool dfm)
	{
		if(dfm == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.dfm\" %i;\n", dfm);
	}
	void setMiHide(bool hde)
	{
		if(hde == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.hde\" %i;\n", hde);
	}
	void setMiVisible(unsigned int vsb)
	{
		if(vsb == 2) return;
		fprintf(mFile,"\tsetAttr \".mrc.vsb\" %i;\n", vsb);
	}
	void setMiTrace(unsigned int trc)
	{
		if(trc == 2) return;
		fprintf(mFile,"\tsetAttr \".mrc.trc\" %i;\n", trc);
	}
	void setMiShadow(unsigned int shd)
	{
		if(shd == 2) return;
		fprintf(mFile,"\tsetAttr \".mrc.shd\" %i;\n", shd);
	}
	void setMiCaustic(unsigned int cst)
	{
		if(cst == 5) return;
		fprintf(mFile,"\tsetAttr \".mrc.cst\" %i;\n", cst);
	}
	void setMiGlobillum(unsigned int glb)
	{
		if(glb == 5) return;
		fprintf(mFile,"\tsetAttr \".mrc.glb\" %i;\n", glb);
	}
	void setMiExportGeoShader(bool mieg)
	{
		if(mieg == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.mieg\" %i;\n", mieg);
	}
	void getTranslate()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getTranslateX()const
	{
		fprintf(mFile,"\"%s.t.tx\"",mName.c_str());
	}
	void getTranslateY()const
	{
		fprintf(mFile,"\"%s.t.ty\"",mName.c_str());
	}
	void getTranslateZ()const
	{
		fprintf(mFile,"\"%s.t.tz\"",mName.c_str());
	}
	void getRotate()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getRotateX()const
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());
	}
	void getRotateY()const
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());
	}
	void getRotateZ()const
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());
	}
	void getRotateOrder()const
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());
	}
	void getScale()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getScaleX()const
	{
		fprintf(mFile,"\"%s.s.sx\"",mName.c_str());
	}
	void getScaleY()const
	{
		fprintf(mFile,"\"%s.s.sy\"",mName.c_str());
	}
	void getScaleZ()const
	{
		fprintf(mFile,"\"%s.s.sz\"",mName.c_str());
	}
	void getShear()const
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());
	}
	void getShearXY()const
	{
		fprintf(mFile,"\"%s.sh.shxy\"",mName.c_str());
	}
	void getShearXZ()const
	{
		fprintf(mFile,"\"%s.sh.shxz\"",mName.c_str());
	}
	void getShearYZ()const
	{
		fprintf(mFile,"\"%s.sh.shyz\"",mName.c_str());
	}
	void getRotatePivot()const
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());
	}
	void getRotatePivotX()const
	{
		fprintf(mFile,"\"%s.rp.rpx\"",mName.c_str());
	}
	void getRotatePivotY()const
	{
		fprintf(mFile,"\"%s.rp.rpy\"",mName.c_str());
	}
	void getRotatePivotZ()const
	{
		fprintf(mFile,"\"%s.rp.rpz\"",mName.c_str());
	}
	void getRotatePivotTranslate()const
	{
		fprintf(mFile,"\"%s.rpt\"",mName.c_str());
	}
	void getRotatePivotTranslateX()const
	{
		fprintf(mFile,"\"%s.rpt.rptx\"",mName.c_str());
	}
	void getRotatePivotTranslateY()const
	{
		fprintf(mFile,"\"%s.rpt.rpty\"",mName.c_str());
	}
	void getRotatePivotTranslateZ()const
	{
		fprintf(mFile,"\"%s.rpt.rptz\"",mName.c_str());
	}
	void getScalePivot()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getScalePivotX()const
	{
		fprintf(mFile,"\"%s.sp.spx\"",mName.c_str());
	}
	void getScalePivotY()const
	{
		fprintf(mFile,"\"%s.sp.spy\"",mName.c_str());
	}
	void getScalePivotZ()const
	{
		fprintf(mFile,"\"%s.sp.spz\"",mName.c_str());
	}
	void getScalePivotTranslate()const
	{
		fprintf(mFile,"\"%s.spt\"",mName.c_str());
	}
	void getScalePivotTranslateX()const
	{
		fprintf(mFile,"\"%s.spt.sptx\"",mName.c_str());
	}
	void getScalePivotTranslateY()const
	{
		fprintf(mFile,"\"%s.spt.spty\"",mName.c_str());
	}
	void getScalePivotTranslateZ()const
	{
		fprintf(mFile,"\"%s.spt.sptz\"",mName.c_str());
	}
	void getRotateAxis()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getRotateAxisX()const
	{
		fprintf(mFile,"\"%s.ra.rax\"",mName.c_str());
	}
	void getRotateAxisY()const
	{
		fprintf(mFile,"\"%s.ra.ray\"",mName.c_str());
	}
	void getRotateAxisZ()const
	{
		fprintf(mFile,"\"%s.ra.raz\"",mName.c_str());
	}
	void getTransMinusRotatePivot()const
	{
		fprintf(mFile,"\"%s.tmrp\"",mName.c_str());
	}
	void getTransMinusRotatePivotX()const
	{
		fprintf(mFile,"\"%s.tmrp.tmrx\"",mName.c_str());
	}
	void getTransMinusRotatePivotY()const
	{
		fprintf(mFile,"\"%s.tmrp.tmry\"",mName.c_str());
	}
	void getTransMinusRotatePivotZ()const
	{
		fprintf(mFile,"\"%s.tmrp.tmrz\"",mName.c_str());
	}
	void getGeometry()const
	{
		fprintf(mFile,"\"%s.g\"",mName.c_str());
	}
	void getXformMatrix()const
	{
		fprintf(mFile,"\"%s.xm\"",mName.c_str());
	}
	void getSelectHandle()const
	{
		fprintf(mFile,"\"%s.hdl\"",mName.c_str());
	}
	void getSelectHandleX()const
	{
		fprintf(mFile,"\"%s.hdl.hdlx\"",mName.c_str());
	}
	void getSelectHandleY()const
	{
		fprintf(mFile,"\"%s.hdl.hdly\"",mName.c_str());
	}
	void getSelectHandleZ()const
	{
		fprintf(mFile,"\"%s.hdl.hdlz\"",mName.c_str());
	}
	void getInheritsTransform()const
	{
		fprintf(mFile,"\"%s.it\"",mName.c_str());
	}
	void getDisplayHandle()const
	{
		fprintf(mFile,"\"%s.dh\"",mName.c_str());
	}
	void getDisplayScalePivot()const
	{
		fprintf(mFile,"\"%s.dsp\"",mName.c_str());
	}
	void getDisplayRotatePivot()const
	{
		fprintf(mFile,"\"%s.drp\"",mName.c_str());
	}
	void getDisplayLocalAxis()const
	{
		fprintf(mFile,"\"%s.dla\"",mName.c_str());
	}
	void getDynamics()const
	{
		fprintf(mFile,"\"%s.dyn\"",mName.c_str());
	}
	void getShowManipDefault()const
	{
		fprintf(mFile,"\"%s.smd\"",mName.c_str());
	}
	void getSpecifiedManipLocation()const
	{
		fprintf(mFile,"\"%s.sml\"",mName.c_str());
	}
	void getRotateQuaternion()const
	{
		fprintf(mFile,"\"%s.rq\"",mName.c_str());
	}
	void getRotateQuaternionX()const
	{
		fprintf(mFile,"\"%s.rq.rqx\"",mName.c_str());
	}
	void getRotateQuaternionY()const
	{
		fprintf(mFile,"\"%s.rq.rqy\"",mName.c_str());
	}
	void getRotateQuaternionZ()const
	{
		fprintf(mFile,"\"%s.rq.rqz\"",mName.c_str());
	}
	void getRotateQuaternionW()const
	{
		fprintf(mFile,"\"%s.rq.rqw\"",mName.c_str());
	}
	void getRotationInterpolation()const
	{
		fprintf(mFile,"\"%s.roi\"",mName.c_str());
	}
	void getMentalRayControls()const
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());
	}
	void getMiDeriveFromMaya()const
	{
		fprintf(mFile,"\"%s.mrc.dfm\"",mName.c_str());
	}
	void getMiHide()const
	{
		fprintf(mFile,"\"%s.mrc.hde\"",mName.c_str());
	}
	void getMiVisible()const
	{
		fprintf(mFile,"\"%s.mrc.vsb\"",mName.c_str());
	}
	void getMiTrace()const
	{
		fprintf(mFile,"\"%s.mrc.trc\"",mName.c_str());
	}
	void getMiShadow()const
	{
		fprintf(mFile,"\"%s.mrc.shd\"",mName.c_str());
	}
	void getMiCaustic()const
	{
		fprintf(mFile,"\"%s.mrc.cst\"",mName.c_str());
	}
	void getMiGlobillum()const
	{
		fprintf(mFile,"\"%s.mrc.glb\"",mName.c_str());
	}
	void getMiExportGeoShader()const
	{
		fprintf(mFile,"\"%s.mrc.mieg\"",mName.c_str());
	}
	void getMiGeoShader()const
	{
		fprintf(mFile,"\"%s.mrc.migs\"",mName.c_str());
	}
protected:
	Transform(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DagNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_TRANSFORM_H__
