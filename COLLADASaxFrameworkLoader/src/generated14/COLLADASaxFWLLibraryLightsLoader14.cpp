/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryLightsLoader14.h"


namespace COLLADASaxFWL
{


bool LibraryLightsLoader14::end__library_lights()
{
SaxVirtualFunctionTest14(end__library_lights());
return mLoader->end__library_lights();
}


bool LibraryLightsLoader14::begin__light( const COLLADASaxFWL14::light__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__light(attributeData));
COLLADASaxFWL::light__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__light(attrData);
}


bool LibraryLightsLoader14::end__light()
{
SaxVirtualFunctionTest14(end__light());
return mLoader->end__light();
}


bool LibraryLightsLoader14::begin__light__technique_common()
{
SaxVirtualFunctionTest14(begin__light__technique_common());
return mLoader->begin__light__technique_common();
}


bool LibraryLightsLoader14::end__light__technique_common()
{
SaxVirtualFunctionTest14(end__light__technique_common());
return mLoader->end__light__technique_common();
}


bool LibraryLightsLoader14::begin__light__technique_common__ambient()
{
SaxVirtualFunctionTest14(begin__light__technique_common__ambient());
return mLoader->begin__light__technique_common__ambient();
}


bool LibraryLightsLoader14::end__light__technique_common__ambient()
{
SaxVirtualFunctionTest14(end__light__technique_common__ambient());
return mLoader->end__light__technique_common__ambient();
}


bool LibraryLightsLoader14::begin__color____TargetableFloat3( const COLLADASaxFWL14::color____TargetableFloat3__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__color____TargetableFloat3(attributeData));
COLLADASaxFWL::color____TargetableFloat3__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__color____TargetableFloat3(attrData);
}


bool LibraryLightsLoader14::end__color____TargetableFloat3()
{
SaxVirtualFunctionTest14(end__color____TargetableFloat3());
return mLoader->end__color____TargetableFloat3();
}


bool LibraryLightsLoader14::data__color____TargetableFloat3( const float* data, size_t length )
{
SaxVirtualFunctionTest14(data__color____TargetableFloat3(data, length));
return mLoader->data__color____TargetableFloat3(data, length);
}


bool LibraryLightsLoader14::begin__directional()
{
SaxVirtualFunctionTest14(begin__directional());
return mLoader->begin__directional();
}


bool LibraryLightsLoader14::end__directional()
{
SaxVirtualFunctionTest14(end__directional());
return mLoader->end__directional();
}


bool LibraryLightsLoader14::begin__point()
{
SaxVirtualFunctionTest14(begin__point());
return mLoader->begin__point();
}


bool LibraryLightsLoader14::end__point()
{
SaxVirtualFunctionTest14(end__point());
return mLoader->end__point();
}


bool LibraryLightsLoader14::begin__constant_attenuation( const COLLADASaxFWL14::constant_attenuation__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__constant_attenuation(attributeData));
COLLADASaxFWL::constant_attenuation__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__constant_attenuation(attrData);
}


bool LibraryLightsLoader14::end__constant_attenuation()
{
SaxVirtualFunctionTest14(end__constant_attenuation());
return mLoader->end__constant_attenuation();
}


bool LibraryLightsLoader14::data__constant_attenuation( float value )
{
SaxVirtualFunctionTest14(data__constant_attenuation(value));
return mLoader->data__constant_attenuation(value);
}


bool LibraryLightsLoader14::begin__linear_attenuation( const COLLADASaxFWL14::linear_attenuation__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__linear_attenuation(attributeData));
COLLADASaxFWL::linear_attenuation__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__linear_attenuation(attrData);
}


bool LibraryLightsLoader14::end__linear_attenuation()
{
SaxVirtualFunctionTest14(end__linear_attenuation());
return mLoader->end__linear_attenuation();
}


bool LibraryLightsLoader14::data__linear_attenuation( float value )
{
SaxVirtualFunctionTest14(data__linear_attenuation(value));
return mLoader->data__linear_attenuation(value);
}


bool LibraryLightsLoader14::begin__quadratic_attenuation( const COLLADASaxFWL14::quadratic_attenuation__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__quadratic_attenuation(attributeData));
COLLADASaxFWL::quadratic_attenuation__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__quadratic_attenuation(attrData);
}


bool LibraryLightsLoader14::end__quadratic_attenuation()
{
SaxVirtualFunctionTest14(end__quadratic_attenuation());
return mLoader->end__quadratic_attenuation();
}


bool LibraryLightsLoader14::data__quadratic_attenuation( float value )
{
SaxVirtualFunctionTest14(data__quadratic_attenuation(value));
return mLoader->data__quadratic_attenuation(value);
}


bool LibraryLightsLoader14::begin__falloff_angle( const COLLADASaxFWL14::falloff_angle__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__falloff_angle(attributeData));
COLLADASaxFWL::falloff_angle__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__falloff_angle(attrData);
}


bool LibraryLightsLoader14::end__falloff_angle()
{
SaxVirtualFunctionTest14(end__falloff_angle());
return mLoader->end__falloff_angle();
}


bool LibraryLightsLoader14::data__falloff_angle( float value )
{
SaxVirtualFunctionTest14(data__falloff_angle(value));
return mLoader->data__falloff_angle(value);
}


bool LibraryLightsLoader14::begin__falloff_exponent( const COLLADASaxFWL14::falloff_exponent__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__falloff_exponent(attributeData));
COLLADASaxFWL::falloff_exponent__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__falloff_exponent(attrData);
}


bool LibraryLightsLoader14::end__falloff_exponent()
{
SaxVirtualFunctionTest14(end__falloff_exponent());
return mLoader->end__falloff_exponent();
}


bool LibraryLightsLoader14::data__falloff_exponent( float value )
{
SaxVirtualFunctionTest14(data__falloff_exponent(value));
return mLoader->data__falloff_exponent(value);
}


bool LibraryLightsLoader14::begin__spot()
{
SaxVirtualFunctionTest14(begin__spot());
return mLoader->begin__spot();
}


bool LibraryLightsLoader14::end__spot()
{
SaxVirtualFunctionTest14(end__spot());
return mLoader->end__spot();
}


bool LibraryLightsLoader14::begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData )
{
SaxVirtualFunctionTest14(begin__technique(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryLightsLoader14::end__technique()
{
SaxVirtualFunctionTest14(end__technique());
return mLoader->end__technique();
}



}
