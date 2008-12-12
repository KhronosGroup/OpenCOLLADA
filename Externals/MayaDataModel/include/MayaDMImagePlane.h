/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IMAGEPLANE_H__
#define __MayaDM_IMAGEPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Image Plane</b> is an object in the scene that can display
 images or textures.  Each image plane is attached to a
 specific camera, and provides a background or environment for
 scenes seen through that camera.
 <p/>
 A single camera can have multiple image planes.  And a single
 image plane can be attached to more than one camera.
 <p/>
 Image planes can use single image files, a numbered sequence of image
 files (such as a saved animation), or a movie file, or a texture.  Environment
 maps (such as Env Sky or Env Ball) work particularly well on image
 planes.
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class ImagePlane : public DependNode
{
public:
public:
	ImagePlane(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "imagePlane"){}
	virtual ~ImagePlane(){}
	/*
	<b>Type</b> controls the source of the image on the
	Image plane.  Allowed values are <b>Image File</b> and
	<b>Texture</b>.  Some attributes are not available when
	using the Texture setting.
	*/
	void setType(unsigned int t){if(t == 0) return; fprintf_s(mFile, "setAttr \".t\" %i;\n", t);}
	/*
	<b>Type</b> controls the source of the image on the
	Image plane.  Allowed values are <b>Image File</b> and
	<b>Texture</b>.  Some attributes are not available when
	using the Texture setting.
	*/
	void setType(const UnsignedintID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*
	<b>Image Name</b> is only used if Type is set to Image File.
	Set this attribute to the file name of the image to be used
	in the image plane.  If you want to use a sequence of images
	(such as a saved animation) then set this to the name of the first
	file in the sequence.  (see also Use Frame Extension and Frame
	Extension).
	<p/>
	You can also specify a movie file here.  Maya can use SGI
	movie files using one of these compressions:  Uncompressed Video,
	RLE, RLE24, JPEG, MVC1, or MVC2.  Maya can also use QuickTime
	movie files using one of these compressions: Uncompressed Video,
	QuickTime Video, QuickTime Animation, or Indeo.  If you specify
	a movie file, you must use the Frame Extension attributes.
	*/
	void setImageName(const string& imn){if(imn == "NULL") return; fprintf_s(mFile, "setAttr \".imn\" -type \"string\" ");imn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Image Name</b> is only used if Type is set to Image File.
	Set this attribute to the file name of the image to be used
	in the image plane.  If you want to use a sequence of images
	(such as a saved animation) then set this to the name of the first
	file in the sequence.  (see also Use Frame Extension and Frame
	Extension).
	<p/>
	You can also specify a movie file here.  Maya can use SGI
	movie files using one of these compressions:  Uncompressed Video,
	RLE, RLE24, JPEG, MVC1, or MVC2.  Maya can also use QuickTime
	movie files using one of these compressions: Uncompressed Video,
	QuickTime Video, QuickTime Animation, or Indeo.  If you specify
	a movie file, you must use the Frame Extension attributes.
	*/
	void setImageName(const StringID& imn){fprintf_s(mFile,"connectAttr \"");imn.write(mFile);fprintf_s(mFile,"\" \"%s.imn\";\n",mName.c_str());}
	/*
	<b>Use Frame Extension</b>.  Turn this ON when you are
	using a sequence of image files (such as a saved animation)
	for the image plane, or if you are using an SGI or QuickTime
	movie file.  When this is on, the system will
	substitute the frame number in the Image Name with
	the number from the Frame Extension attribute (see below).
	*/
	void setUseFrameExtension(bool ufe){if(ufe == false) return; fprintf_s(mFile, "setAttr \".ufe\" %i;\n", ufe);}
	/*
	<b>Use Frame Extension</b>.  Turn this ON when you are
	using a sequence of image files (such as a saved animation)
	for the image plane, or if you are using an SGI or QuickTime
	movie file.  When this is on, the system will
	substitute the frame number in the Image Name with
	the number from the Frame Extension attribute (see below).
	*/
	void setUseFrameExtension(const BoolID& ufe){fprintf_s(mFile,"connectAttr \"");ufe.write(mFile);fprintf_s(mFile,"\" \"%s.ufe\";\n",mName.c_str());}
	/*
	<b>Frame Extension</b>.  This is only used when Use Frame
	Extension is ON.  The frame extension in Image Name is
	replaced by the number here.  Animate this attribute
	to use a sequence of image files (such as a saved animation)
	in the image plane.
	<p/>
	<b>Example:</b> say you have saved images named "pic.1.iff"
	up to "pic.99.iff".  You want them to show on the image plane
	between frames 100 and 300 of your animation.  To do this:
	<ul>
	<li>Set Image Name to "pic.1.iff"</li>
	<li>Turn Frame Extension ON.</li>
	<li>Go to frame 100.  Set Frame Extension to 1.  Keyframe it.</li>
	<li>Go to frame 300.  Set Frame Extension to 99.  Keyframe it.</li>
	</ul>
	<p/><b>Tip:</b> You can also use an expression for this
	attribute.  For example, if you want the frame number of the
	image to always be the same as the current frame number,
	then just type "=frame" into the Frame Extension field
	in the attribute editor.
	*/
	void setFrameExtension(int fe){if(fe == 1) return; fprintf_s(mFile, "setAttr \".fe\" %i;\n", fe);}
	/*
	<b>Frame Extension</b>.  This is only used when Use Frame
	Extension is ON.  The frame extension in Image Name is
	replaced by the number here.  Animate this attribute
	to use a sequence of image files (such as a saved animation)
	in the image plane.
	<p/>
	<b>Example:</b> say you have saved images named "pic.1.iff"
	up to "pic.99.iff".  You want them to show on the image plane
	between frames 100 and 300 of your animation.  To do this:
	<ul>
	<li>Set Image Name to "pic.1.iff"</li>
	<li>Turn Frame Extension ON.</li>
	<li>Go to frame 100.  Set Frame Extension to 1.  Keyframe it.</li>
	<li>Go to frame 300.  Set Frame Extension to 99.  Keyframe it.</li>
	</ul>
	<p/><b>Tip:</b> You can also use an expression for this
	attribute.  For example, if you want the frame number of the
	image to always be the same as the current frame number,
	then just type "=frame" into the Frame Extension field
	in the attribute editor.
	*/
	void setFrameExtension(const IntID& fe){fprintf_s(mFile,"connectAttr \"");fe.write(mFile);fprintf_s(mFile,"\" \"%s.fe\";\n",mName.c_str());}
	/*
	Specifies an offset of the keyed Frame Extension value.
	This attribute is only meaningful if Use Frame Extension is turned on.
	*/
	void setFrameOffset(int fo){if(fo == 0) return; fprintf_s(mFile, "setAttr \".fo\" %i;\n", fo);}
	/*
	Specifies an offset of the keyed Frame Extension value.
	This attribute is only meaningful if Use Frame Extension is turned on.
	*/
	void setFrameOffset(const IntID& fo){fprintf_s(mFile,"connectAttr \"");fo.write(mFile);fprintf_s(mFile,"\" \"%s.fo\";\n",mName.c_str());}
	/*
	<b>Coverage</b> controls the amount of the image that
	will be used in the image plane.  This is only used when
	the Type is set to Image File.  The coverage is measured
	in pixels.  You can specify how many horizontal and vertical
	pixels of the source image will be used.  See also
	Coverage Origin (below).
	*/
	void setCoverage(const short2& cov){if(cov == short2(1, 1)) return; fprintf_s(mFile, "setAttr \".cov\" -type \"short2\" ");cov.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Coverage</b> controls the amount of the image that
	will be used in the image plane.  This is only used when
	the Type is set to Image File.  The coverage is measured
	in pixels.  You can specify how many horizontal and vertical
	pixels of the source image will be used.  See also
	Coverage Origin (below).
	*/
	void setCoverage(const Short2ID& cov){fprintf_s(mFile,"connectAttr \"");cov.write(mFile);fprintf_s(mFile,"\" \"%s.cov\";\n",mName.c_str());}
	/*
	Coverage X:  The width in pixels of the area on the
	source image to be used.
	*/
	void setCoverageX(short cvx){if(cvx == 0) return; fprintf_s(mFile, "setAttr \".cov.cvx\" %i;\n", cvx);}
	/*
	Coverage X:  The width in pixels of the area on the
	source image to be used.
	*/
	void setCoverageX(const ShortID& cvx){fprintf_s(mFile,"connectAttr \"");cvx.write(mFile);fprintf_s(mFile,"\" \"%s.cov.cvx\";\n",mName.c_str());}
	/*
	Coverage Y:  The height in pixels of the area on the
	source image to be used.
	*/
	void setCoverageY(short cvy){if(cvy == 0) return; fprintf_s(mFile, "setAttr \".cov.cvy\" %i;\n", cvy);}
	/*
	Coverage Y:  The height in pixels of the area on the
	source image to be used.
	*/
	void setCoverageY(const ShortID& cvy){fprintf_s(mFile,"connectAttr \"");cvy.write(mFile);fprintf_s(mFile,"\" \"%s.cov.cvy\";\n",mName.c_str());}
	/*
	<b>Coverage Origin</b> controls the lower-left-corner
	of the area of the input image that will be used on the
	image plane.  0, 0, is the lower-left corner of the image.
	See also Coverage (above)
	*/
	void setCoverageOrigin(const short2& co){if(co == short2(0, 0)) return; fprintf_s(mFile, "setAttr \".co\" -type \"short2\" ");co.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Coverage Origin</b> controls the lower-left-corner
	of the area of the input image that will be used on the
	image plane.  0, 0, is the lower-left corner of the image.
	See also Coverage (above)
	*/
	void setCoverageOrigin(const Short2ID& co){fprintf_s(mFile,"connectAttr \"");co.write(mFile);fprintf_s(mFile,"\" \"%s.co\";\n",mName.c_str());}
	/*
	Coverage Origin X:  The pixel position of the left edge of
	the area of the source image to be used.
	*/
	void setCoverageOriginX(short cox){if(cox == 0) return; fprintf_s(mFile, "setAttr \".co.cox\" %i;\n", cox);}
	/*
	Coverage Origin X:  The pixel position of the left edge of
	the area of the source image to be used.
	*/
	void setCoverageOriginX(const ShortID& cox){fprintf_s(mFile,"connectAttr \"");cox.write(mFile);fprintf_s(mFile,"\" \"%s.co.cox\";\n",mName.c_str());}
	/*
	Coverage Origin Y:  The pixel position of the bottom edge of
	the area of the source image to be used.
	*/
	void setCoverageOriginY(short coy){if(coy == 0) return; fprintf_s(mFile, "setAttr \".co.coy\" %i;\n", coy);}
	/*
	Coverage Origin Y:  The pixel position of the bottom edge of
	the area of the source image to be used.
	*/
	void setCoverageOriginY(const ShortID& coy){fprintf_s(mFile,"connectAttr \"");coy.write(mFile);fprintf_s(mFile,"\" \"%s.co.coy\";\n",mName.c_str());}
	/*
	<b>Source Texture</b>.  If the Type attribute is set to
	Texture, then this attribute is connected to the texture
	node used by the image plane.  Note that the Texture node
	must have an attribute named Out Color.
	*/
	void setSourceTexture(const MessageID& stx){fprintf_s(mFile,"connectAttr \"");stx.write(mFile);fprintf_s(mFile,"\" \"%s.stx\";\n",mName.c_str());}
	/*
	<b>Fit</b> controls how the image file will be fit
	into the image plane.  If the image file being used has
	the same aspect ratio as the image plane (determined by
	the Size attribute), then there is no problem; the image
	will fit exactly without any squashing or stretching.  If
	the aspect ratios don't match,
	then this attribute determines which fitting algorithm
	will be used.  Choices are:
	<ul>
	<b>Fill:</b> The image will be made as small as it can
	while still completely filling the image plane.  Whatever
	excess hangs off the sides or the top and bottom will be cropped.
	Fill guarantees that the image will completely fill the plane,
	without being squashed or stretched.
	<p/>
	<b>Best:</b> The image will be made as large as it can
	be, while still fitting completely within the defined image plane.
	(Effectively, this is the same as chooing Horizontal or Vertical, whichever one
	will result in no part of the image being cropped).  Best
	guarantees that you will see the entire image, with no
	cropping and no squashing or stretching.
	<p/><b>Horizontal:</b> The image is sized so that its horizontal
	dimension exactly fits the horizontal dimension of the image
	plane.  The image keeps its own aspect ratio. Horizontal fit
	will crop the top and bottom of the image to make it fit.
	<p/><b>Vertical:</b> The image is sized so that its vertical
	dimension exactly fits the vertical dimension of the image
	plane.  The image keeps its own aspect ratio. Vertical fit
	will crop the left and right sides of the image to make it fit.
	<p/><b>To Size</b>:  The image is squashed or stretched, forced
	to fit into the image plane both horizontally and vertically.
	</ul>
	*/
	void setFit(unsigned int f){if(f == 1) return; fprintf_s(mFile, "setAttr \".f\" %i;\n", f);}
	/*
	<b>Fit</b> controls how the image file will be fit
	into the image plane.  If the image file being used has
	the same aspect ratio as the image plane (determined by
	the Size attribute), then there is no problem; the image
	will fit exactly without any squashing or stretching.  If
	the aspect ratios don't match,
	then this attribute determines which fitting algorithm
	will be used.  Choices are:
	<ul>
	<b>Fill:</b> The image will be made as small as it can
	while still completely filling the image plane.  Whatever
	excess hangs off the sides or the top and bottom will be cropped.
	Fill guarantees that the image will completely fill the plane,
	without being squashed or stretched.
	<p/>
	<b>Best:</b> The image will be made as large as it can
	be, while still fitting completely within the defined image plane.
	(Effectively, this is the same as chooing Horizontal or Vertical, whichever one
	will result in no part of the image being cropped).  Best
	guarantees that you will see the entire image, with no
	cropping and no squashing or stretching.
	<p/><b>Horizontal:</b> The image is sized so that its horizontal
	dimension exactly fits the horizontal dimension of the image
	plane.  The image keeps its own aspect ratio. Horizontal fit
	will crop the top and bottom of the image to make it fit.
	<p/><b>Vertical:</b> The image is sized so that its vertical
	dimension exactly fits the vertical dimension of the image
	plane.  The image keeps its own aspect ratio. Vertical fit
	will crop the left and right sides of the image to make it fit.
	<p/><b>To Size</b>:  The image is squashed or stretched, forced
	to fit into the image plane both horizontally and vertically.
	</ul>
	*/
	void setFit(const UnsignedintID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*
	<b>Display Mode</b> controls how the image plane will be displayed
	both in the 3d view, and when rendered.  Choices are:
	<ul>
	<b>None:</b> The image plane is not shown.
	<p/><b>Outline:</b> The image plane is displayed as a
	rectangle with an X through it.  (If you render in this
	mode, the image plane will show up as though it were in RGB mode)
	<p/><b>RGB:</b> The image is displayed.  Any alpha channel
	(transparency) is ignored.  If you are displaying an SGI or
	QuickTime movie file with no alpha channel, you should use
	this setting.
	<p/><b>RGBA:</b> The image is displayed. The alpha channel controls
	the transparency of the image.  (Areas where the alpha channel
	are brighter are more opaque)
	<p/><b>Luminance:</b> The image is diplayed in
	greyscale, like a black-and-white television.  Transparency
	(alpha) is ignored.
	<p/><b>Alpha:</b> The alpha (transparency) channel is displayed
	as a monochrome image.
	</ul>
	*/
	void setDisplayMode(unsigned int dm){if(dm == 3) return; fprintf_s(mFile, "setAttr \".dm\" %i;\n", dm);}
	/*
	<b>Display Mode</b> controls how the image plane will be displayed
	both in the 3d view, and when rendered.  Choices are:
	<ul>
	<b>None:</b> The image plane is not shown.
	<p/><b>Outline:</b> The image plane is displayed as a
	rectangle with an X through it.  (If you render in this
	mode, the image plane will show up as though it were in RGB mode)
	<p/><b>RGB:</b> The image is displayed.  Any alpha channel
	(transparency) is ignored.  If you are displaying an SGI or
	QuickTime movie file with no alpha channel, you should use
	this setting.
	<p/><b>RGBA:</b> The image is displayed. The alpha channel controls
	the transparency of the image.  (Areas where the alpha channel
	are brighter are more opaque)
	<p/><b>Luminance:</b> The image is diplayed in
	greyscale, like a black-and-white television.  Transparency
	(alpha) is ignored.
	<p/><b>Alpha:</b> The alpha (transparency) channel is displayed
	as a monochrome image.
	</ul>
	*/
	void setDisplayMode(const UnsignedintID& dm){fprintf_s(mFile,"connectAttr \"");dm.write(mFile);fprintf_s(mFile,"\" \"%s.dm\";\n",mName.c_str());}
	/*
	<b>Display Only If Current</b>.  If this is turned on,
	then you will only see the image plane when you are looking
	through the camera that the plane is attached to.
	<p/>
	For example, if you attach an image plane to your perspective
	camera, and you don't want to see it in your ortho views, turn
	this attribute ON.
	*/
	void setDisplayOnlyIfCurrent(bool dic){if(dic == false) return; fprintf_s(mFile, "setAttr \".dic\" %i;\n", dic);}
	/*
	<b>Display Only If Current</b>.  If this is turned on,
	then you will only see the image plane when you are looking
	through the camera that the plane is attached to.
	<p/>
	For example, if you attach an image plane to your perspective
	camera, and you don't want to see it in your ortho views, turn
	this attribute ON.
	*/
	void setDisplayOnlyIfCurrent(const BoolID& dic){fprintf_s(mFile,"connectAttr \"");dic.write(mFile);fprintf_s(mFile,"\" \"%s.dic\";\n",mName.c_str());}
	/*
	<b>Color Gain</b> is a multiplier applied to the colors
	in the image plane.  Use this to control the relative brightness
	of the image.
	*/
	void setColorGain(const float3& cg){if(cg == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".cg\" -type \"float3\" ");cg.write(mFile);fprintf_s(mFile,";\n");}
	/*The red component of Color Gain*/
	void setColorGainR(float cgr){if(cgr == 0.0) return; fprintf_s(mFile, "setAttr \".cg.cgr\" %f;\n", cgr);}
	/*The green component of Color Gain*/
	void setColorGainG(float cgg){if(cgg == 0.0) return; fprintf_s(mFile, "setAttr \".cg.cgg\" %f;\n", cgg);}
	/*The blue component of Color Gain*/
	void setColorGainB(float cgb){if(cgb == 0.0) return; fprintf_s(mFile, "setAttr \".cg.cgb\" %f;\n", cgb);}
	/*
	<b>Color Offset</b> is an additive value applied to the
	colors in the image plane.  Increase this to make the
	whole image uniformly brighter.
	*/
	void setColorOffset(const float3& cof){if(cof == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".cof\" -type \"float3\" ");cof.write(mFile);fprintf_s(mFile,";\n");}
	/*The red component of Color Offset*/
	void setColorOffsetR(float cor){if(cor == 0.0) return; fprintf_s(mFile, "setAttr \".cof.cor\" %f;\n", cor);}
	/*The green component of Color Offset*/
	void setColorOffsetG(float cog){if(cog == 0.0) return; fprintf_s(mFile, "setAttr \".cof.cog\" %f;\n", cog);}
	/*The blue component of Color Offset*/
	void setColorOffsetB(float cob){if(cob == 0.0) return; fprintf_s(mFile, "setAttr \".cof.cob\" %f;\n", cob);}
	/*
	<b>Alpha Gain</b> is a multiplier that is applied to
	the alpha value.  Increase this to make the semi-transparent
	areas of the image more opaque.  Decrease this to make
	them more transparent.
	*/
	void setAlphaGain(double ag){if(ag == 1.0) return; fprintf_s(mFile, "setAttr \".ag\" %f;\n", ag);}
	/*
	<b>Alpha Gain</b> is a multiplier that is applied to
	the alpha value.  Increase this to make the semi-transparent
	areas of the image more opaque.  Decrease this to make
	them more transparent.
	*/
	void setAlphaGain(const DoubleID& ag){fprintf_s(mFile,"connectAttr \"");ag.write(mFile);fprintf_s(mFile,"\" \"%s.ag\";\n",mName.c_str());}
	/*The flag to control if this surface should override global shading sample settings.*/
	void setShadingSamplesOverride(bool sso){if(sso == true) return; fprintf_s(mFile, "setAttr \".sso\" %i;\n", sso);}
	/*The flag to control if this surface should override global shading sample settings.*/
	void setShadingSamplesOverride(const BoolID& sso){fprintf_s(mFile,"connectAttr \"");sso.write(mFile);fprintf_s(mFile,"\" \"%s.sso\";\n",mName.c_str());}
	/*Specifies the minimum number of shading samples should be taken for this surface during rendering.*/
	void setShadingSamples(int ssa){if(ssa == 1) return; fprintf_s(mFile, "setAttr \".ssa\" %i;\n", ssa);}
	/*Specifies the minimum number of shading samples should be taken for this surface during rendering.*/
	void setShadingSamples(const IntID& ssa){fprintf_s(mFile,"connectAttr \"");ssa.write(mFile);fprintf_s(mFile,"\" \"%s.ssa\";\n",mName.c_str());}
	/*Specifies the max number of shading samples can be taken for this surface during rendering.*/
	void setMaxShadingSamples(int msa){if(msa == 1) return; fprintf_s(mFile, "setAttr \".msa\" %i;\n", msa);}
	/*Specifies the max number of shading samples can be taken for this surface during rendering.*/
	void setMaxShadingSamples(const IntID& msa){fprintf_s(mFile,"connectAttr \"");msa.write(mFile);fprintf_s(mFile,"\" \"%s.msa\";\n",mName.c_str());}
	/*
	<b>Locked To Camera</b>.  If this is turned on, then the
	image plane is locked to the camera's position, so that as
	the camera moves, the image plane moves with it.  If this
	is turned off, the image plane stays in a fixed location,
	but it still always faces the camera.  This is normally turned
	on.
	<p/>
	<b>Tip:</b> Use this attribute to trace images.  Attach an
	image plane to an ortho camera, and load an image into it.
	Then turn off Locked to Camera.  Now you can use tools such
	as the Maya curve tool to trace what's in the image.  You
	can pan around and zoom in and out as you need to.
	*/
	void setLockedToCamera(bool dlc){if(dlc == true) return; fprintf_s(mFile, "setAttr \".dlc\" %i;\n", dlc);}
	/*
	<b>Locked To Camera</b>.  If this is turned on, then the
	image plane is locked to the camera's position, so that as
	the camera moves, the image plane moves with it.  If this
	is turned off, the image plane stays in a fixed location,
	but it still always faces the camera.  This is normally turned
	on.
	<p/>
	<b>Tip:</b> Use this attribute to trace images.  Attach an
	image plane to an ortho camera, and load an image into it.
	Then turn off Locked to Camera.  Now you can use tools such
	as the Maya curve tool to trace what's in the image.  You
	can pan around and zoom in and out as you need to.
	*/
	void setLockedToCamera(const BoolID& dlc){fprintf_s(mFile,"connectAttr \"");dlc.write(mFile);fprintf_s(mFile,"\" \"%s.dlc\";\n",mName.c_str());}
	/*
	<b>Depth</b> controls the distance of the plane from the camera.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	void setDepth(double d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	<b>Depth</b> controls the distance of the plane from the camera.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	void setDepth(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	<b>Squeeze Correction</b> applies a horizontal scaling to
	an image.  Increase Squeeze Correction to squeeze the
	image more, and descrease it to spread the image wider.
	<p/>This can be useful when your background images
	were scanned in from film that
	was shot using an anamorphic film format, such as Panavision.
	Set Squeeze Correction to 0.5, and the compressed film
	images will be expanded to twice their width.
	*/
	void setSqueezeCorrection(double sqc){if(sqc == 1.0) return; fprintf_s(mFile, "setAttr \".sqc\" %f;\n", sqc);}
	/*
	<b>Squeeze Correction</b> applies a horizontal scaling to
	an image.  Increase Squeeze Correction to squeeze the
	image more, and descrease it to spread the image wider.
	<p/>This can be useful when your background images
	were scanned in from film that
	was shot using an anamorphic film format, such as Panavision.
	Set Squeeze Correction to 0.5, and the compressed film
	images will be expanded to twice their width.
	*/
	void setSqueezeCorrection(const DoubleID& sqc){fprintf_s(mFile,"connectAttr \"");sqc.write(mFile);fprintf_s(mFile,"\" \"%s.sqc\";\n",mName.c_str());}
	/*
	<b>Size</b> controls the width and height of the image plane.
	This attribute is only meaningful when Locked To Camera is on.
	<p/><b>Note:</b> Size is always measured in inches, so matter what
	your current units are set to.  It is measured on the camera's
	aperture.
	*/
	void setSize(const double2& s){if(s == double2(3.6, 2.4)) return; fprintf_s(mFile, "setAttr \".s\" -type \"double2\" ");s.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Size</b> controls the width and height of the image plane.
	This attribute is only meaningful when Locked To Camera is on.
	<p/><b>Note:</b> Size is always measured in inches, so matter what
	your current units are set to.  It is measured on the camera's
	aperture.
	*/
	void setSize(const Double2ID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Size X:  Image plane width*/
	void setSizeX(double sx){if(sx == 0.0) return; fprintf_s(mFile, "setAttr \".s.sx\" %f;\n", sx);}
	/*Size X:  Image plane width*/
	void setSizeX(const DoubleID& sx){fprintf_s(mFile,"connectAttr \"");sx.write(mFile);fprintf_s(mFile,"\" \"%s.s.sx\";\n",mName.c_str());}
	/*Size Y: Image plane height.*/
	void setSizeY(double sy){if(sy == 0.0) return; fprintf_s(mFile, "setAttr \".s.sy\" %f;\n", sy);}
	/*Size Y: Image plane height.*/
	void setSizeY(const DoubleID& sy){fprintf_s(mFile,"connectAttr \"");sy.write(mFile);fprintf_s(mFile,"\" \"%s.s.sy\";\n",mName.c_str());}
	/*
	<b>Offset</b> controls how much the center of the image
	plane is offset from the centre of the viewing frustum
	of the camera.  Offset is always measured in inches
	on the camera aperture.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	void setOffset(const double2& o){if(o == double2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".o\" -type \"double2\" ");o.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Offset</b> controls how much the center of the image
	plane is offset from the centre of the viewing frustum
	of the camera.  Offset is always measured in inches
	on the camera aperture.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	void setOffset(const Double2ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Horizontal component of Offset*/
	void setOffsetX(double ox){if(ox == 0.0) return; fprintf_s(mFile, "setAttr \".o.ox\" %f;\n", ox);}
	/*Horizontal component of Offset*/
	void setOffsetX(const DoubleID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*Vertical component of Offset*/
	void setOffsetY(double oy){if(oy == 0.0) return; fprintf_s(mFile, "setAttr \".o.oy\" %f;\n", oy);}
	/*Vertical component of Offset*/
	void setOffsetY(const DoubleID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*
	<b>Center</b> controls the world-space position of the center
	of the image plane.  This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	void setCenter(const double3& c){if(c == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c\" -type \"double3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Center</b> controls the world-space position of the center
	of the image plane.  This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	void setCenter(const Double3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*X component of Center*/
	void setCenterX(double cx){if(cx == 0) return; fprintf_s(mFile, "setAttr \".c.cx\" %f;\n", cx);}
	/*X component of Center*/
	void setCenterX(const DoubleID& cx){fprintf_s(mFile,"connectAttr \"");cx.write(mFile);fprintf_s(mFile,"\" \"%s.c.cx\";\n",mName.c_str());}
	/*Y component of Center*/
	void setCenterY(double cy){if(cy == 0) return; fprintf_s(mFile, "setAttr \".c.cy\" %f;\n", cy);}
	/*Y component of Center*/
	void setCenterY(const DoubleID& cy){fprintf_s(mFile,"connectAttr \"");cy.write(mFile);fprintf_s(mFile,"\" \"%s.c.cy\";\n",mName.c_str());}
	/*Z component of Center*/
	void setCenterZ(double cz){if(cz == 0) return; fprintf_s(mFile, "setAttr \".c.cz\" %f;\n", cz);}
	/*Z component of Center*/
	void setCenterZ(const DoubleID& cz){fprintf_s(mFile,"connectAttr \"");cz.write(mFile);fprintf_s(mFile,"\" \"%s.c.cz\";\n",mName.c_str());}
	/*
	<b>Width</b> controls the width of the image plane in world space.
	This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	void setWidth(double w){if(w == 0) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*
	<b>Width</b> controls the width of the image plane in world space.
	This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	void setWidth(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*
	<b>Height</b> controls the height of the image plane in world space.
	This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	void setHeight(double h){if(h == 0) return; fprintf_s(mFile, "setAttr \".h\" %f;\n", h);}
	/*
	<b>Height</b> controls the height of the image plane in world space.
	This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	void setHeight(const DoubleID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*
	<b>Visible In Reflections</b>.  Turn this on if you are
	doing Ray Tracing, and you want the image plane to sppear
	in reflected surfaces.
	*/
	void setVisibleInReflections(bool vir){if(vir == false) return; fprintf_s(mFile, "setAttr \".vir\" %i;\n", vir);}
	/*
	<b>Visible In Reflections</b>.  Turn this on if you are
	doing Ray Tracing, and you want the image plane to sppear
	in reflected surfaces.
	*/
	void setVisibleInReflections(const BoolID& vir){fprintf_s(mFile,"connectAttr \"");vir.write(mFile);fprintf_s(mFile,"\" \"%s.vir\";\n",mName.c_str());}
	/*
	<b>Visible In Refractions</b>.  Turn this on if you are
	doing Ray Tracing, and you want the image plane to sppear
	when seen through a transparent refractive surface.
	*/
	void setVisibleInRefractions(bool vif){if(vif == false) return; fprintf_s(mFile, "setAttr \".vif\" %i;\n", vif);}
	/*
	<b>Visible In Refractions</b>.  Turn this on if you are
	doing Ray Tracing, and you want the image plane to sppear
	when seen through a transparent refractive surface.
	*/
	void setVisibleInRefractions(const BoolID& vif){fprintf_s(mFile,"connectAttr \"");vif.write(mFile);fprintf_s(mFile,"\" \"%s.vif\";\n",mName.c_str());}
	/*
	Rotation of the image plane around the view vector.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	void setRotate(double r){if(r == 0) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*
	Rotation of the image plane around the view vector.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	void setRotate(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*
	Determines whether a depth map should be used for this image plane.
	This is only support for Maya IFF image files.
	*/
	void setUseDepthMap(bool udm){if(udm == false) return; fprintf_s(mFile, "setAttr \".udm\" %i;\n", udm);}
	/*
	Determines whether a depth map should be used for this image plane.
	This is only support for Maya IFF image files.
	*/
	void setUseDepthMap(const BoolID& udm){fprintf_s(mFile,"connectAttr \"");udm.write(mFile);fprintf_s(mFile,"\" \"%s.udm\";\n",mName.c_str());}
	/*
	Indicates whether or not the image plane's color should be
	composited into the final image.
	*/
	void setCompositeDepth(bool cmp){if(cmp == true) return; fprintf_s(mFile, "setAttr \".cmp\" %i;\n", cmp);}
	/*
	Indicates whether or not the image plane's color should be
	composited into the final image.
	*/
	void setCompositeDepth(const BoolID& cmp){fprintf_s(mFile,"connectAttr \"");cmp.write(mFile);fprintf_s(mFile,"\" \"%s.cmp\";\n",mName.c_str());}
	/*
	Indicates whether or not the image plane's stored color
	has already been premultiplied by its alpha.  If it has, then
	Maya will not re-multiply the two. Note, this flag only
	affects rendering in the software renderer.
	*/
	void setAlreadyPremult(bool pre){if(pre == false) return; fprintf_s(mFile, "setAttr \".pre\" %i;\n", pre);}
	/*
	Indicates whether or not the image plane's stored color
	has already been premultiplied by its alpha.  If it has, then
	Maya will not re-multiply the two. Note, this flag only
	affects rendering in the software renderer.
	*/
	void setAlreadyPremult(const BoolID& pre){fprintf_s(mFile,"connectAttr \"");pre.write(mFile);fprintf_s(mFile,"\" \"%s.pre\";\n",mName.c_str());}
	/*
	Indicates if we should oversample the depth buffer.
	Users can specify a depth buffer that is larger than the
	image buffer using the 'depthFile' attribute.  Depth files should
	be integral multiples larger than the width and height of the
	actual image.
	*/
	void setDepthOversample(bool osp){if(osp == false) return; fprintf_s(mFile, "setAttr \".osp\" %i;\n", osp);}
	/*
	Indicates if we should oversample the depth buffer.
	Users can specify a depth buffer that is larger than the
	image buffer using the 'depthFile' attribute.  Depth files should
	be integral multiples larger than the width and height of the
	actual image.
	*/
	void setDepthOversample(const BoolID& osp){fprintf_s(mFile,"connectAttr \"");osp.write(mFile);fprintf_s(mFile,"\" \"%s.osp\";\n",mName.c_str());}
	/*
	Indicates that we should read depth information from the file
	specified in the 'depthFile' attribute.
	*/
	void setSeparateDepth(bool sd){if(sd == false) return; fprintf_s(mFile, "setAttr \".sd\" %i;\n", sd);}
	/*
	Indicates that we should read depth information from the file
	specified in the 'depthFile' attribute.
	*/
	void setSeparateDepth(const BoolID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd\";\n",mName.c_str());}
	/*
	Allows the user to specify a separate file to obtain depth information.
	Only Maya IFF files are supported.
	*/
	void setDepthFile(const string& df){if(df == "false") return; fprintf_s(mFile, "setAttr \".df\" -type \"string\" ");df.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Allows the user to specify a separate file to obtain depth information.
	Only Maya IFF files are supported.
	*/
	void setDepthFile(const StringID& df){fprintf_s(mFile,"connectAttr \"");df.write(mFile);fprintf_s(mFile,"\" \"%s.df\";\n",mName.c_str());}
	/*
	Offsets the depth buffer by the specified amount. Values are clamped
	to the near and far clip plane.
	*/
	void setDepthBias(double dg){if(dg == 0) return; fprintf_s(mFile, "setAttr \".dg\" %f;\n", dg);}
	/*
	Offsets the depth buffer by the specified amount. Values are clamped
	to the near and far clip plane.
	*/
	void setDepthBias(const DoubleID& dg){fprintf_s(mFile,"connectAttr \"");dg.write(mFile);fprintf_s(mFile,"\" \"%s.dg\";\n",mName.c_str());}
	/*
	Scales the depth information the z values are multipled by the scale
	value before rendering. Values are clamped to the near and far clip
	planes.
	*/
	void setDepthScale(double ds){if(ds == 1.0) return; fprintf_s(mFile, "setAttr \".ds\" %f;\n", ds);}
	/*
	Scales the depth information the z values are multipled by the scale
	value before rendering. Values are clamped to the near and far clip
	planes.
	*/
	void setDepthScale(const DoubleID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*
	<b>Type</b> controls the source of the image on the
	Image plane.  Allowed values are <b>Image File</b> and
	<b>Texture</b>.  Some attributes are not available when
	using the Texture setting.
	*/
	UnsignedintID getType(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*
	<b>Image Name</b> is only used if Type is set to Image File.
	Set this attribute to the file name of the image to be used
	in the image plane.  If you want to use a sequence of images
	(such as a saved animation) then set this to the name of the first
	file in the sequence.  (see also Use Frame Extension and Frame
	Extension).
	<p/>
	You can also specify a movie file here.  Maya can use SGI
	movie files using one of these compressions:  Uncompressed Video,
	RLE, RLE24, JPEG, MVC1, or MVC2.  Maya can also use QuickTime
	movie files using one of these compressions: Uncompressed Video,
	QuickTime Video, QuickTime Animation, or Indeo.  If you specify
	a movie file, you must use the Frame Extension attributes.
	*/
	StringID getImageName(){char buffer[4096];sprintf_s (buffer, "%s.imn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Use Frame Extension</b>.  Turn this ON when you are
	using a sequence of image files (such as a saved animation)
	for the image plane, or if you are using an SGI or QuickTime
	movie file.  When this is on, the system will
	substitute the frame number in the Image Name with
	the number from the Frame Extension attribute (see below).
	*/
	BoolID getUseFrameExtension(){char buffer[4096];sprintf_s (buffer, "%s.ufe",mName.c_str());return (const char*)buffer;}
	/*
	<b>Frame Extension</b>.  This is only used when Use Frame
	Extension is ON.  The frame extension in Image Name is
	replaced by the number here.  Animate this attribute
	to use a sequence of image files (such as a saved animation)
	in the image plane.
	<p/>
	<b>Example:</b> say you have saved images named "pic.1.iff"
	up to "pic.99.iff".  You want them to show on the image plane
	between frames 100 and 300 of your animation.  To do this:
	<ul>
	<li>Set Image Name to "pic.1.iff"</li>
	<li>Turn Frame Extension ON.</li>
	<li>Go to frame 100.  Set Frame Extension to 1.  Keyframe it.</li>
	<li>Go to frame 300.  Set Frame Extension to 99.  Keyframe it.</li>
	</ul>
	<p/><b>Tip:</b> You can also use an expression for this
	attribute.  For example, if you want the frame number of the
	image to always be the same as the current frame number,
	then just type "=frame" into the Frame Extension field
	in the attribute editor.
	*/
	IntID getFrameExtension(){char buffer[4096];sprintf_s (buffer, "%s.fe",mName.c_str());return (const char*)buffer;}
	/*
	Specifies an offset of the keyed Frame Extension value.
	This attribute is only meaningful if Use Frame Extension is turned on.
	*/
	IntID getFrameOffset(){char buffer[4096];sprintf_s (buffer, "%s.fo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Coverage</b> controls the amount of the image that
	will be used in the image plane.  This is only used when
	the Type is set to Image File.  The coverage is measured
	in pixels.  You can specify how many horizontal and vertical
	pixels of the source image will be used.  See also
	Coverage Origin (below).
	*/
	Short2ID getCoverage(){char buffer[4096];sprintf_s (buffer, "%s.cov",mName.c_str());return (const char*)buffer;}
	/*
	Coverage X:  The width in pixels of the area on the
	source image to be used.
	*/
	ShortID getCoverageX(){char buffer[4096];sprintf_s (buffer, "%s.cov.cvx",mName.c_str());return (const char*)buffer;}
	/*
	Coverage Y:  The height in pixels of the area on the
	source image to be used.
	*/
	ShortID getCoverageY(){char buffer[4096];sprintf_s (buffer, "%s.cov.cvy",mName.c_str());return (const char*)buffer;}
	/*
	<b>Coverage Origin</b> controls the lower-left-corner
	of the area of the input image that will be used on the
	image plane.  0, 0, is the lower-left corner of the image.
	See also Coverage (above)
	*/
	Short2ID getCoverageOrigin(){char buffer[4096];sprintf_s (buffer, "%s.co",mName.c_str());return (const char*)buffer;}
	/*
	Coverage Origin X:  The pixel position of the left edge of
	the area of the source image to be used.
	*/
	ShortID getCoverageOriginX(){char buffer[4096];sprintf_s (buffer, "%s.co.cox",mName.c_str());return (const char*)buffer;}
	/*
	Coverage Origin Y:  The pixel position of the bottom edge of
	the area of the source image to be used.
	*/
	ShortID getCoverageOriginY(){char buffer[4096];sprintf_s (buffer, "%s.co.coy",mName.c_str());return (const char*)buffer;}
	/*
	<b>Source Texture</b>.  If the Type attribute is set to
	Texture, then this attribute is connected to the texture
	node used by the image plane.  Note that the Texture node
	must have an attribute named Out Color.
	*/
	MessageID getSourceTexture(){char buffer[4096];sprintf_s (buffer, "%s.stx",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fit</b> controls how the image file will be fit
	into the image plane.  If the image file being used has
	the same aspect ratio as the image plane (determined by
	the Size attribute), then there is no problem; the image
	will fit exactly without any squashing or stretching.  If
	the aspect ratios don't match,
	then this attribute determines which fitting algorithm
	will be used.  Choices are:
	<ul>
	<b>Fill:</b> The image will be made as small as it can
	while still completely filling the image plane.  Whatever
	excess hangs off the sides or the top and bottom will be cropped.
	Fill guarantees that the image will completely fill the plane,
	without being squashed or stretched.
	<p/>
	<b>Best:</b> The image will be made as large as it can
	be, while still fitting completely within the defined image plane.
	(Effectively, this is the same as chooing Horizontal or Vertical, whichever one
	will result in no part of the image being cropped).  Best
	guarantees that you will see the entire image, with no
	cropping and no squashing or stretching.
	<p/><b>Horizontal:</b> The image is sized so that its horizontal
	dimension exactly fits the horizontal dimension of the image
	plane.  The image keeps its own aspect ratio. Horizontal fit
	will crop the top and bottom of the image to make it fit.
	<p/><b>Vertical:</b> The image is sized so that its vertical
	dimension exactly fits the vertical dimension of the image
	plane.  The image keeps its own aspect ratio. Vertical fit
	will crop the left and right sides of the image to make it fit.
	<p/><b>To Size</b>:  The image is squashed or stretched, forced
	to fit into the image plane both horizontally and vertically.
	</ul>
	*/
	UnsignedintID getFit(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*
	<b>Display Mode</b> controls how the image plane will be displayed
	both in the 3d view, and when rendered.  Choices are:
	<ul>
	<b>None:</b> The image plane is not shown.
	<p/><b>Outline:</b> The image plane is displayed as a
	rectangle with an X through it.  (If you render in this
	mode, the image plane will show up as though it were in RGB mode)
	<p/><b>RGB:</b> The image is displayed.  Any alpha channel
	(transparency) is ignored.  If you are displaying an SGI or
	QuickTime movie file with no alpha channel, you should use
	this setting.
	<p/><b>RGBA:</b> The image is displayed. The alpha channel controls
	the transparency of the image.  (Areas where the alpha channel
	are brighter are more opaque)
	<p/><b>Luminance:</b> The image is diplayed in
	greyscale, like a black-and-white television.  Transparency
	(alpha) is ignored.
	<p/><b>Alpha:</b> The alpha (transparency) channel is displayed
	as a monochrome image.
	</ul>
	*/
	UnsignedintID getDisplayMode(){char buffer[4096];sprintf_s (buffer, "%s.dm",mName.c_str());return (const char*)buffer;}
	/*
	<b>Display Only If Current</b>.  If this is turned on,
	then you will only see the image plane when you are looking
	through the camera that the plane is attached to.
	<p/>
	For example, if you attach an image plane to your perspective
	camera, and you don't want to see it in your ortho views, turn
	this attribute ON.
	*/
	BoolID getDisplayOnlyIfCurrent(){char buffer[4096];sprintf_s (buffer, "%s.dic",mName.c_str());return (const char*)buffer;}
	/*
	<b>Alpha Gain</b> is a multiplier that is applied to
	the alpha value.  Increase this to make the semi-transparent
	areas of the image more opaque.  Decrease this to make
	them more transparent.
	*/
	DoubleID getAlphaGain(){char buffer[4096];sprintf_s (buffer, "%s.ag",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this surface should override global shading sample settings.*/
	BoolID getShadingSamplesOverride(){char buffer[4096];sprintf_s (buffer, "%s.sso",mName.c_str());return (const char*)buffer;}
	/*Specifies the minimum number of shading samples should be taken for this surface during rendering.*/
	IntID getShadingSamples(){char buffer[4096];sprintf_s (buffer, "%s.ssa",mName.c_str());return (const char*)buffer;}
	/*Specifies the max number of shading samples can be taken for this surface during rendering.*/
	IntID getMaxShadingSamples(){char buffer[4096];sprintf_s (buffer, "%s.msa",mName.c_str());return (const char*)buffer;}
	/*
	<b>Locked To Camera</b>.  If this is turned on, then the
	image plane is locked to the camera's position, so that as
	the camera moves, the image plane moves with it.  If this
	is turned off, the image plane stays in a fixed location,
	but it still always faces the camera.  This is normally turned
	on.
	<p/>
	<b>Tip:</b> Use this attribute to trace images.  Attach an
	image plane to an ortho camera, and load an image into it.
	Then turn off Locked to Camera.  Now you can use tools such
	as the Maya curve tool to trace what's in the image.  You
	can pan around and zoom in and out as you need to.
	*/
	BoolID getLockedToCamera(){char buffer[4096];sprintf_s (buffer, "%s.dlc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Depth</b> controls the distance of the plane from the camera.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	DoubleID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	<b>Squeeze Correction</b> applies a horizontal scaling to
	an image.  Increase Squeeze Correction to squeeze the
	image more, and descrease it to spread the image wider.
	<p/>This can be useful when your background images
	were scanned in from film that
	was shot using an anamorphic film format, such as Panavision.
	Set Squeeze Correction to 0.5, and the compressed film
	images will be expanded to twice their width.
	*/
	DoubleID getSqueezeCorrection(){char buffer[4096];sprintf_s (buffer, "%s.sqc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Size</b> controls the width and height of the image plane.
	This attribute is only meaningful when Locked To Camera is on.
	<p/><b>Note:</b> Size is always measured in inches, so matter what
	your current units are set to.  It is measured on the camera's
	aperture.
	*/
	Double2ID getSize(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Size X:  Image plane width*/
	DoubleID getSizeX(){char buffer[4096];sprintf_s (buffer, "%s.s.sx",mName.c_str());return (const char*)buffer;}
	/*Size Y: Image plane height.*/
	DoubleID getSizeY(){char buffer[4096];sprintf_s (buffer, "%s.s.sy",mName.c_str());return (const char*)buffer;}
	/*
	<b>Offset</b> controls how much the center of the image
	plane is offset from the centre of the viewing frustum
	of the camera.  Offset is always measured in inches
	on the camera aperture.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	Double2ID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*Horizontal component of Offset*/
	DoubleID getOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*Vertical component of Offset*/
	DoubleID getOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*
	<b>Center</b> controls the world-space position of the center
	of the image plane.  This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	Double3ID getCenter(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*X component of Center*/
	DoubleID getCenterX(){char buffer[4096];sprintf_s (buffer, "%s.c.cx",mName.c_str());return (const char*)buffer;}
	/*Y component of Center*/
	DoubleID getCenterY(){char buffer[4096];sprintf_s (buffer, "%s.c.cy",mName.c_str());return (const char*)buffer;}
	/*Z component of Center*/
	DoubleID getCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.c.cz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Width</b> controls the width of the image plane in world space.
	This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	DoubleID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*
	<b>Height</b> controls the height of the image plane in world space.
	This attribute is only meaningful when
	Locked To Camera is turned off.
	*/
	DoubleID getHeight(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*
	<b>Visible In Reflections</b>.  Turn this on if you are
	doing Ray Tracing, and you want the image plane to sppear
	in reflected surfaces.
	*/
	BoolID getVisibleInReflections(){char buffer[4096];sprintf_s (buffer, "%s.vir",mName.c_str());return (const char*)buffer;}
	/*
	<b>Visible In Refractions</b>.  Turn this on if you are
	doing Ray Tracing, and you want the image plane to sppear
	when seen through a transparent refractive surface.
	*/
	BoolID getVisibleInRefractions(){char buffer[4096];sprintf_s (buffer, "%s.vif",mName.c_str());return (const char*)buffer;}
	/*
	Rotation of the image plane around the view vector.
	This attribute is only meaningful when Locked To Camera is on.
	*/
	DoubleID getRotate(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*
	Determines whether a depth map should be used for this image plane.
	This is only support for Maya IFF image files.
	*/
	BoolID getUseDepthMap(){char buffer[4096];sprintf_s (buffer, "%s.udm",mName.c_str());return (const char*)buffer;}
	/*
	Indicates whether or not the image plane's color should be
	composited into the final image.
	*/
	BoolID getCompositeDepth(){char buffer[4096];sprintf_s (buffer, "%s.cmp",mName.c_str());return (const char*)buffer;}
	/*
	Indicates whether or not the image plane's stored color
	has already been premultiplied by its alpha.  If it has, then
	Maya will not re-multiply the two. Note, this flag only
	affects rendering in the software renderer.
	*/
	BoolID getAlreadyPremult(){char buffer[4096];sprintf_s (buffer, "%s.pre",mName.c_str());return (const char*)buffer;}
	/*
	Indicates if we should oversample the depth buffer.
	Users can specify a depth buffer that is larger than the
	image buffer using the 'depthFile' attribute.  Depth files should
	be integral multiples larger than the width and height of the
	actual image.
	*/
	BoolID getDepthOversample(){char buffer[4096];sprintf_s (buffer, "%s.osp",mName.c_str());return (const char*)buffer;}
	/*
	Indicates that we should read depth information from the file
	specified in the 'depthFile' attribute.
	*/
	BoolID getSeparateDepth(){char buffer[4096];sprintf_s (buffer, "%s.sd",mName.c_str());return (const char*)buffer;}
	/*
	Allows the user to specify a separate file to obtain depth information.
	Only Maya IFF files are supported.
	*/
	StringID getDepthFile(){char buffer[4096];sprintf_s (buffer, "%s.df",mName.c_str());return (const char*)buffer;}
	/*
	Offsets the depth buffer by the specified amount. Values are clamped
	to the near and far clip plane.
	*/
	DoubleID getDepthBias(){char buffer[4096];sprintf_s (buffer, "%s.dg",mName.c_str());return (const char*)buffer;}
	/*
	Scales the depth information the z values are multipled by the scale
	value before rendering. Values are clamped to the near and far clip
	planes.
	*/
	DoubleID getDepthScale(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
protected:
	ImagePlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IMAGEPLANE_H__
