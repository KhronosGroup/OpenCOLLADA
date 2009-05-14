/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWSkinControllerData.h"


namespace COLLADAFW
{

    //------------------------------
	SkinControllerData::SkinControllerData( ObjectId objectId )
		: ObjectTemplate< COLLADA_TYPE::SKIN_DATA >(objectId)
		, mBindShapeMatrix(COLLADABU::Math::Matrix4::IDENTITY)
	{}

    //------------------------------
	SkinControllerData::~SkinControllerData()
	{
	}

} // namespace COLLADAFW
