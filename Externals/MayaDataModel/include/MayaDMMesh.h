/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
			void write(FILE* file) const
			{
				vertexColorRGB.write(file);
				fprintf(file, " ");
				fprintf(file,"%f ", vertexAlpha);
				size_t size = sizeof(vertexFaceColor)/sizeof(VertexFaceColor);
				for(size_t i=0; i<size; ++i)
				{
					vertexFaceColor[i].write(file);
					if(i+1<size) fprintf(file," ");
				}
			}
		}* vertexColor;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertexColor)/sizeof(VertexColor);
			for(size_t i=0; i<size; ++i)
			{
				vertexColor[i].write(file);
				if(i+1<size) fprintf(file," ");
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
			void write(FILE* file) const
			{
				vertexNormalXYZ.write(file);
				fprintf(file, " ");
				size_t size = sizeof(vertexFaceNormal)/sizeof(VertexFaceNormal);
				for(size_t i=0; i<size; ++i)
				{
					vertexFaceNormal[i].write(file);
					if(i+1<size) fprintf(file," ");
				}
			}
		}* vertexNormal;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertexNormal)/sizeof(VertexNormal);
			for(size_t i=0; i<size; ++i)
			{
				vertexNormal[i].write(file);
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
	Mesh(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "mesh"){}
	virtual ~Mesh(){}
	void setOutMesh(const mesh& o)
	{
		fprintf(mFile,"setAttr \".o\" -type \"mesh\" ");
		o.write(mFile);
		fprintf(mFile,";\n");

	}
	void setCachedInMesh(const mesh& ci)
	{
		fprintf(mFile,"setAttr \".ci\" -type \"mesh\" ");
		ci.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSmoothWarn(bool sw)
	{
		if(sw == true) return;
		fprintf(mFile,"setAttr \".sw\" %i;\n", sw);

	}
	void setSmoothLevel(short lev)
	{
		if(lev == 2) return;
		fprintf(mFile,"setAttr \".lev\" %i;\n", lev);

	}
	void setContinuity(float co)
	{
		if(co == 1) return;
		fprintf(mFile,"setAttr \".co\" %f;\n", co);

	}
	void setSmoothUVs(bool suv)
	{
		if(suv == true) return;
		fprintf(mFile,"setAttr \".suv\" %i;\n", suv);

	}
	void setKeepBorder(bool kb)
	{
		if(kb == false) return;
		fprintf(mFile,"setAttr \".kb\" %i;\n", kb);

	}
	void setKeepHardEdge(bool khe)
	{
		if(khe == false) return;
		fprintf(mFile,"setAttr \".khe\" %i;\n", khe);

	}
	void setPropagateEdgeHardness(bool peh)
	{
		if(peh == false) return;
		fprintf(mFile,"setAttr \".peh\" %i;\n", peh);

	}
	void setKeepMapBorders(unsigned int kmb)
	{
		if(kmb == 1) return;
		fprintf(mFile,"setAttr \".kmb\" %i;\n", kmb);

	}
	void setSmoothOffset(const float3& so)
	{
		fprintf(mFile,"setAttr \".so\" -type \"float3\" ");
		so.write(mFile);
		fprintf(mFile,";\n");

	}
	void setSofx(float sx)
	{
		if(sx == 0) return;
		fprintf(mFile,"setAttr \".so.sx\" %f;\n", sx);

	}
	void setSofy(float sy)
	{
		if(sy == 0) return;
		fprintf(mFile,"setAttr \".so.sy\" %f;\n", sy);

	}
	void setSofz(float sz)
	{
		if(sz == 0) return;
		fprintf(mFile,"setAttr \".so.sz\" %f;\n", sz);

	}
	void setDisplaySubdComps(bool dsc)
	{
		if(dsc == false) return;
		fprintf(mFile,"setAttr \".dsc\" %i;\n", dsc);

	}
	void setUseMaxEdgeLength(bool uxe)
	{
		if(uxe == false) return;
		fprintf(mFile,"setAttr \".uxe\" %i;\n", uxe);

	}
	void setUseMinEdgeLength(bool uie)
	{
		if(uie == false) return;
		fprintf(mFile,"setAttr \".uie\" %i;\n", uie);

	}
	void setUseMaxSubdivisions(bool uxs)
	{
		if(uxs == false) return;
		fprintf(mFile,"setAttr \".uxs\" %i;\n", uxs);

	}
	void setUseMaxUV(bool uxu)
	{
		if(uxu == false) return;
		fprintf(mFile,"setAttr \".uxu\" %i;\n", uxu);

	}
	void setUseMinScreen(bool uns)
	{
		if(uns == true) return;
		fprintf(mFile,"setAttr \".uns\" %i;\n", uns);

	}
	void setUseNumTriangles(bool unp)
	{
		if(unp == false) return;
		fprintf(mFile,"setAttr \".unp\" %i;\n", unp);

	}
	void setNumTriangles(int nt)
	{
		if(nt == 100) return;
		fprintf(mFile,"setAttr \".nt\" %i;\n", nt);

	}
	void setMaxEdgeLength(float mxe)
	{
		if(mxe == 0.1) return;
		fprintf(mFile,"setAttr \".mxe\" %f;\n", mxe);

	}
	void setMinEdgeLength(float mne)
	{
		if(mne == 0.01) return;
		fprintf(mFile,"setAttr \".mne\" %f;\n", mne);

	}
	void setMaxSubd(int mxs)
	{
		if(mxs == 5) return;
		fprintf(mFile,"setAttr \".mxs\" %i;\n", mxs);

	}
	void setMaxUv(float xuv)
	{
		if(xuv == 0.5) return;
		fprintf(mFile,"setAttr \".xuv\" %f;\n", xuv);

	}
	void setMinScreen(float mns)
	{
		if(mns == 14) return;
		fprintf(mFile,"setAttr \".mns\" %f;\n", mns);

	}
	void setMaxTriangles(int tsl)
	{
		if(tsl == 60000) return;
		fprintf(mFile,"setAttr \".tsl\" %i;\n", tsl);

	}
	void setPnts(size_t pt_i,const float3& pt)
	{
		fprintf(mFile,"setAttr \".pt[%i]\" -type \"float3\" ",pt_i);
		pt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setPnts(size_t pt_start,size_t pt_end,float* pt)
	{
		fprintf(mFile,"setAttr \".pt[%i:%i]\" ", pt_start,pt_end);
		size_t size = (pt_end-pt_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",pt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startPnts(size_t pt_start,size_t pt_end)
	{
		fprintf(mFile,"setAttr \".pt[%i:%i]\"",pt_start,pt_end);

	}
	void appendPnts(float pt)
	{
		fprintf(mFile," %f",pt);

	}
	void endPnts()
	{
		fprintf(mFile,";\n");

	}
	void setPntx(size_t pt_i,float px)
	{
		if(px == 0) return;
		fprintf(mFile,"setAttr \".pt[%i].px\" %f;\n", pt_i,px);

	}
	void setPnty(size_t pt_i,float py)
	{
		if(py == 0) return;
		fprintf(mFile,"setAttr \".pt[%i].py\" %f;\n", pt_i,py);

	}
	void setPntz(size_t pt_i,float pz)
	{
		if(pz == 0) return;
		fprintf(mFile,"setAttr \".pt[%i].pz\" %f;\n", pt_i,pz);

	}
	void setVrts(size_t vt_i,const float3& vt)
	{
		fprintf(mFile,"setAttr \".vt[%i]\" -type \"float3\" ",vt_i);
		vt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVrts(size_t vt_start,size_t vt_end,float* vt)
	{
		fprintf(mFile,"setAttr \".vt[%i:%i]\" ", vt_start,vt_end);
		size_t size = (vt_end-vt_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",vt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startVrts(size_t vt_start,size_t vt_end)
	{
		fprintf(mFile,"setAttr \".vt[%i:%i]\"",vt_start,vt_end);

	}
	void appendVrts(float vt)
	{
		fprintf(mFile," %f",vt);

	}
	void endVrts()
	{
		fprintf(mFile,";\n");

	}
	void setVrtx(size_t vt_i,float vx)
	{
		if(vx == 0.0) return;
		fprintf(mFile,"setAttr \".vt[%i].vx\" %f;\n", vt_i,vx);

	}
	void setVrty(size_t vt_i,float vy)
	{
		if(vy == 0.0) return;
		fprintf(mFile,"setAttr \".vt[%i].vy\" %f;\n", vt_i,vy);

	}
	void setVrtz(size_t vt_i,float vz)
	{
		if(vz == 0.0) return;
		fprintf(mFile,"setAttr \".vt[%i].vz\" %f;\n", vt_i,vz);

	}
	void setEdge(size_t ed_i,const long3& ed)
	{
		fprintf(mFile,"setAttr \".ed[%i]\" -type \"long3\" ",ed_i);
		ed.write(mFile);
		fprintf(mFile,";\n");

	}
	void setEdge(size_t ed_start,size_t ed_end,int* ed)
	{
		fprintf(mFile,"setAttr \".ed[%i:%i]\" ", ed_start,ed_end);
		size_t size = (ed_end-ed_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ed[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEdge(size_t ed_start,size_t ed_end)
	{
		fprintf(mFile,"setAttr \".ed[%i:%i]\"",ed_start,ed_end);

	}
	void appendEdge(int ed)
	{
		fprintf(mFile," %i",ed);

	}
	void endEdge()
	{
		fprintf(mFile,";\n");

	}
	void setEdg1(size_t ed_i,int e1)
	{
		if(e1 == 0) return;
		fprintf(mFile,"setAttr \".ed[%i].e1\" %i;\n", ed_i,e1);

	}
	void setEdg2(size_t ed_i,int e2)
	{
		if(e2 == 0) return;
		fprintf(mFile,"setAttr \".ed[%i].e2\" %i;\n", ed_i,e2);

	}
	void setEdgh(size_t ed_i,int eh)
	{
		if(eh == 0) return;
		fprintf(mFile,"setAttr \".ed[%i].eh\" %i;\n", ed_i,eh);

	}
	void setUvpt(size_t uv_i,const float2& uv)
	{
		fprintf(mFile,"setAttr \".uv[%i]\" -type \"float2\" ",uv_i);
		uv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvpt(size_t uv_start,size_t uv_end,float* uv)
	{
		fprintf(mFile,"setAttr \".uv[%i:%i]\" ", uv_start,uv_end);
		size_t size = (uv_end-uv_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uv[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startUvpt(size_t uv_start,size_t uv_end)
	{
		fprintf(mFile,"setAttr \".uv[%i:%i]\"",uv_start,uv_end);

	}
	void appendUvpt(float uv)
	{
		fprintf(mFile," %f",uv);

	}
	void endUvpt()
	{
		fprintf(mFile,";\n");

	}
	void setUvpx(size_t uv_i,float ux)
	{
		if(ux == 0.0) return;
		fprintf(mFile,"setAttr \".uv[%i].ux\" %f;\n", uv_i,ux);

	}
	void setUvpy(size_t uv_i,float uy)
	{
		if(uy == 0.0) return;
		fprintf(mFile,"setAttr \".uv[%i].uy\" %f;\n", uv_i,uy);

	}
	void setColors(size_t clr_i,const Colors& clr)
	{
		fprintf(mFile,"setAttr \".clr[%i]\" ",clr_i);
		clr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorR(size_t clr_i,float clrr)
	{
		if(clrr == 0.0) return;
		fprintf(mFile,"setAttr \".clr[%i].clrr\" %f;\n", clr_i,clrr);

	}
	void setColorG(size_t clr_i,float clrg)
	{
		if(clrg == 0.0) return;
		fprintf(mFile,"setAttr \".clr[%i].clrg\" %f;\n", clr_i,clrg);

	}
	void setColorB(size_t clr_i,float clrb)
	{
		if(clrb == 0.0) return;
		fprintf(mFile,"setAttr \".clr[%i].clrb\" %f;\n", clr_i,clrb);

	}
	void setColorA(size_t clr_i,float clra)
	{
		if(clra == 0.0) return;
		fprintf(mFile,"setAttr \".clr[%i].clra\" %f;\n", clr_i,clra);

	}
	void setNormals(size_t n_i,const float3& n)
	{
		fprintf(mFile,"setAttr \".n[%i]\" -type \"float3\" ",n_i);
		n.write(mFile);
		fprintf(mFile,";\n");

	}
	void setNormals(size_t n_start,size_t n_end,float* n)
	{
		fprintf(mFile,"setAttr \".n[%i:%i]\" ", n_start,n_end);
		size_t size = (n_end-n_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",n[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startNormals(size_t n_start,size_t n_end)
	{
		fprintf(mFile,"setAttr \".n[%i:%i]\"",n_start,n_end);

	}
	void appendNormals(float n)
	{
		fprintf(mFile," %f",n);

	}
	void endNormals()
	{
		fprintf(mFile,";\n");

	}
	void setNormalx(size_t n_i,float nx)
	{
		if(nx == 1e20) return;
		fprintf(mFile,"setAttr \".n[%i].nx\" %f;\n", n_i,nx);

	}
	void setNormaly(size_t n_i,float ny)
	{
		if(ny == 1e20) return;
		fprintf(mFile,"setAttr \".n[%i].ny\" %f;\n", n_i,ny);

	}
	void setNormalz(size_t n_i,float nz)
	{
		if(nz == 1e20) return;
		fprintf(mFile,"setAttr \".n[%i].nz\" %f;\n", n_i,nz);

	}
	void setFace(size_t fc_i,const polyFaces& fc)
	{
		fprintf(mFile,"setAttr \".fc[%i]\" -type \"polyFaces\" ",fc_i);
		fc.write(mFile);
		fprintf(mFile,";\n");

	}
	void setFace(size_t fc_start,size_t fc_end,polyFaces* fc)
	{
		fprintf(mFile,"setAttr \".fc[%i:%i]\" ", fc_start,fc_end);
		size_t size = (fc_end-fc_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fc[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");

	}
	void startFace(size_t fc_start,size_t fc_end)
	{
		fprintf(mFile,"setAttr \".fc[%i:%i]\"",fc_start,fc_end);
		fprintf(mFile," -type \"polyFaces\" ");

	}
	void appendFace(const polyFaces& fc)
	{
		fprintf(mFile,"\n");
		fc.write(mFile);

	}
	void endFace()
	{
		fprintf(mFile,";\n");

	}
	void setColorPerVertex(const ColorPerVertex& cpvx)
	{
		fprintf(mFile,"setAttr \".cpvx\" ");
		cpvx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexColor(size_t vclr_i,const ColorPerVertex::VertexColor& vclr)
	{
		fprintf(mFile,"setAttr \".cpvx.vclr[%i]\" ",vclr_i);
		vclr.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexColorRGB(size_t vclr_i,const float3& vrgb)
	{
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vrgb\" -type \"float3\" ",vclr_i);
		vrgb.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexColorR(size_t vclr_i,float vxcr)
	{
		if(vxcr == 0) return;
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vrgb.vxcr\" %f;\n", vclr_i,vxcr);

	}
	void setVertexColorG(size_t vclr_i,float vxcg)
	{
		if(vxcg == 0) return;
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vrgb.vxcg\" %f;\n", vclr_i,vxcg);

	}
	void setVertexColorB(size_t vclr_i,float vxcb)
	{
		if(vxcb == 0) return;
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vrgb.vxcb\" %f;\n", vclr_i,vxcb);

	}
	void setVertexAlpha(size_t vclr_i,float vxal)
	{
		if(vxal == 1) return;
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vxal\" %f;\n", vclr_i,vxal);

	}
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_i,const ColorPerVertex::VertexColor::VertexFaceColor& vfcl)
	{
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vfcl[%i]\" ",vclr_i,vfcl_i);
		vfcl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i,const float3& frgb)
	{
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vfcl[%i].frgb\" -type \"float3\" ",vclr_i,vfcl_i);
		frgb.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexFaceColorR(size_t vclr_i,size_t vfcl_i,float vfcr)
	{
		if(vfcr == 0) return;
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcr\" %f;\n", vclr_i,vfcl_i,vfcr);

	}
	void setVertexFaceColorG(size_t vclr_i,size_t vfcl_i,float vfcg)
	{
		if(vfcg == 0) return;
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcg\" %f;\n", vclr_i,vfcl_i,vfcg);

	}
	void setVertexFaceColorB(size_t vclr_i,size_t vfcl_i,float vfcb)
	{
		if(vfcb == 0) return;
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcb\" %f;\n", vclr_i,vfcl_i,vfcb);

	}
	void setVertexFaceAlpha(size_t vclr_i,size_t vfcl_i,float vfal)
	{
		if(vfal == 1) return;
		fprintf(mFile,"setAttr \".cpvx.vclr[%i].vfcl[%i].vfal\" %f;\n", vclr_i,vfcl_i,vfal);

	}
	void setNormalPerVertex(const NormalPerVertex& npvx)
	{
		fprintf(mFile,"setAttr \".npvx\" ");
		npvx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexNormal(size_t vn_i,const NormalPerVertex::VertexNormal& vn)
	{
		fprintf(mFile,"setAttr \".npvx.vn[%i]\" ",vn_i);
		vn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexNormalXYZ(size_t vn_i,const float3& nxyz)
	{
		fprintf(mFile,"setAttr \".npvx.vn[%i].nxyz\" -type \"float3\" ",vn_i);
		nxyz.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexNormalX(size_t vn_i,float vxnx)
	{
		if(vxnx == 1e20) return;
		fprintf(mFile,"setAttr \".npvx.vn[%i].nxyz.vxnx\" %f;\n", vn_i,vxnx);

	}
	void setVertexNormalY(size_t vn_i,float vxny)
	{
		if(vxny == 1e20) return;
		fprintf(mFile,"setAttr \".npvx.vn[%i].nxyz.vxny\" %f;\n", vn_i,vxny);

	}
	void setVertexNormalZ(size_t vn_i,float vxnz)
	{
		if(vxnz == 1e20) return;
		fprintf(mFile,"setAttr \".npvx.vn[%i].nxyz.vxnz\" %f;\n", vn_i,vxnz);

	}
	void setVertexFaceNormal(size_t vn_i,size_t vfnl_i,const NormalPerVertex::VertexNormal::VertexFaceNormal& vfnl)
	{
		fprintf(mFile,"setAttr \".npvx.vn[%i].vfnl[%i]\" ",vn_i,vfnl_i);
		vfnl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexFaceNormalXYZ(size_t vn_i,size_t vfnl_i,const float3& fnxy)
	{
		fprintf(mFile,"setAttr \".npvx.vn[%i].vfnl[%i].fnxy\" -type \"float3\" ",vn_i,vfnl_i);
		fnxy.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertexFaceNormalX(size_t vn_i,size_t vfnl_i,float vfnx)
	{
		if(vfnx == 1e20) return;
		fprintf(mFile,"setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnx\" %f;\n", vn_i,vfnl_i,vfnx);

	}
	void setVertexFaceNormalY(size_t vn_i,size_t vfnl_i,float vfny)
	{
		if(vfny == 1e20) return;
		fprintf(mFile,"setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfny\" %f;\n", vn_i,vfnl_i,vfny);

	}
	void setVertexFaceNormalZ(size_t vn_i,size_t vfnl_i,float vfnz)
	{
		if(vfnz == 1e20) return;
		fprintf(mFile,"setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnz\" %f;\n", vn_i,vfnl_i,vfnz);

	}
	void setDisplayVertices(bool dv)
	{
		if(dv == false) return;
		fprintf(mFile,"setAttr \".dv\" %i;\n", dv);

	}
	void setDisplayBorders(bool db)
	{
		if(db == false) return;
		fprintf(mFile,"setAttr \".db\" %i;\n", db);

	}
	void setDisplayFacesWithGroupId(int dfgi)
	{
		if(dfgi == -2) return;
		fprintf(mFile,"setAttr \".dfgi\" %i;\n", dfgi);

	}
	void setDisplayCenter(bool dc)
	{
		if(dc == false) return;
		fprintf(mFile,"setAttr \".dc\" %i;\n", dc);

	}
	void setDisplayTriangles(bool dt)
	{
		if(dt == false) return;
		fprintf(mFile,"setAttr \".dt\" %i;\n", dt);

	}
	void setDisplayUVs(bool duv)
	{
		if(duv == false) return;
		fprintf(mFile,"setAttr \".duv\" %i;\n", duv);

	}
	void setDisplayItemNumbers(int din)
	{
		if(din == 0) return;
		fprintf(mFile,"setAttr \".din\" %i;\n", din);

	}
	void setDisplayNonPlanar(bool dnp)
	{
		if(dnp == false) return;
		fprintf(mFile,"setAttr \".dnp\" %i;\n", dnp);

	}
	void setBackfaceCulling(unsigned int bck)
	{
		if(bck == 0) return;
		fprintf(mFile,"setAttr \".bck\" %i;\n", bck);

	}
	void setVertexBackfaceCulling(bool vbc)
	{
		if(vbc == true) return;
		fprintf(mFile,"setAttr \".vbc\" %i;\n", vbc);

	}
	void setVertexSize(double vs)
	{
		if(vs == 3.0) return;
		fprintf(mFile,"setAttr \".vs\" %f;\n", vs);

	}
	void setUvSize(double usz)
	{
		if(usz == 4.0) return;
		fprintf(mFile,"setAttr \".usz\" %f;\n", usz);

	}
	void setBorderWidth(double bw)
	{
		if(bw == 2.0) return;
		fprintf(mFile,"setAttr \".bw\" %f;\n", bw);

	}
	void setNormalSize(double ns)
	{
		if(ns == 0.4) return;
		fprintf(mFile,"setAttr \".ns\" %f;\n", ns);

	}
	void setNormalType(unsigned int ndt)
	{
		if(ndt == 0) return;
		fprintf(mFile,"setAttr \".ndt\" %i;\n", ndt);

	}
	void setDisplayNormal(bool dn)
	{
		if(dn == false) return;
		fprintf(mFile,"setAttr \".dn\" %i;\n", dn);

	}
	void setDisplayTangent(bool dtn)
	{
		if(dtn == false) return;
		fprintf(mFile,"setAttr \".dtn\" %i;\n", dtn);

	}
	void setTangentSpace(unsigned int tgsp)
	{
		if(tgsp == 0) return;
		fprintf(mFile,"setAttr \".tgsp\" %i;\n", tgsp);

	}
	void setTangentSmoothingAngle(double tsa)
	{
		if(tsa == 0) return;
		fprintf(mFile,"setAttr \".tsa\" %f;\n", tsa);

	}
	void setTangentNormalThreshold(double tnt)
	{
		if(tnt == 0) return;
		fprintf(mFile,"setAttr \".tnt\" %f;\n", tnt);

	}
	void setAllowTopologyMod(bool atm)
	{
		if(atm == true) return;
		fprintf(mFile,"setAttr \".atm\" %i;\n", atm);

	}
	void setMaterialBlend(unsigned int matb)
	{
		if(matb == 0) return;
		fprintf(mFile,"setAttr \".matb\" %i;\n", matb);

	}
	void setUserTrg(const string& utrg)
	{
		if(utrg == "NULL") return;
		fprintf(mFile,"setAttr \".utrg\" -type \"string\" ");
		utrg.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDispResolution(unsigned int dr)
	{
		if(dr == 0) return;
		fprintf(mFile,"setAttr \".dr\" %i;\n", dr);

	}
	void setDisplaySmoothMesh(unsigned int dsm)
	{
		if(dsm == 0) return;
		fprintf(mFile,"setAttr \".dsm\" %i;\n", dsm);

	}
	void setSmoothMeshSelectionMode(unsigned int ssm)
	{
		if(ssm == 0) return;
		fprintf(mFile,"setAttr \".ssm\" %i;\n", ssm);

	}
	void setReuseTriangles(bool rtri)
	{
		if(rtri == false) return;
		fprintf(mFile,"setAttr \".rtri\" %i;\n", rtri);

	}
	void setQuadSplit(unsigned int qsp)
	{
		if(qsp == 2) return;
		fprintf(mFile,"setAttr \".qsp\" %i;\n", qsp);

	}
	void setPerInstanceIndex(size_t pii_i,int pii)
	{
		if(pii == -1) return;
		fprintf(mFile,"setAttr \".pii[%i]\" %i;\n", pii_i,pii);

	}
	void setPerInstanceIndex(size_t pii_start,size_t pii_end,int* pii)
	{
		fprintf(mFile,"setAttr \".pii[%i:%i]\" ", pii_start,pii_end);
		size_t size = (pii_end-pii_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",pii[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startPerInstanceIndex(size_t pii_start,size_t pii_end)
	{
		fprintf(mFile,"setAttr \".pii[%i:%i]\"",pii_start,pii_end);

	}
	void appendPerInstanceIndex(int pii)
	{
		fprintf(mFile," %i",pii);

	}
	void endPerInstanceIndex()
	{
		fprintf(mFile,";\n");

	}
	void setPerInstanceTag(size_t pit_i,int pit)
	{
		if(pit == -1) return;
		fprintf(mFile,"setAttr \".pit[%i]\" %i;\n", pit_i,pit);

	}
	void setPerInstanceTag(size_t pit_start,size_t pit_end,int* pit)
	{
		fprintf(mFile,"setAttr \".pit[%i:%i]\" ", pit_start,pit_end);
		size_t size = (pit_end-pit_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",pit[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startPerInstanceTag(size_t pit_start,size_t pit_end)
	{
		fprintf(mFile,"setAttr \".pit[%i:%i]\"",pit_start,pit_end);

	}
	void appendPerInstanceTag(int pit)
	{
		fprintf(mFile," %i",pit);

	}
	void endPerInstanceTag()
	{
		fprintf(mFile,";\n");

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
	void setDisplayAlphaAsGreyScale(bool dags)
	{
		if(dags == false) return;
		fprintf(mFile,"setAttr \".dags\" %i;\n", dags);

	}
	void getInMesh()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getOutMesh()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOutGeometryClean()
	{
		fprintf(mFile,"\"%s.ogc\"",mName.c_str());

	}
	void getWorldMesh(size_t w_i)
	{
		fprintf(mFile,"\"%s.w[%i]\"",mName.c_str(),w_i);

	}
	void getCachedSmoothMesh()
	{
		fprintf(mFile,"\"%s.cs\"",mName.c_str());

	}
	void getSmoothWarn()
	{
		fprintf(mFile,"\"%s.sw\"",mName.c_str());

	}
	void getSmoothLevel()
	{
		fprintf(mFile,"\"%s.lev\"",mName.c_str());

	}
	void getContinuity()
	{
		fprintf(mFile,"\"%s.co\"",mName.c_str());

	}
	void getSmoothUVs()
	{
		fprintf(mFile,"\"%s.suv\"",mName.c_str());

	}
	void getKeepBorder()
	{
		fprintf(mFile,"\"%s.kb\"",mName.c_str());

	}
	void getKeepHardEdge()
	{
		fprintf(mFile,"\"%s.khe\"",mName.c_str());

	}
	void getPropagateEdgeHardness()
	{
		fprintf(mFile,"\"%s.peh\"",mName.c_str());

	}
	void getKeepMapBorders()
	{
		fprintf(mFile,"\"%s.kmb\"",mName.c_str());

	}
	void getSmoothOffset()
	{
		fprintf(mFile,"\"%s.so\"",mName.c_str());

	}
	void getSofx()
	{
		fprintf(mFile,"\"%s.so.sx\"",mName.c_str());

	}
	void getSofy()
	{
		fprintf(mFile,"\"%s.so.sy\"",mName.c_str());

	}
	void getSofz()
	{
		fprintf(mFile,"\"%s.so.sz\"",mName.c_str());

	}
	void getDisplaySubdComps()
	{
		fprintf(mFile,"\"%s.dsc\"",mName.c_str());

	}
	void getUseMaxEdgeLength()
	{
		fprintf(mFile,"\"%s.uxe\"",mName.c_str());

	}
	void getUseMinEdgeLength()
	{
		fprintf(mFile,"\"%s.uie\"",mName.c_str());

	}
	void getUseMaxSubdivisions()
	{
		fprintf(mFile,"\"%s.uxs\"",mName.c_str());

	}
	void getUseMaxUV()
	{
		fprintf(mFile,"\"%s.uxu\"",mName.c_str());

	}
	void getUseMinScreen()
	{
		fprintf(mFile,"\"%s.uns\"",mName.c_str());

	}
	void getUseNumTriangles()
	{
		fprintf(mFile,"\"%s.unp\"",mName.c_str());

	}
	void getNumTriangles()
	{
		fprintf(mFile,"\"%s.nt\"",mName.c_str());

	}
	void getMaxEdgeLength()
	{
		fprintf(mFile,"\"%s.mxe\"",mName.c_str());

	}
	void getMinEdgeLength()
	{
		fprintf(mFile,"\"%s.mne\"",mName.c_str());

	}
	void getMaxSubd()
	{
		fprintf(mFile,"\"%s.mxs\"",mName.c_str());

	}
	void getMaxUv()
	{
		fprintf(mFile,"\"%s.xuv\"",mName.c_str());

	}
	void getMinScreen()
	{
		fprintf(mFile,"\"%s.mns\"",mName.c_str());

	}
	void getMaxTriangles()
	{
		fprintf(mFile,"\"%s.tsl\"",mName.c_str());

	}
	void getPnts(size_t pt_i)
	{
		fprintf(mFile,"\"%s.pt[%i]\"",mName.c_str(),pt_i);

	}
	void getPntx(size_t pt_i)
	{
		fprintf(mFile,"\"%s.pt[%i].px\"",mName.c_str(),pt_i);

	}
	void getPnty(size_t pt_i)
	{
		fprintf(mFile,"\"%s.pt[%i].py\"",mName.c_str(),pt_i);

	}
	void getPntz(size_t pt_i)
	{
		fprintf(mFile,"\"%s.pt[%i].pz\"",mName.c_str(),pt_i);

	}
	void getVrtx(size_t vt_i)
	{
		fprintf(mFile,"\"%s.vt[%i].vx\"",mName.c_str(),vt_i);

	}
	void getVrty(size_t vt_i)
	{
		fprintf(mFile,"\"%s.vt[%i].vy\"",mName.c_str(),vt_i);

	}
	void getVrtz(size_t vt_i)
	{
		fprintf(mFile,"\"%s.vt[%i].vz\"",mName.c_str(),vt_i);

	}
	void getEdg1(size_t ed_i)
	{
		fprintf(mFile,"\"%s.ed[%i].e1\"",mName.c_str(),ed_i);

	}
	void getEdg2(size_t ed_i)
	{
		fprintf(mFile,"\"%s.ed[%i].e2\"",mName.c_str(),ed_i);

	}
	void getEdgh(size_t ed_i)
	{
		fprintf(mFile,"\"%s.ed[%i].eh\"",mName.c_str(),ed_i);

	}
	void getUvpx(size_t uv_i)
	{
		fprintf(mFile,"\"%s.uv[%i].ux\"",mName.c_str(),uv_i);

	}
	void getUvpy(size_t uv_i)
	{
		fprintf(mFile,"\"%s.uv[%i].uy\"",mName.c_str(),uv_i);

	}
	void getColorPerVertex()
	{
		fprintf(mFile,"\"%s.cpvx\"",mName.c_str());

	}
	void getVertexColor(size_t vclr_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i]\"",mName.c_str(),vclr_i);

	}
	void getVertexColorRGB(size_t vclr_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb\"",mName.c_str(),vclr_i);

	}
	void getVertexColorR(size_t vclr_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcr\"",mName.c_str(),vclr_i);

	}
	void getVertexColorG(size_t vclr_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcg\"",mName.c_str(),vclr_i);

	}
	void getVertexColorB(size_t vclr_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vrgb.vxcb\"",mName.c_str(),vclr_i);

	}
	void getVertexAlpha(size_t vclr_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vxal\"",mName.c_str(),vclr_i);

	}
	void getVertexFaceColor(size_t vclr_i,size_t vfcl_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i]\"",mName.c_str(),vclr_i,vfcl_i);

	}
	void getVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb\"",mName.c_str(),vclr_i,vfcl_i);

	}
	void getVertexFaceColorR(size_t vclr_i,size_t vfcl_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcr\"",mName.c_str(),vclr_i,vfcl_i);

	}
	void getVertexFaceColorG(size_t vclr_i,size_t vfcl_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcg\"",mName.c_str(),vclr_i,vfcl_i);

	}
	void getVertexFaceColorB(size_t vclr_i,size_t vfcl_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcb\"",mName.c_str(),vclr_i,vfcl_i);

	}
	void getVertexFaceAlpha(size_t vclr_i,size_t vfcl_i)
	{
		fprintf(mFile,"\"%s.cpvx.vclr[%i].vfcl[%i].vfal\"",mName.c_str(),vclr_i,vfcl_i);

	}
	void getDisplayVertices()
	{
		fprintf(mFile,"\"%s.dv\"",mName.c_str());

	}
	void getDisplayBorders()
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());

	}
	void getDisplayEdges()
	{
		fprintf(mFile,"\"%s.de\"",mName.c_str());

	}
	void getDisplayFacesWithGroupId()
	{
		fprintf(mFile,"\"%s.dfgi\"",mName.c_str());

	}
	void getDisplayCenter()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
	void getDisplayTriangles()
	{
		fprintf(mFile,"\"%s.dt\"",mName.c_str());

	}
	void getDisplayUVs()
	{
		fprintf(mFile,"\"%s.duv\"",mName.c_str());

	}
	void getDisplayItemNumbers()
	{
		fprintf(mFile,"\"%s.din\"",mName.c_str());

	}
	void getDisplayNonPlanar()
	{
		fprintf(mFile,"\"%s.dnp\"",mName.c_str());

	}
	void getBackfaceCulling()
	{
		fprintf(mFile,"\"%s.bck\"",mName.c_str());

	}
	void getVertexBackfaceCulling()
	{
		fprintf(mFile,"\"%s.vbc\"",mName.c_str());

	}
	void getVertexSize()
	{
		fprintf(mFile,"\"%s.vs\"",mName.c_str());

	}
	void getUvSize()
	{
		fprintf(mFile,"\"%s.usz\"",mName.c_str());

	}
	void getBorderWidth()
	{
		fprintf(mFile,"\"%s.bw\"",mName.c_str());

	}
	void getNormalSize()
	{
		fprintf(mFile,"\"%s.ns\"",mName.c_str());

	}
	void getNormalType()
	{
		fprintf(mFile,"\"%s.ndt\"",mName.c_str());

	}
	void getDisplayNormal()
	{
		fprintf(mFile,"\"%s.dn\"",mName.c_str());

	}
	void getDisplayTangent()
	{
		fprintf(mFile,"\"%s.dtn\"",mName.c_str());

	}
	void getTangentSpace()
	{
		fprintf(mFile,"\"%s.tgsp\"",mName.c_str());

	}
	void getTangentSmoothingAngle()
	{
		fprintf(mFile,"\"%s.tsa\"",mName.c_str());

	}
	void getTangentNormalThreshold()
	{
		fprintf(mFile,"\"%s.tnt\"",mName.c_str());

	}
	void getAllowTopologyMod()
	{
		fprintf(mFile,"\"%s.atm\"",mName.c_str());

	}
	void getMaterialBlend()
	{
		fprintf(mFile,"\"%s.matb\"",mName.c_str());

	}
	void getUserTrg()
	{
		fprintf(mFile,"\"%s.utrg\"",mName.c_str());

	}
	void getDispResolution()
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());

	}
	void getReuseTriangles()
	{
		fprintf(mFile,"\"%s.rtri\"",mName.c_str());

	}
	void getQuadSplit()
	{
		fprintf(mFile,"\"%s.qsp\"",mName.c_str());

	}
	void getPerInstanceIndex(size_t pii_i)
	{
		fprintf(mFile,"\"%s.pii[%i]\"",mName.c_str(),pii_i);

	}
	void getPerInstanceTag(size_t pit_i)
	{
		fprintf(mFile,"\"%s.pit[%i]\"",mName.c_str(),pit_i);

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
	void getDisplayAlphaAsGreyScale()
	{
		fprintf(mFile,"\"%s.dags\"",mName.c_str());

	}
protected:
	Mesh(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_MESH_H__
