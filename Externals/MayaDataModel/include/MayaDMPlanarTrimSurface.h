/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PLANARTRIMSURFACE_H__
#define __MayaDM_PLANARTRIMSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute a planar trimmed surface by building a plane that contains
 all the input curves and trimming the surface to the input curves.
 Use keepOutside to keep the outer regions. Otherwise the inner
 regions will be kept.
 The resulting planar trimmed surface can be linear or cubic.
 <p/>
*/
class PlanarTrimSurface : public AbstractBaseCreate
{
public:
public:
	PlanarTrimSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "planarTrimSurface"){}
	virtual ~PlanarTrimSurface(){}
	/*The planar curves with which to trim a plane.*/
	void setInputCurve(size_t ic_i,const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i]\";\n",mName.c_str(),ic_i);}
	/*
	The degree of the resulting surface:
	1 - linear,
	3 - cubic
	*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The degree of the resulting surface:
	1 - linear,
	3 - cubic
	*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*If true, keep the regions outside the given curves.*/
	void setKeepOutside(bool ko){if(ko == false) return; fprintf_s(mFile, "setAttr \".ko\" %i;\n", ko);}
	/*If true, keep the regions outside the given curves.*/
	void setKeepOutside(const BoolID& ko){fprintf_s(mFile,"connectAttr \"");ko.write(mFile);fprintf_s(mFile,"\" \"%s.ko\";\n",mName.c_str());}
	/*The planar trimmed surface.*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The distance tolerance for the cvs of the curves to be in the same plane.*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*The distance tolerance for the cvs of the curves to be in the same plane.*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*The planar curves with which to trim a plane.*/
	const NurbsCurveID& getInputCurve(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i]",mName.c_str(),ic_i);return (const char*)buffer;}
	/*
	The degree of the resulting surface:
	1 - linear,
	3 - cubic
	*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*If true, keep the regions outside the given curves.*/
	BoolID getKeepOutside(){char buffer[4096];sprintf_s (buffer, "%s.ko",mName.c_str());return (const char*)buffer;}
	/*The planar trimmed surface.*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*The distance tolerance for the cvs of the curves to be in the same plane.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
protected:
	PlanarTrimSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PLANARTRIMSURFACE_H__
