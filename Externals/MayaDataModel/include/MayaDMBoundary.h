/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BOUNDARY_H__
#define __MayaDM_BOUNDARY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBoundaryBase.h"
namespace MayaDM
{
/*
Creates a boundary surface from three or four input curves.
 A boundary surface is a fast way to create a surface to fill an
 area bounded by three or four curves whose ends touch.
 <p/>
 The curve ends do not need to touch unless the "endPoint" attribute
 is true.
 <p/>
 Note that if surface curves (such
 as isoparms or trim edges) are used to form the boundary surface,
 the resulting surface has <b>no continuity</b> options.  Birail
 surfaces should be used in this case.
*/
class Boundary : public BoundaryBase
{
public:
public:
	Boundary(FILE* file,const std::string& name,const std::string& parent=""):BoundaryBase(file, name, parent, "boundary"){}
	virtual ~Boundary(){}
	/*True if the curve order is important.*/
	void setOrder(bool or){if(or == true) return; fprintf_s(mFile, "setAttr \".or\" %i;\n", or);}
	/*True if the curve order is important.*/
	void setOrder(const BoolID& or){fprintf_s(mFile,"connectAttr \"");or.write(mFile);fprintf_s(mFile,"\" \"%s.or\";\n",mName.c_str());}
	/*True means the curve ends must touch before a surface will be created.*/
	void setEndPoint(bool ep){if(ep == false) return; fprintf_s(mFile, "setAttr \".ep\" %i;\n", ep);}
	/*True means the curve ends must touch before a surface will be created.*/
	void setEndPoint(const BoolID& ep){fprintf_s(mFile,"connectAttr \"");ep.write(mFile);fprintf_s(mFile,"\" \"%s.ep\";\n",mName.c_str());}
	/*True if the curve order is important.*/
	BoolID getOrder(){char buffer[4096];sprintf_s (buffer, "%s.or",mName.c_str());return (const char*)buffer;}
	/*True means the curve ends must touch before a surface will be created.*/
	BoolID getEndPoint(){char buffer[4096];sprintf_s (buffer, "%s.ep",mName.c_str());return (const char*)buffer;}
protected:
	Boundary(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BoundaryBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BOUNDARY_H__
