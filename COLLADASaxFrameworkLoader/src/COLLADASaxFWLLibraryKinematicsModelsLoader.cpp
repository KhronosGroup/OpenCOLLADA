/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryKinematicsModelsLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWTranslate.h"
#include "COLLADAFWRotate.h"
#include "COLLADAFWJoint.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryKinematicsModelsLoader::LibraryKinematicsModelsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mCurrentKinematicsModel(0)
		, mCurrentJointInstance(0)
		, mCurrentAttachment(0)
	{
		FormulasLoader::setHandlingFilePartLoader(this);
		mJointsLoader.setHandlingFilePartLoader(this);
	}

    //------------------------------
	LibraryKinematicsModelsLoader::~LibraryKinematicsModelsLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryKinematicsModelsLoader::getUniqueId ()
    {
        // TODO No uniqueId!
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	template<class Transformationtype> 
	bool LibraryKinematicsModelsLoader::beginTransformation( const char* sid )
	{
		mTransformationLoader.beginTransformation<Transformationtype>();
		addToSidTree( 0, sid, mTransformationLoader.getCurrentTransformation());
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::endTransformation()
	{
		if ( mCurrentAttachment )
		{
			// we are a child of an attachment
			mCurrentAttachment->addTransformation( mTransformationLoader.getCurrentTransformation() );
		}
		else
		{
			// we are a child of a link
			KinematicLink* link = mLinkStack.top();
			link->addTransformation( mTransformationLoader.getCurrentTransformation() );
		}
		moveUpInSidTree();
		mTransformationLoader.endTransformation();
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::beginAttachment( KinematicAttachment::Type attachmentType, const attachment_AttributeData& attributeData )
	{
		String joint(attributeData.joint);
		mCurrentAttachment = new KinematicAttachment( attachmentType, joint);
		COLLADABU_ASSERT( !mLinkStack.empty() );
		KinematicLink* link = mLinkStack.top();
		link->addAttachment( mCurrentAttachment );
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::endAttachment()
	{
		mCurrentAttachment = 0;
		return true;
	}


	//------------------------------
	bool LibraryKinematicsModelsLoader::end__library_kinematics_models()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::begin__kinematics_model( const kinematics_model__AttributeData& attributeData )
	{
		COLLADABU::URI uri(getFileUri());
		if ( attributeData.id )
		{
			uri.setFragment( attributeData.id );
		}

		const char* name = 0;
		if ( attributeData.name )
		{
			name = attributeData.name;
		}
		else if ( attributeData.id )
		{
			name = attributeData.id;
		}

		mCurrentKinematicsModel = new KinematicsModel(uri, name);
		SidTreeNode* sidTreeNode = addToSidTree( attributeData.id, 0, mCurrentKinematicsModel);
		mCurrentKinematicsModel->setSidTreeNode(sidTreeNode);
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::end__kinematics_model()
	{
		getFileLoader()->addKinematicsModel( mCurrentKinematicsModel );
		mCurrentKinematicsModel = 0;
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::begin__instance_joint( const instance_joint__AttributeData& attributeData )
	{
		// Get the unique id of the joint, that will replace this instance in the kinematics model
		COLLADAFW::UniqueId jointId = createUniqueId( COLLADAFW::Joint::ID() );
		mCurrentJointInstance = new KinematicInstance( attributeData.url, jointId );
		getFileLoader()->addInstanceJoint( mCurrentJointInstance );
		addToSidTree( 0, attributeData.sid, mCurrentJointInstance );
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::end__instance_joint()
	{
		mCurrentJointInstance = 0;
		moveUpInSidTree();
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::begin__link( const link__AttributeData& attributeData )
	{
		KinematicLink* link = 0;
		if ( mLinkStack.empty() )
		{
			// this is a base link. Create a new link and add it to the kinematics model
			link = new KinematicLink();
			mCurrentKinematicsModel->addBaseLink(link);
		}
		else
		{
			// this is a child of the current attachment. 
			COLLADABU_ASSERT(mCurrentAttachment);
			link = &mCurrentAttachment->getLink();

		}
		addToSidTree(0, attributeData.sid, link);
		mLinkStack.push( link );
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::end__link()
	{
		moveUpInSidTree();
		mLinkStack.pop();
		return true;
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::begin__attachment_full( const attachment_AttributeData& attributeData )
	{
		return beginAttachment( KinematicAttachment::FULL, attributeData);
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::end__attachment_full()
	{
		return endAttachment();
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::begin__attachment_start( const attachment_AttributeData& attributeData )
	{
		return beginAttachment( KinematicAttachment::START, attributeData);
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::end__attachment_start()
	{
		return endAttachment();
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::begin__attachment_end( const attachment_AttributeData& attributeData )
	{
		return beginAttachment( KinematicAttachment::END, attributeData);
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::end__attachment_end()
	{
		return endAttachment();
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::begin__translate( const translate__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Translate>( attributeData.sid );
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::end__translate()
	{
		return endTransformation();
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::data__translate( const float* data, size_t length )
	{
		return mTransformationLoader.dataTranslate( data, length);
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::begin__rotate( const rotate__AttributeData& attributeData )
	{
		return beginTransformation<COLLADAFW::Rotate>( attributeData.sid );
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::end__rotate()
	{
		return endTransformation();
	}

	//------------------------------
	bool LibraryKinematicsModelsLoader::data__rotate( const float* data, size_t length )
	{
		return mTransformationLoader.dataRotate( data, length);
	}

} // namespace COLLADASaxFWL
