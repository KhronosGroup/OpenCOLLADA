/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SCENE_H__
#define __COLLADAFW_SCENE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWInstanceVisualScene.h"

#include "COLLADABUURI.h"


namespace COLLADAFW
{

    /** 
     * Holds the scene element. This can have following instances:  
     *  <instance_physics_scene> 0 or more
     *  <instance_visual_scene> 0 or 1
     *  <instance_kinematics_scene> 0 or 1
     */
    class Scene : public ObjectTemplate<COLLADA_TYPE::SCENE>
    {
	private:

        /** The instance visual scene.*/
        InstanceVisualScene* mInstanceVisualScene;

	public:

        /** Constructor. */
        Scene ( const UniqueId& uniqueId ) 
            : ObjectTemplate<COLLADA_TYPE::SCENE>(uniqueId)
            , mInstanceVisualScene (0) 
        {}

        /** Destructor. */
        virtual ~Scene() 
        { 
            delete mInstanceVisualScene; 
        }

        /** The instance visual scene.*/
        const InstanceVisualScene* getInstanceVisualScene () const { return mInstanceVisualScene; }

        /** The instance visual scene.*/
        void setInstanceVisualScene ( InstanceVisualScene* val ) { mInstanceVisualScene = val; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SCENE_H__
