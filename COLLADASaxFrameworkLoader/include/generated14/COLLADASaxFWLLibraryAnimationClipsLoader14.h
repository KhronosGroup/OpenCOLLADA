#ifndef __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER14_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryAnimationClipsLoader.h"
#include "COLLADASaxFWLIParserImpl14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryAnimationClipsLoader14 : public IParserImpl14
{
private:
LibraryAnimationClipsLoader* mLoader;

public:
LibraryAnimationClipsLoader14(LibraryAnimationClipsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_animation_clips();

virtual bool begin__animation_clip( const COLLADASaxFWL14::animation_clip__AttributeData& attributeData );

virtual bool end__animation_clip();

virtual bool begin__instance_animation( const COLLADASaxFWL14::instance_animation__AttributeData& attributeData );

virtual bool end__instance_animation();


private:
/** Disable default copy ctor. */
LibraryAnimationClipsLoader14(const LibraryAnimationClipsLoader14&);
/** Disable default assignment operator. */
const LibraryAnimationClipsLoader14& operator=(const LibraryAnimationClipsLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYANIMATIONCLIPSLOADER14_H__
