/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POINTCONSTRAINT_H__
#define __MayaDM_POINTCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
/*
This node implements a pointConstraint.  Each constraint has a
        set of targets that are connected under the target attribute, a
        single constrained object that is connected to the constraint*
        attributes, and possibly other information to help compute the
        correct results.  In the case of the pointConstraint, the extra
        information is stored in offset and constraintOffsetPolarity
  attributes.

        <p/>The pointConstraint node can have any number of target inputs.
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
                                <th>pointConstraint attribute</th>
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

        <p/>The pointConstraint node uses these inputs to compute the world
        space position of the pivot point of each target object.  It then
        computes a weighted average of the these pivot points.  This
        weighted average is called the target point.

        <p/>The constrained object is connected to the constraint*
        attributes.  For a pointConstraint, the constraintRotatePivot,
        constraintRotateTranslate, and constraintParentInverseMatrix are
        inputs to the pointConstraint.  The attribute constraintTranslate
        is the only output.

  <p/>The pointConstraint node computes an output translation value
  such that the pivot point of the constrained object is offset by
  offset * constraintOffsetPolarity from the target point.

        <p/>Although the all the constraint nodes inherit from transform,
        they do not actively use any of the attributes from transform.
*/
class PointConstraint : public Constraint
{
public:
	/*bundle of matrix, input position, and weight*/
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
	PointConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "pointConstraint"){}
	virtual ~PointConstraint(){}
	/*bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const Target& tg){fprintf_s(mFile, "setAttr \".tg[%i]\" ",tg_i);tg.write(mFile);fprintf_s(mFile,";\n");}
	/*bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const TargetID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i]\";\n",mName.c_str(),tg_i);}
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
	/*input world position*/
	void setTargetParentMatrix(size_t tg_i,const matrix& tpm){if(tpm == identity) return; fprintf_s(mFile, "setAttr \".tg[%i].tpm\" -type \"matrix\" ",tg_i);tpm.write(mFile);fprintf_s(mFile,";\n");}
	/*input world position*/
	void setTargetParentMatrix(size_t tg_i,const MatrixID& tpm){fprintf_s(mFile,"connectAttr \"");tpm.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tpm\";\n",mName.c_str(),tg_i);}
	/*input weight for the position*/
	void setTargetWeight(size_t tg_i,double tw){if(tw == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].tw\" %f;\n", tg_i,tw);}
	/*input weight for the position*/
	void setTargetWeight(size_t tg_i,const DoubleID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tw\";\n",mName.c_str(),tg_i);}
	/*inverse of the parent matrix of the object*/
	void setConstraintParentInverseMatrix(const matrix& cpim){if(cpim == identity) return; fprintf_s(mFile, "setAttr \".cpim\" -type \"matrix\" ");cpim.write(mFile);fprintf_s(mFile,";\n");}
	/*inverse of the parent matrix of the object*/
	void setConstraintParentInverseMatrix(const MatrixID& cpim){fprintf_s(mFile,"connectAttr \"");cpim.write(mFile);fprintf_s(mFile,"\" \"%s.cpim\";\n",mName.c_str());}
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
	/*
	This is a scalar value by which the offset vector is multiplied, allowing
	you to animate or tweak the constrained object's offset from its targets
	by adjusting this single value. The overall offset is equal to
	constraintOffsetPolarity times the offset vector.
	*/
	void setConstraintOffsetPolarity(double cop){if(cop == 1) return; fprintf_s(mFile, "setAttr \".cop\" %f;\n", cop);}
	/*
	This is a scalar value by which the offset vector is multiplied, allowing
	you to animate or tweak the constrained object's offset from its targets
	by adjusting this single value. The overall offset is equal to
	constraintOffsetPolarity times the offset vector.
	*/
	void setConstraintOffsetPolarity(const DoubleID& cop){fprintf_s(mFile,"connectAttr \"");cop.write(mFile);fprintf_s(mFile,"\" \"%s.cop\";\n",mName.c_str());}
	/*output point position*/
	void setConstraintTranslate(const Double3ID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*output X point position*/
	void setConstraintTranslateX(const DoubleID& ctx){fprintf_s(mFile,"connectAttr \"");ctx.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctx\";\n",mName.c_str());}
	/*output Y point position*/
	void setConstraintTranslateY(const DoubleID& cty){fprintf_s(mFile,"connectAttr \"");cty.write(mFile);fprintf_s(mFile,"\" \"%s.ct.cty\";\n",mName.c_str());}
	/*output Z point position*/
	void setConstraintTranslateZ(const DoubleID& ctz){fprintf_s(mFile,"connectAttr \"");ctz.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctz\";\n",mName.c_str());}
	/*
	The rest translation defines the output of the constraint when all
	weights are zero. It is used when the enableRestPosition attribute is
	true.
	*/
	void setRestTranslate(const double3& rst){if(rst == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".rst\" -type \"double3\" ");rst.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The rest translation defines the output of the constraint when all
	weights are zero. It is used when the enableRestPosition attribute is
	true.
	*/
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
	/*bundle of matrix, input position, and weight*/
	const TargetID& getTarget(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i]",mName.c_str(),tg_i);return (const char*)buffer;}
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
	/*input world position*/
	const MatrixID& getTargetParentMatrix(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tpm",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input weight for the position*/
	const DoubleID& getTargetWeight(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tw",mName.c_str(),tg_i);return (const char*)buffer;}
	/*inverse of the parent matrix of the object*/
	MatrixID getConstraintParentInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cpim",mName.c_str());return (const char*)buffer;}
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
	/*object offset*/
	Double3ID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*object X offset*/
	DoubleID getOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*object Y offset*/
	DoubleID getOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*object Z offset*/
	DoubleID getOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
	/*
	This is a scalar value by which the offset vector is multiplied, allowing
	you to animate or tweak the constrained object's offset from its targets
	by adjusting this single value. The overall offset is equal to
	constraintOffsetPolarity times the offset vector.
	*/
	DoubleID getConstraintOffsetPolarity(){char buffer[4096];sprintf_s (buffer, "%s.cop",mName.c_str());return (const char*)buffer;}
	/*output point position*/
	Double3ID getConstraintTranslate(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*output X point position*/
	DoubleID getConstraintTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctx",mName.c_str());return (const char*)buffer;}
	/*output Y point position*/
	DoubleID getConstraintTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.ct.cty",mName.c_str());return (const char*)buffer;}
	/*output Z point position*/
	DoubleID getConstraintTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctz",mName.c_str());return (const char*)buffer;}
	/*
	The rest translation defines the output of the constraint when all
	weights are zero. It is used when the enableRestPosition attribute is
	true.
	*/
	Double3ID getRestTranslate(){char buffer[4096];sprintf_s (buffer, "%s.rst",mName.c_str());return (const char*)buffer;}
	/*rest x translation*/
	DoubleID getRestTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.rst.rtx",mName.c_str());return (const char*)buffer;}
	/*rest y translation*/
	DoubleID getRestTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.rst.rty",mName.c_str());return (const char*)buffer;}
	/*rest z translation*/
	DoubleID getRestTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.rst.rtz",mName.c_str());return (const char*)buffer;}
protected:
	PointConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Constraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POINTCONSTRAINT_H__
