/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INPUT_LIST_H__
#define __COLLADASTREAMWRITER_INPUT_LIST_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWBaseElement.h"
#include "COLLADASWConstants.h"

#include "COLLADABUURI.h"

namespace COLLADASW
{

    class InputList;
    class PrimitivesBase;
    class BaseInputElement;
    class Vertices;
	class ControlVertices;

	namespace InputSemantic
	{
		/** The geometry source data types. */
		enum Semantics
		{
			BINORMAL=0, /** Geometric binormal (bitangent) vector */
			BINDMATRIX, 
			COLOR, /** Color coordinate vector. Color inputs are RGB (float3) */
			CONTINUITY, /** Continuity constraint at the control vertex (CV). See also "Curve Interpolation" in Chapter 4: Programming Guide. */
			IMAGE, /** Raster or MIP-level input. */
			INPUT, /** Sampler input. See also "Curve Interpolation" in Chapter 4: Programming Guide. */
			IN_TANGENT, /** Tangent vector for preceding control point. See also "Curve Interpolation" in Chapter 4: Programming Guide. */
			INTERPOLATION, /** Sampler interpolation type. See also "Curve Interpolation" in Chapter 4: Programming Guide. */
			INV_BIND_MATRIX, /** Inverse of local-to-world matrix. */
			JOINT, /** Skin influence identifier */
			LINEAR_STEPS, /** Number of piece-wise linear approximation steps to use for the spline segment that follows this CV. See also Curve Interpolation in Chapter 4: Programming Guide. */
			MORPH_TARGET, /** Morph targets for mesh morphing */
			MORPH_WEIGHT, /** Weights for mesh morphing */
			NORMAL, /** Normal vector */
			OUTPUT, /** Sampler output. See also Curve Interpolation in Chapter 4: Programming Guide. */
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


    /** A class that holds information about an @a \<input\> element.*/
    class Input
    {

    public:
        /** Constructor
        @param semantic The semantic of the @a \<input\> element.
        @param source The source of the @a \<input\> element.
        @param offset The offset of the @a \<input\> element.
        @param set The set of the @a \<input\> element.
        */
		Input ( InputSemantic::Semantics semantic, const URI& source, int offset = -1, int set = -1 )
                : mSemantic ( semantic ),
                mSource ( source ),
                mOffset ( offset ),
                mSet ( set ) {}

        virtual ~Input() {}

        /** Returns the semantic of the Input*/
        InputSemantic::Semantics getSemantic() const
        {
            return mSemantic;
        }

        /** Returns the source of the Input*/
        const COLLADABU::URI& getSource() const
        {
            return mSource;
        }

        /** Returns the offset of the Input*/
        int getOffset() const
        {
            return mOffset;
        }

        /** Returns the set of the Input*/
        int getSet() const
        {
            return mSet;
        }

    private:
        InputSemantic::Semantics mSemantic;
        COLLADABU::URI mSource;
        int mOffset;
        int mSet;
    };


    /** A class that writes a list of Input objects to the stream.*/
    class InputList : public ElementWriter
    {

    private:

        /** Declare friend, so the class can use the 'add()' method. */
        friend class PrimitivesBase;

        /** Declare friend, so the class can use the 'add()' method. */
        friend class BaseInputElement;

		/** Declare friend, so the class can use the 'add()' method. */
		friend class Vertices;

		/** Declare friend, so the class can use the 'add()' method. */
		friend class ControlVertices;

		friend class LibraryAnimations;

        /** List of all the inputs*/
        typedef std::list<Input> List;
        List mList;

    public:

        /** Constructor
        @param The stream the InputList should be written to*/
        InputList ( StreamWriter* streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Destructor*/
        virtual ~InputList() {}

        /** Adds @a input to list of inputs that should be added*/
        void push_back ( Input input )
        {
            mList.push_back ( input );
        }

		/** Returns a string containing the semantic name*/
		static const String& getSemanticString ( InputSemantic::Semantics semantic );

	private:

        /** Add all the inputs, added using push_back(), to the stream*/
        void add()const;


    };


} //namespace COLLADASW



#endif //__COLLADASTREAMWRITER_INPUT_LIST_H__
