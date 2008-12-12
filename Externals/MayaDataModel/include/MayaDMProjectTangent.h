/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PROJECTTANGENT_H__
#define __MayaDM_PROJECTTANGENT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Computes the curve which is tangent to two other curves or a surface. Only
 an end point of the input curve (inputCurveToProject) will be
 modified/aligned for tangent continuity. If using two other curves
 (inputCurve1ToProjectTo and inputCurve2ToProjectTo), then the two curves
 must intersect and an end point of the curve to align must meet at that
 intersection point. If using a surface (inputSurfaceToProjectTo), then an
 end point of the curve to align must be on the surface. If curvature
 continuity is true (curvature) then curvatureScale can be used. The
 tangentScale and rotate values are always available to adjust the tangent
 of the aligned curve. The tangentDirection type defines which tangent to
 use: the u direction of the surface or the first curve, the v direction of
 the surface or the second curve, the normal on the surface or at
 intersection of two other input curves. At any time the inverse tangent
 direction can be used by setting reverseTangent to true.
 <p/>
*/
class ProjectTangent : public AbstractBaseCreate
{
public:
public:
	ProjectTangent(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "projectTangent"){}
	virtual ~ProjectTangent(){}
	/*The input curve that will be aligned.*/
	void setInputCurveToProject(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*The first input curve used for the align.*/
	void setInputCurve1ToProjectTo(const NurbsCurveID& ic1){fprintf_s(mFile,"connectAttr \"");ic1.write(mFile);fprintf_s(mFile,"\" \"%s.ic1\";\n",mName.c_str());}
	/*The second input curve used for the align.*/
	void setInputCurve2ToProjectTo(const NurbsCurveID& ic2){fprintf_s(mFile,"connectAttr \"");ic2.write(mFile);fprintf_s(mFile,"\" \"%s.ic2\";\n",mName.c_str());}
	/*Input surface used for the align.*/
	void setInputSurfaceToProjectTo(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Output aligned curve.*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Tangent scale applied to tangent of curve to align.*/
	void setTangentScale(double ts){if(ts == 1) return; fprintf_s(mFile, "setAttr \".ts\" %f;\n", ts);}
	/*Tangent scale applied to tangent of curve to align.*/
	void setTangentScale(const DoubleID& ts){fprintf_s(mFile,"connectAttr \"");ts.write(mFile);fprintf_s(mFile,"\" \"%s.ts\";\n",mName.c_str());}
	/*Curvature scale applied to curvature of curve to align. Available if curvature option is true.*/
	void setCurvatureScale(double cs){if(cs == 0) return; fprintf_s(mFile, "setAttr \".cs\" %f;\n", cs);}
	/*Curvature scale applied to curvature of curve to align. Available if curvature option is true.*/
	void setCurvatureScale(const DoubleID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs\";\n",mName.c_str());}
	/*Amount by which the tangent of the curve to align will be rotated. Available only if the normal direction (3) is not used for tangentDirection.*/
	void setRotate(double ro){if(ro == 0) return; fprintf_s(mFile, "setAttr \".ro\" %f;\n", ro);}
	/*Amount by which the tangent of the curve to align will be rotated. Available only if the normal direction (3) is not used for tangentDirection.*/
	void setRotate(const DoubleID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*Tangent align direction type legal values: 1=u direction (of surface or use first curve), 2=v direction (of surface or use second curve), 3=normal direction (at point of intersection).*/
	void setTangentDirection(unsigned int td){if(td == 1) return; fprintf_s(mFile, "setAttr \".td\" %i;\n", td);}
	/*Tangent align direction type legal values: 1=u direction (of surface or use first curve), 2=v direction (of surface or use second curve), 3=normal direction (at point of intersection).*/
	void setTangentDirection(const UnsignedintID& td){fprintf_s(mFile,"connectAttr \"");td.write(mFile);fprintf_s(mFile,"\" \"%s.td\";\n",mName.c_str());}
	/*Curvature continuity is on if true and off otherwise.*/
	void setCurvature(bool c){if(c == false) return; fprintf_s(mFile, "setAttr \".c\" %i;\n", c);}
	/*Curvature continuity is on if true and off otherwise.*/
	void setCurvature(const BoolID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*Reverse the tangent direction if true and leave it the way it is if false.*/
	void setReverseTangent(bool rt){if(rt == false) return; fprintf_s(mFile, "setAttr \".rt\" %i;\n", rt);}
	/*Reverse the tangent direction if true and leave it the way it is if false.*/
	void setReverseTangent(const BoolID& rt){fprintf_s(mFile,"connectAttr \"");rt.write(mFile);fprintf_s(mFile,"\" \"%s.rt\";\n",mName.c_str());}
	/*If false, use the tangents of the trim edge curves if the surface is trimmed. If true, use the tangents of the underlying surface in the U/V directions.*/
	void setIgnoreEdges(bool ie){if(ie == false) return; fprintf_s(mFile, "setAttr \".ie\" %i;\n", ie);}
	/*If false, use the tangents of the trim edge curves if the surface is trimmed. If true, use the tangents of the underlying surface in the U/V directions.*/
	void setIgnoreEdges(const BoolID& ie){fprintf_s(mFile,"connectAttr \"");ie.write(mFile);fprintf_s(mFile,"\" \"%s.ie\";\n",mName.c_str());}
	/*The input curve that will be aligned.*/
	NurbsCurveID getInputCurveToProject(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*The first input curve used for the align.*/
	NurbsCurveID getInputCurve1ToProjectTo(){char buffer[4096];sprintf_s (buffer, "%s.ic1",mName.c_str());return (const char*)buffer;}
	/*The second input curve used for the align.*/
	NurbsCurveID getInputCurve2ToProjectTo(){char buffer[4096];sprintf_s (buffer, "%s.ic2",mName.c_str());return (const char*)buffer;}
	/*Input surface used for the align.*/
	NurbsSurfaceID getInputSurfaceToProjectTo(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Output aligned curve.*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Tangent scale applied to tangent of curve to align.*/
	DoubleID getTangentScale(){char buffer[4096];sprintf_s (buffer, "%s.ts",mName.c_str());return (const char*)buffer;}
	/*Curvature scale applied to curvature of curve to align. Available if curvature option is true.*/
	DoubleID getCurvatureScale(){char buffer[4096];sprintf_s (buffer, "%s.cs",mName.c_str());return (const char*)buffer;}
	/*Amount by which the tangent of the curve to align will be rotated. Available only if the normal direction (3) is not used for tangentDirection.*/
	DoubleID getRotate(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*Tangent align direction type legal values: 1=u direction (of surface or use first curve), 2=v direction (of surface or use second curve), 3=normal direction (at point of intersection).*/
	UnsignedintID getTangentDirection(){char buffer[4096];sprintf_s (buffer, "%s.td",mName.c_str());return (const char*)buffer;}
	/*Curvature continuity is on if true and off otherwise.*/
	BoolID getCurvature(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*Reverse the tangent direction if true and leave it the way it is if false.*/
	BoolID getReverseTangent(){char buffer[4096];sprintf_s (buffer, "%s.rt",mName.c_str());return (const char*)buffer;}
	/*If false, use the tangents of the trim edge curves if the surface is trimmed. If true, use the tangents of the underlying surface in the U/V directions.*/
	BoolID getIgnoreEdges(){char buffer[4096];sprintf_s (buffer, "%s.ie",mName.c_str());return (const char*)buffer;}
protected:
	ProjectTangent(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PROJECTTANGENT_H__
