/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLMeshPrimitiveInputList.h"
#include "COLLADASaxFWLMeshLoader.h"


namespace COLLADASaxFWL
{

    //------------------------------
    const InputShared* MeshPrimitiveInputList::getInputBySemantic ( const InputSemantic::Semantic& semantic ) const
    {
        // Look for the input element in the current poly base.
        for ( size_t i=0; i<mInputArray.getCount (); ++i )
        {
            InputShared* input = mInputArray [ i ];
            if ( input->getSemantic () == semantic )
                return input;
        }

        return 0;
    }

    //------------------------------
    const InputShared* MeshPrimitiveInputList::appendInputElement ( InputShared* inputShared )
    {
        if ( inputShared != 0 )
        {
            // Check if we have the maximal offset value
            unsigned long long offset = inputShared->getOffset();
            if ( offset > mInputArrayMaxOffset ) mInputArrayMaxOffset = offset;

            // If we append the "VERTEX" input element, we directly create shared input elements
            // with the vertex attributes.
            if ( inputShared->getSemantic () == InputSemantic::VERTEX )
            {
                const InputUnsharedArray& inputArray = mVertices.getInputArray ();
                size_t numInputElements = inputArray.getCount ();
                // Resize the input array
                mInputArray.reallocMemory ( numInputElements );
                for ( size_t i=0; i<numInputElements; ++i )
                {
                    const InputUnshared* inputUnshared = inputArray [ i ];

                    InputShared* input = new InputShared ( inputUnshared->getSemantic (), inputUnshared->getSource (), inputShared->getOffset (), inputShared->getSet() );
                    mInputArray.append ( input );
                }
				delete inputShared; // we are responsible for inputShared
                return mInputArray [ mInputArray.getCount () - 1 ];
            }
            else
            {
                return mInputArray.append ( inputShared );
            }
        }
        return 0;
    }

	//------------------------------
	void MeshPrimitiveInputList::clearInputs()
	{
		for ( size_t i = 0, count = mInputArray.getCount(); i < count; ++i)
			delete mInputArray[i];
		mInputArray.clear();
		mInputArrayMaxOffset = 0;
	}
} // namespace COLLADASaxFWL
