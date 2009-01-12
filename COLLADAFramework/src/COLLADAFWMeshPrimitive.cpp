/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWMeshPrimitive.h"

namespace COLLADAFW
{



	//---------------------------------------------------------------
	MeshPrimitive::MeshPrimitive() 
		: mPrimitiveType ( UNDEFINED_PRIMITIVE_TYPE )
		, mPositionIndices(UIntValuesArray::OWNER)
		, mNormalIndices(UIntValuesArray::OWNER)
		, mColorIndices(UIntValuesArray::OWNER)
		, mUVCoordIndices(UIntValuesArray::OWNER)
		, mEdgeIndices(UIntValuesArray::OWNER)
		, mFaceCount ( 0 )
	{
	}

	//---------------------------------------------------------------
	MeshPrimitive::MeshPrimitive( PrimitiveType primitiveType ) 
		: mPrimitiveType ( primitiveType )
		, mPositionIndices(UIntValuesArray::OWNER)
		, mNormalIndices(UIntValuesArray::OWNER)
		, mColorIndices(UIntValuesArray::OWNER)
		, mUVCoordIndices(UIntValuesArray::OWNER)
		, mEdgeIndices(UIntValuesArray::OWNER)
		, mFaceCount ( 0 )
	{
	}


}