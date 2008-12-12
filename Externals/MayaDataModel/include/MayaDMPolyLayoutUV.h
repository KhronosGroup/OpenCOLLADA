/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYLAYOUTUV_H__
#define __MayaDM_POLYLAYOUTUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
/*
<p><pre> Move UVs in the texture plane to avoid overlaps.
</pre></p>
*/
class PolyLayoutUV : public PolyModifierUV
{
public:
public:
	PolyLayoutUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyLayoutUV"){}
	virtual ~PolyLayoutUV(){}
	/*Where to cut the pieces*/
	void setSeparate(unsigned int se){if(se == 0) return; fprintf_s(mFile, "setAttr \".se\" %i;\n", se);}
	/*Where to cut the pieces*/
	void setSeparate(const UnsignedintID& se){fprintf_s(mFile,"connectAttr \"");se.write(mFile);fprintf_s(mFile,"\" \"%s.se\";\n",mName.c_str());}
	/*Should reversed mapped areas be flipped*/
	void setFlipReversed(bool fr){if(fr == true) return; fprintf_s(mFile, "setAttr \".fr\" %i;\n", fr);}
	/*Should reversed mapped areas be flipped*/
	void setFlipReversed(const BoolID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*how to move the pieces*/
	void setLayout(unsigned int l){if(l == 2) return; fprintf_s(mFile, "setAttr \".l\" %i;\n", l);}
	/*how to move the pieces*/
	void setLayout(const UnsignedintID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	Extra space between UV pieces. Only used when moving
	pieces to a square. This is a percentage of the texture space.
	*/
	void setPercentageSpace(float ps){if(ps == 0) return; fprintf_s(mFile, "setAttr \".ps\" %f;\n", ps);}
	/*
	Extra space between UV pieces. Only used when moving
	pieces to a square. This is a percentage of the texture space.
	*/
	void setPercentageSpace(const FloatID& ps){fprintf_s(mFile,"connectAttr \"");ps.write(mFile);fprintf_s(mFile,"\" \"%s.ps\";\n",mName.c_str());}
	/*Scaling mode after UVs have been moved*/
	void setScale(unsigned int sc){if(sc == 1) return; fprintf_s(mFile, "setAttr \".sc\" %i;\n", sc);}
	/*Scaling mode after UVs have been moved*/
	void setScale(const UnsignedintID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*
	Optimize packing to reduce unused texture area. Hiden
	attribute for pre 3.0.1 file format compatibility
	*/
	void setDenseLayout(bool dl){if(dl == false) return; fprintf_s(mFile, "setAttr \".dl\" %i;\n", dl);}
	/*
	Optimize packing to reduce unused texture area. Hiden
	attribute for pre 3.0.1 file format compatibility
	*/
	void setDenseLayout(const BoolID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*How to rotate the pieces, before move.*/
	void setRotateForBestFit(unsigned int rbf){if(rbf == 0) return; fprintf_s(mFile, "setAttr \".rbf\" %i;\n", rbf);}
	/*How to rotate the pieces, before move.*/
	void setRotateForBestFit(const UnsignedintID& rbf){fprintf_s(mFile,"connectAttr \"");rbf.write(mFile);fprintf_s(mFile,"\" \"%s.rbf\";\n",mName.c_str());}
	/*How to rotate the pieces, before move.*/
	void setLayoutMethod(unsigned int lm){if(lm == 0) return; fprintf_s(mFile, "setAttr \".lm\" %i;\n", lm);}
	/*How to rotate the pieces, before move.*/
	void setLayoutMethod(const UnsignedintID& lm){fprintf_s(mFile,"connectAttr \"");lm.write(mFile);fprintf_s(mFile,"\" \"%s.lm\";\n",mName.c_str());}
	/*Where to cut the pieces*/
	UnsignedintID getSeparate(){char buffer[4096];sprintf_s (buffer, "%s.se",mName.c_str());return (const char*)buffer;}
	/*Should reversed mapped areas be flipped*/
	BoolID getFlipReversed(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
	/*how to move the pieces*/
	UnsignedintID getLayout(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	Extra space between UV pieces. Only used when moving
	pieces to a square. This is a percentage of the texture space.
	*/
	FloatID getPercentageSpace(){char buffer[4096];sprintf_s (buffer, "%s.ps",mName.c_str());return (const char*)buffer;}
	/*Scaling mode after UVs have been moved*/
	UnsignedintID getScale(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*
	Optimize packing to reduce unused texture area. Hiden
	attribute for pre 3.0.1 file format compatibility
	*/
	BoolID getDenseLayout(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*How to rotate the pieces, before move.*/
	UnsignedintID getRotateForBestFit(){char buffer[4096];sprintf_s (buffer, "%s.rbf",mName.c_str());return (const char*)buffer;}
	/*How to rotate the pieces, before move.*/
	UnsignedintID getLayoutMethod(){char buffer[4096];sprintf_s (buffer, "%s.lm",mName.c_str());return (const char*)buffer;}
protected:
	PolyLayoutUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYLAYOUTUV_H__
