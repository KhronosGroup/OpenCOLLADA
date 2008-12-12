/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDCLEANTOPOLOGY_H__
#define __MayaDM_SUBDCLEANTOPOLOGY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifier.h"
namespace MayaDM
{
/*
Node to clean topology of subdiv surfaces - at all levels. It removes
 vertices that satisfy the following conditions:
                - Zero edits
                - Default uvs (uvs obtained by subdividing parent face).
                - No creases.<p/>
*/
class SubdCleanTopology : public SubdModifier
{
public:
public:
	SubdCleanTopology(FILE* file,const std::string& name,const std::string& parent=""):SubdModifier(file, name, parent, "subdCleanTopology"){}
	virtual ~SubdCleanTopology(){}
protected:
	SubdCleanTopology(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDCLEANTOPOLOGY_H__
