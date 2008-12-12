/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_INSTANCER_H__
#define __MayaDM_INSTANCER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
<p><pre>
    This class describes the instancer node.  It takes a set
 of point data (including positions, rotations, scales, etc.)
 and instances hierarchies to that point data.

</pre></p>
*/
class Instancer : public Transform
{
public:
public:
	Instancer(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "instancer"){}
	virtual ~Instancer(){}
	/*
	This is where the point data is connected.  The point data
	can only be coming from one source.  There is nothing
	keeping the user from having an API node take several
	inputs and combining them into a single point data
	attribute, however.
	*/
	void setInputPoints(const GenericArrayID& inp){fprintf_s(mFile,"connectAttr \"");inp.write(mFile);fprintf_s(mFile,"\" \"%s.inp\";\n",mName.c_str());}
	/*
	This attribute tells the instancer what order to do the
	rotations in for each point if and only if the rotation
	type is set to "Rotation" for that particular point.  When
	either "aimDirection" or "aimPosition" are used, then the
	rotation order does not matter.
	*/
	void setRotationOrder(unsigned int ror){if(ror == 0) return; fprintf_s(mFile, "setAttr \".ror\" %i;\n", ror);}
	/*
	This attribute tells the instancer what order to do the
	rotations in for each point if and only if the rotation
	type is set to "Rotation" for that particular point.  When
	either "aimDirection" or "aimPosition" are used, then the
	rotation order does not matter.
	*/
	void setRotationOrder(const UnsignedintID& ror){fprintf_s(mFile,"connectAttr \"");ror.write(mFile);fprintf_s(mFile,"\" \"%s.ror\";\n",mName.c_str());}
	/*
	This attribute tells the instancer how to interpret the
	values in the "rotation" array when a point's rotation
	type is set to "Rotation".  The valid options are
	"Degrees" and "Radians".
	*/
	void setRotationAngleUnits(unsigned int rau){if(rau == 0) return; fprintf_s(mFile, "setAttr \".rau\" %i;\n", rau);}
	/*
	This attribute tells the instancer how to interpret the
	values in the "rotation" array when a point's rotation
	type is set to "Rotation".  The valid options are
	"Degrees" and "Radians".
	*/
	void setRotationAngleUnits(const UnsignedintID& rau){fprintf_s(mFile,"connectAttr \"");rau.write(mFile);fprintf_s(mFile,"\" \"%s.rau\";\n",mName.c_str());}
	/*
	This attribute tells the instancer whether or not it should
	change the hierachy instanced to each point automatically
	or not, and how it should change them.
	*/
	void setCycle(unsigned int cyc){if(cyc == 0) return; fprintf_s(mFile, "setAttr \".cyc\" %i;\n", cyc);}
	/*
	This attribute tells the instancer whether or not it should
	change the hierachy instanced to each point automatically
	or not, and how it should change them.
	*/
	void setCycle(const UnsignedintID& cyc){fprintf_s(mFile,"connectAttr \"");cyc.write(mFile);fprintf_s(mFile,"\" \"%s.cyc\";\n",mName.c_str());}
	/*
	This attribute tells the instancer how often to change
	the hierarchy instanced to each point.  The unit that
	this value is interpretted in is based on the value
	of aCycleStepUnit
	*/
	void setCycleStep(double cs){if(cs == 1.0) return; fprintf_s(mFile, "setAttr \".cs\" %f;\n", cs);}
	/*
	This attribute tells the instancer how often to change
	the hierarchy instanced to each point.  The unit that
	this value is interpretted in is based on the value
	of aCycleStepUnit
	*/
	void setCycleStep(const DoubleID& cs){fprintf_s(mFile,"connectAttr \"");cs.write(mFile);fprintf_s(mFile,"\" \"%s.cs\";\n",mName.c_str());}
	/*
	This attribute tells the instancer how to interpret the value
	in aCycleStep.  The default is to be in frames.
	*/
	void setCycleStepUnit(unsigned int csu){if(csu == 0) return; fprintf_s(mFile, "setAttr \".csu\" %i;\n", csu);}
	/*
	This attribute tells the instancer how to interpret the value
	in aCycleStep.  The default is to be in frames.
	*/
	void setCycleStepUnit(const UnsignedintID& csu){fprintf_s(mFile,"connectAttr \"");csu.write(mFile);fprintf_s(mFile,"\" \"%s.csu\";\n",mName.c_str());}
	/*
	This attribute lets the user control the display of the
	instanced objects.  Since there could be hundreds or
	thousands of points, the user may not want to draw them all
	interactively.  If this attribute is set to "Full", then
	the objects are drawn exactly as they would be in the current
	display mode.  If the value is "BOXES", then only the bounding
	box for each object is drawn.  If the value is "BOX", then
	only the bounding box for the instnacer is drawn.
	*/
	void setLevelOfDetail(unsigned int lod){if(lod == 0) return; fprintf_s(mFile, "setAttr \".lod\" %i;\n", lod);}
	/*
	This attribute lets the user control the display of the
	instanced objects.  Since there could be hundreds or
	thousands of points, the user may not want to draw them all
	interactively.  If this attribute is set to "Full", then
	the objects are drawn exactly as they would be in the current
	display mode.  If the value is "BOXES", then only the bounding
	box for each object is drawn.  If the value is "BOX", then
	only the bounding box for the instnacer is drawn.
	*/
	void setLevelOfDetail(const UnsignedintID& lod){fprintf_s(mFile,"connectAttr \"");lod.write(mFile);fprintf_s(mFile,"\" \"%s.lod\";\n",mName.c_str());}
	/*
	This attribute will be set to the current number of
	instances being created.  This number includes those
	whose "visibility" value is set to FALSE/0.  It
	is the number of points coming into the instancer.
	*/
	void setInstanceCount(const IntID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*
	This is a READ-ONLY attribute to allow the users to query
	the number of hierarchies being instanced by the node.
	*/
	void setHierarchyCount(const IntID& hc){fprintf_s(mFile,"connectAttr \"");hc.write(mFile);fprintf_s(mFile,"\" \"%s.hc\";\n",mName.c_str());}
	/*
	This is where the point data is connected.  The point data
	can only be coming from one source.  There is nothing
	keeping the user from having an API node take several
	inputs and combining them into a single point data
	attribute, however.
	*/
	GenericArrayID getInputPoints(){char buffer[4096];sprintf_s (buffer, "%s.inp",mName.c_str());return (const char*)buffer;}
	/*
	This attribute tells the instancer what order to do the
	rotations in for each point if and only if the rotation
	type is set to "Rotation" for that particular point.  When
	either "aimDirection" or "aimPosition" are used, then the
	rotation order does not matter.
	*/
	UnsignedintID getRotationOrder(){char buffer[4096];sprintf_s (buffer, "%s.ror",mName.c_str());return (const char*)buffer;}
	/*
	This attribute tells the instancer how to interpret the
	values in the "rotation" array when a point's rotation
	type is set to "Rotation".  The valid options are
	"Degrees" and "Radians".
	*/
	UnsignedintID getRotationAngleUnits(){char buffer[4096];sprintf_s (buffer, "%s.rau",mName.c_str());return (const char*)buffer;}
	/*
	This attribute tells the instancer whether or not it should
	change the hierachy instanced to each point automatically
	or not, and how it should change them.
	*/
	UnsignedintID getCycle(){char buffer[4096];sprintf_s (buffer, "%s.cyc",mName.c_str());return (const char*)buffer;}
	/*
	This attribute tells the instancer how often to change
	the hierarchy instanced to each point.  The unit that
	this value is interpretted in is based on the value
	of aCycleStepUnit
	*/
	DoubleID getCycleStep(){char buffer[4096];sprintf_s (buffer, "%s.cs",mName.c_str());return (const char*)buffer;}
	/*
	This attribute tells the instancer how to interpret the value
	in aCycleStep.  The default is to be in frames.
	*/
	UnsignedintID getCycleStepUnit(){char buffer[4096];sprintf_s (buffer, "%s.csu",mName.c_str());return (const char*)buffer;}
	/*
	This attribute lets the user control the display of the
	instanced objects.  Since there could be hundreds or
	thousands of points, the user may not want to draw them all
	interactively.  If this attribute is set to "Full", then
	the objects are drawn exactly as they would be in the current
	display mode.  If the value is "BOXES", then only the bounding
	box for each object is drawn.  If the value is "BOX", then
	only the bounding box for the instnacer is drawn.
	*/
	UnsignedintID getLevelOfDetail(){char buffer[4096];sprintf_s (buffer, "%s.lod",mName.c_str());return (const char*)buffer;}
	/*
	This attribute will be set to the current number of
	instances being created.  This number includes those
	whose "visibility" value is set to FALSE/0.  It
	is the number of points coming into the instancer.
	*/
	IntID getInstanceCount(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*
	This is a READ-ONLY attribute to allow the users to query
	the number of hierarchies being instanced by the node.
	*/
	IntID getHierarchyCount(){char buffer[4096];sprintf_s (buffer, "%s.hc",mName.c_str());return (const char*)buffer;}
protected:
	Instancer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_INSTANCER_H__
