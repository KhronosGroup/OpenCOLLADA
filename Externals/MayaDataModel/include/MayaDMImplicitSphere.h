/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IMPLICITSPHERE_H__
#define __MayaDM_IMPLICITSPHERE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
/*
Represents an implicit sphere shape.
The sphere has no explicit geometry or points that can be accessed,
and cannot be rendered.
It is useful for other operations (such as the sculpt deformation) that need
a true perfect sphere.
*/
class ImplicitSphere : public GeometryShape
{
public:
public:
	ImplicitSphere(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "implicitSphere"){}
	virtual ~ImplicitSphere(){}
	/*Provides an implicit sphere object*/
	void setSphere(const SphereID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*The radius of the sphere generated, in linear units*/
	void setRadius(double rd){if(rd == 1) return; fprintf_s(mFile, "setAttr \".rd\" %f;\n", rd);}
	/*The radius of the sphere generated, in linear units*/
	void setRadius(const DoubleID& rd){fprintf_s(mFile,"connectAttr \"");rd.write(mFile);fprintf_s(mFile,"\" \"%s.rd\";\n",mName.c_str());}
	/*Provides an implicit sphere object*/
	SphereID getSphere(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*The radius of the sphere generated, in linear units*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.rd",mName.c_str());return (const char*)buffer;}
protected:
	ImplicitSphere(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IMPLICITSPHERE_H__
