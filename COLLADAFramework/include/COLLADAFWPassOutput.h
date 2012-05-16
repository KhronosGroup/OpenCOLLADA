/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PASSOUTPUT_H__
#define __COLLADAFW_PASSOUTPUT_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** Specifies whether a render target surface is to be cleared, and which value to use. */
	class PassOutput 	
    {
    public:

        enum OutputType 
        {
            OUTPUT_TYPE_COLOR, 
            OUTPUT_TYPE_DEPTH, 
            OUTPUT_TYPE_STENCIL
        };

	private:
	
        /** The current output type. */
        OutputType mOutputType;

        /** Which of the multiple render targets is being set. The default is 0. Optional. */
        unsigned int mIndex;

	public:

        /** Constructor. */
        PassOutput( const OutputType& outputType ) 
            : mOutputType ( outputType ) 
        {}

        /** Destructor. */
        virtual ~PassOutput() {}

        /** The current output type. */
        const PassOutput::OutputType getOutputType () const { return mOutputType; }

        /** The current output type. */
        void setOutputType ( const PassOutput::OutputType outputType ) { mOutputType = outputType; }

        /** Which of the multiple render targets is being set. The default is 0. Optional. */
        const unsigned int getIndex () const { return mIndex; }

        /** Which of the multiple render targets is being set. The default is 0. Optional. */
        void setIndex ( const unsigned int Index ) { mIndex = Index; }

	private:

        /** Disable default copy ctor. */
		PassOutput( const PassOutput& pre );

        /** Disable default assignment operator. */
		const PassOutput& operator= ( const PassOutput& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_PASSOUTPUT_H__
