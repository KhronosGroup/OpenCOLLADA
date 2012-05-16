/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class PolyTriangulate : public PolyModifier
{
public:
public:

	PolyTriangulate():PolyModifier(){}
	PolyTriangulate(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyTriangulate", shared, create){}
	virtual ~PolyTriangulate(){}

	void setMaya80(bool m80)
	{
		if(m80 == true) return;
		fprintf(mFile,"\tsetAttr \".m80\" %i;\n", m80);
	}
protected:
	PolyTriangulate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYTRIANGULATE_H__
