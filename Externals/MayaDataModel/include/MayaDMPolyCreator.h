/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCREATOR_H__
#define __MayaDM_POLYCREATOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyBase.h"
namespace MayaDM
{
/*
<p><pre> A base node for the polygonal creation nodes : polyPrimitive, polyCreateFacet and polyUnite.
</pre></p>
*/
class PolyCreator : public PolyBase
{
public:
public:
	PolyCreator(FILE* file,const std::string& name,const std::string& parent=""):PolyBase(file, name, parent, "polyCreator"){}
	virtual ~PolyCreator(){}
protected:
	PolyCreator(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCREATOR_H__
