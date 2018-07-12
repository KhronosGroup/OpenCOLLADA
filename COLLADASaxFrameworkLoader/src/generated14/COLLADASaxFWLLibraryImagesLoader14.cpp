/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryImagesLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryImagesLoader14::end__library_images()
{
SaxVirtualFunctionTest14(end__library_images());
return mLoader->end__library_images();
}


bool LibraryImagesLoader14::begin__image( const COLLADASaxFWL14::image__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__image(attributeData));
COLLADASaxFWL::image__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.sid = 0;
attrData.format = attributeData.format;
attrData.depth = attributeData.depth;
if ( (attributeData.present_attributes & COLLADASaxFWL14::image__AttributeData::ATTRIBUTE_HEIGHT_PRESENT) == COLLADASaxFWL14::image__AttributeData::ATTRIBUTE_HEIGHT_PRESENT ) {
    attrData.height = attributeData.height;
    attrData.present_attributes |= COLLADASaxFWL::image__AttributeData::ATTRIBUTE_HEIGHT_PRESENT;
}
if ( (attributeData.present_attributes & COLLADASaxFWL14::image__AttributeData::ATTRIBUTE_WIDTH_PRESENT) == COLLADASaxFWL14::image__AttributeData::ATTRIBUTE_WIDTH_PRESENT ) {
    attrData.width = attributeData.width;
    attrData.present_attributes |= COLLADASaxFWL::image__AttributeData::ATTRIBUTE_WIDTH_PRESENT;
}
return mLoader->begin__image(attrData);
}


bool LibraryImagesLoader14::end__image()
{
SaxVirtualFunctionTest14(end__image());
return mLoader->end__image();
}


bool LibraryImagesLoader14::begin__init_from____anyURI()
{
SaxVirtualFunctionTest14(begin__init_from____anyURI());
return mLoader->begin__init_from____anyURI();
}


bool LibraryImagesLoader14::end__init_from____anyURI()
{
SaxVirtualFunctionTest14(end__init_from____anyURI());
return mLoader->end__init_from____anyURI();
}


bool LibraryImagesLoader14::data__init_from____anyURI( COLLADABU::URI value )
{
SaxVirtualFunctionTest14(data__init_from____anyURI(value));
return mLoader->data__init_from____anyURI(value);
}


bool LibraryImagesLoader14::begin__data()
{
SaxVirtualFunctionTest14(begin__data());
return mLoader->begin__data();
}


bool LibraryImagesLoader14::end__data()
{
SaxVirtualFunctionTest14(end__data());
return mLoader->end__data();
}


bool LibraryImagesLoader14::data__data( const uint8* data, size_t length )
{
SaxVirtualFunctionTest14(data__data(data, length));
return mLoader->data__data(data, length);
}


bool LibraryImagesLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryImagesLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
