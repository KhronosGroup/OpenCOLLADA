/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTERCLOSESTSAMPLE_H__
#define __MayaDM_FILTERCLOSESTSAMPLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFilter.h"
namespace MayaDM
{
/*<strong>Obsolete.</strong>  Use filterResample instead.*/
class FilterClosestSample : public Filter
{
public:
public:
	FilterClosestSample(FILE* file,const std::string& name,const std::string& parent=""):Filter(file, name, parent, "filterClosestSample"){}
	virtual ~FilterClosestSample(){}
	/*Obsolete. Output sample frequency in Hz.*/
	void setFrequency(double f){if(f == 30.) return; fprintf_s(mFile, "setAttr \".f\" %f;\n", f);}
	/*Obsolete. Output sample frequency in Hz.*/
	void setFrequency(const DoubleID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Obsolete. Output sample frequency in Hz.*/
	DoubleID getFrequency(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
protected:
	FilterClosestSample(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Filter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FILTERCLOSESTSAMPLE_H__
