/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FOLLICLE_H__
#define __MayaDM_FOLLICLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
This node builds the hair structure required by the hairSystem node.
 It also holds per hair attributes that can be used to override the
 global hairSystem simulation attributes. It takes an input start and rest position curve
 as well as a surface and position on that surface.
 It generates polylines that are then passed to the hairSystem node. The current position
 from the hairSystem is then passed back to this node as an array of points. The follicle node then
 turns this array of points into an output nurbs curve for use by other nodes, such as a paint effects stroke.
 <p/>
*/
class Follicle : public Shape
{
public:
	/*
	<b>Stiffness Scale</b> affects the stiffness from root to tip of the hair.
	The left of the graph is the root and the right is the tip. Typically the root of a
	hair is thicker and thus stiffer than the tip. This attribute multiplies
	the stiffness parameter value, so a value of 1.0 will leave the stiffness unchanged.
	Note that there is also a stiffnessScale attribute ramp on the hair system shape
	node which affects all hairs in the system. This per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
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
	<b>Clump Width Scale</b> scales the clumpWidth attribute along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	As a dynamic hair parameter, it is only used when the overrideDynamics attribute
	is enabled. Otherwise, the clumpWidth and clumpWidthScale values on the
	hairSystemShape node are used instead. For dynamic follicles, the effective clump width
	is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
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
	This value attenuates the startCurveAttract value along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	If the startCurveAttract attribute is zero then this parameter will have no effect,
	as zero times a number is always zero.
	There is also a corresponding attractionScale parameter on
	the hair system node which has the same effect only for all hairs.
	This  per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
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
public:
	Follicle(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "follicle"){}
	virtual ~Follicle(){}
	/*Input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Input mesh*/
	void setInputMesh(const MeshID& inm){fprintf_s(mFile,"connectAttr \"");inm.write(mFile);fprintf_s(mFile,"\" \"%s.inm\";\n",mName.c_str());}
	/*Input matrix from mesh or surface*/
	void setInputWorldMatrix(const MatrixID& iwm){fprintf_s(mFile,"connectAttr \"");iwm.write(mFile);fprintf_s(mFile,"\" \"%s.iwm\";\n",mName.c_str());}
	/*U parameter value on surface*/
	void setParameterU(double pu){if(pu == 0.0) return; fprintf_s(mFile, "setAttr \".pu\" %f;\n", pu);}
	/*U parameter value on surface*/
	void setParameterU(const DoubleID& pu){fprintf_s(mFile,"connectAttr \"");pu.write(mFile);fprintf_s(mFile,"\" \"%s.pu\";\n",mName.c_str());}
	/*V parameter value on surface*/
	void setParameterV(double pv){if(pv == 0.0) return; fprintf_s(mFile, "setAttr \".pv\" %f;\n", pv);}
	/*V parameter value on surface*/
	void setParameterV(const DoubleID& pv){fprintf_s(mFile,"connectAttr \"");pv.write(mFile);fprintf_s(mFile,"\" \"%s.pv\";\n",mName.c_str());}
	/*Input start position curve*/
	void setStartPosition(const NurbsCurveID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*Input rest position curve*/
	void setRestPosition(const NurbsCurveID& rp){fprintf_s(mFile,"connectAttr \"");rp.write(mFile);fprintf_s(mFile,"\" \"%s.rp\";\n",mName.c_str());}
	/*Input poly line from hair system node. This is converted to an output nurbs curve.*/
	void setCurrentPosition(const VectorArrayID& crp){fprintf_s(mFile,"connectAttr \"");crp.write(mFile);fprintf_s(mFile,"\" \"%s.crp\";\n",mName.c_str());}
	/*
	This specifies how the rest position of the hair used by dynamic computations is determined.
	It may be straight, based on the start curve position or a separate input curve may be used.
	"start minus gravity" attempts to compute a rest position based on gravity and the hair stiffness
	such that the hair is in dynamic equilibrium at the start of the simulation. If "same as start" is used
	then the hair will fall at the beginning if there is any gravity and the hair is not totally stiff.
	*/
	void setRestPose(unsigned int rsp){if(rsp == 0) return; fprintf_s(mFile, "setAttr \".rsp\" %i;\n", rsp);}
	/*
	This specifies how the rest position of the hair used by dynamic computations is determined.
	It may be straight, based on the start curve position or a separate input curve may be used.
	"start minus gravity" attempts to compute a rest position based on gravity and the hair stiffness
	such that the hair is in dynamic equilibrium at the start of the simulation. If "same as start" is used
	then the hair will fall at the beginning if there is any gravity and the hair is not totally stiff.
	*/
	void setRestPose(const UnsignedintID& rsp){fprintf_s(mFile,"connectAttr \"");rsp.write(mFile);fprintf_s(mFile,"\" \"%s.rsp\";\n",mName.c_str());}
	/*
	This specifies where the hair is attached relative to the start position.
	One may constrain the base( like a normal hair), both ends( like a rope attached at either end ),
	or with no attachments the hair will fall like a loose string that is dropped. One can animate
	this parameter to detach a hair during a simulation.
	*/
	void setPointLock(unsigned int ptl){if(ptl == 1) return; fprintf_s(mFile, "setAttr \".ptl\" %i;\n", ptl);}
	/*
	This specifies where the hair is attached relative to the start position.
	One may constrain the base( like a normal hair), both ends( like a rope attached at either end ),
	or with no attachments the hair will fall like a loose string that is dropped. One can animate
	this parameter to detach a hair during a simulation.
	*/
	void setPointLock(const UnsignedintID& ptl){fprintf_s(mFile,"connectAttr \"");ptl.write(mFile);fprintf_s(mFile,"\" \"%s.ptl\";\n",mName.c_str());}
	/*
	This specifies how to apply dynamic motion to the hair. If static then no dynamics are computed for the hair,
	which will appear totally stiff in the start position.
	Dynamic computes the hair position based on forces and collisions. Passive moves it by interpolating the
	motion of neighboring dynamic hairs, which can be an efficient way of simulating masses of hair in self collision.
	*/
	void setSimulationMethod(unsigned int sim){if(sim == 2) return; fprintf_s(mFile, "setAttr \".sim\" %i;\n", sim);}
	/*
	This specifies how to apply dynamic motion to the hair. If static then no dynamics are computed for the hair,
	which will appear totally stiff in the start position.
	Dynamic computes the hair position based on forces and collisions. Passive moves it by interpolating the
	motion of neighboring dynamic hairs, which can be an efficient way of simulating masses of hair in self collision.
	*/
	void setSimulationMethod(const UnsignedintID& sim){fprintf_s(mFile,"connectAttr \"");sim.write(mFile);fprintf_s(mFile,"\" \"%s.sim\";\n",mName.c_str());}
	/*
	This determines the initial direction a hair emits from the follicle.
	This is used when determining rest deflections, as well
	as when increasing subsegments on the hairsystem. If the restPose is straight
	and this is set to start curve, the hair will try to assume a straight line based
	on the first segment of the start curve. If surface normal is selected then
	the hair would instead move towards a line coming straight out of the surface.
	IF this is set to surface normal then subsegments in the hairsystem will refine
	such that the root of the hair is normal to the surface.
	*/
	void setStartDirection(unsigned int sdr){if(sdr == 0) return; fprintf_s(mFile, "setAttr \".sdr\" %i;\n", sdr);}
	/*
	This determines the initial direction a hair emits from the follicle.
	This is used when determining rest deflections, as well
	as when increasing subsegments on the hairsystem. If the restPose is straight
	and this is set to start curve, the hair will try to assume a straight line based
	on the first segment of the start curve. If surface normal is selected then
	the hair would instead move towards a line coming straight out of the surface.
	IF this is set to surface normal then subsegments in the hairsystem will refine
	such that the root of the hair is normal to the surface.
	*/
	void setStartDirection(const UnsignedintID& sdr){fprintf_s(mFile,"connectAttr \"");sdr.write(mFile);fprintf_s(mFile,"\" \"%s.sdr\";\n",mName.c_str());}
	/*If true then emit the hair from the opposite side of the input surface.*/
	void setFlipDirection(bool fld){if(fld == false) return; fprintf_s(mFile, "setAttr \".fld\" %i;\n", fld);}
	/*If true then emit the hair from the opposite side of the input surface.*/
	void setFlipDirection(const BoolID& fld){fprintf_s(mFile,"connectAttr \"");fld.write(mFile);fprintf_s(mFile,"\" \"%s.fld\";\n",mName.c_str());}
	/*The global gravity value from the simulation node. (used by RestPose )*/
	void setHairSysGravity(double hsg){if(hsg == 1.0) return; fprintf_s(mFile, "setAttr \".hsg\" %f;\n", hsg);}
	/*The global gravity value from the simulation node. (used by RestPose )*/
	void setHairSysGravity(const DoubleID& hsg){fprintf_s(mFile,"connectAttr \"");hsg.write(mFile);fprintf_s(mFile,"\" \"%s.hsg\";\n",mName.c_str());}
	/*The global hair stiffness value from the simulation node. (used by RestPose )*/
	void setHairSysStiffness(double hss){if(hss == 0.5) return; fprintf_s(mFile, "setAttr \".hss\" %f;\n", hss);}
	/*The global hair stiffness value from the simulation node. (used by RestPose )*/
	void setHairSysStiffness(const DoubleID& hss){fprintf_s(mFile,"connectAttr \"");hss.write(mFile);fprintf_s(mFile,"\" \"%s.hss\";\n",mName.c_str());}
	/*If true then use the local hair settings rather then the global hairSystem ones*/
	void setOverrideDynamics(bool ovd){if(ovd == false) return; fprintf_s(mFile, "setAttr \".ovd\" %i;\n", ovd);}
	/*If true then use the local hair settings rather then the global hairSystem ones*/
	void setOverrideDynamics(const BoolID& ovd){fprintf_s(mFile,"connectAttr \"");ovd.write(mFile);fprintf_s(mFile,"\" \"%s.ovd\";\n",mName.c_str());}
	/*If true then collide this hair with geometry if the global hairSystem has collisions*/
	void setCollide(bool cld){if(cld == true) return; fprintf_s(mFile, "setAttr \".cld\" %i;\n", cld);}
	/*If true then collide this hair with geometry if the global hairSystem has collisions*/
	void setCollide(const BoolID& cld){fprintf_s(mFile,"connectAttr \"");cld.write(mFile);fprintf_s(mFile,"\" \"%s.cld\";\n",mName.c_str());}
	/*This overrides the damp on the hairSystem. It can be used to stablize problem hairs.*/
	void setDamp(double dmp){if(dmp == 0.0) return; fprintf_s(mFile, "setAttr \".dmp\" %f;\n", dmp);}
	/*This overrides the damp on the hairSystem. It can be used to stablize problem hairs.*/
	void setDamp(const DoubleID& dmp){fprintf_s(mFile,"connectAttr \"");dmp.write(mFile);fprintf_s(mFile,"\" \"%s.dmp\";\n",mName.c_str());}
	/*The amount the hair can flex with regard to the rest position.*/
	void setStiffness(double stf){if(stf == 0.15) return; fprintf_s(mFile, "setAttr \".stf\" %f;\n", stf);}
	/*The amount the hair can flex with regard to the rest position.*/
	void setStiffness(const DoubleID& stf){fprintf_s(mFile,"connectAttr \"");stf.write(mFile);fprintf_s(mFile,"\" \"%s.stf\";\n",mName.c_str());}
	/*
	<b>Stiffness Scale</b> affects the stiffness from root to tip of the hair.
	The left of the graph is the root and the right is the tip. Typically the root of a
	hair is thicker and thus stiffer than the tip. This attribute multiplies
	the stiffness parameter value, so a value of 1.0 will leave the stiffness unchanged.
	Note that there is also a stiffnessScale attribute ramp on the hair system shape
	node which affects all hairs in the system. This per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
	*/
	void setStiffnessScale(size_t sts_i,const StiffnessScale& sts){fprintf_s(mFile, "setAttr \".sts[%i]\" ",sts_i);sts.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Stiffness Scale</b> affects the stiffness from root to tip of the hair.
	The left of the graph is the root and the right is the tip. Typically the root of a
	hair is thicker and thus stiffer than the tip. This attribute multiplies
	the stiffness parameter value, so a value of 1.0 will leave the stiffness unchanged.
	Note that there is also a stiffnessScale attribute ramp on the hair system shape
	node which affects all hairs in the system. This per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
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
	/*The amount the simulated hair can stretch along its length.*/
	void setLengthFlex(double lfl){if(lfl == 0.0) return; fprintf_s(mFile, "setAttr \".lfl\" %f;\n", lfl);}
	/*The amount the simulated hair can stretch along its length.*/
	void setLengthFlex(const DoubleID& lfl){fprintf_s(mFile,"connectAttr \"");lfl.write(mFile);fprintf_s(mFile,"\" \"%s.lfl\";\n",mName.c_str());}
	/*
	This scales the hair clump relative to the global hair clump width
	on the hair system node. If the hair clump width on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	Note that this will also affect the overall number of hairs within a clump, such that
	the density per unit remains roughly constant.<br/>
	Note that there are also clumpWidth and clumpWidthScale attributes that are in
	effect only when the overrideDynamics attribute is toggled on. For dynamic hairs,
	these two additional attributes can be used to more finely tune the clump width,
	including varying the width along the length of the follicle. For dynamic follicles,
	the effective clump width is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
	*/
	void setClumpWidthMult(double cwm){if(cwm == 1.0) return; fprintf_s(mFile, "setAttr \".cwm\" %f;\n", cwm);}
	/*
	This scales the hair clump relative to the global hair clump width
	on the hair system node. If the hair clump width on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	Note that this will also affect the overall number of hairs within a clump, such that
	the density per unit remains roughly constant.<br/>
	Note that there are also clumpWidth and clumpWidthScale attributes that are in
	effect only when the overrideDynamics attribute is toggled on. For dynamic hairs,
	these two additional attributes can be used to more finely tune the clump width,
	including varying the width along the length of the follicle. For dynamic follicles,
	the effective clump width is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
	*/
	void setClumpWidthMult(const DoubleID& cwm){fprintf_s(mFile,"connectAttr \"");cwm.write(mFile);fprintf_s(mFile,"\" \"%s.cwm\";\n",mName.c_str());}
	/*
	<b>Clump Width Scale</b> scales the clumpWidth attribute along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	As a dynamic hair parameter, it is only used when the overrideDynamics attribute
	is enabled. Otherwise, the clumpWidth and clumpWidthScale values on the
	hairSystemShape node are used instead. For dynamic follicles, the effective clump width
	is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
	*/
	void setClumpWidthScale(size_t cws_i,const ClumpWidthScale& cws){fprintf_s(mFile, "setAttr \".cws[%i]\" ",cws_i);cws.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Clump Width Scale</b> scales the clumpWidth attribute along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	As a dynamic hair parameter, it is only used when the overrideDynamics attribute
	is enabled. Otherwise, the clumpWidth and clumpWidthScale values on the
	hairSystemShape node are used instead. For dynamic follicles, the effective clump width
	is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
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
	especially if there are many cvs per hair. Note that there is an
	identical startCurveAttract on the hair system node. This per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
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
	especially if there are many cvs per hair. Note that there is an
	identical startCurveAttract on the hair system node. This per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
	*/
	void setStartCurveAttract(const DoubleID& sct){fprintf_s(mFile,"connectAttr \"");sct.write(mFile);fprintf_s(mFile,"\" \"%s.sct\";\n",mName.c_str());}
	/*
	This value attenuates the startCurveAttract value along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	If the startCurveAttract attribute is zero then this parameter will have no effect,
	as zero times a number is always zero.
	There is also a corresponding attractionScale parameter on
	the hair system node which has the same effect only for all hairs.
	This  per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
	*/
	void setAttractionScale(size_t ats_i,const AttractionScale& ats){fprintf_s(mFile, "setAttr \".ats[%i]\" ",ats_i);ats.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This value attenuates the startCurveAttract value along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	If the startCurveAttract attribute is zero then this parameter will have no effect,
	as zero times a number is always zero.
	There is also a corresponding attractionScale parameter on
	the hair system node which has the same effect only for all hairs.
	This  per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
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
	Attenuates the effect of startCurveAttract on a per-follicle basis.
	The actual attraction to the start curve is performed by altering the
	current velocity of the hair so that it will meet the
	start position. This control attenuates this value.
	When this value is one, the motion towards the start
	curve is fully attenuated, leaving simply the start position
	plus field forces.  This is useful for applying fields on top
	of previously animated hairs.  To acheive this affect,
	you should set attractionDamp = 1.0 and make the stiffness
	ramp all 1.0. There is also a corresponding attenuation parameter on
	the hair system node which has the same effect only for all hairs.
	This  per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
	*/
	void setAttractionDamp(double ad){if(ad == 0.0) return; fprintf_s(mFile, "setAttr \".ad\" %f;\n", ad);}
	/*
	Attenuates the effect of startCurveAttract on a per-follicle basis.
	The actual attraction to the start curve is performed by altering the
	current velocity of the hair so that it will meet the
	start position. This control attenuates this value.
	When this value is one, the motion towards the start
	curve is fully attenuated, leaving simply the start position
	plus field forces.  This is useful for applying fields on top
	of previously animated hairs.  To acheive this affect,
	you should set attractionDamp = 1.0 and make the stiffness
	ramp all 1.0. There is also a corresponding attenuation parameter on
	the hair system node which has the same effect only for all hairs.
	This  per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
	*/
	void setAttractionDamp(const DoubleID& ad){fprintf_s(mFile,"connectAttr \"");ad.write(mFile);fprintf_s(mFile,"\" \"%s.ad\";\n",mName.c_str());}
	/*
	This scales the number of hairs relative to the global hair per clump
	on the hair system node. If the hairs per clump  on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	void setDensityMult(double dml){if(dml == 1.0) return; fprintf_s(mFile, "setAttr \".dml\" %f;\n", dml);}
	/*
	This scales the number of hairs relative to the global hair per clump
	on the hair system node. If the hairs per clump  on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	void setDensityMult(const DoubleID& dml){fprintf_s(mFile,"connectAttr \"");dml.write(mFile);fprintf_s(mFile,"\" \"%s.dml\";\n",mName.c_str());}
	/*
	This scales the curl rate relative to the global hair curl attribute
	on the hair system node. If the curl on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	void setCurlMult(double cml){if(cml == 1.0) return; fprintf_s(mFile, "setAttr \".cml\" %f;\n", cml);}
	/*
	This scales the curl rate relative to the global hair curl attribute
	on the hair system node. If the curl on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	void setCurlMult(const DoubleID& cml){fprintf_s(mFile,"connectAttr \"");cml.write(mFile);fprintf_s(mFile,"\" \"%s.cml\";\n",mName.c_str());}
	/*
	This affects the rotation of the individual hair clump about the central hair axis.
	This adds onto the global twist defined on the hair system node.
	If the twist on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	void setClumpTwistOffset(double ctf){if(ctf == 0.0) return; fprintf_s(mFile, "setAttr \".ctf\" %f;\n", ctf);}
	/*
	This affects the rotation of the individual hair clump about the central hair axis.
	This adds onto the global twist defined on the hair system node.
	If the twist on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	void setClumpTwistOffset(const DoubleID& ctf){fprintf_s(mFile,"connectAttr \"");ctf.write(mFile);fprintf_s(mFile,"\" \"%s.ctf\";\n",mName.c_str());}
	/*If true then the clump is split into 3 sub groupings that are braided.*/
	void setBraid(bool brd){if(brd == false) return; fprintf_s(mFile, "setAttr \".brd\" %i;\n", brd);}
	/*If true then the clump is split into 3 sub groupings that are braided.*/
	void setBraid(const BoolID& brd){fprintf_s(mFile,"connectAttr \"");brd.write(mFile);fprintf_s(mFile,"\" \"%s.brd\";\n",mName.c_str());}
	/*
	This allows one to have a different base color per hair clump.
	The attribute value determines the proportion the global color is
	is blended with the local color attribute. If the value is zero than
	the hair color is determined by the global hair color on the hair system node.
	If the value is 1.0 then the color is entirely the color attribute on this node.
	In between values blend between the two values.
	*/
	void setColorBlend(double cbl){if(cbl == 0.0) return; fprintf_s(mFile, "setAttr \".cbl\" %f;\n", cbl);}
	/*
	This allows one to have a different base color per hair clump.
	The attribute value determines the proportion the global color is
	is blended with the local color attribute. If the value is zero than
	the hair color is determined by the global hair color on the hair system node.
	If the value is 1.0 then the color is entirely the color attribute on this node.
	In between values blend between the two values.
	*/
	void setColorBlend(const DoubleID& cbl){fprintf_s(mFile,"connectAttr \"");cbl.write(mFile);fprintf_s(mFile,"\" \"%s.cbl\";\n",mName.c_str());}
	/*input color*/
	void setColor(const float3& cl){fprintf_s(mFile, "setAttr \".cl\" -type \"float3\" ");cl.write(mFile);fprintf_s(mFile,";\n");}
	/*input color*/
	void setColor(const Float3ID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*color Red value*/
	void setColorR(float cr){if(cr == 0.0) return; fprintf_s(mFile, "setAttr \".cl.cr\" %f;\n", cr);}
	/*color Red value*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cr\";\n",mName.c_str());}
	/*color Green value*/
	void setColorG(float cg){if(cg == 0.0) return; fprintf_s(mFile, "setAttr \".cl.cg\" %f;\n", cg);}
	/*color Green value*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cg\";\n",mName.c_str());}
	/*color Blue value*/
	void setColorB(float cb){if(cb == 0.0) return; fprintf_s(mFile, "setAttr \".cl.cb\" %f;\n", cb);}
	/*color Blue value*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.cl.cb\";\n",mName.c_str());}
	/*
	Toggles how input curves are sampled. When this attribute is on,
	segmentLength attribute is used to determine the number of CVs
	sampled on the input curve. When the value is false,
	sampleDensity is used to compute the number points sampled.
	*/
	void setFixedSegmentLength(bool fsl){if(fsl == 0) return; fprintf_s(mFile, "setAttr \".fsl\" %i;\n", fsl);}
	/*
	Toggles how input curves are sampled. When this attribute is on,
	segmentLength attribute is used to determine the number of CVs
	sampled on the input curve. When the value is false,
	sampleDensity is used to compute the number points sampled.
	*/
	void setFixedSegmentLength(const BoolID& fsl){fprintf_s(mFile,"connectAttr \"");fsl.write(mFile);fprintf_s(mFile,"\" \"%s.fsl\";\n",mName.c_str());}
	/*
	Specifies how long each segment on the hair should be. This
	is another way of sampling the input curve, used when
	fixedSegmentLength is on.  Using a fixed segment length
	can provide more realistic hair simulation when the length
	of the hair varies across the same hair system.  Setting
	a consistent segment length across all hairs will make longer
	hai rs have more CVs and shorter hairs have less CVs.
	*/
	void setSegmentLength(double sgl){if(sgl == 1) return; fprintf_s(mFile, "setAttr \".sgl\" %f;\n", sgl);}
	/*
	Specifies how long each segment on the hair should be. This
	is another way of sampling the input curve, used when
	fixedSegmentLength is on.  Using a fixed segment length
	can provide more realistic hair simulation when the length
	of the hair varies across the same hair system.  Setting
	a consistent segment length across all hairs will make longer
	hai rs have more CVs and shorter hairs have less CVs.
	*/
	void setSegmentLength(const DoubleID& sgl){fprintf_s(mFile,"connectAttr \"");sgl.write(mFile);fprintf_s(mFile,"\" \"%s.sgl\";\n",mName.c_str());}
	/*
	This controls the number of points to sample along the input
	start and rest position curves when generating the outHair to
	pass to the simulation node. A value of one will cause the simulation
	hair to have the same number of poly line segments as the curve has
	cvs. A value of 2.0 will will double the number of segments, while a value of 0.0
	will result in a single segment. This can dramatically affect the speed and quality
	of the simulation.
	*/
	void setSampleDensity(double sdn){if(sdn == 1.0) return; fprintf_s(mFile, "setAttr \".sdn\" %f;\n", sdn);}
	/*
	This controls the number of points to sample along the input
	start and rest position curves when generating the outHair to
	pass to the simulation node. A value of one will cause the simulation
	hair to have the same number of poly line segments as the curve has
	cvs. A value of 2.0 will will double the number of segments, while a value of 0.0
	will result in a single segment. This can dramatically affect the speed and quality
	of the simulation.
	*/
	void setSampleDensity(const DoubleID& sdn){fprintf_s(mFile,"connectAttr \"");sdn.write(mFile);fprintf_s(mFile,"\" \"%s.sdn\";\n",mName.c_str());}
	/*The degree of the final generated output curve.*/
	void setDegree(int dgr){if(dgr == 2) return; fprintf_s(mFile, "setAttr \".dgr\" %i;\n", dgr);}
	/*The degree of the final generated output curve.*/
	void setDegree(const IntID& dgr){fprintf_s(mFile,"connectAttr \"");dgr.write(mFile);fprintf_s(mFile,"\" \"%s.dgr\";\n",mName.c_str());}
	/*
	This is the base or maximum width for the dynamic hair groups.
	As a dynamic hair parameter, it is only used when the overrideDynamics attribute
	is enabled. Otherwise, the clumpWidth and clumpWidthScale values on the
	hairSystemShape node are used instead. For dynamic follicles, the effective clump width
	is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
	Unlike <b>Clump Width Mult</b>, this attribute has no effect on the number of
	hairs per clump. It thus provides a way of scaling without affecting density.
	*/
	void setClumpWidth(float cw){if(cw == 0.3) return; fprintf_s(mFile, "setAttr \".cw\" %f;\n", cw);}
	/*
	This is the base or maximum width for the dynamic hair groups.
	As a dynamic hair parameter, it is only used when the overrideDynamics attribute
	is enabled. Otherwise, the clumpWidth and clumpWidthScale values on the
	hairSystemShape node are used instead. For dynamic follicles, the effective clump width
	is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
	Unlike <b>Clump Width Mult</b>, this attribute has no effect on the number of
	hairs per clump. It thus provides a way of scaling without affecting density.
	*/
	void setClumpWidth(const FloatID& cw){fprintf_s(mFile,"connectAttr \"");cw.write(mFile);fprintf_s(mFile,"\" \"%s.cw\";\n",mName.c_str());}
	/*world position of hair base*/
	void setOutTranslate(const Double3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*X value of outTranslate*/
	void setOutTranslateX(const DoubleID& otx){fprintf_s(mFile,"connectAttr \"");otx.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otx\";\n",mName.c_str());}
	/*Y value of outTranslate*/
	void setOutTranslateY(const DoubleID& oty){fprintf_s(mFile,"connectAttr \"");oty.write(mFile);fprintf_s(mFile,"\" \"%s.ot.oty\";\n",mName.c_str());}
	/*Z value of outTranslate*/
	void setOutTranslateZ(const DoubleID& otz){fprintf_s(mFile,"connectAttr \"");otz.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otz\";\n",mName.c_str());}
	/*world rotation of hair base*/
	void setOutRotate(const Double3ID& or){fprintf_s(mFile,"connectAttr \"");or.write(mFile);fprintf_s(mFile,"\" \"%s.or\";\n",mName.c_str());}
	/*X value of outRotate*/
	void setOutRotateX(const DoubleID& orx){fprintf_s(mFile,"connectAttr \"");orx.write(mFile);fprintf_s(mFile,"\" \"%s.or.orx\";\n",mName.c_str());}
	/*Y value of outRotate*/
	void setOutRotateY(const DoubleID& ory){fprintf_s(mFile,"connectAttr \"");ory.write(mFile);fprintf_s(mFile,"\" \"%s.or.ory\";\n",mName.c_str());}
	/*Z value of outRotate*/
	void setOutRotateZ(const DoubleID& orz){fprintf_s(mFile,"connectAttr \"");orz.write(mFile);fprintf_s(mFile,"\" \"%s.or.orz\";\n",mName.c_str());}
	/*twist vector at hair base*/
	void setOutTangent(const Double3ID& otn){fprintf_s(mFile,"connectAttr \"");otn.write(mFile);fprintf_s(mFile,"\" \"%s.otn\";\n",mName.c_str());}
	/*X value of outTangent*/
	void setOutTangentX(const DoubleID& otnx){fprintf_s(mFile,"connectAttr \"");otnx.write(mFile);fprintf_s(mFile,"\" \"%s.otn.otnx\";\n",mName.c_str());}
	/*Y value of outTangent*/
	void setOutTangentY(const DoubleID& otny){fprintf_s(mFile,"connectAttr \"");otny.write(mFile);fprintf_s(mFile,"\" \"%s.otn.otny\";\n",mName.c_str());}
	/*Z value of outTangent*/
	void setOutTangentZ(const DoubleID& otnz){fprintf_s(mFile,"connectAttr \"");otnz.write(mFile);fprintf_s(mFile,"\" \"%s.otn.otnz\";\n",mName.c_str());}
	/*normal at hair base with elevation and azimuth applied*/
	void setOutNormal(const Double3ID& onm){fprintf_s(mFile,"connectAttr \"");onm.write(mFile);fprintf_s(mFile,"\" \"%s.onm\";\n",mName.c_str());}
	/*X value of outNormal*/
	void setOutNormalX(const DoubleID& onx){fprintf_s(mFile,"connectAttr \"");onx.write(mFile);fprintf_s(mFile,"\" \"%s.onm.onx\";\n",mName.c_str());}
	/*Y value of outNormal*/
	void setOutNormalY(const DoubleID& ony){fprintf_s(mFile,"connectAttr \"");ony.write(mFile);fprintf_s(mFile,"\" \"%s.onm.ony\";\n",mName.c_str());}
	/*Z value of outNormal*/
	void setOutNormalZ(const DoubleID& onz){fprintf_s(mFile,"connectAttr \"");onz.write(mFile);fprintf_s(mFile,"\" \"%s.onm.onz\";\n",mName.c_str());}
	/*output hair data for use by hairSystemShape node*/
	void setOutHair(const HairCurveID& oha){fprintf_s(mFile,"connectAttr \"");oha.write(mFile);fprintf_s(mFile,"\" \"%s.oha\";\n",mName.c_str());}
	/*output hair data for use by hairSystemShape node*/
	void setOutCurve(const NurbsCurveID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.ocr\";\n",mName.c_str());}
	/*If false then the specified uv for input mesh is not currently defined.*/
	void setValidUv(const BoolID& vuv){fprintf_s(mFile,"connectAttr \"");vuv.write(mFile);fprintf_s(mFile,"\" \"%s.vuv\";\n",mName.c_str());}
	/*The Name of the mapset of the poly on which follicle is present*/
	void setMapSetName(const string& msn){if(msn == "NULL") return; fprintf_s(mFile, "setAttr \".msn\" -type \"string\" ");msn.write(mFile);fprintf_s(mFile,";\n");}
	/*The Name of the mapset of the poly on which follicle is present*/
	void setMapSetName(const StringID& msn){fprintf_s(mFile,"connectAttr \"");msn.write(mFile);fprintf_s(mFile,"\" \"%s.msn\";\n",mName.c_str());}
	/*Input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Input mesh*/
	MeshID getInputMesh(){char buffer[4096];sprintf_s (buffer, "%s.inm",mName.c_str());return (const char*)buffer;}
	/*Input matrix from mesh or surface*/
	MatrixID getInputWorldMatrix(){char buffer[4096];sprintf_s (buffer, "%s.iwm",mName.c_str());return (const char*)buffer;}
	/*U parameter value on surface*/
	DoubleID getParameterU(){char buffer[4096];sprintf_s (buffer, "%s.pu",mName.c_str());return (const char*)buffer;}
	/*V parameter value on surface*/
	DoubleID getParameterV(){char buffer[4096];sprintf_s (buffer, "%s.pv",mName.c_str());return (const char*)buffer;}
	/*Input start position curve*/
	NurbsCurveID getStartPosition(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*Input rest position curve*/
	NurbsCurveID getRestPosition(){char buffer[4096];sprintf_s (buffer, "%s.rp",mName.c_str());return (const char*)buffer;}
	/*Input poly line from hair system node. This is converted to an output nurbs curve.*/
	VectorArrayID getCurrentPosition(){char buffer[4096];sprintf_s (buffer, "%s.crp",mName.c_str());return (const char*)buffer;}
	/*
	This specifies how the rest position of the hair used by dynamic computations is determined.
	It may be straight, based on the start curve position or a separate input curve may be used.
	"start minus gravity" attempts to compute a rest position based on gravity and the hair stiffness
	such that the hair is in dynamic equilibrium at the start of the simulation. If "same as start" is used
	then the hair will fall at the beginning if there is any gravity and the hair is not totally stiff.
	*/
	UnsignedintID getRestPose(){char buffer[4096];sprintf_s (buffer, "%s.rsp",mName.c_str());return (const char*)buffer;}
	/*
	This specifies where the hair is attached relative to the start position.
	One may constrain the base( like a normal hair), both ends( like a rope attached at either end ),
	or with no attachments the hair will fall like a loose string that is dropped. One can animate
	this parameter to detach a hair during a simulation.
	*/
	UnsignedintID getPointLock(){char buffer[4096];sprintf_s (buffer, "%s.ptl",mName.c_str());return (const char*)buffer;}
	/*
	This specifies how to apply dynamic motion to the hair. If static then no dynamics are computed for the hair,
	which will appear totally stiff in the start position.
	Dynamic computes the hair position based on forces and collisions. Passive moves it by interpolating the
	motion of neighboring dynamic hairs, which can be an efficient way of simulating masses of hair in self collision.
	*/
	UnsignedintID getSimulationMethod(){char buffer[4096];sprintf_s (buffer, "%s.sim",mName.c_str());return (const char*)buffer;}
	/*
	This determines the initial direction a hair emits from the follicle.
	This is used when determining rest deflections, as well
	as when increasing subsegments on the hairsystem. If the restPose is straight
	and this is set to start curve, the hair will try to assume a straight line based
	on the first segment of the start curve. If surface normal is selected then
	the hair would instead move towards a line coming straight out of the surface.
	IF this is set to surface normal then subsegments in the hairsystem will refine
	such that the root of the hair is normal to the surface.
	*/
	UnsignedintID getStartDirection(){char buffer[4096];sprintf_s (buffer, "%s.sdr",mName.c_str());return (const char*)buffer;}
	/*If true then emit the hair from the opposite side of the input surface.*/
	BoolID getFlipDirection(){char buffer[4096];sprintf_s (buffer, "%s.fld",mName.c_str());return (const char*)buffer;}
	/*The global gravity value from the simulation node. (used by RestPose )*/
	DoubleID getHairSysGravity(){char buffer[4096];sprintf_s (buffer, "%s.hsg",mName.c_str());return (const char*)buffer;}
	/*The global hair stiffness value from the simulation node. (used by RestPose )*/
	DoubleID getHairSysStiffness(){char buffer[4096];sprintf_s (buffer, "%s.hss",mName.c_str());return (const char*)buffer;}
	/*If true then use the local hair settings rather then the global hairSystem ones*/
	BoolID getOverrideDynamics(){char buffer[4096];sprintf_s (buffer, "%s.ovd",mName.c_str());return (const char*)buffer;}
	/*If true then collide this hair with geometry if the global hairSystem has collisions*/
	BoolID getCollide(){char buffer[4096];sprintf_s (buffer, "%s.cld",mName.c_str());return (const char*)buffer;}
	/*This overrides the damp on the hairSystem. It can be used to stablize problem hairs.*/
	DoubleID getDamp(){char buffer[4096];sprintf_s (buffer, "%s.dmp",mName.c_str());return (const char*)buffer;}
	/*The amount the hair can flex with regard to the rest position.*/
	DoubleID getStiffness(){char buffer[4096];sprintf_s (buffer, "%s.stf",mName.c_str());return (const char*)buffer;}
	/*
	<b>Stiffness Scale</b> affects the stiffness from root to tip of the hair.
	The left of the graph is the root and the right is the tip. Typically the root of a
	hair is thicker and thus stiffer than the tip. This attribute multiplies
	the stiffness parameter value, so a value of 1.0 will leave the stiffness unchanged.
	Note that there is also a stiffnessScale attribute ramp on the hair system shape
	node which affects all hairs in the system. This per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
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
	/*The amount the simulated hair can stretch along its length.*/
	DoubleID getLengthFlex(){char buffer[4096];sprintf_s (buffer, "%s.lfl",mName.c_str());return (const char*)buffer;}
	/*
	This scales the hair clump relative to the global hair clump width
	on the hair system node. If the hair clump width on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	Note that this will also affect the overall number of hairs within a clump, such that
	the density per unit remains roughly constant.<br/>
	Note that there are also clumpWidth and clumpWidthScale attributes that are in
	effect only when the overrideDynamics attribute is toggled on. For dynamic hairs,
	these two additional attributes can be used to more finely tune the clump width,
	including varying the width along the length of the follicle. For dynamic follicles,
	the effective clump width is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
	*/
	DoubleID getClumpWidthMult(){char buffer[4096];sprintf_s (buffer, "%s.cwm",mName.c_str());return (const char*)buffer;}
	/*
	<b>Clump Width Scale</b> scales the clumpWidth attribute along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	As a dynamic hair parameter, it is only used when the overrideDynamics attribute
	is enabled. Otherwise, the clumpWidth and clumpWidthScale values on the
	hairSystemShape node are used instead. For dynamic follicles, the effective clump width
	is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
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
	especially if there are many cvs per hair. Note that there is an
	identical startCurveAttract on the hair system node. This per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
	*/
	DoubleID getStartCurveAttract(){char buffer[4096];sprintf_s (buffer, "%s.sct",mName.c_str());return (const char*)buffer;}
	/*
	This value attenuates the startCurveAttract value along the length of the follicle.
	The left of the graph is the root and the right is the tip.
	If the startCurveAttract attribute is zero then this parameter will have no effect,
	as zero times a number is always zero.
	There is also a corresponding attractionScale parameter on
	the hair system node which has the same effect only for all hairs.
	This  per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
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
	Attenuates the effect of startCurveAttract on a per-follicle basis.
	The actual attraction to the start curve is performed by altering the
	current velocity of the hair so that it will meet the
	start position. This control attenuates this value.
	When this value is one, the motion towards the start
	curve is fully attenuated, leaving simply the start position
	plus field forces.  This is useful for applying fields on top
	of previously animated hairs.  To acheive this affect,
	you should set attractionDamp = 1.0 and make the stiffness
	ramp all 1.0. There is also a corresponding attenuation parameter on
	the hair system node which has the same effect only for all hairs.
	This  per-follicle
	parameter is used in place of the hair system's version when overrideDynamics is true.
	*/
	DoubleID getAttractionDamp(){char buffer[4096];sprintf_s (buffer, "%s.ad",mName.c_str());return (const char*)buffer;}
	/*
	This scales the number of hairs relative to the global hair per clump
	on the hair system node. If the hairs per clump  on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	DoubleID getDensityMult(){char buffer[4096];sprintf_s (buffer, "%s.dml",mName.c_str());return (const char*)buffer;}
	/*
	This scales the curl rate relative to the global hair curl attribute
	on the hair system node. If the curl on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	DoubleID getCurlMult(){char buffer[4096];sprintf_s (buffer, "%s.cml",mName.c_str());return (const char*)buffer;}
	/*
	This affects the rotation of the individual hair clump about the central hair axis.
	This adds onto the global twist defined on the hair system node.
	If the twist on the hair system is zero,
	then this parameter will have no effect, as zero times anything is always zero.
	*/
	DoubleID getClumpTwistOffset(){char buffer[4096];sprintf_s (buffer, "%s.ctf",mName.c_str());return (const char*)buffer;}
	/*If true then the clump is split into 3 sub groupings that are braided.*/
	BoolID getBraid(){char buffer[4096];sprintf_s (buffer, "%s.brd",mName.c_str());return (const char*)buffer;}
	/*
	This allows one to have a different base color per hair clump.
	The attribute value determines the proportion the global color is
	is blended with the local color attribute. If the value is zero than
	the hair color is determined by the global hair color on the hair system node.
	If the value is 1.0 then the color is entirely the color attribute on this node.
	In between values blend between the two values.
	*/
	DoubleID getColorBlend(){char buffer[4096];sprintf_s (buffer, "%s.cbl",mName.c_str());return (const char*)buffer;}
	/*input color*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*color Red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.cl.cr",mName.c_str());return (const char*)buffer;}
	/*color Green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.cl.cg",mName.c_str());return (const char*)buffer;}
	/*color Blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.cl.cb",mName.c_str());return (const char*)buffer;}
	/*
	Toggles how input curves are sampled. When this attribute is on,
	segmentLength attribute is used to determine the number of CVs
	sampled on the input curve. When the value is false,
	sampleDensity is used to compute the number points sampled.
	*/
	BoolID getFixedSegmentLength(){char buffer[4096];sprintf_s (buffer, "%s.fsl",mName.c_str());return (const char*)buffer;}
	/*
	Specifies how long each segment on the hair should be. This
	is another way of sampling the input curve, used when
	fixedSegmentLength is on.  Using a fixed segment length
	can provide more realistic hair simulation when the length
	of the hair varies across the same hair system.  Setting
	a consistent segment length across all hairs will make longer
	hai rs have more CVs and shorter hairs have less CVs.
	*/
	DoubleID getSegmentLength(){char buffer[4096];sprintf_s (buffer, "%s.sgl",mName.c_str());return (const char*)buffer;}
	/*
	This controls the number of points to sample along the input
	start and rest position curves when generating the outHair to
	pass to the simulation node. A value of one will cause the simulation
	hair to have the same number of poly line segments as the curve has
	cvs. A value of 2.0 will will double the number of segments, while a value of 0.0
	will result in a single segment. This can dramatically affect the speed and quality
	of the simulation.
	*/
	DoubleID getSampleDensity(){char buffer[4096];sprintf_s (buffer, "%s.sdn",mName.c_str());return (const char*)buffer;}
	/*The degree of the final generated output curve.*/
	IntID getDegree(){char buffer[4096];sprintf_s (buffer, "%s.dgr",mName.c_str());return (const char*)buffer;}
	/*
	This is the base or maximum width for the dynamic hair groups.
	As a dynamic hair parameter, it is only used when the overrideDynamics attribute
	is enabled. Otherwise, the clumpWidth and clumpWidthScale values on the
	hairSystemShape node are used instead. For dynamic follicles, the effective clump width
	is the product of clumpWidthMult, clumpWidthScale and
	clumpWidth. For non-dynamic follicles clumpWidthMult alone provides the width.
	Unlike <b>Clump Width Mult</b>, this attribute has no effect on the number of
	hairs per clump. It thus provides a way of scaling without affecting density.
	*/
	FloatID getClumpWidth(){char buffer[4096];sprintf_s (buffer, "%s.cw",mName.c_str());return (const char*)buffer;}
	/*world position of hair base*/
	Double3ID getOutTranslate(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*X value of outTranslate*/
	DoubleID getOutTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.ot.otx",mName.c_str());return (const char*)buffer;}
	/*Y value of outTranslate*/
	DoubleID getOutTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.ot.oty",mName.c_str());return (const char*)buffer;}
	/*Z value of outTranslate*/
	DoubleID getOutTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.ot.otz",mName.c_str());return (const char*)buffer;}
	/*world rotation of hair base*/
	Double3ID getOutRotate(){char buffer[4096];sprintf_s (buffer, "%s.or",mName.c_str());return (const char*)buffer;}
	/*X value of outRotate*/
	DoubleID getOutRotateX(){char buffer[4096];sprintf_s (buffer, "%s.or.orx",mName.c_str());return (const char*)buffer;}
	/*Y value of outRotate*/
	DoubleID getOutRotateY(){char buffer[4096];sprintf_s (buffer, "%s.or.ory",mName.c_str());return (const char*)buffer;}
	/*Z value of outRotate*/
	DoubleID getOutRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.or.orz",mName.c_str());return (const char*)buffer;}
	/*twist vector at hair base*/
	Double3ID getOutTangent(){char buffer[4096];sprintf_s (buffer, "%s.otn",mName.c_str());return (const char*)buffer;}
	/*X value of outTangent*/
	DoubleID getOutTangentX(){char buffer[4096];sprintf_s (buffer, "%s.otn.otnx",mName.c_str());return (const char*)buffer;}
	/*Y value of outTangent*/
	DoubleID getOutTangentY(){char buffer[4096];sprintf_s (buffer, "%s.otn.otny",mName.c_str());return (const char*)buffer;}
	/*Z value of outTangent*/
	DoubleID getOutTangentZ(){char buffer[4096];sprintf_s (buffer, "%s.otn.otnz",mName.c_str());return (const char*)buffer;}
	/*normal at hair base with elevation and azimuth applied*/
	Double3ID getOutNormal(){char buffer[4096];sprintf_s (buffer, "%s.onm",mName.c_str());return (const char*)buffer;}
	/*X value of outNormal*/
	DoubleID getOutNormalX(){char buffer[4096];sprintf_s (buffer, "%s.onm.onx",mName.c_str());return (const char*)buffer;}
	/*Y value of outNormal*/
	DoubleID getOutNormalY(){char buffer[4096];sprintf_s (buffer, "%s.onm.ony",mName.c_str());return (const char*)buffer;}
	/*Z value of outNormal*/
	DoubleID getOutNormalZ(){char buffer[4096];sprintf_s (buffer, "%s.onm.onz",mName.c_str());return (const char*)buffer;}
	/*output hair data for use by hairSystemShape node*/
	HairCurveID getOutHair(){char buffer[4096];sprintf_s (buffer, "%s.oha",mName.c_str());return (const char*)buffer;}
	/*output hair data for use by hairSystemShape node*/
	NurbsCurveID getOutCurve(){char buffer[4096];sprintf_s (buffer, "%s.ocr",mName.c_str());return (const char*)buffer;}
	/*If false then the specified uv for input mesh is not currently defined.*/
	BoolID getValidUv(){char buffer[4096];sprintf_s (buffer, "%s.vuv",mName.c_str());return (const char*)buffer;}
	/*The Name of the mapset of the poly on which follicle is present*/
	StringID getMapSetName(){char buffer[4096];sprintf_s (buffer, "%s.msn",mName.c_str());return (const char*)buffer;}
protected:
	Follicle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FOLLICLE_H__
