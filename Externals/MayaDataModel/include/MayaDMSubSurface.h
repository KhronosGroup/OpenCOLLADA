/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBSURFACE_H__
#define __MayaDM_SUBSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
The 'subSurface' node is used to selectively cut a portion of
 a NURBS/Bezier surface. The portion of the surface is specified by giving a
 a face index (in U and V directions) and a number of faces in each
 direction to be appended).  Trim information is ignored and invalid
 face indices are skipped.
 <p/>
 The input attribute 'inputSurface' specifies the NURBS surface on
 which the cut should be performed.
 <p/>
 The output attribute '.os' provides the NURBS surface after the cut.
 <p/>
*/
class SubSurface : public AbstractBaseCreate
{
public:
public:
	SubSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "subSurface"){}
	virtual ~SubSurface(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*First face (U direction index)*/
	void setFirstFaceU(int ffu){if(ffu == 0) return; fprintf_s(mFile, "setAttr \".ffu\" %i;\n", ffu);}
	/*First face (U direction index)*/
	void setFirstFaceU(const IntID& ffu){fprintf_s(mFile,"connectAttr \"");ffu.write(mFile);fprintf_s(mFile,"\" \"%s.ffu\";\n",mName.c_str());}
	/*First face (V direction index)*/
	void setFirstFaceV(int ffv){if(ffv == 0) return; fprintf_s(mFile, "setAttr \".ffv\" %i;\n", ffv);}
	/*First face (V direction index)*/
	void setFirstFaceV(const IntID& ffv){fprintf_s(mFile,"connectAttr \"");ffv.write(mFile);fprintf_s(mFile,"\" \"%s.ffv\";\n",mName.c_str());}
	/*Number of faces in U direction*/
	void setFaceCountU(int fcu){if(fcu == 1) return; fprintf_s(mFile, "setAttr \".fcu\" %i;\n", fcu);}
	/*Number of faces in U direction*/
	void setFaceCountU(const IntID& fcu){fprintf_s(mFile,"connectAttr \"");fcu.write(mFile);fprintf_s(mFile,"\" \"%s.fcu\";\n",mName.c_str());}
	/*Number of faces in V direction*/
	void setFaceCountV(int fcv){if(fcv == 1) return; fprintf_s(mFile, "setAttr \".fcv\" %i;\n", fcv);}
	/*Number of faces in V direction*/
	void setFaceCountV(const IntID& fcv){fprintf_s(mFile,"connectAttr \"");fcv.write(mFile);fprintf_s(mFile,"\" \"%s.fcv\";\n",mName.c_str());}
	/*Output surface*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*First face (U direction index)*/
	IntID getFirstFaceU(){char buffer[4096];sprintf_s (buffer, "%s.ffu",mName.c_str());return (const char*)buffer;}
	/*First face (V direction index)*/
	IntID getFirstFaceV(){char buffer[4096];sprintf_s (buffer, "%s.ffv",mName.c_str());return (const char*)buffer;}
	/*Number of faces in U direction*/
	IntID getFaceCountU(){char buffer[4096];sprintf_s (buffer, "%s.fcu",mName.c_str());return (const char*)buffer;}
	/*Number of faces in V direction*/
	IntID getFaceCountV(){char buffer[4096];sprintf_s (buffer, "%s.fcv",mName.c_str());return (const char*)buffer;}
	/*Output surface*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	SubSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBSURFACE_H__
