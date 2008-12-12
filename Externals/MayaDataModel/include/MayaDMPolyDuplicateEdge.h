/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYDUPLICATEEDGE_H__
#define __MayaDM_POLYDUPLICATEEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
<p><pre>    This node handles duplicating a set of edges in multiple ways.

</pre></p>
*/
class PolyDuplicateEdge : public PolyModifier
{
public:
public:
	PolyDuplicateEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyDuplicateEdge"){}
	virtual ~PolyDuplicateEdge(){}
	/*
	Weight value controlling the relative positioning of the
	new edges. Range is [0.0, 1.0].
	*/
	void setOffset(float of){if(of == 0.5) return; fprintf_s(mFile, "setAttr \".of\" %f;\n", of);}
	/*
	Weight value controlling the relative positioning of the
	new edges. Range is [0.0, 1.0].
	*/
	void setOffset(const FloatID& of){fprintf_s(mFile,"connectAttr \"");of.write(mFile);fprintf_s(mFile,"\" \"%s.of\";\n",mName.c_str());}
	/*
	Weight value controlling the offset of the start vertex
	of the edgeloop.
	*/
	void setStartVertexOffset(float svo){if(svo == 0.0) return; fprintf_s(mFile, "setAttr \".svo\" %f;\n", svo);}
	/*
	Weight value controlling the offset of the start vertex
	of the edgeloop.
	*/
	void setStartVertexOffset(const FloatID& svo){fprintf_s(mFile,"connectAttr \"");svo.write(mFile);fprintf_s(mFile,"\" \"%s.svo\";\n",mName.c_str());}
	/*
	Weight value controlling the offset of the end vertex
	of the edgeloop.
	*/
	void setEndVertexOffset(float evo){if(evo == 0.0) return; fprintf_s(mFile, "setAttr \".evo\" %f;\n", evo);}
	/*
	Weight value controlling the offset of the end vertex
	of the edgeloop.
	*/
	void setEndVertexOffset(const FloatID& evo){fprintf_s(mFile,"connectAttr \"");evo.write(mFile);fprintf_s(mFile,"\" \"%s.evo\";\n",mName.c_str());}
	/*
	When true, the end edges are deleted
	so the end triangles are converted to quads.
	*/
	void setDeleteEdge(bool de){if(de == true) return; fprintf_s(mFile, "setAttr \".de\" %i;\n", de);}
	/*
	When true, the end edges are deleted
	so the end triangles are converted to quads.
	*/
	void setDeleteEdge(const BoolID& de){fprintf_s(mFile,"connectAttr \"");de.write(mFile);fprintf_s(mFile,"\" \"%s.de\";\n",mName.c_str());}
	/*Angle below which new edges will be smoothed*/
	void setSmoothingAngle(double sma){if(sma == 1) return; fprintf_s(mFile, "setAttr \".sma\" %f;\n", sma);}
	/*Angle below which new edges will be smoothed*/
	void setSmoothingAngle(const DoubleID& sma){fprintf_s(mFile,"connectAttr \"");sma.write(mFile);fprintf_s(mFile,"\" \"%s.sma\";\n",mName.c_str());}
	/*Format: 0 - Absolute, 1 - Relative*/
	void setSplitType(unsigned int stp){if(stp == 1) return; fprintf_s(mFile, "setAttr \".stp\" %i;\n", stp);}
	/*Format: 0 - Absolute, 1 - Relative*/
	void setSplitType(const UnsignedintID& stp){fprintf_s(mFile,"connectAttr \"");stp.write(mFile);fprintf_s(mFile,"\" \"%s.stp\";\n",mName.c_str());}
	/*
	Weight value controlling the relative positioning of the
	new edges. Range is [0.0, 1.0].
	*/
	FloatID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.of",mName.c_str());return (const char*)buffer;}
	/*
	Weight value controlling the offset of the start vertex
	of the edgeloop.
	*/
	FloatID getStartVertexOffset(){char buffer[4096];sprintf_s (buffer, "%s.svo",mName.c_str());return (const char*)buffer;}
	/*
	Weight value controlling the offset of the end vertex
	of the edgeloop.
	*/
	FloatID getEndVertexOffset(){char buffer[4096];sprintf_s (buffer, "%s.evo",mName.c_str());return (const char*)buffer;}
	/*
	When true, the end edges are deleted
	so the end triangles are converted to quads.
	*/
	BoolID getDeleteEdge(){char buffer[4096];sprintf_s (buffer, "%s.de",mName.c_str());return (const char*)buffer;}
	/*Angle below which new edges will be smoothed*/
	DoubleID getSmoothingAngle(){char buffer[4096];sprintf_s (buffer, "%s.sma",mName.c_str());return (const char*)buffer;}
	/*Format: 0 - Absolute, 1 - Relative*/
	UnsignedintID getSplitType(){char buffer[4096];sprintf_s (buffer, "%s.stp",mName.c_str());return (const char*)buffer;}
protected:
	PolyDuplicateEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYDUPLICATEEDGE_H__
