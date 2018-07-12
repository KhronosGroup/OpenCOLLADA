/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryNodesLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryNodesLoader15::begin__node( const COLLADASaxFWL15::node__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__node(attributeData));
COLLADASaxFWL::node__AttributeData attrData;
attrData.present_attributes = 0;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
attrData.sid = attributeData.sid;
switch (attributeData.type) {
case COLLADASaxFWL15::ENUM__node_enum__JOINT: attrData.type=COLLADASaxFWL::ENUM__NodeType__JOINT; break;
case COLLADASaxFWL15::ENUM__node_enum__NODE: attrData.type=COLLADASaxFWL::ENUM__NodeType__NODE; break;
case COLLADASaxFWL15::ENUM__node_enum__COUNT: attrData.type=COLLADASaxFWL::ENUM__NodeType__INVALID; break;
case COLLADASaxFWL15::ENUM__node_enum__NOT_PRESENT: attrData.type=COLLADASaxFWL::ENUM__NodeType__NOT_PRESENT; break;
}
if ( (attributeData.present_attributes & COLLADASaxFWL15::node__AttributeData::ATTRIBUTE_LAYER_PRESENT) == COLLADASaxFWL15::node__AttributeData::ATTRIBUTE_LAYER_PRESENT ) {
    attrData.layer = attributeData.layer;
    attrData.present_attributes |= COLLADASaxFWL::node__AttributeData::ATTRIBUTE_LAYER_PRESENT;
}
return mLoader->begin__node(attrData);
}


bool LibraryNodesLoader15::end__node()
{
SaxVirtualFunctionTest15(end__node());
return mLoader->end__node();
}


bool LibraryNodesLoader15::end__library_nodes()
{
SaxVirtualFunctionTest15(end__library_nodes());
return mLoader->end__library_nodes();
}


bool LibraryNodesLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryNodesLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
