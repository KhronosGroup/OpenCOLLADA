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
/*
<p><pre> This node is used to Move and Sew together separate UV pieces
 along geometric edges.
 UV pieces that correspond to the same geometric edge are merged
 together by moving the smaller piece to the larger one.
</pre></p>
*/
class PolyMapSewMove : public PolyModifierUV
{
public:
public:
	PolyMapSewMove(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyMapSewMove"){}
	virtual ~PolyMapSewMove(){}
	/*Enable/disable the numberFaces threshold.*/
	void setLimitPieceSize(bool lps){if(lps == false) return; fprintf_s(mFile, "setAttr \".lps\" %i;\n", lps);}
	/*Enable/disable the numberFaces threshold.*/
	void setLimitPieceSize(const BoolID& lps){fprintf_s(mFile,"connectAttr \"");lps.write(mFile);fprintf_s(mFile,"\" \"%s.lps\";\n",mName.c_str());}
	/*Maximum number of faces in an area to accept merge.*/
	void setNumberFaces(int nf){if(nf == 10) return; fprintf_s(mFile, "setAttr \".nf\" %i;\n", nf);}
	/*Maximum number of faces in an area to accept merge.*/
	void setNumberFaces(const IntID& nf){fprintf_s(mFile,"connectAttr \"");nf.write(mFile);fprintf_s(mFile,"\" \"%s.nf\";\n",mName.c_str());}
	/*Enable/disable the numberFaces threshold.*/
	BoolID getLimitPieceSize(){char buffer[4096];sprintf_s (buffer, "%s.lps",mName.c_str());return (const char*)buffer;}
	/*Maximum number of faces in an area to accept merge.*/
	IntID getNumberFaces(){char buffer[4096];sprintf_s (buffer, "%s.nf",mName.c_str());return (const char*)buffer;}
protected:
	PolyMapSewMove(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMAPSEWMOVE_H__
