/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTWEAKUV_H__
#define __MayaDM_POLYTWEAKUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*Node to edit UV coordinates of polygonal objects.<p/>*/
class PolyTweakUV : public PolyModifier
{
public:
	/*
	Array (multi-attribute) of polygon uv points.
	This attribute is used when new UVs are added to the polygon.
	*/
	struct NewUV{
		int faceId;
		int vertexId;
		float newUValue;
		float newVValue;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", faceId);
			fprintf_s(file,"%i ", vertexId);
			fprintf_s(file,"%f ", newUValue);
			fprintf_s(file,"%f", newVValue);
		}
	};
public:
	PolyTweakUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyTweakUV"){}
	virtual ~PolyTweakUV(){}
	/*
	Array (multi-attribute) of polygon uv displacements.
	There is one for each original UV of the polygon.
	*/
	void setUvTweak(size_t uvtk_i,const float2& uvtk){if(uvtk == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".uvtk[%i]\" -type \"float2\" ",uvtk_i);uvtk.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of polygon uv displacements.
	There is one for each original UV of the polygon.
	*/
	void setUvTweak(size_t uvtk_start,size_t uvtk_end,float* uvtk){fprintf_s(mFile,"setAttr \".uvtk[%i:%i]\" ", uvtk_start,uvtk_end);size_t size = (uvtk_end-uvtk_start)*2+2;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",uvtk[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of polygon uv displacements.
	There is one for each original UV of the polygon.
	*/
	void setUvTweak(size_t uvtk_i,const Float2ID& uvtk){fprintf_s(mFile,"connectAttr \"");uvtk.write(mFile);fprintf_s(mFile,"\" \"%s.uvtk[%i]\";\n",mName.c_str(),uvtk_i);}
	/*Tweak value of U coordinate*/
	void setUvTweakU(size_t uvtk_i,float tu){if(tu == 0.0) return; fprintf_s(mFile, "setAttr \".uvtk[%i].tu\" %f;\n", uvtk_i,tu);}
	/*Tweak value of U coordinate*/
	void setUvTweakU(size_t uvtk_i,const FloatID& tu){fprintf_s(mFile,"connectAttr \"");tu.write(mFile);fprintf_s(mFile,"\" \"%s.uvtk[%i].tu\";\n",mName.c_str(),uvtk_i);}
	/*Tweak value of V coordinate*/
	void setUvTweakV(size_t uvtk_i,float tv){if(tv == 0.0) return; fprintf_s(mFile, "setAttr \".uvtk[%i].tv\" %f;\n", uvtk_i,tv);}
	/*Tweak value of V coordinate*/
	void setUvTweakV(size_t uvtk_i,const FloatID& tv){fprintf_s(mFile,"connectAttr \"");tv.write(mFile);fprintf_s(mFile,"\" \"%s.uvtk[%i].tv\";\n",mName.c_str(),uvtk_i);}
	/*
	Array (multi-attribute) of polygon uv points.
	This attribute is used when new UVs are added to the polygon.
	*/
	void setNewUV(size_t nuv_i,const NewUV& nuv){fprintf_s(mFile, "setAttr \".nuv[%i]\" ",nuv_i);nuv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of polygon uv points.
	This attribute is used when new UVs are added to the polygon.
	*/
	void setNewUV(size_t nuv_i,const NewUVID& nuv){fprintf_s(mFile,"connectAttr \"");nuv.write(mFile);fprintf_s(mFile,"\" \"%s.nuv[%i]\";\n",mName.c_str(),nuv_i);}
	/*Face Id of new UV*/
	void setFaceId(size_t nuv_i,int fid){if(fid == 0) return; fprintf_s(mFile, "setAttr \".nuv[%i].fid\" %i;\n", nuv_i,fid);}
	/*Face Id of new UV*/
	void setFaceId(size_t nuv_i,const IntID& fid){fprintf_s(mFile,"connectAttr \"");fid.write(mFile);fprintf_s(mFile,"\" \"%s.nuv[%i].fid\";\n",mName.c_str(),nuv_i);}
	/*Vertex Id of new UV*/
	void setVertexId(size_t nuv_i,int vid){if(vid == 0) return; fprintf_s(mFile, "setAttr \".nuv[%i].vid\" %i;\n", nuv_i,vid);}
	/*Vertex Id of new UV*/
	void setVertexId(size_t nuv_i,const IntID& vid){fprintf_s(mFile,"connectAttr \"");vid.write(mFile);fprintf_s(mFile,"\" \"%s.nuv[%i].vid\";\n",mName.c_str(),nuv_i);}
	/*Tweak value of U coordinate*/
	void setNewUValue(size_t nuv_i,float nu){if(nu == 0.0) return; fprintf_s(mFile, "setAttr \".nuv[%i].nu\" %f;\n", nuv_i,nu);}
	/*Tweak value of U coordinate*/
	void setNewUValue(size_t nuv_i,const FloatID& nu){fprintf_s(mFile,"connectAttr \"");nu.write(mFile);fprintf_s(mFile,"\" \"%s.nuv[%i].nu\";\n",mName.c_str(),nuv_i);}
	/*Tweak value of V coordinate*/
	void setNewVValue(size_t nuv_i,float nv){if(nv == 0.0) return; fprintf_s(mFile, "setAttr \".nuv[%i].nv\" %f;\n", nuv_i,nv);}
	/*Tweak value of V coordinate*/
	void setNewVValue(size_t nuv_i,const FloatID& nv){fprintf_s(mFile,"connectAttr \"");nv.write(mFile);fprintf_s(mFile,"\" \"%s.nuv[%i].nv\";\n",mName.c_str(),nuv_i);}
	/*The name of the map set to work on*/
	void setUvSetName(const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs\" -type \"string\" ");uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the map set to work on*/
	void setUvSetName(const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*
	Array (multi-attribute) of polygon uv displacements.
	There is one for each original UV of the polygon.
	*/
	const Float2ID& getUvTweak(size_t uvtk_i){char buffer[4096];sprintf_s (buffer, "%s.uvtk[%i]",mName.c_str(),uvtk_i);return (const char*)buffer;}
	/*Tweak value of U coordinate*/
	const FloatID& getUvTweakU(size_t uvtk_i){char buffer[4096];sprintf_s (buffer, "%s.uvtk[%i].tu",mName.c_str(),uvtk_i);return (const char*)buffer;}
	/*Tweak value of V coordinate*/
	const FloatID& getUvTweakV(size_t uvtk_i){char buffer[4096];sprintf_s (buffer, "%s.uvtk[%i].tv",mName.c_str(),uvtk_i);return (const char*)buffer;}
	/*
	Array (multi-attribute) of polygon uv points.
	This attribute is used when new UVs are added to the polygon.
	*/
	const NewUVID& getNewUV(size_t nuv_i){char buffer[4096];sprintf_s (buffer, "%s.nuv[%i]",mName.c_str(),nuv_i);return (const char*)buffer;}
	/*Face Id of new UV*/
	const IntID& getFaceId(size_t nuv_i){char buffer[4096];sprintf_s (buffer, "%s.nuv[%i].fid",mName.c_str(),nuv_i);return (const char*)buffer;}
	/*Vertex Id of new UV*/
	const IntID& getVertexId(size_t nuv_i){char buffer[4096];sprintf_s (buffer, "%s.nuv[%i].vid",mName.c_str(),nuv_i);return (const char*)buffer;}
	/*Tweak value of U coordinate*/
	const FloatID& getNewUValue(size_t nuv_i){char buffer[4096];sprintf_s (buffer, "%s.nuv[%i].nu",mName.c_str(),nuv_i);return (const char*)buffer;}
	/*Tweak value of V coordinate*/
	const FloatID& getNewVValue(size_t nuv_i){char buffer[4096];sprintf_s (buffer, "%s.nuv[%i].nv",mName.c_str(),nuv_i);return (const char*)buffer;}
	/*The name of the map set to work on*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
protected:
	PolyTweakUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYTWEAKUV_H__
