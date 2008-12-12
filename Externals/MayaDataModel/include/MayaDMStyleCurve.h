/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STYLECURVE_H__
#define __MayaDM_STYLECURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
*/
class StyleCurve : public AbstractBaseCreate
{
public:
public:
	StyleCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "styleCurve"){}
	virtual ~StyleCurve(){}
	/*Curve style type:*/
	void setStyle(unsigned int s){if(s == 0) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*Curve style type:*/
	void setStyle(const UnsignedintID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*The style curve computed based on the ID*/
	void setOutCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Curve style type:*/
	UnsignedintID getStyle(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*The style curve computed based on the ID*/
	NurbsCurveID getOutCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	StyleCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_STYLECURVE_H__
