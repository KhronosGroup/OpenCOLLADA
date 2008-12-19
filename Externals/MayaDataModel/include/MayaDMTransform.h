/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Transform(FILE* file,const std::string& name,const std::string& parent=""):DagNode(file, name, parent, "transform"){}
	virtual ~Transform(){}
	void setTranslate(const double3& t)
	{
		fprintf(mFile,"setAttr \".t\" -type \"double3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTranslateX(double tx)
	{
		if(tx == 0) return;
		fprintf(mFile,"setAttr \".t.tx\" %f;\n", tx);

	}
	void setTranslateY(double ty)
	{
		if(ty == 0) return;
		fprintf(mFile,"setAttr \".t.ty\" %f;\n", ty);

	}
	void setTranslateZ(double tz)
	{
		if(tz == 0) return;
		fprintf(mFile,"setAttr \".t.tz\" %f;\n", tz);

	}
	void setRotate(const double3& r)
	{
		fprintf(mFile,"setAttr \".r\" -type \"double3\" ");
		r.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRotateX(double rx)
	{
		if(rx == 0) return;
		fprintf(mFile,"setAttr \".r.rx\" %f;\n", rx);

	}
	void setRotateY(double ry)
	{
		if(ry == 0) return;
		fprintf(mFile,"setAttr \".r.ry\" %f;\n", ry);

	}
	void setRotateZ(double rz)
	{
		if(rz == 0) return;
		fprintf(mFile,"setAttr \".r.rz\" %f;\n", rz);

	}
	void setRotateOrder(unsigned int ro)
	{
		if(ro == 0) return;
		fprintf(mFile,"setAttr \".ro\" %i;\n", ro);

	}
	void setScale(const double3& s)
	{
		fprintf(mFile,"setAttr \".s\" -type \"double3\" ");
		s.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScaleX(double sx)
	{
		if(sx == 1.0) return;
		fprintf(mFile,"setAttr \".s.sx\" %f;\n", sx);

	}
	void setScaleY(double sy)
	{
		if(sy == 1.0) return;
		fprintf(mFile,"setAttr \".s.sy\" %f;\n", sy);

	}
	void setScaleZ(double sz)
	{
		if(sz == 1.0) return;
		fprintf(mFile,"setAttr \".s.sz\" %f;\n", sz);

	}
	void setShear(const double3& sh)
	{
		fprintf(mFile,"setAttr \".sh\" -type \"double3\" ");
		sh.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShearXY(double shxy)
	{
		if(shxy == 0.0) return;
		fprintf(mFile,"setAttr \".sh.shxy\" %f;\n", shxy);

	}
	void setShearXZ(double shxz)
	{
		if(shxz == 0.0) return;
		fprintf(mFile,"setAttr \".sh.shxz\" %f;\n", shxz);

	}
	void setShearYZ(double shyz)
	{
		if(shyz == 0.0) return;
		fprintf(mFile,"setAttr \".sh.shyz\" %f;\n", shyz);

	}
	void setRotatePivot(const double3& rp)
	{
		fprintf(mFile,"setAttr \".rp\" -type \"double3\" ");
		rp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRotatePivotX(double rpx)
	{
		if(rpx == 0) return;
		fprintf(mFile,"setAttr \".rp.rpx\" %f;\n", rpx);

	}
	void setRotatePivotY(double rpy)
	{
		if(rpy == 0) return;
		fprintf(mFile,"setAttr \".rp.rpy\" %f;\n", rpy);

	}
	void setRotatePivotZ(double rpz)
	{
		if(rpz == 0) return;
		fprintf(mFile,"setAttr \".rp.rpz\" %f;\n", rpz);

	}
	void setRotatePivotTranslate(const double3& rpt)
	{
		fprintf(mFile,"setAttr \".rpt\" -type \"double3\" ");
		rpt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRotatePivotTranslateX(double rptx)
	{
		if(rptx == 0) return;
		fprintf(mFile,"setAttr \".rpt.rptx\" %f;\n", rptx);

	}
	void setRotatePivotTranslateY(double rpty)
	{
		if(rpty == 0) return;
		fprintf(mFile,"setAttr \".rpt.rpty\" %f;\n", rpty);

	}
	void setRotatePivotTranslateZ(double rptz)
	{
		if(rptz == 0) return;
		fprintf(mFile,"setAttr \".rpt.rptz\" %f;\n", rptz);

	}
	void setScalePivot(const double3& sp)
	{
		fprintf(mFile,"setAttr \".sp\" -type \"double3\" ");
		sp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScalePivotX(double spx)
	{
		if(spx == 0) return;
		fprintf(mFile,"setAttr \".sp.spx\" %f;\n", spx);

	}
	void setScalePivotY(double spy)
	{
		if(spy == 0) return;
		fprintf(mFile,"setAttr \".sp.spy\" %f;\n", spy);

	}
	void setScalePivotZ(double spz)
	{
		if(spz == 0) return;
		fprintf(mFile,"setAttr \".sp.spz\" %f;\n", spz);

	}
	void setScalePivotTranslate(const double3& spt)
	{
		fprintf(mFile,"setAttr \".spt\" -type \"double3\" ");
		spt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setScalePivotTranslateX(double sptx)
	{
		if(sptx == 0) return;
		fprintf(mFile,"setAttr \".spt.sptx\" %f;\n", sptx);

	}
	void setScalePivotTranslateY(double spty)
	{
		if(spty == 0) return;
		fprintf(mFile,"setAttr \".spt.spty\" %f;\n", spty);

	}
	void setScalePivotTranslateZ(double sptz)
	{
		if(sptz == 0) return;
		fprintf(mFile,"setAttr \".spt.sptz\" %f;\n", sptz);

	}
	void setRotateAxis(const double3& ra)
	{
		fprintf(mFile,"setAttr \".ra\" -type \"double3\" ");
		ra.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRotateAxisX(double rax)
	{
		if(rax == 0) return;
		fprintf(mFile,"setAttr \".ra.rax\" %f;\n", rax);

	}
	void setRotateAxisY(double ray)
	{
		if(ray == 0) return;
		fprintf(mFile,"setAttr \".ra.ray\" %f;\n", ray);

	}
	void setRotateAxisZ(double raz)
	{
		if(raz == 0) return;
		fprintf(mFile,"setAttr \".ra.raz\" %f;\n", raz);

	}
	void setMinTransLimit(const double3& mntl)
	{
		fprintf(mFile,"setAttr \".mntl\" -type \"double3\" ");
		mntl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinTransXLimit(double mtxl)
	{
		if(mtxl == 1) return;
		fprintf(mFile,"setAttr \".mntl.mtxl\" %f;\n", mtxl);

	}
	void setMinTransYLimit(double mtyl)
	{
		if(mtyl == 1) return;
		fprintf(mFile,"setAttr \".mntl.mtyl\" %f;\n", mtyl);

	}
	void setMinTransZLimit(double mtzl)
	{
		if(mtzl == 1) return;
		fprintf(mFile,"setAttr \".mntl.mtzl\" %f;\n", mtzl);

	}
	void setMaxTransLimit(const double3& mxtl)
	{
		fprintf(mFile,"setAttr \".mxtl\" -type \"double3\" ");
		mxtl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxTransXLimit(double xtxl)
	{
		if(xtxl == 1) return;
		fprintf(mFile,"setAttr \".mxtl.xtxl\" %f;\n", xtxl);

	}
	void setMaxTransYLimit(double xtyl)
	{
		if(xtyl == 1) return;
		fprintf(mFile,"setAttr \".mxtl.xtyl\" %f;\n", xtyl);

	}
	void setMaxTransZLimit(double xtzl)
	{
		if(xtzl == 1) return;
		fprintf(mFile,"setAttr \".mxtl.xtzl\" %f;\n", xtzl);

	}
	void setMinTransLimitEnable(const MinTransLimitEnable& mtle)
	{
		fprintf(mFile,"setAttr \".mtle\" ");
		mtle.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinTransXLimitEnable(bool mtxe)
	{
		if(mtxe == false) return;
		fprintf(mFile,"setAttr \".mtle.mtxe\" %i;\n", mtxe);

	}
	void setMinTransYLimitEnable(bool mtye)
	{
		if(mtye == false) return;
		fprintf(mFile,"setAttr \".mtle.mtye\" %i;\n", mtye);

	}
	void setMinTransZLimitEnable(bool mtze)
	{
		if(mtze == false) return;
		fprintf(mFile,"setAttr \".mtle.mtze\" %i;\n", mtze);

	}
	void setMaxTransLimitEnable(const MaxTransLimitEnable& xtle)
	{
		fprintf(mFile,"setAttr \".xtle\" ");
		xtle.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxTransXLimitEnable(bool xtxe)
	{
		if(xtxe == false) return;
		fprintf(mFile,"setAttr \".xtle.xtxe\" %i;\n", xtxe);

	}
	void setMaxTransYLimitEnable(bool xtye)
	{
		if(xtye == false) return;
		fprintf(mFile,"setAttr \".xtle.xtye\" %i;\n", xtye);

	}
	void setMaxTransZLimitEnable(bool xtze)
	{
		if(xtze == false) return;
		fprintf(mFile,"setAttr \".xtle.xtze\" %i;\n", xtze);

	}
	void setMinRotLimit(const double3& mnrl)
	{
		fprintf(mFile,"setAttr \".mnrl\" -type \"double3\" ");
		mnrl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinRotXLimit(double mrxl)
	{
		if(mrxl == 4) return;
		fprintf(mFile,"setAttr \".mnrl.mrxl\" %f;\n", mrxl);

	}
	void setMinRotYLimit(double mryl)
	{
		if(mryl == 4) return;
		fprintf(mFile,"setAttr \".mnrl.mryl\" %f;\n", mryl);

	}
	void setMinRotZLimit(double mrzl)
	{
		if(mrzl == 4) return;
		fprintf(mFile,"setAttr \".mnrl.mrzl\" %f;\n", mrzl);

	}
	void setMaxRotLimit(const double3& mxrl)
	{
		fprintf(mFile,"setAttr \".mxrl\" -type \"double3\" ");
		mxrl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxRotXLimit(double xrxl)
	{
		if(xrxl == 4) return;
		fprintf(mFile,"setAttr \".mxrl.xrxl\" %f;\n", xrxl);

	}
	void setMaxRotYLimit(double xryl)
	{
		if(xryl == 4) return;
		fprintf(mFile,"setAttr \".mxrl.xryl\" %f;\n", xryl);

	}
	void setMaxRotZLimit(double xrzl)
	{
		if(xrzl == 4) return;
		fprintf(mFile,"setAttr \".mxrl.xrzl\" %f;\n", xrzl);

	}
	void setMinRotLimitEnable(const MinRotLimitEnable& mrle)
	{
		fprintf(mFile,"setAttr \".mrle\" ");
		mrle.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinRotXLimitEnable(bool mrxe)
	{
		if(mrxe == false) return;
		fprintf(mFile,"setAttr \".mrle.mrxe\" %i;\n", mrxe);

	}
	void setMinRotYLimitEnable(bool mrye)
	{
		if(mrye == false) return;
		fprintf(mFile,"setAttr \".mrle.mrye\" %i;\n", mrye);

	}
	void setMinRotZLimitEnable(bool mrze)
	{
		if(mrze == false) return;
		fprintf(mFile,"setAttr \".mrle.mrze\" %i;\n", mrze);

	}
	void setMaxRotLimitEnable(const MaxRotLimitEnable& xrle)
	{
		fprintf(mFile,"setAttr \".xrle\" ");
		xrle.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxRotXLimitEnable(bool xrxe)
	{
		if(xrxe == false) return;
		fprintf(mFile,"setAttr \".xrle.xrxe\" %i;\n", xrxe);

	}
	void setMaxRotYLimitEnable(bool xrye)
	{
		if(xrye == false) return;
		fprintf(mFile,"setAttr \".xrle.xrye\" %i;\n", xrye);

	}
	void setMaxRotZLimitEnable(bool xrze)
	{
		if(xrze == false) return;
		fprintf(mFile,"setAttr \".xrle.xrze\" %i;\n", xrze);

	}
	void setMinScaleLimit(const double3& mnsl)
	{
		fprintf(mFile,"setAttr \".mnsl\" -type \"double3\" ");
		mnsl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinScaleXLimit(double msxl)
	{
		if(msxl == -1) return;
		fprintf(mFile,"setAttr \".mnsl.msxl\" %f;\n", msxl);

	}
	void setMinScaleYLimit(double msyl)
	{
		if(msyl == -1) return;
		fprintf(mFile,"setAttr \".mnsl.msyl\" %f;\n", msyl);

	}
	void setMinScaleZLimit(double mszl)
	{
		if(mszl == -1) return;
		fprintf(mFile,"setAttr \".mnsl.mszl\" %f;\n", mszl);

	}
	void setMaxScaleLimit(const double3& mxsl)
	{
		fprintf(mFile,"setAttr \".mxsl\" -type \"double3\" ");
		mxsl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxScaleXLimit(double xsxl)
	{
		if(xsxl == 1) return;
		fprintf(mFile,"setAttr \".mxsl.xsxl\" %f;\n", xsxl);

	}
	void setMaxScaleYLimit(double xsyl)
	{
		if(xsyl == 1) return;
		fprintf(mFile,"setAttr \".mxsl.xsyl\" %f;\n", xsyl);

	}
	void setMaxScaleZLimit(double xszl)
	{
		if(xszl == 1) return;
		fprintf(mFile,"setAttr \".mxsl.xszl\" %f;\n", xszl);

	}
	void setMinScaleLimitEnable(const MinScaleLimitEnable& msle)
	{
		fprintf(mFile,"setAttr \".msle\" ");
		msle.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinScaleXLimitEnable(bool msxe)
	{
		if(msxe == false) return;
		fprintf(mFile,"setAttr \".msle.msxe\" %i;\n", msxe);

	}
	void setMinScaleYLimitEnable(bool msye)
	{
		if(msye == false) return;
		fprintf(mFile,"setAttr \".msle.msye\" %i;\n", msye);

	}
	void setMinScaleZLimitEnable(bool msze)
	{
		if(msze == false) return;
		fprintf(mFile,"setAttr \".msle.msze\" %i;\n", msze);

	}
	void setMaxScaleLimitEnable(const MaxScaleLimitEnable& xsle)
	{
		fprintf(mFile,"setAttr \".xsle\" ");
		xsle.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxScaleXLimitEnable(bool xsxe)
	{
		if(xsxe == false) return;
		fprintf(mFile,"setAttr \".xsle.xsxe\" %i;\n", xsxe);

	}
	void setMaxScaleYLimitEnable(bool xsye)
	{
		if(xsye == false) return;
		fprintf(mFile,"setAttr \".xsle.xsye\" %i;\n", xsye);

	}
	void setMaxScaleZLimitEnable(bool xsze)
	{
		if(xsze == false) return;
		fprintf(mFile,"setAttr \".xsle.xsze\" %i;\n", xsze);

	}
	void setSelectHandle(const double3& hdl)
	{
		fprintf(mFile,"setAttr \".hdl\" -type \"double3\" ");
		hdl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSelectHandleX(double hdlx)
	{
		if(hdlx == 0) return;
		fprintf(mFile,"setAttr \".hdl.hdlx\" %f;\n", hdlx);

	}
	void setSelectHandleY(double hdly)
	{
		if(hdly == 0) return;
		fprintf(mFile,"setAttr \".hdl.hdly\" %f;\n", hdly);

	}
	void setSelectHandleZ(double hdlz)
	{
		if(hdlz == 0) return;
		fprintf(mFile,"setAttr \".hdl.hdlz\" %f;\n", hdlz);

	}
	void setInheritsTransform(bool it)
	{
		if(it == true) return;
		fprintf(mFile,"setAttr \".it\" %i;\n", it);

	}
	void setDisplayHandle(bool dh)
	{
		if(dh == false) return;
		fprintf(mFile,"setAttr \".dh\" %i;\n", dh);

	}
	void setDisplayScalePivot(bool dsp)
	{
		if(dsp == false) return;
		fprintf(mFile,"setAttr \".dsp\" %i;\n", dsp);

	}
	void setDisplayRotatePivot(bool drp)
	{
		if(drp == false) return;
		fprintf(mFile,"setAttr \".drp\" %i;\n", drp);

	}
	void setDisplayLocalAxis(bool dla)
	{
		if(dla == false) return;
		fprintf(mFile,"setAttr \".dla\" %i;\n", dla);

	}
	void setShowManipDefault(unsigned int smd)
	{
		if(smd == 0) return;
		fprintf(mFile,"setAttr \".smd\" %i;\n", smd);

	}
	void setRotateQuaternion(const double4& rq)
	{
		fprintf(mFile,"setAttr \".rq\" -type \"double4\" ");
		rq.write(mFile);
		fprintf(mFile,";\n");

	}
	void setRotateQuaternionX(double rqx)
	{
		if(rqx == 0.0) return;
		fprintf(mFile,"setAttr \".rq.rqx\" %f;\n", rqx);

	}
	void setRotateQuaternionY(double rqy)
	{
		if(rqy == 0.0) return;
		fprintf(mFile,"setAttr \".rq.rqy\" %f;\n", rqy);

	}
	void setRotateQuaternionZ(double rqz)
	{
		if(rqz == 0.0) return;
		fprintf(mFile,"setAttr \".rq.rqz\" %f;\n", rqz);

	}
	void setRotateQuaternionW(double rqw)
	{
		if(rqw == 0.0) return;
		fprintf(mFile,"setAttr \".rq.rqw\" %f;\n", rqw);

	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"setAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiDeriveFromMaya(bool dfm)
	{
		if(dfm == true) return;
		fprintf(mFile,"setAttr \".mrc.dfm\" %i;\n", dfm);

	}
	void setMiHide(bool hde)
	{
		if(hde == false) return;
		fprintf(mFile,"setAttr \".mrc.hde\" %i;\n", hde);

	}
	void setMiVisible(unsigned int vsb)
	{
		if(vsb == 2) return;
		fprintf(mFile,"setAttr \".mrc.vsb\" %i;\n", vsb);

	}
	void setMiTrace(unsigned int trc)
	{
		if(trc == 2) return;
		fprintf(mFile,"setAttr \".mrc.trc\" %i;\n", trc);

	}
	void setMiShadow(unsigned int shd)
	{
		if(shd == 2) return;
		fprintf(mFile,"setAttr \".mrc.shd\" %i;\n", shd);

	}
	void setMiCaustic(unsigned int cst)
	{
		if(cst == 5) return;
		fprintf(mFile,"setAttr \".mrc.cst\" %i;\n", cst);

	}
	void setMiGlobillum(unsigned int glb)
	{
		if(glb == 5) return;
		fprintf(mFile,"setAttr \".mrc.glb\" %i;\n", glb);

	}
	void setMiExportGeoShader(bool mieg)
	{
		if(mieg == false) return;
		fprintf(mFile,"setAttr \".mrc.mieg\" %i;\n", mieg);

	}
	void getTranslate()
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());

	}
	void getTranslateX()
	{
		fprintf(mFile,"\"%s.t.tx\"",mName.c_str());

	}
	void getTranslateY()
	{
		fprintf(mFile,"\"%s.t.ty\"",mName.c_str());

	}
	void getTranslateZ()
	{
		fprintf(mFile,"\"%s.t.tz\"",mName.c_str());

	}
	void getRotate()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getRotateX()
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());

	}
	void getRotateY()
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());

	}
	void getRotateZ()
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());

	}
	void getRotateOrder()
	{
		fprintf(mFile,"\"%s.ro\"",mName.c_str());

	}
	void getScale()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getScaleX()
	{
		fprintf(mFile,"\"%s.s.sx\"",mName.c_str());

	}
	void getScaleY()
	{
		fprintf(mFile,"\"%s.s.sy\"",mName.c_str());

	}
	void getScaleZ()
	{
		fprintf(mFile,"\"%s.s.sz\"",mName.c_str());

	}
	void getShear()
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());

	}
	void getShearXY()
	{
		fprintf(mFile,"\"%s.sh.shxy\"",mName.c_str());

	}
	void getShearXZ()
	{
		fprintf(mFile,"\"%s.sh.shxz\"",mName.c_str());

	}
	void getShearYZ()
	{
		fprintf(mFile,"\"%s.sh.shyz\"",mName.c_str());

	}
	void getRotatePivot()
	{
		fprintf(mFile,"\"%s.rp\"",mName.c_str());

	}
	void getRotatePivotX()
	{
		fprintf(mFile,"\"%s.rp.rpx\"",mName.c_str());

	}
	void getRotatePivotY()
	{
		fprintf(mFile,"\"%s.rp.rpy\"",mName.c_str());

	}
	void getRotatePivotZ()
	{
		fprintf(mFile,"\"%s.rp.rpz\"",mName.c_str());

	}
	void getRotatePivotTranslate()
	{
		fprintf(mFile,"\"%s.rpt\"",mName.c_str());

	}
	void getRotatePivotTranslateX()
	{
		fprintf(mFile,"\"%s.rpt.rptx\"",mName.c_str());

	}
	void getRotatePivotTranslateY()
	{
		fprintf(mFile,"\"%s.rpt.rpty\"",mName.c_str());

	}
	void getRotatePivotTranslateZ()
	{
		fprintf(mFile,"\"%s.rpt.rptz\"",mName.c_str());

	}
	void getScalePivot()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getScalePivotX()
	{
		fprintf(mFile,"\"%s.sp.spx\"",mName.c_str());

	}
	void getScalePivotY()
	{
		fprintf(mFile,"\"%s.sp.spy\"",mName.c_str());

	}
	void getScalePivotZ()
	{
		fprintf(mFile,"\"%s.sp.spz\"",mName.c_str());

	}
	void getScalePivotTranslate()
	{
		fprintf(mFile,"\"%s.spt\"",mName.c_str());

	}
	void getScalePivotTranslateX()
	{
		fprintf(mFile,"\"%s.spt.sptx\"",mName.c_str());

	}
	void getScalePivotTranslateY()
	{
		fprintf(mFile,"\"%s.spt.spty\"",mName.c_str());

	}
	void getScalePivotTranslateZ()
	{
		fprintf(mFile,"\"%s.spt.sptz\"",mName.c_str());

	}
	void getRotateAxis()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
	void getRotateAxisX()
	{
		fprintf(mFile,"\"%s.ra.rax\"",mName.c_str());

	}
	void getRotateAxisY()
	{
		fprintf(mFile,"\"%s.ra.ray\"",mName.c_str());

	}
	void getRotateAxisZ()
	{
		fprintf(mFile,"\"%s.ra.raz\"",mName.c_str());

	}
	void getTransMinusRotatePivot()
	{
		fprintf(mFile,"\"%s.tmrp\"",mName.c_str());

	}
	void getTransMinusRotatePivotX()
	{
		fprintf(mFile,"\"%s.tmrp.tmrx\"",mName.c_str());

	}
	void getTransMinusRotatePivotY()
	{
		fprintf(mFile,"\"%s.tmrp.tmry\"",mName.c_str());

	}
	void getTransMinusRotatePivotZ()
	{
		fprintf(mFile,"\"%s.tmrp.tmrz\"",mName.c_str());

	}
	void getXformMatrix()
	{
		fprintf(mFile,"\"%s.xm\"",mName.c_str());

	}
	void getSelectHandle()
	{
		fprintf(mFile,"\"%s.hdl\"",mName.c_str());

	}
	void getSelectHandleX()
	{
		fprintf(mFile,"\"%s.hdl.hdlx\"",mName.c_str());

	}
	void getSelectHandleY()
	{
		fprintf(mFile,"\"%s.hdl.hdly\"",mName.c_str());

	}
	void getSelectHandleZ()
	{
		fprintf(mFile,"\"%s.hdl.hdlz\"",mName.c_str());

	}
	void getInheritsTransform()
	{
		fprintf(mFile,"\"%s.it\"",mName.c_str());

	}
	void getDisplayHandle()
	{
		fprintf(mFile,"\"%s.dh\"",mName.c_str());

	}
	void getDisplayScalePivot()
	{
		fprintf(mFile,"\"%s.dsp\"",mName.c_str());

	}
	void getDisplayRotatePivot()
	{
		fprintf(mFile,"\"%s.drp\"",mName.c_str());

	}
	void getDisplayLocalAxis()
	{
		fprintf(mFile,"\"%s.dla\"",mName.c_str());

	}
	void getShowManipDefault()
	{
		fprintf(mFile,"\"%s.smd\"",mName.c_str());

	}
	void getRotateQuaternion()
	{
		fprintf(mFile,"\"%s.rq\"",mName.c_str());

	}
	void getRotateQuaternionX()
	{
		fprintf(mFile,"\"%s.rq.rqx\"",mName.c_str());

	}
	void getRotateQuaternionY()
	{
		fprintf(mFile,"\"%s.rq.rqy\"",mName.c_str());

	}
	void getRotateQuaternionZ()
	{
		fprintf(mFile,"\"%s.rq.rqz\"",mName.c_str());

	}
	void getRotateQuaternionW()
	{
		fprintf(mFile,"\"%s.rq.rqw\"",mName.c_str());

	}
	void getRotationInterpolation()
	{
		fprintf(mFile,"\"%s.roi\"",mName.c_str());

	}
	void getMentalRayControls()
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());

	}
	void getMiDeriveFromMaya()
	{
		fprintf(mFile,"\"%s.mrc.dfm\"",mName.c_str());

	}
	void getMiHide()
	{
		fprintf(mFile,"\"%s.mrc.hde\"",mName.c_str());

	}
	void getMiVisible()
	{
		fprintf(mFile,"\"%s.mrc.vsb\"",mName.c_str());

	}
	void getMiTrace()
	{
		fprintf(mFile,"\"%s.mrc.trc\"",mName.c_str());

	}
	void getMiShadow()
	{
		fprintf(mFile,"\"%s.mrc.shd\"",mName.c_str());

	}
	void getMiCaustic()
	{
		fprintf(mFile,"\"%s.mrc.cst\"",mName.c_str());

	}
	void getMiGlobillum()
	{
		fprintf(mFile,"\"%s.mrc.glb\"",mName.c_str());

	}
	void getMiExportGeoShader()
	{
		fprintf(mFile,"\"%s.mrc.mieg\"",mName.c_str());

	}
	void getMiGeoShader()
	{
		fprintf(mFile,"\"%s.mrc.migs\"",mName.c_str());

	}
protected:
	Transform(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DagNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TRANSFORM_H__
