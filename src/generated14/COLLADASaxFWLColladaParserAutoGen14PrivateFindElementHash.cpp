/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLColladaParserAutoGen14Private.h"


namespace COLLADASaxFWL14
{


//---------------------------------------------------------------------
bool ColladaParserAutoGen14Private::findElementHash( ElementData& elementData )
{
    if ( mElementDataStack.empty() )
    {
        if( elementData.elementHash == HASH_ELEMENT_COLLADA )
        {
                elementData.typeID = 408;
                elementData.generatedElementHash = HASH_ELEMENT_COLLADA;

        }
        else
        {
            return false;
        }
    }
    else
    {
        switch ( mElementDataStack.back().typeID )
        {
        case 408:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS:
                elementData.typeID = 221;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS;
                break;
            case HASH_ELEMENT_LIBRARY_ANIMATIONS:
                elementData.typeID = 203;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_ANIMATIONS;
                break;
            case HASH_ELEMENT_LIBRARY_CAMERAS:
                elementData.typeID = 477;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_CAMERAS;
                break;
            case HASH_ELEMENT_LIBRARY_CONTROLLERS:
                elementData.typeID = 241;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_CONTROLLERS;
                break;
            case HASH_ELEMENT_LIBRARY_EFFECTS:
                elementData.typeID = 179;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_EFFECTS;
                break;
            case HASH_ELEMENT_LIBRARY_FORCE_FIELDS:
                elementData.typeID = 81;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_FORCE_FIELDS;
                break;
            case HASH_ELEMENT_LIBRARY_GEOMETRIES:
                elementData.typeID = 540;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_GEOMETRIES;
                break;
            case HASH_ELEMENT_LIBRARY_IMAGES:
                elementData.typeID = 330;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_IMAGES;
                break;
            case HASH_ELEMENT_LIBRARY_LIGHTS:
                elementData.typeID = 135;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_LIGHTS;
                break;
            case HASH_ELEMENT_LIBRARY_MATERIALS:
                elementData.typeID = 29;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_MATERIALS;
                break;
            case HASH_ELEMENT_LIBRARY_NODES:
                elementData.typeID = 530;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_NODES;
                break;
            case HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS:
                elementData.typeID = 391;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS;
                break;
            case HASH_ELEMENT_LIBRARY_PHYSICS_MODELS:
                elementData.typeID = 5;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_PHYSICS_MODELS;
                break;
            case HASH_ELEMENT_LIBRARY_PHYSICS_SCENES:
                elementData.typeID = 398;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_PHYSICS_SCENES;
                break;
            case HASH_ELEMENT_LIBRARY_VISUAL_SCENES:
                elementData.typeID = 515;
                elementData.generatedElementHash = HASH_ELEMENT_LIBRARY_VISUAL_SCENES;
                break;
            case HASH_ELEMENT_SCENE:
                elementData.typeID = 395;
                elementData.generatedElementHash = HASH_ELEMENT_SCENE;
                break;
            default:
                return false;
            }
            break;
        case 507:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 153;
                elementData.generatedElementHash = HASH_ELEMENT_PARAM;
                break;
            default:
                return false;
            }
            break;
        case 337:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FUNC:
                elementData.typeID = 287;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC__FUNC;
                break;
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 378;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC__VALUE;
                break;
            default:
                return false;
            }
            break;
        case 338:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FUNC:
                elementData.typeID = 288;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC__FUNC;
                break;
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 379;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC__VALUE;
                break;
            default:
                return false;
            }
            break;
        case 38:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_COLOR:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR____TARGETABLEFLOAT3;
                break;
            default:
                return false;
            }
            break;
        case 387:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_DAMPING:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_DAMPING;
                break;
            case HASH_ELEMENT_STIFFNESS:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_STIFFNESS;
                break;
            case HASH_ELEMENT_TARGET_VALUE:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_TARGET_VALUE;
                break;
            default:
                return false;
            }
            break;
        case 7:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANIMATION:
                elementData.typeID = 7;
                elementData.generatedElementHash = HASH_ELEMENT_ANIMATION;
                break;
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_CHANNEL:
                elementData.typeID = 101;
                elementData.generatedElementHash = HASH_ELEMENT_CHANNEL;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_SAMPLER:
                elementData.typeID = 467;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 598;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE;
                break;
            default:
                return false;
            }
            break;
        case 280:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INSTANCE_ANIMATION:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_ANIMATION;
                break;
            default:
                return false;
            }
            break;
        case 484:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_CONTRIBUTOR:
                elementData.typeID = 479;
                elementData.generatedElementHash = HASH_ELEMENT_CONTRIBUTOR;
                break;
            case HASH_ELEMENT_CREATED:
                elementData.typeID = 188;
                elementData.generatedElementHash = HASH_ELEMENT_CREATED;
                break;
            case HASH_ELEMENT_KEYWORDS:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_KEYWORDS;
                break;
            case HASH_ELEMENT_MODIFIED:
                elementData.typeID = 188;
                elementData.generatedElementHash = HASH_ELEMENT_MODIFIED;
                break;
            case HASH_ELEMENT_REVISION:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_REVISION;
                break;
            case HASH_ELEMENT_SUBJECT:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_SUBJECT;
                break;
            case HASH_ELEMENT_TITLE:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_TITLE;
                break;
            case HASH_ELEMENT_UNIT:
                elementData.typeID = 230;
                elementData.generatedElementHash = HASH_ELEMENT_UNIT;
                break;
            case HASH_ELEMENT_UP_AXIS:
                elementData.typeID = 427;
                elementData.generatedElementHash = HASH_ELEMENT_UP_AXIS;
                break;
            default:
                return false;
            }
            break;
        case 169:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_ROTATE:
                elementData.typeID = 508;
                elementData.generatedElementHash = HASH_ELEMENT_ROTATE;
                break;
            case HASH_ELEMENT_TRANSLATE:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSLATE;
                break;
            default:
                return false;
            }
            break;
        case 36:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 153;
                elementData.generatedElementHash = HASH_ELEMENT_PARAM;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 569;
                elementData.generatedElementHash = HASH_ELEMENT_BIND_MATERIAL__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 301:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 205;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____CG_BOOL;
                break;
            case HASH_ELEMENT_BOOL1:
                elementData.typeID = 621;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1;
                break;
            case HASH_ELEMENT_BOOL1X1:
                elementData.typeID = 256;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X1;
                break;
            case HASH_ELEMENT_BOOL1X2:
                elementData.typeID = 228;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X2;
                break;
            case HASH_ELEMENT_BOOL1X3:
                elementData.typeID = 406;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X3;
                break;
            case HASH_ELEMENT_BOOL1X4:
                elementData.typeID = 91;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X4;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 317;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____CG_BOOL2;
                break;
            case HASH_ELEMENT_BOOL2X1:
                elementData.typeID = 610;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X1;
                break;
            case HASH_ELEMENT_BOOL2X2:
                elementData.typeID = 270;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X2;
                break;
            case HASH_ELEMENT_BOOL2X3:
                elementData.typeID = 592;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X3;
                break;
            case HASH_ELEMENT_BOOL2X4:
                elementData.typeID = 307;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X4;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 614;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____CG_BOOL3;
                break;
            case HASH_ELEMENT_BOOL3X1:
                elementData.typeID = 32;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X1;
                break;
            case HASH_ELEMENT_BOOL3X2:
                elementData.typeID = 257;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X2;
                break;
            case HASH_ELEMENT_BOOL3X3:
                elementData.typeID = 597;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X3;
                break;
            case HASH_ELEMENT_BOOL3X4:
                elementData.typeID = 385;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X4;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 75;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____CG_BOOL4;
                break;
            case HASH_ELEMENT_BOOL4X1:
                elementData.typeID = 1;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X1;
                break;
            case HASH_ELEMENT_BOOL4X2:
                elementData.typeID = 390;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X2;
                break;
            case HASH_ELEMENT_BOOL4X3:
                elementData.typeID = 132;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X3;
                break;
            case HASH_ELEMENT_BOOL4X4:
                elementData.typeID = 346;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FIXED:
                elementData.typeID = 590;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED;
                break;
            case HASH_ELEMENT_FIXED1:
                elementData.typeID = 587;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1;
                break;
            case HASH_ELEMENT_FIXED1X1:
                elementData.typeID = 514;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X1;
                break;
            case HASH_ELEMENT_FIXED1X2:
                elementData.typeID = 211;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X2;
                break;
            case HASH_ELEMENT_FIXED1X3:
                elementData.typeID = 107;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X3;
                break;
            case HASH_ELEMENT_FIXED1X4:
                elementData.typeID = 428;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X4;
                break;
            case HASH_ELEMENT_FIXED2:
                elementData.typeID = 282;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2;
                break;
            case HASH_ELEMENT_FIXED2X1:
                elementData.typeID = 237;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X1;
                break;
            case HASH_ELEMENT_FIXED2X2:
                elementData.typeID = 499;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X2;
                break;
            case HASH_ELEMENT_FIXED2X3:
                elementData.typeID = 248;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X3;
                break;
            case HASH_ELEMENT_FIXED2X4:
                elementData.typeID = 541;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X4;
                break;
            case HASH_ELEMENT_FIXED3:
                elementData.typeID = 616;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3;
                break;
            case HASH_ELEMENT_FIXED3X1:
                elementData.typeID = 136;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X1;
                break;
            case HASH_ELEMENT_FIXED3X2:
                elementData.typeID = 522;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X2;
                break;
            case HASH_ELEMENT_FIXED3X3:
                elementData.typeID = 424;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X3;
                break;
            case HASH_ELEMENT_FIXED3X4:
                elementData.typeID = 493;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X4;
                break;
            case HASH_ELEMENT_FIXED4:
                elementData.typeID = 322;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4;
                break;
            case HASH_ELEMENT_FIXED4X1:
                elementData.typeID = 48;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X1;
                break;
            case HASH_ELEMENT_FIXED4X2:
                elementData.typeID = 374;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X2;
                break;
            case HASH_ELEMENT_FIXED4X3:
                elementData.typeID = 588;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X3;
                break;
            case HASH_ELEMENT_FIXED4X4:
                elementData.typeID = 252;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X4;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 401;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____CG_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1:
                elementData.typeID = 506;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 114;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____CG_FLOAT1X1;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 394;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____CG_FLOAT1X2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 111;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____CG_FLOAT1X3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 291;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____CG_FLOAT1X4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 238;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____CG_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 629;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____CG_FLOAT2X1;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 323;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____CG_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 438;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____CG_FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 53;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____CG_FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 88;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____CG_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 118;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____CG_FLOAT3X1;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 201;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____CG_FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 503;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____CG_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 191;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____CG_FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 246;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____CG_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 20;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____CG_FLOAT4X1;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 151;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____CG_FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 448;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____CG_FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 122;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____CG_FLOAT4X4;
                break;
            case HASH_ELEMENT_HALF:
                elementData.typeID = 437;
                elementData.generatedElementHash = HASH_ELEMENT_HALF;
                break;
            case HASH_ELEMENT_HALF1:
                elementData.typeID = 416;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1;
                break;
            case HASH_ELEMENT_HALF1X1:
                elementData.typeID = 229;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X1;
                break;
            case HASH_ELEMENT_HALF1X2:
                elementData.typeID = 565;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X2;
                break;
            case HASH_ELEMENT_HALF1X3:
                elementData.typeID = 99;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X3;
                break;
            case HASH_ELEMENT_HALF1X4:
                elementData.typeID = 397;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X4;
                break;
            case HASH_ELEMENT_HALF2:
                elementData.typeID = 60;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2;
                break;
            case HASH_ELEMENT_HALF2X1:
                elementData.typeID = 80;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X1;
                break;
            case HASH_ELEMENT_HALF2X2:
                elementData.typeID = 196;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X2;
                break;
            case HASH_ELEMENT_HALF2X3:
                elementData.typeID = 475;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X3;
                break;
            case HASH_ELEMENT_HALF2X4:
                elementData.typeID = 216;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X4;
                break;
            case HASH_ELEMENT_HALF3:
                elementData.typeID = 244;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3;
                break;
            case HASH_ELEMENT_HALF3X1:
                elementData.typeID = 547;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X1;
                break;
            case HASH_ELEMENT_HALF3X2:
                elementData.typeID = 245;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X2;
                break;
            case HASH_ELEMENT_HALF3X3:
                elementData.typeID = 476;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X3;
                break;
            case HASH_ELEMENT_HALF3X4:
                elementData.typeID = 178;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X4;
                break;
            case HASH_ELEMENT_HALF4:
                elementData.typeID = 266;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4;
                break;
            case HASH_ELEMENT_HALF4X1:
                elementData.typeID = 140;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X1;
                break;
            case HASH_ELEMENT_HALF4X2:
                elementData.typeID = 461;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X2;
                break;
            case HASH_ELEMENT_HALF4X3:
                elementData.typeID = 147;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X3;
                break;
            case HASH_ELEMENT_HALF4X4:
                elementData.typeID = 413;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 531;
                elementData.generatedElementHash = HASH_ELEMENT_INT____CG_INT;
                break;
            case HASH_ELEMENT_INT1:
                elementData.typeID = 603;
                elementData.generatedElementHash = HASH_ELEMENT_INT1;
                break;
            case HASH_ELEMENT_INT1X1:
                elementData.typeID = 607;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X1;
                break;
            case HASH_ELEMENT_INT1X2:
                elementData.typeID = 304;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X2;
                break;
            case HASH_ELEMENT_INT1X3:
                elementData.typeID = 470;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X3;
                break;
            case HASH_ELEMENT_INT1X4:
                elementData.typeID = 190;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X4;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 283;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____CG_INT2;
                break;
            case HASH_ELEMENT_INT2X1:
                elementData.typeID = 193;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X1;
                break;
            case HASH_ELEMENT_INT2X2:
                elementData.typeID = 64;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X2;
                break;
            case HASH_ELEMENT_INT2X3:
                elementData.typeID = 375;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X3;
                break;
            case HASH_ELEMENT_INT2X4:
                elementData.typeID = 30;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X4;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 509;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____CG_INT3;
                break;
            case HASH_ELEMENT_INT3X1:
                elementData.typeID = 426;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X1;
                break;
            case HASH_ELEMENT_INT3X2:
                elementData.typeID = 582;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X2;
                break;
            case HASH_ELEMENT_INT3X3:
                elementData.typeID = 383;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X3;
                break;
            case HASH_ELEMENT_INT3X4:
                elementData.typeID = 594;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X4;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 127;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____CG_INT4;
                break;
            case HASH_ELEMENT_INT4X1:
                elementData.typeID = 207;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X1;
                break;
            case HASH_ELEMENT_INT4X2:
                elementData.typeID = 159;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X2;
                break;
            case HASH_ELEMENT_INT4X3:
                elementData.typeID = 314;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X3;
                break;
            case HASH_ELEMENT_INT4X4:
                elementData.typeID = 511;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X4;
                break;
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 154;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__BIND__PARAM;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 359;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____CG_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 49;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____CG_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 595;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____CG_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 497;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 267;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 102;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT;
                break;
            case HASH_ELEMENT_STRING:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_STRING;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 225;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____CG_SURFACE_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 302:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 206;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____GLSL_BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 318;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____GLSL_BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 615;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____GLSL_BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 76;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____GLSL_BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 402;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____GLSL_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 239;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____GLSL_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 325;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____GLSL_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 90;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____GLSL_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 505;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____GLSL_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 247;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____GLSL_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 124;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____GLSL_FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 532;
                elementData.generatedElementHash = HASH_ELEMENT_INT____GLSL_INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 284;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____GLSL_INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 510;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____GLSL_INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 128;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____GLSL_INT4;
                break;
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 155;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__BIND__PARAM;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 361;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____GL_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 51;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____GL_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 380;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____GL_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 381;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____GL_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 269;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____GL_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 104;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____GL_SAMPLERRECT;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 227;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____GLSL_SURFACE_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 105:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ALPHA:
                elementData.typeID = 580;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_EQUATION_SEPARATE__ALPHA;
                break;
            case HASH_ELEMENT_RGB:
                elementData.typeID = 339;
                elementData.generatedElementHash = HASH_ELEMENT_RGB;
                break;
            default:
                return false;
            }
            break;
        case 435:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_DEST_ALPHA:
                elementData.typeID = 423;
                elementData.generatedElementHash = HASH_ELEMENT_DEST_ALPHA;
                break;
            case HASH_ELEMENT_DEST_RGB:
                elementData.typeID = 6;
                elementData.generatedElementHash = HASH_ELEMENT_DEST_RGB;
                break;
            case HASH_ELEMENT_SRC_ALPHA:
                elementData.typeID = 158;
                elementData.generatedElementHash = HASH_ELEMENT_SRC_ALPHA;
                break;
            case HASH_ELEMENT_SRC_RGB:
                elementData.typeID = 115;
                elementData.generatedElementHash = HASH_ELEMENT_SRC_RGB;
                break;
            default:
                return false;
            }
            break;
        case 166:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_DEST:
                elementData.typeID = 431;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC__DEST;
                break;
            case HASH_ELEMENT_SRC:
                elementData.typeID = 235;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC__SRC;
                break;
            default:
                return false;
            }
            break;
        case 167:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_DEST:
                elementData.typeID = 432;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC__DEST;
                break;
            case HASH_ELEMENT_SRC:
                elementData.typeID = 236;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC__SRC;
                break;
            default:
                return false;
            }
            break;
        case 611:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_AMBIENT:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_AMBIENT____COMMON_COLOR_OR_TEXTURE_TYPE;
                break;
            case HASH_ELEMENT_DIFFUSE:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_DIFFUSE;
                break;
            case HASH_ELEMENT_EMISSION:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_EMISSION;
                break;
            case HASH_ELEMENT_INDEX_OF_REFRACTION:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_INDEX_OF_REFRACTION;
                break;
            case HASH_ELEMENT_REFLECTIVE:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_REFLECTIVE;
                break;
            case HASH_ELEMENT_REFLECTIVITY:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_REFLECTIVITY;
                break;
            case HASH_ELEMENT_SHININESS:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_SHININESS;
                break;
            case HASH_ELEMENT_SPECULAR:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_SPECULAR;
                break;
            case HASH_ELEMENT_TRANSPARENCY:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSPARENCY;
                break;
            case HASH_ELEMENT_TRANSPARENT:
                elementData.typeID = 217;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSPARENT;
                break;
            default:
                return false;
            }
            break;
        case 561:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_HALF_EXTENTS:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_HALF_EXTENTS;
                break;
            default:
                return false;
            }
            break;
        case 28:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGER:
                elementData.typeID = 591;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGER;
                break;
            case HASH_ELEMENT_OPTICS:
                elementData.typeID = 150;
                elementData.generatedElementHash = HASH_ELEMENT_OPTICS;
                break;
            default:
                return false;
            }
            break;
        case 39:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_HEIGHT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_HEIGHT;
                break;
            case HASH_ELEMENT_RADIUS:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_RADIUS____FLOAT2;
                break;
            default:
                return false;
            }
            break;
        case 422:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FACE:
                elementData.typeID = 366;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_MATERIAL__FACE;
                break;
            case HASH_ELEMENT_MODE:
                elementData.typeID = 231;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_MATERIAL__MODE;
                break;
            default:
                return false;
            }
            break;
        case 163:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EMISSION:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_EMISSION;
                break;
            case HASH_ELEMENT_INDEX_OF_REFRACTION:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_INDEX_OF_REFRACTION;
                break;
            case HASH_ELEMENT_REFLECTIVE:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_REFLECTIVE;
                break;
            case HASH_ELEMENT_REFLECTIVITY:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_REFLECTIVITY;
                break;
            case HASH_ELEMENT_TRANSPARENCY:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSPARENCY;
                break;
            case HASH_ELEMENT_TRANSPARENT:
                elementData.typeID = 217;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSPARENT;
                break;
            default:
                return false;
            }
            break;
        case 479:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_AUTHOR:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_AUTHOR;
                break;
            case HASH_ELEMENT_AUTHORING_TOOL:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_AUTHORING_TOOL;
                break;
            case HASH_ELEMENT_COMMENTS:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_COMMENTS;
                break;
            case HASH_ELEMENT_COPYRIGHT:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_COPYRIGHT;
                break;
            case HASH_ELEMENT_SOURCE_DATA:
                elementData.typeID = 70;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE_DATA;
                break;
            default:
                return false;
            }
            break;
        case 180:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 34;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCAL;
                break;
            default:
                return false;
            }
            break;
        case 65:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MORPH:
                elementData.typeID = 265;
                elementData.generatedElementHash = HASH_ELEMENT_MORPH;
                break;
            case HASH_ELEMENT_SKIN:
                elementData.typeID = 410;
                elementData.generatedElementHash = HASH_ELEMENT_SKIN;
                break;
            default:
                return false;
            }
            break;
        case 82:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_LINES:
                elementData.typeID = 434;
                elementData.generatedElementHash = HASH_ELEMENT_LINES;
                break;
            case HASH_ELEMENT_LINESTRIPS:
                elementData.typeID = 521;
                elementData.generatedElementHash = HASH_ELEMENT_LINESTRIPS;
                break;
            case HASH_ELEMENT_POLYGONS:
                elementData.typeID = 389;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGONS;
                break;
            case HASH_ELEMENT_POLYLIST:
                elementData.typeID = 130;
                elementData.generatedElementHash = HASH_ELEMENT_POLYLIST;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 598;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE;
                break;
            case HASH_ELEMENT_TRIANGLES:
                elementData.typeID = 483;
                elementData.generatedElementHash = HASH_ELEMENT_TRIANGLES;
                break;
            case HASH_ELEMENT_TRIFANS:
                elementData.typeID = 612;
                elementData.generatedElementHash = HASH_ELEMENT_TRIFANS;
                break;
            case HASH_ELEMENT_TRISTRIPS:
                elementData.typeID = 312;
                elementData.generatedElementHash = HASH_ELEMENT_TRISTRIPS;
                break;
            case HASH_ELEMENT_VERTICES:
                elementData.typeID = 433;
                elementData.generatedElementHash = HASH_ELEMENT_VERTICES;
                break;
            default:
                return false;
            }
            break;
        case 399:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_HEIGHT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_HEIGHT;
                break;
            case HASH_ELEMENT_RADIUS:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_RADIUS____FLOAT2;
                break;
            default:
                return false;
            }
            break;
        case 306:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_COLOR:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR____TARGETABLEFLOAT3;
                break;
            default:
                return false;
            }
            break;
        case 52:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 555;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____FX_NEWPARAM_COMMON;
                break;
            case HASH_ELEMENT_PROFILE_CG:
                elementData.typeID = 133;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG;
                break;
            case HASH_ELEMENT_PROFILE_COMMON:
                elementData.typeID = 407;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_COMMON;
                break;
            case HASH_ELEMENT_PROFILE_GLES:
                elementData.typeID = 172;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES;
                break;
            case HASH_ELEMENT_PROFILE_GLSL:
                elementData.typeID = 139;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL;
                break;
            default:
                return false;
            }
            break;
        case 319:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_SIZE:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_SIZE____FLOAT3;
                break;
            default:
                return false;
            }
            break;
        case 294:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_RENDER:
                elementData.typeID = 84;
                elementData.generatedElementHash = HASH_ELEMENT_RENDER;
                break;
            default:
                return false;
            }
            break;
        case 4:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            default:
                return false;
            }
            break;
        case 31:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            default:
                return false;
            }
            break;
        case 160:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_CODE:
                elementData.typeID = 253;
                elementData.generatedElementHash = HASH_ELEMENT_CODE;
                break;
            case HASH_ELEMENT_INCLUDE:
                elementData.typeID = 564;
                elementData.generatedElementHash = HASH_ELEMENT_INCLUDE;
                break;
            case HASH_ELEMENT_NAME:
                elementData.typeID = 517;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG__NEWPARAM__SURFACE__GENERATOR__NAME;
                break;
            case HASH_ELEMENT_SETPARAM:
                elementData.typeID = 626;
                elementData.generatedElementHash = HASH_ELEMENT_SETPARAM____CG_SETPARAM_SIMPLE;
                break;
            default:
                return false;
            }
            break;
        case 161:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_CODE:
                elementData.typeID = 253;
                elementData.generatedElementHash = HASH_ELEMENT_CODE;
                break;
            case HASH_ELEMENT_INCLUDE:
                elementData.typeID = 564;
                elementData.generatedElementHash = HASH_ELEMENT_INCLUDE;
                break;
            case HASH_ELEMENT_NAME:
                elementData.typeID = 518;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__NEWPARAM__SURFACE__GENERATOR__NAME;
                break;
            case HASH_ELEMENT_SETPARAM:
                elementData.typeID = 628;
                elementData.generatedElementHash = HASH_ELEMENT_SETPARAM____GLSL_SETPARAM_SIMPLE;
                break;
            default:
                return false;
            }
            break;
        case 524:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_CONVEX_MESH:
                elementData.typeID = 82;
                elementData.generatedElementHash = HASH_ELEMENT_CONVEX_MESH;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MESH:
                elementData.typeID = 593;
                elementData.generatedElementHash = HASH_ELEMENT_MESH;
                break;
            case HASH_ELEMENT_SPLINE:
                elementData.typeID = 47;
                elementData.generatedElementHash = HASH_ELEMENT_SPLINE;
                break;
            default:
                return false;
            }
            break;
        case 224:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_DATA:
                elementData.typeID = 77;
                elementData.generatedElementHash = HASH_ELEMENT_DATA;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INIT_FROM:
                elementData.typeID = 70;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_FROM____ANYURI;
                break;
            default:
                return false;
            }
            break;
        case 591:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            default:
                return false;
            }
            break;
        case 215:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BIND_MATERIAL:
                elementData.typeID = 36;
                elementData.generatedElementHash = HASH_ELEMENT_BIND_MATERIAL;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_SKELETON:
                elementData.typeID = 70;
                elementData.generatedElementHash = HASH_ELEMENT_SKELETON;
                break;
            default:
                return false;
            }
            break;
        case 487:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_SETPARAM:
                elementData.typeID = 623;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_EFFECT__SETPARAM;
                break;
            case HASH_ELEMENT_TECHNIQUE_HINT:
                elementData.typeID = 83;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE_HINT;
                break;
            default:
                return false;
            }
            break;
        case 18:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BIND_MATERIAL:
                elementData.typeID = 36;
                elementData.generatedElementHash = HASH_ELEMENT_BIND_MATERIAL;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 209:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BIND:
                elementData.typeID = 300;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_MATERIAL__BIND;
                break;
            case HASH_ELEMENT_BIND_VERTEX_INPUT:
                elementData.typeID = 430;
                elementData.generatedElementHash = HASH_ELEMENT_BIND_VERTEX_INPUT;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 482:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INSTANCE_FORCE_FIELD:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_FORCE_FIELD;
                break;
            case HASH_ELEMENT_INSTANCE_RIGID_BODY:
                elementData.typeID = 454;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_RIGID_BODY;
                break;
            case HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT:
                elementData.typeID = 609;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT;
                break;
            default:
                return false;
            }
            break;
        case 454:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 570;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 609:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 249:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 34;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCAL;
                break;
            default:
                return false;
            }
            break;
        case 277:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_AMBIENT:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_AMBIENT____COMMON_COLOR_OR_TEXTURE_TYPE;
                break;
            case HASH_ELEMENT_DIFFUSE:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_DIFFUSE;
                break;
            case HASH_ELEMENT_EMISSION:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_EMISSION;
                break;
            case HASH_ELEMENT_INDEX_OF_REFRACTION:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_INDEX_OF_REFRACTION;
                break;
            case HASH_ELEMENT_REFLECTIVE:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_REFLECTIVE;
                break;
            case HASH_ELEMENT_REFLECTIVITY:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_REFLECTIVITY;
                break;
            case HASH_ELEMENT_TRANSPARENCY:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSPARENCY;
                break;
            case HASH_ELEMENT_TRANSPARENT:
                elementData.typeID = 217;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSPARENT;
                break;
            default:
                return false;
            }
            break;
        case 221:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANIMATION_CLIP:
                elementData.typeID = 280;
                elementData.generatedElementHash = HASH_ELEMENT_ANIMATION_CLIP;
                break;
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 203:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANIMATION:
                elementData.typeID = 7;
                elementData.generatedElementHash = HASH_ELEMENT_ANIMATION;
                break;
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 477:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_CAMERA:
                elementData.typeID = 28;
                elementData.generatedElementHash = HASH_ELEMENT_CAMERA;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 241:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_CONTROLLER:
                elementData.typeID = 65;
                elementData.generatedElementHash = HASH_ELEMENT_CONTROLLER;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 179:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EFFECT:
                elementData.typeID = 52;
                elementData.generatedElementHash = HASH_ELEMENT_EFFECT;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 81:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_FORCE_FIELD:
                elementData.typeID = 31;
                elementData.generatedElementHash = HASH_ELEMENT_FORCE_FIELD;
                break;
            default:
                return false;
            }
            break;
        case 540:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_GEOMETRY:
                elementData.typeID = 524;
                elementData.generatedElementHash = HASH_ELEMENT_GEOMETRY;
                break;
            default:
                return false;
            }
            break;
        case 330:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            default:
                return false;
            }
            break;
        case 135:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_LIGHT:
                elementData.typeID = 344;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT;
                break;
            default:
                return false;
            }
            break;
        case 29:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MATERIAL:
                elementData.typeID = 286;
                elementData.generatedElementHash = HASH_ELEMENT_MATERIAL;
                break;
            default:
                return false;
            }
            break;
        case 530:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_NODE:
                elementData.typeID = 22;
                elementData.generatedElementHash = HASH_ELEMENT_NODE;
                break;
            default:
                return false;
            }
            break;
        case 391:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_PHYSICS_MATERIAL:
                elementData.typeID = 255;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_MATERIAL;
                break;
            default:
                return false;
            }
            break;
        case 5:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_PHYSICS_MODEL:
                elementData.typeID = 208;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_MODEL;
                break;
            default:
                return false;
            }
            break;
        case 398:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_PHYSICS_SCENE:
                elementData.typeID = 492;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_SCENE;
                break;
            default:
                return false;
            }
            break;
        case 515:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_VISUAL_SCENE:
                elementData.typeID = 345;
                elementData.generatedElementHash = HASH_ELEMENT_VISUAL_SCENE;
                break;
            default:
                return false;
            }
            break;
        case 344:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 571;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 382:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_LINEAR:
                elementData.typeID = 332;
                elementData.generatedElementHash = HASH_ELEMENT_LIMITS__LINEAR;
                break;
            case HASH_ELEMENT_SWING_CONE_AND_TWIST:
                elementData.typeID = 523;
                elementData.generatedElementHash = HASH_ELEMENT_SWING_CONE_AND_TWIST;
                break;
            default:
                return false;
            }
            break;
        case 332:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_MAX:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_MAX;
                break;
            case HASH_ELEMENT_MIN:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_MIN;
                break;
            default:
                return false;
            }
            break;
        case 333:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_DAMPING:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_DAMPING;
                break;
            case HASH_ELEMENT_STIFFNESS:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_STIFFNESS;
                break;
            case HASH_ELEMENT_TARGET_VALUE:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_TARGET_VALUE;
                break;
            default:
                return false;
            }
            break;
        case 434:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 35;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCALOFFSET;
                break;
            case HASH_ELEMENT_P:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_P;
                break;
            default:
                return false;
            }
            break;
        case 521:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 35;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCALOFFSET;
                break;
            case HASH_ELEMENT_P:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_P;
                break;
            default:
                return false;
            }
            break;
        case 116:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ROTATE:
                elementData.typeID = 508;
                elementData.generatedElementHash = HASH_ELEMENT_ROTATE;
                break;
            case HASH_ELEMENT_TRANSLATE:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSLATE;
                break;
            default:
                return false;
            }
            break;
        case 117:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ROTATE:
                elementData.typeID = 508;
                elementData.generatedElementHash = HASH_ELEMENT_ROTATE;
                break;
            case HASH_ELEMENT_TRANSLATE:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSLATE;
                break;
            default:
                return false;
            }
            break;
        case 286:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INSTANCE_EFFECT:
                elementData.typeID = 487;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_EFFECT;
                break;
            default:
                return false;
            }
            break;
        case 593:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_LINES:
                elementData.typeID = 434;
                elementData.generatedElementHash = HASH_ELEMENT_LINES;
                break;
            case HASH_ELEMENT_LINESTRIPS:
                elementData.typeID = 521;
                elementData.generatedElementHash = HASH_ELEMENT_LINESTRIPS;
                break;
            case HASH_ELEMENT_POLYGONS:
                elementData.typeID = 389;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGONS;
                break;
            case HASH_ELEMENT_POLYLIST:
                elementData.typeID = 130;
                elementData.generatedElementHash = HASH_ELEMENT_POLYLIST;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 598;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE;
                break;
            case HASH_ELEMENT_TRIANGLES:
                elementData.typeID = 483;
                elementData.generatedElementHash = HASH_ELEMENT_TRIANGLES;
                break;
            case HASH_ELEMENT_TRIFANS:
                elementData.typeID = 612;
                elementData.generatedElementHash = HASH_ELEMENT_TRIFANS;
                break;
            case HASH_ELEMENT_TRISTRIPS:
                elementData.typeID = 312;
                elementData.generatedElementHash = HASH_ELEMENT_TRISTRIPS;
                break;
            case HASH_ELEMENT_VERTICES:
                elementData.typeID = 433;
                elementData.generatedElementHash = HASH_ELEMENT_VERTICES;
                break;
            default:
                return false;
            }
            break;
        case 265:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 598;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE;
                break;
            case HASH_ELEMENT_TARGETS:
                elementData.typeID = 79;
                elementData.generatedElementHash = HASH_ELEMENT_TARGETS;
                break;
            default:
                return false;
            }
            break;
        case 22:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INSTANCE_CAMERA:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_CAMERA;
                break;
            case HASH_ELEMENT_INSTANCE_CONTROLLER:
                elementData.typeID = 215;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_CONTROLLER;
                break;
            case HASH_ELEMENT_INSTANCE_GEOMETRY:
                elementData.typeID = 18;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_GEOMETRY;
                break;
            case HASH_ELEMENT_INSTANCE_LIGHT:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_LIGHT;
                break;
            case HASH_ELEMENT_INSTANCE_NODE:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_NODE;
                break;
            case HASH_ELEMENT_LOOKAT:
                elementData.typeID = 168;
                elementData.generatedElementHash = HASH_ELEMENT_LOOKAT;
                break;
            case HASH_ELEMENT_MATRIX:
                elementData.typeID = 457;
                elementData.generatedElementHash = HASH_ELEMENT_MATRIX;
                break;
            case HASH_ELEMENT_NODE:
                elementData.typeID = 22;
                elementData.generatedElementHash = HASH_ELEMENT_NODE;
                break;
            case HASH_ELEMENT_ROTATE:
                elementData.typeID = 508;
                elementData.generatedElementHash = HASH_ELEMENT_ROTATE;
                break;
            case HASH_ELEMENT_SCALE:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_SCALE;
                break;
            case HASH_ELEMENT_SKEW:
                elementData.typeID = 100;
                elementData.generatedElementHash = HASH_ELEMENT_SKEW;
                break;
            case HASH_ELEMENT_TRANSLATE:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSLATE;
                break;
            default:
                return false;
            }
            break;
        case 150:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 572;
                elementData.generatedElementHash = HASH_ELEMENT_OPTICS__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 349:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASPECT_RATIO:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_ASPECT_RATIO;
                break;
            case HASH_ELEMENT_XMAG:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_XMAG;
                break;
            case HASH_ELEMENT_YMAG:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_YMAG;
                break;
            case HASH_ELEMENT_ZFAR:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_ZFAR;
                break;
            case HASH_ELEMENT_ZNEAR:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_ZNEAR;
                break;
            default:
                return false;
            }
            break;
        case 362:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ALPHA_FUNC:
                elementData.typeID = 337;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC;
                break;
            case HASH_ELEMENT_ALPHA_TEST_ENABLE:
                elementData.typeID = 298;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_TEST_ENABLE;
                break;
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_AUTO_NORMAL_ENABLE:
                elementData.typeID = 174;
                elementData.generatedElementHash = HASH_ELEMENT_AUTO_NORMAL_ENABLE;
                break;
            case HASH_ELEMENT_BLEND_COLOR:
                elementData.typeID = 61;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_COLOR;
                break;
            case HASH_ELEMENT_BLEND_ENABLE:
                elementData.typeID = 272;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_ENABLE;
                break;
            case HASH_ELEMENT_BLEND_EQUATION:
                elementData.typeID = 445;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_EQUATION;
                break;
            case HASH_ELEMENT_BLEND_EQUATION_SEPARATE:
                elementData.typeID = 105;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_EQUATION_SEPARATE;
                break;
            case HASH_ELEMENT_BLEND_FUNC:
                elementData.typeID = 166;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC;
                break;
            case HASH_ELEMENT_BLEND_FUNC_SEPARATE:
                elementData.typeID = 435;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_FUNC_SEPARATE;
                break;
            case HASH_ELEMENT_CLEAR_COLOR:
                elementData.typeID = 40;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_COLOR;
                break;
            case HASH_ELEMENT_CLEAR_DEPTH:
                elementData.typeID = 250;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_DEPTH;
                break;
            case HASH_ELEMENT_CLEAR_STENCIL:
                elementData.typeID = 468;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_STENCIL;
                break;
            case HASH_ELEMENT_CLIP_PLANE:
                elementData.typeID = 446;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLIP_PLANE;
                break;
            case HASH_ELEMENT_CLIP_PLANE_ENABLE:
                elementData.typeID = 181;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLIP_PLANE_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_CLEAR:
                elementData.typeID = 137;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_CLEAR____FX_CLEARCOLOR_COMMON;
                break;
            case HASH_ELEMENT_COLOR_LOGIC_OP_ENABLE:
                elementData.typeID = 278;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_LOGIC_OP_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_MASK:
                elementData.typeID = 242;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_MASK;
                break;
            case HASH_ELEMENT_COLOR_MATERIAL:
                elementData.typeID = 422;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_MATERIAL;
                break;
            case HASH_ELEMENT_COLOR_MATERIAL_ENABLE:
                elementData.typeID = 94;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_MATERIAL_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_TARGET:
                elementData.typeID = 412;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_TARGET____FX_COLORTARGET_COMMON;
                break;
            case HASH_ELEMENT_CULL_FACE:
                elementData.typeID = 354;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CULL_FACE;
                break;
            case HASH_ELEMENT_CULL_FACE_ENABLE:
                elementData.typeID = 583;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CULL_FACE_ENABLE;
                break;
            case HASH_ELEMENT_DEPTH_BOUNDS:
                elementData.typeID = 200;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_BOUNDS;
                break;
            case HASH_ELEMENT_DEPTH_BOUNDS_ENABLE:
                elementData.typeID = 254;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_BOUNDS_ENABLE;
                break;
            case HASH_ELEMENT_DEPTH_CLAMP_ENABLE:
                elementData.typeID = 313;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_CLAMP_ENABLE;
                break;
            case HASH_ELEMENT_DEPTH_CLEAR:
                elementData.typeID = 67;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_CLEAR____FX_CLEARDEPTH_COMMON;
                break;
            case HASH_ELEMENT_DEPTH_FUNC:
                elementData.typeID = 462;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_FUNC;
                break;
            case HASH_ELEMENT_DEPTH_MASK:
                elementData.typeID = 551;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_MASK;
                break;
            case HASH_ELEMENT_DEPTH_RANGE:
                elementData.typeID = 480;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_RANGE;
                break;
            case HASH_ELEMENT_DEPTH_TARGET:
                elementData.typeID = 619;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_TARGET____FX_DEPTHTARGET_COMMON;
                break;
            case HASH_ELEMENT_DEPTH_TEST_ENABLE:
                elementData.typeID = 617;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_TEST_ENABLE;
                break;
            case HASH_ELEMENT_DITHER_ENABLE:
                elementData.typeID = 548;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DITHER_ENABLE;
                break;
            case HASH_ELEMENT_DRAW:
                elementData.typeID = 436;
                elementData.generatedElementHash = HASH_ELEMENT_DRAW;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_FOG_COLOR:
                elementData.typeID = 62;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_COLOR;
                break;
            case HASH_ELEMENT_FOG_COORD_SRC:
                elementData.typeID = 281;
                elementData.generatedElementHash = HASH_ELEMENT_FOG_COORD_SRC;
                break;
            case HASH_ELEMENT_FOG_DENSITY:
                elementData.typeID = 567;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_DENSITY;
                break;
            case HASH_ELEMENT_FOG_ENABLE:
                elementData.typeID = 233;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_ENABLE;
                break;
            case HASH_ELEMENT_FOG_END:
                elementData.typeID = 212;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_END;
                break;
            case HASH_ELEMENT_FOG_MODE:
                elementData.typeID = 143;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_MODE;
                break;
            case HASH_ELEMENT_FOG_START:
                elementData.typeID = 459;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_START;
                break;
            case HASH_ELEMENT_FRONT_FACE:
                elementData.typeID = 120;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FRONT_FACE;
                break;
            case HASH_ELEMENT_GL_HOOK_ABSTRACT:
                elementData.typeID = 78;
                elementData.generatedElementHash = HASH_ELEMENT_GL_HOOK_ABSTRACT;
                break;
            case HASH_ELEMENT_LIGHT_AMBIENT:
                elementData.typeID = 512;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_AMBIENT;
                break;
            case HASH_ELEMENT_LIGHT_CONSTANT_ATTENUATION:
                elementData.typeID = 536;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_CONSTANT_ATTENUATION;
                break;
            case HASH_ELEMENT_LIGHT_DIFFUSE:
                elementData.typeID = 274;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_DIFFUSE;
                break;
            case HASH_ELEMENT_LIGHT_ENABLE:
                elementData.typeID = 55;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_ENABLE;
                break;
            case HASH_ELEMENT_LIGHT_LINEAR_ATTENUATION:
                elementData.typeID = 276;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT_LINEAR_ATTENUATION;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_AMBIENT:
                elementData.typeID = 473;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_MODEL_AMBIENT;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_COLOR_CONTROL:
                elementData.typeID = 297;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT_MODEL_COLOR_CONTROL;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_LOCAL_VIEWER_ENABLE:
                elementData.typeID = 419;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT_MODEL_LOCAL_VIEWER_ENABLE;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_TWO_SIDE_ENABLE:
                elementData.typeID = 183;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_MODEL_TWO_SIDE_ENABLE;
                break;
            case HASH_ELEMENT_LIGHT_POSITION:
                elementData.typeID = 8;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_POSITION;
                break;
            case HASH_ELEMENT_LIGHT_QUADRATIC_ATTENUATION:
                elementData.typeID = 578;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_QUADRATIC_ATTENUATION;
                break;
            case HASH_ELEMENT_LIGHT_SPECULAR:
                elementData.typeID = 371;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPECULAR;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_CUTOFF:
                elementData.typeID = 170;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_CUTOFF;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_DIRECTION:
                elementData.typeID = 308;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_DIRECTION;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_EXPONENT:
                elementData.typeID = 534;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_EXPONENT;
                break;
            case HASH_ELEMENT_LIGHTING_ENABLE:
                elementData.typeID = 342;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHTING_ENABLE;
                break;
            case HASH_ELEMENT_LINE_SMOOTH_ENABLE:
                elementData.typeID = 494;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LINE_SMOOTH_ENABLE;
                break;
            case HASH_ELEMENT_LINE_STIPPLE:
                elementData.typeID = 500;
                elementData.generatedElementHash = HASH_ELEMENT_LINE_STIPPLE;
                break;
            case HASH_ELEMENT_LINE_STIPPLE_ENABLE:
                elementData.typeID = 303;
                elementData.generatedElementHash = HASH_ELEMENT_LINE_STIPPLE_ENABLE;
                break;
            case HASH_ELEMENT_LINE_WIDTH:
                elementData.typeID = 403;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LINE_WIDTH;
                break;
            case HASH_ELEMENT_LOGIC_OP:
                elementData.typeID = 443;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LOGIC_OP;
                break;
            case HASH_ELEMENT_LOGIC_OP_ENABLE:
                elementData.typeID = 326;
                elementData.generatedElementHash = HASH_ELEMENT_LOGIC_OP_ENABLE;
                break;
            case HASH_ELEMENT_MATERIAL_AMBIENT:
                elementData.typeID = 335;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_AMBIENT;
                break;
            case HASH_ELEMENT_MATERIAL_DIFFUSE:
                elementData.typeID = 222;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_DIFFUSE;
                break;
            case HASH_ELEMENT_MATERIAL_EMISSION:
                elementData.typeID = 259;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_EMISSION;
                break;
            case HASH_ELEMENT_MATERIAL_SHININESS:
                elementData.typeID = 414;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_SHININESS;
                break;
            case HASH_ELEMENT_MATERIAL_SPECULAR:
                elementData.typeID = 452;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_SPECULAR;
                break;
            case HASH_ELEMENT_MODEL_VIEW_MATRIX:
                elementData.typeID = 198;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MODEL_VIEW_MATRIX;
                break;
            case HASH_ELEMENT_MULTISAMPLE_ENABLE:
                elementData.typeID = 2;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MULTISAMPLE_ENABLE;
                break;
            case HASH_ELEMENT_NORMALIZE_ENABLE:
                elementData.typeID = 489;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__NORMALIZE_ENABLE;
                break;
            case HASH_ELEMENT_POINT_DISTANCE_ATTENUATION:
                elementData.typeID = 58;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_DISTANCE_ATTENUATION;
                break;
            case HASH_ELEMENT_POINT_FADE_THRESHOLD_SIZE:
                elementData.typeID = 420;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_FADE_THRESHOLD_SIZE;
                break;
            case HASH_ELEMENT_POINT_SIZE:
                elementData.typeID = 328;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE;
                break;
            case HASH_ELEMENT_POINT_SIZE_MAX:
                elementData.typeID = 310;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE_MAX;
                break;
            case HASH_ELEMENT_POINT_SIZE_MIN:
                elementData.typeID = 44;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE_MIN;
                break;
            case HASH_ELEMENT_POINT_SMOOTH_ENABLE:
                elementData.typeID = 194;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SMOOTH_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_MODE:
                elementData.typeID = 321;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_MODE;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET:
                elementData.typeID = 125;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POLYGON_OFFSET;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET_FILL_ENABLE:
                elementData.typeID = 218;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POLYGON_OFFSET_FILL_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET_LINE_ENABLE:
                elementData.typeID = 189;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_OFFSET_LINE_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET_POINT_ENABLE:
                elementData.typeID = 542;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_OFFSET_POINT_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_SMOOTH_ENABLE:
                elementData.typeID = 451;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_SMOOTH_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_STIPPLE_ENABLE:
                elementData.typeID = 148;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_STIPPLE_ENABLE;
                break;
            case HASH_ELEMENT_PROJECTION_MATRIX:
                elementData.typeID = 42;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__PROJECTION_MATRIX;
                break;
            case HASH_ELEMENT_RESCALE_NORMAL_ENABLE:
                elementData.typeID = 292;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__RESCALE_NORMAL_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_ALPHA_TO_COVERAGE_ENABLE:
                elementData.typeID = 112;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_ALPHA_TO_ONE_ENABLE:
                elementData.typeID = 347;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_ONE_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_COVERAGE_ENABLE:
                elementData.typeID = 261;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_COVERAGE_ENABLE;
                break;
            case HASH_ELEMENT_SCISSOR:
                elementData.typeID = 441;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SCISSOR;
                break;
            case HASH_ELEMENT_SCISSOR_TEST_ENABLE:
                elementData.typeID = 464;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SCISSOR_TEST_ENABLE;
                break;
            case HASH_ELEMENT_SHADE_MODEL:
                elementData.typeID = 295;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADE_MODEL;
                break;
            case HASH_ELEMENT_SHADER:
                elementData.typeID = 485;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER;
                break;
            case HASH_ELEMENT_STENCIL_CLEAR:
                elementData.typeID = 585;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_CLEAR____FX_CLEARSTENCIL_COMMON;
                break;
            case HASH_ELEMENT_STENCIL_FUNC:
                elementData.typeID = 562;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC;
                break;
            case HASH_ELEMENT_STENCIL_FUNC_SEPARATE:
                elementData.typeID = 145;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_FUNC_SEPARATE;
                break;
            case HASH_ELEMENT_STENCIL_MASK:
                elementData.typeID = 604;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_MASK;
                break;
            case HASH_ELEMENT_STENCIL_MASK_SEPARATE:
                elementData.typeID = 496;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_MASK_SEPARATE;
                break;
            case HASH_ELEMENT_STENCIL_OP:
                elementData.typeID = 23;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP;
                break;
            case HASH_ELEMENT_STENCIL_OP_SEPARATE:
                elementData.typeID = 440;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_OP_SEPARATE;
                break;
            case HASH_ELEMENT_STENCIL_TARGET:
                elementData.typeID = 26;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_TARGET____FX_STENCILTARGET_COMMON;
                break;
            case HASH_ELEMENT_STENCIL_TEST_ENABLE:
                elementData.typeID = 601;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_TEST_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE1D:
                elementData.typeID = 331;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE1D;
                break;
            case HASH_ELEMENT_TEXTURE1D_ENABLE:
                elementData.typeID = 600;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE1D_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE2D:
                elementData.typeID = 149;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE2D;
                break;
            case HASH_ELEMENT_TEXTURE2D_ENABLE:
                elementData.typeID = 14;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE2D_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE3D:
                elementData.typeID = 620;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE3D;
                break;
            case HASH_ELEMENT_TEXTURE3D_ENABLE:
                elementData.typeID = 606;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE3D_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURECUBE:
                elementData.typeID = 589;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURECUBE;
                break;
            case HASH_ELEMENT_TEXTURECUBE_ENABLE:
                elementData.typeID = 411;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURECUBE_ENABLE;
                break;
            case HASH_ELEMENT_TEXTUREDEPTH:
                elementData.typeID = 516;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTUREDEPTH;
                break;
            case HASH_ELEMENT_TEXTUREDEPTH_ENABLE:
                elementData.typeID = 93;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTUREDEPTH_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURERECT:
                elementData.typeID = 240;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURERECT;
                break;
            case HASH_ELEMENT_TEXTURERECT_ENABLE:
                elementData.typeID = 271;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURERECT_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE_ENV_COLOR:
                elementData.typeID = 393;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_ENV_COLOR;
                break;
            case HASH_ELEMENT_TEXTURE_ENV_MODE:
                elementData.typeID = 66;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_ENV_MODE;
                break;
            default:
                return false;
            }
            break;
        case 363:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ALPHA_FUNC:
                elementData.typeID = 338;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC;
                break;
            case HASH_ELEMENT_ALPHA_TEST_ENABLE:
                elementData.typeID = 299;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_TEST_ENABLE;
                break;
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_BLEND_ENABLE:
                elementData.typeID = 273;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_ENABLE;
                break;
            case HASH_ELEMENT_BLEND_FUNC:
                elementData.typeID = 167;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC;
                break;
            case HASH_ELEMENT_CLEAR_COLOR:
                elementData.typeID = 41;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_COLOR;
                break;
            case HASH_ELEMENT_CLEAR_DEPTH:
                elementData.typeID = 251;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_DEPTH;
                break;
            case HASH_ELEMENT_CLEAR_STENCIL:
                elementData.typeID = 469;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_STENCIL;
                break;
            case HASH_ELEMENT_CLIP_PLANE:
                elementData.typeID = 447;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLIP_PLANE;
                break;
            case HASH_ELEMENT_CLIP_PLANE_ENABLE:
                elementData.typeID = 182;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLIP_PLANE_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_CLEAR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_CLEAR____FX_COLOR_COMMON;
                break;
            case HASH_ELEMENT_COLOR_LOGIC_OP_ENABLE:
                elementData.typeID = 279;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_LOGIC_OP_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_MASK:
                elementData.typeID = 243;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_MASK;
                break;
            case HASH_ELEMENT_COLOR_MATERIAL_ENABLE:
                elementData.typeID = 95;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_MATERIAL_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_TARGET:
                elementData.typeID = 27;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_TARGET____GLES_RENDERTARGET_COMMON;
                break;
            case HASH_ELEMENT_CULL_FACE:
                elementData.typeID = 355;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CULL_FACE;
                break;
            case HASH_ELEMENT_CULL_FACE_ENABLE:
                elementData.typeID = 584;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CULL_FACE_ENABLE;
                break;
            case HASH_ELEMENT_DEPTH_CLEAR:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_CLEAR____FLOAT;
                break;
            case HASH_ELEMENT_DEPTH_FUNC:
                elementData.typeID = 463;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_FUNC;
                break;
            case HASH_ELEMENT_DEPTH_MASK:
                elementData.typeID = 552;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_MASK;
                break;
            case HASH_ELEMENT_DEPTH_RANGE:
                elementData.typeID = 481;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_RANGE;
                break;
            case HASH_ELEMENT_DEPTH_TARGET:
                elementData.typeID = 27;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_TARGET____GLES_RENDERTARGET_COMMON;
                break;
            case HASH_ELEMENT_DEPTH_TEST_ENABLE:
                elementData.typeID = 618;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_TEST_ENABLE;
                break;
            case HASH_ELEMENT_DITHER_ENABLE:
                elementData.typeID = 549;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DITHER_ENABLE;
                break;
            case HASH_ELEMENT_DRAW:
                elementData.typeID = 436;
                elementData.generatedElementHash = HASH_ELEMENT_DRAW;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_FOG_COLOR:
                elementData.typeID = 63;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_COLOR;
                break;
            case HASH_ELEMENT_FOG_DENSITY:
                elementData.typeID = 568;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_DENSITY;
                break;
            case HASH_ELEMENT_FOG_ENABLE:
                elementData.typeID = 234;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_ENABLE;
                break;
            case HASH_ELEMENT_FOG_END:
                elementData.typeID = 213;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_END;
                break;
            case HASH_ELEMENT_FOG_MODE:
                elementData.typeID = 144;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_MODE;
                break;
            case HASH_ELEMENT_FOG_START:
                elementData.typeID = 460;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_START;
                break;
            case HASH_ELEMENT_FRONT_FACE:
                elementData.typeID = 121;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FRONT_FACE;
                break;
            case HASH_ELEMENT_LIGHT_AMBIENT:
                elementData.typeID = 513;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_AMBIENT;
                break;
            case HASH_ELEMENT_LIGHT_CONSTANT_ATTENUATION:
                elementData.typeID = 537;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_CONSTANT_ATTENUATION;
                break;
            case HASH_ELEMENT_LIGHT_DIFFUSE:
                elementData.typeID = 275;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_DIFFUSE;
                break;
            case HASH_ELEMENT_LIGHT_ENABLE:
                elementData.typeID = 56;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_ENABLE;
                break;
            case HASH_ELEMENT_LIGHT_LINEAR_ATTENUTATION:
                elementData.typeID = 373;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT_LINEAR_ATTENUTATION;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_AMBIENT:
                elementData.typeID = 474;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_MODEL_AMBIENT;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_TWO_SIDE_ENABLE:
                elementData.typeID = 184;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_MODEL_TWO_SIDE_ENABLE;
                break;
            case HASH_ELEMENT_LIGHT_POSITION:
                elementData.typeID = 9;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_POSITION;
                break;
            case HASH_ELEMENT_LIGHT_QUADRATIC_ATTENUATION:
                elementData.typeID = 579;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_QUADRATIC_ATTENUATION;
                break;
            case HASH_ELEMENT_LIGHT_SPECULAR:
                elementData.typeID = 372;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPECULAR;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_CUTOFF:
                elementData.typeID = 171;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_CUTOFF;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_DIRECTION:
                elementData.typeID = 309;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_DIRECTION;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_EXPONENT:
                elementData.typeID = 535;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_EXPONENT;
                break;
            case HASH_ELEMENT_LIGHTING_ENABLE:
                elementData.typeID = 343;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHTING_ENABLE;
                break;
            case HASH_ELEMENT_LINE_SMOOTH_ENABLE:
                elementData.typeID = 495;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LINE_SMOOTH_ENABLE;
                break;
            case HASH_ELEMENT_LINE_WIDTH:
                elementData.typeID = 404;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LINE_WIDTH;
                break;
            case HASH_ELEMENT_LOGIC_OP:
                elementData.typeID = 444;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LOGIC_OP;
                break;
            case HASH_ELEMENT_MATERIAL_AMBIENT:
                elementData.typeID = 336;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_AMBIENT;
                break;
            case HASH_ELEMENT_MATERIAL_DIFFUSE:
                elementData.typeID = 223;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_DIFFUSE;
                break;
            case HASH_ELEMENT_MATERIAL_EMISSION:
                elementData.typeID = 260;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_EMISSION;
                break;
            case HASH_ELEMENT_MATERIAL_SHININESS:
                elementData.typeID = 415;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_SHININESS;
                break;
            case HASH_ELEMENT_MATERIAL_SPECULAR:
                elementData.typeID = 453;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_SPECULAR;
                break;
            case HASH_ELEMENT_MODEL_VIEW_MATRIX:
                elementData.typeID = 199;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MODEL_VIEW_MATRIX;
                break;
            case HASH_ELEMENT_MULTISAMPLE_ENABLE:
                elementData.typeID = 3;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MULTISAMPLE_ENABLE;
                break;
            case HASH_ELEMENT_NORMALIZE_ENABLE:
                elementData.typeID = 490;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__NORMALIZE_ENABLE;
                break;
            case HASH_ELEMENT_POINT_DISTANCE_ATTENUATION:
                elementData.typeID = 59;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_DISTANCE_ATTENUATION;
                break;
            case HASH_ELEMENT_POINT_FADE_THRESHOLD_SIZE:
                elementData.typeID = 421;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_FADE_THRESHOLD_SIZE;
                break;
            case HASH_ELEMENT_POINT_SIZE:
                elementData.typeID = 329;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE;
                break;
            case HASH_ELEMENT_POINT_SIZE_MAX:
                elementData.typeID = 311;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE_MAX;
                break;
            case HASH_ELEMENT_POINT_SIZE_MIN:
                elementData.typeID = 45;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE_MIN;
                break;
            case HASH_ELEMENT_POINT_SMOOTH_ENABLE:
                elementData.typeID = 195;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SMOOTH_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET:
                elementData.typeID = 126;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POLYGON_OFFSET;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET_FILL_ENABLE:
                elementData.typeID = 219;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POLYGON_OFFSET_FILL_ENABLE;
                break;
            case HASH_ELEMENT_PROJECTION_MATRIX:
                elementData.typeID = 43;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__PROJECTION_MATRIX;
                break;
            case HASH_ELEMENT_RESCALE_NORMAL_ENABLE:
                elementData.typeID = 293;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__RESCALE_NORMAL_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_ALPHA_TO_COVERAGE_ENABLE:
                elementData.typeID = 113;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_ALPHA_TO_ONE_ENABLE:
                elementData.typeID = 348;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_ONE_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_COVERAGE_ENABLE:
                elementData.typeID = 262;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_COVERAGE_ENABLE;
                break;
            case HASH_ELEMENT_SCISSOR:
                elementData.typeID = 442;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SCISSOR;
                break;
            case HASH_ELEMENT_SCISSOR_TEST_ENABLE:
                elementData.typeID = 465;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SCISSOR_TEST_ENABLE;
                break;
            case HASH_ELEMENT_SHADE_MODEL:
                elementData.typeID = 296;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SHADE_MODEL;
                break;
            case HASH_ELEMENT_STENCIL_CLEAR:
                elementData.typeID = 586;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_CLEAR____BYTE;
                break;
            case HASH_ELEMENT_STENCIL_FUNC:
                elementData.typeID = 563;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC;
                break;
            case HASH_ELEMENT_STENCIL_MASK:
                elementData.typeID = 605;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_MASK;
                break;
            case HASH_ELEMENT_STENCIL_OP:
                elementData.typeID = 24;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP;
                break;
            case HASH_ELEMENT_STENCIL_TARGET:
                elementData.typeID = 27;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_TARGET____GLES_RENDERTARGET_COMMON;
                break;
            case HASH_ELEMENT_STENCIL_TEST_ENABLE:
                elementData.typeID = 602;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_TEST_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE_PIPELINE:
                elementData.typeID = 340;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__TEXTURE_PIPELINE;
                break;
            case HASH_ELEMENT_TEXTURE_PIPELINE_ENABLE:
                elementData.typeID = 210;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_PIPELINE_ENABLE;
                break;
            default:
                return false;
            }
            break;
        case 364:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ALPHA_FUNC:
                elementData.typeID = 337;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC;
                break;
            case HASH_ELEMENT_ALPHA_TEST_ENABLE:
                elementData.typeID = 298;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_TEST_ENABLE;
                break;
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_AUTO_NORMAL_ENABLE:
                elementData.typeID = 174;
                elementData.generatedElementHash = HASH_ELEMENT_AUTO_NORMAL_ENABLE;
                break;
            case HASH_ELEMENT_BLEND_COLOR:
                elementData.typeID = 61;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_COLOR;
                break;
            case HASH_ELEMENT_BLEND_ENABLE:
                elementData.typeID = 272;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_ENABLE;
                break;
            case HASH_ELEMENT_BLEND_EQUATION:
                elementData.typeID = 445;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_EQUATION;
                break;
            case HASH_ELEMENT_BLEND_EQUATION_SEPARATE:
                elementData.typeID = 105;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_EQUATION_SEPARATE;
                break;
            case HASH_ELEMENT_BLEND_FUNC:
                elementData.typeID = 166;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC;
                break;
            case HASH_ELEMENT_BLEND_FUNC_SEPARATE:
                elementData.typeID = 435;
                elementData.generatedElementHash = HASH_ELEMENT_BLEND_FUNC_SEPARATE;
                break;
            case HASH_ELEMENT_CLEAR_COLOR:
                elementData.typeID = 40;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_COLOR;
                break;
            case HASH_ELEMENT_CLEAR_DEPTH:
                elementData.typeID = 250;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_DEPTH;
                break;
            case HASH_ELEMENT_CLEAR_STENCIL:
                elementData.typeID = 468;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_STENCIL;
                break;
            case HASH_ELEMENT_CLIP_PLANE:
                elementData.typeID = 446;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLIP_PLANE;
                break;
            case HASH_ELEMENT_CLIP_PLANE_ENABLE:
                elementData.typeID = 181;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLIP_PLANE_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_CLEAR:
                elementData.typeID = 137;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_CLEAR____FX_CLEARCOLOR_COMMON;
                break;
            case HASH_ELEMENT_COLOR_LOGIC_OP_ENABLE:
                elementData.typeID = 278;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_LOGIC_OP_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_MASK:
                elementData.typeID = 242;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_MASK;
                break;
            case HASH_ELEMENT_COLOR_MATERIAL:
                elementData.typeID = 422;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_MATERIAL;
                break;
            case HASH_ELEMENT_COLOR_MATERIAL_ENABLE:
                elementData.typeID = 94;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_MATERIAL_ENABLE;
                break;
            case HASH_ELEMENT_COLOR_TARGET:
                elementData.typeID = 412;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR_TARGET____FX_COLORTARGET_COMMON;
                break;
            case HASH_ELEMENT_CULL_FACE:
                elementData.typeID = 354;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CULL_FACE;
                break;
            case HASH_ELEMENT_CULL_FACE_ENABLE:
                elementData.typeID = 583;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CULL_FACE_ENABLE;
                break;
            case HASH_ELEMENT_DEPTH_BOUNDS:
                elementData.typeID = 200;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_BOUNDS;
                break;
            case HASH_ELEMENT_DEPTH_BOUNDS_ENABLE:
                elementData.typeID = 254;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_BOUNDS_ENABLE;
                break;
            case HASH_ELEMENT_DEPTH_CLAMP_ENABLE:
                elementData.typeID = 313;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_CLAMP_ENABLE;
                break;
            case HASH_ELEMENT_DEPTH_CLEAR:
                elementData.typeID = 67;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_CLEAR____FX_CLEARDEPTH_COMMON;
                break;
            case HASH_ELEMENT_DEPTH_FUNC:
                elementData.typeID = 462;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_FUNC;
                break;
            case HASH_ELEMENT_DEPTH_MASK:
                elementData.typeID = 551;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_MASK;
                break;
            case HASH_ELEMENT_DEPTH_RANGE:
                elementData.typeID = 480;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_RANGE;
                break;
            case HASH_ELEMENT_DEPTH_TARGET:
                elementData.typeID = 619;
                elementData.generatedElementHash = HASH_ELEMENT_DEPTH_TARGET____FX_DEPTHTARGET_COMMON;
                break;
            case HASH_ELEMENT_DEPTH_TEST_ENABLE:
                elementData.typeID = 617;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_TEST_ENABLE;
                break;
            case HASH_ELEMENT_DITHER_ENABLE:
                elementData.typeID = 548;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DITHER_ENABLE;
                break;
            case HASH_ELEMENT_DRAW:
                elementData.typeID = 436;
                elementData.generatedElementHash = HASH_ELEMENT_DRAW;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_FOG_COLOR:
                elementData.typeID = 62;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_COLOR;
                break;
            case HASH_ELEMENT_FOG_COORD_SRC:
                elementData.typeID = 281;
                elementData.generatedElementHash = HASH_ELEMENT_FOG_COORD_SRC;
                break;
            case HASH_ELEMENT_FOG_DENSITY:
                elementData.typeID = 567;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_DENSITY;
                break;
            case HASH_ELEMENT_FOG_ENABLE:
                elementData.typeID = 233;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_ENABLE;
                break;
            case HASH_ELEMENT_FOG_END:
                elementData.typeID = 212;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_END;
                break;
            case HASH_ELEMENT_FOG_MODE:
                elementData.typeID = 143;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_MODE;
                break;
            case HASH_ELEMENT_FOG_START:
                elementData.typeID = 459;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_START;
                break;
            case HASH_ELEMENT_FRONT_FACE:
                elementData.typeID = 120;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FRONT_FACE;
                break;
            case HASH_ELEMENT_GL_HOOK_ABSTRACT:
                elementData.typeID = 78;
                elementData.generatedElementHash = HASH_ELEMENT_GL_HOOK_ABSTRACT;
                break;
            case HASH_ELEMENT_LIGHT_AMBIENT:
                elementData.typeID = 512;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_AMBIENT;
                break;
            case HASH_ELEMENT_LIGHT_CONSTANT_ATTENUATION:
                elementData.typeID = 536;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_CONSTANT_ATTENUATION;
                break;
            case HASH_ELEMENT_LIGHT_DIFFUSE:
                elementData.typeID = 274;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_DIFFUSE;
                break;
            case HASH_ELEMENT_LIGHT_ENABLE:
                elementData.typeID = 55;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_ENABLE;
                break;
            case HASH_ELEMENT_LIGHT_LINEAR_ATTENUATION:
                elementData.typeID = 276;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT_LINEAR_ATTENUATION;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_AMBIENT:
                elementData.typeID = 473;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_MODEL_AMBIENT;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_COLOR_CONTROL:
                elementData.typeID = 297;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT_MODEL_COLOR_CONTROL;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_LOCAL_VIEWER_ENABLE:
                elementData.typeID = 419;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT_MODEL_LOCAL_VIEWER_ENABLE;
                break;
            case HASH_ELEMENT_LIGHT_MODEL_TWO_SIDE_ENABLE:
                elementData.typeID = 183;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_MODEL_TWO_SIDE_ENABLE;
                break;
            case HASH_ELEMENT_LIGHT_POSITION:
                elementData.typeID = 8;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_POSITION;
                break;
            case HASH_ELEMENT_LIGHT_QUADRATIC_ATTENUATION:
                elementData.typeID = 578;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_QUADRATIC_ATTENUATION;
                break;
            case HASH_ELEMENT_LIGHT_SPECULAR:
                elementData.typeID = 371;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPECULAR;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_CUTOFF:
                elementData.typeID = 170;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_CUTOFF;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_DIRECTION:
                elementData.typeID = 308;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_DIRECTION;
                break;
            case HASH_ELEMENT_LIGHT_SPOT_EXPONENT:
                elementData.typeID = 534;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_EXPONENT;
                break;
            case HASH_ELEMENT_LIGHTING_ENABLE:
                elementData.typeID = 342;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHTING_ENABLE;
                break;
            case HASH_ELEMENT_LINE_SMOOTH_ENABLE:
                elementData.typeID = 494;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LINE_SMOOTH_ENABLE;
                break;
            case HASH_ELEMENT_LINE_STIPPLE:
                elementData.typeID = 500;
                elementData.generatedElementHash = HASH_ELEMENT_LINE_STIPPLE;
                break;
            case HASH_ELEMENT_LINE_STIPPLE_ENABLE:
                elementData.typeID = 303;
                elementData.generatedElementHash = HASH_ELEMENT_LINE_STIPPLE_ENABLE;
                break;
            case HASH_ELEMENT_LINE_WIDTH:
                elementData.typeID = 403;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LINE_WIDTH;
                break;
            case HASH_ELEMENT_LOGIC_OP:
                elementData.typeID = 443;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LOGIC_OP;
                break;
            case HASH_ELEMENT_LOGIC_OP_ENABLE:
                elementData.typeID = 326;
                elementData.generatedElementHash = HASH_ELEMENT_LOGIC_OP_ENABLE;
                break;
            case HASH_ELEMENT_MATERIAL_AMBIENT:
                elementData.typeID = 335;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_AMBIENT;
                break;
            case HASH_ELEMENT_MATERIAL_DIFFUSE:
                elementData.typeID = 222;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_DIFFUSE;
                break;
            case HASH_ELEMENT_MATERIAL_EMISSION:
                elementData.typeID = 259;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_EMISSION;
                break;
            case HASH_ELEMENT_MATERIAL_SHININESS:
                elementData.typeID = 414;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_SHININESS;
                break;
            case HASH_ELEMENT_MATERIAL_SPECULAR:
                elementData.typeID = 452;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_SPECULAR;
                break;
            case HASH_ELEMENT_MODEL_VIEW_MATRIX:
                elementData.typeID = 198;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MODEL_VIEW_MATRIX;
                break;
            case HASH_ELEMENT_MULTISAMPLE_ENABLE:
                elementData.typeID = 2;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MULTISAMPLE_ENABLE;
                break;
            case HASH_ELEMENT_NORMALIZE_ENABLE:
                elementData.typeID = 489;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__NORMALIZE_ENABLE;
                break;
            case HASH_ELEMENT_POINT_DISTANCE_ATTENUATION:
                elementData.typeID = 58;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_DISTANCE_ATTENUATION;
                break;
            case HASH_ELEMENT_POINT_FADE_THRESHOLD_SIZE:
                elementData.typeID = 420;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_FADE_THRESHOLD_SIZE;
                break;
            case HASH_ELEMENT_POINT_SIZE:
                elementData.typeID = 328;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE;
                break;
            case HASH_ELEMENT_POINT_SIZE_MAX:
                elementData.typeID = 310;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE_MAX;
                break;
            case HASH_ELEMENT_POINT_SIZE_MIN:
                elementData.typeID = 44;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE_MIN;
                break;
            case HASH_ELEMENT_POINT_SMOOTH_ENABLE:
                elementData.typeID = 194;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SMOOTH_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_MODE:
                elementData.typeID = 321;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_MODE;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET:
                elementData.typeID = 125;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POLYGON_OFFSET;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET_FILL_ENABLE:
                elementData.typeID = 218;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POLYGON_OFFSET_FILL_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET_LINE_ENABLE:
                elementData.typeID = 189;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_OFFSET_LINE_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_OFFSET_POINT_ENABLE:
                elementData.typeID = 542;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_OFFSET_POINT_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_SMOOTH_ENABLE:
                elementData.typeID = 451;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_SMOOTH_ENABLE;
                break;
            case HASH_ELEMENT_POLYGON_STIPPLE_ENABLE:
                elementData.typeID = 148;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_STIPPLE_ENABLE;
                break;
            case HASH_ELEMENT_PROJECTION_MATRIX:
                elementData.typeID = 42;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__PROJECTION_MATRIX;
                break;
            case HASH_ELEMENT_RESCALE_NORMAL_ENABLE:
                elementData.typeID = 292;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__RESCALE_NORMAL_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_ALPHA_TO_COVERAGE_ENABLE:
                elementData.typeID = 112;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_ALPHA_TO_ONE_ENABLE:
                elementData.typeID = 347;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_ONE_ENABLE;
                break;
            case HASH_ELEMENT_SAMPLE_COVERAGE_ENABLE:
                elementData.typeID = 261;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_COVERAGE_ENABLE;
                break;
            case HASH_ELEMENT_SCISSOR:
                elementData.typeID = 441;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SCISSOR;
                break;
            case HASH_ELEMENT_SCISSOR_TEST_ENABLE:
                elementData.typeID = 464;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SCISSOR_TEST_ENABLE;
                break;
            case HASH_ELEMENT_SHADE_MODEL:
                elementData.typeID = 295;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADE_MODEL;
                break;
            case HASH_ELEMENT_SHADER:
                elementData.typeID = 486;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER;
                break;
            case HASH_ELEMENT_STENCIL_CLEAR:
                elementData.typeID = 585;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_CLEAR____FX_CLEARSTENCIL_COMMON;
                break;
            case HASH_ELEMENT_STENCIL_FUNC:
                elementData.typeID = 562;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC;
                break;
            case HASH_ELEMENT_STENCIL_FUNC_SEPARATE:
                elementData.typeID = 145;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_FUNC_SEPARATE;
                break;
            case HASH_ELEMENT_STENCIL_MASK:
                elementData.typeID = 604;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_MASK;
                break;
            case HASH_ELEMENT_STENCIL_MASK_SEPARATE:
                elementData.typeID = 496;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_MASK_SEPARATE;
                break;
            case HASH_ELEMENT_STENCIL_OP:
                elementData.typeID = 23;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP;
                break;
            case HASH_ELEMENT_STENCIL_OP_SEPARATE:
                elementData.typeID = 440;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_OP_SEPARATE;
                break;
            case HASH_ELEMENT_STENCIL_TARGET:
                elementData.typeID = 26;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_TARGET____FX_STENCILTARGET_COMMON;
                break;
            case HASH_ELEMENT_STENCIL_TEST_ENABLE:
                elementData.typeID = 601;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_TEST_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE1D:
                elementData.typeID = 331;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE1D;
                break;
            case HASH_ELEMENT_TEXTURE1D_ENABLE:
                elementData.typeID = 600;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE1D_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE2D:
                elementData.typeID = 149;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE2D;
                break;
            case HASH_ELEMENT_TEXTURE2D_ENABLE:
                elementData.typeID = 14;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE2D_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE3D:
                elementData.typeID = 620;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE3D;
                break;
            case HASH_ELEMENT_TEXTURE3D_ENABLE:
                elementData.typeID = 606;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE3D_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURECUBE:
                elementData.typeID = 589;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURECUBE;
                break;
            case HASH_ELEMENT_TEXTURECUBE_ENABLE:
                elementData.typeID = 411;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURECUBE_ENABLE;
                break;
            case HASH_ELEMENT_TEXTUREDEPTH:
                elementData.typeID = 516;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTUREDEPTH;
                break;
            case HASH_ELEMENT_TEXTUREDEPTH_ENABLE:
                elementData.typeID = 93;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTUREDEPTH_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURERECT:
                elementData.typeID = 240;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURERECT;
                break;
            case HASH_ELEMENT_TEXTURERECT_ENABLE:
                elementData.typeID = 271;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURERECT_ENABLE;
                break;
            case HASH_ELEMENT_TEXTURE_ENV_COLOR:
                elementData.typeID = 393;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_ENV_COLOR;
                break;
            case HASH_ELEMENT_TEXTURE_ENV_MODE:
                elementData.typeID = 66;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_ENV_MODE;
                break;
            default:
                return false;
            }
            break;
        case 186:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASPECT_RATIO:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_ASPECT_RATIO;
                break;
            case HASH_ELEMENT_XFOV:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_XFOV;
                break;
            case HASH_ELEMENT_YFOV:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_YFOV;
                break;
            case HASH_ELEMENT_ZFAR:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_ZFAR;
                break;
            case HASH_ELEMENT_ZNEAR:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_ZNEAR;
                break;
            default:
                return false;
            }
            break;
        case 608:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_AMBIENT:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_AMBIENT____COMMON_COLOR_OR_TEXTURE_TYPE;
                break;
            case HASH_ELEMENT_DIFFUSE:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_DIFFUSE;
                break;
            case HASH_ELEMENT_EMISSION:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_EMISSION;
                break;
            case HASH_ELEMENT_INDEX_OF_REFRACTION:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_INDEX_OF_REFRACTION;
                break;
            case HASH_ELEMENT_REFLECTIVE:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_REFLECTIVE;
                break;
            case HASH_ELEMENT_REFLECTIVITY:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_REFLECTIVITY;
                break;
            case HASH_ELEMENT_SHININESS:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_SHININESS;
                break;
            case HASH_ELEMENT_SPECULAR:
                elementData.typeID = 19;
                elementData.generatedElementHash = HASH_ELEMENT_SPECULAR;
                break;
            case HASH_ELEMENT_TRANSPARENCY:
                elementData.typeID = 173;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSPARENCY;
                break;
            case HASH_ELEMENT_TRANSPARENT:
                elementData.typeID = 217;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSPARENT;
                break;
            default:
                return false;
            }
            break;
        case 417:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_H:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_H;
                break;
            case HASH_ELEMENT_P:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_P;
                break;
            default:
                return false;
            }
            break;
        case 255:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 573;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 208:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INSTANCE_PHYSICS_MODEL:
                elementData.typeID = 482;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_PHYSICS_MODEL;
                break;
            case HASH_ELEMENT_RIGID_BODY:
                elementData.typeID = 37;
                elementData.generatedElementHash = HASH_ELEMENT_RIGID_BODY;
                break;
            case HASH_ELEMENT_RIGID_CONSTRAINT:
                elementData.typeID = 550;
                elementData.generatedElementHash = HASH_ELEMENT_RIGID_CONSTRAINT;
                break;
            default:
                return false;
            }
            break;
        case 492:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INSTANCE_FORCE_FIELD:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_FORCE_FIELD;
                break;
            case HASH_ELEMENT_INSTANCE_PHYSICS_MODEL:
                elementData.typeID = 482;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_PHYSICS_MODEL;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 574;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_SCENE__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 305:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EQUATION:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_EQUATION;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 57:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_COLOR:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR____TARGETABLEFLOAT3;
                break;
            case HASH_ELEMENT_CONSTANT_ATTENUATION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_CONSTANT_ATTENUATION;
                break;
            case HASH_ELEMENT_LINEAR_ATTENUATION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_LINEAR_ATTENUATION;
                break;
            case HASH_ELEMENT_QUADRATIC_ATTENUATION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_QUADRATIC_ATTENUATION;
                break;
            default:
                return false;
            }
            break;
        case 321:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FACE:
                elementData.typeID = 368;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_MODE__FACE;
                break;
            case HASH_ELEMENT_MODE:
                elementData.typeID = 232;
                elementData.generatedElementHash = HASH_ELEMENT_POLYGON_MODE__MODE;
                break;
            default:
                return false;
            }
            break;
        case 389:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 35;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCALOFFSET;
                break;
            case HASH_ELEMENT_P:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_P;
                break;
            case HASH_ELEMENT_PH:
                elementData.typeID = 417;
                elementData.generatedElementHash = HASH_ELEMENT_PH;
                break;
            default:
                return false;
            }
            break;
        case 130:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 35;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCALOFFSET;
                break;
            case HASH_ELEMENT_P:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_P;
                break;
            case HASH_ELEMENT_VCOUNT:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_VCOUNT;
                break;
            default:
                return false;
            }
            break;
        case 376:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ORDER:
                elementData.typeID = 488;
                elementData.generatedElementHash = HASH_ELEMENT_ORDER;
                break;
            default:
                return false;
            }
            break;
        case 133:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_CODE:
                elementData.typeID = 253;
                elementData.generatedElementHash = HASH_ELEMENT_CODE;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_INCLUDE:
                elementData.typeID = 564;
                elementData.generatedElementHash = HASH_ELEMENT_INCLUDE;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 553;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____CG_NEWPARAM;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 526;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG__TECHNIQUE;
                break;
            default:
                return false;
            }
            break;
        case 407:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 554;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____COMMON_NEWPARAM_TYPE;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 527;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_COMMON__TECHNIQUE;
                break;
            default:
                return false;
            }
            break;
        case 172:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 556;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____GLES_NEWPARAM;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 528;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE;
                break;
            default:
                return false;
            }
            break;
        case 139:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_CODE:
                elementData.typeID = 253;
                elementData.generatedElementHash = HASH_ELEMENT_CODE;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_INCLUDE:
                elementData.typeID = 564;
                elementData.generatedElementHash = HASH_ELEMENT_INCLUDE;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 557;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____GLSL_NEWPARAM;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 529;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE;
                break;
            default:
                return false;
            }
            break;
        case 85:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_ROTATE:
                elementData.typeID = 508;
                elementData.generatedElementHash = HASH_ELEMENT_ROTATE;
                break;
            case HASH_ELEMENT_TRANSLATE:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSLATE;
                break;
            default:
                return false;
            }
            break;
        case 84:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_INSTANCE_EFFECT:
                elementData.typeID = 487;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_EFFECT;
                break;
            case HASH_ELEMENT_LAYER:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_LAYER;
                break;
            default:
                return false;
            }
            break;
        case 37:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 575;
                elementData.generatedElementHash = HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 550:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ATTACHMENT:
                elementData.typeID = 169;
                elementData.generatedElementHash = HASH_ELEMENT_ATTACHMENT;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_REF_ATTACHMENT:
                elementData.typeID = 85;
                elementData.generatedElementHash = HASH_ELEMENT_REF_ATTACHMENT;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 576;
                elementData.generatedElementHash = HASH_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 467:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 34;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCAL;
                break;
            default:
                return false;
            }
            break;
        case 395:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INSTANCE_PHYSICS_SCENE:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_PHYSICS_SCENE;
                break;
            case HASH_ELEMENT_INSTANCE_VISUAL_SCENE:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_VISUAL_SCENE;
                break;
            default:
                return false;
            }
            break;
        case 623:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 204;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 316;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 613;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 74;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____STRING;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 324;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 439;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 54;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 202;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 504;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 192;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 152;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 449;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 123;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 533;
                elementData.generatedElementHash = HASH_ELEMENT_INT____INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 285;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 405;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 129;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____INT4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 360;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____FX_SAMPLER1D_COMMON;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 50;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____FX_SAMPLER2D_COMMON;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 596;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____FX_SAMPLER3D_COMMON;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 498;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____FX_SAMPLERCUBE_COMMON;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 268;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____FX_SAMPLERDEPTH_COMMON;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 103;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____FX_SAMPLERRECT_COMMON;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 226;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____FX_SURFACE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 624:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 204;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 316;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 613;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 74;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 264;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GLES_ENUMERATION;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 324;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 439;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 54;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 202;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 504;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 192;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 152;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 449;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 123;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 533;
                elementData.generatedElementHash = HASH_ELEMENT_INT____INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 285;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 405;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 129;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____INT4;
                break;
            case HASH_ELEMENT_SAMPLER_STATE:
                elementData.typeID = 109;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER_STATE____GLES_SAMPLER_STATE;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 226;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____FX_SURFACE_COMMON;
                break;
            case HASH_ELEMENT_TEXTURE_PIPELINE:
                elementData.typeID = 341;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_PIPELINE____GLES_TEXTURE_PIPELINE;
                break;
            case HASH_ELEMENT_TEXTURE_UNIT:
                elementData.typeID = 478;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_UNIT;
                break;
            default:
                return false;
            }
            break;
        case 485:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_BIND:
                elementData.typeID = 301;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__BIND;
                break;
            case HASH_ELEMENT_COMPILER_OPTIONS:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_COMPILER_OPTIONS;
                break;
            case HASH_ELEMENT_COMPILER_TARGET:
                elementData.typeID = 141;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__COMPILER_TARGET;
                break;
            case HASH_ELEMENT_NAME:
                elementData.typeID = 519;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__NAME;
                break;
            default:
                return false;
            }
            break;
        case 486:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_BIND:
                elementData.typeID = 302;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__BIND;
                break;
            case HASH_ELEMENT_COMPILER_OPTIONS:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_COMPILER_OPTIONS;
                break;
            case HASH_ELEMENT_COMPILER_TARGET:
                elementData.typeID = 142;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__COMPILER_TARGET;
                break;
            case HASH_ELEMENT_NAME:
                elementData.typeID = 520;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__NAME;
                break;
            default:
                return false;
            }
            break;
        case 501:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BOX:
                elementData.typeID = 561;
                elementData.generatedElementHash = HASH_ELEMENT_BOX;
                break;
            case HASH_ELEMENT_CAPSULE:
                elementData.typeID = 39;
                elementData.generatedElementHash = HASH_ELEMENT_CAPSULE;
                break;
            case HASH_ELEMENT_CYLINDER:
                elementData.typeID = 399;
                elementData.generatedElementHash = HASH_ELEMENT_CYLINDER;
                break;
            case HASH_ELEMENT_DENSITY:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_DENSITY;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_HOLLOW:
                elementData.typeID = 471;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__SHAPE__HOLLOW;
                break;
            case HASH_ELEMENT_INSTANCE_GEOMETRY:
                elementData.typeID = 18;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_GEOMETRY;
                break;
            case HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL;
                break;
            case HASH_ELEMENT_MASS:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_MASS;
                break;
            case HASH_ELEMENT_PHYSICS_MATERIAL:
                elementData.typeID = 255;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_MATERIAL;
                break;
            case HASH_ELEMENT_PLANE:
                elementData.typeID = 305;
                elementData.generatedElementHash = HASH_ELEMENT_PLANE;
                break;
            case HASH_ELEMENT_ROTATE:
                elementData.typeID = 508;
                elementData.generatedElementHash = HASH_ELEMENT_ROTATE;
                break;
            case HASH_ELEMENT_SPHERE:
                elementData.typeID = 539;
                elementData.generatedElementHash = HASH_ELEMENT_SPHERE;
                break;
            case HASH_ELEMENT_TAPERED_CAPSULE:
                elementData.typeID = 334;
                elementData.generatedElementHash = HASH_ELEMENT_TAPERED_CAPSULE;
                break;
            case HASH_ELEMENT_TAPERED_CYLINDER:
                elementData.typeID = 134;
                elementData.generatedElementHash = HASH_ELEMENT_TAPERED_CYLINDER;
                break;
            case HASH_ELEMENT_TRANSLATE:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSLATE;
                break;
            default:
                return false;
            }
            break;
        case 502:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BOX:
                elementData.typeID = 561;
                elementData.generatedElementHash = HASH_ELEMENT_BOX;
                break;
            case HASH_ELEMENT_CAPSULE:
                elementData.typeID = 39;
                elementData.generatedElementHash = HASH_ELEMENT_CAPSULE;
                break;
            case HASH_ELEMENT_CYLINDER:
                elementData.typeID = 399;
                elementData.generatedElementHash = HASH_ELEMENT_CYLINDER;
                break;
            case HASH_ELEMENT_DENSITY:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_DENSITY;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_HOLLOW:
                elementData.typeID = 472;
                elementData.generatedElementHash = HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__SHAPE__HOLLOW;
                break;
            case HASH_ELEMENT_INSTANCE_GEOMETRY:
                elementData.typeID = 18;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_GEOMETRY;
                break;
            case HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL;
                break;
            case HASH_ELEMENT_MASS:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_MASS;
                break;
            case HASH_ELEMENT_PHYSICS_MATERIAL:
                elementData.typeID = 255;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_MATERIAL;
                break;
            case HASH_ELEMENT_PLANE:
                elementData.typeID = 305;
                elementData.generatedElementHash = HASH_ELEMENT_PLANE;
                break;
            case HASH_ELEMENT_ROTATE:
                elementData.typeID = 508;
                elementData.generatedElementHash = HASH_ELEMENT_ROTATE;
                break;
            case HASH_ELEMENT_SPHERE:
                elementData.typeID = 539;
                elementData.generatedElementHash = HASH_ELEMENT_SPHERE;
                break;
            case HASH_ELEMENT_TAPERED_CAPSULE:
                elementData.typeID = 334;
                elementData.generatedElementHash = HASH_ELEMENT_TAPERED_CAPSULE;
                break;
            case HASH_ELEMENT_TAPERED_CYLINDER:
                elementData.typeID = 134;
                elementData.generatedElementHash = HASH_ELEMENT_TAPERED_CYLINDER;
                break;
            case HASH_ELEMENT_TRANSLATE:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_TRANSLATE;
                break;
            default:
                return false;
            }
            break;
        case 410:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BIND_SHAPE_MATRIX:
                elementData.typeID = 123;
                elementData.generatedElementHash = HASH_ELEMENT_BIND_SHAPE_MATRIX;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_JOINTS:
                elementData.typeID = 249;
                elementData.generatedElementHash = HASH_ELEMENT_JOINTS;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 598;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE;
                break;
            case HASH_ELEMENT_VERTEX_WEIGHTS:
                elementData.typeID = 197;
                elementData.generatedElementHash = HASH_ELEMENT_VERTEX_WEIGHTS;
                break;
            default:
                return false;
            }
            break;
        case 598:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_IDREF_ARRAY:
                elementData.typeID = 429;
                elementData.generatedElementHash = HASH_ELEMENT_IDREF_ARRAY;
                break;
            case HASH_ELEMENT_NAME_ARRAY:
                elementData.typeID = 450;
                elementData.generatedElementHash = HASH_ELEMENT_NAME_ARRAY;
                break;
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_BOOL_ARRAY:
                elementData.typeID = 458;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL_ARRAY;
                break;
            case HASH_ELEMENT_FLOAT_ARRAY:
                elementData.typeID = 108;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT_ARRAY;
                break;
            case HASH_ELEMENT_INT_ARRAY:
                elementData.typeID = 538;
                elementData.generatedElementHash = HASH_ELEMENT_INT_ARRAY;
                break;
            case HASH_ELEMENT_TECHNIQUE:
                elementData.typeID = 525;
                elementData.generatedElementHash = HASH_ELEMENT_TECHNIQUE;
                break;
            case HASH_ELEMENT_TECHNIQUE_COMMON:
                elementData.typeID = 577;
                elementData.generatedElementHash = HASH_ELEMENT_ANIMATION__SOURCE__TECHNIQUE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 539:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_RADIUS:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_RADIUS____FLOAT;
                break;
            default:
                return false;
            }
            break;
        case 47:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_CONTROL_VERTICES:
                elementData.typeID = 180;
                elementData.generatedElementHash = HASH_ELEMENT_CONTROL_VERTICES;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 598;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE;
                break;
            default:
                return false;
            }
            break;
        case 315:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_COLOR:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_COLOR____TARGETABLEFLOAT3;
                break;
            case HASH_ELEMENT_CONSTANT_ATTENUATION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_CONSTANT_ATTENUATION;
                break;
            case HASH_ELEMENT_FALLOFF_ANGLE:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_FALLOFF_ANGLE;
                break;
            case HASH_ELEMENT_FALLOFF_EXPONENT:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_FALLOFF_EXPONENT;
                break;
            case HASH_ELEMENT_LINEAR_ATTENUATION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_LINEAR_ATTENUATION;
                break;
            case HASH_ELEMENT_QUADRATIC_ATTENUATION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_QUADRATIC_ATTENUATION;
                break;
            default:
                return false;
            }
            break;
        case 622:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANGULAR:
                elementData.typeID = 387;
                elementData.generatedElementHash = HASH_ELEMENT_ANGULAR;
                break;
            case HASH_ELEMENT_LINEAR:
                elementData.typeID = 333;
                elementData.generatedElementHash = HASH_ELEMENT_SPRING__LINEAR;
                break;
            default:
                return false;
            }
            break;
        case 145:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BACK:
                elementData.typeID = 384;
                elementData.generatedElementHash = HASH_ELEMENT_BACK;
                break;
            case HASH_ELEMENT_FRONT:
                elementData.typeID = 258;
                elementData.generatedElementHash = HASH_ELEMENT_FRONT;
                break;
            case HASH_ELEMENT_MASK:
                elementData.typeID = 543;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_FUNC_SEPARATE__MASK;
                break;
            case HASH_ELEMENT_REF:
                elementData.typeID = 71;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_FUNC_SEPARATE__REF;
                break;
            default:
                return false;
            }
            break;
        case 562:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FUNC:
                elementData.typeID = 289;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__FUNC;
                break;
            case HASH_ELEMENT_MASK:
                elementData.typeID = 544;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__MASK;
                break;
            case HASH_ELEMENT_REF:
                elementData.typeID = 72;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__REF;
                break;
            default:
                return false;
            }
            break;
        case 563:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FUNC:
                elementData.typeID = 290;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__FUNC;
                break;
            case HASH_ELEMENT_MASK:
                elementData.typeID = 545;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__MASK;
                break;
            case HASH_ELEMENT_REF:
                elementData.typeID = 73;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__REF;
                break;
            default:
                return false;
            }
            break;
        case 496:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FACE:
                elementData.typeID = 369;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_MASK_SEPARATE__FACE;
                break;
            case HASH_ELEMENT_MASK:
                elementData.typeID = 546;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_MASK_SEPARATE__MASK;
                break;
            default:
                return false;
            }
            break;
        case 440:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FACE:
                elementData.typeID = 370;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_OP_SEPARATE__FACE;
                break;
            case HASH_ELEMENT_FAIL:
                elementData.typeID = 15;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_OP_SEPARATE__FAIL;
                break;
            case HASH_ELEMENT_ZFAIL:
                elementData.typeID = 11;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_OP_SEPARATE__ZFAIL;
                break;
            case HASH_ELEMENT_ZPASS:
                elementData.typeID = 175;
                elementData.generatedElementHash = HASH_ELEMENT_STENCIL_OP_SEPARATE__ZPASS;
                break;
            default:
                return false;
            }
            break;
        case 23:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FAIL:
                elementData.typeID = 16;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__FAIL;
                break;
            case HASH_ELEMENT_ZFAIL:
                elementData.typeID = 12;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__ZFAIL;
                break;
            case HASH_ELEMENT_ZPASS:
                elementData.typeID = 176;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__ZPASS;
                break;
            default:
                return false;
            }
            break;
        case 24:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FAIL:
                elementData.typeID = 17;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__FAIL;
                break;
            case HASH_ELEMENT_ZFAIL:
                elementData.typeID = 13;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__ZFAIL;
                break;
            case HASH_ELEMENT_ZPASS:
                elementData.typeID = 177;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__ZPASS;
                break;
            default:
                return false;
            }
            break;
        case 523:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_MAX:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_MAX;
                break;
            case HASH_ELEMENT_MIN:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_MIN;
                break;
            default:
                return false;
            }
            break;
        case 334:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_HEIGHT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_HEIGHT;
                break;
            case HASH_ELEMENT_RADIUS1:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_RADIUS1;
                break;
            case HASH_ELEMENT_RADIUS2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_RADIUS2;
                break;
            default:
                return false;
            }
            break;
        case 134:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_HEIGHT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_HEIGHT;
                break;
            case HASH_ELEMENT_RADIUS1:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_RADIUS1;
                break;
            case HASH_ELEMENT_RADIUS2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_RADIUS2;
                break;
            default:
                return false;
            }
            break;
        case 79:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 34;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCAL;
                break;
            default:
                return false;
            }
            break;
        case 569:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_INSTANCE_MATERIAL:
                elementData.typeID = 209;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_MATERIAL;
                break;
            default:
                return false;
            }
            break;
        case 570:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANGULAR_VELOCITY:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_ANGULAR_VELOCITY;
                break;
            case HASH_ELEMENT_DYNAMIC:
                elementData.typeID = 357;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__DYNAMIC;
                break;
            case HASH_ELEMENT_INERTIA:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_INERTIA;
                break;
            case HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL;
                break;
            case HASH_ELEMENT_MASS:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_MASS;
                break;
            case HASH_ELEMENT_MASS_FRAME:
                elementData.typeID = 116;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__MASS_FRAME;
                break;
            case HASH_ELEMENT_PHYSICS_MATERIAL:
                elementData.typeID = 255;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_MATERIAL;
                break;
            case HASH_ELEMENT_SHAPE:
                elementData.typeID = 501;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__SHAPE;
                break;
            case HASH_ELEMENT_VELOCITY:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_VELOCITY;
                break;
            default:
                return false;
            }
            break;
        case 571:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_AMBIENT:
                elementData.typeID = 38;
                elementData.generatedElementHash = HASH_ELEMENT_LIGHT__TECHNIQUE_COMMON__AMBIENT;
                break;
            case HASH_ELEMENT_DIRECTIONAL:
                elementData.typeID = 306;
                elementData.generatedElementHash = HASH_ELEMENT_DIRECTIONAL;
                break;
            case HASH_ELEMENT_POINT:
                elementData.typeID = 57;
                elementData.generatedElementHash = HASH_ELEMENT_POINT;
                break;
            case HASH_ELEMENT_SPOT:
                elementData.typeID = 315;
                elementData.generatedElementHash = HASH_ELEMENT_SPOT;
                break;
            default:
                return false;
            }
            break;
        case 572:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ORTHOGRAPHIC:
                elementData.typeID = 349;
                elementData.generatedElementHash = HASH_ELEMENT_ORTHOGRAPHIC;
                break;
            case HASH_ELEMENT_PERSPECTIVE:
                elementData.typeID = 186;
                elementData.generatedElementHash = HASH_ELEMENT_PERSPECTIVE;
                break;
            default:
                return false;
            }
            break;
        case 573:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_DYNAMIC_FRICTION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_DYNAMIC_FRICTION;
                break;
            case HASH_ELEMENT_RESTITUTION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_RESTITUTION;
                break;
            case HASH_ELEMENT_STATIC_FRICTION:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_STATIC_FRICTION;
                break;
            default:
                return false;
            }
            break;
        case 574:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_GRAVITY:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_GRAVITY;
                break;
            case HASH_ELEMENT_TIME_STEP:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_TIME_STEP;
                break;
            default:
                return false;
            }
            break;
        case 575:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_DYNAMIC:
                elementData.typeID = 358;
                elementData.generatedElementHash = HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__DYNAMIC;
                break;
            case HASH_ELEMENT_INERTIA:
                elementData.typeID = 25;
                elementData.generatedElementHash = HASH_ELEMENT_INERTIA;
                break;
            case HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL:
                elementData.typeID = 185;
                elementData.generatedElementHash = HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL;
                break;
            case HASH_ELEMENT_MASS:
                elementData.typeID = 10;
                elementData.generatedElementHash = HASH_ELEMENT_MASS;
                break;
            case HASH_ELEMENT_MASS_FRAME:
                elementData.typeID = 117;
                elementData.generatedElementHash = HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__MASS_FRAME;
                break;
            case HASH_ELEMENT_PHYSICS_MATERIAL:
                elementData.typeID = 255;
                elementData.generatedElementHash = HASH_ELEMENT_PHYSICS_MATERIAL;
                break;
            case HASH_ELEMENT_SHAPE:
                elementData.typeID = 502;
                elementData.generatedElementHash = HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__SHAPE;
                break;
            default:
                return false;
            }
            break;
        case 576:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ENABLED:
                elementData.typeID = 320;
                elementData.generatedElementHash = HASH_ELEMENT_ENABLED;
                break;
            case HASH_ELEMENT_INTERPENETRATE:
                elementData.typeID = 356;
                elementData.generatedElementHash = HASH_ELEMENT_INTERPENETRATE;
                break;
            case HASH_ELEMENT_LIMITS:
                elementData.typeID = 382;
                elementData.generatedElementHash = HASH_ELEMENT_LIMITS;
                break;
            case HASH_ELEMENT_SPRING:
                elementData.typeID = 622;
                elementData.generatedElementHash = HASH_ELEMENT_SPRING;
                break;
            default:
                return false;
            }
            break;
        case 577:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ACCESSOR:
                elementData.typeID = 507;
                elementData.generatedElementHash = HASH_ELEMENT_ACCESSOR;
                break;
            default:
                return false;
            }
            break;
        case 526:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_CODE:
                elementData.typeID = 253;
                elementData.generatedElementHash = HASH_ELEMENT_CODE;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_INCLUDE:
                elementData.typeID = 564;
                elementData.generatedElementHash = HASH_ELEMENT_INCLUDE;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 553;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____CG_NEWPARAM;
                break;
            case HASH_ELEMENT_PASS:
                elementData.typeID = 362;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS;
                break;
            case HASH_ELEMENT_SETPARAM:
                elementData.typeID = 625;
                elementData.generatedElementHash = HASH_ELEMENT_SETPARAM____CG_SETPARAM;
                break;
            default:
                return false;
            }
            break;
        case 527:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_BLINN:
                elementData.typeID = 611;
                elementData.generatedElementHash = HASH_ELEMENT_BLINN;
                break;
            case HASH_ELEMENT_CONSTANT:
                elementData.typeID = 163;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_COMMON__TECHNIQUE__CONSTANT;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_LAMBERT:
                elementData.typeID = 277;
                elementData.generatedElementHash = HASH_ELEMENT_LAMBERT;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 554;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____COMMON_NEWPARAM_TYPE;
                break;
            case HASH_ELEMENT_PHONG:
                elementData.typeID = 608;
                elementData.generatedElementHash = HASH_ELEMENT_PHONG;
                break;
            default:
                return false;
            }
            break;
        case 528:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 556;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____GLES_NEWPARAM;
                break;
            case HASH_ELEMENT_PASS:
                elementData.typeID = 363;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS;
                break;
            case HASH_ELEMENT_SETPARAM:
                elementData.typeID = 624;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__SETPARAM;
                break;
            default:
                return false;
            }
            break;
        case 529:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_CODE:
                elementData.typeID = 253;
                elementData.generatedElementHash = HASH_ELEMENT_CODE;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_IMAGE:
                elementData.typeID = 224;
                elementData.generatedElementHash = HASH_ELEMENT_IMAGE;
                break;
            case HASH_ELEMENT_INCLUDE:
                elementData.typeID = 564;
                elementData.generatedElementHash = HASH_ELEMENT_INCLUDE;
                break;
            case HASH_ELEMENT_NEWPARAM:
                elementData.typeID = 557;
                elementData.generatedElementHash = HASH_ELEMENT_NEWPARAM____GLSL_NEWPARAM;
                break;
            case HASH_ELEMENT_PASS:
                elementData.typeID = 364;
                elementData.generatedElementHash = HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS;
                break;
            case HASH_ELEMENT_SETPARAM:
                elementData.typeID = 627;
                elementData.generatedElementHash = HASH_ELEMENT_SETPARAM____GLSL_SETPARAM;
                break;
            default:
                return false;
            }
            break;
        case 331:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_PARAM____NCNAME;
                break;
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 361;
                elementData.generatedElementHash = HASH_ELEMENT_VALUE____GL_SAMPLER1D;
                break;
            default:
                return false;
            }
            break;
        case 149:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_PARAM____NCNAME;
                break;
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 51;
                elementData.generatedElementHash = HASH_ELEMENT_VALUE____GL_SAMPLER2D;
                break;
            default:
                return false;
            }
            break;
        case 620:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_PARAM____NCNAME;
                break;
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 380;
                elementData.generatedElementHash = HASH_ELEMENT_VALUE____GL_SAMPLER3D;
                break;
            default:
                return false;
            }
            break;
        case 589:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_PARAM____NCNAME;
                break;
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 381;
                elementData.generatedElementHash = HASH_ELEMENT_VALUE____GL_SAMPLERCUBE;
                break;
            default:
                return false;
            }
            break;
        case 516:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_PARAM____NCNAME;
                break;
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 269;
                elementData.generatedElementHash = HASH_ELEMENT_VALUE____GL_SAMPLERDEPTH;
                break;
            default:
                return false;
            }
            break;
        case 240:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_PARAM____NCNAME;
                break;
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 104;
                elementData.generatedElementHash = HASH_ELEMENT_VALUE____GL_SAMPLERRECT;
                break;
            default:
                return false;
            }
            break;
        case 340:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_VALUE:
                elementData.typeID = 341;
                elementData.generatedElementHash = HASH_ELEMENT_VALUE____GLES_TEXTURE_PIPELINE;
                break;
            default:
                return false;
            }
            break;
        case 409:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 483:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 35;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCALOFFSET;
                break;
            case HASH_ELEMENT_P:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_P;
                break;
            default:
                return false;
            }
            break;
        case 612:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 35;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCALOFFSET;
                break;
            case HASH_ELEMENT_P:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_P;
                break;
            default:
                return false;
            }
            break;
        case 312:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 35;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCALOFFSET;
                break;
            case HASH_ELEMENT_P:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_P;
                break;
            default:
                return false;
            }
            break;
        case 197:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 35;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCALOFFSET;
                break;
            case HASH_ELEMENT_V:
                elementData.typeID = 187;
                elementData.generatedElementHash = HASH_ELEMENT_V;
                break;
            case HASH_ELEMENT_VCOUNT:
                elementData.typeID = 119;
                elementData.generatedElementHash = HASH_ELEMENT_VCOUNT;
                break;
            default:
                return false;
            }
            break;
        case 433:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_INPUT:
                elementData.typeID = 34;
                elementData.generatedElementHash = HASH_ELEMENT_INPUT____INPUTLOCAL;
                break;
            default:
                return false;
            }
            break;
        case 345:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ASSET:
                elementData.typeID = 484;
                elementData.generatedElementHash = HASH_ELEMENT_ASSET;
                break;
            case HASH_ELEMENT_EVALUATE_SCENE:
                elementData.typeID = 294;
                elementData.generatedElementHash = HASH_ELEMENT_EVALUATE_SCENE;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_NODE:
                elementData.typeID = 22;
                elementData.generatedElementHash = HASH_ELEMENT_NODE;
                break;
            default:
                return false;
            }
            break;
        case 185:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            default:
                return false;
            }
            break;
        case 350:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 350;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____CG_NEWARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 205;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____CG_BOOL;
                break;
            case HASH_ELEMENT_BOOL1:
                elementData.typeID = 621;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1;
                break;
            case HASH_ELEMENT_BOOL1X1:
                elementData.typeID = 256;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X1;
                break;
            case HASH_ELEMENT_BOOL1X2:
                elementData.typeID = 228;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X2;
                break;
            case HASH_ELEMENT_BOOL1X3:
                elementData.typeID = 406;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X3;
                break;
            case HASH_ELEMENT_BOOL1X4:
                elementData.typeID = 91;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X4;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 317;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____CG_BOOL2;
                break;
            case HASH_ELEMENT_BOOL2X1:
                elementData.typeID = 610;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X1;
                break;
            case HASH_ELEMENT_BOOL2X2:
                elementData.typeID = 270;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X2;
                break;
            case HASH_ELEMENT_BOOL2X3:
                elementData.typeID = 592;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X3;
                break;
            case HASH_ELEMENT_BOOL2X4:
                elementData.typeID = 307;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X4;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 614;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____CG_BOOL3;
                break;
            case HASH_ELEMENT_BOOL3X1:
                elementData.typeID = 32;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X1;
                break;
            case HASH_ELEMENT_BOOL3X2:
                elementData.typeID = 257;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X2;
                break;
            case HASH_ELEMENT_BOOL3X3:
                elementData.typeID = 597;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X3;
                break;
            case HASH_ELEMENT_BOOL3X4:
                elementData.typeID = 385;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X4;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 75;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____CG_BOOL4;
                break;
            case HASH_ELEMENT_BOOL4X1:
                elementData.typeID = 1;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X1;
                break;
            case HASH_ELEMENT_BOOL4X2:
                elementData.typeID = 390;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X2;
                break;
            case HASH_ELEMENT_BOOL4X3:
                elementData.typeID = 132;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X3;
                break;
            case HASH_ELEMENT_BOOL4X4:
                elementData.typeID = 346;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X4;
                break;
            case HASH_ELEMENT_CONNECT_PARAM:
                elementData.typeID = 455;
                elementData.generatedElementHash = HASH_ELEMENT_CONNECT_PARAM;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FIXED:
                elementData.typeID = 590;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED;
                break;
            case HASH_ELEMENT_FIXED1:
                elementData.typeID = 587;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1;
                break;
            case HASH_ELEMENT_FIXED1X1:
                elementData.typeID = 514;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X1;
                break;
            case HASH_ELEMENT_FIXED1X2:
                elementData.typeID = 211;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X2;
                break;
            case HASH_ELEMENT_FIXED1X3:
                elementData.typeID = 107;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X3;
                break;
            case HASH_ELEMENT_FIXED1X4:
                elementData.typeID = 428;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X4;
                break;
            case HASH_ELEMENT_FIXED2:
                elementData.typeID = 282;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2;
                break;
            case HASH_ELEMENT_FIXED2X1:
                elementData.typeID = 237;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X1;
                break;
            case HASH_ELEMENT_FIXED2X2:
                elementData.typeID = 499;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X2;
                break;
            case HASH_ELEMENT_FIXED2X3:
                elementData.typeID = 248;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X3;
                break;
            case HASH_ELEMENT_FIXED2X4:
                elementData.typeID = 541;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X4;
                break;
            case HASH_ELEMENT_FIXED3:
                elementData.typeID = 616;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3;
                break;
            case HASH_ELEMENT_FIXED3X1:
                elementData.typeID = 136;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X1;
                break;
            case HASH_ELEMENT_FIXED3X2:
                elementData.typeID = 522;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X2;
                break;
            case HASH_ELEMENT_FIXED3X3:
                elementData.typeID = 424;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X3;
                break;
            case HASH_ELEMENT_FIXED3X4:
                elementData.typeID = 493;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X4;
                break;
            case HASH_ELEMENT_FIXED4:
                elementData.typeID = 322;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4;
                break;
            case HASH_ELEMENT_FIXED4X1:
                elementData.typeID = 48;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X1;
                break;
            case HASH_ELEMENT_FIXED4X2:
                elementData.typeID = 374;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X2;
                break;
            case HASH_ELEMENT_FIXED4X3:
                elementData.typeID = 588;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X3;
                break;
            case HASH_ELEMENT_FIXED4X4:
                elementData.typeID = 252;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X4;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 401;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____CG_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1:
                elementData.typeID = 506;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 114;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____CG_FLOAT1X1;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 394;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____CG_FLOAT1X2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 111;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____CG_FLOAT1X3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 291;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____CG_FLOAT1X4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 238;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____CG_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 629;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____CG_FLOAT2X1;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 323;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____CG_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 438;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____CG_FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 53;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____CG_FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 88;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____CG_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 118;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____CG_FLOAT3X1;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 201;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____CG_FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 503;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____CG_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 191;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____CG_FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 246;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____CG_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 20;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____CG_FLOAT4X1;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 151;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____CG_FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 448;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____CG_FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 122;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____CG_FLOAT4X4;
                break;
            case HASH_ELEMENT_HALF:
                elementData.typeID = 437;
                elementData.generatedElementHash = HASH_ELEMENT_HALF;
                break;
            case HASH_ELEMENT_HALF1:
                elementData.typeID = 416;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1;
                break;
            case HASH_ELEMENT_HALF1X1:
                elementData.typeID = 229;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X1;
                break;
            case HASH_ELEMENT_HALF1X2:
                elementData.typeID = 565;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X2;
                break;
            case HASH_ELEMENT_HALF1X3:
                elementData.typeID = 99;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X3;
                break;
            case HASH_ELEMENT_HALF1X4:
                elementData.typeID = 397;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X4;
                break;
            case HASH_ELEMENT_HALF2:
                elementData.typeID = 60;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2;
                break;
            case HASH_ELEMENT_HALF2X1:
                elementData.typeID = 80;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X1;
                break;
            case HASH_ELEMENT_HALF2X2:
                elementData.typeID = 196;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X2;
                break;
            case HASH_ELEMENT_HALF2X3:
                elementData.typeID = 475;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X3;
                break;
            case HASH_ELEMENT_HALF2X4:
                elementData.typeID = 216;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X4;
                break;
            case HASH_ELEMENT_HALF3:
                elementData.typeID = 244;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3;
                break;
            case HASH_ELEMENT_HALF3X1:
                elementData.typeID = 547;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X1;
                break;
            case HASH_ELEMENT_HALF3X2:
                elementData.typeID = 245;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X2;
                break;
            case HASH_ELEMENT_HALF3X3:
                elementData.typeID = 476;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X3;
                break;
            case HASH_ELEMENT_HALF3X4:
                elementData.typeID = 178;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X4;
                break;
            case HASH_ELEMENT_HALF4:
                elementData.typeID = 266;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4;
                break;
            case HASH_ELEMENT_HALF4X1:
                elementData.typeID = 140;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X1;
                break;
            case HASH_ELEMENT_HALF4X2:
                elementData.typeID = 461;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X2;
                break;
            case HASH_ELEMENT_HALF4X3:
                elementData.typeID = 147;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X3;
                break;
            case HASH_ELEMENT_HALF4X4:
                elementData.typeID = 413;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 531;
                elementData.generatedElementHash = HASH_ELEMENT_INT____CG_INT;
                break;
            case HASH_ELEMENT_INT1:
                elementData.typeID = 603;
                elementData.generatedElementHash = HASH_ELEMENT_INT1;
                break;
            case HASH_ELEMENT_INT1X1:
                elementData.typeID = 607;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X1;
                break;
            case HASH_ELEMENT_INT1X2:
                elementData.typeID = 304;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X2;
                break;
            case HASH_ELEMENT_INT1X3:
                elementData.typeID = 470;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X3;
                break;
            case HASH_ELEMENT_INT1X4:
                elementData.typeID = 190;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X4;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 283;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____CG_INT2;
                break;
            case HASH_ELEMENT_INT2X1:
                elementData.typeID = 193;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X1;
                break;
            case HASH_ELEMENT_INT2X2:
                elementData.typeID = 64;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X2;
                break;
            case HASH_ELEMENT_INT2X3:
                elementData.typeID = 375;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X3;
                break;
            case HASH_ELEMENT_INT2X4:
                elementData.typeID = 30;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X4;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 509;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____CG_INT3;
                break;
            case HASH_ELEMENT_INT3X1:
                elementData.typeID = 426;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X1;
                break;
            case HASH_ELEMENT_INT3X2:
                elementData.typeID = 582;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X2;
                break;
            case HASH_ELEMENT_INT3X3:
                elementData.typeID = 383;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X3;
                break;
            case HASH_ELEMENT_INT3X4:
                elementData.typeID = 594;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X4;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 127;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____CG_INT4;
                break;
            case HASH_ELEMENT_INT4X1:
                elementData.typeID = 207;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X1;
                break;
            case HASH_ELEMENT_INT4X2:
                elementData.typeID = 159;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X2;
                break;
            case HASH_ELEMENT_INT4X3:
                elementData.typeID = 314;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X3;
                break;
            case HASH_ELEMENT_INT4X4:
                elementData.typeID = 511;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 359;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____CG_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 49;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____CG_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 595;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____CG_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 497;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 267;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 102;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT;
                break;
            case HASH_ELEMENT_STRING:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_STRING;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 225;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____CG_SURFACE_TYPE;
                break;
            case HASH_ELEMENT_USERTYPE:
                elementData.typeID = 566;
                elementData.generatedElementHash = HASH_ELEMENT_USERTYPE;
                break;
            default:
                return false;
            }
            break;
        case 553:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 350;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____CG_NEWARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 205;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____CG_BOOL;
                break;
            case HASH_ELEMENT_BOOL1:
                elementData.typeID = 621;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1;
                break;
            case HASH_ELEMENT_BOOL1X1:
                elementData.typeID = 256;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X1;
                break;
            case HASH_ELEMENT_BOOL1X2:
                elementData.typeID = 228;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X2;
                break;
            case HASH_ELEMENT_BOOL1X3:
                elementData.typeID = 406;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X3;
                break;
            case HASH_ELEMENT_BOOL1X4:
                elementData.typeID = 91;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X4;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 317;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____CG_BOOL2;
                break;
            case HASH_ELEMENT_BOOL2X1:
                elementData.typeID = 610;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X1;
                break;
            case HASH_ELEMENT_BOOL2X2:
                elementData.typeID = 270;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X2;
                break;
            case HASH_ELEMENT_BOOL2X3:
                elementData.typeID = 592;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X3;
                break;
            case HASH_ELEMENT_BOOL2X4:
                elementData.typeID = 307;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X4;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 614;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____CG_BOOL3;
                break;
            case HASH_ELEMENT_BOOL3X1:
                elementData.typeID = 32;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X1;
                break;
            case HASH_ELEMENT_BOOL3X2:
                elementData.typeID = 257;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X2;
                break;
            case HASH_ELEMENT_BOOL3X3:
                elementData.typeID = 597;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X3;
                break;
            case HASH_ELEMENT_BOOL3X4:
                elementData.typeID = 385;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X4;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 75;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____CG_BOOL4;
                break;
            case HASH_ELEMENT_BOOL4X1:
                elementData.typeID = 1;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X1;
                break;
            case HASH_ELEMENT_BOOL4X2:
                elementData.typeID = 390;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X2;
                break;
            case HASH_ELEMENT_BOOL4X3:
                elementData.typeID = 132;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X3;
                break;
            case HASH_ELEMENT_BOOL4X4:
                elementData.typeID = 346;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FIXED:
                elementData.typeID = 590;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED;
                break;
            case HASH_ELEMENT_FIXED1:
                elementData.typeID = 587;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1;
                break;
            case HASH_ELEMENT_FIXED1X1:
                elementData.typeID = 514;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X1;
                break;
            case HASH_ELEMENT_FIXED1X2:
                elementData.typeID = 211;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X2;
                break;
            case HASH_ELEMENT_FIXED1X3:
                elementData.typeID = 107;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X3;
                break;
            case HASH_ELEMENT_FIXED1X4:
                elementData.typeID = 428;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X4;
                break;
            case HASH_ELEMENT_FIXED2:
                elementData.typeID = 282;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2;
                break;
            case HASH_ELEMENT_FIXED2X1:
                elementData.typeID = 237;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X1;
                break;
            case HASH_ELEMENT_FIXED2X2:
                elementData.typeID = 499;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X2;
                break;
            case HASH_ELEMENT_FIXED2X3:
                elementData.typeID = 248;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X3;
                break;
            case HASH_ELEMENT_FIXED2X4:
                elementData.typeID = 541;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X4;
                break;
            case HASH_ELEMENT_FIXED3:
                elementData.typeID = 616;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3;
                break;
            case HASH_ELEMENT_FIXED3X1:
                elementData.typeID = 136;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X1;
                break;
            case HASH_ELEMENT_FIXED3X2:
                elementData.typeID = 522;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X2;
                break;
            case HASH_ELEMENT_FIXED3X3:
                elementData.typeID = 424;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X3;
                break;
            case HASH_ELEMENT_FIXED3X4:
                elementData.typeID = 493;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X4;
                break;
            case HASH_ELEMENT_FIXED4:
                elementData.typeID = 322;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4;
                break;
            case HASH_ELEMENT_FIXED4X1:
                elementData.typeID = 48;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X1;
                break;
            case HASH_ELEMENT_FIXED4X2:
                elementData.typeID = 374;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X2;
                break;
            case HASH_ELEMENT_FIXED4X3:
                elementData.typeID = 588;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X3;
                break;
            case HASH_ELEMENT_FIXED4X4:
                elementData.typeID = 252;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X4;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 401;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____CG_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1:
                elementData.typeID = 506;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 114;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____CG_FLOAT1X1;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 394;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____CG_FLOAT1X2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 111;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____CG_FLOAT1X3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 291;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____CG_FLOAT1X4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 238;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____CG_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 629;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____CG_FLOAT2X1;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 323;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____CG_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 438;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____CG_FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 53;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____CG_FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 88;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____CG_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 118;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____CG_FLOAT3X1;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 201;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____CG_FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 503;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____CG_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 191;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____CG_FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 246;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____CG_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 20;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____CG_FLOAT4X1;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 151;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____CG_FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 448;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____CG_FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 122;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____CG_FLOAT4X4;
                break;
            case HASH_ELEMENT_HALF:
                elementData.typeID = 437;
                elementData.generatedElementHash = HASH_ELEMENT_HALF;
                break;
            case HASH_ELEMENT_HALF1:
                elementData.typeID = 416;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1;
                break;
            case HASH_ELEMENT_HALF1X1:
                elementData.typeID = 229;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X1;
                break;
            case HASH_ELEMENT_HALF1X2:
                elementData.typeID = 565;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X2;
                break;
            case HASH_ELEMENT_HALF1X3:
                elementData.typeID = 99;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X3;
                break;
            case HASH_ELEMENT_HALF1X4:
                elementData.typeID = 397;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X4;
                break;
            case HASH_ELEMENT_HALF2:
                elementData.typeID = 60;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2;
                break;
            case HASH_ELEMENT_HALF2X1:
                elementData.typeID = 80;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X1;
                break;
            case HASH_ELEMENT_HALF2X2:
                elementData.typeID = 196;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X2;
                break;
            case HASH_ELEMENT_HALF2X3:
                elementData.typeID = 475;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X3;
                break;
            case HASH_ELEMENT_HALF2X4:
                elementData.typeID = 216;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X4;
                break;
            case HASH_ELEMENT_HALF3:
                elementData.typeID = 244;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3;
                break;
            case HASH_ELEMENT_HALF3X1:
                elementData.typeID = 547;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X1;
                break;
            case HASH_ELEMENT_HALF3X2:
                elementData.typeID = 245;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X2;
                break;
            case HASH_ELEMENT_HALF3X3:
                elementData.typeID = 476;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X3;
                break;
            case HASH_ELEMENT_HALF3X4:
                elementData.typeID = 178;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X4;
                break;
            case HASH_ELEMENT_HALF4:
                elementData.typeID = 266;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4;
                break;
            case HASH_ELEMENT_HALF4X1:
                elementData.typeID = 140;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X1;
                break;
            case HASH_ELEMENT_HALF4X2:
                elementData.typeID = 461;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X2;
                break;
            case HASH_ELEMENT_HALF4X3:
                elementData.typeID = 147;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X3;
                break;
            case HASH_ELEMENT_HALF4X4:
                elementData.typeID = 413;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 531;
                elementData.generatedElementHash = HASH_ELEMENT_INT____CG_INT;
                break;
            case HASH_ELEMENT_INT1:
                elementData.typeID = 603;
                elementData.generatedElementHash = HASH_ELEMENT_INT1;
                break;
            case HASH_ELEMENT_INT1X1:
                elementData.typeID = 607;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X1;
                break;
            case HASH_ELEMENT_INT1X2:
                elementData.typeID = 304;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X2;
                break;
            case HASH_ELEMENT_INT1X3:
                elementData.typeID = 470;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X3;
                break;
            case HASH_ELEMENT_INT1X4:
                elementData.typeID = 190;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X4;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 283;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____CG_INT2;
                break;
            case HASH_ELEMENT_INT2X1:
                elementData.typeID = 193;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X1;
                break;
            case HASH_ELEMENT_INT2X2:
                elementData.typeID = 64;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X2;
                break;
            case HASH_ELEMENT_INT2X3:
                elementData.typeID = 375;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X3;
                break;
            case HASH_ELEMENT_INT2X4:
                elementData.typeID = 30;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X4;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 509;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____CG_INT3;
                break;
            case HASH_ELEMENT_INT3X1:
                elementData.typeID = 426;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X1;
                break;
            case HASH_ELEMENT_INT3X2:
                elementData.typeID = 582;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X2;
                break;
            case HASH_ELEMENT_INT3X3:
                elementData.typeID = 383;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X3;
                break;
            case HASH_ELEMENT_INT3X4:
                elementData.typeID = 594;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X4;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 127;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____CG_INT4;
                break;
            case HASH_ELEMENT_INT4X1:
                elementData.typeID = 207;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X1;
                break;
            case HASH_ELEMENT_INT4X2:
                elementData.typeID = 159;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X2;
                break;
            case HASH_ELEMENT_INT4X3:
                elementData.typeID = 314;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X3;
                break;
            case HASH_ELEMENT_INT4X4:
                elementData.typeID = 511;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X4;
                break;
            case HASH_ELEMENT_MODIFIER:
                elementData.typeID = 560;
                elementData.generatedElementHash = HASH_ELEMENT_MODIFIER;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 359;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____CG_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 49;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____CG_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 595;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____CG_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 497;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 267;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 102;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT;
                break;
            case HASH_ELEMENT_SEMANTIC:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SEMANTIC;
                break;
            case HASH_ELEMENT_STRING:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_STRING;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 225;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____CG_SURFACE_TYPE;
                break;
            case HASH_ELEMENT_USERTYPE:
                elementData.typeID = 566;
                elementData.generatedElementHash = HASH_ELEMENT_USERTYPE;
                break;
            default:
                return false;
            }
            break;
        case 359:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 49:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 595:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_P:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_P;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 497:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_P:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_P;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 267:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 102:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 351:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 351;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____CG_SETARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 205;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____CG_BOOL;
                break;
            case HASH_ELEMENT_BOOL1:
                elementData.typeID = 621;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1;
                break;
            case HASH_ELEMENT_BOOL1X1:
                elementData.typeID = 256;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X1;
                break;
            case HASH_ELEMENT_BOOL1X2:
                elementData.typeID = 228;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X2;
                break;
            case HASH_ELEMENT_BOOL1X3:
                elementData.typeID = 406;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X3;
                break;
            case HASH_ELEMENT_BOOL1X4:
                elementData.typeID = 91;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X4;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 317;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____CG_BOOL2;
                break;
            case HASH_ELEMENT_BOOL2X1:
                elementData.typeID = 610;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X1;
                break;
            case HASH_ELEMENT_BOOL2X2:
                elementData.typeID = 270;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X2;
                break;
            case HASH_ELEMENT_BOOL2X3:
                elementData.typeID = 592;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X3;
                break;
            case HASH_ELEMENT_BOOL2X4:
                elementData.typeID = 307;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X4;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 614;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____CG_BOOL3;
                break;
            case HASH_ELEMENT_BOOL3X1:
                elementData.typeID = 32;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X1;
                break;
            case HASH_ELEMENT_BOOL3X2:
                elementData.typeID = 257;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X2;
                break;
            case HASH_ELEMENT_BOOL3X3:
                elementData.typeID = 597;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X3;
                break;
            case HASH_ELEMENT_BOOL3X4:
                elementData.typeID = 385;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X4;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 75;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____CG_BOOL4;
                break;
            case HASH_ELEMENT_BOOL4X1:
                elementData.typeID = 1;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X1;
                break;
            case HASH_ELEMENT_BOOL4X2:
                elementData.typeID = 390;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X2;
                break;
            case HASH_ELEMENT_BOOL4X3:
                elementData.typeID = 132;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X3;
                break;
            case HASH_ELEMENT_BOOL4X4:
                elementData.typeID = 346;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FIXED:
                elementData.typeID = 590;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED;
                break;
            case HASH_ELEMENT_FIXED1:
                elementData.typeID = 587;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1;
                break;
            case HASH_ELEMENT_FIXED1X1:
                elementData.typeID = 514;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X1;
                break;
            case HASH_ELEMENT_FIXED1X2:
                elementData.typeID = 211;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X2;
                break;
            case HASH_ELEMENT_FIXED1X3:
                elementData.typeID = 107;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X3;
                break;
            case HASH_ELEMENT_FIXED1X4:
                elementData.typeID = 428;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X4;
                break;
            case HASH_ELEMENT_FIXED2:
                elementData.typeID = 282;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2;
                break;
            case HASH_ELEMENT_FIXED2X1:
                elementData.typeID = 237;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X1;
                break;
            case HASH_ELEMENT_FIXED2X2:
                elementData.typeID = 499;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X2;
                break;
            case HASH_ELEMENT_FIXED2X3:
                elementData.typeID = 248;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X3;
                break;
            case HASH_ELEMENT_FIXED2X4:
                elementData.typeID = 541;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X4;
                break;
            case HASH_ELEMENT_FIXED3:
                elementData.typeID = 616;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3;
                break;
            case HASH_ELEMENT_FIXED3X1:
                elementData.typeID = 136;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X1;
                break;
            case HASH_ELEMENT_FIXED3X2:
                elementData.typeID = 522;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X2;
                break;
            case HASH_ELEMENT_FIXED3X3:
                elementData.typeID = 424;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X3;
                break;
            case HASH_ELEMENT_FIXED3X4:
                elementData.typeID = 493;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X4;
                break;
            case HASH_ELEMENT_FIXED4:
                elementData.typeID = 322;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4;
                break;
            case HASH_ELEMENT_FIXED4X1:
                elementData.typeID = 48;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X1;
                break;
            case HASH_ELEMENT_FIXED4X2:
                elementData.typeID = 374;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X2;
                break;
            case HASH_ELEMENT_FIXED4X3:
                elementData.typeID = 588;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X3;
                break;
            case HASH_ELEMENT_FIXED4X4:
                elementData.typeID = 252;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X4;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 401;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____CG_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1:
                elementData.typeID = 506;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 114;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____CG_FLOAT1X1;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 394;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____CG_FLOAT1X2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 111;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____CG_FLOAT1X3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 291;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____CG_FLOAT1X4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 238;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____CG_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 629;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____CG_FLOAT2X1;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 323;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____CG_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 438;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____CG_FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 53;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____CG_FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 88;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____CG_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 118;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____CG_FLOAT3X1;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 201;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____CG_FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 503;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____CG_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 191;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____CG_FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 246;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____CG_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 20;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____CG_FLOAT4X1;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 151;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____CG_FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 448;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____CG_FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 122;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____CG_FLOAT4X4;
                break;
            case HASH_ELEMENT_HALF:
                elementData.typeID = 437;
                elementData.generatedElementHash = HASH_ELEMENT_HALF;
                break;
            case HASH_ELEMENT_HALF1:
                elementData.typeID = 416;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1;
                break;
            case HASH_ELEMENT_HALF1X1:
                elementData.typeID = 229;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X1;
                break;
            case HASH_ELEMENT_HALF1X2:
                elementData.typeID = 565;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X2;
                break;
            case HASH_ELEMENT_HALF1X3:
                elementData.typeID = 99;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X3;
                break;
            case HASH_ELEMENT_HALF1X4:
                elementData.typeID = 397;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X4;
                break;
            case HASH_ELEMENT_HALF2:
                elementData.typeID = 60;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2;
                break;
            case HASH_ELEMENT_HALF2X1:
                elementData.typeID = 80;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X1;
                break;
            case HASH_ELEMENT_HALF2X2:
                elementData.typeID = 196;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X2;
                break;
            case HASH_ELEMENT_HALF2X3:
                elementData.typeID = 475;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X3;
                break;
            case HASH_ELEMENT_HALF2X4:
                elementData.typeID = 216;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X4;
                break;
            case HASH_ELEMENT_HALF3:
                elementData.typeID = 244;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3;
                break;
            case HASH_ELEMENT_HALF3X1:
                elementData.typeID = 547;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X1;
                break;
            case HASH_ELEMENT_HALF3X2:
                elementData.typeID = 245;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X2;
                break;
            case HASH_ELEMENT_HALF3X3:
                elementData.typeID = 476;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X3;
                break;
            case HASH_ELEMENT_HALF3X4:
                elementData.typeID = 178;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X4;
                break;
            case HASH_ELEMENT_HALF4:
                elementData.typeID = 266;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4;
                break;
            case HASH_ELEMENT_HALF4X1:
                elementData.typeID = 140;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X1;
                break;
            case HASH_ELEMENT_HALF4X2:
                elementData.typeID = 461;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X2;
                break;
            case HASH_ELEMENT_HALF4X3:
                elementData.typeID = 147;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X3;
                break;
            case HASH_ELEMENT_HALF4X4:
                elementData.typeID = 413;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 531;
                elementData.generatedElementHash = HASH_ELEMENT_INT____CG_INT;
                break;
            case HASH_ELEMENT_INT1:
                elementData.typeID = 603;
                elementData.generatedElementHash = HASH_ELEMENT_INT1;
                break;
            case HASH_ELEMENT_INT1X1:
                elementData.typeID = 607;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X1;
                break;
            case HASH_ELEMENT_INT1X2:
                elementData.typeID = 304;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X2;
                break;
            case HASH_ELEMENT_INT1X3:
                elementData.typeID = 470;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X3;
                break;
            case HASH_ELEMENT_INT1X4:
                elementData.typeID = 190;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X4;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 283;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____CG_INT2;
                break;
            case HASH_ELEMENT_INT2X1:
                elementData.typeID = 193;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X1;
                break;
            case HASH_ELEMENT_INT2X2:
                elementData.typeID = 64;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X2;
                break;
            case HASH_ELEMENT_INT2X3:
                elementData.typeID = 375;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X3;
                break;
            case HASH_ELEMENT_INT2X4:
                elementData.typeID = 30;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X4;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 509;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____CG_INT3;
                break;
            case HASH_ELEMENT_INT3X1:
                elementData.typeID = 426;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X1;
                break;
            case HASH_ELEMENT_INT3X2:
                elementData.typeID = 582;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X2;
                break;
            case HASH_ELEMENT_INT3X3:
                elementData.typeID = 383;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X3;
                break;
            case HASH_ELEMENT_INT3X4:
                elementData.typeID = 594;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X4;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 127;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____CG_INT4;
                break;
            case HASH_ELEMENT_INT4X1:
                elementData.typeID = 207;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X1;
                break;
            case HASH_ELEMENT_INT4X2:
                elementData.typeID = 159;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X2;
                break;
            case HASH_ELEMENT_INT4X3:
                elementData.typeID = 314;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X3;
                break;
            case HASH_ELEMENT_INT4X4:
                elementData.typeID = 511;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 359;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____CG_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 49;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____CG_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 595;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____CG_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 497;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 267;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 102;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT;
                break;
            case HASH_ELEMENT_STRING:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_STRING;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 225;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____CG_SURFACE_TYPE;
                break;
            case HASH_ELEMENT_USERTYPE:
                elementData.typeID = 566;
                elementData.generatedElementHash = HASH_ELEMENT_USERTYPE;
                break;
            default:
                return false;
            }
            break;
        case 625:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 351;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____CG_SETARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 205;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____CG_BOOL;
                break;
            case HASH_ELEMENT_BOOL1:
                elementData.typeID = 621;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1;
                break;
            case HASH_ELEMENT_BOOL1X1:
                elementData.typeID = 256;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X1;
                break;
            case HASH_ELEMENT_BOOL1X2:
                elementData.typeID = 228;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X2;
                break;
            case HASH_ELEMENT_BOOL1X3:
                elementData.typeID = 406;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X3;
                break;
            case HASH_ELEMENT_BOOL1X4:
                elementData.typeID = 91;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X4;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 317;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____CG_BOOL2;
                break;
            case HASH_ELEMENT_BOOL2X1:
                elementData.typeID = 610;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X1;
                break;
            case HASH_ELEMENT_BOOL2X2:
                elementData.typeID = 270;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X2;
                break;
            case HASH_ELEMENT_BOOL2X3:
                elementData.typeID = 592;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X3;
                break;
            case HASH_ELEMENT_BOOL2X4:
                elementData.typeID = 307;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X4;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 614;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____CG_BOOL3;
                break;
            case HASH_ELEMENT_BOOL3X1:
                elementData.typeID = 32;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X1;
                break;
            case HASH_ELEMENT_BOOL3X2:
                elementData.typeID = 257;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X2;
                break;
            case HASH_ELEMENT_BOOL3X3:
                elementData.typeID = 597;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X3;
                break;
            case HASH_ELEMENT_BOOL3X4:
                elementData.typeID = 385;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X4;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 75;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____CG_BOOL4;
                break;
            case HASH_ELEMENT_BOOL4X1:
                elementData.typeID = 1;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X1;
                break;
            case HASH_ELEMENT_BOOL4X2:
                elementData.typeID = 390;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X2;
                break;
            case HASH_ELEMENT_BOOL4X3:
                elementData.typeID = 132;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X3;
                break;
            case HASH_ELEMENT_BOOL4X4:
                elementData.typeID = 346;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X4;
                break;
            case HASH_ELEMENT_CONNECT_PARAM:
                elementData.typeID = 455;
                elementData.generatedElementHash = HASH_ELEMENT_CONNECT_PARAM;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FIXED:
                elementData.typeID = 590;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED;
                break;
            case HASH_ELEMENT_FIXED1:
                elementData.typeID = 587;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1;
                break;
            case HASH_ELEMENT_FIXED1X1:
                elementData.typeID = 514;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X1;
                break;
            case HASH_ELEMENT_FIXED1X2:
                elementData.typeID = 211;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X2;
                break;
            case HASH_ELEMENT_FIXED1X3:
                elementData.typeID = 107;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X3;
                break;
            case HASH_ELEMENT_FIXED1X4:
                elementData.typeID = 428;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X4;
                break;
            case HASH_ELEMENT_FIXED2:
                elementData.typeID = 282;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2;
                break;
            case HASH_ELEMENT_FIXED2X1:
                elementData.typeID = 237;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X1;
                break;
            case HASH_ELEMENT_FIXED2X2:
                elementData.typeID = 499;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X2;
                break;
            case HASH_ELEMENT_FIXED2X3:
                elementData.typeID = 248;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X3;
                break;
            case HASH_ELEMENT_FIXED2X4:
                elementData.typeID = 541;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X4;
                break;
            case HASH_ELEMENT_FIXED3:
                elementData.typeID = 616;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3;
                break;
            case HASH_ELEMENT_FIXED3X1:
                elementData.typeID = 136;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X1;
                break;
            case HASH_ELEMENT_FIXED3X2:
                elementData.typeID = 522;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X2;
                break;
            case HASH_ELEMENT_FIXED3X3:
                elementData.typeID = 424;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X3;
                break;
            case HASH_ELEMENT_FIXED3X4:
                elementData.typeID = 493;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X4;
                break;
            case HASH_ELEMENT_FIXED4:
                elementData.typeID = 322;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4;
                break;
            case HASH_ELEMENT_FIXED4X1:
                elementData.typeID = 48;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X1;
                break;
            case HASH_ELEMENT_FIXED4X2:
                elementData.typeID = 374;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X2;
                break;
            case HASH_ELEMENT_FIXED4X3:
                elementData.typeID = 588;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X3;
                break;
            case HASH_ELEMENT_FIXED4X4:
                elementData.typeID = 252;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X4;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 401;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____CG_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1:
                elementData.typeID = 506;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 114;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____CG_FLOAT1X1;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 394;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____CG_FLOAT1X2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 111;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____CG_FLOAT1X3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 291;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____CG_FLOAT1X4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 238;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____CG_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 629;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____CG_FLOAT2X1;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 323;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____CG_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 438;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____CG_FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 53;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____CG_FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 88;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____CG_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 118;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____CG_FLOAT3X1;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 201;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____CG_FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 503;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____CG_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 191;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____CG_FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 246;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____CG_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 20;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____CG_FLOAT4X1;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 151;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____CG_FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 448;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____CG_FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 122;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____CG_FLOAT4X4;
                break;
            case HASH_ELEMENT_HALF:
                elementData.typeID = 437;
                elementData.generatedElementHash = HASH_ELEMENT_HALF;
                break;
            case HASH_ELEMENT_HALF1:
                elementData.typeID = 416;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1;
                break;
            case HASH_ELEMENT_HALF1X1:
                elementData.typeID = 229;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X1;
                break;
            case HASH_ELEMENT_HALF1X2:
                elementData.typeID = 565;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X2;
                break;
            case HASH_ELEMENT_HALF1X3:
                elementData.typeID = 99;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X3;
                break;
            case HASH_ELEMENT_HALF1X4:
                elementData.typeID = 397;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X4;
                break;
            case HASH_ELEMENT_HALF2:
                elementData.typeID = 60;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2;
                break;
            case HASH_ELEMENT_HALF2X1:
                elementData.typeID = 80;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X1;
                break;
            case HASH_ELEMENT_HALF2X2:
                elementData.typeID = 196;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X2;
                break;
            case HASH_ELEMENT_HALF2X3:
                elementData.typeID = 475;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X3;
                break;
            case HASH_ELEMENT_HALF2X4:
                elementData.typeID = 216;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X4;
                break;
            case HASH_ELEMENT_HALF3:
                elementData.typeID = 244;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3;
                break;
            case HASH_ELEMENT_HALF3X1:
                elementData.typeID = 547;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X1;
                break;
            case HASH_ELEMENT_HALF3X2:
                elementData.typeID = 245;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X2;
                break;
            case HASH_ELEMENT_HALF3X3:
                elementData.typeID = 476;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X3;
                break;
            case HASH_ELEMENT_HALF3X4:
                elementData.typeID = 178;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X4;
                break;
            case HASH_ELEMENT_HALF4:
                elementData.typeID = 266;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4;
                break;
            case HASH_ELEMENT_HALF4X1:
                elementData.typeID = 140;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X1;
                break;
            case HASH_ELEMENT_HALF4X2:
                elementData.typeID = 461;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X2;
                break;
            case HASH_ELEMENT_HALF4X3:
                elementData.typeID = 147;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X3;
                break;
            case HASH_ELEMENT_HALF4X4:
                elementData.typeID = 413;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 531;
                elementData.generatedElementHash = HASH_ELEMENT_INT____CG_INT;
                break;
            case HASH_ELEMENT_INT1:
                elementData.typeID = 603;
                elementData.generatedElementHash = HASH_ELEMENT_INT1;
                break;
            case HASH_ELEMENT_INT1X1:
                elementData.typeID = 607;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X1;
                break;
            case HASH_ELEMENT_INT1X2:
                elementData.typeID = 304;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X2;
                break;
            case HASH_ELEMENT_INT1X3:
                elementData.typeID = 470;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X3;
                break;
            case HASH_ELEMENT_INT1X4:
                elementData.typeID = 190;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X4;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 283;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____CG_INT2;
                break;
            case HASH_ELEMENT_INT2X1:
                elementData.typeID = 193;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X1;
                break;
            case HASH_ELEMENT_INT2X2:
                elementData.typeID = 64;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X2;
                break;
            case HASH_ELEMENT_INT2X3:
                elementData.typeID = 375;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X3;
                break;
            case HASH_ELEMENT_INT2X4:
                elementData.typeID = 30;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X4;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 509;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____CG_INT3;
                break;
            case HASH_ELEMENT_INT3X1:
                elementData.typeID = 426;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X1;
                break;
            case HASH_ELEMENT_INT3X2:
                elementData.typeID = 582;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X2;
                break;
            case HASH_ELEMENT_INT3X3:
                elementData.typeID = 383;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X3;
                break;
            case HASH_ELEMENT_INT3X4:
                elementData.typeID = 594;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X4;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 127;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____CG_INT4;
                break;
            case HASH_ELEMENT_INT4X1:
                elementData.typeID = 207;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X1;
                break;
            case HASH_ELEMENT_INT4X2:
                elementData.typeID = 159;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X2;
                break;
            case HASH_ELEMENT_INT4X3:
                elementData.typeID = 314;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X3;
                break;
            case HASH_ELEMENT_INT4X4:
                elementData.typeID = 511;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 359;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____CG_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 49;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____CG_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 595;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____CG_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 497;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 267;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 102;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT;
                break;
            case HASH_ELEMENT_STRING:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_STRING;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 225;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____CG_SURFACE_TYPE;
                break;
            case HASH_ELEMENT_USERTYPE:
                elementData.typeID = 566;
                elementData.generatedElementHash = HASH_ELEMENT_USERTYPE;
                break;
            default:
                return false;
            }
            break;
        case 626:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 205;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____CG_BOOL;
                break;
            case HASH_ELEMENT_BOOL1:
                elementData.typeID = 621;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1;
                break;
            case HASH_ELEMENT_BOOL1X1:
                elementData.typeID = 256;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X1;
                break;
            case HASH_ELEMENT_BOOL1X2:
                elementData.typeID = 228;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X2;
                break;
            case HASH_ELEMENT_BOOL1X3:
                elementData.typeID = 406;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X3;
                break;
            case HASH_ELEMENT_BOOL1X4:
                elementData.typeID = 91;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X4;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 317;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____CG_BOOL2;
                break;
            case HASH_ELEMENT_BOOL2X1:
                elementData.typeID = 610;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X1;
                break;
            case HASH_ELEMENT_BOOL2X2:
                elementData.typeID = 270;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X2;
                break;
            case HASH_ELEMENT_BOOL2X3:
                elementData.typeID = 592;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X3;
                break;
            case HASH_ELEMENT_BOOL2X4:
                elementData.typeID = 307;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X4;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 614;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____CG_BOOL3;
                break;
            case HASH_ELEMENT_BOOL3X1:
                elementData.typeID = 32;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X1;
                break;
            case HASH_ELEMENT_BOOL3X2:
                elementData.typeID = 257;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X2;
                break;
            case HASH_ELEMENT_BOOL3X3:
                elementData.typeID = 597;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X3;
                break;
            case HASH_ELEMENT_BOOL3X4:
                elementData.typeID = 385;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X4;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 75;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____CG_BOOL4;
                break;
            case HASH_ELEMENT_BOOL4X1:
                elementData.typeID = 1;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X1;
                break;
            case HASH_ELEMENT_BOOL4X2:
                elementData.typeID = 390;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X2;
                break;
            case HASH_ELEMENT_BOOL4X3:
                elementData.typeID = 132;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X3;
                break;
            case HASH_ELEMENT_BOOL4X4:
                elementData.typeID = 346;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FIXED:
                elementData.typeID = 590;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED;
                break;
            case HASH_ELEMENT_FIXED1:
                elementData.typeID = 587;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1;
                break;
            case HASH_ELEMENT_FIXED1X1:
                elementData.typeID = 514;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X1;
                break;
            case HASH_ELEMENT_FIXED1X2:
                elementData.typeID = 211;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X2;
                break;
            case HASH_ELEMENT_FIXED1X3:
                elementData.typeID = 107;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X3;
                break;
            case HASH_ELEMENT_FIXED1X4:
                elementData.typeID = 428;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X4;
                break;
            case HASH_ELEMENT_FIXED2:
                elementData.typeID = 282;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2;
                break;
            case HASH_ELEMENT_FIXED2X1:
                elementData.typeID = 237;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X1;
                break;
            case HASH_ELEMENT_FIXED2X2:
                elementData.typeID = 499;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X2;
                break;
            case HASH_ELEMENT_FIXED2X3:
                elementData.typeID = 248;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X3;
                break;
            case HASH_ELEMENT_FIXED2X4:
                elementData.typeID = 541;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X4;
                break;
            case HASH_ELEMENT_FIXED3:
                elementData.typeID = 616;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3;
                break;
            case HASH_ELEMENT_FIXED3X1:
                elementData.typeID = 136;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X1;
                break;
            case HASH_ELEMENT_FIXED3X2:
                elementData.typeID = 522;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X2;
                break;
            case HASH_ELEMENT_FIXED3X3:
                elementData.typeID = 424;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X3;
                break;
            case HASH_ELEMENT_FIXED3X4:
                elementData.typeID = 493;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X4;
                break;
            case HASH_ELEMENT_FIXED4:
                elementData.typeID = 322;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4;
                break;
            case HASH_ELEMENT_FIXED4X1:
                elementData.typeID = 48;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X1;
                break;
            case HASH_ELEMENT_FIXED4X2:
                elementData.typeID = 374;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X2;
                break;
            case HASH_ELEMENT_FIXED4X3:
                elementData.typeID = 588;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X3;
                break;
            case HASH_ELEMENT_FIXED4X4:
                elementData.typeID = 252;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X4;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 401;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____CG_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1:
                elementData.typeID = 506;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 114;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____CG_FLOAT1X1;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 394;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____CG_FLOAT1X2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 111;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____CG_FLOAT1X3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 291;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____CG_FLOAT1X4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 238;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____CG_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 629;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____CG_FLOAT2X1;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 323;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____CG_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 438;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____CG_FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 53;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____CG_FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 88;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____CG_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 118;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____CG_FLOAT3X1;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 201;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____CG_FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 503;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____CG_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 191;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____CG_FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 246;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____CG_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 20;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____CG_FLOAT4X1;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 151;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____CG_FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 448;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____CG_FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 122;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____CG_FLOAT4X4;
                break;
            case HASH_ELEMENT_HALF:
                elementData.typeID = 437;
                elementData.generatedElementHash = HASH_ELEMENT_HALF;
                break;
            case HASH_ELEMENT_HALF1:
                elementData.typeID = 416;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1;
                break;
            case HASH_ELEMENT_HALF1X1:
                elementData.typeID = 229;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X1;
                break;
            case HASH_ELEMENT_HALF1X2:
                elementData.typeID = 565;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X2;
                break;
            case HASH_ELEMENT_HALF1X3:
                elementData.typeID = 99;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X3;
                break;
            case HASH_ELEMENT_HALF1X4:
                elementData.typeID = 397;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X4;
                break;
            case HASH_ELEMENT_HALF2:
                elementData.typeID = 60;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2;
                break;
            case HASH_ELEMENT_HALF2X1:
                elementData.typeID = 80;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X1;
                break;
            case HASH_ELEMENT_HALF2X2:
                elementData.typeID = 196;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X2;
                break;
            case HASH_ELEMENT_HALF2X3:
                elementData.typeID = 475;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X3;
                break;
            case HASH_ELEMENT_HALF2X4:
                elementData.typeID = 216;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X4;
                break;
            case HASH_ELEMENT_HALF3:
                elementData.typeID = 244;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3;
                break;
            case HASH_ELEMENT_HALF3X1:
                elementData.typeID = 547;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X1;
                break;
            case HASH_ELEMENT_HALF3X2:
                elementData.typeID = 245;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X2;
                break;
            case HASH_ELEMENT_HALF3X3:
                elementData.typeID = 476;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X3;
                break;
            case HASH_ELEMENT_HALF3X4:
                elementData.typeID = 178;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X4;
                break;
            case HASH_ELEMENT_HALF4:
                elementData.typeID = 266;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4;
                break;
            case HASH_ELEMENT_HALF4X1:
                elementData.typeID = 140;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X1;
                break;
            case HASH_ELEMENT_HALF4X2:
                elementData.typeID = 461;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X2;
                break;
            case HASH_ELEMENT_HALF4X3:
                elementData.typeID = 147;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X3;
                break;
            case HASH_ELEMENT_HALF4X4:
                elementData.typeID = 413;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 531;
                elementData.generatedElementHash = HASH_ELEMENT_INT____CG_INT;
                break;
            case HASH_ELEMENT_INT1:
                elementData.typeID = 603;
                elementData.generatedElementHash = HASH_ELEMENT_INT1;
                break;
            case HASH_ELEMENT_INT1X1:
                elementData.typeID = 607;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X1;
                break;
            case HASH_ELEMENT_INT1X2:
                elementData.typeID = 304;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X2;
                break;
            case HASH_ELEMENT_INT1X3:
                elementData.typeID = 470;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X3;
                break;
            case HASH_ELEMENT_INT1X4:
                elementData.typeID = 190;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X4;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 283;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____CG_INT2;
                break;
            case HASH_ELEMENT_INT2X1:
                elementData.typeID = 193;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X1;
                break;
            case HASH_ELEMENT_INT2X2:
                elementData.typeID = 64;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X2;
                break;
            case HASH_ELEMENT_INT2X3:
                elementData.typeID = 375;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X3;
                break;
            case HASH_ELEMENT_INT2X4:
                elementData.typeID = 30;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X4;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 509;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____CG_INT3;
                break;
            case HASH_ELEMENT_INT3X1:
                elementData.typeID = 426;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X1;
                break;
            case HASH_ELEMENT_INT3X2:
                elementData.typeID = 582;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X2;
                break;
            case HASH_ELEMENT_INT3X3:
                elementData.typeID = 383;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X3;
                break;
            case HASH_ELEMENT_INT3X4:
                elementData.typeID = 594;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X4;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 127;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____CG_INT4;
                break;
            case HASH_ELEMENT_INT4X1:
                elementData.typeID = 207;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X1;
                break;
            case HASH_ELEMENT_INT4X2:
                elementData.typeID = 159;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X2;
                break;
            case HASH_ELEMENT_INT4X3:
                elementData.typeID = 314;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X3;
                break;
            case HASH_ELEMENT_INT4X4:
                elementData.typeID = 511;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 359;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____CG_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 49;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____CG_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 595;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____CG_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 497;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 267;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 102;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT;
                break;
            case HASH_ELEMENT_STRING:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_STRING;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 225;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____CG_SURFACE_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 566:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 351;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____CG_SETARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 205;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____CG_BOOL;
                break;
            case HASH_ELEMENT_BOOL1:
                elementData.typeID = 621;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1;
                break;
            case HASH_ELEMENT_BOOL1X1:
                elementData.typeID = 256;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X1;
                break;
            case HASH_ELEMENT_BOOL1X2:
                elementData.typeID = 228;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X2;
                break;
            case HASH_ELEMENT_BOOL1X3:
                elementData.typeID = 406;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X3;
                break;
            case HASH_ELEMENT_BOOL1X4:
                elementData.typeID = 91;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL1X4;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 317;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____CG_BOOL2;
                break;
            case HASH_ELEMENT_BOOL2X1:
                elementData.typeID = 610;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X1;
                break;
            case HASH_ELEMENT_BOOL2X2:
                elementData.typeID = 270;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X2;
                break;
            case HASH_ELEMENT_BOOL2X3:
                elementData.typeID = 592;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X3;
                break;
            case HASH_ELEMENT_BOOL2X4:
                elementData.typeID = 307;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2X4;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 614;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____CG_BOOL3;
                break;
            case HASH_ELEMENT_BOOL3X1:
                elementData.typeID = 32;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X1;
                break;
            case HASH_ELEMENT_BOOL3X2:
                elementData.typeID = 257;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X2;
                break;
            case HASH_ELEMENT_BOOL3X3:
                elementData.typeID = 597;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X3;
                break;
            case HASH_ELEMENT_BOOL3X4:
                elementData.typeID = 385;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3X4;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 75;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____CG_BOOL4;
                break;
            case HASH_ELEMENT_BOOL4X1:
                elementData.typeID = 1;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X1;
                break;
            case HASH_ELEMENT_BOOL4X2:
                elementData.typeID = 390;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X2;
                break;
            case HASH_ELEMENT_BOOL4X3:
                elementData.typeID = 132;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X3;
                break;
            case HASH_ELEMENT_BOOL4X4:
                elementData.typeID = 346;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4X4;
                break;
            case HASH_ELEMENT_CONNECT_PARAM:
                elementData.typeID = 455;
                elementData.generatedElementHash = HASH_ELEMENT_CONNECT_PARAM;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FIXED:
                elementData.typeID = 590;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED;
                break;
            case HASH_ELEMENT_FIXED1:
                elementData.typeID = 587;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1;
                break;
            case HASH_ELEMENT_FIXED1X1:
                elementData.typeID = 514;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X1;
                break;
            case HASH_ELEMENT_FIXED1X2:
                elementData.typeID = 211;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X2;
                break;
            case HASH_ELEMENT_FIXED1X3:
                elementData.typeID = 107;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X3;
                break;
            case HASH_ELEMENT_FIXED1X4:
                elementData.typeID = 428;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED1X4;
                break;
            case HASH_ELEMENT_FIXED2:
                elementData.typeID = 282;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2;
                break;
            case HASH_ELEMENT_FIXED2X1:
                elementData.typeID = 237;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X1;
                break;
            case HASH_ELEMENT_FIXED2X2:
                elementData.typeID = 499;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X2;
                break;
            case HASH_ELEMENT_FIXED2X3:
                elementData.typeID = 248;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X3;
                break;
            case HASH_ELEMENT_FIXED2X4:
                elementData.typeID = 541;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED2X4;
                break;
            case HASH_ELEMENT_FIXED3:
                elementData.typeID = 616;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3;
                break;
            case HASH_ELEMENT_FIXED3X1:
                elementData.typeID = 136;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X1;
                break;
            case HASH_ELEMENT_FIXED3X2:
                elementData.typeID = 522;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X2;
                break;
            case HASH_ELEMENT_FIXED3X3:
                elementData.typeID = 424;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X3;
                break;
            case HASH_ELEMENT_FIXED3X4:
                elementData.typeID = 493;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED3X4;
                break;
            case HASH_ELEMENT_FIXED4:
                elementData.typeID = 322;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4;
                break;
            case HASH_ELEMENT_FIXED4X1:
                elementData.typeID = 48;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X1;
                break;
            case HASH_ELEMENT_FIXED4X2:
                elementData.typeID = 374;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X2;
                break;
            case HASH_ELEMENT_FIXED4X3:
                elementData.typeID = 588;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X3;
                break;
            case HASH_ELEMENT_FIXED4X4:
                elementData.typeID = 252;
                elementData.generatedElementHash = HASH_ELEMENT_FIXED4X4;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 401;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____CG_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1:
                elementData.typeID = 506;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 114;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____CG_FLOAT1X1;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 394;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____CG_FLOAT1X2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 111;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____CG_FLOAT1X3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 291;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____CG_FLOAT1X4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 238;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____CG_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 629;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____CG_FLOAT2X1;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 323;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____CG_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 438;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____CG_FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 53;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____CG_FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 88;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____CG_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 118;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____CG_FLOAT3X1;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 201;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____CG_FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 503;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____CG_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 191;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____CG_FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 246;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____CG_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 20;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____CG_FLOAT4X1;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 151;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____CG_FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 448;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____CG_FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 122;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____CG_FLOAT4X4;
                break;
            case HASH_ELEMENT_HALF:
                elementData.typeID = 437;
                elementData.generatedElementHash = HASH_ELEMENT_HALF;
                break;
            case HASH_ELEMENT_HALF1:
                elementData.typeID = 416;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1;
                break;
            case HASH_ELEMENT_HALF1X1:
                elementData.typeID = 229;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X1;
                break;
            case HASH_ELEMENT_HALF1X2:
                elementData.typeID = 565;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X2;
                break;
            case HASH_ELEMENT_HALF1X3:
                elementData.typeID = 99;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X3;
                break;
            case HASH_ELEMENT_HALF1X4:
                elementData.typeID = 397;
                elementData.generatedElementHash = HASH_ELEMENT_HALF1X4;
                break;
            case HASH_ELEMENT_HALF2:
                elementData.typeID = 60;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2;
                break;
            case HASH_ELEMENT_HALF2X1:
                elementData.typeID = 80;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X1;
                break;
            case HASH_ELEMENT_HALF2X2:
                elementData.typeID = 196;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X2;
                break;
            case HASH_ELEMENT_HALF2X3:
                elementData.typeID = 475;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X3;
                break;
            case HASH_ELEMENT_HALF2X4:
                elementData.typeID = 216;
                elementData.generatedElementHash = HASH_ELEMENT_HALF2X4;
                break;
            case HASH_ELEMENT_HALF3:
                elementData.typeID = 244;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3;
                break;
            case HASH_ELEMENT_HALF3X1:
                elementData.typeID = 547;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X1;
                break;
            case HASH_ELEMENT_HALF3X2:
                elementData.typeID = 245;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X2;
                break;
            case HASH_ELEMENT_HALF3X3:
                elementData.typeID = 476;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X3;
                break;
            case HASH_ELEMENT_HALF3X4:
                elementData.typeID = 178;
                elementData.generatedElementHash = HASH_ELEMENT_HALF3X4;
                break;
            case HASH_ELEMENT_HALF4:
                elementData.typeID = 266;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4;
                break;
            case HASH_ELEMENT_HALF4X1:
                elementData.typeID = 140;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X1;
                break;
            case HASH_ELEMENT_HALF4X2:
                elementData.typeID = 461;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X2;
                break;
            case HASH_ELEMENT_HALF4X3:
                elementData.typeID = 147;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X3;
                break;
            case HASH_ELEMENT_HALF4X4:
                elementData.typeID = 413;
                elementData.generatedElementHash = HASH_ELEMENT_HALF4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 531;
                elementData.generatedElementHash = HASH_ELEMENT_INT____CG_INT;
                break;
            case HASH_ELEMENT_INT1:
                elementData.typeID = 603;
                elementData.generatedElementHash = HASH_ELEMENT_INT1;
                break;
            case HASH_ELEMENT_INT1X1:
                elementData.typeID = 607;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X1;
                break;
            case HASH_ELEMENT_INT1X2:
                elementData.typeID = 304;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X2;
                break;
            case HASH_ELEMENT_INT1X3:
                elementData.typeID = 470;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X3;
                break;
            case HASH_ELEMENT_INT1X4:
                elementData.typeID = 190;
                elementData.generatedElementHash = HASH_ELEMENT_INT1X4;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 283;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____CG_INT2;
                break;
            case HASH_ELEMENT_INT2X1:
                elementData.typeID = 193;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X1;
                break;
            case HASH_ELEMENT_INT2X2:
                elementData.typeID = 64;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X2;
                break;
            case HASH_ELEMENT_INT2X3:
                elementData.typeID = 375;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X3;
                break;
            case HASH_ELEMENT_INT2X4:
                elementData.typeID = 30;
                elementData.generatedElementHash = HASH_ELEMENT_INT2X4;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 509;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____CG_INT3;
                break;
            case HASH_ELEMENT_INT3X1:
                elementData.typeID = 426;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X1;
                break;
            case HASH_ELEMENT_INT3X2:
                elementData.typeID = 582;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X2;
                break;
            case HASH_ELEMENT_INT3X3:
                elementData.typeID = 383;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X3;
                break;
            case HASH_ELEMENT_INT3X4:
                elementData.typeID = 594;
                elementData.generatedElementHash = HASH_ELEMENT_INT3X4;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 127;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____CG_INT4;
                break;
            case HASH_ELEMENT_INT4X1:
                elementData.typeID = 207;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X1;
                break;
            case HASH_ELEMENT_INT4X2:
                elementData.typeID = 159;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X2;
                break;
            case HASH_ELEMENT_INT4X3:
                elementData.typeID = 314;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X3;
                break;
            case HASH_ELEMENT_INT4X4:
                elementData.typeID = 511;
                elementData.generatedElementHash = HASH_ELEMENT_INT4X4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 359;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____CG_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 49;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____CG_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 595;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____CG_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 497;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 267;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 102;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT;
                break;
            case HASH_ELEMENT_SETPARAM:
                elementData.typeID = 625;
                elementData.generatedElementHash = HASH_ELEMENT_SETPARAM____CG_SETPARAM;
                break;
            case HASH_ELEMENT_STRING:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_STRING;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 225;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____CG_SURFACE_TYPE;
                break;
            case HASH_ELEMENT_USERTYPE:
                elementData.typeID = 566;
                elementData.generatedElementHash = HASH_ELEMENT_USERTYPE;
                break;
            default:
                return false;
            }
            break;
        case 225:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_FORMAT:
                elementData.typeID = 33;
                elementData.generatedElementHash = HASH_ELEMENT_FORMAT;
                break;
            case HASH_ELEMENT_FORMAT_HINT:
                elementData.typeID = 106;
                elementData.generatedElementHash = HASH_ELEMENT_FORMAT_HINT;
                break;
            case HASH_ELEMENT_GENERATOR:
                elementData.typeID = 160;
                elementData.generatedElementHash = HASH_ELEMENT_CG_SURFACE_TYPE____GENERATOR;
                break;
            case HASH_ELEMENT_INIT_AS_NULL:
                elementData.typeID = 78;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_AS_NULL;
                break;
            case HASH_ELEMENT_INIT_AS_TARGET:
                elementData.typeID = 78;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_AS_TARGET;
                break;
            case HASH_ELEMENT_INIT_CUBE:
                elementData.typeID = 599;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_CUBE;
                break;
            case HASH_ELEMENT_INIT_FROM:
                elementData.typeID = 365;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_FROM____FX_SURFACE_INIT_FROM_COMMON;
                break;
            case HASH_ELEMENT_INIT_PLANAR:
                elementData.typeID = 86;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_PLANAR;
                break;
            case HASH_ELEMENT_INIT_VOLUME:
                elementData.typeID = 69;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_VOLUME;
                break;
            case HASH_ELEMENT_MIP_LEVELS:
                elementData.typeID = 396;
                elementData.generatedElementHash = HASH_ELEMENT_MIP_LEVELS;
                break;
            case HASH_ELEMENT_MIPMAP_GENERATE:
                elementData.typeID = 165;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_GENERATE;
                break;
            case HASH_ELEMENT_SIZE:
                elementData.typeID = 405;
                elementData.generatedElementHash = HASH_ELEMENT_SIZE____INT3;
                break;
            case HASH_ELEMENT_VIEWPORT_RATIO:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_VIEWPORT_RATIO;
                break;
            default:
                return false;
            }
            break;
        case 19:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_COLOR:
                elementData.typeID = 456;
                elementData.generatedElementHash = HASH_ELEMENT_COMMON_COLOR_OR_TEXTURE_TYPE____COLOR;
                break;
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 156;
                elementData.generatedElementHash = HASH_ELEMENT_COMMON_COLOR_OR_TEXTURE_TYPE____PARAM;
                break;
            case HASH_ELEMENT_TEXTURE:
                elementData.typeID = 409;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE;
                break;
            default:
                return false;
            }
            break;
        case 173:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 400;
                elementData.generatedElementHash = HASH_ELEMENT_COMMON_FLOAT_OR_PARAM_TYPE____FLOAT;
                break;
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 157;
                elementData.generatedElementHash = HASH_ELEMENT_COMMON_FLOAT_OR_PARAM_TYPE____PARAM;
                break;
            default:
                return false;
            }
            break;
        case 554:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____FLOAT4;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 50;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____FX_SAMPLER2D_COMMON;
                break;
            case HASH_ELEMENT_SEMANTIC:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SEMANTIC;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 226;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____FX_SURFACE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 217:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_COLOR:
                elementData.typeID = 456;
                elementData.generatedElementHash = HASH_ELEMENT_COMMON_COLOR_OR_TEXTURE_TYPE____COLOR;
                break;
            case HASH_ELEMENT_PARAM:
                elementData.typeID = 156;
                elementData.generatedElementHash = HASH_ELEMENT_COMMON_COLOR_OR_TEXTURE_TYPE____PARAM;
                break;
            case HASH_ELEMENT_TEXTURE:
                elementData.typeID = 409;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE;
                break;
            default:
                return false;
            }
            break;
        case 425:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 204;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 316;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 613;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 74;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____BOOL4;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 324;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 504;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 123;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 533;
                elementData.generatedElementHash = HASH_ELEMENT_INT____INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 285;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 405;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 129;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____INT4;
                break;
            case HASH_ELEMENT_STRING:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_STRING;
                break;
            default:
                return false;
            }
            break;
        case 555:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 204;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 316;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 613;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 74;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 146;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____STRING;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 324;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 439;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 54;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 202;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 504;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 192;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 152;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 449;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 123;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 533;
                elementData.generatedElementHash = HASH_ELEMENT_INT____INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 285;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 405;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 129;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____INT4;
                break;
            case HASH_ELEMENT_MODIFIER:
                elementData.typeID = 560;
                elementData.generatedElementHash = HASH_ELEMENT_MODIFIER;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 360;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____FX_SAMPLER1D_COMMON;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 50;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____FX_SAMPLER2D_COMMON;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 596;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____FX_SAMPLER3D_COMMON;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 498;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____FX_SAMPLERCUBE_COMMON;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 268;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____FX_SAMPLERDEPTH_COMMON;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 103;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____FX_SAMPLERRECT_COMMON;
                break;
            case HASH_ELEMENT_SEMANTIC:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SEMANTIC;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 226;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____FX_SURFACE_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 360:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 50:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 596:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_P:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_P;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 498:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_P:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_P;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 268:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 103:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 226:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_FORMAT:
                elementData.typeID = 33;
                elementData.generatedElementHash = HASH_ELEMENT_FORMAT;
                break;
            case HASH_ELEMENT_FORMAT_HINT:
                elementData.typeID = 106;
                elementData.generatedElementHash = HASH_ELEMENT_FORMAT_HINT;
                break;
            case HASH_ELEMENT_INIT_AS_NULL:
                elementData.typeID = 78;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_AS_NULL;
                break;
            case HASH_ELEMENT_INIT_AS_TARGET:
                elementData.typeID = 78;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_AS_TARGET;
                break;
            case HASH_ELEMENT_INIT_CUBE:
                elementData.typeID = 599;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_CUBE;
                break;
            case HASH_ELEMENT_INIT_FROM:
                elementData.typeID = 365;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_FROM____FX_SURFACE_INIT_FROM_COMMON;
                break;
            case HASH_ELEMENT_INIT_PLANAR:
                elementData.typeID = 86;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_PLANAR;
                break;
            case HASH_ELEMENT_INIT_VOLUME:
                elementData.typeID = 69;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_VOLUME;
                break;
            case HASH_ELEMENT_MIP_LEVELS:
                elementData.typeID = 396;
                elementData.generatedElementHash = HASH_ELEMENT_MIP_LEVELS;
                break;
            case HASH_ELEMENT_MIPMAP_GENERATE:
                elementData.typeID = 165;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_GENERATE;
                break;
            case HASH_ELEMENT_SIZE:
                elementData.typeID = 405;
                elementData.generatedElementHash = HASH_ELEMENT_SIZE____INT3;
                break;
            case HASH_ELEMENT_VIEWPORT_RATIO:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_VIEWPORT_RATIO;
                break;
            default:
                return false;
            }
            break;
        case 106:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_CHANNELS:
                elementData.typeID = 466;
                elementData.generatedElementHash = HASH_ELEMENT_CHANNELS;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_OPTION:
                elementData.typeID = 92;
                elementData.generatedElementHash = HASH_ELEMENT_OPTION;
                break;
            case HASH_ELEMENT_PRECISION:
                elementData.typeID = 327;
                elementData.generatedElementHash = HASH_ELEMENT_PRECISION;
                break;
            case HASH_ELEMENT_RANGE:
                elementData.typeID = 418;
                elementData.generatedElementHash = HASH_ELEMENT_RANGE;
                break;
            default:
                return false;
            }
            break;
        case 599:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ALL:
                elementData.typeID = 96;
                elementData.generatedElementHash = HASH_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____ALL;
                break;
            case HASH_ELEMENT_FACE:
                elementData.typeID = 367;
                elementData.generatedElementHash = HASH_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____FACE;
                break;
            case HASH_ELEMENT_PRIMARY:
                elementData.typeID = 376;
                elementData.generatedElementHash = HASH_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____PRIMARY;
                break;
            default:
                return false;
            }
            break;
        case 86:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ALL:
                elementData.typeID = 97;
                elementData.generatedElementHash = HASH_ELEMENT_FX_SURFACE_INIT_PLANAR_COMMON____ALL;
                break;
            default:
                return false;
            }
            break;
        case 69:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ALL:
                elementData.typeID = 98;
                elementData.generatedElementHash = HASH_ELEMENT_FX_SURFACE_INIT_VOLUME_COMMON____ALL;
                break;
            case HASH_ELEMENT_PRIMARY:
                elementData.typeID = 377;
                elementData.generatedElementHash = HASH_ELEMENT_FX_SURFACE_INIT_VOLUME_COMMON____PRIMARY;
                break;
            default:
                return false;
            }
            break;
        case 361:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 51:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 380:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_P:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_P;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 381:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_P:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_P;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 269:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 104:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_BORDER_COLOR:
                elementData.typeID = 138;
                elementData.generatedElementHash = HASH_ELEMENT_BORDER_COLOR;
                break;
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_SOURCE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SOURCE____NCNAME;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 162;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
                break;
            default:
                return false;
            }
            break;
        case 556:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 204;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 316;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 613;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 74;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 264;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GLES_ENUMERATION;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1X1:
                elementData.typeID = 68;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X1____FLOAT;
                break;
            case HASH_ELEMENT_FLOAT1X2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT1X3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT1X4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT1X4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X1:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X1____FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 324;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT2X3:
                elementData.typeID = 439;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X3____FLOAT2X3;
                break;
            case HASH_ELEMENT_FLOAT2X4:
                elementData.typeID = 54;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X4____FLOAT2X4;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X1:
                elementData.typeID = 89;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X1____FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X2:
                elementData.typeID = 202;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X2____FLOAT3X2;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 504;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT3X4:
                elementData.typeID = 192;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X4____FLOAT3X4;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X1:
                elementData.typeID = 21;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X1____FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X2:
                elementData.typeID = 152;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X2____FLOAT4X2;
                break;
            case HASH_ELEMENT_FLOAT4X3:
                elementData.typeID = 449;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X3____FLOAT4X3;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 123;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 533;
                elementData.generatedElementHash = HASH_ELEMENT_INT____INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 285;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 405;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 129;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____INT4;
                break;
            case HASH_ELEMENT_MODIFIER:
                elementData.typeID = 560;
                elementData.generatedElementHash = HASH_ELEMENT_MODIFIER;
                break;
            case HASH_ELEMENT_SAMPLER_STATE:
                elementData.typeID = 109;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER_STATE____GLES_SAMPLER_STATE;
                break;
            case HASH_ELEMENT_SEMANTIC:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SEMANTIC;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 226;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____FX_SURFACE_COMMON;
                break;
            case HASH_ELEMENT_TEXTURE_PIPELINE:
                elementData.typeID = 341;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_PIPELINE____GLES_TEXTURE_PIPELINE;
                break;
            case HASH_ELEMENT_TEXTURE_UNIT:
                elementData.typeID = 478;
                elementData.generatedElementHash = HASH_ELEMENT_TEXTURE_UNIT;
                break;
            default:
                return false;
            }
            break;
        case 109:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_MAGFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MAGFILTER;
                break;
            case HASH_ELEMENT_MINFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MINFILTER;
                break;
            case HASH_ELEMENT_MIPFILTER:
                elementData.typeID = 388;
                elementData.generatedElementHash = HASH_ELEMENT_MIPFILTER;
                break;
            case HASH_ELEMENT_MIPMAP_BIAS:
                elementData.typeID = 87;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_BIAS;
                break;
            case HASH_ELEMENT_MIPMAP_MAXLEVEL:
                elementData.typeID = 392;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_MAXLEVEL;
                break;
            case HASH_ELEMENT_WRAP_S:
                elementData.typeID = 214;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_S____GLES_SAMPLER_WRAP;
                break;
            case HASH_ELEMENT_WRAP_T:
                elementData.typeID = 214;
                elementData.generatedElementHash = HASH_ELEMENT_WRAP_T____GLES_SAMPLER_WRAP;
                break;
            default:
                return false;
            }
            break;
        case 581:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ARGUMENT:
                elementData.typeID = 558;
                elementData.generatedElementHash = HASH_ELEMENT_ARGUMENT____GLES_TEXCOMBINER_ARGUMENTALPHA_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 220:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ARGUMENT:
                elementData.typeID = 559;
                elementData.generatedElementHash = HASH_ELEMENT_ARGUMENT____GLES_TEXCOMBINER_ARGUMENTRGB_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 131:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_RGB:
                elementData.typeID = 220;
                elementData.generatedElementHash = HASH_ELEMENT_RGB;
                break;
            case HASH_ELEMENT_ALPHA:
                elementData.typeID = 581;
                elementData.generatedElementHash = HASH_ELEMENT_ALPHA____GLES_TEXCOMBINER_COMMANDALPHA_TYPE;
                break;
            case HASH_ELEMENT_CONSTANT:
                elementData.typeID = 164;
                elementData.generatedElementHash = HASH_ELEMENT_CONSTANT____GLES_TEXTURE_CONSTANT_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 491:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_CONSTANT:
                elementData.typeID = 164;
                elementData.generatedElementHash = HASH_ELEMENT_CONSTANT____GLES_TEXTURE_CONSTANT_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 341:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_TEXCOMBINER:
                elementData.typeID = 131;
                elementData.generatedElementHash = HASH_ELEMENT_TEXCOMBINER;
                break;
            case HASH_ELEMENT_TEXENV:
                elementData.typeID = 491;
                elementData.generatedElementHash = HASH_ELEMENT_TEXENV;
                break;
            default:
                return false;
            }
            break;
        case 478:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_SAMPLER_STATE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER_STATE____NCNAME;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____NCNAME;
                break;
            case HASH_ELEMENT_TEXCOORD:
                elementData.typeID = 386;
                elementData.generatedElementHash = HASH_ELEMENT_TEXCOORD;
                break;
            default:
                return false;
            }
            break;
        case 352:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 352;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____GLSL_NEWARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 206;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____GLSL_BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 318;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____GLSL_BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 615;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____GLSL_BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 76;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____GLSL_BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 402;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____GLSL_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 239;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____GLSL_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 325;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____GLSL_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 90;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____GLSL_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 505;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____GLSL_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 247;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____GLSL_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 124;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____GLSL_FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 532;
                elementData.generatedElementHash = HASH_ELEMENT_INT____GLSL_INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 284;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____GLSL_INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 510;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____GLSL_INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 128;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____GLSL_INT4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 361;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____GL_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 51;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____GL_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 380;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____GL_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 381;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____GL_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 269;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____GL_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 104;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____GL_SAMPLERRECT;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 227;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____GLSL_SURFACE_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 557:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 352;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____GLSL_NEWARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 206;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____GLSL_BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 318;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____GLSL_BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 615;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____GLSL_BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 76;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____GLSL_BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 402;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____GLSL_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 239;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____GLSL_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 325;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____GLSL_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 90;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____GLSL_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 505;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____GLSL_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 247;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____GLSL_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 124;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____GLSL_FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 532;
                elementData.generatedElementHash = HASH_ELEMENT_INT____GLSL_INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 284;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____GLSL_INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 510;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____GLSL_INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 128;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____GLSL_INT4;
                break;
            case HASH_ELEMENT_MODIFIER:
                elementData.typeID = 560;
                elementData.generatedElementHash = HASH_ELEMENT_MODIFIER;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 361;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____GL_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 51;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____GL_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 380;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____GL_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 381;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____GL_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 269;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____GL_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 104;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____GL_SAMPLERRECT;
                break;
            case HASH_ELEMENT_SEMANTIC:
                elementData.typeID = 110;
                elementData.generatedElementHash = HASH_ELEMENT_SEMANTIC;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 227;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____GLSL_SURFACE_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 353:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 353;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____GLSL_SETARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 206;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____GLSL_BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 318;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____GLSL_BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 615;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____GLSL_BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 76;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____GLSL_BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 402;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____GLSL_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 239;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____GLSL_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 325;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____GLSL_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 90;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____GLSL_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 505;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____GLSL_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 247;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____GLSL_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 124;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____GLSL_FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 532;
                elementData.generatedElementHash = HASH_ELEMENT_INT____GLSL_INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 284;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____GLSL_INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 510;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____GLSL_INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 128;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____GLSL_INT4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 361;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____GL_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 51;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____GL_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 380;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____GL_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 381;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____GL_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 269;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____GL_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 104;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____GL_SAMPLERRECT;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 227;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____GLSL_SURFACE_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 627:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_ARRAY:
                elementData.typeID = 353;
                elementData.generatedElementHash = HASH_ELEMENT_ARRAY____GLSL_SETARRAY_TYPE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 206;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____GLSL_BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 318;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____GLSL_BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 615;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____GLSL_BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 76;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____GLSL_BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 402;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____GLSL_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 239;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____GLSL_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 325;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____GLSL_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 90;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____GLSL_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 505;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____GLSL_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 247;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____GLSL_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 124;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____GLSL_FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 532;
                elementData.generatedElementHash = HASH_ELEMENT_INT____GLSL_INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 284;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____GLSL_INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 510;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____GLSL_INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 128;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____GLSL_INT4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 361;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____GL_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 51;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____GL_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 380;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____GL_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 381;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____GL_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 269;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____GL_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 104;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____GL_SAMPLERRECT;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 227;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____GLSL_SURFACE_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 628:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_ANNOTATE:
                elementData.typeID = 425;
                elementData.generatedElementHash = HASH_ELEMENT_ANNOTATE;
                break;
            case HASH_ELEMENT_BOOL:
                elementData.typeID = 206;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL____GLSL_BOOL;
                break;
            case HASH_ELEMENT_BOOL2:
                elementData.typeID = 318;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL2____GLSL_BOOL2;
                break;
            case HASH_ELEMENT_BOOL3:
                elementData.typeID = 615;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL3____GLSL_BOOL3;
                break;
            case HASH_ELEMENT_BOOL4:
                elementData.typeID = 76;
                elementData.generatedElementHash = HASH_ELEMENT_BOOL4____GLSL_BOOL4;
                break;
            case HASH_ELEMENT_ENUM:
                elementData.typeID = 263;
                elementData.generatedElementHash = HASH_ELEMENT_ENUM____GL_ENUMERATION;
                break;
            case HASH_ELEMENT_FLOAT:
                elementData.typeID = 402;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT____GLSL_FLOAT;
                break;
            case HASH_ELEMENT_FLOAT2:
                elementData.typeID = 239;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2____GLSL_FLOAT2;
                break;
            case HASH_ELEMENT_FLOAT2X2:
                elementData.typeID = 325;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT2X2____GLSL_FLOAT2X2;
                break;
            case HASH_ELEMENT_FLOAT3:
                elementData.typeID = 90;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3____GLSL_FLOAT3;
                break;
            case HASH_ELEMENT_FLOAT3X3:
                elementData.typeID = 505;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT3X3____GLSL_FLOAT3X3;
                break;
            case HASH_ELEMENT_FLOAT4:
                elementData.typeID = 247;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4____GLSL_FLOAT4;
                break;
            case HASH_ELEMENT_FLOAT4X4:
                elementData.typeID = 124;
                elementData.generatedElementHash = HASH_ELEMENT_FLOAT4X4____GLSL_FLOAT4X4;
                break;
            case HASH_ELEMENT_INT:
                elementData.typeID = 532;
                elementData.generatedElementHash = HASH_ELEMENT_INT____GLSL_INT;
                break;
            case HASH_ELEMENT_INT2:
                elementData.typeID = 284;
                elementData.generatedElementHash = HASH_ELEMENT_INT2____GLSL_INT2;
                break;
            case HASH_ELEMENT_INT3:
                elementData.typeID = 510;
                elementData.generatedElementHash = HASH_ELEMENT_INT3____GLSL_INT3;
                break;
            case HASH_ELEMENT_INT4:
                elementData.typeID = 128;
                elementData.generatedElementHash = HASH_ELEMENT_INT4____GLSL_INT4;
                break;
            case HASH_ELEMENT_SAMPLER1D:
                elementData.typeID = 361;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER1D____GL_SAMPLER1D;
                break;
            case HASH_ELEMENT_SAMPLER2D:
                elementData.typeID = 51;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER2D____GL_SAMPLER2D;
                break;
            case HASH_ELEMENT_SAMPLER3D:
                elementData.typeID = 380;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLER3D____GL_SAMPLER3D;
                break;
            case HASH_ELEMENT_SAMPLERCUBE:
                elementData.typeID = 381;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERCUBE____GL_SAMPLERCUBE;
                break;
            case HASH_ELEMENT_SAMPLERDEPTH:
                elementData.typeID = 269;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERDEPTH____GL_SAMPLERDEPTH;
                break;
            case HASH_ELEMENT_SAMPLERRECT:
                elementData.typeID = 104;
                elementData.generatedElementHash = HASH_ELEMENT_SAMPLERRECT____GL_SAMPLERRECT;
                break;
            case HASH_ELEMENT_SURFACE:
                elementData.typeID = 227;
                elementData.generatedElementHash = HASH_ELEMENT_SURFACE____GLSL_SURFACE_TYPE;
                break;
            default:
                return false;
            }
            break;
        case 227:
            switch ( elementData.elementHash )
            {
            case HASH_ELEMENT_EXTRA:
                elementData.typeID = 4;
                elementData.generatedElementHash = HASH_ELEMENT_EXTRA;
                break;
            case HASH_ELEMENT_FORMAT:
                elementData.typeID = 33;
                elementData.generatedElementHash = HASH_ELEMENT_FORMAT;
                break;
            case HASH_ELEMENT_FORMAT_HINT:
                elementData.typeID = 106;
                elementData.generatedElementHash = HASH_ELEMENT_FORMAT_HINT;
                break;
            case HASH_ELEMENT_GENERATOR:
                elementData.typeID = 161;
                elementData.generatedElementHash = HASH_ELEMENT_GLSL_SURFACE_TYPE____GENERATOR;
                break;
            case HASH_ELEMENT_INIT_AS_NULL:
                elementData.typeID = 78;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_AS_NULL;
                break;
            case HASH_ELEMENT_INIT_AS_TARGET:
                elementData.typeID = 78;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_AS_TARGET;
                break;
            case HASH_ELEMENT_INIT_CUBE:
                elementData.typeID = 599;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_CUBE;
                break;
            case HASH_ELEMENT_INIT_FROM:
                elementData.typeID = 365;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_FROM____FX_SURFACE_INIT_FROM_COMMON;
                break;
            case HASH_ELEMENT_INIT_PLANAR:
                elementData.typeID = 86;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_PLANAR;
                break;
            case HASH_ELEMENT_INIT_VOLUME:
                elementData.typeID = 69;
                elementData.generatedElementHash = HASH_ELEMENT_INIT_VOLUME;
                break;
            case HASH_ELEMENT_MIP_LEVELS:
                elementData.typeID = 396;
                elementData.generatedElementHash = HASH_ELEMENT_MIP_LEVELS;
                break;
            case HASH_ELEMENT_MIPMAP_GENERATE:
                elementData.typeID = 165;
                elementData.generatedElementHash = HASH_ELEMENT_MIPMAP_GENERATE;
                break;
            case HASH_ELEMENT_SIZE:
                elementData.typeID = 405;
                elementData.generatedElementHash = HASH_ELEMENT_SIZE____INT3;
                break;
            case HASH_ELEMENT_VIEWPORT_RATIO:
                elementData.typeID = 46;
                elementData.generatedElementHash = HASH_ELEMENT_VIEWPORT_RATIO;
                break;
            default:
                return false;
            }
            break;
        default:
            return false;
        }
    }

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGen14Private::isXsAnyAllowed( const StringHash& elementHash )
{
    if ( mElementDataStack.empty() )
        return false;

    switch ( elementHash )
    {
        case HASH_ELEMENT_FX_PROFILE_ABSTRACT:
            switch ( mElementDataStack.back().typeID )
            {
            case 52:
                return true;
            default:
                return false;
            }
        case HASH_ELEMENT_GL_HOOK_ABSTRACT:
            switch ( mElementDataStack.back().typeID )
            {
            case 364:
                return true;
            default:
                return false;
            }
        case HASH_ELEMENT_INIT_AS_NULL:
            switch ( mElementDataStack.back().typeID )
            {
            case 226:
                return true;
            default:
                return false;
            }
        case HASH_ELEMENT_INIT_AS_TARGET:
            switch ( mElementDataStack.back().typeID )
            {
            case 226:
                return true;
            default:
                return false;
            }
        case HASH_ELEMENT_TECHNIQUE:
            switch ( mElementDataStack.back().typeID )
            {
            case 36:
                return true;
            case 4:
                return true;
            case 31:
                return true;
            case 591:
                return true;
            case 454:
                return true;
            case 344:
                return true;
            case 150:
                return true;
            case 255:
                return true;
            case 492:
                return true;
            case 37:
                return true;
            case 550:
                return true;
            case 598:
                return true;
            default:
                return false;
            }
    }
    return false;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGen14Private::isDifferentNamespaceAllowed()
{
    if ( mElementDataStack.empty() )
        return true;

    switch ( mElementDataStack.back().typeID )
    {
    // fx_profile_abstract
    case 78:
        return true;
    // technique
    case 525:
        return true;
    }
    return false;
}

} // namespace
