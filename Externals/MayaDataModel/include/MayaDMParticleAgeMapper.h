/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARTICLEAGEMAPPER_H__
#define __MayaDM_PARTICLEAGEMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Particle Age Mapper</b> is a utility node that allows you
  to use a texture map to control a particle's color, transparency
  or incandescence when you are doing software particle rendering
  <p/>
  Normally, this node is created automatically when you click
  on the map button beside the Life Color, Life Transparency,
  or Life Incandescence fields in the Attribute Editor of
  a Particle Cloud.
 <p/>
  For example, if you map a "Cloth" texture to Life Color, you
  will get the following nodes and connections:
 <pre>
  ParticleAgeMapper     Place2dTexture          Cloth              ParticleCloud
  -----------------     --------------          -----              -------------
  out UV Coord -------> UV Coord
                        Out UV ---------------> UV Coord
                        Out UV Filter Size ---> UV Filter Size
                                                Out Color -------> Color
 </pre>
 <b>How it Works:</b> Each time a particle in the Particle Cloud is
 rendered, the Particle Age Mapper knows its current age.  This is
 converted to a number between 0 and 1, based on either the particle's
 total life-span, or another number that you provide (in the
 Time Scale attribute).  The output of the Particle Age Mapper
 node is a UV coordinate --- the "U" value is always 0, and the
 "V" value is the number between 0 and 1.
 <p/>
 <b>Example:</b>Say you want to have particles that are emitted white-hot, then
 cool to red over their lifetime, before disappearing.  To do this,
 use a Particle Age Mapper with a Ramp texture, set to type V Ramp.
 The ramp should go from white at the start to red
 at the end.  In the Particle Age Mapper, turn on Relative Age.
 When the particles are rendered, the "young" particles will
 have a low value for age, and therefore take their color from the
 beginning (white) part of the ramp.  Older particles will get
 their color from the other end of the ramp.
 <p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class ParticleAgeMapper : public DependNode
{
public:
public:
	ParticleAgeMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "particleAgeMapper"){}
	virtual ~ParticleAgeMapper(){}
	/*
	<b>Out UV Coord</b> is the output coordinates calculated
	by this node.  The "U" value will always be 0, and the
	"V" value will be based on the age of the particle being
	rendered.<p/>This attribute should be connected to the
	UV Coord attribute of a texture placement node.
	*/
	void setOutUvCoord(const Float2ID& ouv){fprintf_s(mFile,"connectAttr \"");ouv.write(mFile);fprintf_s(mFile,"\" \"%s.ouv\";\n",mName.c_str());}
	/*Output U Coord (always 0)*/
	void setOutUCoord(const FloatID& ouc){fprintf_s(mFile,"connectAttr \"");ouc.write(mFile);fprintf_s(mFile,"\" \"%s.ouv.ouc\";\n",mName.c_str());}
	/*Output V Coord (based on particle age)*/
	void setOutVCoord(const FloatID& ovc){fprintf_s(mFile,"connectAttr \"");ovc.write(mFile);fprintf_s(mFile,"\" \"%s.ouv.ovc\";\n",mName.c_str());}
	/*Particle Age*/
	void setParticleAge(const FloatID& pa){fprintf_s(mFile,"connectAttr \"");pa.write(mFile);fprintf_s(mFile,"\" \"%s.pa\";\n",mName.c_str());}
	/*Particle Lifespan*/
	void setParticleLifespan(const FloatID& pls){fprintf_s(mFile,"connectAttr \"");pls.write(mFile);fprintf_s(mFile,"\" \"%s.pls\";\n",mName.c_str());}
	/*
	<b>Relative Age:</b>  If you turn this on, then the output
	of this node (the V Coord) will be a fraction of the particle's
	total lifespan.  That is, it will be a number between 0 and 1,
	where 1 is the total lifespan of the particular particle.  So
	particles with a shorter lifespans will go through the whole
	texture quicker than particles with longer lifespans.
	<p/>
	If you leave Relative Age turned off, then the output of
	this node (the V Coord) will be the particle's current age,
	divided by the value of the Time Scale attribute.  For example,
	if Time Scale is set to 5 seconds, and the particle is 1 second
	old, then the output of this node will be 0.2.  So all particles
	will take the same amount of time to go through the texture,
	regardless of their lifespans.
	<p/>
	If the particle age is greater than Time Scale, this node
	will map it back to a number between 0 and 1, based on the
	Fold At End attribute (see below)
	*/
	void setRelativeAge(bool rea){if(rea == false) return; fprintf_s(mFile, "setAttr \".rea\" %i;\n", rea);}
	/*
	<b>Relative Age:</b>  If you turn this on, then the output
	of this node (the V Coord) will be a fraction of the particle's
	total lifespan.  That is, it will be a number between 0 and 1,
	where 1 is the total lifespan of the particular particle.  So
	particles with a shorter lifespans will go through the whole
	texture quicker than particles with longer lifespans.
	<p/>
	If you leave Relative Age turned off, then the output of
	this node (the V Coord) will be the particle's current age,
	divided by the value of the Time Scale attribute.  For example,
	if Time Scale is set to 5 seconds, and the particle is 1 second
	old, then the output of this node will be 0.2.  So all particles
	will take the same amount of time to go through the texture,
	regardless of their lifespans.
	<p/>
	If the particle age is greater than Time Scale, this node
	will map it back to a number between 0 and 1, based on the
	Fold At End attribute (see below)
	*/
	void setRelativeAge(const BoolID& rea){fprintf_s(mFile,"connectAttr \"");rea.write(mFile);fprintf_s(mFile,"\" \"%s.rea\";\n",mName.c_str());}
	/*
	<b>Time Scale</b> is the time range over which the particles
	should use the whole texture.  This attribute is only used
	when Relative Age is turned off. (see above).
	<p/>
	<b>Note:</b> This value is always in seconds, not frames
	or anything else.
	*/
	void setTimeScale(float ts){if(ts == 1) return; fprintf_s(mFile, "setAttr \".ts\" %f;\n", ts);}
	/*
	<b>Time Scale</b> is the time range over which the particles
	should use the whole texture.  This attribute is only used
	when Relative Age is turned off. (see above).
	<p/>
	<b>Note:</b> This value is always in seconds, not frames
	or anything else.
	*/
	void setTimeScale(const FloatID& ts){fprintf_s(mFile,"connectAttr \"");ts.write(mFile);fprintf_s(mFile,"\" \"%s.ts\";\n",mName.c_str());}
	/*
	<b>Fold At End</b> controls how this node deals with output
	values that go outside the 0 to 1 range.  It is only meaningful
	when Relative Age is turned off, and some particles get older
	than the value of Time Scale.
	<p/>
	If Fold At End is turned on, then values above 1.0 are "folded
	back", that is, turned around.  If Fold At End is turned off,
	then the values are wrapped around back to 0.  You can think
	of Fold At End ON meaning "oscillate" and Fold At End OFF meaning
	"Loop".
	<p/>For example, lets say you set Time Scale to 10 seconds,
	and your particles live longer than that.  Here is the
	output of this node:
	<pre>
	Fold At End ON:
	Particle Age:  7    8    9    10   11   12   13
	Output V:     .7   .8   .9   1.0   .9   .8   .7
	----
	Fold At End OFF:
	Particle Age:  7    8    9    10   11   12   13
	Output V:     .7   .8   .9   1.0   .1   .2   .3
	</pre>
	*/
	void setFoldAtEnd(bool fae){if(fae == false) return; fprintf_s(mFile, "setAttr \".fae\" %i;\n", fae);}
	/*
	<b>Fold At End</b> controls how this node deals with output
	values that go outside the 0 to 1 range.  It is only meaningful
	when Relative Age is turned off, and some particles get older
	than the value of Time Scale.
	<p/>
	If Fold At End is turned on, then values above 1.0 are "folded
	back", that is, turned around.  If Fold At End is turned off,
	then the values are wrapped around back to 0.  You can think
	of Fold At End ON meaning "oscillate" and Fold At End OFF meaning
	"Loop".
	<p/>For example, lets say you set Time Scale to 10 seconds,
	and your particles live longer than that.  Here is the
	output of this node:
	<pre>
	Fold At End ON:
	Particle Age:  7    8    9    10   11   12   13
	Output V:     .7   .8   .9   1.0   .9   .8   .7
	----
	Fold At End OFF:
	Particle Age:  7    8    9    10   11   12   13
	Output V:     .7   .8   .9   1.0   .1   .2   .3
	</pre>
	*/
	void setFoldAtEnd(const BoolID& fae){fprintf_s(mFile,"connectAttr \"");fae.write(mFile);fprintf_s(mFile,"\" \"%s.fae\";\n",mName.c_str());}
	/*
	<b>Out UV Coord</b> is the output coordinates calculated
	by this node.  The "U" value will always be 0, and the
	"V" value will be based on the age of the particle being
	rendered.<p/>This attribute should be connected to the
	UV Coord attribute of a texture placement node.
	*/
	Float2ID getOutUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.ouv",mName.c_str());return (const char*)buffer;}
	/*Output U Coord (always 0)*/
	FloatID getOutUCoord(){char buffer[4096];sprintf_s (buffer, "%s.ouv.ouc",mName.c_str());return (const char*)buffer;}
	/*Output V Coord (based on particle age)*/
	FloatID getOutVCoord(){char buffer[4096];sprintf_s (buffer, "%s.ouv.ovc",mName.c_str());return (const char*)buffer;}
	/*Particle Age*/
	FloatID getParticleAge(){char buffer[4096];sprintf_s (buffer, "%s.pa",mName.c_str());return (const char*)buffer;}
	/*Particle Lifespan*/
	FloatID getParticleLifespan(){char buffer[4096];sprintf_s (buffer, "%s.pls",mName.c_str());return (const char*)buffer;}
	/*
	<b>Relative Age:</b>  If you turn this on, then the output
	of this node (the V Coord) will be a fraction of the particle's
	total lifespan.  That is, it will be a number between 0 and 1,
	where 1 is the total lifespan of the particular particle.  So
	particles with a shorter lifespans will go through the whole
	texture quicker than particles with longer lifespans.
	<p/>
	If you leave Relative Age turned off, then the output of
	this node (the V Coord) will be the particle's current age,
	divided by the value of the Time Scale attribute.  For example,
	if Time Scale is set to 5 seconds, and the particle is 1 second
	old, then the output of this node will be 0.2.  So all particles
	will take the same amount of time to go through the texture,
	regardless of their lifespans.
	<p/>
	If the particle age is greater than Time Scale, this node
	will map it back to a number between 0 and 1, based on the
	Fold At End attribute (see below)
	*/
	BoolID getRelativeAge(){char buffer[4096];sprintf_s (buffer, "%s.rea",mName.c_str());return (const char*)buffer;}
	/*
	<b>Time Scale</b> is the time range over which the particles
	should use the whole texture.  This attribute is only used
	when Relative Age is turned off. (see above).
	<p/>
	<b>Note:</b> This value is always in seconds, not frames
	or anything else.
	*/
	FloatID getTimeScale(){char buffer[4096];sprintf_s (buffer, "%s.ts",mName.c_str());return (const char*)buffer;}
	/*
	<b>Fold At End</b> controls how this node deals with output
	values that go outside the 0 to 1 range.  It is only meaningful
	when Relative Age is turned off, and some particles get older
	than the value of Time Scale.
	<p/>
	If Fold At End is turned on, then values above 1.0 are "folded
	back", that is, turned around.  If Fold At End is turned off,
	then the values are wrapped around back to 0.  You can think
	of Fold At End ON meaning "oscillate" and Fold At End OFF meaning
	"Loop".
	<p/>For example, lets say you set Time Scale to 10 seconds,
	and your particles live longer than that.  Here is the
	output of this node:
	<pre>
	Fold At End ON:
	Particle Age:  7    8    9    10   11   12   13
	Output V:     .7   .8   .9   1.0   .9   .8   .7
	----
	Fold At End OFF:
	Particle Age:  7    8    9    10   11   12   13
	Output V:     .7   .8   .9   1.0   .1   .2   .3
	</pre>
	*/
	BoolID getFoldAtEnd(){char buffer[4096];sprintf_s (buffer, "%s.fae",mName.c_str());return (const char*)buffer;}
protected:
	ParticleAgeMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARTICLEAGEMAPPER_H__
