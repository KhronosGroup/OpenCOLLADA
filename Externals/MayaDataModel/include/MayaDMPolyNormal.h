/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYNORMAL_H__
#define __MayaDM_POLYNORMAL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyNormal : public PolyModifier
{
public:
public:
	PolyNormal():PolyModifier(){}
	PolyNormal(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:PolyModifier(file, name, parent, "polyNormal", create){}
	virtual ~PolyNormal(){}
	void setNormalMode(unsigned int nm)
	{
		if(nm == 0) return;
		fprintf(mFile,"\tsetAttr \".nm\" %i;\n", nm);

	}
	void setUserNormalMode(bool unm)
	{
		if(unm == true) return;
		fprintf(mFile,"\tsetAttr \".unm\" %i;\n", unm);

	}
	void getNormalMode()const
	{
		fprintf(mFile,"\"%s.nm\"",mName.c_str());

	}
	void getUserNormalMode()const
	{
		fprintf(mFile,"\"%s.unm\"",mName.c_str());

	}
protected:
	PolyNormal(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:PolyModifier(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYNORMAL_H__
