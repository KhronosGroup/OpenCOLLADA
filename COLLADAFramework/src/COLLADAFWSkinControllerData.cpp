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
	SkinControllerData::SkinControllerData( const UniqueId& uniqueId )
		: ObjectTemplate< COLLADA_TYPE::SKIN_DATA >(uniqueId)
		, mBindShapeMatrix(COLLADABU::Math::Matrix4::IDENTITY)
		, mJointsPerVertex(UIntValuesArray::OWNER)
		, mWeightIndices(UIntValuesArray::OWNER)
		, mJointIndices(UIntValuesArray::OWNER)
	{}

    //------------------------------
	SkinControllerData::~SkinControllerData()
	{
	}

} // namespace COLLADAFW
