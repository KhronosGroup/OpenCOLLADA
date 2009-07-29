/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLMeshLoader14.h"
#include "COLLADASaxFWLMeshLoader15.h"
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
        switch (this->getParserImpl()->getCOLLADAVersion())
        {
        case COLLADA_14:
            {
            MeshLoader14* meshloader14 = new MeshLoader14( meshLoader );
            meshLoader->setParserImpl(meshloader14);
            setParser(meshloader14);
            break;
            }
        case COLLADA_15:
            {
            MeshLoader15* meshloader15 = new MeshLoader15( meshLoader );
            meshLoader->setParserImpl(meshloader15);
            setParser(meshloader15);
            break;
            }
        }
		return true;
	}

	//------------------------------
	bool GeometryLoader::end__geometry()
	{
		finish();
		moveUpInSidTree();
		return true;
	}

} // namespace COLLADAFW
