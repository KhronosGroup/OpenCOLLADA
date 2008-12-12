/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ORIENTCONSTRAINT_H__
#define __MayaDM_ORIENTCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
/*
This node implements an orientConstraint.  Each constraint has a set
        of targets that are connected under the target attribute, a single
        constrained object that is connected to the constraint* attributes,
        and possibly other information to help compute the correct results.
        In the case of the orientConstraint, there is no other information.

        <p/>The orientConstraint node can have any number of target inputs.
        Each target is connected to attributes inside a single element
        of the target attribute.  For example, the first target object
        would be connected elements of target[0], the second target object
        would be connected to elements of target[1], etc.  The elements of
        each target are: targetRotate, targetRotateOrder,
        targetParentMatrix, and targetWeight.

        <p/>The elements of each target are normally connected to the target
        objects as follows:
        <blockquote>
                <table>
                        <tr>
                                <th>orientConstraint attribute</th>
                                <th>connected to</th>
                        </tr>
                        <tr>
                                <td>targetRotate</td>
                                <td>rotate</td>
                        </tr>
                        <tr>
                                <td>targetRotateOrder</td>
                                <td>rotateOrder</td>
                        </tr>
                        <tr>
                                <td>targetJointOrient</td>
                                <td>jointOrient <i>(joints only)</i></td>
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
        adjust the weighted average computation for the target orientation.

        <p/>The orientConstraint node uses these inputs to compute the
        world space orientation of each target object.  It then computes a
        weighted average of the these orientations in quaternion space.
        This weighted average is called the target orientation.

        <p/>The constrained object is connected to the constraint*
        attributes.  For an orientConstraint, the attributes
        constraintRotateOrder, constraintJointOrient, and
        constraintParentInverseMatrix are inputs to the orientConstraint.
        The attribute constraintRotate is the only output.

  <p/>The orientConstraint node computes an output rotation value
  such that the orientation of the constrained object matches
  the target orientation.

        <p/>Although the all the constraint nodes inherit from transform,
        they do not actively use any of the attributes from transform.
*/
class OrientConstraint : public Constraint
{
public:
	/*bundle of matrix, input position, and weight*/
	struct Target{
		double3 targetRotate;
		unsigned int targetRotateOrder;
		double3 targetJointOrient;
		matrix targetParentMatrix;
		double targetWeight;
		double3 targetRotateCached;
		void write(FILE* file) const
		{
			targetRotate.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i ", targetRotateOrder);
			targetJointOrient.write(file);
			fprintf_s(file, " ");
			targetParentMatrix.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f ", targetWeight);
			targetRotateCached.write(file);
		}
	};
public:
	OrientConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "orientConstraint"){}
	virtual ~OrientConstraint(){}
	/*bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const Target& tg){fprintf_s(mFile, "setAttr \".tg[%i]\" ",tg_i);tg.write(mFile);fprintf_s(mFile,";\n");}
	/*bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const TargetID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i]\";\n",mName.c_str(),tg_i);}
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
	/*Last computed orientation, helps interpolator avoid flips*/
	void setLastTargetRotate(const double3& lr){fprintf_s(mFile, "setAttr \".lr\" -type \"double3\" ");lr.write(mFile);fprintf_s(mFile,";\n");}
	/*Last computed orientation, helps interpolator avoid flips*/
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
	/*parent inverse matrix of the object*/
	void setConstraintParentInverseMatrix(const matrix& cpim){if(cpim == identity) return; fprintf_s(mFile, "setAttr \".cpim\" -type \"matrix\" ");cpim.write(mFile);fprintf_s(mFile,";\n");}
	/*parent inverse matrix of the object*/
	void setConstraintParentInverseMatrix(const MatrixID& cpim){fprintf_s(mFile,"connectAttr \"");cpim.write(mFile);fprintf_s(mFile,"\" \"%s.cpim\";\n",mName.c_str());}
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
	Interpolation type, used when weighting between more than one target.
	When there is only one target, no interpolation is used and this attribute
	is ignored.
	The meaning of the types of interpolation is as follows:
	<ul> <li> <b>No Flip</b> When constraining between multiple targets, this
	attribute prevents flipping. Since this attribute is dependent on the previous
	frame, it requires a runup to provide consistent results, or a cache can be created
	using the <em>Create Cache</em> button in the orient constraint attribute editor.</li>
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
	using the <em>Create Cache</em> button in the orient constraint attribute editor.</li>
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
	to "cache". The cache is not usually necessary, except when the orient constraint is
	controlled by multiple targets and "no flip" interpType is used to prevent flipping.
	The "no flip" calculation is dependent on the previous frame, so a cache
	is required to consistently provide identical results on a given frame.
	*/
	void setInterpCache(int inc){if(inc == 0) return; fprintf_s(mFile, "setAttr \".inc\" %i;\n", inc);}
	/*
	This attribute controls the interpolation type when the interpType attribute is set
	to "cache". The cache is not usually necessary, except when the orient constraint is
	controlled by multiple targets and "no flip" interpType is used to prevent flipping.
	The "no flip" calculation is dependent on the previous frame, so a cache
	is required to consistently provide identical results on a given frame.
	*/
	void setInterpCache(const IntID& inc){fprintf_s(mFile,"connectAttr \"");inc.write(mFile);fprintf_s(mFile,"\" \"%s.inc\";\n",mName.c_str());}
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
	/*bundle of matrix, input position, and weight*/
	const TargetID& getTarget(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i]",mName.c_str(),tg_i);return (const char*)buffer;}
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
	/*Last computed orientation, helps interpolator avoid flips*/
	Double3ID getLastTargetRotate(){char buffer[4096];sprintf_s (buffer, "%s.lr",mName.c_str());return (const char*)buffer;}
	/*X component of last computed orientation*/
	DoubleID getLastTargetRotateX(){char buffer[4096];sprintf_s (buffer, "%s.lr.lrx",mName.c_str());return (const char*)buffer;}
	/*Y component of last computed orientation*/
	DoubleID getLastTargetRotateY(){char buffer[4096];sprintf_s (buffer, "%s.lr.lry",mName.c_str());return (const char*)buffer;}
	/*Z component of last computed orientation*/
	DoubleID getLastTargetRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.lr.lrz",mName.c_str());return (const char*)buffer;}
	/*parent inverse matrix of the object*/
	MatrixID getConstraintParentInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cpim",mName.c_str());return (const char*)buffer;}
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
	Interpolation type, used when weighting between more than one target.
	When there is only one target, no interpolation is used and this attribute
	is ignored.
	The meaning of the types of interpolation is as follows:
	<ul> <li> <b>No Flip</b> When constraining between multiple targets, this
	attribute prevents flipping. Since this attribute is dependent on the previous
	frame, it requires a runup to provide consistent results, or a cache can be created
	using the <em>Create Cache</em> button in the orient constraint attribute editor.</li>
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
	to "cache". The cache is not usually necessary, except when the orient constraint is
	controlled by multiple targets and "no flip" interpType is used to prevent flipping.
	The "no flip" calculation is dependent on the previous frame, so a cache
	is required to consistently provide identical results on a given frame.
	*/
	IntID getInterpCache(){char buffer[4096];sprintf_s (buffer, "%s.inc",mName.c_str());return (const char*)buffer;}
	/*
	Turning this on switches the offset calculation from computing an
	offset  rotation matrix, to simply adding the individual offset
	values to the x, y, and z rotation value computed by the constraint.
	*/
	BoolID getUseOldOffsetCalculation(){char buffer[4096];sprintf_s (buffer, "%s.uooc",mName.c_str());return (const char*)buffer;}
protected:
	OrientConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Constraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ORIENTCONSTRAINT_H__
