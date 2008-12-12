/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVERANGE_H__
#define __MayaDM_CURVERANGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
<p><pre> Abstract class to parent nodes that produce curves (and could cut parts off)
</pre></p>
*/
class CurveRange : public AbstractBaseCreate
{
public:
public:
	CurveRange(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "curveRange"){}
	virtual ~CurveRange(){}
protected:
	CurveRange(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVERANGE_H__
