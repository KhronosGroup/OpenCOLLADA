/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDAUTOPROJ_H__
#define __MayaDM_SUBDAUTOPROJ_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdModifierUV.h"
namespace MayaDM
{
/*
<p><pre> Projects a map onto an object, using several orthogonal projections simultaneously.
</pre></p>
*/
class SubdAutoProj : public SubdModifierUV
{
public:
public:
	SubdAutoProj(FILE* file,const std::string& name,const std::string& parent=""):SubdModifierUV(file, name, parent, "subdAutoProj"){}
	virtual ~SubdAutoProj(){}
	/*How many projections*/
	void setPlanes(int p){if(p == 6) return; fprintf_s(mFile, "setAttr \".p\" %i;\n", p);}
	/*How many projections*/
	void setPlanes(const IntID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*Either fewer pieces, or more equaly distributed*/
	void setOptimize(unsigned int o){if(o == 1) return; fprintf_s(mFile, "setAttr \".o\" %i;\n", o);}
	/*Either fewer pieces, or more equaly distributed*/
	void setOptimize(const UnsignedintID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Do not check for auto intersections.*/
	void setSkipIntersect(bool si){if(si == false) return; fprintf_s(mFile, "setAttr \".si\" %i;\n", si);}
	/*Do not check for auto intersections.*/
	void setSkipIntersect(const BoolID& si){fprintf_s(mFile,"connectAttr \"");si.write(mFile);fprintf_s(mFile,"\" \"%s.si\";\n",mName.c_str());}
	/*how to move the pieces*/
	void setLayout(unsigned int l){if(l == 1) return; fprintf_s(mFile, "setAttr \".l\" %i;\n", l);}
	/*how to move the pieces*/
	void setLayout(const UnsignedintID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*How to rotate the pieces, before move.*/
	void setLayoutMethod(unsigned int lm){if(lm == 0) return; fprintf_s(mFile, "setAttr \".lm\" %i;\n", lm);}
	/*How to rotate the pieces, before move.*/
	void setLayoutMethod(const UnsignedintID& lm){fprintf_s(mFile,"connectAttr \"");lm.write(mFile);fprintf_s(mFile,"\" \"%s.lm\";\n",mName.c_str());}
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
	/*How many projections*/
	IntID getPlanes(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*Either fewer pieces, or more equaly distributed*/
	UnsignedintID getOptimize(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*Do not check for auto intersections.*/
	BoolID getSkipIntersect(){char buffer[4096];sprintf_s (buffer, "%s.si",mName.c_str());return (const char*)buffer;}
	/*how to move the pieces*/
	UnsignedintID getLayout(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*How to rotate the pieces, before move.*/
	UnsignedintID getLayoutMethod(){char buffer[4096];sprintf_s (buffer, "%s.lm",mName.c_str());return (const char*)buffer;}
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
protected:
	SubdAutoProj(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdModifierUV(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDAUTOPROJ_H__
