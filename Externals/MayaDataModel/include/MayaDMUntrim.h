/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNTRIM_H__
#define __MayaDM_UNTRIM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Untrim an already trimmed surface by reverting to its underlying surface.
 All the 2D trimming curves can be had through outputCurve/oc attribute.
 <p/>
*/
class Untrim : public AbstractBaseCreate
{
public:
public:
	Untrim(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "untrim"){}
	virtual ~Untrim(){}
	/*The surface to untrim.*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The untrimmed surface.*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*Output curve(s) on surface extracted from the trim boundaries.*/
	void setOutputCurve(size_t oc_i,const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc[%i]\";\n",mName.c_str(),oc_i);}
	/*The surface to untrim.*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*The untrimmed surface.*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*Output curve(s) on surface extracted from the trim boundaries.*/
	const NurbsCurveID& getOutputCurve(size_t oc_i){char buffer[4096];sprintf_s (buffer, "%s.oc[%i]",mName.c_str(),oc_i);return (const char*)buffer;}
protected:
	Untrim(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_UNTRIM_H__
