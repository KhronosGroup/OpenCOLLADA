/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWInputList.h"
#include "COLLADASWConstants.h"


namespace COLLADASW
{

    //---------------------------------------------------------------
    void InputList::add()
    {
        // write inputs
        for ( List::iterator it = mList.begin(); it != mList.end(); ++it )
        {
            mSW->openElement ( CSWC::CSW_ELEMENT_INPUT );
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SEMANTIC, getSemanticString ( it->getSemantic() ) );
            mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_SOURCE, it->getSource() );

            if ( it->getOffset() >= 0 )
                mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_OFFSET, ( unsigned long ) it->getOffset() );

            if ( it->getSet() >= 0 )
                mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SET, ( unsigned long ) it->getSet() );

            mSW->closeElement();
        }

    }


    //---------------------------------------------------------------
    const String& InputList::getSemanticString ( Semantics semantic )
    {
        switch ( semantic )
        {

        case POSITION:
            return CSWC::CSW_SEMANTIC_POSITION;

        case VERTEX:
            return CSWC::CSW_SEMANTIC_VERTEX;

        case NORMAL:
            return CSWC::CSW_SEMANTIC_NORMAL;

		case TEXCOORD:
			return CSWC::CSW_SEMANTIC_TEXCOORD;

        case TANGENT:
            return CSWC::CSW_SEMANTIC_TANGENT;

        case BINORMAL:
            return CSWC::CSW_SEMANTIC_BINORMAL;

		case TEXTANGENT:
			return CSWC::CSW_SEMANTIC_TEXTANGENT;

		case TEXBINORMAL:
			return CSWC::CSW_SEMANTIC_TEXBINORMAL;

        case COLOR:
            return CSWC::CSW_SEMANTIC_COLOR;

        case JOINT:
            return CSWC::CSW_SEMANTIC_JOINT;

        case BINDMATRIX:
            return CSWC::CSW_SEMANTIC_BINDMATRIX;

        case WEIGHT:
            return CSWC::CSW_SEMANTIC_WEIGHT;

        case MORPH_TARGET:
            return CSWC::CSW_SEMANTIC_MORPH_TARGET;

        case MORPH_WEIGHT:
            return CSWC::CSW_SEMANTIC_MORPH_WEIGHT;

        default:
            return CSWC::EMPTY_STRING;
        }

    }


} //namespace COLLADASW
