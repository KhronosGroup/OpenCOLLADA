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
/*
<p><pre> Manage the grouping : components group.

 Manage the tweak, used for moving points (translate, rotate, scale),
 the tweak attributes can be animated.

 Manage all display options (normal, center, border, edge style, ...).

 Manage partial attributes used for ascii I/O : aPoints aVertex aEdges aUvpoints aFaces.

 Manage the tesselation's criterions for the polygonal's displacement :
 aUseMaxEdgeLength aUseMinEdgeLength aUseMaxSubd aUseMaxUv aUseMinScreen
 aUseNumTriangles aNumTriangles aMaxEdgeLength aMinEdgeLength aMaxSubd aMaxUvaMinScreen.
</pre></p>
*/
class Mesh : public SurfaceShape
{
public:
	/*Special Attribute to specify the color - For file I/O only.*/
	struct Colors{
		float colorR;
		float colorG;
		float colorB;
		float colorA;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", colorR);
			fprintf_s(file,"%f ", colorG);
			fprintf_s(file,"%f ", colorB);
			fprintf_s(file,"%f", colorA);
		}
	};
	/*
	Attribute to specify the color of a vertex, either on the entire
	vertex or on a per face basis.
	*/
	struct ColorPerVertex{
		/*
		A compound attribute that corresponds to the color of the vertex.
		The attribute is a multi with the index of the multi identifying the
		vertex that the color applies to.
		*/
		struct VertexColor{
			float3 vertexColorRGB;
			float vertexAlpha;
			/*
			A compound attribute that corresponds to the color of the vertex
			attached to a particular face. It is a multi attribute and the index
			of the multi identifies the face that the color applies to. The index
			of the parent attribute (aVertexColor) already identifies the vertex
			that color is being attached to.
			*/
			struct VertexFaceColor{
				float3 vertexFaceColorRGB;
				float vertexFaceAlpha;
				void write(FILE* file) const
				{
					vertexFaceColorRGB.write(file);
					fprintf_s(file, " ");
					fprintf_s(file,"%f", vertexFaceAlpha);
				}
			}* vertexFaceColor;
			void write(FILE* file) const
			{
				vertexColorRGB.write(file);
				fprintf_s(file, " ");
				fprintf_s(file,"%f ", vertexAlpha);
				size_t size = sizeof(vertexFaceColor)/sizeof(VertexFaceColor);
				for(size_t i=0; i<size; ++i)
				{
					vertexFaceColor[i].write(file);
					if(i+1<size) fprintf_s(file," ");
				}
			}
		}* vertexColor;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertexColor)/sizeof(VertexColor);
			for(size_t i=0; i<size; ++i)
			{
				vertexColor[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*
	Attribute to specify the normal of a vertex, either on the entire
	vertex or on a per face basis.
	*/
	struct NormalPerVertex{
		/*
		A compound attribute that corresponds to the normal of the vertex.
		It is a multi attribute with the index of the multi identifying the
		vertex that the normal value applies to.
		*/
		struct VertexNormal{
			float3 vertexNormalXYZ;
			/*
			A compound attribute that represents the normal of the vertex
			attached to a particular face. It is a multi attribute and the index
			of the multi identifies the face that the normal applies to. The index
			of the parent attribute (aVertexNormal) already identifies the vertex
			that normal value applies to.
			*/
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
				fprintf_s(file, " ");
				size_t size = sizeof(vertexFaceNormal)/sizeof(VertexFaceNormal);
				for(size_t i=0; i<size; ++i)
				{
					vertexFaceNormal[i].write(file);
					if(i+1<size) fprintf_s(file," ");
				}
			}
		}* vertexNormal;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertexNormal)/sizeof(VertexNormal);
			for(size_t i=0; i<size; ++i)
			{
				vertexNormal[i].write(file);
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
	Mesh(FILE* file,const std::string& name,const std::string& parent=""):SurfaceShape(file, name, parent, "mesh"){}
	virtual ~Mesh(){}
	/*The input (creation) mesh.*/
	void setInMesh(const MeshID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*The output (local space) mesh.*/
	void setOutMesh(const mesh& o){fprintf_s(mFile, "setAttr \".o\" -type \"mesh\" ");o.write(mFile);fprintf_s(mFile,";\n");}
	/*The output (local space) mesh.*/
	void setOutMesh(const MeshID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Tells if aOutMesh is only dirty due to tweak change.*/
	void setOutGeometryClean(const MessageID& ogc){fprintf_s(mFile,"connectAttr \"");ogc.write(mFile);fprintf_s(mFile,"\" \"%s.ogc\";\n",mName.c_str());}
	/*
	Internal cached input mesh used only for file I/O. This attribute
	is for internal use and should never be directly manipulated by the
	user. If it is modified the results will be unpredictable.
	*/
	void setCachedInMesh(const mesh& ci){fprintf_s(mFile, "setAttr \".ci\" -type \"mesh\" ");ci.write(mFile);fprintf_s(mFile,";\n");}
	/*The world space meshes.*/
	void setWorldMesh(size_t w_i,const MeshID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w[%i]\";\n",mName.c_str(),w_i);}
	/*
	The cached smoothed mesh, that holds all the meshes from
	different levels of subdivision
	*/
	void setCachedSmoothMesh(const MeshID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs\";\n",mName.c_str());}
	/*Check for reasonable face count before smoothing.*/
	void setSmoothWarn(bool sw){if(sw == true) return; fprintf_s(mFile, "setAttr \".sw\" %i;\n", sw);}
	/*Check for reasonable face count before smoothing.*/
	void setSmoothWarn(const BoolID& sw){fprintf_s(mFile,"connectAttr \"");sw.write(mFile);fprintf_s(mFile,"\" \"%s.sw\";\n",mName.c_str());}
	/*The level of smoothing to perform on the mesh.*/
	void setSmoothLevel(short lev){if(lev == 2) return; fprintf_s(mFile, "setAttr \".lev\" %i;\n", lev);}
	/*The level of smoothing to perform on the mesh.*/
	void setSmoothLevel(const ShortID& lev){fprintf_s(mFile,"connectAttr \"");lev.write(mFile);fprintf_s(mFile,"\" \"%s.lev\";\n",mName.c_str());}
	/*
	The smoothness parameter. Range is [0,1]. Default value of 1
	smooths the faces as much as possible. Value of 0 subdivides faces only.
	*/
	void setContinuity(float co){if(co == 1) return; fprintf_s(mFile, "setAttr \".co\" %f;\n", co);}
	/*
	The smoothness parameter. Range is [0,1]. Default value of 1
	smooths the faces as much as possible. Value of 0 subdivides faces only.
	*/
	void setContinuity(const FloatID& co){fprintf_s(mFile,"connectAttr \"");co.write(mFile);fprintf_s(mFile,"\" \"%s.co\";\n",mName.c_str());}
	/*If true: UVs as well as geometry will be smoothed*/
	void setSmoothUVs(bool suv){if(suv == true) return; fprintf_s(mFile, "setAttr \".suv\" %i;\n", suv);}
	/*If true: UVs as well as geometry will be smoothed*/
	void setSmoothUVs(const BoolID& suv){fprintf_s(mFile,"connectAttr \"");suv.write(mFile);fprintf_s(mFile,"\" \"%s.suv\";\n",mName.c_str());}
	/*If true: border edges will not be smoothed.*/
	void setKeepBorder(bool kb){if(kb == false) return; fprintf_s(mFile, "setAttr \".kb\" %i;\n", kb);}
	/*If true: border edges will not be smoothed.*/
	void setKeepBorder(const BoolID& kb){fprintf_s(mFile,"connectAttr \"");kb.write(mFile);fprintf_s(mFile,"\" \"%s.kb\";\n",mName.c_str());}
	/*If true: hard edges will not be smoothed.*/
	void setKeepHardEdge(bool khe){if(khe == false) return; fprintf_s(mFile, "setAttr \".khe\" %i;\n", khe);}
	/*If true: hard edges will not be smoothed.*/
	void setKeepHardEdge(const BoolID& khe){fprintf_s(mFile,"connectAttr \"");khe.write(mFile);fprintf_s(mFile,"\" \"%s.khe\";\n",mName.c_str());}
	/*
	If true: The smooth mesh preview edges which are a result of edges
	from the base cage will share the same hardness value.
	*/
	void setPropagateEdgeHardness(bool peh){if(peh == false) return; fprintf_s(mFile, "setAttr \".peh\" %i;\n", peh);}
	/*
	If true: The smooth mesh preview edges which are a result of edges
	from the base cage will share the same hardness value.
	*/
	void setPropagateEdgeHardness(const BoolID& peh){fprintf_s(mFile,"connectAttr \"");peh.write(mFile);fprintf_s(mFile,"\" \"%s.peh\";\n",mName.c_str());}
	/*
	Treatment of UV map borders
	0 - all map border edges will be smoothed
	1 - map borders that are also geometry borders will be smoothed
	2 - no map borders will be smoothed
	*/
	void setKeepMapBorders(unsigned int kmb){if(kmb == 1) return; fprintf_s(mFile, "setAttr \".kmb\" %i;\n", kmb);}
	/*
	Treatment of UV map borders
	0 - all map border edges will be smoothed
	1 - map borders that are also geometry borders will be smoothed
	2 - no map borders will be smoothed
	*/
	void setKeepMapBorders(const UnsignedintID& kmb){fprintf_s(mFile,"connectAttr \"");kmb.write(mFile);fprintf_s(mFile,"\" \"%s.kmb\";\n",mName.c_str());}
	/*
	The offset that will be added to the smoothed mesh.
	By default, no offset will be added.
	Leaving this to default will improve performance.
	*/
	void setSmoothOffset(const float3& so){fprintf_s(mFile, "setAttr \".so\" -type \"float3\" ");so.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The offset that will be added to the smoothed mesh.
	By default, no offset will be added.
	Leaving this to default will improve performance.
	*/
	void setSmoothOffset(const Float3ID& so){fprintf_s(mFile,"connectAttr \"");so.write(mFile);fprintf_s(mFile,"\" \"%s.so\";\n",mName.c_str());}
	/*Offset in x.*/
	void setSofx(float sx){if(sx == 0) return; fprintf_s(mFile, "setAttr \".so.sx\" %f;\n", sx);}
	/*Offset in x.*/
	void setSofx(const FloatID& sx){fprintf_s(mFile,"connectAttr \"");sx.write(mFile);fprintf_s(mFile,"\" \"%s.so.sx\";\n",mName.c_str());}
	/*Offset in y.*/
	void setSofy(float sy){if(sy == 0) return; fprintf_s(mFile, "setAttr \".so.sy\" %f;\n", sy);}
	/*Offset in y.*/
	void setSofy(const FloatID& sy){fprintf_s(mFile,"connectAttr \"");sy.write(mFile);fprintf_s(mFile,"\" \"%s.so.sy\";\n",mName.c_str());}
	/*Offset in z.*/
	void setSofz(float sz){if(sz == 0) return; fprintf_s(mFile, "setAttr \".so.sz\" %f;\n", sz);}
	/*Offset in z.*/
	void setSofz(const FloatID& sz){fprintf_s(mFile,"connectAttr \"");sz.write(mFile);fprintf_s(mFile,"\" \"%s.so.sz\";\n",mName.c_str());}
	/*Controls if the subdivided components should be displayed or not.*/
	void setDisplaySubdComps(bool dsc){if(dsc == false) return; fprintf_s(mFile, "setAttr \".dsc\" %i;\n", dsc);}
	/*Controls if the subdivided components should be displayed or not.*/
	void setDisplaySubdComps(const BoolID& dsc){fprintf_s(mFile,"connectAttr \"");dsc.write(mFile);fprintf_s(mFile,"\" \"%s.dsc\";\n",mName.c_str());}
	/*Specifies if the decision to continue tessellation should be based on the maximum triangle edge length value.*/
	void setUseMaxEdgeLength(bool uxe){if(uxe == false) return; fprintf_s(mFile, "setAttr \".uxe\" %i;\n", uxe);}
	/*Specifies if the decision to continue tessellation should be based on the maximum triangle edge length value.*/
	void setUseMaxEdgeLength(const BoolID& uxe){fprintf_s(mFile,"connectAttr \"");uxe.write(mFile);fprintf_s(mFile,"\" \"%s.uxe\";\n",mName.c_str());}
	/*Specifies if the decision to continue tessellation should be based on the minimum triangle edge length value.*/
	void setUseMinEdgeLength(bool uie){if(uie == false) return; fprintf_s(mFile, "setAttr \".uie\" %i;\n", uie);}
	/*Specifies if the decision to continue tessellation should be based on the minimum triangle edge length value.*/
	void setUseMinEdgeLength(const BoolID& uie){fprintf_s(mFile,"connectAttr \"");uie.write(mFile);fprintf_s(mFile,"\" \"%s.uie\";\n",mName.c_str());}
	/*Specifies if the decision to continue tessellation should be based on the maximum subdivision level value.*/
	void setUseMaxSubdivisions(bool uxs){if(uxs == false) return; fprintf_s(mFile, "setAttr \".uxs\" %i;\n", uxs);}
	/*Specifies if the decision to continue tessellation should be based on the maximum subdivision level value.*/
	void setUseMaxSubdivisions(const BoolID& uxs){fprintf_s(mFile,"connectAttr \"");uxs.write(mFile);fprintf_s(mFile,"\" \"%s.uxs\";\n",mName.c_str());}
	/*Specifies if the decision to continue tessellation should be based on the maximum UV quad size value.*/
	void setUseMaxUV(bool uxu){if(uxu == false) return; fprintf_s(mFile, "setAttr \".uxu\" %i;\n", uxu);}
	/*Specifies if the decision to continue tessellation should be based on the maximum UV quad size value.*/
	void setUseMaxUV(const BoolID& uxu){fprintf_s(mFile,"connectAttr \"");uxu.write(mFile);fprintf_s(mFile,"\" \"%s.uxu\";\n",mName.c_str());}
	/*Specifies if the decision to continue tessellation should be based on the minimum triangle screen size.*/
	void setUseMinScreen(bool uns){if(uns == true) return; fprintf_s(mFile, "setAttr \".uns\" %i;\n", uns);}
	/*Specifies if the decision to continue tessellation should be based on the minimum triangle screen size.*/
	void setUseMinScreen(const BoolID& uns){fprintf_s(mFile,"connectAttr \"");uns.write(mFile);fprintf_s(mFile,"\" \"%s.uns\";\n",mName.c_str());}
	/*Specifies if the decision to continue tessellation should be based on the number of triangles to produce.*/
	void setUseNumTriangles(bool unp){if(unp == false) return; fprintf_s(mFile, "setAttr \".unp\" %i;\n", unp);}
	/*Specifies if the decision to continue tessellation should be based on the number of triangles to produce.*/
	void setUseNumTriangles(const BoolID& unp){fprintf_s(mFile,"connectAttr \"");unp.write(mFile);fprintf_s(mFile,"\" \"%s.unp\";\n",mName.c_str());}
	/*Specifies the maximum number of triangles for the entire tessellation.*/
	void setNumTriangles(int nt){if(nt == 100) return; fprintf_s(mFile, "setAttr \".nt\" %i;\n", nt);}
	/*Specifies the maximum number of triangles for the entire tessellation.*/
	void setNumTriangles(const IntID& nt){fprintf_s(mFile,"connectAttr \"");nt.write(mFile);fprintf_s(mFile,"\" \"%s.nt\";\n",mName.c_str());}
	/*Specifies the maximum length of a triangle edge for the tessellation.*/
	void setMaxEdgeLength(float mxe){if(mxe == 0.1) return; fprintf_s(mFile, "setAttr \".mxe\" %f;\n", mxe);}
	/*Specifies the maximum length of a triangle edge for the tessellation.*/
	void setMaxEdgeLength(const FloatID& mxe){fprintf_s(mFile,"connectAttr \"");mxe.write(mFile);fprintf_s(mFile,"\" \"%s.mxe\";\n",mName.c_str());}
	/*Specifies the minimum length of a triangle edge for the tessellation.*/
	void setMinEdgeLength(float mne){if(mne == 0.01) return; fprintf_s(mFile, "setAttr \".mne\" %f;\n", mne);}
	/*Specifies the minimum length of a triangle edge for the tessellation.*/
	void setMinEdgeLength(const FloatID& mne){fprintf_s(mFile,"connectAttr \"");mne.write(mFile);fprintf_s(mFile,"\" \"%s.mne\";\n",mName.c_str());}
	/*Specifies the maximum subdivision level for the tessellation.*/
	void setMaxSubd(int mxs){if(mxs == 5) return; fprintf_s(mFile, "setAttr \".mxs\" %i;\n", mxs);}
	/*Specifies the maximum subdivision level for the tessellation.*/
	void setMaxSubd(const IntID& mxs){fprintf_s(mFile,"connectAttr \"");mxs.write(mFile);fprintf_s(mFile,"\" \"%s.mxs\";\n",mName.c_str());}
	/*Specifies the maximum UV rectangle size in parametric space for the tessellation.*/
	void setMaxUv(float xuv){if(xuv == 0.5) return; fprintf_s(mFile, "setAttr \".xuv\" %f;\n", xuv);}
	/*Specifies the maximum UV rectangle size in parametric space for the tessellation.*/
	void setMaxUv(const FloatID& xuv){fprintf_s(mFile,"connectAttr \"");xuv.write(mFile);fprintf_s(mFile,"\" \"%s.xuv\";\n",mName.c_str());}
	/*Specifies the maximum screen size (in pixels) a triangle can be for tessellation.*/
	void setMinScreen(float mns){if(mns == 14) return; fprintf_s(mFile, "setAttr \".mns\" %f;\n", mns);}
	/*Specifies the maximum screen size (in pixels) a triangle can be for tessellation.*/
	void setMinScreen(const FloatID& mns){fprintf_s(mFile,"connectAttr \"");mns.write(mFile);fprintf_s(mFile,"\" \"%s.mns\";\n",mName.c_str());}
	/*Maximum numbers of triangles generated from an initial triangle.*/
	void setMaxTriangles(int tsl){if(tsl == 60000) return; fprintf_s(mFile, "setAttr \".tsl\" %i;\n", tsl);}
	/*Maximum numbers of triangles generated from an initial triangle.*/
	void setMaxTriangles(const IntID& tsl){fprintf_s(mFile,"connectAttr \"");tsl.write(mFile);fprintf_s(mFile,"\" \"%s.tsl\";\n",mName.c_str());}
	/*
	This attribute is the array of vertex tweaks (relative movements).
	The attribute values are always significant regardless of whether the
	object has history or not.
	*/
	void setPnts(size_t pt_i,const float3& pt){fprintf_s(mFile, "setAttr \".pt[%i]\" -type \"float3\" ",pt_i);pt.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute is the array of vertex tweaks (relative movements).
	The attribute values are always significant regardless of whether the
	object has history or not.
	*/
	void setPnts(size_t pt_start,size_t pt_end,float* pt){fprintf_s(mFile,"setAttr \".pt[%i:%i]\" ", pt_start,pt_end);size_t size = (pt_end-pt_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",pt[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*
	This attribute is the array of vertex tweaks (relative movements).
	The attribute values are always significant regardless of whether the
	object has history or not.
	*/
	void setPnts(size_t pt_i,const Float3ID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt[%i]\";\n",mName.c_str(),pt_i);}
	/*Vertex position tweak in x.*/
	void setPntx(size_t pt_i,float px){if(px == 0) return; fprintf_s(mFile, "setAttr \".pt[%i].px\" %f;\n", pt_i,px);}
	/*Vertex position tweak in x.*/
	void setPntx(size_t pt_i,const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.pt[%i].px\";\n",mName.c_str(),pt_i);}
	/*Vertex position tweak in y.*/
	void setPnty(size_t pt_i,float py){if(py == 0) return; fprintf_s(mFile, "setAttr \".pt[%i].py\" %f;\n", pt_i,py);}
	/*Vertex position tweak in y.*/
	void setPnty(size_t pt_i,const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.pt[%i].py\";\n",mName.c_str(),pt_i);}
	/*Vertex position tweak in z.*/
	void setPntz(size_t pt_i,float pz){if(pz == 0) return; fprintf_s(mFile, "setAttr \".pt[%i].pz\" %f;\n", pt_i,pz);}
	/*Vertex position tweak in z.*/
	void setPntz(size_t pt_i,const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.pt[%i].pz\";\n",mName.c_str(),pt_i);}
	/*
	This is an internal attribute representing local space vertex
	position, used for file I/O. It should never be directly manipulated
	by the user. If it is modified, the results will be unpredictable.
	*/
	void setVrts(size_t vt_i,const float3& vt){fprintf_s(mFile, "setAttr \".vt[%i]\" -type \"float3\" ",vt_i);vt.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is an internal attribute representing local space vertex
	position, used for file I/O. It should never be directly manipulated
	by the user. If it is modified, the results will be unpredictable.
	*/
	void setVrts(size_t vt_start,size_t vt_end,float* vt){fprintf_s(mFile,"setAttr \".vt[%i:%i]\" ", vt_start,vt_end);size_t size = (vt_end-vt_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",vt[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Vertex position in x.*/
	void setVrtx(size_t vt_i,float vx){if(vx == 0.0) return; fprintf_s(mFile, "setAttr \".vt[%i].vx\" %f;\n", vt_i,vx);}
	/*Vertex position in x.*/
	void setVrtx(size_t vt_i,const FloatID& vx){fprintf_s(mFile,"connectAttr \"");vx.write(mFile);fprintf_s(mFile,"\" \"%s.vt[%i].vx\";\n",mName.c_str(),vt_i);}
	/*Vertex position in y.*/
	void setVrty(size_t vt_i,float vy){if(vy == 0.0) return; fprintf_s(mFile, "setAttr \".vt[%i].vy\" %f;\n", vt_i,vy);}
	/*Vertex position in y.*/
	void setVrty(size_t vt_i,const FloatID& vy){fprintf_s(mFile,"connectAttr \"");vy.write(mFile);fprintf_s(mFile,"\" \"%s.vt[%i].vy\";\n",mName.c_str(),vt_i);}
	/*Vertex position in z.*/
	void setVrtz(size_t vt_i,float vz){if(vz == 0.0) return; fprintf_s(mFile, "setAttr \".vt[%i].vz\" %f;\n", vt_i,vz);}
	/*Vertex position in z.*/
	void setVrtz(size_t vt_i,const FloatID& vz){fprintf_s(mFile,"connectAttr \"");vz.write(mFile);fprintf_s(mFile,"\" \"%s.vt[%i].vz\";\n",mName.c_str(),vt_i);}
	/*Polygon Edges.*/
	void setEdge(size_t ed_i,const long3& ed){fprintf_s(mFile, "setAttr \".ed[%i]\" -type \"long3\" ",ed_i);ed.write(mFile);fprintf_s(mFile,";\n");}
	/*Polygon Edges.*/
	void setEdge(size_t ed_start,size_t ed_end,long* ed){fprintf_s(mFile,"setAttr \".ed[%i:%i]\" ", ed_start,ed_end);size_t size = (ed_end-ed_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%i",ed[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Polygon first point of edge.*/
	void setEdg1(size_t ed_i,int e1){if(e1 == 0) return; fprintf_s(mFile, "setAttr \".ed[%i].e1\" %i;\n", ed_i,e1);}
	/*Polygon first point of edge.*/
	void setEdg1(size_t ed_i,const IntID& e1){fprintf_s(mFile,"connectAttr \"");e1.write(mFile);fprintf_s(mFile,"\" \"%s.ed[%i].e1\";\n",mName.c_str(),ed_i);}
	/*Polygon second point of edge.*/
	void setEdg2(size_t ed_i,int e2){if(e2 == 0) return; fprintf_s(mFile, "setAttr \".ed[%i].e2\" %i;\n", ed_i,e2);}
	/*Polygon second point of edge.*/
	void setEdg2(size_t ed_i,const IntID& e2){fprintf_s(mFile,"connectAttr \"");e2.write(mFile);fprintf_s(mFile,"\" \"%s.ed[%i].e2\";\n",mName.c_str(),ed_i);}
	/*Polygon the hard or smooth information of edge.*/
	void setEdgh(size_t ed_i,int eh){if(eh == 0) return; fprintf_s(mFile, "setAttr \".ed[%i].eh\" %i;\n", ed_i,eh);}
	/*Polygon the hard or smooth information of edge.*/
	void setEdgh(size_t ed_i,const IntID& eh){fprintf_s(mFile,"connectAttr \"");eh.write(mFile);fprintf_s(mFile,"\" \"%s.ed[%i].eh\";\n",mName.c_str(),ed_i);}
	/*Polygon uvPoints.*/
	void setUvpt(size_t uv_i,const float2& uv){fprintf_s(mFile, "setAttr \".uv[%i]\" -type \"float2\" ",uv_i);uv.write(mFile);fprintf_s(mFile,";\n");}
	/*Polygon uvPoints.*/
	void setUvpt(size_t uv_start,size_t uv_end,float* uv){fprintf_s(mFile,"setAttr \".uv[%i:%i]\" ", uv_start,uv_end);size_t size = (uv_end-uv_start)*2+2;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",uv[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Polygon uvPointX.*/
	void setUvpx(size_t uv_i,float ux){if(ux == 0.0) return; fprintf_s(mFile, "setAttr \".uv[%i].ux\" %f;\n", uv_i,ux);}
	/*Polygon uvPointX.*/
	void setUvpx(size_t uv_i,const FloatID& ux){fprintf_s(mFile,"connectAttr \"");ux.write(mFile);fprintf_s(mFile,"\" \"%s.uv[%i].ux\";\n",mName.c_str(),uv_i);}
	/*Polygon uvPointY.*/
	void setUvpy(size_t uv_i,float uy){if(uy == 0.0) return; fprintf_s(mFile, "setAttr \".uv[%i].uy\" %f;\n", uv_i,uy);}
	/*Polygon uvPointY.*/
	void setUvpy(size_t uv_i,const FloatID& uy){fprintf_s(mFile,"connectAttr \"");uy.write(mFile);fprintf_s(mFile,"\" \"%s.uv[%i].uy\";\n",mName.c_str(),uv_i);}
	/*Special Attribute to specify the color - For file I/O only.*/
	void setColors(size_t clr_i,const Colors& clr){fprintf_s(mFile, "setAttr \".clr[%i]\" ",clr_i);clr.write(mFile);fprintf_s(mFile,";\n");}
	/*Special Attribute to specify color - Red channel - For file I/O only.*/
	void setColorR(size_t clr_i,float clrr){if(clrr == 0.0) return; fprintf_s(mFile, "setAttr \".clr[%i].clrr\" %f;\n", clr_i,clrr);}
	/*Special Attribute to specify color - Green channel - For file I/O only.*/
	void setColorG(size_t clr_i,float clrg){if(clrg == 0.0) return; fprintf_s(mFile, "setAttr \".clr[%i].clrg\" %f;\n", clr_i,clrg);}
	/*Special Attribute to specify color - Blue channel - For file I/O only.*/
	void setColorB(size_t clr_i,float clrb){if(clrb == 0.0) return; fprintf_s(mFile, "setAttr \".clr[%i].clrb\" %f;\n", clr_i,clrb);}
	/*Special Attribute to specify color - Alpha channel - For file I/O only.*/
	void setColorA(size_t clr_i,float clra){if(clra == 0.0) return; fprintf_s(mFile, "setAttr \".clr[%i].clra\" %f;\n", clr_i,clra);}
	/*
	Special Attribute for file i/o of user specified normals. Gets written
	if there are any user specified normals on the object. If the default
	value which is 1e+20 is written out, then it means that system defined
	normal values are used.
	*/
	void setNormals(size_t n_i,const float3& n){fprintf_s(mFile, "setAttr \".n[%i]\" -type \"float3\" ",n_i);n.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Special Attribute for file i/o of user specified normals. Gets written
	if there are any user specified normals on the object. If the default
	value which is 1e+20 is written out, then it means that system defined
	normal values are used.
	*/
	void setNormals(size_t n_start,size_t n_end,float* n){fprintf_s(mFile,"setAttr \".n[%i:%i]\" ", n_start,n_end);size_t size = (n_end-n_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",n[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Special Attribute for file i/o of user specified normals - value in x.*/
	void setNormalx(size_t n_i,float nx){if(nx == 1e20) return; fprintf_s(mFile, "setAttr \".n[%i].nx\" %f;\n", n_i,nx);}
	/*Special Attribute for file i/o of user specified normals - value in y.*/
	void setNormaly(size_t n_i,float ny){if(ny == 1e20) return; fprintf_s(mFile, "setAttr \".n[%i].ny\" %f;\n", n_i,ny);}
	/*Special Attribute for file i/o of user specified normals - value in z.*/
	void setNormalz(size_t n_i,float nz){if(nz == 1e20) return; fprintf_s(mFile, "setAttr \".n[%i].nz\" %f;\n", n_i,nz);}
	/*Polygon Faces.*/
	void setFace(size_t fc_i,const polyFaces& fc){fprintf_s(mFile, "setAttr \".fc[%i]\" -type \"polyFaces\" ",fc_i);fc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Attribute to specify the color of a vertex, either on the entire
	vertex or on a per face basis.
	*/
	void setColorPerVertex(const ColorPerVertex& cpvx){fprintf_s(mFile, "setAttr \".cpvx\" ");cpvx.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Attribute to specify the color of a vertex, either on the entire
	vertex or on a per face basis.
	*/
	void setColorPerVertex(const ColorPerVertexID& cpvx){fprintf_s(mFile,"connectAttr \"");cpvx.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx\";\n",mName.c_str());}
	/*
	A compound attribute that corresponds to the color of the vertex.
	The attribute is a multi with the index of the multi identifying the
	vertex that the color applies to.
	*/
	void setVertexColor(size_t vclr_i,const ColorPerVertex::VertexColor& vclr){fprintf_s(mFile, "setAttr \".cpvx.vclr[%i]\" ",vclr_i);vclr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A compound attribute that corresponds to the color of the vertex.
	The attribute is a multi with the index of the multi identifying the
	vertex that the color applies to.
	*/
	void setVertexColor(size_t vclr_i,const VertexColorID& vclr){fprintf_s(mFile,"connectAttr \"");vclr.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i]\";\n",mName.c_str(),vclr_i);}
	/*Vertex color. RGB channels.*/
	void setVertexColorRGB(size_t vclr_i,const float3& vrgb){fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vrgb\" -type \"float3\" ",vclr_i);vrgb.write(mFile);fprintf_s(mFile,";\n");}
	/*Vertex color. RGB channels.*/
	void setVertexColorRGB(size_t vclr_i,const Float3ID& vrgb){fprintf_s(mFile,"connectAttr \"");vrgb.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vrgb\";\n",mName.c_str(),vclr_i);}
	/*Vertex color - R channel.*/
	void setVertexColorR(size_t vclr_i,float vxcr){if(vxcr == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vrgb.vxcr\" %f;\n", vclr_i,vxcr);}
	/*Vertex color - R channel.*/
	void setVertexColorR(size_t vclr_i,const FloatID& vxcr){fprintf_s(mFile,"connectAttr \"");vxcr.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vrgb.vxcr\";\n",mName.c_str(),vclr_i);}
	/*Vertex color - G channel.*/
	void setVertexColorG(size_t vclr_i,float vxcg){if(vxcg == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vrgb.vxcg\" %f;\n", vclr_i,vxcg);}
	/*Vertex color - G channel.*/
	void setVertexColorG(size_t vclr_i,const FloatID& vxcg){fprintf_s(mFile,"connectAttr \"");vxcg.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vrgb.vxcg\";\n",mName.c_str(),vclr_i);}
	/*Vertex color - B channel.*/
	void setVertexColorB(size_t vclr_i,float vxcb){if(vxcb == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vrgb.vxcb\" %f;\n", vclr_i,vxcb);}
	/*Vertex color - B channel.*/
	void setVertexColorB(size_t vclr_i,const FloatID& vxcb){fprintf_s(mFile,"connectAttr \"");vxcb.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vrgb.vxcb\";\n",mName.c_str(),vclr_i);}
	/*Vertex color - Alpha channel.*/
	void setVertexAlpha(size_t vclr_i,float vxal){if(vxal == 1) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vxal\" %f;\n", vclr_i,vxal);}
	/*Vertex color - Alpha channel.*/
	void setVertexAlpha(size_t vclr_i,const FloatID& vxal){fprintf_s(mFile,"connectAttr \"");vxal.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vxal\";\n",mName.c_str(),vclr_i);}
	/*
	A compound attribute that corresponds to the color of the vertex
	attached to a particular face. It is a multi attribute and the index
	of the multi identifies the face that the color applies to. The index
	of the parent attribute (aVertexColor) already identifies the vertex
	that color is being attached to.
	*/
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_i,const ColorPerVertex::VertexColor::VertexFaceColor& vfcl){fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i]\" ",vclr_i,vfcl_i);vfcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A compound attribute that corresponds to the color of the vertex
	attached to a particular face. It is a multi attribute and the index
	of the multi identifies the face that the color applies to. The index
	of the parent attribute (aVertexColor) already identifies the vertex
	that color is being attached to.
	*/
	void setVertexFaceColor(size_t vclr_i,size_t vfcl_i,const VertexFaceColorID& vfcl){fprintf_s(mFile,"connectAttr \"");vfcl.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i]\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*RGB channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i,const float3& frgb){fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].frgb\" -type \"float3\" ",vclr_i,vfcl_i);frgb.write(mFile);fprintf_s(mFile,";\n");}
	/*RGB channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i,const Float3ID& frgb){fprintf_s(mFile,"connectAttr \"");frgb.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].frgb\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*R channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorR(size_t vclr_i,size_t vfcl_i,float vfcr){if(vfcr == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcr\" %f;\n", vclr_i,vfcl_i,vfcr);}
	/*R channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorR(size_t vclr_i,size_t vfcl_i,const FloatID& vfcr){fprintf_s(mFile,"connectAttr \"");vfcr.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcr\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*G channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorG(size_t vclr_i,size_t vfcl_i,float vfcg){if(vfcg == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcg\" %f;\n", vclr_i,vfcl_i,vfcg);}
	/*G channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorG(size_t vclr_i,size_t vfcl_i,const FloatID& vfcg){fprintf_s(mFile,"connectAttr \"");vfcg.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcg\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*B channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorB(size_t vclr_i,size_t vfcl_i,float vfcb){if(vfcb == 0) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].frgb.vfcb\" %f;\n", vclr_i,vfcl_i,vfcb);}
	/*B channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceColorB(size_t vclr_i,size_t vfcl_i,const FloatID& vfcb){fprintf_s(mFile,"connectAttr \"");vfcb.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcb\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*Alpha channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceAlpha(size_t vclr_i,size_t vfcl_i,float vfal){if(vfal == 1) return; fprintf_s(mFile, "setAttr \".cpvx.vclr[%i].vfcl[%i].vfal\" %f;\n", vclr_i,vfcl_i,vfal);}
	/*Alpha channel of Color of a vertex attached to a particular face.*/
	void setVertexFaceAlpha(size_t vclr_i,size_t vfcl_i,const FloatID& vfal){fprintf_s(mFile,"connectAttr \"");vfal.write(mFile);fprintf_s(mFile,"\" \"%s.cpvx.vclr[%i].vfcl[%i].vfal\";\n",mName.c_str(),vclr_i,vfcl_i);}
	/*
	Attribute to specify the normal of a vertex, either on the entire
	vertex or on a per face basis.
	*/
	void setNormalPerVertex(const NormalPerVertex& npvx){fprintf_s(mFile, "setAttr \".npvx\" ");npvx.write(mFile);fprintf_s(mFile,";\n");}
	/*
	A compound attribute that corresponds to the normal of the vertex.
	It is a multi attribute with the index of the multi identifying the
	vertex that the normal value applies to.
	*/
	void setVertexNormal(size_t vn_i,const NormalPerVertex::VertexNormal& vn){fprintf_s(mFile, "setAttr \".npvx.vn[%i]\" ",vn_i);vn.write(mFile);fprintf_s(mFile,";\n");}
	/*Vertex normal - XYZ values.*/
	void setVertexNormalXYZ(size_t vn_i,const float3& nxyz){fprintf_s(mFile, "setAttr \".npvx.vn[%i].nxyz\" -type \"float3\" ",vn_i);nxyz.write(mFile);fprintf_s(mFile,";\n");}
	/*Vertex normal x value*/
	void setVertexNormalX(size_t vn_i,float vxnx){if(vxnx == 1e20) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].nxyz.vxnx\" %f;\n", vn_i,vxnx);}
	/*Vertex normal y value*/
	void setVertexNormalY(size_t vn_i,float vxny){if(vxny == 1e20) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].nxyz.vxny\" %f;\n", vn_i,vxny);}
	/*Vertex normal z value*/
	void setVertexNormalZ(size_t vn_i,float vxnz){if(vxnz == 1e20) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].nxyz.vxnz\" %f;\n", vn_i,vxnz);}
	/*
	A compound attribute that represents the normal of the vertex
	attached to a particular face. It is a multi attribute and the index
	of the multi identifies the face that the normal applies to. The index
	of the parent attribute (aVertexNormal) already identifies the vertex
	that normal value applies to.
	*/
	void setVertexFaceNormal(size_t vn_i,size_t vfnl_i,const NormalPerVertex::VertexNormal::VertexFaceNormal& vfnl){fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i]\" ",vn_i,vfnl_i);vfnl.write(mFile);fprintf_s(mFile,";\n");}
	/*VertexFace normal - XYZ.*/
	void setVertexFaceNormalXYZ(size_t vn_i,size_t vfnl_i,const float3& fnxy){fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i].fnxy\" -type \"float3\" ",vn_i,vfnl_i);fnxy.write(mFile);fprintf_s(mFile,";\n");}
	/*Vertex face normal x value*/
	void setVertexFaceNormalX(size_t vn_i,size_t vfnl_i,float vfnx){if(vfnx == 1e20) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnx\" %f;\n", vn_i,vfnl_i,vfnx);}
	/*Vertex face normal y value*/
	void setVertexFaceNormalY(size_t vn_i,size_t vfnl_i,float vfny){if(vfny == 1e20) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfny\" %f;\n", vn_i,vfnl_i,vfny);}
	/*Vertex face normal z value*/
	void setVertexFaceNormalZ(size_t vn_i,size_t vfnl_i,float vfnz){if(vfnz == 1e20) return; fprintf_s(mFile, "setAttr \".npvx.vn[%i].vfnl[%i].fnxy.vfnz\" %f;\n", vn_i,vfnl_i,vfnz);}
	/*Controls explicit vertices display.*/
	void setDisplayVertices(bool dv){if(dv == false) return; fprintf_s(mFile, "setAttr \".dv\" %i;\n", dv);}
	/*Controls explicit vertices display.*/
	void setDisplayVertices(const BoolID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*Controls explicit edge border display.*/
	void setDisplayBorders(bool db){if(db == false) return; fprintf_s(mFile, "setAttr \".db\" %i;\n", db);}
	/*Controls explicit edge border display.*/
	void setDisplayBorders(const BoolID& db){fprintf_s(mFile,"connectAttr \"");db.write(mFile);fprintf_s(mFile,"\" \"%s.db\";\n",mName.c_str());}
	/*Controls explicit edge style display.*/
	void setDisplayEdges(const UnsignedintID& de){fprintf_s(mFile,"connectAttr \"");de.write(mFile);fprintf_s(mFile,"\" \"%s.de\";\n",mName.c_str());}
	/*
	Overrides which faces are drawn on the UV Texture
	Editor.  Has no effect on the 3d modeling view
	*/
	void setDisplayFacesWithGroupId(int dfgi){if(dfgi == -2) return; fprintf_s(mFile, "setAttr \".dfgi\" %i;\n", dfgi);}
	/*
	Overrides which faces are drawn on the UV Texture
	Editor.  Has no effect on the 3d modeling view
	*/
	void setDisplayFacesWithGroupId(const IntID& dfgi){fprintf_s(mFile,"connectAttr \"");dfgi.write(mFile);fprintf_s(mFile,"\" \"%s.dfgi\";\n",mName.c_str());}
	/*Controls explicit face center display.*/
	void setDisplayCenter(bool dc){if(dc == false) return; fprintf_s(mFile, "setAttr \".dc\" %i;\n", dc);}
	/*Controls explicit face center display.*/
	void setDisplayCenter(const BoolID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Controls explicit face triangles display.*/
	void setDisplayTriangles(bool dt){if(dt == false) return; fprintf_s(mFile, "setAttr \".dt\" %i;\n", dt);}
	/*Controls explicit face triangles display.*/
	void setDisplayTriangles(const BoolID& dt){fprintf_s(mFile,"connectAttr \"");dt.write(mFile);fprintf_s(mFile,"\" \"%s.dt\";\n",mName.c_str());}
	/*Controls explicit uvs display.*/
	void setDisplayUVs(bool duv){if(duv == false) return; fprintf_s(mFile, "setAttr \".duv\" %i;\n", duv);}
	/*Controls explicit uvs display.*/
	void setDisplayUVs(const BoolID& duv){fprintf_s(mFile,"connectAttr \"");duv.write(mFile);fprintf_s(mFile,"\" \"%s.duv\";\n",mName.c_str());}
	/*Controls explicit item numbers display.*/
	void setDisplayItemNumbers(int din){if(din == 0) return; fprintf_s(mFile, "setAttr \".din\" %i;\n", din);}
	/*Controls explicit item numbers display.*/
	void setDisplayItemNumbers(const IntID& din){fprintf_s(mFile,"connectAttr \"");din.write(mFile);fprintf_s(mFile,"\" \"%s.din\";\n",mName.c_str());}
	/*Controls explicit warped (non-planar) faces display*/
	void setDisplayNonPlanar(bool dnp){if(dnp == false) return; fprintf_s(mFile, "setAttr \".dnp\" %i;\n", dnp);}
	/*Controls explicit warped (non-planar) faces display*/
	void setDisplayNonPlanar(const BoolID& dnp){fprintf_s(mFile,"connectAttr \"");dnp.write(mFile);fprintf_s(mFile,"\" \"%s.dnp\";\n",mName.c_str());}
	/*Controls explicit backculling.*/
	void setBackfaceCulling(unsigned int bck){if(bck == 0) return; fprintf_s(mFile, "setAttr \".bck\" %i;\n", bck);}
	/*Controls explicit backculling.*/
	void setBackfaceCulling(const UnsignedintID& bck){fprintf_s(mFile,"connectAttr \"");bck.write(mFile);fprintf_s(mFile,"\" \"%s.bck\";\n",mName.c_str());}
	/*Controls explicit vertices backculling.*/
	void setVertexBackfaceCulling(bool vbc){if(vbc == true) return; fprintf_s(mFile, "setAttr \".vbc\" %i;\n", vbc);}
	/*Controls explicit vertices backculling.*/
	void setVertexBackfaceCulling(const BoolID& vbc){fprintf_s(mFile,"connectAttr \"");vbc.write(mFile);fprintf_s(mFile,"\" \"%s.vbc\";\n",mName.c_str());}
	/*Controls explicit vertex display size.*/
	void setVertexSize(double vs){if(vs == 3.0) return; fprintf_s(mFile, "setAttr \".vs\" %f;\n", vs);}
	/*Controls explicit vertex display size.*/
	void setVertexSize(const DoubleID& vs){fprintf_s(mFile,"connectAttr \"");vs.write(mFile);fprintf_s(mFile,"\" \"%s.vs\";\n",mName.c_str());}
	/*Controls explicit UV display size.*/
	void setUvSize(double usz){if(usz == 4.0) return; fprintf_s(mFile, "setAttr \".usz\" %f;\n", usz);}
	/*Controls explicit UV display size.*/
	void setUvSize(const DoubleID& usz){fprintf_s(mFile,"connectAttr \"");usz.write(mFile);fprintf_s(mFile,"\" \"%s.usz\";\n",mName.c_str());}
	/*Controls explicit border width .*/
	void setBorderWidth(double bw){if(bw == 2.0) return; fprintf_s(mFile, "setAttr \".bw\" %f;\n", bw);}
	/*Controls explicit border width .*/
	void setBorderWidth(const DoubleID& bw){fprintf_s(mFile,"connectAttr \"");bw.write(mFile);fprintf_s(mFile,"\" \"%s.bw\";\n",mName.c_str());}
	/*Controls explicit normal size.*/
	void setNormalSize(double ns){if(ns == 0.4) return; fprintf_s(mFile, "setAttr \".ns\" %f;\n", ns);}
	/*Controls explicit normal size.*/
	void setNormalSize(const DoubleID& ns){fprintf_s(mFile,"connectAttr \"");ns.write(mFile);fprintf_s(mFile,"\" \"%s.ns\";\n",mName.c_str());}
	/*Controls explicit normal type.*/
	void setNormalType(unsigned int ndt){if(ndt == 0) return; fprintf_s(mFile, "setAttr \".ndt\" %i;\n", ndt);}
	/*Controls explicit normal type.*/
	void setNormalType(const UnsignedintID& ndt){fprintf_s(mFile,"connectAttr \"");ndt.write(mFile);fprintf_s(mFile,"\" \"%s.ndt\";\n",mName.c_str());}
	/*Controls explicit normal display.*/
	void setDisplayNormal(bool dn){if(dn == false) return; fprintf_s(mFile, "setAttr \".dn\" %i;\n", dn);}
	/*Controls explicit normal display.*/
	void setDisplayNormal(const BoolID& dn){fprintf_s(mFile,"connectAttr \"");dn.write(mFile);fprintf_s(mFile,"\" \"%s.dn\";\n",mName.c_str());}
	/*Controls explicit tangents display.*/
	void setDisplayTangent(bool dtn){if(dtn == false) return; fprintf_s(mFile, "setAttr \".dtn\" %i;\n", dtn);}
	/*Controls explicit tangents display.*/
	void setDisplayTangent(const BoolID& dtn){fprintf_s(mFile,"connectAttr \"");dtn.write(mFile);fprintf_s(mFile,"\" \"%s.dtn\";\n",mName.c_str());}
	/*
	"Right Handed" tangent spaces are calculated so that the normal, the
	tangent, and the binormal always form a right handed coordinate system. In
	cases where the UV winding order has been reversed (either manually or as
	part of a mirroring workflow) this will cause the binormal components of
	normal and bump maps to be inverted (matching the behaviour of shaders which
	manually calculate the binormal from the tangent and normal). This is the
	default behaviour for pre-8.0 files.
	"Detect Winding Right Handed" tangent spaces calculate binormal values
	in a right handed coordinate system taking into account the UV winding
	order of the face. This ensures the binormal aligns with the V direction
	of the texture, and so enables the correct display of normal and bump
	maps on faces with reverse wound or mirrored UV mappings. This is the
	default value newly created meshes.
	"Left Handed" tangent spaces are calculated so that the normal, the
	tangent, and the binormal always form a left handed coordinate system. In
	cases where the UV winding order has been reversed (either manually or as
	part of a mirroring workflow) this will cause the binormal components of
	normal and bump maps to be inverted (matching the behaviour of shaders which
	manually calculate the binormal from the tangent and normal).
	"Detect Winding Left Handed" tangent spaces calculate binormal values
	in a left handed coordinate system taking into account the UV winding
	order of the face. This ensures the binormal aligns with the -V direction
	of the texture, and so enables the correct display of left handed normal
	maps on faces with reverse wound or mirrored UV mappings.
	*/
	void setTangentSpace(unsigned int tgsp){if(tgsp == 0) return; fprintf_s(mFile, "setAttr \".tgsp\" %i;\n", tgsp);}
	/*
	"Right Handed" tangent spaces are calculated so that the normal, the
	tangent, and the binormal always form a right handed coordinate system. In
	cases where the UV winding order has been reversed (either manually or as
	part of a mirroring workflow) this will cause the binormal components of
	normal and bump maps to be inverted (matching the behaviour of shaders which
	manually calculate the binormal from the tangent and normal). This is the
	default behaviour for pre-8.0 files.
	"Detect Winding Right Handed" tangent spaces calculate binormal values
	in a right handed coordinate system taking into account the UV winding
	order of the face. This ensures the binormal aligns with the V direction
	of the texture, and so enables the correct display of normal and bump
	maps on faces with reverse wound or mirrored UV mappings. This is the
	default value newly created meshes.
	"Left Handed" tangent spaces are calculated so that the normal, the
	tangent, and the binormal always form a left handed coordinate system. In
	cases where the UV winding order has been reversed (either manually or as
	part of a mirroring workflow) this will cause the binormal components of
	normal and bump maps to be inverted (matching the behaviour of shaders which
	manually calculate the binormal from the tangent and normal).
	"Detect Winding Left Handed" tangent spaces calculate binormal values
	in a left handed coordinate system taking into account the UV winding
	order of the face. This ensures the binormal aligns with the -V direction
	of the texture, and so enables the correct display of left handed normal
	maps on faces with reverse wound or mirrored UV mappings.
	*/
	void setTangentSpace(const UnsignedintID& tgsp){fprintf_s(mFile,"connectAttr \"");tgsp.write(mFile);fprintf_s(mFile,"\" \"%s.tgsp\";\n",mName.c_str());}
	/*
	Angle below which tangents will be smoothed. A value of 0 ensures that
	all UV seams (both UV borders and mirrored edges) create tangents space
	seams. Increase this value to remove undesired tangent space seams
	caused by UV borders or UV mirroring.
	*/
	void setTangentSmoothingAngle(double tsa){if(tsa == 0) return; fprintf_s(mFile, "setAttr \".tsa\" %f;\n", tsa);}
	/*
	Angle below which tangents will be smoothed. A value of 0 ensures that
	all UV seams (both UV borders and mirrored edges) create tangents space
	seams. Increase this value to remove undesired tangent space seams
	caused by UV borders or UV mirroring.
	*/
	void setTangentSmoothingAngle(const DoubleID& tsa){fprintf_s(mFile,"connectAttr \"");tsa.write(mFile);fprintf_s(mFile,"\" \"%s.tsa\";\n",mName.c_str());}
	/*
	Angle below which normals are considered equal when calculating tangent
	space. A value of 0 ensures that all hard edges create tangents space
	seams. Increase this value to remove undesired tangent space seams caused
	by hard edges.
	*/
	void setTangentNormalThreshold(double tnt){if(tnt == 0) return; fprintf_s(mFile, "setAttr \".tnt\" %f;\n", tnt);}
	/*
	Angle below which normals are considered equal when calculating tangent
	space. A value of 0 ensures that all hard edges create tangents space
	seams. Increase this value to remove undesired tangent space seams caused
	by hard edges.
	*/
	void setTangentNormalThreshold(const DoubleID& tnt){fprintf_s(mFile,"connectAttr \"");tnt.write(mFile);fprintf_s(mFile,"\" \"%s.tnt\";\n",mName.c_str());}
	/*Allow commands to modify the surface topology*/
	void setAllowTopologyMod(bool atm){if(atm == true) return; fprintf_s(mFile, "setAttr \".atm\" %i;\n", atm);}
	/*Allow commands to modify the surface topology*/
	void setAllowTopologyMod(const BoolID& atm){fprintf_s(mFile,"connectAttr \"");atm.write(mFile);fprintf_s(mFile,"\" \"%s.atm\";\n",mName.c_str());}
	/*
	Determines how to blend any stored color per vertex
	values with the current material, when in color display
	mode when blending is enabled. The default is
	to overwrite the material color.
	*/
	void setMaterialBlend(unsigned int matb){if(matb == 0) return; fprintf_s(mFile, "setAttr \".matb\" %i;\n", matb);}
	/*
	Determines how to blend any stored color per vertex
	values with the current material, when in color display
	mode when blending is enabled. The default is
	to overwrite the material color.
	*/
	void setMaterialBlend(const UnsignedintID& matb){fprintf_s(mFile,"connectAttr \"");matb.write(mFile);fprintf_s(mFile,"\" \"%s.matb\";\n",mName.c_str());}
	/*
	The name of the user defined face triangulation function.
	By defualt, it is an empty string, which means Maya
	face triangulation will be used. Users can override the
	default triangulation by setting this attribute to the name
	of their own function registered with Maya through the API.
	*/
	void setUserTrg(const string& utrg){if(utrg == "NULL") return; fprintf_s(mFile, "setAttr \".utrg\" -type \"string\" ");utrg.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The name of the user defined face triangulation function.
	By defualt, it is an empty string, which means Maya
	face triangulation will be used. Users can override the
	default triangulation by setting this attribute to the name
	of their own function registered with Maya through the API.
	*/
	void setUserTrg(const StringID& utrg){fprintf_s(mFile,"connectAttr \"");utrg.write(mFile);fprintf_s(mFile,"\" \"%s.utrg\";\n",mName.c_str());}
	/*Controls resolution at which surface is displayed*/
	void setDispResolution(unsigned int dr){if(dr == 0) return; fprintf_s(mFile, "setAttr \".dr\" %i;\n", dr);}
	/*Controls resolution at which surface is displayed*/
	void setDispResolution(const UnsignedintID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*Display mode for the smooth mesh*/
	void setDisplaySmoothMesh(unsigned int dsm){if(dsm == 0) return; fprintf_s(mFile, "setAttr \".dsm\" %i;\n", dsm);}
	/*
	When in the Smooth Mesh Preview display mode where you can
	see both the base cage as well as the smooth preview, this will
	set which components you want to select from.
	*/
	void setSmoothMeshSelectionMode(unsigned int ssm){if(ssm == 0) return; fprintf_s(mFile, "setAttr \".ssm\" %i;\n", ssm);}
	/*
	Should the triangles be reused.  If set to ON, the triangulation
	that existed before the tweaking, or deformation will be re-used.
	Setting this to true helps interactive tweaking and deforming of
	objects.  This setting helps objects with N-sided faces. This setting
	is meant for display modes that require triangles, as in the case
	of shaded mode display, or when the displayTriangles attribute is
	turned on.
	Note that the displayed triangles may not be accurate, since the
	pre-deformed, pre-tweaked triangles are re-used.
	*/
	void setReuseTriangles(bool rtri){if(rtri == false) return; fprintf_s(mFile, "setAttr \".rtri\" %i;\n", rtri);}
	/*
	Should the triangles be reused.  If set to ON, the triangulation
	that existed before the tweaking, or deformation will be re-used.
	Setting this to true helps interactive tweaking and deforming of
	objects.  This setting helps objects with N-sided faces. This setting
	is meant for display modes that require triangles, as in the case
	of shaded mode display, or when the displayTriangles attribute is
	turned on.
	Note that the displayed triangles may not be accurate, since the
	pre-deformed, pre-tweaked triangles are re-used.
	*/
	void setReuseTriangles(const BoolID& rtri){fprintf_s(mFile,"connectAttr \"");rtri.write(mFile);fprintf_s(mFile,"\" \"%s.rtri\";\n",mName.c_str());}
	/*
	This determines how quads (four sided faces) are split into
	two triangles. If "Left" is selected then the new edge will be
	between vertex 1 and 3, while "Right" splits between vertex 2 and 4.
	"Best Shape" attempts to pick the best split based on the shape of
	the quad. Note that this can cause flickering during animation of
	a deforming surface due to the split switching between the two modes.
	If one wishes to have best shape on a deforming surface then selecting
	reuse triangles will lock the triangulation so that the tessellation
	is constant across the animation.
	*/
	void setQuadSplit(unsigned int qsp){if(qsp == 2) return; fprintf_s(mFile, "setAttr \".qsp\" %i;\n", qsp);}
	/*
	This determines how quads (four sided faces) are split into
	two triangles. If "Left" is selected then the new edge will be
	between vertex 1 and 3, while "Right" splits between vertex 2 and 4.
	"Best Shape" attempts to pick the best split based on the shape of
	the quad. Note that this can cause flickering during animation of
	a deforming surface due to the split switching between the two modes.
	If one wishes to have best shape on a deforming surface then selecting
	reuse triangles will lock the triangulation so that the tessellation
	is constant across the animation.
	*/
	void setQuadSplit(const UnsignedintID& qsp){fprintf_s(mFile,"connectAttr \"");qsp.write(mFile);fprintf_s(mFile,"\" \"%s.qsp\";\n",mName.c_str());}
	/*
	When the mesh has per-instance data, this attribute can be
	used to determine the unique tag value for a given dagPath.
	The array index of this attribute corresponds to the dagPath
	instance number.
	*/
	void setPerInstanceIndex(size_t pii_i,int pii){if(pii == -1) return; fprintf_s(mFile, "setAttr \".pii[%i]\" %i;\n", pii_i,pii);}
	/*
	When the mesh has per-instance data, this attribute can be
	used to determine the unique tag value for a given dagPath.
	The array index of this attribute corresponds to the dagPath
	instance number.
	*/
	void setPerInstanceIndex(size_t pii_i,const IntID& pii){fprintf_s(mFile,"connectAttr \"");pii.write(mFile);fprintf_s(mFile,"\" \"%s.pii[%i]\";\n",mName.c_str(),pii_i);}
	/*
	When the mesh has per-instance data, this attribute is used in
	conjunction with the perInstanceIndex to maintain a unique
	per-instance tag for a given dagPath.
	*/
	void setPerInstanceTag(size_t pit_i,int pit){if(pit == -1) return; fprintf_s(mFile, "setAttr \".pit[%i]\" %i;\n", pit_i,pit);}
	/*
	When the mesh has per-instance data, this attribute is used in
	conjunction with the perInstanceIndex to maintain a unique
	per-instance tag for a given dagPath.
	*/
	void setPerInstanceTag(size_t pit_i,const IntID& pit){fprintf_s(mFile,"connectAttr \"");pit.write(mFile);fprintf_s(mFile,"\" \"%s.pit[%i]\";\n",mName.c_str(),pit_i);}
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
	/*Display alpha as grey scale If color set only contains alpha.*/
	void setDisplayAlphaAsGreyScale(bool dags){if(dags == false) return; fprintf_s(mFile, "setAttr \".dags\" %i;\n", dags);}
	/*Display alpha as grey scale If color set only contains alpha.*/
	void setDisplayAlphaAsGreyScale(const BoolID& dags){fprintf_s(mFile,"connectAttr \"");dags.write(mFile);fprintf_s(mFile,"\" \"%s.dags\";\n",mName.c_str());}
	/*The input (creation) mesh.*/
	MeshID getInMesh(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*The output (local space) mesh.*/
	MeshID getOutMesh(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*Tells if aOutMesh is only dirty due to tweak change.*/
	MessageID getOutGeometryClean(){char buffer[4096];sprintf_s (buffer, "%s.ogc",mName.c_str());return (const char*)buffer;}
	/*The world space meshes.*/
	const MeshID& getWorldMesh(size_t w_i){char buffer[4096];sprintf_s (buffer, "%s.w[%i]",mName.c_str(),w_i);return (const char*)buffer;}
	/*
	The cached smoothed mesh, that holds all the meshes from
	different levels of subdivision
	*/
	MeshID getCachedSmoothMesh(){char buffer[4096];sprintf_s (buffer, "%s.cs",mName.c_str());return (const char*)buffer;}
	/*Check for reasonable face count before smoothing.*/
	BoolID getSmoothWarn(){char buffer[4096];sprintf_s (buffer, "%s.sw",mName.c_str());return (const char*)buffer;}
	/*The level of smoothing to perform on the mesh.*/
	ShortID getSmoothLevel(){char buffer[4096];sprintf_s (buffer, "%s.lev",mName.c_str());return (const char*)buffer;}
	/*
	The smoothness parameter. Range is [0,1]. Default value of 1
	smooths the faces as much as possible. Value of 0 subdivides faces only.
	*/
	FloatID getContinuity(){char buffer[4096];sprintf_s (buffer, "%s.co",mName.c_str());return (const char*)buffer;}
	/*If true: UVs as well as geometry will be smoothed*/
	BoolID getSmoothUVs(){char buffer[4096];sprintf_s (buffer, "%s.suv",mName.c_str());return (const char*)buffer;}
	/*If true: border edges will not be smoothed.*/
	BoolID getKeepBorder(){char buffer[4096];sprintf_s (buffer, "%s.kb",mName.c_str());return (const char*)buffer;}
	/*If true: hard edges will not be smoothed.*/
	BoolID getKeepHardEdge(){char buffer[4096];sprintf_s (buffer, "%s.khe",mName.c_str());return (const char*)buffer;}
	/*
	If true: The smooth mesh preview edges which are a result of edges
	from the base cage will share the same hardness value.
	*/
	BoolID getPropagateEdgeHardness(){char buffer[4096];sprintf_s (buffer, "%s.peh",mName.c_str());return (const char*)buffer;}
	/*
	Treatment of UV map borders
	0 - all map border edges will be smoothed
	1 - map borders that are also geometry borders will be smoothed
	2 - no map borders will be smoothed
	*/
	UnsignedintID getKeepMapBorders(){char buffer[4096];sprintf_s (buffer, "%s.kmb",mName.c_str());return (const char*)buffer;}
	/*
	The offset that will be added to the smoothed mesh.
	By default, no offset will be added.
	Leaving this to default will improve performance.
	*/
	Float3ID getSmoothOffset(){char buffer[4096];sprintf_s (buffer, "%s.so",mName.c_str());return (const char*)buffer;}
	/*Offset in x.*/
	FloatID getSofx(){char buffer[4096];sprintf_s (buffer, "%s.so.sx",mName.c_str());return (const char*)buffer;}
	/*Offset in y.*/
	FloatID getSofy(){char buffer[4096];sprintf_s (buffer, "%s.so.sy",mName.c_str());return (const char*)buffer;}
	/*Offset in z.*/
	FloatID getSofz(){char buffer[4096];sprintf_s (buffer, "%s.so.sz",mName.c_str());return (const char*)buffer;}
	/*Controls if the subdivided components should be displayed or not.*/
	BoolID getDisplaySubdComps(){char buffer[4096];sprintf_s (buffer, "%s.dsc",mName.c_str());return (const char*)buffer;}
	/*Specifies if the decision to continue tessellation should be based on the maximum triangle edge length value.*/
	BoolID getUseMaxEdgeLength(){char buffer[4096];sprintf_s (buffer, "%s.uxe",mName.c_str());return (const char*)buffer;}
	/*Specifies if the decision to continue tessellation should be based on the minimum triangle edge length value.*/
	BoolID getUseMinEdgeLength(){char buffer[4096];sprintf_s (buffer, "%s.uie",mName.c_str());return (const char*)buffer;}
	/*Specifies if the decision to continue tessellation should be based on the maximum subdivision level value.*/
	BoolID getUseMaxSubdivisions(){char buffer[4096];sprintf_s (buffer, "%s.uxs",mName.c_str());return (const char*)buffer;}
	/*Specifies if the decision to continue tessellation should be based on the maximum UV quad size value.*/
	BoolID getUseMaxUV(){char buffer[4096];sprintf_s (buffer, "%s.uxu",mName.c_str());return (const char*)buffer;}
	/*Specifies if the decision to continue tessellation should be based on the minimum triangle screen size.*/
	BoolID getUseMinScreen(){char buffer[4096];sprintf_s (buffer, "%s.uns",mName.c_str());return (const char*)buffer;}
	/*Specifies if the decision to continue tessellation should be based on the number of triangles to produce.*/
	BoolID getUseNumTriangles(){char buffer[4096];sprintf_s (buffer, "%s.unp",mName.c_str());return (const char*)buffer;}
	/*Specifies the maximum number of triangles for the entire tessellation.*/
	IntID getNumTriangles(){char buffer[4096];sprintf_s (buffer, "%s.nt",mName.c_str());return (const char*)buffer;}
	/*Specifies the maximum length of a triangle edge for the tessellation.*/
	FloatID getMaxEdgeLength(){char buffer[4096];sprintf_s (buffer, "%s.mxe",mName.c_str());return (const char*)buffer;}
	/*Specifies the minimum length of a triangle edge for the tessellation.*/
	FloatID getMinEdgeLength(){char buffer[4096];sprintf_s (buffer, "%s.mne",mName.c_str());return (const char*)buffer;}
	/*Specifies the maximum subdivision level for the tessellation.*/
	IntID getMaxSubd(){char buffer[4096];sprintf_s (buffer, "%s.mxs",mName.c_str());return (const char*)buffer;}
	/*Specifies the maximum UV rectangle size in parametric space for the tessellation.*/
	FloatID getMaxUv(){char buffer[4096];sprintf_s (buffer, "%s.xuv",mName.c_str());return (const char*)buffer;}
	/*Specifies the maximum screen size (in pixels) a triangle can be for tessellation.*/
	FloatID getMinScreen(){char buffer[4096];sprintf_s (buffer, "%s.mns",mName.c_str());return (const char*)buffer;}
	/*Maximum numbers of triangles generated from an initial triangle.*/
	IntID getMaxTriangles(){char buffer[4096];sprintf_s (buffer, "%s.tsl",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is the array of vertex tweaks (relative movements).
	The attribute values are always significant regardless of whether the
	object has history or not.
	*/
	const Float3ID& getPnts(size_t pt_i){char buffer[4096];sprintf_s (buffer, "%s.pt[%i]",mName.c_str(),pt_i);return (const char*)buffer;}
	/*Vertex position tweak in x.*/
	const FloatID& getPntx(size_t pt_i){char buffer[4096];sprintf_s (buffer, "%s.pt[%i].px",mName.c_str(),pt_i);return (const char*)buffer;}
	/*Vertex position tweak in y.*/
	const FloatID& getPnty(size_t pt_i){char buffer[4096];sprintf_s (buffer, "%s.pt[%i].py",mName.c_str(),pt_i);return (const char*)buffer;}
	/*Vertex position tweak in z.*/
	const FloatID& getPntz(size_t pt_i){char buffer[4096];sprintf_s (buffer, "%s.pt[%i].pz",mName.c_str(),pt_i);return (const char*)buffer;}
	/*Vertex position in x.*/
	const FloatID& getVrtx(size_t vt_i){char buffer[4096];sprintf_s (buffer, "%s.vt[%i].vx",mName.c_str(),vt_i);return (const char*)buffer;}
	/*Vertex position in y.*/
	const FloatID& getVrty(size_t vt_i){char buffer[4096];sprintf_s (buffer, "%s.vt[%i].vy",mName.c_str(),vt_i);return (const char*)buffer;}
	/*Vertex position in z.*/
	const FloatID& getVrtz(size_t vt_i){char buffer[4096];sprintf_s (buffer, "%s.vt[%i].vz",mName.c_str(),vt_i);return (const char*)buffer;}
	/*Polygon first point of edge.*/
	const IntID& getEdg1(size_t ed_i){char buffer[4096];sprintf_s (buffer, "%s.ed[%i].e1",mName.c_str(),ed_i);return (const char*)buffer;}
	/*Polygon second point of edge.*/
	const IntID& getEdg2(size_t ed_i){char buffer[4096];sprintf_s (buffer, "%s.ed[%i].e2",mName.c_str(),ed_i);return (const char*)buffer;}
	/*Polygon the hard or smooth information of edge.*/
	const IntID& getEdgh(size_t ed_i){char buffer[4096];sprintf_s (buffer, "%s.ed[%i].eh",mName.c_str(),ed_i);return (const char*)buffer;}
	/*Polygon uvPointX.*/
	const FloatID& getUvpx(size_t uv_i){char buffer[4096];sprintf_s (buffer, "%s.uv[%i].ux",mName.c_str(),uv_i);return (const char*)buffer;}
	/*Polygon uvPointY.*/
	const FloatID& getUvpy(size_t uv_i){char buffer[4096];sprintf_s (buffer, "%s.uv[%i].uy",mName.c_str(),uv_i);return (const char*)buffer;}
	/*
	Attribute to specify the color of a vertex, either on the entire
	vertex or on a per face basis.
	*/
	ColorPerVertexID getColorPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.cpvx",mName.c_str());return (const char*)buffer;}
	/*
	A compound attribute that corresponds to the color of the vertex.
	The attribute is a multi with the index of the multi identifying the
	vertex that the color applies to.
	*/
	const VertexColorID& getVertexColor(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i]",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color. RGB channels.*/
	const Float3ID& getVertexColorRGB(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vrgb",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color - R channel.*/
	const FloatID& getVertexColorR(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vrgb.vxcr",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color - G channel.*/
	const FloatID& getVertexColorG(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vrgb.vxcg",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color - B channel.*/
	const FloatID& getVertexColorB(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vrgb.vxcb",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*Vertex color - Alpha channel.*/
	const FloatID& getVertexAlpha(size_t vclr_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vxal",mName.c_str(),vclr_i);return (const char*)buffer;}
	/*
	A compound attribute that corresponds to the color of the vertex
	attached to a particular face. It is a multi attribute and the index
	of the multi identifies the face that the color applies to. The index
	of the parent attribute (aVertexColor) already identifies the vertex
	that color is being attached to.
	*/
	const VertexFaceColorID& getVertexFaceColor(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i]",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*RGB channel of Color of a vertex attached to a particular face.*/
	const Float3ID& getVertexFaceColorRGB(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].frgb",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*R channel of Color of a vertex attached to a particular face.*/
	const FloatID& getVertexFaceColorR(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcr",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*G channel of Color of a vertex attached to a particular face.*/
	const FloatID& getVertexFaceColorG(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcg",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*B channel of Color of a vertex attached to a particular face.*/
	const FloatID& getVertexFaceColorB(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].frgb.vfcb",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*Alpha channel of Color of a vertex attached to a particular face.*/
	const FloatID& getVertexFaceAlpha(size_t vclr_i,size_t vfcl_i){char buffer[4096];sprintf_s (buffer, "%s.cpvx.vclr[%i].vfcl[%i].vfal",mName.c_str(),vclr_i,vfcl_i);return (const char*)buffer;}
	/*Controls explicit vertices display.*/
	BoolID getDisplayVertices(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*Controls explicit edge border display.*/
	BoolID getDisplayBorders(){char buffer[4096];sprintf_s (buffer, "%s.db",mName.c_str());return (const char*)buffer;}
	/*Controls explicit edge style display.*/
	UnsignedintID getDisplayEdges(){char buffer[4096];sprintf_s (buffer, "%s.de",mName.c_str());return (const char*)buffer;}
	/*
	Overrides which faces are drawn on the UV Texture
	Editor.  Has no effect on the 3d modeling view
	*/
	IntID getDisplayFacesWithGroupId(){char buffer[4096];sprintf_s (buffer, "%s.dfgi",mName.c_str());return (const char*)buffer;}
	/*Controls explicit face center display.*/
	BoolID getDisplayCenter(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*Controls explicit face triangles display.*/
	BoolID getDisplayTriangles(){char buffer[4096];sprintf_s (buffer, "%s.dt",mName.c_str());return (const char*)buffer;}
	/*Controls explicit uvs display.*/
	BoolID getDisplayUVs(){char buffer[4096];sprintf_s (buffer, "%s.duv",mName.c_str());return (const char*)buffer;}
	/*Controls explicit item numbers display.*/
	IntID getDisplayItemNumbers(){char buffer[4096];sprintf_s (buffer, "%s.din",mName.c_str());return (const char*)buffer;}
	/*Controls explicit warped (non-planar) faces display*/
	BoolID getDisplayNonPlanar(){char buffer[4096];sprintf_s (buffer, "%s.dnp",mName.c_str());return (const char*)buffer;}
	/*Controls explicit backculling.*/
	UnsignedintID getBackfaceCulling(){char buffer[4096];sprintf_s (buffer, "%s.bck",mName.c_str());return (const char*)buffer;}
	/*Controls explicit vertices backculling.*/
	BoolID getVertexBackfaceCulling(){char buffer[4096];sprintf_s (buffer, "%s.vbc",mName.c_str());return (const char*)buffer;}
	/*Controls explicit vertex display size.*/
	DoubleID getVertexSize(){char buffer[4096];sprintf_s (buffer, "%s.vs",mName.c_str());return (const char*)buffer;}
	/*Controls explicit UV display size.*/
	DoubleID getUvSize(){char buffer[4096];sprintf_s (buffer, "%s.usz",mName.c_str());return (const char*)buffer;}
	/*Controls explicit border width .*/
	DoubleID getBorderWidth(){char buffer[4096];sprintf_s (buffer, "%s.bw",mName.c_str());return (const char*)buffer;}
	/*Controls explicit normal size.*/
	DoubleID getNormalSize(){char buffer[4096];sprintf_s (buffer, "%s.ns",mName.c_str());return (const char*)buffer;}
	/*Controls explicit normal type.*/
	UnsignedintID getNormalType(){char buffer[4096];sprintf_s (buffer, "%s.ndt",mName.c_str());return (const char*)buffer;}
	/*Controls explicit normal display.*/
	BoolID getDisplayNormal(){char buffer[4096];sprintf_s (buffer, "%s.dn",mName.c_str());return (const char*)buffer;}
	/*Controls explicit tangents display.*/
	BoolID getDisplayTangent(){char buffer[4096];sprintf_s (buffer, "%s.dtn",mName.c_str());return (const char*)buffer;}
	/*
	"Right Handed" tangent spaces are calculated so that the normal, the
	tangent, and the binormal always form a right handed coordinate system. In
	cases where the UV winding order has been reversed (either manually or as
	part of a mirroring workflow) this will cause the binormal components of
	normal and bump maps to be inverted (matching the behaviour of shaders which
	manually calculate the binormal from the tangent and normal). This is the
	default behaviour for pre-8.0 files.
	"Detect Winding Right Handed" tangent spaces calculate binormal values
	in a right handed coordinate system taking into account the UV winding
	order of the face. This ensures the binormal aligns with the V direction
	of the texture, and so enables the correct display of normal and bump
	maps on faces with reverse wound or mirrored UV mappings. This is the
	default value newly created meshes.
	"Left Handed" tangent spaces are calculated so that the normal, the
	tangent, and the binormal always form a left handed coordinate system. In
	cases where the UV winding order has been reversed (either manually or as
	part of a mirroring workflow) this will cause the binormal components of
	normal and bump maps to be inverted (matching the behaviour of shaders which
	manually calculate the binormal from the tangent and normal).
	"Detect Winding Left Handed" tangent spaces calculate binormal values
	in a left handed coordinate system taking into account the UV winding
	order of the face. This ensures the binormal aligns with the -V direction
	of the texture, and so enables the correct display of left handed normal
	maps on faces with reverse wound or mirrored UV mappings.
	*/
	UnsignedintID getTangentSpace(){char buffer[4096];sprintf_s (buffer, "%s.tgsp",mName.c_str());return (const char*)buffer;}
	/*
	Angle below which tangents will be smoothed. A value of 0 ensures that
	all UV seams (both UV borders and mirrored edges) create tangents space
	seams. Increase this value to remove undesired tangent space seams
	caused by UV borders or UV mirroring.
	*/
	DoubleID getTangentSmoothingAngle(){char buffer[4096];sprintf_s (buffer, "%s.tsa",mName.c_str());return (const char*)buffer;}
	/*
	Angle below which normals are considered equal when calculating tangent
	space. A value of 0 ensures that all hard edges create tangents space
	seams. Increase this value to remove undesired tangent space seams caused
	by hard edges.
	*/
	DoubleID getTangentNormalThreshold(){char buffer[4096];sprintf_s (buffer, "%s.tnt",mName.c_str());return (const char*)buffer;}
	/*Allow commands to modify the surface topology*/
	BoolID getAllowTopologyMod(){char buffer[4096];sprintf_s (buffer, "%s.atm",mName.c_str());return (const char*)buffer;}
	/*
	Determines how to blend any stored color per vertex
	values with the current material, when in color display
	mode when blending is enabled. The default is
	to overwrite the material color.
	*/
	UnsignedintID getMaterialBlend(){char buffer[4096];sprintf_s (buffer, "%s.matb",mName.c_str());return (const char*)buffer;}
	/*
	The name of the user defined face triangulation function.
	By defualt, it is an empty string, which means Maya
	face triangulation will be used. Users can override the
	default triangulation by setting this attribute to the name
	of their own function registered with Maya through the API.
	*/
	StringID getUserTrg(){char buffer[4096];sprintf_s (buffer, "%s.utrg",mName.c_str());return (const char*)buffer;}
	/*Controls resolution at which surface is displayed*/
	UnsignedintID getDispResolution(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*
	Should the triangles be reused.  If set to ON, the triangulation
	that existed before the tweaking, or deformation will be re-used.
	Setting this to true helps interactive tweaking and deforming of
	objects.  This setting helps objects with N-sided faces. This setting
	is meant for display modes that require triangles, as in the case
	of shaded mode display, or when the displayTriangles attribute is
	turned on.
	Note that the displayed triangles may not be accurate, since the
	pre-deformed, pre-tweaked triangles are re-used.
	*/
	BoolID getReuseTriangles(){char buffer[4096];sprintf_s (buffer, "%s.rtri",mName.c_str());return (const char*)buffer;}
	/*
	This determines how quads (four sided faces) are split into
	two triangles. If "Left" is selected then the new edge will be
	between vertex 1 and 3, while "Right" splits between vertex 2 and 4.
	"Best Shape" attempts to pick the best split based on the shape of
	the quad. Note that this can cause flickering during animation of
	a deforming surface due to the split switching between the two modes.
	If one wishes to have best shape on a deforming surface then selecting
	reuse triangles will lock the triangulation so that the tessellation
	is constant across the animation.
	*/
	UnsignedintID getQuadSplit(){char buffer[4096];sprintf_s (buffer, "%s.qsp",mName.c_str());return (const char*)buffer;}
	/*
	When the mesh has per-instance data, this attribute can be
	used to determine the unique tag value for a given dagPath.
	The array index of this attribute corresponds to the dagPath
	instance number.
	*/
	const IntID& getPerInstanceIndex(size_t pii_i){char buffer[4096];sprintf_s (buffer, "%s.pii[%i]",mName.c_str(),pii_i);return (const char*)buffer;}
	/*
	When the mesh has per-instance data, this attribute is used in
	conjunction with the perInstanceIndex to maintain a unique
	per-instance tag for a given dagPath.
	*/
	const IntID& getPerInstanceTag(size_t pit_i){char buffer[4096];sprintf_s (buffer, "%s.pit[%i]",mName.c_str(),pit_i);return (const char*)buffer;}
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
	/*Display alpha as grey scale If color set only contains alpha.*/
	BoolID getDisplayAlphaAsGreyScale(){char buffer[4096];sprintf_s (buffer, "%s.dags",mName.c_str());return (const char*)buffer;}
protected:
	Mesh(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SurfaceShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MESH_H__
