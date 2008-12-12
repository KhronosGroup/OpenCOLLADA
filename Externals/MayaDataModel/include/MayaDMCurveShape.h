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
/*
<p><pre>        This is an abstract base class, used in the derivation of curve
        type of classes (TnurbsCurve, Tpolyline, etc.). This class contains
        methods that are typically used by curve type of objects.
</pre></p>
*/
class CurveShape : public ControlPoint
{
public:
public:
	CurveShape(FILE* file,const std::string& name,const std::string& parent=""):ControlPoint(file, name, parent, "curveShape"){}
	virtual ~CurveShape(){}
protected:
	CurveShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ControlPoint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVESHAPE_H__
