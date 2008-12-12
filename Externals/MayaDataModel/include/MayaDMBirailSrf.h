/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BIRAILSRF_H__
#define __MayaDM_BIRAILSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Nodes derived from this are 'spBirailSrf', 'mpBirailSrf'
 and 'dpBirailSrf'.
 <p/>
 The input attributes 'inputRail1' and 'inputRail2' are the
 two rail NURBS curves used in the NURBS surface creation.
 <p/>
 The attribute 'transformMode' can be used to scale the profiles
 proportionately or non proportionately. The scaling is done in
 an internal local coordinate frame. The legal values are :
 0 - Non proportional , 1 - proportional.
 <p/>
 The attribute 'outputSurface' provides the computed surface.
 <p/>
 The attribute 'surfaceCache' is an internal cached version of the
 computed surface void of any continuity. Toggling of the continuity
 controls in the derived modifies only a copy of this cache.
 <p/>
*/
class BirailSrf : public AbstractBaseCreate
{
public:
public:
	BirailSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "birailSrf"){}
	virtual ~BirailSrf(){}
	/*Rail Curve 1*/
	void setInputRail1(const NurbsCurveID& ir1){fprintf_s(mFile,"connectAttr \"");ir1.write(mFile);fprintf_s(mFile,"\" \"%s.ir1\";\n",mName.c_str());}
	/*Rail Curve 2*/
	void setInputRail2(const NurbsCurveID& ir2){fprintf_s(mFile,"connectAttr \"");ir2.write(mFile);fprintf_s(mFile,"\" \"%s.ir2\";\n",mName.c_str());}
	/*sweep style for Profile ( Natural, View ). Only Natural is supported.*/
	void setSweepStyle(const UnsignedintID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*transform mode ( Non proportional, proportional ). Non proportional is default value.*/
	void setTransformMode(unsigned int tm){if(tm == 0) return; fprintf_s(mFile, "setAttr \".tm\" %i;\n", tm);}
	/*transform mode ( Non proportional, proportional ). Non proportional is default value.*/
	void setTransformMode(const UnsignedintID& tm){fprintf_s(mFile,"connectAttr \"");tm.write(mFile);fprintf_s(mFile,"\" \"%s.tm\";\n",mName.c_str());}
	/*Output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*Rail Curve 1*/
	NurbsCurveID getInputRail1(){char buffer[4096];sprintf_s (buffer, "%s.ir1",mName.c_str());return (const char*)buffer;}
	/*Rail Curve 2*/
	NurbsCurveID getInputRail2(){char buffer[4096];sprintf_s (buffer, "%s.ir2",mName.c_str());return (const char*)buffer;}
	/*sweep style for Profile ( Natural, View ). Only Natural is supported.*/
	UnsignedintID getSweepStyle(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*transform mode ( Non proportional, proportional ). Non proportional is default value.*/
	UnsignedintID getTransformMode(){char buffer[4096];sprintf_s (buffer, "%s.tm",mName.c_str());return (const char*)buffer;}
	/*Output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	BirailSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BIRAILSRF_H__
