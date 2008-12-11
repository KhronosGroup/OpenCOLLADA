/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLPolyBase.h"
#include "COLLADASaxFWLMeshLoader.h"


namespace COLLADASaxFWL
{

    //------------------------------
    const InputShared* PolyBase::getInputBySemantic ( const InputSemantic::Semantic& semantic ) const
    {
        // Look for the input element in the current poly base.
        for ( size_t i=0; i<mInputArray.getCount (); ++i )
        {
            InputShared* input = mInputArray [ i ];
            if ( input->getSemantic () == semantic )
                return input;
        }

//         // Look in the parent vertex element for the input element.
//         if ( parent )
//         {
//             if ( mParent->getVertexInputBySemantic ( semantic ) != 0 )
//                 return getInputBySemantic ( InputSemantic::VERTEX );
// //            return mParent->getVertexInputBySemantic ( semantic );
//         }

        return 0;
    }

    //------------------------------
    const InputShared* PolyBase::appendInputElement ( InputShared* inputShared )
    {
        if ( inputShared != 0 )
        {
            // Check if we have the maximal offset value
            unsigned int offset = inputShared->getOffset ();
            if ( offset > mInputArrayMaxOffset ) mInputArrayMaxOffset = offset;

            // If we append the "VERTEX" input element, we directly create shared input elements
            // with the vertex attributes.
            if ( inputShared->getSemantic () == InputSemantic::VERTEX )
            {
                const Vertices& vertices = mParent->getVertices ();
                const InputUnsharedArray& inputArray = vertices.getInputArray ();
                size_t numInputElements = inputArray.getCount ();
                // Resize the input array
                mInputArray.reallocMemory ( numInputElements );
                for ( size_t i=0; i<numInputElements; ++i )
                {
                    const InputUnshared* inputUnshared = inputArray [ i ];

                    InputShared* input = new InputShared ( inputUnshared->getSemantic (), inputUnshared->getSource (), inputShared->getOffset (), inputShared->getSet() );
                    mInputArray.append ( input );
                }
                return mInputArray [ mInputArray.getCount () - 1 ];
            }
            else
            {
                return mInputArray.append ( inputShared );
            }
        }
        return 0;
    }

} // namespace COLLADASaxFWL
