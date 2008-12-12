/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NCLOTH_H__
#define __MayaDM_NCLOTH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNParticle.h"
namespace MayaDM
{
/*
<p><pre>The nCloth node applys dynamic motion to a deformable mesh.
 This can be used to simulate cloth behavior, as well as other
 deformable dynamic shapes, such as metal.
</pre></p>
*/
class NCloth : public NParticle
{
public:
public:
	NCloth(FILE* file,const std::string& name,const std::string& parent=""):NParticle(file, name, parent, "nCloth"){}
	virtual ~NCloth(){}
	/*Output Geometry for soft body.*/
	void setOutputMesh(const GenericID& omsh){fprintf_s(mFile,"connectAttr \"");omsh.write(mFile);fprintf_s(mFile,"\" \"%s.omsh\";\n",mName.c_str());}
	/*
	RestPosition Geometr(y/ies). This is the shape that the cloth
	tries to achieves. It may be animated over time, but should have the
	exact same topology as the inputMesh.
	*/
	void setRestShapeMesh(const GenericID& rsmh){fprintf_s(mFile,"connectAttr \"");rsmh.write(mFile);fprintf_s(mFile,"\" \"%s.rsmh\";\n",mName.c_str());}
	/*Number of subdivisions for each input/output mesh pairing.*/
	void setNumSubdivisions(int nsub){if(nsub == 2) return; fprintf_s(mFile, "setAttr \".nsub\" %i;\n", nsub);}
	/*Number of subdivisions for each input/output mesh pairing.*/
	void setNumSubdivisions(const IntID& nsub){fprintf_s(mFile,"connectAttr \"");nsub.write(mFile);fprintf_s(mFile,"\" \"%s.nsub\";\n",mName.c_str());}
	/*
	This defines the way dynamic attributes such as bend, stretch and tension are defined relative to
	object scale and cv density.
	If Link is specified then stretch and bend are fixed values applied at each link. Thus if a mesh has more
	cvs it will appear to be more stretchy and bendable, even thought the amount of stretch and bend is the same
	on a per link basis.
	With Object Space the mesh will bend and stretch the same amount regardless of the resolution of the mesh. Note
	that this can result in significantly greater compute times for the high resolution mesh, as the individual links
	need to be stiffer, which requires more calculation( on top of having more links to compute ).
	World Space is similar to ObjectSpace, except that the stiffness of the mesh is now fixed in worldspace. Thus scaling
	a mesh up will make it appear to be a larger sheet made of the same material, which appears proportionately less stiff.
	For example a small piece of paper may bend little under gravity, but a large sheet would flop.
	*/
	void setScalingRelation(unsigned int srl){if(srl == 0) return; fprintf_s(mFile, "setAttr \".srl\" %i;\n", srl);}
	/*
	This defines the way dynamic attributes such as bend, stretch and tension are defined relative to
	object scale and cv density.
	If Link is specified then stretch and bend are fixed values applied at each link. Thus if a mesh has more
	cvs it will appear to be more stretchy and bendable, even thought the amount of stretch and bend is the same
	on a per link basis.
	With Object Space the mesh will bend and stretch the same amount regardless of the resolution of the mesh. Note
	that this can result in significantly greater compute times for the high resolution mesh, as the individual links
	need to be stiffer, which requires more calculation( on top of having more links to compute ).
	World Space is similar to ObjectSpace, except that the stiffness of the mesh is now fixed in worldspace. Thus scaling
	a mesh up will make it appear to be a larger sheet made of the same material, which appears proportionately less stiff.
	For example a small piece of paper may bend little under gravity, but a large sheet would flop.
	*/
	void setScalingRelation(const UnsignedintID& srl){fprintf_s(mFile,"connectAttr \"");srl.write(mFile);fprintf_s(mFile,"\" \"%s.srl\";\n",mName.c_str());}
	/*
	Defines the amount that the material will resist stretching when under tension.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined. Also one may need to additionally make the both collision iterations on the solver
	and constraint strength values high to keep stretching low.
	*/
	void setStretchResistance(float stch){if(stch == 20.0) return; fprintf_s(mFile, "setAttr \".stch\" %f;\n", stch);}
	/*
	Defines the amount that the material will resist stretching when under tension.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined. Also one may need to additionally make the both collision iterations on the solver
	and constraint strength values high to keep stretching low.
	*/
	void setStretchResistance(const FloatID& stch){fprintf_s(mFile,"connectAttr \"");stch.write(mFile);fprintf_s(mFile,"\" \"%s.stch\";\n",mName.c_str());}
	/*
	Defines the amount that the material will resist compression. Note that sometimes it is useful to have
	this value be lower than the Stretch Resistance, because the mesh resolution is only an approximation
	to a true surface, which could possibly fold within the length of a triangle. If one has a rest
	position for a cloth that is not flat and the compression and stretch resistance are both high then
	this can make cloth appear too stiff because the topology locks up. This problem is most noticable when
	the faces have relatively high angles relative to each other. Having a low compression resistance allows
	the material keep from locking up, yet still not appear to stretchy.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined. Also stretch mapping scales both compression and stretch.
	*/
	void setCompressionResistance(float comr){if(comr == 10.0) return; fprintf_s(mFile, "setAttr \".comr\" %f;\n", comr);}
	/*
	Defines the amount that the material will resist compression. Note that sometimes it is useful to have
	this value be lower than the Stretch Resistance, because the mesh resolution is only an approximation
	to a true surface, which could possibly fold within the length of a triangle. If one has a rest
	position for a cloth that is not flat and the compression and stretch resistance are both high then
	this can make cloth appear too stiff because the topology locks up. This problem is most noticable when
	the faces have relatively high angles relative to each other. Having a low compression resistance allows
	the material keep from locking up, yet still not appear to stretchy.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined. Also stretch mapping scales both compression and stretch.
	*/
	void setCompressionResistance(const FloatID& comr){fprintf_s(mFile,"connectAttr \"");comr.write(mFile);fprintf_s(mFile,"\" \"%s.comr\";\n",mName.c_str());}
	/*Stretch map for cloth/object*/
	void setStretchMap(float stmp){if(stmp == 1.0) return; fprintf_s(mFile, "setAttr \".stmp\" %f;\n", stmp);}
	/*Stretch map for cloth/object*/
	void setStretchMap(const FloatID& stmp){fprintf_s(mFile,"connectAttr \"");stmp.write(mFile);fprintf_s(mFile,"\" \"%s.stmp\";\n",mName.c_str());}
	/*Per-vertex stretch for cloth/object*/
	void setStretchPerVertex(const doubleArray& spv){if(spv.size == 0) return; fprintf_s(mFile, "setAttr \".spv\" -type \"doubleArray\" ");spv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex stretch for cloth/object*/
	void setStretchPerVertex(const DoubleArrayID& spv){fprintf_s(mFile,"connectAttr \"");spv.write(mFile);fprintf_s(mFile,"\" \"%s.spv\";\n",mName.c_str());}
	/*
	Defines the amount that the material will resist bending when under strain.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined.
	*/
	void setBendResistance(float bnd){if(bnd == 0.1) return; fprintf_s(mFile, "setAttr \".bnd\" %f;\n", bnd);}
	/*
	Defines the amount that the material will resist bending when under strain.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined.
	*/
	void setBendResistance(const FloatID& bnd){fprintf_s(mFile,"connectAttr \"");bnd.write(mFile);fprintf_s(mFile,"\" \"%s.bnd\";\n",mName.c_str());}
	/*Bend map for cloth/object*/
	void setBendMap(float bemp){if(bemp == 0.0) return; fprintf_s(mFile, "setAttr \".bemp\" %f;\n", bemp);}
	/*Bend map for cloth/object*/
	void setBendMap(const FloatID& bemp){fprintf_s(mFile,"connectAttr \"");bemp.write(mFile);fprintf_s(mFile,"\" \"%s.bemp\";\n",mName.c_str());}
	/*Per-vertex bend for cloth/object*/
	void setBendPerVertex(const doubleArray& bdpv){if(bdpv.size == 0) return; fprintf_s(mFile, "setAttr \".bdpv\" -type \"doubleArray\" ");bdpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex bend for cloth/object*/
	void setBendPerVertex(const DoubleArrayID& bdpv){fprintf_s(mFile,"connectAttr \"");bdpv.write(mFile);fprintf_s(mFile,"\" \"%s.bdpv\";\n",mName.c_str());}
	/*
	Defines the way bend resistance changes with the angle.
	At higher values the bend will resist more at high angles
	then when the surface is nearly flat.
	*/
	void setBendAngleDropoff(float bnad){if(bnad == 0.0) return; fprintf_s(mFile, "setAttr \".bnad\" %f;\n", bnad);}
	/*
	Defines the way bend resistance changes with the angle.
	At higher values the bend will resist more at high angles
	then when the surface is nearly flat.
	*/
	void setBendAngleDropoff(const FloatID& bnad){fprintf_s(mFile,"connectAttr \"");bnad.write(mFile);fprintf_s(mFile,"\" \"%s.bnad\";\n",mName.c_str());}
	/*
	How far can the links be stretched before they fail
	to go back to their rest length when there are no
	forces acting on the cloth. When the tension is greater than the
	defined value the defined rest length will increase until the tension is equal this value.
	For very low values the material will pull apart like taffy, yet still resist stretching under
	mild forces.
	*/
	void setRestitutionTension(float retn){if(retn == 1000.0) return; fprintf_s(mFile, "setAttr \".retn\" %f;\n", retn);}
	/*
	How far can the links be stretched before they fail
	to go back to their rest length when there are no
	forces acting on the cloth. When the tension is greater than the
	defined value the defined rest length will increase until the tension is equal this value.
	For very low values the material will pull apart like taffy, yet still resist stretching under
	mild forces.
	*/
	void setRestitutionTension(const FloatID& retn){fprintf_s(mFile,"connectAttr \"");retn.write(mFile);fprintf_s(mFile,"\" \"%s.retn\";\n",mName.c_str());}
	/*
	Defines how far we can bend across an edge before it will fail
	to go back to the rest angle when there are no
	forces acting on the cloth.
	*/
	void setRestitutionAngle(float reae){if(reae == 3) return; fprintf_s(mFile, "setAttr \".reae\" %f;\n", reae);}
	/*
	Defines how far we can bend across an edge before it will fail
	to go back to the rest angle when there are no
	forces acting on the cloth.
	*/
	void setRestitutionAngle(const FloatID& reae){fprintf_s(mFile,"connectAttr \"");reae.write(mFile);fprintf_s(mFile,"\" \"%s.reae\";\n",mName.c_str());}
	/*
	Defines the shear resistance for each input/output mesh.
	Shear can be thought of as the bend in the plane
	of the cloth.
	*/
	void setShearResistance(float shr){if(shr == 0.0) return; fprintf_s(mFile, "setAttr \".shr\" %f;\n", shr);}
	/*
	Defines the shear resistance for each input/output mesh.
	Shear can be thought of as the bend in the plane
	of the cloth.
	*/
	void setShearResistance(const FloatID& shr){fprintf_s(mFile,"connectAttr \"");shr.write(mFile);fprintf_s(mFile,"\" \"%s.shr\";\n",mName.c_str());}
	/*Defines how inclined the mesh is to be a rigid body*/
	void setRigidity(float rity){if(rity == 0.0) return; fprintf_s(mFile, "setAttr \".rity\" %f;\n", rity);}
	/*Defines how inclined the mesh is to be a rigid body*/
	void setRigidity(const FloatID& rity){fprintf_s(mFile,"connectAttr \"");rity.write(mFile);fprintf_s(mFile,"\" \"%s.rity\";\n",mName.c_str());}
	/*Rigidity map for cloth/object*/
	void setRigidityMap(float rimp){if(rimp == 0.0) return; fprintf_s(mFile, "setAttr \".rimp\" %f;\n", rimp);}
	/*Rigidity map for cloth/object*/
	void setRigidityMap(const FloatID& rimp){fprintf_s(mFile,"connectAttr \"");rimp.write(mFile);fprintf_s(mFile,"\" \"%s.rimp\";\n",mName.c_str());}
	/*Per-vertex rigidity for cloth/object*/
	void setRigidityPerVertex(const doubleArray& rpv){if(rpv.size == 0) return; fprintf_s(mFile, "setAttr \".rpv\" -type \"doubleArray\" ");rpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex rigidity for cloth/object*/
	void setRigidityPerVertex(const DoubleArrayID& rpv){fprintf_s(mFile,"connectAttr \"");rpv.write(mFile);fprintf_s(mFile,"\" \"%s.rpv\";\n",mName.c_str());}
	/*Controls how much a mesh is attracted to its current state.*/
	void setDeformResistance(float dety){if(dety == 0.0) return; fprintf_s(mFile, "setAttr \".dety\" %f;\n", dety);}
	/*Controls how much a mesh is attracted to its current state.*/
	void setDeformResistance(const FloatID& dety){fprintf_s(mFile,"connectAttr \"");dety.write(mFile);fprintf_s(mFile,"\" \"%s.dety\";\n",mName.c_str());}
	/*Deformability map for cloth/object*/
	void setDeformMap(float demp){if(demp == 0.0) return; fprintf_s(mFile, "setAttr \".demp\" %f;\n", demp);}
	/*Deformability map for cloth/object*/
	void setDeformMap(const FloatID& demp){fprintf_s(mFile,"connectAttr \"");demp.write(mFile);fprintf_s(mFile,"\" \"%s.demp\";\n",mName.c_str());}
	/*Per-vertex deformability for cloth/object*/
	void setDeformPerVertex(const doubleArray& dfpv){if(dfpv.size == 0) return; fprintf_s(mFile, "setAttr \".dfpv\" -type \"doubleArray\" ");dfpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex deformability for cloth/object*/
	void setDeformPerVertex(const DoubleArrayID& dfpv){fprintf_s(mFile,"connectAttr \"");dfpv.write(mFile);fprintf_s(mFile,"\" \"%s.dfpv\";\n",mName.c_str());}
	/*Defines how attacted the cloth is to the current position of the input mesh.*/
	void setInputMeshAttract(float imat){if(imat == 0.0) return; fprintf_s(mFile, "setAttr \".imat\" %f;\n", imat);}
	/*Defines how attacted the cloth is to the current position of the input mesh.*/
	void setInputMeshAttract(const FloatID& imat){fprintf_s(mFile,"connectAttr \"");imat.write(mFile);fprintf_s(mFile,"\" \"%s.imat\";\n",mName.c_str());}
	/*Input Mesh Attract map for cloth/object*/
	void setInputAttractMap(float iamp){if(iamp == 0.0) return; fprintf_s(mFile, "setAttr \".iamp\" %f;\n", iamp);}
	/*Input Mesh Attract map for cloth/object*/
	void setInputAttractMap(const FloatID& iamp){fprintf_s(mFile,"connectAttr \"");iamp.write(mFile);fprintf_s(mFile,"\" \"%s.iamp\";\n",mName.c_str());}
	/*Per-vertex input mesh attract for cloth/object*/
	void setInputAttractPerVertex(const doubleArray& iapv){if(iapv.size == 0) return; fprintf_s(mFile, "setAttr \".iapv\" -type \"doubleArray\" ");iapv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex input mesh attract for cloth/object*/
	void setInputAttractPerVertex(const DoubleArrayID& iapv){fprintf_s(mFile,"connectAttr \"");iapv.write(mFile);fprintf_s(mFile,"\" \"%s.iapv\";\n",mName.c_str());}
	/*
	Defines how springy the effect of Input Mesh Attract is. At a value of zero
	input mesh attract will behave like a spring connection from the input mesh to
	the output dynamic mesh. The cloth will tend to wiggle about the input mesh position.
	As the Input Attract Damp is increased to 1 the cloth mesh will still move to the input mesh position
	but not have the momentum to travel past it, so will no longer occillate about the input position.
	*/
	void setInputAttractDamp(float iadm){if(iadm == 0.5) return; fprintf_s(mFile, "setAttr \".iadm\" %f;\n", iadm);}
	/*
	Defines how springy the effect of Input Mesh Attract is. At a value of zero
	input mesh attract will behave like a spring connection from the input mesh to
	the output dynamic mesh. The cloth will tend to wiggle about the input mesh position.
	As the Input Attract Damp is increased to 1 the cloth mesh will still move to the input mesh position
	but not have the momentum to travel past it, so will no longer occillate about the input position.
	*/
	void setInputAttractDamp(const FloatID& iadm){fprintf_s(mFile,"connectAttr \"");iadm.write(mFile);fprintf_s(mFile,"\" \"%s.iadm\";\n",mName.c_str());}
	/*displacement style mapping that affects rest shape*/
	void setWrinkleMap(float wkmp){if(wkmp == 0.0) return; fprintf_s(mFile, "setAttr \".wkmp\" %f;\n", wkmp);}
	/*displacement style mapping that affects rest shape*/
	void setWrinkleMap(const FloatID& wkmp){fprintf_s(mFile,"connectAttr \"");wkmp.write(mFile);fprintf_s(mFile,"\" \"%s.wkmp\";\n",mName.c_str());}
	/*Per-vertex wrinkle for cloth/object*/
	void setWrinklePerVertex(const doubleArray& wpv){if(wpv.size == 0) return; fprintf_s(mFile, "setAttr \".wpv\" -type \"doubleArray\" ");wpv.write(mFile);fprintf_s(mFile,";\n");}
	/*Per-vertex wrinkle for cloth/object*/
	void setWrinklePerVertex(const DoubleArrayID& wpv){fprintf_s(mFile,"connectAttr \"");wpv.write(mFile);fprintf_s(mFile,"\" \"%s.wpv\";\n",mName.c_str());}
	/*
	Defines the amount of wrinkle map displacement. Negative values push wrinkles in instead of out.
	The value may need to be large if the scene scale is large.
	*/
	void setWrinkleMapScale(float wms){if(wms == 1.0) return; fprintf_s(mFile, "setAttr \".wms\" %f;\n", wms);}
	/*
	Defines the amount of wrinkle map displacement. Negative values push wrinkles in instead of out.
	The value may need to be large if the scene scale is large.
	*/
	void setWrinkleMapScale(const FloatID& wms){fprintf_s(mFile,"connectAttr \"");wms.write(mFile);fprintf_s(mFile,"\" \"%s.wms\";\n",mName.c_str());}
	/*Defines the amount by which the rest state of the bend angle is scaled.*/
	void setBendAngleScale(float basc){if(basc == 1.0) return; fprintf_s(mFile, "setAttr \".basc\" %f;\n", basc);}
	/*Defines the amount by which the rest state of the bend angle is scaled.*/
	void setBendAngleScale(const FloatID& basc){fprintf_s(mFile,"connectAttr \"");basc.write(mFile);fprintf_s(mFile,"\" \"%s.basc\";\n",mName.c_str());}
	/*
	Turn on sorting of links. With a sequential evaluation order this
	bases the link order on distance to colliding and constrainted points,
	which can help reduce stretching without requiring high stretchResistance values.
	*/
	void setSortLinks(bool stlk){if(stlk == 0) return; fprintf_s(mFile, "setAttr \".stlk\" %i;\n", stlk);}
	/*
	Turn on sorting of links. With a sequential evaluation order this
	bases the link order on distance to colliding and constrainted points,
	which can help reduce stretching without requiring high stretchResistance values.
	*/
	void setSortLinks(const BoolID& stlk){fprintf_s(mFile,"connectAttr \"");stlk.write(mFile);fprintf_s(mFile,"\" \"%s.stlk\";\n",mName.c_str());}
	/*
	This determines whether links are evaluated in a cumulative or an
	order independant fashion. The sequential mode has a bias based on
	the order the links are processed. By default this order will be the
	edge order on the input mesh. The sequential evaluation converges on
	a solution much faster than the parallel form, which means that it requires
	less computation to make cloth non-stretchy, or rigid. If one uses the
	parallel method then bend and stretch resistance values will need to be
	proportionately higher and simulation times will generally be longer.
	However there will be less bias in the stretching. Also the parallel method
	may multithread better, somewhat offsetting the computational overhead.
	The sequential method can be improved in some cases by using the sortLinks
	attribute, which changes the evaluation order to process links near colliding
	points and constraints first. This can result in lower required stretch values.
	*/
	void setEvaluationOrder(unsigned int evo){if(evo == 0) return; fprintf_s(mFile, "setAttr \".evo\" %i;\n", evo);}
	/*
	This determines whether links are evaluated in a cumulative or an
	order independant fashion. The sequential mode has a bias based on
	the order the links are processed. By default this order will be the
	edge order on the input mesh. The sequential evaluation converges on
	a solution much faster than the parallel form, which means that it requires
	less computation to make cloth non-stretchy, or rigid. If one uses the
	parallel method then bend and stretch resistance values will need to be
	proportionately higher and simulation times will generally be longer.
	However there will be less bias in the stretching. Also the parallel method
	may multithread better, somewhat offsetting the computational overhead.
	The sequential method can be improved in some cases by using the sortLinks
	attribute, which changes the evaluation order to process links near colliding
	points and constraints first. This can result in lower required stretch values.
	*/
	void setEvaluationOrder(const UnsignedintID& evo){fprintf_s(mFile,"connectAttr \"");evo.write(mFile);fprintf_s(mFile,"\" \"%s.evo\";\n",mName.c_str());}
	/*
	For faces with more than 3 vertices this will create additional stretch and bends links such that
	each vertex is connected to each other vertex. If this is off then the links will exactly match
	the meshes list of edges. For a quad meshes having addCrossLinks off would allow the cloth to shear, unless
	the shear resistance attribute was used.
	*/
	void setAddCrossLinks(bool aclk){if(aclk == true) return; fprintf_s(mFile, "setAttr \".aclk\" %i;\n", aclk);}
	/*
	For faces with more than 3 vertices this will create additional stretch and bends links such that
	each vertex is connected to each other vertex. If this is off then the links will exactly match
	the meshes list of edges. For a quad meshes having addCrossLinks off would allow the cloth to shear, unless
	the shear resistance attribute was used.
	*/
	void setAddCrossLinks(const BoolID& aclk){fprintf_s(mFile,"connectAttr \"");aclk.write(mFile);fprintf_s(mFile,"\" \"%s.aclk\";\n",mName.c_str());}
	/*
	Defines how much the velocity due to stretch along the internal connections will be damped.
	Increasing this value will allow the cloth to stretch without bouncing.
	*/
	void setStretchDamp(float sdmp){if(sdmp == 0.1) return; fprintf_s(mFile, "setAttr \".sdmp\" %f;\n", sdmp);}
	/*
	Defines how much the velocity due to stretch along the internal connections will be damped.
	Increasing this value will allow the cloth to stretch without bouncing.
	*/
	void setStretchDamp(const FloatID& sdmp){fprintf_s(mFile,"connectAttr \"");sdmp.write(mFile);fprintf_s(mFile,"\" \"%s.sdmp\";\n",mName.c_str());}
	/*Use the new stretch solve to compute the stretch in one go*/
	void setMinimalStretch(const BoolID& msso){fprintf_s(mFile,"connectAttr \"");msso.write(mFile);fprintf_s(mFile,"\" \"%s.msso\";\n",mName.c_str());}
	/*Use the new stretch solve to compute the stretch in one go*/
	void setMinimalBend(const BoolID& mbso){fprintf_s(mFile,"connectAttr \"");mbso.write(mFile);fprintf_s(mFile,"\" \"%s.mbso\";\n",mName.c_str());}
	/*Use the new stretch solve to compute the stretch in one go*/
	void setMinimalShear(const BoolID& mshs){fprintf_s(mFile,"connectAttr \"");mshs.write(mFile);fprintf_s(mFile,"\" \"%s.mshs\";\n",mName.c_str());}
	/*Number of levels for hierarchical stretch solve*/
	void setStretchHierarchyLevels(const IntID& shlv){fprintf_s(mFile,"connectAttr \"");shlv.write(mFile);fprintf_s(mFile,"\" \"%s.shlv\";\n",mName.c_str());}
	/*How much we reduce for each level of the hierarchical stretch solve*/
	void setStretchHierarchyPercent(const FloatID& shpe){fprintf_s(mFile,"connectAttr \"");shpe.write(mFile);fprintf_s(mFile,"\" \"%s.shpe\";\n",mName.c_str());}
	/*
	Allows the thickness of each input/output mesh to be scaled for self collision.
	This value is defined relative to the CollisionWidth, so if SelfCollideWidthScale is 1.0
	then the width for self collision will be the same as the collision width. If it is 2.0 then
	it will be twice the collision width. It can often be useful to the make the self collision width
	greater than that for collision with other objects, especially when using vertex self collisions.
	*/
	void setSelfCollideWidthScale(float scws){if(scws == 1.0) return; fprintf_s(mFile, "setAttr \".scws\" %f;\n", scws);}
	/*
	Allows the thickness of each input/output mesh to be scaled for self collision.
	This value is defined relative to the CollisionWidth, so if SelfCollideWidthScale is 1.0
	then the width for self collision will be the same as the collision width. If it is 2.0 then
	it will be twice the collision width. It can often be useful to the make the self collision width
	greater than that for collision with other objects, especially when using vertex self collisions.
	*/
	void setSelfCollideWidthScale(const FloatID& scws){fprintf_s(mFile,"connectAttr \"");scws.write(mFile);fprintf_s(mFile,"\" \"%s.scws\";\n",mName.c_str());}
	/*obsolete*/
	void setSelfCollisionSoftness(float scsf){if(scsf == 0.0) return; fprintf_s(mFile, "setAttr \".scsf\" %f;\n", scsf);}
	/*obsolete*/
	void setSelfCollisionSoftness(const FloatID& scsf){fprintf_s(mFile,"connectAttr \"");scsf.write(mFile);fprintf_s(mFile,"\" \"%s.scsf\";\n",mName.c_str());}
	/*
	This is a force applied along the contour where this object crosses its self.
	Because it only works at the point of crossover it may take several steps
	for the surface to pop out into a good state. If self collisions are enabled then one
	may wish to combine this with the selfTrappedCheck toggle because that will disable
	collisions for crossed over faces.
	It can also be used to clean up interpenetration at the start frame, although the collisions
	should be disabled when doing so. Lower values will
	take longer to resolve the self collision, but can create smoother results.
	*/
	void setSelfCrossoverPush(float scpu){if(scpu == 0.0) return; fprintf_s(mFile, "setAttr \".scpu\" %f;\n", scpu);}
	/*
	This is a force applied along the contour where this object crosses its self.
	Because it only works at the point of crossover it may take several steps
	for the surface to pop out into a good state. If self collisions are enabled then one
	may wish to combine this with the selfTrappedCheck toggle because that will disable
	collisions for crossed over faces.
	It can also be used to clean up interpenetration at the start frame, although the collisions
	should be disabled when doing so. Lower values will
	take longer to resolve the self collision, but can create smoother results.
	*/
	void setSelfCrossoverPush(const FloatID& scpu){fprintf_s(mFile,"connectAttr \"");scpu.write(mFile);fprintf_s(mFile,"\" \"%s.scpu\";\n",mName.c_str());}
	/*
	This tracks self collision crossovers and attempts to push the crossed over points
	back. It assumes that the surface is in a good state at the start and attempts to
	preserve that relative state. It is useful in cases where cloth can get caught
	between passive objects than interpenetrate (for example an elbow passing through a
	chest). Rather than get stuck on the wrong side this allows the cloth to push back
	to the correct side when the passive objects later separate.
	*/
	void setSelfTrappedCheck(bool stpc){if(stpc == 0) return; fprintf_s(mFile, "setAttr \".stpc\" %i;\n", stpc);}
	/*
	This tracks self collision crossovers and attempts to push the crossed over points
	back. It assumes that the surface is in a good state at the start and attempts to
	preserve that relative state. It is useful in cases where cloth can get caught
	between passive objects than interpenetrate (for example an elbow passing through a
	chest). Rather than get stuck on the wrong side this allows the cloth to push back
	to the correct side when the passive objects later separate.
	*/
	void setSelfTrappedCheck(const BoolID& stpc){fprintf_s(mFile,"connectAttr \"");stpc.write(mFile);fprintf_s(mFile,"\" \"%s.stpc\";\n",mName.c_str());}
	/*
	The manual setting defines pressure as a simple user input value that can be keyframed.
	The volume tracking model computes the pressure based on the current volume of the cloth
	combined with inflow and outflow of air. Note that higher iterations on the air model will result
	in more incompressibility of the internal air.
	*/
	void setPressureMethod(unsigned int pmth){if(pmth == 0) return; fprintf_s(mFile, "setAttr \".pmth\" %i;\n", pmth);}
	/*
	The manual setting defines pressure as a simple user input value that can be keyframed.
	The volume tracking model computes the pressure based on the current volume of the cloth
	combined with inflow and outflow of air. Note that higher iterations on the air model will result
	in more incompressibility of the internal air.
	*/
	void setPressureMethod(const UnsignedintID& pmth){fprintf_s(mFile,"connectAttr \"");pmth.write(mFile);fprintf_s(mFile,"\" \"%s.pmth\";\n",mName.c_str());}
	/*
	This defines a force applied along the surface normal direction
	when the Pressure Method is set to Manual.
	*/
	void setPressure(float pres){if(pres == 0.0) return; fprintf_s(mFile, "setAttr \".pres\" %f;\n", pres);}
	/*
	This defines a force applied along the surface normal direction
	when the Pressure Method is set to Manual.
	*/
	void setPressure(const FloatID& pres){fprintf_s(mFile,"connectAttr \"");pres.write(mFile);fprintf_s(mFile,"\" \"%s.pres\";\n",mName.c_str());}
	/*
	With the volume tracking pressure method this defines the relative air pressure
	inside the object at the startframe.
	*/
	void setStartPressure(float stpe){if(stpe == 0.0) return; fprintf_s(mFile, "setAttr \".stpe\" %f;\n", stpe);}
	/*
	With the volume tracking pressure method this defines the relative air pressure
	inside the object at the startframe.
	*/
	void setStartPressure(const FloatID& stpe){fprintf_s(mFile,"connectAttr \"");stpe.write(mFile);fprintf_s(mFile,"\" \"%s.stpe\";\n",mName.c_str());}
	/*
	When the volume tracking pressure model is used this defines how incompressible the internal volume
	of fluid is. This also will affect how much force is applied to the cloth when air is pumped in.
	In the case of a balloon higher values of incompressibility will overcome higher stretch resistance.
	Note that higher incompressibility may require more calculation time.
	*/
	void setIncompressibility(float incm){if(incm == 5.0) return; fprintf_s(mFile, "setAttr \".incm\" %f;\n", incm);}
	/*
	When the volume tracking pressure model is used this defines how incompressible the internal volume
	of fluid is. This also will affect how much force is applied to the cloth when air is pumped in.
	In the case of a balloon higher values of incompressibility will overcome higher stretch resistance.
	Note that higher incompressibility may require more calculation time.
	*/
	void setIncompressibility(const FloatID& incm){fprintf_s(mFile,"connectAttr \"");incm.write(mFile);fprintf_s(mFile,"\" \"%s.incm\";\n",mName.c_str());}
	/*Defines the air pressure damping*/
	void setPressureDamping(float prdg){if(prdg == 0.0) return; fprintf_s(mFile, "setAttr \".prdg\" %f;\n", prdg);}
	/*Defines the air pressure damping*/
	void setPressureDamping(const FloatID& prdg){fprintf_s(mFile,"connectAttr \"");prdg.write(mFile);fprintf_s(mFile,"\" \"%s.prdg\";\n",mName.c_str());}
	/*Defines the rate at which air pressure is added to the object*/
	void setPumpRate(float pure){if(pure == 0.0) return; fprintf_s(mFile, "setAttr \".pure\" %f;\n", pure);}
	/*Defines the rate at which air pressure is added to the object*/
	void setPumpRate(const FloatID& pure){fprintf_s(mFile,"connectAttr \"");pure.write(mFile);fprintf_s(mFile,"\" \"%s.pure\";\n",mName.c_str());}
	/*
	Defines the rate at which air can escape from the object, or how permiable the
	surface is. This is in addition to any physical holes in the model, which can be
	be capped or not using the seal holes attributes.
	*/
	void setAirTightness(float aits){if(aits == 1.0) return; fprintf_s(mFile, "setAttr \".aits\" %f;\n", aits);}
	/*
	Defines the rate at which air can escape from the object, or how permiable the
	surface is. This is in addition to any physical holes in the model, which can be
	be capped or not using the seal holes attributes.
	*/
	void setAirTightness(const FloatID& aits){fprintf_s(mFile,"connectAttr \"");aits.write(mFile);fprintf_s(mFile,"\" \"%s.aits\";\n",mName.c_str());}
	/*
	When the volume tracking pressure method is used this determines if physical holes in
	the cloth model are treated as being capped or not. If holes are not sealed, then air
	can escape out them, which also has the effect of pushing the cloth. For example, this can simulate
	a rubber balloon that is suddenly released. It also allows for inflow based on motion of the
	cloth. The opening in a parachute will allow air to flow in as it falls down, causing sideways
	pressure that inflates it. Note that drag alone cannot achieve this sort of effect.
	*/
	void setSealHoles(bool shol){if(shol == true) return; fprintf_s(mFile, "setAttr \".shol\" %i;\n", shol);}
	/*
	When the volume tracking pressure method is used this determines if physical holes in
	the cloth model are treated as being capped or not. If holes are not sealed, then air
	can escape out them, which also has the effect of pushing the cloth. For example, this can simulate
	a rubber balloon that is suddenly released. It also allows for inflow based on motion of the
	cloth. The opening in a parachute will allow air to flow in as it falls down, causing sideways
	pressure that inflates it. Note that drag alone cannot achieve this sort of effect.
	*/
	void setSealHoles(const BoolID& shol){fprintf_s(mFile,"connectAttr \"");shol.write(mFile);fprintf_s(mFile,"\" \"%s.shol\";\n",mName.c_str());}
	/*Turn off the effect of the gravity that is defined on the solver node.*/
	void setIgnoreSolverGravity(bool igsg){if(igsg == 0) return; fprintf_s(mFile, "setAttr \".igsg\" %i;\n", igsg);}
	/*Turn off the effect of the gravity that is defined on the solver node.*/
	void setIgnoreSolverGravity(const BoolID& igsg){fprintf_s(mFile,"connectAttr \"");igsg.write(mFile);fprintf_s(mFile,"\" \"%s.igsg\";\n",mName.c_str());}
	/*Turn off the effect of the wind that is defined on the solver node.*/
	void setIgnoreSolverWind(bool igsw){if(igsw == 0) return; fprintf_s(mFile, "setAttr \".igsw\" %i;\n", igsw);}
	/*Turn off the effect of the wind that is defined on the solver node.*/
	void setIgnoreSolverWind(const BoolID& igsw){fprintf_s(mFile,"connectAttr \"");igsw.write(mFile);fprintf_s(mFile,"\" \"%s.igsw\";\n",mName.c_str());}
	/*Allow the object to shadow parts of itself from the wind.*/
	void setWindSelfShadow(bool wssh){if(wssh == 0) return; fprintf_s(mFile, "setAttr \".wssh\" %i;\n", wssh);}
	/*Allow the object to shadow parts of itself from the wind.*/
	void setWindSelfShadow(const BoolID& wssh){fprintf_s(mFile,"connectAttr \"");wssh.write(mFile);fprintf_s(mFile,"\" \"%s.wssh\";\n",mName.c_str());}
	/*Defines the lift affecting this nParticle system*/
	void setLift(float lft){if(lft == 0.05) return; fprintf_s(mFile, "setAttr \".lft\" %f;\n", lft);}
	/*Defines the lift affecting this nParticle system*/
	void setLift(const FloatID& lft){fprintf_s(mFile,"connectAttr \"");lft.write(mFile);fprintf_s(mFile,"\" \"%s.lft\";\n",mName.c_str());}
	/*Defines the drag affecting this nParticle system*/
	void setDrag(float drg){if(drg == 0.05) return; fprintf_s(mFile, "setAttr \".drg\" %f;\n", drg);}
	/*Defines the drag affecting this nParticle system*/
	void setDrag(const FloatID& drg){fprintf_s(mFile,"connectAttr \"");drg.write(mFile);fprintf_s(mFile,"\" \"%s.drg\";\n",mName.c_str());}
	/*
	Defines the component of drag tangent to the surface. With a value of zero a flat
	plane will slice through air with no resistance and only have drag when moving along
	its normal axis. With a value of 1.0 the effect of drag will be equal in all directions.
	*/
	void setTangentialDrag(float tdrg){if(tdrg == 0.0) return; fprintf_s(mFile, "setAttr \".tdrg\" %f;\n", tdrg);}
	/*
	Defines the component of drag tangent to the surface. With a value of zero a flat
	plane will slice through air with no resistance and only have drag when moving along
	its normal axis. With a value of 1.0 the effect of drag will be equal in all directions.
	*/
	void setTangentialDrag(const FloatID& tdrg){fprintf_s(mFile,"connectAttr \"");tdrg.write(mFile);fprintf_s(mFile,"\" \"%s.tdrg\";\n",mName.c_str());}
	/*Interactive display of internal solver info.*/
	void setSolverDisplay(unsigned int svds){if(svds == 0) return; fprintf_s(mFile, "setAttr \".svds\" %i;\n", svds);}
	/*Interactive display of internal solver info.*/
	void setSolverDisplay(const UnsignedintID& svds){fprintf_s(mFile,"connectAttr \"");svds.write(mFile);fprintf_s(mFile,"\" \"%s.svds\";\n",mName.c_str());}
	/*What type of stretch map to use: per-vertex, texture or none.*/
	void setStretchMapType(unsigned int smt){if(smt == 2) return; fprintf_s(mFile, "setAttr \".smt\" %i;\n", smt);}
	/*What type of stretch map to use: per-vertex, texture or none.*/
	void setStretchMapType(const UnsignedintID& smt){fprintf_s(mFile,"connectAttr \"");smt.write(mFile);fprintf_s(mFile,"\" \"%s.smt\";\n",mName.c_str());}
	/*What type of bend map to use: per-vertex, texture or none.*/
	void setBendMapType(unsigned int bdmt){if(bdmt == 2) return; fprintf_s(mFile, "setAttr \".bdmt\" %i;\n", bdmt);}
	/*What type of bend map to use: per-vertex, texture or none.*/
	void setBendMapType(const UnsignedintID& bdmt){fprintf_s(mFile,"connectAttr \"");bdmt.write(mFile);fprintf_s(mFile,"\" \"%s.bdmt\";\n",mName.c_str());}
	/*What type of rigidity map to use: per-vertex, texture or none.*/
	void setRigidityMapType(unsigned int rmt){if(rmt == 2) return; fprintf_s(mFile, "setAttr \".rmt\" %i;\n", rmt);}
	/*What type of rigidity map to use: per-vertex, texture or none.*/
	void setRigidityMapType(const UnsignedintID& rmt){fprintf_s(mFile,"connectAttr \"");rmt.write(mFile);fprintf_s(mFile,"\" \"%s.rmt\";\n",mName.c_str());}
	/*What type of deform map to use: per-vertex, texture or none.*/
	void setDeformMapType(unsigned int dmmt){if(dmmt == 2) return; fprintf_s(mFile, "setAttr \".dmmt\" %i;\n", dmmt);}
	/*What type of deform map to use: per-vertex, texture or none.*/
	void setDeformMapType(const UnsignedintID& dmmt){fprintf_s(mFile,"connectAttr \"");dmmt.write(mFile);fprintf_s(mFile,"\" \"%s.dmmt\";\n",mName.c_str());}
	/*What type of inputAttract map to use: per-vertex, texture or none.*/
	void setInputAttractMapType(unsigned int iamt){if(iamt == 2) return; fprintf_s(mFile, "setAttr \".iamt\" %i;\n", iamt);}
	/*What type of inputAttract map to use: per-vertex, texture or none.*/
	void setInputAttractMapType(const UnsignedintID& iamt){fprintf_s(mFile,"connectAttr \"");iamt.write(mFile);fprintf_s(mFile,"\" \"%s.iamt\";\n",mName.c_str());}
	/*What type of wrinkle map to use: per-vertex, texture or none.*/
	void setWrinkleMapType(unsigned int wmt){if(wmt == 2) return; fprintf_s(mFile, "setAttr \".wmt\" %i;\n", wmt);}
	/*What type of wrinkle map to use: per-vertex, texture or none.*/
	void setWrinkleMapType(const UnsignedintID& wmt){fprintf_s(mFile,"connectAttr \"");wmt.write(mFile);fprintf_s(mFile,"\" \"%s.wmt\";\n",mName.c_str());}
	/*Output Geometry for soft body.*/
	GenericID getOutputMesh(){char buffer[4096];sprintf_s (buffer, "%s.omsh",mName.c_str());return (const char*)buffer;}
	/*
	RestPosition Geometr(y/ies). This is the shape that the cloth
	tries to achieves. It may be animated over time, but should have the
	exact same topology as the inputMesh.
	*/
	GenericID getRestShapeMesh(){char buffer[4096];sprintf_s (buffer, "%s.rsmh",mName.c_str());return (const char*)buffer;}
	/*Number of subdivisions for each input/output mesh pairing.*/
	IntID getNumSubdivisions(){char buffer[4096];sprintf_s (buffer, "%s.nsub",mName.c_str());return (const char*)buffer;}
	/*
	This defines the way dynamic attributes such as bend, stretch and tension are defined relative to
	object scale and cv density.
	If Link is specified then stretch and bend are fixed values applied at each link. Thus if a mesh has more
	cvs it will appear to be more stretchy and bendable, even thought the amount of stretch and bend is the same
	on a per link basis.
	With Object Space the mesh will bend and stretch the same amount regardless of the resolution of the mesh. Note
	that this can result in significantly greater compute times for the high resolution mesh, as the individual links
	need to be stiffer, which requires more calculation( on top of having more links to compute ).
	World Space is similar to ObjectSpace, except that the stiffness of the mesh is now fixed in worldspace. Thus scaling
	a mesh up will make it appear to be a larger sheet made of the same material, which appears proportionately less stiff.
	For example a small piece of paper may bend little under gravity, but a large sheet would flop.
	*/
	UnsignedintID getScalingRelation(){char buffer[4096];sprintf_s (buffer, "%s.srl",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount that the material will resist stretching when under tension.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined. Also one may need to additionally make the both collision iterations on the solver
	and constraint strength values high to keep stretching low.
	*/
	FloatID getStretchResistance(){char buffer[4096];sprintf_s (buffer, "%s.stch",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount that the material will resist compression. Note that sometimes it is useful to have
	this value be lower than the Stretch Resistance, because the mesh resolution is only an approximation
	to a true surface, which could possibly fold within the length of a triangle. If one has a rest
	position for a cloth that is not flat and the compression and stretch resistance are both high then
	this can make cloth appear too stiff because the topology locks up. This problem is most noticable when
	the faces have relatively high angles relative to each other. Having a low compression resistance allows
	the material keep from locking up, yet still not appear to stretchy.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined. Also stretch mapping scales both compression and stretch.
	*/
	FloatID getCompressionResistance(){char buffer[4096];sprintf_s (buffer, "%s.comr",mName.c_str());return (const char*)buffer;}
	/*Stretch map for cloth/object*/
	FloatID getStretchMap(){char buffer[4096];sprintf_s (buffer, "%s.stmp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex stretch for cloth/object*/
	DoubleArrayID getStretchPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.spv",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount that the material will resist bending when under strain.
	Large values generally require more computation, so they may result in longer
	simulation times. Note that the scalingRelation attribute affects how this
	value is defined.
	*/
	FloatID getBendResistance(){char buffer[4096];sprintf_s (buffer, "%s.bnd",mName.c_str());return (const char*)buffer;}
	/*Bend map for cloth/object*/
	FloatID getBendMap(){char buffer[4096];sprintf_s (buffer, "%s.bemp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex bend for cloth/object*/
	DoubleArrayID getBendPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.bdpv",mName.c_str());return (const char*)buffer;}
	/*
	Defines the way bend resistance changes with the angle.
	At higher values the bend will resist more at high angles
	then when the surface is nearly flat.
	*/
	FloatID getBendAngleDropoff(){char buffer[4096];sprintf_s (buffer, "%s.bnad",mName.c_str());return (const char*)buffer;}
	/*
	How far can the links be stretched before they fail
	to go back to their rest length when there are no
	forces acting on the cloth. When the tension is greater than the
	defined value the defined rest length will increase until the tension is equal this value.
	For very low values the material will pull apart like taffy, yet still resist stretching under
	mild forces.
	*/
	FloatID getRestitutionTension(){char buffer[4096];sprintf_s (buffer, "%s.retn",mName.c_str());return (const char*)buffer;}
	/*
	Defines how far we can bend across an edge before it will fail
	to go back to the rest angle when there are no
	forces acting on the cloth.
	*/
	FloatID getRestitutionAngle(){char buffer[4096];sprintf_s (buffer, "%s.reae",mName.c_str());return (const char*)buffer;}
	/*
	Defines the shear resistance for each input/output mesh.
	Shear can be thought of as the bend in the plane
	of the cloth.
	*/
	FloatID getShearResistance(){char buffer[4096];sprintf_s (buffer, "%s.shr",mName.c_str());return (const char*)buffer;}
	/*Defines how inclined the mesh is to be a rigid body*/
	FloatID getRigidity(){char buffer[4096];sprintf_s (buffer, "%s.rity",mName.c_str());return (const char*)buffer;}
	/*Rigidity map for cloth/object*/
	FloatID getRigidityMap(){char buffer[4096];sprintf_s (buffer, "%s.rimp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex rigidity for cloth/object*/
	DoubleArrayID getRigidityPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.rpv",mName.c_str());return (const char*)buffer;}
	/*Controls how much a mesh is attracted to its current state.*/
	FloatID getDeformResistance(){char buffer[4096];sprintf_s (buffer, "%s.dety",mName.c_str());return (const char*)buffer;}
	/*Deformability map for cloth/object*/
	FloatID getDeformMap(){char buffer[4096];sprintf_s (buffer, "%s.demp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex deformability for cloth/object*/
	DoubleArrayID getDeformPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.dfpv",mName.c_str());return (const char*)buffer;}
	/*Defines how attacted the cloth is to the current position of the input mesh.*/
	FloatID getInputMeshAttract(){char buffer[4096];sprintf_s (buffer, "%s.imat",mName.c_str());return (const char*)buffer;}
	/*Input Mesh Attract map for cloth/object*/
	FloatID getInputAttractMap(){char buffer[4096];sprintf_s (buffer, "%s.iamp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex input mesh attract for cloth/object*/
	DoubleArrayID getInputAttractPerVertex(){char buffer[4096];sprintf_s (buffer, "%s.iapv",mName.c_str());return (const char*)buffer;}
	/*
	Defines how springy the effect of Input Mesh Attract is. At a value of zero
	input mesh attract will behave like a spring connection from the input mesh to
	the output dynamic mesh. The cloth will tend to wiggle about the input mesh position.
	As the Input Attract Damp is increased to 1 the cloth mesh will still move to the input mesh position
	but not have the momentum to travel past it, so will no longer occillate about the input position.
	*/
	FloatID getInputAttractDamp(){char buffer[4096];sprintf_s (buffer, "%s.iadm",mName.c_str());return (const char*)buffer;}
	/*displacement style mapping that affects rest shape*/
	FloatID getWrinkleMap(){char buffer[4096];sprintf_s (buffer, "%s.wkmp",mName.c_str());return (const char*)buffer;}
	/*Per-vertex wrinkle for cloth/object*/
	DoubleArrayID getWrinklePerVertex(){char buffer[4096];sprintf_s (buffer, "%s.wpv",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount of wrinkle map displacement. Negative values push wrinkles in instead of out.
	The value may need to be large if the scene scale is large.
	*/
	FloatID getWrinkleMapScale(){char buffer[4096];sprintf_s (buffer, "%s.wms",mName.c_str());return (const char*)buffer;}
	/*Defines the amount by which the rest state of the bend angle is scaled.*/
	FloatID getBendAngleScale(){char buffer[4096];sprintf_s (buffer, "%s.basc",mName.c_str());return (const char*)buffer;}
	/*
	Turn on sorting of links. With a sequential evaluation order this
	bases the link order on distance to colliding and constrainted points,
	which can help reduce stretching without requiring high stretchResistance values.
	*/
	BoolID getSortLinks(){char buffer[4096];sprintf_s (buffer, "%s.stlk",mName.c_str());return (const char*)buffer;}
	/*
	This determines whether links are evaluated in a cumulative or an
	order independant fashion. The sequential mode has a bias based on
	the order the links are processed. By default this order will be the
	edge order on the input mesh. The sequential evaluation converges on
	a solution much faster than the parallel form, which means that it requires
	less computation to make cloth non-stretchy, or rigid. If one uses the
	parallel method then bend and stretch resistance values will need to be
	proportionately higher and simulation times will generally be longer.
	However there will be less bias in the stretching. Also the parallel method
	may multithread better, somewhat offsetting the computational overhead.
	The sequential method can be improved in some cases by using the sortLinks
	attribute, which changes the evaluation order to process links near colliding
	points and constraints first. This can result in lower required stretch values.
	*/
	UnsignedintID getEvaluationOrder(){char buffer[4096];sprintf_s (buffer, "%s.evo",mName.c_str());return (const char*)buffer;}
	/*
	For faces with more than 3 vertices this will create additional stretch and bends links such that
	each vertex is connected to each other vertex. If this is off then the links will exactly match
	the meshes list of edges. For a quad meshes having addCrossLinks off would allow the cloth to shear, unless
	the shear resistance attribute was used.
	*/
	BoolID getAddCrossLinks(){char buffer[4096];sprintf_s (buffer, "%s.aclk",mName.c_str());return (const char*)buffer;}
	/*
	Defines how much the velocity due to stretch along the internal connections will be damped.
	Increasing this value will allow the cloth to stretch without bouncing.
	*/
	FloatID getStretchDamp(){char buffer[4096];sprintf_s (buffer, "%s.sdmp",mName.c_str());return (const char*)buffer;}
	/*Use the new stretch solve to compute the stretch in one go*/
	BoolID getMinimalStretch(){char buffer[4096];sprintf_s (buffer, "%s.msso",mName.c_str());return (const char*)buffer;}
	/*Use the new stretch solve to compute the stretch in one go*/
	BoolID getMinimalBend(){char buffer[4096];sprintf_s (buffer, "%s.mbso",mName.c_str());return (const char*)buffer;}
	/*Use the new stretch solve to compute the stretch in one go*/
	BoolID getMinimalShear(){char buffer[4096];sprintf_s (buffer, "%s.mshs",mName.c_str());return (const char*)buffer;}
	/*Number of levels for hierarchical stretch solve*/
	IntID getStretchHierarchyLevels(){char buffer[4096];sprintf_s (buffer, "%s.shlv",mName.c_str());return (const char*)buffer;}
	/*How much we reduce for each level of the hierarchical stretch solve*/
	FloatID getStretchHierarchyPercent(){char buffer[4096];sprintf_s (buffer, "%s.shpe",mName.c_str());return (const char*)buffer;}
	/*
	Allows the thickness of each input/output mesh to be scaled for self collision.
	This value is defined relative to the CollisionWidth, so if SelfCollideWidthScale is 1.0
	then the width for self collision will be the same as the collision width. If it is 2.0 then
	it will be twice the collision width. It can often be useful to the make the self collision width
	greater than that for collision with other objects, especially when using vertex self collisions.
	*/
	FloatID getSelfCollideWidthScale(){char buffer[4096];sprintf_s (buffer, "%s.scws",mName.c_str());return (const char*)buffer;}
	/*obsolete*/
	FloatID getSelfCollisionSoftness(){char buffer[4096];sprintf_s (buffer, "%s.scsf",mName.c_str());return (const char*)buffer;}
	/*
	This is a force applied along the contour where this object crosses its self.
	Because it only works at the point of crossover it may take several steps
	for the surface to pop out into a good state. If self collisions are enabled then one
	may wish to combine this with the selfTrappedCheck toggle because that will disable
	collisions for crossed over faces.
	It can also be used to clean up interpenetration at the start frame, although the collisions
	should be disabled when doing so. Lower values will
	take longer to resolve the self collision, but can create smoother results.
	*/
	FloatID getSelfCrossoverPush(){char buffer[4096];sprintf_s (buffer, "%s.scpu",mName.c_str());return (const char*)buffer;}
	/*
	This tracks self collision crossovers and attempts to push the crossed over points
	back. It assumes that the surface is in a good state at the start and attempts to
	preserve that relative state. It is useful in cases where cloth can get caught
	between passive objects than interpenetrate (for example an elbow passing through a
	chest). Rather than get stuck on the wrong side this allows the cloth to push back
	to the correct side when the passive objects later separate.
	*/
	BoolID getSelfTrappedCheck(){char buffer[4096];sprintf_s (buffer, "%s.stpc",mName.c_str());return (const char*)buffer;}
	/*
	The manual setting defines pressure as a simple user input value that can be keyframed.
	The volume tracking model computes the pressure based on the current volume of the cloth
	combined with inflow and outflow of air. Note that higher iterations on the air model will result
	in more incompressibility of the internal air.
	*/
	UnsignedintID getPressureMethod(){char buffer[4096];sprintf_s (buffer, "%s.pmth",mName.c_str());return (const char*)buffer;}
	/*
	This defines a force applied along the surface normal direction
	when the Pressure Method is set to Manual.
	*/
	FloatID getPressure(){char buffer[4096];sprintf_s (buffer, "%s.pres",mName.c_str());return (const char*)buffer;}
	/*
	With the volume tracking pressure method this defines the relative air pressure
	inside the object at the startframe.
	*/
	FloatID getStartPressure(){char buffer[4096];sprintf_s (buffer, "%s.stpe",mName.c_str());return (const char*)buffer;}
	/*
	When the volume tracking pressure model is used this defines how incompressible the internal volume
	of fluid is. This also will affect how much force is applied to the cloth when air is pumped in.
	In the case of a balloon higher values of incompressibility will overcome higher stretch resistance.
	Note that higher incompressibility may require more calculation time.
	*/
	FloatID getIncompressibility(){char buffer[4096];sprintf_s (buffer, "%s.incm",mName.c_str());return (const char*)buffer;}
	/*Defines the air pressure damping*/
	FloatID getPressureDamping(){char buffer[4096];sprintf_s (buffer, "%s.prdg",mName.c_str());return (const char*)buffer;}
	/*Defines the rate at which air pressure is added to the object*/
	FloatID getPumpRate(){char buffer[4096];sprintf_s (buffer, "%s.pure",mName.c_str());return (const char*)buffer;}
	/*
	Defines the rate at which air can escape from the object, or how permiable the
	surface is. This is in addition to any physical holes in the model, which can be
	be capped or not using the seal holes attributes.
	*/
	FloatID getAirTightness(){char buffer[4096];sprintf_s (buffer, "%s.aits",mName.c_str());return (const char*)buffer;}
	/*
	When the volume tracking pressure method is used this determines if physical holes in
	the cloth model are treated as being capped or not. If holes are not sealed, then air
	can escape out them, which also has the effect of pushing the cloth. For example, this can simulate
	a rubber balloon that is suddenly released. It also allows for inflow based on motion of the
	cloth. The opening in a parachute will allow air to flow in as it falls down, causing sideways
	pressure that inflates it. Note that drag alone cannot achieve this sort of effect.
	*/
	BoolID getSealHoles(){char buffer[4096];sprintf_s (buffer, "%s.shol",mName.c_str());return (const char*)buffer;}
	/*Turn off the effect of the gravity that is defined on the solver node.*/
	BoolID getIgnoreSolverGravity(){char buffer[4096];sprintf_s (buffer, "%s.igsg",mName.c_str());return (const char*)buffer;}
	/*Turn off the effect of the wind that is defined on the solver node.*/
	BoolID getIgnoreSolverWind(){char buffer[4096];sprintf_s (buffer, "%s.igsw",mName.c_str());return (const char*)buffer;}
	/*Allow the object to shadow parts of itself from the wind.*/
	BoolID getWindSelfShadow(){char buffer[4096];sprintf_s (buffer, "%s.wssh",mName.c_str());return (const char*)buffer;}
	/*Defines the lift affecting this nParticle system*/
	FloatID getLift(){char buffer[4096];sprintf_s (buffer, "%s.lft",mName.c_str());return (const char*)buffer;}
	/*Defines the drag affecting this nParticle system*/
	FloatID getDrag(){char buffer[4096];sprintf_s (buffer, "%s.drg",mName.c_str());return (const char*)buffer;}
	/*
	Defines the component of drag tangent to the surface. With a value of zero a flat
	plane will slice through air with no resistance and only have drag when moving along
	its normal axis. With a value of 1.0 the effect of drag will be equal in all directions.
	*/
	FloatID getTangentialDrag(){char buffer[4096];sprintf_s (buffer, "%s.tdrg",mName.c_str());return (const char*)buffer;}
	/*Interactive display of internal solver info.*/
	UnsignedintID getSolverDisplay(){char buffer[4096];sprintf_s (buffer, "%s.svds",mName.c_str());return (const char*)buffer;}
	/*What type of stretch map to use: per-vertex, texture or none.*/
	UnsignedintID getStretchMapType(){char buffer[4096];sprintf_s (buffer, "%s.smt",mName.c_str());return (const char*)buffer;}
	/*What type of bend map to use: per-vertex, texture or none.*/
	UnsignedintID getBendMapType(){char buffer[4096];sprintf_s (buffer, "%s.bdmt",mName.c_str());return (const char*)buffer;}
	/*What type of rigidity map to use: per-vertex, texture or none.*/
	UnsignedintID getRigidityMapType(){char buffer[4096];sprintf_s (buffer, "%s.rmt",mName.c_str());return (const char*)buffer;}
	/*What type of deform map to use: per-vertex, texture or none.*/
	UnsignedintID getDeformMapType(){char buffer[4096];sprintf_s (buffer, "%s.dmmt",mName.c_str());return (const char*)buffer;}
	/*What type of inputAttract map to use: per-vertex, texture or none.*/
	UnsignedintID getInputAttractMapType(){char buffer[4096];sprintf_s (buffer, "%s.iamt",mName.c_str());return (const char*)buffer;}
	/*What type of wrinkle map to use: per-vertex, texture or none.*/
	UnsignedintID getWrinkleMapType(){char buffer[4096];sprintf_s (buffer, "%s.wmt",mName.c_str());return (const char*)buffer;}
protected:
	NCloth(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):NParticle(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NCLOTH_H__
