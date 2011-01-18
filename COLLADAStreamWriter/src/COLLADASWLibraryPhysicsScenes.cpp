#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryPhysicsScenes.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    LibraryPhysicsScenes::LibraryPhysicsScenes ( StreamWriter *streamWriter )
            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_PHYSICS_SCENES )
    {}


    //---------------------------------------------------------------
    void LibraryPhysicsScenes::openPhysicsScene ( const String &sceneId, const String &sceneName )
    {
        openLibrary();
        mCurrentPhysicsSceneCloser = mSW->openElement ( CSWC::CSW_ELEMENT_PHYSICS_SCENE );

        if ( !sceneId.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, sceneId );

        if ( !sceneName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, sceneName );
    }


    //---------------------------------------------------------------
    void LibraryPhysicsScenes::closePhysicsScene()
    {
        mCurrentPhysicsSceneCloser.close();
    }

	//---------------------------------------------------------------
	
	void LibraryPhysicsScenes::addTechnique(const PhysicsScene pScene)
	{
	    mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE_COMMON );
		
		mSW->openElement ( CSWC::CSW_ELEMENT_GRAVITY );
		const float *arrayp = pScene.getGravity();
		const float gravity[3] = {*arrayp,*(arrayp+1),*(arrayp+2)}; 
		const short time_step  = pScene.getTimeStep();
		mSW->appendValues ( gravity,3 );
        mSW->closeElement();
		
		mSW->openElement ( CSWC::CSW_ELEMENT_TIMESTEP );
        mSW->appendValues (time_step);
		mSW->closeElement();
		
		mSW->closeElement();
	}  


} //namespace COLLADASW