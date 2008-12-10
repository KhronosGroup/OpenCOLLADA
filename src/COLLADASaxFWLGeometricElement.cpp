/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLGeometricElement.h"


namespace COLLADASaxFWL
{

    //------------------------------
	ColladaGeometricElement::ColladaGeometricElement ( GeometricType elementType )
        : GeometricElement ( elementType )
	{
	}
	
    //------------------------------
	ColladaGeometricElement::~ColladaGeometricElement()
	{
	}

    //------------------------------
    const SourceArray& ColladaGeometricElement::getSourceArray () const
    {
        return mSourceArray;
    }

    //------------------------------
    void ColladaGeometricElement::setSourceArray ( const SourceArray& sourceArray )
    {
        mSourceArray = sourceArray;
    }

    //------------------------------
    const SourceBase* ColladaGeometricElement::getSourceById ( const String& sourceId ) const
    {
        for ( size_t i=0; i<mSourceArray.getCount (); ++i )
        {
            const SourceBase* source = mSourceArray [ i ];
            if ( COLLADABU::Utils::equals ( source->getId (), sourceId ) )
                return source;
        }

        return 0;
    }

    //------------------------------
    SourceBase* ColladaGeometricElement::getSourceById ( const String& sourceId ) 
    {
        for ( size_t i=0; i<mSourceArray.getCount (); ++i )
        {
            SourceBase* source = mSourceArray [ i ];
            if ( COLLADABU::Utils::equals ( source->getId (), sourceId ) )
                return source;
        }

        return 0;
    }

} // namespace COLLADAFW
