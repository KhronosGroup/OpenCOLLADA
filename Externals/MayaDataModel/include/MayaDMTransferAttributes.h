/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRANSFERATTRIBUTES_H__
#define __MayaDM_TRANSFERATTRIBUTES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
/*
<p><pre> Projects a map onto an object, using several orthogonal projections simultaneously.
</pre></p>
*/
class TransferAttributes : public WeightGeometryFilter
{
public:
public:
	TransferAttributes(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "transferAttributes"){}
	virtual ~TransferAttributes(){}
	/*The list of source surface containing the attributes to sample*/
	void setSource(size_t src_i,const GeometryID& src){fprintf_s(mFile,"connectAttr \"");src.write(mFile);fprintf_s(mFile,"\" \"%s.src[%i]\";\n",mName.c_str(),src_i);}
	/*Should position data be sampled?*/
	void setTransferPositions(unsigned int pos){if(pos == 0) return; fprintf_s(mFile, "setAttr \".pos\" %i;\n", pos);}
	/*Should position data be sampled?*/
	void setTransferPositions(const UnsignedintID& pos){fprintf_s(mFile,"connectAttr \"");pos.write(mFile);fprintf_s(mFile,"\" \"%s.pos\";\n",mName.c_str());}
	/*Should normal data be sampled?*/
	void setTransferNormals(unsigned int nml){if(nml == 0) return; fprintf_s(mFile, "setAttr \".nml\" %i;\n", nml);}
	/*Should normal data be sampled?*/
	void setTransferNormals(const UnsignedintID& nml){fprintf_s(mFile,"connectAttr \"");nml.write(mFile);fprintf_s(mFile,"\" \"%s.nml\";\n",mName.c_str());}
	/*Should UV data be sampled?*/
	void setTransferUVs(unsigned int uvs){if(uvs == 0) return; fprintf_s(mFile, "setAttr \".uvs\" %i;\n", uvs);}
	/*Should UV data be sampled?*/
	void setTransferUVs(const UnsignedintID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*
	When sampling a single UV set, this specifies which UV set should
	be sampled on the source surface(s).
	*/
	void setSourceUVSet(const string& suv){if(suv == "NULL") return; fprintf_s(mFile, "setAttr \".suv\" -type \"string\" ");suv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When sampling a single UV set, this specifies which UV set should
	be sampled on the source surface(s).
	*/
	void setSourceUVSet(const StringID& suv){fprintf_s(mFile,"connectAttr \"");suv.write(mFile);fprintf_s(mFile,"\" \"%s.suv\";\n",mName.c_str());}
	/*
	When sampling a single UV set, this specifies which UV set the
	result should be put into on the target surface.
	*/
	void setTargetUVSet(const string& tuv){if(tuv == "NULL") return; fprintf_s(mFile, "setAttr \".tuv\" -type \"string\" ");tuv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When sampling a single UV set, this specifies which UV set the
	result should be put into on the target surface.
	*/
	void setTargetUVSet(const StringID& tuv){fprintf_s(mFile,"connectAttr \"");tuv.write(mFile);fprintf_s(mFile,"\" \"%s.tuv\";\n",mName.c_str());}
	/*Should color data be sampled?*/
	void setTransferColors(unsigned int col){if(col == 0) return; fprintf_s(mFile, "setAttr \".col\" %i;\n", col);}
	/*Should color data be sampled?*/
	void setTransferColors(const UnsignedintID& col){fprintf_s(mFile,"connectAttr \"");col.write(mFile);fprintf_s(mFile,"\" \"%s.col\";\n",mName.c_str());}
	/*
	When sampling a single color set, this specifies which color set should
	be sampled on the source surface(s).
	*/
	void setSourceColorSet(const string& scs){if(scs == "NULL") return; fprintf_s(mFile, "setAttr \".scs\" -type \"string\" ");scs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When sampling a single color set, this specifies which color set should
	be sampled on the source surface(s).
	*/
	void setSourceColorSet(const StringID& scs){fprintf_s(mFile,"connectAttr \"");scs.write(mFile);fprintf_s(mFile,"\" \"%s.scs\";\n",mName.c_str());}
	/*
	When sampling a single color set, this specifies which color set the
	result should be put into on the target surface.
	*/
	void setTargetColorSet(const string& tcs){if(tcs == "NULL") return; fprintf_s(mFile, "setAttr \".tcs\" -type \"string\" ");tcs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When sampling a single color set, this specifies which color set the
	result should be put into on the target surface.
	*/
	void setTargetColorSet(const StringID& tcs){fprintf_s(mFile,"connectAttr \"");tcs.write(mFile);fprintf_s(mFile,"\" \"%s.tcs\";\n",mName.c_str());}
	/*Controls whether attributes are sampled in world or object space.*/
	void setSampleSpace(unsigned int spa){if(spa == 0) return; fprintf_s(mFile, "setAttr \".spa\" %i;\n", spa);}
	/*Controls whether attributes are sampled in world or object space.*/
	void setSampleSpace(const UnsignedintID& spa){fprintf_s(mFile,"connectAttr \"");spa.write(mFile);fprintf_s(mFile,"\" \"%s.spa\";\n",mName.c_str());}
	/*
	When sampling in UV space, this specifies which UV set is used
	for the source surface(s).
	*/
	void setSourceUVSpace(const string& sus){if(sus == "NULL") return; fprintf_s(mFile, "setAttr \".sus\" -type \"string\" ");sus.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When sampling in UV space, this specifies which UV set is used
	for the source surface(s).
	*/
	void setSourceUVSpace(const StringID& sus){fprintf_s(mFile,"connectAttr \"");sus.write(mFile);fprintf_s(mFile,"\" \"%s.sus\";\n",mName.c_str());}
	/*
	When sampling in UV space, this specifies which UV set is used
	for the target surface.
	*/
	void setTargetUVSpace(const string& tus){if(tus == "NULL") return; fprintf_s(mFile, "setAttr \".tus\" -type \"string\" ");tus.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When sampling in UV space, this specifies which UV set is used
	for the target surface.
	*/
	void setTargetUVSpace(const StringID& tus){fprintf_s(mFile,"connectAttr \"");tus.write(mFile);fprintf_s(mFile,"\" \"%s.tus\";\n",mName.c_str());}
	/*
	Which search method should be used to match points between
	the source and target surfaces.
	*/
	void setSearchMethod(unsigned int mtd){if(mtd == 1) return; fprintf_s(mFile, "setAttr \".mtd\" %i;\n", mtd);}
	/*
	Which search method should be used to match points between
	the source and target surfaces.
	*/
	void setSearchMethod(const UnsignedintID& mtd){fprintf_s(mFile,"connectAttr \"");mtd.write(mFile);fprintf_s(mFile,"\" \"%s.mtd\";\n",mName.c_str());}
	/*The maximum distance away from the target to look for source surfaces.*/
	void setSearchDistance(double dis){if(dis == 0.0) return; fprintf_s(mFile, "setAttr \".dis\" %f;\n", dis);}
	/*The maximum distance away from the target to look for source surfaces.*/
	void setSearchDistance(const DoubleID& dis){fprintf_s(mFile,"connectAttr \"");dis.write(mFile);fprintf_s(mFile,"\" \"%s.dis\";\n",mName.c_str());}
	/*How aggressively should the search try to find a path between vertices*/
	void setSearchTolerance(double tol){if(tol == 1.3) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*How aggressively should the search try to find a path between vertices*/
	void setSearchTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*The scaling to use when sampling. Negative values give mirroring.*/
	void setSearchScale(const double3& ss){if(ss == double3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".ss\" -type \"double3\" ");ss.write(mFile);fprintf_s(mFile,";\n");}
	/*The scaling to use when sampling. Negative values give mirroring.*/
	void setSearchScale(const Double3ID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*Search scaling X value.*/
	void setSearchScaleX(double ssx){if(ssx == 0) return; fprintf_s(mFile, "setAttr \".ss.ssx\" %f;\n", ssx);}
	/*Search scaling X value.*/
	void setSearchScaleX(const DoubleID& ssx){fprintf_s(mFile,"connectAttr \"");ssx.write(mFile);fprintf_s(mFile,"\" \"%s.ss.ssx\";\n",mName.c_str());}
	/*Search scaling Y value.*/
	void setSearchScaleY(double ssy){if(ssy == 0) return; fprintf_s(mFile, "setAttr \".ss.ssy\" %f;\n", ssy);}
	/*Search scaling Y value.*/
	void setSearchScaleY(const DoubleID& ssy){fprintf_s(mFile,"connectAttr \"");ssy.write(mFile);fprintf_s(mFile,"\" \"%s.ss.ssy\";\n",mName.c_str());}
	/*Search scaling Z value.*/
	void setSearchScaleZ(double ssz){if(ssz == 0) return; fprintf_s(mFile, "setAttr \".ss.ssz\" %f;\n", ssz);}
	/*Search scaling Z value.*/
	void setSearchScaleZ(const DoubleID& ssz){fprintf_s(mFile,"connectAttr \"");ssz.write(mFile);fprintf_s(mFile,"\" \"%s.ss.ssz\";\n",mName.c_str());}
	/*Controls whether sampled texture coordinates are flipped in UV space.*/
	void setFlipUVs(unsigned int fuv){if(fuv == 0) return; fprintf_s(mFile, "setAttr \".fuv\" %i;\n", fuv);}
	/*Controls whether sampled texture coordinates are flipped in UV space.*/
	void setFlipUVs(const UnsignedintID& fuv){fprintf_s(mFile,"connectAttr \"");fuv.write(mFile);fprintf_s(mFile,"\" \"%s.fuv\";\n",mName.c_str());}
	/*Should color borders be preserved when transfering color.*/
	void setColorBorders(unsigned int clb){if(clb == 1) return; fprintf_s(mFile, "setAttr \".clb\" %i;\n", clb);}
	/*Should color borders be preserved when transfering color.*/
	void setColorBorders(const UnsignedintID& clb){fprintf_s(mFile,"connectAttr \"");clb.write(mFile);fprintf_s(mFile,"\" \"%s.clb\";\n",mName.c_str());}
	/*The list of source surface containing the attributes to sample*/
	const GeometryID& getSource(size_t src_i){char buffer[4096];sprintf_s (buffer, "%s.src[%i]",mName.c_str(),src_i);return (const char*)buffer;}
	/*Should position data be sampled?*/
	UnsignedintID getTransferPositions(){char buffer[4096];sprintf_s (buffer, "%s.pos",mName.c_str());return (const char*)buffer;}
	/*Should normal data be sampled?*/
	UnsignedintID getTransferNormals(){char buffer[4096];sprintf_s (buffer, "%s.nml",mName.c_str());return (const char*)buffer;}
	/*Should UV data be sampled?*/
	UnsignedintID getTransferUVs(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
	/*
	When sampling a single UV set, this specifies which UV set should
	be sampled on the source surface(s).
	*/
	StringID getSourceUVSet(){char buffer[4096];sprintf_s (buffer, "%s.suv",mName.c_str());return (const char*)buffer;}
	/*
	When sampling a single UV set, this specifies which UV set the
	result should be put into on the target surface.
	*/
	StringID getTargetUVSet(){char buffer[4096];sprintf_s (buffer, "%s.tuv",mName.c_str());return (const char*)buffer;}
	/*Should color data be sampled?*/
	UnsignedintID getTransferColors(){char buffer[4096];sprintf_s (buffer, "%s.col",mName.c_str());return (const char*)buffer;}
	/*
	When sampling a single color set, this specifies which color set should
	be sampled on the source surface(s).
	*/
	StringID getSourceColorSet(){char buffer[4096];sprintf_s (buffer, "%s.scs",mName.c_str());return (const char*)buffer;}
	/*
	When sampling a single color set, this specifies which color set the
	result should be put into on the target surface.
	*/
	StringID getTargetColorSet(){char buffer[4096];sprintf_s (buffer, "%s.tcs",mName.c_str());return (const char*)buffer;}
	/*Controls whether attributes are sampled in world or object space.*/
	UnsignedintID getSampleSpace(){char buffer[4096];sprintf_s (buffer, "%s.spa",mName.c_str());return (const char*)buffer;}
	/*
	When sampling in UV space, this specifies which UV set is used
	for the source surface(s).
	*/
	StringID getSourceUVSpace(){char buffer[4096];sprintf_s (buffer, "%s.sus",mName.c_str());return (const char*)buffer;}
	/*
	When sampling in UV space, this specifies which UV set is used
	for the target surface.
	*/
	StringID getTargetUVSpace(){char buffer[4096];sprintf_s (buffer, "%s.tus",mName.c_str());return (const char*)buffer;}
	/*
	Which search method should be used to match points between
	the source and target surfaces.
	*/
	UnsignedintID getSearchMethod(){char buffer[4096];sprintf_s (buffer, "%s.mtd",mName.c_str());return (const char*)buffer;}
	/*The maximum distance away from the target to look for source surfaces.*/
	DoubleID getSearchDistance(){char buffer[4096];sprintf_s (buffer, "%s.dis",mName.c_str());return (const char*)buffer;}
	/*How aggressively should the search try to find a path between vertices*/
	DoubleID getSearchTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*The scaling to use when sampling. Negative values give mirroring.*/
	Double3ID getSearchScale(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*Search scaling X value.*/
	DoubleID getSearchScaleX(){char buffer[4096];sprintf_s (buffer, "%s.ss.ssx",mName.c_str());return (const char*)buffer;}
	/*Search scaling Y value.*/
	DoubleID getSearchScaleY(){char buffer[4096];sprintf_s (buffer, "%s.ss.ssy",mName.c_str());return (const char*)buffer;}
	/*Search scaling Z value.*/
	DoubleID getSearchScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.ss.ssz",mName.c_str());return (const char*)buffer;}
	/*Controls whether sampled texture coordinates are flipped in UV space.*/
	UnsignedintID getFlipUVs(){char buffer[4096];sprintf_s (buffer, "%s.fuv",mName.c_str());return (const char*)buffer;}
	/*Should color borders be preserved when transfering color.*/
	UnsignedintID getColorBorders(){char buffer[4096];sprintf_s (buffer, "%s.clb",mName.c_str());return (const char*)buffer;}
protected:
	TransferAttributes(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):WeightGeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TRANSFERATTRIBUTES_H__
