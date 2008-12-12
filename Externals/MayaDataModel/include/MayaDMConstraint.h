/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONSTRAINT_H__
#define __MayaDM_CONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
<p><pre>
 This is the base class for constraint nodes.

</pre></p>
*/
class Constraint : public Transform
{
public:
public:
	Constraint(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "constraint"){}
	virtual ~Constraint(){}
	/*
	This attribute defines the constraint behavior when all weights are at
	zero. If true, the constraint goes to the restTranslate position when
	all weights are zero. If false, the constraint output is not computed
	when all weights are zero.
	*/
	void setEnableRestPosition(bool erp){if(erp == false) return; fprintf_s(mFile, "setAttr \".erp\" %i;\n", erp);}
	/*
	This attribute defines the constraint behavior when all weights are at
	zero. If true, the constraint goes to the restTranslate position when
	all weights are zero. If false, the constraint output is not computed
	when all weights are zero.
	*/
	void setEnableRestPosition(const BoolID& erp){fprintf_s(mFile,"connectAttr \"");erp.write(mFile);fprintf_s(mFile,"\" \"%s.erp\";\n",mName.c_str());}
	/*
	When enabled, the constrained object cannot be moved
	away from its constrained location, and a pairBlend will not be
	inserted if the user tries to keyframe the constrained attributes.
	This allows for the pre-5.0 behavior of constraints.
	<p/>
	When disabled, the constrained object can be moved away from the
	constraint and a pairBlend will be inserted if the object is keyframed
	and the animation blending preference specifies that blending is
	enabled.
	<p/>
	At the time of constraint creation, this attribute is set to its
	initial value based upon the global animation blending preference.
	If the blending preference is set to "Always Blend", this attribute
	will be false. Otherwise, it will be true.
	*/
	void setLockOutput(bool lo){if(lo == false) return; fprintf_s(mFile, "setAttr \".lo\" %i;\n", lo);}
	/*
	When enabled, the constrained object cannot be moved
	away from its constrained location, and a pairBlend will not be
	inserted if the user tries to keyframe the constrained attributes.
	This allows for the pre-5.0 behavior of constraints.
	<p/>
	When disabled, the constrained object can be moved away from the
	constraint and a pairBlend will be inserted if the object is keyframed
	and the animation blending preference specifies that blending is
	enabled.
	<p/>
	At the time of constraint creation, this attribute is set to its
	initial value based upon the global animation blending preference.
	If the blending preference is set to "Always Blend", this attribute
	will be false. Otherwise, it will be true.
	*/
	void setLockOutput(const BoolID& lo){fprintf_s(mFile,"connectAttr \"");lo.write(mFile);fprintf_s(mFile,"\" \"%s.lo\";\n",mName.c_str());}
	/*
	This attribute defines the constraint behavior when all weights are at
	zero. If true, the constraint goes to the restTranslate position when
	all weights are zero. If false, the constraint output is not computed
	when all weights are zero.
	*/
	BoolID getEnableRestPosition(){char buffer[4096];sprintf_s (buffer, "%s.erp",mName.c_str());return (const char*)buffer;}
	/*
	When enabled, the constrained object cannot be moved
	away from its constrained location, and a pairBlend will not be
	inserted if the user tries to keyframe the constrained attributes.
	This allows for the pre-5.0 behavior of constraints.
	<p/>
	When disabled, the constrained object can be moved away from the
	constraint and a pairBlend will be inserted if the object is keyframed
	and the animation blending preference specifies that blending is
	enabled.
	<p/>
	At the time of constraint creation, this attribute is set to its
	initial value based upon the global animation blending preference.
	If the blending preference is set to "Always Blend", this attribute
	will be false. Otherwise, it will be true.
	*/
	BoolID getLockOutput(){char buffer[4096];sprintf_s (buffer, "%s.lo",mName.c_str());return (const char*)buffer;}
protected:
	Constraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CONSTRAINT_H__
