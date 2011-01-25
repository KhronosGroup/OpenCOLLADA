#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryPhysicsModel.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    LibraryPhysicsModel::LibraryPhysicsModel ( COLLADASW::StreamWriter *streamWriter )
		: Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_PHYSICS_MODELS )
    {}


    //---------------------------------------------------------------
    void LibraryPhysicsModel::openPhysicsModel ( const String &modelId, const String &modelName )
    {
        openLibrary();
        mCurrentPhysicsModelCloser = mSW->openElement ( CSWC::CSW_ELEMENT_PHYSICS_MODEL );

        if ( !modelId.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, modelId );

        if ( !modelName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, modelName );
    }


    //---------------------------------------------------------------
    void LibraryPhysicsModel::closePhysicsModel()
    {
        mCurrentPhysicsModelCloser.close();
    }

	//---------------------------------------------------------------

	
} //namespace COLLADASW
