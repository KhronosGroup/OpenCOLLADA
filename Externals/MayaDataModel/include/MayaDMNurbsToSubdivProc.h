/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSTOSUBDIVPROC_H__
#define __MayaDM_NURBSTOSUBDIVPROC_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMNurbsToSubdiv.h"
namespace MayaDM
{
/*
This node produces a subdivision surface based on a NURBS surface.

 It will additionally "thicken" the open or closed surfaces or
 cap closed surfaces, depending on the "solidType" specified.
*/
class NurbsToSubdivProc : public NurbsToSubdiv
{
public:
public:
	NurbsToSubdivProc(FILE* file,const std::string& name,const std::string& parent=""):NurbsToSubdiv(file, name, parent, "nurbsToSubdivProc"){}
	virtual ~NurbsToSubdivProc(){}
	/*Solid type (do not-0, transform-1, or offset-2)*/
	void setSolidType(unsigned int st){if(st == 2) return; fprintf_s(mFile, "setAttr \".st\" %i;\n", st);}
	/*Solid type (do not-0, transform-1, or offset-2)*/
	void setSolidType(const UnsignedintID& st){fprintf_s(mFile,"connectAttr \"");st.write(mFile);fprintf_s(mFile,"\" \"%s.st\";\n",mName.c_str());}
	/*Cap (0) or stitch (1)*/
	void setCapType(unsigned int ct){if(ct == 0) return; fprintf_s(mFile, "setAttr \".ct\" %i;\n", ct);}
	/*Cap (0) or stitch (1)*/
	void setCapType(const UnsignedintID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*Apply this transform to converted surface*/
	void setTransform(const matrix& t){if(t == identity) return; fprintf_s(mFile, "setAttr \".t\" -type \"matrix\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*Apply this transform to converted surface*/
	void setTransform(const MatrixID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*
	The distance to offset when making into solid
	Use only for solidType 2
	*/
	void setOffset(double o){if(o == 1) return; fprintf_s(mFile, "setAttr \".o\" %f;\n", o);}
	/*
	The distance to offset when making into solid
	Use only for solidType 2
	*/
	void setOffset(const DoubleID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*No bridge (0), bridge in U (1), in V (2) or both (3).  Only used when capType is 0*/
	void setBridge(unsigned int br){if(br == 0) return; fprintf_s(mFile, "setAttr \".br\" %i;\n", br);}
	/*No bridge (0), bridge in U (1), in V (2) or both (3).  Only used when capType is 0*/
	void setBridge(const UnsignedintID& br){fprintf_s(mFile,"connectAttr \"");br.write(mFile);fprintf_s(mFile,"\" \"%s.br\";\n",mName.c_str());}
	/*Use for closing the open surface in U if we are capping and if bridge option is set to 1 or 3.*/
	void setBridgeInU(const NurbsCurveID& biu){fprintf_s(mFile,"connectAttr \"");biu.write(mFile);fprintf_s(mFile,"\" \"%s.biu\";\n",mName.c_str());}
	/*Use for closing the open surface in V if we are capping and if bridge option is set to 2 or 3.*/
	void setBridgeInV(const NurbsCurveID& biv){fprintf_s(mFile,"connectAttr \"");biv.write(mFile);fprintf_s(mFile,"\" \"%s.biv\";\n",mName.c_str());}
	/*Solid type (do not-0, transform-1, or offset-2)*/
	UnsignedintID getSolidType(){char buffer[4096];sprintf_s (buffer, "%s.st",mName.c_str());return (const char*)buffer;}
	/*Cap (0) or stitch (1)*/
	UnsignedintID getCapType(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*Apply this transform to converted surface*/
	MatrixID getTransform(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*
	The distance to offset when making into solid
	Use only for solidType 2
	*/
	DoubleID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*No bridge (0), bridge in U (1), in V (2) or both (3).  Only used when capType is 0*/
	UnsignedintID getBridge(){char buffer[4096];sprintf_s (buffer, "%s.br",mName.c_str());return (const char*)buffer;}
	/*Use for closing the open surface in U if we are capping and if bridge option is set to 1 or 3.*/
	NurbsCurveID getBridgeInU(){char buffer[4096];sprintf_s (buffer, "%s.biu",mName.c_str());return (const char*)buffer;}
	/*Use for closing the open surface in V if we are capping and if bridge option is set to 2 or 3.*/
	NurbsCurveID getBridgeInV(){char buffer[4096];sprintf_s (buffer, "%s.biv",mName.c_str());return (const char*)buffer;}
protected:
	NurbsToSubdivProc(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):NurbsToSubdiv(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NURBSTOSUBDIVPROC_H__
