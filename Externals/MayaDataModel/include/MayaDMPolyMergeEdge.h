/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMERGEEDGE_H__
#define __MayaDM_POLYMERGEEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Sews two border edges together. Both edges must belong to the same object,
 and orientations must match (i.e. normals of corresponding faces must
 point in the same direction).<p/>

 The new edge is located either on the first, second,
 or between both edges, depending on the mode.<p/>
*/
class PolyMergeEdge : public PolyModifier
{
public:
public:
	PolyMergeEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyMergeEdge"){}
	virtual ~PolyMergeEdge(){}
	/*Merge mode : 0=first, 1=halfway between both edges, 2=second.*/
	void setMergeMode(unsigned int mm){if(mm == 1) return; fprintf_s(mFile, "setAttr \".mm\" %i;\n", mm);}
	/*Merge mode : 0=first, 1=halfway between both edges, 2=second.*/
	void setMergeMode(const UnsignedintID& mm){fprintf_s(mFile,"connectAttr \"");mm.write(mFile);fprintf_s(mFile,"\" \"%s.mm\";\n",mName.c_str());}
	/*
	First edge to merge.
	Invalid default value to force the value to be set.
	*/
	void setFirstEdge(int fe){if(fe == -1) return; fprintf_s(mFile, "setAttr \".fe\" %i;\n", fe);}
	/*
	First edge to merge.
	Invalid default value to force the value to be set.
	*/
	void setFirstEdge(const IntID& fe){fprintf_s(mFile,"connectAttr \"");fe.write(mFile);fprintf_s(mFile,"\" \"%s.fe\";\n",mName.c_str());}
	/*
	Second edge to merge.
	Invalid default value to force the value to be set.
	*/
	void setSecondEdge(int se){if(se == -1) return; fprintf_s(mFile, "setAttr \".se\" %i;\n", se);}
	/*
	Second edge to merge.
	Invalid default value to force the value to be set.
	*/
	void setSecondEdge(const IntID& se){fprintf_s(mFile,"connectAttr \"");se.write(mFile);fprintf_s(mFile,"\" \"%s.se\";\n",mName.c_str());}
	/*
	Boolean which is used to decide if uv coordinates should be
	merged or not - along with the geometry.
	*/
	void setMergeTexture(bool mt){if(mt == false) return; fprintf_s(mFile, "setAttr \".mt\" %i;\n", mt);}
	/*
	Boolean which is used to decide if uv coordinates should be
	merged or not - along with the geometry.
	*/
	void setMergeTexture(const BoolID& mt){fprintf_s(mFile,"connectAttr \"");mt.write(mFile);fprintf_s(mFile,"\" \"%s.mt\";\n",mName.c_str());}
	/*Merge mode : 0=first, 1=halfway between both edges, 2=second.*/
	UnsignedintID getMergeMode(){char buffer[4096];sprintf_s (buffer, "%s.mm",mName.c_str());return (const char*)buffer;}
	/*
	First edge to merge.
	Invalid default value to force the value to be set.
	*/
	IntID getFirstEdge(){char buffer[4096];sprintf_s (buffer, "%s.fe",mName.c_str());return (const char*)buffer;}
	/*
	Second edge to merge.
	Invalid default value to force the value to be set.
	*/
	IntID getSecondEdge(){char buffer[4096];sprintf_s (buffer, "%s.se",mName.c_str());return (const char*)buffer;}
	/*
	Boolean which is used to decide if uv coordinates should be
	merged or not - along with the geometry.
	*/
	BoolID getMergeTexture(){char buffer[4096];sprintf_s (buffer, "%s.mt",mName.c_str());return (const char*)buffer;}
protected:
	PolyMergeEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMERGEEDGE_H__
