/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LODTHRESHOLDS_H__
#define __MayaDM_LODTHRESHOLDS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>This lodThresholds node can be used to detect when an object is
 a certain distance from a bounding box.

For example, when the distance between the bounding box and a
 camera point is less than the first threshold (threshold[0]),
 then only the first output attribute (output[0]) is true.
 When the distance is between threshold[0] and threshold[1],
 then the only the 2nd output attribute (output[1]) is true.

Historic note: This was originally developed for the "Level of
Detail" feature but was eventually replaced by the LodGroup node.
 Hence the confusing names.
</pre></p>
*/
class LodThresholds : public DependNode
{
public:
public:
	LodThresholds(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "lodThresholds"){}
	virtual ~LodThresholds(){}
	/*3D point that is the minimum point of a bounding box*/
	void setInBoxMin(const double3& bmn){fprintf_s(mFile, "setAttr \".bmn\" -type \"double3\" ");bmn.write(mFile);fprintf_s(mFile,";\n");}
	/*3D point that is the minimum point of a bounding box*/
	void setInBoxMin(const Double3ID& bmn){fprintf_s(mFile,"connectAttr \"");bmn.write(mFile);fprintf_s(mFile,"\" \"%s.bmn\";\n",mName.c_str());}
	/*Minimum point of a bounding box in X*/
	void setInBoxMinX(double bmix){if(bmix == 0) return; fprintf_s(mFile, "setAttr \".bmn.bmix\" %f;\n", bmix);}
	/*Minimum point of a bounding box in X*/
	void setInBoxMinX(const DoubleID& bmix){fprintf_s(mFile,"connectAttr \"");bmix.write(mFile);fprintf_s(mFile,"\" \"%s.bmn.bmix\";\n",mName.c_str());}
	/*Minimum point of a bounding box in Y*/
	void setInBoxMinY(double bmiy){if(bmiy == 0) return; fprintf_s(mFile, "setAttr \".bmn.bmiy\" %f;\n", bmiy);}
	/*Minimum point of a bounding box in Y*/
	void setInBoxMinY(const DoubleID& bmiy){fprintf_s(mFile,"connectAttr \"");bmiy.write(mFile);fprintf_s(mFile,"\" \"%s.bmn.bmiy\";\n",mName.c_str());}
	/*Minimum point of a bounding box in Z*/
	void setInBoxMinZ(double bmiz){if(bmiz == 0) return; fprintf_s(mFile, "setAttr \".bmn.bmiz\" %f;\n", bmiz);}
	/*Minimum point of a bounding box in Z*/
	void setInBoxMinZ(const DoubleID& bmiz){fprintf_s(mFile,"connectAttr \"");bmiz.write(mFile);fprintf_s(mFile,"\" \"%s.bmn.bmiz\";\n",mName.c_str());}
	/*3D point that is the maximum point of a bounding box*/
	void setInBoxMax(const double3& bmx){fprintf_s(mFile, "setAttr \".bmx\" -type \"double3\" ");bmx.write(mFile);fprintf_s(mFile,";\n");}
	/*3D point that is the maximum point of a bounding box*/
	void setInBoxMax(const Double3ID& bmx){fprintf_s(mFile,"connectAttr \"");bmx.write(mFile);fprintf_s(mFile,"\" \"%s.bmx\";\n",mName.c_str());}
	/*Maxmimum point of a bounding box in X*/
	void setInBoxMaxX(double bmax){if(bmax == 0) return; fprintf_s(mFile, "setAttr \".bmx.bmax\" %f;\n", bmax);}
	/*Maxmimum point of a bounding box in X*/
	void setInBoxMaxX(const DoubleID& bmax){fprintf_s(mFile,"connectAttr \"");bmax.write(mFile);fprintf_s(mFile,"\" \"%s.bmx.bmax\";\n",mName.c_str());}
	/*Maxmimum point of a bounding box in Y*/
	void setInBoxMaxY(double bmay){if(bmay == 0) return; fprintf_s(mFile, "setAttr \".bmx.bmay\" %f;\n", bmay);}
	/*Maxmimum point of a bounding box in Y*/
	void setInBoxMaxY(const DoubleID& bmay){fprintf_s(mFile,"connectAttr \"");bmay.write(mFile);fprintf_s(mFile,"\" \"%s.bmx.bmay\";\n",mName.c_str());}
	/*Maxmimum point of a bounding box in Z*/
	void setInBoxMaxZ(double bmaz){if(bmaz == 0) return; fprintf_s(mFile, "setAttr \".bmx.bmaz\" %f;\n", bmaz);}
	/*Maxmimum point of a bounding box in Z*/
	void setInBoxMaxZ(const DoubleID& bmaz){fprintf_s(mFile,"connectAttr \"");bmaz.write(mFile);fprintf_s(mFile,"\" \"%s.bmx.bmaz\";\n",mName.c_str());}
	/*
	Camera position.  This does not need to be a camera;
	it just needs to be a 3D point.
	*/
	void setCamera(const double3& cam){fprintf_s(mFile, "setAttr \".cam\" -type \"double3\" ");cam.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Camera position.  This does not need to be a camera;
	it just needs to be a 3D point.
	*/
	void setCamera(const Double3ID& cam){fprintf_s(mFile,"connectAttr \"");cam.write(mFile);fprintf_s(mFile,"\" \"%s.cam\";\n",mName.c_str());}
	/*Camera position in X.  This does not need to be a camera;*/
	void setCameraX(double cax){if(cax == 0) return; fprintf_s(mFile, "setAttr \".cam.cax\" %f;\n", cax);}
	/*Camera position in X.  This does not need to be a camera;*/
	void setCameraX(const DoubleID& cax){fprintf_s(mFile,"connectAttr \"");cax.write(mFile);fprintf_s(mFile,"\" \"%s.cam.cax\";\n",mName.c_str());}
	/*Camera position in Y.  This does not need to be a camera;*/
	void setCameraY(double cay){if(cay == 0) return; fprintf_s(mFile, "setAttr \".cam.cay\" %f;\n", cay);}
	/*Camera position in Y.  This does not need to be a camera;*/
	void setCameraY(const DoubleID& cay){fprintf_s(mFile,"connectAttr \"");cay.write(mFile);fprintf_s(mFile,"\" \"%s.cam.cay\";\n",mName.c_str());}
	/*Camera position in Z.  This does not need to be a camera;*/
	void setCameraZ(double caz){if(caz == 0) return; fprintf_s(mFile, "setAttr \".cam.caz\" %f;\n", caz);}
	/*Camera position in Z.  This does not need to be a camera;*/
	void setCameraZ(const DoubleID& caz){fprintf_s(mFile,"connectAttr \"");caz.write(mFile);fprintf_s(mFile,"\" \"%s.cam.caz\";\n",mName.c_str());}
	/*
	List of values that indicate ranges.  Ranges are defined by:
	range[0]: 0 to outLevel[0]
	range[1]: outLevel[0] to outLevel[1]
	etc.
	*/
	void setThreshold(size_t th_i,double th){if(th == 0) return; fprintf_s(mFile, "setAttr \".th[%i]\" %f;\n", th_i,th);}
	/*
	List of values that indicate ranges.  Ranges are defined by:
	range[0]: 0 to outLevel[0]
	range[1]: outLevel[0] to outLevel[1]
	etc.
	*/
	void setThreshold(size_t th_i,const DoubleID& th){fprintf_s(mFile,"connectAttr \"");th.write(mFile);fprintf_s(mFile,"\" \"%s.th[%i]\";\n",mName.c_str(),th_i);}
	/*Distance calculated between the bounding box and the camera point*/
	void setDistance(const DoubleID& d){fprintf_s(mFile,"connectAttr \"");d.write(mFile);fprintf_s(mFile,"\" \"%s.d\";\n",mName.c_str());}
	/*
	The currently active level
	If the distance between the camera point and the bounding box
	is less than the first threshold, then the active level is 0.
	*/
	void setActiveLevel(const IntID& al){fprintf_s(mFile,"connectAttr \"");al.write(mFile);fprintf_s(mFile,"\" \"%s.al\";\n",mName.c_str());}
	/*
	Multi attribute indicating which level is the active level.
	For example, if the active level is 0, then the first
	output attribute, output[0] is true.
	*/
	void setOutLevel(size_t ol_i,const BoolID& ol){fprintf_s(mFile,"connectAttr \"");ol.write(mFile);fprintf_s(mFile,"\" \"%s.ol[%i]\";\n",mName.c_str(),ol_i);}
	/*3D point that is the minimum point of a bounding box*/
	Double3ID getInBoxMin(){char buffer[4096];sprintf_s (buffer, "%s.bmn",mName.c_str());return (const char*)buffer;}
	/*Minimum point of a bounding box in X*/
	DoubleID getInBoxMinX(){char buffer[4096];sprintf_s (buffer, "%s.bmn.bmix",mName.c_str());return (const char*)buffer;}
	/*Minimum point of a bounding box in Y*/
	DoubleID getInBoxMinY(){char buffer[4096];sprintf_s (buffer, "%s.bmn.bmiy",mName.c_str());return (const char*)buffer;}
	/*Minimum point of a bounding box in Z*/
	DoubleID getInBoxMinZ(){char buffer[4096];sprintf_s (buffer, "%s.bmn.bmiz",mName.c_str());return (const char*)buffer;}
	/*3D point that is the maximum point of a bounding box*/
	Double3ID getInBoxMax(){char buffer[4096];sprintf_s (buffer, "%s.bmx",mName.c_str());return (const char*)buffer;}
	/*Maxmimum point of a bounding box in X*/
	DoubleID getInBoxMaxX(){char buffer[4096];sprintf_s (buffer, "%s.bmx.bmax",mName.c_str());return (const char*)buffer;}
	/*Maxmimum point of a bounding box in Y*/
	DoubleID getInBoxMaxY(){char buffer[4096];sprintf_s (buffer, "%s.bmx.bmay",mName.c_str());return (const char*)buffer;}
	/*Maxmimum point of a bounding box in Z*/
	DoubleID getInBoxMaxZ(){char buffer[4096];sprintf_s (buffer, "%s.bmx.bmaz",mName.c_str());return (const char*)buffer;}
	/*
	Camera position.  This does not need to be a camera;
	it just needs to be a 3D point.
	*/
	Double3ID getCamera(){char buffer[4096];sprintf_s (buffer, "%s.cam",mName.c_str());return (const char*)buffer;}
	/*Camera position in X.  This does not need to be a camera;*/
	DoubleID getCameraX(){char buffer[4096];sprintf_s (buffer, "%s.cam.cax",mName.c_str());return (const char*)buffer;}
	/*Camera position in Y.  This does not need to be a camera;*/
	DoubleID getCameraY(){char buffer[4096];sprintf_s (buffer, "%s.cam.cay",mName.c_str());return (const char*)buffer;}
	/*Camera position in Z.  This does not need to be a camera;*/
	DoubleID getCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.cam.caz",mName.c_str());return (const char*)buffer;}
	/*
	List of values that indicate ranges.  Ranges are defined by:
	range[0]: 0 to outLevel[0]
	range[1]: outLevel[0] to outLevel[1]
	etc.
	*/
	const DoubleID& getThreshold(size_t th_i){char buffer[4096];sprintf_s (buffer, "%s.th[%i]",mName.c_str(),th_i);return (const char*)buffer;}
	/*Distance calculated between the bounding box and the camera point*/
	DoubleID getDistance(){char buffer[4096];sprintf_s (buffer, "%s.d",mName.c_str());return (const char*)buffer;}
	/*
	The currently active level
	If the distance between the camera point and the bounding box
	is less than the first threshold, then the active level is 0.
	*/
	IntID getActiveLevel(){char buffer[4096];sprintf_s (buffer, "%s.al",mName.c_str());return (const char*)buffer;}
	/*
	Multi attribute indicating which level is the active level.
	For example, if the active level is 0, then the first
	output attribute, output[0] is true.
	*/
	const BoolID& getOutLevel(size_t ol_i){char buffer[4096];sprintf_s (buffer, "%s.ol[%i]",mName.c_str(),ol_i);return (const char*)buffer;}
protected:
	LodThresholds(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LODTHRESHOLDS_H__
