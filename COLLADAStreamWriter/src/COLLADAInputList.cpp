/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAInputList.h"
#include "COLLADASWC.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void InputList::add()
    {
        // write inputs
        for ( List::iterator it = mList.begin(); it != mList.end(); ++it )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_INPUT );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SEMANTIC, getSemanticString ( it->getSemantic() ) );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, it->getSource() );

            if ( it->getOffset() >= 0 )
                mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_OFFSET, ( unsigned long ) it->getOffset() );

            if ( it->getSet() >= 0 )
                mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SET, ( unsigned long ) it->getSet() );

            mSW->closeElement();
        }

    }


    //---------------------------------------------------------------
    const String & InputList::getSemanticString ( Semantics semantic )
    {
        switch ( semantic )
        {

        case POSITION:
            return CSWC::COLLADA_SEMANTIC_POSITION;

        case VERTEX:
            return CSWC::COLLADA_SEMANTIC_VERTEX;

        case NORMAL:
            return CSWC::COLLADA_SEMANTIC_NORMAL;

        case TEXCOORD:
            return CSWC::COLLADA_SEMANTIC_TEXCOORD;

        case COLOR:
            return CSWC::COLLADA_SEMANTIC_COLOR;

        default:
            return CSWC::EMPTY_STRING;
        }

    }


} //namespace COLLADA
