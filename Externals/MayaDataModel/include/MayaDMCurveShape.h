/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVESHAPE_H__
#define __MayaDM_CURVESHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMControlPoint.h"
namespace MayaDM
{
class CurveShape : public ControlPoint
{
public:
	CurveShape(FILE* file,const std::string& name,const std::string& parent=""):ControlPoint(file, name, parent, "curveShape"){}
	virtual ~CurveShape(){}
protected:
	CurveShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ControlPoint(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVESHAPE_H__
