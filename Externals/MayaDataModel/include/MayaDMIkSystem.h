/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKSYSTEM_H__
#define __MayaDM_IKSYSTEM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The ikSystem node is the control center for IK. All ikHandles, ikSolvers,
        and skeletons are ultimately controlled by the ikSystem. It determines
        whether ik or forward kinematics is to be performed based on rules.<p/>

        The ikSystem has two global control attributes, globalSolve and globalSnap.
        If globalSolve is off, there is no IK solving. If globalSnap is off,
        ikHandles will not be snapped to the ikEffector location. These two
        attributes are on by default. They are the highest priority controls in the
        ikSystem.<p/>

        The other attribute is ikSolver. It shows how the ikSystem organizes
        ikSolvers. When an ikSolver is created, it will be connected with the
        ikSystem through this attribute, and the order of these connections
        implies a priority for that ikSolver.<p/>
*/
class IkSystem : public DependNode
{
public:
public:
	IkSystem(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "ikSystem"){}
	virtual ~IkSystem(){}
	/*If false, no handle will be snapped.*/
	void setGlobalSnap(bool gsn){if(gsn == true) return; fprintf_s(mFile, "setAttr \".gsn\" %i;\n", gsn);}
	/*If false, no handle will be snapped.*/
	void setGlobalSnap(const BoolID& gsn){fprintf_s(mFile,"connectAttr \"");gsn.write(mFile);fprintf_s(mFile,"\" \"%s.gsn\";\n",mName.c_str());}
	/*If false, ikSolvers will not start.*/
	void setGlobalSolve(bool gsv){if(gsv == true) return; fprintf_s(mFile, "setAttr \".gsv\" %i;\n", gsv);}
	/*If false, ikSolvers will not start.*/
	void setGlobalSolve(const BoolID& gsv){fprintf_s(mFile,"connectAttr \"");gsv.write(mFile);fprintf_s(mFile,"\" \"%s.gsv\";\n",mName.c_str());}
	/*If false, no handle will be snapped.*/
	BoolID getGlobalSnap(){char buffer[4096];sprintf_s (buffer, "%s.gsn",mName.c_str());return (const char*)buffer;}
	/*If false, ikSolvers will not start.*/
	BoolID getGlobalSolve(){char buffer[4096];sprintf_s (buffer, "%s.gsv",mName.c_str());return (const char*)buffer;}
protected:
	IkSystem(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKSYSTEM_H__
