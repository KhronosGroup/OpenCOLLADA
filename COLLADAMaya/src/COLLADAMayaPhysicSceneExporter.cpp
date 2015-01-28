/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaPhysicSceneExporter.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaExportOptions.h"

#include <maya/MItDag.h>
#include <maya/MDagPath.h>

#include "COLLADASWNode.h"
#include "COLLADASWInstanceRigidBody.h"
#include "COLLADASWLibraryPhysicsScenes.h"
#include "COLLADASWConstants.h"

#include "Math/COLLADABUMathUtils.h"

#include "assert.h"

#include "COLLADAMayaPhysicsExporter.h"
#include "COLLADASWInstancePhysicsModel.h"

namespace COLLADAMaya
{
	
    //---------------------------------------------------------------
    PhysicSceneExporter::PhysicSceneExporter (
        COLLADASW::StreamWriter* streamWriter,
        DocumentExporter* documentExporter,
        const String& sceneId )
		: COLLADASW::LibraryPhysicsScenes(streamWriter)
    , mDocumentExporter ( documentExporter )
    , mSceneId ( sceneId )
    {
    }

	bool PhysicSceneExporter::exportPhysicScenes()
	{
		if ( !ExportOptions::exportPhysic() ) return false;

		//PhysicsExporter::RB_Map& myMap = PhysicsExporter::getRB_Map();
		std::map<std::string, PhysicsExporter::BodyTarget>::iterator iter;

		// Get the streamWriter from the export document
		COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
		
		COLLADASW::LibraryPhysicsScenes libraryPhysicsScene(streamWriter);


		//Physic_scene tag
		libraryPhysicsScene.openPhysicsScene("collada_physics_scene");

		for (iter = PhysicsExporter::myMap.begin(); iter != PhysicsExporter::myMap.end(); ++iter)
		{
			String url = iter->first;
			COLLADASW::InstancePhysicsModel instancePhysicModel(streamWriter, url);
			instancePhysicModel.openInstancePhysicsModel();


			PhysicsExporter::BodyTarget bt = iter->second;
			COLLADASW::InstanceRigidBody instanceRigidBody(streamWriter, bt.Body, bt.Target);
			instanceRigidBody.openInstanceRigidBody();
			instanceRigidBody.closeInstanceRigidBody();

			instancePhysicModel.closeInstancePhysicsModel();
		}

		// Technique common gravity
		libraryPhysicsScene.openTechniqueCommon();

		libraryPhysicsScene.addGravity(PhysicsExporter::gravityField.x , PhysicsExporter::gravityField.y, PhysicsExporter::gravityField.z);
		libraryPhysicsScene.closeTechniqueCommon();

		libraryPhysicsScene.closePhysicsScene();

		//close library_physics_scene tag
		libraryPhysicsScene.closeLibraryPhysicsScene();

		return true;
	}

}
