/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GAMMACORRECT_H__
#define __MayaDM_GAMMACORRECT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Gamma Correct</b> is a utility node that allows you
 to do gamma correction on a color or texture.
 <p/>
 Gamma Correction allows you to smoothly remap the colors in
 an image.  Extreme values (very light or very dark) will
 not change much, but midrange tones can be made brighter or darker.
 <p/>
 This node allows you to specify different gamma values for the
 three channels of the input.
 <p/>
 The typical formula for calculating gamma is:
 <pre>
     new == old ** (1.0/Gamma)
 </pre>
 <p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class GammaCorrect : public DependNode
{
public:
public:
	GammaCorrect(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "gammaCorrect"){}
	virtual ~GammaCorrect(){}
	/*
	<b>Value</b> is the input color or texture, which
	will be gamma-corrected.
	*/
	void setValue(const float3& v){if(v == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".v\" -type \"float3\" ");v.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Value</b> is the input color or texture, which
	will be gamma-corrected.
	*/
	void setValue(const Float3ID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*The first component of Value*/
	void setValueX(float vx){if(vx == 0.0) return; fprintf_s(mFile, "setAttr \".v.vx\" %f;\n", vx);}
	/*The first component of Value*/
	void setValueX(const FloatID& vx){fprintf_s(mFile,"connectAttr \"");vx.write(mFile);fprintf_s(mFile,"\" \"%s.v.vx\";\n",mName.c_str());}
	/*The second component of Value*/
	void setValueY(float vy){if(vy == 0.0) return; fprintf_s(mFile, "setAttr \".v.vy\" %f;\n", vy);}
	/*The second component of Value*/
	void setValueY(const FloatID& vy){fprintf_s(mFile,"connectAttr \"");vy.write(mFile);fprintf_s(mFile,"\" \"%s.v.vy\";\n",mName.c_str());}
	/*The third component of Value*/
	void setValueZ(float vz){if(vz == 0.0) return; fprintf_s(mFile, "setAttr \".v.vz\" %f;\n", vz);}
	/*The third component of Value*/
	void setValueZ(const FloatID& vz){fprintf_s(mFile,"connectAttr \"");vz.write(mFile);fprintf_s(mFile,"\" \"%s.v.vz\";\n",mName.c_str());}
	/*
	<b>Gamma</b> controls the amount of gamma correction
	applied to each channel.  A value of 1 means that the
	the color is not adjusted at all.  Increase Gamma to
	make the mid-range tones brighter.  Decrease Gamma to
	make them darker.
	*/
	void setGamma(const float3& g){if(g == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".g\" -type \"float3\" ");g.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Gamma</b> controls the amount of gamma correction
	applied to each channel.  A value of 1 means that the
	the color is not adjusted at all.  Increase Gamma to
	make the mid-range tones brighter.  Decrease Gamma to
	make them darker.
	*/
	void setGamma(const Float3ID& g){fprintf_s(mFile,"connectAttr \"");g.write(mFile);fprintf_s(mFile,"\" \"%s.g\";\n",mName.c_str());}
	/*The first component of Gamma*/
	void setGammaX(float gx){if(gx == 0.0) return; fprintf_s(mFile, "setAttr \".g.gx\" %f;\n", gx);}
	/*The first component of Gamma*/
	void setGammaX(const FloatID& gx){fprintf_s(mFile,"connectAttr \"");gx.write(mFile);fprintf_s(mFile,"\" \"%s.g.gx\";\n",mName.c_str());}
	/*The second component of Gamma*/
	void setGammaY(float gy){if(gy == 0.0) return; fprintf_s(mFile, "setAttr \".g.gy\" %f;\n", gy);}
	/*The second component of Gamma*/
	void setGammaY(const FloatID& gy){fprintf_s(mFile,"connectAttr \"");gy.write(mFile);fprintf_s(mFile,"\" \"%s.g.gy\";\n",mName.c_str());}
	/*The third component of Gamma*/
	void setGammaZ(float gz){if(gz == 0.0) return; fprintf_s(mFile, "setAttr \".g.gz\" %f;\n", gz);}
	/*The third component of Gamma*/
	void setGammaZ(const FloatID& gz){fprintf_s(mFile,"connectAttr \"");gz.write(mFile);fprintf_s(mFile,"\" \"%s.g.gz\";\n",mName.c_str());}
	/*
	<b>Out Value</b> is the gamma-corrected color calculated
	by this node.
	*/
	void setOutValue(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The first component of Out Value*/
	void setOutValueX(const FloatID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*The second component of Out Value*/
	void setOutValueY(const FloatID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*The third component of Out Value*/
	void setOutValueZ(const FloatID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*
	<b>Value</b> is the input color or texture, which
	will be gamma-corrected.
	*/
	Float3ID getValue(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*The first component of Value*/
	FloatID getValueX(){char buffer[4096];sprintf_s (buffer, "%s.v.vx",mName.c_str());return (const char*)buffer;}
	/*The second component of Value*/
	FloatID getValueY(){char buffer[4096];sprintf_s (buffer, "%s.v.vy",mName.c_str());return (const char*)buffer;}
	/*The third component of Value*/
	FloatID getValueZ(){char buffer[4096];sprintf_s (buffer, "%s.v.vz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Gamma</b> controls the amount of gamma correction
	applied to each channel.  A value of 1 means that the
	the color is not adjusted at all.  Increase Gamma to
	make the mid-range tones brighter.  Decrease Gamma to
	make them darker.
	*/
	Float3ID getGamma(){char buffer[4096];sprintf_s (buffer, "%s.g",mName.c_str());return (const char*)buffer;}
	/*The first component of Gamma*/
	FloatID getGammaX(){char buffer[4096];sprintf_s (buffer, "%s.g.gx",mName.c_str());return (const char*)buffer;}
	/*The second component of Gamma*/
	FloatID getGammaY(){char buffer[4096];sprintf_s (buffer, "%s.g.gy",mName.c_str());return (const char*)buffer;}
	/*The third component of Gamma*/
	FloatID getGammaZ(){char buffer[4096];sprintf_s (buffer, "%s.g.gz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Value</b> is the gamma-corrected color calculated
	by this node.
	*/
	Float3ID getOutValue(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The first component of Out Value*/
	FloatID getOutValueX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*The second component of Out Value*/
	FloatID getOutValueY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*The third component of Out Value*/
	FloatID getOutValueZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
protected:
	GammaCorrect(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GAMMACORRECT_H__
