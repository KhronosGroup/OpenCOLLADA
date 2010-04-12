/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryKinematicsScenesLoader15.h"


namespace COLLADASaxFWL
{


bool LibraryKinematicsScenesLoader15::end__library_kinematics_scenes()
{
SaxVirtualFunctionTest15(end__library_kinematics_scenes());
return mLoader->end__library_kinematics_scenes();
}


bool LibraryKinematicsScenesLoader15::begin__kinematics_scene( const COLLADASaxFWL15::kinematics_scene__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__kinematics_scene(attributeData));
COLLADASaxFWL::kinematics_scene__AttributeData attrData;
attrData.id = attributeData.id;
attrData.name = attributeData.name;
return mLoader->begin__kinematics_scene(attrData);
}


bool LibraryKinematicsScenesLoader15::end__kinematics_scene()
{
SaxVirtualFunctionTest15(end__kinematics_scene());
return mLoader->end__kinematics_scene();
}


bool LibraryKinematicsScenesLoader15::begin__bind____kinematics_bind_type( const COLLADASaxFWL15::bind____kinematics_bind_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__bind____kinematics_bind_type(attributeData));
COLLADASaxFWL::bind____kinematics_bind_type__AttributeData attrData;
attrData.symbol = attributeData.symbol;
return mLoader->begin__bind____kinematics_bind_type(attrData);
}


bool LibraryKinematicsScenesLoader15::end__bind____kinematics_bind_type()
{
SaxVirtualFunctionTest15(end__bind____kinematics_bind_type());
return mLoader->end__bind____kinematics_bind_type();
}


bool LibraryKinematicsScenesLoader15::begin__param____kinematics_param_type( const COLLADASaxFWL15::param____kinematics_param_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__param____kinematics_param_type(attributeData));
COLLADASaxFWL::param____kinematics_param_type__AttributeData attrData;
attrData.ref = attributeData.ref;
return mLoader->begin__param____kinematics_param_type(attrData);
}


bool LibraryKinematicsScenesLoader15::end__param____kinematics_param_type()
{
SaxVirtualFunctionTest15(end__param____kinematics_param_type());
return mLoader->end__param____kinematics_param_type();
}


bool LibraryKinematicsScenesLoader15::begin__instance_kinematics_model( const COLLADASaxFWL15::instance_kinematics_model__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__instance_kinematics_model(attributeData));
COLLADASaxFWL::instance_kinematics_model__AttributeData attrData;
attrData.present_attributes = attributeData.present_attributes;
attrData.url = attributeData.url;
attrData.sid = attributeData.sid;
attrData.name = attributeData.name;
return mLoader->begin__instance_kinematics_model(attrData);
}


bool LibraryKinematicsScenesLoader15::end__instance_kinematics_model()
{
SaxVirtualFunctionTest15(end__instance_kinematics_model());
return mLoader->end__instance_kinematics_model();
}


bool LibraryKinematicsScenesLoader15::begin__newparam____kinematics_newparam_type( const COLLADASaxFWL15::newparam____kinematics_newparam_type__AttributeData& attributeData )
{
SaxVirtualFunctionTest15(begin__newparam____kinematics_newparam_type(attributeData));
COLLADASaxFWL::newparam____kinematics_newparam_type__AttributeData attrData;
attrData.sid = attributeData.sid;
return mLoader->begin__newparam____kinematics_newparam_type(attrData);
}


bool LibraryKinematicsScenesLoader15::end__newparam____kinematics_newparam_type()
{
SaxVirtualFunctionTest15(end__newparam____kinematics_newparam_type());
return mLoader->end__newparam____kinematics_newparam_type();
}


bool LibraryKinematicsScenesLoader15::begin__float____float_type()
{
SaxVirtualFunctionTest15(begin__float____float_type());
return mLoader->begin__float();
}


bool LibraryKinematicsScenesLoader15::end__float____float_type()
{
SaxVirtualFunctionTest15(end__float____float_type());
return mLoader->end__float();
}


bool LibraryKinematicsScenesLoader15::data__float____float_type( float value )
{
SaxVirtualFunctionTest15(data__float____float_type(value));
return mLoader->data__float(value);
}


bool LibraryKinematicsScenesLoader15::begin__int____int_type()
{
SaxVirtualFunctionTest15(begin__int____int_type());
return mLoader->begin__int();
}


bool LibraryKinematicsScenesLoader15::end__int____int_type()
{
SaxVirtualFunctionTest15(end__int____int_type());
return mLoader->end__int();
}


bool LibraryKinematicsScenesLoader15::data__int____int_type( int value )
{
SaxVirtualFunctionTest15(data__int____int_type(value));
return mLoader->data__int(value);
}


bool LibraryKinematicsScenesLoader15::begin__bool()
{
SaxVirtualFunctionTest15(begin__bool());
return mLoader->begin__bool();
}


bool LibraryKinematicsScenesLoader15::end__bool()
{
SaxVirtualFunctionTest15(end__bool());
return mLoader->end__bool();
}


bool LibraryKinematicsScenesLoader15::data__bool( bool value )
{
SaxVirtualFunctionTest15(data__bool(value));
return mLoader->data__bool(value);
}


bool LibraryKinematicsScenesLoader15::begin__SIDREF()
{
SaxVirtualFunctionTest15(begin__SIDREF());
return mLoader->begin__SIDREF();
}


bool LibraryKinematicsScenesLoader15::end__SIDREF()
{
SaxVirtualFunctionTest15(end__SIDREF());
return mLoader->end__SIDREF();
}


bool LibraryKinematicsScenesLoader15::data__SIDREF( const ParserChar* value, size_t length )
{
SaxVirtualFunctionTest15(data__SIDREF(value, length));
return mLoader->data__SIDREF(value, length);
}



}
