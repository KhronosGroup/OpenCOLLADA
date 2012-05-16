/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLTransformationLoader.h"

#include "COLLADAFWTranslate.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWSkew.h"
#include "COLLADAFWLookat.h"
#include "COLLADAFWMatrix.h"

namespace COLLADASaxFWL
{

    //------------------------------
	TransformationLoader::TransformationLoader()
		: mCurrentTransformation(0)
		, mTransformationNumbersReceived(0)
	{
	}
	
    //------------------------------
	TransformationLoader::~TransformationLoader()
	{
	}

	//------------------------------
	bool TransformationLoader::dataTranslate( const float* data, size_t length )
	{	
		COLLADAFW::Translate* translate = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::TRANSLATE)
		{
			translate = (COLLADAFW::Translate*)(mCurrentTransformation);
		}

		COLLADABU_ASSERT(translate);
		COLLADABU::Math::Vector3& translationVector = translate->getTranslation();
		for ( size_t i = 0; i < length; ++i )
		{
			translationVector[mTransformationNumbersReceived++] = data[i];
		}
		return true;
	}

	//------------------------------
	bool TransformationLoader::dataRotate( const float* data, size_t length )
	{
		COLLADAFW::Rotate* rotate = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::ROTATE)
		{
			rotate = (COLLADAFW::Rotate*)(mCurrentTransformation);
		}

		COLLADABU_ASSERT(rotate);
		COLLADABU::Math::Vector3& axisVector = rotate->getRotationAxis();
		for ( size_t i = 0; i < length; ++i )
		{
			if ( mTransformationNumbersReceived < 3)
			{
				axisVector[mTransformationNumbersReceived++] = data[i];
			}
			else
			{
				rotate->setRotationAngle(data[i]);
			}
		}
		return true;
	}

	//------------------------------
	bool TransformationLoader::dataMatrix( const float* data, size_t length )
	{
		COLLADAFW::Matrix* matrix = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::MATRIX)
		{
			matrix = (COLLADAFW::Matrix*)(mCurrentTransformation);
		}

		COLLADABU_ASSERT(matrix);
		COLLADABU::Math::Matrix4& transformationMatrix = matrix->getMatrix();
		for ( size_t i = 0; i < length; ++i )
		{
			size_t row = mTransformationNumbersReceived / 4;
			size_t column = mTransformationNumbersReceived % 4;
			transformationMatrix.setElement(row, column, data[i]);
			mTransformationNumbersReceived++;
		}
		return true;
	}

	//------------------------------
	bool TransformationLoader::dataScale( const float* data, size_t length )
	{
		COLLADAFW::Scale* scale = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::SCALE)
		{
			scale = (COLLADAFW::Scale*)(mCurrentTransformation);
		}

		COLLADABU_ASSERT(scale);
		COLLADABU::Math::Vector3& scaleVector = scale->getScale();
		for ( size_t i = 0; i < length; ++i )
		{
			scaleVector[mTransformationNumbersReceived++] = data[i];
		}
		return true;
	}

	//------------------------------
	bool TransformationLoader::dataSkew( const float* data, size_t length )
	{
		COLLADAFW::Skew* skew = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::SKEW)
		{
			skew = (COLLADAFW::Skew*)(mCurrentTransformation);
		}

		COLLADABU_ASSERT(skew);

		COLLADABU::Math::Vector3& rotateAxis = skew->getRotateAxis ();
		COLLADABU::Math::Vector3& aroundAxis = skew->getTranslateAxis ();

		size_t i = 0;
		if ( i < length && mTransformationNumbersReceived == 0 )
		{
			float angle = skew->getAngle ();
			skew->setAngle ( angle + data [mTransformationNumbersReceived++] );
			++i;
		}
		if ( i < length && mTransformationNumbersReceived > 0 && mTransformationNumbersReceived < 4 )
		{
			for ( size_t j=0; j<3 && i<length; ++j, ++i )
			{
				rotateAxis[j] = data[i];
				mTransformationNumbersReceived++;
			}
		}
		if (  i < length && mTransformationNumbersReceived >= 4 )
		{
			for ( size_t j=0; j<3 && i<length; ++j, ++i )
			{
				aroundAxis[j] = data[i];
				mTransformationNumbersReceived++;
			}
		}
		return true;
	}

	//------------------------------
	bool TransformationLoader::dataLookat( const float* data, size_t length )
	{
		COLLADAFW::Lookat* lookat = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::LOOKAT)
		{
			lookat = (COLLADAFW::Lookat*)(mCurrentTransformation);
		}

		COLLADABU_ASSERT(lookat);

		COLLADABU::Math::Vector3& eyePosition = lookat->getEyePosition ();
		COLLADABU::Math::Vector3& interestPointPosition = lookat->getInterestPointPosition ();
		COLLADABU::Math::Vector3& upAxisDirection = lookat->getUpAxisDirection ();

		size_t i = 0;
		if ( i < length && mTransformationNumbersReceived < 3 )
		{
			for ( size_t j=mTransformationNumbersReceived; j<3 && i<length; ++j, ++i )
			{
				eyePosition[j] = data[i];
				mTransformationNumbersReceived++;
			}
		}
		if ( i < length && mTransformationNumbersReceived >= 3 && mTransformationNumbersReceived < 6 )
		{
			for ( size_t j=mTransformationNumbersReceived-3; j<3 && i<length; ++j, ++i )
			{
				interestPointPosition[j] = data[i];
				mTransformationNumbersReceived++;
			}
		}
		if (  i < length && mTransformationNumbersReceived >= 6 )
		{
			for ( size_t j=mTransformationNumbersReceived-6; j<3 && i<length; ++j, ++i )
			{
				upAxisDirection[j] = data[i];
				mTransformationNumbersReceived++;
			}
		}
		return true;
	}

	//------------------------------
	void TransformationLoader::endTransformation()
	{
		mTransformationNumbersReceived = 0;
		mCurrentTransformation = 0;
	}

} // namespace COLLADASaxFWL
