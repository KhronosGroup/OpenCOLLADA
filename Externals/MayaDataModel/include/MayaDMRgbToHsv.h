/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RGBTOHSV_H__
#define __MayaDM_RGBTOHSV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>RGB to HSV</b> is a utility node that allows you to
  convert an RGB (Red-Green-Blue) color into an
  HSV (Hue-Saturation-Value) color.
  <p/>
  There are some kinds of effects that are easier to calculate
  using HSV values than RGB values.  With this node, you can
  convert the output of any shading network into HSV values.
 <p/>
  <b>Example:</b> Say you want to 'rotate' the Hue values of an
  image, like when you adjust the Hue control on a color television.
  This shifts the colors in the image around;  red becomes yellow,
  green becomes cyan, etc.  You could do that like this:
<pre>
  File Texture    RGBtoHSV    PlusMinusAverage      HSVtoRGB   Blinn
  ------------    --------    ----------------      --------   -----
  Out Color------>In Rgb
                  Out Hsv---->Input3D[0]
                              Input3D[1]=(60,0,0)
                              Operation = "Sum"
                              Output3D------------->In Hsv
                                                    Out Rgb--->Color
</pre>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class RgbToHsv : public DependNode
{
public:
public:
	RgbToHsv(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "rgbToHsv"){}
	virtual ~RgbToHsv(){}
	/*
	<b>In Rgb</b> is the color that will be converted
	into HSV values.
	*/
	void setInRgb(const float3& i){if(i == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i\" -type \"float3\" ");i.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>In Rgb</b> is the color that will be converted
	into HSV values.
	*/
	void setInRgb(const Float3ID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*The first (red) component of In Rgb*/
	void setInRgbR(float ir){if(ir == 0.0) return; fprintf_s(mFile, "setAttr \".i.ir\" %f;\n", ir);}
	/*The first (red) component of In Rgb*/
	void setInRgbR(const FloatID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.i.ir\";\n",mName.c_str());}
	/*The second (green) component of In Rgb*/
	void setInRgbG(float ig){if(ig == 0.0) return; fprintf_s(mFile, "setAttr \".i.ig\" %f;\n", ig);}
	/*The second (green) component of In Rgb*/
	void setInRgbG(const FloatID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.i.ig\";\n",mName.c_str());}
	/*The third (blue) component of In Rgb*/
	void setInRgbB(float ib){if(ib == 0.0) return; fprintf_s(mFile, "setAttr \".i.ib\" %f;\n", ib);}
	/*The third (blue) component of In Rgb*/
	void setInRgbB(const FloatID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.i.ib\";\n",mName.c_str());}
	/*<b>Out Hsv</b> is the output HSV values.*/
	void setOutHsv(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*
	The first (hue) component of Out Hsv.  This value ranges
	from 0 to 360, representing degrees of a circle.
	The primary colors are found here:
	<ul>
	0/360: Red<br/>60: Yellow<br/>120: Green<br/>
	180: Cyan<br/>240: Blue<br/>300: Magenta
	</ul>
	*/
	void setOutHsvH(const FloatID& oh){fprintf_s(mFile,"connectAttr \"");oh.write(mFile);fprintf_s(mFile,"\" \"%s.o.oh\";\n",mName.c_str());}
	/*
	The second (saturation) component of Out Hsv.   The range is
	from 0 to 1 where 0 is a shade of grey, and 1 is a completely
	saturated color.
	*/
	void setOutHsvS(const FloatID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.o.os\";\n",mName.c_str());}
	/*
	The third (value) component of Out Hsv.   The range is from
	0 to 1, where 0 is black and 1 is the brightest possible
	color of the given saturation.
	*/
	void setOutHsvV(const FloatID& ov){fprintf_s(mFile,"connectAttr \"");ov.write(mFile);fprintf_s(mFile,"\" \"%s.o.ov\";\n",mName.c_str());}
	/*
	<b>In Rgb</b> is the color that will be converted
	into HSV values.
	*/
	Float3ID getInRgb(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*The first (red) component of In Rgb*/
	FloatID getInRgbR(){char buffer[4096];sprintf_s (buffer, "%s.i.ir",mName.c_str());return (const char*)buffer;}
	/*The second (green) component of In Rgb*/
	FloatID getInRgbG(){char buffer[4096];sprintf_s (buffer, "%s.i.ig",mName.c_str());return (const char*)buffer;}
	/*The third (blue) component of In Rgb*/
	FloatID getInRgbB(){char buffer[4096];sprintf_s (buffer, "%s.i.ib",mName.c_str());return (const char*)buffer;}
	/*<b>Out Hsv</b> is the output HSV values.*/
	Float3ID getOutHsv(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*
	The first (hue) component of Out Hsv.  This value ranges
	from 0 to 360, representing degrees of a circle.
	The primary colors are found here:
	<ul>
	0/360: Red<br/>60: Yellow<br/>120: Green<br/>
	180: Cyan<br/>240: Blue<br/>300: Magenta
	</ul>
	*/
	FloatID getOutHsvH(){char buffer[4096];sprintf_s (buffer, "%s.o.oh",mName.c_str());return (const char*)buffer;}
	/*
	The second (saturation) component of Out Hsv.   The range is
	from 0 to 1 where 0 is a shade of grey, and 1 is a completely
	saturated color.
	*/
	FloatID getOutHsvS(){char buffer[4096];sprintf_s (buffer, "%s.o.os",mName.c_str());return (const char*)buffer;}
	/*
	The third (value) component of Out Hsv.   The range is from
	0 to 1, where 0 is black and 1 is the brightest possible
	color of the given saturation.
	*/
	FloatID getOutHsvV(){char buffer[4096];sprintf_s (buffer, "%s.o.ov",mName.c_str());return (const char*)buffer;}
protected:
	RgbToHsv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RGBTOHSV_H__
