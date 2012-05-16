/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSTOSUBDIV_H__
#define __MayaDM_NURBSTOSUBDIV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseNurbsConversion.h"
namespace MayaDM
{
class NurbsToSubdiv : public AbstractBaseNurbsConversion
{
public:
public:

	NurbsToSubdiv():AbstractBaseNurbsConversion(){}
	NurbsToSubdiv(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseNurbsConversion(file, name, parent, "nurbsToSubdiv", shared, create){}
	virtual ~NurbsToSubdiv(){}

	void setMaxPolyCount(int mpc)
	{
		if(mpc == 1000) return;
		fprintf(mFile,"\tsetAttr \".mpc\" %i;\n", mpc);
	}
	void setReverseNormal(bool rn)
	{
		if(rn == true) return;
		fprintf(mFile,"\tsetAttr \".rn\" %i;\n", rn);
	}
	void setMatchPeriodic(bool mp)
	{
		if(mp == false) return;
		fprintf(mFile,"\tsetAttr \".mp\" %i;\n", mp);
	}
	void setCollapsePoles(bool cp)
	{
		if(cp == false) return;
		fprintf(mFile,"\tsetAttr \".cp\" %i;\n", cp);
	}
	void getInputSurface()const
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());
	}
	void getOutputSubd()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getMaxPolyCount()const
	{
		fprintf(mFile,"\"%s.mpc\"",mName.c_str());
	}
	void getReverseNormal()const
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());
	}
	void getMatchPeriodic()const
	{
		fprintf(mFile,"\"%s.mp\"",mName.c_str());
	}
	void getCollapsePoles()const
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());
	}
protected:
	NurbsToSubdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseNurbsConversion(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSTOSUBDIV_H__
