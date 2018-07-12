/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWMatrix.h"

#include "Math/COLLADABUMathMatrix4.h"


namespace COLLADAFW
{

	//--------------------------------------------------------------------
    Node::Node(const UniqueId& uniqueId) 
		:ObjectTemplate< COLLADA_TYPE::NODE >( uniqueId ) 
		, mType( Node::NODE )
	{
	}


	//--------------------------------------------------------------------
	Node::~Node()
	{
	}

	//--------------------------------------------------------------------
	void Node::getTransformationMatrix(COLLADABU::Math::Matrix4& transformationMatrix) const
	{
		transformationMatrix = COLLADABU::Math::Matrix4::IDENTITY;

		for ( size_t i = 0, count = mTransformations.getCount(); i < count; ++i )
		{
			Transformation* transform = mTransformations[i];

			switch ( transform->getTransformationType() )
			{
			case Transformation::ROTATE:
				{
					Rotate* rotate = (Rotate*)transform;
                    COLLADABU::Math::Vector3 axis = rotate->getRotationAxis();
					axis.normalise();
					double angle = rotate->getRotationAngle();
					transformationMatrix = transformationMatrix * COLLADABU::Math::Matrix4(COLLADABU::Math::Quaternion(COLLADABU::Math::Utils::degToRad(angle), axis));
					break;
				}
			case Transformation::TRANSLATE:
				{
					Translate* translate = (Translate*)transform;
					const COLLADABU::Math::Vector3& translation = translate->getTranslation();
					COLLADABU::Math::Matrix4 translationMatrix;
					translationMatrix.makeTrans(translation);
					transformationMatrix = transformationMatrix * translationMatrix;
					break;
				}
			case Transformation::SCALE:
				{
					Scale* scale = (Scale*)transform;
					const COLLADABU::Math::Vector3& scaleVector = scale->getScale();
					COLLADABU::Math::Matrix4 scaleMatrix;
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
			case Transformation::LOOKAT:
				break; /** @TODO unhandled case */
			case Transformation::SKEW:
				break; /** @TODO unhandled case */
			}

		}
	}

    //--------------------------------------------------------------------
    COLLADABU::Math::Matrix4 Node::getTransformationMatrix() const
    {
        COLLADABU::Math::Matrix4 matrix;
        getTransformationMatrix(matrix);
        return matrix;
    }

} // namespace COLLADAFW
