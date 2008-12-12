/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REVERSESURFACE_H__
#define __MayaDM_REVERSESURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Reverses one or both directions of the input surface or "swaps" the
 U and V surface directions.  Swapping the directions produces the effect of
 reversing the surface normal.
 <p/>  Reversing a surface twice in the same direction produces the
 exact same result as the original surface.  eg. reversing twice in U
 results in the original surface.
*/
class ReverseSurface : public AbstractBaseCreate
{
public:
public:
	ReverseSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "reverseSurface"){}
	virtual ~ReverseSurface(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*
	The direction to reverse the surface in:
	0 - U,
	1 - V,
	2 - Both U and V,
	3 - Swap
	*/
	void setDirection(unsigned int d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The direction to reverse the surface in:
	0 - U,
	1 - V,
	2 - Both U and V,
	3 - Swap
	*/
	void setDirection(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*
	The direction to reverse the surface in:
	0 - U,
	1 - V,
	2 - Both U and V,
	3 - Swap
	*/
	UnsignedintID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	ReverseSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REVERSESURFACE_H__
