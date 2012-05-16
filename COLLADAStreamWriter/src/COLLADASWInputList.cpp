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
    void InputList::add() const
    {
        // write inputs
        for ( List::const_iterator it = mList.begin(); it != mList.end(); ++it )
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
    const String& InputList::getSemanticString( InputSemantic::Semantics semantic )
    {
        switch ( semantic )
        {
        case InputSemantic::POSITION:
            return CSWC::CSW_SEMANTIC_POSITION;
        case InputSemantic::VERTEX:
            return CSWC::CSW_SEMANTIC_VERTEX;
        case InputSemantic::NORMAL:
            return CSWC::CSW_SEMANTIC_NORMAL;
		case InputSemantic::TEXCOORD:
			return CSWC::CSW_SEMANTIC_TEXCOORD;
		case InputSemantic::TANGENT:
			return CSWC::CSW_SEMANTIC_TANGENT;
		case InputSemantic::IN_TANGENT:
			return CSWC::CSW_SEMANTIC_IN_TANGENT;
		case InputSemantic::OUT_TANGENT:
			return CSWC::CSW_SEMANTIC_OUT_TANGENT;
		case InputSemantic::INTERPOLATION:
			return CSWC::CSW_SEMANTIC_INTERPOLATION;
        case InputSemantic::BINORMAL:
            return CSWC::CSW_SEMANTIC_BINORMAL;
		case InputSemantic::TEXTANGENT:
			return CSWC::CSW_SEMANTIC_TEXTANGENT;
		case InputSemantic::TEXBINORMAL:
			return CSWC::CSW_SEMANTIC_TEXBINORMAL;
        case InputSemantic::COLOR:
            return CSWC::CSW_SEMANTIC_COLOR;
        case InputSemantic::JOINT:
            return CSWC::CSW_SEMANTIC_JOINT;
        case InputSemantic::BINDMATRIX:
            return CSWC::CSW_SEMANTIC_BINDMATRIX;
        case InputSemantic::WEIGHT:
            return CSWC::CSW_SEMANTIC_WEIGHT;
        case InputSemantic::MORPH_TARGET:
            return CSWC::CSW_SEMANTIC_MORPH_TARGET;
		case InputSemantic::MORPH_WEIGHT:
			return CSWC::CSW_SEMANTIC_MORPH_WEIGHT;
		case InputSemantic::LINEAR_STEPS:
			return CSWC::CSW_SEMANTIC_LINEAR_STEPS;
		case InputSemantic::INPUT:
			return CSWC::CSW_SEMANTIC_INPUT;
		case InputSemantic::OUTPUT:
			return CSWC::CSW_SEMANTIC_OUTPUT;
		case InputSemantic::CONTINUITY:
			return CSWC::CSW_SEMANTIC_CONTINUITY;
        default:
            return CSWC::EMPTY_STRING;
        }

    }


} //namespace COLLADASW
