/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_EXPLODENURBSSHELL_H__
#define __MayaDM_EXPLODENURBSSHELL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
<p><pre> The "explodeNurbsShell" node detaches the input NURBS shell into
 individual NURBS surfaces/faces. The input attribute "ish" is used to
 specify the shell to be detached. The surface(s) comprising the shell
 are available at the output attribute "os".
</pre></p>
*/
class ExplodeNurbsShell : public AbstractBaseCreate
{
public:
public:
	ExplodeNurbsShell(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "explodeNurbsShell"){}
	virtual ~ExplodeNurbsShell(){}
	/*The input NURBS shell to be detached as NURBS surfaces.*/
	void setInputShell(const NurbsShellID& ish){fprintf_s(mFile,"connectAttr \"");ish.write(mFile);fprintf_s(mFile,"\" \"%s.ish\";\n",mName.c_str());}
	/*Output NURBS surfaces*/
	void setOutputSurface(size_t os_i,const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os[%i]\";\n",mName.c_str(),os_i);}
	/*The input NURBS shell to be detached as NURBS surfaces.*/
	NurbsShellID getInputShell(){char buffer[4096];sprintf_s (buffer, "%s.ish",mName.c_str());return (const char*)buffer;}
	/*Output NURBS surfaces*/
	const NurbsSurfaceID& getOutputSurface(size_t os_i){char buffer[4096];sprintf_s (buffer, "%s.os[%i]",mName.c_str(),os_i);return (const char*)buffer;}
protected:
	ExplodeNurbsShell(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_EXPLODENURBSSHELL_H__
