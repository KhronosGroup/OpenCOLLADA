/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLAssetLoader15.h"


namespace COLLADASaxFWL
{


bool AssetLoader15::end__asset()
{
SaxVirtualFunctionTest15(end__asset());
return mLoader->end__asset();
}


bool AssetLoader15::begin__contributor()
{
SaxVirtualFunctionTest15(begin__contributor());
return mLoader->begin__contributor();
}


bool AssetLoader15::end__contributor()
{
SaxVirtualFunctionTest15(end__contributor());
return mLoader->end__contributor();
}


bool AssetLoader15::begin__author()
{
SaxVirtualFunctionTest15(begin__author());
return mLoader->begin__author();
}


bool AssetLoader15::end__author()
{
SaxVirtualFunctionTest15(end__author());
return mLoader->end__author();
}


bool AssetLoader15::data__author( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__author(data, length));
return mLoader->data__author(data, length);
}


bool AssetLoader15::begin__authoring_tool()
{
SaxVirtualFunctionTest15(begin__authoring_tool());
return mLoader->begin__authoring_tool();
}


bool AssetLoader15::end__authoring_tool()
{
SaxVirtualFunctionTest15(end__authoring_tool());
return mLoader->end__authoring_tool();
}


bool AssetLoader15::data__authoring_tool( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__authoring_tool(data, length));
return mLoader->data__authoring_tool(data, length);
}


bool AssetLoader15::begin__comments()
{
SaxVirtualFunctionTest15(begin__comments());
return mLoader->begin__comments();
}


bool AssetLoader15::end__comments()
{
SaxVirtualFunctionTest15(end__comments());
return mLoader->end__comments();
}


bool AssetLoader15::data__comments( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__comments(data, length));
return mLoader->data__comments(data, length);
}


bool AssetLoader15::begin__copyright()
{
SaxVirtualFunctionTest15(begin__copyright());
return mLoader->begin__copyright();
}


bool AssetLoader15::end__copyright()
{
SaxVirtualFunctionTest15(end__copyright());
return mLoader->end__copyright();
}


bool AssetLoader15::data__copyright( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__copyright(data, length));
return mLoader->data__copyright(data, length);
}


bool AssetLoader15::begin__source_data()
{
SaxVirtualFunctionTest15(begin__source_data());
return mLoader->begin__source_data();
}


bool AssetLoader15::end__source_data()
{
SaxVirtualFunctionTest15(end__source_data());
return mLoader->end__source_data();
}


bool AssetLoader15::data__source_data( COLLADABU::URI value )
{
SaxVirtualFunctionTest15(data__source_data(value));
return mLoader->data__source_data(value);
}


bool AssetLoader15::begin__created()
{
SaxVirtualFunctionTest15(begin__created());
return mLoader->begin__created();
}


bool AssetLoader15::end__created()
{
SaxVirtualFunctionTest15(end__created());
return mLoader->end__created();
}


bool AssetLoader15::data__created( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__created(data, length));
return mLoader->data__created(data, length);
}


bool AssetLoader15::begin__keywords()
{
SaxVirtualFunctionTest15(begin__keywords());
return mLoader->begin__keywords();
}


bool AssetLoader15::end__keywords()
{
SaxVirtualFunctionTest15(end__keywords());
return mLoader->end__keywords();
}


bool AssetLoader15::data__keywords( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__keywords(data, length));
return mLoader->data__keywords(data, length);
}


bool AssetLoader15::begin__modified()
{
SaxVirtualFunctionTest15(begin__modified());
return mLoader->begin__modified();
}


bool AssetLoader15::end__modified()
{
SaxVirtualFunctionTest15(end__modified());
return mLoader->end__modified();
}


bool AssetLoader15::data__modified( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__modified(data, length));
return mLoader->data__modified(data, length);
}


bool AssetLoader15::begin__revision()
{
SaxVirtualFunctionTest15(begin__revision());
return mLoader->begin__revision();
}


bool AssetLoader15::end__revision()
{
SaxVirtualFunctionTest15(end__revision());
return mLoader->end__revision();
}


bool AssetLoader15::data__revision( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__revision(data, length));
return mLoader->data__revision(data, length);
}


bool AssetLoader15::begin__subject()
{
SaxVirtualFunctionTest15(begin__subject());
return mLoader->begin__subject();
}


bool AssetLoader15::end__subject()
{
SaxVirtualFunctionTest15(end__subject());
return mLoader->end__subject();
}


bool AssetLoader15::data__subject( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__subject(data, length));
return mLoader->data__subject(data, length);
}


bool AssetLoader15::begin__title()
{
SaxVirtualFunctionTest15(begin__title());
return mLoader->begin__title();
}


bool AssetLoader15::end__title()
{
SaxVirtualFunctionTest15(end__title());
return mLoader->end__title();
}


bool AssetLoader15::data__title( const ParserChar* data, size_t length )
{
SaxVirtualFunctionTest15(data__title(data, length));
return mLoader->data__title(data, length);
}


bool AssetLoader15::begin__unit( const COLLADASaxFWL15::unit__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__unit(attributeData));
COLLADASaxFWL::unit__AttributeData attrData;
attrData.meter = attributeData.meter;
attrData.name = attributeData.name;
return mLoader->begin__unit(attrData);
}


bool AssetLoader15::end__unit()
{
SaxVirtualFunctionTest15(end__unit());
return mLoader->end__unit();
}


bool AssetLoader15::begin__up_axis()
{
SaxVirtualFunctionTest15(begin__up_axis());
return mLoader->begin__up_axis();
}


bool AssetLoader15::end__up_axis()
{
SaxVirtualFunctionTest15(end__up_axis());
return mLoader->end__up_axis();
}


bool AssetLoader15::data__up_axis( const COLLADASaxFWL15::ENUM__up_axis_enum value )
{
SaxVirtualFunctionTest15(data__up_axis(value));
COLLADASaxFWL::ENUM__UpAxisType val;
switch (value) {
case COLLADASaxFWL15::ENUM__up_axis_enum__X_UP: val=COLLADASaxFWL::ENUM__UpAxisType__X_UP; break;
case COLLADASaxFWL15::ENUM__up_axis_enum__Y_UP: val=COLLADASaxFWL::ENUM__UpAxisType__Y_UP; break;
case COLLADASaxFWL15::ENUM__up_axis_enum__Z_UP: val=COLLADASaxFWL::ENUM__UpAxisType__Z_UP; break;
case COLLADASaxFWL15::ENUM__up_axis_enum__COUNT: val=COLLADASaxFWL::ENUM__UpAxisType__INVALID; break;
case COLLADASaxFWL15::ENUM__up_axis_enum__NOT_PRESENT: val=COLLADASaxFWL::ENUM__UpAxisType__NOT_PRESENT; break;
}
return mLoader->data__up_axis(val);
}


bool AssetLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool AssetLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
