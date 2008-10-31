/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_SURFACE_H__
#define __COLLADASTREAMWRITER_SURFACE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWSurfaceInitOption.h"
#include "COLLADASWFormatHint.h"

namespace COLLADASW
{

    /** Declares a resource that can be used both as the source for texture 
    samples and as the target of a rendering pass. 
    <surface> is an abstract generalization of <image> for GPU rendering that 
    can link multiple <image> resources into a single object. For example, the 
    object could be a MIP-mapped image with n prefiltered levels, or a cube 
    map formed by joining six square textures.
    <surface> objects:
    • Have a data format describing the size and layout of fields in each pixel.
    • Can be sized either in absolute numbers of pixels using <size> or as some 
    fractional size of the viewport using <viewport_ratio>.
    • Can declare a fixed number of MIP-map levels using <mip_levels>.
    <surface> objects can be initialized from a set of preexisting <image> 
    objects by providing an ordered list of their IDs to <init_from>. 
    <surface> objects can also be initialized programmatically by
    evaluating source code over each pixel in the surface, using the <generator> 
    element. */
    class Surface : public BaseExtraTechnique
    {

    public:

        static const String SURFACE_SID_SUFFIX;

    public:

        /** The type of this surface. Must be one of UNTYPED, 1D, 2D, 3D, CUBE,
        DEPTH, RECT. Required in the COMMON, GLES, and GLSL scope;
        not valid in the CG scope (or in <texture_unit> within GLES). */
        enum SurfaceType
        {
            SURFACE_TYPE_UNSPECIFIED,
            SURFACE_TYPE_NONE,
            /**< When a surface's type attribute is set to UNTYPED, its type is initially
            unknown and established later by the context in which it is used, such as by a
            texture sampler that references it. A surface of any other type may be changed
            into an UNTYPED surface at run-time, as if it were created by \<newparam\>, using
            \<setparam\>. If there is a type mismatch between a \<setparam\> operation and what
            the run-time decides the type should be, the result is profile- and
            platform-specific behavior. */
            SURFACE_TYPE_UNTYPED,
            SURFACE_TYPE_1D,
            SURFACE_TYPE_2D,
            SURFACE_TYPE_3D,
            SURFACE_TYPE_RECT,
            SURFACE_TYPE_CUBE,
            SURFACE_TYPE_DEPTH
        };

        /** Dimension of the surface (scale or viewport ratio). */ 
        struct DimensionRatio
        {
        public:
            int width, height;
            DimensionRatio () : width ( 1 ), height ( 1 ) {}
        };

        /** Dimension of the surface (scale or viewport ratio). */ 
        class DimensionScale
        {
        public:
            float width, height, depth;
            DimensionScale () : width ( 0 ), height ( 0 ), depth ( 0 ) {}
        };

    private:

        /** The sid of the surface. */
        String mSid;

        /** The type of the surface. */
        SurfaceType mType;

        /** The init option of the surface. */
        SurfaceInitOption mInitOption;

        /** The format of the current surface. 
        Contains a string representing the texel format for this
        surface. If this element is not specified or understood by
        the application, then the application will attempt to use
        <format_hint> if it is provided; otherwise, it should
        use a common format linear R8G8B8A8. */
        String mFormat;

        /** An application uses <format_hint> if <format> does
        not exist or is not understood by the application and
        <format_hint> exists. This element describes the
        important features intended by the author so that the
        application can pick a format that best represents what
        the author wanted. */
        FormatHint mFormatHint;

        /** Contains three integer values. If specified, the surface is
        sized to these exact dimensions in texels. Surfaces of
        type 1D and CUBE use only the first value. Surfaces of
        type 2D and RECT use only the first two values,
        representing width and then height. Type 3D uses all
        three values, representing width, height, and depth.
        Invalid if <viewport_ratio> is used. */
        DimensionScale mSize; 

        /** Contains two floating-point values representing width and
        then height. If specified, the surface is sized to a
        dimension based on these ratios of the viewport’s
        (backbuffer’s) dimensions. For example, the following
        scales the surface’s width to half the viewport’s width
        and its height to twice the viewport’s height:
        <viewport_ratio>0.5 2</viewport_ratio>
        This element is valid only for surfaces of type 2D or RECT.
        Invalid if <size> is used. */
        DimensionRatio mViewportRatio;

        /** Contains the number of MIP levels in the surface. A value
        of 0 assumes that all MIP levels exist until a dimension
        becomes 1 texel. To create a surface that has only one
        level of MIP maps (mip=0), set this to 1. */
        unsigned int mMipLevels;

        /** Contains a Boolean. If false and not all subsurfaces are
        initialized because you have not provided MIP-map
        levels, the generated surface will have profile- and
        platform-specific behavior. If true, the application is
        responsible for initializing the remainder of the
        subsurfaces; this is typically done through a graphics API
        render state or function that does this automatically, such
        as glGenerateMipmap(). */
        bool mMipmapGenerate;

        /** Valid in CG, GLES, and GLSL scopes. Specifies a
        procedural surface generator. */
//        Generator mGenerator;

    public:

        /**Constructor that sets all required attributes and the default values for optional attributes.*/
        Surface ( Surface::SurfaceType surfaceType, const String &sid="" );

        /**Constructor that creates an invalid surface.*/
        Surface();

        /** Destructor */
        ~Surface() {};

        /** Returns the sid of the surface used by this texture*/
        void setSurfaceSid ( String sid ) 
        {
            mSid = sid;
        }

        /** Returns the sid of the surface used by this texture*/
        String getSurfaceSid() const
        {
            return mSid;
        }

        /** Set the type of the current surface. */
        void setSurfaceType ( SurfaceType surfaceType )
        {
            mType = surfaceType;
        }

        /** Returns the type of the current surface. */
        const SurfaceType getSurfaceType () const
        {
            return mType;
        }

        /** Returns a reference to the COLLADASW name of the surface type*/
        static const String& getSurfaceTypeString ( SurfaceType surfaceType );

        /** Write the <surface> element to the collada stream. */
        void add ( StreamWriter* sw ) const;

        /** The init option of the surface. */
        const SurfaceInitOption& getInitOption () const { return mInitOption; }

        /** The init option of the surface. */
        void setInitOption ( const SurfaceInitOption& val ) { mInitOption = val; }

        /** The format of the current surface. 
        Contains a string representing the texel format for this
        surface. If this element is not specified or understood by
        the application, then the application will attempt to use
        <format_hint> if it is provided; otherwise, it should
        use a common format linear R8G8B8A8. */
        const String& getFormat () const { return mFormat; }

        /** The format of the current surface. 
        Contains a string representing the texel format for this
        surface. If this element is not specified or understood by
        the application, then the application will attempt to use
        <format_hint> if it is provided; otherwise, it should
        use a common format linear R8G8B8A8. */
        void setFormat ( const String& val ) { mFormat = val; }

        /** An application uses <format_hint> if <format> does
        not exist or is not understood by the application and
        <format_hint> exists. This element describes the
        important features intended by the author so that the
        application can pick a format that best represents what
        the author wanted. */
        const FormatHint& getFormatHint () const { return mFormatHint; }

        /** An application uses <format_hint> if <format> does
        not exist or is not understood by the application and
        <format_hint> exists. This element describes the
        important features intended by the author so that the
        application can pick a format that best represents what
        the author wanted. */
        void setFormatHint ( const FormatHint& val ) { mFormatHint = val; }

        /** Contains three integer values. If specified, the surface is
        sized to these exact dimensions in texels. Surfaces of
        type 1D and CUBE use only the first value. Surfaces of
        type 2D and RECT use only the first two values,
        representing width and then height. Type 3D uses all
        three values, representing width, height, and depth.
        Invalid if <viewport_ratio> is used. */
        const DimensionScale& getSize () const { return mSize; }

        /** Contains three integer values. If specified, the surface is
        sized to these exact dimensions in texels. Surfaces of
        type 1D and CUBE use only the first value. Surfaces of
        type 2D and RECT use only the first two values,
        representing width and then height. Type 3D uses all
        three values, representing width, height, and depth.
        Invalid if <viewport_ratio> is used. */
        void setSize ( const DimensionScale& val ) { mSize = val; }

        /** Contains two floating-point values representing width and
        then height. If specified, the surface is sized to a
        dimension based on these ratios of the viewport’s
        (backbuffer’s) dimensions. For example, the following
        scales the surface’s width to half the viewport’s width
        and its height to twice the viewport’s height:
        <viewport_ratio>0.5 2</viewport_ratio>
        This element is valid only for surfaces of type 2D or RECT.
        Invalid if <size> is used. */
        const DimensionRatio& getViewportRatio () const { return mViewportRatio; }

        /** Contains two floating-point values representing width and
        then height. If specified, the surface is sized to a
        dimension based on these ratios of the viewport’s
        (backbuffer’s) dimensions. For example, the following
        scales the surface’s width to half the viewport’s width
        and its height to twice the viewport’s height:
        <viewport_ratio>0.5 2</viewport_ratio>
        This element is valid only for surfaces of type 2D or RECT.
        Invalid if <size> is used. */
        void setViewportRatio ( const DimensionRatio& val ) { mViewportRatio = val; }

        /** Contains the number of MIP levels in the surface. A value
        of 0 assumes that all MIP levels exist until a dimension
        becomes 1 texel. To create a surface that has only one
        level of MIP maps (mip=0), set this to 1. */
        const unsigned int getMipLevels () const { return mMipLevels; }

        /** Contains the number of MIP levels in the surface. A value
        of 0 assumes that all MIP levels exist until a dimension
        becomes 1 texel. To create a surface that has only one
        level of MIP maps (mip=0), set this to 1. */
        void setMipLevels ( const unsigned int val ) { mMipLevels = val; }

        /** Contains a Boolean. If false and not all subsurfaces are
        initialized because you have not provided MIP-map
        levels, the generated surface will have profile- and
        platform-specific behavior. If true, the application is
        responsible for initializing the remainder of the
        subsurfaces; this is typically done through a graphics API
        render state or function that does this automatically, such
        as glGenerateMipmap(). */
        const bool getMipmapGenerate () const { return mMipmapGenerate; }

        /** Contains a Boolean. If false and not all subsurfaces are
        initialized because you have not provided MIP-map
        levels, the generated surface will have profile- and
        platform-specific behavior. If true, the application is
        responsible for initializing the remainder of the
        subsurfaces; this is typically done through a graphics API
        render state or function that does this automatically, such
        as glGenerateMipmap(). */
        void setMipmapGenerate ( const bool val ) { mMipmapGenerate = val; }

    };
}

#endif // __COLLADASTREAMWRITER_SURFACE_H__