/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Reference(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "reference"){}
	virtual ~Reference(){}
	void setFileNames(size_t fn_i,const string& fn)
	{
		if(fn == "NULL") return;
		fprintf(mFile,"setAttr \".fn[%i]\" -type \"string\" ",fn_i);
		fn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMultiParentList(size_t mpl_i,const MultiParentList& mpl)
	{
		fprintf(mFile,"setAttr \".mpl[%i]\" ",mpl_i);
		mpl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setProxyTag(const string& ptag)
	{
		if(ptag == "NULL") return;
		fprintf(mFile,"setAttr \".ptag\" -type \"string\" ");
		ptag.write(mFile);
		fprintf(mFile,";\n");

	}
	void setLocked(bool lk)
	{
		if(lk == false) return;
		fprintf(mFile,"setAttr \".lk\" %i;\n", lk);

	}
	void getFileNames(size_t fn_i)
	{
		fprintf(mFile,"\"%s.fn[%i]\"",mName.c_str(),fn_i);

	}
	void getConnectionList(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i]\"",mName.c_str(),cl_i);

	}
	void getConnectionAttr(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].ca\"",mName.c_str(),cl_i);

	}
	void getConnection(size_t cl_i)
	{
		fprintf(mFile,"\"%s.cl[%i].c\"",mName.c_str(),cl_i);

	}
	void getSetAttrList(size_t sl_i)
	{
		fprintf(mFile,"\"%s.sl[%i]\"",mName.c_str(),sl_i);

	}
	void getAddAttrList(size_t al_i)
	{
		fprintf(mFile,"\"%s.al[%i]\"",mName.c_str(),al_i);

	}
	void getDeleteAttrList(size_t dl_i)
	{
		fprintf(mFile,"\"%s.dl[%i]\"",mName.c_str(),dl_i);

	}
	void getBrokenConnectionList(size_t bl_i)
	{
		fprintf(mFile,"\"%s.bl[%i]\"",mName.c_str(),bl_i);

	}
	void getParentList(size_t pl_i)
	{
		fprintf(mFile,"\"%s.pl[%i]\"",mName.c_str(),pl_i);

	}
	void getPlaceHolderList(size_t phl_i)
	{
		fprintf(mFile,"\"%s.phl[%i]\"",mName.c_str(),phl_i);

	}
	void getMultiParentList(size_t mpl_i)
	{
		fprintf(mFile,"\"%s.mpl[%i]\"",mName.c_str(),mpl_i);

	}
	void getMultiParent(size_t mpl_i,size_t mp_i)
	{
		fprintf(mFile,"\"%s.mpl[%i].mp[%i]\"",mName.c_str(),mpl_i,mp_i);

	}
	void getEdits()
	{
		fprintf(mFile,"\"%s.ed\"",mName.c_str());

	}
	void getProxyTag()
	{
		fprintf(mFile,"\"%s.ptag\"",mName.c_str());

	}
	void getProxyMsg()
	{
		fprintf(mFile,"\"%s.pmsg\"",mName.c_str());

	}
	void getUnknownReference()
	{
		fprintf(mFile,"\"%s.ur\"",mName.c_str());

	}
	void getSharedReference()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getLocked()
	{
		fprintf(mFile,"\"%s.lk\"",mName.c_str());

	}
protected:
	Reference(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_REFERENCE_H__
