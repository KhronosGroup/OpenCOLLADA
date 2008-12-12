/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCUBE_H__
#define __MayaDM_POLYCUBE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
This node creates a polygonal cube according to the width, height, depth,
 and number of subdivisions in X, Y, and Z. UVs on the cube are created if
 the texture attribute is set to true.<p/>
*/
class PolyCube : public PolyPrimitive
{
public:
public:
	PolyCube(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyCube"){}
	virtual ~PolyCube(){}
	/*Width of the cube.*/
	void setWidth(double w){if(w == 1) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*Width of the cube.*/
	void setWidth(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*Height of the cube.*/
	void setHeight(double h){if(h == 1) return; fprintf_s(mFile, "setAttr \".h\" %f;\n", h);}
	/*Height of the cube.*/
	void setHeight(const DoubleID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*Depth of the cube.*/
	void setDepth(double d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*Depth of the cube.*/
	void setDepth(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Subdivisions along the width of the cube.*/
	void setSubdivisionsWidth(int sw){if(sw == 1) return; fprintf_s(mFile, "setAttr \".sw\" %i;\n", sw);}
	/*Subdivisions along the width of the cube.*/
	void setSubdivisionsWidth(const IntID& sw){fprintf_s(mFile,"connectAttr \"");sw.write(mFile);fprintf_s(mFile,"\" \"%s.sw\";\n",mName.c_str());}
	/*Subdivisions along the height of the cube.*/
	void setSubdivisionsHeight(int sh){if(sh == 1) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*Subdivisions along the height of the cube.*/
	void setSubdivisionsHeight(const IntID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*Subdivisions along the depth of the cube.*/
	void setSubdivisionsDepth(int sd){if(sd == 1) return; fprintf_s(mFile, "setAttr \".sd\" %i;\n", sd);}
	/*Subdivisions along the depth of the cube.*/
	void setSubdivisionsDepth(const IntID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd\";\n",mName.c_str());}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Object; 2=Faces
	*/
	void setTexture(unsigned int tx){if(tx == 1) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Object; 2=Faces
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
	/*Width of the cube.*/
	DoubleID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*Height of the cube.*/
	DoubleID getHeight(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*Depth of the cube.*/
	DoubleID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the width of the cube.*/
	IntID getSubdivisionsWidth(){char buffer[4096];sprintf_s (buffer, "%s.sw",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the height of the cube.*/
	IntID getSubdivisionsHeight(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the depth of the cube.*/
	IntID getSubdivisionsDepth(){char buffer[4096];sprintf_s (buffer, "%s.sd",mName.c_str());return (const char*)buffer;}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Object; 2=Faces
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
	PolyCube(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCUBE_H__
