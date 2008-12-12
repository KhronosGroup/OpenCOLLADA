/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LATTICE_H__
#define __MayaDM_LATTICE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMControlPoint.h"
namespace MayaDM
{
/*
This node represents a deformed freeform deformation (FFD) lattice.
The lattice is composed of a 3-d grid of points of dimensions s by t by u.
When the lattice is selected, a RGB axis is drawn at its origin to
indicate the (s,t,u) axis directions.
*/
class Lattice : public ControlPoint
{
public:
public:
	Lattice(FILE* file,const std::string& name,const std::string& parent=""):ControlPoint(file, name, parent, "lattice"){}
	virtual ~Lattice(){}
	/*Number of divisions along the s axis.*/
	void setSDivisions(short sd){if(sd == 2) return; fprintf_s(mFile, "setAttr \".sd\" %i;\n", sd);}
	/*Number of divisions along the t axis.*/
	void setTDivisions(short td){if(td == 5) return; fprintf_s(mFile, "setAttr \".td\" %i;\n", td);}
	/*Number of divisions along the u axis.*/
	void setUDivisions(short ud){if(ud == 2) return; fprintf_s(mFile, "setAttr \".ud\" %i;\n", ud);}
	/*The output deformed lattice shape in local space.*/
	void setLatticeOutput(const LatticeID& lo){fprintf_s(mFile,"connectAttr \"");lo.write(mFile);fprintf_s(mFile,"\" \"%s.lo\";\n",mName.c_str());}
	/*The output deformed lattice shape in world space.*/
	void setWorldLattice(size_t wl_i,const LatticeID& wl){fprintf_s(mFile,"connectAttr \"");wl.write(mFile);fprintf_s(mFile,"\" \"%s.wl[%i]\";\n",mName.c_str(),wl_i);}
	/*
	Used to connect any construction history for the deformed lattice.
	One example of this is when a lattice is created by the flow operation.
	*/
	void setLatticeInput(const LatticeID& li){fprintf_s(mFile,"connectAttr \"");li.write(mFile);fprintf_s(mFile,"\" \"%s.li\";\n",mName.c_str());}
	/*Used to store tweaked lattice point coordinates.*/
	void setCached(const lattice& cc){fprintf_s(mFile, "setAttr \".cc\" -type \"lattice\" ");cc.write(mFile);fprintf_s(mFile,";\n");}
	/*Used to store tweaked lattice point coordinates.*/
	void setCached(const LatticeID& cc){fprintf_s(mFile,"connectAttr \"");cc.write(mFile);fprintf_s(mFile,"\" \"%s.cc\";\n",mName.c_str());}
	/*
	Internal attribute used to set lattice and world lattice dirty
	without side effects.
	*/
	void setLatticePointMoved(const MessageID& lpm){fprintf_s(mFile,"connectAttr \"");lpm.write(mFile);fprintf_s(mFile,"\" \"%s.lpm\";\n",mName.c_str());}
	/*
	This attribute is connected to the associated node that controls
	whether this lattice should be displayed.
	Used when Display->Object Components->Lattice Shape is toggled off
	to enable display of this lattice when the associated node is selected.
	*/
	void setDisplayControl(const MessageID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Controls whether the points of this lattice are displayed or not.*/
	void setDispPoints(bool dcv){if(dcv == off) return; fprintf_s(mFile, "setAttr \".dcv\" %i;\n", dcv);}
	/*Controls whether the points of this lattice are displayed or not.*/
	void setDispPoints(const BoolID& dcv){fprintf_s(mFile,"connectAttr \"");dcv.write(mFile);fprintf_s(mFile,"\" \"%s.dcv\";\n",mName.c_str());}
	/*Controls whether this lattice is displayed.*/
	void setDispLattice(bool dep){if(dep == on) return; fprintf_s(mFile, "setAttr \".dep\" %i;\n", dep);}
	/*Controls whether this lattice is displayed.*/
	void setDispLattice(const BoolID& dep){fprintf_s(mFile,"connectAttr \"");dep.write(mFile);fprintf_s(mFile,"\" \"%s.dep\";\n",mName.c_str());}
	/*The location in local space of the displayed 'L' icon.*/
	void setOrigin(const double3& or){fprintf_s(mFile, "setAttr \".or\" -type \"double3\" ");or.write(mFile);fprintf_s(mFile,";\n");}
	/*The location in local space of the displayed 'L' icon.*/
	void setOrigin(const Double3ID& or){fprintf_s(mFile,"connectAttr \"");or.write(mFile);fprintf_s(mFile,"\" \"%s.or\";\n",mName.c_str());}
	/*X position of the displayed 'L' icon.*/
	void setOriginX(double ox){if(ox == 0) return; fprintf_s(mFile, "setAttr \".or.ox\" %f;\n", ox);}
	/*X position of the displayed 'L' icon.*/
	void setOriginX(const DoubleID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.or.ox\";\n",mName.c_str());}
	/*Y position of the displayed 'L' icon.*/
	void setOriginY(double oy){if(oy == 0) return; fprintf_s(mFile, "setAttr \".or.oy\" %f;\n", oy);}
	/*Y position of the displayed 'L' icon.*/
	void setOriginY(const DoubleID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.or.oy\";\n",mName.c_str());}
	/*Z position of the displayed 'L' icon.*/
	void setOriginZ(double oz){if(oz == 0) return; fprintf_s(mFile, "setAttr \".or.oz\" %f;\n", oz);}
	/*Z position of the displayed 'L' icon.*/
	void setOriginZ(const DoubleID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.or.oz\";\n",mName.c_str());}
	/*The output deformed lattice shape in local space.*/
	LatticeID getLatticeOutput(){char buffer[4096];sprintf_s (buffer, "%s.lo",mName.c_str());return (const char*)buffer;}
	/*The output deformed lattice shape in world space.*/
	const LatticeID& getWorldLattice(size_t wl_i){char buffer[4096];sprintf_s (buffer, "%s.wl[%i]",mName.c_str(),wl_i);return (const char*)buffer;}
	/*
	Used to connect any construction history for the deformed lattice.
	One example of this is when a lattice is created by the flow operation.
	*/
	LatticeID getLatticeInput(){char buffer[4096];sprintf_s (buffer, "%s.li",mName.c_str());return (const char*)buffer;}
	/*Used to store tweaked lattice point coordinates.*/
	LatticeID getCached(){char buffer[4096];sprintf_s (buffer, "%s.cc",mName.c_str());return (const char*)buffer;}
	/*
	Internal attribute used to set lattice and world lattice dirty
	without side effects.
	*/
	MessageID getLatticePointMoved(){char buffer[4096];sprintf_s (buffer, "%s.lpm",mName.c_str());return (const char*)buffer;}
	/*
	This attribute is connected to the associated node that controls
	whether this lattice should be displayed.
	Used when Display->Object Components->Lattice Shape is toggled off
	to enable display of this lattice when the associated node is selected.
	*/
	MessageID getDisplayControl(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*Controls whether the points of this lattice are displayed or not.*/
	BoolID getDispPoints(){char buffer[4096];sprintf_s (buffer, "%s.dcv",mName.c_str());return (const char*)buffer;}
	/*Controls whether this lattice is displayed.*/
	BoolID getDispLattice(){char buffer[4096];sprintf_s (buffer, "%s.dep",mName.c_str());return (const char*)buffer;}
	/*The location in local space of the displayed 'L' icon.*/
	Double3ID getOrigin(){char buffer[4096];sprintf_s (buffer, "%s.or",mName.c_str());return (const char*)buffer;}
	/*X position of the displayed 'L' icon.*/
	DoubleID getOriginX(){char buffer[4096];sprintf_s (buffer, "%s.or.ox",mName.c_str());return (const char*)buffer;}
	/*Y position of the displayed 'L' icon.*/
	DoubleID getOriginY(){char buffer[4096];sprintf_s (buffer, "%s.or.oy",mName.c_str());return (const char*)buffer;}
	/*Z position of the displayed 'L' icon.*/
	DoubleID getOriginZ(){char buffer[4096];sprintf_s (buffer, "%s.or.oz",mName.c_str());return (const char*)buffer;}
protected:
	Lattice(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ControlPoint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LATTICE_H__
