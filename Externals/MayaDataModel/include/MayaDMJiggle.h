/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_JIGGLE_H__
#define __MayaDM_JIGGLE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMWeightGeometryFilter.h"
namespace MayaDM
{
/*
The jiggle deformer node generates secondary jiggling effect caused by
 the user defined animation.  The animation can be transform, deformation,
 etc. on the transform node as well as on each cv.
 <p/>
*/
class Jiggle : public WeightGeometryFilter
{
public:
	/*
	This is the multi attr to keep the internal cached data
	Each child is a compound attr corresponding to a geometry.
	The child attr contains a cached time, a cached status
	if the geometry is resting or not, an array of cached
	positions and an array of cached velocities.
	cached internal data
	*/
	struct CachedDataList{
		/*cached internal data for one geometry*/
		struct CachedData{
			void write(FILE* file) const
			{
			}
		} cachedData;
		void write(FILE* file) const
		{
		}
	};
public:
	Jiggle(FILE* file,const std::string& name,const std::string& parent=""):WeightGeometryFilter(file, name, parent, "jiggle"){}
	virtual ~Jiggle(){}
	/*
	This message attribute needs to be connect to a diskCache node
	so that it can invoke the method getCacheFile on diskCache to
	access the cached file.
	*/
	void setDiskCache(const MessageID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*
	This attribute connects to the global time node to access the current
	DG time.
	*/
	void setCurrentTime(const TimeID& cti){fprintf_s(mFile,"connectAttr \"");cti.write(mFile);fprintf_s(mFile,"\" \"%s.cti\";\n",mName.c_str());}
	/*
	Switch for ON, OFF, and Enable only when resting.
	EnableOnlyWhenResting enables the jiggle effect only if the
	object is not currently animated.  This means the jiggle will
	activate only if the movement from previous frame to the current
	frame is close to zero.
	*/
	void setEnable(unsigned int ebl){if(ebl == 2) return; fprintf_s(mFile, "setAttr \".ebl\" %i;\n", ebl);}
	/*
	Switch for ON, OFF, and Enable only when resting.
	EnableOnlyWhenResting enables the jiggle effect only if the
	object is not currently animated.  This means the jiggle will
	activate only if the movement from previous frame to the current
	frame is close to zero.
	*/
	void setEnable(const UnsignedintID& ebl){fprintf_s(mFile,"connectAttr \"");ebl.write(mFile);fprintf_s(mFile,"\" \"%s.ebl\";\n",mName.c_str());}
	/*The animation on xform will be ignored if this is true*/
	void setIgnoreTransform(bool it){if(it == false) return; fprintf_s(mFile, "setAttr \".it\" %i;\n", it);}
	/*The animation on xform will be ignored if this is true*/
	void setIgnoreTransform(const BoolID& it){fprintf_s(mFile,"connectAttr \"");it.write(mFile);fprintf_s(mFile,"\" \"%s.it\";\n",mName.c_str());}
	/*This is the scaling factor for the force along the surface normal direction*/
	void setForceAlongNormal(double fan){if(fan == 1.0) return; fprintf_s(mFile, "setAttr \".fan\" %f;\n", fan);}
	/*This is the scaling factor for the force along the surface normal direction*/
	void setForceAlongNormal(const DoubleID& fan){fprintf_s(mFile,"connectAttr \"");fan.write(mFile);fprintf_s(mFile,"\" \"%s.fan\";\n",mName.c_str());}
	/*This is the scaling factor for the force on the surface tangent plane*/
	void setForceOnTangent(double fot){if(fot == 1.0) return; fprintf_s(mFile, "setAttr \".fot\" %f;\n", fot);}
	/*This is the scaling factor for the force on the surface tangent plane*/
	void setForceOnTangent(const DoubleID& fot){fprintf_s(mFile,"connectAttr \"");fot.write(mFile);fprintf_s(mFile,"\" \"%s.fot\";\n",mName.c_str());}
	/*
	This is the global scaling factor for the jiggle effect.  This
	is enabled only if EnableOnlyWhenResting because in that case, the
	first order motion (i.e. user defined motion) isn't allowed to
	trigger the jiggle until it almost stops.  So, we need this
	attribute to amplify the first order motion, and it will only
	be applied the first time jiggle is activated.
	*/
	void setMotionMultiplier(double mm){if(mm == 1.0) return; fprintf_s(mFile, "setAttr \".mm\" %f;\n", mm);}
	/*
	This is the global scaling factor for the jiggle effect.  This
	is enabled only if EnableOnlyWhenResting because in that case, the
	first order motion (i.e. user defined motion) isn't allowed to
	trigger the jiggle until it almost stops.  So, we need this
	attribute to amplify the first order motion, and it will only
	be applied the first time jiggle is activated.
	*/
	void setMotionMultiplier(const DoubleID& mm){fprintf_s(mFile,"connectAttr \"");mm.write(mFile);fprintf_s(mFile,"\" \"%s.mm\";\n",mName.c_str());}
	/*This controls the stiffness.*/
	void setStiffness(double sf){if(sf == 0.5) return; fprintf_s(mFile, "setAttr \".sf\" %f;\n", sf);}
	/*This controls the stiffness.*/
	void setStiffness(const DoubleID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sf\";\n",mName.c_str());}
	/*This controls the damping magnitude.*/
	void setDamping(double dp){if(dp == 0.5) return; fprintf_s(mFile, "setAttr \".dp\" %f;\n", dp);}
	/*This controls the damping magnitude.*/
	void setDamping(const DoubleID& dp){fprintf_s(mFile,"connectAttr \"");dp.write(mFile);fprintf_s(mFile,"\" \"%s.dp\";\n",mName.c_str());}
	/*This scales the amount to jiggle*/
	void setJiggleWeight(double jw){if(jw == 1.0) return; fprintf_s(mFile, "setAttr \".jw\" %f;\n", jw);}
	/*This scales the amount to jiggle*/
	void setJiggleWeight(const DoubleID& jw){fprintf_s(mFile,"connectAttr \"");jw.write(mFile);fprintf_s(mFile,"\" \"%s.jw\";\n",mName.c_str());}
	/*
	This control scales down the jiggle motion toward the goal position and it's
	useful to prevent self penetration.  A value of zero allows free jiggle motion.
	A value of 1 allows a point to move along the normal's direction, but not
	the the opposite direction; whereas a value of -1 gives the opposite effect.
	*/
	void setDirectionBias(double bias){if(bias == 0.0) return; fprintf_s(mFile, "setAttr \".bias\" %f;\n", bias);}
	/*
	This control scales down the jiggle motion toward the goal position and it's
	useful to prevent self penetration.  A value of zero allows free jiggle motion.
	A value of 1 allows a point to move along the normal's direction, but not
	the the opposite direction; whereas a value of -1 gives the opposite effect.
	*/
	void setDirectionBias(const DoubleID& bias){fprintf_s(mFile,"connectAttr \"");bias.write(mFile);fprintf_s(mFile,"\" \"%s.bias\";\n",mName.c_str());}
	/*
	This message attribute needs to be connect to a diskCache node
	so that it can invoke the method getCacheFile on diskCache to
	access the cached file.
	*/
	MessageID getDiskCache(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*
	This attribute connects to the global time node to access the current
	DG time.
	*/
	TimeID getCurrentTime(){char buffer[4096];sprintf_s (buffer, "%s.cti",mName.c_str());return (const char*)buffer;}
	/*
	Switch for ON, OFF, and Enable only when resting.
	EnableOnlyWhenResting enables the jiggle effect only if the
	object is not currently animated.  This means the jiggle will
	activate only if the movement from previous frame to the current
	frame is close to zero.
	*/
	UnsignedintID getEnable(){char buffer[4096];sprintf_s (buffer, "%s.ebl",mName.c_str());return (const char*)buffer;}
	/*The animation on xform will be ignored if this is true*/
	BoolID getIgnoreTransform(){char buffer[4096];sprintf_s (buffer, "%s.it",mName.c_str());return (const char*)buffer;}
	/*This is the scaling factor for the force along the surface normal direction*/
	DoubleID getForceAlongNormal(){char buffer[4096];sprintf_s (buffer, "%s.fan",mName.c_str());return (const char*)buffer;}
	/*This is the scaling factor for the force on the surface tangent plane*/
	DoubleID getForceOnTangent(){char buffer[4096];sprintf_s (buffer, "%s.fot",mName.c_str());return (const char*)buffer;}
	/*
	This is the global scaling factor for the jiggle effect.  This
	is enabled only if EnableOnlyWhenResting because in that case, the
	first order motion (i.e. user defined motion) isn't allowed to
	trigger the jiggle until it almost stops.  So, we need this
	attribute to amplify the first order motion, and it will only
	be applied the first time jiggle is activated.
	*/
	DoubleID getMotionMultiplier(){char buffer[4096];sprintf_s (buffer, "%s.mm",mName.c_str());return (const char*)buffer;}
	/*This controls the stiffness.*/
	DoubleID getStiffness(){char buffer[4096];sprintf_s (buffer, "%s.sf",mName.c_str());return (const char*)buffer;}
	/*This controls the damping magnitude.*/
	DoubleID getDamping(){char buffer[4096];sprintf_s (buffer, "%s.dp",mName.c_str());return (const char*)buffer;}
	/*This scales the amount to jiggle*/
	DoubleID getJiggleWeight(){char buffer[4096];sprintf_s (buffer, "%s.jw",mName.c_str());return (const char*)buffer;}
	/*
	This control scales down the jiggle motion toward the goal position and it's
	useful to prevent self penetration.  A value of zero allows free jiggle motion.
	A value of 1 allows a point to move along the normal's direction, but not
	the the opposite direction; whereas a value of -1 gives the opposite effect.
	*/
	DoubleID getDirectionBias(){char buffer[4096];sprintf_s (buffer, "%s.bias",mName.c_str());return (const char*)buffer;}
protected:
	Jiggle(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):WeightGeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_JIGGLE_H__
