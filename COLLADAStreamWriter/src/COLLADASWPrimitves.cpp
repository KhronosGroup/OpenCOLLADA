/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWPrimitves.h"

namespace COLLADASW
{
    //---------------------------------------------------------------
    void PrimitivesBase::prepareBaseToAppendValues ( 
        const bool openPolylistElement, 
        const bool openVertexlistElement )
    {
        mPrimitiveCloser = mSW->openElement ( mPrimitiveName );

        if ( !mMaterial.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_MATERIAL, mMaterial );

        mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_COUNT, mCount );

        mInputList.add();

        // write the vertex count list
        if ( !mVCountList.empty() )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_VCOUNT );
            mSW->appendValues ( mVCountList );
            mSW->closeElement();
        }

        if ( openPolylistElement )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_P );
        }
        else if ( openVertexlistElement )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_V );
        }
    }

    //---------------------------------------------------------------
    void PrimitivesBase::openPrimitiveElement ( )
    {
        mPrimitiveCloser = mSW->openElement ( mPrimitiveName );
    }

    //---------------------------------------------------------------
    void PrimitivesBase::appendMaterial ( const String &material )
    {
        mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_MATERIAL, material );
    }

    //---------------------------------------------------------------
    void PrimitivesBase::appendCount ( const unsigned int count )
    {
        mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_COUNT, count );
    }

    //---------------------------------------------------------------
    void PrimitivesBase::appendCount ( const unsigned long count )
    {
        mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_COUNT, count );
    }

    //---------------------------------------------------------------
    void PrimitivesBase::appendVertexCount( const unsigned long vCount )
    {
        mSW->appendValues ( vCount );
    }

    //---------------------------------------------------------------
    void PrimitivesBase::appendVertexCount( const VCountList& vCountList )
    {
        mSW->appendValues ( vCountList );
    }

    //---------------------------------------------------------------
    void PrimitivesBase::openVertexCountListElement()
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_VCOUNT );
    }

    //---------------------------------------------------------------
    void PrimitivesBase::closeElement()
    {
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void PrimitivesBase::appendInputList ()
    {
        mInputList.add();
    }

    //---------------------------------------------------------------
    void PrimitivesBase::openPolylistElement ()
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_P );
    }

    //---------------------------------------------------------------
    void PrimitivesBase::finish()
    {
        mPrimitiveCloser.close();
    }

	void PrimitivesBase::CloseVCountAndOpenVElement()
	{
		closeElement();
		mSW->openElement(CSWC::CSW_ELEMENT_V);
	}

	//---------------------------------------------------------------
	void VertexWeightsElement::prepareToAppendVCountValues()
	{
		prepareBaseToAppendValues ( false, false );
		openVertexCountListElement ();
	}
} //namespace COLLADASW

