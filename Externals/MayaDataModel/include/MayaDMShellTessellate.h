/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHELLTESSELLATE_H__
#define __MayaDM_SHELLTESSELLATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMParentTessellate.h"
namespace MayaDM
{
class ShellTessellate : public ParentTessellate
{
public:
public:

	ShellTessellate():ParentTessellate(){}
	ShellTessellate(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:ParentTessellate(file, name, parent, "shellTessellate", shared, create){}
	virtual ~ShellTessellate(){}

	void getInputShell()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
protected:
	ShellTessellate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:ParentTessellate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SHELLTESSELLATE_H__
