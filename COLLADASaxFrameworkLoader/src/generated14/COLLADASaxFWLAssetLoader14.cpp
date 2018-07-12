/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLAssetLoader14.h"


namespace COLLADASaxFWL
{


bool AssetLoader14::end__asset()
{
SaxVirtualFunctionTest14(end__asset());
return mLoader->end__asset();
}


bool AssetLoader14::begin__contributor()
{
SaxVirtualFunctionTest14(begin__contributor());
return mLoader->begin__contributor();
}


bool AssetLoader14::end__contributor()
{
SaxVirtualFunctionTest14(end__contributor());
return mLoader->end__contributor();
}


bool AssetLoader14::begin__author()
{
SaxVirtualFunctionTest14(begin__author());
return mLoader->begin__author();
}


bool AssetLoader14::end__author()
{
SaxVirtualFunctionTest14(end__author());
return mLoader->end__author();
}


bool AssetLoader14::data__author( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__author(data, length));
return mLoader->data__author(data, length);
}


bool AssetLoader14::begin__authoring_tool()
{
SaxVirtualFunctionTest14(begin__authoring_tool());
return mLoader->begin__authoring_tool();
}


bool AssetLoader14::end__authoring_tool()
{
SaxVirtualFunctionTest14(end__authoring_tool());
return mLoader->end__authoring_tool();
}


bool AssetLoader14::data__authoring_tool( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__authoring_tool(data, length));
return mLoader->data__authoring_tool(data, length);
}


bool AssetLoader14::begin__comments()
{
SaxVirtualFunctionTest14(begin__comments());
return mLoader->begin__comments();
}


bool AssetLoader14::end__comments()
{
SaxVirtualFunctionTest14(end__comments());
return mLoader->end__comments();
}


bool AssetLoader14::data__comments( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__comments(data, length));
return mLoader->data__comments(data, length);
}


bool AssetLoader14::begin__copyright()
{
SaxVirtualFunctionTest14(begin__copyright());
return mLoader->begin__copyright();
}


bool AssetLoader14::end__copyright()
{
SaxVirtualFunctionTest14(end__copyright());
return mLoader->end__copyright();
}


bool AssetLoader14::data__copyright( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__copyright(data, length));
return mLoader->data__copyright(data, length);
}


bool AssetLoader14::begin__source_data()
{
SaxVirtualFunctionTest14(begin__source_data());
return mLoader->begin__source_data();
}


bool AssetLoader14::end__source_data()
{
SaxVirtualFunctionTest14(end__source_data());
return mLoader->end__source_data();
}


bool AssetLoader14::data__source_data( COLLADABU::URI value )
{
SaxVirtualFunctionTest14(data__source_data(value));
return mLoader->data__source_data(value);
}


bool AssetLoader14::begin__created()
{
SaxVirtualFunctionTest14(begin__created());
return mLoader->begin__created();
}


bool AssetLoader14::end__created()
{
SaxVirtualFunctionTest14(end__created());
return mLoader->end__created();
}


bool AssetLoader14::data__created( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__created(data, length));
return mLoader->data__created(data, length);
}


bool AssetLoader14::begin__keywords()
{
SaxVirtualFunctionTest14(begin__keywords());
return mLoader->begin__keywords();
}


bool AssetLoader14::end__keywords()
{
SaxVirtualFunctionTest14(end__keywords());
return mLoader->end__keywords();
}


bool AssetLoader14::data__keywords( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__keywords(data, length));
return mLoader->data__keywords(data, length);
}


bool AssetLoader14::begin__modified()
{
SaxVirtualFunctionTest14(begin__modified());
return mLoader->begin__modified();
}


bool AssetLoader14::end__modified()
{
SaxVirtualFunctionTest14(end__modified());
return mLoader->end__modified();
}


bool AssetLoader14::data__modified( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__modified(data, length));
return mLoader->data__modified(data, length);
}


bool AssetLoader14::begin__revision()
{
SaxVirtualFunctionTest14(begin__revision());
return mLoader->begin__revision();
}


bool AssetLoader14::end__revision()
{
SaxVirtualFunctionTest14(end__revision());
return mLoader->end__revision();
}


bool AssetLoader14::data__revision( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__revision(data, length));
return mLoader->data__revision(data, length);
}


bool AssetLoader14::begin__subject()
{
SaxVirtualFunctionTest14(begin__subject());
return mLoader->begin__subject();
}


bool AssetLoader14::end__subject()
{
SaxVirtualFunctionTest14(end__subject());
return mLoader->end__subject();
}


bool AssetLoader14::data__subject( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__subject(data, length));
return mLoader->data__subject(data, length);
}


bool AssetLoader14::begin__title()
{
SaxVirtualFunctionTest14(begin__title());
return mLoader->begin__title();
}


bool AssetLoader14::end__title()
{
SaxVirtualFunctionTest14(end__title());
return mLoader->end__title();
}


bool AssetLoader14::data__title( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest14(data__title(data, length));
return mLoader->data__title(data, length);
}


bool AssetLoader14::begin__unit( const COLLADASaxFWL14::unit__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__unit(attributeData));
COLLADASaxFWL::unit__AttributeData attrData;
attrData.meter = attributeData.meter;
attrData.name = attributeData.name;
return mLoader->begin__unit(attrData);
}


bool AssetLoader14::end__unit()
{
SaxVirtualFunctionTest14(end__unit());
return mLoader->end__unit();
}


bool AssetLoader14::begin__up_axis()
{
SaxVirtualFunctionTest14(begin__up_axis());
return mLoader->begin__up_axis();
}


bool AssetLoader14::end__up_axis()
{
SaxVirtualFunctionTest14(end__up_axis());
return mLoader->end__up_axis();
}


bool AssetLoader14::data__up_axis( const COLLADASaxFWL14::ENUM__UpAxisType value )
{
SaxVirtualFunctionTest14(data__up_axis(value));
COLLADASaxFWL::ENUM__UpAxisType val;
switch (value) {
case COLLADASaxFWL14::ENUM__UpAxisType__X_UP: val=COLLADASaxFWL::ENUM__UpAxisType__X_UP; break;
case COLLADASaxFWL14::ENUM__UpAxisType__Y_UP: val=COLLADASaxFWL::ENUM__UpAxisType__Y_UP; break;
case COLLADASaxFWL14::ENUM__UpAxisType__Z_UP: val=COLLADASaxFWL::ENUM__UpAxisType__Z_UP; break;
case COLLADASaxFWL14::ENUM__UpAxisType__COUNT: val=COLLADASaxFWL::ENUM__UpAxisType__INVALID; break;
case COLLADASaxFWL14::ENUM__UpAxisType__NOT_PRESENT: val=COLLADASaxFWL::ENUM__UpAxisType__NOT_PRESENT; break;
}
return mLoader->data__up_axis(val);
}


bool AssetLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool AssetLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
