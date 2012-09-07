/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSplineLoader14.h"


namespace COLLADASaxFWL
{


bool SplineLoader14::begin__source( const COLLADASaxFWL14::source__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__source(attributeData));
COLLADASaxFWL::source__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__source(attrData);
}


bool SplineLoader14::end__source()
{
SaxVirtualFunctionTest14(end__source());
return mLoader->end__source();
}


bool SplineLoader14::end__spline()
{
SaxVirtualFunctionTest14(end__spline());
return mLoader->end__spline();
}

bool SplineLoader14::begin__input____InputLocal( const COLLADASaxFWL14::input____InputLocal__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__input____InputLocal(attributeData));
COLLADASaxFWL::input____InputLocal__AttributeData attrData;
attrData.semantic = attributeData.semantic;
attrData.source = attributeData.source;
return mLoader->begin__input____InputLocal(attrData);
}


bool SplineLoader14::end__input____InputLocal()
{
SaxVirtualFunctionTest14(end__input____InputLocal());
return mLoader->end__input____InputLocal();
}

bool SplineLoader14::begin__control_vertices()
{
    SaxVirtualFunctionTest14(begin__control_vertices());
    return mLoader->begin__control_vertices();
}

bool SplineLoader14::end__control_vertices()
{
    SaxVirtualFunctionTest14(begin__control_vertices());
    return mLoader->end__control_vertices();
}


bool SplineLoader14::begin__Name_array( const COLLADASaxFWL14::Name_array__AttributeData& attributeData )
{
    SaxVirtualFunctionTest14(begin__Name_array(attributeData));
    COLLADASaxFWL::Name_array__AttributeData attrData;
    attrData.present_attributes = 0;
    attrData.id = attributeData.id;
    attrData.name = attributeData.name;
    if ( (attributeData.present_attributes & COLLADASaxFWL14::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT) == COLLADASaxFWL14::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT ) {
        attrData.count = attributeData.count;
        attrData.present_attributes |= COLLADASaxFWL::Name_array__AttributeData::ATTRIBUTE_COUNT_PRESENT;
    }
    return mLoader->begin__Name_array(attrData);
}


bool SplineLoader14::end__Name_array()
{
    SaxVirtualFunctionTest14(end__Name_array());
    return mLoader->end__Name_array();
}


bool SplineLoader14::data__Name_array( const ParserString* data, size_t length )
{
    SaxVirtualFunctionTest14(data__Name_array(data, length));
    return mLoader->data__Name_array(data, length);
}


}
