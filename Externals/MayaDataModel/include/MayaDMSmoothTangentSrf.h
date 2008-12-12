/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SMOOTHTANGENTSRF_H__
#define __MayaDM_SMOOTHTANGENTSRF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
This node will smooth a tangent along an isoparm.  The number of
 cvs/spans doesn't change, just some cvs are moved.
 <p/>
 Note: A single smoothTangentSrf node cannot smooth in both directions
 at once; you must use two nodes to do this.
*/
class SmoothTangentSrf : public AbstractBaseCreate
{
public:
public:
	SmoothTangentSrf(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "smoothTangentSrf"){}
	virtual ~SmoothTangentSrf(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Parameter value(s) where knots are added*/
	void setParameter(size_t p_i,double p){if(p == 0.0) return; fprintf_s(mFile, "setAttr \".p[%i]\" %f;\n", p_i,p);}
	/*Parameter value(s) where knots are added*/
	void setParameter(size_t p_i,const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*
	Direction in which to smooth knot:
	0 - V direction,
	1 - U direction
	*/
	void setDirection(unsigned int d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	Direction in which to smooth knot:
	0 - V direction,
	1 - U direction
	*/
	void setDirection(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	Smoothness to get:
	0 - Tangent,
	1 - Maximum (based on the degree)
	*/
	void setSmoothness(unsigned int s){if(s == 1) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*
	Smoothness to get:
	0 - Tangent,
	1 - Maximum (based on the degree)
	*/
	void setSmoothness(const UnsignedintID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*The output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Parameter value(s) where knots are added*/
	const DoubleID& getParameter(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*
	Direction in which to smooth knot:
	0 - V direction,
	1 - U direction
	*/
	UnsignedintID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	Smoothness to get:
	0 - Tangent,
	1 - Maximum (based on the degree)
	*/
	UnsignedintID getSmoothness(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*The output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	SmoothTangentSrf(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SMOOTHTANGENTSRF_H__
