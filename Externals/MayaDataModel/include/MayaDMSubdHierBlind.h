/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDHIERBLIND_H__
#define __MayaDM_SUBDHIERBLIND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBlindDataTemplate.h"
namespace MayaDM
{
/*
Special case of a blind data template node.  Used as a template
 node for the blind data on the polygons that holds hierarchical
 edits for subdivision surfaces.
*/
class SubdHierBlind : public BlindDataTemplate
{
public:
public:
	SubdHierBlind(FILE* file,const std::string& name,const std::string& parent=""):BlindDataTemplate(file, name, parent, "subdHierBlind"){}
	virtual ~SubdHierBlind(){}
	/*
	This gives us a way to know the number of attributes on this template
	node without actually counting them.  There will be 5 * 2^woi
	attributes available. The maximum number of attributes is 5 * 2^6.
	If the value of this attribute is greater than 6, then it means
	that this is a node with the same number of attributes (as one
	with woi = 6), but with a different typeId - blindData mechanism in
	maya disallows having multiple subdHierBlind nodes with the same typeId.
	*/
	void setWhichOneIndex(int woi){if(woi == -1) return; fprintf_s(mFile, "setAttr \".woi\" %i;\n", woi);}
protected:
	SubdHierBlind(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BlindDataTemplate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDHIERBLIND_H__
