/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

namespace COLLADA
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

    const PassState::State RenderState::CG_RENDER_STATES_XREF[] = {
        PassState::ALPHA_FUNC, //AlphaFunc
        PassState::ALPHA_TEST_ENABLE, //AlphaTestEnable
        PassState::AUTO_NORMAL_ENABLE, //AutoNormalEnable

        PassState::BLEND_FUNC, //BlendFunc
        PassState::BLEND_FUNC_SEPARATE, //BlendFuncSeparate
        PassState::BLEND_EQUATION, //BlendEquation
        PassState::BLEND_EQUATION_SEPARATE, //BlendEquationSeparate
        PassState::BLEND_COLOR, //BlendColor
        PassState::BLEND_ENABLE, //BlendEnable

        PassState::CLEAR_COLOR, //ClearColor
        PassState::CLEAR_STENCIL, //ClearStencil
        PassState::CLEAR_DEPTH, //ClearDepth
        PassState::CLIP_PLANE, //ClipPlane
        PassState::COLOR_MASK, //ColorMask
        PassState::INVALID, //ColorMatrix
        PassState::COLOR_MATERIAL, //ColorMaterial
        PassState::CULL_FACE, //CullFace
        PassState::CLIP_PLANE_ENABLE, //ClipPlaneEnable
        PassState::COLOR_LOGIC_OP_ENABLE, //ColorLogicOpEnable
        PassState::CULL_FACE_ENABLE, //CullFaceEnable

        PassState::DEPTH_BOUNDS, //DepthBounds
        PassState::DEPTH_FUNC, //DepthFunc
        PassState::DEPTH_MASK, //DepthMask
        PassState::DEPTH_RANGE, //DepthRange
        PassState::DEPTH_BOUNDS_ENABLE, //DepthBoundsEnable
        PassState::DEPTH_CLAMP_ENABLE, //DepthClampEnable
        PassState::DEPTH_TEST_ENABLE, //DepthTestEnable
        PassState::DITHER_ENABLE, //DitherEnable

        PassState::FOG_MODE, //FogMode
        PassState::FOG_ENABLE, //FogEnable
        PassState::FOG_DENSITY, //FogDensity
        PassState::FOG_START, //FogStart
        PassState::FOG_END, //FogEnd
        PassState::FOG_COLOR, //FogColor
        PassState::INVALID, //FragmentEnvParameter
        PassState::INVALID, //FragmentLocalParameter
        PassState::FOG_COORD_SRC, //FogCoordSrc
        PassState::INVALID, //FogDistanceMode
        PassState::INVALID, //FragmentProgram
        PassState::FRONT_FACE, //FrontFace

        PassState::LIGHT_MODEL_AMBIENT, //LightModelAmbient
        PassState::LIGHT_AMBIENT, //LightAmbient
        PassState::LIGHT_DIFFUSE, //LightDiffuse
        PassState::LIGHT_SPECULAR, //LightSpecular
        PassState::LIGHT_CONSTANT_ATTENUATION, //LightConstantAttenuation
        PassState::LIGHT_LINEAR_ATTENUATION, //LightLinearAttenuation
        PassState::LIGHT_QUADRATIC_ATTENUATION, //LightQuadraticAttenuation
        PassState::LIGHT_POSITION, //LightPosition
        PassState::LIGHT_SPOT_CUTOFF, //LightSpotCutoff
        PassState::LIGHT_SPOT_DIRECTION, //LightSpotDirection
        PassState::LIGHT_SPOT_EXPONENT, //LightSpotExponent
        PassState::LIGHT_MODEL_COLOR_CONTROL, //LightModelColorControl
        PassState::LINE_STIPPLE, //LineStipple
        PassState::LINE_WIDTH, //LineWidth
        PassState::LOGIC_OP, //LogicOp
        PassState::LOGIC_OP_ENABLE, //LogicOpEnable
        PassState::LIGHT_ENABLE, //LightEnable
        PassState::LIGHTING_ENABLE, //LightingEnable
        PassState::LIGHT_MODEL_LOCAL_VIEWER_ENABLE, //LightModelLocalViewerEnable
        PassState::LIGHT_MODEL_TWO_SIDE_ENABLE, //LightModelTwoSideEnable
        PassState::LINE_SMOOTH_ENABLE, //LineSmoothEnable
        PassState::LINE_STIPPLE_ENABLE, //LineStippleEnable

        PassState::MATERIAL_AMBIENT, //MaterialAmbient
        PassState::MATERIAL_DIFFUSE, //MaterialDiffuse
        PassState::MATERIAL_EMISSION, //MaterialEmission
        PassState::MATERIAL_SHININESS, //MaterialShininess
        PassState::MATERIAL_SPECULAR, //MaterialSpecular
        PassState::MODEL_VIEW_MATRIX, //ModelViewMatrix
        PassState::MULTISAMPLE_ENABLE, //MultisampleEnable

        PassState::NORMALIZE_ENABLE, //NormalizeEnable

        PassState::POINT_DISTANCE_ATTENUATION, //PointDistanceAttenuation
        PassState::POINT_FADE_THRESHOLD_SIZE, //PointFadeThresholdSize
        PassState::POINT_SIZE, //PointSize
        PassState::POINT_SIZE_MIN, //PointSizeMin
        PassState::POINT_SIZE_MAX, //PointSizeMax
        PassState::INVALID, //PointSpriteCoordOrigin
        PassState::INVALID, //PointSpriteCoordReplace
        PassState::INVALID, //PointSpriteRMode
        PassState::POLYGON_MODE, //PolygonMode
        PassState::POLYGON_OFFSET, //PolygonOffset
        PassState::PROJECTION_MATRIX, //ProjectionMatrix
        PassState::POINT_SMOOTH_ENABLE, //PointSmoothEnable
        PassState::INVALID, //PointSpriteEnable
        PassState::POLYGON_OFFSET_FILL_ENABLE, //PolygonOffsetFillEnable
        PassState::POLYGON_OFFSET_LINE_ENABLE, //PolygonOffsetLineEnable
        PassState::POLYGON_OFFSET_POINT_ENABLE, //PolygonOffsetPointEnable
        PassState::POLYGON_SMOOTH_ENABLE, //PolygonSmoothEnable
        PassState::POLYGON_STIPPLE_ENABLE, //PolygonStippleEnable

        PassState::RESCALE_NORMAL_ENABLE, //RescaleNormalEnable

        PassState::SCISSOR, //Scissor
        PassState::SHADE_MODEL, //ShadeModel
        PassState::STENCIL_FUNC, //StencilFunc
        PassState::STENCIL_MASK, //StencilMask
        PassState::STENCIL_OP, //StencilOp
        PassState::STENCIL_FUNC_SEPARATE, //StencilFuncSeparate
        PassState::STENCIL_MASK_SEPARATE, //StencilMaskSeparate
        PassState::STENCIL_OP_SEPARATE, //StencilOpSeparate
        PassState::SAMPLE_ALPHA_TO_COVERAGE_ENABLE, //SampleAlphaToCoverageEnable
        PassState::SAMPLE_ALPHA_TO_ONE_ENABLE, //SampleAlphaToOneEnable
        PassState::SAMPLE_COVERAGE_ENABLE, //SampleCoverageEnable
        PassState::SCISSOR_TEST_ENABLE, //ScissorTestEnable
        PassState::STENCIL_TEST_ENABLE, //StencilTestEnable

        PassState::INVALID, //TexGenSMode
        PassState::INVALID, //TexGenTMode
        PassState::INVALID, //TexGenRMode
        PassState::INVALID, //TexGenQMode
        PassState::INVALID, //TexGenSEyePlane
        PassState::INVALID, //TexGenTEyePlane
        PassState::INVALID, //TexGenREyePlane
        PassState::INVALID, //TexGenQEyePlane
        PassState::INVALID, //TexGenSObjectPlace
        PassState::INVALID, //TexGenTObjectPlace
        PassState::INVALID, //TexGenRObjectPlace
        PassState::INVALID, //TexGenQObjectPlace
        PassState::TEXTURE1D, //Texture1D
        PassState::TEXTURE2D, //Texture2D
        PassState::TEXTURE3D, //Texture3D
        PassState::TEXTURERECT, //TextureRectangle
        PassState::TEXTURECUBE, //TextureCubeMap
        PassState::TEXTURE_ENV_COLOR, //TextureEnvColor
        PassState::TEXTURE_ENV_MODE, //TextureEnvMode
        PassState::INVALID, //TexGenSEnable
        PassState::INVALID, //TexGenTEnable
        PassState::INVALID, //TexGenREnable
        PassState::INVALID, //TexGenQEnable
        PassState::TEXTURE1D_ENABLE, //Texture1DEnable
        PassState::TEXTURE2D_ENABLE, //Texture2DEnable
        PassState::TEXTURE3D_ENABLE, //Texture3DEnable
        PassState::TEXTURERECT_ENABLE, //TextureRectangleEnable
        PassState::TEXTURECUBE_ENABLE, //TextureCubeMapEnable

        PassState::INVALID, //VertexEnvParameter
        PassState::INVALID, //VertexLocalParameter
        PassState::INVALID, //VertexProgram
    };

}

