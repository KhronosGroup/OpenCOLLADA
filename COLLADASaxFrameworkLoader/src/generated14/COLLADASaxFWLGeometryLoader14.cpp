/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLGeometryLoader14.h"


namespace COLLADASaxFWL
{


bool GeometryLoader14::begin__mesh()
{
SaxVirtualFunctionTest14(begin__mesh());
return mLoader->begin__mesh();
}

bool GeometryLoader14::begin__spline( const COLLADASaxFWL14::spline__AttributeData& attributeData )
{
    SaxVirtualFunctionTest14(begin__spline( attributeData ));
    COLLADASaxFWL::spline__AttributeData attrData;
    attrData.closed = attributeData.closed;
    return mLoader->begin__spline( attrData );
}


bool GeometryLoader14::end__geometry()
{
SaxVirtualFunctionTest14(end__geometry());
return mLoader->end__geometry();
}


bool GeometryLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool GeometryLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
