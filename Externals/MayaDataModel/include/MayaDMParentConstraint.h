/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PARENTCONSTRAINT_H__
#define __MayaDM_PARENTCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
/*
This node implements a parentConstraint.  Each constraint has a
        set of targets that are connected under the target attribute and a
        single constrained object that is connected to the constraint*
        attributes.

        <p/>The parentConstraint node can have any number of target inputs.
        Each target is connected to attributes inside a single element
        of the target attribute.  For example, the first target object
        would be connected elements of target[0], the second target object
        would be connected to elements of target[1], etc.  The elements of
        each target are: targetTranslate, targetRotate, targetScale,
        targetRotatePivot, targetRotateTranslate, targetParentMatrix,
        targetRotateOrder, targetOffsetRotate, targetOffsetTranslate, and
  targetWeight.

        <p/>The elements of each target are normally connected to the target
        objects as follows:
        <blockquote>
                <table>
                        <tr>
                                <th>parentConstraint attribute</th>
                                <th>connected to</th>
                        </tr>
                        <tr>
                                <td>targetTranslate</td>
                                <td>translate</td>
                        </tr>
                        <tr>
                                <td>targetRotate</td>
                                <td>rotate</td>
                        </tr>
                        <tr>
                                <td>targetScale</td>
                                <td>scale</td>
                        </tr>
                        <tr>
                                <td>targetRotateOrder</td>
                                <td>rotateOrder</td>
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
                                <td>targetOffsetTranslate</td>
                                <td>set to constrained object's translational offset from target, in target's local space</td>
                        </tr>
                        <tr>
                                <td>targetOffsetRotate</td>
                                <td>set to constrained object's rotational offset from target, in target's local space amd rotation order</td>
                        </tr>
                        <tr>
                                <td>targetWeight</td>
                                <td><i>set to 1.0</i></td>
                        </tr>
                </table>
        </blockquote>

        <p/>The targetWeight attribute is not generally connected to the
        target object.  Instead, it may be animated by other means to
        adjust the weighted average computation for the target parent. Similarly,
  targetOffsetTranslate and targetOffsetRotate are generally not connected
  to the target object, but rather a calculated to determine an appropriate
  offset from that target in the target's local space.

        <p/>For each target, the parentConstraint node uses these inputs to
  first rotate the constrained object to match that of the target, then
  computes the world space position of the pivot point of the target.
  It then       computes a weighted average of the these transformations.

        <p/>The constrained object is connected to the constraint*
        attributes.  The constraintRotatePivot, constraintRotateTranslate,
  constraintRotateOrder and constraintParentInverseMatrix
  are inputs to the pointConstraint. These values are used to determine
  counter-translations and -rotations which are used to compensate for any
  transformation induced by the constrained object's parent, changes to its
  rotate pivot, and so forth.
        

  <p/> The attributes constraintTranslate and constraintRotate are the only
  outputs.

        <p/>Although the all the constraint nodes inherit from transform,
        they do not actively use any of the attributes from transform.
*/
class ParentConstraint : public Constraint
{
public:
	/*bundle of matrix, input position, and weight*/
	struct Target{
		matrix targetParentMatrix;
		double targetWeight;
		double3 targetRotateCached;
		double3 targetTranslate;
		double3 targetRotatePivot;
		double3 targetRotateTranslate;
		double3 targetOffsetTranslate;
		double3 targetRotate;
		unsigned int targetRotateOrder;
		double3 targetJointOrient;
		double3 targetOffsetRotate;
		double3 targetScale;
		void write(FILE* file) const
		{
			targetParentMatrix.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f ", targetWeight);
			targetRotateCached.write(file);
			fprintf_s(file, " ");
			targetTranslate.write(file);
			fprintf_s(file, " ");
			targetRotatePivot.write(file);
			fprintf_s(file, " ");
			targetRotateTranslate.write(file);
			fprintf_s(file, " ");
			targetOffsetTranslate.write(file);
			fprintf_s(file, " ");
			targetRotate.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i ", targetRotateOrder);
			targetJointOrient.write(file);
			fprintf_s(file, " ");
			targetOffsetRotate.write(file);
			fprintf_s(file, " ");
			targetScale.write(file);
		}
	};
public:
	ParentConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "parentConstraint"){}
	virtual ~ParentConstraint(){}
	/*bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const Target& tg){fprintf_s(mFile, "setAttr \".tg[%i]\" ",tg_i);tg.write(mFile);fprintf_s(mFile,";\n");}
	/*bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const TargetID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i]\";\n",mName.c_str(),tg_i);}
	/*input world position*/
	void setTargetParentMatrix(size_t tg_i,const matrix& tpm){if(tpm == identity) return; fprintf_s(mFile, "setAttr \".tg[%i].tpm\" -type \"matrix\" ",tg_i);tpm.write(mFile);fprintf_s(mFile,";\n");}
	/*input world position*/
	void setTargetParentMatrix(size_t tg_i,const MatrixID& tpm){fprintf_s(mFile,"connectAttr \"");tpm.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tpm\";\n",mName.c_str(),tg_i);}
	/*input weight for the position*/
	void setTargetWeight(size_t tg_i,double tw){if(tw == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].tw\" %f;\n", tg_i,tw);}
	/*input weight for the position*/
	void setTargetWeight(size_t tg_i,const DoubleID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tw\";\n",mName.c_str(),tg_i);}
	/*
	Cached orientation. This attribute is used internally by the constraint and should
	not be modified by the user.
	*/
	void setTargetRotateCached(size_t tg_i,const double3& ctr){fprintf_s(mFile, "setAttr \".tg[%i].ctr\" -type \"double3\" ",tg_i);ctr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Cached orientation. This attribute is used internally by the constraint and should
	not be modified by the user.
	*/
	void setTargetRotateCached(size_t tg_i,const Double3ID& ctr){fprintf_s(mFile,"connectAttr \"");ctr.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ctr\";\n",mName.c_str(),tg_i);}
	/*cached X orientation*/
	void setTargetRotateCachedX(size_t tg_i,double ctrx){if(ctrx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].ctr.ctrx\" %f;\n", tg_i,ctrx);}
	/*cached X orientation*/
	void setTargetRotateCachedX(size_t tg_i,const DoubleID& ctrx){fprintf_s(mFile,"connectAttr \"");ctrx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ctr.ctrx\";\n",mName.c_str(),tg_i);}
	/*cached Y orientation*/
	void setTargetRotateCachedY(size_t tg_i,double ctry){if(ctry == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].ctr.ctry\" %f;\n", tg_i,ctry);}
	/*cached Y orientation*/
	void setTargetRotateCachedY(size_t tg_i,const DoubleID& ctry){fprintf_s(mFile,"connectAttr \"");ctry.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ctr.ctry\";\n",mName.c_str(),tg_i);}
	/*cached Z orientation*/
	void setTargetRotateCachedZ(size_t tg_i,double ctrz){if(ctrz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].ctr.ctrz\" %f;\n", tg_i,ctrz);}
	/*cached Z orientation*/
	void setTargetRotateCachedZ(size_t tg_i,const DoubleID& ctrz){fprintf_s(mFile,"connectAttr \"");ctrz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ctr.ctrz\";\n",mName.c_str(),tg_i);}
	/*input translation*/
	void setTargetTranslate(size_t tg_i,const double3& tt){fprintf_s(mFile, "setAttr \".tg[%i].tt\" -type \"double3\" ",tg_i);tt.write(mFile);fprintf_s(mFile,";\n");}
	/*input translation*/
	void setTargetTranslate(size_t tg_i,const Double3ID& tt){fprintf_s(mFile,"connectAttr \"");tt.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tt\";\n",mName.c_str(),tg_i);}
	/*input X translation*/
	void setTargetTranslateX(size_t tg_i,double ttx){if(ttx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tt.ttx\" %f;\n", tg_i,ttx);}
	/*input X translation*/
	void setTargetTranslateX(size_t tg_i,const DoubleID& ttx){fprintf_s(mFile,"connectAttr \"");ttx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tt.ttx\";\n",mName.c_str(),tg_i);}
	/*input Y translation*/
	void setTargetTranslateY(size_t tg_i,double tty){if(tty == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tt.tty\" %f;\n", tg_i,tty);}
	/*input Y translation*/
	void setTargetTranslateY(size_t tg_i,const DoubleID& tty){fprintf_s(mFile,"connectAttr \"");tty.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tt.tty\";\n",mName.c_str(),tg_i);}
	/*input Z translation*/
	void setTargetTranslateZ(size_t tg_i,double ttz){if(ttz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tt.ttz\" %f;\n", tg_i,ttz);}
	/*input Z translation*/
	void setTargetTranslateZ(size_t tg_i,const DoubleID& ttz){fprintf_s(mFile,"connectAttr \"");ttz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tt.ttz\";\n",mName.c_str(),tg_i);}
	/*input rotate pivot*/
	void setTargetRotatePivot(size_t tg_i,const double3& trp){fprintf_s(mFile, "setAttr \".tg[%i].trp\" -type \"double3\" ",tg_i);trp.write(mFile);fprintf_s(mFile,";\n");}
	/*input rotate pivot*/
	void setTargetRotatePivot(size_t tg_i,const Double3ID& trp){fprintf_s(mFile,"connectAttr \"");trp.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trp\";\n",mName.c_str(),tg_i);}
	/*input X rotate pivot*/
	void setTargetRotatePivotX(size_t tg_i,double trpx){if(trpx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trp.trpx\" %f;\n", tg_i,trpx);}
	/*input X rotate pivot*/
	void setTargetRotatePivotX(size_t tg_i,const DoubleID& trpx){fprintf_s(mFile,"connectAttr \"");trpx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trp.trpx\";\n",mName.c_str(),tg_i);}
	/*input Y rotate pivot*/
	void setTargetRotatePivotY(size_t tg_i,double trpy){if(trpy == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trp.trpy\" %f;\n", tg_i,trpy);}
	/*input Y rotate pivot*/
	void setTargetRotatePivotY(size_t tg_i,const DoubleID& trpy){fprintf_s(mFile,"connectAttr \"");trpy.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trp.trpy\";\n",mName.c_str(),tg_i);}
	/*input Z rotate pivot*/
	void setTargetRotatePivotZ(size_t tg_i,double trpz){if(trpz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trp.trpz\" %f;\n", tg_i,trpz);}
	/*input Z rotate pivot*/
	void setTargetRotatePivotZ(size_t tg_i,const DoubleID& trpz){fprintf_s(mFile,"connectAttr \"");trpz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trp.trpz\";\n",mName.c_str(),tg_i);}
	/*input rotate pivot translate*/
	void setTargetRotateTranslate(size_t tg_i,const double3& trt){fprintf_s(mFile, "setAttr \".tg[%i].trt\" -type \"double3\" ",tg_i);trt.write(mFile);fprintf_s(mFile,";\n");}
	/*input rotate pivot translate*/
	void setTargetRotateTranslate(size_t tg_i,const Double3ID& trt){fprintf_s(mFile,"connectAttr \"");trt.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trt\";\n",mName.c_str(),tg_i);}
	/*input X rotate pivot translate*/
	void setTargetRotateTranslateX(size_t tg_i,double trtx){if(trtx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trt.trtx\" %f;\n", tg_i,trtx);}
	/*input X rotate pivot translate*/
	void setTargetRotateTranslateX(size_t tg_i,const DoubleID& trtx){fprintf_s(mFile,"connectAttr \"");trtx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trt.trtx\";\n",mName.c_str(),tg_i);}
	/*input Y rotate pivot translate*/
	void setTargetRotateTranslateY(size_t tg_i,double trty){if(trty == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trt.trty\" %f;\n", tg_i,trty);}
	/*input Y rotate pivot translate*/
	void setTargetRotateTranslateY(size_t tg_i,const DoubleID& trty){fprintf_s(mFile,"connectAttr \"");trty.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trt.trty\";\n",mName.c_str(),tg_i);}
	/*input Z rotate pivot translate*/
	void setTargetRotateTranslateZ(size_t tg_i,double trtz){if(trtz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].trt.trtz\" %f;\n", tg_i,trtz);}
	/*input Z rotate pivot translate*/
	void setTargetRotateTranslateZ(size_t tg_i,const DoubleID& trtz){fprintf_s(mFile,"connectAttr \"");trtz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].trt.trtz\";\n",mName.c_str(),tg_i);}
	/*Constrained object's translational offset from the target*/
	void setTargetOffsetTranslate(size_t tg_i,const double3& tot){fprintf_s(mFile, "setAttr \".tg[%i].tot\" -type \"double3\" ",tg_i);tot.write(mFile);fprintf_s(mFile,";\n");}
	/*Constrained object's translational offset from the target*/
	void setTargetOffsetTranslate(size_t tg_i,const Double3ID& tot){fprintf_s(mFile,"connectAttr \"");tot.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tot\";\n",mName.c_str(),tg_i);}
	/*Constrained object's x-translational offset from the target*/
	void setTargetOffsetTranslateX(size_t tg_i,double totx){if(totx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tot.totx\" %f;\n", tg_i,totx);}
	/*Constrained object's x-translational offset from the target*/
	void setTargetOffsetTranslateX(size_t tg_i,const DoubleID& totx){fprintf_s(mFile,"connectAttr \"");totx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tot.totx\";\n",mName.c_str(),tg_i);}
	/*Constrained object's y-translational offset from the target*/
	void setTargetOffsetTranslateY(size_t tg_i,double toty){if(toty == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tot.toty\" %f;\n", tg_i,toty);}
	/*Constrained object's y-translational offset from the target*/
	void setTargetOffsetTranslateY(size_t tg_i,const DoubleID& toty){fprintf_s(mFile,"connectAttr \"");toty.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tot.toty\";\n",mName.c_str(),tg_i);}
	/*Constrained object's z-translational offset from the target*/
	void setTargetOffsetTranslateZ(size_t tg_i,double totz){if(totz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tot.totz\" %f;\n", tg_i,totz);}
	/*Constrained object's z-translational offset from the target*/
	void setTargetOffsetTranslateZ(size_t tg_i,const DoubleID& totz){fprintf_s(mFile,"connectAttr \"");totz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tot.totz\";\n",mName.c_str(),tg_i);}
	/*input orientation*/
	void setTargetRotate(size_t tg_i,const double3& tr){fprintf_s(mFile, "setAttr \".tg[%i].tr\" -type \"double3\" ",tg_i);tr.write(mFile);fprintf_s(mFile,";\n");}
	/*input orientation*/
	void setTargetRotate(size_t tg_i,const Double3ID& tr){fprintf_s(mFile,"connectAttr \"");tr.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tr\";\n",mName.c_str(),tg_i);}
	/*input X orientation*/
	void setTargetRotateX(size_t tg_i,double trx){if(trx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tr.trx\" %f;\n", tg_i,trx);}
	/*input X orientation*/
	void setTargetRotateX(size_t tg_i,const DoubleID& trx){fprintf_s(mFile,"connectAttr \"");trx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tr.trx\";\n",mName.c_str(),tg_i);}
	/*input Y orientation*/
	void setTargetRotateY(size_t tg_i,double try_){if(try_ == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tr.try\" %f;\n", tg_i,try_);}
	/*input Y orientation*/
	void setTargetRotateY(size_t tg_i,const DoubleID& try_){fprintf_s(mFile,"connectAttr \"");try_.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tr.try\";\n",mName.c_str(),tg_i);}
	/*input Z orientation*/
	void setTargetRotateZ(size_t tg_i,double trz){if(trz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tr.trz\" %f;\n", tg_i,trz);}
	/*input Z orientation*/
	void setTargetRotateZ(size_t tg_i,const DoubleID& trz){fprintf_s(mFile,"connectAttr \"");trz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tr.trz\";\n",mName.c_str(),tg_i);}
	/*Input target object rotate order value.*/
	void setTargetRotateOrder(size_t tg_i,unsigned int tro){if(tro == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tro\" %i;\n", tg_i,tro);}
	/*Input target object rotate order value.*/
	void setTargetRotateOrder(size_t tg_i,const UnsignedintID& tro){fprintf_s(mFile,"connectAttr \"");tro.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tro\";\n",mName.c_str(),tg_i);}
	/*input joint orientation*/
	void setTargetJointOrient(size_t tg_i,const double3& tjo){fprintf_s(mFile, "setAttr \".tg[%i].tjo\" -type \"double3\" ",tg_i);tjo.write(mFile);fprintf_s(mFile,";\n");}
	/*input joint orientation*/
	void setTargetJointOrient(size_t tg_i,const Double3ID& tjo){fprintf_s(mFile,"connectAttr \"");tjo.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tjo\";\n",mName.c_str(),tg_i);}
	/*input X joint orientation*/
	void setTargetJointOrientX(size_t tg_i,double tjox){if(tjox == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tjo.tjox\" %f;\n", tg_i,tjox);}
	/*input X joint orientation*/
	void setTargetJointOrientX(size_t tg_i,const DoubleID& tjox){fprintf_s(mFile,"connectAttr \"");tjox.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tjo.tjox\";\n",mName.c_str(),tg_i);}
	/*input Y joint orientation*/
	void setTargetJointOrientY(size_t tg_i,double tjoy){if(tjoy == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tjo.tjoy\" %f;\n", tg_i,tjoy);}
	/*input Y joint orientation*/
	void setTargetJointOrientY(size_t tg_i,const DoubleID& tjoy){fprintf_s(mFile,"connectAttr \"");tjoy.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tjo.tjoy\";\n",mName.c_str(),tg_i);}
	/*input Z joint orientation*/
	void setTargetJointOrientZ(size_t tg_i,double tjoz){if(tjoz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tjo.tjoz\" %f;\n", tg_i,tjoz);}
	/*input Z joint orientation*/
	void setTargetJointOrientZ(size_t tg_i,const DoubleID& tjoz){fprintf_s(mFile,"connectAttr \"");tjoz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tjo.tjoz\";\n",mName.c_str(),tg_i);}
	/*Constrained object's rotational offset from the target*/
	void setTargetOffsetRotate(size_t tg_i,const double3& tor){fprintf_s(mFile, "setAttr \".tg[%i].tor\" -type \"double3\" ",tg_i);tor.write(mFile);fprintf_s(mFile,";\n");}
	/*Constrained object's rotational offset from the target*/
	void setTargetOffsetRotate(size_t tg_i,const Double3ID& tor){fprintf_s(mFile,"connectAttr \"");tor.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tor\";\n",mName.c_str(),tg_i);}
	/*Constrained object's x-rotational offset from the target*/
	void setTargetOffsetRotateX(size_t tg_i,double torx){if(torx == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tor.torx\" %f;\n", tg_i,torx);}
	/*Constrained object's x-rotational offset from the target*/
	void setTargetOffsetRotateX(size_t tg_i,const DoubleID& torx){fprintf_s(mFile,"connectAttr \"");torx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tor.torx\";\n",mName.c_str(),tg_i);}
	/*Constrained object's y-rotational offset from the target*/
	void setTargetOffsetRotateY(size_t tg_i,double tory){if(tory == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tor.tory\" %f;\n", tg_i,tory);}
	/*Constrained object's y-rotational offset from the target*/
	void setTargetOffsetRotateY(size_t tg_i,const DoubleID& tory){fprintf_s(mFile,"connectAttr \"");tory.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tor.tory\";\n",mName.c_str(),tg_i);}
	/*Constrained object's z-rotational offset from the target*/
	void setTargetOffsetRotateZ(size_t tg_i,double torz){if(torz == 0) return; fprintf_s(mFile, "setAttr \".tg[%i].tor.torz\" %f;\n", tg_i,torz);}
	/*Constrained object's z-rotational offset from the target*/
	void setTargetOffsetRotateZ(size_t tg_i,const DoubleID& torz){fprintf_s(mFile,"connectAttr \"");torz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tor.torz\";\n",mName.c_str(),tg_i);}
	/*Target's scaling. Used to properly determine constraintTranslate from the given target.*/
	void setTargetScale(size_t tg_i,const double3& ts){fprintf_s(mFile, "setAttr \".tg[%i].ts\" -type \"double3\" ",tg_i);ts.write(mFile);fprintf_s(mFile,";\n");}
	/*Target's scaling. Used to properly determine constraintTranslate from the given target.*/
	void setTargetScale(size_t tg_i,const Double3ID& ts){fprintf_s(mFile,"connectAttr \"");ts.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ts\";\n",mName.c_str(),tg_i);}
	/*Target's x scaling.*/
	void setTargetScaleX(size_t tg_i,double tsx){if(tsx == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].ts.tsx\" %f;\n", tg_i,tsx);}
	/*Target's x scaling.*/
	void setTargetScaleX(size_t tg_i,const DoubleID& tsx){fprintf_s(mFile,"connectAttr \"");tsx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ts.tsx\";\n",mName.c_str(),tg_i);}
	/*Target's y scaling.*/
	void setTargetScaleY(size_t tg_i,double tsy){if(tsy == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].ts.tsy\" %f;\n", tg_i,tsy);}
	/*Target's y scaling.*/
	void setTargetScaleY(size_t tg_i,const DoubleID& tsy){fprintf_s(mFile,"connectAttr \"");tsy.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ts.tsy\";\n",mName.c_str(),tg_i);}
	/*Target's z scaling.*/
	void setTargetScaleZ(size_t tg_i,double tsz){if(tsz == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].ts.tsz\" %f;\n", tg_i,tsz);}
	/*Target's z scaling.*/
	void setTargetScaleZ(size_t tg_i,const DoubleID& tsz){fprintf_s(mFile,"connectAttr \"");tsz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ts.tsz\";\n",mName.c_str(),tg_i);}
	/*inverse of the parent matrix of the object*/
	void setConstraintParentInverseMatrix(const matrix& cpim){if(cpim == identity) return; fprintf_s(mFile, "setAttr \".cpim\" -type \"matrix\" ");cpim.write(mFile);fprintf_s(mFile,";\n");}
	/*inverse of the parent matrix of the object*/
	void setConstraintParentInverseMatrix(const MatrixID& cpim){fprintf_s(mFile,"connectAttr \"");cpim.write(mFile);fprintf_s(mFile,"\" \"%s.cpim\";\n",mName.c_str());}
	/*Last computed orientation helps interpolator avoid flips*/
	void setLastTargetRotate(const double3& lr){fprintf_s(mFile, "setAttr \".lr\" -type \"double3\" ");lr.write(mFile);fprintf_s(mFile,";\n");}
	/*Last computed orientation helps interpolator avoid flips*/
	void setLastTargetRotate(const Double3ID& lr){fprintf_s(mFile,"connectAttr \"");lr.write(mFile);fprintf_s(mFile,"\" \"%s.lr\";\n",mName.c_str());}
	/*X component of last computed orientation*/
	void setLastTargetRotateX(double lrx){if(lrx == 0) return; fprintf_s(mFile, "setAttr \".lr.lrx\" %f;\n", lrx);}
	/*X component of last computed orientation*/
	void setLastTargetRotateX(const DoubleID& lrx){fprintf_s(mFile,"connectAttr \"");lrx.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lrx\";\n",mName.c_str());}
	/*Y component of last computed orientation*/
	void setLastTargetRotateY(double lry){if(lry == 0) return; fprintf_s(mFile, "setAttr \".lr.lry\" %f;\n", lry);}
	/*Y component of last computed orientation*/
	void setLastTargetRotateY(const DoubleID& lry){fprintf_s(mFile,"connectAttr \"");lry.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lry\";\n",mName.c_str());}
	/*Z component of last computed orientation*/
	void setLastTargetRotateZ(double lrz){if(lrz == 0) return; fprintf_s(mFile, "setAttr \".lr.lrz\" %f;\n", lrz);}
	/*Z component of last computed orientation*/
	void setLastTargetRotateZ(const DoubleID& lrz){fprintf_s(mFile,"connectAttr \"");lrz.write(mFile);fprintf_s(mFile,"\" \"%s.lr.lrz\";\n",mName.c_str());}
	/*object rotate pivot*/
	void setConstraintRotatePivot(const double3& crp){fprintf_s(mFile, "setAttr \".crp\" -type \"double3\" ");crp.write(mFile);fprintf_s(mFile,";\n");}
	/*object rotate pivot*/
	void setConstraintRotatePivot(const Double3ID& crp){fprintf_s(mFile,"connectAttr \"");crp.write(mFile);fprintf_s(mFile,"\" \"%s.crp\";\n",mName.c_str());}
	/*object X rotate pivot*/
	void setConstraintRotatePivotX(double crpx){if(crpx == 0) return; fprintf_s(mFile, "setAttr \".crp.crpx\" %f;\n", crpx);}
	/*object X rotate pivot*/
	void setConstraintRotatePivotX(const DoubleID& crpx){fprintf_s(mFile,"connectAttr \"");crpx.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpx\";\n",mName.c_str());}
	/*object Y rotate pivot*/
	void setConstraintRotatePivotY(double crpy){if(crpy == 0) return; fprintf_s(mFile, "setAttr \".crp.crpy\" %f;\n", crpy);}
	/*object Y rotate pivot*/
	void setConstraintRotatePivotY(const DoubleID& crpy){fprintf_s(mFile,"connectAttr \"");crpy.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpy\";\n",mName.c_str());}
	/*object Z rotate pivot*/
	void setConstraintRotatePivotZ(double crpz){if(crpz == 0) return; fprintf_s(mFile, "setAttr \".crp.crpz\" %f;\n", crpz);}
	/*object Z rotate pivot*/
	void setConstraintRotatePivotZ(const DoubleID& crpz){fprintf_s(mFile,"connectAttr \"");crpz.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpz\";\n",mName.c_str());}
	/*object rotate pivot translate*/
	void setConstraintRotateTranslate(const double3& crt){fprintf_s(mFile, "setAttr \".crt\" -type \"double3\" ");crt.write(mFile);fprintf_s(mFile,";\n");}
	/*object rotate pivot translate*/
	void setConstraintRotateTranslate(const Double3ID& crt){fprintf_s(mFile,"connectAttr \"");crt.write(mFile);fprintf_s(mFile,"\" \"%s.crt\";\n",mName.c_str());}
	/*object X rotate pivot translate*/
	void setConstraintRotateTranslateX(double crtx){if(crtx == 0) return; fprintf_s(mFile, "setAttr \".crt.crtx\" %f;\n", crtx);}
	/*object X rotate pivot translate*/
	void setConstraintRotateTranslateX(const DoubleID& crtx){fprintf_s(mFile,"connectAttr \"");crtx.write(mFile);fprintf_s(mFile,"\" \"%s.crt.crtx\";\n",mName.c_str());}
	/*object Y rotate pivot translate*/
	void setConstraintRotateTranslateY(double crty){if(crty == 0) return; fprintf_s(mFile, "setAttr \".crt.crty\" %f;\n", crty);}
	/*object Y rotate pivot translate*/
	void setConstraintRotateTranslateY(const DoubleID& crty){fprintf_s(mFile,"connectAttr \"");crty.write(mFile);fprintf_s(mFile,"\" \"%s.crt.crty\";\n",mName.c_str());}
	/*object Z rotate pivot translate*/
	void setConstraintRotateTranslateZ(double crtz){if(crtz == 0) return; fprintf_s(mFile, "setAttr \".crt.crtz\" %f;\n", crtz);}
	/*object Z rotate pivot translate*/
	void setConstraintRotateTranslateZ(const DoubleID& crtz){fprintf_s(mFile,"connectAttr \"");crtz.write(mFile);fprintf_s(mFile,"\" \"%s.crt.crtz\";\n",mName.c_str());}
	/*output point position*/
	void setConstraintTranslate(const Double3ID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*output X point position*/
	void setConstraintTranslateX(const DoubleID& ctx){fprintf_s(mFile,"connectAttr \"");ctx.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctx\";\n",mName.c_str());}
	/*output Y point position*/
	void setConstraintTranslateY(const DoubleID& cty){fprintf_s(mFile,"connectAttr \"");cty.write(mFile);fprintf_s(mFile,"\" \"%s.ct.cty\";\n",mName.c_str());}
	/*output Z point position*/
	void setConstraintTranslateZ(const DoubleID& ctz){fprintf_s(mFile,"connectAttr \"");ctz.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctz\";\n",mName.c_str());}
	/*rest translation*/
	void setRestTranslate(const double3& rst){if(rst == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".rst\" -type \"double3\" ");rst.write(mFile);fprintf_s(mFile,";\n");}
	/*rest translation*/
	void setRestTranslate(const Double3ID& rst){fprintf_s(mFile,"connectAttr \"");rst.write(mFile);fprintf_s(mFile,"\" \"%s.rst\";\n",mName.c_str());}
	/*rest x translation*/
	void setRestTranslateX(double rtx){if(rtx == 0) return; fprintf_s(mFile, "setAttr \".rst.rtx\" %f;\n", rtx);}
	/*rest x translation*/
	void setRestTranslateX(const DoubleID& rtx){fprintf_s(mFile,"connectAttr \"");rtx.write(mFile);fprintf_s(mFile,"\" \"%s.rst.rtx\";\n",mName.c_str());}
	/*rest y translation*/
	void setRestTranslateY(double rty){if(rty == 0) return; fprintf_s(mFile, "setAttr \".rst.rty\" %f;\n", rty);}
	/*rest y translation*/
	void setRestTranslateY(const DoubleID& rty){fprintf_s(mFile,"connectAttr \"");rty.write(mFile);fprintf_s(mFile,"\" \"%s.rst.rty\";\n",mName.c_str());}
	/*rest z translation*/
	void setRestTranslateZ(double rtz){if(rtz == 0) return; fprintf_s(mFile, "setAttr \".rst.rtz\" %f;\n", rtz);}
	/*rest z translation*/
	void setRestTranslateZ(const DoubleID& rtz){fprintf_s(mFile,"connectAttr \"");rtz.write(mFile);fprintf_s(mFile,"\" \"%s.rst.rtz\";\n",mName.c_str());}
	/*Input constrained object rotate order value.*/
	void setConstraintRotateOrder(unsigned int cro){if(cro == 0) return; fprintf_s(mFile, "setAttr \".cro\" %i;\n", cro);}
	/*Input constrained object rotate order value.*/
	void setConstraintRotateOrder(const UnsignedintID& cro){fprintf_s(mFile,"connectAttr \"");cro.write(mFile);fprintf_s(mFile,"\" \"%s.cro\";\n",mName.c_str());}
	/*Input constrained object joint orient value.*/
	void setConstraintJointOrient(const double3& cjo){fprintf_s(mFile, "setAttr \".cjo\" -type \"double3\" ");cjo.write(mFile);fprintf_s(mFile,";\n");}
	/*Input constrained object joint orient value.*/
	void setConstraintJointOrient(const Double3ID& cjo){fprintf_s(mFile,"connectAttr \"");cjo.write(mFile);fprintf_s(mFile,"\" \"%s.cjo\";\n",mName.c_str());}
	/*Input constrained object joint orient X value.*/
	void setConstraintJointOrientX(double cjox){if(cjox == 0) return; fprintf_s(mFile, "setAttr \".cjo.cjox\" %f;\n", cjox);}
	/*Input constrained object joint orient X value.*/
	void setConstraintJointOrientX(const DoubleID& cjox){fprintf_s(mFile,"connectAttr \"");cjox.write(mFile);fprintf_s(mFile,"\" \"%s.cjo.cjox\";\n",mName.c_str());}
	/*Input constrained object joint orient Y value.*/
	void setConstraintJointOrientY(double cjoy){if(cjoy == 0) return; fprintf_s(mFile, "setAttr \".cjo.cjoy\" %f;\n", cjoy);}
	/*Input constrained object joint orient Y value.*/
	void setConstraintJointOrientY(const DoubleID& cjoy){fprintf_s(mFile,"connectAttr \"");cjoy.write(mFile);fprintf_s(mFile,"\" \"%s.cjo.cjoy\";\n",mName.c_str());}
	/*Input constrained object joint orient Z value.*/
	void setConstraintJointOrientZ(double cjoz){if(cjoz == 0) return; fprintf_s(mFile, "setAttr \".cjo.cjoz\" %f;\n", cjoz);}
	/*Input constrained object joint orient Z value.*/
	void setConstraintJointOrientZ(const DoubleID& cjoz){fprintf_s(mFile,"connectAttr \"");cjoz.write(mFile);fprintf_s(mFile,"\" \"%s.cjo.cjoz\";\n",mName.c_str());}
	/*output orientation*/
	void setConstraintRotate(const Double3ID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*output X orientation*/
	void setConstraintRotateX(const DoubleID& crx){fprintf_s(mFile,"connectAttr \"");crx.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crx\";\n",mName.c_str());}
	/*output Y orientation*/
	void setConstraintRotateY(const DoubleID& cry){fprintf_s(mFile,"connectAttr \"");cry.write(mFile);fprintf_s(mFile,"\" \"%s.cr.cry\";\n",mName.c_str());}
	/*output Z orientation*/
	void setConstraintRotateZ(const DoubleID& crz){fprintf_s(mFile,"connectAttr \"");crz.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crz\";\n",mName.c_str());}
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
	Interpolation type, used when weighting between more than one target.
	When there is only one target, no interpolation is used and this attribute
	is ignored.
	The meaning of the types of interpolation is as follows:
	<ul> <li> <b>No Flip</b> When constraining between multiple targets, this
	attribute prevents flipping. Since this attribute is dependent on the previous
	frame, it requires a runup to provide consistent results, or a cache can be created
	using the <em>Create Cache</em> button in the parent constraint attribute editor.</li>
	<li> <b>Average</b> The quaternion average. This setting can cause flipping since
	the previous result is not taken into consideration. Use the "No Flip" setting in
	order to prevent flipping.</li>
	<li> <b>Shortest</b> Use the shortest path between the targets.</li>
	<li> <b>Longest</b> Use the longest path between the targets.</li>
	<li> <b>Cache</b> Use the cached result.</li>
	</ul>
	*/
	void setInterpType(unsigned int int_){if(int_ == 1) return; fprintf_s(mFile, "setAttr \".int\" %i;\n", int_);}
	/*
	Interpolation type, used when weighting between more than one target.
	When there is only one target, no interpolation is used and this attribute
	is ignored.
	The meaning of the types of interpolation is as follows:
	<ul> <li> <b>No Flip</b> When constraining between multiple targets, this
	attribute prevents flipping. Since this attribute is dependent on the previous
	frame, it requires a runup to provide consistent results, or a cache can be created
	using the <em>Create Cache</em> button in the parent constraint attribute editor.</li>
	<li> <b>Average</b> The quaternion average. This setting can cause flipping since
	the previous result is not taken into consideration. Use the "No Flip" setting in
	order to prevent flipping.</li>
	<li> <b>Shortest</b> Use the shortest path between the targets.</li>
	<li> <b>Longest</b> Use the longest path between the targets.</li>
	<li> <b>Cache</b> Use the cached result.</li>
	</ul>
	*/
	void setInterpType(const UnsignedintID& int_){fprintf_s(mFile,"connectAttr \"");int_.write(mFile);fprintf_s(mFile,"\" \"%s.int\";\n",mName.c_str());}
	/*
	This attribute controls the interpolation type when the interpType attribute is set
	to "cache". The cache is not usually necessary, except when the parent constraint is
	controlled by multiple targets and "no flip" interpType is used to prevent flipping.
	The "no flip" calculation is dependent on the previous frame, so a cache
	is required to consistently provide identical results on a given frame.
	*/
	void setInterpCache(int inc){if(inc == 0) return; fprintf_s(mFile, "setAttr \".inc\" %i;\n", inc);}
	/*
	This attribute controls the interpolation type when the interpType attribute is set
	to "cache". The cache is not usually necessary, except when the parent constraint is
	controlled by multiple targets and "no flip" interpType is used to prevent flipping.
	The "no flip" calculation is dependent on the previous frame, so a cache
	is required to consistently provide identical results on a given frame.
	*/
	void setInterpCache(const IntID& inc){fprintf_s(mFile,"connectAttr \"");inc.write(mFile);fprintf_s(mFile,"\" \"%s.inc\";\n",mName.c_str());}
	/*bundle of matrix, input position, and weight*/
	const TargetID& getTarget(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i]",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input world position*/
	const MatrixID& getTargetParentMatrix(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tpm",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input weight for the position*/
	const DoubleID& getTargetWeight(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tw",mName.c_str(),tg_i);return (const char*)buffer;}
	/*
	Cached orientation. This attribute is used internally by the constraint and should
	not be modified by the user.
	*/
	const Double3ID& getTargetRotateCached(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ctr",mName.c_str(),tg_i);return (const char*)buffer;}
	/*cached X orientation*/
	const DoubleID& getTargetRotateCachedX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ctr.ctrx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*cached Y orientation*/
	const DoubleID& getTargetRotateCachedY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ctr.ctry",mName.c_str(),tg_i);return (const char*)buffer;}
	/*cached Z orientation*/
	const DoubleID& getTargetRotateCachedZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ctr.ctrz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input translation*/
	const Double3ID& getTargetTranslate(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tt",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input X translation*/
	const DoubleID& getTargetTranslateX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tt.ttx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Y translation*/
	const DoubleID& getTargetTranslateY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tt.tty",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Z translation*/
	const DoubleID& getTargetTranslateZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tt.ttz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input rotate pivot*/
	const Double3ID& getTargetRotatePivot(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trp",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input X rotate pivot*/
	const DoubleID& getTargetRotatePivotX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trp.trpx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Y rotate pivot*/
	const DoubleID& getTargetRotatePivotY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trp.trpy",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Z rotate pivot*/
	const DoubleID& getTargetRotatePivotZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trp.trpz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input rotate pivot translate*/
	const Double3ID& getTargetRotateTranslate(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trt",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input X rotate pivot translate*/
	const DoubleID& getTargetRotateTranslateX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trt.trtx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Y rotate pivot translate*/
	const DoubleID& getTargetRotateTranslateY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trt.trty",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Z rotate pivot translate*/
	const DoubleID& getTargetRotateTranslateZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].trt.trtz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Constrained object's translational offset from the target*/
	const Double3ID& getTargetOffsetTranslate(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tot",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Constrained object's x-translational offset from the target*/
	const DoubleID& getTargetOffsetTranslateX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tot.totx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Constrained object's y-translational offset from the target*/
	const DoubleID& getTargetOffsetTranslateY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tot.toty",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Constrained object's z-translational offset from the target*/
	const DoubleID& getTargetOffsetTranslateZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tot.totz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input orientation*/
	const Double3ID& getTargetRotate(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tr",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input X orientation*/
	const DoubleID& getTargetRotateX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tr.trx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Y orientation*/
	const DoubleID& getTargetRotateY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tr.try",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Z orientation*/
	const DoubleID& getTargetRotateZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tr.trz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input target object rotate order value.*/
	const UnsignedintID& getTargetRotateOrder(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tro",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input joint orientation*/
	const Double3ID& getTargetJointOrient(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tjo",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input X joint orientation*/
	const DoubleID& getTargetJointOrientX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tjo.tjox",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Y joint orientation*/
	const DoubleID& getTargetJointOrientY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tjo.tjoy",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Z joint orientation*/
	const DoubleID& getTargetJointOrientZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tjo.tjoz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Constrained object's rotational offset from the target*/
	const Double3ID& getTargetOffsetRotate(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tor",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Constrained object's x-rotational offset from the target*/
	const DoubleID& getTargetOffsetRotateX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tor.torx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Constrained object's y-rotational offset from the target*/
	const DoubleID& getTargetOffsetRotateY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tor.tory",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Constrained object's z-rotational offset from the target*/
	const DoubleID& getTargetOffsetRotateZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tor.torz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Target's scaling. Used to properly determine constraintTranslate from the given target.*/
	const Double3ID& getTargetScale(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ts",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Target's x scaling.*/
	const DoubleID& getTargetScaleX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ts.tsx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Target's y scaling.*/
	const DoubleID& getTargetScaleY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ts.tsy",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Target's z scaling.*/
	const DoubleID& getTargetScaleZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ts.tsz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*inverse of the parent matrix of the object*/
	MatrixID getConstraintParentInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cpim",mName.c_str());return (const char*)buffer;}
	/*Last computed orientation helps interpolator avoid flips*/
	Double3ID getLastTargetRotate(){char buffer[4096];sprintf_s (buffer, "%s.lr",mName.c_str());return (const char*)buffer;}
	/*X component of last computed orientation*/
	DoubleID getLastTargetRotateX(){char buffer[4096];sprintf_s (buffer, "%s.lr.lrx",mName.c_str());return (const char*)buffer;}
	/*Y component of last computed orientation*/
	DoubleID getLastTargetRotateY(){char buffer[4096];sprintf_s (buffer, "%s.lr.lry",mName.c_str());return (const char*)buffer;}
	/*Z component of last computed orientation*/
	DoubleID getLastTargetRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.lr.lrz",mName.c_str());return (const char*)buffer;}
	/*object rotate pivot*/
	Double3ID getConstraintRotatePivot(){char buffer[4096];sprintf_s (buffer, "%s.crp",mName.c_str());return (const char*)buffer;}
	/*object X rotate pivot*/
	DoubleID getConstraintRotatePivotX(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpx",mName.c_str());return (const char*)buffer;}
	/*object Y rotate pivot*/
	DoubleID getConstraintRotatePivotY(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpy",mName.c_str());return (const char*)buffer;}
	/*object Z rotate pivot*/
	DoubleID getConstraintRotatePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpz",mName.c_str());return (const char*)buffer;}
	/*object rotate pivot translate*/
	Double3ID getConstraintRotateTranslate(){char buffer[4096];sprintf_s (buffer, "%s.crt",mName.c_str());return (const char*)buffer;}
	/*object X rotate pivot translate*/
	DoubleID getConstraintRotateTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.crt.crtx",mName.c_str());return (const char*)buffer;}
	/*object Y rotate pivot translate*/
	DoubleID getConstraintRotateTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.crt.crty",mName.c_str());return (const char*)buffer;}
	/*object Z rotate pivot translate*/
	DoubleID getConstraintRotateTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.crt.crtz",mName.c_str());return (const char*)buffer;}
	/*output point position*/
	Double3ID getConstraintTranslate(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*output X point position*/
	DoubleID getConstraintTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctx",mName.c_str());return (const char*)buffer;}
	/*output Y point position*/
	DoubleID getConstraintTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.ct.cty",mName.c_str());return (const char*)buffer;}
	/*output Z point position*/
	DoubleID getConstraintTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctz",mName.c_str());return (const char*)buffer;}
	/*rest translation*/
	Double3ID getRestTranslate(){char buffer[4096];sprintf_s (buffer, "%s.rst",mName.c_str());return (const char*)buffer;}
	/*rest x translation*/
	DoubleID getRestTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.rst.rtx",mName.c_str());return (const char*)buffer;}
	/*rest y translation*/
	DoubleID getRestTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.rst.rty",mName.c_str());return (const char*)buffer;}
	/*rest z translation*/
	DoubleID getRestTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.rst.rtz",mName.c_str());return (const char*)buffer;}
	/*Input constrained object rotate order value.*/
	UnsignedintID getConstraintRotateOrder(){char buffer[4096];sprintf_s (buffer, "%s.cro",mName.c_str());return (const char*)buffer;}
	/*Input constrained object joint orient value.*/
	Double3ID getConstraintJointOrient(){char buffer[4096];sprintf_s (buffer, "%s.cjo",mName.c_str());return (const char*)buffer;}
	/*Input constrained object joint orient X value.*/
	DoubleID getConstraintJointOrientX(){char buffer[4096];sprintf_s (buffer, "%s.cjo.cjox",mName.c_str());return (const char*)buffer;}
	/*Input constrained object joint orient Y value.*/
	DoubleID getConstraintJointOrientY(){char buffer[4096];sprintf_s (buffer, "%s.cjo.cjoy",mName.c_str());return (const char*)buffer;}
	/*Input constrained object joint orient Z value.*/
	DoubleID getConstraintJointOrientZ(){char buffer[4096];sprintf_s (buffer, "%s.cjo.cjoz",mName.c_str());return (const char*)buffer;}
	/*output orientation*/
	Double3ID getConstraintRotate(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*output X orientation*/
	DoubleID getConstraintRotateX(){char buffer[4096];sprintf_s (buffer, "%s.cr.crx",mName.c_str());return (const char*)buffer;}
	/*output Y orientation*/
	DoubleID getConstraintRotateY(){char buffer[4096];sprintf_s (buffer, "%s.cr.cry",mName.c_str());return (const char*)buffer;}
	/*output Z orientation*/
	DoubleID getConstraintRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.cr.crz",mName.c_str());return (const char*)buffer;}
	/*rest orientation*/
	Double3ID getRestRotate(){char buffer[4096];sprintf_s (buffer, "%s.rsrr",mName.c_str());return (const char*)buffer;}
	/*rest X orientation*/
	DoubleID getRestRotateX(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rrx",mName.c_str());return (const char*)buffer;}
	/*rest Y orientation*/
	DoubleID getRestRotateY(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rry",mName.c_str());return (const char*)buffer;}
	/*rest Z orientation*/
	DoubleID getRestRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rrz",mName.c_str());return (const char*)buffer;}
	/*
	Interpolation type, used when weighting between more than one target.
	When there is only one target, no interpolation is used and this attribute
	is ignored.
	The meaning of the types of interpolation is as follows:
	<ul> <li> <b>No Flip</b> When constraining between multiple targets, this
	attribute prevents flipping. Since this attribute is dependent on the previous
	frame, it requires a runup to provide consistent results, or a cache can be created
	using the <em>Create Cache</em> button in the parent constraint attribute editor.</li>
	<li> <b>Average</b> The quaternion average. This setting can cause flipping since
	the previous result is not taken into consideration. Use the "No Flip" setting in
	order to prevent flipping.</li>
	<li> <b>Shortest</b> Use the shortest path between the targets.</li>
	<li> <b>Longest</b> Use the longest path between the targets.</li>
	<li> <b>Cache</b> Use the cached result.</li>
	</ul>
	*/
	UnsignedintID getInterpType(){char buffer[4096];sprintf_s (buffer, "%s.int",mName.c_str());return (const char*)buffer;}
	/*
	This attribute controls the interpolation type when the interpType attribute is set
	to "cache". The cache is not usually necessary, except when the parent constraint is
	controlled by multiple targets and "no flip" interpType is used to prevent flipping.
	The "no flip" calculation is dependent on the previous frame, so a cache
	is required to consistently provide identical results on a given frame.
	*/
	IntID getInterpCache(){char buffer[4096];sprintf_s (buffer, "%s.inc",mName.c_str());return (const char*)buffer;}
protected:
	ParentConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Constraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PARENTCONSTRAINT_H__
