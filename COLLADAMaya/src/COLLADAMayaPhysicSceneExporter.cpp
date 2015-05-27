/*
    Copyright (c) 2015 Starbreeze

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
#include "COLLADAMayaSyntax.h"

namespace COLLADAMaya
{
	
	const String physicModelUrl("#" + String(PHYSIC_MODEL_ID));
	const String physicWorldReferenceUrl("#" + String(PHYSIC_WORLD_REFERENCE));

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

        PhysicsExporter* pPhysicsExporter = mDocumentExporter->getPhysicsExporter();
        const PhysicsExporter::DaeToIRBMap & instanceRigidBodies = pPhysicsExporter->getInstanceRigidBodies();

		// Get the streamWriter from the export document
		COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();
		
		COLLADASW::LibraryPhysicsScenes libraryPhysicsScene(streamWriter);


		//Physic_scene tag
		libraryPhysicsScene.openPhysicsScene(PHYSIC_SCENE_NODE_ID);

        for (PhysicsExporter::DaeToIRBMap::const_iterator iMap = instanceRigidBodies.begin(); iMap != instanceRigidBodies.end(); ++iMap)
		{
            COLLADASW::InstancePhysicsModel instancePhysicModel(streamWriter, iMap->first + physicModelUrl);
            instancePhysicModel.openInstancePhysicsModel();

            for (std::vector<PhysicsExporter::BodyTarget>::const_iterator iVec = iMap->second.begin(); iVec != iMap->second.end(); ++iVec)
            {
                // Don't export bodies linked to world
                if ((*iVec).Target.compare(physicWorldReferenceUrl))
                {
                    COLLADASW::InstanceRigidBody instanceRigidBody(streamWriter, (*iVec).Body, (*iVec).Target);
                    instanceRigidBody.openInstanceRigidBody();
                    instanceRigidBody.closeInstanceRigidBody();
                }
            }

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
