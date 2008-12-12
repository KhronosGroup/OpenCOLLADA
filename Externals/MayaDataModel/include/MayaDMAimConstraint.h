/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AIMCONSTRAINT_H__
#define __MayaDM_AIMCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
/*
This node implements an aimConstraint.  Each constraint has a set
        of targets that are connected under the target attribute, a single
        constrained object that is connected to the constraint* attributes,
        and possibly other information to help compute the correct results.
        In the case of the aimConstraint, the additional information is:
        aimVector, upVector, worldUpVector, worldUpMatrix, and
        worldUpType.

        <p/>The aimConstraint node can have any number of target inputs.
        Each target is connected to attributes inside a single element
        of the target attribute.  For example, the first target object
        would be connected elements of target[0], the second target object
        would be connected to elements of target[1], etc.  The elements of
        each target are: targetTranslate, targetRotatePivot,
        targetRotateTranslate, targetParentMatrix, and targetWeight.

        <p/>The elements of each target are normally connected to the target
        objects as follows:
        <blockquote>
                <table>
                        <tr>
                                <th>aimConstraint attribute</th>
                                <th>connected to</th>
                        </tr>
                        <tr>
                                <td>targetTranslate</td>
                                <td>translate</td>
                        </tr>
                        <tr>
                                <td>targetRotatePivot</td>
                                <td>rotatePivot</td>
                        </tr>
                        <tr>
                                <td>targetRotateTranslate</td>
                                <td>rotatePivotTranslate</td>
                        </tr>
                        <tr>
                                <td>targetParentMatrix</td>
                                <td>parentMatrix[<i>i</i>]</td>
                        </tr>
                        <tr>
                                <td>targetWeight</td>
                                <td><i>set to 1.0</i></td>
                        </tr>
                </table>
        </blockquote>

        <p/>The targetWeight attribute is not generally connected to the
        target object.  Instead, it may be animated by other means to
        adjust the weighted average computation for the target point.

        <p/>The aimConstraint node uses these inputs to compute the world
        space position of the pivot point of each target object.  It then
        computes a weighted average of the these pivot points.  This
        weighted average is called the target point.

        <p/>The constrained object is connected to the constraint*
        attributes.  For an aimConstraint, the constraintTranslate,
        constraintRotatePivot, constraintRotateTranslate,
        constraintJointOrient, and constraintParentInverseMatrix are
        inputs to the aimConstraint.  The attributes constraintRotate and
        constraintVector are outputs.

        <p/>The additional aimConstraint inputs tell the constraint node
        how to orient the constrained object.  The aimVector attribute
        defines a vector in the space of the constrained object that
        should be oriented along the line from the pivot point of the
        constrained object to the target point.  The upVector,
        worldUpVector, worldUpMatrix, and worldUpType define how the
        constrained object is rotated about the aimVector.

        <p/>The upVector defines a vector in the space of the constrained
        object, very much like the aimVector does.  The constrained object is
        rotated so that the aimVector points at the target point and so that
        the upVector aligns as closely as possible with the computed world up
        vector.  The world up vector is determined by the worldUpType,
        worldUpVector, and worldUpMatrix attributes.

        <p/>The attribute worldUpType can have one of 5 values, which affects the
        calculation of the world up vector as shown in the following table.
        <blockquote>
                <table border="1">
                        <tr>
                                <th>Mnemonic</th>
                                <th>Value</th>
                                <th>Description</th>
                        </tr>
                        <tr>
                                <td>scene</td>
                                <td>0</td>
                                <td>
                                        The upVector is aligned with the up axis of the scene and
                                        worldUpVector and worldUpObject are ignored.
                                </td>
                        </tr>
                        <tr>
                                <td>object</td>
                                <td>1</td>
                                <td>
                                        The upVector is aimed as closely as possible to the
                                        origin of the space of the worldUpObject and
                                        the worldUpVector is ignored.
                                </td>

                        </tr>
                        <tr>
                                <td>objectrotation</td>
                                <td>2</td>
                                <td>
                                        The worldUpVector is interpreted as being in
                                        the coordinate space of the worldUpObject, transformed
                                        into world space and the upVector is aligned as
                                        closely as possible to the result.
                                </td>
                        </tr>
                        <tr>
                                <td>vector</td>
                                <td>3</td>
                                <td>
                                        <strong>Default:</strong>
                                        The upVector is aligned with worldUpVector as closely as
                                        possible and worldUpMatrix is ignored.
                                </td>
                        </tr>
                        <tr>
                                <td>none</td>
                                <td>4</td>
                                <td>
                                        No up vector is used in the computation of the orientation of the
                                        constrained object; only the aim vector and the target's position
                                        are used. Specifying an up vector can cause flipping to occur if the
                  constrained object's new orientation vector is close to the up vector.
                                        If the worldUpType is instead set to none, this flipping won't happen,
                                        at a loss of control over twisting.
                                </td>
                        </tr>
                </table>
        </blockquote>

        <p/>While setAttr requires the numeric values for the worldUpType
        attribute, both numeric and mnemonic values are allowed by the
        aimConstraint command.

        <p/>Although the all the constraint nodes inherit from transform,
        they do not actively use any of the attributes from transform.
*/
class AimConstraint : public Constraint
{
public:
	/*Array of all information for all the targets*/
	struct Target{
		double3 targetTranslate;
		double3 targetRotatePivot;
		double3 targetRotateTranslate;
		matrix targetParentMatrix;
		double targetWeight;
		void write(FILE* file) const
		{
			targetTranslate.write(file);
			fprintf_s(file, " ");
			targetRotatePivot.write(file);
			fprintf_s(file, " ");
			targetRotateTranslate.write(file);
			fprintf_s(file, " ");
			targetParentMatrix.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f", targetWeight);
		}
	};
public:
	AimConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "aimConstraint"){}
	virtual ~AimConstraint(){}
	/*Array of all information for all the targets*/
	void setTarget(size_t tg_i,const Target& tg){fprintf_s(mFile, "setAttr \".tg[%i]\" ",tg_i);tg.write(mFile);fprintf_s(mFile,";\n");}
	/*Array of all information for all the targets*/
	void setTarget(size_t tg_i,const TargetID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i]\";\n",mName.c_str(),tg_i);}
	/*Input translate of a target.*/
	void setTargetTranslate(size_t tg_i,const double3& tt){fprintf_s(mFile, "setAttr \".tg[%i].tt\" -type \"double3\" ",tg_i);tt.write(mFile);fprintf_s(mFile,";\n");}
	/*Input translate of a target.*/
	void setTargetTranslate(size_t tg_i,const Double3ID& tt){fprintf_s(mFile,"connectAttr \"");tt.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tt\";\n",mName.c_str(),tg_i);}
	/*Input translateX of a target.*/
	void setTargetTranslateX(size_t tg_i,double ttx){if(ttx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tt.ttx\" %f;\n", tg_i,ttx);}
	/*Input translateX of a target.*/
	void setTargetTranslateX(size_t tg_i,const DoubleID& ttx){fprintf_s(mFile,"connectAttr \"");ttx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tt.ttx\";\n",mName.c_str(),tg_i);}
	/*Input translateY of a target.*/
	void setTargetTranslateY(size_t tg_i,double tty){if(tty == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tt.tty\" %f;\n", tg_i,tty);}
	/*Input translateY of a target.*/
	void setTargetTranslateY(size_t tg_i,const DoubleID& tty){fprintf_s(mFile,"connectAttr \"");tty.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tt.tty\";\n",mName.c_str(),tg_i);}
	/*Input translateZ of a target.*/
	void setTargetTranslateZ(size_t tg_i,double ttz){if(ttz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tt.ttz\" %f;\n", tg_i,ttz);}
	/*Input translateZ of a target.*/
	void setTargetTranslateZ(size_t tg_i,const DoubleID& ttz){fprintf_s(mFile,"connectAttr \"");ttz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tt.ttz\";\n",mName.c_str(),tg_i);}
	/*Input rotatePivot of a target.*/
	void setTargetRotatePivot(size_t tg_i,const double3& trp){fprintf_s(mFile, "setAttr \".tg[%i].trp\" -type \"double3\" ",tg_i);trp.write(mFile);fprintf_s(mFile,";\n");}
	/*Input rotatePivot of a target.*/
	void setTargetRotatePivot(size_t tg_i,const Double3ID& trp){fprintf_s(mFile,"connectAttr \"");trp.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trp\";\n",mName.c_str(),tg_i);}
	/*Input rotatePivotX of a target.*/
	void setTargetRotatePivotX(size_t tg_i,double trpx){if(trpx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trp.trpx\" %f;\n", tg_i,trpx);}
	/*Input rotatePivotX of a target.*/
	void setTargetRotatePivotX(size_t tg_i,const DoubleID& trpx){fprintf_s(mFile,"connectAttr \"");trpx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trp.trpx\";\n",mName.c_str(),tg_i);}
	/*Input rotatePivotY of a target.*/
	void setTargetRotatePivotY(size_t tg_i,double trpy){if(trpy == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trp.trpy\" %f;\n", tg_i,trpy);}
	/*Input rotatePivotY of a target.*/
	void setTargetRotatePivotY(size_t tg_i,const DoubleID& trpy){fprintf_s(mFile,"connectAttr \"");trpy.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trp.trpy\";\n",mName.c_str(),tg_i);}
	/*Input rotatePivotZ of a target.*/
	void setTargetRotatePivotZ(size_t tg_i,double trpz){if(trpz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trp.trpz\" %f;\n", tg_i,trpz);}
	/*Input rotatePivotZ of a target.*/
	void setTargetRotatePivotZ(size_t tg_i,const DoubleID& trpz){fprintf_s(mFile,"connectAttr \"");trpz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trp.trpz\";\n",mName.c_str(),tg_i);}
	/*Input rotatePivotTranslate of a target.*/
	void setTargetRotateTranslate(size_t tg_i,const double3& trt){fprintf_s(mFile, "setAttr \".tg[%i].trt\" -type \"double3\" ",tg_i);trt.write(mFile);fprintf_s(mFile,";\n");}
	/*Input rotatePivotTranslate of a target.*/
	void setTargetRotateTranslate(size_t tg_i,const Double3ID& trt){fprintf_s(mFile,"connectAttr \"");trt.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trt\";\n",mName.c_str(),tg_i);}
	/*Input rotatePivotTranslateX of a target.*/
	void setTargetRotateTranslateX(size_t tg_i,double trtx){if(trtx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trt.trtx\" %f;\n", tg_i,trtx);}
	/*Input rotatePivotTranslateX of a target.*/
	void setTargetRotateTranslateX(size_t tg_i,const DoubleID& trtx){fprintf_s(mFile,"connectAttr \"");trtx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trt.trtx\";\n",mName.c_str(),tg_i);}
	/*Input rotatePivotTranslateY of a target.*/
	void setTargetRotateTranslateY(size_t tg_i,double trty){if(trty == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trt.trty\" %f;\n", tg_i,trty);}
	/*Input rotatePivotTranslateY of a target.*/
	void setTargetRotateTranslateY(size_t tg_i,const DoubleID& trty){fprintf_s(mFile,"connectAttr \"");trty.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trt.trty\";\n",mName.c_str(),tg_i);}
	/*Input rotatePivotTranslateZ of a target.*/
	void setTargetRotateTranslateZ(size_t tg_i,double trtz){if(trtz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trt.trtz\" %f;\n", tg_i,trtz);}
	/*Input rotatePivotTranslateZ of a target.*/
	void setTargetRotateTranslateZ(size_t tg_i,const DoubleID& trtz){fprintf_s(mFile,"connectAttr \"");trtz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trt.trtz\";\n",mName.c_str(),tg_i);}
	/*Input parentMatrix of a target.*/
	void setTargetParentMatrix(size_t tg_i,const matrix& tpm){if(tpm == identity) return; fprintf_s(mFile, "setAttr \".tg[%i].tpm\" -type \"matrix\" ",tg_i);tpm.write(mFile);fprintf_s(mFile,";\n");}
	/*Input parentMatrix of a target.*/
	void setTargetParentMatrix(size_t tg_i,const MatrixID& tpm){fprintf_s(mFile,"connectAttr \"");tpm.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tpm\";\n",mName.c_str(),tg_i);}
	/*Input weight for a target.*/
	void setTargetWeight(size_t tg_i,double tw){if(tw == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].tw\" %f;\n", tg_i,tw);}
	/*Input weight for a target.*/
	void setTargetWeight(size_t tg_i,const DoubleID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tw\";\n",mName.c_str(),tg_i);}
	/*Input parentInverseMatrix for the constrained object.*/
	void setConstraintParentInverseMatrix(const matrix& cpim){if(cpim == identity) return; fprintf_s(mFile, "setAttr \".cpim\" -type \"matrix\" ");cpim.write(mFile);fprintf_s(mFile,";\n");}
	/*Input parentInverseMatrix for the constrained object.*/
	void setConstraintParentInverseMatrix(const MatrixID& cpim){fprintf_s(mFile,"connectAttr \"");cpim.write(mFile);fprintf_s(mFile,"\" \"%s.cpim\";\n",mName.c_str());}
	/*Input aimVector in constrained object coordinate system.*/
	void setAimVector(const double3& a){if(a == double3(1.0,0.0,0.0)) return; fprintf_s(mFile, "setAttr \".a\" -type \"double3\" ");a.write(mFile);fprintf_s(mFile,";\n");}
	/*Input aimVector in constrained object coordinate system.*/
	void setAimVector(const Double3ID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*Input aimVectorX in constrained object coordinate system.*/
	void setAimVectorX(double ax){if(ax == 1.0) return; fprintf_s(mFile, "setAttr \".a.ax\" %f;\n", ax);}
	/*Input aimVectorX in constrained object coordinate system.*/
	void setAimVectorX(const DoubleID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.a.ax\";\n",mName.c_str());}
	/*Input aimVectorY in constrained object coordinate system.*/
	void setAimVectorY(double ay){if(ay == 0.0) return; fprintf_s(mFile, "setAttr \".a.ay\" %f;\n", ay);}
	/*Input aimVectorY in constrained object coordinate system.*/
	void setAimVectorY(const DoubleID& ay){fprintf_s(mFile,"connectAttr \"");ay.write(mFile);fprintf_s(mFile,"\" \"%s.a.ay\";\n",mName.c_str());}
	/*Input aimVectorZ in constrained object coordinate system.*/
	void setAimVectorZ(double az){if(az == 0.0) return; fprintf_s(mFile, "setAttr \".a.az\" %f;\n", az);}
	/*Input aimVectorZ in constrained object coordinate system.*/
	void setAimVectorZ(const DoubleID& az){fprintf_s(mFile,"connectAttr \"");az.write(mFile);fprintf_s(mFile,"\" \"%s.a.az\";\n",mName.c_str());}
	/*Input upVector in constrained object coordinate system.*/
	void setUpVector(const double3& u){if(u == double3(0.0,1.0,0.0)) return; fprintf_s(mFile, "setAttr \".u\" -type \"double3\" ");u.write(mFile);fprintf_s(mFile,";\n");}
	/*Input upVector in constrained object coordinate system.*/
	void setUpVector(const Double3ID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*Input upVectorX in constrained object coordinate system.*/
	void setUpVectorX(double ux){if(ux == 0.0) return; fprintf_s(mFile, "setAttr \".u.ux\" %f;\n", ux);}
	/*Input upVectorX in constrained object coordinate system.*/
	void setUpVectorX(const DoubleID& ux){fprintf_s(mFile,"connectAttr \"");ux.write(mFile);fprintf_s(mFile,"\" \"%s.u.ux\";\n",mName.c_str());}
	/*Input upVectorY in constrained object coordinate system.*/
	void setUpVectorY(double uy){if(uy == 1.0) return; fprintf_s(mFile, "setAttr \".u.uy\" %f;\n", uy);}
	/*Input upVectorY in constrained object coordinate system.*/
	void setUpVectorY(const DoubleID& uy){fprintf_s(mFile,"connectAttr \"");uy.write(mFile);fprintf_s(mFile,"\" \"%s.u.uy\";\n",mName.c_str());}
	/*Input upVectorZ in constrained object coordinate system.*/
	void setUpVectorZ(double uz){if(uz == 0.0) return; fprintf_s(mFile, "setAttr \".u.uz\" %f;\n", uz);}
	/*Input upVectorZ in constrained object coordinate system.*/
	void setUpVectorZ(const DoubleID& uz){fprintf_s(mFile,"connectAttr \"");uz.write(mFile);fprintf_s(mFile,"\" \"%s.u.uz\";\n",mName.c_str());}
	/*Input worldUpVector in world coordinates.*/
	void setWorldUpVector(const double3& wu){if(wu == double3(0.0,1.0,0.0)) return; fprintf_s(mFile, "setAttr \".wu\" -type \"double3\" ");wu.write(mFile);fprintf_s(mFile,";\n");}
	/*Input worldUpVector in world coordinates.*/
	void setWorldUpVector(const Double3ID& wu){fprintf_s(mFile,"connectAttr \"");wu.write(mFile);fprintf_s(mFile,"\" \"%s.wu\";\n",mName.c_str());}
	/*Input worldUpVectorX in world coordinates.*/
	void setWorldUpVectorX(double wux){if(wux == 0.0) return; fprintf_s(mFile, "setAttr \".wu.wux\" %f;\n", wux);}
	/*Input worldUpVectorX in world coordinates.*/
	void setWorldUpVectorX(const DoubleID& wux){fprintf_s(mFile,"connectAttr \"");wux.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wux\";\n",mName.c_str());}
	/*Input worldUpVectorY in world coordinates.*/
	void setWorldUpVectorY(double wuy){if(wuy == 1.0) return; fprintf_s(mFile, "setAttr \".wu.wuy\" %f;\n", wuy);}
	/*Input worldUpVectorY in world coordinates.*/
	void setWorldUpVectorY(const DoubleID& wuy){fprintf_s(mFile,"connectAttr \"");wuy.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wuy\";\n",mName.c_str());}
	/*Input worldUpVectorZ in world coordinates.*/
	void setWorldUpVectorZ(double wuz){if(wuz == 0.0) return; fprintf_s(mFile, "setAttr \".wu.wuz\" %f;\n", wuz);}
	/*Input worldUpVectorZ in world coordinates.*/
	void setWorldUpVectorZ(const DoubleID& wuz){fprintf_s(mFile,"connectAttr \"");wuz.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wuz\";\n",mName.c_str());}
	/*Input worldMatrix for the up object.*/
	void setWorldUpMatrix(const matrix& wum){if(wum == identity) return; fprintf_s(mFile, "setAttr \".wum\" -type \"matrix\" ");wum.write(mFile);fprintf_s(mFile,";\n");}
	/*Input worldMatrix for the up object.*/
	void setWorldUpMatrix(const MatrixID& wum){fprintf_s(mFile,"connectAttr \"");wum.write(mFile);fprintf_s(mFile,"\" \"%s.wum\";\n",mName.c_str());}
	/*Input control value for computation of world up vector.*/
	void setWorldUpType(unsigned int wut){if(wut == 3) return; fprintf_s(mFile, "setAttr \".wut\" %i;\n", wut);}
	/*Input control value for computation of world up vector.*/
	void setWorldUpType(const UnsignedintID& wut){fprintf_s(mFile,"connectAttr \"");wut.write(mFile);fprintf_s(mFile,"\" \"%s.wut\";\n",mName.c_str());}
	/*Input constrained object translate value.*/
	void setConstraintTranslate(const double3& ct){fprintf_s(mFile, "setAttr \".ct\" -type \"double3\" ");ct.write(mFile);fprintf_s(mFile,";\n");}
	/*Input constrained object translate value.*/
	void setConstraintTranslate(const Double3ID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*Input constrained object translateX value.*/
	void setConstraintTranslateX(double ctx){if(ctx == 0) return; fprintf_s(mFile, "setAttr \".ct.ctx\" %f;\n", ctx);}
	/*Input constrained object translateX value.*/
	void setConstraintTranslateX(const DoubleID& ctx){fprintf_s(mFile,"connectAttr \"");ctx.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctx\";\n",mName.c_str());}
	/*Input constrained object translateY value.*/
	void setConstraintTranslateY(double cty){if(cty == 0) return; fprintf_s(mFile, "setAttr \".ct.cty\" %f;\n", cty);}
	/*Input constrained object translateY value.*/
	void setConstraintTranslateY(const DoubleID& cty){fprintf_s(mFile,"connectAttr \"");cty.write(mFile);fprintf_s(mFile,"\" \"%s.ct.cty\";\n",mName.c_str());}
	/*Input constrained object translateZ value.*/
	void setConstraintTranslateZ(double ctz){if(ctz == 0) return; fprintf_s(mFile, "setAttr \".ct.ctz\" %f;\n", ctz);}
	/*Input constrained object translateZ value.*/
	void setConstraintTranslateZ(const DoubleID& ctz){fprintf_s(mFile,"connectAttr \"");ctz.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctz\";\n",mName.c_str());}
	/*Input constrained object rotatelPivot value.*/
	void setConstraintRotatePivot(const double3& crp){fprintf_s(mFile, "setAttr \".crp\" -type \"double3\" ");crp.write(mFile);fprintf_s(mFile,";\n");}
	/*Input constrained object rotatelPivot value.*/
	void setConstraintRotatePivot(const Double3ID& crp){fprintf_s(mFile,"connectAttr \"");crp.write(mFile);fprintf_s(mFile,"\" \"%s.crp\";\n",mName.c_str());}
	/*Input constrained object rotatelPivotX value.*/
	void setConstraintRotatePivotX(double crpx){if(crpx == 0) return; fprintf_s(mFile, "setAttr \".crp.crpx\" %f;\n", crpx);}
	/*Input constrained object rotatelPivotX value.*/
	void setConstraintRotatePivotX(const DoubleID& crpx){fprintf_s(mFile,"connectAttr \"");crpx.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpx\";\n",mName.c_str());}
	/*Input constrained object rotatelPivotY value.*/
	void setConstraintRotatePivotY(double crpy){if(crpy == 0) return; fprintf_s(mFile, "setAttr \".crp.crpy\" %f;\n", crpy);}
	/*Input constrained object rotatelPivotY value.*/
	void setConstraintRotatePivotY(const DoubleID& crpy){fprintf_s(mFile,"connectAttr \"");crpy.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpy\";\n",mName.c_str());}
	/*Input constrained object rotatelPivotZ value.*/
	void setConstraintRotatePivotZ(double crpz){if(crpz == 0) return; fprintf_s(mFile, "setAttr \".crp.crpz\" %f;\n", crpz);}
	/*Input constrained object rotatelPivotZ value.*/
	void setConstraintRotatePivotZ(const DoubleID& crpz){fprintf_s(mFile,"connectAttr \"");crpz.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpz\";\n",mName.c_str());}
	/*Input constrained object rotatePivotTranslate value.*/
	void setConstraintRotateTranslate(const double3& crt){fprintf_s(mFile, "setAttr \".crt\" -type \"double3\" ");crt.write(mFile);fprintf_s(mFile,";\n");}
	/*Input constrained object rotatePivotTranslate value.*/
	void setConstraintRotateTranslate(const Double3ID& crt){fprintf_s(mFile,"connectAttr \"");crt.write(mFile);fprintf_s(mFile,"\" \"%s.crt\";\n",mName.c_str());}
	/*Input constrained object rotatePivotTranslateX value.*/
	void setConstraintRotateTranslateX(double crtx){if(crtx == 0) return; fprintf_s(mFile, "setAttr \".crt.crtx\" %f;\n", crtx);}
	/*Input constrained object rotatePivotTranslateX value.*/
	void setConstraintRotateTranslateX(const DoubleID& crtx){fprintf_s(mFile,"connectAttr \"");crtx.write(mFile);fprintf_s(mFile,"\" \"%s.crt.crtx\";\n",mName.c_str());}
	/*Input constrained object rotatePivotTranslateY value.*/
	void setConstraintRotateTranslateY(double crty){if(crty == 0) return; fprintf_s(mFile, "setAttr \".crt.crty\" %f;\n", crty);}
	/*Input constrained object rotatePivotTranslateY value.*/
	void setConstraintRotateTranslateY(const DoubleID& crty){fprintf_s(mFile,"connectAttr \"");crty.write(mFile);fprintf_s(mFile,"\" \"%s.crt.crty\";\n",mName.c_str());}
	/*Input constrained object rotatePivotTranslateZ value.*/
	void setConstraintRotateTranslateZ(double crtz){if(crtz == 0) return; fprintf_s(mFile, "setAttr \".crt.crtz\" %f;\n", crtz);}
	/*Input constrained object rotatePivotTranslateZ value.*/
	void setConstraintRotateTranslateZ(const DoubleID& crtz){fprintf_s(mFile,"connectAttr \"");crtz.write(mFile);fprintf_s(mFile,"\" \"%s.crt.crtz\";\n",mName.c_str());}
	/*Input constrained object rotate order value.*/
	void setConstraintRotateOrder(unsigned int cro){if(cro == 0) return; fprintf_s(mFile, "setAttr \".cro\" %i;\n", cro);}
	/*Input constrained object rotate order value.*/
	void setConstraintRotateOrder(const UnsignedintID& cro){fprintf_s(mFile,"connectAttr \"");cro.write(mFile);fprintf_s(mFile,"\" \"%s.cro\";\n",mName.c_str());}
	/*Input constrained object joint orient (if any).*/
	void setConstraintJointOrient(const double3& cjo){fprintf_s(mFile, "setAttr \".cjo\" -type \"double3\" ");cjo.write(mFile);fprintf_s(mFile,";\n");}
	/*Input constrained object joint orient (if any).*/
	void setConstraintJointOrient(const Double3ID& cjo){fprintf_s(mFile,"connectAttr \"");cjo.write(mFile);fprintf_s(mFile,"\" \"%s.cjo\";\n",mName.c_str());}
	/*Input constrained object joint orient X.*/
	void setConstraintJointOrientX(double cjox){if(cjox == 0) return; fprintf_s(mFile, "setAttr \".cjo.cjox\" %f;\n", cjox);}
	/*Input constrained object joint orient X.*/
	void setConstraintJointOrientX(const DoubleID& cjox){fprintf_s(mFile,"connectAttr \"");cjox.write(mFile);fprintf_s(mFile,"\" \"%s.cjo.cjox\";\n",mName.c_str());}
	/*Input constrained object joint orient Y.*/
	void setConstraintJointOrientY(double cjoy){if(cjoy == 0) return; fprintf_s(mFile, "setAttr \".cjo.cjoy\" %f;\n", cjoy);}
	/*Input constrained object joint orient Y.*/
	void setConstraintJointOrientY(const DoubleID& cjoy){fprintf_s(mFile,"connectAttr \"");cjoy.write(mFile);fprintf_s(mFile,"\" \"%s.cjo.cjoy\";\n",mName.c_str());}
	/*Input constrained object joint orient Z.*/
	void setConstraintJointOrientZ(double cjoz){if(cjoz == 0) return; fprintf_s(mFile, "setAttr \".cjo.cjoz\" %f;\n", cjoz);}
	/*Input constrained object joint orient Z.*/
	void setConstraintJointOrientZ(const DoubleID& cjoz){fprintf_s(mFile,"connectAttr \"");cjoz.write(mFile);fprintf_s(mFile,"\" \"%s.cjo.cjoz\";\n",mName.c_str());}
	/*Output constrained object rotate.*/
	void setConstraintRotate(const Double3ID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*Output constrained object rotateX.*/
	void setConstraintRotateX(const DoubleID& crx){fprintf_s(mFile,"connectAttr \"");crx.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crx\";\n",mName.c_str());}
	/*Output constrained object rotateY.*/
	void setConstraintRotateY(const DoubleID& cry){fprintf_s(mFile,"connectAttr \"");cry.write(mFile);fprintf_s(mFile,"\" \"%s.cr.cry\";\n",mName.c_str());}
	/*Output constrained object rotateZ.*/
	void setConstraintRotateZ(const DoubleID& crz){fprintf_s(mFile,"connectAttr \"");crz.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crz\";\n",mName.c_str());}
	/*Output vector from constrained object to target position*/
	void setConstraintVector(const Double3ID& cv){fprintf_s(mFile,"connectAttr \"");cv.write(mFile);fprintf_s(mFile,"\" \"%s.cv\";\n",mName.c_str());}
	/*Output X vector from constrained object to target position*/
	void setConstraintVectorX(const DoubleID& cvx){fprintf_s(mFile,"connectAttr \"");cvx.write(mFile);fprintf_s(mFile,"\" \"%s.cv.cvx\";\n",mName.c_str());}
	/*Output Y vector from constrained object to target position*/
	void setConstraintVectorY(const DoubleID& cvy){fprintf_s(mFile,"connectAttr \"");cvy.write(mFile);fprintf_s(mFile,"\" \"%s.cv.cvy\";\n",mName.c_str());}
	/*Output Z vector from constrained object to target position*/
	void setConstraintVectorZ(const DoubleID& cvz){fprintf_s(mFile,"connectAttr \"");cvz.write(mFile);fprintf_s(mFile,"\" \"%s.cv.cvz\";\n",mName.c_str());}
	/*object offset*/
	void setOffset(const double3& o){fprintf_s(mFile, "setAttr \".o\" -type \"double3\" ");o.write(mFile);fprintf_s(mFile,";\n");}
	/*object offset*/
	void setOffset(const Double3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*object X offset*/
	void setOffsetX(double ox){if(ox == 0) return; fprintf_s(mFile, "setAttr \".o.ox\" %f;\n", ox);}
	/*object X offset*/
	void setOffsetX(const DoubleID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*object Y offset*/
	void setOffsetY(double oy){if(oy == 0) return; fprintf_s(mFile, "setAttr \".o.oy\" %f;\n", oy);}
	/*object Y offset*/
	void setOffsetY(const DoubleID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*object Z offset*/
	void setOffsetZ(double oz){if(oz == 0) return; fprintf_s(mFile, "setAttr \".o.oz\" %f;\n", oz);}
	/*object Z offset*/
	void setOffsetZ(const DoubleID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*rest orientation*/
	void setRestRotate(const double3& rsrr){fprintf_s(mFile, "setAttr \".rsrr\" -type \"double3\" ");rsrr.write(mFile);fprintf_s(mFile,";\n");}
	/*rest orientation*/
	void setRestRotate(const Double3ID& rsrr){fprintf_s(mFile,"connectAttr \"");rsrr.write(mFile);fprintf_s(mFile,"\" \"%s.rsrr\";\n",mName.c_str());}
	/*rest X orientation*/
	void setRestRotateX(double rrx){if(rrx == 0) return; fprintf_s(mFile, "setAttr \".rsrr.rrx\" %f;\n", rrx);}
	/*rest X orientation*/
	void setRestRotateX(const DoubleID& rrx){fprintf_s(mFile,"connectAttr \"");rrx.write(mFile);fprintf_s(mFile,"\" \"%s.rsrr.rrx\";\n",mName.c_str());}
	/*rest Y orientation*/
	void setRestRotateY(double rry){if(rry == 0) return; fprintf_s(mFile, "setAttr \".rsrr.rry\" %f;\n", rry);}
	/*rest Y orientation*/
	void setRestRotateY(const DoubleID& rry){fprintf_s(mFile,"connectAttr \"");rry.write(mFile);fprintf_s(mFile,"\" \"%s.rsrr.rry\";\n",mName.c_str());}
	/*rest Z orientation*/
	void setRestRotateZ(double rrz){if(rrz == 0) return; fprintf_s(mFile, "setAttr \".rsrr.rrz\" %f;\n", rrz);}
	/*rest Z orientation*/
	void setRestRotateZ(const DoubleID& rrz){fprintf_s(mFile,"connectAttr \"");rrz.write(mFile);fprintf_s(mFile,"\" \"%s.rsrr.rrz\";\n",mName.c_str());}
	/*
	Turning this on switches the offset calculation from computing an
	offset  rotation matrix, to simply adding the individual offset
	values to the x, y, and z rotation value computed by the constraint.
	*/
	void setUseOldOffsetCalculation(bool uooc){if(uooc == false) return; fprintf_s(mFile, "setAttr \".uooc\" %i;\n", uooc);}
	/*
	Turning this on switches the offset calculation from computing an
	offset  rotation matrix, to simply adding the individual offset
	values to the x, y, and z rotation value computed by the constraint.
	*/
	void setUseOldOffsetCalculation(const BoolID& uooc){fprintf_s(mFile,"connectAttr \"");uooc.write(mFile);fprintf_s(mFile,"\" \"%s.uooc\";\n",mName.c_str());}
	/*Array of all information for all the targets*/
	const TargetID& getTarget(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i]",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input translate of a target.*/
	const Double3ID& getTargetTranslate(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tt",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input translateX of a target.*/
	const DoubleID& getTargetTranslateX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tt.ttx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input translateY of a target.*/
	const DoubleID& getTargetTranslateY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tt.tty",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input translateZ of a target.*/
	const DoubleID& getTargetTranslateZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tt.ttz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input rotatePivot of a target.*/
	const Double3ID& getTargetRotatePivot(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trp",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input rotatePivotX of a target.*/
	const DoubleID& getTargetRotatePivotX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trp.trpx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input rotatePivotY of a target.*/
	const DoubleID& getTargetRotatePivotY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trp.trpy",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input rotatePivotZ of a target.*/
	const DoubleID& getTargetRotatePivotZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trp.trpz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input rotatePivotTranslate of a target.*/
	const Double3ID& getTargetRotateTranslate(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trt",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input rotatePivotTranslateX of a target.*/
	const DoubleID& getTargetRotateTranslateX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trt.trtx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input rotatePivotTranslateY of a target.*/
	const DoubleID& getTargetRotateTranslateY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trt.trty",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input rotatePivotTranslateZ of a target.*/
	const DoubleID& getTargetRotateTranslateZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trt.trtz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input parentMatrix of a target.*/
	const MatrixID& getTargetParentMatrix(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tpm",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input weight for a target.*/
	const DoubleID& getTargetWeight(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tw",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input parentInverseMatrix for the constrained object.*/
	MatrixID getConstraintParentInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cpim",mName.c_str());return (const char*)buffer;}
	/*Input aimVector in constrained object coordinate system.*/
	Double3ID getAimVector(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*Input aimVectorX in constrained object coordinate system.*/
	DoubleID getAimVectorX(){char buffer[4096];sprintf_s (buffer, "%s.a.ax",mName.c_str());return (const char*)buffer;}
	/*Input aimVectorY in constrained object coordinate system.*/
	DoubleID getAimVectorY(){char buffer[4096];sprintf_s (buffer, "%s.a.ay",mName.c_str());return (const char*)buffer;}
	/*Input aimVectorZ in constrained object coordinate system.*/
	DoubleID getAimVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.a.az",mName.c_str());return (const char*)buffer;}
	/*Input upVector in constrained object coordinate system.*/
	Double3ID getUpVector(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*Input upVectorX in constrained object coordinate system.*/
	DoubleID getUpVectorX(){char buffer[4096];sprintf_s (buffer, "%s.u.ux",mName.c_str());return (const char*)buffer;}
	/*Input upVectorY in constrained object coordinate system.*/
	DoubleID getUpVectorY(){char buffer[4096];sprintf_s (buffer, "%s.u.uy",mName.c_str());return (const char*)buffer;}
	/*Input upVectorZ in constrained object coordinate system.*/
	DoubleID getUpVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.u.uz",mName.c_str());return (const char*)buffer;}
	/*Input worldUpVector in world coordinates.*/
	Double3ID getWorldUpVector(){char buffer[4096];sprintf_s (buffer, "%s.wu",mName.c_str());return (const char*)buffer;}
	/*Input worldUpVectorX in world coordinates.*/
	DoubleID getWorldUpVectorX(){char buffer[4096];sprintf_s (buffer, "%s.wu.wux",mName.c_str());return (const char*)buffer;}
	/*Input worldUpVectorY in world coordinates.*/
	DoubleID getWorldUpVectorY(){char buffer[4096];sprintf_s (buffer, "%s.wu.wuy",mName.c_str());return (const char*)buffer;}
	/*Input worldUpVectorZ in world coordinates.*/
	DoubleID getWorldUpVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.wu.wuz",mName.c_str());return (const char*)buffer;}
	/*Input worldMatrix for the up object.*/
	MatrixID getWorldUpMatrix(){char buffer[4096];sprintf_s (buffer, "%s.wum",mName.c_str());return (const char*)buffer;}
	/*Input control value for computation of world up vector.*/
	UnsignedintID getWorldUpType(){char buffer[4096];sprintf_s (buffer, "%s.wut",mName.c_str());return (const char*)buffer;}
	/*Input constrained object translate value.*/
	Double3ID getConstraintTranslate(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*Input constrained object translateX value.*/
	DoubleID getConstraintTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctx",mName.c_str());return (const char*)buffer;}
	/*Input constrained object translateY value.*/
	DoubleID getConstraintTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.ct.cty",mName.c_str());return (const char*)buffer;}
	/*Input constrained object translateZ value.*/
	DoubleID getConstraintTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctz",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotatelPivot value.*/
	Double3ID getConstraintRotatePivot(){char buffer[4096];sprintf_s (buffer, "%s.crp",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotatelPivotX value.*/
	DoubleID getConstraintRotatePivotX(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpx",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotatelPivotY value.*/
	DoubleID getConstraintRotatePivotY(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpy",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotatelPivotZ value.*/
	DoubleID getConstraintRotatePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpz",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotatePivotTranslate value.*/
	Double3ID getConstraintRotateTranslate(){char buffer[4096];sprintf_s (buffer, "%s.crt",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotatePivotTranslateX value.*/
	DoubleID getConstraintRotateTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.crt.crtx",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotatePivotTranslateY value.*/
	DoubleID getConstraintRotateTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.crt.crty",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotatePivotTranslateZ value.*/
	DoubleID getConstraintRotateTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.crt.crtz",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotate order value.*/
	UnsignedintID getConstraintRotateOrder(){char buffer[4096];sprintf_s (buffer, "%s.cro",mName.c_str());return (const char*)buffer;}
	/*Input constrained object joint orient (if any).*/
	Double3ID getConstraintJointOrient(){char buffer[4096];sprintf_s (buffer, "%s.cjo",mName.c_str());return (const char*)buffer;}
	/*Input constrained object joint orient X.*/
	DoubleID getConstraintJointOrientX(){char buffer[4096];sprintf_s (buffer, "%s.cjo.cjox",mName.c_str());return (const char*)buffer;}
	/*Input constrained object joint orient Y.*/
	DoubleID getConstraintJointOrientY(){char buffer[4096];sprintf_s (buffer, "%s.cjo.cjoy",mName.c_str());return (const char*)buffer;}
	/*Input constrained object joint orient Z.*/
	DoubleID getConstraintJointOrientZ(){char buffer[4096];sprintf_s (buffer, "%s.cjo.cjoz",mName.c_str());return (const char*)buffer;}
	/*Output constrained object rotate.*/
	Double3ID getConstraintRotate(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*Output constrained object rotateX.*/
	DoubleID getConstraintRotateX(){char buffer[4096];sprintf_s (buffer, "%s.cr.crx",mName.c_str());return (const char*)buffer;}
	/*Output constrained object rotateY.*/
	DoubleID getConstraintRotateY(){char buffer[4096];sprintf_s (buffer, "%s.cr.cry",mName.c_str());return (const char*)buffer;}
	/*Output constrained object rotateZ.*/
	DoubleID getConstraintRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.cr.crz",mName.c_str());return (const char*)buffer;}
	/*Output vector from constrained object to target position*/
	Double3ID getConstraintVector(){char buffer[4096];sprintf_s (buffer, "%s.cv",mName.c_str());return (const char*)buffer;}
	/*Output X vector from constrained object to target position*/
	DoubleID getConstraintVectorX(){char buffer[4096];sprintf_s (buffer, "%s.cv.cvx",mName.c_str());return (const char*)buffer;}
	/*Output Y vector from constrained object to target position*/
	DoubleID getConstraintVectorY(){char buffer[4096];sprintf_s (buffer, "%s.cv.cvy",mName.c_str());return (const char*)buffer;}
	/*Output Z vector from constrained object to target position*/
	DoubleID getConstraintVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.cv.cvz",mName.c_str());return (const char*)buffer;}
	/*object offset*/
	Double3ID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*object X offset*/
	DoubleID getOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*object Y offset*/
	DoubleID getOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*object Z offset*/
	DoubleID getOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
	/*rest orientation*/
	Double3ID getRestRotate(){char buffer[4096];sprintf_s (buffer, "%s.rsrr",mName.c_str());return (const char*)buffer;}
	/*rest X orientation*/
	DoubleID getRestRotateX(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rrx",mName.c_str());return (const char*)buffer;}
	/*rest Y orientation*/
	DoubleID getRestRotateY(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rry",mName.c_str());return (const char*)buffer;}
	/*rest Z orientation*/
	DoubleID getRestRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rrz",mName.c_str());return (const char*)buffer;}
	/*
	Turning this on switches the offset calculation from computing an
	offset  rotation matrix, to simply adding the individual offset
	values to the x, y, and z rotation value computed by the constraint.
	*/
	BoolID getUseOldOffsetCalculation(){char buffer[4096];sprintf_s (buffer, "%s.uooc",mName.c_str());return (const char*)buffer;}
protected:
	AimConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Constraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_AIMCONSTRAINT_H__
