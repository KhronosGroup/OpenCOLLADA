/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSOFTEDGE_H__
#define __MayaDM_POLYSOFTEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
<p><pre> Selectively makes edges soft or hard.

 An edge is hard if the angle between two owning facets is sharper (larger)
 than the smoothing angle.
 An edge is soft if the angle between two owning facets is flatter (smaller)
 than the smoothing angle.
</pre></p>
*/
class PolySoftEdge : public PolyModifierWorld
{
public:
public:
	PolySoftEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySoftEdge"){}
	virtual ~PolySoftEdge(){}
	/*Smoothing angle. An angle value greater than "angle", means that the edges are rendered hard; otherwise, they are rendered soft.*/
	void setAngle(double a){if(a == 3) return; fprintf_s(mFile, "setAttr \".a\" %f;\n", a);}
	/*Smoothing angle. An angle value greater than "angle", means that the edges are rendered hard; otherwise, they are rendered soft.*/
	void setAngle(const DoubleID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*Smoothing angle. An angle value greater than "angle", means that the edges are rendered hard; otherwise, they are rendered soft.*/
	DoubleID getAngle(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
protected:
	PolySoftEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSOFTEDGE_H__
