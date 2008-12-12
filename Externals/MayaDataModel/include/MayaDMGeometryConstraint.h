/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOMETRYCONSTRAINT_H__
#define __MayaDM_GEOMETRYCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
/*
This node implements (part of) a geometryConstraint.  Each
        constraint has a set of targets that are connected under the
        target attribute, a single constrained object that is connected to
        the constraint* attributes, and possibly other information to help
        compute the correct results.  In the case of the
        geometryConstraint, there is no additional information.

        <p/>The geometryConstraint node can have any number of target inputs.
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
                                <th>geometryConstraint attribute</th>
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
        attributes.  For a geometryConstraint, the attribute
        constraintParentInverseMatrix is an input and the attribute
        constraintGeometry is the only output.

        <p/>The geometryConstraint node simply provides on its output
        (constraintGeometry), the input with the largest targetWeight
        value.  If more than one target has the same value, the one with
        the lowest target index is returned.  This output geometry is then
        passed to the geometry attribute of a transform which causes the
        transform to constrain its translate values.

        <p/>Although the all the constraint nodes inherit from transform,
        they do not actively use any of the attributes from transform.
*/
class GeometryConstraint : public Constraint
{
public:
	/*Bundle of input geometry and weight*/
	struct Target{
		double targetWeight;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f", targetWeight);
		}
	};
public:
	GeometryConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "geometryConstraint"){}
	virtual ~GeometryConstraint(){}
	/*Bundle of input geometry and weight*/
	void setTarget(size_t tg_i,const Target& tg){fprintf_s(mFile, "setAttr \".tg[%i]\" ",tg_i);tg.write(mFile);fprintf_s(mFile,";\n");}
	/*Bundle of input geometry and weight*/
	void setTarget(size_t tg_i,const TargetID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i]\";\n",mName.c_str(),tg_i);}
	/*input geometry to which the object should be constrained*/
	void setTargetGeometry(size_t tg_i,const GenericID& tgm){fprintf_s(mFile,"connectAttr \"");tgm.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tgm\";\n",mName.c_str(),tg_i);}
	/*Input weight for the geometry, the largest weight wins*/
	void setTargetWeight(size_t tg_i,double tw){if(tw == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].tw\" %f;\n", tg_i,tw);}
	/*Input weight for the geometry, the largest weight wins*/
	void setTargetWeight(size_t tg_i,const DoubleID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tw\";\n",mName.c_str(),tg_i);}
	/*Input parent inverse matrix for the object*/
	void setConstraintParentInverseMatrix(const matrix& cpim){if(cpim == identity) return; fprintf_s(mFile, "setAttr \".cpim\" -type \"matrix\" ");cpim.write(mFile);fprintf_s(mFile,";\n");}
	/*Input parent inverse matrix for the object*/
	void setConstraintParentInverseMatrix(const MatrixID& cpim){fprintf_s(mFile,"connectAttr \"");cpim.write(mFile);fprintf_s(mFile,"\" \"%s.cpim\";\n",mName.c_str());}
	/*output geometry to which the object should be constrained*/
	void setConstraintGeometry(const GenericID& cgm){fprintf_s(mFile,"connectAttr \"");cgm.write(mFile);fprintf_s(mFile,"\" \"%s.cgm\";\n",mName.c_str());}
	/*Bundle of input geometry and weight*/
	const TargetID& getTarget(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i]",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input geometry to which the object should be constrained*/
	const GenericID& getTargetGeometry(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tgm",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input weight for the geometry, the largest weight wins*/
	const DoubleID& getTargetWeight(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tw",mName.c_str(),tg_i);return (const char*)buffer;}
	/*Input parent inverse matrix for the object*/
	MatrixID getConstraintParentInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cpim",mName.c_str());return (const char*)buffer;}
	/*output geometry to which the object should be constrained*/
	GenericID getConstraintGeometry(){char buffer[4096];sprintf_s (buffer, "%s.cgm",mName.c_str());return (const char*)buffer;}
protected:
	GeometryConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Constraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYCONSTRAINT_H__
