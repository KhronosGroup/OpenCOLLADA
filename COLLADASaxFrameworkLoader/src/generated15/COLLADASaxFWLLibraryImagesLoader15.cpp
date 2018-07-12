/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryImagesLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryImagesLoader15::end__library_images()
{
SaxVirtualFunctionTest15(end__library_images());
return mLoader->end__library_images();
}


bool LibraryImagesLoader15::begin__image____image_type( const COLLADASaxFWL15::image____image_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__image____image_type(attributeData));
COLLADASaxFWL::image__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
attrData.format = 0;
attrData.depth = 0;
attrData.width = 0;
attrData.height = 0;
return mLoader->begin__image(attrData);
}


bool LibraryImagesLoader15::end__image____image_type()
{
SaxVirtualFunctionTest15(end__image____image_type());
return mLoader->end__image();
}


bool LibraryImagesLoader15::begin__ref____anyURI()
{
SaxVirtualFunctionTest15(begin__ref____anyURI());
return mLoader->begin__init_from____anyURI();
}


bool LibraryImagesLoader15::end__ref____anyURI()
{
SaxVirtualFunctionTest15(end__ref____anyURI());
return mLoader->end__init_from____anyURI();
}


bool LibraryImagesLoader15::data__ref____anyURI( COLLADABU::URI value )
{
SaxVirtualFunctionTest15(data__ref____anyURI(value));
return mLoader->data__init_from____anyURI(value);
}


bool LibraryImagesLoader15::begin__binary__hex( const COLLADASaxFWL15::binary__hex__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__binary__hex(attributeData));
return mLoader->begin__data();
}


bool LibraryImagesLoader15::end__binary__hex()
{
SaxVirtualFunctionTest15(end__binary__hex());
return mLoader->end__data();
}


bool LibraryImagesLoader15::data__binary__hex( const uint8* data, size_t length )
{
SaxVirtualFunctionTest15(data__binary__hex(data, length));
return mLoader->data__data(data, length);
}


bool LibraryImagesLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryImagesLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
