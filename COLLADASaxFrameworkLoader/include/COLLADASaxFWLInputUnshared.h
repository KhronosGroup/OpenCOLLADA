/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_INPUT_UNSHARED_H__
#define __COLLADASAXFWL_INPUT_UNSHARED_H__

#include "COLLADASaxFWLPrerequisites.h"

// TODO
#include "COLLADAFWConstants.h"
#include "COLLADAFWArray.h"

#include "COLLADABUURI.h"


namespace COLLADASaxFWL
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
            LINEAR_STEPS, /** Number of piece-wise linear approximation steps to use for the spline segment that follows this CV. See also �Curve Interpolation� in Chapter 4: Programming Guide. */
            MORPH_TARGET, /** Morph targets for mesh morphing */
            MORPH_WEIGHT, /** Weights for mesh morphing */
            NORMAL, /** Normal vector */
            OUTPUT, /** Sampler output. See also �Curve Interpolation� in Chapter 4: Programming Guide. */
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

		static const size_t BINORMAL_HASH = 238318908;
		static const size_t COLOR_HASH = 4735298;
		static const size_t CONTINUITY_HASH = 149363369;
		static const size_t IMAGE_HASH = 5117365;
		static const size_t INPUT_HASH = 5125540;
		static const size_t IN_TANGENT_HASH = 140926580;
		static const size_t INTERPOLATION_HASH = 238955310;
		static const size_t INV_BIND_MATRIX_HASH = 2112040;
		static const size_t JOINT_HASH = 5193268;
		static const size_t LINEAR_STEPS_HASH = 54960947;
		static const size_t MORPH_TARGET_HASH = 27402052;
		static const size_t MORPH_WEIGHT_HASH = 27111220;
		static const size_t NORMAL_HASH = 87322972;
		static const size_t OUTPUT_HASH = 88774052;
		static const size_t OUT_TANGENT_HASH = 135664756;
		static const size_t POSITION_HASH = 75401582;
		static const size_t TANGENT_HASH = 140687972;
		static const size_t TEXBINORMAL_HASH = 244112700;
		static const size_t TEXCOORD_HASH = 180896228;
		static const size_t TEXTANGENT_HASH = 140981476;
		static const size_t UV_HASH = 1446;
		static const size_t VERTEX_HASH = 95058088;
		static const size_t WEIGHT_HASH = 96066516;
    }

    /** 
     * Declares the input semantics of a data source and connects a consumer to that source.
     * Note: There are two <input> variants; see also "<input> (shared)."
     * The <input> element declares the input connections that a consumer requires. A data source 
     * is a container of raw data that lacks semantic meaning so that the data can be reused within 
     * the document. To use the data, a consumer declares a connection to it with the desired 
     * semantic information.
     * The <source> and <input> elements are part of the COLLADA dataflow model. This model is also
     * known as stream processing, pipe, or producer-consumer. An input connection is the dataflow 
     * path from a <source> to a sink (the dataflow consumers, which are <input>�s parents, such as 
     * <vertices>).
     * In COLLADA, all inputs are driven by index values. A consumer samples an input by supplying 
     * an index value to an input. Some consumers have simple inputs that are driven by unique 
     * index values. These inputs are described in this section as unshared inputs but otherwise 
     * operate in the same manner as shared inputs.
     */
    class InputUnshared
    {

    private:

        /** The user-defined meaning of the input connection. Required. See "Details"
        for the list of common <input> semantic attribute values enumerated in
        the COLLADA schema (type Common_profile_input). */
        InputSemantic::Semantic mSemantic;

        /** The location of the data source. Required. */
        COLLADABU::URI mSource;

    public:

        /**
         * Default-Constructor.
         */
        InputUnshared () : mSemantic ( InputSemantic::UNKNOWN ) {}

        /** 
         * Constructor.
         * @param semantic The semantic of the @a \<input\> element.
         * @param source The source of the @a \<input\> element.
         */
        InputUnshared ( InputSemantic::Semantic semantic, const COLLADABU::URI& source );

		/** 
		* Constructor.
		* @param semantic The semantic of the @a \<input\> element.
		* @param source The source of the @a \<input\> element.
		*/
		InputUnshared ( const String& semantic, const String& source );

        /**
         * Destructor.
         */
        virtual ~InputUnshared() {}

        /** 
         * The user-defined meaning of the input connection. Required. See InputSemantic::Semantic 
         * for the list of common <input> semantic attribute values enumerated in the COLLADA 
         * schema (type Common_profile_input). 
         * @return const InputSemantic::Semantic The user-defined meaning of the input connection.
         */
        const InputSemantic::Semantic& getSemantic () const { return mSemantic; }

        /**
         * The user-defined meaning of the input connection. Required. See InputSemantic::Semantic 
         * for the list of common <input> semantic attribute values enumerated in the COLLADA 
         * schema (type Common_profile_input). 
         * @param val The user-defined meaning of the input connection.
         */
        void setSemantic ( const InputSemantic::Semantic val ) { mSemantic = val; }

        /**
         * The location of the data source. Required.
         * @return const COLLADABU::URI The location of the data source.
         */
        const COLLADABU::URI& getSource () const { return mSource; }

        /**
         * The location of the data source. Required.
         * @param val The location of the data source.
         */
        void setSource ( const COLLADABU::URI val ) { mSource = val; }

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
    typedef COLLADAFW::ArrayPrimitiveType<InputUnshared*> InputUnsharedArray;

}

#endif // __COLLADASAXFWL_INPUT_UNSHARED_H__
