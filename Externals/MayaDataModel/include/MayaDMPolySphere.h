/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSPHERE_H__
#define __MayaDM_POLYSPHERE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyPrimitive.h"
namespace MayaDM
{
/*
This node creates a polygonal sphere according to the radius, and
 number of subdivisions in X and Y. UVs on the sphere are created if
 the texture attribute is true.<p/>
*/
class PolySphere : public PolyPrimitive
{
public:
public:
	PolySphere(FILE* file,const std::string& name,const std::string& parent=""):PolyPrimitive(file, name, parent, "polySphere"){}
	virtual ~PolySphere(){}
	/*Radius of the sphere.*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*Radius of the sphere.*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*Subdivisions around the axis.*/
	void setSubdivisionsAxis(int sa){if(sa == 20) return; fprintf_s(mFile, "setAttr \".sa\" %i;\n", sa);}
	/*Subdivisions around the axis.*/
	void setSubdivisionsAxis(const IntID& sa){fprintf_s(mFile,"connectAttr \"");sa.write(mFile);fprintf_s(mFile,"\" \"%s.sa\";\n",mName.c_str());}
	/*Subdivisions along the height of the sphere.*/
	void setSubdivisionsHeight(int sh){if(sh == 20) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*Subdivisions along the height of the sphere.*/
	void setSubdivisionsHeight(const IntID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Piched; 2=SawTooth
	This is an old attribute.
	This is unsupported and would be removed in a future release.
	*/
	void setTexture(unsigned int tx){if(tx == 1) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Piched; 2=SawTooth
	This is an old attribute.
	This is unsupported and would be removed in a future release.
	*/
	void setTexture(const UnsignedintID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tx\";\n",mName.c_str());}
	/*
	Create UVs or not.
	0=No UVs; 1=Piched; 2=SawTooth
	*/
	void setCreateUVs(unsigned int cuv){if(cuv == 2) return; fprintf_s(mFile, "setAttr \".cuv\" %i;\n", cuv);}
	/*
	Create UVs or not.
	0=No UVs; 1=Piched; 2=SawTooth
	*/
	void setCreateUVs(const UnsignedintID& cuv){fprintf_s(mFile,"connectAttr \"");cuv.write(mFile);fprintf_s(mFile,"\" \"%s.cuv\";\n",mName.c_str());}
	/*Radius of the sphere.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*Subdivisions around the axis.*/
	IntID getSubdivisionsAxis(){char buffer[4096];sprintf_s (buffer, "%s.sa",mName.c_str());return (const char*)buffer;}
	/*Subdivisions along the height of the sphere.*/
	IntID getSubdivisionsHeight(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*
	What texture mechanism to be applied
	0=No textures; 1=Piched; 2=SawTooth
	This is an old attribute.
	This is unsupported and would be removed in a future release.
	*/
	UnsignedintID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
	/*
	Create UVs or not.
	0=No UVs; 1=Piched; 2=SawTooth
	*/
	UnsignedintID getCreateUVs(){char buffer[4096];sprintf_s (buffer, "%s.cuv",mName.c_str());return (const char*)buffer;}
protected:
	PolySphere(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSPHERE_H__
