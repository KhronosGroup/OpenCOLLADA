/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYKINEMATICSSCENESLOADER15_H__
#define __COLLADASAXFWL_LIBRARYKINEMATICSSCENESLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryKinematicsScenesLoader.h"
#include "COLLADASaxFWLIParserImpl15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryKinematicsScenesLoader15 : public IParserImpl15
{
private:
LibraryKinematicsScenesLoader* mLoader;

public:
LibraryKinematicsScenesLoader15(LibraryKinematicsScenesLoader* loader)
 : mLoader(loader)
{}


virtual bool end__library_kinematics_scenes();

virtual bool begin__kinematics_scene( const COLLADASaxFWL15::kinematics_scene__AttributeData& attributeData );

virtual bool end__kinematics_scene();

virtual bool begin__bind____kinematics_bind_type( const COLLADASaxFWL15::bind____kinematics_bind_type__AttributeData& attributeData );

virtual bool end__bind____kinematics_bind_type();

virtual bool begin__param____kinematics_param_type( const COLLADASaxFWL15::param____kinematics_param_type__AttributeData& attributeData );

virtual bool end__param____kinematics_param_type();

virtual bool begin__instance_kinematics_model( const COLLADASaxFWL15::instance_kinematics_model__AttributeData& attributeData );

virtual bool end__instance_kinematics_model();

virtual bool begin__newparam____kinematics_newparam_type( const COLLADASaxFWL15::newparam____kinematics_newparam_type__AttributeData& attributeData );

virtual bool end__newparam____kinematics_newparam_type();

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


private:
/** Disable default copy ctor. */
LibraryKinematicsScenesLoader15(const LibraryKinematicsScenesLoader15&);
/** Disable default assignment operator. */
const LibraryKinematicsScenesLoader15& operator=(const LibraryKinematicsScenesLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYKINEMATICSSCENESLOADER15_H__
