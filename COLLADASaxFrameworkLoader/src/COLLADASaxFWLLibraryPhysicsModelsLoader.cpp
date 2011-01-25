/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLLibraryPhysicsModelsLoader.h"
#include "COLLADASaxFWLFileLoader.h"

#include "COLLADAFWIWriter.h"
#include "COLLADAFWPhysicsModel.h"


namespace COLLADASaxFWL
{

    //------------------------------
	LibraryPhysicsModelsLoader::LibraryPhysicsModelsLoader(IFilePartLoader* callingFilePartLoader)
		: FilePartLoader(callingFilePartLoader)//,
		//mPhysicsModel(0)
	{
		PhysicsModelLoader::setHandlingFilePartLoader(this);
	}
	
    //------------------------------
	LibraryPhysicsModelsLoader::~LibraryPhysicsModelsLoader()
	{
	}

    //------------------------------
    const COLLADAFW::UniqueId& LibraryPhysicsModelsLoader::getUniqueId ()
    {
        if ( mPhysicsModel )
            return mPhysicsModel->getUniqueId();
        return COLLADAFW::UniqueId::INVALID;
    }

	//------------------------------
	bool LibraryPhysicsModelsLoader::begin__physics_model( const physics_model__AttributeData& attributeData )
	{
		return beginPhysicsModel(attributeData);
	}

	//------------------------------
	bool LibraryPhysicsModelsLoader::end__physics_model()
	{
		return endPhysicsModel();
	}

	//------------------------------
	bool LibraryPhysicsModelsLoader::end__library_physics_models()
	{	std::cout << "in end library phys models in LPSL::end phys model \n";
		moveUpInSidTree();
		getFileLoader()->addPhysicsModels(mPhysicsModel);
		finish();
		return true;
	}

} // namespace COLLADASaxFWL
