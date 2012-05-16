/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FILTER_H__
#define __MayaDM_FILTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Filter : public DependNode
{
public:
	struct Input{
		void write(FILE* file) const
		{
		}
	};
	struct Output{
		void write(FILE* file) const
		{
		}
	};
public:

	Filter():DependNode(){}
	Filter(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "filter", shared, create){}
	virtual ~Filter(){}

	void setDeviceEditorActive(bool dea)
	{
		if(dea == false) return;
		fprintf(mFile,"\tsetAttr \".dea\" %i;\n", dea);
	}
	void getDeviceEditorActive()const
	{
		fprintf(mFile,"\"%s.dea\"",mName.c_str());
	}
protected:
	Filter(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FILTER_H__
