/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBTORUS_H__
#define __MayaDM_MAKENURBTORUS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRevolvedPrimitive.h"
namespace MayaDM
{
/*
Compute a torus given the center point (pivot) and the radius (radius).
 A partial torus can be computed by using startSweep and endSweep and
 minorSweep angles.
 <br/>
 <br/>
 The resolution of the torus can be controlled by specifying the
 useTolerance (useTolerance) attribute and the tolerance (tolerance).
 Otherwise the number of sections and spans will be used.

 <br/>
 <br/>
 Control the orientation of the torus by specifying the axis of the torus.
 <br/>
 <br/>
 The degree of the resulting surface can be linear or cubic.
 <p/>
*/
class MakeNurbTorus : public RevolvedPrimitive
{
public:
public:
	MakeNurbTorus(FILE* file,const std::string& name,const std::string& parent=""):RevolvedPrimitive(file, name, parent, "makeNurbTorus"){}
	virtual ~MakeNurbTorus(){}
	/*The sweep angle for the minor circle in the torus*/
	void setMinorSweep(double msw){if(msw == 6.2831853) return; fprintf_s(mFile, "setAttr \".msw\" %f;\n", msw);}
	/*The sweep angle for the minor circle in the torus*/
	void setMinorSweep(const DoubleID& msw){fprintf_s(mFile,"connectAttr \"");msw.write(mFile);fprintf_s(mFile,"\" \"%s.msw\";\n",mName.c_str());}
	/*The sweep angle for the minor circle in the torus*/
	DoubleID getMinorSweep(){char buffer[4096];sprintf_s (buffer, "%s.msw",mName.c_str());return (const char*)buffer;}
protected:
	MakeNurbTorus(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):RevolvedPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBTORUS_H__
