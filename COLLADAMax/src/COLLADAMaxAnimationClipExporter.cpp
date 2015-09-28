#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxAnimationClipExporter.h"

namespace COLLADAMax
{

	AnimationClipExporter::AnimationClipExporter(COLLADASW::StreamWriter* streamWriter) :
		LibraryAnimationClips(streamWriter)
	{}

	void AnimationClipExporter::open() {
		openLibrary();
	}
	void AnimationClipExporter::close() {
		closeLibrary();
	}

	void AnimationClipExporter::addClip(const COLLADASW::ColladaAnimationClip& clip) {
		addAnimationClip(clip);
	}

}
