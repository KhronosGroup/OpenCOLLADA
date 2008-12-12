/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PROJECTCURVE_H__
#define __MayaDM_PROJECTCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute the curve(s) on surface given a curve to project and the surface to
 project onto. If useNormal is true, the normals of the surface are used for
 the direction of projection. Otherwise, if useNormal is false then the
 project direction can be specified by the direction input.  Note that the
 result of this operation is a 2 dimensional curve.
 <p/>
*/
class ProjectCurve : public AbstractBaseCreate
{
public:
public:
	ProjectCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "projectCurve"){}
	virtual ~ProjectCurve(){}
	/*The input curve to project.*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*The input surface to project onto.*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Output curve(s) on surface (2 dimensional.)*/
	void setOutputCurve(size_t oc_i,const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc[%i]\";\n",mName.c_str(),oc_i);}
	/*Direction of projection. Available only if useNormal is false.*/
	void setDirection(const double3& d){fprintf_s(mFile, "setAttr \".d\" -type \"double3\" ");d.write(mFile);fprintf_s(mFile,";\n");}
	/*Direction of projection. Available only if useNormal is false.*/
	void setDirection(const Double3ID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*X direction of projection.*/
	void setDirectionX(double dx){if(dx == 0) return; fprintf_s(mFile, "setAttr \".d.dx\" %f;\n", dx);}
	/*X direction of projection.*/
	void setDirectionX(const DoubleID& dx){fprintf_s(mFile,"connectAttr \"");dx.write(mFile);fprintf_s(mFile,"\" \"%s.d.dx\";\n",mName.c_str());}
	/*Y direction of projection.*/
	void setDirectionY(double dy){if(dy == 0) return; fprintf_s(mFile, "setAttr \".d.dy\" %f;\n", dy);}
	/*Y direction of projection.*/
	void setDirectionY(const DoubleID& dy){fprintf_s(mFile,"connectAttr \"");dy.write(mFile);fprintf_s(mFile,"\" \"%s.d.dy\";\n",mName.c_str());}
	/*Z direction of projection.*/
	void setDirectionZ(double dz){if(dz == 1) return; fprintf_s(mFile, "setAttr \".d.dz\" %f;\n", dz);}
	/*Z direction of projection.*/
	void setDirectionZ(const DoubleID& dz){fprintf_s(mFile,"connectAttr \"");dz.write(mFile);fprintf_s(mFile,"\" \"%s.d.dz\";\n",mName.c_str());}
	/*Tolerance to fit to.*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*Tolerance to fit to.*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*True if the surface normal is to be used and false if the direction vector should be used instead.*/
	void setUseNormal(bool un){if(un == false) return; fprintf_s(mFile, "setAttr \".un\" %i;\n", un);}
	/*True if the surface normal is to be used and false if the direction vector should be used instead.*/
	void setUseNormal(const BoolID& un){fprintf_s(mFile,"connectAttr \"");un.write(mFile);fprintf_s(mFile,"\" \"%s.un\";\n",mName.c_str());}
	/*The input curve to project.*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*The input surface to project onto.*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Output curve(s) on surface (2 dimensional.)*/
	const NurbsCurveID& getOutputCurve(size_t oc_i){char buffer[4096];sprintf_s (buffer, "%s.oc[%i]",mName.c_str(),oc_i);return (const char*)buffer;}
	/*Direction of projection. Available only if useNormal is false.*/
	Double3ID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*X direction of projection.*/
	DoubleID getDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.d.dx",mName.c_str());return (const char*)buffer;}
	/*Y direction of projection.*/
	DoubleID getDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.d.dy",mName.c_str());return (const char*)buffer;}
	/*Z direction of projection.*/
	DoubleID getDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.d.dz",mName.c_str());return (const char*)buffer;}
	/*Tolerance to fit to.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*True if the surface normal is to be used and false if the direction vector should be used instead.*/
	BoolID getUseNormal(){char buffer[4096];sprintf_s (buffer, "%s.un",mName.c_str());return (const char*)buffer;}
protected:
	ProjectCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PROJECTCURVE_H__
