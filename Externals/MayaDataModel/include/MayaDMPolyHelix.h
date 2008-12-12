/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYHELIX_H__
#define __MayaDM_POLYHELIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
<p><pre> This node creates a polygonal helix according to the number of coils, height of helix,
 width of helix, radius of tube  and direction of coil
 UVs on the plane are created according to the texture attribute.
</pre></p>
*/
class PolyHelix : public PolyPrimitive
{
public:
public:
	PolyHelix(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polyHelix"){}
	virtual ~PolyHelix(){}
	/*Number of coils.*/
	void setCoils(double c){if(c == 3) return; fprintf_s(mFile, "setAttr \".c\" %f;\n", c);}
	/*Number of coils.*/
	void setCoils(const DoubleID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*Height of the helix.*/
	void setHeight(double h){if(h == 2) return; fprintf_s(mFile, "setAttr \".h\" %f;\n", h);}
	/*Height of the helix.*/
	void setHeight(const DoubleID& h){fprintf_s(mFile,"connectAttr \"");h.write(mFile);fprintf_s(mFile,"\" \"%s.h\";\n",mName.c_str());}
	/*Width of the helix.*/
	void setWidth(double w){if(w == 2) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*Width of the helix.*/
	void setWidth(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*Radius of tube.*/
	void setRadius(double r){if(r == 0) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Radius of tube.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*
	What should be the direction of the coil.
	0=Clockwise; 1=Counterclockwise
	*/
	void setDirection(unsigned int d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	What should be the direction of the coil.
	0=Clockwise; 1=Counterclockwise
	*/
	void setDirection(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Subdivisions around the axis.*/
	void setSubdivisionsAxis(int sa){if(sa == 8) return; fprintf_s(mFile, "setAttr \".sa\" %i;\n", sa);}
	/*Subdivisions around the axis.*/
	void setSubdivisionsAxis(const IntID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*Subdivisions along the coil.*/
	void setSubdivisionsCoil(int sco){if(sco == 50) return; fprintf_s(mFile, "setAttr \".sco\" %i;\n", sco);}
	/*Subdivisions along the coil.*/
	void setSubdivisionsCoil(const IntID& sco){fprintf_s(mFile,"connectAttr \"");sco.write(mFile);fprintf_s(mFile,"\" \"%s.sco\";\n",mName.c_str());}
	/*Subdivisions along the thickness caps.*/
	void setSubdivisionsCaps(int sc){if(sc == 0) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*Subdivisions along the thickness caps.*/
	void setSubdivisionsCaps(const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Object; 2=Faces
	*/
	void setTexture(unsigned int tx){if(tx == 2) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Object; 2=Faces
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
	/*To indicate whether we need a round cap*/
	void setRoundCap(bool rcp){if(rcp == false) return; fprintf_s(mFile, "setAttr \".rcp\" %i;\n", rcp);}
	/*To indicate whether we need a round cap*/
	void setRoundCap(const BoolID& rcp){fprintf_s(mFile,"connectAttr \"");rcp.write(mFile);fprintf_s(mFile,"\" \"%s.rcp\";\n",mName.c_str());}
	/*
	Create the helix with base on the origin as in Maya V8.0 and below
	Otherwise create helix centred at origin
	*/
	void setUseOldInitBehaviour(bool oib){if(oib == false) return; fprintf_s(mFile, "setAttr \".oib\" %i;\n", oib);}
	/*
	Create the helix with base on the origin as in Maya V8.0 and below
	Otherwise create helix centred at origin
	*/
	void setUseOldInitBehaviour(const BoolID& oib){fprintf_s(mFile,"connectAttr \"");oib.write(mFile);fprintf_s(mFile,"\" \"%s.oib\";\n",mName.c_str());}
	/*Number of coils.*/
	DoubleID getCoils(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*Height of the helix.*/
	DoubleID getHeight(){char buffer[4096];sprintf_s (buffer, "%s.h",mName.c_str());return (const char*)buffer;}
	/*Width of the helix.*/
	DoubleID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*Radius of tube.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*
	What should be the direction of the coil.
	0=Clockwise; 1=Counterclockwise
	*/
	UnsignedintID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Subdivisions around the axis.*/
	IntID getSubdivisionsAxis(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the coil.*/
	IntID getSubdivisionsCoil(){char buffer[4096];sprintf_s (buffer, "%s.sco",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the thickness caps.*/
	IntID getSubdivisionsCaps(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Object; 2=Faces
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
	/*To indicate whether we need a round cap*/
	BoolID getRoundCap(){char buffer[4096];sprintf_s (buffer, "%s.rcp",mName.c_str());return (const char*)buffer;}
	/*
	Create the helix with base on the origin as in Maya V8.0 and below
	Otherwise create helix centred at origin
	*/
	BoolID getUseOldInitBehaviour(){char buffer[4096];sprintf_s (buffer, "%s.oib",mName.c_str());return (const char*)buffer;}
protected:
	PolyHelix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYHELIX_H__
