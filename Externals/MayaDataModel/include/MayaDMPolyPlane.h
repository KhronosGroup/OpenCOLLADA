/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPLANE_H__
#define __MayaDM_POLYPLANE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
This node creates a polygonal plane according to the width, height, and
 number of subdivisions in X and Y. UVs on the plane
 are created according to the texture attribute.<p/>
*/
class PolyPlane : public PolyPrimitive
{
public:
public:
	PolyPlane(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyPlane"){}
	virtual ~PolyPlane(){}
	/*Width of the plane.*/
	void setWidth(double w){if(w == 1) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*Width of the plane.*/
	void setWidth(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*Height of the plane.*/
	void setHeight(double h){if(h == 1) return; fprintf_s(mFile, "setAttr \".h\" %f;\n", h);}
	/*Height of the plane.*/
	void setHeight(const DoubleID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*Subdivisions along the width of the plane.*/
	void setSubdivisionsWidth(int sw){if(sw == 10) return; fprintf_s(mFile, "setAttr \".sw\" %i;\n", sw);}
	/*Subdivisions along the width of the plane.*/
	void setSubdivisionsWidth(const IntID& sw){fprintf_s(mFile,"connectAttr \"");sw.write(mFile);fprintf_s(mFile,"\" \"%s.sw\";\n",mName.c_str());}
	/*Subdivisions along the height of the plane.*/
	void setSubdivisionsHeight(int sh){if(sh == 10) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*Subdivisions along the height of the plane.*/
	void setSubdivisionsHeight(const IntID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*
	What texture mechanism to be applied.
	0=No textures; 1=stretch to fit;
	2=preserve aspect ratio
	*/
	void setTexture(unsigned int tx){if(tx == 1) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*
	What texture mechanism to be applied.
	0=No textures; 1=stretch to fit;
	2=preserve aspect ratio
	*/
	void setTexture(const UnsignedintID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tx\";\n",mName.c_str());}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	void setCreateUVs(unsigned int cuv){if(cuv == 1) return; fprintf_s(mFile, "setAttr \".cuv\" %i;\n", cuv);}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	void setCreateUVs(const UnsignedintID& cuv){fprintf_s(mFile,"connectAttr \"");cuv.write(mFile);fprintf_s(mFile,"\" \"%s.cuv\";\n",mName.c_str());}
	/*Width of the plane.*/
	DoubleID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*Height of the plane.*/
	DoubleID getHeight(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the width of the plane.*/
	IntID getSubdivisionsWidth(){char buffer[4096];sprintf_s (buffer, "%s.sw",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the height of the plane.*/
	IntID getSubdivisionsHeight(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*
	What texture mechanism to be applied.
	0=No textures; 1=stretch to fit;
	2=preserve aspect ratio
	*/
	UnsignedintID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	UnsignedintID getCreateUVs(){char buffer[4096];sprintf_s (buffer, "%s.cuv",mName.c_str());return (const char*)buffer;}
protected:
	PolyPlane(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYPLANE_H__
