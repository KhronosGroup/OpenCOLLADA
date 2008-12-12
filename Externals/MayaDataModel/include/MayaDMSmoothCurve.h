/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SMOOTHCURVE_H__
#define __MayaDM_SMOOTHCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Given an input curve (inputCurve) and the index of control verticies
 (index), we call a smoothing algorithm to remove the wiggles.
*/
class SmoothCurve : public AbstractBaseCreate
{
public:
public:
	SmoothCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "smoothCurve"){}
	virtual ~SmoothCurve(){}
	/*Input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*smoothness factor*/
	void setSmoothness(double s){if(s == 10.0) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*smoothness factor*/
	void setSmoothness(const DoubleID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*index of the control vertex*/
	void setIndex(size_t i_i,int i){if(i == 0) return; fprintf_s(mFile, "setAttr \".i[%i]\" %i;\n", i_i,i);}
	/*index of the control vertex*/
	void setIndex(size_t i_i,const IntID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*Output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*smoothness factor*/
	DoubleID getSmoothness(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*index of the control vertex*/
	const IntID& getIndex(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*Output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	SmoothCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SMOOTHCURVE_H__
