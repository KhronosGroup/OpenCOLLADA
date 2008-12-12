/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDTWEAKUV_H__
#define __MayaDM_SUBDTWEAKUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifier.h"
namespace MayaDM
{
/*Node to edit UV coordinates of polygonal objects.<p/>*/
class SubdTweakUV : public SubdModifier
{
public:
public:
	SubdTweakUV(FILE* file,const std::string& name,const std::string& parent=""):SubdModifier(file, name, parent, "subdTweakUV"){}
	virtual ~SubdTweakUV(){}
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
	Array (multi-attribute) of polygon uv displacements.
	There is one for each original UV of the polygon.
	*/
	const Float2ID& getUvTweak(size_t uvtk_i){char buffer[4096];sprintf_s (buffer, "%s.uvtk[%i]",mName.c_str(),uvtk_i);return (const char*)buffer;}
	/*Tweak value of U coordinate*/
	const FloatID& getUvTweakU(size_t uvtk_i){char buffer[4096];sprintf_s (buffer, "%s.uvtk[%i].tu",mName.c_str(),uvtk_i);return (const char*)buffer;}
	/*Tweak value of V coordinate*/
	const FloatID& getUvTweakV(size_t uvtk_i){char buffer[4096];sprintf_s (buffer, "%s.uvtk[%i].tv",mName.c_str(),uvtk_i);return (const char*)buffer;}
protected:
	SubdTweakUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDTWEAKUV_H__
