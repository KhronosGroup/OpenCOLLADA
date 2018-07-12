/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYKINEMATICSMODELSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYKINEMATICSMODELSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryKinematicsModelsLoader.h"
#include "COLLADASaxFWLFormulasLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryKinematicsModelsLoader15 : public FormulasLoader15
{
private:
LibraryKinematicsModelsLoader* mLoader;

public:
LibraryKinematicsModelsLoader15(LibraryKinematicsModelsLoader* loader)
 : FormulasLoader15(loader)
 , mLoader(loader)
{}


virtual bool end__library_kinematics_models();

virtual bool begin__kinematics_model( const COLLADASaxFWL15::kinematics_model__AttributeData& attributeData );

virtual bool end__kinematics_model();

virtual bool begin__technique_common____kinematics_model_technique_type();

virtual bool end__technique_common____kinematics_model_technique_type();

virtual bool begin__newparam____kinematics_newparam_type( const COLLADASaxFWL15::newparam____kinematics_newparam_type__AttributeData& attributeData );

virtual bool end__newparam____kinematics_newparam_type();

virtual bool begin__joint( const COLLADASaxFWL15::joint__AttributeData& attributeData );

virtual bool end__joint();

virtual bool begin__prismatic( const COLLADASaxFWL15::prismatic__AttributeData& attributeData );

virtual bool end__prismatic();

virtual bool begin__axis____axis_type( const COLLADASaxFWL15::axis____axis_type__AttributeData& attributeData );

virtual bool end__axis____axis_type();

virtual bool data__axis____axis_type( const float* data, size_t length );

virtual bool begin__limits____joint_limits_type();

virtual bool end__limits____joint_limits_type();

virtual bool begin__min____minmax_type( const COLLADASaxFWL15::min____minmax_type__AttributeData& attributeData );

virtual bool end__min____minmax_type();

virtual bool data__min____minmax_type( float value );

virtual bool begin__max____minmax_type( const COLLADASaxFWL15::max____minmax_type__AttributeData& attributeData );

virtual bool end__max____minmax_type();

virtual bool data__max____minmax_type( float value );

virtual bool begin__revolute( const COLLADASaxFWL15::revolute__AttributeData& attributeData );

virtual bool end__revolute();

virtual bool begin__instance_joint( const COLLADASaxFWL15::instance_joint__AttributeData& attributeData );

virtual bool end__instance_joint();

virtual bool begin__link( const COLLADASaxFWL15::link__AttributeData& attributeData );

virtual bool end__link();

virtual bool begin__attachment_full( const COLLADASaxFWL15::attachment_full__AttributeData& attributeData );

virtual bool end__attachment_full();

virtual bool begin__attachment_start( const COLLADASaxFWL15::attachment_start__AttributeData& attributeData );

virtual bool end__attachment_start();

virtual bool begin__attachment_end( const COLLADASaxFWL15::attachment_end__AttributeData& attributeData );

virtual bool end__attachment_end();

virtual bool begin__translate( const COLLADASaxFWL15::translate__AttributeData& attributeData );

virtual bool end__translate();

virtual bool data__translate( const float* data, size_t length );

virtual bool begin__rotate( const COLLADASaxFWL15::rotate__AttributeData& attributeData );

virtual bool end__rotate();

virtual bool data__rotate( const float* data, size_t length );

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryKinematicsModelsLoader15(const LibraryKinematicsModelsLoader15&);
/** Disable default assignment operator. */
const LibraryKinematicsModelsLoader15& operator=(const LibraryKinematicsModelsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYKINEMATICSMODELSLOADER15_H__
