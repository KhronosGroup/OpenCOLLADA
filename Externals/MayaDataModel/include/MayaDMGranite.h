/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GRANITE_H__
#define __MayaDM_GRANITE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
the asm version os probably now slower than the revised C version -- so lets
 eliminate it... -- I.A.


 The <b>Granite</b> texture is used to create the appearance of
 granite or other granite-like stone.  The texture simulates a
 material comprising three different minerals (colors) suspended
 in a medium (filler).
<p/>
 Used as a bump map, the Granite texture can produce a rough, even,
 sandpaper-like texture.  If used as both bump and color, it can be
 used to look like the inside surface of a rock that has been
 broken open.
<p/>
 <ul><b>Tip:</b><br/>
 Granite is an expensive texture to calculate.  To save time on
 a final render, convert your Granite texture to a File texture after you
 have set it up the way you like it.
</ul><p/>
 Aside from the attributes listed here, Granite inherits many
 other attributes from its parent, <a href="texture3d.html">
 Texture3d</a>
<p/>
 In the table below, important attributes are listed with their
 names shown in <b>bold</b> in the description column.
*/
class Granite : public Texture3d
{
public:
public:
	Granite(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "granite"){}
	virtual ~Granite(){}
	/*The current reference sample point that has to be shaded*/
	void setRefPointObj(const Float3ID& rpo){fprintf_s(mFile,"connectAttr \"");rpo.write(mFile);fprintf_s(mFile,"\" \"%s.rpo\";\n",mName.c_str());}
	/*The x component of the current reference sample position*/
	void setRefPointObjX(const FloatID& rox){fprintf_s(mFile,"connectAttr \"");rox.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.rox\";\n",mName.c_str());}
	/*The y component of the current reference sample position*/
	void setRefPointObjY(const FloatID& roy){fprintf_s(mFile,"connectAttr \"");roy.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.roy\";\n",mName.c_str());}
	/*The z component of the current reference sample position*/
	void setRefPointObjZ(const FloatID& roz){fprintf_s(mFile,"connectAttr \"");roz.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.roz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*
	<b>Color1</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	void setColor1(const float3& c1){if(c1 == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c1\" -type \"float3\" ");c1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color1</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	void setColor1(const Float3ID& c1){fprintf_s(mFile,"connectAttr \"");c1.write(mFile);fprintf_s(mFile,"\" \"%s.c1\";\n",mName.c_str());}
	/*The red value of Color 1*/
	void setColor1R(float c1r){if(c1r == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1r\" %f;\n", c1r);}
	/*The red value of Color 1*/
	void setColor1R(const FloatID& c1r){fprintf_s(mFile,"connectAttr \"");c1r.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1r\";\n",mName.c_str());}
	/*The green value of Color 1*/
	void setColor1G(float c1g){if(c1g == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1g\" %f;\n", c1g);}
	/*The green value of Color 1*/
	void setColor1G(const FloatID& c1g){fprintf_s(mFile,"connectAttr \"");c1g.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1g\";\n",mName.c_str());}
	/*The blue value of Color 1*/
	void setColor1B(float c1b){if(c1b == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1b\" %f;\n", c1b);}
	/*The blue value of Color 1*/
	void setColor1B(const FloatID& c1b){fprintf_s(mFile,"connectAttr \"");c1b.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1b\";\n",mName.c_str());}
	/*
	<b>Color2</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	void setColor2(const float3& c2){if(c2 == float3(0.549, 0.784, 0.392)) return; fprintf_s(mFile, "setAttr \".c2\" -type \"float3\" ");c2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color2</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	void setColor2(const Float3ID& c2){fprintf_s(mFile,"connectAttr \"");c2.write(mFile);fprintf_s(mFile,"\" \"%s.c2\";\n",mName.c_str());}
	/*The red value of Color 2*/
	void setColor2R(float c2r){if(c2r == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2r\" %f;\n", c2r);}
	/*The red value of Color 2*/
	void setColor2R(const FloatID& c2r){fprintf_s(mFile,"connectAttr \"");c2r.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2r\";\n",mName.c_str());}
	/*The green value of Color 2*/
	void setColor2G(float c2g){if(c2g == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2g\" %f;\n", c2g);}
	/*The green value of Color 2*/
	void setColor2G(const FloatID& c2g){fprintf_s(mFile,"connectAttr \"");c2g.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2g\";\n",mName.c_str());}
	/*The blue value of Color 2*/
	void setColor2B(float c2b){if(c2b == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2b\" %f;\n", c2b);}
	/*The blue value of Color 2*/
	void setColor2B(const FloatID& c2b){fprintf_s(mFile,"connectAttr \"");c2b.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2b\";\n",mName.c_str());}
	/*
	<b>Color3</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	void setColor3(const float3& c3){if(c3 == float3(0.627, 0.824, 0.823)) return; fprintf_s(mFile, "setAttr \".c3\" -type \"float3\" ");c3.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color3</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	void setColor3(const Float3ID& c3){fprintf_s(mFile,"connectAttr \"");c3.write(mFile);fprintf_s(mFile,"\" \"%s.c3\";\n",mName.c_str());}
	/*The red value of Color 3*/
	void setColor3R(float c3r){if(c3r == 0.0) return; fprintf_s(mFile, "setAttr \".c3.c3r\" %f;\n", c3r);}
	/*The red value of Color 3*/
	void setColor3R(const FloatID& c3r){fprintf_s(mFile,"connectAttr \"");c3r.write(mFile);fprintf_s(mFile,"\" \"%s.c3.c3r\";\n",mName.c_str());}
	/*The green value of Color 3*/
	void setColor3G(float c3g){if(c3g == 0.0) return; fprintf_s(mFile, "setAttr \".c3.c3g\" %f;\n", c3g);}
	/*The green value of Color 3*/
	void setColor3G(const FloatID& c3g){fprintf_s(mFile,"connectAttr \"");c3g.write(mFile);fprintf_s(mFile,"\" \"%s.c3.c3g\";\n",mName.c_str());}
	/*The blue value of Color 3*/
	void setColor3B(float c3b){if(c3b == 0.0) return; fprintf_s(mFile, "setAttr \".c3.c3b\" %f;\n", c3b);}
	/*The blue value of Color 3*/
	void setColor3B(const FloatID& c3b){fprintf_s(mFile,"connectAttr \"");c3b.write(mFile);fprintf_s(mFile,"\" \"%s.c3.c3b\";\n",mName.c_str());}
	/*
	<b>Filler Color</b> is the color of the medium in which
	the three minerals (colors) are suspended.  The combination
	of these colors makes up the granite texture.
	*/
	void setFillerColor(const float3& fc){if(fc == float3(0.588, 0.294, 0.196)) return; fprintf_s(mFile, "setAttr \".fc\" -type \"float3\" ");fc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Filler Color</b> is the color of the medium in which
	the three minerals (colors) are suspended.  The combination
	of these colors makes up the granite texture.
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
	<b>Cell Size</b> controls the size of the mineral particles
	suspended in the filler material.  Increase this to make
	the color spots larger.
	<p/>
	If the Granite texture is being used as a bump map, then
	increasing Cell Size makes the bumps look less like sandpaper,
	and more like cobblestones.
	*/
	void setCellSize(float cs){if(cs == 0.15) return; fprintf_s(mFile, "setAttr \".cs\" %f;\n", cs);}
	/*
	<b>Cell Size</b> controls the size of the mineral particles
	suspended in the filler material.  Increase this to make
	the color spots larger.
	<p/>
	If the Granite texture is being used as a bump map, then
	increasing Cell Size makes the bumps look less like sandpaper,
	and more like cobblestones.
	*/
	void setCellSize(const FloatID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs\";\n",mName.c_str());}
	/*
	<b>Density</b> controls how much of the suspended minerals
	are present in the filler.  Decrease Density to make the filler
	color dominate the texture.  Increase Densiry to add more of
	suspended minerals.
	<p/>
	If the Granite texture is being used as a bump map, then
	low Density values will make it look like a smooth surface
	with tiny rust-like bumps on it.
	*/
	void setDensity(float dy){if(dy == 1.0) return; fprintf_s(mFile, "setAttr \".dy\" %f;\n", dy);}
	/*
	<b>Density</b> controls how much of the suspended minerals
	are present in the filler.  Decrease Density to make the filler
	color dominate the texture.  Increase Densiry to add more of
	suspended minerals.
	<p/>
	If the Granite texture is being used as a bump map, then
	low Density values will make it look like a smooth surface
	with tiny rust-like bumps on it.
	*/
	void setDensity(const FloatID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.dy\";\n",mName.c_str());}
	/*
	<b>Mix Ratio</b> controls the relative amounts of each
	color that are present in the texture.  Set it close to
	0 to get more of Color1; close to 0.5 to get more of Color2,
	and close to 1.0 to get more of Color3.
	*/
	void setMixRatio(float mr){if(mr == 0.5) return; fprintf_s(mFile, "setAttr \".mr\" %f;\n", mr);}
	/*
	<b>Mix Ratio</b> controls the relative amounts of each
	color that are present in the texture.  Set it close to
	0 to get more of Color1; close to 0.5 to get more of Color2,
	and close to 1.0 to get more of Color3.
	*/
	void setMixRatio(const FloatID& mr){fprintf_s(mFile,"connectAttr \"");mr.write(mFile);fprintf_s(mFile,"\" \"%s.mr\";\n",mName.c_str());}
	/*
	<b>Spottyness</b> controls how random the intensity of
	the spots of color are in the granite.  When Spottyness
	is 0, all the spots of each color are exactly the same
	intensity.  As you increase spottyness, individual spots
	may become more or less intense (bright) randomly.  When
	Spottyness is 1.0, the intensity of each spot is completely
	random.
	*/
	void setSpottyness(float s){if(s == 0.3) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*
	<b>Spottyness</b> controls how random the intensity of
	the spots of color are in the granite.  When Spottyness
	is 0, all the spots of each color are exactly the same
	intensity.  As you increase spottyness, individual spots
	may become more or less intense (bright) randomly.  When
	Spottyness is 1.0, the intensity of each spot is completely
	random.
	*/
	void setSpottyness(const FloatID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	<b>Randomness</b> controls how the spots of color are arranged
	relative to one another.  Set randomness to 1.0 to get a realistic
	random distribution of minerals, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	void setRandomness(float ra){if(ra == 1.0) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Randomness</b> controls how the spots of color are arranged
	relative to one another.  Set randomness to 1.0 to get a realistic
	random distribution of minerals, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	void setRandomness(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*
	<b>Threshold</b> controls the amount that the three colors
	used in the texture mix into each other.  Use low values
	of Threshold to make the colors blend more smoothly into
	one another.  Use high values to sharply separate the colors
	into solid dots.
	*/
	void setThreshold(float th){if(th == 0.5) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*
	<b>Threshold</b> controls the amount that the three colors
	used in the texture mix into each other.  Use low values
	of Threshold to make the colors blend more smoothly into
	one another.  Use high values to sharply separate the colors
	into solid dots.
	*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*
	<b>Creases</b>.  Turn this on to prevent the color spots
	from blending into each other at their borders.  The effect
	of this is more noticeable in bump maps than in color maps.
	Turn off Creases to make the spots smootly diffuse into one
	another at their edges.
	*/
	void setCreases(bool c){if(c == true) return; fprintf_s(mFile, "setAttr \".c\" %i;\n", c);}
	/*
	<b>Creases</b>.  Turn this on to prevent the color spots
	from blending into each other at their borders.  The effect
	of this is more noticeable in bump maps than in color maps.
	Turn off Creases to make the spots smootly diffuse into one
	another at their edges.
	*/
	void setCreases(const BoolID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointObj(){char buffer[4096];sprintf_s (buffer, "%s.rpo",mName.c_str());return (const char*)buffer;}
	/*The x component of the current reference sample position*/
	FloatID getRefPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.rpo.rox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current reference sample position*/
	FloatID getRefPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.rpo.roy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current reference sample position*/
	FloatID getRefPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.rpo.roz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color1</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	Float3ID getColor1(){char buffer[4096];sprintf_s (buffer, "%s.c1",mName.c_str());return (const char*)buffer;}
	/*The red value of Color 1*/
	FloatID getColor1R(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1r",mName.c_str());return (const char*)buffer;}
	/*The green value of Color 1*/
	FloatID getColor1G(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1g",mName.c_str());return (const char*)buffer;}
	/*The blue value of Color 1*/
	FloatID getColor1B(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color2</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	Float3ID getColor2(){char buffer[4096];sprintf_s (buffer, "%s.c2",mName.c_str());return (const char*)buffer;}
	/*The red value of Color 2*/
	FloatID getColor2R(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2r",mName.c_str());return (const char*)buffer;}
	/*The green value of Color 2*/
	FloatID getColor2G(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2g",mName.c_str());return (const char*)buffer;}
	/*The blue value of Color 2*/
	FloatID getColor2B(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color3</b> is the color of one of the minerals
	comprising the granite texture.  There are three
	different mineral colors, suspended in a filler color.
	*/
	Float3ID getColor3(){char buffer[4096];sprintf_s (buffer, "%s.c3",mName.c_str());return (const char*)buffer;}
	/*The red value of Color 3*/
	FloatID getColor3R(){char buffer[4096];sprintf_s (buffer, "%s.c3.c3r",mName.c_str());return (const char*)buffer;}
	/*The green value of Color 3*/
	FloatID getColor3G(){char buffer[4096];sprintf_s (buffer, "%s.c3.c3g",mName.c_str());return (const char*)buffer;}
	/*The blue value of Color 3*/
	FloatID getColor3B(){char buffer[4096];sprintf_s (buffer, "%s.c3.c3b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Filler Color</b> is the color of the medium in which
	the three minerals (colors) are suspended.  The combination
	of these colors makes up the granite texture.
	*/
	Float3ID getFillerColor(){char buffer[4096];sprintf_s (buffer, "%s.fc",mName.c_str());return (const char*)buffer;}
	/*Filler Color red value*/
	FloatID getFillerColorR(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcr",mName.c_str());return (const char*)buffer;}
	/*Filler Color green value*/
	FloatID getFillerColorG(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcg",mName.c_str());return (const char*)buffer;}
	/*Filler Color blue value*/
	FloatID getFillerColorB(){char buffer[4096];sprintf_s (buffer, "%s.fc.fcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Cell Size</b> controls the size of the mineral particles
	suspended in the filler material.  Increase this to make
	the color spots larger.
	<p/>
	If the Granite texture is being used as a bump map, then
	increasing Cell Size makes the bumps look less like sandpaper,
	and more like cobblestones.
	*/
	FloatID getCellSize(){char buffer[4096];sprintf_s (buffer, "%s.cs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Density</b> controls how much of the suspended minerals
	are present in the filler.  Decrease Density to make the filler
	color dominate the texture.  Increase Densiry to add more of
	suspended minerals.
	<p/>
	If the Granite texture is being used as a bump map, then
	low Density values will make it look like a smooth surface
	with tiny rust-like bumps on it.
	*/
	FloatID getDensity(){char buffer[4096];sprintf_s (buffer, "%s.dy",mName.c_str());return (const char*)buffer;}
	/*
	<b>Mix Ratio</b> controls the relative amounts of each
	color that are present in the texture.  Set it close to
	0 to get more of Color1; close to 0.5 to get more of Color2,
	and close to 1.0 to get more of Color3.
	*/
	FloatID getMixRatio(){char buffer[4096];sprintf_s (buffer, "%s.mr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Spottyness</b> controls how random the intensity of
	the spots of color are in the granite.  When Spottyness
	is 0, all the spots of each color are exactly the same
	intensity.  As you increase spottyness, individual spots
	may become more or less intense (bright) randomly.  When
	Spottyness is 1.0, the intensity of each spot is completely
	random.
	*/
	FloatID getSpottyness(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	<b>Randomness</b> controls how the spots of color are arranged
	relative to one another.  Set randomness to 1.0 to get a realistic
	random distribution of minerals, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	FloatID getRandomness(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*
	<b>Threshold</b> controls the amount that the three colors
	used in the texture mix into each other.  Use low values
	of Threshold to make the colors blend more smoothly into
	one another.  Use high values to sharply separate the colors
	into solid dots.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
	/*
	<b>Creases</b>.  Turn this on to prevent the color spots
	from blending into each other at their borders.  The effect
	of this is more noticeable in bump maps than in color maps.
	Turn off Creases to make the spots smootly diffuse into one
	another at their edges.
	*/
	BoolID getCreases(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
protected:
	Granite(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GRANITE_H__
