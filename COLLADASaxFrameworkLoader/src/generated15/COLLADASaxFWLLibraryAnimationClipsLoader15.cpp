#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryAnimationClipsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryAnimationClipsLoader15::end__library_animation_clips()
{
SaxVirtualFunctionTest15(end__library_animation_clips());
return mLoader->end__library_animation_clips();
}


bool LibraryAnimationClipsLoader15::begin__animation_clip( const COLLADASaxFWL15::animation_clip__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__animation_clip(attributeData));
COLLADASaxFWL::animation_clip__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__animation_clip(attrData);
}


bool LibraryAnimationClipsLoader15::end__animation_clip()
{
SaxVirtualFunctionTest15(end__animation_clip());
return mLoader->end__animation_clip();
}


bool LibraryAnimationClipsLoader15::begin__instance_animation( const COLLADASaxFWL15::instance_animation__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_animation(attributeData));
COLLADASaxFWL::instance_animation__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
if ( (attributeData.present_attributes & COLLADASaxFWL15::instance_animation__AttributeData::ATTRIBUTE_URL_PRESENT) == COLLADASaxFWL15::instance_animation__AttributeData::ATTRIBUTE_URL_PRESENT ) {
    attrData.url = attributeData.url;
    attrData.present_attributes |= COLLADASaxFWL::instance_animation__AttributeData::ATTRIBUTE_URL_PRESENT;
}
return mLoader->begin__instance_animation(attrData);
}


bool LibraryAnimationClipsLoader15::end__instance_animation() {
SaxVirtualFunctionTest15(end__instance_animation());
return mLoader->end__instance_animation();
}



}
