/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSTOSUBDIV_H__
#define __MayaDM_NURBSTOSUBDIV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseNurbsConversion.h"
namespace MayaDM
{
/*
This node produces a subdivision surface based on a NURBS surface.

 This will just create a subdivision surface with the mesh points
 matching the cvs of the surface.  If you have enough spans, the resulting
 shape will be exactly the same if you started with a uniform, bi-cubic
 surface.  Use rebuild surface function to get it into that state if you
 do not like the result of the direct conversion.
*/
class NurbsToSubdiv : public AbstractBaseNurbsConversion
{
public:
public:
	NurbsToSubdiv(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseNurbsConversion(file, name, parent, "nurbsToSubdiv"){}
	virtual ~NurbsToSubdiv(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Output subd surface*/
	void setOutputSubd(const SubdivisionSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The maximum number of base mesh faces in the resulting subdivision surface.*/
	void setMaxPolyCount(int mpc){if(mpc == 1000) return; fprintf_s(mFile, "setAttr \".mpc\" %i;\n", mpc);}
	/*The maximum number of base mesh faces in the resulting subdivision surface.*/
	void setMaxPolyCount(const IntID& mpc){fprintf_s(mFile,"connectAttr \"");mpc.write(mFile);fprintf_s(mFile,"\" \"%s.mpc\";\n",mName.c_str());}
	/*Reverse the NURBS surface normal in the conversion.*/
	void setReverseNormal(bool rn){if(rn == true) return; fprintf_s(mFile, "setAttr \".rn\" %i;\n", rn);}
	/*Reverse the NURBS surface normal in the conversion.*/
	void setReverseNormal(const BoolID& rn){fprintf_s(mFile,"connectAttr \"");rn.write(mFile);fprintf_s(mFile,"\" \"%s.rn\";\n",mName.c_str());}
	/*Match periodic surface texture mapping in the result.*/
	void setMatchPeriodic(bool mp){if(mp == false) return; fprintf_s(mFile, "setAttr \".mp\" %i;\n", mp);}
	/*Match periodic surface texture mapping in the result.*/
	void setMatchPeriodic(const BoolID& mp){fprintf_s(mFile,"connectAttr \"");mp.write(mFile);fprintf_s(mFile,"\" \"%s.mp\";\n",mName.c_str());}
	/*Collapse poles into a single point*/
	void setCollapsePoles(bool cp){if(cp == false) return; fprintf_s(mFile, "setAttr \".cp\" %i;\n", cp);}
	/*Collapse poles into a single point*/
	void setCollapsePoles(const BoolID& cp){fprintf_s(mFile,"connectAttr \"");cp.write(mFile);fprintf_s(mFile,"\" \"%s.cp\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Output subd surface*/
	SubdivisionSurfaceID getOutputSubd(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*The maximum number of base mesh faces in the resulting subdivision surface.*/
	IntID getMaxPolyCount(){char buffer[4096];sprintf_s (buffer, "%s.mpc",mName.c_str());return (const char*)buffer;}
	/*Reverse the NURBS surface normal in the conversion.*/
	BoolID getReverseNormal(){char buffer[4096];sprintf_s (buffer, "%s.rn",mName.c_str());return (const char*)buffer;}
	/*Match periodic surface texture mapping in the result.*/
	BoolID getMatchPeriodic(){char buffer[4096];sprintf_s (buffer, "%s.mp",mName.c_str());return (const char*)buffer;}
	/*Collapse poles into a single point*/
	BoolID getCollapsePoles(){char buffer[4096];sprintf_s (buffer, "%s.cp",mName.c_str());return (const char*)buffer;}
protected:
	NurbsToSubdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseNurbsConversion(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NURBSTOSUBDIV_H__
