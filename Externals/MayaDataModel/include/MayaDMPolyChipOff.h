/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCHIPOFF_H__
#define __MayaDM_POLYCHIPOFF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyMoveFace.h"
namespace MayaDM
{
class PolyChipOff : public PolyMoveFace
{
public:
public:

	PolyChipOff():PolyMoveFace(){}
	PolyChipOff(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyMoveFace(file, name, parent, "polyChipOff", shared, create){}
	virtual ~PolyChipOff(){}

	void setKeepFacesTogether(bool kft)
	{
		if(kft == true) return;
		fprintf(mFile,"\tsetAttr \".kft\" %i;\n", kft);
	}
	void setDuplicate(bool dup)
	{
		if(dup == true) return;
		fprintf(mFile,"\tsetAttr \".dup\" %i;\n", dup);
	}
	void getKeepFacesTogether()const
	{
		fprintf(mFile,"\"%s.kft\"",mName.c_str());
	}
	void getDuplicate()const
	{
		fprintf(mFile,"\"%s.dup\"",mName.c_str());
	}
protected:
	PolyChipOff(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyMoveFace(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCHIPOFF_H__
