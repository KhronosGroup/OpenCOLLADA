/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOTH_H__
#define __MayaDM_CLOTH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Cloth</b> texture simulates a woven fabric.  You can control
  the color and width of the threads, the size of the gap between them,
  and the randomness of the weaving.
 <p/>
  Aside from the attributes listed here, Checker inherits many other
  attributes from its parent node, <a href="texture2d.html">Texture2d</a>.
  <p/>
  In the table below, important attributes have their names listed
  in <b>bold</b> in the description column.
*/
class Cloth : public Texture2d
{
public:
public:
	Cloth(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "cloth"){}
	virtual ~Cloth(){}
	/*
	<b>Gap Color</b> is the color of the spaces between the
	threads of the cloth.
	*/
	void setGapColor(const float3& gc){if(gc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".gc\" -type \"float3\" ");gc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Gap Color</b> is the color of the spaces between the
	threads of the cloth.
	*/
	void setGapColor(const Float3ID& gc){fprintf_s(mFile,"connectAttr \"");gc.write(mFile);fprintf_s(mFile,"\" \"%s.gc\";\n",mName.c_str());}
	/*The red component of Gap Color*/
	void setGapColorR(float gcr){if(gcr == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcr\" %f;\n", gcr);}
	/*The red component of Gap Color*/
	void setGapColorR(const FloatID& gcr){fprintf_s(mFile,"connectAttr \"");gcr.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcr\";\n",mName.c_str());}
	/*The green component of Gap Color*/
	void setGapColorG(float gcg){if(gcg == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcg\" %f;\n", gcg);}
	/*The green component of Gap Color*/
	void setGapColorG(const FloatID& gcg){fprintf_s(mFile,"connectAttr \"");gcg.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcg\";\n",mName.c_str());}
	/*The blue component of Gap Color*/
	void setGapColorB(float gcb){if(gcb == 0.0) return; fprintf_s(mFile, "setAttr \".gc.gcb\" %f;\n", gcb);}
	/*The blue component of Gap Color*/
	void setGapColorB(const FloatID& gcb){fprintf_s(mFile,"connectAttr \"");gcb.write(mFile);fprintf_s(mFile,"\" \"%s.gc.gcb\";\n",mName.c_str());}
	/*
	<b>U Color</b> is the color of the threads that run in
	the texture's "U" direction.
	*/
	void setUColor(const float3& uc){if(uc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".uc\" -type \"float3\" ");uc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>U Color</b> is the color of the threads that run in
	the texture's "U" direction.
	*/
	void setUColor(const Float3ID& uc){fprintf_s(mFile,"connectAttr \"");uc.write(mFile);fprintf_s(mFile,"\" \"%s.uc\";\n",mName.c_str());}
	/*The red component of  U Color*/
	void setUColorR(float ucr){if(ucr == 0.0) return; fprintf_s(mFile, "setAttr \".uc.ucr\" %f;\n", ucr);}
	/*The red component of  U Color*/
	void setUColorR(const FloatID& ucr){fprintf_s(mFile,"connectAttr \"");ucr.write(mFile);fprintf_s(mFile,"\" \"%s.uc.ucr\";\n",mName.c_str());}
	/*The green component of  U Color*/
	void setUColorG(float ucg){if(ucg == 0.0) return; fprintf_s(mFile, "setAttr \".uc.ucg\" %f;\n", ucg);}
	/*The green component of  U Color*/
	void setUColorG(const FloatID& ucg){fprintf_s(mFile,"connectAttr \"");ucg.write(mFile);fprintf_s(mFile,"\" \"%s.uc.ucg\";\n",mName.c_str());}
	/*The blue component of  U Color*/
	void setUColorB(float ucb){if(ucb == 0.0) return; fprintf_s(mFile, "setAttr \".uc.ucb\" %f;\n", ucb);}
	/*The blue component of  U Color*/
	void setUColorB(const FloatID& ucb){fprintf_s(mFile,"connectAttr \"");ucb.write(mFile);fprintf_s(mFile,"\" \"%s.uc.ucb\";\n",mName.c_str());}
	/*
	<b>V Color</b> is the color of the threads that run in
	the texture's "V" direction.
	*/
	void setVColor(const float3& vc){if(vc == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".vc\" -type \"float3\" ");vc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>V Color</b> is the color of the threads that run in
	the texture's "V" direction.
	*/
	void setVColor(const Float3ID& vc){fprintf_s(mFile,"connectAttr \"");vc.write(mFile);fprintf_s(mFile,"\" \"%s.vc\";\n",mName.c_str());}
	/*The red component of  V Color*/
	void setVColorR(float vcr){if(vcr == 0.0) return; fprintf_s(mFile, "setAttr \".vc.vcr\" %f;\n", vcr);}
	/*The red component of  V Color*/
	void setVColorR(const FloatID& vcr){fprintf_s(mFile,"connectAttr \"");vcr.write(mFile);fprintf_s(mFile,"\" \"%s.vc.vcr\";\n",mName.c_str());}
	/*The green component of  V Color*/
	void setVColorG(float vcg){if(vcg == 0.0) return; fprintf_s(mFile, "setAttr \".vc.vcg\" %f;\n", vcg);}
	/*The green component of  V Color*/
	void setVColorG(const FloatID& vcg){fprintf_s(mFile,"connectAttr \"");vcg.write(mFile);fprintf_s(mFile,"\" \"%s.vc.vcg\";\n",mName.c_str());}
	/*The blue component of  V Color*/
	void setVColorB(float vcb){if(vcb == 0.0) return; fprintf_s(mFile, "setAttr \".vc.vcb\" %f;\n", vcb);}
	/*The blue component of  V Color*/
	void setVColorB(const FloatID& vcb){fprintf_s(mFile,"connectAttr \"");vcb.write(mFile);fprintf_s(mFile,"\" \"%s.vc.vcb\";\n",mName.c_str());}
	/*
	<b>U Width</b> is the width (thickness) of the
	threads that run in the texture's "U" direction.
	*/
	void setUWidth(float uwi){if(uwi == 0.75) return; fprintf_s(mFile, "setAttr \".uwi\" %f;\n", uwi);}
	/*
	<b>U Width</b> is the width (thickness) of the
	threads that run in the texture's "U" direction.
	*/
	void setUWidth(const FloatID& uwi){fprintf_s(mFile,"connectAttr \"");uwi.write(mFile);fprintf_s(mFile,"\" \"%s.uwi\";\n",mName.c_str());}
	/*
	<b>V Width</b> is the width (thickness) of the
	threads that run in the texture's "V" direction.
	*/
	void setVWidth(float vwi){if(vwi == 0.75) return; fprintf_s(mFile, "setAttr \".vwi\" %f;\n", vwi);}
	/*
	<b>V Width</b> is the width (thickness) of the
	threads that run in the texture's "V" direction.
	*/
	void setVWidth(const FloatID& vwi){fprintf_s(mFile,"connectAttr \"");vwi.write(mFile);fprintf_s(mFile,"\" \"%s.vwi\";\n",mName.c_str());}
	/*
	<b>U Wave</b> controls how much the threads in the texture's
	"U" direction appear to bend to go around the threads in the
	"V" direction.
	<p/>
	Increasing this value gives the cloth a rougher, more 3-dimensional
	appearance.
	*/
	void setUWave(float uwa){if(uwa == 0.0) return; fprintf_s(mFile, "setAttr \".uwa\" %f;\n", uwa);}
	/*
	<b>U Wave</b> controls how much the threads in the texture's
	"U" direction appear to bend to go around the threads in the
	"V" direction.
	<p/>
	Increasing this value gives the cloth a rougher, more 3-dimensional
	appearance.
	*/
	void setUWave(const FloatID& uwa){fprintf_s(mFile,"connectAttr \"");uwa.write(mFile);fprintf_s(mFile,"\" \"%s.uwa\";\n",mName.c_str());}
	/*
	<b>V Wave</b> controls how much the threads in the texture's
	"V" direction appear to bend to go around the threads in the
	"U" direction.
	<p/>
	Increasing this value gives the cloth a rougher, more 3-dimensional
	appearance.
	*/
	void setVWave(float vwa){if(vwa == 0.0) return; fprintf_s(mFile, "setAttr \".vwa\" %f;\n", vwa);}
	/*
	<b>V Wave</b> controls how much the threads in the texture's
	"V" direction appear to bend to go around the threads in the
	"U" direction.
	<p/>
	Increasing this value gives the cloth a rougher, more 3-dimensional
	appearance.
	*/
	void setVWave(const FloatID& vwa){fprintf_s(mFile,"connectAttr \"");vwa.write(mFile);fprintf_s(mFile,"\" \"%s.vwa\";\n",mName.c_str());}
	/*
	<b>Randomness</b> can be used to smear the pattern in both
	the "U" and "V" directions.  This can be used to create a
	more irregular, naturalistic looking cloth.
	<p/>
	A small amount of Randomness can prevent aliasing and
	moiré patterns that can occur when a very fine cloth
	texture is being used.
	*/
	void setRandomness(float r){if(r == 0.0) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*
	<b>Randomness</b> can be used to smear the pattern in both
	the "U" and "V" directions.  This can be used to create a
	more irregular, naturalistic looking cloth.
	<p/>
	A small amount of Randomness can prevent aliasing and
	moiré patterns that can occur when a very fine cloth
	texture is being used.
	*/
	void setRandomness(const FloatID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*
	<b>Width Spread</b> randomly makes some threads narrower
	than the value specified by the U Width and V Width attributes.
	The widths of the threads will vary along their lengths.
	<p/>
	This attribute specifies the maximum amount that can be
	subtracted from a thread width.
	*/
	void setWidthSpread(float ws){if(ws == 0.0) return; fprintf_s(mFile, "setAttr \".ws\" %f;\n", ws);}
	/*
	<b>Width Spread</b> randomly makes some threads narrower
	than the value specified by the U Width and V Width attributes.
	The widths of the threads will vary along their lengths.
	<p/>
	This attribute specifies the maximum amount that can be
	subtracted from a thread width.
	*/
	void setWidthSpread(const FloatID& ws){fprintf_s(mFile,"connectAttr \"");ws.write(mFile);fprintf_s(mFile,"\" \"%s.ws\";\n",mName.c_str());}
	/*
	<b>Brightness Spread</b> randomly makes some threads darker
	than the value specified by the U Color and V Color attributes.
	The brightness of the threads will vary along their lengths.
	<p/>
	This attribute specifies the maximum amount that can be
	subtracted from the brightness of the threads.
	*/
	void setBrightSpread(float bs){if(bs == 0.0) return; fprintf_s(mFile, "setAttr \".bs\" %f;\n", bs);}
	/*
	<b>Brightness Spread</b> randomly makes some threads darker
	than the value specified by the U Color and V Color attributes.
	The brightness of the threads will vary along their lengths.
	<p/>
	This attribute specifies the maximum amount that can be
	subtracted from the brightness of the threads.
	*/
	void setBrightSpread(const FloatID& bs){fprintf_s(mFile,"connectAttr \"");bs.write(mFile);fprintf_s(mFile,"\" \"%s.bs\";\n",mName.c_str());}
	/*
	<b>Gap Color</b> is the color of the spaces between the
	threads of the cloth.
	*/
	Float3ID getGapColor(){char buffer[4096];sprintf_s (buffer, "%s.gc",mName.c_str());return (const char*)buffer;}
	/*The red component of Gap Color*/
	FloatID getGapColorR(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcr",mName.c_str());return (const char*)buffer;}
	/*The green component of Gap Color*/
	FloatID getGapColorG(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcg",mName.c_str());return (const char*)buffer;}
	/*The blue component of Gap Color*/
	FloatID getGapColorB(){char buffer[4096];sprintf_s (buffer, "%s.gc.gcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>U Color</b> is the color of the threads that run in
	the texture's "U" direction.
	*/
	Float3ID getUColor(){char buffer[4096];sprintf_s (buffer, "%s.uc",mName.c_str());return (const char*)buffer;}
	/*The red component of  U Color*/
	FloatID getUColorR(){char buffer[4096];sprintf_s (buffer, "%s.uc.ucr",mName.c_str());return (const char*)buffer;}
	/*The green component of  U Color*/
	FloatID getUColorG(){char buffer[4096];sprintf_s (buffer, "%s.uc.ucg",mName.c_str());return (const char*)buffer;}
	/*The blue component of  U Color*/
	FloatID getUColorB(){char buffer[4096];sprintf_s (buffer, "%s.uc.ucb",mName.c_str());return (const char*)buffer;}
	/*
	<b>V Color</b> is the color of the threads that run in
	the texture's "V" direction.
	*/
	Float3ID getVColor(){char buffer[4096];sprintf_s (buffer, "%s.vc",mName.c_str());return (const char*)buffer;}
	/*The red component of  V Color*/
	FloatID getVColorR(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcr",mName.c_str());return (const char*)buffer;}
	/*The green component of  V Color*/
	FloatID getVColorG(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcg",mName.c_str());return (const char*)buffer;}
	/*The blue component of  V Color*/
	FloatID getVColorB(){char buffer[4096];sprintf_s (buffer, "%s.vc.vcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>U Width</b> is the width (thickness) of the
	threads that run in the texture's "U" direction.
	*/
	FloatID getUWidth(){char buffer[4096];sprintf_s (buffer, "%s.uwi",mName.c_str());return (const char*)buffer;}
	/*
	<b>V Width</b> is the width (thickness) of the
	threads that run in the texture's "V" direction.
	*/
	FloatID getVWidth(){char buffer[4096];sprintf_s (buffer, "%s.vwi",mName.c_str());return (const char*)buffer;}
	/*
	<b>U Wave</b> controls how much the threads in the texture's
	"U" direction appear to bend to go around the threads in the
	"V" direction.
	<p/>
	Increasing this value gives the cloth a rougher, more 3-dimensional
	appearance.
	*/
	FloatID getUWave(){char buffer[4096];sprintf_s (buffer, "%s.uwa",mName.c_str());return (const char*)buffer;}
	/*
	<b>V Wave</b> controls how much the threads in the texture's
	"V" direction appear to bend to go around the threads in the
	"U" direction.
	<p/>
	Increasing this value gives the cloth a rougher, more 3-dimensional
	appearance.
	*/
	FloatID getVWave(){char buffer[4096];sprintf_s (buffer, "%s.vwa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Randomness</b> can be used to smear the pattern in both
	the "U" and "V" directions.  This can be used to create a
	more irregular, naturalistic looking cloth.
	<p/>
	A small amount of Randomness can prevent aliasing and
	moiré patterns that can occur when a very fine cloth
	texture is being used.
	*/
	FloatID getRandomness(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*
	<b>Width Spread</b> randomly makes some threads narrower
	than the value specified by the U Width and V Width attributes.
	The widths of the threads will vary along their lengths.
	<p/>
	This attribute specifies the maximum amount that can be
	subtracted from a thread width.
	*/
	FloatID getWidthSpread(){char buffer[4096];sprintf_s (buffer, "%s.ws",mName.c_str());return (const char*)buffer;}
	/*
	<b>Brightness Spread</b> randomly makes some threads darker
	than the value specified by the U Color and V Color attributes.
	The brightness of the threads will vary along their lengths.
	<p/>
	This attribute specifies the maximum amount that can be
	subtracted from the brightness of the threads.
	*/
	FloatID getBrightSpread(){char buffer[4096];sprintf_s (buffer, "%s.bs",mName.c_str());return (const char*)buffer;}
protected:
	Cloth(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLOTH_H__
