/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ATTACHSURFACE_H__
#define __MayaDM_ATTACHSURFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
/*
Compute the attached surface given two input surfaces. The end boundary of
 the first surface is attached to the start boundary of the second surface
 in the defined attach direction (directionU). After the attach is done,
 multiple knots exist at the isoparm where the curves were joined. The
 multiple knots can be kept (keepMultipleKnots set to true) or they can be
 removed. If removed, the shape of the attach result may change.
 <p/>
*/
class AttachSurface : public AbstractBaseCreate
{
public:
public:
	AttachSurface(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "attachSurface"){}
	virtual ~AttachSurface(){}
	/*The first input surface.*/
	void setInputSurface1(const NurbsSurfaceID& is1){fprintf_s(mFile,"connectAttr \"");is1.write(mFile);fprintf_s(mFile,"\" \"%s.is1\";\n",mName.c_str());}
	/*The second input surface.*/
	void setInputSurface2(const NurbsSurfaceID& is2){fprintf_s(mFile,"connectAttr \"");is2.write(mFile);fprintf_s(mFile,"\" \"%s.is2\";\n",mName.c_str());}
	/*Output attached surface.*/
	void setOutputSurface(const NurbsSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*Attach method (connect-0, blend-1)*/
	void setMethod(unsigned int m){if(m == 0) return; fprintf_s(mFile, "setAttr \".m\" %i;\n", m);}
	/*Attach method (connect-0, blend-1)*/
	void setMethod(const UnsignedintID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m\";\n",mName.c_str());}
	/*If true attach in U direction of surface and V direction otherwise.*/
	void setDirectionU(bool du){if(du == true) return; fprintf_s(mFile, "setAttr \".du\" %i;\n", du);}
	/*If true attach in U direction of surface and V direction otherwise.*/
	void setDirectionU(const BoolID& du){fprintf_s(mFile,"connectAttr \"");du.write(mFile);fprintf_s(mFile,"\" \"%s.du\";\n",mName.c_str());}
	/*If true, reverse the direction (specified by directionU) of the first input surface before doing attach. Otherwise, do nothing to the first input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse1(bool rv1){if(rv1 == false) return; fprintf_s(mFile, "setAttr \".rv1\" %i;\n", rv1);}
	/*If true, reverse the direction (specified by directionU) of the first input surface before doing attach. Otherwise, do nothing to the first input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse1(const BoolID& rv1){fprintf_s(mFile,"connectAttr \"");rv1.write(mFile);fprintf_s(mFile,"\" \"%s.rv1\";\n",mName.c_str());}
	/*If true, reverse the direction (specified by directionU) of the second input surface before doing attach. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse2(bool rv2){if(rv2 == false) return; fprintf_s(mFile, "setAttr \".rv2\" %i;\n", rv2);}
	/*If true, reverse the direction (specified by directionU) of the second input surface before doing attach. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setReverse2(const BoolID& rv2){fprintf_s(mFile,"connectAttr \"");rv2.write(mFile);fprintf_s(mFile,"\" \"%s.rv2\";\n",mName.c_str());}
	/*If true, swap the UV directions of the first input surface before doing attach. Otherwise, do nothing to the first input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setSwap1(bool sw1){if(sw1 == false) return; fprintf_s(mFile, "setAttr \".sw1\" %i;\n", sw1);}
	/*If true, swap the UV directions of the first input surface before doing attach. Otherwise, do nothing to the first input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setSwap1(const BoolID& sw1){fprintf_s(mFile,"connectAttr \"");sw1.write(mFile);fprintf_s(mFile,"\" \"%s.sw1\";\n",mName.c_str());}
	/*If true, swap the UV directions of the second input surface before doing attach. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setSwap2(bool sw2){if(sw2 == false) return; fprintf_s(mFile, "setAttr \".sw2\" %i;\n", sw2);}
	/*If true, swap the UV directions of the second input surface before doing attach. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setSwap2(const BoolID& sw2){fprintf_s(mFile,"connectAttr \"");sw2.write(mFile);fprintf_s(mFile,"\" \"%s.sw2\";\n",mName.c_str());}
	/*If true, reverse the second surface in the opposite direction (specified by directionU) before doing attach. This will avoid twists in the attached surfaces. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setTwist(bool tw){if(tw == false) return; fprintf_s(mFile, "setAttr \".tw\" %i;\n", tw);}
	/*If true, reverse the second surface in the opposite direction (specified by directionU) before doing attach. This will avoid twists in the attached surfaces. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	void setTwist(const BoolID& tw){fprintf_s(mFile,"connectAttr \"");tw.write(mFile);fprintf_s(mFile,"\" \"%s.tw\";\n",mName.c_str());}
	/*Skew the result toward the first or the second curve depending on the blend factory being smaller or larger than 0.5.*/
	void setBlendBias(double bb){if(bb == 0.5) return; fprintf_s(mFile, "setAttr \".bb\" %f;\n", bb);}
	/*Skew the result toward the first or the second curve depending on the blend factory being smaller or larger than 0.5.*/
	void setBlendBias(const DoubleID& bb){fprintf_s(mFile,"connectAttr \"");bb.write(mFile);fprintf_s(mFile,"\" \"%s.bb\";\n",mName.c_str());}
	/*If set to true, insert a knot in one of the original curves (relative position given by the parameter attribute below) in order to produce a slightly different effect.*/
	void setBlendKnotInsertion(bool bki){if(bki == false) return; fprintf_s(mFile, "setAttr \".bki\" %i;\n", bki);}
	/*If set to true, insert a knot in one of the original curves (relative position given by the parameter attribute below) in order to produce a slightly different effect.*/
	void setBlendKnotInsertion(const BoolID& bki){fprintf_s(mFile,"connectAttr \"");bki.write(mFile);fprintf_s(mFile,"\" \"%s.bki\";\n",mName.c_str());}
	/*The parameter value for the positioning of the newly inserted knot.*/
	void setParameter(double p){if(p == 0.1) return; fprintf_s(mFile, "setAttr \".p\" %f;\n", p);}
	/*The parameter value for the positioning of the newly inserted knot.*/
	void setParameter(const DoubleID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*If true, keep multiple knots at the join parameter. Otherwise remove them.*/
	void setKeepMultipleKnots(bool kmk){if(kmk == true) return; fprintf_s(mFile, "setAttr \".kmk\" %i;\n", kmk);}
	/*If true, keep multiple knots at the join parameter. Otherwise remove them.*/
	void setKeepMultipleKnots(const BoolID& kmk){fprintf_s(mFile,"connectAttr \"");kmk.write(mFile);fprintf_s(mFile,"\" \"%s.kmk\";\n",mName.c_str());}
	/*The first input surface.*/
	NurbsSurfaceID getInputSurface1(){char buffer[4096];sprintf_s (buffer, "%s.is1",mName.c_str());return (const char*)buffer;}
	/*The second input surface.*/
	NurbsSurfaceID getInputSurface2(){char buffer[4096];sprintf_s (buffer, "%s.is2",mName.c_str());return (const char*)buffer;}
	/*Output attached surface.*/
	NurbsSurfaceID getOutputSurface(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
	/*Attach method (connect-0, blend-1)*/
	UnsignedintID getMethod(){char buffer[4096];sprintf_s (buffer, "%s.m",mName.c_str());return (const char*)buffer;}
	/*If true attach in U direction of surface and V direction otherwise.*/
	BoolID getDirectionU(){char buffer[4096];sprintf_s (buffer, "%s.du",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the direction (specified by directionU) of the first input surface before doing attach. Otherwise, do nothing to the first input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getReverse1(){char buffer[4096];sprintf_s (buffer, "%s.rv1",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the direction (specified by directionU) of the second input surface before doing attach. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getReverse2(){char buffer[4096];sprintf_s (buffer, "%s.rv2",mName.c_str());return (const char*)buffer;}
	/*If true, swap the UV directions of the first input surface before doing attach. Otherwise, do nothing to the first input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getSwap1(){char buffer[4096];sprintf_s (buffer, "%s.sw1",mName.c_str());return (const char*)buffer;}
	/*If true, swap the UV directions of the second input surface before doing attach. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getSwap2(){char buffer[4096];sprintf_s (buffer, "%s.sw2",mName.c_str());return (const char*)buffer;}
	/*If true, reverse the second surface in the opposite direction (specified by directionU) before doing attach. This will avoid twists in the attached surfaces. Otherwise, do nothing to the second input surface before attaching. NOTE: setting this attribute to random values will cause unpredictable results and is not supported.*/
	BoolID getTwist(){char buffer[4096];sprintf_s (buffer, "%s.tw",mName.c_str());return (const char*)buffer;}
	/*Skew the result toward the first or the second curve depending on the blend factory being smaller or larger than 0.5.*/
	DoubleID getBlendBias(){char buffer[4096];sprintf_s (buffer, "%s.bb",mName.c_str());return (const char*)buffer;}
	/*If set to true, insert a knot in one of the original curves (relative position given by the parameter attribute below) in order to produce a slightly different effect.*/
	BoolID getBlendKnotInsertion(){char buffer[4096];sprintf_s (buffer, "%s.bki",mName.c_str());return (const char*)buffer;}
	/*The parameter value for the positioning of the newly inserted knot.*/
	DoubleID getParameter(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*If true, keep multiple knots at the join parameter. Otherwise remove them.*/
	BoolID getKeepMultipleKnots(){char buffer[4096];sprintf_s (buffer, "%s.kmk",mName.c_str());return (const char*)buffer;}
protected:
	AttachSurface(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AbstractBaseCreate(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ATTACHSURFACE_H__
