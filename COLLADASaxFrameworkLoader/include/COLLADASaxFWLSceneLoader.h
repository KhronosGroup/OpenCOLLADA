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

#include "COLLADAFWHashFunctions.h"
#include "COLLADABUhash_map.h"


namespace COLLADASaxFWL
{

	class KinematicsInstanceKinematicsScene;

    /** TODO Documentation */
	class SceneLoader : public FilePartLoader
    {
	private:
		typedef COLLADABU::hash_set<COLLADAFW::UniqueId> UniqueIdSet;

	private:
	
        /** The current scene.*/
        COLLADAFW::Scene* mCurrentScene;

        /** The instantiated visual scene. Just one is allowed. */
        COLLADAFW::InstanceVisualScene* mInstanceVisualScene;

		/** List of all nodes of the visual scene that are bound to the kinematics model.*/
		UniqueIdSet mBoundNodes;

		/** The InstanceKinematicsScene currently being parsed.*/
		KinematicsInstanceKinematicsScene* mCurrentInstanceKinematicsScene;

		/** The bind joint axis currently being parsed.*/
		KinematicsBindJointAxis* mCurrentBindJointAxis;

		/** The character data gather from the current element. Used for param.*/
		String mCurrentCharacterData;
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

		/** Sax callback function for beginning reading the instance kinematics scene. */
		virtual bool begin__instance_kinematics_scene( const instance_kinematics_scene__AttributeData& attributeData );

		/** Sax callback function for ending reading the instance kinematics scene. */
		virtual bool end__instance_kinematics_scene();

		virtual bool begin__bind_kinematics_model( const bind_kinematics_model__AttributeData& attributeData ){return true;}
		virtual bool end__bind_kinematics_model();

		virtual bool begin__bind_joint_axis( const bind_joint_axis__AttributeData& attributeData );

		virtual bool end__bind_joint_axis();

		virtual bool begin__axis____common_sidref_or_param_type();
		virtual bool end__axis____common_sidref_or_param_type();

		virtual bool begin__value____common_float_or_param_type();
		virtual bool end__value____common_float_or_param_type();

		virtual bool begin__param____common_param_type();
		virtual bool end__param____common_param_type();
		virtual bool data__param____common_param_type( const ParserChar* value, size_t length );



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
