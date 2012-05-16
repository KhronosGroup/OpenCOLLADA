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
#include "COLLADAMaxImageImporter.h"


namespace COLLADAMax
{

    //------------------------------
	ImageImporter::ImageImporter( DocumentImporter* documentImporter, const COLLADAFW::Image* image )
		: ImporterBase(documentImporter)
		, mImage(image)
	{

	}

    //------------------------------
	ImageImporter::~ImageImporter()
	{
	}

	//------------------------------
	bool ImageImporter::import()
	{
		const COLLADAFW::UniqueId& imageUniqueId = mImage->getUniqueId();
		if ( imageUniqueId.isValid() )
			addUniqueIdFWImagePair(imageUniqueId, *mImage);
		return true;
	}

} // namespace COLLADAMax
