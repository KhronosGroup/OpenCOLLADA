/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWMatrix.h"

namespace COLLADAFW
{
	//--------------------------------------------------------------------
	Matrix::Matrix()
		: Transformation(Transformation::MATRIX),
		mMatrix(COLLADABU::Math::Matrix4::IDENTITY)
	{
	}

	Matrix::Matrix( const COLLADABU::Math::Matrix4& matrix )
		: Transformation(Transformation::MATRIX),
		mMatrix(matrix)
	{
	}

	

	//--------------------------------------------------------------------
	Matrix::~Matrix()
	{
	}

} // namespace COLLADAFW
