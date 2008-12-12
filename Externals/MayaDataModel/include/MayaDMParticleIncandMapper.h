/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLEINCANDMAPPER_H__
#define __MayaDM_PARTICLEINCANDMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Particle Incand Mapper</b> is a utility node used for certain
  cases when you are rendering particles using Software Rendering.
  <p/>
  Normally, when you do Software rendering, you control the particle
  incandescence using the Incandescence attribute of the Particle Cloud node.  When
  you do Hardware rendering, you control the particle Incandescence using
  the attributes in the Particle Shape node.  The Particle Shape node
  allows you to do many things; You
  can add per-particle attributes, with special expressions to
  set the incandescence.  These values are all used automatically by the
  Hardware renderer, but not by the Software renderer.  The Particle
  Incand Mapper node allows you to use all these attributes in the Software
  renderer as well as the Hardware renderer.
  <p/>
  <b>To use this node:</b> Create a Particle Incand Mapper node.  Connect
  its Particle Incandescence attribute to the Incandescence attribute of the
  Particle Cloud object associated with the particles you are rendering.
  Now when you do Software rendering, particles
  will get their incandescence from the attributes in the particle shape, just
  like they would if you were doing a Hardware render.
*/
class ParticleIncandMapper : public DependNode
{
public:
public:
	ParticleIncandMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleIncandMapper"){}
	virtual ~ParticleIncandMapper(){}
	/*
	<b>Particle Incandescence</b>.  Connect this to the Incadescence
	attribute of a Particle Cloud node.
	*/
	void setParticleIncandescence(const float3& pi){fprintf_s(mFile, "setAttr \".pi\" -type \"float3\" ");pi.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Particle Incandescence</b>.  Connect this to the Incadescence
	attribute of a Particle Cloud node.
	*/
	void setParticleIncandescence(const Float3ID& pi){fprintf_s(mFile,"connectAttr \"");pi.write(mFile);fprintf_s(mFile,"\" \"%s.pi\";\n",mName.c_str());}
	/*Particle Incandescence red value*/
	void setParticleIncandescenceR(float pir){if(pir == 0.0) return; fprintf_s(mFile, "setAttr \".pi.pir\" %f;\n", pir);}
	/*Particle Incandescence red value*/
	void setParticleIncandescenceR(const FloatID& pir){fprintf_s(mFile,"connectAttr \"");pir.write(mFile);fprintf_s(mFile,"\" \"%s.pi.pir\";\n",mName.c_str());}
	/*Particle Incandescence green value*/
	void setParticleIncandescenceG(float pig){if(pig == 0.0) return; fprintf_s(mFile, "setAttr \".pi.pig\" %f;\n", pig);}
	/*Particle Incandescence green value*/
	void setParticleIncandescenceG(const FloatID& pig){fprintf_s(mFile,"connectAttr \"");pig.write(mFile);fprintf_s(mFile,"\" \"%s.pi.pig\";\n",mName.c_str());}
	/*Particle Incandescence blue value*/
	void setParticleIncandescenceB(float pib){if(pib == 0.0) return; fprintf_s(mFile, "setAttr \".pi.pib\" %f;\n", pib);}
	/*Particle Incandescence blue value*/
	void setParticleIncandescenceB(const FloatID& pib){fprintf_s(mFile,"connectAttr \"");pib.write(mFile);fprintf_s(mFile,"\" \"%s.pi.pib\";\n",mName.c_str());}
	/*
	<b>Particle Incandescence</b>.  Connect this to the Incadescence
	attribute of a Particle Cloud node.
	*/
	Float3ID getParticleIncandescence(){char buffer[4096];sprintf_s (buffer, "%s.pi",mName.c_str());return (const char*)buffer;}
	/*Particle Incandescence red value*/
	FloatID getParticleIncandescenceR(){char buffer[4096];sprintf_s (buffer, "%s.pi.pir",mName.c_str());return (const char*)buffer;}
	/*Particle Incandescence green value*/
	FloatID getParticleIncandescenceG(){char buffer[4096];sprintf_s (buffer, "%s.pi.pig",mName.c_str());return (const char*)buffer;}
	/*Particle Incandescence blue value*/
	FloatID getParticleIncandescenceB(){char buffer[4096];sprintf_s (buffer, "%s.pi.pib",mName.c_str());return (const char*)buffer;}
protected:
	ParticleIncandMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLEINCANDMAPPER_H__
