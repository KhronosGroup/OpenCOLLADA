/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVREVERSEFACES_H__
#define __MayaDM_SUBDIVREVERSEFACES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class SubdivReverseFaces : public DependNode
{
public:
public:
	SubdivReverseFaces(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdivReverseFaces"){}
	virtual ~SubdivReverseFaces(){}
	/*The input subdivision surface for which faces are to be reversed.*/
	void setInSubdiv(const SubdivisionSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Mirror the vertices in X*/
	void setXMirror(bool xm){if(xm == false) return; fprintf_s(mFile, "setAttr \".xm\" %i;\n", xm);}
	/*Mirror the vertices in X*/
	void setXMirror(const BoolID& xm){fprintf_s(mFile,"connectAttr \"");xm.write(mFile);fprintf_s(mFile,"\" \"%s.xm\";\n",mName.c_str());}
	/*Mirror the vertices in Y*/
	void setYMirror(bool ym){if(ym == false) return; fprintf_s(mFile, "setAttr \".ym\" %i;\n", ym);}
	/*Mirror the vertices in Y*/
	void setYMirror(const BoolID& ym){fprintf_s(mFile,"connectAttr \"");ym.write(mFile);fprintf_s(mFile,"\" \"%s.ym\";\n",mName.c_str());}
	/*Mirror the vertices in Z*/
	void setZMirror(bool zm){if(zm == false) return; fprintf_s(mFile, "setAttr \".zm\" %i;\n", zm);}
	/*Mirror the vertices in Z*/
	void setZMirror(const BoolID& zm){fprintf_s(mFile,"connectAttr \"");zm.write(mFile);fprintf_s(mFile,"\" \"%s.zm\";\n",mName.c_str());}
	/*The resulting subdivision surface*/
	void setOutSubdiv(const SubdivisionSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*The input subdivision surface for which faces are to be reversed.*/
	SubdivisionSurfaceID getInSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Mirror the vertices in X*/
	BoolID getXMirror(){char buffer[4096];sprintf_s (buffer, "%s.xm",mName.c_str());return (const char*)buffer;}
	/*Mirror the vertices in Y*/
	BoolID getYMirror(){char buffer[4096];sprintf_s (buffer, "%s.ym",mName.c_str());return (const char*)buffer;}
	/*Mirror the vertices in Z*/
	BoolID getZMirror(){char buffer[4096];sprintf_s (buffer, "%s.zm",mName.c_str());return (const char*)buffer;}
	/*The resulting subdivision surface*/
	SubdivisionSurfaceID getOutSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	SubdivReverseFaces(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVREVERSEFACES_H__
