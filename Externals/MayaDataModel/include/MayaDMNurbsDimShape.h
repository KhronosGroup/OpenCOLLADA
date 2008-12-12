/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSDIMSHAPE_H__
#define __MayaDM_NURBSDIMSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDimensionShape.h"
namespace MayaDM
{
/*
This node is the base class for all dimension shapes that are used to
        perform measurements on nurbs curves and surfaces. The information
        handled by this node includes:
 <ul>
        <li> input geometry - geometry to perform the measurement on.</li>
        <li> the u param value, on the geometry, at which the measurement is to be
                 performed.</li>
        <li> the v param value, on the geometry, at which the measurement is to be
                 performed.</li>
 </ul>
*/
class NurbsDimShape : public DimensionShape
{
public:
public:
	NurbsDimShape(FILE* file,const std::string& name,const std::string& parent=""):DimensionShape(file, name, parent, "nurbsDimShape"){}
	virtual ~NurbsDimShape(){}
	/*u param position of the dimension on the curve/surface.*/
	void setUParamValue(double upv){if(upv == 0.0) return; fprintf_s(mFile, "setAttr \".upv\" %f;\n", upv);}
	/*u param position of the dimension on the curve/surface.*/
	void setUParamValue(const DoubleID& upv){fprintf_s(mFile,"connectAttr \"");upv.write(mFile);fprintf_s(mFile,"\" \"%s.upv\";\n",mName.c_str());}
	/*v param position of the dimension on the surface.*/
	void setVParamValue(double vpv){if(vpv == 0.0) return; fprintf_s(mFile, "setAttr \".vpv\" %f;\n", vpv);}
	/*v param position of the dimension on the surface.*/
	void setVParamValue(const DoubleID& vpv){fprintf_s(mFile,"connectAttr \"");vpv.write(mFile);fprintf_s(mFile,"\" \"%s.vpv\";\n",mName.c_str());}
	/*The nurbs geometry that this dimension object is measuring.*/
	void setNurbsGeometry(const GenericID& ng){fprintf_s(mFile,"connectAttr \"");ng.write(mFile);fprintf_s(mFile,"\" \"%s.ng\";\n",mName.c_str());}
	/*u param position of the dimension on the curve/surface.*/
	DoubleID getUParamValue(){char buffer[4096];sprintf_s (buffer, "%s.upv",mName.c_str());return (const char*)buffer;}
	/*v param position of the dimension on the surface.*/
	DoubleID getVParamValue(){char buffer[4096];sprintf_s (buffer, "%s.vpv",mName.c_str());return (const char*)buffer;}
	/*The nurbs geometry that this dimension object is measuring.*/
	GenericID getNurbsGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ng",mName.c_str());return (const char*)buffer;}
protected:
	NurbsDimShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DimensionShape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NURBSDIMSHAPE_H__
