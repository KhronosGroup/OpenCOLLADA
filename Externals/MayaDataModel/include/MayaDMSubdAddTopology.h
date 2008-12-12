/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDADDTOPOLOGY_H__
#define __MayaDM_SUBDADDTOPOLOGY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifier.h"
namespace MayaDM
{
/*Node to create finer level vertices, edges and faces on shape in history.<p/>*/
class SubdAddTopology : public SubdModifier
{
public:
public:
	SubdAddTopology(FILE* file,const std::string& name,const std::string& parent=""):SubdModifier(file, name, parent, "subdAddTopology"){}
	virtual ~SubdAddTopology(){}
protected:
	SubdAddTopology(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDADDTOPOLOGY_H__
