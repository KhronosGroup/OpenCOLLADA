/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCHIPOFF_H__
#define __MayaDM_POLYCHIPOFF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveFace.h"
namespace MayaDM
{
/*
Computes the extraction of faces. Faces can be chipped off
 separately or together, keeping originals or not.<p/>

 This node uses many attributes of its parent nodes to calculate
 the extraction.<p/>
*/
class PolyChipOff : public PolyMoveFace
{
public:
public:
	PolyChipOff(FILE* file,const std::string& name,const std::string& parent=""):PolyMoveFace(file, name, parent, "polyChipOff"){}
	virtual ~PolyChipOff(){}
	/*
	Specifies how to chip off faces.
	If on, faces are pulled together (connected ones stay connected),
	otherwise they are pulled independentely.
	*/
	void setKeepFacesTogether(bool kft){if(kft == true) return; fprintf_s(mFile, "setAttr \".kft\" %i;\n", kft);}
	/*
	Specifies how to chip off faces.
	If on, faces are pulled together (connected ones stay connected),
	otherwise they are pulled independentely.
	*/
	void setKeepFacesTogether(const BoolID& kft){fprintf_s(mFile,"connectAttr \"");kft.write(mFile);fprintf_s(mFile,"\" \"%s.kft\";\n",mName.c_str());}
	/*If true : faces are duplicated, otherwise original are destroyed.*/
	void setDuplicate(bool dup){if(dup == true) return; fprintf_s(mFile, "setAttr \".dup\" %i;\n", dup);}
	/*If true : faces are duplicated, otherwise original are destroyed.*/
	void setDuplicate(const BoolID& dup){fprintf_s(mFile,"connectAttr \"");dup.write(mFile);fprintf_s(mFile,"\" \"%s.dup\";\n",mName.c_str());}
	/*
	Specifies how to chip off faces.
	If on, faces are pulled together (connected ones stay connected),
	otherwise they are pulled independentely.
	*/
	BoolID getKeepFacesTogether(){char buffer[4096];sprintf_s (buffer, "%s.kft",mName.c_str());return (const char*)buffer;}
	/*If true : faces are duplicated, otherwise original are destroyed.*/
	BoolID getDuplicate(){char buffer[4096];sprintf_s (buffer, "%s.dup",mName.c_str());return (const char*)buffer;}
protected:
	PolyChipOff(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyMoveFace(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCHIPOFF_H__
