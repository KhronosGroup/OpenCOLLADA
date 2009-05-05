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
    Node::Node(ObjectId objectId) 
		:ObjectTemplate< COLLADA_TYPE::NODE >( objectId ) 
		, mType( Node::NODE )
        , mParentNode (0)
	{
	}


	//--------------------------------------------------------------------
	Node::~Node()
	{
	}

	//--------------------------------------------------------------------
	void Node::getNodeTransformationMatrix(COLLADABU::Math::Matrix4& transformationMatrix) const
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
                    const COLLADABU::Math::Vector3& axis = rotate->getRotationAxis();
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
			}

		}
	}

    //--------------------------------------------------------------------
    COLLADABU::Math::Matrix4 Node::getNodeTransformationMatrix() const
    {
        COLLADABU::Math::Matrix4 matrix;
        getNodeTransformationMatrix(matrix);
        return matrix;
    }

    //--------------------------------------------------------------------
    COLLADABU::Math::Matrix4 Node::getJointTransformationMatrix () const
    {
        // Get the node transform matrix.
        COLLADABU::Math::Matrix4 transformMatrix;
        getNodeTransformationMatrix(transformMatrix);

        // Get the parent scale inverse.
        COLLADABU::Math::Matrix4 matrix = mParentNode->getNodeTransformationMatrix ();
        COLLADABU::Math::Vector3 parentScaleInverse = matrix.getScale () * -1;
        COLLADABU::Math::Matrix4 scaleMatrix;
        scaleMatrix.makeScale(parentScaleInverse);

        // Multiply the parent scale inverse.
        transformMatrix = transformMatrix * scaleMatrix;

        return transformMatrix;
    }


} // namespace COLLADAFW
