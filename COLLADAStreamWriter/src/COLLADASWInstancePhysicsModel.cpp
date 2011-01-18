
#include "COLLADASWInstancePhysicsModel.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"
#include "COLLADASWExtraTechnique.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    void InstancePhysicsModel::start()
	{
	mIModelCloser = mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_MODEL );

            if ( !pmUrl.isValid() )
            {
                fprintf ( stderr, "No Model URL for the instance node!" );
                return; 
            }

			mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, getUrl() );
            mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_PARENT, getParent() );
	}
    
	void InstancePhysicsModel::end()
    {
        // Write the extra technique tags in the collada document
        //addExtraTechniques ( mSW );

        mIModelCloser.close();
    }


	
	//void InstancePhysicsModel::add()
 //   {
 //       mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_PHYSICS_MODEL );
 //       mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, pmUrl );
 //       mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_PARENT, pmUrl );
 //       mSW->closeElement();
 //   }



} //namespace COLLADASW
