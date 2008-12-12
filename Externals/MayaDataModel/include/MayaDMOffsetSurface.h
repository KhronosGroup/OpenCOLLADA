/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OFFSETSURFACE_H__
#define __MayaDM_OFFSETSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Create a new surface which is an offset of an existing surface.
 The 'distance' attribute defines how far the offset surface should be
 from the original surface. The method defines how the offset is done.
 The standard method is more accurate, but slower than the approximate
 method. In both cases, the offset surface has the same number of CVs
 and the same knots as the original surface.
*/
class OffsetSurface : public AbstractBaseCreate
{
public:
public:
	OffsetSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "offsetSurface"){}
	virtual ~OffsetSurface(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Offset distance*/
	void setDistance(double d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*Offset distance*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	Offset method
	0 - Surface Fit
	1 - CV Fit
	*/
	void setMethod(unsigned int m){if(m == 0) return; fprintf_s(mFile, "setAttr \".m\" %i;\n", m);}
	/*
	Offset method
	0 - Surface Fit
	1 - CV Fit
	*/
	void setMethod(const UnsignedintID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*Output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Offset distance*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	Offset method
	0 - Surface Fit
	1 - CV Fit
	*/
	UnsignedintID getMethod(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*Output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	OffsetSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_OFFSETSURFACE_H__
