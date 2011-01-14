/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLForceFieldLoader14.h"


namespace COLLADASaxFWL
{


bool ForceFieldLoader14::begin__force_field( const COLLADASaxFWL14::force_field__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__force_field(attributeData));
COLLADASaxFWL::force_field__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__force_field(attrData);
}


bool ForceFieldLoader14::end__force_field()
{
SaxVirtualFunctionTest14(end__force_field());
return mLoader->end__force_field();
}



}
