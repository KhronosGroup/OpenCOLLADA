/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONTRAST_H__
#define __MayaDM_CONTRAST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Contrast</b> is a utility node you can use to increase or
 decrease the contrast in a texture.
 <p/>
 When you increase Contrast, you are making the light colors lighter
 and the dark colors darker.  When you decrease contrast, you are
 bringing all the colors closer to the middle range.  The Bias
 attribute is used to control where the "center" of this range is.
 <p/>
 The Contrast node lets you control the contrast of each of the
 R, G, and B channels individually.
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class Contrast : public DependNode
{
public:
public:
	Contrast(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "contrast"){}
	virtual ~Contrast(){}
	/*
	<b>Value</b> is the input color or texture that will
	have its contrast adjusted by this node.
	*/
	void setValue(const float3& v){if(v == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".v\" -type \"float3\" ");v.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Value</b> is the input color or texture that will
	have its contrast adjusted by this node.
	*/
	void setValue(const Float3ID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*First component of Value*/
	void setValueX(float vx){if(vx == 0.0) return; fprintf_s(mFile, "setAttr \".v.vx\" %f;\n", vx);}
	/*First component of Value*/
	void setValueX(const FloatID& vx){fprintf_s(mFile,"connectAttr \"");vx.write(mFile);fprintf_s(mFile,"\" \"%s.v.vx\";\n",mName.c_str());}
	/*Second component of Value*/
	void setValueY(float vy){if(vy == 0.0) return; fprintf_s(mFile, "setAttr \".v.vy\" %f;\n", vy);}
	/*Second component of Value*/
	void setValueY(const FloatID& vy){fprintf_s(mFile,"connectAttr \"");vy.write(mFile);fprintf_s(mFile,"\" \"%s.v.vy\";\n",mName.c_str());}
	/*Third component of Value*/
	void setValueZ(float vz){if(vz == 0.0) return; fprintf_s(mFile, "setAttr \".v.vz\" %f;\n", vz);}
	/*Third component of Value*/
	void setValueZ(const FloatID& vz){fprintf_s(mFile,"connectAttr \"");vz.write(mFile);fprintf_s(mFile,"\" \"%s.v.vz\";\n",mName.c_str());}
	/*
	<b>Contrast</b> controls the amount of contrast adjustment
	done by this node.  You can adjust the contrast of the
	R, G, and B components individually.
	<p/>
	Increase Contrast to make the light colors lighter, and the
	dark colors darker.  Decrease Contrast to make everything
	more grey.
	*/
	void setContrast(const float3& c){if(c == float3(2.0, 2.0, 2.0)) return; fprintf_s(mFile, "setAttr \".c\" -type \"float3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Contrast</b> controls the amount of contrast adjustment
	done by this node.  You can adjust the contrast of the
	R, G, and B components individually.
	<p/>
	Increase Contrast to make the light colors lighter, and the
	dark colors darker.  Decrease Contrast to make everything
	more grey.
	*/
	void setContrast(const Float3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*The first component of Contrast*/
	void setContrastX(float cx){if(cx == 0.0) return; fprintf_s(mFile, "setAttr \".c.cx\" %f;\n", cx);}
	/*The first component of Contrast*/
	void setContrastX(const FloatID& cx){fprintf_s(mFile,"connectAttr \"");cx.write(mFile);fprintf_s(mFile,"\" \"%s.c.cx\";\n",mName.c_str());}
	/*The second component of Contrast*/
	void setContrastY(float cy){if(cy == 0.0) return; fprintf_s(mFile, "setAttr \".c.cy\" %f;\n", cy);}
	/*The second component of Contrast*/
	void setContrastY(const FloatID& cy){fprintf_s(mFile,"connectAttr \"");cy.write(mFile);fprintf_s(mFile,"\" \"%s.c.cy\";\n",mName.c_str());}
	/*The third component of Contrast*/
	void setContrastZ(float cz){if(cz == 0.0) return; fprintf_s(mFile, "setAttr \".c.cz\" %f;\n", cz);}
	/*The third component of Contrast*/
	void setContrastZ(const FloatID& cz){fprintf_s(mFile,"connectAttr \"");cz.write(mFile);fprintf_s(mFile,"\" \"%s.c.cz\";\n",mName.c_str());}
	/*
	<b>Bias</b> controls the "middle point" of the contrast
	adjustment.  Increase Bias to move the middle point
	upwards (more of the texture will become dark as contrast
	increaes).  Decrease Bias to move the middle point down
	(more of the texture will become light as contrast
	increases).
	*/
	void setBias(const float3& b){if(b == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".b\" -type \"float3\" ");b.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Bias</b> controls the "middle point" of the contrast
	adjustment.  Increase Bias to move the middle point
	upwards (more of the texture will become dark as contrast
	increaes).  Decrease Bias to move the middle point down
	(more of the texture will become light as contrast
	increases).
	*/
	void setBias(const Float3ID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*The first component of Bias*/
	void setBiasX(float bx){if(bx == 0.0) return; fprintf_s(mFile, "setAttr \".b.bx\" %f;\n", bx);}
	/*The first component of Bias*/
	void setBiasX(const FloatID& bx){fprintf_s(mFile,"connectAttr \"");bx.write(mFile);fprintf_s(mFile,"\" \"%s.b.bx\";\n",mName.c_str());}
	/*The second component of Bias*/
	void setBiasY(float by){if(by == 0.0) return; fprintf_s(mFile, "setAttr \".b.by\" %f;\n", by);}
	/*The second component of Bias*/
	void setBiasY(const FloatID& by){fprintf_s(mFile,"connectAttr \"");by.write(mFile);fprintf_s(mFile,"\" \"%s.b.by\";\n",mName.c_str());}
	/*The third component of Bias*/
	void setBiasZ(float bz){if(bz == 0.0) return; fprintf_s(mFile, "setAttr \".b.bz\" %f;\n", bz);}
	/*The third component of Bias*/
	void setBiasZ(const FloatID& bz){fprintf_s(mFile,"connectAttr \"");bz.write(mFile);fprintf_s(mFile,"\" \"%s.b.bz\";\n",mName.c_str());}
	/*
	<b>Out Value</b> is the new color or texture, calculated
	by applying the contrast adjustment to Value.
	*/
	void setOutValue(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The first component of Out Value*/
	void setOutValueX(const FloatID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*The second component of Out Value*/
	void setOutValueY(const FloatID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*The third component of Out Value*/
	void setOutValueZ(const FloatID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*
	<b>Value</b> is the input color or texture that will
	have its contrast adjusted by this node.
	*/
	Float3ID getValue(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*First component of Value*/
	FloatID getValueX(){char buffer[4096];sprintf_s (buffer, "%s.v.vx",mName.c_str());return (const char*)buffer;}
	/*Second component of Value*/
	FloatID getValueY(){char buffer[4096];sprintf_s (buffer, "%s.v.vy",mName.c_str());return (const char*)buffer;}
	/*Third component of Value*/
	FloatID getValueZ(){char buffer[4096];sprintf_s (buffer, "%s.v.vz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Contrast</b> controls the amount of contrast adjustment
	done by this node.  You can adjust the contrast of the
	R, G, and B components individually.
	<p/>
	Increase Contrast to make the light colors lighter, and the
	dark colors darker.  Decrease Contrast to make everything
	more grey.
	*/
	Float3ID getContrast(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*The first component of Contrast*/
	FloatID getContrastX(){char buffer[4096];sprintf_s (buffer, "%s.c.cx",mName.c_str());return (const char*)buffer;}
	/*The second component of Contrast*/
	FloatID getContrastY(){char buffer[4096];sprintf_s (buffer, "%s.c.cy",mName.c_str());return (const char*)buffer;}
	/*The third component of Contrast*/
	FloatID getContrastZ(){char buffer[4096];sprintf_s (buffer, "%s.c.cz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Bias</b> controls the "middle point" of the contrast
	adjustment.  Increase Bias to move the middle point
	upwards (more of the texture will become dark as contrast
	increaes).  Decrease Bias to move the middle point down
	(more of the texture will become light as contrast
	increases).
	*/
	Float3ID getBias(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*The first component of Bias*/
	FloatID getBiasX(){char buffer[4096];sprintf_s (buffer, "%s.b.bx",mName.c_str());return (const char*)buffer;}
	/*The second component of Bias*/
	FloatID getBiasY(){char buffer[4096];sprintf_s (buffer, "%s.b.by",mName.c_str());return (const char*)buffer;}
	/*The third component of Bias*/
	FloatID getBiasZ(){char buffer[4096];sprintf_s (buffer, "%s.b.bz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Value</b> is the new color or texture, calculated
	by applying the contrast adjustment to Value.
	*/
	Float3ID getOutValue(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The first component of Out Value*/
	FloatID getOutValueX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*The second component of Out Value*/
	FloatID getOutValueY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*The third component of Out Value*/
	FloatID getOutValueZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
protected:
	Contrast(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CONTRAST_H__
