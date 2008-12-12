/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GUIDE_H__
#define __MayaDM_GUIDE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node is used internally by some of the flexor operations.
It serves several purposes:
<br/>
   1) It calculates the bend vector at a joint given the joint
      above, the joint below and the joint itself.
<br/>
   2) It calculates a bend angle. The bend angle is based
      on the type of joint guide specified for jointGuideAxis.
      If "auto" is chosen then straight = 0 deg and completely
      bent = 180 deg.
<br/>
   3) It calculates a bend magnitude. If jointGuideAxis is set to "auto",
      this is a mapping of the bend angle to the range [0, 1].  For all
      other settings of jointGuideAxis, it maps the bend angle to the
      range [-1, 1].  Typically this parameter
      is used as the motor for high-level joint/bone lattice behavior.
<br/>
   4) It serves as a central location for the typical drivers available
      for flexors --> rotateX/Y/Z, maxXYZ and autoGuide. This means that
      the flexor node can connect all of its default drivers to the
      outputs of the guide node.
*/
class Guide : public DependNode
{
public:
public:
	Guide(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "guide"){}
	virtual ~Guide(){}
	/*The matrix of the joint above the motor joint.*/
	void setJointAboveMatrix(const matrix& am){if(am == identity) return; fprintf_s(mFile, "setAttr \".am\" -type \"matrix\" ");am.write(mFile);fprintf_s(mFile,";\n");}
	/*The matrix of the joint above the motor joint.*/
	void setJointAboveMatrix(const MatrixID& am){fprintf_s(mFile,"connectAttr \"");am.write(mFile);fprintf_s(mFile,"\" \"%s.am\";\n",mName.c_str());}
	/*The matrix of the motor joint.*/
	void setJointXformMatrix(const matrix& jm){fprintf_s(mFile, "setAttr \".jm\" -type \"matrix\" ");jm.write(mFile);fprintf_s(mFile,";\n");}
	/*The matrix of the motor joint.*/
	void setJointXformMatrix(const MatrixID& jm){fprintf_s(mFile,"connectAttr \"");jm.write(mFile);fprintf_s(mFile,"\" \"%s.jm\";\n",mName.c_str());}
	/*The matrix of the joint below the motor joint.*/
	void setJointBelowMatrix(const matrix& bm){if(bm == identity) return; fprintf_s(mFile, "setAttr \".bm\" -type \"matrix\" ");bm.write(mFile);fprintf_s(mFile,";\n");}
	/*The matrix of the joint below the motor joint.*/
	void setJointBelowMatrix(const MatrixID& bm){fprintf_s(mFile,"connectAttr \"");bm.write(mFile);fprintf_s(mFile,"\" \"%s.bm\";\n",mName.c_str());}
	/*
	This controls how the joints determine the output for
	bendAngle/bendMagnitude.
	Valid values are 0 = "auto", 1 = "max xyz", 2 = "x", 3 = "y", 4 = "z",
	or 5 = "none".
	*/
	void setJointGuideAxis(unsigned int ga){if(ga == 0) return; fprintf_s(mFile, "setAttr \".ga\" %i;\n", ga);}
	/*
	This controls how the joints determine the output for
	bendAngle/bendMagnitude.
	Valid values are 0 = "auto", 1 = "max xyz", 2 = "x", 3 = "y", 4 = "z",
	or 5 = "none".
	*/
	void setJointGuideAxis(const UnsignedintID& ga){fprintf_s(mFile,"connectAttr \"");ga.write(mFile);fprintf_s(mFile,"\" \"%s.ga\";\n",mName.c_str());}
	/*Bisector of a vector representation of the upper/lower bones.*/
	void setBendVector(const Float3ID& bv){fprintf_s(mFile,"connectAttr \"");bv.write(mFile);fprintf_s(mFile,"\" \"%s.bv\";\n",mName.c_str());}
	/*Bend vector X value.*/
	void setBendVectorX(const FloatID& bx){fprintf_s(mFile,"connectAttr \"");bx.write(mFile);fprintf_s(mFile,"\" \"%s.bv.bx\";\n",mName.c_str());}
	/*Bend vector Y value.*/
	void setBendVectorY(const FloatID& by){fprintf_s(mFile,"connectAttr \"");by.write(mFile);fprintf_s(mFile,"\" \"%s.bv.by\";\n",mName.c_str());}
	/*Bend vector Z value.*/
	void setBendVectorZ(const FloatID& bz){fprintf_s(mFile,"connectAttr \"");bz.write(mFile);fprintf_s(mFile,"\" \"%s.bv.bz\";\n",mName.c_str());}
	/*The bend angle at the motor joint, as specified by the jointGuideAxis.*/
	void setBendAngle(const DoubleID& ba){fprintf_s(mFile,"connectAttr \"");ba.write(mFile);fprintf_s(mFile,"\" \"%s.ba\";\n",mName.c_str());}
	/*A [-1, 1] or [0, 1] remapping of the bend angle.*/
	void setBendMagnitude(const DoubleID& mg){fprintf_s(mFile,"connectAttr \"");mg.write(mFile);fprintf_s(mFile,"\" \"%s.mg\";\n",mName.c_str());}
	/*The generated X rotation of the xform joint.*/
	void setRotateX(const DoubleID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.rx\";\n",mName.c_str());}
	/*The generated Y rotation of the xform joint.*/
	void setRotateY(const DoubleID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.ry\";\n",mName.c_str());}
	/*The generated Z rotation of the xform joint.*/
	void setRotateZ(const DoubleID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.rz\";\n",mName.c_str());}
	/*The maximum of rotateX/Y/Z.*/
	void setMaxXYZ(const DoubleID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma\";\n",mName.c_str());}
	/*The auto guide angle generated by the guide algorithm.*/
	void setAutoGuide(const DoubleID& ag){fprintf_s(mFile,"connectAttr \"");ag.write(mFile);fprintf_s(mFile,"\" \"%s.ag\";\n",mName.c_str());}
	/*The matrix of the joint above the motor joint.*/
	MatrixID getJointAboveMatrix(){char buffer[4096];sprintf_s (buffer, "%s.am",mName.c_str());return (const char*)buffer;}
	/*The matrix of the motor joint.*/
	MatrixID getJointXformMatrix(){char buffer[4096];sprintf_s (buffer, "%s.jm",mName.c_str());return (const char*)buffer;}
	/*The matrix of the joint below the motor joint.*/
	MatrixID getJointBelowMatrix(){char buffer[4096];sprintf_s (buffer, "%s.bm",mName.c_str());return (const char*)buffer;}
	/*
	This controls how the joints determine the output for
	bendAngle/bendMagnitude.
	Valid values are 0 = "auto", 1 = "max xyz", 2 = "x", 3 = "y", 4 = "z",
	or 5 = "none".
	*/
	UnsignedintID getJointGuideAxis(){char buffer[4096];sprintf_s (buffer, "%s.ga",mName.c_str());return (const char*)buffer;}
	/*Bisector of a vector representation of the upper/lower bones.*/
	Float3ID getBendVector(){char buffer[4096];sprintf_s (buffer, "%s.bv",mName.c_str());return (const char*)buffer;}
	/*Bend vector X value.*/
	FloatID getBendVectorX(){char buffer[4096];sprintf_s (buffer, "%s.bv.bx",mName.c_str());return (const char*)buffer;}
	/*Bend vector Y value.*/
	FloatID getBendVectorY(){char buffer[4096];sprintf_s (buffer, "%s.bv.by",mName.c_str());return (const char*)buffer;}
	/*Bend vector Z value.*/
	FloatID getBendVectorZ(){char buffer[4096];sprintf_s (buffer, "%s.bv.bz",mName.c_str());return (const char*)buffer;}
	/*The bend angle at the motor joint, as specified by the jointGuideAxis.*/
	DoubleID getBendAngle(){char buffer[4096];sprintf_s (buffer, "%s.ba",mName.c_str());return (const char*)buffer;}
	/*A [-1, 1] or [0, 1] remapping of the bend angle.*/
	DoubleID getBendMagnitude(){char buffer[4096];sprintf_s (buffer, "%s.mg",mName.c_str());return (const char*)buffer;}
	/*The generated X rotation of the xform joint.*/
	DoubleID getRotateX(){char buffer[4096];sprintf_s (buffer, "%s.rx",mName.c_str());return (const char*)buffer;}
	/*The generated Y rotation of the xform joint.*/
	DoubleID getRotateY(){char buffer[4096];sprintf_s (buffer, "%s.ry",mName.c_str());return (const char*)buffer;}
	/*The generated Z rotation of the xform joint.*/
	DoubleID getRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.rz",mName.c_str());return (const char*)buffer;}
	/*The maximum of rotateX/Y/Z.*/
	DoubleID getMaxXYZ(){char buffer[4096];sprintf_s (buffer, "%s.ma",mName.c_str());return (const char*)buffer;}
	/*The auto guide angle generated by the guide algorithm.*/
	DoubleID getAutoGuide(){char buffer[4096];sprintf_s (buffer, "%s.ag",mName.c_str());return (const char*)buffer;}
protected:
	Guide(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GUIDE_H__
