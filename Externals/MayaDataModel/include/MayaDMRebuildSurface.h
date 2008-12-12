/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REBUILDSURFACE_H__
#define __MayaDM_REBUILDSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseNurbsConversion.h"
namespace MayaDM
{
/*
Rebuild the input surface so that its parameterization and/or control points
 are modified. This may change the shape of the surface. The input surface
 can be rebuilt in the u, v, or both directions. There are five methods
 with which to rebuild the surface:
 <br/>
 <br/>
 uniform- rebuild the input surface so that it will have uniform parameterization.
 Use spansU and spansV to specify the number of spans in each direction.
 Use degreeU and degreeV to specify the new surface degree in each direction.
 <br/>
 <br/>
 reduce- rebuild the input surface to reduce the number of spans.
 <br/>
 <br/>
 matchKnots- rebuild the input surface so that its parameterization matches
 that of another surface.
 A second input surface must be specified.
 <br/>
 <br/>
 noMults- remove multiple interior knots.
 <br/>
 <br/>
 non-Rational- Rebuild the input surface so that it no longer rational.
 <br/>
 <br/>
 ends - Rebuild the input surface to have multiple or nonmultiple end knots.
 <br/>
 <br/>
 bezier - Rebuild the input surface to be Bezier mesh
 <br/>
 <br/>
 trim convert - Rebuild the 4 edged trim surface surface into a untrimmed one.
 <br/>
 <br/>
 Use keepCorners, keepRange, and keepControlPoints to gain some control over the
 parameterization and shape of the resulting surface.
 <p/>
*/
class RebuildSurface : public AbstractBaseNurbsConversion
{
public:
public:
	RebuildSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseNurbsConversion(file, name, parent, "rebuildSurface"){}
	virtual ~RebuildSurface(){}
	/*The surface to rebuild*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Use this surface to rebuild the input surface so that the new surface is compatable with this surface*/
	void setMatchSurface(const NurbsSurfaceID& ms){fprintf_s(mFile,"connectAttr \"");ms.write(mFile);fprintf_s(mFile,"\" \"%s.ms\";\n",mName.c_str());}
	/*
	The rebuild type:
	0 - uniform,
	1 - reduce spans,
	2 - match knots,
	3 - remove multiple knots,
	4 - force non rational
	5 - rebuild ends
	6 - trim convert (uniform)
	7 - into Bezier mesh
	*/
	void setRebuildType(unsigned int rt){if(rt == 0) return; fprintf_s(mFile, "setAttr \".rt\" %i;\n", rt);}
	/*
	The rebuild type:
	0 - uniform,
	1 - reduce spans,
	2 - match knots,
	3 - remove multiple knots,
	4 - force non rational
	5 - rebuild ends
	6 - trim convert (uniform)
	7 - into Bezier mesh
	*/
	void setRebuildType(const UnsignedintID& rt){fprintf_s(mFile,"connectAttr \"");rt.write(mFile);fprintf_s(mFile,"\" \"%s.rt\";\n",mName.c_str());}
	/*
	The direction in which to rebuild:
	0 - U,
	1 - V,
	2 - Both U and V
	*/
	void setDirection(unsigned int dir){if(dir == 2) return; fprintf_s(mFile, "setAttr \".dir\" %i;\n", dir);}
	/*
	The direction in which to rebuild:
	0 - U,
	1 - V,
	2 - Both U and V
	*/
	void setDirection(const UnsignedintID& dir){fprintf_s(mFile,"connectAttr \"");dir.write(mFile);fprintf_s(mFile,"\" \"%s.dir\";\n",mName.c_str());}
	/*The number of spans in the u direction in resulting surface. Used only when rebuildType is 0 - uniform. If 0, keep the same number of spans as the original surface.*/
	void setSpansU(int su){if(su == 4) return; fprintf_s(mFile, "setAttr \".su\" %i;\n", su);}
	/*The number of spans in the u direction in resulting surface. Used only when rebuildType is 0 - uniform. If 0, keep the same number of spans as the original surface.*/
	void setSpansU(const IntID& su){fprintf_s(mFile,"connectAttr \"");su.write(mFile);fprintf_s(mFile,"\" \"%s.su\";\n",mName.c_str());}
	/*The number of spans in the v direction in resulting surface. Used only when rebuildType is 0 - uniform. If 0, keep the same number of spans as the original surface.*/
	void setSpansV(int sv){if(sv == 4) return; fprintf_s(mFile, "setAttr \".sv\" %i;\n", sv);}
	/*The number of spans in the v direction in resulting surface. Used only when rebuildType is 0 - uniform. If 0, keep the same number of spans as the original surface.*/
	void setSpansV(const IntID& sv){fprintf_s(mFile,"connectAttr \"");sv.write(mFile);fprintf_s(mFile,"\" \"%s.sv\";\n",mName.c_str());}
	/*
	The degree of the resulting surface in the u direction
	0 - maintain current,
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegreeU(unsigned int du){if(du == 3) return; fprintf_s(mFile, "setAttr \".du\" %i;\n", du);}
	/*
	The degree of the resulting surface in the u direction
	0 - maintain current,
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegreeU(const UnsignedintID& du){fprintf_s(mFile,"connectAttr \"");du.write(mFile);fprintf_s(mFile,"\" \"%s.du\";\n",mName.c_str());}
	/*
	The degree of the resulting surface in the v direction
	0 - maintain current,
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegreeV(unsigned int dv){if(dv == 3) return; fprintf_s(mFile, "setAttr \".dv\" %i;\n", dv);}
	/*
	The degree of the resulting surface in the v direction
	0 - maintain current,
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	void setDegreeV(const UnsignedintID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*The tolerance with which to rebuild*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*The tolerance with which to rebuild*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*
	End conditions for the surface
	0 - uniform end knots,
	1 - multiple end knots,
	*/
	void setEndKnots(unsigned int end){if(end == 0) return; fprintf_s(mFile, "setAttr \".end\" %i;\n", end);}
	/*
	End conditions for the surface
	0 - uniform end knots,
	1 - multiple end knots,
	*/
	void setEndKnots(const UnsignedintID& end){fprintf_s(mFile,"connectAttr \"");end.write(mFile);fprintf_s(mFile,"\" \"%s.end\";\n",mName.c_str());}
	/*The corners of the resulting surface will not change from the corners of the input surface.*/
	void setKeepCorners(bool kc){if(kc == true) return; fprintf_s(mFile, "setAttr \".kc\" %i;\n", kc);}
	/*The corners of the resulting surface will not change from the corners of the input surface.*/
	void setKeepCorners(const BoolID& kc){fprintf_s(mFile,"connectAttr \"");kc.write(mFile);fprintf_s(mFile,"\" \"%s.kc\";\n",mName.c_str());}
	/*
	Determine the parameterization for the resulting surface.
	0 - reparameterize the resulting surface from 0 to 1;
	1 - keep the original surface parameterization;
	2 - reparameterize the result from 0 to number of spans
	*/
	void setKeepRange(unsigned int kr){if(kr == 1) return; fprintf_s(mFile, "setAttr \".kr\" %i;\n", kr);}
	/*
	Determine the parameterization for the resulting surface.
	0 - reparameterize the resulting surface from 0 to 1;
	1 - keep the original surface parameterization;
	2 - reparameterize the result from 0 to number of spans
	*/
	void setKeepRange(const UnsignedintID& kr){fprintf_s(mFile,"connectAttr \"");kr.write(mFile);fprintf_s(mFile,"\" \"%s.kr\";\n",mName.c_str());}
	/*
	Use the control points of the input surface.
	This forces uniform parameterization unless rebuildType is 2 (match knots)
	*/
	void setKeepControlPoints(bool kcp){if(kcp == false) return; fprintf_s(mFile, "setAttr \".kcp\" %i;\n", kcp);}
	/*
	Use the control points of the input surface.
	This forces uniform parameterization unless rebuildType is 2 (match knots)
	*/
	void setKeepControlPoints(const BoolID& kcp){fprintf_s(mFile,"connectAttr \"");kcp.write(mFile);fprintf_s(mFile,"\" \"%s.kcp\";\n",mName.c_str());}
	/*
	Specify the type of rebuild method to be used:
	0 - Convert Classic, the default and original convert method.
	1 - Fit using the least squares fit method.
	2 - Convert Match, alternate matching convert method.
	3 - Convert Grid, uses a grid-based fit algorithm.
	*/
	void setFitRebuild(unsigned int fr){if(fr == 0) return; fprintf_s(mFile, "setAttr \".fr\" %i;\n", fr);}
	/*
	Specify the type of rebuild method to be used:
	0 - Convert Classic, the default and original convert method.
	1 - Fit using the least squares fit method.
	2 - Convert Match, alternate matching convert method.
	3 - Convert Grid, uses a grid-based fit algorithm.
	*/
	void setFitRebuild(const UnsignedintID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*
	If true this will make rebuild Surfaces with convert option
	always rational. Use for backward compatibility.
	*/
	void setOldRebuildRational(bool orr){if(orr == false) return; fprintf_s(mFile, "setAttr \".orr\" %i;\n", orr);}
	/*
	If true this will make rebuild Surfaces with convert option
	always rational. Use for backward compatibility.
	*/
	void setOldRebuildRational(const BoolID& orr){fprintf_s(mFile,"connectAttr \"");orr.write(mFile);fprintf_s(mFile,"\" \"%s.orr\";\n",mName.c_str());}
	/*The rebuilt surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The surface to rebuild*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Use this surface to rebuild the input surface so that the new surface is compatable with this surface*/
	NurbsSurfaceID getMatchSurface(){char buffer[4096];sprintf_s (buffer, "%s.ms",mName.c_str());return (const char*)buffer;}
	/*
	The rebuild type:
	0 - uniform,
	1 - reduce spans,
	2 - match knots,
	3 - remove multiple knots,
	4 - force non rational
	5 - rebuild ends
	6 - trim convert (uniform)
	7 - into Bezier mesh
	*/
	UnsignedintID getRebuildType(){char buffer[4096];sprintf_s (buffer, "%s.rt",mName.c_str());return (const char*)buffer;}
	/*
	The direction in which to rebuild:
	0 - U,
	1 - V,
	2 - Both U and V
	*/
	UnsignedintID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.dir",mName.c_str());return (const char*)buffer;}
	/*The number of spans in the u direction in resulting surface. Used only when rebuildType is 0 - uniform. If 0, keep the same number of spans as the original surface.*/
	IntID getSpansU(){char buffer[4096];sprintf_s (buffer, "%s.su",mName.c_str());return (const char*)buffer;}
	/*The number of spans in the v direction in resulting surface. Used only when rebuildType is 0 - uniform. If 0, keep the same number of spans as the original surface.*/
	IntID getSpansV(){char buffer[4096];sprintf_s (buffer, "%s.sv",mName.c_str());return (const char*)buffer;}
	/*
	The degree of the resulting surface in the u direction
	0 - maintain current,
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	UnsignedintID getDegreeU(){char buffer[4096];sprintf_s (buffer, "%s.du",mName.c_str());return (const char*)buffer;}
	/*
	The degree of the resulting surface in the v direction
	0 - maintain current,
	1 - linear,
	2 - quadratic,
	3 - cubic,
	5 - quintic,
	7 - heptic
	*/
	UnsignedintID getDegreeV(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*The tolerance with which to rebuild*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*
	End conditions for the surface
	0 - uniform end knots,
	1 - multiple end knots,
	*/
	UnsignedintID getEndKnots(){char buffer[4096];sprintf_s (buffer, "%s.end",mName.c_str());return (const char*)buffer;}
	/*The corners of the resulting surface will not change from the corners of the input surface.*/
	BoolID getKeepCorners(){char buffer[4096];sprintf_s (buffer, "%s.kc",mName.c_str());return (const char*)buffer;}
	/*
	Determine the parameterization for the resulting surface.
	0 - reparameterize the resulting surface from 0 to 1;
	1 - keep the original surface parameterization;
	2 - reparameterize the result from 0 to number of spans
	*/
	UnsignedintID getKeepRange(){char buffer[4096];sprintf_s (buffer, "%s.kr",mName.c_str());return (const char*)buffer;}
	/*
	Use the control points of the input surface.
	This forces uniform parameterization unless rebuildType is 2 (match knots)
	*/
	BoolID getKeepControlPoints(){char buffer[4096];sprintf_s (buffer, "%s.kcp",mName.c_str());return (const char*)buffer;}
	/*
	Specify the type of rebuild method to be used:
	0 - Convert Classic, the default and original convert method.
	1 - Fit using the least squares fit method.
	2 - Convert Match, alternate matching convert method.
	3 - Convert Grid, uses a grid-based fit algorithm.
	*/
	UnsignedintID getFitRebuild(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*
	If true this will make rebuild Surfaces with convert option
	always rational. Use for backward compatibility.
	*/
	BoolID getOldRebuildRational(){char buffer[4096];sprintf_s (buffer, "%s.orr",mName.c_str());return (const char*)buffer;}
	/*The rebuilt surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	RebuildSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseNurbsConversion(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REBUILDSURFACE_H__
