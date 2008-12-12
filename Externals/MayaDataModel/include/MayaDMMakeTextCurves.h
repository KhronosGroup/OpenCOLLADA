/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKETEXTCURVES_H__
#define __MayaDM_MAKETEXTCURVES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Create curves for the given text using the specified font. The text string
 can be any number of characters typed in from the keyboard. The font is any
 type available on the users machine.
 <br/>
 Each character of the created text string can be made up of many curves. For
 example, the letter "O" in font type "Times-Roman" would be created with 2
 curves: one small O curve inside another larger O curve.
 <p/>
*/
class MakeTextCurves : public AbstractBaseCreate
{
public:
public:
	MakeTextCurves(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "makeTextCurves"){}
	virtual ~MakeTextCurves(){}
	/*Text characters to be created.*/
	void setText(const string& t){if(t == "Maya") return; fprintf_s(mFile, "setAttr \".t\" -type \"string\" ");t.write(mFile);fprintf_s(mFile,";\n");}
	/*Text characters to be created.*/
	void setText(const StringID& t){fprintf_s(mFile,"connectAttr \"");t.write(mFile);fprintf_s(mFile,"\" \"%s.t\";\n",mName.c_str());}
	/*Font type for creating the text.*/
	void setFont(const string& f){if(f == "Times-Roman") return; fprintf_s(mFile, "setAttr \".f\" -type \"string\" ");f.write(mFile);fprintf_s(mFile,";\n");}
	/*Font type for creating the text.*/
	void setFont(const StringID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Output curves for the whole text string.*/
	void setOutputCurve(size_t oc_i,const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc[%i]\";\n",mName.c_str(),oc_i);}
	/*
	Offsets for each character of the created text string.
	The value is specified in the current distance units.
	*/
	void setPosition(size_t p_i,const Double3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i]\";\n",mName.c_str(),p_i);}
	/*Offsets for each character in X.*/
	void setPositionX(size_t p_i,const DoubleID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].px\";\n",mName.c_str(),p_i);}
	/*Offsets for each character in Y.*/
	void setPositionY(size_t p_i,const DoubleID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].py\";\n",mName.c_str(),p_i);}
	/*Offsets for each character in Z.*/
	void setPositionZ(size_t p_i,const DoubleID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p[%i].pz\";\n",mName.c_str(),p_i);}
	/*
	The number of curves for each created text character.
	There is an entry for each character in the string, and the value
	should be the number of curves in that character.
	*/
	void setCount(size_t c_i,const IntID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c[%i]\";\n",mName.c_str(),c_i);}
	/*Text characters to be created.*/
	StringID getText(){char buffer[4096];sprintf_s (buffer, "%s.t",mName.c_str());return (const char*)buffer;}
	/*Font type for creating the text.*/
	StringID getFont(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Output curves for the whole text string.*/
	const NurbsCurveID& getOutputCurve(size_t oc_i){char buffer[4096];sprintf_s (buffer, "%s.oc[%i]",mName.c_str(),oc_i);return (const char*)buffer;}
	/*
	Offsets for each character of the created text string.
	The value is specified in the current distance units.
	*/
	const Double3ID& getPosition(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i]",mName.c_str(),p_i);return (const char*)buffer;}
	/*Offsets for each character in X.*/
	const DoubleID& getPositionX(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].px",mName.c_str(),p_i);return (const char*)buffer;}
	/*Offsets for each character in Y.*/
	const DoubleID& getPositionY(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].py",mName.c_str(),p_i);return (const char*)buffer;}
	/*Offsets for each character in Z.*/
	const DoubleID& getPositionZ(size_t p_i){char buffer[4096];sprintf_s (buffer, "%s.p[%i].pz",mName.c_str(),p_i);return (const char*)buffer;}
	/*
	The number of curves for each created text character.
	There is an entry for each character in the string, and the value
	should be the number of curves in that character.
	*/
	const IntID& getCount(size_t c_i){char buffer[4096];sprintf_s (buffer, "%s.c[%i]",mName.c_str(),c_i);return (const char*)buffer;}
protected:
	MakeTextCurves(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKETEXTCURVES_H__
