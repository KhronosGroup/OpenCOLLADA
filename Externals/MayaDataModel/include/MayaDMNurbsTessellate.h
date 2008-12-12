/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSTESSELLATE_H__
#define __MayaDM_NURBSTESSELLATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMParentTessellate.h"
namespace MayaDM
{
/*
This node produces a polygon surface based on a NURBS surface and
 several tesselation parameters.  You can choose to produce either
 3-sided polygons or 4-sided polygons with the "polygonType" attribute.
<p/>
<p/>  There are three formats for controlling the output polygon surface:
<p/>
 Triangle Count lets you specify the exact number of resulting polygons
 by using the polygonCount attribute.
<p/>
 Standard Fit lets you fit polygons based on tolerances to the
 NURBS surface.  You can control chordHeightRatio, fractionalTolerance,
 minEdgeLength, and delta.
<p/>
 General lets you control tesselation along the two surface directions,
 while keeping within specified tolerances.  You can control uType,
 uNumber, vType, vNumber, useChordHeight, chordHeight, useChordHeightRatio,
 chordHeightRatio, and edgeSwap.  This type of tessellation first
 generates a polygon surface based on the Type and Number attributes,
 then examines the polygons to determine if they meet the other
 attributes for chord height, chord height ratio and edge swap.
 This is performed recursively until all criteria have been met,
 or a depth of 10 recursions has been reached.
<p/>
<p/>
*/
class NurbsTessellate : public ParentTessellate
{
public:
public:
	NurbsTessellate(FILE* file,const std::string& name,const std::string& parent=""):ParentTessellate(file, name, parent, "nurbsTessellate"){}
	virtual ~NurbsTessellate(){}
	/*The input surface*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*
	Specifies if the decision to continue tessellation should be
	based on the nurbs edge smoothness
	*/
	void setSmoothEdge(bool ues){if(ues == false) return; fprintf_s(mFile, "setAttr \".ues\" %i;\n", ues);}
	/*
	Specifies if the decision to continue tessellation should be
	based on the nurbs edge smoothness
	*/
	void setSmoothEdge(const BoolID& ues){fprintf_s(mFile,"connectAttr \"");ues.write(mFile);fprintf_s(mFile,"\" \"%s.ues\";\n",mName.c_str());}
	/*
	Specifies the edge smooth ratio.  The higher the value, the
	smoother the edge will be.
	*/
	void setSmoothEdgeRatio(double esr){if(esr == 0.99) return; fprintf_s(mFile, "setAttr \".esr\" %f;\n", esr);}
	/*
	Specifies the edge smooth ratio.  The higher the value, the
	smoother the edge will be.
	*/
	void setSmoothEdgeRatio(const DoubleID& esr){fprintf_s(mFile,"connectAttr \"");esr.write(mFile);fprintf_s(mFile,"\" \"%s.esr\";\n",mName.c_str());}
	/*specify advanced or novice mode for tessellation parameters*/
	void setExplicitTessellationAttributes(bool eta){if(eta == true) return; fprintf_s(mFile, "setAttr \".eta\" %i;\n", eta);}
	/*specify advanced or novice mode for tessellation parameters*/
	void setExplicitTessellationAttributes(const BoolID& eta){fprintf_s(mFile,"connectAttr \"");eta.write(mFile);fprintf_s(mFile,"\" \"%s.eta\";\n",mName.c_str());}
	/*Specifies the tessellation increase factor in U for novice mode*/
	void setUDivisionsFactor(double nuf){if(nuf == 1.5) return; fprintf_s(mFile, "setAttr \".nuf\" %f;\n", nuf);}
	/*Specifies the tessellation increase factor in U for novice mode*/
	void setUDivisionsFactor(const DoubleID& nuf){fprintf_s(mFile,"connectAttr \"");nuf.write(mFile);fprintf_s(mFile,"\" \"%s.nuf\";\n",mName.c_str());}
	/*Specifies the tessellation increase factor in V for novice mode*/
	void setVDivisionsFactor(double nvf){if(nvf == 1.5) return; fprintf_s(mFile, "setAttr \".nvf\" %f;\n", nvf);}
	/*Specifies the tessellation increase factor in V for novice mode*/
	void setVDivisionsFactor(const DoubleID& nvf){fprintf_s(mFile,"connectAttr \"");nvf.write(mFile);fprintf_s(mFile,"\" \"%s.nvf\";\n",mName.c_str());}
	/*
	Presets for level of secondary criteria curvature tolerance:
	0 = highest tolerance, 1 = high tolerance, 2 = medium tolerance,
	3 = no tolerance
	*/
	void setCurvatureTolerance(unsigned int cvt){if(cvt == 2) return; fprintf_s(mFile, "setAttr \".cvt\" %i;\n", cvt);}
	/*
	Presets for level of secondary criteria curvature tolerance:
	0 = highest tolerance, 1 = high tolerance, 2 = medium tolerance,
	3 = no tolerance
	*/
	void setCurvatureTolerance(const UnsignedintID& cvt){fprintf_s(mFile,"connectAttr \"");cvt.write(mFile);fprintf_s(mFile,"\" \"%s.cvt\";\n",mName.c_str());}
	/*The input surface*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*
	Specifies if the decision to continue tessellation should be
	based on the nurbs edge smoothness
	*/
	BoolID getSmoothEdge(){char buffer[4096];sprintf_s (buffer, "%s.ues",mName.c_str());return (const char*)buffer;}
	/*
	Specifies the edge smooth ratio.  The higher the value, the
	smoother the edge will be.
	*/
	DoubleID getSmoothEdgeRatio(){char buffer[4096];sprintf_s (buffer, "%s.esr",mName.c_str());return (const char*)buffer;}
	/*specify advanced or novice mode for tessellation parameters*/
	BoolID getExplicitTessellationAttributes(){char buffer[4096];sprintf_s (buffer, "%s.eta",mName.c_str());return (const char*)buffer;}
	/*Specifies the tessellation increase factor in U for novice mode*/
	DoubleID getUDivisionsFactor(){char buffer[4096];sprintf_s (buffer, "%s.nuf",mName.c_str());return (const char*)buffer;}
	/*Specifies the tessellation increase factor in V for novice mode*/
	DoubleID getVDivisionsFactor(){char buffer[4096];sprintf_s (buffer, "%s.nvf",mName.c_str());return (const char*)buffer;}
	/*
	Presets for level of secondary criteria curvature tolerance:
	0 = highest tolerance, 1 = high tolerance, 2 = medium tolerance,
	3 = no tolerance
	*/
	UnsignedintID getCurvatureTolerance(){char buffer[4096];sprintf_s (buffer, "%s.cvt",mName.c_str());return (const char*)buffer;}
protected:
	NurbsTessellate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ParentTessellate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NURBSTESSELLATE_H__
