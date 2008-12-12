/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDTWEAK_H__
#define __MayaDM_SUBDTWEAK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifier.h"
namespace MayaDM
{
/*Node to edit subdiv vertex positions in history.<p/>*/
class SubdTweak : public SubdModifier
{
public:
public:
	SubdTweak(FILE* file,const std::string& name,const std::string& parent=""):SubdModifier(file, name, parent, "subdTweak"){}
	virtual ~SubdTweak(){}
	/*
	Array (multi-attribute) of subdiv displacements. There is one
	for each vertex of the subdiv surface that has been tweaked.
	*/
	void setTweak(size_t tk_i,const double3& tk){if(tk == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tk[%i]\" -type \"double3\" ",tk_i);tk.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of subdiv displacements. There is one
	for each vertex of the subdiv surface that has been tweaked.
	*/
	void setTweak(size_t tk_start,size_t tk_end,double* tk){fprintf_s(mFile,"setAttr \".tk[%i:%i]\" ", tk_start,tk_end);size_t size = (tk_end-tk_start)*3+3;for(size_t i=0;i<size;++i){fprintf_s(mFile,"%f",tk[i]);if(i+1<size) fprintf_s(mFile," ");}fprintf_s(mFile,";\n");}
	/*
	Array (multi-attribute) of subdiv displacements. There is one
	for each vertex of the subdiv surface that has been tweaked.
	*/
	void setTweak(size_t tk_i,const Double3ID& tk){fprintf_s(mFile,"connectAttr \"");tk.write(mFile);fprintf_s(mFile,"\" \"%s.tk[%i]\";\n",mName.c_str(),tk_i);}
	/*X tweak of the vertex.*/
	void setTweakX(size_t tk_i,double tx){if(tx == 0.0) return; fprintf_s(mFile, "setAttr \".tk[%i].tx\" %f;\n", tk_i,tx);}
	/*X tweak of the vertex.*/
	void setTweakX(size_t tk_i,const DoubleID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tk[%i].tx\";\n",mName.c_str(),tk_i);}
	/*Y tweak of the vertex.*/
	void setTweakY(size_t tk_i,double ty){if(ty == 0.0) return; fprintf_s(mFile, "setAttr \".tk[%i].ty\" %f;\n", tk_i,ty);}
	/*Y tweak of the vertex.*/
	void setTweakY(size_t tk_i,const DoubleID& ty){fprintf_s(mFile,"connectAttr \"");ty.write(mFile);fprintf_s(mFile,"\" \"%s.tk[%i].ty\";\n",mName.c_str(),tk_i);}
	/*Z tweak of the vertex.*/
	void setTweakZ(size_t tk_i,double tz){if(tz == 0.0) return; fprintf_s(mFile, "setAttr \".tk[%i].tz\" %f;\n", tk_i,tz);}
	/*Z tweak of the vertex.*/
	void setTweakZ(size_t tk_i,const DoubleID& tz){fprintf_s(mFile,"connectAttr \"");tz.write(mFile);fprintf_s(mFile,"\" \"%s.tk[%i].tz\";\n",mName.c_str(),tk_i);}
	/*
	This is a mapping of single 32 bit indices to 64 bit values.
	Currently only used where a 64 bit value is
	needed to uniquely specify a subdiv vertex.
	*/
	void setMap64BitIndices(const LongArrayID& map){fprintf_s(mFile,"connectAttr \"");map.write(mFile);fprintf_s(mFile,"\" \"%s.map\";\n",mName.c_str());}
	/*
	Array (multi-attribute) of subdiv displacements. There is one
	for each vertex of the subdiv surface that has been tweaked.
	*/
	const Double3ID& getTweak(size_t tk_i){char buffer[4096];sprintf_s (buffer, "%s.tk[%i]",mName.c_str(),tk_i);return (const char*)buffer;}
	/*X tweak of the vertex.*/
	const DoubleID& getTweakX(size_t tk_i){char buffer[4096];sprintf_s (buffer, "%s.tk[%i].tx",mName.c_str(),tk_i);return (const char*)buffer;}
	/*Y tweak of the vertex.*/
	const DoubleID& getTweakY(size_t tk_i){char buffer[4096];sprintf_s (buffer, "%s.tk[%i].ty",mName.c_str(),tk_i);return (const char*)buffer;}
	/*Z tweak of the vertex.*/
	const DoubleID& getTweakZ(size_t tk_i){char buffer[4096];sprintf_s (buffer, "%s.tk[%i].tz",mName.c_str(),tk_i);return (const char*)buffer;}
	/*
	This is a mapping of single 32 bit indices to 64 bit values.
	Currently only used where a 64 bit value is
	needed to uniquely specify a subdiv vertex.
	*/
	LongArrayID getMap64BitIndices(){char buffer[4096];sprintf_s (buffer, "%s.map",mName.c_str());return (const char*)buffer;}
protected:
	SubdTweak(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDTWEAK_H__
