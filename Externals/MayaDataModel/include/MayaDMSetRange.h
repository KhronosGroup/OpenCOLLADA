/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SETRANGE_H__
#define __MayaDM_SETRANGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Set Range</b> is a utility node that allows you to take
 values in one range, and map them into another range.
 <p/>
 <b>For example:</b>  Say you have an rotation attribute whose value goes from
 0 to 360.  You want to use this attribute to drive a color
 value, which goes from 0 to 1.
 <p/>
 To do this:<p/><ul> Set the Old Min and Old Max attributes to the range
 the the incoming attribute has, in this case 0 to 360.
 <p/>
 Set the Min and Max attributes to the desired range, in this
 case 0 to 1.
 <p/>
 Connect your rotation attribute to the Value attribute.
 <p/>
 Once that is done, the Out Value attribute of this node will provide
 you with numbers between 0 and 1, that you can use for your color.
</ul>
<p/>
 The input of Set Range is a triple value, so you can use it for
 vectors, or colors.  If you want to set the range for single values,
 just use one of the X, Y, or Z channels.
<p/>
 Here is the mathematical calculation done by this node:
<ul>
 OutValue = Min + (((Value-OldMin)/(OldMax-OldMin)) * (Max-Min))
</ul>
<p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class SetRange : public DependNode
{
public:
public:
	SetRange(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "setRange"){}
	virtual ~SetRange(){}
	/*
	<b>Value</b>.  This value will be mapped from the old
	range (Old Min to Old Max) into the new range (Min to Max).
	*/
	void setValue(const float3& v){if(v == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".v\" -type \"float3\" ");v.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Value</b>.  This value will be mapped from the old
	range (Old Min to Old Max) into the new range (Min to Max).
	*/
	void setValue(const Float3ID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*Input Value X component*/
	void setValueX(float vx){if(vx == 0.0) return; fprintf_s(mFile, "setAttr \".v.vx\" %f;\n", vx);}
	/*Input Value X component*/
	void setValueX(const FloatID& vx){fprintf_s(mFile,"connectAttr \"");vx.write(mFile);fprintf_s(mFile,"\" \"%s.v.vx\";\n",mName.c_str());}
	/*Input Value Y component*/
	void setValueY(float vy){if(vy == 0.0) return; fprintf_s(mFile, "setAttr \".v.vy\" %f;\n", vy);}
	/*Input Value Y component*/
	void setValueY(const FloatID& vy){fprintf_s(mFile,"connectAttr \"");vy.write(mFile);fprintf_s(mFile,"\" \"%s.v.vy\";\n",mName.c_str());}
	/*Input Value Z component*/
	void setValueZ(float vz){if(vz == 0.0) return; fprintf_s(mFile, "setAttr \".v.vz\" %f;\n", vz);}
	/*Input Value Z component*/
	void setValueZ(const FloatID& vz){fprintf_s(mFile,"connectAttr \"");vz.write(mFile);fprintf_s(mFile,"\" \"%s.v.vz\";\n",mName.c_str());}
	/*<b>Min</b> is the minimum value in the new range.*/
	void setMin(const float3& n){if(n == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".n\" -type \"float3\" ");n.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Min</b> is the minimum value in the new range.*/
	void setMin(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*Min value X component*/
	void setMinX(float nx){if(nx == 0.0) return; fprintf_s(mFile, "setAttr \".n.nx\" %f;\n", nx);}
	/*Min value X component*/
	void setMinX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*Min value Y component*/
	void setMinY(float ny){if(ny == 0.0) return; fprintf_s(mFile, "setAttr \".n.ny\" %f;\n", ny);}
	/*Min value Y component*/
	void setMinY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*Min value Z component*/
	void setMinZ(float nz){if(nz == 0.0) return; fprintf_s(mFile, "setAttr \".n.nz\" %f;\n", nz);}
	/*Min value Z component*/
	void setMinZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*<b>Max</b> is the maximum value in the new range.*/
	void setMax(const float3& m){if(m == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".m\" -type \"float3\" ");m.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Max</b> is the maximum value in the new range.*/
	void setMax(const Float3ID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*Max value X component*/
	void setMaxX(float mx){if(mx == 0.0) return; fprintf_s(mFile, "setAttr \".m.mx\" %f;\n", mx);}
	/*Max value X component*/
	void setMaxX(const FloatID& mx){fprintf_s(mFile,"connectAttr \"");mx.write(mFile);fprintf_s(mFile,"\" \"%s.m.mx\";\n",mName.c_str());}
	/*Max value Y component*/
	void setMaxY(float my){if(my == 0.0) return; fprintf_s(mFile, "setAttr \".m.my\" %f;\n", my);}
	/*Max value Y component*/
	void setMaxY(const FloatID& my){fprintf_s(mFile,"connectAttr \"");my.write(mFile);fprintf_s(mFile,"\" \"%s.m.my\";\n",mName.c_str());}
	/*Max value Z component*/
	void setMaxZ(float mz){if(mz == 0.0) return; fprintf_s(mFile, "setAttr \".m.mz\" %f;\n", mz);}
	/*Max value Z component*/
	void setMaxZ(const FloatID& mz){fprintf_s(mFile,"connectAttr \"");mz.write(mFile);fprintf_s(mFile,"\" \"%s.m.mz\";\n",mName.c_str());}
	/*<b>Old Min</b> is the minimum value in old range.*/
	void setOldMin(const float3& on){if(on == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".on\" -type \"float3\" ");on.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Old Min</b> is the minimum value in old range.*/
	void setOldMin(const Float3ID& on){fprintf_s(mFile,"connectAttr \"");on.write(mFile);fprintf_s(mFile,"\" \"%s.on\";\n",mName.c_str());}
	/*Old Min X component*/
	void setOldMinX(float onx){if(onx == 0.0) return; fprintf_s(mFile, "setAttr \".on.onx\" %f;\n", onx);}
	/*Old Min X component*/
	void setOldMinX(const FloatID& onx){fprintf_s(mFile,"connectAttr \"");onx.write(mFile);fprintf_s(mFile,"\" \"%s.on.onx\";\n",mName.c_str());}
	/*Old Min Y component*/
	void setOldMinY(float ony){if(ony == 0.0) return; fprintf_s(mFile, "setAttr \".on.ony\" %f;\n", ony);}
	/*Old Min Y component*/
	void setOldMinY(const FloatID& ony){fprintf_s(mFile,"connectAttr \"");ony.write(mFile);fprintf_s(mFile,"\" \"%s.on.ony\";\n",mName.c_str());}
	/*Old Min Z component*/
	void setOldMinZ(float onz){if(onz == 0.0) return; fprintf_s(mFile, "setAttr \".on.onz\" %f;\n", onz);}
	/*Old Min Z component*/
	void setOldMinZ(const FloatID& onz){fprintf_s(mFile,"connectAttr \"");onz.write(mFile);fprintf_s(mFile,"\" \"%s.on.onz\";\n",mName.c_str());}
	/*<b>Old Max</b> is the maximum value in old range.*/
	void setOldMax(const float3& om){if(om == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".om\" -type \"float3\" ");om.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Old Max</b> is the maximum value in old range.*/
	void setOldMax(const Float3ID& om){fprintf_s(mFile,"connectAttr \"");om.write(mFile);fprintf_s(mFile,"\" \"%s.om\";\n",mName.c_str());}
	/*Old Max X component*/
	void setOldMaxX(float omx){if(omx == 0.0) return; fprintf_s(mFile, "setAttr \".om.omx\" %f;\n", omx);}
	/*Old Max X component*/
	void setOldMaxX(const FloatID& omx){fprintf_s(mFile,"connectAttr \"");omx.write(mFile);fprintf_s(mFile,"\" \"%s.om.omx\";\n",mName.c_str());}
	/*Old Max Y component*/
	void setOldMaxY(float omy){if(omy == 0.0) return; fprintf_s(mFile, "setAttr \".om.omy\" %f;\n", omy);}
	/*Old Max Y component*/
	void setOldMaxY(const FloatID& omy){fprintf_s(mFile,"connectAttr \"");omy.write(mFile);fprintf_s(mFile,"\" \"%s.om.omy\";\n",mName.c_str());}
	/*Old Max Z component*/
	void setOldMaxZ(float omz){if(omz == 0.0) return; fprintf_s(mFile, "setAttr \".om.omz\" %f;\n", omz);}
	/*Old Max Z component*/
	void setOldMaxZ(const FloatID& omz){fprintf_s(mFile,"connectAttr \"");omz.write(mFile);fprintf_s(mFile,"\" \"%s.om.omz\";\n",mName.c_str());}
	/*<b>Out Value</b>.  This is the new calculated value.*/
	void setOutValue(const Float3ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Output Value X component*/
	void setOutValueX(const FloatID& ox){fprintf_s(mFile,"connectAttr \"");ox.write(mFile);fprintf_s(mFile,"\" \"%s.o.ox\";\n",mName.c_str());}
	/*Output Value Y component*/
	void setOutValueY(const FloatID& oy){fprintf_s(mFile,"connectAttr \"");oy.write(mFile);fprintf_s(mFile,"\" \"%s.o.oy\";\n",mName.c_str());}
	/*Output Value Z component*/
	void setOutValueZ(const FloatID& oz){fprintf_s(mFile,"connectAttr \"");oz.write(mFile);fprintf_s(mFile,"\" \"%s.o.oz\";\n",mName.c_str());}
	/*
	<b>Value</b>.  This value will be mapped from the old
	range (Old Min to Old Max) into the new range (Min to Max).
	*/
	Float3ID getValue(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*Input Value X component*/
	FloatID getValueX(){char buffer[4096];sprintf_s (buffer, "%s.v.vx",mName.c_str());return (const char*)buffer;}
	/*Input Value Y component*/
	FloatID getValueY(){char buffer[4096];sprintf_s (buffer, "%s.v.vy",mName.c_str());return (const char*)buffer;}
	/*Input Value Z component*/
	FloatID getValueZ(){char buffer[4096];sprintf_s (buffer, "%s.v.vz",mName.c_str());return (const char*)buffer;}
	/*<b>Min</b> is the minimum value in the new range.*/
	Float3ID getMin(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*Min value X component*/
	FloatID getMinX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*Min value Y component*/
	FloatID getMinY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*Min value Z component*/
	FloatID getMinZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*<b>Max</b> is the maximum value in the new range.*/
	Float3ID getMax(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*Max value X component*/
	FloatID getMaxX(){char buffer[4096];sprintf_s (buffer, "%s.m.mx",mName.c_str());return (const char*)buffer;}
	/*Max value Y component*/
	FloatID getMaxY(){char buffer[4096];sprintf_s (buffer, "%s.m.my",mName.c_str());return (const char*)buffer;}
	/*Max value Z component*/
	FloatID getMaxZ(){char buffer[4096];sprintf_s (buffer, "%s.m.mz",mName.c_str());return (const char*)buffer;}
	/*<b>Old Min</b> is the minimum value in old range.*/
	Float3ID getOldMin(){char buffer[4096];sprintf_s (buffer, "%s.on",mName.c_str());return (const char*)buffer;}
	/*Old Min X component*/
	FloatID getOldMinX(){char buffer[4096];sprintf_s (buffer, "%s.on.onx",mName.c_str());return (const char*)buffer;}
	/*Old Min Y component*/
	FloatID getOldMinY(){char buffer[4096];sprintf_s (buffer, "%s.on.ony",mName.c_str());return (const char*)buffer;}
	/*Old Min Z component*/
	FloatID getOldMinZ(){char buffer[4096];sprintf_s (buffer, "%s.on.onz",mName.c_str());return (const char*)buffer;}
	/*<b>Old Max</b> is the maximum value in old range.*/
	Float3ID getOldMax(){char buffer[4096];sprintf_s (buffer, "%s.om",mName.c_str());return (const char*)buffer;}
	/*Old Max X component*/
	FloatID getOldMaxX(){char buffer[4096];sprintf_s (buffer, "%s.om.omx",mName.c_str());return (const char*)buffer;}
	/*Old Max Y component*/
	FloatID getOldMaxY(){char buffer[4096];sprintf_s (buffer, "%s.om.omy",mName.c_str());return (const char*)buffer;}
	/*Old Max Z component*/
	FloatID getOldMaxZ(){char buffer[4096];sprintf_s (buffer, "%s.om.omz",mName.c_str());return (const char*)buffer;}
	/*<b>Out Value</b>.  This is the new calculated value.*/
	Float3ID getOutValue(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*Output Value X component*/
	FloatID getOutValueX(){char buffer[4096];sprintf_s (buffer, "%s.o.ox",mName.c_str());return (const char*)buffer;}
	/*Output Value Y component*/
	FloatID getOutValueY(){char buffer[4096];sprintf_s (buffer, "%s.o.oy",mName.c_str());return (const char*)buffer;}
	/*Output Value Z component*/
	FloatID getOutValueZ(){char buffer[4096];sprintf_s (buffer, "%s.o.oz",mName.c_str());return (const char*)buffer;}
protected:
	SetRange(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SETRANGE_H__
