/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLGeometryObjectLoader.h"

namespace COLLADASaxFWL
{

	//------------------------------
	GeometryObjectLoader::GeometryObjectLoader(IFilePartLoader* callingFilePartLoader)
		:FilePartLoader(callingFilePartLoader),
		 mCurrentSoure(0)
	{
	}

	//------------------------------
	GeometryObjectLoader::~GeometryObjectLoader()
	{
	}


    //------------------------------
    const SourceArray& GeometryObjectLoader::getSourceArray () const
    {
        return mSourceArray;
    }

    //------------------------------
    void GeometryObjectLoader::setSourceArray ( const SourceArray& sourceArray )
    {
        mSourceArray = sourceArray;
    }

    //------------------------------
    const SourceBase* GeometryObjectLoader::getSourceById ( const String& sourceId ) const
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
    SourceBase* GeometryObjectLoader::getSourceById ( const String& sourceId ) 
    {
        for ( size_t i=0; i<mSourceArray.getCount (); ++i )
        {
            SourceBase* source = mSourceArray [ i ];
            if ( COLLADABU::Utils::equals ( source->getId (), sourceId ) )
                return source;
        }
        return 0;
    }

	//------------------------------
	bool GeometryObjectLoader::beginSource( const mesh__source__AttributeData& attributes )
	{
		mCurrentSourceId = (const char*)attributes.id;
		return true;
	}

} // namespace COLLADAFW
