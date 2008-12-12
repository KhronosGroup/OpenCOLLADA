/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DYNAMICCONSTRAINT_H__
#define __MayaDM_DYNAMICCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
This node can be used to create constraint relationships between dynamic objects.
 <p/>
*/
class DynamicConstraint : public Shape
{
public:
	/*
	<b>connectionDensityRange</b> allows one to thin out connects based on distance.
	For example one can make it such that one only has long links and no short links
	by making the graph 1.0 at the far right an zero everywhere else.
	This attribute scales the connectionDensity attribute. The right side of the graph
	represents links of the length determined by the MaxDistance attribute while the left is
	zero length lengths.
	*/
	struct ConnectionDensityRange{
		float connectionDensityRange_Position;
		float connectionDensityRange_FloatValue;
		unsigned int connectionDensityRange_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", connectionDensityRange_Position);
			fprintf_s(file,"%f ", connectionDensityRange_FloatValue);
			fprintf_s(file,"%i", connectionDensityRange_Interp);
		}
	};
	/*
	<b>StrengthDropoff</b> allows one to control the strength of the links based on distance.
	The left side of the ramp is the strength at a length of zero with the right side representing
	the max distance.
	*/
	struct StrengthDropoff{
		float strengthDropoff_Position;
		float strengthDropoff_FloatValue;
		unsigned int strengthDropoff_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", strengthDropoff_Position);
			fprintf_s(file,"%f ", strengthDropoff_FloatValue);
			fprintf_s(file,"%i", strengthDropoff_Interp);
		}
	};
public:
	DynamicConstraint(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "dynamicConstraint"){}
	virtual ~DynamicConstraint(){}
	/*Toggle dynamics on/off for this object.*/
	void setIsDynamic(bool isd){if(isd == true) return; fprintf_s(mFile, "setAttr \".isd\" %i;\n", isd);}
	/*Toggle dynamics on/off for this object.*/
	void setIsDynamic(const BoolID& isd){fprintf_s(mFile,"connectAttr \"");isd.write(mFile);fprintf_s(mFile,"\" \"%s.isd\";\n",mName.c_str());}
	/*
	Toggle dynamics on/off for this object.
	If animated then links are reformed when this toggles on, setting
	the rest length of links to the distance at the time the constraint
	was enabled. This is useful for animating a constraint grabbing objects.
	*/
	void setEnable(bool ena){if(ena == true) return; fprintf_s(mFile, "setAttr \".ena\" %i;\n", ena);}
	/*
	Toggle dynamics on/off for this object.
	If animated then links are reformed when this toggles on, setting
	the rest length of links to the distance at the time the constraint
	was enabled. This is useful for animating a constraint grabbing objects.
	*/
	void setEnable(const BoolID& ena){fprintf_s(mFile,"connectAttr \"");ena.write(mFile);fprintf_s(mFile,"\" \"%s.ena\";\n",mName.c_str());}
	/*
	This is the current time used synchronize start frame initialization with
	the nucleus node controlling the simulation
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve),if the nucleus node connected to this constraint
	has replaced its time connection
	*/
	void setCurrentTime(const TimeID& cti){fprintf_s(mFile,"connectAttr \"");cti.write(mFile);fprintf_s(mFile,"\" \"%s.cti\";\n",mName.c_str());}
	/*Ids of nucleus component objects.*/
	void setComponentIds(size_t cid_i,const NIdID& cid){fprintf_s(mFile,"connectAttr \"");cid.write(mFile);fprintf_s(mFile,"\" \"%s.cid[%i]\";\n",mName.c_str(),cid_i);}
	/*
	This determines how the constraint links behave.
	Weld locks vertices together such that they can't stretch apart.
	Spring treats each connection as a springy link.
	Rubber Band behaves similar to the spring when stretched, but does nothing when
	the link is compressed. It has no effect when the points are closer than the link rest length.
	*/
	void setConstraintMethod(unsigned int cm){if(cm == 1) return; fprintf_s(mFile, "setAttr \".cm\" %i;\n", cm);}
	/*
	This determines how the constraint links behave.
	Weld locks vertices together such that they can't stretch apart.
	Spring treats each connection as a springy link.
	Rubber Band behaves similar to the spring when stretched, but does nothing when
	the link is compressed. It has no effect when the points are closer than the link rest length.
	*/
	void setConstraintMethod(const UnsignedintID& cm){fprintf_s(mFile,"connectAttr \"");cm.write(mFile);fprintf_s(mFile,"\" \"%s.cm\";\n",mName.c_str());}
	/*
	This determines the logic used when generating constraint links.
	Component Order simply links between the different components based on the order
	the elements are listed on the nComponent node.
	Within Max Distance links together any pairs that are closer than the
	maxDistance attribute in worldspace at the start frame.
	Nearest Pair links each element with the nearest other element. While the
	max distance setting allows for multiple points to be joined together the nearest
	pair connects each point with just one other point.
	*/
	void setConnectionMethod(unsigned int cnm){if(cnm == 0) return; fprintf_s(mFile, "setAttr \".cnm\" %i;\n", cnm);}
	/*
	This determines the logic used when generating constraint links.
	Component Order simply links between the different components based on the order
	the elements are listed on the nComponent node.
	Within Max Distance links together any pairs that are closer than the
	maxDistance attribute in worldspace at the start frame.
	Nearest Pair links each element with the nearest other element. While the
	max distance setting allows for multiple points to be joined together the nearest
	pair connects each point with just one other point.
	*/
	void setConnectionMethod(const UnsignedintID& cnm){fprintf_s(mFile,"connectAttr \"");cnm.write(mFile);fprintf_s(mFile,"\" \"%s.cnm\";\n",mName.c_str());}
	/*
	This specifies the way the objects are related together.
	ObjectToConstraint relates the input components to the constraint node position.
	With ObjectToObject each object is related to each other object and the
	constraint node's position and transform is ignored.
	*/
	void setConstraintRelation(unsigned int crr){if(crr == 1) return; fprintf_s(mFile, "setAttr \".crr\" %i;\n", crr);}
	/*
	This specifies the way the objects are related together.
	ObjectToConstraint relates the input components to the constraint node position.
	With ObjectToObject each object is related to each other object and the
	constraint node's position and transform is ignored.
	*/
	void setConstraintRelation(const UnsignedintID& crr){fprintf_s(mFile,"connectAttr \"");crr.write(mFile);fprintf_s(mFile,"\" \"%s.crr\";\n",mName.c_str());}
	/*
	This specifies the way the component nodes are related together. A component is
	defined as an nComponent connected to the constraint node. Each component
	defines a subset of elements for a nucleus object, for example a group of triangles or points.
	All to First links between all components and the first listed component.
	All to All links each component to each other component
	Chain links the components in series, which each component constrained to the next one in the list.
	*/
	void setComponentRelation(unsigned int cmr){if(cmr == 0) return; fprintf_s(mFile, "setAttr \".cmr\" %i;\n", cmr);}
	/*
	This specifies the way the component nodes are related together. A component is
	defined as an nComponent connected to the constraint node. Each component
	defines a subset of elements for a nucleus object, for example a group of triangles or points.
	All to First links between all components and the first listed component.
	All to All links each component to each other component
	Chain links the components in series, which each component constrained to the next one in the list.
	*/
	void setComponentRelation(const UnsignedintID& cmr){fprintf_s(mFile,"connectAttr \"");cmr.write(mFile);fprintf_s(mFile,"\" \"%s.cmr\";\n",mName.c_str());}
	/*TODO EXPLANATION*/
	void setConnectionUpdate(unsigned int cu){if(cu == 0) return; fprintf_s(mFile, "setAttr \".cu\" %i;\n", cu);}
	/*TODO EXPLANATION*/
	void setConnectionUpdate(const UnsignedintID& cu){fprintf_s(mFile,"connectAttr \"");cu.write(mFile);fprintf_s(mFile,"\" \"%s.cu\";\n",mName.c_str());}
	/*
	If on then links can be formed within nObjects or nComponent, while when off
	links are only formed between different nComponents.
	*/
	void setConnectWithinComponent(bool cwc){if(cwc == false) return; fprintf_s(mFile, "setAttr \".cwc\" %i;\n", cwc);}
	/*
	If on then links can be formed within nObjects or nComponent, while when off
	links are only formed between different nComponents.
	*/
	void setConnectWithinComponent(const BoolID& cwc){fprintf_s(mFile,"connectAttr \"");cwc.write(mFile);fprintf_s(mFile,"\" \"%s.cwc\";\n",mName.c_str());}
	/*
	<b>connectionDensity</b> allows one to thin out connects based on distance.
	A value of 1.0 leaves links intact, while a value of 0.0 will result in no links.
	Inbetween values determine the probablities that links will be broken.
	The gradient attribute connectionDensityRange additionally allows one to
	determine the overall distribution of connections based on connection length.
	*/
	void setConnectionDensity(double cdn){if(cdn == 1.0) return; fprintf_s(mFile, "setAttr \".cdn\" %f;\n", cdn);}
	/*
	<b>connectionDensity</b> allows one to thin out connects based on distance.
	A value of 1.0 leaves links intact, while a value of 0.0 will result in no links.
	Inbetween values determine the probablities that links will be broken.
	The gradient attribute connectionDensityRange additionally allows one to
	determine the overall distribution of connections based on connection length.
	*/
	void setConnectionDensity(const DoubleID& cdn){fprintf_s(mFile,"connectAttr \"");cdn.write(mFile);fprintf_s(mFile,"\" \"%s.cdn\";\n",mName.c_str());}
	/*
	<b>connectionDensityRange</b> allows one to thin out connects based on distance.
	For example one can make it such that one only has long links and no short links
	by making the graph 1.0 at the far right an zero everywhere else.
	This attribute scales the connectionDensity attribute. The right side of the graph
	represents links of the length determined by the MaxDistance attribute while the left is
	zero length lengths.
	*/
	void setConnectionDensityRange(size_t cdnr_i,const ConnectionDensityRange& cdnr){fprintf_s(mFile, "setAttr \".cdnr[%i]\" ",cdnr_i);cdnr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>connectionDensityRange</b> allows one to thin out connects based on distance.
	For example one can make it such that one only has long links and no short links
	by making the graph 1.0 at the far right an zero everywhere else.
	This attribute scales the connectionDensity attribute. The right side of the graph
	represents links of the length determined by the MaxDistance attribute while the left is
	zero length lengths.
	*/
	void setConnectionDensityRange(size_t cdnr_i,const ConnectionDensityRangeID& cdnr){fprintf_s(mFile,"connectAttr \"");cdnr.write(mFile);fprintf_s(mFile,"\" \"%s.cdnr[%i]\";\n",mName.c_str(),cdnr_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setConnectionDensityRange_Position(size_t cdnr_i,float cdnrp){if(cdnrp == 0.0) return; fprintf_s(mFile, "setAttr \".cdnr[%i].cdnrp\" %f;\n", cdnr_i,cdnrp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setConnectionDensityRange_Position(size_t cdnr_i,const FloatID& cdnrp){fprintf_s(mFile,"connectAttr \"");cdnrp.write(mFile);fprintf_s(mFile,"\" \"%s.cdnr[%i].cdnrp\";\n",mName.c_str(),cdnr_i);}
	/*Ramp value at the sibling position*/
	void setConnectionDensityRange_FloatValue(size_t cdnr_i,float cdnrfv){if(cdnrfv == 0.0) return; fprintf_s(mFile, "setAttr \".cdnr[%i].cdnrfv\" %f;\n", cdnr_i,cdnrfv);}
	/*Ramp value at the sibling position*/
	void setConnectionDensityRange_FloatValue(size_t cdnr_i,const FloatID& cdnrfv){fprintf_s(mFile,"connectAttr \"");cdnrfv.write(mFile);fprintf_s(mFile,"\" \"%s.cdnr[%i].cdnrfv\";\n",mName.c_str(),cdnr_i);}
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
	void setConnectionDensityRange_Interp(size_t cdnr_i,unsigned int cdnri){if(cdnri == 0) return; fprintf_s(mFile, "setAttr \".cdnr[%i].cdnri\" %i;\n", cdnr_i,cdnri);}
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
	void setConnectionDensityRange_Interp(size_t cdnr_i,const UnsignedintID& cdnri){fprintf_s(mFile,"connectAttr \"");cdnri.write(mFile);fprintf_s(mFile,"\" \"%s.cdnr[%i].cdnri\";\n",mName.c_str(),cdnr_i);}
	/*Toggle the display of the constraint links in the viewport.*/
	void setDisplayConnections(bool dcn){if(dcn == true) return; fprintf_s(mFile, "setAttr \".dcn\" %i;\n", dcn);}
	/*Toggle the display of the constraint links in the viewport.*/
	void setDisplayConnections(const BoolID& dcn){fprintf_s(mFile,"connectAttr \"");dcn.write(mFile);fprintf_s(mFile,"\" \"%s.dcn\";\n",mName.c_str());}
	/*The overall amount of effect of the constraint.*/
	void setStrength(double str){if(str == 20.0) return; fprintf_s(mFile, "setAttr \".str\" %f;\n", str);}
	/*The overall amount of effect of the constraint.*/
	void setStrength(const DoubleID& str){fprintf_s(mFile,"connectAttr \"");str.write(mFile);fprintf_s(mFile,"\" \"%s.str\";\n",mName.c_str());}
	/*
	This specifies the way the rest length is determined.
	From Start Distance sets the constraint distances to the initial distance at
	the start frame. If RestLengthScale is 1.0 then there then will be no tension on
	constraint initially.
	With Constant rest length, the rest length attribute on the constraint node will be used.
	This will push or pull on connections if they are not this distance at the start.
	*/
	void setRestLengthMethod(unsigned int rlm){if(rlm == 0) return; fprintf_s(mFile, "setAttr \".rlm\" %i;\n", rlm);}
	/*
	This specifies the way the rest length is determined.
	From Start Distance sets the constraint distances to the initial distance at
	the start frame. If RestLengthScale is 1.0 then there then will be no tension on
	constraint initially.
	With Constant rest length, the rest length attribute on the constraint node will be used.
	This will push or pull on connections if they are not this distance at the start.
	*/
	void setRestLengthMethod(const UnsignedintID& rlm){fprintf_s(mFile,"connectAttr \"");rlm.write(mFile);fprintf_s(mFile,"\" \"%s.rlm\";\n",mName.c_str());}
	/*
	This is the rest length in world space of constraint links used when the Rest Length Method is set
	to From Start Distance.
	*/
	void setRestLength(double rl){if(rl == 0.0) return; fprintf_s(mFile, "setAttr \".rl\" %f;\n", rl);}
	/*
	This is the rest length in world space of constraint links used when the Rest Length Method is set
	to From Start Distance.
	*/
	void setRestLength(const DoubleID& rl){fprintf_s(mFile,"connectAttr \"");rl.write(mFile);fprintf_s(mFile,"\" \"%s.rl\";\n",mName.c_str());}
	/*Dynamically scale the rest length that was determined at the start frame.*/
	void setRestLengthScale(double rls){if(rls == 1.0) return; fprintf_s(mFile, "setAttr \".rls\" %f;\n", rls);}
	/*Dynamically scale the rest length that was determined at the start frame.*/
	void setRestLengthScale(const DoubleID& rls){fprintf_s(mFile,"connectAttr \"");rls.write(mFile);fprintf_s(mFile,"\" \"%s.rls\";\n",mName.c_str());}
	/*The resistance to motion in the local tangent directions*/
	void setTangentStrength(double tst){if(tst == 10) return; fprintf_s(mFile, "setAttr \".tst\" %f;\n", tst);}
	/*The resistance to motion in the local tangent directions*/
	void setTangentStrength(const DoubleID& tst){fprintf_s(mFile,"connectAttr \"");tst.write(mFile);fprintf_s(mFile,"\" \"%s.tst\";\n",mName.c_str());}
	/*
	For edge-edge constraints  this controls whether we
	constraint the bend permitted across those edges.
	*/
	void setBend(bool bnd){if(bnd == false) return; fprintf_s(mFile, "setAttr \".bnd\" %i;\n", bnd);}
	/*
	For edge-edge constraints  this controls whether we
	constraint the bend permitted across those edges.
	*/
	void setBend(const BoolID& bnd){fprintf_s(mFile,"connectAttr \"");bnd.write(mFile);fprintf_s(mFile,"\" \"%s.bnd\";\n",mName.c_str());}
	/*The strength of the edge constraint connection to resist bending.*/
	void setBendStrength(double bns){if(bns == 20.0) return; fprintf_s(mFile, "setAttr \".bns\" %f;\n", bns);}
	/*The strength of the edge constraint connection to resist bending.*/
	void setBendStrength(const DoubleID& bns){fprintf_s(mFile,"connectAttr \"");bns.write(mFile);fprintf_s(mFile,"\" \"%s.bns\";\n",mName.c_str());}
	/*The strength of the edge constraint connection to resist bending.*/
	void setBendBreakAngle(double bba){if(bba == 360.0) return; fprintf_s(mFile, "setAttr \".bba\" %f;\n", bba);}
	/*The strength of the edge constraint connection to resist bending.*/
	void setBendBreakAngle(const DoubleID& bba){fprintf_s(mFile,"connectAttr \"");bba.write(mFile);fprintf_s(mFile,"\" \"%s.bba\";\n",mName.c_str());}
	/*
	The strength of the constraint connection to resist breaking. A value
	of 1.0 represents a strength that will never break. A value of zero will
	break immediately(as if there is no constraint). This strength is relative to the overall scene, or object scale.
	You can adjust the Glue Strength Scale to adjust the sensitivity for overall scene scale.
	Bonds are formed at the start frame. During simulation once broken the links never reform except
	when the glue strength is animated back up to a value of 1.
	*/
	void setGlueStrength(double gls){if(gls == 1.0) return; fprintf_s(mFile, "setAttr \".gls\" %f;\n", gls);}
	/*
	The strength of the constraint connection to resist breaking. A value
	of 1.0 represents a strength that will never break. A value of zero will
	break immediately(as if there is no constraint). This strength is relative to the overall scene, or object scale.
	You can adjust the Glue Strength Scale to adjust the sensitivity for overall scene scale.
	Bonds are formed at the start frame. During simulation once broken the links never reform except
	when the glue strength is animated back up to a value of 1.
	*/
	void setGlueStrength(const DoubleID& gls){fprintf_s(mFile,"connectAttr \"");gls.write(mFile);fprintf_s(mFile,"\" \"%s.gls\";\n",mName.c_str());}
	/*
	You can adjust the Glue Strength Scale to adjust the sensitivity  of the Glue Strength attribute
	for the overall scene scale. Glue strength uses a the worldspace distance of separation between links
	to determine the point at which a break occurs. This scales the required separation distance.
	*/
	void setGlueStrengthScale(double glss){if(glss == 1.0) return; fprintf_s(mFile, "setAttr \".glss\" %f;\n", glss);}
	/*
	You can adjust the Glue Strength Scale to adjust the sensitivity  of the Glue Strength attribute
	for the overall scene scale. Glue strength uses a the worldspace distance of separation between links
	to determine the point at which a break occurs. This scales the required separation distance.
	*/
	void setGlueStrengthScale(const DoubleID& glss){fprintf_s(mFile,"connectAttr \"");glss.write(mFile);fprintf_s(mFile,"\" \"%s.glss\";\n",mName.c_str());}
	/*
	This is an added force between the constrained points. For constraints between components the force drops off
	with distance according to the dropoffDistance attribute where the strengthDropoff gradient is mapped to this distance.
	For transform constraints the force is between the points and the center of the transform, and the
	strengthDropoff is defined relative to the boundary of the transform. Outside the bounds of the transform the
	rightmost value of the strengthDropoff gradient is used.  Unlike normal maya fields this can be applied to
	specific components instead of only to the entire object.
	*/
	void setForce(double for_){if(for_ == 0.0) return; fprintf_s(mFile, "setAttr \".for\" %f;\n", for_);}
	/*
	This is an added force between the constrained points. For constraints between components the force drops off
	with distance according to the dropoffDistance attribute where the strengthDropoff gradient is mapped to this distance.
	For transform constraints the force is between the points and the center of the transform, and the
	strengthDropoff is defined relative to the boundary of the transform. Outside the bounds of the transform the
	rightmost value of the strengthDropoff gradient is used.  Unlike normal maya fields this can be applied to
	specific components instead of only to the entire object.
	*/
	void setForce(const DoubleID& for_){fprintf_s(mFile,"connectAttr \"");for_.write(mFile);fprintf_s(mFile,"\" \"%s.for\";\n",mName.c_str());}
	/*
	A force is applied to each object being constrainted that pulls it more
	towards the motion of the other object. At a drag of one the objects
	will be fully locked and move together.
	*/
	void setMotionDrag(double mdg){if(mdg == 0.0) return; fprintf_s(mFile, "setAttr \".mdg\" %f;\n", mdg);}
	/*
	A force is applied to each object being constrainted that pulls it more
	towards the motion of the other object. At a drag of one the objects
	will be fully locked and move together.
	*/
	void setMotionDrag(const DoubleID& mdg){fprintf_s(mFile,"connectAttr \"");mdg.write(mFile);fprintf_s(mFile,"\" \"%s.mdg\";\n",mName.c_str());}
	/*
	This controls a dropoff of effect with distance.
	It is a scalar applied to the dropoff
	distance (e.g., a value of 0.5 is equivalent to reducing the dropoff
	by 50%)
	*/
	void setDropoff(double drp){if(drp == 1.0) return; fprintf_s(mFile, "setAttr \".drp\" %f;\n", drp);}
	/*
	This controls a dropoff of effect with distance.
	It is a scalar applied to the dropoff
	distance (e.g., a value of 0.5 is equivalent to reducing the dropoff
	by 50%)
	*/
	void setDropoff(const DoubleID& drp){fprintf_s(mFile,"connectAttr \"");drp.write(mFile);fprintf_s(mFile,"\" \"%s.drp\";\n",mName.c_str());}
	/*
	This is the dropoff distance. Anything beyond this distance won't
	be affected by the constraint. The dropoffDistance can take on any
	value between 0 and infinity.
	*/
	void setDropoffDistance(double ddd){if(ddd == 50.0) return; fprintf_s(mFile, "setAttr \".ddd\" %f;\n", ddd);}
	/*
	This is the dropoff distance. Anything beyond this distance won't
	be affected by the constraint. The dropoffDistance can take on any
	value between 0 and infinity.
	*/
	void setDropoffDistance(const DoubleID& ddd){fprintf_s(mFile,"connectAttr \"");ddd.write(mFile);fprintf_s(mFile,"\" \"%s.ddd\";\n",mName.c_str());}
	/*
	<b>StrengthDropoff</b> allows one to control the strength of the links based on distance.
	The left side of the ramp is the strength at a length of zero with the right side representing
	the max distance.
	*/
	void setStrengthDropoff(size_t sdp_i,const StrengthDropoff& sdp){fprintf_s(mFile, "setAttr \".sdp[%i]\" ",sdp_i);sdp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>StrengthDropoff</b> allows one to control the strength of the links based on distance.
	The left side of the ramp is the strength at a length of zero with the right side representing
	the max distance.
	*/
	void setStrengthDropoff(size_t sdp_i,const StrengthDropoffID& sdp){fprintf_s(mFile,"connectAttr \"");sdp.write(mFile);fprintf_s(mFile,"\" \"%s.sdp[%i]\";\n",mName.c_str(),sdp_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setStrengthDropoff_Position(size_t sdp_i,float sdpp){if(sdpp == 0.0) return; fprintf_s(mFile, "setAttr \".sdp[%i].sdpp\" %f;\n", sdp_i,sdpp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setStrengthDropoff_Position(size_t sdp_i,const FloatID& sdpp){fprintf_s(mFile,"connectAttr \"");sdpp.write(mFile);fprintf_s(mFile,"\" \"%s.sdp[%i].sdpp\";\n",mName.c_str(),sdp_i);}
	/*Ramp value at the sibling position*/
	void setStrengthDropoff_FloatValue(size_t sdp_i,float sdpfv){if(sdpfv == 0.0) return; fprintf_s(mFile, "setAttr \".sdp[%i].sdpfv\" %f;\n", sdp_i,sdpfv);}
	/*Ramp value at the sibling position*/
	void setStrengthDropoff_FloatValue(size_t sdp_i,const FloatID& sdpfv){fprintf_s(mFile,"connectAttr \"");sdpfv.write(mFile);fprintf_s(mFile,"\" \"%s.sdp[%i].sdpfv\";\n",mName.c_str(),sdp_i);}
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
	void setStrengthDropoff_Interp(size_t sdp_i,unsigned int sdpi){if(sdpi == 0) return; fprintf_s(mFile, "setAttr \".sdp[%i].sdpi\" %i;\n", sdp_i,sdpi);}
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
	void setStrengthDropoff_Interp(size_t sdp_i,const UnsignedintID& sdpi){fprintf_s(mFile,"connectAttr \"");sdpi.write(mFile);fprintf_s(mFile,"\" \"%s.sdp[%i].sdpi\";\n",mName.c_str(),sdp_i);}
	/*
	When the connection method is set to Max Distance then this determines the
	distance within which component elements are linked.
	*/
	void setMaxDistance(double mds){if(mds == 0.1) return; fprintf_s(mFile, "setAttr \".mds\" %f;\n", mds);}
	/*
	When the connection method is set to Max Distance then this determines the
	distance within which component elements are linked.
	*/
	void setMaxDistance(const DoubleID& mds){fprintf_s(mFile,"connectAttr \"");mds.write(mFile);fprintf_s(mFile,"\" \"%s.mds\";\n",mName.c_str());}
	/*This is the amount that energy from the constraint is removed from the system.*/
	void setDamp(double dmp){if(dmp == 0.0) return; fprintf_s(mFile, "setAttr \".dmp\" %f;\n", dmp);}
	/*This is the amount that energy from the constraint is removed from the system.*/
	void setDamp(const DoubleID& dmp){fprintf_s(mFile,"connectAttr \"");dmp.write(mFile);fprintf_s(mFile,"\" \"%s.dmp\";\n",mName.c_str());}
	/*
	This determines how freely sliding surface constraints can move.
	At a friction setting of 1 they are locked and at zero they are fully
	free to slide.
	*/
	void setFriction(double frc){if(frc == 0.0) return; fprintf_s(mFile, "setAttr \".frc\" %f;\n", frc);}
	/*
	This determines how freely sliding surface constraints can move.
	At a friction setting of 1 they are locked and at zero they are fully
	free to slide.
	*/
	void setFriction(const DoubleID& frc){fprintf_s(mFile,"connectAttr \"");frc.write(mFile);fprintf_s(mFile,"\" \"%s.frc\";\n",mName.c_str());}
	/*
	This computes collisions just along the constrainted link.
	For surface constraints this collides the point being
	constrainted to the surface at the nearest point on surface.
	This collision is very fast to compute compared with
	normal surface collisions, although it is possible for corners to poke
	through. An advantage over normal collisions is that constraint links remember
	the relative surface side at the start of the simulation, so it can't get stuck
	on the wrong side. The collide width scale allows one
	to adjust this width relative to the defined surface collision widths.
	*/
	void setLocalCollide(bool lcl){if(lcl == false) return; fprintf_s(mFile, "setAttr \".lcl\" %i;\n", lcl);}
	/*
	This computes collisions just along the constrainted link.
	For surface constraints this collides the point being
	constrainted to the surface at the nearest point on surface.
	This collision is very fast to compute compared with
	normal surface collisions, although it is possible for corners to poke
	through. An advantage over normal collisions is that constraint links remember
	the relative surface side at the start of the simulation, so it can't get stuck
	on the wrong side. The collide width scale allows one
	to adjust this width relative to the defined surface collision widths.
	*/
	void setLocalCollide(const BoolID& lcl){fprintf_s(mFile,"connectAttr \"");lcl.write(mFile);fprintf_s(mFile,"\" \"%s.lcl\";\n",mName.c_str());}
	/*
	This value multiplies the collide width defined on the dynamic node to
	determine the width used for local collision by the constraint. One may
	wish to use values greater than one, because the pointwise collisions
	used by local collide can allow penetration around corners and edges. Thus
	larger widths than for normal collisions may be required to avoid seeing
	interpenetration.
	*/
	void setCollideWidthScale(double cws){if(cws == 1.0) return; fprintf_s(mFile, "setAttr \".cws\" %f;\n", cws);}
	/*
	This value multiplies the collide width defined on the dynamic node to
	determine the width used for local collision by the constraint. One may
	wish to use values greater than one, because the pointwise collisions
	used by local collide can allow penetration around corners and edges. Thus
	larger widths than for normal collisions may be required to avoid seeing
	interpenetration.
	*/
	void setCollideWidthScale(const DoubleID& cws){fprintf_s(mFile,"connectAttr \"");cws.write(mFile);fprintf_s(mFile,"\" \"%s.cws\";\n",mName.c_str());}
	/*
	For any points, edges and faces that are interacting with each other
	as a result of this constraint, do not perform any normal collision computations
	that would have occurred otherwise
	*/
	void setExcludeCollisions(bool excs){if(excs == false) return; fprintf_s(mFile, "setAttr \".excs\" %i;\n", excs);}
	/*
	For any points, edges and faces that are interacting with each other
	as a result of this constraint, do not perform any normal collision computations
	that would have occurred otherwise
	*/
	void setExcludeCollisions(const BoolID& excs){fprintf_s(mFile,"connectAttr \"");excs.write(mFile);fprintf_s(mFile,"\" \"%s.excs\";\n",mName.c_str());}
	/*
	For surface constraints that can move this restricts the
	constraint to always be on just one side of the surface.
	The side of the surface each constrained point is on is
	determined at the start frame and then maintained.
	This avoids the problem where a constraint can flip to push
	in the opposite direction when the constraining surface moves.
	If one constrained cloth to an open cylinder this could be used to
	keep the cloth from sliding to the inside of the cylinder as well
	as keep it on the outside of the cylinder.
	*/
	void setSingleSided(bool ssd){if(ssd == true) return; fprintf_s(mFile, "setAttr \".ssd\" %i;\n", ssd);}
	/*
	For surface constraints that can move this restricts the
	constraint to always be on just one side of the surface.
	The side of the surface each constrained point is on is
	determined at the start frame and then maintained.
	This avoids the problem where a constraint can flip to push
	in the opposite direction when the constraining surface moves.
	If one constrained cloth to an open cylinder this could be used to
	keep the cloth from sliding to the inside of the cylinder as well
	as keep it on the outside of the cylinder.
	*/
	void setSingleSided(const BoolID& ssd){fprintf_s(mFile,"connectAttr \"");ssd.write(mFile);fprintf_s(mFile,"\" \"%s.ssd\";\n",mName.c_str());}
	/*The maximum solver iterations used to evaluate the constraint.*/
	void setMaxIterations(int mitr){if(mitr == 500) return; fprintf_s(mFile, "setAttr \".mitr\" %i;\n", mitr);}
	/*The maximum solver iterations used to evaluate the constraint.*/
	void setMaxIterations(const IntID& mitr){fprintf_s(mFile,"connectAttr \"");mitr.write(mFile);fprintf_s(mFile,"\" \"%s.mitr\";\n",mName.c_str());}
	/*
	The miximum solver iterations used to evaluate the constraint.
	Use a non-zero value if you want to force constraint iterations
	to sync up with collision iterations, or to use local collisions with
	a constraint strength of 0.
	*/
	void setMinIterations(int mini){if(mini == 0) return; fprintf_s(mFile, "setAttr \".mini\" %i;\n", mini);}
	/*
	The miximum solver iterations used to evaluate the constraint.
	Use a non-zero value if you want to force constraint iterations
	to sync up with collision iterations, or to use local collisions with
	a constraint strength of 0.
	*/
	void setMinIterations(const IntID& mini){fprintf_s(mFile,"connectAttr \"");mini.write(mFile);fprintf_s(mFile,"\" \"%s.mini\";\n",mName.c_str());}
	/*
	Returns the ID of the internal nucleus constraint and also updates
	the constraint settings for the start frame.
	*/
	void setEvalStart(size_t evs_i,const NIdID& evs){fprintf_s(mFile,"connectAttr \"");evs.write(mFile);fprintf_s(mFile,"\" \"%s.evs[%i]\";\n",mName.c_str(),evs_i);}
	/*
	Returns the ID of the internal nucleus constraint and also updates
	the constraint settings for the start frame.
	*/
	void setEvalCurrent(size_t evc_i,const NIdID& evc){fprintf_s(mFile,"connectAttr \"");evc.write(mFile);fprintf_s(mFile,"\" \"%s.evc[%i]\";\n",mName.c_str(),evc_i);}
	/*obsolete*/
	void setIterations(const IntID& itr){fprintf_s(mFile,"connectAttr \"");itr.write(mFile);fprintf_s(mFile,"\" \"%s.itr\";\n",mName.c_str());}
	/*obsolete*/
	void setCollide(const BoolID& cld){fprintf_s(mFile,"connectAttr \"");cld.write(mFile);fprintf_s(mFile,"\" \"%s.cld\";\n",mName.c_str());}
	/*Toggle dynamics on/off for this object.*/
	BoolID getIsDynamic(){char buffer[4096];sprintf_s (buffer, "%s.isd",mName.c_str());return (const char*)buffer;}
	/*
	Toggle dynamics on/off for this object.
	If animated then links are reformed when this toggles on, setting
	the rest length of links to the distance at the time the constraint
	was enabled. This is useful for animating a constraint grabbing objects.
	*/
	BoolID getEnable(){char buffer[4096];sprintf_s (buffer, "%s.ena",mName.c_str());return (const char*)buffer;}
	/*
	This is the current time used synchronize start frame initialization with
	the nucleus node controlling the simulation
	By default, it is given an incoming connection from the main time node.
	This can be replaced with some other connection (e.g. from an expression
	or param curve),if the nucleus node connected to this constraint
	has replaced its time connection
	*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.cti",mName.c_str());return (const char*)buffer;}
	/*Ids of nucleus component objects.*/
	const NIdID& getComponentIds(size_t cid_i){char buffer[4096];sprintf_s (buffer, "%s.cid[%i]",mName.c_str(),cid_i);return (const char*)buffer;}
	/*
	This determines how the constraint links behave.
	Weld locks vertices together such that they can't stretch apart.
	Spring treats each connection as a springy link.
	Rubber Band behaves similar to the spring when stretched, but does nothing when
	the link is compressed. It has no effect when the points are closer than the link rest length.
	*/
	UnsignedintID getConstraintMethod(){char buffer[4096];sprintf_s (buffer, "%s.cm",mName.c_str());return (const char*)buffer;}
	/*
	This determines the logic used when generating constraint links.
	Component Order simply links between the different components based on the order
	the elements are listed on the nComponent node.
	Within Max Distance links together any pairs that are closer than the
	maxDistance attribute in worldspace at the start frame.
	Nearest Pair links each element with the nearest other element. While the
	max distance setting allows for multiple points to be joined together the nearest
	pair connects each point with just one other point.
	*/
	UnsignedintID getConnectionMethod(){char buffer[4096];sprintf_s (buffer, "%s.cnm",mName.c_str());return (const char*)buffer;}
	/*
	This specifies the way the objects are related together.
	ObjectToConstraint relates the input components to the constraint node position.
	With ObjectToObject each object is related to each other object and the
	constraint node's position and transform is ignored.
	*/
	UnsignedintID getConstraintRelation(){char buffer[4096];sprintf_s (buffer, "%s.crr",mName.c_str());return (const char*)buffer;}
	/*
	This specifies the way the component nodes are related together. A component is
	defined as an nComponent connected to the constraint node. Each component
	defines a subset of elements for a nucleus object, for example a group of triangles or points.
	All to First links between all components and the first listed component.
	All to All links each component to each other component
	Chain links the components in series, which each component constrained to the next one in the list.
	*/
	UnsignedintID getComponentRelation(){char buffer[4096];sprintf_s (buffer, "%s.cmr",mName.c_str());return (const char*)buffer;}
	/*TODO EXPLANATION*/
	UnsignedintID getConnectionUpdate(){char buffer[4096];sprintf_s (buffer, "%s.cu",mName.c_str());return (const char*)buffer;}
	/*
	If on then links can be formed within nObjects or nComponent, while when off
	links are only formed between different nComponents.
	*/
	BoolID getConnectWithinComponent(){char buffer[4096];sprintf_s (buffer, "%s.cwc",mName.c_str());return (const char*)buffer;}
	/*
	<b>connectionDensity</b> allows one to thin out connects based on distance.
	A value of 1.0 leaves links intact, while a value of 0.0 will result in no links.
	Inbetween values determine the probablities that links will be broken.
	The gradient attribute connectionDensityRange additionally allows one to
	determine the overall distribution of connections based on connection length.
	*/
	DoubleID getConnectionDensity(){char buffer[4096];sprintf_s (buffer, "%s.cdn",mName.c_str());return (const char*)buffer;}
	/*
	<b>connectionDensityRange</b> allows one to thin out connects based on distance.
	For example one can make it such that one only has long links and no short links
	by making the graph 1.0 at the far right an zero everywhere else.
	This attribute scales the connectionDensity attribute. The right side of the graph
	represents links of the length determined by the MaxDistance attribute while the left is
	zero length lengths.
	*/
	const ConnectionDensityRangeID& getConnectionDensityRange(size_t cdnr_i){char buffer[4096];sprintf_s (buffer, "%s.cdnr[%i]",mName.c_str(),cdnr_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getConnectionDensityRange_Position(size_t cdnr_i){char buffer[4096];sprintf_s (buffer, "%s.cdnr[%i].cdnrp",mName.c_str(),cdnr_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getConnectionDensityRange_FloatValue(size_t cdnr_i){char buffer[4096];sprintf_s (buffer, "%s.cdnr[%i].cdnrfv",mName.c_str(),cdnr_i);return (const char*)buffer;}
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
	const UnsignedintID& getConnectionDensityRange_Interp(size_t cdnr_i){char buffer[4096];sprintf_s (buffer, "%s.cdnr[%i].cdnri",mName.c_str(),cdnr_i);return (const char*)buffer;}
	/*Toggle the display of the constraint links in the viewport.*/
	BoolID getDisplayConnections(){char buffer[4096];sprintf_s (buffer, "%s.dcn",mName.c_str());return (const char*)buffer;}
	/*The overall amount of effect of the constraint.*/
	DoubleID getStrength(){char buffer[4096];sprintf_s (buffer, "%s.str",mName.c_str());return (const char*)buffer;}
	/*
	This specifies the way the rest length is determined.
	From Start Distance sets the constraint distances to the initial distance at
	the start frame. If RestLengthScale is 1.0 then there then will be no tension on
	constraint initially.
	With Constant rest length, the rest length attribute on the constraint node will be used.
	This will push or pull on connections if they are not this distance at the start.
	*/
	UnsignedintID getRestLengthMethod(){char buffer[4096];sprintf_s (buffer, "%s.rlm",mName.c_str());return (const char*)buffer;}
	/*
	This is the rest length in world space of constraint links used when the Rest Length Method is set
	to From Start Distance.
	*/
	DoubleID getRestLength(){char buffer[4096];sprintf_s (buffer, "%s.rl",mName.c_str());return (const char*)buffer;}
	/*Dynamically scale the rest length that was determined at the start frame.*/
	DoubleID getRestLengthScale(){char buffer[4096];sprintf_s (buffer, "%s.rls",mName.c_str());return (const char*)buffer;}
	/*The resistance to motion in the local tangent directions*/
	DoubleID getTangentStrength(){char buffer[4096];sprintf_s (buffer, "%s.tst",mName.c_str());return (const char*)buffer;}
	/*
	For edge-edge constraints  this controls whether we
	constraint the bend permitted across those edges.
	*/
	BoolID getBend(){char buffer[4096];sprintf_s (buffer, "%s.bnd",mName.c_str());return (const char*)buffer;}
	/*The strength of the edge constraint connection to resist bending.*/
	DoubleID getBendStrength(){char buffer[4096];sprintf_s (buffer, "%s.bns",mName.c_str());return (const char*)buffer;}
	/*The strength of the edge constraint connection to resist bending.*/
	DoubleID getBendBreakAngle(){char buffer[4096];sprintf_s (buffer, "%s.bba",mName.c_str());return (const char*)buffer;}
	/*
	The strength of the constraint connection to resist breaking. A value
	of 1.0 represents a strength that will never break. A value of zero will
	break immediately(as if there is no constraint). This strength is relative to the overall scene, or object scale.
	You can adjust the Glue Strength Scale to adjust the sensitivity for overall scene scale.
	Bonds are formed at the start frame. During simulation once broken the links never reform except
	when the glue strength is animated back up to a value of 1.
	*/
	DoubleID getGlueStrength(){char buffer[4096];sprintf_s (buffer, "%s.gls",mName.c_str());return (const char*)buffer;}
	/*
	You can adjust the Glue Strength Scale to adjust the sensitivity  of the Glue Strength attribute
	for the overall scene scale. Glue strength uses a the worldspace distance of separation between links
	to determine the point at which a break occurs. This scales the required separation distance.
	*/
	DoubleID getGlueStrengthScale(){char buffer[4096];sprintf_s (buffer, "%s.glss",mName.c_str());return (const char*)buffer;}
	/*
	This is an added force between the constrained points. For constraints between components the force drops off
	with distance according to the dropoffDistance attribute where the strengthDropoff gradient is mapped to this distance.
	For transform constraints the force is between the points and the center of the transform, and the
	strengthDropoff is defined relative to the boundary of the transform. Outside the bounds of the transform the
	rightmost value of the strengthDropoff gradient is used.  Unlike normal maya fields this can be applied to
	specific components instead of only to the entire object.
	*/
	DoubleID getForce(){char buffer[4096];sprintf_s (buffer, "%s.for",mName.c_str());return (const char*)buffer;}
	/*
	A force is applied to each object being constrainted that pulls it more
	towards the motion of the other object. At a drag of one the objects
	will be fully locked and move together.
	*/
	DoubleID getMotionDrag(){char buffer[4096];sprintf_s (buffer, "%s.mdg",mName.c_str());return (const char*)buffer;}
	/*
	This controls a dropoff of effect with distance.
	It is a scalar applied to the dropoff
	distance (e.g., a value of 0.5 is equivalent to reducing the dropoff
	by 50%)
	*/
	DoubleID getDropoff(){char buffer[4096];sprintf_s (buffer, "%s.drp",mName.c_str());return (const char*)buffer;}
	/*
	This is the dropoff distance. Anything beyond this distance won't
	be affected by the constraint. The dropoffDistance can take on any
	value between 0 and infinity.
	*/
	DoubleID getDropoffDistance(){char buffer[4096];sprintf_s (buffer, "%s.ddd",mName.c_str());return (const char*)buffer;}
	/*
	<b>StrengthDropoff</b> allows one to control the strength of the links based on distance.
	The left side of the ramp is the strength at a length of zero with the right side representing
	the max distance.
	*/
	const StrengthDropoffID& getStrengthDropoff(size_t sdp_i){char buffer[4096];sprintf_s (buffer, "%s.sdp[%i]",mName.c_str(),sdp_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getStrengthDropoff_Position(size_t sdp_i){char buffer[4096];sprintf_s (buffer, "%s.sdp[%i].sdpp",mName.c_str(),sdp_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getStrengthDropoff_FloatValue(size_t sdp_i){char buffer[4096];sprintf_s (buffer, "%s.sdp[%i].sdpfv",mName.c_str(),sdp_i);return (const char*)buffer;}
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
	const UnsignedintID& getStrengthDropoff_Interp(size_t sdp_i){char buffer[4096];sprintf_s (buffer, "%s.sdp[%i].sdpi",mName.c_str(),sdp_i);return (const char*)buffer;}
	/*
	When the connection method is set to Max Distance then this determines the
	distance within which component elements are linked.
	*/
	DoubleID getMaxDistance(){char buffer[4096];sprintf_s (buffer, "%s.mds",mName.c_str());return (const char*)buffer;}
	/*This is the amount that energy from the constraint is removed from the system.*/
	DoubleID getDamp(){char buffer[4096];sprintf_s (buffer, "%s.dmp",mName.c_str());return (const char*)buffer;}
	/*
	This determines how freely sliding surface constraints can move.
	At a friction setting of 1 they are locked and at zero they are fully
	free to slide.
	*/
	DoubleID getFriction(){char buffer[4096];sprintf_s (buffer, "%s.frc",mName.c_str());return (const char*)buffer;}
	/*
	This computes collisions just along the constrainted link.
	For surface constraints this collides the point being
	constrainted to the surface at the nearest point on surface.
	This collision is very fast to compute compared with
	normal surface collisions, although it is possible for corners to poke
	through. An advantage over normal collisions is that constraint links remember
	the relative surface side at the start of the simulation, so it can't get stuck
	on the wrong side. The collide width scale allows one
	to adjust this width relative to the defined surface collision widths.
	*/
	BoolID getLocalCollide(){char buffer[4096];sprintf_s (buffer, "%s.lcl",mName.c_str());return (const char*)buffer;}
	/*
	This value multiplies the collide width defined on the dynamic node to
	determine the width used for local collision by the constraint. One may
	wish to use values greater than one, because the pointwise collisions
	used by local collide can allow penetration around corners and edges. Thus
	larger widths than for normal collisions may be required to avoid seeing
	interpenetration.
	*/
	DoubleID getCollideWidthScale(){char buffer[4096];sprintf_s (buffer, "%s.cws",mName.c_str());return (const char*)buffer;}
	/*
	For any points, edges and faces that are interacting with each other
	as a result of this constraint, do not perform any normal collision computations
	that would have occurred otherwise
	*/
	BoolID getExcludeCollisions(){char buffer[4096];sprintf_s (buffer, "%s.excs",mName.c_str());return (const char*)buffer;}
	/*
	For surface constraints that can move this restricts the
	constraint to always be on just one side of the surface.
	The side of the surface each constrained point is on is
	determined at the start frame and then maintained.
	This avoids the problem where a constraint can flip to push
	in the opposite direction when the constraining surface moves.
	If one constrained cloth to an open cylinder this could be used to
	keep the cloth from sliding to the inside of the cylinder as well
	as keep it on the outside of the cylinder.
	*/
	BoolID getSingleSided(){char buffer[4096];sprintf_s (buffer, "%s.ssd",mName.c_str());return (const char*)buffer;}
	/*The maximum solver iterations used to evaluate the constraint.*/
	IntID getMaxIterations(){char buffer[4096];sprintf_s (buffer, "%s.mitr",mName.c_str());return (const char*)buffer;}
	/*
	The miximum solver iterations used to evaluate the constraint.
	Use a non-zero value if you want to force constraint iterations
	to sync up with collision iterations, or to use local collisions with
	a constraint strength of 0.
	*/
	IntID getMinIterations(){char buffer[4096];sprintf_s (buffer, "%s.mini",mName.c_str());return (const char*)buffer;}
	/*
	Returns the ID of the internal nucleus constraint and also updates
	the constraint settings for the start frame.
	*/
	const NIdID& getEvalStart(size_t evs_i){char buffer[4096];sprintf_s (buffer, "%s.evs[%i]",mName.c_str(),evs_i);return (const char*)buffer;}
	/*
	Returns the ID of the internal nucleus constraint and also updates
	the constraint settings for the start frame.
	*/
	const NIdID& getEvalCurrent(size_t evc_i){char buffer[4096];sprintf_s (buffer, "%s.evc[%i]",mName.c_str(),evc_i);return (const char*)buffer;}
	/*obsolete*/
	IntID getIterations(){char buffer[4096];sprintf_s (buffer, "%s.itr",mName.c_str());return (const char*)buffer;}
	/*obsolete*/
	BoolID getCollide(){char buffer[4096];sprintf_s (buffer, "%s.cld",mName.c_str());return (const char*)buffer;}
protected:
	DynamicConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DYNAMICCONSTRAINT_H__
