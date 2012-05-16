/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVENORMALIZER_H__
#define __MayaDM_CURVENORMALIZER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class CurveNormalizer : public DependNode
{
public:
public:

	CurveNormalizer():DependNode(){}
	CurveNormalizer(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "curveNormalizer", shared, create){}
	virtual ~CurveNormalizer(){}

	void setScalar(double sc)
	{
		if(sc == 1.0) return;
		fprintf(mFile,"\tsetAttr \".sc\" %f;\n", sc);
	}
	void getScalar()const
	{
		fprintf(mFile,"\"%s.sc\"",mName.c_str());
	}
protected:
	CurveNormalizer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVENORMALIZER_H__
