/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DAGPOSE_H__
#define __MayaDM_DAGPOSE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node is used to store information about a hierarchical pose.<p/>

        This node performs no computation. It is typically used in
        conjunction with the dagPose command in order to save and restore
        poses.<p/>

        Poses are also created when skin is bound to a skeleton. These poses
        are called bindPoses, and are unique in that each joint/transform is
        only allowed to be placed in a single bindPose. <p/>
*/
class DagPose : public DependNode
{
public:
public:
	DagPose(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "dagPose"){}
	virtual ~DagPose(){}
	/*
	This attribute stores the inclusive matrix for the associated
	member at the time the pose is saved.
	Indices in the worldMatrix multi have a one-to-one correspondence
	with indices in the members multi.
	*/
	void setWorldMatrix(size_t wm_i,const matrix& wm){if(wm == identity) return; fprintf_s(mFile, "setAttr \".wm[%i]\" -type \"matrix\" ",wm_i);wm.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This attribute stores the inclusive matrix for the associated
	member at the time the pose is saved.
	Indices in the worldMatrix multi have a one-to-one correspondence
	with indices in the members multi.
	*/
	void setWorldMatrix(size_t wm_i,const MatrixID& wm){fprintf_s(mFile,"connectAttr \"");wm.write(mFile);fprintf_s(mFile,"\" \"%s.wm[%i]\";\n",mName.c_str(),wm_i);}
	/*
	Stores the local matrix for the associated member at the time the
	pose is saved.
	Indices in the xformMatrix multi have a one-to-one correspondence
	with indices in the members multi.
	*/
	void setXformMatrix(size_t xm_i,const matrix& xm){if(xm == identity) return; fprintf_s(mFile, "setAttr \".xm[%i]\" -type \"matrix\" ",xm_i);xm.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Connection to this attribute as a destination signals that the
	connected item is a member of the pose.
	*/
	void setMembers(size_t m_i,const MessageID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m[%i]\";\n",mName.c_str(),m_i);}
	/*
	Connection to this attribute as a destination signals that the
	connected item is a parent of the associated member.
	Indices in the parents multi have a one-to-one correspondence
	with indices in the members multi.
	*/
	void setParents(size_t p_i,const MessageID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*
	Indicates whether the member should be restored to its local pose
	in global mode only. The typical situation where global will be
	true is if the pose is made to selected items only. Parents
	of the selected item will be saved with the pose, but only restored
	to their pose in global mode.
	Indices in the global multi have a one-to-one correspondence
	with indices in the members multi.
	*/
	void setGlobal(size_t g_i,bool g){if(g == false) return; fprintf_s(mFile, "setAttr \".g[%i]\" %i;\n", g_i,g);}
	/*
	Connection to the parent attribute from this attribute indicates
	that the associated member was parented to world at the time
	of the bind.
	*/
	void setWorld(const MessageID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.w\";\n",mName.c_str());}
	/*Indicates that the pose node is storing a bindPose.*/
	void setBindPose(bool bp){if(bp == false) return; fprintf_s(mFile, "setAttr \".bp\" %i;\n", bp);}
	/*
	This attribute stores the inclusive matrix for the associated
	member at the time the pose is saved.
	Indices in the worldMatrix multi have a one-to-one correspondence
	with indices in the members multi.
	*/
	const MatrixID& getWorldMatrix(size_t wm_i){char buffer[4096];sprintf_s (buffer, "%s.wm[%i]",mName.c_str(),wm_i);return (const char*)buffer;}
	/*
	Connection to this attribute as a destination signals that the
	connected item is a member of the pose.
	*/
	const MessageID& getMembers(size_t m_i){char buffer[4096];sprintf_s (buffer, "%s.m[%i]",mName.c_str(),m_i);return (const char*)buffer;}
	/*
	Connection to this attribute as a destination signals that the
	connected item is a parent of the associated member.
	Indices in the parents multi have a one-to-one correspondence
	with indices in the members multi.
	*/
	const MessageID& getParents(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*
	Connection to the parent attribute from this attribute indicates
	that the associated member was parented to world at the time
	of the bind.
	*/
	MessageID getWorld(){char buffer[4096];sprintf_s (buffer, "%s.w",mName.c_str());return (const char*)buffer;}
protected:
	DagPose(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DAGPOSE_H__
