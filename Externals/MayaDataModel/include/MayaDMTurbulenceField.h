/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TURBULENCEFIELD_H__
#define __MayaDM_TURBULENCEFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
/*
The turbulence node implements a Perlin noise field which can
 be applied to particles or rigid bodies.  The magnitude,
 frequency, and phase attributes control the random motion
 induced by the node.  The best way to see the effect is to
 apply the field to a group of particles and try varying
 the parameters.  <p/>
*/
class TurbulenceField : public Field
{
public:
public:
	TurbulenceField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "turbulenceField"){}
	virtual ~TurbulenceField(){}
	/*frequency*/
	void setFrequency(double frq){if(frq == 1.0) return; fprintf_s(mFile, "setAttr \".frq\" %f;\n", frq);}
	/*frequency*/
	void setFrequency(const DoubleID& frq){fprintf_s(mFile,"connectAttr \"");frq.write(mFile);fprintf_s(mFile,"\" \"%s.frq\";\n",mName.c_str());}
	/*
	x component of phase shift.  By animating this, you can
	see the noise disturbance move along the x dimension.
	*/
	void setPhaseX(double phx){if(phx == 0.0) return; fprintf_s(mFile, "setAttr \".phx\" %f;\n", phx);}
	/*
	x component of phase shift.  By animating this, you can
	see the noise disturbance move along the x dimension.
	*/
	void setPhaseX(const DoubleID& phx){fprintf_s(mFile,"connectAttr \"");phx.write(mFile);fprintf_s(mFile,"\" \"%s.phx\";\n",mName.c_str());}
	/*
	y component of phase shift.  By animating this, you can
	see the noise disturbance move along the y dimension.
	*/
	void setPhaseY(double phy){if(phy == 0.0) return; fprintf_s(mFile, "setAttr \".phy\" %f;\n", phy);}
	/*
	y component of phase shift.  By animating this, you can
	see the noise disturbance move along the y dimension.
	*/
	void setPhaseY(const DoubleID& phy){fprintf_s(mFile,"connectAttr \"");phy.write(mFile);fprintf_s(mFile,"\" \"%s.phy\";\n",mName.c_str());}
	/*
	z component of phase shift.  By animating this, you can
	see the noise disturbance move along the z dimension.
	The "phase" attribute prior to Maya 3.0 was equivalent to phaseZ.
	Pre-Maya 3.0 files will load correctly with the old "phase"
	value assigned to phaseZ.
	*/
	void setPhaseZ(double phz){if(phz == 0.0) return; fprintf_s(mFile, "setAttr \".phz\" %f;\n", phz);}
	/*
	z component of phase shift.  By animating this, you can
	see the noise disturbance move along the z dimension.
	The "phase" attribute prior to Maya 3.0 was equivalent to phaseZ.
	Pre-Maya 3.0 files will load correctly with the old "phase"
	value assigned to phaseZ.
	*/
	void setPhaseZ(const DoubleID& phz){fprintf_s(mFile,"connectAttr \"");phz.write(mFile);fprintf_s(mFile,"\" \"%s.phz\";\n",mName.c_str());}
	/*
	Number of iterations for noise evaluation.
	Increasing this value will give greater irregularity in the
	particle motion, at the cost of some computation time.
	A value of 0 gives the same results as in versions of Maya prior to 3.0.
	*/
	void setNoiseLevel(int nslv){if(nslv == 0) return; fprintf_s(mFile, "setAttr \".nslv\" %i;\n", nslv);}
	/*
	Number of iterations for noise evaluation.
	Increasing this value will give greater irregularity in the
	particle motion, at the cost of some computation time.
	A value of 0 gives the same results as in versions of Maya prior to 3.0.
	*/
	void setNoiseLevel(const IntID& nslv){fprintf_s(mFile,"connectAttr \"");nslv.write(mFile);fprintf_s(mFile,"\" \"%s.nslv\";\n",mName.c_str());}
	/*
	The relative magnitude for each consecutive noise evaluation.
	Used with noiseLevel.
	*/
	void setNoiseRatio(double nsrt){if(nsrt == 0.707) return; fprintf_s(mFile, "setAttr \".nsrt\" %f;\n", nsrt);}
	/*
	The relative magnitude for each consecutive noise evaluation.
	Used with noiseLevel.
	*/
	void setNoiseRatio(const DoubleID& nsrt){fprintf_s(mFile,"connectAttr \"");nsrt.write(mFile);fprintf_s(mFile,"\" \"%s.nsrt\";\n",mName.c_str());}
	/*
	the toggle between linear interpolated noise and quadratic
	interpolated noise.  Quadratic interpolation gives more smooth
	result, but it's more expensive to evaluate.
	*/
	void setInterpolationType(unsigned int intr){if(intr == 0) return; fprintf_s(mFile, "setAttr \".intr\" %i;\n", intr);}
	/*
	the toggle between linear interpolated noise and quadratic
	interpolated noise.  Quadratic interpolation gives more smooth
	result, but it's more expensive to evaluate.
	*/
	void setInterpolationType(const UnsignedintID& intr){fprintf_s(mFile,"connectAttr \"");intr.write(mFile);fprintf_s(mFile,"\" \"%s.intr\";\n",mName.c_str());}
	/*frequency*/
	DoubleID getFrequency(){char buffer[4096];sprintf_s (buffer, "%s.frq",mName.c_str());return (const char*)buffer;}
	/*
	x component of phase shift.  By animating this, you can
	see the noise disturbance move along the x dimension.
	*/
	DoubleID getPhaseX(){char buffer[4096];sprintf_s (buffer, "%s.phx",mName.c_str());return (const char*)buffer;}
	/*
	y component of phase shift.  By animating this, you can
	see the noise disturbance move along the y dimension.
	*/
	DoubleID getPhaseY(){char buffer[4096];sprintf_s (buffer, "%s.phy",mName.c_str());return (const char*)buffer;}
	/*
	z component of phase shift.  By animating this, you can
	see the noise disturbance move along the z dimension.
	The "phase" attribute prior to Maya 3.0 was equivalent to phaseZ.
	Pre-Maya 3.0 files will load correctly with the old "phase"
	value assigned to phaseZ.
	*/
	DoubleID getPhaseZ(){char buffer[4096];sprintf_s (buffer, "%s.phz",mName.c_str());return (const char*)buffer;}
	/*
	Number of iterations for noise evaluation.
	Increasing this value will give greater irregularity in the
	particle motion, at the cost of some computation time.
	A value of 0 gives the same results as in versions of Maya prior to 3.0.
	*/
	IntID getNoiseLevel(){char buffer[4096];sprintf_s (buffer, "%s.nslv",mName.c_str());return (const char*)buffer;}
	/*
	The relative magnitude for each consecutive noise evaluation.
	Used with noiseLevel.
	*/
	DoubleID getNoiseRatio(){char buffer[4096];sprintf_s (buffer, "%s.nsrt",mName.c_str());return (const char*)buffer;}
	/*
	the toggle between linear interpolated noise and quadratic
	interpolated noise.  Quadratic interpolation gives more smooth
	result, but it's more expensive to evaluate.
	*/
	UnsignedintID getInterpolationType(){char buffer[4096];sprintf_s (buffer, "%s.intr",mName.c_str());return (const char*)buffer;}
protected:
	TurbulenceField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_TURBULENCEFIELD_H__
