/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVTOPOLY_H__
#define __MayaDM_SUBDIVTOPOLY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class SubdivToPoly : public DependNode
{
public:
public:
	SubdivToPoly(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdivToPoly"){}
	virtual ~SubdivToPoly(){}
	/*The resulting mesh*/
	void setOutMesh(const MeshID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Format: 0 - Constant Depth, 1 - Leaf Geometry, 2 - Polygon Count 3 - Vertices*/
	void setFormat(unsigned int f){if(f == 0) return; fprintf_s(mFile, "setAttr \".f\" %i;\n", f);}
	/*Format: 0 - Constant Depth, 1 - Leaf Geometry, 2 - Polygon Count 3 - Vertices*/
	void setFormat(const UnsignedintID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Polygon type: 0 - Triangles, 1 - Quads, 2 - Polygons*/
	void setPolygonType(unsigned int pt){if(pt == 2) return; fprintf_s(mFile, "setAttr \".pt\" %i;\n", pt);}
	/*Polygon type: 0 - Triangles, 1 - Quads, 2 - Polygons*/
	void setPolygonType(const UnsignedintID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*
	Determines how the position of a mesh point is calculated
	If on the position of the mesh point is returned. If off the
	position of the point of the surface is returned.
	*/
	void setExtractPointPosition(bool epp){if(epp == false) return; fprintf_s(mFile, "setAttr \".epp\" %i;\n", epp);}
	/*
	Determines how the position of a mesh point is calculated
	If on the position of the mesh point is returned. If off the
	position of the point of the surface is returned.
	*/
	void setExtractPointPosition(const BoolID& epp){fprintf_s(mFile,"connectAttr \"");epp.write(mFile);fprintf_s(mFile,"\" \"%s.epp\";\n",mName.c_str());}
	/*The number of samples per face*/
	void setSampleCount(int sc){if(sc == 1) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*The number of samples per face*/
	void setSampleCount(const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*The depth at which constant-depth tessellates the surface*/
	void setDepth(int d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*The depth at which constant-depth tessellates the surface*/
	void setDepth(const IntID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	The maximum number of polygons at which by polygons tessellates.
	If this attribute is greater than zero, it will override the
	sample count and depth attributes.
	*/
	void setMaxPolys(int mp){if(mp == 0) return; fprintf_s(mFile, "setAttr \".mp\" %i;\n", mp);}
	/*
	The maximum number of polygons at which by polygons tessellates.
	If this attribute is greater than zero, it will override the
	sample count and depth attributes.
	*/
	void setMaxPolys(const IntID& mp){fprintf_s(mFile,"connectAttr \"");mp.write(mFile);fprintf_s(mFile,"\" \"%s.mp\";\n",mName.c_str());}
	/*Keep subdiv surface normals*/
	void setSubdNormals(bool un){if(un == false) return; fprintf_s(mFile, "setAttr \".un\" %i;\n", un);}
	/*Keep subdiv surface normals*/
	void setSubdNormals(const BoolID& un){fprintf_s(mFile,"connectAttr \"");un.write(mFile);fprintf_s(mFile,"\" \"%s.un\";\n",mName.c_str());}
	/*
	Copy over uv topology (shared/unshared) from the original subdivision
	surface to the converted polygonal mesh.
	*/
	void setCopyUVTopology(bool cut){if(cut == false) return; fprintf_s(mFile, "setAttr \".cut\" %i;\n", cut);}
	/*
	Copy over uv topology (shared/unshared) from the original subdivision
	surface to the converted polygonal mesh.
	*/
	void setCopyUVTopology(const BoolID& cut){fprintf_s(mFile,"connectAttr \"");cut.write(mFile);fprintf_s(mFile,"\" \"%s.cut\";\n",mName.c_str());}
	/*
	Force sharing of uvs on all common vertices - the value of this
	attribute gets overridden by the value of the copyUVTopology attribute.
	*/
	void setShareUVs(bool suv){if(suv == false) return; fprintf_s(mFile, "setAttr \".suv\" %i;\n", suv);}
	/*
	Force sharing of uvs on all common vertices - the value of this
	attribute gets overridden by the value of the copyUVTopology attribute.
	*/
	void setShareUVs(const BoolID& suv){fprintf_s(mFile,"connectAttr \"");suv.write(mFile);fprintf_s(mFile,"\" \"%s.suv\";\n",mName.c_str());}
	/*
	The depth from which to extract the CVs of the polyMesh
	(Used only when the extractPointPosition is set to true)
	*** CAUTION *** :Setting to higher values will be both memory-time expensive
	*/
	void setLevel(int l){if(l == 0) return; fprintf_s(mFile, "setAttr \".l\" %i;\n", l);}
	/*
	The depth from which to extract the CVs of the polyMesh
	(Used only when the extractPointPosition is set to true)
	*** CAUTION *** :Setting to higher values will be both memory-time expensive
	*/
	void setLevel(const IntID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	Convert the componentIds back and forth
	A mapping that can be used to get the one-to-one association
	between the poly and the SubD component Ids
	*/
	void setConvertComp(bool cc){if(cc == false) return; fprintf_s(mFile, "setAttr \".cc\" %i;\n", cc);}
	/*
	Convert the componentIds back and forth
	A mapping that can be used to get the one-to-one association
	between the poly and the SubD component Ids
	*/
	void setConvertComp(const BoolID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc\";\n",mName.c_str());}
	/*Output CV Id*/
	void setOutSubdCVId(size_t os_i,const long2& os){fprintf_s(mFile, "setAttr \".os[%i]\" -type \"long2\" ",os_i);os.write(mFile);fprintf_s(mFile,";\n");}
	/*Output CV Id*/
	void setOutSubdCVId(size_t os_start,size_t os_end,long* os){fprintf_s(mFile,"setAttr \".os[%i:%i]\" ", os_start,os_end);size_t size = (os_end-os_start)*2+2;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%i",os[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Output CV Id*/
	void setOutSubdCVId(size_t os_i,const Long2ID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i]\";\n",mName.c_str(),os_i);}
	/*Higher 32 bit integer of the output CV Id*/
	void setOutSubdCVIdLeft(size_t os_i,int osl){if(osl == 0) return; fprintf_s(mFile, "setAttr \".os[%i].osl\" %i;\n", os_i,osl);}
	/*Higher 32 bit integer of the output CV Id*/
	void setOutSubdCVIdLeft(size_t os_i,const IntID& osl){fprintf_s(mFile,"connectAttr \"");osl.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i].osl\";\n",mName.c_str(),os_i);}
	/*Lower 32 bit integer of the output CV Id*/
	void setOutSubdCVIdRight(size_t os_i,int osr){if(osr == 0) return; fprintf_s(mFile, "setAttr \".os[%i].osr\" %i;\n", os_i,osr);}
	/*Lower 32 bit integer of the output CV Id*/
	void setOutSubdCVIdRight(size_t os_i,const IntID& osr){fprintf_s(mFile,"connectAttr \"");osr.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i].osr\";\n",mName.c_str(),os_i);}
	/*Input CV Id*/
	void setInSubdCVId(size_t is_i,const long2& is){fprintf_s(mFile, "setAttr \".is[%i]\" -type \"long2\" ",is_i);is.write(mFile);fprintf_s(mFile,";\n");}
	/*Input CV Id*/
	void setInSubdCVId(size_t is_start,size_t is_end,long* is){fprintf_s(mFile,"setAttr \".is[%i:%i]\" ", is_start,is_end);size_t size = (is_end-is_start)*2+2;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%i",is[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Input CV Id*/
	void setInSubdCVId(size_t is_i,const Long2ID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is[%i]\";\n",mName.c_str(),is_i);}
	/*Higher 32 bit integer of the input CV Id*/
	void setInSubdCVIdLeft(size_t is_i,int isl){if(isl == 0) return; fprintf_s(mFile, "setAttr \".is[%i].isl\" %i;\n", is_i,isl);}
	/*Higher 32 bit integer of the input CV Id*/
	void setInSubdCVIdLeft(size_t is_i,const IntID& isl){fprintf_s(mFile,"connectAttr \"");isl.write(mFile);fprintf_s(mFile,"\" \"%s.is[%i].isl\";\n",mName.c_str(),is_i);}
	/*Lower 32 bit integer of the input CV Id*/
	void setInSubdCVIdRight(size_t is_i,int isr){if(isr == 0) return; fprintf_s(mFile, "setAttr \".is[%i].isr\" %i;\n", is_i,isr);}
	/*Lower 32 bit integer of the input CV Id*/
	void setInSubdCVIdRight(size_t is_i,const IntID& isr){fprintf_s(mFile,"connectAttr \"");isr.write(mFile);fprintf_s(mFile,"\" \"%s.is[%i].isr\";\n",mName.c_str(),is_i);}
	/*Preserve vertex ordering in conversion*/
	void setPreserveVertexOrdering(bool pvo){if(pvo == true) return; fprintf_s(mFile, "setAttr \".pvo\" %i;\n", pvo);}
	/*Preserve vertex ordering in conversion*/
	void setPreserveVertexOrdering(const BoolID& pvo){fprintf_s(mFile,"connectAttr \"");pvo.write(mFile);fprintf_s(mFile,"\" \"%s.pvo\";\n",mName.c_str());}
	/*Out Vertices corresponding to the inSubDCVs.*/
	void setOutv(size_t ov_i,int ov){if(ov == 0) return; fprintf_s(mFile, "setAttr \".ov[%i]\" %i;\n", ov_i,ov);}
	/*Out Vertices corresponding to the inSubDCVs.*/
	void setOutv(size_t ov_i,const IntID& ov){fprintf_s(mFile,"connectAttr \"");ov.write(mFile);fprintf_s(mFile,"\" \"%s.ov[%i]\";\n",mName.c_str(),ov_i);}
	/*
	If true, the matrix on the input geometry is applied to the object
	and the resulting geometry will have identity matrix on it.  If false
	the conversion is done on the local space object and the resulting
	geometry has the input object's matrix on it.
	*/
	void setApplyMatrixToResult(bool amr){if(amr == true) return; fprintf_s(mFile, "setAttr \".amr\" %i;\n", amr);}
	/*
	If true, the matrix on the input geometry is applied to the object
	and the resulting geometry will have identity matrix on it.  If false
	the conversion is done on the local space object and the resulting
	geometry has the input object's matrix on it.
	*/
	void setApplyMatrixToResult(const BoolID& amr){fprintf_s(mFile,"connectAttr \"");amr.write(mFile);fprintf_s(mFile,"\" \"%s.amr\";\n",mName.c_str());}
	/*The resulting mesh*/
	MeshID getOutMesh(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*Format: 0 - Constant Depth, 1 - Leaf Geometry, 2 - Polygon Count 3 - Vertices*/
	UnsignedintID getFormat(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Polygon type: 0 - Triangles, 1 - Quads, 2 - Polygons*/
	UnsignedintID getPolygonType(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*
	Determines how the position of a mesh point is calculated
	If on the position of the mesh point is returned. If off the
	position of the point of the surface is returned.
	*/
	BoolID getExtractPointPosition(){char buffer[4096];sprintf_s (buffer, "%s.epp",mName.c_str());return (const char*)buffer;}
	/*The number of samples per face*/
	IntID getSampleCount(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*The depth at which constant-depth tessellates the surface*/
	IntID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	The maximum number of polygons at which by polygons tessellates.
	If this attribute is greater than zero, it will override the
	sample count and depth attributes.
	*/
	IntID getMaxPolys(){char buffer[4096];sprintf_s (buffer, "%s.mp",mName.c_str());return (const char*)buffer;}
	/*Keep subdiv surface normals*/
	BoolID getSubdNormals(){char buffer[4096];sprintf_s (buffer, "%s.un",mName.c_str());return (const char*)buffer;}
	/*
	Copy over uv topology (shared/unshared) from the original subdivision
	surface to the converted polygonal mesh.
	*/
	BoolID getCopyUVTopology(){char buffer[4096];sprintf_s (buffer, "%s.cut",mName.c_str());return (const char*)buffer;}
	/*
	Force sharing of uvs on all common vertices - the value of this
	attribute gets overridden by the value of the copyUVTopology attribute.
	*/
	BoolID getShareUVs(){char buffer[4096];sprintf_s (buffer, "%s.suv",mName.c_str());return (const char*)buffer;}
	/*
	The depth from which to extract the CVs of the polyMesh
	(Used only when the extractPointPosition is set to true)
	*** CAUTION *** :Setting to higher values will be both memory-time expensive
	*/
	IntID getLevel(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	Convert the componentIds back and forth
	A mapping that can be used to get the one-to-one association
	between the poly and the SubD component Ids
	*/
	BoolID getConvertComp(){char buffer[4096];sprintf_s (buffer, "%s.cc",mName.c_str());return (const char*)buffer;}
	/*Output CV Id*/
	const Long2ID& getOutSubdCVId(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i]",mName.c_str(),os_i);return (const char*)buffer;}
	/*Higher 32 bit integer of the output CV Id*/
	const IntID& getOutSubdCVIdLeft(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i].osl",mName.c_str(),os_i);return (const char*)buffer;}
	/*Lower 32 bit integer of the output CV Id*/
	const IntID& getOutSubdCVIdRight(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i].osr",mName.c_str(),os_i);return (const char*)buffer;}
	/*Input CV Id*/
	const Long2ID& getInSubdCVId(size_t is_i){char buffer[4096];sprintf_s (buffer, "%s.is[%i]",mName.c_str(),is_i);return (const char*)buffer;}
	/*Higher 32 bit integer of the input CV Id*/
	const IntID& getInSubdCVIdLeft(size_t is_i){char buffer[4096];sprintf_s (buffer, "%s.is[%i].isl",mName.c_str(),is_i);return (const char*)buffer;}
	/*Lower 32 bit integer of the input CV Id*/
	const IntID& getInSubdCVIdRight(size_t is_i){char buffer[4096];sprintf_s (buffer, "%s.is[%i].isr",mName.c_str(),is_i);return (const char*)buffer;}
	/*Preserve vertex ordering in conversion*/
	BoolID getPreserveVertexOrdering(){char buffer[4096];sprintf_s (buffer, "%s.pvo",mName.c_str());return (const char*)buffer;}
	/*Out Vertices corresponding to the inSubDCVs.*/
	const IntID& getOutv(size_t ov_i){char buffer[4096];sprintf_s (buffer, "%s.ov[%i]",mName.c_str(),ov_i);return (const char*)buffer;}
	/*
	If true, the matrix on the input geometry is applied to the object
	and the resulting geometry will have identity matrix on it.  If false
	the conversion is done on the local space object and the resulting
	geometry has the input object's matrix on it.
	*/
	BoolID getApplyMatrixToResult(){char buffer[4096];sprintf_s (buffer, "%s.amr",mName.c_str());return (const char*)buffer;}
protected:
	SubdivToPoly(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVTOPOLY_H__
