/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLForceFieldLoader15.h"


namespace COLLADASaxFWL
{


bool ForceFieldLoader15::begin__force_field( const COLLADASaxFWL15::force_field__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__force_field(attributeData));
COLLADASaxFWL::force_field__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__force_field(attrData);
}


bool ForceFieldLoader15::end__force_field()
{
SaxVirtualFunctionTest15(end__force_field());
return mLoader->end__force_field();
}



}
