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
    const InputShared* PolyBase::getInputBySemantic ( 
        const InputSemantic::Semantic& semantic, 
        const bool parent /*= false */ ) const
    {
        // Look for the input element in the current poly base.
        for ( size_t i=0; i<mInputArray.getCount (); ++i )
        {
            InputShared* input = mInputArray [ i ];
            if ( input->getSemantic () == semantic )
                return input;
        }

        // Look in the parent vertex element for the input element.
        if ( parent )
        {
            if ( mParent->getVertexInputBySemantic ( semantic ) != 0 )
                return getInputBySemantic ( InputSemantic::VERTEX );
        }

        return 0;
    }


} // namespace COLLADASaxFWL
