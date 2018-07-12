/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSSURFACE_H__
#define __MayaDM_NURBSSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSurfaceShape.h"
namespace MayaDM
{
class NurbsSurface : public SurfaceShape
{
public:
	struct MentalRayControls{
		bool miOverrideCaustics;
		short miCausticAccuracy;
		float miCausticRadius;
		bool miOverrideGlobalIllumination;
		short miGlobillumAccuracy;
		float miGlobillumRadius;
		bool miOverrideFinalGather;
		int miFinalGatherRays;
		float miFinalGatherMinRadius;
		float miFinalGatherMaxRadius;
		short miFinalGatherFilter;
		bool miFinalGatherView;
		bool miOverrideSamples;
		short miMinSamples;
		short miMaxSamples;
		bool miFinalGatherCast;
		bool miFinalGatherReceive;
		bool miTransparencyCast;
		bool miTransparencyReceive;
		bool miReflectionReceive;
		bool miRefractionReceive;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", miOverrideCaustics);
			fprintf(file,"%i ", miCausticAccuracy);
			fprintf(file,"%f ", miCausticRadius);
			fprintf(file,"%i ", miOverrideGlobalIllumination);
			fprintf(file,"%i ", miGlobillumAccuracy);
			fprintf(file,"%f ", miGlobillumRadius);
			fprintf(file,"%i ", miOverrideFinalGather);
			fprintf(file,"%i ", miFinalGatherRays);
			fprintf(file,"%f ", miFinalGatherMinRadius);
			fprintf(file,"%f ", miFinalGatherMaxRadius);
			fprintf(file,"%i ", miFinalGatherFilter);
			fprintf(file,"%i ", miFinalGatherView);
			fprintf(file,"%i ", miOverrideSamples);
			fprintf(file,"%i ", miMinSamples);
			fprintf(file,"%i ", miMaxSamples);
			fprintf(file,"%i ", miFinalGatherCast);
			fprintf(file,"%i ", miFinalGatherReceive);
			fprintf(file,"%i ", miTransparencyCast);
			fprintf(file,"%i ", miTransparencyReceive);
			fprintf(file,"%i ", miReflectionReceive);
			fprintf(file,"%i", miRefractionReceive);
		}
	};
public:

	NurbsSurface():SurfaceShape(){}
	NurbsSurface(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SurfaceShape(file, name, parent, "nurbsSurface", shared, create){}
	virtual ~NurbsSurface(){}

	void setDivisionsU(unsigned char dvu)
	{
		if(dvu == 0) return;
		fprintf(mFile,"\tsetAttr \".dvu\" %i;\n", dvu);
	}
	void setDivisionsV(unsigned char dvv)
	{
		if(dvv == 0) return;
		fprintf(mFile,"\tsetAttr \".dvv\" %i;\n", dvv);
	}
	void setCurvePrecision(unsigned char cpr)
	{
		if(cpr == 4) return;
		fprintf(mFile,"\tsetAttr \".cpr\" %i;\n", cpr);
	}
	void setCurvePrecisionShaded(unsigned char cps)
	{
		if(cps == 1) return;
		fprintf(mFile,"\tsetAttr \".cps\" %i;\n", cps);
	}
	void setSimplifyMode(unsigned char sm)
	{
		if(sm == 0) return;
		fprintf(mFile,"\tsetAttr \".sm\" %i;\n", sm);
	}
	void setSimplifyU(unsigned char smu)
	{
		if(smu == 1) return;
		fprintf(mFile,"\tsetAttr \".smu\" %i;\n", smu);
	}
	void setSimplifyV(unsigned char smv)
	{
		if(smv == 1) return;
		fprintf(mFile,"\tsetAttr \".smv\" %i;\n", smv);
	}
	void setSmoothEdge(bool ues)
	{
		if(ues == false) return;
		fprintf(mFile,"\tsetAttr \".ues\" %i;\n", ues);
	}
	void setSmoothEdgeRatio(double esr)
	{
		if(esr == 0.99) return;
		fprintf(mFile,"\tsetAttr \".esr\" %f;\n", esr);
	}
	void setUseChordHeight(bool uch)
	{
		if(uch == false) return;
		fprintf(mFile,"\tsetAttr \".uch\" %i;\n", uch);
	}
	void setObjSpaceChordHeight(bool uco)
	{
		if(uco == true) return;
		fprintf(mFile,"\tsetAttr \".uco\" %i;\n", uco);
	}
	void setUseChordHeightRatio(bool ucr)
	{
		if(ucr == true) return;
		fprintf(mFile,"\tsetAttr \".ucr\" %i;\n", ucr);
	}
	void setEdgeSwap(bool es)
	{
		if(es == false) return;
		fprintf(mFile,"\tsetAttr \".es\" %i;\n", es);
	}
	void setUseMinScreen(bool uns)
	{
		if(uns == false) return;
		fprintf(mFile,"\tsetAttr \".uns\" %i;\n", uns);
	}
	void setSelCVDisp(bool scvd)
	{
		if(scvd == false) return;
		fprintf(mFile,"\tsetAttr \".scvd\" %i;\n", scvd);
	}
	void setDispCV(bool dcv)
	{
		if(dcv == false) return;
		fprintf(mFile,"\tsetAttr \".dcv\" %i;\n", dcv);
	}
	void setDispEP(bool dep)
	{
		if(dep == false) return;
		fprintf(mFile,"\tsetAttr \".dep\" %i;\n", dep);
	}
	void setDispHull(bool dh)
	{
		if(dh == false) return;
		fprintf(mFile,"\tsetAttr \".dh\" %i;\n", dh);
	}
	void setDispGeometry(bool dg)
	{
		if(dg == true) return;
		fprintf(mFile,"\tsetAttr \".dg\" %i;\n", dg);
	}
	void setDispOrigin(bool dor)
	{
		if(dor == false) return;
		fprintf(mFile,"\tsetAttr \".dor\" %i;\n", dor);
	}
	void setNumberU(int nu)
	{
		if(nu == 3) return;
		fprintf(mFile,"\tsetAttr \".nu\" %i;\n", nu);
	}
	void setModeU(unsigned int mu)
	{
		if(mu == 3) return;
		fprintf(mFile,"\tsetAttr \".mu\" %i;\n", mu);
	}
	void setNumberV(int nv)
	{
		if(nv == 3) return;
		fprintf(mFile,"\tsetAttr \".nv\" %i;\n", nv);
	}
	void setModeV(unsigned int mv)
	{
		if(mv == 3) return;
		fprintf(mFile,"\tsetAttr \".mv\" %i;\n", mv);
	}
	void setChordHeight(double ch)
	{
		if(ch == 0.1) return;
		fprintf(mFile,"\tsetAttr \".ch\" %f;\n", ch);
	}
	void setChordHeightRatio(double chr)
	{
		if(chr == 0.983) return;
		fprintf(mFile,"\tsetAttr \".chr\" %f;\n", chr);
	}
	void setMinScreen(double mns)
	{
		if(mns == 14) return;
		fprintf(mFile,"\tsetAttr \".mns\" %f;\n", mns);
	}
	void setCached(const nurbsSurface& cc)
	{
		fprintf(mFile,"\tsetAttr \".cc\" -type \"nurbsSurface\" ");
		cc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInPlace(bool ipo)
	{
		if(ipo == false) return;
		fprintf(mFile,"\tsetAttr \".ipo\" %i;\n", ipo);
	}
	void setDisplayRenderTessellation(bool drt)
	{
		if(drt == false) return;
		fprintf(mFile,"\tsetAttr \".drt\" %i;\n", drt);
	}
	void setFixTextureWarp(bool ftwp)
	{
		if(ftwp == false) return;
		fprintf(mFile,"\tsetAttr \".ftwp\" %i;\n", ftwp);
	}
	void setGridDivisionPerSpanU(short gdsu)
	{
		if(gdsu == 4) return;
		fprintf(mFile,"\tsetAttr \".gdsu\" %i;\n", gdsu);
	}
	void setGridDivisionPerSpanV(short gdsv)
	{
		if(gdsv == 4) return;
		fprintf(mFile,"\tsetAttr \".gdsv\" %i;\n", gdsv);
	}
	void setExplicitTessellationAttributes(bool eta)
	{
		if(eta == false) return;
		fprintf(mFile,"\tsetAttr \".eta\" %i;\n", eta);
	}
	void setUDivisionsFactor(double nufa)
	{
		if(nufa == 1.5) return;
		fprintf(mFile,"\tsetAttr \".nufa\" %f;\n", nufa);
	}
	void setVDivisionsFactor(double nvfa)
	{
		if(nvfa == 1.5) return;
		fprintf(mFile,"\tsetAttr \".nvfa\" %f;\n", nvfa);
	}
	void setCurvatureTolerance(unsigned int cvto)
	{
		if(cvto == 2) return;
		fprintf(mFile,"\tsetAttr \".cvto\" %i;\n", cvto);
	}
	void setBasicTessellationType(unsigned int btt)
	{
		if(btt == 0) return;
		fprintf(mFile,"\tsetAttr \".btt\" %i;\n", btt);
	}
	void setDispSF(bool dsf)
	{
		if(dsf == false) return;
		fprintf(mFile,"\tsetAttr \".dsf\" %i;\n", dsf);
	}
	void setNormalsDisplayScale(double ndf)
	{
		if(ndf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ndf\" %f;\n", ndf);
	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"\tsetAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMiOverrideCaustics(bool oca)
	{
		if(oca == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.oca\" %i;\n", oca);
	}
	void setMiCausticAccuracy(short caa)
	{
		if(caa == 64) return;
		fprintf(mFile,"\tsetAttr \".mrc.caa\" %i;\n", caa);
	}
	void setMiCausticRadius(float car)
	{
		if(car == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.car\" %f;\n", car);
	}
	void setMiOverrideGlobalIllumination(bool ogi)
	{
		if(ogi == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.ogi\" %i;\n", ogi);
	}
	void setMiGlobillumAccuracy(short gia)
	{
		if(gia == 64) return;
		fprintf(mFile,"\tsetAttr \".mrc.gia\" %i;\n", gia);
	}
	void setMiGlobillumRadius(float gir)
	{
		if(gir == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.gir\" %f;\n", gir);
	}
	void setMiOverrideFinalGather(bool ofg)
	{
		if(ofg == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.ofg\" %i;\n", ofg);
	}
	void setMiFinalGatherRays(int fry)
	{
		if(fry == 1000) return;
		fprintf(mFile,"\tsetAttr \".mrc.fry\" %i;\n", fry);
	}
	void setMiFinalGatherMinRadius(float fmn)
	{
		if(fmn == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.fmn\" %f;\n", fmn);
	}
	void setMiFinalGatherMaxRadius(float fmx)
	{
		if(fmx == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.fmx\" %f;\n", fmx);
	}
	void setMiFinalGatherFilter(short ffi)
	{
		if(ffi == 1) return;
		fprintf(mFile,"\tsetAttr \".mrc.ffi\" %i;\n", ffi);
	}
	void setMiFinalGatherView(bool fgv)
	{
		if(fgv == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.fgv\" %i;\n", fgv);
	}
	void setMiOverrideSamples(bool oos)
	{
		if(oos == false) return;
		fprintf(mFile,"\tsetAttr \".mrc.oos\" %i;\n", oos);
	}
	void setMiMinSamples(short mins)
	{
		if(mins == 0) return;
		fprintf(mFile,"\tsetAttr \".mrc.mins\" %i;\n", mins);
	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 2) return;
		fprintf(mFile,"\tsetAttr \".mrc.maxs\" %i;\n", maxs);
	}
	void setMiFinalGatherCast(bool fgc)
	{
		if(fgc == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.fgc\" %i;\n", fgc);
	}
	void setMiFinalGatherReceive(bool fge)
	{
		if(fge == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.fge\" %i;\n", fge);
	}
	void setMiTransparencyCast(bool tpc)
	{
		if(tpc == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.tpc\" %i;\n", tpc);
	}
	void setMiTransparencyReceive(bool tpr)
	{
		if(tpr == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.tpr\" %i;\n", tpr);
	}
	void setMiReflectionReceive(bool rflr)
	{
		if(rflr == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.rflr\" %i;\n", rflr);
	}
	void setMiRefractionReceive(bool rfrr)
	{
		if(rfrr == true) return;
		fprintf(mFile,"\tsetAttr \".mrc.rfrr\" %i;\n", rfrr);
	}
	void getCreate()const
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getLocal()const
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getWorldSpace(size_t ws_i)const
	{
		fprintf(mFile,"\"%s.ws[%i]\"",mName.c_str(),ws_i);
	}
	void getWorldSpace()const
	{

		fprintf(mFile,"\"%s.ws\"",mName.c_str());
	}
	void getDivisionsU()const
	{
		fprintf(mFile,"\"%s.dvu\"",mName.c_str());
	}
	void getDivisionsV()const
	{
		fprintf(mFile,"\"%s.dvv\"",mName.c_str());
	}
	void getCurvePrecision()const
	{
		fprintf(mFile,"\"%s.cpr\"",mName.c_str());
	}
	void getCurvePrecisionShaded()const
	{
		fprintf(mFile,"\"%s.cps\"",mName.c_str());
	}
	void getSimplifyMode()const
	{
		fprintf(mFile,"\"%s.sm\"",mName.c_str());
	}
	void getSimplifyU()const
	{
		fprintf(mFile,"\"%s.smu\"",mName.c_str());
	}
	void getSimplifyV()const
	{
		fprintf(mFile,"\"%s.smv\"",mName.c_str());
	}
	void getSmoothEdge()const
	{
		fprintf(mFile,"\"%s.ues\"",mName.c_str());
	}
	void getSmoothEdgeRatio()const
	{
		fprintf(mFile,"\"%s.esr\"",mName.c_str());
	}
	void getUseChordHeight()const
	{
		fprintf(mFile,"\"%s.uch\"",mName.c_str());
	}
	void getObjSpaceChordHeight()const
	{
		fprintf(mFile,"\"%s.uco\"",mName.c_str());
	}
	void getUseChordHeightRatio()const
	{
		fprintf(mFile,"\"%s.ucr\"",mName.c_str());
	}
	void getEdgeSwap()const
	{
		fprintf(mFile,"\"%s.es\"",mName.c_str());
	}
	void getUseMinScreen()const
	{
		fprintf(mFile,"\"%s.uns\"",mName.c_str());
	}
	void getSelCVDisp()const
	{
		fprintf(mFile,"\"%s.scvd\"",mName.c_str());
	}
	void getDispCV()const
	{
		fprintf(mFile,"\"%s.dcv\"",mName.c_str());
	}
	void getDispEP()const
	{
		fprintf(mFile,"\"%s.dep\"",mName.c_str());
	}
	void getDispHull()const
	{
		fprintf(mFile,"\"%s.dh\"",mName.c_str());
	}
	void getDispGeometry()const
	{
		fprintf(mFile,"\"%s.dg\"",mName.c_str());
	}
	void getDispOrigin()const
	{
		fprintf(mFile,"\"%s.dor\"",mName.c_str());
	}
	void getNumberU()const
	{
		fprintf(mFile,"\"%s.nu\"",mName.c_str());
	}
	void getModeU()const
	{
		fprintf(mFile,"\"%s.mu\"",mName.c_str());
	}
	void getNumberV()const
	{
		fprintf(mFile,"\"%s.nv\"",mName.c_str());
	}
	void getModeV()const
	{
		fprintf(mFile,"\"%s.mv\"",mName.c_str());
	}
	void getChordHeight()const
	{
		fprintf(mFile,"\"%s.ch\"",mName.c_str());
	}
	void getChordHeightRatio()const
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());
	}
	void getMinScreen()const
	{
		fprintf(mFile,"\"%s.mns\"",mName.c_str());
	}
	void getFormU()const
	{
		fprintf(mFile,"\"%s.fu\"",mName.c_str());
	}
	void getFormV()const
	{
		fprintf(mFile,"\"%s.fv\"",mName.c_str());
	}
	void getCached()const
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());
	}
	void getPatchUVIds(size_t pu_i)const
	{
		fprintf(mFile,"\"%s.pu[%i]\"",mName.c_str(),pu_i);
	}
	void getPatchUVIds()const
	{

		fprintf(mFile,"\"%s.pu\"",mName.c_str());
	}
	void getInPlace()const
	{
		fprintf(mFile,"\"%s.ipo\"",mName.c_str());
	}
	void getTweakSizeU()const
	{
		fprintf(mFile,"\"%s.tsu\"",mName.c_str());
	}
	void getTweakSizeV()const
	{
		fprintf(mFile,"\"%s.tsv\"",mName.c_str());
	}
	void getMinMaxRangeU()const
	{
		fprintf(mFile,"\"%s.mmu\"",mName.c_str());
	}
	void getMinValueU()const
	{
		fprintf(mFile,"\"%s.mmu.mnu\"",mName.c_str());
	}
	void getMaxValueU()const
	{
		fprintf(mFile,"\"%s.mmu.mxu\"",mName.c_str());
	}
	void getMinMaxRangeV()const
	{
		fprintf(mFile,"\"%s.mmv\"",mName.c_str());
	}
	void getMinValueV()const
	{
		fprintf(mFile,"\"%s.mmv.mnv\"",mName.c_str());
	}
	void getMaxValueV()const
	{
		fprintf(mFile,"\"%s.mmv.mxv\"",mName.c_str());
	}
	void getDegreeUV()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getDegreeU()const
	{
		fprintf(mFile,"\"%s.d.du\"",mName.c_str());
	}
	void getDegreeV()const
	{
		fprintf(mFile,"\"%s.d.dv\"",mName.c_str());
	}
	void getSpansUV()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getSpansU()const
	{
		fprintf(mFile,"\"%s.sp.su\"",mName.c_str());
	}
	void getSpansV()const
	{
		fprintf(mFile,"\"%s.sp.sv\"",mName.c_str());
	}
	void getDisplayRenderTessellation()const
	{
		fprintf(mFile,"\"%s.drt\"",mName.c_str());
	}
	void getRenderTriangleCount()const
	{
		fprintf(mFile,"\"%s.tcn\"",mName.c_str());
	}
	void getFixTextureWarp()const
	{
		fprintf(mFile,"\"%s.ftwp\"",mName.c_str());
	}
	void getGridDivisionPerSpanU()const
	{
		fprintf(mFile,"\"%s.gdsu\"",mName.c_str());
	}
	void getGridDivisionPerSpanV()const
	{
		fprintf(mFile,"\"%s.gdsv\"",mName.c_str());
	}
	void getExplicitTessellationAttributes()const
	{
		fprintf(mFile,"\"%s.eta\"",mName.c_str());
	}
	void getUDivisionsFactor()const
	{
		fprintf(mFile,"\"%s.nufa\"",mName.c_str());
	}
	void getVDivisionsFactor()const
	{
		fprintf(mFile,"\"%s.nvfa\"",mName.c_str());
	}
	void getCurvatureTolerance()const
	{
		fprintf(mFile,"\"%s.cvto\"",mName.c_str());
	}
	void getBasicTessellationType()const
	{
		fprintf(mFile,"\"%s.btt\"",mName.c_str());
	}
	void getDispSF()const
	{
		fprintf(mFile,"\"%s.dsf\"",mName.c_str());
	}
	void getNormalsDisplayScale()const
	{
		fprintf(mFile,"\"%s.ndf\"",mName.c_str());
	}
	void getMentalRayControls()const
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());
	}
	void getMiOverrideCaustics()const
	{
		fprintf(mFile,"\"%s.mrc.oca\"",mName.c_str());
	}
	void getMiCausticAccuracy()const
	{
		fprintf(mFile,"\"%s.mrc.caa\"",mName.c_str());
	}
	void getMiCausticRadius()const
	{
		fprintf(mFile,"\"%s.mrc.car\"",mName.c_str());
	}
	void getMiOverrideGlobalIllumination()const
	{
		fprintf(mFile,"\"%s.mrc.ogi\"",mName.c_str());
	}
	void getMiGlobillumAccuracy()const
	{
		fprintf(mFile,"\"%s.mrc.gia\"",mName.c_str());
	}
	void getMiGlobillumRadius()const
	{
		fprintf(mFile,"\"%s.mrc.gir\"",mName.c_str());
	}
	void getMiOverrideFinalGather()const
	{
		fprintf(mFile,"\"%s.mrc.ofg\"",mName.c_str());
	}
	void getMiFinalGatherRays()const
	{
		fprintf(mFile,"\"%s.mrc.fry\"",mName.c_str());
	}
	void getMiFinalGatherMinRadius()const
	{
		fprintf(mFile,"\"%s.mrc.fmn\"",mName.c_str());
	}
	void getMiFinalGatherMaxRadius()const
	{
		fprintf(mFile,"\"%s.mrc.fmx\"",mName.c_str());
	}
	void getMiFinalGatherFilter()const
	{
		fprintf(mFile,"\"%s.mrc.ffi\"",mName.c_str());
	}
	void getMiFinalGatherView()const
	{
		fprintf(mFile,"\"%s.mrc.fgv\"",mName.c_str());
	}
	void getMiOverrideSamples()const
	{
		fprintf(mFile,"\"%s.mrc.oos\"",mName.c_str());
	}
	void getMiMinSamples()const
	{
		fprintf(mFile,"\"%s.mrc.mins\"",mName.c_str());
	}
	void getMiMaxSamples()const
	{
		fprintf(mFile,"\"%s.mrc.maxs\"",mName.c_str());
	}
	void getMiFinalGatherCast()const
	{
		fprintf(mFile,"\"%s.mrc.fgc\"",mName.c_str());
	}
	void getMiFinalGatherReceive()const
	{
		fprintf(mFile,"\"%s.mrc.fge\"",mName.c_str());
	}
	void getMiTransparencyCast()const
	{
		fprintf(mFile,"\"%s.mrc.tpc\"",mName.c_str());
	}
	void getMiTransparencyReceive()const
	{
		fprintf(mFile,"\"%s.mrc.tpr\"",mName.c_str());
	}
	void getMiReflectionReceive()const
	{
		fprintf(mFile,"\"%s.mrc.rflr\"",mName.c_str());
	}
	void getMiRefractionReceive()const
	{
		fprintf(mFile,"\"%s.mrc.rfrr\"",mName.c_str());
	}
protected:
	NurbsSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SurfaceShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSSURFACE_H__
