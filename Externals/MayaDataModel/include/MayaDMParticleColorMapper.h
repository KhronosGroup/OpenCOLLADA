/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLECOLORMAPPER_H__
#define __MayaDM_PARTICLECOLORMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Particle Color Mapper</b> is a utility node used for certain
  cases when you are rendering particles using Software Rendering.
  <p/>
  Normally, when you do Software rendering, you control the particle
  colors using the Color attribute of the Particle Cloud node.  When
  you do Hardware rendering, you control the particle colors using
  the attributes in the Particle Shape node.  The Particle Shape node
  allows you to do many things; You
  can add per-particle attributes, with special expressions to
  set the colors.  These values are all used automatically by the
  Hardware renderer, but not by the Software renderer.  The Particle
  Color Mapper node allows you to use all these attributes in the Software
  renderer as well as the Hardware renderer.
  <p/>
  <b>To use this node:</b> Create a Particle Age Mapper node.  Connect
  its Particle Color attribute to the Color attribute of the
  Particle Cloud object associated with the particles you are rendering.
  Now when you do Software rendering, particles
  will get their color from the attributes in the particle shape, just
  like they would if you were doing a Hardware render.
 <p/>
  <b>Note:</b> There are differences in result between using hardware
  rendering and software rendering.  In software rendering, for example,
  color computation takes into account the lighting in the scene.  Hardware
  does not.
*/
class ParticleColorMapper : public DependNode
{
public:
public:
	ParticleColorMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleColorMapper"){}
	virtual ~ParticleColorMapper(){}
	/*
	<b>Particle Color</b>.  Connect this attribute to the Color
	attribute of a Particle Cloud node.
	*/
	void setParticleColor(const float3& pc){fprintf_s(mFile, "setAttr \".pc\" -type \"float3\" ");pc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Particle Color</b>.  Connect this attribute to the Color
	attribute of a Particle Cloud node.
	*/
	void setParticleColor(const Float3ID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*Particle Color red value*/
	void setParticleColorR(float pcr){if(pcr == 0.0) return; fprintf_s(mFile, "setAttr \".pc.pcr\" %f;\n", pcr);}
	/*Particle Color red value*/
	void setParticleColorR(const FloatID& pcr){fprintf_s(mFile,"connectAttr \"");pcr.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcr\";\n",mName.c_str());}
	/*Particle Color green value*/
	void setParticleColorG(float pcg){if(pcg == 0.0) return; fprintf_s(mFile, "setAttr \".pc.pcg\" %f;\n", pcg);}
	/*Particle Color green value*/
	void setParticleColorG(const FloatID& pcg){fprintf_s(mFile,"connectAttr \"");pcg.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcg\";\n",mName.c_str());}
	/*Particle Color blue value*/
	void setParticleColorB(float pcb){if(pcb == 0.0) return; fprintf_s(mFile, "setAttr \".pc.pcb\" %f;\n", pcb);}
	/*Particle Color blue value*/
	void setParticleColorB(const FloatID& pcb){fprintf_s(mFile,"connectAttr \"");pcb.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcb\";\n",mName.c_str());}
	/*
	<b>Particle Color</b>.  Connect this attribute to the Color
	attribute of a Particle Cloud node.
	*/
	Float3ID getParticleColor(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*Particle Color red value*/
	FloatID getParticleColorR(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcr",mName.c_str());return (const char*)buffer;}
	/*Particle Color green value*/
	FloatID getParticleColorG(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcg",mName.c_str());return (const char*)buffer;}
	/*Particle Color blue value*/
	FloatID getParticleColorB(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcb",mName.c_str());return (const char*)buffer;}
protected:
	ParticleColorMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLECOLORMAPPER_H__
