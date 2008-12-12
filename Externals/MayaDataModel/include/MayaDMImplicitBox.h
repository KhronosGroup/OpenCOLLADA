/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IMPLICITBOX_H__
#define __MayaDM_IMPLICITBOX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
/*
Represents an implicit box shape.
The box has no explicit geometry or points that can be accessed,
and cannot be rendered.
It is useful for other operations (such as the sculpt deformation) that need
a true perfect box.
*/
class ImplicitBox : public GeometryShape
{
public:
public:
	ImplicitBox(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "implicitBox"){}
	virtual ~ImplicitBox(){}
	/*Provides an implicit box object*/
	void setBox(const BoxID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*relative size of the box in x y and z*/
	void setSize(const double3& siz){fprintf_s(mFile, "setAttr \".siz\" -type \"double3\" ");siz.write(mFile);fprintf_s(mFile,";\n");}
	/*relative size of the box in x y and z*/
	void setSize(const Double3ID& siz){fprintf_s(mFile,"connectAttr \"");siz.write(mFile);fprintf_s(mFile,"\" \"%s.siz\";\n",mName.c_str());}
	/*relative size of the box in x*/
	void setSizeX(double szx){if(szx == 2.0) return; fprintf_s(mFile, "setAttr \".siz.szx\" %f;\n", szx);}
	/*relative size of the box in x*/
	void setSizeX(const DoubleID& szx){fprintf_s(mFile,"connectAttr \"");szx.write(mFile);fprintf_s(mFile,"\" \"%s.siz.szx\";\n",mName.c_str());}
	/*relative size of the box in y*/
	void setSizeY(double szy){if(szy == 2.0) return; fprintf_s(mFile, "setAttr \".siz.szy\" %f;\n", szy);}
	/*relative size of the box in y*/
	void setSizeY(const DoubleID& szy){fprintf_s(mFile,"connectAttr \"");szy.write(mFile);fprintf_s(mFile,"\" \"%s.siz.szy\";\n",mName.c_str());}
	/*relative size of the box in z*/
	void setSizeZ(double szz){if(szz == 2.0) return; fprintf_s(mFile, "setAttr \".siz.szz\" %f;\n", szz);}
	/*relative size of the box in z*/
	void setSizeZ(const DoubleID& szz){fprintf_s(mFile,"connectAttr \"");szz.write(mFile);fprintf_s(mFile,"\" \"%s.siz.szz\";\n",mName.c_str());}
	/*Provides an implicit box object*/
	BoxID getBox(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*relative size of the box in x y and z*/
	Double3ID getSize(){char buffer[4096];sprintf_s (buffer, "%s.siz",mName.c_str());return (const char*)buffer;}
	/*relative size of the box in x*/
	DoubleID getSizeX(){char buffer[4096];sprintf_s (buffer, "%s.siz.szx",mName.c_str());return (const char*)buffer;}
	/*relative size of the box in y*/
	DoubleID getSizeY(){char buffer[4096];sprintf_s (buffer, "%s.siz.szy",mName.c_str());return (const char*)buffer;}
	/*relative size of the box in z*/
	DoubleID getSizeZ(){char buffer[4096];sprintf_s (buffer, "%s.siz.szz",mName.c_str());return (const char*)buffer;}
protected:
	ImplicitBox(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IMPLICITBOX_H__
