/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPRISM_H__
#define __MayaDM_POLYPRISM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
This node creates a polygonal Prism according to the number of sides, length of side, length of prism, and
 number of subdivisions around along length, and on the caps.
 UVs on the Prism are created
 according to the enumerated texture attribute.<p/>
*/
class PolyPrism : public PolyPrimitive
{
public:
public:
	PolyPrism(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyPrism"){}
	virtual ~PolyPrism(){}
	/*Length of the prism.*/
	void setLength(double l){if(l == 2) return; fprintf_s(mFile, "setAttr \".l\" %f;\n", l);}
	/*Length of the prism.*/
	void setLength(const DoubleID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*Side length of the prism.*/
	void setSideLength(double w){if(w == 1) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*Side length of the prism.*/
	void setSideLength(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*Number of sides of prism.*/
	void setNumderOfSides(int ns){if(ns == 3) return; fprintf_s(mFile, "setAttr \".ns\" %i;\n", ns);}
	/*Number of sides of prism.*/
	void setNumderOfSides(const IntID& ns){fprintf_s(mFile,"connectAttr \"");ns.write(mFile);fprintf_s(mFile,"\" \"%s.ns\";\n",mName.c_str());}
	/*Subdivisions along the height.*/
	void setSubdivisionsHeight(int sh){if(sh == 1) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*Subdivisions along the height.*/
	void setSubdivisionsHeight(const IntID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*Subdivisions on the caps*/
	void setSubdivisionsCaps(int sc){if(sc == 0) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*Subdivisions on the caps*/
	void setSubdivisionsCaps(const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*
	What texture mechanism to be applied
	0=No textures, 1=Object, 2=Faces
	*/
	void setTexture(unsigned int tx){if(tx == 2) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*
	What texture mechanism to be applied
	0=No textures, 1=Object, 2=Faces
	*/
	void setTexture(const UnsignedintID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tx\";\n",mName.c_str());}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize</li>
	<li>3: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	void setCreateUVs(unsigned int cuv){if(cuv == 2) return; fprintf_s(mFile, "setAttr \".cuv\" %i;\n", cuv);}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize</li>
	<li>3: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	void setCreateUVs(const UnsignedintID& cuv){fprintf_s(mFile,"connectAttr \"");cuv.write(mFile);fprintf_s(mFile,"\" \"%s.cuv\";\n",mName.c_str());}
	/*Length of the prism.*/
	DoubleID getLength(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*Side length of the prism.*/
	DoubleID getSideLength(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*Number of sides of prism.*/
	IntID getNumderOfSides(){char buffer[4096];sprintf_s (buffer, "%s.ns",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the height.*/
	IntID getSubdivisionsHeight(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*Subdivisions on the caps*/
	IntID getSubdivisionsCaps(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	What texture mechanism to be applied
	0=No textures, 1=Object, 2=Faces
	*/
	UnsignedintID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize</li>
	<li>3: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	UnsignedintID getCreateUVs(){char buffer[4096];sprintf_s (buffer, "%s.cuv",mName.c_str());return (const char*)buffer;}
protected:
	PolyPrism(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYPRISM_H__
