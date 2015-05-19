/*
    Copyright (c) 2015 Starbreeze

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_PHYSICS_SCENES_H__
#define __COLLADASTREAMWRITER_PHYSICS_SCENES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_visual_scenes\> and @a \<visual_scene\>'s*/

    class LibraryPhysicsScenes : public Library
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_physics_scenes\> and @a \<physics_scene\>'s
        should be written to.
        */
        LibraryPhysicsScenes ( StreamWriter* streamWriter );

        /** Destructor*/
        virtual ~LibraryPhysicsScenes() {}

        /** Writes the opening @a \<physics_scene\> tag and, if necessary the opening @a \<library_physics_scenes\> tag.
        closePhycsicsScene() must be use to close the opened tags.
        @param id the id of the visual scene*/
        void openPhysicsScene ( const String& nodeId = EMPTY_STRING, const String& nodeName = EMPTY_STRING );

        /** Closes the tag opened by openVisualScene()*/
        void closePhysicsScene();

		void closeLibraryPhysicsScene();

		void openTechniqueCommon();
		void closeTechniqueCommon();
		void addGravity(double x, double y, double z) const;

    private:
        TagCloser mCurrentPhysicsSceneCloser;  //!< Used to close the current physics scene
		TagCloser mCurrentTechniqueCommonCloser;  //!< Used to close the current techniqueCommon
    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_PHYSICS_SCENES_H__
