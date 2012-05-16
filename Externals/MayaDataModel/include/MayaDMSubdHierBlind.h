/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class SubdHierBlind : public BlindDataTemplate
{
public:
public:

	SubdHierBlind():BlindDataTemplate(){}
	SubdHierBlind(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:BlindDataTemplate(file, name, parent, "subdHierBlind", shared, create){}
	virtual ~SubdHierBlind(){}

	void setWhichOneIndex(int woi)
	{
		if(woi == -1) return;
		fprintf(mFile,"\tsetAttr \".woi\" %i;\n", woi);
	}
protected:
	SubdHierBlind(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:BlindDataTemplate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDHIERBLIND_H__
