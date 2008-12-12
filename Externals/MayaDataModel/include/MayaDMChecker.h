/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHECKER_H__
#define __MayaDM_CHECKER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Checker</b> texture applies a checkerboard pattern, using
  the two input colors.
  <p/>
  Aside from the attributes listed here, Checker inherits many other
  attributes from its parent node, <a href="texture2d.html">Texture2d</a>.
  <p/>
  In the table below, important attributes have their names listed
  in <b>bold</b> in the description column.
*/
class Checker : public Texture2d
{
public:
public:
	Checker(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "checker"){}
	virtual ~Checker(){}
	/*
	<b>Color 1</b> is one of the two colors used to make up the
	the checkerboard pattern.
	*/
	void setColor1(const float3& c1){if(c1 == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c1\" -type \"float3\" ");c1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color 1</b> is one of the two colors used to make up the
	the checkerboard pattern.
	*/
	void setColor1(const Float3ID& c1){fprintf_s(mFile,"connectAttr \"");c1.write(mFile);fprintf_s(mFile,"\" \"%s.c1\";\n",mName.c_str());}
	/*The red component of color 1*/
	void setColor1R(float c1r){if(c1r == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1r\" %f;\n", c1r);}
	/*The red component of color 1*/
	void setColor1R(const FloatID& c1r){fprintf_s(mFile,"connectAttr \"");c1r.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1r\";\n",mName.c_str());}
	/*The green component of color 1*/
	void setColor1G(float c1g){if(c1g == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1g\" %f;\n", c1g);}
	/*The green component of color 1*/
	void setColor1G(const FloatID& c1g){fprintf_s(mFile,"connectAttr \"");c1g.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1g\";\n",mName.c_str());}
	/*The blue component of color 1*/
	void setColor1B(float c1b){if(c1b == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1b\" %f;\n", c1b);}
	/*The blue component of color 1*/
	void setColor1B(const FloatID& c1b){fprintf_s(mFile,"connectAttr \"");c1b.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1b\";\n",mName.c_str());}
	/*
	<b>Color 2</b> is one of the two colors used to make up the
	the checkerboard pattern.
	*/
	void setColor2(const float3& c2){if(c2 == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c2\" -type \"float3\" ");c2.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Color 2</b> is one of the two colors used to make up the
	the checkerboard pattern.
	*/
	void setColor2(const Float3ID& c2){fprintf_s(mFile,"connectAttr \"");c2.write(mFile);fprintf_s(mFile,"\" \"%s.c2\";\n",mName.c_str());}
	/*The red component of color 2*/
	void setColor2R(float c2r){if(c2r == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2r\" %f;\n", c2r);}
	/*The red component of color 2*/
	void setColor2R(const FloatID& c2r){fprintf_s(mFile,"connectAttr \"");c2r.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2r\";\n",mName.c_str());}
	/*The green component of color 2*/
	void setColor2G(float c2g){if(c2g == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2g\" %f;\n", c2g);}
	/*The green component of color 2*/
	void setColor2G(const FloatID& c2g){fprintf_s(mFile,"connectAttr \"");c2g.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2g\";\n",mName.c_str());}
	/*The blue component of color 2*/
	void setColor2B(float c2b){if(c2b == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2b\" %f;\n", c2b);}
	/*The blue component of color 2*/
	void setColor2B(const FloatID& c2b){fprintf_s(mFile,"connectAttr \"");c2b.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2b\";\n",mName.c_str());}
	/*
	<b>Contrast</b> controls how much the two input colors
	affect each other.  When set to 1.0 (the default), the colors
	on the checkerboard are completely independent of each other.
	As Contrast is reduced, the colors blend more together.  When
	Constrast is 0.0, you will not see a checker pattern, but rather just
	a single color that is the average of the two input colors.
	*/
	void setContrast(float ct){if(ct == 1.0) return; fprintf_s(mFile, "setAttr \".ct\" %f;\n", ct);}
	/*
	<b>Contrast</b> controls how much the two input colors
	affect each other.  When set to 1.0 (the default), the colors
	on the checkerboard are completely independent of each other.
	As Contrast is reduced, the colors blend more together.  When
	Constrast is 0.0, you will not see a checker pattern, but rather just
	a single color that is the average of the two input colors.
	*/
	void setContrast(const FloatID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*
	<b>Color 1</b> is one of the two colors used to make up the
	the checkerboard pattern.
	*/
	Float3ID getColor1(){char buffer[4096];sprintf_s (buffer, "%s.c1",mName.c_str());return (const char*)buffer;}
	/*The red component of color 1*/
	FloatID getColor1R(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1r",mName.c_str());return (const char*)buffer;}
	/*The green component of color 1*/
	FloatID getColor1G(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1g",mName.c_str());return (const char*)buffer;}
	/*The blue component of color 1*/
	FloatID getColor1B(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Color 2</b> is one of the two colors used to make up the
	the checkerboard pattern.
	*/
	Float3ID getColor2(){char buffer[4096];sprintf_s (buffer, "%s.c2",mName.c_str());return (const char*)buffer;}
	/*The red component of color 2*/
	FloatID getColor2R(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2r",mName.c_str());return (const char*)buffer;}
	/*The green component of color 2*/
	FloatID getColor2G(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2g",mName.c_str());return (const char*)buffer;}
	/*The blue component of color 2*/
	FloatID getColor2B(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2b",mName.c_str());return (const char*)buffer;}
	/*
	<b>Contrast</b> controls how much the two input colors
	affect each other.  When set to 1.0 (the default), the colors
	on the checkerboard are completely independent of each other.
	As Contrast is reduced, the colors blend more together.  When
	Constrast is 0.0, you will not see a checker pattern, but rather just
	a single color that is the average of the two input colors.
	*/
	FloatID getContrast(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
protected:
	Checker(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CHECKER_H__
