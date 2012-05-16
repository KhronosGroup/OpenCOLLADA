/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMAPSEWMOVE_H__
#define __MayaDM_POLYMAPSEWMOVE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
class PolyMapSewMove : public PolyModifierUV
{
public:
public:

	PolyMapSewMove():PolyModifierUV(){}
	PolyMapSewMove(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, "polyMapSewMove", shared, create){}
	virtual ~PolyMapSewMove(){}

	void setLimitPieceSize(bool lps)
	{
		if(lps == false) return;
		fprintf(mFile,"\tsetAttr \".lps\" %i;\n", lps);
	}
	void setNumberFaces(int nf)
	{
		if(nf == 10) return;
		fprintf(mFile,"\tsetAttr \".nf\" %i;\n", nf);
	}
	void getLimitPieceSize()const
	{
		fprintf(mFile,"\"%s.lps\"",mName.c_str());
	}
	void getNumberFaces()const
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());
	}
protected:
	PolyMapSewMove(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMAPSEWMOVE_H__
