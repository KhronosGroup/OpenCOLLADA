/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHARACTEROFFSET_H__
#define __MayaDM_CHARACTEROFFSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
    As its name suggests, the characterOffset node is designed to add an offset
  to any transform node in your scene. This allows you to, for example, redirect
  a character's walk so that it points in a different direction, or spins around a particular
  point. Typically, the offset will be driven by a control object which provides the
    necessary input values to the tranformOffset node.


</pre></p>
*/
class CharacterOffset : public DependNode
{
public:
public:
	CharacterOffset(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "characterOffset"){}
	virtual ~CharacterOffset(){}
	/*
	Root node's translate value, prior to offset calculation. Normally, this will be connected to
	an output from the character node itself. For example, if the character node
	drives a skeleton with pelvis1 as its root, the pelvis1_translate output values
	will be routed through inRootTranslate so that they can be modified by the
	root offset values.
	*/
	void setInRootTranslate(const double3& rti){fprintf_s(mFile, "setAttr \".rti\" -type \"double3\" ");rti.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Root node's translate value, prior to offset calculation. Normally, this will be connected to
	an output from the character node itself. For example, if the character node
	drives a skeleton with pelvis1 as its root, the pelvis1_translate output values
	will be routed through inRootTranslate so that they can be modified by the
	root offset values.
	*/
	void setInRootTranslate(const Double3ID& rti){fprintf_s(mFile,"connectAttr \"");rti.write(mFile);fprintf_s(mFile,"\" \"%s.rti\";\n",mName.c_str());}
	/*Root node's x-translate value, prior to offset calculation.*/
	void setInRootTranslateX(double rtix){if(rtix == 0) return; fprintf_s(mFile, "setAttr \".rti.rtix\" %f;\n", rtix);}
	/*Root node's x-translate value, prior to offset calculation.*/
	void setInRootTranslateX(const DoubleID& rtix){fprintf_s(mFile,"connectAttr \"");rtix.write(mFile);fprintf_s(mFile,"\" \"%s.rti.rtix\";\n",mName.c_str());}
	/*Root node's y-translate value, prior to offset calculation.*/
	void setInRootTranslateY(double rtiy){if(rtiy == 0) return; fprintf_s(mFile, "setAttr \".rti.rtiy\" %f;\n", rtiy);}
	/*Root node's y-translate value, prior to offset calculation.*/
	void setInRootTranslateY(const DoubleID& rtiy){fprintf_s(mFile,"connectAttr \"");rtiy.write(mFile);fprintf_s(mFile,"\" \"%s.rti.rtiy\";\n",mName.c_str());}
	/*Root node's z-translate value, prior to offset calculation.*/
	void setInRootTranslateZ(double rtiz){if(rtiz == 0) return; fprintf_s(mFile, "setAttr \".rti.rtiz\" %f;\n", rtiz);}
	/*Root node's z-translate value, prior to offset calculation.*/
	void setInRootTranslateZ(const DoubleID& rtiz){fprintf_s(mFile,"connectAttr \"");rtiz.write(mFile);fprintf_s(mFile,"\" \"%s.rti.rtiz\";\n",mName.c_str());}
	/*
	Root node's rotate value, prior to offset calculation. Normally, this will be connected to
	an output from the character node itself. For example, if the character node
	drives a skeleton with pelvis1 as its root, the pelvis1_rotate output values
	will be routed through inRootRotate so that they can be modified by the
	root offset values.
	*/
	void setInRootRotate(const double3& rri){fprintf_s(mFile, "setAttr \".rri\" -type \"double3\" ");rri.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Root node's rotate value, prior to offset calculation. Normally, this will be connected to
	an output from the character node itself. For example, if the character node
	drives a skeleton with pelvis1 as its root, the pelvis1_rotate output values
	will be routed through inRootRotate so that they can be modified by the
	root offset values.
	*/
	void setInRootRotate(const Double3ID& rri){fprintf_s(mFile,"connectAttr \"");rri.write(mFile);fprintf_s(mFile,"\" \"%s.rri\";\n",mName.c_str());}
	/*Root node's x-rotate value, prior to offset calculation.*/
	void setInRootRotateX(double rrix){if(rrix == 0) return; fprintf_s(mFile, "setAttr \".rri.rrix\" %f;\n", rrix);}
	/*Root node's x-rotate value, prior to offset calculation.*/
	void setInRootRotateX(const DoubleID& rrix){fprintf_s(mFile,"connectAttr \"");rrix.write(mFile);fprintf_s(mFile,"\" \"%s.rri.rrix\";\n",mName.c_str());}
	/*Root node's y-rotate value, prior to offset calculation.*/
	void setInRootRotateY(double rriy){if(rriy == 0) return; fprintf_s(mFile, "setAttr \".rri.rriy\" %f;\n", rriy);}
	/*Root node's y-rotate value, prior to offset calculation.*/
	void setInRootRotateY(const DoubleID& rriy){fprintf_s(mFile,"connectAttr \"");rriy.write(mFile);fprintf_s(mFile,"\" \"%s.rri.rriy\";\n",mName.c_str());}
	/*Root node's z-rotate value, prior to offset calculation.*/
	void setInRootRotateZ(double rriz){if(rriz == 0) return; fprintf_s(mFile, "setAttr \".rri.rriz\" %f;\n", rriz);}
	/*Root node's z-rotate value, prior to offset calculation.*/
	void setInRootRotateZ(const DoubleID& rriz){fprintf_s(mFile,"connectAttr \"");rriz.write(mFile);fprintf_s(mFile,"\" \"%s.rri.rriz\";\n",mName.c_str());}
	/*
	The root node's rotate order, which is needed to correctly
	calculate the output rotation for the root.
	*/
	void setRootRotateOrder(unsigned int rror){if(rror == 0) return; fprintf_s(mFile, "setAttr \".rror\" %i;\n", rror);}
	/*
	The root node's rotate order, which is needed to correctly
	calculate the output rotation for the root.
	*/
	void setRootRotateOrder(const UnsignedintID& rror){fprintf_s(mFile,"connectAttr \"");rror.write(mFile);fprintf_s(mFile,"\" \"%s.rror\";\n",mName.c_str());}
	/*Root node's joint orient value.*/
	void setRootJointOrient(const double3& rjo){fprintf_s(mFile, "setAttr \".rjo\" -type \"double3\" ");rjo.write(mFile);fprintf_s(mFile,";\n");}
	/*Root node's joint orient value.*/
	void setRootJointOrient(const Double3ID& rjo){fprintf_s(mFile,"connectAttr \"");rjo.write(mFile);fprintf_s(mFile,"\" \"%s.rjo\";\n",mName.c_str());}
	/*Root node's joint x-orient value.*/
	void setRootJointOrientX(double rjox){if(rjox == 0) return; fprintf_s(mFile, "setAttr \".rjo.rjox\" %f;\n", rjox);}
	/*Root node's joint x-orient value.*/
	void setRootJointOrientX(const DoubleID& rjox){fprintf_s(mFile,"connectAttr \"");rjox.write(mFile);fprintf_s(mFile,"\" \"%s.rjo.rjox\";\n",mName.c_str());}
	/*Root node's joint y-orient value.*/
	void setRootJointOrientY(double rjoy){if(rjoy == 0) return; fprintf_s(mFile, "setAttr \".rjo.rjoy\" %f;\n", rjoy);}
	/*Root node's joint y-orient value.*/
	void setRootJointOrientY(const DoubleID& rjoy){fprintf_s(mFile,"connectAttr \"");rjoy.write(mFile);fprintf_s(mFile,"\" \"%s.rjo.rjoy\";\n",mName.c_str());}
	/*Root node's joint z-orient value.*/
	void setRootJointOrientZ(double rjoz){if(rjoz == 0) return; fprintf_s(mFile, "setAttr \".rjo.rjoz\" %f;\n", rjoz);}
	/*Root node's joint z-orient value.*/
	void setRootJointOrientZ(const DoubleID& rjoz){fprintf_s(mFile,"connectAttr \"");rjoz.write(mFile);fprintf_s(mFile,"\" \"%s.rjo.rjoz\";\n",mName.c_str());}
	/*The root node's parent matrix*/
	void setRootParentMatrix(const matrix& rpm){if(rpm == identity) return; fprintf_s(mFile, "setAttr \".rpm\" -type \"matrix\" ");rpm.write(mFile);fprintf_s(mFile,";\n");}
	/*The root node's parent matrix*/
	void setRootParentMatrix(const MatrixID& rpm){fprintf_s(mFile,"connectAttr \"");rpm.write(mFile);fprintf_s(mFile,"\" \"%s.rpm\";\n",mName.c_str());}
	/*The root node's parent matrix, inverted*/
	void setRootParentInverseMatrix(const matrix& rpim){if(rpim == identity) return; fprintf_s(mFile, "setAttr \".rpim\" -type \"matrix\" ");rpim.write(mFile);fprintf_s(mFile,";\n");}
	/*The root node's parent matrix, inverted*/
	void setRootParentInverseMatrix(const MatrixID& rpim){fprintf_s(mFile,"connectAttr \"");rpim.write(mFile);fprintf_s(mFile,"\" \"%s.rpim\";\n",mName.c_str());}
	/*
	When adding offsets to a transform node, the offset node can look at the parent matrix
	of the offset control object. In most situations, however, this is undesirable. A typical
	situation would be when adding offsets to, say, the shoulder of a character. You'd want to
	parent your offset control object to the character's collar bone so that it follows animation
	above the shoulder. However, if Apply Control Parent Transform is on, the offset will be
	applied multiple times, giving an incorrect offset.
	You should only enable this flag when parenting the control object to something outside of the hierarchy
	of the object it offsets. In this case, the offset will only be applied once.
	*/
	void setApplyControlParentTransform(bool acpx){if(acpx == false) return; fprintf_s(mFile, "setAttr \".acpx\" %i;\n", acpx);}
	/*
	When adding offsets to a transform node, the offset node can look at the parent matrix
	of the offset control object. In most situations, however, this is undesirable. A typical
	situation would be when adding offsets to, say, the shoulder of a character. You'd want to
	parent your offset control object to the character's collar bone so that it follows animation
	above the shoulder. However, if Apply Control Parent Transform is on, the offset will be
	applied multiple times, giving an incorrect offset.
	You should only enable this flag when parenting the control object to something outside of the hierarchy
	of the object it offsets. In this case, the offset will only be applied once.
	*/
	void setApplyControlParentTransform(const BoolID& acpx){fprintf_s(mFile,"connectAttr \"");acpx.write(mFile);fprintf_s(mFile,"\" \"%s.acpx\";\n",mName.c_str());}
	/*
	The offset node is enabled only when this attribute is true. This allows you to bypass the offset to view
	and edit animation without the offset applied to your object.
	*/
	void setEnable(bool nabl){if(nabl == true) return; fprintf_s(mFile, "setAttr \".nabl\" %i;\n", nabl);}
	/*
	The offset node is enabled only when this attribute is true. This allows you to bypass the offset to view
	and edit animation without the offset applied to your object.
	*/
	void setEnable(const BoolID& nabl){fprintf_s(mFile,"connectAttr \"");nabl.write(mFile);fprintf_s(mFile,"\" \"%s.nabl\";\n",mName.c_str());}
	/*
	Root node's translate offset value. This modifies the outRootTranslate value so that
	motion can be redirected. For example, if you had cycled animation of a character walking in
	place and wanted him to do the moonwalk, you could animate the offsetRootTranslateZ value
	so that the overall motion of the character is a slide backwards while stepping forward.
	*/
	void setOffsetRootTranslate(const double3& rtf){fprintf_s(mFile, "setAttr \".rtf\" -type \"double3\" ");rtf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Root node's translate offset value. This modifies the outRootTranslate value so that
	motion can be redirected. For example, if you had cycled animation of a character walking in
	place and wanted him to do the moonwalk, you could animate the offsetRootTranslateZ value
	so that the overall motion of the character is a slide backwards while stepping forward.
	*/
	void setOffsetRootTranslate(const Double3ID& rtf){fprintf_s(mFile,"connectAttr \"");rtf.write(mFile);fprintf_s(mFile,"\" \"%s.rtf\";\n",mName.c_str());}
	/*Root node's x-translate offset value.*/
	void setOffsetRootTranslateX(double rtfx){if(rtfx == 0) return; fprintf_s(mFile, "setAttr \".rtf.rtfx\" %f;\n", rtfx);}
	/*Root node's x-translate offset value.*/
	void setOffsetRootTranslateX(const DoubleID& rtfx){fprintf_s(mFile,"connectAttr \"");rtfx.write(mFile);fprintf_s(mFile,"\" \"%s.rtf.rtfx\";\n",mName.c_str());}
	/*Root node's y-translate offset value.*/
	void setOffsetRootTranslateY(double rtfy){if(rtfy == 0) return; fprintf_s(mFile, "setAttr \".rtf.rtfy\" %f;\n", rtfy);}
	/*Root node's y-translate offset value.*/
	void setOffsetRootTranslateY(const DoubleID& rtfy){fprintf_s(mFile,"connectAttr \"");rtfy.write(mFile);fprintf_s(mFile,"\" \"%s.rtf.rtfy\";\n",mName.c_str());}
	/*Root node's z-translate offset value.*/
	void setOffsetRootTranslateZ(double rtfz){if(rtfz == 0) return; fprintf_s(mFile, "setAttr \".rtf.rtfz\" %f;\n", rtfz);}
	/*Root node's z-translate offset value.*/
	void setOffsetRootTranslateZ(const DoubleID& rtfz){fprintf_s(mFile,"connectAttr \"");rtfz.write(mFile);fprintf_s(mFile,"\" \"%s.rtf.rtfz\";\n",mName.c_str());}
	/*
	The inital position of whatever's driving the translation offset (typically, a
	control object in the scene). The transaltion offset is calculated relative to this position.
	If you're offsetting rotation as well, you should leave these values at their default,
	and instead parent your translation offset control object to your rotation offset control object.
	*/
	void setInitialOffsetRootTranslate(const double3& itf){fprintf_s(mFile, "setAttr \".itf\" -type \"double3\" ");itf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The inital position of whatever's driving the translation offset (typically, a
	control object in the scene). The transaltion offset is calculated relative to this position.
	If you're offsetting rotation as well, you should leave these values at their default,
	and instead parent your translation offset control object to your rotation offset control object.
	*/
	void setInitialOffsetRootTranslate(const Double3ID& itf){fprintf_s(mFile,"connectAttr \"");itf.write(mFile);fprintf_s(mFile,"\" \"%s.itf\";\n",mName.c_str());}
	/*The initial x-coordinate of whatever's driving the translation offset.*/
	void setInitialOffsetRootTranslateX(double itfx){if(itfx == 0) return; fprintf_s(mFile, "setAttr \".itf.itfx\" %f;\n", itfx);}
	/*The initial x-coordinate of whatever's driving the translation offset.*/
	void setInitialOffsetRootTranslateX(const DoubleID& itfx){fprintf_s(mFile,"connectAttr \"");itfx.write(mFile);fprintf_s(mFile,"\" \"%s.itf.itfx\";\n",mName.c_str());}
	/*The initial y-coordinate of whatever's driving the translation offset.*/
	void setInitialOffsetRootTranslateY(double itfy){if(itfy == 0) return; fprintf_s(mFile, "setAttr \".itf.itfy\" %f;\n", itfy);}
	/*The initial y-coordinate of whatever's driving the translation offset.*/
	void setInitialOffsetRootTranslateY(const DoubleID& itfy){fprintf_s(mFile,"connectAttr \"");itfy.write(mFile);fprintf_s(mFile,"\" \"%s.itf.itfy\";\n",mName.c_str());}
	/*The initial z-coordinate of whatever's driving the translation offset.*/
	void setInitialOffsetRootTranslateZ(double itfz){if(itfz == 0) return; fprintf_s(mFile, "setAttr \".itf.itfz\" %f;\n", itfz);}
	/*The initial z-coordinate of whatever's driving the translation offset.*/
	void setInitialOffsetRootTranslateZ(const DoubleID& itfz){fprintf_s(mFile,"connectAttr \"");itfz.write(mFile);fprintf_s(mFile,"\" \"%s.itf.itfz\";\n",mName.c_str());}
	/*
	The scale factor of the rotate control object. Needed to correctly calculate
	the translation offset when the translate control object is parented to the
	rotate control object.
	*/
	void setRotateControlScale(const double3& rcs){fprintf_s(mFile, "setAttr \".rcs\" -type \"double3\" ");rcs.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The scale factor of the rotate control object. Needed to correctly calculate
	the translation offset when the translate control object is parented to the
	rotate control object.
	*/
	void setRotateControlScale(const Double3ID& rcs){fprintf_s(mFile,"connectAttr \"");rcs.write(mFile);fprintf_s(mFile,"\" \"%s.rcs\";\n",mName.c_str());}
	/*The rotate control object's x-scale value.*/
	void setRotateControlScaleX(double rcsx){if(rcsx == 1.0) return; fprintf_s(mFile, "setAttr \".rcs.rcsx\" %f;\n", rcsx);}
	/*The rotate control object's x-scale value.*/
	void setRotateControlScaleX(const DoubleID& rcsx){fprintf_s(mFile,"connectAttr \"");rcsx.write(mFile);fprintf_s(mFile,"\" \"%s.rcs.rcsx\";\n",mName.c_str());}
	/*The rotate control object's y-scale value.*/
	void setRotateControlScaleY(double rcsy){if(rcsy == 1.0) return; fprintf_s(mFile, "setAttr \".rcs.rcsy\" %f;\n", rcsy);}
	/*The rotate control object's y-scale value.*/
	void setRotateControlScaleY(const DoubleID& rcsy){fprintf_s(mFile,"connectAttr \"");rcsy.write(mFile);fprintf_s(mFile,"\" \"%s.rcs.rcsy\";\n",mName.c_str());}
	/*The rotate control object's z-scale value.*/
	void setRotateControlScaleZ(double rcsz){if(rcsz == 1.0) return; fprintf_s(mFile, "setAttr \".rcs.rcsz\" %f;\n", rcsz);}
	/*The rotate control object's z-scale value.*/
	void setRotateControlScaleZ(const DoubleID& rcsz){fprintf_s(mFile,"connectAttr \"");rcsz.write(mFile);fprintf_s(mFile,"\" \"%s.rcs.rcsz\";\n",mName.c_str());}
	/*The rotate control object's parent matrix*/
	void setRotateControlParentMatrix(const matrix& rcpm){if(rcpm == identity) return; fprintf_s(mFile, "setAttr \".rcpm\" -type \"matrix\" ");rcpm.write(mFile);fprintf_s(mFile,";\n");}
	/*The rotate control object's parent matrix*/
	void setRotateControlParentMatrix(const MatrixID& rcpm){fprintf_s(mFile,"connectAttr \"");rcpm.write(mFile);fprintf_s(mFile,"\" \"%s.rcpm\";\n",mName.c_str());}
	/*
	Root node's rotate offset value. This modifies the outRootTranslate and outRootRotate
	values so that the motion of the character can be redirected. For example, if you wanted to
	rotate the character to turn 90 degrees at frame 120, you'd keyframe the offsetRootRotateY
	value to be 90 at this frame.
	*/
	void setOffsetRootRotate(const double3& rrf){fprintf_s(mFile, "setAttr \".rrf\" -type \"double3\" ");rrf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Root node's rotate offset value. This modifies the outRootTranslate and outRootRotate
	values so that the motion of the character can be redirected. For example, if you wanted to
	rotate the character to turn 90 degrees at frame 120, you'd keyframe the offsetRootRotateY
	value to be 90 at this frame.
	*/
	void setOffsetRootRotate(const Double3ID& rrf){fprintf_s(mFile,"connectAttr \"");rrf.write(mFile);fprintf_s(mFile,"\" \"%s.rrf\";\n",mName.c_str());}
	/*Root node's x-rotate offset value.*/
	void setOffsetRootRotateX(double rrfx){if(rrfx == 0) return; fprintf_s(mFile, "setAttr \".rrf.rrfx\" %f;\n", rrfx);}
	/*Root node's x-rotate offset value.*/
	void setOffsetRootRotateX(const DoubleID& rrfx){fprintf_s(mFile,"connectAttr \"");rrfx.write(mFile);fprintf_s(mFile,"\" \"%s.rrf.rrfx\";\n",mName.c_str());}
	/*Root node's y-rotate offset value.*/
	void setOffsetRootRotateY(double rrfy){if(rrfy == 0) return; fprintf_s(mFile, "setAttr \".rrf.rrfy\" %f;\n", rrfy);}
	/*Root node's y-rotate offset value.*/
	void setOffsetRootRotateY(const DoubleID& rrfy){fprintf_s(mFile,"connectAttr \"");rrfy.write(mFile);fprintf_s(mFile,"\" \"%s.rrf.rrfy\";\n",mName.c_str());}
	/*Root node's z-rotate offset value.*/
	void setOffsetRootRotateZ(double rrfz){if(rrfz == 0) return; fprintf_s(mFile, "setAttr \".rrf.rrfz\" %f;\n", rrfz);}
	/*Root node's z-rotate offset value.*/
	void setOffsetRootRotateZ(const DoubleID& rrfz){fprintf_s(mFile,"connectAttr \"");rrfz.write(mFile);fprintf_s(mFile,"\" \"%s.rrf.rrfz\";\n",mName.c_str());}
	/*The order in which the rotatation offsets are to be be applied.*/
	void setOffsetRootRotateOrder(unsigned int rfor){if(rfor == 0) return; fprintf_s(mFile, "setAttr \".rfor\" %i;\n", rfor);}
	/*The order in which the rotatation offsets are to be be applied.*/
	void setOffsetRootRotateOrder(const UnsignedintID& rfor){fprintf_s(mFile,"connectAttr \"");rfor.write(mFile);fprintf_s(mFile,"\" \"%s.rfor\";\n",mName.c_str());}
	/*
	The point around which the rotational offset pivots. This modifies the outRootRotate and
	outRootTranslate values so that motion can be redirected. For example, if you wanted to
	pivot around the character's foot, you'd move the pivot point to this location and rotate
	the character around it.
	*/
	void setOffsetRootRotatePivot(const double3& rpf){fprintf_s(mFile, "setAttr \".rpf\" -type \"double3\" ");rpf.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The point around which the rotational offset pivots. This modifies the outRootRotate and
	outRootTranslate values so that motion can be redirected. For example, if you wanted to
	pivot around the character's foot, you'd move the pivot point to this location and rotate
	the character around it.
	*/
	void setOffsetRootRotatePivot(const Double3ID& rpf){fprintf_s(mFile,"connectAttr \"");rpf.write(mFile);fprintf_s(mFile,"\" \"%s.rpf\";\n",mName.c_str());}
	/*Root node's x-translate offset value.*/
	void setOffsetRootRotatePivotX(double rppfx){if(rppfx == 0) return; fprintf_s(mFile, "setAttr \".rpf.rppfx\" %f;\n", rppfx);}
	/*Root node's x-translate offset value.*/
	void setOffsetRootRotatePivotX(const DoubleID& rppfx){fprintf_s(mFile,"connectAttr \"");rppfx.write(mFile);fprintf_s(mFile,"\" \"%s.rpf.rppfx\";\n",mName.c_str());}
	/*Root node's y-translate offset value.*/
	void setOffsetRootRotatePivotY(double rppfy){if(rppfy == 0) return; fprintf_s(mFile, "setAttr \".rpf.rppfy\" %f;\n", rppfy);}
	/*Root node's y-translate offset value.*/
	void setOffsetRootRotatePivotY(const DoubleID& rppfy){fprintf_s(mFile,"connectAttr \"");rppfy.write(mFile);fprintf_s(mFile,"\" \"%s.rpf.rppfy\";\n",mName.c_str());}
	/*Root node's z-translate offset value.*/
	void setOffsetRootRotatePivotZ(double rppfz){if(rppfz == 0) return; fprintf_s(mFile, "setAttr \".rpf.rppfz\" %f;\n", rppfz);}
	/*Root node's z-translate offset value.*/
	void setOffsetRootRotatePivotZ(const DoubleID& rppfz){fprintf_s(mFile,"connectAttr \"");rppfz.write(mFile);fprintf_s(mFile,"\" \"%s.rpf.rppfz\";\n",mName.c_str());}
	/*Root node's final translate value, having been modified by the rotate and translate offset values.*/
	void setOutRootTranslate(const Double3ID& rto){fprintf_s(mFile,"connectAttr \"");rto.write(mFile);fprintf_s(mFile,"\" \"%s.rto\";\n",mName.c_str());}
	/*Root node's final x-translate value.*/
	void setOutRootTranslateX(const DoubleID& rtox){fprintf_s(mFile,"connectAttr \"");rtox.write(mFile);fprintf_s(mFile,"\" \"%s.rto.rtox\";\n",mName.c_str());}
	/*Root node's final y-translate value.*/
	void setOutRootTranslateY(const DoubleID& rtoy){fprintf_s(mFile,"connectAttr \"");rtoy.write(mFile);fprintf_s(mFile,"\" \"%s.rto.rtoy\";\n",mName.c_str());}
	/*Root node's final z-translate value.*/
	void setOutRootTranslateZ(const DoubleID& rtoz){fprintf_s(mFile,"connectAttr \"");rtoz.write(mFile);fprintf_s(mFile,"\" \"%s.rto.rtoz\";\n",mName.c_str());}
	/*Root node's final  rotate value, having been modified by the rotate and translate offset values.*/
	void setOutRootRotate(const Double3ID& rro){fprintf_s(mFile,"connectAttr \"");rro.write(mFile);fprintf_s(mFile,"\" \"%s.rro\";\n",mName.c_str());}
	/*Root node's final x-rotate value.*/
	void setOutRootRotateX(const DoubleID& rrox){fprintf_s(mFile,"connectAttr \"");rrox.write(mFile);fprintf_s(mFile,"\" \"%s.rro.rrox\";\n",mName.c_str());}
	/*Root node's final y-rotate value.*/
	void setOutRootRotateY(const DoubleID& rroy){fprintf_s(mFile,"connectAttr \"");rroy.write(mFile);fprintf_s(mFile,"\" \"%s.rro.rroy\";\n",mName.c_str());}
	/*Root node's final z-rotate value.*/
	void setOutRootRotateZ(const DoubleID& rroz){fprintf_s(mFile,"connectAttr \"");rroz.write(mFile);fprintf_s(mFile,"\" \"%s.rro.rroz\";\n",mName.c_str());}
	/*
	Root node's translate value, prior to offset calculation. Normally, this will be connected to
	an output from the character node itself. For example, if the character node
	drives a skeleton with pelvis1 as its root, the pelvis1_translate output values
	will be routed through inRootTranslate so that they can be modified by the
	root offset values.
	*/
	Double3ID getInRootTranslate(){char buffer[4096];sprintf_s (buffer, "%s.rti",mName.c_str());return (const char*)buffer;}
	/*Root node's x-translate value, prior to offset calculation.*/
	DoubleID getInRootTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.rti.rtix",mName.c_str());return (const char*)buffer;}
	/*Root node's y-translate value, prior to offset calculation.*/
	DoubleID getInRootTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.rti.rtiy",mName.c_str());return (const char*)buffer;}
	/*Root node's z-translate value, prior to offset calculation.*/
	DoubleID getInRootTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.rti.rtiz",mName.c_str());return (const char*)buffer;}
	/*
	Root node's rotate value, prior to offset calculation. Normally, this will be connected to
	an output from the character node itself. For example, if the character node
	drives a skeleton with pelvis1 as its root, the pelvis1_rotate output values
	will be routed through inRootRotate so that they can be modified by the
	root offset values.
	*/
	Double3ID getInRootRotate(){char buffer[4096];sprintf_s (buffer, "%s.rri",mName.c_str());return (const char*)buffer;}
	/*Root node's x-rotate value, prior to offset calculation.*/
	DoubleID getInRootRotateX(){char buffer[4096];sprintf_s (buffer, "%s.rri.rrix",mName.c_str());return (const char*)buffer;}
	/*Root node's y-rotate value, prior to offset calculation.*/
	DoubleID getInRootRotateY(){char buffer[4096];sprintf_s (buffer, "%s.rri.rriy",mName.c_str());return (const char*)buffer;}
	/*Root node's z-rotate value, prior to offset calculation.*/
	DoubleID getInRootRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.rri.rriz",mName.c_str());return (const char*)buffer;}
	/*
	The root node's rotate order, which is needed to correctly
	calculate the output rotation for the root.
	*/
	UnsignedintID getRootRotateOrder(){char buffer[4096];sprintf_s (buffer, "%s.rror",mName.c_str());return (const char*)buffer;}
	/*Root node's joint orient value.*/
	Double3ID getRootJointOrient(){char buffer[4096];sprintf_s (buffer, "%s.rjo",mName.c_str());return (const char*)buffer;}
	/*Root node's joint x-orient value.*/
	DoubleID getRootJointOrientX(){char buffer[4096];sprintf_s (buffer, "%s.rjo.rjox",mName.c_str());return (const char*)buffer;}
	/*Root node's joint y-orient value.*/
	DoubleID getRootJointOrientY(){char buffer[4096];sprintf_s (buffer, "%s.rjo.rjoy",mName.c_str());return (const char*)buffer;}
	/*Root node's joint z-orient value.*/
	DoubleID getRootJointOrientZ(){char buffer[4096];sprintf_s (buffer, "%s.rjo.rjoz",mName.c_str());return (const char*)buffer;}
	/*The root node's parent matrix*/
	MatrixID getRootParentMatrix(){char buffer[4096];sprintf_s (buffer, "%s.rpm",mName.c_str());return (const char*)buffer;}
	/*The root node's parent matrix, inverted*/
	MatrixID getRootParentInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.rpim",mName.c_str());return (const char*)buffer;}
	/*
	When adding offsets to a transform node, the offset node can look at the parent matrix
	of the offset control object. In most situations, however, this is undesirable. A typical
	situation would be when adding offsets to, say, the shoulder of a character. You'd want to
	parent your offset control object to the character's collar bone so that it follows animation
	above the shoulder. However, if Apply Control Parent Transform is on, the offset will be
	applied multiple times, giving an incorrect offset.
	You should only enable this flag when parenting the control object to something outside of the hierarchy
	of the object it offsets. In this case, the offset will only be applied once.
	*/
	BoolID getApplyControlParentTransform(){char buffer[4096];sprintf_s (buffer, "%s.acpx",mName.c_str());return (const char*)buffer;}
	/*
	The offset node is enabled only when this attribute is true. This allows you to bypass the offset to view
	and edit animation without the offset applied to your object.
	*/
	BoolID getEnable(){char buffer[4096];sprintf_s (buffer, "%s.nabl",mName.c_str());return (const char*)buffer;}
	/*
	Root node's translate offset value. This modifies the outRootTranslate value so that
	motion can be redirected. For example, if you had cycled animation of a character walking in
	place and wanted him to do the moonwalk, you could animate the offsetRootTranslateZ value
	so that the overall motion of the character is a slide backwards while stepping forward.
	*/
	Double3ID getOffsetRootTranslate(){char buffer[4096];sprintf_s (buffer, "%s.rtf",mName.c_str());return (const char*)buffer;}
	/*Root node's x-translate offset value.*/
	DoubleID getOffsetRootTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.rtf.rtfx",mName.c_str());return (const char*)buffer;}
	/*Root node's y-translate offset value.*/
	DoubleID getOffsetRootTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.rtf.rtfy",mName.c_str());return (const char*)buffer;}
	/*Root node's z-translate offset value.*/
	DoubleID getOffsetRootTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.rtf.rtfz",mName.c_str());return (const char*)buffer;}
	/*
	The inital position of whatever's driving the translation offset (typically, a
	control object in the scene). The transaltion offset is calculated relative to this position.
	If you're offsetting rotation as well, you should leave these values at their default,
	and instead parent your translation offset control object to your rotation offset control object.
	*/
	Double3ID getInitialOffsetRootTranslate(){char buffer[4096];sprintf_s (buffer, "%s.itf",mName.c_str());return (const char*)buffer;}
	/*The initial x-coordinate of whatever's driving the translation offset.*/
	DoubleID getInitialOffsetRootTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.itf.itfx",mName.c_str());return (const char*)buffer;}
	/*The initial y-coordinate of whatever's driving the translation offset.*/
	DoubleID getInitialOffsetRootTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.itf.itfy",mName.c_str());return (const char*)buffer;}
	/*The initial z-coordinate of whatever's driving the translation offset.*/
	DoubleID getInitialOffsetRootTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.itf.itfz",mName.c_str());return (const char*)buffer;}
	/*
	The scale factor of the rotate control object. Needed to correctly calculate
	the translation offset when the translate control object is parented to the
	rotate control object.
	*/
	Double3ID getRotateControlScale(){char buffer[4096];sprintf_s (buffer, "%s.rcs",mName.c_str());return (const char*)buffer;}
	/*The rotate control object's x-scale value.*/
	DoubleID getRotateControlScaleX(){char buffer[4096];sprintf_s (buffer, "%s.rcs.rcsx",mName.c_str());return (const char*)buffer;}
	/*The rotate control object's y-scale value.*/
	DoubleID getRotateControlScaleY(){char buffer[4096];sprintf_s (buffer, "%s.rcs.rcsy",mName.c_str());return (const char*)buffer;}
	/*The rotate control object's z-scale value.*/
	DoubleID getRotateControlScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.rcs.rcsz",mName.c_str());return (const char*)buffer;}
	/*The rotate control object's parent matrix*/
	MatrixID getRotateControlParentMatrix(){char buffer[4096];sprintf_s (buffer, "%s.rcpm",mName.c_str());return (const char*)buffer;}
	/*
	Root node's rotate offset value. This modifies the outRootTranslate and outRootRotate
	values so that the motion of the character can be redirected. For example, if you wanted to
	rotate the character to turn 90 degrees at frame 120, you'd keyframe the offsetRootRotateY
	value to be 90 at this frame.
	*/
	Double3ID getOffsetRootRotate(){char buffer[4096];sprintf_s (buffer, "%s.rrf",mName.c_str());return (const char*)buffer;}
	/*Root node's x-rotate offset value.*/
	DoubleID getOffsetRootRotateX(){char buffer[4096];sprintf_s (buffer, "%s.rrf.rrfx",mName.c_str());return (const char*)buffer;}
	/*Root node's y-rotate offset value.*/
	DoubleID getOffsetRootRotateY(){char buffer[4096];sprintf_s (buffer, "%s.rrf.rrfy",mName.c_str());return (const char*)buffer;}
	/*Root node's z-rotate offset value.*/
	DoubleID getOffsetRootRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.rrf.rrfz",mName.c_str());return (const char*)buffer;}
	/*The order in which the rotatation offsets are to be be applied.*/
	UnsignedintID getOffsetRootRotateOrder(){char buffer[4096];sprintf_s (buffer, "%s.rfor",mName.c_str());return (const char*)buffer;}
	/*
	The point around which the rotational offset pivots. This modifies the outRootRotate and
	outRootTranslate values so that motion can be redirected. For example, if you wanted to
	pivot around the character's foot, you'd move the pivot point to this location and rotate
	the character around it.
	*/
	Double3ID getOffsetRootRotatePivot(){char buffer[4096];sprintf_s (buffer, "%s.rpf",mName.c_str());return (const char*)buffer;}
	/*Root node's x-translate offset value.*/
	DoubleID getOffsetRootRotatePivotX(){char buffer[4096];sprintf_s (buffer, "%s.rpf.rppfx",mName.c_str());return (const char*)buffer;}
	/*Root node's y-translate offset value.*/
	DoubleID getOffsetRootRotatePivotY(){char buffer[4096];sprintf_s (buffer, "%s.rpf.rppfy",mName.c_str());return (const char*)buffer;}
	/*Root node's z-translate offset value.*/
	DoubleID getOffsetRootRotatePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.rpf.rppfz",mName.c_str());return (const char*)buffer;}
	/*Root node's final translate value, having been modified by the rotate and translate offset values.*/
	Double3ID getOutRootTranslate(){char buffer[4096];sprintf_s (buffer, "%s.rto",mName.c_str());return (const char*)buffer;}
	/*Root node's final x-translate value.*/
	DoubleID getOutRootTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.rto.rtox",mName.c_str());return (const char*)buffer;}
	/*Root node's final y-translate value.*/
	DoubleID getOutRootTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.rto.rtoy",mName.c_str());return (const char*)buffer;}
	/*Root node's final z-translate value.*/
	DoubleID getOutRootTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.rto.rtoz",mName.c_str());return (const char*)buffer;}
	/*Root node's final  rotate value, having been modified by the rotate and translate offset values.*/
	Double3ID getOutRootRotate(){char buffer[4096];sprintf_s (buffer, "%s.rro",mName.c_str());return (const char*)buffer;}
	/*Root node's final x-rotate value.*/
	DoubleID getOutRootRotateX(){char buffer[4096];sprintf_s (buffer, "%s.rro.rrox",mName.c_str());return (const char*)buffer;}
	/*Root node's final y-rotate value.*/
	DoubleID getOutRootRotateY(){char buffer[4096];sprintf_s (buffer, "%s.rro.rroy",mName.c_str());return (const char*)buffer;}
	/*Root node's final z-rotate value.*/
	DoubleID getOutRootRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.rro.rroz",mName.c_str());return (const char*)buffer;}
protected:
	CharacterOffset(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CHARACTEROFFSET_H__
