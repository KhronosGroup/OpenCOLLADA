/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKHANDLE_H__
#define __MayaDM_IKHANDLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
The ikHandle node represents the goal of the skeleton. An
        ikSolver takes the goal information (position and orientation) to find
        the IK solution for the skeleton.<p/>

        An ikHandle node has the skeleton information, the start joint (joint)
        and the end-effector (ikEffector) of that skeleton. From these two ends,
        the ikHandle node knows the whole skeleton chain, for example, all the
        degrees of freedom (DOF).<p/>

        There are several kinds of ikHandle nodes, depending on what ikSolver they
        use. If the ikHandle node uses an ikRPsolver or ikSCsolver, it is a single
        chain handle. If it uses an ikSplineSolver, it is an IK spline handle.
        These different IK  handles have different behavior which is determined by
        the IK solver.<p/>

        A single chain handle is created with the IK handle tool, and an IK spline
        handle with the IK spline handle tool. They can also be created with the
        ikHandle command. When an ikHandle node has been created, it is connected
        with the start joint and the end-effector of the skeleton chain, and also
        connected with the given ikSolver node through three attributes, startJoint,
        endEffector, and ikSolver. Then it becomes a valid ikHandle and is added
        into a global list of ikHandle nodes in the ikSystem node.<p/>

        There are also other attributes that determine how this ikHandle node is
        involved in an IK solution.<p/>

        The ikBlend attribute determines whether the joints spanned by the ikHandle
        are solved by pure IK, pure FK (joint rotations), or a blend of the two.
  An ikBlend of 1.0 specifies pure IK. An ikBlend of 0.0 specifies pure FK.
  Values between 0 and 1 are blended. The default value is 1.0.
  Prior to version 5.0 of Maya, the ikBlend attribute
  was called "solverEnable".<p/>

        The snapEnable attribute allows the ikHandle node to be snapped back
        to the end-effector position and orientation if it is on. The default
        is on.<p/>

        The stickiness attribute is an enum attribute. It works in the interactive
        mode. If it is set to 'sticky', the IK solution should be calculated when
        translating the root of the skeleton. The default is off.<p/>

        The priority attribute represents an order in which this ikHandle node gets
        solved. It also determines how ikHandle nodes will be grouped. The ikHandle
        node with the smaller priority value will be solved earlier than higher.
        If auto-priority is on when creating an ikHandle node, the priority is set
        to the depth of start joint in the hierarchy. The default priority is 1.<p/>

        The weight attribute determines how much this ikHandle node affects
        the IK solution. This attribute does not affect the ik solution for single
        chain and spline ikHandle nodes. The default value is 1.0.<p/>

        The poWeight attribute is a balance weight value of position/orientation.
        It is used to determine how the position/orientation of this ikHandle node
        affects the IK solution. If it is 1.0, only position information of the
        ikHandle node contributes to the IK solution. If it is 0.0, only the
        orientation is taken into account to compute the IK solution. This
        attribute does not affect the ik solution for single chain and spline
        ikHandle nodes either. The default value is 1.0.<p/>

        The poleVector attribute is a special control for an ikHandle node which
        uses an ikRPsolver (see the documentation for the ikRPsolver node). The
        default value is the Z-axis (0.0 0.0 1.0).<p/>

        The twist attribute determines the twist value of the
        ikRPhandle or ikSplineHandle.  For the ikSplineHandle, the twist value
        determines how much to twist the joint chain from the end. (For the ikRPhandle,
        see the documentation for the ikRPsolver node).  The default value is 0.0.<p/>

        The following attributes are specific to the ikSplineSolver.
        See the documentation for the ikSplineSolver node for more details.<p/>

        The inCurve attribute is an input curve which is used to determine where
        to place and how to orient the joints.<p/>

        The rootOnCurve attribute determines if the root joint is constrained
        to be on the curve.<p/>

        The offset attribute determines how much to offset the root joint
        along the curve. The offset value is used only when the attribute
        rootOnCurve is set. The default value is 0.0.<p/>

        The roll attribute determines how much to roll the root joint.
        All subsequent joints are rolled as well. The default value is 0.0.<p/>

        The twistType attribute is an enum attribute which determines how
        to distribute the twist along the joints.  There are four twist types:
        linear, easeIn, easeOut and easeInOut. The default type is linear.<p/>

        The rootTwistMode attribute indicates whether the start joint is allowed to
        twist or not. If not, then the required twist is distributed over the
        remaining joints. This applies to all the twist types.
*/
class IkHandle : public Transform
{
public:
public:
	IkHandle(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "ikHandle"){}
	virtual ~IkHandle(){}
	/*The IK handle's start joint.*/
	void setStartJoint(const MessageID& hsj){fprintf_s(mFile,"connectAttr \"");hsj.write(mFile);fprintf_s(mFile,"\" \"%s.hsj\";\n",mName.c_str());}
	/*The IK handle's end effector.*/
	void setEndEffector(const MessageID& hee){fprintf_s(mFile,"connectAttr \"");hee.write(mFile);fprintf_s(mFile,"\" \"%s.hee\";\n",mName.c_str());}
	/*The IK solver used by the IK handle.*/
	void setIkSolver(const MessageID& hsv){fprintf_s(mFile,"connectAttr \"");hsv.write(mFile);fprintf_s(mFile,"\" \"%s.hsv\";\n",mName.c_str());}
	/*Indicates whether the IK handle may be snapped or not.*/
	void setSnapEnable(bool hsh){if(hsh == true) return; fprintf_s(mFile, "setAttr \".hsh\" %i;\n", hsh);}
	/*Indicates whether the IK handle may be snapped or not.*/
	void setSnapEnable(const BoolID& hsh){fprintf_s(mFile,"connectAttr \"");hsh.write(mFile);fprintf_s(mFile,"\" \"%s.hsh\";\n",mName.c_str());}
	/*Indicates whether stickiness is enabled for the IK handle or not.*/
	void setStickiness(unsigned int hs){if(hs == 0) return; fprintf_s(mFile, "setAttr \".hs\" %i;\n", hs);}
	/*Indicates whether stickiness is enabled for the IK handle or not.*/
	void setStickiness(const UnsignedintID& hs){fprintf_s(mFile,"connectAttr \"");hs.write(mFile);fprintf_s(mFile,"\" \"%s.hs\";\n",mName.c_str());}
	/*The IK handle's priority value for grouping.*/
	void setPriority(int hpr){if(hpr == 1) return; fprintf_s(mFile, "setAttr \".hpr\" %i;\n", hpr);}
	/*The IK handle's priority value for grouping.*/
	void setPriority(const IntID& hpr){fprintf_s(mFile,"connectAttr \"");hpr.write(mFile);fprintf_s(mFile,"\" \"%s.hpr\";\n",mName.c_str());}
	/*Determine how much this IK handle affects the IK solution.*/
	void setWeight(double hw){if(hw == 1.0) return; fprintf_s(mFile, "setAttr \".hw\" %f;\n", hw);}
	/*Determine how much this IK handle affects the IK solution.*/
	void setWeight(const DoubleID& hw){fprintf_s(mFile,"connectAttr \"");hw.write(mFile);fprintf_s(mFile,"\" \"%s.hw\";\n",mName.c_str());}
	/*Determine how position/orientation affects IK solution.*/
	void setPoWeight(double hpo){if(hpo == 1.0) return; fprintf_s(mFile, "setAttr \".hpo\" %f;\n", hpo);}
	/*Determine how position/orientation affects IK solution.*/
	void setPoWeight(const DoubleID& hpo){fprintf_s(mFile,"connectAttr \"");hpo.write(mFile);fprintf_s(mFile,"\" \"%s.hpo\";\n",mName.c_str());}
	/*Pole vector used by ikRPsolver to adjust the IK solution.*/
	void setPoleVector(const double3& pv){fprintf_s(mFile, "setAttr \".pv\" -type \"double3\" ");pv.write(mFile);fprintf_s(mFile,";\n");}
	/*Pole vector used by ikRPsolver to adjust the IK solution.*/
	void setPoleVector(const Double3ID& pv){fprintf_s(mFile,"connectAttr \"");pv.write(mFile);fprintf_s(mFile,"\" \"%s.pv\";\n",mName.c_str());}
	/*X component of the pole vector.*/
	void setPoleVectorX(double pvx){if(pvx == 0.0) return; fprintf_s(mFile, "setAttr \".pv.pvx\" %f;\n", pvx);}
	/*X component of the pole vector.*/
	void setPoleVectorX(const DoubleID& pvx){fprintf_s(mFile,"connectAttr \"");pvx.write(mFile);fprintf_s(mFile,"\" \"%s.pv.pvx\";\n",mName.c_str());}
	/*Y component of the pole vector.*/
	void setPoleVectorY(double pvy){if(pvy == 0.0) return; fprintf_s(mFile, "setAttr \".pv.pvy\" %f;\n", pvy);}
	/*Y component of the pole vector.*/
	void setPoleVectorY(const DoubleID& pvy){fprintf_s(mFile,"connectAttr \"");pvy.write(mFile);fprintf_s(mFile,"\" \"%s.pv.pvy\";\n",mName.c_str());}
	/*Z component of the pole vector.*/
	void setPoleVectorZ(double pvz){if(pvz == 1.0) return; fprintf_s(mFile, "setAttr \".pv.pvz\" %f;\n", pvz);}
	/*Z component of the pole vector.*/
	void setPoleVectorZ(const DoubleID& pvz){fprintf_s(mFile,"connectAttr \"");pvz.write(mFile);fprintf_s(mFile,"\" \"%s.pv.pvz\";\n",mName.c_str());}
	/*The IK spline handle's input curve.*/
	void setInCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*The ikSplineHandle's offset along the curve.*/
	void setOffset(double off){if(off == 0.0) return; fprintf_s(mFile, "setAttr \".off\" %f;\n", off);}
	/*The ikSplineHandle's offset along the curve.*/
	void setOffset(const DoubleID& off){fprintf_s(mFile,"connectAttr \"");off.write(mFile);fprintf_s(mFile,"\" \"%s.off\";\n",mName.c_str());}
	/*The ikSplineHandle's roll.*/
	void setRoll(double rol){if(rol == 0) return; fprintf_s(mFile, "setAttr \".rol\" %f;\n", rol);}
	/*The ikSplineHandle's roll.*/
	void setRoll(const DoubleID& rol){fprintf_s(mFile,"connectAttr \"");rol.write(mFile);fprintf_s(mFile,"\" \"%s.rol\";\n",mName.c_str());}
	/*The twist for both the IK spline handle and the IK RP handle.*/
	void setTwist(double twi){if(twi == 0) return; fprintf_s(mFile, "setAttr \".twi\" %f;\n", twi);}
	/*The twist for both the IK spline handle and the IK RP handle.*/
	void setTwist(const DoubleID& twi){fprintf_s(mFile,"connectAttr \"");twi.write(mFile);fprintf_s(mFile,"\" \"%s.twi\";\n",mName.c_str());}
	/*Indicates if the IK spline handle's root joint is constrained to the curve.*/
	void setRootOnCurve(bool roc){if(roc == false) return; fprintf_s(mFile, "setAttr \".roc\" %i;\n", roc);}
	/*Indicates if the IK spline handle's root joint is constrained to the curve.*/
	void setRootOnCurve(const BoolID& roc){fprintf_s(mFile,"connectAttr \"");roc.write(mFile);fprintf_s(mFile,"\" \"%s.roc\";\n",mName.c_str());}
	/*The IK spline handle's twist interpolation type. The following are legal values: 0=Linear, 1=EaseIn, 2=EaseOut, 3=EaseInOut.*/
	void setTwistType(unsigned int twt){if(twt == 0) return; fprintf_s(mFile, "setAttr \".twt\" %i;\n", twt);}
	/*The IK spline handle's twist interpolation type. The following are legal values: 0=Linear, 1=EaseIn, 2=EaseOut, 3=EaseInOut.*/
	void setTwistType(const UnsignedintID& twt){fprintf_s(mFile,"connectAttr \"");twt.write(mFile);fprintf_s(mFile,"\" \"%s.twt\";\n",mName.c_str());}
	/*
	This attribute indicates whether the start joint is allowed to
	twist or not. If not, then the required twist is distributed over the
	remaining joints. This applies to all the twist types.
	*/
	void setRootTwistMode(bool rtm){if(rtm == false) return; fprintf_s(mFile, "setAttr \".rtm\" %i;\n", rtm);}
	/*
	This attribute indicates whether the start joint is allowed to
	twist or not. If not, then the required twist is distributed over the
	remaining joints. This applies to all the twist types.
	*/
	void setRootTwistMode(const BoolID& rtm){fprintf_s(mFile,"connectAttr \"");rtm.write(mFile);fprintf_s(mFile,"\" \"%s.rtm\";\n",mName.c_str());}
	/*
	Indicates whether or not the solver is invoked for the IK handle.
	A value of 1.0 means the solver is invoked.
	A value of 0.0 means the solver is not invoked.
	Values between 0 and 1 indicate that the solver result will be
	blended with fk connections on the joints.
	*/
	void setIkBlend(double ikb){if(ikb == 1.0) return; fprintf_s(mFile, "setAttr \".ikb\" %f;\n", ikb);}
	/*
	Indicates whether or not the solver is invoked for the IK handle.
	A value of 1.0 means the solver is invoked.
	A value of 0.0 means the solver is not invoked.
	Values between 0 and 1 indicate that the solver result will be
	blended with fk connections on the joints.
	*/
	void setIkBlend(const DoubleID& ikb){fprintf_s(mFile,"connectAttr \"");ikb.write(mFile);fprintf_s(mFile,"\" \"%s.ikb\";\n",mName.c_str());}
	/*
	Enables ik blend controls: snapping is disabled, and
	joints can be rotated even when there are keys on the handle.
	When true, this attribute overrides the global ik blend setting.
	*/
	void setIkFkManipulation(bool eik){if(eik == false) return; fprintf_s(mFile, "setAttr \".eik\" %i;\n", eik);}
	/*
	Enables ik blend controls: snapping is disabled, and
	joints can be rotated even when there are keys on the handle.
	When true, this attribute overrides the global ik blend setting.
	*/
	void setIkFkManipulation(const BoolID& eik){fprintf_s(mFile,"connectAttr \"");eik.write(mFile);fprintf_s(mFile,"\" \"%s.eik\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	The type of up-vector constraint used to twist joints
	in the chain.  Legal values are 0=Scene Up, 1=Object Up,
	2=Object Up (Start/End), 3=Object Rotation Up,
	4=Object Rotation Up (Start/End), 5=Vector,
	6=Vector (Start/End), 7=Relative
	*/
	void setDWorldUpType(unsigned int dwut){if(dwut == 0) return; fprintf_s(mFile, "setAttr \".dwut\" %i;\n", dwut);}
	/*
	Applies to Spline IK Handles only.
	The type of up-vector constraint used to twist joints
	in the chain.  Legal values are 0=Scene Up, 1=Object Up,
	2=Object Up (Start/End), 3=Object Rotation Up,
	4=Object Rotation Up (Start/End), 5=Vector,
	6=Vector (Start/End), 7=Relative
	*/
	void setDWorldUpType(const UnsignedintID& dwut){fprintf_s(mFile,"connectAttr \"");dwut.write(mFile);fprintf_s(mFile,"\" \"%s.dwut\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Determines which of the joints local axes will
	be aligned with the up vector when an up vector
	is in use.  The positive or negative Y or Z axes
	can be selected, or the "closest" of one of those
	axes (meaning whichever of the positive or negative
	axes is closest to the up vector).  The X-axes are
	not available, since the joint x-axis always points
	along the spline.  Joint twisting happens about this
	axis.  "Closest Y" and "Closest Z" modes are useful
	for joint chains that have been constructed with their
	local axes flipped every few joints.  These settings
	are not recommended for animation, as they are prone to
	flipping as the chain moves.
	*/
	void setDWorldUpAxis(unsigned int dwua){if(dwua == 0) return; fprintf_s(mFile, "setAttr \".dwua\" %i;\n", dwua);}
	/*
	Applies to Spline IK Handles only.
	Determines which of the joints local axes will
	be aligned with the up vector when an up vector
	is in use.  The positive or negative Y or Z axes
	can be selected, or the "closest" of one of those
	axes (meaning whichever of the positive or negative
	axes is closest to the up vector).  The X-axes are
	not available, since the joint x-axis always points
	along the spline.  Joint twisting happens about this
	axis.  "Closest Y" and "Closest Z" modes are useful
	for joint chains that have been constructed with their
	local axes flipped every few joints.  These settings
	are not recommended for animation, as they are prone to
	flipping as the chain moves.
	*/
	void setDWorldUpAxis(const UnsignedintID& dwua){fprintf_s(mFile,"connectAttr \"");dwua.write(mFile);fprintf_s(mFile,"\" \"%s.dwua\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Joints will twist to make one of their local axes
	align as best as possible with this vector.  If the
	World Up Type value is Vector, then this value
	specifies a worldspace vector.  For Object Rotation
	mode, this value specifies a vector in the local
	space of the target object specified by the World Up
	Object attribute.  If the World Up Type is either
	Vector (Start/End) or Object Rotation Up (Start/End),
	then the vector applies to the start joint in the
	chain, and is interpolated with the World Up Vector End
	value that is specified for the end joint in the chain.
	Otherwise, this value is used for every joint in the
	chain.
	*/
	void setDWorldUpVector(const double3& dwuv){fprintf_s(mFile, "setAttr \".dwuv\" -type \"double3\" ");dwuv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Applies to Spline IK Handles only.
	Joints will twist to make one of their local axes
	align as best as possible with this vector.  If the
	World Up Type value is Vector, then this value
	specifies a worldspace vector.  For Object Rotation
	mode, this value specifies a vector in the local
	space of the target object specified by the World Up
	Object attribute.  If the World Up Type is either
	Vector (Start/End) or Object Rotation Up (Start/End),
	then the vector applies to the start joint in the
	chain, and is interpolated with the World Up Vector End
	value that is specified for the end joint in the chain.
	Otherwise, this value is used for every joint in the
	chain.
	*/
	void setDWorldUpVector(const Double3ID& dwuv){fprintf_s(mFile,"connectAttr \"");dwuv.write(mFile);fprintf_s(mFile,"\" \"%s.dwuv\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	X component of the up vector
	*/
	void setDWorldUpVectorX(double dwux){if(dwux == 0.0) return; fprintf_s(mFile, "setAttr \".dwuv.dwux\" %f;\n", dwux);}
	/*
	Applies to Spline IK Handles only.
	X component of the up vector
	*/
	void setDWorldUpVectorX(const DoubleID& dwux){fprintf_s(mFile,"connectAttr \"");dwux.write(mFile);fprintf_s(mFile,"\" \"%s.dwuv.dwux\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Y component of the up vector
	*/
	void setDWorldUpVectorY(double dwuy){if(dwuy == 1.0) return; fprintf_s(mFile, "setAttr \".dwuv.dwuy\" %f;\n", dwuy);}
	/*
	Applies to Spline IK Handles only.
	Y component of the up vector
	*/
	void setDWorldUpVectorY(const DoubleID& dwuy){fprintf_s(mFile,"connectAttr \"");dwuy.write(mFile);fprintf_s(mFile,"\" \"%s.dwuv.dwuy\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Z component of the up vector
	*/
	void setDWorldUpVectorZ(double dwuz){if(dwuz == 0.0) return; fprintf_s(mFile, "setAttr \".dwuv.dwuz\" %f;\n", dwuz);}
	/*
	Applies to Spline IK Handles only.
	Z component of the up vector
	*/
	void setDWorldUpVectorZ(const DoubleID& dwuz){fprintf_s(mFile,"connectAttr \"");dwuz.write(mFile);fprintf_s(mFile,"\" \"%s.dwuv.dwuz\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Same as World Up Vector attribute, except this value
	applies to the end joint in the chain.  When the
	World Up Type is Vector (Start/End) or
	Object Rotation Up (Start/End), the World Up Vector
	and World Up Vector End values will be interpolated
	along the chain to provide up vectors for the
	intermediate joints.
	*/
	void setDWorldUpVectorEnd(const double3& dwve){fprintf_s(mFile, "setAttr \".dwve\" -type \"double3\" ");dwve.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Applies to Spline IK Handles only.
	Same as World Up Vector attribute, except this value
	applies to the end joint in the chain.  When the
	World Up Type is Vector (Start/End) or
	Object Rotation Up (Start/End), the World Up Vector
	and World Up Vector End values will be interpolated
	along the chain to provide up vectors for the
	intermediate joints.
	*/
	void setDWorldUpVectorEnd(const Double3ID& dwve){fprintf_s(mFile,"connectAttr \"");dwve.write(mFile);fprintf_s(mFile,"\" \"%s.dwve\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	X component of the end joint up vector
	*/
	void setDWorldUpVectorEndX(double dwvx){if(dwvx == 0.0) return; fprintf_s(mFile, "setAttr \".dwve.dwvx\" %f;\n", dwvx);}
	/*
	Applies to Spline IK Handles only.
	X component of the end joint up vector
	*/
	void setDWorldUpVectorEndX(const DoubleID& dwvx){fprintf_s(mFile,"connectAttr \"");dwvx.write(mFile);fprintf_s(mFile,"\" \"%s.dwve.dwvx\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Y component of the end joint up vector
	*/
	void setDWorldUpVectorEndY(double dwvy){if(dwvy == 1.0) return; fprintf_s(mFile, "setAttr \".dwve.dwvy\" %f;\n", dwvy);}
	/*
	Applies to Spline IK Handles only.
	Y component of the end joint up vector
	*/
	void setDWorldUpVectorEndY(const DoubleID& dwvy){fprintf_s(mFile,"connectAttr \"");dwvy.write(mFile);fprintf_s(mFile,"\" \"%s.dwve.dwvy\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Z component of the end joint up vector
	*/
	void setDWorldUpVectorEndZ(double dwvz){if(dwvz == 0.0) return; fprintf_s(mFile, "setAttr \".dwve.dwvz\" %f;\n", dwvz);}
	/*
	Applies to Spline IK Handles only.
	Z component of the end joint up vector
	*/
	void setDWorldUpVectorEndZ(const DoubleID& dwvz){fprintf_s(mFile,"connectAttr \"");dwvz.write(mFile);fprintf_s(mFile,"\" \"%s.dwve.dwvz\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Object->World matrix for object being used to specify
	up vector in Object Up or Object Rotation Up modes.
	If in one of the Start/End modes, this object's matrix
	is used to compute a value for the first joint (which
	is then interpolated with a value computed for the last
	joint), otherwise this matrix is used for the entire
	array.
	*/
	void setDWorldUpMatrix(const matrix& dwum){if(dwum == identity) return; fprintf_s(mFile, "setAttr \".dwum\" -type \"matrix\" ");dwum.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Applies to Spline IK Handles only.
	Object->World matrix for object being used to specify
	up vector in Object Up or Object Rotation Up modes.
	If in one of the Start/End modes, this object's matrix
	is used to compute a value for the first joint (which
	is then interpolated with a value computed for the last
	joint), otherwise this matrix is used for the entire
	array.
	*/
	void setDWorldUpMatrix(const MatrixID& dwum){fprintf_s(mFile,"connectAttr \"");dwum.write(mFile);fprintf_s(mFile,"\" \"%s.dwum\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Object->World matrix for object being used to specify
	up vector for the last joint in the chain.  Up vector
	computed using this matrix will be interpolated with the
	one computed for the start joint when in
	Object Up (Start/End) or Object Rotation Up (Start/End)
	modes.
	*/
	void setDWorldUpMatrixEnd(const matrix& dwue){if(dwue == identity) return; fprintf_s(mFile, "setAttr \".dwue\" -type \"matrix\" ");dwue.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Applies to Spline IK Handles only.
	Object->World matrix for object being used to specify
	up vector for the last joint in the chain.  Up vector
	computed using this matrix will be interpolated with the
	one computed for the start joint when in
	Object Up (Start/End) or Object Rotation Up (Start/End)
	modes.
	*/
	void setDWorldUpMatrixEnd(const MatrixID& dwue){fprintf_s(mFile,"connectAttr \"");dwue.write(mFile);fprintf_s(mFile,"\" \"%s.dwue\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Specifies how twist will be distributed along the joint
	chain.  "Total" mode means that the Twist attribute
	specifies a total amount of twist for the end joint,
	and all previous joints ramp up to this value.  "Start/End"
	mode means that the Twist Start/End attribute specifies
	twist values for the start and end joints, and other
	joints interpolate their twist values from these.
	"Ramp" mode means that a texture is used to specify
	twists for joints along the chain.  Joints are assigned
	texture coordinates (0.0,V), where V ranges from 0.0 to
	1.0 along the chain.  Valid values are 0=Total, 1=Start/End,
	2=Ramp.
	*/
	void setDTwistValueType(unsigned int dtvt){if(dtvt == 0) return; fprintf_s(mFile, "setAttr \".dtvt\" %i;\n", dtvt);}
	/*
	Applies to Spline IK Handles only.
	Specifies how twist will be distributed along the joint
	chain.  "Total" mode means that the Twist attribute
	specifies a total amount of twist for the end joint,
	and all previous joints ramp up to this value.  "Start/End"
	mode means that the Twist Start/End attribute specifies
	twist values for the start and end joints, and other
	joints interpolate their twist values from these.
	"Ramp" mode means that a texture is used to specify
	twists for joints along the chain.  Joints are assigned
	texture coordinates (0.0,V), where V ranges from 0.0 to
	1.0 along the chain.  Valid values are 0=Total, 1=Start/End,
	2=Ramp.
	*/
	void setDTwistValueType(const UnsignedintID& dtvt){fprintf_s(mFile,"connectAttr \"");dtvt.write(mFile);fprintf_s(mFile,"\" \"%s.dtvt\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	For "Start/End" twist mode, specifies twist values for
	the start and end joints in the chain.  Values for
	intermediate joints are interpolated from these values.
	Twist is applied relative to the up-vector specified
	via the World Up Type controls.  If the World Up Type
	is "Relative", then joints twist relative to their
	predecessors in the chain.
	*/
	void setDTwistStartEnd(const double2& dtse){fprintf_s(mFile, "setAttr \".dtse\" -type \"double2\" ");dtse.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Applies to Spline IK Handles only.
	For "Start/End" twist mode, specifies twist values for
	the start and end joints in the chain.  Values for
	intermediate joints are interpolated from these values.
	Twist is applied relative to the up-vector specified
	via the World Up Type controls.  If the World Up Type
	is "Relative", then joints twist relative to their
	predecessors in the chain.
	*/
	void setDTwistStartEnd(const Double2ID& dtse){fprintf_s(mFile,"connectAttr \"");dtse.write(mFile);fprintf_s(mFile,"\" \"%s.dtse\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Twist value for the start joint in the chain.  Only has
	an effect when Twist Type is set to Start/End.
	*/
	void setDTwistStart(double dtst){if(dtst == 0.0) return; fprintf_s(mFile, "setAttr \".dtse.dtst\" %f;\n", dtst);}
	/*
	Applies to Spline IK Handles only.
	Twist value for the start joint in the chain.  Only has
	an effect when Twist Type is set to Start/End.
	*/
	void setDTwistStart(const DoubleID& dtst){fprintf_s(mFile,"connectAttr \"");dtst.write(mFile);fprintf_s(mFile,"\" \"%s.dtse.dtst\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Twist value for the end joint in the chain.  Only has
	an effect when Twist Type is set to Start/End.
	*/
	void setDTwistEnd(double dten){if(dten == 0.0) return; fprintf_s(mFile, "setAttr \".dtse.dten\" %f;\n", dten);}
	/*
	Applies to Spline IK Handles only.
	Twist value for the end joint in the chain.  Only has
	an effect when Twist Type is set to Start/End.
	*/
	void setDTwistEnd(const DoubleID& dten){fprintf_s(mFile,"connectAttr \"");dten.write(mFile);fprintf_s(mFile,"\" \"%s.dtse.dten\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	2d texture node used to distribute twist along the
	joint chain.  Joints are assigned texture V-coordinates
	in the range [0,1], and the texture is evaluated
	at coordinates (0.0,V).  The luminance of the resulting
	color is multiplied by the value of the Texture Multiplier
	attribute to produce the twist for that joint.
	*/
	void setDTwistRamp(const float3& dtra){fprintf_s(mFile, "setAttr \".dtra\" -type \"float3\" ");dtra.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Applies to Spline IK Handles only.
	2d texture node used to distribute twist along the
	joint chain.  Joints are assigned texture V-coordinates
	in the range [0,1], and the texture is evaluated
	at coordinates (0.0,V).  The luminance of the resulting
	color is multiplied by the value of the Texture Multiplier
	attribute to produce the twist for that joint.
	*/
	void setDTwistRamp(const Float3ID& dtra){fprintf_s(mFile,"connectAttr \"");dtra.write(mFile);fprintf_s(mFile,"\" \"%s.dtra\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	R component of the twist texture color
	*/
	void setDTwistRampR(float dtrr){if(dtrr == 0.0) return; fprintf_s(mFile, "setAttr \".dtra.dtrr\" %f;\n", dtrr);}
	/*
	Applies to Spline IK Handles only.
	R component of the twist texture color
	*/
	void setDTwistRampR(const FloatID& dtrr){fprintf_s(mFile,"connectAttr \"");dtrr.write(mFile);fprintf_s(mFile,"\" \"%s.dtra.dtrr\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	G component of the twist texture color
	*/
	void setDTwistRampG(float dtrg){if(dtrg == 0.0) return; fprintf_s(mFile, "setAttr \".dtra.dtrg\" %f;\n", dtrg);}
	/*
	Applies to Spline IK Handles only.
	G component of the twist texture color
	*/
	void setDTwistRampG(const FloatID& dtrg){fprintf_s(mFile,"connectAttr \"");dtrg.write(mFile);fprintf_s(mFile,"\" \"%s.dtra.dtrg\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	B component of the twist texture color
	*/
	void setDTwistRampB(float dtrb){if(dtrb == 0.0) return; fprintf_s(mFile, "setAttr \".dtra.dtrb\" %f;\n", dtrb);}
	/*
	Applies to Spline IK Handles only.
	B component of the twist texture color
	*/
	void setDTwistRampB(const FloatID& dtrb){fprintf_s(mFile,"connectAttr \"");dtrb.write(mFile);fprintf_s(mFile,"\" \"%s.dtra.dtrb\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Value (in degrees) that is multiplied by the result of
	the twist texture when the Twist Value Type is Ramp.
	This is to map the texture result (typically in the
	range [0,1]) into a more useful range of angular twist.
	*/
	void setDTwistRampMult(double dtrm){if(dtrm == 90.0) return; fprintf_s(mFile, "setAttr \".dtrm\" %f;\n", dtrm);}
	/*
	Applies to Spline IK Handles only.
	Value (in degrees) that is multiplied by the result of
	the twist texture when the Twist Value Type is Ramp.
	This is to map the texture result (typically in the
	range [0,1]) into a more useful range of angular twist.
	*/
	void setDTwistRampMult(const DoubleID& dtrm){fprintf_s(mFile,"connectAttr \"");dtrm.write(mFile);fprintf_s(mFile,"\" \"%s.dtrm\";\n",mName.c_str());}
	/*
	Applies to Spline IK Handles only.
	Determines whether the Advanced Twist Controls are used
	or not.  If disabled, Maya will use the old style twist,
	in which each joint twists relative to its predecessor
	in the joint chain.  This can lead to undesirable excess
	twisting as the chain animates.  With the Advanced Twist
	controls, users can lock the twist to an up-vector that
	can be specified in a number of ways.  Additional twist
	can also be applied along the chain using the different
	Twist Value Types.
	*/
	void setDTwistControlEnable(bool dtce){if(dtce == false) return; fprintf_s(mFile, "setAttr \".dtce\" %i;\n", dtce);}
	/*
	Applies to Spline IK Handles only.
	Determines whether the Advanced Twist Controls are used
	or not.  If disabled, Maya will use the old style twist,
	in which each joint twists relative to its predecessor
	in the joint chain.  This can lead to undesirable excess
	twisting as the chain animates.  With the Advanced Twist
	controls, users can lock the twist to an up-vector that
	can be specified in a number of ways.  Additional twist
	can also be applied along the chain using the different
	Twist Value Types.
	*/
	void setDTwistControlEnable(const BoolID& dtce){fprintf_s(mFile,"connectAttr \"");dtce.write(mFile);fprintf_s(mFile,"\" \"%s.dtce\";\n",mName.c_str());}
	/*
	Used only with the ikSpringSolver.
	Prior to Maya 8.5, spring ik solvers used the scene
	up as the solver up orientation, so they did not work right
	when parented. Fixing that problem changed the solution
	for some existing spring ik setups. Setting this attribute to true
	goes back to the old (pre-8.5) style of computation.
	*/
	void setSplineIkOldStyle(bool sio){if(sio == false) return; fprintf_s(mFile, "setAttr \".sio\" %i;\n", sio);}
	/*
	Used only with the ikSpringSolver.
	Prior to Maya 8.5, spring ik solvers used the scene
	up as the solver up orientation, so they did not work right
	when parented. Fixing that problem changed the solution
	for some existing spring ik setups. Setting this attribute to true
	goes back to the old (pre-8.5) style of computation.
	*/
	void setSplineIkOldStyle(const BoolID& sio){fprintf_s(mFile,"connectAttr \"");sio.write(mFile);fprintf_s(mFile,"\" \"%s.sio\";\n",mName.c_str());}
	/*The IK handle's start joint.*/
	MessageID getStartJoint(){char buffer[4096];sprintf_s (buffer, "%s.hsj",mName.c_str());return (const char*)buffer;}
	/*The IK handle's end effector.*/
	MessageID getEndEffector(){char buffer[4096];sprintf_s (buffer, "%s.hee",mName.c_str());return (const char*)buffer;}
	/*The IK solver used by the IK handle.*/
	MessageID getIkSolver(){char buffer[4096];sprintf_s (buffer, "%s.hsv",mName.c_str());return (const char*)buffer;}
	/*Indicates whether the IK handle may be snapped or not.*/
	BoolID getSnapEnable(){char buffer[4096];sprintf_s (buffer, "%s.hsh",mName.c_str());return (const char*)buffer;}
	/*Indicates whether stickiness is enabled for the IK handle or not.*/
	UnsignedintID getStickiness(){char buffer[4096];sprintf_s (buffer, "%s.hs",mName.c_str());return (const char*)buffer;}
	/*The IK handle's priority value for grouping.*/
	IntID getPriority(){char buffer[4096];sprintf_s (buffer, "%s.hpr",mName.c_str());return (const char*)buffer;}
	/*Determine how much this IK handle affects the IK solution.*/
	DoubleID getWeight(){char buffer[4096];sprintf_s (buffer, "%s.hw",mName.c_str());return (const char*)buffer;}
	/*Determine how position/orientation affects IK solution.*/
	DoubleID getPoWeight(){char buffer[4096];sprintf_s (buffer, "%s.hpo",mName.c_str());return (const char*)buffer;}
	/*Pole vector used by ikRPsolver to adjust the IK solution.*/
	Double3ID getPoleVector(){char buffer[4096];sprintf_s (buffer, "%s.pv",mName.c_str());return (const char*)buffer;}
	/*X component of the pole vector.*/
	DoubleID getPoleVectorX(){char buffer[4096];sprintf_s (buffer, "%s.pv.pvx",mName.c_str());return (const char*)buffer;}
	/*Y component of the pole vector.*/
	DoubleID getPoleVectorY(){char buffer[4096];sprintf_s (buffer, "%s.pv.pvy",mName.c_str());return (const char*)buffer;}
	/*Z component of the pole vector.*/
	DoubleID getPoleVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.pv.pvz",mName.c_str());return (const char*)buffer;}
	/*The IK spline handle's input curve.*/
	NurbsCurveID getInCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*The ikSplineHandle's offset along the curve.*/
	DoubleID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.off",mName.c_str());return (const char*)buffer;}
	/*The ikSplineHandle's roll.*/
	DoubleID getRoll(){char buffer[4096];sprintf_s (buffer, "%s.rol",mName.c_str());return (const char*)buffer;}
	/*The twist for both the IK spline handle and the IK RP handle.*/
	DoubleID getTwist(){char buffer[4096];sprintf_s (buffer, "%s.twi",mName.c_str());return (const char*)buffer;}
	/*Indicates if the IK spline handle's root joint is constrained to the curve.*/
	BoolID getRootOnCurve(){char buffer[4096];sprintf_s (buffer, "%s.roc",mName.c_str());return (const char*)buffer;}
	/*The IK spline handle's twist interpolation type. The following are legal values: 0=Linear, 1=EaseIn, 2=EaseOut, 3=EaseInOut.*/
	UnsignedintID getTwistType(){char buffer[4096];sprintf_s (buffer, "%s.twt",mName.c_str());return (const char*)buffer;}
	/*
	This attribute indicates whether the start joint is allowed to
	twist or not. If not, then the required twist is distributed over the
	remaining joints. This applies to all the twist types.
	*/
	BoolID getRootTwistMode(){char buffer[4096];sprintf_s (buffer, "%s.rtm",mName.c_str());return (const char*)buffer;}
	/*
	Indicates whether or not the solver is invoked for the IK handle.
	A value of 1.0 means the solver is invoked.
	A value of 0.0 means the solver is not invoked.
	Values between 0 and 1 indicate that the solver result will be
	blended with fk connections on the joints.
	*/
	DoubleID getIkBlend(){char buffer[4096];sprintf_s (buffer, "%s.ikb",mName.c_str());return (const char*)buffer;}
	/*
	Enables ik blend controls: snapping is disabled, and
	joints can be rotated even when there are keys on the handle.
	When true, this attribute overrides the global ik blend setting.
	*/
	BoolID getIkFkManipulation(){char buffer[4096];sprintf_s (buffer, "%s.eik",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	The type of up-vector constraint used to twist joints
	in the chain.  Legal values are 0=Scene Up, 1=Object Up,
	2=Object Up (Start/End), 3=Object Rotation Up,
	4=Object Rotation Up (Start/End), 5=Vector,
	6=Vector (Start/End), 7=Relative
	*/
	UnsignedintID getDWorldUpType(){char buffer[4096];sprintf_s (buffer, "%s.dwut",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Determines which of the joints local axes will
	be aligned with the up vector when an up vector
	is in use.  The positive or negative Y or Z axes
	can be selected, or the "closest" of one of those
	axes (meaning whichever of the positive or negative
	axes is closest to the up vector).  The X-axes are
	not available, since the joint x-axis always points
	along the spline.  Joint twisting happens about this
	axis.  "Closest Y" and "Closest Z" modes are useful
	for joint chains that have been constructed with their
	local axes flipped every few joints.  These settings
	are not recommended for animation, as they are prone to
	flipping as the chain moves.
	*/
	UnsignedintID getDWorldUpAxis(){char buffer[4096];sprintf_s (buffer, "%s.dwua",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Joints will twist to make one of their local axes
	align as best as possible with this vector.  If the
	World Up Type value is Vector, then this value
	specifies a worldspace vector.  For Object Rotation
	mode, this value specifies a vector in the local
	space of the target object specified by the World Up
	Object attribute.  If the World Up Type is either
	Vector (Start/End) or Object Rotation Up (Start/End),
	then the vector applies to the start joint in the
	chain, and is interpolated with the World Up Vector End
	value that is specified for the end joint in the chain.
	Otherwise, this value is used for every joint in the
	chain.
	*/
	Double3ID getDWorldUpVector(){char buffer[4096];sprintf_s (buffer, "%s.dwuv",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	X component of the up vector
	*/
	DoubleID getDWorldUpVectorX(){char buffer[4096];sprintf_s (buffer, "%s.dwuv.dwux",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Y component of the up vector
	*/
	DoubleID getDWorldUpVectorY(){char buffer[4096];sprintf_s (buffer, "%s.dwuv.dwuy",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Z component of the up vector
	*/
	DoubleID getDWorldUpVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.dwuv.dwuz",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Same as World Up Vector attribute, except this value
	applies to the end joint in the chain.  When the
	World Up Type is Vector (Start/End) or
	Object Rotation Up (Start/End), the World Up Vector
	and World Up Vector End values will be interpolated
	along the chain to provide up vectors for the
	intermediate joints.
	*/
	Double3ID getDWorldUpVectorEnd(){char buffer[4096];sprintf_s (buffer, "%s.dwve",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	X component of the end joint up vector
	*/
	DoubleID getDWorldUpVectorEndX(){char buffer[4096];sprintf_s (buffer, "%s.dwve.dwvx",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Y component of the end joint up vector
	*/
	DoubleID getDWorldUpVectorEndY(){char buffer[4096];sprintf_s (buffer, "%s.dwve.dwvy",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Z component of the end joint up vector
	*/
	DoubleID getDWorldUpVectorEndZ(){char buffer[4096];sprintf_s (buffer, "%s.dwve.dwvz",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Object->World matrix for object being used to specify
	up vector in Object Up or Object Rotation Up modes.
	If in one of the Start/End modes, this object's matrix
	is used to compute a value for the first joint (which
	is then interpolated with a value computed for the last
	joint), otherwise this matrix is used for the entire
	array.
	*/
	MatrixID getDWorldUpMatrix(){char buffer[4096];sprintf_s (buffer, "%s.dwum",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Object->World matrix for object being used to specify
	up vector for the last joint in the chain.  Up vector
	computed using this matrix will be interpolated with the
	one computed for the start joint when in
	Object Up (Start/End) or Object Rotation Up (Start/End)
	modes.
	*/
	MatrixID getDWorldUpMatrixEnd(){char buffer[4096];sprintf_s (buffer, "%s.dwue",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Specifies how twist will be distributed along the joint
	chain.  "Total" mode means that the Twist attribute
	specifies a total amount of twist for the end joint,
	and all previous joints ramp up to this value.  "Start/End"
	mode means that the Twist Start/End attribute specifies
	twist values for the start and end joints, and other
	joints interpolate their twist values from these.
	"Ramp" mode means that a texture is used to specify
	twists for joints along the chain.  Joints are assigned
	texture coordinates (0.0,V), where V ranges from 0.0 to
	1.0 along the chain.  Valid values are 0=Total, 1=Start/End,
	2=Ramp.
	*/
	UnsignedintID getDTwistValueType(){char buffer[4096];sprintf_s (buffer, "%s.dtvt",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	For "Start/End" twist mode, specifies twist values for
	the start and end joints in the chain.  Values for
	intermediate joints are interpolated from these values.
	Twist is applied relative to the up-vector specified
	via the World Up Type controls.  If the World Up Type
	is "Relative", then joints twist relative to their
	predecessors in the chain.
	*/
	Double2ID getDTwistStartEnd(){char buffer[4096];sprintf_s (buffer, "%s.dtse",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Twist value for the start joint in the chain.  Only has
	an effect when Twist Type is set to Start/End.
	*/
	DoubleID getDTwistStart(){char buffer[4096];sprintf_s (buffer, "%s.dtse.dtst",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Twist value for the end joint in the chain.  Only has
	an effect when Twist Type is set to Start/End.
	*/
	DoubleID getDTwistEnd(){char buffer[4096];sprintf_s (buffer, "%s.dtse.dten",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	2d texture node used to distribute twist along the
	joint chain.  Joints are assigned texture V-coordinates
	in the range [0,1], and the texture is evaluated
	at coordinates (0.0,V).  The luminance of the resulting
	color is multiplied by the value of the Texture Multiplier
	attribute to produce the twist for that joint.
	*/
	Float3ID getDTwistRamp(){char buffer[4096];sprintf_s (buffer, "%s.dtra",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	R component of the twist texture color
	*/
	FloatID getDTwistRampR(){char buffer[4096];sprintf_s (buffer, "%s.dtra.dtrr",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	G component of the twist texture color
	*/
	FloatID getDTwistRampG(){char buffer[4096];sprintf_s (buffer, "%s.dtra.dtrg",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	B component of the twist texture color
	*/
	FloatID getDTwistRampB(){char buffer[4096];sprintf_s (buffer, "%s.dtra.dtrb",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Value (in degrees) that is multiplied by the result of
	the twist texture when the Twist Value Type is Ramp.
	This is to map the texture result (typically in the
	range [0,1]) into a more useful range of angular twist.
	*/
	DoubleID getDTwistRampMult(){char buffer[4096];sprintf_s (buffer, "%s.dtrm",mName.c_str());return (const char*)buffer;}
	/*
	Applies to Spline IK Handles only.
	Determines whether the Advanced Twist Controls are used
	or not.  If disabled, Maya will use the old style twist,
	in which each joint twists relative to its predecessor
	in the joint chain.  This can lead to undesirable excess
	twisting as the chain animates.  With the Advanced Twist
	controls, users can lock the twist to an up-vector that
	can be specified in a number of ways.  Additional twist
	can also be applied along the chain using the different
	Twist Value Types.
	*/
	BoolID getDTwistControlEnable(){char buffer[4096];sprintf_s (buffer, "%s.dtce",mName.c_str());return (const char*)buffer;}
	/*
	Used only with the ikSpringSolver.
	Prior to Maya 8.5, spring ik solvers used the scene
	up as the solver up orientation, so they did not work right
	when parented. Fixing that problem changed the solution
	for some existing spring ik setups. Setting this attribute to true
	goes back to the old (pre-8.5) style of computation.
	*/
	BoolID getSplineIkOldStyle(){char buffer[4096];sprintf_s (buffer, "%s.sio",mName.c_str());return (const char*)buffer;}
protected:
	IkHandle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKHANDLE_H__
