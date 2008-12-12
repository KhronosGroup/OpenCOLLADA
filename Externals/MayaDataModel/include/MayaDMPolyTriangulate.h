/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTRIANGULATE_H__
#define __MayaDM_POLYTRIANGULATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Breaks non-triangular faces into triangles.<p/>

 Triangulation ensures that faces are planar and non-holed.
 If four or more sided faces are not required, triangulation will
 ensure model is topologically correct. Among other benefits, this will
 improve rendering results, particularly when models include
 non-planar faces.<p/>

 See the documentation for the parent node polyModifier for more
 details.<p/>
*/
class PolyTriangulate : public PolyModifier
{
public:
public:
	PolyTriangulate(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyTriangulate"){}
	virtual ~PolyTriangulate(){}
	/*
	Enable Maya 8.0 behaviour.
	This attribute is not meant to be modified through command line.
	*/
	void setMaya80(bool m80){if(m80 == true) return; fprintf_s(mFile, "setAttr \".m80\" %i;\n", m80);}
protected:
	PolyTriangulate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYTRIANGULATE_H__
