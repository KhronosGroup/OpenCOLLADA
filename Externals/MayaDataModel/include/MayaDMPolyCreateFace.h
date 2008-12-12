/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCREATEFACE_H__
#define __MayaDM_POLYCREATEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyCreator.h"
namespace MayaDM
{
/*
<p><pre> Create a new polygonal object with the specified
 face. The face will be automatically closed. The
 vertex array (vertices) must have at least 3 points.
</pre></p>
*/
class PolyCreateFace : public PolyCreator
{
public:
public:
	PolyCreateFace(FILE* file,const std::string& name,const std::string& parent=""):PolyCreator(file, name, parent, "polyCreateFace"){}
	virtual ~PolyCreateFace(){}
	/*Array of vertices for the new object.*/
	void setVertices(size_t v_i,const float3& v){fprintf_s(mFile, "setAttr \".v[%i]\" -type \"float3\" ",v_i);v.write(mFile);fprintf_s(mFile,";\n");}
	/*Array of vertices for the new object.*/
	void setVertices(size_t v_start,size_t v_end,float* v){fprintf_s(mFile,"setAttr \".v[%i:%i]\" ", v_start,v_end);size_t size = (v_end-v_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",v[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Array of vertices for the new object.*/
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
	/*Array of loop sizes (number of points for each loop)*/
	void setLoop(size_t l_i,int l){if(l == 0) return; fprintf_s(mFile, "setAttr \".l[%i]\" %i;\n", l_i,l);}
	/*Array of loop sizes (number of points for each loop)*/
	void setLoop(size_t l_i,const IntID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l[%i]\";\n",mName.c_str(),l_i);}
	/*Number of subdivisions for each edge.*/
	void setSubdivision(int s){if(s == 1) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*Number of subdivisions for each edge.*/
	void setSubdivision(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	What texture mechanism to be applied
	0=No textures, 1=Normalized, Undistorted textures
	2=Unitized textures
	*/
	void setTexture(unsigned int tx){if(tx == 0) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*
	What texture mechanism to be applied
	0=No textures, 1=Normalized, Undistorted textures
	2=Unitized textures
	*/
	void setTexture(const UnsignedintID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tx\";\n",mName.c_str());}
	/*The name of the map set to work on*/
	void setUvSetName(const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs\" -type \"string\" ");uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the map set to work on*/
	void setUvSetName(const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*Array of vertices for the new object.*/
	const Float3ID& getVertices(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i]",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex x coord*/
	const FloatID& getVtxx(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vx",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex y coord*/
	const FloatID& getVtxy(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vy",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex z coord*/
	const FloatID& getVtxz(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vz",mName.c_str(),v_i);return (const char*)buffer;}
	/*Array of loop sizes (number of points for each loop)*/
	const IntID& getLoop(size_t l_i){char buffer[4096];sprintf_s (buffer, "%s.l[%i]",mName.c_str(),l_i);return (const char*)buffer;}
	/*Number of subdivisions for each edge.*/
	IntID getSubdivision(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	What texture mechanism to be applied
	0=No textures, 1=Normalized, Undistorted textures
	2=Unitized textures
	*/
	UnsignedintID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
	/*The name of the map set to work on*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
protected:
	PolyCreateFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyCreator(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCREATEFACE_H__
