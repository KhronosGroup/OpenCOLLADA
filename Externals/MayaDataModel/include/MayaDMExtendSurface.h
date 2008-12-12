/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXTENDSURFACE_H__
#define __MayaDM_EXTENDSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
*/
class ExtendSurface : public AbstractBaseCreate
{
public:
public:
	ExtendSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "extendSurface"){}
	virtual ~ExtendSurface(){}
	/*The surface to extend*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The surface to extend to (optional)*/
	void setTargetObject(const NurbsSurfaceID& to){fprintf_s(mFile,"connectAttr \"");to.write(mFile);fprintf_s(mFile,"\" \"%s.to\";\n",mName.c_str());}
	/*The type of extension (0 - tangent, 2 - extrapolate)*/
	void setExtensionType(unsigned int et){if(et == 0) return; fprintf_s(mFile, "setAttr \".et\" %i;\n", et);}
	/*The type of extension (0 - tangent, 2 - extrapolate)*/
	void setExtensionType(const UnsignedintID& et){fprintf_s(mFile,"connectAttr \"");et.write(mFile);fprintf_s(mFile,"\" \"%s.et\";\n",mName.c_str());}
	/*The extend method (0 - distance)*/
	void setExtendMethod(unsigned int em){if(em == 0) return; fprintf_s(mFile, "setAttr \".em\" %i;\n", em);}
	/*The extend method (0 - distance)*/
	void setExtendMethod(const UnsignedintID& em){fprintf_s(mFile,"connectAttr \"");em.write(mFile);fprintf_s(mFile,"\" \"%s.em\";\n",mName.c_str());}
	/*Which end of the surface to extend ( 0 - end, 1 - start, 2 - both )*/
	void setExtendSide(unsigned int es){if(es == 1) return; fprintf_s(mFile, "setAttr \".es\" %i;\n", es);}
	/*Which end of the surface to extend ( 0 - end, 1 - start, 2 - both )*/
	void setExtendSide(const UnsignedintID& es){fprintf_s(mFile,"connectAttr \"");es.write(mFile);fprintf_s(mFile,"\" \"%s.es\";\n",mName.c_str());}
	/*Which parametric direction of the surface to extend ( 0 - U, 1 - V, 2 - both )*/
	void setExtendDirection(unsigned int ed){if(ed == 0) return; fprintf_s(mFile, "setAttr \".ed\" %i;\n", ed);}
	/*Which parametric direction of the surface to extend ( 0 - U, 1 - V, 2 - both )*/
	void setExtendDirection(const UnsignedintID& ed){fprintf_s(mFile,"connectAttr \"");ed.write(mFile);fprintf_s(mFile,"\" \"%s.ed\";\n",mName.c_str());}
	/*Join extension to original*/
	void setJoin(bool jn){if(jn == true) return; fprintf_s(mFile, "setAttr \".jn\" %i;\n", jn);}
	/*Join extension to original*/
	void setJoin(const BoolID& jn){fprintf_s(mFile,"connectAttr \"");jn.write(mFile);fprintf_s(mFile,"\" \"%s.jn\";\n",mName.c_str());}
	/*The distance to extend (for by distance only)*/
	void setDistance(double d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*The distance to extend (for by distance only)*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Output surface*/
	void setOutputSurface(const NurbsSurfaceID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The surface to extend*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*The surface to extend to (optional)*/
	NurbsSurfaceID getTargetObject(){char buffer[4096];sprintf_s (buffer, "%s.to",mName.c_str());return (const char*)buffer;}
	/*The type of extension (0 - tangent, 2 - extrapolate)*/
	UnsignedintID getExtensionType(){char buffer[4096];sprintf_s (buffer, "%s.et",mName.c_str());return (const char*)buffer;}
	/*The extend method (0 - distance)*/
	UnsignedintID getExtendMethod(){char buffer[4096];sprintf_s (buffer, "%s.em",mName.c_str());return (const char*)buffer;}
	/*Which end of the surface to extend ( 0 - end, 1 - start, 2 - both )*/
	UnsignedintID getExtendSide(){char buffer[4096];sprintf_s (buffer, "%s.es",mName.c_str());return (const char*)buffer;}
	/*Which parametric direction of the surface to extend ( 0 - U, 1 - V, 2 - both )*/
	UnsignedintID getExtendDirection(){char buffer[4096];sprintf_s (buffer, "%s.ed",mName.c_str());return (const char*)buffer;}
	/*Join extension to original*/
	BoolID getJoin(){char buffer[4096];sprintf_s (buffer, "%s.jn",mName.c_str());return (const char*)buffer;}
	/*The distance to extend (for by distance only)*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	ExtendSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_EXTENDSURFACE_H__
