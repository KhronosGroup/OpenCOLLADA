/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RIGIDBODY_H__
#define __MayaDM_RIGIDBODY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
<p><pre>
 The rigid node contains the attributes for the rigid body.  This
 node controls the active rigid body behavior of a polygonal or nurbs shape.
 If the object is a nurbs shape the shape is tessellated for collisions.
 The tessellated shape is then passed to the rigid solver.  This node
 also includes a cache which the user can turn on on a per rigid body basis.
 This node moniters the mesh/nurbs shape to determine if the shape's
 surface changes via a scale or some form of deformation.  If the
 shape is changed the surface is re-tessellated and passed to the
 rigid solver.

</pre></p>
*/
class RigidBody : public Shape
{
public:
	/*force data for the field forces.*/
	struct FieldData{
		void write(FILE* file) const
		{
		}
	};
	/*generalized for on the rigid body (forces and torques).*/
	struct GeneralForce{
		void write(FILE* file) const
		{
		}
	};
public:
	RigidBody(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "rigidBody"){}
	virtual ~RigidBody(){}
	/*This holds the value for time.*/
	void setCurrentTime(const TimeID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*
	Local transformation matrix. Contains the same information as
	the matrix attribute on dagNode but it is stored in a format
	that can be interpolated easily.
	*/
	void setRigidWorldMatrix(const MatrixID& rmx){fprintf_s(mFile,"connectAttr \"");rmx.write(mFile);fprintf_s(mFile,"\" \"%s.rmx\";\n",mName.c_str());}
	/*
	Obsolete attribute from version 1.
	Included only for file compatibility.  Not otherwise used.
	To be removed in post version 3 release.
	*/
	void setFieldConnections(size_t fc_i,const MessageID& fc){fprintf_s(mFile,"connectAttr \"");fc.write(mFile);fprintf_s(mFile,"\" \"%s.fc[%i]\";\n",mName.c_str(),fc_i);}
	/*run up and instantaneous data cache.*/
	void setRunUpCache(const doubleArray& rc){if(rc.size == 0) return; fprintf_s(mFile, "setAttr \".rc\" -type \"doubleArray\" ");rc.write(mFile);fprintf_s(mFile,";\n");}
	/*run up and instantaneous data cache.*/
	void setRunUpCache(const DoubleArrayID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc\";\n",mName.c_str());}
	/*data cache*/
	void setDataCache(const doubleArray& dc){if(dc.size == 0) return; fprintf_s(mFile, "setAttr \".dc\" -type \"doubleArray\" ");dc.write(mFile);fprintf_s(mFile,";\n");}
	/*data cache*/
	void setDataCache(const DoubleArrayID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*The first frame of the cache.*/
	void setFirstCachedFrame(int fcf){if(fcf == 0) return; fprintf_s(mFile, "setAttr \".fcf\" %i;\n", fcf);}
	/*The first frame of the cache.*/
	void setFirstCachedFrame(const IntID& fcf){fprintf_s(mFile,"connectAttr \"");fcf.write(mFile);fprintf_s(mFile,"\" \"%s.fcf\";\n",mName.c_str());}
	/*The last frame of the cache.*/
	void setLastCachedFrame(int lcf){if(lcf == 0) return; fprintf_s(mFile, "setAttr \".lcf\" %i;\n", lcf);}
	/*The last frame of the cache.*/
	void setLastCachedFrame(const IntID& lcf){fprintf_s(mFile,"connectAttr \"");lcf.write(mFile);fprintf_s(mFile,"\" \"%s.lcf\";\n",mName.c_str());}
	/*The number of cached frames.*/
	void setCachedFrameCount(int cfc){if(cfc == 0) return; fprintf_s(mFile, "setAttr \".cfc\" %i;\n", cfc);}
	/*The number of cached frames.*/
	void setCachedFrameCount(const IntID& cfc){fprintf_s(mFile,"connectAttr \"");cfc.write(mFile);fprintf_s(mFile,"\" \"%s.cfc\";\n",mName.c_str());}
	/*REMOVE IN POST 2.0 RELEASE.*/
	void setCacheDirtyArray(const IntArrayID& cda){fprintf_s(mFile,"connectAttr \"");cda.write(mFile);fprintf_s(mFile,"\" \"%s.cda\";\n",mName.c_str());}
	/*index to rigid bodies which are contacting.*/
	void setContactName(size_t cnn_i,const StringID& cnn){fprintf_s(mFile,"connectAttr \"");cnn.write(mFile);fprintf_s(mFile,"\" \"%s.cnn[%i]\";\n",mName.c_str(),cnn_i);}
	/*connections to objects which this rigid body is allowed to interpenetrate.*/
	void setInterpenetrateWith(size_t itw_i,const MessageID& itw){fprintf_s(mFile,"connectAttr \"");itw.write(mFile);fprintf_s(mFile,"\" \"%s.itw[%i]\";\n",mName.c_str(),itw_i);}
	/*The initial position of the rigid body in the dynamics simulation.*/
	void setInitialPosition(const double3& ip){if(ip == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".ip\" -type \"double3\" ");ip.write(mFile);fprintf_s(mFile,";\n");}
	/*The X component of the initial position.*/
	void setInitialPositionX(double ipx){if(ipx == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipx\" %f;\n", ipx);}
	/*The X component of the initial position.*/
	void setInitialPositionX(const DoubleID& ipx){fprintf_s(mFile,"connectAttr \"");ipx.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipx\";\n",mName.c_str());}
	/*The Y component of the initial position.*/
	void setInitialPositionY(double ipy){if(ipy == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipy\" %f;\n", ipy);}
	/*The Y component of the initial position.*/
	void setInitialPositionY(const DoubleID& ipy){fprintf_s(mFile,"connectAttr \"");ipy.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipy\";\n",mName.c_str());}
	/*The Z component of the initial position.*/
	void setInitialPositionZ(double ipz){if(ipz == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipz\" %f;\n", ipz);}
	/*The Z component of the initial position.*/
	void setInitialPositionZ(const DoubleID& ipz){fprintf_s(mFile,"connectAttr \"");ipz.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipz\";\n",mName.c_str());}
	/*last position x of the rigid body.*/
	void setLastPositionX(const DoubleID& lpx){fprintf_s(mFile,"connectAttr \"");lpx.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpx\";\n",mName.c_str());}
	/*last position y of the rigid body.*/
	void setLastPositionY(const DoubleID& lpy){fprintf_s(mFile,"connectAttr \"");lpy.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpy\";\n",mName.c_str());}
	/*last position z of the rigid body.*/
	void setLastPositionZ(const DoubleID& lpz){fprintf_s(mFile,"connectAttr \"");lpz.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpz\";\n",mName.c_str());}
	/*last rotation x of the rigid body.*/
	void setLastRotationX(const DoubleID& lrx){fprintf_s(mFile,"connectAttr \"");lrx.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lrx\";\n",mName.c_str());}
	/*last rotation y of the rigid body.*/
	void setLastRotationY(const DoubleID& lry){fprintf_s(mFile,"connectAttr \"");lry.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lry\";\n",mName.c_str());}
	/*last rotation z of the rigid body.*/
	void setLastRotationZ(const DoubleID& lrz){fprintf_s(mFile,"connectAttr \"");lrz.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lrz\";\n",mName.c_str());}
	/*The initial orientation of the rigid body in the dynamics simulation.*/
	void setInitialOrientation(const double3& ior){if(ior == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".ior\" -type \"double3\" ");ior.write(mFile);fprintf_s(mFile,";\n");}
	/*The X component of the initial orientation.*/
	void setInitialOrientationX(double iox){if(iox == 0) return; fprintf_s(mFile, "setAttr \".ior.iox\" %f;\n", iox);}
	/*The X component of the initial orientation.*/
	void setInitialOrientationX(const DoubleID& iox){fprintf_s(mFile,"connectAttr \"");iox.write(mFile);fprintf_s(mFile,"\" \"%s.ior.iox\";\n",mName.c_str());}
	/*The Y component of the initial orientation.*/
	void setInitialOrientationY(double ioy){if(ioy == 0) return; fprintf_s(mFile, "setAttr \".ior.ioy\" %f;\n", ioy);}
	/*The Y component of the initial orientation.*/
	void setInitialOrientationY(const DoubleID& ioy){fprintf_s(mFile,"connectAttr \"");ioy.write(mFile);fprintf_s(mFile,"\" \"%s.ior.ioy\";\n",mName.c_str());}
	/*The Z component of the initial orientation.*/
	void setInitialOrientationZ(double ioz){if(ioz == 0) return; fprintf_s(mFile, "setAttr \".ior.ioz\" %f;\n", ioz);}
	/*The Z component of the initial orientation.*/
	void setInitialOrientationZ(const DoubleID& ioz){fprintf_s(mFile,"connectAttr \"");ioz.write(mFile);fprintf_s(mFile,"\" \"%s.ior.ioz\";\n",mName.c_str());}
	/*The initial velocity of the rigid body in the dynamics simulation.*/
	void setInitialVelocity(const double3& iv){if(iv == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".iv\" -type \"double3\" ");iv.write(mFile);fprintf_s(mFile,";\n");}
	/*The initial velocity of the rigid body in the dynamics simulation.*/
	void setInitialVelocity(const Double3ID& iv){fprintf_s(mFile,"connectAttr \"");iv.write(mFile);fprintf_s(mFile,"\" \"%s.iv\";\n",mName.c_str());}
	/*The X component of the initial velocity.*/
	void setInitialVelocityX(double ivx){if(ivx == 0.0) return; fprintf_s(mFile, "setAttr \".iv.ivx\" %f;\n", ivx);}
	/*The X component of the initial velocity.*/
	void setInitialVelocityX(const DoubleID& ivx){fprintf_s(mFile,"connectAttr \"");ivx.write(mFile);fprintf_s(mFile,"\" \"%s.iv.ivx\";\n",mName.c_str());}
	/*The Y component of the initial velocity.*/
	void setInitialVelocityY(double ivy){if(ivy == 0.0) return; fprintf_s(mFile, "setAttr \".iv.ivy\" %f;\n", ivy);}
	/*The Y component of the initial velocity.*/
	void setInitialVelocityY(const DoubleID& ivy){fprintf_s(mFile,"connectAttr \"");ivy.write(mFile);fprintf_s(mFile,"\" \"%s.iv.ivy\";\n",mName.c_str());}
	/*The Z component of the initial velocity.*/
	void setInitialVelocityZ(double ivz){if(ivz == 0.0) return; fprintf_s(mFile, "setAttr \".iv.ivz\" %f;\n", ivz);}
	/*The Z component of the initial velocity.*/
	void setInitialVelocityZ(const DoubleID& ivz){fprintf_s(mFile,"connectAttr \"");ivz.write(mFile);fprintf_s(mFile,"\" \"%s.iv.ivz\";\n",mName.c_str());}
	/*
	The initial angular (rotational) velocity of the rigid body
	in the dynamics simulation.
	*/
	void setInitialSpin(const double3& is){if(is == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".is\" -type \"double3\" ");is.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The initial angular (rotational) velocity of the rigid body
	in the dynamics simulation.
	*/
	void setInitialSpin(const Double3ID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The X component of the initial angular velocity.*/
	void setInitialSpinX(double isx){if(isx == 0) return; fprintf_s(mFile, "setAttr \".is.isx\" %f;\n", isx);}
	/*The X component of the initial angular velocity.*/
	void setInitialSpinX(const DoubleID& isx){fprintf_s(mFile,"connectAttr \"");isx.write(mFile);fprintf_s(mFile,"\" \"%s.is.isx\";\n",mName.c_str());}
	/*The Y component of the initial angular velocity.*/
	void setInitialSpinY(double isy){if(isy == 0) return; fprintf_s(mFile, "setAttr \".is.isy\" %f;\n", isy);}
	/*The Y component of the initial angular velocity.*/
	void setInitialSpinY(const DoubleID& isy){fprintf_s(mFile,"connectAttr \"");isy.write(mFile);fprintf_s(mFile,"\" \"%s.is.isy\";\n",mName.c_str());}
	/*The Z component of the initial angular velocity*/
	void setInitialSpinZ(double isz){if(isz == 0) return; fprintf_s(mFile, "setAttr \".is.isz\" %f;\n", isz);}
	/*The Z component of the initial angular velocity*/
	void setInitialSpinZ(const DoubleID& isz){fprintf_s(mFile,"connectAttr \"");isz.write(mFile);fprintf_s(mFile,"\" \"%s.is.isz\";\n",mName.c_str());}
	/*
	For purposes of the dynamic simulation this is the point
	(in object space) the object naturally should rotate around. For more
	realistic rotational motion this point should be placed at or near
	what would be considered the heaviest part of the rigid body.
	*/
	void setCenterOfMass(const double3& com){if(com == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".com\" -type \"double3\" ");com.write(mFile);fprintf_s(mFile,";\n");}
	/*
	For purposes of the dynamic simulation this is the point
	(in object space) the object naturally should rotate around. For more
	realistic rotational motion this point should be placed at or near
	what would be considered the heaviest part of the rigid body.
	*/
	void setCenterOfMass(const Double3ID& com){fprintf_s(mFile,"connectAttr \"");com.write(mFile);fprintf_s(mFile,"\" \"%s.com\";\n",mName.c_str());}
	/*The X component of the center of mass to rotate around.*/
	void setCenterOfMassX(double cmx){if(cmx == 0.0) return; fprintf_s(mFile, "setAttr \".com.cmx\" %f;\n", cmx);}
	/*The X component of the center of mass to rotate around.*/
	void setCenterOfMassX(const DoubleID& cmx){fprintf_s(mFile,"connectAttr \"");cmx.write(mFile);fprintf_s(mFile,"\" \"%s.com.cmx\";\n",mName.c_str());}
	/*The Y component of the center of mass to rotate around.*/
	void setCenterOfMassY(double cmy){if(cmy == 0.0) return; fprintf_s(mFile, "setAttr \".com.cmy\" %f;\n", cmy);}
	/*The Y component of the center of mass to rotate around.*/
	void setCenterOfMassY(const DoubleID& cmy){fprintf_s(mFile,"connectAttr \"");cmy.write(mFile);fprintf_s(mFile,"\" \"%s.com.cmy\";\n",mName.c_str());}
	/*The Z component of the center of mass to rotate around.*/
	void setCenterOfMassZ(double cmz){if(cmz == 0.0) return; fprintf_s(mFile, "setAttr \".com.cmz\" %f;\n", cmz);}
	/*The Z component of the center of mass to rotate around.*/
	void setCenterOfMassZ(const DoubleID& cmz){fprintf_s(mFile,"connectAttr \"");cmz.write(mFile);fprintf_s(mFile,"\" \"%s.com.cmz\";\n",mName.c_str());}
	/*
	Intended to be used to apply a momentary force
	(via keyframing of impulse) to the object.
	Should be zero except during the brief
	period the force is in effect.
	*/
	void setImpulse(const double3& imp){if(imp == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".imp\" -type \"double3\" ");imp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Intended to be used to apply a momentary force
	(via keyframing of impulse) to the object.
	Should be zero except during the brief
	period the force is in effect.
	*/
	void setImpulse(const Double3ID& imp){fprintf_s(mFile,"connectAttr \"");imp.write(mFile);fprintf_s(mFile,"\" \"%s.imp\";\n",mName.c_str());}
	/*The X component of the impulse force.*/
	void setImpulseX(double imx){if(imx == 0.0) return; fprintf_s(mFile, "setAttr \".imp.imx\" %f;\n", imx);}
	/*The X component of the impulse force.*/
	void setImpulseX(const DoubleID& imx){fprintf_s(mFile,"connectAttr \"");imx.write(mFile);fprintf_s(mFile,"\" \"%s.imp.imx\";\n",mName.c_str());}
	/*The Y component of the impulse force.*/
	void setImpulseY(double imy){if(imy == 0.0) return; fprintf_s(mFile, "setAttr \".imp.imy\" %f;\n", imy);}
	/*The Y component of the impulse force.*/
	void setImpulseY(const DoubleID& imy){fprintf_s(mFile,"connectAttr \"");imy.write(mFile);fprintf_s(mFile,"\" \"%s.imp.imy\";\n",mName.c_str());}
	/*The Z component of the impulse force.*/
	void setImpulseZ(double imz){if(imz == 0.0) return; fprintf_s(mFile, "setAttr \".imp.imz\" %f;\n", imz);}
	/*The Z component of the impulse force.*/
	void setImpulseZ(const DoubleID& imz){fprintf_s(mFile,"connectAttr \"");imz.write(mFile);fprintf_s(mFile,"\" \"%s.imp.imz\";\n",mName.c_str());}
	/*
	This is the position (in object space) at which the
	impulse force is applied to a rigid body.
	*/
	void setImpulsePosition(const double3& ipo){if(ipo == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".ipo\" -type \"double3\" ");ipo.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This is the position (in object space) at which the
	impulse force is applied to a rigid body.
	*/
	void setImpulsePosition(const Double3ID& ipo){fprintf_s(mFile,"connectAttr \"");ipo.write(mFile);fprintf_s(mFile,"\" \"%s.ipo\";\n",mName.c_str());}
	/*The X component of the position at which the impulse force is applied.*/
	void setImpulsePositionX(double pix){if(pix == 0.0) return; fprintf_s(mFile, "setAttr \".ipo.pix\" %f;\n", pix);}
	/*The X component of the position at which the impulse force is applied.*/
	void setImpulsePositionX(const DoubleID& pix){fprintf_s(mFile,"connectAttr \"");pix.write(mFile);fprintf_s(mFile,"\" \"%s.ipo.pix\";\n",mName.c_str());}
	/*The Y component of the position at which the impulse force is applied.*/
	void setImpulsePositionY(double piy){if(piy == 0.0) return; fprintf_s(mFile, "setAttr \".ipo.piy\" %f;\n", piy);}
	/*The Y component of the position at which the impulse force is applied.*/
	void setImpulsePositionY(const DoubleID& piy){fprintf_s(mFile,"connectAttr \"");piy.write(mFile);fprintf_s(mFile,"\" \"%s.ipo.piy\";\n",mName.c_str());}
	/*The Z component of the position at which the impulse force is applied.*/
	void setImpulsePositionZ(double piz){if(piz == 0.0) return; fprintf_s(mFile, "setAttr \".ipo.piz\" %f;\n", piz);}
	/*The Z component of the position at which the impulse force is applied.*/
	void setImpulsePositionZ(const DoubleID& piz){fprintf_s(mFile,"connectAttr \"");piz.write(mFile);fprintf_s(mFile,"\" \"%s.ipo.piz\";\n",mName.c_str());}
	/*
	Intended to be used to apply a momentary rotational force
	(via keyframing of spin impulse) to the object.
	Should be zero except during the brief
	period the force is in effect.
	*/
	void setSpinImpulse(const double3& sim){if(sim == double3(0, 0, 0)) return; fprintf_s(mFile, "setAttr \".sim\" -type \"double3\" ");sim.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Intended to be used to apply a momentary rotational force
	(via keyframing of spin impulse) to the object.
	Should be zero except during the brief
	period the force is in effect.
	*/
	void setSpinImpulse(const Double3ID& sim){fprintf_s(mFile,"connectAttr \"");sim.write(mFile);fprintf_s(mFile,"\" \"%s.sim\";\n",mName.c_str());}
	/*The X component of the rotational impulse force.*/
	void setSpinImpulseX(double six){if(six == 0.0) return; fprintf_s(mFile, "setAttr \".sim.six\" %f;\n", six);}
	/*The X component of the rotational impulse force.*/
	void setSpinImpulseX(const DoubleID& six){fprintf_s(mFile,"connectAttr \"");six.write(mFile);fprintf_s(mFile,"\" \"%s.sim.six\";\n",mName.c_str());}
	/*The Y component of the rotational impulse force.*/
	void setSpinImpulseY(double siy){if(siy == 0.0) return; fprintf_s(mFile, "setAttr \".sim.siy\" %f;\n", siy);}
	/*The Y component of the rotational impulse force.*/
	void setSpinImpulseY(const DoubleID& siy){fprintf_s(mFile,"connectAttr \"");siy.write(mFile);fprintf_s(mFile,"\" \"%s.sim.siy\";\n",mName.c_str());}
	/*The Z component of the rotational impulse force.*/
	void setSpinImpulseZ(double siz){if(siz == 0.0) return; fprintf_s(mFile, "setAttr \".sim.siz\" %f;\n", siz);}
	/*The Z component of the rotational impulse force.*/
	void setSpinImpulseZ(const DoubleID& siz){fprintf_s(mFile,"connectAttr \"");siz.write(mFile);fprintf_s(mFile,"\" \"%s.sim.siz\";\n",mName.c_str());}
	/*The mass of the rigid body. Use larger values for heavier objects.*/
	void setMass(double mas){if(mas == 1.0) return; fprintf_s(mFile, "setAttr \".mas\" %f;\n", mas);}
	/*The mass of the rigid body. Use larger values for heavier objects.*/
	void setMass(const DoubleID& mas){fprintf_s(mFile,"connectAttr \"");mas.write(mFile);fprintf_s(mFile,"\" \"%s.mas\";\n",mName.c_str());}
	/*volume of the rigid body.*/
	void setVolume(const DoubleID& vol){fprintf_s(mFile,"connectAttr \"");vol.write(mFile);fprintf_s(mFile,"\" \"%s.vol\";\n",mName.c_str());}
	/*
	Controls how much bounce a rigid body contributes
	to collisions. Larger values increase bounce.
	Imagine a ball bouncing up and down on a floor.
	If both the ball and the floor have a setting of 1.0
	the ball will bounce to the same height each time it bounces.
	If either the ball or the floor is modified to have a value
	less than 1.0 the height the ball bounces to will diminish
	each time it bounces. Conversely, if either the ball or the floor had
	been modified to have a value greater than 1.0 the ball would
	bounce higher with each bounce.
	*/
	void setBounciness(double b){if(b == 0.6) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*
	Controls how much bounce a rigid body contributes
	to collisions. Larger values increase bounce.
	Imagine a ball bouncing up and down on a floor.
	If both the ball and the floor have a setting of 1.0
	the ball will bounce to the same height each time it bounces.
	If either the ball or the floor is modified to have a value
	less than 1.0 the height the ball bounces to will diminish
	each time it bounces. Conversely, if either the ball or the floor had
	been modified to have a value greater than 1.0 the ball would
	bounce higher with each bounce.
	*/
	void setBounciness(const DoubleID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*
	Controls how much a rigid body tends to lose velocity.
	A value of 0 result in no velocity being lost to damping.
	A value of >0 results in velocity being lost.
	A value of <0 results in velocity being gained.
	Use larger values for large bulky rigid bodies and
	values closer to 0 for small compact rigid bodies.
	*/
	void setDamping(double dp){if(dp == 0.0) return; fprintf_s(mFile, "setAttr \".dp\" %f;\n", dp);}
	/*
	Controls how much a rigid body tends to lose velocity.
	A value of 0 result in no velocity being lost to damping.
	A value of >0 results in velocity being lost.
	A value of <0 results in velocity being gained.
	Use larger values for large bulky rigid bodies and
	values closer to 0 for small compact rigid bodies.
	*/
	void setDamping(const DoubleID& dp){fprintf_s(mFile,"connectAttr \"");dp.write(mFile);fprintf_s(mFile,"\" \"%s.dp\";\n",mName.c_str());}
	/*static friction value of the rigid body.*/
	void setStaticFriction(double sf){if(sf == 0.2) return; fprintf_s(mFile, "setAttr \".sf\" %f;\n", sf);}
	/*static friction value of the rigid body.*/
	void setStaticFriction(const DoubleID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sf\";\n",mName.c_str());}
	/*dynamic friction value of the rigid body.*/
	void setDynamicFriction(double df){if(df == 0.2) return; fprintf_s(mFile, "setAttr \".df\" %f;\n", df);}
	/*dynamic friction value of the rigid body.*/
	void setDynamicFriction(const DoubleID& df){fprintf_s(mFile,"connectAttr \"");df.write(mFile);fprintf_s(mFile,"\" \"%s.df\";\n",mName.c_str());}
	/*
	Determines which collision layer the rigid body is in.
	Rigid bodies will only collide with other rigid bodies
	that are in the same layer. Rigid bodies in collision
	layer -1 will collide with all other rigid bodies in the scene
	regardless of their collision layer.
	*/
	void setCollisionLayer(int cl){if(cl == 0) return; fprintf_s(mFile, "setAttr \".cl\" %i;\n", cl);}
	/*
	Determines which collision layer the rigid body is in.
	Rigid bodies will only collide with other rigid bodies
	that are in the same layer. Rigid bodies in collision
	layer -1 will collide with all other rigid bodies in the scene
	regardless of their collision layer.
	*/
	void setCollisionLayer(const IntID& cl){fprintf_s(mFile,"connectAttr \"");cl.write(mFile);fprintf_s(mFile,"\" \"%s.cl\";\n",mName.c_str());}
	/*
	To speed up the dynamics simulation at the expense of less accuracy.
	Set this to use a simpler shape (such as a sphere or cube)
	for collisions instead of the actual geometry.
	A setting of NONE will use the actual geometry.
	*/
	void setStandIn(unsigned int si){if(si == 0) return; fprintf_s(mFile, "setAttr \".si\" %i;\n", si);}
	/*
	To speed up the dynamics simulation at the expense of less accuracy.
	Set this to use a simpler shape (such as a sphere or cube)
	for collisions instead of the actual geometry.
	A setting of NONE will use the actual geometry.
	*/
	void setStandIn(const UnsignedintID& si){fprintf_s(mFile,"connectAttr \"");si.write(mFile);fprintf_s(mFile,"\" \"%s.si\";\n",mName.c_str());}
	/*number of geometry shapes connected to this rigid shape.*/
	void setInputGeometryCnt(int igc){if(igc == 0) return; fprintf_s(mFile, "setAttr \".igc\" %i;\n", igc);}
	/*number of geometry shapes connected to this rigid shape.*/
	void setInputGeometryCnt(const IntID& igc){fprintf_s(mFile,"connectAttr \"");igc.write(mFile);fprintf_s(mFile,"\" \"%s.igc\";\n",mName.c_str());}
	/*
	This determines whether the rigid body is treated as
	an active rigid body or a passive rigid body.
	*/
	void setActive(bool act){if(act == true) return; fprintf_s(mFile, "setAttr \".act\" %i;\n", act);}
	/*
	This determines whether the rigid body is treated as
	an active rigid body or a passive rigid body.
	*/
	void setActive(const BoolID& act){fprintf_s(mFile,"connectAttr \"");act.write(mFile);fprintf_s(mFile,"\" \"%s.act\";\n",mName.c_str());}
	/*determine which selection the choice node uses*/
	void setChoice(int chc){if(chc == 0) return; fprintf_s(mFile, "setAttr \".chc\" %i;\n", chc);}
	/*determine which selection the choice node uses*/
	void setChoice(const IntID& chc){fprintf_s(mFile,"connectAttr \"");chc.write(mFile);fprintf_s(mFile,"\" \"%s.chc\";\n",mName.c_str());}
	/*determines if the rigidBody is keyframed or parented.*/
	void setIsKinematic(bool kin){if(kin == false) return; fprintf_s(mFile, "setAttr \".kin\" %i;\n", kin);}
	/*determines if the rigidBody is keyframed or parented.*/
	void setIsKinematic(const BoolID& kin){fprintf_s(mFile,"connectAttr \"");kin.write(mFile);fprintf_s(mFile,"\" \"%s.kin\";\n",mName.c_str());}
	/*set if the rigid body is keyframed.*/
	void setIsKeyframed(bool key){if(key == false) return; fprintf_s(mFile, "setAttr \".key\" %i;\n", key);}
	/*set if the rigid body is keyframed.*/
	void setIsKeyframed(const BoolID& key){fprintf_s(mFile,"connectAttr \"");key.write(mFile);fprintf_s(mFile,"\" \"%s.key\";\n",mName.c_str());}
	/*set if the rigid body is parented.*/
	void setIsParented(bool par){if(par == false) return; fprintf_s(mFile, "setAttr \".par\" %i;\n", par);}
	/*set if the rigid body is parented.*/
	void setIsParented(const BoolID& par){fprintf_s(mFile,"connectAttr \"");par.write(mFile);fprintf_s(mFile,"\" \"%s.par\";\n",mName.c_str());}
	/*
	If this is an active rigid body and you have
	setup some particles to collide with it, setting this
	attribute to TRUE will allow the object to move as a result of
	those particle collisions.
	*/
	void setParticleCollision(bool pc){if(pc == false) return; fprintf_s(mFile, "setAttr \".pc\" %i;\n", pc);}
	/*
	If this is an active rigid body and you have
	setup some particles to collide with it, setting this
	attribute to TRUE will allow the object to move as a result of
	those particle collisions.
	*/
	void setParticleCollision(const BoolID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*Turns on and off the auto initialization feature.*/
	void setAutoInit(bool ai){if(ai == true) return; fprintf_s(mFile, "setAttr \".ai\" %i;\n", ai);}
	/*Turns on and off the auto initialization feature.*/
	void setAutoInit(const BoolID& ai){fprintf_s(mFile,"connectAttr \"");ai.write(mFile);fprintf_s(mFile,"\" \"%s.ai\";\n",mName.c_str());}
	/*
	Allows the user to disconnect the connection made by the rigid body to
	the solver, time node and choice nodes.
	*/
	void setAllowDisconnection(bool ad){if(ad == false) return; fprintf_s(mFile, "setAttr \".ad\" %i;\n", ad);}
	/*
	Allows the user to disconnect the connection made by the rigid body to
	the solver, time node and choice nodes.
	*/
	void setAllowDisconnection(const BoolID& ad){fprintf_s(mFile,"connectAttr \"");ad.write(mFile);fprintf_s(mFile,"\" \"%s.ad\";\n",mName.c_str());}
	/*data is in cache flag*/
	void setCacheData(bool idc){if(idc == false) return; fprintf_s(mFile, "setAttr \".idc\" %i;\n", idc);}
	/*data is in cache flag*/
	void setCacheData(const BoolID& idc){fprintf_s(mFile,"connectAttr \"");idc.write(mFile);fprintf_s(mFile,"\" \"%s.idc\";\n",mName.c_str());}
	/*The tessellation factor for nurbs surfaces.*/
	void setTessellationFactor(int tes){if(tes == 200) return; fprintf_s(mFile, "setAttr \".tes\" %i;\n", tes);}
	/*The current velocity of the rigid body.*/
	void setVelocity(const Double3ID& vel){fprintf_s(mFile,"connectAttr \"");vel.write(mFile);fprintf_s(mFile,"\" \"%s.vel\";\n",mName.c_str());}
	/*The X component of the current velocity.*/
	void setVelocityX(const DoubleID& vx){fprintf_s(mFile,"connectAttr \"");vx.write(mFile);fprintf_s(mFile,"\" \"%s.vel.vx\";\n",mName.c_str());}
	/*The Y component of the current velocity.*/
	void setVelocityY(const DoubleID& vy){fprintf_s(mFile,"connectAttr \"");vy.write(mFile);fprintf_s(mFile,"\" \"%s.vel.vy\";\n",mName.c_str());}
	/*The Z component of the current velocity.*/
	void setVelocityZ(const DoubleID& vz){fprintf_s(mFile,"connectAttr \"");vz.write(mFile);fprintf_s(mFile,"\" \"%s.vel.vz\";\n",mName.c_str());}
	/*The current angular velocity of the rigid body.*/
	void setSpin(const Double3ID& sp){fprintf_s(mFile,"connectAttr \"");sp.write(mFile);fprintf_s(mFile,"\" \"%s.sp\";\n",mName.c_str());}
	/*The X component of the current angular velocity.*/
	void setSpinX(const DoubleID& spx){fprintf_s(mFile,"connectAttr \"");spx.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spx\";\n",mName.c_str());}
	/*The Y component of the current angular velocity.*/
	void setSpinY(const DoubleID& spy){fprintf_s(mFile,"connectAttr \"");spy.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spy\";\n",mName.c_str());}
	/*The Z component of the current angular velocity.*/
	void setSpinZ(const DoubleID& spz){fprintf_s(mFile,"connectAttr \"");spz.write(mFile);fprintf_s(mFile,"\" \"%s.sp.spz\";\n",mName.c_str());}
	/*Number of valid contact points.*/
	void setContactCount(const IntID& cct){fprintf_s(mFile,"connectAttr \"");cct.write(mFile);fprintf_s(mFile,"\" \"%s.cct\";\n",mName.c_str());}
	/*Array of rigid body contact positions.*/
	void setContactPosition(size_t cnp_i,const Double3ID& cnp){fprintf_s(mFile,"connectAttr \"");cnp.write(mFile);fprintf_s(mFile,"\" \"%s.cnp[%i]\";\n",mName.c_str(),cnp_i);}
	/*X contact point*/
	void setContactX(size_t cnp_i,const DoubleID& cnx){fprintf_s(mFile,"connectAttr \"");cnx.write(mFile);fprintf_s(mFile,"\" \"%s.cnp[%i].cnx\";\n",mName.c_str(),cnp_i);}
	/*Y contact point*/
	void setContactY(size_t cnp_i,const DoubleID& cny){fprintf_s(mFile,"connectAttr \"");cny.write(mFile);fprintf_s(mFile,"\" \"%s.cnp[%i].cny\";\n",mName.c_str(),cnp_i);}
	/*Z contact point*/
	void setContactZ(size_t cnp_i,const DoubleID& cnz){fprintf_s(mFile,"connectAttr \"");cnz.write(mFile);fprintf_s(mFile,"\" \"%s.cnp[%i].cnz\";\n",mName.c_str(),cnp_i);}
	/*The current force on the rigid body.*/
	void setForce(const Double3ID& for_){fprintf_s(mFile,"connectAttr \"");for_.write(mFile);fprintf_s(mFile,"\" \"%s.for\";\n",mName.c_str());}
	/*The X component of the current force on the rigid body.*/
	void setForceX(const DoubleID& fx){fprintf_s(mFile,"connectAttr \"");fx.write(mFile);fprintf_s(mFile,"\" \"%s.for.fx\";\n",mName.c_str());}
	/*The Y component of the current force on the rigid body.*/
	void setForceY(const DoubleID& fy){fprintf_s(mFile,"connectAttr \"");fy.write(mFile);fprintf_s(mFile,"\" \"%s.for.fy\";\n",mName.c_str());}
	/*The Z component of the current force on the rigid body.*/
	void setForceZ(const DoubleID& fz){fprintf_s(mFile,"connectAttr \"");fz.write(mFile);fprintf_s(mFile,"\" \"%s.for.fz\";\n",mName.c_str());}
	/*The current torque on the rigid body.*/
	void setTorque(const Double3ID& tor){fprintf_s(mFile,"connectAttr \"");tor.write(mFile);fprintf_s(mFile,"\" \"%s.tor\";\n",mName.c_str());}
	/*The X component of the current torque on the rigid body.*/
	void setTorqueX(const DoubleID& trx){fprintf_s(mFile,"connectAttr \"");trx.write(mFile);fprintf_s(mFile,"\" \"%s.tor.trx\";\n",mName.c_str());}
	/*The Y component of the current torque on the rigid body.*/
	void setTorqueY(const DoubleID& try_){fprintf_s(mFile,"connectAttr \"");try_.write(mFile);fprintf_s(mFile,"\" \"%s.tor.try\";\n",mName.c_str());}
	/*The Z component of the current torque on the rigid body.*/
	void setTorqueZ(const DoubleID& trz){fprintf_s(mFile,"connectAttr \"");trz.write(mFile);fprintf_s(mFile,"\" \"%s.tor.trz\";\n",mName.c_str());}
	/*force data for the field forces.*/
	void setFieldData(const FieldDataID& fld){fprintf_s(mFile,"connectAttr \"");fld.write(mFile);fprintf_s(mFile,"\" \"%s.fld\";\n",mName.c_str());}
	/*position data for fields.*/
	void setFieldDataPosition(const VectorArrayID& fdp){fprintf_s(mFile,"connectAttr \"");fdp.write(mFile);fprintf_s(mFile,"\" \"%s.fld.fdp\";\n",mName.c_str());}
	/*velocity data for fields.*/
	void setFieldDataVelocity(const VectorArrayID& fdv){fprintf_s(mFile,"connectAttr \"");fdv.write(mFile);fprintf_s(mFile,"\" \"%s.fld.fdv\";\n",mName.c_str());}
	/*mass data for fields.*/
	void setFieldDataMass(const DoubleArrayID& fdm){fprintf_s(mFile,"connectAttr \"");fdm.write(mFile);fprintf_s(mFile,"\" \"%s.fld.fdm\";\n",mName.c_str());}
	/*some fields may need deltaTime to compute force (i.e. Vortex).*/
	void setDeltaTime(const TimeID& dt){fprintf_s(mFile,"connectAttr \"");dt.write(mFile);fprintf_s(mFile,"\" \"%s.fld.dt\";\n",mName.c_str());}
	/*force applied by external factors (fields) on the rigid body.*/
	void setInputForce(size_t ifr_i,const VectorArrayID& ifr){fprintf_s(mFile,"connectAttr \"");ifr.write(mFile);fprintf_s(mFile,"\" \"%s.ifr[%i]\";\n",mName.c_str(),ifr_i);}
	/*Type of force (positional/non-positional) connected to rigid body.*/
	void setInputForceType(size_t ift_i,bool ift){if(ift == false) return; fprintf_s(mFile, "setAttr \".ift[%i]\" %i;\n", ift_i,ift);}
	/*Type of force (positional/non-positional) connected to rigid body.*/
	void setInputForceType(size_t ift_i,const BoolID& ift){fprintf_s(mFile,"connectAttr \"");ift.write(mFile);fprintf_s(mFile,"\" \"%s.ift[%i]\";\n",mName.c_str(),ift_i);}
	/*particle collision force data*/
	void setCollisionRecords(size_t crc_i,const GenericArrayID& crc){fprintf_s(mFile,"connectAttr \"");crc.write(mFile);fprintf_s(mFile,"\" \"%s.crc[%i]\";\n",mName.c_str(),crc_i);}
	/*generalized for on the rigid body (forces and torques).*/
	void setGeneralForce(const GeneralForceID& gfr){fprintf_s(mFile,"connectAttr \"");gfr.write(mFile);fprintf_s(mFile,"\" \"%s.gfr\";\n",mName.c_str());}
	/*forces on the rigid body calculated from the external and collision forces.*/
	void setOutputForce(const VectorArrayID& ofr){fprintf_s(mFile,"connectAttr \"");ofr.write(mFile);fprintf_s(mFile,"\" \"%s.gfr.ofr\";\n",mName.c_str());}
	/*torques on the rigid body calculated from the external and collision forces.*/
	void setOutputTorque(const VectorArrayID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.gfr.otr\";\n",mName.c_str());}
	/*this is the index into the solver multi attributes.*/
	void setSolverId(int sid){if(sid == -1) return; fprintf_s(mFile, "setAttr \".sid\" %i;\n", sid);}
	/*this is the index into the solver multi attributes.*/
	void setSolverId(const IntID& sid){fprintf_s(mFile,"connectAttr \"");sid.write(mFile);fprintf_s(mFile,"\" \"%s.sid\";\n",mName.c_str());}
	/*Indicates the choice selection index during a bake simulation.*/
	void setBakeSimulationIndex(int bsi){if(bsi == -1) return; fprintf_s(mFile, "setAttr \".bsi\" %i;\n", bsi);}
	/*Indicates the choice selection index during a bake simulation.*/
	void setBakeSimulationIndex(const IntID& bsi){fprintf_s(mFile,"connectAttr \"");bsi.write(mFile);fprintf_s(mFile,"\" \"%s.bsi\";\n",mName.c_str());}
	/*
	Indicates that the shape has changed and needs updating.
	This is an internal attribute that should not be modified by the user.
	*/
	void setShapeChanged(const IntID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*
	Locks the center of mass of the rigid body so that
	it is not automatically recalculated if the object is modified.
	*/
	void setLockCenterOfMass(bool lcm){if(lcm == false) return; fprintf_s(mFile, "setAttr \".lcm\" %i;\n", lcm);}
	/*
	Locks the center of mass of the rigid body so that
	it is not automatically recalculated if the object is modified.
	*/
	void setLockCenterOfMass(const BoolID& lcm){fprintf_s(mFile,"connectAttr \"");lcm.write(mFile);fprintf_s(mFile,"\" \"%s.lcm\";\n",mName.c_str());}
	/*The rigid body is ignored in the simulator if true.*/
	void setIgnore(bool ign){if(ign == false) return; fprintf_s(mFile, "setAttr \".ign\" %i;\n", ign);}
	/*The rigid body is ignored in the simulator if true.*/
	void setIgnore(const BoolID& ign){fprintf_s(mFile,"connectAttr \"");ign.write(mFile);fprintf_s(mFile,"\" \"%s.ign\";\n",mName.c_str());}
	/*Turns collisions off if set false*/
	void setCollisions(bool col){if(col == true) return; fprintf_s(mFile, "setAttr \".col\" %i;\n", col);}
	/*Turns collisions off if set false*/
	void setCollisions(const BoolID& col){fprintf_s(mFile,"connectAttr \"");col.write(mFile);fprintf_s(mFile,"\" \"%s.col\";\n",mName.c_str());}
	/*Determines at what points to apply forces to the rigid body.*/
	void setApplyForceAt(unsigned int afa){if(afa == 1) return; fprintf_s(mFile, "setAttr \".afa\" %i;\n", afa);}
	/*Determines at what points to apply forces to the rigid body.*/
	void setApplyForceAt(const UnsignedintID& afa){fprintf_s(mFile,"connectAttr \"");afa.write(mFile);fprintf_s(mFile,"\" \"%s.afa\";\n",mName.c_str());}
	/*Draws the rigid body mesh.  Used for debugging only.*/
	void setDebugDraw(bool dd){if(dd == false) return; fprintf_s(mFile, "setAttr \".dd\" %i;\n", dd);}
	/*Draws the rigid body mesh.  Used for debugging only.*/
	void setDebugDraw(const BoolID& dd){fprintf_s(mFile,"connectAttr \"");dd.write(mFile);fprintf_s(mFile,"\" \"%s.dd\";\n",mName.c_str());}
	/*This holds the value for time.*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*
	Local transformation matrix. Contains the same information as
	the matrix attribute on dagNode but it is stored in a format
	that can be interpolated easily.
	*/
	MatrixID getRigidWorldMatrix(){char buffer[4096];sprintf_s (buffer, "%s.rmx",mName.c_str());return (const char*)buffer;}
	/*
	Obsolete attribute from version 1.
	Included only for file compatibility.  Not otherwise used.
	To be removed in post version 3 release.
	*/
	const MessageID& getFieldConnections(size_t fc_i){char buffer[4096];sprintf_s (buffer, "%s.fc[%i]",mName.c_str(),fc_i);return (const char*)buffer;}
	/*run up and instantaneous data cache.*/
	DoubleArrayID getRunUpCache(){char buffer[4096];sprintf_s (buffer, "%s.rc",mName.c_str());return (const char*)buffer;}
	/*data cache*/
	DoubleArrayID getDataCache(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*The first frame of the cache.*/
	IntID getFirstCachedFrame(){char buffer[4096];sprintf_s (buffer, "%s.fcf",mName.c_str());return (const char*)buffer;}
	/*The last frame of the cache.*/
	IntID getLastCachedFrame(){char buffer[4096];sprintf_s (buffer, "%s.lcf",mName.c_str());return (const char*)buffer;}
	/*The number of cached frames.*/
	IntID getCachedFrameCount(){char buffer[4096];sprintf_s (buffer, "%s.cfc",mName.c_str());return (const char*)buffer;}
	/*REMOVE IN POST 2.0 RELEASE.*/
	IntArrayID getCacheDirtyArray(){char buffer[4096];sprintf_s (buffer, "%s.cda",mName.c_str());return (const char*)buffer;}
	/*index to rigid bodies which are contacting.*/
	const StringID& getContactName(size_t cnn_i){char buffer[4096];sprintf_s (buffer, "%s.cnn[%i]",mName.c_str(),cnn_i);return (const char*)buffer;}
	/*connections to objects which this rigid body is allowed to interpenetrate.*/
	const MessageID& getInterpenetrateWith(size_t itw_i){char buffer[4096];sprintf_s (buffer, "%s.itw[%i]",mName.c_str(),itw_i);return (const char*)buffer;}
	/*The X component of the initial position.*/
	DoubleID getInitialPositionX(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the initial position.*/
	DoubleID getInitialPositionY(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the initial position.*/
	DoubleID getInitialPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipz",mName.c_str());return (const char*)buffer;}
	/*last position x of the rigid body.*/
	DoubleID getLastPositionX(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpx",mName.c_str());return (const char*)buffer;}
	/*last position y of the rigid body.*/
	DoubleID getLastPositionY(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpy",mName.c_str());return (const char*)buffer;}
	/*last position z of the rigid body.*/
	DoubleID getLastPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpz",mName.c_str());return (const char*)buffer;}
	/*last rotation x of the rigid body.*/
	DoubleID getLastRotationX(){char buffer[4096];sprintf_s (buffer, "%s.lr.lrx",mName.c_str());return (const char*)buffer;}
	/*last rotation y of the rigid body.*/
	DoubleID getLastRotationY(){char buffer[4096];sprintf_s (buffer, "%s.lr.lry",mName.c_str());return (const char*)buffer;}
	/*last rotation z of the rigid body.*/
	DoubleID getLastRotationZ(){char buffer[4096];sprintf_s (buffer, "%s.lr.lrz",mName.c_str());return (const char*)buffer;}
	/*The X component of the initial orientation.*/
	DoubleID getInitialOrientationX(){char buffer[4096];sprintf_s (buffer, "%s.ior.iox",mName.c_str());return (const char*)buffer;}
	/*The Y component of the initial orientation.*/
	DoubleID getInitialOrientationY(){char buffer[4096];sprintf_s (buffer, "%s.ior.ioy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the initial orientation.*/
	DoubleID getInitialOrientationZ(){char buffer[4096];sprintf_s (buffer, "%s.ior.ioz",mName.c_str());return (const char*)buffer;}
	/*The initial velocity of the rigid body in the dynamics simulation.*/
	Double3ID getInitialVelocity(){char buffer[4096];sprintf_s (buffer, "%s.iv",mName.c_str());return (const char*)buffer;}
	/*The X component of the initial velocity.*/
	DoubleID getInitialVelocityX(){char buffer[4096];sprintf_s (buffer, "%s.iv.ivx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the initial velocity.*/
	DoubleID getInitialVelocityY(){char buffer[4096];sprintf_s (buffer, "%s.iv.ivy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the initial velocity.*/
	DoubleID getInitialVelocityZ(){char buffer[4096];sprintf_s (buffer, "%s.iv.ivz",mName.c_str());return (const char*)buffer;}
	/*
	The initial angular (rotational) velocity of the rigid body
	in the dynamics simulation.
	*/
	Double3ID getInitialSpin(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*The X component of the initial angular velocity.*/
	DoubleID getInitialSpinX(){char buffer[4096];sprintf_s (buffer, "%s.is.isx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the initial angular velocity.*/
	DoubleID getInitialSpinY(){char buffer[4096];sprintf_s (buffer, "%s.is.isy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the initial angular velocity*/
	DoubleID getInitialSpinZ(){char buffer[4096];sprintf_s (buffer, "%s.is.isz",mName.c_str());return (const char*)buffer;}
	/*
	For purposes of the dynamic simulation this is the point
	(in object space) the object naturally should rotate around. For more
	realistic rotational motion this point should be placed at or near
	what would be considered the heaviest part of the rigid body.
	*/
	Double3ID getCenterOfMass(){char buffer[4096];sprintf_s (buffer, "%s.com",mName.c_str());return (const char*)buffer;}
	/*The X component of the center of mass to rotate around.*/
	DoubleID getCenterOfMassX(){char buffer[4096];sprintf_s (buffer, "%s.com.cmx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the center of mass to rotate around.*/
	DoubleID getCenterOfMassY(){char buffer[4096];sprintf_s (buffer, "%s.com.cmy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the center of mass to rotate around.*/
	DoubleID getCenterOfMassZ(){char buffer[4096];sprintf_s (buffer, "%s.com.cmz",mName.c_str());return (const char*)buffer;}
	/*
	Intended to be used to apply a momentary force
	(via keyframing of impulse) to the object.
	Should be zero except during the brief
	period the force is in effect.
	*/
	Double3ID getImpulse(){char buffer[4096];sprintf_s (buffer, "%s.imp",mName.c_str());return (const char*)buffer;}
	/*The X component of the impulse force.*/
	DoubleID getImpulseX(){char buffer[4096];sprintf_s (buffer, "%s.imp.imx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the impulse force.*/
	DoubleID getImpulseY(){char buffer[4096];sprintf_s (buffer, "%s.imp.imy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the impulse force.*/
	DoubleID getImpulseZ(){char buffer[4096];sprintf_s (buffer, "%s.imp.imz",mName.c_str());return (const char*)buffer;}
	/*
	This is the position (in object space) at which the
	impulse force is applied to a rigid body.
	*/
	Double3ID getImpulsePosition(){char buffer[4096];sprintf_s (buffer, "%s.ipo",mName.c_str());return (const char*)buffer;}
	/*The X component of the position at which the impulse force is applied.*/
	DoubleID getImpulsePositionX(){char buffer[4096];sprintf_s (buffer, "%s.ipo.pix",mName.c_str());return (const char*)buffer;}
	/*The Y component of the position at which the impulse force is applied.*/
	DoubleID getImpulsePositionY(){char buffer[4096];sprintf_s (buffer, "%s.ipo.piy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the position at which the impulse force is applied.*/
	DoubleID getImpulsePositionZ(){char buffer[4096];sprintf_s (buffer, "%s.ipo.piz",mName.c_str());return (const char*)buffer;}
	/*
	Intended to be used to apply a momentary rotational force
	(via keyframing of spin impulse) to the object.
	Should be zero except during the brief
	period the force is in effect.
	*/
	Double3ID getSpinImpulse(){char buffer[4096];sprintf_s (buffer, "%s.sim",mName.c_str());return (const char*)buffer;}
	/*The X component of the rotational impulse force.*/
	DoubleID getSpinImpulseX(){char buffer[4096];sprintf_s (buffer, "%s.sim.six",mName.c_str());return (const char*)buffer;}
	/*The Y component of the rotational impulse force.*/
	DoubleID getSpinImpulseY(){char buffer[4096];sprintf_s (buffer, "%s.sim.siy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the rotational impulse force.*/
	DoubleID getSpinImpulseZ(){char buffer[4096];sprintf_s (buffer, "%s.sim.siz",mName.c_str());return (const char*)buffer;}
	/*The mass of the rigid body. Use larger values for heavier objects.*/
	DoubleID getMass(){char buffer[4096];sprintf_s (buffer, "%s.mas",mName.c_str());return (const char*)buffer;}
	/*volume of the rigid body.*/
	DoubleID getVolume(){char buffer[4096];sprintf_s (buffer, "%s.vol",mName.c_str());return (const char*)buffer;}
	/*
	Controls how much bounce a rigid body contributes
	to collisions. Larger values increase bounce.
	Imagine a ball bouncing up and down on a floor.
	If both the ball and the floor have a setting of 1.0
	the ball will bounce to the same height each time it bounces.
	If either the ball or the floor is modified to have a value
	less than 1.0 the height the ball bounces to will diminish
	each time it bounces. Conversely, if either the ball or the floor had
	been modified to have a value greater than 1.0 the ball would
	bounce higher with each bounce.
	*/
	DoubleID getBounciness(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*
	Controls how much a rigid body tends to lose velocity.
	A value of 0 result in no velocity being lost to damping.
	A value of >0 results in velocity being lost.
	A value of <0 results in velocity being gained.
	Use larger values for large bulky rigid bodies and
	values closer to 0 for small compact rigid bodies.
	*/
	DoubleID getDamping(){char buffer[4096];sprintf_s (buffer, "%s.dp",mName.c_str());return (const char*)buffer;}
	/*static friction value of the rigid body.*/
	DoubleID getStaticFriction(){char buffer[4096];sprintf_s (buffer, "%s.sf",mName.c_str());return (const char*)buffer;}
	/*dynamic friction value of the rigid body.*/
	DoubleID getDynamicFriction(){char buffer[4096];sprintf_s (buffer, "%s.df",mName.c_str());return (const char*)buffer;}
	/*
	Determines which collision layer the rigid body is in.
	Rigid bodies will only collide with other rigid bodies
	that are in the same layer. Rigid bodies in collision
	layer -1 will collide with all other rigid bodies in the scene
	regardless of their collision layer.
	*/
	IntID getCollisionLayer(){char buffer[4096];sprintf_s (buffer, "%s.cl",mName.c_str());return (const char*)buffer;}
	/*
	To speed up the dynamics simulation at the expense of less accuracy.
	Set this to use a simpler shape (such as a sphere or cube)
	for collisions instead of the actual geometry.
	A setting of NONE will use the actual geometry.
	*/
	UnsignedintID getStandIn(){char buffer[4096];sprintf_s (buffer, "%s.si",mName.c_str());return (const char*)buffer;}
	/*number of geometry shapes connected to this rigid shape.*/
	IntID getInputGeometryCnt(){char buffer[4096];sprintf_s (buffer, "%s.igc",mName.c_str());return (const char*)buffer;}
	/*
	This determines whether the rigid body is treated as
	an active rigid body or a passive rigid body.
	*/
	BoolID getActive(){char buffer[4096];sprintf_s (buffer, "%s.act",mName.c_str());return (const char*)buffer;}
	/*determine which selection the choice node uses*/
	IntID getChoice(){char buffer[4096];sprintf_s (buffer, "%s.chc",mName.c_str());return (const char*)buffer;}
	/*determines if the rigidBody is keyframed or parented.*/
	BoolID getIsKinematic(){char buffer[4096];sprintf_s (buffer, "%s.kin",mName.c_str());return (const char*)buffer;}
	/*set if the rigid body is keyframed.*/
	BoolID getIsKeyframed(){char buffer[4096];sprintf_s (buffer, "%s.key",mName.c_str());return (const char*)buffer;}
	/*set if the rigid body is parented.*/
	BoolID getIsParented(){char buffer[4096];sprintf_s (buffer, "%s.par",mName.c_str());return (const char*)buffer;}
	/*
	If this is an active rigid body and you have
	setup some particles to collide with it, setting this
	attribute to TRUE will allow the object to move as a result of
	those particle collisions.
	*/
	BoolID getParticleCollision(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*Turns on and off the auto initialization feature.*/
	BoolID getAutoInit(){char buffer[4096];sprintf_s (buffer, "%s.ai",mName.c_str());return (const char*)buffer;}
	/*
	Allows the user to disconnect the connection made by the rigid body to
	the solver, time node and choice nodes.
	*/
	BoolID getAllowDisconnection(){char buffer[4096];sprintf_s (buffer, "%s.ad",mName.c_str());return (const char*)buffer;}
	/*data is in cache flag*/
	BoolID getCacheData(){char buffer[4096];sprintf_s (buffer, "%s.idc",mName.c_str());return (const char*)buffer;}
	/*The current velocity of the rigid body.*/
	Double3ID getVelocity(){char buffer[4096];sprintf_s (buffer, "%s.vel",mName.c_str());return (const char*)buffer;}
	/*The X component of the current velocity.*/
	DoubleID getVelocityX(){char buffer[4096];sprintf_s (buffer, "%s.vel.vx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the current velocity.*/
	DoubleID getVelocityY(){char buffer[4096];sprintf_s (buffer, "%s.vel.vy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the current velocity.*/
	DoubleID getVelocityZ(){char buffer[4096];sprintf_s (buffer, "%s.vel.vz",mName.c_str());return (const char*)buffer;}
	/*The current angular velocity of the rigid body.*/
	Double3ID getSpin(){char buffer[4096];sprintf_s (buffer, "%s.sp",mName.c_str());return (const char*)buffer;}
	/*The X component of the current angular velocity.*/
	DoubleID getSpinX(){char buffer[4096];sprintf_s (buffer, "%s.sp.spx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the current angular velocity.*/
	DoubleID getSpinY(){char buffer[4096];sprintf_s (buffer, "%s.sp.spy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the current angular velocity.*/
	DoubleID getSpinZ(){char buffer[4096];sprintf_s (buffer, "%s.sp.spz",mName.c_str());return (const char*)buffer;}
	/*Number of valid contact points.*/
	IntID getContactCount(){char buffer[4096];sprintf_s (buffer, "%s.cct",mName.c_str());return (const char*)buffer;}
	/*Array of rigid body contact positions.*/
	const Double3ID& getContactPosition(size_t cnp_i){char buffer[4096];sprintf_s (buffer, "%s.cnp[%i]",mName.c_str(),cnp_i);return (const char*)buffer;}
	/*X contact point*/
	const DoubleID& getContactX(size_t cnp_i){char buffer[4096];sprintf_s (buffer, "%s.cnp[%i].cnx",mName.c_str(),cnp_i);return (const char*)buffer;}
	/*Y contact point*/
	const DoubleID& getContactY(size_t cnp_i){char buffer[4096];sprintf_s (buffer, "%s.cnp[%i].cny",mName.c_str(),cnp_i);return (const char*)buffer;}
	/*Z contact point*/
	const DoubleID& getContactZ(size_t cnp_i){char buffer[4096];sprintf_s (buffer, "%s.cnp[%i].cnz",mName.c_str(),cnp_i);return (const char*)buffer;}
	/*The current force on the rigid body.*/
	Double3ID getForce(){char buffer[4096];sprintf_s (buffer, "%s.for",mName.c_str());return (const char*)buffer;}
	/*The X component of the current force on the rigid body.*/
	DoubleID getForceX(){char buffer[4096];sprintf_s (buffer, "%s.for.fx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the current force on the rigid body.*/
	DoubleID getForceY(){char buffer[4096];sprintf_s (buffer, "%s.for.fy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the current force on the rigid body.*/
	DoubleID getForceZ(){char buffer[4096];sprintf_s (buffer, "%s.for.fz",mName.c_str());return (const char*)buffer;}
	/*The current torque on the rigid body.*/
	Double3ID getTorque(){char buffer[4096];sprintf_s (buffer, "%s.tor",mName.c_str());return (const char*)buffer;}
	/*The X component of the current torque on the rigid body.*/
	DoubleID getTorqueX(){char buffer[4096];sprintf_s (buffer, "%s.tor.trx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the current torque on the rigid body.*/
	DoubleID getTorqueY(){char buffer[4096];sprintf_s (buffer, "%s.tor.try",mName.c_str());return (const char*)buffer;}
	/*The Z component of the current torque on the rigid body.*/
	DoubleID getTorqueZ(){char buffer[4096];sprintf_s (buffer, "%s.tor.trz",mName.c_str());return (const char*)buffer;}
	/*force data for the field forces.*/
	FieldDataID getFieldData(){char buffer[4096];sprintf_s (buffer, "%s.fld",mName.c_str());return (const char*)buffer;}
	/*position data for fields.*/
	VectorArrayID getFieldDataPosition(){char buffer[4096];sprintf_s (buffer, "%s.fld.fdp",mName.c_str());return (const char*)buffer;}
	/*velocity data for fields.*/
	VectorArrayID getFieldDataVelocity(){char buffer[4096];sprintf_s (buffer, "%s.fld.fdv",mName.c_str());return (const char*)buffer;}
	/*mass data for fields.*/
	DoubleArrayID getFieldDataMass(){char buffer[4096];sprintf_s (buffer, "%s.fld.fdm",mName.c_str());return (const char*)buffer;}
	/*some fields may need deltaTime to compute force (i.e. Vortex).*/
	TimeID getDeltaTime(){char buffer[4096];sprintf_s (buffer, "%s.fld.dt",mName.c_str());return (const char*)buffer;}
	/*force applied by external factors (fields) on the rigid body.*/
	const VectorArrayID& getInputForce(size_t ifr_i){char buffer[4096];sprintf_s (buffer, "%s.ifr[%i]",mName.c_str(),ifr_i);return (const char*)buffer;}
	/*Type of force (positional/non-positional) connected to rigid body.*/
	const BoolID& getInputForceType(size_t ift_i){char buffer[4096];sprintf_s (buffer, "%s.ift[%i]",mName.c_str(),ift_i);return (const char*)buffer;}
	/*particle collision force data*/
	const GenericArrayID& getCollisionRecords(size_t crc_i){char buffer[4096];sprintf_s (buffer, "%s.crc[%i]",mName.c_str(),crc_i);return (const char*)buffer;}
	/*generalized for on the rigid body (forces and torques).*/
	GeneralForceID getGeneralForce(){char buffer[4096];sprintf_s (buffer, "%s.gfr",mName.c_str());return (const char*)buffer;}
	/*forces on the rigid body calculated from the external and collision forces.*/
	VectorArrayID getOutputForce(){char buffer[4096];sprintf_s (buffer, "%s.gfr.ofr",mName.c_str());return (const char*)buffer;}
	/*torques on the rigid body calculated from the external and collision forces.*/
	VectorArrayID getOutputTorque(){char buffer[4096];sprintf_s (buffer, "%s.gfr.otr",mName.c_str());return (const char*)buffer;}
	/*this is the index into the solver multi attributes.*/
	IntID getSolverId(){char buffer[4096];sprintf_s (buffer, "%s.sid",mName.c_str());return (const char*)buffer;}
	/*Indicates the choice selection index during a bake simulation.*/
	IntID getBakeSimulationIndex(){char buffer[4096];sprintf_s (buffer, "%s.bsi",mName.c_str());return (const char*)buffer;}
	/*
	Indicates that the shape has changed and needs updating.
	This is an internal attribute that should not be modified by the user.
	*/
	IntID getShapeChanged(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	Locks the center of mass of the rigid body so that
	it is not automatically recalculated if the object is modified.
	*/
	BoolID getLockCenterOfMass(){char buffer[4096];sprintf_s (buffer, "%s.lcm",mName.c_str());return (const char*)buffer;}
	/*The rigid body is ignored in the simulator if true.*/
	BoolID getIgnore(){char buffer[4096];sprintf_s (buffer, "%s.ign",mName.c_str());return (const char*)buffer;}
	/*Turns collisions off if set false*/
	BoolID getCollisions(){char buffer[4096];sprintf_s (buffer, "%s.col",mName.c_str());return (const char*)buffer;}
	/*Determines at what points to apply forces to the rigid body.*/
	UnsignedintID getApplyForceAt(){char buffer[4096];sprintf_s (buffer, "%s.afa",mName.c_str());return (const char*)buffer;}
	/*Draws the rigid body mesh.  Used for debugging only.*/
	BoolID getDebugDraw(){char buffer[4096];sprintf_s (buffer, "%s.dd",mName.c_str());return (const char*)buffer;}
protected:
	RigidBody(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_RIGIDBODY_H__
