/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DYNGLOBALS_H__
#define __MayaDM_DYNGLOBALS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DynGlobals : public DependNode
{
public:
public:

	DynGlobals():DependNode(){}
	DynGlobals(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "dynGlobals", shared, create){}
	virtual ~DynGlobals(){}

	void setOverSamples(int os)
	{
		if(os == 1) return;
		fprintf(mFile,"\tsetAttr \".os\" %i;\n", os);
	}
	void setUseParticleDiskCache(bool upd)
	{
		if(upd == 0) return;
		fprintf(mFile,"\tsetAttr \".upd\" %i;\n", upd);
	}
	void setCacheDirectory(const string& cd)
	{
		if(cd == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cd\" -type \"string\" ");
		cd.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMinFrameCached(int mnf)
	{
		if(mnf == 0) return;
		fprintf(mFile,"\tsetAttr \".mnf\" %i;\n", mnf);
	}
	void setMaxFrameCached(int mxf)
	{
		if(mxf == 0) return;
		fprintf(mFile,"\tsetAttr \".mxf\" %i;\n", mxf);
	}
	void setConfirmedPath(const string& cnp)
	{
		if(cnp == "NULL") return;
		fprintf(mFile,"\tsetAttr \".cnp\" -type \"string\" ");
		cnp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setConfirmSceneName(const string& csn)
	{
		if(csn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".csn\" -type \"string\" ");
		csn.write(mFile);
		fprintf(mFile,";\n");
	}
	void getOverSamples()const
	{
		fprintf(mFile,"\"%s.os\"",mName.c_str());
	}
	void getInternalOverSamples()const
	{
		fprintf(mFile,"\"%s.ios\"",mName.c_str());
	}
	void getUseParticleDiskCache()const
	{
		fprintf(mFile,"\"%s.upd\"",mName.c_str());
	}
	void getCacheDirectory()const
	{
		fprintf(mFile,"\"%s.cd\"",mName.c_str());
	}
	void getMinFrameCached()const
	{
		fprintf(mFile,"\"%s.mnf\"",mName.c_str());
	}
	void getMaxFrameCached()const
	{
		fprintf(mFile,"\"%s.mxf\"",mName.c_str());
	}
protected:
	DynGlobals(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DYNGLOBALS_H__
