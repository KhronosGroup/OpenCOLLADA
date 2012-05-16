/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLGeometryMaterialIdInfo.h"


namespace COLLADASaxFWL
{

	//---------------------------------
	GeometryMaterialIdInfo::GeometryMaterialIdInfo()
		: mHighestMaterialId(0)
		, mColladaSymbolMaterialIdMap()
	{
	}

	//---------------------------------
	COLLADAFW::MaterialId GeometryMaterialIdInfo::getMaterialId( const String& symbol )
	{
		if ( symbol.empty() )
			return 0;

		ColladaSymbolMaterialIdMap::const_iterator it = mColladaSymbolMaterialIdMap.find(symbol);
		if ( it == mColladaSymbolMaterialIdMap.end())
		{
			mHighestMaterialId++;
			mColladaSymbolMaterialIdMap[symbol] = mHighestMaterialId;
			return mHighestMaterialId;
		}
		else
		{
			return it->second;
		}

	}

} // namespace COLLADASaxFWL
