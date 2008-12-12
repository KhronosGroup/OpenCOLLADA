/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NPARTICLE_H__
#define __MayaDM_NPARTICLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMParticle.h"
namespace MayaDM
{
/*
<p><pre> The nParticle node implements a particle object which interacts with the
 nucleus dynamics solver.
</pre></p>
*/
class NParticle : public Particle
{
public:
public:
	NParticle(FILE* file,const std::string& name,const std::string& parent=""):Particle(file, name, parent, "nParticle"){}
	virtual ~NParticle(){}
	/*
	Input Geometr(y/ies) for soft body. This should be connected
	from the local/object-space version of the geometry.
	Valid inputs are polygons, nurbs surfaces, nurbs curves, and lattices.
	*/
	void setInputMesh(const GenericID& imsh){fprintf_s(mFile,"connectAttr \"");imsh.write(mFile);fprintf_s(mFile,"\" \"%s.imsh\";\n",mName.c_str());}
	/*Input for cached position data*/
	void setPositions(const GenericID& poss){fprintf_s(mFile,"connectAttr \"");poss.write(mFile);fprintf_s(mFile,"\" \"%s.poss\";\n",mName.c_str());}
	/*When enabled, it reads back position from the vector array input*/
	void setPlayFromCache(bool pfc){if(pfc == false) return; fprintf_s(mFile, "setAttr \".pfc\" %i;\n", pfc);}
	/*When enabled, it reads back position from the vector array input*/
	void setPlayFromCache(const BoolID& pfc){fprintf_s(mFile,"connectAttr \"");pfc.write(mFile);fprintf_s(mFile,"\" \"%s.pfc\";\n",mName.c_str());}
	/*Start positions*/
	void setStartPositions(const vectorArray& spns){if(spns.size == 0) return; fprintf_s(mFile, "setAttr \".spns\" -type \"vectorArray\" ");spns.write(mFile);fprintf_s(mFile,";\n");}
	/*Start positions*/
	void setStartPositions(const VectorArrayID& spns){fprintf_s(mFile,"connectAttr \"");spns.write(mFile);fprintf_s(mFile,"\" \"%s.spns\";\n",mName.c_str());}
	/*Start velocities*/
	void setStartVelocities(const vectorArray& sves){if(sves.size == 0) return; fprintf_s(mFile, "setAttr \".sves\" -type \"vectorArray\" ");sves.write(mFile);fprintf_s(mFile,";\n");}
	/*Start velocities*/
	void setStartVelocities(const VectorArrayID& sves){fprintf_s(mFile,"connectAttr \"");sves.write(mFile);fprintf_s(mFile,"\" \"%s.sves\";\n",mName.c_str());}
	/*Defines the thickness of each input/output mesh*/
	void setThickness(float thss){if(thss == 0.1) return; fprintf_s(mFile, "setAttr \".thss\" %f;\n", thss);}
	/*Defines the thickness of each input/output mesh*/
	void setThickness(const FloatID& thss){fprintf_s(mFile,"connectAttr \"");thss.write(mFile);fprintf_s(mFile,"\" \"%s.thss\";\n",mName.c_str());}
	/*Thickness map for cloth/object*/
	void setThicknessMap(float thmp){if(thmp == 0.1) return; fprintf_s(mFile, "setAttr \".thmp\" %f;\n", thmp);}
	/*Thickness map for cloth/object*/
	void setThicknessMap(const FloatID& thmp){fprintf_s(mFile,"connectAttr \"");thmp.write(mFile);fprintf_s(mFile,"\" \"%s.thmp\";\n",mName.c_str());}
	/*Per-vertex thickness for cloth/object*/
	void setThicknessPerVertex(const doubleArray& thpv){if(thpv.size == 0) return; fprintf_s(mFile, "setAttr \".thpv\" -type \"doubleArray\" ");thpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex thickness for cloth/object*/
	void setThicknessPerVertex(const DoubleArrayID& thpv){fprintf_s(mFile,"connectAttr \"");thpv.write(mFile);fprintf_s(mFile,"\" \"%s.thpv\";\n",mName.c_str());}
	/*Defines the self-collision bounce for each input/output mesh*/
	void setBounce(float boce){if(boce == 0.0) return; fprintf_s(mFile, "setAttr \".boce\" %f;\n", boce);}
	/*Defines the self-collision bounce for each input/output mesh*/
	void setBounce(const FloatID& boce){fprintf_s(mFile,"connectAttr \"");boce.write(mFile);fprintf_s(mFile,"\" \"%s.boce\";\n",mName.c_str());}
	/*Bounce map for cloth/object*/
	void setBounceMap(float bomp){if(bomp == 0.0) return; fprintf_s(mFile, "setAttr \".bomp\" %f;\n", bomp);}
	/*Bounce map for cloth/object*/
	void setBounceMap(const FloatID& bomp){fprintf_s(mFile,"connectAttr \"");bomp.write(mFile);fprintf_s(mFile,"\" \"%s.bomp\";\n",mName.c_str());}
	/*Per-vertex bounce for cloth/object*/
	void setBouncePerVertex(const doubleArray& bpv){if(bpv.size == 0) return; fprintf_s(mFile, "setAttr \".bpv\" -type \"doubleArray\" ");bpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex bounce for cloth/object*/
	void setBouncePerVertex(const DoubleArrayID& bpv){fprintf_s(mFile,"connectAttr \"");bpv.write(mFile);fprintf_s(mFile,"\" \"%s.bpv\";\n",mName.c_str());}
	/*Defines the self-collision friction for each input/output mesh*/
	void setFriction(float fron){if(fron == 0.1) return; fprintf_s(mFile, "setAttr \".fron\" %f;\n", fron);}
	/*Defines the self-collision friction for each input/output mesh*/
	void setFriction(const FloatID& fron){fprintf_s(mFile,"connectAttr \"");fron.write(mFile);fprintf_s(mFile,"\" \"%s.fron\";\n",mName.c_str());}
	/*Friction map for cloth/object*/
	void setFrictionMap(float frmp){if(frmp == 0.0) return; fprintf_s(mFile, "setAttr \".frmp\" %f;\n", frmp);}
	/*Friction map for cloth/object*/
	void setFrictionMap(const FloatID& frmp){fprintf_s(mFile,"connectAttr \"");frmp.write(mFile);fprintf_s(mFile,"\" \"%s.frmp\";\n",mName.c_str());}
	/*Per-vertex friction for cloth/object*/
	void setFrictionPerVertex(const doubleArray& fpv){if(fpv.size == 0) return; fprintf_s(mFile, "setAttr \".fpv\" -type \"doubleArray\" ");fpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex friction for cloth/object*/
	void setFrictionPerVertex(const DoubleArrayID& fpv){fprintf_s(mFile,"connectAttr \"");fpv.write(mFile);fprintf_s(mFile,"\" \"%s.fpv\";\n",mName.c_str());}
	/*Defines the motion-averaging damping for this mesh*/
	void setDamp(float adng){if(adng == 0.0) return; fprintf_s(mFile, "setAttr \".adng\" %f;\n", adng);}
	/*Defines the motion-averaging damping for this mesh*/
	void setDamp(const FloatID& adng){fprintf_s(mFile,"connectAttr \"");adng.write(mFile);fprintf_s(mFile,"\" \"%s.adng\";\n",mName.c_str());}
	/*damping map for cloth*/
	void setDampMap(float admp){if(admp == 0.0) return; fprintf_s(mFile, "setAttr \".admp\" %f;\n", admp);}
	/*damping map for cloth*/
	void setDampMap(const FloatID& admp){fprintf_s(mFile,"connectAttr \"");admp.write(mFile);fprintf_s(mFile,"\" \"%s.admp\";\n",mName.c_str());}
	/*Per-vertex damping for cloth/object*/
	void setDampPerVertex(const doubleArray& dpv){if(dpv.size == 0) return; fprintf_s(mFile, "setAttr \".dpv\" -type \"doubleArray\" ");dpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex damping for cloth/object*/
	void setDampPerVertex(const DoubleArrayID& dpv){fprintf_s(mFile,"connectAttr \"");dpv.write(mFile);fprintf_s(mFile,"\" \"%s.dpv\";\n",mName.c_str());}
	/*
	Controls the elements of the object that collide. Thickness is added to
	the collisions, so if vertex is selected the collisions are with spheres around
	each vertex. If edge is use then collisions are with cylinders around the
	edges as well as with spheres at the vertices. If face is selected then the entire
	surface is collided with. Note that the resulting collision surface for face, when
	thickness is applied is the sum of vertex edge and face collisions, so the effective borders
	of the mesh will be rounded and extended.
	*/
	void setCollisionFlag(unsigned int cofl){if(cofl == 2) return; fprintf_s(mFile, "setAttr \".cofl\" %i;\n", cofl);}
	/*
	Controls the elements of the object that collide. Thickness is added to
	the collisions, so if vertex is selected the collisions are with spheres around
	each vertex. If edge is use then collisions are with cylinders around the
	edges as well as with spheres at the vertices. If face is selected then the entire
	surface is collided with. Note that the resulting collision surface for face, when
	thickness is applied is the sum of vertex edge and face collisions, so the effective borders
	of the mesh will be rounded and extended.
	*/
	void setCollisionFlag(const UnsignedintID& cofl){fprintf_s(mFile,"connectAttr \"");cofl.write(mFile);fprintf_s(mFile,"\" \"%s.cofl\";\n",mName.c_str());}
	/*Controls the type(s) of collisions that are processed.*/
	void setSelfCollisionFlag(unsigned int scfl){if(scfl == 0) return; fprintf_s(mFile, "setAttr \".scfl\" %i;\n", scfl);}
	/*Controls the type(s) of collisions that are processed.*/
	void setSelfCollisionFlag(const UnsignedintID& scfl){fprintf_s(mFile,"connectAttr \"");scfl.write(mFile);fprintf_s(mFile,"\" \"%s.scfl\";\n",mName.c_str());}
	/*Maximum number of self collision iterations per subcycle.*/
	void setMaxSelfCollisionIterations(int msci){if(msci == 4) return; fprintf_s(mFile, "setAttr \".msci\" %i;\n", msci);}
	/*Maximum number of self collision iterations per subcycle.*/
	void setMaxSelfCollisionIterations(const IntID& msci){fprintf_s(mFile,"connectAttr \"");msci.write(mFile);fprintf_s(mFile,"\" \"%s.msci\";\n",mName.c_str());}
	/*
	Defines the maximum number of iterations used to compute various dynamic
	properties like drag, damping, stretch and bend. Higher iterations take longer,
	and the primary use of this attribute is to keep things from locking up should
	high iteration values be requested. High values on dynamic attributes, high resolution geometry or
	large times steps can all increase the attempted number of iterations.
	*/
	void setMaxIterations(int mxit){if(mxit == 500) return; fprintf_s(mFile, "setAttr \".mxit\" %i;\n", mxit);}
	/*
	Defines the maximum number of iterations used to compute various dynamic
	properties like drag, damping, stretch and bend. Higher iterations take longer,
	and the primary use of this attribute is to keep things from locking up should
	high iteration values be requested. High values on dynamic attributes, high resolution geometry or
	large times steps can all increase the attempted number of iterations.
	*/
	void setMaxIterations(const IntID& mxit){fprintf_s(mFile,"connectAttr \"");mxit.write(mFile);fprintf_s(mFile,"\" \"%s.mxit\";\n",mName.c_str());}
	/*Base mass for cloth/object*/
	void setPointMass(float pmss){if(pmss == 1.0) return; fprintf_s(mFile, "setAttr \".pmss\" %f;\n", pmss);}
	/*Base mass for cloth/object*/
	void setPointMass(const FloatID& pmss){fprintf_s(mFile,"connectAttr \"");pmss.write(mFile);fprintf_s(mFile,"\" \"%s.pmss\";\n",mName.c_str());}
	/*Mass map for cloth/object*/
	void setMassMap(float mamp){if(mamp == 1.0) return; fprintf_s(mFile, "setAttr \".mamp\" %f;\n", mamp);}
	/*Mass map for cloth/object*/
	void setMassMap(const FloatID& mamp){fprintf_s(mFile,"connectAttr \"");mamp.write(mFile);fprintf_s(mFile,"\" \"%s.mamp\";\n",mName.c_str());}
	/*Per-vertex mass for cloth/object*/
	void setMassPerVertex(const doubleArray& mpv){if(mpv.size == 0) return; fprintf_s(mFile, "setAttr \".mpv\" -type \"doubleArray\" ");mpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex mass for cloth/object*/
	void setMassPerVertex(const DoubleArrayID& mpv){fprintf_s(mFile,"connectAttr \"");mpv.write(mFile);fprintf_s(mFile,"\" \"%s.mpv\";\n",mName.c_str());}
	/*Allows the rest length to change with the object size*/
	void setRestLengthScale(float rlsc){if(rlsc == 1.0) return; fprintf_s(mFile, "setAttr \".rlsc\" %f;\n", rlsc);}
	/*Allows the rest length to change with the object size*/
	void setRestLengthScale(const FloatID& rlsc){fprintf_s(mFile,"connectAttr \"");rlsc.write(mFile);fprintf_s(mFile,"\" \"%s.rlsc\";\n",mName.c_str());}
	/*Tell the solver whether or not to solve this object*/
	void setActive(bool actv){if(actv == 1) return; fprintf_s(mFile, "setAttr \".actv\" %i;\n", actv);}
	/*Tell the solver whether or not to solve this object*/
	void setActive(const BoolID& actv){fprintf_s(mFile,"connectAttr \"");actv.write(mFile);fprintf_s(mFile,"\" \"%s.actv\";\n",mName.c_str());}
	/*Tell the solver if this object participates in collisions*/
	void setCollide(bool cold){if(cold == 1) return; fprintf_s(mFile, "setAttr \".cold\" %i;\n", cold);}
	/*Tell the solver if this object participates in collisions*/
	void setCollide(const BoolID& cold){fprintf_s(mFile,"connectAttr \"");cold.write(mFile);fprintf_s(mFile,"\" \"%s.cold\";\n",mName.c_str());}
	/*Tell the solver if this object collides with its own geometry*/
	void setSelfCollide(bool scld){if(scld == 1) return; fprintf_s(mFile, "setAttr \".scld\" %i;\n", scld);}
	/*Tell the solver if this object collides with its own geometry*/
	void setSelfCollide(const BoolID& scld){fprintf_s(mFile,"connectAttr \"");scld.write(mFile);fprintf_s(mFile,"\" \"%s.scld\";\n",mName.c_str());}
	/*
	Layer for collision with other objects. Objects with the same layer value intercollide
	in a normal fashion, while if the layer values are different the object with the lower value
	will appear more massive for the purpose of the collision. If the difference is one or more
	then the object with the lower value will push but not be pushed. This is useful for layered
	clothing, where one could assign a lower collision layer for the shirt than for as coat. This will
	make it easier for the solver to simulate the coat without interpentration errors. Note that one
	can also use the collision layer to keep some objects from intercolliding altogether, optimizing
	the performance. The attribute collisionLayerRange on the solver works with collison layer to
	determine collision exclusion.  For example if one does not wishes to collide a shirt with the
	body and a coat with the shirt, but not collide the coat to the body, one can do so by making
	the collision layer 0 on the body, 1 on the shirt and 2 on the coat and setting the collisionLayerRange
	to 1.5. The difference between the coat(2) and the body (0) is 2, which is greater than 1.5 thus
	they will not collide, while the coat and the shirt are only different by 1, so they will collide.
	*/
	void setCollisionLayer(float cll){if(cll == 0.0) return; fprintf_s(mFile, "setAttr \".cll\" %f;\n", cll);}
	/*
	Layer for collision with other objects. Objects with the same layer value intercollide
	in a normal fashion, while if the layer values are different the object with the lower value
	will appear more massive for the purpose of the collision. If the difference is one or more
	then the object with the lower value will push but not be pushed. This is useful for layered
	clothing, where one could assign a lower collision layer for the shirt than for as coat. This will
	make it easier for the solver to simulate the coat without interpentration errors. Note that one
	can also use the collision layer to keep some objects from intercolliding altogether, optimizing
	the performance. The attribute collisionLayerRange on the solver works with collison layer to
	determine collision exclusion.  For example if one does not wishes to collide a shirt with the
	body and a coat with the shirt, but not collide the coat to the body, one can do so by making
	the collision layer 0 on the body, 1 on the shirt and 2 on the coat and setting the collisionLayerRange
	to 1.5. The difference between the coat(2) and the body (0) is 2, which is greater than 1.5 thus
	they will not collide, while the coat and the shirt are only different by 1, so they will collide.
	*/
	void setCollisionLayer(const FloatID& cll){fprintf_s(mFile,"connectAttr \"");cll.write(mFile);fprintf_s(mFile,"\" \"%s.cll\";\n",mName.c_str());}
	/*How much does the wind diffuse around this object*/
	void setWindShadowDiffusion(float wsdi){if(wsdi == 0.0) return; fprintf_s(mFile, "setAttr \".wsdi\" %f;\n", wsdi);}
	/*How much does the wind diffuse around this object*/
	void setWindShadowDiffusion(const FloatID& wsdi){fprintf_s(mFile,"connectAttr \"");wsdi.write(mFile);fprintf_s(mFile,"\" \"%s.wsdi\";\n",mName.c_str());}
	/*The distance over which the wind shadow drops off behind this object*/
	void setWindShadowDistance(float wsds){if(wsds == 0.0) return; fprintf_s(mFile, "setAttr \".wsds\" %f;\n", wsds);}
	/*The distance over which the wind shadow drops off behind this object*/
	void setWindShadowDistance(const FloatID& wsds){fprintf_s(mFile,"connectAttr \"");wsds.write(mFile);fprintf_s(mFile,"\" \"%s.wsds\";\n",mName.c_str());}
	/*
	The distance over which the wind created by the motion
	of this object affects other objects.
	*/
	void setAirPushDistance(float apds){if(apds == 0.0) return; fprintf_s(mFile, "setAttr \".apds\" %f;\n", apds);}
	/*
	The distance over which the wind created by the motion
	of this object affects other objects.
	*/
	void setAirPushDistance(const FloatID& apds){fprintf_s(mFile,"connectAttr \"");apds.write(mFile);fprintf_s(mFile,"\" \"%s.apds\";\n",mName.c_str());}
	/*
	The distance over which the wind created by the motion
	of this object affects other objects.
	*/
	void setAirPushVorticity(float apvy){if(apvy == 0.0) return; fprintf_s(mFile, "setAttr \".apvy\" %f;\n", apvy);}
	/*
	The distance over which the wind created by the motion
	of this object affects other objects.
	*/
	void setAirPushVorticity(const FloatID& apvy){fprintf_s(mFile,"connectAttr \"");apvy.write(mFile);fprintf_s(mFile,"\" \"%s.apvy\";\n",mName.c_str());}
	/*
	A force to push out other objects to the nearest point on this objects surface.
	This can be useful when dealing with objects that are in collision at the start frame.
	As well this can be animated to help fix a bad state at certain frames. It is even
	possible to use this in a limited sense instead of collisions, but it can fail for
	fast moving collisions.
	At a force value of 1 it pushes objects completely out in one step. Lower values
	will take more steps but may be smoother. The push
	amount takes into account the collide width values. Points further from the
	surface than the pushOutRadius value will be ignored.  If the value of
	pushOut is positive then the push is towards the positive normal side of the surface.
	Negative values push to the opposite of the normal side of the surface.
	*/
	void setPushOut(float pou){if(pou == 0.0) return; fprintf_s(mFile, "setAttr \".pou\" %f;\n", pou);}
	/*
	A force to push out other objects to the nearest point on this objects surface.
	This can be useful when dealing with objects that are in collision at the start frame.
	As well this can be animated to help fix a bad state at certain frames. It is even
	possible to use this in a limited sense instead of collisions, but it can fail for
	fast moving collisions.
	At a force value of 1 it pushes objects completely out in one step. Lower values
	will take more steps but may be smoother. The push
	amount takes into account the collide width values. Points further from the
	surface than the pushOutRadius value will be ignored.  If the value of
	pushOut is positive then the push is towards the positive normal side of the surface.
	Negative values push to the opposite of the normal side of the surface.
	*/
	void setPushOut(const FloatID& pou){fprintf_s(mFile,"connectAttr \"");pou.write(mFile);fprintf_s(mFile,"\" \"%s.pou\";\n",mName.c_str());}
	/*
	This defines the max distance from the surface that pushOut will affect.
	Thus objects more than this distance from this object will not be affected by the
	push out.
	*/
	void setPushOutRadius(float por){if(por == 10.0) return; fprintf_s(mFile, "setAttr \".por\" %f;\n", por);}
	/*
	This defines the max distance from the surface that pushOut will affect.
	Thus objects more than this distance from this object will not be affected by the
	push out.
	*/
	void setPushOutRadius(const FloatID& por){fprintf_s(mFile,"connectAttr \"");por.write(mFile);fprintf_s(mFile,"\" \"%s.por\";\n",mName.c_str());}
	/*
	This is a force applied to other objects along the contour where
	they crossover this object. Because it only works at the point of crossover
	it may take several steps for the surface to pop out into a good state. If
	collisions are enabled for this object on may wish to combine this with the
	trappedCheck toggle because that will disable collisions for crossed over objects.
	It can also be used to clean up interpenetration at the start frame, although the collisions
	should be disabled when doing so. This handles sharp edges better than the pushOut attribute,
	but requires that the surfaces be crossing at some point and can take more steps. It
	also may shift or rotate meshes more than the pushOut in some cases. Lower values will
	take longer to resolve the collision, but can create smoother results.
	*/
	void setCrossoverPush(float cop){if(cop == 0.0) return; fprintf_s(mFile, "setAttr \".cop\" %f;\n", cop);}
	/*
	This is a force applied to other objects along the contour where
	they crossover this object. Because it only works at the point of crossover
	it may take several steps for the surface to pop out into a good state. If
	collisions are enabled for this object on may wish to combine this with the
	trappedCheck toggle because that will disable collisions for crossed over objects.
	It can also be used to clean up interpenetration at the start frame, although the collisions
	should be disabled when doing so. This handles sharp edges better than the pushOut attribute,
	but requires that the surfaces be crossing at some point and can take more steps. It
	also may shift or rotate meshes more than the pushOut in some cases. Lower values will
	take longer to resolve the collision, but can create smoother results.
	*/
	void setCrossoverPush(const FloatID& cop){fprintf_s(mFile,"connectAttr \"");cop.write(mFile);fprintf_s(mFile,"\" \"%s.cop\";\n",mName.c_str());}
	/*
	This tracks collision crossovers and attempts to push the crossed over points
	back. It assumes that the surface is in a good state at the start and attempts to
	preserve that relative state. It is very useful in cases where cloth can get caught
	between passive objects than interpenetrate (for example an elbow passing through a
	chest). Rather than get stuck on the wrong side this allows the cloth to push back
	to the correct side when the passive objects later separate.
	*/
	void setTrappedCheck(bool tpc){if(tpc == 0) return; fprintf_s(mFile, "setAttr \".tpc\" %i;\n", tpc);}
	/*
	This tracks collision crossovers and attempts to push the crossed over points
	back. It assumes that the surface is in a good state at the start and attempts to
	preserve that relative state. It is very useful in cases where cloth can get caught
	between passive objects than interpenetrate (for example an elbow passing through a
	chest). Rather than get stuck on the wrong side this allows the cloth to push back
	to the correct side when the passive objects later separate.
	*/
	void setTrappedCheck(const BoolID& tpc){fprintf_s(mFile,"connectAttr \"");tpc.write(mFile);fprintf_s(mFile,"\" \"%s.tpc\";\n",mName.c_str());}
	/*What type of thickness map to use: per-vertex, texture or none.*/
	void setThicknessMapType(unsigned int tmt){if(tmt == 2) return; fprintf_s(mFile, "setAttr \".tmt\" %i;\n", tmt);}
	/*What type of thickness map to use: per-vertex, texture or none.*/
	void setThicknessMapType(const UnsignedintID& tmt){fprintf_s(mFile,"connectAttr \"");tmt.write(mFile);fprintf_s(mFile,"\" \"%s.tmt\";\n",mName.c_str());}
	/*What type of bounce map to use: per-vertex, texture or none.*/
	void setBounceMapType(unsigned int bmt){if(bmt == 2) return; fprintf_s(mFile, "setAttr \".bmt\" %i;\n", bmt);}
	/*What type of bounce map to use: per-vertex, texture or none.*/
	void setBounceMapType(const UnsignedintID& bmt){fprintf_s(mFile,"connectAttr \"");bmt.write(mFile);fprintf_s(mFile,"\" \"%s.bmt\";\n",mName.c_str());}
	/*What type of friction map to use: per-vertex, texture or none.*/
	void setFrictionMapType(unsigned int fmt){if(fmt == 2) return; fprintf_s(mFile, "setAttr \".fmt\" %i;\n", fmt);}
	/*What type of friction map to use: per-vertex, texture or none.*/
	void setFrictionMapType(const UnsignedintID& fmt){fprintf_s(mFile,"connectAttr \"");fmt.write(mFile);fprintf_s(mFile,"\" \"%s.fmt\";\n",mName.c_str());}
	/*What type of damp map to use: per-vertex, texture or none.*/
	void setDampMapType(unsigned int dmt){if(dmt == 2) return; fprintf_s(mFile, "setAttr \".dmt\" %i;\n", dmt);}
	/*What type of damp map to use: per-vertex, texture or none.*/
	void setDampMapType(const UnsignedintID& dmt){fprintf_s(mFile,"connectAttr \"");dmt.write(mFile);fprintf_s(mFile,"\" \"%s.dmt\";\n",mName.c_str());}
	/*What type of mass map to use: per-vertex, texture or none.*/
	void setMassMapType(unsigned int mmt){if(mmt == 2) return; fprintf_s(mFile, "setAttr \".mmt\" %i;\n", mmt);}
	/*What type of mass map to use: per-vertex, texture or none.*/
	void setMassMapType(const UnsignedintID& mmt){fprintf_s(mFile,"connectAttr \"");mmt.write(mFile);fprintf_s(mFile,"\" \"%s.mmt\";\n",mName.c_str());}
	/*Geometry and material properties coverted to nData*/
	void setCurrentState(const GenericID& cust){fprintf_s(mFile,"connectAttr \"");cust.write(mFile);fprintf_s(mFile,"\" \"%s.cust\";\n",mName.c_str());}
	/*Geometry and material properties coverted to nData*/
	void setStartState(const GenericID& stst){fprintf_s(mFile,"connectAttr \"");stst.write(mFile);fprintf_s(mFile,"\" \"%s.stst\";\n",mName.c_str());}
	/*
	Internal Id that identifies a Nucleus object to other members
	of the Nsystem
	*/
	void setNucleusId(const GenericID& nuid){fprintf_s(mFile,"connectAttr \"");nuid.write(mFile);fprintf_s(mFile,"\" \"%s.nuid\";\n",mName.c_str());}
	/*If true then output is transformed from world to local space.*/
	void setLocalSpaceOutput(bool lsou){if(lsou == 0) return; fprintf_s(mFile, "setAttr \".lsou\" %i;\n", lsou);}
	/*If true then output is transformed from world to local space.*/
	void setLocalSpaceOutput(const BoolID& lsou){fprintf_s(mFile,"connectAttr \"");lsou.write(mFile);fprintf_s(mFile,"\" \"%s.lsou\";\n",mName.c_str());}
	/*Color for interactive display of thickness.*/
	void setDisplayColor(const float3& dcl){fprintf_s(mFile, "setAttr \".dcl\" -type \"float3\" ");dcl.write(mFile);fprintf_s(mFile,";\n");}
	/*Color for interactive display of thickness.*/
	void setDisplayColor(const Float3ID& dcl){fprintf_s(mFile,"connectAttr \"");dcl.write(mFile);fprintf_s(mFile,"\" \"%s.dcl\";\n",mName.c_str());}
	/*display Red value*/
	void setDisplayColorR(float dcr){if(dcr == 1.0) return; fprintf_s(mFile, "setAttr \".dcl.dcr\" %f;\n", dcr);}
	/*display Red value*/
	void setDisplayColorR(const FloatID& dcr){fprintf_s(mFile,"connectAttr \"");dcr.write(mFile);fprintf_s(mFile,"\" \"%s.dcl.dcr\";\n",mName.c_str());}
	/*display Green value*/
	void setDisplayColorG(float dcg){if(dcg == 0.8) return; fprintf_s(mFile, "setAttr \".dcl.dcg\" %f;\n", dcg);}
	/*display Green value*/
	void setDisplayColorG(const FloatID& dcg){fprintf_s(mFile,"connectAttr \"");dcg.write(mFile);fprintf_s(mFile,"\" \"%s.dcl.dcg\";\n",mName.c_str());}
	/*display Blue value*/
	void setDisplayColorB(float dcb){if(dcb == 0.0) return; fprintf_s(mFile, "setAttr \".dcl.dcb\" %f;\n", dcb);}
	/*display Blue value*/
	void setDisplayColorB(const FloatID& dcb){fprintf_s(mFile,"connectAttr \"");dcb.write(mFile);fprintf_s(mFile,"\" \"%s.dcl.dcb\";\n",mName.c_str());}
	/*
	Input Geometr(y/ies) for soft body. This should be connected
	from the local/object-space version of the geometry.
	Valid inputs are polygons, nurbs surfaces, nurbs curves, and lattices.
	*/
	GenericID getInputMesh(){char buffer[4096];sprintf_s (buffer, "%s.imsh",mName.c_str());return (const char*)buffer;}
	/*Input for cached position data*/
	GenericID getPositions(){char buffer[4096];sprintf_s (buffer, "%s.poss",mName.c_str());return (const char*)buffer;}
	/*When enabled, it reads back position from the vector array input*/
	BoolID getPlayFromCache(){char buffer[4096];sprintf_s (buffer, "%s.pfc",mName.c_str());return (const char*)buffer;}
	/*Start positions*/
	VectorArrayID getStartPositions(){char buffer[4096];sprintf_s (buffer, "%s.spns",mName.c_str());return (const char*)buffer;}
	/*Start velocities*/
	VectorArrayID getStartVelocities(){char buffer[4096];sprintf_s (buffer, "%s.sves",mName.c_str());return (const char*)buffer;}
	/*Defines the thickness of each input/output mesh*/
	FloatID getThickness(){char buffer[4096];sprintf_s (buffer, "%s.thss",mName.c_str());return (const char*)buffer;}
	/*Thickness map for cloth/object*/
	FloatID getThicknessMap(){char buffer[4096];sprintf_s (buffer, "%s.thmp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex thickness for cloth/object*/
	DoubleArrayID getThicknessPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.thpv",mName.c_str());return (const char*)buffer;}
	/*Defines the self-collision bounce for each input/output mesh*/
	FloatID getBounce(){char buffer[4096];sprintf_s (buffer, "%s.boce",mName.c_str());return (const char*)buffer;}
	/*Bounce map for cloth/object*/
	FloatID getBounceMap(){char buffer[4096];sprintf_s (buffer, "%s.bomp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex bounce for cloth/object*/
	DoubleArrayID getBouncePerVertex(){char buffer[4096];sprintf_s (buffer, "%s.bpv",mName.c_str());return (const char*)buffer;}
	/*Defines the self-collision friction for each input/output mesh*/
	FloatID getFriction(){char buffer[4096];sprintf_s (buffer, "%s.fron",mName.c_str());return (const char*)buffer;}
	/*Friction map for cloth/object*/
	FloatID getFrictionMap(){char buffer[4096];sprintf_s (buffer, "%s.frmp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex friction for cloth/object*/
	DoubleArrayID getFrictionPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.fpv",mName.c_str());return (const char*)buffer;}
	/*Defines the motion-averaging damping for this mesh*/
	FloatID getDamp(){char buffer[4096];sprintf_s (buffer, "%s.adng",mName.c_str());return (const char*)buffer;}
	/*damping map for cloth*/
	FloatID getDampMap(){char buffer[4096];sprintf_s (buffer, "%s.admp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex damping for cloth/object*/
	DoubleArrayID getDampPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.dpv",mName.c_str());return (const char*)buffer;}
	/*
	Controls the elements of the object that collide. Thickness is added to
	the collisions, so if vertex is selected the collisions are with spheres around
	each vertex. If edge is use then collisions are with cylinders around the
	edges as well as with spheres at the vertices. If face is selected then the entire
	surface is collided with. Note that the resulting collision surface for face, when
	thickness is applied is the sum of vertex edge and face collisions, so the effective borders
	of the mesh will be rounded and extended.
	*/
	UnsignedintID getCollisionFlag(){char buffer[4096];sprintf_s (buffer, "%s.cofl",mName.c_str());return (const char*)buffer;}
	/*Controls the type(s) of collisions that are processed.*/
	UnsignedintID getSelfCollisionFlag(){char buffer[4096];sprintf_s (buffer, "%s.scfl",mName.c_str());return (const char*)buffer;}
	/*Maximum number of self collision iterations per subcycle.*/
	IntID getMaxSelfCollisionIterations(){char buffer[4096];sprintf_s (buffer, "%s.msci",mName.c_str());return (const char*)buffer;}
	/*
	Defines the maximum number of iterations used to compute various dynamic
	properties like drag, damping, stretch and bend. Higher iterations take longer,
	and the primary use of this attribute is to keep things from locking up should
	high iteration values be requested. High values on dynamic attributes, high resolution geometry or
	large times steps can all increase the attempted number of iterations.
	*/
	IntID getMaxIterations(){char buffer[4096];sprintf_s (buffer, "%s.mxit",mName.c_str());return (const char*)buffer;}
	/*Base mass for cloth/object*/
	FloatID getPointMass(){char buffer[4096];sprintf_s (buffer, "%s.pmss",mName.c_str());return (const char*)buffer;}
	/*Mass map for cloth/object*/
	FloatID getMassMap(){char buffer[4096];sprintf_s (buffer, "%s.mamp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex mass for cloth/object*/
	DoubleArrayID getMassPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.mpv",mName.c_str());return (const char*)buffer;}
	/*Allows the rest length to change with the object size*/
	FloatID getRestLengthScale(){char buffer[4096];sprintf_s (buffer, "%s.rlsc",mName.c_str());return (const char*)buffer;}
	/*Tell the solver whether or not to solve this object*/
	BoolID getActive(){char buffer[4096];sprintf_s (buffer, "%s.actv",mName.c_str());return (const char*)buffer;}
	/*Tell the solver if this object participates in collisions*/
	BoolID getCollide(){char buffer[4096];sprintf_s (buffer, "%s.cold",mName.c_str());return (const char*)buffer;}
	/*Tell the solver if this object collides with its own geometry*/
	BoolID getSelfCollide(){char buffer[4096];sprintf_s (buffer, "%s.scld",mName.c_str());return (const char*)buffer;}
	/*
	Layer for collision with other objects. Objects with the same layer value intercollide
	in a normal fashion, while if the layer values are different the object with the lower value
	will appear more massive for the purpose of the collision. If the difference is one or more
	then the object with the lower value will push but not be pushed. This is useful for layered
	clothing, where one could assign a lower collision layer for the shirt than for as coat. This will
	make it easier for the solver to simulate the coat without interpentration errors. Note that one
	can also use the collision layer to keep some objects from intercolliding altogether, optimizing
	the performance. The attribute collisionLayerRange on the solver works with collison layer to
	determine collision exclusion.  For example if one does not wishes to collide a shirt with the
	body and a coat with the shirt, but not collide the coat to the body, one can do so by making
	the collision layer 0 on the body, 1 on the shirt and 2 on the coat and setting the collisionLayerRange
	to 1.5. The difference between the coat(2) and the body (0) is 2, which is greater than 1.5 thus
	they will not collide, while the coat and the shirt are only different by 1, so they will collide.
	*/
	FloatID getCollisionLayer(){char buffer[4096];sprintf_s (buffer, "%s.cll",mName.c_str());return (const char*)buffer;}
	/*How much does the wind diffuse around this object*/
	FloatID getWindShadowDiffusion(){char buffer[4096];sprintf_s (buffer, "%s.wsdi",mName.c_str());return (const char*)buffer;}
	/*The distance over which the wind shadow drops off behind this object*/
	FloatID getWindShadowDistance(){char buffer[4096];sprintf_s (buffer, "%s.wsds",mName.c_str());return (const char*)buffer;}
	/*
	The distance over which the wind created by the motion
	of this object affects other objects.
	*/
	FloatID getAirPushDistance(){char buffer[4096];sprintf_s (buffer, "%s.apds",mName.c_str());return (const char*)buffer;}
	/*
	The distance over which the wind created by the motion
	of this object affects other objects.
	*/
	FloatID getAirPushVorticity(){char buffer[4096];sprintf_s (buffer, "%s.apvy",mName.c_str());return (const char*)buffer;}
	/*
	A force to push out other objects to the nearest point on this objects surface.
	This can be useful when dealing with objects that are in collision at the start frame.
	As well this can be animated to help fix a bad state at certain frames. It is even
	possible to use this in a limited sense instead of collisions, but it can fail for
	fast moving collisions.
	At a force value of 1 it pushes objects completely out in one step. Lower values
	will take more steps but may be smoother. The push
	amount takes into account the collide width values. Points further from the
	surface than the pushOutRadius value will be ignored.  If the value of
	pushOut is positive then the push is towards the positive normal side of the surface.
	Negative values push to the opposite of the normal side of the surface.
	*/
	FloatID getPushOut(){char buffer[4096];sprintf_s (buffer, "%s.pou",mName.c_str());return (const char*)buffer;}
	/*
	This defines the max distance from the surface that pushOut will affect.
	Thus objects more than this distance from this object will not be affected by the
	push out.
	*/
	FloatID getPushOutRadius(){char buffer[4096];sprintf_s (buffer, "%s.por",mName.c_str());return (const char*)buffer;}
	/*
	This is a force applied to other objects along the contour where
	they crossover this object. Because it only works at the point of crossover
	it may take several steps for the surface to pop out into a good state. If
	collisions are enabled for this object on may wish to combine this with the
	trappedCheck toggle because that will disable collisions for crossed over objects.
	It can also be used to clean up interpenetration at the start frame, although the collisions
	should be disabled when doing so. This handles sharp edges better than the pushOut attribute,
	but requires that the surfaces be crossing at some point and can take more steps. It
	also may shift or rotate meshes more than the pushOut in some cases. Lower values will
	take longer to resolve the collision, but can create smoother results.
	*/
	FloatID getCrossoverPush(){char buffer[4096];sprintf_s (buffer, "%s.cop",mName.c_str());return (const char*)buffer;}
	/*
	This tracks collision crossovers and attempts to push the crossed over points
	back. It assumes that the surface is in a good state at the start and attempts to
	preserve that relative state. It is very useful in cases where cloth can get caught
	between passive objects than interpenetrate (for example an elbow passing through a
	chest). Rather than get stuck on the wrong side this allows the cloth to push back
	to the correct side when the passive objects later separate.
	*/
	BoolID getTrappedCheck(){char buffer[4096];sprintf_s (buffer, "%s.tpc",mName.c_str());return (const char*)buffer;}
	/*What type of thickness map to use: per-vertex, texture or none.*/
	UnsignedintID getThicknessMapType(){char buffer[4096];sprintf_s (buffer, "%s.tmt",mName.c_str());return (const char*)buffer;}
	/*What type of bounce map to use: per-vertex, texture or none.*/
	UnsignedintID getBounceMapType(){char buffer[4096];sprintf_s (buffer, "%s.bmt",mName.c_str());return (const char*)buffer;}
	/*What type of friction map to use: per-vertex, texture or none.*/
	UnsignedintID getFrictionMapType(){char buffer[4096];sprintf_s (buffer, "%s.fmt",mName.c_str());return (const char*)buffer;}
	/*What type of damp map to use: per-vertex, texture or none.*/
	UnsignedintID getDampMapType(){char buffer[4096];sprintf_s (buffer, "%s.dmt",mName.c_str());return (const char*)buffer;}
	/*What type of mass map to use: per-vertex, texture or none.*/
	UnsignedintID getMassMapType(){char buffer[4096];sprintf_s (buffer, "%s.mmt",mName.c_str());return (const char*)buffer;}
	/*Geometry and material properties coverted to nData*/
	GenericID getCurrentState(){char buffer[4096];sprintf_s (buffer, "%s.cust",mName.c_str());return (const char*)buffer;}
	/*Geometry and material properties coverted to nData*/
	GenericID getStartState(){char buffer[4096];sprintf_s (buffer, "%s.stst",mName.c_str());return (const char*)buffer;}
	/*
	Internal Id that identifies a Nucleus object to other members
	of the Nsystem
	*/
	GenericID getNucleusId(){char buffer[4096];sprintf_s (buffer, "%s.nuid",mName.c_str());return (const char*)buffer;}
	/*If true then output is transformed from world to local space.*/
	BoolID getLocalSpaceOutput(){char buffer[4096];sprintf_s (buffer, "%s.lsou",mName.c_str());return (const char*)buffer;}
	/*Color for interactive display of thickness.*/
	Float3ID getDisplayColor(){char buffer[4096];sprintf_s (buffer, "%s.dcl",mName.c_str());return (const char*)buffer;}
	/*display Red value*/
	FloatID getDisplayColorR(){char buffer[4096];sprintf_s (buffer, "%s.dcl.dcr",mName.c_str());return (const char*)buffer;}
	/*display Green value*/
	FloatID getDisplayColorG(){char buffer[4096];sprintf_s (buffer, "%s.dcl.dcg",mName.c_str());return (const char*)buffer;}
	/*display Blue value*/
	FloatID getDisplayColorB(){char buffer[4096];sprintf_s (buffer, "%s.dcl.dcb",mName.c_str());return (const char*)buffer;}
protected:
	NParticle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Particle(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NPARTICLE_H__
