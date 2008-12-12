/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LINEMODIFIER_H__
#define __MayaDM_LINEMODIFIER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
/*
This node can be used to locally modify toon line attributes.
 <p/>
*/
class LineModifier : public Shape
{
public:
	/*
	This determines the range of effect within the bounds of the modifier. If the dropoff is set
	to a constant value of 1.0 (horizontal line) then lines will be uniformly modified inside
	the bounds of the dropoff shape, with a hard transition at the shape edge. If the right
	edge of the dropoff is instead ramped down to zero the transition will be gradual, with no
	modulation at the shape edge, with increasing modulation towards its center.
	The dropoff graph attribute is defined relative to the shape, such that the right edge of the dropoff is the
	the outer edge of the shape, and the left is the shapes center.
	*/
	struct Dropoff{
		float dropoff_Position;
		float dropoff_FloatValue;
		unsigned int dropoff_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", dropoff_Position);
			fprintf_s(file,"%f ", dropoff_FloatValue);
			fprintf_s(file,"%i", dropoff_Interp);
		}
	};
public:
	LineModifier(FILE* file,const std::string& name,const std::string& parent=""):Shape(file, name, parent, "lineModifier"){}
	virtual ~LineModifier(){}
	/*
	This determines the shape of the line modifier. There will be no effect outside the bounds of the selected shape.
	The dropoff graph attribute is defined relative to the shape, such that the right edge of the dropoff is the
	the outer edge of the shape, and the left is the shapes center.
	*/
	void setShape(unsigned int shp){if(shp == 0) return; fprintf_s(mFile, "setAttr \".shp\" %i;\n", shp);}
	/*
	This determines the shape of the line modifier. There will be no effect outside the bounds of the selected shape.
	The dropoff graph attribute is defined relative to the shape, such that the right edge of the dropoff is the
	the outer edge of the shape, and the left is the shapes center.
	*/
	void setShape(const UnsignedintID& shp){fprintf_s(mFile,"connectAttr \"");shp.write(mFile);fprintf_s(mFile,"\" \"%s.shp\";\n",mName.c_str());}
	/*
	This value multiplies the current line width.  A value of 1.0 will have no
	effect and a value of zero will scale the width to zero.
	*/
	void setWidthScale(double wsc){if(wsc == 5.0) return; fprintf_s(mFile, "setAttr \".wsc\" %f;\n", wsc);}
	/*
	This value multiplies the current line width.  A value of 1.0 will have no
	effect and a value of zero will scale the width to zero.
	*/
	void setWidthScale(const DoubleID& wsc){fprintf_s(mFile,"connectAttr \"");wsc.write(mFile);fprintf_s(mFile,"\" \"%s.wsc\";\n",mName.c_str());}
	/*
	This value adds onto the current line width.  A value of 0.0 will have no
	effect and a value of 1.0 will grow the width by one.
	*/
	void setWidthOffset(double wof){if(wof == 0.0) return; fprintf_s(mFile, "setAttr \".wof\" %f;\n", wof);}
	/*
	This value adds onto the current line width.  A value of 0.0 will have no
	effect and a value of 1.0 will grow the width by one.
	*/
	void setWidthOffset(const DoubleID& wof){fprintf_s(mFile,"connectAttr \"");wof.write(mFile);fprintf_s(mFile,"\" \"%s.wof\";\n",mName.c_str());}
	/*
	This value multiplies the current line opacity.  A value of 1.0 will have no
	effect and a value of zero will scale the opacity to zero.
	*/
	void setOpacityScale(double osc){if(osc == 1.0) return; fprintf_s(mFile, "setAttr \".osc\" %f;\n", osc);}
	/*
	This value multiplies the current line opacity.  A value of 1.0 will have no
	effect and a value of zero will scale the opacity to zero.
	*/
	void setOpacityScale(const DoubleID& osc){fprintf_s(mFile,"connectAttr \"");osc.write(mFile);fprintf_s(mFile,"\" \"%s.osc\";\n",mName.c_str());}
	/*
	This value adds onto the current line opacity.  A value of 0.0 will have no
	effect and a value of 1.0 will make the lines fully opaque.
	*/
	void setOpacityOffset(double oof){if(oof == 0.0) return; fprintf_s(mFile, "setAttr \".oof\" %f;\n", oof);}
	/*
	This value adds onto the current line opacity.  A value of 0.0 will have no
	effect and a value of 1.0 will make the lines fully opaque.
	*/
	void setOpacityOffset(const DoubleID& oof){fprintf_s(mFile,"connectAttr \"");oof.write(mFile);fprintf_s(mFile,"\" \"%s.oof\";\n",mName.c_str());}
	/*
	This value adds onto the current line surface offset.  A value of 0.0 will have no
	effect and a value of 1.0 will increase the offset by 1.0. Negative values will
	clamp when an offset of 0 is achieved.
	*/
	void setSurfaceOffset(double sof){if(sof == 0.0) return; fprintf_s(mFile, "setAttr \".sof\" %f;\n", sof);}
	/*
	This value adds onto the current line surface offset.  A value of 0.0 will have no
	effect and a value of 1.0 will increase the offset by 1.0. Negative values will
	clamp when an offset of 0 is achieved.
	*/
	void setSurfaceOffset(const DoubleID& sof){fprintf_s(mFile,"connectAttr \"");sof.write(mFile);fprintf_s(mFile,"\" \"%s.sof\";\n",mName.c_str());}
	/*
	This value adds onto the current line extend.  A value of 0.0 will have no
	effect and a value of 1.0 will increase the extend by 1.0. Negative values will
	clamp when an extend of 0 is achieved.
	*/
	void setLineExtend(double lex){if(lex == 0.0) return; fprintf_s(mFile, "setAttr \".lex\" %f;\n", lex);}
	/*
	This value adds onto the current line extend.  A value of 0.0 will have no
	effect and a value of 1.0 will increase the extend by 1.0. Negative values will
	clamp when an extend of 0 is achieved.
	*/
	void setLineExtend(const DoubleID& lex){fprintf_s(mFile,"connectAttr \"");lex.write(mFile);fprintf_s(mFile,"\" \"%s.lex\";\n",mName.c_str());}
	/*If on then the color value is blended with the line color based on the droffoff value.*/
	void setModifyColor(bool mcl){if(mcl == false) return; fprintf_s(mFile, "setAttr \".mcl\" %i;\n", mcl);}
	/*If on then the color value is blended with the line color based on the droffoff value.*/
	void setModifyColor(const BoolID& mcl){fprintf_s(mFile,"connectAttr \"");mcl.write(mFile);fprintf_s(mFile,"\" \"%s.mcl\";\n",mName.c_str());}
	/*
	If modify color is on then this color is blended into the local
	line color based on the dropoff value.
	*/
	void setColor(const float3& clr){fprintf_s(mFile, "setAttr \".clr\" -type \"float3\" ");clr.write(mFile);fprintf_s(mFile,";\n");}
	/*
	If modify color is on then this color is blended into the local
	line color based on the dropoff value.
	*/
	void setColor(const Float3ID& clr){fprintf_s(mFile,"connectAttr \"");clr.write(mFile);fprintf_s(mFile,"\" \"%s.clr\";\n",mName.c_str());}
	/*Red value*/
	void setColorR(float crr){if(crr == 1.0) return; fprintf_s(mFile, "setAttr \".clr.crr\" %f;\n", crr);}
	/*Red value*/
	void setColorR(const FloatID& crr){fprintf_s(mFile,"connectAttr \"");crr.write(mFile);fprintf_s(mFile,"\" \"%s.clr.crr\";\n",mName.c_str());}
	/*Green value*/
	void setColorG(float crg){if(crg == 0.0) return; fprintf_s(mFile, "setAttr \".clr.crg\" %f;\n", crg);}
	/*Green value*/
	void setColorG(const FloatID& crg){fprintf_s(mFile,"connectAttr \"");crg.write(mFile);fprintf_s(mFile,"\" \"%s.clr.crg\";\n",mName.c_str());}
	/*Blue value*/
	void setColorB(float crb){if(crb == 0.0) return; fprintf_s(mFile, "setAttr \".clr.crb\" %f;\n", crb);}
	/*Blue value*/
	void setColorB(const FloatID& crb){fprintf_s(mFile,"connectAttr \"");crb.write(mFile);fprintf_s(mFile,"\" \"%s.clr.crb\";\n",mName.c_str());}
	/*
	This can be used to scale the length and width of paint effects tubes generated.
	A value of 1.0 will have no effect and a value of 0.0 will scale the tubes to
	nothing, resulting in no tubes generated. The behavior is similar to modifying
	the brush global scale.  To have an effect this requires hat a brush with tubes=ON
	be used.
	*/
	void setTubeScale(double tus){if(tus == 1.0) return; fprintf_s(mFile, "setAttr \".tus\" %f;\n", tus);}
	/*
	This can be used to scale the length and width of paint effects tubes generated.
	A value of 1.0 will have no effect and a value of 0.0 will scale the tubes to
	nothing, resulting in no tubes generated. The behavior is similar to modifying
	the brush global scale.  To have an effect this requires hat a brush with tubes=ON
	be used.
	*/
	void setTubeScale(const DoubleID& tus){fprintf_s(mFile,"connectAttr \"");tus.write(mFile);fprintf_s(mFile,"\" \"%s.tus\";\n",mName.c_str());}
	/*
	This can be used to reduce the number of paint effects tubes generated.
	A value of 0.0 will have no effect and a value of 1.0 will result
	in no tubes generated. To have an effect this requires that a brush with tubes=ON
	be used.
	*/
	void setTubeDropout(double tud){if(tud == 0.0) return; fprintf_s(mFile, "setAttr \".tud\" %f;\n", tud);}
	/*
	This can be used to reduce the number of paint effects tubes generated.
	A value of 0.0 will have no effect and a value of 1.0 will result
	in no tubes generated. To have an effect this requires that a brush with tubes=ON
	be used.
	*/
	void setTubeDropout(const DoubleID& tud){fprintf_s(mFile,"connectAttr \"");tud.write(mFile);fprintf_s(mFile,"\" \"%s.tud\";\n",mName.c_str());}
	/*
	This value adds onto the current branch dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and branches=ON be used.
	*/
	void setBranchDropout(double bdp){if(bdp == 0.0) return; fprintf_s(mFile, "setAttr \".bdp\" %f;\n", bdp);}
	/*
	This value adds onto the current branch dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and branches=ON be used.
	*/
	void setBranchDropout(const DoubleID& bdp){fprintf_s(mFile,"connectAttr \"");bdp.write(mFile);fprintf_s(mFile,"\" \"%s.bdp\";\n",mName.c_str());}
	/*
	This value adds onto the current branch dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and twigs=ON be used.
	*/
	void setTwigDropout(double tdp){if(tdp == 0.0) return; fprintf_s(mFile, "setAttr \".tdp\" %f;\n", tdp);}
	/*
	This value adds onto the current branch dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and twigs=ON be used.
	*/
	void setTwigDropout(const DoubleID& tdp){fprintf_s(mFile,"connectAttr \"");tdp.write(mFile);fprintf_s(mFile,"\" \"%s.tdp\";\n",mName.c_str());}
	/*
	This value adds onto the current leaf dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and leaves=ON be used.
	*/
	void setLeafDropout(double ldp){if(ldp == 0.0) return; fprintf_s(mFile, "setAttr \".ldp\" %f;\n", ldp);}
	/*
	This value adds onto the current leaf dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and leaves=ON be used.
	*/
	void setLeafDropout(const DoubleID& ldp){fprintf_s(mFile,"connectAttr \"");ldp.write(mFile);fprintf_s(mFile,"\" \"%s.ldp\";\n",mName.c_str());}
	/*
	This value adds onto the current flower dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and flowers=ON be used.
	*/
	void setFlowerDropout(double fdp){if(fdp == 0.0) return; fprintf_s(mFile, "setAttr \".fdp\" %f;\n", fdp);}
	/*
	This value adds onto the current flower dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and flowers=ON be used.
	*/
	void setFlowerDropout(const DoubleID& fdp){fprintf_s(mFile,"connectAttr \"");fdp.write(mFile);fprintf_s(mFile,"\" \"%s.fdp\";\n",mName.c_str());}
	/*
	This value multiplies the size of leaves used by the paint
	effects brush. A value of 1.0 will have no effect and a value of 0.5 will reduce
	leaf size by  half. To have an effect this requires that a brush with tubes=ON
	and leaves=ON be used.
	*/
	void setLeafScale(double lsc){if(lsc == 1.0) return; fprintf_s(mFile, "setAttr \".lsc\" %f;\n", lsc);}
	/*
	This value multiplies the size of leaves used by the paint
	effects brush. A value of 1.0 will have no effect and a value of 0.5 will reduce
	leaf size by  half. To have an effect this requires that a brush with tubes=ON
	and leaves=ON be used.
	*/
	void setLeafScale(const DoubleID& lsc){fprintf_s(mFile,"connectAttr \"");lsc.write(mFile);fprintf_s(mFile,"\" \"%s.lsc\";\n",mName.c_str());}
	/*
	This value multiplies the size of flowers used by the paint
	effects brush. A value of 1.0 will have no effect and a value of 0.5 will reduce
	flower size by  half. To have an effect this requires that a brush with tubes=ON
	and flowers=ON be used.
	*/
	void setFlowerScale(double fsc){if(fsc == 1.0) return; fprintf_s(mFile, "setAttr \".fsc\" %f;\n", fsc);}
	/*
	This value multiplies the size of flowers used by the paint
	effects brush. A value of 1.0 will have no effect and a value of 0.5 will reduce
	flower size by  half. To have an effect this requires that a brush with tubes=ON
	and flowers=ON be used.
	*/
	void setFlowerScale(const DoubleID& fsc){fprintf_s(mFile,"connectAttr \"");fsc.write(mFile);fprintf_s(mFile,"\" \"%s.fsc\";\n",mName.c_str());}
	/*
	This acts as a force pushing tubes away from the center of the line modifier shape.
	Positive values will push away from the center while negative values will push towards
	the center.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	void setForce(double frc){if(frc == 0.0) return; fprintf_s(mFile, "setAttr \".frc\" %f;\n", frc);}
	/*
	This acts as a force pushing tubes away from the center of the line modifier shape.
	Positive values will push away from the center while negative values will push towards
	the center.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	void setForce(const DoubleID& frc){fprintf_s(mFile,"connectAttr \"");frc.write(mFile);fprintf_s(mFile,"\" \"%s.frc\";\n",mName.c_str());}
	/*
	This acts as a force pushing tubes along the local x axis of the line modifier shape.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	void setDirectionalForce(double dfc){if(dfc == 0.0) return; fprintf_s(mFile, "setAttr \".dfc\" %f;\n", dfc);}
	/*
	This acts as a force pushing tubes along the local x axis of the line modifier shape.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	void setDirectionalForce(const DoubleID& dfc){fprintf_s(mFile,"connectAttr \"");dfc.write(mFile);fprintf_s(mFile,"\" \"%s.dfc\";\n",mName.c_str());}
	/*
	This acts as a displacement pushing tubes away from the center of the line modifier shape.
	Positive values will push away from the center while negative values will push towards
	the center. This is similar to the force attribute, but tube segments further down the
	tube are not affected by the offset.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	void setDisplacement(double dsp){if(dsp == 0.0) return; fprintf_s(mFile, "setAttr \".dsp\" %f;\n", dsp);}
	/*
	This acts as a displacement pushing tubes away from the center of the line modifier shape.
	Positive values will push away from the center while negative values will push towards
	the center. This is similar to the force attribute, but tube segments further down the
	tube are not affected by the offset.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	void setDisplacement(const DoubleID& dsp){fprintf_s(mFile,"connectAttr \"");dsp.write(mFile);fprintf_s(mFile,"\" \"%s.dsp\";\n",mName.c_str());}
	/*
	This acts as a displacement pushing tubes along the local x axis of the line modifier shape.
	To have an effect this requires that a brush with tubes=ON be used. This is similar to the
	directional force attribute, but tube segments further down the tube are not affected
	by the offset.
	*/
	void setDirectionalDisplacement(double ddc){if(ddc == 0.0) return; fprintf_s(mFile, "setAttr \".ddc\" %f;\n", ddc);}
	/*
	This acts as a displacement pushing tubes along the local x axis of the line modifier shape.
	To have an effect this requires that a brush with tubes=ON be used. This is similar to the
	directional force attribute, but tube segments further down the tube are not affected
	by the offset.
	*/
	void setDirectionalDisplacement(const DoubleID& ddc){fprintf_s(mFile,"connectAttr \"");ddc.write(mFile);fprintf_s(mFile,"\" \"%s.ddc\";\n",mName.c_str());}
	/*
	This modulates the dropoff value with a 3D noise. This can provide variation for the
	parameters being modulated. For example the tube width can be randomized or wiggled
	in a noisy fashion using this attribute. The Noise Frequency attribute controls how
	detailed the noise is.
	*/
	void setDropoffNoise(double don){if(don == 0.0) return; fprintf_s(mFile, "setAttr \".don\" %f;\n", don);}
	/*
	This modulates the dropoff value with a 3D noise. This can provide variation for the
	parameters being modulated. For example the tube width can be randomized or wiggled
	in a noisy fashion using this attribute. The Noise Frequency attribute controls how
	detailed the noise is.
	*/
	void setDropoffNoise(const DoubleID& don){fprintf_s(mFile,"connectAttr \"");don.write(mFile);fprintf_s(mFile,"\" \"%s.don\";\n",mName.c_str());}
	/*
	The Noise Frequency attribute controls how detailed the dropoff noise is.
	Lower values result in a smoother noise. The 3D noise is defined relative to
	the local space of the line modifier shape.
	*/
	void setNoiseFrequency(double nfr){if(nfr == 0.2) return; fprintf_s(mFile, "setAttr \".nfr\" %f;\n", nfr);}
	/*
	The Noise Frequency attribute controls how detailed the dropoff noise is.
	Lower values result in a smoother noise. The 3D noise is defined relative to
	the local space of the line modifier shape.
	*/
	void setNoiseFrequency(const DoubleID& nfr){fprintf_s(mFile,"connectAttr \"");nfr.write(mFile);fprintf_s(mFile,"\" \"%s.nfr\";\n",mName.c_str());}
	/*
	This determines the range of effect within the bounds of the modifier. If the dropoff is set
	to a constant value of 1.0 (horizontal line) then lines will be uniformly modified inside
	the bounds of the dropoff shape, with a hard transition at the shape edge. If the right
	edge of the dropoff is instead ramped down to zero the transition will be gradual, with no
	modulation at the shape edge, with increasing modulation towards its center.
	The dropoff graph attribute is defined relative to the shape, such that the right edge of the dropoff is the
	the outer edge of the shape, and the left is the shapes center.
	*/
	void setDropoff(size_t drp_i,const Dropoff& drp){fprintf_s(mFile, "setAttr \".drp[%i]\" ",drp_i);drp.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This determines the range of effect within the bounds of the modifier. If the dropoff is set
	to a constant value of 1.0 (horizontal line) then lines will be uniformly modified inside
	the bounds of the dropoff shape, with a hard transition at the shape edge. If the right
	edge of the dropoff is instead ramped down to zero the transition will be gradual, with no
	modulation at the shape edge, with increasing modulation towards its center.
	The dropoff graph attribute is defined relative to the shape, such that the right edge of the dropoff is the
	the outer edge of the shape, and the left is the shapes center.
	*/
	void setDropoff(size_t drp_i,const DropoffID& drp){fprintf_s(mFile,"connectAttr \"");drp.write(mFile);fprintf_s(mFile,"\" \"%s.drp[%i]\";\n",mName.c_str(),drp_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setDropoff_Position(size_t drp_i,float drpp){if(drpp == 0.0) return; fprintf_s(mFile, "setAttr \".drp[%i].drpp\" %f;\n", drp_i,drpp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setDropoff_Position(size_t drp_i,const FloatID& drpp){fprintf_s(mFile,"connectAttr \"");drpp.write(mFile);fprintf_s(mFile,"\" \"%s.drp[%i].drpp\";\n",mName.c_str(),drp_i);}
	/*Ramp value at the sibling position*/
	void setDropoff_FloatValue(size_t drp_i,float drpfv){if(drpfv == 0.0) return; fprintf_s(mFile, "setAttr \".drp[%i].drpfv\" %f;\n", drp_i,drpfv);}
	/*Ramp value at the sibling position*/
	void setDropoff_FloatValue(size_t drp_i,const FloatID& drpfv){fprintf_s(mFile,"connectAttr \"");drpfv.write(mFile);fprintf_s(mFile,"\" \"%s.drp[%i].drpfv\";\n",mName.c_str(),drp_i);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setDropoff_Interp(size_t drp_i,unsigned int drpi){if(drpi == 0) return; fprintf_s(mFile, "setAttr \".drp[%i].drpi\" %i;\n", drp_i,drpi);}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	void setDropoff_Interp(size_t drp_i,const UnsignedintID& drpi){fprintf_s(mFile,"connectAttr \"");drpi.write(mFile);fprintf_s(mFile,"\" \"%s.drp[%i].drpi\";\n",mName.c_str(),drp_i);}
	/*output line modifier data for use by pfxToon node*/
	void setOutLineModifier(size_t olm_i,const LineModifierID& olm){fprintf_s(mFile,"connectAttr \"");olm.write(mFile);fprintf_s(mFile,"\" \"%s.olm[%i]\";\n",mName.c_str(),olm_i);}
	/*
	This determines the shape of the line modifier. There will be no effect outside the bounds of the selected shape.
	The dropoff graph attribute is defined relative to the shape, such that the right edge of the dropoff is the
	the outer edge of the shape, and the left is the shapes center.
	*/
	UnsignedintID getShape(){char buffer[4096];sprintf_s (buffer, "%s.shp",mName.c_str());return (const char*)buffer;}
	/*
	This value multiplies the current line width.  A value of 1.0 will have no
	effect and a value of zero will scale the width to zero.
	*/
	DoubleID getWidthScale(){char buffer[4096];sprintf_s (buffer, "%s.wsc",mName.c_str());return (const char*)buffer;}
	/*
	This value adds onto the current line width.  A value of 0.0 will have no
	effect and a value of 1.0 will grow the width by one.
	*/
	DoubleID getWidthOffset(){char buffer[4096];sprintf_s (buffer, "%s.wof",mName.c_str());return (const char*)buffer;}
	/*
	This value multiplies the current line opacity.  A value of 1.0 will have no
	effect and a value of zero will scale the opacity to zero.
	*/
	DoubleID getOpacityScale(){char buffer[4096];sprintf_s (buffer, "%s.osc",mName.c_str());return (const char*)buffer;}
	/*
	This value adds onto the current line opacity.  A value of 0.0 will have no
	effect and a value of 1.0 will make the lines fully opaque.
	*/
	DoubleID getOpacityOffset(){char buffer[4096];sprintf_s (buffer, "%s.oof",mName.c_str());return (const char*)buffer;}
	/*
	This value adds onto the current line surface offset.  A value of 0.0 will have no
	effect and a value of 1.0 will increase the offset by 1.0. Negative values will
	clamp when an offset of 0 is achieved.
	*/
	DoubleID getSurfaceOffset(){char buffer[4096];sprintf_s (buffer, "%s.sof",mName.c_str());return (const char*)buffer;}
	/*
	This value adds onto the current line extend.  A value of 0.0 will have no
	effect and a value of 1.0 will increase the extend by 1.0. Negative values will
	clamp when an extend of 0 is achieved.
	*/
	DoubleID getLineExtend(){char buffer[4096];sprintf_s (buffer, "%s.lex",mName.c_str());return (const char*)buffer;}
	/*If on then the color value is blended with the line color based on the droffoff value.*/
	BoolID getModifyColor(){char buffer[4096];sprintf_s (buffer, "%s.mcl",mName.c_str());return (const char*)buffer;}
	/*
	If modify color is on then this color is blended into the local
	line color based on the dropoff value.
	*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.clr",mName.c_str());return (const char*)buffer;}
	/*Red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.clr.crr",mName.c_str());return (const char*)buffer;}
	/*Green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.clr.crg",mName.c_str());return (const char*)buffer;}
	/*Blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.clr.crb",mName.c_str());return (const char*)buffer;}
	/*
	This can be used to scale the length and width of paint effects tubes generated.
	A value of 1.0 will have no effect and a value of 0.0 will scale the tubes to
	nothing, resulting in no tubes generated. The behavior is similar to modifying
	the brush global scale.  To have an effect this requires hat a brush with tubes=ON
	be used.
	*/
	DoubleID getTubeScale(){char buffer[4096];sprintf_s (buffer, "%s.tus",mName.c_str());return (const char*)buffer;}
	/*
	This can be used to reduce the number of paint effects tubes generated.
	A value of 0.0 will have no effect and a value of 1.0 will result
	in no tubes generated. To have an effect this requires that a brush with tubes=ON
	be used.
	*/
	DoubleID getTubeDropout(){char buffer[4096];sprintf_s (buffer, "%s.tud",mName.c_str());return (const char*)buffer;}
	/*
	This value adds onto the current branch dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and branches=ON be used.
	*/
	DoubleID getBranchDropout(){char buffer[4096];sprintf_s (buffer, "%s.bdp",mName.c_str());return (const char*)buffer;}
	/*
	This value adds onto the current branch dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and twigs=ON be used.
	*/
	DoubleID getTwigDropout(){char buffer[4096];sprintf_s (buffer, "%s.tdp",mName.c_str());return (const char*)buffer;}
	/*
	This value adds onto the current leaf dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and leaves=ON be used.
	*/
	DoubleID getLeafDropout(){char buffer[4096];sprintf_s (buffer, "%s.ldp",mName.c_str());return (const char*)buffer;}
	/*
	This value adds onto the current flower dropout value used by the paint
	effects brush. A value of 0.0 will have no effect and a value of 1.0 will increase
	the dropout by 1.0. To have an effect this requires that a brush with tubes=ON
	and flowers=ON be used.
	*/
	DoubleID getFlowerDropout(){char buffer[4096];sprintf_s (buffer, "%s.fdp",mName.c_str());return (const char*)buffer;}
	/*
	This value multiplies the size of leaves used by the paint
	effects brush. A value of 1.0 will have no effect and a value of 0.5 will reduce
	leaf size by  half. To have an effect this requires that a brush with tubes=ON
	and leaves=ON be used.
	*/
	DoubleID getLeafScale(){char buffer[4096];sprintf_s (buffer, "%s.lsc",mName.c_str());return (const char*)buffer;}
	/*
	This value multiplies the size of flowers used by the paint
	effects brush. A value of 1.0 will have no effect and a value of 0.5 will reduce
	flower size by  half. To have an effect this requires that a brush with tubes=ON
	and flowers=ON be used.
	*/
	DoubleID getFlowerScale(){char buffer[4096];sprintf_s (buffer, "%s.fsc",mName.c_str());return (const char*)buffer;}
	/*
	This acts as a force pushing tubes away from the center of the line modifier shape.
	Positive values will push away from the center while negative values will push towards
	the center.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	DoubleID getForce(){char buffer[4096];sprintf_s (buffer, "%s.frc",mName.c_str());return (const char*)buffer;}
	/*
	This acts as a force pushing tubes along the local x axis of the line modifier shape.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	DoubleID getDirectionalForce(){char buffer[4096];sprintf_s (buffer, "%s.dfc",mName.c_str());return (const char*)buffer;}
	/*
	This acts as a displacement pushing tubes away from the center of the line modifier shape.
	Positive values will push away from the center while negative values will push towards
	the center. This is similar to the force attribute, but tube segments further down the
	tube are not affected by the offset.
	To have an effect this requires that a brush with tubes=ON be used.
	*/
	DoubleID getDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.dsp",mName.c_str());return (const char*)buffer;}
	/*
	This acts as a displacement pushing tubes along the local x axis of the line modifier shape.
	To have an effect this requires that a brush with tubes=ON be used. This is similar to the
	directional force attribute, but tube segments further down the tube are not affected
	by the offset.
	*/
	DoubleID getDirectionalDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.ddc",mName.c_str());return (const char*)buffer;}
	/*
	This modulates the dropoff value with a 3D noise. This can provide variation for the
	parameters being modulated. For example the tube width can be randomized or wiggled
	in a noisy fashion using this attribute. The Noise Frequency attribute controls how
	detailed the noise is.
	*/
	DoubleID getDropoffNoise(){char buffer[4096];sprintf_s (buffer, "%s.don",mName.c_str());return (const char*)buffer;}
	/*
	The Noise Frequency attribute controls how detailed the dropoff noise is.
	Lower values result in a smoother noise. The 3D noise is defined relative to
	the local space of the line modifier shape.
	*/
	DoubleID getNoiseFrequency(){char buffer[4096];sprintf_s (buffer, "%s.nfr",mName.c_str());return (const char*)buffer;}
	/*
	This determines the range of effect within the bounds of the modifier. If the dropoff is set
	to a constant value of 1.0 (horizontal line) then lines will be uniformly modified inside
	the bounds of the dropoff shape, with a hard transition at the shape edge. If the right
	edge of the dropoff is instead ramped down to zero the transition will be gradual, with no
	modulation at the shape edge, with increasing modulation towards its center.
	The dropoff graph attribute is defined relative to the shape, such that the right edge of the dropoff is the
	the outer edge of the shape, and the left is the shapes center.
	*/
	const DropoffID& getDropoff(size_t drp_i){char buffer[4096];sprintf_s (buffer, "%s.drp[%i]",mName.c_str(),drp_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getDropoff_Position(size_t drp_i){char buffer[4096];sprintf_s (buffer, "%s.drp[%i].drpp",mName.c_str(),drp_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getDropoff_FloatValue(size_t drp_i){char buffer[4096];sprintf_s (buffer, "%s.drp[%i].drpfv",mName.c_str(),drp_i);return (const char*)buffer;}
	/*
	<b>Ramp Interpolation</b> controls the way the
	    intermediate values are calculated.  The values are:
	    <ul><b>None</b>: No interpolation is done; the different
	    colors just show up as different bands in the final texture.
	    <p/><b>Linear</b>: The values are interpolated linearly in RGB
	    color space.
	    <p/><b>Smooth</b>: The values are interpolated along a bell curve,
	    so that each color on the ramp dominates the region around it,
	    then blends quickly to the next color.
	    <p/><b>Spline</b>: The values are interpolated with a spline
	    curve, taking neighboring indices into account for greater smoothness.
	    </ul>
	*/
	const UnsignedintID& getDropoff_Interp(size_t drp_i){char buffer[4096];sprintf_s (buffer, "%s.drp[%i].drpi",mName.c_str(),drp_i);return (const char*)buffer;}
	/*output line modifier data for use by pfxToon node*/
	const LineModifierID& getOutLineModifier(size_t olm_i){char buffer[4096];sprintf_s (buffer, "%s.olm[%i]",mName.c_str(),olm_i);return (const char*)buffer;}
protected:
	LineModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Shape(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LINEMODIFIER_H__
