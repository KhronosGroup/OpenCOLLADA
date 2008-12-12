/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBCONE_H__
#define __MayaDM_MAKENURBCONE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRevolvedPrimitive.h"
namespace MayaDM
{
/*
Compute a cone given the center (pivot), radius (radius), and a height
 ratio to determine the cone's height. A partial cone can be computed
 by using startSweep and endSweep.
 <br/>
 <br/>
 The resolution of the cone in the sweep direction can be controlled
 by specifying the useTolerance (useTolerance) attribute and the
 tolerance (tolerance). Otherwise the number of sections (sections) will
 be used. Use spans to control the cone's resolution in the opposite direction.
 <br/>
 <br/>
 Control the orientation of the cone by specifying the axis of the cone.
 <br/>
 <br/>
 The degree of the resulting surface can be linear or cubic.
 <p/>
*/
class MakeNurbCone : public RevolvedPrimitive
{
public:
public:
	MakeNurbCone(FILE* file,const std::string& name,const std::string& parent=""):RevolvedPrimitive(file, name, parent, "makeNurbCone"){}
	virtual ~MakeNurbCone(){}
	/*
	Create the cone with base on the origin as in Maya V8.0 and below
	Otherwise create cone centred at origin
	*/
	void setUseOldInitBehaviour(bool oib){if(oib == false) return; fprintf_s(mFile, "setAttr \".oib\" %i;\n", oib);}
	/*
	Create the cone with base on the origin as in Maya V8.0 and below
	Otherwise create cone centred at origin
	*/
	void setUseOldInitBehaviour(const BoolID& oib){fprintf_s(mFile,"connectAttr \"");oib.write(mFile);fprintf_s(mFile,"\" \"%s.oib\";\n",mName.c_str());}
	/*
	Create the cone with base on the origin as in Maya V8.0 and below
	Otherwise create cone centred at origin
	*/
	BoolID getUseOldInitBehaviour(){char buffer[4096];sprintf_s (buffer, "%s.oib",mName.c_str());return (const char*)buffer;}
protected:
	MakeNurbCone(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):RevolvedPrimitive(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBCONE_H__
