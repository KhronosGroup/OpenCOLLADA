/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyMapSewMove(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyMapSewMove"){}
	virtual ~PolyMapSewMove(){}
	void setLimitPieceSize(bool lps)
	{
		if(lps == false) return;
		fprintf(mFile,"setAttr \".lps\" %i;\n", lps);

	}
	void setNumberFaces(int nf)
	{
		if(nf == 10) return;
		fprintf(mFile,"setAttr \".nf\" %i;\n", nf);

	}
	void getLimitPieceSize()
	{
		fprintf(mFile,"\"%s.lps\"",mName.c_str());

	}
	void getNumberFaces()
	{
		fprintf(mFile,"\"%s.nf\"",mName.c_str());

	}
protected:
	PolyMapSewMove(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMAPSEWMOVE_H__
