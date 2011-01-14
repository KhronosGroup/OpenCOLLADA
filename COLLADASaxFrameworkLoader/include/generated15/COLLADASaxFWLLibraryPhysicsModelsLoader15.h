/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYPHYSICSMODELSLOADER15_H__
#define __COLLADASAXFWL_LIBRARYPHYSICSMODELSLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryPhysicsModelsLoader.h"
#include "COLLADASaxFWLPhysicsModelLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryPhysicsModelsLoader15 : public PhysicsModelLoader15
{
private:
LibraryPhysicsModelsLoader* mLoader;

public:
LibraryPhysicsModelsLoader15(LibraryPhysicsModelsLoader* loader)
 : PhysicsModelLoader15(loader)
 , mLoader(loader)
{}


virtual bool begin__physics_model( const COLLADASaxFWL15::physics_model__AttributeData& attributeData );

virtual bool end__physics_model();

virtual bool end__library_physics_models();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryPhysicsModelsLoader15(const LibraryPhysicsModelsLoader15&);
/** Disable default assignment operator. */
const LibraryPhysicsModelsLoader15& operator=(const LibraryPhysicsModelsLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYPHYSICSMODELSLOADER15_H__
