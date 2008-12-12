/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRIM_H__
#define __MayaDM_TRIM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Trim a surface to its active curves on surface by splitting the surface
 into regions and keeping some while discarding other regions. Use
 locators (locatorU and locatorV) to select split regions. Use selected
 to specify whether to keep or discard the selected regions. Use shrinkSurface
 to limit the bounds of the underlying surface to just greater than the outer
 boundaries of the trimmed surface.
 <p/>
*/
class Trim : public AbstractBaseCreate
{
public:
public:
	Trim(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "trim"){}
	virtual ~Trim(){}
	/*The curves on surface to be used for trimming.*/
	void setInputCurve(size_t ic_i,const NurbsCurveID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic[%i]\";\n",mName.c_str(),ic_i);}
	/*The surface to be trimmed.*/
	void setInputSurface(const NurbsSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*u parameter value to position a locator on the surface.*/
	void setLocatorU(size_t lu_i,double lu){if(lu == 0.5) return; fprintf_s(mFile, "setAttr \".lu[%i]\" %f;\n", lu_i,lu);}
	/*u parameter value to position a locator on the surface.*/
	void setLocatorU(size_t lu_i,const DoubleID& lu){fprintf_s(mFile,"connectAttr \"");lu.write(mFile);fprintf_s(mFile,"\" \"%s.lu[%i]\";\n",mName.c_str(),lu_i);}
	/*v parameter value to position a locator on the surface.*/
	void setLocatorV(size_t lv_i,double lv){if(lv == 0.5) return; fprintf_s(mFile, "setAttr \".lv[%i]\" %f;\n", lv_i,lv);}
	/*v parameter value to position a locator on the surface.*/
	void setLocatorV(size_t lv_i,const DoubleID& lv){fprintf_s(mFile,"connectAttr \"");lv.write(mFile);fprintf_s(mFile,"\" \"%s.lv[%i]\";\n",mName.c_str(),lv_i);}
	/*Specify whether to keep or discard selected regions.*/
	void setSelected(unsigned int sl){if(sl == 0) return; fprintf_s(mFile, "setAttr \".sl\" %i;\n", sl);}
	/*Specify whether to keep or discard selected regions.*/
	void setSelected(const UnsignedintID& sl){fprintf_s(mFile,"connectAttr \"");sl.write(mFile);fprintf_s(mFile,"\" \"%s.sl\";\n",mName.c_str());}
	/*If true, shrink underlying surface to outer boundaries of trimmed surface.*/
	void setShrink(bool sh){if(sh == false) return; fprintf_s(mFile, "setAttr \".sh\" %i;\n", sh);}
	/*If true, shrink underlying surface to outer boundaries of trimmed surface.*/
	void setShrink(const BoolID& sh){fprintf_s(mFile,"connectAttr \"");sh.write(mFile);fprintf_s(mFile,"\" \"%s.sh\";\n",mName.c_str());}
	/*The tolerance with which to trim.*/
	void setTolerance(double tol){if(tol == 0) return; fprintf_s(mFile, "setAttr \".tol\" %f;\n", tol);}
	/*The tolerance with which to trim.*/
	void setTolerance(const DoubleID& tol){fprintf_s(mFile,"connectAttr \"");tol.write(mFile);fprintf_s(mFile,"\" \"%s.tol\";\n",mName.c_str());}
	/*Flag each curve as used or not used in trimming.*/
	void setUsedCurves(size_t uc_i,const BoolID& uc){fprintf_s(mFile,"connectAttr \"");uc.write(mFile);fprintf_s(mFile,"\" \"%s.uc[%i]\";\n",mName.c_str(),uc_i);}
	/*The surface (don't use this) after split*/
	void setSplitSurface(const NurbsSurfaceID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*The trimmed surface.*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*If true, then deformers will let this trim node be last*/
	void setShouldBeLast(const BoolID& sbl){fprintf_s(mFile,"connectAttr \"");sbl.write(mFile);fprintf_s(mFile,"\" \"%s.sbl\";\n",mName.c_str());}
	/*The curves on surface to be used for trimming.*/
	const NurbsCurveID& getInputCurve(size_t ic_i){char buffer[4096];sprintf_s (buffer, "%s.ic[%i]",mName.c_str(),ic_i);return (const char*)buffer;}
	/*The surface to be trimmed.*/
	NurbsSurfaceID getInputSurface(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*u parameter value to position a locator on the surface.*/
	const DoubleID& getLocatorU(size_t lu_i){char buffer[4096];sprintf_s (buffer, "%s.lu[%i]",mName.c_str(),lu_i);return (const char*)buffer;}
	/*v parameter value to position a locator on the surface.*/
	const DoubleID& getLocatorV(size_t lv_i){char buffer[4096];sprintf_s (buffer, "%s.lv[%i]",mName.c_str(),lv_i);return (const char*)buffer;}
	/*Specify whether to keep or discard selected regions.*/
	UnsignedintID getSelected(){char buffer[4096];sprintf_s (buffer, "%s.sl",mName.c_str());return (const char*)buffer;}
	/*If true, shrink underlying surface to outer boundaries of trimmed surface.*/
	BoolID getShrink(){char buffer[4096];sprintf_s (buffer, "%s.sh",mName.c_str());return (const char*)buffer;}
	/*The tolerance with which to trim.*/
	DoubleID getTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tol",mName.c_str());return (const char*)buffer;}
	/*Flag each curve as used or not used in trimming.*/
	const BoolID& getUsedCurves(size_t uc_i){char buffer[4096];sprintf_s (buffer, "%s.uc[%i]",mName.c_str(),uc_i);return (const char*)buffer;}
	/*The surface (don't use this) after split*/
	NurbsSurfaceID getSplitSurface(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*The trimmed surface.*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*If true, then deformers will let this trim node be last*/
	BoolID getShouldBeLast(){char buffer[4096];sprintf_s (buffer, "%s.sbl",mName.c_str());return (const char*)buffer;}
protected:
	Trim(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TRIM_H__
