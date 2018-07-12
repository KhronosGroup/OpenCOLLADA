/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REFERENCE_H__
#define __MayaDM_REFERENCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Reference : public DependNode
{
public:
	struct ConnectionList{
		void write(FILE* file) const
		{
		}
	};
	struct MultiParentList{
		void write(FILE* file) const
		{
		}
	};
public:

	Reference():DependNode(){}
	Reference(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "reference", shared, create){}
	virtual ~Reference(){}

	void setFileNames(size_t fn_i,const string& fn)
	{
		if(fn == "NULL") return;
		fprintf(mFile,"\tsetAttr \".fn[%i]\" -type \"string\" ",fn_i);
		fn.write(mFile);
		fprintf(mFile,";\n");
	}
	void setFileNames(size_t fn_start,size_t fn_end,string* fn)
	{
		fprintf(mFile,"\tsetAttr \".fn[%i:%i]\" ", fn_start,fn_end);
		size_t size = (fn_end-fn_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fn[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startFileNames(size_t fn_start,size_t fn_end)const
	{
		fprintf(mFile,"\tsetAttr \".fn[%i:%i]\"",fn_start,fn_end);
		fprintf(mFile," -type \"string\" ");
	}
	void appendFileNames(const string& fn)const
	{
		fprintf(mFile," ");
		fn.write(mFile);
	}
	void endFileNames()const
	{
		fprintf(mFile,";\n");
	}
	void setMultiParentList(size_t mpl_i,const MultiParentList& mpl)
	{
		fprintf(mFile,"\tsetAttr \".mpl[%i]\" ",mpl_i);
		mpl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMultiParentList(size_t mpl_start,size_t mpl_end,MultiParentList* mpl)
	{
		fprintf(mFile,"\tsetAttr \".mpl[%i:%i]\" ", mpl_start,mpl_end);
		size_t size = (mpl_end-mpl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			mpl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startMultiParentList(size_t mpl_start,size_t mpl_end)const
	{
		fprintf(mFile,"\tsetAttr \".mpl[%i:%i]\"",mpl_start,mpl_end);
		fprintf(mFile," -type \"MultiParentList\" ");
	}
	void appendMultiParentList(const MultiParentList& mpl)const
	{
		fprintf(mFile," ");
		mpl.write(mFile);
	}
	void endMultiParentList()const
	{
		fprintf(mFile,";\n");
	}
	void setProxyTag(const string& ptag)
	{
		if(ptag == "NULL") return;
		fprintf(mFile,"\tsetAttr \".ptag\" -type \"string\" ");
		ptag.write(mFile);
		fprintf(mFile,";\n");
	}
	void setLocked(bool lk)
	{
		if(lk == false) return;
		fprintf(mFile,"\tsetAttr \".lk\" %i;\n", lk);
	}
	void getFileNames(size_t fn_i)const
	{
		fprintf(mFile,"\"%s.fn[%i]\"",mName.c_str(),fn_i);
	}
	void getFileNames()const
	{

		fprintf(mFile,"\"%s.fn\"",mName.c_str());
	}
	void getConnectionList(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i]\"",mName.c_str(),cl_i);
	}
	void getConnectionList()const
	{

		fprintf(mFile,"\"%s.cl\"",mName.c_str());
	}
	void getConnectionAttr(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i].ca\"",mName.c_str(),cl_i);
	}
	void getConnectionAttr()const
	{

		fprintf(mFile,"\"%s.cl.ca\"",mName.c_str());
	}
	void getConnection(size_t cl_i)const
	{
		fprintf(mFile,"\"%s.cl[%i].c\"",mName.c_str(),cl_i);
	}
	void getConnection()const
	{

		fprintf(mFile,"\"%s.cl.c\"",mName.c_str());
	}
	void getSetAttrList(size_t sl_i)const
	{
		fprintf(mFile,"\"%s.sl[%i]\"",mName.c_str(),sl_i);
	}
	void getSetAttrList()const
	{

		fprintf(mFile,"\"%s.sl\"",mName.c_str());
	}
	void getAddAttrList(size_t al_i)const
	{
		fprintf(mFile,"\"%s.al[%i]\"",mName.c_str(),al_i);
	}
	void getAddAttrList()const
	{

		fprintf(mFile,"\"%s.al\"",mName.c_str());
	}
	void getDeleteAttrList(size_t dl_i)const
	{
		fprintf(mFile,"\"%s.dl[%i]\"",mName.c_str(),dl_i);
	}
	void getDeleteAttrList()const
	{

		fprintf(mFile,"\"%s.dl\"",mName.c_str());
	}
	void getBrokenConnectionList(size_t bl_i)const
	{
		fprintf(mFile,"\"%s.bl[%i]\"",mName.c_str(),bl_i);
	}
	void getBrokenConnectionList()const
	{

		fprintf(mFile,"\"%s.bl\"",mName.c_str());
	}
	void getParentList(size_t pl_i)const
	{
		fprintf(mFile,"\"%s.pl[%i]\"",mName.c_str(),pl_i);
	}
	void getParentList()const
	{

		fprintf(mFile,"\"%s.pl\"",mName.c_str());
	}
	void getFosterParent()const
	{
		fprintf(mFile,"\"%s.fp\"",mName.c_str());
	}
	void getFosterSiblings(size_t fs_i)const
	{
		fprintf(mFile,"\"%s.fs[%i]\"",mName.c_str(),fs_i);
	}
	void getFosterSiblings()const
	{

		fprintf(mFile,"\"%s.fs\"",mName.c_str());
	}
	void getPlaceHolderList(size_t phl_i)const
	{
		fprintf(mFile,"\"%s.phl[%i]\"",mName.c_str(),phl_i);
	}
	void getPlaceHolderList()const
	{

		fprintf(mFile,"\"%s.phl\"",mName.c_str());
	}
	void getMultiParentList(size_t mpl_i)const
	{
		fprintf(mFile,"\"%s.mpl[%i]\"",mName.c_str(),mpl_i);
	}
	void getMultiParentList()const
	{

		fprintf(mFile,"\"%s.mpl\"",mName.c_str());
	}
	void getMultiParent(size_t mpl_i,size_t mp_i)const
	{
		fprintf(mFile,"\"%s.mpl[%i].mp[%i]\"",mName.c_str(),mpl_i,mp_i);
	}
	void getMultiParent(size_t mp_i)const
	{

		fprintf(mFile,"\"%s.mpl.mp[%i]\"",mName.c_str(),mp_i);
	}
	void getEdits()const
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());
	}
	void getProxyTag()const
	{
		fprintf(mFile,"\"%s.ptag\"",mName.c_str());
	}
	void getProxyMsg()const
	{
		fprintf(mFile,"\"%s.pmsg\"",mName.c_str());
	}
	void getUnknownReference()const
	{
		fprintf(mFile,"\"%s.ur\"",mName.c_str());
	}
	void getSharedReference()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getLocked()const
	{
		fprintf(mFile,"\"%s.lk\"",mName.c_str());
	}
protected:
	Reference(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_REFERENCE_H__
