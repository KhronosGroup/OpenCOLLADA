/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMERGEVERT_H__
#define __MayaDM_POLYMERGEVERT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
Merge vertices within a given threshold.
 Vertices must lie on the same object to be merged.<p/>

 Two methods are used to merge vertices.
 First, a pairwise comparison of selected vertices is performed.
 A pair is considered if both vertices lie on a border
 and they share an edge. They are merged with another pair
 if the respective vertices are within distance attrbute of one
 another and their orientations match (i.e. the
 normals on both faces point in the same direction).
 Second, any selected vertices which share an edge are
 merged if the distance between them is within the
 threshold value.<p/>
 Both edges and vertices are merged.<p/>

 NOTE: If only two vertices are selected and alwaysMergeTwoVertices is  set
 to true, the tolerance is ignored and the vertices will be merged
 regardless of distance.

 Resulting geometry may have extra vertices or edges
 to ensure valid topology.<p/>
*/
class PolyMergeVert : public PolyModifierWorld
{
public:
public:
	PolyMergeVert(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyMergeVert"){}
	virtual ~PolyMergeVert(){}
	/*
	Tolerance to determine whether vertices (and edges) should
	be merged.
	*/
	void setDistance(double d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	Tolerance to determine whether vertices (and edges) should
	be merged.
	*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	If true : if only two vertices are selected, they will be merged
	regardless of distance
	*/
	void setAlwaysMergeTwoVertices(bool am){if(am == false) return; fprintf_s(mFile, "setAttr \".am\" %i;\n", am);}
	/*
	If true : if only two vertices are selected, they will be merged
	regardless of distance
	*/
	void setAlwaysMergeTwoVertices(const BoolID& am){fprintf_s(mFile,"connectAttr \"");am.write(mFile);fprintf_s(mFile,"\" \"%s.am\";\n",mName.c_str());}
	/*If true : texture is sewn as well as the 3d edge.*/
	void setTexture(bool tx){if(tx == true) return; fprintf_s(mFile, "setAttr \".tx\" %i;\n", tx);}
	/*If true : texture is sewn as well as the 3d edge.*/
	void setTexture(const BoolID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.tx\";\n",mName.c_str());}
	/*
	Tolerance to determine whether vertices (and edges) should
	be merged.
	*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	If true : if only two vertices are selected, they will be merged
	regardless of distance
	*/
	BoolID getAlwaysMergeTwoVertices(){char buffer[4096];sprintf_s (buffer, "%s.am",mName.c_str());return (const char*)buffer;}
	/*If true : texture is sewn as well as the 3d edge.*/
	BoolID getTexture(){char buffer[4096];sprintf_s (buffer, "%s.tx",mName.c_str());return (const char*)buffer;}
protected:
	PolyMergeVert(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMERGEVERT_H__
