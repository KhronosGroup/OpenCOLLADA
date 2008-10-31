/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INPUT_H__
#define __COLLADAFW_INPUT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWConstants.h"

#include <COLLADASWURI.h>


namespace COLLADAFW
{

    namespace InputSemantic
    {
        /** The geometry source data types. */
        enum Semantic
        {
            BINORMAL=0, /** Geometric binormal (bitangent) vector */
            COLOR, /** Color coordinate vector. Color inputs are RGB (float3) */
            CONTINUITY, /** Continuity constraint at the control vertex (CV). See also "Curve Interpolation" in Chapter 4: Programming Guide. */
            IMAGE, /** Raster or MIP-level input. */
            INPUT, /** Sampler input. See also "Curve Interpolation" in Chapter 4: Programming Guide. */
            IN_TANGENT, /** Tangent vector for preceding control point. See also "Curve Interpolation" in Chapter 4: Programming Guide. */
            INTERPOLATION, /** Sampler interpolation type. See also "Curve Interpolation" in Chapter 4: Programming Guide. */
            INV_BIND_MATRIX, /** Inverse of local-to-world matrix. */
            JOINT, /** Skin influence identifier */
            LINEAR_STEPS, /** Number of piece-wise linear approximation steps to use for the spline segment that follows this CV. See also “Curve Interpolation” in Chapter 4: Programming Guide. */
            MORPH_TARGET, /** Morph targets for mesh morphing */
            MORPH_WEIGHT, /** Weights for mesh morphing */
            NORMAL, /** Normal vector */
            OUTPUT, /** Sampler output. See also “Curve Interpolation” in Chapter 4: Programming Guide. */
            OUT_TANGENT, /** Tangent vector for succeeding control point. See also "Curve Interpolation" in Chapter 4: Programming Guide. */
            POSITION, /** Geometric coordinate vector. See also "Curve Interpolation" in Chapter 4: Programming Guide. */
            TANGENT, /** Geometric tangent vector */
            TEXBINORMAL, /** Texture binormal (bitangent) vector */
            TEXCOORD, /** Texture coordinate vector */
            TEXTANGENT, /** Texture tangent vector */
            UV, /** Generic parameter vector */
            VERTEX, /** Mesh vertex */
            WEIGHT, /** Skin influence weighting value */
            UNKNOWN = -1 /**< An unknown data source. */
        };
    }

    /** A class that holds information about an @a \<input\> element.
    The <input> element declares the input connections to a data source that a consumer requires. A data
    source is a container of raw data that lacks semantic meaning so that the data can be reused within the
    document. To use the data, a consumer declares a connection to it with the desired semantic information.
    The <source> and <input> elements are part of the COLLADA dataflow model. This model is also
    known as stream processing, pipe, or producer-consumer. An input connection is the dataflow path from a
    <source> to a sink (the dataflow consumers, which are <input>’s parents, such as <polylist>).
    In COLLADA, all inputs are driven by index values. A consumer samples an input by supplying an index
    value to an input. Some consumers have multiple inputs that can share the same index values. Inputs that
    have the same offset attribute value are driven by the same index value from the consumer. This is an
    optimization that reduces the total number of indexes that the consumer must store. These inputs are
    described in this section as shared inputs but otherwise operate in the same manner as unshared inputs.*/
    class Input
    {

    private:

        /** The offset into the list of indices defined by the parent element’s <p> or
        <v> subelement. If two <input> elements share the same offset, they are
        indexed the same. This is a simple form of compression for the list of
        indices and also defines the order in which the inputs are used. Required. */
        unsigned int mOffset;

        /** The user-defined meaning of the input connection. Required. See "Details"
        for the list of common <input> semantic attribute values enumerated in
        the COLLADA schema (type Common_profile_input). */
        InputSemantic::Semantic mSemantic;

        /** The location of the data source. Required. */
        COLLADASW::URI mSource;

        /** Which inputs to group as a single set. This is helpful when multiple inputs
        share the same semantics. Optional. */
        int mSet;

    public:

        /**
         * Default-Constructor.
         */
        Input () 
            : mSemantic ( InputSemantic::UNKNOWN )
        , mSource ( "" )
        , mOffset ( 0 )
        , mSet ( 0 ) 
        {}

        /** 
         * Constructor.
         * @param semantic The semantic of the @a \<input\> element.
         * @param source The source of the @a \<input\> element.
         * @param offset The offset of the @a \<input\> element.
         * @param set The set of the @a \<input\> element.
         */
        Input ( InputSemantic::Semantic semantic, const COLLADASW::URI& source, int offset = 0, int set = 0 )
            : mSemantic ( semantic )
            , mSource ( source )
            , mOffset ( offset )
            , mSet ( set ) 
        {}

        virtual ~Input() {}

        /** The offset into the list of indices defined by the parent element’s <p> or
        <v> subelement. If two <input> elements share the same offset, they are
        indexed the same. This is a simple form of compression for the list of
        indices and also defines the order in which the inputs are used. Required. */
        const unsigned int getOffset () const { return mOffset; }
        void setOffset ( const unsigned int val ) { mOffset = val; }

        /** The user-defined meaning of the input connection. Required. See "Details"
        for the list of common <input> semantic attribute values enumerated in
        the COLLADA schema (type Common_profile_input). */
        const InputSemantic::Semantic getSemantic () const { return mSemantic; }
        void setSemantic ( const InputSemantic::Semantic val ) { mSemantic = val; }

        /** The location of the data source. Required. */
        const COLLADASW::URI getSource () const { return mSource; }
        void setSource ( const COLLADASW::URI val ) { mSource = val; }

        /** Which inputs to group as a single set. This is helpful when multiple inputs
        share the same semantics. Optional. */
        const int getSet () const { return mSet; }
        void setSet ( const int val ) { mSet = val; }

        /**
         * Returns the string of the current semantic type.
         * @param semantic The input semantic as semantic type.
         * @return const String& The input semantic as string.
         */
        static const String& getSemanticAsString ( const InputSemantic::Semantic semantic );

        /**
        * Returns the string of the current semantic type.
        * @param semanticStr The input semantic as semantic string.
        * @return const String& The input semantic as semantic type.
        */
        static const InputSemantic::Semantic getSemanticFromString ( const String& semanticStr );

    };

    /** Pointer to an array of input elements. */
    typedef Input* InputArray;

}

#endif // __COLLADAFW_INPUT_H__