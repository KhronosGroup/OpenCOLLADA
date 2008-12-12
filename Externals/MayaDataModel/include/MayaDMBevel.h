/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BEVEL_H__
#define __MayaDM_BEVEL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
*/
class Bevel : public AbstractBaseCreate
{
public:
public:
	Bevel(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "bevel"){}
	virtual ~Bevel(){}
	/*The input curve*/
	void setInputCurve(const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Bevel the above input curve in the same direction as this curve.*/
	void setUseDirectionCurve(const NurbsCurveID& udc){fprintf_s(mFile,"connectAttr \"");udc.write(mFile);fprintf_s(mFile,"\" \"%s.udc\";\n",mName.c_str());}
	/*Output surface 1 - the bevel surface with all the pieces joined or the first bevel piece when not joining everything*/
	void setOutputSurface1(const NurbsSurfaceID& os1){fprintf_s(mFile,"connectAttr \"");os1.write(mFile);fprintf_s(mFile,"\" \"%s.os1\";\n",mName.c_str());}
	/*Output surface 2 - the second bevel piece when not joining everything*/
	void setOutputSurface2(const NurbsSurfaceID& os2){fprintf_s(mFile,"connectAttr \"");os2.write(mFile);fprintf_s(mFile,"\" \"%s.os2\";\n",mName.c_str());}
	/*Output surface 3 - the third bevel piece when not joining everything*/
	void setOutputSurface3(const NurbsSurfaceID& os3){fprintf_s(mFile,"connectAttr \"");os3.write(mFile);fprintf_s(mFile,"\" \"%s.os3\";\n",mName.c_str());}
	/*The tolerance for bevel offsets*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*The tolerance for bevel offsets*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*The width for bevel*/
	void setWidth(double w){if(w == 0) return; fprintf_s(mFile, "setAttr \".w\" %f;\n", w);}
	/*The width for bevel*/
	void setWidth(const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*The depth for bevel*/
	void setDepth(double d){if(d == 0) return; fprintf_s(mFile, "setAttr \".d\" %f;\n", d);}
	/*The depth for bevel*/
	void setDepth(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*The extrude depth for bevel*/
	void setExtrudeDepth(double ed){if(ed == 1) return; fprintf_s(mFile, "setAttr \".ed\" %f;\n", ed);}
	/*The extrude depth for bevel*/
	void setExtrudeDepth(const DoubleID& ed){fprintf_s(mFile,"connectAttr \"");ed.write(mFile);fprintf_s(mFile,"\" \"%s.ed\";\n",mName.c_str());}
	/*Corner type: 1 - linear, 2 - circular*/
	void setCornerType(unsigned int ct){if(ct == 2) return; fprintf_s(mFile, "setAttr \".ct\" %i;\n", ct);}
	/*Corner type: 1 - linear, 2 - circular*/
	void setCornerType(const UnsignedintID& ct){fprintf_s(mFile,"connectAttr \"");ct.write(mFile);fprintf_s(mFile,"\" \"%s.ct\";\n",mName.c_str());}
	/*Number of sides to bevel: 1 - no bevel just extrude, 2 - bevel start and extrude, 3 - bevel end and extrude, 4 - bevel end and start and extrude*/
	void setNumberOfSides(int ns){if(ns == 4) return; fprintf_s(mFile, "setAttr \".ns\" %i;\n", ns);}
	/*Number of sides to bevel: 1 - no bevel just extrude, 2 - bevel start and extrude, 3 - bevel end and extrude, 4 - bevel end and start and extrude*/
	void setNumberOfSides(const IntID& ns){fprintf_s(mFile,"connectAttr \"");ns.write(mFile);fprintf_s(mFile,"\" \"%s.ns\";\n",mName.c_str());}
	/*Shape type: 1 - straight cut, 2 - curve out, 3 - curve in*/
	void setBevelShapeType(unsigned int bst){if(bst == 1) return; fprintf_s(mFile, "setAttr \".bst\" %i;\n", bst);}
	/*Shape type: 1 - straight cut, 2 - curve out, 3 - curve in*/
	void setBevelShapeType(const UnsignedintID& bst){fprintf_s(mFile,"connectAttr \"");bst.write(mFile);fprintf_s(mFile,"\" \"%s.bst\";\n",mName.c_str());}
	/*If true, join all the bevel surfaces into one or leave separate if false*/
	void setJoinSurfaces(bool js){if(js == true) return; fprintf_s(mFile, "setAttr \".js\" %i;\n", js);}
	/*If true, join all the bevel surfaces into one or leave separate if false*/
	void setJoinSurfaces(const BoolID& js){fprintf_s(mFile,"connectAttr \"");js.write(mFile);fprintf_s(mFile,"\" \"%s.js\";\n",mName.c_str());}
	/*The input curve*/
	NurbsCurveID getInputCurve(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*Bevel the above input curve in the same direction as this curve.*/
	NurbsCurveID getUseDirectionCurve(){char buffer[4096];sprintf_s (buffer, "%s.udc",mName.c_str());return (const char*)buffer;}
	/*Output surface 1 - the bevel surface with all the pieces joined or the first bevel piece when not joining everything*/
	NurbsSurfaceID getOutputSurface1(){char buffer[4096];sprintf_s (buffer, "%s.os1",mName.c_str());return (const char*)buffer;}
	/*Output surface 2 - the second bevel piece when not joining everything*/
	NurbsSurfaceID getOutputSurface2(){char buffer[4096];sprintf_s (buffer, "%s.os2",mName.c_str());return (const char*)buffer;}
	/*Output surface 3 - the third bevel piece when not joining everything*/
	NurbsSurfaceID getOutputSurface3(){char buffer[4096];sprintf_s (buffer, "%s.os3",mName.c_str());return (const char*)buffer;}
	/*The tolerance for bevel offsets*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*The width for bevel*/
	DoubleID getWidth(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
	/*The depth for bevel*/
	DoubleID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*The extrude depth for bevel*/
	DoubleID getExtrudeDepth(){char buffer[4096];sprintf_s (buffer, "%s.ed",mName.c_str());return (const char*)buffer;}
	/*Corner type: 1 - linear, 2 - circular*/
	UnsignedintID getCornerType(){char buffer[4096];sprintf_s (buffer, "%s.ct",mName.c_str());return (const char*)buffer;}
	/*Number of sides to bevel: 1 - no bevel just extrude, 2 - bevel start and extrude, 3 - bevel end and extrude, 4 - bevel end and start and extrude*/
	IntID getNumberOfSides(){char buffer[4096];sprintf_s (buffer, "%s.ns",mName.c_str());return (const char*)buffer;}
	/*Shape type: 1 - straight cut, 2 - curve out, 3 - curve in*/
	UnsignedintID getBevelShapeType(){char buffer[4096];sprintf_s (buffer, "%s.bst",mName.c_str());return (const char*)buffer;}
	/*If true, join all the bevel surfaces into one or leave separate if false*/
	BoolID getJoinSurfaces(){char buffer[4096];sprintf_s (buffer, "%s.js",mName.c_str());return (const char*)buffer;}
protected:
	Bevel(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BEVEL_H__
