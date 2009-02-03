/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLGeometryLoader.h"

namespace COLLADASaxFWL
{

	GeometryLoader::GeometryLoader( IFilePartLoader* callingFilePartLoader)
		: FilePartLoader(callingFilePartLoader)
	{
	}

    //------------------------------
	GeometryLoader::~GeometryLoader()
	{
	}

	//------------------------------
	bool GeometryLoader::begin__mesh()
	{
		MeshLoader* meshLoader = new MeshLoader(this, mGeometryId, mGeometryName);
		setPartLoader(meshLoader);
		setParser(meshLoader);
		return true;
	}

	//------------------------------
	bool GeometryLoader::end__geometry()
	{
		finish();
		return true;
	}

/*
    //------------------------------
    const SourceBase* GeometryLoader::getSourceById ( const String& sourceId ) const
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
    SourceBase* GeometryLoader::getSourceById ( const String& sourceId ) 
    {
        for ( size_t i=0; i<mSourceArray.getCount (); ++i )
        {
            SourceBase* source = mSourceArray [ i ];
            if ( COLLADABU::Utils::equals ( source->getId (), sourceId ) )
                return source;
        }

        return 0;
    }

	*/

} // namespace COLLADAFW
