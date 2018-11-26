#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryAnimationClipsLoader.h"
#include "COLLADASaxFWLLoader.h"

#include "COLLADAFWAnimationClip.h"
#include "COLLADAFWIWriter.h"
#include "COLLADAFWUniqueId.h"

namespace COLLADASaxFWL
{
	//------------------------------
	LibraryAnimationClipsLoader::LibraryAnimationClipsLoader( IFilePartLoader* callingFilePartLoader )
		: FilePartLoader(callingFilePartLoader)
		, mAnimationClip(0)
	{

	}

	//------------------------------
	LibraryAnimationClipsLoader::~LibraryAnimationClipsLoader()
	{
	}

	//------------------------------
	const COLLADAFW::UniqueId& LibraryAnimationClipsLoader::getUniqueId()
	{
		if ( mAnimationClip )
			return mAnimationClip->getUniqueId();
		return COLLADAFW::UniqueId::INVALID;
	}

	//------------------------------
	bool LibraryAnimationClipsLoader::end__library_animation_clips()
	{
		moveUpInSidTree();
		finish();
		return true;
	}

	//------------------------------
	bool LibraryAnimationClipsLoader::begin__animation_clip( const animation_clip__AttributeData& attributeData )
	{
		mAnimationClip = FW_NEW COLLADAFW::AnimationClip(createUniqueIdFromId(attributeData.id, COLLADAFW::AnimationClip::ID()));
		
		if ( attributeData.name )
			mAnimationClip->setName ( (const char*)attributeData.name );
		else if ( attributeData.id )
			mAnimationClip->setName ( (const char*)attributeData.id );

		if ( attributeData.id )
			mAnimationClip->setOriginalId ( (const char*)attributeData.id );

		return true;
	}

	//------------------------------
	bool LibraryAnimationClipsLoader::end__animation_clip()
	{
		COLLADAFW::UniqueIdArray& instanceAnimationUniqueIds = mAnimationClip->getInstanceAnimationUniqueIds();
		instanceAnimationUniqueIds.allocMemory( mInstanceAnimationIds.size() );
		instanceAnimationUniqueIds.setCount( mInstanceAnimationIds.size() );

		UniqueIdSet::const_iterator it = mInstanceAnimationIds.begin();
		size_t i = 0;
		for ( ; it != mInstanceAnimationIds.end(); ++it, ++i )
		{
			instanceAnimationUniqueIds[i] = *it;
		}

		mInstanceAnimationIds.clear();

		bool success = true;
		if ( (getObjectFlags() & Loader::ANIMATION_CLIP_FLAG) != 0)
		{
			success = writer()->writeAnimationClip(mAnimationClip);
		}

		FW_DELETE mAnimationClip;
		mAnimationClip = 0;
		return success;
	}

	//------------------------------
	bool LibraryAnimationClipsLoader::begin__instance_animation( const instance_animation__AttributeData& attributeData )
	{
		mInstanceAnimationIds.insert(createUniqueIdFromUrl(attributeData.url, COLLADAFW::Animation::ID()));
		return true;
	}

	//------------------------------
	bool LibraryAnimationClipsLoader::end__instance_animation()
	{
		return true;
	}
} // namespace COLLADASaxFWL