/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLETRANSPMAPPER_H__
#define __MayaDM_PARTICLETRANSPMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Particle Transp Mapper</b> is a utility node used for certain
  cases when you are rendering particles using Software Rendering.
  <p/>
  Normally, when you do Software rendering, you control the particle
  transparency using the Transparency attribute of the Particle Cloud node.  When
  you do Hardware rendering, you control the particle transparency using
  the attributes in the Particle Shape node.  The Particle Shape node
  allows you to do many things; You
  can add per-particle attributes, with special expressions to
  set the transparency.  These values are all used automatically by the
  Hardware renderer, but not by the Software renderer.  The Particle
  Transp Mapper node allows you to use all these attributes in the Software
  renderer as well as the Hardware renderer.
  <p/>
  <b>To use this node:</b> Create a Particle Transp Mapper node.  Connect
  its Particle Transparency attribute to the Transparency attribute of the
  Particle Cloud object associated with the particles you are rendering.
  Now when you do Software rendering, particles
  will get their transparency from the attributes in the particle shape, just
  like they would if you were doing a Hardware render.
        <p/>
  <b>Note:</b> There are differences in result between using hardware
  rendering and software rendering.  In hardware rendering, for example,
  transparency is treated as though the particles were in a separated,
  non-overlapping layer, but in software rendering they are treated
  as volumes, with overlapping allowed.
*/
class ParticleTranspMapper : public DependNode
{
public:
public:
	ParticleTranspMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleTranspMapper"){}
	virtual ~ParticleTranspMapper(){}
	/*
	<b>Particle Transparency</b>.  Connect this to the Transparency
	attribute of a Particle Cloud node.
	*/
	void setParticleTransparency(const float3& pt){fprintf_s(mFile, "setAttr \".pt\" -type \"float3\" ");pt.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Particle Transparency</b>.  Connect this to the Transparency
	attribute of a Particle Cloud node.
	*/
	void setParticleTransparency(const Float3ID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
	/*Particle Transparency red value*/
	void setParticleTransparencyR(float ptr){if(ptr == 0.0) return; fprintf_s(mFile, "setAttr \".pt.ptr\" %f;\n", ptr);}
	/*Particle Transparency red value*/
	void setParticleTransparencyR(const FloatID& ptr){fprintf_s(mFile,"connectAttr \"");ptr.write(mFile);fprintf_s(mFile,"\" \"%s.pt.ptr\";\n",mName.c_str());}
	/*Particle Transparency green value*/
	void setParticleTransparencyG(float ptg){if(ptg == 0.0) return; fprintf_s(mFile, "setAttr \".pt.ptg\" %f;\n", ptg);}
	/*Particle Transparency green value*/
	void setParticleTransparencyG(const FloatID& ptg){fprintf_s(mFile,"connectAttr \"");ptg.write(mFile);fprintf_s(mFile,"\" \"%s.pt.ptg\";\n",mName.c_str());}
	/*Particle Transparency blue value*/
	void setParticleTransparencyB(float ptb){if(ptb == 0.0) return; fprintf_s(mFile, "setAttr \".pt.ptb\" %f;\n", ptb);}
	/*Particle Transparency blue value*/
	void setParticleTransparencyB(const FloatID& ptb){fprintf_s(mFile,"connectAttr \"");ptb.write(mFile);fprintf_s(mFile,"\" \"%s.pt.ptb\";\n",mName.c_str());}
	/*
	<b>Particle Transparency</b>.  Connect this to the Transparency
	attribute of a Particle Cloud node.
	*/
	Float3ID getParticleTransparency(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*Particle Transparency red value*/
	FloatID getParticleTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.pt.ptr",mName.c_str());return (const char*)buffer;}
	/*Particle Transparency green value*/
	FloatID getParticleTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.pt.ptg",mName.c_str());return (const char*)buffer;}
	/*Particle Transparency blue value*/
	FloatID getParticleTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.pt.ptb",mName.c_str());return (const char*)buffer;}
protected:
	ParticleTranspMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLETRANSPMAPPER_H__
