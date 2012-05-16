/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_LIGHTIMPORTER_H__
#define __DAE2MA_LIGHTIMPORTER_H__

#include "DAE2MAPrerequisites.h"
#include "DAE2MABaseImporter.h"

#include <MayaDMLightList.h>
#include <MayaDMObjectSet.h>
#include <MayaDMSpotLight.h>
#include <MayaDMPointLight.h>
#include <MayaDMLightLinker.h>


namespace DAE2MA
{

    /** TODO Documentation */
    class LightImporter : BaseImporter
    {
    private:

        /** The standard name for a light without name. */
        static const String LIGHT_NAME;

        /** The name of maya's default light list and set. */
        static const String DEFAULT_LIGHT_LIST_NAME;
        static const String DEFAULT_LIGHT_SET_NAME;

        /** The name of the light linker to link all the light objects. */
        static const String DEFAULT_LIGHT_LINKER_NAME;

    private:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::Light*> UniqueIdLightNodeMap;

	private:

        /**
         * If we have one or more lights, we need a light linker.
         * This node defines light linking relationships between lights and objects. Connecting a 
         * light to the "light" child of the "link" compound will cause it to illuminate the object 
         * connected to the "object" child of the same index of the "link" compound.
         */
        MayaDM::LightLinker mDefaultLightLinker;

        /**
         * The default light list object.
         */
        MayaDM::LightList mDefaultLightList; 

        /**
         * The default light set object.
         */
        MayaDM::ObjectSet mDefaultLightSet;

        /** 
        * The map holds the unique ids of the light nodes to the maya specific nodes. 
        * Need for the instances.
        */
        UniqueIdMayaNodeMap mMayaLightNodesMap;

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

        /**
         * Write the light connections.
         */
        void connectLightObjects ();

        /**
         * Creates the maya default light linker, light set and light list objects.
         */
        void initialiseDefaultLightObjects ();

    private:

        /**
         * Creates a light.
         */
        void createLight ( const COLLADAFW::Light* light,  MayaNode* mayaTransformNode );

        /**
         * Writes the object connections of the light linker into the maya ascii file.
         * If we have one or more lights, we need a light linker.
         * This node defines light linking relationships between lights and objects. Connecting a 
         * light to the "light" child of the "link" compound will cause it to illuminate the object 
         * connected to the "object" child of the same index of the "link" compound.
         */
        void connectLightLinkers ();

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

} // namespace DAE2MA

#endif // __DAE2MA_LIGHTIMPORTER_H__
