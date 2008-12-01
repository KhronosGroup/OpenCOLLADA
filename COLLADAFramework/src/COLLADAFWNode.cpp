/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWNode.h"

#include "COLLADAFWMathMatrix4.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWMatrix.h"

namespace COLLADAFW
{
	//--------------------------------------------------------------------
	Node::Node()
	{
	}
	
	//--------------------------------------------------------------------
	Node::~Node()
	{
		//delete all child nodes
		for ( size_t i = 0, count = mChildNodes.getCount(); i < count; ++i)
			delete mChildNodes[i];

		//delete all transformations
		for ( size_t i = 0, count = mTransformations.getCount(); i < count; ++i)
			delete mTransformations[i];

		//delete all instance geometries
		for ( size_t i = 0, count = mInstanceGeometries.getCount(); i < count; ++i)
			delete mInstanceGeometries[i];
	}

	//--------------------------------------------------------------------
	void Node::getTransformationMatrix(Math::Matrix4& transformationMatrix) const
	{
		transformationMatrix = Math::Matrix4::IDENTITY;

		for ( size_t i = 0, count = mTransformations.getCount(); i < count; ++i )
		{
			Transformation* transform = mTransformations[i];

			switch ( transform->getTransformationType() )
			{
			case Transformation::ROTATE:
				{
					Rotate* rotate = (Rotate*)transform;
					const Math::Vector3& axis = rotate->getRotationAxis();
					double angle = rotate->getRotationAngle();
					transformationMatrix = transformationMatrix * Math::Matrix4(Math::Quaternion(angle, axis));
					break;
				}
			case Transformation::TRANSLATE:
				{
					Translate* translate = (Translate*)transform;
					const Math::Vector3& translation = translate->getTranslation();
					Math::Matrix4 translationMatrix;
					translationMatrix.makeTrans(translation);
					transformationMatrix = transformationMatrix * translationMatrix;
					break;
				}
			case Transformation::SCALE:
				{
					Scale* scale = (Scale*)transform;
					const Math::Vector3& scaleVector = scale->getScale();
					Math::Matrix4 scaleMatrix;
					scaleMatrix.makeScale(scaleVector);
					transformationMatrix = transformationMatrix * scaleMatrix;
					break;
				}
			case Transformation::MATRIX:
				{
					Matrix* matrix = (Matrix*)transform;
					transformationMatrix = transformationMatrix * matrix->getMatrix();
					break;
				}
			}

		}
	}

	//--------------------------------------------------------------------
	Math::Matrix4 Node::getTransformationMatrix() const
	{
		Math::Matrix4 matrix;
		getTransformationMatrix(matrix);
		return matrix;
	}

} // namespace COLLADAFW
