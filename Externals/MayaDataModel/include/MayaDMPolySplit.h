/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSPLIT_H__
#define __MayaDM_POLYSPLIT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Split faces and edges of a polygonal object.
 New vertices can be inserted along existing edges
 or placed as free points within existing faces.
 First and last new points must lie on existing edges.<p/>
*/
class PolySplit : public PolyModifier
{
public:
public:
	PolySplit(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polySplit"){}
	virtual ~PolySplit(){}
	/*
	Array (multi-attribute) of new free vertices
	(used to create a new point in a face).
	The order of the array corresponds to the order of the free
	points, but is not the same size and does not line up with
	the desc array (it only contains entries for free points).
	*/
	void setVertices(size_t v_i,const float3& v){fprintf_s(mFile, "setAttr \".v[%i]\" -type \"float3\" ",v_i);v.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of new free vertices
	(used to create a new point in a face).
	The order of the array corresponds to the order of the free
	points, but is not the same size and does not line up with
	the desc array (it only contains entries for free points).
	*/
	void setVertices(size_t v_start,size_t v_end,float* v){fprintf_s(mFile,"setAttr \".v[%i:%i]\" ", v_start,v_end);size_t size = (v_end-v_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",v[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of new free vertices
	(used to create a new point in a face).
	The order of the array corresponds to the order of the free
	points, but is not the same size and does not line up with
	the desc array (it only contains entries for free points).
	*/
	void setVertices(size_t v_i,const Float3ID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i]\";\n",mName.c_str(),v_i);}
	/*New vertex x coord*/
	void setVtxx(size_t v_i,float vx){if(vx == 0) return; fprintf_s(mFile, "setAttr \".v[%i].vx\" %f;\n", v_i,vx);}
	/*New vertex x coord*/
	void setVtxx(size_t v_i,const FloatID& vx){fprintf_s(mFile,"connectAttr \"");vx.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i].vx\";\n",mName.c_str(),v_i);}
	/*New vertex y coord*/
	void setVtxy(size_t v_i,float vy){if(vy == 0) return; fprintf_s(mFile, "setAttr \".v[%i].vy\" %f;\n", v_i,vy);}
	/*New vertex y coord*/
	void setVtxy(size_t v_i,const FloatID& vy){fprintf_s(mFile,"connectAttr \"");vy.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i].vy\";\n",mName.c_str(),v_i);}
	/*New vertex z coord*/
	void setVtxz(size_t v_i,float vz){if(vz == 0) return; fprintf_s(mFile, "setAttr \".v[%i].vz\" %f;\n", v_i,vz);}
	/*New vertex z coord*/
	void setVtxz(size_t v_i,const FloatID& vz){fprintf_s(mFile,"connectAttr \"");vz.write(mFile);fprintf_s(mFile,"\" \"%s.v[%i].vz\";\n",mName.c_str(),v_i);}
	/*
	Array (multi-attribute) of edge distance ratios used to create
	new points on existing edges. Range of edge values is [0.0, 1.0].
	A value of 0 puts the new point at the start of the edge,
	1 specifies the new point should go at the endpoint.
	This array has the same size as the desc array.
	A free point index in desc will correspond with a -1.0 edge
	value for that index.
	*/
	void setEdge(size_t e_i,float e){if(e == 0.0) return; fprintf_s(mFile, "setAttr \".e[%i]\" %f;\n", e_i,e);}
	/*
	Array (multi-attribute) of edge distance ratios used to create
	new points on existing edges. Range of edge values is [0.0, 1.0].
	A value of 0 puts the new point at the start of the edge,
	1 specifies the new point should go at the endpoint.
	This array has the same size as the desc array.
	A free point index in desc will correspond with a -1.0 edge
	value for that index.
	*/
	void setEdge(size_t e_i,const FloatID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e[%i]\";\n",mName.c_str(),e_i);}
	/*
	Array (multi-attribute) of descriptors indicating whether the new
	point to be inserted should be placed on an existing edge or
	inside a face (as a free point). If a free point, the desc value
	for that index will be the face number. If the new point
	is to be on an existing edge, the desc value will be the edge
	number bitwise ANDed with either 0x40000000 for a hole border
	edge or 0x80000000 otherwise.
	*/
	void setDesc(size_t d_i,int d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d[%i]\" %i;\n", d_i,d);}
	/*
	Array (multi-attribute) of descriptors indicating whether the new
	point to be inserted should be placed on an existing edge or
	inside a face (as a free point). If a free point, the desc value
	for that index will be the face number. If the new point
	is to be on an existing edge, the desc value will be the edge
	number bitwise ANDed with either 0x40000000 for a hole border
	edge or 0x80000000 otherwise.
	*/
	void setDesc(size_t d_i,const IntID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d[%i]\";\n",mName.c_str(),d_i);}
	/*
	Edge subdivision. New edges for which both vertices lie on existing edges
	will have this many subdivisions. New edges involving free points are not
	subdivided.
	*/
	void setSubdivision(int s){if(s == 1) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*
	Edge subdivision. New edges for which both vertices lie on existing edges
	will have this many subdivisions. New edges involving free points are not
	subdivided.
	*/
	void setSubdivision(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Angle below which new edges will be smoothed*/
	void setSmoothingAngle(double sma){if(sma == 0) return; fprintf_s(mFile, "setAttr \".sma\" %f;\n", sma);}
	/*Angle below which new edges will be smoothed*/
	void setSmoothingAngle(const DoubleID& sma){fprintf_s(mFile,"connectAttr \"");sma.write(mFile);fprintf_s(mFile,"\" \"%s.sma\";\n",mName.c_str());}
	/*
	Enable Maya 7.0 behaviour.
	This attribute is not meant to be modified through command line.
	*/
	void setMaya70(bool m70){if(m70 == true) return; fprintf_s(mFile, "setAttr \".m70\" %i;\n", m70);}
	/*
	Array (multi-attribute) of new free vertices
	(used to create a new point in a face).
	The order of the array corresponds to the order of the free
	points, but is not the same size and does not line up with
	the desc array (it only contains entries for free points).
	*/
	const Float3ID& getVertices(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i]",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex x coord*/
	const FloatID& getVtxx(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vx",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex y coord*/
	const FloatID& getVtxy(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vy",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex z coord*/
	const FloatID& getVtxz(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vz",mName.c_str(),v_i);return (const char*)buffer;}
	/*
	Array (multi-attribute) of edge distance ratios used to create
	new points on existing edges. Range of edge values is [0.0, 1.0].
	A value of 0 puts the new point at the start of the edge,
	1 specifies the new point should go at the endpoint.
	This array has the same size as the desc array.
	A free point index in desc will correspond with a -1.0 edge
	value for that index.
	*/
	const FloatID& getEdge(size_t e_i){char buffer[4096];sprintf_s (buffer, "%s.e[%i]",mName.c_str(),e_i);return (const char*)buffer;}
	/*
	Array (multi-attribute) of descriptors indicating whether the new
	point to be inserted should be placed on an existing edge or
	inside a face (as a free point). If a free point, the desc value
	for that index will be the face number. If the new point
	is to be on an existing edge, the desc value will be the edge
	number bitwise ANDed with either 0x40000000 for a hole border
	edge or 0x80000000 otherwise.
	*/
	const IntID& getDesc(size_t d_i){char buffer[4096];sprintf_s (buffer, "%s.d[%i]",mName.c_str(),d_i);return (const char*)buffer;}
	/*
	Edge subdivision. New edges for which both vertices lie on existing edges
	will have this many subdivisions. New edges involving free points are not
	subdivided.
	*/
	IntID getSubdivision(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Angle below which new edges will be smoothed*/
	DoubleID getSmoothingAngle(){char buffer[4096];sprintf_s (buffer, "%s.sma",mName.c_str());return (const char*)buffer;}
protected:
	PolySplit(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSPLIT_H__
