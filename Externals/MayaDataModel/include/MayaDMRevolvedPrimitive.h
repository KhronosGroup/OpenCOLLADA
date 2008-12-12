/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REVOLVEDPRIMITIVE_H__
#define __MayaDM_REVOLVEDPRIMITIVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPrimitive.h"
namespace MayaDM
{
/*
Compute a surface of revolution given a radius. A partial surface
 of revolution can be created by using startSweep and endSweep.
 This is used for creating spheres, cylinders, and cones. Please refer
 to their documentation for more specific descriptions.
 <p/>
*/
class RevolvedPrimitive : public Primitive
{
public:
public:
	RevolvedPrimitive(FILE* file,const std::string& name,const std::string& parent=""):Primitive(file, name, parent, "revolvedPrimitive"){}
	virtual ~RevolvedPrimitive(){}
	/*The radius of the object*/
	void setRadius(double r){if(r == 1) return; fprintf_s(mFile, "setAttr \".r\" %f;\n", r);}
	/*The radius of the object*/
	void setRadius(const DoubleID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The angle at which to start the surface of revolution*/
	void setStartSweep(double ssw){if(ssw == 0) return; fprintf_s(mFile, "setAttr \".ssw\" %f;\n", ssw);}
	/*The angle at which to start the surface of revolution*/
	void setStartSweep(const DoubleID& ssw){fprintf_s(mFile,"connectAttr \"");ssw.write(mFile);fprintf_s(mFile,"\" \"%s.ssw\";\n",mName.c_str());}
	/*
	The angle at which to end the surface of revolution.
	Default is 2Pi radians, or 360 degrees.
	*/
	void setEndSweep(double esw){if(esw == 6.2831853) return; fprintf_s(mFile, "setAttr \".esw\" %f;\n", esw);}
	/*
	The angle at which to end the surface of revolution.
	Default is 2Pi radians, or 360 degrees.
	*/
	void setEndSweep(const DoubleID& esw){fprintf_s(mFile,"connectAttr \"");esw.write(mFile);fprintf_s(mFile,"\" \"%s.esw\";\n",mName.c_str());}
	/*
	Use the specified tolerance to determine resolution.
	Otherwise number of sections will be used.
	*/
	void setUseTolerance(bool ut){if(ut == false) return; fprintf_s(mFile, "setAttr \".ut\" %i;\n", ut);}
	/*
	Use the specified tolerance to determine resolution.
	Otherwise number of sections will be used.
	*/
	void setUseTolerance(const BoolID& ut){fprintf_s(mFile,"connectAttr \"");ut.write(mFile);fprintf_s(mFile,"\" \"%s.ut\";\n",mName.c_str());}
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
	/*
	The number of sections determines the resolution of the surface in the sweep direction.
	Used only if useTolerance is false.
	*/
	void setSections(int s){if(s == 8) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*
	The number of sections determines the resolution of the surface in the sweep direction.
	Used only if useTolerance is false.
	*/
	void setSections(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*The number of spans determines the resolution of the surface in the opposite direction.*/
	void setSpans(int nsp){if(nsp == 1) return; fprintf_s(mFile, "setAttr \".nsp\" %i;\n", nsp);}
	/*The number of spans determines the resolution of the surface in the opposite direction.*/
	void setSpans(const IntID& nsp){fprintf_s(mFile,"connectAttr \"");nsp.write(mFile);fprintf_s(mFile,"\" \"%s.nsp\";\n",mName.c_str());}
	/*
	The tolerance with which to build the surface.
	Used only if useTolerance is true
	*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*
	The tolerance with which to build the surface.
	Used only if useTolerance is true
	*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*Ratio of "height" to "width"*/
	void setHeightRatio(double hr){if(hr == 2.0) return; fprintf_s(mFile, "setAttr \".hr\" %f;\n", hr);}
	/*Ratio of "height" to "width"*/
	void setHeightRatio(const DoubleID& hr){fprintf_s(mFile,"connectAttr \"");hr.write(mFile);fprintf_s(mFile,"\" \"%s.hr\";\n",mName.c_str());}
	/*The curve that can be used for the top cap*/
	void setTopCapCurve(const NurbsCurveID& tcc){fprintf_s(mFile,"connectAttr \"");tcc.write(mFile);fprintf_s(mFile,"\" \"%s.tcc\";\n",mName.c_str());}
	/*The curve that can be used for the bot cap*/
	void setBottomCapCurve(const NurbsCurveID& bcc){fprintf_s(mFile,"connectAttr \"");bcc.write(mFile);fprintf_s(mFile,"\" \"%s.bcc\";\n",mName.c_str());}
	/*The difference of endSweep - startSweep*/
	void setAbsoluteSweepDifference(const DoubleID& asd){fprintf_s(mFile,"connectAttr \"");asd.write(mFile);fprintf_s(mFile,"\" \"%s.asd\";\n",mName.c_str());}
	/*The radius of the object*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The angle at which to start the surface of revolution*/
	DoubleID getStartSweep(){char buffer[4096];sprintf_s (buffer, "%s.ssw",mName.c_str());return (const char*)buffer;}
	/*
	The angle at which to end the surface of revolution.
	Default is 2Pi radians, or 360 degrees.
	*/
	DoubleID getEndSweep(){char buffer[4096];sprintf_s (buffer, "%s.esw",mName.c_str());return (const char*)buffer;}
	/*
	Use the specified tolerance to determine resolution.
	Otherwise number of sections will be used.
	*/
	BoolID getUseTolerance(){char buffer[4096];sprintf_s (buffer, "%s.ut",mName.c_str());return (const char*)buffer;}
	/*
	The degree of the resulting surface:
	1 - linear,
	3 - cubic
	*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	The number of sections determines the resolution of the surface in the sweep direction.
	Used only if useTolerance is false.
	*/
	IntID getSections(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*The number of spans determines the resolution of the surface in the opposite direction.*/
	IntID getSpans(){char buffer[4096];sprintf_s (buffer, "%s.nsp",mName.c_str());return (const char*)buffer;}
	/*
	The tolerance with which to build the surface.
	Used only if useTolerance is true
	*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*Ratio of "height" to "width"*/
	DoubleID getHeightRatio(){char buffer[4096];sprintf_s (buffer, "%s.hr",mName.c_str());return (const char*)buffer;}
	/*The curve that can be used for the top cap*/
	NurbsCurveID getTopCapCurve(){char buffer[4096];sprintf_s (buffer, "%s.tcc",mName.c_str());return (const char*)buffer;}
	/*The curve that can be used for the bot cap*/
	NurbsCurveID getBottomCapCurve(){char buffer[4096];sprintf_s (buffer, "%s.bcc",mName.c_str());return (const char*)buffer;}
	/*The difference of endSweep - startSweep*/
	DoubleID getAbsoluteSweepDifference(){char buffer[4096];sprintf_s (buffer, "%s.asd",mName.c_str());return (const char*)buffer;}
protected:
	RevolvedPrimitive(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Primitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REVOLVEDPRIMITIVE_H__
