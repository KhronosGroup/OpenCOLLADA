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
/*
<p><pre>
 Manage a subdivision surface shape

</pre></p>
*/
class Subdiv : public SurfaceShape
{
public:
	/*The attribute for the vertices*/
	struct Vertex{
		void write(FILE* file) const
		{
		}
	};
	/*The attribute for the vertex tweaks on shapes with history*/
	struct VertexTweak{
		double3* singleVertexTweak;
		void write(FILE* file) const
		{
			size_t size = sizeof(singleVertexTweak)/sizeof(double3);
			for(size_t i=0; i<size; ++i)
			{
				singleVertexTweak[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*This is a root of following mental ray attributes.*/
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
			fprintf_s(file,"%i ", miOverrideCaustics);
			fprintf_s(file,"%i ", miCausticAccuracy);
			fprintf_s(file,"%f ", miCausticRadius);
			fprintf_s(file,"%i ", miOverrideGlobalIllumination);
			fprintf_s(file,"%i ", miGlobillumAccuracy);
			fprintf_s(file,"%f ", miGlobillumRadius);
			fprintf_s(file,"%i ", miOverrideFinalGather);
			fprintf_s(file,"%i ", miFinalGatherRays);
			fprintf_s(file,"%f ", miFinalGatherMinRadius);
			fprintf_s(file,"%f ", miFinalGatherMaxRadius);
			fprintf_s(file,"%i ", miFinalGatherFilter);
			fprintf_s(file,"%i ", miFinalGatherView);
			fprintf_s(file,"%i ", miOverrideSamples);
			fprintf_s(file,"%i ", miMinSamples);
			fprintf_s(file,"%i ", miMaxSamples);
			fprintf_s(file,"%i ", miFinalGatherCast);
			fprintf_s(file,"%i ", miFinalGatherReceive);
			fprintf_s(file,"%i ", miTransparencyCast);
			fprintf_s(file,"%i ", miTransparencyReceive);
			fprintf_s(file,"%i ", miReflectionReceive);
			fprintf_s(file,"%i", miRefractionReceive);
		}
	};
public:
	Subdiv(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "subdiv"){}
	virtual ~Subdiv(){}
	/*The input subdivision surface in local space.*/
	void setCreate(const SubdivisionSurfaceID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*Used to store an internal copy of the surface for faster evaluation*/
	void setCached(const SubdivisionSurfaceID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc\";\n",mName.c_str());}
	/*Controls explicit CV display*/
	void setDispVertices(bool dv){if(dv == false) return; fprintf_s(mFile, "setAttr \".dv\" %i;\n", dv);}
	/*Controls explicit CV display*/
	void setDispVertices(const BoolID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*Control Display of vertices as Limit Points on Surface. Conditional on display vertices.*/
	void setDispVerticesAsLimitPoints(const BoolID& dvl){fprintf_s(mFile,"connectAttr \"");dvl.write(mFile);fprintf_s(mFile,"\" \"%s.dvl\";\n",mName.c_str());}
	/*Localize edit of more than one limit point. Conditional on display vertices as limit points.*/
	void setLocalizeLimitPointsEdit(const BoolID& llp){fprintf_s(mFile,"connectAttr \"");llp.write(mFile);fprintf_s(mFile,"\" \"%s.llp\";\n",mName.c_str());}
	/*Controls explicit edge display*/
	void setDispEdges(bool de){if(de == false) return; fprintf_s(mFile, "setAttr \".de\" %i;\n", de);}
	/*Controls explicit edge display*/
	void setDispEdges(const BoolID& de){fprintf_s(mFile,"connectAttr \"");de.write(mFile);fprintf_s(mFile,"\" \"%s.de\";\n",mName.c_str());}
	/*Controls explicit face display*/
	void setDispFaces(bool df){if(df == false) return; fprintf_s(mFile, "setAttr \".df\" %i;\n", df);}
	/*Controls explicit face display*/
	void setDispFaces(const BoolID& df){fprintf_s(mFile,"connectAttr \"");df.write(mFile);fprintf_s(mFile,"\" \"%s.df\";\n",mName.c_str());}
	/*Controls explicit UV texture map co-ordinates display*/
	void setDispMaps(bool dm){if(dm == false) return; fprintf_s(mFile, "setAttr \".dm\" %i;\n", dm);}
	/*Controls explicit UV texture map co-ordinates display*/
	void setDispMaps(const BoolID& dm){fprintf_s(mFile,"connectAttr \"");dm.write(mFile);fprintf_s(mFile,"\" \"%s.dm\";\n",mName.c_str());}
	/*Controls explicit UV texture map border display*/
	void setDispUVBorder(bool db){if(db == false) return; fprintf_s(mFile, "setAttr \".db\" %i;\n", db);}
	/*Controls explicit UV texture map border display*/
	void setDispUVBorder(const BoolID& db){fprintf_s(mFile,"connectAttr \"");db.write(mFile);fprintf_s(mFile,"\" \"%s.db\";\n",mName.c_str());}
	/*This attribute currently has no effect in Maya.*/
	void setDispCreases(bool dcr){if(dcr == false) return; fprintf_s(mFile, "setAttr \".dcr\" %i;\n", dcr);}
	/*This attribute currently has no effect in Maya.*/
	void setDispCreases(const BoolID& dcr){fprintf_s(mFile,"connectAttr \"");dcr.write(mFile);fprintf_s(mFile,"\" \"%s.dcr\";\n",mName.c_str());}
	/*Controls explicit geometry display*/
	void setDispGeometry(bool dg){if(dg == true) return; fprintf_s(mFile, "setAttr \".dg\" %i;\n", dg);}
	/*Controls explicit geometry display*/
	void setDispGeometry(const BoolID& dg){fprintf_s(mFile,"connectAttr \"");dg.write(mFile);fprintf_s(mFile,"\" \"%s.dg\";\n",mName.c_str());}
	/*Controls resolution at which surface is displayed*/
	void setDispResolution(int dr){if(dr == 1) return; fprintf_s(mFile, "setAttr \".dr\" %i;\n", dr);}
	/*Controls resolution at which surface is displayed*/
	void setDispResolution(const IntID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*The attribute for the vertices*/
	void setVertex(size_t vt_i,const VertexID& vt){fprintf_s(mFile,"connectAttr \"");vt.write(mFile);fprintf_s(mFile,"\" \"%s.vt[%i]\";\n",mName.c_str(),vt_i);}
	/*The attribute for the vertices*/
	void setSingleVertex(size_t vt_i,size_t svt_i,const Double3ID& svt){fprintf_s(mFile,"connectAttr \"");svt.write(mFile);fprintf_s(mFile,"\" \"%s.vt[%i].svt[%i]\";\n",mName.c_str(),vt_i,svt_i);}
	/*The attribute for the vertices*/
	void setSingleVertexX(size_t vt_i,size_t svt_i,const DoubleID& svx){fprintf_s(mFile,"connectAttr \"");svx.write(mFile);fprintf_s(mFile,"\" \"%s.vt[%i].svt[%i].svx\";\n",mName.c_str(),vt_i,svt_i);}
	/*The attribute for the vertices*/
	void setSingleVertexY(size_t vt_i,size_t svt_i,const DoubleID& svy){fprintf_s(mFile,"connectAttr \"");svy.write(mFile);fprintf_s(mFile,"\" \"%s.vt[%i].svt[%i].svy\";\n",mName.c_str(),vt_i,svt_i);}
	/*The attribute for the vertices*/
	void setSingleVertexZ(size_t vt_i,size_t svt_i,const DoubleID& svz){fprintf_s(mFile,"connectAttr \"");svz.write(mFile);fprintf_s(mFile,"\" \"%s.vt[%i].svt[%i].svz\";\n",mName.c_str(),vt_i,svt_i);}
	/*The attribute for the vertex tweaks on shapes with history*/
	void setVertexTweak(size_t vtw_i,const VertexTweak& vtw){fprintf_s(mFile, "setAttr \".vtw[%i]\" ",vtw_i);vtw.write(mFile);fprintf_s(mFile,";\n");}
	/*The attribute for the vertex tweaks on shapes with history*/
	void setVertexTweak(size_t vtw_i,const VertexTweakID& vtw){fprintf_s(mFile,"connectAttr \"");vtw.write(mFile);fprintf_s(mFile,"\" \"%s.vtw[%i]\";\n",mName.c_str(),vtw_i);}
	/*The attribute for the vertex tweaks on shapes with history*/
	void setSingleVertexTweak(size_t vtw_i,size_t stw_i,const double3& stw){fprintf_s(mFile, "setAttr \".vtw[%i].stw[%i]\" -type \"double3\" ",vtw_i,stw_i);stw.write(mFile);fprintf_s(mFile,";\n");}
	/*The attribute for the vertex tweaks on shapes with history*/
	void setSingleVertexTweak(size_t vtw_i,size_t stw_start,size_t stw_end,double* stw){fprintf_s(mFile,"setAttr \".vtw[%i].stw[%i:%i]\" ", vtw_i,stw_start,stw_end);size_t size = (stw_end-stw_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",stw[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*The attribute for the vertex tweaks on shapes with history*/
	void setSingleVertexTweak(size_t vtw_i,size_t stw_i,const Double3ID& stw){fprintf_s(mFile,"connectAttr \"");stw.write(mFile);fprintf_s(mFile,"\" \"%s.vtw[%i].stw[%i]\";\n",mName.c_str(),vtw_i,stw_i);}
	/*The attribute for the vertex tweaks on shapes with history - x value*/
	void setSingleVertexTweakX(size_t vtw_i,size_t stw_i,double stwx){if(stwx == 0) return; fprintf_s(mFile, "setAttr \".vtw[%i].stw[%i].stwx\" %f;\n", vtw_i,stw_i,stwx);}
	/*The attribute for the vertex tweaks on shapes with history - x value*/
	void setSingleVertexTweakX(size_t vtw_i,size_t stw_i,const DoubleID& stwx){fprintf_s(mFile,"connectAttr \"");stwx.write(mFile);fprintf_s(mFile,"\" \"%s.vtw[%i].stw[%i].stwx\";\n",mName.c_str(),vtw_i,stw_i);}
	/*The attribute for the vertex tweaks on shapes with history - y value*/
	void setSingleVertexTweakY(size_t vtw_i,size_t stw_i,double stwy){if(stwy == 0) return; fprintf_s(mFile, "setAttr \".vtw[%i].stw[%i].stwy\" %f;\n", vtw_i,stw_i,stwy);}
	/*The attribute for the vertex tweaks on shapes with history - y value*/
	void setSingleVertexTweakY(size_t vtw_i,size_t stw_i,const DoubleID& stwy){fprintf_s(mFile,"connectAttr \"");stwy.write(mFile);fprintf_s(mFile,"\" \"%s.vtw[%i].stw[%i].stwy\";\n",mName.c_str(),vtw_i,stw_i);}
	/*The attribute for the vertex tweaks on shapes with history - z value*/
	void setSingleVertexTweakZ(size_t vtw_i,size_t stw_i,double stwz){if(stwz == 0) return; fprintf_s(mFile, "setAttr \".vtw[%i].stw[%i].stwz\" %f;\n", vtw_i,stw_i,stwz);}
	/*The attribute for the vertex tweaks on shapes with history - z value*/
	void setSingleVertexTweakZ(size_t vtw_i,size_t stw_i,const DoubleID& stwz){fprintf_s(mFile,"connectAttr \"");stwz.write(mFile);fprintf_s(mFile,"\" \"%s.vtw[%i].stw[%i].stwz\";\n",mName.c_str(),vtw_i,stw_i);}
	/*The output subdivision surface.*/
	void setOutSubdiv(const SubdivisionSurfaceID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The output subdivision surface in world space.*/
	void setWorldSubdiv(size_t ws_i,const SubdivisionSurfaceID& ws){fprintf_s(mFile,"connectAttr \"");ws.write(mFile);fprintf_s(mFile,"\" \"%s.ws[%i]\";\n",mName.c_str(),ws_i);}
	/*Edge creases*/
	void setEdgeCrease(const SubdivEdgeCreaseID& ecr){fprintf_s(mFile,"connectAttr \"");ecr.write(mFile);fprintf_s(mFile,"\" \"%s.ecr\";\n",mName.c_str());}
	/*Texture Coordinates*/
	void setTextureCoord(const SubdivTextCoordID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*
	Face corner UV Ids. Explicit UVs on subdiv surfaces are stored on a
	per-face per-vertex basis. This attribute is used to specify
	the UV ids on a per-face per-vertex for each UV set that exists
	on the surface. The values on this attribute are to be used in
	conjunction with the UVSetPoints attribute defined in the parent
	controlPointShape class, since that attribute holds on to the uv values
	corresponding to these ids.
	*/
	void setFaceUVIds(size_t fuv_i,const SubdivFaceUVIdsID& fuv){fprintf_s(mFile,"connectAttr \"");fuv.write(mFile);fprintf_s(mFile,"\" \"%s.fuv[%i]\";\n",mName.c_str(),fuv_i);}
	/*Specifies the scaling factor for the surface normal display.*/
	void setNormalsDisplayScale(double ndf){if(ndf == 1.0) return; fprintf_s(mFile, "setAttr \".ndf\" %f;\n", ndf);}
	/*Specifies the scaling factor for the surface normal display.*/
	void setNormalsDisplayScale(const DoubleID& ndf){fprintf_s(mFile,"connectAttr \"");ndf.write(mFile);fprintf_s(mFile,"\" \"%s.ndf\";\n",mName.c_str());}
	/*Format: 0 - Uniform, 1 - Adaptive (Leaf Level)*/
	void setFormat(unsigned int f){if(f == 1) return; fprintf_s(mFile, "setAttr \".f\" %i;\n", f);}
	/*Format: 0 - Uniform, 1 - Adaptive (Leaf Level)*/
	void setFormat(const UnsignedintID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*The depth at which constant-depth tessellates the surface*/
	void setDepth(int d){if(d == 2) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*The depth at which constant-depth tessellates the surface*/
	void setDepth(const IntID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The number of samples per face*/
	void setSampleCount(int sc){if(sc == 4) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*The number of samples per face*/
	void setSampleCount(const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*
	The level at which components (vertices, edges, faces...) will be
	displayed. Valid values are 0=Base through 13=Finest.
	*/
	void setDisplayLevel(unsigned int dl){if(dl == 0) return; fprintf_s(mFile, "setAttr \".dl\" %i;\n", dl);}
	/*
	The level at which components (vertices, edges, faces...) will be
	displayed. Valid values are 0=Base through 13=Finest.
	*/
	void setDisplayLevel(const UnsignedintID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*
	Determines whether diplay includes components "edited" or
	"visited" at the current display level.  Valid values are
	0=Edited, 1=Visited, or 2=All.
	*/
	void setDisplayFilter(unsigned int dfl){if(dfl == 0) return; fprintf_s(mFile, "setAttr \".dfl\" %i;\n", dfl);}
	/*
	Determines whether diplay includes components "edited" or
	"visited" at the current display level.  Valid values are
	0=Edited, 1=Visited, or 2=All.
	*/
	void setDisplayFilter(const UnsignedintID& dfl){fprintf_s(mFile,"connectAttr \"");dfl.write(mFile);fprintf_s(mFile,"\" \"%s.dfl\";\n",mName.c_str());}
	/*The number of base mesh faces*/
	void setBaseFaceCount(const IntID& bfc){fprintf_s(mFile,"connectAttr \"");bfc.write(mFile);fprintf_s(mFile,"\" \"%s.bfc\";\n",mName.c_str());}
	/*The number of faces at level 1*/
	void setLevelOneFaceCount(const IntID& ofc){fprintf_s(mFile,"connectAttr \"");ofc.write(mFile);fprintf_s(mFile,"\" \"%s.ofc\";\n",mName.c_str());}
	/*
	Controls how scaling of coarser vertices affects finer ones.
	When set to "Propagate", scaling applied to coarser vertices
	is propagated to those at finer levels of the hierarchy.  This
	has the effect of making hierarchically-added geometric features
	scale with the surface as coarser vertices are manipulated.
	When this attribute is set to "Ignore", scaling applied to
	coarser vertices is ignored at finer levels of the hierarchy.
	This has the effect of making hierarchically-added geometric
	features maintain their size as the rest of the surface is manipulated.
	Note that this attribute has no effect on scaling applied to
	the entire object via transforms anywhere above it in the DAG,
	only to vertices of the surface via component manipulation
	or (indirectly) via deformations applied to vertices.
	*/
	void setScalingHierarchy(unsigned int sh){if(sh == 1) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*
	Controls how scaling of coarser vertices affects finer ones.
	When set to "Propagate", scaling applied to coarser vertices
	is propagated to those at finer levels of the hierarchy.  This
	has the effect of making hierarchically-added geometric features
	scale with the surface as coarser vertices are manipulated.
	When this attribute is set to "Ignore", scaling applied to
	coarser vertices is ignored at finer levels of the hierarchy.
	This has the effect of making hierarchically-added geometric
	features maintain their size as the rest of the surface is manipulated.
	Note that this attribute has no effect on scaling applied to
	the entire object via transforms anywhere above it in the DAG,
	only to vertices of the surface via component manipulation
	or (indirectly) via deformations applied to vertices.
	*/
	void setScalingHierarchy(const UnsignedintID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(bool oca){if(oca == false) return; fprintf_s(mFile, "setAttr \".mrc.oca\" %i;\n", oca);}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(const BoolID& oca){fprintf_s(mFile,"connectAttr \"");oca.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oca\";\n",mName.c_str());}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(short caa){if(caa == 64) return; fprintf_s(mFile, "setAttr \".mrc.caa\" %i;\n", caa);}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(const ShortID& caa){fprintf_s(mFile,"connectAttr \"");caa.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.caa\";\n",mName.c_str());}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(float car){if(car == 0) return; fprintf_s(mFile, "setAttr \".mrc.car\" %f;\n", car);}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(const FloatID& car){fprintf_s(mFile,"connectAttr \"");car.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.car\";\n",mName.c_str());}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(bool ogi){if(ogi == false) return; fprintf_s(mFile, "setAttr \".mrc.ogi\" %i;\n", ogi);}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(const BoolID& ogi){fprintf_s(mFile,"connectAttr \"");ogi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ogi\";\n",mName.c_str());}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(short gia){if(gia == 64) return; fprintf_s(mFile, "setAttr \".mrc.gia\" %i;\n", gia);}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(const ShortID& gia){fprintf_s(mFile,"connectAttr \"");gia.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gia\";\n",mName.c_str());}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(float gir){if(gir == 0) return; fprintf_s(mFile, "setAttr \".mrc.gir\" %f;\n", gir);}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(const FloatID& gir){fprintf_s(mFile,"connectAttr \"");gir.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gir\";\n",mName.c_str());}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(bool ofg){if(ofg == false) return; fprintf_s(mFile, "setAttr \".mrc.ofg\" %i;\n", ofg);}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(const BoolID& ofg){fprintf_s(mFile,"connectAttr \"");ofg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ofg\";\n",mName.c_str());}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(int fry){if(fry == 1000) return; fprintf_s(mFile, "setAttr \".mrc.fry\" %i;\n", fry);}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(const IntID& fry){fprintf_s(mFile,"connectAttr \"");fry.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fry\";\n",mName.c_str());}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(float fmn){if(fmn == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmn\" %f;\n", fmn);}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(const FloatID& fmn){fprintf_s(mFile,"connectAttr \"");fmn.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmn\";\n",mName.c_str());}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(float fmx){if(fmx == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmx\" %f;\n", fmx);}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(const FloatID& fmx){fprintf_s(mFile,"connectAttr \"");fmx.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmx\";\n",mName.c_str());}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(short ffi){if(ffi == 1) return; fprintf_s(mFile, "setAttr \".mrc.ffi\" %i;\n", ffi);}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(const ShortID& ffi){fprintf_s(mFile,"connectAttr \"");ffi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ffi\";\n",mName.c_str());}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(bool fgv){if(fgv == false) return; fprintf_s(mFile, "setAttr \".mrc.fgv\" %i;\n", fgv);}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(const BoolID& fgv){fprintf_s(mFile,"connectAttr \"");fgv.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgv\";\n",mName.c_str());}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	void setMiOverrideSamples(bool oos){if(oos == false) return; fprintf_s(mFile, "setAttr \".mrc.oos\" %i;\n", oos);}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	void setMiOverrideSamples(const BoolID& oos){fprintf_s(mFile,"connectAttr \"");oos.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oos\";\n",mName.c_str());}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(short mins){if(mins == 0) return; fprintf_s(mFile, "setAttr \".mrc.mins\" %i;\n", mins);}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(const ShortID& mins){fprintf_s(mFile,"connectAttr \"");mins.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mins\";\n",mName.c_str());}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(short maxs){if(maxs == 2) return; fprintf_s(mFile, "setAttr \".mrc.maxs\" %i;\n", maxs);}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(const ShortID& maxs){fprintf_s(mFile,"connectAttr \"");maxs.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.maxs\";\n",mName.c_str());}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	void setMiFinalGatherCast(bool fgc){if(fgc == true) return; fprintf_s(mFile, "setAttr \".mrc.fgc\" %i;\n", fgc);}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	void setMiFinalGatherCast(const BoolID& fgc){fprintf_s(mFile,"connectAttr \"");fgc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgc\";\n",mName.c_str());}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	void setMiFinalGatherReceive(bool fge){if(fge == true) return; fprintf_s(mFile, "setAttr \".mrc.fge\" %i;\n", fge);}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	void setMiFinalGatherReceive(const BoolID& fge){fprintf_s(mFile,"connectAttr \"");fge.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fge\";\n",mName.c_str());}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	void setMiTransparencyCast(bool tpc){if(tpc == true) return; fprintf_s(mFile, "setAttr \".mrc.tpc\" %i;\n", tpc);}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	void setMiTransparencyCast(const BoolID& tpc){fprintf_s(mFile,"connectAttr \"");tpc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.tpc\";\n",mName.c_str());}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	void setMiTransparencyReceive(bool tpr){if(tpr == true) return; fprintf_s(mFile, "setAttr \".mrc.tpr\" %i;\n", tpr);}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	void setMiTransparencyReceive(const BoolID& tpr){fprintf_s(mFile,"connectAttr \"");tpr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.tpr\";\n",mName.c_str());}
	/*
	The object receives reflection rays if <b>miReflectionReceive</b> is on.
	This flag controls reflection of other objects on this object.
	If disabled, this object will not show any reflection,
	as if the surface is not reflective.
	The casting behaviour is ruled by visibleInReflections flag,
	which controls reflection of this object on other objects.
	Disabling <b>visibleInReflections</b> will make this object
	disappera from reflection.
	*/
	void setMiReflectionReceive(bool rflr){if(rflr == true) return; fprintf_s(mFile, "setAttr \".mrc.rflr\" %i;\n", rflr);}
	/*
	The object receives reflection rays if <b>miReflectionReceive</b> is on.
	This flag controls reflection of other objects on this object.
	If disabled, this object will not show any reflection,
	as if the surface is not reflective.
	The casting behaviour is ruled by visibleInReflections flag,
	which controls reflection of this object on other objects.
	Disabling <b>visibleInReflections</b> will make this object
	disappera from reflection.
	*/
	void setMiReflectionReceive(const BoolID& rflr){fprintf_s(mFile,"connectAttr \"");rflr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.rflr\";\n",mName.c_str());}
	/*
	The object receives refraction rays if <b>miRefractionReceive</b> is on.
	This flag contols refraction of other objects through this object.
	Disabling this value will make this object non-refractive.
	The casting behaviour is ruled by visibleInRefractions flag,
	which controls refraction of this object showing through other objects.
	Disabling <b>visibleInRefractions</b> will make this object disappear
	from refraction.
	*/
	void setMiRefractionReceive(bool rfrr){if(rfrr == true) return; fprintf_s(mFile, "setAttr \".mrc.rfrr\" %i;\n", rfrr);}
	/*
	The object receives refraction rays if <b>miRefractionReceive</b> is on.
	This flag contols refraction of other objects through this object.
	Disabling this value will make this object non-refractive.
	The casting behaviour is ruled by visibleInRefractions flag,
	which controls refraction of this object showing through other objects.
	Disabling <b>visibleInRefractions</b> will make this object disappear
	from refraction.
	*/
	void setMiRefractionReceive(const BoolID& rfrr){fprintf_s(mFile,"connectAttr \"");rfrr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.rfrr\";\n",mName.c_str());}
	/*The input subdivision surface in local space.*/
	SubdivisionSurfaceID getCreate(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*Used to store an internal copy of the surface for faster evaluation*/
	SubdivisionSurfaceID getCached(){char buffer[4096];sprintf_s (buffer, "%s.cc",mName.c_str());return (const char*)buffer;}
	/*Controls explicit CV display*/
	BoolID getDispVertices(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*Control Display of vertices as Limit Points on Surface. Conditional on display vertices.*/
	BoolID getDispVerticesAsLimitPoints(){char buffer[4096];sprintf_s (buffer, "%s.dvl",mName.c_str());return (const char*)buffer;}
	/*Localize edit of more than one limit point. Conditional on display vertices as limit points.*/
	BoolID getLocalizeLimitPointsEdit(){char buffer[4096];sprintf_s (buffer, "%s.llp",mName.c_str());return (const char*)buffer;}
	/*Controls explicit edge display*/
	BoolID getDispEdges(){char buffer[4096];sprintf_s (buffer, "%s.de",mName.c_str());return (const char*)buffer;}
	/*Controls explicit face display*/
	BoolID getDispFaces(){char buffer[4096];sprintf_s (buffer, "%s.df",mName.c_str());return (const char*)buffer;}
	/*Controls explicit UV texture map co-ordinates display*/
	BoolID getDispMaps(){char buffer[4096];sprintf_s (buffer, "%s.dm",mName.c_str());return (const char*)buffer;}
	/*Controls explicit UV texture map border display*/
	BoolID getDispUVBorder(){char buffer[4096];sprintf_s (buffer, "%s.db",mName.c_str());return (const char*)buffer;}
	/*This attribute currently has no effect in Maya.*/
	BoolID getDispCreases(){char buffer[4096];sprintf_s (buffer, "%s.dcr",mName.c_str());return (const char*)buffer;}
	/*Controls explicit geometry display*/
	BoolID getDispGeometry(){char buffer[4096];sprintf_s (buffer, "%s.dg",mName.c_str());return (const char*)buffer;}
	/*Controls resolution at which surface is displayed*/
	IntID getDispResolution(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*The attribute for the vertices*/
	const VertexID& getVertex(size_t vt_i){char buffer[4096];sprintf_s (buffer, "%s.vt[%i]",mName.c_str(),vt_i);return (const char*)buffer;}
	/*The attribute for the vertices*/
	const Double3ID& getSingleVertex(size_t vt_i,size_t svt_i){char buffer[4096];sprintf_s (buffer, "%s.vt[%i].svt[%i]",mName.c_str(),vt_i,svt_i);return (const char*)buffer;}
	/*The attribute for the vertices*/
	const DoubleID& getSingleVertexX(size_t vt_i,size_t svt_i){char buffer[4096];sprintf_s (buffer, "%s.vt[%i].svt[%i].svx",mName.c_str(),vt_i,svt_i);return (const char*)buffer;}
	/*The attribute for the vertices*/
	const DoubleID& getSingleVertexY(size_t vt_i,size_t svt_i){char buffer[4096];sprintf_s (buffer, "%s.vt[%i].svt[%i].svy",mName.c_str(),vt_i,svt_i);return (const char*)buffer;}
	/*The attribute for the vertices*/
	const DoubleID& getSingleVertexZ(size_t vt_i,size_t svt_i){char buffer[4096];sprintf_s (buffer, "%s.vt[%i].svt[%i].svz",mName.c_str(),vt_i,svt_i);return (const char*)buffer;}
	/*The attribute for the vertex tweaks on shapes with history*/
	const VertexTweakID& getVertexTweak(size_t vtw_i){char buffer[4096];sprintf_s (buffer, "%s.vtw[%i]",mName.c_str(),vtw_i);return (const char*)buffer;}
	/*The attribute for the vertex tweaks on shapes with history*/
	const Double3ID& getSingleVertexTweak(size_t vtw_i,size_t stw_i){char buffer[4096];sprintf_s (buffer, "%s.vtw[%i].stw[%i]",mName.c_str(),vtw_i,stw_i);return (const char*)buffer;}
	/*The attribute for the vertex tweaks on shapes with history - x value*/
	const DoubleID& getSingleVertexTweakX(size_t vtw_i,size_t stw_i){char buffer[4096];sprintf_s (buffer, "%s.vtw[%i].stw[%i].stwx",mName.c_str(),vtw_i,stw_i);return (const char*)buffer;}
	/*The attribute for the vertex tweaks on shapes with history - y value*/
	const DoubleID& getSingleVertexTweakY(size_t vtw_i,size_t stw_i){char buffer[4096];sprintf_s (buffer, "%s.vtw[%i].stw[%i].stwy",mName.c_str(),vtw_i,stw_i);return (const char*)buffer;}
	/*The attribute for the vertex tweaks on shapes with history - z value*/
	const DoubleID& getSingleVertexTweakZ(size_t vtw_i,size_t stw_i){char buffer[4096];sprintf_s (buffer, "%s.vtw[%i].stw[%i].stwz",mName.c_str(),vtw_i,stw_i);return (const char*)buffer;}
	/*The output subdivision surface.*/
	SubdivisionSurfaceID getOutSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The output subdivision surface in world space.*/
	const SubdivisionSurfaceID& getWorldSubdiv(size_t ws_i){char buffer[4096];sprintf_s (buffer, "%s.ws[%i]",mName.c_str(),ws_i);return (const char*)buffer;}
	/*Edge creases*/
	SubdivEdgeCreaseID getEdgeCrease(){char buffer[4096];sprintf_s (buffer, "%s.ecr",mName.c_str());return (const char*)buffer;}
	/*Texture Coordinates*/
	SubdivTextCoordID getTextureCoord(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
	/*
	Face corner UV Ids. Explicit UVs on subdiv surfaces are stored on a
	per-face per-vertex basis. This attribute is used to specify
	the UV ids on a per-face per-vertex for each UV set that exists
	on the surface. The values on this attribute are to be used in
	conjunction with the UVSetPoints attribute defined in the parent
	controlPointShape class, since that attribute holds on to the uv values
	corresponding to these ids.
	*/
	const SubdivFaceUVIdsID& getFaceUVIds(size_t fuv_i){char buffer[4096];sprintf_s (buffer, "%s.fuv[%i]",mName.c_str(),fuv_i);return (const char*)buffer;}
	/*Specifies the scaling factor for the surface normal display.*/
	DoubleID getNormalsDisplayScale(){char buffer[4096];sprintf_s (buffer, "%s.ndf",mName.c_str());return (const char*)buffer;}
	/*Format: 0 - Uniform, 1 - Adaptive (Leaf Level)*/
	UnsignedintID getFormat(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*The depth at which constant-depth tessellates the surface*/
	IntID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The number of samples per face*/
	IntID getSampleCount(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	The level at which components (vertices, edges, faces...) will be
	displayed. Valid values are 0=Base through 13=Finest.
	*/
	UnsignedintID getDisplayLevel(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*
	Determines whether diplay includes components "edited" or
	"visited" at the current display level.  Valid values are
	0=Edited, 1=Visited, or 2=All.
	*/
	UnsignedintID getDisplayFilter(){char buffer[4096];sprintf_s (buffer, "%s.dfl",mName.c_str());return (const char*)buffer;}
	/*The number of base mesh faces*/
	IntID getBaseFaceCount(){char buffer[4096];sprintf_s (buffer, "%s.bfc",mName.c_str());return (const char*)buffer;}
	/*The number of faces at level 1*/
	IntID getLevelOneFaceCount(){char buffer[4096];sprintf_s (buffer, "%s.ofc",mName.c_str());return (const char*)buffer;}
	/*
	Controls how scaling of coarser vertices affects finer ones.
	When set to "Propagate", scaling applied to coarser vertices
	is propagated to those at finer levels of the hierarchy.  This
	has the effect of making hierarchically-added geometric features
	scale with the surface as coarser vertices are manipulated.
	When this attribute is set to "Ignore", scaling applied to
	coarser vertices is ignored at finer levels of the hierarchy.
	This has the effect of making hierarchically-added geometric
	features maintain their size as the rest of the surface is manipulated.
	Note that this attribute has no effect on scaling applied to
	the entire object via transforms anywhere above it in the DAG,
	only to vertices of the surface via component manipulation
	or (indirectly) via deformations applied to vertices.
	*/
	UnsignedintID getScalingHierarchy(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideCaustics(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oca",mName.c_str());return (const char*)buffer;}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	ShortID getMiCausticAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.caa",mName.c_str());return (const char*)buffer;}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	FloatID getMiCausticRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.car",mName.c_str());return (const char*)buffer;}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideGlobalIllumination(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ogi",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	ShortID getMiGlobillumAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gia",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	FloatID getMiGlobillumRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gir",mName.c_str());return (const char*)buffer;}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideFinalGather(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ofg",mName.c_str());return (const char*)buffer;}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	IntID getMiFinalGatherRays(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fry",mName.c_str());return (const char*)buffer;}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMinRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmn",mName.c_str());return (const char*)buffer;}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMaxRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmx",mName.c_str());return (const char*)buffer;}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	ShortID getMiFinalGatherFilter(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ffi",mName.c_str());return (const char*)buffer;}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	BoolID getMiFinalGatherView(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgv",mName.c_str());return (const char*)buffer;}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	BoolID getMiOverrideSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oos",mName.c_str());return (const char*)buffer;}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	ShortID getMiMinSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mins",mName.c_str());return (const char*)buffer;}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	ShortID getMiMaxSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.maxs",mName.c_str());return (const char*)buffer;}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	BoolID getMiFinalGatherCast(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgc",mName.c_str());return (const char*)buffer;}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	BoolID getMiFinalGatherReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fge",mName.c_str());return (const char*)buffer;}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	BoolID getMiTransparencyCast(){char buffer[4096];sprintf_s (buffer, "%s.mrc.tpc",mName.c_str());return (const char*)buffer;}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	BoolID getMiTransparencyReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.tpr",mName.c_str());return (const char*)buffer;}
	/*
	The object receives reflection rays if <b>miReflectionReceive</b> is on.
	This flag controls reflection of other objects on this object.
	If disabled, this object will not show any reflection,
	as if the surface is not reflective.
	The casting behaviour is ruled by visibleInReflections flag,
	which controls reflection of this object on other objects.
	Disabling <b>visibleInReflections</b> will make this object
	disappera from reflection.
	*/
	BoolID getMiReflectionReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.rflr",mName.c_str());return (const char*)buffer;}
	/*
	The object receives refraction rays if <b>miRefractionReceive</b> is on.
	This flag contols refraction of other objects through this object.
	Disabling this value will make this object non-refractive.
	The casting behaviour is ruled by visibleInRefractions flag,
	which controls refraction of this object showing through other objects.
	Disabling <b>visibleInRefractions</b> will make this object disappear
	from refraction.
	*/
	BoolID getMiRefractionReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.rfrr",mName.c_str());return (const char*)buffer;}
protected:
	Subdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIV_H__
