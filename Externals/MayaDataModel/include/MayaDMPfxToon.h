/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PFXTOON_H__
#define __MayaDM_PFXTOON_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPfxGeometry.h"
namespace MayaDM
{
/*
<p><pre>
        This node contains attributes and routines for
        creating toon style outlines around objects.

</pre></p>
*/
class PfxToon : public PfxGeometry
{
public:
	/*
	This is the input multi-attribute for the surfaces getting toon outlines.
	Both the geometry and world matrix are connected.
	*/
	struct InputSurface{
		void write(FILE* file) const
		{
		}
	};
	/*
	When curvatureModulation is enabled the curvatureWidth graph controls
	how curvature affects line width.
	The input position sampled from the curvatureWidth graph is the the curvature,
	where the left of the graph is zero curvature( straight ) and the right is
	fully bent at a 180 degree angle. The output value of the graph (vertical position)
	is then used to determine a scale factor for the current width. Thus if the graph
	is a horizontal line with a value of 1.0 the line width is unchanged. Where the
	graph is zero the line width will be zero.
	*/
	struct CurvatureWidth{
		float curvatureWidth_Position;
		float curvatureWidth_FloatValue;
		unsigned int curvatureWidth_Interp;
		void write(FILE* file) const
		{
			fprintf_s(file,"%f ", curvatureWidth_Position);
			fprintf_s(file,"%f ", curvatureWidth_FloatValue);
			fprintf_s(file,"%i", curvatureWidth_Interp);
		}
	};
public:
	PfxToon(FILE* file,const std::string& name,const std::string& parent=""):PfxGeometry(file, name, parent, "pfxToon"){}
	virtual ~PfxToon(){}
	/*
	This is the input multi-attribute for the surfaces getting toon outlines.
	Both the geometry and world matrix are connected.
	*/
	void setInputSurface(size_t ins_i,const InputSurfaceID& ins){fprintf_s(mFile,"connectAttr \"");ins.write(mFile);fprintf_s(mFile,"\" \"%s.ins[%i]\";\n",mName.c_str(),ins_i);}
	/*Input mesh*/
	void setSurface(size_t ins_i,const MeshID& srf){fprintf_s(mFile,"connectAttr \"");srf.write(mFile);fprintf_s(mFile,"\" \"%s.ins[%i].srf\";\n",mName.c_str(),ins_i);}
	/*Input matrix from mesh or surface*/
	void setInputWorldMatrix(size_t ins_i,const MatrixID& iwm){fprintf_s(mFile,"connectAttr \"");iwm.write(mFile);fprintf_s(mFile,"\" \"%s.ins[%i].iwm\";\n",mName.c_str(),ins_i);}
	/*If on, then lines are displayed in the modelling viewports.*/
	void setDisplayInViewport(bool div){if(div == true) return; fprintf_s(mFile, "setAttr \".div\" %i;\n", div);}
	/*If on, then lines are displayed in the modelling viewports.*/
	void setDisplayInViewport(const BoolID& div){fprintf_s(mFile,"connectAttr \"");div.write(mFile);fprintf_s(mFile,"\" \"%s.div\";\n",mName.c_str());}
	/*
	If not off then lines are generated along the silhoutte of objects.
	If Paint Effects lines are used then curves following the outline are constructed.
	These lines are view relative and thus must are rebuilt when the view changes.
	If Offset Mesh is used, then a duplicate of the input mesh is constructed that is
	offset along the surface normal by the line width. By making this mesh both single sided
	and reversed a shell is formed that creates a silhoutte when rendered with the input mesh.
	This has the advantage of built in thick thin line properties that are stable when animated.
	It also has the advantage of not needing to be updated when the view changes. It will also
	appear in raytraced reflections and refractions.
	*/
	void setProfileLines(unsigned int pln){if(pln == 1) return; fprintf_s(mFile, "setAttr \".pln\" %i;\n", pln);}
	/*
	If not off then lines are generated along the silhoutte of objects.
	If Paint Effects lines are used then curves following the outline are constructed.
	These lines are view relative and thus must are rebuilt when the view changes.
	If Offset Mesh is used, then a duplicate of the input mesh is constructed that is
	offset along the surface normal by the line width. By making this mesh both single sided
	and reversed a shell is formed that creates a silhoutte when rendered with the input mesh.
	This has the advantage of built in thick thin line properties that are stable when animated.
	It also has the advantage of not needing to be updated when the view changes. It will also
	appear in raytraced reflections and refractions.
	*/
	void setProfileLines(const UnsignedintID& pln){fprintf_s(mFile,"connectAttr \"");pln.write(mFile);fprintf_s(mFile,"\" \"%s.pln\";\n",mName.c_str());}
	/*If on, then lines are generated along internal hard edges.*/
	void setCreaseLines(bool cln){if(cln == true) return; fprintf_s(mFile, "setAttr \".cln\" %i;\n", cln);}
	/*If on, then lines are generated along internal hard edges.*/
	void setCreaseLines(const BoolID& cln){fprintf_s(mFile,"connectAttr \"");cln.write(mFile);fprintf_s(mFile,"\" \"%s.cln\";\n",mName.c_str());}
	/*
	This allows one to generated lines along boundaries.
	Open Edges are considered to be edges that are shared by only one face. This can
	be used to provide lines around the border of a simple plane, for example.
	Profile lines do not handle this sort of edge, which only occurs when the surface
	is not fully closed.
	Shader boundary edges are where the faces attached to the edge do not
	share the same shader.
	*/
	void setBorderLines(unsigned int bln){if(bln == 1) return; fprintf_s(mFile, "setAttr \".bln\" %i;\n", bln);}
	/*
	This allows one to generated lines along boundaries.
	Open Edges are considered to be edges that are shared by only one face. This can
	be used to provide lines around the border of a simple plane, for example.
	Profile lines do not handle this sort of edge, which only occurs when the surface
	is not fully closed.
	Shader boundary edges are where the faces attached to the edge do not
	share the same shader.
	*/
	void setBorderLines(const UnsignedintID& bln){fprintf_s(mFile,"connectAttr \"");bln.write(mFile);fprintf_s(mFile,"\" \"%s.bln\";\n",mName.c_str());}
	/*If on, then lines are generated where surfaces intersect.*/
	void setIntersectionLines(bool iln){if(iln == false) return; fprintf_s(mFile, "setAttr \".iln\" %i;\n", iln);}
	/*If on, then lines are generated where surfaces intersect.*/
	void setIntersectionLines(const BoolID& iln){fprintf_s(mFile,"connectAttr \"");iln.write(mFile);fprintf_s(mFile,"\" \"%s.iln\";\n",mName.c_str());}
	/*If on, then lines are generated where surfaces intersect themselves.*/
	void setSelfIntersect(bool sei){if(sei == false) return; fprintf_s(mFile, "setAttr \".sei\" %i;\n", sei);}
	/*If on, then lines are generated where surfaces intersect themselves.*/
	void setSelfIntersect(const BoolID& sei){fprintf_s(mFile,"connectAttr \"");sei.write(mFile);fprintf_s(mFile,"\" \"%s.sei\";\n",mName.c_str());}
	/*This controls the global width of the profile, crease and boundary lines.*/
	void setLineWidth(double lwd){if(lwd == 0.1) return; fprintf_s(mFile, "setAttr \".lwd\" %f;\n", lwd);}
	/*This controls the global width of the profile, crease and boundary lines.*/
	void setLineWidth(const DoubleID& lwd){fprintf_s(mFile,"connectAttr \"");lwd.write(mFile);fprintf_s(mFile,"\" \"%s.lwd\";\n",mName.c_str());}
	/*
	This attribute can be used to vary line width with a 2D texture map.
	This attributes scales the currently defined line width, but by 2 times the
	lineWidthMap value, so that a value of 0.5 has no effect. Where the texture
	value was 0.25 the line width would be half of the lineWidth attribute value and
	where the value is 1.0 the value would be double. Values outside the zero to one
	range can also be used( for file textures this generally requires increasing the
	alpha gain on the texture ).
	The texture is mapped into uv space of the surface the lines are on. In addition
	to thick and thin effects, one can also block line formation entirely in places by
	using a zero texture value. Note that 3D, projective 2D, and environment textures
	are not currently supported.
	*/
	void setLineWidthMap(double lwm){if(lwm == 0.5) return; fprintf_s(mFile, "setAttr \".lwm\" %f;\n", lwm);}
	/*
	This attribute can be used to vary line width with a 2D texture map.
	This attributes scales the currently defined line width, but by 2 times the
	lineWidthMap value, so that a value of 0.5 has no effect. Where the texture
	value was 0.25 the line width would be half of the lineWidth attribute value and
	where the value is 1.0 the value would be double. Values outside the zero to one
	range can also be used( for file textures this generally requires increasing the
	alpha gain on the texture ).
	The texture is mapped into uv space of the surface the lines are on. In addition
	to thick and thin effects, one can also block line formation entirely in places by
	using a zero texture value. Note that 3D, projective 2D, and environment textures
	are not currently supported.
	*/
	void setLineWidthMap(const DoubleID& lwm){fprintf_s(mFile,"connectAttr \"");lwm.write(mFile);fprintf_s(mFile,"\" \"%s.lwm\";\n",mName.c_str());}
	/*
	This controls the opacity of the profile, crease and boundary lines.
	An opacity of 0 is fully transparent and an opacity of 1 is fully opaque.
	*/
	void setLineOpacity(double lop){if(lop == 1.0) return; fprintf_s(mFile, "setAttr \".lop\" %f;\n", lop);}
	/*
	This controls the opacity of the profile, crease and boundary lines.
	An opacity of 0 is fully transparent and an opacity of 1 is fully opaque.
	*/
	void setLineOpacity(const DoubleID& lop){fprintf_s(mFile,"connectAttr \"");lop.write(mFile);fprintf_s(mFile,"\" \"%s.lop\";\n",mName.c_str());}
	/*
	This attribute can be used to vary the line opacity with a 2D texture map.
	This attributes scales the currently defined line opacity, so where the texture
	value was 0.5 the line opacity would be half of the lineOpacity attribute value.
	The texture is mapped into uv space of the surface the lines are on.
	Note that 3D, projective 2D, and environment textures are not currently supported.
	*/
	void setLineOpacityMap(double lpm){if(lpm == 1.0) return; fprintf_s(mFile, "setAttr \".lpm\" %f;\n", lpm);}
	/*
	This attribute can be used to vary the line opacity with a 2D texture map.
	This attributes scales the currently defined line opacity, so where the texture
	value was 0.5 the line opacity would be half of the lineOpacity attribute value.
	The texture is mapped into uv space of the surface the lines are on.
	Note that 3D, projective 2D, and environment textures are not currently supported.
	*/
	void setLineOpacityMap(const DoubleID& lpm){fprintf_s(mFile,"connectAttr \"");lpm.write(mFile);fprintf_s(mFile,"\" \"%s.lpm\";\n",mName.c_str());}
	/*
	If Line Surface is used then lines will be clipped where they are hidden by the surface they are created from.
	If All Toon Surfaces is used then lines will be clipped where they are hidden by any of the surfaces that are
	currently assigned these toon lines.
	This occlusion is generally meant to augment the line occlusion by the normal paint effect render, or
	orther renders if convert toon to poly is used. With paint effects renders, the depthBias attribute may
	be useful when combined with local occlusion.
	*/
	void setLocalOcclusion(unsigned int lcl){if(lcl == 0) return; fprintf_s(mFile, "setAttr \".lcl\" %i;\n", lcl);}
	/*
	If Line Surface is used then lines will be clipped where they are hidden by the surface they are created from.
	If All Toon Surfaces is used then lines will be clipped where they are hidden by any of the surfaces that are
	currently assigned these toon lines.
	This occlusion is generally meant to augment the line occlusion by the normal paint effect render, or
	orther renders if convert toon to poly is used. With paint effects renders, the depthBias attribute may
	be useful when combined with local occlusion.
	*/
	void setLocalOcclusion(const UnsignedintID& lcl){fprintf_s(mFile,"connectAttr \"");lcl.write(mFile);fprintf_s(mFile,"\" \"%s.lcl\";\n",mName.c_str());}
	/*
	This is an amount in worldspace that lines are moved towards the camera when testing
	depth for local occlusion. A small value is required to avoid artifacts where the surface
	self occludes lines.
	*/
	void setOcclusionTolerance(double otl){if(otl == 0.01) return; fprintf_s(mFile, "setAttr \".otl\" %f;\n", otl);}
	/*
	This is an amount in worldspace that lines are moved towards the camera when testing
	depth for local occlusion. A small value is required to avoid artifacts where the surface
	self occludes lines.
	*/
	void setOcclusionTolerance(const DoubleID& otl){fprintf_s(mFile,"connectAttr \"");otl.write(mFile);fprintf_s(mFile,"\" \"%s.otl\";\n",mName.c_str());}
	/*
	This is an amount in worldspace that lines are moved towards the camera when rendering.
	This is useful in avoiding artifacts with depth occlusion by the surface the lines are on.
	*/
	void setDepthBias(double dbs){if(dbs == 0.0) return; fprintf_s(mFile, "setAttr \".dbs\" %f;\n", dbs);}
	/*
	This is an amount in worldspace that lines are moved towards the camera when rendering.
	This is useful in avoiding artifacts with depth occlusion by the surface the lines are on.
	*/
	void setDepthBias(const DoubleID& dbs){fprintf_s(mFile,"connectAttr \"");dbs.write(mFile);fprintf_s(mFile,"\" \"%s.dbs\";\n",mName.c_str());}
	/*This is a relative scale of the width of the profile, or silhoutte lines.*/
	void setProfileLineWidth(double plw){if(plw == 1.0) return; fprintf_s(mFile, "setAttr \".plw\" %f;\n", plw);}
	/*This is a relative scale of the width of the profile, or silhoutte lines.*/
	void setProfileLineWidth(const DoubleID& plw){fprintf_s(mFile,"connectAttr \"");plw.write(mFile);fprintf_s(mFile,"\" \"%s.plw\";\n",mName.c_str());}
	/*This is a relative scale of the width of the crease, or hard edge lines.*/
	void setCreaseLineWidth(double clw){if(clw == 1.0) return; fprintf_s(mFile, "setAttr \".clw\" %f;\n", clw);}
	/*This is a relative scale of the width of the crease, or hard edge lines.*/
	void setCreaseLineWidth(const DoubleID& clw){fprintf_s(mFile,"connectAttr \"");clw.write(mFile);fprintf_s(mFile,"\" \"%s.clw\";\n",mName.c_str());}
	/*This is a relative scale of the width of the border, or boundary lines.*/
	void setBorderLineWidth(double blw){if(blw == 1.0) return; fprintf_s(mFile, "setAttr \".blw\" %f;\n", blw);}
	/*This is a relative scale of the width of the border, or boundary lines.*/
	void setBorderLineWidth(const DoubleID& blw){fprintf_s(mFile,"connectAttr \"");blw.write(mFile);fprintf_s(mFile,"\" \"%s.blw\";\n",mName.c_str());}
	/*This is a relative scale of the width of the intersection lines.*/
	void setIntersectionLineWidth(double ilw){if(ilw == 1.0) return; fprintf_s(mFile, "setAttr \".ilw\" %f;\n", ilw);}
	/*This is a relative scale of the width of the intersection lines.*/
	void setIntersectionLineWidth(const DoubleID& ilw){fprintf_s(mFile,"connectAttr \"");ilw.write(mFile);fprintf_s(mFile,"\" \"%s.ilw\";\n",mName.c_str());}
	/*
	This offsets lines along the surface normal. The amount of offset is relative
	to the line width, a value of 1.0 having the line just touch the surface. With a
	value of 0 the line is half intersecting the surface.
	*/
	void setLineOffset(double lof){if(lof == 0.0) return; fprintf_s(mFile, "setAttr \".lof\" %f;\n", lof);}
	/*
	This offsets lines along the surface normal. The amount of offset is relative
	to the line width, a value of 1.0 having the line just touch the surface. With a
	value of 0 the line is half intersecting the surface.
	*/
	void setLineOffset(const DoubleID& lof){fprintf_s(mFile,"connectAttr \"");lof.write(mFile);fprintf_s(mFile,"\" \"%s.lof\";\n",mName.c_str());}
	/*
	This attribute can be used to vary line offset with a 2D texture map. If
	a noisy texture is used this can create a wiggly line.
	This attributes scales the currently defined line offset, so where the texture
	value was 0.5 the line offset would be half of the lineOffset attribute value.
	The texture is mapped into uv space of the surface the lines are on.
	Note that 3D, projective 2D, and environment textures
	are not currently supported.
	*/
	void setLineOffsetMap(double lom){if(lom == 0.0) return; fprintf_s(mFile, "setAttr \".lom\" %f;\n", lom);}
	/*
	This attribute can be used to vary line offset with a 2D texture map. If
	a noisy texture is used this can create a wiggly line.
	This attributes scales the currently defined line offset, so where the texture
	value was 0.5 the line offset would be half of the lineOffset attribute value.
	The texture is mapped into uv space of the surface the lines are on.
	Note that 3D, projective 2D, and environment textures
	are not currently supported.
	*/
	void setLineOffsetMap(const DoubleID& lom){fprintf_s(mFile,"connectAttr \"");lom.write(mFile);fprintf_s(mFile,"\" \"%s.lom\";\n",mName.c_str());}
	/*
	The width is scaled by the diffuse light
	intensity. Brighter regions will be thinner.
	Shadowed and dark regions will have full width
	tubes. Using negative values can have the reverse
	effect. The lighting used is a diffuse illumination
	that is relative to the local surface normal.
	*/
	void setLightingBasedWidth(double lbw){if(lbw == 0.0) return; fprintf_s(mFile, "setAttr \".lbw\" %f;\n", lbw);}
	/*
	The width is scaled by the diffuse light
	intensity. Brighter regions will be thinner.
	Shadowed and dark regions will have full width
	tubes. Using negative values can have the reverse
	effect. The lighting used is a diffuse illumination
	that is relative to the local surface normal.
	*/
	void setLightingBasedWidth(const DoubleID& lbw){fprintf_s(mFile,"connectAttr \"");lbw.write(mFile);fprintf_s(mFile,"\" \"%s.lbw\";\n",mName.c_str());}
	/*
	<b>OcclusionWidthScale</b> is useful for avoiding aliasing artifacts
	along the inside edge of lines. The paint effects brush stamp radius is
	scaled down based on the average occlusion within the stamp region, rather
	than occluding each pixel of the stamp draw. This allows lines to have their
	center on the object's profile boundary. Otherwise the line on the inside
	edge gets occluded by the object, and thus only the outer half of the line
	is visible. Paint Effects relies on the the depth buffer from the scanline
	phase of the render for occlusion, however there is only one depth value
	per pixel, which creates a challenge for good antialiasing. Using
	Occlusion Width Scale gets around some of these aliasing problems, although
	very thick lines may in places bite into objects more than desired. Also
	in some unusual situations it may cause a blobby quality where there are
	sudden changes in occlusion. Note that if a brush is assigned the toon line,
	then the setting for occlusion width scale on the brush node will override
	the setting on the toon node.
	*/
	void setOcclusionWidthScale(bool ows){if(ows == true) return; fprintf_s(mFile, "setAttr \".ows\" %i;\n", ows);}
	/*
	<b>OcclusionWidthScale</b> is useful for avoiding aliasing artifacts
	along the inside edge of lines. The paint effects brush stamp radius is
	scaled down based on the average occlusion within the stamp region, rather
	than occluding each pixel of the stamp draw. This allows lines to have their
	center on the object's profile boundary. Otherwise the line on the inside
	edge gets occluded by the object, and thus only the outer half of the line
	is visible. Paint Effects relies on the the depth buffer from the scanline
	phase of the render for occlusion, however there is only one depth value
	per pixel, which creates a challenge for good antialiasing. Using
	Occlusion Width Scale gets around some of these aliasing problems, although
	very thick lines may in places bite into objects more than desired. Also
	in some unusual situations it may cause a blobby quality where there are
	sudden changes in occlusion. Note that if a brush is assigned the toon line,
	then the setting for occlusion width scale on the brush node will override
	the setting on the toon node.
	*/
	void setOcclusionWidthScale(const BoolID& ows){fprintf_s(mFile,"connectAttr \"");ows.write(mFile);fprintf_s(mFile,"\" \"%s.ows\";\n",mName.c_str());}
	/*
	This offsets profile lines along the view direction. This can help give lines
	a more graduated width where the profile is internal to the object.
	*/
	void setDepthOffset(double dff){if(dff == 0.0) return; fprintf_s(mFile, "setAttr \".dff\" %f;\n", dff);}
	/*
	This offsets profile lines along the view direction. This can help give lines
	a more graduated width where the profile is internal to the object.
	*/
	void setDepthOffset(const DoubleID& dff){fprintf_s(mFile,"connectAttr \"");dff.write(mFile);fprintf_s(mFile,"\" \"%s.dff\";\n",mName.c_str());}
	/*
	This is the start angle in degrees between faces beyond which creasing forms.
	Line thickness can be graduated between zero width at the min angle and
	going to full thickness at the max.
	At an angle of zero all edges will be drawn, if hardCreasesOnly is OFF.
	*/
	void setCreaseAngleMin(double amn){if(amn == 20.0) return; fprintf_s(mFile, "setAttr \".amn\" %f;\n", amn);}
	/*
	This is the start angle in degrees between faces beyond which creasing forms.
	Line thickness can be graduated between zero width at the min angle and
	going to full thickness at the max.
	At an angle of zero all edges will be drawn, if hardCreasesOnly is OFF.
	*/
	void setCreaseAngleMin(const DoubleID& amn){fprintf_s(mFile,"connectAttr \"");amn.write(mFile);fprintf_s(mFile,"\" \"%s.amn\";\n",mName.c_str());}
	/*
	This is the angle in degrees between faces beyond which crease line thickness
	is the maximum.
	At an angle of zero all edges will be drawn, if hardCreasesOnly is OFF.
	*/
	void setCreaseAngleMax(double amx){if(amx == 90.0) return; fprintf_s(mFile, "setAttr \".amx\" %f;\n", amx);}
	/*
	This is the angle in degrees between faces beyond which crease line thickness
	is the maximum.
	At an angle of zero all edges will be drawn, if hardCreasesOnly is OFF.
	*/
	void setCreaseAngleMax(const DoubleID& amx){fprintf_s(mFile,"connectAttr \"");amx.write(mFile);fprintf_s(mFile,"\" \"%s.amx\";\n",mName.c_str());}
	/*If on, then creases are only generated along hardened edges.*/
	void setHardCreasesOnly(bool hco){if(hco == true) return; fprintf_s(mFile, "setAttr \".hco\" %i;\n", hco);}
	/*If on, then creases are only generated along hardened edges.*/
	void setHardCreasesOnly(const BoolID& hco){fprintf_s(mFile,"connectAttr \"");hco.write(mFile);fprintf_s(mFile,"\" \"%s.hco\";\n",mName.c_str());}
	/*If on, then creases are generated on surfaces that face away from the view.*/
	void setBackfacingCreases(bool bfc){if(bfc == true) return; fprintf_s(mFile, "setAttr \".bfc\" %i;\n", bfc);}
	/*If on, then creases are generated on surfaces that face away from the view.*/
	void setBackfacingCreases(const BoolID& bfc){fprintf_s(mFile,"connectAttr \"");bfc.write(mFile);fprintf_s(mFile,"\" \"%s.bfc\";\n",mName.c_str());}
	/*
	This is the start angle in degrees between faces beyond which intersection lines form.
	Line thickness can be graduated between zero width at the min angle and
	going to full thickness at the max.
	At an angle of zero all intersecting edges will be drawn.
	By varying the min max intersection angle one can avoid lines along
	flush intersections, yet still have lines where the intersection angle
	is steeper.
	*/
	void setIntersectionAngleMin(double imn){if(imn == 1.0) return; fprintf_s(mFile, "setAttr \".imn\" %f;\n", imn);}
	/*
	This is the start angle in degrees between faces beyond which intersection lines form.
	Line thickness can be graduated between zero width at the min angle and
	going to full thickness at the max.
	At an angle of zero all intersecting edges will be drawn.
	By varying the min max intersection angle one can avoid lines along
	flush intersections, yet still have lines where the intersection angle
	is steeper.
	*/
	void setIntersectionAngleMin(const DoubleID& imn){fprintf_s(mFile,"connectAttr \"");imn.write(mFile);fprintf_s(mFile,"\" \"%s.imn\";\n",mName.c_str());}
	/*
	This is the angle in degrees between faces beyond which intersection line thickness
	is the maximum.
	At an angle of zero all intersection lines will be drawn at full thickness.
	*/
	void setIntersectionAngleMax(double imx){if(imx == 1.0) return; fprintf_s(mFile, "setAttr \".imx\" %f;\n", imx);}
	/*
	This is the angle in degrees between faces beyond which intersection line thickness
	is the maximum.
	At an angle of zero all intersection lines will be drawn at full thickness.
	*/
	void setIntersectionAngleMax(const DoubleID& imx){fprintf_s(mFile,"connectAttr \"");imx.write(mFile);fprintf_s(mFile,"\" \"%s.imx\";\n",mName.c_str());}
	/*
	If on then the profile is computed based on the interpolated normals.
	If off the profile curve will exist only on polygon edges. The off state guarantees that
	the profile will be always at the exact visible boundary, although it will jump in
	discreet steps as the view changes or the object deforms. With smooth profiles ON
	the profile changes in a smooth continuous fashion, but may creep in from edges in places
	where the surface is crudely triangulated.
	*/
	void setSmoothProfile(bool spf){if(spf == true) return; fprintf_s(mFile, "setAttr \".spf\" %i;\n", spf);}
	/*
	If on then the profile is computed based on the interpolated normals.
	If off the profile curve will exist only on polygon edges. The off state guarantees that
	the profile will be always at the exact visible boundary, although it will jump in
	discreet steps as the view changes or the object deforms. With smooth profiles ON
	the profile changes in a smooth continuous fashion, but may creep in from edges in places
	where the surface is crudely triangulated.
	*/
	void setSmoothProfile(const BoolID& spf){fprintf_s(mFile,"connectAttr \"");spf.write(mFile);fprintf_s(mFile,"\" \"%s.spf\";\n",mName.c_str());}
	/*
	If on then smooth profiles will be a bit closer to the mesh profile edge, particularily
	in cases where the vertex normals do not match an edge orientation well. A primitive cone
	is a good example of this situation. Deriving the profile from the vertex normals does
	not work well in this case, because the normals define more of a hump than a pointed cone.
	For a cone the tighter profile method will push the profile about halfway closer to the
	the point of the cone. To fit closer than this, increase the subdivisions on the cone, or
	turn off smooth profile.
	*/
	void setTighterProfile(bool tpf){if(tpf == false) return; fprintf_s(mFile, "setAttr \".tpf\" %i;\n", tpf);}
	/*
	If on then smooth profiles will be a bit closer to the mesh profile edge, particularily
	in cases where the vertex normals do not match an edge orientation well. A primitive cone
	is a good example of this situation. Deriving the profile from the vertex normals does
	not work well in this case, because the normals define more of a hump than a pointed cone.
	For a cone the tighter profile method will push the profile about halfway closer to the
	the point of the cone. To fit closer than this, increase the subdivisions on the cone, or
	turn off smooth profile.
	*/
	void setTighterProfile(const BoolID& tpf){fprintf_s(mFile,"connectAttr \"");tpf.write(mFile);fprintf_s(mFile,"\" \"%s.tpf\";\n",mName.c_str());}
	/*
	This varies the width of lines relative to the 3d curvature of the line.
	When enabled the curvatureWidth graph controls how curvature affects line width.
	The input position sampled from the curvatureWidth graph is the the curvature,
	where the left of the graph is zero curvature( straight ) and the right is
	fully bent at a 180 degree angle. The output value of the graph (vertical position)
	is then used to determine a scale factor for the current width. Thus if the graph
	is a horizontal line with a value of 1.0 the line width is unchanged. Where the
	graph is zero the line width will be zero.
	*/
	void setCurvatureModulation(bool cmo){if(cmo == false) return; fprintf_s(mFile, "setAttr \".cmo\" %i;\n", cmo);}
	/*
	This varies the width of lines relative to the 3d curvature of the line.
	When enabled the curvatureWidth graph controls how curvature affects line width.
	The input position sampled from the curvatureWidth graph is the the curvature,
	where the left of the graph is zero curvature( straight ) and the right is
	fully bent at a 180 degree angle. The output value of the graph (vertical position)
	is then used to determine a scale factor for the current width. Thus if the graph
	is a horizontal line with a value of 1.0 the line width is unchanged. Where the
	graph is zero the line width will be zero.
	*/
	void setCurvatureModulation(const BoolID& cmo){fprintf_s(mFile,"connectAttr \"");cmo.write(mFile);fprintf_s(mFile,"\" \"%s.cmo\";\n",mName.c_str());}
	/*
	When curvatureModulation is enabled the curvatureWidth graph controls
	how curvature affects line width.
	The input position sampled from the curvatureWidth graph is the the curvature,
	where the left of the graph is zero curvature( straight ) and the right is
	fully bent at a 180 degree angle. The output value of the graph (vertical position)
	is then used to determine a scale factor for the current width. Thus if the graph
	is a horizontal line with a value of 1.0 the line width is unchanged. Where the
	graph is zero the line width will be zero.
	*/
	void setCurvatureWidth(size_t cwd_i,const CurvatureWidth& cwd){fprintf_s(mFile, "setAttr \".cwd[%i]\" ",cwd_i);cwd.write(mFile);fprintf_s(mFile,";\n");}
	/*
	When curvatureModulation is enabled the curvatureWidth graph controls
	how curvature affects line width.
	The input position sampled from the curvatureWidth graph is the the curvature,
	where the left of the graph is zero curvature( straight ) and the right is
	fully bent at a 180 degree angle. The output value of the graph (vertical position)
	is then used to determine a scale factor for the current width. Thus if the graph
	is a horizontal line with a value of 1.0 the line width is unchanged. Where the
	graph is zero the line width will be zero.
	*/
	void setCurvatureWidth(size_t cwd_i,const CurvatureWidthID& cwd){fprintf_s(mFile,"connectAttr \"");cwd.write(mFile);fprintf_s(mFile,"\" \"%s.cwd[%i]\";\n",mName.c_str(),cwd_i);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCurvatureWidth_Position(size_t cwd_i,float cwdp){if(cwdp == 0.0) return; fprintf_s(mFile, "setAttr \".cwd[%i].cwdp\" %f;\n", cwd_i,cwdp);}
	/*Position of ramp value on normalized 0-1 scale*/
	void setCurvatureWidth_Position(size_t cwd_i,const FloatID& cwdp){fprintf_s(mFile,"connectAttr \"");cwdp.write(mFile);fprintf_s(mFile,"\" \"%s.cwd[%i].cwdp\";\n",mName.c_str(),cwd_i);}
	/*Ramp value at the sibling position*/
	void setCurvatureWidth_FloatValue(size_t cwd_i,float cwdfv){if(cwdfv == 0.0) return; fprintf_s(mFile, "setAttr \".cwd[%i].cwdfv\" %f;\n", cwd_i,cwdfv);}
	/*Ramp value at the sibling position*/
	void setCurvatureWidth_FloatValue(size_t cwd_i,const FloatID& cwdfv){fprintf_s(mFile,"connectAttr \"");cwdfv.write(mFile);fprintf_s(mFile,"\" \"%s.cwd[%i].cwdfv\";\n",mName.c_str(),cwd_i);}
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
	void setCurvatureWidth_Interp(size_t cwd_i,unsigned int cwdi){if(cwdi == 0) return; fprintf_s(mFile, "setAttr \".cwd[%i].cwdi\" %i;\n", cwd_i,cwdi);}
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
	void setCurvatureWidth_Interp(size_t cwd_i,const UnsignedintID& cwdi){fprintf_s(mFile,"connectAttr \"");cwdi.write(mFile);fprintf_s(mFile,"\" \"%s.cwd[%i].cwdi\";\n",mName.c_str(),cwd_i);}
	/*This varies the width of lines relative to the view angle.*/
	void setProfileWidthModulation(double pwm){if(pwm == 0.0) return; fprintf_s(mFile, "setAttr \".pwm\" %f;\n", pwm);}
	/*This varies the width of lines relative to the view angle.*/
	void setProfileWidthModulation(const DoubleID& pwm){fprintf_s(mFile,"connectAttr \"");pwm.write(mFile);fprintf_s(mFile,"\" \"%s.pwm\";\n",mName.c_str());}
	/*This varies the width of lines relative to the view angle.*/
	void setCreaseWidthModulation(double cwm){if(cwm == 0.0) return; fprintf_s(mFile, "setAttr \".cwm\" %f;\n", cwm);}
	/*This varies the width of lines relative to the view angle.*/
	void setCreaseWidthModulation(const DoubleID& cwm){fprintf_s(mFile,"connectAttr \"");cwm.write(mFile);fprintf_s(mFile,"\" \"%s.cwm\";\n",mName.c_str());}
	/*This varies the width of lines relative to the view angle.*/
	void setBorderWidthModulation(double bwm){if(bwm == 0.5) return; fprintf_s(mFile, "setAttr \".bwm\" %f;\n", bwm);}
	/*This varies the width of lines relative to the view angle.*/
	void setBorderWidthModulation(const DoubleID& bwm){fprintf_s(mFile,"connectAttr \"");bwm.write(mFile);fprintf_s(mFile,"\" \"%s.bwm\";\n",mName.c_str());}
	/*This varies the width of lines relative to the view angle.*/
	void setIntersectionWidthModulation(double imd){if(imd == 0.0) return; fprintf_s(mFile, "setAttr \".imd\" %f;\n", imd);}
	/*This varies the width of lines relative to the view angle.*/
	void setIntersectionWidthModulation(const DoubleID& imd){fprintf_s(mFile,"connectAttr \"");imd.write(mFile);fprintf_s(mFile,"\" \"%s.imd\";\n",mName.c_str());}
	/*
	This is the angle in degrees beyond which profile lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	void setProfileBreakAngle(double pba){if(pba == 180.0) return; fprintf_s(mFile, "setAttr \".pba\" %f;\n", pba);}
	/*
	This is the angle in degrees beyond which profile lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	void setProfileBreakAngle(const DoubleID& pba){fprintf_s(mFile,"connectAttr \"");pba.write(mFile);fprintf_s(mFile,"\" \"%s.pba\";\n",mName.c_str());}
	/*
	This is the angle in degrees beyond which crease lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	void setCreaseBreakAngle(double cba){if(cba == 80) return; fprintf_s(mFile, "setAttr \".cba\" %f;\n", cba);}
	/*
	This is the angle in degrees beyond which crease lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	void setCreaseBreakAngle(const DoubleID& cba){fprintf_s(mFile,"connectAttr \"");cba.write(mFile);fprintf_s(mFile,"\" \"%s.cba\";\n",mName.c_str());}
	/*
	This is the angle in degrees beyond which border lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	void setBorderBreakAngle(double bba){if(bba == 80.0) return; fprintf_s(mFile, "setAttr \".bba\" %f;\n", bba);}
	/*
	This is the angle in degrees beyond which border lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	void setBorderBreakAngle(const DoubleID& bba){fprintf_s(mFile,"connectAttr \"");bba.write(mFile);fprintf_s(mFile,"\" \"%s.bba\";\n",mName.c_str());}
	/*
	This is the angle in degrees beyond which intersection lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	void setIntersectionBreakAngle(double iba){if(iba == 180.0) return; fprintf_s(mFile, "setAttr \".iba\" %f;\n", iba);}
	/*
	This is the angle in degrees beyond which intersection lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	void setIntersectionBreakAngle(const DoubleID& iba){fprintf_s(mFile,"connectAttr \"");iba.write(mFile);fprintf_s(mFile,"\" \"%s.iba\";\n",mName.c_str());}
	/*This will removes borders where meshes touch and have matching normals.*/
	void setRemoveFlushBorders(bool rfb){if(rfb == false) return; fprintf_s(mFile, "setAttr \".rfb\" %i;\n", rfb);}
	/*This will removes borders where meshes touch and have matching normals.*/
	void setRemoveFlushBorders(const BoolID& rfb){fprintf_s(mFile,"connectAttr \"");rfb.write(mFile);fprintf_s(mFile,"\" \"%s.rfb\";\n",mName.c_str());}
	/*
	This is the max distance boundary cvs can be from each other when suppressing
	flush or common border lines.
	*/
	void setFlushTolerance(double tfl){if(tfl == 0.01) return; fprintf_s(mFile, "setAttr \".tfl\" %f;\n", tfl);}
	/*
	This is the max distance boundary cvs can be from each other when suppressing
	flush or common border lines.
	*/
	void setFlushTolerance(const DoubleID& tfl){fprintf_s(mFile,"connectAttr \"");tfl.write(mFile);fprintf_s(mFile,"\" \"%s.tfl\";\n",mName.c_str());}
	/*
	This is the max angle in degrees that boundary vertex normals can be from
	each other when suppressing flush or common border lines.
	*/
	void setFlushAngleMax(double fmx){if(fmx == 4.0) return; fprintf_s(mFile, "setAttr \".fmx\" %f;\n", fmx);}
	/*
	This is the max angle in degrees that boundary vertex normals can be from
	each other when suppressing flush or common border lines.
	*/
	void setFlushAngleMax(const DoubleID& fmx){fprintf_s(mFile,"connectAttr \"");fmx.write(mFile);fprintf_s(mFile,"\" \"%s.fmx\";\n",mName.c_str());}
	/*
	This controls the distance from line ends beyond which they become fully thick.
	Depending on the object one may need to lower the Break Angle values in order to
	see open line ends. For most surfaces the profile lines form closed lines with no
	open ends. The continuation of the profile is sometimes hidden where it goes behind
	the object. It may thus look like it has open ends event though it is closed and will
	thus not show the effect of line end thinning. Crease lines are more likely to show
	open ends than profiles or borders. One can use the break angles to create open ends
	where the line curves strongly.
	*/
	void setLineEndThinning(double let){if(let == 0.0) return; fprintf_s(mFile, "setAttr \".let\" %f;\n", let);}
	/*
	This controls the distance from line ends beyond which they become fully thick.
	Depending on the object one may need to lower the Break Angle values in order to
	see open line ends. For most surfaces the profile lines form closed lines with no
	open ends. The continuation of the profile is sometimes hidden where it goes behind
	the object. It may thus look like it has open ends event though it is closed and will
	thus not show the effect of line end thinning. Crease lines are more likely to show
	open ends than profiles or borders. One can use the break angles to create open ends
	where the line curves strongly.
	*/
	void setLineEndThinning(const DoubleID& let){fprintf_s(mFile,"connectAttr \"");let.write(mFile);fprintf_s(mFile,"\" \"%s.let\";\n",mName.c_str());}
	/*
	This extends the ends of lines so they cross at corners rather than simply intersecting.
	Line Extend simulates a pencil drafting style of line.
	Depending on the object one may need to lower the Break Angle values in order to
	see open line ends. For most surfaces the profile lines form closed lines with no
	open ends. The continuation of the profile is sometimes hidden where it goes behind
	the object. It may thus look like it has open ends event though it is closed and will
	thus not show the effect of Line Extend. Crease lines are more likely to show
	open ends than profiles or borders. One can use the break angles to create open ends
	where the line curves strongly.
	*/
	void setLineExtend(double lex){if(lex == 0.0) return; fprintf_s(mFile, "setAttr \".lex\" %f;\n", lex);}
	/*
	This extends the ends of lines so they cross at corners rather than simply intersecting.
	Line Extend simulates a pencil drafting style of line.
	Depending on the object one may need to lower the Break Angle values in order to
	see open line ends. For most surfaces the profile lines form closed lines with no
	open ends. The continuation of the profile is sometimes hidden where it goes behind
	the object. It may thus look like it has open ends event though it is closed and will
	thus not show the effect of Line Extend. Crease lines are more likely to show
	open ends than profiles or borders. One can use the break angles to create open ends
	where the line curves strongly.
	*/
	void setLineExtend(const DoubleID& lex){fprintf_s(mFile,"connectAttr \"");lex.write(mFile);fprintf_s(mFile,"\" \"%s.lex\";\n",mName.c_str());}
	/*
	The points along the profile are typically spaced at irregular distances, depending
	on the surface geometry. This is especially noticable if one assigns a brush with tubes ON
	to the toon line, where the tubes will jump around as the scene is animated. Enabling this
	causes the profile lines to be resampled at a uniform cv spacing, resulting in smoother
	strokes that jump less. The resample spacing needs to be small enough to avoid rounding
	corner edges.
	*/
	void setResampleProfile(bool rpf){if(rpf == false) return; fprintf_s(mFile, "setAttr \".rpf\" %i;\n", rpf);}
	/*
	The points along the profile are typically spaced at irregular distances, depending
	on the surface geometry. This is especially noticable if one assigns a brush with tubes ON
	to the toon line, where the tubes will jump around as the scene is animated. Enabling this
	causes the profile lines to be resampled at a uniform cv spacing, resulting in smoother
	strokes that jump less. The resample spacing needs to be small enough to avoid rounding
	corner edges.
	*/
	void setResampleProfile(const BoolID& rpf){fprintf_s(mFile,"connectAttr \"");rpf.write(mFile);fprintf_s(mFile,"\" \"%s.rpf\";\n",mName.c_str());}
	/*
	The points along the crease are normally spaced according to the size of poly edges. For simple objects
	this may not provide enough cvs for effects like line end thinning. Resample crease provides the ability
	to sample the crease lines with fewer or more cvs, as well as to fix the worldspace distance between
	curve cvs. Note that this may make crease lines twitch when animated if screenspace resampling is not zero.
	The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	void setResampleCrease(bool rcr){if(rcr == false) return; fprintf_s(mFile, "setAttr \".rcr\" %i;\n", rcr);}
	/*
	The points along the crease are normally spaced according to the size of poly edges. For simple objects
	this may not provide enough cvs for effects like line end thinning. Resample crease provides the ability
	to sample the crease lines with fewer or more cvs, as well as to fix the worldspace distance between
	curve cvs. Note that this may make crease lines twitch when animated if screenspace resampling is not zero.
	The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	void setResampleCrease(const BoolID& rcr){fprintf_s(mFile,"connectAttr \"");rcr.write(mFile);fprintf_s(mFile,"\" \"%s.rcr\";\n",mName.c_str());}
	/*
	The points along the border are normally spaced according to the size of poly edges. For simple objects
	this may not provide enough cvs for effects like line end thinning. Resample border provides the ability
	to sample the border lines with fewer or more cvs, as well as to fix the worldspace distance between
	curve cvs. Note that this may make border lines twitch when animated if screenspace resampling is not zero.
	The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	void setResampleBorder(bool rbd){if(rbd == false) return; fprintf_s(mFile, "setAttr \".rbd\" %i;\n", rbd);}
	/*
	The points along the border are normally spaced according to the size of poly edges. For simple objects
	this may not provide enough cvs for effects like line end thinning. Resample border provides the ability
	to sample the border lines with fewer or more cvs, as well as to fix the worldspace distance between
	curve cvs. Note that this may make border lines twitch when animated if screenspace resampling is not zero.
	The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	void setResampleBorder(const BoolID& rbd){fprintf_s(mFile,"connectAttr \"");rbd.write(mFile);fprintf_s(mFile,"\" \"%s.rbd\";\n",mName.c_str());}
	/*
	The points along the intersection are typically spaced at irregular distances. This is do to the way
	that triangles overlap along the edge. This is especially noticable if one assigns a brush with tubes ON
	to the toon line, where the tubes will jump around as the scene is animated. Enabling Resample Intersection
	causes the profile lines to be resampled at a uniform cv spacing, resulting in smoother
	strokes that jump less. The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	void setResampleIntersection(bool rin){if(rin == false) return; fprintf_s(mFile, "setAttr \".rin\" %i;\n", rin);}
	/*
	The points along the intersection are typically spaced at irregular distances. This is do to the way
	that triangles overlap along the edge. This is especially noticable if one assigns a brush with tubes ON
	to the toon line, where the tubes will jump around as the scene is animated. Enabling Resample Intersection
	causes the profile lines to be resampled at a uniform cv spacing, resulting in smoother
	strokes that jump less. The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	void setResampleIntersection(const BoolID& rin){fprintf_s(mFile,"connectAttr \"");rin.write(mFile);fprintf_s(mFile,"\" \"%s.rin\";\n",mName.c_str());}
	/*
	This is a maximum distance that is allowed between cvs on
	profiles when resample profile is ON. If this is small there
	may be many cvs on a profile curve. If this value is very large
	the profile curve will have its original number of cvs, but uniformly
	distributed across the original curve. One may have rounded corners
	if the max segment length is not low enough.
	*/
	void setMaxSegmentLength(double msl){if(msl == 0.5) return; fprintf_s(mFile, "setAttr \".msl\" %f;\n", msl);}
	/*
	This is a maximum distance that is allowed between cvs on
	profiles when resample profile is ON. If this is small there
	may be many cvs on a profile curve. If this value is very large
	the profile curve will have its original number of cvs, but uniformly
	distributed across the original curve. One may have rounded corners
	if the max segment length is not low enough.
	*/
	void setMaxSegmentLength(const DoubleID& msl){fprintf_s(mFile,"connectAttr \"");msl.write(mFile);fprintf_s(mFile,"\" \"%s.msl\";\n",mName.c_str());}
	/*
	This is the smallest distance that is allowed between cvs on
	profiles when resample profile is ON. If this is large the
	profile curve may be very crudely sampled. It is useful if one
	wants an output, for example to polymesh, where the number of segments
	is kept to a minimum. Also when combined with screenspace resampling it
	can be used to simplify distant profiles.
	*/
	void setMinSegmentLength(double mns){if(mns == 0.0) return; fprintf_s(mFile, "setAttr \".mns\" %f;\n", mns);}
	/*
	This is the smallest distance that is allowed between cvs on
	profiles when resample profile is ON. If this is large the
	profile curve may be very crudely sampled. It is useful if one
	wants an output, for example to polymesh, where the number of segments
	is kept to a minimum. Also when combined with screenspace resampling it
	can be used to simplify distant profiles.
	*/
	void setMinSegmentLength(const DoubleID& mns){fprintf_s(mFile,"connectAttr \"");mns.write(mFile);fprintf_s(mFile,"\" \"%s.mns\";\n",mName.c_str());}
	/*
	This controls the degree to which outline curve resampling is
	done in screenspace. When this is 1.0 the segments will be a fixed
	distance apart in screenspace. When it is 0.0 the distances are fixed in
	worldspace. Between 1.0 and 0.0 these two sampling methods are interpolated.
	This can be used to have profile curves become simpler with distance. Also if
	one has a brush with tubes = on assigned to the toon line the number of tubes
	will reduce with distance when this is greater than zero.
	*/
	void setScreenSpaceResampling(double ssr){if(ssr == 0.0) return; fprintf_s(mFile, "setAttr \".ssr\" %f;\n", ssr);}
	/*
	This controls the degree to which outline curve resampling is
	done in screenspace. When this is 1.0 the segments will be a fixed
	distance apart in screenspace. When it is 0.0 the distances are fixed in
	worldspace. Between 1.0 and 0.0 these two sampling methods are interpolated.
	This can be used to have profile curves become simpler with distance. Also if
	one has a brush with tubes = on assigned to the toon line the number of tubes
	will reduce with distance when this is greater than zero.
	*/
	void setScreenSpaceResampling(const DoubleID& ssr){fprintf_s(mFile,"connectAttr \"");ssr.write(mFile);fprintf_s(mFile,"\" \"%s.ssr\";\n",mName.c_str());}
	/*
	If this is ON then each curve is given a new random seed for paint effects.
	This requires that one have a pfx brush with tubes=ON assigned to the toon line.
	Profiles line tubes may jump around if this is ON when animated.
	*/
	void setPfxRandomize(bool prz){if(prz == false) return; fprintf_s(mFile, "setAttr \".prz\" %i;\n", prz);}
	/*
	If this is ON then each curve is given a new random seed for paint effects.
	This requires that one have a pfx brush with tubes=ON assigned to the toon line.
	Profiles line tubes may jump around if this is ON when animated.
	*/
	void setPfxRandomize(const BoolID& prz){fprintf_s(mFile,"connectAttr \"");prz.write(mFile);fprintf_s(mFile,"\" \"%s.prz\";\n",mName.c_str());}
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
	/*
	input color for profiles
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	void setProfileColor(const float3& pcl){fprintf_s(mFile, "setAttr \".pcl\" -type \"float3\" ");pcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	input color for profiles
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	void setProfileColor(const Float3ID& pcl){fprintf_s(mFile,"connectAttr \"");pcl.write(mFile);fprintf_s(mFile,"\" \"%s.pcl\";\n",mName.c_str());}
	/*profile color red value*/
	void setProfileColorR(float pcr){if(pcr == 0.0) return; fprintf_s(mFile, "setAttr \".pcl.pcr\" %f;\n", pcr);}
	/*profile color red value*/
	void setProfileColorR(const FloatID& pcr){fprintf_s(mFile,"connectAttr \"");pcr.write(mFile);fprintf_s(mFile,"\" \"%s.pcl.pcr\";\n",mName.c_str());}
	/*profile color green value*/
	void setProfileColorG(float pcg){if(pcg == 0.0) return; fprintf_s(mFile, "setAttr \".pcl.pcg\" %f;\n", pcg);}
	/*profile color green value*/
	void setProfileColorG(const FloatID& pcg){fprintf_s(mFile,"connectAttr \"");pcg.write(mFile);fprintf_s(mFile,"\" \"%s.pcl.pcg\";\n",mName.c_str());}
	/*profile color blue value*/
	void setProfileColorB(float pcb){if(pcb == 0.0) return; fprintf_s(mFile, "setAttr \".pcl.pcb\" %f;\n", pcb);}
	/*profile color blue value*/
	void setProfileColorB(const FloatID& pcb){fprintf_s(mFile,"connectAttr \"");pcb.write(mFile);fprintf_s(mFile,"\" \"%s.pcl.pcb\";\n",mName.c_str());}
	/*
	input color for creases
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	void setCreaseColor(const float3& ccl){fprintf_s(mFile, "setAttr \".ccl\" -type \"float3\" ");ccl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	input color for creases
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	void setCreaseColor(const Float3ID& ccl){fprintf_s(mFile,"connectAttr \"");ccl.write(mFile);fprintf_s(mFile,"\" \"%s.ccl\";\n",mName.c_str());}
	/*crease color red value*/
	void setCreaseColorR(float ccr){if(ccr == 0.0) return; fprintf_s(mFile, "setAttr \".ccl.ccr\" %f;\n", ccr);}
	/*crease color red value*/
	void setCreaseColorR(const FloatID& ccr){fprintf_s(mFile,"connectAttr \"");ccr.write(mFile);fprintf_s(mFile,"\" \"%s.ccl.ccr\";\n",mName.c_str());}
	/*crease color green value*/
	void setCreaseColorG(float ccg){if(ccg == 0.0) return; fprintf_s(mFile, "setAttr \".ccl.ccg\" %f;\n", ccg);}
	/*crease color green value*/
	void setCreaseColorG(const FloatID& ccg){fprintf_s(mFile,"connectAttr \"");ccg.write(mFile);fprintf_s(mFile,"\" \"%s.ccl.ccg\";\n",mName.c_str());}
	/*crease color blue value*/
	void setCreaseColorB(float ccb){if(ccb == 0.0) return; fprintf_s(mFile, "setAttr \".ccl.ccb\" %f;\n", ccb);}
	/*crease color blue value*/
	void setCreaseColorB(const FloatID& ccb){fprintf_s(mFile,"connectAttr \"");ccb.write(mFile);fprintf_s(mFile,"\" \"%s.ccl.ccb\";\n",mName.c_str());}
	/*
	input color for borders
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	void setBorderColor(const float3& bcl){fprintf_s(mFile, "setAttr \".bcl\" -type \"float3\" ");bcl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	input color for borders
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	void setBorderColor(const Float3ID& bcl){fprintf_s(mFile,"connectAttr \"");bcl.write(mFile);fprintf_s(mFile,"\" \"%s.bcl\";\n",mName.c_str());}
	/*border color red value*/
	void setBorderColorR(float bcr){if(bcr == 0.0) return; fprintf_s(mFile, "setAttr \".bcl.bcr\" %f;\n", bcr);}
	/*border color red value*/
	void setBorderColorR(const FloatID& bcr){fprintf_s(mFile,"connectAttr \"");bcr.write(mFile);fprintf_s(mFile,"\" \"%s.bcl.bcr\";\n",mName.c_str());}
	/*border color green value*/
	void setBorderColorG(float bcg){if(bcg == 0.0) return; fprintf_s(mFile, "setAttr \".bcl.bcg\" %f;\n", bcg);}
	/*border color green value*/
	void setBorderColorG(const FloatID& bcg){fprintf_s(mFile,"connectAttr \"");bcg.write(mFile);fprintf_s(mFile,"\" \"%s.bcl.bcg\";\n",mName.c_str());}
	/*border color blue value*/
	void setBorderColorB(float bcb){if(bcb == 0.0) return; fprintf_s(mFile, "setAttr \".bcl.bcb\" %f;\n", bcb);}
	/*border color blue value*/
	void setBorderColorB(const FloatID& bcb){fprintf_s(mFile,"connectAttr \"");bcb.write(mFile);fprintf_s(mFile,"\" \"%s.bcl.bcb\";\n",mName.c_str());}
	/*
	input color for intersections
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	void setIntersectionColor(const float3& icl){fprintf_s(mFile, "setAttr \".icl\" -type \"float3\" ");icl.write(mFile);fprintf_s(mFile,";\n");}
	/*
	input color for intersections
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	void setIntersectionColor(const Float3ID& icl){fprintf_s(mFile,"connectAttr \"");icl.write(mFile);fprintf_s(mFile,"\" \"%s.icl\";\n",mName.c_str());}
	/*intersection color red value*/
	void setIntersectionColorR(float icr){if(icr == 0.0) return; fprintf_s(mFile, "setAttr \".icl.icr\" %f;\n", icr);}
	/*intersection color red value*/
	void setIntersectionColorR(const FloatID& icr){fprintf_s(mFile,"connectAttr \"");icr.write(mFile);fprintf_s(mFile,"\" \"%s.icl.icr\";\n",mName.c_str());}
	/*intersection color green value*/
	void setIntersectionColorG(float icg){if(icg == 0.0) return; fprintf_s(mFile, "setAttr \".icl.icg\" %f;\n", icg);}
	/*intersection color green value*/
	void setIntersectionColorG(const FloatID& icg){fprintf_s(mFile,"connectAttr \"");icg.write(mFile);fprintf_s(mFile,"\" \"%s.icl.icg\";\n",mName.c_str());}
	/*intersection color blue value*/
	void setIntersectionColorB(float icb){if(icb == 0.0) return; fprintf_s(mFile, "setAttr \".icl.icb\" %f;\n", icb);}
	/*intersection color blue value*/
	void setIntersectionColorB(const FloatID& icb){fprintf_s(mFile,"connectAttr \"");icb.write(mFile);fprintf_s(mFile,"\" \"%s.icl.icb\";\n",mName.c_str());}
	/*
	The output profile color. This is currently a simple pass-through from
	the profile color.
	*/
	void setOutColor(const Float3ID& ocl){fprintf_s(mFile,"connectAttr \"");ocl.write(mFile);fprintf_s(mFile,"\" \"%s.ocl\";\n",mName.c_str());}
	/*The red component of the profile  output color.*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.ocr\";\n",mName.c_str());}
	/*The green component of the profile  output color.*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.ocg\";\n",mName.c_str());}
	/*The blue component of the profile  output color.*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.ocl.ocb\";\n",mName.c_str());}
	/*
	This is an output array of meshes matching the input meshes, but offset along the normal
	by the line width. By enabling opposite siding and backface removal these meshes create
	a profile outline about the original input meshes. Unlike pfx profile lines these lines
	are formed by the render of the two meshes, and do not need to be updated when the view
	changes. If offsetMeshProfile lines are not enabled then these output connections
	will evaluated to empty meshes.
	*/
	void setOutProfileMesh(size_t opm_i,const MeshID& opm){fprintf_s(mFile,"connectAttr \"");opm.write(mFile);fprintf_s(mFile,"\" \"%s.opm[%i]\";\n",mName.c_str(),opm_i);}
	/*
	This is the input multi-attribute for the surfaces getting toon outlines.
	Both the geometry and world matrix are connected.
	*/
	const InputSurfaceID& getInputSurface(size_t ins_i){char buffer[4096];sprintf_s (buffer, "%s.ins[%i]",mName.c_str(),ins_i);return (const char*)buffer;}
	/*Input mesh*/
	const MeshID& getSurface(size_t ins_i){char buffer[4096];sprintf_s (buffer, "%s.ins[%i].srf",mName.c_str(),ins_i);return (const char*)buffer;}
	/*Input matrix from mesh or surface*/
	const MatrixID& getInputWorldMatrix(size_t ins_i){char buffer[4096];sprintf_s (buffer, "%s.ins[%i].iwm",mName.c_str(),ins_i);return (const char*)buffer;}
	/*If on, then lines are displayed in the modelling viewports.*/
	BoolID getDisplayInViewport(){char buffer[4096];sprintf_s (buffer, "%s.div",mName.c_str());return (const char*)buffer;}
	/*
	If not off then lines are generated along the silhoutte of objects.
	If Paint Effects lines are used then curves following the outline are constructed.
	These lines are view relative and thus must are rebuilt when the view changes.
	If Offset Mesh is used, then a duplicate of the input mesh is constructed that is
	offset along the surface normal by the line width. By making this mesh both single sided
	and reversed a shell is formed that creates a silhoutte when rendered with the input mesh.
	This has the advantage of built in thick thin line properties that are stable when animated.
	It also has the advantage of not needing to be updated when the view changes. It will also
	appear in raytraced reflections and refractions.
	*/
	UnsignedintID getProfileLines(){char buffer[4096];sprintf_s (buffer, "%s.pln",mName.c_str());return (const char*)buffer;}
	/*If on, then lines are generated along internal hard edges.*/
	BoolID getCreaseLines(){char buffer[4096];sprintf_s (buffer, "%s.cln",mName.c_str());return (const char*)buffer;}
	/*
	This allows one to generated lines along boundaries.
	Open Edges are considered to be edges that are shared by only one face. This can
	be used to provide lines around the border of a simple plane, for example.
	Profile lines do not handle this sort of edge, which only occurs when the surface
	is not fully closed.
	Shader boundary edges are where the faces attached to the edge do not
	share the same shader.
	*/
	UnsignedintID getBorderLines(){char buffer[4096];sprintf_s (buffer, "%s.bln",mName.c_str());return (const char*)buffer;}
	/*If on, then lines are generated where surfaces intersect.*/
	BoolID getIntersectionLines(){char buffer[4096];sprintf_s (buffer, "%s.iln",mName.c_str());return (const char*)buffer;}
	/*If on, then lines are generated where surfaces intersect themselves.*/
	BoolID getSelfIntersect(){char buffer[4096];sprintf_s (buffer, "%s.sei",mName.c_str());return (const char*)buffer;}
	/*This controls the global width of the profile, crease and boundary lines.*/
	DoubleID getLineWidth(){char buffer[4096];sprintf_s (buffer, "%s.lwd",mName.c_str());return (const char*)buffer;}
	/*
	This attribute can be used to vary line width with a 2D texture map.
	This attributes scales the currently defined line width, but by 2 times the
	lineWidthMap value, so that a value of 0.5 has no effect. Where the texture
	value was 0.25 the line width would be half of the lineWidth attribute value and
	where the value is 1.0 the value would be double. Values outside the zero to one
	range can also be used( for file textures this generally requires increasing the
	alpha gain on the texture ).
	The texture is mapped into uv space of the surface the lines are on. In addition
	to thick and thin effects, one can also block line formation entirely in places by
	using a zero texture value. Note that 3D, projective 2D, and environment textures
	are not currently supported.
	*/
	DoubleID getLineWidthMap(){char buffer[4096];sprintf_s (buffer, "%s.lwm",mName.c_str());return (const char*)buffer;}
	/*
	This controls the opacity of the profile, crease and boundary lines.
	An opacity of 0 is fully transparent and an opacity of 1 is fully opaque.
	*/
	DoubleID getLineOpacity(){char buffer[4096];sprintf_s (buffer, "%s.lop",mName.c_str());return (const char*)buffer;}
	/*
	This attribute can be used to vary the line opacity with a 2D texture map.
	This attributes scales the currently defined line opacity, so where the texture
	value was 0.5 the line opacity would be half of the lineOpacity attribute value.
	The texture is mapped into uv space of the surface the lines are on.
	Note that 3D, projective 2D, and environment textures are not currently supported.
	*/
	DoubleID getLineOpacityMap(){char buffer[4096];sprintf_s (buffer, "%s.lpm",mName.c_str());return (const char*)buffer;}
	/*
	If Line Surface is used then lines will be clipped where they are hidden by the surface they are created from.
	If All Toon Surfaces is used then lines will be clipped where they are hidden by any of the surfaces that are
	currently assigned these toon lines.
	This occlusion is generally meant to augment the line occlusion by the normal paint effect render, or
	orther renders if convert toon to poly is used. With paint effects renders, the depthBias attribute may
	be useful when combined with local occlusion.
	*/
	UnsignedintID getLocalOcclusion(){char buffer[4096];sprintf_s (buffer, "%s.lcl",mName.c_str());return (const char*)buffer;}
	/*
	This is an amount in worldspace that lines are moved towards the camera when testing
	depth for local occlusion. A small value is required to avoid artifacts where the surface
	self occludes lines.
	*/
	DoubleID getOcclusionTolerance(){char buffer[4096];sprintf_s (buffer, "%s.otl",mName.c_str());return (const char*)buffer;}
	/*
	This is an amount in worldspace that lines are moved towards the camera when rendering.
	This is useful in avoiding artifacts with depth occlusion by the surface the lines are on.
	*/
	DoubleID getDepthBias(){char buffer[4096];sprintf_s (buffer, "%s.dbs",mName.c_str());return (const char*)buffer;}
	/*This is a relative scale of the width of the profile, or silhoutte lines.*/
	DoubleID getProfileLineWidth(){char buffer[4096];sprintf_s (buffer, "%s.plw",mName.c_str());return (const char*)buffer;}
	/*This is a relative scale of the width of the crease, or hard edge lines.*/
	DoubleID getCreaseLineWidth(){char buffer[4096];sprintf_s (buffer, "%s.clw",mName.c_str());return (const char*)buffer;}
	/*This is a relative scale of the width of the border, or boundary lines.*/
	DoubleID getBorderLineWidth(){char buffer[4096];sprintf_s (buffer, "%s.blw",mName.c_str());return (const char*)buffer;}
	/*This is a relative scale of the width of the intersection lines.*/
	DoubleID getIntersectionLineWidth(){char buffer[4096];sprintf_s (buffer, "%s.ilw",mName.c_str());return (const char*)buffer;}
	/*
	This offsets lines along the surface normal. The amount of offset is relative
	to the line width, a value of 1.0 having the line just touch the surface. With a
	value of 0 the line is half intersecting the surface.
	*/
	DoubleID getLineOffset(){char buffer[4096];sprintf_s (buffer, "%s.lof",mName.c_str());return (const char*)buffer;}
	/*
	This attribute can be used to vary line offset with a 2D texture map. If
	a noisy texture is used this can create a wiggly line.
	This attributes scales the currently defined line offset, so where the texture
	value was 0.5 the line offset would be half of the lineOffset attribute value.
	The texture is mapped into uv space of the surface the lines are on.
	Note that 3D, projective 2D, and environment textures
	are not currently supported.
	*/
	DoubleID getLineOffsetMap(){char buffer[4096];sprintf_s (buffer, "%s.lom",mName.c_str());return (const char*)buffer;}
	/*
	The width is scaled by the diffuse light
	intensity. Brighter regions will be thinner.
	Shadowed and dark regions will have full width
	tubes. Using negative values can have the reverse
	effect. The lighting used is a diffuse illumination
	that is relative to the local surface normal.
	*/
	DoubleID getLightingBasedWidth(){char buffer[4096];sprintf_s (buffer, "%s.lbw",mName.c_str());return (const char*)buffer;}
	/*
	<b>OcclusionWidthScale</b> is useful for avoiding aliasing artifacts
	along the inside edge of lines. The paint effects brush stamp radius is
	scaled down based on the average occlusion within the stamp region, rather
	than occluding each pixel of the stamp draw. This allows lines to have their
	center on the object's profile boundary. Otherwise the line on the inside
	edge gets occluded by the object, and thus only the outer half of the line
	is visible. Paint Effects relies on the the depth buffer from the scanline
	phase of the render for occlusion, however there is only one depth value
	per pixel, which creates a challenge for good antialiasing. Using
	Occlusion Width Scale gets around some of these aliasing problems, although
	very thick lines may in places bite into objects more than desired. Also
	in some unusual situations it may cause a blobby quality where there are
	sudden changes in occlusion. Note that if a brush is assigned the toon line,
	then the setting for occlusion width scale on the brush node will override
	the setting on the toon node.
	*/
	BoolID getOcclusionWidthScale(){char buffer[4096];sprintf_s (buffer, "%s.ows",mName.c_str());return (const char*)buffer;}
	/*
	This offsets profile lines along the view direction. This can help give lines
	a more graduated width where the profile is internal to the object.
	*/
	DoubleID getDepthOffset(){char buffer[4096];sprintf_s (buffer, "%s.dff",mName.c_str());return (const char*)buffer;}
	/*
	This is the start angle in degrees between faces beyond which creasing forms.
	Line thickness can be graduated between zero width at the min angle and
	going to full thickness at the max.
	At an angle of zero all edges will be drawn, if hardCreasesOnly is OFF.
	*/
	DoubleID getCreaseAngleMin(){char buffer[4096];sprintf_s (buffer, "%s.amn",mName.c_str());return (const char*)buffer;}
	/*
	This is the angle in degrees between faces beyond which crease line thickness
	is the maximum.
	At an angle of zero all edges will be drawn, if hardCreasesOnly is OFF.
	*/
	DoubleID getCreaseAngleMax(){char buffer[4096];sprintf_s (buffer, "%s.amx",mName.c_str());return (const char*)buffer;}
	/*If on, then creases are only generated along hardened edges.*/
	BoolID getHardCreasesOnly(){char buffer[4096];sprintf_s (buffer, "%s.hco",mName.c_str());return (const char*)buffer;}
	/*If on, then creases are generated on surfaces that face away from the view.*/
	BoolID getBackfacingCreases(){char buffer[4096];sprintf_s (buffer, "%s.bfc",mName.c_str());return (const char*)buffer;}
	/*
	This is the start angle in degrees between faces beyond which intersection lines form.
	Line thickness can be graduated between zero width at the min angle and
	going to full thickness at the max.
	At an angle of zero all intersecting edges will be drawn.
	By varying the min max intersection angle one can avoid lines along
	flush intersections, yet still have lines where the intersection angle
	is steeper.
	*/
	DoubleID getIntersectionAngleMin(){char buffer[4096];sprintf_s (buffer, "%s.imn",mName.c_str());return (const char*)buffer;}
	/*
	This is the angle in degrees between faces beyond which intersection line thickness
	is the maximum.
	At an angle of zero all intersection lines will be drawn at full thickness.
	*/
	DoubleID getIntersectionAngleMax(){char buffer[4096];sprintf_s (buffer, "%s.imx",mName.c_str());return (const char*)buffer;}
	/*
	If on then the profile is computed based on the interpolated normals.
	If off the profile curve will exist only on polygon edges. The off state guarantees that
	the profile will be always at the exact visible boundary, although it will jump in
	discreet steps as the view changes or the object deforms. With smooth profiles ON
	the profile changes in a smooth continuous fashion, but may creep in from edges in places
	where the surface is crudely triangulated.
	*/
	BoolID getSmoothProfile(){char buffer[4096];sprintf_s (buffer, "%s.spf",mName.c_str());return (const char*)buffer;}
	/*
	If on then smooth profiles will be a bit closer to the mesh profile edge, particularily
	in cases where the vertex normals do not match an edge orientation well. A primitive cone
	is a good example of this situation. Deriving the profile from the vertex normals does
	not work well in this case, because the normals define more of a hump than a pointed cone.
	For a cone the tighter profile method will push the profile about halfway closer to the
	the point of the cone. To fit closer than this, increase the subdivisions on the cone, or
	turn off smooth profile.
	*/
	BoolID getTighterProfile(){char buffer[4096];sprintf_s (buffer, "%s.tpf",mName.c_str());return (const char*)buffer;}
	/*
	This varies the width of lines relative to the 3d curvature of the line.
	When enabled the curvatureWidth graph controls how curvature affects line width.
	The input position sampled from the curvatureWidth graph is the the curvature,
	where the left of the graph is zero curvature( straight ) and the right is
	fully bent at a 180 degree angle. The output value of the graph (vertical position)
	is then used to determine a scale factor for the current width. Thus if the graph
	is a horizontal line with a value of 1.0 the line width is unchanged. Where the
	graph is zero the line width will be zero.
	*/
	BoolID getCurvatureModulation(){char buffer[4096];sprintf_s (buffer, "%s.cmo",mName.c_str());return (const char*)buffer;}
	/*
	When curvatureModulation is enabled the curvatureWidth graph controls
	how curvature affects line width.
	The input position sampled from the curvatureWidth graph is the the curvature,
	where the left of the graph is zero curvature( straight ) and the right is
	fully bent at a 180 degree angle. The output value of the graph (vertical position)
	is then used to determine a scale factor for the current width. Thus if the graph
	is a horizontal line with a value of 1.0 the line width is unchanged. Where the
	graph is zero the line width will be zero.
	*/
	const CurvatureWidthID& getCurvatureWidth(size_t cwd_i){char buffer[4096];sprintf_s (buffer, "%s.cwd[%i]",mName.c_str(),cwd_i);return (const char*)buffer;}
	/*Position of ramp value on normalized 0-1 scale*/
	const FloatID& getCurvatureWidth_Position(size_t cwd_i){char buffer[4096];sprintf_s (buffer, "%s.cwd[%i].cwdp",mName.c_str(),cwd_i);return (const char*)buffer;}
	/*Ramp value at the sibling position*/
	const FloatID& getCurvatureWidth_FloatValue(size_t cwd_i){char buffer[4096];sprintf_s (buffer, "%s.cwd[%i].cwdfv",mName.c_str(),cwd_i);return (const char*)buffer;}
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
	const UnsignedintID& getCurvatureWidth_Interp(size_t cwd_i){char buffer[4096];sprintf_s (buffer, "%s.cwd[%i].cwdi",mName.c_str(),cwd_i);return (const char*)buffer;}
	/*This varies the width of lines relative to the view angle.*/
	DoubleID getProfileWidthModulation(){char buffer[4096];sprintf_s (buffer, "%s.pwm",mName.c_str());return (const char*)buffer;}
	/*This varies the width of lines relative to the view angle.*/
	DoubleID getCreaseWidthModulation(){char buffer[4096];sprintf_s (buffer, "%s.cwm",mName.c_str());return (const char*)buffer;}
	/*This varies the width of lines relative to the view angle.*/
	DoubleID getBorderWidthModulation(){char buffer[4096];sprintf_s (buffer, "%s.bwm",mName.c_str());return (const char*)buffer;}
	/*This varies the width of lines relative to the view angle.*/
	DoubleID getIntersectionWidthModulation(){char buffer[4096];sprintf_s (buffer, "%s.imd",mName.c_str());return (const char*)buffer;}
	/*
	This is the angle in degrees beyond which profile lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	DoubleID getProfileBreakAngle(){char buffer[4096];sprintf_s (buffer, "%s.pba",mName.c_str());return (const char*)buffer;}
	/*
	This is the angle in degrees beyond which crease lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	DoubleID getCreaseBreakAngle(){char buffer[4096];sprintf_s (buffer, "%s.cba",mName.c_str());return (const char*)buffer;}
	/*
	This is the angle in degrees beyond which border lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	DoubleID getBorderBreakAngle(){char buffer[4096];sprintf_s (buffer, "%s.bba",mName.c_str());return (const char*)buffer;}
	/*
	This is the angle in degrees beyond which intersection lines are broken.
	Line segments that are less than this angle with respect to each other are
	joined into lines. At a value of 0 all lines will be only one segment long.
	At a value of 180 all adjacent segments will be joined together into lines.
	*/
	DoubleID getIntersectionBreakAngle(){char buffer[4096];sprintf_s (buffer, "%s.iba",mName.c_str());return (const char*)buffer;}
	/*This will removes borders where meshes touch and have matching normals.*/
	BoolID getRemoveFlushBorders(){char buffer[4096];sprintf_s (buffer, "%s.rfb",mName.c_str());return (const char*)buffer;}
	/*
	This is the max distance boundary cvs can be from each other when suppressing
	flush or common border lines.
	*/
	DoubleID getFlushTolerance(){char buffer[4096];sprintf_s (buffer, "%s.tfl",mName.c_str());return (const char*)buffer;}
	/*
	This is the max angle in degrees that boundary vertex normals can be from
	each other when suppressing flush or common border lines.
	*/
	DoubleID getFlushAngleMax(){char buffer[4096];sprintf_s (buffer, "%s.fmx",mName.c_str());return (const char*)buffer;}
	/*
	This controls the distance from line ends beyond which they become fully thick.
	Depending on the object one may need to lower the Break Angle values in order to
	see open line ends. For most surfaces the profile lines form closed lines with no
	open ends. The continuation of the profile is sometimes hidden where it goes behind
	the object. It may thus look like it has open ends event though it is closed and will
	thus not show the effect of line end thinning. Crease lines are more likely to show
	open ends than profiles or borders. One can use the break angles to create open ends
	where the line curves strongly.
	*/
	DoubleID getLineEndThinning(){char buffer[4096];sprintf_s (buffer, "%s.let",mName.c_str());return (const char*)buffer;}
	/*
	This extends the ends of lines so they cross at corners rather than simply intersecting.
	Line Extend simulates a pencil drafting style of line.
	Depending on the object one may need to lower the Break Angle values in order to
	see open line ends. For most surfaces the profile lines form closed lines with no
	open ends. The continuation of the profile is sometimes hidden where it goes behind
	the object. It may thus look like it has open ends event though it is closed and will
	thus not show the effect of Line Extend. Crease lines are more likely to show
	open ends than profiles or borders. One can use the break angles to create open ends
	where the line curves strongly.
	*/
	DoubleID getLineExtend(){char buffer[4096];sprintf_s (buffer, "%s.lex",mName.c_str());return (const char*)buffer;}
	/*
	The points along the profile are typically spaced at irregular distances, depending
	on the surface geometry. This is especially noticable if one assigns a brush with tubes ON
	to the toon line, where the tubes will jump around as the scene is animated. Enabling this
	causes the profile lines to be resampled at a uniform cv spacing, resulting in smoother
	strokes that jump less. The resample spacing needs to be small enough to avoid rounding
	corner edges.
	*/
	BoolID getResampleProfile(){char buffer[4096];sprintf_s (buffer, "%s.rpf",mName.c_str());return (const char*)buffer;}
	/*
	The points along the crease are normally spaced according to the size of poly edges. For simple objects
	this may not provide enough cvs for effects like line end thinning. Resample crease provides the ability
	to sample the crease lines with fewer or more cvs, as well as to fix the worldspace distance between
	curve cvs. Note that this may make crease lines twitch when animated if screenspace resampling is not zero.
	The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	BoolID getResampleCrease(){char buffer[4096];sprintf_s (buffer, "%s.rcr",mName.c_str());return (const char*)buffer;}
	/*
	The points along the border are normally spaced according to the size of poly edges. For simple objects
	this may not provide enough cvs for effects like line end thinning. Resample border provides the ability
	to sample the border lines with fewer or more cvs, as well as to fix the worldspace distance between
	curve cvs. Note that this may make border lines twitch when animated if screenspace resampling is not zero.
	The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	BoolID getResampleBorder(){char buffer[4096];sprintf_s (buffer, "%s.rbd",mName.c_str());return (const char*)buffer;}
	/*
	The points along the intersection are typically spaced at irregular distances. This is do to the way
	that triangles overlap along the edge. This is especially noticable if one assigns a brush with tubes ON
	to the toon line, where the tubes will jump around as the scene is animated. Enabling Resample Intersection
	causes the profile lines to be resampled at a uniform cv spacing, resulting in smoother
	strokes that jump less. The resample spacing needs to be small enough to avoid rounding corner edges.
	*/
	BoolID getResampleIntersection(){char buffer[4096];sprintf_s (buffer, "%s.rin",mName.c_str());return (const char*)buffer;}
	/*
	This is a maximum distance that is allowed between cvs on
	profiles when resample profile is ON. If this is small there
	may be many cvs on a profile curve. If this value is very large
	the profile curve will have its original number of cvs, but uniformly
	distributed across the original curve. One may have rounded corners
	if the max segment length is not low enough.
	*/
	DoubleID getMaxSegmentLength(){char buffer[4096];sprintf_s (buffer, "%s.msl",mName.c_str());return (const char*)buffer;}
	/*
	This is the smallest distance that is allowed between cvs on
	profiles when resample profile is ON. If this is large the
	profile curve may be very crudely sampled. It is useful if one
	wants an output, for example to polymesh, where the number of segments
	is kept to a minimum. Also when combined with screenspace resampling it
	can be used to simplify distant profiles.
	*/
	DoubleID getMinSegmentLength(){char buffer[4096];sprintf_s (buffer, "%s.mns",mName.c_str());return (const char*)buffer;}
	/*
	This controls the degree to which outline curve resampling is
	done in screenspace. When this is 1.0 the segments will be a fixed
	distance apart in screenspace. When it is 0.0 the distances are fixed in
	worldspace. Between 1.0 and 0.0 these two sampling methods are interpolated.
	This can be used to have profile curves become simpler with distance. Also if
	one has a brush with tubes = on assigned to the toon line the number of tubes
	will reduce with distance when this is greater than zero.
	*/
	DoubleID getScreenSpaceResampling(){char buffer[4096];sprintf_s (buffer, "%s.ssr",mName.c_str());return (const char*)buffer;}
	/*
	If this is ON then each curve is given a new random seed for paint effects.
	This requires that one have a pfx brush with tubes=ON assigned to the toon line.
	Profiles line tubes may jump around if this is ON when animated.
	*/
	BoolID getPfxRandomize(){char buffer[4096];sprintf_s (buffer, "%s.prz",mName.c_str());return (const char*)buffer;}
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
	/*
	input color for profiles
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	Float3ID getProfileColor(){char buffer[4096];sprintf_s (buffer, "%s.pcl",mName.c_str());return (const char*)buffer;}
	/*profile color red value*/
	FloatID getProfileColorR(){char buffer[4096];sprintf_s (buffer, "%s.pcl.pcr",mName.c_str());return (const char*)buffer;}
	/*profile color green value*/
	FloatID getProfileColorG(){char buffer[4096];sprintf_s (buffer, "%s.pcl.pcg",mName.c_str());return (const char*)buffer;}
	/*profile color blue value*/
	FloatID getProfileColorB(){char buffer[4096];sprintf_s (buffer, "%s.pcl.pcb",mName.c_str());return (const char*)buffer;}
	/*
	input color for creases
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	Float3ID getCreaseColor(){char buffer[4096];sprintf_s (buffer, "%s.ccl",mName.c_str());return (const char*)buffer;}
	/*crease color red value*/
	FloatID getCreaseColorR(){char buffer[4096];sprintf_s (buffer, "%s.ccl.ccr",mName.c_str());return (const char*)buffer;}
	/*crease color green value*/
	FloatID getCreaseColorG(){char buffer[4096];sprintf_s (buffer, "%s.ccl.ccg",mName.c_str());return (const char*)buffer;}
	/*crease color blue value*/
	FloatID getCreaseColorB(){char buffer[4096];sprintf_s (buffer, "%s.ccl.ccb",mName.c_str());return (const char*)buffer;}
	/*
	input color for borders
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	Float3ID getBorderColor(){char buffer[4096];sprintf_s (buffer, "%s.bcl",mName.c_str());return (const char*)buffer;}
	/*border color red value*/
	FloatID getBorderColorR(){char buffer[4096];sprintf_s (buffer, "%s.bcl.bcr",mName.c_str());return (const char*)buffer;}
	/*border color green value*/
	FloatID getBorderColorG(){char buffer[4096];sprintf_s (buffer, "%s.bcl.bcg",mName.c_str());return (const char*)buffer;}
	/*border color blue value*/
	FloatID getBorderColorB(){char buffer[4096];sprintf_s (buffer, "%s.bcl.bcb",mName.c_str());return (const char*)buffer;}
	/*
	input color for intersections
	This may be textured with 2D textures. The line color is then
	derived based on the color of the texture mapped to the surface.
	Note that 3D, projective 2D, and environment textures
	are not currently supported, however one could convert the toon
	lines to a poly mesh then apply a shader with 3D textures to the
	result.
	*/
	Float3ID getIntersectionColor(){char buffer[4096];sprintf_s (buffer, "%s.icl",mName.c_str());return (const char*)buffer;}
	/*intersection color red value*/
	FloatID getIntersectionColorR(){char buffer[4096];sprintf_s (buffer, "%s.icl.icr",mName.c_str());return (const char*)buffer;}
	/*intersection color green value*/
	FloatID getIntersectionColorG(){char buffer[4096];sprintf_s (buffer, "%s.icl.icg",mName.c_str());return (const char*)buffer;}
	/*intersection color blue value*/
	FloatID getIntersectionColorB(){char buffer[4096];sprintf_s (buffer, "%s.icl.icb",mName.c_str());return (const char*)buffer;}
	/*
	The output profile color. This is currently a simple pass-through from
	the profile color.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.ocl",mName.c_str());return (const char*)buffer;}
	/*The red component of the profile  output color.*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.ocl.ocr",mName.c_str());return (const char*)buffer;}
	/*The green component of the profile  output color.*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.ocl.ocg",mName.c_str());return (const char*)buffer;}
	/*The blue component of the profile  output color.*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.ocl.ocb",mName.c_str());return (const char*)buffer;}
	/*
	This is an output array of meshes matching the input meshes, but offset along the normal
	by the line width. By enabling opposite siding and backface removal these meshes create
	a profile outline about the original input meshes. Unlike pfx profile lines these lines
	are formed by the render of the two meshes, and do not need to be updated when the view
	changes. If offsetMeshProfile lines are not enabled then these output connections
	will evaluated to empty meshes.
	*/
	const MeshID& getOutProfileMesh(size_t opm_i){char buffer[4096];sprintf_s (buffer, "%s.opm[%i]",mName.c_str(),opm_i);return (const char*)buffer;}
protected:
	PfxToon(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PfxGeometry(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PFXTOON_H__
