/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWGeometricElement.h"


namespace COLLADAFW
{

    //------------------------------
	GeometricElement::GeometricElement ( Type elementType )
        : mType ( elementType )
	{
	}
	
    //------------------------------
	GeometricElement::~GeometricElement()
	{
	}

    //------------------------------
    const SourceArray& GeometricElement::getSourceArray () const
    {
        return mSourceArray;
    }

    //------------------------------
    void GeometricElement::setSourceArray ( const SourceArray& sourceArray )
    {
        mSourceArray = sourceArray;
    }

    //------------------------------
    const SourceBase* GeometricElement::getSourceById ( const String& sourceId ) const
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
