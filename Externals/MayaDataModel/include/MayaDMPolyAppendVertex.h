/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYAPPENDVERTEX_H__
#define __MayaDM_POLYAPPENDVERTEX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*Appends a new face to an existing polygonal object.<p/>*/
class PolyAppendVertex : public PolyModifier
{
public:
public:
	PolyAppendVertex(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyAppendVertex"){}
	virtual ~PolyAppendVertex(){}
	/*Array of new vertices.*/
	void setVertices(size_t v_i,const float3& v){fprintf_s(mFile, "setAttr \".v[%i]\" -type \"float3\" ",v_i);v.write(mFile);fprintf_s(mFile,";\n");}
	/*Array of new vertices.*/
	void setVertices(size_t v_start,size_t v_end,float* v){fprintf_s(mFile,"setAttr \".v[%i:%i]\" ", v_start,v_end);size_t size = (v_end-v_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",v[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*Array of new vertices.*/
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
	/*Array of descriptors : either a new point or a vertex num.*/
	void setDesc(size_t d_i,int d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d[%i]\" %i;\n", d_i,d);}
	/*Array of descriptors : either a new point or a vertex num.*/
	void setDesc(size_t d_i,const IntID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d[%i]\";\n",mName.c_str(),d_i);}
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
	/*Array of new vertices.*/
	const Float3ID& getVertices(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i]",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex x coord*/
	const FloatID& getVtxx(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vx",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex y coord*/
	const FloatID& getVtxy(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vy",mName.c_str(),v_i);return (const char*)buffer;}
	/*New vertex z coord*/
	const FloatID& getVtxz(size_t v_i){char buffer[4096];sprintf_s (buffer, "%s.v[%i].vz",mName.c_str(),v_i);return (const char*)buffer;}
	/*Array of descriptors : either a new point or a vertex num.*/
	const IntID& getDesc(size_t d_i){char buffer[4096];sprintf_s (buffer, "%s.d[%i]",mName.c_str(),d_i);return (const char*)buffer;}
	/*
	What texture mechanism to be applied
	0=No textures, 1=Normalized, Undistorted textures
	2=Unitized textures
	*/
	UnsignedintID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
protected:
	PolyAppendVertex(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYAPPENDVERTEX_H__
