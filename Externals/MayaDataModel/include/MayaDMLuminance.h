/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LUMINANCE_H__
#define __MayaDM_LUMINANCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Luminance</b> is a utility node that takes in a color,
  and outputs a luminance value.
  <p/>
  Luminance simply means the apparent brightness of a color,
  as seen by the human eye.  The human eye is not equally sensitive
  across the whole spectrum; greens appear brighter than reds, and
  reds brighter than blue.  For this reason, luminance is calculated
  by this equation:
 <pre>
   Luminance = 0.3 * red + 0.59 * green + 0.11 * blue
 </pre>
  You can use the Luminance node to convert a color image or texture
  into a monochrome (black-and-white) image.  To do this, connect
  the texture's Out Color into the Luminance node's Value attribute,
  then connect the Luminance node's Out Value attribute to
  all three color channels (R, G, and B) of a shader.
 <p/>
  In the table below, imporant attributes have their names
  listed in <b>bold</b> in the description column.
*/
class Luminance : public DependNode
{
public:
public:
	Luminance(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "luminance"){}
	virtual ~Luminance(){}
	/*<b>Value</b> is the input color or texture.*/
	void setValue(const float3& v){if(v == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".v\" -type \"float3\" ");v.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Value</b> is the input color or texture.*/
	void setValue(const Float3ID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*The first component of Value*/
	void setValueR(float vr){if(vr == 0.0) return; fprintf_s(mFile, "setAttr \".v.vr\" %f;\n", vr);}
	/*The first component of Value*/
	void setValueR(const FloatID& vr){fprintf_s(mFile,"connectAttr \"");vr.write(mFile);fprintf_s(mFile,"\" \"%s.v.vr\";\n",mName.c_str());}
	/*The second component of Value*/
	void setValueG(float vg){if(vg == 0.0) return; fprintf_s(mFile, "setAttr \".v.vg\" %f;\n", vg);}
	/*The second component of Value*/
	void setValueG(const FloatID& vg){fprintf_s(mFile,"connectAttr \"");vg.write(mFile);fprintf_s(mFile,"\" \"%s.v.vg\";\n",mName.c_str());}
	/*The third component of Value*/
	void setValueB(float vb){if(vb == 0.0) return; fprintf_s(mFile, "setAttr \".v.vb\" %f;\n", vb);}
	/*The third component of Value*/
	void setValueB(const FloatID& vb){fprintf_s(mFile,"connectAttr \"");vb.write(mFile);fprintf_s(mFile,"\" \"%s.v.vb\";\n",mName.c_str());}
	/*<b>Out Value</b> is the luminance of the Value input.*/
	void setOutValue(const FloatID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*<b>Value</b> is the input color or texture.*/
	Float3ID getValue(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*The first component of Value*/
	FloatID getValueR(){char buffer[4096];sprintf_s (buffer, "%s.v.vr",mName.c_str());return (const char*)buffer;}
	/*The second component of Value*/
	FloatID getValueG(){char buffer[4096];sprintf_s (buffer, "%s.v.vg",mName.c_str());return (const char*)buffer;}
	/*The third component of Value*/
	FloatID getValueB(){char buffer[4096];sprintf_s (buffer, "%s.v.vb",mName.c_str());return (const char*)buffer;}
	/*<b>Out Value</b> is the luminance of the Value input.*/
	FloatID getOutValue(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	Luminance(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LUMINANCE_H__
