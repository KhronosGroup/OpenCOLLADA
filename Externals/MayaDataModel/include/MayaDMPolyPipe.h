/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPIPE_H__
#define __MayaDM_POLYPIPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
This node creates a polygonal pipe according to the radius, length, thickness and
 number of subdivisions along height. UVs on the plane
 are created according to the texture attribute.<p/>
*/
class PolyPipe : public PolyPrimitive
{
public:
public:
	PolyPipe(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyPipe"){}
	virtual ~PolyPipe(){}
	/*Radius of the pipe.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Radius of the pipe.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Height of the pipe.*/
	void setHeight(double h){if(h == 2) return; fprintf_s(mFile, "setAttr \".h\" %f;\n", h);}
	/*Height of the pipe.*/
	void setHeight(const DoubleID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*Thickness of the pipe.*/
	void setThickness(double t){if(t == 0) return; fprintf_s(mFile, "setAttr \".t\" %f;\n", t);}
	/*Thickness of the pipe.*/
	void setThickness(const DoubleID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*Subdivisions around the axis.*/
	void setSubdivisionsAxis(int sa){if(sa == 20) return; fprintf_s(mFile, "setAttr \".sa\" %i;\n", sa);}
	/*Subdivisions around the axis.*/
	void setSubdivisionsAxis(const IntID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*Subdivisions along the height.*/
	void setSubdivisionsHeight(int sh){if(sh == 1) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*Subdivisions along the height.*/
	void setSubdivisionsHeight(const IntID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*Subdivisions along the thickness caps.*/
	void setSubdivisionsCaps(int sc){if(sc == 1) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*Subdivisions along the thickness caps.*/
	void setSubdivisionsCaps(const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
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
	/*To indicate whether we need a round cap*/
	void setRoundCap(bool rcp){if(rcp == false) return; fprintf_s(mFile, "setAttr \".rcp\" %i;\n", rcp);}
	/*To indicate whether we need a round cap*/
	void setRoundCap(const BoolID& rcp){fprintf_s(mFile,"connectAttr \"");rcp.write(mFile);fprintf_s(mFile,"\" \"%s.rcp\";\n",mName.c_str());}
	/*Radius of the pipe.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Height of the pipe.*/
	DoubleID getHeight(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*Thickness of the pipe.*/
	DoubleID getThickness(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*Subdivisions around the axis.*/
	IntID getSubdivisionsAxis(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the height.*/
	IntID getSubdivisionsHeight(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the thickness caps.*/
	IntID getSubdivisionsCaps(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	Apply texture or not. this is an old attribute.
	This is unsupported and would be removed in a future release.
	*/
	BoolID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
	/*Create UVs or not.*/
	BoolID getCreateUVs(){char buffer[4096];sprintf_s (buffer, "%s.cuv",mName.c_str());return (const char*)buffer;}
	/*To indicate whether we need a round cap*/
	BoolID getRoundCap(){char buffer[4096];sprintf_s (buffer, "%s.rcp",mName.c_str());return (const char*)buffer;}
protected:
	PolyPipe(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYPIPE_H__
