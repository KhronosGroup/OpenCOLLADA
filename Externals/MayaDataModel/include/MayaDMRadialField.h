/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RADIALFIELD_H__
#define __MayaDM_RADIALFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
The radialField node implements a radial field.  A radial field
pushes objects away from a point (if the magnitude is positive)
or pulls them toward it (if the magnitude is negative).  The type
attribute determines how the attentuation parameter is to be applied
to reduce the magnitude as a functionof distance.<p/>
*/
class RadialField : public Field
{
public:
public:
	RadialField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "radialField"){}
	virtual ~RadialField(){}
	/*
	type of radial field (0, 1, or in between)
	Controls how the max distance interacts with attenuation.
	Value 0 smooths magnitude to zero as you approach max distance.
	Value 1 ignores max distance, giving an immediate drop-off to
	zero when you reach max distance.  In between you get a blend.
	*/
	void setRadialType(double typ){if(typ == 0.0) return; fprintf_s(mFile, "setAttr \".typ\" %f;\n", typ);}
	/*
	type of radial field (0, 1, or in between)
	Controls how the max distance interacts with attenuation.
	Value 0 smooths magnitude to zero as you approach max distance.
	Value 1 ignores max distance, giving an immediate drop-off to
	zero when you reach max distance.  In between you get a blend.
	*/
	void setRadialType(const DoubleID& typ){fprintf_s(mFile,"connectAttr \"");typ.write(mFile);fprintf_s(mFile,"\" \"%s.typ\";\n",mName.c_str());}
	/*
	type of radial field (0, 1, or in between)
	Controls how the max distance interacts with attenuation.
	Value 0 smooths magnitude to zero as you approach max distance.
	Value 1 ignores max distance, giving an immediate drop-off to
	zero when you reach max distance.  In between you get a blend.
	*/
	DoubleID getRadialType(){char buffer[4096];sprintf_s (buffer, "%s.typ",mName.c_str());return (const char*)buffer;}
protected:
	RadialField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RADIALFIELD_H__
