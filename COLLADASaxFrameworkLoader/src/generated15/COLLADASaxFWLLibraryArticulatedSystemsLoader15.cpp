/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryArticulatedSystemsLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryArticulatedSystemsLoader15::end__library_articulated_systems()
{
SaxVirtualFunctionTest15(end__library_articulated_systems());
return mLoader->end__library_articulated_systems();
}


bool LibraryArticulatedSystemsLoader15::begin__articulated_system( const COLLADASaxFWL15::articulated_system__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__articulated_system(attributeData));
COLLADASaxFWL::articulated_system__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__articulated_system(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__articulated_system()
{
SaxVirtualFunctionTest15(end__articulated_system());
return mLoader->end__articulated_system();
}


bool LibraryArticulatedSystemsLoader15::begin__kinematics()
{
SaxVirtualFunctionTest15(begin__kinematics());
return mLoader->begin__kinematics();
}


bool LibraryArticulatedSystemsLoader15::end__kinematics()
{
SaxVirtualFunctionTest15(end__kinematics());
return mLoader->end__kinematics();
}


bool LibraryArticulatedSystemsLoader15::begin__instance_kinematics_model( const COLLADASaxFWL15::instance_kinematics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_kinematics_model(attributeData));
COLLADASaxFWL::instance_kinematics_model__AttributeData attrData;
attrData.present_attributes = attributeData.present_attributes;
attrData.url = attributeData.url;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
return mLoader->begin__instance_kinematics_model(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__instance_kinematics_model()
{
SaxVirtualFunctionTest15(end__instance_kinematics_model());
return mLoader->end__instance_kinematics_model();
}


bool LibraryArticulatedSystemsLoader15::begin__newparam____kinematics_newparam_type( const COLLADASaxFWL15::newparam____kinematics_newparam_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__newparam____kinematics_newparam_type(attributeData));
COLLADASaxFWL::newparam____kinematics_newparam_type__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__newparam____kinematics_newparam_type(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__newparam____kinematics_newparam_type()
{
SaxVirtualFunctionTest15(end__newparam____kinematics_newparam_type());
return mLoader->end__newparam____kinematics_newparam_type();
}


bool LibraryArticulatedSystemsLoader15::begin__bind____kinematics_bind_type( const COLLADASaxFWL15::bind____kinematics_bind_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__bind____kinematics_bind_type(attributeData));
COLLADASaxFWL::bind____kinematics_bind_type__AttributeData attrData;
attrData.symbol = attributeData.symbol;
return mLoader->begin__bind____kinematics_bind_type(attrData);
}


bool LibraryArticulatedSystemsLoader15::begin__float____float_type()
{
SaxVirtualFunctionTest15(begin__float____float_type());
return mLoader->begin__float();
}


bool LibraryArticulatedSystemsLoader15::end__float____float_type()
{
SaxVirtualFunctionTest15(end__float____float_type());
return mLoader->end__float();
}


bool LibraryArticulatedSystemsLoader15::data__float____float_type( float value )
{
SaxVirtualFunctionTest15(data__float____float_type(value));
return mLoader->data__float(value);
}


bool LibraryArticulatedSystemsLoader15::begin__int____int_type()
{
SaxVirtualFunctionTest15(begin__int____int_type());
return mLoader->begin__int();
}


bool LibraryArticulatedSystemsLoader15::end__int____int_type()
{
SaxVirtualFunctionTest15(end__int____int_type());
return mLoader->end__int();
}


bool LibraryArticulatedSystemsLoader15::data__int____int_type( int value )
{
SaxVirtualFunctionTest15(data__int____int_type(value));
return mLoader->data__int(value);
}


bool LibraryArticulatedSystemsLoader15::begin__bool()
{
SaxVirtualFunctionTest15(begin__bool());
return mLoader->begin__bool();
}


bool LibraryArticulatedSystemsLoader15::end__bool()
{
SaxVirtualFunctionTest15(end__bool());
return mLoader->end__bool();
}


bool LibraryArticulatedSystemsLoader15::data__bool( bool value )
{
SaxVirtualFunctionTest15(data__bool(value));
return mLoader->data__bool(value);
}


bool LibraryArticulatedSystemsLoader15::begin__SIDREF()
{
SaxVirtualFunctionTest15(begin__SIDREF());
return mLoader->begin__SIDREF();
}


bool LibraryArticulatedSystemsLoader15::end__SIDREF()
{
SaxVirtualFunctionTest15(end__SIDREF());
return mLoader->end__SIDREF();
}


bool LibraryArticulatedSystemsLoader15::data__SIDREF( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest15(data__SIDREF(value, length));
return mLoader->data__SIDREF(value, length);
}


bool LibraryArticulatedSystemsLoader15::end__bind____kinematics_bind_type()
{
SaxVirtualFunctionTest15(end__bind____kinematics_bind_type());
return mLoader->end__bind____kinematics_bind_type();
}


bool LibraryArticulatedSystemsLoader15::begin__param____kinematics_param_type( const COLLADASaxFWL15::param____kinematics_param_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__param____kinematics_param_type(attributeData));
COLLADASaxFWL::param____kinematics_param_type__AttributeData attrData;
attrData.ref = attributeData.ref;
return mLoader->begin__param____kinematics_param_type(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__param____kinematics_param_type()
{
SaxVirtualFunctionTest15(end__param____kinematics_param_type());
return mLoader->end__param____kinematics_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__setparam____kinematics_setparam_type( const COLLADASaxFWL15::setparam____kinematics_setparam_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__setparam____kinematics_setparam_type(attributeData));
COLLADASaxFWL::setparam____kinematics_setparam_type__AttributeData attrData;
attrData.ref = attributeData.ref;
return mLoader->begin__setparam____kinematics_setparam_type(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__setparam____kinematics_setparam_type()
{
SaxVirtualFunctionTest15(end__setparam____kinematics_setparam_type());
return mLoader->end__setparam____kinematics_setparam_type();
}


bool LibraryArticulatedSystemsLoader15::begin__technique_common____kinematics_technique_type()
{
SaxVirtualFunctionTest15(begin__technique_common____kinematics_technique_type());
return mLoader->begin__technique_common____kinematics_technique_type();
}


bool LibraryArticulatedSystemsLoader15::end__technique_common____kinematics_technique_type()
{
SaxVirtualFunctionTest15(end__technique_common____kinematics_technique_type());
return mLoader->end__technique_common____kinematics_technique_type();
}


bool LibraryArticulatedSystemsLoader15::begin__axis_info____kinematics_axis_info_type( const COLLADASaxFWL15::axis_info____kinematics_axis_info_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__axis_info____kinematics_axis_info_type(attributeData));
COLLADASaxFWL::axis_info____kinematics_axis_info_type__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
attrData.axis = attributeData.axis;
return mLoader->begin__axis_info____kinematics_axis_info_type(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__axis_info____kinematics_axis_info_type()
{
SaxVirtualFunctionTest15(end__axis_info____kinematics_axis_info_type());
return mLoader->end__axis_info____kinematics_axis_info_type();
}


bool LibraryArticulatedSystemsLoader15::begin__active()
{
SaxVirtualFunctionTest15(begin__active());
return mLoader->begin__active();
}


bool LibraryArticulatedSystemsLoader15::end__active()
{
SaxVirtualFunctionTest15(end__active());
return mLoader->end__active();
}


bool LibraryArticulatedSystemsLoader15::begin__locked()
{
SaxVirtualFunctionTest15(begin__locked());
return mLoader->begin__locked();
}


bool LibraryArticulatedSystemsLoader15::end__locked()
{
SaxVirtualFunctionTest15(end__locked());
return mLoader->end__locked();
}


bool LibraryArticulatedSystemsLoader15::begin__index( const COLLADASaxFWL15::index__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__index(attributeData));
COLLADASaxFWL::index__AttributeData attrData;
attrData.semantic = attributeData.semantic;
return mLoader->begin__index(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__index()
{
SaxVirtualFunctionTest15(end__index());
return mLoader->end__index();
}


bool LibraryArticulatedSystemsLoader15::begin__limits____kinematics_limits_type()
{
SaxVirtualFunctionTest15(begin__limits____kinematics_limits_type());
return mLoader->begin__limits____kinematics_limits_type();
}


bool LibraryArticulatedSystemsLoader15::end__limits____kinematics_limits_type()
{
SaxVirtualFunctionTest15(end__limits____kinematics_limits_type());
return mLoader->end__limits____kinematics_limits_type();
}


bool LibraryArticulatedSystemsLoader15::begin__min____common_float_or_param_type()
{
SaxVirtualFunctionTest15(begin__min____common_float_or_param_type());
return mLoader->begin__min____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__min____common_float_or_param_type()
{
SaxVirtualFunctionTest15(end__min____common_float_or_param_type());
return mLoader->end__min____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__max____common_float_or_param_type()
{
SaxVirtualFunctionTest15(begin__max____common_float_or_param_type());
return mLoader->begin__max____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__max____common_float_or_param_type()
{
SaxVirtualFunctionTest15(end__max____common_float_or_param_type());
return mLoader->end__max____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__frame_origin( const COLLADASaxFWL15::frame_origin__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__frame_origin(attributeData));
COLLADASaxFWL::frame__AttributeData attrData;
attrData.link = attributeData.link;
return mLoader->begin__frame_origin(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__frame_origin()
{
SaxVirtualFunctionTest15(end__frame_origin());
return mLoader->end__frame_origin();
}


bool LibraryArticulatedSystemsLoader15::begin__frame_tip( const COLLADASaxFWL15::frame_tip__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__frame_tip(attributeData));
COLLADASaxFWL::frame__AttributeData attrData;
attrData.link = attributeData.link;
return mLoader->begin__frame_tip(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__frame_tip()
{
SaxVirtualFunctionTest15(end__frame_tip());
return mLoader->end__frame_tip();
}


bool LibraryArticulatedSystemsLoader15::begin__frame_tcp( const COLLADASaxFWL15::frame_tcp__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__frame_tcp(attributeData));
COLLADASaxFWL::frame__AttributeData attrData;
attrData.link = attributeData.link;
return mLoader->begin__frame_tcp(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__frame_tcp()
{
SaxVirtualFunctionTest15(end__frame_tcp());
return mLoader->end__frame_tcp();
}


bool LibraryArticulatedSystemsLoader15::begin__frame_object( const COLLADASaxFWL15::frame_object__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__frame_object(attributeData));
COLLADASaxFWL::frame__AttributeData attrData;
attrData.link = attributeData.link;
return mLoader->begin__frame_object(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__frame_object()
{
SaxVirtualFunctionTest15(end__frame_object());
return mLoader->end__frame_object();
}


bool LibraryArticulatedSystemsLoader15::begin__motion()
{
SaxVirtualFunctionTest15(begin__motion());
return mLoader->begin__motion();
}


bool LibraryArticulatedSystemsLoader15::end__motion()
{
SaxVirtualFunctionTest15(end__motion());
return mLoader->end__motion();
}


bool LibraryArticulatedSystemsLoader15::begin__instance_articulated_system( const COLLADASaxFWL15::instance_articulated_system__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_articulated_system(attributeData));
COLLADASaxFWL::instance_articulated_system__AttributeData attrData;
attrData.present_attributes = attributeData.present_attributes;
attrData.sid = attributeData.sid;
attrData.url = attributeData.url;
attrData.name = attributeData.name;
return mLoader->begin__instance_articulated_system(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__instance_articulated_system()
{
SaxVirtualFunctionTest15(end__instance_articulated_system());
return mLoader->end__instance_articulated_system();
}


bool LibraryArticulatedSystemsLoader15::begin__technique_common____motion_technique_type()
{
SaxVirtualFunctionTest15(begin__technique_common____motion_technique_type());
return mLoader->begin__technique_common____motion_technique_type();
}


bool LibraryArticulatedSystemsLoader15::end__technique_common____motion_technique_type()
{
SaxVirtualFunctionTest15(end__technique_common____motion_technique_type());
return mLoader->end__technique_common____motion_technique_type();
}


bool LibraryArticulatedSystemsLoader15::begin__axis_info____motion_axis_info_type( const COLLADASaxFWL15::axis_info____motion_axis_info_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__axis_info____motion_axis_info_type(attributeData));
COLLADASaxFWL::axis_info____motion_axis_info_type__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.axis = attributeData.axis;
attrData.name = attributeData.name;
return mLoader->begin__axis_info____motion_axis_info_type(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__axis_info____motion_axis_info_type()
{
SaxVirtualFunctionTest15(end__axis_info____motion_axis_info_type());
return mLoader->end__axis_info____motion_axis_info_type();
}


bool LibraryArticulatedSystemsLoader15::begin__speed____common_float_or_param_type()
{
SaxVirtualFunctionTest15(begin__speed____common_float_or_param_type());
return mLoader->begin__speed____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__speed____common_float_or_param_type()
{
SaxVirtualFunctionTest15(end__speed____common_float_or_param_type());
return mLoader->end__speed____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__acceleration____common_float_or_param_type()
{
SaxVirtualFunctionTest15(begin__acceleration____common_float_or_param_type());
return mLoader->begin__acceleration____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__acceleration____common_float_or_param_type()
{
SaxVirtualFunctionTest15(end__acceleration____common_float_or_param_type());
return mLoader->end__acceleration____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__deceleration____common_float_or_param_type()
{
SaxVirtualFunctionTest15(begin__deceleration____common_float_or_param_type());
return mLoader->begin__deceleration____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__deceleration____common_float_or_param_type()
{
SaxVirtualFunctionTest15(end__deceleration____common_float_or_param_type());
return mLoader->end__deceleration____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__jerk____common_float_or_param_type()
{
SaxVirtualFunctionTest15(begin__jerk____common_float_or_param_type());
return mLoader->begin__jerk____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__jerk____common_float_or_param_type()
{
SaxVirtualFunctionTest15(end__jerk____common_float_or_param_type());
return mLoader->end__jerk____common_float_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__effector_info( const COLLADASaxFWL15::effector_info__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__effector_info(attributeData));
COLLADASaxFWL::effector_info__AttributeData attrData;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
return mLoader->begin__effector_info(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__effector_info()
{
SaxVirtualFunctionTest15(end__effector_info());
return mLoader->end__effector_info();
}


bool LibraryArticulatedSystemsLoader15::begin__speed____common_float2_or_param_type()
{
SaxVirtualFunctionTest15(begin__speed____common_float2_or_param_type());
return mLoader->begin__speed____common_float2_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__speed____common_float2_or_param_type()
{
SaxVirtualFunctionTest15(end__speed____common_float2_or_param_type());
return mLoader->end__speed____common_float2_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__acceleration____common_float2_or_param_type()
{
SaxVirtualFunctionTest15(begin__acceleration____common_float2_or_param_type());
return mLoader->begin__acceleration____common_float2_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__acceleration____common_float2_or_param_type()
{
SaxVirtualFunctionTest15(end__acceleration____common_float2_or_param_type());
return mLoader->end__acceleration____common_float2_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__deceleration____common_float2_or_param_type()
{
SaxVirtualFunctionTest15(begin__deceleration____common_float2_or_param_type());
return mLoader->begin__deceleration____common_float2_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__deceleration____common_float2_or_param_type()
{
SaxVirtualFunctionTest15(end__deceleration____common_float2_or_param_type());
return mLoader->end__deceleration____common_float2_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__jerk____common_float2_or_param_type()
{
SaxVirtualFunctionTest15(begin__jerk____common_float2_or_param_type());
return mLoader->begin__jerk____common_float2_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::end__jerk____common_float2_or_param_type()
{
SaxVirtualFunctionTest15(end__jerk____common_float2_or_param_type());
return mLoader->end__jerk____common_float2_or_param_type();
}


bool LibraryArticulatedSystemsLoader15::begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__technique____technique_type(attributeData));
COLLADASaxFWL::technique__AttributeData attrData;
attrData.profile = attributeData.profile;
return mLoader->begin__technique(attrData);
}


bool LibraryArticulatedSystemsLoader15::end__technique____technique_type()
{
SaxVirtualFunctionTest15(end__technique____technique_type());
return mLoader->end__technique();
}



}
