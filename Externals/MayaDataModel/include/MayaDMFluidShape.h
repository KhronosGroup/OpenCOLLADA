/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
			size_t nbFieldFunction_Inmap;
			struct FieldFunction_Outmap{
				short fieldFunction_OutmapTo;
				short fieldFunction_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", fieldFunction_OutmapTo);
					fprintf(file,"%i", fieldFunction_OutmapFrom);
				}
			}* fieldFunction_Outmap;
			size_t nbFieldFunction_Outmap;
			void write(FILE* file) const
			{
				for (size_t i = 0; i<nbFieldFunction_Inmap; ++i)
				{
					fieldFunction_Inmap[i].write(file);
					fprintf(file, " ");
					if (i + 1<nbFieldFunction_Inmap) fprintf(file, " ");
				}
				for (size_t i = 0; i<nbFieldFunction_Outmap; ++i)
				{
					fieldFunction_Outmap[i].write(file);
					if (i + 1<nbFieldFunction_Outmap) fprintf(file, " ");
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
			size_t nbEmissionFunction_Inmap;
			struct EmissionFunction_Outmap{
				short emissionFunction_OutmapTo;
				short emissionFunction_OutmapFrom;
				void write(FILE* file) const
				{
					fprintf(file,"%i ", emissionFunction_OutmapTo);
					fprintf(file,"%i", emissionFunction_OutmapFrom);
				}
			}* emissionFunction_Outmap;
			size_t nbEmissionFunction_Outmap;
			void write(FILE* file) const
			{
				for (size_t i = 0; i<nbEmissionFunction_Inmap; ++i)
				{
					emissionFunction_Inmap[i].write(file);
					fprintf(file, " ");
					if (i + 1<nbEmissionFunction_Inmap) fprintf(file, " ");
				}
				for (size_t i = 0; i<nbEmissionFunction_Outmap; ++i)
				{
					emissionFunction_Outmap[i].write(file);
					if (i + 1<nbEmissionFunction_Outmap) fprintf(file, " ");
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
		double deltaTime;
		void write(FILE* file) const
		{
			inputPositions.write(file);
			fprintf(file, " ");
			inputVelocities.write(file);
			fprintf(file, " ");
			inputMass.write(file);
			fprintf(file, " ");
			fprintf(file,"%f", deltaTime);
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

	FluidShape():SurfaceShape(){}
	FluidShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SurfaceShape(file, name, parent, "fluidShape", shared, create){}
	virtual ~FluidShape(){}

	void setStartFrame(double stf)
	{
		if(stf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".stf\" %f;\n", stf);
	}
	void setDisableInteractiveEval(bool die)
	{
		if(die == false) return;
		fprintf(mFile,"\tsetAttr \".die\" %i;\n", die);
	}
	void setIs2d(bool is2)
	{
		if(is2 == false) return;
		fprintf(mFile,"\tsetAttr \".is2\" %i;\n", is2);
	}
	void setResolution(const Resolution& res)
	{
		fprintf(mFile,"\tsetAttr \".res\" ");
		res.write(mFile);
		fprintf(mFile,";\n");
	}
	void setResolutionW(int rw)
	{
		if(rw == 10) return;
		fprintf(mFile,"\tsetAttr \".res.rw\" %i;\n", rw);
	}
	void setResolutionH(int rh)
	{
		if(rh == 10) return;
		fprintf(mFile,"\tsetAttr \".res.rh\" %i;\n", rh);
	}
	void setResolutionD(int rd)
	{
		if(rd == 10) return;
		fprintf(mFile,"\tsetAttr \".res.rd\" %i;\n", rd);
	}
	void setDimensions(const Dimensions& dim)
	{
		fprintf(mFile,"\tsetAttr \".dim\" ");
		dim.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDimensionsW(double dw)
	{
		if(dw == 3) return;
		fprintf(mFile,"\tsetAttr \".dim.dw\" %f;\n", dw);
	}
	void setDimensionsH(double dh)
	{
		if(dh == 3) return;
		fprintf(mFile,"\tsetAttr \".dim.dh\" %f;\n", dh);
	}
	void setDimensionsD(double dd)
	{
		if(dd == 3) return;
		fprintf(mFile,"\tsetAttr \".dim.dd\" %f;\n", dd);
	}
	void setDoFields(bool dfr)
	{
		if(dfr == true) return;
		fprintf(mFile,"\tsetAttr \".dfr\" %i;\n", dfr);
	}
	void setFieldList(size_t fll_i,const FieldList& fll)
	{
		fprintf(mFile,"\tsetAttr \".fll[%i]\" ",fll_i);
		fll.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFieldList(size_t fll_start,size_t fll_end,FieldList* fll)
	{
		fprintf(mFile,"\tsetAttr \".fll[%i:%i]\" ", fll_start,fll_end);
		size_t size = (fll_end-fll_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fll[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startFieldList(size_t fll_start,size_t fll_end)const
	{
		fprintf(mFile,"\tsetAttr \".fll[%i:%i]\"",fll_start,fll_end);
		fprintf(mFile," -type \"FieldList\" ");
	}
	void appendFieldList(const FieldList& fll)const
	{
		fprintf(mFile," ");
		fll.write(mFile);
	}
	void endFieldList()const
	{
		fprintf(mFile,";\n");
	}
	void setFieldFunction(size_t fll_i,const FieldList::FieldFunction& frf)
	{
		fprintf(mFile,"\tsetAttr \".fll[%i].frf\" ",fll_i);
		frf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFieldFunction_Inmap(size_t fll_i,size_t frfi_i,const FieldList::FieldFunction::FieldFunction_Inmap& frfi)
	{
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfi[%i]\" ",fll_i,frfi_i);
		frfi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFieldFunction_Inmap(size_t fll_i,size_t frfi_start,size_t frfi_end,FieldList::FieldFunction::FieldFunction_Inmap* frfi)
	{
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfi[%i:%i]\" ", fll_i,frfi_start,frfi_end);
		size_t size = (frfi_end-frfi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			frfi[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startFieldFunction_Inmap(size_t fll_i,size_t frfi_start,size_t frfi_end)const
	{
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfi[%i:%i]\"",fll_i,frfi_start,frfi_end);
		fprintf(mFile," -type \"FieldList::FieldFunction::FieldFunction_Inmap\" ");
	}
	void appendFieldFunction_Inmap(const FieldList::FieldFunction::FieldFunction_Inmap& frfi)const
	{
		fprintf(mFile," ");
		frfi.write(mFile);
	}
	void endFieldFunction_Inmap()const
	{
		fprintf(mFile,";\n");
	}
	void setFieldFunction_InmapTo(size_t fll_i,size_t frfi_i,short frfit)
	{
		if(frfit == 0) return;
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfi[%i].frfit\" %i;\n", fll_i,frfi_i,frfit);
	}
	void setFieldFunction_InmapFrom(size_t fll_i,size_t frfi_i,short frfif)
	{
		if(frfif == 0) return;
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfi[%i].frfif\" %i;\n", fll_i,frfi_i,frfif);
	}
	void setFieldFunction_Outmap(size_t fll_i,size_t frfo_i,const FieldList::FieldFunction::FieldFunction_Outmap& frfo)
	{
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfo[%i]\" ",fll_i,frfo_i);
		frfo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFieldFunction_Outmap(size_t fll_i,size_t frfo_start,size_t frfo_end,FieldList::FieldFunction::FieldFunction_Outmap* frfo)
	{
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfo[%i:%i]\" ", fll_i,frfo_start,frfo_end);
		size_t size = (frfo_end-frfo_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			frfo[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startFieldFunction_Outmap(size_t fll_i,size_t frfo_start,size_t frfo_end)const
	{
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfo[%i:%i]\"",fll_i,frfo_start,frfo_end);
		fprintf(mFile," -type \"FieldList::FieldFunction::FieldFunction_Outmap\" ");
	}
	void appendFieldFunction_Outmap(const FieldList::FieldFunction::FieldFunction_Outmap& frfo)const
	{
		fprintf(mFile," ");
		frfo.write(mFile);
	}
	void endFieldFunction_Outmap()const
	{
		fprintf(mFile,";\n");
	}
	void setFieldFunction_OutmapTo(size_t fll_i,size_t frfo_i,short frfot)
	{
		if(frfot == 0) return;
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfo[%i].frfot\" %i;\n", fll_i,frfo_i,frfot);
	}
	void setFieldFunction_OutmapFrom(size_t fll_i,size_t frfo_i,short frfof)
	{
		if(frfof == 0) return;
		fprintf(mFile,"\tsetAttr \".fll[%i].frf.frfo[%i].frfof\" %i;\n", fll_i,frfo_i,frfof);
	}
	void setDoEmission(bool de)
	{
		if(de == true) return;
		fprintf(mFile,"\tsetAttr \".de\" %i;\n", de);
	}
	void setInheritFactor(double inh)
	{
		if(inh == 0.0) return;
		fprintf(mFile,"\tsetAttr \".inh\" %f;\n", inh);
	}
	void setSeed(size_t sd_i,int sd)
	{
		if(sd == 1) return;
		fprintf(mFile,"\tsetAttr \".sd[%i]\" %i;\n", sd_i,sd);
	}
	void setSeed(size_t sd_start,size_t sd_end,int* sd)
	{
		fprintf(mFile,"\tsetAttr \".sd[%i:%i]\" ", sd_start,sd_end);
		size_t size = (sd_end-sd_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",sd[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startSeed(size_t sd_start,size_t sd_end)const
	{
		fprintf(mFile,"\tsetAttr \".sd[%i:%i]\"",sd_start,sd_end);
	}
	void appendSeed(int sd)const
	{
		fprintf(mFile," %i",sd);
	}
	void endSeed()const
	{
		fprintf(mFile,";\n");
	}
	void setEmissionList(size_t eml_i,const EmissionList& eml)
	{
		fprintf(mFile,"\tsetAttr \".eml[%i]\" ",eml_i);
		eml.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEmissionList(size_t eml_start,size_t eml_end,EmissionList* eml)
	{
		fprintf(mFile,"\tsetAttr \".eml[%i:%i]\" ", eml_start,eml_end);
		size_t size = (eml_end-eml_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			eml[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startEmissionList(size_t eml_start,size_t eml_end)const
	{
		fprintf(mFile,"\tsetAttr \".eml[%i:%i]\"",eml_start,eml_end);
		fprintf(mFile," -type \"EmissionList\" ");
	}
	void appendEmissionList(const EmissionList& eml)const
	{
		fprintf(mFile," ");
		eml.write(mFile);
	}
	void endEmissionList()const
	{
		fprintf(mFile,";\n");
	}
	void setEmissionFunction(size_t eml_i,const EmissionList::EmissionFunction& emf)
	{
		fprintf(mFile,"\tsetAttr \".eml[%i].emf\" ",eml_i);
		emf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEmissionFunction_Inmap(size_t eml_i,size_t emfi_i,const EmissionList::EmissionFunction::EmissionFunction_Inmap& emfi)
	{
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfi[%i]\" ",eml_i,emfi_i);
		emfi.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEmissionFunction_Inmap(size_t eml_i,size_t emfi_start,size_t emfi_end,EmissionList::EmissionFunction::EmissionFunction_Inmap* emfi)
	{
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfi[%i:%i]\" ", eml_i,emfi_start,emfi_end);
		size_t size = (emfi_end-emfi_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			emfi[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startEmissionFunction_Inmap(size_t eml_i,size_t emfi_start,size_t emfi_end)const
	{
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfi[%i:%i]\"",eml_i,emfi_start,emfi_end);
		fprintf(mFile," -type \"EmissionList::EmissionFunction::EmissionFunction_Inmap\" ");
	}
	void appendEmissionFunction_Inmap(const EmissionList::EmissionFunction::EmissionFunction_Inmap& emfi)const
	{
		fprintf(mFile," ");
		emfi.write(mFile);
	}
	void endEmissionFunction_Inmap()const
	{
		fprintf(mFile,";\n");
	}
	void setEmissionFunction_InmapTo(size_t eml_i,size_t emfi_i,short emfit)
	{
		if(emfit == 0) return;
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfi[%i].emfit\" %i;\n", eml_i,emfi_i,emfit);
	}
	void setEmissionFunction_InmapFrom(size_t eml_i,size_t emfi_i,short emfif)
	{
		if(emfif == 0) return;
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfi[%i].emfif\" %i;\n", eml_i,emfi_i,emfif);
	}
	void setEmissionFunction_Outmap(size_t eml_i,size_t emfo_i,const EmissionList::EmissionFunction::EmissionFunction_Outmap& emfo)
	{
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfo[%i]\" ",eml_i,emfo_i);
		emfo.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEmissionFunction_Outmap(size_t eml_i,size_t emfo_start,size_t emfo_end,EmissionList::EmissionFunction::EmissionFunction_Outmap* emfo)
	{
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfo[%i:%i]\" ", eml_i,emfo_start,emfo_end);
		size_t size = (emfo_end-emfo_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			emfo[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startEmissionFunction_Outmap(size_t eml_i,size_t emfo_start,size_t emfo_end)const
	{
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfo[%i:%i]\"",eml_i,emfo_start,emfo_end);
		fprintf(mFile," -type \"EmissionList::EmissionFunction::EmissionFunction_Outmap\" ");
	}
	void appendEmissionFunction_Outmap(const EmissionList::EmissionFunction::EmissionFunction_Outmap& emfo)const
	{
		fprintf(mFile," ");
		emfo.write(mFile);
	}
	void endEmissionFunction_Outmap()const
	{
		fprintf(mFile,";\n");
	}
	void setEmissionFunction_OutmapTo(size_t eml_i,size_t emfo_i,short emfot)
	{
		if(emfot == 0) return;
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfo[%i].emfot\" %i;\n", eml_i,emfo_i,emfot);
	}
	void setEmissionFunction_OutmapFrom(size_t eml_i,size_t emfo_i,short emfof)
	{
		if(emfof == 0) return;
		fprintf(mFile,"\tsetAttr \".eml[%i].emf.emfo[%i].emfof\" %i;\n", eml_i,emfo_i,emfof);
	}
	void setSlices(int sli)
	{
		if(sli == 2) return;
		fprintf(mFile,"\tsetAttr \".sli\" %i;\n", sli);
	}
	void setVoxelQuality(unsigned int vqu)
	{
		if(vqu == 0) return;
		fprintf(mFile,"\tsetAttr \".vqu\" %i;\n", vqu);
	}
	void setDrawSubVolume(bool dsv)
	{
		if(dsv == false) return;
		fprintf(mFile,"\tsetAttr \".dsv\" %i;\n", dsv);
	}
	void setSubVolumeCenter(const SubVolumeCenter& svc)
	{
		fprintf(mFile,"\tsetAttr \".svc\" ");
		svc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSubVolumeCenterW(int scw)
	{
		if(scw == -1) return;
		fprintf(mFile,"\tsetAttr \".svc.scw\" %i;\n", scw);
	}
	void setSubVolumeCenterH(int sch)
	{
		if(sch == -1) return;
		fprintf(mFile,"\tsetAttr \".svc.sch\" %i;\n", sch);
	}
	void setSubVolumeCenterD(int scd)
	{
		if(scd == -1) return;
		fprintf(mFile,"\tsetAttr \".svc.scd\" %i;\n", scd);
	}
	void setSubVolumeSize(const SubVolumeSize& svs)
	{
		fprintf(mFile,"\tsetAttr \".svs\" ");
		svs.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSubVolumeSizeW(int ssw)
	{
		if(ssw == -1) return;
		fprintf(mFile,"\tsetAttr \".svs.ssw\" %i;\n", ssw);
	}
	void setSubVolumeSizeH(int ssh)
	{
		if(ssh == -1) return;
		fprintf(mFile,"\tsetAttr \".svs.ssh\" %i;\n", ssh);
	}
	void setSubVolumeSizeD(int ssd)
	{
		if(ssd == -1) return;
		fprintf(mFile,"\tsetAttr \".svs.ssd\" %i;\n", ssd);
	}
	void setBoundaryDraw(unsigned int bod)
	{
		if(bod == 0) return;
		fprintf(mFile,"\tsetAttr \".bod\" %i;\n", bod);
	}
	void setDrawHeads(bool dhd)
	{
		if(dhd == true) return;
		fprintf(mFile,"\tsetAttr \".dhd\" %i;\n", dhd);
	}
	void setVelocityDraw(bool vld)
	{
		if(vld == false) return;
		fprintf(mFile,"\tsetAttr \".vld\" %i;\n", vld);
	}
	void setVelocityDrawLength(double vdl)
	{
		if(vdl == 1) return;
		fprintf(mFile,"\tsetAttr \".vdl\" %f;\n", vdl);
	}
	void setVelocityDrawSkip(int vds)
	{
		if(vds == 1) return;
		fprintf(mFile,"\tsetAttr \".vds\" %i;\n", vds);
	}
	void setShadedDisplay(unsigned int sdp)
	{
		if(sdp == 1) return;
		fprintf(mFile,"\tsetAttr \".sdp\" %i;\n", sdp);
	}
	void setOpacityPreviewGain(float opg)
	{
		if(opg == 0.5) return;
		fprintf(mFile,"\tsetAttr \".opg\" %f;\n", opg);
	}
	void setWireframeDisplay(unsigned int wdp)
	{
		if(wdp == 2) return;
		fprintf(mFile,"\tsetAttr \".wdp\" %i;\n", wdp);
	}
	void setNumericDisplay(unsigned int nud)
	{
		if(nud == 0) return;
		fprintf(mFile,"\tsetAttr \".nud\" %i;\n", nud);
	}
	void setHardwareSelfShadow(bool hss)
	{
		if(hss == true) return;
		fprintf(mFile,"\tsetAttr \".hss\" %i;\n", hss);
	}
	void setCoordinateMethod(unsigned int cmet)
	{
		if(cmet == 0) return;
		fprintf(mFile,"\tsetAttr \".cmet\" %i;\n", cmet);
	}
	void setOverrideTimeStep(double ots)
	{
		if(ots == 1) return;
		fprintf(mFile,"\tsetAttr \".ots\" %f;\n", ots);
	}
	void setSimulationRateScale(float srs)
	{
		if(srs == 1) return;
		fprintf(mFile,"\tsetAttr \".srs\" %f;\n", srs);
	}
	void setGridInterpolator(unsigned int gdi)
	{
		if(gdi == 0) return;
		fprintf(mFile,"\tsetAttr \".gdi\" %i;\n", gdi);
	}
	void setForceDynamics(bool fdn)
	{
		if(fdn == false) return;
		fprintf(mFile,"\tsetAttr \".fdn\" %i;\n", fdn);
	}
	void setSolver(unsigned int sol)
	{
		if(sol == 1) return;
		fprintf(mFile,"\tsetAttr \".sol\" %i;\n", sol);
	}
	void setSolverQuality(int sql)
	{
		if(sql == 20) return;
		fprintf(mFile,"\tsetAttr \".sql\" %i;\n", sql);
	}
	void setHighDetailSolve(unsigned int hds)
	{
		if(hds == 0) return;
		fprintf(mFile,"\tsetAttr \".hds\" %i;\n", hds);
	}
	void setBoundaryX(unsigned int bndx)
	{
		if(bndx == 1) return;
		fprintf(mFile,"\tsetAttr \".bndx\" %i;\n", bndx);
	}
	void setBoundaryY(unsigned int bndy)
	{
		if(bndy == 1) return;
		fprintf(mFile,"\tsetAttr \".bndy\" %i;\n", bndy);
	}
	void setBoundaryZ(unsigned int bndz)
	{
		if(bndz == 1) return;
		fprintf(mFile,"\tsetAttr \".bndz\" %i;\n", bndz);
	}
	void setMassConversion(double mcv)
	{
		if(mcv == 1) return;
		fprintf(mFile,"\tsetAttr \".mcv\" %f;\n", mcv);
	}
	void setFalloffMethod(unsigned int fmt)
	{
		if(fmt == 0) return;
		fprintf(mFile,"\tsetAttr \".fmt\" %i;\n", fmt);
	}
	void setDensityMethod(unsigned int dmt)
	{
		if(dmt == 2) return;
		fprintf(mFile,"\tsetAttr \".dmt\" %i;\n", dmt);
	}
	void setDensityGradient(unsigned int dgr)
	{
		if(dgr == 0) return;
		fprintf(mFile,"\tsetAttr \".dgr\" %i;\n", dgr);
	}
	void setDensityScale(float dsc)
	{
		if(dsc == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dsc\" %f;\n", dsc);
	}
	void setDensityDissipation(double dds)
	{
		if(dds == 0) return;
		fprintf(mFile,"\tsetAttr \".dds\" %f;\n", dds);
	}
	void setDensityDiffusion(double ddf)
	{
		if(ddf == 0) return;
		fprintf(mFile,"\tsetAttr \".ddf\" %f;\n", ddf);
	}
	void setConserveMass(bool cm)
	{
		if(cm == true) return;
		fprintf(mFile,"\tsetAttr \".cm\" %i;\n", cm);
	}
	void setDensityBuoyancy(float dsb)
	{
		if(dsb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".dsb\" %f;\n", dsb);
	}
	void setGravity(float grv)
	{
		if(grv == 9.8) return;
		fprintf(mFile,"\tsetAttr \".grv\" %f;\n", grv);
	}
	void setVelocityMethod(unsigned int vmt)
	{
		if(vmt == 2) return;
		fprintf(mFile,"\tsetAttr \".vmt\" %i;\n", vmt);
	}
	void setVelocityGradient(unsigned int vgr)
	{
		if(vgr == 0) return;
		fprintf(mFile,"\tsetAttr \".vgr\" %i;\n", vgr);
	}
	void setVelocityScale(const float3& vsc)
	{
		if(vsc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".vsc\" -type \"float3\" ");
		vsc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVelocityScaleX(float vsx)
	{
		if(vsx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vsc.vsx\" %f;\n", vsx);
	}
	void setVelocityScaleY(float vsy)
	{
		if(vsy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vsc.vsy\" %f;\n", vsy);
	}
	void setVelocityScaleZ(float vsz)
	{
		if(vsz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vsc.vsz\" %f;\n", vsz);
	}
	void setViscosity(float viy)
	{
		if(viy == 0) return;
		fprintf(mFile,"\tsetAttr \".viy\" %f;\n", viy);
	}
	void setFriction(float fri)
	{
		if(fri == 0) return;
		fprintf(mFile,"\tsetAttr \".fri\" %f;\n", fri);
	}
	void setVelocitySwirl(float vsw)
	{
		if(vsw == 0) return;
		fprintf(mFile,"\tsetAttr \".vsw\" %f;\n", vsw);
	}
	void setVelocityDamp(float vdp)
	{
		if(vdp == 0) return;
		fprintf(mFile,"\tsetAttr \".vdp\" %f;\n", vdp);
	}
	void setVelocityAdvect(bool va)
	{
		if(va == true) return;
		fprintf(mFile,"\tsetAttr \".va\" %i;\n", va);
	}
	void setVelocityProject(bool vi)
	{
		if(vi == true) return;
		fprintf(mFile,"\tsetAttr \".vi\" %i;\n", vi);
	}
	void setTurbulenceStrength(float tst)
	{
		if(tst == 0) return;
		fprintf(mFile,"\tsetAttr \".tst\" %f;\n", tst);
	}
	void setTurbulenceFrequency(float tfr)
	{
		if(tfr == 0.2) return;
		fprintf(mFile,"\tsetAttr \".tfr\" %f;\n", tfr);
	}
	void setTurbulenceSpeed(float tbs)
	{
		if(tbs == .2) return;
		fprintf(mFile,"\tsetAttr \".tbs\" %f;\n", tbs);
	}
	void setTurbulenceRes(int trs)
	{
		if(trs == 10) return;
		fprintf(mFile,"\tsetAttr \".trs\" %i;\n", trs);
	}
	void setTemperatureMethod(unsigned int tmet)
	{
		if(tmet == 0) return;
		fprintf(mFile,"\tsetAttr \".tmet\" %i;\n", tmet);
	}
	void setTemperatureGradient(unsigned int tgr)
	{
		if(tgr == 0) return;
		fprintf(mFile,"\tsetAttr \".tgr\" %i;\n", tgr);
	}
	void setTemperatureScale(float tmsc)
	{
		if(tmsc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".tmsc\" %f;\n", tmsc);
	}
	void setTemperatureDissipation(double tds)
	{
		if(tds == 0.1) return;
		fprintf(mFile,"\tsetAttr \".tds\" %f;\n", tds);
	}
	void setTemperatureDiffusion(double tdf)
	{
		if(tdf == 0.1) return;
		fprintf(mFile,"\tsetAttr \".tdf\" %f;\n", tdf);
	}
	void setTemperatureTurbulence(float ttb)
	{
		if(ttb == 0.1) return;
		fprintf(mFile,"\tsetAttr \".ttb\" %f;\n", ttb);
	}
	void setBuoyancy(float buo)
	{
		if(buo == 3) return;
		fprintf(mFile,"\tsetAttr \".buo\" %f;\n", buo);
	}
	void setColorMethod(unsigned int cmt)
	{
		if(cmt == 0) return;
		fprintf(mFile,"\tsetAttr \".cmt\" %i;\n", cmt);
	}
	void setColorDissipation(double cds)
	{
		if(cds == 0) return;
		fprintf(mFile,"\tsetAttr \".cds\" %f;\n", cds);
	}
	void setColorDiffusion(double cdf)
	{
		if(cdf == 0) return;
		fprintf(mFile,"\tsetAttr \".cdf\" %f;\n", cdf);
	}
	void setFuelMethod(unsigned int fmet)
	{
		if(fmet == 0) return;
		fprintf(mFile,"\tsetAttr \".fmet\" %i;\n", fmet);
	}
	void setFuelGradient(unsigned int fgr)
	{
		if(fgr == 0) return;
		fprintf(mFile,"\tsetAttr \".fgr\" %i;\n", fgr);
	}
	void setFuelScale(float fesc)
	{
		if(fesc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fesc\" %f;\n", fesc);
	}
	void setReactionSpeed(float resp)
	{
		if(resp == 0.05) return;
		fprintf(mFile,"\tsetAttr \".resp\" %f;\n", resp);
	}
	void setFuelIgnitionTemp(float fuit)
	{
		if(fuit == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fuit\" %f;\n", fuit);
	}
	void setMaxReactionTemp(float mxrt)
	{
		if(mxrt == 1.0) return;
		fprintf(mFile,"\tsetAttr \".mxrt\" %f;\n", mxrt);
	}
	void setHeatReleased(float hre)
	{
		if(hre == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hre\" %f;\n", hre);
	}
	void setLightReleased(float lre)
	{
		if(lre == 0.0) return;
		fprintf(mFile,"\tsetAttr \".lre\" %f;\n", lre);
	}
	void setLightColor(const float3& lco)
	{
		fprintf(mFile,"\tsetAttr \".lco\" -type \"float3\" ");
		lco.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLightColorR(float lcor)
	{
		if(lcor == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lco.lcor\" %f;\n", lcor);
	}
	void setLightColorG(float lcog)
	{
		if(lcog == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lco.lcog\" %f;\n", lcog);
	}
	void setLightColorB(float lcob)
	{
		if(lcob == 1.0) return;
		fprintf(mFile,"\tsetAttr \".lco.lcob\" %f;\n", lcob);
	}
	void setUsePre70Dynamics(bool updy)
	{
		if(updy == false) return;
		fprintf(mFile,"\tsetAttr \".updy\" %i;\n", updy);
	}
	void setInputData(size_t ind_i,const InputData& ind)
	{
		fprintf(mFile,"\tsetAttr \".ind[%i]\" ",ind_i);
		ind.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputData(size_t ind_start,size_t ind_end,InputData* ind)
	{
		fprintf(mFile,"\tsetAttr \".ind[%i:%i]\" ", ind_start,ind_end);
		size_t size = (ind_end-ind_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ind[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startInputData(size_t ind_start,size_t ind_end)const
	{
		fprintf(mFile,"\tsetAttr \".ind[%i:%i]\"",ind_start,ind_end);
		fprintf(mFile," -type \"InputData\" ");
	}
	void appendInputData(const InputData& ind)const
	{
		fprintf(mFile," ");
		ind.write(mFile);
	}
	void endInputData()const
	{
		fprintf(mFile,";\n");
	}
	void setInputPositions(size_t ind_i,const vectorArray& inp)
	{
		if(inp.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ind[%i].inp\" -type \"vectorArray\" ",ind_i);
		inp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputVelocities(size_t ind_i,const vectorArray& inv)
	{
		if(inv.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ind[%i].inv\" -type \"vectorArray\" ",ind_i);
		inv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInputMass(size_t ind_i,const doubleArray& inm)
	{
		if(inm.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ind[%i].inm\" -type \"doubleArray\" ",ind_i);
		inm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDeltaTime(size_t ind_i,double dt)
	{
		if(dt == 0) return;
		fprintf(mFile,"\tsetAttr \".ind[%i].dt\" %f;\n", ind_i,dt);
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
	void setSelfShadowing(bool ss)
	{
		if(ss == false) return;
		fprintf(mFile,"\tsetAttr \".ss\" %i;\n", ss);
	}
	void setQuality(float qua)
	{
		if(qua == 1.0) return;
		fprintf(mFile,"\tsetAttr \".qua\" %f;\n", qua);
	}
	void setRenderInterpolator(unsigned int rin)
	{
		if(rin == 0) return;
		fprintf(mFile,"\tsetAttr \".rin\" %i;\n", rin);
	}
	void setColor(size_t cl_i,const Color& cl)
	{
		fprintf(mFile,"\tsetAttr \".cl[%i]\" ",cl_i);
		cl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor(size_t cl_start,size_t cl_end,Color* cl)
	{
		fprintf(mFile,"\tsetAttr \".cl[%i:%i]\" ", cl_start,cl_end);
		size_t size = (cl_end-cl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startColor(size_t cl_start,size_t cl_end)const
	{
		fprintf(mFile,"\tsetAttr \".cl[%i:%i]\"",cl_start,cl_end);
		fprintf(mFile," -type \"Color\" ");
	}
	void appendColor(const Color& cl)const
	{
		fprintf(mFile," ");
		cl.write(mFile);
	}
	void endColor()const
	{
		fprintf(mFile,";\n");
	}
	void setColor_Position(size_t cl_i,float clp)
	{
		if(clp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl[%i].clp\" %f;\n", cl_i,clp);
	}
	void setColor_Color(size_t cl_i,const float3& clc)
	{
		fprintf(mFile,"\tsetAttr \".cl[%i].clc\" -type \"float3\" ",cl_i);
		clc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColor_ColorR(size_t cl_i,float clcr)
	{
		if(clcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl[%i].clc.clcr\" %f;\n", cl_i,clcr);
	}
	void setColor_ColorG(size_t cl_i,float clcg)
	{
		if(clcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl[%i].clc.clcg\" %f;\n", cl_i,clcg);
	}
	void setColor_ColorB(size_t cl_i,float clcb)
	{
		if(clcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cl[%i].clc.clcb\" %f;\n", cl_i,clcb);
	}
	void setColor_Interp(size_t cl_i,unsigned int cli)
	{
		if(cli == 0) return;
		fprintf(mFile,"\tsetAttr \".cl[%i].cli\" %i;\n", cl_i,cli);
	}
	void setColorInput(unsigned int coi)
	{
		if(coi == 0) return;
		fprintf(mFile,"\tsetAttr \".coi\" %i;\n", coi);
	}
	void setColorInputBias(float cib)
	{
		if(cib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cib\" %f;\n", cib);
	}
	void setOpacity(size_t opa_i,const Opacity& opa)
	{
		fprintf(mFile,"\tsetAttr \".opa[%i]\" ",opa_i);
		opa.write(mFile);
		fprintf(mFile,";\n");
	}
	void setOpacity(size_t opa_start,size_t opa_end,Opacity* opa)
	{
		fprintf(mFile,"\tsetAttr \".opa[%i:%i]\" ", opa_start,opa_end);
		size_t size = (opa_end-opa_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			opa[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startOpacity(size_t opa_start,size_t opa_end)const
	{
		fprintf(mFile,"\tsetAttr \".opa[%i:%i]\"",opa_start,opa_end);
		fprintf(mFile," -type \"Opacity\" ");
	}
	void appendOpacity(const Opacity& opa)const
	{
		fprintf(mFile," ");
		opa.write(mFile);
	}
	void endOpacity()const
	{
		fprintf(mFile,";\n");
	}
	void setOpacity_Position(size_t opa_i,float opap)
	{
		if(opap == 0.0) return;
		fprintf(mFile,"\tsetAttr \".opa[%i].opap\" %f;\n", opa_i,opap);
	}
	void setOpacity_FloatValue(size_t opa_i,float opafv)
	{
		if(opafv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".opa[%i].opafv\" %f;\n", opa_i,opafv);
	}
	void setOpacity_Interp(size_t opa_i,unsigned int opai)
	{
		if(opai == 0) return;
		fprintf(mFile,"\tsetAttr \".opa[%i].opai\" %i;\n", opa_i,opai);
	}
	void setOpacityInput(unsigned int opi)
	{
		if(opi == 5) return;
		fprintf(mFile,"\tsetAttr \".opi\" %i;\n", opi);
	}
	void setOpacityInputBias(float oib)
	{
		if(oib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".oib\" %f;\n", oib);
	}
	void setTransparency(const float3& t)
	{
		fprintf(mFile,"\tsetAttr \".t\" -type \"float3\" ");
		t.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTransparencyR(float tr)
	{
		if(tr == 0.25) return;
		fprintf(mFile,"\tsetAttr \".t.tr\" %f;\n", tr);
	}
	void setTransparencyG(float tg)
	{
		if(tg == 0.25) return;
		fprintf(mFile,"\tsetAttr \".t.tg\" %f;\n", tg);
	}
	void setTransparencyB(float tb)
	{
		if(tb == 0.25) return;
		fprintf(mFile,"\tsetAttr \".t.tb\" %f;\n", tb);
	}
	void setShadowOpacity(float shp)
	{
		if(shp == 0.5) return;
		fprintf(mFile,"\tsetAttr \".shp\" %f;\n", shp);
	}
	void setIncandescence(size_t i_i,const Incandescence& i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i]\" ",i_i);
		i_.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescence(size_t i_start,size_t i_end,Incandescence* i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\" ", i_start,i_end);
		size_t size = (i_end-i_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			i_[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startIncandescence(size_t i_start,size_t i_end)const
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\"",i_start,i_end);
		fprintf(mFile," -type \"Incandescence\" ");
	}
	void appendIncandescence(const Incandescence& i)const
	{
		fprintf(mFile," ");
		i.write(mFile);
	}
	void endIncandescence()const
	{
		fprintf(mFile,";\n");
	}
	void setIncandescence_Position(size_t i_i,float ip)
	{
		if(ip == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].ip\" %f;\n", i_i,ip);
	}
	void setIncandescence_Color(size_t i_i,const float3& ic)
	{
		fprintf(mFile,"\tsetAttr \".i[%i].ic\" -type \"float3\" ",i_i);
		ic.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIncandescence_ColorR(size_t i_i,float icr)
	{
		if(icr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].ic.icr\" %f;\n", i_i,icr);
	}
	void setIncandescence_ColorG(size_t i_i,float icg)
	{
		if(icg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].ic.icg\" %f;\n", i_i,icg);
	}
	void setIncandescence_ColorB(size_t i_i,float icb)
	{
		if(icb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].ic.icb\" %f;\n", i_i,icb);
	}
	void setIncandescence_Interp(size_t i_i,unsigned int ii)
	{
		if(ii == 0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].ii\" %i;\n", i_i,ii);
	}
	void setIncandescenceInput(unsigned int ili)
	{
		if(ili == 6) return;
		fprintf(mFile,"\tsetAttr \".ili\" %i;\n", ili);
	}
	void setIncandescenceInputBias(float iib)
	{
		if(iib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".iib\" %f;\n", iib);
	}
	void setGlowIntensity(float gi)
	{
		if(gi == 0.0) return;
		fprintf(mFile,"\tsetAttr \".gi\" %f;\n", gi);
	}
	void setSpecularColor(const float3& spc)
	{
		fprintf(mFile,"\tsetAttr \".spc\" -type \"float3\" ");
		spc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSpecularColorR(float spr)
	{
		if(spr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spc.spr\" %f;\n", spr);
	}
	void setSpecularColorG(float spg)
	{
		if(spg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spc.spg\" %f;\n", spg);
	}
	void setSpecularColorB(float spb)
	{
		if(spb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".spc.spb\" %f;\n", spb);
	}
	void setCosinePower(float csp)
	{
		if(csp == 20.0) return;
		fprintf(mFile,"\tsetAttr \".csp\" %f;\n", csp);
	}
	void setEnvironment(size_t env_i,const Environment& env)
	{
		fprintf(mFile,"\tsetAttr \".env[%i]\" ",env_i);
		env.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEnvironment(size_t env_start,size_t env_end,Environment* env)
	{
		fprintf(mFile,"\tsetAttr \".env[%i:%i]\" ", env_start,env_end);
		size_t size = (env_end-env_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			env[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startEnvironment(size_t env_start,size_t env_end)const
	{
		fprintf(mFile,"\tsetAttr \".env[%i:%i]\"",env_start,env_end);
		fprintf(mFile," -type \"Environment\" ");
	}
	void appendEnvironment(const Environment& env)const
	{
		fprintf(mFile," ");
		env.write(mFile);
	}
	void endEnvironment()const
	{
		fprintf(mFile,";\n");
	}
	void setEnvironment_Position(size_t env_i,float envp)
	{
		if(envp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envp\" %f;\n", env_i,envp);
	}
	void setEnvironment_Color(size_t env_i,const float3& envc)
	{
		fprintf(mFile,"\tsetAttr \".env[%i].envc\" -type \"float3\" ",env_i);
		envc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEnvironment_ColorR(size_t env_i,float envcr)
	{
		if(envcr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envc.envcr\" %f;\n", env_i,envcr);
	}
	void setEnvironment_ColorG(size_t env_i,float envcg)
	{
		if(envcg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envc.envcg\" %f;\n", env_i,envcg);
	}
	void setEnvironment_ColorB(size_t env_i,float envcb)
	{
		if(envcb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envc.envcb\" %f;\n", env_i,envcb);
	}
	void setEnvironment_Interp(size_t env_i,unsigned int envi)
	{
		if(envi == 0) return;
		fprintf(mFile,"\tsetAttr \".env[%i].envi\" %i;\n", env_i,envi);
	}
	void setDropoffShape(unsigned int dos)
	{
		if(dos == 2) return;
		fprintf(mFile,"\tsetAttr \".dos\" %i;\n", dos);
	}
	void setEdgeDropoff(float edr)
	{
		if(edr == .05) return;
		fprintf(mFile,"\tsetAttr \".edr\" %f;\n", edr);
	}
	void setContrastTolerance(float ctl)
	{
		if(ctl == 0.01) return;
		fprintf(mFile,"\tsetAttr \".ctl\" %f;\n", ctl);
	}
	void setHeightField(bool hfld)
	{
		if(hfld == false) return;
		fprintf(mFile,"\tsetAttr \".hfld\" %i;\n", hfld);
	}
	void setSurfaceRender(bool srr)
	{
		if(srr == false) return;
		fprintf(mFile,"\tsetAttr \".srr\" %i;\n", srr);
	}
	void setSurfaceThreshold(float srt)
	{
		if(srt == 0.01) return;
		fprintf(mFile,"\tsetAttr \".srt\" %f;\n", srt);
	}
	void setSurfaceTolerance(float stl)
	{
		if(stl == 0.1) return;
		fprintf(mFile,"\tsetAttr \".stl\" %f;\n", stl);
	}
	void setSoftSurface(bool ssf)
	{
		if(ssf == false) return;
		fprintf(mFile,"\tsetAttr \".ssf\" %i;\n", ssf);
	}
	void setRefractiveIndex(float rei)
	{
		if(rei == 1.8) return;
		fprintf(mFile,"\tsetAttr \".rei\" %f;\n", rei);
	}
	void setSampleMethod(unsigned int smpm)
	{
		if(smpm == 3) return;
		fprintf(mFile,"\tsetAttr \".smpm\" %i;\n", smpm);
	}
	void setRealLights(bool rl)
	{
		if(rl == true) return;
		fprintf(mFile,"\tsetAttr \".rl\" %i;\n", rl);
	}
	void setDirectionalLight(const float3& dl)
	{
		fprintf(mFile,"\tsetAttr \".dl\" -type \"float3\" ");
		dl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDirectionalLightX(float dlx)
	{
		if(dlx == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dl.dlx\" %f;\n", dlx);
	}
	void setDirectionalLightY(float dly)
	{
		if(dly == 0.8) return;
		fprintf(mFile,"\tsetAttr \".dl.dly\" %f;\n", dly);
	}
	void setDirectionalLightZ(float dlz)
	{
		if(dlz == 0.5) return;
		fprintf(mFile,"\tsetAttr \".dl.dlz\" %f;\n", dlz);
	}
	void setTextureType(unsigned int tty)
	{
		if(tty == 0) return;
		fprintf(mFile,"\tsetAttr \".tty\" %i;\n", tty);
	}
	void setColorTexture(bool ctx)
	{
		if(ctx == false) return;
		fprintf(mFile,"\tsetAttr \".ctx\" %i;\n", ctx);
	}
	void setColorTexGain(float ctxg)
	{
		if(ctxg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".ctxg\" %f;\n", ctxg);
	}
	void setIncandTexture(bool itx)
	{
		if(itx == false) return;
		fprintf(mFile,"\tsetAttr \".itx\" %i;\n", itx);
	}
	void setIncandTexGain(float itxg)
	{
		if(itxg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".itxg\" %f;\n", itxg);
	}
	void setOpacityTexture(bool otx)
	{
		if(otx == false) return;
		fprintf(mFile,"\tsetAttr \".otx\" %i;\n", otx);
	}
	void setOpacityTexGain(float otxg)
	{
		if(otxg == 1.0) return;
		fprintf(mFile,"\tsetAttr \".otxg\" %f;\n", otxg);
	}
	void setInvertTexture(bool ivt)
	{
		if(ivt == false) return;
		fprintf(mFile,"\tsetAttr \".ivt\" %i;\n", ivt);
	}
	void setAmplitude(float a)
	{
		if(a == 1.0) return;
		fprintf(mFile,"\tsetAttr \".a\" %f;\n", a);
	}
	void setRatio(float ra)
	{
		if(ra == 0.707) return;
		fprintf(mFile,"\tsetAttr \".ra\" %f;\n", ra);
	}
	void setThreshold(float th)
	{
		if(th == 0.0) return;
		fprintf(mFile,"\tsetAttr \".th\" %f;\n", th);
	}
	void setTextureScale(const float3& txsc)
	{
		if(txsc == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".txsc\" -type \"float3\" ");
		txsc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTextureScaleX(float tscx)
	{
		if(tscx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".txsc.tscx\" %f;\n", tscx);
	}
	void setTextureScaleY(float tscy)
	{
		if(tscy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".txsc.tscy\" %f;\n", tscy);
	}
	void setTextureScaleZ(float tscz)
	{
		if(tscz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".txsc.tscz\" %f;\n", tscz);
	}
	void setTextureOrigin(const float3& tor)
	{
		if(tor == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".tor\" -type \"float3\" ");
		tor.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTextureOriginX(float torx)
	{
		if(torx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tor.torx\" %f;\n", torx);
	}
	void setTextureOriginY(float tory)
	{
		if(tory == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tor.tory\" %f;\n", tory);
	}
	void setTextureOriginZ(float torz)
	{
		if(torz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tor.torz\" %f;\n", torz);
	}
	void setDepthMax(short dm)
	{
		if(dm == 2) return;
		fprintf(mFile,"\tsetAttr \".dm\" %i;\n", dm);
	}
	void setFrequency(float fq)
	{
		if(fq == 1.0) return;
		fprintf(mFile,"\tsetAttr \".fq\" %f;\n", fq);
	}
	void setFrequencyRatio(float fr)
	{
		if(fr == 2.0) return;
		fprintf(mFile,"\tsetAttr \".fr\" %f;\n", fr);
	}
	void setInflection(bool in)
	{
		if(in == false) return;
		fprintf(mFile,"\tsetAttr \".in\" %i;\n", in);
	}
	void setTextureTime(float tti)
	{
		if(tti == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tti\" %f;\n", tti);
	}
	void setBillowDensity(float bd)
	{
		if(bd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".bd\" %f;\n", bd);
	}
	void setSpottyness(float sp)
	{
		if(sp == 0.1) return;
		fprintf(mFile,"\tsetAttr \".sp\" %f;\n", sp);
	}
	void setSizeRand(float sr)
	{
		if(sr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);
	}
	void setRandomness(float rnd)
	{
		if(rnd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".rnd\" %f;\n", rnd);
	}
	void setFalloff(unsigned int falo)
	{
		if(falo == 2) return;
		fprintf(mFile,"\tsetAttr \".falo\" %i;\n", falo);
	}
	void setNumWaves(short nw)
	{
		if(nw == 5) return;
		fprintf(mFile,"\tsetAttr \".nw\" %i;\n", nw);
	}
	void setImplode(float imp)
	{
		if(imp == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imp\" %f;\n", imp);
	}
	void setImplodeCenter(const float3& imc)
	{
		if(imc == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".imc\" -type \"float3\" ");
		imc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setImplodeCenterX(float imx)
	{
		if(imx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imc.imx\" %f;\n", imx);
	}
	void setImplodeCenterY(float imy)
	{
		if(imy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imc.imy\" %f;\n", imy);
	}
	void setImplodeCenterZ(float imz)
	{
		if(imz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".imc.imz\" %f;\n", imz);
	}
	void setCacheDensity(bool cdns)
	{
		if(cdns == true) return;
		fprintf(mFile,"\tsetAttr \".cdns\" %i;\n", cdns);
	}
	void setLoadDensity(bool ldns)
	{
		if(ldns == true) return;
		fprintf(mFile,"\tsetAttr \".ldns\" %i;\n", ldns);
	}
	void setCacheVelocity(bool cvel)
	{
		if(cvel == true) return;
		fprintf(mFile,"\tsetAttr \".cvel\" %i;\n", cvel);
	}
	void setLoadVelocity(bool lvel)
	{
		if(lvel == true) return;
		fprintf(mFile,"\tsetAttr \".lvel\" %i;\n", lvel);
	}
	void setCacheTemperature(bool ctmp)
	{
		if(ctmp == true) return;
		fprintf(mFile,"\tsetAttr \".ctmp\" %i;\n", ctmp);
	}
	void setLoadTemperature(bool ltmp)
	{
		if(ltmp == true) return;
		fprintf(mFile,"\tsetAttr \".ltmp\" %i;\n", ltmp);
	}
	void setCacheColor(bool ccol)
	{
		if(ccol == true) return;
		fprintf(mFile,"\tsetAttr \".ccol\" %i;\n", ccol);
	}
	void setLoadColor(bool lcol)
	{
		if(lcol == true) return;
		fprintf(mFile,"\tsetAttr \".lcol\" %i;\n", lcol);
	}
	void setCacheReaction(bool crea)
	{
		if(crea == true) return;
		fprintf(mFile,"\tsetAttr \".crea\" %i;\n", crea);
	}
	void setLoadReaction(bool lrea)
	{
		if(lrea == true) return;
		fprintf(mFile,"\tsetAttr \".lrea\" %i;\n", lrea);
	}
	void setCacheTextureCoordinates(bool catc)
	{
		if(catc == true) return;
		fprintf(mFile,"\tsetAttr \".catc\" %i;\n", catc);
	}
	void setLoadTextureCoordinates(bool lotc)
	{
		if(lotc == true) return;
		fprintf(mFile,"\tsetAttr \".lotc\" %i;\n", lotc);
	}
	void setCacheFalloff(bool cfal)
	{
		if(cfal == true) return;
		fprintf(mFile,"\tsetAttr \".cfal\" %i;\n", cfal);
	}
	void setLoadFalloff(bool lfal)
	{
		if(lfal == true) return;
		fprintf(mFile,"\tsetAttr \".lfal\" %i;\n", lfal);
	}
	void setCollide(bool cld)
	{
		if(cld == true) return;
		fprintf(mFile,"\tsetAttr \".cld\" %i;\n", cld);
	}
	void setObjectType(char obt)
	{
		if(obt == 2) return;
		fprintf(mFile,"\tsetAttr \".obt\" %;\n", obt);
	}
	void setSurfaceShaderDepth(float susd)
	{
		if(susd == 1.0) return;
		fprintf(mFile,"\tsetAttr \".susd\" %f;\n", susd);
	}
	void setCoordinateSpeed(float csd)
	{
		if(csd == 0.2) return;
		fprintf(mFile,"\tsetAttr \".csd\" %f;\n", csd);
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
		if(mins == 1) return;
		fprintf(mFile,"\tsetAttr \".mrc.mins\" %i;\n", mins);
	}
	void setMiMaxSamples(short maxs)
	{
		if(maxs == 2) return;
		fprintf(mFile,"\tsetAttr \".mrc.maxs\" %i;\n", maxs);
	}
	void getOutGrid()const
	{
		fprintf(mFile,"\"%s.out\"",mName.c_str());
	}
	void getCurrentTime()const
	{
		fprintf(mFile,"\"%s.cti\"",mName.c_str());
	}
	void getStartTime()const
	{
		fprintf(mFile,"\"%s.sti\"",mName.c_str());
	}
	void getStartFrame()const
	{
		fprintf(mFile,"\"%s.stf\"",mName.c_str());
	}
	void getDisableInteractiveEval()const
	{
		fprintf(mFile,"\"%s.die\"",mName.c_str());
	}
	void getIs2d()const
	{
		fprintf(mFile,"\"%s.is2\"",mName.c_str());
	}
	void getResolution()const
	{
		fprintf(mFile,"\"%s.res\"",mName.c_str());
	}
	void getResolutionW()const
	{
		fprintf(mFile,"\"%s.res.rw\"",mName.c_str());
	}
	void getResolutionH()const
	{
		fprintf(mFile,"\"%s.res.rh\"",mName.c_str());
	}
	void getResolutionD()const
	{
		fprintf(mFile,"\"%s.res.rd\"",mName.c_str());
	}
	void getDimensions()const
	{
		fprintf(mFile,"\"%s.dim\"",mName.c_str());
	}
	void getDimensionsW()const
	{
		fprintf(mFile,"\"%s.dim.dw\"",mName.c_str());
	}
	void getDimensionsH()const
	{
		fprintf(mFile,"\"%s.dim.dh\"",mName.c_str());
	}
	void getDimensionsD()const
	{
		fprintf(mFile,"\"%s.dim.dd\"",mName.c_str());
	}
	void getInitialConditions()const
	{
		fprintf(mFile,"\"%s.inc\"",mName.c_str());
	}
	void getDoFields()const
	{
		fprintf(mFile,"\"%s.dfr\"",mName.c_str());
	}
	void getInputForce(size_t ifc_i)const
	{
		fprintf(mFile,"\"%s.ifc[%i]\"",mName.c_str(),ifc_i);
	}
	void getInputForce()const
	{

		fprintf(mFile,"\"%s.ifc\"",mName.c_str());
	}
	void getFieldData()const
	{
		fprintf(mFile,"\"%s.fd\"",mName.c_str());
	}
	void getFieldDataPosition()const
	{
		fprintf(mFile,"\"%s.fd.fdp\"",mName.c_str());
	}
	void getFieldDataVelocity()const
	{
		fprintf(mFile,"\"%s.fd.fdv\"",mName.c_str());
	}
	void getFieldDataMass()const
	{
		fprintf(mFile,"\"%s.fd.fdm\"",mName.c_str());
	}
	void getFieldDataDeltaTime()const
	{
		fprintf(mFile,"\"%s.fd.fdt\"",mName.c_str());
	}
	void getFieldList(size_t fll_i)const
	{
		fprintf(mFile,"\"%s.fll[%i]\"",mName.c_str(),fll_i);
	}
	void getFieldList()const
	{

		fprintf(mFile,"\"%s.fll\"",mName.c_str());
	}
	void getFieldFunction(size_t fll_i)const
	{
		fprintf(mFile,"\"%s.fll[%i].frf\"",mName.c_str(),fll_i);
	}
	void getFieldFunction()const
	{

		fprintf(mFile,"\"%s.fll.frf\"",mName.c_str());
	}
	void getFieldFunction_Raw(size_t fll_i)const
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfr\"",mName.c_str(),fll_i);
	}
	void getFieldFunction_Raw()const
	{

		fprintf(mFile,"\"%s.fll.frf.frfr\"",mName.c_str());
	}
	void getFieldFunction_Inmap(size_t fll_i,size_t frfi_i)const
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfi[%i]\"",mName.c_str(),fll_i,frfi_i);
	}
	void getFieldFunction_Inmap(size_t frfi_i)const
	{

		fprintf(mFile,"\"%s.fll.frf.frfi[%i]\"",mName.c_str(),frfi_i);
	}
	void getFieldFunction_InmapTo(size_t fll_i,size_t frfi_i)const
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfi[%i].frfit\"",mName.c_str(),fll_i,frfi_i);
	}
	void getFieldFunction_InmapTo(size_t frfi_i)const
	{

		fprintf(mFile,"\"%s.fll.frf.frfi[%i].frfit\"",mName.c_str(),frfi_i);
	}
	void getFieldFunction_InmapFrom(size_t fll_i,size_t frfi_i)const
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfi[%i].frfif\"",mName.c_str(),fll_i,frfi_i);
	}
	void getFieldFunction_InmapFrom(size_t frfi_i)const
	{

		fprintf(mFile,"\"%s.fll.frf.frfi[%i].frfif\"",mName.c_str(),frfi_i);
	}
	void getFieldFunction_Outmap(size_t fll_i,size_t frfo_i)const
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfo[%i]\"",mName.c_str(),fll_i,frfo_i);
	}
	void getFieldFunction_Outmap(size_t frfo_i)const
	{

		fprintf(mFile,"\"%s.fll.frf.frfo[%i]\"",mName.c_str(),frfo_i);
	}
	void getFieldFunction_OutmapTo(size_t fll_i,size_t frfo_i)const
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfo[%i].frfot\"",mName.c_str(),fll_i,frfo_i);
	}
	void getFieldFunction_OutmapTo(size_t frfo_i)const
	{

		fprintf(mFile,"\"%s.fll.frf.frfo[%i].frfot\"",mName.c_str(),frfo_i);
	}
	void getFieldFunction_OutmapFrom(size_t fll_i,size_t frfo_i)const
	{
		fprintf(mFile,"\"%s.fll[%i].frf.frfo[%i].frfof\"",mName.c_str(),fll_i,frfo_i);
	}
	void getFieldFunction_OutmapFrom(size_t frfo_i)const
	{

		fprintf(mFile,"\"%s.fll.frf.frfo[%i].frfof\"",mName.c_str(),frfo_i);
	}
	void getDoEmission()const
	{
		fprintf(mFile,"\"%s.de\"",mName.c_str());
	}
	void getIsFull()const
	{
		fprintf(mFile,"\"%s.ifl\"",mName.c_str());
	}
	void getInheritFactor()const
	{
		fprintf(mFile,"\"%s.inh\"",mName.c_str());
	}
	void getSeed(size_t sd_i)const
	{
		fprintf(mFile,"\"%s.sd[%i]\"",mName.c_str(),sd_i);
	}
	void getSeed()const
	{

		fprintf(mFile,"\"%s.sd\"",mName.c_str());
	}
	void getFluidColorEmission(size_t fce_i)const
	{
		fprintf(mFile,"\"%s.fce[%i]\"",mName.c_str(),fce_i);
	}
	void getFluidColorEmission()const
	{

		fprintf(mFile,"\"%s.fce\"",mName.c_str());
	}
	void getFluidReactantEmission(size_t frm_i)const
	{
		fprintf(mFile,"\"%s.frm[%i]\"",mName.c_str(),frm_i);
	}
	void getFluidReactantEmission()const
	{

		fprintf(mFile,"\"%s.frm\"",mName.c_str());
	}
	void getEmissionList(size_t eml_i)const
	{
		fprintf(mFile,"\"%s.eml[%i]\"",mName.c_str(),eml_i);
	}
	void getEmissionList()const
	{

		fprintf(mFile,"\"%s.eml\"",mName.c_str());
	}
	void getEmissionFunction(size_t eml_i)const
	{
		fprintf(mFile,"\"%s.eml[%i].emf\"",mName.c_str(),eml_i);
	}
	void getEmissionFunction()const
	{

		fprintf(mFile,"\"%s.eml.emf\"",mName.c_str());
	}
	void getEmissionFunction_Raw(size_t eml_i)const
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfr\"",mName.c_str(),eml_i);
	}
	void getEmissionFunction_Raw()const
	{

		fprintf(mFile,"\"%s.eml.emf.emfr\"",mName.c_str());
	}
	void getEmissionFunction_Inmap(size_t eml_i,size_t emfi_i)const
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfi[%i]\"",mName.c_str(),eml_i,emfi_i);
	}
	void getEmissionFunction_Inmap(size_t emfi_i)const
	{

		fprintf(mFile,"\"%s.eml.emf.emfi[%i]\"",mName.c_str(),emfi_i);
	}
	void getEmissionFunction_InmapTo(size_t eml_i,size_t emfi_i)const
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfi[%i].emfit\"",mName.c_str(),eml_i,emfi_i);
	}
	void getEmissionFunction_InmapTo(size_t emfi_i)const
	{

		fprintf(mFile,"\"%s.eml.emf.emfi[%i].emfit\"",mName.c_str(),emfi_i);
	}
	void getEmissionFunction_InmapFrom(size_t eml_i,size_t emfi_i)const
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfi[%i].emfif\"",mName.c_str(),eml_i,emfi_i);
	}
	void getEmissionFunction_InmapFrom(size_t emfi_i)const
	{

		fprintf(mFile,"\"%s.eml.emf.emfi[%i].emfif\"",mName.c_str(),emfi_i);
	}
	void getEmissionFunction_Outmap(size_t eml_i,size_t emfo_i)const
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfo[%i]\"",mName.c_str(),eml_i,emfo_i);
	}
	void getEmissionFunction_Outmap(size_t emfo_i)const
	{

		fprintf(mFile,"\"%s.eml.emf.emfo[%i]\"",mName.c_str(),emfo_i);
	}
	void getEmissionFunction_OutmapTo(size_t eml_i,size_t emfo_i)const
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfo[%i].emfot\"",mName.c_str(),eml_i,emfo_i);
	}
	void getEmissionFunction_OutmapTo(size_t emfo_i)const
	{

		fprintf(mFile,"\"%s.eml.emf.emfo[%i].emfot\"",mName.c_str(),emfo_i);
	}
	void getEmissionFunction_OutmapFrom(size_t eml_i,size_t emfo_i)const
	{
		fprintf(mFile,"\"%s.eml[%i].emf.emfo[%i].emfof\"",mName.c_str(),eml_i,emfo_i);
	}
	void getEmissionFunction_OutmapFrom(size_t emfo_i)const
	{

		fprintf(mFile,"\"%s.eml.emf.emfo[%i].emfof\"",mName.c_str(),emfo_i);
	}
	void getSlices()const
	{
		fprintf(mFile,"\"%s.sli\"",mName.c_str());
	}
	void getVoxelQuality()const
	{
		fprintf(mFile,"\"%s.vqu\"",mName.c_str());
	}
	void getDrawSubVolume()const
	{
		fprintf(mFile,"\"%s.dsv\"",mName.c_str());
	}
	void getSubVolumeCenter()const
	{
		fprintf(mFile,"\"%s.svc\"",mName.c_str());
	}
	void getSubVolumeCenterW()const
	{
		fprintf(mFile,"\"%s.svc.scw\"",mName.c_str());
	}
	void getSubVolumeCenterH()const
	{
		fprintf(mFile,"\"%s.svc.sch\"",mName.c_str());
	}
	void getSubVolumeCenterD()const
	{
		fprintf(mFile,"\"%s.svc.scd\"",mName.c_str());
	}
	void getSubVolumeSize()const
	{
		fprintf(mFile,"\"%s.svs\"",mName.c_str());
	}
	void getSubVolumeSizeW()const
	{
		fprintf(mFile,"\"%s.svs.ssw\"",mName.c_str());
	}
	void getSubVolumeSizeH()const
	{
		fprintf(mFile,"\"%s.svs.ssh\"",mName.c_str());
	}
	void getSubVolumeSizeD()const
	{
		fprintf(mFile,"\"%s.svs.ssd\"",mName.c_str());
	}
	void getLockDrawAxis()const
	{
		fprintf(mFile,"\"%s.lda\"",mName.c_str());
	}
	void getBoundaryDraw()const
	{
		fprintf(mFile,"\"%s.bod\"",mName.c_str());
	}
	void getDrawHeads()const
	{
		fprintf(mFile,"\"%s.dhd\"",mName.c_str());
	}
	void getVelocityDraw()const
	{
		fprintf(mFile,"\"%s.vld\"",mName.c_str());
	}
	void getVelocityDrawLength()const
	{
		fprintf(mFile,"\"%s.vdl\"",mName.c_str());
	}
	void getVelocityDrawSkip()const
	{
		fprintf(mFile,"\"%s.vds\"",mName.c_str());
	}
	void getShadedDisplay()const
	{
		fprintf(mFile,"\"%s.sdp\"",mName.c_str());
	}
	void getOpacityPreviewGain()const
	{
		fprintf(mFile,"\"%s.opg\"",mName.c_str());
	}
	void getWireframeDisplay()const
	{
		fprintf(mFile,"\"%s.wdp\"",mName.c_str());
	}
	void getNumericDisplay()const
	{
		fprintf(mFile,"\"%s.nud\"",mName.c_str());
	}
	void getHardwareSelfShadow()const
	{
		fprintf(mFile,"\"%s.hss\"",mName.c_str());
	}
	void getCoordinateMethod()const
	{
		fprintf(mFile,"\"%s.cmet\"",mName.c_str());
	}
	void getOverrideTimeStep()const
	{
		fprintf(mFile,"\"%s.ots\"",mName.c_str());
	}
	void getSimulationRateScale()const
	{
		fprintf(mFile,"\"%s.srs\"",mName.c_str());
	}
	void getGridInterpolator()const
	{
		fprintf(mFile,"\"%s.gdi\"",mName.c_str());
	}
	void getSolver()const
	{
		fprintf(mFile,"\"%s.sol\"",mName.c_str());
	}
	void getSolverQuality()const
	{
		fprintf(mFile,"\"%s.sql\"",mName.c_str());
	}
	void getHighDetailSolve()const
	{
		fprintf(mFile,"\"%s.hds\"",mName.c_str());
	}
	void getBoundaryX()const
	{
		fprintf(mFile,"\"%s.bndx\"",mName.c_str());
	}
	void getBoundaryY()const
	{
		fprintf(mFile,"\"%s.bndy\"",mName.c_str());
	}
	void getBoundaryZ()const
	{
		fprintf(mFile,"\"%s.bndz\"",mName.c_str());
	}
	void getMassConversion()const
	{
		fprintf(mFile,"\"%s.mcv\"",mName.c_str());
	}
	void getFalloffMethod()const
	{
		fprintf(mFile,"\"%s.fmt\"",mName.c_str());
	}
	void getDensityMethod()const
	{
		fprintf(mFile,"\"%s.dmt\"",mName.c_str());
	}
	void getDensityGradient()const
	{
		fprintf(mFile,"\"%s.dgr\"",mName.c_str());
	}
	void getDensityScale()const
	{
		fprintf(mFile,"\"%s.dsc\"",mName.c_str());
	}
	void getDensityDissipation()const
	{
		fprintf(mFile,"\"%s.dds\"",mName.c_str());
	}
	void getDensityDiffusion()const
	{
		fprintf(mFile,"\"%s.ddf\"",mName.c_str());
	}
	void getConserveMass()const
	{
		fprintf(mFile,"\"%s.cm\"",mName.c_str());
	}
	void getDensityBuoyancy()const
	{
		fprintf(mFile,"\"%s.dsb\"",mName.c_str());
	}
	void getGravity()const
	{
		fprintf(mFile,"\"%s.grv\"",mName.c_str());
	}
	void getVelocityMethod()const
	{
		fprintf(mFile,"\"%s.vmt\"",mName.c_str());
	}
	void getVelocityGradient()const
	{
		fprintf(mFile,"\"%s.vgr\"",mName.c_str());
	}
	void getVelocityScale()const
	{
		fprintf(mFile,"\"%s.vsc\"",mName.c_str());
	}
	void getVelocityScaleX()const
	{
		fprintf(mFile,"\"%s.vsc.vsx\"",mName.c_str());
	}
	void getVelocityScaleY()const
	{
		fprintf(mFile,"\"%s.vsc.vsy\"",mName.c_str());
	}
	void getVelocityScaleZ()const
	{
		fprintf(mFile,"\"%s.vsc.vsz\"",mName.c_str());
	}
	void getViscosity()const
	{
		fprintf(mFile,"\"%s.viy\"",mName.c_str());
	}
	void getFriction()const
	{
		fprintf(mFile,"\"%s.fri\"",mName.c_str());
	}
	void getVelocitySwirl()const
	{
		fprintf(mFile,"\"%s.vsw\"",mName.c_str());
	}
	void getVelocityDamp()const
	{
		fprintf(mFile,"\"%s.vdp\"",mName.c_str());
	}
	void getVelocityAdvect()const
	{
		fprintf(mFile,"\"%s.va\"",mName.c_str());
	}
	void getVelocityProject()const
	{
		fprintf(mFile,"\"%s.vi\"",mName.c_str());
	}
	void getTurbulenceStrength()const
	{
		fprintf(mFile,"\"%s.tst\"",mName.c_str());
	}
	void getTurbulenceFrequency()const
	{
		fprintf(mFile,"\"%s.tfr\"",mName.c_str());
	}
	void getTurbulenceSpeed()const
	{
		fprintf(mFile,"\"%s.tbs\"",mName.c_str());
	}
	void getTurbulenceRes()const
	{
		fprintf(mFile,"\"%s.trs\"",mName.c_str());
	}
	void getTemperatureMethod()const
	{
		fprintf(mFile,"\"%s.tmet\"",mName.c_str());
	}
	void getTemperatureGradient()const
	{
		fprintf(mFile,"\"%s.tgr\"",mName.c_str());
	}
	void getTemperatureScale()const
	{
		fprintf(mFile,"\"%s.tmsc\"",mName.c_str());
	}
	void getTemperatureDissipation()const
	{
		fprintf(mFile,"\"%s.tds\"",mName.c_str());
	}
	void getTemperatureDiffusion()const
	{
		fprintf(mFile,"\"%s.tdf\"",mName.c_str());
	}
	void getTemperatureTurbulence()const
	{
		fprintf(mFile,"\"%s.ttb\"",mName.c_str());
	}
	void getBuoyancy()const
	{
		fprintf(mFile,"\"%s.buo\"",mName.c_str());
	}
	void getColorMethod()const
	{
		fprintf(mFile,"\"%s.cmt\"",mName.c_str());
	}
	void getColorDissipation()const
	{
		fprintf(mFile,"\"%s.cds\"",mName.c_str());
	}
	void getColorDiffusion()const
	{
		fprintf(mFile,"\"%s.cdf\"",mName.c_str());
	}
	void getFuelMethod()const
	{
		fprintf(mFile,"\"%s.fmet\"",mName.c_str());
	}
	void getFuelGradient()const
	{
		fprintf(mFile,"\"%s.fgr\"",mName.c_str());
	}
	void getFuelScale()const
	{
		fprintf(mFile,"\"%s.fesc\"",mName.c_str());
	}
	void getReactionSpeed()const
	{
		fprintf(mFile,"\"%s.resp\"",mName.c_str());
	}
	void getFuelIgnitionTemp()const
	{
		fprintf(mFile,"\"%s.fuit\"",mName.c_str());
	}
	void getMaxReactionTemp()const
	{
		fprintf(mFile,"\"%s.mxrt\"",mName.c_str());
	}
	void getHeatReleased()const
	{
		fprintf(mFile,"\"%s.hre\"",mName.c_str());
	}
	void getLightReleased()const
	{
		fprintf(mFile,"\"%s.lre\"",mName.c_str());
	}
	void getLightColor()const
	{
		fprintf(mFile,"\"%s.lco\"",mName.c_str());
	}
	void getLightColorR()const
	{
		fprintf(mFile,"\"%s.lco.lcor\"",mName.c_str());
	}
	void getLightColorG()const
	{
		fprintf(mFile,"\"%s.lco.lcog\"",mName.c_str());
	}
	void getLightColorB()const
	{
		fprintf(mFile,"\"%s.lco.lcob\"",mName.c_str());
	}
	void getUsePre70Dynamics()const
	{
		fprintf(mFile,"\"%s.updy\"",mName.c_str());
	}
	void getOutMesh()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getInputData(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i]\"",mName.c_str(),ind_i);
	}
	void getInputData()const
	{

		fprintf(mFile,"\"%s.ind\"",mName.c_str());
	}
	void getInputPositions(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i].inp\"",mName.c_str(),ind_i);
	}
	void getInputPositions()const
	{

		fprintf(mFile,"\"%s.ind.inp\"",mName.c_str());
	}
	void getInputVelocities(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i].inv\"",mName.c_str(),ind_i);
	}
	void getInputVelocities()const
	{

		fprintf(mFile,"\"%s.ind.inv\"",mName.c_str());
	}
	void getInputMass(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i].inm\"",mName.c_str(),ind_i);
	}
	void getInputMass()const
	{

		fprintf(mFile,"\"%s.ind.inm\"",mName.c_str());
	}
	void getDeltaTime(size_t ind_i)const
	{
		fprintf(mFile,"\"%s.ind[%i].dt\"",mName.c_str(),ind_i);
	}
	void getDeltaTime()const
	{

		fprintf(mFile,"\"%s.ind.dt\"",mName.c_str());
	}
	void getInputForce2(size_t in2_i)const
	{
		fprintf(mFile,"\"%s.in2[%i]\"",mName.c_str(),in2_i);
	}
	void getInputForce2()const
	{

		fprintf(mFile,"\"%s.in2\"",mName.c_str());
	}
	void getOutputForce(size_t of_i)const
	{
		fprintf(mFile,"\"%s.of[%i]\"",mName.c_str(),of_i);
	}
	void getOutputForce()const
	{

		fprintf(mFile,"\"%s.of\"",mName.c_str());
	}
	void getMatteOpacityMode()const
	{
		fprintf(mFile,"\"%s.mom\"",mName.c_str());
	}
	void getMatteOpacity()const
	{
		fprintf(mFile,"\"%s.mog\"",mName.c_str());
	}
	void getFilterSize()const
	{
		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getFilterSizeX()const
	{
		fprintf(mFile,"\"%s.fs.fsx\"",mName.c_str());
	}
	void getFilterSizeY()const
	{
		fprintf(mFile,"\"%s.fs.fsy\"",mName.c_str());
	}
	void getFilterSizeZ()const
	{
		fprintf(mFile,"\"%s.fs.fsz\"",mName.c_str());
	}
	void getMatrixEyeToWorld()const
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());
	}
	void getMatrixWorldToObject()const
	{
		fprintf(mFile,"\"%s.w2o\"",mName.c_str());
	}
	void getPointWorld()const
	{
		fprintf(mFile,"\"%s.pw\"",mName.c_str());
	}
	void getPointWorldX()const
	{
		fprintf(mFile,"\"%s.pw.pwx\"",mName.c_str());
	}
	void getPointWorldY()const
	{
		fprintf(mFile,"\"%s.pw.pwy\"",mName.c_str());
	}
	void getPointWorldZ()const
	{
		fprintf(mFile,"\"%s.pw.pwz\"",mName.c_str());
	}
	void getFarPointWorld()const
	{
		fprintf(mFile,"\"%s.fw\"",mName.c_str());
	}
	void getFarPointWorldX()const
	{
		fprintf(mFile,"\"%s.fw.fwx\"",mName.c_str());
	}
	void getFarPointWorldY()const
	{
		fprintf(mFile,"\"%s.fw.fwy\"",mName.c_str());
	}
	void getFarPointWorldZ()const
	{
		fprintf(mFile,"\"%s.fw.fwz\"",mName.c_str());
	}
	void getPointObj()const
	{
		fprintf(mFile,"\"%s.po\"",mName.c_str());
	}
	void getPointObjX()const
	{
		fprintf(mFile,"\"%s.po.pox\"",mName.c_str());
	}
	void getPointObjY()const
	{
		fprintf(mFile,"\"%s.po.poy\"",mName.c_str());
	}
	void getPointObjZ()const
	{
		fprintf(mFile,"\"%s.po.poz\"",mName.c_str());
	}
	void getFarPointObj()const
	{
		fprintf(mFile,"\"%s.fo\"",mName.c_str());
	}
	void getFarPointObjectX()const
	{
		fprintf(mFile,"\"%s.fo.fox\"",mName.c_str());
	}
	void getFarPointObjectY()const
	{
		fprintf(mFile,"\"%s.fo.foy\"",mName.c_str());
	}
	void getFarPointObjectZ()const
	{
		fprintf(mFile,"\"%s.fo.foz\"",mName.c_str());
	}
	void getRayInstance()const
	{
		fprintf(mFile,"\"%s.ryi\"",mName.c_str());
	}
	void getLightDataArray(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i]\"",mName.c_str(),ltd_i);
	}
	void getLightDataArray()const
	{

		fprintf(mFile,"\"%s.ltd\"",mName.c_str());
	}
	void getLightDirection(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld\"",mName.c_str(),ltd_i);
	}
	void getLightDirection()const
	{

		fprintf(mFile,"\"%s.ltd.ld\"",mName.c_str());
	}
	void getLightDirectionX(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldx\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionX()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldx\"",mName.c_str());
	}
	void getLightDirectionY(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldy\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionY()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldy\"",mName.c_str());
	}
	void getLightDirectionZ(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ld.ldz\"",mName.c_str(),ltd_i);
	}
	void getLightDirectionZ()const
	{

		fprintf(mFile,"\"%s.ltd.ld.ldz\"",mName.c_str());
	}
	void getLightIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li\"",mName.c_str(),ltd_i);
	}
	void getLightIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.li\"",mName.c_str());
	}
	void getLightIntensityR(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lir\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityR()const
	{

		fprintf(mFile,"\"%s.ltd.li.lir\"",mName.c_str());
	}
	void getLightIntensityG(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lig\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityG()const
	{

		fprintf(mFile,"\"%s.ltd.li.lig\"",mName.c_str());
	}
	void getLightIntensityB(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].li.lib\"",mName.c_str(),ltd_i);
	}
	void getLightIntensityB()const
	{

		fprintf(mFile,"\"%s.ltd.li.lib\"",mName.c_str());
	}
	void getLightAmbient(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].la\"",mName.c_str(),ltd_i);
	}
	void getLightAmbient()const
	{

		fprintf(mFile,"\"%s.ltd.la\"",mName.c_str());
	}
	void getLightDiffuse(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ldf\"",mName.c_str(),ltd_i);
	}
	void getLightDiffuse()const
	{

		fprintf(mFile,"\"%s.ltd.ldf\"",mName.c_str());
	}
	void getLightSpecular(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].ls\"",mName.c_str(),ltd_i);
	}
	void getLightSpecular()const
	{

		fprintf(mFile,"\"%s.ltd.ls\"",mName.c_str());
	}
	void getLightShadowFraction(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lsf\"",mName.c_str(),ltd_i);
	}
	void getLightShadowFraction()const
	{

		fprintf(mFile,"\"%s.ltd.lsf\"",mName.c_str());
	}
	void getPreShadowIntensity(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].psi\"",mName.c_str(),ltd_i);
	}
	void getPreShadowIntensity()const
	{

		fprintf(mFile,"\"%s.ltd.psi\"",mName.c_str());
	}
	void getLightBlindData(size_t ltd_i)const
	{
		fprintf(mFile,"\"%s.ltd[%i].lbd\"",mName.c_str(),ltd_i);
	}
	void getLightBlindData()const
	{

		fprintf(mFile,"\"%s.ltd.lbd\"",mName.c_str());
	}
	void getSelfShadowing()const
	{
		fprintf(mFile,"\"%s.ss\"",mName.c_str());
	}
	void getQuality()const
	{
		fprintf(mFile,"\"%s.qua\"",mName.c_str());
	}
	void getRenderInterpolator()const
	{
		fprintf(mFile,"\"%s.rin\"",mName.c_str());
	}
	void getColor(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i]\"",mName.c_str(),cl_i);
	}
	void getColor()const
	{

		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getColor_Position(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i].clp\"",mName.c_str(),cl_i);
	}
	void getColor_Position()const
	{

		fprintf(mFile,"\"%s.cl.clp\"",mName.c_str());
	}
	void getColor_Color(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i].clc\"",mName.c_str(),cl_i);
	}
	void getColor_Color()const
	{

		fprintf(mFile,"\"%s.cl.clc\"",mName.c_str());
	}
	void getColor_ColorR(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcr\"",mName.c_str(),cl_i);
	}
	void getColor_ColorR()const
	{

		fprintf(mFile,"\"%s.cl.clc.clcr\"",mName.c_str());
	}
	void getColor_ColorG(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcg\"",mName.c_str(),cl_i);
	}
	void getColor_ColorG()const
	{

		fprintf(mFile,"\"%s.cl.clc.clcg\"",mName.c_str());
	}
	void getColor_ColorB(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i].clc.clcb\"",mName.c_str(),cl_i);
	}
	void getColor_ColorB()const
	{

		fprintf(mFile,"\"%s.cl.clc.clcb\"",mName.c_str());
	}
	void getColor_Interp(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i].cli\"",mName.c_str(),cl_i);
	}
	void getColor_Interp()const
	{

		fprintf(mFile,"\"%s.cl.cli\"",mName.c_str());
	}
	void getColorInput()const
	{
		fprintf(mFile,"\"%s.coi\"",mName.c_str());
	}
	void getColorInputBias()const
	{
		fprintf(mFile,"\"%s.cib\"",mName.c_str());
	}
	void getOpacity(size_t opa_i)const
	{
		fprintf(mFile,"\"%s.opa[%i]\"",mName.c_str(),opa_i);
	}
	void getOpacity()const
	{

		fprintf(mFile,"\"%s.opa\"",mName.c_str());
	}
	void getOpacity_Position(size_t opa_i)const
	{
		fprintf(mFile,"\"%s.opa[%i].opap\"",mName.c_str(),opa_i);
	}
	void getOpacity_Position()const
	{

		fprintf(mFile,"\"%s.opa.opap\"",mName.c_str());
	}
	void getOpacity_FloatValue(size_t opa_i)const
	{
		fprintf(mFile,"\"%s.opa[%i].opafv\"",mName.c_str(),opa_i);
	}
	void getOpacity_FloatValue()const
	{

		fprintf(mFile,"\"%s.opa.opafv\"",mName.c_str());
	}
	void getOpacity_Interp(size_t opa_i)const
	{
		fprintf(mFile,"\"%s.opa[%i].opai\"",mName.c_str(),opa_i);
	}
	void getOpacity_Interp()const
	{

		fprintf(mFile,"\"%s.opa.opai\"",mName.c_str());
	}
	void getOpacityInput()const
	{
		fprintf(mFile,"\"%s.opi\"",mName.c_str());
	}
	void getOpacityInputBias()const
	{
		fprintf(mFile,"\"%s.oib\"",mName.c_str());
	}
	void getTransparency()const
	{
		fprintf(mFile,"\"%s.t\"",mName.c_str());
	}
	void getTransparencyR()const
	{
		fprintf(mFile,"\"%s.t.tr\"",mName.c_str());
	}
	void getTransparencyG()const
	{
		fprintf(mFile,"\"%s.t.tg\"",mName.c_str());
	}
	void getTransparencyB()const
	{
		fprintf(mFile,"\"%s.t.tb\"",mName.c_str());
	}
	void getShadowOpacity()const
	{
		fprintf(mFile,"\"%s.shp\"",mName.c_str());
	}
	void getIncandescence(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);
	}
	void getIncandescence()const
	{

		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getIncandescence_Position(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].ip\"",mName.c_str(),i_i);
	}
	void getIncandescence_Position()const
	{

		fprintf(mFile,"\"%s.i.ip\"",mName.c_str());
	}
	void getIncandescence_Color(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].ic\"",mName.c_str(),i_i);
	}
	void getIncandescence_Color()const
	{

		fprintf(mFile,"\"%s.i.ic\"",mName.c_str());
	}
	void getIncandescence_ColorR(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].ic.icr\"",mName.c_str(),i_i);
	}
	void getIncandescence_ColorR()const
	{

		fprintf(mFile,"\"%s.i.ic.icr\"",mName.c_str());
	}
	void getIncandescence_ColorG(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].ic.icg\"",mName.c_str(),i_i);
	}
	void getIncandescence_ColorG()const
	{

		fprintf(mFile,"\"%s.i.ic.icg\"",mName.c_str());
	}
	void getIncandescence_ColorB(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].ic.icb\"",mName.c_str(),i_i);
	}
	void getIncandescence_ColorB()const
	{

		fprintf(mFile,"\"%s.i.ic.icb\"",mName.c_str());
	}
	void getIncandescence_Interp(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].ii\"",mName.c_str(),i_i);
	}
	void getIncandescence_Interp()const
	{

		fprintf(mFile,"\"%s.i.ii\"",mName.c_str());
	}
	void getIncandescenceInput()const
	{
		fprintf(mFile,"\"%s.ili\"",mName.c_str());
	}
	void getIncandescenceInputBias()const
	{
		fprintf(mFile,"\"%s.iib\"",mName.c_str());
	}
	void getGlowIntensity()const
	{
		fprintf(mFile,"\"%s.gi\"",mName.c_str());
	}
	void getSpecularColor()const
	{
		fprintf(mFile,"\"%s.spc\"",mName.c_str());
	}
	void getSpecularColorR()const
	{
		fprintf(mFile,"\"%s.spc.spr\"",mName.c_str());
	}
	void getSpecularColorG()const
	{
		fprintf(mFile,"\"%s.spc.spg\"",mName.c_str());
	}
	void getSpecularColorB()const
	{
		fprintf(mFile,"\"%s.spc.spb\"",mName.c_str());
	}
	void getCosinePower()const
	{
		fprintf(mFile,"\"%s.csp\"",mName.c_str());
	}
	void getEnvironment(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i]\"",mName.c_str(),env_i);
	}
	void getEnvironment()const
	{

		fprintf(mFile,"\"%s.env\"",mName.c_str());
	}
	void getEnvironment_Position(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envp\"",mName.c_str(),env_i);
	}
	void getEnvironment_Position()const
	{

		fprintf(mFile,"\"%s.env.envp\"",mName.c_str());
	}
	void getEnvironment_Color(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envc\"",mName.c_str(),env_i);
	}
	void getEnvironment_Color()const
	{

		fprintf(mFile,"\"%s.env.envc\"",mName.c_str());
	}
	void getEnvironment_ColorR(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcr\"",mName.c_str(),env_i);
	}
	void getEnvironment_ColorR()const
	{

		fprintf(mFile,"\"%s.env.envc.envcr\"",mName.c_str());
	}
	void getEnvironment_ColorG(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcg\"",mName.c_str(),env_i);
	}
	void getEnvironment_ColorG()const
	{

		fprintf(mFile,"\"%s.env.envc.envcg\"",mName.c_str());
	}
	void getEnvironment_ColorB(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envc.envcb\"",mName.c_str(),env_i);
	}
	void getEnvironment_ColorB()const
	{

		fprintf(mFile,"\"%s.env.envc.envcb\"",mName.c_str());
	}
	void getEnvironment_Interp(size_t env_i)const
	{
		fprintf(mFile,"\"%s.env[%i].envi\"",mName.c_str(),env_i);
	}
	void getEnvironment_Interp()const
	{

		fprintf(mFile,"\"%s.env.envi\"",mName.c_str());
	}
	void getDropoffShape()const
	{
		fprintf(mFile,"\"%s.dos\"",mName.c_str());
	}
	void getEdgeDropoff()const
	{
		fprintf(mFile,"\"%s.edr\"",mName.c_str());
	}
	void getContrastTolerance()const
	{
		fprintf(mFile,"\"%s.ctl\"",mName.c_str());
	}
	void getHeightField()const
	{
		fprintf(mFile,"\"%s.hfld\"",mName.c_str());
	}
	void getSurfaceRender()const
	{
		fprintf(mFile,"\"%s.srr\"",mName.c_str());
	}
	void getSurfaceThreshold()const
	{
		fprintf(mFile,"\"%s.srt\"",mName.c_str());
	}
	void getSurfaceTolerance()const
	{
		fprintf(mFile,"\"%s.stl\"",mName.c_str());
	}
	void getSoftSurface()const
	{
		fprintf(mFile,"\"%s.ssf\"",mName.c_str());
	}
	void getRefractiveIndex()const
	{
		fprintf(mFile,"\"%s.rei\"",mName.c_str());
	}
	void getSampleMethod()const
	{
		fprintf(mFile,"\"%s.smpm\"",mName.c_str());
	}
	void getRealLights()const
	{
		fprintf(mFile,"\"%s.rl\"",mName.c_str());
	}
	void getDirectionalLight()const
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getDirectionalLightX()const
	{
		fprintf(mFile,"\"%s.dl.dlx\"",mName.c_str());
	}
	void getDirectionalLightY()const
	{
		fprintf(mFile,"\"%s.dl.dly\"",mName.c_str());
	}
	void getDirectionalLightZ()const
	{
		fprintf(mFile,"\"%s.dl.dlz\"",mName.c_str());
	}
	void getTextureType()const
	{
		fprintf(mFile,"\"%s.tty\"",mName.c_str());
	}
	void getColorTexture()const
	{
		fprintf(mFile,"\"%s.ctx\"",mName.c_str());
	}
	void getColorTexGain()const
	{
		fprintf(mFile,"\"%s.ctxg\"",mName.c_str());
	}
	void getIncandTexture()const
	{
		fprintf(mFile,"\"%s.itx\"",mName.c_str());
	}
	void getIncandTexGain()const
	{
		fprintf(mFile,"\"%s.itxg\"",mName.c_str());
	}
	void getOpacityTexture()const
	{
		fprintf(mFile,"\"%s.otx\"",mName.c_str());
	}
	void getOpacityTexGain()const
	{
		fprintf(mFile,"\"%s.otxg\"",mName.c_str());
	}
	void getInvertTexture()const
	{
		fprintf(mFile,"\"%s.ivt\"",mName.c_str());
	}
	void getAmplitude()const
	{
		fprintf(mFile,"\"%s.a\"",mName.c_str());
	}
	void getRatio()const
	{
		fprintf(mFile,"\"%s.ra\"",mName.c_str());
	}
	void getThreshold()const
	{
		fprintf(mFile,"\"%s.th\"",mName.c_str());
	}
	void getTextureScale()const
	{
		fprintf(mFile,"\"%s.txsc\"",mName.c_str());
	}
	void getTextureScaleX()const
	{
		fprintf(mFile,"\"%s.txsc.tscx\"",mName.c_str());
	}
	void getTextureScaleY()const
	{
		fprintf(mFile,"\"%s.txsc.tscy\"",mName.c_str());
	}
	void getTextureScaleZ()const
	{
		fprintf(mFile,"\"%s.txsc.tscz\"",mName.c_str());
	}
	void getTextureOrigin()const
	{
		fprintf(mFile,"\"%s.tor\"",mName.c_str());
	}
	void getTextureOriginX()const
	{
		fprintf(mFile,"\"%s.tor.torx\"",mName.c_str());
	}
	void getTextureOriginY()const
	{
		fprintf(mFile,"\"%s.tor.tory\"",mName.c_str());
	}
	void getTextureOriginZ()const
	{
		fprintf(mFile,"\"%s.tor.torz\"",mName.c_str());
	}
	void getDepthMax()const
	{
		fprintf(mFile,"\"%s.dm\"",mName.c_str());
	}
	void getFrequency()const
	{
		fprintf(mFile,"\"%s.fq\"",mName.c_str());
	}
	void getFrequencyRatio()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getInflection()const
	{
		fprintf(mFile,"\"%s.in\"",mName.c_str());
	}
	void getTextureTime()const
	{
		fprintf(mFile,"\"%s.tti\"",mName.c_str());
	}
	void getBillowDensity()const
	{
		fprintf(mFile,"\"%s.bd\"",mName.c_str());
	}
	void getSpottyness()const
	{
		fprintf(mFile,"\"%s.sp\"",mName.c_str());
	}
	void getSizeRand()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getRandomness()const
	{
		fprintf(mFile,"\"%s.rnd\"",mName.c_str());
	}
	void getFalloff()const
	{
		fprintf(mFile,"\"%s.falo\"",mName.c_str());
	}
	void getNumWaves()const
	{
		fprintf(mFile,"\"%s.nw\"",mName.c_str());
	}
	void getImplode()const
	{
		fprintf(mFile,"\"%s.imp\"",mName.c_str());
	}
	void getImplodeCenter()const
	{
		fprintf(mFile,"\"%s.imc\"",mName.c_str());
	}
	void getImplodeCenterX()const
	{
		fprintf(mFile,"\"%s.imc.imx\"",mName.c_str());
	}
	void getImplodeCenterY()const
	{
		fprintf(mFile,"\"%s.imc.imy\"",mName.c_str());
	}
	void getImplodeCenterZ()const
	{
		fprintf(mFile,"\"%s.imc.imz\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.ocl\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.ocl.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.ocl.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.ocl.ocb\"",mName.c_str());
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
	void getDiskCache()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getDiskCacheIC()const
	{
		fprintf(mFile,"\"%s.dcic\"",mName.c_str());
	}
	void getCacheDensity()const
	{
		fprintf(mFile,"\"%s.cdns\"",mName.c_str());
	}
	void getLoadDensity()const
	{
		fprintf(mFile,"\"%s.ldns\"",mName.c_str());
	}
	void getCacheVelocity()const
	{
		fprintf(mFile,"\"%s.cvel\"",mName.c_str());
	}
	void getLoadVelocity()const
	{
		fprintf(mFile,"\"%s.lvel\"",mName.c_str());
	}
	void getCacheTemperature()const
	{
		fprintf(mFile,"\"%s.ctmp\"",mName.c_str());
	}
	void getLoadTemperature()const
	{
		fprintf(mFile,"\"%s.ltmp\"",mName.c_str());
	}
	void getCacheColor()const
	{
		fprintf(mFile,"\"%s.ccol\"",mName.c_str());
	}
	void getLoadColor()const
	{
		fprintf(mFile,"\"%s.lcol\"",mName.c_str());
	}
	void getCacheReaction()const
	{
		fprintf(mFile,"\"%s.crea\"",mName.c_str());
	}
	void getLoadReaction()const
	{
		fprintf(mFile,"\"%s.lrea\"",mName.c_str());
	}
	void getCacheTextureCoordinates()const
	{
		fprintf(mFile,"\"%s.catc\"",mName.c_str());
	}
	void getLoadTextureCoordinates()const
	{
		fprintf(mFile,"\"%s.lotc\"",mName.c_str());
	}
	void getCacheFalloff()const
	{
		fprintf(mFile,"\"%s.cfal\"",mName.c_str());
	}
	void getLoadFalloff()const
	{
		fprintf(mFile,"\"%s.lfal\"",mName.c_str());
	}
	void getCollisionData()const
	{
		fprintf(mFile,"\"%s.cda\"",mName.c_str());
	}
	void getCollisionGeometry(size_t cge_i)const
	{
		fprintf(mFile,"\"%s.cda.cge[%i]\"",mName.c_str(),cge_i);
	}
	void getCollisionResilience(size_t crs_i)const
	{
		fprintf(mFile,"\"%s.cda.crs[%i]\"",mName.c_str(),crs_i);
	}
	void getCollisionFriction(size_t cfr_i)const
	{
		fprintf(mFile,"\"%s.cda.cfr[%i]\"",mName.c_str(),cfr_i);
	}
	void getCollide()const
	{
		fprintf(mFile,"\"%s.cld\"",mName.c_str());
	}
	void getObjectType()const
	{
		fprintf(mFile,"\"%s.obt\"",mName.c_str());
	}
	void getSurfaceShaderDepth()const
	{
		fprintf(mFile,"\"%s.susd\"",mName.c_str());
	}
	void getParticleWeight()const
	{
		fprintf(mFile,"\"%s.we\"",mName.c_str());
	}
	void getCoordinateSpeed()const
	{
		fprintf(mFile,"\"%s.csd\"",mName.c_str());
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
protected:
	FluidShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SurfaceShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FLUIDSHAPE_H__
