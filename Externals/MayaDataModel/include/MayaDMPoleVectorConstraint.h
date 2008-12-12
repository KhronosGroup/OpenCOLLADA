/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLEVECTORCONSTRAINT_H__
#define __MayaDM_POLEVECTORCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPointConstraint.h"
namespace MayaDM
{
/*
This node implements a poleVectorConstraint.  A
        poleVectorConstraint is a variation on a pointConstraint that is
        designed explicitly to constrain the pole vector of an ikRPsolver ikHandle
        to follow one or more target objects.  In order to
        accomplish this, the poleVectorConstraint adds one extra attribute
        named pivotSpace to those of the pointConstraint.

        <p/>The poleVectorConstraint node can have any number of target inputs.
        From these, a target point is computed by the same means used by the
        pointConstraint.

        <p/>The constrained handle and start joint of that handle are connected
        to the constraint* and pivotSpace attributes.
        <blockquote>
                <table>
                        <tr>
                                <th>poleVector attribute</th>
                                <th>connected to node</th>
                                <th>attribute</th>
                        </tr>
                        <tr>
                                <td>pivotSpace</td>
                                <td>handle start joint</td>
                                <td>parentMatrix</td>
                        </tr>
                        <tr>
                                <td>constraintRotatePivot</td>
                                <td>handle start joint</td>
                                <td>translate</td>
                        </tr>
                        <tr>
                                <td>constraintParentInverseMatrix</td>
                                <td>handle</td>
                                <td>parentInverseMatrix</td>
                        </tr>
                        <tr>
                                <td>constraintTranslate</td>
                                <td>handle</td>
                                <td>poleVector</td>
                        </tr>
                </table>
        </blockquote>

        <p/>The constraintRotatePivot,   constraintParentInverseMatrix,
        pivotSpace are inputs to the poleVectorConstraint. The attribute
        constraintTranslate is the only output. The constraintTranslate value
        is computed such that the poleVector of the constrained handle lies
        at the target point.

        <p/>Although the all the constraint nodes inherit from transform,
        they do not actively use any of the attributes from transform.
*/
class PoleVectorConstraint : public PointConstraint
{
public:
public:
	PoleVectorConstraint(FILE* file,const std::string& name,const std::string& parent=""):PointConstraint(file, name, parent, "poleVectorConstraint"){}
	virtual ~PoleVectorConstraint(){}
	/*
	the world matrix for the constraintRotatePivot and
	constraintRotateTranslate.
	*/
	void setPivotSpace(const matrix& ps){if(ps == identity) return; fprintf_s(mFile, "setAttr \".ps\" -type \"matrix\" ");ps.write(mFile);fprintf_s(mFile,";\n");}
	/*
	the world matrix for the constraintRotatePivot and
	constraintRotateTranslate.
	*/
	void setPivotSpace(const MatrixID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*
	the world matrix for the constraintRotatePivot and
	constraintRotateTranslate.
	*/
	MatrixID getPivotSpace(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
protected:
	PoleVectorConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PointConstraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLEVECTORCONSTRAINT_H__
