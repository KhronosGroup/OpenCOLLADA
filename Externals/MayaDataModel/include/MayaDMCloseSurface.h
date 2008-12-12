/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOSESURFACE_H__
#define __MayaDM_CLOSESURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
If the input surface is open in the direction specified by the
 "direction" attribute, then this node will make the surface periodic
 in that direction.  If the input surface is periodic, then this node
 will make the surface open.
 <p/> This node behaves as a toggle, ie. if a surface is closed twice,
 then the result is exactly the same as the original surface.
 <p/> Use this node if you want to close a surface such that it becomes
 curvature continous along one direction.
*/
class CloseSurface : public AbstractBaseCreate
{
public:
public:
	CloseSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "closeSurface"){}
	virtual ~CloseSurface(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*
	0 - without preserving the shape
	1 - preserve shape
	2 - blend
	*/
	void setPreserveShape(unsigned int ps){if(ps == 1) return; fprintf_s(mFile, "setAttr \".ps\" %i;\n", ps);}
	/*
	0 - without preserving the shape
	1 - preserve shape
	2 - blend
	*/
	void setPreserveShape(const UnsignedintID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*Skew the result toward the first or the second surface depending on the blend value being smaller or larger than 0.5.*/
	void setBlendBias(double bb){if(bb == 0.5) return; fprintf_s(mFile, "setAttr \".bb\" %f;\n", bb);}
	/*Skew the result toward the first or the second surface depending on the blend value being smaller or larger than 0.5.*/
	void setBlendBias(const DoubleID& bb){fprintf_s(mFile,"connectAttr \"");bb.write(mFile);fprintf_s(mFile,"\" \"%s.bb\";\n",mName.c_str());}
	/*If set to true, insert a knot in one of the original surfaces (relative position given by the parameter attribute below) in order to produce a slightly different effect.*/
	void setBlendKnotInsertion(bool bki){if(bki == false) return; fprintf_s(mFile, "setAttr \".bki\" %i;\n", bki);}
	/*If set to true, insert a knot in one of the original surfaces (relative position given by the parameter attribute below) in order to produce a slightly different effect.*/
	void setBlendKnotInsertion(const BoolID& bki){fprintf_s(mFile,"connectAttr \"");bki.write(mFile);fprintf_s(mFile,"\" \"%s.bki\";\n",mName.c_str());}
	/*The parameter value for the positioning of the newly inserted knot.*/
	void setParameter(double p){if(p == 0.1) return; fprintf_s(mFile, "setAttr \".p\" %f;\n", p);}
	/*The parameter value for the positioning of the newly inserted knot.*/
	void setParameter(const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*
	The direction in which to close:
	0 - U,
	1 - V,
	2 - Both U and V
	*/
	void setDirection(unsigned int d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The direction in which to close:
	0 - U,
	1 - V,
	2 - Both U and V
	*/
	void setDirection(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*
	0 - without preserving the shape
	1 - preserve shape
	2 - blend
	*/
	UnsignedintID getPreserveShape(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*Skew the result toward the first or the second surface depending on the blend value being smaller or larger than 0.5.*/
	DoubleID getBlendBias(){char buffer[4096];sprintf_s (buffer, "%s.bb",mName.c_str());return (const char*)buffer;}
	/*If set to true, insert a knot in one of the original surfaces (relative position given by the parameter attribute below) in order to produce a slightly different effect.*/
	BoolID getBlendKnotInsertion(){char buffer[4096];sprintf_s (buffer, "%s.bki",mName.c_str());return (const char*)buffer;}
	/*The parameter value for the positioning of the newly inserted knot.*/
	DoubleID getParameter(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*
	The direction in which to close:
	0 - U,
	1 - V,
	2 - Both U and V
	*/
	UnsignedintID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	CloseSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLOSESURFACE_H__
