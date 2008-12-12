/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LOOKAT_H__
#define __MayaDM_LOOKAT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAimConstraint.h"
namespace MayaDM
{
/*
The look at dependency graph node. <p/>

  This node has all the functionality of the aim constraint node,
  but additional behavior to implement the 2 and 3 node camera. The
  camera view tools and manipulators are capable of disabling this
  node during the mouse press and drag. Upon mouse release the
  target and the up nodes will then re-positioned to reflect the
  camera's new orientation. <p/>

  The twist can be used rotate the camera around the viewing
  direction when the worldUpType has been set to kUpScene or
  kUpVector. These up settings define the 2 node camera. This
  attribute has no effect otherwise. <p/>

  The distanceBetween is typically connected to the camera center of
  interest, and is a measure of the distance from the camera eye
  point to the target. <p/>

  The displayConnector attribute can be used to toggle the display
  of the connection lines between the up, eye, and target nodes. <p/>
*/
class LookAt : public AimConstraint
{
public:
public:
	LookAt(FILE* file,const std::string& name,const std::string& parent=""):AimConstraint(file, name, parent, "lookAt"){}
	virtual ~LookAt(){}
	/*Output distance between object and target (object space).*/
	void setDistanceBetween(double db){if(db == 0.0) return; fprintf_s(mFile, "setAttr \".db\" %f;\n", db);}
	/*Output distance between object and target (object space).*/
	void setDistanceBetween(const DoubleID& db){fprintf_s(mFile,"connectAttr \"");db.write(mFile);fprintf_s(mFile,"\" \"%s.db\";\n",mName.c_str());}
	/*Angle to rotate up around aim vector.*/
	void setTwist(double tws){if(tws == 0) return; fprintf_s(mFile, "setAttr \".tws\" %f;\n", tws);}
	/*Angle to rotate up around aim vector.*/
	void setTwist(const DoubleID& tws){fprintf_s(mFile,"connectAttr \"");tws.write(mFile);fprintf_s(mFile,"\" \"%s.tws\";\n",mName.c_str());}
	/*Toggle the display of eye and up connector lines*/
	void setDisplayConnector(bool dc){if(dc == true) return; fprintf_s(mFile, "setAttr \".dc\" %i;\n", dc);}
	/*Toggle the display of eye and up connector lines*/
	void setDisplayConnector(const BoolID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Output distance between object and target (object space).*/
	DoubleID getDistanceBetween(){char buffer[4096];sprintf_s (buffer, "%s.db",mName.c_str());return (const char*)buffer;}
	/*Angle to rotate up around aim vector.*/
	DoubleID getTwist(){char buffer[4096];sprintf_s (buffer, "%s.tws",mName.c_str());return (const char*)buffer;}
	/*Toggle the display of eye and up connector lines*/
	BoolID getDisplayConnector(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
protected:
	LookAt(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AimConstraint(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LOOKAT_H__
