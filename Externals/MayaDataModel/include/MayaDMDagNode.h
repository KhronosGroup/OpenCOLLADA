/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DAGNODE_H__
#define __MayaDM_DAGNODE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMEntity.h"
namespace MayaDM
{
/*
DAG object node. Base class for all objects in the
 3D transformation hierarchy or DAG.
 <p/>
 <h4>Transformation Hierarchy (DAG)</h4>
 The transformation hierarchy or DAG (Directed Acyclic Graph) is a
 hierarchy where objects are defined relative to the transformations
 on their parent objects. These objects are dependency nodes and are
 referred to as dag nodes. There are basically two types of dag
 nodes: transforms and shapes. Transform nodes are grouping nodes
 which can have any number of other dag nodes below it. Transform
 nodes have affine transformation information which is applied to
 nodes below them. Shape nodes are leaf level nodes and cannot have
 any other nodes below them. Shape nodes must have at least one
 transform node as a parent. Dag nodes can have more than one
 parent. That is, they can be in more than one hierarchy. This makes
 the transformation hierarchy a graph instead of a tree. Dag nodes
 that are in more than one hierarchy are said to be "instanced".
 <h4>Names</h4>
 Dag nodes have names. There can be more than one dag node in the dag with
 the same name. However, a transform grouping node cannot have two child
 nodes with the same name.
 <h4>Paths</h4>
 Since there may be multiple ways to reach an instanced dag node
 when traversing down from the root of the hierarchy, all dag nodes
 are identified by a "path" which uniquely identifies a particular
 instance of an object. Paths define the traversal path from the
 root of the hierarchy down to the node. A dag node may have
 multiple paths to it.  Paths have an associated number which
 corresponds to their position in the list of paths to the node at
 the end of the path.  DAG Traversal is depth first so the first
 time a node is visited, the path traversed is path 0. The
 second time the dag node is visited, this different path traversed
 is path 1, and so on.  Each path to a dag node also
 defines how the node is to be transformed.  Instanced dag nodes
 will appear multiple times in the scene (once for each unique path
 from the root of the hierarchy to the object).
 <h4>Transformations</h4>
 All transformations in the DAG are affine transformations. All dag node
 transformations can be represented by a 4x4
 transformation matrix where the fourth column contains the vector (0,0,0,1),
 the fourth row contains the vector (tx, ty, tz, 1) and represents a
 translational component.
 This implies objects are transformed by post multiplying their position by
 the transformation matrix.
 <p/>
 <h4>Transformation Spaces</h4>
 When dealing with dag nodes there is the concept of "transformation space".
 Common transformation spaces include "world-space", "object-space" and
 "parent-space". "world-space" is the space in which the objects appear
 in the scene, after all the hierarchical transformations
 have been applied. "object-space" is defined
 as the space in which the geometry of the object is defined before
 any transformations have been applied. Finally, "parent-space"
 is the transformation space that includes the matrices of the parents
 above the object but not the object's transformation matrix.
 <p/>
 These transformation spaces are essential when dealing with attributes
 from different nodes to ensure consistent behaviour. For example, to
 compare
 the positions of vertices on two different objects in the scene, the
 vertices must first be transformed to a common transformation space.
 One way this can be accomplished is to transform the vertices using
 the worldMatrix attribute before doing the comparison.
 <p/>
 Note: certain attributes like the transformation channels defined in
 a transform
 node do not correspond to any of the transformation spaces described
 above because they are used to construct the transformation matrix.
 Therefore, the order in which they are applied within the transformation
 matrix defines a unique transformation space for each of these attributes.
 <p/>
 <h4>Instanced Attributes</h4>
 Additionally, dag nodes can contain a special type of attribute
 called an "instanced attribute". Instanced attributes are array attributes
 where the array attribute at index 'i' corresponds to instance number 'i'
 for this object in the transformation hierarchy. Instances are mapped
 to array
 indices according to their relative ordering when traversing the DAG
 depth first. (in ascending child order) When specifying
 instanced attributes it is not necessary to give the array index because
 the system will infer this information from the path. Therefore, the
 attribute "ball.worldMatrix" corresponds to the array attribute
 "ball.worldMatrix[0]". From this definition it follows that all
 instanced attributes must contain at least one array item.
 <p/>
 <h4>Matrix Attributes and MEL</h4>
 Some attributes represent transformation matrixes. Although these attributes
 are represented internally as 4x4 matrices, unfortunately, matrix attributes are not
 returned as MEL 4x4 matrix types. Instead, they are returned as an array of floats
 where the elements of the matrix are listed in row major order.
 For instance, "matrix $m[4][4] = `getAttr ball.worldMatrix`;"
 will not work.  To obtain the value of a matrix attribute, you need something like
 "float $m[16] = `getAttr ball.worldMatrix`;".
*/
class DagNode : public Entity
{
public:
	/*
	Bounding box. The bounding box of a dagNode includes the bounding
	boxes of all it's children and is transformed by the matrix
	attribute.
	*/
	struct BoundingBox{
		void write(FILE* file) const
		{
		}
	};
	/*
	An instanced attribute array of compound attributes used to
	represent "set" membership information.
	Connections are made to this attribute if the entire
	instance is in a set and connections are made to the children of
	this attribute if portions of this attribute are in sets.
	*/
	struct InstObjGroups{
		/*
		An array of compound attributes used to identify the parts of the
		object that are in various sets. Each element in the array refers
		to the membership in one set.
		*/
		struct ObjectGroups{
			componentList objectGrpCompList;
			int objectGroupId;
			short objectGrpColor;
			void write(FILE* file) const
			{
				objectGrpCompList.write(file);
				fprintf_s(file, " ");
				fprintf_s(file,"%i ", objectGroupId);
				fprintf_s(file,"%i", objectGrpColor);
			}
		}* objectGroups;
		void write(FILE* file) const
		{
			size_t size = sizeof(objectGroups)/sizeof(ObjectGroups);
			for(size_t i=0; i<size; ++i)
			{
				objectGroups[i].write(file);
				if(i+1<size) fprintf_s(file," ");
			}
		}
	};
	/*Parent attribute encapsulating all draw override information*/
	struct DrawOverride{
		unsigned int overrideDisplayType;
		unsigned int overrideLevelOfDetail;
		bool overrideShading;
		bool overrideTexturing;
		bool overridePlayback;
		bool overrideEnabled;
		bool overrideVisibility;
		unsigned char overrideColor;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", overrideDisplayType);
			fprintf_s(file,"%i ", overrideLevelOfDetail);
			fprintf_s(file,"%i ", overrideShading);
			fprintf_s(file,"%i ", overrideTexturing);
			fprintf_s(file,"%i ", overridePlayback);
			fprintf_s(file,"%i ", overrideEnabled);
			fprintf_s(file,"%i ", overrideVisibility);
			fprintf_s(file,"%i", overrideColor);
		}
	};
	/*Maya V7 obsolete*/
	struct RenderInfo{
		short identification;
		bool layerRenderable;
		unsigned char layerOverrideColor;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", identification);
			fprintf_s(file,"%i ", layerRenderable);
			fprintf_s(file,"%i", layerOverrideColor);
		}
	};
	/*Parent attribute encapsulating all render override information.*/
	struct RenderLayerInfo{
		short renderLayerId;
		bool renderLayerRenderable;
		unsigned char renderLayerColor;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", renderLayerId);
			fprintf_s(file,"%i ", renderLayerRenderable);
			fprintf_s(file,"%i", renderLayerColor);
		}
	};
	/*
	Attribute which stores the step information for ghosting.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	struct GhostCustomSteps{
		int ghostPreSteps;
		int ghostPostSteps;
		int ghostStepSize;
		void write(FILE* file) const
		{
			fprintf_s(file,"%i ", ghostPreSteps);
			fprintf_s(file,"%i ", ghostPostSteps);
			fprintf_s(file,"%i", ghostStepSize);
		}
	};
public:
	DagNode(FILE* file,const std::string& name,const std::string& parent=""):Entity(file, name, parent, "dagNode"){}
	virtual ~DagNode(){}
	/*
	Bounding box. The bounding box of a dagNode includes the bounding
	boxes of all it's children and is transformed by the matrix
	attribute.
	*/
	void setBoundingBox(const BoundingBoxID& bb){fprintf_s(mFile,"connectAttr \"");bb.write(mFile);fprintf_s(mFile,"\" \"%s.bb\";\n",mName.c_str());}
	/*Bounding box minimum.*/
	void setBoundingBoxMin(const Double3ID& bbmn){fprintf_s(mFile,"connectAttr \"");bbmn.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbmn\";\n",mName.c_str());}
	/*Bounding box minimum X value*/
	void setBoundingBoxMinX(const DoubleID& bbnx){fprintf_s(mFile,"connectAttr \"");bbnx.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbmn.bbnx\";\n",mName.c_str());}
	/*Bounding box minimum Y value*/
	void setBoundingBoxMinY(const DoubleID& bbny){fprintf_s(mFile,"connectAttr \"");bbny.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbmn.bbny\";\n",mName.c_str());}
	/*Bounding box minimum Z value*/
	void setBoundingBoxMinZ(const DoubleID& bbnz){fprintf_s(mFile,"connectAttr \"");bbnz.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbmn.bbnz\";\n",mName.c_str());}
	/*Bounding box maximum.*/
	void setBoundingBoxMax(const Double3ID& bbmx){fprintf_s(mFile,"connectAttr \"");bbmx.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbmx\";\n",mName.c_str());}
	/*Bounding box maximum X value.*/
	void setBoundingBoxMaxX(const DoubleID& bbxx){fprintf_s(mFile,"connectAttr \"");bbxx.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbmx.bbxx\";\n",mName.c_str());}
	/*Bounding box maximum Y value.*/
	void setBoundingBoxMaxY(const DoubleID& bbxy){fprintf_s(mFile,"connectAttr \"");bbxy.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbmx.bbxy\";\n",mName.c_str());}
	/*Bounding box maximum Z value.*/
	void setBoundingBoxMaxZ(const DoubleID& bbxz){fprintf_s(mFile,"connectAttr \"");bbxz.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbmx.bbxz\";\n",mName.c_str());}
	/*Bounding box extents. (boundingBoxMax - boundingBoxMin)*/
	void setBoundingBoxSize(const Double3ID& bbsi){fprintf_s(mFile,"connectAttr \"");bbsi.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbsi\";\n",mName.c_str());}
	/*Bounding box extent in X.*/
	void setBoundingBoxSizeX(const DoubleID& bbsx){fprintf_s(mFile,"connectAttr \"");bbsx.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbsi.bbsx\";\n",mName.c_str());}
	/*Bounding box extent in Y.*/
	void setBoundingBoxSizeY(const DoubleID& bbsy){fprintf_s(mFile,"connectAttr \"");bbsy.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbsi.bbsy\";\n",mName.c_str());}
	/*Bounding box extent in Z.*/
	void setBoundingBoxSizeZ(const DoubleID& bbsz){fprintf_s(mFile,"connectAttr \"");bbsz.write(mFile);fprintf_s(mFile,"\" \"%s.bb.bbsi.bbsz\";\n",mName.c_str());}
	/*
	Center of the boundingBox. Note: like the boundingBox attribute,
	this attribute is also transformed by the matrix attribute.
	*/
	void setCenter(const Double3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*Center X value.*/
	void setBoundingBoxCenterX(const DoubleID& bcx){fprintf_s(mFile,"connectAttr \"");bcx.write(mFile);fprintf_s(mFile,"\" \"%s.c.bcx\";\n",mName.c_str());}
	/*Center Y value.*/
	void setBoundingBoxCenterY(const DoubleID& bcy){fprintf_s(mFile,"connectAttr \"");bcy.write(mFile);fprintf_s(mFile,"\" \"%s.c.bcy\";\n",mName.c_str());}
	/*Center Z value.*/
	void setBoundingBoxCenterZ(const DoubleID& bcz){fprintf_s(mFile,"connectAttr \"");bcz.write(mFile);fprintf_s(mFile,"\" \"%s.c.bcz\";\n",mName.c_str());}
	/*Local transformation matrix for the dagNode.*/
	void setMatrix(const MatrixID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*Inverse of matrix attribute.*/
	void setInverseMatrix(const MatrixID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*
	The worldMatrix instanced attribute is the 4x4 transformation matrix
	that transforms the object to world-space. There is a world-space
	matrix for each unique path to the object.  Eg. 'ball.worldMatrix[0]'
	identifies the world-space transformation matrix for the first instance
	of the object 'ball'. Each world-space transformation matrix
	is the result of post multiplying the 'matrix' attribute by
	corresponding 'parentMatrix' instanced attribute
	(i.e. worldMatrix[i] == matrix x parentMatrix[i]). Thus, the worldMatrix
	is the concatenation of the 'matrix' attribute of all the dagNodes along
	the path from the node up to the root of the dag hierarchy.
	*/
	void setWorldMatrix(size_t wm_i,const MatrixID& wm){fprintf_s(mFile,"connectAttr \"");wm.write(mFile);fprintf_s(mFile,"\" \"%s.wm[%i]\";\n",mName.c_str(),wm_i);}
	/*Inverse of worldMatrix instanced attribute.*/
	void setWorldInverseMatrix(size_t wim_i,const MatrixID& wim){fprintf_s(mFile,"connectAttr \"");wim.write(mFile);fprintf_s(mFile,"\" \"%s.wim[%i]\";\n",mName.c_str(),wim_i);}
	/*
	The parentMatrix instanced attribute represents the world-space
	transformation matrix for the parents of this dagNode.
	If the dagNode is a transform node and its inheritTransform attribute
	is false, then the parentMatrix is identity.
	*/
	void setParentMatrix(size_t pm_i,const MatrixID& pm){fprintf_s(mFile,"connectAttr \"");pm.write(mFile);fprintf_s(mFile,"\" \"%s.pm[%i]\";\n",mName.c_str(),pm_i);}
	/*Inverse of parentMatrix instanced attribute.*/
	void setParentInverseMatrix(size_t pim_i,const MatrixID& pim){fprintf_s(mFile,"connectAttr \"");pim.write(mFile);fprintf_s(mFile,"\" \"%s.pim[%i]\";\n",mName.c_str(),pim_i);}
	/*
	Boolean attribute that is set to false for invisible objects in
	the scene. Note: visibility is inherited by children of a dagNode.
	*/
	void setVisibility(bool v){if(v == true) return; fprintf_s(mFile, "setAttr \".v\" %i;\n", v);}
	/*
	Boolean attribute that is set to false for invisible objects in
	the scene. Note: visibility is inherited by children of a dagNode.
	*/
	void setVisibility(const BoolID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*
	Boolean attribute that specifies whether the dagNode is an
	intermediate object resulting from a construction history
	operation. dagNodes with this attribute set to true are not
	visible and/or rendered. This attribute is automatically set
	so changing this value may cause unpredictable results.
	*/
	void setIntermediateObject(bool io){if(io == false) return; fprintf_s(mFile, "setAttr \".io\" %i;\n", io);}
	/*
	Boolean attribute that specifies whether the dagNode is an
	intermediate object resulting from a construction history
	operation. dagNodes with this attribute set to true are not
	visible and/or rendered. This attribute is automatically set
	so changing this value may cause unpredictable results.
	*/
	void setIntermediateObject(const BoolID& io){fprintf_s(mFile,"connectAttr \"");io.write(mFile);fprintf_s(mFile,"\" \"%s.io\";\n",mName.c_str());}
	/*
	Boolean attribute that specifies whether the object is templated.
	Templated objects are objects in the scene that are not rendered,
	always drawn in wireframe mode, and can only be selected using
	"template" selection mode.
	Note: template state is inherited by children of a dagNode.
	*/
	void setTemplate(bool tmp){if(tmp == false) return; fprintf_s(mFile, "setAttr \".tmp\" %i;\n", tmp);}
	/*
	Boolean attribute that specifies whether the object is templated.
	Templated objects are objects in the scene that are not rendered,
	always drawn in wireframe mode, and can only be selected using
	"template" selection mode.
	Note: template state is inherited by children of a dagNode.
	*/
	void setTemplate(const BoolID& tmp){fprintf_s(mFile,"connectAttr \"");tmp.write(mFile);fprintf_s(mFile,"\" \"%s.tmp\";\n",mName.c_str());}
	/*
	Boolean attribute controls whether ghosts of the object are
	displayed.
	*/
	void setGhosting(bool gh){if(gh == false) return; fprintf_s(mFile, "setAttr \".gh\" %i;\n", gh);}
	/*
	Boolean attribute controls whether ghosts of the object are
	displayed.
	*/
	void setGhosting(const BoolID& gh){fprintf_s(mFile,"connectAttr \"");gh.write(mFile);fprintf_s(mFile,"\" \"%s.gh\";\n",mName.c_str());}
	/*
	An instanced attribute array of compound attributes used to
	represent "set" membership information.
	Connections are made to this attribute if the entire
	instance is in a set and connections are made to the children of
	this attribute if portions of this attribute are in sets.
	*/
	void setInstObjGroups(size_t iog_i,const InstObjGroups& iog){fprintf_s(mFile, "setAttr \".iog[%i]\" ",iog_i);iog.write(mFile);fprintf_s(mFile,";\n");}
	/*
	An instanced attribute array of compound attributes used to
	represent "set" membership information.
	Connections are made to this attribute if the entire
	instance is in a set and connections are made to the children of
	this attribute if portions of this attribute are in sets.
	*/
	void setInstObjGroups(size_t iog_i,const InstObjGroupsID& iog){fprintf_s(mFile,"connectAttr \"");iog.write(mFile);fprintf_s(mFile,"\" \"%s.iog[%i]\";\n",mName.c_str(),iog_i);}
	/*
	An array of compound attributes used to identify the parts of the
	object that are in various sets. Each element in the array refers
	to the membership in one set.
	*/
	void setObjectGroups(size_t iog_i,size_t og_i,const InstObjGroups::ObjectGroups& og){fprintf_s(mFile, "setAttr \".iog[%i].og[%i]\" ",iog_i,og_i);og.write(mFile);fprintf_s(mFile,";\n");}
	/*
	An array of compound attributes used to identify the parts of the
	object that are in various sets. Each element in the array refers
	to the membership in one set.
	*/
	void setObjectGroups(size_t iog_i,size_t og_i,const ObjectGroupsID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.iog[%i].og[%i]\";\n",mName.c_str(),iog_i,og_i);}
	/*Specifies the portion of the object that is in the set.*/
	void setObjectGrpCompList(size_t iog_i,size_t og_i,const componentList& gcl){fprintf_s(mFile, "setAttr \".iog[%i].og[%i].gcl\" -type \"componentList\" ",iog_i,og_i);gcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Group Id
	Integer that identifies the object group in the object.
	*/
	void setObjectGroupId(size_t iog_i,size_t og_i,int gid){if(gid == 0) return; fprintf_s(mFile, "setAttr \".iog[%i].og[%i].gid\" %i;\n", iog_i,og_i,gid);}
	/*
	Group Id
	Integer that identifies the object group in the object.
	*/
	void setObjectGroupId(size_t iog_i,size_t og_i,const IntID& gid){fprintf_s(mFile,"connectAttr \"");gid.write(mFile);fprintf_s(mFile,"\" \"%s.iog[%i].og[%i].gid\";\n",mName.c_str(),iog_i,og_i);}
	/*
	Integer representing the user-defined color index assigned
	to the set this that this object group is a part of. A value
	of -1 turns off this attribute.
	Warning, setting this value to anything outside the range
	-1..7 will cause unpredictable results.
	*/
	void setObjectGrpColor(size_t iog_i,size_t og_i,short gco){if(gco == -1) return; fprintf_s(mFile, "setAttr \".iog[%i].og[%i].gco\" %i;\n", iog_i,og_i,gco);}
	/*
	Integer representing the user-defined color index assigned
	to the set this that this object group is a part of. A value
	of -1 turns off this attribute.
	Warning, setting this value to anything outside the range
	-1..7 will cause unpredictable results.
	*/
	void setObjectGrpColor(size_t iog_i,size_t og_i,const ShortID& gco){fprintf_s(mFile,"connectAttr \"");gco.write(mFile);fprintf_s(mFile,"\" \"%s.iog[%i].og[%i].gco\";\n",mName.c_str(),iog_i,og_i);}
	/*
	If true the dormant wireframe color of the dagNode is controlled
	by the aObjectColor attribute. Otherwise, the dormant color is
	determined by the type of object and the color preferences.
	*/
	void setUseObjectColor(bool uoc){if(uoc == false) return; fprintf_s(mFile, "setAttr \".uoc\" %i;\n", uoc);}
	/*
	If true the dormant wireframe color of the dagNode is controlled
	by the aObjectColor attribute. Otherwise, the dormant color is
	determined by the type of object and the color preferences.
	*/
	void setUseObjectColor(const BoolID& uoc){fprintf_s(mFile,"connectAttr \"");uoc.write(mFile);fprintf_s(mFile,"\" \"%s.uoc\";\n",mName.c_str());}
	/*
	Integer representing a user-defined color index to use as
	the dormant color for this dagNode in wireframe mode.
	Warning, setting this value to anything outside the range
	0..7 will cause unpredictable results.
	*/
	void setObjectColor(short oc){if(oc == 0) return; fprintf_s(mFile, "setAttr \".oc\" %i;\n", oc);}
	/*
	Integer representing a user-defined color index to use as
	the dormant color for this dagNode in wireframe mode.
	Warning, setting this value to anything outside the range
	0..7 will cause unpredictable results.
	*/
	void setObjectColor(const ShortID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Parent attribute encapsulating all draw override information*/
	void setDrawOverride(const DrawOverride& do_){fprintf_s(mFile, "setAttr \".do\" ");do_.write(mFile);fprintf_s(mFile,";\n");}
	/*Parent attribute encapsulating all draw override information*/
	void setDrawOverride(const DrawOverrideID& do_){fprintf_s(mFile,"connectAttr \"");do_.write(mFile);fprintf_s(mFile,"\" \"%s.do\";\n",mName.c_str());}
	/*Override for the method of drawing.  0=Normal, 1=Template, 2=Reference*/
	void setOverrideDisplayType(unsigned int ovdt){if(ovdt == 0) return; fprintf_s(mFile, "setAttr \".do.ovdt\" %i;\n", ovdt);}
	/*Override for the method of drawing.  0=Normal, 1=Template, 2=Reference*/
	void setOverrideDisplayType(const UnsignedintID& ovdt){fprintf_s(mFile,"connectAttr \"");ovdt.write(mFile);fprintf_s(mFile,"\" \"%s.do.ovdt\";\n",mName.c_str());}
	/*
	Override for the amount of detail to be drawn.
	0=Full, 1=Bounding Box
	*/
	void setOverrideLevelOfDetail(unsigned int ovlod){if(ovlod == 0) return; fprintf_s(mFile, "setAttr \".do.ovlod\" %i;\n", ovlod);}
	/*
	Override for the amount of detail to be drawn.
	0=Full, 1=Bounding Box
	*/
	void setOverrideLevelOfDetail(const UnsignedintID& ovlod){fprintf_s(mFile,"connectAttr \"");ovlod.write(mFile);fprintf_s(mFile,"\" \"%s.do.ovlod\";\n",mName.c_str());}
	/*Override of shading state when in shaded display*/
	void setOverrideShading(bool ovs){if(ovs == true) return; fprintf_s(mFile, "setAttr \".do.ovs\" %i;\n", ovs);}
	/*Override of shading state when in shaded display*/
	void setOverrideShading(const BoolID& ovs){fprintf_s(mFile,"connectAttr \"");ovs.write(mFile);fprintf_s(mFile,"\" \"%s.do.ovs\";\n",mName.c_str());}
	/*Override of texturing state when in shaded display*/
	void setOverrideTexturing(bool ovt){if(ovt == true) return; fprintf_s(mFile, "setAttr \".do.ovt\" %i;\n", ovt);}
	/*Override of texturing state when in shaded display*/
	void setOverrideTexturing(const BoolID& ovt){fprintf_s(mFile,"connectAttr \"");ovt.write(mFile);fprintf_s(mFile,"\" \"%s.do.ovt\";\n",mName.c_str());}
	/*Override of ability to animate*/
	void setOverridePlayback(bool ovp){if(ovp == true) return; fprintf_s(mFile, "setAttr \".do.ovp\" %i;\n", ovp);}
	/*Override of ability to animate*/
	void setOverridePlayback(const BoolID& ovp){fprintf_s(mFile,"connectAttr \"");ovp.write(mFile);fprintf_s(mFile,"\" \"%s.do.ovp\";\n",mName.c_str());}
	/*Turn on/off the effect of the sibling attributes*/
	void setOverrideEnabled(bool ove){if(ove == false) return; fprintf_s(mFile, "setAttr \".do.ove\" %i;\n", ove);}
	/*Turn on/off the effect of the sibling attributes*/
	void setOverrideEnabled(const BoolID& ove){fprintf_s(mFile,"connectAttr \"");ove.write(mFile);fprintf_s(mFile,"\" \"%s.do.ove\";\n",mName.c_str());}
	/*Override of the object visibility*/
	void setOverrideVisibility(bool ovv){if(ovv == true) return; fprintf_s(mFile, "setAttr \".do.ovv\" %i;\n", ovv);}
	/*Override of the object visibility*/
	void setOverrideVisibility(const BoolID& ovv){fprintf_s(mFile,"connectAttr \"");ovv.write(mFile);fprintf_s(mFile,"\" \"%s.do.ovv\";\n",mName.c_str());}
	/*
	Override of the object color. Valid range is [0-31].
	A value of zero disables the override.
	*/
	void setOverrideColor(unsigned char ovc){if(ovc == 0) return; fprintf_s(mFile, "setAttr \".do.ovc\" %i;\n", ovc);}
	/*
	Override of the object color. Valid range is [0-31].
	A value of zero disables the override.
	*/
	void setOverrideColor(const UnsignedcharID& ovc){fprintf_s(mFile,"connectAttr \"");ovc.write(mFile);fprintf_s(mFile,"\" \"%s.do.ovc\";\n",mName.c_str());}
	/*
	Override of the object visibility. Used to control visibility
	of objects for level of detail.
	*/
	void setLodVisibility(bool lodv){if(lodv == true) return; fprintf_s(mFile, "setAttr \".lodv\" %i;\n", lodv);}
	/*
	Override of the object visibility. Used to control visibility
	of objects for level of detail.
	*/
	void setLodVisibility(const BoolID& lodv){fprintf_s(mFile,"connectAttr \"");lodv.write(mFile);fprintf_s(mFile,"\" \"%s.lodv\";\n",mName.c_str());}
	/*Maya V7 obsolete*/
	void setRenderInfo(const RenderInfo& ri){fprintf_s(mFile, "setAttr \".ri\" ");ri.write(mFile);fprintf_s(mFile,";\n");}
	/*Maya V7 obsolete*/
	void setRenderInfo(const RenderInfoID& ri){fprintf_s(mFile,"connectAttr \"");ri.write(mFile);fprintf_s(mFile,"\" \"%s.ri\";\n",mName.c_str());}
	/*Maya V7 obsolete*/
	void setIdentification(short rlid){if(rlid == 0) return; fprintf_s(mFile, "setAttr \".ri.rlid\" %i;\n", rlid);}
	/*Maya V7 obsolete*/
	void setIdentification(const ShortID& rlid){fprintf_s(mFile,"connectAttr \"");rlid.write(mFile);fprintf_s(mFile,"\" \"%s.ri.rlid\";\n",mName.c_str());}
	/*Maya V7 obsolete*/
	void setLayerRenderable(bool rndr){if(rndr == true) return; fprintf_s(mFile, "setAttr \".ri.rndr\" %i;\n", rndr);}
	/*Maya V7 obsolete*/
	void setLayerRenderable(const BoolID& rndr){fprintf_s(mFile,"connectAttr \"");rndr.write(mFile);fprintf_s(mFile,"\" \"%s.ri.rndr\";\n",mName.c_str());}
	/*Maya V7 Obsolete*/
	void setLayerOverrideColor(unsigned char lovc){if(lovc == 0) return; fprintf_s(mFile, "setAttr \".ri.lovc\" %i;\n", lovc);}
	/*Maya V7 Obsolete*/
	void setLayerOverrideColor(const UnsignedcharID& lovc){fprintf_s(mFile,"connectAttr \"");lovc.write(mFile);fprintf_s(mFile,"\" \"%s.ri.lovc\";\n",mName.c_str());}
	/*Parent attribute encapsulating all render override information.*/
	void setRenderLayerInfo(size_t rlio_i,const RenderLayerInfo& rlio){fprintf_s(mFile, "setAttr \".rlio[%i]\" ",rlio_i);rlio.write(mFile);fprintf_s(mFile,";\n");}
	/*Parent attribute encapsulating all render override information.*/
	void setRenderLayerInfo(size_t rlio_i,const RenderLayerInfoID& rlio){fprintf_s(mFile,"connectAttr \"");rlio.write(mFile);fprintf_s(mFile,"\" \"%s.rlio[%i]\";\n",mName.c_str(),rlio_i);}
	/*Render layer identification number*/
	void setRenderLayerId(size_t rlio_i,short rli){if(rli == 0) return; fprintf_s(mFile, "setAttr \".rlio[%i].rli\" %i;\n", rlio_i,rli);}
	/*Render layer identification number*/
	void setRenderLayerId(size_t rlio_i,const ShortID& rli){fprintf_s(mFile,"connectAttr \"");rli.write(mFile);fprintf_s(mFile,"\" \"%s.rlio[%i].rli\";\n",mName.c_str(),rlio_i);}
	/*Specifies whether the layer is visible when rendered.*/
	void setRenderLayerRenderable(size_t rlio_i,bool rlr){if(rlr == true) return; fprintf_s(mFile, "setAttr \".rlio[%i].rlr\" %i;\n", rlio_i,rlr);}
	/*Specifies whether the layer is visible when rendered.*/
	void setRenderLayerRenderable(size_t rlio_i,const BoolID& rlr){fprintf_s(mFile,"connectAttr \"");rlr.write(mFile);fprintf_s(mFile,"\" \"%s.rlio[%i].rlr\";\n",mName.c_str(),rlio_i);}
	/*Color with which to draw.*/
	void setRenderLayerColor(size_t rlio_i,unsigned char rlc){if(rlc == 0) return; fprintf_s(mFile, "setAttr \".rlio[%i].rlc\" %i;\n", rlio_i,rlc);}
	/*Color with which to draw.*/
	void setRenderLayerColor(size_t rlio_i,const UnsignedcharID& rlc){fprintf_s(mFile,"connectAttr \"");rlc.write(mFile);fprintf_s(mFile,"\" \"%s.rlio[%i].rlc\";\n",mName.c_str(),rlio_i);}
	/*
	This attribute specifies how the user wants to specify the frames where the ghosts appear.
	The settings have the following meanings:
	globalPreferences: ghosts are drawn at the steps specified in the Animation Preferences
	customFrames: ghosts are drawn at the frames specified in the ghostFrames attribute
	customFramePrePost: ghosts are drawn at the steps of frame specified in the ghostPrePost attribute
	customKeyPrePost: ghosts are drawn at the steps of key specified in the ghostPrePost attribute
	keyframeRange: ghosts are drawn at the frames within the range where there are keys
	*/
	void setGhostingControl(unsigned int gc){if(gc == 0) return; fprintf_s(mFile, "setAttr \".gc\" %i;\n", gc);}
	/*
	This attribute specifies how the user wants to specify the frames where the ghosts appear.
	The settings have the following meanings:
	globalPreferences: ghosts are drawn at the steps specified in the Animation Preferences
	customFrames: ghosts are drawn at the frames specified in the ghostFrames attribute
	customFramePrePost: ghosts are drawn at the steps of frame specified in the ghostPrePost attribute
	customKeyPrePost: ghosts are drawn at the steps of key specified in the ghostPrePost attribute
	keyframeRange: ghosts are drawn at the frames within the range where there are keys
	*/
	void setGhostingControl(const UnsignedintID& gc){fprintf_s(mFile,"connectAttr \"");gc.write(mFile);fprintf_s(mFile,"\" \"%s.gc\";\n",mName.c_str());}
	/*
	Attribute which stores the step information for ghosting.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	void setGhostCustomSteps(const GhostCustomSteps& gcs){fprintf_s(mFile, "setAttr \".gcs\" ");gcs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Attribute which stores the step information for ghosting.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	void setGhostCustomSteps(const GhostCustomStepsID& gcs){fprintf_s(mFile,"connectAttr \"");gcs.write(mFile);fprintf_s(mFile,"\" \"%s.gcs\";\n",mName.c_str());}
	/*
	The number of ghost steps before the current frame.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	void setGhostPreSteps(int gpr){if(gpr == 3) return; fprintf_s(mFile, "setAttr \".gcs.gpr\" %i;\n", gpr);}
	/*
	The number of ghost steps before the current frame.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	void setGhostPreSteps(const IntID& gpr){fprintf_s(mFile,"connectAttr \"");gpr.write(mFile);fprintf_s(mFile,"\" \"%s.gcs.gpr\";\n",mName.c_str());}
	/*
	The number of ghost steps after the current frame.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	void setGhostPostSteps(int gps){if(gps == 3) return; fprintf_s(mFile, "setAttr \".gcs.gps\" %i;\n", gps);}
	/*
	The number of ghost steps after the current frame.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	void setGhostPostSteps(const IntID& gps){fprintf_s(mFile,"connectAttr \"");gps.write(mFile);fprintf_s(mFile,"\" \"%s.gcs.gps\";\n",mName.c_str());}
	/*
	The number of frames per ghosting step.
	This value is only used if the ghostingControl is set to customFramePrePost or customKeyPrePost.
	*/
	void setGhostStepSize(int gss){if(gss == 1) return; fprintf_s(mFile, "setAttr \".gcs.gss\" %i;\n", gss);}
	/*
	The number of frames per ghosting step.
	This value is only used if the ghostingControl is set to customFramePrePost or customKeyPrePost.
	*/
	void setGhostStepSize(const IntID& gss){fprintf_s(mFile,"connectAttr \"");gss.write(mFile);fprintf_s(mFile,"\" \"%s.gcs.gss\";\n",mName.c_str());}
	/*
	Specific frames where the ghost will apear.
	This value is only used if the ghostingControl is set to customFrames.
	*/
	void setGhostFrames(const intArray& gf){if(gf.size == 0) return; fprintf_s(mFile, "setAttr \".gf\" -type \"intArray\" ");gf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Specific frames where the ghost will apear.
	This value is only used if the ghostingControl is set to customFrames.
	*/
	void setGhostFrames(const IntArrayID& gf){fprintf_s(mFile,"connectAttr \"");gf.write(mFile);fprintf_s(mFile,"\" \"%s.gf\";\n",mName.c_str());}
	/*
	Start of time range where ghosts on keyframes will appear.
	This value is only used if the ghostingControl is set to keyframeRange.
	*/
	void setGhostRangeStart(const TimeID& grs){fprintf_s(mFile,"connectAttr \"");grs.write(mFile);fprintf_s(mFile,"\" \"%s.grs\";\n",mName.c_str());}
	/*
	End of time range where ghosts on keyframes will appear.
	This value is only used if the ghostingControl is set to keyframeRange.
	*/
	void setGhostRangeEnd(const TimeID& gre){fprintf_s(mFile,"connectAttr \"");gre.write(mFile);fprintf_s(mFile,"\" \"%s.gre\";\n",mName.c_str());}
	/*
	The message attribute determines which dag object's keys will
	be used to display ghosting for this object
	*/
	void setGhostDriver(const MessageID& gdr){fprintf_s(mFile,"connectAttr \"");gdr.write(mFile);fprintf_s(mFile,"\" \"%s.gdr\";\n",mName.c_str());}
	/*
	Bounding box. The bounding box of a dagNode includes the bounding
	boxes of all it's children and is transformed by the matrix
	attribute.
	*/
	BoundingBoxID getBoundingBox(){char buffer[4096];sprintf_s (buffer, "%s.bb",mName.c_str());return (const char*)buffer;}
	/*Bounding box minimum.*/
	Double3ID getBoundingBoxMin(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbmn",mName.c_str());return (const char*)buffer;}
	/*Bounding box minimum X value*/
	DoubleID getBoundingBoxMinX(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbmn.bbnx",mName.c_str());return (const char*)buffer;}
	/*Bounding box minimum Y value*/
	DoubleID getBoundingBoxMinY(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbmn.bbny",mName.c_str());return (const char*)buffer;}
	/*Bounding box minimum Z value*/
	DoubleID getBoundingBoxMinZ(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbmn.bbnz",mName.c_str());return (const char*)buffer;}
	/*Bounding box maximum.*/
	Double3ID getBoundingBoxMax(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbmx",mName.c_str());return (const char*)buffer;}
	/*Bounding box maximum X value.*/
	DoubleID getBoundingBoxMaxX(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbmx.bbxx",mName.c_str());return (const char*)buffer;}
	/*Bounding box maximum Y value.*/
	DoubleID getBoundingBoxMaxY(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbmx.bbxy",mName.c_str());return (const char*)buffer;}
	/*Bounding box maximum Z value.*/
	DoubleID getBoundingBoxMaxZ(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbmx.bbxz",mName.c_str());return (const char*)buffer;}
	/*Bounding box extents. (boundingBoxMax - boundingBoxMin)*/
	Double3ID getBoundingBoxSize(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbsi",mName.c_str());return (const char*)buffer;}
	/*Bounding box extent in X.*/
	DoubleID getBoundingBoxSizeX(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbsi.bbsx",mName.c_str());return (const char*)buffer;}
	/*Bounding box extent in Y.*/
	DoubleID getBoundingBoxSizeY(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbsi.bbsy",mName.c_str());return (const char*)buffer;}
	/*Bounding box extent in Z.*/
	DoubleID getBoundingBoxSizeZ(){char buffer[4096];sprintf_s (buffer, "%s.bb.bbsi.bbsz",mName.c_str());return (const char*)buffer;}
	/*
	Center of the boundingBox. Note: like the boundingBox attribute,
	this attribute is also transformed by the matrix attribute.
	*/
	Double3ID getCenter(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*Center X value.*/
	DoubleID getBoundingBoxCenterX(){char buffer[4096];sprintf_s (buffer, "%s.c.bcx",mName.c_str());return (const char*)buffer;}
	/*Center Y value.*/
	DoubleID getBoundingBoxCenterY(){char buffer[4096];sprintf_s (buffer, "%s.c.bcy",mName.c_str());return (const char*)buffer;}
	/*Center Z value.*/
	DoubleID getBoundingBoxCenterZ(){char buffer[4096];sprintf_s (buffer, "%s.c.bcz",mName.c_str());return (const char*)buffer;}
	/*Local transformation matrix for the dagNode.*/
	MatrixID getMatrix(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*Inverse of matrix attribute.*/
	MatrixID getInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*
	The worldMatrix instanced attribute is the 4x4 transformation matrix
	that transforms the object to world-space. There is a world-space
	matrix for each unique path to the object.  Eg. 'ball.worldMatrix[0]'
	identifies the world-space transformation matrix for the first instance
	of the object 'ball'. Each world-space transformation matrix
	is the result of post multiplying the 'matrix' attribute by
	corresponding 'parentMatrix' instanced attribute
	(i.e. worldMatrix[i] == matrix x parentMatrix[i]). Thus, the worldMatrix
	is the concatenation of the 'matrix' attribute of all the dagNodes along
	the path from the node up to the root of the dag hierarchy.
	*/
	const MatrixID& getWorldMatrix(size_t wm_i){char buffer[4096];sprintf_s (buffer, "%s.wm[%i]",mName.c_str(),wm_i);return (const char*)buffer;}
	/*Inverse of worldMatrix instanced attribute.*/
	const MatrixID& getWorldInverseMatrix(size_t wim_i){char buffer[4096];sprintf_s (buffer, "%s.wim[%i]",mName.c_str(),wim_i);return (const char*)buffer;}
	/*
	The parentMatrix instanced attribute represents the world-space
	transformation matrix for the parents of this dagNode.
	If the dagNode is a transform node and its inheritTransform attribute
	is false, then the parentMatrix is identity.
	*/
	const MatrixID& getParentMatrix(size_t pm_i){char buffer[4096];sprintf_s (buffer, "%s.pm[%i]",mName.c_str(),pm_i);return (const char*)buffer;}
	/*Inverse of parentMatrix instanced attribute.*/
	const MatrixID& getParentInverseMatrix(size_t pim_i){char buffer[4096];sprintf_s (buffer, "%s.pim[%i]",mName.c_str(),pim_i);return (const char*)buffer;}
	/*
	Boolean attribute that is set to false for invisible objects in
	the scene. Note: visibility is inherited by children of a dagNode.
	*/
	BoolID getVisibility(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*
	Boolean attribute that specifies whether the dagNode is an
	intermediate object resulting from a construction history
	operation. dagNodes with this attribute set to true are not
	visible and/or rendered. This attribute is automatically set
	so changing this value may cause unpredictable results.
	*/
	BoolID getIntermediateObject(){char buffer[4096];sprintf_s (buffer, "%s.io",mName.c_str());return (const char*)buffer;}
	/*
	Boolean attribute that specifies whether the object is templated.
	Templated objects are objects in the scene that are not rendered,
	always drawn in wireframe mode, and can only be selected using
	"template" selection mode.
	Note: template state is inherited by children of a dagNode.
	*/
	BoolID getTemplate(){char buffer[4096];sprintf_s (buffer, "%s.tmp",mName.c_str());return (const char*)buffer;}
	/*
	Boolean attribute controls whether ghosts of the object are
	displayed.
	*/
	BoolID getGhosting(){char buffer[4096];sprintf_s (buffer, "%s.gh",mName.c_str());return (const char*)buffer;}
	/*
	An instanced attribute array of compound attributes used to
	represent "set" membership information.
	Connections are made to this attribute if the entire
	instance is in a set and connections are made to the children of
	this attribute if portions of this attribute are in sets.
	*/
	const InstObjGroupsID& getInstObjGroups(size_t iog_i){char buffer[4096];sprintf_s (buffer, "%s.iog[%i]",mName.c_str(),iog_i);return (const char*)buffer;}
	/*
	An array of compound attributes used to identify the parts of the
	object that are in various sets. Each element in the array refers
	to the membership in one set.
	*/
	const ObjectGroupsID& getObjectGroups(size_t iog_i,size_t og_i){char buffer[4096];sprintf_s (buffer, "%s.iog[%i].og[%i]",mName.c_str(),iog_i,og_i);return (const char*)buffer;}
	/*
	Group Id
	Integer that identifies the object group in the object.
	*/
	const IntID& getObjectGroupId(size_t iog_i,size_t og_i){char buffer[4096];sprintf_s (buffer, "%s.iog[%i].og[%i].gid",mName.c_str(),iog_i,og_i);return (const char*)buffer;}
	/*
	Integer representing the user-defined color index assigned
	to the set this that this object group is a part of. A value
	of -1 turns off this attribute.
	Warning, setting this value to anything outside the range
	-1..7 will cause unpredictable results.
	*/
	const ShortID& getObjectGrpColor(size_t iog_i,size_t og_i){char buffer[4096];sprintf_s (buffer, "%s.iog[%i].og[%i].gco",mName.c_str(),iog_i,og_i);return (const char*)buffer;}
	/*
	If true the dormant wireframe color of the dagNode is controlled
	by the aObjectColor attribute. Otherwise, the dormant color is
	determined by the type of object and the color preferences.
	*/
	BoolID getUseObjectColor(){char buffer[4096];sprintf_s (buffer, "%s.uoc",mName.c_str());return (const char*)buffer;}
	/*
	Integer representing a user-defined color index to use as
	the dormant color for this dagNode in wireframe mode.
	Warning, setting this value to anything outside the range
	0..7 will cause unpredictable results.
	*/
	ShortID getObjectColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Parent attribute encapsulating all draw override information*/
	DrawOverrideID getDrawOverride(){char buffer[4096];sprintf_s (buffer, "%s.do",mName.c_str());return (const char*)buffer;}
	/*Override for the method of drawing.  0=Normal, 1=Template, 2=Reference*/
	UnsignedintID getOverrideDisplayType(){char buffer[4096];sprintf_s (buffer, "%s.do.ovdt",mName.c_str());return (const char*)buffer;}
	/*
	Override for the amount of detail to be drawn.
	0=Full, 1=Bounding Box
	*/
	UnsignedintID getOverrideLevelOfDetail(){char buffer[4096];sprintf_s (buffer, "%s.do.ovlod",mName.c_str());return (const char*)buffer;}
	/*Override of shading state when in shaded display*/
	BoolID getOverrideShading(){char buffer[4096];sprintf_s (buffer, "%s.do.ovs",mName.c_str());return (const char*)buffer;}
	/*Override of texturing state when in shaded display*/
	BoolID getOverrideTexturing(){char buffer[4096];sprintf_s (buffer, "%s.do.ovt",mName.c_str());return (const char*)buffer;}
	/*Override of ability to animate*/
	BoolID getOverridePlayback(){char buffer[4096];sprintf_s (buffer, "%s.do.ovp",mName.c_str());return (const char*)buffer;}
	/*Turn on/off the effect of the sibling attributes*/
	BoolID getOverrideEnabled(){char buffer[4096];sprintf_s (buffer, "%s.do.ove",mName.c_str());return (const char*)buffer;}
	/*Override of the object visibility*/
	BoolID getOverrideVisibility(){char buffer[4096];sprintf_s (buffer, "%s.do.ovv",mName.c_str());return (const char*)buffer;}
	/*
	Override of the object color. Valid range is [0-31].
	A value of zero disables the override.
	*/
	UnsignedcharID getOverrideColor(){char buffer[4096];sprintf_s (buffer, "%s.do.ovc",mName.c_str());return (const char*)buffer;}
	/*
	Override of the object visibility. Used to control visibility
	of objects for level of detail.
	*/
	BoolID getLodVisibility(){char buffer[4096];sprintf_s (buffer, "%s.lodv",mName.c_str());return (const char*)buffer;}
	/*Maya V7 obsolete*/
	RenderInfoID getRenderInfo(){char buffer[4096];sprintf_s (buffer, "%s.ri",mName.c_str());return (const char*)buffer;}
	/*Maya V7 obsolete*/
	ShortID getIdentification(){char buffer[4096];sprintf_s (buffer, "%s.ri.rlid",mName.c_str());return (const char*)buffer;}
	/*Maya V7 obsolete*/
	BoolID getLayerRenderable(){char buffer[4096];sprintf_s (buffer, "%s.ri.rndr",mName.c_str());return (const char*)buffer;}
	/*Maya V7 Obsolete*/
	UnsignedcharID getLayerOverrideColor(){char buffer[4096];sprintf_s (buffer, "%s.ri.lovc",mName.c_str());return (const char*)buffer;}
	/*Parent attribute encapsulating all render override information.*/
	const RenderLayerInfoID& getRenderLayerInfo(size_t rlio_i){char buffer[4096];sprintf_s (buffer, "%s.rlio[%i]",mName.c_str(),rlio_i);return (const char*)buffer;}
	/*Render layer identification number*/
	const ShortID& getRenderLayerId(size_t rlio_i){char buffer[4096];sprintf_s (buffer, "%s.rlio[%i].rli",mName.c_str(),rlio_i);return (const char*)buffer;}
	/*Specifies whether the layer is visible when rendered.*/
	const BoolID& getRenderLayerRenderable(size_t rlio_i){char buffer[4096];sprintf_s (buffer, "%s.rlio[%i].rlr",mName.c_str(),rlio_i);return (const char*)buffer;}
	/*Color with which to draw.*/
	const UnsignedcharID& getRenderLayerColor(size_t rlio_i){char buffer[4096];sprintf_s (buffer, "%s.rlio[%i].rlc",mName.c_str(),rlio_i);return (const char*)buffer;}
	/*
	This attribute specifies how the user wants to specify the frames where the ghosts appear.
	The settings have the following meanings:
	globalPreferences: ghosts are drawn at the steps specified in the Animation Preferences
	customFrames: ghosts are drawn at the frames specified in the ghostFrames attribute
	customFramePrePost: ghosts are drawn at the steps of frame specified in the ghostPrePost attribute
	customKeyPrePost: ghosts are drawn at the steps of key specified in the ghostPrePost attribute
	keyframeRange: ghosts are drawn at the frames within the range where there are keys
	*/
	UnsignedintID getGhostingControl(){char buffer[4096];sprintf_s (buffer, "%s.gc",mName.c_str());return (const char*)buffer;}
	/*
	Attribute which stores the step information for ghosting.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	GhostCustomStepsID getGhostCustomSteps(){char buffer[4096];sprintf_s (buffer, "%s.gcs",mName.c_str());return (const char*)buffer;}
	/*
	The number of ghost steps before the current frame.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	IntID getGhostPreSteps(){char buffer[4096];sprintf_s (buffer, "%s.gcs.gpr",mName.c_str());return (const char*)buffer;}
	/*
	The number of ghost steps after the current frame.
	This value is only used if the ghostingControl is set to customPrePost.
	*/
	IntID getGhostPostSteps(){char buffer[4096];sprintf_s (buffer, "%s.gcs.gps",mName.c_str());return (const char*)buffer;}
	/*
	The number of frames per ghosting step.
	This value is only used if the ghostingControl is set to customFramePrePost or customKeyPrePost.
	*/
	IntID getGhostStepSize(){char buffer[4096];sprintf_s (buffer, "%s.gcs.gss",mName.c_str());return (const char*)buffer;}
	/*
	Specific frames where the ghost will apear.
	This value is only used if the ghostingControl is set to customFrames.
	*/
	IntArrayID getGhostFrames(){char buffer[4096];sprintf_s (buffer, "%s.gf",mName.c_str());return (const char*)buffer;}
	/*
	Start of time range where ghosts on keyframes will appear.
	This value is only used if the ghostingControl is set to keyframeRange.
	*/
	TimeID getGhostRangeStart(){char buffer[4096];sprintf_s (buffer, "%s.grs",mName.c_str());return (const char*)buffer;}
	/*
	End of time range where ghosts on keyframes will appear.
	This value is only used if the ghostingControl is set to keyframeRange.
	*/
	TimeID getGhostRangeEnd(){char buffer[4096];sprintf_s (buffer, "%s.gre",mName.c_str());return (const char*)buffer;}
	/*
	The message attribute determines which dag object's keys will
	be used to display ghosting for this object
	*/
	MessageID getGhostDriver(){char buffer[4096];sprintf_s (buffer, "%s.gdr",mName.c_str());return (const char*)buffer;}
protected:
	DagNode(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Entity(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DAGNODE_H__
