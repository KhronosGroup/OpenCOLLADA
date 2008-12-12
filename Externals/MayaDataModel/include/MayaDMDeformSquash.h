/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMSQUASH_H__
#define __MayaDM_DEFORMSQUASH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
/*
This node provides a deformation function for the squash deformation and
 stores the attributes specifically related to it.  For more information
 on using this node, see the parent class documentation.
 <p/>
*/
class DeformSquash : public DeformFunc
{
public:
public:
	DeformSquash(FILE* file,const std::string& name,const std::string& parent=""):DeformFunc(file, name, parent, "deformSquash"){}
	virtual ~DeformSquash(){}
	/*Low bound of the deformation*/
	void setLowBound(double lb){if(lb == -1.0) return; fprintf_s(mFile, "setAttr \".lb\" %f;\n", lb);}
	/*Low bound of the deformation*/
	void setLowBound(const DoubleID& lb){fprintf_s(mFile,"connectAttr \"");lb.write(mFile);fprintf_s(mFile,"\" \"%s.lb\";\n",mName.c_str());}
	/*High bound of the deformation*/
	void setHighBound(double hb){if(hb == 1.0) return; fprintf_s(mFile, "setAttr \".hb\" %f;\n", hb);}
	/*High bound of the deformation*/
	void setHighBound(const DoubleID& hb){fprintf_s(mFile,"connectAttr \"");hb.write(mFile);fprintf_s(mFile,"\" \"%s.hb\";\n",mName.c_str());}
	/*
	Controls the curve profile between low bound and
	the maximum expansion position
	*/
	void setStartSmoothness(double ss){if(ss == 0.0) return; fprintf_s(mFile, "setAttr \".ss\" %f;\n", ss);}
	/*
	Controls the curve profile between low bound and
	the maximum expansion position
	*/
	void setStartSmoothness(const DoubleID& ss){fprintf_s(mFile,"connectAttr \"");ss.write(mFile);fprintf_s(mFile,"\" \"%s.ss\";\n",mName.c_str());}
	/*
	Controls the curve profile between the high bound and
	the maximum expansion position
	*/
	void setEndSmoothness(double es){if(es == 0.0) return; fprintf_s(mFile, "setAttr \".es\" %f;\n", es);}
	/*
	Controls the curve profile between the high bound and
	the maximum expansion position
	*/
	void setEndSmoothness(const DoubleID& es){fprintf_s(mFile,"connectAttr \"");es.write(mFile);fprintf_s(mFile,"\" \"%s.es\";\n",mName.c_str());}
	/*The position where maximum expansion/contraction takes place*/
	void setMaxExpandPos(double mp){if(mp == 0.5) return; fprintf_s(mFile, "setAttr \".mp\" %f;\n", mp);}
	/*The position where maximum expansion/contraction takes place*/
	void setMaxExpandPos(const DoubleID& mp){fprintf_s(mFile,"connectAttr \"");mp.write(mFile);fprintf_s(mFile,"\" \"%s.mp\";\n",mName.c_str());}
	/*The amount of expansion/contraction*/
	void setExpand(double exp){if(exp == 1.0) return; fprintf_s(mFile, "setAttr \".exp\" %f;\n", exp);}
	/*The amount of expansion/contraction*/
	void setExpand(const DoubleID& exp){fprintf_s(mFile,"connectAttr \"");exp.write(mFile);fprintf_s(mFile,"\" \"%s.exp\";\n",mName.c_str());}
	/*The amount of squashing/stretching*/
	void setFactor(double fac){if(fac == 0.0) return; fprintf_s(mFile, "setAttr \".fac\" %f;\n", fac);}
	/*The amount of squashing/stretching*/
	void setFactor(const DoubleID& fac){fprintf_s(mFile,"connectAttr \"");fac.write(mFile);fprintf_s(mFile,"\" \"%s.fac\";\n",mName.c_str());}
	/*Low bound of the deformation*/
	DoubleID getLowBound(){char buffer[4096];sprintf_s (buffer, "%s.lb",mName.c_str());return (const char*)buffer;}
	/*High bound of the deformation*/
	DoubleID getHighBound(){char buffer[4096];sprintf_s (buffer, "%s.hb",mName.c_str());return (const char*)buffer;}
	/*
	Controls the curve profile between low bound and
	the maximum expansion position
	*/
	DoubleID getStartSmoothness(){char buffer[4096];sprintf_s (buffer, "%s.ss",mName.c_str());return (const char*)buffer;}
	/*
	Controls the curve profile between the high bound and
	the maximum expansion position
	*/
	DoubleID getEndSmoothness(){char buffer[4096];sprintf_s (buffer, "%s.es",mName.c_str());return (const char*)buffer;}
	/*The position where maximum expansion/contraction takes place*/
	DoubleID getMaxExpandPos(){char buffer[4096];sprintf_s (buffer, "%s.mp",mName.c_str());return (const char*)buffer;}
	/*The amount of expansion/contraction*/
	DoubleID getExpand(){char buffer[4096];sprintf_s (buffer, "%s.exp",mName.c_str());return (const char*)buffer;}
	/*The amount of squashing/stretching*/
	DoubleID getFactor(){char buffer[4096];sprintf_s (buffer, "%s.fac",mName.c_str());return (const char*)buffer;}
protected:
	DeformSquash(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DeformFunc(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMSQUASH_H__
