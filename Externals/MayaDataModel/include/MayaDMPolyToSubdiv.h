/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTOSUBDIV_H__
#define __MayaDM_POLYTOSUBDIV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class PolyToSubdiv : public DependNode
{
public:
	/*
	Compound attribute that corresponds to uv set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aUVSetName)
	*/
	struct CachedUVs{
		float2* uvPoints;
		void write(FILE* file) const
		{
			size_t size = sizeof(uvPoints)/sizeof(float2);
			for(size_t i=0; i<size; ++i)
			{
				uvPoints[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
public:
	PolyToSubdiv(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "polyToSubdiv"){}
	virtual ~PolyToSubdiv(){}
	/*The input surface which will become the base mesh of the subdivision surface*/
	void setInMesh(const mesh& i){fprintf_s(mFile, "setAttr \".i\" -type \"mesh\" ");i.write(mFile);fprintf_s(mFile,";\n");}
	/*The output subdivision surface*/
	void setOutSubdiv(const SubdivisionSurfaceID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The maximum number of polygons accepted on the input mesh.*/
	void setMaxPolyCount(int mpc){if(mpc == 1000) return; fprintf_s(mFile, "setAttr \".mpc\" %i;\n", mpc);}
	/*The maximum number of polygons accepted on the input mesh.*/
	void setMaxPolyCount(const IntID& mpc){fprintf_s(mFile,"connectAttr \"");mpc.write(mFile);fprintf_s(mFile,"\" \"%s.mpc\";\n",mName.c_str());}
	/*The maximum allowed valence for a vertex on the input mesh*/
	void setMaxEdgesPerVert(int me){if(me == 32) return; fprintf_s(mFile, "setAttr \".me\" %i;\n", me);}
	/*The maximum allowed valence for a vertex on the input mesh*/
	void setMaxEdgesPerVert(const IntID& me){fprintf_s(mFile,"connectAttr \"");me.write(mFile);fprintf_s(mFile,"\" \"%s.me\";\n",mName.c_str());}
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
	/*
	If true, the possible blind data information that comes from the
	polygon will be treated as absolute positions of the vertices,
	instead of the relative offsets.  You most likelly just want to
	use the default of false, unless you know that the blind data
	has the absolute positions in it.
	*/
	void setAbsolutePosition(bool ap){if(ap == false) return; fprintf_s(mFile, "setAttr \".ap\" %i;\n", ap);}
	/*
	If true, the possible blind data information that comes from the
	polygon will be treated as absolute positions of the vertices,
	instead of the relative offsets.  You most likelly just want to
	use the default of false, unless you know that the blind data
	has the absolute positions in it.
	*/
	void setAbsolutePosition(const BoolID& ap){fprintf_s(mFile,"connectAttr \"");ap.write(mFile);fprintf_s(mFile,"\" \"%s.ap\";\n",mName.c_str());}
	/*
	Treatment of Subd UVs when in proxy mode:
	0 - preserve Subd UVs
	1 - build Subd UVs from Poly UVs
	2 - no UVs on Subd
	*/
	void setUvTreatment(unsigned int uvt){if(uvt == 0) return; fprintf_s(mFile, "setAttr \".uvt\" %i;\n", uvt);}
	/*
	Treatment of Subd UVs when in proxy mode:
	0 - preserve Subd UVs
	1 - build Subd UVs from Poly UVs
	2 - no UVs on Subd
	*/
	void setUvTreatment(const UnsignedintID& uvt){fprintf_s(mFile,"connectAttr \"");uvt.write(mFile);fprintf_s(mFile,"\" \"%s.uvt\";\n",mName.c_str());}
	/*
	Compound attribute that corresponds to uv set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aUVSetName)
	*/
	void setCachedUVs(size_t cuv_i,const CachedUVs& cuv){fprintf_s(mFile, "setAttr \".cuv[%i]\" ",cuv_i);cuv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Compound attribute that corresponds to uv set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aUVSetName)
	*/
	void setCachedUVs(size_t cuv_i,const CachedUVsID& cuv){fprintf_s(mFile,"connectAttr \"");cuv.write(mFile);fprintf_s(mFile,"\" \"%s.cuv[%i]\";\n",mName.c_str(),cuv_i);}
	/*
	This is a cached uv point needed to transfer uv data associated with
	finer level vertices (when switching between standard editing mode
	and poly proxy mode.
	*/
	void setUvPoints(size_t cuv_i,size_t uvp_i,const float2& uvp){fprintf_s(mFile, "setAttr \".cuv[%i].uvp[%i]\" -type \"float2\" ",cuv_i,uvp_i);uvp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is a cached uv point needed to transfer uv data associated with
	finer level vertices (when switching between standard editing mode
	and poly proxy mode.
	*/
	void setUvPoints(size_t cuv_i,size_t uvp_start,size_t uvp_end,float* uvp){fprintf_s(mFile,"setAttr \".cuv[%i].uvp[%i:%i]\" ", cuv_i,uvp_start,uvp_end);size_t size = (uvp_end-uvp_start)*2+2;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",uvp[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*
	This is a cached uv point needed to transfer uv data associated with
	finer level vertices (when switching between standard editing mode
	and poly proxy mode.
	*/
	void setUvPoints(size_t cuv_i,size_t uvp_i,const Float2ID& uvp){fprintf_s(mFile,"connectAttr \"");uvp.write(mFile);fprintf_s(mFile,"\" \"%s.cuv[%i].uvp[%i]\";\n",mName.c_str(),cuv_i,uvp_i);}
	/*U value of a cached uv point*/
	void setUvPointsU(size_t cuv_i,size_t uvp_i,float uvu){if(uvu == 0.0) return; fprintf_s(mFile, "setAttr \".cuv[%i].uvp[%i].uvu\" %f;\n", cuv_i,uvp_i,uvu);}
	/*U value of a cached uv point*/
	void setUvPointsU(size_t cuv_i,size_t uvp_i,const FloatID& uvu){fprintf_s(mFile,"connectAttr \"");uvu.write(mFile);fprintf_s(mFile,"\" \"%s.cuv[%i].uvp[%i].uvu\";\n",mName.c_str(),cuv_i,uvp_i);}
	/*V value of a cached uv point*/
	void setUvPointsV(size_t cuv_i,size_t uvp_i,float uvv){if(uvv == 0.0) return; fprintf_s(mFile, "setAttr \".cuv[%i].uvp[%i].uvv\" %f;\n", cuv_i,uvp_i,uvv);}
	/*V value of a cached uv point*/
	void setUvPointsV(size_t cuv_i,size_t uvp_i,const FloatID& uvv){fprintf_s(mFile,"connectAttr \"");uvv.write(mFile);fprintf_s(mFile,"\" \"%s.cuv[%i].uvp[%i].uvv\";\n",mName.c_str(),cuv_i,uvp_i);}
	/*Preserve vertex ordering in conversion*/
	void setPreserveVertexOrdering(bool pvo){if(pvo == true) return; fprintf_s(mFile, "setAttr \".pvo\" %i;\n", pvo);}
	/*Preserve vertex ordering in conversion*/
	void setPreserveVertexOrdering(const BoolID& pvo){fprintf_s(mFile,"connectAttr \"");pvo.write(mFile);fprintf_s(mFile,"\" \"%s.pvo\";\n",mName.c_str());}
	/*Debug flag to test the performance*/
	void setQuickConvert(bool qc){if(qc == true) return; fprintf_s(mFile, "setAttr \".qc\" %i;\n", qc);}
	/*Debug flag to test the performance*/
	void setQuickConvert(const BoolID& qc){fprintf_s(mFile,"connectAttr \"");qc.write(mFile);fprintf_s(mFile,"\" \"%s.qc\";\n",mName.c_str());}
	/*The output subdivision surface*/
	SubdivisionSurfaceID getOutSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The maximum number of polygons accepted on the input mesh.*/
	IntID getMaxPolyCount(){char buffer[4096];sprintf_s (buffer, "%s.mpc",mName.c_str());return (const char*)buffer;}
	/*The maximum allowed valence for a vertex on the input mesh*/
	IntID getMaxEdgesPerVert(){char buffer[4096];sprintf_s (buffer, "%s.me",mName.c_str());return (const char*)buffer;}
	/*
	If true, the matrix on the input geometry is applied to the object
	and the resulting geometry will have identity matrix on it.  If false
	the conversion is done on the local space object and the resulting
	geometry has the input object's matrix on it.
	*/
	BoolID getApplyMatrixToResult(){char buffer[4096];sprintf_s (buffer, "%s.amr",mName.c_str());return (const char*)buffer;}
	/*
	If true, the possible blind data information that comes from the
	polygon will be treated as absolute positions of the vertices,
	instead of the relative offsets.  You most likelly just want to
	use the default of false, unless you know that the blind data
	has the absolute positions in it.
	*/
	BoolID getAbsolutePosition(){char buffer[4096];sprintf_s (buffer, "%s.ap",mName.c_str());return (const char*)buffer;}
	/*
	Treatment of Subd UVs when in proxy mode:
	0 - preserve Subd UVs
	1 - build Subd UVs from Poly UVs
	2 - no UVs on Subd
	*/
	UnsignedintID getUvTreatment(){char buffer[4096];sprintf_s (buffer, "%s.uvt",mName.c_str());return (const char*)buffer;}
	/*
	Compound attribute that corresponds to uv set of a object
	It is a multi attribute. The index of the multi has no
	logical meaning, as indexing is not done by array location
	but instead by a child attribute (See aUVSetName)
	*/
	const CachedUVsID& getCachedUVs(size_t cuv_i){char buffer[4096];sprintf_s (buffer, "%s.cuv[%i]",mName.c_str(),cuv_i);return (const char*)buffer;}
	/*
	This is a cached uv point needed to transfer uv data associated with
	finer level vertices (when switching between standard editing mode
	and poly proxy mode.
	*/
	const Float2ID& getUvPoints(size_t cuv_i,size_t uvp_i){char buffer[4096];sprintf_s (buffer, "%s.cuv[%i].uvp[%i]",mName.c_str(),cuv_i,uvp_i);return (const char*)buffer;}
	/*U value of a cached uv point*/
	const FloatID& getUvPointsU(size_t cuv_i,size_t uvp_i){char buffer[4096];sprintf_s (buffer, "%s.cuv[%i].uvp[%i].uvu",mName.c_str(),cuv_i,uvp_i);return (const char*)buffer;}
	/*V value of a cached uv point*/
	const FloatID& getUvPointsV(size_t cuv_i,size_t uvp_i){char buffer[4096];sprintf_s (buffer, "%s.cuv[%i].uvp[%i].uvv",mName.c_str(),cuv_i,uvp_i);return (const char*)buffer;}
	/*Preserve vertex ordering in conversion*/
	BoolID getPreserveVertexOrdering(){char buffer[4096];sprintf_s (buffer, "%s.pvo",mName.c_str());return (const char*)buffer;}
	/*Debug flag to test the performance*/
	BoolID getQuickConvert(){char buffer[4096];sprintf_s (buffer, "%s.qc",mName.c_str());return (const char*)buffer;}
protected:
	PolyToSubdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYTOSUBDIV_H__
