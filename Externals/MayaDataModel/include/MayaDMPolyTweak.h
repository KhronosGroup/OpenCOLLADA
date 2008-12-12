/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTWEAK_H__
#define __MayaDM_POLYTWEAK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*Node to edit vertex positions.<p/>*/
class PolyTweak : public PolyModifier
{
public:
public:
	PolyTweak(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyTweak"){}
	virtual ~PolyTweak(){}
	/*
	Array (multi-attribute) of polygon displacements. There is one
	for each vertex of the polygon.
	*/
	void setTweak(size_t tk_i,const float3& tk){if(tk == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tk[%i]\" -type \"float3\" ",tk_i);tk.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of polygon displacements. There is one
	for each vertex of the polygon.
	*/
	void setTweak(size_t tk_start,size_t tk_end,float* tk){fprintf_s(mFile,"setAttr \".tk[%i:%i]\" ", tk_start,tk_end);size_t size = (tk_end-tk_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",tk[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of polygon displacements. There is one
	for each vertex of the polygon.
	*/
	void setTweak(size_t tk_i,const Float3ID& tk){fprintf_s(mFile,"connectAttr \"");tk.write(mFile);fprintf_s(mFile,"\" \"%s.tk[%i]\";\n",mName.c_str(),tk_i);}
	/*X tweak of the vertex.*/
	void setTweakX(size_t tk_i,float tx){if(tx == 0.0) return; fprintf_s(mFile, "setAttr \".tk[%i].tx\" %f;\n", tk_i,tx);}
	/*X tweak of the vertex.*/
	void setTweakX(size_t tk_i,const FloatID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tk[%i].tx\";\n",mName.c_str(),tk_i);}
	/*Y tweak of the vertex.*/
	void setTweakY(size_t tk_i,float ty){if(ty == 0.0) return; fprintf_s(mFile, "setAttr \".tk[%i].ty\" %f;\n", tk_i,ty);}
	/*Y tweak of the vertex.*/
	void setTweakY(size_t tk_i,const FloatID& ty){fprintf_s(mFile,"connectAttr \"");ty.write(mFile);fprintf_s(mFile,"\" \"%s.tk[%i].ty\";\n",mName.c_str(),tk_i);}
	/*Z tweak of the vertex.*/
	void setTweakZ(size_t tk_i,float tz){if(tz == 0.0) return; fprintf_s(mFile, "setAttr \".tk[%i].tz\" %f;\n", tk_i,tz);}
	/*Z tweak of the vertex.*/
	void setTweakZ(size_t tk_i,const FloatID& tz){fprintf_s(mFile,"connectAttr \"");tz.write(mFile);fprintf_s(mFile,"\" \"%s.tk[%i].tz\";\n",mName.c_str(),tk_i);}
	/*
	Array (multi-attribute) of polygon displacements. There is one
	for each vertex of the polygon.
	*/
	const Float3ID& getTweak(size_t tk_i){char buffer[4096];sprintf_s (buffer, "%s.tk[%i]",mName.c_str(),tk_i);return (const char*)buffer;}
	/*X tweak of the vertex.*/
	const FloatID& getTweakX(size_t tk_i){char buffer[4096];sprintf_s (buffer, "%s.tk[%i].tx",mName.c_str(),tk_i);return (const char*)buffer;}
	/*Y tweak of the vertex.*/
	const FloatID& getTweakY(size_t tk_i){char buffer[4096];sprintf_s (buffer, "%s.tk[%i].ty",mName.c_str(),tk_i);return (const char*)buffer;}
	/*Z tweak of the vertex.*/
	const FloatID& getTweakZ(size_t tk_i){char buffer[4096];sprintf_s (buffer, "%s.tk[%i].tz",mName.c_str(),tk_i);return (const char*)buffer;}
protected:
	PolyTweak(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYTWEAK_H__
