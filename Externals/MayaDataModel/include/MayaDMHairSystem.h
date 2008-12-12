/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HAIRSYSTEM_H__
#define __MayaDM_HAIRSYSTEM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
This node is used to dynamically simulate long hair motion with collision.
 This takes an array of start and rest positions from follicle nodes and computes an array of
 output hair positions(point arrays). When the current time input steps forward this computes a new
 position based on its current position. When the time is rewound to the start frame it sets the positions
 to the input start hair positions.
 <p/>
*/
class HairSystem : public Shape
{
public:
	/*
	<b>Stiffness Scale</b> affects the stiffness from root to tip of the hair.
	The left of the graph is the root and the right is the tip. Typically the root of a
	hair is thicker and thus stiffer than the tip. This attribute multiplies
	the stiffness parameter value, so a value of 1.0 will leave the stiffness unchanged.
	If the stiffness attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	struct StiffnessScale{
		float stiffnessScale_Position;
		float stiffnessScale_FloatValue;
		unsigned int stiffnessScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", stiffnessScale_Position);
			fprintf_s(file,"%f ", stiffnessScale_FloatValue);
			fprintf_s(file,"%i", stiffnessScale_Interp);
		}
	};
	/*
	This value attenuates the startCurveAttract value along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	If the startCurveAttract attribute is zero then this parameter will have no effect,
	as zero times a number is always zero.
	*/
	struct AttractionScale{
		float attractionScale_Position;
		float attractionScale_FloatValue;
		unsigned int attractionScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", attractionScale_Position);
			fprintf_s(file,"%f ", attractionScale_FloatValue);
			fprintf_s(file,"%i", attractionScale_Interp);
		}
	};
	/*
	<b>Clump Width Scale</b> affects the width from root to tip of the hair clump.
	The left of the graph is the root and the right is the tip.
	Often one may wish the hairs within the clump to come to a tip at the end of the clump,
	in which case the right value should be smaller than the left. This attribute multiplies
	the clumpWidth parameter value, so a value of 1.0 will leave the clumpWidth unchanged.
	If the clumpWidth attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	struct ClumpWidthScale{
		float clumpWidthScale_Position;
		float clumpWidthScale_FloatValue;
		unsigned int clumpWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", clumpWidthScale_Position);
			fprintf_s(file,"%f ", clumpWidthScale_FloatValue);
			fprintf_s(file,"%i", clumpWidthScale_Interp);
		}
	};
	/*
	<b>Clump Curl</b> controls the rate of curling about the primary axis of each hair clump.
	The left of the graph is the root and the right is the tip.
	The mid value of the ramp(0.5) represents no twist while values greater than that will result
	in positive twisting while smaller values will cause twisting in the reverse direction.
	*/
	struct ClumpCurl{
		float clumpCurl_Position;
		float clumpCurl_FloatValue;
		unsigned int clumpCurl_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", clumpCurl_Position);
			fprintf_s(file,"%f ", clumpCurl_FloatValue);
			fprintf_s(file,"%i", clumpCurl_Interp);
		}
	};
	/*
	<b>Clump Flatness</b> affects the flatness of the clump group from root to tip.
	The left of the graph is the root and the right is the tip.
	*/
	struct ClumpFlatness{
		float clumpFlatness_Position;
		float clumpFlatness_FloatValue;
		unsigned int clumpFlatness_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", clumpFlatness_Position);
			fprintf_s(file,"%f ", clumpFlatness_FloatValue);
			fprintf_s(file,"%i", clumpFlatness_Interp);
		}
	};
	/*
	<b>Hair Width Scale</b> affects the width from root to tip of the hairs.
	The left of the graph is the root and the right is the tip.
	This attribute multiplies the hairWidth parameter value, so a value of 1.0
	will leave the hairWidth unchanged.
	If the hairWidth attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	struct HairWidthScale{
		float hairWidthScale_Position;
		float hairWidthScale_FloatValue;
		unsigned int hairWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", hairWidthScale_Position);
			fprintf_s(file,"%f ", hairWidthScale_FloatValue);
			fprintf_s(file,"%i", hairWidthScale_Interp);
		}
	};
	/*
	<b>Hair Color</b> defines the global color of the hairs from root to tip.
	The left of the graph is the root and the right is the tip.
	*/
	struct HairColorScale{
		float hairColorScale_Position;
		float3 hairColorScale_Color;
		unsigned int hairColorScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", hairColorScale_Position);
			hairColorScale_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", hairColorScale_Interp);
		}
	};
	/*
	<b>Displacement Scale</b> affects the amount of displacment applied from root to
	tip of the hair clump. This affects curl, noise and subclumps. If the left side
	is zero then the effect will be gradually added such that the root position of the
	hair is not changed.
	*/
	struct DisplacementScale{
		float displacementScale_Position;
		float displacementScale_FloatValue;
		unsigned int displacementScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", displacementScale_Position);
			fprintf_s(file,"%f ", displacementScale_FloatValue);
			fprintf_s(file,"%i", displacementScale_Interp);
		}
	};
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	struct FieldData{
		void write(FILE* file) const
		{
		}
	};
	/*Parent attribute for all collision input data.*/
	struct CollisionData{
		void write(FILE* file) const
		{
		}
	};
	/*This is a root of following mental ray attributes.*/
	struct MentalRayControls{
		bool miOverrideCaustics;
		short miCausticAccuracy;
		float miCausticRadius;
		bool miOverrideGlobalIllumination;
		short miGlobillumAccuracy;
		float miGlobillumRadius;
		bool miOverrideFinalGather;
		int miFinalGatherRays;
		float miFinalGatherMinRadius;
		float miFinalGatherMaxRadius;
		short miFinalGatherFilter;
		bool miFinalGatherView;
		bool miOverrideSamples;
		short miMinSamples;
		short miMaxSamples;
		bool miFinalGatherCast;
		bool miFinalGatherReceive;
		bool miTransparencyCast;
		bool miTransparencyReceive;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", miOverrideCaustics);
			fprintf_s(file,"%i ", miCausticAccuracy);
			fprintf_s(file,"%f ", miCausticRadius);
			fprintf_s(file,"%i ", miOverrideGlobalIllumination);
			fprintf_s(file,"%i ", miGlobillumAccuracy);
			fprintf_s(file,"%f ", miGlobillumRadius);
			fprintf_s(file,"%i ", miOverrideFinalGather);
			fprintf_s(file,"%i ", miFinalGatherRays);
			fprintf_s(file,"%f ", miFinalGatherMinRadius);
			fprintf_s(file,"%f ", miFinalGatherMaxRadius);
			fprintf_s(file,"%i ", miFinalGatherFilter);
			fprintf_s(file,"%i ", miFinalGatherView);
			fprintf_s(file,"%i ", miOverrideSamples);
			fprintf_s(file,"%i ", miMinSamples);
			fprintf_s(file,"%i ", miMaxSamples);
			fprintf_s(file,"%i ", miFinalGatherCast);
			fprintf_s(file,"%i ", miFinalGatherReceive);
			fprintf_s(file,"%i ", miTransparencyCast);
			fprintf_s(file,"%i", miTransparencyReceive);
		}
	};
public:
	HairSystem(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "hairSystem"){}
	virtual ~HairSystem(){}
	/*
	This controls the simulation level. If Off is selected then there is no output.
	Static positions the output hair aways at the start position with no dynamics(totally stiff).
	Dynamic Follicles Only will avoid generating output for passive follicles(if any).
	This is useful for faster preview of complex hairsystems.
	All Follicles will compute the full simulation.
	*/
	void setSimulationMethod(unsigned int sim){if(sim == 3) return; fprintf_s(mFile, "setAttr \".sim\" %i;\n", sim);}
	/*
	This controls the simulation level. If Off is selected then there is no output.
	Static positions the output hair aways at the start position with no dynamics(totally stiff).
	Dynamic Follicles Only will avoid generating output for passive follicles(if any).
	This is useful for faster preview of complex hairsystems.
	All Follicles will compute the full simulation.
	*/
	void setSimulationMethod(const UnsignedintID& sim){fprintf_s(mFile,"connectAttr \"");sim.write(mFile);fprintf_s(mFile,"\" \"%s.sim\";\n",mName.c_str());}
	/*Input hair*/
	void setInputHair(size_t ih_i,const HairCurveID& ih){fprintf_s(mFile,"connectAttr \"");ih.write(mFile);fprintf_s(mFile,"\" \"%s.ih[%i]\";\n",mName.c_str(),ih_i);}
	/*Input hair pin constraints*/
	void setInputHairPin(size_t ihp_i,const HairPinID& ihp){fprintf_s(mFile,"connectAttr \"");ihp.write(mFile);fprintf_s(mFile,"\" \"%s.ihp[%i]\";\n",mName.c_str(),ihp_i);}
	/*If true then collide with connected objects.*/
	void setCollide(bool cld){if(cld == true) return; fprintf_s(mFile, "setAttr \".cld\" %i;\n", cld);}
	/*If true then collide with connected objects.*/
	void setCollide(const BoolID& cld){fprintf_s(mFile,"connectAttr \"");cld.write(mFile);fprintf_s(mFile,"\" \"%s.cld\";\n",mName.c_str());}
	/*
	This allows one to adjust the quality collision sampling.
	larger values will help keep hairs from pushing through surfaces.
	*/
	void setCollideOverSample(int cos){if(cos == 0) return; fprintf_s(mFile, "setAttr \".cos\" %i;\n", cos);}
	/*
	This allows one to adjust the quality collision sampling.
	larger values will help keep hairs from pushing through surfaces.
	*/
	void setCollideOverSample(const IntID& cos){fprintf_s(mFile,"connectAttr \"");cos.write(mFile);fprintf_s(mFile,"\" \"%s.cos\";\n",mName.c_str());}
	/*If true then simulate hair/hair interaction.*/
	void setSelfCollide(bool scd){if(scd == false) return; fprintf_s(mFile, "setAttr \".scd\" %i;\n", scd);}
	/*If true then simulate hair/hair interaction.*/
	void setSelfCollide(const BoolID& scd){fprintf_s(mFile,"connectAttr \"");scd.write(mFile);fprintf_s(mFile,"\" \"%s.scd\";\n",mName.c_str());}
	/*
	If true then collide with an infinite plane at the ground height.
	This collision does not impact the speed of the solution, unlike geometry collisions.
	*/
	void setCollideGround(bool cdg){if(cdg == false) return; fprintf_s(mFile, "setAttr \".cdg\" %i;\n", cdg);}
	/*
	If true then collide with an infinite plane at the ground height.
	This collision does not impact the speed of the solution, unlike geometry collisions.
	*/
	void setCollideGround(const BoolID& cdg){fprintf_s(mFile,"connectAttr \"");cdg.write(mFile);fprintf_s(mFile,"\" \"%s.cdg\";\n",mName.c_str());}
	/*When collide ground is on, this determine the height of the ground plane.*/
	void setGroundHeight(double ghe){if(ghe == 0.0) return; fprintf_s(mFile, "setAttr \".ghe\" %f;\n", ghe);}
	/*When collide ground is on, this determine the height of the ground plane.*/
	void setGroundHeight(const DoubleID& ghe){fprintf_s(mFile,"connectAttr \"");ghe.write(mFile);fprintf_s(mFile,"\" \"%s.ghe\";\n",mName.c_str());}
	/*The amount the hair can flex with regard to the rest position.*/
	void setStiffness(double sfn){if(sfn == 0.15) return; fprintf_s(mFile, "setAttr \".sfn\" %f;\n", sfn);}
	/*The amount the hair can flex with regard to the rest position.*/
	void setStiffness(const DoubleID& sfn){fprintf_s(mFile,"connectAttr \"");sfn.write(mFile);fprintf_s(mFile,"\" \"%s.sfn\";\n",mName.c_str());}
	/*
	<b>Stiffness Scale</b> affects the stiffness from root to tip of the hair.
	The left of the graph is the root and the right is the tip. Typically the root of a
	hair is thicker and thus stiffer than the tip. This attribute multiplies
	the stiffness parameter value, so a value of 1.0 will leave the stiffness unchanged.
	If the stiffness attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	void setStiffnessScale(size_t sts_i,const StiffnessScale& sts){fprintf_s(mFile, "setAttr \".sts[%i]\" ",sts_i);sts.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Stiffness Scale</b> affects the stiffness from root to tip of the hair.
	The left of the graph is the root and the right is the tip. Typically the root of a
	hair is thicker and thus stiffer than the tip. This attribute multiplies
	the stiffness parameter value, so a value of 1.0 will leave the stiffness unchanged.
	If the stiffness attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	void setStiffnessScale(size_t sts_i,const StiffnessScaleID& sts){fprintf_s(mFile,"connectAttr \"");sts.write(mFile);fprintf_s(mFile,"\" \"%s.sts[%i]\";\n",mName.c_str(),sts_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setStiffnessScale_Position(size_t sts_i,float stsp){if(stsp == 0.0) return; fprintf_s(mFile, "setAttr \".sts[%i].stsp\" %f;\n", sts_i,stsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setStiffnessScale_Position(size_t sts_i,const FloatID& stsp){fprintf_s(mFile,"connectAttr \"");stsp.write(mFile);fprintf_s(mFile,"\" \"%s.sts[%i].stsp\";\n",mName.c_str(),sts_i);}
	/*Ramp value at the sibling position*/
	void setStiffnessScale_FloatValue(size_t sts_i,float stsfv){if(stsfv == 0.0) return; fprintf_s(mFile, "setAttr \".sts[%i].stsfv\" %f;\n", sts_i,stsfv);}
	/*Ramp value at the sibling position*/
	void setStiffnessScale_FloatValue(size_t sts_i,const FloatID& stsfv){fprintf_s(mFile,"connectAttr \"");stsfv.write(mFile);fprintf_s(mFile,"\" \"%s.sts[%i].stsfv\";\n",mName.c_str(),sts_i);}
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
	void setStiffnessScale_Interp(size_t sts_i,unsigned int stsi){if(stsi == 0) return; fprintf_s(mFile, "setAttr \".sts[%i].stsi\" %i;\n", sts_i,stsi);}
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
	void setStiffnessScale_Interp(size_t sts_i,const UnsignedintID& stsi){fprintf_s(mFile,"connectAttr \"");stsi.write(mFile);fprintf_s(mFile,"\" \"%s.sts[%i].stsi\";\n",mName.c_str(),sts_i);}
	/*The amount the hair can stretch along its length.*/
	void setLengthFlex(double lfx){if(lfx == 0.0) return; fprintf_s(mFile, "setAttr \".lfx\" %f;\n", lfx);}
	/*The amount the hair can stretch along its length.*/
	void setLengthFlex(const DoubleID& lfx){fprintf_s(mFile,"connectAttr \"");lfx.write(mFile);fprintf_s(mFile,"\" \"%s.lfx\";\n",mName.c_str());}
	/*
	This dampens the internal motions of individual hairs.
	It is particularily useful to help stabilize shaped hair when
	one has a defined rest position.
	*/
	void setDamp(double dmp){if(dmp == 0.0) return; fprintf_s(mFile, "setAttr \".dmp\" %f;\n", dmp);}
	/*
	This dampens the internal motions of individual hairs.
	It is particularily useful to help stabilize shaped hair when
	one has a defined rest position.
	*/
	void setDamp(const DoubleID& dmp){fprintf_s(mFile,"connectAttr \"");dmp.write(mFile);fprintf_s(mFile,"\" \"%s.dmp\";\n",mName.c_str());}
	/*This simulates friction with the air, in addition to helping to stabilize the simulation. When the damp is 1.0 the hair will behave as if it has no inertial motion or followthrough: it will move as if in a thick fluid.*/
	void setDrag(double drg){if(drg == 0.05) return; fprintf_s(mFile, "setAttr \".drg\" %f;\n", drg);}
	/*This simulates friction with the air, in addition to helping to stabilize the simulation. When the damp is 1.0 the hair will behave as if it has no inertial motion or followthrough: it will move as if in a thick fluid.*/
	void setDrag(const DoubleID& drg){fprintf_s(mFile,"connectAttr \"");drg.write(mFile);fprintf_s(mFile,"\" \"%s.drg\";\n",mName.c_str());}
	/*This simulates friction with on contact with other surfaces.*/
	void setFriction(double frc){if(frc == 0.5) return; fprintf_s(mFile, "setAttr \".frc\" %f;\n", frc);}
	/*This simulates friction with on contact with other surfaces.*/
	void setFriction(const DoubleID& frc){fprintf_s(mFile,"connectAttr \"");frc.write(mFile);fprintf_s(mFile,"\" \"%s.frc\";\n",mName.c_str());}
	/*
	This controls the simulated mass of the hair cvs. This currently will
	only show an effect if one applies external fields that consider mass, such as drag.
	*/
	void setMass(double mss){if(mss == 1.0) return; fprintf_s(mFile, "setAttr \".mss\" %f;\n", mss);}
	/*
	This controls the simulated mass of the hair cvs. This currently will
	only show an effect if one applies external fields that consider mass, such as drag.
	*/
	void setMass(const DoubleID& mss){fprintf_s(mFile,"connectAttr \"");mss.write(mFile);fprintf_s(mFile,"\" \"%s.mss\";\n",mName.c_str());}
	/*Scale factor for the effect of attached dynamic fields on the hair motion.*/
	void setDynamicsWeight(double dw){if(dw == 1.0) return; fprintf_s(mFile, "setAttr \".dw\" %f;\n", dw);}
	/*Scale factor for the effect of attached dynamic fields on the hair motion.*/
	void setDynamicsWeight(const DoubleID& dw){fprintf_s(mFile,"connectAttr \"");dw.write(mFile);fprintf_s(mFile,"\" \"%s.dw\";\n",mName.c_str());}
	/*
	This value is added to clumpWidths before determining collisions.
	The amount is relative to the clump width.
	It can be used to handle situations where there is some interpenetration,
	or where one has passive hairs that are outside the boundaries of active clumps.
	In cases where the hairs collide too far off an object, one can use negative values
	to allow a little interpenetration of clumps.
	*/
	void setCollideWidthOffset(double wid){if(wid == 0.0) return; fprintf_s(mFile, "setAttr \".wid\" %f;\n", wid);}
	/*
	This value is added to clumpWidths before determining collisions.
	The amount is relative to the clump width.
	It can be used to handle situations where there is some interpenetration,
	or where one has passive hairs that are outside the boundaries of active clumps.
	In cases where the hairs collide too far off an object, one can use negative values
	to allow a little interpenetration of clumps.
	*/
	void setCollideWidthOffset(const DoubleID& wid){fprintf_s(mFile,"connectAttr \"");wid.write(mFile);fprintf_s(mFile,"\" \"%s.wid\";\n",mName.c_str());}
	/*
	This value determines the amount of local attraction between
	self colliding hair clumps. It simulates static cling and friction
	between hair clumps. Self collide must be on for this to have an effect.
	Motion of masses of hair tend to be very damped due to the effects of
	self collision, friction and static. This can be helpful in achieving
	natural motion. Negative values can be used to make hairs repel from each other.
	*/
	void setStaticCling(double stc){if(stc == 0.0) return; fprintf_s(mFile, "setAttr \".stc\" %f;\n", stc);}
	/*
	This value determines the amount of local attraction between
	self colliding hair clumps. It simulates static cling and friction
	between hair clumps. Self collide must be on for this to have an effect.
	Motion of masses of hair tend to be very damped due to the effects of
	self collision, friction and static. This can be helpful in achieving
	natural motion. Negative values can be used to make hairs repel from each other.
	*/
	void setStaticCling(const DoubleID& stc){fprintf_s(mFile,"connectAttr \"");stc.write(mFile);fprintf_s(mFile,"\" \"%s.stc\";\n",mName.c_str());}
	/*
	This value determines the amount of repulsion when clumps are
	overlapping. When this is 1.0 clumps are pushed apart in a single timestep,
	although this may cause excessive motion in some cases, especially when clumps
	start out overlapping. Lowering this value can help damp such motion yet still
	preserve general body in the hair.
	*/
	void setRepulsion(double rpl){if(rpl == 0.5) return; fprintf_s(mFile, "setAttr \".rpl\" %f;\n", rpl);}
	/*
	This value determines the amount of repulsion when clumps are
	overlapping. When this is 1.0 clumps are pushed apart in a single timestep,
	although this may cause excessive motion in some cases, especially when clumps
	start out overlapping. Lowering this value can help damp such motion yet still
	preserve general body in the hair.
	*/
	void setRepulsion(const DoubleID& rpl){fprintf_s(mFile,"connectAttr \"");rpl.write(mFile);fprintf_s(mFile,"\" \"%s.rpl\";\n",mName.c_str());}
	/*
	This controls how many neighbor hairs to include in the self collision.
	Each hair clump with collide with the closest hairs( relative to the separation
	at the base of the hair on the start frame ). If this number is equal to the
	total number of clumps then all hairs will collide with all other hairs in
	the hair system, but the simulation will be slow.
	*/
	void setNumCollideNeighbors(int ncn){if(ncn == 4) return; fprintf_s(mFile, "setAttr \".ncn\" %i;\n", ncn);}
	/*
	This controls how many neighbor hairs to include in the self collision.
	Each hair clump with collide with the closest hairs( relative to the separation
	at the base of the hair on the start frame ). If this number is equal to the
	total number of clumps then all hairs will collide with all other hairs in
	the hair system, but the simulation will be slow.
	*/
	void setNumCollideNeighbors(const IntID& ncn){fprintf_s(mFile,"connectAttr \"");ncn.write(mFile);fprintf_s(mFile,"\" \"%s.ncn\";\n",mName.c_str());}
	/*
	This controls number of iterations per time step of the hair solver.
	This affects hair stiffness and length flex, as well as the accuracy of collisions.
	Large values are required for very high stiffness. Note that large value will also increase
	the time required by the solver
	*/
	void setIterations(int itr){if(itr == 4) return; fprintf_s(mFile, "setAttr \".itr\" %i;\n", itr);}
	/*
	This controls number of iterations per time step of the hair solver.
	This affects hair stiffness and length flex, as well as the accuracy of collisions.
	Large values are required for very high stiffness. Note that large value will also increase
	the time required by the solver
	*/
	void setIterations(const IntID& itr){fprintf_s(mFile,"connectAttr \"");itr.write(mFile);fprintf_s(mFile,"\" \"%s.itr\";\n",mName.c_str());}
	/*If true then draw circles around each line representing its width used for collision.*/
	void setDrawCollideWidth(bool dwd){if(dwd == false) return; fprintf_s(mFile, "setAttr \".dwd\" %i;\n", dwd);}
	/*If true then draw circles around each line representing its width used for collision.*/
	void setDrawCollideWidth(const BoolID& dwd){fprintf_s(mFile,"connectAttr \"");dwd.write(mFile);fprintf_s(mFile,"\" \"%s.dwd\";\n",mName.c_str());}
	/*
	This allows one to adjust the quality of the tube collide width drawing.
	A value of zero will cause a circle to be draw for every segment of
	the tube, which may clutter the display for tube with many segments.
	*/
	void setWidthDrawSkip(int wds){if(wds == 2) return; fprintf_s(mFile, "setAttr \".wds\" %i;\n", wds);}
	/*
	This allows one to adjust the quality of the tube collide width drawing.
	A value of zero will cause a circle to be draw for every segment of
	the tube, which may clutter the display for tube with many segments.
	*/
	void setWidthDrawSkip(const IntID& wds){fprintf_s(mFile,"connectAttr \"");wds.write(mFile);fprintf_s(mFile,"\" \"%s.wds\";\n",mName.c_str());}
	/*A built in downward force in y simulating gravity.*/
	void setGravity(double grv){if(grv == 0.98) return; fprintf_s(mFile, "setAttr \".grv\" %f;\n", grv);}
	/*A built in downward force in y simulating gravity.*/
	void setGravity(const DoubleID& grv){fprintf_s(mFile,"connectAttr \"");grv.write(mFile);fprintf_s(mFile,"\" \"%s.grv\";\n",mName.c_str());}
	/*
	Increasing this will increase the amount of force applied
	by the turbulence
	*/
	void setTurbulenceStrength(double tst){if(tst == 0) return; fprintf_s(mFile, "setAttr \".tst\" %f;\n", tst);}
	/*
	Increasing this will increase the amount of force applied
	by the turbulence
	*/
	void setTurbulenceStrength(const DoubleID& tst){fprintf_s(mFile,"connectAttr \"");tst.write(mFile);fprintf_s(mFile,"\" \"%s.tst\";\n",mName.c_str());}
	/*
	Lowering this will make the turbulence vortices larger. This
	is a spacial scale factor on the turbulence function and has
	no effect if the turbulence strength is zero.
	*/
	void setTurbulenceFrequency(double tfr){if(tfr == 0.2) return; fprintf_s(mFile, "setAttr \".tfr\" %f;\n", tfr);}
	/*
	Lowering this will make the turbulence vortices larger. This
	is a spacial scale factor on the turbulence function and has
	no effect if the turbulence strength is zero.
	*/
	void setTurbulenceFrequency(const DoubleID& tfr){fprintf_s(mFile,"connectAttr \"");tfr.write(mFile);fprintf_s(mFile,"\" \"%s.tfr\";\n",mName.c_str());}
	/*Rate at which turbulence pattern changes over time*/
	void setTurbulenceSpeed(double tbs){if(tbs == .2) return; fprintf_s(mFile, "setAttr \".tbs\" %f;\n", tbs);}
	/*Rate at which turbulence pattern changes over time*/
	void setTurbulenceSpeed(const DoubleID& tbs){fprintf_s(mFile,"connectAttr \"");tbs.write(mFile);fprintf_s(mFile,"\" \"%s.tbs\";\n",mName.c_str());}
	/*
	Attraction to the start curve is done by altering the
	current velocity of the hair so that it will meet the
	start position. This control damps out this value.
	When this value is one, the motion towards the start
	curve is fully damped leaving simply the start position
	plus field forces.  This is useful for applying fields on top
	of previously animated hairs.  To acheive this affect,
	you should set attractionDamp = 1.0 and make the stiffness
	ramp all 1.0.
	*/
	void setAttractionDamp(double ad){if(ad == 0.0) return; fprintf_s(mFile, "setAttr \".ad\" %f;\n", ad);}
	/*
	Attraction to the start curve is done by altering the
	current velocity of the hair so that it will meet the
	start position. This control damps out this value.
	When this value is one, the motion towards the start
	curve is fully damped leaving simply the start position
	plus field forces.  This is useful for applying fields on top
	of previously animated hairs.  To acheive this affect,
	you should set attractionDamp = 1.0 and make the stiffness
	ramp all 1.0.
	*/
	void setAttractionDamp(const DoubleID& ad){fprintf_s(mFile,"connectAttr \"");ad.write(mFile);fprintf_s(mFile,"\" \"%s.ad\";\n",mName.c_str());}
	/*
	This value determines the amount of attraction of the current hair
	position to the start position. Normally one would leave this at
	zero for long flowing hair. However for short hair it can be
	difficult to make hair stiff enough. This is good when the hair needs
	to be very stiff, and yet at the same time have some dynamic properties.
	At a value of one the hair position will be the start curve position(
	relative to the transformed follicle position ), only collisions and
	forces will still deflect the hair. Without startCurveAttract this
	could otherwise require a very high iteration count and damp value,
	especially if there are many cvs per hair.
	*/
	void setStartCurveAttract(double sct){if(sct == 0.0) return; fprintf_s(mFile, "setAttr \".sct\" %f;\n", sct);}
	/*
	This value determines the amount of attraction of the current hair
	position to the start position. Normally one would leave this at
	zero for long flowing hair. However for short hair it can be
	difficult to make hair stiff enough. This is good when the hair needs
	to be very stiff, and yet at the same time have some dynamic properties.
	At a value of one the hair position will be the start curve position(
	relative to the transformed follicle position ), only collisions and
	forces will still deflect the hair. Without startCurveAttract this
	could otherwise require a very high iteration count and damp value,
	especially if there are many cvs per hair.
	*/
	void setStartCurveAttract(const DoubleID& sct){fprintf_s(mFile,"connectAttr \"");sct.write(mFile);fprintf_s(mFile,"\" \"%s.sct\";\n",mName.c_str());}
	/*
	This value attenuates the startCurveAttract value along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	If the startCurveAttract attribute is zero then this parameter will have no effect,
	as zero times a number is always zero.
	*/
	void setAttractionScale(size_t ats_i,const AttractionScale& ats){fprintf_s(mFile, "setAttr \".ats[%i]\" ",ats_i);ats.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This value attenuates the startCurveAttract value along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	If the startCurveAttract attribute is zero then this parameter will have no effect,
	as zero times a number is always zero.
	*/
	void setAttractionScale(size_t ats_i,const AttractionScaleID& ats){fprintf_s(mFile,"connectAttr \"");ats.write(mFile);fprintf_s(mFile,"\" \"%s.ats[%i]\";\n",mName.c_str(),ats_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setAttractionScale_Position(size_t ats_i,float atsp){if(atsp == 0.0) return; fprintf_s(mFile, "setAttr \".ats[%i].atsp\" %f;\n", ats_i,atsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setAttractionScale_Position(size_t ats_i,const FloatID& atsp){fprintf_s(mFile,"connectAttr \"");atsp.write(mFile);fprintf_s(mFile,"\" \"%s.ats[%i].atsp\";\n",mName.c_str(),ats_i);}
	/*Ramp value at the sibling position*/
	void setAttractionScale_FloatValue(size_t ats_i,float atsfv){if(atsfv == 0.0) return; fprintf_s(mFile, "setAttr \".ats[%i].atsfv\" %f;\n", ats_i,atsfv);}
	/*Ramp value at the sibling position*/
	void setAttractionScale_FloatValue(size_t ats_i,const FloatID& atsfv){fprintf_s(mFile,"connectAttr \"");atsfv.write(mFile);fprintf_s(mFile,"\" \"%s.ats[%i].atsfv\";\n",mName.c_str(),ats_i);}
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
	void setAttractionScale_Interp(size_t ats_i,unsigned int atsi){if(atsi == 0) return; fprintf_s(mFile, "setAttr \".ats[%i].atsi\" %i;\n", ats_i,atsi);}
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
	void setAttractionScale_Interp(size_t ats_i,const UnsignedintID& atsi){fprintf_s(mFile,"connectAttr \"");atsi.write(mFile);fprintf_s(mFile,"\" \"%s.ats[%i].atsi\";\n",mName.c_str(),ats_i);}
	/*
	This value determines the amount the current hair
	is damped relative to the transform of the follicle.
	If this value is 1 then the hair will fully move with the
	follicle, but its shape can still be changed by other forces.
	Unlike startCurveAttract which makes the hair like a stiff spring
	this pushes the hair with the motion of the follicle, but allows
	it to change shape. It is as if there is a block of air or mud
	(depending on the motion damp intensity) that moves with the follicle
	and tends to drag the hair with it. The normal drag attribute
	instead drags relative to zero motion, rather than the motion
	of the follicle base. This is useful in making hair stiff with fewer
	iterations and it can simulate the combination of self collision of
	hairs along with friction and trapped air. The relative range of
	affect along the hairs for motion drag is scaled by the stiffness ramp.
	It looks most natural when there is more drag at the base.
	*/
	void setMotionDrag(double mdg){if(mdg == 0.0) return; fprintf_s(mFile, "setAttr \".mdg\" %f;\n", mdg);}
	/*
	This value determines the amount the current hair
	is damped relative to the transform of the follicle.
	If this value is 1 then the hair will fully move with the
	follicle, but its shape can still be changed by other forces.
	Unlike startCurveAttract which makes the hair like a stiff spring
	this pushes the hair with the motion of the follicle, but allows
	it to change shape. It is as if there is a block of air or mud
	(depending on the motion damp intensity) that moves with the follicle
	and tends to drag the hair with it. The normal drag attribute
	instead drags relative to zero motion, rather than the motion
	of the follicle base. This is useful in making hair stiff with fewer
	iterations and it can simulate the combination of self collision of
	hairs along with friction and trapped air. The relative range of
	affect along the hairs for motion drag is scaled by the stiffness ramp.
	It looks most natural when there is more drag at the base.
	*/
	void setMotionDrag(const DoubleID& mdg){fprintf_s(mFile,"connectAttr \"");mdg.write(mFile);fprintf_s(mFile,"\" \"%s.mdg\";\n",mName.c_str());}
	/*
	percentage of hairs within clumps to display for interactive draw
	This corresponds to the display quality on paint effects strokes.
	*/
	void setDisplayQuality(double dpq){if(dpq == 100.0) return; fprintf_s(mFile, "setAttr \".dpq\" %f;\n", dpq);}
	/*
	percentage of hairs within clumps to display for interactive draw
	This corresponds to the display quality on paint effects strokes.
	*/
	void setDisplayQuality(const DoubleID& dpq){fprintf_s(mFile,"connectAttr \"");dpq.write(mFile);fprintf_s(mFile,"\" \"%s.dpq\";\n",mName.c_str());}
	/*
	If true then fix the length of the output hairs to be constant.
	The internal dynamic hairs will still stretch, but the output
	hair will be locked to the base point. Care should be taken
	when using this attribute. If the lengthFlex is
	low or the iterations are low then the dynamic computed hair
	may protrude much beyond the end of the rendered hair, and the
	behavior could look unnatural.
	*/
	void setNoStretch(bool nst){if(nst == false) return; fprintf_s(mFile, "setAttr \".nst\" %i;\n", nst);}
	/*
	If true then fix the length of the output hairs to be constant.
	The internal dynamic hairs will still stretch, but the output
	hair will be locked to the base point. Care should be taken
	when using this attribute. If the lengthFlex is
	low or the iterations are low then the dynamic computed hair
	may protrude much beyond the end of the rendered hair, and the
	behavior could look unnatural.
	*/
	void setNoStretch(const BoolID& nst){fprintf_s(mFile,"connectAttr \"");nst.write(mFile);fprintf_s(mFile,"\" \"%s.nst\";\n",mName.c_str());}
	/*
	This determines the number of smoothly interpolated segments at render time.
	The hermite interpolation smooths the shape of the line, in addition to providing
	more detail for curls and fine features. The added segments affect the rendered look only,
	and do not affect the dynamic simulation.
	*/
	void setSubSegments(int ssg){if(ssg == 0) return; fprintf_s(mFile, "setAttr \".ssg\" %i;\n", ssg);}
	/*
	This determines the number of smoothly interpolated segments at render time.
	The hermite interpolation smooths the shape of the line, in addition to providing
	more detail for curls and fine features. The added segments affect the rendered look only,
	and do not affect the dynamic simulation.
	*/
	void setSubSegments(const IntID& ssg){fprintf_s(mFile,"connectAttr \"");ssg.write(mFile);fprintf_s(mFile,"\" \"%s.ssg\";\n",mName.c_str());}
	/*This is the base or maximum width for the dynamic hair groups.*/
	void setClumpWidth(double cwd){if(cwd == 0.3) return; fprintf_s(mFile, "setAttr \".cwd\" %f;\n", cwd);}
	/*This is the base or maximum width for the dynamic hair groups.*/
	void setClumpWidth(const DoubleID& cwd){fprintf_s(mFile,"connectAttr \"");cwd.write(mFile);fprintf_s(mFile,"\" \"%s.cwd\";\n",mName.c_str());}
	/*
	<b>Clump Width Scale</b> affects the width from root to tip of the hair clump.
	The left of the graph is the root and the right is the tip.
	Often one may wish the hairs within the clump to come to a tip at the end of the clump,
	in which case the right value should be smaller than the left. This attribute multiplies
	the clumpWidth parameter value, so a value of 1.0 will leave the clumpWidth unchanged.
	If the clumpWidth attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	void setClumpWidthScale(size_t cws_i,const ClumpWidthScale& cws){fprintf_s(mFile, "setAttr \".cws[%i]\" ",cws_i);cws.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Clump Width Scale</b> affects the width from root to tip of the hair clump.
	The left of the graph is the root and the right is the tip.
	Often one may wish the hairs within the clump to come to a tip at the end of the clump,
	in which case the right value should be smaller than the left. This attribute multiplies
	the clumpWidth parameter value, so a value of 1.0 will leave the clumpWidth unchanged.
	If the clumpWidth attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	void setClumpWidthScale(size_t cws_i,const ClumpWidthScaleID& cws){fprintf_s(mFile,"connectAttr \"");cws.write(mFile);fprintf_s(mFile,"\" \"%s.cws[%i]\";\n",mName.c_str(),cws_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setClumpWidthScale_Position(size_t cws_i,float cwsp){if(cwsp == 0.0) return; fprintf_s(mFile, "setAttr \".cws[%i].cwsp\" %f;\n", cws_i,cwsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setClumpWidthScale_Position(size_t cws_i,const FloatID& cwsp){fprintf_s(mFile,"connectAttr \"");cwsp.write(mFile);fprintf_s(mFile,"\" \"%s.cws[%i].cwsp\";\n",mName.c_str(),cws_i);}
	/*Ramp value at the sibling position*/
	void setClumpWidthScale_FloatValue(size_t cws_i,float cwsfv){if(cwsfv == 0.0) return; fprintf_s(mFile, "setAttr \".cws[%i].cwsfv\" %f;\n", cws_i,cwsfv);}
	/*Ramp value at the sibling position*/
	void setClumpWidthScale_FloatValue(size_t cws_i,const FloatID& cwsfv){fprintf_s(mFile,"connectAttr \"");cwsfv.write(mFile);fprintf_s(mFile,"\" \"%s.cws[%i].cwsfv\";\n",mName.c_str(),cws_i);}
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
	void setClumpWidthScale_Interp(size_t cws_i,unsigned int cwsi){if(cwsi == 0) return; fprintf_s(mFile, "setAttr \".cws[%i].cwsi\" %i;\n", cws_i,cwsi);}
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
	void setClumpWidthScale_Interp(size_t cws_i,const UnsignedintID& cwsi){fprintf_s(mFile,"connectAttr \"");cwsi.write(mFile);fprintf_s(mFile,"\" \"%s.cws[%i].cwsi\";\n",mName.c_str(),cws_i);}
	/*This is the rotation of the clump group about the primary hair axis.*/
	void setClumpTwist(double ctw){if(ctw == 0.0) return; fprintf_s(mFile, "setAttr \".ctw\" %f;\n", ctw);}
	/*This is the rotation of the clump group about the primary hair axis.*/
	void setClumpTwist(const DoubleID& ctw){fprintf_s(mFile,"connectAttr \"");ctw.write(mFile);fprintf_s(mFile,"\" \"%s.ctw\";\n",mName.c_str());}
	/*
	<b>Clump Curl</b> controls the rate of curling about the primary axis of each hair clump.
	The left of the graph is the root and the right is the tip.
	The mid value of the ramp(0.5) represents no twist while values greater than that will result
	in positive twisting while smaller values will cause twisting in the reverse direction.
	*/
	void setClumpCurl(size_t clc_i,const ClumpCurl& clc){fprintf_s(mFile, "setAttr \".clc[%i]\" ",clc_i);clc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Clump Curl</b> controls the rate of curling about the primary axis of each hair clump.
	The left of the graph is the root and the right is the tip.
	The mid value of the ramp(0.5) represents no twist while values greater than that will result
	in positive twisting while smaller values will cause twisting in the reverse direction.
	*/
	void setClumpCurl(size_t clc_i,const ClumpCurlID& clc){fprintf_s(mFile,"connectAttr \"");clc.write(mFile);fprintf_s(mFile,"\" \"%s.clc[%i]\";\n",mName.c_str(),clc_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setClumpCurl_Position(size_t clc_i,float clcp){if(clcp == 0.0) return; fprintf_s(mFile, "setAttr \".clc[%i].clcp\" %f;\n", clc_i,clcp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setClumpCurl_Position(size_t clc_i,const FloatID& clcp){fprintf_s(mFile,"connectAttr \"");clcp.write(mFile);fprintf_s(mFile,"\" \"%s.clc[%i].clcp\";\n",mName.c_str(),clc_i);}
	/*Ramp value at the sibling position*/
	void setClumpCurl_FloatValue(size_t clc_i,float clcfv){if(clcfv == 0.0) return; fprintf_s(mFile, "setAttr \".clc[%i].clcfv\" %f;\n", clc_i,clcfv);}
	/*Ramp value at the sibling position*/
	void setClumpCurl_FloatValue(size_t clc_i,const FloatID& clcfv){fprintf_s(mFile,"connectAttr \"");clcfv.write(mFile);fprintf_s(mFile,"\" \"%s.clc[%i].clcfv\";\n",mName.c_str(),clc_i);}
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
	void setClumpCurl_Interp(size_t clc_i,unsigned int clci){if(clci == 0) return; fprintf_s(mFile, "setAttr \".clc[%i].clci\" %i;\n", clc_i,clci);}
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
	void setClumpCurl_Interp(size_t clc_i,const UnsignedintID& clci){fprintf_s(mFile,"connectAttr \"");clci.write(mFile);fprintf_s(mFile,"\" \"%s.clc[%i].clci\";\n",mName.c_str(),clc_i);}
	/*
	<b>Clump Flatness</b> affects the flatness of the clump group from root to tip.
	The left of the graph is the root and the right is the tip.
	*/
	void setClumpFlatness(size_t cfl_i,const ClumpFlatness& cfl){fprintf_s(mFile, "setAttr \".cfl[%i]\" ",cfl_i);cfl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Clump Flatness</b> affects the flatness of the clump group from root to tip.
	The left of the graph is the root and the right is the tip.
	*/
	void setClumpFlatness(size_t cfl_i,const ClumpFlatnessID& cfl){fprintf_s(mFile,"connectAttr \"");cfl.write(mFile);fprintf_s(mFile,"\" \"%s.cfl[%i]\";\n",mName.c_str(),cfl_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setClumpFlatness_Position(size_t cfl_i,float cflp){if(cflp == 0.0) return; fprintf_s(mFile, "setAttr \".cfl[%i].cflp\" %f;\n", cfl_i,cflp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setClumpFlatness_Position(size_t cfl_i,const FloatID& cflp){fprintf_s(mFile,"connectAttr \"");cflp.write(mFile);fprintf_s(mFile,"\" \"%s.cfl[%i].cflp\";\n",mName.c_str(),cfl_i);}
	/*Ramp value at the sibling position*/
	void setClumpFlatness_FloatValue(size_t cfl_i,float cflfv){if(cflfv == 0.0) return; fprintf_s(mFile, "setAttr \".cfl[%i].cflfv\" %f;\n", cfl_i,cflfv);}
	/*Ramp value at the sibling position*/
	void setClumpFlatness_FloatValue(size_t cfl_i,const FloatID& cflfv){fprintf_s(mFile,"connectAttr \"");cflfv.write(mFile);fprintf_s(mFile,"\" \"%s.cfl[%i].cflfv\";\n",mName.c_str(),cfl_i);}
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
	void setClumpFlatness_Interp(size_t cfl_i,unsigned int cfli){if(cfli == 0) return; fprintf_s(mFile, "setAttr \".cfl[%i].cfli\" %i;\n", cfl_i,cfli);}
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
	void setClumpFlatness_Interp(size_t cfl_i,const UnsignedintID& cfli){fprintf_s(mFile,"connectAttr \"");cfli.write(mFile);fprintf_s(mFile,"\" \"%s.cfl[%i].cfli\";\n",mName.c_str(),cfl_i);}
	/*
	This determines how much the rotation of the overall clump
	follows the primary hair axis. Short straight fur may work better
	with this value near zero, as the end of wide clumps will blend better
	when they twist. With this value at 1.0 the cross section of the
	hair clump will always be perpendicular to the tube direction,
	which can work well for long relatively thin clumps.  When this
	value is zero the cross section is always perpendicular to the
	surface normal at the start of the hair clump.
	*/
	void setBendFollow(double bnf){if(bnf == 1.0) return; fprintf_s(mFile, "setAttr \".bnf\" %f;\n", bnf);}
	/*
	This determines how much the rotation of the overall clump
	follows the primary hair axis. Short straight fur may work better
	with this value near zero, as the end of wide clumps will blend better
	when they twist. With this value at 1.0 the cross section of the
	hair clump will always be perpendicular to the tube direction,
	which can work well for long relatively thin clumps.  When this
	value is zero the cross section is always perpendicular to the
	surface normal at the start of the hair clump.
	*/
	void setBendFollow(const DoubleID& bnf){fprintf_s(mFile,"connectAttr \"");bnf.write(mFile);fprintf_s(mFile,"\" \"%s.bnf\";\n",mName.c_str());}
	/*This is the global width for hairs.*/
	void setHairWidth(double hwd){if(hwd == 0.01) return; fprintf_s(mFile, "setAttr \".hwd\" %f;\n", hwd);}
	/*This is the global width for hairs.*/
	void setHairWidth(const DoubleID& hwd){fprintf_s(mFile,"connectAttr \"");hwd.write(mFile);fprintf_s(mFile,"\" \"%s.hwd\";\n",mName.c_str());}
	/*
	<b>Hair Width Scale</b> affects the width from root to tip of the hairs.
	The left of the graph is the root and the right is the tip.
	This attribute multiplies the hairWidth parameter value, so a value of 1.0
	will leave the hairWidth unchanged.
	If the hairWidth attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	void setHairWidthScale(size_t hws_i,const HairWidthScale& hws){fprintf_s(mFile, "setAttr \".hws[%i]\" ",hws_i);hws.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Hair Width Scale</b> affects the width from root to tip of the hairs.
	The left of the graph is the root and the right is the tip.
	This attribute multiplies the hairWidth parameter value, so a value of 1.0
	will leave the hairWidth unchanged.
	If the hairWidth attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	void setHairWidthScale(size_t hws_i,const HairWidthScaleID& hws){fprintf_s(mFile,"connectAttr \"");hws.write(mFile);fprintf_s(mFile,"\" \"%s.hws[%i]\";\n",mName.c_str(),hws_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setHairWidthScale_Position(size_t hws_i,float hwsp){if(hwsp == 0.0) return; fprintf_s(mFile, "setAttr \".hws[%i].hwsp\" %f;\n", hws_i,hwsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setHairWidthScale_Position(size_t hws_i,const FloatID& hwsp){fprintf_s(mFile,"connectAttr \"");hwsp.write(mFile);fprintf_s(mFile,"\" \"%s.hws[%i].hwsp\";\n",mName.c_str(),hws_i);}
	/*Ramp value at the sibling position*/
	void setHairWidthScale_FloatValue(size_t hws_i,float hwsfv){if(hwsfv == 0.0) return; fprintf_s(mFile, "setAttr \".hws[%i].hwsfv\" %f;\n", hws_i,hwsfv);}
	/*Ramp value at the sibling position*/
	void setHairWidthScale_FloatValue(size_t hws_i,const FloatID& hwsfv){fprintf_s(mFile,"connectAttr \"");hwsfv.write(mFile);fprintf_s(mFile,"\" \"%s.hws[%i].hwsfv\";\n",mName.c_str(),hws_i);}
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
	void setHairWidthScale_Interp(size_t hws_i,unsigned int hwsi){if(hwsi == 0) return; fprintf_s(mFile, "setAttr \".hws[%i].hwsi\" %i;\n", hws_i,hwsi);}
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
	void setHairWidthScale_Interp(size_t hws_i,const UnsignedintID& hwsi){fprintf_s(mFile,"connectAttr \"");hwsi.write(mFile);fprintf_s(mFile,"\" \"%s.hws[%i].hwsi\";\n",mName.c_str(),hws_i);}
	/*
	This reduces the hair density using a texture. The texture
	used must be a 2D texture.
	*/
	void setBaldnessMap(double bmp){if(bmp == 1.0) return; fprintf_s(mFile, "setAttr \".bmp\" %f;\n", bmp);}
	/*
	This reduces the hair density using a texture. The texture
	used must be a 2D texture.
	*/
	void setBaldnessMap(const DoubleID& bmp){fprintf_s(mFile,"connectAttr \"");bmp.write(mFile);fprintf_s(mFile,"\" \"%s.bmp\";\n",mName.c_str());}
	/*
	This controls the overall transparency of the hair.
	A value of 0 is fully transparent and 1 is fully opaque.
	*/
	void setOpacity(double opc){if(opc == 1.0) return; fprintf_s(mFile, "setAttr \".opc\" %f;\n", opc);}
	/*
	This controls the overall transparency of the hair.
	A value of 0 is fully transparent and 1 is fully opaque.
	*/
	void setOpacity(const DoubleID& opc){fprintf_s(mFile,"connectAttr \"");opc.write(mFile);fprintf_s(mFile,"\" \"%s.opc\";\n",mName.c_str());}
	/*
	Base color for hairs. The final color used is determined
	after the hairColorScale and randomization parameters are applied.
	Also individual hair clumps may override the hairColor.
	*/
	void setHairColor(const float3& hcl){fprintf_s(mFile, "setAttr \".hcl\" -type \"float3\" ");hcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Base color for hairs. The final color used is determined
	after the hairColorScale and randomization parameters are applied.
	Also individual hair clumps may override the hairColor.
	*/
	void setHairColor(const Float3ID& hcl){fprintf_s(mFile,"connectAttr \"");hcl.write(mFile);fprintf_s(mFile,"\" \"%s.hcl\";\n",mName.c_str());}
	/*hair Red value*/
	void setHairColorR(float hcr){if(hcr == 0.3) return; fprintf_s(mFile, "setAttr \".hcl.hcr\" %f;\n", hcr);}
	/*hair Red value*/
	void setHairColorR(const FloatID& hcr){fprintf_s(mFile,"connectAttr \"");hcr.write(mFile);fprintf_s(mFile,"\" \"%s.hcl.hcr\";\n",mName.c_str());}
	/*hair Green value*/
	void setHairColorG(float hcg){if(hcg == 0.25) return; fprintf_s(mFile, "setAttr \".hcl.hcg\" %f;\n", hcg);}
	/*hair Green value*/
	void setHairColorG(const FloatID& hcg){fprintf_s(mFile,"connectAttr \"");hcg.write(mFile);fprintf_s(mFile,"\" \"%s.hcl.hcg\";\n",mName.c_str());}
	/*hair Blue value*/
	void setHairColorB(float hcb){if(hcb == 0.15) return; fprintf_s(mFile, "setAttr \".hcl.hcb\" %f;\n", hcb);}
	/*hair Blue value*/
	void setHairColorB(const FloatID& hcb){fprintf_s(mFile,"connectAttr \"");hcb.write(mFile);fprintf_s(mFile,"\" \"%s.hcl.hcb\";\n",mName.c_str());}
	/*
	<b>Hair Color</b> defines the global color of the hairs from root to tip.
	The left of the graph is the root and the right is the tip.
	*/
	void setHairColorScale(size_t hcs_i,const HairColorScale& hcs){fprintf_s(mFile, "setAttr \".hcs[%i]\" ",hcs_i);hcs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Hair Color</b> defines the global color of the hairs from root to tip.
	The left of the graph is the root and the right is the tip.
	*/
	void setHairColorScale(size_t hcs_i,const HairColorScaleID& hcs){fprintf_s(mFile,"connectAttr \"");hcs.write(mFile);fprintf_s(mFile,"\" \"%s.hcs[%i]\";\n",mName.c_str(),hcs_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setHairColorScale_Position(size_t hcs_i,float hcsp){if(hcsp == 0.0) return; fprintf_s(mFile, "setAttr \".hcs[%i].hcsp\" %f;\n", hcs_i,hcsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setHairColorScale_Position(size_t hcs_i,const FloatID& hcsp){fprintf_s(mFile,"connectAttr \"");hcsp.write(mFile);fprintf_s(mFile,"\" \"%s.hcs[%i].hcsp\";\n",mName.c_str(),hcs_i);}
	/*Ramp color at the sibling position*/
	void setHairColorScale_Color(size_t hcs_i,const float3& hcsc){fprintf_s(mFile, "setAttr \".hcs[%i].hcsc\" -type \"float3\" ",hcs_i);hcsc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setHairColorScale_Color(size_t hcs_i,const Float3ID& hcsc){fprintf_s(mFile,"connectAttr \"");hcsc.write(mFile);fprintf_s(mFile,"\" \"%s.hcs[%i].hcsc\";\n",mName.c_str(),hcs_i);}
	/*Ramp red channel value at the sibling position*/
	void setHairColorScale_ColorR(size_t hcs_i,float hcscr){if(hcscr == 0.0) return; fprintf_s(mFile, "setAttr \".hcs[%i].hcsc.hcscr\" %f;\n", hcs_i,hcscr);}
	/*Ramp red channel value at the sibling position*/
	void setHairColorScale_ColorR(size_t hcs_i,const FloatID& hcscr){fprintf_s(mFile,"connectAttr \"");hcscr.write(mFile);fprintf_s(mFile,"\" \"%s.hcs[%i].hcsc.hcscr\";\n",mName.c_str(),hcs_i);}
	/*Ramp green channel value at the sibling position*/
	void setHairColorScale_ColorG(size_t hcs_i,float hcscg){if(hcscg == 0.0) return; fprintf_s(mFile, "setAttr \".hcs[%i].hcsc.hcscg\" %f;\n", hcs_i,hcscg);}
	/*Ramp green channel value at the sibling position*/
	void setHairColorScale_ColorG(size_t hcs_i,const FloatID& hcscg){fprintf_s(mFile,"connectAttr \"");hcscg.write(mFile);fprintf_s(mFile,"\" \"%s.hcs[%i].hcsc.hcscg\";\n",mName.c_str(),hcs_i);}
	/*Ramp blue channel value at the sibling position*/
	void setHairColorScale_ColorB(size_t hcs_i,float hcscb){if(hcscb == 0.0) return; fprintf_s(mFile, "setAttr \".hcs[%i].hcsc.hcscb\" %f;\n", hcs_i,hcscb);}
	/*Ramp blue channel value at the sibling position*/
	void setHairColorScale_ColorB(size_t hcs_i,const FloatID& hcscb){fprintf_s(mFile,"connectAttr \"");hcscb.write(mFile);fprintf_s(mFile,"\" \"%s.hcs[%i].hcsc.hcscb\";\n",mName.c_str(),hcs_i);}
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
	void setHairColorScale_Interp(size_t hcs_i,unsigned int hcsi){if(hcsi == 0) return; fprintf_s(mFile, "setAttr \".hcs[%i].hcsi\" %i;\n", hcs_i,hcsi);}
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
	void setHairColorScale_Interp(size_t hcs_i,const UnsignedintID& hcsi){fprintf_s(mFile,"connectAttr \"");hcsi.write(mFile);fprintf_s(mFile,"\" \"%s.hcs[%i].hcsi\";\n",mName.c_str(),hcs_i);}
	/*This is the number of hairs rendered for each current position hair curve.*/
	void setHairsPerClump(int hpc){if(hpc == 10) return; fprintf_s(mFile, "setAttr \".hpc\" %i;\n", hpc);}
	/*This is the number of hairs rendered for each current position hair curve.*/
	void setHairsPerClump(const IntID& hpc){fprintf_s(mFile,"connectAttr \"");hpc.write(mFile);fprintf_s(mFile,"\" \"%s.hpc\";\n",mName.c_str());}
	/*This controls the proportion of shorter length hairs.*/
	void setThinning(double thn){if(thn == 0.0) return; fprintf_s(mFile, "setAttr \".thn\" %f;\n", thn);}
	/*This controls the proportion of shorter length hairs.*/
	void setThinning(const DoubleID& thn){fprintf_s(mFile,"connectAttr \"");thn.write(mFile);fprintf_s(mFile,"\" \"%s.thn\";\n",mName.c_str());}
	/*This allows light to filter through hair for a softer effect.*/
	void setTranslucence(double tlc){if(tlc == 0.5) return; fprintf_s(mFile, "setAttr \".tlc\" %f;\n", tlc);}
	/*This allows light to filter through hair for a softer effect.*/
	void setTranslucence(const DoubleID& tlc){fprintf_s(mFile,"connectAttr \"");tlc.write(mFile);fprintf_s(mFile,"\" \"%s.tlc\";\n",mName.c_str());}
	/*input color for specular highlights*/
	void setSpecularColor(const float3& spc){fprintf_s(mFile, "setAttr \".spc\" -type \"float3\" ");spc.write(mFile);fprintf_s(mFile,";\n");}
	/*input color for specular highlights*/
	void setSpecularColor(const Float3ID& spc){fprintf_s(mFile,"connectAttr \"");spc.write(mFile);fprintf_s(mFile,"\" \"%s.spc\";\n",mName.c_str());}
	/*specular Red value*/
	void setSpecularColorR(float spr){if(spr == 0.35) return; fprintf_s(mFile, "setAttr \".spc.spr\" %f;\n", spr);}
	/*specular Red value*/
	void setSpecularColorR(const FloatID& spr){fprintf_s(mFile,"connectAttr \"");spr.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spr\";\n",mName.c_str());}
	/*specular Green value*/
	void setSpecularColorG(float spg){if(spg == 0.35) return; fprintf_s(mFile, "setAttr \".spc.spg\" %f;\n", spg);}
	/*specular Green value*/
	void setSpecularColorG(const FloatID& spg){fprintf_s(mFile,"connectAttr \"");spg.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spg\";\n",mName.c_str());}
	/*specular Blue value*/
	void setSpecularColorB(float spb){if(spb == 0.3) return; fprintf_s(mFile, "setAttr \".spc.spb\" %f;\n", spb);}
	/*specular Blue value*/
	void setSpecularColorB(const FloatID& spb){fprintf_s(mFile,"connectAttr \"");spb.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spb\";\n",mName.c_str());}
	/*This allows light to filter through hair for a softer effect.*/
	void setSpecularPower(double spp){if(spp == 3.0) return; fprintf_s(mFile, "setAttr \".spp\" %f;\n", spp);}
	/*This allows light to filter through hair for a softer effect.*/
	void setSpecularPower(const DoubleID& spp){fprintf_s(mFile,"connectAttr \"");spp.write(mFile);fprintf_s(mFile,"\" \"%s.spp\";\n",mName.c_str());}
	/*This causes the hair to cast shadows(depthmap only).*/
	void setCastShadows(bool csd){if(csd == true) return; fprintf_s(mFile, "setAttr \".csd\" %i;\n", csd);}
	/*This causes the hair to cast shadows(depthmap only).*/
	void setCastShadows(const BoolID& csd){fprintf_s(mFile,"connectAttr \"");csd.write(mFile);fprintf_s(mFile,"\" \"%s.csd\";\n",mName.c_str());}
	/*a diffuse brightness randomization between hairs in a clump*/
	void setDiffuseRand(double dfr){if(dfr == 0.2) return; fprintf_s(mFile, "setAttr \".dfr\" %f;\n", dfr);}
	/*a diffuse brightness randomization between hairs in a clump*/
	void setDiffuseRand(const DoubleID& dfr){fprintf_s(mFile,"connectAttr \"");dfr.write(mFile);fprintf_s(mFile,"\" \"%s.dfr\";\n",mName.c_str());}
	/*a specular brightness randomization between hairs in a clump*/
	void setSpecularRand(double sra){if(sra == 0.4) return; fprintf_s(mFile, "setAttr \".sra\" %f;\n", sra);}
	/*a specular brightness randomization between hairs in a clump*/
	void setSpecularRand(const DoubleID& sra){fprintf_s(mFile,"connectAttr \"");sra.write(mFile);fprintf_s(mFile,"\" \"%s.sra\";\n",mName.c_str());}
	/*random deviation in hue of hairs*/
	void setHueRand(double chr){if(chr == 0.0) return; fprintf_s(mFile, "setAttr \".chr\" %f;\n", chr);}
	/*random deviation in hue of hairs*/
	void setHueRand(const DoubleID& chr){fprintf_s(mFile,"connectAttr \"");chr.write(mFile);fprintf_s(mFile,"\" \"%s.chr\";\n",mName.c_str());}
	/*random deviation in color saturation of hairs*/
	void setSatRand(double csr){if(csr == 0.0) return; fprintf_s(mFile, "setAttr \".csr\" %f;\n", csr);}
	/*random deviation in color saturation of hairs*/
	void setSatRand(const DoubleID& csr){fprintf_s(mFile,"connectAttr \"");csr.write(mFile);fprintf_s(mFile,"\" \"%s.csr\";\n",mName.c_str());}
	/*random deviation in brighness value of hairs*/
	void setValRand(double cvr){if(cvr == 0.0) return; fprintf_s(mFile, "setAttr \".cvr\" %f;\n", cvr);}
	/*random deviation in brighness value of hairs*/
	void setValRand(const DoubleID& cvr){fprintf_s(mFile,"connectAttr \"");cvr.write(mFile);fprintf_s(mFile,"\" \"%s.cvr\";\n",mName.c_str());}
	/*
	<b>Multi Streaks</b> is the number of added sub hairs for each hair in a clump.
	These hairs will share the same shape and shading as the base hair they are
	derived from. They are created at render time and are simple duplicates,
	and thus do not take up any shape computation. This allows one to have a
	great number of tubes and yet render them in a reasonable amount of time.
	*/
	void setMultiStreaks(int mst){if(mst == 0) return; fprintf_s(mFile, "setAttr \".mst\" %i;\n", mst);}
	/*
	<b>Multi Streaks</b> is the number of added sub hairs for each hair in a clump.
	These hairs will share the same shape and shading as the base hair they are
	derived from. They are created at render time and are simple duplicates,
	and thus do not take up any shape computation. This allows one to have a
	great number of tubes and yet render them in a reasonable amount of time.
	*/
	void setMultiStreaks(const IntID& mst){fprintf_s(mFile,"connectAttr \"");mst.write(mFile);fprintf_s(mFile,"\" \"%s.mst\";\n",mName.c_str());}
	/*the maximum offset for added hairs relative to the clump width*/
	void setMultiStreakSpread1(double ms1){if(ms1 == 0.3) return; fprintf_s(mFile, "setAttr \".ms1\" %f;\n", ms1);}
	/*the maximum offset for added hairs relative to the clump width*/
	void setMultiStreakSpread1(const DoubleID& ms1){fprintf_s(mFile,"connectAttr \"");ms1.write(mFile);fprintf_s(mFile,"\" \"%s.ms1\";\n",mName.c_str());}
	/*the maximum offset for added tubes relative to the clump width at the tube tip*/
	void setMultiStreakSpread2(double ms2){if(ms2 == 0.1) return; fprintf_s(mFile, "setAttr \".ms2\" %f;\n", ms2);}
	/*the maximum offset for added tubes relative to the clump width at the tube tip*/
	void setMultiStreakSpread2(const DoubleID& ms2){fprintf_s(mFile,"connectAttr \"");ms2.write(mFile);fprintf_s(mFile,"\" \"%s.ms2\";\n",mName.c_str());}
	/*
	Render times can be much faster if we share the same illumination for each hair
	in a multiStreak.
	If the multiStreak spread is relatively large or self shadowing between hairs
	within a multiStreak group is desired
	then lightEachHair should be enabled. Also enabling this could avoid popping artifacts in
	situations with moving hard edged shadows.
	*/
	void setLightEachHair(bool leh){if(leh == false) return; fprintf_s(mFile, "setAttr \".leh\" %i;\n", leh);}
	/*
	Render times can be much faster if we share the same illumination for each hair
	in a multiStreak.
	If the multiStreak spread is relatively large or self shadowing between hairs
	within a multiStreak group is desired
	then lightEachHair should be enabled. Also enabling this could avoid popping artifacts in
	situations with moving hard edged shadows.
	*/
	void setLightEachHair(const BoolID& leh){fprintf_s(mFile,"connectAttr \"");leh.write(mFile);fprintf_s(mFile,"\" \"%s.leh\";\n",mName.c_str());}
	/*
	<b>Displacement Scale</b> affects the amount of displacment applied from root to
	tip of the hair clump. This affects curl, noise and subclumps. If the left side
	is zero then the effect will be gradually added such that the root position of the
	hair is not changed.
	*/
	void setDisplacementScale(size_t dsc_i,const DisplacementScale& dsc){fprintf_s(mFile, "setAttr \".dsc[%i]\" ",dsc_i);dsc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Displacement Scale</b> affects the amount of displacment applied from root to
	tip of the hair clump. This affects curl, noise and subclumps. If the left side
	is zero then the effect will be gradually added such that the root position of the
	hair is not changed.
	*/
	void setDisplacementScale(size_t dsc_i,const DisplacementScaleID& dsc){fprintf_s(mFile,"connectAttr \"");dsc.write(mFile);fprintf_s(mFile,"\" \"%s.dsc[%i]\";\n",mName.c_str(),dsc_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setDisplacementScale_Position(size_t dsc_i,float dscp){if(dscp == 0.0) return; fprintf_s(mFile, "setAttr \".dsc[%i].dscp\" %f;\n", dsc_i,dscp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setDisplacementScale_Position(size_t dsc_i,const FloatID& dscp){fprintf_s(mFile,"connectAttr \"");dscp.write(mFile);fprintf_s(mFile,"\" \"%s.dsc[%i].dscp\";\n",mName.c_str(),dsc_i);}
	/*Ramp value at the sibling position*/
	void setDisplacementScale_FloatValue(size_t dsc_i,float dscfv){if(dscfv == 0.0) return; fprintf_s(mFile, "setAttr \".dsc[%i].dscfv\" %f;\n", dsc_i,dscfv);}
	/*Ramp value at the sibling position*/
	void setDisplacementScale_FloatValue(size_t dsc_i,const FloatID& dscfv){fprintf_s(mFile,"connectAttr \"");dscfv.write(mFile);fprintf_s(mFile,"\" \"%s.dsc[%i].dscfv\";\n",mName.c_str(),dsc_i);}
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
	void setDisplacementScale_Interp(size_t dsc_i,unsigned int dsci){if(dsci == 0) return; fprintf_s(mFile, "setAttr \".dsc[%i].dsci\" %i;\n", dsc_i,dsci);}
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
	void setDisplacementScale_Interp(size_t dsc_i,const UnsignedintID& dsci){fprintf_s(mFile,"connectAttr \"");dsci.write(mFile);fprintf_s(mFile,"\" \"%s.dsc[%i].dsci\";\n",mName.c_str(),dsc_i);}
	/*
	This is the amount of curl displacement applied to each hair.
	The amount of displacement is relative to the hair width.
	The clump curl creates large scale curls about the clump center, while
	this attribute creates curls about the direction of individual hairs.
	*/
	void setCurl(double crl){if(crl == 0.0) return; fprintf_s(mFile, "setAttr \".crl\" %f;\n", crl);}
	/*
	This is the amount of curl displacement applied to each hair.
	The amount of displacement is relative to the hair width.
	The clump curl creates large scale curls about the clump center, while
	this attribute creates curls about the direction of individual hairs.
	*/
	void setCurl(const DoubleID& crl){fprintf_s(mFile,"connectAttr \"");crl.write(mFile);fprintf_s(mFile,"\" \"%s.crl\";\n",mName.c_str());}
	/*This is the rate of curl. Larger values result in more curls*/
	void setCurlFrequency(double crf){if(crf == 10) return; fprintf_s(mFile, "setAttr \".crf\" %f;\n", crf);}
	/*This is the rate of curl. Larger values result in more curls*/
	void setCurlFrequency(const DoubleID& crf){fprintf_s(mFile,"connectAttr \"");crf.write(mFile);fprintf_s(mFile,"\" \"%s.crf\";\n",mName.c_str());}
	/*
	Random defines the noise as a wiggle for each hair with no relation
	to neighboring hairs.
	Surface UV defines the noise displacement volumetrically
	and is relative to the uv distribution of the hairs across the
	surface. The noise is a 3D volume with a scale in U and V
	across the surface with the 3rd dimension (W) mapped down the length
	of the hairs. Clump UV defines the noise relative to the clump, and
	while neighboring clumps have completely independant noises,
	the frequency of the noise is not affected by the surface
	parametric density.
	Random is good for fuzzy, kinky hair, while the other, smoother
	noise methods can provide natural shaping and sub structure to
	hair clumps.
	*/
	void setNoiseMethod(unsigned int nmt){if(nmt == 0) return; fprintf_s(mFile, "setAttr \".nmt\" %i;\n", nmt);}
	/*
	Random defines the noise as a wiggle for each hair with no relation
	to neighboring hairs.
	Surface UV defines the noise displacement volumetrically
	and is relative to the uv distribution of the hairs across the
	surface. The noise is a 3D volume with a scale in U and V
	across the surface with the 3rd dimension (W) mapped down the length
	of the hairs. Clump UV defines the noise relative to the clump, and
	while neighboring clumps have completely independant noises,
	the frequency of the noise is not affected by the surface
	parametric density.
	Random is good for fuzzy, kinky hair, while the other, smoother
	noise methods can provide natural shaping and sub structure to
	hair clumps.
	*/
	void setNoiseMethod(const UnsignedintID& nmt){fprintf_s(mFile,"connectAttr \"");nmt.write(mFile);fprintf_s(mFile,"\" \"%s.nmt\";\n",mName.c_str());}
	/*
	This is the amount of perlin noise displacement of the hair.
	The amount of displacement is relative to the hair width when
	the noiseMethod is Random, otherwise it is relative to the
	clump width.
	This can create a knotted, kinky look to the hair.
	*/
	void setNoise(double noi){if(noi == 0.0) return; fprintf_s(mFile, "setAttr \".noi\" %f;\n", noi);}
	/*
	This is the amount of perlin noise displacement of the hair.
	The amount of displacement is relative to the hair width when
	the noiseMethod is Random, otherwise it is relative to the
	clump width.
	This can create a knotted, kinky look to the hair.
	*/
	void setNoise(const DoubleID& noi){fprintf_s(mFile,"connectAttr \"");noi.write(mFile);fprintf_s(mFile,"\" \"%s.noi\";\n",mName.c_str());}
	/*
	This is the amount of secondary high frequency noise added
	when smooth noise is used. It can add subtle detail on top of smooth
	undulations from the base noise. If non-zero a second noise offset
	calculation is performed so this can make evaluation of the hair slightly
	slower than the smooth noise with no detail noise.
	*/
	void setDetailNoise(double dno){if(dno == 0.0) return; fprintf_s(mFile, "setAttr \".dno\" %f;\n", dno);}
	/*
	This is the amount of secondary high frequency noise added
	when smooth noise is used. It can add subtle detail on top of smooth
	undulations from the base noise. If non-zero a second noise offset
	calculation is performed so this can make evaluation of the hair slightly
	slower than the smooth noise with no detail noise.
	*/
	void setDetailNoise(const DoubleID& dno){fprintf_s(mFile,"connectAttr \"");dno.write(mFile);fprintf_s(mFile,"\" \"%s.dno\";\n",mName.c_str());}
	/*
	This is the spacial scale of the noise offset along hair.
	Increasing this value results in finer kinks in the hairs.
	*/
	void setNoiseFrequency(double nof){if(nof == 0.4) return; fprintf_s(mFile, "setAttr \".nof\" %f;\n", nof);}
	/*
	This is the spacial scale of the noise offset along hair.
	Increasing this value results in finer kinks in the hairs.
	*/
	void setNoiseFrequency(const DoubleID& nof){fprintf_s(mFile,"connectAttr \"");nof.write(mFile);fprintf_s(mFile,"\" \"%s.nof\";\n",mName.c_str());}
	/*
	When smooth noise is used, this scales the noise frequency in the
	u parameter direction relative to the surface the
	hair is attached to.
	*/
	void setNoiseFrequencyU(double nfu){if(nfu == 1.0) return; fprintf_s(mFile, "setAttr \".nfu\" %f;\n", nfu);}
	/*
	When smooth noise is used, this scales the noise frequency in the
	u parameter direction relative to the surface the
	hair is attached to.
	*/
	void setNoiseFrequencyU(const DoubleID& nfu){fprintf_s(mFile,"connectAttr \"");nfu.write(mFile);fprintf_s(mFile,"\" \"%s.nfu\";\n",mName.c_str());}
	/*
	When smooth noise is used, this scales the noise frequency in the
	v parameter direction relative to the surface the
	hair is attached to.
	*/
	void setNoiseFrequencyV(double nfv){if(nfv == 1.0) return; fprintf_s(mFile, "setAttr \".nfv\" %f;\n", nfv);}
	/*
	When smooth noise is used, this scales the noise frequency in the
	v parameter direction relative to the surface the
	hair is attached to.
	*/
	void setNoiseFrequencyV(const DoubleID& nfv){fprintf_s(mFile,"connectAttr \"");nfv.write(mFile);fprintf_s(mFile,"\" \"%s.nfv\";\n",mName.c_str());}
	/*
	When smooth noise is used, this scales the noise frequency along the
	length of the hair.
	*/
	void setNoiseFrequencyW(double nfw){if(nfw == 1.0) return; fprintf_s(mFile, "setAttr \".nfw\" %f;\n", nfw);}
	/*
	When smooth noise is used, this scales the noise frequency along the
	length of the hair.
	*/
	void setNoiseFrequencyW(const DoubleID& nfw){fprintf_s(mFile,"connectAttr \"");nfw.write(mFile);fprintf_s(mFile,"\" \"%s.nfw\";\n",mName.c_str());}
	/*
	This determines how sub clumps are defined in UV.
	If Surface UV is used the sub clumps are laid out
	relative to the overall surface uv space. Some follicles
	may thus share a clump with a neighbor follicle. The density
	of sub clumps with be affected by the parametric density
	of the surface the hair system is attached to.
	The total number of clumps across a surface will be the
	numUClumps times the numVClumps.
	If Clump UV is used then the number of subClumps for each
	clump will be the numUClumps times the numVClumps. All
	follicles, regardless of clump width, will have the same
	number of sub clumps and the width of the sub clumps will
	be relate to the clump width. With Surface UV the smaller clumps
	will have fewer sub clumps and the clump width would be relative
	to the parametric density of the surface.
	*/
	void setSubClumpMethod(unsigned int scm){if(scm == 0) return; fprintf_s(mFile, "setAttr \".scm\" %i;\n", scm);}
	/*
	This determines how sub clumps are defined in UV.
	If Surface UV is used the sub clumps are laid out
	relative to the overall surface uv space. Some follicles
	may thus share a clump with a neighbor follicle. The density
	of sub clumps with be affected by the parametric density
	of the surface the hair system is attached to.
	The total number of clumps across a surface will be the
	numUClumps times the numVClumps.
	If Clump UV is used then the number of subClumps for each
	clump will be the numUClumps times the numVClumps. All
	follicles, regardless of clump width, will have the same
	number of sub clumps and the width of the sub clumps will
	be relate to the clump width. With Surface UV the smaller clumps
	will have fewer sub clumps and the clump width would be relative
	to the parametric density of the surface.
	*/
	void setSubClumpMethod(const UnsignedintID& scm){fprintf_s(mFile,"connectAttr \"");scm.write(mFile);fprintf_s(mFile,"\" \"%s.scm\";\n",mName.c_str());}
	/*
	This is the amount secondary clumps pull together.
	The sub clumping is useful for a wet look. The clumps
	are defined in a grid relative to the uv space of
	the surface the hair is attached to.
	*/
	void setSubClumping(double scp){if(scp == 0.0) return; fprintf_s(mFile, "setAttr \".scp\" %f;\n", scp);}
	/*
	This is the amount secondary clumps pull together.
	The sub clumping is useful for a wet look. The clumps
	are defined in a grid relative to the uv space of
	the surface the hair is attached to.
	*/
	void setSubClumping(const DoubleID& scp){fprintf_s(mFile,"connectAttr \"");scp.write(mFile);fprintf_s(mFile,"\" \"%s.scp\";\n",mName.c_str());}
	/*
	This randomizes the sub clumps with a noise function.
	The clumps will get smeared into irregular shapes with
	higher values.
	*/
	void setSubClumpRand(double scr){if(scr == 0.0) return; fprintf_s(mFile, "setAttr \".scr\" %f;\n", scr);}
	/*
	This randomizes the sub clumps with a noise function.
	The clumps will get smeared into irregular shapes with
	higher values.
	*/
	void setSubClumpRand(const DoubleID& scr){fprintf_s(mFile,"connectAttr \"");scr.write(mFile);fprintf_s(mFile,"\" \"%s.scr\";\n",mName.c_str());}
	/*
	This is the number of sub clumps in the u dimension of
	surface the hair system is attached to.
	*/
	void setNumUClumps(double nuc){if(nuc == 15.0) return; fprintf_s(mFile, "setAttr \".nuc\" %f;\n", nuc);}
	/*
	This is the number of sub clumps in the u dimension of
	surface the hair system is attached to.
	*/
	void setNumUClumps(const DoubleID& nuc){fprintf_s(mFile,"connectAttr \"");nuc.write(mFile);fprintf_s(mFile,"\" \"%s.nuc\";\n",mName.c_str());}
	/*
	This is the number of sub clumps in the v dimension of
	surface the hair system is attached to.
	*/
	void setNumVClumps(double nvc){if(nvc == 15.0) return; fprintf_s(mFile, "setAttr \".nvc\" %f;\n", nvc);}
	/*
	This is the number of sub clumps in the v dimension of
	surface the hair system is attached to.
	*/
	void setNumVClumps(const DoubleID& nvc){fprintf_s(mFile,"connectAttr \"");nvc.write(mFile);fprintf_s(mFile,"\" \"%s.nvc\";\n",mName.c_str());}
	/*
	This interpolates hairs between neighboring clumps
	Note that when this is not zero hairs are not
	contained within the clump boundaries, and thus
	collisions with a clump may not be correct.
	*/
	void setClumpInterpolation(double cin){if(cin == 0.0) return; fprintf_s(mFile, "setAttr \".cin\" %f;\n", cin);}
	/*
	This interpolates hairs between neighboring clumps
	Note that when this is not zero hairs are not
	contained within the clump boundaries, and thus
	collisions with a clump may not be correct.
	*/
	void setClumpInterpolation(const DoubleID& cin){fprintf_s(mFile,"connectAttr \"");cin.write(mFile);fprintf_s(mFile,"\" \"%s.cin\";\n",mName.c_str());}
	/*
	This determines how far apart a clump may be and still
	interpolate with another clump. The distance is defined
	relative to the clump diameter, so a value of 1 would
	only interpolate clumps that just overlap.
	*/
	void setInterpolationRange(double inr){if(inr == 8.0) return; fprintf_s(mFile, "setAttr \".inr\" %f;\n", inr);}
	/*
	This determines how far apart a clump may be and still
	interpolate with another clump. The distance is defined
	relative to the clump diameter, so a value of 1 would
	only interpolate clumps that just overlap.
	*/
	void setInterpolationRange(const DoubleID& inr){fprintf_s(mFile,"connectAttr \"");inr.write(mFile);fprintf_s(mFile,"\" \"%s.inr\";\n",mName.c_str());}
	/*
	This is the current time used for the hair solution.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.  There must be some incoming connection in order
	for the hairSystem object to play back.
	*/
	void setCurrentTime(const TimeID& cti){fprintf_s(mFile,"connectAttr \"");cti.write(mFile);fprintf_s(mFile,"\" \"%s.cti\";\n",mName.c_str());}
	/*
	The time after which the simulation will be run for this hair object.
	This is set from the startFrame attribute.
	Users should set startFrame instead of this attribute.
	*/
	void setStartTime(const TimeID& sti){fprintf_s(mFile,"connectAttr \"");sti.write(mFile);fprintf_s(mFile,"\" \"%s.sti\";\n",mName.c_str());}
	/*
	This is the frame after which the simulation will run. Nothing
	will play back for this object prior to startFrame.
	*/
	void setStartFrame(double stf){if(stf == 1.0) return; fprintf_s(mFile, "setAttr \".stf\" %f;\n", stf);}
	/*
	This is the frame after which the simulation will run. Nothing
	will play back for this object prior to startFrame.
	*/
	void setStartFrame(const DoubleID& stf){fprintf_s(mFile,"connectAttr \"");stf.write(mFile);fprintf_s(mFile,"\" \"%s.stf\";\n",mName.c_str());}
	/*
	This is the input multi-attribute where any fields acting on
	this particle object are connected.  These are accumulated
	in the computePlug() section for aForce, along with other
	forces like goals.
	*/
	void setInputForce(size_t ifc_i,const VectorArrayID& ifc){fprintf_s(mFile,"connectAttr \"");ifc.write(mFile);fprintf_s(mFile,"\" \"%s.ifc[%i]\";\n",mName.c_str(),ifc_i);}
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	void setFieldData(const FieldDataID& fd){fprintf_s(mFile,"connectAttr \"");fd.write(mFile);fprintf_s(mFile,"\" \"%s.fd\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this particle object's
	position data from.  It will share the data from aPosition.
	*/
	void setFieldDataPosition(const VectorArrayID& fdp){fprintf_s(mFile,"connectAttr \"");fdp.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdp\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this particle object's
	velcoity data from.  It will share the data from aVelocity.
	*/
	void setFieldDataVelocity(const VectorArrayID& fdv){fprintf_s(mFile,"connectAttr \"");fdv.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdv\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this particle object's
	mass data from.  It will share the data from aMass.
	*/
	void setFieldDataMass(const DoubleArrayID& fdm){fprintf_s(mFile,"connectAttr \"");fdm.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdm\";\n",mName.c_str());}
	/*
	This is the default place that the fields will get this particle object's
	timeStep size from.  It will share the data from aTimeStepSize.
	*/
	void setFieldDataDeltaTime(const TimeID& fdt){fprintf_s(mFile,"connectAttr \"");fdt.write(mFile);fprintf_s(mFile,"\" \"%s.fd.fdt\";\n",mName.c_str());}
	/*
	Force evaluation changed in maya7.0 to match normal particle dynamics. Enabling
	this attribute will revert to the older behavior.
	*/
	void setUsePre70ForceIntensity(bool upfi){if(upfi == false) return; fprintf_s(mFile, "setAttr \".upfi\" %i;\n", upfi);}
	/*
	Force evaluation changed in maya7.0 to match normal particle dynamics. Enabling
	this attribute will revert to the older behavior.
	*/
	void setUsePre70ForceIntensity(const BoolID& upfi){fprintf_s(mFile,"connectAttr \"");upfi.write(mFile);fprintf_s(mFile,"\" \"%s.upfi\";\n",mName.c_str());}
	/*Connection for playback cache node*/
	void setDiskCache(const MessageID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*The flag to control if this object casts shadows.*/
	void setReceiveShadows(bool rcsh){if(rcsh == true) return; fprintf_s(mFile, "setAttr \".rcsh\" %i;\n", rcsh);}
	/*The flag to control if this object casts shadows.*/
	void setReceiveShadows(const BoolID& rcsh){fprintf_s(mFile,"connectAttr \"");rcsh.write(mFile);fprintf_s(mFile,"\" \"%s.rcsh\";\n",mName.c_str());}
	/*The flag to control if this object is visible in reflections.*/
	void setVisibleInReflections(bool vir){if(vir == false) return; fprintf_s(mFile, "setAttr \".vir\" %i;\n", vir);}
	/*The flag to control if this object is visible in reflections.*/
	void setVisibleInReflections(const BoolID& vir){fprintf_s(mFile,"connectAttr \"");vir.write(mFile);fprintf_s(mFile,"\" \"%s.vir\";\n",mName.c_str());}
	/*The flag to control if this object is visible in refractions.*/
	void setVisibleInRefractions(bool vif){if(vif == false) return; fprintf_s(mFile, "setAttr \".vif\" %i;\n", vif);}
	/*The flag to control if this object is visible in refractions.*/
	void setVisibleInRefractions(const BoolID& vif){fprintf_s(mFile,"connectAttr \"");vif.write(mFile);fprintf_s(mFile,"\" \"%s.vif\";\n",mName.c_str());}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControls& mrc){fprintf_s(mFile, "setAttr \".mrc\" ");mrc.write(mFile);fprintf_s(mFile,";\n");}
	/*This is a root of following mental ray attributes.*/
	void setMentalRayControls(const MentalRayControlsID& mrc){fprintf_s(mFile,"connectAttr \"");mrc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc\";\n",mName.c_str());}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(bool oca){if(oca == false) return; fprintf_s(mFile, "setAttr \".mrc.oca\" %i;\n", oca);}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideCaustics(const BoolID& oca){fprintf_s(mFile,"connectAttr \"");oca.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oca\";\n",mName.c_str());}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(short caa){if(caa == 64) return; fprintf_s(mFile, "setAttr \".mrc.caa\" %i;\n", caa);}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticAccuracy(const ShortID& caa){fprintf_s(mFile,"connectAttr \"");caa.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.caa\";\n",mName.c_str());}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(float car){if(car == 0) return; fprintf_s(mFile, "setAttr \".mrc.car\" %f;\n", car);}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	void setMiCausticRadius(const FloatID& car){fprintf_s(mFile,"connectAttr \"");car.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.car\";\n",mName.c_str());}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(bool ogi){if(ogi == false) return; fprintf_s(mFile, "setAttr \".mrc.ogi\" %i;\n", ogi);}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideGlobalIllumination(const BoolID& ogi){fprintf_s(mFile,"connectAttr \"");ogi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ogi\";\n",mName.c_str());}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(short gia){if(gia == 64) return; fprintf_s(mFile, "setAttr \".mrc.gia\" %i;\n", gia);}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumAccuracy(const ShortID& gia){fprintf_s(mFile,"connectAttr \"");gia.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gia\";\n",mName.c_str());}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(float gir){if(gir == 0) return; fprintf_s(mFile, "setAttr \".mrc.gir\" %f;\n", gir);}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	void setMiGlobillumRadius(const FloatID& gir){fprintf_s(mFile,"connectAttr \"");gir.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.gir\";\n",mName.c_str());}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(bool ofg){if(ofg == false) return; fprintf_s(mFile, "setAttr \".mrc.ofg\" %i;\n", ofg);}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	void setMiOverrideFinalGather(const BoolID& ofg){fprintf_s(mFile,"connectAttr \"");ofg.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ofg\";\n",mName.c_str());}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(int fry){if(fry == 1000) return; fprintf_s(mFile, "setAttr \".mrc.fry\" %i;\n", fry);}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherRays(const IntID& fry){fprintf_s(mFile,"connectAttr \"");fry.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fry\";\n",mName.c_str());}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(float fmn){if(fmn == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmn\" %f;\n", fmn);}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMinRadius(const FloatID& fmn){fprintf_s(mFile,"connectAttr \"");fmn.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmn\";\n",mName.c_str());}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(float fmx){if(fmx == 0) return; fprintf_s(mFile, "setAttr \".mrc.fmx\" %f;\n", fmx);}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherMaxRadius(const FloatID& fmx){fprintf_s(mFile,"connectAttr \"");fmx.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fmx\";\n",mName.c_str());}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(short ffi){if(ffi == 1) return; fprintf_s(mFile, "setAttr \".mrc.ffi\" %i;\n", ffi);}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherFilter(const ShortID& ffi){fprintf_s(mFile,"connectAttr \"");ffi.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.ffi\";\n",mName.c_str());}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(bool fgv){if(fgv == false) return; fprintf_s(mFile, "setAttr \".mrc.fgv\" %i;\n", fgv);}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	void setMiFinalGatherView(const BoolID& fgv){fprintf_s(mFile,"connectAttr \"");fgv.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgv\";\n",mName.c_str());}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	void setMiOverrideSamples(bool oos){if(oos == false) return; fprintf_s(mFile, "setAttr \".mrc.oos\" %i;\n", oos);}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	void setMiOverrideSamples(const BoolID& oos){fprintf_s(mFile,"connectAttr \"");oos.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.oos\";\n",mName.c_str());}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(short mins){if(mins == 0) return; fprintf_s(mFile, "setAttr \".mrc.mins\" %i;\n", mins);}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	void setMiMinSamples(const ShortID& mins){fprintf_s(mFile,"connectAttr \"");mins.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.mins\";\n",mName.c_str());}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(short maxs){if(maxs == 2) return; fprintf_s(mFile, "setAttr \".mrc.maxs\" %i;\n", maxs);}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	void setMiMaxSamples(const ShortID& maxs){fprintf_s(mFile,"connectAttr \"");maxs.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.maxs\";\n",mName.c_str());}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	void setMiFinalGatherCast(bool fgc){if(fgc == true) return; fprintf_s(mFile, "setAttr \".mrc.fgc\" %i;\n", fgc);}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	void setMiFinalGatherCast(const BoolID& fgc){fprintf_s(mFile,"connectAttr \"");fgc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fgc\";\n",mName.c_str());}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	void setMiFinalGatherReceive(bool fge){if(fge == true) return; fprintf_s(mFile, "setAttr \".mrc.fge\" %i;\n", fge);}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	void setMiFinalGatherReceive(const BoolID& fge){fprintf_s(mFile,"connectAttr \"");fge.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.fge\";\n",mName.c_str());}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	void setMiTransparencyCast(bool tpc){if(tpc == true) return; fprintf_s(mFile, "setAttr \".mrc.tpc\" %i;\n", tpc);}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	void setMiTransparencyCast(const BoolID& tpc){fprintf_s(mFile,"connectAttr \"");tpc.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.tpc\";\n",mName.c_str());}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	void setMiTransparencyReceive(bool tpr){if(tpr == true) return; fprintf_s(mFile, "setAttr \".mrc.tpr\" %i;\n", tpr);}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	void setMiTransparencyReceive(const BoolID& tpr){fprintf_s(mFile,"connectAttr \"");tpr.write(mFile);fprintf_s(mFile,"\" \"%s.mrc.tpr\";\n",mName.c_str());}
	/*
	Output array of polylines (double point arrays) that represet the current
	position of the dynamically solved hairs.
	*/
	void setOutputHair(size_t oh_i,const vectorArray& oh){if(oh.size == 0) return; fprintf_s(mFile, "setAttr \".oh[%i]\" -type \"vectorArray\" ",oh_i);oh.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Output array of polylines (double point arrays) that represet the current
	position of the dynamically solved hairs.
	*/
	void setOutputHair(size_t oh_i,const VectorArrayID& oh){fprintf_s(mFile,"connectAttr \"");oh.write(mFile);fprintf_s(mFile,"\" \"%s.oh[%i]\";\n",mName.c_str(),oh_i);}
	/*
	Output of the hair system for paint effects rendering. This connection passes the
	positions and widths of all dynamically solved hairs in addition to shading attributes.
	*/
	void setOutputRenderHairs(const HairRenderInfoID& orh){fprintf_s(mFile,"connectAttr \"");orh.write(mFile);fprintf_s(mFile,"\" \"%s.orh\";\n",mName.c_str());}
	/*
	This controls the simulation level. If Off is selected then there is no output.
	Static positions the output hair aways at the start position with no dynamics(totally stiff).
	Dynamic Follicles Only will avoid generating output for passive follicles(if any).
	This is useful for faster preview of complex hairsystems.
	All Follicles will compute the full simulation.
	*/
	UnsignedintID getSimulationMethod(){char buffer[4096];sprintf_s (buffer, "%s.sim",mName.c_str());return (const char*)buffer;}
	/*Input hair*/
	const HairCurveID& getInputHair(size_t ih_i){char buffer[4096];sprintf_s (buffer, "%s.ih[%i]",mName.c_str(),ih_i);return (const char*)buffer;}
	/*Input hair pin constraints*/
	const HairPinID& getInputHairPin(size_t ihp_i){char buffer[4096];sprintf_s (buffer, "%s.ihp[%i]",mName.c_str(),ihp_i);return (const char*)buffer;}
	/*If true then collide with connected objects.*/
	BoolID getCollide(){char buffer[4096];sprintf_s (buffer, "%s.cld",mName.c_str());return (const char*)buffer;}
	/*
	This allows one to adjust the quality collision sampling.
	larger values will help keep hairs from pushing through surfaces.
	*/
	IntID getCollideOverSample(){char buffer[4096];sprintf_s (buffer, "%s.cos",mName.c_str());return (const char*)buffer;}
	/*If true then simulate hair/hair interaction.*/
	BoolID getSelfCollide(){char buffer[4096];sprintf_s (buffer, "%s.scd",mName.c_str());return (const char*)buffer;}
	/*
	If true then collide with an infinite plane at the ground height.
	This collision does not impact the speed of the solution, unlike geometry collisions.
	*/
	BoolID getCollideGround(){char buffer[4096];sprintf_s (buffer, "%s.cdg",mName.c_str());return (const char*)buffer;}
	/*When collide ground is on, this determine the height of the ground plane.*/
	DoubleID getGroundHeight(){char buffer[4096];sprintf_s (buffer, "%s.ghe",mName.c_str());return (const char*)buffer;}
	/*The amount the hair can flex with regard to the rest position.*/
	DoubleID getStiffness(){char buffer[4096];sprintf_s (buffer, "%s.sfn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Stiffness Scale</b> affects the stiffness from root to tip of the hair.
	The left of the graph is the root and the right is the tip. Typically the root of a
	hair is thicker and thus stiffer than the tip. This attribute multiplies
	the stiffness parameter value, so a value of 1.0 will leave the stiffness unchanged.
	If the stiffness attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	const StiffnessScaleID& getStiffnessScale(size_t sts_i){char buffer[4096];sprintf_s (buffer, "%s.sts[%i]",mName.c_str(),sts_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getStiffnessScale_Position(size_t sts_i){char buffer[4096];sprintf_s (buffer, "%s.sts[%i].stsp",mName.c_str(),sts_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getStiffnessScale_FloatValue(size_t sts_i){char buffer[4096];sprintf_s (buffer, "%s.sts[%i].stsfv",mName.c_str(),sts_i);return (const char*)buffer;}
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
	const UnsignedintID& getStiffnessScale_Interp(size_t sts_i){char buffer[4096];sprintf_s (buffer, "%s.sts[%i].stsi",mName.c_str(),sts_i);return (const char*)buffer;}
	/*The amount the hair can stretch along its length.*/
	DoubleID getLengthFlex(){char buffer[4096];sprintf_s (buffer, "%s.lfx",mName.c_str());return (const char*)buffer;}
	/*
	This dampens the internal motions of individual hairs.
	It is particularily useful to help stabilize shaped hair when
	one has a defined rest position.
	*/
	DoubleID getDamp(){char buffer[4096];sprintf_s (buffer, "%s.dmp",mName.c_str());return (const char*)buffer;}
	/*This simulates friction with the air, in addition to helping to stabilize the simulation. When the damp is 1.0 the hair will behave as if it has no inertial motion or followthrough: it will move as if in a thick fluid.*/
	DoubleID getDrag(){char buffer[4096];sprintf_s (buffer, "%s.drg",mName.c_str());return (const char*)buffer;}
	/*This simulates friction with on contact with other surfaces.*/
	DoubleID getFriction(){char buffer[4096];sprintf_s (buffer, "%s.frc",mName.c_str());return (const char*)buffer;}
	/*
	This controls the simulated mass of the hair cvs. This currently will
	only show an effect if one applies external fields that consider mass, such as drag.
	*/
	DoubleID getMass(){char buffer[4096];sprintf_s (buffer, "%s.mss",mName.c_str());return (const char*)buffer;}
	/*Scale factor for the effect of attached dynamic fields on the hair motion.*/
	DoubleID getDynamicsWeight(){char buffer[4096];sprintf_s (buffer, "%s.dw",mName.c_str());return (const char*)buffer;}
	/*
	This value is added to clumpWidths before determining collisions.
	The amount is relative to the clump width.
	It can be used to handle situations where there is some interpenetration,
	or where one has passive hairs that are outside the boundaries of active clumps.
	In cases where the hairs collide too far off an object, one can use negative values
	to allow a little interpenetration of clumps.
	*/
	DoubleID getCollideWidthOffset(){char buffer[4096];sprintf_s (buffer, "%s.wid",mName.c_str());return (const char*)buffer;}
	/*
	This value determines the amount of local attraction between
	self colliding hair clumps. It simulates static cling and friction
	between hair clumps. Self collide must be on for this to have an effect.
	Motion of masses of hair tend to be very damped due to the effects of
	self collision, friction and static. This can be helpful in achieving
	natural motion. Negative values can be used to make hairs repel from each other.
	*/
	DoubleID getStaticCling(){char buffer[4096];sprintf_s (buffer, "%s.stc",mName.c_str());return (const char*)buffer;}
	/*
	This value determines the amount of repulsion when clumps are
	overlapping. When this is 1.0 clumps are pushed apart in a single timestep,
	although this may cause excessive motion in some cases, especially when clumps
	start out overlapping. Lowering this value can help damp such motion yet still
	preserve general body in the hair.
	*/
	DoubleID getRepulsion(){char buffer[4096];sprintf_s (buffer, "%s.rpl",mName.c_str());return (const char*)buffer;}
	/*
	This controls how many neighbor hairs to include in the self collision.
	Each hair clump with collide with the closest hairs( relative to the separation
	at the base of the hair on the start frame ). If this number is equal to the
	total number of clumps then all hairs will collide with all other hairs in
	the hair system, but the simulation will be slow.
	*/
	IntID getNumCollideNeighbors(){char buffer[4096];sprintf_s (buffer, "%s.ncn",mName.c_str());return (const char*)buffer;}
	/*
	This controls number of iterations per time step of the hair solver.
	This affects hair stiffness and length flex, as well as the accuracy of collisions.
	Large values are required for very high stiffness. Note that large value will also increase
	the time required by the solver
	*/
	IntID getIterations(){char buffer[4096];sprintf_s (buffer, "%s.itr",mName.c_str());return (const char*)buffer;}
	/*If true then draw circles around each line representing its width used for collision.*/
	BoolID getDrawCollideWidth(){char buffer[4096];sprintf_s (buffer, "%s.dwd",mName.c_str());return (const char*)buffer;}
	/*
	This allows one to adjust the quality of the tube collide width drawing.
	A value of zero will cause a circle to be draw for every segment of
	the tube, which may clutter the display for tube with many segments.
	*/
	IntID getWidthDrawSkip(){char buffer[4096];sprintf_s (buffer, "%s.wds",mName.c_str());return (const char*)buffer;}
	/*A built in downward force in y simulating gravity.*/
	DoubleID getGravity(){char buffer[4096];sprintf_s (buffer, "%s.grv",mName.c_str());return (const char*)buffer;}
	/*
	Increasing this will increase the amount of force applied
	by the turbulence
	*/
	DoubleID getTurbulenceStrength(){char buffer[4096];sprintf_s (buffer, "%s.tst",mName.c_str());return (const char*)buffer;}
	/*
	Lowering this will make the turbulence vortices larger. This
	is a spacial scale factor on the turbulence function and has
	no effect if the turbulence strength is zero.
	*/
	DoubleID getTurbulenceFrequency(){char buffer[4096];sprintf_s (buffer, "%s.tfr",mName.c_str());return (const char*)buffer;}
	/*Rate at which turbulence pattern changes over time*/
	DoubleID getTurbulenceSpeed(){char buffer[4096];sprintf_s (buffer, "%s.tbs",mName.c_str());return (const char*)buffer;}
	/*
	Attraction to the start curve is done by altering the
	current velocity of the hair so that it will meet the
	start position. This control damps out this value.
	When this value is one, the motion towards the start
	curve is fully damped leaving simply the start position
	plus field forces.  This is useful for applying fields on top
	of previously animated hairs.  To acheive this affect,
	you should set attractionDamp = 1.0 and make the stiffness
	ramp all 1.0.
	*/
	DoubleID getAttractionDamp(){char buffer[4096];sprintf_s (buffer, "%s.ad",mName.c_str());return (const char*)buffer;}
	/*
	This value determines the amount of attraction of the current hair
	position to the start position. Normally one would leave this at
	zero for long flowing hair. However for short hair it can be
	difficult to make hair stiff enough. This is good when the hair needs
	to be very stiff, and yet at the same time have some dynamic properties.
	At a value of one the hair position will be the start curve position(
	relative to the transformed follicle position ), only collisions and
	forces will still deflect the hair. Without startCurveAttract this
	could otherwise require a very high iteration count and damp value,
	especially if there are many cvs per hair.
	*/
	DoubleID getStartCurveAttract(){char buffer[4096];sprintf_s (buffer, "%s.sct",mName.c_str());return (const char*)buffer;}
	/*
	This value attenuates the startCurveAttract value along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	If the startCurveAttract attribute is zero then this parameter will have no effect,
	as zero times a number is always zero.
	*/
	const AttractionScaleID& getAttractionScale(size_t ats_i){char buffer[4096];sprintf_s (buffer, "%s.ats[%i]",mName.c_str(),ats_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getAttractionScale_Position(size_t ats_i){char buffer[4096];sprintf_s (buffer, "%s.ats[%i].atsp",mName.c_str(),ats_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getAttractionScale_FloatValue(size_t ats_i){char buffer[4096];sprintf_s (buffer, "%s.ats[%i].atsfv",mName.c_str(),ats_i);return (const char*)buffer;}
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
	const UnsignedintID& getAttractionScale_Interp(size_t ats_i){char buffer[4096];sprintf_s (buffer, "%s.ats[%i].atsi",mName.c_str(),ats_i);return (const char*)buffer;}
	/*
	This value determines the amount the current hair
	is damped relative to the transform of the follicle.
	If this value is 1 then the hair will fully move with the
	follicle, but its shape can still be changed by other forces.
	Unlike startCurveAttract which makes the hair like a stiff spring
	this pushes the hair with the motion of the follicle, but allows
	it to change shape. It is as if there is a block of air or mud
	(depending on the motion damp intensity) that moves with the follicle
	and tends to drag the hair with it. The normal drag attribute
	instead drags relative to zero motion, rather than the motion
	of the follicle base. This is useful in making hair stiff with fewer
	iterations and it can simulate the combination of self collision of
	hairs along with friction and trapped air. The relative range of
	affect along the hairs for motion drag is scaled by the stiffness ramp.
	It looks most natural when there is more drag at the base.
	*/
	DoubleID getMotionDrag(){char buffer[4096];sprintf_s (buffer, "%s.mdg",mName.c_str());return (const char*)buffer;}
	/*
	percentage of hairs within clumps to display for interactive draw
	This corresponds to the display quality on paint effects strokes.
	*/
	DoubleID getDisplayQuality(){char buffer[4096];sprintf_s (buffer, "%s.dpq",mName.c_str());return (const char*)buffer;}
	/*
	If true then fix the length of the output hairs to be constant.
	The internal dynamic hairs will still stretch, but the output
	hair will be locked to the base point. Care should be taken
	when using this attribute. If the lengthFlex is
	low or the iterations are low then the dynamic computed hair
	may protrude much beyond the end of the rendered hair, and the
	behavior could look unnatural.
	*/
	BoolID getNoStretch(){char buffer[4096];sprintf_s (buffer, "%s.nst",mName.c_str());return (const char*)buffer;}
	/*
	This determines the number of smoothly interpolated segments at render time.
	The hermite interpolation smooths the shape of the line, in addition to providing
	more detail for curls and fine features. The added segments affect the rendered look only,
	and do not affect the dynamic simulation.
	*/
	IntID getSubSegments(){char buffer[4096];sprintf_s (buffer, "%s.ssg",mName.c_str());return (const char*)buffer;}
	/*This is the base or maximum width for the dynamic hair groups.*/
	DoubleID getClumpWidth(){char buffer[4096];sprintf_s (buffer, "%s.cwd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Clump Width Scale</b> affects the width from root to tip of the hair clump.
	The left of the graph is the root and the right is the tip.
	Often one may wish the hairs within the clump to come to a tip at the end of the clump,
	in which case the right value should be smaller than the left. This attribute multiplies
	the clumpWidth parameter value, so a value of 1.0 will leave the clumpWidth unchanged.
	If the clumpWidth attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	const ClumpWidthScaleID& getClumpWidthScale(size_t cws_i){char buffer[4096];sprintf_s (buffer, "%s.cws[%i]",mName.c_str(),cws_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getClumpWidthScale_Position(size_t cws_i){char buffer[4096];sprintf_s (buffer, "%s.cws[%i].cwsp",mName.c_str(),cws_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getClumpWidthScale_FloatValue(size_t cws_i){char buffer[4096];sprintf_s (buffer, "%s.cws[%i].cwsfv",mName.c_str(),cws_i);return (const char*)buffer;}
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
	const UnsignedintID& getClumpWidthScale_Interp(size_t cws_i){char buffer[4096];sprintf_s (buffer, "%s.cws[%i].cwsi",mName.c_str(),cws_i);return (const char*)buffer;}
	/*This is the rotation of the clump group about the primary hair axis.*/
	DoubleID getClumpTwist(){char buffer[4096];sprintf_s (buffer, "%s.ctw",mName.c_str());return (const char*)buffer;}
	/*
	<b>Clump Curl</b> controls the rate of curling about the primary axis of each hair clump.
	The left of the graph is the root and the right is the tip.
	The mid value of the ramp(0.5) represents no twist while values greater than that will result
	in positive twisting while smaller values will cause twisting in the reverse direction.
	*/
	const ClumpCurlID& getClumpCurl(size_t clc_i){char buffer[4096];sprintf_s (buffer, "%s.clc[%i]",mName.c_str(),clc_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getClumpCurl_Position(size_t clc_i){char buffer[4096];sprintf_s (buffer, "%s.clc[%i].clcp",mName.c_str(),clc_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getClumpCurl_FloatValue(size_t clc_i){char buffer[4096];sprintf_s (buffer, "%s.clc[%i].clcfv",mName.c_str(),clc_i);return (const char*)buffer;}
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
	const UnsignedintID& getClumpCurl_Interp(size_t clc_i){char buffer[4096];sprintf_s (buffer, "%s.clc[%i].clci",mName.c_str(),clc_i);return (const char*)buffer;}
	/*
	<b>Clump Flatness</b> affects the flatness of the clump group from root to tip.
	The left of the graph is the root and the right is the tip.
	*/
	const ClumpFlatnessID& getClumpFlatness(size_t cfl_i){char buffer[4096];sprintf_s (buffer, "%s.cfl[%i]",mName.c_str(),cfl_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getClumpFlatness_Position(size_t cfl_i){char buffer[4096];sprintf_s (buffer, "%s.cfl[%i].cflp",mName.c_str(),cfl_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getClumpFlatness_FloatValue(size_t cfl_i){char buffer[4096];sprintf_s (buffer, "%s.cfl[%i].cflfv",mName.c_str(),cfl_i);return (const char*)buffer;}
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
	const UnsignedintID& getClumpFlatness_Interp(size_t cfl_i){char buffer[4096];sprintf_s (buffer, "%s.cfl[%i].cfli",mName.c_str(),cfl_i);return (const char*)buffer;}
	/*
	This determines how much the rotation of the overall clump
	follows the primary hair axis. Short straight fur may work better
	with this value near zero, as the end of wide clumps will blend better
	when they twist. With this value at 1.0 the cross section of the
	hair clump will always be perpendicular to the tube direction,
	which can work well for long relatively thin clumps.  When this
	value is zero the cross section is always perpendicular to the
	surface normal at the start of the hair clump.
	*/
	DoubleID getBendFollow(){char buffer[4096];sprintf_s (buffer, "%s.bnf",mName.c_str());return (const char*)buffer;}
	/*This is the global width for hairs.*/
	DoubleID getHairWidth(){char buffer[4096];sprintf_s (buffer, "%s.hwd",mName.c_str());return (const char*)buffer;}
	/*
	<b>Hair Width Scale</b> affects the width from root to tip of the hairs.
	The left of the graph is the root and the right is the tip.
	This attribute multiplies the hairWidth parameter value, so a value of 1.0
	will leave the hairWidth unchanged.
	If the hairWidth attribute is zero then this parameter will have no effect, as zero times
	a number is always zero.
	*/
	const HairWidthScaleID& getHairWidthScale(size_t hws_i){char buffer[4096];sprintf_s (buffer, "%s.hws[%i]",mName.c_str(),hws_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getHairWidthScale_Position(size_t hws_i){char buffer[4096];sprintf_s (buffer, "%s.hws[%i].hwsp",mName.c_str(),hws_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getHairWidthScale_FloatValue(size_t hws_i){char buffer[4096];sprintf_s (buffer, "%s.hws[%i].hwsfv",mName.c_str(),hws_i);return (const char*)buffer;}
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
	const UnsignedintID& getHairWidthScale_Interp(size_t hws_i){char buffer[4096];sprintf_s (buffer, "%s.hws[%i].hwsi",mName.c_str(),hws_i);return (const char*)buffer;}
	/*
	This reduces the hair density using a texture. The texture
	used must be a 2D texture.
	*/
	DoubleID getBaldnessMap(){char buffer[4096];sprintf_s (buffer, "%s.bmp",mName.c_str());return (const char*)buffer;}
	/*
	This controls the overall transparency of the hair.
	A value of 0 is fully transparent and 1 is fully opaque.
	*/
	DoubleID getOpacity(){char buffer[4096];sprintf_s (buffer, "%s.opc",mName.c_str());return (const char*)buffer;}
	/*
	Base color for hairs. The final color used is determined
	after the hairColorScale and randomization parameters are applied.
	Also individual hair clumps may override the hairColor.
	*/
	Float3ID getHairColor(){char buffer[4096];sprintf_s (buffer, "%s.hcl",mName.c_str());return (const char*)buffer;}
	/*hair Red value*/
	FloatID getHairColorR(){char buffer[4096];sprintf_s (buffer, "%s.hcl.hcr",mName.c_str());return (const char*)buffer;}
	/*hair Green value*/
	FloatID getHairColorG(){char buffer[4096];sprintf_s (buffer, "%s.hcl.hcg",mName.c_str());return (const char*)buffer;}
	/*hair Blue value*/
	FloatID getHairColorB(){char buffer[4096];sprintf_s (buffer, "%s.hcl.hcb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Hair Color</b> defines the global color of the hairs from root to tip.
	The left of the graph is the root and the right is the tip.
	*/
	const HairColorScaleID& getHairColorScale(size_t hcs_i){char buffer[4096];sprintf_s (buffer, "%s.hcs[%i]",mName.c_str(),hcs_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getHairColorScale_Position(size_t hcs_i){char buffer[4096];sprintf_s (buffer, "%s.hcs[%i].hcsp",mName.c_str(),hcs_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getHairColorScale_Color(size_t hcs_i){char buffer[4096];sprintf_s (buffer, "%s.hcs[%i].hcsc",mName.c_str(),hcs_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getHairColorScale_ColorR(size_t hcs_i){char buffer[4096];sprintf_s (buffer, "%s.hcs[%i].hcsc.hcscr",mName.c_str(),hcs_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getHairColorScale_ColorG(size_t hcs_i){char buffer[4096];sprintf_s (buffer, "%s.hcs[%i].hcsc.hcscg",mName.c_str(),hcs_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getHairColorScale_ColorB(size_t hcs_i){char buffer[4096];sprintf_s (buffer, "%s.hcs[%i].hcsc.hcscb",mName.c_str(),hcs_i);return (const char*)buffer;}
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
	const UnsignedintID& getHairColorScale_Interp(size_t hcs_i){char buffer[4096];sprintf_s (buffer, "%s.hcs[%i].hcsi",mName.c_str(),hcs_i);return (const char*)buffer;}
	/*This is the number of hairs rendered for each current position hair curve.*/
	IntID getHairsPerClump(){char buffer[4096];sprintf_s (buffer, "%s.hpc",mName.c_str());return (const char*)buffer;}
	/*This controls the proportion of shorter length hairs.*/
	DoubleID getThinning(){char buffer[4096];sprintf_s (buffer, "%s.thn",mName.c_str());return (const char*)buffer;}
	/*This allows light to filter through hair for a softer effect.*/
	DoubleID getTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.tlc",mName.c_str());return (const char*)buffer;}
	/*input color for specular highlights*/
	Float3ID getSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.spc",mName.c_str());return (const char*)buffer;}
	/*specular Red value*/
	FloatID getSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.spc.spr",mName.c_str());return (const char*)buffer;}
	/*specular Green value*/
	FloatID getSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.spc.spg",mName.c_str());return (const char*)buffer;}
	/*specular Blue value*/
	FloatID getSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.spc.spb",mName.c_str());return (const char*)buffer;}
	/*This allows light to filter through hair for a softer effect.*/
	DoubleID getSpecularPower(){char buffer[4096];sprintf_s (buffer, "%s.spp",mName.c_str());return (const char*)buffer;}
	/*This causes the hair to cast shadows(depthmap only).*/
	BoolID getCastShadows(){char buffer[4096];sprintf_s (buffer, "%s.csd",mName.c_str());return (const char*)buffer;}
	/*a diffuse brightness randomization between hairs in a clump*/
	DoubleID getDiffuseRand(){char buffer[4096];sprintf_s (buffer, "%s.dfr",mName.c_str());return (const char*)buffer;}
	/*a specular brightness randomization between hairs in a clump*/
	DoubleID getSpecularRand(){char buffer[4096];sprintf_s (buffer, "%s.sra",mName.c_str());return (const char*)buffer;}
	/*random deviation in hue of hairs*/
	DoubleID getHueRand(){char buffer[4096];sprintf_s (buffer, "%s.chr",mName.c_str());return (const char*)buffer;}
	/*random deviation in color saturation of hairs*/
	DoubleID getSatRand(){char buffer[4096];sprintf_s (buffer, "%s.csr",mName.c_str());return (const char*)buffer;}
	/*random deviation in brighness value of hairs*/
	DoubleID getValRand(){char buffer[4096];sprintf_s (buffer, "%s.cvr",mName.c_str());return (const char*)buffer;}
	/*
	<b>Multi Streaks</b> is the number of added sub hairs for each hair in a clump.
	These hairs will share the same shape and shading as the base hair they are
	derived from. They are created at render time and are simple duplicates,
	and thus do not take up any shape computation. This allows one to have a
	great number of tubes and yet render them in a reasonable amount of time.
	*/
	IntID getMultiStreaks(){char buffer[4096];sprintf_s (buffer, "%s.mst",mName.c_str());return (const char*)buffer;}
	/*the maximum offset for added hairs relative to the clump width*/
	DoubleID getMultiStreakSpread1(){char buffer[4096];sprintf_s (buffer, "%s.ms1",mName.c_str());return (const char*)buffer;}
	/*the maximum offset for added tubes relative to the clump width at the tube tip*/
	DoubleID getMultiStreakSpread2(){char buffer[4096];sprintf_s (buffer, "%s.ms2",mName.c_str());return (const char*)buffer;}
	/*
	Render times can be much faster if we share the same illumination for each hair
	in a multiStreak.
	If the multiStreak spread is relatively large or self shadowing between hairs
	within a multiStreak group is desired
	then lightEachHair should be enabled. Also enabling this could avoid popping artifacts in
	situations with moving hard edged shadows.
	*/
	BoolID getLightEachHair(){char buffer[4096];sprintf_s (buffer, "%s.leh",mName.c_str());return (const char*)buffer;}
	/*
	<b>Displacement Scale</b> affects the amount of displacment applied from root to
	tip of the hair clump. This affects curl, noise and subclumps. If the left side
	is zero then the effect will be gradually added such that the root position of the
	hair is not changed.
	*/
	const DisplacementScaleID& getDisplacementScale(size_t dsc_i){char buffer[4096];sprintf_s (buffer, "%s.dsc[%i]",mName.c_str(),dsc_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getDisplacementScale_Position(size_t dsc_i){char buffer[4096];sprintf_s (buffer, "%s.dsc[%i].dscp",mName.c_str(),dsc_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getDisplacementScale_FloatValue(size_t dsc_i){char buffer[4096];sprintf_s (buffer, "%s.dsc[%i].dscfv",mName.c_str(),dsc_i);return (const char*)buffer;}
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
	const UnsignedintID& getDisplacementScale_Interp(size_t dsc_i){char buffer[4096];sprintf_s (buffer, "%s.dsc[%i].dsci",mName.c_str(),dsc_i);return (const char*)buffer;}
	/*
	This is the amount of curl displacement applied to each hair.
	The amount of displacement is relative to the hair width.
	The clump curl creates large scale curls about the clump center, while
	this attribute creates curls about the direction of individual hairs.
	*/
	DoubleID getCurl(){char buffer[4096];sprintf_s (buffer, "%s.crl",mName.c_str());return (const char*)buffer;}
	/*This is the rate of curl. Larger values result in more curls*/
	DoubleID getCurlFrequency(){char buffer[4096];sprintf_s (buffer, "%s.crf",mName.c_str());return (const char*)buffer;}
	/*
	Random defines the noise as a wiggle for each hair with no relation
	to neighboring hairs.
	Surface UV defines the noise displacement volumetrically
	and is relative to the uv distribution of the hairs across the
	surface. The noise is a 3D volume with a scale in U and V
	across the surface with the 3rd dimension (W) mapped down the length
	of the hairs. Clump UV defines the noise relative to the clump, and
	while neighboring clumps have completely independant noises,
	the frequency of the noise is not affected by the surface
	parametric density.
	Random is good for fuzzy, kinky hair, while the other, smoother
	noise methods can provide natural shaping and sub structure to
	hair clumps.
	*/
	UnsignedintID getNoiseMethod(){char buffer[4096];sprintf_s (buffer, "%s.nmt",mName.c_str());return (const char*)buffer;}
	/*
	This is the amount of perlin noise displacement of the hair.
	The amount of displacement is relative to the hair width when
	the noiseMethod is Random, otherwise it is relative to the
	clump width.
	This can create a knotted, kinky look to the hair.
	*/
	DoubleID getNoise(){char buffer[4096];sprintf_s (buffer, "%s.noi",mName.c_str());return (const char*)buffer;}
	/*
	This is the amount of secondary high frequency noise added
	when smooth noise is used. It can add subtle detail on top of smooth
	undulations from the base noise. If non-zero a second noise offset
	calculation is performed so this can make evaluation of the hair slightly
	slower than the smooth noise with no detail noise.
	*/
	DoubleID getDetailNoise(){char buffer[4096];sprintf_s (buffer, "%s.dno",mName.c_str());return (const char*)buffer;}
	/*
	This is the spacial scale of the noise offset along hair.
	Increasing this value results in finer kinks in the hairs.
	*/
	DoubleID getNoiseFrequency(){char buffer[4096];sprintf_s (buffer, "%s.nof",mName.c_str());return (const char*)buffer;}
	/*
	When smooth noise is used, this scales the noise frequency in the
	u parameter direction relative to the surface the
	hair is attached to.
	*/
	DoubleID getNoiseFrequencyU(){char buffer[4096];sprintf_s (buffer, "%s.nfu",mName.c_str());return (const char*)buffer;}
	/*
	When smooth noise is used, this scales the noise frequency in the
	v parameter direction relative to the surface the
	hair is attached to.
	*/
	DoubleID getNoiseFrequencyV(){char buffer[4096];sprintf_s (buffer, "%s.nfv",mName.c_str());return (const char*)buffer;}
	/*
	When smooth noise is used, this scales the noise frequency along the
	length of the hair.
	*/
	DoubleID getNoiseFrequencyW(){char buffer[4096];sprintf_s (buffer, "%s.nfw",mName.c_str());return (const char*)buffer;}
	/*
	This determines how sub clumps are defined in UV.
	If Surface UV is used the sub clumps are laid out
	relative to the overall surface uv space. Some follicles
	may thus share a clump with a neighbor follicle. The density
	of sub clumps with be affected by the parametric density
	of the surface the hair system is attached to.
	The total number of clumps across a surface will be the
	numUClumps times the numVClumps.
	If Clump UV is used then the number of subClumps for each
	clump will be the numUClumps times the numVClumps. All
	follicles, regardless of clump width, will have the same
	number of sub clumps and the width of the sub clumps will
	be relate to the clump width. With Surface UV the smaller clumps
	will have fewer sub clumps and the clump width would be relative
	to the parametric density of the surface.
	*/
	UnsignedintID getSubClumpMethod(){char buffer[4096];sprintf_s (buffer, "%s.scm",mName.c_str());return (const char*)buffer;}
	/*
	This is the amount secondary clumps pull together.
	The sub clumping is useful for a wet look. The clumps
	are defined in a grid relative to the uv space of
	the surface the hair is attached to.
	*/
	DoubleID getSubClumping(){char buffer[4096];sprintf_s (buffer, "%s.scp",mName.c_str());return (const char*)buffer;}
	/*
	This randomizes the sub clumps with a noise function.
	The clumps will get smeared into irregular shapes with
	higher values.
	*/
	DoubleID getSubClumpRand(){char buffer[4096];sprintf_s (buffer, "%s.scr",mName.c_str());return (const char*)buffer;}
	/*
	This is the number of sub clumps in the u dimension of
	surface the hair system is attached to.
	*/
	DoubleID getNumUClumps(){char buffer[4096];sprintf_s (buffer, "%s.nuc",mName.c_str());return (const char*)buffer;}
	/*
	This is the number of sub clumps in the v dimension of
	surface the hair system is attached to.
	*/
	DoubleID getNumVClumps(){char buffer[4096];sprintf_s (buffer, "%s.nvc",mName.c_str());return (const char*)buffer;}
	/*
	This interpolates hairs between neighboring clumps
	Note that when this is not zero hairs are not
	contained within the clump boundaries, and thus
	collisions with a clump may not be correct.
	*/
	DoubleID getClumpInterpolation(){char buffer[4096];sprintf_s (buffer, "%s.cin",mName.c_str());return (const char*)buffer;}
	/*
	This determines how far apart a clump may be and still
	interpolate with another clump. The distance is defined
	relative to the clump diameter, so a value of 1 would
	only interpolate clumps that just overlap.
	*/
	DoubleID getInterpolationRange(){char buffer[4096];sprintf_s (buffer, "%s.inr",mName.c_str());return (const char*)buffer;}
	/*
	This is the current time used for the hair solution.
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve), and then the solving is done based
	on that time value.  There must be some incoming connection in order
	for the hairSystem object to play back.
	*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.cti",mName.c_str());return (const char*)buffer;}
	/*
	The time after which the simulation will be run for this hair object.
	This is set from the startFrame attribute.
	Users should set startFrame instead of this attribute.
	*/
	TimeID getStartTime(){char buffer[4096];sprintf_s (buffer, "%s.sti",mName.c_str());return (const char*)buffer;}
	/*
	This is the frame after which the simulation will run. Nothing
	will play back for this object prior to startFrame.
	*/
	DoubleID getStartFrame(){char buffer[4096];sprintf_s (buffer, "%s.stf",mName.c_str());return (const char*)buffer;}
	/*
	This is the input multi-attribute where any fields acting on
	this particle object are connected.  These are accumulated
	in the computePlug() section for aForce, along with other
	forces like goals.
	*/
	const VectorArrayID& getInputForce(size_t ifc_i){char buffer[4096];sprintf_s (buffer, "%s.ifc[%i]",mName.c_str(),ifc_i);return (const char*)buffer;}
	/*
	This is the compound that holds all of the default attribute for the
	fields to connect to.  The contents are just sharing the data from
	the real attributes.
	*/
	FieldDataID getFieldData(){char buffer[4096];sprintf_s (buffer, "%s.fd",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this particle object's
	position data from.  It will share the data from aPosition.
	*/
	VectorArrayID getFieldDataPosition(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdp",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this particle object's
	velcoity data from.  It will share the data from aVelocity.
	*/
	VectorArrayID getFieldDataVelocity(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdv",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this particle object's
	mass data from.  It will share the data from aMass.
	*/
	DoubleArrayID getFieldDataMass(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdm",mName.c_str());return (const char*)buffer;}
	/*
	This is the default place that the fields will get this particle object's
	timeStep size from.  It will share the data from aTimeStepSize.
	*/
	TimeID getFieldDataDeltaTime(){char buffer[4096];sprintf_s (buffer, "%s.fd.fdt",mName.c_str());return (const char*)buffer;}
	/*
	Force evaluation changed in maya7.0 to match normal particle dynamics. Enabling
	this attribute will revert to the older behavior.
	*/
	BoolID getUsePre70ForceIntensity(){char buffer[4096];sprintf_s (buffer, "%s.upfi",mName.c_str());return (const char*)buffer;}
	/*Connection for playback cache node*/
	MessageID getDiskCache(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object casts shadows.*/
	BoolID getReceiveShadows(){char buffer[4096];sprintf_s (buffer, "%s.rcsh",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object is visible in reflections.*/
	BoolID getVisibleInReflections(){char buffer[4096];sprintf_s (buffer, "%s.vir",mName.c_str());return (const char*)buffer;}
	/*The flag to control if this object is visible in refractions.*/
	BoolID getVisibleInRefractions(){char buffer[4096];sprintf_s (buffer, "%s.vif",mName.c_str());return (const char*)buffer;}
	/*This is a root of following mental ray attributes.*/
	MentalRayControlsID getMentalRayControls(){char buffer[4096];sprintf_s (buffer, "%s.mrc",mName.c_str());return (const char*)buffer;}
	/*
	Enable caustic settings override for this shape.
	If this parameter is set,
	the following caustics settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideCaustics(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oca",mName.c_str());return (const char*)buffer;}
	/*Caustic accuracy for this shape if <b>miOverrideCaustics</b> is on.*/
	ShortID getMiCausticAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.caa",mName.c_str());return (const char*)buffer;}
	/*Caustic radius for this shape if <b>miOverrideCaustics</b> is on.*/
	FloatID getMiCausticRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.car",mName.c_str());return (const char*)buffer;}
	/*
	Enable global illumination settings override for this shape.
	If this parameter is set,
	the following global illumination settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideGlobalIllumination(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ogi",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination accuracy for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	ShortID getMiGlobillumAccuracy(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gia",mName.c_str());return (const char*)buffer;}
	/*
	Global illumination radius for this shape
	if <b>miOverrideGlobalIllumination</b> is on.
	*/
	FloatID getMiGlobillumRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.gir",mName.c_str());return (const char*)buffer;}
	/*
	Enable final gather settings override for this shape.
	If this parameter is set,
	the following final gather settings will override
	the renddr global settings for this shape node.
	*/
	BoolID getMiOverrideFinalGather(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ofg",mName.c_str());return (const char*)buffer;}
	/*Final gather rays for this shape if <b>miOverrideFinalGather</b> is on.*/
	IntID getMiFinalGatherRays(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fry",mName.c_str());return (const char*)buffer;}
	/*Final gather min radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMinRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmn",mName.c_str());return (const char*)buffer;}
	/*Final gather max radius for this shape if <b>miOverrideFinalGather</b> is on.*/
	FloatID getMiFinalGatherMaxRadius(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fmx",mName.c_str());return (const char*)buffer;}
	/*Final gather filter for this shape if <b>miOverrideFinalGather</b> is on.*/
	ShortID getMiFinalGatherFilter(){char buffer[4096];sprintf_s (buffer, "%s.mrc.ffi",mName.c_str());return (const char*)buffer;}
	/*Final gather view flag for this shape if <b>miOverrideFinalGather</b> is on.*/
	BoolID getMiFinalGatherView(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgv",mName.c_str());return (const char*)buffer;}
	/*
	Override global object sample settings.
	In addition to global sample settings
	mental ray supports per-object sample settings.
	The global mental ray default for all objects in the scene
	can be set by <b>minObjectSamples</b> and <b>maxObjectSamples</b>
	on the mental ray options node (miDefaultOptions).
	Similar attributes on individual shape nodes
	<b>miMinSamples</b> and <b>miMaxSamples</b>
	are overriding the global default,
	within global samples range.
	*/
	BoolID getMiOverrideSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.oos",mName.c_str());return (const char*)buffer;}
	/*
	Specifies min sample settings for the shape.
	For all pixels that touch this object,
	at least pow(2, <b>miMinSamples</b>) samples are taken.
	<b>miMinSamples</b> lower than the global min samples is ignored.
	*/
	ShortID getMiMinSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.mins",mName.c_str());return (const char*)buffer;}
	/*
	Specifies max sample settings for the shape.
	For all pixels that touch this object,
	at most pow(2, <b>miMaxSamples</b>) samples are taken.
	<b>miMaxSamples</b> higher than the global max samples is ignored.
	*/
	ShortID getMiMaxSamples(){char buffer[4096];sprintf_s (buffer, "%s.mrc.maxs",mName.c_str());return (const char*)buffer;}
	/*
	The object casts final gather rays if <b>miFinalGatherCast</b> is on,
	which means that the object participates in final gather.
	*/
	BoolID getMiFinalGatherCast(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fgc",mName.c_str());return (const char*)buffer;}
	/*
	The object receives final gather rays if <b>miFinalGatherReceive</b> is on,
	which means that the object is not affected by final gathering.
	*/
	BoolID getMiFinalGatherReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.fge",mName.c_str());return (const char*)buffer;}
	/*
	The object casts transparent rays if <b>miTransparencyCast</b> is on.
	thus shown through transparent object if ray depth has not been reached the limit.
	*/
	BoolID getMiTransparencyCast(){char buffer[4096];sprintf_s (buffer, "%s.mrc.tpc",mName.c_str());return (const char*)buffer;}
	/*The object receives transparent rays if <b>miTransparencyReceive</b> is on.*/
	BoolID getMiTransparencyReceive(){char buffer[4096];sprintf_s (buffer, "%s.mrc.tpr",mName.c_str());return (const char*)buffer;}
	/*
	Output array of polylines (double point arrays) that represet the current
	position of the dynamically solved hairs.
	*/
	const VectorArrayID& getOutputHair(size_t oh_i){char buffer[4096];sprintf_s (buffer, "%s.oh[%i]",mName.c_str(),oh_i);return (const char*)buffer;}
	/*
	Output of the hair system for paint effects rendering. This connection passes the
	positions and widths of all dynamically solved hairs in addition to shading attributes.
	*/
	HairRenderInfoID getOutputRenderHairs(){char buffer[4096];sprintf_s (buffer, "%s.orh",mName.c_str());return (const char*)buffer;}
protected:
	HairSystem(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HAIRSYSTEM_H__
