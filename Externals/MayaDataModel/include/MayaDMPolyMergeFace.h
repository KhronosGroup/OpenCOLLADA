/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMERGEFACE_H__
#define __MayaDM_POLYMERGEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
Merges two facets. The second face becomes a hole in the first.<p/>

 Both faces must belong to the same object.
 The new holed face is located either on the first, second,
 or between both faces, depending on the mergeMode.<p/>
*/
class PolyMergeFace : public PolyModifier
{
public:
public:
	PolyMergeFace(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyMergeFace"){}
	virtual ~PolyMergeFace(){}
	/*How to merge : 0=first, 1=halfway between both faces, 2=second.*/
	void setMergeMode(unsigned int mm){if(mm == 6) return; fprintf_s(mFile, "setAttr \".mm\" %i;\n", mm);}
	/*How to merge : 0=first, 1=halfway between both faces, 2=second.*/
	void setMergeMode(const UnsignedintID& mm){fprintf_s(mFile,"connectAttr \"");mm.write(mFile);fprintf_s(mFile,"\" \"%s.mm\";\n",mName.c_str());}
	/*
	Attribute to specify if the area comparison uses a tolerance
	for the evaluation of this node. SHOULD NOT BE SET OR MODIFIED
	BY THE USER!!
	*/
	void setUseAreaTolerance(bool uat){if(uat == true) return; fprintf_s(mFile, "setAttr \".uat\" %i;\n", uat);}
	/*
	First face to merge.
	Invalid default value to force the value to be set.
	*/
	void setFirstFacet(int ff){if(ff == -1) return; fprintf_s(mFile, "setAttr \".ff\" %i;\n", ff);}
	/*
	First face to merge.
	Invalid default value to force the value to be set.
	*/
	void setFirstFacet(const IntID& ff){fprintf_s(mFile,"connectAttr \"");ff.write(mFile);fprintf_s(mFile,"\" \"%s.ff\";\n",mName.c_str());}
	/*
	Second face to merge.
	Invalid default value to force the value to be set.
	*/
	void setSecondFacet(int sf){if(sf == -1) return; fprintf_s(mFile, "setAttr \".sf\" %i;\n", sf);}
	/*
	Second face to merge.
	Invalid default value to force the value to be set.
	*/
	void setSecondFacet(const IntID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sf\";\n",mName.c_str());}
	/*How to merge : 0=first, 1=halfway between both faces, 2=second.*/
	UnsignedintID getMergeMode(){char buffer[4096];sprintf_s (buffer, "%s.mm",mName.c_str());return (const char*)buffer;}
	/*
	First face to merge.
	Invalid default value to force the value to be set.
	*/
	IntID getFirstFacet(){char buffer[4096];sprintf_s (buffer, "%s.ff",mName.c_str());return (const char*)buffer;}
	/*
	Second face to merge.
	Invalid default value to force the value to be set.
	*/
	IntID getSecondFacet(){char buffer[4096];sprintf_s (buffer, "%s.sf",mName.c_str());return (const char*)buffer;}
protected:
	PolyMergeFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMERGEFACE_H__
