/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	NurbsToSubdiv(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseNurbsConversion(file, name, parent, "nurbsToSubdiv"){}
	virtual ~NurbsToSubdiv(){}
	void setMaxPolyCount(int mpc)
	{
		if(mpc == 1000) return;
		fprintf(mFile,"setAttr \".mpc\" %i;\n", mpc);

	}
	void setReverseNormal(bool rn)
	{
		if(rn == true) return;
		fprintf(mFile,"setAttr \".rn\" %i;\n", rn);

	}
	void setMatchPeriodic(bool mp)
	{
		if(mp == false) return;
		fprintf(mFile,"setAttr \".mp\" %i;\n", mp);

	}
	void setCollapsePoles(bool cp)
	{
		if(cp == false) return;
		fprintf(mFile,"setAttr \".cp\" %i;\n", cp);

	}
	void getInputSurface()
	{
		fprintf(mFile,"\"%s.is\"",mName.c_str());

	}
	void getOutputSubd()
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());

	}
	void getMaxPolyCount()
	{
		fprintf(mFile,"\"%s.mpc\"",mName.c_str());

	}
	void getReverseNormal()
	{
		fprintf(mFile,"\"%s.rn\"",mName.c_str());

	}
	void getMatchPeriodic()
	{
		fprintf(mFile,"\"%s.mp\"",mName.c_str());

	}
	void getCollapsePoles()
	{
		fprintf(mFile,"\"%s.cp\"",mName.c_str());

	}
protected:
	NurbsToSubdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseNurbsConversion(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSTOSUBDIV_H__
