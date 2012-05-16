/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FOURBYFOURMATRIX_H__
#define __MayaDM_FOURBYFOURMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class FourByFourMatrix : public DependNode
{
public:
public:

	FourByFourMatrix():DependNode(){}
	FourByFourMatrix(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "fourByFourMatrix", shared, create){}
	virtual ~FourByFourMatrix(){}

	void setIn00(double i00)
	{
		if(i00 == 1.0) return;
		fprintf(mFile,"\tsetAttr \".i00\" %f;\n", i00);
	}
	void setIn01(double i01)
	{
		if(i01 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i01\" %f;\n", i01);
	}
	void setIn02(double i02)
	{
		if(i02 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i02\" %f;\n", i02);
	}
	void setIn03(double i03)
	{
		if(i03 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i03\" %f;\n", i03);
	}
	void setIn10(double i10)
	{
		if(i10 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i10\" %f;\n", i10);
	}
	void setIn11(double i11)
	{
		if(i11 == 1.0) return;
		fprintf(mFile,"\tsetAttr \".i11\" %f;\n", i11);
	}
	void setIn12(double i12)
	{
		if(i12 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i12\" %f;\n", i12);
	}
	void setIn13(double i13)
	{
		if(i13 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i13\" %f;\n", i13);
	}
	void setIn20(double i20)
	{
		if(i20 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i20\" %f;\n", i20);
	}
	void setIn21(double i21)
	{
		if(i21 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i21\" %f;\n", i21);
	}
	void setIn22(double i22)
	{
		if(i22 == 1.0) return;
		fprintf(mFile,"\tsetAttr \".i22\" %f;\n", i22);
	}
	void setIn23(double i23)
	{
		if(i23 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i23\" %f;\n", i23);
	}
	void setIn30(double i30)
	{
		if(i30 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i30\" %f;\n", i30);
	}
	void setIn31(double i31)
	{
		if(i31 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i31\" %f;\n", i31);
	}
	void setIn32(double i32)
	{
		if(i32 == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i32\" %f;\n", i32);
	}
	void setIn33(double i33)
	{
		if(i33 == 1.0) return;
		fprintf(mFile,"\tsetAttr \".i33\" %f;\n", i33);
	}
	void getIn00()const
	{
		fprintf(mFile,"\"%s.i00\"",mName.c_str());
	}
	void getIn01()const
	{
		fprintf(mFile,"\"%s.i01\"",mName.c_str());
	}
	void getIn02()const
	{
		fprintf(mFile,"\"%s.i02\"",mName.c_str());
	}
	void getIn03()const
	{
		fprintf(mFile,"\"%s.i03\"",mName.c_str());
	}
	void getIn10()const
	{
		fprintf(mFile,"\"%s.i10\"",mName.c_str());
	}
	void getIn11()const
	{
		fprintf(mFile,"\"%s.i11\"",mName.c_str());
	}
	void getIn12()const
	{
		fprintf(mFile,"\"%s.i12\"",mName.c_str());
	}
	void getIn13()const
	{
		fprintf(mFile,"\"%s.i13\"",mName.c_str());
	}
	void getIn20()const
	{
		fprintf(mFile,"\"%s.i20\"",mName.c_str());
	}
	void getIn21()const
	{
		fprintf(mFile,"\"%s.i21\"",mName.c_str());
	}
	void getIn22()const
	{
		fprintf(mFile,"\"%s.i22\"",mName.c_str());
	}
	void getIn23()const
	{
		fprintf(mFile,"\"%s.i23\"",mName.c_str());
	}
	void getIn30()const
	{
		fprintf(mFile,"\"%s.i30\"",mName.c_str());
	}
	void getIn31()const
	{
		fprintf(mFile,"\"%s.i31\"",mName.c_str());
	}
	void getIn32()const
	{
		fprintf(mFile,"\"%s.i32\"",mName.c_str());
	}
	void getIn33()const
	{
		fprintf(mFile,"\"%s.i33\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	FourByFourMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FOURBYFOURMATRIX_H__
