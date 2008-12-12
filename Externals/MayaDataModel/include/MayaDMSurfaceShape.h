/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACESHAPE_H__
#define __MayaDM_SURFACESHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMControlPoint.h"
namespace MayaDM
{
/*
This node is an base class for surface objects.
        It defines some basic rendering attributes which determine whether the
        surface should appear smooth shaded or flat shaded, whether the
        surface normals should be reversed and whether the surface is visible
        only on the side where the normals are pointing outward or is visible
        from both sides of the surface. <p/>
*/
class SurfaceShape : public ControlPoint
{
public:
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	struct CollisionOffsetVelocityIncrement{
		float collisionOffsetVelocityIncrement_Position;
		float collisionOffsetVelocityIncrement_FloatValue;
		unsigned int collisionOffsetVelocityIncrement_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", collisionOffsetVelocityIncrement_Position);
			fprintf_s(file,"%f ", collisionOffsetVelocityIncrement_FloatValue);
			fprintf_s(file,"%i", collisionOffsetVelocityIncrement_Interp);
		}
	};
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	struct CollisionDepthVelocityIncrement{
		float collisionDepthVelocityIncrement_Position;
		float collisionDepthVelocityIncrement_FloatValue;
		unsigned int collisionDepthVelocityIncrement_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", collisionDepthVelocityIncrement_Position);
			fprintf_s(file,"%f ", collisionDepthVelocityIncrement_FloatValue);
			fprintf_s(file,"%i", collisionDepthVelocityIncrement_Interp);
		}
	};
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	struct CollisionOffsetVelocityMultiplier{
		float collisionOffsetVelocityMultiplier_Position;
		float collisionOffsetVelocityMultiplier_FloatValue;
		unsigned int collisionOffsetVelocityMultiplier_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", collisionOffsetVelocityMultiplier_Position);
			fprintf_s(file,"%f ", collisionOffsetVelocityMultiplier_FloatValue);
			fprintf_s(file,"%i", collisionOffsetVelocityMultiplier_Interp);
		}
	};
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	struct CollisionDepthVelocityMultiplier{
		float collisionDepthVelocityMultiplier_Position;
		float collisionDepthVelocityMultiplier_FloatValue;
		unsigned int collisionDepthVelocityMultiplier_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", collisionDepthVelocityMultiplier_Position);
			fprintf_s(file,"%f ", collisionDepthVelocityMultiplier_FloatValue);
			fprintf_s(file,"%i", collisionDepthVelocityMultiplier_Interp);
		}
	};
public:
	SurfaceShape(FILE* file,const std::string& name,const std::string& parent=""):ControlPoint(file, name, parent, "surfaceShape"){}
	virtual ~SurfaceShape(){}
	/*
	Wether or not the drawing of this surface ignores the hardware shader.
	If true, the default shader will be used instead of the hardware shader.
	*/
	void setIgnoreHwShader(bool ih){if(ih == false) return; fprintf_s(mFile, "setAttr \".ih\" %i;\n", ih);}
	/*
	Wether or not the drawing of this surface ignores the hardware shader.
	If true, the default shader will be used instead of the hardware shader.
	*/
	void setIgnoreHwShader(const BoolID& ih){fprintf_s(mFile,"connectAttr \"");ih.write(mFile);fprintf_s(mFile,"\" \"%s.ih\";\n",mName.c_str());}
	/*
	Is the surface double sided or not.  If single sided, it can bring
	some memory reduction, and it will also obey the "opposite" flag
	*/
	void setDoubleSided(bool ds){if(ds == true) return; fprintf_s(mFile, "setAttr \".ds\" %i;\n", ds);}
	/*
	Is the surface double sided or not.  If single sided, it can bring
	some memory reduction, and it will also obey the "opposite" flag
	*/
	void setDoubleSided(const BoolID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*
	Should the surface normals be flipped - only relevant when
	doubleSided is turned off
	*/
	void setOpposite(bool op){if(op == false) return; fprintf_s(mFile, "setAttr \".op\" %i;\n", op);}
	/*
	Should the surface normals be flipped - only relevant when
	doubleSided is turned off
	*/
	void setOpposite(const BoolID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*Does the surface have smooth shading - this is only relevant for polymesh*/
	void setSmoothShading(bool smo){if(smo == true) return; fprintf_s(mFile, "setAttr \".smo\" %i;\n", smo);}
	/*Does the surface have smooth shading - this is only relevant for polymesh*/
	void setSmoothShading(const BoolID& smo){fprintf_s(mFile,"connectAttr \"");smo.write(mFile);fprintf_s(mFile,"\" \"%s.smo\";\n",mName.c_str());}
	/*bounding box scale for displacement map.*/
	void setBoundingBoxScale(const float3& bbs){fprintf_s(mFile, "setAttr \".bbs\" -type \"float3\" ");bbs.write(mFile);fprintf_s(mFile,";\n");}
	/*bounding box scale for displacement map.*/
	void setBoundingBoxScale(const Float3ID& bbs){fprintf_s(mFile,"connectAttr \"");bbs.write(mFile);fprintf_s(mFile,"\" \"%s.bbs\";\n",mName.c_str());}
	/*bounding box scale x for displacement map.*/
	void setBoundingBoxScaleX(float bscx){if(bscx == 1.5) return; fprintf_s(mFile, "setAttr \".bbs.bscx\" %f;\n", bscx);}
	/*bounding box scale x for displacement map.*/
	void setBoundingBoxScaleX(const FloatID& bscx){fprintf_s(mFile,"connectAttr \"");bscx.write(mFile);fprintf_s(mFile,"\" \"%s.bbs.bscx\";\n",mName.c_str());}
	/*bounding box scale y for displacement map.*/
	void setBoundingBoxScaleY(float bscy){if(bscy == 1.5) return; fprintf_s(mFile, "setAttr \".bbs.bscy\" %f;\n", bscy);}
	/*bounding box scale y for displacement map.*/
	void setBoundingBoxScaleY(const FloatID& bscy){fprintf_s(mFile,"connectAttr \"");bscy.write(mFile);fprintf_s(mFile,"\" \"%s.bbs.bscy\";\n",mName.c_str());}
	/*bounding box scale z for displacement map.*/
	void setBoundingBoxScaleZ(float bscz){if(bscz == 1.5) return; fprintf_s(mFile, "setAttr \".bbs.bscz\" %f;\n", bscz);}
	/*bounding box scale z for displacement map.*/
	void setBoundingBoxScaleZ(const FloatID& bscz){fprintf_s(mFile,"connectAttr \"");bscz.write(mFile);fprintf_s(mFile,"\" \"%s.bbs.bscz\";\n",mName.c_str());}
	/*When true, use feature-based displacement algorithm for displacement-map.*/
	void setFeatureDisplacement(bool fbda){if(fbda == true) return; fprintf_s(mFile, "setAttr \".fbda\" %i;\n", fbda);}
	/*When true, use feature-based displacement algorithm for displacement-map.*/
	void setFeatureDisplacement(const BoolID& fbda){fprintf_s(mFile,"connectAttr \"");fbda.write(mFile);fprintf_s(mFile,"\" \"%s.fbda\";\n",mName.c_str());}
	/*Number of samples per triangle edge.*/
	void setInitialSampleRate(int dsr){if(dsr == 6) return; fprintf_s(mFile, "setAttr \".dsr\" %i;\n", dsr);}
	/*Number of samples per triangle edge.*/
	void setInitialSampleRate(const IntID& dsr){fprintf_s(mFile,"connectAttr \"");dsr.write(mFile);fprintf_s(mFile,"\" \"%s.dsr\";\n",mName.c_str());}
	/*Number of extra samples taken when moving sample points*/
	void setExtraSampleRate(int xsr){if(xsr == 5) return; fprintf_s(mFile, "setAttr \".xsr\" %i;\n", xsr);}
	/*Number of extra samples taken when moving sample points*/
	void setExtraSampleRate(const IntID& xsr){fprintf_s(mFile,"connectAttr \"");xsr.write(mFile);fprintf_s(mFile,"\" \"%s.xsr\";\n",mName.c_str());}
	/*Only a percentage of the largest texture feature will be captured.*/
	void setTextureThreshold(int fth){if(fth == 0) return; fprintf_s(mFile, "setAttr \".fth\" %i;\n", fth);}
	/*Only a percentage of the largest texture feature will be captured.*/
	void setTextureThreshold(const IntID& fth){fprintf_s(mFile,"connectAttr \"");fth.write(mFile);fprintf_s(mFile,"\" \"%s.fth\";\n",mName.c_str());}
	/*Normals below the threshold angle will be averaged.*/
	void setNormalThreshold(float nat){if(nat == 30) return; fprintf_s(mFile, "setAttr \".nat\" %f;\n", nat);}
	/*Normals below the threshold angle will be averaged.*/
	void setNormalThreshold(const FloatID& nat){fprintf_s(mFile,"connectAttr \"");nat.write(mFile);fprintf_s(mFile,"\" \"%s.nat\";\n",mName.c_str());}
	/*
	Specifies if the object is to display hardware environment maps
	in shaded mode. By default this flag is false.
	*/
	void setDisplayHWEnvironment(bool dhe){if(dhe == false) return; fprintf_s(mFile, "setAttr \".dhe\" %i;\n", dhe);}
	/*
	Specifies if the object is to display hardware environment maps
	in shaded mode. By default this flag is false.
	*/
	void setDisplayHWEnvironment(const BoolID& dhe){fprintf_s(mFile,"connectAttr \"");dhe.write(mFile);fprintf_s(mFile,"\" \"%s.dhe\";\n",mName.c_str());}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	void setCollisionOffsetVelocityIncrement(size_t covi_i,const CollisionOffsetVelocityIncrement& covi){fprintf_s(mFile, "setAttr \".covi[%i]\" ",covi_i);covi.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	void setCollisionOffsetVelocityIncrement(size_t covi_i,const CollisionOffsetVelocityIncrementID& covi){fprintf_s(mFile,"connectAttr \"");covi.write(mFile);fprintf_s(mFile,"\" \"%s.covi[%i]\";\n",mName.c_str(),covi_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCollisionOffsetVelocityIncrement_Position(size_t covi_i,float covip){if(covip == 0.0) return; fprintf_s(mFile, "setAttr \".covi[%i].covip\" %f;\n", covi_i,covip);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCollisionOffsetVelocityIncrement_Position(size_t covi_i,const FloatID& covip){fprintf_s(mFile,"connectAttr \"");covip.write(mFile);fprintf_s(mFile,"\" \"%s.covi[%i].covip\";\n",mName.c_str(),covi_i);}
	/*Ramp value at the sibling position*/
	void setCollisionOffsetVelocityIncrement_FloatValue(size_t covi_i,float covifv){if(covifv == 0.0) return; fprintf_s(mFile, "setAttr \".covi[%i].covifv\" %f;\n", covi_i,covifv);}
	/*Ramp value at the sibling position*/
	void setCollisionOffsetVelocityIncrement_FloatValue(size_t covi_i,const FloatID& covifv){fprintf_s(mFile,"connectAttr \"");covifv.write(mFile);fprintf_s(mFile,"\" \"%s.covi[%i].covifv\";\n",mName.c_str(),covi_i);}
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
	void setCollisionOffsetVelocityIncrement_Interp(size_t covi_i,unsigned int covii){if(covii == 0) return; fprintf_s(mFile, "setAttr \".covi[%i].covii\" %i;\n", covi_i,covii);}
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
	void setCollisionOffsetVelocityIncrement_Interp(size_t covi_i,const UnsignedintID& covii){fprintf_s(mFile,"connectAttr \"");covii.write(mFile);fprintf_s(mFile,"\" \"%s.covi[%i].covii\";\n",mName.c_str(),covi_i);}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	void setCollisionDepthVelocityIncrement(size_t cdvi_i,const CollisionDepthVelocityIncrement& cdvi){fprintf_s(mFile, "setAttr \".cdvi[%i]\" ",cdvi_i);cdvi.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	void setCollisionDepthVelocityIncrement(size_t cdvi_i,const CollisionDepthVelocityIncrementID& cdvi){fprintf_s(mFile,"connectAttr \"");cdvi.write(mFile);fprintf_s(mFile,"\" \"%s.cdvi[%i]\";\n",mName.c_str(),cdvi_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCollisionDepthVelocityIncrement_Position(size_t cdvi_i,float cdvip){if(cdvip == 0.0) return; fprintf_s(mFile, "setAttr \".cdvi[%i].cdvip\" %f;\n", cdvi_i,cdvip);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCollisionDepthVelocityIncrement_Position(size_t cdvi_i,const FloatID& cdvip){fprintf_s(mFile,"connectAttr \"");cdvip.write(mFile);fprintf_s(mFile,"\" \"%s.cdvi[%i].cdvip\";\n",mName.c_str(),cdvi_i);}
	/*Ramp value at the sibling position*/
	void setCollisionDepthVelocityIncrement_FloatValue(size_t cdvi_i,float cdvifv){if(cdvifv == 0.0) return; fprintf_s(mFile, "setAttr \".cdvi[%i].cdvifv\" %f;\n", cdvi_i,cdvifv);}
	/*Ramp value at the sibling position*/
	void setCollisionDepthVelocityIncrement_FloatValue(size_t cdvi_i,const FloatID& cdvifv){fprintf_s(mFile,"connectAttr \"");cdvifv.write(mFile);fprintf_s(mFile,"\" \"%s.cdvi[%i].cdvifv\";\n",mName.c_str(),cdvi_i);}
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
	void setCollisionDepthVelocityIncrement_Interp(size_t cdvi_i,unsigned int cdvii){if(cdvii == 0) return; fprintf_s(mFile, "setAttr \".cdvi[%i].cdvii\" %i;\n", cdvi_i,cdvii);}
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
	void setCollisionDepthVelocityIncrement_Interp(size_t cdvi_i,const UnsignedintID& cdvii){fprintf_s(mFile,"connectAttr \"");cdvii.write(mFile);fprintf_s(mFile,"\" \"%s.cdvi[%i].cdvii\";\n",mName.c_str(),cdvi_i);}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	void setCollisionOffsetVelocityMultiplier(size_t covm_i,const CollisionOffsetVelocityMultiplier& covm){fprintf_s(mFile, "setAttr \".covm[%i]\" ",covm_i);covm.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	void setCollisionOffsetVelocityMultiplier(size_t covm_i,const CollisionOffsetVelocityMultiplierID& covm){fprintf_s(mFile,"connectAttr \"");covm.write(mFile);fprintf_s(mFile,"\" \"%s.covm[%i]\";\n",mName.c_str(),covm_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCollisionOffsetVelocityMultiplier_Position(size_t covm_i,float covmp){if(covmp == 0.0) return; fprintf_s(mFile, "setAttr \".covm[%i].covmp\" %f;\n", covm_i,covmp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCollisionOffsetVelocityMultiplier_Position(size_t covm_i,const FloatID& covmp){fprintf_s(mFile,"connectAttr \"");covmp.write(mFile);fprintf_s(mFile,"\" \"%s.covm[%i].covmp\";\n",mName.c_str(),covm_i);}
	/*Ramp value at the sibling position*/
	void setCollisionOffsetVelocityMultiplier_FloatValue(size_t covm_i,float covmfv){if(covmfv == 0.0) return; fprintf_s(mFile, "setAttr \".covm[%i].covmfv\" %f;\n", covm_i,covmfv);}
	/*Ramp value at the sibling position*/
	void setCollisionOffsetVelocityMultiplier_FloatValue(size_t covm_i,const FloatID& covmfv){fprintf_s(mFile,"connectAttr \"");covmfv.write(mFile);fprintf_s(mFile,"\" \"%s.covm[%i].covmfv\";\n",mName.c_str(),covm_i);}
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
	void setCollisionOffsetVelocityMultiplier_Interp(size_t covm_i,unsigned int covmi){if(covmi == 0) return; fprintf_s(mFile, "setAttr \".covm[%i].covmi\" %i;\n", covm_i,covmi);}
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
	void setCollisionOffsetVelocityMultiplier_Interp(size_t covm_i,const UnsignedintID& covmi){fprintf_s(mFile,"connectAttr \"");covmi.write(mFile);fprintf_s(mFile,"\" \"%s.covm[%i].covmi\";\n",mName.c_str(),covm_i);}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	void setCollisionDepthVelocityMultiplier(size_t cdvm_i,const CollisionDepthVelocityMultiplier& cdvm){fprintf_s(mFile, "setAttr \".cdvm[%i]\" ",cdvm_i);cdvm.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	void setCollisionDepthVelocityMultiplier(size_t cdvm_i,const CollisionDepthVelocityMultiplierID& cdvm){fprintf_s(mFile,"connectAttr \"");cdvm.write(mFile);fprintf_s(mFile,"\" \"%s.cdvm[%i]\";\n",mName.c_str(),cdvm_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCollisionDepthVelocityMultiplier_Position(size_t cdvm_i,float cdvmp){if(cdvmp == 0.0) return; fprintf_s(mFile, "setAttr \".cdvm[%i].cdvmp\" %f;\n", cdvm_i,cdvmp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCollisionDepthVelocityMultiplier_Position(size_t cdvm_i,const FloatID& cdvmp){fprintf_s(mFile,"connectAttr \"");cdvmp.write(mFile);fprintf_s(mFile,"\" \"%s.cdvm[%i].cdvmp\";\n",mName.c_str(),cdvm_i);}
	/*Ramp value at the sibling position*/
	void setCollisionDepthVelocityMultiplier_FloatValue(size_t cdvm_i,float cdvmfv){if(cdvmfv == 0.0) return; fprintf_s(mFile, "setAttr \".cdvm[%i].cdvmfv\" %f;\n", cdvm_i,cdvmfv);}
	/*Ramp value at the sibling position*/
	void setCollisionDepthVelocityMultiplier_FloatValue(size_t cdvm_i,const FloatID& cdvmfv){fprintf_s(mFile,"connectAttr \"");cdvmfv.write(mFile);fprintf_s(mFile,"\" \"%s.cdvm[%i].cdvmfv\";\n",mName.c_str(),cdvm_i);}
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
	void setCollisionDepthVelocityMultiplier_Interp(size_t cdvm_i,unsigned int cdvmi){if(cdvmi == 0) return; fprintf_s(mFile, "setAttr \".cdvm[%i].cdvmi\" %i;\n", cdvm_i,cdvmi);}
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
	void setCollisionDepthVelocityMultiplier_Interp(size_t cdvm_i,const UnsignedintID& cdvmi){fprintf_s(mFile,"connectAttr \"");cdvmi.write(mFile);fprintf_s(mFile,"\" \"%s.cdvm[%i].cdvmi\";\n",mName.c_str(),cdvm_i);}
	/*
	Wether or not the drawing of this surface ignores the hardware shader.
	If true, the default shader will be used instead of the hardware shader.
	*/
	BoolID getIgnoreHwShader(){char buffer[4096];sprintf_s (buffer, "%s.ih",mName.c_str());return (const char*)buffer;}
	/*
	Is the surface double sided or not.  If single sided, it can bring
	some memory reduction, and it will also obey the "opposite" flag
	*/
	BoolID getDoubleSided(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
	/*
	Should the surface normals be flipped - only relevant when
	doubleSided is turned off
	*/
	BoolID getOpposite(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*Does the surface have smooth shading - this is only relevant for polymesh*/
	BoolID getSmoothShading(){char buffer[4096];sprintf_s (buffer, "%s.smo",mName.c_str());return (const char*)buffer;}
	/*bounding box scale for displacement map.*/
	Float3ID getBoundingBoxScale(){char buffer[4096];sprintf_s (buffer, "%s.bbs",mName.c_str());return (const char*)buffer;}
	/*bounding box scale x for displacement map.*/
	FloatID getBoundingBoxScaleX(){char buffer[4096];sprintf_s (buffer, "%s.bbs.bscx",mName.c_str());return (const char*)buffer;}
	/*bounding box scale y for displacement map.*/
	FloatID getBoundingBoxScaleY(){char buffer[4096];sprintf_s (buffer, "%s.bbs.bscy",mName.c_str());return (const char*)buffer;}
	/*bounding box scale z for displacement map.*/
	FloatID getBoundingBoxScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.bbs.bscz",mName.c_str());return (const char*)buffer;}
	/*When true, use feature-based displacement algorithm for displacement-map.*/
	BoolID getFeatureDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.fbda",mName.c_str());return (const char*)buffer;}
	/*Number of samples per triangle edge.*/
	IntID getInitialSampleRate(){char buffer[4096];sprintf_s (buffer, "%s.dsr",mName.c_str());return (const char*)buffer;}
	/*Number of extra samples taken when moving sample points*/
	IntID getExtraSampleRate(){char buffer[4096];sprintf_s (buffer, "%s.xsr",mName.c_str());return (const char*)buffer;}
	/*Only a percentage of the largest texture feature will be captured.*/
	IntID getTextureThreshold(){char buffer[4096];sprintf_s (buffer, "%s.fth",mName.c_str());return (const char*)buffer;}
	/*Normals below the threshold angle will be averaged.*/
	FloatID getNormalThreshold(){char buffer[4096];sprintf_s (buffer, "%s.nat",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if the object is to display hardware environment maps
	in shaded mode. By default this flag is false.
	*/
	BoolID getDisplayHWEnvironment(){char buffer[4096];sprintf_s (buffer, "%s.dhe",mName.c_str());return (const char*)buffer;}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	const CollisionOffsetVelocityIncrementID& getCollisionOffsetVelocityIncrement(size_t covi_i){char buffer[4096];sprintf_s (buffer, "%s.covi[%i]",mName.c_str(),covi_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getCollisionOffsetVelocityIncrement_Position(size_t covi_i){char buffer[4096];sprintf_s (buffer, "%s.covi[%i].covip",mName.c_str(),covi_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getCollisionOffsetVelocityIncrement_FloatValue(size_t covi_i){char buffer[4096];sprintf_s (buffer, "%s.covi[%i].covifv",mName.c_str(),covi_i);return (const char*)buffer;}
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
	const UnsignedintID& getCollisionOffsetVelocityIncrement_Interp(size_t covi_i){char buffer[4096];sprintf_s (buffer, "%s.covi[%i].covii",mName.c_str(),covi_i);return (const char*)buffer;}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	const CollisionDepthVelocityIncrementID& getCollisionDepthVelocityIncrement(size_t cdvi_i){char buffer[4096];sprintf_s (buffer, "%s.cdvi[%i]",mName.c_str(),cdvi_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getCollisionDepthVelocityIncrement_Position(size_t cdvi_i){char buffer[4096];sprintf_s (buffer, "%s.cdvi[%i].cdvip",mName.c_str(),cdvi_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getCollisionDepthVelocityIncrement_FloatValue(size_t cdvi_i){char buffer[4096];sprintf_s (buffer, "%s.cdvi[%i].cdvifv",mName.c_str(),cdvi_i);return (const char*)buffer;}
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
	const UnsignedintID& getCollisionDepthVelocityIncrement_Interp(size_t cdvi_i){char buffer[4096];sprintf_s (buffer, "%s.cdvi[%i].cdvii",mName.c_str(),cdvi_i);return (const char*)buffer;}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	const CollisionOffsetVelocityMultiplierID& getCollisionOffsetVelocityMultiplier(size_t covm_i){char buffer[4096];sprintf_s (buffer, "%s.covm[%i]",mName.c_str(),covm_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getCollisionOffsetVelocityMultiplier_Position(size_t covm_i){char buffer[4096];sprintf_s (buffer, "%s.covm[%i].covmp",mName.c_str(),covm_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getCollisionOffsetVelocityMultiplier_FloatValue(size_t covm_i){char buffer[4096];sprintf_s (buffer, "%s.covm[%i].covmfv",mName.c_str(),covm_i);return (const char*)buffer;}
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
	const UnsignedintID& getCollisionOffsetVelocityMultiplier_Interp(size_t covm_i){char buffer[4096];sprintf_s (buffer, "%s.covm[%i].covmi",mName.c_str(),covm_i);return (const char*)buffer;}
	/*
	This is to control cloth collision. We leave it here because the
	dynamic ramp attribute is not supported. See bug 218113.
	*/
	const CollisionDepthVelocityMultiplierID& getCollisionDepthVelocityMultiplier(size_t cdvm_i){char buffer[4096];sprintf_s (buffer, "%s.cdvm[%i]",mName.c_str(),cdvm_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getCollisionDepthVelocityMultiplier_Position(size_t cdvm_i){char buffer[4096];sprintf_s (buffer, "%s.cdvm[%i].cdvmp",mName.c_str(),cdvm_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getCollisionDepthVelocityMultiplier_FloatValue(size_t cdvm_i){char buffer[4096];sprintf_s (buffer, "%s.cdvm[%i].cdvmfv",mName.c_str(),cdvm_i);return (const char*)buffer;}
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
	const UnsignedintID& getCollisionDepthVelocityMultiplier_Interp(size_t cdvm_i){char buffer[4096];sprintf_s (buffer, "%s.cdvm[%i].cdvmi",mName.c_str(),cdvm_i);return (const char*)buffer;}
protected:
	SurfaceShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ControlPoint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SURFACESHAPE_H__
