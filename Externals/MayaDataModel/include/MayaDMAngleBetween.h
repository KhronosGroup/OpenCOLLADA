/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANGLEBETWEEN_H__
#define __MayaDM_ANGLEBETWEEN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Compute the rotation angles (eulerX, eulerY, eulerZ) or an axis
 (axisX, axisY, axisZ) and an angle (angle) that will rotate (normalized)
 vector1 into vector2.
*/
class AngleBetween : public DependNode
{
public:
	/*Output axis and angle*/
	struct AxisAngle{
		void write(FILE* file) const
		{
		}
	};
public:
	AngleBetween(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "angleBetween"){}
	virtual ~AngleBetween(){}
	/*First input vector (from)*/
	void setVector1(const double3& v1){fprintf_s(mFile, "setAttr \".v1\" -type \"double3\" ");v1.write(mFile);fprintf_s(mFile,";\n");}
	/*First input vector (from)*/
	void setVector1(const Double3ID& v1){fprintf_s(mFile,"connectAttr \"");v1.write(mFile);fprintf_s(mFile,"\" \"%s.v1\";\n",mName.c_str());}
	/*X of first input vector*/
	void setVector1X(double v1x){if(v1x == 0) return; fprintf_s(mFile, "setAttr \".v1.v1x\" %f;\n", v1x);}
	/*X of first input vector*/
	void setVector1X(const DoubleID& v1x){fprintf_s(mFile,"connectAttr \"");v1x.write(mFile);fprintf_s(mFile,"\" \"%s.v1.v1x\";\n",mName.c_str());}
	/*Y of first input vector*/
	void setVector1Y(double v1y){if(v1y == 1) return; fprintf_s(mFile, "setAttr \".v1.v1y\" %f;\n", v1y);}
	/*Y of first input vector*/
	void setVector1Y(const DoubleID& v1y){fprintf_s(mFile,"connectAttr \"");v1y.write(mFile);fprintf_s(mFile,"\" \"%s.v1.v1y\";\n",mName.c_str());}
	/*Z of first input vector*/
	void setVector1Z(double v1z){if(v1z == 0) return; fprintf_s(mFile, "setAttr \".v1.v1z\" %f;\n", v1z);}
	/*Z of first input vector*/
	void setVector1Z(const DoubleID& v1z){fprintf_s(mFile,"connectAttr \"");v1z.write(mFile);fprintf_s(mFile,"\" \"%s.v1.v1z\";\n",mName.c_str());}
	/*Second input vector (to)*/
	void setVector2(const double3& v2){fprintf_s(mFile, "setAttr \".v2\" -type \"double3\" ");v2.write(mFile);fprintf_s(mFile,";\n");}
	/*Second input vector (to)*/
	void setVector2(const Double3ID& v2){fprintf_s(mFile,"connectAttr \"");v2.write(mFile);fprintf_s(mFile,"\" \"%s.v2\";\n",mName.c_str());}
	/*X of second input vector*/
	void setVector2X(double v2x){if(v2x == 0) return; fprintf_s(mFile, "setAttr \".v2.v2x\" %f;\n", v2x);}
	/*X of second input vector*/
	void setVector2X(const DoubleID& v2x){fprintf_s(mFile,"connectAttr \"");v2x.write(mFile);fprintf_s(mFile,"\" \"%s.v2.v2x\";\n",mName.c_str());}
	/*Y of second input vector*/
	void setVector2Y(double v2y){if(v2y == 0) return; fprintf_s(mFile, "setAttr \".v2.v2y\" %f;\n", v2y);}
	/*Y of second input vector*/
	void setVector2Y(const DoubleID& v2y){fprintf_s(mFile,"connectAttr \"");v2y.write(mFile);fprintf_s(mFile,"\" \"%s.v2.v2y\";\n",mName.c_str());}
	/*Z of second input vector*/
	void setVector2Z(double v2z){if(v2z == 1) return; fprintf_s(mFile, "setAttr \".v2.v2z\" %f;\n", v2z);}
	/*Z of second input vector*/
	void setVector2Z(const DoubleID& v2z){fprintf_s(mFile,"connectAttr \"");v2z.write(mFile);fprintf_s(mFile,"\" \"%s.v2.v2z\";\n",mName.c_str());}
	/*Output in Euler angles*/
	void setEuler(const Double3ID& eu){fprintf_s(mFile,"connectAttr \"");eu.write(mFile);fprintf_s(mFile,"\" \"%s.eu\";\n",mName.c_str());}
	/*Output Euler "X" angle*/
	void setEulerX(const DoubleID& eux){fprintf_s(mFile,"connectAttr \"");eux.write(mFile);fprintf_s(mFile,"\" \"%s.eu.eux\";\n",mName.c_str());}
	/*Output Euler "Y" angle*/
	void setEulerY(const DoubleID& euy){fprintf_s(mFile,"connectAttr \"");euy.write(mFile);fprintf_s(mFile,"\" \"%s.eu.euy\";\n",mName.c_str());}
	/*Output Euler "Z" angle*/
	void setEulerZ(const DoubleID& euz){fprintf_s(mFile,"connectAttr \"");euz.write(mFile);fprintf_s(mFile,"\" \"%s.eu.euz\";\n",mName.c_str());}
	/*Output axis and angle*/
	void setAxisAngle(const AxisAngleID& axa){fprintf_s(mFile,"connectAttr \"");axa.write(mFile);fprintf_s(mFile,"\" \"%s.axa\";\n",mName.c_str());}
	/*Output axis (in axisAngle)*/
	void setAxis(const Double3ID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.axa.ax\";\n",mName.c_str());}
	/*X of the output axis*/
	void setAxisX(const DoubleID& axx){fprintf_s(mFile,"connectAttr \"");axx.write(mFile);fprintf_s(mFile,"\" \"%s.axa.ax.axx\";\n",mName.c_str());}
	/*Y of the output axis*/
	void setAxisY(const DoubleID& axy){fprintf_s(mFile,"connectAttr \"");axy.write(mFile);fprintf_s(mFile,"\" \"%s.axa.ax.axy\";\n",mName.c_str());}
	/*Z of the output axis*/
	void setAxisZ(const DoubleID& axz){fprintf_s(mFile,"connectAttr \"");axz.write(mFile);fprintf_s(mFile,"\" \"%s.axa.ax.axz\";\n",mName.c_str());}
	/*Output angle (in axisAngle)*/
	void setAngle(const DoubleID& a){fprintf_s(mFile,"connectAttr \"");a.write(mFile);fprintf_s(mFile,"\" \"%s.axa.a\";\n",mName.c_str());}
	/*First input vector (from)*/
	Double3ID getVector1(){char buffer[4096];sprintf_s (buffer, "%s.v1",mName.c_str());return (const char*)buffer;}
	/*X of first input vector*/
	DoubleID getVector1X(){char buffer[4096];sprintf_s (buffer, "%s.v1.v1x",mName.c_str());return (const char*)buffer;}
	/*Y of first input vector*/
	DoubleID getVector1Y(){char buffer[4096];sprintf_s (buffer, "%s.v1.v1y",mName.c_str());return (const char*)buffer;}
	/*Z of first input vector*/
	DoubleID getVector1Z(){char buffer[4096];sprintf_s (buffer, "%s.v1.v1z",mName.c_str());return (const char*)buffer;}
	/*Second input vector (to)*/
	Double3ID getVector2(){char buffer[4096];sprintf_s (buffer, "%s.v2",mName.c_str());return (const char*)buffer;}
	/*X of second input vector*/
	DoubleID getVector2X(){char buffer[4096];sprintf_s (buffer, "%s.v2.v2x",mName.c_str());return (const char*)buffer;}
	/*Y of second input vector*/
	DoubleID getVector2Y(){char buffer[4096];sprintf_s (buffer, "%s.v2.v2y",mName.c_str());return (const char*)buffer;}
	/*Z of second input vector*/
	DoubleID getVector2Z(){char buffer[4096];sprintf_s (buffer, "%s.v2.v2z",mName.c_str());return (const char*)buffer;}
	/*Output in Euler angles*/
	Double3ID getEuler(){char buffer[4096];sprintf_s (buffer, "%s.eu",mName.c_str());return (const char*)buffer;}
	/*Output Euler "X" angle*/
	DoubleID getEulerX(){char buffer[4096];sprintf_s (buffer, "%s.eu.eux",mName.c_str());return (const char*)buffer;}
	/*Output Euler "Y" angle*/
	DoubleID getEulerY(){char buffer[4096];sprintf_s (buffer, "%s.eu.euy",mName.c_str());return (const char*)buffer;}
	/*Output Euler "Z" angle*/
	DoubleID getEulerZ(){char buffer[4096];sprintf_s (buffer, "%s.eu.euz",mName.c_str());return (const char*)buffer;}
	/*Output axis and angle*/
	AxisAngleID getAxisAngle(){char buffer[4096];sprintf_s (buffer, "%s.axa",mName.c_str());return (const char*)buffer;}
	/*Output axis (in axisAngle)*/
	Double3ID getAxis(){char buffer[4096];sprintf_s (buffer, "%s.axa.ax",mName.c_str());return (const char*)buffer;}
	/*X of the output axis*/
	DoubleID getAxisX(){char buffer[4096];sprintf_s (buffer, "%s.axa.ax.axx",mName.c_str());return (const char*)buffer;}
	/*Y of the output axis*/
	DoubleID getAxisY(){char buffer[4096];sprintf_s (buffer, "%s.axa.ax.axy",mName.c_str());return (const char*)buffer;}
	/*Z of the output axis*/
	DoubleID getAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.axa.ax.axz",mName.c_str());return (const char*)buffer;}
	/*Output angle (in axisAngle)*/
	DoubleID getAngle(){char buffer[4096];sprintf_s (buffer, "%s.axa.a",mName.c_str());return (const char*)buffer;}
protected:
	AngleBetween(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ANGLEBETWEEN_H__
