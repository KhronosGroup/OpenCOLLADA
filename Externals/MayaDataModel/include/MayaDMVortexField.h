/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VORTEXFIELD_H__
#define __MayaDM_VORTEXFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
The vortex node implements a force acting in a circular direction
 about an axis.  The axis is determined by the axisX/Y/Z attributes.<p/>
*/
class VortexField : public Field
{
public:
	/*direction of vortex*/
	struct Axis{
		double axisX;
		double axisY;
		double axisZ;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", axisX);
			fprintf_s(file,"%f ", axisY);
			fprintf_s(file,"%f", axisZ);
		}
	};
public:
	VortexField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "vortexField"){}
	virtual ~VortexField(){}
	/*direction of vortex*/
	void setAxis(const Axis& ax){fprintf_s(mFile, "setAttr \".ax\" ");ax.write(mFile);fprintf_s(mFile,";\n");}
	/*direction of vortex*/
	void setAxis(const AxisID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.ax\";\n",mName.c_str());}
	/*x-axis of vortex*/
	void setAxisX(double axx){if(axx == 0.0) return; fprintf_s(mFile, "setAttr \".ax.axx\" %f;\n", axx);}
	/*x-axis of vortex*/
	void setAxisX(const DoubleID& axx){fprintf_s(mFile,"connectAttr \"");axx.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axx\";\n",mName.c_str());}
	/*y-axis of vortex*/
	void setAxisY(double axy){if(axy == 0.0) return; fprintf_s(mFile, "setAttr \".ax.axy\" %f;\n", axy);}
	/*y-axis of vortex*/
	void setAxisY(const DoubleID& axy){fprintf_s(mFile,"connectAttr \"");axy.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axy\";\n",mName.c_str());}
	/*z-axis of vortex*/
	void setAxisZ(double axz){if(axz == 0.0) return; fprintf_s(mFile, "setAttr \".ax.axz\" %f;\n", axz);}
	/*z-axis of vortex*/
	void setAxisZ(const DoubleID& axz){fprintf_s(mFile,"connectAttr \"");axz.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axz\";\n",mName.c_str());}
	/*direction of vortex*/
	AxisID getAxis(){char buffer[4096];sprintf_s (buffer, "%s.ax",mName.c_str());return (const char*)buffer;}
	/*x-axis of vortex*/
	DoubleID getAxisX(){char buffer[4096];sprintf_s (buffer, "%s.ax.axx",mName.c_str());return (const char*)buffer;}
	/*y-axis of vortex*/
	DoubleID getAxisY(){char buffer[4096];sprintf_s (buffer, "%s.ax.axy",mName.c_str());return (const char*)buffer;}
	/*z-axis of vortex*/
	DoubleID getAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.ax.axz",mName.c_str());return (const char*)buffer;}
protected:
	VortexField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_VORTEXFIELD_H__
