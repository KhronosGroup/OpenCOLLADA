/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_JOINTFFD_H__
#define __MayaDM_JOINTFFD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFfd.h"
namespace MayaDM
{
/*
This node is used by jointLattice flexors.  It deforms the components of
an input object or objects using a slightly modified version of the
standard FFD algorithm.  Rather than using a single lattice, this node
makes use of a second base lattice.
This is mainly used for wrapping an ffd around a joint.
The normal base is used for the points associated with the upper bone
of the joint while the second base is used for the points associated
with the lower bone of the joint.
*/
class JointFfd : public Ffd
{
public:
public:
	JointFfd(FILE* file,const std::string& name,const std::string& parent=""):Ffd(file, name, parent, "jointFfd"){}
	virtual ~JointFfd(){}
	/*The second base lattice needed for joint lattice flexors.*/
	void setBaseLattice2Matrix(const matrix& b2){if(b2 == identity) return; fprintf_s(mFile, "setAttr \".b2\" -type \"matrix\" ");b2.write(mFile);fprintf_s(mFile,";\n");}
	/*The second base lattice needed for joint lattice flexors.*/
	void setBaseLattice2Matrix(const MatrixID& b2){fprintf_s(mFile,"connectAttr \"");b2.write(mFile);fprintf_s(mFile,"\" \"%s.b2\";\n",mName.c_str());}
	/*The group id for points associated with the upper bone.*/
	void setGroupIdUpperBindSkin(size_t gu_i,const IntID& gu){fprintf_s(mFile,"connectAttr \"");gu.write(mFile);fprintf_s(mFile,"\" \"%s.gu[%i]\";\n",mName.c_str(),gu_i);}
	/*The group id for points associated with the lower bone.*/
	void setGroupIdLowerBindSkin(size_t gl_i,const IntID& gl){fprintf_s(mFile,"connectAttr \"");gl.write(mFile);fprintf_s(mFile,"\" \"%s.gl[%i]\";\n",mName.c_str(),gl_i);}
	/*Connected to the joint that owns the jointCluster node for the upper bone.*/
	void setUpperBindSkinNode(const MessageID& ub){fprintf_s(mFile,"connectAttr \"");ub.write(mFile);fprintf_s(mFile,"\" \"%s.ub\";\n",mName.c_str());}
	/*Connected to the joint that owns the jointCluster node for the lower bone.*/
	void setLowerBindSkinNode(const MessageID& lb){fprintf_s(mFile,"connectAttr \"");lb.write(mFile);fprintf_s(mFile,"\" \"%s.lb\";\n",mName.c_str());}
	/*Enable or disable the caching of component lists.*/
	void setUseComponentCache(bool uc){if(uc == true) return; fprintf_s(mFile, "setAttr \".uc\" %i;\n", uc);}
	/*Enable or disable the caching of component lists.*/
	void setUseComponentCache(const BoolID& uc){fprintf_s(mFile,"connectAttr \"");uc.write(mFile);fprintf_s(mFile,"\" \"%s.uc\";\n",mName.c_str());}
	/*The second base lattice needed for joint lattice flexors.*/
	MatrixID getBaseLattice2Matrix(){char buffer[4096];sprintf_s (buffer, "%s.b2",mName.c_str());return (const char*)buffer;}
	/*The group id for points associated with the upper bone.*/
	const IntID& getGroupIdUpperBindSkin(size_t gu_i){char buffer[4096];sprintf_s (buffer, "%s.gu[%i]",mName.c_str(),gu_i);return (const char*)buffer;}
	/*The group id for points associated with the lower bone.*/
	const IntID& getGroupIdLowerBindSkin(size_t gl_i){char buffer[4096];sprintf_s (buffer, "%s.gl[%i]",mName.c_str(),gl_i);return (const char*)buffer;}
	/*Connected to the joint that owns the jointCluster node for the upper bone.*/
	MessageID getUpperBindSkinNode(){char buffer[4096];sprintf_s (buffer, "%s.ub",mName.c_str());return (const char*)buffer;}
	/*Connected to the joint that owns the jointCluster node for the lower bone.*/
	MessageID getLowerBindSkinNode(){char buffer[4096];sprintf_s (buffer, "%s.lb",mName.c_str());return (const char*)buffer;}
	/*Enable or disable the caching of component lists.*/
	BoolID getUseComponentCache(){char buffer[4096];sprintf_s (buffer, "%s.uc",mName.c_str());return (const char*)buffer;}
protected:
	JointFfd(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Ffd(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_JOINTFFD_H__
