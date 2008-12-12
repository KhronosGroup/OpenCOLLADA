/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCONE_H__
#define __MayaDM_POLYCONE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
This node creates a polygonal cone accordingly to the radius, height,
 and the number of subdivisions in X, Y, and Z. UVs are created on the cone if
 the texture attribute is true.<p/>
*/
class PolyCone : public PolyPrimitive
{
public:
public:
	PolyCone(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyCone"){}
	virtual ~PolyCone(){}
	/*Radius of the cone.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Radius of the cone.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Height of the cone.*/
	void setHeight(double h){if(h == 2) return; fprintf_s(mFile, "setAttr \".h\" %f;\n", h);}
	/*Height of the cone.*/
	void setHeight(const DoubleID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*Subdivisions around the axis.*/
	void setSubdivisionsAxis(int sa){if(sa == 20) return; fprintf_s(mFile, "setAttr \".sa\" %i;\n", sa);}
	/*Subdivisions around the axis.*/
	void setSubdivisionsAxis(const IntID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*Subdivisions along the height.*/
	void setSubdivisionsHeight(int sh){if(sh == 1) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*Subdivisions along the height.*/
	void setSubdivisionsHeight(const IntID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*Subdivisions on the bottom cap.*/
	void setSubdivisionsCap(int sc){if(sc == 0) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*Subdivisions on the bottom cap.*/
	void setSubdivisionsCap(const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*Apply texture or not.*/
	void setTexture(bool tx){if(tx == true) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*Apply texture or not.*/
	void setTexture(const BoolID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tx\";\n",mName.c_str());}
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
	/*To indicate whether we need a round cap*/
	void setRoundCap(bool rcp){if(rcp == false) return; fprintf_s(mFile, "setAttr \".rcp\" %i;\n", rcp);}
	/*To indicate whether we need a round cap*/
	void setRoundCap(const BoolID& rcp){fprintf_s(mFile,"connectAttr \"");rcp.write(mFile);fprintf_s(mFile,"\" \"%s.rcp\";\n",mName.c_str());}
	/*Radius of the cone.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Height of the cone.*/
	DoubleID getHeight(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*Subdivisions around the axis.*/
	IntID getSubdivisionsAxis(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the height.*/
	IntID getSubdivisionsHeight(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*Subdivisions on the bottom cap.*/
	IntID getSubdivisionsCap(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*Apply texture or not.*/
	BoolID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
	/*
	Create UVs or not.
	<ul><li>0: No UVs</li>
	<li>1: No Normalization</li>
	<li>2: Normalize</li>
	<li>3: Normalize and Preserve Aspect Ratio</li></ul>
	*/
	UnsignedintID getCreateUVs(){char buffer[4096];sprintf_s (buffer, "%s.cuv",mName.c_str());return (const char*)buffer;}
	/*To indicate whether we need a round cap*/
	BoolID getRoundCap(){char buffer[4096];sprintf_s (buffer, "%s.rcp",mName.c_str());return (const char*)buffer;}
protected:
	PolyCone(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCONE_H__
