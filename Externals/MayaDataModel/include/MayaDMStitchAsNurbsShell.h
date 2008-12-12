/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STITCHASNURBSSHELL_H__
#define __MayaDM_STITCHASNURBSSHELL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
<p><pre> The "stitchNurbsShell" node stitches together one or more
 given NURBS surfaces into a NURBS shell. The input attribute
 "is" is used to specify the one or more surfaces. The computed
 NURBS shell is available at the output attribute "osh".
</pre></p>
*/
class StitchAsNurbsShell : public AbstractBaseCreate
{
public:
public:
	StitchAsNurbsShell(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "stitchAsNurbsShell"){}
	virtual ~StitchAsNurbsShell(){}
	/*The input surfaces to be stitched together in to a shell.*/
	void setInputSurface(size_t is_i,const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is[%i]\";\n",mName.c_str(),is_i);}
	/*surfaces are only stitched if their separation is less than this tolerance*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*surfaces are only stitched if their separation is less than this tolerance*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*Output NURBS shell*/
	void setOutputShell(const NurbsShellID& osh){fprintf_s(mFile,"connectAttr \"");osh.write(mFile);fprintf_s(mFile,"\" \"%s.osh\";\n",mName.c_str());}
	/*The input surfaces to be stitched together in to a shell.*/
	const NurbsSurfaceID& getInputSurface(size_t is_i){char buffer[4096];sprintf_s (buffer, "%s.is[%i]",mName.c_str(),is_i);return (const char*)buffer;}
	/*surfaces are only stitched if their separation is less than this tolerance*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*Output NURBS shell*/
	NurbsShellID getOutputShell(){char buffer[4096];sprintf_s (buffer, "%s.osh",mName.c_str());return (const char*)buffer;}
protected:
	StitchAsNurbsShell(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_STITCHASNURBSSHELL_H__
