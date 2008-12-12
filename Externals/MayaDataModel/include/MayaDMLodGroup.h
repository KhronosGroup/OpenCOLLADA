/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LODGROUP_H__
#define __MayaDM_LODGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
<p><pre> This transform node is a group node that can be used to detect how
 close a group of objects is to a camera.  Typically this node is
 used for controlling "Level of Detail" visibility.  With "Level of Detail",
 the visibility of the children of this transform are controlled
 by the distance of a group to a camera and the threshold values.

 For example, under a LOD group node, there are three children:
 ship_detailed, ship_medium, and ship_rough.  There are three
 threshold values: 5, 10 and 15.  When the camera is within
 5 units of the group bounding box, only ship_detailed is visible.
 When the view is zoomed out and the camera is 9 units away from
 the group, only ship_medium is visible.  When the view is
 zoomed out to 30 units away, only ship_rough is visible.

 See also documentation on the "Level Of Detail" feature in Maya Version
 3.0 and higher.

</pre></p>
*/
class LodGroup : public Transform
{
public:
public:
	LodGroup(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "lodGroup"){}
	virtual ~LodGroup(){}
	/*Transformation matrix to put the camera position into world space*/
	void setCameraMatrix(const matrix& cm){if(cm == identity) return; fprintf_s(mFile, "setAttr \".cm\" -type \"matrix\" ");cm.write(mFile);fprintf_s(mFile,";\n");}
	/*Transformation matrix to put the camera position into world space*/
	void setCameraMatrix(const MatrixID& cm){fprintf_s(mFile,"connectAttr \"");cm.write(mFile);fprintf_s(mFile,"\" \"%s.cm\";\n",mName.c_str());}
	/*
	List of values that indicate ranges.  Ranges are defined by:
	range[0]: 0 to outLevel[0]
	range[1]: outLevel[0] to outLevel[1]
	etc.
	For example, the first child under this group node will be
	displayed when
	the camera is in the first range.
	*/
	void setThreshold(size_t th_i,double th){if(th == 0) return; fprintf_s(mFile, "setAttr \".th[%i]\" %f;\n", th_i,th);}
	/*
	List of values that indicate ranges.  Ranges are defined by:
	range[0]: 0 to outLevel[0]
	range[1]: outLevel[0] to outLevel[1]
	etc.
	For example, the first child under this group node will be
	displayed when
	the camera is in the first range.
	*/
	void setThreshold(size_t th_i,const DoubleID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th[%i]\";\n",mName.c_str(),th_i);}
	/*
	Overrides the display of any level and can force it to hide or show
	the object at that level.
	For example, if the distance between the group and the camera is
	smaller than the first threshold, then the object at level 0
	is visible.  If the display level for the object at level 2
	is changed to "show", ie. if the attribute displayLevel[2] is
	set to "show", then the object at level 2 will show, regardless
	of the current active level.
	*/
	void setDisplayLevel(size_t dl_i,unsigned int dl){if(dl == 0) return; fprintf_s(mFile, "setAttr \".dl[%i]\" %i;\n", dl_i,dl);}
	/*
	Overrides the display of any level and can force it to hide or show
	the object at that level.
	For example, if the distance between the group and the camera is
	smaller than the first threshold, then the object at level 0
	is visible.  If the display level for the object at level 2
	is changed to "show", ie. if the attribute displayLevel[2] is
	set to "show", then the object at level 2 will show, regardless
	of the current active level.
	*/
	void setDisplayLevel(size_t dl_i,const UnsignedintID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl[%i]\";\n",mName.c_str(),dl_i);}
	/*
	Enables the minimum and maximum distance to take effect.
	For example, if the distance between the group and the camera is
	smaller than the minimum distace, then the whole group disappears.
	*/
	void setMinMaxDistance(bool mmd){if(mmd == 0) return; fprintf_s(mFile, "setAttr \".mmd\" %i;\n", mmd);}
	/*
	Enables the minimum and maximum distance to take effect.
	For example, if the distance between the group and the camera is
	smaller than the minimum distace, then the whole group disappears.
	*/
	void setMinMaxDistance(const BoolID& mmd){fprintf_s(mFile,"connectAttr \"");mmd.write(mFile);fprintf_s(mFile,"\" \"%s.mmd\";\n",mName.c_str());}
	/*The minimum distance at which the group is displayed.*/
	void setMinDistance(double mid){if(mid == -100.0) return; fprintf_s(mFile, "setAttr \".mid\" %f;\n", mid);}
	/*The minimum distance at which the group is displayed.*/
	void setMinDistance(const DoubleID& mid){fprintf_s(mFile,"connectAttr \"");mid.write(mFile);fprintf_s(mFile,"\" \"%s.mid\";\n",mName.c_str());}
	/*The maximum distance at which the group is displayed.*/
	void setMaxDistance(double mxd){if(mxd == 100.0) return; fprintf_s(mFile, "setAttr \".mxd\" %f;\n", mxd);}
	/*The maximum distance at which the group is displayed.*/
	void setMaxDistance(const DoubleID& mxd){fprintf_s(mFile,"connectAttr \"");mxd.write(mFile);fprintf_s(mFile,"\" \"%s.mxd\";\n",mName.c_str());}
	/*Distance calculated between the camera and the group node's bounding box.*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	The currently active level.
	For example, if the distance between the group and the camera is
	smaller than the first threshold, then the active level is 0.
	*/
	void setActiveLevel(const IntID& al){fprintf_s(mFile,"connectAttr \"");al.write(mFile);fprintf_s(mFile,"\" \"%s.al\";\n",mName.c_str());}
	/*
	Multi-attribute whose members are enabled based on the distance
	between the camera and the group node's bounding box.
	For example, if the distance between the group and the camera is
	smaller than the first threshold, then the attribute output[0] is TRUE.
	All other output attributes are false.
	When the active level changes to 1, then the attribute
	output[1] is TRUE, and all others are false.
	*/
	void setOutput(size_t o_i,const BoolID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o[%i]\";\n",mName.c_str(),o_i);}
	/*Transformation matrix to put the camera position into world space*/
	MatrixID getCameraMatrix(){char buffer[4096];sprintf_s (buffer, "%s.cm",mName.c_str());return (const char*)buffer;}
	/*
	List of values that indicate ranges.  Ranges are defined by:
	range[0]: 0 to outLevel[0]
	range[1]: outLevel[0] to outLevel[1]
	etc.
	For example, the first child under this group node will be
	displayed when
	the camera is in the first range.
	*/
	const DoubleID& getThreshold(size_t th_i){char buffer[4096];sprintf_s (buffer, "%s.th[%i]",mName.c_str(),th_i);return (const char*)buffer;}
	/*
	Overrides the display of any level and can force it to hide or show
	the object at that level.
	For example, if the distance between the group and the camera is
	smaller than the first threshold, then the object at level 0
	is visible.  If the display level for the object at level 2
	is changed to "show", ie. if the attribute displayLevel[2] is
	set to "show", then the object at level 2 will show, regardless
	of the current active level.
	*/
	const UnsignedintID& getDisplayLevel(size_t dl_i){char buffer[4096];sprintf_s (buffer, "%s.dl[%i]",mName.c_str(),dl_i);return (const char*)buffer;}
	/*
	Enables the minimum and maximum distance to take effect.
	For example, if the distance between the group and the camera is
	smaller than the minimum distace, then the whole group disappears.
	*/
	BoolID getMinMaxDistance(){char buffer[4096];sprintf_s (buffer, "%s.mmd",mName.c_str());return (const char*)buffer;}
	/*The minimum distance at which the group is displayed.*/
	DoubleID getMinDistance(){char buffer[4096];sprintf_s (buffer, "%s.mid",mName.c_str());return (const char*)buffer;}
	/*The maximum distance at which the group is displayed.*/
	DoubleID getMaxDistance(){char buffer[4096];sprintf_s (buffer, "%s.mxd",mName.c_str());return (const char*)buffer;}
	/*Distance calculated between the camera and the group node's bounding box.*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	The currently active level.
	For example, if the distance between the group and the camera is
	smaller than the first threshold, then the active level is 0.
	*/
	IntID getActiveLevel(){char buffer[4096];sprintf_s (buffer, "%s.al",mName.c_str());return (const char*)buffer;}
	/*
	Multi-attribute whose members are enabled based on the distance
	between the camera and the group node's bounding box.
	For example, if the distance between the group and the camera is
	smaller than the first threshold, then the attribute output[0] is TRUE.
	All other output attributes are false.
	When the active level changes to 1, then the attribute
	output[1] is TRUE, and all others are false.
	*/
	const BoolID& getOutput(size_t o_i){char buffer[4096];sprintf_s (buffer, "%s.o[%i]",mName.c_str(),o_i);return (const char*)buffer;}
protected:
	LodGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LODGROUP_H__
