/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PRIMITIVE_H__
#define __MayaDM_PRIMITIVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute a surface primitive given a center (pivot) and an axis (axis).
 This is used for creating the revolved primitives such as spheres,
 cylinders, and cones. It is also used for creating planes and cubes.
 Please refer to their documentation for more specific descriptions.
 <p/>
*/
class Primitive : public AbstractBaseCreate
{
public:
public:
	Primitive(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "primitive"){}
	virtual ~Primitive(){}
	/*The primitive's pivot point*/
	void setPivot(const double3& p){fprintf_s(mFile, "setAttr \".p\" -type \"double3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*The primitive's pivot point*/
	void setPivot(const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*X of the pivot*/
	void setPivotX(double px){if(px == 0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*X of the pivot*/
	void setPivotX(const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*Y of the pivot*/
	void setPivotY(double py){if(py == 0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*Y of the pivot*/
	void setPivotY(const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*Z of the pivot*/
	void setPivotZ(double pz){if(pz == 0) return; fprintf_s(mFile, "setAttr \".p.pz\" %f;\n", pz);}
	/*Z of the pivot*/
	void setPivotZ(const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*The primitive's axis*/
	void setAxis(const double3& ax){fprintf_s(mFile, "setAttr \".ax\" -type \"double3\" ");ax.write(mFile);fprintf_s(mFile,";\n");}
	/*The primitive's axis*/
	void setAxis(const Double3ID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.ax\";\n",mName.c_str());}
	/*X of the axis*/
	void setAxisX(double axx){if(axx == 1) return; fprintf_s(mFile, "setAttr \".ax.axx\" %f;\n", axx);}
	/*X of the axis*/
	void setAxisX(const DoubleID& axx){fprintf_s(mFile,"connectAttr \"");axx.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axx\";\n",mName.c_str());}
	/*Y of the axis*/
	void setAxisY(double axy){if(axy == 0) return; fprintf_s(mFile, "setAttr \".ax.axy\" %f;\n", axy);}
	/*Y of the axis*/
	void setAxisY(const DoubleID& axy){fprintf_s(mFile,"connectAttr \"");axy.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axy\";\n",mName.c_str());}
	/*Z of the axis*/
	void setAxisZ(double axz){if(axz == 0) return; fprintf_s(mFile, "setAttr \".ax.axz\" %f;\n", axz);}
	/*Z of the axis*/
	void setAxisZ(const DoubleID& axz){fprintf_s(mFile,"connectAttr \"");axz.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axz\";\n",mName.c_str());}
	/*The created surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The primitive's pivot point*/
	Double3ID getPivot(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*X of the pivot*/
	DoubleID getPivotX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*Y of the pivot*/
	DoubleID getPivotY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*Z of the pivot*/
	DoubleID getPivotZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*The primitive's axis*/
	Double3ID getAxis(){char buffer[4096];sprintf_s (buffer, "%s.ax",mName.c_str());return (const char*)buffer;}
	/*X of the axis*/
	DoubleID getAxisX(){char buffer[4096];sprintf_s (buffer, "%s.ax.axx",mName.c_str());return (const char*)buffer;}
	/*Y of the axis*/
	DoubleID getAxisY(){char buffer[4096];sprintf_s (buffer, "%s.ax.axy",mName.c_str());return (const char*)buffer;}
	/*Z of the axis*/
	DoubleID getAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.ax.axz",mName.c_str());return (const char*)buffer;}
	/*The created surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	Primitive(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PRIMITIVE_H__
