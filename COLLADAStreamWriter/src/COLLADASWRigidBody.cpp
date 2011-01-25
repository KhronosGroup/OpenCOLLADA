#include "COLLADASWStreamWriter.h"
#include "COLLADASWRigidBody.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{
	//---------------------------------------------------

	void RigidBody::add()
	{
		mSW->openElement ( CSWC::CSW_ELEMENT_RIGID_BODY );
		if ( !mRigidBodyId.empty() )
			mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, getBodyId() );
		
		if ( !mRigidBodyName.empty() )
			mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, getBodyName() );
		
		
		mSW->openElement(CSWC::CSW_ELEMENT_TECHNIQUE_COMMON);

		mSW->openElement( CSWC::CSW_ELEMENT_DYNAMIC );
		mSW->appendValues ( (bool)isDynamic() );
        mSW->closeElement(); // COLLADASW_ELEMENT_DYNAMIC

		mSW->openElement( CSWC::CSW_ELEMENT_MASS );
		mSW->appendValues ( getBodyMass() );
        mSW->closeElement(); // COLLADASW_ELEMENT_MASS


		mSW->closeElement(); // COLLADASW_ELEMENT_TECHNIQUE_COMMON

		mSW->closeElement(); // COLLADASW_ELEMENT_RIGID_BODY

	}

}//namespace COLLADASW