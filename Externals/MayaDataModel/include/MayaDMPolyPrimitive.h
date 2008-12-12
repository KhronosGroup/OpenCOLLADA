/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPRIMITIVE_H__
#define __MayaDM_POLYPRIMITIVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyCreator.h"
namespace MayaDM
{
/*
A base node for the polygonal primitives nodes (cone,
 cube, cylinder, plane, sphere, torus). This node owns
 the primitive axis, which is used to build the primitive.<p/>
*/
class PolyPrimitive : public PolyCreator
{
public:
public:
	PolyPrimitive(FILE* file,const std::string& name,const std::string& parent=""):PolyCreator(file, name, parent, "polyPrimitive"){}
	virtual ~PolyPrimitive(){}
	/*The primitive axis used to build the primitive.*/
	void setAxis(const double3& ax){fprintf_s(mFile, "setAttr \".ax\" -type \"double3\" ");ax.write(mFile);fprintf_s(mFile,";\n");}
	/*The primitive axis used to build the primitive.*/
	void setAxis(const Double3ID& ax){fprintf_s(mFile,"connectAttr \"");ax.write(mFile);fprintf_s(mFile,"\" \"%s.ax\";\n",mName.c_str());}
	/*X axis coord.*/
	void setAxisX(double axx){if(axx == 0) return; fprintf_s(mFile, "setAttr \".ax.axx\" %f;\n", axx);}
	/*X axis coord.*/
	void setAxisX(const DoubleID& axx){fprintf_s(mFile,"connectAttr \"");axx.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axx\";\n",mName.c_str());}
	/*Y axis coord.*/
	void setAxisY(double axy){if(axy == 1) return; fprintf_s(mFile, "setAttr \".ax.axy\" %f;\n", axy);}
	/*Y axis coord.*/
	void setAxisY(const DoubleID& axy){fprintf_s(mFile,"connectAttr \"");axy.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axy\";\n",mName.c_str());}
	/*Z axis coord.*/
	void setAxisZ(double axz){if(axz == 0) return; fprintf_s(mFile, "setAttr \".ax.axz\" %f;\n", axz);}
	/*Z axis coord.*/
	void setAxisZ(const DoubleID& axz){fprintf_s(mFile,"connectAttr \"");axz.write(mFile);fprintf_s(mFile,"\" \"%s.ax.axz\";\n",mName.c_str());}
	/*Check for reasonable parameter settings.*/
	void setParamWarn(bool pw){if(pw == true) return; fprintf_s(mFile, "setAttr \".pw\" %i;\n", pw);}
	/*Check for reasonable parameter settings.*/
	void setParamWarn(const BoolID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.pw\";\n",mName.c_str());}
	/*The name of the map set to create uvs on, if any*/
	void setUvSetName(const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs\" -type \"string\" ");uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*The name of the map set to create uvs on, if any*/
	void setUvSetName(const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs\";\n",mName.c_str());}
	/*The primitive axis used to build the primitive.*/
	Double3ID getAxis(){char buffer[4096];sprintf_s (buffer, "%s.ax",mName.c_str());return (const char*)buffer;}
	/*X axis coord.*/
	DoubleID getAxisX(){char buffer[4096];sprintf_s (buffer, "%s.ax.axx",mName.c_str());return (const char*)buffer;}
	/*Y axis coord.*/
	DoubleID getAxisY(){char buffer[4096];sprintf_s (buffer, "%s.ax.axy",mName.c_str());return (const char*)buffer;}
	/*Z axis coord.*/
	DoubleID getAxisZ(){char buffer[4096];sprintf_s (buffer, "%s.ax.axz",mName.c_str());return (const char*)buffer;}
	/*Check for reasonable parameter settings.*/
	BoolID getParamWarn(){char buffer[4096];sprintf_s (buffer, "%s.pw",mName.c_str());return (const char*)buffer;}
	/*The name of the map set to create uvs on, if any*/
	StringID getUvSetName(){char buffer[4096];sprintf_s (buffer, "%s.uvs",mName.c_str());return (const char*)buffer;}
protected:
	PolyPrimitive(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyCreator(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYPRIMITIVE_H__
