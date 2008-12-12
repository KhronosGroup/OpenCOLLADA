/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PAIRBLEND_H__
#define __MayaDM_PAIRBLEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The pairBlend node was designed with the goal of allowing constraints and animation
 to be blended. The setKeyframe command and constraint commands understand the pairBlend
 node and will automatically create it when the user tries to keyframe a constrained object,
 or vice versa.
 <p/>
 The pairBlend supports translate and rotate inputs and outputs.
*/
class PairBlend : public DependNode
{
public:
public:
	PairBlend(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "pairBlend"){}
	virtual ~PairBlend(){}
	/*Index of the current input driver*/
	void setCurrentDriver(unsigned int c){if(c == 0) return; fprintf_s(mFile, "setAttr \".c\" %i;\n", c);}
	/*Input translation 1*/
	void setInTranslate1(const double3& it1){fprintf_s(mFile, "setAttr \".it1\" -type \"double3\" ");it1.write(mFile);fprintf_s(mFile,";\n");}
	/*Input translation 1*/
	void setInTranslate1(const Double3ID& it1){fprintf_s(mFile,"connectAttr \"");it1.write(mFile);fprintf_s(mFile,"\" \"%s.it1\";\n",mName.c_str());}
	/*Input translate x 1*/
	void setInTranslateX1(double itx1){if(itx1 == 0) return; fprintf_s(mFile, "setAttr \".it1.itx1\" %f;\n", itx1);}
	/*Input translate x 1*/
	void setInTranslateX1(const DoubleID& itx1){fprintf_s(mFile,"connectAttr \"");itx1.write(mFile);fprintf_s(mFile,"\" \"%s.it1.itx1\";\n",mName.c_str());}
	/*Input translate y 1*/
	void setInTranslateY1(double ity1){if(ity1 == 0) return; fprintf_s(mFile, "setAttr \".it1.ity1\" %f;\n", ity1);}
	/*Input translate y 1*/
	void setInTranslateY1(const DoubleID& ity1){fprintf_s(mFile,"connectAttr \"");ity1.write(mFile);fprintf_s(mFile,"\" \"%s.it1.ity1\";\n",mName.c_str());}
	/*Input translate z 1*/
	void setInTranslateZ1(double itz1){if(itz1 == 0) return; fprintf_s(mFile, "setAttr \".it1.itz1\" %f;\n", itz1);}
	/*Input translate z 1*/
	void setInTranslateZ1(const DoubleID& itz1){fprintf_s(mFile,"connectAttr \"");itz1.write(mFile);fprintf_s(mFile,"\" \"%s.it1.itz1\";\n",mName.c_str());}
	/*Input rotation 1*/
	void setInRotate1(const double3& ir1){fprintf_s(mFile, "setAttr \".ir1\" -type \"double3\" ");ir1.write(mFile);fprintf_s(mFile,";\n");}
	/*Input rotation 1*/
	void setInRotate1(const Double3ID& ir1){fprintf_s(mFile,"connectAttr \"");ir1.write(mFile);fprintf_s(mFile,"\" \"%s.ir1\";\n",mName.c_str());}
	/*Input rotate x 1*/
	void setInRotateX1(double irx1){if(irx1 == 0) return; fprintf_s(mFile, "setAttr \".ir1.irx1\" %f;\n", irx1);}
	/*Input rotate x 1*/
	void setInRotateX1(const DoubleID& irx1){fprintf_s(mFile,"connectAttr \"");irx1.write(mFile);fprintf_s(mFile,"\" \"%s.ir1.irx1\";\n",mName.c_str());}
	/*Input rotate y 1*/
	void setInRotateY1(double iry1){if(iry1 == 0) return; fprintf_s(mFile, "setAttr \".ir1.iry1\" %f;\n", iry1);}
	/*Input rotate y 1*/
	void setInRotateY1(const DoubleID& iry1){fprintf_s(mFile,"connectAttr \"");iry1.write(mFile);fprintf_s(mFile,"\" \"%s.ir1.iry1\";\n",mName.c_str());}
	/*Input rotate z 1*/
	void setInRotateZ1(double irz1){if(irz1 == 0) return; fprintf_s(mFile, "setAttr \".ir1.irz1\" %f;\n", irz1);}
	/*Input rotate z 1*/
	void setInRotateZ1(const DoubleID& irz1){fprintf_s(mFile,"connectAttr \"");irz1.write(mFile);fprintf_s(mFile,"\" \"%s.ir1.irz1\";\n",mName.c_str());}
	/*Input translation 2*/
	void setInTranslate2(const double3& it2){fprintf_s(mFile, "setAttr \".it2\" -type \"double3\" ");it2.write(mFile);fprintf_s(mFile,";\n");}
	/*Input translation 2*/
	void setInTranslate2(const Double3ID& it2){fprintf_s(mFile,"connectAttr \"");it2.write(mFile);fprintf_s(mFile,"\" \"%s.it2\";\n",mName.c_str());}
	/*Input translate x 2*/
	void setInTranslateX2(double itx2){if(itx2 == 0) return; fprintf_s(mFile, "setAttr \".it2.itx2\" %f;\n", itx2);}
	/*Input translate x 2*/
	void setInTranslateX2(const DoubleID& itx2){fprintf_s(mFile,"connectAttr \"");itx2.write(mFile);fprintf_s(mFile,"\" \"%s.it2.itx2\";\n",mName.c_str());}
	/*Input translate y 2*/
	void setInTranslateY2(double ity2){if(ity2 == 0) return; fprintf_s(mFile, "setAttr \".it2.ity2\" %f;\n", ity2);}
	/*Input translate y 2*/
	void setInTranslateY2(const DoubleID& ity2){fprintf_s(mFile,"connectAttr \"");ity2.write(mFile);fprintf_s(mFile,"\" \"%s.it2.ity2\";\n",mName.c_str());}
	/*Input translate z 2*/
	void setInTranslateZ2(double itz2){if(itz2 == 0) return; fprintf_s(mFile, "setAttr \".it2.itz2\" %f;\n", itz2);}
	/*Input translate z 2*/
	void setInTranslateZ2(const DoubleID& itz2){fprintf_s(mFile,"connectAttr \"");itz2.write(mFile);fprintf_s(mFile,"\" \"%s.it2.itz2\";\n",mName.c_str());}
	/*Input rotation 2*/
	void setInRotate2(const double3& ir2){fprintf_s(mFile, "setAttr \".ir2\" -type \"double3\" ");ir2.write(mFile);fprintf_s(mFile,";\n");}
	/*Input rotation 2*/
	void setInRotate2(const Double3ID& ir2){fprintf_s(mFile,"connectAttr \"");ir2.write(mFile);fprintf_s(mFile,"\" \"%s.ir2\";\n",mName.c_str());}
	/*Input rotate x 2*/
	void setInRotateX2(double irx2){if(irx2 == 0) return; fprintf_s(mFile, "setAttr \".ir2.irx2\" %f;\n", irx2);}
	/*Input rotate x 2*/
	void setInRotateX2(const DoubleID& irx2){fprintf_s(mFile,"connectAttr \"");irx2.write(mFile);fprintf_s(mFile,"\" \"%s.ir2.irx2\";\n",mName.c_str());}
	/*Input rotate y 2*/
	void setInRotateY2(double iry2){if(iry2 == 0) return; fprintf_s(mFile, "setAttr \".ir2.iry2\" %f;\n", iry2);}
	/*Input rotate y 2*/
	void setInRotateY2(const DoubleID& iry2){fprintf_s(mFile,"connectAttr \"");iry2.write(mFile);fprintf_s(mFile,"\" \"%s.ir2.iry2\";\n",mName.c_str());}
	/*Input rotate z 2*/
	void setInRotateZ2(double irz2){if(irz2 == 0) return; fprintf_s(mFile, "setAttr \".ir2.irz2\" %f;\n", irz2);}
	/*Input rotate z 2*/
	void setInRotateZ2(const DoubleID& irz2){fprintf_s(mFile,"connectAttr \"");irz2.write(mFile);fprintf_s(mFile,"\" \"%s.ir2.irz2\";\n",mName.c_str());}
	/*
	Weight between inputs 1 and 2. Weight 0 = all input 1; weight 1 = all input
	2; weight 1.5 = half of each.
	*/
	void setWeight(double w){if(w == 1.0) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*
	Weight between inputs 1 and 2. Weight 0 = all input 1; weight 1 = all input
	2; weight 1.5 = half of each.
	*/
	void setWeight(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*
	This attribute lets us know the order in which rx, ry, and rz are
	applied from the driven object so that we can output rotation values
	appropriately.
	*/
	void setRotateOrder(unsigned int ro){if(ro == 0) return; fprintf_s(mFile, "setAttr \".ro\" %i;\n", ro);}
	/*
	This attribute lets us know the order in which rx, ry, and rz are
	applied from the driven object so that we can output rotation values
	appropriately.
	*/
	void setRotateOrder(const UnsignedintID& ro){fprintf_s(mFile,"connectAttr \"");ro.write(mFile);fprintf_s(mFile,"\" \"%s.ro\";\n",mName.c_str());}
	/*
	Allows output translate x to be set to only input 1, only input 2,
	or the blended value
	*/
	void setTranslateXMode(unsigned int txm){if(txm == 0) return; fprintf_s(mFile, "setAttr \".txm\" %i;\n", txm);}
	/*
	Allows output translate y to be set to only input 1, only input 2,
	or the blended value
	*/
	void setTranslateYMode(unsigned int tym){if(tym == 0) return; fprintf_s(mFile, "setAttr \".tym\" %i;\n", tym);}
	/*
	Allows output translate z to be set to only input 1, only input 2,
	or the blended value
	*/
	void setTranslateZMode(unsigned int tzm){if(tzm == 0) return; fprintf_s(mFile, "setAttr \".tzm\" %i;\n", tzm);}
	/*
	Allows output rotation to be set to only input 1, only input 2,
	or the blended value
	*/
	void setRotateMode(unsigned int rm){if(rm == 0) return; fprintf_s(mFile, "setAttr \".rm\" %i;\n", rm);}
	/*
	Determines if rotation is caclulated by linearly interpolating between
	Euler rotation values, or spherically interplating between quaternion
	values.
	*/
	void setRotInterpolation(unsigned int ri){if(ri == 0) return; fprintf_s(mFile, "setAttr \".ri\" %i;\n", ri);}
	/*Output translation*/
	void setOutTranslate(const Double3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*Output translate x*/
	void setOutTranslateX(const DoubleID& otx){fprintf_s(mFile,"connectAttr \"");otx.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otx\";\n",mName.c_str());}
	/*Output translate y*/
	void setOutTranslateY(const DoubleID& oty){fprintf_s(mFile,"connectAttr \"");oty.write(mFile);fprintf_s(mFile,"\" \"%s.ot.oty\";\n",mName.c_str());}
	/*Output translate z*/
	void setOutTranslateZ(const DoubleID& otz){fprintf_s(mFile,"connectAttr \"");otz.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otz\";\n",mName.c_str());}
	/*Output rotation*/
	void setOutRotate(const Double3ID& or){fprintf_s(mFile,"connectAttr \"");or.write(mFile);fprintf_s(mFile,"\" \"%s.or\";\n",mName.c_str());}
	/*Output rotate x*/
	void setOutRotateX(const DoubleID& orx){fprintf_s(mFile,"connectAttr \"");orx.write(mFile);fprintf_s(mFile,"\" \"%s.or.orx\";\n",mName.c_str());}
	/*Output rotate y*/
	void setOutRotateY(const DoubleID& ory){fprintf_s(mFile,"connectAttr \"");ory.write(mFile);fprintf_s(mFile,"\" \"%s.or.ory\";\n",mName.c_str());}
	/*Output rotate z*/
	void setOutRotateZ(const DoubleID& orz){fprintf_s(mFile,"connectAttr \"");orz.write(mFile);fprintf_s(mFile,"\" \"%s.or.orz\";\n",mName.c_str());}
	/*Input translation 1*/
	Double3ID getInTranslate1(){char buffer[4096];sprintf_s (buffer, "%s.it1",mName.c_str());return (const char*)buffer;}
	/*Input translate x 1*/
	DoubleID getInTranslateX1(){char buffer[4096];sprintf_s (buffer, "%s.it1.itx1",mName.c_str());return (const char*)buffer;}
	/*Input translate y 1*/
	DoubleID getInTranslateY1(){char buffer[4096];sprintf_s (buffer, "%s.it1.ity1",mName.c_str());return (const char*)buffer;}
	/*Input translate z 1*/
	DoubleID getInTranslateZ1(){char buffer[4096];sprintf_s (buffer, "%s.it1.itz1",mName.c_str());return (const char*)buffer;}
	/*Input rotation 1*/
	Double3ID getInRotate1(){char buffer[4096];sprintf_s (buffer, "%s.ir1",mName.c_str());return (const char*)buffer;}
	/*Input rotate x 1*/
	DoubleID getInRotateX1(){char buffer[4096];sprintf_s (buffer, "%s.ir1.irx1",mName.c_str());return (const char*)buffer;}
	/*Input rotate y 1*/
	DoubleID getInRotateY1(){char buffer[4096];sprintf_s (buffer, "%s.ir1.iry1",mName.c_str());return (const char*)buffer;}
	/*Input rotate z 1*/
	DoubleID getInRotateZ1(){char buffer[4096];sprintf_s (buffer, "%s.ir1.irz1",mName.c_str());return (const char*)buffer;}
	/*Input translation 2*/
	Double3ID getInTranslate2(){char buffer[4096];sprintf_s (buffer, "%s.it2",mName.c_str());return (const char*)buffer;}
	/*Input translate x 2*/
	DoubleID getInTranslateX2(){char buffer[4096];sprintf_s (buffer, "%s.it2.itx2",mName.c_str());return (const char*)buffer;}
	/*Input translate y 2*/
	DoubleID getInTranslateY2(){char buffer[4096];sprintf_s (buffer, "%s.it2.ity2",mName.c_str());return (const char*)buffer;}
	/*Input translate z 2*/
	DoubleID getInTranslateZ2(){char buffer[4096];sprintf_s (buffer, "%s.it2.itz2",mName.c_str());return (const char*)buffer;}
	/*Input rotation 2*/
	Double3ID getInRotate2(){char buffer[4096];sprintf_s (buffer, "%s.ir2",mName.c_str());return (const char*)buffer;}
	/*Input rotate x 2*/
	DoubleID getInRotateX2(){char buffer[4096];sprintf_s (buffer, "%s.ir2.irx2",mName.c_str());return (const char*)buffer;}
	/*Input rotate y 2*/
	DoubleID getInRotateY2(){char buffer[4096];sprintf_s (buffer, "%s.ir2.iry2",mName.c_str());return (const char*)buffer;}
	/*Input rotate z 2*/
	DoubleID getInRotateZ2(){char buffer[4096];sprintf_s (buffer, "%s.ir2.irz2",mName.c_str());return (const char*)buffer;}
	/*
	Weight between inputs 1 and 2. Weight 0 = all input 1; weight 1 = all input
	2; weight 1.5 = half of each.
	*/
	DoubleID getWeight(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*
	This attribute lets us know the order in which rx, ry, and rz are
	applied from the driven object so that we can output rotation values
	appropriately.
	*/
	UnsignedintID getRotateOrder(){char buffer[4096];sprintf_s (buffer, "%s.ro",mName.c_str());return (const char*)buffer;}
	/*Output translation*/
	Double3ID getOutTranslate(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*Output translate x*/
	DoubleID getOutTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.ot.otx",mName.c_str());return (const char*)buffer;}
	/*Output translate y*/
	DoubleID getOutTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.ot.oty",mName.c_str());return (const char*)buffer;}
	/*Output translate z*/
	DoubleID getOutTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.ot.otz",mName.c_str());return (const char*)buffer;}
	/*Output rotation*/
	Double3ID getOutRotate(){char buffer[4096];sprintf_s (buffer, "%s.or",mName.c_str());return (const char*)buffer;}
	/*Output rotate x*/
	DoubleID getOutRotateX(){char buffer[4096];sprintf_s (buffer, "%s.or.orx",mName.c_str());return (const char*)buffer;}
	/*Output rotate y*/
	DoubleID getOutRotateY(){char buffer[4096];sprintf_s (buffer, "%s.or.ory",mName.c_str());return (const char*)buffer;}
	/*Output rotate z*/
	DoubleID getOutRotateZ(){char buffer[4096];sprintf_s (buffer, "%s.or.orz",mName.c_str());return (const char*)buffer;}
protected:
	PairBlend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PAIRBLEND_H__
