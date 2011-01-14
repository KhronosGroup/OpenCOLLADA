/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER14_H__
#define __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryPhysicsScenesLoader.h"
#include "COLLADASaxFWLPhysicsSceneLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryPhysicsScenesLoader14 : public PhysicsSceneLoader14
{
private:
LibraryPhysicsScenesLoader* mLoader;

public:
LibraryPhysicsScenesLoader14(LibraryPhysicsScenesLoader* loader)
 : PhysicsSceneLoader14(loader)
 , mLoader(loader)
{}


virtual bool begin__physics_scene( const COLLADASaxFWL14::physics_scene__AttributeData& attributeData );

virtual bool end__physics_scene();

virtual bool end__library_physics_scenes();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryPhysicsScenesLoader14(const LibraryPhysicsScenesLoader14&);
/** Disable default assignment operator. */
const LibraryPhysicsScenesLoader14& operator=(const LibraryPhysicsScenesLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYPHYSICSSCENESLOADER14_H__
