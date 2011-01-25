#include "COLLADASWStreamWriter.h"
#include "COLLADASWPhysicsModel.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    // ---------------------------------------------------
    PhysicsModel::PhysicsModel ( 
        StreamWriter* streamWriter, 
        const String& modelId, 
        const String& modelName )
    : ElementWriter ( streamWriter )
    , mModelId ( modelId )
    , mModelName ( modelName )
    {}

    // ---------------------------------------------------
    void PhysicsModel::start()
	{
	mModelCloser = mSW->openElement ( CSWC::CSW_ELEMENT_PHYSICS_MODEL );

        if ( !getModelId().empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, getModelId() );
        
        if ( !getModelName().empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, getModelName() );	
	}
    
	void PhysicsModel::end()
    {
        // Write the extra technique tags in the collada document
        //addExtraTechniques ( mSW );

        mModelCloser.close();
    }

} //namespace COLLADASW
