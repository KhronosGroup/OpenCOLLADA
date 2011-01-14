/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASAXFWL_LIBRARYPHYSICSMATERIALSLOADER14_H__
#define __COLLADASAXFWL_LIBRARYPHYSICSMATERIALSLOADER14_H__


#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLLibraryPhysicsMaterialsLoader.h"
#include "COLLADASaxFWLPhysicsMaterialLoader14.h"


namespace COLLADASaxFWL
{


class IFilePartLoader;


class LibraryPhysicsMaterialsLoader14 : public PhysicsMaterialLoader14
{
private:
LibraryPhysicsMaterialsLoader* mLoader;

public:
LibraryPhysicsMaterialsLoader14(LibraryPhysicsMaterialsLoader* loader)
 : PhysicsMaterialLoader14(loader)
 , mLoader(loader)
{}


virtual bool begin__physics_material( const COLLADASaxFWL14::physics_material__AttributeData& attributeData );

virtual bool end__physics_material();

virtual bool end__library_physics_materials();

virtual bool begin__technique( const COLLADASaxFWL14::technique__AttributeData& attributeData );

virtual bool end__technique();


private:
/** Disable default copy ctor. */
LibraryPhysicsMaterialsLoader14(const LibraryPhysicsMaterialsLoader14&);
/** Disable default assignment operator. */
const LibraryPhysicsMaterialsLoader14& operator=(const LibraryPhysicsMaterialsLoader14&);
};
}
#endif // __COLLADASAXFWL_LIBRARYPHYSICSMATERIALSLOADER14_H__
