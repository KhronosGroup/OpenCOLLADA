/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

namespace COLLADAFW
{

    const String RenderState::CG_RENDER_STATE_NAMES[] = {
        "AlphaFunc",
        "AlphaTestEnable",
        "AutoNormalEnable",

        "BlendFunc",
        "BlendFuncSeparate",
        "BlendEquation",
        "BlendEquationSeparate",
        "BlendColor",
        "BlendEnable",

        "ClearColor",
        "ClearStencil",
        "ClearDepth",
        "ClipPlane",
        "ColorMask",
        "ColorMatrix",
        "ColorMaterial",
        "CullFace",
        "ClipPlaneEnable",
        "ColorLogicOpEnable",
        "CullFaceEnable",

        "DepthBounds",
        "DepthFunc",
        "DepthMask",
        "DepthRange",
        "DepthBoundsEnable",
        "DepthClampEnable",
        "DepthTestEnable",
        "DitherEnable",

        "FogMode",
        "FogEnable",
        "FogDensity",
        "FogStart",
        "FogEnd",
        "FogColor",
        "FragmentEnvParameter",
        "FragmentLocalParameter",
        "FogCoordSrc",
        "FogDistanceMode",
        "FragmentProgram",
        "FrontFace",

        "LightModelAmbient",
        "LightAmbient",
        "LightDiffuse",
        "LightSpecular",
        "LightConstantAttenuation",
        "LightLinearAttenuation",
        "LightQuadraticAttenuation",
        "LightPosition",
        "LightSpotCutoff",
        "LightSpotDirection",
        "LightSpotExponent",
        "LightModelColorControl",
        "LineStipple",
        "LineWidth",
        "LogicOp",
        "LogicOpEnable",
        "LightEnable",
        "LightingEnable",
        "LightModelLocalViewerEnable",
        "LightModelTwoSideEnable",
        "LineSmoothEnable",
        "LineStippleEnable",

        "MaterialAmbient",
        "MaterialDiffuse",
        "MaterialEmission",
        "MaterialShininess",
        "MaterialSpecular",
        "ModelViewMatrix",
        "MultisampleEnable",

        "NormalizeEnable",

        "PointDistanceAttenuation",
        "PointFadeThresholdSize",
        "PointSize",
        "PointSizeMin",
        "PointSizeMax",
        "PointSpriteCoordOrigin",
        "PointSpriteCoordReplace",
        "PointSpriteRMode",
        "PolygonMode",
        "PolygonOffset",
        "ProjectionMatrix",
        "PointSmoothEnable",
        "PointSpriteEnable",
        "PolygonOffsetFillEnable",
        "PolygonOffsetLineEnable",
        "PolygonOffsetPointEnable",
        "PolygonSmoothEnable",
        "PolygonStippleEnable",

        "RescaleNormalEnable",

        "Scissor",
        "ShadeModel",
        "StencilFunc",
        "StencilMask",
        "StencilOp",
        "StencilFuncSeparate",
        "StencilMaskSeparate",
        "StencilOpSeparate",
        "SampleAlphaToCoverageEnable",
        "SampleAlphaToOneEnable",
        "SampleCoverageEnable",
        "ScissorTestEnable",
        "StencilTestEnable",

        "TexGenSMode",
        "TexGenTMode",
        "TexGenRMode",
        "TexGenQMode",
        "TexGenSEyePlane",
        "TexGenTEyePlane",
        "TexGenREyePlane",
        "TexGenQEyePlane",
        "TexGenSObjectPlace",
        "TexGenTObjectPlace",
        "TexGenRObjectPlace",
        "TexGenQObjectPlace",
        "Texture1D",
        "Texture2D",
        "Texture3D",
        "TextureRectangle",
        "TextureCubeMap",
        "TextureEnvColor",
        "TextureEnvMode",
        "TexGenSEnable",
        "TexGenTEnable",
        "TexGenREnable",
        "TexGenQEnable",
        "Texture1DEnable",
        "Texture2DEnable",
        "Texture3DEnable",
        "TextureRectangleEnable",
        "TextureCubeMapEnable",

        "VertexEnvParameter",
        "VertexLocalParameter",
        "VertexProgram"
    };

    const RenderState::PassState RenderState::CG_RENDER_STATES_XREF[] = {
        RenderState::ALPHA_FUNC, //AlphaFunc
        RenderState::ALPHA_TEST_ENABLE, //AlphaTestEnable
        RenderState::AUTO_NORMAL_ENABLE, //AutoNormalEnable

        RenderState::BLEND_FUNC, //BlendFunc
        RenderState::BLEND_FUNC_SEPARATE, //BlendFuncSeparate
        RenderState::BLEND_EQUATION, //BlendEquation
        RenderState::BLEND_EQUATION_SEPARATE, //BlendEquationSeparate
        RenderState::BLEND_COLOR, //BlendColor
        RenderState::BLEND_ENABLE, //BlendEnable

        RenderState::CLEAR_COLOR, //ClearColor
        RenderState::CLEAR_STENCIL, //ClearStencil
        RenderState::CLEAR_DEPTH, //ClearDepth
        RenderState::CLIP_PLANE, //ClipPlane
        RenderState::COLOR_MASK, //ColorMask
        RenderState::PASS_STATE_INVALID, //ColorMatrix
        RenderState::COLOR_MATERIAL, //ColorMaterial
        RenderState::CULL_FACE, //CullFace
        RenderState::CLIP_PLANE_ENABLE, //ClipPlaneEnable
        RenderState::COLOR_LOGIC_OP_ENABLE, //ColorLogicOpEnable
        RenderState::CULL_FACE_ENABLE, //CullFaceEnable

        RenderState::DEPTH_BOUNDS, //DepthBounds
        RenderState::DEPTH_FUNC, //DepthFunc
        RenderState::DEPTH_MASK, //DepthMask
        RenderState::DEPTH_RANGE, //DepthRange
        RenderState::DEPTH_BOUNDS_ENABLE, //DepthBoundsEnable
        RenderState::DEPTH_CLAMP_ENABLE, //DepthClampEnable
        RenderState::DEPTH_TEST_ENABLE, //DepthTestEnable
        RenderState::DITHER_ENABLE, //DitherEnable

        RenderState::FOG_MODE, //FogMode
        RenderState::FOG_ENABLE, //FogEnable
        RenderState::FOG_DENSITY, //FogDensity
        RenderState::FOG_START, //FogStart
        RenderState::FOG_END, //FogEnd
        RenderState::FOG_COLOR, //FogColor
        RenderState::PASS_STATE_INVALID, //FragmentEnvParameter
        RenderState::PASS_STATE_INVALID, //FragmentLocalParameter
        RenderState::FOG_COORD_SRC, //FogCoordSrc
        RenderState::PASS_STATE_INVALID, //FogDistanceMode
        RenderState::PASS_STATE_INVALID, //FragmentProgram
        RenderState::FRONT_FACE, //FrontFace

        RenderState::LIGHT_MODEL_AMBIENT, //LightModelAmbient
        RenderState::LIGHT_AMBIENT, //LightAmbient
        RenderState::LIGHT_DIFFUSE, //LightDiffuse
        RenderState::LIGHT_SPECULAR, //LightSpecular
        RenderState::LIGHT_CONSTANT_ATTENUATION, //LightConstantAttenuation
        RenderState::LIGHT_LINEAR_ATTENUATION, //LightLinearAttenuation
        RenderState::LIGHT_QUADRATIC_ATTENUATION, //LightQuadraticAttenuation
        RenderState::LIGHT_POSITION, //LightPosition
        RenderState::LIGHT_SPOT_CUTOFF, //LightSpotCutoff
        RenderState::LIGHT_SPOT_DIRECTION, //LightSpotDirection
        RenderState::LIGHT_SPOT_EXPONENT, //LightSpotExponent
        RenderState::LIGHT_MODEL_COLOR_CONTROL, //LightModelColorControl
        RenderState::LINE_STIPPLE, //LineStipple
        RenderState::LINE_WIDTH, //LineWidth
        RenderState::LOGIC_OP, //LogicOp
        RenderState::LOGIC_OP_ENABLE, //LogicOpEnable
        RenderState::LIGHT_ENABLE, //LightEnable
        RenderState::LIGHTING_ENABLE, //LightingEnable
        RenderState::LIGHT_MODEL_LOCAL_VIEWER_ENABLE, //LightModelLocalViewerEnable
        RenderState::LIGHT_MODEL_TWO_SIDE_ENABLE, //LightModelTwoSideEnable
        RenderState::LINE_SMOOTH_ENABLE, //LineSmoothEnable
        RenderState::LINE_STIPPLE_ENABLE, //LineStippleEnable

        RenderState::MATERIAL_AMBIENT, //MaterialAmbient
        RenderState::MATERIAL_DIFFUSE, //MaterialDiffuse
        RenderState::MATERIAL_EMISSION, //MaterialEmission
        RenderState::MATERIAL_SHININESS, //MaterialShininess
        RenderState::MATERIAL_SPECULAR, //MaterialSpecular
        RenderState::MODEL_VIEW_MATRIX, //ModelViewMatrix
        RenderState::MULTISAMPLE_ENABLE, //MultisampleEnable

        RenderState::NORMALIZE_ENABLE, //NormalizeEnable

        RenderState::POINT_DISTANCE_ATTENUATION, //PointDistanceAttenuation
        RenderState::POINT_FADE_THRESHOLD_SIZE, //PointFadeThresholdSize
        RenderState::POINT_SIZE, //PointSize
        RenderState::POINT_SIZE_MIN, //PointSizeMin
        RenderState::POINT_SIZE_MAX, //PointSizeMax
        RenderState::PASS_STATE_INVALID, //PointSpriteCoordOrigin
        RenderState::PASS_STATE_INVALID, //PointSpriteCoordReplace
        RenderState::PASS_STATE_INVALID, //PointSpriteRMode
        RenderState::POLYGON_MODE, //PolygonMode
        RenderState::POLYGON_OFFSET, //PolygonOffset
        RenderState::PROJECTION_MATRIX, //ProjectionMatrix
        RenderState::POINT_SMOOTH_ENABLE, //PointSmoothEnable
        RenderState::PASS_STATE_INVALID, //PointSpriteEnable
        RenderState::POLYGON_OFFSET_FILL_ENABLE, //PolygonOffsetFillEnable
        RenderState::POLYGON_OFFSET_LINE_ENABLE, //PolygonOffsetLineEnable
        RenderState::POLYGON_OFFSET_POINT_ENABLE, //PolygonOffsetPointEnable
        RenderState::POLYGON_SMOOTH_ENABLE, //PolygonSmoothEnable
        RenderState::POLYGON_STIPPLE_ENABLE, //PolygonStippleEnable

        RenderState::RESCALE_NORMAL_ENABLE, //RescaleNormalEnable

        RenderState::SCISSOR, //Scissor
        RenderState::SHADE_MODEL, //ShadeModel
        RenderState::STENCIL_FUNC, //StencilFunc
        RenderState::STENCIL_MASK, //StencilMask
        RenderState::STENCIL_OP, //StencilOp
        RenderState::STENCIL_FUNC_SEPARATE, //StencilFuncSeparate
        RenderState::STENCIL_MASK_SEPARATE, //StencilMaskSeparate
        RenderState::STENCIL_OP_SEPARATE, //StencilOpSeparate
        RenderState::SAMPLE_ALPHA_TO_COVERAGE_ENABLE, //SampleAlphaToCoverageEnable
        RenderState::SAMPLE_ALPHA_TO_ONE_ENABLE, //SampleAlphaToOneEnable
        RenderState::SAMPLE_COVERAGE_ENABLE, //SampleCoverageEnable
        RenderState::SCISSOR_TEST_ENABLE, //ScissorTestEnable
        RenderState::STENCIL_TEST_ENABLE, //StencilTestEnable

        RenderState::PASS_STATE_INVALID, //TexGenSMode
        RenderState::PASS_STATE_INVALID, //TexGenTMode
        RenderState::PASS_STATE_INVALID, //TexGenRMode
        RenderState::PASS_STATE_INVALID, //TexGenQMode
        RenderState::PASS_STATE_INVALID, //TexGenSEyePlane
        RenderState::PASS_STATE_INVALID, //TexGenTEyePlane
        RenderState::PASS_STATE_INVALID, //TexGenREyePlane
        RenderState::PASS_STATE_INVALID, //TexGenQEyePlane
        RenderState::PASS_STATE_INVALID, //TexGenSObjectPlace
        RenderState::PASS_STATE_INVALID, //TexGenTObjectPlace
        RenderState::PASS_STATE_INVALID, //TexGenRObjectPlace
        RenderState::PASS_STATE_INVALID, //TexGenQObjectPlace
        RenderState::TEXTURE1D, //Texture1D
        RenderState::TEXTURE2D, //Texture2D
        RenderState::TEXTURE3D, //Texture3D
        RenderState::TEXTURERECT, //TextureRectangle
        RenderState::TEXTURECUBE, //TextureCubeMap
        RenderState::TEXTURE_ENV_COLOR, //TextureEnvColor
        RenderState::TEXTURE_ENV_MODE, //TextureEnvMode
        RenderState::PASS_STATE_INVALID, //TexGenSEnable
        RenderState::PASS_STATE_INVALID, //TexGenTEnable
        RenderState::PASS_STATE_INVALID, //TexGenREnable
        RenderState::PASS_STATE_INVALID, //TexGenQEnable
        RenderState::TEXTURE1D_ENABLE, //Texture1DEnable
        RenderState::TEXTURE2D_ENABLE, //Texture2DEnable
        RenderState::TEXTURE3D_ENABLE, //Texture3DEnable
        RenderState::TEXTURERECT_ENABLE, //TextureRectangleEnable
        RenderState::TEXTURECUBE_ENABLE, //TextureCubeMapEnable

        RenderState::PASS_STATE_INVALID, //VertexEnvParameter
        RenderState::PASS_STATE_INVALID, //VertexLocalParameter
        RenderState::PASS_STATE_INVALID, //VertexProgram
    };

}

