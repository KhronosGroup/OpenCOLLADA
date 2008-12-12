/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SCALECONSTRAINT_H__
#define __MayaDM_SCALECONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMConstraint.h"
namespace MayaDM
{
/*
This node implements a scaleConstraint.  Each constraint has a set
        of targets that are connected under the target attribute, a single
        constrained object that is connected to the constraint* attributes,
        and possibly other information to help compute the correct results.
        In the case of the scaleConstraint, there is no other information.

        <p/>The scaleConstraint node can have any number of target inputs.
        Each target is connected to attributes inside a single element
        of the target attribute.  For example, the first target object
        would be connected elements of target[0], the second target object
        would be connected to elements of target[1], etc.  The elements of
        each target are: targetScale, targetParentMatrix, and
        targetWeight.

        <p/>The elements of each target are normally connected to the target
        objects as follows:
        <blockquote>
                <table>
                        <tr>
                                <th>scaleConstraint attribute</th>
                                <th>connected to</th>
                        </tr>
                        <tr>
                                <td>targetScale</td>
                                <td>scale</td>
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
        adjust the weighted average computation for the target scale.

        <p/>The scaleConstraint node uses these inputs to compute the world
        space scale factor of each target object.  It then
        computes a weighted geometric average of the these scales.  This
        weighted average is called the target scale.

        <p/>The constrained object is connected to the constraint*
        attributes.  For a scaleConstraint, the attribute
        constraintParentInverseMatrix is an input and the attribute
        constraintTranslate is the only output.

  <p/>The scaleConstraint node computes an output scale value such
  that the world space scale factor of the constrained object
  matches the target scale.

        <p/>Although the all the constraint nodes inherit from transform,
        they do not actively use any of the attributes from transform.
*/
class ScaleConstraint : public Constraint
{
public:
	/*bundle of matrix, input position, and weight*/
	struct Target{
		double3 targetScale;
		matrix targetParentMatrix;
		double targetWeight;
		void write(FILE* file) const
		{
			targetScale.write(file);
			fprintf_s(file, " ");
			targetParentMatrix.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f", targetWeight);
		}
	};
public:
	ScaleConstraint(FILE* file,const std::string& name,const std::string& parent=""):Constraint(file, name, parent, "scaleConstraint"){}
	virtual ~ScaleConstraint(){}
	/*bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const Target& tg){fprintf_s(mFile, "setAttr \".tg[%i]\" ",tg_i);tg.write(mFile);fprintf_s(mFile,";\n");}
	/*bundle of matrix, input position, and weight*/
	void setTarget(size_t tg_i,const TargetID& tg){fprintf_s(mFile,"connectAttr \"");tg.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i]\";\n",mName.c_str(),tg_i);}
	/*input scale factor*/
	void setTargetScale(size_t tg_i,const double3& ts){fprintf_s(mFile, "setAttr \".tg[%i].ts\" -type \"double3\" ",tg_i);ts.write(mFile);fprintf_s(mFile,";\n");}
	/*input scale factor*/
	void setTargetScale(size_t tg_i,const Double3ID& ts){fprintf_s(mFile,"connectAttr \"");ts.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ts\";\n",mName.c_str(),tg_i);}
	/*input X scale factor*/
	void setTargetScaleX(size_t tg_i,double tsx){if(tsx == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].ts.tsx\" %f;\n", tg_i,tsx);}
	/*input X scale factor*/
	void setTargetScaleX(size_t tg_i,const DoubleID& tsx){fprintf_s(mFile,"connectAttr \"");tsx.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ts.tsx\";\n",mName.c_str(),tg_i);}
	/*input Y scale factor*/
	void setTargetScaleY(size_t tg_i,double tsy){if(tsy == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].ts.tsy\" %f;\n", tg_i,tsy);}
	/*input Y scale factor*/
	void setTargetScaleY(size_t tg_i,const DoubleID& tsy){fprintf_s(mFile,"connectAttr \"");tsy.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ts.tsy\";\n",mName.c_str(),tg_i);}
	/*input Z scale factor*/
	void setTargetScaleZ(size_t tg_i,double tsz){if(tsz == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].ts.tsz\" %f;\n", tg_i,tsz);}
	/*input Z scale factor*/
	void setTargetScaleZ(size_t tg_i,const DoubleID& tsz){fprintf_s(mFile,"connectAttr \"");tsz.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].ts.tsz\";\n",mName.c_str(),tg_i);}
	/*input world position*/
	void setTargetParentMatrix(size_t tg_i,const matrix& tpm){if(tpm == identity) return; fprintf_s(mFile, "setAttr \".tg[%i].tpm\" -type \"matrix\" ",tg_i);tpm.write(mFile);fprintf_s(mFile,";\n");}
	/*input world position*/
	void setTargetParentMatrix(size_t tg_i,const MatrixID& tpm){fprintf_s(mFile,"connectAttr \"");tpm.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tpm\";\n",mName.c_str(),tg_i);}
	/*input weight for the position*/
	void setTargetWeight(size_t tg_i,double tw){if(tw == 1.0) return; fprintf_s(mFile, "setAttr \".tg[%i].tw\" %f;\n", tg_i,tw);}
	/*input weight for the position*/
	void setTargetWeight(size_t tg_i,const DoubleID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tg[%i].tw\";\n",mName.c_str(),tg_i);}
	/*parent inverse matrix of the object*/
	void setConstraintParentInverseMatrix(const matrix& cpim){if(cpim == identity) return; fprintf_s(mFile, "setAttr \".cpim\" -type \"matrix\" ");cpim.write(mFile);fprintf_s(mFile,";\n");}
	/*parent inverse matrix of the object*/
	void setConstraintParentInverseMatrix(const MatrixID& cpim){fprintf_s(mFile,"connectAttr \"");cpim.write(mFile);fprintf_s(mFile,"\" \"%s.cpim\";\n",mName.c_str());}
	/*object offset*/
	void setOffset(const double3& o){fprintf_s(mFile, "setAttr \".o\" -type \"double3\" ");o.write(mFile);fprintf_s(mFile,";\n");}
	/*object offset*/
	void setOffset(const Double3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*object X offset*/
	void setOffsetX(double ox){if(ox == 1.0) return; fprintf_s(mFile, "setAttr \".o.ox\" %f;\n", ox);}
	/*object X offset*/
	void setOffsetX(const DoubleID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*object Y offset*/
	void setOffsetY(double oy){if(oy == 1.0) return; fprintf_s(mFile, "setAttr \".o.oy\" %f;\n", oy);}
	/*object Y offset*/
	void setOffsetY(const DoubleID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*object Z offset*/
	void setOffsetZ(double oz){if(oz == 1.0) return; fprintf_s(mFile, "setAttr \".o.oz\" %f;\n", oz);}
	/*object Z offset*/
	void setOffsetZ(const DoubleID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*output scale factor*/
	void setConstraintScale(const Double3ID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs\";\n",mName.c_str());}
	/*output X scale factor*/
	void setConstraintScaleX(const DoubleID& csx){fprintf_s(mFile,"connectAttr \"");csx.write(mFile);fprintf_s(mFile,"\" \"%s.cs.csx\";\n",mName.c_str());}
	/*output Y scale factor*/
	void setConstraintScaleY(const DoubleID& csy){fprintf_s(mFile,"connectAttr \"");csy.write(mFile);fprintf_s(mFile,"\" \"%s.cs.csy\";\n",mName.c_str());}
	/*output Z scale factor*/
	void setConstraintScaleZ(const DoubleID& csz){fprintf_s(mFile,"connectAttr \"");csz.write(mFile);fprintf_s(mFile,"\" \"%s.cs.csz\";\n",mName.c_str());}
	/*
	Rest scale. When enableRestPosition is enabled, this is the
	output scale.
	*/
	void setRestScale(const Double3ID& rs){fprintf_s(mFile,"connectAttr \"");rs.write(mFile);fprintf_s(mFile,"\" \"%s.rs\";\n",mName.c_str());}
	/*rest X scale factor*/
	void setRestScaleX(const DoubleID& rsx){fprintf_s(mFile,"connectAttr \"");rsx.write(mFile);fprintf_s(mFile,"\" \"%s.rs.rsx\";\n",mName.c_str());}
	/*rest Y scale factor*/
	void setRestScaleY(const DoubleID& rsy){fprintf_s(mFile,"connectAttr \"");rsy.write(mFile);fprintf_s(mFile,"\" \"%s.rs.rsy\";\n",mName.c_str());}
	/*rest Z scale factor*/
	void setRestScaleZ(const DoubleID& rsz){fprintf_s(mFile,"connectAttr \"");rsz.write(mFile);fprintf_s(mFile,"\" \"%s.rs.rsz\";\n",mName.c_str());}
	/*bundle of matrix, input position, and weight*/
	const TargetID& getTarget(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i]",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input scale factor*/
	const Double3ID& getTargetScale(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ts",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input X scale factor*/
	const DoubleID& getTargetScaleX(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ts.tsx",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Y scale factor*/
	const DoubleID& getTargetScaleY(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ts.tsy",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input Z scale factor*/
	const DoubleID& getTargetScaleZ(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].ts.tsz",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input world position*/
	const MatrixID& getTargetParentMatrix(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tpm",mName.c_str(),tg_i);return (const char*)buffer;}
	/*input weight for the position*/
	const DoubleID& getTargetWeight(size_t tg_i){char buffer[4096];sprintf_s (buffer, "%s.tg[%i].tw",mName.c_str(),tg_i);return (const char*)buffer;}
	/*parent inverse matrix of the object*/
	MatrixID getConstraintParentInverseMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cpim",mName.c_str());return (const char*)buffer;}
	/*object offset*/
	Double3ID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*object X offset*/
	DoubleID getOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*object Y offset*/
	DoubleID getOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*object Z offset*/
	DoubleID getOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
	/*output scale factor*/
	Double3ID getConstraintScale(){char buffer[4096];sprintf_s (buffer, "%s.cs",mName.c_str());return (const char*)buffer;}
	/*output X scale factor*/
	DoubleID getConstraintScaleX(){char buffer[4096];sprintf_s (buffer, "%s.cs.csx",mName.c_str());return (const char*)buffer;}
	/*output Y scale factor*/
	DoubleID getConstraintScaleY(){char buffer[4096];sprintf_s (buffer, "%s.cs.csy",mName.c_str());return (const char*)buffer;}
	/*output Z scale factor*/
	DoubleID getConstraintScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.cs.csz",mName.c_str());return (const char*)buffer;}
	/*
	Rest scale. When enableRestPosition is enabled, this is the
	output scale.
	*/
	Double3ID getRestScale(){char buffer[4096];sprintf_s (buffer, "%s.rs",mName.c_str());return (const char*)buffer;}
	/*rest X scale factor*/
	DoubleID getRestScaleX(){char buffer[4096];sprintf_s (buffer, "%s.rs.rsx",mName.c_str());return (const char*)buffer;}
	/*rest Y scale factor*/
	DoubleID getRestScaleY(){char buffer[4096];sprintf_s (buffer, "%s.rs.rsy",mName.c_str());return (const char*)buffer;}
	/*rest Z scale factor*/
	DoubleID getRestScaleZ(){char buffer[4096];sprintf_s (buffer, "%s.rs.rsz",mName.c_str());return (const char*)buffer;}
protected:
	ScaleConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Constraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SCALECONSTRAINT_H__
