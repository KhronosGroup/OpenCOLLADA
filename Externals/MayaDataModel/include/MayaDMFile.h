/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILE_H__
#define __MayaDM_FILE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
<b>File</b> textures allow you to use any image file as a texture map.
  The image file can be any of the image file types supported by Maya.
  <p/>
  File Texture can also use a numbered sequence of images, allowing you
  to use an animation as a texture map.  To do this:
        <ul>
          <li>Set File Texture Name to the name of one of the first image in
  the sequence, <i>e.g.</i> "myfile.1.iff"</li>
    <li>Turn on the Use Frame Extension attribute to start using an
    image sequence.</li>
    <li>Go to the first frame in your animation where you want the texture
  to show, set the Frame Extension attribute to the number of the image file you
  want used at that frame, and keyframe it.</li>
    <li>Go to the last frame in your animation where you want the texture
  to show, set the Frame Extension attribute to the number of the image file you
  want used at that frame, and keyframe it.</li>
  </ul>
  <p/>
  Some tips for using File Textures:
  <ul>
    <li>Square images usually give the best image quality.</li>
    <li>Use IFF or SGI format images for optimum performance.</li>
  </ul>
  Aside from the attribute described here, File Texture inherits
  many other attributes from its parent, <a href="texture2d.html">Texture 2d</a>.
  <p/>
  In the table below, important attributes have their names listed
  in <b>bold</b> in the description column.
*/
class File : public Texture2d
{
public:
public:
	File(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "file"){}
	virtual ~File(){}
	/*
	<b>File Texture Name</b> is the name of an image file.  The
	image in this file will be used as the texture.
	<p/>
	If you want to use a numbered sequence of image files in
	your texture (<i>i.e.</i>, animate your texture, set this
	to the name of the first image
	in the sequence.
	*/
	void setFileTextureName(const string& ftn){if(ftn == "NULL") return; fprintf_s(mFile, "setAttr \".ftn\" -type \"string\" ");ftn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>File Texture Name</b> is the name of an image file.  The
	image in this file will be used as the texture.
	<p/>
	If you want to use a numbered sequence of image files in
	your texture (<i>i.e.</i>, animate your texture, set this
	to the name of the first image
	in the sequence.
	*/
	void setFileTextureName(const StringID& ftn){fprintf_s(mFile,"connectAttr \"");ftn.write(mFile);fprintf_s(mFile,"\" \"%s.ftn\";\n",mName.c_str());}
	/*
	If set, then the texture file will not be loaded into the
	node. Instead a flat, grey color will be output in place of
	the image.
	*/
	void setDisableFileLoad(bool dfl){if(dfl == false) return; fprintf_s(mFile, "setAttr \".dfl\" %i;\n", dfl);}
	/*
	If set, then the texture file will not be loaded into the
	node. Instead a flat, grey color will be output in place of
	the image.
	*/
	void setDisableFileLoad(const BoolID& dfl){fprintf_s(mFile,"connectAttr \"");dfl.write(mFile);fprintf_s(mFile,"\" \"%s.dfl\";\n",mName.c_str());}
	/*
	When <b>Use Frame Extension</b> is on, the frame
	number in the file name will be replaced with the number
	specified in the Frame Extension attribute.  Use this when
	you want to animate the texture. (See notes in the description
	section above.)
	*/
	void setUseFrameExtension(bool ufe){if(ufe == false) return; fprintf_s(mFile, "setAttr \".ufe\" %i;\n", ufe);}
	/*
	When <b>Use Frame Extension</b> is on, the frame
	number in the file name will be replaced with the number
	specified in the Frame Extension attribute.  Use this when
	you want to animate the texture. (See notes in the description
	section above.)
	*/
	void setUseFrameExtension(const BoolID& ufe){fprintf_s(mFile,"connectAttr \"");ufe.write(mFile);fprintf_s(mFile,"\" \"%s.ufe\";\n",mName.c_str());}
	/*
	<b>Frame Extension</b> replaces the frame extension number
	in the file name (if there is one).  This attribute is only
	meaningful if Use FrameExtension is turned on.
	<p/>
	Keyframe this attribute when you want to use a sequence of files
	as a file texture.  (See notes in the description section
	above.)
	*/
	void setFrameExtension(int fe){if(fe == 1) return; fprintf_s(mFile, "setAttr \".fe\" %i;\n", fe);}
	/*
	<b>Frame Extension</b> replaces the frame extension number
	in the file name (if there is one).  This attribute is only
	meaningful if Use FrameExtension is turned on.
	<p/>
	Keyframe this attribute when you want to use a sequence of files
	as a file texture.  (See notes in the description section
	above.)
	*/
	void setFrameExtension(const IntID& fe){fprintf_s(mFile,"connectAttr \"");fe.write(mFile);fprintf_s(mFile,"\" \"%s.fe\";\n",mName.c_str());}
	/*
	Specifies an offset of the keyed Frame Extension value.
	This attribute is only meaningful if Use FrameExtension is turned on.
	*/
	void setFrameOffset(int io){if(io == 0) return; fprintf_s(mFile, "setAttr \".io\" %i;\n", io);}
	/*
	Specifies an offset of the keyed Frame Extension value.
	This attribute is only meaningful if Use FrameExtension is turned on.
	*/
	void setFrameOffset(const IntID& io){fprintf_s(mFile,"connectAttr \"");io.write(mFile);fprintf_s(mFile,"\" \"%s.io\";\n",mName.c_str());}
	/*
	<b>Use Hardware Texture Cycling</b>.  Turn this on to get
	better performance when:
	<ul>
	<li>You are using a sequence of frames for the file textures.
	(See the Use Frame Extension attribute above).</li>
	<li>You are using Harware texturing in the 3d view.</li>
	<li>You need to "scrub" along the time line, and see the
	the animated texture update as you do so.</li>
	</ul>
	<p/>
	When Use Hardware Texture Cycling is turned on, you are forcing
	Maya to load all (or a subset of) the texture file sequence into
	memory.  This uses up memory, but significantly improves
	the update speed.  Use the attributes below to indicate which
	frames you want loaded in.  If you do not load them all in,
	at playback time Maya will use the closest frame available.
	<p/>
	The Hardware Texture Cycling attributes have no effect on
	the look of your final rendered image.  They are only used
	to speed up what you see interactively.
	*/
	void setUseHardwareTextureCycling(bool uhc){if(uhc == false) return; fprintf_s(mFile, "setAttr \".uhc\" %i;\n", uhc);}
	/*
	<b>Use Hardware Texture Cycling</b>.  Turn this on to get
	better performance when:
	<ul>
	<li>You are using a sequence of frames for the file textures.
	(See the Use Frame Extension attribute above).</li>
	<li>You are using Harware texturing in the 3d view.</li>
	<li>You need to "scrub" along the time line, and see the
	the animated texture update as you do so.</li>
	</ul>
	<p/>
	When Use Hardware Texture Cycling is turned on, you are forcing
	Maya to load all (or a subset of) the texture file sequence into
	memory.  This uses up memory, but significantly improves
	the update speed.  Use the attributes below to indicate which
	frames you want loaded in.  If you do not load them all in,
	at playback time Maya will use the closest frame available.
	<p/>
	The Hardware Texture Cycling attributes have no effect on
	the look of your final rendered image.  They are only used
	to speed up what you see interactively.
	*/
	void setUseHardwareTextureCycling(const BoolID& uhc){fprintf_s(mFile,"connectAttr \"");uhc.write(mFile);fprintf_s(mFile,"\" \"%s.uhc\";\n",mName.c_str());}
	/*
	<b>Start Cycle Extension</b> is the number of the first
	frame you want loaded into memory when Use Hardware Texture
	Cycling is turned on.  (See above).
	*/
	void setStartCycleExtension(int sce){if(sce == 1) return; fprintf_s(mFile, "setAttr \".sce\" %i;\n", sce);}
	/*
	<b>Start Cycle Extension</b> is the number of the first
	frame you want loaded into memory when Use Hardware Texture
	Cycling is turned on.  (See above).
	*/
	void setStartCycleExtension(const IntID& sce){fprintf_s(mFile,"connectAttr \"");sce.write(mFile);fprintf_s(mFile,"\" \"%s.sce\";\n",mName.c_str());}
	/*
	<b>End Cycle Extension</b> is the number of the last
	frame you want loaded into memory when Use Hardware Texture
	Cycling is turned on.  (See above).
	*/
	void setEndCycleExtension(int ece){if(ece == 1) return; fprintf_s(mFile, "setAttr \".ece\" %i;\n", ece);}
	/*
	<b>End Cycle Extension</b> is the number of the last
	frame you want loaded into memory when Use Hardware Texture
	Cycling is turned on.  (See above).
	*/
	void setEndCycleExtension(const IntID& ece){fprintf_s(mFile,"connectAttr \"");ece.write(mFile);fprintf_s(mFile,"\" \"%s.ece\";\n",mName.c_str());}
	/*
	<b>By Cycle Increment</b> controls which frames
	will be loaded into memory when Use Hardware Texture
	Cycling is turned on.  If it is 1, then every frame
	between Start Cycle Extension and End Cycle Extension
	will be loaded in.  If this is 2, every second frame
	will be loaded in.  If this is 3, every third frame, etc.
	<p/>
	During playback or scrubbing, the system will use
	whichever loaded frame is the closest to what is needed.
	*/
	void setByCycleIncrement(int bci){if(bci == 1) return; fprintf_s(mFile, "setAttr \".bci\" %i;\n", bci);}
	/*
	<b>By Cycle Increment</b> controls which frames
	will be loaded into memory when Use Hardware Texture
	Cycling is turned on.  If it is 1, then every frame
	between Start Cycle Extension and End Cycle Extension
	will be loaded in.  If this is 2, every second frame
	will be loaded in.  If this is 3, every third frame, etc.
	<p/>
	During playback or scrubbing, the system will use
	whichever loaded frame is the closest to what is needed.
	*/
	void setByCycleIncrement(const IntID& bci){fprintf_s(mFile,"connectAttr \"");bci.write(mFile);fprintf_s(mFile,"\" \"%s.bci\";\n",mName.c_str());}
	/*Force swatch generation despite image size*/
	void setForceSwatchGen(const BoolID& fsg){fprintf_s(mFile,"connectAttr \"");fsg.write(mFile);fprintf_s(mFile,"\" \"%s.fsg\";\n",mName.c_str());}
	/*
	<b>Filter Type</b> determines what kind of filter Maya
	will use when applying the file texture.  Each kind of
	filter has slightly different properties and costs in performance.
	<p/>
	<ul>
	<b>No Filter</b> means just that.  No filter is applied
	to the file texture.  This is the fastest in terms of
	rendering, but will usually produce substandard results.
	Using this will probably result in aliasing artifacts
	(jaggies).
	<p/>
	<b>Mip Map</b> filtering is the best choice for all-round
	general use.  Its cost is negligible compared to the
	other filter types, and it generally does a good job.
	Internally, the renderer stores a 'pyramid' of versions
	of the texture, each a different resolutions, and as it
	renders it chooses the best ones for calculation.
	<p/>
	<b>Box</b> filtering works by placing a 'box' over the
	the area of the texture map to be sampled, and averaging
	out all the samples within the box.  Do not use
	this filter type if the file texture is to be used as
	a 2d projection or bump map, as it will not work properly.
	<p/>
	<b>Quadratic</b> and <b>Quartic</b> filters give a
	somewhat better quality of filtering.  Like the Box
	filter, they sample an area of the texture, but they
	give more weight to samples closer to the center of
	the area.
	<p/>These filters approximate the quality of Gaussian,
	but are optimized to be faster.  However, if you use these
	filter types, textures may "swim" or appear blurry.  Do not use
	these filter type if the file texture is to be used as
	a 2d projection or bump map, as they will not work properly.
	<p/>
	<b>Gaussian</b> filtering is slower, but gives the best
	quality.  Use this for high-quality rendering with
	very sharp results.
	</ul>
	*/
	void setFilterType(unsigned int ft){if(ft == 3) return; fprintf_s(mFile, "setAttr \".ft\" %i;\n", ft);}
	/*Width of filter It is recommend not to change this value.*/
	void setFilterWidth(float fw){if(fw == 0.707) return; fprintf_s(mFile, "setAttr \".fw\" %f;\n", fw);}
	/*
	<b>Use Cache</b> is provided for situations when memory
	is low.  If you turn this on, rendering this file texture
	will use less memory, but it will also be slower.
	*/
	void setUseCache(bool uca){if(uca == false) return; fprintf_s(mFile, "setAttr \".uca\" %i;\n", uca);}
	/*
	<b>Use Maximum Res</b> is only meaningful if your filter
	type is set to MipMap.  If you turn this on, it forces
	the MipMap to always use the highest-resolution version
	of the texture.
	*/
	void setUseMaximumRes(bool umr){if(umr == false) return; fprintf_s(mFile, "setAttr \".umr\" %i;\n", umr);}
	/*The UV coverage*/
	void setCoverage(const float2& c){if(c == float2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c\" -type \"float2\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*The UV coverage*/
	void setCoverage(const Float2ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*The U coverage*/
	void setCoverageU(float cu){if(cu == 0.0) return; fprintf_s(mFile, "setAttr \".c.cu\" %f;\n", cu);}
	/*The U coverage*/
	void setCoverageU(const FloatID& cu){fprintf_s(mFile,"connectAttr \"");cu.write(mFile);fprintf_s(mFile,"\" \"%s.c.cu\";\n",mName.c_str());}
	/*The V coverage*/
	void setCoverageV(float cv){if(cv == 0.0) return; fprintf_s(mFile, "setAttr \".c.cv\" %f;\n", cv);}
	/*The V coverage*/
	void setCoverageV(const FloatID& cv){fprintf_s(mFile,"connectAttr \"");cv.write(mFile);fprintf_s(mFile,"\" \"%s.c.cv\";\n",mName.c_str());}
	/*The translation of the texture frame along UV axes*/
	void setTranslateFrame(const float2& tf){if(tf == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tf\" -type \"float2\" ");tf.write(mFile);fprintf_s(mFile,";\n");}
	/*The translation of the texture frame along UV axes*/
	void setTranslateFrame(const Float2ID& tf){fprintf_s(mFile,"connectAttr \"");tf.write(mFile);fprintf_s(mFile,"\" \"%s.tf\";\n",mName.c_str());}
	/*The translation of the texture frame along U*/
	void setTranslateFrameU(float tfu){if(tfu == 0.0) return; fprintf_s(mFile, "setAttr \".tf.tfu\" %f;\n", tfu);}
	/*The translation of the texture frame along U*/
	void setTranslateFrameU(const FloatID& tfu){fprintf_s(mFile,"connectAttr \"");tfu.write(mFile);fprintf_s(mFile,"\" \"%s.tf.tfu\";\n",mName.c_str());}
	/*The translation of the texture frame along V*/
	void setTranslateFrameV(float tfv){if(tfv == 0.0) return; fprintf_s(mFile, "setAttr \".tf.tfv\" %f;\n", tfv);}
	/*The translation of the texture frame along V*/
	void setTranslateFrameV(const FloatID& tfv){fprintf_s(mFile,"connectAttr \"");tfv.write(mFile);fprintf_s(mFile,"\" \"%s.tf.tfv\";\n",mName.c_str());}
	/*The rotation angle for the texture frame*/
	void setRotateFrame(double rf){if(rf == 0) return; fprintf_s(mFile, "setAttr \".rf\" %f;\n", rf);}
	/*The rotation angle for the texture frame*/
	void setRotateFrame(const DoubleID& rf){fprintf_s(mFile,"connectAttr \"");rf.write(mFile);fprintf_s(mFile,"\" \"%s.rf\";\n",mName.c_str());}
	/*false iff we never have to do any texture transformation*/
	void setDoTransform(bool dtf){if(dtf == true) return; fprintf_s(mFile, "setAttr \".dtf\" %i;\n", dtf);}
	/*false iff we never have to do any texture transformation*/
	void setDoTransform(const BoolID& dtf){fprintf_s(mFile,"connectAttr \"");dtf.write(mFile);fprintf_s(mFile,"\" \"%s.dtf\";\n",mName.c_str());}
	/*The u mirror flag*/
	void setMirrorU(bool mu){if(mu == false) return; fprintf_s(mFile, "setAttr \".mu\" %i;\n", mu);}
	/*The u mirror flag*/
	void setMirrorU(const BoolID& mu){fprintf_s(mFile,"connectAttr \"");mu.write(mFile);fprintf_s(mFile,"\" \"%s.mu\";\n",mName.c_str());}
	/*The v mirror flag*/
	void setMirrorV(bool mv){if(mv == false) return; fprintf_s(mFile, "setAttr \".mv\" %i;\n", mv);}
	/*The v mirror flag*/
	void setMirrorV(const BoolID& mv){fprintf_s(mFile,"connectAttr \"");mv.write(mFile);fprintf_s(mFile,"\" \"%s.mv\";\n",mName.c_str());}
	/*The stagger flag*/
	void setStagger(bool s){if(s == false) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*The stagger flag*/
	void setStagger(const BoolID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*The wrapU flag*/
	void setWrapU(bool wu){if(wu == true) return; fprintf_s(mFile, "setAttr \".wu\" %i;\n", wu);}
	/*The wrapU flag*/
	void setWrapU(const BoolID& wu){fprintf_s(mFile,"connectAttr \"");wu.write(mFile);fprintf_s(mFile,"\" \"%s.wu\";\n",mName.c_str());}
	/*The wrapV flag*/
	void setWrapV(bool wv){if(wv == true) return; fprintf_s(mFile, "setAttr \".wv\" %i;\n", wv);}
	/*The wrapV flag*/
	void setWrapV(const BoolID& wv){fprintf_s(mFile,"connectAttr \"");wv.write(mFile);fprintf_s(mFile,"\" \"%s.wv\";\n",mName.c_str());}
	/*How many times the texture is repeated along U and along V*/
	void setRepeatUV(const float2& re){if(re == float2(1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".re\" -type \"float2\" ");re.write(mFile);fprintf_s(mFile,";\n");}
	/*How many times the texture is repeated along U and along V*/
	void setRepeatUV(const Float2ID& re){fprintf_s(mFile,"connectAttr \"");re.write(mFile);fprintf_s(mFile,"\" \"%s.re\";\n",mName.c_str());}
	/*The repeat value for U*/
	void setRepeatU(float reu){if(reu == 0.0) return; fprintf_s(mFile, "setAttr \".re.reu\" %f;\n", reu);}
	/*The repeat value for U*/
	void setRepeatU(const FloatID& reu){fprintf_s(mFile,"connectAttr \"");reu.write(mFile);fprintf_s(mFile,"\" \"%s.re.reu\";\n",mName.c_str());}
	/*The repeat value for V*/
	void setRepeatV(float rev){if(rev == 0.0) return; fprintf_s(mFile, "setAttr \".re.rev\" %f;\n", rev);}
	/*The repeat value for V*/
	void setRepeatV(const FloatID& rev){fprintf_s(mFile,"connectAttr \"");rev.write(mFile);fprintf_s(mFile,"\" \"%s.re.rev\";\n",mName.c_str());}
	/*The offset in UV, to set the origin inside the texture.*/
	void setOffset(const float2& of){if(of == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".of\" -type \"float2\" ");of.write(mFile);fprintf_s(mFile,";\n");}
	/*The offset in UV, to set the origin inside the texture.*/
	void setOffset(const Float2ID& of){fprintf_s(mFile,"connectAttr \"");of.write(mFile);fprintf_s(mFile,"\" \"%s.of\";\n",mName.c_str());}
	/*U offset*/
	void setOffsetU(float ofu){if(ofu == 0.0) return; fprintf_s(mFile, "setAttr \".of.ofu\" %f;\n", ofu);}
	/*U offset*/
	void setOffsetU(const FloatID& ofu){fprintf_s(mFile,"connectAttr \"");ofu.write(mFile);fprintf_s(mFile,"\" \"%s.of.ofu\";\n",mName.c_str());}
	/*V offset*/
	void setOffsetV(float ofv){if(ofv == 0.0) return; fprintf_s(mFile, "setAttr \".of.ofv\" %f;\n", ofv);}
	/*V offset*/
	void setOffsetV(const FloatID& ofv){fprintf_s(mFile,"connectAttr \"");ofv.write(mFile);fprintf_s(mFile,"\" \"%s.of.ofv\";\n",mName.c_str());}
	/*The rotation for the texture space.*/
	void setRotateUV(double ro){if(ro == 0) return; fprintf_s(mFile, "setAttr \".ro\" %f;\n", ro);}
	/*The rotation for the texture space.*/
	void setRotateUV(const DoubleID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*The 2D noise for U and V*/
	void setNoiseUV(const float2& n){if(n == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".n\" -type \"float2\" ");n.write(mFile);fprintf_s(mFile,";\n");}
	/*The 2D noise for U and V*/
	void setNoiseUV(const Float2ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The U noise*/
	void setNoiseU(float nu){if(nu == 0.0) return; fprintf_s(mFile, "setAttr \".n.nu\" %f;\n", nu);}
	/*The U noise*/
	void setNoiseU(const FloatID& nu){fprintf_s(mFile,"connectAttr \"");nu.write(mFile);fprintf_s(mFile,"\" \"%s.n.nu\";\n",mName.c_str());}
	/*The V noise*/
	void setNoiseV(float nv){if(nv == 0.0) return; fprintf_s(mFile, "setAttr \".n.nv\" %f;\n", nv);}
	/*The V noise*/
	void setNoiseV(const FloatID& nv){fprintf_s(mFile,"connectAttr \"");nv.write(mFile);fprintf_s(mFile,"\" \"%s.n.nv\";\n",mName.c_str());}
	/*controls the level of fuzziness vs. pixelated results*/
	void setBlurPixelation(bool blp){if(blp == true) return; fprintf_s(mFile, "setAttr \".blp\" %i;\n", blp);}
	/*controls the level of fuzziness vs. pixelated results*/
	void setBlurPixelation(const BoolID& blp){fprintf_s(mFile,"connectAttr \"");blp.write(mFile);fprintf_s(mFile,"\" \"%s.blp\";\n",mName.c_str());}
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
	/*We only care if this flag is TrenderableObjectType::kSurface*/
	void setObjectType(char otp){if(otp == 0) return; fprintf_s(mFile, "setAttr \".otp\" %;\n", otp);}
	/*We only care if this flag is TrenderableObjectType::kSurface*/
	void setObjectType(const CharID& otp){fprintf_s(mFile,"connectAttr \"");otp.write(mFile);fprintf_s(mFile,"\" \"%s.otp\";\n",mName.c_str());}
	/*depth of ray intersection object to be textured*/
	void setRayDepth(int rdp){if(rdp == 0) return; fprintf_s(mFile, "setAttr \".rdp\" %i;\n", rdp);}
	/*depth of ray intersection object to be textured*/
	void setRayDepth(const IntID& rdp){fprintf_s(mFile,"connectAttr \"");rdp.write(mFile);fprintf_s(mFile,"\" \"%s.rdp\";\n",mName.c_str());}
	/*centre of pixel*/
	void setPixelCenter(const float2& pct){fprintf_s(mFile, "setAttr \".pct\" -type \"float2\" ");pct.write(mFile);fprintf_s(mFile,";\n");}
	/*centre of pixel*/
	void setPixelCenter(const Float2ID& pct){fprintf_s(mFile,"connectAttr \"");pct.write(mFile);fprintf_s(mFile,"\" \"%s.pct\";\n",mName.c_str());}
	/*X component of aPixelCenter*/
	void setPixelCenterX(float pcx){if(pcx == 0.0) return; fprintf_s(mFile, "setAttr \".pct.pcx\" %f;\n", pcx);}
	/*X component of aPixelCenter*/
	void setPixelCenterX(const FloatID& pcx){fprintf_s(mFile,"connectAttr \"");pcx.write(mFile);fprintf_s(mFile,"\" \"%s.pct.pcx\";\n",mName.c_str());}
	/*Y component of aPixelCenter*/
	void setPixelCenterY(float pcy){if(pcy == 0.0) return; fprintf_s(mFile, "setAttr \".pct.pcy\" %f;\n", pcy);}
	/*Y component of aPixelCenter*/
	void setPixelCenterY(const FloatID& pcy){fprintf_s(mFile,"connectAttr \"");pcy.write(mFile);fprintf_s(mFile,"\" \"%s.pct.pcy\";\n",mName.c_str());}
	/*
	The mapping used to convert a floating point image into a fixed
	point image. The current options are to either : clamp floating
	point values to be between 0.0 and 1.0, rescale the image linearly
	to the 0.0 to 1.0 range, or to rescale the image logarithmically
	to the 0.0 to 1.0 range. The default setting is to perform
	linear remapping.
	*/
	void setHdrMapping(unsigned int hm){if(hm == 1) return; fprintf_s(mFile, "setAttr \".hm\" %i;\n", hm);}
	/*
	Exposure control setting for exponential exposure setting.
	Numbers less than 0 will darken the image, while numbers
	greater than 0 will brighen the image. The default value is 0,
	or no exposure mapping.
	*/
	void setHdrExposure(float he){if(he == 0.0) return; fprintf_s(mFile, "setAttr \".he\" %f;\n", he);}
	/*The size of the file texture*/
	void setOutSize(const Float2ID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The width of the file texture*/
	void setOutSizeX(const FloatID& osx){fprintf_s(mFile,"connectAttr \"");osx.write(mFile);fprintf_s(mFile,"\" \"%s.os.osx\";\n",mName.c_str());}
	/*The height of the file texture*/
	void setOutSizeY(const FloatID& osy){fprintf_s(mFile,"connectAttr \"");osy.write(mFile);fprintf_s(mFile,"\" \"%s.os.osy\";\n",mName.c_str());}
	/*
	Is set to true if the file on disk has an alpha channel
	for which one or more pixels have alpha != 1, false otherwise.
	*/
	void setFileHasAlpha(const BoolID& fha){fprintf_s(mFile,"connectAttr \"");fha.write(mFile);fprintf_s(mFile,"\" \"%s.fha\";\n",mName.c_str());}
	/*
	<b>Out Transparency</b> is the transparency computed by this
	texture. Each channel of Out Transparency (R, G, B) is
	1 - outAlpha.
	Connect this value to a transparency
	attribute of a shader to texture map that color.
	*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*Out Transparency red value.*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*Out Transparency green value.*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*Out Transparency blue value.*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*Flag to active/deactivate the pre filtering feature*/
	void setPreFilter(bool pf){if(pf == false) return; fprintf_s(mFile, "setAttr \".pf\" %i;\n", pf);}
	/*Flag to active/deactivate the pre filtering feature*/
	void setPreFilter(const BoolID& pf){fprintf_s(mFile,"connectAttr \"");pf.write(mFile);fprintf_s(mFile,"\" \"%s.pf\";\n",mName.c_str());}
	/*Filter radius for the file texture pre filtering*/
	void setPreFilterRadius(float pfr){if(pfr == 2.0f) return; fprintf_s(mFile, "setAttr \".pfr\" %f;\n", pfr);}
	/*Filter radius for the file texture pre filtering*/
	void setPreFilterRadius(const FloatID& pfr){fprintf_s(mFile,"connectAttr \"");pfr.write(mFile);fprintf_s(mFile,"\" \"%s.pfr\";\n",mName.c_str());}
	/*Information bits passing along information about type of shading*/
	void setInfoBits(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*
	<b>File Texture Name</b> is the name of an image file.  The
	image in this file will be used as the texture.
	<p/>
	If you want to use a numbered sequence of image files in
	your texture (<i>i.e.</i>, animate your texture, set this
	to the name of the first image
	in the sequence.
	*/
	StringID getFileTextureName(){char buffer[4096];sprintf_s (buffer, "%s.ftn",mName.c_str());return (const char*)buffer;}
	/*
	If set, then the texture file will not be loaded into the
	node. Instead a flat, grey color will be output in place of
	the image.
	*/
	BoolID getDisableFileLoad(){char buffer[4096];sprintf_s (buffer, "%s.dfl",mName.c_str());return (const char*)buffer;}
	/*
	When <b>Use Frame Extension</b> is on, the frame
	number in the file name will be replaced with the number
	specified in the Frame Extension attribute.  Use this when
	you want to animate the texture. (See notes in the description
	section above.)
	*/
	BoolID getUseFrameExtension(){char buffer[4096];sprintf_s (buffer, "%s.ufe",mName.c_str());return (const char*)buffer;}
	/*
	<b>Frame Extension</b> replaces the frame extension number
	in the file name (if there is one).  This attribute is only
	meaningful if Use FrameExtension is turned on.
	<p/>
	Keyframe this attribute when you want to use a sequence of files
	as a file texture.  (See notes in the description section
	above.)
	*/
	IntID getFrameExtension(){char buffer[4096];sprintf_s (buffer, "%s.fe",mName.c_str());return (const char*)buffer;}
	/*
	Specifies an offset of the keyed Frame Extension value.
	This attribute is only meaningful if Use FrameExtension is turned on.
	*/
	IntID getFrameOffset(){char buffer[4096];sprintf_s (buffer, "%s.io",mName.c_str());return (const char*)buffer;}
	/*
	<b>Use Hardware Texture Cycling</b>.  Turn this on to get
	better performance when:
	<ul>
	<li>You are using a sequence of frames for the file textures.
	(See the Use Frame Extension attribute above).</li>
	<li>You are using Harware texturing in the 3d view.</li>
	<li>You need to "scrub" along the time line, and see the
	the animated texture update as you do so.</li>
	</ul>
	<p/>
	When Use Hardware Texture Cycling is turned on, you are forcing
	Maya to load all (or a subset of) the texture file sequence into
	memory.  This uses up memory, but significantly improves
	the update speed.  Use the attributes below to indicate which
	frames you want loaded in.  If you do not load them all in,
	at playback time Maya will use the closest frame available.
	<p/>
	The Hardware Texture Cycling attributes have no effect on
	the look of your final rendered image.  They are only used
	to speed up what you see interactively.
	*/
	BoolID getUseHardwareTextureCycling(){char buffer[4096];sprintf_s (buffer, "%s.uhc",mName.c_str());return (const char*)buffer;}
	/*
	<b>Start Cycle Extension</b> is the number of the first
	frame you want loaded into memory when Use Hardware Texture
	Cycling is turned on.  (See above).
	*/
	IntID getStartCycleExtension(){char buffer[4096];sprintf_s (buffer, "%s.sce",mName.c_str());return (const char*)buffer;}
	/*
	<b>End Cycle Extension</b> is the number of the last
	frame you want loaded into memory when Use Hardware Texture
	Cycling is turned on.  (See above).
	*/
	IntID getEndCycleExtension(){char buffer[4096];sprintf_s (buffer, "%s.ece",mName.c_str());return (const char*)buffer;}
	/*
	<b>By Cycle Increment</b> controls which frames
	will be loaded into memory when Use Hardware Texture
	Cycling is turned on.  If it is 1, then every frame
	between Start Cycle Extension and End Cycle Extension
	will be loaded in.  If this is 2, every second frame
	will be loaded in.  If this is 3, every third frame, etc.
	<p/>
	During playback or scrubbing, the system will use
	whichever loaded frame is the closest to what is needed.
	*/
	IntID getByCycleIncrement(){char buffer[4096];sprintf_s (buffer, "%s.bci",mName.c_str());return (const char*)buffer;}
	/*Force swatch generation despite image size*/
	BoolID getForceSwatchGen(){char buffer[4096];sprintf_s (buffer, "%s.fsg",mName.c_str());return (const char*)buffer;}
	/*The UV coverage*/
	Float2ID getCoverage(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*The U coverage*/
	FloatID getCoverageU(){char buffer[4096];sprintf_s (buffer, "%s.c.cu",mName.c_str());return (const char*)buffer;}
	/*The V coverage*/
	FloatID getCoverageV(){char buffer[4096];sprintf_s (buffer, "%s.c.cv",mName.c_str());return (const char*)buffer;}
	/*The translation of the texture frame along UV axes*/
	Float2ID getTranslateFrame(){char buffer[4096];sprintf_s (buffer, "%s.tf",mName.c_str());return (const char*)buffer;}
	/*The translation of the texture frame along U*/
	FloatID getTranslateFrameU(){char buffer[4096];sprintf_s (buffer, "%s.tf.tfu",mName.c_str());return (const char*)buffer;}
	/*The translation of the texture frame along V*/
	FloatID getTranslateFrameV(){char buffer[4096];sprintf_s (buffer, "%s.tf.tfv",mName.c_str());return (const char*)buffer;}
	/*The rotation angle for the texture frame*/
	DoubleID getRotateFrame(){char buffer[4096];sprintf_s (buffer, "%s.rf",mName.c_str());return (const char*)buffer;}
	/*false iff we never have to do any texture transformation*/
	BoolID getDoTransform(){char buffer[4096];sprintf_s (buffer, "%s.dtf",mName.c_str());return (const char*)buffer;}
	/*The u mirror flag*/
	BoolID getMirrorU(){char buffer[4096];sprintf_s (buffer, "%s.mu",mName.c_str());return (const char*)buffer;}
	/*The v mirror flag*/
	BoolID getMirrorV(){char buffer[4096];sprintf_s (buffer, "%s.mv",mName.c_str());return (const char*)buffer;}
	/*The stagger flag*/
	BoolID getStagger(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*The wrapU flag*/
	BoolID getWrapU(){char buffer[4096];sprintf_s (buffer, "%s.wu",mName.c_str());return (const char*)buffer;}
	/*The wrapV flag*/
	BoolID getWrapV(){char buffer[4096];sprintf_s (buffer, "%s.wv",mName.c_str());return (const char*)buffer;}
	/*How many times the texture is repeated along U and along V*/
	Float2ID getRepeatUV(){char buffer[4096];sprintf_s (buffer, "%s.re",mName.c_str());return (const char*)buffer;}
	/*The repeat value for U*/
	FloatID getRepeatU(){char buffer[4096];sprintf_s (buffer, "%s.re.reu",mName.c_str());return (const char*)buffer;}
	/*The repeat value for V*/
	FloatID getRepeatV(){char buffer[4096];sprintf_s (buffer, "%s.re.rev",mName.c_str());return (const char*)buffer;}
	/*The offset in UV, to set the origin inside the texture.*/
	Float2ID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.of",mName.c_str());return (const char*)buffer;}
	/*U offset*/
	FloatID getOffsetU(){char buffer[4096];sprintf_s (buffer, "%s.of.ofu",mName.c_str());return (const char*)buffer;}
	/*V offset*/
	FloatID getOffsetV(){char buffer[4096];sprintf_s (buffer, "%s.of.ofv",mName.c_str());return (const char*)buffer;}
	/*The rotation for the texture space.*/
	DoubleID getRotateUV(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*The 2D noise for U and V*/
	Float2ID getNoiseUV(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The U noise*/
	FloatID getNoiseU(){char buffer[4096];sprintf_s (buffer, "%s.n.nu",mName.c_str());return (const char*)buffer;}
	/*The V noise*/
	FloatID getNoiseV(){char buffer[4096];sprintf_s (buffer, "%s.n.nv",mName.c_str());return (const char*)buffer;}
	/*controls the level of fuzziness vs. pixelated results*/
	BoolID getBlurPixelation(){char buffer[4096];sprintf_s (buffer, "%s.blp",mName.c_str());return (const char*)buffer;}
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
	/*We only care if this flag is TrenderableObjectType::kSurface*/
	CharID getObjectType(){char buffer[4096];sprintf_s (buffer, "%s.otp",mName.c_str());return (const char*)buffer;}
	/*depth of ray intersection object to be textured*/
	IntID getRayDepth(){char buffer[4096];sprintf_s (buffer, "%s.rdp",mName.c_str());return (const char*)buffer;}
	/*centre of pixel*/
	Float2ID getPixelCenter(){char buffer[4096];sprintf_s (buffer, "%s.pct",mName.c_str());return (const char*)buffer;}
	/*X component of aPixelCenter*/
	FloatID getPixelCenterX(){char buffer[4096];sprintf_s (buffer, "%s.pct.pcx",mName.c_str());return (const char*)buffer;}
	/*Y component of aPixelCenter*/
	FloatID getPixelCenterY(){char buffer[4096];sprintf_s (buffer, "%s.pct.pcy",mName.c_str());return (const char*)buffer;}
	/*The size of the file texture*/
	Float2ID getOutSize(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*The width of the file texture*/
	FloatID getOutSizeX(){char buffer[4096];sprintf_s (buffer, "%s.os.osx",mName.c_str());return (const char*)buffer;}
	/*The height of the file texture*/
	FloatID getOutSizeY(){char buffer[4096];sprintf_s (buffer, "%s.os.osy",mName.c_str());return (const char*)buffer;}
	/*
	Is set to true if the file on disk has an alpha channel
	for which one or more pixels have alpha != 1, false otherwise.
	*/
	BoolID getFileHasAlpha(){char buffer[4096];sprintf_s (buffer, "%s.fha",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Transparency</b> is the transparency computed by this
	texture. Each channel of Out Transparency (R, G, B) is
	1 - outAlpha.
	Connect this value to a transparency
	attribute of a shader to texture map that color.
	*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*Out Transparency red value.*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*Out Transparency green value.*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*Out Transparency blue value.*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*Flag to active/deactivate the pre filtering feature*/
	BoolID getPreFilter(){char buffer[4096];sprintf_s (buffer, "%s.pf",mName.c_str());return (const char*)buffer;}
	/*Filter radius for the file texture pre filtering*/
	FloatID getPreFilterRadius(){char buffer[4096];sprintf_s (buffer, "%s.pfr",mName.c_str());return (const char*)buffer;}
	/*Information bits passing along information about type of shading*/
	IntID getInfoBits(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
protected:
	File(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FILE_H__
