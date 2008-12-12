/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SOFTMOD_H__
#define __MayaDM_SOFTMOD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
/*
<p><pre>
 Description:

    The softMod node deforms one or more geometries by transforming them
    based on the falloffCurve attribute.  The falloffRadius determines which
    points will be deformed by the softMod, and the falloffCenter
    determines the center of the falloffRadius sphere.

  The accuracy of the deformation is controlled by the percentResolution
  attribute.

  The envelope attribute can be used to globally attenuate the amount of deformation.

</pre></p>
*/
class SoftMod : public WeightGeometryFilter
{
public:
	/*the bundled softMod transforms*/
	struct SoftModXforms{
		void write(FILE* file) const
		{
		}
	};
	/*Define the falloff of the soft select by manipulating this ramp attribute*/
	struct FalloffCurve{
		float falloffCurve_Position;
		float falloffCurve_FloatValue;
		unsigned int falloffCurve_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", falloffCurve_Position);
			fprintf_s(file,"%f ", falloffCurve_FloatValue);
			fprintf_s(file,"%i", falloffCurve_Interp);
		}
	};
public:
	SoftMod(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "softMod"){}
	virtual ~SoftMod(){}
	/*resolution by which softMod percents can differ without being lumped together as a single percentage for efficiency*/
	void setPercentResolution(float ptr){if(ptr == 5) return; fprintf_s(mFile, "setAttr \".ptr\" %f;\n", ptr);}
	/*whether or not to use the partial resolution*/
	void setUsePartialResolution(unsigned int upr){if(upr == 0) return; fprintf_s(mFile, "setAttr \".upr\" %i;\n", upr);}
	/*whether or not to use the partial resolution*/
	void setUsePartialResolution(const UnsignedintID& upr){fprintf_s(mFile,"connectAttr \"");upr.write(mFile);fprintf_s(mFile,"\" \"%s.upr\";\n",mName.c_str());}
	/*relative => only use weighted node i.e. no pre, post matrix*/
	void setRelative(bool rel){if(rel == false) return; fprintf_s(mFile, "setAttr \".rel\" %i;\n", rel);}
	/*relative => only use weighted node i.e. no pre, post matrix*/
	void setRelative(const BoolID& rel){fprintf_s(mFile,"connectAttr \"");rel.write(mFile);fprintf_s(mFile,"\" \"%s.rel\";\n",mName.c_str());}
	/*the bundled softMod transforms*/
	void setSoftModXforms(const SoftModXformsID& x){fprintf_s(mFile,"connectAttr \"");x.write(mFile);fprintf_s(mFile,"\" \"%s.x\";\n",mName.c_str());}
	/*worldSpace matrix above softMod weighted matrix*/
	void setPreMatrix(const MatrixID& pre){fprintf_s(mFile,"connectAttr \"");pre.write(mFile);fprintf_s(mFile,"\" \"%s.x.pre\";\n",mName.c_str());}
	/*softMod weighted matrix*/
	void setWeightedMatrix(const MatrixID& wt){fprintf_s(mFile,"connectAttr \"");wt.write(mFile);fprintf_s(mFile,"\" \"%s.x.wt\";\n",mName.c_str());}
	/*worldSpace matrix below softMod weighted matrix*/
	void setPostMatrix(const MatrixID& post){fprintf_s(mFile,"connectAttr \"");post.write(mFile);fprintf_s(mFile,"\" \"%s.x.post\";\n",mName.c_str());}
	/*softMod weighted matrix compensation*/
	void setWeightedCompensationMatrix(const matrix& wcm){if(wcm == identity) return; fprintf_s(mFile, "setAttr \".wcm\" -type \"matrix\" ");wcm.write(mFile);fprintf_s(mFile,";\n");}
	/*softMod weighted matrix compensation*/
	void setWeightedCompensationMatrix(const MatrixID& wcm){fprintf_s(mFile,"connectAttr \"");wcm.write(mFile);fprintf_s(mFile,"\" \"%s.wcm\";\n",mName.c_str());}
	/*Matrix to set account for the geom matrix at softMod creation time.*/
	void setGeomMatrix(size_t gm_i,const matrix& gm){if(gm == identity) return; fprintf_s(mFile, "setAttr \".gm[%i]\" -type \"matrix\" ",gm_i);gm.write(mFile);fprintf_s(mFile,";\n");}
	/*Matrix to set account for the geom matrix at softMod creation time.*/
	void setGeomMatrix(size_t gm_i,const MatrixID& gm){fprintf_s(mFile,"connectAttr \"");gm.write(mFile);fprintf_s(mFile,"\" \"%s.gm[%i]\";\n",mName.c_str(),gm_i);}
	/*transform that we will rigidly deform by when all percentages are at one*/
	void setMatrix(const matrix& ma){if(ma == identity) return; fprintf_s(mFile, "setAttr \".ma\" -type \"matrix\" ");ma.write(mFile);fprintf_s(mFile,";\n");}
	/*transform that we will rigidly deform by when all percentages are at one*/
	void setMatrix(const MatrixID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma\";\n",mName.c_str());}
	/*compensation matrix used when we rigidly deform the geometry*/
	void setBindPreMatrix(const matrix& pm){if(pm == identity) return; fprintf_s(mFile, "setAttr \".pm\" -type \"matrix\" ");pm.write(mFile);fprintf_s(mFile,";\n");}
	/*compensation matrix used when we rigidly deform the geometry*/
	void setBindPreMatrix(const MatrixID& pm){fprintf_s(mFile,"connectAttr \"");pm.write(mFile);fprintf_s(mFile,"\" \"%s.pm\";\n",mName.c_str());}
	/*Define the falloff of the soft select by manipulating this ramp attribute*/
	void setFalloffCurve(size_t fc_i,const FalloffCurve& fc){fprintf_s(mFile, "setAttr \".fc[%i]\" ",fc_i);fc.write(mFile);fprintf_s(mFile,";\n");}
	/*Define the falloff of the soft select by manipulating this ramp attribute*/
	void setFalloffCurve(size_t fc_i,const FalloffCurveID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i]\";\n",mName.c_str(),fc_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setFalloffCurve_Position(size_t fc_i,float fcp){if(fcp == 0.0) return; fprintf_s(mFile, "setAttr \".fc[%i].fcp\" %f;\n", fc_i,fcp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setFalloffCurve_Position(size_t fc_i,const FloatID& fcp){fprintf_s(mFile,"connectAttr \"");fcp.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i].fcp\";\n",mName.c_str(),fc_i);}
	/*Ramp value at the sibling position*/
	void setFalloffCurve_FloatValue(size_t fc_i,float fcfv){if(fcfv == 0.0) return; fprintf_s(mFile, "setAttr \".fc[%i].fcfv\" %f;\n", fc_i,fcfv);}
	/*Ramp value at the sibling position*/
	void setFalloffCurve_FloatValue(size_t fc_i,const FloatID& fcfv){fprintf_s(mFile,"connectAttr \"");fcfv.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i].fcfv\";\n",mName.c_str(),fc_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setFalloffCurve_Interp(size_t fc_i,unsigned int fci){if(fci == 0) return; fprintf_s(mFile, "setAttr \".fc[%i].fci\" %i;\n", fc_i,fci);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setFalloffCurve_Interp(size_t fc_i,const UnsignedintID& fci){fprintf_s(mFile,"connectAttr \"");fci.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i].fci\";\n",mName.c_str(),fc_i);}
	/*
	Point will only be deformed if they are within the falloff radius about
	the falloff center.
	*/
	void setFalloffRadius(double fr){if(fr == 5) return; fprintf_s(mFile, "setAttr \".fr\" %f;\n", fr);}
	/*
	Point will only be deformed if they are within the falloff radius about
	the falloff center.
	*/
	void setFalloffRadius(const DoubleID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*Point around which to scale.*/
	void setFalloffCenter(const double3& fcr){fprintf_s(mFile, "setAttr \".fcr\" -type \"double3\" ");fcr.write(mFile);fprintf_s(mFile,";\n");}
	/*Point around which to scale.*/
	void setFalloffCenter(const Double3ID& fcr){fprintf_s(mFile,"connectAttr \"");fcr.write(mFile);fprintf_s(mFile,"\" \"%s.fcr\";\n",mName.c_str());}
	/*X component of the point around which to scale.*/
	void setFalloffCenterX(double fcx){if(fcx == 0) return; fprintf_s(mFile, "setAttr \".fcr.fcx\" %f;\n", fcx);}
	/*X component of the point around which to scale.*/
	void setFalloffCenterX(const DoubleID& fcx){fprintf_s(mFile,"connectAttr \"");fcx.write(mFile);fprintf_s(mFile,"\" \"%s.fcr.fcx\";\n",mName.c_str());}
	/*Y component of the point around which to scale.*/
	void setFalloffCenterY(double fcy){if(fcy == 0) return; fprintf_s(mFile, "setAttr \".fcr.fcy\" %f;\n", fcy);}
	/*Y component of the point around which to scale.*/
	void setFalloffCenterY(const DoubleID& fcy){fprintf_s(mFile,"connectAttr \"");fcy.write(mFile);fprintf_s(mFile,"\" \"%s.fcr.fcy\";\n",mName.c_str());}
	/*Z component of the point around which to scale.*/
	void setFalloffCenterZ(double fcz){if(fcz == 0) return; fprintf_s(mFile, "setAttr \".fcr.fcz\" %f;\n", fcz);}
	/*Z component of the point around which to scale.*/
	void setFalloffCenterZ(const DoubleID& fcz){fprintf_s(mFile,"connectAttr \"");fcz.write(mFile);fprintf_s(mFile,"\" \"%s.fcr.fcz\";\n",mName.c_str());}
	/*If set to true then points will falloff in X*/
	void setFalloffInX(bool fix){if(fix == true) return; fprintf_s(mFile, "setAttr \".fix\" %i;\n", fix);}
	/*If set to true then points will falloff in X*/
	void setFalloffInX(const BoolID& fix){fprintf_s(mFile,"connectAttr \"");fix.write(mFile);fprintf_s(mFile,"\" \"%s.fix\";\n",mName.c_str());}
	/*If set to true then points will falloff in X*/
	void setFalloffInY(bool fiy){if(fiy == true) return; fprintf_s(mFile, "setAttr \".fiy\" %i;\n", fiy);}
	/*If set to true then points will falloff in X*/
	void setFalloffInY(const BoolID& fiy){fprintf_s(mFile,"connectAttr \"");fiy.write(mFile);fprintf_s(mFile,"\" \"%s.fiy\";\n",mName.c_str());}
	/*If set to true then points will falloff in X*/
	void setFalloffInZ(bool fiz){if(fiz == true) return; fprintf_s(mFile, "setAttr \".fiz\" %i;\n", fiz);}
	/*If set to true then points will falloff in X*/
	void setFalloffInZ(const BoolID& fiz){fprintf_s(mFile,"connectAttr \"");fiz.write(mFile);fprintf_s(mFile,"\" \"%s.fiz\";\n",mName.c_str());}
	/*If set to true then selected components will be deformed at centre weight*/
	void setFalloffAroundSelection(bool fas){if(fas == true) return; fprintf_s(mFile, "setAttr \".fas\" %i;\n", fas);}
	/*If set to true then selected components will be deformed at centre weight*/
	void setFalloffAroundSelection(const BoolID& fas){fprintf_s(mFile,"connectAttr \"");fas.write(mFile);fprintf_s(mFile,"\" \"%s.fas\";\n",mName.c_str());}
	/*If set to true then only selected components will be deformed*/
	void setFalloffMasking(bool fm){if(fm == true) return; fprintf_s(mFile, "setAttr \".fm\" %i;\n", fm);}
	/*If set to true then only selected components will be deformed*/
	void setFalloffMasking(const BoolID& fm){fprintf_s(mFile,"connectAttr \"");fm.write(mFile);fprintf_s(mFile,"\" \"%s.fm\";\n",mName.c_str());}
	/*
	If a transform matrix is passed to this attribute then the softMod
	will update in that transform's local space.
	*/
	void setInfluenceMatrix(const matrix& im){if(im == identity) return; fprintf_s(mFile, "setAttr \".im\" -type \"matrix\" ");im.write(mFile);fprintf_s(mFile,";\n");}
	/*
	If a transform matrix is passed to this attribute then the softMod
	will update in that transform's local space.
	*/
	void setInfluenceMatrix(const MatrixID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*
	The direction of angle interpolation.  In most cases
	0 (Closest) will work the best.  However, if components
	appear to be rotating in the wrong direction, a value
	of 1 (Positive) or 2 (Negative) may be needed.
	*/
	void setAngleInterpolation(unsigned int ait){if(ait == 0) return; fprintf_s(mFile, "setAttr \".ait\" %i;\n", ait);}
	/*
	The direction of angle interpolation.  In most cases
	0 (Closest) will work the best.  However, if components
	appear to be rotating in the wrong direction, a value
	of 1 (Positive) or 2 (Negative) may be needed.
	*/
	void setAngleInterpolation(const UnsignedintID& ait){fprintf_s(mFile,"connectAttr \"");ait.write(mFile);fprintf_s(mFile,"\" \"%s.ait\";\n",mName.c_str());}
	/*
	If set to true the deformer will cache internal distances to
	improve performance at the cost of additional memory.
	*/
	void setUseDistanceCache(bool udc){if(udc == true) return; fprintf_s(mFile, "setAttr \".udc\" %i;\n", udc);}
	/*
	If set to true the deformer will cache internal distances to
	improve performance at the cost of additional memory.
	*/
	void setUseDistanceCache(const BoolID& udc){fprintf_s(mFile,"connectAttr \"");udc.write(mFile);fprintf_s(mFile,"\" \"%s.udc\";\n",mName.c_str());}
	/*
	Internal attribute - the dirty state of this attribute reflects the dirty
	of the internal cache. The value itself is immaterial.
	*/
	void setDistanceCacheDirty(const BoolID& dcd){fprintf_s(mFile,"connectAttr \"");dcd.write(mFile);fprintf_s(mFile,"\" \"%s.dcd\";\n",mName.c_str());}
	/*
	How the falloff should be applied. A Volume based falloff (0)
	affects components based on their 3-dimensional distance
	from the influence point(s). A Surface based falloff (1) uses
	the distance across the surface being deformed.
	*/
	void setFalloffMode(unsigned int fom){if(fom == 0) return; fprintf_s(mFile, "setAttr \".fom\" %i;\n", fom);}
	/*
	How the falloff should be applied. A Volume based falloff (0)
	affects components based on their 3-dimensional distance
	from the influence point(s). A Surface based falloff (1) uses
	the distance across the surface being deformed.
	*/
	void setFalloffMode(const UnsignedintID& fom){fprintf_s(mFile,"connectAttr \"");fom.write(mFile);fprintf_s(mFile,"\" \"%s.fom\";\n",mName.c_str());}
	/*whether or not to use the partial resolution*/
	UnsignedintID getUsePartialResolution(){char buffer[4096];sprintf_s (buffer, "%s.upr",mName.c_str());return (const char*)buffer;}
	/*relative => only use weighted node i.e. no pre, post matrix*/
	BoolID getRelative(){char buffer[4096];sprintf_s (buffer, "%s.rel",mName.c_str());return (const char*)buffer;}
	/*the bundled softMod transforms*/
	SoftModXformsID getSoftModXforms(){char buffer[4096];sprintf_s (buffer, "%s.x",mName.c_str());return (const char*)buffer;}
	/*worldSpace matrix above softMod weighted matrix*/
	MatrixID getPreMatrix(){char buffer[4096];sprintf_s (buffer, "%s.x.pre",mName.c_str());return (const char*)buffer;}
	/*softMod weighted matrix*/
	MatrixID getWeightedMatrix(){char buffer[4096];sprintf_s (buffer, "%s.x.wt",mName.c_str());return (const char*)buffer;}
	/*worldSpace matrix below softMod weighted matrix*/
	MatrixID getPostMatrix(){char buffer[4096];sprintf_s (buffer, "%s.x.post",mName.c_str());return (const char*)buffer;}
	/*softMod weighted matrix compensation*/
	MatrixID getWeightedCompensationMatrix(){char buffer[4096];sprintf_s (buffer, "%s.wcm",mName.c_str());return (const char*)buffer;}
	/*Matrix to set account for the geom matrix at softMod creation time.*/
	const MatrixID& getGeomMatrix(size_t gm_i){char buffer[4096];sprintf_s (buffer, "%s.gm[%i]",mName.c_str(),gm_i);return (const char*)buffer;}
	/*transform that we will rigidly deform by when all percentages are at one*/
	MatrixID getMatrix(){char buffer[4096];sprintf_s (buffer, "%s.ma",mName.c_str());return (const char*)buffer;}
	/*compensation matrix used when we rigidly deform the geometry*/
	MatrixID getBindPreMatrix(){char buffer[4096];sprintf_s (buffer, "%s.pm",mName.c_str());return (const char*)buffer;}
	/*Define the falloff of the soft select by manipulating this ramp attribute*/
	const FalloffCurveID& getFalloffCurve(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i]",mName.c_str(),fc_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getFalloffCurve_Position(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i].fcp",mName.c_str(),fc_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getFalloffCurve_FloatValue(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i].fcfv",mName.c_str(),fc_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getFalloffCurve_Interp(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i].fci",mName.c_str(),fc_i);return (const char*)buffer;}
	/*
	Point will only be deformed if they are within the falloff radius about
	the falloff center.
	*/
	DoubleID getFalloffRadius(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*Point around which to scale.*/
	Double3ID getFalloffCenter(){char buffer[4096];sprintf_s (buffer, "%s.fcr",mName.c_str());return (const char*)buffer;}
	/*X component of the point around which to scale.*/
	DoubleID getFalloffCenterX(){char buffer[4096];sprintf_s (buffer, "%s.fcr.fcx",mName.c_str());return (const char*)buffer;}
	/*Y component of the point around which to scale.*/
	DoubleID getFalloffCenterY(){char buffer[4096];sprintf_s (buffer, "%s.fcr.fcy",mName.c_str());return (const char*)buffer;}
	/*Z component of the point around which to scale.*/
	DoubleID getFalloffCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.fcr.fcz",mName.c_str());return (const char*)buffer;}
	/*If set to true then points will falloff in X*/
	BoolID getFalloffInX(){char buffer[4096];sprintf_s (buffer, "%s.fix",mName.c_str());return (const char*)buffer;}
	/*If set to true then points will falloff in X*/
	BoolID getFalloffInY(){char buffer[4096];sprintf_s (buffer, "%s.fiy",mName.c_str());return (const char*)buffer;}
	/*If set to true then points will falloff in X*/
	BoolID getFalloffInZ(){char buffer[4096];sprintf_s (buffer, "%s.fiz",mName.c_str());return (const char*)buffer;}
	/*If set to true then selected components will be deformed at centre weight*/
	BoolID getFalloffAroundSelection(){char buffer[4096];sprintf_s (buffer, "%s.fas",mName.c_str());return (const char*)buffer;}
	/*If set to true then only selected components will be deformed*/
	BoolID getFalloffMasking(){char buffer[4096];sprintf_s (buffer, "%s.fm",mName.c_str());return (const char*)buffer;}
	/*
	If a transform matrix is passed to this attribute then the softMod
	will update in that transform's local space.
	*/
	MatrixID getInfluenceMatrix(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*
	The direction of angle interpolation.  In most cases
	0 (Closest) will work the best.  However, if components
	appear to be rotating in the wrong direction, a value
	of 1 (Positive) or 2 (Negative) may be needed.
	*/
	UnsignedintID getAngleInterpolation(){char buffer[4096];sprintf_s (buffer, "%s.ait",mName.c_str());return (const char*)buffer;}
	/*
	If set to true the deformer will cache internal distances to
	improve performance at the cost of additional memory.
	*/
	BoolID getUseDistanceCache(){char buffer[4096];sprintf_s (buffer, "%s.udc",mName.c_str());return (const char*)buffer;}
	/*
	Internal attribute - the dirty state of this attribute reflects the dirty
	of the internal cache. The value itself is immaterial.
	*/
	BoolID getDistanceCacheDirty(){char buffer[4096];sprintf_s (buffer, "%s.dcd",mName.c_str());return (const char*)buffer;}
	/*
	How the falloff should be applied. A Volume based falloff (0)
	affects components based on their 3-dimensional distance
	from the influence point(s). A Surface based falloff (1) uses
	the distance across the surface being deformed.
	*/
	UnsignedintID getFalloffMode(){char buffer[4096];sprintf_s (buffer, "%s.fom",mName.c_str());return (const char*)buffer;}
protected:
	SoftMod(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):WeightGeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SOFTMOD_H__
