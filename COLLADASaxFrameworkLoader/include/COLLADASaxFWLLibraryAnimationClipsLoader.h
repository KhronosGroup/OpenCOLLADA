#ifndef __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER_H__
#define __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"

#include "COLLADAFWHashFunctions.h"
#include "COLLADABUhash_map.h"

namespace COLLADAFW
{
	class AnimationClip;
}


namespace COLLADASaxFWL
{
	/** Loads all animation clips in a library animation clips.  */
	class LibraryAnimationClipsLoader : public FilePartLoader
	{
	private:
		typedef COLLADABU::hash_set<COLLADAFW::UniqueId> UniqueIdSet;

		/** The instance animation ids for the current animation clip. */
		UniqueIdSet mInstanceAnimationIds;

		/** The current animation clip being parsed. */
		COLLADAFW::AnimationClip* mAnimationClip;

	public:

		/** Constructor. */
		LibraryAnimationClipsLoader( IFilePartLoader* callingFilePartLoader );

		/** Destructor. */
		virtual ~LibraryAnimationClipsLoader();

		/** Returns the unique id of the current parsed object. */
		virtual const COLLADAFW::UniqueId& getUniqueId();

		/** Finishes loading a library animation clips. */
		virtual bool end__library_animation_clips();


		/** Creates a new animation clip. */
		virtual bool begin__animation_clip( const animation_clip__AttributeData& attributeData );

		/** Sends the animation clip to the writer. */
		virtual bool end__animation_clip();


		/** Add the referenced animation to the current animation clip. */
		virtual bool begin__instance_animation( const instance_animation__AttributeData& attributeData );
		
		/** We don't need to do anything here. */
		virtual bool end__instance_animation();

	private:

		/** Disable defult copy ctor. */
		LibraryAnimationClipsLoader( const LibraryAnimationClipsLoader& pre );

		/** Disable default assignment operator. */
		const LibraryAnimationClipsLoader& operator= ( const LibraryAnimationClipsLoader& pre );
	
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER_H__
