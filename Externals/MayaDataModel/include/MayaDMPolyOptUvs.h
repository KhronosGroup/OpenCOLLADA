/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYOPTUVS_H__
#define __MayaDM_POLYOPTUVS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
/*
<p><pre> Modifies selected UV.

 Modifies a selected part of the map by moving the selected
 vertices on the flattened representation of the 3D object.
 It works in the same way as move vertex function.
 Instead of references to X, Y and Z, it references to U and V.
 As the selected vertices are adjusted, the way the image is
 mapped onto the object changes accordingly.
 The vertices of the model (mapping) are manipulated without
 actually changing the vertices of the 3D object.
</pre></p>
*/
class PolyOptUvs : public PolyModifierUV
{
public:
public:
	PolyOptUvs(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyOptUvs"){}
	virtual ~PolyOptUvs(){}
	/*Maximum number of iterations for each connected UV piece.*/
	void setIterations(int i){if(i == 100) return; fprintf_s(mFile, "setAttr \".i\" %i;\n", i);}
	/*Maximum number of iterations for each connected UV piece.*/
	void setIterations(const IntID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Minimum distorsion improvment between two steps in %.*/
	void setStoppingThreshold(float ss){if(ss == .001) return; fprintf_s(mFile, "setAttr \".ss\" %f;\n", ss);}
	/*Minimum distorsion improvment between two steps in %.*/
	void setStoppingThreshold(const FloatID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*Surface driven importance: 0 treat all faces equal. 1 gives more importance to large ones.*/
	void setAreaWeight(float aw){if(aw == 1.) return; fprintf_s(mFile, "setAttr \".aw\" %f;\n", aw);}
	/*Surface driven importance: 0 treat all faces equal. 1 gives more importance to large ones.*/
	void setAreaWeight(const FloatID& aw){fprintf_s(mFile,"connectAttr \"");aw.write(mFile);fprintf_s(mFile,"\" \"%s.aw\";\n",mName.c_str());}
	/*Adjust the scale or not.*/
	void setUseScale(bool us){if(us == false) return; fprintf_s(mFile, "setAttr \".us\" %i;\n", us);}
	/*Adjust the scale or not.*/
	void setUseScale(const BoolID& us){fprintf_s(mFile,"connectAttr \"");us.write(mFile);fprintf_s(mFile,"\" \"%s.us\";\n",mName.c_str());}
	/*Ratio between 2d and 3d space.*/
	void setScale(float s){if(s == 1.) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*Ratio between 2d and 3d space.*/
	void setScale(const FloatID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	Specifies that the UV border should be pinned when doing the solve.
	by default only unselected components are pinned.
	*/
	void setPinUvBorder(bool pub){if(pub == 0) return; fprintf_s(mFile, "setAttr \".pub\" %i;\n", pub);}
	/*
	Specifies that the UV border should be pinned when doing the solve.
	by default only unselected components are pinned.
	*/
	void setPinUvBorder(const BoolID& pub){fprintf_s(mFile,"connectAttr \"");pub.write(mFile);fprintf_s(mFile,"\" \"%s.pub\";\n",mName.c_str());}
	/*
	Specifies that the selected components should be pinned instead
	of the unselected components.
	*/
	void setPinSelected(bool ps){if(ps == 0) return; fprintf_s(mFile, "setAttr \".ps\" %i;\n", ps);}
	/*
	Specifies that the selected components should be pinned instead
	of the unselected components.
	*/
	void setPinSelected(const BoolID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*
	Specifies where the whole object or just shells that are selected
	or pinned should be affected.
	*/
	void setApplyToShell(bool as){if(as == 0) return; fprintf_s(mFile, "setAttr \".as\" %i;\n", as);}
	/*
	Specifies where the whole object or just shells that are selected
	or pinned should be affected.
	*/
	void setApplyToShell(const BoolID& as){fprintf_s(mFile,"connectAttr \"");as.write(mFile);fprintf_s(mFile,"\" \"%s.as\";\n",mName.c_str());}
	/*
	Degree of freedom for optimization
	0=Optimize freely, 1=Move vertically only, 2=Move horzontally only
	*/
	void setOptimizeAxis(unsigned int oa){if(oa == 0) return; fprintf_s(mFile, "setAttr \".oa\" %i;\n", oa);}
	/*
	Degree of freedom for optimization
	0=Optimize freely, 1=Move vertically only, 2=Move horzontally only
	*/
	void setOptimizeAxis(const UnsignedintID& oa){fprintf_s(mFile,"connectAttr \"");oa.write(mFile);fprintf_s(mFile,"\" \"%s.oa\";\n",mName.c_str());}
	/*
	This allows the user to blend between a local optimization method
	(globalBlend = 0.0) and a global optimization method
	(globalBlend = 1.0). The local optimization method looks at the
	ratio between the triangles on the object and the triangles in UV
	space.  It has a side affect that it can sometimes introduce tapering
	problems.  The global optimization is much slower, but takes into
	consideration the entire object when optimizing uv placement.
	*/
	void setGlobalBlend(float gb){if(gb == 0.0) return; fprintf_s(mFile, "setAttr \".gb\" %f;\n", gb);}
	/*
	This allows the user to blend between a local optimization method
	(globalBlend = 0.0) and a global optimization method
	(globalBlend = 1.0). The local optimization method looks at the
	ratio between the triangles on the object and the triangles in UV
	space.  It has a side affect that it can sometimes introduce tapering
	problems.  The global optimization is much slower, but takes into
	consideration the entire object when optimizing uv placement.
	*/
	void setGlobalBlend(const FloatID& gb){fprintf_s(mFile,"connectAttr \"");gb.write(mFile);fprintf_s(mFile,"\" \"%s.gb\";\n",mName.c_str());}
	/*
	The global optimization method uses two functions to compute
	a minimization.  The first function controls edge
	stretch by using edges lengths between xyz and uv.  The second
	function penalizes the first function by preventing
	configurations where triangles would overlap.  For every surface
	there is a mix between these two functions that will give the
	appropriate response. Values closer to 1.0 give more weight to
	the edge length function. Values closer to 0.0 give more weight to
	surface area.  The default value of '0.5' is a even mix
	between these two values.
	*/
	void setGlobalMethodBlend(float gmb){if(gmb == 0.5) return; fprintf_s(mFile, "setAttr \".gmb\" %f;\n", gmb);}
	/*
	The global optimization method uses two functions to compute
	a minimization.  The first function controls edge
	stretch by using edges lengths between xyz and uv.  The second
	function penalizes the first function by preventing
	configurations where triangles would overlap.  For every surface
	there is a mix between these two functions that will give the
	appropriate response. Values closer to 1.0 give more weight to
	the edge length function. Values closer to 0.0 give more weight to
	surface area.  The default value of '0.5' is a even mix
	between these two values.
	*/
	void setGlobalMethodBlend(const FloatID& gmb){fprintf_s(mFile,"connectAttr \"");gmb.write(mFile);fprintf_s(mFile,"\" \"%s.gmb\";\n",mName.c_str());}
	/*Maximum number of iterations for each connected UV piece.*/
	IntID getIterations(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Minimum distorsion improvment between two steps in %.*/
	FloatID getStoppingThreshold(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*Surface driven importance: 0 treat all faces equal. 1 gives more importance to large ones.*/
	FloatID getAreaWeight(){char buffer[4096];sprintf_s (buffer, "%s.aw",mName.c_str());return (const char*)buffer;}
	/*Adjust the scale or not.*/
	BoolID getUseScale(){char buffer[4096];sprintf_s (buffer, "%s.us",mName.c_str());return (const char*)buffer;}
	/*Ratio between 2d and 3d space.*/
	FloatID getScale(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	Specifies that the UV border should be pinned when doing the solve.
	by default only unselected components are pinned.
	*/
	BoolID getPinUvBorder(){char buffer[4096];sprintf_s (buffer, "%s.pub",mName.c_str());return (const char*)buffer;}
	/*
	Specifies that the selected components should be pinned instead
	of the unselected components.
	*/
	BoolID getPinSelected(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*
	Specifies where the whole object or just shells that are selected
	or pinned should be affected.
	*/
	BoolID getApplyToShell(){char buffer[4096];sprintf_s (buffer, "%s.as",mName.c_str());return (const char*)buffer;}
	/*
	Degree of freedom for optimization
	0=Optimize freely, 1=Move vertically only, 2=Move horzontally only
	*/
	UnsignedintID getOptimizeAxis(){char buffer[4096];sprintf_s (buffer, "%s.oa",mName.c_str());return (const char*)buffer;}
	/*
	This allows the user to blend between a local optimization method
	(globalBlend = 0.0) and a global optimization method
	(globalBlend = 1.0). The local optimization method looks at the
	ratio between the triangles on the object and the triangles in UV
	space.  It has a side affect that it can sometimes introduce tapering
	problems.  The global optimization is much slower, but takes into
	consideration the entire object when optimizing uv placement.
	*/
	FloatID getGlobalBlend(){char buffer[4096];sprintf_s (buffer, "%s.gb",mName.c_str());return (const char*)buffer;}
	/*
	The global optimization method uses two functions to compute
	a minimization.  The first function controls edge
	stretch by using edges lengths between xyz and uv.  The second
	function penalizes the first function by preventing
	configurations where triangles would overlap.  For every surface
	there is a mix between these two functions that will give the
	appropriate response. Values closer to 1.0 give more weight to
	the edge length function. Values closer to 0.0 give more weight to
	surface area.  The default value of '0.5' is a even mix
	between these two values.
	*/
	FloatID getGlobalMethodBlend(){char buffer[4096];sprintf_s (buffer, "%s.gmb",mName.c_str());return (const char*)buffer;}
protected:
	PolyOptUvs(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYOPTUVS_H__
