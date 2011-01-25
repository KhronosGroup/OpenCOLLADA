/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYPHYSICSMODELSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYPHYSICSMODELSLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryPhysicsModelsLoader.h"
#include "COLLADASaxFWLPhysicsModelLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryPhysicsModelsLoader14 : public PhysicsModelLoader14
{
private:
LibraryPhysicsModelsLoader* mLoader;

public:
LibraryPhysicsModelsLoader14(LibraryPhysicsModelsLoader* loader)
 : PhysicsModelLoader14(loader)
 , mLoader(loader)
{}


virtual bool begin__physics_model( const COLLADASaxFWL14::physics_model__AttributeData& attributeData );

virtual bool end__physics_model();

virtual bool end__library_physics_models();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryPhysicsModelsLoader14(const LibraryPhysicsModelsLoader14&);
/** Disable default assignment operator. */
const LibraryPhysicsModelsLoader14& operator=(const LibraryPhysicsModelsLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYPHYSICSMODELSLOADER14_H__
