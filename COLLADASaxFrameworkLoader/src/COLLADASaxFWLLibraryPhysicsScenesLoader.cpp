/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryPhysicsScenesLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWPhysicsScene.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryPhysicsScenesLoader::LibraryPhysicsScenesLoader(IFilePartLoader* callingFilePartLoader)
		: FilePartLoader(callingFilePartLoader)//,
		//mPhysicsScene(0)
	{
		PhysicsSceneLoader::setHandlingFilePartLoader(this);
	}
	
    //------------------------------
	LibraryPhysicsScenesLoader::~LibraryPhysicsScenesLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryPhysicsScenesLoader::getUniqueId ()
    {
        if ( mPhysicsScene )
            return mPhysicsScene->getUniqueId();
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	bool LibraryPhysicsScenesLoader::begin__physics_scene( const physics_scene__AttributeData& attributeData )
	{
		return beginPhysicsScene(attributeData);
	}

	//------------------------------
	bool LibraryPhysicsScenesLoader::end__physics_scene()
	{
		return endPhysicsScene();
	}

	//------------------------------
	bool LibraryPhysicsScenesLoader::end__library_physics_scenes()
	{	std::cout << "in end library phys scenes in LPSL::end phys scene \n";
		moveUpInSidTree();
		getFileLoader()->addPhysicsScenes(mPhysicsScene);
		finish();
		return true;
	}

} // namespace COLLADASaxFWL
