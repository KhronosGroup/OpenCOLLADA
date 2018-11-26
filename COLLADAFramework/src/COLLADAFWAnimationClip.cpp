#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWAnimationClip.h"


namespace COLLADAFW
{

	//------------------------------
	AnimationClip::AnimationClip ( const UniqueId& uniqueId )
		: ObjectTemplate<COLLADA_TYPE::ANIMATION_CLIP> ( uniqueId )
	{
	}
	
	//------------------------------
	AnimationClip::~AnimationClip()
	{
	}

} // namespace COLLADAFW
