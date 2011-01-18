#include "COLLADASWInstanceRigidBody.h"
#include "COLLADASWConstants.h"


namespace COLLADASW
{

    //---------------------------------------------------------------
    void InstanceRigidBody::add()
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_RIGID_BODY );
        mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mUrl );
		mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mTarget );
        
		//If there are any parameters to override
		/*mTech->openTechnique( CSWC::CSW_ELEMENT_TECHNIQUE_COMMON );
		mTech->addChildElement( CSWC::CSW_ELEMENT_ANGULAR_VELOCITY );
		mTech->mSW->appendValues ( 
		*/
		
		mSW->closeElement();


    }



} //namespace COLLADASW
