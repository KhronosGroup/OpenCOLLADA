/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_GEOMETRYMATERIALIDINFO_H__
#define __COLLADASAXFWL_GEOMETRYMATERIALIDINFO_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADAFWTypes.h"
#include "COLLADAFWUniqueId.h"

#include <map>

namespace COLLADASaxFWL
{

	/** Hold information about the relation of collada symbols and material ids used in the framework.*/
	class GeometryMaterialIdInfo
	{
	public:

		/** Maps the collada symbol (used to bind materials) to the MaterialId used in the framework.*/
		typedef std::map<String, COLLADAFW::MaterialId> ColladaSymbolMaterialIdMap;

	private:

		/** The highest material id already used for the mesh.*/
		COLLADAFW::MaterialId mHighestMaterialId;

		/** The map that maps collada symbols to material ids for the mesh.*/
		ColladaSymbolMaterialIdMap mColladaSymbolMaterialIdMap;

	public:
		/** Creates an empty GeometryMaterialIdInfo.*/
		GeometryMaterialIdInfo();

		/** Returns the material id the is used in the framework instead of the symbol name. If this member has
		been called with the same symbol earlier, the same material id as on the first call is returned. If not, a
		new material is returned. 
		If the symbol is empty, always 0 is returned.*/
		COLLADAFW::MaterialId getMaterialId( const String& symbol);
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_GEOMETRYMATERIALIDINFO_H__
