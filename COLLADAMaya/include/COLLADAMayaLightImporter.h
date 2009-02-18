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

        /** The name of maya's default light list. */
        static const String INITIAL_LIGHT_LIST;
        static const String DEFAULT_LIGHT_SET;

    private:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::Light*> UniqueIdLightNodeMap;

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
        * Need for the instances.
        */
        UniqueIdMayaNodesMap mMayaLightNodesMap;

        /**
        * The map holds the maya light objects for the connections.
        */
        UniqueIdLightNodeMap mMayaLightMap;

	public:

        /** Constructor. */
		LightImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~LightImporter ();

        /**
        * Imports the data of the current light.
        */
        void importLight ( const COLLADAFW::Light* light );

        /**
         * Writes the connection attributes into the maya ascii file. 
         */
        void writeConnections ();

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

        /** 
        * The map holds the unique ids of the light nodes to the maya specific nodes. 
        * Need for the instances.
        */
        MayaNode* findMayaLightNode ( const COLLADAFW::UniqueId& lightId );

        /**
        * The map holds the maya material objects.
        */
        MayaDM::Light* findMayaLight ( const COLLADAFW::UniqueId& val ) const;

        /**
        * The map holds the maya light objects.
        */
        void appendLight ( const COLLADAFW::UniqueId& id, MayaDM::Light* lightNode );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_LIGHTIMPORTER_H__
