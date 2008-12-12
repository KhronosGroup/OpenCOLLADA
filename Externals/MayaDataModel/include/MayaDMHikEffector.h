/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HIKEFFECTOR_H__
#define __MayaDM_HIKEFFECTOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
<p><pre>
 The hikEffector node can be used to drive Human IK on an associated
 joint hierarchy.

</pre></p>
*/
class HikEffector : public Transform
{
public:
public:
	HikEffector(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "hikEffector"){}
	virtual ~HikEffector(){}
	/*The associated joint for human ik*/
	void setJoint(const MessageID& jt){fprintf_s(mFile,"connectAttr \"");jt.write(mFile);fprintf_s(mFile,"\" \"%s.jt\";\n",mName.c_str());}
	/*The associated FK joint for human ik*/
	void setFkjoint(const MessageID& fj){fprintf_s(mFile,"connectAttr \"");fj.write(mFile);fprintf_s(mFile,"\" \"%s.fj\";\n",mName.c_str());}
	/*
	The pinning state for full-body IK. When set to "unpinned", effectors
	will translate and rotate depending on the full-body solution. When set to "pinTranslate"
	the effectors may rotate with the full-body solution, but their
	translation will not be modified.   When set to "pinRotate"
	the effectors will translate with the full-body solution, but their rotation
	will not be modified. When set to "pinAll", the effectors will not rotate
	or translate.
	*/
	void setPinning(unsigned int pin){if(pin == 0) return; fprintf_s(mFile, "setAttr \".pin\" %i;\n", pin);}
	/*
	The pinning state for full-body IK. When set to "unpinned", effectors
	will translate and rotate depending on the full-body solution. When set to "pinTranslate"
	the effectors may rotate with the full-body solution, but their
	translation will not be modified.   When set to "pinRotate"
	the effectors will translate with the full-body solution, but their rotation
	will not be modified. When set to "pinAll", the effectors will not rotate
	or translate.
	*/
	void setPinning(const UnsignedintID& pin){fprintf_s(mFile,"connectAttr \"");pin.write(mFile);fprintf_s(mFile,"\" \"%s.pin\";\n",mName.c_str());}
	/*connection to associated ik handle*/
	void setHandle(size_t ha_i,const BoolID& ha){fprintf_s(mFile,"connectAttr \"");ha.write(mFile);fprintf_s(mFile,"\" \"%s.ha[%i]\";\n",mName.c_str(),ha_i);}
	/*
	The HumanIK effectorId. This is used internally by the HumanIK solver
	and should not be modified by the user.
	*/
	void setEffectorID(int ei){if(ei == 0) return; fprintf_s(mFile, "setAttr \".ei\" %i;\n", ei);}
	/*
	The HumanIK effectorId. This is used internally by the HumanIK solver
	and should not be modified by the user.
	*/
	void setEffectorID(const IntID& ei){fprintf_s(mFile,"connectAttr \"");ei.write(mFile);fprintf_s(mFile,"\" \"%s.ei\";\n",mName.c_str());}
	/*The associated hikEffectors, each to represent a different pivot*/
	void setPivots(size_t pvt_i,const MessageID& pvt){fprintf_s(mFile,"connectAttr \"");pvt.write(mFile);fprintf_s(mFile,"\" \"%s.pvt[%i]\";\n",mName.c_str(),pvt_i);}
	/*Pivot offset.*/
	void setPivotOffset(const double3& po){fprintf_s(mFile, "setAttr \".po\" -type \"double3\" ");po.write(mFile);fprintf_s(mFile,";\n");}
	/*Pivot offset.*/
	void setPivotOffset(const Double3ID& po){fprintf_s(mFile,"connectAttr \"");po.write(mFile);fprintf_s(mFile,"\" \"%s.po\";\n",mName.c_str());}
	/*PivotOffset X.*/
	void setPivotOffsetX(double px){if(px == 0) return; fprintf_s(mFile, "setAttr \".po.px\" %f;\n", px);}
	/*PivotOffset X.*/
	void setPivotOffsetX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.po.px\";\n",mName.c_str());}
	/*PivotOffset Y.*/
	void setPivotOffsetY(double py){if(py == 0) return; fprintf_s(mFile, "setAttr \".po.py\" %f;\n", py);}
	/*PivotOffset Y.*/
	void setPivotOffsetY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.po.py\";\n",mName.c_str());}
	/*PivotOffset Z.*/
	void setPivotOffsetZ(double pz){if(pz == 0) return; fprintf_s(mFile, "setAttr \".po.pz\" %f;\n", pz);}
	/*PivotOffset Z.*/
	void setPivotOffsetZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.po.pz\";\n",mName.c_str());}
	/*
	Controls how much the joints want to reach their associated effector's translation.
	A value of 1.0 indicates that the joints fully try to reach the effector's translation.
	A value of 0.0 indicates that the joints ignore the effector's translation.
	*/
	void setReachTranslation(double rt){if(rt == 0.0) return; fprintf_s(mFile, "setAttr \".rt\" %f;\n", rt);}
	/*
	Controls how much the joints want to reach their associated effector's translation.
	A value of 1.0 indicates that the joints fully try to reach the effector's translation.
	A value of 0.0 indicates that the joints ignore the effector's translation.
	*/
	void setReachTranslation(const DoubleID& rt){fprintf_s(mFile,"connectAttr \"");rt.write(mFile);fprintf_s(mFile,"\" \"%s.rt\";\n",mName.c_str());}
	/*
	Controls how much the joints want to reach their associated effector's rotation.
	A value of 1.0 indicates that the joints fully try to reach the effector's rotation.
	A value of 0.0 indicates that the joints ignore the effector's rotation.
	*/
	void setReachRotation(double rr){if(rr == 0.0) return; fprintf_s(mFile, "setAttr \".rr\" %f;\n", rr);}
	/*
	Controls how much the joints want to reach their associated effector's rotation.
	A value of 1.0 indicates that the joints fully try to reach the effector's rotation.
	A value of 0.0 indicates that the joints ignore the effector's rotation.
	*/
	void setReachRotation(const DoubleID& rr){fprintf_s(mFile,"connectAttr \"");rr.write(mFile);fprintf_s(mFile,"\" \"%s.rr\";\n",mName.c_str());}
	/*Draw radius for the effector.*/
	void setRadius(double radi){if(radi == 1.0) return; fprintf_s(mFile, "setAttr \".radi\" %f;\n", radi);}
	/*Draw radius for the effector.*/
	void setRadius(const DoubleID& radi){fprintf_s(mFile,"connectAttr \"");radi.write(mFile);fprintf_s(mFile,"\" \"%s.radi\";\n",mName.c_str());}
	/*Whether this effector behaves as an auxilliary effector.*/
	void setAuxEffector(bool aeff){if(aeff == false) return; fprintf_s(mFile, "setAttr \".aeff\" %i;\n", aeff);}
	/*Whether this effector behaves as an auxilliary effector.*/
	void setAuxEffector(const BoolID& aeff){fprintf_s(mFile,"connectAttr \"");aeff.write(mFile);fprintf_s(mFile,"\" \"%s.aeff\";\n",mName.c_str());}
	/*The pre rotation, similar to the joint orient on joints.*/
	void setPreRotation(const double3& pr){fprintf_s(mFile, "setAttr \".pr\" -type \"double3\" ");pr.write(mFile);fprintf_s(mFile,";\n");}
	/*The pre rotation, similar to the joint orient on joints.*/
	void setPreRotation(const Double3ID& pr){fprintf_s(mFile,"connectAttr \"");pr.write(mFile);fprintf_s(mFile,"\" \"%s.pr\";\n",mName.c_str());}
	/*pre rotationX.*/
	void setPreRotationX(double prx){if(prx == 0) return; fprintf_s(mFile, "setAttr \".pr.prx\" %f;\n", prx);}
	/*pre rotationX.*/
	void setPreRotationX(const DoubleID& prx){fprintf_s(mFile,"connectAttr \"");prx.write(mFile);fprintf_s(mFile,"\" \"%s.pr.prx\";\n",mName.c_str());}
	/*pre rotationY.*/
	void setPreRotationY(double pry){if(pry == 0) return; fprintf_s(mFile, "setAttr \".pr.pry\" %f;\n", pry);}
	/*pre rotationY.*/
	void setPreRotationY(const DoubleID& pry){fprintf_s(mFile,"connectAttr \"");pry.write(mFile);fprintf_s(mFile,"\" \"%s.pr.pry\";\n",mName.c_str());}
	/*pre rotationZ.*/
	void setPreRotationZ(double prz){if(prz == 0) return; fprintf_s(mFile, "setAttr \".pr.prz\" %f;\n", prz);}
	/*pre rotationZ.*/
	void setPreRotationZ(const DoubleID& prz){fprintf_s(mFile,"connectAttr \"");prz.write(mFile);fprintf_s(mFile,"\" \"%s.pr.prz\";\n",mName.c_str());}
	/*Used to store the color for fbx import/export*/
	void setColor(const float3& col){fprintf_s(mFile, "setAttr \".col\" -type \"float3\" ");col.write(mFile);fprintf_s(mFile,";\n");}
	/*Used to store the color for fbx import/export*/
	void setColor(const Float3ID& col){fprintf_s(mFile,"connectAttr \"");col.write(mFile);fprintf_s(mFile,"\" \"%s.col\";\n",mName.c_str());}
	/*Used to store the red color value for fbx import/export*/
	void setColorR(float clr){if(clr == 1.0) return; fprintf_s(mFile, "setAttr \".col.clr\" %f;\n", clr);}
	/*Used to store the red color value for fbx import/export*/
	void setColorR(const FloatID& clr){fprintf_s(mFile,"connectAttr \"");clr.write(mFile);fprintf_s(mFile,"\" \"%s.col.clr\";\n",mName.c_str());}
	/*Used to store the green color value for fbx import/export*/
	void setColorG(float clg){if(clg == 0.0) return; fprintf_s(mFile, "setAttr \".col.clg\" %f;\n", clg);}
	/*Used to store the green color value for fbx import/export*/
	void setColorG(const FloatID& clg){fprintf_s(mFile,"connectAttr \"");clg.write(mFile);fprintf_s(mFile,"\" \"%s.col.clg\";\n",mName.c_str());}
	/*Used to store the blue color value for fbx import/export*/
	void setColorB(float clb){if(clb == 0.0) return; fprintf_s(mFile, "setAttr \".col.clb\" %f;\n", clb);}
	/*Used to store the blue color value for fbx import/export*/
	void setColorB(const FloatID& clb){fprintf_s(mFile,"connectAttr \"");clb.write(mFile);fprintf_s(mFile,"\" \"%s.col.clb\";\n",mName.c_str());}
	/*Used to store the alpha value for fbx import/export*/
	void setAlpha(float alp){if(alp == 1.0) return; fprintf_s(mFile, "setAttr \".alp\" %f;\n", alp);}
	/*Used to store the alpha value for fbx import/export*/
	void setAlpha(const FloatID& alp){fprintf_s(mFile,"connectAttr \"");alp.write(mFile);fprintf_s(mFile,"\" \"%s.alp\";\n",mName.c_str());}
	/*Used to store the marker look for fbx import/export*/
	void setMarkerLook(unsigned int mkl){if(mkl == 3) return; fprintf_s(mFile, "setAttr \".mkl\" %i;\n", mkl);}
	/*Used to store the marker look for fbx import/export*/
	void setMarkerLook(const UnsignedintID& mkl){fprintf_s(mFile,"connectAttr \"");mkl.write(mFile);fprintf_s(mFile,"\" \"%s.mkl\";\n",mName.c_str());}
	/*The associated joint for human ik*/
	MessageID getJoint(){char buffer[4096];sprintf_s (buffer, "%s.jt",mName.c_str());return (const char*)buffer;}
	/*The associated FK joint for human ik*/
	MessageID getFkjoint(){char buffer[4096];sprintf_s (buffer, "%s.fj",mName.c_str());return (const char*)buffer;}
	/*
	The pinning state for full-body IK. When set to "unpinned", effectors
	will translate and rotate depending on the full-body solution. When set to "pinTranslate"
	the effectors may rotate with the full-body solution, but their
	translation will not be modified.   When set to "pinRotate"
	the effectors will translate with the full-body solution, but their rotation
	will not be modified. When set to "pinAll", the effectors will not rotate
	or translate.
	*/
	UnsignedintID getPinning(){char buffer[4096];sprintf_s (buffer, "%s.pin",mName.c_str());return (const char*)buffer;}
	/*connection to associated ik handle*/
	const BoolID& getHandle(size_t ha_i){char buffer[4096];sprintf_s (buffer, "%s.ha[%i]",mName.c_str(),ha_i);return (const char*)buffer;}
	/*
	The HumanIK effectorId. This is used internally by the HumanIK solver
	and should not be modified by the user.
	*/
	IntID getEffectorID(){char buffer[4096];sprintf_s (buffer, "%s.ei",mName.c_str());return (const char*)buffer;}
	/*The associated hikEffectors, each to represent a different pivot*/
	const MessageID& getPivots(size_t pvt_i){char buffer[4096];sprintf_s (buffer, "%s.pvt[%i]",mName.c_str(),pvt_i);return (const char*)buffer;}
	/*Pivot offset.*/
	Double3ID getPivotOffset(){char buffer[4096];sprintf_s (buffer, "%s.po",mName.c_str());return (const char*)buffer;}
	/*PivotOffset X.*/
	DoubleID getPivotOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.po.px",mName.c_str());return (const char*)buffer;}
	/*PivotOffset Y.*/
	DoubleID getPivotOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.po.py",mName.c_str());return (const char*)buffer;}
	/*PivotOffset Z.*/
	DoubleID getPivotOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.po.pz",mName.c_str());return (const char*)buffer;}
	/*
	Controls how much the joints want to reach their associated effector's translation.
	A value of 1.0 indicates that the joints fully try to reach the effector's translation.
	A value of 0.0 indicates that the joints ignore the effector's translation.
	*/
	DoubleID getReachTranslation(){char buffer[4096];sprintf_s (buffer, "%s.rt",mName.c_str());return (const char*)buffer;}
	/*
	Controls how much the joints want to reach their associated effector's rotation.
	A value of 1.0 indicates that the joints fully try to reach the effector's rotation.
	A value of 0.0 indicates that the joints ignore the effector's rotation.
	*/
	DoubleID getReachRotation(){char buffer[4096];sprintf_s (buffer, "%s.rr",mName.c_str());return (const char*)buffer;}
	/*Draw radius for the effector.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.radi",mName.c_str());return (const char*)buffer;}
	/*Whether this effector behaves as an auxilliary effector.*/
	BoolID getAuxEffector(){char buffer[4096];sprintf_s (buffer, "%s.aeff",mName.c_str());return (const char*)buffer;}
	/*The pre rotation, similar to the joint orient on joints.*/
	Double3ID getPreRotation(){char buffer[4096];sprintf_s (buffer, "%s.pr",mName.c_str());return (const char*)buffer;}
	/*pre rotationX.*/
	DoubleID getPreRotationX(){char buffer[4096];sprintf_s (buffer, "%s.pr.prx",mName.c_str());return (const char*)buffer;}
	/*pre rotationY.*/
	DoubleID getPreRotationY(){char buffer[4096];sprintf_s (buffer, "%s.pr.pry",mName.c_str());return (const char*)buffer;}
	/*pre rotationZ.*/
	DoubleID getPreRotationZ(){char buffer[4096];sprintf_s (buffer, "%s.pr.prz",mName.c_str());return (const char*)buffer;}
	/*Used to store the color for fbx import/export*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.col",mName.c_str());return (const char*)buffer;}
	/*Used to store the red color value for fbx import/export*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.col.clr",mName.c_str());return (const char*)buffer;}
	/*Used to store the green color value for fbx import/export*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.col.clg",mName.c_str());return (const char*)buffer;}
	/*Used to store the blue color value for fbx import/export*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.col.clb",mName.c_str());return (const char*)buffer;}
	/*Used to store the alpha value for fbx import/export*/
	FloatID getAlpha(){char buffer[4096];sprintf_s (buffer, "%s.alp",mName.c_str());return (const char*)buffer;}
	/*Used to store the marker look for fbx import/export*/
	UnsignedintID getMarkerLook(){char buffer[4096];sprintf_s (buffer, "%s.mkl",mName.c_str());return (const char*)buffer;}
protected:
	HikEffector(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HIKEFFECTOR_H__
