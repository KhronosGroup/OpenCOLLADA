/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHELLTESSELLATE_H__
#define __MayaDM_SHELLTESSELLATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMParentTessellate.h"
namespace MayaDM
{
/*
This node produces a polygon surface based on a NURBS shell and
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
class ShellTessellate : public ParentTessellate
{
public:
public:
	ShellTessellate(FILE* file,const std::string& name,const std::string& parent=""):ParentTessellate(file, name, parent, "shellTessellate"){}
	virtual ~ShellTessellate(){}
	/*The input shell*/
	void setInputShell(const NurbsShellID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*The input shell*/
	NurbsShellID getInputShell(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
protected:
	ShellTessellate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):ParentTessellate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SHELLTESSELLATE_H__
