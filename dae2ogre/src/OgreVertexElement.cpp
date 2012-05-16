/*
Copyright (c) 2009 NetAllied Systems GmbH

This file is part of dae2ogre.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2OgreStableHeaders.h"

#include "OgreVertexElement.h"

namespace Ogre
{
    //-----------------------------------------------------------------------
    size_t VertexElement::getTypeSize( VertexElementType etype )
    {
        switch ( etype )
        {

        case VET_COLOUR:

        case VET_COLOUR_ABGR:

        case VET_COLOUR_ARGB:
            return sizeof( RGBA );

        case VET_FLOAT1:
            return sizeof( float );

        case VET_FLOAT2:
            return sizeof( float ) * 2;

        case VET_FLOAT3:
            return sizeof( float ) * 3;

        case VET_FLOAT4:
            return sizeof( float ) * 4;

        case VET_SHORT1:
            return sizeof( short );

        case VET_SHORT2:
            return sizeof( short ) * 2;

        case VET_SHORT3:
            return sizeof( short ) * 3;

        case VET_SHORT4:
            return sizeof( short ) * 4;

        case VET_UBYTE4:
            return sizeof( unsigned char ) * 4;
        }

        return 0;
    }

    //-----------------------------------------------------------------------
    VertexElement::VertexElement()
{}

    //-----------------------------------------------------------------------
    VertexElement::VertexElement( unsigned short source, size_t offset, VertexElementType type, VertexElementSemantic semantic, unsigned short index )
            : mSource( source )
            , mOffset( offset )
            , mType( type )
            , mSemantic( semantic )
            , mIndex( index )
    {}

    //-----------------------------------------------------------------------
    VertexElement::~VertexElement()
    {}

}
