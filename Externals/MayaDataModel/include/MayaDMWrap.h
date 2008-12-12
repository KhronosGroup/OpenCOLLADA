/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WRAP_H__
#define __MayaDM_WRAP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
<p><pre>
 Description:

 The wrap deformer node binds a geometry with one or more influence objects
 in such a way that transformations or deformations of the influence objects
 result in an intuitive deformation of the geometry.  The amount by which
 the motion of a component of an influence object affects a point on the
 bound geometry is a function of the distance of the component from the point.
 Influence objects can be mesh shapes, nurbs curves and nurbs
 surfaces.

</pre></p>
*/
class Wrap : public GeometryFilter
{
public:
public:
	Wrap(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "wrap"){}
	virtual ~Wrap(){}
	/*World matrix of the deformed object*/
	void setGeomMatrix(const matrix& gm){if(gm == identity) return; fprintf_s(mFile, "setAttr \".gm\" -type \"matrix\" ");gm.write(mFile);fprintf_s(mFile,";\n");}
	/*World matrix of the deformed object*/
	void setGeomMatrix(const MatrixID& gm){fprintf_s(mFile,"connectAttr \"");gm.write(mFile);fprintf_s(mFile,"\" \"%s.gm\";\n",mName.c_str());}
	/*Driver geometry*/
	void setDriverPoints(size_t dp_i,const GeometryID& dp){fprintf_s(mFile,"connectAttr \"");dp.write(mFile);fprintf_s(mFile,"\" \"%s.dp[%i]\";\n",mName.c_str(),dp_i);}
	/*Base geometry*/
	void setBasePoints(size_t bp_i,const GeometryID& bp){fprintf_s(mFile,"connectAttr \"");bp.write(mFile);fprintf_s(mFile,"\" \"%s.bp[%i]\";\n",mName.c_str(),bp_i);}
	/*Dropoff rates for the influence objects*/
	void setDropoff(size_t dr_i,double dr){if(dr == 4.0) return; fprintf_s(mFile, "setAttr \".dr[%i]\" %f;\n", dr_i,dr);}
	/*Dropoff rates for the influence objects*/
	void setDropoff(size_t dr_i,const DoubleID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr[%i]\";\n",mName.c_str(),dr_i);}
	/*
	Controls how smooth the deformation resulting from the
	given influence object will be
	*/
	void setSmoothness(size_t smt_i,double smt){if(smt == 0.0) return; fprintf_s(mFile, "setAttr \".smt[%i]\" %f;\n", smt_i,smt);}
	/*
	Controls how smooth the deformation resulting from the
	given influence object will be
	*/
	void setSmoothness(size_t smt_i,const DoubleID& smt){fprintf_s(mFile,"connectAttr \"");smt.write(mFile);fprintf_s(mFile,"\" \"%s.smt[%i]\";\n",mName.c_str(),smt_i);}
	/*Influence type (1 = point, 2 = face)*/
	void setInflType(size_t it_i,short it){if(it == 2) return; fprintf_s(mFile, "setAttr \".it[%i]\" %i;\n", it_i,it);}
	/*Influence type (1 = point, 2 = face)*/
	void setInflType(size_t it_i,const ShortID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.it[%i]\";\n",mName.c_str(),it_i);}
	/*The number of samples to be taken on influence curves/surfaces*/
	void setNurbsSamples(size_t ns_i,short ns){if(ns == 10) return; fprintf_s(mFile, "setAttr \".ns[%i]\" %i;\n", ns_i,ns);}
	/*The number of samples to be taken on influence curves/surfaces*/
	void setNurbsSamples(size_t ns_i,const ShortID& ns){fprintf_s(mFile,"connectAttr \"");ns.write(mFile);fprintf_s(mFile,"\" \"%s.ns[%i]\";\n",mName.c_str(),ns_i);}
	/*Weight threshold under which no deformation takes place*/
	void setWeightThreshold(double wt){if(wt == 0) return; fprintf_s(mFile, "setAttr \".wt\" %f;\n", wt);}
	/*Weight threshold under which no deformation takes place*/
	void setWeightThreshold(const DoubleID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.wt\";\n",mName.c_str());}
	/*
	Distance threshold over which points on the deformed
	surface are not affected.  Use zero to turn the max
	distance off.
	*/
	void setMaxDistance(double md){if(md == 0) return; fprintf_s(mFile, "setAttr \".md\" %f;\n", md);}
	/*
	Distance threshold over which points on the deformed
	surface are not affected.  Use zero to turn the max
	distance off.
	*/
	void setMaxDistance(const DoubleID& md){fprintf_s(mFile,"connectAttr \"");md.write(mFile);fprintf_s(mFile,"\" \"%s.md\";\n",mName.c_str());}
	/*
	Exclusive bind for weighting. If on, only weights of zero and one are assigned.
	If off, weights are computed based on distance
	Only applies to mesh influence objects
	*/
	void setExclusiveBind(bool rb){if(rb == false) return; fprintf_s(mFile, "setAttr \".rb\" %i;\n", rb);}
	/*
	Exclusive bind for weighting. If on, only weights of zero and one are assigned.
	If off, weights are computed based on distance
	Only applies to mesh influence objects
	*/
	void setExclusiveBind(const BoolID& rb){fprintf_s(mFile,"connectAttr \"");rb.write(mFile);fprintf_s(mFile,"\" \"%s.rb\";\n",mName.c_str());}
	/*Gets marked dirty when the point weights need to be recomputed*/
	void setWtDrty(const MessageID& wtd){fprintf_s(mFile,"connectAttr \"");wtd.write(mFile);fprintf_s(mFile,"\" \"%s.wtd\";\n",mName.c_str());}
	/*Gets marked dirty every time  something changes in the base geometry*/
	void setBaseDrt(const MessageID& bsd){fprintf_s(mFile,"connectAttr \"");bsd.write(mFile);fprintf_s(mFile,"\" \"%s.bsd\";\n",mName.c_str());}
	/*World matrix of the deformed object*/
	MatrixID getGeomMatrix(){char buffer[4096];sprintf_s (buffer, "%s.gm",mName.c_str());return (const char*)buffer;}
	/*Driver geometry*/
	const GeometryID& getDriverPoints(size_t dp_i){char buffer[4096];sprintf_s (buffer, "%s.dp[%i]",mName.c_str(),dp_i);return (const char*)buffer;}
	/*Base geometry*/
	const GeometryID& getBasePoints(size_t bp_i){char buffer[4096];sprintf_s (buffer, "%s.bp[%i]",mName.c_str(),bp_i);return (const char*)buffer;}
	/*Dropoff rates for the influence objects*/
	const DoubleID& getDropoff(size_t dr_i){char buffer[4096];sprintf_s (buffer, "%s.dr[%i]",mName.c_str(),dr_i);return (const char*)buffer;}
	/*
	Controls how smooth the deformation resulting from the
	given influence object will be
	*/
	const DoubleID& getSmoothness(size_t smt_i){char buffer[4096];sprintf_s (buffer, "%s.smt[%i]",mName.c_str(),smt_i);return (const char*)buffer;}
	/*Influence type (1 = point, 2 = face)*/
	const ShortID& getInflType(size_t it_i){char buffer[4096];sprintf_s (buffer, "%s.it[%i]",mName.c_str(),it_i);return (const char*)buffer;}
	/*The number of samples to be taken on influence curves/surfaces*/
	const ShortID& getNurbsSamples(size_t ns_i){char buffer[4096];sprintf_s (buffer, "%s.ns[%i]",mName.c_str(),ns_i);return (const char*)buffer;}
	/*Weight threshold under which no deformation takes place*/
	DoubleID getWeightThreshold(){char buffer[4096];sprintf_s (buffer, "%s.wt",mName.c_str());return (const char*)buffer;}
	/*
	Distance threshold over which points on the deformed
	surface are not affected.  Use zero to turn the max
	distance off.
	*/
	DoubleID getMaxDistance(){char buffer[4096];sprintf_s (buffer, "%s.md",mName.c_str());return (const char*)buffer;}
	/*
	Exclusive bind for weighting. If on, only weights of zero and one are assigned.
	If off, weights are computed based on distance
	Only applies to mesh influence objects
	*/
	BoolID getExclusiveBind(){char buffer[4096];sprintf_s (buffer, "%s.rb",mName.c_str());return (const char*)buffer;}
	/*Gets marked dirty when the point weights need to be recomputed*/
	MessageID getWtDrty(){char buffer[4096];sprintf_s (buffer, "%s.wtd",mName.c_str());return (const char*)buffer;}
	/*Gets marked dirty every time  something changes in the base geometry*/
	MessageID getBaseDrt(){char buffer[4096];sprintf_s (buffer, "%s.bsd",mName.c_str());return (const char*)buffer;}
protected:
	Wrap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_WRAP_H__
