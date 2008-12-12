/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NORMALCONSTRAINT_H__
#define __MayaDM_NORMALCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
/*
This node implements a normalConstraint.  Each constraint has a set
        of targets that are connected under the target attribute, a single
        constrained object that is connected to the constraint* attributes,
        and possibly other information to help compute the correct results.
        In the case of the normalConstraint, the additional information is:
        aimVector, upVector, worldUpVector, worldUpMatrix, and
        worldUpType.

        <p/>The normalConstraint node can have any number of target inputs.
        Each target is connected to attributes inside a single element
        of the target attribute.  For example, the first target object
        would be connected elements of target[0], the second target object
        would be connected to elements of target[1], etc.  The elements of
        each target are: targetGeometry and targetWeight.

        <p/>The elements of each target are normally connected to the target
        objects as follows:
        <blockquote>
                <table>
                        <tr>
                                <th>normalConstraint attribute</th>
                                <th>connected to</th>
                        </tr>
                        <tr>
                                <td>targetGeometry</td>
                                <td>worldSpace</td>
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

        <p/>The constrained object is connected to the constraint*
        attributes.  For a normalConstraint, the constraintTranslate,
        constraintRotatePivot, constraintRotateTranslate, and
        constraintParentInverseMatrix are inputs to the normalConstraint.
        The attribute constraintRotate is the only output..

        <p/>The normalConstraint node uses the constraintTranslate,
        constraintRotatePivot, constraintRotateTranslate,
        constraintJointOrient, and constraintParentInverseMatrix
        attributes to compute the world space position of the pivot point
        of the constrained object.  Then, for each target geometry, the
        closest point is found and the normal at that point is computed.
        Each normal is then added into a weighted average vector and the
        constrained object is oriented so that the aimVector (see below)
        matches the weighted average vector.

        <p/>The additional normalConstraint inputs tell the constraint node how to
        aim the constrained object.  The aimVector attribute defines a vector
        in the space of the constrained object that should be aligned with
        the weighted average vector computed by the constraint.
        The upVector, worldUpVector, worldUpMatrix, and worldUpType
        define how the constrained object is rotated about the aimVector.

        <p/>The upVector defines a vector in the space of the constrained
        object, very much like the aimVector does.  The constrained object is
        rotated so that the aimVector matches the weighted average vector and so that
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
                  and surface normals are used. Specifying an up vector can cause flipping
                                        to occur when the constrained object's new orientation vector is
                                        close to the up vector. If the worldUpType is instead set to none,
                                        this flipping won't happen, at a loss of control over twisting.
                                </td>
                        </tr>
                </table>
        </blockquote>

        <p/>While setAttr requires the numeric values for the worldUpType
        attribute, both numeric and mnemonic values are allowed by the
        normalConstraint command.

        <p/>Although the all the constraint nodes inherit from transform,
        they do not actively use any of the attributes from transform.
*/
class NormalConstraint : public Constraint
{
public:
	/*Bundle of matrix, input position, and weight*/
	struct Target{
		double targetWeight;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f", targetWeight);
		}
	};
public:
	NormalConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "normalConstraint"){}
	virtual ~NormalConstraint(){}
	/*Bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const Target& tg){fprintf_s(mFile, "setAttr \".tg[%i]\" ",tg_i);tg.write(mFile);fprintf_s(mFile,";\n");}
	/*Bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const TargetID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i]\";\n",mName.c_str(),tg_i);}
	/*input geometry to which the object should be constrained*/
	void setTargetGeometry(size_t tg_i,const GenericID& tgm){fprintf_s(mFile,"connectAttr \"");tgm.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tgm\";\n",mName.c_str(),tg_i);}
	/*Input weight for the position*/
	void setTargetWeight(size_t tg_i,double tw){if(tw == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].tw\" %f;\n", tg_i,tw);}
	/*Input weight for the position*/
	void setTargetWeight(size_t tg_i,const DoubleID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tw\";\n",mName.c_str(),tg_i);}
	/*Input parent inverse matrix for the object*/
	void setConstraintParentInverseMatrix(const matrix& cpim){if(cpim == identity) return; fprintf_s(mFile, "setAttr \".cpim\" -type \"matrix\" ");cpim.write(mFile);fprintf_s(mFile,";\n");}
	/*Input parent inverse matrix for the object*/
	void setConstraintParentInverseMatrix(const MatrixID& cpim){fprintf_s(mFile,"connectAttr \"");cpim.write(mFile);fprintf_s(mFile,"\" \"%s.cpim\";\n",mName.c_str());}
	/*Input aim vector (in local coordinates)*/
	void setAimVector(const double3& a){fprintf_s(mFile, "setAttr \".a\" -type \"double3\" ");a.write(mFile);fprintf_s(mFile,";\n");}
	/*Input aim vector (in local coordinates)*/
	void setAimVector(const Double3ID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.a\";\n",mName.c_str());}
	/*Aim vector X component*/
	void setAimVectorX(double ax){if(ax == 1.0) return; fprintf_s(mFile, "setAttr \".a.ax\" %f;\n", ax);}
	/*Aim vector X component*/
	void setAimVectorX(const DoubleID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.a.ax\";\n",mName.c_str());}
	/*Aim vector Y component*/
	void setAimVectorY(double ay){if(ay == 0.0) return; fprintf_s(mFile, "setAttr \".a.ay\" %f;\n", ay);}
	/*Aim vector Y component*/
	void setAimVectorY(const DoubleID& ay){fprintf_s(mFile,"connectAttr \"");ay.write(mFile);fprintf_s(mFile,"\" \"%s.a.ay\";\n",mName.c_str());}
	/*Aim vector Z component*/
	void setAimVectorZ(double az){if(az == 0.0) return; fprintf_s(mFile, "setAttr \".a.az\" %f;\n", az);}
	/*Aim vector Z component*/
	void setAimVectorZ(const DoubleID& az){fprintf_s(mFile,"connectAttr \"");az.write(mFile);fprintf_s(mFile,"\" \"%s.a.az\";\n",mName.c_str());}
	/*Input up vector (in local coordinates)*/
	void setUpVector(const double3& u){fprintf_s(mFile, "setAttr \".u\" -type \"double3\" ");u.write(mFile);fprintf_s(mFile,";\n");}
	/*Input up vector (in local coordinates)*/
	void setUpVector(const Double3ID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.u\";\n",mName.c_str());}
	/*Up vector X component*/
	void setUpVectorX(double ux){if(ux == 0.0) return; fprintf_s(mFile, "setAttr \".u.ux\" %f;\n", ux);}
	/*Up vector X component*/
	void setUpVectorX(const DoubleID& ux){fprintf_s(mFile,"connectAttr \"");ux.write(mFile);fprintf_s(mFile,"\" \"%s.u.ux\";\n",mName.c_str());}
	/*Up vector Y component*/
	void setUpVectorY(double uy){if(uy == 1.0) return; fprintf_s(mFile, "setAttr \".u.uy\" %f;\n", uy);}
	/*Up vector Y component*/
	void setUpVectorY(const DoubleID& uy){fprintf_s(mFile,"connectAttr \"");uy.write(mFile);fprintf_s(mFile,"\" \"%s.u.uy\";\n",mName.c_str());}
	/*up vector Z component*/
	void setUpVectorZ(double uz){if(uz == 0.0) return; fprintf_s(mFile, "setAttr \".u.uz\" %f;\n", uz);}
	/*up vector Z component*/
	void setUpVectorZ(const DoubleID& uz){fprintf_s(mFile,"connectAttr \"");uz.write(mFile);fprintf_s(mFile,"\" \"%s.u.uz\";\n",mName.c_str());}
	/*Input world up vector (in local coordinates)*/
	void setWorldUpVector(const double3& wu){fprintf_s(mFile, "setAttr \".wu\" -type \"double3\" ");wu.write(mFile);fprintf_s(mFile,";\n");}
	/*Input world up vector (in local coordinates)*/
	void setWorldUpVector(const Double3ID& wu){fprintf_s(mFile,"connectAttr \"");wu.write(mFile);fprintf_s(mFile,"\" \"%s.wu\";\n",mName.c_str());}
	/*World up vector X component*/
	void setWorldUpVectorX(double wux){if(wux == 0.0) return; fprintf_s(mFile, "setAttr \".wu.wux\" %f;\n", wux);}
	/*World up vector X component*/
	void setWorldUpVectorX(const DoubleID& wux){fprintf_s(mFile,"connectAttr \"");wux.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wux\";\n",mName.c_str());}
	/*World up vector Y component*/
	void setWorldUpVectorY(double wuy){if(wuy == 1.0) return; fprintf_s(mFile, "setAttr \".wu.wuy\" %f;\n", wuy);}
	/*World up vector Y component*/
	void setWorldUpVectorY(const DoubleID& wuy){fprintf_s(mFile,"connectAttr \"");wuy.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wuy\";\n",mName.c_str());}
	/*World up vector Z component*/
	void setWorldUpVectorZ(double wuz){if(wuz == 0.0) return; fprintf_s(mFile, "setAttr \".wu.wuz\" %f;\n", wuz);}
	/*World up vector Z component*/
	void setWorldUpVectorZ(const DoubleID& wuz){fprintf_s(mFile,"connectAttr \"");wuz.write(mFile);fprintf_s(mFile,"\" \"%s.wu.wuz\";\n",mName.c_str());}
	/*Input world matrix for the up object*/
	void setWorldUpMatrix(const matrix& wum){if(wum == identity) return; fprintf_s(mFile, "setAttr \".wum\" -type \"matrix\" ");wum.write(mFile);fprintf_s(mFile,";\n");}
	/*Input world matrix for the up object*/
	void setWorldUpMatrix(const MatrixID& wum){fprintf_s(mFile,"connectAttr \"");wum.write(mFile);fprintf_s(mFile,"\" \"%s.wum\";\n",mName.c_str());}
	/*Input behavior to resolve world up vector.*/
	void setWorldUpType(unsigned int wut){if(wut == 3) return; fprintf_s(mFile, "setAttr \".wut\" %i;\n", wut);}
	/*Input behavior to resolve world up vector.*/
	void setWorldUpType(const UnsignedintID& wut){fprintf_s(mFile,"connectAttr \"");wut.write(mFile);fprintf_s(mFile,"\" \"%s.wut\";\n",mName.c_str());}
	/*Object translation (in local coordinates)*/
	void setConstraintTranslate(const double3& ct){fprintf_s(mFile, "setAttr \".ct\" -type \"double3\" ");ct.write(mFile);fprintf_s(mFile,";\n");}
	/*Object translation (in local coordinates)*/
	void setConstraintTranslate(const Double3ID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*Object X translation*/
	void setConstraintTranslateX(double ctx){if(ctx == 0) return; fprintf_s(mFile, "setAttr \".ct.ctx\" %f;\n", ctx);}
	/*Object X translation*/
	void setConstraintTranslateX(const DoubleID& ctx){fprintf_s(mFile,"connectAttr \"");ctx.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctx\";\n",mName.c_str());}
	/*Object Y translation*/
	void setConstraintTranslateY(double cty){if(cty == 0) return; fprintf_s(mFile, "setAttr \".ct.cty\" %f;\n", cty);}
	/*Object Y translation*/
	void setConstraintTranslateY(const DoubleID& cty){fprintf_s(mFile,"connectAttr \"");cty.write(mFile);fprintf_s(mFile,"\" \"%s.ct.cty\";\n",mName.c_str());}
	/*Object Z translation*/
	void setConstraintTranslateZ(double ctz){if(ctz == 0) return; fprintf_s(mFile, "setAttr \".ct.ctz\" %f;\n", ctz);}
	/*Object Z translation*/
	void setConstraintTranslateZ(const DoubleID& ctz){fprintf_s(mFile,"connectAttr \"");ctz.write(mFile);fprintf_s(mFile,"\" \"%s.ct.ctz\";\n",mName.c_str());}
	/*Object rotate pivot (in local coordinates)*/
	void setConstraintRotatePivot(const double3& crp){fprintf_s(mFile, "setAttr \".crp\" -type \"double3\" ");crp.write(mFile);fprintf_s(mFile,";\n");}
	/*Object rotate pivot (in local coordinates)*/
	void setConstraintRotatePivot(const Double3ID& crp){fprintf_s(mFile,"connectAttr \"");crp.write(mFile);fprintf_s(mFile,"\" \"%s.crp\";\n",mName.c_str());}
	/*Object X rotate pivot*/
	void setConstraintRotatePivotX(double crpx){if(crpx == 0) return; fprintf_s(mFile, "setAttr \".crp.crpx\" %f;\n", crpx);}
	/*Object X rotate pivot*/
	void setConstraintRotatePivotX(const DoubleID& crpx){fprintf_s(mFile,"connectAttr \"");crpx.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpx\";\n",mName.c_str());}
	/*Object Y rotate pivot*/
	void setConstraintRotatePivotY(double crpy){if(crpy == 0) return; fprintf_s(mFile, "setAttr \".crp.crpy\" %f;\n", crpy);}
	/*Object Y rotate pivot*/
	void setConstraintRotatePivotY(const DoubleID& crpy){fprintf_s(mFile,"connectAttr \"");crpy.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpy\";\n",mName.c_str());}
	/*Object Z rotate pivot*/
	void setConstraintRotatePivotZ(double crpz){if(crpz == 0) return; fprintf_s(mFile, "setAttr \".crp.crpz\" %f;\n", crpz);}
	/*Object Z rotate pivot*/
	void setConstraintRotatePivotZ(const DoubleID& crpz){fprintf_s(mFile,"connectAttr \"");crpz.write(mFile);fprintf_s(mFile,"\" \"%s.crp.crpz\";\n",mName.c_str());}
	/*Object rotate translate (in local coordinates)*/
	void setConstraintRotateTranslate(const double3& crt){fprintf_s(mFile, "setAttr \".crt\" -type \"double3\" ");crt.write(mFile);fprintf_s(mFile,";\n");}
	/*Object rotate translate (in local coordinates)*/
	void setConstraintRotateTranslate(const Double3ID& crt){fprintf_s(mFile,"connectAttr \"");crt.write(mFile);fprintf_s(mFile,"\" \"%s.crt\";\n",mName.c_str());}
	/*Object X rotate translate*/
	void setConstraintRotateTranslateX(double crtx){if(crtx == 0) return; fprintf_s(mFile, "setAttr \".crt.crtx\" %f;\n", crtx);}
	/*Object X rotate translate*/
	void setConstraintRotateTranslateX(const DoubleID& crtx){fprintf_s(mFile,"connectAttr \"");crtx.write(mFile);fprintf_s(mFile,"\" \"%s.crt.crtx\";\n",mName.c_str());}
	/*Object Y rotate translate*/
	void setConstraintRotateTranslateY(double crty){if(crty == 0) return; fprintf_s(mFile, "setAttr \".crt.crty\" %f;\n", crty);}
	/*Object Y rotate translate*/
	void setConstraintRotateTranslateY(const DoubleID& crty){fprintf_s(mFile,"connectAttr \"");crty.write(mFile);fprintf_s(mFile,"\" \"%s.crt.crty\";\n",mName.c_str());}
	/*Object Z rotate translate*/
	void setConstraintRotateTranslateZ(double crtz){if(crtz == 0) return; fprintf_s(mFile, "setAttr \".crt.crtz\" %f;\n", crtz);}
	/*Object Z rotate translate*/
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
	/*Output orientation*/
	void setConstraintRotate(const Double3ID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr\";\n",mName.c_str());}
	/*Output X orientation*/
	void setConstraintRotateX(const DoubleID& crx){fprintf_s(mFile,"connectAttr \"");crx.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crx\";\n",mName.c_str());}
	/*Output Y orientation*/
	void setConstraintRotateY(const DoubleID& cry){fprintf_s(mFile,"connectAttr \"");cry.write(mFile);fprintf_s(mFile,"\" \"%s.cr.cry\";\n",mName.c_str());}
	/*Output Z orientation*/
	void setConstraintRotateZ(const DoubleID& crz){fprintf_s(mFile,"connectAttr \"");crz.write(mFile);fprintf_s(mFile,"\" \"%s.cr.crz\";\n",mName.c_str());}
	/*Output vector from constrained object to target position*/
	void setConstraintVector(const Double3ID& cv){fprintf_s(mFile,"connectAttr \"");cv.write(mFile);fprintf_s(mFile,"\" \"%s.cv\";\n",mName.c_str());}
	/*Output X vector from constrained object to target position*/
	void setConstraintVectorX(const DoubleID& cvx){fprintf_s(mFile,"connectAttr \"");cvx.write(mFile);fprintf_s(mFile,"\" \"%s.cv.cvx\";\n",mName.c_str());}
	/*Output Y vector from constrained object to target position*/
	void setConstraintVectorY(const DoubleID& cvy){fprintf_s(mFile,"connectAttr \"");cvy.write(mFile);fprintf_s(mFile,"\" \"%s.cv.cvy\";\n",mName.c_str());}
	/*Output Z vector from constrained object to target position*/
	void setConstraintVectorZ(const DoubleID& cvz){fprintf_s(mFile,"connectAttr \"");cvz.write(mFile);fprintf_s(mFile,"\" \"%s.cv.cvz\";\n",mName.c_str());}
	/*
	Rest orientation. When enableRestPosition is enabled, and all the weights
	sum to zero, this is the output orientation of the constraint.
	*/
	void setRestRotate(const double3& rsrr){fprintf_s(mFile, "setAttr \".rsrr\" -type \"double3\" ");rsrr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Rest orientation. When enableRestPosition is enabled, and all the weights
	sum to zero, this is the output orientation of the constraint.
	*/
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
	/*Bundle of matrix, input position, and weight*/
	const TargetID& getTarget(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i]",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input geometry to which the object should be constrained*/
	const GenericID& getTargetGeometry(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tgm",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input weight for the position*/
	const DoubleID& getTargetWeight(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tw",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input parent inverse matrix for the object*/
	MatrixID getConstraintParentInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cpim",mName.c_str());return (const char*)buffer;}
	/*Input aim vector (in local coordinates)*/
	Double3ID getAimVector(){char buffer[4096];sprintf_s (buffer, "%s.a",mName.c_str());return (const char*)buffer;}
	/*Aim vector X component*/
	DoubleID getAimVectorX(){char buffer[4096];sprintf_s (buffer, "%s.a.ax",mName.c_str());return (const char*)buffer;}
	/*Aim vector Y component*/
	DoubleID getAimVectorY(){char buffer[4096];sprintf_s (buffer, "%s.a.ay",mName.c_str());return (const char*)buffer;}
	/*Aim vector Z component*/
	DoubleID getAimVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.a.az",mName.c_str());return (const char*)buffer;}
	/*Input up vector (in local coordinates)*/
	Double3ID getUpVector(){char buffer[4096];sprintf_s (buffer, "%s.u",mName.c_str());return (const char*)buffer;}
	/*Up vector X component*/
	DoubleID getUpVectorX(){char buffer[4096];sprintf_s (buffer, "%s.u.ux",mName.c_str());return (const char*)buffer;}
	/*Up vector Y component*/
	DoubleID getUpVectorY(){char buffer[4096];sprintf_s (buffer, "%s.u.uy",mName.c_str());return (const char*)buffer;}
	/*up vector Z component*/
	DoubleID getUpVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.u.uz",mName.c_str());return (const char*)buffer;}
	/*Input world up vector (in local coordinates)*/
	Double3ID getWorldUpVector(){char buffer[4096];sprintf_s (buffer, "%s.wu",mName.c_str());return (const char*)buffer;}
	/*World up vector X component*/
	DoubleID getWorldUpVectorX(){char buffer[4096];sprintf_s (buffer, "%s.wu.wux",mName.c_str());return (const char*)buffer;}
	/*World up vector Y component*/
	DoubleID getWorldUpVectorY(){char buffer[4096];sprintf_s (buffer, "%s.wu.wuy",mName.c_str());return (const char*)buffer;}
	/*World up vector Z component*/
	DoubleID getWorldUpVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.wu.wuz",mName.c_str());return (const char*)buffer;}
	/*Input world matrix for the up object*/
	MatrixID getWorldUpMatrix(){char buffer[4096];sprintf_s (buffer, "%s.wum",mName.c_str());return (const char*)buffer;}
	/*Input behavior to resolve world up vector.*/
	UnsignedintID getWorldUpType(){char buffer[4096];sprintf_s (buffer, "%s.wut",mName.c_str());return (const char*)buffer;}
	/*Object translation (in local coordinates)*/
	Double3ID getConstraintTranslate(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*Object X translation*/
	DoubleID getConstraintTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctx",mName.c_str());return (const char*)buffer;}
	/*Object Y translation*/
	DoubleID getConstraintTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.ct.cty",mName.c_str());return (const char*)buffer;}
	/*Object Z translation*/
	DoubleID getConstraintTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.ct.ctz",mName.c_str());return (const char*)buffer;}
	/*Object rotate pivot (in local coordinates)*/
	Double3ID getConstraintRotatePivot(){char buffer[4096];sprintf_s (buffer, "%s.crp",mName.c_str());return (const char*)buffer;}
	/*Object X rotate pivot*/
	DoubleID getConstraintRotatePivotX(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpx",mName.c_str());return (const char*)buffer;}
	/*Object Y rotate pivot*/
	DoubleID getConstraintRotatePivotY(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpy",mName.c_str());return (const char*)buffer;}
	/*Object Z rotate pivot*/
	DoubleID getConstraintRotatePivotZ(){char buffer[4096];sprintf_s (buffer, "%s.crp.crpz",mName.c_str());return (const char*)buffer;}
	/*Object rotate translate (in local coordinates)*/
	Double3ID getConstraintRotateTranslate(){char buffer[4096];sprintf_s (buffer, "%s.crt",mName.c_str());return (const char*)buffer;}
	/*Object X rotate translate*/
	DoubleID getConstraintRotateTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.crt.crtx",mName.c_str());return (const char*)buffer;}
	/*Object Y rotate translate*/
	DoubleID getConstraintRotateTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.crt.crty",mName.c_str());return (const char*)buffer;}
	/*Object Z rotate translate*/
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
	/*Output orientation*/
	Double3ID getConstraintRotate(){char buffer[4096];sprintf_s (buffer, "%s.cr",mName.c_str());return (const char*)buffer;}
	/*Output X orientation*/
	DoubleID getConstraintRotateX(){char buffer[4096];sprintf_s (buffer, "%s.cr.crx",mName.c_str());return (const char*)buffer;}
	/*Output Y orientation*/
	DoubleID getConstraintRotateY(){char buffer[4096];sprintf_s (buffer, "%s.cr.cry",mName.c_str());return (const char*)buffer;}
	/*Output Z orientation*/
	DoubleID getConstraintRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.cr.crz",mName.c_str());return (const char*)buffer;}
	/*Output vector from constrained object to target position*/
	Double3ID getConstraintVector(){char buffer[4096];sprintf_s (buffer, "%s.cv",mName.c_str());return (const char*)buffer;}
	/*Output X vector from constrained object to target position*/
	DoubleID getConstraintVectorX(){char buffer[4096];sprintf_s (buffer, "%s.cv.cvx",mName.c_str());return (const char*)buffer;}
	/*Output Y vector from constrained object to target position*/
	DoubleID getConstraintVectorY(){char buffer[4096];sprintf_s (buffer, "%s.cv.cvy",mName.c_str());return (const char*)buffer;}
	/*Output Z vector from constrained object to target position*/
	DoubleID getConstraintVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.cv.cvz",mName.c_str());return (const char*)buffer;}
	/*
	Rest orientation. When enableRestPosition is enabled, and all the weights
	sum to zero, this is the output orientation of the constraint.
	*/
	Double3ID getRestRotate(){char buffer[4096];sprintf_s (buffer, "%s.rsrr",mName.c_str());return (const char*)buffer;}
	/*rest X orientation*/
	DoubleID getRestRotateX(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rrx",mName.c_str());return (const char*)buffer;}
	/*rest Y orientation*/
	DoubleID getRestRotateY(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rry",mName.c_str());return (const char*)buffer;}
	/*rest Z orientation*/
	DoubleID getRestRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.rsrr.rrz",mName.c_str());return (const char*)buffer;}
protected:
	NormalConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Constraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NORMALCONSTRAINT_H__
