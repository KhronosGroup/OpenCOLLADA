/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSEWEDGE_H__
#define __MayaDM_POLYSEWEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
Merge border edges within a given threshold.
 Edges must be on the same object to be merged.<p/>

 A pairwise comparison of input edges is performed. Pairs whose
 corresponding vertices are within threshold and whose
 orientations are aligned (i.e. their respective normals point
 in the same direction) are merged, as are the vertices.<p/>
*/
class PolySewEdge : public PolyModifierWorld
{
public:
public:
	PolySewEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polySewEdge"){}
	virtual ~PolySewEdge(){}
	/*Edges whose vertices are within tolerance will be merged.*/
	void setTolerance(double t){if(t == 0) return; fprintf_s(mFile, "setAttr \".t\" %f;\n", t);}
	/*Edges whose vertices are within tolerance will be merged.*/
	void setTolerance(const DoubleID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*If true : texture is sewn as well as the 3d edge.*/
	void setTexture(bool tx){if(tx == true) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*If true : texture is sewn as well as the 3d edge.*/
	void setTexture(const BoolID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tx\";\n",mName.c_str());}
	/*Edges whose vertices are within tolerance will be merged.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*If true : texture is sewn as well as the 3d edge.*/
	BoolID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
protected:
	PolySewEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSEWEDGE_H__
