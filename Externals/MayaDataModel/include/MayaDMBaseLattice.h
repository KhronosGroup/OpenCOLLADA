/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BASELATTICE_H__
#define __MayaDM_BASELATTICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
This node represents the base (undeformed)
lattice shape. Each lattice (ffd) deformation has an associated base
lattice shape. The base shape defines the region of 3-d space that
the lattice acts upon. Geometries that are not located within the
base lattice will not be deformed by the lattice.
*/
class BaseLattice : public Shape
{
public:
public:
	BaseLattice(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "baseLattice"){}
	virtual ~BaseLattice(){}
protected:
	BaseLattice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BASELATTICE_H__
