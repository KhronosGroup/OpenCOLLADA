/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYARTICULATEDSYSTEMSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYARTICULATEDSYSTEMSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryArticulatedSystemsLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryArticulatedSystemsLoader15 : public IParserImpl15
{
private:
LibraryArticulatedSystemsLoader* mLoader;

public:
LibraryArticulatedSystemsLoader15(LibraryArticulatedSystemsLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_articulated_systems();

virtual bool begin__articulated_system( const COLLADASaxFWL15::articulated_system__AttributeData& attributeData );

virtual bool end__articulated_system();

virtual bool begin__kinematics();

virtual bool end__kinematics();

virtual bool begin__instance_kinematics_model( const COLLADASaxFWL15::instance_kinematics_model__AttributeData& attributeData );

virtual bool end__instance_kinematics_model();

virtual bool begin__newparam____kinematics_newparam_type( const COLLADASaxFWL15::newparam____kinematics_newparam_type__AttributeData& attributeData );

virtual bool end__newparam____kinematics_newparam_type();

virtual bool begin__bind____kinematics_bind_type( const COLLADASaxFWL15::bind____kinematics_bind_type__AttributeData& attributeData );

virtual bool begin__float____float_type();

virtual bool end__float____float_type();

virtual bool data__float____float_type( float value );

virtual bool begin__int____int_type();

virtual bool end__int____int_type();

virtual bool data__int____int_type( sint64 value );

virtual bool begin__bool();

virtual bool end__bool();

virtual bool data__bool( bool value );

virtual bool begin__SIDREF();

virtual bool end__SIDREF();

virtual bool data__SIDREF( const ParserChar* value, size_t length );

virtual bool end__bind____kinematics_bind_type();

virtual bool begin__param____kinematics_param_type( const COLLADASaxFWL15::param____kinematics_param_type__AttributeData& attributeData );

virtual bool end__param____kinematics_param_type();

virtual bool begin__setparam____kinematics_setparam_type( const COLLADASaxFWL15::setparam____kinematics_setparam_type__AttributeData& attributeData );

virtual bool end__setparam____kinematics_setparam_type();

virtual bool begin__technique_common____kinematics_technique_type();

virtual bool end__technique_common____kinematics_technique_type();

virtual bool begin__axis_info____kinematics_axis_info_type( const COLLADASaxFWL15::axis_info____kinematics_axis_info_type__AttributeData& attributeData );

virtual bool end__axis_info____kinematics_axis_info_type();

virtual bool begin__active();

virtual bool end__active();

virtual bool begin__locked();

virtual bool end__locked();

virtual bool begin__index( const COLLADASaxFWL15::index__AttributeData& attributeData );

virtual bool end__index();

virtual bool begin__limits____kinematics_limits_type();

virtual bool end__limits____kinematics_limits_type();

virtual bool begin__min____common_float_or_param_type();

virtual bool end__min____common_float_or_param_type();

virtual bool begin__max____common_float_or_param_type();

virtual bool end__max____common_float_or_param_type();

virtual bool begin__frame_origin( const COLLADASaxFWL15::frame_origin__AttributeData& attributeData );

virtual bool end__frame_origin();

virtual bool begin__frame_tip( const COLLADASaxFWL15::frame_tip__AttributeData& attributeData );

virtual bool end__frame_tip();

virtual bool begin__frame_tcp( const COLLADASaxFWL15::frame_tcp__AttributeData& attributeData );

virtual bool end__frame_tcp();

virtual bool begin__frame_object( const COLLADASaxFWL15::frame_object__AttributeData& attributeData );

virtual bool end__frame_object();

virtual bool begin__motion();

virtual bool end__motion();

virtual bool begin__instance_articulated_system( const COLLADASaxFWL15::instance_articulated_system__AttributeData& attributeData );

virtual bool end__instance_articulated_system();

virtual bool begin__technique_common____motion_technique_type();

virtual bool end__technique_common____motion_technique_type();

virtual bool begin__axis_info____motion_axis_info_type( const COLLADASaxFWL15::axis_info____motion_axis_info_type__AttributeData& attributeData );

virtual bool end__axis_info____motion_axis_info_type();

virtual bool begin__speed____common_float_or_param_type();

virtual bool end__speed____common_float_or_param_type();

virtual bool begin__acceleration____common_float_or_param_type();

virtual bool end__acceleration____common_float_or_param_type();

virtual bool begin__deceleration____common_float_or_param_type();

virtual bool end__deceleration____common_float_or_param_type();

virtual bool begin__jerk____common_float_or_param_type();

virtual bool end__jerk____common_float_or_param_type();

virtual bool begin__effector_info( const COLLADASaxFWL15::effector_info__AttributeData& attributeData );

virtual bool end__effector_info();

virtual bool begin__speed____common_float2_or_param_type();

virtual bool end__speed____common_float2_or_param_type();

virtual bool begin__acceleration____common_float2_or_param_type();

virtual bool end__acceleration____common_float2_or_param_type();

virtual bool begin__deceleration____common_float2_or_param_type();

virtual bool end__deceleration____common_float2_or_param_type();

virtual bool begin__jerk____common_float2_or_param_type();

virtual bool end__jerk____common_float2_or_param_type();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryArticulatedSystemsLoader15(const LibraryArticulatedSystemsLoader15&);
/** Disable default assignment operator. */
const LibraryArticulatedSystemsLoader15& operator=(const LibraryArticulatedSystemsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYARTICULATEDSYSTEMSLOADER15_H__
