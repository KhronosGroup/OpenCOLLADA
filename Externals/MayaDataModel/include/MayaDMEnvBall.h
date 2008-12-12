/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVBALL_H__
#define __MayaDM_ENVBALL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
/*
<b>EnvBall</b> uses an image or series of images of a highly reflective
 chrome ball in an environment (real world or computer-generated) to
 re-create that environment.  This is possible because the reflections
 in the chrome ball provide a nearly 360 degree view of the environment.
<p/>
 <b>To create an image of a chrome ball</b>, first place a highly reflective chrome ball (sphere) in the
 environment (real world or computer generated) that you want to re-create. Place the ball at the
 exact location (in the original environment) where you want your model to appear (in the
 re-created environment), and take note of the ball's distance from any floor/walls/ceiling or
 large objects.
<p/>
 Photograph (or render) the ball using a telephoto lens, and take note of the camera's elevation
 (the angle between the camera's view and the environment's ground plane), and the camera's
 inclination (the angle between the camera's view and the environment's YZ plane).
<p/>
 The photo essentially contains a compressed sample of the entire environment, except for the
 area directly behind the ball. The highest resolution is in the direction of the camera, so the
 image provides the best data compression for that point of view.
<p/>
 There is much more detail about how to use EnvBall in the Rendering
 documentation,
 <p/>
 Aside from the attributes listed here, EnvBall inherits additional
 attributes from <a href="textureEnv.html">TextureEnv</a>.
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class EnvBall : public TextureEnv
{
public:
public:
	EnvBall(FILE* file,const std::string& name,const std::string& parent=""):TextureEnv(file, name, parent, "envBall"){}
	virtual ~EnvBall(){}
	/*The current sample point that has to be shaded*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*
	<b>Image</b> is the source image (texture) to be used in
	the environment map.  See the description section above
	and the Rendering documentation for details on how to
	create this image.  When you have an image file ready to
	use, create a File Texture using the image,
	then connect the Out Color attribute of the File Texture
	to this Image attribute.
	*/
	void setImage(const float3& so){if(so == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".so\" -type \"float3\" ");so.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Image</b> is the source image (texture) to be used in
	the environment map.  See the description section above
	and the Rendering documentation for details on how to
	create this image.  When you have an image file ready to
	use, create a File Texture using the image,
	then connect the Out Color attribute of the File Texture
	to this Image attribute.
	*/
	void setImage(const Float3ID& so){fprintf_s(mFile,"connectAttr \"");so.write(mFile);fprintf_s(mFile,"\" \"%s.so\";\n",mName.c_str());}
	/*The red component of the input texture*/
	void setImageR(float sor){if(sor == 0.0) return; fprintf_s(mFile, "setAttr \".so.sor\" %f;\n", sor);}
	/*The red component of the input texture*/
	void setImageR(const FloatID& sor){fprintf_s(mFile,"connectAttr \"");sor.write(mFile);fprintf_s(mFile,"\" \"%s.so.sor\";\n",mName.c_str());}
	/*The green component of the input texture*/
	void setImageG(float sog){if(sog == 0.0) return; fprintf_s(mFile, "setAttr \".so.sog\" %f;\n", sog);}
	/*The green component of the input texture*/
	void setImageG(const FloatID& sog){fprintf_s(mFile,"connectAttr \"");sog.write(mFile);fprintf_s(mFile,"\" \"%s.so.sog\";\n",mName.c_str());}
	/*The blue component of the input texture*/
	void setImageB(float sob){if(sob == 0.0) return; fprintf_s(mFile, "setAttr \".so.sob\" %f;\n", sob);}
	/*The blue component of the input texture*/
	void setImageB(const FloatID& sob){fprintf_s(mFile,"connectAttr \"");sob.write(mFile);fprintf_s(mFile,"\" \"%s.so.sob\";\n",mName.c_str());}
	/*
	<b>Inclination</b> is the angle of the camera
	when the picture of the source image was taken.  (See
	notes in the description section above.)  Specifically,
	this is the angle formed by the camera's line of sight,
	and the environment's YZ plane.
	*/
	void setInclination(float i){if(i == 0.0) return; fprintf_s(mFile, "setAttr \".i\" %f;\n", i);}
	/*
	<b>Inclination</b> is the angle of the camera
	when the picture of the source image was taken.  (See
	notes in the description section above.)  Specifically,
	this is the angle formed by the camera's line of sight,
	and the environment's YZ plane.
	*/
	void setInclination(const FloatID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*
	<b>Elevation</b> is the angle of the camera
	when the picture of the source image was taken.  (See
	notes in the description section above.)  Specifically,
	this is the angle formed by the camera's line of sight,
	and the ground.  If the camera's
	line-of-sight was parallel to the ground, Elevation is 0.
	If the camera was pointing straight down, Elevation is 90 degrees.
	*/
	void setElevation(float e){if(e == 0.0) return; fprintf_s(mFile, "setAttr \".e\" %f;\n", e);}
	/*
	<b>Elevation</b> is the angle of the camera
	when the picture of the source image was taken.  (See
	notes in the description section above.)  Specifically,
	this is the angle formed by the camera's line of sight,
	and the ground.  If the camera's
	line-of-sight was parallel to the ground, Elevation is 0.
	If the camera was pointing straight down, Elevation is 90 degrees.
	*/
	void setElevation(const FloatID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*
	<b>Sky Radius</b> defines the distance to the sky, so
	that the texture can properly calculate the reflections
	in the re-created environment.
	*/
	void setSkyRadius(float sr){if(sr == 0.0) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*
	<b>Sky Radius</b> defines the distance to the sky, so
	that the texture can properly calculate the reflections
	in the re-created environment.
	*/
	void setSkyRadius(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*
	<b>Bottom</b> is the distance from the sphere to whatever
	surface is below it (usually the ground).  If there is
	no surface below it, set bottom to 0.  The texture will
	just use the Sky Radius for calculation in that case.
	*/
	void setBottom(float bo){if(bo == 0.0) return; fprintf_s(mFile, "setAttr \".bo\" %f;\n", bo);}
	/*
	<b>Bottom</b> is the distance from the sphere to whatever
	surface is below it (usually the ground).  If there is
	no surface below it, set bottom to 0.  The texture will
	just use the Sky Radius for calculation in that case.
	*/
	void setBottom(const FloatID& bo){fprintf_s(mFile,"connectAttr \"");bo.write(mFile);fprintf_s(mFile,"\" \"%s.bo\";\n",mName.c_str());}
	/*
	<b>Top</b> is the distance from the sphere to whatever
	surface is above it (such as a ceiling).  If there is
	no surface above it, set top to 0.  The texture will
	just use the Sky Radius for calculation in that case.
	*/
	void setTop(float to){if(to == 0.0) return; fprintf_s(mFile, "setAttr \".to\" %f;\n", to);}
	/*
	<b>Top</b> is the distance from the sphere to whatever
	surface is above it (such as a ceiling).  If there is
	no surface above it, set top to 0.  The texture will
	just use the Sky Radius for calculation in that case.
	*/
	void setTop(const FloatID& to){fprintf_s(mFile,"connectAttr \"");to.write(mFile);fprintf_s(mFile,"\" \"%s.to\";\n",mName.c_str());}
	/*
	<b>Left</b> is the distance from the sphere to whatever
	surface is to its left (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	void setLeft(float le){if(le == 0.0) return; fprintf_s(mFile, "setAttr \".le\" %f;\n", le);}
	/*
	<b>Left</b> is the distance from the sphere to whatever
	surface is to its left (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	void setLeft(const FloatID& le){fprintf_s(mFile,"connectAttr \"");le.write(mFile);fprintf_s(mFile,"\" \"%s.le\";\n",mName.c_str());}
	/*
	<b>Right</b> is the distance from the sphere to whatever
	surface is to its right (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	void setRight(float ri){if(ri == 0.0) return; fprintf_s(mFile, "setAttr \".ri\" %f;\n", ri);}
	/*
	<b>Right</b> is the distance from the sphere to whatever
	surface is to its right (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	void setRight(const FloatID& ri){fprintf_s(mFile,"connectAttr \"");ri.write(mFile);fprintf_s(mFile,"\" \"%s.ri\";\n",mName.c_str());}
	/*
	<b>Front</b> is the distance from the sphere to whatever
	surface is in front of it (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	void setFront(float fr){if(fr == 0.0) return; fprintf_s(mFile, "setAttr \".fr\" %f;\n", fr);}
	/*
	<b>Front</b> is the distance from the sphere to whatever
	surface is in front of it (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	void setFront(const FloatID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*
	<b>Front</b> is the distance from the sphere to whatever
	surface is behind it (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	void setBack(float ba){if(ba == 0.0) return; fprintf_s(mFile, "setAttr \".ba\" %f;\n", ba);}
	/*
	<b>Front</b> is the distance from the sphere to whatever
	surface is behind it (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	void setBack(const FloatID& ba){fprintf_s(mFile,"connectAttr \"");ba.write(mFile);fprintf_s(mFile,"\" \"%s.ba\";\n",mName.c_str());}
	/*
	<b>Reflect</b>.  This is normally left on, when you are
	using this texture to simulate reflections on an object.
	<p/>
	However, you can also use this texture to project the
	environment into stand-in objects you model in the scene.
	To do that, turn off the Reflect flag, and connect the
	Out Color attribute of this node to the Color attribute
	of the stand-in background objects.
	*/
	void setReflect(bool ref){if(ref == true) return; fprintf_s(mFile, "setAttr \".ref\" %i;\n", ref);}
	/*
	<b>Reflect</b>.  This is normally left on, when you are
	using this texture to simulate reflections on an object.
	<p/>
	However, you can also use this texture to project the
	environment into stand-in objects you model in the scene.
	To do that, turn off the Reflect flag, and connect the
	Out Color attribute of this node to the Color attribute
	of the stand-in background objects.
	*/
	void setReflect(const BoolID& ref){fprintf_s(mFile,"connectAttr \"");ref.write(mFile);fprintf_s(mFile,"\" \"%s.ref\";\n",mName.c_str());}
	/*
	<b>Eye Space</b> causes the position of the Env Ball's image
	file to be defined relative to the window, not the camera
	view.  If <b>Eye Space</b> is on, the texture will automatically
	match a background image file, provided both were taken
	from the same point of view.
	*/
	void setEyeSpace(bool eye){if(eye == false) return; fprintf_s(mFile, "setAttr \".eye\" %i;\n", eye);}
	/*
	<b>Eye Space</b> causes the position of the Env Ball's image
	file to be defined relative to the window, not the camera
	view.  If <b>Eye Space</b> is on, the texture will automatically
	match a background image file, provided both were taken
	from the same point of view.
	*/
	void setEyeSpace(const BoolID& eye){fprintf_s(mFile,"connectAttr \"");eye.write(mFile);fprintf_s(mFile,"\" \"%s.eye\";\n",mName.c_str());}
	/*Information bits passing along information about type of shading*/
	void setInfoBits(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Image</b> is the source image (texture) to be used in
	the environment map.  See the description section above
	and the Rendering documentation for details on how to
	create this image.  When you have an image file ready to
	use, create a File Texture using the image,
	then connect the Out Color attribute of the File Texture
	to this Image attribute.
	*/
	Float3ID getImage(){char buffer[4096];sprintf_s (buffer, "%s.so",mName.c_str());return (const char*)buffer;}
	/*The red component of the input texture*/
	FloatID getImageR(){char buffer[4096];sprintf_s (buffer, "%s.so.sor",mName.c_str());return (const char*)buffer;}
	/*The green component of the input texture*/
	FloatID getImageG(){char buffer[4096];sprintf_s (buffer, "%s.so.sog",mName.c_str());return (const char*)buffer;}
	/*The blue component of the input texture*/
	FloatID getImageB(){char buffer[4096];sprintf_s (buffer, "%s.so.sob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Inclination</b> is the angle of the camera
	when the picture of the source image was taken.  (See
	notes in the description section above.)  Specifically,
	this is the angle formed by the camera's line of sight,
	and the environment's YZ plane.
	*/
	FloatID getInclination(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*
	<b>Elevation</b> is the angle of the camera
	when the picture of the source image was taken.  (See
	notes in the description section above.)  Specifically,
	this is the angle formed by the camera's line of sight,
	and the ground.  If the camera's
	line-of-sight was parallel to the ground, Elevation is 0.
	If the camera was pointing straight down, Elevation is 90 degrees.
	*/
	FloatID getElevation(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sky Radius</b> defines the distance to the sky, so
	that the texture can properly calculate the reflections
	in the re-created environment.
	*/
	FloatID getSkyRadius(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bottom</b> is the distance from the sphere to whatever
	surface is below it (usually the ground).  If there is
	no surface below it, set bottom to 0.  The texture will
	just use the Sky Radius for calculation in that case.
	*/
	FloatID getBottom(){char buffer[4096];sprintf_s (buffer, "%s.bo",mName.c_str());return (const char*)buffer;}
	/*
	<b>Top</b> is the distance from the sphere to whatever
	surface is above it (such as a ceiling).  If there is
	no surface above it, set top to 0.  The texture will
	just use the Sky Radius for calculation in that case.
	*/
	FloatID getTop(){char buffer[4096];sprintf_s (buffer, "%s.to",mName.c_str());return (const char*)buffer;}
	/*
	<b>Left</b> is the distance from the sphere to whatever
	surface is to its left (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	FloatID getLeft(){char buffer[4096];sprintf_s (buffer, "%s.le",mName.c_str());return (const char*)buffer;}
	/*
	<b>Right</b> is the distance from the sphere to whatever
	surface is to its right (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	FloatID getRight(){char buffer[4096];sprintf_s (buffer, "%s.ri",mName.c_str());return (const char*)buffer;}
	/*
	<b>Front</b> is the distance from the sphere to whatever
	surface is in front of it (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	FloatID getFront(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Front</b> is the distance from the sphere to whatever
	surface is behind it (such as a wall).  If there is
	no surface there, set left to 0.
	*/
	FloatID getBack(){char buffer[4096];sprintf_s (buffer, "%s.ba",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reflect</b>.  This is normally left on, when you are
	using this texture to simulate reflections on an object.
	<p/>
	However, you can also use this texture to project the
	environment into stand-in objects you model in the scene.
	To do that, turn off the Reflect flag, and connect the
	Out Color attribute of this node to the Color attribute
	of the stand-in background objects.
	*/
	BoolID getReflect(){char buffer[4096];sprintf_s (buffer, "%s.ref",mName.c_str());return (const char*)buffer;}
	/*
	<b>Eye Space</b> causes the position of the Env Ball's image
	file to be defined relative to the window, not the camera
	view.  If <b>Eye Space</b> is on, the texture will automatically
	match a background image file, provided both were taken
	from the same point of view.
	*/
	BoolID getEyeSpace(){char buffer[4096];sprintf_s (buffer, "%s.eye",mName.c_str());return (const char*)buffer;}
	/*Information bits passing along information about type of shading*/
	IntID getInfoBits(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
protected:
	EnvBall(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):TextureEnv(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ENVBALL_H__
