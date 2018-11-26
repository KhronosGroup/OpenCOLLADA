#ifndef __COLLADAFW_ANIMATIONCLIP_H__
#define __COLLADAFW_ANIMATIONCLIP_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAFW
{
	class AnimationClip : public ObjectTemplate<COLLADA_TYPE::ANIMATION_CLIP>
	{
	private:
	/**
	* The original object id, if it in the original file format exist. 
	*/
	String mOriginalId;

	/** The list of unique animation ids of the instance animations in this clip. */
	UniqueIdArray mInstanceAnimationUniqueIds;

	/** The text string name of this element. Optional. */
	String mName; 

	public:

	/** Constructor. */
	AnimationClip ( const UniqueId& uniqueId );

	/** Destructor. */
	virtual ~AnimationClip();

	/**
	* The original object id, if it in the original file format exist. 
	*/
	const String& getOriginalId () const { return mOriginalId; }

	/**
	* The original object id, if it in the original file format exist. 
	*/
	void setOriginalId ( const String& val ) { mOriginalId = val; }

	/** The text string name of this element. Optional. */
	const String& getName () const { return mName; }

	/** The text string name of this element. Optional. */
	void setName ( const String& Name ) { mName = Name; }

	/** List of the unique ids of the instance animations in this clip. */
	const UniqueIdArray& getInstanceAnimationUniqueIds() const { return mInstanceAnimationUniqueIds; }

	/** List of the unique ids of the instance animations in this clip. */
	UniqueIdArray& getInstanceAnimationUniqueIds() { return mInstanceAnimationUniqueIds; }
	};
}

#endif // __COLLADAFW_ANIMATIONCLIP_H__
