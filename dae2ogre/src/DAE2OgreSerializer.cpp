/*
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2006 Torus Knot Software Ltd
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.

You may alternatively use this source under the terms of a specific version of
the OGRE Unrestricted License provided you have obtained such a license from
Torus Knot Software Ltd.
-----------------------------------------------------------------------------
*/
#include "DAE2OgreStableHeaders.h"

#include "DAE2OgreSerializer.h"

#include <stdlib.h>
#include <string.h>

namespace DAE2Ogre
{

    /// stream overhead = ID + size
	const size_t OgreSerializer::STREAM_OVERHEAD_SIZE = sizeof( uint16 ) + sizeof( uint32 );
    const uint16 OgreSerializer::HEADER_STREAM_ID = 0x1000;
    const uint16 OgreSerializer::OTHER_ENDIAN_HEADER_STREAM_ID = 0x0010;
    //---------------------------------------------------------------------
    OgreSerializer::OgreSerializer()
    {
        // Version number
        mVersion = "[Serializer_v1.00]";
        mFlipEndian = false;
    }

    //---------------------------------------------------------------------
    OgreSerializer::~OgreSerializer()
    {}

    //---------------------------------------------------------------------
    void OgreSerializer::determineEndianness( Endian requestedEndian )
    {
        switch ( requestedEndian )
        {

        case ENDIAN_NATIVE:
            mFlipEndian = false;
            break;

        case ENDIAN_BIG:
#if CPF_ENDIAN == CPF_ENDIAN_BIG

            mFlipEndian = false;
#else

            mFlipEndian = true;
#endif

            break;

        case ENDIAN_LITTLE:
#if CPF_ENDIAN == CPF_ENDIAN_BIG

            mFlipEndian = true;
#else

            mFlipEndian = false;
#endif

            break;
        }
    }

    //---------------------------------------------------------------------
    void OgreSerializer::writeFileHeader( void )
    {

        uint16 val = HEADER_STREAM_ID;
        writeShorts( &val, 1 );

        writeString( mVersion );

    }

    //---------------------------------------------------------------------
    void OgreSerializer::writeChunkHeader( uint16 id, size_t size )
    {
        writeShorts( &id, 1 );
        uint32 uint32size = static_cast<uint32>( size );
        writeInts( &uint32size, 1 );
    }

    //---------------------------------------------------------------------
    void OgreSerializer::writeFloats( const float* const pFloat, size_t count )
    {
        if ( mFlipEndian )
        {
            float * pFloatToWrite = ( float * ) malloc( sizeof( float ) * count );
            memcpy( pFloatToWrite, pFloat, sizeof( float ) * count );

            flipToLittleEndian( pFloatToWrite, sizeof( float ), count );
            writeData( pFloatToWrite, sizeof( float ), count );

            free( pFloatToWrite );
        }

        else
        {
            writeData( pFloat, sizeof( float ), count );
        }
    }

    //---------------------------------------------------------------------
    void OgreSerializer::writeFloats( const double* const pDouble, size_t count )
    {
        // Convert to float, then write
        float * tmp = new float[ count ];

        for ( unsigned int i = 0; i < count; ++i )
        {
            tmp[ i ] = static_cast<float>( pDouble[ i ] );
        }

        if ( mFlipEndian )
        {
            flipToLittleEndian( tmp, sizeof( float ), count );
            writeData( tmp, sizeof( float ), count );
        }

        else
        {
            writeData( tmp, sizeof( float ), count );
        }

        delete [] tmp;
    }

    //---------------------------------------------------------------------
    void OgreSerializer::writeShorts( const uint16* const pShort, size_t count = 1 )
    {
        if ( mFlipEndian )
        {
            unsigned short * pShortToWrite = ( unsigned short * ) malloc( sizeof( unsigned short ) * count );
            memcpy( pShortToWrite, pShort, sizeof( unsigned short ) * count );

            flipToLittleEndian( pShortToWrite, sizeof( unsigned short ), count );
            writeData( pShortToWrite, sizeof( unsigned short ), count );

            free( pShortToWrite );
        }

        else
        {
            writeData( pShort, sizeof( unsigned short ), count );
        }
    }

    //---------------------------------------------------------------------
    void OgreSerializer::writeInts( const uint32* const pInt, size_t count = 1 )
    {
        if ( mFlipEndian )
        {
            unsigned int * pIntToWrite = ( unsigned int * ) malloc( sizeof( unsigned int ) * count );
            memcpy( pIntToWrite, pInt, sizeof( unsigned int ) * count );

            flipToLittleEndian( pIntToWrite, sizeof( unsigned int ), count );
            writeData( pIntToWrite, sizeof( unsigned int ), count );

            free( pIntToWrite );
        }

        else
        {
            writeData( pInt, sizeof( unsigned int ), count );
        }
    }

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    void OgreSerializer::writeBools( const bool* const pBool, size_t count = 1 )
    {
        //no endian flipping for 1-byte bools
        //XXX Nasty Hack to convert to 1-byte bools
# if CPF_PLATFORM == CPF_PLATFORM_APPLE
        char * pCharToWrite = ( char * ) malloc( sizeof( char ) * count );

        for ( int i = 0; i < count; i++ )
        {
            *( char * ) ( pCharToWrite + i ) = *( bool * ) ( pBool + i );
        }

        writeData( pCharToWrite, sizeof( char ), count );

        free( pCharToWrite );
# else

        writeData( pBool, sizeof( bool ), count );
# endif

    }

    //---------------------------------------------------------------------
    void OgreSerializer::writeData( const void* const buf, size_t size, size_t count )
    {
        fwrite( ( void * const ) buf, size, count, mpfFile );
    }

    //---------------------------------------------------------------------
    void OgreSerializer::writeString( const std::string& string )
    {
        fputs( string.c_str(), mpfFile );
        // Write terminating newline char
        fputc( '\n', mpfFile );
    }

    //---------------------------------------------------------------------


    void OgreSerializer::flipToLittleEndian( void* pData, size_t size, size_t count )
    {
        if ( mFlipEndian )
        {
            flipEndian( pData, size, count );
        }
    }

    void OgreSerializer::flipFromLittleEndian( void* pData, size_t size, size_t count )
    {
        if ( mFlipEndian )
        {
            flipEndian( pData, size, count );
        }
    }

    void OgreSerializer::flipEndian( void * pData, size_t size, size_t count )
    {
        for ( unsigned int index = 0; index < count; index++ )
        {
            flipEndian( ( void * ) ( ( long ) pData + ( index * size ) ), size );
        }
    }

    void OgreSerializer::flipEndian( void * pData, size_t size )
    {
        char swapByte;

        for ( unsigned int byteIndex = 0; byteIndex < size / 2; byteIndex++ )
        {
            swapByte = *( char * ) ( ( long ) pData + byteIndex );
            *( char * ) ( ( long ) pData + byteIndex ) = *( char * ) ( ( long ) pData + size - byteIndex - 1 );
            *( char * ) ( ( long ) pData + size - byteIndex - 1 ) = swapByte;
        }
    }

	fpos_t OgreSerializer::getPos()
	{
		fpos_t pos; 
		fgetpos(mpfFile, &pos);
		return pos;
	}

	bool OgreSerializer::setPos( fpos_t pos )
	{
		return (fsetpos( mpfFile, &pos) == 0);
	}
}

