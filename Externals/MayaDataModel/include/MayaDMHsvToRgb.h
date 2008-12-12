/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HSVTORGB_H__
#define __MayaDM_HSVTORGB_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>HSV to RGB</b> is a utility node that allows you to
  convert an HSV (Hue-Saturation-Value) color into an
  RGB (Red-Green-Blue) color.
  <p/>
  This is useful when you want to control a color using
  HSV values.  For example, say you want to animate a
  shader to run through all the rainbow colors.  (This is
  the same as animating the Hue of an HSV color).  To
  do this, create an HSV to RGB node, and connect the
  Out Rgb attribute to the shader color.  Then animate
  the first channel of InHsv (which is the Hue).
  <p/>
  In the table below, important attributes have their names
  listed in <b>bold</b> in the description column.
*/
class HsvToRgb : public DependNode
{
public:
public:
	HsvToRgb(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hsvToRgb"){}
	virtual ~HsvToRgb(){}
	/*
	<b>In Hsv</b> is the input color (represented as
	Hue, Saturation, and Value) that will be converted
	to an RGB color.
	*/
	void setInHsv(const float3& i){if(i == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i\" -type \"float3\" ");i.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>In Hsv</b> is the input color (represented as
	Hue, Saturation, and Value) that will be converted
	to an RGB color.
	*/
	void setInHsv(const Float3ID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*
	The first (Hue) component of In Hsv.  This value ranges
	from 0 to 360, representing degrees of a circle.
	The primary colors are found here:
	<ul>
	0/360: Red<br/>60: Yellow<br/>120: Green<br/>
	180: Cyan<br/>240: Blue<br/>300: Magenta
	</ul>
	*/
	void setInHsvR(float ir){if(ir == 0.0) return; fprintf_s(mFile, "setAttr \".i.ir\" %f;\n", ir);}
	/*
	The first (Hue) component of In Hsv.  This value ranges
	from 0 to 360, representing degrees of a circle.
	The primary colors are found here:
	<ul>
	0/360: Red<br/>60: Yellow<br/>120: Green<br/>
	180: Cyan<br/>240: Blue<br/>300: Magenta
	</ul>
	*/
	void setInHsvR(const FloatID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.i.ir\";\n",mName.c_str());}
	/*
	The second (Saturation) component of In Hsv.  The range is
	from 0 to 1 where 0 is a shade of grey, and 1 is a completely
	saturated color.
	*/
	void setInHsvG(float ig){if(ig == 0.0) return; fprintf_s(mFile, "setAttr \".i.ig\" %f;\n", ig);}
	/*
	The second (Saturation) component of In Hsv.  The range is
	from 0 to 1 where 0 is a shade of grey, and 1 is a completely
	saturated color.
	*/
	void setInHsvG(const FloatID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.i.ig\";\n",mName.c_str());}
	/*
	The third (Value) component of In Hsv.  The range is from
	0 to 1, where 0 is black and 1 is the brightest possible
	color of the given saturation.
	*/
	void setInHsvB(float ib){if(ib == 0.0) return; fprintf_s(mFile, "setAttr \".i.ib\" %f;\n", ib);}
	/*
	The third (Value) component of In Hsv.  The range is from
	0 to 1, where 0 is black and 1 is the brightest possible
	color of the given saturation.
	*/
	void setInHsvB(const FloatID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.i.ib\";\n",mName.c_str());}
	/*<b>Out Rgb</b> is the output RGB color calculated by this node.*/
	void setOutRgb(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The first (red) component of Out Rgb*/
	void setOutRgbR(const FloatID& or){fprintf_s(mFile,"connectAttr \"");or.write(mFile);fprintf_s(mFile,"\" \"%s.o.or\";\n",mName.c_str());}
	/*The second (green) component of Out Rgb*/
	void setOutRgbG(const FloatID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.o.og\";\n",mName.c_str());}
	/*The third (blue) component of Out Rgb*/
	void setOutRgbB(const FloatID& ob){fprintf_s(mFile,"connectAttr \"");ob.write(mFile);fprintf_s(mFile,"\" \"%s.o.ob\";\n",mName.c_str());}
	/*
	<b>In Hsv</b> is the input color (represented as
	Hue, Saturation, and Value) that will be converted
	to an RGB color.
	*/
	Float3ID getInHsv(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*
	The first (Hue) component of In Hsv.  This value ranges
	from 0 to 360, representing degrees of a circle.
	The primary colors are found here:
	<ul>
	0/360: Red<br/>60: Yellow<br/>120: Green<br/>
	180: Cyan<br/>240: Blue<br/>300: Magenta
	</ul>
	*/
	FloatID getInHsvR(){char buffer[4096];sprintf_s (buffer, "%s.i.ir",mName.c_str());return (const char*)buffer;}
	/*
	The second (Saturation) component of In Hsv.  The range is
	from 0 to 1 where 0 is a shade of grey, and 1 is a completely
	saturated color.
	*/
	FloatID getInHsvG(){char buffer[4096];sprintf_s (buffer, "%s.i.ig",mName.c_str());return (const char*)buffer;}
	/*
	The third (Value) component of In Hsv.  The range is from
	0 to 1, where 0 is black and 1 is the brightest possible
	color of the given saturation.
	*/
	FloatID getInHsvB(){char buffer[4096];sprintf_s (buffer, "%s.i.ib",mName.c_str());return (const char*)buffer;}
	/*<b>Out Rgb</b> is the output RGB color calculated by this node.*/
	Float3ID getOutRgb(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The first (red) component of Out Rgb*/
	FloatID getOutRgbR(){char buffer[4096];sprintf_s (buffer, "%s.o.or",mName.c_str());return (const char*)buffer;}
	/*The second (green) component of Out Rgb*/
	FloatID getOutRgbG(){char buffer[4096];sprintf_s (buffer, "%s.o.og",mName.c_str());return (const char*)buffer;}
	/*The third (blue) component of Out Rgb*/
	FloatID getOutRgbB(){char buffer[4096];sprintf_s (buffer, "%s.o.ob",mName.c_str());return (const char*)buffer;}
protected:
	HsvToRgb(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HSVTORGB_H__
