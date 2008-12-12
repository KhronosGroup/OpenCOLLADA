/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLOSESTPOINTONSURFACE_H__
#define __MayaDM_CLOSESTPOINTONSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
<p><pre> This node returns the closest point of an (x,y,z) point (attribute
 "inPosition") to a surface (given by the attribute "inputSurface").
 You can query the closest
 (x,y,z) point (attribute "position") or you can query the closest
 surface (u,v) point (given by attributes "parameterU" and "parameterV").
</pre></p>
*/
class ClosestPointOnSurface : public AbstractBaseCreate
{
public:
	/*All results - container holding closest point, u and v parameter values*/
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:
	ClosestPointOnSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "closestPointOnSurface"){}
	virtual ~ClosestPointOnSurface(){}
	/*The input surface for the info*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Input reference point*/
	void setInPosition(const double3& ip){if(ip == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ip\" -type \"double3\" ");ip.write(mFile);fprintf_s(mFile,";\n");}
	/*Input reference point*/
	void setInPosition(const Double3ID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip\";\n",mName.c_str());}
	/*Input X value of reference position*/
	void setInPositionX(double ipx){if(ipx == 0) return; fprintf_s(mFile, "setAttr \".ip.ipx\" %f;\n", ipx);}
	/*Input X value of reference position*/
	void setInPositionX(const DoubleID& ipx){fprintf_s(mFile,"connectAttr \"");ipx.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipx\";\n",mName.c_str());}
	/*Input Y value of reference position*/
	void setInPositionY(double ipy){if(ipy == 0) return; fprintf_s(mFile, "setAttr \".ip.ipy\" %f;\n", ipy);}
	/*Input Y value of reference position*/
	void setInPositionY(const DoubleID& ipy){fprintf_s(mFile,"connectAttr \"");ipy.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipy\";\n",mName.c_str());}
	/*Input Z value of reference position*/
	void setInPositionZ(double ipz){if(ipz == 0) return; fprintf_s(mFile, "setAttr \".ip.ipz\" %f;\n", ipz);}
	/*Input Z value of reference position*/
	void setInPositionZ(const DoubleID& ipz){fprintf_s(mFile,"connectAttr \"");ipz.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipz\";\n",mName.c_str());}
	/*All results - container holding closest point, u and v parameter values*/
	void setResult(const ResultID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The closest (x,y,z) position (in result compound)*/
	void setPosition(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.r.p\";\n",mName.c_str());}
	/*Computed X value of closest position*/
	void setPositionX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.px\";\n",mName.c_str());}
	/*Computed Y value of closest position*/
	void setPositionY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.py\";\n",mName.c_str());}
	/*Computed Z value of closest position*/
	void setPositionZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.r.p.pz\";\n",mName.c_str());}
	/*The U parameter value on the surface at the closest point*/
	void setParameterU(const DoubleID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.r.u\";\n",mName.c_str());}
	/*The V parameter value on the surface at the closest point*/
	void setParameterV(const DoubleID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.r.v\";\n",mName.c_str());}
	/*The input surface for the info*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Input reference point*/
	Double3ID getInPosition(){char buffer[4096];sprintf_s (buffer, "%s.ip",mName.c_str());return (const char*)buffer;}
	/*Input X value of reference position*/
	DoubleID getInPositionX(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipx",mName.c_str());return (const char*)buffer;}
	/*Input Y value of reference position*/
	DoubleID getInPositionY(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipy",mName.c_str());return (const char*)buffer;}
	/*Input Z value of reference position*/
	DoubleID getInPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipz",mName.c_str());return (const char*)buffer;}
	/*All results - container holding closest point, u and v parameter values*/
	ResultID getResult(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The closest (x,y,z) position (in result compound)*/
	Double3ID getPosition(){char buffer[4096];sprintf_s (buffer, "%s.r.p",mName.c_str());return (const char*)buffer;}
	/*Computed X value of closest position*/
	DoubleID getPositionX(){char buffer[4096];sprintf_s (buffer, "%s.r.p.px",mName.c_str());return (const char*)buffer;}
	/*Computed Y value of closest position*/
	DoubleID getPositionY(){char buffer[4096];sprintf_s (buffer, "%s.r.p.py",mName.c_str());return (const char*)buffer;}
	/*Computed Z value of closest position*/
	DoubleID getPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.p.pz",mName.c_str());return (const char*)buffer;}
	/*The U parameter value on the surface at the closest point*/
	DoubleID getParameterU(){char buffer[4096];sprintf_s (buffer, "%s.r.u",mName.c_str());return (const char*)buffer;}
	/*The V parameter value on the surface at the closest point*/
	DoubleID getParameterV(){char buffer[4096];sprintf_s (buffer, "%s.r.v",mName.c_str());return (const char*)buffer;}
protected:
	ClosestPointOnSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLOSESTPOINTONSURFACE_H__
