/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_SCENELOADER_H__
#define __COLLADASAXFWL_SCENELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLFilePartLoader.h"
#include "COLLADASaxFWLXmlTypes.h"

#include "COLLADAFWInstanceVisualScene.h"
#include "COLLADAFWScene.h"


namespace COLLADASaxFWL
{

    /** TODO Documentation */
	class SceneLoader : public FilePartLoader
    {
	private:
	
        /** The current scene.*/
        COLLADAFW::Scene* mCurrentScene;

        /** The instantiated visual scene. Just one is allowed. */
        COLLADAFW::InstanceVisualScene* mInstanceVisualScene;

	public:

        /** Constructor. */
		SceneLoader ( IFilePartLoader* callingFilePartLoader );

        /** Destructor. */
		virtual ~SceneLoader ();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();


        /** Sax callback function for beginning reading the instance visual scene. */
        virtual bool begin__instance_visual_scene( const instance_visual_scene__AttributeData& attributeData );

        /** Sax callback function for ending reading the instance visual scene. */
        virtual bool end__instance_visual_scene();

        /** Sax callback function for ending reading the scene. */
        virtual bool end__scene ();

	private:

        /** Disable default copy ctor. */
		SceneLoader( const SceneLoader& pre );

        /** Disable default assignment operator. */
		const SceneLoader& operator= ( const SceneLoader& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_SCENELOADER_H__
