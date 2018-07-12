/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryLightsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryLightsLoader15::end__library_lights()
{
SaxVirtualFunctionTest15(end__library_lights());
return mLoader->end__library_lights();
}


bool LibraryLightsLoader15::begin__light( const COLLADASaxFWL15::light__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__light(attributeData));
COLLADASaxFWL::light__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__light(attrData);
}


bool LibraryLightsLoader15::end__light()
{
SaxVirtualFunctionTest15(end__light());
return mLoader->end__light();
}


bool LibraryLightsLoader15::begin__light_type____technique_common()
{
SaxVirtualFunctionTest15(begin__light_type____technique_common());
return mLoader->begin__light__technique_common();
}


bool LibraryLightsLoader15::end__light_type____technique_common()
{
SaxVirtualFunctionTest15(end__light_type____technique_common());
return mLoader->end__light__technique_common();
}


bool LibraryLightsLoader15::begin__light__technique_common__ambient()
{
SaxVirtualFunctionTest15(begin__light__technique_common__ambient());
return mLoader->begin__light__technique_common__ambient();
}


bool LibraryLightsLoader15::end__light__technique_common__ambient()
{
SaxVirtualFunctionTest15(end__light__technique_common__ambient());
return mLoader->end__light__technique_common__ambient();
}


bool LibraryLightsLoader15::begin__color____targetable_float3_type( const COLLADASaxFWL15::color____targetable_float3_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__color____targetable_float3_type(attributeData));
COLLADASaxFWL::color____TargetableFloat3__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__color____TargetableFloat3(attrData);
}


bool LibraryLightsLoader15::end__color____targetable_float3_type()
{
SaxVirtualFunctionTest15(end__color____targetable_float3_type());
return mLoader->end__color____TargetableFloat3();
}


bool LibraryLightsLoader15::data__color____targetable_float3_type( const float* data, size_t length )
{
SaxVirtualFunctionTest15(data__color____targetable_float3_type(data, length));
return mLoader->data__color____TargetableFloat3(data, length);
}


bool LibraryLightsLoader15::begin__directional()
{
SaxVirtualFunctionTest15(begin__directional());
return mLoader->begin__directional();
}


bool LibraryLightsLoader15::end__directional()
{
SaxVirtualFunctionTest15(end__directional());
return mLoader->end__directional();
}


bool LibraryLightsLoader15::begin__point()
{
SaxVirtualFunctionTest15(begin__point());
return mLoader->begin__point();
}


bool LibraryLightsLoader15::end__point()
{
SaxVirtualFunctionTest15(end__point());
return mLoader->end__point();
}


bool LibraryLightsLoader15::begin__constant_attenuation( const COLLADASaxFWL15::constant_attenuation__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__constant_attenuation(attributeData));
COLLADASaxFWL::constant_attenuation__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__constant_attenuation(attrData);
}


bool LibraryLightsLoader15::end__constant_attenuation()
{
SaxVirtualFunctionTest15(end__constant_attenuation());
return mLoader->end__constant_attenuation();
}


bool LibraryLightsLoader15::data__constant_attenuation( float value )
{
SaxVirtualFunctionTest15(data__constant_attenuation(value));
return mLoader->data__constant_attenuation(value);
}


bool LibraryLightsLoader15::begin__linear_attenuation( const COLLADASaxFWL15::linear_attenuation__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__linear_attenuation(attributeData));
COLLADASaxFWL::linear_attenuation__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__linear_attenuation(attrData);
}


bool LibraryLightsLoader15::end__linear_attenuation()
{
SaxVirtualFunctionTest15(end__linear_attenuation());
return mLoader->end__linear_attenuation();
}


bool LibraryLightsLoader15::data__linear_attenuation( float value )
{
SaxVirtualFunctionTest15(data__linear_attenuation(value));
return mLoader->data__linear_attenuation(value);
}


bool LibraryLightsLoader15::begin__quadratic_attenuation( const COLLADASaxFWL15::quadratic_attenuation__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__quadratic_attenuation(attributeData));
COLLADASaxFWL::quadratic_attenuation__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__quadratic_attenuation(attrData);
}


bool LibraryLightsLoader15::end__quadratic_attenuation()
{
SaxVirtualFunctionTest15(end__quadratic_attenuation());
return mLoader->end__quadratic_attenuation();
}


bool LibraryLightsLoader15::data__quadratic_attenuation( float value )
{
SaxVirtualFunctionTest15(data__quadratic_attenuation(value));
return mLoader->data__quadratic_attenuation(value);
}


bool LibraryLightsLoader15::begin__falloff_angle( const COLLADASaxFWL15::falloff_angle__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__falloff_angle(attributeData));
COLLADASaxFWL::falloff_angle__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__falloff_angle(attrData);
}


bool LibraryLightsLoader15::end__falloff_angle()
{
SaxVirtualFunctionTest15(end__falloff_angle());
return mLoader->end__falloff_angle();
}


bool LibraryLightsLoader15::data__falloff_angle( float value )
{
SaxVirtualFunctionTest15(data__falloff_angle(value));
return mLoader->data__falloff_angle(value);
}


bool LibraryLightsLoader15::begin__falloff_exponent( const COLLADASaxFWL15::falloff_exponent__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__falloff_exponent(attributeData));
COLLADASaxFWL::falloff_exponent__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__falloff_exponent(attrData);
}


bool LibraryLightsLoader15::end__falloff_exponent()
{
SaxVirtualFunctionTest15(end__falloff_exponent());
return mLoader->end__falloff_exponent();
}


bool LibraryLightsLoader15::data__falloff_exponent( float value )
{
SaxVirtualFunctionTest15(data__falloff_exponent(value));
return mLoader->data__falloff_exponent(value);
}


bool LibraryLightsLoader15::begin__spot()
{
SaxVirtualFunctionTest15(begin__spot());
return mLoader->begin__spot();
}


bool LibraryLightsLoader15::end__spot()
{
SaxVirtualFunctionTest15(end__spot());
return mLoader->end__spot();
}


bool LibraryLightsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryLightsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
