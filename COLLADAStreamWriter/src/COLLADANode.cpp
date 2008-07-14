/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADANode.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void Node::start()
    {
        mNodeCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_NODE );

        if ( !mNodeId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mNodeId );

        if ( !mNodeName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, mNodeName );

        switch ( mType )
        {

        case NODE:
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, CSWC::COLLADA_NODE_TYPE_NODE );
            break;

        case JOINT:
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, CSWC::COLLADA_NODE_TYPE_JOINT );
            break;
        }
    }


    //---------------------------------------------------------------
    void Node::addTranslate ( const String &sid, double x, double y, double z ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_TRANSLATE );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, sid );

        mSW->appendValues ( x, y, z );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addTranslate ( double x, double y, double z ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_TRANSLATE );
        mSW->appendValues ( x, y, z );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addRotate ( const String &sid, double x, double y, double z, double angle ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_ROTATE );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, sid );

        mSW->appendValues ( x, y, z, angle );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addRotate ( double x, double y, double z, double angle ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_ROTATE );
        mSW->appendValues ( x, y, z, angle );
        mSW->closeElement();
    }


    //---------------------------------------------------------------
    void Node::addMatrix ( const String &sid, double matrix[4][4] ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_MATRIX );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, sid );

        mSW->appendValues ( matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3] );
        mSW->appendValues ( matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3] );
        mSW->appendValues ( matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3] );
        mSW->appendValues ( matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3] );

        mSW->closeElement();

    }

    //---------------------------------------------------------------
    void Node::addMatrix ( double matrix[4][4] ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_MATRIX );
        mSW->appendValues ( matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3] );
        mSW->appendValues ( matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3] );
        mSW->appendValues ( matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3] );
        mSW->appendValues ( matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3] );
        mSW->closeElement();
    }


    //---------------------------------------------------------------
    void Node::addScale ( const String &sid, double x, double y, double z ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_SCALE );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, sid );

        mSW->appendValues ( x, y, z );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addScale ( double x, double y, double z ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_SCALE );
        mSW->appendValues ( x, y, z );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addSkew ( const String &sid, float angle,
                         const float rotateAxis[3], const float aroundAxis[3] ) const
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_SKEW );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, sid );

        mSW->appendValues ( angle );
        mSW->appendValues ( rotateAxis, 3 );
        mSW->appendValues ( aroundAxis, 3 );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::end()
    {
        mNodeCloser.close();
    }


} //namespace COLLADA
