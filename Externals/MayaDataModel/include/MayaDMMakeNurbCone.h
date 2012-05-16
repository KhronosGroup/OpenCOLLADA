/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKENURBCONE_H__
#define __MayaDM_MAKENURBCONE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMRevolvedPrimitive.h"
namespace MayaDM
{
class MakeNurbCone : public RevolvedPrimitive
{
public:
public:

	MakeNurbCone():RevolvedPrimitive(){}
	MakeNurbCone(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:RevolvedPrimitive(file, name, parent, "makeNurbCone", shared, create){}
	virtual ~MakeNurbCone(){}

	void setUseOldInitBehaviour(bool oib)
	{
		if(oib == false) return;
		fprintf(mFile,"\tsetAttr \".oib\" %i;\n", oib);
	}
	void getUseOldInitBehaviour()const
	{
		fprintf(mFile,"\"%s.oib\"",mName.c_str());
	}
protected:
	MakeNurbCone(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:RevolvedPrimitive(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MAKENURBCONE_H__
