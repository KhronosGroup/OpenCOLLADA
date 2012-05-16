/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_MATRIX_H__
#define __COLLADAFW_MATRIX_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"

#include "Math/COLLADABUMathMatrix4.h"


namespace COLLADAFW
{
	class Matrix : public Transformation 
	{
	private:
		/** The matrix holding the transformation.*/
        COLLADABU::Math::Matrix4 mMatrix;
	
	public:
		/** Constructor. Creates identity transformation.*/
		Matrix();

		virtual ~Matrix();

		/** Constructor. Sets transformation to @a matrix.*/
        Matrix(const COLLADABU::Math::Matrix4& matrix);

		/** Returns the matrix.*/
		COLLADABU::Math::Matrix4& getMatrix() { return mMatrix; }

		/** Returns the matrix.*/
		const COLLADABU::Math::Matrix4& getMatrix() const { return mMatrix; }

		/** Sets the transformation to @a matrix.*/
		void setMatrix(const COLLADABU::Math::Matrix4& matrix) { mMatrix = matrix; }

		/** Clones the matrix.*/
		Matrix* clone() const { return new Matrix(*this); }


	};
} // namespace COLLADAFW

#endif // __COLLADAFW_MATRIX_H__
