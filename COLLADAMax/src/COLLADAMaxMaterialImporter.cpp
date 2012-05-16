/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxMaterialImporter.h"

#include "COLLADAFWMaterial.h"


namespace COLLADAMax
{

	MaterialImporter::MaterialImporter( DocumentImporter* documentImporter, const COLLADAFW::Material* material )
		: ImporterBase(documentImporter)
		, mMaterial(material)
	{

	}

    //------------------------------
	MaterialImporter::~MaterialImporter()
	{
	}

	bool MaterialImporter::import()
	{
		const COLLADAFW::UniqueId& materialUniqueId = mMaterial->getUniqueId();
		if ( materialUniqueId.isValid() )
			addUniqueIdFWMaterialPair(materialUniqueId, *mMaterial);
		return true;
	}
} // namespace COLLADAMax
