/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSUBDFACE_H__
#define __MayaDM_POLYSUBDFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Subdivides a face, creating multiple quads or triangles
 (according to the mode) for each input face.<p/>

 In quad mode, a point is created at the center of
 each face and midpoints are inserted on all existing face edges.
 New faces are built by adding edges from the new midpoints to the new
 center point. In triangle mode, only the center point is
 created; the existing vertices are then connected to this new
 center point to form the new faces.<p/>
*/
class PolySubdFace : public PolyModifier
{
public:
public:
	PolySubdFace(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polySubdFace"){}
	virtual ~PolySubdFace(){}
	/*
	The number of subdivision steps to perform. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	void setDivisions(int dv){if(dv == 1) return; fprintf_s(mFile, "setAttr \".dv\" %i;\n", dv);}
	/*
	The number of subdivision steps to perform. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	void setDivisions(const IntID& dv){fprintf_s(mFile,"connectAttr \"");dv.write(mFile);fprintf_s(mFile,"\" \"%s.dv\";\n",mName.c_str());}
	/*
	The number of subdivision steps to perform along U direction. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	void setDivisionsU(int duv){if(duv == 1) return; fprintf_s(mFile, "setAttr \".duv\" %i;\n", duv);}
	/*
	The number of subdivision steps to perform along U direction. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	void setDivisionsU(const IntID& duv){fprintf_s(mFile,"connectAttr \"");duv.write(mFile);fprintf_s(mFile,"\" \"%s.duv\";\n",mName.c_str());}
	/*
	The number of subdivision steps to perform along V direction. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	void setDivisionsV(int dvv){if(dvv == 1) return; fprintf_s(mFile, "setAttr \".dvv\" %i;\n", dvv);}
	/*
	The number of subdivision steps to perform along V direction. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	void setDivisionsV(const IntID& dvv){fprintf_s(mFile,"connectAttr \"");dvv.write(mFile);fprintf_s(mFile,"\" \"%s.dvv\";\n",mName.c_str());}
	/*Specifies the subdivision mode : 0=quads, 1=triangles*/
	void setMode(unsigned int m){if(m == 0) return; fprintf_s(mFile, "setAttr \".m\" %i;\n", m);}
	/*Specifies the subdivision mode : 0=quads, 1=triangles*/
	void setMode(const UnsignedintID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*
	Type of subdivision to use
	0 - exponential - traditional subdivision
	1 - linear - number of faces per edge grows linearly
	*/
	void setSubdMethod(unsigned int sbm){if(sbm == 0) return; fprintf_s(mFile, "setAttr \".sbm\" %i;\n", sbm);}
	/*
	Type of subdivision to use
	0 - exponential - traditional subdivision
	1 - linear - number of faces per edge grows linearly
	*/
	void setSubdMethod(const UnsignedintID& sbm){fprintf_s(mFile,"connectAttr \"");sbm.write(mFile);fprintf_s(mFile,"\" \"%s.sbm\";\n",mName.c_str());}
	/*
	The number of subdivision steps to perform. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	IntID getDivisions(){char buffer[4096];sprintf_s (buffer, "%s.dv",mName.c_str());return (const char*)buffer;}
	/*
	The number of subdivision steps to perform along U direction. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	IntID getDivisionsU(){char buffer[4096];sprintf_s (buffer, "%s.duv",mName.c_str());return (const char*)buffer;}
	/*
	The number of subdivision steps to perform along V direction. A square face will be subdivided
	into 4^(divisions) faces in quad mode, 4*3^(divisions-1) in triangle mode.
	*/
	IntID getDivisionsV(){char buffer[4096];sprintf_s (buffer, "%s.dvv",mName.c_str());return (const char*)buffer;}
	/*Specifies the subdivision mode : 0=quads, 1=triangles*/
	UnsignedintID getMode(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*
	Type of subdivision to use
	0 - exponential - traditional subdivision
	1 - linear - number of faces per edge grows linearly
	*/
	UnsignedintID getSubdMethod(){char buffer[4096];sprintf_s (buffer, "%s.sbm",mName.c_str());return (const char*)buffer;}
protected:
	PolySubdFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSUBDFACE_H__
