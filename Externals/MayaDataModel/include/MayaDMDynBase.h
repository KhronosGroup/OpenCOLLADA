/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DYNBASE_H__
#define __MayaDM_DYNBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
dynAuxiliary is a base class node for all fields and emitters.
It encapulsates the machinery common to all those objects.
Its basic task is to handle drawing and selection tasks which are
common to all those classes. The name "dynBase" is vestigial.<p/>
*/
class DynBase : public Transform
{
public:
public:
	DynBase(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "dynBase"){}
	virtual ~DynBase(){}
	/*Obsolete. This attribute was used in version 1.  It is no longer used.*/
	void setOwner(const MessageID& ow){fprintf_s(mFile,"connectAttr \"");ow.write(mFile);fprintf_s(mFile,"\" \"%s.ow\";\n",mName.c_str());}
	/*Obsolete. This attribute was used in version 1.  It is no longer used.*/
	void setFromWhere(short fw){if(fw == 0) return; fprintf_s(mFile, "setAttr \".fw\" %i;\n", fw);}
	/*Obsolete. This attribute was used in version 1.  It is no longer used.*/
	void setFromWhere(const ShortID& fw){fprintf_s(mFile,"connectAttr \"");fw.write(mFile);fprintf_s(mFile,"\" \"%s.fw\";\n",mName.c_str());}
	/*
	Obsolete. This attribute was used in version 1.  It is no longer used.
	In v1.0, recorded which set of vertices/cvs to use.
	*/
	void setSubsetId(int sid){if(sid == -1) return; fprintf_s(mFile, "setAttr \".sid\" %i;\n", sid);}
	/*
	Obsolete. This attribute was used in version 1.  It is no longer used.
	In v1.0, recorded which set of vertices/cvs to use.
	*/
	void setSubsetId(const IntID& sid){fprintf_s(mFile,"connectAttr \"");sid.write(mFile);fprintf_s(mFile,"\" \"%s.sid\";\n",mName.c_str());}
	/*
	Tells UI if this is a positional object.
	This is for convenience of the UI only.
	*/
	void setPositional(const BoolID& psl){fprintf_s(mFile,"connectAttr \"");psl.write(mFile);fprintf_s(mFile,"\" \"%s.psl\";\n",mName.c_str());}
	/*Centroid of the owner's CV's or particles positions.*/
	void setOwnerCentroid(const Double3ID& ocd){fprintf_s(mFile,"connectAttr \"");ocd.write(mFile);fprintf_s(mFile,"\" \"%s.ocd\";\n",mName.c_str());}
	/*x-component of centroid of the owner position.*/
	void setOwnerCentroidX(const DoubleID& ocx){fprintf_s(mFile,"connectAttr \"");ocx.write(mFile);fprintf_s(mFile,"\" \"%s.ocd.ocx\";\n",mName.c_str());}
	/*y-component of centroid of the owner position.*/
	void setOwnerCentroidY(const DoubleID& ocy){fprintf_s(mFile,"connectAttr \"");ocy.write(mFile);fprintf_s(mFile,"\" \"%s.ocd.ocy\";\n",mName.c_str());}
	/*z-component of centroid of the owner position.*/
	void setOwnerCentroidZ(const DoubleID& ocz){fprintf_s(mFile,"connectAttr \"");ocz.write(mFile);fprintf_s(mFile,"\" \"%s.ocd.ocz\";\n",mName.c_str());}
	/*owner's position data array.*/
	void setOwnerPosData(const VectorArrayID& opd){fprintf_s(mFile,"connectAttr \"");opd.write(mFile);fprintf_s(mFile,"\" \"%s.opd\";\n",mName.c_str());}
	/*owner's velocity data array.*/
	void setOwnerVelData(const VectorArrayID& ovd){fprintf_s(mFile,"connectAttr \"");ovd.write(mFile);fprintf_s(mFile,"\" \"%s.ovd\";\n",mName.c_str());}
	/*Obsolete. This attribute was used in version 1.  It is no longer used.*/
	MessageID getOwner(){char buffer[4096];sprintf_s (buffer, "%s.ow",mName.c_str());return (const char*)buffer;}
	/*Obsolete. This attribute was used in version 1.  It is no longer used.*/
	ShortID getFromWhere(){char buffer[4096];sprintf_s (buffer, "%s.fw",mName.c_str());return (const char*)buffer;}
	/*
	Obsolete. This attribute was used in version 1.  It is no longer used.
	In v1.0, recorded which set of vertices/cvs to use.
	*/
	IntID getSubsetId(){char buffer[4096];sprintf_s (buffer, "%s.sid",mName.c_str());return (const char*)buffer;}
	/*
	Tells UI if this is a positional object.
	This is for convenience of the UI only.
	*/
	BoolID getPositional(){char buffer[4096];sprintf_s (buffer, "%s.psl",mName.c_str());return (const char*)buffer;}
	/*Centroid of the owner's CV's or particles positions.*/
	Double3ID getOwnerCentroid(){char buffer[4096];sprintf_s (buffer, "%s.ocd",mName.c_str());return (const char*)buffer;}
	/*x-component of centroid of the owner position.*/
	DoubleID getOwnerCentroidX(){char buffer[4096];sprintf_s (buffer, "%s.ocd.ocx",mName.c_str());return (const char*)buffer;}
	/*y-component of centroid of the owner position.*/
	DoubleID getOwnerCentroidY(){char buffer[4096];sprintf_s (buffer, "%s.ocd.ocy",mName.c_str());return (const char*)buffer;}
	/*z-component of centroid of the owner position.*/
	DoubleID getOwnerCentroidZ(){char buffer[4096];sprintf_s (buffer, "%s.ocd.ocz",mName.c_str());return (const char*)buffer;}
	/*owner's position data array.*/
	VectorArrayID getOwnerPosData(){char buffer[4096];sprintf_s (buffer, "%s.opd",mName.c_str());return (const char*)buffer;}
	/*owner's velocity data array.*/
	VectorArrayID getOwnerVelData(){char buffer[4096];sprintf_s (buffer, "%s.ovd",mName.c_str());return (const char*)buffer;}
protected:
	DynBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DYNBASE_H__
