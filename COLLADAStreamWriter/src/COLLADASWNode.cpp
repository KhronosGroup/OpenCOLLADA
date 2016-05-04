/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWNode.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"


namespace COLLADASW
{

    //---------------------------------------------------------------
    void Node::start(bool lodPass)
    {
		if (!mIsInstanceNode || lodPass)
        {
            mNodeCloser = mSW->openElement ( CSWC::CSW_ELEMENT_NODE );

            if ( !mNodeId.empty() )
                mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, mNodeId );

            if ( !mNodeName.empty() )
                mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, mNodeName );

            if ( !mNodeSid.empty() )
                mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, mNodeSid );

            switch ( mType )
            {
				case NODE:
				{
					if (!lodPass)
						mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, CSWC::CSW_NODE_TYPE_NODE);
				}
				break;


				case JOINT:
					mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_TYPE, CSWC::CSW_NODE_TYPE_JOINT );
					break;

				default:
					fprintf ( stderr, "Not a valid node type: %d", mType );
					break;
            }
        }
        else
        {
            mNodeCloser = mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_NODE );

            if ( !mNodeURL.isValid() )
            {
                fprintf ( stderr, "No node URL for the instance node!" );
                return; 
            }

            mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mNodeURL );
        }

    }


    //---------------------------------------------------------------
    void Node::addTranslate ( const String &sid, double x, double y, double z ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_TRANSLATE );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sid );

        mSW->appendValues ( x, y, z );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addTranslate ( double x, double y, double z ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_TRANSLATE );
        mSW->appendValues ( x, y, z );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addRotate ( const String &sid, double x, double y, double z, double angle ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_ROTATE );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sid );

        mSW->appendValues ( x, y, z, angle );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addRotate ( double x, double y, double z, double angle ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_ROTATE );
        mSW->appendValues ( x, y, z, angle );
        mSW->closeElement();
    }


    //---------------------------------------------------------------
    void Node::addMatrix ( const String &sid, double matrix[4][4] ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_MATRIX );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sid );

        mSW->appendValues ( matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3] );
        mSW->appendValues ( matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3] );
        mSW->appendValues ( matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3] );
        mSW->appendValues ( matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3] );

        mSW->closeElement();

    }

    //---------------------------------------------------------------
    void Node::addMatrix ( double matrix[4][4] ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_MATRIX );
        mSW->appendValues ( matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3] );
        mSW->appendValues ( matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3] );
        mSW->appendValues ( matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3] );
        mSW->appendValues ( matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3] );
        mSW->closeElement();
    }


    //---------------------------------------------------------------
    void Node::addScale ( const String &sid, double x, double y, double z ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_SCALE );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sid );

        mSW->appendValues ( x, y, z );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addScale ( double x, double y, double z ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_SCALE );
        mSW->appendValues ( x, y, z );
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addSkew ( const String &sid, float angle,
                         const float rotateAxis[3], const float aroundAxis[3] ) const
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_SKEW );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sid );

        mSW->appendValues ( angle );
        mSW->appendValues ( rotateAxis, 3 );
        mSW->appendValues ( aroundAxis, 3 );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::addLookat ( 
        const float eyePosition[3], 
        const float interestPosition[3], 
        const float upPosition[3], 
        const String &sid )
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_LOOKAT );

        if ( !sid.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sid );

        mSW->appendValues ( eyePosition, 3 );
        mSW->appendValues ( interestPosition, 3 );
        mSW->appendValues ( upPosition, 3 );

        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Node::end()
    {
        // Write the extra technique tags in the collada document
        addExtraTechniques ( mSW );

        mNodeCloser.close();
    }


} //namespace COLLADASW
