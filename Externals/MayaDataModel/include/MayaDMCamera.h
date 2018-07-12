/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CAMERA_H__
#define __MayaDM_CAMERA_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class Camera : public Shape
{
public:
	struct PostProjection{
		double preScale;
		double2 filmTranslate;
		struct FilmRollControl{
			double2 filmRollPivot;
			double filmRollValue;
			unsigned int filmRollOrder;
			void write(FILE* file) const
			{
				filmRollPivot.write(file);
				fprintf(file, " ");
				fprintf(file,"%f ", filmRollValue);
				fprintf(file,"%i", filmRollOrder);
			}
		} filmRollControl;
		double postScale;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", preScale);
			filmTranslate.write(file);
			fprintf(file, " ");
			filmRollControl.write(file);
			fprintf(file, " ");
			fprintf(file,"%f", postScale);
		}
	};
	struct MentalRayControls{
		bool miFbComputeColor;
		short miFbBitsizeColor;
		bool miFbComputeAlpha;
		short miFbBitsizeAlpha;
		bool miFbComputeDepth;
		bool miFbComputeNormal;
		bool miFbComputeMotion;
		bool miFbComputeCoverage;
		bool miFbComputeTag;
		bool miFbComputeContour;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", miFbComputeColor);
			fprintf(file,"%i ", miFbBitsizeColor);
			fprintf(file,"%i ", miFbComputeAlpha);
			fprintf(file,"%i ", miFbBitsizeAlpha);
			fprintf(file,"%i ", miFbComputeDepth);
			fprintf(file,"%i ", miFbComputeNormal);
			fprintf(file,"%i ", miFbComputeMotion);
			fprintf(file,"%i ", miFbComputeCoverage);
			fprintf(file,"%i ", miFbComputeTag);
			fprintf(file,"%i ", miFbComputeContour);
		}
	};
public:

	Camera():Shape(){}
	Camera(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "camera", shared, create){}
	virtual ~Camera(){}

	void setRenderable(bool rnd)
	{
		if(rnd == true) return;
		fprintf(mFile,"\tsetAttr \".rnd\" %i;\n", rnd);
	}
	void setCameraAperture(const double2& cap)
	{
		if(cap == double2(3.6, 2.4)) return;
		fprintf(mFile,"\tsetAttr \".cap\" -type \"double2\" ");
		cap.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHorizontalFilmAperture(double hfa)
	{
		if(hfa == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cap.hfa\" %f;\n", hfa);
	}
	void setVerticalFilmAperture(double vfa)
	{
		if(vfa == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cap.vfa\" %f;\n", vfa);
	}
	void setShakeOverscan(double sos)
	{
		if(sos == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sos\" %f;\n", sos);
	}
	void setShakeOverscanEnabled(bool soe)
	{
		if(soe == false) return;
		fprintf(mFile,"\tsetAttr \".soe\" %i;\n", soe);
	}
	void setFilmOffset(const double2& fio)
	{
		if(fio == double2(0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".fio\" -type \"double2\" ");
		fio.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHorizontalFilmOffset(double hfo)
	{
		if(hfo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fio.hfo\" %f;\n", hfo);
	}
	void setVerticalFilmOffset(double vfo)
	{
		if(vfo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fio.vfo\" %f;\n", vfo);
	}
	void setShakeEnabled(bool se)
	{
		if(se == false) return;
		fprintf(mFile,"\tsetAttr \".se\" %i;\n", se);
	}
	void setShake(const double2& shk)
	{
		if(shk == double2(0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".shk\" -type \"double2\" ");
		shk.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHorizontalShake(double hs)
	{
		if(hs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".shk.hs\" %f;\n", hs);
	}
	void setVerticalShake(double vs)
	{
		if(vs == 0.0) return;
		fprintf(mFile,"\tsetAttr \".shk.vs\" %f;\n", vs);
	}
	void setStereoHorizontalImageTranslateEnabled(bool hte)
	{
		if(hte == false) return;
		fprintf(mFile,"\tsetAttr \".hte\" %i;\n", hte);
	}
	void setStereoHorizontalImageTranslate(double hit)
	{
		if(hit == 0.0) return;
		fprintf(mFile,"\tsetAttr \".hit\" %f;\n", hit);
	}
	void setPostProjection(const PostProjection& ppj)
	{
		fprintf(mFile,"\tsetAttr \".ppj\" ");
		ppj.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPreScale(double psc)
	{
		if(psc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ppj.psc\" %f;\n", psc);
	}
	void setFilmTranslate(const double2& ct)
	{
		if(ct == double2(0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".ppj.ct\" -type \"double2\" ");
		ct.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFilmTranslateH(double fth)
	{
		if(fth == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ppj.ct.fth\" %f;\n", fth);
	}
	void setFilmTranslateV(double ftv)
	{
		if(ftv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ppj.ct.ftv\" %f;\n", ftv);
	}
	void setFilmRollControl(const PostProjection::FilmRollControl& frc)
	{
		fprintf(mFile,"\tsetAttr \".ppj.frc\" ");
		frc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFilmRollPivot(const double2& frp)
	{
		if(frp == double2(0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".ppj.frc.frp\" -type \"double2\" ");
		frp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setHorizontalRollPivot(double hrp)
	{
		if(hrp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ppj.frc.frp.hrp\" %f;\n", hrp);
	}
	void setVerticalRollPivot(double vrp)
	{
		if(vrp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ppj.frc.frp.vrp\" %f;\n", vrp);
	}
	void setFilmRollValue(double frv)
	{
		if(frv == 0) return;
		fprintf(mFile,"\tsetAttr \".ppj.frc.frv\" %f;\n", frv);
	}
	void setFilmRollOrder(unsigned int fro)
	{
		if(fro == 0) return;
		fprintf(mFile,"\tsetAttr \".ppj.frc.fro\" %i;\n", fro);
	}
	void setPostScale(double ptsc)
	{
		if(ptsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ppj.ptsc\" %f;\n", ptsc);
	}
	void setFilmFit(unsigned int ff)
	{
		if(ff == 1) return;
		fprintf(mFile,"\tsetAttr \".ff\" %i;\n", ff);
	}
	void setFilmFitOffset(double ffo)
	{
		if(ffo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ffo\" %f;\n", ffo);
	}
	void setOverscan(double ovr)
	{
		if(ovr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ovr\" %f;\n", ovr);
	}
	void setFocalLength(double fl)
	{
		if(fl == 35.0) return;
		fprintf(mFile,"\tsetAttr \".fl\" %f;\n", fl);
	}
	void setLensSqueezeRatio(double lsr)
	{
		if(lsr == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lsr\" %f;\n", lsr);
	}
	void setCameraScale(double cs)
	{
		if(cs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cs\" %f;\n", cs);
	}
	void setTriggerUpdate(double tu)
	{
		if(tu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tu\" %f;\n", tu);
	}
	void setNearClipPlane(double ncp)
	{
		if(ncp == 0) return;
		fprintf(mFile,"\tsetAttr \".ncp\" %f;\n", ncp);
	}
	void setFarClipPlane(double fcp)
	{
		if(fcp == 1) return;
		fprintf(mFile,"\tsetAttr \".fcp\" %f;\n", fcp);
	}
	void setFStop(double fs)
	{
		if(fs == 5.6) return;
		fprintf(mFile,"\tsetAttr \".fs\" %f;\n", fs);
	}
	void setFocusDistance(double fd)
	{
		if(fd == 5) return;
		fprintf(mFile,"\tsetAttr \".fd\" %f;\n", fd);
	}
	void setShutterAngle(double sa)
	{
		if(sa == 1) return;
		fprintf(mFile,"\tsetAttr \".sa\" %f;\n", sa);
	}
	void setCenterOfInterest(double coi)
	{
		if(coi == 5) return;
		fprintf(mFile,"\tsetAttr \".coi\" %f;\n", coi);
	}
	void setOrthographicWidth(double ow)
	{
		if(ow == 1) return;
		fprintf(mFile,"\tsetAttr \".ow\" %f;\n", ow);
	}
	void setImageName(const string& imn)
	{
		if(imn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".imn\" -type \"string\" ");
		imn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDepthName(const string& den)
	{
		if(den == "NULL") return;
		fprintf(mFile,"\tsetAttr \".den\" -type \"string\" ");
		den.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaskName(const string& man)
	{
		if(man == "NULL") return;
		fprintf(mFile,"\tsetAttr \".man\" -type \"string\" ");
		man.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTumblePivot(const double3& tp)
	{
		if(tp == double3(0.0, 0.0, 0.0)) return;
		fprintf(mFile,"\tsetAttr \".tp\" -type \"double3\" ");
		tp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTumblePivotX(double tpx)
	{
		if(tpx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tp.tpx\" %f;\n", tpx);
	}
	void setTumblePivotY(double tpy)
	{
		if(tpy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tp.tpy\" %f;\n", tpy);
	}
	void setTumblePivotZ(double tpz)
	{
		if(tpz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tp.tpz\" %f;\n", tpz);
	}
	void setUsePivotAsLocalSpace(bool uls)
	{
		if(uls == 0) return;
		fprintf(mFile,"\tsetAttr \".uls\" %i;\n", uls);
	}
	void setHomeCommand(const string& hc)
	{
		if(hc == "NULL") return;
		fprintf(mFile,"\tsetAttr \".hc\" -type \"string\" ");
		hc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocatorScale(double lls)
	{
		if(lls == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lls\" %f;\n", lls);
	}
	void setDisplayFilmGate(bool dfg)
	{
		if(dfg == false) return;
		fprintf(mFile,"\tsetAttr \".dfg\" %i;\n", dfg);
	}
	void setDisplayResolution(bool dr)
	{
		if(dr == false) return;
		fprintf(mFile,"\tsetAttr \".dr\" %i;\n", dr);
	}
	void setDisplaySafeAction(bool dsa)
	{
		if(dsa == false) return;
		fprintf(mFile,"\tsetAttr \".dsa\" %i;\n", dsa);
	}
	void setDisplaySafeTitle(bool dst)
	{
		if(dst == false) return;
		fprintf(mFile,"\tsetAttr \".dst\" %i;\n", dst);
	}
	void setDisplayFieldChart(bool dfc)
	{
		if(dfc == false) return;
		fprintf(mFile,"\tsetAttr \".dfc\" %i;\n", dfc);
	}
	void setDisplayFilmPivot(bool dfp)
	{
		if(dfp == false) return;
		fprintf(mFile,"\tsetAttr \".dfp\" %i;\n", dfp);
	}
	void setDisplayFilmOrigin(bool dfo)
	{
		if(dfo == false) return;
		fprintf(mFile,"\tsetAttr \".dfo\" %i;\n", dfo);
	}
	void setClippingPlanes(bool cp)
	{
		if(cp == true) return;
		fprintf(mFile,"\tsetAttr \".cp\" %i;\n", cp);
	}
	void setBestFitClippingPlanes(bool bfc)
	{
		if(bfc == true) return;
		fprintf(mFile,"\tsetAttr \".bfc\" %i;\n", bfc);
	}
	void setDepthOfField(bool dof)
	{
		if(dof == false) return;
		fprintf(mFile,"\tsetAttr \".dof\" %i;\n", dof);
	}
	void setMotionBlur(bool mb)
	{
		if(mb == false) return;
		fprintf(mFile,"\tsetAttr \".mb\" %i;\n", mb);
	}
	void setOrthographic(bool o)
	{
		if(o == false) return;
		fprintf(mFile,"\tsetAttr \".o\" %i;\n", o);
	}
	void setJournalCommand(bool jc)
	{
		if(jc == false) return;
		fprintf(mFile,"\tsetAttr \".jc\" %i;\n", jc);
	}
	void setImage(bool img)
	{
		if(img == true) return;
		fprintf(mFile,"\tsetAttr \".img\" %i;\n", img);
	}
	void setDepth(bool dep)
	{
		if(dep == false) return;
		fprintf(mFile,"\tsetAttr \".dep\" %i;\n", dep);
	}
	void setTransparencyBasedDepth(bool tdth)
	{
		if(tdth == true) return;
		fprintf(mFile,"\tsetAttr \".tdth\" %i;\n", tdth);
	}
	void setThreshold(double tthd)
	{
		if(tthd == 0.9) return;
		fprintf(mFile,"\tsetAttr \".tthd\" %f;\n", tthd);
	}
	void setDepthType(unsigned int dptp)
	{
		if(dptp == 1) return;
		fprintf(mFile,"\tsetAttr \".dptp\" %i;\n", dptp);
	}
	void setUseExploreDepthFormat(bool uexd)
	{
		if(uexd == false) return;
		fprintf(mFile,"\tsetAttr \".uexd\" %i;\n", uexd);
	}
	void setMask(bool ma)
	{
		if(ma == true) return;
		fprintf(mFile,"\tsetAttr \".ma\" %i;\n", ma);
	}
	void setBackgroundColor(const float3& col)
	{
		fprintf(mFile,"\tsetAttr \".col\" -type \"float3\" ");
		col.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBackgroundColorR(float colr)
	{
		if(colr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".col.colr\" %f;\n", colr);
	}
	void setBackgroundColorG(float colg)
	{
		if(colg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".col.colg\" %f;\n", colg);
	}
	void setBackgroundColorB(float colb)
	{
		if(colb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".col.colb\" %f;\n", colb);
	}
	void setFocusRegionScale(double frs)
	{
		if(frs == 1.0) return;
		fprintf(mFile,"\tsetAttr \".frs\" %f;\n", frs);
	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"\tsetAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiFbComputeColor(bool micc)
	{
		if(micc == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.micc\" %i;\n", micc);
	}
	void setMiFbBitsizeColor(short mict)
	{
		if(mict == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.mict\" %i;\n", mict);
	}
	void setMiFbComputeAlpha(bool mica)
	{
		if(mica == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.mica\" %i;\n", mica);
	}
	void setMiFbBitsizeAlpha(short miat)
	{
		if(miat == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.miat\" %i;\n", miat);
	}
	void setMiFbComputeDepth(bool micd)
	{
		if(micd == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.micd\" %i;\n", micd);
	}
	void setMiFbComputeNormal(bool micn)
	{
		if(micn == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.micn\" %i;\n", micn);
	}
	void setMiFbComputeMotion(bool micm)
	{
		if(micm == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.micm\" %i;\n", micm);
	}
	void setMiFbComputeCoverage(bool micv)
	{
		if(micv == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.micv\" %i;\n", micv);
	}
	void setMiFbComputeTag(bool mitg)
	{
		if(mitg == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.mitg\" %i;\n", mitg);
	}
	void setMiFbComputeContour(bool mico)
	{
		if(mico == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.mico\" %i;\n", mico);
	}
	void getRenderable()const
	{
		fprintf(mFile,"\"%s.rnd\"",mName.c_str());
	}
	void getCameraAperture()const
	{
		fprintf(mFile,"\"%s.cap\"",mName.c_str());
	}
	void getHorizontalFilmAperture()const
	{
		fprintf(mFile,"\"%s.cap.hfa\"",mName.c_str());
	}
	void getVerticalFilmAperture()const
	{
		fprintf(mFile,"\"%s.cap.vfa\"",mName.c_str());
	}
	void getShakeOverscan()const
	{
		fprintf(mFile,"\"%s.sos\"",mName.c_str());
	}
	void getShakeOverscanEnabled()const
	{
		fprintf(mFile,"\"%s.soe\"",mName.c_str());
	}
	void getFilmOffset()const
	{
		fprintf(mFile,"\"%s.fio\"",mName.c_str());
	}
	void getHorizontalFilmOffset()const
	{
		fprintf(mFile,"\"%s.fio.hfo\"",mName.c_str());
	}
	void getVerticalFilmOffset()const
	{
		fprintf(mFile,"\"%s.fio.vfo\"",mName.c_str());
	}
	void getShakeEnabled()const
	{
		fprintf(mFile,"\"%s.se\"",mName.c_str());
	}
	void getShake()const
	{
		fprintf(mFile,"\"%s.shk\"",mName.c_str());
	}
	void getHorizontalShake()const
	{
		fprintf(mFile,"\"%s.shk.hs\"",mName.c_str());
	}
	void getVerticalShake()const
	{
		fprintf(mFile,"\"%s.shk.vs\"",mName.c_str());
	}
	void getStereoHorizontalImageTranslateEnabled()const
	{
		fprintf(mFile,"\"%s.hte\"",mName.c_str());
	}
	void getStereoHorizontalImageTranslate()const
	{
		fprintf(mFile,"\"%s.hit\"",mName.c_str());
	}
	void getPostProjection()const
	{
		fprintf(mFile,"\"%s.ppj\"",mName.c_str());
	}
	void getPreScale()const
	{
		fprintf(mFile,"\"%s.ppj.psc\"",mName.c_str());
	}
	void getFilmTranslate()const
	{
		fprintf(mFile,"\"%s.ppj.ct\"",mName.c_str());
	}
	void getFilmTranslateH()const
	{
		fprintf(mFile,"\"%s.ppj.ct.fth\"",mName.c_str());
	}
	void getFilmTranslateV()const
	{
		fprintf(mFile,"\"%s.ppj.ct.ftv\"",mName.c_str());
	}
	void getFilmRollControl()const
	{
		fprintf(mFile,"\"%s.ppj.frc\"",mName.c_str());
	}
	void getFilmRollPivot()const
	{
		fprintf(mFile,"\"%s.ppj.frc.frp\"",mName.c_str());
	}
	void getHorizontalRollPivot()const
	{
		fprintf(mFile,"\"%s.ppj.frc.frp.hrp\"",mName.c_str());
	}
	void getVerticalRollPivot()const
	{
		fprintf(mFile,"\"%s.ppj.frc.frp.vrp\"",mName.c_str());
	}
	void getFilmRollValue()const
	{
		fprintf(mFile,"\"%s.ppj.frc.frv\"",mName.c_str());
	}
	void getFilmRollOrder()const
	{
		fprintf(mFile,"\"%s.ppj.frc.fro\"",mName.c_str());
	}
	void getPostScale()const
	{
		fprintf(mFile,"\"%s.ppj.ptsc\"",mName.c_str());
	}
	void getFilmFit()const
	{
		fprintf(mFile,"\"%s.ff\"",mName.c_str());
	}
	void getFilmFitOffset()const
	{
		fprintf(mFile,"\"%s.ffo\"",mName.c_str());
	}
	void getOverscan()const
	{
		fprintf(mFile,"\"%s.ovr\"",mName.c_str());
	}
	void getFocalLength()const
	{
		fprintf(mFile,"\"%s.fl\"",mName.c_str());
	}
	void getLensSqueezeRatio()const
	{
		fprintf(mFile,"\"%s.lsr\"",mName.c_str());
	}
	void getCameraScale()const
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getTriggerUpdate()const
	{
		fprintf(mFile,"\"%s.tu\"",mName.c_str());
	}
	void getNearClipPlane()const
	{
		fprintf(mFile,"\"%s.ncp\"",mName.c_str());
	}
	void getFarClipPlane()const
	{
		fprintf(mFile,"\"%s.fcp\"",mName.c_str());
	}
	void getFStop()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getFocusDistance()const
	{
		fprintf(mFile,"\"%s.fd\"",mName.c_str());
	}
	void getShutterAngle()const
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());
	}
	void getCenterOfInterest()const
	{
		fprintf(mFile,"\"%s.coi\"",mName.c_str());
	}
	void getOrthographicWidth()const
	{
		fprintf(mFile,"\"%s.ow\"",mName.c_str());
	}
	void getImageName()const
	{
		fprintf(mFile,"\"%s.imn\"",mName.c_str());
	}
	void getDepthName()const
	{
		fprintf(mFile,"\"%s.den\"",mName.c_str());
	}
	void getMaskName()const
	{
		fprintf(mFile,"\"%s.man\"",mName.c_str());
	}
	void getTumblePivot()const
	{
		fprintf(mFile,"\"%s.tp\"",mName.c_str());
	}
	void getTumblePivotX()const
	{
		fprintf(mFile,"\"%s.tp.tpx\"",mName.c_str());
	}
	void getTumblePivotY()const
	{
		fprintf(mFile,"\"%s.tp.tpy\"",mName.c_str());
	}
	void getTumblePivotZ()const
	{
		fprintf(mFile,"\"%s.tp.tpz\"",mName.c_str());
	}
	void getUsePivotAsLocalSpace()const
	{
		fprintf(mFile,"\"%s.uls\"",mName.c_str());
	}
	void getImagePlane(size_t ip_i)const
	{
		fprintf(mFile,"\"%s.ip[%i]\"",mName.c_str(),ip_i);
	}
	void getImagePlane()const
	{

		fprintf(mFile,"\"%s.ip\"",mName.c_str());
	}
	void getHomeCommand()const
	{
		fprintf(mFile,"\"%s.hc\"",mName.c_str());
	}
	void getBookmarks(size_t b_i)const
	{
		fprintf(mFile,"\"%s.b[%i]\"",mName.c_str(),b_i);
	}
	void getBookmarks()const
	{

		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getLocatorScale()const
	{
		fprintf(mFile,"\"%s.lls\"",mName.c_str());
	}
	void getDisplayFilmGate()const
	{
		fprintf(mFile,"\"%s.dfg\"",mName.c_str());
	}
	void getDisplayResolution()const
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());
	}
	void getDisplaySafeAction()const
	{
		fprintf(mFile,"\"%s.dsa\"",mName.c_str());
	}
	void getDisplaySafeTitle()const
	{
		fprintf(mFile,"\"%s.dst\"",mName.c_str());
	}
	void getDisplayFieldChart()const
	{
		fprintf(mFile,"\"%s.dfc\"",mName.c_str());
	}
	void getDisplayFilmPivot()const
	{
		fprintf(mFile,"\"%s.dfp\"",mName.c_str());
	}
	void getDisplayFilmOrigin()const
	{
		fprintf(mFile,"\"%s.dfo\"",mName.c_str());
	}
	void getClippingPlanes()const
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());
	}
	void getBestFitClippingPlanes()const
	{
		fprintf(mFile,"\"%s.bfc\"",mName.c_str());
	}
	void getDepthOfField()const
	{
		fprintf(mFile,"\"%s.dof\"",mName.c_str());
	}
	void getMotionBlur()const
	{
		fprintf(mFile,"\"%s.mb\"",mName.c_str());
	}
	void getOrthographic()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getJournalCommand()const
	{
		fprintf(mFile,"\"%s.jc\"",mName.c_str());
	}
	void getImage()const
	{
		fprintf(mFile,"\"%s.img\"",mName.c_str());
	}
	void getDepth()const
	{
		fprintf(mFile,"\"%s.dep\"",mName.c_str());
	}
	void getTransparencyBasedDepth()const
	{
		fprintf(mFile,"\"%s.tdth\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.tthd\"",mName.c_str());
	}
	void getDepthType()const
	{
		fprintf(mFile,"\"%s.dptp\"",mName.c_str());
	}
	void getUseExploreDepthFormat()const
	{
		fprintf(mFile,"\"%s.uexd\"",mName.c_str());
	}
	void getMask()const
	{
		fprintf(mFile,"\"%s.ma\"",mName.c_str());
	}
	void getBackgroundColor()const
	{
		fprintf(mFile,"\"%s.col\"",mName.c_str());
	}
	void getBackgroundColorR()const
	{
		fprintf(mFile,"\"%s.col.colr\"",mName.c_str());
	}
	void getBackgroundColorG()const
	{
		fprintf(mFile,"\"%s.col.colg\"",mName.c_str());
	}
	void getBackgroundColorB()const
	{
		fprintf(mFile,"\"%s.col.colb\"",mName.c_str());
	}
	void getFocusRegionScale()const
	{
		fprintf(mFile,"\"%s.frs\"",mName.c_str());
	}
	void getMentalRayControls()const
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());
	}
	void getMiOutputShader()const
	{
		fprintf(mFile,"\"%s.mrc.mios\"",mName.c_str());
	}
	void getMiFbComputeColor()const
	{
		fprintf(mFile,"\"%s.mrc.micc\"",mName.c_str());
	}
	void getMiFbBitsizeColor()const
	{
		fprintf(mFile,"\"%s.mrc.mict\"",mName.c_str());
	}
	void getMiFbComputeAlpha()const
	{
		fprintf(mFile,"\"%s.mrc.mica\"",mName.c_str());
	}
	void getMiFbBitsizeAlpha()const
	{
		fprintf(mFile,"\"%s.mrc.miat\"",mName.c_str());
	}
	void getMiFbComputeDepth()const
	{
		fprintf(mFile,"\"%s.mrc.micd\"",mName.c_str());
	}
	void getMiFbComputeNormal()const
	{
		fprintf(mFile,"\"%s.mrc.micn\"",mName.c_str());
	}
	void getMiFbComputeMotion()const
	{
		fprintf(mFile,"\"%s.mrc.micm\"",mName.c_str());
	}
	void getMiFbComputeCoverage()const
	{
		fprintf(mFile,"\"%s.mrc.micv\"",mName.c_str());
	}
	void getMiFbComputeTag()const
	{
		fprintf(mFile,"\"%s.mrc.mitg\"",mName.c_str());
	}
	void getMiFbComputeContour()const
	{
		fprintf(mFile,"\"%s.mrc.mico\"",mName.c_str());
	}
	void getMiVolumeShader()const
	{
		fprintf(mFile,"\"%s.mrc.mivs\"",mName.c_str());
	}
	void getMiLensShader()const
	{
		fprintf(mFile,"\"%s.mrc.mils\"",mName.c_str());
	}
	void getMiEnvironmentShader()const
	{
		fprintf(mFile,"\"%s.mrc.mies\"",mName.c_str());
	}
	void getMiOutputShaderList(size_t miol_i)const
	{
		fprintf(mFile,"\"%s.mrc.miol[%i]\"",mName.c_str(),miol_i);
	}
	void getMiLensShaderList(size_t mill_i)const
	{
		fprintf(mFile,"\"%s.mrc.mill[%i]\"",mName.c_str(),mill_i);
	}
	void getMiRenderPassList(size_t mirp_i)const
	{
		fprintf(mFile,"\"%s.mrc.mirp[%i]\"",mName.c_str(),mirp_i);
	}
protected:
	Camera(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CAMERA_H__
