/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_OPEN_GL_CONSTANTS_H__
#define __COLLADASTREAMWRITER_OPEN_GL_CONSTANTS_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWSampler.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    namespace OPEN_GL
    {
        //-------------------------------
        /** 
        Contains the texture wrap modes.
        Wrap modes that affect the interpretation of s, t, and p texture 
        coordinates in <sampler_*> elements. The wrap mode enums map to the 
        following OpenGL symbols.
        */
        static const String WrapModesOpenGL[] =
        {
            "Repeat", 
            "Clamp",
            "ClampToEdge",
            "ClampToBorder",
            "MirroredRepeat",
            "MirrorClamp",
            "MirrorClampToEdge",
            "MirrorClampToBorder"
        };

        //-------------------------------
        static const Sampler::WrapMode getWrapModeFromOpenGL ( const String& wrapModeOpenGL )
        {
            // "Repeat"
            if ( COLLADASW::Utils::equals ( wrapModeOpenGL, WrapModesOpenGL[0] ) )
                return Sampler::WRAP_MODE_WRAP;

            // "Clamp"
            else if ( COLLADASW::Utils::equals ( wrapModeOpenGL, WrapModesOpenGL[1] ) )
                return Sampler::WRAP_MODE_CLAMP;

            // "ClampToEdge"
            else if ( COLLADASW::Utils::equals ( wrapModeOpenGL, WrapModesOpenGL[2] ) )
                return Sampler::WRAP_MODE_CLAMP;

            // "ClampToBorder"
            else if ( COLLADASW::Utils::equals ( wrapModeOpenGL, WrapModesOpenGL[3] ) )
                return Sampler::WRAP_MODE_BORDER;

            // "MirroredRepeat"
            else if ( COLLADASW::Utils::equals ( wrapModeOpenGL, WrapModesOpenGL[4] ) )
                return Sampler::WRAP_MODE_CLAMP;

            // "MirrorClamp"
            else if ( COLLADASW::Utils::equals ( wrapModeOpenGL, WrapModesOpenGL[5] ) )
                return Sampler::WRAP_MODE_MIRROR;

            // "MirrorClampToEdge"
            else if ( COLLADASW::Utils::equals ( wrapModeOpenGL, WrapModesOpenGL[6] ) )
                return Sampler::WRAP_MODE_MIRROR;

            // "MirrorClampToBorder"
            else if ( COLLADASW::Utils::equals ( wrapModeOpenGL, WrapModesOpenGL[7] ) )
                return Sampler::WRAP_MODE_MIRROR;

            else return Sampler::WRAP_MODE_UNSPECIFIED;
        }

        //-------------------------------
        static const String FilterOpenGL[] = 
        {
            "none",
            "nearest",
            "linear",
            "nearestmipmapnearest",
            "linearmipmapnearest",
            "nearestmipmaplinear", 
            "linearmipmaplinear"
        };

        //-------------------------------
        static const Sampler::SamplerFilter getSamplerFilterFromOpenGL ( const String& samplerFilter )
        {
            // "none"
            if ( COLLADASW::Utils::equals ( samplerFilter, FilterOpenGL[0] ) )
                return Sampler::SAMPLER_FILTER_NONE;

            // "nearest"
            else if ( COLLADASW::Utils::equals ( samplerFilter, FilterOpenGL[1] ) )
                return Sampler::SAMPLER_FILTER_NEAREST;

            // "linear"
            else if ( COLLADASW::Utils::equals ( samplerFilter, FilterOpenGL[2] ) )
                return Sampler::SAMPLER_FILTER_LINEAR;

            // "nearestmipmapnearest"
            else if ( COLLADASW::Utils::equals ( samplerFilter, FilterOpenGL[3] ) )
                return Sampler::SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST;

            // "linearmipmapnearest"
            else if ( COLLADASW::Utils::equals ( samplerFilter, FilterOpenGL[4] ) )
                return Sampler::SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST;

            // "nearestmipmaplinear"
            else if ( COLLADASW::Utils::equals ( samplerFilter, FilterOpenGL[5] ) )
                return Sampler::SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR;

            // "linearmipmaplinear"
            else if ( COLLADASW::Utils::equals ( samplerFilter, FilterOpenGL[6] ) )
                return Sampler::SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR;

            else return Sampler::SAMPLER_FILTER_UNSPECIFIED;
        }

    }

}

#endif // __COLLADASTREAMWRITER_OPEN_GL_CONSTANTS_H__