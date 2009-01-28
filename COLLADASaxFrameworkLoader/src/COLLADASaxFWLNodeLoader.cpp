/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLNodeLoader.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWTranslate.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWScale.h"
#include "COLLADAFWSkew.h"
#include "COLLADAFWLookat.h"
#include "COLLADAFWMatrix.h"
#include "COLLADAFWGeometry.h"


namespace COLLADASaxFWL
{

	NodeLoader::NodeLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader),
		mCurrentTransformation(0),
		mTransformationNumbersReceived(0)
	{
	}

	//------------------------------
	NodeLoader::~NodeLoader()
	{
	}

	//------------------------------
	bool NodeLoader::beginNode( const node__AttributeData& attributeData )
	{
		COLLADAFW::Node* newNode;
		if ( attributeData.id )
		{
			newNode = new COLLADAFW::Node(getUniqueId(String("#") + (const char*)attributeData.id, COLLADAFW::Node::ID()).getObjectId());
		}
		else
		{
			newNode = new COLLADAFW::Node(getUniqueId(COLLADAFW::Node::ID()).getObjectId());
		}

		if ( attributeData.name )
			newNode->setName((const char*)attributeData.name);
		else if ( attributeData.id )
			newNode->setName((const char*)attributeData.id);

		if ( mNodeStack.empty() )
		{
			// we are a direct child of a container
			handleRootNode(newNode);
		}
		else
		{
			//we are a child of another node
			COLLADAFW::Node* parentNode = mNodeStack.top();
			parentNode->getChildNodes().append(newNode);
		}
		mNodeStack.push(newNode);
		return true;
	}

	//------------------------------
	bool NodeLoader::endNode()
	{
		mNodeStack.pop();
		return true;
	}

	//------------------------------
	template<class Transformationtype>
	bool NodeLoader::beginTransformation()
	{
		mCurrentTransformation = new Transformationtype();
		assert(mCurrentTransformation);
		return true;
	}


	//------------------------------
	bool NodeLoader::endTransformation()
	{
		assert(!mNodeStack.empty());
		mNodeStack.top()->getTransformations().append(mCurrentTransformation);
		mTransformationNumbersReceived = 0;
		mCurrentTransformation = 0;
		return true;
	}


	//------------------------------
	bool NodeLoader::begin__node__node( const node__AttributeData& attributeData )
	{
		return beginNode(attributeData);
	}

	//------------------------------
	bool NodeLoader::end__node__node()
	{
		return endNode();
	}


	//------------------------------
	bool NodeLoader::begin__node__translate( const translate__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Translate>();
	}

	//------------------------------
	bool NodeLoader::end__node__translate()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__node__translate( const double* data, size_t length )
	{
		COLLADAFW::Translate* translate = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::TRANSLATE)
			translate = (COLLADAFW::Translate*)(mCurrentTransformation);

		assert(translate);
		COLLADABU::Math::Vector3& translationVector = translate->getTranslation();
		for ( size_t i = 0; i < length; ++i )
			translationVector[mTransformationNumbersReceived++] = data[i];
		return true;
	}

	//------------------------------
	bool NodeLoader::begin__node__rotate( const rotate__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Rotate>();
	}

	//------------------------------
	bool NodeLoader::end__node__rotate()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__node__rotate( const double* data, size_t length )
	{
		COLLADAFW::Rotate* rotate = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::ROTATE)
			rotate = (COLLADAFW::Rotate*)(mCurrentTransformation);

		assert(rotate);
		COLLADABU::Math::Vector3& axisVector = rotate->getRotationAxis();
		for ( size_t i = 0; i < length; ++i )
		{
			if ( mTransformationNumbersReceived < 3)
				axisVector[mTransformationNumbersReceived++] = data[i];
			else
				rotate->setRotationAngle(data[i]);
		}
		return true;
	}

	//------------------------------
	bool NodeLoader::begin__matrix( const matrix__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Matrix>();
	}

	//------------------------------
	bool NodeLoader::end__matrix()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__matrix( const double* data, size_t length )
	{
		COLLADAFW::Matrix* matrix = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::MATRIX)
			matrix = (COLLADAFW::Matrix*)(mCurrentTransformation);

		assert(matrix);
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
	bool NodeLoader::begin__scale( const scale__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Scale>();
	}

	//------------------------------
	bool NodeLoader::end__scale()
	{
		return endTransformation();
	}

	//------------------------------
	bool NodeLoader::data__scale( const double* data, size_t length )
	{
		COLLADAFW::Scale* scale = 0;

		if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::SCALE)
			scale = (COLLADAFW::Scale*)(mCurrentTransformation);

		assert(scale);
		COLLADABU::Math::Vector3& scaleVector = scale->getScale();
		for ( size_t i = 0; i < length; ++i )
			scaleVector[mTransformationNumbersReceived++] = data[i];
		return true;
	}

    //------------------------------
    bool NodeLoader::begin__skew ( const skew__AttributeData& attributeData )
    {
        return beginTransformation<COLLADAFW::Skew>();
    }

    //------------------------------
    bool NodeLoader::end__skew ()
    {
        return endTransformation();
    }

    //------------------------------
    bool NodeLoader::data__skew ( const double* data, size_t length )
    {
        COLLADAFW::Skew* skew = 0;

        if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::SKEW)
            skew = (COLLADAFW::Skew*)(mCurrentTransformation);

        assert(skew);

        double angle = skew->getAngle ();
        COLLADABU::Math::Vector3& rotateAxis = skew->getRotateAxis ();
        COLLADABU::Math::Vector3& aroundAxis = skew->getTranslateAxis ();

        size_t i = 0;
        if ( i < length && mTransformationNumbersReceived == 0 )
        {
            angle = data [mTransformationNumbersReceived++];
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
	bool NodeLoader::begin__node__instance_geometry( const instance_geometry__AttributeData& attributeData )
	{
		COLLADAFW::Node* currentNode = mNodeStack.top();

		COLLADAFW::UniqueId instantiatedGeometryUniqueId = getUniqueId((const char*)attributeData.url, COLLADAFW::Geometry::ID());

		COLLADAFW::InstanceGeometry* instanceGeometry = new COLLADAFW::InstanceGeometry(instantiatedGeometryUniqueId);

		currentNode->getInstanceGeometries().append(instanceGeometry);

		return true;
	}

	//------------------------------
	bool NodeLoader::end__node__instance_geometry()
	{
		return true;
	}

	//------------------------------
	bool NodeLoader::begin__instance_node( const instance_node__AttributeData& attributeData )
	{
		COLLADAFW::Node* currentNode = mNodeStack.top();

		COLLADAFW::UniqueId instantiatedNodeUniqueId = getUniqueId((const char*)attributeData.url, COLLADAFW::Node::ID());

		COLLADAFW::InstanceNode* instanceNode = new COLLADAFW::InstanceNode(instantiatedNodeUniqueId);

		currentNode->getInstanceNodes().append(instanceNode);

		return true;
	}

	//------------------------------
	bool NodeLoader::end__instance_node()
	{
		return true;
	}

    //------------------------------
    bool NodeLoader::begin__lookat ( const lookat__AttributeData& attributeData )
    {
        return beginTransformation<COLLADAFW::Lookat>();
    }

    //------------------------------
    bool NodeLoader::end__lookat ()
    {
        return endTransformation();
    }

    //------------------------------
    bool NodeLoader::data__lookat ( const double* data, size_t length )
    {
        COLLADAFW::Lookat* lookat = 0;

        if (mCurrentTransformation->getTransformationType() == COLLADAFW::Transformation::LOOKAT)
            lookat = (COLLADAFW::Lookat*)(mCurrentTransformation);

        assert(lookat);

        COLLADABU::Math::Vector3& eyePosition = lookat->getEyePosition ();
        COLLADABU::Math::Vector3& interestPosition = lookat->getInterestPosition ();
        COLLADABU::Math::Vector3& upPosition = lookat->getUpPosition ();

        size_t i = 0;
        if ( i < length && mTransformationNumbersReceived < 3 )
        {
            for ( size_t j=0; j<3 && i<length; ++j, ++i )
            {
                eyePosition[j] = data[i];
                mTransformationNumbersReceived++;
            }
        }
        if ( i < length && mTransformationNumbersReceived >= 3 && mTransformationNumbersReceived < 6 )
        {
            for ( size_t j=0; j<3 && i<length; ++j, ++i )
            {
                interestPosition[j] = data[i];
                mTransformationNumbersReceived++;
            }
        }
        if (  i < length && mTransformationNumbersReceived >= 6 )
        {
            for ( size_t j=0; j<3 && i<length; ++j, ++i )
            {
                upPosition[j] = data[i];
                mTransformationNumbersReceived++;
            }
        }
        return true;
    }

} // namespace COLLADASaxFWL
