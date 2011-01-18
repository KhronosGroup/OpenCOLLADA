#ifndef __COLLADASTREAMWRITER_LIBRARY_PHYSICS_SCENES_H__
#define __COLLADASTREAMWRITER_LIBRARY_PHYSICS_SCENES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWPhysicsScene.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_physics_scenes\> and @a \<physics_scene\>'s*/

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

    protected:
        /** Writes the opening @a \<physics_scene\> tag and, if necessary the opening @a \<library_physics_scenes\> tag.
        closePhysicsScene() must be use to close the opened tags.
        @param id the id of the physics scene*/
        void openPhysicsScene ( const String& sceneId = EMPTY_STRING, const String& sceneName = EMPTY_STRING );

        /** Closes the tag opened by openPhysicsScene()*/
        void closePhysicsScene();

		/** add Technique Common elements*/
		void addTechnique(const PhysicsScene pScene);   		

    private:
        TagCloser mCurrentPhysicsSceneCloser;  //!< Used to close the current physics scene

		//PhysicsScene mCurrentPhysicsScene;
    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_PHYSICS_SCENES_H__
