/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYPOKE_H__
#define __MayaDM_POLYPOKE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
Poke the face(s) a polygonal object.<p/>

 Poke operation introduces a vertex at the center of the
 selected face(s) and connects this vertex with each
 vertex of the selected face(s) by creating new edges.
 .<p/>
*/
class PolyPoke : public PolyModifierWorld
{
public:
public:
	PolyPoke(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyPoke"){}
	virtual ~PolyPoke(){}
	/*Translation vector of the new vertex.*/
	void setTranslate(const double3& t){if(t == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".t\" -type \"double3\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*Translation vector of the new vertex.*/
	void setTranslate(const Double3ID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*Translation X coord.*/
	void setTranslateX(double tx){if(tx == 0) return; fprintf_s(mFile, "setAttr \".t.tx\" %f;\n", tx);}
	/*Translation X coord.*/
	void setTranslateX(const DoubleID& tx){fprintf_s(mFile,"connectAttr \"");tx.write(mFile);fprintf_s(mFile,"\" \"%s.t.tx\";\n",mName.c_str());}
	/*Translation Y coord.*/
	void setTranslateY(double ty){if(ty == 0) return; fprintf_s(mFile, "setAttr \".t.ty\" %f;\n", ty);}
	/*Translation Y coord.*/
	void setTranslateY(const DoubleID& ty){fprintf_s(mFile,"connectAttr \"");ty.write(mFile);fprintf_s(mFile,"\" \"%s.t.ty\";\n",mName.c_str());}
	/*Translation Z coord.*/
	void setTranslateZ(double tz){if(tz == 0) return; fprintf_s(mFile, "setAttr \".t.tz\" %f;\n", tz);}
	/*Translation Z coord.*/
	void setTranslateZ(const DoubleID& tz){fprintf_s(mFile,"connectAttr \"");tz.write(mFile);fprintf_s(mFile,"\" \"%s.t.tz\";\n",mName.c_str());}
	/*Local translate.*/
	void setLocalTranslate(const double3& lt){if(lt == double3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".lt\" -type \"double3\" ");lt.write(mFile);fprintf_s(mFile,";\n");}
	/*Local translate.*/
	void setLocalTranslate(const Double3ID& lt){fprintf_s(mFile,"connectAttr \"");lt.write(mFile);fprintf_s(mFile,"\" \"%s.lt\";\n",mName.c_str());}
	/*Local translation X coord.*/
	void setLocalTranslateX(double ltx){if(ltx == 0) return; fprintf_s(mFile, "setAttr \".lt.ltx\" %f;\n", ltx);}
	/*Local translation X coord.*/
	void setLocalTranslateX(const DoubleID& ltx){fprintf_s(mFile,"connectAttr \"");ltx.write(mFile);fprintf_s(mFile,"\" \"%s.lt.ltx\";\n",mName.c_str());}
	/*Local translation Y coord.*/
	void setLocalTranslateY(double lty){if(lty == 0) return; fprintf_s(mFile, "setAttr \".lt.lty\" %f;\n", lty);}
	/*Local translation Y coord.*/
	void setLocalTranslateY(const DoubleID& lty){fprintf_s(mFile,"connectAttr \"");lty.write(mFile);fprintf_s(mFile,"\" \"%s.lt.lty\";\n",mName.c_str());}
	/*Local translation Z coord : Move along the normal.*/
	void setLocalTranslateZ(double ltz){if(ltz == 0) return; fprintf_s(mFile, "setAttr \".lt.ltz\" %f;\n", ltz);}
	/*Local translation Z coord : Move along the normal.*/
	void setLocalTranslateZ(const DoubleID& ltz){fprintf_s(mFile,"connectAttr \"");ltz.write(mFile);fprintf_s(mFile,"\" \"%s.lt.ltz\";\n",mName.c_str());}
	/*Object to component matrix (for interaction purposes only).*/
	void setMatrix(const MatrixID& cma){fprintf_s(mFile,"connectAttr \"");cma.write(mFile);fprintf_s(mFile,"\" \"%s.cma\";\n",mName.c_str());}
	/*
	Enable Maya 7.0 behaviour.
	This attribute is not meant to be modified through command line.
	*/
	void setMaya70(bool m70){if(m70 == true) return; fprintf_s(mFile, "setAttr \".m70\" %i;\n", m70);}
	/*Translation vector of the new vertex.*/
	Double3ID getTranslate(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*Translation X coord.*/
	DoubleID getTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.t.tx",mName.c_str());return (const char*)buffer;}
	/*Translation Y coord.*/
	DoubleID getTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.t.ty",mName.c_str());return (const char*)buffer;}
	/*Translation Z coord.*/
	DoubleID getTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.t.tz",mName.c_str());return (const char*)buffer;}
	/*Local translate.*/
	Double3ID getLocalTranslate(){char buffer[4096];sprintf_s (buffer, "%s.lt",mName.c_str());return (const char*)buffer;}
	/*Local translation X coord.*/
	DoubleID getLocalTranslateX(){char buffer[4096];sprintf_s (buffer, "%s.lt.ltx",mName.c_str());return (const char*)buffer;}
	/*Local translation Y coord.*/
	DoubleID getLocalTranslateY(){char buffer[4096];sprintf_s (buffer, "%s.lt.lty",mName.c_str());return (const char*)buffer;}
	/*Local translation Z coord : Move along the normal.*/
	DoubleID getLocalTranslateZ(){char buffer[4096];sprintf_s (buffer, "%s.lt.ltz",mName.c_str());return (const char*)buffer;}
	/*Object to component matrix (for interaction purposes only).*/
	MatrixID getMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cma",mName.c_str());return (const char*)buffer;}
protected:
	PolyPoke(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYPOKE_H__
