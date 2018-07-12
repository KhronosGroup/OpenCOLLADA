/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLGeometryLoader15.h"


namespace COLLADASaxFWL
{


bool GeometryLoader15::begin__mesh()
{
SaxVirtualFunctionTest15(begin__mesh());
return mLoader->begin__mesh();
}


bool GeometryLoader15::end__geometry()
{
SaxVirtualFunctionTest15(end__geometry());
return mLoader->end__geometry();
}


bool GeometryLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool GeometryLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
