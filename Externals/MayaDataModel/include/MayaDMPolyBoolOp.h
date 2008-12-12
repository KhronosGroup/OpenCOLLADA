/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYBOOLOP_H__
#define __MayaDM_POLYBOOLOP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyUnite.h"
namespace MayaDM
{
/*
This node creates a new poly
 by applying a boolean operation on the input polys.
 Unlike the parent node polyUnite, this node only
 functions with exactly two input polys.<p/>
*/
class PolyBoolOp : public PolyUnite
{
public:
public:
	PolyBoolOp(FILE* file,const std::string& name,const std::string& parent=""):PolyUnite(file, name, parent, "polyBoolOp"){}
	virtual ~PolyBoolOp(){}
	/*
	Boolean operation type. 1=union, 2=difference, 3=intersection.
	Default type is union.
	*/
	void setOperation(unsigned int op){if(op == 0) return; fprintf_s(mFile, "setAttr \".op\" %i;\n", op);}
	/*
	Boolean operation type. 1=union, 2=difference, 3=intersection.
	Default type is union.
	*/
	void setOperation(const UnsignedintID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*
	If true, merge vertices with separations less then
	vertexDistanceThreshold and collapse faces with areas
	less then faceAreaThreshold. If false, do not merge
	vertices or collapse faces
	*/
	void setUseThresholds(bool uth){if(uth == false) return; fprintf_s(mFile, "setAttr \".uth\" %i;\n", uth);}
	/*
	If true, merge vertices with separations less then
	vertexDistanceThreshold and collapse faces with areas
	less then faceAreaThreshold. If false, do not merge
	vertices or collapse faces
	*/
	void setUseThresholds(const BoolID& uth){fprintf_s(mFile,"connectAttr \"");uth.write(mFile);fprintf_s(mFile,"\" \"%s.uth\";\n",mName.c_str());}
	/*
	Tolerance to determine whether vertices (and edges) should
	be merged before boolean operation is applied. Attribute is
	ignored unless useThresholds is set to true
	*/
	void setVertexDistanceThreshold(double vdt){if(vdt == 0) return; fprintf_s(mFile, "setAttr \".vdt\" %f;\n", vdt);}
	/*
	Tolerance to determine whether vertices (and edges) should
	be merged before boolean operation is applied. Attribute is
	ignored unless useThresholds is set to true
	*/
	void setVertexDistanceThreshold(const DoubleID& vdt){fprintf_s(mFile,"connectAttr \"");vdt.write(mFile);fprintf_s(mFile,"\" \"%s.vdt\";\n",mName.c_str());}
	/*
	Area threshold to determine whether faces should
	be collapsed before boolean. Attribute is ignored unless
	useThresholds is set to true
	*/
	void setFaceAreaThreshold(double fat){if(fat == 0) return; fprintf_s(mFile, "setAttr \".fat\" %f;\n", fat);}
	/*
	Area threshold to determine whether faces should
	be collapsed before boolean. Attribute is ignored unless
	useThresholds is set to true
	*/
	void setFaceAreaThreshold(const DoubleID& fat){fprintf_s(mFile,"connectAttr \"");fat.write(mFile);fprintf_s(mFile,"\" \"%s.fat\";\n",mName.c_str());}
	/*
	Boolean operation type. 1=union, 2=difference, 3=intersection.
	Default type is union.
	*/
	UnsignedintID getOperation(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*
	If true, merge vertices with separations less then
	vertexDistanceThreshold and collapse faces with areas
	less then faceAreaThreshold. If false, do not merge
	vertices or collapse faces
	*/
	BoolID getUseThresholds(){char buffer[4096];sprintf_s (buffer, "%s.uth",mName.c_str());return (const char*)buffer;}
	/*
	Tolerance to determine whether vertices (and edges) should
	be merged before boolean operation is applied. Attribute is
	ignored unless useThresholds is set to true
	*/
	DoubleID getVertexDistanceThreshold(){char buffer[4096];sprintf_s (buffer, "%s.vdt",mName.c_str());return (const char*)buffer;}
	/*
	Area threshold to determine whether faces should
	be collapsed before boolean. Attribute is ignored unless
	useThresholds is set to true
	*/
	DoubleID getFaceAreaThreshold(){char buffer[4096];sprintf_s (buffer, "%s.fat",mName.c_str());return (const char*)buffer;}
protected:
	PolyBoolOp(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyUnite(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYBOOLOP_H__
