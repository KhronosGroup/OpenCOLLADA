/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VECTORRENDERGLOBALS_H__
#define __MayaDM_VECTORRENDERGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    Node used to store global vector render attributes. By using
    a node, these attributes will be read/written to file. There
    should only be one of these nodes.
</pre></p>
*/
class VectorRenderGlobals : public DependNode
{
public:
public:
	VectorRenderGlobals(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "vectorRenderGlobals"){}
	virtual ~VectorRenderGlobals(){}
	/*Render the current frame only*/
	void setCurrentFrame(bool cf){if(cf == false) return; fprintf_s(mFile, "setAttr \".cf\" %i;\n", cf);}
	/*The frame rate*/
	void setFrameRate(int fr){if(fr == 12) return; fprintf_s(mFile, "setAttr \".fr\" %i;\n", fr);}
	/*The SVG animation option*/
	void setSvgAnimation(unsigned int sa){if(sa == 0) return; fprintf_s(mFile, "setAttr \".sa\" %i;\n", sa);}
	/*The SVG compression option*/
	void setSvgCompression(bool sc){if(sc == false) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*The flash version*/
	void setFlashVersion(unsigned int fv){if(fv == 2) return; fprintf_s(mFile, "setAttr \".fv\" %i;\n", fv);}
	/*The browser preview option*/
	void setBrowserView(bool bv){if(bv == false) return; fprintf_s(mFile, "setAttr \".bv\" %i;\n", bv);}
	/*The show back faces option*/
	void setShowBackFaces(bool sb){if(sb == true) return; fprintf_s(mFile, "setAttr \".sb\" %i;\n", sb);}
	/*The draw shadows option*/
	void setShadows(bool sh){if(sh == false) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*The draw highlights option*/
	void setHighlights(bool hi){if(hi == false) return; fprintf_s(mFile, "setAttr \".hi\" %i;\n", hi);}
	/*The highlight level option*/
	void setHighlightLevel(short hl){if(hl == 4) return; fprintf_s(mFile, "setAttr \".hl\" %i;\n", hl);}
	/*The draw reflections option*/
	void setReflections(bool rf){if(rf == false) return; fprintf_s(mFile, "setAttr \".rf\" %i;\n", rf);}
	/*The reflection depth option*/
	void setReflectionDepth(short rd){if(rd == 2) return; fprintf_s(mFile, "setAttr \".rd\" %i;\n", rd);}
	/*The combine fills and edges option*/
	void setCombineFillsEdges(bool cfe){if(cfe == false) return; fprintf_s(mFile, "setAttr \".cfe\" %i;\n", cfe);}
	/*
	The curve tolerance (range: 0.0 - 15.0) - it is a relative tolerance
	used when trying to fit the curve to a series of line segments.
	If 0.0 straight lines will be drawn, if 15.0, aggressive fitting
	will be applied.
	*/
	void setCurveTolerance(double ct){if(ct == 7.5) return; fprintf_s(mFile, "setAttr \".ct\" %f;\n", ct);}
	/*
	Occasionally the first pass at curve fitting does not fit all
	line segments that can be converted to curves. The secondary
	curve fitting code is a higher level curve fitting algorithm
	that can often times find more curves than the first pass
	algorithm.
	*/
	void setSecondaryCF(bool scf){if(scf == false) return; fprintf_s(mFile, "setAttr \".scf\" %i;\n", scf);}
	/*
	Detail Level - (range: 0 - 50 ) - how much detail we want to
	obtain from the scene. The smaller the "detail level" the more
	polygons maybe combined to produce smaller files.
	*/
	void setDetailLevel(short dl){if(dl == 0) return; fprintf_s(mFile, "setAttr \".dl\" %i;\n", dl);}
	/*The include edge option*/
	void setIncludeEdges(bool ie){if(ie == false) return; fprintf_s(mFile, "setAttr \".ie\" %i;\n", ie);}
	/*Frame optimization.*/
	void setRenderOptimization(const string& rno){if(rno == "Safe") return; fprintf_s(mFile, "setAttr \".rno\" -type \"string\" ");rno.write(mFile);fprintf_s(mFile,";\n");}
	/*The fill object (include fills) option*/
	void setFillObjects(bool fo){if(fo == true) return; fprintf_s(mFile, "setAttr \".fo\" %i;\n", fo);}
	/*The fill style option*/
	void setFillStyle(unsigned int fs){if(fs == 0) return; fprintf_s(mFile, "setAttr \".fs\" %i;\n", fs);}
	/*The edge style option*/
	void setEdgeStyle(unsigned int es){if(es == 0) return; fprintf_s(mFile, "setAttr \".es\" %i;\n", es);}
	/*The hidden edges option*/
	void setHiddenEdges(bool he){if(he == false) return; fprintf_s(mFile, "setAttr \".he\" %i;\n", he);}
	/*The edge detail option*/
	void setEdgeDetail(bool ed){if(ed == false) return; fprintf_s(mFile, "setAttr \".ed\" %i;\n", ed);}
	/*Specifies that edges should be drawn when two polygons intersect.*/
	void setOutlinesAtIntersections(bool oai){if(oai == true) return; fprintf_s(mFile, "setAttr \".oai\" %i;\n", oai);}
	/*
	Minimum Edge Angle (range: 1.0 - 90.0) - the edge detail angle is a the
	minimum angle between adjacent polygon face normals that is used to
	determine if an edge is hard and therefore visible.
	*/
	void setMinEdgeAngle(double mea){if(mea == 90.0) return; fprintf_s(mFile, "setAttr \".mea\" %f;\n", mea);}
	/*The edge color*/
	void setEdgeColor(const float3& ec){fprintf_s(mFile, "setAttr \".ec\" -type \"float3\" ");ec.write(mFile);fprintf_s(mFile,";\n");}
	/*The edge color red component (see edgeColor)*/
	void setEdgeColorR(float ecr){if(ecr == 0) return; fprintf_s(mFile, "setAttr \".ec.ecr\" %f;\n", ecr);}
	/*The edge color green component (see edgeColor)*/
	void setEdgeColorG(float ecg){if(ecg == 0) return; fprintf_s(mFile, "setAttr \".ec.ecg\" %f;\n", ecg);}
	/*The edge color blue component (see edgeColor)*/
	void setEdgeColorB(float ecb){if(ecb == 0) return; fprintf_s(mFile, "setAttr \".ec.ecb\" %f;\n", ecb);}
	/*
	The edge weight - specifies the edge weight to be used for all edges. It is
	specified in points (there are 72 points per inch).  The value of 0.0
	specifies hairline edge weight
	*/
	void setEdgeWeight(double ew){if(ew == 0.0) return; fprintf_s(mFile, "setAttr \".ew\" %f;\n", ew);}
	/*Unused any more, this attribute is only define for backward compatibility reasons*/
	void setImageNamePrefix(const StringID& inp){fprintf_s(mFile,"connectAttr \"");inp.write(mFile);fprintf_s(mFile,"\" \"%s.inp\";\n",mName.c_str());}
	/*Unused any more, this attribute is only define for backward compatibility reasons*/
	void setImageFormat(const IntID& if_){fprintf_s(mFile,"connectAttr \"");if_.write(mFile);fprintf_s(mFile,"\" \"%s.if\";\n",mName.c_str());}
	/*Unused any more, this attribute is only define for backward compatibility reasons*/
	void setPixelAspectRatio(const DoubleID& par){fprintf_s(mFile,"connectAttr \"");par.write(mFile);fprintf_s(mFile,"\" \"%s.par\";\n",mName.c_str());}
	/*Unused any more, this attribute is only define for backward compatibility reasons*/
	void setFilenameFormat(const IntID& ff){fprintf_s(mFile,"connectAttr \"");ff.write(mFile);fprintf_s(mFile,"\" \"%s.ff\";\n",mName.c_str());}
	/*Unused any more, this attribute is only define for backward compatibility reasons*/
	StringID getImageNamePrefix(){char buffer[4096];sprintf_s (buffer, "%s.inp",mName.c_str());return (const char*)buffer;}
	/*Unused any more, this attribute is only define for backward compatibility reasons*/
	IntID getImageFormat(){char buffer[4096];sprintf_s (buffer, "%s.if",mName.c_str());return (const char*)buffer;}
	/*Unused any more, this attribute is only define for backward compatibility reasons*/
	DoubleID getPixelAspectRatio(){char buffer[4096];sprintf_s (buffer, "%s.par",mName.c_str());return (const char*)buffer;}
	/*Unused any more, this attribute is only define for backward compatibility reasons*/
	IntID getFilenameFormat(){char buffer[4096];sprintf_s (buffer, "%s.ff",mName.c_str());return (const char*)buffer;}
protected:
	VectorRenderGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_VECTORRENDERGLOBALS_H__
