/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLUIDSHAPE_H__
#define __MayaDM_FLUIDSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSurfaceShape.h"
namespace MayaDM
{
class FluidShape : public SurfaceShape
{
public:
	struct Resolution{
		int resolutionW;
		int resolutionH;
		int resolutionD;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", resolutionW);
			fprintf(file,"%i ", resolutionH);
			fprintf(file,"%i", resolutionD);
		}
	};
	struct Dimensions{
		double dimensionsW;
		double dimensionsH;
		double dimensionsD;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", dimensionsW);
			fprintf(file,"%f ", dimensionsH);
			fprintf(file,"%f", dimensionsD);
		}
	};
	struct FieldData{
		void write(FILE* file) const
		{
		}
	};
	struct FieldList{
		struct FieldFunction{
			struct FieldFunction_Inmap{
				short fieldFunction_InmapTo;
				short fieldFunction_InmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", fieldFunction_InmapTo);
					fprintf(file,"%i", fieldFunction_InmapFrom);
				}
			}* fieldFunction_Inmap;
			struct FieldFunction_Outmap{
				short fieldFunction_OutmapTo;
				short fieldFunction_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", fieldFunction_OutmapTo);
					fprintf(file,"%i", fieldFunction_OutmapFrom);
				}
			}* fieldFunction_Outmap;
			void write(FILE* file) const
			{
				size_t size = sizeof(fieldFunction_Inmap)/sizeof(FieldFunction_Inmap);
				for(size_t i=0; i<size; ++i)
				{
					fieldFunction_Inmap[i].write(file);
					fprintf(file, " ");
					if(i+1<size) fprintf(file," ");
				}
				size = sizeof(fieldFunction_Outmap)/sizeof(FieldFunction_Outmap);
				for(size_t i=0; i<size; ++i)
				{
					fieldFunction_Outmap[i].write(file);
					if(i+1<size) fprintf(file," ");
				}
			}
		} fieldFunction;
		void write(FILE* file) const
		{
			fieldFunction.write(file);
		}
	};
	struct EmissionList{
		struct EmissionFunction{
			struct EmissionFunction_Inmap{
				short emissionFunction_InmapTo;
				short emissionFunction_InmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", emissionFunction_InmapTo);
					fprintf(file,"%i", emissionFunction_InmapFrom);
				}
			}* emissionFunction_Inmap;
			struct EmissionFunction_Outmap{
				short emissionFunction_OutmapTo;
				short emissionFunction_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", emissionFunction_OutmapTo);
					fprintf(file,"%i", emissionFunction_OutmapFrom);
				}
			}* emissionFunction_Outmap;
			void write(FILE* file) const
			{
				size_t size = sizeof(emissionFunction_Inmap)/sizeof(EmissionFunction_Inmap);
				for(size_t i=0; i<size; ++i)
				{
					emissionFunction_Inmap[i].write(file);
					fprintf(file, " ");
					if(i+1<size) fprintf(file," ");
				}
				size = sizeof(emissionFunction_Outmap)/sizeof(EmissionFunction_Outmap);
				for(size_t i=0; i<size; ++i)
				{
					emissionFunction_Outmap[i].write(file);
					if(i+1<size) fprintf(file," ");
				}
			}
		} emissionFunction;
		void write(FILE* file) const
		{
			emissionFunction.write(file);
		}
	};
	struct SubVolumeCenter{
		int subVolumeCenterW;
		int subVolumeCenterH;
		int subVolumeCenterD;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", subVolumeCenterW);
			fprintf(file,"%i ", subVolumeCenterH);
			fprintf(file,"%i ", subVolumeCenterD);
		}
	};
	struct SubVolumeSize{
		int subVolumeSizeW;
		int subVolumeSizeH;
		int subVolumeSizeD;
		void write(FILE* file) const
		{
			fprintf(file,"%i ", subVolumeSizeW);
			fprintf(file,"%i ", subVolumeSizeH);
			fprintf(file,"%i ", subVolumeSizeD);
		}
	};
	struct InputData{
		vectorArray inputPositions;
		vectorArray inputVelocities;
		doubleArray inputMass;
		void write(FILE* file) const
		{
			inputPositions.write(file);
			fprintf(file, " ");
			inputVelocities.write(file);
			fprintf(file, " ");
			inputMass.write(file);
			fprintf(file, " ");
		}
	};
	struct Color{
		float color_Position;
		float3 color_Color;
		unsigned int color_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", color_Position);
			color_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", color_Interp);
		}
	};
	struct Opacity{
		float opacity_Position;
		float opacity_FloatValue;
		unsigned int opacity_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", opacity_Position);
			fprintf(file,"%f ", opacity_FloatValue);
			fprintf(file,"%i", opacity_Interp);
		}
	};
	struct Incandescence{
		float incandescence_Position;
		float3 incandescence_Color;
		unsigned int incandescence_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", incandescence_Position);
			incandescence_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", incandescence_Interp);
		}
	};
	struct Environment{
		float environment_Position;
		float3 environment_Color;
		unsigned int environment_Interp;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", environment_Position);
			environment_Color.write(file);
			fprintf(file, " ");
			fprintf(file,"%i", environment_Interp);
		}
	};
	struct CollisionData{
		void write(FILE* file) const
		{
		}
	};
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
			fprintf(file,"%i", miMaxSamples);
		}
	};
public:
	FluidShape(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "fluidShape"){}
	virtual ~FluidShape(){}
	void setStartFrame(double stf)
	{
		if(stf == 1.0) return;
		fprintf(mFile,"setAttr \".stf\" %f;\n", stf);

	}
	void setDisableInteractiveEval(bool die)
	{
		if(die == false) return;
		fprintf(mFile,"setAttr \".die\" %i;\n", die);

	}
	void setIs2d(bool is2)
	{
		if(is2 == false) return;
		fprintf(mFile,"setAttr \".is2\" %i;\n", is2);

	}
	void setResolution(const Resolution& res)
	{
		fprintf(mFile,"setAttr \".res\" ");
		res.write(mFile);
		fprintf(mFile,";\n");

	}
	void setResolutionW(int rw)
	{
		if(rw == 10) return;
		fprintf(mFile,"setAttr \".res.rw\" %i;\n", rw);

	}
	void setResolutionH(int rh)
	{
		if(rh == 10) return;
		fprintf(mFile,"setAttr \".res.rh\" %i;\n", rh);

	}
	void setResolutionD(int rd)
	{
		if(rd == 10) return;
		fprintf(mFile,"setAttr \".res.rd\" %i;\n", rd);

	}
	void setDimensions(const Dimensions& dim)
	{
		fprintf(mFile,"setAttr \".dim\" ");
		dim.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDimensionsW(double dw)
	{
		if(dw == 3) return;
		fprintf(mFile,"setAttr \".dim.dw\" %f;\n", dw);

	}
	void setDimensionsH(double dh)
	{
		if(dh == 3) return;
		fprintf(mFile,"setAttr \".dim.dh\" %f;\n", dh);

	}
	void setDimensionsD(double dd)
	{
		if(dd == 3) return;
		fprintf(mFile,"setAttr \".dim.dd\" %f;\n", dd);

	}
	void setDoFields(bool dfr)
	{
		if(dfr == true) return;
		fprintf(mFile,"setAttr \".dfr\" %i;\n", dfr);

	}
	void setFieldList(size_t fll_i,const FieldList& fll)
	{
		fprintf(mFile,"setAttr \".fll[%i]\" ",fll_i);
		fll.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFieldFunction(size_t fll_i,const FieldList::FieldFunction& frf)
	{
		fprintf(mFile,"setAttr \".fll[%i].frf\" ",fll_i);
		frf.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFieldFunction_Inmap(size_t fll_i,size_t frfi_i,const FieldList::FieldFunction::FieldFunction_Inmap& frfi)
	{
		fprintf(mFile,"setAttr \".fll[%i].frf.frfi[%i]\" ",fll_i,frfi_i);
		frfi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFieldFunction_InmapTo(size_t fll_i,size_t frfi_i,short frfit)
	{
		if(frfit == 0) return;
		fprintf(mFile,"setAttr \".fll[%i].frf.frfi[%i].frfit\" %i;\n", fll_i,frfi_i,frfit);

	}
	void setFieldFunction_InmapFrom(size_t fll_i,size_t frfi_i,short frfif)
	{
		if(frfif == 0) return;
		fprintf(mFile,"setAttr \".fll[%i].frf.frfi[%i].frfif\" %i;\n", fll_i,frfi_i,frfif);

	}
	void setFieldFunction_Outmap(size_t fll_i,size_t frfo_i,const FieldList::FieldFunction::FieldFunction_Outmap& frfo)
	{
		fprintf(mFile,"setAttr \".fll[%i].frf.frfo[%i]\" ",fll_i,frfo_i);
		frfo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFieldFunction_OutmapTo(size_t fll_i,size_t frfo_i,short frfot)
	{
		if(frfot == 0) return;
		fprintf(mFile,"setAttr \".fll[%i].frf.frfo[%i].frfot\" %i;\n", fll_i,frfo_i,frfot);

	}
	void setFieldFunction_OutmapFrom(size_t fll_i,size_t frfo_i,short frfof)
	{
		if(frfof == 0) return;
		fprintf(mFile,"setAttr \".fll[%i].frf.frfo[%i].frfof\" %i;\n", fll_i,frfo_i,frfof);

	}
	void setDoEmission(bool de)
	{
		if(de == true) return;
		fprintf(mFile,"setAttr \".de\" %i;\n", de);

	}
	void setInheritFactor(double inh)
	{
		if(inh == 0.0) return;
		fprintf(mFile,"setAttr \".inh\" %f;\n", inh);

	}
	void setSeed(size_t sd_i,int sd)
	{
		if(sd == 1) return;
		fprintf(mFile,"setAttr \".sd[%i]\" %i;\n", sd_i,sd);

	}
	void setSeed(size_t sd_start,size_t sd_end,int* sd)
	{
		fprintf(mFile,"setAttr \".sd[%i:%i]\" ", sd_start,sd_end);
		size_t size = (sd_end-sd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",sd[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startSeed(size_t sd_start,size_t sd_end)
	{
		fprintf(mFile,"setAttr \".sd[%i:%i]\"",sd_start,sd_end);

	}
	void appendSeed(int sd)
	{
		fprintf(mFile," %i",sd);

	}
	void endSeed()
	{
		fprintf(mFile,";\n");

	}
	void setEmissionList(size_t eml_i,const EmissionList& eml)
	{
		fprintf(mFile,"setAttr \".eml[%i]\" ",eml_i);
		eml.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEmissionFunction(size_t eml_i,const EmissionList::EmissionFunction& emf)
	{
		fprintf(mFile,"setAttr \".eml[%i].emf\" ",eml_i);
		emf.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEmissionFunction_Inmap(size_t eml_i,size_t emfi_i,const EmissionList::EmissionFunction::EmissionFunction_Inmap& emfi)
	{
		fprintf(mFile,"setAttr \".eml[%i].emf.emfi[%i]\" ",eml_i,emfi_i);
		emfi.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEmissionFunction_InmapTo(size_t eml_i,size_t emfi_i,short emfit)
	{
		if(emfit == 0) return;
		fprintf(mFile,"setAttr \".eml[%i].emf.emfi[%i].emfit\" %i;\n", eml_i,emfi_i,emfit);

	}
	void setEmissionFunction_InmapFrom(size_t eml_i,size_t emfi_i,short emfif)
	{
		if(emfif == 0) return;
		fprintf(mFile,"setAttr \".eml[%i].emf.emfi[%i].emfif\" %i;\n", eml_i,emfi_i,emfif);

	}
	void setEmissionFunction_Outmap(size_t eml_i,size_t emfo_i,const EmissionList::EmissionFunction::EmissionFunction_Outmap& emfo)
	{
		fprintf(mFile,"setAttr \".eml[%i].emf.emfo[%i]\" ",eml_i,emfo_i);
		emfo.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEmissionFunction_OutmapTo(size_t eml_i,size_t emfo_i,short emfot)
	{
		if(emfot == 0) return;
		fprintf(mFile,"setAttr \".eml[%i].emf.emfo[%i].emfot\" %i;\n", eml_i,emfo_i,emfot);

	}
	void setEmissionFunction_OutmapFrom(size_t eml_i,size_t emfo_i,short emfof)
	{
		if(emfof == 0) return;
		fprintf(mFile,"setAttr \".eml[%i].emf.emfo[%i].emfof\" %i;\n", eml_i,emfo_i,emfof);

	}
	void setSlices(int sli)
	{
		if(sli == 2) return;
		fprintf(mFile,"setAttr \".sli\" %i;\n", sli);

	}
	void setVoxelQuality(unsigned int vqu)
	{
		if(vqu == 0) return;
		fprintf(mFile,"setAttr \".vqu\" %i;\n", vqu);

	}
	void setDrawSubVolume(bool dsv)
	{
		if(dsv == false) return;
		fprintf(mFile,"setAttr \".dsv\" %i;\n", dsv);

	}
	void setSubVolumeCenter(const SubVolumeCenter& svc)
	{
		fprintf(mFile,"setAttr \".svc\" ");
		svc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSubVolumeCenterW(int scw)
	{
		if(scw == -1) return;
		fprintf(mFile,"setAttr \".svc.scw\" %i;\n", scw);

	}
	void setSubVolumeCenterH(int sch)
	{
		if(sch == -1) return;
		fprintf(mFile,"setAttr \".svc.sch\" %i;\n", sch);

	}
	void setSubVolumeCenterD(int scd)
	{
		if(scd == -1) return;
		fprintf(mFile,"setAttr \".svc.scd\" %i;\n", scd);

	}
	void setSubVolumeSize(const SubVolumeSize& svs)
	{
		fprintf(mFile,"setAttr \".svs\" ");
		svs.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSubVolumeSizeW(int ssw)
	{
		if(ssw == -1) return;
		fprintf(mFile,"setAttr \".svs.ssw\" %i;\n", ssw);

	}
	void setSubVolumeSizeH(int ssh)
	{
		if(ssh == -1) return;
		fprintf(mFile,"setAttr \".svs.ssh\" %i;\n", ssh);

	}
	void setSubVolumeSizeD(int ssd)
	{
		if(ssd == -1) return;
		fprintf(mFile,"setAttr \".svs.ssd\" %i;\n", ssd);

	}
	void setBoundaryDraw(unsigned int bod)
	{
		if(bod == 0) return;
		fprintf(mFile,"setAttr \".bod\" %i;\n", bod);

	}
	void setDrawHeads(bool dhd)
	{
		if(dhd == true) return;
		fprintf(mFile,"setAttr \".dhd\" %i;\n", dhd);

	}
	void setVelocityDraw(bool vld)
	{
		if(vld == false) return;
		fprintf(mFile,"setAttr \".vld\" %i;\n", vld);

	}
	void setVelocityDrawLength(double vdl)
	{
		if(vdl == 1) return;
		fprintf(mFile,"setAttr \".vdl\" %f;\n", vdl);

	}
	void setVelocityDrawSkip(int vds)
	{
		if(vds == 1) return;
		fprintf(mFile,"setAttr \".vds\" %i;\n", vds);

	}
	void setShadedDisplay(unsigned int sdp)
	{
		if(sdp == 1) return;
		fprintf(mFile,"setAttr \".sdp\" %i;\n", sdp);

	}
	void setOpacityPreviewGain(float opg)
	{
		if(opg == 0.5) return;
		fprintf(mFile,"setAttr \".opg\" %f;\n", opg);

	}
	void setWireframeDisplay(unsigned int wdp)
	{
		if(wdp == 2) return;
		fprintf(mFile,"setAttr \".wdp\" %i;\n", wdp);

	}
	void setNumericDisplay(unsigned int nud)
	{
		if(nud == 0) return;
		fprintf(mFile,"setAttr \".nud\" %i;\n", nud);

	}
	void setHardwareSelfShadow(bool hss)
	{
		if(hss == true) return;
		fprintf(mFile,"setAttr \".hss\" %i;\n", hss);

	}
	void setCoordinateMethod(unsigned int cmet)
	{
		if(cmet == 0) return;
		fprintf(mFile,"setAttr \".cmet\" %i;\n", cmet);

	}
	void setSimulationRateScale(float srs)
	{
		if(srs == 1) return;
		fprintf(mFile,"setAttr \".srs\" %f;\n", srs);

	}
	void setGridInterpolator(unsigned int gdi)
	{
		if(gdi == 0) return;
		fprintf(mFile,"setAttr \".gdi\" %i;\n", gdi);

	}
	void setForceDynamics(bool fdn)
	{
		if(fdn == false) return;
		fprintf(mFile,"setAttr \".fdn\" %i;\n", fdn);

	}
	void setSolver(unsigned int sol)
	{
		if(sol == 1) return;
		fprintf(mFile,"setAttr \".sol\" %i;\n", sol);

	}
	void setSolverQuality(int sql)
	{
		if(sql == 20) return;
		fprintf(mFile,"setAttr \".sql\" %i;\n", sql);

	}
	void setHighDetailSolve(unsigned int hds)
	{
		if(hds == 0) return;
		fprintf(mFile,"setAttr \".hds\" %i;\n", hds);

	}
	void setBoundaryX(unsigned int bndx)
	{
		if(bndx == 1) return;
		fprintf(mFile,"setAttr \".bndx\" %i;\n", bndx);

	}
	void setBoundaryY(unsigned int bndy)
	{
		if(bndy == 1) return;
		fprintf(mFile,"setAttr \".bndy\" %i;\n", bndy);

	}
	void setBoundaryZ(unsigned int bndz)
	{
		if(bndz == 1) return;
		fprintf(mFile,"setAttr \".bndz\" %i;\n", bndz);

	}
	void setMassConversion(double mcv)
	{
		if(mcv == 1) return;
		fprintf(mFile,"setAttr \".mcv\" %f;\n", mcv);

	}
	void setFalloffMethod(unsigned int fmt)
	{
		if(fmt == 0) return;
		fprintf(mFile,"setAttr \".fmt\" %i;\n", fmt);

	}
	void setDensityMethod(unsigned int dmt)
	{
		if(dmt == 2) return;
		fprintf(mFile,"setAttr \".dmt\" %i;\n", dmt);

	}
	void setDensityGradient(unsigned int dgr)
	{
		if(dgr == 0) return;
		fprintf(mFile,"setAttr \".dgr\" %i;\n", dgr);

	}
	void setDensityScale(float dsc)
	{
		if(dsc == 0.5) return;
		fprintf(mFile,"setAttr \".dsc\" %f;\n", dsc);

	}
	void setDensityDissipation(double dds)
	{
		if(dds == 0) return;
		fprintf(mFile,"setAttr \".dds\" %f;\n", dds);

	}
	void setDensityDiffusion(double ddf)
	{
		if(ddf == 0) return;
		fprintf(mFile,"setAttr \".ddf\" %f;\n", ddf);

	}
	void setConserveMass(bool cm)
	{
		if(cm == true) return;
		fprintf(mFile,"setAttr \".cm\" %i;\n", cm);

	}
	void setDensityBuoyancy(float dsb)
	{
		if(dsb == 1.0) return;
		fprintf(mFile,"setAttr \".dsb\" %f;\n", dsb);

	}
	void setGravity(float grv)
	{
		if(grv == 9.8) return;
		fprintf(mFile,"setAttr \".grv\" %f;\n", grv);

	}
	void setVelocityMethod(unsigned int vmt)
	{
		if(vmt == 2) return;
		fprintf(mFile,"setAttr \".vmt\" %i;\n", vmt);

	}
	void setVelocityGradient(unsigned int vgr)
	{
		if(vgr == 0) return;
		fprintf(mFile,"setAttr \".vgr\" %i;\n", vgr);

	}
	void setVelocityScale(const float3& vsc)
	{
		if(vsc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".vsc\" -type \"float3\" ");
		vsc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVelocityScaleX(float vsx)
	{
		if(vsx == 0.0) return;
		fprintf(mFile,"setAttr \".vsc.vsx\" %f;\n", vsx);

	}
	void setVelocityScaleY(float vsy)
	{
		if(vsy == 0.0) return;
		fprintf(mFile,"setAttr \".vsc.vsy\" %f;\n", vsy);

	}
	void setVelocityScaleZ(float vsz)
	{
		if(vsz == 0.0) return;
		fprintf(mFile,"setAttr \".vsc.vsz\" %f;\n", vsz);

	}
	void setViscosity(float viy)
	{
		if(viy == 0) return;
		fprintf(mFile,"setAttr \".viy\" %f;\n", viy);

	}
	void setFriction(float fri)
	{
		if(fri == 0) return;
		fprintf(mFile,"setAttr \".fri\" %f;\n", fri);

	}
	void setVelocitySwirl(float vsw)
	{
		if(vsw == 0) return;
		fprintf(mFile,"setAttr \".vsw\" %f;\n", vsw);

	}
	void setVelocityDamp(float vdp)
	{
		if(vdp == 0) return;
		fprintf(mFile,"setAttr \".vdp\" %f;\n", vdp);

	}
	void setVelocityAdvect(bool va)
	{
		if(va == true) return;
		fprintf(mFile,"setAttr \".va\" %i;\n", va);

	}
	void setVelocityProject(bool vi)
	{
		if(vi == true) return;
		fprintf(mFile,"setAttr \".vi\" %i;\n", vi);

	}
	void setTurbulenceStrength(float tst)
	{
		if(tst == 0) return;
		fprintf(mFile,"setAttr \".tst\" %f;\n", tst);

	}
	void setTurbulenceFrequency(float tfr)
	{
		if(tfr == 0.2) return;
		fprintf(mFile,"setAttr \".tfr\" %f;\n", tfr);

	}
	void setTurbulenceSpeed(float tbs)
	{
		if(tbs == .2) return;
		fprintf(mFile,"setAttr \".tbs\" %f;\n", tbs);

	}
	void setTurbulenceRes(int trs)
	{
		if(trs == 10) return;
		fprintf(mFile,"setAttr \".trs\" %i;\n", trs);

	}
	void setTemperatureMethod(unsigned int tmet)
	{
		if(tmet == 0) return;
		fprintf(mFile,"setAttr \".tmet\" %i;\n", tmet);

	}
	void setTemperatureGradient(unsigned int tgr)
	{
		if(tgr == 0) return;
		fprintf(mFile,"setAttr \".tgr\" %i;\n", tgr);

	}
	void setTemperatureScale(float tmsc)
	{
		if(tmsc == 1.0) return;
		fprintf(mFile,"setAttr \".tmsc\" %f;\n", tmsc);

	}
	void setTemperatureDissipation(double tds)
	{
		if(tds == 0.1) return;
		fprintf(mFile,"setAttr \".tds\" %f;\n", tds);

	}
	void setTemperatureDiffusion(double tdf)
	{
		if(tdf == 0.1) return;
		fprintf(mFile,"setAttr \".tdf\" %f;\n", tdf);

	}
	void setTemperatureTurbulence(float ttb)
	{
		if(ttb == 0.1) return;
		fprintf(mFile,"setAttr \".ttb\" %f;\n", ttb);

	}
	void setBuoyancy(float buo)
	{
		if(buo == 3) return;
		fprintf(mFile,"setAttr \".buo\" %f;\n", buo);

	}
	void setColorMethod(unsigned int cmt)
	{
		if(cmt == 0) return;
		fprintf(mFile,"setAttr \".cmt\" %i;\n", cmt);

	}
	void setColorDissipation(double cds)
	{
		if(cds == 0) return;
		fprintf(mFile,"setAttr \".cds\" %f;\n", cds);

	}
	void setColorDiffusion(double cdf)
	{
		if(cdf == 0) return;
		fprintf(mFile,"setAttr \".cdf\" %f;\n", cdf);

	}
	void setFuelMethod(unsigned int fmet)
	{
		if(fmet == 0) return;
		fprintf(mFile,"setAttr \".fmet\" %i;\n", fmet);

	}
	void setFuelGradient(unsigned int fgr)
	{
		if(fgr == 0) return;
		fprintf(mFile,"setAttr \".fgr\" %i;\n", fgr);

	}
	void setFuelScale(float fesc)
	{
		if(fesc == 1.0) return;
		fprintf(mFile,"setAttr \".fesc\" %f;\n", fesc);

	}
	void setReactionSpeed(float resp)
	{
		if(resp == 0.05) return;
		fprintf(mFile,"setAttr \".resp\" %f;\n", resp);

	}
	void setFuelIgnitionTemp(float fuit)
	{
		if(fuit == 0.0) return;
		fprintf(mFile,"setAttr \".fuit\" %f;\n", fuit);

	}
	void setMaxReactionTemp(float mxrt)
	{
		if(mxrt == 1.0) return;
		fprintf(mFile,"setAttr \".mxrt\" %f;\n", mxrt);

	}
	void setHeatReleased(float hre)
	{
		if(hre == 1.0) return;
		fprintf(mFile,"setAttr \".hre\" %f;\n", hre);

	}
	void setLightReleased(float lre)
	{
		if(lre == 0.0) return;
		fprintf(mFile,"setAttr \".lre\" %f;\n", lre);

	}
	void setLightColor(const float3& lco)
	{
		fprintf(mFile,"setAttr \".lco\" -type \"float3\" ");
		lco.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLightColorR(float lcor)
	{
		if(lcor == 1.0) return;
		fprintf(mFile,"setAttr \".lco.lcor\" %f;\n", lcor);

	}
	void setLightColorG(float lcog)
	{
		if(lcog == 1.0) return;
		fprintf(mFile,"setAttr \".lco.lcog\" %f;\n", lcog);

	}
	void setLightColorB(float lcob)
	{
		if(lcob == 1.0) return;
		fprintf(mFile,"setAttr \".lco.lcob\" %f;\n", lcob);

	}
	void setUsePre70Dynamics(bool updy)
	{
		if(updy == false) return;
		fprintf(mFile,"setAttr \".updy\" %i;\n", updy);

	}
	void setInputData(size_t ind_i,const InputData& ind)
	{
		fprintf(mFile,"setAttr \".ind[%i]\" ",ind_i);
		ind.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputPositions(size_t ind_i,const vectorArray& inp)
	{
		if(inp.size == 0) return;
		fprintf(mFile,"setAttr \".ind[%i].inp\" -type \"vectorArray\" ",ind_i);
		inp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputVelocities(size_t ind_i,const vectorArray& inv)
	{
		if(inv.size == 0) return;
		fprintf(mFile,"setAttr \".ind[%i].inv\" -type \"vectorArray\" ",ind_i);
		inv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputMass(size_t ind_i,const doubleArray& inm)
	{
		if(inm.size == 0) return;
		fprintf(mFile,"setAttr \".ind[%i].inm\" -type \"doubleArray\" ",ind_i);
		inm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMatteOpacityMode(unsigned int mom)
	{
		if(mom == 2) return;
		fprintf(mFile,"setAttr \".mom\" %i;\n", mom);

	}
	void setMatteOpacity(float mog)
	{
		if(mog == 1.0) return;
		fprintf(mFile,"setAttr \".mog\" %f;\n", mog);

	}
	void setSelfShadowing(bool ss)
	{
		if(ss == false) return;
		fprintf(mFile,"setAttr \".ss\" %i;\n", ss);

	}
	void setQuality(float qua)
	{
		if(qua == 1.0) return;
		fprintf(mFile,"setAttr \".qua\" %f;\n", qua);

	}
	void setRenderInterpolator(unsigned int rin)
	{
		if(rin == 0) return;
		fprintf(mFile,"setAttr \".rin\" %i;\n", rin);

	}
	void setColor(size_t cl_i,const Color& cl)
	{
		fprintf(mFile,"setAttr \".cl[%i]\" ",cl_i);
		cl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor_Position(size_t cl_i,float clp)
	{
		if(clp == 0.0) return;
		fprintf(mFile,"setAttr \".cl[%i].clp\" %f;\n", cl_i,clp);

	}
	void setColor_Color(size_t cl_i,const float3& clc)
	{
		fprintf(mFile,"setAttr \".cl[%i].clc\" -type \"float3\" ",cl_i);
		clc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColor_ColorR(size_t cl_i,float clcr)
	{
		if(clcr == 0.0) return;
		fprintf(mFile,"setAttr \".cl[%i].clc.clcr\" %f;\n", cl_i,clcr);

	}
	void setColor_ColorG(size_t cl_i,float clcg)
	{
		if(clcg == 0.0) return;
		fprintf(mFile,"setAttr \".cl[%i].clc.clcg\" %f;\n", cl_i,clcg);

	}
	void setColor_ColorB(size_t cl_i,float clcb)
	{
		if(clcb == 0.0) return;
		fprintf(mFile,"setAttr \".cl[%i].clc.clcb\" %f;\n", cl_i,clcb);

	}
	void setColor_Interp(size_t cl_i,unsigned int cli)
	{
		if(cli == 0) return;
		fprintf(mFile,"setAttr \".cl[%i].cli\" %i;\n", cl_i,cli);

	}
	void setColorInput(unsigned int coi)
	{
		if(coi == 0) return;
		fprintf(mFile,"setAttr \".coi\" %i;\n", coi);

	}
	void setColorInputBias(float cib)
	{
		if(cib == 0.0) return;
		fprintf(mFile,"setAttr \".cib\" %f;\n", cib);

	}
	void setOpacity(size_t opa_i,const Opacity& opa)
	{
		fprintf(mFile,"setAttr \".opa[%i]\" ",opa_i);
		opa.write(mFile);
		fprintf(mFile,";\n");

	}
	void setOpacity_Position(size_t opa_i,float opap)
	{
		if(opap == 0.0) return;
		fprintf(mFile,"setAttr \".opa[%i].opap\" %f;\n", opa_i,opap);

	}
	void setOpacity_FloatValue(size_t opa_i,float opafv)
	{
		if(opafv == 0.0) return;
		fprintf(mFile,"setAttr \".opa[%i].opafv\" %f;\n", opa_i,opafv);

	}
	void setOpacity_Interp(size_t opa_i,unsigned int opai)
	{
		if(opai == 0) return;
		fprintf(mFile,"setAttr \".opa[%i].opai\" %i;\n", opa_i,opai);

	}
	void setOpacityInput(unsigned int opi)
	{
		if(opi == 5) return;
		fprintf(mFile,"setAttr \".opi\" %i;\n", opi);

	}
	void setOpacityInputBias(float oib)
	{
		if(oib == 0.0) return;
		fprintf(mFile,"setAttr \".oib\" %f;\n", oib);

	}
	void setTransparency(const float3& t)
	{
		fprintf(mFile,"setAttr \".t\" -type \"float3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTransparencyR(float tr)
	{
		if(tr == 0.25) return;
		fprintf(mFile,"setAttr \".t.tr\" %f;\n", tr);

	}
	void setTransparencyG(float tg)
	{
		if(tg == 0.25) return;
		fprintf(mFile,"setAttr \".t.tg\" %f;\n", tg);

	}
	void setTransparencyB(float tb)
	{
		if(tb == 0.25) return;
		fprintf(mFile,"setAttr \".t.tb\" %f;\n", tb);

	}
	void setShadowOpacity(float shp)
	{
		if(shp == 0.5) return;
		fprintf(mFile,"setAttr \".shp\" %f;\n", shp);

	}
	void setIncandescence(size_t i_i,const Incandescence& i_)
	{
		fprintf(mFile,"setAttr \".i[%i]\" ",i_i);
		i_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescence_Position(size_t i_i,float ip)
	{
		if(ip == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].ip\" %f;\n", i_i,ip);

	}
	void setIncandescence_Color(size_t i_i,const float3& ic)
	{
		fprintf(mFile,"setAttr \".i[%i].ic\" -type \"float3\" ",i_i);
		ic.write(mFile);
		fprintf(mFile,";\n");

	}
	void setIncandescence_ColorR(size_t i_i,float icr)
	{
		if(icr == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].ic.icr\" %f;\n", i_i,icr);

	}
	void setIncandescence_ColorG(size_t i_i,float icg)
	{
		if(icg == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].ic.icg\" %f;\n", i_i,icg);

	}
	void setIncandescence_ColorB(size_t i_i,float icb)
	{
		if(icb == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].ic.icb\" %f;\n", i_i,icb);

	}
	void setIncandescence_Interp(size_t i_i,unsigned int ii)
	{
		if(ii == 0) return;
		fprintf(mFile,"setAttr \".i[%i].ii\" %i;\n", i_i,ii);

	}
	void setIncandescenceInput(unsigned int ili)
	{
		if(ili == 6) return;
		fprintf(mFile,"setAttr \".ili\" %i;\n", ili);

	}
	void setIncandescenceInputBias(float iib)
	{
		if(iib == 0.0) return;
		fprintf(mFile,"setAttr \".iib\" %f;\n", iib);

	}
	void setGlowIntensity(float gi)
	{
		if(gi == 0.0) return;
		fprintf(mFile,"setAttr \".gi\" %f;\n", gi);

	}
	void setSpecularColor(const float3& spc)
	{
		fprintf(mFile,"setAttr \".spc\" -type \"float3\" ");
		spc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSpecularColorR(float spr)
	{
		if(spr == 0.0) return;
		fprintf(mFile,"setAttr \".spc.spr\" %f;\n", spr);

	}
	void setSpecularColorG(float spg)
	{
		if(spg == 0.0) return;
		fprintf(mFile,"setAttr \".spc.spg\" %f;\n", spg);

	}
	void setSpecularColorB(float spb)
	{
		if(spb == 0.0) return;
		fprintf(mFile,"setAttr \".spc.spb\" %f;\n", spb);

	}
	void setCosinePower(float csp)
	{
		if(csp == 20.0) return;
		fprintf(mFile,"setAttr \".csp\" %f;\n", csp);

	}
	void setEnvironment(size_t env_i,const Environment& env)
	{
		fprintf(mFile,"setAttr \".env[%i]\" ",env_i);
		env.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEnvironment_Position(size_t env_i,float envp)
	{
		if(envp == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envp\" %f;\n", env_i,envp);

	}
	void setEnvironment_Color(size_t env_i,const float3& envc)
	{
		fprintf(mFile,"setAttr \".env[%i].envc\" -type \"float3\" ",env_i);
		envc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEnvironment_ColorR(size_t env_i,float envcr)
	{
		if(envcr == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcr\" %f;\n", env_i,envcr);

	}
	void setEnvironment_ColorG(size_t env_i,float envcg)
	{
		if(envcg == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcg\" %f;\n", env_i,envcg);

	}
	void setEnvironment_ColorB(size_t env_i,float envcb)
	{
		if(envcb == 0.0) return;
		fprintf(mFile,"setAttr \".env[%i].envc.envcb\" %f;\n", env_i,envcb);

	}
	void setEnvironment_Interp(size_t env_i,unsigned int envi)
	{
		if(envi == 0) return;
		fprintf(mFile,"setAttr \".env[%i].envi\" %i;\n", env_i,envi);

	}
	void setDropoffShape(unsigned int dos)
	{
		if(dos == 2) return;
		fprintf(mFile,"setAttr \".dos\" %i;\n", dos);

	}
	void setEdgeDropoff(float edr)
	{
		if(edr == .05) return;
		fprintf(mFile,"setAttr \".edr\" %f;\n", edr);

	}
	void setContrastTolerance(float ctl)
	{
		if(ctl == 0.01) return;
		fprintf(mFile,"setAttr \".ctl\" %f;\n", ctl);

	}
	void setHeightField(bool hfld)
	{
		if(hfld == false) return;
		fprintf(mFile,"setAttr \".hfld\" %i;\n", hfld);

	}
	void setSurfaceRender(bool srr)
	{
		if(srr == false) return;
		fprintf(mFile,"setAttr \".srr\" %i;\n", srr);

	}
	void setSurfaceThreshold(float srt)
	{
		if(srt == 0.01) return;
		fprintf(mFile,"setAttr \".srt\" %f;\n", srt);

	}
	void setSurfaceTolerance(float stl)
	{
		if(stl == 0.1) return;
		fprintf(mFile,"setAttr \".stl\" %f;\n", stl);

	}
	void setSoftSurface(bool ssf)
	{
		if(ssf == false) return;
		fprintf(mFile,"setAttr \".ssf\" %i;\n", ssf);

	}
	void setRefractiveIndex(float rei)
	{
		if(rei == 1.8) return;
		fprintf(mFile,"setAttr \".rei\" %f;\n", rei);

	}
	void setSampleMethod(unsigned int smpm)
	{
		if(smpm == 3) return;
		fprintf(mFile,"setAttr \".smpm\" %i;\n", smpm);

	}
	void setRealLights(bool rl)
	{
		if(rl == true) return;
		fprintf(mFile,"setAttr \".rl\" %i;\n", rl);

	}
	void setDirectionalLight(const float3& dl)
	{
		fprintf(mFile,"setAttr \".dl\" -type \"float3\" ");
		dl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDirectionalLightX(float dlx)
	{
		if(dlx == 0.5) return;
		fprintf(mFile,"setAttr \".dl.dlx\" %f;\n", dlx);

	}
	void setDirectionalLightY(float dly)
	{
		if(dly == 0.8) return;
		fprintf(mFile,"setAttr \".dl.dly\" %f;\n", dly);

	}
	void setDirectionalLightZ(float dlz)
	{
		if(dlz == 0.5) return;
		fprintf(mFile,"setAttr \".dl.dlz\" %f;\n", dlz);

	}
	void setTextureType(unsigned int tty)
	{
		if(tty == 0) return;
		fprintf(mFile,"setAttr \".tty\" %i;\n", tty);

	}
	void setColorTexture(bool ctx)
	{
		if(ctx == false) return;
		fprintf(mFile,"setAttr \".ctx\" %i;\n", ctx);

	}
	void setColorTexGain(float ctxg)
	{
		if(ctxg == 1.0) return;
		fprintf(mFile,"setAttr \".ctxg\" %f;\n", ctxg);

	}
	void setIncandTexture(bool itx)
	{
		if(itx == false) return;
		fprintf(mFile,"setAttr \".itx\" %i;\n", itx);

	}
	void setIncandTexGain(float itxg)
	{
		if(itxg == 1.0) return;
		fprintf(mFile,"setAttr \".itxg\" %f;\n", itxg);

	}
	void setOpacityTexture(bool otx)
	{
		if(otx == false) return;
		fprintf(mFile,"setAttr \".otx\" %i;\n", otx);

	}
	void setOpacityTexGain(float otxg)
	{
		if(otxg == 1.0) return;
		fprintf(mFile,"setAttr \".otxg\" %f;\n", otxg);

	}
	void setInvertTexture(bool ivt)
	{
		if(ivt == false) return;
		fprintf(mFile,"setAttr \".ivt\" %i;\n", ivt);

	}
	void setAmplitude(float a)
	{
		if(a == 1.0) return;
		fprintf(mFile,"setAttr \".a\" %f;\n", a);

	}
	void setRatio(float ra)
	{
		if(ra == 0.707) return;
		fprintf(mFile,"setAttr \".ra\" %f;\n", ra);

	}
	void setThreshold(float th)
	{
		if(th == 0.0) return;
		fprintf(mFile,"setAttr \".th\" %f;\n", th);

	}
	void setTextureScale(const float3& txsc)
	{
		if(txsc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".txsc\" -type \"float3\" ");
		txsc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTextureScaleX(float tscx)
	{
		if(tscx == 0.0) return;
		fprintf(mFile,"setAttr \".txsc.tscx\" %f;\n", tscx);

	}
	void setTextureScaleY(float tscy)
	{
		if(tscy == 0.0) return;
		fprintf(mFile,"setAttr \".txsc.tscy\" %f;\n", tscy);

	}
	void setTextureScaleZ(float tscz)
	{
		if(tscz == 0.0) return;
		fprintf(mFile,"setAttr \".txsc.tscz\" %f;\n", tscz);

	}
	void setTextureOrigin(const float3& tor)
	{
		if(tor == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".tor\" -type \"float3\" ");
		tor.write(mFile);
		fprintf(mFile,";\n");

	}
	void setTextureOriginX(float torx)
	{
		if(torx == 0.0) return;
		fprintf(mFile,"setAttr \".tor.torx\" %f;\n", torx);

	}
	void setTextureOriginY(float tory)
	{
		if(tory == 0.0) return;
		fprintf(mFile,"setAttr \".tor.tory\" %f;\n", tory);

	}
	void setTextureOriginZ(float torz)
	{
		if(torz == 0.0) return;
		fprintf(mFile,"setAttr \".tor.torz\" %f;\n", torz);

	}
	void setDepthMax(short dm)
	{
		if(dm == 2) return;
		fprintf(mFile,"setAttr \".dm\" %i;\n", dm);

	}
	void setFrequency(float fq)
	{
		if(fq == 1.0) return;
		fprintf(mFile,"setAttr \".fq\" %f;\n", fq);

	}
	void setFrequencyRatio(float fr)
	{
		if(fr == 2.0) return;
		fprintf(mFile,"setAttr \".fr\" %f;\n", fr);

	}
	void setInflection(bool in)
	{
		if(in == false) return;
		fprintf(mFile,"setAttr \".in\" %i;\n", in);

	}
	void setTextureTime(float tti)
	{
		if(tti == 0.0) return;
		fprintf(mFile,"setAttr \".tti\" %f;\n", tti);

	}
	void setBillowDensity(float bd)
	{
		if(bd == 1.0) return;
		fprintf(mFile,"setAttr \".bd\" %f;\n", bd);

	}
	void setSpottyness(float sp)
	{
		if(sp == 0.1) return;
		fprintf(mFile,"setAttr \".sp\" %f;\n", sp);

	}
	void setSizeRand(float sr)
	{
		if(sr == 0.0) return;
		fprintf(mFile,"setAttr \".sr\" %f;\n", sr);

	}
	void setRandomness(float rnd)
	{
		if(rnd == 1.0) return;
		fprintf(mFile,"setAttr \".rnd\" %f;\n", rnd);

	}
	void setFalloff(unsigned int falo)
	{
		if(falo == 2) return;
		fprintf(mFile,"setAttr \".falo\" %i;\n", falo);

	}
	void setNumWaves(short nw)
	{
		if(nw == 5) return;
		fprintf(mFile,"setAttr \".nw\" %i;\n", nw);

	}
	void setImplode(float imp)
	{
		if(imp == 0.0) return;
		fprintf(mFile,"setAttr \".imp\" %f;\n", imp);

	}
	void setImplodeCenter(const float3& imc)
	{
		if(imc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".imc\" -type \"float3\" ");
		imc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImplodeCenterX(float imx)
	{
		if(imx == 0.0) return;
		fprintf(mFile,"setAttr \".imc.imx\" %f;\n", imx);

	}
	void setImplodeCenterY(float imy)
	{
		if(imy == 0.0) return;
		fprintf(mFile,"setAttr \".imc.imy\" %f;\n", imy);

	}
	void setImplodeCenterZ(float imz)
	{
		if(imz == 0.0) return;
		fprintf(mFile,"setAttr \".imc.imz\" %f;\n", imz);

	}
	void setCacheDensity(bool cdns)
	{
		if(cdns == true) return;
		fprintf(mFile,"setAttr \".cdns\" %i;\n", cdns);

	}
	void setLoadDensity(bool ldns)
	{
		if(ldns == true) return;
		fprintf(mFile,"setAttr \".ldns\" %i;\n", ldns);

	}
	void setCacheVelocity(bool cvel)
	{
		if(cvel == true) return;
		fprintf(mFile,"setAttr \".cvel\" %i;\n", cvel);

	}
	void setLoadVelocity(bool lvel)
	{
		if(lvel == true) return;
		fprintf(mFile,"setAttr \".lvel\" %i;\n", lvel);

	}
	void setCacheTemperature(bool ctmp)
	{
		if(ctmp == true) return;
		fprintf(mFile,"setAttr \".ctmp\" %i;\n", ctmp);

	}
	void setLoadTemperature(bool ltmp)
	{
		if(ltmp == true) return;
		fprintf(mFile,"setAttr \".ltmp\" %i;\n", ltmp);

	}
	void setCacheColor(bool ccol)
	{
		if(ccol == true) return;
		fprintf(mFile,"setAttr \".ccol\" %i;\n", ccol);

	}
	void setLoadColor(bool lcol)
	{
		if(lcol == true) return;
		fprintf(mFile,"setAttr \".lcol\" %i;\n", lcol);

	}
	void setCacheReaction(bool crea)
	{
		if(crea == true) return;
		fprintf(mFile,"setAttr \".crea\" %i;\n", crea);

	}
	void setLoadReaction(bool lrea)
	{
		if(lrea == true) return;
		fprintf(mFile,"setAttr \".lrea\" %i;\n", lrea);

	}
	void setCacheTextureCoordinates(bool catc)
	{
		if(catc == true) return;
		fprintf(mFile,"setAttr \".catc\" %i;\n", catc);

	}
	void setLoadTextureCoordinates(bool lotc)
	{
		if(lotc == true) return;
		fprintf(mFile,"setAttr \".lotc\" %i;\n", lotc);

	}
	void setCacheFalloff(bool cfal)
	{
		if(cfal == true) return;
		fprintf(mFile,"setAttr \".cfal\" %i;\n", cfal);

	}
	void setLoadFalloff(bool lfal)
	{
		if(lfal == true) return;
		fprintf(mFile,"setAttr \".lfal\" %i;\n", lfal);

	}
	void setCollide(bool cld)
	{
		if(cld == true) return;
		fprintf(mFile,"setAttr \".cld\" %i;\n", cld);

	}
	void setObjectType(char obt)
	{
		if(obt == 2) return;
		fprintf(mFile,"setAttr \".obt\" %;\n", obt);

	}
	void setSurfaceShaderDepth(float susd)
	{
		if(susd == 1.0) return;
		fprintf(mFile,"setAttr \".susd\" %f;\n", susd);

	}
	void setCoordinateSpeed(float csd)
	{
		if(csd == 0.2) return;
		fprintf(mFile,"setAttr \".csd\" %f;\n", csd);

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
		if(mins == 1) return;
		fprintf(mFile,"setAttr \".mrc.mins\" %i;\n", mins);

	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 2) return;
		fprintf(mFile,"setAttr \".mrc.maxs\" %i;\n", maxs);

	}
	void getOutGrid()
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());

	}
	void getCurrentTime()
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());

	}
	void getStartTime()
	{
		fprintf(mFile,"\"%s.sti\"",mName.c_str());

	}
	void getStartFrame()
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());

	}
	void getDisableInteractiveEval()
	{
		fprintf(mFile,"\"%s.die\"",mName.c_str());

	}
	void getIs2d()
	{
		fprintf(mFile,"\"%s.is2\"",mName.c_str());

	}
	void getResolution()
	{
		fprintf(mFile,"\"%s.res\"",mName.c_str());

	}
	void getResolutionW()
	{
		fprintf(mFile,"\"%s.res.rw\"",mName.c_str());

	}
	void getResolutionH()
	{
		fprintf(mFile,"\"%s.res.rh\"",mName.c_str());

	}
	void getResolutionD()
	{
		fprintf(mFile,"\"%s.res.rd\"",mName.c_str());

	}
	void getDimensions()
	{
		fprintf(mFile,"\"%s.dim\"",mName.c_str());

	}
	void getDimensionsW()
	{
		fprintf(mFile,"\"%s.dim.dw\"",mName.c_str());

	}
	void getDimensionsH()
	{
		fprintf(mFile,"\"%s.dim.dh\"",mName.c_str());

	}
	void getDimensionsD()
	{
		fprintf(mFile,"\"%s.dim.dd\"",mName.c_str());

	}
	void getInitialConditions()
	{
		fprintf(mFile,"\"%s.inc\"",mName.c_str());

	}
	void getDoFields()
	{
		fprintf(mFile,"\"%s.dfr\"",mName.c_str());

	}
	void getInputForce(size_t ifc_i)
	{
		fprintf(mFile,"\"%s.ifc[%i]\"",mName.c_str(),ifc_i);

	}
	void getFieldData()
	{
		fprintf(mFile,"\"%s.fd\"",mName.c_str());

	}
	void getFieldDataPosition()
	{
		fprintf(mFile,"\"%s.fd.fdp\"",mName.c_str());

	}
	void getFieldDataVelocity()
	{
		fprintf(mFile,"\"%s.fd.fdv\"",mName.c_str());

	}
	void getFieldDataMass()
	{
		fprintf(mFile,"\"%s.fd.fdm\"",mName.c_str());

	}
	void getFieldDataDeltaTime()
	{
		fprintf(mFile,"\"%s.fd.fdt\"",mName.c_str());

	}
	void getFieldList(size_t fll_i)
	{
		fprintf(mFile,"\"%s.fll[%i]\"",mName.c_str(),fll_i);

	}
	void getFieldFunction(size_t fll_i)
	{
		fprintf(mFile,"\"%s.fll[%i].frf\"",mName.c_str(),fll_i);

	}
	void getFieldFunction_Raw(size_t fll_i)
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfr\"",mName.c_str(),fll_i);

	}
	void getFieldFunction_Inmap(size_t fll_i,size_t frfi_i)
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfi[%i]\"",mName.c_str(),fll_i,frfi_i);

	}
	void getFieldFunction_InmapTo(size_t fll_i,size_t frfi_i)
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfi[%i].frfit\"",mName.c_str(),fll_i,frfi_i);

	}
	void getFieldFunction_InmapFrom(size_t fll_i,size_t frfi_i)
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfi[%i].frfif\"",mName.c_str(),fll_i,frfi_i);

	}
	void getFieldFunction_Outmap(size_t fll_i,size_t frfo_i)
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfo[%i]\"",mName.c_str(),fll_i,frfo_i);

	}
	void getFieldFunction_OutmapTo(size_t fll_i,size_t frfo_i)
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfo[%i].frfot\"",mName.c_str(),fll_i,frfo_i);

	}
	void getFieldFunction_OutmapFrom(size_t fll_i,size_t frfo_i)
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfo[%i].frfof\"",mName.c_str(),fll_i,frfo_i);

	}
	void getDoEmission()
	{
		fprintf(mFile,"\"%s.de\"",mName.c_str());

	}
	void getIsFull()
	{
		fprintf(mFile,"\"%s.ifl\"",mName.c_str());

	}
	void getInheritFactor()
	{
		fprintf(mFile,"\"%s.inh\"",mName.c_str());

	}
	void getSeed(size_t sd_i)
	{
		fprintf(mFile,"\"%s.sd[%i]\"",mName.c_str(),sd_i);

	}
	void getFluidColorEmission(size_t fce_i)
	{
		fprintf(mFile,"\"%s.fce[%i]\"",mName.c_str(),fce_i);

	}
	void getFluidReactantEmission(size_t frm_i)
	{
		fprintf(mFile,"\"%s.frm[%i]\"",mName.c_str(),frm_i);

	}
	void getEmissionList(size_t eml_i)
	{
		fprintf(mFile,"\"%s.eml[%i]\"",mName.c_str(),eml_i);

	}
	void getEmissionFunction(size_t eml_i)
	{
		fprintf(mFile,"\"%s.eml[%i].emf\"",mName.c_str(),eml_i);

	}
	void getEmissionFunction_Raw(size_t eml_i)
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfr\"",mName.c_str(),eml_i);

	}
	void getEmissionFunction_Inmap(size_t eml_i,size_t emfi_i)
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfi[%i]\"",mName.c_str(),eml_i,emfi_i);

	}
	void getEmissionFunction_InmapTo(size_t eml_i,size_t emfi_i)
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfi[%i].emfit\"",mName.c_str(),eml_i,emfi_i);

	}
	void getEmissionFunction_InmapFrom(size_t eml_i,size_t emfi_i)
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfi[%i].emfif\"",mName.c_str(),eml_i,emfi_i);

	}
	void getEmissionFunction_Outmap(size_t eml_i,size_t emfo_i)
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfo[%i]\"",mName.c_str(),eml_i,emfo_i);

	}
	void getEmissionFunction_OutmapTo(size_t eml_i,size_t emfo_i)
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfo[%i].emfot\"",mName.c_str(),eml_i,emfo_i);

	}
	void getEmissionFunction_OutmapFrom(size_t eml_i,size_t emfo_i)
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfo[%i].emfof\"",mName.c_str(),eml_i,emfo_i);

	}
	void getSlices()
	{
		fprintf(mFile,"\"%s.sli\"",mName.c_str());

	}
	void getVoxelQuality()
	{
		fprintf(mFile,"\"%s.vqu\"",mName.c_str());

	}
	void getDrawSubVolume()
	{
		fprintf(mFile,"\"%s.dsv\"",mName.c_str());

	}
	void getSubVolumeCenter()
	{
		fprintf(mFile,"\"%s.svc\"",mName.c_str());

	}
	void getSubVolumeCenterW()
	{
		fprintf(mFile,"\"%s.svc.scw\"",mName.c_str());

	}
	void getSubVolumeCenterH()
	{
		fprintf(mFile,"\"%s.svc.sch\"",mName.c_str());

	}
	void getSubVolumeCenterD()
	{
		fprintf(mFile,"\"%s.svc.scd\"",mName.c_str());

	}
	void getSubVolumeSize()
	{
		fprintf(mFile,"\"%s.svs\"",mName.c_str());

	}
	void getSubVolumeSizeW()
	{
		fprintf(mFile,"\"%s.svs.ssw\"",mName.c_str());

	}
	void getSubVolumeSizeH()
	{
		fprintf(mFile,"\"%s.svs.ssh\"",mName.c_str());

	}
	void getSubVolumeSizeD()
	{
		fprintf(mFile,"\"%s.svs.ssd\"",mName.c_str());

	}
	void getLockDrawAxis()
	{
		fprintf(mFile,"\"%s.lda\"",mName.c_str());

	}
	void getBoundaryDraw()
	{
		fprintf(mFile,"\"%s.bod\"",mName.c_str());

	}
	void getDrawHeads()
	{
		fprintf(mFile,"\"%s.dhd\"",mName.c_str());

	}
	void getVelocityDraw()
	{
		fprintf(mFile,"\"%s.vld\"",mName.c_str());

	}
	void getVelocityDrawLength()
	{
		fprintf(mFile,"\"%s.vdl\"",mName.c_str());

	}
	void getVelocityDrawSkip()
	{
		fprintf(mFile,"\"%s.vds\"",mName.c_str());

	}
	void getShadedDisplay()
	{
		fprintf(mFile,"\"%s.sdp\"",mName.c_str());

	}
	void getOpacityPreviewGain()
	{
		fprintf(mFile,"\"%s.opg\"",mName.c_str());

	}
	void getWireframeDisplay()
	{
		fprintf(mFile,"\"%s.wdp\"",mName.c_str());

	}
	void getNumericDisplay()
	{
		fprintf(mFile,"\"%s.nud\"",mName.c_str());

	}
	void getHardwareSelfShadow()
	{
		fprintf(mFile,"\"%s.hss\"",mName.c_str());

	}
	void getCoordinateMethod()
	{
		fprintf(mFile,"\"%s.cmet\"",mName.c_str());

	}
	void getOverrideTimeStep()
	{
		fprintf(mFile,"\"%s.ots\"",mName.c_str());

	}
	void getSimulationRateScale()
	{
		fprintf(mFile,"\"%s.srs\"",mName.c_str());

	}
	void getGridInterpolator()
	{
		fprintf(mFile,"\"%s.gdi\"",mName.c_str());

	}
	void getSolver()
	{
		fprintf(mFile,"\"%s.sol\"",mName.c_str());

	}
	void getSolverQuality()
	{
		fprintf(mFile,"\"%s.sql\"",mName.c_str());

	}
	void getHighDetailSolve()
	{
		fprintf(mFile,"\"%s.hds\"",mName.c_str());

	}
	void getBoundaryX()
	{
		fprintf(mFile,"\"%s.bndx\"",mName.c_str());

	}
	void getBoundaryY()
	{
		fprintf(mFile,"\"%s.bndy\"",mName.c_str());

	}
	void getBoundaryZ()
	{
		fprintf(mFile,"\"%s.bndz\"",mName.c_str());

	}
	void getMassConversion()
	{
		fprintf(mFile,"\"%s.mcv\"",mName.c_str());

	}
	void getFalloffMethod()
	{
		fprintf(mFile,"\"%s.fmt\"",mName.c_str());

	}
	void getDensityMethod()
	{
		fprintf(mFile,"\"%s.dmt\"",mName.c_str());

	}
	void getDensityGradient()
	{
		fprintf(mFile,"\"%s.dgr\"",mName.c_str());

	}
	void getDensityScale()
	{
		fprintf(mFile,"\"%s.dsc\"",mName.c_str());

	}
	void getDensityDissipation()
	{
		fprintf(mFile,"\"%s.dds\"",mName.c_str());

	}
	void getDensityDiffusion()
	{
		fprintf(mFile,"\"%s.ddf\"",mName.c_str());

	}
	void getConserveMass()
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());

	}
	void getDensityBuoyancy()
	{
		fprintf(mFile,"\"%s.dsb\"",mName.c_str());

	}
	void getGravity()
	{
		fprintf(mFile,"\"%s.grv\"",mName.c_str());

	}
	void getVelocityMethod()
	{
		fprintf(mFile,"\"%s.vmt\"",mName.c_str());

	}
	void getVelocityGradient()
	{
		fprintf(mFile,"\"%s.vgr\"",mName.c_str());

	}
	void getVelocityScale()
	{
		fprintf(mFile,"\"%s.vsc\"",mName.c_str());

	}
	void getVelocityScaleX()
	{
		fprintf(mFile,"\"%s.vsc.vsx\"",mName.c_str());

	}
	void getVelocityScaleY()
	{
		fprintf(mFile,"\"%s.vsc.vsy\"",mName.c_str());

	}
	void getVelocityScaleZ()
	{
		fprintf(mFile,"\"%s.vsc.vsz\"",mName.c_str());

	}
	void getViscosity()
	{
		fprintf(mFile,"\"%s.viy\"",mName.c_str());

	}
	void getFriction()
	{
		fprintf(mFile,"\"%s.fri\"",mName.c_str());

	}
	void getVelocitySwirl()
	{
		fprintf(mFile,"\"%s.vsw\"",mName.c_str());

	}
	void getVelocityDamp()
	{
		fprintf(mFile,"\"%s.vdp\"",mName.c_str());

	}
	void getVelocityAdvect()
	{
		fprintf(mFile,"\"%s.va\"",mName.c_str());

	}
	void getVelocityProject()
	{
		fprintf(mFile,"\"%s.vi\"",mName.c_str());

	}
	void getTurbulenceStrength()
	{
		fprintf(mFile,"\"%s.tst\"",mName.c_str());

	}
	void getTurbulenceFrequency()
	{
		fprintf(mFile,"\"%s.tfr\"",mName.c_str());

	}
	void getTurbulenceSpeed()
	{
		fprintf(mFile,"\"%s.tbs\"",mName.c_str());

	}
	void getTurbulenceRes()
	{
		fprintf(mFile,"\"%s.trs\"",mName.c_str());

	}
	void getTemperatureMethod()
	{
		fprintf(mFile,"\"%s.tmet\"",mName.c_str());

	}
	void getTemperatureGradient()
	{
		fprintf(mFile,"\"%s.tgr\"",mName.c_str());

	}
	void getTemperatureScale()
	{
		fprintf(mFile,"\"%s.tmsc\"",mName.c_str());

	}
	void getTemperatureDissipation()
	{
		fprintf(mFile,"\"%s.tds\"",mName.c_str());

	}
	void getTemperatureDiffusion()
	{
		fprintf(mFile,"\"%s.tdf\"",mName.c_str());

	}
	void getTemperatureTurbulence()
	{
		fprintf(mFile,"\"%s.ttb\"",mName.c_str());

	}
	void getBuoyancy()
	{
		fprintf(mFile,"\"%s.buo\"",mName.c_str());

	}
	void getColorMethod()
	{
		fprintf(mFile,"\"%s.cmt\"",mName.c_str());

	}
	void getColorDissipation()
	{
		fprintf(mFile,"\"%s.cds\"",mName.c_str());

	}
	void getColorDiffusion()
	{
		fprintf(mFile,"\"%s.cdf\"",mName.c_str());

	}
	void getFuelMethod()
	{
		fprintf(mFile,"\"%s.fmet\"",mName.c_str());

	}
	void getFuelGradient()
	{
		fprintf(mFile,"\"%s.fgr\"",mName.c_str());

	}
	void getFuelScale()
	{
		fprintf(mFile,"\"%s.fesc\"",mName.c_str());

	}
	void getReactionSpeed()
	{
		fprintf(mFile,"\"%s.resp\"",mName.c_str());

	}
	void getFuelIgnitionTemp()
	{
		fprintf(mFile,"\"%s.fuit\"",mName.c_str());

	}
	void getMaxReactionTemp()
	{
		fprintf(mFile,"\"%s.mxrt\"",mName.c_str());

	}
	void getHeatReleased()
	{
		fprintf(mFile,"\"%s.hre\"",mName.c_str());

	}
	void getLightReleased()
	{
		fprintf(mFile,"\"%s.lre\"",mName.c_str());

	}
	void getLightColor()
	{
		fprintf(mFile,"\"%s.lco\"",mName.c_str());

	}
	void getLightColorR()
	{
		fprintf(mFile,"\"%s.lco.lcor\"",mName.c_str());

	}
	void getLightColorG()
	{
		fprintf(mFile,"\"%s.lco.lcog\"",mName.c_str());

	}
	void getLightColorB()
	{
		fprintf(mFile,"\"%s.lco.lcob\"",mName.c_str());

	}
	void getUsePre70Dynamics()
	{
		fprintf(mFile,"\"%s.updy\"",mName.c_str());

	}
	void getOutMesh()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getInputData(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i]\"",mName.c_str(),ind_i);

	}
	void getInputPositions(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i].inp\"",mName.c_str(),ind_i);

	}
	void getInputVelocities(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i].inv\"",mName.c_str(),ind_i);

	}
	void getInputMass(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i].inm\"",mName.c_str(),ind_i);

	}
	void getDeltaTime(size_t ind_i)
	{
		fprintf(mFile,"\"%s.ind[%i].dt\"",mName.c_str(),ind_i);

	}
	void getInputForce2(size_t in2_i)
	{
		fprintf(mFile,"\"%s.in2[%i]\"",mName.c_str(),in2_i);

	}
	void getOutputForce(size_t of_i)
	{
		fprintf(mFile,"\"%s.of[%i]\"",mName.c_str(),of_i);

	}
	void getMatteOpacityMode()
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());

	}
	void getMatteOpacity()
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());

	}
	void getMatrixEyeToWorld()
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());

	}
	void getMatrixWorldToObject()
	{
		fprintf(mFile,"\"%s.w2o\"",mName.c_str());

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
	void getRayInstance()
	{
		fprintf(mFile,"\"%s.ryi\"",mName.c_str());

	}
	void getSelfShadowing()
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());

	}
	void getQuality()
	{
		fprintf(mFile,"\"%s.qua\"",mName.c_str());

	}
	void getRenderInterpolator()
	{
		fprintf(mFile,"\"%s.rin\"",mName.c_str());

	}
	void getColor(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i]\"",mName.c_str(),cl_i);

	}
	void getColor_Position(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clp\"",mName.c_str(),cl_i);

	}
	void getColor_Color(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clc\"",mName.c_str(),cl_i);

	}
	void getColor_ColorR(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcr\"",mName.c_str(),cl_i);

	}
	void getColor_ColorG(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcg\"",mName.c_str(),cl_i);

	}
	void getColor_ColorB(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcb\"",mName.c_str(),cl_i);

	}
	void getColor_Interp(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].cli\"",mName.c_str(),cl_i);

	}
	void getColorInput()
	{
		fprintf(mFile,"\"%s.coi\"",mName.c_str());

	}
	void getColorInputBias()
	{
		fprintf(mFile,"\"%s.cib\"",mName.c_str());

	}
	void getOpacity(size_t opa_i)
	{
		fprintf(mFile,"\"%s.opa[%i]\"",mName.c_str(),opa_i);

	}
	void getOpacity_Position(size_t opa_i)
	{
		fprintf(mFile,"\"%s.opa[%i].opap\"",mName.c_str(),opa_i);

	}
	void getOpacity_FloatValue(size_t opa_i)
	{
		fprintf(mFile,"\"%s.opa[%i].opafv\"",mName.c_str(),opa_i);

	}
	void getOpacity_Interp(size_t opa_i)
	{
		fprintf(mFile,"\"%s.opa[%i].opai\"",mName.c_str(),opa_i);

	}
	void getOpacityInput()
	{
		fprintf(mFile,"\"%s.opi\"",mName.c_str());

	}
	void getOpacityInputBias()
	{
		fprintf(mFile,"\"%s.oib\"",mName.c_str());

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
	void getShadowOpacity()
	{
		fprintf(mFile,"\"%s.shp\"",mName.c_str());

	}
	void getIncandescence(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);

	}
	void getIncandescence_Position(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].ip\"",mName.c_str(),i_i);

	}
	void getIncandescence_Color(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].ic\"",mName.c_str(),i_i);

	}
	void getIncandescence_ColorR(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].ic.icr\"",mName.c_str(),i_i);

	}
	void getIncandescence_ColorG(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].ic.icg\"",mName.c_str(),i_i);

	}
	void getIncandescence_ColorB(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].ic.icb\"",mName.c_str(),i_i);

	}
	void getIncandescence_Interp(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].ii\"",mName.c_str(),i_i);

	}
	void getIncandescenceInput()
	{
		fprintf(mFile,"\"%s.ili\"",mName.c_str());

	}
	void getIncandescenceInputBias()
	{
		fprintf(mFile,"\"%s.iib\"",mName.c_str());

	}
	void getGlowIntensity()
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());

	}
	void getSpecularColor()
	{
		fprintf(mFile,"\"%s.spc\"",mName.c_str());

	}
	void getSpecularColorR()
	{
		fprintf(mFile,"\"%s.spc.spr\"",mName.c_str());

	}
	void getSpecularColorG()
	{
		fprintf(mFile,"\"%s.spc.spg\"",mName.c_str());

	}
	void getSpecularColorB()
	{
		fprintf(mFile,"\"%s.spc.spb\"",mName.c_str());

	}
	void getCosinePower()
	{
		fprintf(mFile,"\"%s.csp\"",mName.c_str());

	}
	void getEnvironment(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i]\"",mName.c_str(),env_i);

	}
	void getEnvironment_Position(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envp\"",mName.c_str(),env_i);

	}
	void getEnvironment_Color(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorR(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcr\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorG(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcg\"",mName.c_str(),env_i);

	}
	void getEnvironment_ColorB(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcb\"",mName.c_str(),env_i);

	}
	void getEnvironment_Interp(size_t env_i)
	{
		fprintf(mFile,"\"%s.env[%i].envi\"",mName.c_str(),env_i);

	}
	void getDropoffShape()
	{
		fprintf(mFile,"\"%s.dos\"",mName.c_str());

	}
	void getEdgeDropoff()
	{
		fprintf(mFile,"\"%s.edr\"",mName.c_str());

	}
	void getContrastTolerance()
	{
		fprintf(mFile,"\"%s.ctl\"",mName.c_str());

	}
	void getHeightField()
	{
		fprintf(mFile,"\"%s.hfld\"",mName.c_str());

	}
	void getSurfaceRender()
	{
		fprintf(mFile,"\"%s.srr\"",mName.c_str());

	}
	void getSurfaceThreshold()
	{
		fprintf(mFile,"\"%s.srt\"",mName.c_str());

	}
	void getSurfaceTolerance()
	{
		fprintf(mFile,"\"%s.stl\"",mName.c_str());

	}
	void getSoftSurface()
	{
		fprintf(mFile,"\"%s.ssf\"",mName.c_str());

	}
	void getRefractiveIndex()
	{
		fprintf(mFile,"\"%s.rei\"",mName.c_str());

	}
	void getSampleMethod()
	{
		fprintf(mFile,"\"%s.smpm\"",mName.c_str());

	}
	void getRealLights()
	{
		fprintf(mFile,"\"%s.rl\"",mName.c_str());

	}
	void getDirectionalLight()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
	void getDirectionalLightX()
	{
		fprintf(mFile,"\"%s.dl.dlx\"",mName.c_str());

	}
	void getDirectionalLightY()
	{
		fprintf(mFile,"\"%s.dl.dly\"",mName.c_str());

	}
	void getDirectionalLightZ()
	{
		fprintf(mFile,"\"%s.dl.dlz\"",mName.c_str());

	}
	void getTextureType()
	{
		fprintf(mFile,"\"%s.tty\"",mName.c_str());

	}
	void getColorTexture()
	{
		fprintf(mFile,"\"%s.ctx\"",mName.c_str());

	}
	void getColorTexGain()
	{
		fprintf(mFile,"\"%s.ctxg\"",mName.c_str());

	}
	void getIncandTexture()
	{
		fprintf(mFile,"\"%s.itx\"",mName.c_str());

	}
	void getIncandTexGain()
	{
		fprintf(mFile,"\"%s.itxg\"",mName.c_str());

	}
	void getOpacityTexture()
	{
		fprintf(mFile,"\"%s.otx\"",mName.c_str());

	}
	void getOpacityTexGain()
	{
		fprintf(mFile,"\"%s.otxg\"",mName.c_str());

	}
	void getInvertTexture()
	{
		fprintf(mFile,"\"%s.ivt\"",mName.c_str());

	}
	void getAmplitude()
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());

	}
	void getRatio()
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());

	}
	void getThreshold()
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());

	}
	void getTextureScale()
	{
		fprintf(mFile,"\"%s.txsc\"",mName.c_str());

	}
	void getTextureScaleX()
	{
		fprintf(mFile,"\"%s.txsc.tscx\"",mName.c_str());

	}
	void getTextureScaleY()
	{
		fprintf(mFile,"\"%s.txsc.tscy\"",mName.c_str());

	}
	void getTextureScaleZ()
	{
		fprintf(mFile,"\"%s.txsc.tscz\"",mName.c_str());

	}
	void getTextureOrigin()
	{
		fprintf(mFile,"\"%s.tor\"",mName.c_str());

	}
	void getTextureOriginX()
	{
		fprintf(mFile,"\"%s.tor.torx\"",mName.c_str());

	}
	void getTextureOriginY()
	{
		fprintf(mFile,"\"%s.tor.tory\"",mName.c_str());

	}
	void getTextureOriginZ()
	{
		fprintf(mFile,"\"%s.tor.torz\"",mName.c_str());

	}
	void getDepthMax()
	{
		fprintf(mFile,"\"%s.dm\"",mName.c_str());

	}
	void getFrequency()
	{
		fprintf(mFile,"\"%s.fq\"",mName.c_str());

	}
	void getFrequencyRatio()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getInflection()
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());

	}
	void getTextureTime()
	{
		fprintf(mFile,"\"%s.tti\"",mName.c_str());

	}
	void getBillowDensity()
	{
		fprintf(mFile,"\"%s.bd\"",mName.c_str());

	}
	void getSpottyness()
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());

	}
	void getSizeRand()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getRandomness()
	{
		fprintf(mFile,"\"%s.rnd\"",mName.c_str());

	}
	void getFalloff()
	{
		fprintf(mFile,"\"%s.falo\"",mName.c_str());

	}
	void getNumWaves()
	{
		fprintf(mFile,"\"%s.nw\"",mName.c_str());

	}
	void getImplode()
	{
		fprintf(mFile,"\"%s.imp\"",mName.c_str());

	}
	void getImplodeCenter()
	{
		fprintf(mFile,"\"%s.imc\"",mName.c_str());

	}
	void getImplodeCenterX()
	{
		fprintf(mFile,"\"%s.imc.imx\"",mName.c_str());

	}
	void getImplodeCenterY()
	{
		fprintf(mFile,"\"%s.imc.imy\"",mName.c_str());

	}
	void getImplodeCenterZ()
	{
		fprintf(mFile,"\"%s.imc.imz\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.ocl\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.ocl.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.ocl.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.ocl.ocb\"",mName.c_str());

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
	void getDiskCache()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getDiskCacheIC()
	{
		fprintf(mFile,"\"%s.dcic\"",mName.c_str());

	}
	void getCacheDensity()
	{
		fprintf(mFile,"\"%s.cdns\"",mName.c_str());

	}
	void getLoadDensity()
	{
		fprintf(mFile,"\"%s.ldns\"",mName.c_str());

	}
	void getCacheVelocity()
	{
		fprintf(mFile,"\"%s.cvel\"",mName.c_str());

	}
	void getLoadVelocity()
	{
		fprintf(mFile,"\"%s.lvel\"",mName.c_str());

	}
	void getCacheTemperature()
	{
		fprintf(mFile,"\"%s.ctmp\"",mName.c_str());

	}
	void getLoadTemperature()
	{
		fprintf(mFile,"\"%s.ltmp\"",mName.c_str());

	}
	void getCacheColor()
	{
		fprintf(mFile,"\"%s.ccol\"",mName.c_str());

	}
	void getLoadColor()
	{
		fprintf(mFile,"\"%s.lcol\"",mName.c_str());

	}
	void getCacheReaction()
	{
		fprintf(mFile,"\"%s.crea\"",mName.c_str());

	}
	void getLoadReaction()
	{
		fprintf(mFile,"\"%s.lrea\"",mName.c_str());

	}
	void getCacheTextureCoordinates()
	{
		fprintf(mFile,"\"%s.catc\"",mName.c_str());

	}
	void getLoadTextureCoordinates()
	{
		fprintf(mFile,"\"%s.lotc\"",mName.c_str());

	}
	void getCacheFalloff()
	{
		fprintf(mFile,"\"%s.cfal\"",mName.c_str());

	}
	void getLoadFalloff()
	{
		fprintf(mFile,"\"%s.lfal\"",mName.c_str());

	}
	void getCollide()
	{
		fprintf(mFile,"\"%s.cld\"",mName.c_str());

	}
	void getSurfaceShaderDepth()
	{
		fprintf(mFile,"\"%s.susd\"",mName.c_str());

	}
	void getParticleWeight()
	{
		fprintf(mFile,"\"%s.we\"",mName.c_str());

	}
	void getCoordinateSpeed()
	{
		fprintf(mFile,"\"%s.csd\"",mName.c_str());

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
protected:
	FluidShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_FLUIDSHAPE_H__
