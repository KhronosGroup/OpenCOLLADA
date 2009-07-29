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
#include "COLLADASaxFWLSaxParserErrorHandler.h"

#include "COLLADABUURI.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWLibraryNodes.h"
#include "COLLADAFWIWriter.h"
#include "COLLADAFWEffect.h"
#include "COLLADAFWLight.h"
#include "COLLADAFWCamera.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADASaxFWLUtils.h"

#include <sys/types.h>
#include <sys/timeb.h>
#include <fstream>

namespace COLLADASaxFWL
{

	Loader::Loader( IErrorHandler* errorHandler )
		: mErrorHandler(errorHandler)
		, mNextTextureMapId(0)
		, mObjectFlags( Loader::ALL_OBJECTS_MASK )
		, mParsedObjectFlags( Loader::NO_FLAG )
		, mSidTreeRoot( new SidTreeNode("", 0) )
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
			return mURIUniqueIdMap[uri] = COLLADAFW::UniqueId(classId, mLoaderUtil.getLowestObjectIdFor(classId));
		}
		else
		{
			return it.second();
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
			return it.second();
		}
	}

	//---------------------------------
	COLLADAFW::UniqueId Loader::getUniqueId( COLLADAFW::ClassId classId )
	{
		return COLLADAFW::UniqueId(classId, mLoaderUtil.getLowestObjectIdFor(classId));
	}

	//---------------------------------
	bool Loader::loadDocument( const String& fileName, COLLADAFW::IWriter* writer )
	{
		if ( !writer )
			return false;
		mWriter = writer;

		SaxParserErrorHandler saxParserErrorHandler(mErrorHandler);

		FileLoader fileLoader(this, 
			                  COLLADABU::URI::URI(COLLADABU::URI::nativePathToUri(fileName)), 
							  &saxParserErrorHandler, 
							  mObjectFlags,
							  mParsedObjectFlags);
		fileLoader.load();
		mParsedObjectFlags |= mObjectFlags;

		return true;
	}

	//---------------------------------
	GeometryMaterialIdInfo& Loader::getMeshMaterialIdInfo( const COLLADAFW::UniqueId& uniqueId )
	{
		return mGeometryMeshMaterialIdInfoMapMap[uniqueId];
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

} // namespace COLLADA
