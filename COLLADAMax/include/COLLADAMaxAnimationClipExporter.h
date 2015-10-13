
#ifndef __COLLADAMAX_ANIMATIONCLIPEXPORTER_H__
#define __COLLADAMAX_ANIMATIONCLIPEXPORTER_H__


#include "COLLADASWLibraryAnimationClips.h"

namespace COLLADAMax
{

	class AnimationClipExporter : public COLLADASW::LibraryAnimationClips
	{
	public:
		AnimationClipExporter(COLLADASW::StreamWriter* streamWriter);

		void open();
		void close();

		void addClip(const COLLADASW::ColladaAnimationClip& clip);
	};
}

#endif
