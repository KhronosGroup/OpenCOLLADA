/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLJointsLoader.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLFilePartLoader.h"

#include "COLLADAFWJoint.h"


namespace COLLADASaxFWL
{

    //------------------------------
	JointsLoader::JointsLoader(  )
		: mCurrentJoint(0)
		, mCurrentJointPrimitive(0)
		, mAxisNumbersReceived(0)
	{
	}

    //------------------------------
	JointsLoader::~JointsLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& JointsLoader::getUniqueId ()
    {
        if ( mCurrentJoint )
            return mCurrentJoint->getUniqueId ();
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	bool JointsLoader::beginJointPrimitive( COLLADAFW::JointPrimitive::Type jointPrimitiveType, const char * sid)
	{
		mCurrentJointPrimitive = FW_NEW COLLADAFW::JointPrimitive( getHandlingFilePartLoader()->createUniqueId( COLLADAFW::JointPrimitive::ID()), jointPrimitiveType );
		mCurrentJoint->getJointPrimitives().append( mCurrentJointPrimitive );
		getHandlingFilePartLoader()->addToSidTree(0, sid, mCurrentJointPrimitive);
		return true;
	}

	//------------------------------
	bool JointsLoader::endJointPrimitive()
	{
		mCurrentJointPrimitive = 0;
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool JointsLoader::begin__joint( const joint__AttributeData& attributeData )
	{
		mCurrentJoint = FW_NEW COLLADAFW::Joint( getHandlingFilePartLoader()->createUniqueIdFromId( attributeData.id, COLLADAFW::Joint::ID()) );
		if ( attributeData.name )
		{
			mCurrentJoint->setName(attributeData.name);
		}
		else if ( attributeData.id )
		{
			mCurrentJoint->setName(attributeData.id);
		}

		if ( attributeData.id )
		{
			mCurrentJoint->setOriginalId(attributeData.id);
		}
		getHandlingFilePartLoader()->addToSidTree( attributeData.id, attributeData.sid, mCurrentJoint);
		return true;
	}

	//------------------------------
	bool JointsLoader::end__joint()
	{
		getHandlingFilePartLoader()->getFileLoader()->addJoint(mCurrentJoint);
		mCurrentJoint = 0;
		getHandlingFilePartLoader()->moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool JointsLoader::begin__prismatic( const prismatic__AttributeData& attributeData )
	{
		return beginJointPrimitive( COLLADAFW::JointPrimitive::PRISMATIC, attributeData.sid);
	}

	//------------------------------
	bool JointsLoader::end__prismatic()
	{
		return endJointPrimitive();
	}

	//------------------------------
	bool JointsLoader::begin__revolute( const revolute__AttributeData& attributeData )
	{
		return beginJointPrimitive( COLLADAFW::JointPrimitive::REVOLUTE, attributeData.sid);
	}

	//------------------------------
	bool JointsLoader::end__revolute()
	{
		return endJointPrimitive();
	}

	//------------------------------
	bool JointsLoader::begin__axis____axis_type( const axis____axis_type__AttributeData& attributeData )
	{
		getHandlingFilePartLoader()->addToSidTree( 0, attributeData.sid);
		return true;
	}

	//------------------------------
	bool JointsLoader::end__axis____axis_type()
	{
		getHandlingFilePartLoader()->moveUpInSidTree();
		mAxisNumbersReceived = 0;
		return true;
	}

	//------------------------------
	bool JointsLoader::data__axis____axis_type( const float* data, size_t length )
	{
		COLLADABU::Math::Vector3& axis = mCurrentJointPrimitive->getAxis();
		for ( size_t i = 0; i < length; ++i )
		{
			axis[mAxisNumbersReceived++] = data[i];
		}
		return true;
	}

	//------------------------------
	bool JointsLoader::data__min____minmax_type( float value )
	{
		COLLADABU_ASSERT(mCurrentJointPrimitive);
		if ( mCurrentJointPrimitive )
		{
			mCurrentJointPrimitive->setHardLimitMin(value);
		}
		return true;
	}

	//------------------------------
	bool JointsLoader::data__max____minmax_type( float value )
	{
		COLLADABU_ASSERT(mCurrentJointPrimitive);
		if ( mCurrentJointPrimitive )
		{
			mCurrentJointPrimitive->setHardLimitMax(value);
		}
		return true;
	}


} // namespace COLLADASaxFWL
