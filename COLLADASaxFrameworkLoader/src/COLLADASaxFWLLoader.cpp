/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADASaxFrameworkLoader.

Licensed under the MIT Open Source License,
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLoader.h"
#include "COLLADASaxFWLFileLoader.h"
#include "COLLADASaxFWLPostProcessor.h"
#include "COLLADASaxFWLSaxParserErrorHandler.h"
#include "COLLADASaxFWLUtils.h"

#include "COLLADABUURI.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWLibraryNodes.h"
#include "COLLADAFWIWriter.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWLight.h"
#include "COLLADAFWCamera.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWConstants.h"

#include <sys/types.h>
#include <sys/timeb.h>
#include <fstream>

namespace COLLADASaxFWL
{

	const Loader::InstanceControllerDataList Loader::EMPTY_INSTANCE_CONTROLLER_DATALIST = Loader::InstanceControllerDataList();

	const Loader::JointSidsOrIds Loader::EMPTY_JOINTSIDSORIDS;


	Loader::Loader( IErrorHandler* errorHandler )
		: mFileLoader(0)
		, mNextFileId(0)
		, mCurrentFileId(0)
		, mErrorHandler(errorHandler)
		, mNextTextureMapId(0)
		, mObjectFlags( Loader::ALL_OBJECTS_MASK )
		, mParsedObjectFlags( Loader::NO_FLAG )
		, mSidTreeRoot( new SidTreeNode("", 0) )
		, mSkinControllerSet( compare )
		, mExternalReferenceDeciderCallbackFunction()

	{
	}


	//---------------------------------
	Loader::~Loader()
	{
		delete mSidTreeRoot;

		// delete visual scenes
		deleteVectorFW(mVisualScenes);

		// delete library nodes
		deleteVectorFW(mLibraryNodes);

		// delete effects
		deleteVectorFW(mEffects);

		// delete lights
		deleteVectorFW(mLights);

		// delete cameras
		deleteVectorFW(mCameras);

		// We do not delete formulas here. They are deleted by the Formulas class

		// delete animation lists
		Loader::UniqueIdAnimationListMap::const_iterator it = mUniqueIdAnimationListMap.begin();
		for ( ; it != mUniqueIdAnimationListMap.end(); ++it )
		{
			COLLADAFW::AnimationList* animationList = it->second;
			FW_DELETE animationList;
		}
	}

    //---------------------------------
	const COLLADAFW::UniqueId& Loader::getUniqueId( const COLLADABU::URI& uri, COLLADAFW::ClassId classId )
	{
		URIUniqueIdMap::iterator it = mURIUniqueIdMap.find(uri);
		if ( it == mURIUniqueIdMap.end() )
		{
			return mURIUniqueIdMap[uri] = COLLADAFW::UniqueId(classId, mLoaderUtil.getLowestObjectIdFor(classId), getFileId(uri));
		}
		else
		{
			return it->second;
		}
	}

	//---------------------------------
	const COLLADAFW::UniqueId& Loader::getUniqueId( const COLLADABU::URI& uri)
	{
		URIUniqueIdMap::iterator it = mURIUniqueIdMap.find(uri);
		if ( it == mURIUniqueIdMap.end() )
		{
			return COLLADAFW::UniqueId::INVALID;
		}
		else
		{
			return it->second;
		}
	}

	//---------------------------------
	COLLADAFW::UniqueId Loader::getUniqueId( COLLADAFW::ClassId classId )
	{
		return COLLADAFW::UniqueId(classId, mLoaderUtil.getLowestObjectIdFor(classId), mCurrentFileId);
	}

	//---------------------------------
	COLLADAFW::FileId Loader::getFileId( const COLLADABU::URI& uri )
	{
		// check if the uri is relative
		bool isRelative = uri.getScheme().empty() && 
			              uri.getAuthority().empty() && 
						  uri.getPath().empty() && 
						  uri.getQuery().empty();
		if ( isRelative )
		{
			// its a relative uri. The file id is that of the current file
			return mCurrentFileId;
		}

		// the uri is not relative. We need to find the correct file id
		const COLLADABU::URI* usedUri = 0;

		COLLADABU::URI uriWithoutFragment;
		
		if ( uri.getFragment().empty() )
		{
			// the passed uri has no fragment, we can use it without modification
			usedUri = &uri;
		}
		else
		{
			// the passed uri has a fragment, we need to make a copy without fragment
			uriWithoutFragment.set( uri.getScheme(), uri.getAuthority(), uri.getPath(), uri.getQuery(), COLLADAFW::Constants::EMPTY_STRING);
			usedUri = &uriWithoutFragment;
		}

		URIFileIdMap::iterator it = mURIFileIdMap.find( *usedUri );

		if ( it == mURIFileIdMap.end() )
		{
			COLLADAFW::FileId fileId = mNextFileId++;
			addFileIdUriPair( fileId, *usedUri );
			return fileId;
		}
		else
		{
			return it->second;
		}
	}

	//---------------------------------
	const COLLADABU::URI& Loader::getFileUri( COLLADAFW::FileId fileId )const
	{
		FileIdURIMap::const_iterator it = mFileIdURIMap.find( fileId );

		if ( it == mFileIdURIMap.end() )
		{
			return COLLADABU::URI::INVALID;
		}
		else
		{
			return it->second;
		}
	}

	//---------------------------------
	void Loader::addFileIdUriPair( COLLADAFW::FileId fileId, const COLLADABU::URI& uri )
	{
		mURIFileIdMap[uri] = fileId;
		mFileIdURIMap[fileId] = uri;
	}

	//---------------------------------
	bool Loader::loadDocument( const String& fileName, COLLADAFW::IWriter* writer )
	{
		if ( !writer )
			return false;
		mWriter = writer;

		mWriter->start();

		SaxParserErrorHandler saxParserErrorHandler(mErrorHandler);

		COLLADABU::URI rootFileUri(COLLADABU::URI::nativePathToUri(fileName));
		
		// the root file has always file id 0
		addFileIdUriPair( mNextFileId++, rootFileUri );

		bool abortLoading = false;

		while ( (mCurrentFileId < mNextFileId) && !abortLoading )
		{
			const COLLADABU::URI& fileUri = getFileUri( mCurrentFileId );

			if ( (mCurrentFileId == 0) 
				|| !mExternalReferenceDeciderCallbackFunction 
				|| mExternalReferenceDeciderCallbackFunction(fileUri, mCurrentFileId) )
			{
				mFileLoader = new FileLoader(this, 
					fileUri,
					&saxParserErrorHandler, 
					mObjectFlags,
					mParsedObjectFlags, 
					mExtraDataCallbackHandlerList );
				bool success = mFileLoader->load();
				delete mFileLoader;
				abortLoading = !success;
			}

			mCurrentFileId++;
		}

		if ( !abortLoading )
		{
			PostProcessor postProcessor(this, 
				&saxParserErrorHandler, 
				mObjectFlags,
				mParsedObjectFlags);
			postProcessor.postProcess();
		}
		else
		{
			mWriter->cancel("Generic error");
		}

		mWriter->finish();

		mParsedObjectFlags |= mObjectFlags;

		return !abortLoading;
	}

	//---------------------------------
	bool Loader::loadDocument( const String& uri, const char* buffer, int length, COLLADAFW::IWriter* writer )
	{
		if ( !writer )
			return false;
		mWriter = writer;
        
		SaxParserErrorHandler saxParserErrorHandler(mErrorHandler);
        
		COLLADABU::URI rootUri(uri);
		
		// the root file has always file id 0
		addFileIdUriPair( mNextFileId++, rootUri );
        
		bool abortLoading = false;

		while ( (mCurrentFileId < mNextFileId) && !abortLoading )
		{
			const COLLADABU::URI& fileUri = getFileUri( mCurrentFileId );

			if ( (mCurrentFileId == 0) 
				|| !mExternalReferenceDeciderCallbackFunction 
				|| mExternalReferenceDeciderCallbackFunction(fileUri, mCurrentFileId) )
			{
				FileLoader fileLoader(this, 
					getFileUri( mCurrentFileId ),
					&saxParserErrorHandler, 
					mObjectFlags,
					mParsedObjectFlags, 
					mExtraDataCallbackHandlerList );
				bool success = fileLoader.load();
				abortLoading = !success;
			}
            
			mCurrentFileId++;
		}
        
		if ( !abortLoading )
		{
			PostProcessor postProcessor(this, 
				&saxParserErrorHandler, 
				mObjectFlags,
				mParsedObjectFlags);
			postProcessor.postProcess();
		}
		else
		{
			mWriter->cancel("Generic error");
		}
        
		mWriter->finish();

		mParsedObjectFlags |= mObjectFlags;
        
		return !abortLoading;
	}

    //---------------------------------
    bool Loader::registerExtraDataCallbackHandler ( IExtraDataCallbackHandler* extraDataCallbackHandler )
    {
        // Push the callback handler in the list of callback handlers.
        mExtraDataCallbackHandlerList.push_back ( extraDataCallbackHandler );

        return true;
    }

	//---------------------------------
	GeometryMaterialIdInfo& Loader::getMeshMaterialIdInfo( )
	{
		return mGeometryMaterialIdInfo;
	}

	//---------------------------------
	COLLADAFW::TextureMapId Loader::getTextureMapIdBySematic( const String& semantic )
	{
		StringTextureMapIdMap::iterator it = mTextureMapSemanticTextureMapIdMap.find(semantic);
		if ( it == mTextureMapSemanticTextureMapIdMap.end() )
		{
			return mTextureMapSemanticTextureMapIdMap[semantic] = mNextTextureMapId++;
		}
		else
		{
			return it->second;
		}
	}

	//-----------------------------
	bool Loader::compare( const COLLADAFW::SkinController& lhs, const COLLADAFW::SkinController& rhs )
	{

		if (lhs.getSkinControllerData() < rhs.getSkinControllerData() )
			return true;
		if (lhs.getSkinControllerData() > rhs.getSkinControllerData() )
			return false;

		if (lhs.getSource() < rhs.getSource() )
			return true;
		if (lhs.getSource() > rhs.getSource() )
			return false;

		const COLLADAFW::UniqueIdArray& lhsJoints = lhs.getJoints();
		const COLLADAFW::UniqueIdArray& rhsJoints = rhs.getJoints();
		size_t lhsJointsCount = lhsJoints.getCount();
		size_t rhsJointsCount = rhsJoints.getCount();
		if (lhsJointsCount < rhsJointsCount )
			return true;
		if (lhsJointsCount > rhsJointsCount )
			return false;

		for ( size_t i = 0; i < lhsJointsCount; ++i)
		{
			const COLLADAFW::UniqueId& lhsJoint = lhsJoints[i];
			const COLLADAFW::UniqueId& rhsJoint = rhsJoints[i];
			if (lhsJoint < rhsJoint )
				return true;
			if (lhsJoint > rhsJoint )
				return false;
		}

		return false;
	}

	//------------------------------
	void Loader::registerExternalReferenceDeciderCallbackFunction( ExternalReferenceDeciderCallbackFunction externalReferenceDeciderCallbackFunction )
	{
		mExternalReferenceDeciderCallbackFunction = externalReferenceDeciderCallbackFunction;
	}

} // namespace COLLADA
