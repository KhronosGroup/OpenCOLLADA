/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWRenderState.h"
#include "COLLADASWRenderStateStatic.h"

namespace COLLADASW
{

    // -------------------------------
    const RenderState::PassState RenderState::getRenderStateFromCgName ( const char* cgName )
    {
        // sanity checks
        if (cgName == NULL || cgName[0] == '\0') return RenderState::PASS_STATE_INVALID;

        const size_t arrayLength = getTotalRenderStateCount();

        // skip to interesting part of the array
        size_t i = 0;
        while ( i<arrayLength && tolower(CG_RENDER_STATE_NAMES[i][0]) != tolower(cgName[0]) ) i++;

        // try to match the string (not case sensitive)
        for ( ; i<arrayLength && tolower(CG_RENDER_STATE_NAMES[i][0]) == tolower(cgName[0]); i++ )
        {
            if ( Utils::equals ( CG_RENDER_STATE_NAMES[i], cgName ) )
                return CG_RENDER_STATES_XREF[i];
        }

        // past the interesting part, we didn't find it.
        return RenderState::PASS_STATE_INVALID;
    }

    // -------------------------------
    const String RenderState::getCgRenderStateName ( const PassState& state )
    {
        size_t len = getTotalRenderStateCount();
        for ( size_t i = 0; i < len; i++ )
        {
            if (CG_RENDER_STATES_XREF[i] == state)
                return CG_RENDER_STATE_NAMES[i];
        }
        return NULL;
    }

    // -------------------------------
    size_t RenderState::getTotalRenderStateCount ()
    {
        return sizeof ( CG_RENDER_STATE_NAMES ) / sizeof ( *CG_RENDER_STATE_NAMES );
    }

    // -------------------------------
    const RenderState::PassStateFunction RenderState::getPassStateFunction ( const char* val )
    {
        if ( Utils::equalsIgnoreCase ( val, CSWC::CSW_FX_FUNCTION_NEVER ) ) return PASS_STATE_FN_NEVER;
        else if ( Utils::equalsIgnoreCase ( val, CSWC::CSW_FX_FUNCTION_LESS ) ) return PASS_STATE_FN_LESS;
        else if ( Utils::equalsIgnoreCase ( val, CSWC::CSW_FX_FUNCTION_EQUAL ) ) return PASS_STATE_FN_EQUAL;
        else if ( Utils::equalsIgnoreCase ( val, CSWC::CSW_FX_FUNCTION_LEQUAL ) ) return PASS_STATE_FN_LESS_EQUAL;
        else if ( Utils::equalsIgnoreCase ( val, CSWC::CSW_FX_FUNCTION_GREATER ) ) return PASS_STATE_FN_GREATER;
        else if ( Utils::equalsIgnoreCase ( val, CSWC::CSW_FX_FUNCTION_NEQUAL ) ) return PASS_STATE_FN_NOT_EQUAL;
        else if ( Utils::equalsIgnoreCase ( val, CSWC::CSW_FX_FUNCTION_GEQUAL ) ) return PASS_STATE_FN_GREATER_EQUAL;
        else if ( Utils::equalsIgnoreCase ( val, CSWC::CSW_FX_FUNCTION_ALWAYS ) ) return PASS_STATE_FN_ALWAYS;
        else return PASS_STATE_FN_INVALID;
    }

    // -------------------------------
    const String& RenderState::getColladaPassStateString ( const PassStateFunction& fn )
    {
        switch (fn)
        {
        case PASS_STATE_FN_NEVER: return CSWC::CSW_FX_FUNCTION_NEVER;
        case PASS_STATE_FN_LESS: return CSWC::CSW_FX_FUNCTION_LESS;
        case PASS_STATE_FN_EQUAL: return CSWC::CSW_FX_FUNCTION_EQUAL;
        case PASS_STATE_FN_LESS_EQUAL: return CSWC::CSW_FX_FUNCTION_LEQUAL;
        case PASS_STATE_FN_GREATER: return CSWC::CSW_FX_FUNCTION_GREATER;
        case PASS_STATE_FN_NOT_EQUAL: return CSWC::CSW_FX_FUNCTION_NEQUAL;
        case PASS_STATE_FN_GREATER_EQUAL: return CSWC::CSW_FX_FUNCTION_GEQUAL;
        case PASS_STATE_FN_ALWAYS: return CSWC::CSW_FX_FUNCTION_ALWAYS;
        case PASS_STATE_FN_INVALID:
        default: return CSWC::CSW_ERR_UNKNOWN_INPUT;
        }
    }

    // -------------------------------
    const String& RenderState::getColladaRenderStateName ( const PassState& state )    
    {
        switch (state)
        {
        case ALPHA_FUNC: return CSWC::CSW_FX_STATE_ALPHA_FUNC;
        case BLEND_FUNC: return CSWC::CSW_FX_STATE_BLEND_FUNC;
        case BLEND_FUNC_SEPARATE: return CSWC::CSW_FX_STATE_BLEND_FUNC_SEPARATE;
        case BLEND_EQUATION: return CSWC::CSW_FX_STATE_BLEND_EQUATION;
        case BLEND_EQUATION_SEPARATE: return CSWC::CSW_FX_STATE_BLEND_EQUATION_SEPARATE;
        case COLOR_MATERIAL: return CSWC::CSW_FX_STATE_COLOR_MATERIAL;
        case CULL_FACE: return CSWC::CSW_FX_STATE_CULL_FACE;
        case DEPTH_FUNC: return CSWC::CSW_FX_STATE_DEPTH_FUNC;
        case FOG_MODE: return CSWC::CSW_FX_STATE_FOG_MODE;
        case FOG_COORD_SRC: return CSWC::CSW_FX_STATE_FOG_COORD_SRC;
        case FRONT_FACE: return CSWC::CSW_FX_STATE_FRONT_FACE;
        case LIGHT_MODEL_COLOR_CONTROL: return CSWC::CSW_FX_STATE_LIGHT_MODEL_COLOR_CONTROL;
        case LOGIC_OP: return CSWC::CSW_FX_STATE_LOGIC_OP;
        case POLYGON_MODE: return CSWC::CSW_FX_STATE_POLYGON_MODE;
        case SHADE_MODEL: return CSWC::CSW_FX_STATE_SHADE_MODEL;
        case STENCIL_FUNC: return CSWC::CSW_FX_STATE_STENCIL_FUNC;
        case STENCIL_OP: return CSWC::CSW_FX_STATE_STENCIL_OP;
        case STENCIL_FUNC_SEPARATE: return CSWC::CSW_FX_STATE_STENCIL_FUNC_SEPARATE;
        case STENCIL_OP_SEPARATE: return CSWC::CSW_FX_STATE_STENCIL_OP_SEPARATE;
        case STENCIL_MASK_SEPARATE: return CSWC::CSW_FX_STATE_STENCIL_MASK_SEPARATE;
        case LIGHT_ENABLE: return CSWC::CSW_FX_STATE_LIGHT_ENABLE;
        case LIGHT_AMBIENT: return CSWC::CSW_FX_STATE_LIGHT_AMBIENT;
        case LIGHT_DIFFUSE: return CSWC::CSW_FX_STATE_LIGHT_DIFFUSE;
        case LIGHT_SPECULAR: return CSWC::CSW_FX_STATE_LIGHT_SPECULAR;
        case LIGHT_POSITION: return CSWC::CSW_FX_STATE_LIGHT_POSITION;
        case LIGHT_CONSTANT_ATTENUATION: return CSWC::CSW_FX_STATE_LIGHT_CONSTANT_ATTENUATION;
        case LIGHT_LINEAR_ATTENUATION: return CSWC::CSW_FX_STATE_LIGHT_LINEAR_ATTENUATION;
        case LIGHT_QUADRATIC_ATTENUATION: return CSWC::CSW_FX_STATE_LIGHT_QUADRATIC_ATTENUATION;
        case LIGHT_SPOT_CUTOFF: return CSWC::CSW_FX_STATE_LIGHT_SPOT_CUTOFF;
        case LIGHT_SPOT_DIRECTION: return CSWC::CSW_FX_STATE_LIGHT_SPOT_DIRECTION;
        case LIGHT_SPOT_EXPONENT: return CSWC::CSW_FX_STATE_LIGHT_SPOT_EXPONENT;
        case TEXTURE1D: return CSWC::CSW_FX_STATE_TEXTURE1D;
        case TEXTURE2D: return CSWC::CSW_FX_STATE_TEXTURE2D;
        case TEXTURE3D: return CSWC::CSW_FX_STATE_TEXTURE3D;
        case TEXTURECUBE: return CSWC::CSW_FX_STATE_TEXTURECUBE;
        case TEXTURERECT: return CSWC::CSW_FX_STATE_TEXTURERECT;
        case TEXTUREDEPTH: return CSWC::CSW_FX_STATE_TEXTUREDEPTH;
        case TEXTURE1D_ENABLE: return CSWC::CSW_FX_STATE_TEXTURE1D_ENABLE;
        case TEXTURE2D_ENABLE: return CSWC::CSW_FX_STATE_TEXTURE2D_ENABLE;
        case TEXTURE3D_ENABLE: return CSWC::CSW_FX_STATE_TEXTURE3D_ENABLE;
        case TEXTURECUBE_ENABLE: return CSWC::CSW_FX_STATE_TEXTURECUBE_ENABLE;
        case TEXTURERECT_ENABLE: return CSWC::CSW_FX_STATE_TEXTURERECT_ENABLE;
        case TEXTUREDEPTH_ENABLE: return CSWC::CSW_FX_STATE_TEXTUREDEPTH_ENABLE;
        case TEXTURE_ENV_COLOR: return CSWC::CSW_FX_STATE_TEXTURE_ENV_COLOR;
        case TEXTURE_ENV_MODE: return CSWC::CSW_FX_STATE_TEXTURE_ENV_MODE;
        case CLIP_PLANE: return CSWC::CSW_FX_STATE_CLIP_PLANE;
        case CLIP_PLANE_ENABLE: return CSWC::CSW_FX_STATE_CLIP_PLANE_ENABLE;
        case BLEND_COLOR: return CSWC::CSW_FX_STATE_BLEND_COLOR;
        case CLEAR_COLOR: return CSWC::CSW_FX_STATE_CLEAR_COLOR;
        case CLEAR_STENCIL: return CSWC::CSW_FX_STATE_CLEAR_STENCIL;
        case CLEAR_DEPTH: return CSWC::CSW_FX_STATE_CLEAR_DEPTH;
        case COLOR_MASK: return CSWC::CSW_FX_STATE_COLOR_MASK;
        case DEPTH_BOUNDS: return CSWC::CSW_FX_STATE_DEPTH_BOUNDS;
        case DEPTH_MASK: return CSWC::CSW_FX_STATE_DEPTH_MASK;
        case DEPTH_RANGE: return CSWC::CSW_FX_STATE_DEPTH_RANGE;
        case FOG_DENSITY: return CSWC::CSW_FX_STATE_FOG_DENSITY;
        case FOG_START: return CSWC::CSW_FX_STATE_FOG_START;
        case FOG_END: return CSWC::CSW_FX_STATE_FOG_END;
        case FOG_COLOR: return CSWC::CSW_FX_STATE_FOG_COLOR;
        case LIGHT_MODEL_AMBIENT: return CSWC::CSW_FX_STATE_LIGHT_MODEL_AMBIENT;
        case LIGHTING_ENABLE: return CSWC::CSW_FX_STATE_LIGHTING_ENABLE;
        case LINE_STIPPLE: return CSWC::CSW_FX_STATE_LINE_STIPPLE;
        case LINE_WIDTH: return CSWC::CSW_FX_STATE_LINE_WIDTH;
        case MATERIAL_AMBIENT: return CSWC::CSW_FX_STATE_MATERIAL_AMBIENT;
        case MATERIAL_DIFFUSE: return CSWC::CSW_FX_STATE_MATERIAL_DIFFUSE;
        case MATERIAL_EMISSION: return CSWC::CSW_FX_STATE_MATERIAL_EMISSION;
        case MATERIAL_SHININESS: return CSWC::CSW_FX_STATE_MATERIAL_SHININESS;
        case MATERIAL_SPECULAR: return CSWC::CSW_FX_STATE_MATERIAL_SPECULAR;
        case MODEL_VIEW_MATRIX: return CSWC::CSW_FX_STATE_MODEL_VIEW_MATRIX;
        case POINT_DISTANCE_ATTENUATION: return CSWC::CSW_FX_STATE_POINT_DISTANCE_ATTENUATION;
        case POINT_FADE_THRESHOLD_SIZE: return CSWC::CSW_FX_STATE_POINT_FADE_THRESHOLD_SIZE;
        case POINT_SIZE: return CSWC::CSW_FX_STATE_POINT_SIZE;
        case POINT_SIZE_MIN: return CSWC::CSW_FX_STATE_POINT_SIZE_MIN;
        case POINT_SIZE_MAX: return CSWC::CSW_FX_STATE_POINT_SIZE_MAX;
        case POLYGON_OFFSET: return CSWC::CSW_FX_STATE_POLYGON_OFFSET;
        case PROJECTION_MATRIX: return CSWC::CSW_FX_STATE_PROJECTION_MATRIX;
        case SCISSOR: return CSWC::CSW_FX_STATE_SCISSOR;
        case STENCIL_MASK: return CSWC::CSW_FX_STATE_STENCIL_MASK;
        case ALPHA_TEST_ENABLE: return CSWC::CSW_FX_STATE_ALPHA_TEST_ENABLE;
        case AUTO_NORMAL_ENABLE: return CSWC::CSW_FX_STATE_AUTO_NORMAL_ENABLE;
        case BLEND_ENABLE: return CSWC::CSW_FX_STATE_BLEND_ENABLE;
        case COLOR_LOGIC_OP_ENABLE: return CSWC::CSW_FX_STATE_COLOR_LOGIC_OP_ENABLE;
        case COLOR_MATERIAL_ENABLE: return CSWC::CSW_FX_STATE_COLOR_MATERIAL_ENABLE;
        case CULL_FACE_ENABLE: return CSWC::CSW_FX_STATE_CULL_FACE_ENABLE;
        case DEPTH_BOUNDS_ENABLE: return CSWC::CSW_FX_STATE_DEPTH_BOUNDS_ENABLE;
        case DEPTH_CLAMP_ENABLE: return CSWC::CSW_FX_STATE_DEPTH_CLAMP_ENABLE;
        case DEPTH_TEST_ENABLE: return CSWC::CSW_FX_STATE_DEPTH_TEST_ENABLE;
        case DITHER_ENABLE: return CSWC::CSW_FX_STATE_DITHER_ENABLE;
        case FOG_ENABLE: return CSWC::CSW_FX_STATE_FOG_ENABLE;
        case LIGHT_MODEL_LOCAL_VIEWER_ENABLE: return CSWC::CSW_FX_STATE_LIGHT_MODEL_LOCAL_VIEWER_ENABLE;
        case LIGHT_MODEL_TWO_SIDE_ENABLE: return CSWC::CSW_FX_STATE_LIGHT_MODEL_TWO_SIDE_ENABLE;
        case LINE_SMOOTH_ENABLE: return CSWC::CSW_FX_STATE_LINE_SMOOTH_ENABLE;
        case LINE_STIPPLE_ENABLE: return CSWC::CSW_FX_STATE_LINE_STIPPLE_ENABLE;
        case LOGIC_OP_ENABLE: return CSWC::CSW_FX_STATE_LOGIC_OP_ENABLE;
        case MULTISAMPLE_ENABLE: return CSWC::CSW_FX_STATE_MULTISAMPLE_ENABLE;
        case NORMALIZE_ENABLE: return CSWC::CSW_FX_STATE_NORMALIZE_ENABLE;
        case POINT_SMOOTH_ENABLE: return CSWC::CSW_FX_STATE_POINT_SMOOTH_ENABLE;
        case POLYGON_OFFSET_FILL_ENABLE: return CSWC::CSW_FX_STATE_POLYGON_OFFSET_FILL_ENABLE;
        case POLYGON_OFFSET_LINE_ENABLE: return CSWC::CSW_FX_STATE_POLYGON_OFFSET_LINE_ENABLE;
        case POLYGON_OFFSET_POINT_ENABLE: return CSWC::CSW_FX_STATE_POLYGON_OFFSET_POINT_ENABLE;
        case POLYGON_SMOOTH_ENABLE: return CSWC::CSW_FX_STATE_POLYGON_SMOOTH_ENABLE;
        case POLYGON_STIPPLE_ENABLE: return CSWC::CSW_FX_STATE_POLYGON_STIPPLE_ENABLE;
        case RESCALE_NORMAL_ENABLE: return CSWC::CSW_FX_STATE_RESCALE_NORMAL_ENABLE;
        case SAMPLE_ALPHA_TO_COVERAGE_ENABLE: return CSWC::CSW_FX_STATE_SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
        case SAMPLE_ALPHA_TO_ONE_ENABLE: return CSWC::CSW_FX_STATE_SAMPLE_ALPHA_TO_ONE_ENABLE;
        case SAMPLE_COVERAGE_ENABLE: return CSWC::CSW_FX_STATE_SAMPLE_COVERAGE_ENABLE;
        case SCISSOR_TEST_ENABLE: return CSWC::CSW_FX_STATE_SCISSOR_TEST_ENABLE;
        case STENCIL_TEST_ENABLE: return CSWC::CSW_FX_STATE_STENCIL_TEST_ENABLE;
        case PASS_STATE_INVALID:
        default: return CSWC::CSW_ERR_UNKNOWN_INPUT;
        }
    }

}
