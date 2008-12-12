/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPRIMITIVEMISC_H__
#define __MayaDM_POLYPRIMITIVEMISC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
<p><pre> This node creates a general polygon  based on the radius and side length.

</pre></p>
*/
class PolyPrimitiveMisc : public PolyPrimitive
{
public:
public:
	PolyPrimitiveMisc(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyPrimitiveMisc"){}
	virtual ~PolyPrimitiveMisc(){}
	/*Radius of the Polygon.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Radius of the Polygon.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Side length of Polygon.*/
	void setSideLength(double l){if(l == 0) return; fprintf_s(mFile, "setAttr \".l\" %f;\n", l);}
	/*Side length of Polygon.*/
	void setSideLength(const DoubleID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	What Polygon to create
	0=Soccerball
	*/
	void setPolyType(unsigned int pt){if(pt == 0) return; fprintf_s(mFile, "setAttr \".pt\" %i;\n", pt);}
	/*
	What Polygon to create
	0=Soccerball
	*/
	void setPolyType(const UnsignedintID& pt){fprintf_s(mFile,"connectAttr \"");pt.write(mFile);fprintf_s(mFile,"\" \"%s.pt\";\n",mName.c_str());}
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
	<li>2: Normalize Each Face Separately</li>
	<li>3: Normalize Collectively</li>
	<li>4: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	void setCreateUVs(unsigned int cuv){if(cuv == 3) return; fprintf_s(mFile, "setAttr \".cuv\" %i;\n", cuv);}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize Each Face Separately</li>
	<li>3: Normalize Collectively</li>
	<li>4: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	void setCreateUVs(const UnsignedintID& cuv){fprintf_s(mFile,"connectAttr \"");cuv.write(mFile);fprintf_s(mFile,"\" \"%s.cuv\";\n",mName.c_str());}
	/*Radius of the Polygon.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Side length of Polygon.*/
	DoubleID getSideLength(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	What Polygon to create
	0=Soccerball
	*/
	UnsignedintID getPolyType(){char buffer[4096];sprintf_s (buffer, "%s.pt",mName.c_str());return (const char*)buffer;}
	/*
	What texture mechanism to be applied
	0=No textures, 1=Object, 2=Faces
	*/
	UnsignedintID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize Each Face Separately</li>
	<li>3: Normalize Collectively</li>
	<li>4: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	UnsignedintID getCreateUVs(){char buffer[4096];sprintf_s (buffer, "%s.cuv",mName.c_str());return (const char*)buffer;}
protected:
	PolyPrimitiveMisc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYPRIMITIVEMISC_H__
