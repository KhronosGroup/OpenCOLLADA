/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DETACHSURFACE_H__
#define __MayaDM_DETACHSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Detaches a surface at parameter value(s) in a specified direction
 (attribute "direction").  The parameter value(s) are given by the
 the multiattribute "parameter".  The output attribute is a
 multiattribute containing the resulting surface pieces.
 The "keep" multiattribute specifies which surface pieces to keep
 or discard.  The "keep" attribute is one element larger than the
 "parameter" attribute.  eg. if a surface is detached at 3 parameter
 values, then the result is 4 surface pieces to keep or discard.

 <p/>A single detachSurface node can only detach in one direction.
*/
class DetachSurface : public AbstractBaseCreate
{
public:
public:
	DetachSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "detachSurface"){}
	virtual ~DetachSurface(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The output detached surface(s)*/
	void setOutputSurface(size_t os_i,const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i]\";\n",mName.c_str(),os_i);}
	/*
	Direction in which to detach:
	0 - V direction,
	1 - U direction
	*/
	void setDirection(unsigned int d){if(d == 1) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*
	Direction in which to detach:
	0 - V direction,
	1 - U direction
	*/
	void setDirection(const UnsignedintID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*Parameter at which to detach.*/
	void setParameter(size_t p_i,double p){if(p == 0.0) return; fprintf_s(mFile, "setAttr \".p[%i]\" %f;\n", p_i,p);}
	/*Parameter at which to detach.*/
	void setParameter(size_t p_i,const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*Keep the detached pieces.*/
	void setKeep(size_t k_i,bool k){if(k == true) return; fprintf_s(mFile, "setAttr \".k[%i]\" %i;\n", k_i,k);}
	/*Keep the detached pieces.*/
	void setKeep(size_t k_i,const BoolID& k){fprintf_s(mFile,"connectAttr \"");k.write(mFile);fprintf_s(mFile,"\" \"%s.k[%i]\";\n",mName.c_str(),k_i);}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*The output detached surface(s)*/
	const NurbsSurfaceID& getOutputSurface(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i]",mName.c_str(),os_i);return (const char*)buffer;}
	/*
	Direction in which to detach:
	0 - V direction,
	1 - U direction
	*/
	UnsignedintID getDirection(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*Parameter at which to detach.*/
	const DoubleID& getParameter(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*Keep the detached pieces.*/
	const BoolID& getKeep(size_t k_i){char buffer[4096];sprintf_s (buffer, "%s.k[%i]",mName.c_str(),k_i);return (const char*)buffer;}
protected:
	DetachSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DETACHSURFACE_H__
