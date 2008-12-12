/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVCOMPONENTID_H__
#define __MayaDM_SUBDIVCOMPONENTID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
*/
class SubdivComponentId : public DependNode
{
public:
public:
	SubdivComponentId(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdivComponentId"){}
	virtual ~SubdivComponentId(){}
	/*The index of the base mesh face*/
	void setInBase(int ib){if(ib == 0) return; fprintf_s(mFile, "setAttr \".ib\" %i;\n", ib);}
	/*The index of the base mesh face*/
	void setInBase(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*The index of the level 1 face within a given base face*/
	void setInEdge(int ie){if(ie == 0) return; fprintf_s(mFile, "setAttr \".ie\" %i;\n", ie);}
	/*The index of the level 1 face within a given base face*/
	void setInEdge(const IntID& ie){fprintf_s(mFile,"connectAttr \"");ie.write(mFile);fprintf_s(mFile,"\" \"%s.ie\";\n",mName.c_str());}
	/*The level for the face/edge/vertex.*/
	void setInLevel(unsigned int il){if(il == 0) return; fprintf_s(mFile, "setAttr \".il\" %i;\n", il);}
	/*The level for the face/edge/vertex.*/
	void setInLevel(const UnsignedintID& il){fprintf_s(mFile,"connectAttr \"");il.write(mFile);fprintf_s(mFile,"\" \"%s.il\";\n",mName.c_str());}
	/*
	The path as to how to get to the face/edge/vertex at the specified
	level.  Each level takes two bits which are used to give us one of
	the four possible choices (all level 1 faces are four sided).
	*/
	void setInPath(int ip){if(ip == 0) return; fprintf_s(mFile, "setAttr \".ip\" %i;\n", ip);}
	/*
	The path as to how to get to the face/edge/vertex at the specified
	level.  Each level takes two bits which are used to give us one of
	the four possible choices (all level 1 faces are four sided).
	*/
	void setInPath(const IntID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip\";\n",mName.c_str());}
	/*
	Once the face is determined, we have to specify one of the four
	possible choices for the vertex or an edge.  This is zero (ignored)
	for the face.
	*/
	void setInFinal(unsigned int if_){if(if_ == 0) return; fprintf_s(mFile, "setAttr \".if\" %i;\n", if_);}
	/*
	Once the face is determined, we have to specify one of the four
	possible choices for the vertex or an edge.  This is zero (ignored)
	for the face.
	*/
	void setInFinal(const UnsignedintID& if_){fprintf_s(mFile,"connectAttr \"");if_.write(mFile);fprintf_s(mFile,"\" \"%s.if\";\n",mName.c_str());}
	/*Left index output (used in the selection items and file I/O)*/
	void setOutLeft(const IntID& olt){fprintf_s(mFile,"connectAttr \"");olt.write(mFile);fprintf_s(mFile,"\" \"%s.olt\";\n",mName.c_str());}
	/*Right index output (used in the selection items and file I/O)*/
	void setOutRight(const IntID& or){fprintf_s(mFile,"connectAttr \"");or.write(mFile);fprintf_s(mFile,"\" \"%s.or\";\n",mName.c_str());}
	/*Left index output (used in the selection items and file I/O)*/
	void setInLeft(int ilt){if(ilt == 0) return; fprintf_s(mFile, "setAttr \".ilt\" %i;\n", ilt);}
	/*Left index output (used in the selection items and file I/O)*/
	void setInLeft(const IntID& ilt){fprintf_s(mFile,"connectAttr \"");ilt.write(mFile);fprintf_s(mFile,"\" \"%s.ilt\";\n",mName.c_str());}
	/*Right index output (used in the selection items and file I/O)*/
	void setInRight(int ir){if(ir == 0) return; fprintf_s(mFile, "setAttr \".ir\" %i;\n", ir);}
	/*Right index output (used in the selection items and file I/O)*/
	void setInRight(const IntID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.ir\";\n",mName.c_str());}
	/*The index of the base mesh face*/
	void setOutBase(const IntID& ob){fprintf_s(mFile,"connectAttr \"");ob.write(mFile);fprintf_s(mFile,"\" \"%s.ob\";\n",mName.c_str());}
	/*The index of the level 1 face within a given base face*/
	void setOutEdge(const IntID& oe){fprintf_s(mFile,"connectAttr \"");oe.write(mFile);fprintf_s(mFile,"\" \"%s.oe\";\n",mName.c_str());}
	/*The level for the face/edge/vertex.*/
	void setOutLevel(const UnsignedintID& ol){fprintf_s(mFile,"connectAttr \"");ol.write(mFile);fprintf_s(mFile,"\" \"%s.ol\";\n",mName.c_str());}
	/*
	The path as to how to get to the face/edge/vertex at the specified
	level.  Each level takes two bits which are used to give us one of
	the four possible choices (all level 1 faces are four sided).
	*/
	void setOutPath(const IntID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*
	Once the face is determined, we have to specify one of the four
	possible choices for the vertex or an edge.  This is zero (ignored)
	for the face.
	*/
	void setOutFinal(const UnsignedintID& of){fprintf_s(mFile,"connectAttr \"");of.write(mFile);fprintf_s(mFile,"\" \"%s.of\";\n",mName.c_str());}
	/*The index of the base mesh face*/
	IntID getInBase(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
	/*The index of the level 1 face within a given base face*/
	IntID getInEdge(){char buffer[4096];sprintf_s (buffer, "%s.ie",mName.c_str());return (const char*)buffer;}
	/*The level for the face/edge/vertex.*/
	UnsignedintID getInLevel(){char buffer[4096];sprintf_s (buffer, "%s.il",mName.c_str());return (const char*)buffer;}
	/*
	The path as to how to get to the face/edge/vertex at the specified
	level.  Each level takes two bits which are used to give us one of
	the four possible choices (all level 1 faces are four sided).
	*/
	IntID getInPath(){char buffer[4096];sprintf_s (buffer, "%s.ip",mName.c_str());return (const char*)buffer;}
	/*
	Once the face is determined, we have to specify one of the four
	possible choices for the vertex or an edge.  This is zero (ignored)
	for the face.
	*/
	UnsignedintID getInFinal(){char buffer[4096];sprintf_s (buffer, "%s.if",mName.c_str());return (const char*)buffer;}
	/*Left index output (used in the selection items and file I/O)*/
	IntID getOutLeft(){char buffer[4096];sprintf_s (buffer, "%s.olt",mName.c_str());return (const char*)buffer;}
	/*Right index output (used in the selection items and file I/O)*/
	IntID getOutRight(){char buffer[4096];sprintf_s (buffer, "%s.or",mName.c_str());return (const char*)buffer;}
	/*Left index output (used in the selection items and file I/O)*/
	IntID getInLeft(){char buffer[4096];sprintf_s (buffer, "%s.ilt",mName.c_str());return (const char*)buffer;}
	/*Right index output (used in the selection items and file I/O)*/
	IntID getInRight(){char buffer[4096];sprintf_s (buffer, "%s.ir",mName.c_str());return (const char*)buffer;}
	/*The index of the base mesh face*/
	IntID getOutBase(){char buffer[4096];sprintf_s (buffer, "%s.ob",mName.c_str());return (const char*)buffer;}
	/*The index of the level 1 face within a given base face*/
	IntID getOutEdge(){char buffer[4096];sprintf_s (buffer, "%s.oe",mName.c_str());return (const char*)buffer;}
	/*The level for the face/edge/vertex.*/
	UnsignedintID getOutLevel(){char buffer[4096];sprintf_s (buffer, "%s.ol",mName.c_str());return (const char*)buffer;}
	/*
	The path as to how to get to the face/edge/vertex at the specified
	level.  Each level takes two bits which are used to give us one of
	the four possible choices (all level 1 faces are four sided).
	*/
	IntID getOutPath(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*
	Once the face is determined, we have to specify one of the four
	possible choices for the vertex or an edge.  This is zero (ignored)
	for the face.
	*/
	UnsignedintID getOutFinal(){char buffer[4096];sprintf_s (buffer, "%s.of",mName.c_str());return (const char*)buffer;}
protected:
	SubdivComponentId(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVCOMPONENTID_H__
