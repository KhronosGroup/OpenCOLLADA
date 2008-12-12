/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GRID_H__
#define __MayaDM_GRID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Grid</b> texture simply creates a regular grid of horizontal
 and vertical lines.
 <p/>
  Aside from the attributes listed here, Grid inherits many other
  attributes from its parent node, <a href="texture2d.html">Texture2d</a>.
  <p/>
 In the table below, important attributes are shown in <b>bold</b>
 in the description column.
*/
class Grid : public Texture2d
{
public:
public:
	Grid(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "grid"){}
	virtual ~Grid(){}
	/*
	<b>Filler Color</b> controls the color of the spaces
	between the horizontal and vertical lines of the grid.
	*/
	void setFillerColor(const float3& fc){if(fc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".fc\" -type \"float3\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Filler Color</b> controls the color of the spaces
	between the horizontal and vertical lines of the grid.
	*/
	void setFillerColor(const Float3ID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc\";\n",mName.c_str());}
	/*Filler Color red value*/
	void setFillerColorR(float fcr){if(fcr == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcr\" %f;\n", fcr);}
	/*Filler Color red value*/
	void setFillerColorR(const FloatID& fcr){fprintf_s(mFile,"connectAttr \"");fcr.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcr\";\n",mName.c_str());}
	/*Filler Color green value*/
	void setFillerColorG(float fcg){if(fcg == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcg\" %f;\n", fcg);}
	/*Filler Color green value*/
	void setFillerColorG(const FloatID& fcg){fprintf_s(mFile,"connectAttr \"");fcg.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcg\";\n",mName.c_str());}
	/*Filler Color blue value*/
	void setFillerColorB(float fcb){if(fcb == 0.0) return; fprintf_s(mFile, "setAttr \".fc.fcb\" %f;\n", fcb);}
	/*Filler Color blue value*/
	void setFillerColorB(const FloatID& fcb){fprintf_s(mFile,"connectAttr \"");fcb.write(mFile);fprintf_s(mFile,"\" \"%s.fc.fcb\";\n",mName.c_str());}
	/*
	<b>Line Color</b> controls the color of the horizontal
	and vertical grid lines.
	*/
	void setLineColor(const float3& lc){if(lc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".lc\" -type \"float3\" ");lc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Line Color</b> controls the color of the horizontal
	and vertical grid lines.
	*/
	void setLineColor(const Float3ID& lc){fprintf_s(mFile,"connectAttr \"");lc.write(mFile);fprintf_s(mFile,"\" \"%s.lc\";\n",mName.c_str());}
	/*Line Color red value*/
	void setLineColorR(float lcr){if(lcr == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lcr\" %f;\n", lcr);}
	/*Line Color red value*/
	void setLineColorR(const FloatID& lcr){fprintf_s(mFile,"connectAttr \"");lcr.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lcr\";\n",mName.c_str());}
	/*Line Color green value*/
	void setLineColorG(float lcg){if(lcg == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lcg\" %f;\n", lcg);}
	/*Line Color green value*/
	void setLineColorG(const FloatID& lcg){fprintf_s(mFile,"connectAttr \"");lcg.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lcg\";\n",mName.c_str());}
	/*Line Color blue value*/
	void setLineColorB(float lcb){if(lcb == 0.0) return; fprintf_s(mFile, "setAttr \".lc.lcb\" %f;\n", lcb);}
	/*Line Color blue value*/
	void setLineColorB(const FloatID& lcb){fprintf_s(mFile,"connectAttr \"");lcb.write(mFile);fprintf_s(mFile,"\" \"%s.lc.lcb\";\n",mName.c_str());}
	/*
	<b>Contrast</b> is used to control the contrast between
	the Line Color and the Filler Color.  When set to 1.0 (the
	default) the two colors do not affect each other at all.
	As contrast is decreased, each color starts to blend with
	other.  When contrast is 0, there is no grid at all, but just
	a flat texture consisting of the average of the two input
	colors.
	<p/>
	Use this attribute to control the sharpness of the ridges
	when using a Grid Texture as a bump map.
	*/
	void setContrast(float c){if(c == 1.0) return; fprintf_s(mFile, "setAttr \".c\" %f;\n", c);}
	/*
	<b>Contrast</b> is used to control the contrast between
	the Line Color and the Filler Color.  When set to 1.0 (the
	default) the two colors do not affect each other at all.
	As contrast is decreased, each color starts to blend with
	other.  When contrast is 0, there is no grid at all, but just
	a flat texture consisting of the average of the two input
	colors.
	<p/>
	Use this attribute to control the sharpness of the ridges
	when using a Grid Texture as a bump map.
	*/
	void setContrast(const FloatID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*
	<b>U Width</b> controls the width of the grid lines
	that run in the surface's "U" direction.
	*/
	void setUWidth(float uw){if(uw == 0.1) return; fprintf_s(mFile, "setAttr \".uw\" %f;\n", uw);}
	/*
	<b>U Width</b> controls the width of the grid lines
	that run in the surface's "U" direction.
	*/
	void setUWidth(const FloatID& uw){fprintf_s(mFile,"connectAttr \"");uw.write(mFile);fprintf_s(mFile,"\" \"%s.uw\";\n",mName.c_str());}
	/*
	<b>V Width</b> controls the width of the grid lines
	that run in the surface's "V" direction.
	*/
	void setVWidth(float vw){if(vw == 0.1) return; fprintf_s(mFile, "setAttr \".vw\" %f;\n", vw);}
	/*
	<b>V Width</b> controls the width of the grid lines
	that run in the surface's "V" direction.
	*/
	void setVWidth(const FloatID& vw){fprintf_s(mFile,"connectAttr \"");vw.write(mFile);fprintf_s(mFile,"\" \"%s.vw\";\n",mName.c_str());}
	/*
	<b>Filler Color</b> controls the color of the spaces
	between the horizontal and vertical lines of the grid.
	*/
	Float3ID getFillerColor(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*Filler Color red value*/
	FloatID getFillerColorR(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcr",mName.c_str());return (const char*)buffer;}
	/*Filler Color green value*/
	FloatID getFillerColorG(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcg",mName.c_str());return (const char*)buffer;}
	/*Filler Color blue value*/
	FloatID getFillerColorB(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Line Color</b> controls the color of the horizontal
	and vertical grid lines.
	*/
	Float3ID getLineColor(){char buffer[4096];sprintf_s (buffer, "%s.lc",mName.c_str());return (const char*)buffer;}
	/*Line Color red value*/
	FloatID getLineColorR(){char buffer[4096];sprintf_s (buffer, "%s.lc.lcr",mName.c_str());return (const char*)buffer;}
	/*Line Color green value*/
	FloatID getLineColorG(){char buffer[4096];sprintf_s (buffer, "%s.lc.lcg",mName.c_str());return (const char*)buffer;}
	/*Line Color blue value*/
	FloatID getLineColorB(){char buffer[4096];sprintf_s (buffer, "%s.lc.lcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Contrast</b> is used to control the contrast between
	the Line Color and the Filler Color.  When set to 1.0 (the
	default) the two colors do not affect each other at all.
	As contrast is decreased, each color starts to blend with
	other.  When contrast is 0, there is no grid at all, but just
	a flat texture consisting of the average of the two input
	colors.
	<p/>
	Use this attribute to control the sharpness of the ridges
	when using a Grid Texture as a bump map.
	*/
	FloatID getContrast(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*
	<b>U Width</b> controls the width of the grid lines
	that run in the surface's "U" direction.
	*/
	FloatID getUWidth(){char buffer[4096];sprintf_s (buffer, "%s.uw",mName.c_str());return (const char*)buffer;}
	/*
	<b>V Width</b> controls the width of the grid lines
	that run in the surface's "V" direction.
	*/
	FloatID getVWidth(){char buffer[4096];sprintf_s (buffer, "%s.vw",mName.c_str());return (const char*)buffer;}
protected:
	Grid(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GRID_H__
