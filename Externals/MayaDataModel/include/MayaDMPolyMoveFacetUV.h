/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMOVEFACETUV_H__
#define __MayaDM_POLYMOVEFACETUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveUV.h"
namespace MayaDM
{
/*
Modifies UV coordinates belonging to input faces. The
 texture coordinates are transformed
 without changing the 3D geometry of the object.<p/>
*/
class PolyMoveFacetUV : public PolyMoveUV
{
public:
public:
	PolyMoveFacetUV(FILE* file,const std::string& name,const std::string& parent=""):PolyMoveUV(file, name, parent, "polyMoveFacetUV"){}
	virtual ~PolyMoveFacetUV(){}
protected:
	PolyMoveFacetUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyMoveUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMOVEFACETUV_H__
