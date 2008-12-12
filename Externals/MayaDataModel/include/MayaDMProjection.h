/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PROJECTION_H__
#define __MayaDM_PROJECTION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
<b>Projection</b> nodes can take any 2d texture, and make a 3d
 texture out of it, using one of the many projection types available.
 <p/>
 Projection nodes are created automatically by the system when
 you tell it to create a 2d texture as a projection.
 <p/>
 The Out Color attribute of the 2d texture is connected to the
 Image attribute of the Projection node.  Then, the Out Color attribute
 of the Projection nodes is connected to where ever it needs to go.
 (Usually, the Color attribute of a Phong, Blinn, or Lambert shader).
 <p/>
 Aside from the attributes described here, Projection nodes also
 inherit many attributes from <a href="texture3d.html">Texture3d</a>.
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the Description column.
*/
class Projection : public Texture3d
{
public:
public:
	Projection(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "projection"){}
	virtual ~Projection(){}
	/*The input normal*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The X component of the input normal*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The Y component of the input normal*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The Z component of the input normal*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*The input normal on the surface based on world matrix*/
	void setSrfNormal(const Float3ID& srn){fprintf_s(mFile,"connectAttr \"");srn.write(mFile);fprintf_s(mFile,"\" \"%s.srn\";\n",mName.c_str());}
	/*The X component of the input normal*/
	void setSrfNormalX(const FloatID& snx){fprintf_s(mFile,"connectAttr \"");snx.write(mFile);fprintf_s(mFile,"\" \"%s.srn.snx\";\n",mName.c_str());}
	/*The Y component of the input normal*/
	void setSrfNormalY(const FloatID& sny){fprintf_s(mFile,"connectAttr \"");sny.write(mFile);fprintf_s(mFile,"\" \"%s.srn.sny\";\n",mName.c_str());}
	/*The Z component of the input normal*/
	void setSrfNormalZ(const FloatID& snz){fprintf_s(mFile,"connectAttr \"");snz.write(mFile);fprintf_s(mFile,"\" \"%s.srn.snz\";\n",mName.c_str());}
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
	/*The pixel angle*/
	void setXPixelAngle(float xpa){if(xpa == 0.002053) return; fprintf_s(mFile, "setAttr \".xpa\" %f;\n", xpa);}
	/*
	<b>Image</b>.  The Out Color attribute of a 2d texture
	should be connected to this attribute.  This is the
	texture that will be projected.
	*/
	void setImage(const float3& im){if(im == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".im\" -type \"float3\" ");im.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Image</b>.  The Out Color attribute of a 2d texture
	should be connected to this attribute.  This is the
	texture that will be projected.
	*/
	void setImage(const Float3ID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*The red image value for the current sample*/
	void setImageR(float imr){if(imr == 0.0) return; fprintf_s(mFile, "setAttr \".im.imr\" %f;\n", imr);}
	/*The red image value for the current sample*/
	void setImageR(const FloatID& imr){fprintf_s(mFile,"connectAttr \"");imr.write(mFile);fprintf_s(mFile,"\" \"%s.im.imr\";\n",mName.c_str());}
	/*The green image value for the current sample*/
	void setImageG(float img){if(img == 0.0) return; fprintf_s(mFile, "setAttr \".im.img\" %f;\n", img);}
	/*The green image value for the current sample*/
	void setImageG(const FloatID& img){fprintf_s(mFile,"connectAttr \"");img.write(mFile);fprintf_s(mFile,"\" \"%s.im.img\";\n",mName.c_str());}
	/*The blue image value for the current sample*/
	void setImageB(float imb){if(imb == 0.0) return; fprintf_s(mFile, "setAttr \".im.imb\" %f;\n", imb);}
	/*The blue image value for the current sample*/
	void setImageB(const FloatID& imb){fprintf_s(mFile,"connectAttr \"");imb.write(mFile);fprintf_s(mFile,"\" \"%s.im.imb\";\n",mName.c_str());}
	/*
	<b>U Angle</b> controls how the input 2d texture is mapped
	around a circle, if you are using Spherical or Cylindrical
	texture mapping.  If U Angle is set to 90 degrees, that means
	that one instance of the texture is fit into each 90 degrees
	around the circle in the U direction.
	<p/>This attribute does nothing for other projection types.
	See also V Angle.
	*/
	void setUAngle(double ua){if(ua == 1) return; fprintf_s(mFile, "setAttr \".ua\" %f;\n", ua);}
	/*
	<b>U Angle</b> controls how the input 2d texture is mapped
	around a circle, if you are using Spherical or Cylindrical
	texture mapping.  If U Angle is set to 90 degrees, that means
	that one instance of the texture is fit into each 90 degrees
	around the circle in the U direction.
	<p/>This attribute does nothing for other projection types.
	See also V Angle.
	*/
	void setUAngle(const DoubleID& ua){fprintf_s(mFile,"connectAttr \"");ua.write(mFile);fprintf_s(mFile,"\" \"%s.ua\";\n",mName.c_str());}
	/*
	<b>V Angle</b> controls how the input 2d texture is mapped
	around a circle, if you are using Spherical or Cylindrical
	texture mapping.  If V Angle is set to 90 degrees, that means
	that one instance of the texture is fit into each 90 degrees
	around the circle in the V direction.
	<p/>This attribute does nothing for other projection types.
	See also U Angle.
	*/
	void setVAngle(double va){if(va == 9) return; fprintf_s(mFile, "setAttr \".va\" %f;\n", va);}
	/*
	<b>V Angle</b> controls how the input 2d texture is mapped
	around a circle, if you are using Spherical or Cylindrical
	texture mapping.  If V Angle is set to 90 degrees, that means
	that one instance of the texture is fit into each 90 degrees
	around the circle in the V direction.
	<p/>This attribute does nothing for other projection types.
	See also U Angle.
	*/
	void setVAngle(const DoubleID& va){fprintf_s(mFile,"connectAttr \"");va.write(mFile);fprintf_s(mFile,"\" \"%s.va\";\n",mName.c_str());}
	/*
	<b>Proj Type</b> controls how the 2d texture will be projected
	into 3d space.  The supported projection types are:
	<ul>
	<b>0. No Projection</b>: No projection is done.  Only the
	Default Color.is output.
	<p/><b>1. Planar</b>: Places the texture on a planar surface and
	projects it onto the object.
	<p/><b>2. Spherical</b>: Places the texture inside a sphere and
	projects it onto the object.  There will be two "pinch points",
	one at each of the poles of the sphere.
	<p/><b>3. Cylindrical</b>: Places the texture inside a cylinder and
	projects it onto the object.  There will be two "pinch points",
	one at each of the ends of the cylinder.
	<p/><b>4. Ball</b>: Places the texture inside a ball and
	projects it onto the object.  This is similar to the way that
	a candy wrapper is pulled around a lollipop.  There will be
	one "pinch points" at the Z-pole.
	<p/><b>5. Cubic</b>: Places the texture on six faces of a
	a cube, and projects them onto the object.
	<p/><b>6. TriPlanar</b>: Projects the texture by extruding it
	along the axis defined by the maximum current direction of the
	surface normal.  This is somewhat like fabric being wrapped around
	the object.
	<p/><b>7. Concentric</b>: Projects the texture by randomly selecting
	slices from it and making a concentric pattern from it.
	<p/><b>8. Perspective</b>:  Projects the texture by matching exactly
	the perspective of a particular camera.  To use this, you need to
	link the Projection node to a camera.  This type of projection is intended
	to be used to match modelled CGI to scanned backdrops.  To do this,
	use the same texture as a backdrop (put it on an Image Plane attached
	to the camera) and as a shader (use Perspective projection, and link
	the projection node to the same camera).  Objects in your scene using
	the shader will seem to disappear, since they will match the backdrop.
	You can then convert the object's shader to a solid texture, and
	animate the objects.
	For more detail on this process, see the rendering books.
	</ul>
	*/
	void setProjType(unsigned int t){if(t == 1) return; fprintf_s(mFile, "setAttr \".t\" %i;\n", t);}
	/*
	<b>Proj Type</b> controls how the 2d texture will be projected
	into 3d space.  The supported projection types are:
	<ul>
	<b>0. No Projection</b>: No projection is done.  Only the
	Default Color.is output.
	<p/><b>1. Planar</b>: Places the texture on a planar surface and
	projects it onto the object.
	<p/><b>2. Spherical</b>: Places the texture inside a sphere and
	projects it onto the object.  There will be two "pinch points",
	one at each of the poles of the sphere.
	<p/><b>3. Cylindrical</b>: Places the texture inside a cylinder and
	projects it onto the object.  There will be two "pinch points",
	one at each of the ends of the cylinder.
	<p/><b>4. Ball</b>: Places the texture inside a ball and
	projects it onto the object.  This is similar to the way that
	a candy wrapper is pulled around a lollipop.  There will be
	one "pinch points" at the Z-pole.
	<p/><b>5. Cubic</b>: Places the texture on six faces of a
	a cube, and projects them onto the object.
	<p/><b>6. TriPlanar</b>: Projects the texture by extruding it
	along the axis defined by the maximum current direction of the
	surface normal.  This is somewhat like fabric being wrapped around
	the object.
	<p/><b>7. Concentric</b>: Projects the texture by randomly selecting
	slices from it and making a concentric pattern from it.
	<p/><b>8. Perspective</b>:  Projects the texture by matching exactly
	the perspective of a particular camera.  To use this, you need to
	link the Projection node to a camera.  This type of projection is intended
	to be used to match modelled CGI to scanned backdrops.  To do this,
	use the same texture as a backdrop (put it on an Image Plane attached
	to the camera) and as a shader (use Perspective projection, and link
	the projection node to the same camera).  Objects in your scene using
	the shader will seem to disappear, since they will match the backdrop.
	You can then convert the object's shader to a solid texture, and
	animate the objects.
	For more detail on this process, see the rendering books.
	</ul>
	*/
	void setProjType(const UnsignedintID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*
	<b>Linked Camera</b> is a connection to a camera node.
	This is only used when Proj Type is set to Perspective.
	*/
	void setLinkedCamera(const MessageID& lc){fprintf_s(mFile,"connectAttr \"");lc.write(mFile);fprintf_s(mFile,"\" \"%s.lc\";\n",mName.c_str());}
	/*
	<b>Fit Type</b> controls how the texture will be fit to the camera when
	Proj type is set to Perspective.  If you are using this to match a backdrop,
	you should set this to match the setting in the Image Plane.
	<p/>
	Usually, you will have an image plane that is the same size as the rendered
	image.  If that is the case, you should use the Resolution Gate setting.
	<p/>You can also choose No Fit, which means that the image is not squeezed
	or stretched to fit.  One of its axes (determined by the Fit Fill attribute)
	will be fit to the filmgate, and the other will just be as big as it needs
	to.
	<p/>The third choice is Film Gate, which squeezes the image to fit the film gate.
	*/
	void setFitType(unsigned int ft){if(ft == 1) return; fprintf_s(mFile, "setAttr \".ft\" %i;\n", ft);}
	/*
	<b>Fit Type</b> controls how the texture will be fit to the camera when
	Proj type is set to Perspective.  If you are using this to match a backdrop,
	you should set this to match the setting in the Image Plane.
	<p/>
	Usually, you will have an image plane that is the same size as the rendered
	image.  If that is the case, you should use the Resolution Gate setting.
	<p/>You can also choose No Fit, which means that the image is not squeezed
	or stretched to fit.  One of its axes (determined by the Fit Fill attribute)
	will be fit to the filmgate, and the other will just be as big as it needs
	to.
	<p/>The third choice is Film Gate, which squeezes the image to fit the film gate.
	*/
	void setFitType(const UnsignedintID& ft){fprintf_s(mFile,"connectAttr \"");ft.write(mFile);fprintf_s(mFile,"\" \"%s.ft\";\n",mName.c_str());}
	/*
	<b>Fit Fill</b> is only used if Proj Type is set to Perspective, and
	Fit Type is set to No Fit.  If the image plane aspect ratio is not
	the same as the filmgate aspect ratio, then this attribute decides
	which axis of the image is fit to the film gate.
	*/
	void setFitFill(unsigned int ff){if(ff == 0) return; fprintf_s(mFile, "setAttr \".ff\" %i;\n", ff);}
	/*
	<b>Fit Fill</b> is only used if Proj Type is set to Perspective, and
	Fit Type is set to No Fit.  If the image plane aspect ratio is not
	the same as the filmgate aspect ratio, then this attribute decides
	which axis of the image is fit to the film gate.
	*/
	void setFitFill(const UnsignedintID& ff){fprintf_s(mFile,"connectAttr \"");ff.write(mFile);fprintf_s(mFile,"\" \"%s.ff\";\n",mName.c_str());}
	/*
	<b>Ripples</b> determines how wavy the image will be when
	projected, but controlling the scale of the fundamental
	frequency of any fractal noise added to the texture.
	<p/>
	If you increase Ripples in any particular direction, the
	fractal detail will seem to smear out in that direction.
	<p/>
	This attribute will not do anything unless Amplitude X or
	Amplitude Y is non-zero.  (That is, there must be some
	fractal noise added to the system.)
	*/
	void setRipples(const float3& r){if(r == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".r\" -type \"float3\" ");r.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Ripples</b> determines how wavy the image will be when
	projected, but controlling the scale of the fundamental
	frequency of any fractal noise added to the texture.
	<p/>
	If you increase Ripples in any particular direction, the
	fractal detail will seem to smear out in that direction.
	<p/>
	This attribute will not do anything unless Amplitude X or
	Amplitude Y is non-zero.  (That is, there must be some
	fractal noise added to the system.)
	*/
	void setRipples(const Float3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The noise along X*/
	void setRipplesX(float rx){if(rx == 0.0) return; fprintf_s(mFile, "setAttr \".r.rx\" %f;\n", rx);}
	/*The noise along X*/
	void setRipplesX(const FloatID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*The noise along Y*/
	void setRipplesY(float ry){if(ry == 0.0) return; fprintf_s(mFile, "setAttr \".r.ry\" %f;\n", ry);}
	/*The noise along Y*/
	void setRipplesY(const FloatID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*The noise along Z*/
	void setRipplesZ(float rz){if(rz == 0.0) return; fprintf_s(mFile, "setAttr \".r.rz\" %f;\n", rz);}
	/*The noise along Z*/
	void setRipplesZ(const FloatID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*
	<b>Depth</b> controls
	how much calculation is done by this
	texture when Ripples are added.  Fractal noise such as ripples
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	void setDepth(const float2& d){if(d == float2(0.0, 10.0)) return; fprintf_s(mFile, "setAttr \".d\" -type \"float2\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Depth</b> controls
	how much calculation is done by this
	texture when Ripples are added.  Fractal noise such as ripples
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	void setDepth(const Float2ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The minimum value for recursion depth*/
	void setDepthMin(float dmn){if(dmn == 0.0) return; fprintf_s(mFile, "setAttr \".d.dmn\" %f;\n", dmn);}
	/*The minimum value for recursion depth*/
	void setDepthMin(const FloatID& dmn){fprintf_s(mFile,"connectAttr \"");dmn.write(mFile);fprintf_s(mFile,"\" \"%s.d.dmn\";\n",mName.c_str());}
	/*The maximum value for recursion depth*/
	void setDepthMax(float dmx){if(dmx == 0.0) return; fprintf_s(mFile, "setAttr \".d.dmx\" %f;\n", dmx);}
	/*The maximum value for recursion depth*/
	void setDepthMax(const FloatID& dmx){fprintf_s(mFile,"connectAttr \"");dmx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dmx\";\n",mName.c_str());}
	/*
	<b>Amplitude X</b> can be used to scale the amount
	of fractal noise added to the projection in the X direction.
	When Amplitude X and Amplitude Y are 0,
	no fractal noise is added.  Adding fractal noise is
	a way of randomizing or blurring the texture.
	*/
	void setAmplitudeX(float ax){if(ax == 0.0) return; fprintf_s(mFile, "setAttr \".ax\" %f;\n", ax);}
	/*
	<b>Amplitude X</b> can be used to scale the amount
	of fractal noise added to the projection in the X direction.
	When Amplitude X and Amplitude Y are 0,
	no fractal noise is added.  Adding fractal noise is
	a way of randomizing or blurring the texture.
	*/
	void setAmplitudeX(const FloatID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.ax\";\n",mName.c_str());}
	/*
	<b>Amplitude Y</b> can be used to scale the amount
	of fractal noise added to the projection in the Y direction.
	When Amplitude X and Amplitude Y are 0,
	no fractal noise is added.  Adding fractal noise is
	a way of randomizing or blurring the texture.
	*/
	void setAmplitudeY(float ay){if(ay == 0.0) return; fprintf_s(mFile, "setAttr \".ay\" %f;\n", ay);}
	/*
	<b>Amplitude Y</b> can be used to scale the amount
	of fractal noise added to the projection in the Y direction.
	When Amplitude X and Amplitude Y are 0,
	no fractal noise is added.  Adding fractal noise is
	a way of randomizing or blurring the texture.
	*/
	void setAmplitudeY(const FloatID& ay){fprintf_s(mFile,"connectAttr \"");ay.write(mFile);fprintf_s(mFile,"\" \"%s.ay\";\n",mName.c_str());}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal noise (if there is any; see Amplitude
	X and Amplitude Y above).
	*/
	void setRatio(float ra){if(ra == 0.3) return; fprintf_s(mFile, "setAttr \".ra\" %f;\n", ra);}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal noise (if there is any; see Amplitude
	X and Amplitude Y above).
	*/
	void setRatio(const FloatID& ra){fprintf_s(mFile,"connectAttr \"");ra.write(mFile);fprintf_s(mFile,"\" \"%s.ra\";\n",mName.c_str());}
	/*Information bits passing along information about type of shading*/
	void setInfoBits(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*
	<b>Depth Wts</b> is the array of depth weights computed in projection
	node and passed on to texture composer for blending process
	*/
	void setDepWts(const FloatID& dwt){fprintf_s(mFile,"connectAttr \"");dwt.write(mFile);fprintf_s(mFile,"\" \"%s.dwt\";\n",mName.c_str());}
	/*
	<b>Angle Wts</b> is the array of angle weights computed in projection
	node and passed on to texture composer for blending process
	*/
	void setAngWts(const FloatID& awt){fprintf_s(mFile,"connectAttr \"");awt.write(mFile);fprintf_s(mFile,"\" \"%s.awt\";\n",mName.c_str());}
	/*Camera position in world space*/
	void setCamPos(const Float3ID& cpo){fprintf_s(mFile,"connectAttr \"");cpo.write(mFile);fprintf_s(mFile,"\" \"%s.cpo\";\n",mName.c_str());}
	/*Camera position in world space*/
	void setCamPsX(const FloatID& cpx){fprintf_s(mFile,"connectAttr \"");cpx.write(mFile);fprintf_s(mFile,"\" \"%s.cpo.cpx\";\n",mName.c_str());}
	/*Camera position in world space*/
	void setCamPsY(const FloatID& cpy){fprintf_s(mFile,"connectAttr \"");cpy.write(mFile);fprintf_s(mFile,"\" \"%s.cpo.cpy\";\n",mName.c_str());}
	/*Camera position in world space*/
	void setCamPsZ(const FloatID& cpz){fprintf_s(mFile,"connectAttr \"");cpz.write(mFile);fprintf_s(mFile,"\" \"%s.cpo.cpz\";\n",mName.c_str());}
	/*Camera angle in world space*/
	void setCamAg(const Float3ID& cag){fprintf_s(mFile,"connectAttr \"");cag.write(mFile);fprintf_s(mFile,"\" \"%s.cag\";\n",mName.c_str());}
	/*Camera angle in world space*/
	void setCamAngX(const FloatID& cax){fprintf_s(mFile,"connectAttr \"");cax.write(mFile);fprintf_s(mFile,"\" \"%s.cag.cax\";\n",mName.c_str());}
	/*Camera angle in world space*/
	void setCamAngY(const FloatID& cay){fprintf_s(mFile,"connectAttr \"");cay.write(mFile);fprintf_s(mFile,"\" \"%s.cag.cay\";\n",mName.c_str());}
	/*Camera angle in world space*/
	void setCamAngZ(const FloatID& caz){fprintf_s(mFile,"connectAttr \"");caz.write(mFile);fprintf_s(mFile,"\" \"%s.cag.caz\";\n",mName.c_str());}
	/*
	Pass through option to project paint on surfaces oriented towards
	and away from camera.
	*/
	void setPassTr(const BoolID& pst){fprintf_s(mFile,"connectAttr \"");pst.write(mFile);fprintf_s(mFile,"\" \"%s.pst\";\n",mName.c_str());}
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.uv.u\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.uv.v\";\n",mName.c_str());}
	/*Triangle s first vertex, in camera space*/
	void setVertexCameraOne(const float3& vc1){fprintf_s(mFile, "setAttr \".vc1\" -type \"float3\" ");vc1.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s first vertex, in camera space*/
	void setVertexCameraOne(const Float3ID& vc1){fprintf_s(mFile,"connectAttr \"");vc1.write(mFile);fprintf_s(mFile,"\" \"%s.vc1\";\n",mName.c_str());}
	/*X component of aVertexCameraOne*/
	void setVertexCameraOneX(float c1x){if(c1x == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1x\" %f;\n", c1x);}
	/*X component of aVertexCameraOne*/
	void setVertexCameraOneX(const FloatID& c1x){fprintf_s(mFile,"connectAttr \"");c1x.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1x\";\n",mName.c_str());}
	/*Y component of aVertexCameraOne*/
	void setVertexCameraOneY(float c1y){if(c1y == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1y\" %f;\n", c1y);}
	/*Y component of aVertexCameraOne*/
	void setVertexCameraOneY(const FloatID& c1y){fprintf_s(mFile,"connectAttr \"");c1y.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1y\";\n",mName.c_str());}
	/*Z component of aVertexCameraOne*/
	void setVertexCameraOneZ(float c1z){if(c1z == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1z\" %f;\n", c1z);}
	/*Z component of aVertexCameraOne*/
	void setVertexCameraOneZ(const FloatID& c1z){fprintf_s(mFile,"connectAttr \"");c1z.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1z\";\n",mName.c_str());}
	/*Triangle s second vertex, in camera space*/
	void setVertexCameraTwo(const float3& vc2){fprintf_s(mFile, "setAttr \".vc2\" -type \"float3\" ");vc2.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s second vertex, in camera space*/
	void setVertexCameraTwo(const Float3ID& vc2){fprintf_s(mFile,"connectAttr \"");vc2.write(mFile);fprintf_s(mFile,"\" \"%s.vc2\";\n",mName.c_str());}
	/*X component of aVertexCameraTwo*/
	void setVertexCameraTwoX(float c2x){if(c2x == 0.0) return; fprintf_s(mFile, "setAttr \".vc2.c2x\" %f;\n", c2x);}
	/*X component of aVertexCameraTwo*/
	void setVertexCameraTwoX(const FloatID& c2x){fprintf_s(mFile,"connectAttr \"");c2x.write(mFile);fprintf_s(mFile,"\" \"%s.vc2.c2x\";\n",mName.c_str());}
	/*Y component of aVertexCameraTwo*/
	void setVertexCameraTwoY(float c2y){if(c2y == 0.0) return; fprintf_s(mFile, "setAttr \".vc2.c2y\" %f;\n", c2y);}
	/*Y component of aVertexCameraTwo*/
	void setVertexCameraTwoY(const FloatID& c2y){fprintf_s(mFile,"connectAttr \"");c2y.write(mFile);fprintf_s(mFile,"\" \"%s.vc2.c2y\";\n",mName.c_str());}
	/*Z component of aVertexCameraTwo*/
	void setVertexCameraTwoZ(float c2z){if(c2z == 0.0) return; fprintf_s(mFile, "setAttr \".vc2.c2z\" %f;\n", c2z);}
	/*Z component of aVertexCameraTwo*/
	void setVertexCameraTwoZ(const FloatID& c2z){fprintf_s(mFile,"connectAttr \"");c2z.write(mFile);fprintf_s(mFile,"\" \"%s.vc2.c2z\";\n",mName.c_str());}
	/*Triangle s third vertex, in camera space*/
	void setVertexCameraThree(const float3& vc3){fprintf_s(mFile, "setAttr \".vc3\" -type \"float3\" ");vc3.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s third vertex, in camera space*/
	void setVertexCameraThree(const Float3ID& vc3){fprintf_s(mFile,"connectAttr \"");vc3.write(mFile);fprintf_s(mFile,"\" \"%s.vc3\";\n",mName.c_str());}
	/*X component of aVertexCameraThree*/
	void setVertexCameraThreeX(float c3x){if(c3x == 0.0) return; fprintf_s(mFile, "setAttr \".vc3.c3x\" %f;\n", c3x);}
	/*X component of aVertexCameraThree*/
	void setVertexCameraThreeX(const FloatID& c3x){fprintf_s(mFile,"connectAttr \"");c3x.write(mFile);fprintf_s(mFile,"\" \"%s.vc3.c3x\";\n",mName.c_str());}
	/*Y component of aVertexCameraThree*/
	void setVertexCameraThreeY(float c3y){if(c3y == 0.0) return; fprintf_s(mFile, "setAttr \".vc3.c3y\" %f;\n", c3y);}
	/*Y component of aVertexCameraThree*/
	void setVertexCameraThreeY(const FloatID& c3y){fprintf_s(mFile,"connectAttr \"");c3y.write(mFile);fprintf_s(mFile,"\" \"%s.vc3.c3y\";\n",mName.c_str());}
	/*Z component of aVertexCameraThree*/
	void setVertexCameraThreeZ(float c3z){if(c3z == 0.0) return; fprintf_s(mFile, "setAttr \".vc3.c3z\" %f;\n", c3z);}
	/*Z component of aVertexCameraThree*/
	void setVertexCameraThreeZ(const FloatID& c3z){fprintf_s(mFile,"connectAttr \"");c3z.write(mFile);fprintf_s(mFile,"\" \"%s.vc3.c3z\";\n",mName.c_str());}
	/*Triangle s first vertex, in texture space*/
	void setVertexUvOne(const float2& vt1){fprintf_s(mFile, "setAttr \".vt1\" -type \"float2\" ");vt1.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s first vertex, in texture space*/
	void setVertexUvOne(const Float2ID& vt1){fprintf_s(mFile,"connectAttr \"");vt1.write(mFile);fprintf_s(mFile,"\" \"%s.vt1\";\n",mName.c_str());}
	/*X component of aVertexUvOne*/
	void setVertexUvOneU(float t1u){if(t1u == 0.0) return; fprintf_s(mFile, "setAttr \".vt1.t1u\" %f;\n", t1u);}
	/*X component of aVertexUvOne*/
	void setVertexUvOneU(const FloatID& t1u){fprintf_s(mFile,"connectAttr \"");t1u.write(mFile);fprintf_s(mFile,"\" \"%s.vt1.t1u\";\n",mName.c_str());}
	/*Y component of aVertexUvOne*/
	void setVertexUvOneV(float t1v){if(t1v == 0.0) return; fprintf_s(mFile, "setAttr \".vt1.t1v\" %f;\n", t1v);}
	/*Y component of aVertexUvOne*/
	void setVertexUvOneV(const FloatID& t1v){fprintf_s(mFile,"connectAttr \"");t1v.write(mFile);fprintf_s(mFile,"\" \"%s.vt1.t1v\";\n",mName.c_str());}
	/*Triangle s first vertex, in texture space*/
	void setVertexUvTwo(const float2& vt2){fprintf_s(mFile, "setAttr \".vt2\" -type \"float2\" ");vt2.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s first vertex, in texture space*/
	void setVertexUvTwo(const Float2ID& vt2){fprintf_s(mFile,"connectAttr \"");vt2.write(mFile);fprintf_s(mFile,"\" \"%s.vt2\";\n",mName.c_str());}
	/*X component of aVertexUvTwo*/
	void setVertexUvTwoU(float t2u){if(t2u == 0.0) return; fprintf_s(mFile, "setAttr \".vt2.t2u\" %f;\n", t2u);}
	/*X component of aVertexUvTwo*/
	void setVertexUvTwoU(const FloatID& t2u){fprintf_s(mFile,"connectAttr \"");t2u.write(mFile);fprintf_s(mFile,"\" \"%s.vt2.t2u\";\n",mName.c_str());}
	/*Y component of aVertexUvTwo*/
	void setVertexUvTwoV(float t2v){if(t2v == 0.0) return; fprintf_s(mFile, "setAttr \".vt2.t2v\" %f;\n", t2v);}
	/*Y component of aVertexUvTwo*/
	void setVertexUvTwoV(const FloatID& t2v){fprintf_s(mFile,"connectAttr \"");t2v.write(mFile);fprintf_s(mFile,"\" \"%s.vt2.t2v\";\n",mName.c_str());}
	/*Triangle s first vertex, in texture space*/
	void setVertexUvThree(const float2& vt3){fprintf_s(mFile, "setAttr \".vt3\" -type \"float2\" ");vt3.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s first vertex, in texture space*/
	void setVertexUvThree(const Float2ID& vt3){fprintf_s(mFile,"connectAttr \"");vt3.write(mFile);fprintf_s(mFile,"\" \"%s.vt3\";\n",mName.c_str());}
	/*X component of aVertexUvThree*/
	void setVertexUvThreeU(float t3u){if(t3u == 0.0) return; fprintf_s(mFile, "setAttr \".vt3.t3u\" %f;\n", t3u);}
	/*X component of aVertexUvThree*/
	void setVertexUvThreeU(const FloatID& t3u){fprintf_s(mFile,"connectAttr \"");t3u.write(mFile);fprintf_s(mFile,"\" \"%s.vt3.t3u\";\n",mName.c_str());}
	/*Y component of aVertexUvThree*/
	void setVertexUvThreeV(float t3v){if(t3v == 0.0) return; fprintf_s(mFile, "setAttr \".vt3.t3v\" %f;\n", t3v);}
	/*Y component of aVertexUvThree*/
	void setVertexUvThreeV(const FloatID& t3v){fprintf_s(mFile,"connectAttr \"");t3v.write(mFile);fprintf_s(mFile,"\" \"%s.vt3.t3v\";\n",mName.c_str());}
	/*The sample (filter) size*/
	void setUvFilterSize(const Float2ID& uf){fprintf_s(mFile,"connectAttr \"");uf.write(mFile);fprintf_s(mFile,"\" \"%s.uf\";\n",mName.c_str());}
	/*The X size of the filter (sample)*/
	void setUvFilterSizeX(const FloatID& ufx){fprintf_s(mFile,"connectAttr \"");ufx.write(mFile);fprintf_s(mFile,"\" \"%s.uf.ufx\";\n",mName.c_str());}
	/*The Y size of the filter (sample)*/
	void setUvFilterSizeY(const FloatID& ufy){fprintf_s(mFile,"connectAttr \"");ufy.write(mFile);fprintf_s(mFile,"\" \"%s.uf.ufy\";\n",mName.c_str());}
	/*The surface tangent along U (dPdU)*/
	void setTangentUCamera(const Float3ID& tu){fprintf_s(mFile,"connectAttr \"");tu.write(mFile);fprintf_s(mFile,"\" \"%s.tu\";\n",mName.c_str());}
	/*The X component of the U tangent*/
	void setTangentUx(const FloatID& tux){fprintf_s(mFile,"connectAttr \"");tux.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tux\";\n",mName.c_str());}
	/*The Y component of the U tangent*/
	void setTangentUy(const FloatID& tuy){fprintf_s(mFile,"connectAttr \"");tuy.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tuy\";\n",mName.c_str());}
	/*The Z component of the U tangent*/
	void setTangentUz(const FloatID& tuz){fprintf_s(mFile,"connectAttr \"");tuz.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tuz\";\n",mName.c_str());}
	/*The surface tangent along V (dPdV)*/
	void setTangentVCamera(const Float3ID& tv){fprintf_s(mFile,"connectAttr \"");tv.write(mFile);fprintf_s(mFile,"\" \"%s.tv\";\n",mName.c_str());}
	/*The X component of the V tangent*/
	void setTangentVx(const FloatID& tvx){fprintf_s(mFile,"connectAttr \"");tvx.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvx\";\n",mName.c_str());}
	/*The Y component of the V tangent*/
	void setTangentVy(const FloatID& tvy){fprintf_s(mFile,"connectAttr \"");tvy.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvy\";\n",mName.c_str());}
	/*The Z component of the V tangent*/
	void setTangentVz(const FloatID& tvz){fprintf_s(mFile,"connectAttr \"");tvz.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvz\";\n",mName.c_str());}
	/*The input normal*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The X component of the input normal*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the input normal*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The Z component of the input normal*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*The input normal on the surface based on world matrix*/
	Float3ID getSrfNormal(){char buffer[4096];sprintf_s (buffer, "%s.srn",mName.c_str());return (const char*)buffer;}
	/*The X component of the input normal*/
	FloatID getSrfNormalX(){char buffer[4096];sprintf_s (buffer, "%s.srn.snx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the input normal*/
	FloatID getSrfNormalY(){char buffer[4096];sprintf_s (buffer, "%s.srn.sny",mName.c_str());return (const char*)buffer;}
	/*The Z component of the input normal*/
	FloatID getSrfNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.srn.snz",mName.c_str());return (const char*)buffer;}
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
	<b>Image</b>.  The Out Color attribute of a 2d texture
	should be connected to this attribute.  This is the
	texture that will be projected.
	*/
	Float3ID getImage(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*The red image value for the current sample*/
	FloatID getImageR(){char buffer[4096];sprintf_s (buffer, "%s.im.imr",mName.c_str());return (const char*)buffer;}
	/*The green image value for the current sample*/
	FloatID getImageG(){char buffer[4096];sprintf_s (buffer, "%s.im.img",mName.c_str());return (const char*)buffer;}
	/*The blue image value for the current sample*/
	FloatID getImageB(){char buffer[4096];sprintf_s (buffer, "%s.im.imb",mName.c_str());return (const char*)buffer;}
	/*
	<b>U Angle</b> controls how the input 2d texture is mapped
	around a circle, if you are using Spherical or Cylindrical
	texture mapping.  If U Angle is set to 90 degrees, that means
	that one instance of the texture is fit into each 90 degrees
	around the circle in the U direction.
	<p/>This attribute does nothing for other projection types.
	See also V Angle.
	*/
	DoubleID getUAngle(){char buffer[4096];sprintf_s (buffer, "%s.ua",mName.c_str());return (const char*)buffer;}
	/*
	<b>V Angle</b> controls how the input 2d texture is mapped
	around a circle, if you are using Spherical or Cylindrical
	texture mapping.  If V Angle is set to 90 degrees, that means
	that one instance of the texture is fit into each 90 degrees
	around the circle in the V direction.
	<p/>This attribute does nothing for other projection types.
	See also U Angle.
	*/
	DoubleID getVAngle(){char buffer[4096];sprintf_s (buffer, "%s.va",mName.c_str());return (const char*)buffer;}
	/*
	<b>Proj Type</b> controls how the 2d texture will be projected
	into 3d space.  The supported projection types are:
	<ul>
	<b>0. No Projection</b>: No projection is done.  Only the
	Default Color.is output.
	<p/><b>1. Planar</b>: Places the texture on a planar surface and
	projects it onto the object.
	<p/><b>2. Spherical</b>: Places the texture inside a sphere and
	projects it onto the object.  There will be two "pinch points",
	one at each of the poles of the sphere.
	<p/><b>3. Cylindrical</b>: Places the texture inside a cylinder and
	projects it onto the object.  There will be two "pinch points",
	one at each of the ends of the cylinder.
	<p/><b>4. Ball</b>: Places the texture inside a ball and
	projects it onto the object.  This is similar to the way that
	a candy wrapper is pulled around a lollipop.  There will be
	one "pinch points" at the Z-pole.
	<p/><b>5. Cubic</b>: Places the texture on six faces of a
	a cube, and projects them onto the object.
	<p/><b>6. TriPlanar</b>: Projects the texture by extruding it
	along the axis defined by the maximum current direction of the
	surface normal.  This is somewhat like fabric being wrapped around
	the object.
	<p/><b>7. Concentric</b>: Projects the texture by randomly selecting
	slices from it and making a concentric pattern from it.
	<p/><b>8. Perspective</b>:  Projects the texture by matching exactly
	the perspective of a particular camera.  To use this, you need to
	link the Projection node to a camera.  This type of projection is intended
	to be used to match modelled CGI to scanned backdrops.  To do this,
	use the same texture as a backdrop (put it on an Image Plane attached
	to the camera) and as a shader (use Perspective projection, and link
	the projection node to the same camera).  Objects in your scene using
	the shader will seem to disappear, since they will match the backdrop.
	You can then convert the object's shader to a solid texture, and
	animate the objects.
	For more detail on this process, see the rendering books.
	</ul>
	*/
	UnsignedintID getProjType(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*
	<b>Linked Camera</b> is a connection to a camera node.
	This is only used when Proj Type is set to Perspective.
	*/
	MessageID getLinkedCamera(){char buffer[4096];sprintf_s (buffer, "%s.lc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fit Type</b> controls how the texture will be fit to the camera when
	Proj type is set to Perspective.  If you are using this to match a backdrop,
	you should set this to match the setting in the Image Plane.
	<p/>
	Usually, you will have an image plane that is the same size as the rendered
	image.  If that is the case, you should use the Resolution Gate setting.
	<p/>You can also choose No Fit, which means that the image is not squeezed
	or stretched to fit.  One of its axes (determined by the Fit Fill attribute)
	will be fit to the filmgate, and the other will just be as big as it needs
	to.
	<p/>The third choice is Film Gate, which squeezes the image to fit the film gate.
	*/
	UnsignedintID getFitType(){char buffer[4096];sprintf_s (buffer, "%s.ft",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fit Fill</b> is only used if Proj Type is set to Perspective, and
	Fit Type is set to No Fit.  If the image plane aspect ratio is not
	the same as the filmgate aspect ratio, then this attribute decides
	which axis of the image is fit to the film gate.
	*/
	UnsignedintID getFitFill(){char buffer[4096];sprintf_s (buffer, "%s.ff",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ripples</b> determines how wavy the image will be when
	projected, but controlling the scale of the fundamental
	frequency of any fractal noise added to the texture.
	<p/>
	If you increase Ripples in any particular direction, the
	fractal detail will seem to smear out in that direction.
	<p/>
	This attribute will not do anything unless Amplitude X or
	Amplitude Y is non-zero.  (That is, there must be some
	fractal noise added to the system.)
	*/
	Float3ID getRipples(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The noise along X*/
	FloatID getRipplesX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*The noise along Y*/
	FloatID getRipplesY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*The noise along Z*/
	FloatID getRipplesZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Depth</b> controls
	how much calculation is done by this
	texture when Ripples are added.  Fractal noise such as ripples
	are created by an iterative
	mathematical process;  as the process goes over
	more levels, it produces a more detailed fractal,
	but takes longer to do so.  Normally, the texture
	will choose a level it thinks is appropriate for the
	volume being rendered.  You can use Depth Min and
	Depth Max to control the minimum and maximum amount
	of calculation that the texure will do.
	*/
	Float2ID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The minimum value for recursion depth*/
	FloatID getDepthMin(){char buffer[4096];sprintf_s (buffer, "%s.d.dmn",mName.c_str());return (const char*)buffer;}
	/*The maximum value for recursion depth*/
	FloatID getDepthMax(){char buffer[4096];sprintf_s (buffer, "%s.d.dmx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Amplitude X</b> can be used to scale the amount
	of fractal noise added to the projection in the X direction.
	When Amplitude X and Amplitude Y are 0,
	no fractal noise is added.  Adding fractal noise is
	a way of randomizing or blurring the texture.
	*/
	FloatID getAmplitudeX(){char buffer[4096];sprintf_s (buffer, "%s.ax",mName.c_str());return (const char*)buffer;}
	/*
	<b>Amplitude Y</b> can be used to scale the amount
	of fractal noise added to the projection in the Y direction.
	When Amplitude X and Amplitude Y are 0,
	no fractal noise is added.  Adding fractal noise is
	a way of randomizing or blurring the texture.
	*/
	FloatID getAmplitudeY(){char buffer[4096];sprintf_s (buffer, "%s.ay",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ratio</b> controls the frequency of the fractal
	noise.  Increase this value to increase the fineness of
	detail in the fractal noise (if there is any; see Amplitude
	X and Amplitude Y above).
	*/
	FloatID getRatio(){char buffer[4096];sprintf_s (buffer, "%s.ra",mName.c_str());return (const char*)buffer;}
	/*Information bits passing along information about type of shading*/
	IntID getInfoBits(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Depth Wts</b> is the array of depth weights computed in projection
	node and passed on to texture composer for blending process
	*/
	FloatID getDepWts(){char buffer[4096];sprintf_s (buffer, "%s.dwt",mName.c_str());return (const char*)buffer;}
	/*
	<b>Angle Wts</b> is the array of angle weights computed in projection
	node and passed on to texture composer for blending process
	*/
	FloatID getAngWts(){char buffer[4096];sprintf_s (buffer, "%s.awt",mName.c_str());return (const char*)buffer;}
	/*Camera position in world space*/
	Float3ID getCamPos(){char buffer[4096];sprintf_s (buffer, "%s.cpo",mName.c_str());return (const char*)buffer;}
	/*Camera position in world space*/
	FloatID getCamPsX(){char buffer[4096];sprintf_s (buffer, "%s.cpo.cpx",mName.c_str());return (const char*)buffer;}
	/*Camera position in world space*/
	FloatID getCamPsY(){char buffer[4096];sprintf_s (buffer, "%s.cpo.cpy",mName.c_str());return (const char*)buffer;}
	/*Camera position in world space*/
	FloatID getCamPsZ(){char buffer[4096];sprintf_s (buffer, "%s.cpo.cpz",mName.c_str());return (const char*)buffer;}
	/*Camera angle in world space*/
	Float3ID getCamAg(){char buffer[4096];sprintf_s (buffer, "%s.cag",mName.c_str());return (const char*)buffer;}
	/*Camera angle in world space*/
	FloatID getCamAngX(){char buffer[4096];sprintf_s (buffer, "%s.cag.cax",mName.c_str());return (const char*)buffer;}
	/*Camera angle in world space*/
	FloatID getCamAngY(){char buffer[4096];sprintf_s (buffer, "%s.cag.cay",mName.c_str());return (const char*)buffer;}
	/*Camera angle in world space*/
	FloatID getCamAngZ(){char buffer[4096];sprintf_s (buffer, "%s.cag.caz",mName.c_str());return (const char*)buffer;}
	/*
	Pass through option to project paint on surfaces oriented towards
	and away from camera.
	*/
	BoolID getPassTr(){char buffer[4096];sprintf_s (buffer, "%s.pst",mName.c_str());return (const char*)buffer;}
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.u",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.v",mName.c_str());return (const char*)buffer;}
	/*Triangle s first vertex, in camera space*/
	Float3ID getVertexCameraOne(){char buffer[4096];sprintf_s (buffer, "%s.vc1",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexCameraOne*/
	FloatID getVertexCameraOneX(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1x",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexCameraOne*/
	FloatID getVertexCameraOneY(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1y",mName.c_str());return (const char*)buffer;}
	/*Z component of aVertexCameraOne*/
	FloatID getVertexCameraOneZ(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1z",mName.c_str());return (const char*)buffer;}
	/*Triangle s second vertex, in camera space*/
	Float3ID getVertexCameraTwo(){char buffer[4096];sprintf_s (buffer, "%s.vc2",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexCameraTwo*/
	FloatID getVertexCameraTwoX(){char buffer[4096];sprintf_s (buffer, "%s.vc2.c2x",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexCameraTwo*/
	FloatID getVertexCameraTwoY(){char buffer[4096];sprintf_s (buffer, "%s.vc2.c2y",mName.c_str());return (const char*)buffer;}
	/*Z component of aVertexCameraTwo*/
	FloatID getVertexCameraTwoZ(){char buffer[4096];sprintf_s (buffer, "%s.vc2.c2z",mName.c_str());return (const char*)buffer;}
	/*Triangle s third vertex, in camera space*/
	Float3ID getVertexCameraThree(){char buffer[4096];sprintf_s (buffer, "%s.vc3",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexCameraThree*/
	FloatID getVertexCameraThreeX(){char buffer[4096];sprintf_s (buffer, "%s.vc3.c3x",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexCameraThree*/
	FloatID getVertexCameraThreeY(){char buffer[4096];sprintf_s (buffer, "%s.vc3.c3y",mName.c_str());return (const char*)buffer;}
	/*Z component of aVertexCameraThree*/
	FloatID getVertexCameraThreeZ(){char buffer[4096];sprintf_s (buffer, "%s.vc3.c3z",mName.c_str());return (const char*)buffer;}
	/*Triangle s first vertex, in texture space*/
	Float2ID getVertexUvOne(){char buffer[4096];sprintf_s (buffer, "%s.vt1",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvOne*/
	FloatID getVertexUvOneU(){char buffer[4096];sprintf_s (buffer, "%s.vt1.t1u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvOne*/
	FloatID getVertexUvOneV(){char buffer[4096];sprintf_s (buffer, "%s.vt1.t1v",mName.c_str());return (const char*)buffer;}
	/*Triangle s first vertex, in texture space*/
	Float2ID getVertexUvTwo(){char buffer[4096];sprintf_s (buffer, "%s.vt2",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvTwo*/
	FloatID getVertexUvTwoU(){char buffer[4096];sprintf_s (buffer, "%s.vt2.t2u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvTwo*/
	FloatID getVertexUvTwoV(){char buffer[4096];sprintf_s (buffer, "%s.vt2.t2v",mName.c_str());return (const char*)buffer;}
	/*Triangle s first vertex, in texture space*/
	Float2ID getVertexUvThree(){char buffer[4096];sprintf_s (buffer, "%s.vt3",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvThree*/
	FloatID getVertexUvThreeU(){char buffer[4096];sprintf_s (buffer, "%s.vt3.t3u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvThree*/
	FloatID getVertexUvThreeV(){char buffer[4096];sprintf_s (buffer, "%s.vt3.t3v",mName.c_str());return (const char*)buffer;}
	/*The sample (filter) size*/
	Float2ID getUvFilterSize(){char buffer[4096];sprintf_s (buffer, "%s.uf",mName.c_str());return (const char*)buffer;}
	/*The X size of the filter (sample)*/
	FloatID getUvFilterSizeX(){char buffer[4096];sprintf_s (buffer, "%s.uf.ufx",mName.c_str());return (const char*)buffer;}
	/*The Y size of the filter (sample)*/
	FloatID getUvFilterSizeY(){char buffer[4096];sprintf_s (buffer, "%s.uf.ufy",mName.c_str());return (const char*)buffer;}
	/*The surface tangent along U (dPdU)*/
	Float3ID getTangentUCamera(){char buffer[4096];sprintf_s (buffer, "%s.tu",mName.c_str());return (const char*)buffer;}
	/*The X component of the U tangent*/
	FloatID getTangentUx(){char buffer[4096];sprintf_s (buffer, "%s.tu.tux",mName.c_str());return (const char*)buffer;}
	/*The Y component of the U tangent*/
	FloatID getTangentUy(){char buffer[4096];sprintf_s (buffer, "%s.tu.tuy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the U tangent*/
	FloatID getTangentUz(){char buffer[4096];sprintf_s (buffer, "%s.tu.tuz",mName.c_str());return (const char*)buffer;}
	/*The surface tangent along V (dPdV)*/
	Float3ID getTangentVCamera(){char buffer[4096];sprintf_s (buffer, "%s.tv",mName.c_str());return (const char*)buffer;}
	/*The X component of the V tangent*/
	FloatID getTangentVx(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the V tangent*/
	FloatID getTangentVy(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the V tangent*/
	FloatID getTangentVz(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvz",mName.c_str());return (const char*)buffer;}
protected:
	Projection(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PROJECTION_H__
