/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_OBJECTSET_H__
#define __MayaDM_OBJECTSET_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMEntity.h"
namespace MayaDM
{
class ObjectSet : public Entity
{
public:
public:

	ObjectSet():Entity(){}
	ObjectSet(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Entity(file, name, parent, "objectSet", shared, create){}
	virtual ~ObjectSet(){}

	void setMemberWireframeColor(short mwc)
	{
		if(mwc == -1) return;
		fprintf(mFile,"\tsetAttr \".mwc\" %i;\n", mwc);
	}
	void setAnnotation(const string& an)
	{
		if(an == "NULL") return;
		fprintf(mFile,"\tsetAttr \".an\" -type \"string\" ");
		an.write(mFile);
		fprintf(mFile,";\n");
	}
	void setIsLayer(bool il)
	{
		if(il == false) return;
		fprintf(mFile,"\tsetAttr \".il\" %i;\n", il);
	}
	void setVerticesOnlySet(bool vo)
	{
		if(vo == false) return;
		fprintf(mFile,"\tsetAttr \".vo\" %i;\n", vo);
	}
	void setEdgesOnlySet(bool eo)
	{
		if(eo == false) return;
		fprintf(mFile,"\tsetAttr \".eo\" %i;\n", eo);
	}
	void setFacetsOnlySet(bool fo)
	{
		if(fo == false) return;
		fprintf(mFile,"\tsetAttr \".fo\" %i;\n", fo);
	}
	void setEditPointsOnlySet(bool epo)
	{
		if(epo == false) return;
		fprintf(mFile,"\tsetAttr \".epo\" %i;\n", epo);
	}
	void setRenderableOnlySet(bool ro)
	{
		if(ro == false) return;
		fprintf(mFile,"\tsetAttr \".ro\" %i;\n", ro);
	}
	void getDagSetMembers(size_t dsm_i)const
	{
		fprintf(mFile,"\"%s.dsm[%i]\"",mName.c_str(),dsm_i);
	}
	void getDagSetMembers()const
	{

		fprintf(mFile,"\"%s.dsm\"",mName.c_str());
	}
	void getDnSetMembers(size_t dnsm_i)const
	{
		fprintf(mFile,"\"%s.dnsm[%i]\"",mName.c_str(),dnsm_i);
	}
	void getDnSetMembers()const
	{

		fprintf(mFile,"\"%s.dnsm\"",mName.c_str());
	}
	void getMemberWireframeColor()const
	{
		fprintf(mFile,"\"%s.mwc\"",mName.c_str());
	}
	void getPartition()const
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());
	}
	void getGroupNodes(size_t gn_i)const
	{
		fprintf(mFile,"\"%s.gn[%i]\"",mName.c_str(),gn_i);
	}
	void getGroupNodes()const
	{

		fprintf(mFile,"\"%s.gn\"",mName.c_str());
	}
	void getUsedBy(size_t ub_i)const
	{
		fprintf(mFile,"\"%s.ub[%i]\"",mName.c_str(),ub_i);
	}
	void getUsedBy()const
	{

		fprintf(mFile,"\"%s.ub\"",mName.c_str());
	}
protected:
	ObjectSet(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Entity(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_OBJECTSET_H__
