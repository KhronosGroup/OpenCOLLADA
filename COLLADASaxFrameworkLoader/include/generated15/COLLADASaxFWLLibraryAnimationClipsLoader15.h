#ifndef __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER15_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryAnimationClipsLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryAnimationClipsLoader15 : public IParserImpl15
{
private:
LibraryAnimationClipsLoader* mLoader;

public:
LibraryAnimationClipsLoader15(LibraryAnimationClipsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_animation_clips();

virtual bool begin__animation_clip( const COLLADASaxFWL15::animation_clip__AttributeData& attributeData );

virtual bool end__animation_clip();

virtual bool begin__instance_animation( const COLLADASaxFWL15::instance_animation__AttributeData& attributeData );

virtual bool end__instance_animation();


private:
/** Disable default copy ctor. */
LibraryAnimationClipsLoader15(const LibraryAnimationClipsLoader15&);
/** Disable default assignment operator. */
const LibraryAnimationClipsLoader15& operator=(const LibraryAnimationClipsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER15_H__