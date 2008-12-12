/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_JOINT_H__
#define __MayaDM_JOINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
A joint is a transform which is the basic node of a kinematic skeleton.
        A hierarchy of joints is a kinematics skeleton. In a 3D view, a joint is
        drawn as a combination of three circles perpendicular to each other. If a
        joint is the child of another joint, a bone is drawn between them.<p/>

        The joint node is derived from the transform node, so it inherits some of
        its basic transformation from its parent node (see the documentation for
        transform node for details). Many elements in the inherited transformation matrix
        have been suppressed so the following invariances are maintained:<p/>

<pre>
        rotatePivot = 0
        rotatePivotTranslate = 0
        scalePivot = 0
        scalePivotTranslate = 0
        shear = 0
</pre>

        There are also attributes used only by joint nodes.
        The transformation matrix for a joint node is below.<p/>

<pre>
        matrix = [S] * [RO] * [R] * [JO] * [IS] * [T]
</pre>

        (where '*' denotes matrix multiplication).<p/>

<pre>
        [S]:  scale.
        [RO]: Rotate Orient (attribute name is rotateAxis).
        [R]:  rotate.
        [JO]: jointOrient.
        [IS]: parentScaleInverse.
        [T]:  translate.
</pre>

<H4>Joint Attributes</H4>

        The jointType attribute determines if a joint node is a ball joint,
        a universal joint,
        or a hinge joint. There are six different joint types: 'xyz', 'xy', 'yz',
        'xz', 'x', 'y', and 'z'. If jointType is 'xyz', the joint is a ball joint
        (with three degrees of freedom). If jointType is 'xy', 'yz', or
        'xz', it is a universal joint. If jointType is 'x', 'y', or 'z',
        it is a hinge joint. The rotation order of a joint node is determined by
        the transform node. The default jointType is 'xyz'.<p/>

        The dofMask attribute determines which degree of freedom is used
        in the ik solving process. The first 3 bytes of the value indicate the
        presence or absence of each of the 'x', 'y' and 'z' degrees of freedom,
        using the character values for "x", "y" and "z" respectively.
        The fourth byte indicates how many of the 3 degrees of freedom
        are present.
        Since the default jointType value is
        'xyz', the default dofMask value is 0x78797a03: all three
        degrees of freedom are involved into the ik solving process. The other
        dofMask values are:<p/>
<pre>
        0x78790002: for jointType 'xy';
        0x00797a02: for jointType 'yz';
        0x78007a02: for jointType 'xz';
        0x78000001: for jointType 'x';
        0x00790001: for jointType 'y';
        0x00007a01: for jointType 'z';
</pre>

        The jointOrient attribute defines the orientation of the joint node. It is
        different from the rotation orientation defined in the transform node.
        Modifying the jointOrient changes how scaling a joint behaves. Internally,
        jointOrient is stored as a quaternion. This means that if you set a value
        and then query it, you may get back different numbers. For example, if you
        set jointOrient to (360, 0, 0), you will read back (0, 0, 0).<p/>

        The segmentScaleCompensate attribute controls the use of the inverseScale
        attribute. If it is on, inverseScale is used to compute the joint's
        transformation matrix. If it is off, inverseScale is simply left out of
        the computation. The default is on.<p/>

        The inverseScale attribute is used to do the scale compensation. It is
        typically connected to the scale attribute of the joint's parent. The
        value of inverseScale is set by this connection to match the parent's
        scale value. However, when the matrix is computed, the inverse of the
        value is used. This means that if you set the inverseScale attribute to
        (1, 2, 3), the joint and its children will scale by (1, 1/2, 1/3).<p/>

        The stiffness attribute is used by ikSolvers to generate a resistance to a
        joint motion. It affects the inverse kinematic solution. The default is
        no stiffness (0.0 for all three components).<p/>

        The preferredAngle attribute defines the initial joint configuration used
        by a single chain ik solver to calculate the inverse kinematic solution.
        The values are set on joint creation. It can also be modified with
        the joint command or through the Skeletons menu.<p/>

        The minRotateDampRange and minRotateDampStrength are attributes to apply
        resistance to a joint rotation as it approaches the lower boundary of its
        rotation limits. This functionality allows joint motion to slow down
        smoothly until the joint reaches its rotation limits instead of stopping
        abruptly. The minRotateDampRange specifies when the deceleration should
        start, and the minRotateDampStrength defines the rate of deceleration.<p/>

        The maxRotateDampRange and maxRotateDampStrength are attributes which have
        the same functionality as above two attributes. But they apply to the
        upper boundary of the joint rotation limits.<p/>

        The bindPose attribute stores the transformation matrix in use at the time
        a skin is bound. The joint bind pose is created and saved when the bindSkin
        command is executed; it is undefined unless a bindSkin operation
        has been performed. The dagPose command resets the joint back
        to its bind pose easily and quickly.<p/>

        The bindRotation attribute stores the joint local rotation in use at the
        time a skin is bound.<p/>

        The bindRotateAxis attribute stores the joint rotate axis in use at the
        time a skin is bound. It is set when the skin is bound.<p/>

        The bindJointOrient attribute stores the joint orientation in use at the
        time a skin is bound. It is set when the skin is bound.<p/>

        The bindScale attribute stores the scale parameter for the joint in use
        at the time a skin is bound. It is also set when the skin is bound.<p/>

        The bindInverseScale attribute stores the inverse scale parameter of the
        joint in use at the time a skin is bound. It is set when the skin is
        bound.<p/>

        The bindSegmentScaleCompensate attribute stores the state of segment
        scale compensate of the joint in use at the time a skin is bound. It is
        also set when the skin is bound.<p/>
*/
class Joint : public Transform
{
public:
public:
	Joint(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "joint"){}
	virtual ~Joint(){}
	/*this type is used to determine the joint orientation when created.*/
	void setJointOrientType(const string& jot){if(jot == "xyz") return; fprintf_s(mFile, "setAttr \".jot\" -type \"string\" ");jot.write(mFile);fprintf_s(mFile,";\n");}
	/*Joint dof has "X" component.*/
	void setJointTypeX(bool jtx){if(jtx == true) return; fprintf_s(mFile, "setAttr \".jtx\" %i;\n", jtx);}
	/*Joint dof has "X" component.*/
	void setJointTypeX(const BoolID& jtx){fprintf_s(mFile,"connectAttr \"");jtx.write(mFile);fprintf_s(mFile,"\" \"%s.jtx\";\n",mName.c_str());}
	/*Joint dof has "Y" component.*/
	void setJointTypeY(bool jty){if(jty == true) return; fprintf_s(mFile, "setAttr \".jty\" %i;\n", jty);}
	/*Joint dof has "Y" component.*/
	void setJointTypeY(const BoolID& jty){fprintf_s(mFile,"connectAttr \"");jty.write(mFile);fprintf_s(mFile,"\" \"%s.jty\";\n",mName.c_str());}
	/*Joint dof has "Z" component.*/
	void setJointTypeZ(bool jtz){if(jtz == true) return; fprintf_s(mFile, "setAttr \".jtz\" %i;\n", jtz);}
	/*Joint dof has "Z" component.*/
	void setJointTypeZ(const BoolID& jtz){fprintf_s(mFile,"connectAttr \"");jtz.write(mFile);fprintf_s(mFile,"\" \"%s.jtz\";\n",mName.c_str());}
	/*Joint orient.*/
	void setJointOrient(const double3& jo){fprintf_s(mFile, "setAttr \".jo\" -type \"double3\" ");jo.write(mFile);fprintf_s(mFile,";\n");}
	/*Joint orient.*/
	void setJointOrient(const Double3ID& jo){fprintf_s(mFile,"connectAttr \"");jo.write(mFile);fprintf_s(mFile,"\" \"%s.jo\";\n",mName.c_str());}
	/*Joint orientX.*/
	void setJointOrientX(double jox){if(jox == 0) return; fprintf_s(mFile, "setAttr \".jo.jox\" %f;\n", jox);}
	/*Joint orientX.*/
	void setJointOrientX(const DoubleID& jox){fprintf_s(mFile,"connectAttr \"");jox.write(mFile);fprintf_s(mFile,"\" \"%s.jo.jox\";\n",mName.c_str());}
	/*Joint orientY.*/
	void setJointOrientY(double joy){if(joy == 0) return; fprintf_s(mFile, "setAttr \".jo.joy\" %f;\n", joy);}
	/*Joint orientY.*/
	void setJointOrientY(const DoubleID& joy){fprintf_s(mFile,"connectAttr \"");joy.write(mFile);fprintf_s(mFile,"\" \"%s.jo.joy\";\n",mName.c_str());}
	/*Joint orientZ.*/
	void setJointOrientZ(double joz){if(joz == 0) return; fprintf_s(mFile, "setAttr \".jo.joz\" %f;\n", joz);}
	/*Joint orientZ.*/
	void setJointOrientZ(const DoubleID& joz){fprintf_s(mFile,"connectAttr \"");joz.write(mFile);fprintf_s(mFile,"\" \"%s.jo.joz\";\n",mName.c_str());}
	/*Indicates whether to compensate for the scale of the parent joint.*/
	void setSegmentScaleCompensate(bool ssc){if(ssc == true) return; fprintf_s(mFile, "setAttr \".ssc\" %i;\n", ssc);}
	/*Indicates whether to compensate for the scale of the parent joint.*/
	void setSegmentScaleCompensate(const BoolID& ssc){fprintf_s(mFile,"connectAttr \"");ssc.write(mFile);fprintf_s(mFile,"\" \"%s.ssc\";\n",mName.c_str());}
	/*The scale of the parent joint.*/
	void setInverseScale(const double3& is){fprintf_s(mFile, "setAttr \".is\" -type \"double3\" ");is.write(mFile);fprintf_s(mFile,";\n");}
	/*The scale of the parent joint.*/
	void setInverseScale(const Double3ID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*X component of aParentScale.*/
	void setInverseScaleX(double isx){if(isx == 1.0) return; fprintf_s(mFile, "setAttr \".is.isx\" %f;\n", isx);}
	/*X component of aParentScale.*/
	void setInverseScaleX(const DoubleID& isx){fprintf_s(mFile,"connectAttr \"");isx.write(mFile);fprintf_s(mFile,"\" \"%s.is.isx\";\n",mName.c_str());}
	/*Y component of aParentScale.*/
	void setInverseScaleY(double isy){if(isy == 1.0) return; fprintf_s(mFile, "setAttr \".is.isy\" %f;\n", isy);}
	/*Y component of aParentScale.*/
	void setInverseScaleY(const DoubleID& isy){fprintf_s(mFile,"connectAttr \"");isy.write(mFile);fprintf_s(mFile,"\" \"%s.is.isy\";\n",mName.c_str());}
	/*Z component of aParentScale.*/
	void setInverseScaleZ(double isz){if(isz == 1.0) return; fprintf_s(mFile, "setAttr \".is.isz\" %f;\n", isz);}
	/*Z component of aParentScale.*/
	void setInverseScaleZ(const DoubleID& isz){fprintf_s(mFile,"connectAttr \"");isz.write(mFile);fprintf_s(mFile,"\" \"%s.is.isz\";\n",mName.c_str());}
	/*Joint stiffness.*/
	void setStiffness(const double3& st){fprintf_s(mFile, "setAttr \".st\" -type \"double3\" ");st.write(mFile);fprintf_s(mFile,";\n");}
	/*Joint stiffness.*/
	void setStiffness(const Double3ID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*Joint stiffness X.*/
	void setStiffnessX(double stx){if(stx == 0.0) return; fprintf_s(mFile, "setAttr \".st.stx\" %f;\n", stx);}
	/*Joint stiffness X.*/
	void setStiffnessX(const DoubleID& stx){fprintf_s(mFile,"connectAttr \"");stx.write(mFile);fprintf_s(mFile,"\" \"%s.st.stx\";\n",mName.c_str());}
	/*Joint stiffness Y.*/
	void setStiffnessY(double sty){if(sty == 0.0) return; fprintf_s(mFile, "setAttr \".st.sty\" %f;\n", sty);}
	/*Joint stiffness Y.*/
	void setStiffnessY(const DoubleID& sty){fprintf_s(mFile,"connectAttr \"");sty.write(mFile);fprintf_s(mFile,"\" \"%s.st.sty\";\n",mName.c_str());}
	/*Joint stiffness Z.*/
	void setStiffnessZ(double stz){if(stz == 0.0) return; fprintf_s(mFile, "setAttr \".st.stz\" %f;\n", stz);}
	/*Joint stiffness Z.*/
	void setStiffnessZ(const DoubleID& stz){fprintf_s(mFile,"connectAttr \"");stz.write(mFile);fprintf_s(mFile,"\" \"%s.st.stz\";\n",mName.c_str());}
	/*Joint preferred angle.*/
	void setPreferredAngle(const double3& pa){fprintf_s(mFile, "setAttr \".pa\" -type \"double3\" ");pa.write(mFile);fprintf_s(mFile,";\n");}
	/*Joint preferred angle.*/
	void setPreferredAngle(const Double3ID& pa){fprintf_s(mFile,"connectAttr \"");pa.write(mFile);fprintf_s(mFile,"\" \"%s.pa\";\n",mName.c_str());}
	/*Joint preferred angle X.*/
	void setPreferredAngleX(double pax){if(pax == 0) return; fprintf_s(mFile, "setAttr \".pa.pax\" %f;\n", pax);}
	/*Joint preferred angle X.*/
	void setPreferredAngleX(const DoubleID& pax){fprintf_s(mFile,"connectAttr \"");pax.write(mFile);fprintf_s(mFile,"\" \"%s.pa.pax\";\n",mName.c_str());}
	/*Joint preferred angle Y.*/
	void setPreferredAngleY(double pay){if(pay == 0) return; fprintf_s(mFile, "setAttr \".pa.pay\" %f;\n", pay);}
	/*Joint preferred angle Y.*/
	void setPreferredAngleY(const DoubleID& pay){fprintf_s(mFile,"connectAttr \"");pay.write(mFile);fprintf_s(mFile,"\" \"%s.pa.pay\";\n",mName.c_str());}
	/*Joint preferred angle Z.*/
	void setPreferredAngleZ(double paz){if(paz == 0) return; fprintf_s(mFile, "setAttr \".pa.paz\" %f;\n", paz);}
	/*Joint preferred angle Z.*/
	void setPreferredAngleZ(const DoubleID& paz){fprintf_s(mFile,"connectAttr \"");paz.write(mFile);fprintf_s(mFile,"\" \"%s.pa.paz\";\n",mName.c_str());}
	/*Joint min rotate damping range.*/
	void setMinRotateDampRange(const double3& ndr){fprintf_s(mFile, "setAttr \".ndr\" -type \"double3\" ");ndr.write(mFile);fprintf_s(mFile,";\n");}
	/*Joint min rotate damping range.*/
	void setMinRotateDampRange(const Double3ID& ndr){fprintf_s(mFile,"connectAttr \"");ndr.write(mFile);fprintf_s(mFile,"\" \"%s.ndr\";\n",mName.c_str());}
	/*Joint min rotate damping range X.*/
	void setMinRotateDampRangeX(double ndx){if(ndx == 0) return; fprintf_s(mFile, "setAttr \".ndr.ndx\" %f;\n", ndx);}
	/*Joint min rotate damping range X.*/
	void setMinRotateDampRangeX(const DoubleID& ndx){fprintf_s(mFile,"connectAttr \"");ndx.write(mFile);fprintf_s(mFile,"\" \"%s.ndr.ndx\";\n",mName.c_str());}
	/*Joint min rotate damping range Y.*/
	void setMinRotateDampRangeY(double ndy){if(ndy == 0) return; fprintf_s(mFile, "setAttr \".ndr.ndy\" %f;\n", ndy);}
	/*Joint min rotate damping range Y.*/
	void setMinRotateDampRangeY(const DoubleID& ndy){fprintf_s(mFile,"connectAttr \"");ndy.write(mFile);fprintf_s(mFile,"\" \"%s.ndr.ndy\";\n",mName.c_str());}
	/*Joint min rotate damping range Z.*/
	void setMinRotateDampRangeZ(double ndz){if(ndz == 0) return; fprintf_s(mFile, "setAttr \".ndr.ndz\" %f;\n", ndz);}
	/*Joint min rotate damping range Z.*/
	void setMinRotateDampRangeZ(const DoubleID& ndz){fprintf_s(mFile,"connectAttr \"");ndz.write(mFile);fprintf_s(mFile,"\" \"%s.ndr.ndz\";\n",mName.c_str());}
	/*Joint min rotate damping strength.*/
	void setMinRotateDampStrength(const double3& nst){fprintf_s(mFile, "setAttr \".nst\" -type \"double3\" ");nst.write(mFile);fprintf_s(mFile,";\n");}
	/*Joint min rotate damping strength.*/
	void setMinRotateDampStrength(const Double3ID& nst){fprintf_s(mFile,"connectAttr \"");nst.write(mFile);fprintf_s(mFile,"\" \"%s.nst\";\n",mName.c_str());}
	/*Joint min rotate damping strength X.*/
	void setMinRotateDampStrengthX(double nstx){if(nstx == 0.0) return; fprintf_s(mFile, "setAttr \".nst.nstx\" %f;\n", nstx);}
	/*Joint min rotate damping strength X.*/
	void setMinRotateDampStrengthX(const DoubleID& nstx){fprintf_s(mFile,"connectAttr \"");nstx.write(mFile);fprintf_s(mFile,"\" \"%s.nst.nstx\";\n",mName.c_str());}
	/*Joint min rotate damping strength Y.*/
	void setMinRotateDampStrengthY(double nsty){if(nsty == 0.0) return; fprintf_s(mFile, "setAttr \".nst.nsty\" %f;\n", nsty);}
	/*Joint min rotate damping strength Y.*/
	void setMinRotateDampStrengthY(const DoubleID& nsty){fprintf_s(mFile,"connectAttr \"");nsty.write(mFile);fprintf_s(mFile,"\" \"%s.nst.nsty\";\n",mName.c_str());}
	/*Joint min rotate damping strength Z.*/
	void setMinRotateDampStrengthZ(double nstz){if(nstz == 0.0) return; fprintf_s(mFile, "setAttr \".nst.nstz\" %f;\n", nstz);}
	/*Joint min rotate damping strength Z.*/
	void setMinRotateDampStrengthZ(const DoubleID& nstz){fprintf_s(mFile,"connectAttr \"");nstz.write(mFile);fprintf_s(mFile,"\" \"%s.nst.nstz\";\n",mName.c_str());}
	/*Joint max rotate damping range.*/
	void setMaxRotateDampRange(const double3& xdr){fprintf_s(mFile, "setAttr \".xdr\" -type \"double3\" ");xdr.write(mFile);fprintf_s(mFile,";\n");}
	/*Joint max rotate damping range.*/
	void setMaxRotateDampRange(const Double3ID& xdr){fprintf_s(mFile,"connectAttr \"");xdr.write(mFile);fprintf_s(mFile,"\" \"%s.xdr\";\n",mName.c_str());}
	/*Joint max rotate damping range X.*/
	void setMaxRotateDampRangeX(double xdx){if(xdx == 0) return; fprintf_s(mFile, "setAttr \".xdr.xdx\" %f;\n", xdx);}
	/*Joint max rotate damping range X.*/
	void setMaxRotateDampRangeX(const DoubleID& xdx){fprintf_s(mFile,"connectAttr \"");xdx.write(mFile);fprintf_s(mFile,"\" \"%s.xdr.xdx\";\n",mName.c_str());}
	/*Joint max rotate damping range Y.*/
	void setMaxRotateDampRangeY(double xdy){if(xdy == 0) return; fprintf_s(mFile, "setAttr \".xdr.xdy\" %f;\n", xdy);}
	/*Joint max rotate damping range Y.*/
	void setMaxRotateDampRangeY(const DoubleID& xdy){fprintf_s(mFile,"connectAttr \"");xdy.write(mFile);fprintf_s(mFile,"\" \"%s.xdr.xdy\";\n",mName.c_str());}
	/*Joint max rotate damping range Z.*/
	void setMaxRotateDampRangeZ(double xdz){if(xdz == 0) return; fprintf_s(mFile, "setAttr \".xdr.xdz\" %f;\n", xdz);}
	/*Joint max rotate damping range Z.*/
	void setMaxRotateDampRangeZ(const DoubleID& xdz){fprintf_s(mFile,"connectAttr \"");xdz.write(mFile);fprintf_s(mFile,"\" \"%s.xdr.xdz\";\n",mName.c_str());}
	/*Joint max rotate damping strength.*/
	void setMaxRotateDampStrength(const double3& xst){fprintf_s(mFile, "setAttr \".xst\" -type \"double3\" ");xst.write(mFile);fprintf_s(mFile,";\n");}
	/*Joint max rotate damping strength.*/
	void setMaxRotateDampStrength(const Double3ID& xst){fprintf_s(mFile,"connectAttr \"");xst.write(mFile);fprintf_s(mFile,"\" \"%s.xst\";\n",mName.c_str());}
	/*Joint max rotate damping strength X.*/
	void setMaxRotateDampStrengthX(double xstx){if(xstx == 0.0) return; fprintf_s(mFile, "setAttr \".xst.xstx\" %f;\n", xstx);}
	/*Joint max rotate damping strength X.*/
	void setMaxRotateDampStrengthX(const DoubleID& xstx){fprintf_s(mFile,"connectAttr \"");xstx.write(mFile);fprintf_s(mFile,"\" \"%s.xst.xstx\";\n",mName.c_str());}
	/*Joint max rotate damping strength Y.*/
	void setMaxRotateDampStrengthY(double xsty){if(xsty == 0.0) return; fprintf_s(mFile, "setAttr \".xst.xsty\" %f;\n", xsty);}
	/*Joint max rotate damping strength Y.*/
	void setMaxRotateDampStrengthY(const DoubleID& xsty){fprintf_s(mFile,"connectAttr \"");xsty.write(mFile);fprintf_s(mFile,"\" \"%s.xst.xsty\";\n",mName.c_str());}
	/*Joint max rotate damping strength Z.*/
	void setMaxRotateDampStrengthZ(double xstz){if(xstz == 0.0) return; fprintf_s(mFile, "setAttr \".xst.xstz\" %f;\n", xstz);}
	/*Joint max rotate damping strength Z.*/
	void setMaxRotateDampStrengthZ(const DoubleID& xstz){fprintf_s(mFile,"connectAttr \"");xstz.write(mFile);fprintf_s(mFile,"\" \"%s.xst.xstz\";\n",mName.c_str());}
	/*
	joint bind pose for binding skin. This attribute is connected to the dagPose
	node that stores the bindPose info for the joint. This attribute stores the
	world matrix of the joint at the time of the bind.
	The bindPose matrix is undefined if no bindSkin operation
	has been performed.
	*/
	void setBindPose(const matrix& bps){if(bps == identity) return; fprintf_s(mFile, "setAttr \".bps\" -type \"matrix\" ");bps.write(mFile);fprintf_s(mFile,";\n");}
	/*
	joint bind pose for binding skin. This attribute is connected to the dagPose
	node that stores the bindPose info for the joint. This attribute stores the
	world matrix of the joint at the time of the bind.
	The bindPose matrix is undefined if no bindSkin operation
	has been performed.
	*/
	void setBindPose(const MatrixID& bps){fprintf_s(mFile,"connectAttr \"");bps.write(mFile);fprintf_s(mFile,"\" \"%s.bps\";\n",mName.c_str());}
	/*
	This attribute controls how the joint is drawn if it has multiple
	child joints. The "bone" draw style indicates that a unique bone will be drawn
	from this joint to each child joint. The "box" draw style indicates that
	a single box will be drawn to represent the joint and its children. The
	box size is chosen as a bounding box of the children joints. Typically the
	"bone" draw style is preferable if you are creating a complex skeletal
	hierarchy such as human ribs, while the "box" draw style is preferable
	for representing a large bone with multiple children such as the pelvic bone.
	*/
	void setDrawStyle(unsigned int ds){if(ds == 0) return; fprintf_s(mFile, "setAttr \".ds\" %i;\n", ds);}
	/*
	When enabled, the joint side and type attribute values are drawn as
	text next to the joint.
	*/
	void setDrawLabel(bool dl){if(dl == false) return; fprintf_s(mFile, "setAttr \".dl\" %i;\n", dl);}
	/*
	When enabled, the joint side and type attribute values are drawn as
	text next to the joint.
	*/
	void setDrawLabel(const BoolID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*
	This attribute can be used to specify the joint's side in the puppet.
	This information is used when retargeting animation info from one hierarchy to another.
	*/
	void setSide(unsigned int sd){if(sd == 0) return; fprintf_s(mFile, "setAttr \".sd\" %i;\n", sd);}
	/*
	This attribute can be used to specify the joint's part in the puppet.
	This information is used when retargeting animation info from one hierarchy to another.
	*/
	void setType(unsigned int typ){if(typ == 0) return; fprintf_s(mFile, "setAttr \".typ\" %i;\n", typ);}
	/*When the puppetPart is set to "Other", this string should be used to describe the part type.*/
	void setOtherType(const string& otp){if(otp == "jaw") return; fprintf_s(mFile, "setAttr \".otp\" -type \"string\" ");otp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The joint's radius which, when multiplied by the global joint scaling factor,
	determines how wide the bone should be when displayed.
	*/
	void setRadius(double radi){if(radi == 1.0) return; fprintf_s(mFile, "setAttr \".radi\" %f;\n", radi);}
	/*
	The joint's radius which, when multiplied by the global joint scaling factor,
	determines how wide the bone should be when displayed.
	*/
	void setRadius(const DoubleID& radi){fprintf_s(mFile,"connectAttr \"");radi.write(mFile);fprintf_s(mFile,"\" \"%s.radi\";\n",mName.c_str());}
	/*The HumanIK nodeId. This is for internal use by Maya and should never be modified manually.*/
	void setHikNodeID(int hni){if(hni == -1) return; fprintf_s(mFile, "setAttr \".hni\" %i;\n", hni);}
	/*The HumanIK nodeId. This is for internal use by Maya and should never be modified manually.*/
	void setHikNodeID(const IntID& hni){fprintf_s(mFile,"connectAttr \"");hni.write(mFile);fprintf_s(mFile,"\" \"%s.hni\";\n",mName.c_str());}
	/*Joint dof has "X" component.*/
	BoolID getJointTypeX(){char buffer[4096];sprintf_s (buffer, "%s.jtx",mName.c_str());return (const char*)buffer;}
	/*Joint dof has "Y" component.*/
	BoolID getJointTypeY(){char buffer[4096];sprintf_s (buffer, "%s.jty",mName.c_str());return (const char*)buffer;}
	/*Joint dof has "Z" component.*/
	BoolID getJointTypeZ(){char buffer[4096];sprintf_s (buffer, "%s.jtz",mName.c_str());return (const char*)buffer;}
	/*Joint orient.*/
	Double3ID getJointOrient(){char buffer[4096];sprintf_s (buffer, "%s.jo",mName.c_str());return (const char*)buffer;}
	/*Joint orientX.*/
	DoubleID getJointOrientX(){char buffer[4096];sprintf_s (buffer, "%s.jo.jox",mName.c_str());return (const char*)buffer;}
	/*Joint orientY.*/
	DoubleID getJointOrientY(){char buffer[4096];sprintf_s (buffer, "%s.jo.joy",mName.c_str());return (const char*)buffer;}
	/*Joint orientZ.*/
	DoubleID getJointOrientZ(){char buffer[4096];sprintf_s (buffer, "%s.jo.joz",mName.c_str());return (const char*)buffer;}
	/*Indicates whether to compensate for the scale of the parent joint.*/
	BoolID getSegmentScaleCompensate(){char buffer[4096];sprintf_s (buffer, "%s.ssc",mName.c_str());return (const char*)buffer;}
	/*The scale of the parent joint.*/
	Double3ID getInverseScale(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*X component of aParentScale.*/
	DoubleID getInverseScaleX(){char buffer[4096];sprintf_s (buffer, "%s.is.isx",mName.c_str());return (const char*)buffer;}
	/*Y component of aParentScale.*/
	DoubleID getInverseScaleY(){char buffer[4096];sprintf_s (buffer, "%s.is.isy",mName.c_str());return (const char*)buffer;}
	/*Z component of aParentScale.*/
	DoubleID getInverseScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.is.isz",mName.c_str());return (const char*)buffer;}
	/*Joint stiffness.*/
	Double3ID getStiffness(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*Joint stiffness X.*/
	DoubleID getStiffnessX(){char buffer[4096];sprintf_s (buffer, "%s.st.stx",mName.c_str());return (const char*)buffer;}
	/*Joint stiffness Y.*/
	DoubleID getStiffnessY(){char buffer[4096];sprintf_s (buffer, "%s.st.sty",mName.c_str());return (const char*)buffer;}
	/*Joint stiffness Z.*/
	DoubleID getStiffnessZ(){char buffer[4096];sprintf_s (buffer, "%s.st.stz",mName.c_str());return (const char*)buffer;}
	/*Joint preferred angle.*/
	Double3ID getPreferredAngle(){char buffer[4096];sprintf_s (buffer, "%s.pa",mName.c_str());return (const char*)buffer;}
	/*Joint preferred angle X.*/
	DoubleID getPreferredAngleX(){char buffer[4096];sprintf_s (buffer, "%s.pa.pax",mName.c_str());return (const char*)buffer;}
	/*Joint preferred angle Y.*/
	DoubleID getPreferredAngleY(){char buffer[4096];sprintf_s (buffer, "%s.pa.pay",mName.c_str());return (const char*)buffer;}
	/*Joint preferred angle Z.*/
	DoubleID getPreferredAngleZ(){char buffer[4096];sprintf_s (buffer, "%s.pa.paz",mName.c_str());return (const char*)buffer;}
	/*Joint min rotate damping range.*/
	Double3ID getMinRotateDampRange(){char buffer[4096];sprintf_s (buffer, "%s.ndr",mName.c_str());return (const char*)buffer;}
	/*Joint min rotate damping range X.*/
	DoubleID getMinRotateDampRangeX(){char buffer[4096];sprintf_s (buffer, "%s.ndr.ndx",mName.c_str());return (const char*)buffer;}
	/*Joint min rotate damping range Y.*/
	DoubleID getMinRotateDampRangeY(){char buffer[4096];sprintf_s (buffer, "%s.ndr.ndy",mName.c_str());return (const char*)buffer;}
	/*Joint min rotate damping range Z.*/
	DoubleID getMinRotateDampRangeZ(){char buffer[4096];sprintf_s (buffer, "%s.ndr.ndz",mName.c_str());return (const char*)buffer;}
	/*Joint min rotate damping strength.*/
	Double3ID getMinRotateDampStrength(){char buffer[4096];sprintf_s (buffer, "%s.nst",mName.c_str());return (const char*)buffer;}
	/*Joint min rotate damping strength X.*/
	DoubleID getMinRotateDampStrengthX(){char buffer[4096];sprintf_s (buffer, "%s.nst.nstx",mName.c_str());return (const char*)buffer;}
	/*Joint min rotate damping strength Y.*/
	DoubleID getMinRotateDampStrengthY(){char buffer[4096];sprintf_s (buffer, "%s.nst.nsty",mName.c_str());return (const char*)buffer;}
	/*Joint min rotate damping strength Z.*/
	DoubleID getMinRotateDampStrengthZ(){char buffer[4096];sprintf_s (buffer, "%s.nst.nstz",mName.c_str());return (const char*)buffer;}
	/*Joint max rotate damping range.*/
	Double3ID getMaxRotateDampRange(){char buffer[4096];sprintf_s (buffer, "%s.xdr",mName.c_str());return (const char*)buffer;}
	/*Joint max rotate damping range X.*/
	DoubleID getMaxRotateDampRangeX(){char buffer[4096];sprintf_s (buffer, "%s.xdr.xdx",mName.c_str());return (const char*)buffer;}
	/*Joint max rotate damping range Y.*/
	DoubleID getMaxRotateDampRangeY(){char buffer[4096];sprintf_s (buffer, "%s.xdr.xdy",mName.c_str());return (const char*)buffer;}
	/*Joint max rotate damping range Z.*/
	DoubleID getMaxRotateDampRangeZ(){char buffer[4096];sprintf_s (buffer, "%s.xdr.xdz",mName.c_str());return (const char*)buffer;}
	/*Joint max rotate damping strength.*/
	Double3ID getMaxRotateDampStrength(){char buffer[4096];sprintf_s (buffer, "%s.xst",mName.c_str());return (const char*)buffer;}
	/*Joint max rotate damping strength X.*/
	DoubleID getMaxRotateDampStrengthX(){char buffer[4096];sprintf_s (buffer, "%s.xst.xstx",mName.c_str());return (const char*)buffer;}
	/*Joint max rotate damping strength Y.*/
	DoubleID getMaxRotateDampStrengthY(){char buffer[4096];sprintf_s (buffer, "%s.xst.xsty",mName.c_str());return (const char*)buffer;}
	/*Joint max rotate damping strength Z.*/
	DoubleID getMaxRotateDampStrengthZ(){char buffer[4096];sprintf_s (buffer, "%s.xst.xstz",mName.c_str());return (const char*)buffer;}
	/*
	joint bind pose for binding skin. This attribute is connected to the dagPose
	node that stores the bindPose info for the joint. This attribute stores the
	world matrix of the joint at the time of the bind.
	The bindPose matrix is undefined if no bindSkin operation
	has been performed.
	*/
	MatrixID getBindPose(){char buffer[4096];sprintf_s (buffer, "%s.bps",mName.c_str());return (const char*)buffer;}
	/*
	When enabled, the joint side and type attribute values are drawn as
	text next to the joint.
	*/
	BoolID getDrawLabel(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*
	The joint's radius which, when multiplied by the global joint scaling factor,
	determines how wide the bone should be when displayed.
	*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.radi",mName.c_str());return (const char*)buffer;}
	/*The HumanIK nodeId. This is for internal use by Maya and should never be modified manually.*/
	IntID getHikNodeID(){char buffer[4096];sprintf_s (buffer, "%s.hni",mName.c_str());return (const char*)buffer;}
protected:
	Joint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_JOINT_H__
