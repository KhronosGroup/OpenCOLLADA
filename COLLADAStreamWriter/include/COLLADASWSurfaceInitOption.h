/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_SURFACE_INIT_OPTION_H__
#define __COLLADASTREAMWRITER_SURFACE_INIT_OPTION_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"

namespace COLLADASW
{

    /** The optional initialization option specifies whether to initialize 
    the surface and how to do so. Although the initialization option is 
    optional in the schema, all surfaces should have one such element. */
    class SurfaceInitOption  
    {

    public:

        /** An uninitialized surface should include the <init_as_null> element, 
        while the <init_as_target> element indicates that that images will be 
        rendered or copied into later by an effect or some other system.
        The <init_cube>, <init_volume>, and <init_planar> elements enable the 
        initialization of surface types with compound images such as DDS, 
        animated GIF, or openEXR. In COLLADASW, all 3D images are considered to 
        be compound images, because the schema considers them to be an array 
        of slices. Also in COLLADASW, 1D images are also planar images, with y 
        value of 1. For other images, <init_from> can be used.
        To maximize compatibility with more applications, it is suggested, 
        that developers support a single <init_from> with a DDS file as a 
        complete initialization of the surface, because it could include the
        MIPmapping information.
        The option can be any one of the following elements: */
        enum InitType
        {
            INIT_AS_NULL,
            INIT_AS_TARGET,
            INIT_CUBE,
            INIT_VOLUME,
            INIT_PLANAR,
            INIT_FROM, 
            UNINITIALIZED_INIT_TYPE
        };

        /** Specifies which surface of a cube to initialize from the specified image. */
        enum Face
        {
            POSITIVE_X,
            NEGATIVE_X,
            POSITIVE_Y, 
            NEGATIVE_Y, 
            POSITIVE_Z, 
            NEGATIVE_Z
        };

    private:

        /** The init type. */
        InitType mType;

        /** A reference of the init option <init_cube>. 
        Initializes the surface with one compound image such as DDS.
        This element contains no data; the ref attribute, referencing an image, 
        is required. */
        String mAllRef;

        /** A reference of the init option <init_cube>. 
        <primary>: Initializes all primary MIP level 0 subsurfaces with one
        compound image such as DDS. Its ref attribute, referencing an image, is
        required. Use of this element expects the surface to have element
        <mip_levels>=0 or <mipmap_generate>.
        Its subelement <order> occurs 0 or 6 times and has no attributes.
        Image formats that natively describe the face ordering, such as DDS, do
        not need this element. For other images, such as animated GIFs, this
        series of ordered elements describes which face the index belongs to.
        Each <order> contains one of the enumerated values of type
        fx_surface_face_enum.*/
        String mPrimaryRef;
        std::vector<Face> mPrimaryOrders;

        /** A reference of the init option <init_cube>. 
        </primary><face>: Occurs 6 times. Initializes each face MIP chain
        with one compound image such as DDS. This element contains no data;
        the ref attribute, referencing an image, is required. */
        std::vector<String> mFaceRefs;

        /** An xs:unsignedInt that specifies the MIP level. The default is 0. */
        unsigned int mMipLevel;

        /** An xs:unsignedInt that specifies which 2D layer within a
        volume to initialize. There are anywhere from 0 to n slices in a volume,
        where n is the volume�s depth slice. This attribute is used in combination
        with mip because a volume might have MIPmaps The default is 0. */
        unsigned int mSlice;

        /** An enumerated value of type fx_surface_face_enum that
        specifies which surface of a cube to initialize from the specified image.
        This attribute is used in combination with mip because a cubemap might
        have MIPmaps. The default is POSITIVE_X. */
        Face mFace;

        /** Contains a reference to a 1D or 2D image. */
        String mImageReference;

    public:

        /** Default-Constructor. */
        SurfaceInitOption () 
        : mType ( UNINITIALIZED_INIT_TYPE ) 
        , mAllRef ( "" )
        , mPrimaryRef ( "" )
        , mMipLevel ( 0 )
        , mSlice ( 0 )
        , mFace ( POSITIVE_X )
        {}

        /** Constructor. */
        SurfaceInitOption ( InitType type ) 
            : mType ( type ) 
            , mAllRef ( "" )
            , mPrimaryRef ( "" )
            , mMipLevel ( 0 )
            , mSlice ( 0 )
            , mFace ( POSITIVE_X )
        {}

        /** Destructor. */
        virtual ~SurfaceInitOption() {}

        /** Adds the init option of the current type to the collada document. */
        void add ( StreamWriter* sw ) const;

        /** Adds a primary order to the list. Must always zero or six orders! */
        void addPrimaryOrder ( Face primaryOrder ) { mPrimaryOrders.push_back ( primaryOrder ); }
        const std::vector<Face>& getPrimaryOrders () const { return mPrimaryOrders; }

        /** The init type. */
        const SurfaceInitOption::InitType& getType () const { return mType; }
        void setType ( const SurfaceInitOption::InitType& val ) { mType = val; }

        /** A reference of the init option <init_cube>. 
        Initializes the surface with one compound image such as DDS.
        This element contains no data; the ref attribute, referencing an image, 
        is required. */
        const String& getAllRef () const { return mAllRef; }
        void setAllRef ( const String& val ) { mAllRef = val; }

        /** A reference of the init option <init_cube>. 
        <primary>: Initializes all primary MIP level 0 subsurfaces with one
        compound image such as DDS. Its ref attribute, referencing an image, is
        required. Use of this element expects the surface to have element
        <mip_levels>=0 or <mipmap_generate>.
        Its subelement <order> occurs 0 or 6 times and has no attributes.
        Image formats that natively describe the face ordering, such as DDS, do
        not need this element. For other images, such as animated GIFs, this
        series of ordered elements describes which face the index belongs to.
        Each <order> contains one of the enumerated values of type
        fx_surface_face_enum.*/
        const String& getPrimaryRef () const { return mPrimaryRef; }
        void setPrimaryRef ( const String& val ) { mPrimaryRef = val; }

        /** A reference of the init option <init_cube>. 
        </primary><face>: Occurs 6 times. Initializes each face MIP chain
        with one compound image such as DDS. This element contains no data;
        the ref attribute, referencing an image, is required. */
        const std::vector<String>& getFaceRefs () const { return mFaceRefs; }
        void setFaceRefs ( const std::vector<String>& val ) { mFaceRefs = val; }

        /** An xs:unsignedInt that specifies the MIP level. The default is 0. */
        const unsigned int getMipLevel () const { return mMipLevel; }
        void setMipLevel ( const unsigned int val ) { mMipLevel = val; }

        /** An xs:unsignedInt that specifies which 2D layer within a
        volume to initialize. There are anywhere from 0 to n slices in a volume,
        where n is the volume�s depth slice. This attribute is used in combination
        with mip because a volume might have MIPmaps The default is 0. */
        const unsigned int getSlice () const { return mSlice; }
        void setSlice ( const unsigned int val ) { mSlice = val; }

        /** An enumerated value of type fx_surface_face_enum that
        specifies which surface of a cube to initialize from the specified image.
        This attribute is used in combination with mip because a cubemap might
        have MIPmaps. The default is POSITIVE_X. */
        const SurfaceInitOption::Face& getFace () const { return mFace; }
        void setFace ( const SurfaceInitOption::Face& val ) { mFace = val; }

        /** Contains a reference to a 1D or 2D image. */
        const String& getImageReference () const { return mImageReference; }

        /** Contains a reference to a 1D or 2D image. */
        void setImageReference ( const String& val ) { mImageReference = val; }

        /** Returns a reference to the COLLADASW name of the face. */
        static const String& getFaceString ( const Face& face );


    private:

        /** This surface is intended to be initialized later externally by a <setparam> element.
        If it is used before being initialized, there is profile- and platform-specific behavior.
        Most elements on the <surface> element that contains this will be ignored,
        including <mip_levels>, <mipmap_generate>, <size>,
        <viewport_ratio>, and <format>. This element has no attributes and
        contains no data. */
        void addInitAsNull ( StreamWriter* sw ) const;

        /** Contains a reference to a 1D or 2D image. Initializes the surface one subsurface at
        a time by specifying combinations of mip, face, and slice that make sense for a
        particular surface type. Each subsurface is initialized by a common 1-D or 2-D
        image, not a complex compound image such as DDS. If not all subsurfaces are
        initialized, the surface is invalid and will result in profile- and platform-specific
        behavior unless <mipmap_generate> is responsible for initializing the remaining
        subsurfaces.
        All attributes are optional:
        � mip: An xs:unsignedInt that specifies the MIP level. The default is 0.
        � slice: An xs:unsignedInt that specifies which 2D layer within a
        volume to initialize. There are anywhere from 0 to n slices in a volume,
        where n is the volume�s depth slice. This attribute is used in combination
        with mip because a volume might have MIPmaps The default is 0.
        � face: An enumerated value of type fx_surface_face_enum that
        specifies which surface of a cube to initialize from the specified image.
        This attribute is used in combination with mip because a cubemap might
        have MIPmaps. The default is POSITIVE_X. */
        void addInitFrom ( StreamWriter* sw ) const;

        /** Initializes this surface with a 1D, 2D, RECT, or DEPTH from a compound image
        such as DDS.
        Must include:
        � <all>: Initializes the surface with one compound image such as DDS.
        This element contains no data; the ref attribute, referencing an image, is
        required. */
        void addInitPlanar ( StreamWriter* sw ) const;

        /** Initializes this surface with a 3D from a compound image such as DDS.
        Choose one of the following; for both, the ref attribute, referencing an image, is
        required:
        � <all>: Initializes the surface with one compound image such as DDS.
        � <primary>: Initializes MIP level 0 of the surface with one compound
        image such as DDS. Use of this element expects the surface to have
        element <mip_levels>=0 or <mipmap_generate>. */
        void addInitVolume ( StreamWriter* sw ) const;

        /** Initializes the entire surface with a CUBE from a compound image such as DDS.
        Contains one of:
        � <all>: Initializes the surface with one compound image such as DDS.
        This element contains no data; the ref attribute, referencing an image, is
        required.
        � <primary>: Initializes all primary MIP level 0 subsurfaces with one
        compound image such as DDS. Its ref attribute, referencing an image, is
        required. Use of this element expects the surface to have element
        <mip_levels>=0 or <mipmap_generate>.
        Its subelement <order> occurs 0 or 6 times and has no attributes.
        Image formats that natively describe the face ordering, such as DDS, do
        not need this element. For other images, such as animated GIFs, this
        series of ordered elements describes which face the index belongs to.
        Each <order> contains one of the enumerated values of type
        fx_surface_face_enum. For example:
        <primary ="file:///c:/foo.gif">
        <order>POSITIVE_X</order>
        <order>POSITIVE_Y</order>
        <order>POSITIVE_Z</order>
        <order>NEGATIVE_X</order>
        <order>NEGATIVE_Y</order>
        <order>NEGATIVE_Z</order>
        � </primary><face>: Occurs 6 times. Initializes each face MIP chain
        with one compound image such as DDS. This element contains no data;
        the ref attribute, referencing an image, is required. */
        void addInitCube ( StreamWriter* sw ) const;

        /** Initializes this surface as a target for depth, stencil, or color. It does not need image
        data. If this element is used, <mipmap_generate> is ignored. This element has
        no attributes and contains no data. */
        void addInitAsTarget ( StreamWriter* sw ) const;

    };

}

#endif // __COLLADASTREAMWRITER_SURFACE_INIT_OPTION_H__
