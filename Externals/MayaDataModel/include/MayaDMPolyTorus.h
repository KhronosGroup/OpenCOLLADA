/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTORUS_H__
#define __MayaDM_POLYTORUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
Creates a polygonal torus accordingly to the radius,
 the section radius, the twist angle, and
 the number of subdivisions in X and Y. UVs are created on the torus if
 the texture attribute is true.<p/>
*/
class PolyTorus : public PolyPrimitive
{
public:
public:
	PolyTorus(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyTorus"){}
	virtual ~PolyTorus(){}
	/*Radius of the torus.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Radius of the torus.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Section of the torus.*/
	void setSectionRadius(double sr){if(sr == 0) return; fprintf_s(mFile, "setAttr \".sr\" %f;\n", sr);}
	/*Section of the torus.*/
	void setSectionRadius(const DoubleID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sr\";\n",mName.c_str());}
	/*Twist angle of the torus.*/
	void setTwist(double tw){if(tw == 0) return; fprintf_s(mFile, "setAttr \".tw\" %f;\n", tw);}
	/*Twist angle of the torus.*/
	void setTwist(const DoubleID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tw\";\n",mName.c_str());}
	/*Subdivisions about the vertical axis.*/
	void setSubdivisionsAxis(int sa){if(sa == 20) return; fprintf_s(mFile, "setAttr \".sa\" %i;\n", sa);}
	/*Subdivisions about the vertical axis.*/
	void setSubdivisionsAxis(const IntID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*Subdivisions along the height.*/
	void setSubdivisionsHeight(int sh){if(sh == 20) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*Subdivisions along the height.*/
	void setSubdivisionsHeight(const IntID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*
	Apply texture or not. this is an old attribute.
	This is unsupported and would be removed in a future release.
	*/
	void setTexture(bool tx){if(tx == true) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*
	Apply texture or not. this is an old attribute.
	This is unsupported and would be removed in a future release.
	*/
	void setTexture(const BoolID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tx\";\n",mName.c_str());}
	/*Create UVs or not.*/
	void setCreateUVs(bool cuv){if(cuv == true) return; fprintf_s(mFile, "setAttr \".cuv\" %i;\n", cuv);}
	/*Create UVs or not.*/
	void setCreateUVs(const BoolID& cuv){fprintf_s(mFile,"connectAttr \"");cuv.write(mFile);fprintf_s(mFile,"\" \"%s.cuv\";\n",mName.c_str());}
	/*Genereate reversed UVs. Value is set to true on pre-3.0 nodes, to ensure backward file compatibility.*/
	void setReverseTexture(bool rtx){if(rtx == false) return; fprintf_s(mFile, "setAttr \".rtx\" %i;\n", rtx);}
	/*Radius of the torus.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Section of the torus.*/
	DoubleID getSectionRadius(){char buffer[4096];sprintf_s (buffer, "%s.sr",mName.c_str());return (const char*)buffer;}
	/*Twist angle of the torus.*/
	DoubleID getTwist(){char buffer[4096];sprintf_s (buffer, "%s.tw",mName.c_str());return (const char*)buffer;}
	/*Subdivisions about the vertical axis.*/
	IntID getSubdivisionsAxis(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the height.*/
	IntID getSubdivisionsHeight(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*
	Apply texture or not. this is an old attribute.
	This is unsupported and would be removed in a future release.
	*/
	BoolID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
	/*Create UVs or not.*/
	BoolID getCreateUVs(){char buffer[4096];sprintf_s (buffer, "%s.cuv",mName.c_str());return (const char*)buffer;}
protected:
	PolyTorus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYTORUS_H__
