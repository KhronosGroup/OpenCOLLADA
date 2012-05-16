/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America

    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxControllerImporter.h"

#include "COLLADAFWController.h"
#include "COLLADAFWSkinController.h"


namespace COLLADAMax
{

    //------------------------------
	ControllerImporter::ControllerImporter( DocumentImporter* documentImporter, const COLLADAFW::Controller* controller )
		: ImporterBase(documentImporter)
		, mController(controller)
	{
	}

    //------------------------------
	ControllerImporter::~ControllerImporter()
	{
	}

	//------------------------------
	bool ControllerImporter::import()
	{
		if ( mController->getControllerType() == COLLADAFW::Controller::CONTROLLER_TYPE_SKIN )
		{
			const COLLADAFW::SkinController* skinController = (const COLLADAFW::SkinController*)mController;
			const COLLADAFW::UniqueId& controllerDataUniqueId = skinController->getSkinControllerData();
			if ( controllerDataUniqueId.isValid() )
			{
				COLLADAFW::SkinController* clonedSkinController = new COLLADAFW::SkinController(*skinController);
				addUniqueIdControllerPair(controllerDataUniqueId, clonedSkinController);
				// clonedSkinController will be deleted by ImporterBase after import
				addSkinController( clonedSkinController );
			}
		} 
		else if ( mController->getControllerType() == COLLADAFW::Controller::CONTROLLER_TYPE_MORPH )
		{
			const COLLADAFW::MorphController* morphController = (const COLLADAFW::MorphController*)mController;
			COLLADAFW::MorphController* clonedMorphController = new COLLADAFW::MorphController(*morphController);
			// clonedMorphController will be deleted by ImporterBase after import
			addMorphController( clonedMorphController );
		}

		return true;
	}
} // namespace COLLADAMax
