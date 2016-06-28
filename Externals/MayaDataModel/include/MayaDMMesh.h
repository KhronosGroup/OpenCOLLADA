/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MESH_H__
#define __MayaDM_MESH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSurfaceShape.h"
namespace MayaDM
{
class Mesh : public SurfaceShape
{
public:
	struct Colors{
		float colorR;
		float colorG;
		float colorB;
		float colorA;
		void write(FILE* file) const
		{
			fprintf(file,"%f ", colorR);
			fprintf(file,"%f ", colorG);
			fprintf(file,"%f ", colorB);
			fprintf(file,"%f", colorA);
		}
	};
	struct ColorPerVertex{
		struct VertexColor{
			float3 vertexColorRGB;
			float vertexAlpha;
			struct VertexFaceColor{
				float3 vertexFaceColorRGB;
				float vertexFaceAlpha;
				void write(FILE* file) const
				{
					vertexFaceColorRGB.write(file);
					fprintf(file, " ");
					fprintf(file,"%f", vertexFaceAlpha);
				}
			}* vertexFaceColor;
			size_t nbVertexFaceColor;
			void write(FILE* file) const
			{
				vertexColorRGB.write(file);
				fprintf(file, " ");
				fprintf(file,"%f ", vertexAlpha);
				for (size_t i = 0; i<nbVertexFaceColor; ++i)
				{
					vertexFaceColor[i].write(file);
					if (i + 1<nbVertexFaceColor) fprintf(file, " ");
				}
			}
		}* vertexColor;
		size_t nbVertexColor;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbVertexColor; ++i)
			{
				vertexColor[i].write(file);
				if (i + 1<nbVertexColor) fprintf(file, " ");
			}
		}
	};
	struct NormalPerVertex{
		struct VertexNormal{
			float3 vertexNormalXYZ;
			struct VertexFaceNormal{
				float3 vertexFaceNormalXYZ;
				void write(FILE* file) const
				{
					vertexFaceNormalXYZ.write(file);
				}
			}* vertexFaceNormal;
			size_t nbVertexFaceNormal;
			void write(FILE* file) const
			{
				vertexNormalXYZ.write(file);
				fprintf(file, " ");
				for (size_t i = 0; i<nbVertexFaceNormal; ++i)
				{
					vertexFaceNormal[i].write(file);
					if (i + 1<nbVertexFaceNormal) fprintf(file, " ");
				}
			}
		}* vertexNormal;
		size_t nbVertexNormal;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbVertexNormal; ++i)
			{
				vertexNormal[i].write(file);
				if (i + 1<nbVertexNormal) fprintf(file, " ");
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

	Mesh():SurfaceShape(){}
	Mesh(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:SurfaceShape(file, name, parent, "mesh", shared, create){}
	virtual ~Mesh(){}

	void setOutMesh(const mesh& o)
	{
		fprintf(mFile,"\tsetAttr \".o\" -type \"mesh\" ");
		o.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCachedInMesh(const mesh& ci)
	{
		fprintf(mFile,"\tsetAttr \".ci\" -type \"mesh\" ");
		ci.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSmoothWarn(bool sw)
	{
		if(sw == true) return;
		fprintf(mFile,"\tsetAttr \".sw\" %i;\n", sw);
	}
	void setSmoothLevel(short lev)
	{
		if(lev == 2) return;
		fprintf(mFile,"\tsetAttr \".lev\" %i;\n", lev);
	}
	void setContinuity(float co)
	{
		if(co == 1) return;
		fprintf(mFile,"\tsetAttr \".co\" %f;\n", co);
	}
	void setSmoothUVs(bool suv)
	{
		if(suv == true) return;
		fprintf(mFile,"\tsetAttr \".suv\" %i;\n", suv);
	}
	void setKeepBorder(bool kb)
	{
		if(kb == false) return;
		fprintf(mFile,"\tsetAttr \".kb\" %i;\n", kb);
	}
	void setKeepHardEdge(bool khe)
	{
		if(khe == false) return;
		fprintf(mFile,"\tsetAttr \".khe\" %i;\n", khe);
	}
	void setPropagateEdgeHardness(bool peh)
	{
		if(peh == false) return;
		fprintf(mFile,"\tsetAttr \".peh\" %i;\n", peh);
	}
	void setKeepMapBorders(unsigned int kmb)
	{
		if(kmb == 1) return;
		fprintf(mFile,"\tsetAttr \".kmb\" %i;\n", kmb);
	}
	void setSmoothOffset(const float3& so)
	{
		fprintf(mFile,"\tsetAttr \".so\" -type \"float3\" ");
		so.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSofx(float sx)
	{
		if(sx == 0) return;
		fprintf(mFile,"\tsetAttr \".so.sx\" %f;\n", sx);
	}
	void setSofy(float sy)
	{
		if(sy == 0) return;
		fprintf(mFile,"\tsetAttr \".so.sy\" %f;\n", sy);
	}
	void setSofz(float sz)
	{
		if(sz == 0) return;
		fprintf(mFile,"\tsetAttr \".so.sz\" %f;\n", sz);
	}
	void setDisplaySubdComps(bool dsc)
	{
		if(dsc == false) return;
		fprintf(mFile,"\tsetAttr \".dsc\" %i;\n", dsc);
	}
	void setUseMaxEdgeLength(bool uxe)
	{
		if(uxe == false) return;
		fprintf(mFile,"\tsetAttr \".uxe\" %i;\n", uxe);
	}
	void setUseMinEdgeLength(bool uie)
	{
		if(uie == false) return;
		fprintf(mFile,"\tsetAttr \".uie\" %i;\n", uie);
	}
	void setUseMaxSubdivisions(bool uxs)
	{
		if(uxs == false) return;
		fprintf(mFile,"\tsetAttr \".uxs\" %i;\n", uxs);
	}
	void setUseMaxUV(bool uxu)
	{
		if(uxu == false) return;
		fprintf(mFile,"\tsetAttr \".uxu\" %i;\n", uxu);
	}
	void setUseMinScreen(bool uns)
	{
		if(uns == true) return;
		fprintf(mFile,"\tsetAttr \".uns\" %i;\n", uns);
	}
	void setUseNumTriangles(bool unp)
	{
		if(unp == false) return;
		fprintf(mFile,"\tsetAttr \".unp\" %i;\n", unp);
	}
	void setNumTriangles(int nt)
	{
		if(nt == 100) return;
		fprintf(mFile,"\tsetAttr \".nt\" %i;\n", nt);
	}
	void setMaxEdgeLength(float mxe)
	{
		if(mxe == 0.1) return;
		fprintf(mFile,"\tsetAttr \".mxe\" %f;\n", mxe);
	}
	void setMinEdgeLength(float mne)
	{
		if(mne == 0.01) return;
		fprintf(mFile,"\tsetAttr \".mne\" %f;\n", mne);
	}
	void setMaxSubd(int mxs)
	{
		if(mxs == 5) return;
		fprintf(mFile,"\tsetAttr \".mxs\" %i;\n", mxs);
	}
	void setMaxUv(float xuv)
	{
		if(xuv == 0.5) return;
		fprintf(mFile,"\tsetAttr \".xuv\" %f;\n", xuv);
	}
	void setMinScreen(float mns)
	{
		if(mns == 14) return;
		fprintf(mFile,"\tsetAttr \".mns\" %f;\n", mns);
	}
	void setMaxTriangles(int tsl)
	{
		if(tsl == 60000) return;
		fprintf(mFile,"\tsetAttr \".tsl\" %i;\n", tsl);
	}
	void setPnts(size_t pt_i,const float3& pt)
	{
		fprintf(mFile,"\tsetAttr \".pt[%i]\" -type \"float3\" ",pt_i);
		pt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPnts(size_t pt_start,size_t pt_end,float* pt)
	{
		fprintf(mFile,"\tsetAttr \".pt[%i:%i]\" ", pt_start,pt_end);
		size_t size = (pt_end-pt_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",pt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startPnts(size_t pt_start,size_t pt_end)const
	{
		fprintf(mFile,"\tsetAttr \".pt[%i:%i]\"",pt_start,pt_end);
	}
	void appendPnts(float pt)const
	{
		fprintf(mFile," %f",pt);
	}
	void endPnts()const
	{
		fprintf(mFile,";\n");
	}
	void setPntx(size_t pt_i,float px)
	{
		if(px == 0) return;
		fprintf(mFile,"\tsetAttr \".pt[%i].px\" %f;\n", pt_i,px);
	}
	void setPnty(size_t pt_i,float py)
	{
		if(py == 0) return;
		fprintf(mFile,"\tsetAttr \".pt[%i].py\" %f;\n", pt_i,py);
	}
	void setPntz(size_t pt_i,float pz)
	{
		if(pz == 0) return;
		fprintf(mFile,"\tsetAttr \".pt[%i].pz\" %f;\n", pt_i,pz);
	}
	void setVrts(size_t vt_i,const float3& vt)
	{
		fprintf(mFile,"\tsetAttr \".vt[%i]\" -type \"float3\" ",vt_i);
		vt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVrts(size_t vt_start,size_t vt_end,float* vt)
	{
		fprintf(mFile,"\tsetAttr \".vt[%i:%i]\" ", vt_start,vt_end);
		size_t size = (vt_end-vt_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",vt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startVrts(size_t vt_start,size_t vt_end)const
	{
		fprintf(mFile,"\tsetAttr \".vt[%i:%i]\"",vt_start,vt_end);
	}
	void appendVrts(float vt)const
	{
		fprintf(mFile," %f",vt);
	}
	void endVrts()const
	{
		fprintf(mFile,";\n");
	}
	void setVrtx(size_t vt_i,float vx)
	{
		if(vx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt[%i].vx\" %f;\n", vt_i,vx);
	}
	void setVrty(size_t vt_i,float vy)
	{
		if(vy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt[%i].vy\" %f;\n", vt_i,vy);
	}
	void setVrtz(size_t vt_i,float vz)
	{
		if(vz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vt[%i].vz\" %f;\n", vt_i,vz);
	}
	void setEdge(size_t ed_i,const long3& ed)
	{
		fprintf(mFile,"\tsetAttr \".ed[%i]\" -type \"long3\" ",ed_i);
		ed.write(mFile);
		fprintf(mFile,";\n");
	}
	void setEdge(size_t ed_start,size_t ed_end,int* ed)
	{
		fprintf(mFile,"\tsetAttr \".ed[%i:%i]\" ", ed_start,ed_end);
		size_t size = (ed_end-ed_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ed[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEdge(size_t ed_start,size_t ed_end)const
	{
		fprintf(mFile,"\tsetAttr \".ed[%i:%i]\"",ed_start,ed_end);
	}
	void appendEdge(int ed)const
	{
		fprintf(mFile," %i",ed);
	}
	void endEdge()const
	{
		fprintf(mFile,";\n");
	}
	void setEdg1(size_t ed_i,int e1)
	{
		if(e1 == 0) return;
		fprintf(mFile,"\tsetAttr \".ed[%i].e1\" %i;\n", ed_i,e1);
	}
	void setEdg2(size_t ed_i,int e2)
	{
		if(e2 == 0) return;
		fprintf(mFile,"\tsetAttr \".ed[%i].e2\" %i;\n", ed_i,e2);
	}
	void setEdgh(size_t ed_i,int eh)
	{
		if(eh == 0) return;
		fprintf(mFile,"\tsetAttr \".ed[%i].eh\" %i;\n", ed_i,eh);
	}
	void setUvpt(size_t uv_i,const float2& uv)
	{
		fprintf(mFile,"\tsetAttr \".uv[%i]\" -type \"float2\" ",uv_i);
		uv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUvpt(size_t uv_start,size_t uv_end,float* uv)
	{
		fprintf(mFile,"\tsetAttr \".uv[%i:%i]\" ", uv_start,uv_end);
		size_t size = (uv_end-uv_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uv[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startUvpt(size_t uv_start,size_t uv_end)const
	{
		fprintf(mFile,"\tsetAttr \".uv[%i:%i]\"",uv_start,uv_end);
	}
	void appendUvpt(float uv)const
	{
		fprintf(mFile," %f",uv);
	}
	void endUvpt()const
	{
		fprintf(mFile,";\n");
	}
	void setUvpx(size_t uv_i,float ux)
	{
		if(ux == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uv[%i].ux\" %f;\n", uv_i,ux);
	}
	void setUvpy(size_t uv_i,float uy)
	{
		if(uy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uv[%i].uy\" %f;\n", uv_i,uy);
	}
	void setColors(size_t clr_i,const Colors& clr)
	{
		fprintf(mFile,"\tsetAttr \".clr[%i]\" ",clr_i);
		clr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColors(size_t clr_start,size_t clr_end,Colors* clr)
	{
		fprintf(mFile,"\tsetAttr \".clr[%i:%i]\" ", clr_start,clr_end);
		size_t size = (clr_end-clr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			clr[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startColors(size_t clr_start,size_t clr_end)const
	{
		fprintf(mFile,"\tsetAttr \".clr[%i:%i]\"",clr_start,clr_end);
		fprintf(mFile," -type \"Colors\" ");
	}
	void appendColors(const Colors& clr)const
	{
		fprintf(mFile," ");
		clr.write(mFile);
	}
	void endColors()const
	{
		fprintf(mFile,";\n");
	}
	void setColorR(size_t clr_i,float clrr)
	{
		if(clrr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clrr\" %f;\n", clr_i,clrr);
	}
	void setColorG(size_t clr_i,float clrg)
	{
		if(clrg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clrg\" %f;\n", clr_i,clrg);
	}
	void setColorB(size_t clr_i,float clrb)
	{
		if(clrb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clrb\" %f;\n", clr_i,clrb);
	}
	void setColorA(size_t clr_i,float clra)
	{
		if(clra == 0.0) return;
		fprintf(mFile,"\tsetAttr \".clr[%i].clra\" %f;\n", clr_i,clra);
	}
	void setNormals(size_t n_i,const float3& n)
	{
		fprintf(mFile,"\tsetAttr \".n[%i]\" -type \"float3\" ",n_i);
		n.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNormals(size_t n_start,size_t n_end,float* n)
	{
		fprintf(mFile,"\tsetAttr \".n[%i:%i]\" ", n_start,n_end);
		size_t size = (n_end-n_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",n[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startNormals(size_t n_start,size_t n_end)const
	{
		fprintf(mFile,"\tsetAttr \".n[%i:%i]\"",n_start,n_end);
	}
	void appendNormals(float n)const
	{
		fprintf(mFile," %f",n);
	}
	void endNormals()const
	{
		fprintf(mFile,";\n");
	}
	void setNormalx(size_t n_i,float nx)
	{
		if(nx == 1e20) return;
		fprintf(mFile,"\tsetAttr \".n[%i].nx\" %f;\n", n_i,nx);
	}
	void setNormaly(size_t n_i,float ny)
	{
		if(ny == 1e20) return;
		fprintf(mFile,"\tsetAttr \".n[%i].ny\" %f;\n", n_i,ny);
	}
	void setNormalz(size_t n_i,float nz)
	{
		if(nz == 1e20) return;
		fprintf(mFile,"\tsetAttr \".n[%i].nz\" %f;\n", n_i,nz);
	}
	void setFace(size_t fc_i,const polyFaces& fc)
	{
		fprintf(mFile,"\tsetAttr \".fc[%i]\" -type \"polyFaces\" ",fc_i);
		fc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFace(size_t fc_start,size_t fc_end,polyFaces* fc)
	{
		fprintf(mFile,"\tsetAttr \".fc[%i:%i]\" ", fc_start,fc_end);
		size_t size = (fc_end-fc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fc[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startFace(size_t fc_start,size_t fc_end)const
	{
		fprintf(mFile,"\tsetAttr \".fc[%i:%i]\"",fc_start,fc_end);
		fprintf(mFile," -type \"polyFaces\" ");
	}
	void appendFace(const polyFaces& fc)const
	{
		fprintf(mFile," ");
		fc.write(mFile);
	}
	void endFace()const
	{
		fprintf(mFile,";\n");
	}
	void setColorPerVertex(const ColorPerVertex& cpvx)
	{
		fprintf(mFile,"\tsetAttr \".cpvx\" ");
		cpvx.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexColor(size_t vclr_i,const ColorPerVertex::VertexColor& vclr)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i]\" ",vclr_i);
		vclr.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexColor(size_t vclr_start,size_t vclr_end,ColorPerVertex::VertexColor* vclr)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i:%i]\" ", vclr_start,vclr_end);
		size_t size = (vclr_end-vclr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			vclr[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startVertexColor(size_t vclr_start,size_t vclr_end)const
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i:%i]\"",vclr_start,vclr_end);
		fprintf(mFile," -type \"ColorPerVertex::VertexColor\" ");
	}
	void appendVertexColor(const ColorPerVertex::VertexColor& vclr)const
	{
		fprintf(mFile," ");
		vclr.write(mFile);
	}
	void endVertexColor()const
	{
		fprintf(mFile,";\n");
	}
	void setVertexColorRGB(size_t vclr_i,const float3& vrgb)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vrgb\" -type \"float3\" ",vclr_i);
		vrgb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexColorR(size_t vclr_i,float vxcr)
	{
		if(vxcr == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vrgb.vxcr\" %f;\n", vclr_i,vxcr);
	}
	void setVertexColorG(size_t vclr_i,float vxcg)
	{
		if(vxcg == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vrgb.vxcg\" %f;\n", vclr_i,vxcg);
	}
	void setVertexColorB(size_t vclr_i,float vxcb)
	{
		if(vxcb == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vrgb.vxcb\" %f;\n", vclr_i,vxcb);
	}
	void setVertexAlpha(size_t vclr_i,float vxal)
	{
		if(vxal == 1) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vxal\" %f;\n", vclr_i,vxal);
	}
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_i,const ColorPerVertex::VertexColor::VertexFaceColor& vfcl)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i]\" ",vclr_i,vfcl_i);
		vfcl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_start,size_t vfcl_end,ColorPerVertex::VertexColor::VertexFaceColor* vfcl)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i:%i]\" ", vclr_i,vfcl_start,vfcl_end);
		size_t size = (vfcl_end-vfcl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			vfcl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startVertexFaceColor(size_t vclr_i,size_t vfcl_start,size_t vfcl_end)const
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i:%i]\"",vclr_i,vfcl_start,vfcl_end);
		fprintf(mFile," -type \"ColorPerVertex::VertexColor::VertexFaceColor\" ");
	}
	void appendVertexFaceColor(const ColorPerVertex::VertexColor::VertexFaceColor& vfcl)const
	{
		fprintf(mFile," ");
		vfcl.write(mFile);
	}
	void endVertexFaceColor()const
	{
		fprintf(mFile,";\n");
	}
	void setVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i,const float3& frgb)
	{
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].frgb\" -type \"float3\" ",vclr_i,vfcl_i);
		frgb.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexFaceColorR(size_t vclr_i,size_t vfcl_i,float vfcr)
	{
		if(vfcr == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcr\" %f;\n", vclr_i,vfcl_i,vfcr);
	}
	void setVertexFaceColorG(size_t vclr_i,size_t vfcl_i,float vfcg)
	{
		if(vfcg == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcg\" %f;\n", vclr_i,vfcl_i,vfcg);
	}
	void setVertexFaceColorB(size_t vclr_i,size_t vfcl_i,float vfcb)
	{
		if(vfcb == 0) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcb\" %f;\n", vclr_i,vfcl_i,vfcb);
	}
	void setVertexFaceAlpha(size_t vclr_i,size_t vfcl_i,float vfal)
	{
		if(vfal == 1) return;
		fprintf(mFile,"\tsetAttr \".cpvx.vclr[%i].vfcl[%i].vfal\" %f;\n", vclr_i,vfcl_i,vfal);
	}
	void setNormalPerVertex(const NormalPerVertex& npvx)
	{
		fprintf(mFile,"\tsetAttr \".npvx\" ");
		npvx.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexNormal(size_t vn_i,const NormalPerVertex::VertexNormal& vn)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i]\" ",vn_i);
		vn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexNormal(size_t vn_start,size_t vn_end,NormalPerVertex::VertexNormal* vn)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i:%i]\" ", vn_start,vn_end);
		size_t size = (vn_end-vn_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			vn[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startVertexNormal(size_t vn_start,size_t vn_end)const
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i:%i]\"",vn_start,vn_end);
		fprintf(mFile," -type \"NormalPerVertex::VertexNormal\" ");
	}
	void appendVertexNormal(const NormalPerVertex::VertexNormal& vn)const
	{
		fprintf(mFile," ");
		vn.write(mFile);
	}
	void endVertexNormal()const
	{
		fprintf(mFile,";\n");
	}
	void setVertexNormalXYZ(size_t vn_i,const float3& nxyz)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].nxyz\" -type \"float3\" ",vn_i);
		nxyz.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexNormalX(size_t vn_i,float vxnx)
	{
		if(vxnx == 1e20) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].nxyz.vxnx\" %f;\n", vn_i,vxnx);
	}
	void setVertexNormalY(size_t vn_i,float vxny)
	{
		if(vxny == 1e20) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].nxyz.vxny\" %f;\n", vn_i,vxny);
	}
	void setVertexNormalZ(size_t vn_i,float vxnz)
	{
		if(vxnz == 1e20) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].nxyz.vxnz\" %f;\n", vn_i,vxnz);
	}
	void setVertexFaceNormal(size_t vn_i,size_t vfnl_i,const NormalPerVertex::VertexNormal::VertexFaceNormal& vfnl)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i]\" ",vn_i,vfnl_i);
		vfnl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexFaceNormal(size_t vn_i,size_t vfnl_start,size_t vfnl_end,NormalPerVertex::VertexNormal::VertexFaceNormal* vfnl)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i:%i]\" ", vn_i,vfnl_start,vfnl_end);
		size_t size = (vfnl_end-vfnl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			vfnl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startVertexFaceNormal(size_t vn_i,size_t vfnl_start,size_t vfnl_end)const
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i:%i]\"",vn_i,vfnl_start,vfnl_end);
		fprintf(mFile," -type \"NormalPerVertex::VertexNormal::VertexFaceNormal\" ");
	}
	void appendVertexFaceNormal(const NormalPerVertex::VertexNormal::VertexFaceNormal& vfnl)const
	{
		fprintf(mFile," ");
		vfnl.write(mFile);
	}
	void endVertexFaceNormal()const
	{
		fprintf(mFile,";\n");
	}
	void setVertexFaceNormalXYZ(size_t vn_i,size_t vfnl_i,const float3& fnxy)
	{
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i].fnxy\" -type \"float3\" ",vn_i,vfnl_i);
		fnxy.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertexFaceNormalX(size_t vn_i,size_t vfnl_i,float vfnx)
	{
		if(vfnx == 1e20) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnx\" %f;\n", vn_i,vfnl_i,vfnx);
	}
	void setVertexFaceNormalY(size_t vn_i,size_t vfnl_i,float vfny)
	{
		if(vfny == 1e20) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfny\" %f;\n", vn_i,vfnl_i,vfny);
	}
	void setVertexFaceNormalZ(size_t vn_i,size_t vfnl_i,float vfnz)
	{
		if(vfnz == 1e20) return;
		fprintf(mFile,"\tsetAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnz\" %f;\n", vn_i,vfnl_i,vfnz);
	}
	void setDisplayVertices(bool dv)
	{
		if(dv == false) return;
		fprintf(mFile,"\tsetAttr \".dv\" %i;\n", dv);
	}
	void setDisplayBorders(bool db)
	{
		if(db == false) return;
		fprintf(mFile,"\tsetAttr \".db\" %i;\n", db);
	}
	void setDisplayFacesWithGroupId(int dfgi)
	{
		if(dfgi == -2) return;
		fprintf(mFile,"\tsetAttr \".dfgi\" %i;\n", dfgi);
	}
	void setDisplayCenter(bool dc)
	{
		if(dc == false) return;
		fprintf(mFile,"\tsetAttr \".dc\" %i;\n", dc);
	}
	void setDisplayTriangles(bool dt)
	{
		if(dt == false) return;
		fprintf(mFile,"\tsetAttr \".dt\" %i;\n", dt);
	}
	void setDisplayUVs(bool duv)
	{
		if(duv == false) return;
		fprintf(mFile,"\tsetAttr \".duv\" %i;\n", duv);
	}
	void setDisplayItemNumbers(int din)
	{
		if(din == 0) return;
		fprintf(mFile,"\tsetAttr \".din\" %i;\n", din);
	}
	void setDisplayNonPlanar(bool dnp)
	{
		if(dnp == false) return;
		fprintf(mFile,"\tsetAttr \".dnp\" %i;\n", dnp);
	}
	void setBackfaceCulling(unsigned int bck)
	{
		if(bck == 0) return;
		fprintf(mFile,"\tsetAttr \".bck\" %i;\n", bck);
	}
	void setVertexBackfaceCulling(bool vbc)
	{
		if(vbc == true) return;
		fprintf(mFile,"\tsetAttr \".vbc\" %i;\n", vbc);
	}
	void setVertexSize(double vs)
	{
		if(vs == 3.0) return;
		fprintf(mFile,"\tsetAttr \".vs\" %f;\n", vs);
	}
	void setUvSize(double usz)
	{
		if(usz == 4.0) return;
		fprintf(mFile,"\tsetAttr \".usz\" %f;\n", usz);
	}
	void setBorderWidth(double bw)
	{
		if(bw == 2.0) return;
		fprintf(mFile,"\tsetAttr \".bw\" %f;\n", bw);
	}
	void setNormalSize(double ns)
	{
		if(ns == 0.4) return;
		fprintf(mFile,"\tsetAttr \".ns\" %f;\n", ns);
	}
	void setNormalType(unsigned int ndt)
	{
		if(ndt == 0) return;
		fprintf(mFile,"\tsetAttr \".ndt\" %i;\n", ndt);
	}
	void setDisplayNormal(bool dn)
	{
		if(dn == false) return;
		fprintf(mFile,"\tsetAttr \".dn\" %i;\n", dn);
	}
	void setDisplayTangent(bool dtn)
	{
		if(dtn == false) return;
		fprintf(mFile,"\tsetAttr \".dtn\" %i;\n", dtn);
	}
	void setTangentSpace(unsigned int tgsp)
	{
		if(tgsp == 0) return;
		fprintf(mFile,"\tsetAttr \".tgsp\" %i;\n", tgsp);
	}
	void setTangentSmoothingAngle(double tsa)
	{
		if(tsa == 0) return;
		fprintf(mFile,"\tsetAttr \".tsa\" %f;\n", tsa);
	}
	void setTangentNormalThreshold(double tnt)
	{
		if(tnt == 0) return;
		fprintf(mFile,"\tsetAttr \".tnt\" %f;\n", tnt);
	}
	void setAllowTopologyMod(bool atm)
	{
		if(atm == true) return;
		fprintf(mFile,"\tsetAttr \".atm\" %i;\n", atm);
	}
	void setMaterialBlend(unsigned int matb)
	{
		if(matb == 0) return;
		fprintf(mFile,"\tsetAttr \".matb\" %i;\n", matb);
	}
	void setUserTrg(const string& utrg)
	{
		if(utrg == "NULL") return;
		fprintf(mFile,"\tsetAttr \".utrg\" -type \"string\" ");
		utrg.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDispResolution(unsigned int dr)
	{
		if(dr == 0) return;
		fprintf(mFile,"\tsetAttr \".dr\" %i;\n", dr);
	}
	void setDisplaySmoothMesh(unsigned int dsm)
	{
		if(dsm == 0) return;
		fprintf(mFile,"\tsetAttr \".dsm\" %i;\n", dsm);
	}
	void setSmoothMeshSelectionMode(unsigned int ssm)
	{
		if(ssm == 0) return;
		fprintf(mFile,"\tsetAttr \".ssm\" %i;\n", ssm);
	}
	void setReuseTriangles(bool rtri)
	{
		if(rtri == false) return;
		fprintf(mFile,"\tsetAttr \".rtri\" %i;\n", rtri);
	}
	void setQuadSplit(unsigned int qsp)
	{
		if(qsp == 2) return;
		fprintf(mFile,"\tsetAttr \".qsp\" %i;\n", qsp);
	}
	void setPerInstanceIndex(size_t pii_i,int pii)
	{
		if(pii == -1) return;
		fprintf(mFile,"\tsetAttr \".pii[%i]\" %i;\n", pii_i,pii);
	}
	void setPerInstanceIndex(size_t pii_start,size_t pii_end,int* pii)
	{
		fprintf(mFile,"\tsetAttr \".pii[%i:%i]\" ", pii_start,pii_end);
		size_t size = (pii_end-pii_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",pii[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startPerInstanceIndex(size_t pii_start,size_t pii_end)const
	{
		fprintf(mFile,"\tsetAttr \".pii[%i:%i]\"",pii_start,pii_end);
	}
	void appendPerInstanceIndex(int pii)const
	{
		fprintf(mFile," %i",pii);
	}
	void endPerInstanceIndex()const
	{
		fprintf(mFile,";\n");
	}
	void setPerInstanceTag(size_t pit_i,int pit)
	{
		if(pit == -1) return;
		fprintf(mFile,"\tsetAttr \".pit[%i]\" %i;\n", pit_i,pit);
	}
	void setPerInstanceTag(size_t pit_start,size_t pit_end,int* pit)
	{
		fprintf(mFile,"\tsetAttr \".pit[%i:%i]\" ", pit_start,pit_end);
		size_t size = (pit_end-pit_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",pit[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startPerInstanceTag(size_t pit_start,size_t pit_end)const
	{
		fprintf(mFile,"\tsetAttr \".pit[%i:%i]\"",pit_start,pit_end);
	}
	void appendPerInstanceTag(int pit)const
	{
		fprintf(mFile," %i",pit);
	}
	void endPerInstanceTag()const
	{
		fprintf(mFile,";\n");
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
	void setDisplayAlphaAsGreyScale(bool dags)
	{
		if(dags == false) return;
		fprintf(mFile,"\tsetAttr \".dags\" %i;\n", dags);
	}
	void getInMesh()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutMesh()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getOutGeometryClean()const
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());
	}
	void getWorldMesh(size_t w_i)const
	{
		fprintf(mFile,"\"%s.w[%i]\"",mName.c_str(),w_i);
	}
	void getWorldMesh()const
	{

		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
	void getOutSmoothMesh()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getCachedSmoothMesh()const
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());
	}
	void getSmoothWarn()const
	{
		fprintf(mFile,"\"%s.sw\"",mName.c_str());
	}
	void getSmoothLevel()const
	{
		fprintf(mFile,"\"%s.lev\"",mName.c_str());
	}
	void getContinuity()const
	{
		fprintf(mFile,"\"%s.co\"",mName.c_str());
	}
	void getSmoothUVs()const
	{
		fprintf(mFile,"\"%s.suv\"",mName.c_str());
	}
	void getKeepBorder()const
	{
		fprintf(mFile,"\"%s.kb\"",mName.c_str());
	}
	void getKeepHardEdge()const
	{
		fprintf(mFile,"\"%s.khe\"",mName.c_str());
	}
	void getPropagateEdgeHardness()const
	{
		fprintf(mFile,"\"%s.peh\"",mName.c_str());
	}
	void getKeepMapBorders()const
	{
		fprintf(mFile,"\"%s.kmb\"",mName.c_str());
	}
	void getSmoothOffset()const
	{
		fprintf(mFile,"\"%s.so\"",mName.c_str());
	}
	void getSofx()const
	{
		fprintf(mFile,"\"%s.so.sx\"",mName.c_str());
	}
	void getSofy()const
	{
		fprintf(mFile,"\"%s.so.sy\"",mName.c_str());
	}
	void getSofz()const
	{
		fprintf(mFile,"\"%s.so.sz\"",mName.c_str());
	}
	void getDisplaySubdComps()const
	{
		fprintf(mFile,"\"%s.dsc\"",mName.c_str());
	}
	void getUseMaxEdgeLength()const
	{
		fprintf(mFile,"\"%s.uxe\"",mName.c_str());
	}
	void getUseMinEdgeLength()const
	{
		fprintf(mFile,"\"%s.uie\"",mName.c_str());
	}
	void getUseMaxSubdivisions()const
	{
		fprintf(mFile,"\"%s.uxs\"",mName.c_str());
	}
	void getUseMaxUV()const
	{
		fprintf(mFile,"\"%s.uxu\"",mName.c_str());
	}
	void getUseMinScreen()const
	{
		fprintf(mFile,"\"%s.uns\"",mName.c_str());
	}
	void getUseNumTriangles()const
	{
		fprintf(mFile,"\"%s.unp\"",mName.c_str());
	}
	void getNumTriangles()const
	{
		fprintf(mFile,"\"%s.nt\"",mName.c_str());
	}
	void getMaxEdgeLength()const
	{
		fprintf(mFile,"\"%s.mxe\"",mName.c_str());
	}
	void getMinEdgeLength()const
	{
		fprintf(mFile,"\"%s.mne\"",mName.c_str());
	}
	void getMaxSubd()const
	{
		fprintf(mFile,"\"%s.mxs\"",mName.c_str());
	}
	void getMaxUv()const
	{
		fprintf(mFile,"\"%s.xuv\"",mName.c_str());
	}
	void getMinScreen()const
	{
		fprintf(mFile,"\"%s.mns\"",mName.c_str());
	}
	void getMaxTriangles()const
	{
		fprintf(mFile,"\"%s.tsl\"",mName.c_str());
	}
	void getPnts(size_t pt_i)const
	{
		fprintf(mFile,"\"%s.pt[%i]\"",mName.c_str(),pt_i);
	}
	void getPnts()const
	{

		fprintf(mFile,"\"%s.pt\"",mName.c_str());
	}
	void getPntx(size_t pt_i)const
	{
		fprintf(mFile,"\"%s.pt[%i].px\"",mName.c_str(),pt_i);
	}
	void getPntx()const
	{

		fprintf(mFile,"\"%s.pt.px\"",mName.c_str());
	}
	void getPnty(size_t pt_i)const
	{
		fprintf(mFile,"\"%s.pt[%i].py\"",mName.c_str(),pt_i);
	}
	void getPnty()const
	{

		fprintf(mFile,"\"%s.pt.py\"",mName.c_str());
	}
	void getPntz(size_t pt_i)const
	{
		fprintf(mFile,"\"%s.pt[%i].pz\"",mName.c_str(),pt_i);
	}
	void getPntz()const
	{

		fprintf(mFile,"\"%s.pt.pz\"",mName.c_str());
	}
	void getVrtx(size_t vt_i)const
	{
		fprintf(mFile,"\"%s.vt[%i].vx\"",mName.c_str(),vt_i);
	}
	void getVrtx()const
	{

		fprintf(mFile,"\"%s.vt.vx\"",mName.c_str());
	}
	void getVrty(size_t vt_i)const
	{
		fprintf(mFile,"\"%s.vt[%i].vy\"",mName.c_str(),vt_i);
	}
	void getVrty()const
	{

		fprintf(mFile,"\"%s.vt.vy\"",mName.c_str());
	}
	void getVrtz(size_t vt_i)const
	{
		fprintf(mFile,"\"%s.vt[%i].vz\"",mName.c_str(),vt_i);
	}
	void getVrtz()const
	{

		fprintf(mFile,"\"%s.vt.vz\"",mName.c_str());
	}
	void getEdg1(size_t ed_i)const
	{
		fprintf(mFile,"\"%s.ed[%i].e1\"",mName.c_str(),ed_i);
	}
	void getEdg1()const
	{

		fprintf(mFile,"\"%s.ed.e1\"",mName.c_str());
	}
	void getEdg2(size_t ed_i)const
	{
		fprintf(mFile,"\"%s.ed[%i].e2\"",mName.c_str(),ed_i);
	}
	void getEdg2()const
	{

		fprintf(mFile,"\"%s.ed.e2\"",mName.c_str());
	}
	void getEdgh(size_t ed_i)const
	{
		fprintf(mFile,"\"%s.ed[%i].eh\"",mName.c_str(),ed_i);
	}
	void getEdgh()const
	{

		fprintf(mFile,"\"%s.ed.eh\"",mName.c_str());
	}
	void getUvpx(size_t uv_i)const
	{
		fprintf(mFile,"\"%s.uv[%i].ux\"",mName.c_str(),uv_i);
	}
	void getUvpx()const
	{

		fprintf(mFile,"\"%s.uv.ux\"",mName.c_str());
	}
	void getUvpy(size_t uv_i)const
	{
		fprintf(mFile,"\"%s.uv[%i].uy\"",mName.c_str(),uv_i);
	}
	void getUvpy()const
	{

		fprintf(mFile,"\"%s.uv.uy\"",mName.c_str());
	}
	void getColorPerVertex()const
	{
		fprintf(mFile,"\"%s.cpvx\"",mName.c_str());
	}
	void getVertexColor(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i]\"",mName.c_str(),vclr_i);
	}
	void getVertexColorRGB(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb\"",mName.c_str(),vclr_i);
	}
	void getVertexColorR(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcr\"",mName.c_str(),vclr_i);
	}
	void getVertexColorG(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcg\"",mName.c_str(),vclr_i);
	}
	void getVertexColorB(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcb\"",mName.c_str(),vclr_i);
	}
	void getVertexAlpha(size_t vclr_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vxal\"",mName.c_str(),vclr_i);
	}
	void getVertexFaceColor(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i]\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceColorR(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcr\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceColorG(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcg\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceColorB(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcb\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getVertexFaceAlpha(size_t vclr_i,size_t vfcl_i)const
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].vfal\"",mName.c_str(),vclr_i,vfcl_i);
	}
	void getDisplayVertices()const
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());
	}
	void getDisplayBorders()const
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());
	}
	void getDisplayEdges()const
	{
		fprintf(mFile,"\"%s.de\"",mName.c_str());
	}
	void getDisplayFacesWithGroupId()const
	{
		fprintf(mFile,"\"%s.dfgi\"",mName.c_str());
	}
	void getDisplayCenter()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
	void getDisplayTriangles()const
	{
		fprintf(mFile,"\"%s.dt\"",mName.c_str());
	}
	void getDisplayUVs()const
	{
		fprintf(mFile,"\"%s.duv\"",mName.c_str());
	}
	void getDisplayItemNumbers()const
	{
		fprintf(mFile,"\"%s.din\"",mName.c_str());
	}
	void getDisplayNonPlanar()const
	{
		fprintf(mFile,"\"%s.dnp\"",mName.c_str());
	}
	void getBackfaceCulling()const
	{
		fprintf(mFile,"\"%s.bck\"",mName.c_str());
	}
	void getVertexBackfaceCulling()const
	{
		fprintf(mFile,"\"%s.vbc\"",mName.c_str());
	}
	void getVertexSize()const
	{
		fprintf(mFile,"\"%s.vs\"",mName.c_str());
	}
	void getUvSize()const
	{
		fprintf(mFile,"\"%s.usz\"",mName.c_str());
	}
	void getBorderWidth()const
	{
		fprintf(mFile,"\"%s.bw\"",mName.c_str());
	}
	void getNormalSize()const
	{
		fprintf(mFile,"\"%s.ns\"",mName.c_str());
	}
	void getNormalType()const
	{
		fprintf(mFile,"\"%s.ndt\"",mName.c_str());
	}
	void getDisplayNormal()const
	{
		fprintf(mFile,"\"%s.dn\"",mName.c_str());
	}
	void getDisplayTangent()const
	{
		fprintf(mFile,"\"%s.dtn\"",mName.c_str());
	}
	void getTangentSpace()const
	{
		fprintf(mFile,"\"%s.tgsp\"",mName.c_str());
	}
	void getTangentSmoothingAngle()const
	{
		fprintf(mFile,"\"%s.tsa\"",mName.c_str());
	}
	void getTangentNormalThreshold()const
	{
		fprintf(mFile,"\"%s.tnt\"",mName.c_str());
	}
	void getAllowTopologyMod()const
	{
		fprintf(mFile,"\"%s.atm\"",mName.c_str());
	}
	void getMaterialBlend()const
	{
		fprintf(mFile,"\"%s.matb\"",mName.c_str());
	}
	void getUvTweakLocation()const
	{
		fprintf(mFile,"\"%s.uvtl\"",mName.c_str());
	}
	void getUserTrg()const
	{
		fprintf(mFile,"\"%s.utrg\"",mName.c_str());
	}
	void getDispResolution()const
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());
	}
	void getReuseTriangles()const
	{
		fprintf(mFile,"\"%s.rtri\"",mName.c_str());
	}
	void getQuadSplit()const
	{
		fprintf(mFile,"\"%s.qsp\"",mName.c_str());
	}
	void getPerInstanceIndex(size_t pii_i)const
	{
		fprintf(mFile,"\"%s.pii[%i]\"",mName.c_str(),pii_i);
	}
	void getPerInstanceIndex()const
	{

		fprintf(mFile,"\"%s.pii\"",mName.c_str());
	}
	void getPerInstanceTag(size_t pit_i)const
	{
		fprintf(mFile,"\"%s.pit[%i]\"",mName.c_str(),pit_i);
	}
	void getPerInstanceTag()const
	{

		fprintf(mFile,"\"%s.pit\"",mName.c_str());
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
	void getDisplayAlphaAsGreyScale()const
	{
		fprintf(mFile,"\"%s.dags\"",mName.c_str());
	}
protected:
	Mesh(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:SurfaceShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MESH_H__
