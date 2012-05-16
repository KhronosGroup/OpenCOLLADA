/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_RENDER_STATE_H__
#define __COLLADAFW_RENDER_STATE_H__

#include "COLLADAFWPrerequisites.h"
//#include "COLLADAFWConstants.h"

#include "COLLADABUUtils.h"

namespace COLLADAFW
{

    /** Declares the storage for the graphical representation of an object. */
    class RenderState
    {

    public:

        /** Enumerates the COLLADAFW render states for effect passes.
        Each state description states the structure allocated in FCollada for this state.
        For example, ALPHA_FUNC describes: { FUDaePassStateFunction function = ALWAYS, float alphaComparison = 0.0f }.
        This implies a 8-byte structure with
        1) FUDaePassStateFunction::Function at offset 0; it defaults to the ALWAYS enumerated type.
        2) The alpha comparison value at offset 4; it defaults to 0.0f.
        All enumerated types are 4 byte in length. */
        enum PassState
        {
            ALPHA_FUNC = 0, /**< { FUDaePassStateFunction function = ALWAYS, float alphaComparison = 0.0f } */
            BLEND_FUNC, /**< { FUDaePassStateBlendType sourceBlend = ONE, FUDaePassStateBlendType destinationBlend = ZERO } */
            BLEND_FUNC_SEPARATE, /**< { FUDaePassStateBlendType sourceColorBlend = ONE, FUDaePassStateBlendType destinationColorBlend = ZERO, FUDaePassStateBlendType sourceAlphaBlend = ONE, FUDaePassStateBlendType destinationAlphaBlend = ZERO } */
            BLEND_EQUATION, /**< { FUDaePassStateBlendEquation blendEquation = ADD } */
            BLEND_EQUATION_SEPARATE, /**< { FUDaePassStateBlendEquation colorEquation = ADD, FUDaePassStateBlendEquation alphaEquation = ADD } */
            COLOR_MATERIAL, /**< { FUDaePassStateFaceType whichFaces = FRONT_AND_BACK, FUDaePassStateMaterialType material = AMBIENT_AND_DIFFUSE } */
            CULL_FACE, /**< { FUDaePassStateFaceType culledFaces = BACK } */
            DEPTH_FUNC, /**< { FUDaePassStateFunction depthAcceptFunction = ALWAYS } */
            FOG_MODE, /**< { FUDaePassStateFogType fogType = EXP } */
            FOG_COORD_SRC, /**< { FUDaePassStateFogCoordinateType type = FOG_COORDINATE } */

            FRONT_FACE = 10, /**< { FUDaePassStateFrontFaceType frontFaceSide = COUNTER_CLOCKWISE } */
            LIGHT_MODEL_COLOR_CONTROL, /**< { FUDaePassStateLightModelColorControlType controlType = SINGLE_COLOR } */
            LOGIC_OP, /**< { FUDaePassStateLogicOperation operation = COPY } */
            POLYGON_MODE, /**< { FUDaePassStateFaceType whichFaces = FRONT_AND_BACK, FUDaePassStatePolygonMode renderMode = FILL } */
            SHADE_MODEL, /**< { FUDaePassStateShadeModel model = SMOOTH } */
            STENCIL_FUNC, /**< { FUDaePassStateFunction acceptFunction = ALWAYS, uint8 referenceValue = 0, uint8 mask = 0xFF } */
            STENCIL_OP, /**< { FUDaePassStateStencilOperation failOperation = KEEP, FUDaePassStateStencilOperation depthFailOperation = KEEP, FUDaePassStateStencilOperation depthPassOperation = KEEP } */
            STENCIL_FUNC_SEPARATE, /**< { FUDaePassStateFunction frontFacesAcceptFunction = ALWAYS, FUDaePassStateFunction backFacesAcceptFunction = ALWAYS, uint8 referenceValue = 0, uint8 mask = 0xFF } */
            STENCIL_OP_SEPARATE, /**< { FUDaePassStateFaceType whichFaces = FRONT_AND_BACK, FUDaePassStateStencilOperation failOperation = KEEP, FUDaePassStateStencilOperation depthFailOperation = KEEP, FUDaePassStateStencilOperation depthPassOperation = KEEP } */
            STENCIL_MASK_SEPARATE, /**< { FUDaePassStateFaceType whichFaces = FRONT_AND_BACK, uint8 mask = 0xFF } */

            LIGHT_ENABLE = 20, /**< { uint8 lightIndex = 0, bool enabled = false } */
            LIGHT_AMBIENT, /**< { uint8 lightIndex = 0, FMVector4 ambientColor = [0,0,0,1] } */
            LIGHT_DIFFUSE, /**< { uint8 lightIndex = 0, FMVector4 diffuseColor = [0,0,0,0] } */
            LIGHT_SPECULAR, /**< { uint8 lightIndex = 0, FMVector4 specularColor = [0,0,0,0] } */
            LIGHT_POSITION, /**< { uint8 lightIndex = 0, FMVector4 position = [0,0,1,0] } */
            LIGHT_CONSTANT_ATTENUATION, /**< { uint8 lightIndex = 0, float constantAttenuation = 1.0f } */
            LIGHT_LINEAR_ATTENUATION, /**< { uint8 lightIndex = 0, float linearAttenuation = 0.0f } */
            LIGHT_QUADRATIC_ATTENUATION, /**< { uint8 lightIndex = 0, float quadraticAttenuation = 0.0f } */
            LIGHT_SPOT_CUTOFF, /**< { uint8 lightIndex = 0, float cutoff = 180.0f } */
            LIGHT_SPOT_DIRECTION, /**< { uint8 lightIndex = 0, FMVector4 direction = [0,0,-1] } */
            LIGHT_SPOT_EXPONENT = 30, /**< { uint8 lightIndex = 0, float exponent = 0.0f } */

            TEXTURE1D = 31, /**< { uint8 textureIndex = 0, uint32 textureId = 0 } */ 
            TEXTURE2D, /**< { uint8 textureIndex = 0, uint32 textureId = 0 } */
            TEXTURE3D, /**< { uint8 textureIndex = 0, uint32 textureId = 0 } */
            TEXTURECUBE, /**< { uint8 textureIndex = 0, uint32 textureId = 0 } */
            TEXTURERECT, /**< { uint8 textureIndex = 0, uint32 textureId = 0 } */
            TEXTUREDEPTH, /**< { uint8 textureIndex = 0, uint32 textureId = 0 } */
            TEXTURE1D_ENABLE, /**< { uint8 textureIndex = 0, bool enabled = false } */
            TEXTURE2D_ENABLE, /**< { uint8 textureIndex = 0, bool enabled = false } */
            TEXTURE3D_ENABLE, /**< { uint8 textureIndex = 0, bool enabled = false } */
            TEXTURECUBE_ENABLE, /**< { uint8 textureIndex = 0, bool enabled = false } */
            TEXTURERECT_ENABLE, /**< { uint8 textureIndex = 0, bool enabled = false } */
            TEXTUREDEPTH_ENABLE, /**< { uint8 textureIndex = 0, bool enabled = false } */
            TEXTURE_ENV_COLOR, /**< { uint8 textureIndex = 0, FMVector4 environmentColor = [0,0,0,0] } */
            TEXTURE_ENV_MODE, /**< { uint8 textureIndex = 0, char environmentMode[255] = "" } */

            CLIP_PLANE = 45, /**< { uint8 planeIndex = 0, FMVector4 planeValue = [0,0,0,0] } */
            CLIP_PLANE_ENABLE, /**< { uint8 planeIndex = 0, bool enabled = false } */
            BLEND_COLOR, /**< { FMVector4 blendColor = [0,0,0,0] } */
            CLEAR_COLOR, /**< { FMVector4 clearColor = [0,0,0,0] } */
            CLEAR_STENCIL, /**< { uint32 clearStencilValue = 0 } */
            CLEAR_DEPTH, /**< { float clearDepthValue = 1.0f } */
            COLOR_MASK, /**< { bool redWriteMask = true, bool greenWriteMask = true, bool blueWriteMask = true, bool alphaWriteMask = true } */
            DEPTH_BOUNDS, /**< { FMVector2 depthBounds = [0,1] } */
            DEPTH_MASK, /**< { bool depthWriteMask = true } */
            DEPTH_RANGE, /**< { float minimumDepthValue = 0.0f, float maximumDepthValue = 1.0f } */

            FOG_DENSITY = 55, /**< { float fogDensity = 1.0f } */
            FOG_START, /**< { float fogStartDepthValue = 0.0f } */
            FOG_END, /**< { float fogEndDepthValue = 1.0f } */
            FOG_COLOR, /**< { FMVector4 fogColor = [0,0,0,0] } */
            LIGHT_MODEL_AMBIENT, /**< { FMVector4 ambientColor = [0.2,0.2,0.2,1] } */
            LIGHTING_ENABLE, /**< { bool enabled = false } */
            LINE_STIPPLE, /**< { uint16 lineStippleStart = 1, uint16 lineStippleEnd = 0xFF } */
            LINE_WIDTH, /**< { float lineWidth = 1.0f } */

            MATERIAL_AMBIENT = 63, /**< { FMVector4 ambientColor = [0.2,0.2,0.2,1] } */
            MATERIAL_DIFFUSE, /**< { FMVector4 diffuseColor = [0.8,0.8,0.8,1] } */
            MATERIAL_EMISSION, /**< { FMVector4 emissionColor = [0,0,0,1] } */
            MATERIAL_SHININESS, /**< { float shininessOrSpecularLevel = 0.0f } */
            MATERIAL_SPECULAR, /**< { FMVector4 specularColor = [0,0,0,1] } */
            MODEL_VIEW_MATRIX, /**< { FMMatrix44 modelViewMatrix = FMMatrix44::Identity } */
            POINT_DISTANCE_ATTENUATION, /**< { FMVector3 attenuation = [1,0,0] } */
            POINT_FADE_THRESHOLD_SIZE, /**< { float threshold = 1.0f } */
            POINT_SIZE, /**< { float size = 1.0f } */
            POINT_SIZE_MIN, /**< { float minimum = 0.0f } */
            POINT_SIZE_MAX, /**< { float maximum = 1.0f } */

            POLYGON_OFFSET = 74, /**< { float factor = 0.0f, float units = 0.0f } */
            PROJECTION_MATRIX, /**< { FMMatrix44 projectionMatrix = FMMatrix44::Identity } */
            SCISSOR, /**< { FMVector4 scissor = [0,0,0,0] } */
            STENCIL_MASK, /**< { uint32 mask = 0xFFFFFFFF } */
            ALPHA_TEST_ENABLE, /**< { bool enabled = false } */
            AUTO_NORMAL_ENABLE, /**< { bool enabled  = false } */
            BLEND_ENABLE, /**< { bool enabled  = false } */
            COLOR_LOGIC_OP_ENABLE, /**< { bool enabled  = false } */
            COLOR_MATERIAL_ENABLE, /**< { bool enabled  = true } */
            CULL_FACE_ENABLE, /**< { bool enabled  = false } */

            DEPTH_BOUNDS_ENABLE = 84, /**< { bool enabled  = false } */
            DEPTH_CLAMP_ENABLE, /**< { bool enabled  = false } */
            DEPTH_TEST_ENABLE, /**< { bool enabled  = false } */
            DITHER_ENABLE, /**< { bool enabled  = false } */
            FOG_ENABLE, /**< { bool enabled  = false } */
            LIGHT_MODEL_LOCAL_VIEWER_ENABLE, /**< { bool enabled  = false } */
            LIGHT_MODEL_TWO_SIDE_ENABLE, /**< { bool enabled  = false } */
            LINE_SMOOTH_ENABLE, /**< { bool enabled  = false } */
            LINE_STIPPLE_ENABLE, /**< { bool enabled = false } */
            LOGIC_OP_ENABLE, /**< { bool enabled  = false } */
            MULTISAMPLE_ENABLE, /**< { bool enabled  = false } */

            NORMALIZE_ENABLE = 95, /**< { bool enabled  = false } */
            POINT_SMOOTH_ENABLE, /**< { bool enabled  = false } */
            POLYGON_OFFSET_FILL_ENABLE, /**< { bool enabled  = false } */
            POLYGON_OFFSET_LINE_ENABLE, /**< { bool enabled  = false } */
            POLYGON_OFFSET_POINT_ENABLE, /**< { bool enabled  = false } */
            POLYGON_SMOOTH_ENABLE, /**< { bool enabled  = false } */
            POLYGON_STIPPLE_ENABLE, /**< { bool enabled  = false } */
            RESCALE_NORMAL_ENABLE, /**< { bool enabled  = false } */

            SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 103, /**< { bool enabled  = false } */
            SAMPLE_ALPHA_TO_ONE_ENABLE, /**< { bool enabled  = false } */
            SAMPLE_COVERAGE_ENABLE, /**< { bool enabled  = false } */
            SCISSOR_TEST_ENABLE, /**< { bool enabled  = false } */
            STENCIL_TEST_ENABLE, /**< { bool enabled  = false } */

            COUNT = 108, /**< The number of supported render states. */
            PASS_STATE_INVALID /**< An invalid render state. */
        };

        /** Enumerates the COLLADAFW render state function types.
        The usage of this enumeration type depends on the render state.
        For the alpha-test and the depth-test, this function determines
        when a given pixel will be kept when compared against the
        color/depth buffer's current alpha/depth value. */
        enum PassStateFunction
        {
            PASS_STATE_FN_NEVER = 0x0200, /**< Never kept. */
            PASS_STATE_FN_LESS = 0x0201, /**< The pixel is kept when its value is lesser to the current value. */
            PASS_STATE_FN_EQUAL = 0x0202, /**< The pixel is kept when its value is equal to the current value. */
            PASS_STATE_FN_LESS_EQUAL = 0x0203, /**< The pixel is kept when its value is lesser or equal to the current value. */
            PASS_STATE_FN_GREATER = 0x0204, /**< The pixel is kept when its value is greater to the current value. */
            PASS_STATE_FN_NOT_EQUAL = 0x0205, /**< The pixel is kept when its value is not equal to the current value. */
            PASS_STATE_FN_GREATER_EQUAL = 0x0206, /**< The pixel is kept when its value is greater or equal to the current value. */
            PASS_STATE_FN_ALWAYS = 0x0207, /** Always kept. */

            PASS_STATE_FN_INVALID /**< An invalid function. */
        };

    public:

        /** The render states for effect passes. */
        static const String CG_RENDER_STATE_NAMES[];
        static const PassState CG_RENDER_STATES_XREF[];

    public:

        /** Constructor. */
        RenderState () {}

        /** Destructor. */
        ~RenderState () {}

        /** Returns the enumeration type of the current CG state. */
        static const PassState getRenderStateFromCgName ( const char* cgName );

        /** Returns the collada name of the current CG state. */
        static const String getCgRenderStateName ( const PassState& state );

        /** Returns the render state count. */
        static size_t getTotalRenderStateCount();

        /** Converts the render state enumeration type to its COLLADAFW render state name string.
        @param state The render state enumeration type.
        @return The render state name string. */
        static const String& getColladaRenderStateName ( const PassState& state );

        /** Converts the COLLADAFW render state function string to the render state function type.
        @param value The render state function string.
        @return The render state function type. */
        static const PassStateFunction getPassStateFunction ( const char* val );
        inline const PassStateFunction getPassStateFunction ( const String& value ) 
        { return getPassStateFunction ( value.c_str() ); } /**< See above. */

        /** Converts the render state function type to its COLLADAFW render state function string.
        @param fn The render state function type.
        @return The render state function string. */
        static const String& getColladaPassStateString ( const PassStateFunction& fn );

    };
}

#endif // __COLLADAFW_RENDER_STATE_H__
