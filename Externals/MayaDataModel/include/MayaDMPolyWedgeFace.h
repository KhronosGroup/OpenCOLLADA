/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYWEDGEFACE_H__
#define __MayaDM_POLYWEDGEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
<p><pre>    This node extrudes face(s) about an edge


</pre></p>
*/
class PolyWedgeFace : public PolyModifierWorld
{
public:
public:
	PolyWedgeFace(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyWedgeFace"){}
	virtual ~PolyWedgeFace(){}
	/*wedge angle.*/
	void setWedgeAngle(double wa){if(wa == 0) return; fprintf_s(mFile, "setAttr \".wa\" %f;\n", wa);}
	/*wedge angle.*/
	void setWedgeAngle(const DoubleID& wa){fprintf_s(mFile,"connectAttr \"");wa.write(mFile);fprintf_s(mFile,"\" \"%s.wa\";\n",mName.c_str());}
	/*How many divisions should the wedge be broken-up into.*/
	void setDivisions(int d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*How many divisions should the wedge be broken-up into.*/
	void setDivisions(const IntID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*List of Edge Ids about which the faces will be extruded*/
	void setEdge(size_t ed_i,int ed){if(ed == 0) return; fprintf_s(mFile, "setAttr \".ed[%i]\" %i;\n", ed_i,ed);}
	/*List of Edge Ids about which the faces will be extruded*/
	void setEdge(size_t ed_i,const IntID& ed){fprintf_s(mFile,"connectAttr \"");ed.write(mFile);fprintf_s(mFile,"\" \"%s.ed[%i]\";\n",mName.c_str(),ed_i);}
	/*wedge angle.*/
	DoubleID getWedgeAngle(){char buffer[4096];sprintf_s (buffer, "%s.wa",mName.c_str());return (const char*)buffer;}
	/*How many divisions should the wedge be broken-up into.*/
	IntID getDivisions(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*List of Edge Ids about which the faces will be extruded*/
	const IntID& getEdge(size_t ed_i){char buffer[4096];sprintf_s (buffer, "%s.ed[%i]",mName.c_str(),ed_i);return (const char*)buffer;}
protected:
	PolyWedgeFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYWEDGEFACE_H__
