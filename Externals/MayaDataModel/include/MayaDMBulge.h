/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BULGE_H__
#define __MayaDM_BULGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture2d.h"
namespace MayaDM
{
/*
The <b>Bulge</b> texture is intended to be used as a bump map
 or a displacement map.  It produces an area that is flat along
 the outer edges, and bulging in the middle.  If this texture
 is repeated along a surface, it produces an effect similar to
 a skyscraper pumped full of air; the windows are bulging, but
 held in by the flat frames around their edges.
 <p/>
 Aside from the attributes listed here, Bulge inherits many other
 attributes from its parent class, <a href="texture2d.html">Texture2d</a>.
 <p/>
 Some uses for Bulge:
 <ul>
   <li>Map a bulge texture to both the Transparency
 attribute of a shader, and through a bump node to the same shader,
 to produce a 3d window effect.</li>
   <li>Map a bulge texture to the Color attribute of a shader.  There
 will be no apparent bulge created, but it will produce a tiled
 color effect.</li>
 </ul>
*/
class Bulge : public Texture2d
{
public:
public:
	Bulge(FILE* file,const std::string& name,const std::string& parent=""):Texture2d(file, name, parent, "bulge"){}
	virtual ~Bulge(){}
	/*
	<b>U Width</b> and V Width delimit the area of constant
	value in the texture.  If you think of the texture as
	as producing a window frame with a bulging window, then
	U Width and V Width control the width of the window
	frame in each direction.
	*/
	void setUWidth(float uw){if(uw == 0.1) return; fprintf_s(mFile, "setAttr \".uw\" %f;\n", uw);}
	/*
	<b>U Width</b> and V Width delimit the area of constant
	value in the texture.  If you think of the texture as
	as producing a window frame with a bulging window, then
	U Width and V Width control the width of the window
	frame in each direction.
	*/
	void setUWidth(const FloatID& uw){fprintf_s(mFile,"connectAttr \"");uw.write(mFile);fprintf_s(mFile,"\" \"%s.uw\";\n",mName.c_str());}
	/*<b>V Width</b>.  See the description for U Width.*/
	void setVWidth(float vw){if(vw == 0.1) return; fprintf_s(mFile, "setAttr \".vw\" %f;\n", vw);}
	/*<b>V Width</b>.  See the description for U Width.*/
	void setVWidth(const FloatID& vw){fprintf_s(mFile,"connectAttr \"");vw.write(mFile);fprintf_s(mFile,"\" \"%s.vw\";\n",mName.c_str());}
	/*
	<b>U Width</b> and V Width delimit the area of constant
	value in the texture.  If you think of the texture as
	as producing a window frame with a bulging window, then
	U Width and V Width control the width of the window
	frame in each direction.
	*/
	FloatID getUWidth(){char buffer[4096];sprintf_s (buffer, "%s.uw",mName.c_str());return (const char*)buffer;}
	/*<b>V Width</b>.  See the description for U Width.*/
	FloatID getVWidth(){char buffer[4096];sprintf_s (buffer, "%s.vw",mName.c_str());return (const char*)buffer;}
protected:
	Bulge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture2d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BULGE_H__
