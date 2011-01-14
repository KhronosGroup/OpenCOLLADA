/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER15_H__
#define __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER15_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryPhysicsScenesLoader.h"
#include "COLLADASaxFWLPhysicsSceneLoader15.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryPhysicsScenesLoader15 : public PhysicsSceneLoader15
{
private:
LibraryPhysicsScenesLoader* mLoader;

public:
LibraryPhysicsScenesLoader15(LibraryPhysicsScenesLoader* loader)
 : PhysicsSceneLoader15(loader)
 , mLoader(loader)
{}


virtual bool begin__physics_scene( const COLLADASaxFWL15::physics_scene__AttributeData& attributeData );

virtual bool end__physics_scene();

virtual bool end__library_physics_scenes();

virtual bool begin__technique____technique_type( const COLLADASaxFWL15::technique____technique_type__AttributeData& attributeData );

virtual bool end__technique____technique_type();


private:
/** Disable default copy ctor. */
LibraryPhysicsScenesLoader15(const LibraryPhysicsScenesLoader15&);
/** Disable default assignment operator. */
const LibraryPhysicsScenesLoader15& operator=(const LibraryPhysicsScenesLoader15&);
};
}
#endif // __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER15_H__
