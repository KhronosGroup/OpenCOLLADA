/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryNodesLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryNodesLoader14::begin__node( const COLLADASaxFWL14::node__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__node(attributeData));
COLLADASaxFWL::node__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
switch (attributeData.type) {
case COLLADASaxFWL14::ENUM__NodeType__JOINT: attrData.type=COLLADASaxFWL::ENUM__NodeType__JOINT; break;
case COLLADASaxFWL14::ENUM__NodeType__NODE: attrData.type=COLLADASaxFWL::ENUM__NodeType__NODE; break;
case COLLADASaxFWL14::ENUM__NodeType__COUNT: attrData.type=COLLADASaxFWL::ENUM__NodeType__INVALID; break;
case COLLADASaxFWL14::ENUM__NodeType__NOT_PRESENT: attrData.type=COLLADASaxFWL::ENUM__NodeType__NOT_PRESENT; break;
}
if ( (attributeData.present_attributes & COLLADASaxFWL14::node__AttributeData::ATTRIBUTE_LAYER_PRESENT) == COLLADASaxFWL14::node__AttributeData::ATTRIBUTE_LAYER_PRESENT ) {
    attrData.layer = attributeData.layer;
    attrData.present_attributes |= COLLADASaxFWL::node__AttributeData::ATTRIBUTE_LAYER_PRESENT;
}
return mLoader->begin__node(attrData);
}


bool LibraryNodesLoader14::end__node()
{
SaxVirtualFunctionTest14(end__node());
return mLoader->end__node();
}


bool LibraryNodesLoader14::end__library_nodes()
{
SaxVirtualFunctionTest14(end__library_nodes());
return mLoader->end__library_nodes();
}


bool LibraryNodesLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryNodesLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
