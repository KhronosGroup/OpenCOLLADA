/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARAMDIMENSION_H__
#define __MayaDM_PARAMDIMENSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNurbsDimShape.h"
namespace MayaDM
{
/*
This node is basically used to visually display param values on curves
        and surfaces at the specified point. <p/>

  When dealing with curves, it displays the param value in u at the
        specified point on the curve. On the other hand, when dealing with
        surfaces, it displays the param value in u and v at the specified
        point. <p/>

  These nodes are created either using the "paramDimension" command or by
        using the "parameter" tool. After creation, by using the "move" tool, the
        shape can be moved around on the curve/surface, and the param values
        updates interactively based on the new position of the object. <p/>
*/
class ParamDimension : public NurbsDimShape
{
public:
public:
	ParamDimension(FILE* file,const std::string& name,const std::string& parent=""):NurbsDimShape(file, name, parent, "paramDimension"){}
	virtual ~ParamDimension(){}
protected:
	ParamDimension(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):NurbsDimShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARAMDIMENSION_H__
