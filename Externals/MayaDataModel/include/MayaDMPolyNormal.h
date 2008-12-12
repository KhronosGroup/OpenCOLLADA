/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYNORMAL_H__
#define __MayaDM_POLYNORMAL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Controls the normal orientation of the object.
 The normal computation is done according to one of
 five modes:<br/>
 <ul>
   <li> reverse</li>
   <li> propagate</li>
   <li> conform
 <br/>These 3 modes are being phased out and remain for
 backwards compatability only.</li>
 <li> ReverseAndCut : reverse normals on input faces
   and cut into new shells. Since new vertices and edges need
         to be added to create the new shells, this operation will
         result in vertex and edge index re-numbering thus resulting
         in a change in polygonal topology.</li>
 <li> ReverseAndPropagate : reverse normals on input
   faces and propagate this direction so that all faces
   in the shell are now oriented in the new (reversed)
   direction.</li>
 </ul>
 <p/>
*/
class PolyNormal : public PolyModifier
{
public:
public:
	PolyNormal(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyNormal"){}
	virtual ~PolyNormal(){}
	/*
	Normal mode : 0=reverse, 1=propagate, 2=conform,
	3=reverseAndCut, 4=reverseAndPropagate
	*/
	void setNormalMode(unsigned int nm){if(nm == 0) return; fprintf_s(mFile, "setAttr \".nm\" %i;\n", nm);}
	/*
	Normal mode : 0=reverse, 1=propagate, 2=conform,
	3=reverseAndCut, 4=reverseAndPropagate
	*/
	void setNormalMode(const UnsignedintID& nm){fprintf_s(mFile,"connectAttr \"");nm.write(mFile);fprintf_s(mFile,"\" \"%s.nm\";\n",mName.c_str());}
	/*Determines if user normals needs to be reversed as well.*/
	void setUserNormalMode(bool unm){if(unm == true) return; fprintf_s(mFile, "setAttr \".unm\" %i;\n", unm);}
	/*Determines if user normals needs to be reversed as well.*/
	void setUserNormalMode(const BoolID& unm){fprintf_s(mFile,"connectAttr \"");unm.write(mFile);fprintf_s(mFile,"\" \"%s.unm\";\n",mName.c_str());}
	/*
	Normal mode : 0=reverse, 1=propagate, 2=conform,
	3=reverseAndCut, 4=reverseAndPropagate
	*/
	UnsignedintID getNormalMode(){char buffer[4096];sprintf_s (buffer, "%s.nm",mName.c_str());return (const char*)buffer;}
	/*Determines if user normals needs to be reversed as well.*/
	BoolID getUserNormalMode(){char buffer[4096];sprintf_s (buffer, "%s.unm",mName.c_str());return (const char*)buffer;}
protected:
	PolyNormal(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYNORMAL_H__
