#include "COLLADASWStreamWriter.h"
#include "COLLADASWRigidbodyShape.h"
#include "COLLADASWConstants.h"
#include <assert.h>

namespace COLLADASW
{

    // ---------------------------------------------------
    Shape::Shape ( StreamWriter* streamWriter )
        : ElementWriter ( streamWriter )
        , BaseExtraTechnique ( )
		, mHasDensity ( false )
		, mHasMass ( false )
      {}

	void Shape::add () const
    {
		mSW->openElement ( CSWC::CSW_ELEMENT_SHAPE );
         
		mSW->openElement ( CSWC::CSW_ELEMENT_HOLLOW );
		mSW->appendBoolean ( mHollow );
		mSW->closeElement();

		mSW->openElement ( CSWC::CSW_ELEMENT_MASS );
		mSW->appendValues ( mMass );
		mSW->closeElement();

		mSW->openElement ( CSWC::CSW_ELEMENT_DENSITY );
		mSW->appendValues ( mDensity );
		mSW->closeElement();

		mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE_COMMON );
		
        //addExtraTechniques ( mSW );

        this->addTypeSpecificInfos ();

        mSW->closeElement(); // COLLADASW_ELEMENT_TECHNIQUE_COMMON
        mSW->closeElement(); // COLLADASW_ELEMENT_SHAPE
    }