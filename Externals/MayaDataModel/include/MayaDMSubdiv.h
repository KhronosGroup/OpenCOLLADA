/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIV_H__
#define __MayaDM_SUBDIV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSurfaceShape.h"
namespace MayaDM
{
class Subdiv : public SurfaceShape
{
public:
	struct Vertex{
		void write(FILE* file) const
		{
		}
	};
	struct VertexTweak{
		double3* singleVertexTweak;
		void write(FILE* file) const
		{
			size_t size = sizeof(singleVertexTweak)/sizeof(double3);
			for(size_t i=0; i<size; ++i)
			{
				singleVertexTweak[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
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
	Subdiv(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "subdiv"){}
	virtual ~Subdiv(){}
	void setDispVertices(bool dv)
	{
		if(dv == false) return;
		fprintf(mFile,"setAttr \".dv\" %i;\n", dv);

	}
	void setDispEdges(bool de)
	{
		if(de == false) return;
		fprintf(mFile,"setAttr \".de\" %i;\n", de);

	}
	void setDispFaces(bool df)
	{
		if(df == false) return;
		fprintf(mFile,"setAttr \".df\" %i;\n", df);

	}
	void setDispMaps(bool dm)
	{
		if(dm == false) return;
		fprintf(mFile,"setAttr \".dm\" %i;\n", dm);

	}
	void setDispUVBorder(bool db)
	{
		if(db == false) return;
		fprintf(mFile,"setAttr \".db\" %i;\n", db);

	}
	void setDispCreases(bool dcr)
	{
		if(dcr == false) return;
		fprintf(mFile,"setAttr \".dcr\" %i;\n", dcr);

	}
	void setDispGeometry(bool dg)
	{
		if(dg == true) return;
		fprintf(mFile,"setAttr \".dg\" %i;\n", dg);

	}
	void setDispResolution(int dr)
	{
		if(dr == 1) return;
		fprintf(mFile,"setAttr \".dr\" %i;\n", dr);

	}
	void setVertexTweak(size_t vtw_i,const VertexTweak& vtw)
	{
		fprintf(mFile,"setAttr \".vtw[%i]\" ",vtw_i);
		vtw.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSingleVertexTweak(size_t vtw_i,size_t stw_i,const double3& stw)
	{
		fprintf(mFile,"setAttr \".vtw[%i].stw[%i]\" -type \"double3\" ",vtw_i,stw_i);
		stw.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSingleVertexTweak(size_t vtw_i,size_t stw_start,size_t stw_end,double* stw)
	{
		fprintf(mFile,"setAttr \".vtw[%i].stw[%i:%i]\" ", vtw_i,stw_start,stw_end);
		size_t size = (stw_end-stw_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",stw[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void setSingleVertexTweakX(size_t vtw_i,size_t stw_i,double stwx)
	{
		if(stwx == 0) return;
		fprintf(mFile,"setAttr \".vtw[%i].stw[%i].stwx\" %f;\n", vtw_i,stw_i,stwx);

	}
	void setSingleVertexTweakY(size_t vtw_i,size_t stw_i,double stwy)
	{
		if(stwy == 0) return;
		fprintf(mFile,"setAttr \".vtw[%i].stw[%i].stwy\" %f;\n", vtw_i,stw_i,stwy);

	}
	void setSingleVertexTweakZ(size_t vtw_i,size_t stw_i,double stwz)
	{
		if(stwz == 0) return;
		fprintf(mFile,"setAttr \".vtw[%i].stw[%i].stwz\" %f;\n", vtw_i,stw_i,stwz);

	}
	void setNormalsDisplayScale(double ndf)
	{
		if(ndf == 1.0) return;
		fprintf(mFile,"setAttr \".ndf\" %f;\n", ndf);

	}
	void setFormat(unsigned int f)
	{
		if(f == 1) return;
		fprintf(mFile,"setAttr \".f\" %i;\n", f);

	}
	void setDepth(int d)
	{
		if(d == 2) return;
		fprintf(mFile,"setAttr \".d\" %i;\n", d);

	}
	void setSampleCount(int sc)
	{
		if(sc == 4) return;
		fprintf(mFile,"setAttr \".sc\" %i;\n", sc);

	}
	void setDisplayLevel(unsigned int dl)
	{
		if(dl == 0) return;
		fprintf(mFile,"setAttr \".dl\" %i;\n", dl);

	}
	void setDisplayFilter(unsigned int dfl)
	{
		if(dfl == 0) return;
		fprintf(mFile,"setAttr \".dfl\" %i;\n", dfl);

	}
	void setScalingHierarchy(unsigned int sh)
	{
		if(sh == 1) return;
		fprintf(mFile,"setAttr \".sh\" %i;\n", sh);

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
	void getCached()
	{
		fprintf(mFile,"\"%s.cc\"",mName.c_str());

	}
	void getDispVertices()
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());

	}
	void getDispVerticesAsLimitPoints()
	{
		fprintf(mFile,"\"%s.dvl\"",mName.c_str());

	}
	void getLocalizeLimitPointsEdit()
	{
		fprintf(mFile,"\"%s.llp\"",mName.c_str());

	}
	void getDispEdges()
	{
		fprintf(mFile,"\"%s.de\"",mName.c_str());

	}
	void getDispFaces()
	{
		fprintf(mFile,"\"%s.df\"",mName.c_str());

	}
	void getDispMaps()
	{
		fprintf(mFile,"\"%s.dm\"",mName.c_str());

	}
	void getDispUVBorder()
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());

	}
	void getDispCreases()
	{
		fprintf(mFile,"\"%s.dcr\"",mName.c_str());

	}
	void getDispGeometry()
	{
		fprintf(mFile,"\"%s.dg\"",mName.c_str());

	}
	void getDispResolution()
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());

	}
	void getVertex(size_t vt_i)
	{
		fprintf(mFile,"\"%s.vt[%i]\"",mName.c_str(),vt_i);

	}
	void getSingleVertex(size_t vt_i,size_t svt_i)
	{
		fprintf(mFile,"\"%s.vt[%i].svt[%i]\"",mName.c_str(),vt_i,svt_i);

	}
	void getSingleVertexX(size_t vt_i,size_t svt_i)
	{
		fprintf(mFile,"\"%s.vt[%i].svt[%i].svx\"",mName.c_str(),vt_i,svt_i);

	}
	void getSingleVertexY(size_t vt_i,size_t svt_i)
	{
		fprintf(mFile,"\"%s.vt[%i].svt[%i].svy\"",mName.c_str(),vt_i,svt_i);

	}
	void getSingleVertexZ(size_t vt_i,size_t svt_i)
	{
		fprintf(mFile,"\"%s.vt[%i].svt[%i].svz\"",mName.c_str(),vt_i,svt_i);

	}
	void getVertexTweak(size_t vtw_i)
	{
		fprintf(mFile,"\"%s.vtw[%i]\"",mName.c_str(),vtw_i);

	}
	void getSingleVertexTweak(size_t vtw_i,size_t stw_i)
	{
		fprintf(mFile,"\"%s.vtw[%i].stw[%i]\"",mName.c_str(),vtw_i,stw_i);

	}
	void getSingleVertexTweakX(size_t vtw_i,size_t stw_i)
	{
		fprintf(mFile,"\"%s.vtw[%i].stw[%i].stwx\"",mName.c_str(),vtw_i,stw_i);

	}
	void getSingleVertexTweakY(size_t vtw_i,size_t stw_i)
	{
		fprintf(mFile,"\"%s.vtw[%i].stw[%i].stwy\"",mName.c_str(),vtw_i,stw_i);

	}
	void getSingleVertexTweakZ(size_t vtw_i,size_t stw_i)
	{
		fprintf(mFile,"\"%s.vtw[%i].stw[%i].stwz\"",mName.c_str(),vtw_i,stw_i);

	}
	void getOutSubdiv()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getWorldSubdiv(size_t ws_i)
	{
		fprintf(mFile,"\"%s.ws[%i]\"",mName.c_str(),ws_i);

	}
	void getEdgeCrease()
	{
		fprintf(mFile,"\"%s.ecr\"",mName.c_str());

	}
	void getTextureCoord()
	{
		fprintf(mFile,"\"%s.uvs\"",mName.c_str());

	}
	void getFaceUVIds(size_t fuv_i)
	{
		fprintf(mFile,"\"%s.fuv[%i]\"",mName.c_str(),fuv_i);

	}
	void getNormalsDisplayScale()
	{
		fprintf(mFile,"\"%s.ndf\"",mName.c_str());

	}
	void getFormat()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getDepth()
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());

	}
	void getSampleCount()
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());

	}
	void getDisplayLevel()
	{
		fprintf(mFile,"\"%s.dl\"",mName.c_str());

	}
	void getDisplayFilter()
	{
		fprintf(mFile,"\"%s.dfl\"",mName.c_str());

	}
	void getBaseFaceCount()
	{
		fprintf(mFile,"\"%s.bfc\"",mName.c_str());

	}
	void getLevelOneFaceCount()
	{
		fprintf(mFile,"\"%s.ofc\"",mName.c_str());

	}
	void getScalingHierarchy()
	{
		fprintf(mFile,"\"%s.sh\"",mName.c_str());

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
	Subdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIV_H__
