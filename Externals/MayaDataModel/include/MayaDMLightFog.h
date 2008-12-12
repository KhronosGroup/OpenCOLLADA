/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHTFOG_H__
#define __MayaDM_LIGHTFOG_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Light Fog</b> nodes are used to fill a spotlit region with the
 appearance of fog or mist.
<p/>
  In the table below, important attribute have their names indicated
  in <b>bold</b> in the description column.
*/
class LightFog : public DependNode
{
public:
public:
	LightFog(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "lightFog"){}
	virtual ~LightFog(){}
	/*
	<b>Color</b> is the basic color of the fog.<p/>To make
	the fog appear more smoke-like, connect the
	Out Color attribute of a Cloud texture to this attribute,
	and turn on Color Based Transparency.
	*/
	void setColor(const float3& c){if(c == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c\" -type \"float3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color</b> is the basic color of the fog.<p/>To make
	the fog appear more smoke-like, connect the
	Out Color attribute of a Cloud texture to this attribute,
	and turn on Color Based Transparency.
	*/
	void setColor(const Float3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*The red component of the fog color.*/
	void setColorR(float cr){if(cr == 0.0) return; fprintf_s(mFile, "setAttr \".c.cr\" %f;\n", cr);}
	/*The red component of the fog color.*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.c.cr\";\n",mName.c_str());}
	/*The green component of the fog color.*/
	void setColorG(float cg){if(cg == 0.0) return; fprintf_s(mFile, "setAttr \".c.cg\" %f;\n", cg);}
	/*The green component of the fog color.*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.c.cg\";\n",mName.c_str());}
	/*The blue component of the fog color.*/
	void setColorB(float cb){if(cb == 0.0) return; fprintf_s(mFile, "setAttr \".c.cb\" %f;\n", cb);}
	/*The blue component of the fog color.*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.c.cb\";\n",mName.c_str());}
	/*
	<b>Density</b> controls the apparent density of the
	fog.  The higher this value, the denser the fog.  It
	becomes brighter, and more completely masks whatever is
	behind it.
	*/
	void setDensity(float d){if(d == 1.0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	<b>Density</b> controls the apparent density of the
	fog.  The higher this value, the denser the fog.  It
	becomes brighter, and more completely masks whatever is
	behind it.
	*/
	void setDensity(const FloatID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	When <b>Fast Drop Off</b> is turned on, the fog transparency
	changes with the fog depth.  This means that the more fog
	you have in front of an object, the more hidden and masked
	the object will be.  This is what happens in real fog.  As
	a result, objects closer to the camera are more visible than
	objects farther away.
	*/
	void setFastDropOff(bool fd){if(fd == false) return; fprintf_s(mFile, "setAttr \".fd\" %i;\n", fd);}
	/*
	When <b>Fast Drop Off</b> is turned on, the fog transparency
	changes with the fog depth.  This means that the more fog
	you have in front of an object, the more hidden and masked
	the object will be.  This is what happens in real fog.  As
	a result, objects closer to the camera are more visible than
	objects farther away.
	*/
	void setFastDropOff(const BoolID& fd){fprintf_s(mFile,"connectAttr \"");fd.write(mFile);fprintf_s(mFile,"\" \"%s.fd\";\n",mName.c_str());}
	/*
	When <b>Color-Based Transparency</b> is turned on, the fog is
	is more opaque where its color is brightest.  White areas are
	completely opaque;  black areas are completely transparent.<p/>
	This setting is particularly effective when used in conjunction
	with Fast Drop Off.
	*/
	void setColorBasedTransparency(bool cbt){if(cbt == true) return; fprintf_s(mFile, "setAttr \".cbt\" %i;\n", cbt);}
	/*
	When <b>Color-Based Transparency</b> is turned on, the fog is
	is more opaque where its color is brightest.  White areas are
	completely opaque;  black areas are completely transparent.<p/>
	This setting is particularly effective when used in conjunction
	with Fast Drop Off.
	*/
	void setColorBasedTransparency(const BoolID& cbt){fprintf_s(mFile,"connectAttr \"");cbt.write(mFile);fprintf_s(mFile,"\" \"%s.cbt\";\n",mName.c_str());}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	void setMatteOpacityMode(unsigned int mom){if(mom == 2) return; fprintf_s(mFile, "setAttr \".mom\" %i;\n", mom);}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	void setMatteOpacityMode(const UnsignedintID& mom){fprintf_s(mFile,"connectAttr \"");mom.write(mFile);fprintf_s(mFile,"\" \"%s.mom\";\n",mName.c_str());}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(float mog){if(mog == 1.0) return; fprintf_s(mFile, "setAttr \".mog\" %f;\n", mog);}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	void setMatteOpacity(const FloatID& mog){fprintf_s(mFile,"connectAttr \"");mog.write(mFile);fprintf_s(mFile,"\" \"%s.mog\";\n",mName.c_str());}
	/*output Matte Opacity*/
	void setOutMatteOpacity(const Float3ID& omo){fprintf_s(mFile,"connectAttr \"");omo.write(mFile);fprintf_s(mFile,"\" \"%s.omo\";\n",mName.c_str());}
	/*output Matte Opacity red value*/
	void setOutMatteOpacityR(const FloatID& omor){fprintf_s(mFile,"connectAttr \"");omor.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omor\";\n",mName.c_str());}
	/*output Matte Opacity green value*/
	void setOutMatteOpacityG(const FloatID& omog){fprintf_s(mFile,"connectAttr \"");omog.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omog\";\n",mName.c_str());}
	/*output Matte Opacity blue value*/
	void setOutMatteOpacityB(const FloatID& omob){fprintf_s(mFile,"connectAttr \"");omob.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omob\";\n",mName.c_str());}
	/*The fog  output color.*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The red component of the fog  output color.*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*The green component of the fog  output color.*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*The blue component of the fog  output color.*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*The fog output transparency.*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*The red component of the fog output transparency.*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*The green component of the fog output transparency.*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*The blue component of the fog output transparency.*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*
	<b>Color</b> is the basic color of the fog.<p/>To make
	the fog appear more smoke-like, connect the
	Out Color attribute of a Cloud texture to this attribute,
	and turn on Color Based Transparency.
	*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*The red component of the fog color.*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.c.cr",mName.c_str());return (const char*)buffer;}
	/*The green component of the fog color.*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.c.cg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the fog color.*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.c.cb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Density</b> controls the apparent density of the
	fog.  The higher this value, the denser the fog.  It
	becomes brighter, and more completely masks whatever is
	behind it.
	*/
	FloatID getDensity(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	When <b>Fast Drop Off</b> is turned on, the fog transparency
	changes with the fog depth.  This means that the more fog
	you have in front of an object, the more hidden and masked
	the object will be.  This is what happens in real fog.  As
	a result, objects closer to the camera are more visible than
	objects farther away.
	*/
	BoolID getFastDropOff(){char buffer[4096];sprintf_s (buffer, "%s.fd",mName.c_str());return (const char*)buffer;}
	/*
	When <b>Color-Based Transparency</b> is turned on, the fog is
	is more opaque where its color is brightest.  White areas are
	completely opaque;  black areas are completely transparent.<p/>
	This setting is particularly effective when used in conjunction
	with Fast Drop Off.
	*/
	BoolID getColorBasedTransparency(){char buffer[4096];sprintf_s (buffer, "%s.cbt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity Mode</b> controls how the system will use the
	Matte Opacity attribute (below).  When you are rendering with a
	matte (<i>i.e.</i> an alpha channel, or mask), these two attributes
	are used to control how this material will show up in the matte.
	This is useful if you will be compositing your rendered images
	later on.
	<p/>There are three settings, used for different purposes:<p/>
	<ul>
	<b>Opacity Gain</b>: (the default).
	Matte values are calculated in the normal way (based on the transparency
	of the object) then multiplied by the
	Matte Opacity.  (Matte Opacity has a default value of one, by
	default these attributes have no effect.)  With Opacity Gain, you
	can animate the Matte Opacity value to change the overall transparency
	of the object when it is later composited.<p/>
	<b>Solid Matte</b>:  This is like Opacity Gain, except that the
	normally-calculated matte values are ignored in favor of the
	Matte Opacity setting.  The entire matte for
	the object is set to the value of the Matte Opacity attribute.
	If there are transparent
	areas on the object, their transparency is ignored in the matte.
	Use this setting to composite an object with transparent
	parts, when you don't want the background to show through them.
	<p/>
	<b>Black Hole</b>:  The value of Matte Opacity is ignored, and all
	the matte for this material is set to be transparent.  Use this when
	you are creating substitute geometry in a scene, which is standing
	in for objects in a background image that you will be compositing with
	later.  Your stand-in objects will 'punch
	a hole' in the matte.  This allows other computer-generated
	geometry to pass behind your stand-in objects. Later, when
	foreground and background are composited, the results will be correct,
	with the background object showing through the 'black hole' areas.
	</ul>
	*/
	UnsignedintID getMatteOpacityMode(){char buffer[4096];sprintf_s (buffer, "%s.mom",mName.c_str());return (const char*)buffer;}
	/*
	<b>Matte Opacity</b> is used (along with Matte Opactiy Mode)
	to affect how the matte (<i>i.e.</i> alpha channel or mask)
	for this material will be calculated.  See Matte Opacity Mode above
	for full details.
	*/
	FloatID getMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.mog",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity*/
	Float3ID getOutMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.omo",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity red value*/
	FloatID getOutMatteOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.omo.omor",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity green value*/
	FloatID getOutMatteOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.omo.omog",mName.c_str());return (const char*)buffer;}
	/*output Matte Opacity blue value*/
	FloatID getOutMatteOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.omo.omob",mName.c_str());return (const char*)buffer;}
	/*The fog  output color.*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*The red component of the fog  output color.*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*The green component of the fog  output color.*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the fog  output color.*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*The fog output transparency.*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*The red component of the fog output transparency.*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*The green component of the fog output transparency.*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the fog output transparency.*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
protected:
	LightFog(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LIGHTFOG_H__
