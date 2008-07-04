/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryAnimations.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    const String LibraryAnimations::LINEAR_NAME = "LINEAR";
    const String LibraryAnimations::BEZIER_NAME = "BEZIER";
    const String LibraryAnimations::CARDINAL_NAME = "CARDINAL";
    const String LibraryAnimations::HERMITE_NAME = "HERMITE";
    const String LibraryAnimations::BSPLINE_NAME = "BSPLINE";
    const String LibraryAnimations::TCB_NAME = "TCB";
    const String LibraryAnimations::STEP_NAME = "STEP";


    const String LibraryAnimations::INPUT_SOURCE_ID_SUFFIX = "-input";
    const String LibraryAnimations::OUTPUT_SOURCE_ID_SUFFIX = "-output";
    const String LibraryAnimations::INTANGENT_SOURCE_ID_SUFFIX = "-intangent";
    const String LibraryAnimations::OUTTANGENT_SOURCE_ID_SUFFIX = "-outtangent";
    const String LibraryAnimations::INTERPOLATION_SOURCE_ID_SUFFIX = "-interpolation";
    const String LibraryAnimations::TCBS_SOURCE_ID_SUFFIX = "-tcbs";
    const String LibraryAnimations::EASES_SOURCE_ID_SUFFIX = "-eases";
    const String LibraryAnimations::ARRAY_ID_SUFFIX = "-array";

    const String LibraryAnimations::SAMPLER_ID_SUFFIX = "-sampler";


    //---------------------------------------------------------------
    void Animation::openAnimation ( const String & id, const String & name )
    {
        // Open a <animation> element
        mAnimationCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_ANIMATION );

        // Write the id and the name, if they are set.

        if ( !id.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, id );

        if ( !name.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, name );
    }


    //---------------------------------------------------------------
    void Animation::closeAnimation()
    {
        mAnimationCloser.close();
    }

    //---------------------------------------------------------------
    LibraryAnimations::LibraryAnimations ( COLLADA::StreamWriter * streamWriter )
            : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_ANIMATIONS ), mOpenAnimations ( NULL )
    {}

    //---------------------------------------------------------------
    void LibraryAnimations::openAnimation ( const String & id, const String & name )
    {
        // Open the tag <library_animations> if it is not already open
        openLibrary();

        Animation* animation = new Animation ( mSW );
        animation->openAnimation ( id, name );

        mOpenAnimations.push_back ( animation );
    }

    //---------------------------------------------------------------
    void LibraryAnimations::closeAnimation()
    {
        Animation* animation = mOpenAnimations.back();
        animation->closeAnimation();
        delete animation;

        // Erases the animation element from the list.
        mOpenAnimations.pop_back();
    }

    //---------------------------------------------------------------
    const String & LibraryAnimations::getNameOfInterpolation ( const InterpolationType & type )
    {
        switch ( type )
        {

        case LINEAR:
            return LINEAR_NAME;

        case BEZIER:
            return BEZIER_NAME;

        case CARDINAL:
            return CARDINAL_NAME;

        case HERMITE:
            return HERMITE_NAME;

        case BSPLINE:
            return BSPLINE_NAME;

        case STEP:
            return STEP_NAME;

        default:
            return EMPTY_STRING;
        }
    }

    //---------------------------------------------------------------
    void LibraryAnimations::addSampler ( const Sampler & sampler )
    {

        mSW->openElement ( CSWC::COLLADA_ELEMENT_SAMPLER );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, sampler.getId() );

        const LibraryAnimations::Sampler::InputList & inputList = sampler.getInputList();

        for ( LibraryAnimations::Sampler::InputList::const_iterator it = inputList.begin(); it<inputList.end(); ++it )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_INPUT );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SEMANTIC, Sampler::getElementNameBySemantic ( it->semantic ) );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, it->source );
            mSW->closeElement();
        }

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void LibraryAnimations::addChannel ( const String & source, const String & target )
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_CHANNEL );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, source );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TARGET, target );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void LibraryAnimations::Sampler::addInput ( Semantic semantic, const String & source )
    {
        Input input;
        input.semantic = semantic;
        input.source = source;
        mInputList.push_back ( input );
    }

    //---------------------------------------------------------------
    const String & LibraryAnimations::Sampler::getElementNameBySemantic ( Semantic semantic )
    {
        switch ( semantic )
        {

        case POSITION:
            return CSWC::COLLADA_SEMANTIC_POSITION;

        case INTERPOLATION:
            return CSWC::COLLADA_SEMANTIC_INTERPOLATION;

        case LINEAR_STEPS:
            return CSWC::COLLADA_SEMANTIC_LINEAR_STEPS;

        case INPUT:
            return CSWC::COLLADA_SEMANTIC_INPUT;

        case OUTPUT:
            return CSWC::COLLADA_SEMANTIC_OUTPUT;

        case IN_TANGENT:
            return CSWC::COLLADA_SEMANTIC_IN_TANGENT;

        case OUT_TANGENT:
            return CSWC::COLLADA_SEMANTIC_OUT_TANGENT;

        case CONTINUITY:
            return CSWC::COLLADA_SEMANTIC_CONTINUITY;

        default:
            return CSWC::EMPTY_STRING;
        }
    }

} //namespace COLLADA
