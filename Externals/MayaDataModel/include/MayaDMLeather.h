/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LEATHER_H__
#define __MayaDM_LEATHER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
The <b>Leather</b> texture can be used to simulate a wide range
 of reptile and animal hides.  Used as a bump map it can simulate
 anything from fine-grained concrete to cobblestones.  The texture
 itself consists of a collection of spheres (also called cells)
 suspended in a medium.
<p/>
 You get the best animal-skin effect by using Leather both as a
 color and a bump map.
<p/>
 Aside from the attributes listed here, Leather inherits many
 attributes from <a href="texture3d.html">Texture3d</a>.
<p/>
 In the table below, important attributes have their names
 shown in <b>bold</b> in the Description column.
*/
class Leather : public Texture3d
{
public:
public:
	Leather(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "leather"){}
	virtual ~Leather(){}
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
	<b>Cell Color</b> controls the colors of the cells in the
	leather texture.  The texture consists uf a series of
	spheres (cells) imbedded in a medium.
	*/
	void setCellColor(const float3& ce){if(ce == float3(0.373, 0.157, 0.059)) return; fprintf_s(mFile, "setAttr \".ce\" -type \"float3\" ");ce.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Cell Color</b> controls the colors of the cells in the
	leather texture.  The texture consists uf a series of
	spheres (cells) imbedded in a medium.
	*/
	void setCellColor(const Float3ID& ce){fprintf_s(mFile,"connectAttr \"");ce.write(mFile);fprintf_s(mFile,"\" \"%s.ce\";\n",mName.c_str());}
	/*The red value of Cell Color*/
	void setCellColorR(float cer){if(cer == 0.0) return; fprintf_s(mFile, "setAttr \".ce.cer\" %f;\n", cer);}
	/*The red value of Cell Color*/
	void setCellColorR(const FloatID& cer){fprintf_s(mFile,"connectAttr \"");cer.write(mFile);fprintf_s(mFile,"\" \"%s.ce.cer\";\n",mName.c_str());}
	/*The green value of Cell Color*/
	void setCellColorG(float ceg){if(ceg == 0.0) return; fprintf_s(mFile, "setAttr \".ce.ceg\" %f;\n", ceg);}
	/*The green value of Cell Color*/
	void setCellColorG(const FloatID& ceg){fprintf_s(mFile,"connectAttr \"");ceg.write(mFile);fprintf_s(mFile,"\" \"%s.ce.ceg\";\n",mName.c_str());}
	/*The blue value of Cell Color*/
	void setCellColorB(float ceb){if(ceb == 0.0) return; fprintf_s(mFile, "setAttr \".ce.ceb\" %f;\n", ceb);}
	/*The blue value of Cell Color*/
	void setCellColorB(const FloatID& ceb){fprintf_s(mFile,"connectAttr \"");ceb.write(mFile);fprintf_s(mFile,"\" \"%s.ce.ceb\";\n",mName.c_str());}
	/*
	<b>Crease Color</b> controls the color of the space between
	the cells in the leather texture.
	*/
	void setCreaseColor(const float3& cr){if(cr == float3(0.235, 0.118, 0.0)) return; fprintf_s(mFile, "setAttr \".cr\" -type \"float3\" ");cr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Crease Color</b> controls the color of the space between
	the cells in the leather texture.
	*/
	void setCreaseColor(const Float3ID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*The red value of Crease Color*/
	void setCreaseColorR(float crr){if(crr == 0.0) return; fprintf_s(mFile, "setAttr \".cr.crr\" %f;\n", crr);}
	/*The red value of Crease Color*/
	void setCreaseColorR(const FloatID& crr){fprintf_s(mFile,"connectAttr \"");crr.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crr\";\n",mName.c_str());}
	/*The green value of Crease Color*/
	void setCreaseColorG(float crg){if(crg == 0.0) return; fprintf_s(mFile, "setAttr \".cr.crg\" %f;\n", crg);}
	/*The green value of Crease Color*/
	void setCreaseColorG(const FloatID& crg){fprintf_s(mFile,"connectAttr \"");crg.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crg\";\n",mName.c_str());}
	/*The blue value of Crease Color*/
	void setCreaseColorB(float crb){if(crb == 0.0) return; fprintf_s(mFile, "setAttr \".cr.crb\" %f;\n", crb);}
	/*The blue value of Crease Color*/
	void setCreaseColorB(const FloatID& crb){fprintf_s(mFile,"connectAttr \"");crb.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crb\";\n",mName.c_str());}
	/*
	<b>Cell Size</b> controls the size of the color cells in the
	leather texture.  Increase this to make the cells bigger.
	<p/>If the Leather texture is being used as a bump map, larger
	values for Cell Size can make it look like cobblestones.
	Smaller values make it look more like sandpaper.
	*/
	void setCellSize(float cs){if(cs == 0.5) return; fprintf_s(mFile, "setAttr \".cs\" %f;\n", cs);}
	/*
	<b>Cell Size</b> controls the size of the color cells in the
	leather texture.  Increase this to make the cells bigger.
	<p/>If the Leather texture is being used as a bump map, larger
	values for Cell Size can make it look like cobblestones.
	Smaller values make it look more like sandpaper.
	*/
	void setCellSize(const FloatID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs\";\n",mName.c_str());}
	/*
	<b>Density</b> controls how many cells there are imbedded
	in the medium.  At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the Leather texture is being used as a bump map, then
	low values for Density will make it look likea smooth surface
	with occasional bumps on it.
	*/
	void setDensity(float d){if(d == 1.0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	<b>Density</b> controls how many cells there are imbedded
	in the medium.  At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the Leather texture is being used as a bump map, then
	low values for Density will make it look likea smooth surface
	with occasional bumps on it.
	*/
	void setDensity(const FloatID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	<b>Spottyness</b> controls the randomization of the color
	of the individual cells.  When Spottyness is close to 0,
	all the cells will be the same color.  As you increase
	Spottyness, some cells will be brighter or darker than others,
	in a random fashion.
	*/
	void setSpottyness(float s){if(s == 0.1) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*
	<b>Spottyness</b> controls the randomization of the color
	of the individual cells.  When Spottyness is close to 0,
	all the cells will be the same color.  As you increase
	Spottyness, some cells will be brighter or darker than others,
	in a random fashion.
	*/
	void setSpottyness(const FloatID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	<b>Randomness</b> controls how the cells are arranged
	relative to one another.  Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	void setRandomness(float r){if(r == 0.5) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*
	<b>Randomness</b> controls how the cells are arranged
	relative to one another.  Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	void setRandomness(const FloatID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*
	<b>Threshold</b> controls the amount that the two colors
	used in the texture mix into each other.  Use low values
	of Threshold to make the colors blend more smoothly into
	one another.  Use high values to sharply separate the colors
	into solid dots.
	*/
	void setThreshold(float th){if(th == 0.83) return; fprintf_s(mFile, "setAttr \".th\" %f;\n", th);}
	/*
	<b>Threshold</b> controls the amount that the two colors
	used in the texture mix into each other.  Use low values
	of Threshold to make the colors blend more smoothly into
	one another.  Use high values to sharply separate the colors
	into solid dots.
	*/
	void setThreshold(const FloatID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th\";\n",mName.c_str());}
	/*
	<b>Creases</b>.  Turn this on to prevent overlapping
	cells from blending into one another.  If this is on
	there will always be a sharp separation between cells.
	*/
	void setCreases(bool c){if(c == true) return; fprintf_s(mFile, "setAttr \".c\" %i;\n", c);}
	/*
	<b>Creases</b>.  Turn this on to prevent overlapping
	cells from blending into one another.  If this is on
	there will always be a sharp separation between cells.
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
	<b>Cell Color</b> controls the colors of the cells in the
	leather texture.  The texture consists uf a series of
	spheres (cells) imbedded in a medium.
	*/
	Float3ID getCellColor(){char buffer[4096];sprintf_s (buffer, "%s.ce",mName.c_str());return (const char*)buffer;}
	/*The red value of Cell Color*/
	FloatID getCellColorR(){char buffer[4096];sprintf_s (buffer, "%s.ce.cer",mName.c_str());return (const char*)buffer;}
	/*The green value of Cell Color*/
	FloatID getCellColorG(){char buffer[4096];sprintf_s (buffer, "%s.ce.ceg",mName.c_str());return (const char*)buffer;}
	/*The blue value of Cell Color*/
	FloatID getCellColorB(){char buffer[4096];sprintf_s (buffer, "%s.ce.ceb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Crease Color</b> controls the color of the space between
	the cells in the leather texture.
	*/
	Float3ID getCreaseColor(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*The red value of Crease Color*/
	FloatID getCreaseColorR(){char buffer[4096];sprintf_s (buffer, "%s.cr.crr",mName.c_str());return (const char*)buffer;}
	/*The green value of Crease Color*/
	FloatID getCreaseColorG(){char buffer[4096];sprintf_s (buffer, "%s.cr.crg",mName.c_str());return (const char*)buffer;}
	/*The blue value of Crease Color*/
	FloatID getCreaseColorB(){char buffer[4096];sprintf_s (buffer, "%s.cr.crb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Cell Size</b> controls the size of the color cells in the
	leather texture.  Increase this to make the cells bigger.
	<p/>If the Leather texture is being used as a bump map, larger
	values for Cell Size can make it look like cobblestones.
	Smaller values make it look more like sandpaper.
	*/
	FloatID getCellSize(){char buffer[4096];sprintf_s (buffer, "%s.cs",mName.c_str());return (const char*)buffer;}
	/*
	<b>Density</b> controls how many cells there are imbedded
	in the medium.  At 1.0, the medium is completely packed
	with cells.  Reduce this value to make the cells more sparse.
	<p/>If the Leather texture is being used as a bump map, then
	low values for Density will make it look likea smooth surface
	with occasional bumps on it.
	*/
	FloatID getDensity(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	<b>Spottyness</b> controls the randomization of the color
	of the individual cells.  When Spottyness is close to 0,
	all the cells will be the same color.  As you increase
	Spottyness, some cells will be brighter or darker than others,
	in a random fashion.
	*/
	FloatID getSpottyness(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	<b>Randomness</b> controls how the cells are arranged
	relative to one another.  Set randomness to 1.0 to get a realistic
	random distribution of cells, as would be found in nature.
	If you set Randomness to 0, all the spots are laid out in a
	completely regular pattern.  This can provide interesting
	effects when used as a bump map;  you can make things like
	insect eyes, or machine-tooled raspy surfaces.
	*/
	FloatID getRandomness(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*
	<b>Threshold</b> controls the amount that the two colors
	used in the texture mix into each other.  Use low values
	of Threshold to make the colors blend more smoothly into
	one another.  Use high values to sharply separate the colors
	into solid dots.
	*/
	FloatID getThreshold(){char buffer[4096];sprintf_s (buffer, "%s.th",mName.c_str());return (const char*)buffer;}
	/*
	<b>Creases</b>.  Turn this on to prevent overlapping
	cells from blending into one another.  If this is on
	there will always be a sharp separation between cells.
	*/
	BoolID getCreases(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
protected:
	Leather(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LEATHER_H__
