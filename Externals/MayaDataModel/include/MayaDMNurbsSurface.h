/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	NurbsSurface(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "nurbsSurface"){}
	virtual ~NurbsSurface(){}
	void setDivisionsU(unsigned char dvu)
	{
		if(dvu == 0) return;
		fprintf(mFile,"setAttr \".dvu\" %i;\n", dvu);

	}
	void setDivisionsV(unsigned char dvv)
	{
		if(dvv == 0) return;
		fprintf(mFile,"setAttr \".dvv\" %i;\n", dvv);

	}
	void setCurvePrecision(unsigned char cpr)
	{
		if(cpr == 4) return;
		fprintf(mFile,"setAttr \".cpr\" %i;\n", cpr);

	}
	void setCurvePrecisionShaded(unsigned char cps)
	{
		if(cps == 1) return;
		fprintf(mFile,"setAttr \".cps\" %i;\n", cps);

	}
	void setSimplifyMode(unsigned char sm)
	{
		if(sm == 0) return;
		fprintf(mFile,"setAttr \".sm\" %i;\n", sm);

	}
	void setSimplifyU(unsigned char smu)
	{
		if(smu == 1) return;
		fprintf(mFile,"setAttr \".smu\" %i;\n", smu);

	}
	void setSimplifyV(unsigned char smv)
	{
		if(smv == 1) return;
		fprintf(mFile,"setAttr \".smv\" %i;\n", smv);

	}
	void setSmoothEdge(bool ues)
	{
		if(ues == false) return;
		fprintf(mFile,"setAttr \".ues\" %i;\n", ues);

	}
	void setSmoothEdgeRatio(double esr)
	{
		if(esr == 0.99) return;
		fprintf(mFile,"setAttr \".esr\" %f;\n", esr);

	}
	void setUseChordHeight(bool uch)
	{
		if(uch == false) return;
		fprintf(mFile,"setAttr \".uch\" %i;\n", uch);

	}
	void setObjSpaceChordHeight(bool uco)
	{
		if(uco == true) return;
		fprintf(mFile,"setAttr \".uco\" %i;\n", uco);

	}
	void setUseChordHeightRatio(bool ucr)
	{
		if(ucr == true) return;
		fprintf(mFile,"setAttr \".ucr\" %i;\n", ucr);

	}
	void setEdgeSwap(bool es)
	{
		if(es == false) return;
		fprintf(mFile,"setAttr \".es\" %i;\n", es);

	}
	void setUseMinScreen(bool uns)
	{
		if(uns == false) return;
		fprintf(mFile,"setAttr \".uns\" %i;\n", uns);

	}
	void setSelCVDisp(bool scvd)
	{
		if(scvd == false) return;
		fprintf(mFile,"setAttr \".scvd\" %i;\n", scvd);

	}
	void setDispCV(bool dcv)
	{
		if(dcv == false) return;
		fprintf(mFile,"setAttr \".dcv\" %i;\n", dcv);

	}
	void setDispEP(bool dep)
	{
		if(dep == false) return;
		fprintf(mFile,"setAttr \".dep\" %i;\n", dep);

	}
	void setDispHull(bool dh)
	{
		if(dh == false) return;
		fprintf(mFile,"setAttr \".dh\" %i;\n", dh);

	}
	void setDispGeometry(bool dg)
	{
		if(dg == true) return;
		fprintf(mFile,"setAttr \".dg\" %i;\n", dg);

	}
	void setDispOrigin(bool dor)
	{
		if(dor == false) return;
		fprintf(mFile,"setAttr \".dor\" %i;\n", dor);

	}
	void setNumberU(int nu)
	{
		if(nu == 3) return;
		fprintf(mFile,"setAttr \".nu\" %i;\n", nu);

	}
	void setModeU(unsigned int mu)
	{
		if(mu == 3) return;
		fprintf(mFile,"setAttr \".mu\" %i;\n", mu);

	}
	void setNumberV(int nv)
	{
		if(nv == 3) return;
		fprintf(mFile,"setAttr \".nv\" %i;\n", nv);

	}
	void setModeV(unsigned int mv)
	{
		if(mv == 3) return;
		fprintf(mFile,"setAttr \".mv\" %i;\n", mv);

	}
	void setChordHeight(double ch)
	{
		if(ch == 0.1) return;
		fprintf(mFile,"setAttr \".ch\" %f;\n", ch);

	}
	void setChordHeightRatio(double chr)
	{
		if(chr == 0.983) return;
		fprintf(mFile,"setAttr \".chr\" %f;\n", chr);

	}
	void setMinScreen(double mns)
	{
		if(mns == 14) return;
		fprintf(mFile,"setAttr \".mns\" %f;\n", mns);

	}
	void setCached(const nurbsSurface& cc)
	{
		fprintf(mFile,"setAttr \".cc\" -type \"nurbsSurface\" ");
		cc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInPlace(bool ipo)
	{
		if(ipo == false) return;
		fprintf(mFile,"setAttr \".ipo\" %i;\n", ipo);

	}
	void setDisplayRenderTessellation(bool drt)
	{
		if(drt == false) return;
		fprintf(mFile,"setAttr \".drt\" %i;\n", drt);

	}
	void setFixTextureWarp(bool ftwp)
	{
		if(ftwp == false) return;
		fprintf(mFile,"setAttr \".ftwp\" %i;\n", ftwp);

	}
	void setGridDivisionPerSpanU(short gdsu)
	{
		if(gdsu == 4) return;
		fprintf(mFile,"setAttr \".gdsu\" %i;\n", gdsu);

	}
	void setGridDivisionPerSpanV(short gdsv)
	{
		if(gdsv == 4) return;
		fprintf(mFile,"setAttr \".gdsv\" %i;\n", gdsv);

	}
	void setExplicitTessellationAttributes(bool eta)
	{
		if(eta == false) return;
		fprintf(mFile,"setAttr \".eta\" %i;\n", eta);

	}
	void setUDivisionsFactor(double nufa)
	{
		if(nufa == 1.5) return;
		fprintf(mFile,"setAttr \".nufa\" %f;\n", nufa);

	}
	void setVDivisionsFactor(double nvfa)
	{
		if(nvfa == 1.5) return;
		fprintf(mFile,"setAttr \".nvfa\" %f;\n", nvfa);

	}
	void setCurvatureTolerance(unsigned int cvto)
	{
		if(cvto == 2) return;
		fprintf(mFile,"setAttr \".cvto\" %i;\n", cvto);

	}
	void setBasicTessellationType(unsigned int btt)
	{
		if(btt == 0) return;
		fprintf(mFile,"setAttr \".btt\" %i;\n", btt);

	}
	void setDispSF(bool dsf)
	{
		if(dsf == false) return;
		fprintf(mFile,"setAttr \".dsf\" %i;\n", dsf);

	}
	void setNormalsDisplayScale(double ndf)
	{
		if(ndf == 1.0) return;
		fprintf(mFile,"setAttr \".ndf\" %f;\n", ndf);

	}
	void setMentalRayControls(const MentalRayControls& mrc)
	{
		fprintf(mFile,"setAttr \".mrc\" ");
		mrc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMiOverrideCaustics(bool oca)
	{
		if(oca == false) return;
		fprintf(mFile,"setAttr \".mrc.oca\" %i;\n", oca);

	}
	void setMiCausticAccuracy(short caa)
	{
		if(caa == 64) return;
		fprintf(mFile,"setAttr \".mrc.caa\" %i;\n", caa);

	}
	void setMiCausticRadius(float car)
	{
		if(car == 0) return;
		fprintf(mFile,"setAttr \".mrc.car\" %f;\n", car);

	}
	void setMiOverrideGlobalIllumination(bool ogi)
	{
		if(ogi == false) return;
		fprintf(mFile,"setAttr \".mrc.ogi\" %i;\n", ogi);

	}
	void setMiGlobillumAccuracy(short gia)
	{
		if(gia == 64) return;
		fprintf(mFile,"setAttr \".mrc.gia\" %i;\n", gia);

	}
	void setMiGlobillumRadius(float gir)
	{
		if(gir == 0) return;
		fprintf(mFile,"setAttr \".mrc.gir\" %f;\n", gir);

	}
	void setMiOverrideFinalGather(bool ofg)
	{
		if(ofg == false) return;
		fprintf(mFile,"setAttr \".mrc.ofg\" %i;\n", ofg);

	}
	void setMiFinalGatherRays(int fry)
	{
		if(fry == 1000) return;
		fprintf(mFile,"setAttr \".mrc.fry\" %i;\n", fry);

	}
	void setMiFinalGatherMinRadius(float fmn)
	{
		if(fmn == 0) return;
		fprintf(mFile,"setAttr \".mrc.fmn\" %f;\n", fmn);

	}
	void setMiFinalGatherMaxRadius(float fmx)
	{
		if(fmx == 0) return;
		fprintf(mFile,"setAttr \".mrc.fmx\" %f;\n", fmx);

	}
	void setMiFinalGatherFilter(short ffi)
	{
		if(ffi == 1) return;
		fprintf(mFile,"setAttr \".mrc.ffi\" %i;\n", ffi);

	}
	void setMiFinalGatherView(bool fgv)
	{
		if(fgv == false) return;
		fprintf(mFile,"setAttr \".mrc.fgv\" %i;\n", fgv);

	}
	void setMiOverrideSamples(bool oos)
	{
		if(oos == false) return;
		fprintf(mFile,"setAttr \".mrc.oos\" %i;\n", oos);

	}
	void setMiMinSamples(short mins)
	{
		if(mins == 0) return;
		fprintf(mFile,"setAttr \".mrc.mins\" %i;\n", mins);

	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 2) return;
		fprintf(mFile,"setAttr \".mrc.maxs\" %i;\n", maxs);

	}
	void setMiFinalGatherCast(bool fgc)
	{
		if(fgc == true) return;
		fprintf(mFile,"setAttr \".mrc.fgc\" %i;\n", fgc);

	}
	void setMiFinalGatherReceive(bool fge)
	{
		if(fge == true) return;
		fprintf(mFile,"setAttr \".mrc.fge\" %i;\n", fge);

	}
	void setMiTransparencyCast(bool tpc)
	{
		if(tpc == true) return;
		fprintf(mFile,"setAttr \".mrc.tpc\" %i;\n", tpc);

	}
	void setMiTransparencyReceive(bool tpr)
	{
		if(tpr == true) return;
		fprintf(mFile,"setAttr \".mrc.tpr\" %i;\n", tpr);

	}
	void setMiReflectionReceive(bool rflr)
	{
		if(rflr == true) return;
		fprintf(mFile,"setAttr \".mrc.rflr\" %i;\n", rflr);

	}
	void setMiRefractionReceive(bool rfrr)
	{
		if(rfrr == true) return;
		fprintf(mFile,"setAttr \".mrc.rfrr\" %i;\n", rfrr);

	}
	void getCreate()
	{
		fprintf(mFile,"\"%s.cr\"",mName.c_str());

	}
	void getLocal()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
	void getWorldSpace(size_t ws_i)
	{
		fprintf(mFile,"\"%s.ws[%i]\"",mName.c_str(),ws_i);

	}
	void getDivisionsU()
	{
		fprintf(mFile,"\"%s.dvu\"",mName.c_str());

	}
	void getDivisionsV()
	{
		fprintf(mFile,"\"%s.dvv\"",mName.c_str());

	}
	void getCurvePrecision()
	{
		fprintf(mFile,"\"%s.cpr\"",mName.c_str());

	}
	void getCurvePrecisionShaded()
	{
		fprintf(mFile,"\"%s.cps\"",mName.c_str());

	}
	void getSimplifyMode()
	{
		fprintf(mFile,"\"%s.sm\"",mName.c_str());

	}
	void getSimplifyU()
	{
		fprintf(mFile,"\"%s.smu\"",mName.c_str());

	}
	void getSimplifyV()
	{
		fprintf(mFile,"\"%s.smv\"",mName.c_str());

	}
	void getSmoothEdge()
	{
		fprintf(mFile,"\"%s.ues\"",mName.c_str());

	}
	void getSmoothEdgeRatio()
	{
		fprintf(mFile,"\"%s.esr\"",mName.c_str());

	}
	void getUseChordHeight()
	{
		fprintf(mFile,"\"%s.uch\"",mName.c_str());

	}
	void getObjSpaceChordHeight()
	{
		fprintf(mFile,"\"%s.uco\"",mName.c_str());

	}
	void getUseChordHeightRatio()
	{
		fprintf(mFile,"\"%s.ucr\"",mName.c_str());

	}
	void getEdgeSwap()
	{
		fprintf(mFile,"\"%s.es\"",mName.c_str());

	}
	void getUseMinScreen()
	{
		fprintf(mFile,"\"%s.uns\"",mName.c_str());

	}
	void getSelCVDisp()
	{
		fprintf(mFile,"\"%s.scvd\"",mName.c_str());

	}
	void getDispCV()
	{
		fprintf(mFile,"\"%s.dcv\"",mName.c_str());

	}
	void getDispEP()
	{
		fprintf(mFile,"\"%s.dep\"",mName.c_str());

	}
	void getDispHull()
	{
		fprintf(mFile,"\"%s.dh\"",mName.c_str());

	}
	void getDispGeometry()
	{
		fprintf(mFile,"\"%s.dg\"",mName.c_str());

	}
	void getDispOrigin()
	{
		fprintf(mFile,"\"%s.dor\"",mName.c_str());

	}
	void getNumberU()
	{
		fprintf(mFile,"\"%s.nu\"",mName.c_str());

	}
	void getModeU()
	{
		fprintf(mFile,"\"%s.mu\"",mName.c_str());

	}
	void getNumberV()
	{
		fprintf(mFile,"\"%s.nv\"",mName.c_str());

	}
	void getModeV()
	{
		fprintf(mFile,"\"%s.mv\"",mName.c_str());

	}
	void getChordHeight()
	{
		fprintf(mFile,"\"%s.ch\"",mName.c_str());

	}
	void getChordHeightRatio()
	{
		fprintf(mFile,"\"%s.chr\"",mName.c_str());

	}
	void getMinScreen()
	{
		fprintf(mFile,"\"%s.mns\"",mName.c_str());

	}
	void getFormU()
	{
		fprintf(mFile,"\"%s.fu\"",mName.c_str());

	}
	void getFormV()
	{
		fprintf(mFile,"\"%s.fv\"",mName.c_str());

	}
	void getCached()
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());

	}
	void getPatchUVIds(size_t pu_i)
	{
		fprintf(mFile,"\"%s.pu[%i]\"",mName.c_str(),pu_i);

	}
	void getInPlace()
	{
		fprintf(mFile,"\"%s.ipo\"",mName.c_str());

	}
	void getTweakSizeU()
	{
		fprintf(mFile,"\"%s.tsu\"",mName.c_str());

	}
	void getTweakSizeV()
	{
		fprintf(mFile,"\"%s.tsv\"",mName.c_str());

	}
	void getMinMaxRangeU()
	{
		fprintf(mFile,"\"%s.mmu\"",mName.c_str());

	}
	void getMinValueU()
	{
		fprintf(mFile,"\"%s.mmu.mnu\"",mName.c_str());

	}
	void getMaxValueU()
	{
		fprintf(mFile,"\"%s.mmu.mxu\"",mName.c_str());

	}
	void getMinMaxRangeV()
	{
		fprintf(mFile,"\"%s.mmv\"",mName.c_str());

	}
	void getMinValueV()
	{
		fprintf(mFile,"\"%s.mmv.mnv\"",mName.c_str());

	}
	void getMaxValueV()
	{
		fprintf(mFile,"\"%s.mmv.mxv\"",mName.c_str());

	}
	void getDegreeUV()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getDegreeU()
	{
		fprintf(mFile,"\"%s.d.du\"",mName.c_str());

	}
	void getDegreeV()
	{
		fprintf(mFile,"\"%s.d.dv\"",mName.c_str());

	}
	void getSpansUV()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getSpansU()
	{
		fprintf(mFile,"\"%s.sp.su\"",mName.c_str());

	}
	void getSpansV()
	{
		fprintf(mFile,"\"%s.sp.sv\"",mName.c_str());

	}
	void getDisplayRenderTessellation()
	{
		fprintf(mFile,"\"%s.drt\"",mName.c_str());

	}
	void getRenderTriangleCount()
	{
		fprintf(mFile,"\"%s.tcn\"",mName.c_str());

	}
	void getFixTextureWarp()
	{
		fprintf(mFile,"\"%s.ftwp\"",mName.c_str());

	}
	void getGridDivisionPerSpanU()
	{
		fprintf(mFile,"\"%s.gdsu\"",mName.c_str());

	}
	void getGridDivisionPerSpanV()
	{
		fprintf(mFile,"\"%s.gdsv\"",mName.c_str());

	}
	void getExplicitTessellationAttributes()
	{
		fprintf(mFile,"\"%s.eta\"",mName.c_str());

	}
	void getUDivisionsFactor()
	{
		fprintf(mFile,"\"%s.nufa\"",mName.c_str());

	}
	void getVDivisionsFactor()
	{
		fprintf(mFile,"\"%s.nvfa\"",mName.c_str());

	}
	void getCurvatureTolerance()
	{
		fprintf(mFile,"\"%s.cvto\"",mName.c_str());

	}
	void getBasicTessellationType()
	{
		fprintf(mFile,"\"%s.btt\"",mName.c_str());

	}
	void getDispSF()
	{
		fprintf(mFile,"\"%s.dsf\"",mName.c_str());

	}
	void getNormalsDisplayScale()
	{
		fprintf(mFile,"\"%s.ndf\"",mName.c_str());

	}
	void getMentalRayControls()
	{
		fprintf(mFile,"\"%s.mrc\"",mName.c_str());

	}
	void getMiOverrideCaustics()
	{
		fprintf(mFile,"\"%s.mrc.oca\"",mName.c_str());

	}
	void getMiCausticAccuracy()
	{
		fprintf(mFile,"\"%s.mrc.caa\"",mName.c_str());

	}
	void getMiCausticRadius()
	{
		fprintf(mFile,"\"%s.mrc.car\"",mName.c_str());

	}
	void getMiOverrideGlobalIllumination()
	{
		fprintf(mFile,"\"%s.mrc.ogi\"",mName.c_str());

	}
	void getMiGlobillumAccuracy()
	{
		fprintf(mFile,"\"%s.mrc.gia\"",mName.c_str());

	}
	void getMiGlobillumRadius()
	{
		fprintf(mFile,"\"%s.mrc.gir\"",mName.c_str());

	}
	void getMiOverrideFinalGather()
	{
		fprintf(mFile,"\"%s.mrc.ofg\"",mName.c_str());

	}
	void getMiFinalGatherRays()
	{
		fprintf(mFile,"\"%s.mrc.fry\"",mName.c_str());

	}
	void getMiFinalGatherMinRadius()
	{
		fprintf(mFile,"\"%s.mrc.fmn\"",mName.c_str());

	}
	void getMiFinalGatherMaxRadius()
	{
		fprintf(mFile,"\"%s.mrc.fmx\"",mName.c_str());

	}
	void getMiFinalGatherFilter()
	{
		fprintf(mFile,"\"%s.mrc.ffi\"",mName.c_str());

	}
	void getMiFinalGatherView()
	{
		fprintf(mFile,"\"%s.mrc.fgv\"",mName.c_str());

	}
	void getMiOverrideSamples()
	{
		fprintf(mFile,"\"%s.mrc.oos\"",mName.c_str());

	}
	void getMiMinSamples()
	{
		fprintf(mFile,"\"%s.mrc.mins\"",mName.c_str());

	}
	void getMiMaxSamples()
	{
		fprintf(mFile,"\"%s.mrc.maxs\"",mName.c_str());

	}
	void getMiFinalGatherCast()
	{
		fprintf(mFile,"\"%s.mrc.fgc\"",mName.c_str());

	}
	void getMiFinalGatherReceive()
	{
		fprintf(mFile,"\"%s.mrc.fge\"",mName.c_str());

	}
	void getMiTransparencyCast()
	{
		fprintf(mFile,"\"%s.mrc.tpc\"",mName.c_str());

	}
	void getMiTransparencyReceive()
	{
		fprintf(mFile,"\"%s.mrc.tpr\"",mName.c_str());

	}
	void getMiReflectionReceive()
	{
		fprintf(mFile,"\"%s.mrc.rflr\"",mName.c_str());

	}
	void getMiRefractionReceive()
	{
		fprintf(mFile,"\"%s.mrc.rfrr\"",mName.c_str());

	}
protected:
	NurbsSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSSURFACE_H__
