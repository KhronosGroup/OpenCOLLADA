/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKEILLUSTRATORCURVES_H__
#define __MayaDM_MAKEILLUSTRATORCURVES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*Create curves or bevel surfaces from an input Adobe(R) Illustrator(R) file*/
class MakeIllustratorCurves : public AbstractBaseCreate
{
public:
public:
	MakeIllustratorCurves(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "makeIllustratorCurves"){}
	virtual ~MakeIllustratorCurves(){}
	/*Input Adobe(R) Illustrator(R) filename.*/
	void setIllustratorFilename(const string& ifn){if(ifn == "NULL") return; fprintf_s(mFile, "setAttr \".ifn\" -type \"string\" ");ifn.write(mFile);fprintf_s(mFile,";\n");}
	/*Input Adobe(R) Illustrator(R) filename.*/
	void setIllustratorFilename(const StringID& ifn){fprintf_s(mFile,"connectAttr \"");ifn.write(mFile);fprintf_s(mFile,"\" \"%s.ifn\";\n",mName.c_str());}
	/*Scale Factor*/
	void setScaleFactor(float sf){if(sf == 1.0f) return; fprintf_s(mFile, "setAttr \".sf\" %f;\n", sf);}
	/*Scale Factor*/
	void setScaleFactor(const FloatID& sf){fprintf_s(mFile,"connectAttr \"");sf.write(mFile);fprintf_s(mFile,"\" \"%s.sf\";\n",mName.c_str());}
	/*Used to reload the same Adobe(R) Illustrator(R) file*/
	void setReload(const BoolID& rl){fprintf_s(mFile,"connectAttr \"");rl.write(mFile);fprintf_s(mFile,"\" \"%s.rl\";\n",mName.c_str());}
	/*Output curves for all the curves from an Adobe(R) Illustrator(R) file.*/
	void setOutputCurves(size_t oc_i,const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc[%i]\";\n",mName.c_str(),oc_i);}
	/*
	Number of curves per compound path.
	In Adobe(R) Illustrator(R), curves are grouped under a
	compound path (e.g., a letter)
	*/
	void setCount(size_t c_i,const IntID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c[%i]\";\n",mName.c_str(),c_i);}
	/*
	Offsets for each curve.
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
	CVs on the output curve get snapped if the distance
	between two contiguous CVs are lesser than this tolerance value.
	*/
	void setTolerance(float tl){if(tl == 0.001f) return; fprintf_s(mFile, "setAttr \".tl\" %f;\n", tl);}
	/*
	CVs on the output curve get snapped if the distance
	between two contiguous CVs are lesser than this tolerance value.
	*/
	void setTolerance(const FloatID& tl){fprintf_s(mFile,"connectAttr \"");tl.write(mFile);fprintf_s(mFile,"\" \"%s.tl\";\n",mName.c_str());}
	/*Input Adobe(R) Illustrator(R) filename.*/
	StringID getIllustratorFilename(){char buffer[4096];sprintf_s (buffer, "%s.ifn",mName.c_str());return (const char*)buffer;}
	/*Scale Factor*/
	FloatID getScaleFactor(){char buffer[4096];sprintf_s (buffer, "%s.sf",mName.c_str());return (const char*)buffer;}
	/*Used to reload the same Adobe(R) Illustrator(R) file*/
	BoolID getReload(){char buffer[4096];sprintf_s (buffer, "%s.rl",mName.c_str());return (const char*)buffer;}
	/*Output curves for all the curves from an Adobe(R) Illustrator(R) file.*/
	const NurbsCurveID& getOutputCurves(size_t oc_i){char buffer[4096];sprintf_s (buffer, "%s.oc[%i]",mName.c_str(),oc_i);return (const char*)buffer;}
	/*
	Number of curves per compound path.
	In Adobe(R) Illustrator(R), curves are grouped under a
	compound path (e.g., a letter)
	*/
	const IntID& getCount(size_t c_i){char buffer[4096];sprintf_s (buffer, "%s.c[%i]",mName.c_str(),c_i);return (const char*)buffer;}
	/*
	Offsets for each curve.
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
	CVs on the output curve get snapped if the distance
	between two contiguous CVs are lesser than this tolerance value.
	*/
	FloatID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tl",mName.c_str());return (const char*)buffer;}
protected:
	MakeIllustratorCurves(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKEILLUSTRATORCURVES_H__
