/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMODIFIERWORLD_H__
#define __MayaDM_POLYMODIFIERWORLD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
A base node for polygonal modifier nodes which
 can be referenced in either local or world space.
 The worldSpace attribute specifies which reference to use.<p/>
*/
class PolyModifierWorld : public PolyModifier
{
public:
public:
	PolyModifierWorld(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyModifierWorld"){}
	virtual ~PolyModifierWorld(){}
	/*
	Input transformation matrix for world space coords. Default NULL
	value translates to the identity matrix in normal circumstances.
	*/
	void setInputMatrix(const matrix& ix){fprintf_s(mFile, "setAttr \".ix\" -type \"matrix\" ");ix.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Input transformation matrix for world space coords. Default NULL
	value translates to the identity matrix in normal circumstances.
	*/
	void setInputMatrix(const MatrixID& ix){fprintf_s(mFile,"connectAttr \"");ix.write(mFile);fprintf_s(mFile,"\" \"%s.ix\";\n",mName.c_str());}
	/*
	If true, the inputMatrix attribute is used (world space).
	If false, the local transformation matrix is used (object space).
	*/
	void setWorldSpace(bool ws){if(ws == false) return; fprintf_s(mFile, "setAttr \".ws\" %i;\n", ws);}
	/*
	If true, the inputMatrix attribute is used (world space).
	If false, the local transformation matrix is used (object space).
	*/
	void setWorldSpace(const BoolID& ws){fprintf_s(mFile,"connectAttr \"");ws.write(mFile);fprintf_s(mFile,"\" \"%s.ws\";\n",mName.c_str());}
	/*
	Input transformation matrix for manipulator position. Default NULL
	value translates to the identity matrix in normal circumstances.
	*/
	void setManipMatrix(const matrix& mp){fprintf_s(mFile, "setAttr \".mp\" -type \"matrix\" ");mp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Input transformation matrix for manipulator position. Default NULL
	value translates to the identity matrix in normal circumstances.
	*/
	void setManipMatrix(const MatrixID& mp){fprintf_s(mFile,"connectAttr \"");mp.write(mFile);fprintf_s(mFile,"\" \"%s.mp\";\n",mName.c_str());}
	/*
	Input transformation matrix for world space coords. Default NULL
	value translates to the identity matrix in normal circumstances.
	*/
	MatrixID getInputMatrix(){char buffer[4096];sprintf_s (buffer, "%s.ix",mName.c_str());return (const char*)buffer;}
	/*
	If true, the inputMatrix attribute is used (world space).
	If false, the local transformation matrix is used (object space).
	*/
	BoolID getWorldSpace(){char buffer[4096];sprintf_s (buffer, "%s.ws",mName.c_str());return (const char*)buffer;}
	/*
	Input transformation matrix for manipulator position. Default NULL
	value translates to the identity matrix in normal circumstances.
	*/
	MatrixID getManipMatrix(){char buffer[4096];sprintf_s (buffer, "%s.mp",mName.c_str());return (const char*)buffer;}
protected:
	PolyModifierWorld(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMODIFIERWORLD_H__
