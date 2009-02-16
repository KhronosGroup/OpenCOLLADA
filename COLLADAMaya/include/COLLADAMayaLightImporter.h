/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_LIGHTIMPORTER_H__
#define __COLLADAMAYA_LIGHTIMPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADABUIDList.h"

#include <MayaDMSpotLight.h>
#include <MayaDMPointLight.h>


namespace COLLADAMaya
{

    /** TODO Documentation */
    class LightImporter : BaseImporter
    {
    private:

        /** The standard name for camera without name. */
        static const String LIGHT_NAME;

	private:
	
        /**
        * The list of the unique maya light names.
        */
        COLLADABU::IDList mLightIdList;

        /** 
        * The map holds the unique ids of the light nodes to the maya specific nodes. 
        */
        UniqueIdMayaNodesMap mMayaLightNodesMap;

	public:

        /** Constructor. */
		LightImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~LightImporter ();

        /**
        * Imports the data of the current light.
        */
        void importLight ( const COLLADAFW::Light* light );

    private:

        /**
         * Creates a light.
         */
        void createLight ( const COLLADAFW::Light* light,  MayaNode* mayaTransformNode );

        /**
        * Sets the spot light specific attributes.
        */
        void setSpotLightAttributes ( 
            const COLLADAFW::Light* light, 
            MayaDM::Light* mayaLight );

        /**
         * Sets the point light specific attributes.
         */
        void setPointLightAttributes ( 
            const COLLADAFW::Light* light, 
            MayaDM::Light* mayaLight );

        MayaNode* findMayaLightNode ( const COLLADAFW::UniqueId& lightId );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_LIGHTIMPORTER_H__
