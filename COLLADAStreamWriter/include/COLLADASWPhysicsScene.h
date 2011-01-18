/* * Contributor(s): Prabhath Jayathilake.*/

#ifndef __COLLADASTREAMWRITER_PHYSICS_SCENE_H__
#define __COLLADASTREAMWRITER_PHYSICS_SCENE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** A class that hold all information about a @a \<physics_scene\> element.*/
    class PhysicsScene : public ElementWriter
    {
       
    private:

        friend class LibraryPhysicsScenes;

        /** The id of the scene.*/
        String mSceneId;

        /** The name of the scene.*/
        String mSceneName;

    protected:
		
		float mGravity[3];

		short mTimeStep;
   
    public:
 
        /** 
         * Constructor
         * @param sceneId The id of the scene.
         * @param sceneName The name of the scene.
         */
        PhysicsScene ( 
            StreamWriter* streamWriter, 
            const String& sceneId,
			const String& sceneName = ElementWriter::EMPTY_STRING ):
				ElementWriter(streamWriter),
				mSceneId( sceneId ),
				mSceneName ( sceneName ) 
				{}

        /** Destructor */
        virtual ~PhysicsScene() {}

        /** Returns a reference to the scene id */
        const String& getSceneId() const { return mSceneId; }

		/** Returns a reference to the scene name */
		const String& getSceneName() const { return mSceneName; }

        /** The name of the light.*/
        void setSceneName ( const String& val ) { mSceneName = val; }

        /** The gravity attribute. */
        const float* getGravity() const { return mGravity; }

		void setGravity ( const float* gravity ) {
						mGravity[0] = gravity[0];
						mGravity[1] = gravity[1];
						mGravity[2] = gravity[2]; }
		
		void setGravity ( const float x, const float y , const float z ) { 
						mGravity[0] = x;
						mGravity[1] = y;
						mGravity[2] = z; }
		
        /** The timeStep attribute. */
		const short getTimeStep() const { return mTimeStep; }

		void setTimeStep ( const short timestep ) { mTimeStep = timestep; }

       }; 
	
}//namespace COLLADASW

#endif //__COLLADASTREAMWRITER_PHYSICS_SCENE_H__
