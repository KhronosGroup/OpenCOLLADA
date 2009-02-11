/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBSURFACE_H__
#define __MayaDM_SUBSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class SubSurface : public AbstractBaseCreate
{
public:
public:
	SubSurface():AbstractBaseCreate(){}
	SubSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "subSurface"){}
	virtual ~SubSurface(){}
	void setFirstFaceU(int ffu)
	{
		if(ffu == 0) return;
		fprintf(mFile,"\tsetAttr \".ffu\" %i;\n", ffu);

	}
	void setFirstFaceV(int ffv)
	{
		if(ffv == 0) return;
		fprintf(mFile,"\tsetAttr \".ffv\" %i;\n", ffv);

	}
	void setFaceCountU(int fcu)
	{
		if(fcu == 1) return;
		fprintf(mFile,"\tsetAttr \".fcu\" %i;\n", fcu);

	}
	void setFaceCountV(int fcv)
	{
		if(fcv == 1) return;
		fprintf(mFile,"\tsetAttr \".fcv\" %i;\n", fcv);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getFirstFaceU()
	{
		fprintf(mFile,"\"%s.ffu\"",mName.c_str());

	}
	void getFirstFaceV()
	{
		fprintf(mFile,"\"%s.ffv\"",mName.c_str());

	}
	void getFaceCountU()
	{
		fprintf(mFile,"\"%s.fcu\"",mName.c_str());

	}
	void getFaceCountV()
	{
		fprintf(mFile,"\"%s.fcv\"",mName.c_str());

	}
	void getOutputSurface()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
protected:
	SubSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBSURFACE_H__
