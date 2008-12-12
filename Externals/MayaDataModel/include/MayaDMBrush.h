/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BRUSH_H__
#define __MayaDM_BRUSH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
        This node contains shading and tube dynamics attributes
        that are used by stroke nodes for Maya Particle Paint.

</pre></p>
*/
class Brush : public DependNode
{
public:
	/*
	amount of curl away from the primary axis of the leaf.
	This is perpendicular to the leaf bend direction.
	This can both provide a more natural leaf shape and help
	create a more rounded shading when the flatness is 1.0.
	The left side of the ramp represents curl at the leaf
	base and the right side is the leaf tip.
	*/
	struct LeafCurl{
		float leafCurl_Position;
		float leafCurl_FloatValue;
		unsigned int leafCurl_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", leafCurl_Position);
			fprintf_s(file,"%f ", leafCurl_FloatValue);
			fprintf_s(file,"%i", leafCurl_Interp);
		}
	};
	/*
	amount of curl away from the primary axis of the petal.
	This is perpendicular to the petal bend direction.
	This can provide a more natural petal shape and help avoid
	interpenetration with neighboring petals.
	The left side of the ramp represents curl at the petal
	base and the right side is the petal tip.
	*/
	struct PetalCurl{
		float petalCurl_Position;
		float petalCurl_FloatValue;
		unsigned int petalCurl_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", petalCurl_Position);
			fprintf_s(file,"%f ", petalCurl_FloatValue);
			fprintf_s(file,"%i", petalCurl_Interp);
		}
	};
	/*
	multiplies the width along the tube determined by
	the base and tip width. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	struct WidthScale{
		float widthScale_Position;
		float widthScale_FloatValue;
		unsigned int widthScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", widthScale_Position);
			fprintf_s(file,"%f ", widthScale_FloatValue);
			fprintf_s(file,"%i", widthScale_Interp);
		}
	};
	/*
	multiplies the width along the leaf determined by
	the leaf base and tip widths. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	struct LeafWidthScale{
		float leafWidthScale_Position;
		float leafWidthScale_FloatValue;
		unsigned int leafWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", leafWidthScale_Position);
			fprintf_s(file,"%f ", leafWidthScale_FloatValue);
			fprintf_s(file,"%i", leafWidthScale_Interp);
		}
	};
	/*
	multiplies the width along the petal determined by
	the petal base and tip widths. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	struct PetalWidthScale{
		float petalWidthScale_Position;
		float petalWidthScale_FloatValue;
		unsigned int petalWidthScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", petalWidthScale_Position);
			fprintf_s(file,"%f ", petalWidthScale_FloatValue);
			fprintf_s(file,"%i", petalWidthScale_Interp);
		}
	};
	/*
	multiplies the twig lengths from root to tip of
	the parent branch.
	The left of the graph is the scale at the
	base of a tree and the right is the scale at the tip.
	*/
	struct TwigLengthScale{
		float twigLengthScale_Position;
		float twigLengthScale_FloatValue;
		unsigned int twigLengthScale_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", twigLengthScale_Position);
			fprintf_s(file,"%f ", twigLengthScale_FloatValue);
			fprintf_s(file,"%i", twigLengthScale_Interp);
		}
	};
	/*
	This defines a spherical reflection environment, where
	the left of the ramp represents light from the top of the sky, the right is
	the ground and the middle is the horizon. Currently it
	only works with the mesh brushtype.
	*/
	struct Environment{
		float environment_Position;
		float3 environment_Color;
		unsigned int environment_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", environment_Position);
			environment_Color.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%i", environment_Interp);
		}
	};
	/*
	<b>Reflection Rolloff</b> controls the reflectivity of the
	environment ramp based on the angle of the surface with the view.
	The horizontal dimension of the graph represents the brightness
	of reflections and the horizontal represents the facing
	angle with the view.
	<i>Tip:</i> to get a "wet" look (such as wet paint), make the
	edges more reflective.
	*/
	struct ReflectionRolloff{
		float reflectionRolloff_Position;
		float reflectionRolloff_FloatValue;
		unsigned int reflectionRolloff_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", reflectionRolloff_Position);
			fprintf_s(file,"%f ", reflectionRolloff_FloatValue);
			fprintf_s(file,"%i", reflectionRolloff_Interp);
		}
	};
public:
	Brush(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "brush"){}
	virtual ~Brush(){}
	/*output brush data for use by stroke nodes*/
	void setOutBrush(const DynBrushID& obr){fprintf_s(mFile,"connectAttr \"");obr.write(mFile);fprintf_s(mFile,"\" \"%s.obr\";\n",mName.c_str());}
	/*time value for animated effects*/
	void setTime(const TimeID& tim){fprintf_s(mFile,"connectAttr \"");tim.write(mFile);fprintf_s(mFile,"\" \"%s.tim\";\n",mName.c_str());}
	/*Scales all effects*/
	void setGlobalScale(double gsc){if(gsc == 1.0) return; fprintf_s(mFile, "setAttr \".gsc\" %f;\n", gsc);}
	/*Scales all effects*/
	void setGlobalScale(const DoubleID& gsc){fprintf_s(mFile,"connectAttr \"");gsc.write(mFile);fprintf_s(mFile,"\" \"%s.gsc\";\n",mName.c_str());}
	/*whether or not to use zbuffered occusion*/
	void setDepth(bool dep){if(dep == false) return; fprintf_s(mFile, "setAttr \".dep\" %i;\n", dep);}
	/*whether or not to use zbuffered occusion*/
	void setDepth(const BoolID& dep){fprintf_s(mFile,"connectAttr \"");dep.write(mFile);fprintf_s(mFile,"\" \"%s.dep\";\n",mName.c_str());}
	/*whether or not to write into the zbuffer( only if depth is ON )*/
	void setModifyDepth(bool mdp){if(mdp == true) return; fprintf_s(mFile, "setAttr \".mdp\" %i;\n", mdp);}
	/*whether or not to write into the zbuffer( only if depth is ON )*/
	void setModifyDepth(const BoolID& mdp){fprintf_s(mFile,"connectAttr \"");mdp.write(mFile);fprintf_s(mFile,"\" \"%s.mdp\";\n",mName.c_str());}
	/*whether or not to write into r,g,b*/
	void setModifyColor(bool mdc){if(mdc == true) return; fprintf_s(mFile, "setAttr \".mdc\" %i;\n", mdc);}
	/*whether or not to write into r,g,b*/
	void setModifyColor(const BoolID& mdc){fprintf_s(mFile,"connectAttr \"");mdc.write(mFile);fprintf_s(mFile,"\" \"%s.mdc\";\n",mName.c_str());}
	/*whether or not to write into the alpha channel*/
	void setModifyAlpha(bool mda){if(mda == true) return; fprintf_s(mFile, "setAttr \".mda\" %i;\n", mda);}
	/*whether or not to write into the alpha channel*/
	void setModifyAlpha(const BoolID& mda){fprintf_s(mFile,"connectAttr \"");mda.write(mFile);fprintf_s(mFile,"\" \"%s.mda\";\n",mName.c_str());}
	/*Use lights for shading.*/
	void setIlluminated(bool ill){if(ill == false) return; fprintf_s(mFile, "setAttr \".ill\" %i;\n", ill);}
	/*Use lights for shading.*/
	void setIlluminated(const BoolID& ill){fprintf_s(mFile,"connectAttr \"");ill.write(mFile);fprintf_s(mFile,"\" \"%s.ill\";\n",mName.c_str());}
	/*make brush strokes appear in depth map shadows*/
	void setCastShadows(bool csd){if(csd == false) return; fprintf_s(mFile, "setAttr \".csd\" %i;\n", csd);}
	/*make brush strokes appear in depth map shadows*/
	void setCastShadows(const BoolID& csd){fprintf_s(mFile,"connectAttr \"");csd.write(mFile);fprintf_s(mFile,"\" \"%s.csd\";\n",mName.c_str());}
	/*
	The tube width is scaled by the diffuse light
	intensity. Brighter regions will be thinner.
	Shadowed and dark regions will have full width
	tubes. Using negative values can have the reverse
	effect. The lighting used is a diffuse illumination
	that is relative to the local surface normal painted
	on by the stroke.
	*/
	void setLightingBasedWidth(double lbw){if(lbw == 0.0) return; fprintf_s(mFile, "setAttr \".lbw\" %f;\n", lbw);}
	/*
	The tube width is scaled by the diffuse light
	intensity. Brighter regions will be thinner.
	Shadowed and dark regions will have full width
	tubes. Using negative values can have the reverse
	effect. The lighting used is a diffuse illumination
	that is relative to the local surface normal painted
	on by the stroke.
	*/
	void setLightingBasedWidth(const DoubleID& lbw){fprintf_s(mFile,"connectAttr \"");lbw.write(mFile);fprintf_s(mFile,"\" \"%s.lbw\";\n",mName.c_str());}
	/*split tubes into branches*/
	void setBranches(bool brc){if(brc == false) return; fprintf_s(mFile, "setAttr \".brc\" %i;\n", brc);}
	/*split tubes into branches*/
	void setBranches(const BoolID& brc){fprintf_s(mFile,"connectAttr \"");brc.write(mFile);fprintf_s(mFile,"\" \"%s.brc\";\n",mName.c_str());}
	/*create twigs as offshoots on branches*/
	void setTwigs(bool twg){if(twg == false) return; fprintf_s(mFile, "setAttr \".twg\" %i;\n", twg);}
	/*create twigs as offshoots on branches*/
	void setTwigs(const BoolID& twg){fprintf_s(mFile,"connectAttr \"");twg.write(mFile);fprintf_s(mFile,"\" \"%s.twg\";\n",mName.c_str());}
	/*create bud swellings at the tips of branches and twigs*/
	void setBuds(bool bud){if(bud == false) return; fprintf_s(mFile, "setAttr \".bud\" %i;\n", bud);}
	/*create bud swellings at the tips of branches and twigs*/
	void setBuds(const BoolID& bud){fprintf_s(mFile,"connectAttr \"");bud.write(mFile);fprintf_s(mFile,"\" \"%s.bud\";\n",mName.c_str());}
	/*create leaves on branches and twigs*/
	void setLeaves(bool lvs){if(lvs == false) return; fprintf_s(mFile, "setAttr \".lvs\" %i;\n", lvs);}
	/*create leaves on branches and twigs*/
	void setLeaves(const BoolID& lvs){fprintf_s(mFile,"connectAttr \"");lvs.write(mFile);fprintf_s(mFile,"\" \"%s.lvs\";\n",mName.c_str());}
	/*create flower petals on branches, twigs and buds*/
	void setFlowers(bool flw){if(flw == false) return; fprintf_s(mFile, "setAttr \".flw\" %i;\n", flw);}
	/*create flower petals on branches, twigs and buds*/
	void setFlowers(const BoolID& flw){fprintf_s(mFile,"connectAttr \"");flw.write(mFile);fprintf_s(mFile,"\" \"%s.flw\";\n",mName.c_str());}
	/*
	Method used for brushstamp rendering
	0 - Paint Brush
	1 - Smear Brush
	2 - Blur Brush
	3 - Erasor Brush
	4 - Thin Line Brush
	5 - Triangle Mesh Tube
	*/
	void setBrushType(unsigned int brt){if(brt == 0) return; fprintf_s(mFile, "setAttr \".brt\" %i;\n", brt);}
	/*
	Method used for brushstamp rendering
	0 - Paint Brush
	1 - Smear Brush
	2 - Blur Brush
	3 - Erasor Brush
	4 - Thin Line Brush
	5 - Triangle Mesh Tube
	*/
	void setBrushType(const UnsignedintID& brt){fprintf_s(mFile,"connectAttr \"");brt.write(mFile);fprintf_s(mFile,"\" \"%s.brt\";\n",mName.c_str());}
	/*the worldspace width of the brushstroke*/
	void setBrushWidth(double bwd){if(bwd == 0.05) return; fprintf_s(mFile, "setAttr \".bwd\" %f;\n", bwd);}
	/*the worldspace width of the brushstroke*/
	void setBrushWidth(const DoubleID& bwd){fprintf_s(mFile,"connectAttr \"");bwd.write(mFile);fprintf_s(mFile,"\" \"%s.bwd\";\n",mName.c_str());}
	/*whether or not to make the line width constant for different depths from the view*/
	void setScreenspaceWidth(bool spw){if(spw == false) return; fprintf_s(mFile, "setAttr \".spw\" %i;\n", spw);}
	/*whether or not to make the line width constant for different depths from the view*/
	void setScreenspaceWidth(const BoolID& spw){fprintf_s(mFile,"connectAttr \"");spw.write(mFile);fprintf_s(mFile,"\" \"%s.spw\";\n",mName.c_str());}
	/*
	This controls the amount that the distance from
	the eye affects the tube width when screenSpace width
	is enabled. At a value of 0.0 the width is constant
	while at a value of 1.0 it behaves as if screenspace
	width is OFF.
	*/
	void setDistanceScaling(double dsl){if(dsl == 0.0) return; fprintf_s(mFile, "setAttr \".dsl\" %f;\n", dsl);}
	/*
	This controls the amount that the distance from
	the eye affects the tube width when screenSpace width
	is enabled. At a value of 0.0 the width is constant
	while at a value of 1.0 it behaves as if screenspace
	width is OFF.
	*/
	void setDistanceScaling(const DoubleID& dsl){fprintf_s(mFile,"connectAttr \"");dsl.write(mFile);fprintf_s(mFile,"\" \"%s.dsl\";\n",mName.c_str());}
	/*
	When screenspace width is enabled this controls
	the smallest width a stroke can be in pixels.
	It is useful for toon lines when one wishes to
	avoid very thin lines.
	*/
	void setMinPixelWidth(double mpw){if(mpw == 0.0) return; fprintf_s(mFile, "setAttr \".mpw\" %f;\n", mpw);}
	/*
	When screenspace width is enabled this controls
	the smallest width a stroke can be in pixels.
	It is useful for toon lines when one wishes to
	avoid very thin lines.
	*/
	void setMinPixelWidth(const DoubleID& mpw){fprintf_s(mFile,"connectAttr \"");mpw.write(mFile);fprintf_s(mFile,"\" \"%s.mpw\";\n",mName.c_str());}
	/*
	When screenspace width is enabled this controls
	the largest width a stroke can be in pixels.
	It is useful for toon lines when one wishes to
	avoid very fat lines.
	*/
	void setMaxPixelWidth(double mxp){if(mxp == 1000.0) return; fprintf_s(mFile, "setAttr \".mxp\" %f;\n", mxp);}
	/*
	When screenspace width is enabled this controls
	the largest width a stroke can be in pixels.
	It is useful for toon lines when one wishes to
	avoid very fat lines.
	*/
	void setMaxPixelWidth(const DoubleID& mxp){fprintf_s(mFile,"connectAttr \"");mxp.write(mFile);fprintf_s(mFile,"\" \"%s.mxp\";\n",mName.c_str());}
	/*the spacing of stamps relative to brush width*/
	void setStampDensity(double sdn){if(sdn == 8.0) return; fprintf_s(mFile, "setAttr \".sdn\" %f;\n", sdn);}
	/*the spacing of stamps relative to brush width*/
	void setStampDensity(const DoubleID& sdn){fprintf_s(mFile,"connectAttr \"");sdn.write(mFile);fprintf_s(mFile,"\" \"%s.sdn\";\n",mName.c_str());}
	/*control for brush edge blurring*/
	void setSoftness(double sft){if(sft == 0.2) return; fprintf_s(mFile, "setAttr \".sft\" %f;\n", sft);}
	/*control for brush edge blurring*/
	void setSoftness(const DoubleID& sft){fprintf_s(mFile,"connectAttr \"");sft.write(mFile);fprintf_s(mFile,"\" \"%s.sft\";\n",mName.c_str());}
	/*
	<b>EdgeAntialias</b> determines whether or not to antialias brushstroke edges.
	Note that this does not affect paint or render speed and should be left
	on unless hard jagged edges are desired.
	*/
	void setEdgeAntialias(bool eaa){if(eaa == true) return; fprintf_s(mFile, "setAttr \".eaa\" %i;\n", eaa);}
	/*
	<b>EdgeAntialias</b> determines whether or not to antialias brushstroke edges.
	Note that this does not affect paint or render speed and should be left
	on unless hard jagged edges are desired.
	*/
	void setEdgeAntialias(const BoolID& eaa){fprintf_s(mFile,"connectAttr \"");eaa.write(mFile);fprintf_s(mFile,"\" \"%s.eaa\";\n",mName.c_str());}
	/*
	<b>EdgeClip</b> allows one to make 3D strokes render as if
	they are painted directly onto a surface's texture.
	The edgeClipDepth attribute controls how far in front of a
	surface the stroke can be before it becomes invisible.
	Thus 3D strokes that sit close to an objects surface
	can be seen if the surface is behind them, but not if the
	surface edge is in profile.
	*/
	void setEdgeClip(bool ecl){if(ecl == false) return; fprintf_s(mFile, "setAttr \".ecl\" %i;\n", ecl);}
	/*
	<b>EdgeClip</b> allows one to make 3D strokes render as if
	they are painted directly onto a surface's texture.
	The edgeClipDepth attribute controls how far in front of a
	surface the stroke can be before it becomes invisible.
	Thus 3D strokes that sit close to an objects surface
	can be seen if the surface is behind them, but not if the
	surface edge is in profile.
	*/
	void setEdgeClip(const BoolID& ecl){fprintf_s(mFile,"connectAttr \"");ecl.write(mFile);fprintf_s(mFile,"\" \"%s.ecl\";\n",mName.c_str());}
	/*
	<b>EdgeClipDepth</b> controls how close an object behind a
	stroke must be in order for the stroke to be visible.
	*/
	void setEdgeClipDepth(double ecd){if(ecd == 0.1) return; fprintf_s(mFile, "setAttr \".ecd\" %f;\n", ecd);}
	/*
	<b>EdgeClipDepth</b> controls how close an object behind a
	stroke must be in order for the stroke to be visible.
	*/
	void setEdgeClipDepth(const DoubleID& ecd){fprintf_s(mFile,"connectAttr \"");ecd.write(mFile);fprintf_s(mFile,"\" \"%s.ecd\";\n",mName.c_str());}
	/*
	<b>OcclusionWidthScale</b> scale stamp size down based on overlap
	by forground objects. The full stamp is always drawn, avoiding
	antialias problems where occluded by non-paint effects forground objects.
	The size of the stamp is reduced to zero (and thus hidden) when the
	entire stamp is occluded.
	*/
	void setOcclusionWidthScale(bool ows){if(ows == false) return; fprintf_s(mFile, "setAttr \".ows\" %i;\n", ows);}
	/*
	<b>OcclusionWidthScale</b> scale stamp size down based on overlap
	by forground objects. The full stamp is always drawn, avoiding
	antialias problems where occluded by non-paint effects forground objects.
	The size of the stamp is reduced to zero (and thus hidden) when the
	entire stamp is occluded.
	*/
	void setOcclusionWidthScale(const BoolID& ows){fprintf_s(mFile,"connectAttr \"");ows.write(mFile);fprintf_s(mFile,"\" \"%s.ows\";\n",mName.c_str());}
	/*number of iterations of the blur filter each stamp*/
	void setBlurIntensity(int bin){if(bin == 4) return; fprintf_s(mFile, "setAttr \".bin\" %i;\n", bin);}
	/*number of iterations of the blur filter each stamp*/
	void setBlurIntensity(const IntID& bin){fprintf_s(mFile,"connectAttr \"");bin.write(mFile);fprintf_s(mFile,"\" \"%s.bin\";\n",mName.c_str());}
	/*input color*/
	void setColor1(const float3& cl1){fprintf_s(mFile, "setAttr \".cl1\" -type \"float3\" ");cl1.write(mFile);fprintf_s(mFile,";\n");}
	/*input color*/
	void setColor1(const Float3ID& cl1){fprintf_s(mFile,"connectAttr \"");cl1.write(mFile);fprintf_s(mFile,"\" \"%s.cl1\";\n",mName.c_str());}
	/*color1 Red value*/
	void setColor1R(float c1r){if(c1r == 0.0) return; fprintf_s(mFile, "setAttr \".cl1.c1r\" %f;\n", c1r);}
	/*color1 Red value*/
	void setColor1R(const FloatID& c1r){fprintf_s(mFile,"connectAttr \"");c1r.write(mFile);fprintf_s(mFile,"\" \"%s.cl1.c1r\";\n",mName.c_str());}
	/*color1 Green value*/
	void setColor1G(float c1g){if(c1g == 0.0) return; fprintf_s(mFile, "setAttr \".cl1.c1g\" %f;\n", c1g);}
	/*color1 Green value*/
	void setColor1G(const FloatID& c1g){fprintf_s(mFile,"connectAttr \"");c1g.write(mFile);fprintf_s(mFile,"\" \"%s.cl1.c1g\";\n",mName.c_str());}
	/*color1 Blue value*/
	void setColor1B(float c1b){if(c1b == 0.0) return; fprintf_s(mFile, "setAttr \".cl1.c1b\" %f;\n", c1b);}
	/*color1 Blue value*/
	void setColor1B(const FloatID& c1b){fprintf_s(mFile,"connectAttr \"");c1b.write(mFile);fprintf_s(mFile,"\" \"%s.cl1.c1b\";\n",mName.c_str());}
	/*input color for tube ends*/
	void setColor2(const float3& cl2){fprintf_s(mFile, "setAttr \".cl2\" -type \"float3\" ");cl2.write(mFile);fprintf_s(mFile,";\n");}
	/*input color for tube ends*/
	void setColor2(const Float3ID& cl2){fprintf_s(mFile,"connectAttr \"");cl2.write(mFile);fprintf_s(mFile,"\" \"%s.cl2\";\n",mName.c_str());}
	/*color2 Red value*/
	void setColor2R(float c2r){if(c2r == 1.0) return; fprintf_s(mFile, "setAttr \".cl2.c2r\" %f;\n", c2r);}
	/*color2 Red value*/
	void setColor2R(const FloatID& c2r){fprintf_s(mFile,"connectAttr \"");c2r.write(mFile);fprintf_s(mFile,"\" \"%s.cl2.c2r\";\n",mName.c_str());}
	/*color2 Green value*/
	void setColor2G(float c2g){if(c2g == 1.0) return; fprintf_s(mFile, "setAttr \".cl2.c2g\" %f;\n", c2g);}
	/*color2 Green value*/
	void setColor2G(const FloatID& c2g){fprintf_s(mFile,"connectAttr \"");c2g.write(mFile);fprintf_s(mFile,"\" \"%s.cl2.c2g\";\n",mName.c_str());}
	/*color2 Blue value*/
	void setColor2B(float c2b){if(c2b == 1.0) return; fprintf_s(mFile, "setAttr \".cl2.c2b\" %f;\n", c2b);}
	/*color2 Blue value*/
	void setColor2B(const FloatID& c2b){fprintf_s(mFile,"connectAttr \"");c2b.write(mFile);fprintf_s(mFile,"\" \"%s.cl2.c2b\";\n",mName.c_str());}
	/*input color transparency*/
	void setTransparency1(const float3& tn1){fprintf_s(mFile, "setAttr \".tn1\" -type \"float3\" ");tn1.write(mFile);fprintf_s(mFile,";\n");}
	/*input color transparency*/
	void setTransparency1(const Float3ID& tn1){fprintf_s(mFile,"connectAttr \"");tn1.write(mFile);fprintf_s(mFile,"\" \"%s.tn1\";\n",mName.c_str());}
	/*transparency1 Red value*/
	void setTransparency1R(float t1r){if(t1r == 0.0) return; fprintf_s(mFile, "setAttr \".tn1.t1r\" %f;\n", t1r);}
	/*transparency1 Red value*/
	void setTransparency1R(const FloatID& t1r){fprintf_s(mFile,"connectAttr \"");t1r.write(mFile);fprintf_s(mFile,"\" \"%s.tn1.t1r\";\n",mName.c_str());}
	/*transparency1 Green value*/
	void setTransparency1G(float t1g){if(t1g == 0.0) return; fprintf_s(mFile, "setAttr \".tn1.t1g\" %f;\n", t1g);}
	/*transparency1 Green value*/
	void setTransparency1G(const FloatID& t1g){fprintf_s(mFile,"connectAttr \"");t1g.write(mFile);fprintf_s(mFile,"\" \"%s.tn1.t1g\";\n",mName.c_str());}
	/*transparency1 Blue value*/
	void setTransparency1B(float t1b){if(t1b == 0.0) return; fprintf_s(mFile, "setAttr \".tn1.t1b\" %f;\n", t1b);}
	/*transparency1 Blue value*/
	void setTransparency1B(const FloatID& t1b){fprintf_s(mFile,"connectAttr \"");t1b.write(mFile);fprintf_s(mFile,"\" \"%s.tn1.t1b\";\n",mName.c_str());}
	/*input color transparency for tube end*/
	void setTransparency2(const float3& tn2){fprintf_s(mFile, "setAttr \".tn2\" -type \"float3\" ");tn2.write(mFile);fprintf_s(mFile,";\n");}
	/*input color transparency for tube end*/
	void setTransparency2(const Float3ID& tn2){fprintf_s(mFile,"connectAttr \"");tn2.write(mFile);fprintf_s(mFile,"\" \"%s.tn2\";\n",mName.c_str());}
	/*transparency2 Red value*/
	void setTransparency2R(float t2r){if(t2r == 0.0) return; fprintf_s(mFile, "setAttr \".tn2.t2r\" %f;\n", t2r);}
	/*transparency2 Red value*/
	void setTransparency2R(const FloatID& t2r){fprintf_s(mFile,"connectAttr \"");t2r.write(mFile);fprintf_s(mFile,"\" \"%s.tn2.t2r\";\n",mName.c_str());}
	/*transparency2 Green value*/
	void setTransparency2G(float t2g){if(t2g == 0.0) return; fprintf_s(mFile, "setAttr \".tn2.t2g\" %f;\n", t2g);}
	/*transparency2 Green value*/
	void setTransparency2G(const FloatID& t2g){fprintf_s(mFile,"connectAttr \"");t2g.write(mFile);fprintf_s(mFile,"\" \"%s.tn2.t2g\";\n",mName.c_str());}
	/*transparency2 Blue value*/
	void setTransparency2B(float t2b){if(t2b == 0.0) return; fprintf_s(mFile, "setAttr \".tn2.t2b\" %f;\n", t2b);}
	/*transparency2 Blue value*/
	void setTransparency2B(const FloatID& t2b){fprintf_s(mFile,"connectAttr \"");t2b.write(mFile);fprintf_s(mFile,"\" \"%s.tn2.t2b\";\n",mName.c_str());}
	/*input incandescence (color addition)*/
	void setIncandescence1(const float3& in1){fprintf_s(mFile, "setAttr \".in1\" -type \"float3\" ");in1.write(mFile);fprintf_s(mFile,";\n");}
	/*input incandescence (color addition)*/
	void setIncandescence1(const Float3ID& in1){fprintf_s(mFile,"connectAttr \"");in1.write(mFile);fprintf_s(mFile,"\" \"%s.in1\";\n",mName.c_str());}
	/*incandescence1 Red value*/
	void setIncandescence1R(float i1r){if(i1r == 0.0) return; fprintf_s(mFile, "setAttr \".in1.i1r\" %f;\n", i1r);}
	/*incandescence1 Red value*/
	void setIncandescence1R(const FloatID& i1r){fprintf_s(mFile,"connectAttr \"");i1r.write(mFile);fprintf_s(mFile,"\" \"%s.in1.i1r\";\n",mName.c_str());}
	/*incandescence1 Green value*/
	void setIncandescence1G(float i1g){if(i1g == 0.0) return; fprintf_s(mFile, "setAttr \".in1.i1g\" %f;\n", i1g);}
	/*incandescence1 Green value*/
	void setIncandescence1G(const FloatID& i1g){fprintf_s(mFile,"connectAttr \"");i1g.write(mFile);fprintf_s(mFile,"\" \"%s.in1.i1g\";\n",mName.c_str());}
	/*incandescence1 Blue value*/
	void setIncandescence1B(float i1b){if(i1b == 0.0) return; fprintf_s(mFile, "setAttr \".in1.i1b\" %f;\n", i1b);}
	/*incandescence1 Blue value*/
	void setIncandescence1B(const FloatID& i1b){fprintf_s(mFile,"connectAttr \"");i1b.write(mFile);fprintf_s(mFile,"\" \"%s.in1.i1b\";\n",mName.c_str());}
	/*input incandescence for tube end*/
	void setIncandescence2(const float3& in2){fprintf_s(mFile, "setAttr \".in2\" -type \"float3\" ");in2.write(mFile);fprintf_s(mFile,";\n");}
	/*input incandescence for tube end*/
	void setIncandescence2(const Float3ID& in2){fprintf_s(mFile,"connectAttr \"");in2.write(mFile);fprintf_s(mFile,"\" \"%s.in2\";\n",mName.c_str());}
	/*incandescence2 Red value*/
	void setIncandescence2R(float i2r){if(i2r == 0.0) return; fprintf_s(mFile, "setAttr \".in2.i2r\" %f;\n", i2r);}
	/*incandescence2 Red value*/
	void setIncandescence2R(const FloatID& i2r){fprintf_s(mFile,"connectAttr \"");i2r.write(mFile);fprintf_s(mFile,"\" \"%s.in2.i2r\";\n",mName.c_str());}
	/*incandescence2 Green value*/
	void setIncandescence2G(float i2g){if(i2g == 0.0) return; fprintf_s(mFile, "setAttr \".in2.i2g\" %f;\n", i2g);}
	/*incandescence2 Green value*/
	void setIncandescence2G(const FloatID& i2g){fprintf_s(mFile,"connectAttr \"");i2g.write(mFile);fprintf_s(mFile,"\" \"%s.in2.i2g\";\n",mName.c_str());}
	/*incandescence2 Blue value*/
	void setIncandescence2B(float i2b){if(i2b == 0.0) return; fprintf_s(mFile, "setAttr \".in2.i2b\" %f;\n", i2b);}
	/*incandescence2 Blue value*/
	void setIncandescence2B(const FloatID& i2b){fprintf_s(mFile,"connectAttr \"");i2b.write(mFile);fprintf_s(mFile,"\" \"%s.in2.i2b\";\n",mName.c_str());}
	/*input color for specular highlights*/
	void setSpecularColor(const float3& spc){fprintf_s(mFile, "setAttr \".spc\" -type \"float3\" ");spc.write(mFile);fprintf_s(mFile,";\n");}
	/*input color for specular highlights*/
	void setSpecularColor(const Float3ID& spc){fprintf_s(mFile,"connectAttr \"");spc.write(mFile);fprintf_s(mFile,"\" \"%s.spc\";\n",mName.c_str());}
	/*specular Red value*/
	void setSpecularColorR(float spr){if(spr == 1.0) return; fprintf_s(mFile, "setAttr \".spc.spr\" %f;\n", spr);}
	/*specular Red value*/
	void setSpecularColorR(const FloatID& spr){fprintf_s(mFile,"connectAttr \"");spr.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spr\";\n",mName.c_str());}
	/*specular Green value*/
	void setSpecularColorG(float spg){if(spg == 1.0) return; fprintf_s(mFile, "setAttr \".spc.spg\" %f;\n", spg);}
	/*specular Green value*/
	void setSpecularColorG(const FloatID& spg){fprintf_s(mFile,"connectAttr \"");spg.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spg\";\n",mName.c_str());}
	/*specular Blue value*/
	void setSpecularColorB(float spb){if(spb == 1.0) return; fprintf_s(mFile, "setAttr \".spc.spb\" %f;\n", spb);}
	/*specular Blue value*/
	void setSpecularColorB(const FloatID& spb){fprintf_s(mFile,"connectAttr \"");spb.write(mFile);fprintf_s(mFile,"\" \"%s.spc.spb\";\n",mName.c_str());}
	/*intensity of specular highlights*/
	void setSpecular(double spe){if(spe == 0.0) return; fprintf_s(mFile, "setAttr \".spe\" %f;\n", spe);}
	/*intensity of specular highlights*/
	void setSpecular(const DoubleID& spe){fprintf_s(mFile,"connectAttr \"");spe.write(mFile);fprintf_s(mFile,"\" \"%s.spe\";\n",mName.c_str());}
	/*focus or size of specular highlights*/
	void setSpecularPower(double spp){if(spp == 10.0) return; fprintf_s(mFile, "setAttr \".spp\" %f;\n", spp);}
	/*focus or size of specular highlights*/
	void setSpecularPower(const DoubleID& spp){fprintf_s(mFile,"connectAttr \"");spp.write(mFile);fprintf_s(mFile,"\" \"%s.spp\";\n",mName.c_str());}
	/*blend factor between translucent and lambertian shading*/
	void setTranslucence(double trn){if(trn == 0.2) return; fprintf_s(mFile, "setAttr \".trn\" %f;\n", trn);}
	/*blend factor between translucent and lambertian shading*/
	void setTranslucence(const DoubleID& trn){fprintf_s(mFile,"connectAttr \"");trn.write(mFile);fprintf_s(mFile,"\" \"%s.trn\";\n",mName.c_str());}
	/*intensity of glow effect*/
	void setGlow(double glw){if(glw == 0.0) return; fprintf_s(mFile, "setAttr \".glw\" %f;\n", glw);}
	/*intensity of glow effect*/
	void setGlow(const DoubleID& glw){fprintf_s(mFile,"connectAttr \"");glw.write(mFile);fprintf_s(mFile,"\" \"%s.glw\";\n",mName.c_str());}
	/*input color for glow*/
	void setGlowColor(const float3& glc){fprintf_s(mFile, "setAttr \".glc\" -type \"float3\" ");glc.write(mFile);fprintf_s(mFile,";\n");}
	/*input color for glow*/
	void setGlowColor(const Float3ID& glc){fprintf_s(mFile,"connectAttr \"");glc.write(mFile);fprintf_s(mFile,"\" \"%s.glc\";\n",mName.c_str());}
	/*glow Red value*/
	void setGlowColorR(float glr){if(glr == 0.5) return; fprintf_s(mFile, "setAttr \".glc.glr\" %f;\n", glr);}
	/*glow Red value*/
	void setGlowColorR(const FloatID& glr){fprintf_s(mFile,"connectAttr \"");glr.write(mFile);fprintf_s(mFile,"\" \"%s.glc.glr\";\n",mName.c_str());}
	/*glow Green value*/
	void setGlowColorG(float glg){if(glg == 0.5) return; fprintf_s(mFile, "setAttr \".glc.glg\" %f;\n", glg);}
	/*glow Green value*/
	void setGlowColorG(const FloatID& glg){fprintf_s(mFile,"connectAttr \"");glg.write(mFile);fprintf_s(mFile,"\" \"%s.glc.glg\";\n",mName.c_str());}
	/*glow Blue value*/
	void setGlowColorB(float glb){if(glb == 0.5) return; fprintf_s(mFile, "setAttr \".glc.glb\" %f;\n", glb);}
	/*glow Blue value*/
	void setGlowColorB(const FloatID& glb){fprintf_s(mFile,"connectAttr \"");glb.write(mFile);fprintf_s(mFile,"\" \"%s.glc.glb\";\n",mName.c_str());}
	/*amount to scale brush size by for glow stamp*/
	void setGlowSpread(double gls){if(gls == 3.0) return; fprintf_s(mFile, "setAttr \".gls\" %f;\n", gls);}
	/*amount to scale brush size by for glow stamp*/
	void setGlowSpread(const DoubleID& gls){fprintf_s(mFile,"connectAttr \"");gls.write(mFile);fprintf_s(mFile,"\" \"%s.gls\";\n",mName.c_str());}
	/*intensity of post render shaderglow effect*/
	void setShaderGlow(double sgl){if(sgl == 0.0) return; fprintf_s(mFile, "setAttr \".sgl\" %f;\n", sgl);}
	/*intensity of post render shaderglow effect*/
	void setShaderGlow(const DoubleID& sgl){fprintf_s(mFile,"connectAttr \"");sgl.write(mFile);fprintf_s(mFile,"\" \"%s.sgl\";\n",mName.c_str());}
	/*random deviation in hue of tubes*/
	void setHueRand(double chr){if(chr == 0.0) return; fprintf_s(mFile, "setAttr \".chr\" %f;\n", chr);}
	/*random deviation in hue of tubes*/
	void setHueRand(const DoubleID& chr){fprintf_s(mFile,"connectAttr \"");chr.write(mFile);fprintf_s(mFile,"\" \"%s.chr\";\n",mName.c_str());}
	/*random deviation in color saturation of tubes*/
	void setSatRand(double csr){if(csr == 0.0) return; fprintf_s(mFile, "setAttr \".csr\" %f;\n", csr);}
	/*random deviation in color saturation of tubes*/
	void setSatRand(const DoubleID& csr){fprintf_s(mFile,"connectAttr \"");csr.write(mFile);fprintf_s(mFile,"\" \"%s.csr\";\n",mName.c_str());}
	/*random deviation in brighness value of tubes*/
	void setValRand(double cvr){if(cvr == 0.0) return; fprintf_s(mFile, "setAttr \".cvr\" %f;\n", cvr);}
	/*random deviation in brighness value of tubes*/
	void setValRand(const DoubleID& cvr){fprintf_s(mFile,"connectAttr \"");cvr.write(mFile);fprintf_s(mFile,"\" \"%s.cvr\";\n",mName.c_str());}
	/*distance from base of tube at which it becomes fully visible*/
	void setRootFade(double rfd){if(rfd == 0.0) return; fprintf_s(mFile, "setAttr \".rfd\" %f;\n", rfd);}
	/*distance from base of tube at which it becomes fully visible*/
	void setRootFade(const DoubleID& rfd){fprintf_s(mFile,"connectAttr \"");rfd.write(mFile);fprintf_s(mFile,"\" \"%s.rfd\";\n",mName.c_str());}
	/*distance from end of tube at which it becomes fully visible*/
	void setTipFade(double tfd){if(tfd == 0.0) return; fprintf_s(mFile, "setAttr \".tfd\" %f;\n", tfd);}
	/*distance from end of tube at which it becomes fully visible*/
	void setTipFade(const DoubleID& tfd){fprintf_s(mFile,"connectAttr \"");tfd.write(mFile);fprintf_s(mFile,"\" \"%s.tfd\";\n",mName.c_str());}
	/*
	create 3D surface shadow simulation or simple 2D dropshadow
	0 - none
	1 - 2D offset shadow
	2 - 3D simulated cast shadow
	*/
	void setFakeShadow(unsigned int fks){if(fks == 0) return; fprintf_s(mFile, "setAttr \".fks\" %i;\n", fks);}
	/*
	create 3D surface shadow simulation or simple 2D dropshadow
	0 - none
	1 - 2D offset shadow
	2 - 3D simulated cast shadow
	*/
	void setFakeShadow(const UnsignedintID& fks){fprintf_s(mFile,"connectAttr \"");fks.write(mFile);fprintf_s(mFile,"\" \"%s.fks\";\n",mName.c_str());}
	/*2D drop shadow offset*/
	void setShadowOffset(double sof){if(sof == 0.5) return; fprintf_s(mFile, "setAttr \".sof\" %f;\n", sof);}
	/*2D drop shadow offset*/
	void setShadowOffset(const DoubleID& sof){fprintf_s(mFile,"connectAttr \"");sof.write(mFile);fprintf_s(mFile,"\" \"%s.sof\";\n",mName.c_str());}
	/*the softness of fake shadows*/
	void setShadowDiffusion(double sdf){if(sdf == 0.1) return; fprintf_s(mFile, "setAttr \".sdf\" %f;\n", sdf);}
	/*the softness of fake shadows*/
	void setShadowDiffusion(const DoubleID& sdf){fprintf_s(mFile,"connectAttr \"");sdf.write(mFile);fprintf_s(mFile,"\" \"%s.sdf\";\n",mName.c_str());}
	/*visibility of simulated shadows*/
	void setShadowTransparency(double stn){if(stn == 0.8) return; fprintf_s(mFile, "setAttr \".stn\" %f;\n", stn);}
	/*visibility of simulated shadows*/
	void setShadowTransparency(const DoubleID& stn){fprintf_s(mFile,"connectAttr \"");stn.write(mFile);fprintf_s(mFile,"\" \"%s.stn\";\n",mName.c_str());}
	/*shadow strokes on awayfacing side of parent surface*/
	void setBackShadow(double bks){if(bks == 0.0) return; fprintf_s(mFile, "setAttr \".bks\" %f;\n", bks);}
	/*shadow strokes on awayfacing side of parent surface*/
	void setBackShadow(const DoubleID& bks){fprintf_s(mFile,"connectAttr \"");bks.write(mFile);fprintf_s(mFile,"\" \"%s.bks\";\n",mName.c_str());}
	/*randomization of tube brightness*/
	void setBrightnessRand(double brn){if(brn == 0.0) return; fprintf_s(mFile, "setAttr \".brn\" %f;\n", brn);}
	/*randomization of tube brightness*/
	void setBrightnessRand(const DoubleID& brn){fprintf_s(mFile,"connectAttr \"");brn.write(mFile);fprintf_s(mFile,"\" \"%s.brn\";\n",mName.c_str());}
	/*shadow from brushstamp center*/
	void setCenterShadow(double cns){if(cns == 0.0) return; fprintf_s(mFile, "setAttr \".cns\" %f;\n", cns);}
	/*shadow from brushstamp center*/
	void setCenterShadow(const DoubleID& cns){fprintf_s(mFile,"connectAttr \"");cns.write(mFile);fprintf_s(mFile,"\" \"%s.cns\";\n",mName.c_str());}
	/*
	define shadow as depth from surface, or distance from path
	0 - Surface Depth
	1 - Path Dist
	*/
	void setDepthShadowType(unsigned int dpt){if(dpt == 0) return; fprintf_s(mFile, "setAttr \".dpt\" %i;\n", dpt);}
	/*
	define shadow as depth from surface, or distance from path
	0 - Surface Depth
	1 - Path Dist
	*/
	void setDepthShadowType(const UnsignedintID& dpt){fprintf_s(mFile,"connectAttr \"");dpt.write(mFile);fprintf_s(mFile,"\" \"%s.dpt\";\n",mName.c_str());}
	/*darkness of the depth shadow*/
	void setDepthShadow(double dpl){if(dpl == 0.0) return; fprintf_s(mFile, "setAttr \".dpl\" %f;\n", dpl);}
	/*darkness of the depth shadow*/
	void setDepthShadow(const DoubleID& dpl){fprintf_s(mFile,"connectAttr \"");dpl.write(mFile);fprintf_s(mFile,"\" \"%s.dpl\";\n",mName.c_str());}
	/*shadow offset distance*/
	void setDepthShadowDepth(double dps){if(dps == 0.0) return; fprintf_s(mFile, "setAttr \".dps\" %f;\n", dps);}
	/*shadow offset distance*/
	void setDepthShadowDepth(const DoubleID& dps){fprintf_s(mFile,"connectAttr \"");dps.write(mFile);fprintf_s(mFile,"\" \"%s.dps\";\n",mName.c_str());}
	/*illuminate using light nodes*/
	void setRealLights(bool rll){if(rll == false) return; fprintf_s(mFile, "setAttr \".rll\" %i;\n", rll);}
	/*illuminate using light nodes*/
	void setRealLights(const BoolID& rll){fprintf_s(mFile,"connectAttr \"");rll.write(mFile);fprintf_s(mFile,"\" \"%s.rll\";\n",mName.c_str());}
	/*direction of simple directional lightsource*/
	void setLightDirection(const double3& ldr){fprintf_s(mFile, "setAttr \".ldr\" -type \"double3\" ");ldr.write(mFile);fprintf_s(mFile,";\n");}
	/*direction of simple directional lightsource*/
	void setLightDirection(const Double3ID& ldr){fprintf_s(mFile,"connectAttr \"");ldr.write(mFile);fprintf_s(mFile,"\" \"%s.ldr\";\n",mName.c_str());}
	/*X value for light direction*/
	void setLightDirectionX(double ldx){if(ldx == 0.5) return; fprintf_s(mFile, "setAttr \".ldr.ldx\" %f;\n", ldx);}
	/*X value for light direction*/
	void setLightDirectionX(const DoubleID& ldx){fprintf_s(mFile,"connectAttr \"");ldx.write(mFile);fprintf_s(mFile,"\" \"%s.ldr.ldx\";\n",mName.c_str());}
	/*Y value for light direction*/
	void setLightDirectionY(double ldy){if(ldy == 0.5) return; fprintf_s(mFile, "setAttr \".ldr.ldy\" %f;\n", ldy);}
	/*Y value for light direction*/
	void setLightDirectionY(const DoubleID& ldy){fprintf_s(mFile,"connectAttr \"");ldy.write(mFile);fprintf_s(mFile,"\" \"%s.ldr.ldy\";\n",mName.c_str());}
	/*Z value for light direction*/
	void setLightDirectionZ(double ldz){if(ldz == -0.5) return; fprintf_s(mFile, "setAttr \".ldr.ldz\" %f;\n", ldz);}
	/*Z value for light direction*/
	void setLightDirectionZ(const DoubleID& ldz){fprintf_s(mFile,"connectAttr \"");ldz.write(mFile);fprintf_s(mFile,"\" \"%s.ldr.ldz\";\n",mName.c_str());}
	/*size of gaps relative to gapSpacing (1 = all hole)*/
	void setGapSize(double gsz){if(gsz == 0.0) return; fprintf_s(mFile, "setAttr \".gsz\" %f;\n", gsz);}
	/*size of gaps relative to gapSpacing (1 = all hole)*/
	void setGapSize(const DoubleID& gsz){fprintf_s(mFile,"connectAttr \"");gsz.write(mFile);fprintf_s(mFile,"\" \"%s.gsz\";\n",mName.c_str());}
	/*separation of gaps along stroke*/
	void setGapSpacing(double gsp){if(gsp == 1.0) return; fprintf_s(mFile, "setAttr \".gsp\" %f;\n", gsp);}
	/*separation of gaps along stroke*/
	void setGapSpacing(const DoubleID& gsp){fprintf_s(mFile,"connectAttr \"");gsp.write(mFile);fprintf_s(mFile,"\" \"%s.gsp\";\n",mName.c_str());}
	/*random offset along tubes for gaps*/
	void setGapRand(double grn){if(grn == 0.0) return; fprintf_s(mFile, "setAttr \".grn\" %f;\n", grn);}
	/*random offset along tubes for gaps*/
	void setGapRand(const DoubleID& grn){fprintf_s(mFile,"connectAttr \"");grn.write(mFile);fprintf_s(mFile,"\" \"%s.grn\";\n",mName.c_str());}
	/*speed of flow down brush path: affects gaps, twist and texture*/
	void setFlowSpeed(double fws){if(fws == 0.0) return; fprintf_s(mFile, "setAttr \".fws\" %f;\n", fws);}
	/*speed of flow down brush path: affects gaps, twist and texture*/
	void setFlowSpeed(const DoubleID& fws){fprintf_s(mFile,"connectAttr \"");fws.write(mFile);fprintf_s(mFile,"\" \"%s.fws\";\n",mName.c_str());}
	/*
	move texture with flow defined by flowspeed. In general this
	is best turned off for growth animations, but is useful when
	one want a texture, particularily a displacement, to flow down
	the tubes.
	*/
	void setTextureFlow(bool tfl){if(tfl == true) return; fprintf_s(mFile, "setAttr \".tfl\" %i;\n", tfl);}
	/*
	move texture with flow defined by flowspeed. In general this
	is best turned off for growth animations, but is useful when
	one want a texture, particularily a displacement, to flow down
	the tubes.
	*/
	void setTextureFlow(const BoolID& tfl){fprintf_s(mFile,"connectAttr \"");tfl.write(mFile);fprintf_s(mFile,"\" \"%s.tfl\";\n",mName.c_str());}
	/*bound tubes with a start and end time( tube treated as a flow )*/
	void setTimeClip(bool tcl){if(tcl == false) return; fprintf_s(mFile, "setAttr \".tcl\" %i;\n", tcl);}
	/*bound tubes with a start and end time( tube treated as a flow )*/
	void setTimeClip(const BoolID& tcl){fprintf_s(mFile,"connectAttr \"");tcl.write(mFile);fprintf_s(mFile,"\" \"%s.tcl\";\n",mName.c_str());}
	/*add in the path steps to time used for clipping.*/
	void setStrokeTime(bool srm){if(srm == false) return; fprintf_s(mFile, "setAttr \".srm\" %i;\n", srm);}
	/*add in the path steps to time used for clipping.*/
	void setStrokeTime(const BoolID& srm){fprintf_s(mFile,"connectAttr \"");srm.write(mFile);fprintf_s(mFile,"\" \"%s.srm\";\n",mName.c_str());}
	/*start time bound for tubes and path*/
	void setStartTime(double sti){if(sti == 0.0) return; fprintf_s(mFile, "setAttr \".sti\" %f;\n", sti);}
	/*start time bound for tubes and path*/
	void setStartTime(const DoubleID& sti){fprintf_s(mFile,"connectAttr \"");sti.write(mFile);fprintf_s(mFile,"\" \"%s.sti\";\n",mName.c_str());}
	/*end time bound for tubes and path*/
	void setEndTime(double eti){if(eti == 1000.0) return; fprintf_s(mFile, "setAttr \".eti\" %f;\n", eti);}
	/*end time bound for tubes and path*/
	void setEndTime(const DoubleID& eti){fprintf_s(mFile,"connectAttr \"");eti.write(mFile);fprintf_s(mFile,"\" \"%s.eti\";\n",mName.c_str());}
	/*generate dynamic tubes along path*/
	void setTubes(bool tub){if(tub == false) return; fprintf_s(mFile, "setAttr \".tub\" %i;\n", tub);}
	/*generate dynamic tubes along path*/
	void setTubes(const BoolID& tub){fprintf_s(mFile,"connectAttr \"");tub.write(mFile);fprintf_s(mFile,"\" \"%s.tub\";\n",mName.c_str());}
	/*the name of a mel script to use for tube generation*/
	void setCreationScript(const string& csc){if(csc == "NULL") return; fprintf_s(mFile, "setAttr \".csc\" -type \"string\" ");csc.write(mFile);fprintf_s(mFile,";\n");}
	/*the name of a mel script to use for tube generation*/
	void setCreationScript(const StringID& csc){fprintf_s(mFile,"connectAttr \"");csc.write(mFile);fprintf_s(mFile,"\" \"%s.csc\";\n",mName.c_str());}
	/*
	the name of a mel script called at each step in the
	simulation to shape the flow and behavior of tubes
	*/
	void setRuntimeScript(const string& rsc){if(rsc == "NULL") return; fprintf_s(mFile, "setAttr \".rsc\" -type \"string\" ");rsc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	the name of a mel script called at each step in the
	simulation to shape the flow and behavior of tubes
	*/
	void setRuntimeScript(const StringID& rsc){fprintf_s(mFile,"connectAttr \"");rsc.write(mFile);fprintf_s(mFile,"\" \"%s.rsc\";\n",mName.c_str());}
	/*run dynamic simulation until all tubes are at their final length*/
	void setTubeCompletion(bool tcm){if(tcm == true) return; fprintf_s(mFile, "setAttr \".tcm\" %i;\n", tcm);}
	/*run dynamic simulation until all tubes are at their final length*/
	void setTubeCompletion(const BoolID& tcm){fprintf_s(mFile,"connectAttr \"");tcm.write(mFile);fprintf_s(mFile,"\" \"%s.tcm\";\n",mName.c_str());}
	/*number of tubes generated for every new point along path*/
	void setTubesPerStep(double tps){if(tps == 0.5) return; fprintf_s(mFile, "setAttr \".tps\" %f;\n", tps);}
	/*number of tubes generated for every new point along path*/
	void setTubesPerStep(const DoubleID& tps){fprintf_s(mFile,"connectAttr \"");tps.write(mFile);fprintf_s(mFile,"\" \"%s.tps\";\n",mName.c_str());}
	/*randomization of tube generation*/
	void setTubeRand(double trd){if(trd == 1.0) return; fprintf_s(mFile, "setAttr \".trd\" %f;\n", trd);}
	/*randomization of tube generation*/
	void setTubeRand(const DoubleID& trd){fprintf_s(mFile,"connectAttr \"");trd.write(mFile);fprintf_s(mFile,"\" \"%s.trd\";\n",mName.c_str());}
	/*number of tubes created at beginning of path*/
	void setStartTubes(int stb){if(stb == 0) return; fprintf_s(mFile, "setAttr \".stb\" %i;\n", stb);}
	/*number of tubes created at beginning of path*/
	void setStartTubes(const IntID& stb){fprintf_s(mFile,"connectAttr \"");stb.write(mFile);fprintf_s(mFile,"\" \"%s.stb\";\n",mName.c_str());}
	/*max tube length*/
	void setLengthMax(double lnx){if(lnx == 1.0) return; fprintf_s(mFile, "setAttr \".lnx\" %f;\n", lnx);}
	/*max tube length*/
	void setLengthMax(const DoubleID& lnx){fprintf_s(mFile,"connectAttr \"");lnx.write(mFile);fprintf_s(mFile,"\" \"%s.lnx\";\n",mName.c_str());}
	/*min tube length*/
	void setLengthMin(double lnn){if(lnn == 0.0) return; fprintf_s(mFile, "setAttr \".lnn\" %f;\n", lnn);}
	/*min tube length*/
	void setLengthMin(const DoubleID& lnn){fprintf_s(mFile,"connectAttr \"");lnn.write(mFile);fprintf_s(mFile,"\" \"%s.lnn\";\n",mName.c_str());}
	/*number of segments in full length tubes*/
	void setSegments(int sgm){if(sgm == 10) return; fprintf_s(mFile, "setAttr \".sgm\" %i;\n", sgm);}
	/*number of segments in full length tubes*/
	void setSegments(const IntID& sgm){fprintf_s(mFile,"connectAttr \"");sgm.write(mFile);fprintf_s(mFile,"\" \"%s.sgm\";\n",mName.c_str());}
	/*worldspace start width of tubes*/
	void setTubeWidth1(double tw1){if(tw1 == 0.01) return; fprintf_s(mFile, "setAttr \".tw1\" %f;\n", tw1);}
	/*worldspace start width of tubes*/
	void setTubeWidth1(const DoubleID& tw1){fprintf_s(mFile,"connectAttr \"");tw1.write(mFile);fprintf_s(mFile,"\" \"%s.tw1\";\n",mName.c_str());}
	/*worldspace end width of tubes*/
	void setTubeWidth2(double tw2){if(tw2 == 0.01) return; fprintf_s(mFile, "setAttr \".tw2\" %f;\n", tw2);}
	/*worldspace end width of tubes*/
	void setTubeWidth2(const DoubleID& tw2){fprintf_s(mFile,"connectAttr \"");tw2.write(mFile);fprintf_s(mFile,"\" \"%s.tw2\";\n",mName.c_str());}
	/*Randomization of tube start widths*/
	void setWidthRand(double wdr){if(wdr == 0.0) return; fprintf_s(mFile, "setAttr \".wdr\" %f;\n", wdr);}
	/*Randomization of tube start widths*/
	void setWidthRand(const DoubleID& wdr){fprintf_s(mFile,"connectAttr \"");wdr.write(mFile);fprintf_s(mFile,"\" \"%s.wdr\";\n",mName.c_str());}
	/*the proportion of large to small tubes*/
	void setWidthBias(double wdb){if(wdb == 0.0) return; fprintf_s(mFile, "setAttr \".wdb\" %f;\n", wdb);}
	/*the proportion of large to small tubes*/
	void setWidthBias(const DoubleID& wdb){fprintf_s(mFile,"connectAttr \"");wdb.write(mFile);fprintf_s(mFile,"\" \"%s.wdb\";\n",mName.c_str());}
	/*the degree to which forces can stretch the tubes*/
	void setLengthFlex(double lfx){if(lfx == 0.0) return; fprintf_s(mFile, "setAttr \".lfx\" %f;\n", lfx);}
	/*the degree to which forces can stretch the tubes*/
	void setLengthFlex(const DoubleID& lfx){fprintf_s(mFile,"connectAttr \"");lfx.write(mFile);fprintf_s(mFile,"\" \"%s.lfx\";\n",mName.c_str());}
	/*the amount that segment lengths are smaller towards root or tip of tube*/
	void setSegmentLengthBias(double sgb){if(sgb == 0.0) return; fprintf_s(mFile, "setAttr \".sgb\" %f;\n", sgb);}
	/*the amount that segment lengths are smaller towards root or tip of tube*/
	void setSegmentLengthBias(const DoubleID& sgb){fprintf_s(mFile,"connectAttr \"");sgb.write(mFile);fprintf_s(mFile,"\" \"%s.sgb\";\n",mName.c_str());}
	/*the amount that segment lengths are proportional to the tube width*/
	void setSegmentWidthBias(double swb){if(swb == 0.0) return; fprintf_s(mFile, "setAttr \".swb\" %f;\n", swb);}
	/*the amount that segment lengths are proportional to the tube width*/
	void setSegmentWidthBias(const DoubleID& swb){fprintf_s(mFile,"connectAttr \"");swb.write(mFile);fprintf_s(mFile,"\" \"%s.swb\";\n",mName.c_str());}
	/*
	primary axis for generation of tubes ( direction if elevation = 0.0)
	0 - along surface or defined normal
	1 - along path of stroke
	*/
	void setTubeDirection(unsigned int tdr){if(tdr == 0) return; fprintf_s(mFile, "setAttr \".tdr\" %i;\n", tdr);}
	/*
	primary axis for generation of tubes ( direction if elevation = 0.0)
	0 - along surface or defined normal
	1 - along path of stroke
	*/
	void setTubeDirection(const UnsignedintID& tdr){fprintf_s(mFile,"connectAttr \"");tdr.write(mFile);fprintf_s(mFile,"\" \"%s.tdr\";\n",mName.c_str());}
	/*min elevation of tubes above stroke*/
	void setElevationMin(double elm){if(elm == 0.2) return; fprintf_s(mFile, "setAttr \".elm\" %f;\n", elm);}
	/*min elevation of tubes above stroke*/
	void setElevationMin(const DoubleID& elm){fprintf_s(mFile,"connectAttr \"");elm.write(mFile);fprintf_s(mFile,"\" \"%s.elm\";\n",mName.c_str());}
	/*max elevation of tubes above stroke*/
	void setElevationMax(double elx){if(elx == 0.5) return; fprintf_s(mFile, "setAttr \".elx\" %f;\n", elx);}
	/*max elevation of tubes above stroke*/
	void setElevationMax(const DoubleID& elx){fprintf_s(mFile,"connectAttr \"");elx.write(mFile);fprintf_s(mFile,"\" \"%s.elx\";\n",mName.c_str());}
	/*min angle of tubes with stroke direction*/
	void setAzimuthMin(double azn){if(azn == -0.1) return; fprintf_s(mFile, "setAttr \".azn\" %f;\n", azn);}
	/*min angle of tubes with stroke direction*/
	void setAzimuthMin(const DoubleID& azn){fprintf_s(mFile,"connectAttr \"");azn.write(mFile);fprintf_s(mFile,"\" \"%s.azn\";\n",mName.c_str());}
	/*max angle of tubes with stroke direction*/
	void setAzimuthMax(double azx){if(azx == 0.1) return; fprintf_s(mFile, "setAttr \".azx\" %f;\n", azx);}
	/*max angle of tubes with stroke direction*/
	void setAzimuthMax(const DoubleID& azx){fprintf_s(mFile,"connectAttr \"");azx.write(mFile);fprintf_s(mFile,"\" \"%s.azx\";\n",mName.c_str());}
	/*flatness of tube at base*/
	void setFlatness1(double fl1){if(fl1 == 0.0) return; fprintf_s(mFile, "setAttr \".fl1\" %f;\n", fl1);}
	/*flatness of tube at base*/
	void setFlatness1(const DoubleID& fl1){fprintf_s(mFile,"connectAttr \"");fl1.write(mFile);fprintf_s(mFile,"\" \"%s.fl1\";\n",mName.c_str());}
	/*flatness of tube at tip*/
	void setFlatness2(double fl2){if(fl2 == 0.0) return; fprintf_s(mFile, "setAttr \".fl2\" %f;\n", fl2);}
	/*flatness of tube at tip*/
	void setFlatness2(const DoubleID& fl2){fprintf_s(mFile,"connectAttr \"");fl2.write(mFile);fprintf_s(mFile,"\" \"%s.fl2\";\n",mName.c_str());}
	/*start twist of tube*/
	void setTwist(double twi){if(twi == 0.0) return; fprintf_s(mFile, "setAttr \".twi\" %f;\n", twi);}
	/*start twist of tube*/
	void setTwist(const DoubleID& twi){fprintf_s(mFile,"connectAttr \"");twi.write(mFile);fprintf_s(mFile,"\" \"%s.twi\";\n",mName.c_str());}
	/*how much flat tubes twist along length like a streamer*/
	void setTwistRate(double twr){if(twr == 0.0) return; fprintf_s(mFile, "setAttr \".twr\" %f;\n", twr);}
	/*how much flat tubes twist along length like a streamer*/
	void setTwistRate(const DoubleID& twr){fprintf_s(mFile,"connectAttr \"");twr.write(mFile);fprintf_s(mFile,"\" \"%s.twr\";\n",mName.c_str());}
	/*randomization of twist when splitting*/
	void setTwistRand(double twd){if(twd == 1.0) return; fprintf_s(mFile, "setAttr \".twd\" %f;\n", twd);}
	/*randomization of twist when splitting*/
	void setTwistRand(const DoubleID& twd){fprintf_s(mFile,"connectAttr \"");twd.write(mFile);fprintf_s(mFile,"\" \"%s.twd\";\n",mName.c_str());}
	/*min amount of spiral about surface normal*/
	void setSpiralMin(double spm){if(spm == 0.0) return; fprintf_s(mFile, "setAttr \".spm\" %f;\n", spm);}
	/*min amount of spiral about surface normal*/
	void setSpiralMin(const DoubleID& spm){fprintf_s(mFile,"connectAttr \"");spm.write(mFile);fprintf_s(mFile,"\" \"%s.spm\";\n",mName.c_str());}
	/*max amount of spiral about surface normal*/
	void setSpiralMax(double spx){if(spx == 0.0) return; fprintf_s(mFile, "setAttr \".spx\" %f;\n", spx);}
	/*max amount of spiral about surface normal*/
	void setSpiralMax(const DoubleID& spx){fprintf_s(mFile,"connectAttr \"");spx.write(mFile);fprintf_s(mFile,"\" \"%s.spx\";\n",mName.c_str());}
	/*rate of change in spiral*/
	void setSpiralDecay(double spd){if(spd == 0.0) return; fprintf_s(mFile, "setAttr \".spd\" %f;\n", spd);}
	/*rate of change in spiral*/
	void setSpiralDecay(const DoubleID& spd){fprintf_s(mFile,"connectAttr \"");spd.write(mFile);fprintf_s(mFile,"\" \"%s.spd\";\n",mName.c_str());}
	/*
	amount of bend about the axis defined by the
	current twist.
	*/
	void setBend(double ben){if(ben == 0.0) return; fprintf_s(mFile, "setAttr \".ben\" %f;\n", ben);}
	/*
	amount of bend about the axis defined by the
	current twist.
	*/
	void setBend(const DoubleID& ben){fprintf_s(mFile,"connectAttr \"");ben.write(mFile);fprintf_s(mFile,"\" \"%s.ben\";\n",mName.c_str());}
	/*
	the relative strength of the bend from root to tip.
	High values cause a faster bending near the tip.
	*/
	void setBendBias(double bnb){if(bnb == 0.0) return; fprintf_s(mFile, "setAttr \".bnb\" %f;\n", bnb);}
	/*
	the relative strength of the bend from root to tip.
	High values cause a faster bending near the tip.
	*/
	void setBendBias(const DoubleID& bnb){fprintf_s(mFile,"connectAttr \"");bnb.write(mFile);fprintf_s(mFile,"\" \"%s.bnb\";\n",mName.c_str());}
	/*initial ramp up of displacement relative to max tube length*/
	void setDisplacementDelay(double ddl){if(ddl == 0.2) return; fprintf_s(mFile, "setAttr \".ddl\" %f;\n", ddl);}
	/*initial ramp up of displacement relative to max tube length*/
	void setDisplacementDelay(const DoubleID& ddl){fprintf_s(mFile,"connectAttr \"");ddl.write(mFile);fprintf_s(mFile,"\" \"%s.ddl\";\n",mName.c_str());}
	/*amount of wiggle tangent to stroke surface*/
	void setWiggle(double wgl){if(wgl == 0.0) return; fprintf_s(mFile, "setAttr \".wgl\" %f;\n", wgl);}
	/*amount of wiggle tangent to stroke surface*/
	void setWiggle(const DoubleID& wgl){fprintf_s(mFile,"connectAttr \"");wgl.write(mFile);fprintf_s(mFile,"\" \"%s.wgl\";\n",mName.c_str());}
	/*wavelength for wiggle effect*/
	void setWiggleFrequency(double wgf){if(wgf == 3) return; fprintf_s(mFile, "setAttr \".wgf\" %f;\n", wgf);}
	/*wavelength for wiggle effect*/
	void setWiggleFrequency(const DoubleID& wgf){fprintf_s(mFile,"connectAttr \"");wgf.write(mFile);fprintf_s(mFile,"\" \"%s.wgf\";\n",mName.c_str());}
	/*translation of wiggle down tube path*/
	void setWiggleOffset(double wgo){if(wgo == 0.0) return; fprintf_s(mFile, "setAttr \".wgo\" %f;\n", wgo);}
	/*translation of wiggle down tube path*/
	void setWiggleOffset(const DoubleID& wgo){fprintf_s(mFile,"connectAttr \"");wgo.write(mFile);fprintf_s(mFile,"\" \"%s.wgo\";\n",mName.c_str());}
	/*amount of curl about tube direction*/
	void setCurl(double crl){if(crl == 0.0) return; fprintf_s(mFile, "setAttr \".crl\" %f;\n", crl);}
	/*amount of curl about tube direction*/
	void setCurl(const DoubleID& crl){fprintf_s(mFile,"connectAttr \"");crl.write(mFile);fprintf_s(mFile,"\" \"%s.crl\";\n",mName.c_str());}
	/*rate of curl*/
	void setCurlFrequency(double crf){if(crf == 1) return; fprintf_s(mFile, "setAttr \".crf\" %f;\n", crf);}
	/*rate of curl*/
	void setCurlFrequency(const DoubleID& crf){fprintf_s(mFile,"connectAttr \"");crf.write(mFile);fprintf_s(mFile,"\" \"%s.crf\";\n",mName.c_str());}
	/*translation of curl down tube*/
	void setCurlOffset(double cro){if(cro == 0.0) return; fprintf_s(mFile, "setAttr \".cro\" %f;\n", cro);}
	/*translation of curl down tube*/
	void setCurlOffset(const DoubleID& cro){fprintf_s(mFile,"connectAttr \"");cro.write(mFile);fprintf_s(mFile,"\" \"%s.cro\";\n",mName.c_str());}
	/*amount of perlin noise offset in space*/
	void setNoise(double noi){if(noi == 0.0) return; fprintf_s(mFile, "setAttr \".noi\" %f;\n", noi);}
	/*amount of perlin noise offset in space*/
	void setNoise(const DoubleID& noi){fprintf_s(mFile,"connectAttr \"");noi.write(mFile);fprintf_s(mFile,"\" \"%s.noi\";\n",mName.c_str());}
	/*scale of the noise offset along tube*/
	void setNoiseFrequency(double nof){if(nof == 0.2) return; fprintf_s(mFile, "setAttr \".nof\" %f;\n", nof);}
	/*scale of the noise offset along tube*/
	void setNoiseFrequency(const DoubleID& nof){fprintf_s(mFile,"connectAttr \"");nof.write(mFile);fprintf_s(mFile,"\" \"%s.nof\";\n",mName.c_str());}
	/*translation of noise  down tube*/
	void setNoiseOffset(double noo){if(noo == 0.0) return; fprintf_s(mFile, "setAttr \".noo\" %f;\n", noo);}
	/*translation of noise  down tube*/
	void setNoiseOffset(const DoubleID& noo){fprintf_s(mFile,"connectAttr \"");noo.write(mFile);fprintf_s(mFile,"\" \"%s.noo\";\n",mName.c_str());}
	/*the number of splits along a given tube*/
	void setSplitMaxDepth(double smd){if(smd == 2.0) return; fprintf_s(mFile, "setAttr \".smd\" %f;\n", smd);}
	/*the number of splits along a given tube*/
	void setSplitMaxDepth(const DoubleID& smd){fprintf_s(mFile,"connectAttr \"");smd.write(mFile);fprintf_s(mFile,"\" \"%s.smd\";\n",mName.c_str());}
	/*the randomness of the offset of split events along the tube*/
	void setSplitRand(double srd){if(srd == 0.0) return; fprintf_s(mFile, "setAttr \".srd\" %f;\n", srd);}
	/*the randomness of the offset of split events along the tube*/
	void setSplitRand(const DoubleID& srd){fprintf_s(mFile,"connectAttr \"");srd.write(mFile);fprintf_s(mFile,"\" \"%s.srd\";\n",mName.c_str());}
	/*the angle with the new branches with respect to the base tube*/
	void setSplitAngle(double spa){if(spa == 30.0) return; fprintf_s(mFile, "setAttr \".spa\" %f;\n", spa);}
	/*the angle with the new branches with respect to the base tube*/
	void setSplitAngle(const DoubleID& spa){fprintf_s(mFile,"connectAttr \"");spa.write(mFile);fprintf_s(mFile,"\" \"%s.spa\";\n",mName.c_str());}
	/*tubes are scaled by this factor at each split*/
	void setSplitSizeDecay(double ssd){if(ssd == 0.7) return; fprintf_s(mFile, "setAttr \".ssd\" %f;\n", ssd);}
	/*tubes are scaled by this factor at each split*/
	void setSplitSizeDecay(const DoubleID& ssd){fprintf_s(mFile,"connectAttr \"");ssd.write(mFile);fprintf_s(mFile,"\" \"%s.ssd\";\n",mName.c_str());}
	/*the degree to which splits happen nearer the tube base or tip*/
	void setSplitBias(double slb){if(slb == 0.0) return; fprintf_s(mFile, "setAttr \".slb\" %f;\n", slb);}
	/*the degree to which splits happen nearer the tube base or tip*/
	void setSplitBias(const DoubleID& slb){fprintf_s(mFile,"connectAttr \"");slb.write(mFile);fprintf_s(mFile,"\" \"%s.slb\";\n",mName.c_str());}
	/*the amount of twist every branch event*/
	void setSplitTwist(double slt){if(slt == 0.5) return; fprintf_s(mFile, "setAttr \".slt\" %f;\n", slt);}
	/*the amount of twist every branch event*/
	void setSplitTwist(const DoubleID& slt){fprintf_s(mFile,"connectAttr \"");slt.write(mFile);fprintf_s(mFile,"\" \"%s.slt\";\n",mName.c_str());}
	/*the initial number of child branches at tube origin*/
	void setStartBranches(double sbr){if(sbr == 0) return; fprintf_s(mFile, "setAttr \".sbr\" %f;\n", sbr);}
	/*the initial number of child branches at tube origin*/
	void setStartBranches(const DoubleID& sbr){fprintf_s(mFile,"connectAttr \"");sbr.write(mFile);fprintf_s(mFile,"\" \"%s.sbr\";\n",mName.c_str());}
	/*the number of child branches per split*/
	void setNumBranches(int nbr){if(nbr == 2) return; fprintf_s(mFile, "setAttr \".nbr\" %i;\n", nbr);}
	/*the number of child branches per split*/
	void setNumBranches(const IntID& nbr){fprintf_s(mFile,"connectAttr \"");nbr.write(mFile);fprintf_s(mFile,"\" \"%s.nbr\";\n",mName.c_str());}
	/*the proportion of branches that are pruned*/
	void setBranchDropout(double bdr){if(bdr == 0.0) return; fprintf_s(mFile, "setAttr \".bdr\" %f;\n", bdr);}
	/*the proportion of branches that are pruned*/
	void setBranchDropout(const DoubleID& bdr){fprintf_s(mFile,"connectAttr \"");bdr.write(mFile);fprintf_s(mFile,"\" \"%s.bdr\";\n",mName.c_str());}
	/*whether or not to keep the main trunk at split points*/
	void setMiddleBranch(bool mbr){if(mbr == false) return; fprintf_s(mFile, "setAttr \".mbr\" %i;\n", mbr);}
	/*whether or not to keep the main trunk at split points*/
	void setMiddleBranch(const BoolID& mbr){fprintf_s(mFile,"connectAttr \"");mbr.write(mFile);fprintf_s(mFile,"\" \"%s.mbr\";\n",mName.c_str());}
	/*cutoff size when tube size is diminishing*/
	void setMinSize(double mms){if(mms == 0.0001) return; fprintf_s(mFile, "setAttr \".mms\" %f;\n", mms);}
	/*cutoff size when tube size is diminishing*/
	void setMinSize(const DoubleID& mms){fprintf_s(mFile,"connectAttr \"");mms.write(mFile);fprintf_s(mFile,"\" \"%s.mms\";\n",mName.c_str());}
	/*the amount tubes shapes match the shape of the path*/
	void setPathFollow(double pfl){if(pfl == 0.0) return; fprintf_s(mFile, "setAttr \".pfl\" %f;\n", pfl);}
	/*the amount tubes shapes match the shape of the path*/
	void setPathFollow(const DoubleID& pfl){fprintf_s(mFile,"connectAttr \"");pfl.write(mFile);fprintf_s(mFile,"\" \"%s.pfl\";\n",mName.c_str());}
	/*the path acts as a force*/
	void setPathAttract(double pat){if(pat == 0.0) return; fprintf_s(mFile, "setAttr \".pat\" %f;\n", pat);}
	/*the path acts as a force*/
	void setPathAttract(const DoubleID& pat){fprintf_s(mFile,"connectAttr \"");pat.write(mFile);fprintf_s(mFile,"\" \"%s.pat\";\n",mName.c_str());}
	/*degree to which stroke shape matches input curve*/
	void setCurveFollow(double cfw){if(cfw == 0.0) return; fprintf_s(mFile, "setAttr \".cfw\" %f;\n", cfw);}
	/*degree to which stroke shape matches input curve*/
	void setCurveFollow(const DoubleID& cfw){fprintf_s(mFile,"connectAttr \"");cfw.write(mFile);fprintf_s(mFile,"\" \"%s.cfw\";\n",mName.c_str());}
	/*input curve acts as a force*/
	void setCurveAttract(double cva){if(cva == 0.0) return; fprintf_s(mFile, "setAttr \".cva\" %f;\n", cva);}
	/*input curve acts as a force*/
	void setCurveAttract(const DoubleID& cva){fprintf_s(mFile,"connectAttr \"");cva.write(mFile);fprintf_s(mFile,"\" \"%s.cva\";\n",mName.c_str());}
	/*max distance for influence of curves (0.0 = infinite)*/
	void setCurveMaxDist(double cmd){if(cmd == 0.0) return; fprintf_s(mFile, "setAttr \".cmd\" %f;\n", cmd);}
	/*max distance for influence of curves (0.0 = infinite)*/
	void setCurveMaxDist(const DoubleID& cmd){fprintf_s(mFile,"connectAttr \"");cmd.write(mFile);fprintf_s(mFile,"\" \"%s.cmd\";\n",mName.c_str());}
	/*worldspace directional force*/
	void setUniformForce(const double3& ufr){fprintf_s(mFile, "setAttr \".ufr\" -type \"double3\" ");ufr.write(mFile);fprintf_s(mFile,";\n");}
	/*worldspace directional force*/
	void setUniformForce(const Double3ID& ufr){fprintf_s(mFile,"connectAttr \"");ufr.write(mFile);fprintf_s(mFile,"\" \"%s.ufr\";\n",mName.c_str());}
	/*worldspace directional force X value*/
	void setUniformForceX(double ufx){if(ufx == 0.0) return; fprintf_s(mFile, "setAttr \".ufr.ufx\" %f;\n", ufx);}
	/*worldspace directional force X value*/
	void setUniformForceX(const DoubleID& ufx){fprintf_s(mFile,"connectAttr \"");ufx.write(mFile);fprintf_s(mFile,"\" \"%s.ufr.ufx\";\n",mName.c_str());}
	/*worldspace directional force Y value*/
	void setUniformForceY(double ufy){if(ufy == 0.0) return; fprintf_s(mFile, "setAttr \".ufr.ufy\" %f;\n", ufy);}
	/*worldspace directional force Y value*/
	void setUniformForceY(const DoubleID& ufy){fprintf_s(mFile,"connectAttr \"");ufy.write(mFile);fprintf_s(mFile,"\" \"%s.ufr.ufy\";\n",mName.c_str());}
	/*worldspace directional force Z value*/
	void setUniformForceZ(double ufz){if(ufz == 0.0) return; fprintf_s(mFile, "setAttr \".ufr.ufz\" %f;\n", ufz);}
	/*worldspace directional force Z value*/
	void setUniformForceZ(const DoubleID& ufz){fprintf_s(mFile,"connectAttr \"");ufz.write(mFile);fprintf_s(mFile,"\" \"%s.ufr.ufz\";\n",mName.c_str());}
	/*
	use no turbulence, path relative, or worldspace turbulence
	0 - Off
	1 - Turbulence is a force in path space
	2 - Turbulence is a force in worldspace
	3 - Turbulence applied as localspace offset to tube
	4 - Turbulence applied as worldspace offset to tube
	*/
	void setTurbulenceType(unsigned int trt){if(trt == 0) return; fprintf_s(mFile, "setAttr \".trt\" %i;\n", trt);}
	/*
	use no turbulence, path relative, or worldspace turbulence
	0 - Off
	1 - Turbulence is a force in path space
	2 - Turbulence is a force in worldspace
	3 - Turbulence applied as localspace offset to tube
	4 - Turbulence applied as worldspace offset to tube
	*/
	void setTurbulenceType(const UnsignedintID& trt){fprintf_s(mFile,"connectAttr \"");trt.write(mFile);fprintf_s(mFile,"\" \"%s.trt\";\n",mName.c_str());}
	/*
	Interpolation method for values on the turbulence grid
	0 - Linear interpolation
	1 - Smooth interpolation(quadratic) over time only
	2 - Smooth interpolation(quadratic) over both time and space
	*/
	void setTurbulenceInterpolation(unsigned int tin){if(tin == 0) return; fprintf_s(mFile, "setAttr \".tin\" %i;\n", tin);}
	/*
	Interpolation method for values on the turbulence grid
	0 - Linear interpolation
	1 - Smooth interpolation(quadratic) over time only
	2 - Smooth interpolation(quadratic) over both time and space
	*/
	void setTurbulenceInterpolation(const UnsignedintID& tin){fprintf_s(mFile,"connectAttr \"");tin.write(mFile);fprintf_s(mFile,"\" \"%s.tin\";\n",mName.c_str());}
	/*level of animated wind turbulence that seamlessly loops in both space and time*/
	void setTurbulence(double tur){if(tur == 0.2) return; fprintf_s(mFile, "setAttr \".tur\" %f;\n", tur);}
	/*level of animated wind turbulence that seamlessly loops in both space and time*/
	void setTurbulence(const DoubleID& tur){fprintf_s(mFile,"connectAttr \"");tur.write(mFile);fprintf_s(mFile,"\" \"%s.tur\";\n",mName.c_str());}
	/*this scales the turbulence spacially*/
	void setTurbulenceFrequency(double trf){if(trf == 0.2) return; fprintf_s(mFile, "setAttr \".trf\" %f;\n", trf);}
	/*this scales the turbulence spacially*/
	void setTurbulenceFrequency(const DoubleID& trf){fprintf_s(mFile,"connectAttr \"");trf.write(mFile);fprintf_s(mFile,"\" \"%s.trf\";\n",mName.c_str());}
	/*this scales the time value used for the turbulence function*/
	void setTurbulenceSpeed(double trs){if(trs == 0.5) return; fprintf_s(mFile, "setAttr \".trs\" %f;\n", trs);}
	/*this scales the time value used for the turbulence function*/
	void setTurbulenceSpeed(const DoubleID& trs){fprintf_s(mFile,"connectAttr \"");trs.write(mFile);fprintf_s(mFile,"\" \"%s.trs\";\n",mName.c_str());}
	/*xyz translation of turbulence*/
	void setTurbulenceOffset(const double3& tro){fprintf_s(mFile, "setAttr \".tro\" -type \"double3\" ");tro.write(mFile);fprintf_s(mFile,";\n");}
	/*xyz translation of turbulence*/
	void setTurbulenceOffset(const Double3ID& tro){fprintf_s(mFile,"connectAttr \"");tro.write(mFile);fprintf_s(mFile,"\" \"%s.tro\";\n",mName.c_str());}
	/*turbulence translation in X*/
	void setTurbulenceOffsetX(double trx){if(trx == 0.0) return; fprintf_s(mFile, "setAttr \".tro.trx\" %f;\n", trx);}
	/*turbulence translation in X*/
	void setTurbulenceOffsetX(const DoubleID& trx){fprintf_s(mFile,"connectAttr \"");trx.write(mFile);fprintf_s(mFile,"\" \"%s.tro.trx\";\n",mName.c_str());}
	/*turbulence translation in Y*/
	void setTurbulenceOffsetY(double try_){if(try_ == 0.0) return; fprintf_s(mFile, "setAttr \".tro.try\" %f;\n", try_);}
	/*turbulence translation in Y*/
	void setTurbulenceOffsetY(const DoubleID& try_){fprintf_s(mFile,"connectAttr \"");try_.write(mFile);fprintf_s(mFile,"\" \"%s.tro.try\";\n",mName.c_str());}
	/*turbulence translation in Z*/
	void setTurbulenceOffsetZ(double trz){if(trz == 0.0) return; fprintf_s(mFile, "setAttr \".tro.trz\" %f;\n", trz);}
	/*turbulence translation in Z*/
	void setTurbulenceOffsetZ(const DoubleID& trz){fprintf_s(mFile,"connectAttr \"");trz.write(mFile);fprintf_s(mFile,"\" \"%s.tro.trz\";\n",mName.c_str());}
	/*local force with random direction and intensity*/
	void setRandom(double ran){if(ran == 0.0) return; fprintf_s(mFile, "setAttr \".ran\" %f;\n", ran);}
	/*local force with random direction and intensity*/
	void setRandom(const DoubleID& ran){fprintf_s(mFile,"connectAttr \"");ran.write(mFile);fprintf_s(mFile,"\" \"%s.ran\";\n",mName.c_str());}
	/*vertical worldspace force*/
	void setGravity(double grv){if(grv == 0.0) return; fprintf_s(mFile, "setAttr \".grv\" %f;\n", grv);}
	/*vertical worldspace force*/
	void setGravity(const DoubleID& grv){fprintf_s(mFile,"connectAttr \"");grv.write(mFile);fprintf_s(mFile,"\" \"%s.grv\";\n",mName.c_str());}
	/*The particle velocity is scaled by this factor at each simulation step.*/
	void setMomentum(double mmt){if(mmt == 1.0) return; fprintf_s(mFile, "setAttr \".mmt\" %f;\n", mmt);}
	/*The particle velocity is scaled by this factor at each simulation step.*/
	void setMomentum(const DoubleID& mmt){fprintf_s(mFile,"connectAttr \"");mmt.write(mFile);fprintf_s(mFile,"\" \"%s.mmt\";\n",mName.c_str());}
	/*Fake surface collision using repulsive force*/
	void setDeflection(bool def){if(def == false) return; fprintf_s(mFile, "setAttr \".def\" %i;\n", def);}
	/*Fake surface collision using repulsive force*/
	void setDeflection(const BoolID& def){fprintf_s(mFile,"connectAttr \"");def.write(mFile);fprintf_s(mFile,"\" \"%s.def\";\n",mName.c_str());}
	/*offset for where the surface is presumed to be*/
	void setDeflectionMin(double dfm){if(dfm == 0.0) return; fprintf_s(mFile, "setAttr \".dfm\" %f;\n", dfm);}
	/*offset for where the surface is presumed to be*/
	void setDeflectionMin(const DoubleID& dfm){fprintf_s(mFile,"connectAttr \"");dfm.write(mFile);fprintf_s(mFile,"\" \"%s.dfm\";\n",mName.c_str());}
	/*distance from surface at which deflection field fades to zero*/
	void setDeflectionMax(double dfx){if(dfx == 0.3) return; fprintf_s(mFile, "setAttr \".dfx\" %f;\n", dfx);}
	/*distance from surface at which deflection field fades to zero*/
	void setDeflectionMax(const DoubleID& dfx){fprintf_s(mFile,"connectAttr \"");dfx.write(mFile);fprintf_s(mFile,"\" \"%s.dfx\";\n",mName.c_str());}
	/*number of twigs created at life end*/
	void setTwigsInCluster(int tic){if(tic == 1) return; fprintf_s(mFile, "setAttr \".tic\" %i;\n", tic);}
	/*number of twigs created at life end*/
	void setTwigsInCluster(const IntID& tic){fprintf_s(mFile,"connectAttr \"");tic.write(mFile);fprintf_s(mFile,"\" \"%s.tic\";\n",mName.c_str());}
	/*rate of omitted twigs*/
	void setTwigDropout(double tdp){if(tdp == 0.0) return; fprintf_s(mFile, "setAttr \".tdp\" %f;\n", tdp);}
	/*rate of omitted twigs*/
	void setTwigDropout(const DoubleID& tdp){fprintf_s(mFile,"connectAttr \"");tdp.write(mFile);fprintf_s(mFile,"\" \"%s.tdp\";\n",mName.c_str());}
	/*start angle of twig with branch*/
	void setTwigAngle1(double ta1){if(ta1 == 90.0) return; fprintf_s(mFile, "setAttr \".ta1\" %f;\n", ta1);}
	/*start angle of twig with branch*/
	void setTwigAngle1(const DoubleID& ta1){fprintf_s(mFile,"connectAttr \"");ta1.write(mFile);fprintf_s(mFile,"\" \"%s.ta1\";\n",mName.c_str());}
	/*end angle of twig with branch*/
	void setTwigAngle2(double ta2){if(ta2 == 80.0) return; fprintf_s(mFile, "setAttr \".ta2\" %f;\n", ta2);}
	/*end angle of twig with branch*/
	void setTwigAngle2(const DoubleID& ta2){fprintf_s(mFile,"connectAttr \"");ta2.write(mFile);fprintf_s(mFile,"\" \"%s.ta2\";\n",mName.c_str());}
	/*rate of twist about branch per twig*/
	void setTwigTwist(double ttw){if(ttw == 0.0) return; fprintf_s(mFile, "setAttr \".ttw\" %f;\n", ttw);}
	/*rate of twist about branch per twig*/
	void setTwigTwist(const DoubleID& ttw){fprintf_s(mFile,"connectAttr \"");ttw.write(mFile);fprintf_s(mFile,"\" \"%s.ttw\";\n",mName.c_str());}
	/*length of twig stroke*/
	void setTwigLength(double twl){if(twl == 0.5) return; fprintf_s(mFile, "setAttr \".twl\" %f;\n", twl);}
	/*length of twig stroke*/
	void setTwigLength(const DoubleID& twl){fprintf_s(mFile,"connectAttr \"");twl.write(mFile);fprintf_s(mFile,"\" \"%s.twl\";\n",mName.c_str());}
	/*point along branch where twigs start*/
	void setTwigStart(double tst){if(tst == 0.5) return; fprintf_s(mFile, "setAttr \".tst\" %f;\n", tst);}
	/*point along branch where twigs start*/
	void setTwigStart(const DoubleID& tst){fprintf_s(mFile,"connectAttr \"");tst.write(mFile);fprintf_s(mFile,"\" \"%s.tst\";\n",mName.c_str());}
	/*total number of twig sprouts created between twig Start and branch tip*/
	void setNumTwigClusters(double ntc){if(ntc == 4) return; fprintf_s(mFile, "setAttr \".ntc\" %f;\n", ntc);}
	/*total number of twig sprouts created between twig Start and branch tip*/
	void setNumTwigClusters(const DoubleID& ntc){fprintf_s(mFile,"connectAttr \"");ntc.write(mFile);fprintf_s(mFile,"\" \"%s.ntc\";\n",mName.c_str());}
	/*start size for twig stroke*/
	void setTwigBaseWidth(double twb){if(twb == 0.4) return; fprintf_s(mFile, "setAttr \".twb\" %f;\n", twb);}
	/*start size for twig stroke*/
	void setTwigBaseWidth(const DoubleID& twb){fprintf_s(mFile,"connectAttr \"");twb.write(mFile);fprintf_s(mFile,"\" \"%s.twb\";\n",mName.c_str());}
	/*end size for twig stroke*/
	void setTwigTipWidth(double twt){if(twt == 0.2) return; fprintf_s(mFile, "setAttr \".twt\" %f;\n", twt);}
	/*end size for twig stroke*/
	void setTwigTipWidth(const DoubleID& twt){fprintf_s(mFile,"connectAttr \"");twt.write(mFile);fprintf_s(mFile,"\" \"%s.twt\";\n",mName.c_str());}
	/*
	how much twigs are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	void setTwigStiffness(double tgs){if(tgs == 0.5) return; fprintf_s(mFile, "setAttr \".tgs\" %f;\n", tgs);}
	/*
	how much twigs are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	void setTwigStiffness(const DoubleID& tgs){fprintf_s(mFile,"connectAttr \"");tgs.write(mFile);fprintf_s(mFile,"\" \"%s.tgs\";\n",mName.c_str());}
	/*put branches on twigs rather than twigs on branches*/
	void setBranchAfterTwigs(bool bat){if(bat == false) return; fprintf_s(mFile, "setAttr \".bat\" %i;\n", bat);}
	/*put branches on twigs rather than twigs on branches*/
	void setBranchAfterTwigs(const BoolID& bat){fprintf_s(mFile,"connectAttr \"");bat.write(mFile);fprintf_s(mFile,"\" \"%s.bat\";\n",mName.c_str());}
	/*number of leaves created at each sprout*/
	void setLeavesInCluster(int lic){if(lic == 1) return; fprintf_s(mFile, "setAttr \".lic\" %i;\n", lic);}
	/*number of leaves created at each sprout*/
	void setLeavesInCluster(const IntID& lic){fprintf_s(mFile,"connectAttr \"");lic.write(mFile);fprintf_s(mFile,"\" \"%s.lic\";\n",mName.c_str());}
	/*
	This determines which components may sprout leaves.
	0 - On All
	1 - On Secondary Branches Only
	2 - On Twigs Only
	*/
	void setLeafLocation(unsigned int llo){if(llo == 0) return; fprintf_s(mFile, "setAttr \".llo\" %i;\n", llo);}
	/*
	This determines which components may sprout leaves.
	0 - On All
	1 - On Secondary Branches Only
	2 - On Twigs Only
	*/
	void setLeafLocation(const UnsignedintID& llo){fprintf_s(mFile,"connectAttr \"");llo.write(mFile);fprintf_s(mFile,"\" \"%s.llo\";\n",mName.c_str());}
	/*rate of omitted leaves*/
	void setLeafDropout(double ldp){if(ldp == 0.0) return; fprintf_s(mFile, "setAttr \".ldp\" %f;\n", ldp);}
	/*rate of omitted leaves*/
	void setLeafDropout(const DoubleID& ldp){fprintf_s(mFile,"connectAttr \"");ldp.write(mFile);fprintf_s(mFile,"\" \"%s.ldp\";\n",mName.c_str());}
	/*angle of leaf with branch at leafStart*/
	void setLeafAngle1(double ll1){if(ll1 == 75.0) return; fprintf_s(mFile, "setAttr \".ll1\" %f;\n", ll1);}
	/*angle of leaf with branch at leafStart*/
	void setLeafAngle1(const DoubleID& ll1){fprintf_s(mFile,"connectAttr \"");ll1.write(mFile);fprintf_s(mFile,"\" \"%s.ll1\";\n",mName.c_str());}
	/*angle of leaf with branch at branch tip*/
	void setLeafAngle2(double ll2){if(ll2 == 25.0) return; fprintf_s(mFile, "setAttr \".ll2\" %f;\n", ll2);}
	/*angle of leaf with branch at branch tip*/
	void setLeafAngle2(const DoubleID& ll2){fprintf_s(mFile,"connectAttr \"");ll2.write(mFile);fprintf_s(mFile,"\" \"%s.ll2\";\n",mName.c_str());}
	/*rate of twist about branch per leaf*/
	void setLeafTwist(double ltw){if(ltw == 0.0) return; fprintf_s(mFile, "setAttr \".ltw\" %f;\n", ltw);}
	/*rate of twist about branch per leaf*/
	void setLeafTwist(const DoubleID& ltw){fprintf_s(mFile,"connectAttr \"");ltw.write(mFile);fprintf_s(mFile,"\" \"%s.ltw\";\n",mName.c_str());}
	/*
	amount of bend about the axis defined by the
	current twist of the leaf. This can be used to make
	a leaf roll up, or provide better shaping of the
	general curl of the leaf.
	*/
	void setLeafBend(double lbn){if(lbn == 0.0) return; fprintf_s(mFile, "setAttr \".lbn\" %f;\n", lbn);}
	/*
	amount of bend about the axis defined by the
	current twist of the leaf. This can be used to make
	a leaf roll up, or provide better shaping of the
	general curl of the leaf.
	*/
	void setLeafBend(const DoubleID& lbn){fprintf_s(mFile,"connectAttr \"");lbn.write(mFile);fprintf_s(mFile,"\" \"%s.lbn\";\n",mName.c_str());}
	/*
	amount of curl away from the primary axis of the leaf.
	This is perpendicular to the leaf bend direction.
	This can both provide a more natural leaf shape and help
	create a more rounded shading when the flatness is 1.0.
	The left side of the ramp represents curl at the leaf
	base and the right side is the leaf tip.
	*/
	void setLeafCurl(size_t lcl_i,const LeafCurl& lcl){fprintf_s(mFile, "setAttr \".lcl[%i]\" ",lcl_i);lcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	amount of curl away from the primary axis of the leaf.
	This is perpendicular to the leaf bend direction.
	This can both provide a more natural leaf shape and help
	create a more rounded shading when the flatness is 1.0.
	The left side of the ramp represents curl at the leaf
	base and the right side is the leaf tip.
	*/
	void setLeafCurl(size_t lcl_i,const LeafCurlID& lcl){fprintf_s(mFile,"connectAttr \"");lcl.write(mFile);fprintf_s(mFile,"\" \"%s.lcl[%i]\";\n",mName.c_str(),lcl_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setLeafCurl_Position(size_t lcl_i,float lclp){if(lclp == 0.0) return; fprintf_s(mFile, "setAttr \".lcl[%i].lclp\" %f;\n", lcl_i,lclp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setLeafCurl_Position(size_t lcl_i,const FloatID& lclp){fprintf_s(mFile,"connectAttr \"");lclp.write(mFile);fprintf_s(mFile,"\" \"%s.lcl[%i].lclp\";\n",mName.c_str(),lcl_i);}
	/*Ramp value at the sibling position*/
	void setLeafCurl_FloatValue(size_t lcl_i,float lclfv){if(lclfv == 0.0) return; fprintf_s(mFile, "setAttr \".lcl[%i].lclfv\" %f;\n", lcl_i,lclfv);}
	/*Ramp value at the sibling position*/
	void setLeafCurl_FloatValue(size_t lcl_i,const FloatID& lclfv){fprintf_s(mFile,"connectAttr \"");lclfv.write(mFile);fprintf_s(mFile,"\" \"%s.lcl[%i].lclfv\";\n",mName.c_str(),lcl_i);}
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
	void setLeafCurl_Interp(size_t lcl_i,unsigned int lcli){if(lcli == 0) return; fprintf_s(mFile, "setAttr \".lcl[%i].lcli\" %i;\n", lcl_i,lcli);}
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
	void setLeafCurl_Interp(size_t lcl_i,const UnsignedintID& lcli){fprintf_s(mFile,"connectAttr \"");lcli.write(mFile);fprintf_s(mFile,"\" \"%s.lcl[%i].lcli\";\n",mName.c_str(),lcl_i);}
	/*
	amount of rotation or twist of the leaf about its primary axis.
	This can be used to make leaves better face a certain
	direction.
	*/
	void setLeafTwirl(double ltwl){if(ltwl == 0.0) return; fprintf_s(mFile, "setAttr \".ltwl\" %f;\n", ltwl);}
	/*
	amount of rotation or twist of the leaf about its primary axis.
	This can be used to make leaves better face a certain
	direction.
	*/
	void setLeafTwirl(const DoubleID& ltwl){fprintf_s(mFile,"connectAttr \"");ltwl.write(mFile);fprintf_s(mFile,"\" \"%s.ltwl\";\n",mName.c_str());}
	/*number of segments in leaf stroke*/
	void setLeafSegments(int lsg){if(lsg == 5) return; fprintf_s(mFile, "setAttr \".lsg\" %i;\n", lsg);}
	/*number of segments in leaf stroke*/
	void setLeafSegments(const IntID& lsg){fprintf_s(mFile,"connectAttr \"");lsg.write(mFile);fprintf_s(mFile,"\" \"%s.lsg\";\n",mName.c_str());}
	/*point along branch where leaves start*/
	void setLeafStart(double lst){if(lst == .5) return; fprintf_s(mFile, "setAttr \".lst\" %f;\n", lst);}
	/*point along branch where leaves start*/
	void setLeafStart(const DoubleID& lst){fprintf_s(mFile,"connectAttr \"");lst.write(mFile);fprintf_s(mFile,"\" \"%s.lst\";\n",mName.c_str());}
	/*total number of leaf sprouts created between Leaf Start and branch tip*/
	void setNumLeafClusters(double nlc){if(nlc == 3) return; fprintf_s(mFile, "setAttr \".nlc\" %f;\n", nlc);}
	/*total number of leaf sprouts created between Leaf Start and branch tip*/
	void setNumLeafClusters(const DoubleID& nlc){fprintf_s(mFile,"connectAttr \"");nlc.write(mFile);fprintf_s(mFile,"\" \"%s.nlc\";\n",mName.c_str());}
	/*flatness to use for the leaf stroke*/
	void setLeafFlatness(double lft){if(lft == 1.0) return; fprintf_s(mFile, "setAttr \".lft\" %f;\n", lft);}
	/*flatness to use for the leaf stroke*/
	void setLeafFlatness(const DoubleID& lft){fprintf_s(mFile,"connectAttr \"");lft.write(mFile);fprintf_s(mFile,"\" \"%s.lft\";\n",mName.c_str());}
	/*length scale for leaf stroke*/
	void setLeafLength(double lln){if(lln == 0.3) return; fprintf_s(mFile, "setAttr \".lln\" %f;\n", lln);}
	/*length scale for leaf stroke*/
	void setLeafLength(const DoubleID& lln){fprintf_s(mFile,"connectAttr \"");lln.write(mFile);fprintf_s(mFile,"\" \"%s.lln\";\n",mName.c_str());}
	/*width at base of leaf stroke*/
	void setLeafBaseWidth(double leb){if(leb == 0.15) return; fprintf_s(mFile, "setAttr \".leb\" %f;\n", leb);}
	/*width at base of leaf stroke*/
	void setLeafBaseWidth(const DoubleID& leb){fprintf_s(mFile,"connectAttr \"");leb.write(mFile);fprintf_s(mFile,"\" \"%s.leb\";\n",mName.c_str());}
	/*width at tip of leaf stroke*/
	void setLeafTipWidth(double let){if(let == 0.05) return; fprintf_s(mFile, "setAttr \".let\" %f;\n", let);}
	/*width at tip of leaf stroke*/
	void setLeafTipWidth(const DoubleID& let){fprintf_s(mFile,"connectAttr \"");let.write(mFile);fprintf_s(mFile,"\" \"%s.let\";\n",mName.c_str());}
	/*scale factor for leaves at branch tip*/
	void setLeafSizeDecay(double lsd){if(lsd == 0.7) return; fprintf_s(mFile, "setAttr \".lsd\" %f;\n", lsd);}
	/*scale factor for leaves at branch tip*/
	void setLeafSizeDecay(const DoubleID& lsd){fprintf_s(mFile,"connectAttr \"");lsd.write(mFile);fprintf_s(mFile,"\" \"%s.lsd\";\n",mName.c_str());}
	/*blend factor between translucent and lambertian shading for leaves*/
	void setLeafTranslucence(double ltr){if(ltr == 0.7) return; fprintf_s(mFile, "setAttr \".ltr\" %f;\n", ltr);}
	/*blend factor between translucent and lambertian shading for leaves*/
	void setLeafTranslucence(const DoubleID& ltr){fprintf_s(mFile,"connectAttr \"");ltr.write(mFile);fprintf_s(mFile,"\" \"%s.ltr\";\n",mName.c_str());}
	/*intensity of specular highlights on leaves*/
	void setLeafSpecular(double lsp){if(lsp == 0.0) return; fprintf_s(mFile, "setAttr \".lsp\" %f;\n", lsp);}
	/*intensity of specular highlights on leaves*/
	void setLeafSpecular(const DoubleID& lsp){fprintf_s(mFile,"connectAttr \"");lsp.write(mFile);fprintf_s(mFile,"\" \"%s.lsp\";\n",mName.c_str());}
	/*whether or not to add a single leaf at the very end of the branch*/
	void setTerminalLeaf(bool tml){if(tml == false) return; fprintf_s(mFile, "setAttr \".tml\" %i;\n", tml);}
	/*whether or not to add a single leaf at the very end of the branch*/
	void setTerminalLeaf(const BoolID& tml){fprintf_s(mFile,"connectAttr \"");tml.write(mFile);fprintf_s(mFile,"\" \"%s.tml\";\n",mName.c_str());}
	/*start color for leaf*/
	void setLeafColor1(const float3& lc1){fprintf_s(mFile, "setAttr \".lc1\" -type \"float3\" ");lc1.write(mFile);fprintf_s(mFile,";\n");}
	/*start color for leaf*/
	void setLeafColor1(const Float3ID& lc1){fprintf_s(mFile,"connectAttr \"");lc1.write(mFile);fprintf_s(mFile,"\" \"%s.lc1\";\n",mName.c_str());}
	/*leaf start Red value*/
	void setLeafColor1R(float lr1){if(lr1 == 0.2) return; fprintf_s(mFile, "setAttr \".lc1.lr1\" %f;\n", lr1);}
	/*leaf start Red value*/
	void setLeafColor1R(const FloatID& lr1){fprintf_s(mFile,"connectAttr \"");lr1.write(mFile);fprintf_s(mFile,"\" \"%s.lc1.lr1\";\n",mName.c_str());}
	/*leaf start Green value*/
	void setLeafColor1G(float lg1){if(lg1 == 0.6) return; fprintf_s(mFile, "setAttr \".lc1.lg1\" %f;\n", lg1);}
	/*leaf start Green value*/
	void setLeafColor1G(const FloatID& lg1){fprintf_s(mFile,"connectAttr \"");lg1.write(mFile);fprintf_s(mFile,"\" \"%s.lc1.lg1\";\n",mName.c_str());}
	/*leaf start Blue value*/
	void setLeafColor1B(float lb1){if(lb1 == 0.3) return; fprintf_s(mFile, "setAttr \".lc1.lb1\" %f;\n", lb1);}
	/*leaf start Blue value*/
	void setLeafColor1B(const FloatID& lb1){fprintf_s(mFile,"connectAttr \"");lb1.write(mFile);fprintf_s(mFile,"\" \"%s.lc1.lb1\";\n",mName.c_str());}
	/*start color for leaf*/
	void setLeafColor2(const float3& lc2){fprintf_s(mFile, "setAttr \".lc2\" -type \"float3\" ");lc2.write(mFile);fprintf_s(mFile,";\n");}
	/*start color for leaf*/
	void setLeafColor2(const Float3ID& lc2){fprintf_s(mFile,"connectAttr \"");lc2.write(mFile);fprintf_s(mFile,"\" \"%s.lc2\";\n",mName.c_str());}
	/*leaf end Red value*/
	void setLeafColor2R(float lr2){if(lr2 == 0.4) return; fprintf_s(mFile, "setAttr \".lc2.lr2\" %f;\n", lr2);}
	/*leaf end Red value*/
	void setLeafColor2R(const FloatID& lr2){fprintf_s(mFile,"connectAttr \"");lr2.write(mFile);fprintf_s(mFile,"\" \"%s.lc2.lr2\";\n",mName.c_str());}
	/*leaf end Green value*/
	void setLeafColor2G(float lg2){if(lg2 == 0.6) return; fprintf_s(mFile, "setAttr \".lc2.lg2\" %f;\n", lg2);}
	/*leaf end Green value*/
	void setLeafColor2G(const FloatID& lg2){fprintf_s(mFile,"connectAttr \"");lg2.write(mFile);fprintf_s(mFile,"\" \"%s.lc2.lg2\";\n",mName.c_str());}
	/*leaf end Blue value*/
	void setLeafColor2B(float lb2){if(lb2 == 0.3) return; fprintf_s(mFile, "setAttr \".lc2.lb2\" %f;\n", lb2);}
	/*leaf end Blue value*/
	void setLeafColor2B(const FloatID& lb2){fprintf_s(mFile,"connectAttr \"");lb2.write(mFile);fprintf_s(mFile,"\" \"%s.lc2.lb2\";\n",mName.c_str());}
	/*random deviation in hue of leaves*/
	void setLeafHueRand(double lhr){if(lhr == 0.0) return; fprintf_s(mFile, "setAttr \".lhr\" %f;\n", lhr);}
	/*random deviation in hue of leaves*/
	void setLeafHueRand(const DoubleID& lhr){fprintf_s(mFile,"connectAttr \"");lhr.write(mFile);fprintf_s(mFile,"\" \"%s.lhr\";\n",mName.c_str());}
	/*random deviation in color saturation of leaves*/
	void setLeafSatRand(double lsr){if(lsr == 0.0) return; fprintf_s(mFile, "setAttr \".lsr\" %f;\n", lsr);}
	/*random deviation in color saturation of leaves*/
	void setLeafSatRand(const DoubleID& lsr){fprintf_s(mFile,"connectAttr \"");lsr.write(mFile);fprintf_s(mFile,"\" \"%s.lsr\";\n",mName.c_str());}
	/*random deviation in brighness value of leaves*/
	void setLeafValRand(double lvr){if(lvr == 0.0) return; fprintf_s(mFile, "setAttr \".lvr\" %f;\n", lvr);}
	/*random deviation in brighness value of leaves*/
	void setLeafValRand(const DoubleID& lvr){fprintf_s(mFile,"connectAttr \"");lvr.write(mFile);fprintf_s(mFile,"\" \"%s.lvr\";\n",mName.c_str());}
	/*whether or not to use the main texture applied to branches*/
	void setLeafUseBranchTex(bool lub){if(lub == true) return; fprintf_s(mFile, "setAttr \".lub\" %i;\n", lub);}
	/*whether or not to use the main texture applied to branches*/
	void setLeafUseBranchTex(const BoolID& lub){fprintf_s(mFile,"connectAttr \"");lub.write(mFile);fprintf_s(mFile,"\" \"%s.lub\";\n",mName.c_str());}
	/*the name of an image file to use for leaf strokes*/
	void setLeafImage(const string& lim){if(lim == "NULL") return; fprintf_s(mFile, "setAttr \".lim\" -type \"string\" ");lim.write(mFile);fprintf_s(mFile,";\n");}
	/*the name of an image file to use for leaf strokes*/
	void setLeafImage(const StringID& lim){fprintf_s(mFile,"connectAttr \"");lim.write(mFile);fprintf_s(mFile,"\" \"%s.lim\";\n",mName.c_str());}
	/*
	how much leaves are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	void setLeafStiffness(double lfs){if(lfs == 0.5) return; fprintf_s(mFile, "setAttr \".lfs\" %f;\n", lfs);}
	/*
	how much leaves are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	void setLeafStiffness(const DoubleID& lfs){fprintf_s(mFile,"connectAttr \"");lfs.write(mFile);fprintf_s(mFile,"\" \"%s.lfs\";\n",mName.c_str());}
	/*size of bud swelling at branch tip*/
	void setBudSize(double bds){if(bds == 0.03) return; fprintf_s(mFile, "setAttr \".bds\" %f;\n", bds);}
	/*size of bud swelling at branch tip*/
	void setBudSize(const DoubleID& bds){fprintf_s(mFile,"connectAttr \"");bds.write(mFile);fprintf_s(mFile,"\" \"%s.bds\";\n",mName.c_str());}
	/*color of bud at branch tip*/
	void setBudColor(const float3& bcr){fprintf_s(mFile, "setAttr \".bcr\" -type \"float3\" ");bcr.write(mFile);fprintf_s(mFile,";\n");}
	/*color of bud at branch tip*/
	void setBudColor(const Float3ID& bcr){fprintf_s(mFile,"connectAttr \"");bcr.write(mFile);fprintf_s(mFile,"\" \"%s.bcr\";\n",mName.c_str());}
	/*bud Red value*/
	void setBudColorR(float bur){if(bur == 0.4) return; fprintf_s(mFile, "setAttr \".bcr.bur\" %f;\n", bur);}
	/*bud Red value*/
	void setBudColorR(const FloatID& bur){fprintf_s(mFile,"connectAttr \"");bur.write(mFile);fprintf_s(mFile,"\" \"%s.bcr.bur\";\n",mName.c_str());}
	/*bud Green value*/
	void setBudColorG(float bug){if(bug == 0.8) return; fprintf_s(mFile, "setAttr \".bcr.bug\" %f;\n", bug);}
	/*bud Green value*/
	void setBudColorG(const FloatID& bug){fprintf_s(mFile,"connectAttr \"");bug.write(mFile);fprintf_s(mFile,"\" \"%s.bcr.bug\";\n",mName.c_str());}
	/*bud Blue value*/
	void setBudColorB(float bub){if(bub == 0.2) return; fprintf_s(mFile, "setAttr \".bcr.bub\" %f;\n", bub);}
	/*bud Blue value*/
	void setBudColorB(const FloatID& bub){fprintf_s(mFile,"connectAttr \"");bub.write(mFile);fprintf_s(mFile,"\" \"%s.bcr.bub\";\n",mName.c_str());}
	/*number of flowers created at life end*/
	void setPetalsInFlower(int pif){if(pif == 1) return; fprintf_s(mFile, "setAttr \".pif\" %i;\n", pif);}
	/*number of flowers created at life end*/
	void setPetalsInFlower(const IntID& pif){fprintf_s(mFile,"connectAttr \"");pif.write(mFile);fprintf_s(mFile,"\" \"%s.pif\";\n",mName.c_str());}
	/*
	This determines which components may sprout flowers.
	0 - On All
	1 - On Secondary Branches Only
	2 - On Twigs Only
	*/
	void setFlowerLocation(unsigned int flc){if(flc == 0) return; fprintf_s(mFile, "setAttr \".flc\" %i;\n", flc);}
	/*
	This determines which components may sprout flowers.
	0 - On All
	1 - On Secondary Branches Only
	2 - On Twigs Only
	*/
	void setFlowerLocation(const UnsignedintID& flc){fprintf_s(mFile,"connectAttr \"");flc.write(mFile);fprintf_s(mFile,"\" \"%s.flc\";\n",mName.c_str());}
	/*rate of omitted flowers*/
	void setPetalDropout(double pdp){if(pdp == 0.0) return; fprintf_s(mFile, "setAttr \".pdp\" %f;\n", pdp);}
	/*rate of omitted flowers*/
	void setPetalDropout(const DoubleID& pdp){fprintf_s(mFile,"connectAttr \"");pdp.write(mFile);fprintf_s(mFile,"\" \"%s.pdp\";\n",mName.c_str());}
	/*angle of flower with branch at flowerStart*/
	void setFlowerAngle1(double fw1){if(fw1 == 75.0) return; fprintf_s(mFile, "setAttr \".fw1\" %f;\n", fw1);}
	/*angle of flower with branch at flowerStart*/
	void setFlowerAngle1(const DoubleID& fw1){fprintf_s(mFile,"connectAttr \"");fw1.write(mFile);fprintf_s(mFile,"\" \"%s.fw1\";\n",mName.c_str());}
	/*angle of flower with branch at branch tip*/
	void setFlowerAngle2(double fw2){if(fw2 == 25.0) return; fprintf_s(mFile, "setAttr \".fw2\" %f;\n", fw2);}
	/*angle of flower with branch at branch tip*/
	void setFlowerAngle2(const DoubleID& fw2){fprintf_s(mFile,"connectAttr \"");fw2.write(mFile);fprintf_s(mFile,"\" \"%s.fw2\";\n",mName.c_str());}
	/*rate of twist about branch per flower*/
	void setFlowerTwist(double ftw){if(ftw == 0.23) return; fprintf_s(mFile, "setAttr \".ftw\" %f;\n", ftw);}
	/*rate of twist about branch per flower*/
	void setFlowerTwist(const DoubleID& ftw){fprintf_s(mFile,"connectAttr \"");ftw.write(mFile);fprintf_s(mFile,"\" \"%s.ftw\";\n",mName.c_str());}
	/*
	amount of bend about the axis defined by the
	current twist of the petal. This can be used to make
	a petal curl up, or provide better shaping of the petal.
	*/
	void setPetalBend(double pbn){if(pbn == 0.0) return; fprintf_s(mFile, "setAttr \".pbn\" %f;\n", pbn);}
	/*
	amount of bend about the axis defined by the
	current twist of the petal. This can be used to make
	a petal curl up, or provide better shaping of the petal.
	*/
	void setPetalBend(const DoubleID& pbn){fprintf_s(mFile,"connectAttr \"");pbn.write(mFile);fprintf_s(mFile,"\" \"%s.pbn\";\n",mName.c_str());}
	/*
	amount of curl away from the primary axis of the petal.
	This is perpendicular to the petal bend direction.
	This can provide a more natural petal shape and help avoid
	interpenetration with neighboring petals.
	The left side of the ramp represents curl at the petal
	base and the right side is the petal tip.
	*/
	void setPetalCurl(size_t pcl_i,const PetalCurl& pcl){fprintf_s(mFile, "setAttr \".pcl[%i]\" ",pcl_i);pcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	amount of curl away from the primary axis of the petal.
	This is perpendicular to the petal bend direction.
	This can provide a more natural petal shape and help avoid
	interpenetration with neighboring petals.
	The left side of the ramp represents curl at the petal
	base and the right side is the petal tip.
	*/
	void setPetalCurl(size_t pcl_i,const PetalCurlID& pcl){fprintf_s(mFile,"connectAttr \"");pcl.write(mFile);fprintf_s(mFile,"\" \"%s.pcl[%i]\";\n",mName.c_str(),pcl_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setPetalCurl_Position(size_t pcl_i,float pclp){if(pclp == 0.0) return; fprintf_s(mFile, "setAttr \".pcl[%i].pclp\" %f;\n", pcl_i,pclp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setPetalCurl_Position(size_t pcl_i,const FloatID& pclp){fprintf_s(mFile,"connectAttr \"");pclp.write(mFile);fprintf_s(mFile,"\" \"%s.pcl[%i].pclp\";\n",mName.c_str(),pcl_i);}
	/*Ramp value at the sibling position*/
	void setPetalCurl_FloatValue(size_t pcl_i,float pclfv){if(pclfv == 0.0) return; fprintf_s(mFile, "setAttr \".pcl[%i].pclfv\" %f;\n", pcl_i,pclfv);}
	/*Ramp value at the sibling position*/
	void setPetalCurl_FloatValue(size_t pcl_i,const FloatID& pclfv){fprintf_s(mFile,"connectAttr \"");pclfv.write(mFile);fprintf_s(mFile,"\" \"%s.pcl[%i].pclfv\";\n",mName.c_str(),pcl_i);}
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
	void setPetalCurl_Interp(size_t pcl_i,unsigned int pcli){if(pcli == 0) return; fprintf_s(mFile, "setAttr \".pcl[%i].pcli\" %i;\n", pcl_i,pcli);}
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
	void setPetalCurl_Interp(size_t pcl_i,const UnsignedintID& pcli){fprintf_s(mFile,"connectAttr \"");pcli.write(mFile);fprintf_s(mFile,"\" \"%s.pcl[%i].pcli\";\n",mName.c_str(),pcl_i);}
	/*
	amount of rotation or twist of the petal about its primary axis.
	This can be used to make petals better face a certain
	direction, or to twist a bit so as not to self
	intersect when forming a flower.
	*/
	void setPetalTwirl(double lpwl){if(lpwl == 0.0) return; fprintf_s(mFile, "setAttr \".lpwl\" %f;\n", lpwl);}
	/*
	amount of rotation or twist of the petal about its primary axis.
	This can be used to make petals better face a certain
	direction, or to twist a bit so as not to self
	intersect when forming a flower.
	*/
	void setPetalTwirl(const DoubleID& lpwl){fprintf_s(mFile,"connectAttr \"");lpwl.write(mFile);fprintf_s(mFile,"\" \"%s.lpwl\";\n",mName.c_str());}
	/*number of segments in flower stroke*/
	void setPetalSegments(int psg){if(psg == 5) return; fprintf_s(mFile, "setAttr \".psg\" %i;\n", psg);}
	/*number of segments in flower stroke*/
	void setPetalSegments(const IntID& psg){fprintf_s(mFile,"connectAttr \"");psg.write(mFile);fprintf_s(mFile,"\" \"%s.psg\";\n",mName.c_str());}
	/*point along branch where flowers start*/
	void setFlowerStart(double fst){if(fst == 1) return; fprintf_s(mFile, "setAttr \".fst\" %f;\n", fst);}
	/*point along branch where flowers start*/
	void setFlowerStart(const DoubleID& fst){fprintf_s(mFile,"connectAttr \"");fst.write(mFile);fprintf_s(mFile,"\" \"%s.fst\";\n",mName.c_str());}
	/*total number of petal groups created between flower Start and branch tip*/
	void setNumFlowers(double nfl){if(nfl == 10) return; fprintf_s(mFile, "setAttr \".nfl\" %f;\n", nfl);}
	/*total number of petal groups created between flower Start and branch tip*/
	void setNumFlowers(const DoubleID& nfl){fprintf_s(mFile,"connectAttr \"");nfl.write(mFile);fprintf_s(mFile,"\" \"%s.nfl\";\n",mName.c_str());}
	/*flatness to use for the flower stroke*/
	void setPetalFlatness(double pft){if(pft == 1.0) return; fprintf_s(mFile, "setAttr \".pft\" %f;\n", pft);}
	/*flatness to use for the flower stroke*/
	void setPetalFlatness(const DoubleID& pft){fprintf_s(mFile,"connectAttr \"");pft.write(mFile);fprintf_s(mFile,"\" \"%s.pft\";\n",mName.c_str());}
	/*length scale for flower stroke*/
	void setPetalLength(double pln){if(pln == 0.2) return; fprintf_s(mFile, "setAttr \".pln\" %f;\n", pln);}
	/*length scale for flower stroke*/
	void setPetalLength(const DoubleID& pln){fprintf_s(mFile,"connectAttr \"");pln.write(mFile);fprintf_s(mFile,"\" \"%s.pln\";\n",mName.c_str());}
	/*width at base of flower petals*/
	void setPetalBaseWidth(double ptb){if(ptb == 0.05) return; fprintf_s(mFile, "setAttr \".ptb\" %f;\n", ptb);}
	/*width at base of flower petals*/
	void setPetalBaseWidth(const DoubleID& ptb){fprintf_s(mFile,"connectAttr \"");ptb.write(mFile);fprintf_s(mFile,"\" \"%s.ptb\";\n",mName.c_str());}
	/*width at tip of flower petals*/
	void setPetalTipWidth(double ptt){if(ptt == 0.1) return; fprintf_s(mFile, "setAttr \".ptt\" %f;\n", ptt);}
	/*width at tip of flower petals*/
	void setPetalTipWidth(const DoubleID& ptt){fprintf_s(mFile,"connectAttr \"");ptt.write(mFile);fprintf_s(mFile,"\" \"%s.ptt\";\n",mName.c_str());}
	/*scale factor for flowers at branch tip*/
	void setFlowerSizeDecay(double fsd){if(fsd == 0.7) return; fprintf_s(mFile, "setAttr \".fsd\" %f;\n", fsd);}
	/*scale factor for flowers at branch tip*/
	void setFlowerSizeDecay(const DoubleID& fsd){fprintf_s(mFile,"connectAttr \"");fsd.write(mFile);fprintf_s(mFile,"\" \"%s.fsd\";\n",mName.c_str());}
	/*blend factor between translucent and lambertian shading for flowers*/
	void setFlowerTranslucence(double ftr){if(ftr == 0.7) return; fprintf_s(mFile, "setAttr \".ftr\" %f;\n", ftr);}
	/*blend factor between translucent and lambertian shading for flowers*/
	void setFlowerTranslucence(const DoubleID& ftr){fprintf_s(mFile,"connectAttr \"");ftr.write(mFile);fprintf_s(mFile,"\" \"%s.ftr\";\n",mName.c_str());}
	/*intensity of specular highlights on flowers*/
	void setFlowerSpecular(double fsp){if(fsp == 0.0) return; fprintf_s(mFile, "setAttr \".fsp\" %f;\n", fsp);}
	/*intensity of specular highlights on flowers*/
	void setFlowerSpecular(const DoubleID& fsp){fprintf_s(mFile,"connectAttr \"");fsp.write(mFile);fprintf_s(mFile,"\" \"%s.fsp\";\n",mName.c_str());}
	/*start color for flower*/
	void setPetalColor1(const float3& pc1){fprintf_s(mFile, "setAttr \".pc1\" -type \"float3\" ");pc1.write(mFile);fprintf_s(mFile,";\n");}
	/*start color for flower*/
	void setPetalColor1(const Float3ID& pc1){fprintf_s(mFile,"connectAttr \"");pc1.write(mFile);fprintf_s(mFile,"\" \"%s.pc1\";\n",mName.c_str());}
	/*flower start Red value*/
	void setPetalColor1R(float pr1){if(pr1 == 0.8) return; fprintf_s(mFile, "setAttr \".pc1.pr1\" %f;\n", pr1);}
	/*flower start Red value*/
	void setPetalColor1R(const FloatID& pr1){fprintf_s(mFile,"connectAttr \"");pr1.write(mFile);fprintf_s(mFile,"\" \"%s.pc1.pr1\";\n",mName.c_str());}
	/*flower start Green value*/
	void setPetalColor1G(float pg1){if(pg1 == 0.2) return; fprintf_s(mFile, "setAttr \".pc1.pg1\" %f;\n", pg1);}
	/*flower start Green value*/
	void setPetalColor1G(const FloatID& pg1){fprintf_s(mFile,"connectAttr \"");pg1.write(mFile);fprintf_s(mFile,"\" \"%s.pc1.pg1\";\n",mName.c_str());}
	/*flower start Blue value*/
	void setPetalColor1B(float pb1){if(pb1 == 0.1) return; fprintf_s(mFile, "setAttr \".pc1.pb1\" %f;\n", pb1);}
	/*flower start Blue value*/
	void setPetalColor1B(const FloatID& pb1){fprintf_s(mFile,"connectAttr \"");pb1.write(mFile);fprintf_s(mFile,"\" \"%s.pc1.pb1\";\n",mName.c_str());}
	/*start color for flower*/
	void setPetalColor2(const float3& pc2){fprintf_s(mFile, "setAttr \".pc2\" -type \"float3\" ");pc2.write(mFile);fprintf_s(mFile,";\n");}
	/*start color for flower*/
	void setPetalColor2(const Float3ID& pc2){fprintf_s(mFile,"connectAttr \"");pc2.write(mFile);fprintf_s(mFile,"\" \"%s.pc2\";\n",mName.c_str());}
	/*flower end Red value*/
	void setPetalColor2R(float pr2){if(pr2 == 1.0) return; fprintf_s(mFile, "setAttr \".pc2.pr2\" %f;\n", pr2);}
	/*flower end Red value*/
	void setPetalColor2R(const FloatID& pr2){fprintf_s(mFile,"connectAttr \"");pr2.write(mFile);fprintf_s(mFile,"\" \"%s.pc2.pr2\";\n",mName.c_str());}
	/*flower end Green value*/
	void setPetalColor2G(float pg2){if(pg2 == 1.0) return; fprintf_s(mFile, "setAttr \".pc2.pg2\" %f;\n", pg2);}
	/*flower end Green value*/
	void setPetalColor2G(const FloatID& pg2){fprintf_s(mFile,"connectAttr \"");pg2.write(mFile);fprintf_s(mFile,"\" \"%s.pc2.pg2\";\n",mName.c_str());}
	/*flower end Blue value*/
	void setPetalColor2B(float pb2){if(pb2 == 1.0) return; fprintf_s(mFile, "setAttr \".pc2.pb2\" %f;\n", pb2);}
	/*flower end Blue value*/
	void setPetalColor2B(const FloatID& pb2){fprintf_s(mFile,"connectAttr \"");pb2.write(mFile);fprintf_s(mFile,"\" \"%s.pc2.pb2\";\n",mName.c_str());}
	/*random deviation in hue of flowers*/
	void setFlowerHueRand(double fhr){if(fhr == 0.0) return; fprintf_s(mFile, "setAttr \".fhr\" %f;\n", fhr);}
	/*random deviation in hue of flowers*/
	void setFlowerHueRand(const DoubleID& fhr){fprintf_s(mFile,"connectAttr \"");fhr.write(mFile);fprintf_s(mFile,"\" \"%s.fhr\";\n",mName.c_str());}
	/*random deviation in color saturation of flowers*/
	void setFlowerSatRand(double fsr){if(fsr == 0.0) return; fprintf_s(mFile, "setAttr \".fsr\" %f;\n", fsr);}
	/*random deviation in color saturation of flowers*/
	void setFlowerSatRand(const DoubleID& fsr){fprintf_s(mFile,"connectAttr \"");fsr.write(mFile);fprintf_s(mFile,"\" \"%s.fsr\";\n",mName.c_str());}
	/*random deviation in brightness value of flowers*/
	void setFlowerValRand(double fvr){if(fvr == 0.0) return; fprintf_s(mFile, "setAttr \".fvr\" %f;\n", fvr);}
	/*random deviation in brightness value of flowers*/
	void setFlowerValRand(const DoubleID& fvr){fprintf_s(mFile,"connectAttr \"");fvr.write(mFile);fprintf_s(mFile,"\" \"%s.fvr\";\n",mName.c_str());}
	/*whether or not to use the main texture applied to branches*/
	void setFlowerUseBranchTex(bool fub){if(fub == true) return; fprintf_s(mFile, "setAttr \".fub\" %i;\n", fub);}
	/*whether or not to use the main texture applied to branches*/
	void setFlowerUseBranchTex(const BoolID& fub){fprintf_s(mFile,"connectAttr \"");fub.write(mFile);fprintf_s(mFile,"\" \"%s.fub\";\n",mName.c_str());}
	/*the name of an image file to use for flower petals*/
	void setFlowerImage(const string& fim){if(fim == "NULL") return; fprintf_s(mFile, "setAttr \".fim\" -type \"string\" ");fim.write(mFile);fprintf_s(mFile,";\n");}
	/*the name of an image file to use for flower petals*/
	void setFlowerImage(const StringID& fim){fprintf_s(mFile,"connectAttr \"");fim.write(mFile);fprintf_s(mFile,"\" \"%s.fim\";\n",mName.c_str());}
	/*
	how much flowers are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	void setFlowerStiffness(double fls){if(fls == 0.5) return; fprintf_s(mFile, "setAttr \".fls\" %f;\n", fls);}
	/*
	how much flowers are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	void setFlowerStiffness(const DoubleID& fls){fprintf_s(mFile,"connectAttr \"");fls.write(mFile);fprintf_s(mFile,"\" \"%s.fls\";\n",mName.c_str());}
	/*
	method used to simplify the wireframe draw in conjunction with the stroke display quality setting
	0 - stroke quality only affects the number of tubes
	1 - stroke quality only affects the number of segments along tubes
	2 - stroke quality affects the number of tubes and the number of segments
	*/
	void setSimplifyMethod(unsigned int smp){if(smp == 0) return; fprintf_s(mFile, "setAttr \".smp\" %i;\n", smp);}
	/*
	method used to simplify the wireframe draw in conjunction with the stroke display quality setting
	0 - stroke quality only affects the number of tubes
	1 - stroke quality only affects the number of segments along tubes
	2 - stroke quality affects the number of tubes and the number of segments
	*/
	void setSimplifyMethod(const UnsignedintID& smp){fprintf_s(mFile,"connectAttr \"");smp.write(mFile);fprintf_s(mFile,"\" \"%s.smp\";\n",mName.c_str());}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setColorLengthMap(unsigned int clm){if(clm == 0) return; fprintf_s(mFile, "setAttr \".clm\" %i;\n", clm);}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setColorLengthMap(const UnsignedintID& clm){fprintf_s(mFile,"connectAttr \"");clm.write(mFile);fprintf_s(mFile,"\" \"%s.clm\";\n",mName.c_str());}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setTranspLengthMap(unsigned int tlm){if(tlm == 0) return; fprintf_s(mFile, "setAttr \".tlm\" %i;\n", tlm);}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setTranspLengthMap(const UnsignedintID& tlm){fprintf_s(mFile,"connectAttr \"");tlm.write(mFile);fprintf_s(mFile,"\" \"%s.tlm\";\n",mName.c_str());}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setIncandLengthMap(unsigned int ilm){if(ilm == 0) return; fprintf_s(mFile, "setAttr \".ilm\" %i;\n", ilm);}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setIncandLengthMap(const UnsignedintID& ilm){fprintf_s(mFile,"connectAttr \"");ilm.write(mFile);fprintf_s(mFile,"\" \"%s.ilm\";\n",mName.c_str());}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setWidthLengthMap(unsigned int wlm){if(wlm == 0) return; fprintf_s(mFile, "setAttr \".wlm\" %i;\n", wlm);}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setWidthLengthMap(const UnsignedintID& wlm){fprintf_s(mFile,"connectAttr \"");wlm.write(mFile);fprintf_s(mFile,"\" \"%s.wlm\";\n",mName.c_str());}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setSplitLengthMap(unsigned int spl){if(spl == 0) return; fprintf_s(mFile, "setAttr \".spl\" %i;\n", spl);}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	void setSplitLengthMap(const UnsignedintID& spl){fprintf_s(mFile,"connectAttr \"");spl.write(mFile);fprintf_s(mFile,"\" \"%s.spl\";\n",mName.c_str());}
	/*Texture color using the current texture*/
	void setMapColor(bool mcl){if(mcl == false) return; fprintf_s(mFile, "setAttr \".mcl\" %i;\n", mcl);}
	/*Texture color using the current texture*/
	void setMapColor(const BoolID& mcl){fprintf_s(mFile,"connectAttr \"");mcl.write(mFile);fprintf_s(mFile,"\" \"%s.mcl\";\n",mName.c_str());}
	/*Texture opacity using the current texture*/
	void setMapOpacity(bool mop){if(mop == false) return; fprintf_s(mFile, "setAttr \".mop\" %i;\n", mop);}
	/*Texture opacity using the current texture*/
	void setMapOpacity(const BoolID& mop){fprintf_s(mFile,"connectAttr \"");mop.write(mFile);fprintf_s(mFile,"\" \"%s.mop\";\n",mName.c_str());}
	/*Texture displacement using the current texture*/
	void setMapDisplacement(bool mds){if(mds == false) return; fprintf_s(mFile, "setAttr \".mds\" %i;\n", mds);}
	/*Texture displacement using the current texture*/
	void setMapDisplacement(const BoolID& mds){fprintf_s(mFile,"connectAttr \"");mds.write(mFile);fprintf_s(mFile,"\" \"%s.mds\";\n",mName.c_str());}
	/*
	define the current texture method
	0 - Checker
	1 - U Ramp
	2 - V Ramp
	3 - Fractal
	4 - File
	*/
	void setTextureType(unsigned int txt){if(txt == 0) return; fprintf_s(mFile, "setAttr \".txt\" %i;\n", txt);}
	/*
	define the current texture method
	0 - Checker
	1 - U Ramp
	2 - V Ramp
	3 - Fractal
	4 - File
	*/
	void setTextureType(const UnsignedintID& txt){fprintf_s(mFile,"connectAttr \"");txt.write(mFile);fprintf_s(mFile,"\" \"%s.txt\";\n",mName.c_str());}
	/*
	0 - the texture is fit to the view
	1 - the mapping is in eyespace but scaled and offset based on the
	start of the brushstroke or tube
	2 - the mapping is in worldspace but always centered on the tube, such
	that there never a visible seam.
	3 - the texture is fully mapped in 3D around the tube, with a seam
	that is visible from some views. The texture appears correct when
	the viewpoint is animated.
	*/
	void setMapMethod(unsigned int mmd){if(mmd == 0) return; fprintf_s(mFile, "setAttr \".mmd\" %i;\n", mmd);}
	/*
	0 - the texture is fit to the view
	1 - the mapping is in eyespace but scaled and offset based on the
	start of the brushstroke or tube
	2 - the mapping is in worldspace but always centered on the tube, such
	that there never a visible seam.
	3 - the texture is fully mapped in 3D around the tube, with a seam
	that is visible from some views. The texture appears correct when
	the viewpoint is animated.
	*/
	void setMapMethod(const UnsignedintID& mmd){fprintf_s(mFile,"connectAttr \"");mmd.write(mFile);fprintf_s(mFile,"\" \"%s.mmd\";\n",mName.c_str());}
	/*The amount the texture's color is multiplied by the non-textured color.*/
	void setTexColorScale(double tcs){if(tcs == 1.0) return; fprintf_s(mFile, "setAttr \".tcs\" %f;\n", tcs);}
	/*The amount the texture's color is multiplied by the non-textured color.*/
	void setTexColorScale(const DoubleID& tcs){fprintf_s(mFile,"connectAttr \"");tcs.write(mFile);fprintf_s(mFile,"\" \"%s.tcs\";\n",mName.c_str());}
	/*The amount the texture's color is added into the output color*/
	void setTexColorOffset(double tco){if(tco == 0.0) return; fprintf_s(mFile, "setAttr \".tco\" %f;\n", tco);}
	/*The amount the texture's color is added into the output color*/
	void setTexColorOffset(const DoubleID& tco){fprintf_s(mFile,"connectAttr \"");tco.write(mFile);fprintf_s(mFile,"\" \"%s.tco\";\n",mName.c_str());}
	/*The amount the texture's alpha multiplies the opacity.*/
	void setTexOpacityScale(double tos){if(tos == 1.0) return; fprintf_s(mFile, "setAttr \".tos\" %f;\n", tos);}
	/*The amount the texture's alpha multiplies the opacity.*/
	void setTexOpacityScale(const DoubleID& tos){fprintf_s(mFile,"connectAttr \"");tos.write(mFile);fprintf_s(mFile,"\" \"%s.tos\";\n",mName.c_str());}
	/*The amount the texture's alpha is added into the output opacity*/
	void setTexOpacityOffset(double too){if(too == 0.0) return; fprintf_s(mFile, "setAttr \".too\" %f;\n", too);}
	/*The amount the texture's alpha is added into the output opacity*/
	void setTexOpacityOffset(const DoubleID& too){fprintf_s(mFile,"connectAttr \"");too.write(mFile);fprintf_s(mFile,"\" \"%s.too\";\n",mName.c_str());}
	/*
	The amount the texture's alpha is used to scale ( or
	multiply ) the tube width. Thus this form of
	displacement is relative to the width of tubes.
	*/
	void setDisplacementScale(double dsc){if(dsc == 1.0) return; fprintf_s(mFile, "setAttr \".dsc\" %f;\n", dsc);}
	/*
	The amount the texture's alpha is used to scale ( or
	multiply ) the tube width. Thus this form of
	displacement is relative to the width of tubes.
	*/
	void setDisplacementScale(const DoubleID& dsc){fprintf_s(mFile,"connectAttr \"");dsc.write(mFile);fprintf_s(mFile,"\" \"%s.dsc\";\n",mName.c_str());}
	/*
	The amount the texture's alpha is added to the tube width.
	This displacement is independent of tube width, so
	thin tubes may have more displacement than desired.
	*/
	void setDisplacementOffset(double dof){if(dof == 0.0) return; fprintf_s(mFile, "setAttr \".dof\" %f;\n", dof);}
	/*
	The amount the texture's alpha is added to the tube width.
	This displacement is independent of tube width, so
	thin tubes may have more displacement than desired.
	*/
	void setDisplacementOffset(const DoubleID& dof){fprintf_s(mFile,"connectAttr \"");dof.write(mFile);fprintf_s(mFile,"\" \"%s.dof\";\n",mName.c_str());}
	/*
	The amount of bump added relative to the general displacement.
	The bump provides needed detail when displaced
	triangles are large relative to a pixel.
	Note that bump mapping requires
	both that displacement is on and perPixel
	mesh shading is used. If one wishes to have only the
	bump with no displacement, then make the displacement
	scale and offset zero.
	*/
	void setBumpIntensity(double bmi){if(bmi == 1.0) return; fprintf_s(mFile, "setAttr \".bmi\" %f;\n", bmi);}
	/*
	The amount of bump added relative to the general displacement.
	The bump provides needed detail when displaced
	triangles are large relative to a pixel.
	Note that bump mapping requires
	both that displacement is on and perPixel
	mesh shading is used. If one wishes to have only the
	bump with no displacement, then make the displacement
	scale and offset zero.
	*/
	void setBumpIntensity(const DoubleID& bmi){fprintf_s(mFile,"connectAttr \"");bmi.write(mFile);fprintf_s(mFile,"\" \"%s.bmi\";\n",mName.c_str());}
	/*
	This scales the separation of the extra texture
	samples used in computing the bump map. It has the
	effect of making the bump smoother and less detailed.
	If it is too low, however, the bump may appear broken
	up and may jitter in animations. A value of 1.0 avoids
	most of these jitter or aliasing problems, but
	results in too smooth a bump for distant
	or oblique strokes. In practice a value of 0.5
	can be a good compromise.
	*/
	void setBumpBlur(double bbl){if(bbl == 0.5) return; fprintf_s(mFile, "setAttr \".bbl\" %f;\n", bbl);}
	/*
	This scales the separation of the extra texture
	samples used in computing the bump map. It has the
	effect of making the bump smoother and less detailed.
	If it is too low, however, the bump may appear broken
	up and may jitter in animations. A value of 1.0 avoids
	most of these jitter or aliasing problems, but
	results in too smooth a bump for distant
	or oblique strokes. In practice a value of 0.5
	can be a good compromise.
	*/
	void setBumpBlur(const DoubleID& bbl){fprintf_s(mFile,"connectAttr \"");bbl.write(mFile);fprintf_s(mFile,"\" \"%s.bbl\";\n",mName.c_str());}
	/*
	In particular one may wish to use the color from file
	textures for displacement instead of the image alpha.
	This also frees the alpha for use in transparency.
	This uses the brighness of the color for displacement.
	*/
	void setLuminanceIsDisplacement(bool lid){if(lid == true) return; fprintf_s(mFile, "setAttr \".lid\" %i;\n", lid);}
	/*
	In particular one may wish to use the color from file
	textures for displacement instead of the image alpha.
	This also frees the alpha for use in transparency.
	This uses the brighness of the color for displacement.
	*/
	void setLuminanceIsDisplacement(const BoolID& lid){fprintf_s(mFile,"connectAttr \"");lid.write(mFile);fprintf_s(mFile,"\" \"%s.lid\";\n",mName.c_str());}
	/*color for min texture values*/
	void setTexColor1(const float3& tc1){fprintf_s(mFile, "setAttr \".tc1\" -type \"float3\" ");tc1.write(mFile);fprintf_s(mFile,";\n");}
	/*color for min texture values*/
	void setTexColor1(const Float3ID& tc1){fprintf_s(mFile,"connectAttr \"");tc1.write(mFile);fprintf_s(mFile,"\" \"%s.tc1\";\n",mName.c_str());}
	/*texColor1 Red value*/
	void setTexColor1R(float x1r){if(x1r == 1.0) return; fprintf_s(mFile, "setAttr \".tc1.x1r\" %f;\n", x1r);}
	/*texColor1 Red value*/
	void setTexColor1R(const FloatID& x1r){fprintf_s(mFile,"connectAttr \"");x1r.write(mFile);fprintf_s(mFile,"\" \"%s.tc1.x1r\";\n",mName.c_str());}
	/*texColor1 Green value*/
	void setTexColor1G(float x1g){if(x1g == 1.0) return; fprintf_s(mFile, "setAttr \".tc1.x1g\" %f;\n", x1g);}
	/*texColor1 Green value*/
	void setTexColor1G(const FloatID& x1g){fprintf_s(mFile,"connectAttr \"");x1g.write(mFile);fprintf_s(mFile,"\" \"%s.tc1.x1g\";\n",mName.c_str());}
	/*texColor1 Blue value*/
	void setTexColor1B(float x1b){if(x1b == 1.0) return; fprintf_s(mFile, "setAttr \".tc1.x1b\" %f;\n", x1b);}
	/*texColor1 Blue value*/
	void setTexColor1B(const FloatID& x1b){fprintf_s(mFile,"connectAttr \"");x1b.write(mFile);fprintf_s(mFile,"\" \"%s.tc1.x1b\";\n",mName.c_str());}
	/*color for min texture values*/
	void setTexColor2(const float3& tc2){fprintf_s(mFile, "setAttr \".tc2\" -type \"float3\" ");tc2.write(mFile);fprintf_s(mFile,";\n");}
	/*color for min texture values*/
	void setTexColor2(const Float3ID& tc2){fprintf_s(mFile,"connectAttr \"");tc2.write(mFile);fprintf_s(mFile,"\" \"%s.tc2\";\n",mName.c_str());}
	/*texColor2 Red value*/
	void setTexColor2R(float x2r){if(x2r == 0.0) return; fprintf_s(mFile, "setAttr \".tc2.x2r\" %f;\n", x2r);}
	/*texColor2 Red value*/
	void setTexColor2R(const FloatID& x2r){fprintf_s(mFile,"connectAttr \"");x2r.write(mFile);fprintf_s(mFile,"\" \"%s.tc2.x2r\";\n",mName.c_str());}
	/*texColor2 Green value*/
	void setTexColor2G(float x2g){if(x2g == 0.0) return; fprintf_s(mFile, "setAttr \".tc2.x2g\" %f;\n", x2g);}
	/*texColor2 Green value*/
	void setTexColor2G(const FloatID& x2g){fprintf_s(mFile,"connectAttr \"");x2g.write(mFile);fprintf_s(mFile,"\" \"%s.tc2.x2g\";\n",mName.c_str());}
	/*texColor2 Blue value*/
	void setTexColor2B(float x2b){if(x2b == 0.0) return; fprintf_s(mFile, "setAttr \".tc2.x2b\" %f;\n", x2b);}
	/*texColor2 Blue value*/
	void setTexColor2B(const FloatID& x2b){fprintf_s(mFile,"connectAttr \"");x2b.write(mFile);fprintf_s(mFile,"\" \"%s.tc2.x2b\";\n",mName.c_str());}
	/*Alpha (opacity) for max texture values.*/
	void setTexAlpha1(double al1){if(al1 == 1.0) return; fprintf_s(mFile, "setAttr \".al1\" %f;\n", al1);}
	/*Alpha (opacity) for max texture values.*/
	void setTexAlpha1(const DoubleID& al1){fprintf_s(mFile,"connectAttr \"");al1.write(mFile);fprintf_s(mFile,"\" \"%s.al1\";\n",mName.c_str());}
	/*Alpha (opacity) for min texture values.*/
	void setTexAlpha2(double al2){if(al2 == 0.0) return; fprintf_s(mFile, "setAttr \".al2\" %f;\n", al2);}
	/*Alpha (opacity) for min texture values.*/
	void setTexAlpha2(const DoubleID& al2){fprintf_s(mFile,"connectAttr \"");al2.write(mFile);fprintf_s(mFile,"\" \"%s.al2\";\n",mName.c_str());}
	/*Degree to which Uvalue along stroke is in worldspace*/
	void setTexUniformity(double txu){if(txu == 0.5) return; fprintf_s(mFile, "setAttr \".txu\" %f;\n", txu);}
	/*Degree to which Uvalue along stroke is in worldspace*/
	void setTexUniformity(const DoubleID& txu){fprintf_s(mFile,"connectAttr \"");txu.write(mFile);fprintf_s(mFile,"\" \"%s.txu\";\n",mName.c_str());}
	/*
	Correct for dark fringes along file texture alpha boundaries.
	The file texture's color is premultiplied by 1/alpha.
	*/
	void setFringeRemoval(bool frm){if(frm == true) return; fprintf_s(mFile, "setAttr \".frm\" %i;\n", frm);}
	/*
	Correct for dark fringes along file texture alpha boundaries.
	The file texture's color is premultiplied by 1/alpha.
	*/
	void setFringeRemoval(const BoolID& frm){fprintf_s(mFile,"connectAttr \"");frm.write(mFile);fprintf_s(mFile,"\" \"%s.frm\";\n",mName.c_str());}
	/*repeat of texture in U dimension*/
	void setRepeatU(double rpu){if(rpu == 1.0) return; fprintf_s(mFile, "setAttr \".rpu\" %f;\n", rpu);}
	/*repeat of texture in U dimension*/
	void setRepeatU(const DoubleID& rpu){fprintf_s(mFile,"connectAttr \"");rpu.write(mFile);fprintf_s(mFile,"\" \"%s.rpu\";\n",mName.c_str());}
	/*repeat of texture in V dimension*/
	void setRepeatV(double rpv){if(rpv == 1.0) return; fprintf_s(mFile, "setAttr \".rpv\" %f;\n", rpv);}
	/*repeat of texture in V dimension*/
	void setRepeatV(const DoubleID& rpv){fprintf_s(mFile,"connectAttr \"");rpv.write(mFile);fprintf_s(mFile,"\" \"%s.rpv\";\n",mName.c_str());}
	/*translate of texture along U*/
	void setOffsetU(double ofu){if(ofu == 0.0) return; fprintf_s(mFile, "setAttr \".ofu\" %f;\n", ofu);}
	/*translate of texture along U*/
	void setOffsetU(const DoubleID& ofu){fprintf_s(mFile,"connectAttr \"");ofu.write(mFile);fprintf_s(mFile,"\" \"%s.ofu\";\n",mName.c_str());}
	/*translate of texture along V*/
	void setOffsetV(double ofv){if(ofv == 0.0) return; fprintf_s(mFile, "setAttr \".ofv\" %f;\n", ofv);}
	/*translate of texture along V*/
	void setOffsetV(const DoubleID& ofv){fprintf_s(mFile,"connectAttr \"");ofv.write(mFile);fprintf_s(mFile,"\" \"%s.ofv\";\n",mName.c_str());}
	/*blurring of texture(needed for antialiasing )*/
	void setBlurMult(double bmt){if(bmt == 1.0) return; fprintf_s(mFile, "setAttr \".bmt\" %f;\n", bmt);}
	/*blurring of texture(needed for antialiasing )*/
	void setBlurMult(const DoubleID& bmt){fprintf_s(mFile,"connectAttr \"");bmt.write(mFile);fprintf_s(mFile,"\" \"%s.bmt\";\n",mName.c_str());}
	/*scale of 2Dnoise used for smear effect*/
	void setSmear(double smr){if(smr == 0.1) return; fprintf_s(mFile, "setAttr \".smr\" %f;\n", smr);}
	/*scale of 2Dnoise used for smear effect*/
	void setSmear(const DoubleID& smr){fprintf_s(mFile,"connectAttr \"");smr.write(mFile);fprintf_s(mFile,"\" \"%s.smr\";\n",mName.c_str());}
	/*smear offset intensity in U*/
	void setSmearU(double sru){if(sru == 0.0) return; fprintf_s(mFile, "setAttr \".sru\" %f;\n", sru);}
	/*smear offset intensity in U*/
	void setSmearU(const DoubleID& sru){fprintf_s(mFile,"connectAttr \"");sru.write(mFile);fprintf_s(mFile,"\" \"%s.sru\";\n",mName.c_str());}
	/*smear offset intensity in V*/
	void setSmearV(double srv){if(srv == 0.0) return; fprintf_s(mFile, "setAttr \".srv\" %f;\n", srv);}
	/*smear offset intensity in V*/
	void setSmearV(const DoubleID& srv){fprintf_s(mFile,"connectAttr \"");srv.write(mFile);fprintf_s(mFile,"\" \"%s.srv\";\n",mName.c_str());}
	/*the name of an image file to use for file texture type*/
	void setImageName(const string& imn){if(imn == "NULL") return; fprintf_s(mFile, "setAttr \".imn\" -type \"string\" ");imn.write(mFile);fprintf_s(mFile,";\n");}
	/*the name of an image file to use for file texture type*/
	void setImageName(const StringID& imn){fprintf_s(mFile,"connectAttr \"");imn.write(mFile);fprintf_s(mFile,"\" \"%s.imn\";\n",mName.c_str());}
	/*
	When <b>Use Frame Extension</b> is on, the frame
	number in the file name will be replaced with the number
	specified in the Frame Extension attribute.  Use this when
	you want to animate the texture.
	*/
	void setUseFrameExtension(bool ufe){if(ufe == false) return; fprintf_s(mFile, "setAttr \".ufe\" %i;\n", ufe);}
	/*
	When <b>Use Frame Extension</b> is on, the frame
	number in the file name will be replaced with the number
	specified in the Frame Extension attribute.  Use this when
	you want to animate the texture.
	*/
	void setUseFrameExtension(const BoolID& ufe){fprintf_s(mFile,"connectAttr \"");ufe.write(mFile);fprintf_s(mFile,"\" \"%s.ufe\";\n",mName.c_str());}
	/*
	<b>Frame Extension</b> replaces the frame extension number
	in the file name (if there is one).  This attribute is only
	meaningful if Use FrameExtension is turned on.
	<p/>
	Keyframe this attribute when you want to use a sequence of files
	as a file texture.
	*/
	void setFrameExtension(int fe){if(fe == 1) return; fprintf_s(mFile, "setAttr \".fe\" %i;\n", fe);}
	/*
	<b>Frame Extension</b> replaces the frame extension number
	in the file name (if there is one).  This attribute is only
	meaningful if Use FrameExtension is turned on.
	<p/>
	Keyframe this attribute when you want to use a sequence of files
	as a file texture.
	*/
	void setFrameExtension(const IntID& fe){fprintf_s(mFile,"connectAttr \"");fe.write(mFile);fprintf_s(mFile,"\" \"%s.fe\";\n",mName.c_str());}
	/*the roughness of the fractal*/
	void setFractalRatio(double fra){if(fra == 0.7) return; fprintf_s(mFile, "setAttr \".fra\" %f;\n", fra);}
	/*the roughness of the fractal*/
	void setFractalRatio(const DoubleID& fra){fprintf_s(mFile,"connectAttr \"");fra.write(mFile);fprintf_s(mFile,"\" \"%s.fra\";\n",mName.c_str());}
	/*the intensity or contrast of the fractal*/
	void setFractalAmplitude(double fam){if(fam == 1.0) return; fprintf_s(mFile, "setAttr \".fam\" %f;\n", fam);}
	/*the intensity or contrast of the fractal*/
	void setFractalAmplitude(const DoubleID& fam){fprintf_s(mFile,"connectAttr \"");fam.write(mFile);fprintf_s(mFile,"\" \"%s.fam\";\n",mName.c_str());}
	/*a cutoff value*/
	void setFractalThreshold(double fth){if(fth == 0.0) return; fprintf_s(mFile, "setAttr \".fth\" %f;\n", fth);}
	/*a cutoff value*/
	void setFractalThreshold(const DoubleID& fth){fprintf_s(mFile,"connectAttr \"");fth.write(mFile);fprintf_s(mFile,"\" \"%s.fth\";\n",mName.c_str());}
	/*
	<b>Multi Streaks</b> is the number of added tubes. These tubes
	will share the same shading as the base tube they are
	derived from. They are created at render time and are simple duplicates,
	and thus do not take up any shape computation. This allows one to have a
	great number of tubes and yet render them in a reasonable amount of time.
	*/
	void setMultiStreaks(int mst){if(mst == 0) return; fprintf_s(mFile, "setAttr \".mst\" %i;\n", mst);}
	/*
	<b>Multi Streaks</b> is the number of added tubes. These tubes
	will share the same shading as the base tube they are
	derived from. They are created at render time and are simple duplicates,
	and thus do not take up any shape computation. This allows one to have a
	great number of tubes and yet render them in a reasonable amount of time.
	*/
	void setMultiStreaks(const IntID& mst){fprintf_s(mFile,"connectAttr \"");mst.write(mFile);fprintf_s(mFile,"\" \"%s.mst\";\n",mName.c_str());}
	/*the maximum offset for added tubes relative to the brush width at the tube base*/
	void setMultiStreakSpread1(double ms1){if(ms1 == 0.2) return; fprintf_s(mFile, "setAttr \".ms1\" %f;\n", ms1);}
	/*the maximum offset for added tubes relative to the brush width at the tube base*/
	void setMultiStreakSpread1(const DoubleID& ms1){fprintf_s(mFile,"connectAttr \"");ms1.write(mFile);fprintf_s(mFile,"\" \"%s.ms1\";\n",mName.c_str());}
	/*the maximum offset for added tubes relative to the brush width at the tube tip*/
	void setMultiStreakSpread2(double ms2){if(ms2 == 0.2) return; fprintf_s(mFile, "setAttr \".ms2\" %f;\n", ms2);}
	/*the maximum offset for added tubes relative to the brush width at the tube tip*/
	void setMultiStreakSpread2(const DoubleID& ms2){fprintf_s(mFile,"connectAttr \"");ms2.write(mFile);fprintf_s(mFile,"\" \"%s.ms2\";\n",mName.c_str());}
	/*a diffuse brightness randomization for the added tubes*/
	void setMultiStreakDiffuseRand(double msdr){if(msdr == 0.0) return; fprintf_s(mFile, "setAttr \".msdr\" %f;\n", msdr);}
	/*a diffuse brightness randomization for the added tubes*/
	void setMultiStreakDiffuseRand(const DoubleID& msdr){fprintf_s(mFile,"connectAttr \"");msdr.write(mFile);fprintf_s(mFile,"\" \"%s.msdr\";\n",mName.c_str());}
	/*a specular brightness randomization for the added tubes*/
	void setMultiStreakSpecularRand(double mssr){if(mssr == 0.0) return; fprintf_s(mFile, "setAttr \".mssr\" %f;\n", mssr);}
	/*a specular brightness randomization for the added tubes*/
	void setMultiStreakSpecularRand(const DoubleID& mssr){fprintf_s(mFile,"connectAttr \"");mssr.write(mFile);fprintf_s(mFile,"\" \"%s.mssr\";\n",mName.c_str());}
	/*a brightness randomization for the added tubes*/
	void setMultiStreakLightAll(bool msla){if(msla == false) return; fprintf_s(mFile, "setAttr \".msla\" %i;\n", msla);}
	/*a brightness randomization for the added tubes*/
	void setMultiStreakLightAll(const BoolID& msla){fprintf_s(mFile,"connectAttr \"");msla.write(mFile);fprintf_s(mFile,"\" \"%s.msla\";\n",mName.c_str());}
	/*
	toggles backface removal for the mesh brushType
	making the inside edge of tubes disappear and speeding
	up the render
	*/
	void setSingleSided(bool snsd){if(snsd == false) return; fprintf_s(mFile, "setAttr \".snsd\" %i;\n", snsd);}
	/*
	toggles backface removal for the mesh brushType
	making the inside edge of tubes disappear and speeding
	up the render
	*/
	void setSingleSided(const BoolID& snsd){fprintf_s(mFile,"connectAttr \"");snsd.write(mFile);fprintf_s(mFile,"\" \"%s.snsd\";\n",mName.c_str());}
	/*the number of points in each cross section used for the mesh brushType*/
	void setTubeSections(int tbs){if(tbs == 6) return; fprintf_s(mFile, "setAttr \".tbs\" %i;\n", tbs);}
	/*the number of points in each cross section used for the mesh brushType*/
	void setTubeSections(const IntID& tbs){fprintf_s(mFile,"connectAttr \"");tbs.write(mFile);fprintf_s(mFile,"\" \"%s.tbs\";\n",mName.c_str());}
	/*the number of cross sections added for each base segment for the mesh brushType*/
	void setSubSegments(int ssg){if(ssg == 1) return; fprintf_s(mFile, "setAttr \".ssg\" %i;\n", ssg);}
	/*the number of cross sections added for each base segment for the mesh brushType*/
	void setSubSegments(const IntID& ssg){fprintf_s(mFile,"connectAttr \"");ssg.write(mFile);fprintf_s(mFile,"\" \"%s.ssg\";\n",mName.c_str());}
	/*
	light each pixel when rendering, as opposed to
	lighting  each vertex and interpolating the result
	when the mesh brushType is used.
	This will allows for detailed shadows and specular
	highlights. Also when displacement mapping is used it
	will allow a bump mapping of normals within each triangle.
	Note that if realLights is enabled this can result in
	significantly slower renders, as the evaluation of
	Maya lights is slow in the paint effects context.
	*/
	void setPerPixelLighting(bool ppl){if(ppl == false) return; fprintf_s(mFile, "setAttr \".ppl\" %i;\n", ppl);}
	/*
	light each pixel when rendering, as opposed to
	lighting  each vertex and interpolating the result
	when the mesh brushType is used.
	This will allows for detailed shadows and specular
	highlights. Also when displacement mapping is used it
	will allow a bump mapping of normals within each triangle.
	Note that if realLights is enabled this can result in
	significantly slower renders, as the evaluation of
	Maya lights is slow in the paint effects context.
	*/
	void setPerPixelLighting(const BoolID& ppl){fprintf_s(mFile,"connectAttr \"");ppl.write(mFile);fprintf_s(mFile,"\" \"%s.ppl\";\n",mName.c_str());}
	/*
	multiplies the width along the tube determined by
	the base and tip width. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	void setWidthScale(size_t wsc_i,const WidthScale& wsc){fprintf_s(mFile, "setAttr \".wsc[%i]\" ",wsc_i);wsc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	multiplies the width along the tube determined by
	the base and tip width. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	void setWidthScale(size_t wsc_i,const WidthScaleID& wsc){fprintf_s(mFile,"connectAttr \"");wsc.write(mFile);fprintf_s(mFile,"\" \"%s.wsc[%i]\";\n",mName.c_str(),wsc_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWidthScale_Position(size_t wsc_i,float wscp){if(wscp == 0.0) return; fprintf_s(mFile, "setAttr \".wsc[%i].wscp\" %f;\n", wsc_i,wscp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setWidthScale_Position(size_t wsc_i,const FloatID& wscp){fprintf_s(mFile,"connectAttr \"");wscp.write(mFile);fprintf_s(mFile,"\" \"%s.wsc[%i].wscp\";\n",mName.c_str(),wsc_i);}
	/*Ramp value at the sibling position*/
	void setWidthScale_FloatValue(size_t wsc_i,float wscfv){if(wscfv == 0.0) return; fprintf_s(mFile, "setAttr \".wsc[%i].wscfv\" %f;\n", wsc_i,wscfv);}
	/*Ramp value at the sibling position*/
	void setWidthScale_FloatValue(size_t wsc_i,const FloatID& wscfv){fprintf_s(mFile,"connectAttr \"");wscfv.write(mFile);fprintf_s(mFile,"\" \"%s.wsc[%i].wscfv\";\n",mName.c_str(),wsc_i);}
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
	void setWidthScale_Interp(size_t wsc_i,unsigned int wsci){if(wsci == 0) return; fprintf_s(mFile, "setAttr \".wsc[%i].wsci\" %i;\n", wsc_i,wsci);}
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
	void setWidthScale_Interp(size_t wsc_i,const UnsignedintID& wsci){fprintf_s(mFile,"connectAttr \"");wsci.write(mFile);fprintf_s(mFile,"\" \"%s.wsc[%i].wsci\";\n",mName.c_str(),wsc_i);}
	/*
	multiplies the width along the leaf determined by
	the leaf base and tip widths. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	void setLeafWidthScale(size_t lws_i,const LeafWidthScale& lws){fprintf_s(mFile, "setAttr \".lws[%i]\" ",lws_i);lws.write(mFile);fprintf_s(mFile,";\n");}
	/*
	multiplies the width along the leaf determined by
	the leaf base and tip widths. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	void setLeafWidthScale(size_t lws_i,const LeafWidthScaleID& lws){fprintf_s(mFile,"connectAttr \"");lws.write(mFile);fprintf_s(mFile,"\" \"%s.lws[%i]\";\n",mName.c_str(),lws_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setLeafWidthScale_Position(size_t lws_i,float lwsp){if(lwsp == 0.0) return; fprintf_s(mFile, "setAttr \".lws[%i].lwsp\" %f;\n", lws_i,lwsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setLeafWidthScale_Position(size_t lws_i,const FloatID& lwsp){fprintf_s(mFile,"connectAttr \"");lwsp.write(mFile);fprintf_s(mFile,"\" \"%s.lws[%i].lwsp\";\n",mName.c_str(),lws_i);}
	/*Ramp value at the sibling position*/
	void setLeafWidthScale_FloatValue(size_t lws_i,float lwsfv){if(lwsfv == 0.0) return; fprintf_s(mFile, "setAttr \".lws[%i].lwsfv\" %f;\n", lws_i,lwsfv);}
	/*Ramp value at the sibling position*/
	void setLeafWidthScale_FloatValue(size_t lws_i,const FloatID& lwsfv){fprintf_s(mFile,"connectAttr \"");lwsfv.write(mFile);fprintf_s(mFile,"\" \"%s.lws[%i].lwsfv\";\n",mName.c_str(),lws_i);}
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
	void setLeafWidthScale_Interp(size_t lws_i,unsigned int lwsi){if(lwsi == 0) return; fprintf_s(mFile, "setAttr \".lws[%i].lwsi\" %i;\n", lws_i,lwsi);}
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
	void setLeafWidthScale_Interp(size_t lws_i,const UnsignedintID& lwsi){fprintf_s(mFile,"connectAttr \"");lwsi.write(mFile);fprintf_s(mFile,"\" \"%s.lws[%i].lwsi\";\n",mName.c_str(),lws_i);}
	/*
	multiplies the width along the petal determined by
	the petal base and tip widths. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	void setPetalWidthScale(size_t pws_i,const PetalWidthScale& pws){fprintf_s(mFile, "setAttr \".pws[%i]\" ",pws_i);pws.write(mFile);fprintf_s(mFile,";\n");}
	/*
	multiplies the width along the petal determined by
	the petal base and tip widths. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	void setPetalWidthScale(size_t pws_i,const PetalWidthScaleID& pws){fprintf_s(mFile,"connectAttr \"");pws.write(mFile);fprintf_s(mFile,"\" \"%s.pws[%i]\";\n",mName.c_str(),pws_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setPetalWidthScale_Position(size_t pws_i,float pwsp){if(pwsp == 0.0) return; fprintf_s(mFile, "setAttr \".pws[%i].pwsp\" %f;\n", pws_i,pwsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setPetalWidthScale_Position(size_t pws_i,const FloatID& pwsp){fprintf_s(mFile,"connectAttr \"");pwsp.write(mFile);fprintf_s(mFile,"\" \"%s.pws[%i].pwsp\";\n",mName.c_str(),pws_i);}
	/*Ramp value at the sibling position*/
	void setPetalWidthScale_FloatValue(size_t pws_i,float pwsfv){if(pwsfv == 0.0) return; fprintf_s(mFile, "setAttr \".pws[%i].pwsfv\" %f;\n", pws_i,pwsfv);}
	/*Ramp value at the sibling position*/
	void setPetalWidthScale_FloatValue(size_t pws_i,const FloatID& pwsfv){fprintf_s(mFile,"connectAttr \"");pwsfv.write(mFile);fprintf_s(mFile,"\" \"%s.pws[%i].pwsfv\";\n",mName.c_str(),pws_i);}
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
	void setPetalWidthScale_Interp(size_t pws_i,unsigned int pwsi){if(pwsi == 0) return; fprintf_s(mFile, "setAttr \".pws[%i].pwsi\" %i;\n", pws_i,pwsi);}
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
	void setPetalWidthScale_Interp(size_t pws_i,const UnsignedintID& pwsi){fprintf_s(mFile,"connectAttr \"");pwsi.write(mFile);fprintf_s(mFile,"\" \"%s.pws[%i].pwsi\";\n",mName.c_str(),pws_i);}
	/*
	multiplies the twig lengths from root to tip of
	the parent branch.
	The left of the graph is the scale at the
	base of a tree and the right is the scale at the tip.
	*/
	void setTwigLengthScale(size_t tls_i,const TwigLengthScale& tls){fprintf_s(mFile, "setAttr \".tls[%i]\" ",tls_i);tls.write(mFile);fprintf_s(mFile,";\n");}
	/*
	multiplies the twig lengths from root to tip of
	the parent branch.
	The left of the graph is the scale at the
	base of a tree and the right is the scale at the tip.
	*/
	void setTwigLengthScale(size_t tls_i,const TwigLengthScaleID& tls){fprintf_s(mFile,"connectAttr \"");tls.write(mFile);fprintf_s(mFile,"\" \"%s.tls[%i]\";\n",mName.c_str(),tls_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setTwigLengthScale_Position(size_t tls_i,float tlsp){if(tlsp == 0.0) return; fprintf_s(mFile, "setAttr \".tls[%i].tlsp\" %f;\n", tls_i,tlsp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setTwigLengthScale_Position(size_t tls_i,const FloatID& tlsp){fprintf_s(mFile,"connectAttr \"");tlsp.write(mFile);fprintf_s(mFile,"\" \"%s.tls[%i].tlsp\";\n",mName.c_str(),tls_i);}
	/*Ramp value at the sibling position*/
	void setTwigLengthScale_FloatValue(size_t tls_i,float tlsfv){if(tlsfv == 0.0) return; fprintf_s(mFile, "setAttr \".tls[%i].tlsfv\" %f;\n", tls_i,tlsfv);}
	/*Ramp value at the sibling position*/
	void setTwigLengthScale_FloatValue(size_t tls_i,const FloatID& tlsfv){fprintf_s(mFile,"connectAttr \"");tlsfv.write(mFile);fprintf_s(mFile,"\" \"%s.tls[%i].tlsfv\";\n",mName.c_str(),tls_i);}
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
	void setTwigLengthScale_Interp(size_t tls_i,unsigned int tlsi){if(tlsi == 0) return; fprintf_s(mFile, "setAttr \".tls[%i].tlsi\" %i;\n", tls_i,tlsi);}
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
	void setTwigLengthScale_Interp(size_t tls_i,const UnsignedintID& tlsi){fprintf_s(mFile,"connectAttr \"");tlsi.write(mFile);fprintf_s(mFile,"\" \"%s.tls[%i].tlsi\";\n",mName.c_str(),tls_i);}
	/*
	create thorns or prickles on branch tubes when the
	mesh brushType is used. This will
	also show up on normal strokes when tubes = OFF, as
	the effect is not part of the tubes simulation, but
	rather a render effect.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	void setBranchThorns(bool bth){if(bth == false) return; fprintf_s(mFile, "setAttr \".bth\" %i;\n", bth);}
	/*
	create thorns or prickles on branch tubes when the
	mesh brushType is used. This will
	also show up on normal strokes when tubes = OFF, as
	the effect is not part of the tubes simulation, but
	rather a render effect.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	void setBranchThorns(const BoolID& bth){fprintf_s(mFile,"connectAttr \"");bth.write(mFile);fprintf_s(mFile,"\" \"%s.bth\";\n",mName.c_str());}
	/*
	create thorns or prickles on twig tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	void setTwigThorns(bool tth){if(tth == false) return; fprintf_s(mFile, "setAttr \".tth\" %i;\n", tth);}
	/*
	create thorns or prickles on twig tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	void setTwigThorns(const BoolID& tth){fprintf_s(mFile,"connectAttr \"");tth.write(mFile);fprintf_s(mFile,"\" \"%s.tth\";\n",mName.c_str());}
	/*
	create thorns or prickles on leaf tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	void setLeafThorns(bool lth){if(lth == false) return; fprintf_s(mFile, "setAttr \".lth\" %i;\n", lth);}
	/*
	create thorns or prickles on leaf tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	void setLeafThorns(const BoolID& lth){fprintf_s(mFile,"connectAttr \"");lth.write(mFile);fprintf_s(mFile,"\" \"%s.lth\";\n",mName.c_str());}
	/*
	create thorns or prickles on flower tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	void setFlowerThorns(bool flt){if(flt == false) return; fprintf_s(mFile, "setAttr \".flt\" %i;\n", flt);}
	/*
	create thorns or prickles on flower tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	void setFlowerThorns(const BoolID& flt){fprintf_s(mFile,"connectAttr \"");flt.write(mFile);fprintf_s(mFile,"\" \"%s.flt\";\n",mName.c_str());}
	/*The general amount of thorns drawn on the mesh.*/
	void setThornDensity(double nth){if(nth == 10.0) return; fprintf_s(mFile, "setAttr \".nth\" %f;\n", nth);}
	/*The general amount of thorns drawn on the mesh.*/
	void setThornDensity(const DoubleID& nth){fprintf_s(mFile,"connectAttr \"");nth.write(mFile);fprintf_s(mFile,"\" \"%s.nth\";\n",mName.c_str());}
	/*The length (relative to the max tube width) for the thorns.*/
	void setThornLength(double tln){if(tln == 0.5) return; fprintf_s(mFile, "setAttr \".tln\" %f;\n", tln);}
	/*The length (relative to the max tube width) for the thorns.*/
	void setThornLength(const DoubleID& tln){fprintf_s(mFile,"connectAttr \"");tln.write(mFile);fprintf_s(mFile,"\" \"%s.tln\";\n",mName.c_str());}
	/*The width (relative to the thorn length) at the base of the thorn.*/
	void setThornBaseWidth(double tbwd){if(tbwd == 0.05) return; fprintf_s(mFile, "setAttr \".tbwd\" %f;\n", tbwd);}
	/*The width (relative to the thorn length) at the base of the thorn.*/
	void setThornBaseWidth(const DoubleID& tbwd){fprintf_s(mFile,"connectAttr \"");tbwd.write(mFile);fprintf_s(mFile,"\" \"%s.tbwd\";\n",mName.c_str());}
	/*The width (relative to the thorn length) at the outer thorn tip.*/
	void setThornTipWidth(double ttwd){if(ttwd == 0.01) return; fprintf_s(mFile, "setAttr \".ttwd\" %f;\n", ttwd);}
	/*The width (relative to the thorn length) at the outer thorn tip.*/
	void setThornTipWidth(const DoubleID& ttwd){fprintf_s(mFile,"connectAttr \"");ttwd.write(mFile);fprintf_s(mFile,"\" \"%s.ttwd\";\n",mName.c_str());}
	/*
	elevation of the thorns relative to the mesh surface.
	An elevation of 1.0 is along the mesh normal.
	An elevation of 0 is along the tube and an elevation of
	2 is opposite to this.
	*/
	void setThornElevation(double tel){if(tel == 0.6) return; fprintf_s(mFile, "setAttr \".tel\" %f;\n", tel);}
	/*
	elevation of the thorns relative to the mesh surface.
	An elevation of 1.0 is along the mesh normal.
	An elevation of 0 is along the tube and an elevation of
	2 is opposite to this.
	*/
	void setThornElevation(const DoubleID& tel){fprintf_s(mFile,"connectAttr \"");tel.write(mFile);fprintf_s(mFile,"\" \"%s.tel\";\n",mName.c_str());}
	/*intensity of specular highlights on thorns*/
	void setThornSpecular(double tsp){if(tsp == 0.4) return; fprintf_s(mFile, "setAttr \".tsp\" %f;\n", tsp);}
	/*intensity of specular highlights on thorns*/
	void setThornSpecular(const DoubleID& tsp){fprintf_s(mFile,"connectAttr \"");tsp.write(mFile);fprintf_s(mFile,"\" \"%s.tsp\";\n",mName.c_str());}
	/*color of thorns at the base*/
	void setThornBaseColor(const float3& tbc){fprintf_s(mFile, "setAttr \".tbc\" -type \"float3\" ");tbc.write(mFile);fprintf_s(mFile,";\n");}
	/*color of thorns at the base*/
	void setThornBaseColor(const Float3ID& tbc){fprintf_s(mFile,"connectAttr \"");tbc.write(mFile);fprintf_s(mFile,"\" \"%s.tbc\";\n",mName.c_str());}
	/*Thorn Base Color Red value*/
	void setThornBaseColorR(float tbcr){if(tbcr == 0.5) return; fprintf_s(mFile, "setAttr \".tbc.tbcr\" %f;\n", tbcr);}
	/*Thorn Base Color Red value*/
	void setThornBaseColorR(const FloatID& tbcr){fprintf_s(mFile,"connectAttr \"");tbcr.write(mFile);fprintf_s(mFile,"\" \"%s.tbc.tbcr\";\n",mName.c_str());}
	/*Thorn Base Color Green value*/
	void setThornBaseColorG(float tbcg){if(tbcg == 0.5) return; fprintf_s(mFile, "setAttr \".tbc.tbcg\" %f;\n", tbcg);}
	/*Thorn Base Color Green value*/
	void setThornBaseColorG(const FloatID& tbcg){fprintf_s(mFile,"connectAttr \"");tbcg.write(mFile);fprintf_s(mFile,"\" \"%s.tbc.tbcg\";\n",mName.c_str());}
	/*Thorn Base Color Blue value*/
	void setThornBaseColorB(float tbcb){if(tbcb == 0.5) return; fprintf_s(mFile, "setAttr \".tbc.tbcb\" %f;\n", tbcb);}
	/*Thorn Base Color Blue value*/
	void setThornBaseColorB(const FloatID& tbcb){fprintf_s(mFile,"connectAttr \"");tbcb.write(mFile);fprintf_s(mFile,"\" \"%s.tbc.tbcb\";\n",mName.c_str());}
	/*color of thorns at the tip*/
	void setThornTipColor(const float3& ttc){fprintf_s(mFile, "setAttr \".ttc\" -type \"float3\" ");ttc.write(mFile);fprintf_s(mFile,";\n");}
	/*color of thorns at the tip*/
	void setThornTipColor(const Float3ID& ttc){fprintf_s(mFile,"connectAttr \"");ttc.write(mFile);fprintf_s(mFile,"\" \"%s.ttc\";\n",mName.c_str());}
	/*Thorn Tip Color Red value*/
	void setThornTipColorR(float ttcr){if(ttcr == 0.5) return; fprintf_s(mFile, "setAttr \".ttc.ttcr\" %f;\n", ttcr);}
	/*Thorn Tip Color Red value*/
	void setThornTipColorR(const FloatID& ttcr){fprintf_s(mFile,"connectAttr \"");ttcr.write(mFile);fprintf_s(mFile,"\" \"%s.ttc.ttcr\";\n",mName.c_str());}
	/*Thorn Tip Color Green value*/
	void setThornTipColorG(float ttcg){if(ttcg == 0.5) return; fprintf_s(mFile, "setAttr \".ttc.ttcg\" %f;\n", ttcg);}
	/*Thorn Tip Color Green value*/
	void setThornTipColorG(const FloatID& ttcg){fprintf_s(mFile,"connectAttr \"");ttcg.write(mFile);fprintf_s(mFile,"\" \"%s.ttc.ttcg\";\n",mName.c_str());}
	/*Thorn Tip Color Blue value*/
	void setThornTipColorB(float ttcb){if(ttcb == 0.5) return; fprintf_s(mFile, "setAttr \".ttc.ttcb\" %f;\n", ttcb);}
	/*Thorn Tip Color Blue value*/
	void setThornTipColorB(const FloatID& ttcb){fprintf_s(mFile,"connectAttr \"");ttcb.write(mFile);fprintf_s(mFile,"\" \"%s.ttc.ttcb\";\n",mName.c_str());}
	/*
	This defines a spherical reflection environment, where
	the left of the ramp represents light from the top of the sky, the right is
	the ground and the middle is the horizon. Currently it
	only works with the mesh brushtype.
	*/
	void setEnvironment(size_t env_i,const Environment& env){fprintf_s(mFile, "setAttr \".env[%i]\" ",env_i);env.write(mFile);fprintf_s(mFile,";\n");}
	/*
	This defines a spherical reflection environment, where
	the left of the ramp represents light from the top of the sky, the right is
	the ground and the middle is the horizon. Currently it
	only works with the mesh brushtype.
	*/
	void setEnvironment(size_t env_i,const EnvironmentID& env){fprintf_s(mFile,"connectAttr \"");env.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i]\";\n",mName.c_str(),env_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setEnvironment_Position(size_t env_i,float envp){if(envp == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envp\" %f;\n", env_i,envp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setEnvironment_Position(size_t env_i,const FloatID& envp){fprintf_s(mFile,"connectAttr \"");envp.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envp\";\n",mName.c_str(),env_i);}
	/*Ramp color at the sibling position*/
	void setEnvironment_Color(size_t env_i,const float3& envc){fprintf_s(mFile, "setAttr \".env[%i].envc\" -type \"float3\" ",env_i);envc.write(mFile);fprintf_s(mFile,";\n");}
	/*Ramp color at the sibling position*/
	void setEnvironment_Color(size_t env_i,const Float3ID& envc){fprintf_s(mFile,"connectAttr \"");envc.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc\";\n",mName.c_str(),env_i);}
	/*Ramp red channel value at the sibling position*/
	void setEnvironment_ColorR(size_t env_i,float envcr){if(envcr == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcr\" %f;\n", env_i,envcr);}
	/*Ramp red channel value at the sibling position*/
	void setEnvironment_ColorR(size_t env_i,const FloatID& envcr){fprintf_s(mFile,"connectAttr \"");envcr.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcr\";\n",mName.c_str(),env_i);}
	/*Ramp green channel value at the sibling position*/
	void setEnvironment_ColorG(size_t env_i,float envcg){if(envcg == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcg\" %f;\n", env_i,envcg);}
	/*Ramp green channel value at the sibling position*/
	void setEnvironment_ColorG(size_t env_i,const FloatID& envcg){fprintf_s(mFile,"connectAttr \"");envcg.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcg\";\n",mName.c_str(),env_i);}
	/*Ramp blue channel value at the sibling position*/
	void setEnvironment_ColorB(size_t env_i,float envcb){if(envcb == 0.0) return; fprintf_s(mFile, "setAttr \".env[%i].envc.envcb\" %f;\n", env_i,envcb);}
	/*Ramp blue channel value at the sibling position*/
	void setEnvironment_ColorB(size_t env_i,const FloatID& envcb){fprintf_s(mFile,"connectAttr \"");envcb.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envc.envcb\";\n",mName.c_str(),env_i);}
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
	void setEnvironment_Interp(size_t env_i,unsigned int envi){if(envi == 0) return; fprintf_s(mFile, "setAttr \".env[%i].envi\" %i;\n", env_i,envi);}
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
	void setEnvironment_Interp(size_t env_i,const UnsignedintID& envi){fprintf_s(mFile,"connectAttr \"");envi.write(mFile);fprintf_s(mFile,"\" \"%s.env[%i].envi\";\n",mName.c_str(),env_i);}
	/*
	<b>Reflection Rolloff</b> controls the reflectivity of the
	environment ramp based on the angle of the surface with the view.
	The horizontal dimension of the graph represents the brightness
	of reflections and the horizontal represents the facing
	angle with the view.
	<i>Tip:</i> to get a "wet" look (such as wet paint), make the
	edges more reflective.
	*/
	void setReflectionRolloff(size_t rro_i,const ReflectionRolloff& rro){fprintf_s(mFile, "setAttr \".rro[%i]\" ",rro_i);rro.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Reflection Rolloff</b> controls the reflectivity of the
	environment ramp based on the angle of the surface with the view.
	The horizontal dimension of the graph represents the brightness
	of reflections and the horizontal represents the facing
	angle with the view.
	<i>Tip:</i> to get a "wet" look (such as wet paint), make the
	edges more reflective.
	*/
	void setReflectionRolloff(size_t rro_i,const ReflectionRolloffID& rro){fprintf_s(mFile,"connectAttr \"");rro.write(mFile);fprintf_s(mFile,"\" \"%s.rro[%i]\";\n",mName.c_str(),rro_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setReflectionRolloff_Position(size_t rro_i,float rrop){if(rrop == 0.0) return; fprintf_s(mFile, "setAttr \".rro[%i].rrop\" %f;\n", rro_i,rrop);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setReflectionRolloff_Position(size_t rro_i,const FloatID& rrop){fprintf_s(mFile,"connectAttr \"");rrop.write(mFile);fprintf_s(mFile,"\" \"%s.rro[%i].rrop\";\n",mName.c_str(),rro_i);}
	/*Ramp value at the sibling position*/
	void setReflectionRolloff_FloatValue(size_t rro_i,float rrofv){if(rrofv == 0.0) return; fprintf_s(mFile, "setAttr \".rro[%i].rrofv\" %f;\n", rro_i,rrofv);}
	/*Ramp value at the sibling position*/
	void setReflectionRolloff_FloatValue(size_t rro_i,const FloatID& rrofv){fprintf_s(mFile,"connectAttr \"");rrofv.write(mFile);fprintf_s(mFile,"\" \"%s.rro[%i].rrofv\";\n",mName.c_str(),rro_i);}
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
	void setReflectionRolloff_Interp(size_t rro_i,unsigned int rroi){if(rroi == 0) return; fprintf_s(mFile, "setAttr \".rro[%i].rroi\" %i;\n", rro_i,rroi);}
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
	void setReflectionRolloff_Interp(size_t rro_i,const UnsignedintID& rroi){fprintf_s(mFile,"connectAttr \"");rroi.write(mFile);fprintf_s(mFile,"\" \"%s.rro[%i].rroi\";\n",mName.c_str(),rro_i);}
	/*
	intensity of environment reflection on primary
	branches and twigs. This also applies to strokes when
	tubes = OFF. Environment reflections only work with
	the mesh brushtype.
	*/
	void setBranchReflectivity(double brf){if(brf == 0.0) return; fprintf_s(mFile, "setAttr \".brf\" %f;\n", brf);}
	/*
	intensity of environment reflection on primary
	branches and twigs. This also applies to strokes when
	tubes = OFF. Environment reflections only work with
	the mesh brushtype.
	*/
	void setBranchReflectivity(const DoubleID& brf){fprintf_s(mFile,"connectAttr \"");brf.write(mFile);fprintf_s(mFile,"\" \"%s.brf\";\n",mName.c_str());}
	/*
	intensity of environment reflection on leaves.
	Environment reflections only work with
	the mesh brushtype.
	*/
	void setLeafReflectivity(double lrf){if(lrf == 0.0) return; fprintf_s(mFile, "setAttr \".lrf\" %f;\n", lrf);}
	/*
	intensity of environment reflection on leaves.
	Environment reflections only work with
	the mesh brushtype.
	*/
	void setLeafReflectivity(const DoubleID& lrf){fprintf_s(mFile,"connectAttr \"");lrf.write(mFile);fprintf_s(mFile,"\" \"%s.lrf\";\n",mName.c_str());}
	/*
	intensity of environment reflection on flowers.
	Environment reflections only work with
	the mesh brushtype.
	*/
	void setFlowerReflectivity(double frf){if(frf == 0.0) return; fprintf_s(mFile, "setAttr \".frf\" %f;\n", frf);}
	/*
	intensity of environment reflection on flowers.
	Environment reflections only work with
	the mesh brushtype.
	*/
	void setFlowerReflectivity(const DoubleID& frf){fprintf_s(mFile,"connectAttr \"");frf.write(mFile);fprintf_s(mFile,"\" \"%s.frf\";\n",mName.c_str());}
	/*
	Lock the twist about main branches to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the tubes are flat, then the flat
	side will alway orient towards the camera. With this on, one could texture
	a simple flat stroke and always have it face the view. For a tree one could
	create a texture of a tree trunk with rough edges and map to a simple
	flat ribbon where the ribbon always faces the camera.
	*/
	void setForwardTwist(bool fwt){if(fwt == false) return; fprintf_s(mFile, "setAttr \".fwt\" %i;\n", fwt);}
	/*
	Lock the twist about main branches to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the tubes are flat, then the flat
	side will alway orient towards the camera. With this on, one could texture
	a simple flat stroke and always have it face the view. For a tree one could
	create a texture of a tree trunk with rough edges and map to a simple
	flat ribbon where the ribbon always faces the camera.
	*/
	void setForwardTwist(const BoolID& fwt){fprintf_s(mFile,"connectAttr \"");fwt.write(mFile);fprintf_s(mFile,"\" \"%s.fwt\";\n",mName.c_str());}
	/*
	Lock the twist about leaves to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the leaves are flat, then the flat
	side will alway orient towards the camera. One could map an image of an entire
	leafy branch with alpha to a flat leaf and use this toggle to always
	orient this image towards the view.
	*/
	void setLeafForwardTwist(bool lfwt){if(lfwt == false) return; fprintf_s(mFile, "setAttr \".lfwt\" %i;\n", lfwt);}
	/*
	Lock the twist about leaves to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the leaves are flat, then the flat
	side will alway orient towards the camera. One could map an image of an entire
	leafy branch with alpha to a flat leaf and use this toggle to always
	orient this image towards the view.
	*/
	void setLeafForwardTwist(const BoolID& lfwt){fprintf_s(mFile,"connectAttr \"");lfwt.write(mFile);fprintf_s(mFile,"\" \"%s.lfwt\";\n",mName.c_str());}
	/*
	Lock the twist about flower petals to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the petals are flat, then the flat
	side will alway orient towards the camera. One could map an image of an apple
	or rose to a single flat petal, and have this always face the viewpoint.
	*/
	void setPetalForwardTwist(bool lpwt){if(lpwt == false) return; fprintf_s(mFile, "setAttr \".lpwt\" %i;\n", lpwt);}
	/*
	Lock the twist about flower petals to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the petals are flat, then the flat
	side will alway orient towards the camera. One could map an image of an apple
	or rose to a single flat petal, and have this always face the viewpoint.
	*/
	void setPetalForwardTwist(const BoolID& lpwt){fprintf_s(mFile,"connectAttr \"");lpwt.write(mFile);fprintf_s(mFile,"\" \"%s.lpwt\";\n",mName.c_str());}
	/*Add end cap geometry to tubes when using the mesh brushType .*/
	void setEndCaps(bool edc){if(edc == false) return; fprintf_s(mFile, "setAttr \".edc\" %i;\n", edc);}
	/*Add end cap geometry to tubes when using the mesh brushType .*/
	void setEndCaps(const BoolID& edc){fprintf_s(mFile,"connectAttr \"");edc.write(mFile);fprintf_s(mFile,"\" \"%s.edc\";\n",mName.c_str());}
	/*
	Make the edges around tubes hard when using the mesh brushType.
	For example if the tubeSections is 4 then this toggle will make
	the tube shade as if the 4 sides are flat, rather than trying to
	simulate a rounded tube. For bends in the direction of the tube( for
	example due to changes in the widthScale ) the bend angle across a given
	must be sufficiently large to make the angle hard. The number of segments
	used can affect whether a given region on the tube become hard edged or not.
	Note that this parameter adjusts the normals used for shading, and does not
	alter the shape of the tube.
	*/
	void setHardEdges(bool hde){if(hde == false) return; fprintf_s(mFile, "setAttr \".hde\" %i;\n", hde);}
	/*
	Make the edges around tubes hard when using the mesh brushType.
	For example if the tubeSections is 4 then this toggle will make
	the tube shade as if the 4 sides are flat, rather than trying to
	simulate a rounded tube. For bends in the direction of the tube( for
	example due to changes in the widthScale ) the bend angle across a given
	must be sufficiently large to make the angle hard. The number of segments
	used can affect whether a given region on the tube become hard edged or not.
	Note that this parameter adjusts the normals used for shading, and does not
	alter the shape of the tube.
	*/
	void setHardEdges(const BoolID& hde){fprintf_s(mFile,"connectAttr \"");hde.write(mFile);fprintf_s(mFile,"\" \"%s.hde\";\n",mName.c_str());}
	/*output brush data for use by stroke nodes*/
	DynBrushID getOutBrush(){char buffer[4096];sprintf_s (buffer, "%s.obr",mName.c_str());return (const char*)buffer;}
	/*time value for animated effects*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.tim",mName.c_str());return (const char*)buffer;}
	/*Scales all effects*/
	DoubleID getGlobalScale(){char buffer[4096];sprintf_s (buffer, "%s.gsc",mName.c_str());return (const char*)buffer;}
	/*whether or not to use zbuffered occusion*/
	BoolID getDepth(){char buffer[4096];sprintf_s (buffer, "%s.dep",mName.c_str());return (const char*)buffer;}
	/*whether or not to write into the zbuffer( only if depth is ON )*/
	BoolID getModifyDepth(){char buffer[4096];sprintf_s (buffer, "%s.mdp",mName.c_str());return (const char*)buffer;}
	/*whether or not to write into r,g,b*/
	BoolID getModifyColor(){char buffer[4096];sprintf_s (buffer, "%s.mdc",mName.c_str());return (const char*)buffer;}
	/*whether or not to write into the alpha channel*/
	BoolID getModifyAlpha(){char buffer[4096];sprintf_s (buffer, "%s.mda",mName.c_str());return (const char*)buffer;}
	/*Use lights for shading.*/
	BoolID getIlluminated(){char buffer[4096];sprintf_s (buffer, "%s.ill",mName.c_str());return (const char*)buffer;}
	/*make brush strokes appear in depth map shadows*/
	BoolID getCastShadows(){char buffer[4096];sprintf_s (buffer, "%s.csd",mName.c_str());return (const char*)buffer;}
	/*
	The tube width is scaled by the diffuse light
	intensity. Brighter regions will be thinner.
	Shadowed and dark regions will have full width
	tubes. Using negative values can have the reverse
	effect. The lighting used is a diffuse illumination
	that is relative to the local surface normal painted
	on by the stroke.
	*/
	DoubleID getLightingBasedWidth(){char buffer[4096];sprintf_s (buffer, "%s.lbw",mName.c_str());return (const char*)buffer;}
	/*split tubes into branches*/
	BoolID getBranches(){char buffer[4096];sprintf_s (buffer, "%s.brc",mName.c_str());return (const char*)buffer;}
	/*create twigs as offshoots on branches*/
	BoolID getTwigs(){char buffer[4096];sprintf_s (buffer, "%s.twg",mName.c_str());return (const char*)buffer;}
	/*create bud swellings at the tips of branches and twigs*/
	BoolID getBuds(){char buffer[4096];sprintf_s (buffer, "%s.bud",mName.c_str());return (const char*)buffer;}
	/*create leaves on branches and twigs*/
	BoolID getLeaves(){char buffer[4096];sprintf_s (buffer, "%s.lvs",mName.c_str());return (const char*)buffer;}
	/*create flower petals on branches, twigs and buds*/
	BoolID getFlowers(){char buffer[4096];sprintf_s (buffer, "%s.flw",mName.c_str());return (const char*)buffer;}
	/*
	Method used for brushstamp rendering
	0 - Paint Brush
	1 - Smear Brush
	2 - Blur Brush
	3 - Erasor Brush
	4 - Thin Line Brush
	5 - Triangle Mesh Tube
	*/
	UnsignedintID getBrushType(){char buffer[4096];sprintf_s (buffer, "%s.brt",mName.c_str());return (const char*)buffer;}
	/*the worldspace width of the brushstroke*/
	DoubleID getBrushWidth(){char buffer[4096];sprintf_s (buffer, "%s.bwd",mName.c_str());return (const char*)buffer;}
	/*whether or not to make the line width constant for different depths from the view*/
	BoolID getScreenspaceWidth(){char buffer[4096];sprintf_s (buffer, "%s.spw",mName.c_str());return (const char*)buffer;}
	/*
	This controls the amount that the distance from
	the eye affects the tube width when screenSpace width
	is enabled. At a value of 0.0 the width is constant
	while at a value of 1.0 it behaves as if screenspace
	width is OFF.
	*/
	DoubleID getDistanceScaling(){char buffer[4096];sprintf_s (buffer, "%s.dsl",mName.c_str());return (const char*)buffer;}
	/*
	When screenspace width is enabled this controls
	the smallest width a stroke can be in pixels.
	It is useful for toon lines when one wishes to
	avoid very thin lines.
	*/
	DoubleID getMinPixelWidth(){char buffer[4096];sprintf_s (buffer, "%s.mpw",mName.c_str());return (const char*)buffer;}
	/*
	When screenspace width is enabled this controls
	the largest width a stroke can be in pixels.
	It is useful for toon lines when one wishes to
	avoid very fat lines.
	*/
	DoubleID getMaxPixelWidth(){char buffer[4096];sprintf_s (buffer, "%s.mxp",mName.c_str());return (const char*)buffer;}
	/*the spacing of stamps relative to brush width*/
	DoubleID getStampDensity(){char buffer[4096];sprintf_s (buffer, "%s.sdn",mName.c_str());return (const char*)buffer;}
	/*control for brush edge blurring*/
	DoubleID getSoftness(){char buffer[4096];sprintf_s (buffer, "%s.sft",mName.c_str());return (const char*)buffer;}
	/*
	<b>EdgeAntialias</b> determines whether or not to antialias brushstroke edges.
	Note that this does not affect paint or render speed and should be left
	on unless hard jagged edges are desired.
	*/
	BoolID getEdgeAntialias(){char buffer[4096];sprintf_s (buffer, "%s.eaa",mName.c_str());return (const char*)buffer;}
	/*
	<b>EdgeClip</b> allows one to make 3D strokes render as if
	they are painted directly onto a surface's texture.
	The edgeClipDepth attribute controls how far in front of a
	surface the stroke can be before it becomes invisible.
	Thus 3D strokes that sit close to an objects surface
	can be seen if the surface is behind them, but not if the
	surface edge is in profile.
	*/
	BoolID getEdgeClip(){char buffer[4096];sprintf_s (buffer, "%s.ecl",mName.c_str());return (const char*)buffer;}
	/*
	<b>EdgeClipDepth</b> controls how close an object behind a
	stroke must be in order for the stroke to be visible.
	*/
	DoubleID getEdgeClipDepth(){char buffer[4096];sprintf_s (buffer, "%s.ecd",mName.c_str());return (const char*)buffer;}
	/*
	<b>OcclusionWidthScale</b> scale stamp size down based on overlap
	by forground objects. The full stamp is always drawn, avoiding
	antialias problems where occluded by non-paint effects forground objects.
	The size of the stamp is reduced to zero (and thus hidden) when the
	entire stamp is occluded.
	*/
	BoolID getOcclusionWidthScale(){char buffer[4096];sprintf_s (buffer, "%s.ows",mName.c_str());return (const char*)buffer;}
	/*number of iterations of the blur filter each stamp*/
	IntID getBlurIntensity(){char buffer[4096];sprintf_s (buffer, "%s.bin",mName.c_str());return (const char*)buffer;}
	/*input color*/
	Float3ID getColor1(){char buffer[4096];sprintf_s (buffer, "%s.cl1",mName.c_str());return (const char*)buffer;}
	/*color1 Red value*/
	FloatID getColor1R(){char buffer[4096];sprintf_s (buffer, "%s.cl1.c1r",mName.c_str());return (const char*)buffer;}
	/*color1 Green value*/
	FloatID getColor1G(){char buffer[4096];sprintf_s (buffer, "%s.cl1.c1g",mName.c_str());return (const char*)buffer;}
	/*color1 Blue value*/
	FloatID getColor1B(){char buffer[4096];sprintf_s (buffer, "%s.cl1.c1b",mName.c_str());return (const char*)buffer;}
	/*input color for tube ends*/
	Float3ID getColor2(){char buffer[4096];sprintf_s (buffer, "%s.cl2",mName.c_str());return (const char*)buffer;}
	/*color2 Red value*/
	FloatID getColor2R(){char buffer[4096];sprintf_s (buffer, "%s.cl2.c2r",mName.c_str());return (const char*)buffer;}
	/*color2 Green value*/
	FloatID getColor2G(){char buffer[4096];sprintf_s (buffer, "%s.cl2.c2g",mName.c_str());return (const char*)buffer;}
	/*color2 Blue value*/
	FloatID getColor2B(){char buffer[4096];sprintf_s (buffer, "%s.cl2.c2b",mName.c_str());return (const char*)buffer;}
	/*input color transparency*/
	Float3ID getTransparency1(){char buffer[4096];sprintf_s (buffer, "%s.tn1",mName.c_str());return (const char*)buffer;}
	/*transparency1 Red value*/
	FloatID getTransparency1R(){char buffer[4096];sprintf_s (buffer, "%s.tn1.t1r",mName.c_str());return (const char*)buffer;}
	/*transparency1 Green value*/
	FloatID getTransparency1G(){char buffer[4096];sprintf_s (buffer, "%s.tn1.t1g",mName.c_str());return (const char*)buffer;}
	/*transparency1 Blue value*/
	FloatID getTransparency1B(){char buffer[4096];sprintf_s (buffer, "%s.tn1.t1b",mName.c_str());return (const char*)buffer;}
	/*input color transparency for tube end*/
	Float3ID getTransparency2(){char buffer[4096];sprintf_s (buffer, "%s.tn2",mName.c_str());return (const char*)buffer;}
	/*transparency2 Red value*/
	FloatID getTransparency2R(){char buffer[4096];sprintf_s (buffer, "%s.tn2.t2r",mName.c_str());return (const char*)buffer;}
	/*transparency2 Green value*/
	FloatID getTransparency2G(){char buffer[4096];sprintf_s (buffer, "%s.tn2.t2g",mName.c_str());return (const char*)buffer;}
	/*transparency2 Blue value*/
	FloatID getTransparency2B(){char buffer[4096];sprintf_s (buffer, "%s.tn2.t2b",mName.c_str());return (const char*)buffer;}
	/*input incandescence (color addition)*/
	Float3ID getIncandescence1(){char buffer[4096];sprintf_s (buffer, "%s.in1",mName.c_str());return (const char*)buffer;}
	/*incandescence1 Red value*/
	FloatID getIncandescence1R(){char buffer[4096];sprintf_s (buffer, "%s.in1.i1r",mName.c_str());return (const char*)buffer;}
	/*incandescence1 Green value*/
	FloatID getIncandescence1G(){char buffer[4096];sprintf_s (buffer, "%s.in1.i1g",mName.c_str());return (const char*)buffer;}
	/*incandescence1 Blue value*/
	FloatID getIncandescence1B(){char buffer[4096];sprintf_s (buffer, "%s.in1.i1b",mName.c_str());return (const char*)buffer;}
	/*input incandescence for tube end*/
	Float3ID getIncandescence2(){char buffer[4096];sprintf_s (buffer, "%s.in2",mName.c_str());return (const char*)buffer;}
	/*incandescence2 Red value*/
	FloatID getIncandescence2R(){char buffer[4096];sprintf_s (buffer, "%s.in2.i2r",mName.c_str());return (const char*)buffer;}
	/*incandescence2 Green value*/
	FloatID getIncandescence2G(){char buffer[4096];sprintf_s (buffer, "%s.in2.i2g",mName.c_str());return (const char*)buffer;}
	/*incandescence2 Blue value*/
	FloatID getIncandescence2B(){char buffer[4096];sprintf_s (buffer, "%s.in2.i2b",mName.c_str());return (const char*)buffer;}
	/*input color for specular highlights*/
	Float3ID getSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.spc",mName.c_str());return (const char*)buffer;}
	/*specular Red value*/
	FloatID getSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.spc.spr",mName.c_str());return (const char*)buffer;}
	/*specular Green value*/
	FloatID getSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.spc.spg",mName.c_str());return (const char*)buffer;}
	/*specular Blue value*/
	FloatID getSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.spc.spb",mName.c_str());return (const char*)buffer;}
	/*intensity of specular highlights*/
	DoubleID getSpecular(){char buffer[4096];sprintf_s (buffer, "%s.spe",mName.c_str());return (const char*)buffer;}
	/*focus or size of specular highlights*/
	DoubleID getSpecularPower(){char buffer[4096];sprintf_s (buffer, "%s.spp",mName.c_str());return (const char*)buffer;}
	/*blend factor between translucent and lambertian shading*/
	DoubleID getTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.trn",mName.c_str());return (const char*)buffer;}
	/*intensity of glow effect*/
	DoubleID getGlow(){char buffer[4096];sprintf_s (buffer, "%s.glw",mName.c_str());return (const char*)buffer;}
	/*input color for glow*/
	Float3ID getGlowColor(){char buffer[4096];sprintf_s (buffer, "%s.glc",mName.c_str());return (const char*)buffer;}
	/*glow Red value*/
	FloatID getGlowColorR(){char buffer[4096];sprintf_s (buffer, "%s.glc.glr",mName.c_str());return (const char*)buffer;}
	/*glow Green value*/
	FloatID getGlowColorG(){char buffer[4096];sprintf_s (buffer, "%s.glc.glg",mName.c_str());return (const char*)buffer;}
	/*glow Blue value*/
	FloatID getGlowColorB(){char buffer[4096];sprintf_s (buffer, "%s.glc.glb",mName.c_str());return (const char*)buffer;}
	/*amount to scale brush size by for glow stamp*/
	DoubleID getGlowSpread(){char buffer[4096];sprintf_s (buffer, "%s.gls",mName.c_str());return (const char*)buffer;}
	/*intensity of post render shaderglow effect*/
	DoubleID getShaderGlow(){char buffer[4096];sprintf_s (buffer, "%s.sgl",mName.c_str());return (const char*)buffer;}
	/*random deviation in hue of tubes*/
	DoubleID getHueRand(){char buffer[4096];sprintf_s (buffer, "%s.chr",mName.c_str());return (const char*)buffer;}
	/*random deviation in color saturation of tubes*/
	DoubleID getSatRand(){char buffer[4096];sprintf_s (buffer, "%s.csr",mName.c_str());return (const char*)buffer;}
	/*random deviation in brighness value of tubes*/
	DoubleID getValRand(){char buffer[4096];sprintf_s (buffer, "%s.cvr",mName.c_str());return (const char*)buffer;}
	/*distance from base of tube at which it becomes fully visible*/
	DoubleID getRootFade(){char buffer[4096];sprintf_s (buffer, "%s.rfd",mName.c_str());return (const char*)buffer;}
	/*distance from end of tube at which it becomes fully visible*/
	DoubleID getTipFade(){char buffer[4096];sprintf_s (buffer, "%s.tfd",mName.c_str());return (const char*)buffer;}
	/*
	create 3D surface shadow simulation or simple 2D dropshadow
	0 - none
	1 - 2D offset shadow
	2 - 3D simulated cast shadow
	*/
	UnsignedintID getFakeShadow(){char buffer[4096];sprintf_s (buffer, "%s.fks",mName.c_str());return (const char*)buffer;}
	/*2D drop shadow offset*/
	DoubleID getShadowOffset(){char buffer[4096];sprintf_s (buffer, "%s.sof",mName.c_str());return (const char*)buffer;}
	/*the softness of fake shadows*/
	DoubleID getShadowDiffusion(){char buffer[4096];sprintf_s (buffer, "%s.sdf",mName.c_str());return (const char*)buffer;}
	/*visibility of simulated shadows*/
	DoubleID getShadowTransparency(){char buffer[4096];sprintf_s (buffer, "%s.stn",mName.c_str());return (const char*)buffer;}
	/*shadow strokes on awayfacing side of parent surface*/
	DoubleID getBackShadow(){char buffer[4096];sprintf_s (buffer, "%s.bks",mName.c_str());return (const char*)buffer;}
	/*randomization of tube brightness*/
	DoubleID getBrightnessRand(){char buffer[4096];sprintf_s (buffer, "%s.brn",mName.c_str());return (const char*)buffer;}
	/*shadow from brushstamp center*/
	DoubleID getCenterShadow(){char buffer[4096];sprintf_s (buffer, "%s.cns",mName.c_str());return (const char*)buffer;}
	/*
	define shadow as depth from surface, or distance from path
	0 - Surface Depth
	1 - Path Dist
	*/
	UnsignedintID getDepthShadowType(){char buffer[4096];sprintf_s (buffer, "%s.dpt",mName.c_str());return (const char*)buffer;}
	/*darkness of the depth shadow*/
	DoubleID getDepthShadow(){char buffer[4096];sprintf_s (buffer, "%s.dpl",mName.c_str());return (const char*)buffer;}
	/*shadow offset distance*/
	DoubleID getDepthShadowDepth(){char buffer[4096];sprintf_s (buffer, "%s.dps",mName.c_str());return (const char*)buffer;}
	/*illuminate using light nodes*/
	BoolID getRealLights(){char buffer[4096];sprintf_s (buffer, "%s.rll",mName.c_str());return (const char*)buffer;}
	/*direction of simple directional lightsource*/
	Double3ID getLightDirection(){char buffer[4096];sprintf_s (buffer, "%s.ldr",mName.c_str());return (const char*)buffer;}
	/*X value for light direction*/
	DoubleID getLightDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.ldr.ldx",mName.c_str());return (const char*)buffer;}
	/*Y value for light direction*/
	DoubleID getLightDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.ldr.ldy",mName.c_str());return (const char*)buffer;}
	/*Z value for light direction*/
	DoubleID getLightDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.ldr.ldz",mName.c_str());return (const char*)buffer;}
	/*size of gaps relative to gapSpacing (1 = all hole)*/
	DoubleID getGapSize(){char buffer[4096];sprintf_s (buffer, "%s.gsz",mName.c_str());return (const char*)buffer;}
	/*separation of gaps along stroke*/
	DoubleID getGapSpacing(){char buffer[4096];sprintf_s (buffer, "%s.gsp",mName.c_str());return (const char*)buffer;}
	/*random offset along tubes for gaps*/
	DoubleID getGapRand(){char buffer[4096];sprintf_s (buffer, "%s.grn",mName.c_str());return (const char*)buffer;}
	/*speed of flow down brush path: affects gaps, twist and texture*/
	DoubleID getFlowSpeed(){char buffer[4096];sprintf_s (buffer, "%s.fws",mName.c_str());return (const char*)buffer;}
	/*
	move texture with flow defined by flowspeed. In general this
	is best turned off for growth animations, but is useful when
	one want a texture, particularily a displacement, to flow down
	the tubes.
	*/
	BoolID getTextureFlow(){char buffer[4096];sprintf_s (buffer, "%s.tfl",mName.c_str());return (const char*)buffer;}
	/*bound tubes with a start and end time( tube treated as a flow )*/
	BoolID getTimeClip(){char buffer[4096];sprintf_s (buffer, "%s.tcl",mName.c_str());return (const char*)buffer;}
	/*add in the path steps to time used for clipping.*/
	BoolID getStrokeTime(){char buffer[4096];sprintf_s (buffer, "%s.srm",mName.c_str());return (const char*)buffer;}
	/*start time bound for tubes and path*/
	DoubleID getStartTime(){char buffer[4096];sprintf_s (buffer, "%s.sti",mName.c_str());return (const char*)buffer;}
	/*end time bound for tubes and path*/
	DoubleID getEndTime(){char buffer[4096];sprintf_s (buffer, "%s.eti",mName.c_str());return (const char*)buffer;}
	/*generate dynamic tubes along path*/
	BoolID getTubes(){char buffer[4096];sprintf_s (buffer, "%s.tub",mName.c_str());return (const char*)buffer;}
	/*the name of a mel script to use for tube generation*/
	StringID getCreationScript(){char buffer[4096];sprintf_s (buffer, "%s.csc",mName.c_str());return (const char*)buffer;}
	/*
	the name of a mel script called at each step in the
	simulation to shape the flow and behavior of tubes
	*/
	StringID getRuntimeScript(){char buffer[4096];sprintf_s (buffer, "%s.rsc",mName.c_str());return (const char*)buffer;}
	/*run dynamic simulation until all tubes are at their final length*/
	BoolID getTubeCompletion(){char buffer[4096];sprintf_s (buffer, "%s.tcm",mName.c_str());return (const char*)buffer;}
	/*number of tubes generated for every new point along path*/
	DoubleID getTubesPerStep(){char buffer[4096];sprintf_s (buffer, "%s.tps",mName.c_str());return (const char*)buffer;}
	/*randomization of tube generation*/
	DoubleID getTubeRand(){char buffer[4096];sprintf_s (buffer, "%s.trd",mName.c_str());return (const char*)buffer;}
	/*number of tubes created at beginning of path*/
	IntID getStartTubes(){char buffer[4096];sprintf_s (buffer, "%s.stb",mName.c_str());return (const char*)buffer;}
	/*max tube length*/
	DoubleID getLengthMax(){char buffer[4096];sprintf_s (buffer, "%s.lnx",mName.c_str());return (const char*)buffer;}
	/*min tube length*/
	DoubleID getLengthMin(){char buffer[4096];sprintf_s (buffer, "%s.lnn",mName.c_str());return (const char*)buffer;}
	/*number of segments in full length tubes*/
	IntID getSegments(){char buffer[4096];sprintf_s (buffer, "%s.sgm",mName.c_str());return (const char*)buffer;}
	/*worldspace start width of tubes*/
	DoubleID getTubeWidth1(){char buffer[4096];sprintf_s (buffer, "%s.tw1",mName.c_str());return (const char*)buffer;}
	/*worldspace end width of tubes*/
	DoubleID getTubeWidth2(){char buffer[4096];sprintf_s (buffer, "%s.tw2",mName.c_str());return (const char*)buffer;}
	/*Randomization of tube start widths*/
	DoubleID getWidthRand(){char buffer[4096];sprintf_s (buffer, "%s.wdr",mName.c_str());return (const char*)buffer;}
	/*the proportion of large to small tubes*/
	DoubleID getWidthBias(){char buffer[4096];sprintf_s (buffer, "%s.wdb",mName.c_str());return (const char*)buffer;}
	/*the degree to which forces can stretch the tubes*/
	DoubleID getLengthFlex(){char buffer[4096];sprintf_s (buffer, "%s.lfx",mName.c_str());return (const char*)buffer;}
	/*the amount that segment lengths are smaller towards root or tip of tube*/
	DoubleID getSegmentLengthBias(){char buffer[4096];sprintf_s (buffer, "%s.sgb",mName.c_str());return (const char*)buffer;}
	/*the amount that segment lengths are proportional to the tube width*/
	DoubleID getSegmentWidthBias(){char buffer[4096];sprintf_s (buffer, "%s.swb",mName.c_str());return (const char*)buffer;}
	/*
	primary axis for generation of tubes ( direction if elevation = 0.0)
	0 - along surface or defined normal
	1 - along path of stroke
	*/
	UnsignedintID getTubeDirection(){char buffer[4096];sprintf_s (buffer, "%s.tdr",mName.c_str());return (const char*)buffer;}
	/*min elevation of tubes above stroke*/
	DoubleID getElevationMin(){char buffer[4096];sprintf_s (buffer, "%s.elm",mName.c_str());return (const char*)buffer;}
	/*max elevation of tubes above stroke*/
	DoubleID getElevationMax(){char buffer[4096];sprintf_s (buffer, "%s.elx",mName.c_str());return (const char*)buffer;}
	/*min angle of tubes with stroke direction*/
	DoubleID getAzimuthMin(){char buffer[4096];sprintf_s (buffer, "%s.azn",mName.c_str());return (const char*)buffer;}
	/*max angle of tubes with stroke direction*/
	DoubleID getAzimuthMax(){char buffer[4096];sprintf_s (buffer, "%s.azx",mName.c_str());return (const char*)buffer;}
	/*flatness of tube at base*/
	DoubleID getFlatness1(){char buffer[4096];sprintf_s (buffer, "%s.fl1",mName.c_str());return (const char*)buffer;}
	/*flatness of tube at tip*/
	DoubleID getFlatness2(){char buffer[4096];sprintf_s (buffer, "%s.fl2",mName.c_str());return (const char*)buffer;}
	/*start twist of tube*/
	DoubleID getTwist(){char buffer[4096];sprintf_s (buffer, "%s.twi",mName.c_str());return (const char*)buffer;}
	/*how much flat tubes twist along length like a streamer*/
	DoubleID getTwistRate(){char buffer[4096];sprintf_s (buffer, "%s.twr",mName.c_str());return (const char*)buffer;}
	/*randomization of twist when splitting*/
	DoubleID getTwistRand(){char buffer[4096];sprintf_s (buffer, "%s.twd",mName.c_str());return (const char*)buffer;}
	/*min amount of spiral about surface normal*/
	DoubleID getSpiralMin(){char buffer[4096];sprintf_s (buffer, "%s.spm",mName.c_str());return (const char*)buffer;}
	/*max amount of spiral about surface normal*/
	DoubleID getSpiralMax(){char buffer[4096];sprintf_s (buffer, "%s.spx",mName.c_str());return (const char*)buffer;}
	/*rate of change in spiral*/
	DoubleID getSpiralDecay(){char buffer[4096];sprintf_s (buffer, "%s.spd",mName.c_str());return (const char*)buffer;}
	/*
	amount of bend about the axis defined by the
	current twist.
	*/
	DoubleID getBend(){char buffer[4096];sprintf_s (buffer, "%s.ben",mName.c_str());return (const char*)buffer;}
	/*
	the relative strength of the bend from root to tip.
	High values cause a faster bending near the tip.
	*/
	DoubleID getBendBias(){char buffer[4096];sprintf_s (buffer, "%s.bnb",mName.c_str());return (const char*)buffer;}
	/*initial ramp up of displacement relative to max tube length*/
	DoubleID getDisplacementDelay(){char buffer[4096];sprintf_s (buffer, "%s.ddl",mName.c_str());return (const char*)buffer;}
	/*amount of wiggle tangent to stroke surface*/
	DoubleID getWiggle(){char buffer[4096];sprintf_s (buffer, "%s.wgl",mName.c_str());return (const char*)buffer;}
	/*wavelength for wiggle effect*/
	DoubleID getWiggleFrequency(){char buffer[4096];sprintf_s (buffer, "%s.wgf",mName.c_str());return (const char*)buffer;}
	/*translation of wiggle down tube path*/
	DoubleID getWiggleOffset(){char buffer[4096];sprintf_s (buffer, "%s.wgo",mName.c_str());return (const char*)buffer;}
	/*amount of curl about tube direction*/
	DoubleID getCurl(){char buffer[4096];sprintf_s (buffer, "%s.crl",mName.c_str());return (const char*)buffer;}
	/*rate of curl*/
	DoubleID getCurlFrequency(){char buffer[4096];sprintf_s (buffer, "%s.crf",mName.c_str());return (const char*)buffer;}
	/*translation of curl down tube*/
	DoubleID getCurlOffset(){char buffer[4096];sprintf_s (buffer, "%s.cro",mName.c_str());return (const char*)buffer;}
	/*amount of perlin noise offset in space*/
	DoubleID getNoise(){char buffer[4096];sprintf_s (buffer, "%s.noi",mName.c_str());return (const char*)buffer;}
	/*scale of the noise offset along tube*/
	DoubleID getNoiseFrequency(){char buffer[4096];sprintf_s (buffer, "%s.nof",mName.c_str());return (const char*)buffer;}
	/*translation of noise  down tube*/
	DoubleID getNoiseOffset(){char buffer[4096];sprintf_s (buffer, "%s.noo",mName.c_str());return (const char*)buffer;}
	/*the number of splits along a given tube*/
	DoubleID getSplitMaxDepth(){char buffer[4096];sprintf_s (buffer, "%s.smd",mName.c_str());return (const char*)buffer;}
	/*the randomness of the offset of split events along the tube*/
	DoubleID getSplitRand(){char buffer[4096];sprintf_s (buffer, "%s.srd",mName.c_str());return (const char*)buffer;}
	/*the angle with the new branches with respect to the base tube*/
	DoubleID getSplitAngle(){char buffer[4096];sprintf_s (buffer, "%s.spa",mName.c_str());return (const char*)buffer;}
	/*tubes are scaled by this factor at each split*/
	DoubleID getSplitSizeDecay(){char buffer[4096];sprintf_s (buffer, "%s.ssd",mName.c_str());return (const char*)buffer;}
	/*the degree to which splits happen nearer the tube base or tip*/
	DoubleID getSplitBias(){char buffer[4096];sprintf_s (buffer, "%s.slb",mName.c_str());return (const char*)buffer;}
	/*the amount of twist every branch event*/
	DoubleID getSplitTwist(){char buffer[4096];sprintf_s (buffer, "%s.slt",mName.c_str());return (const char*)buffer;}
	/*the initial number of child branches at tube origin*/
	DoubleID getStartBranches(){char buffer[4096];sprintf_s (buffer, "%s.sbr",mName.c_str());return (const char*)buffer;}
	/*the number of child branches per split*/
	IntID getNumBranches(){char buffer[4096];sprintf_s (buffer, "%s.nbr",mName.c_str());return (const char*)buffer;}
	/*the proportion of branches that are pruned*/
	DoubleID getBranchDropout(){char buffer[4096];sprintf_s (buffer, "%s.bdr",mName.c_str());return (const char*)buffer;}
	/*whether or not to keep the main trunk at split points*/
	BoolID getMiddleBranch(){char buffer[4096];sprintf_s (buffer, "%s.mbr",mName.c_str());return (const char*)buffer;}
	/*cutoff size when tube size is diminishing*/
	DoubleID getMinSize(){char buffer[4096];sprintf_s (buffer, "%s.mms",mName.c_str());return (const char*)buffer;}
	/*the amount tubes shapes match the shape of the path*/
	DoubleID getPathFollow(){char buffer[4096];sprintf_s (buffer, "%s.pfl",mName.c_str());return (const char*)buffer;}
	/*the path acts as a force*/
	DoubleID getPathAttract(){char buffer[4096];sprintf_s (buffer, "%s.pat",mName.c_str());return (const char*)buffer;}
	/*degree to which stroke shape matches input curve*/
	DoubleID getCurveFollow(){char buffer[4096];sprintf_s (buffer, "%s.cfw",mName.c_str());return (const char*)buffer;}
	/*input curve acts as a force*/
	DoubleID getCurveAttract(){char buffer[4096];sprintf_s (buffer, "%s.cva",mName.c_str());return (const char*)buffer;}
	/*max distance for influence of curves (0.0 = infinite)*/
	DoubleID getCurveMaxDist(){char buffer[4096];sprintf_s (buffer, "%s.cmd",mName.c_str());return (const char*)buffer;}
	/*worldspace directional force*/
	Double3ID getUniformForce(){char buffer[4096];sprintf_s (buffer, "%s.ufr",mName.c_str());return (const char*)buffer;}
	/*worldspace directional force X value*/
	DoubleID getUniformForceX(){char buffer[4096];sprintf_s (buffer, "%s.ufr.ufx",mName.c_str());return (const char*)buffer;}
	/*worldspace directional force Y value*/
	DoubleID getUniformForceY(){char buffer[4096];sprintf_s (buffer, "%s.ufr.ufy",mName.c_str());return (const char*)buffer;}
	/*worldspace directional force Z value*/
	DoubleID getUniformForceZ(){char buffer[4096];sprintf_s (buffer, "%s.ufr.ufz",mName.c_str());return (const char*)buffer;}
	/*
	use no turbulence, path relative, or worldspace turbulence
	0 - Off
	1 - Turbulence is a force in path space
	2 - Turbulence is a force in worldspace
	3 - Turbulence applied as localspace offset to tube
	4 - Turbulence applied as worldspace offset to tube
	*/
	UnsignedintID getTurbulenceType(){char buffer[4096];sprintf_s (buffer, "%s.trt",mName.c_str());return (const char*)buffer;}
	/*
	Interpolation method for values on the turbulence grid
	0 - Linear interpolation
	1 - Smooth interpolation(quadratic) over time only
	2 - Smooth interpolation(quadratic) over both time and space
	*/
	UnsignedintID getTurbulenceInterpolation(){char buffer[4096];sprintf_s (buffer, "%s.tin",mName.c_str());return (const char*)buffer;}
	/*level of animated wind turbulence that seamlessly loops in both space and time*/
	DoubleID getTurbulence(){char buffer[4096];sprintf_s (buffer, "%s.tur",mName.c_str());return (const char*)buffer;}
	/*this scales the turbulence spacially*/
	DoubleID getTurbulenceFrequency(){char buffer[4096];sprintf_s (buffer, "%s.trf",mName.c_str());return (const char*)buffer;}
	/*this scales the time value used for the turbulence function*/
	DoubleID getTurbulenceSpeed(){char buffer[4096];sprintf_s (buffer, "%s.trs",mName.c_str());return (const char*)buffer;}
	/*xyz translation of turbulence*/
	Double3ID getTurbulenceOffset(){char buffer[4096];sprintf_s (buffer, "%s.tro",mName.c_str());return (const char*)buffer;}
	/*turbulence translation in X*/
	DoubleID getTurbulenceOffsetX(){char buffer[4096];sprintf_s (buffer, "%s.tro.trx",mName.c_str());return (const char*)buffer;}
	/*turbulence translation in Y*/
	DoubleID getTurbulenceOffsetY(){char buffer[4096];sprintf_s (buffer, "%s.tro.try",mName.c_str());return (const char*)buffer;}
	/*turbulence translation in Z*/
	DoubleID getTurbulenceOffsetZ(){char buffer[4096];sprintf_s (buffer, "%s.tro.trz",mName.c_str());return (const char*)buffer;}
	/*local force with random direction and intensity*/
	DoubleID getRandom(){char buffer[4096];sprintf_s (buffer, "%s.ran",mName.c_str());return (const char*)buffer;}
	/*vertical worldspace force*/
	DoubleID getGravity(){char buffer[4096];sprintf_s (buffer, "%s.grv",mName.c_str());return (const char*)buffer;}
	/*The particle velocity is scaled by this factor at each simulation step.*/
	DoubleID getMomentum(){char buffer[4096];sprintf_s (buffer, "%s.mmt",mName.c_str());return (const char*)buffer;}
	/*Fake surface collision using repulsive force*/
	BoolID getDeflection(){char buffer[4096];sprintf_s (buffer, "%s.def",mName.c_str());return (const char*)buffer;}
	/*offset for where the surface is presumed to be*/
	DoubleID getDeflectionMin(){char buffer[4096];sprintf_s (buffer, "%s.dfm",mName.c_str());return (const char*)buffer;}
	/*distance from surface at which deflection field fades to zero*/
	DoubleID getDeflectionMax(){char buffer[4096];sprintf_s (buffer, "%s.dfx",mName.c_str());return (const char*)buffer;}
	/*number of twigs created at life end*/
	IntID getTwigsInCluster(){char buffer[4096];sprintf_s (buffer, "%s.tic",mName.c_str());return (const char*)buffer;}
	/*rate of omitted twigs*/
	DoubleID getTwigDropout(){char buffer[4096];sprintf_s (buffer, "%s.tdp",mName.c_str());return (const char*)buffer;}
	/*start angle of twig with branch*/
	DoubleID getTwigAngle1(){char buffer[4096];sprintf_s (buffer, "%s.ta1",mName.c_str());return (const char*)buffer;}
	/*end angle of twig with branch*/
	DoubleID getTwigAngle2(){char buffer[4096];sprintf_s (buffer, "%s.ta2",mName.c_str());return (const char*)buffer;}
	/*rate of twist about branch per twig*/
	DoubleID getTwigTwist(){char buffer[4096];sprintf_s (buffer, "%s.ttw",mName.c_str());return (const char*)buffer;}
	/*length of twig stroke*/
	DoubleID getTwigLength(){char buffer[4096];sprintf_s (buffer, "%s.twl",mName.c_str());return (const char*)buffer;}
	/*point along branch where twigs start*/
	DoubleID getTwigStart(){char buffer[4096];sprintf_s (buffer, "%s.tst",mName.c_str());return (const char*)buffer;}
	/*total number of twig sprouts created between twig Start and branch tip*/
	DoubleID getNumTwigClusters(){char buffer[4096];sprintf_s (buffer, "%s.ntc",mName.c_str());return (const char*)buffer;}
	/*start size for twig stroke*/
	DoubleID getTwigBaseWidth(){char buffer[4096];sprintf_s (buffer, "%s.twb",mName.c_str());return (const char*)buffer;}
	/*end size for twig stroke*/
	DoubleID getTwigTipWidth(){char buffer[4096];sprintf_s (buffer, "%s.twt",mName.c_str());return (const char*)buffer;}
	/*
	how much twigs are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	DoubleID getTwigStiffness(){char buffer[4096];sprintf_s (buffer, "%s.tgs",mName.c_str());return (const char*)buffer;}
	/*put branches on twigs rather than twigs on branches*/
	BoolID getBranchAfterTwigs(){char buffer[4096];sprintf_s (buffer, "%s.bat",mName.c_str());return (const char*)buffer;}
	/*number of leaves created at each sprout*/
	IntID getLeavesInCluster(){char buffer[4096];sprintf_s (buffer, "%s.lic",mName.c_str());return (const char*)buffer;}
	/*
	This determines which components may sprout leaves.
	0 - On All
	1 - On Secondary Branches Only
	2 - On Twigs Only
	*/
	UnsignedintID getLeafLocation(){char buffer[4096];sprintf_s (buffer, "%s.llo",mName.c_str());return (const char*)buffer;}
	/*rate of omitted leaves*/
	DoubleID getLeafDropout(){char buffer[4096];sprintf_s (buffer, "%s.ldp",mName.c_str());return (const char*)buffer;}
	/*angle of leaf with branch at leafStart*/
	DoubleID getLeafAngle1(){char buffer[4096];sprintf_s (buffer, "%s.ll1",mName.c_str());return (const char*)buffer;}
	/*angle of leaf with branch at branch tip*/
	DoubleID getLeafAngle2(){char buffer[4096];sprintf_s (buffer, "%s.ll2",mName.c_str());return (const char*)buffer;}
	/*rate of twist about branch per leaf*/
	DoubleID getLeafTwist(){char buffer[4096];sprintf_s (buffer, "%s.ltw",mName.c_str());return (const char*)buffer;}
	/*
	amount of bend about the axis defined by the
	current twist of the leaf. This can be used to make
	a leaf roll up, or provide better shaping of the
	general curl of the leaf.
	*/
	DoubleID getLeafBend(){char buffer[4096];sprintf_s (buffer, "%s.lbn",mName.c_str());return (const char*)buffer;}
	/*
	amount of curl away from the primary axis of the leaf.
	This is perpendicular to the leaf bend direction.
	This can both provide a more natural leaf shape and help
	create a more rounded shading when the flatness is 1.0.
	The left side of the ramp represents curl at the leaf
	base and the right side is the leaf tip.
	*/
	const LeafCurlID& getLeafCurl(size_t lcl_i){char buffer[4096];sprintf_s (buffer, "%s.lcl[%i]",mName.c_str(),lcl_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getLeafCurl_Position(size_t lcl_i){char buffer[4096];sprintf_s (buffer, "%s.lcl[%i].lclp",mName.c_str(),lcl_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getLeafCurl_FloatValue(size_t lcl_i){char buffer[4096];sprintf_s (buffer, "%s.lcl[%i].lclfv",mName.c_str(),lcl_i);return (const char*)buffer;}
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
	const UnsignedintID& getLeafCurl_Interp(size_t lcl_i){char buffer[4096];sprintf_s (buffer, "%s.lcl[%i].lcli",mName.c_str(),lcl_i);return (const char*)buffer;}
	/*
	amount of rotation or twist of the leaf about its primary axis.
	This can be used to make leaves better face a certain
	direction.
	*/
	DoubleID getLeafTwirl(){char buffer[4096];sprintf_s (buffer, "%s.ltwl",mName.c_str());return (const char*)buffer;}
	/*number of segments in leaf stroke*/
	IntID getLeafSegments(){char buffer[4096];sprintf_s (buffer, "%s.lsg",mName.c_str());return (const char*)buffer;}
	/*point along branch where leaves start*/
	DoubleID getLeafStart(){char buffer[4096];sprintf_s (buffer, "%s.lst",mName.c_str());return (const char*)buffer;}
	/*total number of leaf sprouts created between Leaf Start and branch tip*/
	DoubleID getNumLeafClusters(){char buffer[4096];sprintf_s (buffer, "%s.nlc",mName.c_str());return (const char*)buffer;}
	/*flatness to use for the leaf stroke*/
	DoubleID getLeafFlatness(){char buffer[4096];sprintf_s (buffer, "%s.lft",mName.c_str());return (const char*)buffer;}
	/*length scale for leaf stroke*/
	DoubleID getLeafLength(){char buffer[4096];sprintf_s (buffer, "%s.lln",mName.c_str());return (const char*)buffer;}
	/*width at base of leaf stroke*/
	DoubleID getLeafBaseWidth(){char buffer[4096];sprintf_s (buffer, "%s.leb",mName.c_str());return (const char*)buffer;}
	/*width at tip of leaf stroke*/
	DoubleID getLeafTipWidth(){char buffer[4096];sprintf_s (buffer, "%s.let",mName.c_str());return (const char*)buffer;}
	/*scale factor for leaves at branch tip*/
	DoubleID getLeafSizeDecay(){char buffer[4096];sprintf_s (buffer, "%s.lsd",mName.c_str());return (const char*)buffer;}
	/*blend factor between translucent and lambertian shading for leaves*/
	DoubleID getLeafTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.ltr",mName.c_str());return (const char*)buffer;}
	/*intensity of specular highlights on leaves*/
	DoubleID getLeafSpecular(){char buffer[4096];sprintf_s (buffer, "%s.lsp",mName.c_str());return (const char*)buffer;}
	/*whether or not to add a single leaf at the very end of the branch*/
	BoolID getTerminalLeaf(){char buffer[4096];sprintf_s (buffer, "%s.tml",mName.c_str());return (const char*)buffer;}
	/*start color for leaf*/
	Float3ID getLeafColor1(){char buffer[4096];sprintf_s (buffer, "%s.lc1",mName.c_str());return (const char*)buffer;}
	/*leaf start Red value*/
	FloatID getLeafColor1R(){char buffer[4096];sprintf_s (buffer, "%s.lc1.lr1",mName.c_str());return (const char*)buffer;}
	/*leaf start Green value*/
	FloatID getLeafColor1G(){char buffer[4096];sprintf_s (buffer, "%s.lc1.lg1",mName.c_str());return (const char*)buffer;}
	/*leaf start Blue value*/
	FloatID getLeafColor1B(){char buffer[4096];sprintf_s (buffer, "%s.lc1.lb1",mName.c_str());return (const char*)buffer;}
	/*start color for leaf*/
	Float3ID getLeafColor2(){char buffer[4096];sprintf_s (buffer, "%s.lc2",mName.c_str());return (const char*)buffer;}
	/*leaf end Red value*/
	FloatID getLeafColor2R(){char buffer[4096];sprintf_s (buffer, "%s.lc2.lr2",mName.c_str());return (const char*)buffer;}
	/*leaf end Green value*/
	FloatID getLeafColor2G(){char buffer[4096];sprintf_s (buffer, "%s.lc2.lg2",mName.c_str());return (const char*)buffer;}
	/*leaf end Blue value*/
	FloatID getLeafColor2B(){char buffer[4096];sprintf_s (buffer, "%s.lc2.lb2",mName.c_str());return (const char*)buffer;}
	/*random deviation in hue of leaves*/
	DoubleID getLeafHueRand(){char buffer[4096];sprintf_s (buffer, "%s.lhr",mName.c_str());return (const char*)buffer;}
	/*random deviation in color saturation of leaves*/
	DoubleID getLeafSatRand(){char buffer[4096];sprintf_s (buffer, "%s.lsr",mName.c_str());return (const char*)buffer;}
	/*random deviation in brighness value of leaves*/
	DoubleID getLeafValRand(){char buffer[4096];sprintf_s (buffer, "%s.lvr",mName.c_str());return (const char*)buffer;}
	/*whether or not to use the main texture applied to branches*/
	BoolID getLeafUseBranchTex(){char buffer[4096];sprintf_s (buffer, "%s.lub",mName.c_str());return (const char*)buffer;}
	/*the name of an image file to use for leaf strokes*/
	StringID getLeafImage(){char buffer[4096];sprintf_s (buffer, "%s.lim",mName.c_str());return (const char*)buffer;}
	/*
	how much leaves are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	DoubleID getLeafStiffness(){char buffer[4096];sprintf_s (buffer, "%s.lfs",mName.c_str());return (const char*)buffer;}
	/*size of bud swelling at branch tip*/
	DoubleID getBudSize(){char buffer[4096];sprintf_s (buffer, "%s.bds",mName.c_str());return (const char*)buffer;}
	/*color of bud at branch tip*/
	Float3ID getBudColor(){char buffer[4096];sprintf_s (buffer, "%s.bcr",mName.c_str());return (const char*)buffer;}
	/*bud Red value*/
	FloatID getBudColorR(){char buffer[4096];sprintf_s (buffer, "%s.bcr.bur",mName.c_str());return (const char*)buffer;}
	/*bud Green value*/
	FloatID getBudColorG(){char buffer[4096];sprintf_s (buffer, "%s.bcr.bug",mName.c_str());return (const char*)buffer;}
	/*bud Blue value*/
	FloatID getBudColorB(){char buffer[4096];sprintf_s (buffer, "%s.bcr.bub",mName.c_str());return (const char*)buffer;}
	/*number of flowers created at life end*/
	IntID getPetalsInFlower(){char buffer[4096];sprintf_s (buffer, "%s.pif",mName.c_str());return (const char*)buffer;}
	/*
	This determines which components may sprout flowers.
	0 - On All
	1 - On Secondary Branches Only
	2 - On Twigs Only
	*/
	UnsignedintID getFlowerLocation(){char buffer[4096];sprintf_s (buffer, "%s.flc",mName.c_str());return (const char*)buffer;}
	/*rate of omitted flowers*/
	DoubleID getPetalDropout(){char buffer[4096];sprintf_s (buffer, "%s.pdp",mName.c_str());return (const char*)buffer;}
	/*angle of flower with branch at flowerStart*/
	DoubleID getFlowerAngle1(){char buffer[4096];sprintf_s (buffer, "%s.fw1",mName.c_str());return (const char*)buffer;}
	/*angle of flower with branch at branch tip*/
	DoubleID getFlowerAngle2(){char buffer[4096];sprintf_s (buffer, "%s.fw2",mName.c_str());return (const char*)buffer;}
	/*rate of twist about branch per flower*/
	DoubleID getFlowerTwist(){char buffer[4096];sprintf_s (buffer, "%s.ftw",mName.c_str());return (const char*)buffer;}
	/*
	amount of bend about the axis defined by the
	current twist of the petal. This can be used to make
	a petal curl up, or provide better shaping of the petal.
	*/
	DoubleID getPetalBend(){char buffer[4096];sprintf_s (buffer, "%s.pbn",mName.c_str());return (const char*)buffer;}
	/*
	amount of curl away from the primary axis of the petal.
	This is perpendicular to the petal bend direction.
	This can provide a more natural petal shape and help avoid
	interpenetration with neighboring petals.
	The left side of the ramp represents curl at the petal
	base and the right side is the petal tip.
	*/
	const PetalCurlID& getPetalCurl(size_t pcl_i){char buffer[4096];sprintf_s (buffer, "%s.pcl[%i]",mName.c_str(),pcl_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getPetalCurl_Position(size_t pcl_i){char buffer[4096];sprintf_s (buffer, "%s.pcl[%i].pclp",mName.c_str(),pcl_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getPetalCurl_FloatValue(size_t pcl_i){char buffer[4096];sprintf_s (buffer, "%s.pcl[%i].pclfv",mName.c_str(),pcl_i);return (const char*)buffer;}
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
	const UnsignedintID& getPetalCurl_Interp(size_t pcl_i){char buffer[4096];sprintf_s (buffer, "%s.pcl[%i].pcli",mName.c_str(),pcl_i);return (const char*)buffer;}
	/*
	amount of rotation or twist of the petal about its primary axis.
	This can be used to make petals better face a certain
	direction, or to twist a bit so as not to self
	intersect when forming a flower.
	*/
	DoubleID getPetalTwirl(){char buffer[4096];sprintf_s (buffer, "%s.lpwl",mName.c_str());return (const char*)buffer;}
	/*number of segments in flower stroke*/
	IntID getPetalSegments(){char buffer[4096];sprintf_s (buffer, "%s.psg",mName.c_str());return (const char*)buffer;}
	/*point along branch where flowers start*/
	DoubleID getFlowerStart(){char buffer[4096];sprintf_s (buffer, "%s.fst",mName.c_str());return (const char*)buffer;}
	/*total number of petal groups created between flower Start and branch tip*/
	DoubleID getNumFlowers(){char buffer[4096];sprintf_s (buffer, "%s.nfl",mName.c_str());return (const char*)buffer;}
	/*flatness to use for the flower stroke*/
	DoubleID getPetalFlatness(){char buffer[4096];sprintf_s (buffer, "%s.pft",mName.c_str());return (const char*)buffer;}
	/*length scale for flower stroke*/
	DoubleID getPetalLength(){char buffer[4096];sprintf_s (buffer, "%s.pln",mName.c_str());return (const char*)buffer;}
	/*width at base of flower petals*/
	DoubleID getPetalBaseWidth(){char buffer[4096];sprintf_s (buffer, "%s.ptb",mName.c_str());return (const char*)buffer;}
	/*width at tip of flower petals*/
	DoubleID getPetalTipWidth(){char buffer[4096];sprintf_s (buffer, "%s.ptt",mName.c_str());return (const char*)buffer;}
	/*scale factor for flowers at branch tip*/
	DoubleID getFlowerSizeDecay(){char buffer[4096];sprintf_s (buffer, "%s.fsd",mName.c_str());return (const char*)buffer;}
	/*blend factor between translucent and lambertian shading for flowers*/
	DoubleID getFlowerTranslucence(){char buffer[4096];sprintf_s (buffer, "%s.ftr",mName.c_str());return (const char*)buffer;}
	/*intensity of specular highlights on flowers*/
	DoubleID getFlowerSpecular(){char buffer[4096];sprintf_s (buffer, "%s.fsp",mName.c_str());return (const char*)buffer;}
	/*start color for flower*/
	Float3ID getPetalColor1(){char buffer[4096];sprintf_s (buffer, "%s.pc1",mName.c_str());return (const char*)buffer;}
	/*flower start Red value*/
	FloatID getPetalColor1R(){char buffer[4096];sprintf_s (buffer, "%s.pc1.pr1",mName.c_str());return (const char*)buffer;}
	/*flower start Green value*/
	FloatID getPetalColor1G(){char buffer[4096];sprintf_s (buffer, "%s.pc1.pg1",mName.c_str());return (const char*)buffer;}
	/*flower start Blue value*/
	FloatID getPetalColor1B(){char buffer[4096];sprintf_s (buffer, "%s.pc1.pb1",mName.c_str());return (const char*)buffer;}
	/*start color for flower*/
	Float3ID getPetalColor2(){char buffer[4096];sprintf_s (buffer, "%s.pc2",mName.c_str());return (const char*)buffer;}
	/*flower end Red value*/
	FloatID getPetalColor2R(){char buffer[4096];sprintf_s (buffer, "%s.pc2.pr2",mName.c_str());return (const char*)buffer;}
	/*flower end Green value*/
	FloatID getPetalColor2G(){char buffer[4096];sprintf_s (buffer, "%s.pc2.pg2",mName.c_str());return (const char*)buffer;}
	/*flower end Blue value*/
	FloatID getPetalColor2B(){char buffer[4096];sprintf_s (buffer, "%s.pc2.pb2",mName.c_str());return (const char*)buffer;}
	/*random deviation in hue of flowers*/
	DoubleID getFlowerHueRand(){char buffer[4096];sprintf_s (buffer, "%s.fhr",mName.c_str());return (const char*)buffer;}
	/*random deviation in color saturation of flowers*/
	DoubleID getFlowerSatRand(){char buffer[4096];sprintf_s (buffer, "%s.fsr",mName.c_str());return (const char*)buffer;}
	/*random deviation in brightness value of flowers*/
	DoubleID getFlowerValRand(){char buffer[4096];sprintf_s (buffer, "%s.fvr",mName.c_str());return (const char*)buffer;}
	/*whether or not to use the main texture applied to branches*/
	BoolID getFlowerUseBranchTex(){char buffer[4096];sprintf_s (buffer, "%s.fub",mName.c_str());return (const char*)buffer;}
	/*the name of an image file to use for flower petals*/
	StringID getFlowerImage(){char buffer[4096];sprintf_s (buffer, "%s.fim",mName.c_str());return (const char*)buffer;}
	/*
	how much flowers are affected by forces such as
	turbulence, gravity, random and spiral. At a value of
	one these brush forces will not have an effect.
	*/
	DoubleID getFlowerStiffness(){char buffer[4096];sprintf_s (buffer, "%s.fls",mName.c_str());return (const char*)buffer;}
	/*
	method used to simplify the wireframe draw in conjunction with the stroke display quality setting
	0 - stroke quality only affects the number of tubes
	1 - stroke quality only affects the number of segments along tubes
	2 - stroke quality affects the number of tubes and the number of segments
	*/
	UnsignedintID getSimplifyMethod(){char buffer[4096];sprintf_s (buffer, "%s.smp",mName.c_str());return (const char*)buffer;}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	UnsignedintID getColorLengthMap(){char buffer[4096];sprintf_s (buffer, "%s.clm",mName.c_str());return (const char*)buffer;}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	UnsignedintID getTranspLengthMap(){char buffer[4096];sprintf_s (buffer, "%s.tlm",mName.c_str());return (const char*)buffer;}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	UnsignedintID getIncandLengthMap(){char buffer[4096];sprintf_s (buffer, "%s.ilm",mName.c_str());return (const char*)buffer;}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	UnsignedintID getWidthLengthMap(){char buffer[4096];sprintf_s (buffer, "%s.wlm",mName.c_str());return (const char*)buffer;}
	/*
	define the method used to map against tube length
	0 - Length Relative
	1 - Max Length Relative
	*/
	UnsignedintID getSplitLengthMap(){char buffer[4096];sprintf_s (buffer, "%s.spl",mName.c_str());return (const char*)buffer;}
	/*Texture color using the current texture*/
	BoolID getMapColor(){char buffer[4096];sprintf_s (buffer, "%s.mcl",mName.c_str());return (const char*)buffer;}
	/*Texture opacity using the current texture*/
	BoolID getMapOpacity(){char buffer[4096];sprintf_s (buffer, "%s.mop",mName.c_str());return (const char*)buffer;}
	/*Texture displacement using the current texture*/
	BoolID getMapDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.mds",mName.c_str());return (const char*)buffer;}
	/*
	define the current texture method
	0 - Checker
	1 - U Ramp
	2 - V Ramp
	3 - Fractal
	4 - File
	*/
	UnsignedintID getTextureType(){char buffer[4096];sprintf_s (buffer, "%s.txt",mName.c_str());return (const char*)buffer;}
	/*
	0 - the texture is fit to the view
	1 - the mapping is in eyespace but scaled and offset based on the
	start of the brushstroke or tube
	2 - the mapping is in worldspace but always centered on the tube, such
	that there never a visible seam.
	3 - the texture is fully mapped in 3D around the tube, with a seam
	that is visible from some views. The texture appears correct when
	the viewpoint is animated.
	*/
	UnsignedintID getMapMethod(){char buffer[4096];sprintf_s (buffer, "%s.mmd",mName.c_str());return (const char*)buffer;}
	/*The amount the texture's color is multiplied by the non-textured color.*/
	DoubleID getTexColorScale(){char buffer[4096];sprintf_s (buffer, "%s.tcs",mName.c_str());return (const char*)buffer;}
	/*The amount the texture's color is added into the output color*/
	DoubleID getTexColorOffset(){char buffer[4096];sprintf_s (buffer, "%s.tco",mName.c_str());return (const char*)buffer;}
	/*The amount the texture's alpha multiplies the opacity.*/
	DoubleID getTexOpacityScale(){char buffer[4096];sprintf_s (buffer, "%s.tos",mName.c_str());return (const char*)buffer;}
	/*The amount the texture's alpha is added into the output opacity*/
	DoubleID getTexOpacityOffset(){char buffer[4096];sprintf_s (buffer, "%s.too",mName.c_str());return (const char*)buffer;}
	/*
	The amount the texture's alpha is used to scale ( or
	multiply ) the tube width. Thus this form of
	displacement is relative to the width of tubes.
	*/
	DoubleID getDisplacementScale(){char buffer[4096];sprintf_s (buffer, "%s.dsc",mName.c_str());return (const char*)buffer;}
	/*
	The amount the texture's alpha is added to the tube width.
	This displacement is independent of tube width, so
	thin tubes may have more displacement than desired.
	*/
	DoubleID getDisplacementOffset(){char buffer[4096];sprintf_s (buffer, "%s.dof",mName.c_str());return (const char*)buffer;}
	/*
	The amount of bump added relative to the general displacement.
	The bump provides needed detail when displaced
	triangles are large relative to a pixel.
	Note that bump mapping requires
	both that displacement is on and perPixel
	mesh shading is used. If one wishes to have only the
	bump with no displacement, then make the displacement
	scale and offset zero.
	*/
	DoubleID getBumpIntensity(){char buffer[4096];sprintf_s (buffer, "%s.bmi",mName.c_str());return (const char*)buffer;}
	/*
	This scales the separation of the extra texture
	samples used in computing the bump map. It has the
	effect of making the bump smoother and less detailed.
	If it is too low, however, the bump may appear broken
	up and may jitter in animations. A value of 1.0 avoids
	most of these jitter or aliasing problems, but
	results in too smooth a bump for distant
	or oblique strokes. In practice a value of 0.5
	can be a good compromise.
	*/
	DoubleID getBumpBlur(){char buffer[4096];sprintf_s (buffer, "%s.bbl",mName.c_str());return (const char*)buffer;}
	/*
	In particular one may wish to use the color from file
	textures for displacement instead of the image alpha.
	This also frees the alpha for use in transparency.
	This uses the brighness of the color for displacement.
	*/
	BoolID getLuminanceIsDisplacement(){char buffer[4096];sprintf_s (buffer, "%s.lid",mName.c_str());return (const char*)buffer;}
	/*color for min texture values*/
	Float3ID getTexColor1(){char buffer[4096];sprintf_s (buffer, "%s.tc1",mName.c_str());return (const char*)buffer;}
	/*texColor1 Red value*/
	FloatID getTexColor1R(){char buffer[4096];sprintf_s (buffer, "%s.tc1.x1r",mName.c_str());return (const char*)buffer;}
	/*texColor1 Green value*/
	FloatID getTexColor1G(){char buffer[4096];sprintf_s (buffer, "%s.tc1.x1g",mName.c_str());return (const char*)buffer;}
	/*texColor1 Blue value*/
	FloatID getTexColor1B(){char buffer[4096];sprintf_s (buffer, "%s.tc1.x1b",mName.c_str());return (const char*)buffer;}
	/*color for min texture values*/
	Float3ID getTexColor2(){char buffer[4096];sprintf_s (buffer, "%s.tc2",mName.c_str());return (const char*)buffer;}
	/*texColor2 Red value*/
	FloatID getTexColor2R(){char buffer[4096];sprintf_s (buffer, "%s.tc2.x2r",mName.c_str());return (const char*)buffer;}
	/*texColor2 Green value*/
	FloatID getTexColor2G(){char buffer[4096];sprintf_s (buffer, "%s.tc2.x2g",mName.c_str());return (const char*)buffer;}
	/*texColor2 Blue value*/
	FloatID getTexColor2B(){char buffer[4096];sprintf_s (buffer, "%s.tc2.x2b",mName.c_str());return (const char*)buffer;}
	/*Alpha (opacity) for max texture values.*/
	DoubleID getTexAlpha1(){char buffer[4096];sprintf_s (buffer, "%s.al1",mName.c_str());return (const char*)buffer;}
	/*Alpha (opacity) for min texture values.*/
	DoubleID getTexAlpha2(){char buffer[4096];sprintf_s (buffer, "%s.al2",mName.c_str());return (const char*)buffer;}
	/*Degree to which Uvalue along stroke is in worldspace*/
	DoubleID getTexUniformity(){char buffer[4096];sprintf_s (buffer, "%s.txu",mName.c_str());return (const char*)buffer;}
	/*
	Correct for dark fringes along file texture alpha boundaries.
	The file texture's color is premultiplied by 1/alpha.
	*/
	BoolID getFringeRemoval(){char buffer[4096];sprintf_s (buffer, "%s.frm",mName.c_str());return (const char*)buffer;}
	/*repeat of texture in U dimension*/
	DoubleID getRepeatU(){char buffer[4096];sprintf_s (buffer, "%s.rpu",mName.c_str());return (const char*)buffer;}
	/*repeat of texture in V dimension*/
	DoubleID getRepeatV(){char buffer[4096];sprintf_s (buffer, "%s.rpv",mName.c_str());return (const char*)buffer;}
	/*translate of texture along U*/
	DoubleID getOffsetU(){char buffer[4096];sprintf_s (buffer, "%s.ofu",mName.c_str());return (const char*)buffer;}
	/*translate of texture along V*/
	DoubleID getOffsetV(){char buffer[4096];sprintf_s (buffer, "%s.ofv",mName.c_str());return (const char*)buffer;}
	/*blurring of texture(needed for antialiasing )*/
	DoubleID getBlurMult(){char buffer[4096];sprintf_s (buffer, "%s.bmt",mName.c_str());return (const char*)buffer;}
	/*scale of 2Dnoise used for smear effect*/
	DoubleID getSmear(){char buffer[4096];sprintf_s (buffer, "%s.smr",mName.c_str());return (const char*)buffer;}
	/*smear offset intensity in U*/
	DoubleID getSmearU(){char buffer[4096];sprintf_s (buffer, "%s.sru",mName.c_str());return (const char*)buffer;}
	/*smear offset intensity in V*/
	DoubleID getSmearV(){char buffer[4096];sprintf_s (buffer, "%s.srv",mName.c_str());return (const char*)buffer;}
	/*the name of an image file to use for file texture type*/
	StringID getImageName(){char buffer[4096];sprintf_s (buffer, "%s.imn",mName.c_str());return (const char*)buffer;}
	/*
	When <b>Use Frame Extension</b> is on, the frame
	number in the file name will be replaced with the number
	specified in the Frame Extension attribute.  Use this when
	you want to animate the texture.
	*/
	BoolID getUseFrameExtension(){char buffer[4096];sprintf_s (buffer, "%s.ufe",mName.c_str());return (const char*)buffer;}
	/*
	<b>Frame Extension</b> replaces the frame extension number
	in the file name (if there is one).  This attribute is only
	meaningful if Use FrameExtension is turned on.
	<p/>
	Keyframe this attribute when you want to use a sequence of files
	as a file texture.
	*/
	IntID getFrameExtension(){char buffer[4096];sprintf_s (buffer, "%s.fe",mName.c_str());return (const char*)buffer;}
	/*the roughness of the fractal*/
	DoubleID getFractalRatio(){char buffer[4096];sprintf_s (buffer, "%s.fra",mName.c_str());return (const char*)buffer;}
	/*the intensity or contrast of the fractal*/
	DoubleID getFractalAmplitude(){char buffer[4096];sprintf_s (buffer, "%s.fam",mName.c_str());return (const char*)buffer;}
	/*a cutoff value*/
	DoubleID getFractalThreshold(){char buffer[4096];sprintf_s (buffer, "%s.fth",mName.c_str());return (const char*)buffer;}
	/*
	<b>Multi Streaks</b> is the number of added tubes. These tubes
	will share the same shading as the base tube they are
	derived from. They are created at render time and are simple duplicates,
	and thus do not take up any shape computation. This allows one to have a
	great number of tubes and yet render them in a reasonable amount of time.
	*/
	IntID getMultiStreaks(){char buffer[4096];sprintf_s (buffer, "%s.mst",mName.c_str());return (const char*)buffer;}
	/*the maximum offset for added tubes relative to the brush width at the tube base*/
	DoubleID getMultiStreakSpread1(){char buffer[4096];sprintf_s (buffer, "%s.ms1",mName.c_str());return (const char*)buffer;}
	/*the maximum offset for added tubes relative to the brush width at the tube tip*/
	DoubleID getMultiStreakSpread2(){char buffer[4096];sprintf_s (buffer, "%s.ms2",mName.c_str());return (const char*)buffer;}
	/*a diffuse brightness randomization for the added tubes*/
	DoubleID getMultiStreakDiffuseRand(){char buffer[4096];sprintf_s (buffer, "%s.msdr",mName.c_str());return (const char*)buffer;}
	/*a specular brightness randomization for the added tubes*/
	DoubleID getMultiStreakSpecularRand(){char buffer[4096];sprintf_s (buffer, "%s.mssr",mName.c_str());return (const char*)buffer;}
	/*a brightness randomization for the added tubes*/
	BoolID getMultiStreakLightAll(){char buffer[4096];sprintf_s (buffer, "%s.msla",mName.c_str());return (const char*)buffer;}
	/*
	toggles backface removal for the mesh brushType
	making the inside edge of tubes disappear and speeding
	up the render
	*/
	BoolID getSingleSided(){char buffer[4096];sprintf_s (buffer, "%s.snsd",mName.c_str());return (const char*)buffer;}
	/*the number of points in each cross section used for the mesh brushType*/
	IntID getTubeSections(){char buffer[4096];sprintf_s (buffer, "%s.tbs",mName.c_str());return (const char*)buffer;}
	/*the number of cross sections added for each base segment for the mesh brushType*/
	IntID getSubSegments(){char buffer[4096];sprintf_s (buffer, "%s.ssg",mName.c_str());return (const char*)buffer;}
	/*
	light each pixel when rendering, as opposed to
	lighting  each vertex and interpolating the result
	when the mesh brushType is used.
	This will allows for detailed shadows and specular
	highlights. Also when displacement mapping is used it
	will allow a bump mapping of normals within each triangle.
	Note that if realLights is enabled this can result in
	significantly slower renders, as the evaluation of
	Maya lights is slow in the paint effects context.
	*/
	BoolID getPerPixelLighting(){char buffer[4096];sprintf_s (buffer, "%s.ppl",mName.c_str());return (const char*)buffer;}
	/*
	multiplies the width along the tube determined by
	the base and tip width. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	const WidthScaleID& getWidthScale(size_t wsc_i){char buffer[4096];sprintf_s (buffer, "%s.wsc[%i]",mName.c_str(),wsc_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getWidthScale_Position(size_t wsc_i){char buffer[4096];sprintf_s (buffer, "%s.wsc[%i].wscp",mName.c_str(),wsc_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getWidthScale_FloatValue(size_t wsc_i){char buffer[4096];sprintf_s (buffer, "%s.wsc[%i].wscfv",mName.c_str(),wsc_i);return (const char*)buffer;}
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
	const UnsignedintID& getWidthScale_Interp(size_t wsc_i){char buffer[4096];sprintf_s (buffer, "%s.wsc[%i].wsci",mName.c_str(),wsc_i);return (const char*)buffer;}
	/*
	multiplies the width along the leaf determined by
	the leaf base and tip widths. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	const LeafWidthScaleID& getLeafWidthScale(size_t lws_i){char buffer[4096];sprintf_s (buffer, "%s.lws[%i]",mName.c_str(),lws_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getLeafWidthScale_Position(size_t lws_i){char buffer[4096];sprintf_s (buffer, "%s.lws[%i].lwsp",mName.c_str(),lws_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getLeafWidthScale_FloatValue(size_t lws_i){char buffer[4096];sprintf_s (buffer, "%s.lws[%i].lwsfv",mName.c_str(),lws_i);return (const char*)buffer;}
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
	const UnsignedintID& getLeafWidthScale_Interp(size_t lws_i){char buffer[4096];sprintf_s (buffer, "%s.lws[%i].lwsi",mName.c_str(),lws_i);return (const char*)buffer;}
	/*
	multiplies the width along the petal determined by
	the petal base and tip widths. This is useful for creating shapes other
	than the simple conical tube shape determined by the base and tip widths.
	The left of the graph is the scale at the
	base and the right is the scale at the tip.
	*/
	const PetalWidthScaleID& getPetalWidthScale(size_t pws_i){char buffer[4096];sprintf_s (buffer, "%s.pws[%i]",mName.c_str(),pws_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getPetalWidthScale_Position(size_t pws_i){char buffer[4096];sprintf_s (buffer, "%s.pws[%i].pwsp",mName.c_str(),pws_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getPetalWidthScale_FloatValue(size_t pws_i){char buffer[4096];sprintf_s (buffer, "%s.pws[%i].pwsfv",mName.c_str(),pws_i);return (const char*)buffer;}
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
	const UnsignedintID& getPetalWidthScale_Interp(size_t pws_i){char buffer[4096];sprintf_s (buffer, "%s.pws[%i].pwsi",mName.c_str(),pws_i);return (const char*)buffer;}
	/*
	multiplies the twig lengths from root to tip of
	the parent branch.
	The left of the graph is the scale at the
	base of a tree and the right is the scale at the tip.
	*/
	const TwigLengthScaleID& getTwigLengthScale(size_t tls_i){char buffer[4096];sprintf_s (buffer, "%s.tls[%i]",mName.c_str(),tls_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getTwigLengthScale_Position(size_t tls_i){char buffer[4096];sprintf_s (buffer, "%s.tls[%i].tlsp",mName.c_str(),tls_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getTwigLengthScale_FloatValue(size_t tls_i){char buffer[4096];sprintf_s (buffer, "%s.tls[%i].tlsfv",mName.c_str(),tls_i);return (const char*)buffer;}
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
	const UnsignedintID& getTwigLengthScale_Interp(size_t tls_i){char buffer[4096];sprintf_s (buffer, "%s.tls[%i].tlsi",mName.c_str(),tls_i);return (const char*)buffer;}
	/*
	create thorns or prickles on branch tubes when the
	mesh brushType is used. This will
	also show up on normal strokes when tubes = OFF, as
	the effect is not part of the tubes simulation, but
	rather a render effect.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	BoolID getBranchThorns(){char buffer[4096];sprintf_s (buffer, "%s.bth",mName.c_str());return (const char*)buffer;}
	/*
	create thorns or prickles on twig tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	BoolID getTwigThorns(){char buffer[4096];sprintf_s (buffer, "%s.tth",mName.c_str());return (const char*)buffer;}
	/*
	create thorns or prickles on leaf tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	BoolID getLeafThorns(){char buffer[4096];sprintf_s (buffer, "%s.lth",mName.c_str());return (const char*)buffer;}
	/*
	create thorns or prickles on flower tubes when the
	mesh brushType is used.
	The thorns are drawn as a single segment using the thinTube method,
	and project off the triangle mesh along the triangle normals.
	*/
	BoolID getFlowerThorns(){char buffer[4096];sprintf_s (buffer, "%s.flt",mName.c_str());return (const char*)buffer;}
	/*The general amount of thorns drawn on the mesh.*/
	DoubleID getThornDensity(){char buffer[4096];sprintf_s (buffer, "%s.nth",mName.c_str());return (const char*)buffer;}
	/*The length (relative to the max tube width) for the thorns.*/
	DoubleID getThornLength(){char buffer[4096];sprintf_s (buffer, "%s.tln",mName.c_str());return (const char*)buffer;}
	/*The width (relative to the thorn length) at the base of the thorn.*/
	DoubleID getThornBaseWidth(){char buffer[4096];sprintf_s (buffer, "%s.tbwd",mName.c_str());return (const char*)buffer;}
	/*The width (relative to the thorn length) at the outer thorn tip.*/
	DoubleID getThornTipWidth(){char buffer[4096];sprintf_s (buffer, "%s.ttwd",mName.c_str());return (const char*)buffer;}
	/*
	elevation of the thorns relative to the mesh surface.
	An elevation of 1.0 is along the mesh normal.
	An elevation of 0 is along the tube and an elevation of
	2 is opposite to this.
	*/
	DoubleID getThornElevation(){char buffer[4096];sprintf_s (buffer, "%s.tel",mName.c_str());return (const char*)buffer;}
	/*intensity of specular highlights on thorns*/
	DoubleID getThornSpecular(){char buffer[4096];sprintf_s (buffer, "%s.tsp",mName.c_str());return (const char*)buffer;}
	/*color of thorns at the base*/
	Float3ID getThornBaseColor(){char buffer[4096];sprintf_s (buffer, "%s.tbc",mName.c_str());return (const char*)buffer;}
	/*Thorn Base Color Red value*/
	FloatID getThornBaseColorR(){char buffer[4096];sprintf_s (buffer, "%s.tbc.tbcr",mName.c_str());return (const char*)buffer;}
	/*Thorn Base Color Green value*/
	FloatID getThornBaseColorG(){char buffer[4096];sprintf_s (buffer, "%s.tbc.tbcg",mName.c_str());return (const char*)buffer;}
	/*Thorn Base Color Blue value*/
	FloatID getThornBaseColorB(){char buffer[4096];sprintf_s (buffer, "%s.tbc.tbcb",mName.c_str());return (const char*)buffer;}
	/*color of thorns at the tip*/
	Float3ID getThornTipColor(){char buffer[4096];sprintf_s (buffer, "%s.ttc",mName.c_str());return (const char*)buffer;}
	/*Thorn Tip Color Red value*/
	FloatID getThornTipColorR(){char buffer[4096];sprintf_s (buffer, "%s.ttc.ttcr",mName.c_str());return (const char*)buffer;}
	/*Thorn Tip Color Green value*/
	FloatID getThornTipColorG(){char buffer[4096];sprintf_s (buffer, "%s.ttc.ttcg",mName.c_str());return (const char*)buffer;}
	/*Thorn Tip Color Blue value*/
	FloatID getThornTipColorB(){char buffer[4096];sprintf_s (buffer, "%s.ttc.ttcb",mName.c_str());return (const char*)buffer;}
	/*
	This defines a spherical reflection environment, where
	the left of the ramp represents light from the top of the sky, the right is
	the ground and the middle is the horizon. Currently it
	only works with the mesh brushtype.
	*/
	const EnvironmentID& getEnvironment(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i]",mName.c_str(),env_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getEnvironment_Position(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envp",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp color at the sibling position*/
	const Float3ID& getEnvironment_Color(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp red channel value at the sibling position*/
	const FloatID& getEnvironment_ColorR(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcr",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp green channel value at the sibling position*/
	const FloatID& getEnvironment_ColorG(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcg",mName.c_str(),env_i);return (const char*)buffer;}
	/*Ramp blue channel value at the sibling position*/
	const FloatID& getEnvironment_ColorB(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envc.envcb",mName.c_str(),env_i);return (const char*)buffer;}
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
	const UnsignedintID& getEnvironment_Interp(size_t env_i){char buffer[4096];sprintf_s (buffer, "%s.env[%i].envi",mName.c_str(),env_i);return (const char*)buffer;}
	/*
	<b>Reflection Rolloff</b> controls the reflectivity of the
	environment ramp based on the angle of the surface with the view.
	The horizontal dimension of the graph represents the brightness
	of reflections and the horizontal represents the facing
	angle with the view.
	<i>Tip:</i> to get a "wet" look (such as wet paint), make the
	edges more reflective.
	*/
	const ReflectionRolloffID& getReflectionRolloff(size_t rro_i){char buffer[4096];sprintf_s (buffer, "%s.rro[%i]",mName.c_str(),rro_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getReflectionRolloff_Position(size_t rro_i){char buffer[4096];sprintf_s (buffer, "%s.rro[%i].rrop",mName.c_str(),rro_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getReflectionRolloff_FloatValue(size_t rro_i){char buffer[4096];sprintf_s (buffer, "%s.rro[%i].rrofv",mName.c_str(),rro_i);return (const char*)buffer;}
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
	const UnsignedintID& getReflectionRolloff_Interp(size_t rro_i){char buffer[4096];sprintf_s (buffer, "%s.rro[%i].rroi",mName.c_str(),rro_i);return (const char*)buffer;}
	/*
	intensity of environment reflection on primary
	branches and twigs. This also applies to strokes when
	tubes = OFF. Environment reflections only work with
	the mesh brushtype.
	*/
	DoubleID getBranchReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.brf",mName.c_str());return (const char*)buffer;}
	/*
	intensity of environment reflection on leaves.
	Environment reflections only work with
	the mesh brushtype.
	*/
	DoubleID getLeafReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.lrf",mName.c_str());return (const char*)buffer;}
	/*
	intensity of environment reflection on flowers.
	Environment reflections only work with
	the mesh brushtype.
	*/
	DoubleID getFlowerReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.frf",mName.c_str());return (const char*)buffer;}
	/*
	Lock the twist about main branches to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the tubes are flat, then the flat
	side will alway orient towards the camera. With this on, one could texture
	a simple flat stroke and always have it face the view. For a tree one could
	create a texture of a tree trunk with rough edges and map to a simple
	flat ribbon where the ribbon always faces the camera.
	*/
	BoolID getForwardTwist(){char buffer[4096];sprintf_s (buffer, "%s.fwt",mName.c_str());return (const char*)buffer;}
	/*
	Lock the twist about leaves to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the leaves are flat, then the flat
	side will alway orient towards the camera. One could map an image of an entire
	leafy branch with alpha to a flat leaf and use this toggle to always
	orient this image towards the view.
	*/
	BoolID getLeafForwardTwist(){char buffer[4096];sprintf_s (buffer, "%s.lfwt",mName.c_str());return (const char*)buffer;}
	/*
	Lock the twist about flower petals to always face the current camera.
	This is useful when setting up billboard style effect where one always
	wishes the texture to face the view. If the petals are flat, then the flat
	side will alway orient towards the camera. One could map an image of an apple
	or rose to a single flat petal, and have this always face the viewpoint.
	*/
	BoolID getPetalForwardTwist(){char buffer[4096];sprintf_s (buffer, "%s.lpwt",mName.c_str());return (const char*)buffer;}
	/*Add end cap geometry to tubes when using the mesh brushType .*/
	BoolID getEndCaps(){char buffer[4096];sprintf_s (buffer, "%s.edc",mName.c_str());return (const char*)buffer;}
	/*
	Make the edges around tubes hard when using the mesh brushType.
	For example if the tubeSections is 4 then this toggle will make
	the tube shade as if the 4 sides are flat, rather than trying to
	simulate a rounded tube. For bends in the direction of the tube( for
	example due to changes in the widthScale ) the bend angle across a given
	must be sufficiently large to make the angle hard. The number of segments
	used can affect whether a given region on the tube become hard edged or not.
	Note that this parameter adjusts the normals used for shading, and does not
	alter the shape of the tube.
	*/
	BoolID getHardEdges(){char buffer[4096];sprintf_s (buffer, "%s.hde",mName.c_str());return (const char*)buffer;}
protected:
	Brush(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BRUSH_H__
