/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REBUILDCURVE_H__
#define __MayaDM_REBUILDCURVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Rebuild a curve so that its parameterization and/or control points are
 modified. This may change the shape of the curve. There are five methods
 with which to rebuild the curve (rebuildType).
 <br/>
 <br/>
 uniform- the resulting curve will have uniform parameterization with the
 specified number of spans (spans) and degree (degree).
 <br/>
 <br/>
 reduceSpans- remove redundant knots if possible.
 <br/>
 <br/>
 matchKnots- rebuild the input curve so that it matches the parametrization
 of another curve.
 <br/>
 <br/>
 noMults- remove multiple interior knots.
 <br/>
 <br/>
 curvature- rebuild the input curve adding more knots where the curvature is highest.
 <br/>
 <br/>
 ends - Rebuild the input curve to have multiple or nonmultiple end knots.
 <br/>
 <br/>
 Use keepRange and keepEndpoints to control the end conditions of the rebuilt curve.
 <p/>
*/
class RebuildCurve : public AbstractBaseCreate
{
public:
public:
	RebuildCurve(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "rebuildCurve"){}
	virtual ~RebuildCurve(){}
	/*The curve to rebuild.*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*If rebuildType is matchKnots then use this curve's parameterization.*/
	void setMatchCurve(const NurbsCurveID& mc){fprintf_s(mFile,"connectAttr \"");mc.write(mFile);fprintf_s(mFile,"\" \"%s.mc\";\n",mName.c_str());}
	/*
	If true use the least squares fit rebuild.
	Otherwise use the convert method.
	*/
	void setFitRebuild(bool fr){if(fr == true) return; fprintf_s(mFile, "setAttr \".fr\" %i;\n", fr);}
	/*
	If true use the least squares fit rebuild.
	Otherwise use the convert method.
	*/
	void setFitRebuild(const BoolID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*
	How to rebuild the input curve.
	0 - uniform,
	1 - reduce spans,
	2 - match knots,
	3 - remove multiple knots,
	4 - curvature
	5 - rebuild ends
	6 - clean
	*/
	void setRebuildType(unsigned int rt){if(rt == 0) return; fprintf_s(mFile, "setAttr \".rt\" %i;\n", rt);}
	/*
	How to rebuild the input curve.
	0 - uniform,
	1 - reduce spans,
	2 - match knots,
	3 - remove multiple knots,
	4 - curvature
	5 - rebuild ends
	6 - clean
	*/
	void setRebuildType(const UnsignedintID& rt){fprintf_s(mFile,"connectAttr \"");rt.write(mFile);fprintf_s(mFile,"\" \"%s.rt\";\n",mName.c_str());}
	/*
	The number of spans in resulting curve
	Used only if rebuildType is uniform.
	*/
	void setSpans(int s){if(s == 4) return; fprintf_s(mFile, "setAttr \".s\" %i;\n", s);}
	/*
	The number of spans in resulting curve
	Used only if rebuildType is uniform.
	*/
	void setSpans(const IntID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	The degree of the resulting curve
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegree(unsigned int d){if(d == 3) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	The degree of the resulting curve
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegree(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The tolerance with which to rebuild.*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*The tolerance with which to rebuild.*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*
	End conditions for the curve
	0 - uniform end knots,
	1 - multiple end knots,
	*/
	void setEndKnots(unsigned int end){if(end == 0) return; fprintf_s(mFile, "setAttr \".end\" %i;\n", end);}
	/*
	End conditions for the curve
	0 - uniform end knots,
	1 - multiple end knots,
	*/
	void setEndKnots(const UnsignedintID& end){fprintf_s(mFile,"connectAttr \"");end.write(mFile);fprintf_s(mFile,"\" \"%s.end\";\n",mName.c_str());}
	/*
	Determine the parameterization for the resulting curve.
	0 - reparameterize the resulting curve from 0 to 1,
	1 - keep the original curve parameterization,
	2 - reparameterize the result from 0 to number of spans
	*/
	void setKeepRange(unsigned int kr){if(kr == 1) return; fprintf_s(mFile, "setAttr \".kr\" %i;\n", kr);}
	/*
	Determine the parameterization for the resulting curve.
	0 - reparameterize the resulting curve from 0 to 1,
	1 - keep the original curve parameterization,
	2 - reparameterize the result from 0 to number of spans
	*/
	void setKeepRange(const UnsignedintID& kr){fprintf_s(mFile,"connectAttr \"");kr.write(mFile);fprintf_s(mFile,"\" \"%s.kr\";\n",mName.c_str());}
	/*If true, keep the endpoints the same.*/
	void setKeepEndPoints(bool kep){if(kep == true) return; fprintf_s(mFile, "setAttr \".kep\" %i;\n", kep);}
	/*If true, keep the endpoints the same.*/
	void setKeepEndPoints(const BoolID& kep){fprintf_s(mFile,"connectAttr \"");kep.write(mFile);fprintf_s(mFile,"\" \"%s.kep\";\n",mName.c_str());}
	/*If true, keep the end tangents the same.*/
	void setKeepTangents(bool kt){if(kt == true) return; fprintf_s(mFile, "setAttr \".kt\" %i;\n", kt);}
	/*If true, keep the end tangents the same.*/
	void setKeepTangents(const BoolID& kt){fprintf_s(mFile,"connectAttr \"");kt.write(mFile);fprintf_s(mFile,"\" \"%s.kt\";\n",mName.c_str());}
	/*The rebuilt curve.*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*
	If true, the CVs will remain the same.
	This forces uniform parameterization unless rebuildType is matchKnots.
	*/
	void setKeepControlPoints(bool kcp){if(kcp == false) return; fprintf_s(mFile, "setAttr \".kcp\" %i;\n", kcp);}
	/*
	If true, the CVs will remain the same.
	This forces uniform parameterization unless rebuildType is matchKnots.
	*/
	void setKeepControlPoints(const BoolID& kcp){fprintf_s(mFile,"connectAttr \"");kcp.write(mFile);fprintf_s(mFile,"\" \"%s.kcp\";\n",mName.c_str());}
	/*If true, curve on surface is rebuild in 3D and 2D info is kept*/
	void setSmartSurfaceCurveRebuild(bool scr){if(scr == false) return; fprintf_s(mFile, "setAttr \".scr\" %i;\n", scr);}
	/*If true, curve on surface is rebuild in 3D and 2D info is kept*/
	void setSmartSurfaceCurveRebuild(const BoolID& scr){fprintf_s(mFile,"connectAttr \"");scr.write(mFile);fprintf_s(mFile,"\" \"%s.scr\";\n",mName.c_str());}
	/*The curve to rebuild.*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*If rebuildType is matchKnots then use this curve's parameterization.*/
	NurbsCurveID getMatchCurve(){char buffer[4096];sprintf_s (buffer, "%s.mc",mName.c_str());return (const char*)buffer;}
	/*
	If true use the least squares fit rebuild.
	Otherwise use the convert method.
	*/
	BoolID getFitRebuild(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*
	How to rebuild the input curve.
	0 - uniform,
	1 - reduce spans,
	2 - match knots,
	3 - remove multiple knots,
	4 - curvature
	5 - rebuild ends
	6 - clean
	*/
	UnsignedintID getRebuildType(){char buffer[4096];sprintf_s (buffer, "%s.rt",mName.c_str());return (const char*)buffer;}
	/*
	The number of spans in resulting curve
	Used only if rebuildType is uniform.
	*/
	IntID getSpans(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	The degree of the resulting curve
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	UnsignedintID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The tolerance with which to rebuild.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*
	End conditions for the curve
	0 - uniform end knots,
	1 - multiple end knots,
	*/
	UnsignedintID getEndKnots(){char buffer[4096];sprintf_s (buffer, "%s.end",mName.c_str());return (const char*)buffer;}
	/*
	Determine the parameterization for the resulting curve.
	0 - reparameterize the resulting curve from 0 to 1,
	1 - keep the original curve parameterization,
	2 - reparameterize the result from 0 to number of spans
	*/
	UnsignedintID getKeepRange(){char buffer[4096];sprintf_s (buffer, "%s.kr",mName.c_str());return (const char*)buffer;}
	/*If true, keep the endpoints the same.*/
	BoolID getKeepEndPoints(){char buffer[4096];sprintf_s (buffer, "%s.kep",mName.c_str());return (const char*)buffer;}
	/*If true, keep the end tangents the same.*/
	BoolID getKeepTangents(){char buffer[4096];sprintf_s (buffer, "%s.kt",mName.c_str());return (const char*)buffer;}
	/*The rebuilt curve.*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*
	If true, the CVs will remain the same.
	This forces uniform parameterization unless rebuildType is matchKnots.
	*/
	BoolID getKeepControlPoints(){char buffer[4096];sprintf_s (buffer, "%s.kcp",mName.c_str());return (const char*)buffer;}
	/*If true, curve on surface is rebuild in 3D and 2D info is kept*/
	BoolID getSmartSurfaceCurveRebuild(){char buffer[4096];sprintf_s (buffer, "%s.scr",mName.c_str());return (const char*)buffer;}
protected:
	RebuildCurve(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REBUILDCURVE_H__
