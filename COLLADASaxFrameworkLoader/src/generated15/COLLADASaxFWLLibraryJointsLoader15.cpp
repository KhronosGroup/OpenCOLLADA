/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryJointsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryJointsLoader15::end__library_joints()
{
SaxVirtualFunctionTest15(end__library_joints());
return mLoader->end__library_joints();
}


bool LibraryJointsLoader15::begin__joint( const COLLADASaxFWL15::joint__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__joint(attributeData));
COLLADASaxFWL::joint__AttributeData attrData;
attrData.id = attributeData.id;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
return mLoader->begin__joint(attrData);
}


bool LibraryJointsLoader15::end__joint()
{
SaxVirtualFunctionTest15(end__joint());
return mLoader->end__joint();
}


bool LibraryJointsLoader15::begin__prismatic( const COLLADASaxFWL15::prismatic__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__prismatic(attributeData));
COLLADASaxFWL::prismatic__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__prismatic(attrData);
}


bool LibraryJointsLoader15::end__prismatic()
{
SaxVirtualFunctionTest15(end__prismatic());
return mLoader->end__prismatic();
}


bool LibraryJointsLoader15::begin__axis____axis_type( const COLLADASaxFWL15::axis____axis_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__axis____axis_type(attributeData));
COLLADASaxFWL::axis____axis_type__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
return mLoader->begin__axis____axis_type(attrData);
}


bool LibraryJointsLoader15::end__axis____axis_type()
{
SaxVirtualFunctionTest15(end__axis____axis_type());
return mLoader->end__axis____axis_type();
}


bool LibraryJointsLoader15::data__axis____axis_type( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__axis____axis_type(data, length));
return mLoader->data__axis____axis_type(data, length);
}


bool LibraryJointsLoader15::begin__limits____joint_limits_type()
{
SaxVirtualFunctionTest15(begin__limits____joint_limits_type());
return mLoader->begin__limits____joint_limits_type();
}


bool LibraryJointsLoader15::end__limits____joint_limits_type()
{
SaxVirtualFunctionTest15(end__limits____joint_limits_type());
return mLoader->end__limits____joint_limits_type();
}


bool LibraryJointsLoader15::begin__min____minmax_type( const COLLADASaxFWL15::min____minmax_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__min____minmax_type(attributeData));
COLLADASaxFWL::min____minmax_type__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
return mLoader->begin__min____minmax_type(attrData);
}


bool LibraryJointsLoader15::end__min____minmax_type()
{
SaxVirtualFunctionTest15(end__min____minmax_type());
return mLoader->end__min____minmax_type();
}


bool LibraryJointsLoader15::data__min____minmax_type( float value )
{
SaxVirtualFunctionTest15(data__min____minmax_type(value));
return mLoader->data__min____minmax_type(value);
}


bool LibraryJointsLoader15::begin__max____minmax_type( const COLLADASaxFWL15::max____minmax_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__max____minmax_type(attributeData));
COLLADASaxFWL::max____minmax_type__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
return mLoader->begin__max____minmax_type(attrData);
}


bool LibraryJointsLoader15::end__max____minmax_type()
{
SaxVirtualFunctionTest15(end__max____minmax_type());
return mLoader->end__max____minmax_type();
}


bool LibraryJointsLoader15::data__max____minmax_type( float value )
{
SaxVirtualFunctionTest15(data__max____minmax_type(value));
return mLoader->data__max____minmax_type(value);
}


bool LibraryJointsLoader15::begin__revolute( const COLLADASaxFWL15::revolute__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__revolute(attributeData));
COLLADASaxFWL::revolute__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__revolute(attrData);
}


bool LibraryJointsLoader15::end__revolute()
{
SaxVirtualFunctionTest15(end__revolute());
return mLoader->end__revolute();
}


bool LibraryJointsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryJointsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
