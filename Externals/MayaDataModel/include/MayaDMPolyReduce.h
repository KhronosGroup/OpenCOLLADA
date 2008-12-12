/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYREDUCE_H__
#define __MayaDM_POLYREDUCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
<p><pre> Reduce a poly object using a vertex deletion algorithm.

</pre></p>
*/
class PolyReduce : public PolyModifier
{
public:
public:
	PolyReduce(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyReduce"){}
	virtual ~PolyReduce(){}
	/*Percentage of triangles to be removed.*/
	void setPercentage(double p){if(p == 0) return; fprintf_s(mFile, "setAttr \".p\" %f;\n", p);}
	/*Percentage of triangles to be removed.*/
	void setPercentage(const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*
	Tolerance for compactness for the generated triangles
	A value of 0 will accept all triangles during decimation
	A value close to 0 will attempt to eliminate triangles
	that have collinear edges (zero area triangles)
	A value closer to 1 will attempt to eliminate triangles
	that are not strictly equilateral (of equal lengths)
	The closer to 1.0, the more expensive the computation
	*/
	void setCompactness(double com){if(com == 0.0) return; fprintf_s(mFile, "setAttr \".com\" %f;\n", com);}
	/*
	Tolerance for compactness for the generated triangles
	A value of 0 will accept all triangles during decimation
	A value close to 0 will attempt to eliminate triangles
	that have collinear edges (zero area triangles)
	A value closer to 1 will attempt to eliminate triangles
	that are not strictly equilateral (of equal lengths)
	The closer to 1.0, the more expensive the computation
	*/
	void setCompactness(const DoubleID& com){fprintf_s(mFile,"connectAttr \"");com.write(mFile);fprintf_s(mFile,"\" \"%s.com\";\n",mName.c_str());}
	/*
	How much consideration vertex positions are given in the
	reduction algorithm. A higher weight means the reduction
	will try harder to preserve geometry.
	*/
	void setGeomWeights(double gwt){if(gwt == 1) return; fprintf_s(mFile, "setAttr \".gwt\" %f;\n", gwt);}
	/*
	How much consideration vertex positions are given in the
	reduction algorithm. A higher weight means the reduction
	will try harder to preserve geometry.
	*/
	void setGeomWeights(const DoubleID& gwt){fprintf_s(mFile,"connectAttr \"");gwt.write(mFile);fprintf_s(mFile,"\" \"%s.gwt\";\n",mName.c_str());}
	/*
	How much consideration uv positions are given in the
	reduction algorithm. A higher weight means the
	reduction will try harder to preserve uv positions.
	*/
	void setUvWeights(double uwt){if(uwt == 0) return; fprintf_s(mFile, "setAttr \".uwt\" %f;\n", uwt);}
	/*
	How much consideration uv positions are given in the
	reduction algorithm. A higher weight means the
	reduction will try harder to preserve uv positions.
	*/
	void setUvWeights(const DoubleID& uwt){fprintf_s(mFile,"connectAttr \"");uwt.write(mFile);fprintf_s(mFile,"\" \"%s.uwt\";\n",mName.c_str());}
	/*
	How much consideration vertex color is given in the reduction
	algorithm. A higher weight means the reduction will try
	harder to preserve vertex coloring.
	*/
	void setColorWeights(double cwt){if(cwt == 0) return; fprintf_s(mFile, "setAttr \".cwt\" %f;\n", cwt);}
	/*
	How much consideration vertex color is given in the reduction
	algorithm. A higher weight means the reduction will try
	harder to preserve vertex coloring.
	*/
	void setColorWeights(const DoubleID& cwt){fprintf_s(mFile,"connectAttr \"");cwt.write(mFile);fprintf_s(mFile,"\" \"%s.cwt\";\n",mName.c_str());}
	/*
	How much consideration is given in the reduction
	algorithm to keeping quad faces. A higher weight means
	the reduction will try harder to keep quad faces and
	avoid creation of triangles.
	*/
	void setKeepQuadsWeight(double kqw){if(kqw == 0) return; fprintf_s(mFile, "setAttr \".kqw\" %f;\n", kqw);}
	/*
	How much consideration is given in the reduction
	algorithm to keeping quad faces. A higher weight means
	the reduction will try harder to keep quad faces and
	avoid creation of triangles.
	*/
	void setKeepQuadsWeight(const DoubleID& kqw){fprintf_s(mFile,"connectAttr \"");kqw.write(mFile);fprintf_s(mFile,"\" \"%s.kqw\";\n",mName.c_str());}
	/*
	The weight of each vertex is multiplied with this coefficient
	when the reduction is performed.  This value does not have
	to be edited, normally.  It gives finer control over the
	weighted reduction.
	*/
	void setWeightCoefficient(double wc){if(wc == 10000.0) return; fprintf_s(mFile, "setAttr \".wc\" %f;\n", wc);}
	/*
	The weight of each vertex is multiplied with this coefficient
	when the reduction is performed.  This value does not have
	to be edited, normally.  It gives finer control over the
	weighted reduction.
	*/
	void setWeightCoefficient(const DoubleID& wc){fprintf_s(mFile,"connectAttr \"");wc.write(mFile);fprintf_s(mFile,"\" \"%s.wc\";\n",mName.c_str());}
	/*
	This attribute was used in 6.0 or earlier versions, and is
	not used anymore.  This is an obsolete attribute.
	*/
	void setWeights(size_t wts_i,const DoubleID& wts){fprintf_s(mFile,"connectAttr \"");wts.write(mFile);fprintf_s(mFile,"\" \"%s.wts[%i]\";\n",mName.c_str(),wts_i);}
	/*
	An array containing the weights of all vertices.
	A higher weight means that vertex is less likely to be reduced.
	If not specified, weights are assumed to be 0.
	*/
	void setVertexWeights(const doubleArray& vwt){if(vwt.size == 0) return; fprintf_s(mFile, "setAttr \".vwt\" -type \"doubleArray\" ");vwt.write(mFile);fprintf_s(mFile,";\n");}
	/*
	An array containing the weights of all vertices.
	A higher weight means that vertex is less likely to be reduced.
	If not specified, weights are assumed to be 0.
	*/
	void setVertexWeights(const DoubleArrayID& vwt){fprintf_s(mFile,"connectAttr \"");vwt.write(mFile);fprintf_s(mFile,"\" \"%s.vwt\";\n",mName.c_str());}
	/*Keep the object borders*/
	void setKeepBorder(bool kb){if(kb == true) return; fprintf_s(mFile, "setAttr \".kb\" %i;\n", kb);}
	/*Keep the object borders*/
	void setKeepBorder(const BoolID& kb){fprintf_s(mFile,"connectAttr \"");kb.write(mFile);fprintf_s(mFile,"\" \"%s.kb\";\n",mName.c_str());}
	/*Keep the object texture mapping borders*/
	void setKeepMapBorder(bool kmb){if(kmb == true) return; fprintf_s(mFile, "setAttr \".kmb\" %i;\n", kmb);}
	/*Keep the object texture mapping borders*/
	void setKeepMapBorder(const BoolID& kmb){fprintf_s(mFile,"connectAttr \"");kmb.write(mFile);fprintf_s(mFile,"\" \"%s.kmb\";\n",mName.c_str());}
	/*Keep the hard edges on the object*/
	void setKeepHardEdge(bool khe){if(khe == true) return; fprintf_s(mFile, "setAttr \".khe\" %i;\n", khe);}
	/*Keep the hard edges on the object*/
	void setKeepHardEdge(const BoolID& khe){fprintf_s(mFile,"connectAttr \"");khe.write(mFile);fprintf_s(mFile,"\" \"%s.khe\";\n",mName.c_str());}
	/*
	Keep original positions, UVs and colors of vertices when collapsing edges.
	If false, new vertices will be positioned to give optimal shape
	If true, the vertex closest to the optimal position will be preserved
	*/
	void setKeepOriginalVertices(bool kev){if(kev == false) return; fprintf_s(mFile, "setAttr \".kev\" %i;\n", kev);}
	/*
	Keep original positions, UVs and colors of vertices when collapsing edges.
	If false, new vertices will be positioned to give optimal shape
	If true, the vertex closest to the optimal position will be preserved
	*/
	void setKeepOriginalVertices(const BoolID& kev){fprintf_s(mFile,"connectAttr \"");kev.write(mFile);fprintf_s(mFile,"\" \"%s.kev\";\n",mName.c_str());}
	/*
	Triangulate all faces, included non reduced ones (for pre 5.0 files)
	For version 5.0, this attribute specifies if the geometry
	or the selected faces has to be triangulated,
	before performing reduction.
	*/
	void setTriangulate(bool t){if(t == true) return; fprintf_s(mFile, "setAttr \".t\" %i;\n", t);}
	/*
	Triangulate all faces, included non reduced ones (for pre 5.0 files)
	For version 5.0, this attribute specifies if the geometry
	or the selected faces has to be triangulated,
	before performing reduction.
	*/
	void setTriangulate(const BoolID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*Cache intermediate reductions for speed at the expense of memory*/
	void setCachingReduce(bool cr){if(cr == false) return; fprintf_s(mFile, "setAttr \".cr\" %i;\n", cr);}
	/*Cache intermediate reductions for speed at the expense of memory*/
	void setCachingReduce(const BoolID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*
	Specifies the degree to which vertices along the geometric border
	are to be preserved. It has effect only if the keepBorder attribute
	is set to false.
	A value of 0 results in all border vertices being preserved.
	A value of 1.0 results in no special effort being
	made to preserve any border vertices.
	*/
	void setBorder(double b){if(b == .5) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*
	Specifies the degree to which vertices along the geometric border
	are to be preserved. It has effect only if the keepBorder attribute
	is set to false.
	A value of 0 results in all border vertices being preserved.
	A value of 1.0 results in no special effort being
	made to preserve any border vertices.
	*/
	void setBorder(const DoubleID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*
	Specifies the degree to which "feature lines" (edges joining faces
	with sharp geometric angles between them) are to be
	preserved.
	A value of 0 results in the greatest possible effort to preserve
	such features.
	A value of 1.0 results in no special effort being made
	to preserve such features.
	*/
	void setLine(double l){if(l == .5) return; fprintf_s(mFile, "setAttr \".l\" %f;\n", l);}
	/*
	Specifies the degree to which "feature lines" (edges joining faces
	with sharp geometric angles between them) are to be
	preserved.
	A value of 0 results in the greatest possible effort to preserve
	such features.
	A value of 1.0 results in no special effort being made
	to preserve such features.
	*/
	void setLine(const DoubleID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	Specifies how much of the reduced geometry should be
	dedicated to preserving regions of high curvature.
	A value of 0 will concentrate the detail in areas of high curvature.
	A value of 1.0 will result in relatively equal distribution of
	vertices and faces regardless of curvature.
	This value is ignored when keepHardEdge is set to false.
	*/
	void setDetail(double d){if(d == .5) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*
	Specifies how much of the reduced geometry should be
	dedicated to preserving regions of high curvature.
	A value of 0 will concentrate the detail in areas of high curvature.
	A value of 1.0 will result in relatively equal distribution of
	vertices and faces regardless of curvature.
	This value is ignored when keepHardEdge is set to false.
	*/
	void setDetail(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Percentage of triangles to be removed.*/
	DoubleID getPercentage(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*
	Tolerance for compactness for the generated triangles
	A value of 0 will accept all triangles during decimation
	A value close to 0 will attempt to eliminate triangles
	that have collinear edges (zero area triangles)
	A value closer to 1 will attempt to eliminate triangles
	that are not strictly equilateral (of equal lengths)
	The closer to 1.0, the more expensive the computation
	*/
	DoubleID getCompactness(){char buffer[4096];sprintf_s (buffer, "%s.com",mName.c_str());return (const char*)buffer;}
	/*
	How much consideration vertex positions are given in the
	reduction algorithm. A higher weight means the reduction
	will try harder to preserve geometry.
	*/
	DoubleID getGeomWeights(){char buffer[4096];sprintf_s (buffer, "%s.gwt",mName.c_str());return (const char*)buffer;}
	/*
	How much consideration uv positions are given in the
	reduction algorithm. A higher weight means the
	reduction will try harder to preserve uv positions.
	*/
	DoubleID getUvWeights(){char buffer[4096];sprintf_s (buffer, "%s.uwt",mName.c_str());return (const char*)buffer;}
	/*
	How much consideration vertex color is given in the reduction
	algorithm. A higher weight means the reduction will try
	harder to preserve vertex coloring.
	*/
	DoubleID getColorWeights(){char buffer[4096];sprintf_s (buffer, "%s.cwt",mName.c_str());return (const char*)buffer;}
	/*
	How much consideration is given in the reduction
	algorithm to keeping quad faces. A higher weight means
	the reduction will try harder to keep quad faces and
	avoid creation of triangles.
	*/
	DoubleID getKeepQuadsWeight(){char buffer[4096];sprintf_s (buffer, "%s.kqw",mName.c_str());return (const char*)buffer;}
	/*
	The weight of each vertex is multiplied with this coefficient
	when the reduction is performed.  This value does not have
	to be edited, normally.  It gives finer control over the
	weighted reduction.
	*/
	DoubleID getWeightCoefficient(){char buffer[4096];sprintf_s (buffer, "%s.wc",mName.c_str());return (const char*)buffer;}
	/*
	This attribute was used in 6.0 or earlier versions, and is
	not used anymore.  This is an obsolete attribute.
	*/
	const DoubleID& getWeights(size_t wts_i){char buffer[4096];sprintf_s (buffer, "%s.wts[%i]",mName.c_str(),wts_i);return (const char*)buffer;}
	/*
	An array containing the weights of all vertices.
	A higher weight means that vertex is less likely to be reduced.
	If not specified, weights are assumed to be 0.
	*/
	DoubleArrayID getVertexWeights(){char buffer[4096];sprintf_s (buffer, "%s.vwt",mName.c_str());return (const char*)buffer;}
	/*Keep the object borders*/
	BoolID getKeepBorder(){char buffer[4096];sprintf_s (buffer, "%s.kb",mName.c_str());return (const char*)buffer;}
	/*Keep the object texture mapping borders*/
	BoolID getKeepMapBorder(){char buffer[4096];sprintf_s (buffer, "%s.kmb",mName.c_str());return (const char*)buffer;}
	/*Keep the hard edges on the object*/
	BoolID getKeepHardEdge(){char buffer[4096];sprintf_s (buffer, "%s.khe",mName.c_str());return (const char*)buffer;}
	/*
	Keep original positions, UVs and colors of vertices when collapsing edges.
	If false, new vertices will be positioned to give optimal shape
	If true, the vertex closest to the optimal position will be preserved
	*/
	BoolID getKeepOriginalVertices(){char buffer[4096];sprintf_s (buffer, "%s.kev",mName.c_str());return (const char*)buffer;}
	/*
	Triangulate all faces, included non reduced ones (for pre 5.0 files)
	For version 5.0, this attribute specifies if the geometry
	or the selected faces has to be triangulated,
	before performing reduction.
	*/
	BoolID getTriangulate(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*Cache intermediate reductions for speed at the expense of memory*/
	BoolID getCachingReduce(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the degree to which vertices along the geometric border
	are to be preserved. It has effect only if the keepBorder attribute
	is set to false.
	A value of 0 results in all border vertices being preserved.
	A value of 1.0 results in no special effort being
	made to preserve any border vertices.
	*/
	DoubleID getBorder(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the degree to which "feature lines" (edges joining faces
	with sharp geometric angles between them) are to be
	preserved.
	A value of 0 results in the greatest possible effort to preserve
	such features.
	A value of 1.0 results in no special effort being made
	to preserve such features.
	*/
	DoubleID getLine(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	Specifies how much of the reduced geometry should be
	dedicated to preserving regions of high curvature.
	A value of 0 will concentrate the detail in areas of high curvature.
	A value of 1.0 will result in relatively equal distribution of
	vertices and faces regardless of curvature.
	This value is ignored when keepHardEdge is set to false.
	*/
	DoubleID getDetail(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
protected:
	PolyReduce(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYREDUCE_H__
